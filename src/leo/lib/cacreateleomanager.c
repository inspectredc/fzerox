#include "libultra/ultra64.h"
#include "libc/stdint.h"
#include "leo/leo_internal.h"
#include "PR/os_internal_exception.h"

s32 LeoCACreateLeoManager(OSPri comPri, OSPri intPri, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    OSPiHandle* driveRomHandle;
    OSPiHandle* leoDiskHandle;
    volatile LEOCmdInquiry cmdBlockInq;
    volatile LEOCmd cmdBlockID;
    LEODiskID thisID;
    u32 stat;
    u32 status;
    volatile intptr_t dummy;

    if (__leoActive) {
        return LEO_ERROR_GOOD;
    }

#if LEO_VERSION == LEO_VERSION_B
    if (!LeoDriveExist()) {
        return LEO_ERROR_DEVICE_COMMUNICATION_FAILURE;
    }
#endif
    leoDiskHandle = osLeoDiskInit();
    driveRomHandle = osDriveRomInit();

#if LEO_VERSION == LEO_VERSION_A
    osEPiReadIo(leoDiskHandle, LEO_STATUS, &status);
    if (status & LEO_STATUS_PRESENCE_MASK) {
        return LEO_ERROR_DEVICE_COMMUNICATION_FAILURE;
    }
#endif

    __leoActive = true;

#if LEO_VERSION == LEO_VERSION_A
    __osSetHWIntrRoutine(1, __osLeoInterrupt);
#else // LEO_VERSION_B
    __osSetHWIntrRoutine(1, __osLeoInterrupt, leoDiskStack + sizeof(leoDiskStack) - 16);
#endif
    leoInitialize(comPri, intPri, cmdBuf, cmdMsgCnt);

    if (osResetType == 1) {
        __leoSetReset();
    }

    cmdBlockInq.header.command = LEO_COMMAND_INQUIRY;
    cmdBlockInq.header.reserve1 = 0;
    cmdBlockInq.header.control = 0;
    cmdBlockInq.header.reserve3 = 0;
    leoCommand((void*) &cmdBlockInq);

    dummy = (uintptr_t) __osSetHWIntrRoutine & 0xA48D3C;

    while (dummy < 0xE00000) {
        dummy += (((uintptr_t) leoCommand & 0xFF) | 0x8A) << 0x10;
    }

    while (cmdBlockInq.header.status == LEO_STATUS_BUSY) {}

    if (cmdBlockInq.header.status != 0) {
        return GET_ERROR(cmdBlockInq);
    }
    __leoVersion.driver = cmdBlockInq.version;
#if LEO_VERSION == LEO_VERSION_A
    __leoVersion.drive = 4;
#else // LEO_VERSION_B
    __leoVersion.drive = 6;
#endif
    __leoVersion.deviceType = cmdBlockInq.dev_type;
    __leoVersion.ndevices = cmdBlockInq.dev_num;

    if ((__leoVersion.driver & 0xF) == 4) {
        LEO_country_code = LEO_COUNTRY_NONE;
    } else if (((__leoVersion.driver & 0xF) == 3) || ((__leoVersion.driver & 0xF) == 1)) {
        volatile intptr_t dummy2;
        osEPiReadIo(driveRomHandle, 0x9FF00, &status);
        status = ((status & 0xFF000000) >> 0x18);

        if (status != 4) {
            while (true) {}
        }

        dummy2 = 0x32F8EB20;
        LEO_country_code = LEO_COUNTRY_USA;
        dummy2 += (uintptr_t) &__leoActive;
    } else {
        while (true) {}
    }

    return LEO_ERROR_GOOD;
}
