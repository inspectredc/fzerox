#include "libultra/ultra64.h"
#include "leo/leo_internal.h"
#include "PR/os_internal_exception.h"

s32 LeoCreateLeoManager(OSPri comPri, OSPri intPri, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    OSPiHandle* driveRomHandle;
    OSPiHandle* leoDiskHandle;
    LEOCmdInquiry cmdBlockInq;
    LEOCmd cmdBlockID;
    LEODiskID thisID;
    u32 stat;
    u32 status;
    s32 dummy;

    if (__leoActive) {
        return LEO_ERROR_GOOD;
    }

    leoDiskHandle = osLeoDiskInit();
    driveRomHandle = osDriveRomInit();

    osEPiReadIo(leoDiskHandle, LEO_STATUS, &status);
    if (status & LEO_STATUS_PRESENCE_MASK) {
        return LEO_ERROR_DEVICE_COMMUNICATION_FAILURE;
    }

    __leoActive = 1;

    __osSetHWIntrRoutine(1, __osLeoInterrupt);
    leoInitialize(comPri, intPri, cmdBuf, cmdMsgCnt);

    cmdBlockInq.header.command = 2;
    cmdBlockInq.header.reserve1 = 0;
    cmdBlockInq.header.control = 0;
    cmdBlockInq.header.reserve3 = 0;
    leoCommand((void*)&cmdBlockInq);

    dummy = (s32) __osSetHWIntrRoutine & 0xA48D3C;
    while (dummy < 0xE00000) {
        dummy += (((s32) leoCommand & 0xFF) | 0x8A) << 0x10;
    }

    while (cmdBlockInq.header.status == 8) { }

    if (cmdBlockInq.header.status != 0) {
        return GET_ERROR(cmdBlockInq);
    }

    __leoVersion.driver = cmdBlockInq.version;
    __leoVersion.drive = 4;
    __leoVersion.deviceType = cmdBlockInq.dev_type;
    __leoVersion.ndevices = cmdBlockInq.dev_num;

    return LEO_ERROR_GOOD;
}
