#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

void leoStart_stop(void) {
    u32 send_cmd;
    u8 sense_code;
    u8 retry_cntr = 8;
    u32 send_data;

    do {
        send_data = 0;
        if ((LEOcur_command->header.control & LEO_CONTROL_START)) {
            send_cmd = ASIC_START;
        } else if ((LEOcur_command->header.control & LEO_CONTROL_STBY)) {
            send_cmd = ASIC_STANDBY;
        } else {
            if ((LEOcur_command->header.control & LEO_CONTROL_BRAKE)) {
                send_data = 0x10000;
            }
            send_cmd = ASIC_SLEEP;
        }
        sense_code = leoSend_asic_cmd_w(send_cmd, send_data);
        if (sense_code == 0) {
            LEOcur_command->header.status = LEO_STATUS_GOOD;
            return;
        }
        if (leoChk_err_retry(sense_code)) {
            break;
        }
    } while (retry_cntr--);

    LEOcur_command->header.sense = sense_code;
    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
    return;
}
