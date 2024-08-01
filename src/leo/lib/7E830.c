#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

extern u32 asic_cur_status;
extern u32 unit_atten;

u8 leoAnalize_asic_status(void) {
    u32 curr_stat;

    osEPiReadIo(LEOPiInfo, LEO_STATUS, &asic_cur_status);
    curr_stat = asic_cur_status ^ LEO_STATUS_DISK_PRESENT;
    if (curr_stat & (LEO_STATUS_DISK_PRESENT | LEO_STATUS_BUSY_STATE | LEO_STATUS_RESET_STATE | LEO_STATUS_MECHANIC_ERROR | LEO_STATUS_DISK_CHANGE | LEO_STATUS_PRESENCE_MASK)) {
        if (curr_stat & (LEO_STATUS_DISK_PRESENT | LEO_STATUS_BUSY_STATE | LEO_STATUS_RESET_STATE | LEO_STATUS_DISK_CHANGE | LEO_STATUS_PRESENCE_MASK)) {
            LEOdrive_flag = 0;
        }
        if (curr_stat & LEO_STATUS_PRESENCE_MASK) {
            return LEO_SENSE_DEVICE_COMMUNICATION_FAILURE;
        }
        if ((curr_stat & 0xC00000) == LEO_STATUS_BUSY_STATE) {
            return LEO_SENSE_COMMAND_PHASE_ERROR;
        }
        if (curr_stat & LEO_STATUS_RESET_STATE) {
            unit_atten |= 2;
            return LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
        }
        if (curr_stat & LEO_STATUS_DISK_PRESENT) {
            return LEO_SENSE_EJECTED_ILLEGALLY_RESUME;
        }
        if (curr_stat & LEO_STATUS_DISK_CHANGE) {
            unit_atten |= 1;
            return LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED;
        }
        if (curr_stat & LEO_STATUS_MECHANIC_ERROR) {
            return LEO_SENSE_NO_SEEK_COMPLETE;
        }
    }
    return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
}

u8 leoChk_asic_ready(u32 asic_cmd) {
    u32 sense_code = leoAnalize_asic_status();

    switch (sense_code) {
        case LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED:
            if (asic_cmd == ASIC_CLR_CHGFLG) {
                return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
            }
        case LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED:
            if (!(asic_cur_status & LEO_STATUS_BUSY_STATE)) {
                if (asic_cmd == ASIC_CLR_RSTFLG) {
                    return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
                }
                if (leoRecv_event_mesg(0) != 0) {
                    return LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
                }
                osEPiWriteIo(LEOPiInfo, LEO_CMD, ASIC_CLR_RSTFLG);
                if (leoRecv_event_mesg(1) != 0) {
                    return LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
                }
            }
            break;
        case LEO_SENSE_EJECTED_ILLEGALLY_RESUME:
            if (asic_cmd & ASIC_NEED_DISK_IN) {
                break;
            }
        case LEO_SENSE_NO_SEEK_COMPLETE:
            return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
    }
    return sense_code;
}

u8 leoChk_done_status(u32 asic_cmd) {
    u32 asic_data;
    u32 code = leoAnalize_asic_status();

    switch (code) {
        case LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED:
        case LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED:
            if (!(asic_cur_status & LEO_STATUS_BUSY_STATE)) {
                if (leoRecv_event_mesg(0) != 0) {
                    return LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
                }

                osEPiWriteIo(LEOPiInfo, 0x5000508, 0x90000);
                if (leoRecv_event_mesg(1) != 0) {
                    return LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
                }
            }
            break;

        case LEO_SENSE_EJECTED_ILLEGALLY_RESUME:
            if (asic_cmd & 1) {
                break;
            }
            return 0;

        case LEO_SENSE_NO_SEEK_COMPLETE:
            osEPiWriteIo(LEOPiInfo, 0x5000500, 0);
            if (leoRecv_event_mesg(0) != 0) {
                return LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
            }

            osEPiWriteIo(LEOPiInfo, 0x5000508, 0xC0000);
            if (leoRecv_event_mesg(1) != 0) {
                return LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
            }

            osEPiReadIo(LEOPiInfo, 0x5000500, &asic_data);
            code = leoChk_asic_ready(ASIC_REQ_STATUS);
            if (code != 0) {
                return code;
            }

            if (asic_data & 0x10000) {
                return LEO_SENSE_DIAGNOSTIC_FAILURE;
            }
            if (asic_data & 0x20000) {
                return LEO_SENSE_NO_REFERENCE_POSITION_FOUND;
            }
            if (asic_data & 0x40000) {
                return LEO_SENSE_DRIVE_NOT_READY;
            }
            if (asic_data & 0x80000) {
                return LEO_SENSE_NO_SEEK_COMPLETE;
            }
            if (asic_data & 0x200000) {
                return LEO_SENSE_INCOMPATIBLE_MEDIUM_INSTALLED; // or LEO_SENSE_UNKNOWN_FORMAT
            }
            return LEO_SENSE_DEVICE_COMMUNICATION_FAILURE;
    }
    return code;
}

u8 leoSend_asic_cmd_i(u32 asic_cmd, u32 asic_data) {
    u8 status = leoChk_asic_ready(asic_cmd);

    if (status != 0) {
        return LEOcur_command->header.sense = status;
    }
    osEPiWriteIo(LEOPiInfo, LEO_DATA, asic_data);
    if (leoRecv_event_mesg(0) != 0) {
        return LEOcur_command->header.sense = LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
    }
    osEPiWriteIo(LEOPiInfo, LEO_STATUS, asic_cmd);
    return 0;
}

u8 leoWait_mecha_cmd_done(u32 asic_cmd) {
    u32 done_stat;

    if (leoRecv_event_mesg(1)) {
        return LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
    }
    done_stat = leoChk_done_status(asic_cmd);
    if (done_stat != 0) {
        return done_stat;
    }
    return 0;
}

u8 leoSend_asic_cmd_w(u32 asic_cmd, u32 asic_data) {
    u32 wstatus = leoSend_asic_cmd_i(asic_cmd, asic_data);

    if (wstatus != 0) {
        return wstatus;
    }
    return leoWait_mecha_cmd_done(asic_cmd);
}

u8 leoDetect_index_w(void) {
    return leoSend_asic_cmd_w(ASIC_INDEX_LOCK_RETRY, 0);
}

u8 leoRecal_i(void) {
    return leoSend_asic_cmd_i(ASIC_RECAL, 0);
}

u8 leoRecal_w(void) {
    return leoSend_asic_cmd_w(ASIC_RECAL, 0);
}

u8 leoSeek_i(u16 rwmode) {
    u32 tgt_tk = ((LEOtgt_param.head << 12) + LEOtgt_param.cylinder) << 16;

    if (rwmode == 0) {
        return leoSend_asic_cmd_i(ASIC_RD_SEEK, tgt_tk);
    } else {
        return leoSend_asic_cmd_i(ASIC_WR_SEEK, tgt_tk);
    }
}

u8 leoSeek_w(void) {
    u8 sksense = leoSeek_i(0);

    if (sksense != 0) {
        return sksense;
    }

    return leoWait_mecha_cmd_done(ASIC_RD_SEEK);
}

s32 leoRecv_event_mesg(s32 control) {
    u32 done_mesg;

    if (osRecvMesg(&LEOevent_que, (OSMesg*)&done_mesg, control) == 0) {
        if (done_mesg == ASIC_SOFT_RESET_CODE) {
            leoDrive_reset();
            return 0xFF;
        }
    }
    return 0;
}

u32 leoChk_err_retry(u32 sense) {

    switch (sense) {
        case LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED:
            unit_atten |= 2;
        case LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED:
            unit_atten |= 1;
        case LEO_SENSE_DIAGNOSTIC_FAILURE:
        case LEO_SENSE_COMMAND_PHASE_ERROR:
        case LEO_SENSE_DEVICE_COMMUNICATION_FAILURE:
        case LEO_SENSE_MEDIUM_NOT_PRESENT:
        case LEO_SENSE_EJECTED_ILLEGALLY_RESUME:
            LEOdrive_flag = 0;
            return -1;
    }

    return 0;
}

u8 leoChk_cur_drvmode(void) {
    u8 devstat = 0;
    if (!(asic_cur_status & 0x1000000)) {
        devstat |= 1;
    }
    if (asic_cur_status & 0x80000) {
        devstat |= 2;
    }
    if (asic_cur_status & 0x100000) {
        devstat |= 4;
    }
    return devstat;
}

void leoDrive_reset(void) {
    osEPiWriteIo(LEOPiInfo, 0x05000520, 0xAAAA0000);
}

u32 leoChkUnit_atten(void) {
    return unit_atten;
}

u32 leoRetUnit_atten(void) {
    if (unit_atten & 2) {
        return LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
    }
    if (unit_atten & 1) {
        return LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED;
    }
    return 0;
}

void leoClrUA_RESET(void) {
    unit_atten &= ~3;
}

void leoClrUA_MEDIUM_CHANGED(void) {
    unit_atten &= ~1;
}

void leoInitUnit_atten(void) {
    unit_atten = 0;
}
