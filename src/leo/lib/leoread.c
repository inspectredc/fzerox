#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

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
    if ((tg_lba + tg_blocks) > NUM_LBAS + 0x18) {
    invalid_lba:
        LEOcur_command->header.sense = LEO_SENSE_LBA_OUT_OF_RANGE;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }

    if (tg_blocks == 0) {
        if (tg_lba >= NUM_LBAS + 0x18) {
            goto invalid_lba;
        }
        LEOcur_command->header.sense = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
        LEOcur_command->header.status = LEO_STATUS_GOOD;
        return;
    }

    LEOtgt_param.lba = tg_lba;
    LEOrw_flags &= ~(0x8000 | 0x4000);
    osSendMesg(&LEOc2ctrl_que, NULL, OS_MESG_NOBLOCK);
    osStartThread(&LEOinterruptThread);

    while (true) {
        osRecvMesg(&LEOcontrol_que, (OSMesg) &message, OS_MESG_BLOCK);

        switch (message) {
#if LEO_VERSION == LEO_VERSION_A
            case LEO_MSG_CONTROL_FORCE_ACCEPT:
                goto end;
#endif
            case LEO_MSG_CONTROL_C2_CORRECTION:
                leoC2_Correction();
                LEOrw_flags &= ~0x4000;
                osSendMesg(&LEOc2ctrl_que, NULL, OS_MESG_NOBLOCK);
                break;

            default:
                LEOcur_command->header.sense = message;
                LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                return;
#if LEO_VERSION == LEO_VERSION_B
            case LEO_MSG_CONTROL_FORCE_ACCEPT:
                LEOcur_command->header.sense = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
                LEOcur_command->header.status = LEO_STATUS_GOOD;
                return;
#endif
        }
    }
#if LEO_VERSION == LEO_VERSION_A
end:
    LEOcur_command->header.sense = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
    LEOcur_command->header.status = LEO_STATUS_GOOD;
#endif
}
