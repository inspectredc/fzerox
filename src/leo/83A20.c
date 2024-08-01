#include "libultra/ultra64.h"
#include "libc/stdbool.h"
#include "leo/leo_internal.h"

s32 LeoCJCreateLeoManager(OSPri comPri, OSPri intPri, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    OSPiHandle* driveRomHandle;
    OSPiHandle* leoDiskHandle;
    LEOCmdInquiry cmdBlockInq;
    LEOCmd cmdBlockID;
    LEODiskID thisID;
    u32 stat;
    u32 data;
    s32 dummy;
    s32 dummy2;

    if (__leoActive) {
        return LEO_ERROR_GOOD;
    }

    leoDiskHandle = osLeoDiskInit();
    driveRomHandle = osDriveRomInit();

    osEPiReadIo(leoDiskHandle, 0x05000508, &data);
    if (data & 0xFFFF) {
        return LEO_ERROR_DEVICE_COMMUNICATION_FAILURE;
    }
    
    __leoActive = 1;

    __osSetHWIntrRoutine(1, __osLeoInterrupt);
    leoInitialize(comPri, intPri, cmdBuf, cmdMsgCnt);

    if (osResetType == 1) {
        __leoSetReset();
    }

    cmdBlockInq.header.command = 2;
    cmdBlockInq.header.reserve1 = 0;
    cmdBlockInq.header.control = 0;
    cmdBlockInq.header.reserve3 = 0;
    leoCommand((void*)&cmdBlockInq);

    dummy = (u32)&cmdBlockInq & 0xFFFFFF;

    while (dummy > 0) {
        dummy -= ((u32)__leoSetReset & 0xFFFFFF) | 0x403DF4;
    }

    while (cmdBlockInq.header.status == 8) {
        ;
    }

    if (cmdBlockInq.header.status != 0) {
        return cmdBlockInq.header.sense;
    }
    __leoVersion.driver = cmdBlockInq.version;
    __leoVersion.drive = 4;
    __leoVersion.deviceType = cmdBlockInq.dev_type;
    __leoVersion.ndevices = cmdBlockInq.dev_num;

    if ((__leoVersion.driver & 0xF) == 4) {
        LEO_country_code = 0;
    } else if (((__leoVersion.driver & 0xF) == 3) || ((__leoVersion.driver & 0xF) == 1)) {

        osEPiReadIo(driveRomHandle, 0x9FF00, &data);
        data = ((data & 0xFF000000) >> 0x18);
        dummy2 = 0x3ED98F23;
        if (data != 0xC3) {
            while (1) {}
        }

        dummy2 *= data;
        dummy2 -= (u32)&cmdBlockInq;
        LEO_country_code = 0xE848D316;
    } else {
        while (true) {}
    }


    return LEO_ERROR_GOOD;
}

s32 LeoCACreateLeoManager(OSPri comPri, OSPri intPri, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    OSPiHandle* driveRomHandle;
    OSPiHandle* leoDiskHandle;
    LEOCmdInquiry cmdBlockInq;
    LEOCmd cmdBlockID;
    LEODiskID thisID;
    u32 stat;
    u32 data;
    s32 dummy;

    if (__leoActive) {
        return LEO_ERROR_GOOD;
    }

    leoDiskHandle = osLeoDiskInit();
    driveRomHandle = osDriveRomInit();

    osEPiReadIo(leoDiskHandle, 0x05000508, &data);
    if (data & 0xFFFF) {
        return LEO_ERROR_DEVICE_COMMUNICATION_FAILURE;
    }
    
    __leoActive = 1;

    __osSetHWIntrRoutine(1, __osLeoInterrupt);
    leoInitialize(comPri, intPri, cmdBuf, cmdMsgCnt);

    if (osResetType == 1) {
        __leoSetReset();
    }

    cmdBlockInq.header.command = 2;
    cmdBlockInq.header.reserve1 = 0;
    cmdBlockInq.header.control = 0;
    cmdBlockInq.header.reserve3 = 0;
    leoCommand((void*)&cmdBlockInq);

    dummy = (u32)__osSetHWIntrRoutine & 0xA48D3C;

    while (dummy < 0xE00000) {
        dummy += (((s32) leoCommand & 0xFF) | 0x8A) << 0x10;
    }

    while (cmdBlockInq.header.status == 8) { }

    if (cmdBlockInq.header.status != 0) {
        return cmdBlockInq.header.sense;
    }
    __leoVersion.driver = cmdBlockInq.version;
    __leoVersion.drive = 4;
    __leoVersion.deviceType = cmdBlockInq.dev_type;
    __leoVersion.ndevices = cmdBlockInq.dev_num;

    if ((__leoVersion.driver & 0xF) == 4) {
        LEO_country_code = 0;
    } else if (((__leoVersion.driver & 0xF) == 3) || ((__leoVersion.driver & 0xF) == 1)) {
        s32 dummy2;
        osEPiReadIo(driveRomHandle, 0x9FF00, &data);
        data = ((data & 0xFF000000) >> 0x18);

        if (data != 4) {
            while (true) {}
        }

        dummy2 = 0x32F8EB20;
        LEO_country_code = 0x2263EE56;
        dummy2 += (u32)&__leoActive;
    } else {
        while (true) {}
    }

    return LEO_ERROR_GOOD;
}
