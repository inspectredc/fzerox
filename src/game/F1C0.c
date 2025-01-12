#include "global.h"
#include "PR/leo.h"
#include "fzxthread.h"

LEOStatus D_800E32E0;
LEOCmd D_800E32E8;
OSMesgQueue gLeoMesgQueue;
OSMesg sLeoMsgBuf[1];
OSMesg sLeoErrMsg;
OSMesg D_800E3328;
u8 D_800E332C[4];
OSMesg sLeoCmdMsgBuf[16];

extern bool gLeoDDConnected;
extern OSMesgQueue gMainThreadMesgQueue;

LEODiskID D_800CD2B0 = { 0 };
s32 D_800CD2D0 = 0;
OSThread* D_800CD2D4 = NULL;

void LeoDD_ForceWritebackDCacheAll(void) {
    OSIntMask prevMask = osGetIntMask();

    osSetIntMask(OS_IM_NONE);
    osWritebackDCacheAll();
    osSetIntMask(prevMask);
}

void func_800751FC(char* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800E332C[i] = *arg0++;
    }
}

void func_80075228(void) {
}

void func_80075230(OSThread* arg0) {
    D_800CD2D4 = arg0;
}

bool func_8007523C(LEODiskID arg0, LEODiskID arg1) {
    s32 i;
    s32* var_v0 = (s32*) &arg0;
    s32* var_v1 = (s32*) &arg1;

    for (i = 0; i < sizeof(LEODiskID) / sizeof(s32); i++, var_v0++, var_v1++) {
        if (*var_v0 != *var_v1) {
            return true;
        }
    }

    return false;
}

void LeoDD_DrawReferUserGuide(void);

bool func_800752EC(void) {

    LeoSpdlMotor(&D_800E32E8, LEO_MOTOR_BRAKE, &gLeoMesgQueue);
    osRecvMesg(&gLeoMesgQueue, &sLeoErrMsg, OS_MESG_BLOCK);
    switch ((s32) sLeoErrMsg) {
        case LEO_ERROR_GOOD:
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            return true;
        case LEO_ERROR_QUEUE_FULL:
            return func_800752EC();
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            return false;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReferUserGuide();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();
            while (true) {}
    }
}

OSMesg func_800753EC(void) {

    LeoReadDiskID(&D_800E32E8, &D_800CD2B0, &gLeoMesgQueue);
    osRecvMesg(&gLeoMesgQueue, &sLeoErrMsg, OS_MESG_BLOCK);

    switch ((s32) sLeoErrMsg) {
        case LEO_ERROR_GOOD:
            D_800CD2D0 = 1;
            return sLeoErrMsg;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            break;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReinsertDisk();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();

            while (func_800752EC()) {}
            break;
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawCautionDoNotRemove();
            LeoDD_ForceWritebackDCacheAll();
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        case LEO_ERROR_QUEUE_FULL:
        default:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReferUserGuide();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();
            while (true) {}
    }

    return sLeoErrMsg;
}

OSMesg func_80075534(void) {

    LeoReadDiskID(&D_800E32E8, &D_800CD2B0, &gLeoMesgQueue);
    osRecvMesg(&gLeoMesgQueue, &sLeoErrMsg, OS_MESG_BLOCK);

    switch ((s32) sLeoErrMsg) {
        case LEO_ERROR_GOOD:
            D_800CD2D0 = 1;
            return sLeoErrMsg;
        case LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED:
            return (OSMesg) LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReinsertDisk();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();
            while (func_800752EC()) {}
            break;

        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawCautionDoNotRemove();
            LeoDD_ForceWritebackDCacheAll();
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        case LEO_ERROR_QUEUE_FULL:
        default:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReferUserGuide();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();
            while (true) {}
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            break;
    }

    return sLeoErrMsg;
}

s32 func_80075690(LEODiskID arg0) {
    s32 i;
    char company[] = { '0', '1' };

    if (arg0.company[0] != company[0]) {
        return 1;
    }
    if (arg0.company[1] != company[1]) {
        return 1;
    }

    if (arg0.gameName[0] < D_800E332C[0]) {
        return 1;
    }

    for (i = 1; i < ARRAY_COUNT(arg0.gameName); i++) {
        if (D_800E332C[i] != arg0.gameName[i]) {
            return 1;
        }
    }
    return 2;
}

s32 func_80075738(LEODiskID arg0) {
    s32 i;
    char company[] = { '0', '1' };

    if (arg0.company[0] != company[0]) {
        return 1;
    }
    if (arg0.company[1] != company[1]) {
        return 1;
    }

    for (i = 0; i < ARRAY_COUNT(arg0.gameName); i++) {
        if (D_800E332C[i] != arg0.gameName[i]) {
            return 1;
        }
    }
    return 2;
}

void func_80075228(void);

s32 func_80075800(void) {

    sLeoErrMsg = LeoTestUnitReady(&D_800E32E0);

    switch ((s32) sLeoErrMsg) {
        case LEO_ERROR_GOOD:
            if (D_800CD2D0 == 0) {
                if (func_800753EC() == 0) {
                    return 0;
                }
                return 1;
            }
            return 0;
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            if (func_800753EC() == 0) {
                func_80075228();
                return 0;
            }
            break;
        case LEO_ERROR_BUSY:
            return 2;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            return 1;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReferUserGuide();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();
            while (true) {}
    }
    return 1;
}

s32 func_800758F8(void) {

    sLeoErrMsg = LeoTestUnitReady(&D_800E32E0);

    switch ((s32) sLeoErrMsg) {
        case LEO_ERROR_BUSY:
            return 1;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReferUserGuide();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();
            while (true) {}
        case LEO_ERROR_GOOD:
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            if (D_800E32E0 & LEO_TEST_UNIT_MR) {
                return 1;
            } else {
                return 0;
            }
    }
}

bool func_800759AC(LEOCmd* cmdBlock, s32 direction, u32 LBA, void* vAddr, u32 nLBAs, OSMesgQueue* arg5) {
    OSMesg msg;

    while (func_80075738(D_800CD2B0) != 2) {

        LeoDD_ForceWritebackDCacheAll();
        LeoDD_DrawWrongDisk();
        LeoDD_ForceWritebackDCacheAll();

        while (func_800752EC()) {}
        while (func_80075800()) {}
    }
    LeoReadWrite(cmdBlock, direction, LBA, vAddr, nLBAs, &gLeoMesgQueue);
    osRecvMesg(&gLeoMesgQueue, &sLeoErrMsg, OS_MESG_BLOCK);

    msg = sLeoErrMsg;

    if (msg == NULL) {
        osSendMesg(arg5, msg, OS_MESG_NOBLOCK);
    }

    switch ((s32) sLeoErrMsg) {
        case LEO_ERROR_GOOD:
            return false;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawIsDiskInserted();
            LeoDD_ForceWritebackDCacheAll();

            while (func_80075800()) {}
            return func_800759AC(cmdBlock, direction, LBA, vAddr, nLBAs, arg5);
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:

            while (func_80075800()) {}
            func_80075228();
            return func_800759AC(cmdBlock, direction, LBA, vAddr, nLBAs, arg5);
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawCautionDoNotRemovePleaseInsert();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();

            while (func_80075800()) {}
            return func_800759AC(cmdBlock, direction, LBA, vAddr, nLBAs, arg5);
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReinsertDisk();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();

            while (func_800752EC()) {}
            while (func_80075800()) {}

            return func_800759AC(cmdBlock, direction, LBA, vAddr, nLBAs, arg5);
        case LEO_ERROR_QUEUE_FULL:
            return func_800759AC(cmdBlock, direction, LBA, vAddr, nLBAs, arg5);
        case LEO_ERROR_UNRECOVERED_READ_ERROR:
            if (direction == OS_READ) {
                break;
            }
        /* fallthrough */
        default:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReferUserGuide();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();
            while (true) {}
    }

    return false;
}

bool func_80075D10(LEOCmd* cmdBlock, s32 direction, s32 LBA, void* vaddr, u32 nLBAs, OSMesgQueue* arg5) {
    OSMesg msg;

    while (func_8007523C(D_800CD2B0, leoBootID)) {

        LeoDD_ForceWritebackDCacheAll();
        LeoDD_DrawInsertInitialDiskUsed();
        LeoDD_ForceWritebackDCacheAll();

        while (func_800752EC()) {}
        while (func_80075800()) {}
    }
    LeoReadWrite(cmdBlock, direction, LBA, vaddr, nLBAs, &gLeoMesgQueue);
    osRecvMesg(&gLeoMesgQueue, &sLeoErrMsg, OS_MESG_BLOCK);

    msg = sLeoErrMsg;

    if (msg == NULL) {
        osSendMesg(arg5, msg, OS_MESG_NOBLOCK);
    }

    switch ((s32) sLeoErrMsg) {
        case LEO_ERROR_GOOD:
            return 0;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawIsDiskInserted();
            LeoDD_ForceWritebackDCacheAll();

            while (func_80075800()) {}
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:

            while (func_80075800()) {}
            func_80075228();
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawCautionDoNotRemovePleaseInsert();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();

            while (func_80075800()) {}
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReinsertDisk();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();

            while (func_800752EC()) {}
            while (func_80075800()) {}
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case LEO_ERROR_QUEUE_FULL:
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case LEO_ERROR_UNRECOVERED_READ_ERROR:
            if (direction == OS_READ) {
                break;
            }
        /* fallthrough */
        default:
            LeoDD_ForceWritebackDCacheAll();
            LeoDD_DrawReferUserGuide();
            LeoDD_DrawErrorNumber(sLeoErrMsg);
            LeoDD_ForceWritebackDCacheAll();
            while (true) {}
    }

    return false;
}

s32 func_800760F8(void) {
    static s32 D_800E3370;

    if (!gLeoDDConnected) {
        return 0;
    }
    D_800E3370 = func_80075800();

    while (D_800E3370 == 2) {
        D_800E3370 = func_80075800();
    }
    if (D_800E3370 == 0) {
        if (func_80075738(D_800CD2B0) == 2) {
            return 2;
        }
        return 1;
    }

    return 0;
}

s32 func_800761D4(void) {
    static s32 D_800E3374;

    if (!gLeoDDConnected) {
        return 0;
    }
    D_800E3374 = func_80075800();

    while (D_800E3374 == 2) {
        D_800E3374 = func_80075800();
    }
    if (D_800E3374 == 0) {
        if (func_80075690(D_800CD2B0) == 2) {
            return 2;
        }
        return 1;
    }

    return 0;
}

void func_800762B0(LEODiskID arg0) {
    D_800CD2B0 = arg0;
}

void func_80076310(void) {
    osCreateMesgQueue(&gLeoMesgQueue, sLeoMsgBuf, ARRAY_COUNT(sLeoMsgBuf));
}

s32 func_80076340(void) {

    osCreateMesgQueue(&gLeoMesgQueue, sLeoMsgBuf, ARRAY_COUNT(sLeoMsgBuf));
    sLeoErrMsg = LeoCACreateLeoManager(149, 150, sLeoCmdMsgBuf, ARRAY_COUNT(sLeoCmdMsgBuf));

    if ((s32) sLeoErrMsg == LEO_ERROR_DEVICE_COMMUNICATION_FAILURE) {
        return -1;
    }
    return 0;
}

void func_800763A8(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        do {
            osRecvMesg(&gMainThreadMesgQueue, &D_800E3328, OS_MESG_BLOCK);
        } while (D_800E3328 != (OSMesg) EVENT_MESG_VI);

        LeoResetClear();
        sLeoErrMsg = func_80075534();

        if ((s32) sLeoErrMsg != LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED) {
            return;
        }
    }
    LeoDD_ForceWritebackDCacheAll();
    LeoDD_DrawReferUserGuide();
    LeoDD_DrawErrorNumber(sLeoErrMsg);
    LeoDD_ForceWritebackDCacheAll();
    while (true) {}
}

void func_8007647C(void) {
}
