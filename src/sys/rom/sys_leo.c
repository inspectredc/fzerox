#include "global.h"
#include "PR/leo.h"
#include "leo/mfs.h"
#include "fzx_thread.h"

#if BUILD_REVISION == REVISION_C
s32 sSLLeoReadWriteBlocksSize;
#endif
LEOStatus D_800E32E0;
LEOCmd D_800E32E8;
OSMesgQueue sSLLeoMesgQueue;
OSMesg sSLLeoMsgBuf[1];
s32 sSLLeoError;
#if (BUILD_REVISION == REVISION_A) || (BUILD_REVISION == REVISION_C)
UNUSED s32 D_800E3318_JP;
#endif
s32 D_800E3328;
u8 D_800E332C[4];
OSMesg sSLLeoCmdMsgBuf[16];

extern s32 gLeoDriveConnectionState;
extern OSMesgQueue gMainThreadMesgQueue;

LEODiskID D_800CD2B0 = { 0 };
bool D_800CD2D0 = false;
OSThread* D_800CD2D4 = NULL;

#if BUILD_REVISION == REVISION_C
void func_80075070(void) {
    s32 i;

    for (i = 0; i < 0xFFFFF; i++) {}
}
#endif

void SLForceWritebackDCacheAll(void) {
    OSIntMask prevMask = osGetIntMask();

    osSetIntMask(OS_IM_NONE);
    osWritebackDCacheAll();
    osSetIntMask(prevMask);
}

void func_800751FC(char* gameCode) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800E332C[i] = *gameCode++;
    }
}

void func_80075228(void) {
}

void func_80075230(OSThread* arg0) {
    D_800CD2D4 = arg0;
}

bool SLLeoDiskCompare(LEODiskID diskId1, LEODiskID diskId2) {
    s32 i;
    s32* ptr1 = (s32*) &diskId1;
    s32* ptr2 = (s32*) &diskId2;

    for (i = 0; i < sizeof(LEODiskID) / sizeof(s32); i++, ptr1++, ptr2++) {
        if (*ptr1 != *ptr2) {
            return true;
        }
    }

    return false;
}

bool func_800752EC(void) {

    LeoSpdlMotor(&D_800E32E8, LEO_MOTOR_BRAKE, &sSLLeoMesgQueue);
    osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);
    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            return true;
        case LEO_ERROR_QUEUE_FULL:
            return func_800752EC();
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
#if BUILD_REVISION == REVISION_C
            func_80075228();
#endif
            return false;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReferUserGuide();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (true) {}
    }
}

s32 func_800753EC(void) {

    LeoReadDiskID(&D_800E32E8, &D_800CD2B0, &sSLLeoMesgQueue);
    osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);

    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
            D_800CD2D0 = true;
            return sSLLeoError;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            break;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReinsertDisk();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();

            while (func_800752EC()) {}
            break;
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            SLForceWritebackDCacheAll();
            LeoFault_DrawCautionDoNotRemove();
            SLForceWritebackDCacheAll();
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        case LEO_ERROR_QUEUE_FULL:
        default:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReferUserGuide();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (true) {}
    }

    return sSLLeoError;
}

s32 SLLeoReadDiskID_for_start(void) {

    LeoReadDiskID(&D_800E32E8, &D_800CD2B0, &sSLLeoMesgQueue);
    osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);

    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
            D_800CD2D0 = true;
            return sSLLeoError;
        case LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED:
            return LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReinsertDisk();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (func_800752EC()) {}
            break;

        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            SLForceWritebackDCacheAll();
            LeoFault_DrawCautionDoNotRemove();
            SLForceWritebackDCacheAll();
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        case LEO_ERROR_QUEUE_FULL:
        default:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReferUserGuide();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (true) {}
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            break;
    }

    return sSLLeoError;
}

s32 func_80075690(LEODiskID diskId) {
    s32 i;
    char company[] = { '0', '1' };

    if (diskId.company[0] != company[0]) {
        return 1;
    }
    if (diskId.company[1] != company[1]) {
        return 1;
    }

    if (diskId.gameName[0] < D_800E332C[0]) {
        return 1;
    }

    for (i = 1; i < ARRAY_COUNT(diskId.gameName); i++) {
        if (D_800E332C[i] != diskId.gameName[i]) {
            return 1;
        }
    }
    return 2;
}

s32 func_80075738(LEODiskID diskId) {
    s32 i;
    char company[] = { '0', '1' };

    if (diskId.company[0] != company[0]) {
        return 1;
    }
    if (diskId.company[1] != company[1]) {
        return 1;
    }

    for (i = 0; i < ARRAY_COUNT(diskId.gameName); i++) {
        if (D_800E332C[i] != diskId.gameName[i]) {
            return 1;
        }
    }
    return 2;
}

s32 SLCheckDiskInsert(void) {

    sSLLeoError = LeoTestUnitReady(&D_800E32E0);

    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
            if (!D_800CD2D0) {
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
            SLForceWritebackDCacheAll();
            LeoFault_DrawReferUserGuide();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (true) {}
    }
    return 1;
}

s32 func_800758F8(void) {

    sSLLeoError = LeoTestUnitReady(&D_800E32E0);

    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
#if BUILD_REVISION == REVISION_C
            func_80075228();
#endif
            break;
        case LEO_ERROR_BUSY:
            return 1;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReferUserGuide();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (true) {}
    }

    if (D_800E32E0 & LEO_TEST_UNIT_MR) {
        return 1;
    } else {
        return 0;
    }
}

s32 SLLeoReadWrite_DATA(LEOCmd* cmdBlock, s32 direction, u32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq) {
    OSMesg msg;

    while (func_80075738(D_800CD2B0) != 2) {

        SLForceWritebackDCacheAll();
        LeoFault_DrawWrongDisk();
        SLForceWritebackDCacheAll();

        while (func_800752EC()) {}
        while (SLCheckDiskInsert()) {}
    }
#if BUILD_REVISION == REVISION_C
    LeoLBAToByte(lba, nLbas, &sSLLeoReadWriteBlocksSize);
    osInvalDCache(osPhysicalToVirtual(vAddr), sSLLeoReadWriteBlocksSize);
#endif
    LeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, &sSLLeoMesgQueue);
    osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);

    msg = sSLLeoError;

    if (msg == NULL) {
        osSendMesg(mq, msg, OS_MESG_NOBLOCK);
    }

    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
            return 0;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            SLForceWritebackDCacheAll();
            LeoFault_DrawIsDiskInserted();
            SLForceWritebackDCacheAll();

            while (SLCheckDiskInsert()) {}
            return SLLeoReadWrite_DATA(cmdBlock, direction, lba, vAddr, nLbas, mq);
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:

            while (SLCheckDiskInsert()) {}
            func_80075228();
            return SLLeoReadWrite_DATA(cmdBlock, direction, lba, vAddr, nLbas, mq);
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            SLForceWritebackDCacheAll();
            LeoFault_DrawCautionDoNotRemovePleaseInsert();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();

            while (SLCheckDiskInsert()) {}
            return SLLeoReadWrite_DATA(cmdBlock, direction, lba, vAddr, nLbas, mq);
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReinsertDisk();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();

            while (func_800752EC()) {}
            while (SLCheckDiskInsert()) {}

            return SLLeoReadWrite_DATA(cmdBlock, direction, lba, vAddr, nLbas, mq);
        case LEO_ERROR_QUEUE_FULL:
            return SLLeoReadWrite_DATA(cmdBlock, direction, lba, vAddr, nLbas, mq);
        case LEO_ERROR_UNRECOVERED_READ_ERROR:
            if (direction == OS_READ) {
                break;
            }
        /* fallthrough */
        default:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReferUserGuide();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (true) {}
    }

    return 0;
}

s32 SLLeoReadWrite(LEOCmd* cmdBlock, s32 direction, s32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq) {
    OSMesg msg;

    while (SLLeoDiskCompare(D_800CD2B0, leoBootID)) {

        SLForceWritebackDCacheAll();
        LeoFault_DrawInsertInitialDiskUsed();
        SLForceWritebackDCacheAll();

        while (func_800752EC()) {}
        while (SLCheckDiskInsert()) {}
    }
#if BUILD_REVISION == REVISION_C
    LeoLBAToByte(lba, nLbas, &sSLLeoReadWriteBlocksSize);
    osInvalDCache(osPhysicalToVirtual(vAddr), sSLLeoReadWriteBlocksSize);
#endif
    LeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, &sSLLeoMesgQueue);
    osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);

    msg = sSLLeoError;

    if (msg == NULL) {
        osSendMesg(mq, msg, OS_MESG_NOBLOCK);
    }

    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
            return 0;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            SLForceWritebackDCacheAll();
            LeoFault_DrawIsDiskInserted();
            SLForceWritebackDCacheAll();

            while (SLCheckDiskInsert()) {}
            return SLLeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, mq);
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:

            while (SLCheckDiskInsert()) {}
            func_80075228();
            return SLLeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, mq);
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            SLForceWritebackDCacheAll();
            LeoFault_DrawCautionDoNotRemovePleaseInsert();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();

            while (SLCheckDiskInsert()) {}
            return SLLeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, mq);
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReinsertDisk();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();

            while (func_800752EC()) {}
            while (SLCheckDiskInsert()) {}
            return SLLeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, mq);
        case LEO_ERROR_QUEUE_FULL:
            return SLLeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, mq);
        case LEO_ERROR_UNRECOVERED_READ_ERROR:
            if (direction == OS_READ) {
                break;
            }
        /* fallthrough */
        default:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReferUserGuide();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (true) {}
    }

    return 0;
}

s32 func_800760F8(void) {
    static s32 D_800E3370;

    if (gLeoDriveConnectionState == 0) {
        return 0;
    }

    while ((D_800E3370 = SLCheckDiskInsert()) == 2) {}

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

    if (gLeoDriveConnectionState == 0) {
        return 0;
    }

    while ((D_800E3374 = SLCheckDiskInsert()) == 2) {}

    if (D_800E3374 == 0) {
        if (func_80075690(D_800CD2B0) == 2) {
            return 2;
        }
        return 1;
    }

    return 0;
}

void func_800762B0(LEODiskID diskId) {
    D_800CD2B0 = diskId;
}

void func_80076310(void) {
    osCreateMesgQueue(&sSLLeoMesgQueue, sSLLeoMsgBuf, ARRAY_COUNT(sSLLeoMsgBuf));
}

s32 SLLeoCreateManager(void) {

    osCreateMesgQueue(&sSLLeoMesgQueue, sSLLeoMsgBuf, ARRAY_COUNT(sSLLeoMsgBuf));
#if LANGUAGE == LANGUAGE_JPN
    sSLLeoError = LeoCJCreateLeoManager(149, 150, sSLLeoCmdMsgBuf, ARRAY_COUNT(sSLLeoCmdMsgBuf));
#else
    sSLLeoError = LeoCACreateLeoManager(149, 150, sSLLeoCmdMsgBuf, ARRAY_COUNT(sSLLeoCmdMsgBuf));
#endif

    if (sSLLeoError == LEO_ERROR_DEVICE_COMMUNICATION_FAILURE) {
        return -1;
    }
    return 0;
}

void SLLeoResetClear(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        do {
            osRecvMesg(&gMainThreadMesgQueue, &D_800E3328, OS_MESG_BLOCK);
        } while (D_800E3328 != EVENT_MESG_VI);

        LeoResetClear();
        sSLLeoError = SLLeoReadDiskID_for_start();

        if (sSLLeoError != LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED) {
            return;
        }
    }
    SLForceWritebackDCacheAll();
    LeoFault_DrawReferUserGuide();
    LeoFault_DrawErrorNumber(sSLLeoError);
    SLForceWritebackDCacheAll();
    while (true) {}
}

#if BUILD_REVISION <= REVISION_B
void func_8007647C(void) {
}
#endif

#if BUILD_REVISION == REVISION_C
void func_800763B0(void) {

    switch (func_800753EC()) {
        case LEO_ERROR_GOOD:
            func_80075228();
            break;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            SLForceWritebackDCacheAll();
            LeoFault_DrawIsDiskInserted();
            SLForceWritebackDCacheAll();
            while (SLCheckDiskInsert()) {}
            func_800763B0();
            break;
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            SLForceWritebackDCacheAll();
            LeoFault_DrawCautionDoNotRemovePleaseInsert();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (SLCheckDiskInsert()) {}
            func_800763B0();
            break;
    }
}

void func_800764AC(u32 standby, u32 sleep) {

    LeoModeSelectAsync(&D_800E32E8, standby, sleep, &sSLLeoMesgQueue);
    osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);
    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
        case LEO_ERROR_QUEUE_FULL:
            break;
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            while (true) {
                if (SLCheckDiskInsert() != 0) {
                    SLForceWritebackDCacheAll();
                    LeoFault_DrawIsDiskInserted();
                    SLForceWritebackDCacheAll();
                }
                while (SLCheckDiskInsert()) {}
                func_80075228();
                if (func_80075738(D_800CD2B0) == 2) {
                    break;
                }
                SLForceWritebackDCacheAll();
                LeoFault_DrawWrongDisk();
                SLForceWritebackDCacheAll();
                while (func_800752EC()) {}
            }
            func_800764AC(standby, sleep);
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReferUserGuide();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (true) {}
    }
}

// Roughly correct w/ wrong symbol names
void func_80076678(u16 arg0) {

    while (func_80075738(D_800CD2B0) != 2) {

        SLForceWritebackDCacheAll();
        LeoFault_DrawWrongDisk();
        SLForceWritebackDCacheAll();

        while (func_800752EC()) {}
        while (SLCheckDiskInsert()) {}
    }

    Mfs_GetFilesPreparation(arg0);
    switch (gMfsError) {
        case LEO_ERROR_GOOD:
            break;
        case LEO_ERROR_BUSY:
        case LEO_ERROR_QUEUE_FULL:
            func_80075070();
            func_80076678(arg0);
            break;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            SLForceWritebackDCacheAll();
            LeoFault_DrawIsDiskInserted();
            SLForceWritebackDCacheAll();
            while (SLCheckDiskInsert()) {}
            func_80075228();
            func_80076678(arg0);
            /* fallthrough */
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            while (SLCheckDiskInsert()) {}
            func_80075228();
            func_80076678(arg0);
            break;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReinsertDisk();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (func_800752EC()) {}
            while (SLCheckDiskInsert()) {}
            func_80075228();
            func_80076678(arg0);
            break;
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            SLForceWritebackDCacheAll();
            LeoFault_DrawCautionDoNotRemovePleaseInsert();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (SLCheckDiskInsert()) {}
            func_80076678(arg0);
            /* fallthrough */
        case LEO_ERROR_UNRECOVERED_READ_ERROR:
        case 0x10A:
            Mfs_CopyRamAreaFromBackup();
            break;
        default:
            SLForceWritebackDCacheAll();
            LeoFault_DrawReferUserGuide();
            LeoFault_DrawErrorNumber(sSLLeoError);
            SLForceWritebackDCacheAll();
            while (true) {}
    }
}
#endif
