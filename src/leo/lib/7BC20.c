#include "global.h"
#include "leo/leo_internal.h"

extern void (*LEO_cmd_tbl[])(void);

void leomain(void* arg0) {
    u32 cur_status;
    s32 sense_code;

    ((u8*)&LEO_country_code)[0] = *(u8*)0xA0000010;
    ((u8*)&LEO_country_code)[1] = *(u8*)0xA0000090;
    ((u8*)&LEO_country_code)[2] = *(u8*)0xA0000110;
    ((u8*)&LEO_country_code)[3] = *(u8*)0xA0000190;

    LEOasic_seq_ctl_shadow = 0;
    LEOasic_bm_ctl_shadow = 0;
    LEOdrive_flag = 0;
    LEOclr_que_flag = 0;
    leoInitUnit_atten();
    LEOPiInfo = osLeoDiskInit();
    LEOPiDmaParam.hdr.pri = 1;
    LEOPiDmaParam.hdr.retQueue = &LEOdma_que;
    osEPiReadIo(LEOPiInfo, LEO_STATUS, &cur_status);
    if (!(cur_status & 0x400000)) {
        if ((cur_status & 0x06800000)) {
            leoDrive_reset();
        }
    }

    while (true) {
        osRecvMesg(&LEOcommand_que, (void** ) &LEOcur_command, 1);
        if (LEOcur_command->header.command == 0) {
            leoDrive_reset();
            osRecvMesg(&LEOevent_que, NULL, OS_MESG_NOBLOCK);
            continue;
        }
        sense_code = leoChk_asic_ready(0x10001);
        cur_status = leoChkUnit_atten();
        if (cur_status == 0) {
            if (sense_code == 0) {
                goto block_43;
            }
        } else {
            switch (sense_code) {
                case 3:
                case 41:
                case 43:
                    break;
                case 49:
                    if (leoRetUnit_atten() == 0x2B) {
                        sense_code = 0x2B;
                    }
                    break;
                default:
                    sense_code = leoRetUnit_atten();
            }
        }
        switch (sense_code) {
            case 47:
                switch (LEOcur_command->header.command) {
                    case 12:
                        leoClrUA_MEDIUM_CHANGED();
                        /* fallthrough */
                    case 2:
                    case 13:
                    case 14:
                    case 15:
                        goto block_43;
                }
                break;
            case 49:
                switch (LEOcur_command->header.command) {
                    case 2:
                    case 11:
                    case 13:
                    case 14:
                    case 15:
                        goto block_43;
                    default:
                        sense_code = 0x2A;
                }
                break;
            case 43:
                switch (LEOcur_command->header.command) {
                    case 15:
                        leoClrUA_RESET();
                        /* fallthrough */
                    case 2:
                    case 13:
                    case 14:
                        goto block_43;
                }
                break;
        }

        if (LEOcur_command->header.command == 3) {
            LEOcur_command->data.time.pad = leoChk_cur_drvmode();
        }
        LEOcur_command->header.sense = (u8) sense_code;
        LEOcur_command->header.status = 2;
        while (false) {
            block_43:
            if (LEOdrive_flag == 0) {
                switch (LEOcur_command->header.command) {
                    case 2:
                    case 3:
                    case 11:
                    case 13:
                    case 14:
                    case 15:
                        goto block_59;
                }
    
                if (LEO_country_code == LEO_COUNTRY_NONE) {
                    osEPiReadIo(LEOPiInfo, LEO_ID_REG, &cur_status);
                    if ((cur_status & 0x70000) != 0x40000) {
                        while (true) {}
                    }
                }
                    
                if (leoRead_system_area() != 0) {
                    LEOcur_command->header.status = 2;
                    break;
                } 
                
                if ((LEOcur_command->header.sense = leoSend_asic_cmd_w(ASIC_SET_DTYPE, LEO_sys_data.param.disk_type << 16)) != 0) {
                    LEOcur_command->header.status = 2;
                    break;
                } 
                                        
                if ((LEO_sys_data.param.disk_type & 0xF0) != 0x10) {
                    goto block_57;
                }
                LEOdisk_type = LEO_sys_data.param.disk_type & 0xF;
                if ((LEOdisk_type) >= 7) {
    block_57:
                    LEOcur_command->header.sense = 0xB;
                    LEOcur_command->header.status = 2;
                    break;
                } 
                LEOdrive_flag = 0xFF;
            }
    block_59:
            LEO_cmd_tbl[LEOcur_command->header.command]();
        }
        if (LEOcur_command->header.control & LEO_CONTROL_POST) {
            osSendMesg(LEOcur_command->header.post, (OSMesg)LEOcur_command->header.sense, 1);
        }
        if (LEOclr_que_flag != 0) {
            leoClr_queue();
        }
    }
}

extern LEOCmdRead leo_sys_read_cmd;
const u8 leo_sys_form_lbas[] = { 0, 1, 8, 9, 0, 0, 0, 0 };

u8 leoRead_system_area(void) {
    LEOCmdRead temp_cmd;
    LEOCmd* prev_cmd;
    u32 retry_cntr;
    s32 read_mode;

    prev_cmd = LEOcur_command;
    LEOcur_command = (LEOCmd*)&temp_cmd;
    read_mode = 0;
    retry_cntr = 0;

    while (1) {
        LEOdisk_type = 0;
        // For lba_to_phys to avoid dealing with alternative tracks on the disk
        LEO_sys_data.param.defect_num[0] = 0;
        LEOrw_flags = 0x3000;
        temp_cmd = leo_sys_read_cmd;
        temp_cmd.buff_ptr = &LEO_sys_data;

        if (read_mode == 0) {
            // read System LBA 12 (+0, this is an offset value for leoRead_common)
            // see leo_sys_read_cmd premade struct
            leoRead_common(0);
            switch (GET_ERROR(temp_cmd)) {
                case LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION:
                    do {
                        // if expecting a retail disk, LBA 12 is expected to do a read error, if not then freeze
                    } while (LEO_country_code != LEO_COUNTRY_NONE);
                    break;
                case LEO_SENSE_UNRECOVERED_READ_ERROR:
                    do {
                        // if expecting a development disk, LBA 12 is expected to read correctly, if not then freeze
                    } while (LEO_country_code == LEO_COUNTRY_NONE);
                    break;
                default:
                    goto system_retry;
            }
            read_mode--;
            retry_cntr = 0;
            continue;
        } else {
            // read System LBA 0,1,8,9 (or 2,3,10,11 for dev)
            temp_cmd.lba = leo_sys_form_lbas[retry_cntr % 4];
            if (LEO_country_code == LEO_COUNTRY_NONE) {
                temp_cmd.lba += 2;
            }
            leoRead_common(0);
            if (temp_cmd.header.status == LEO_STATUS_GOOD) {
                do {
                    // if disk country and set country code in libleo mismatch, then freeze
                } while ((0, LEO_sys_data.param.country) != LEO_country_code);
                // todo: use likely macro for above
                break;
            }
        }
    system_retry:
        if (leoChk_err_retry(GET_ERROR(temp_cmd)) != LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
            break;
        }
        if (retry_cntr++ >= 0x40U) {
            break;
        }
        if ((retry_cntr & 7) == 0) {
            // Recalibrate drive every 8th tries
            if ((temp_cmd.header.sense = leoSend_asic_cmd_w(ASIC_RECAL, 0)) !=
                LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
                goto system_retry;
            }
        }
    }
    LEOcur_command = prev_cmd;
    return LEOcur_command->header.sense = GET_ERROR(temp_cmd);
}

void leoRead(void) {
    LEOrw_flags = 0;
    leoRead_common(0x18);
}

void leoRead_common(u32 offset) {
    u32 tg_lba = LEOcur_command->data.readwrite.lba;
    u32 tg_blocks = LEOcur_command->data.readwrite.xfer_blks;
    u32 message;
    s32 pad;

    if ((tg_lba | tg_blocks) & 0xFFFF0000) {
        goto invalid_lba;
    }

    tg_lba += offset;
    if ((tg_lba + tg_blocks) > 0x10DC) { // Unclear what this number represents
    invalid_lba:
        LEOcur_command->header.sense = LEO_SENSE_LBA_OUT_OF_RANGE;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }

    if (tg_blocks == 0) {
        if (tg_lba >= 0x10DC) {
            goto invalid_lba;
        }
        LEOcur_command->header.sense = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
        LEOcur_command->header.status = LEO_STATUS_GOOD;
        return;
    }

    LEOtgt_param.lba = tg_lba;
    LEOrw_flags &= 0xFFFF3FFF;
    osSendMesg(&LEOc2ctrl_que, NULL, OS_MESG_NOBLOCK);
    osStartThread(&LEOinterruptThread);

    while (true) {
        osRecvMesg(&LEOcontrol_que, (OSMesg)&message, OS_MESG_BLOCK);

        switch (message) {
            case LEO_MSG_CONTROL_FORCE_ACCEPT:
                goto end;
            case LEO_MSG_CONTROL_C2_CORRECTION:
                leoC2_Correction();
                LEOrw_flags &= ~0x4000;
                osSendMesg(&LEOc2ctrl_que, NULL, OS_MESG_NOBLOCK);
                break;

            default:
                LEOcur_command->header.sense = message;
                LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                return;

        }
    }
end:
    LEOcur_command->header.sense = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
    LEOcur_command->header.status = LEO_STATUS_GOOD;
}

s32 LeoLBAToByte(s32 startlba, u32 nlbas, s32* bytes) {
    u32 resbytes;
    u32 byte_p_blk;
    u16 zone;
    u16 vzone;
    u8 flag;

    if (!__leoActive) {
        return -1;
    }
    if ((u32)startlba >= NUM_LBAS) {
        return LEO_ERROR_LBA_OUT_OF_RANGE;
    }
    resbytes = 0;
    flag = vzone = 1;
    startlba += 0x18;
    while (nlbas > 0) {
        if ((flag != 0) || (LEOVZONE_TBL[LEOdisk_type][vzone] == startlba)) {
            vzone = leoLba_to_vzone(startlba);
            zone = LEOVZONE_PZONEHD_TBL[LEOdisk_type][vzone];
            if (zone >= 8) {
                zone -= 7;
            }
            byte_p_blk = LEOBYTE_TBL2[zone];
        }
        resbytes += byte_p_blk;
        nlbas -= 1;
        startlba += 1;
        if ((nlbas > 0) && ((u32)startlba >= NUM_LBAS + 0x18)) {
            return LEO_ERROR_LBA_OUT_OF_RANGE;
        }
        flag = 0;
    }

    *bytes = resbytes;
    return LEO_ERROR_GOOD;
}
