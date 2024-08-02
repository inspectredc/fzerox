#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

s32 LeoModeSelectAsync(LEOCmd* cmdBlock, u32 standby, u32 sleep, OSMesgQueue* mq) {
    if (!__leoActive) {
        return -1;
    }
    if ((standby > 10) || (sleep > 10)) {
        return -1;
    }
    cmdBlock->header.command = LEO_COMMAND_MODE_SELECT;
    cmdBlock->header.reserve1 = 0;
    cmdBlock->header.control = 0;
    cmdBlock->header.reserve3 = 0;
    cmdBlock->data.modeselect.reserve1 = 0;
    cmdBlock->data.modeselect.reserve2 = 0;
    cmdBlock->data.modeselect.standby_time = standby;
    cmdBlock->data.modeselect.sleep_time = sleep;
    cmdBlock->data.modeselect.reserve3 = 0;
    if (mq != NULL) {
        cmdBlock->header.control |= LEO_CONTROL_POST;
        cmdBlock->header.post = mq;
    }
    leoCommand(cmdBlock);
    return 0;
}
