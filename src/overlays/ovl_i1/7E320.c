#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

s32 leoVerifyRTC(u8, u8);

s32 LeoSetRTC(LEOCmd* cmdBlock, LEODiskTime* RTCdata, OSMesgQueue* mq) {
    if (!__leoActive) {
        return -1;
    }
    if (leoVerifyRTC(RTCdata->yearhi, RTCdata->yearlo) != 0) {
        osSendMesg(mq, (void*)LEO_SENSE_ILLEGAL_TIMER_VALUE, 1);
        return 0;
    }
    cmdBlock->header.command = LEO_COMMAND_SET_TIMER;
    cmdBlock->header.reserve1 = 0;
    cmdBlock->header.control = 0;
    cmdBlock->header.reserve3 = 0;
    bcopy(RTCdata, &cmdBlock->data.time, 8);
    if (mq != NULL) {
        cmdBlock->header.control |= LEO_CONTROL_POST;
        cmdBlock->header.post = mq;
    }
    leoCommand(cmdBlock);
    return 0;
}

s32 leoVerifyRTC(u8 yearhi, u8 yearlo) {
    u32 year;
    if (((yearlo & 0xF) >= 10) || ((yearlo & 0xF0) >= 145) || ((yearhi & 0xF) >= 10) || ((yearhi & 0xF0) >= 145)) {
        return 1;
    }
    year = (((yearhi - ((yearhi >> 4) * 6)) * 100)) + (yearlo - (yearlo >> 4) * 6);
    if ((year < 1996) || (year >= 2096)) {
        return 1;
    }
    return 0;
}
