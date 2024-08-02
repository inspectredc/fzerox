#include "libultra/ultra64.h"
#include "libc/stdbool.h"
#include "leo/leo_internal.h"

LEOError read_write_track(void);
u32 leoChk_mecha_int(void);
void leosetup_BM(void);
u32 leochk_err_reg(void);

void leointerrupt(void* arg) {
    u32 result;
    u32 tg_blocks;

    osCreateMesgQueue(&LEOc2ctrl_que, (OSMesg)&LEOc2ctrl_que_buf, 1);

    while (true) {
        osStopThread(&LEOinterruptThread);
        tg_blocks = LEOcur_command->data.readwrite.xfer_blks;
        LEOwrite_pointer = LEOcur_command->data.readwrite.buff_ptr;
        do {
            leoLba_to_phys(LEOtgt_param.lba);
            if (LEOrw_flags & 0x8000) {
                result = leoSeek_i(OS_WRITE);
            } else {
                result = leoSeek_i(OS_READ);
            }

            if (result != 0) {
                goto complete;
            }

            if (LEOrw_flags & 0x2000) {
                LEOtgt_param.rdwr_blocks = 1;
            } else if (LEOtgt_param.rdwr_blocks > tg_blocks) {
                LEOtgt_param.rdwr_blocks = tg_blocks;
            }
            LEOtgt_param.lba += LEOtgt_param.rdwr_blocks;
            tg_blocks -= LEOtgt_param.rdwr_blocks;
            result = read_write_track();
            if (result != 0) {
                goto complete;
            }

            LEOcur_command->data.readwrite.rw_bytes = LEOwrite_pointer - (u8*)LEOcur_command->data.readwrite.buff_ptr;
        } while (tg_blocks != 0);
        result = LEO_MSG_CONTROL_FORCE_ACCEPT; // Unreachable, probably intended as a dev snippet

    complete:;

        osSendMesg(&LEOcontrol_que, result, OS_MESG_BLOCK);
    }
}

extern u8 LEOC2_Syndrome[2][0x3A0];

LEOError read_write_track(void) {
    LEOError message;
    u32 block;
    u32 retry_cntr;
    block_param_form block_param;
    u16 bnum;
    u8* temp;
    u32 c2datasize;

    block_param.bytes = LEOtgt_param.sec_bytes;
    block_param.blkbytes = LEOtgt_param.blk_bytes;
    if (LEOrw_flags & 0x2000) {
        // Sector Mode
        block_param.blkbytes = block_param.bytes;
    }
    block_param.pntr = LEOwrite_pointer;
    LEOwrite_pointer += block_param.blkbytes;
    if (LEOtgt_param.rdwr_blocks == 2) {
        LEOwrite_pointer += block_param.blkbytes;
    }
    retry_cntr = 0;
    while (true) {
        LEOPiInfo->transferInfo.transferMode = LEO_BLOCK_MODE;
        LEOPiInfo->transferInfo.blockNum = 0;
        LEOPiInfo->transferInfo.block[0].C1ErrNum = 0;
        LEOPiInfo->transferInfo.block[0].sectorSize = block_param.bytes;
        LEOPiInfo->transferInfo.block[0].dramAddr = block_param.pntr;
        LEOPiInfo->transferInfo.block[0].C2Addr = &LEOC2_Syndrome[0];
        if (LEOrw_flags & 0x2000) {
            // Sector Mode
            LEOtgt_param.rdwr_blocks = 1;
            LEOPiInfo->transferInfo.transferMode = LEO_SECTOR_MODE;
        } else if (LEOtgt_param.rdwr_blocks == 2) {
            LEOPiInfo->transferInfo.transferMode = LEO_TRACK_MODE;
            LEOPiInfo->transferInfo.block[1] = LEOPiInfo->transferInfo.block[0];
            LEOPiInfo->transferInfo.block[1].C2Addr = &LEOC2_Syndrome[1];
            LEOPiInfo->transferInfo.block[1].dramAddr =
                ((u8*)LEOPiInfo->transferInfo.block[1].dramAddr + block_param.blkbytes);
        }
        message = leoChk_mecha_int();
        if (message != LEO_ERROR_GOOD) {
            goto track_end;
        }
        if (LEOrw_flags & 0x8000) {
            // Write Mode
            leoSet_mseq(1);
        } else {
            // Read Mode
            leoSet_mseq(0);
        }
        leosetup_BM();
        LEOPiInfo->transferInfo.bmCtlShadow = LEOasic_bm_ctl_shadow;
        LEOPiInfo->transferInfo.seqCtlShadow = LEOasic_seq_ctl_shadow;
        if (LEOrw_flags & 0x8000) {
            LEOPiInfo->transferInfo.cmdType = LEO_CMD_TYPE_1;
            osWritebackDCache(block_param.pntr, block_param.blkbytes * LEOtgt_param.rdwr_blocks);
            osEPiStartDma(LEOPiInfo, &LEOPiDmaParam, OS_WRITE);
            osRecvMesg(&LEOdma_que, NULL, OS_MESG_BLOCK);
            LEOasic_bm_ctl_shadow = LEOPiInfo->transferInfo.bmCtlShadow;
            LEOasic_seq_ctl_shadow = LEOPiInfo->transferInfo.seqCtlShadow;
            bnum = LEOPiInfo->transferInfo.blockNum;
            message = LEOPiInfo->transferInfo.block[bnum].errStatus;
            if (message == LEO_ERROR_GOOD) {
                return message;
            }
            goto track_end;
        } 
        
        if (LEOrw_flags & 0x4000) {
            osRecvMesg(&LEOc2ctrl_que, NULL, OS_MESG_BLOCK);
            osSendMesg(&LEOc2ctrl_que, NULL, OS_MESG_NOBLOCK);
        }
        LEOPiInfo->transferInfo.cmdType = LEO_CMD_TYPE_0;
        osInvalDCache(block_param.pntr, block_param.blkbytes * LEOtgt_param.rdwr_blocks);
        osEPiStartDma(LEOPiInfo, &LEOPiDmaParam, OS_READ);
        
        for (block = 0; LEOtgt_param.rdwr_blocks != 0; block++) {
            osRecvMesg(&LEOdma_que, NULL, OS_MESG_BLOCK);
            LEOasic_bm_ctl_shadow = LEOPiInfo->transferInfo.bmCtlShadow;
            LEOasic_seq_ctl_shadow = LEOPiInfo->transferInfo.seqCtlShadow;
            message = LEOPiInfo->transferInfo.block[block].errStatus;
            if (message != LEO_ERROR_GOOD) {
                goto track_end;
            }
            if (LEOrw_flags & 0x2000) {
                return LEO_ERROR_GOOD;
            }
            if (LEOPiInfo->transferInfo.block[block].C1ErrNum) {
                if (LEOPiInfo->transferInfo.block[block].C1ErrSector[0] < 0x55) {
                    if (LEOtgt_param.rdwr_blocks == 1) {
                        osEPiReadIo(LEOPiInfo, LEO_ERR_SECTOR, &message);
                        if (message & 0x10000000) {
                            message = LEO_ERROR_DATA_PHASE_ERROR;
                            goto track_end;
                        }
                    }

                    if (block == 0) {
                        temp = LEOC2_Syndrome[0];
                    } else {
                        temp = LEOC2_Syndrome[1];
                    }
                    c2datasize = block_param.bytes * 4;
                    block_param.c2buff_e = temp + c2datasize;
                    osInvalDCache(temp, c2datasize);
                    block_param.err_num = LEOPiInfo->transferInfo.block[block].C1ErrNum;
                    block_param.err_pos[0] = LEOPiInfo->transferInfo.block[block].C1ErrSector[0];
                    block_param.err_pos[1] = LEOPiInfo->transferInfo.block[block].C1ErrSector[1];
                    block_param.err_pos[2] = LEOPiInfo->transferInfo.block[block].C1ErrSector[2];
                    block_param.err_pos[3] = LEOPiInfo->transferInfo.block[block].C1ErrSector[3];
                    osRecvMesg(&LEOc2ctrl_que, NULL, OS_MESG_BLOCK);
                    LEOrw_flags |= 0x4000;
                    LEOc2_param = block_param;
                    osSendMesg(&LEOcontrol_que, LEO_MSG_CONTROL_C2_CORRECTION, OS_MESG_BLOCK);
                }
            } else {
                if (LEOtgt_param.rdwr_blocks == 1) {
                    if ((*(u32*)&LEOC2_Syndrome[block][0x00] | *(u32*)&LEOC2_Syndrome[block][0x04] |
                         *(u32*)&LEOC2_Syndrome[block][0x08] | *(u32*)&LEOC2_Syndrome[block][0x0C]) != 0) {
                        message = LEO_ERROR_NO_REFERENCE_POSITION_FOUND;
                        goto track_end;
                    }
                }
            }
            block_param.pntr += block_param.blkbytes;
            LEOtgt_param.start_block ^= 1;
            LEOtgt_param.rdwr_blocks--;
        }

        return LEO_ERROR_GOOD;
        
    track_end:
        if (message == LEO_ERROR_WRITE_FAULT) {
            message = leochk_err_reg();
        }
    do_retry:
        if (leoChk_err_retry(message)) {
            break;
        } 
        if (LEOrw_flags & 0x1000) {
            break;
        } 
        if (retry_cntr++ == 64) {
            break;
        }
        if ((retry_cntr % 8) == 0) {
            message = leoSend_asic_cmd_w(ASIC_RECAL, 0);
            if (message != 0) {
                goto do_retry;
            }
        }
        if (message == LEO_ERROR_NO_REFERENCE_POSITION_FOUND) {
            message = leoDetect_index_w();
            if (message != 0) {
                goto do_retry;
            }
        }
        if (LEOrw_flags & 0x8000) {
            message = leoSeek_i(1);
        } else {
            message = leoSeek_i(0);
        }
        if (message != LEO_ERROR_GOOD) {
            goto do_retry;
        }
    }
    return message;
}

u32 leoChk_mecha_int(void) {
    u32 stat = leoWait_mecha_cmd_done(ASIC_RD_SEEK);
    u32 index_stat;

    if (stat == 0) {
        osEPiReadIo(LEOPiInfo, LEO_CUR_TK, &index_stat);
        if ((index_stat & LEO_CUR_TK_INDEX_LOCK) != LEO_CUR_TK_INDEX_LOCK) {
            stat = LEO_SENSE_NO_REFERENCE_POSITION_FOUND;
        }
    }
    return stat;
}

void leosetup_BM(void) {
    osEPiWriteIo(LEOPiInfo, LEO_BM_STATUS, LEOasic_bm_ctl_shadow | 0x10000000);
    osEPiWriteIo(LEOPiInfo, LEO_BM_STATUS, LEOasic_bm_ctl_shadow);
    if (LEOtgt_param.start_block != 0) {
        LEOasic_bm_ctl_shadow = 0x5A0000;
    } else {
        LEOasic_bm_ctl_shadow = 0;
    }
    if (!(LEOrw_flags & 0x8000)) {
        LEOasic_bm_ctl_shadow |= 0x40000000;
    }
    if (LEOtgt_param.rdwr_blocks == 2) {
        LEOasic_bm_ctl_shadow |= 0x02000000;
    }
    osEPiWriteIo(LEOPiInfo, LEO_BM_STATUS, LEOasic_bm_ctl_shadow);
}

LEOError leochk_err_reg(void) {
    u32 sense;
    u32 index_status;

    osEPiReadIo(LEOPiInfo, LEO_ERR_SECTOR, &sense);
    osEPiWriteIo(LEOPiInfo, LEO_BM_STATUS, LEOasic_bm_ctl_shadow | 0x10000000);
    osEPiWriteIo(LEOPiInfo, LEO_BM_STATUS, LEOasic_bm_ctl_shadow);
    if (sense & 0x04000000) {
        return LEO_SENSE_EJECTED_ILLEGALLY_RESUME;
    } else if (sense & 0x10000000) {
        return LEO_SENSE_DATA_PHASE_ERROR;
    } else if (sense & 0x42000000) {
        if (LEOrw_flags & 0x8000) {
            return LEO_SENSE_WRITE_FAULT;
        }
        return LEO_SENSE_UNRECOVERED_READ_ERROR;
    } else if (sense & 0x80000000) {
        return LEO_SENSE_NO_REFERENCE_POSITION_FOUND;
    } else {
        osEPiReadIo(LEOPiInfo, LEO_CUR_TK, &index_status);
        if ((index_status & 0x60000000) == 0x60000000) {
            return LEO_SENSE_TRACK_FOLLOWING_ERROR;
        } else {
            return LEO_SENSE_NO_REFERENCE_POSITION_FOUND;
        }
    }
}
