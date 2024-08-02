#include "libultra/ultra64.h"
#include "libc/stdbool.h"
#include "leo/leo_internal.h"

extern void (*LEO_cmd_tbl[])(void);

void leomain(void* arg0) {
    u32 cur_status;
    s32 sense_code;

    ((u8*) &LEO_country_code)[0] = *(u8*) 0xA0000010;
    ((u8*) &LEO_country_code)[1] = *(u8*) 0xA0000090;
    ((u8*) &LEO_country_code)[2] = *(u8*) 0xA0000110;
    ((u8*) &LEO_country_code)[3] = *(u8*) 0xA0000190;

    LEOasic_seq_ctl_shadow = 0;
    LEOasic_bm_ctl_shadow = 0;
    LEOdrive_flag = 0;
    LEOclr_que_flag = 0;
    leoInitUnit_atten();
    LEOPiInfo = osLeoDiskInit();
    LEOPiDmaParam.hdr.pri = OS_MESG_PRI_HIGH;
    LEOPiDmaParam.hdr.retQueue = &LEOdma_que;
    osEPiReadIo(LEOPiInfo, LEO_STATUS, &cur_status);
    if (!(cur_status & LEO_STATUS_RESET_STATE)) {
        if ((cur_status &
             (LEO_STATUS_BUFFER_MANAGER_INTERRUPT | LEO_STATUS_MECHANIC_INTERRUPT | LEO_STATUS_BUSY_STATE))) {
            leoDrive_reset();
        }
    }

    while (true) {
        osRecvMesg(&LEOcommand_que, (void**) &LEOcur_command, OS_MESG_BLOCK);
        if (LEOcur_command->header.command == 0) {
            leoDrive_reset();
            osRecvMesg(&LEOevent_que, NULL, OS_MESG_NOBLOCK);
            continue;
        }
        sense_code = leoChk_asic_ready(ASIC_RD_SEEK);
        cur_status = leoChkUnit_atten();
        if (cur_status == LEO_STATUS_GOOD) {
            if (sense_code == LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
                goto block_43;
            }
        } else {
            switch (sense_code) {
                case LEO_SENSE_COMMAND_PHASE_ERROR:
                case LEO_SENSE_DEVICE_COMMUNICATION_FAILURE:
                case LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED:
                    break;
                case LEO_SENSE_EJECTED_ILLEGALLY_RESUME:
                    if (leoRetUnit_atten() == LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED) {
                        sense_code = LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
                    }
                    break;
                default:
                    sense_code = leoRetUnit_atten();
            }
        }
        switch (sense_code) {
            case LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED:
                switch (LEOcur_command->header.command) {
                    case LEO_COMMAND_READ_DISK_ID:
                        leoClrUA_MEDIUM_CHANGED();
                        /* fallthrough */
                    case LEO_COMMAND_INQUIRY:
                    case LEO_COMMAND_READ_TIMER:
                    case LEO_COMMAND_SET_TIMER:
                    case LEO_COMMAND_RESET_CLEAR:
                        goto block_43;
                }
                break;
            case LEO_SENSE_EJECTED_ILLEGALLY_RESUME:
                switch (LEOcur_command->header.command) {
                    case LEO_COMMAND_INQUIRY:
                    case LEO_COMMAND_MODE_SELECT:
                    case LEO_COMMAND_READ_TIMER:
                    case LEO_COMMAND_SET_TIMER:
                    case LEO_COMMAND_RESET_CLEAR:
                        goto block_43;
                    default:
                        sense_code = LEO_SENSE_MEDIUM_NOT_PRESENT;
                }
                break;
            case LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED:
                switch (LEOcur_command->header.command) {
                    case LEO_COMMAND_RESET_CLEAR:
                        leoClrUA_RESET();
                        /* fallthrough */
                    case LEO_COMMAND_INQUIRY:
                    case LEO_COMMAND_READ_TIMER:
                    case LEO_COMMAND_SET_TIMER:
                        goto block_43;
                }
                break;
        }

        if (LEOcur_command->header.command == LEO_COMMAND_TEST_UNIT_READY) {
            LEOcur_command->data.time.pad = leoChk_cur_drvmode();
        }
        LEOcur_command->header.sense = (u8) sense_code;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        while (false) {
        block_43:
            if (LEOdrive_flag == 0) {
                switch (LEOcur_command->header.command) {
                    case LEO_COMMAND_INQUIRY:
                    case LEO_COMMAND_TEST_UNIT_READY:
                    case LEO_COMMAND_MODE_SELECT:
                    case LEO_COMMAND_READ_TIMER:
                    case LEO_COMMAND_SET_TIMER:
                    case LEO_COMMAND_RESET_CLEAR:
                        goto block_59;
                }

                if (LEO_country_code == LEO_COUNTRY_NONE) {
                    osEPiReadIo(LEOPiInfo, LEO_ID_REG, &cur_status);
                    if ((cur_status & (LEO_STATUS_WRITE_PROTECT_ERROR | LEO_STATUS_MECHANIC_ERROR |
                                       LEO_STATUS_DISK_CHANGE)) != LEO_STATUS_WRITE_PROTECT_ERROR) {
                        while (true) {}
                    }
                }

                if (leoRead_system_area() != 0) {
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    break;
                }

                if ((LEOcur_command->header.sense =
                         leoSend_asic_cmd_w(ASIC_SET_DTYPE, LEO_sys_data.param.disk_type << 16)) != 0) {
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    break;
                }

                if ((LEO_sys_data.param.disk_type & 0xF0) != 0x10) {
                    goto block_57;
                }
                LEOdisk_type = LEO_sys_data.param.disk_type & 0xF;
                if ((LEOdisk_type) >= 7) {
                block_57:
                    LEOcur_command->header.sense = LEO_SENSE_INCOMPATIBLE_MEDIUM_INSTALLED;
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    break;
                }
                LEOdrive_flag = -1;
            }
        block_59:
            LEO_cmd_tbl[LEOcur_command->header.command]();
        }
        if (LEOcur_command->header.control & LEO_CONTROL_POST) {
            osSendMesg(LEOcur_command->header.post, (OSMesg) LEOcur_command->header.sense, OS_MESG_BLOCK);
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
    LEOcur_command = (LEOCmd*) &temp_cmd;
    read_mode = 0;
    retry_cntr = 0;

    while (true) {
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
        if (retry_cntr++ >= 64) {
            break;
        }
        if ((retry_cntr % 8) == 0) {
            // Recalibrate drive every 8 tries
            if ((temp_cmd.header.sense = leoSend_asic_cmd_w(ASIC_RECAL, 0)) !=
                LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
                goto system_retry;
            }
        }
    }
    LEOcur_command = prev_cmd;
    return LEOcur_command->header.sense = GET_ERROR(temp_cmd);
}
