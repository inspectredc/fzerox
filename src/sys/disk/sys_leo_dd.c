#include "global.h"
#include "leo/leo_internal.h"
#include "leo/mfs.h"

s32 sSLLeoReadWriteBlocksSize;
LEOStatus D_800E32E0;
LEOCmd D_800E32E8;
OSMesgQueue sSLLeoMesgQueue;
OSMesg sSLLeoMsgBuf[1];
OSMesgQueue gMFSMesgQ;
OSMesg D_8079F9B0[1];
s32 D_8079F9B4;
s32 sSLLeoError;
s32 D_8079F9BC;
UNUSED s32 D_8079F9C0;
u8 D_8079F9C4[2];
u8 D_8079F9C8[4];
s32 D_8079F9CC;
OSMesg sSLLeoCmdMsgBuf[16];
LEODiskID D_8079FA10;

LEODiskID D_800CD2B0 = { 0 };
LEODiskID D_8076CB70 = { 0 };
LEODiskID D_8076CB90 = { 0 };
bool D_8076CBB0 = true;
bool D_8076CBB4 = true;
bool D_8076CBB8 = false;
bool D_800CD2D0 = false;
OSThread* D_800CD2D4 = NULL;
s32 D_8076CBC4 = 0;
bool D_8076CBC8 = true;
bool D_8076CBCC = false;

extern s32 gMfsError;

void func_80704050(bool arg0) {
    D_8076CBCC = arg0;
}

void func_8070405C(bool arg0) {
    D_8076CBC8 = arg0;
}

void func_80704068(void) {
    if ((D_800CD2D4 != NULL) && (D_8076CBC4 == 0) && (D_8076CBCC == 0)) {
        osStopThread(D_800CD2D4);
    }
    D_8076CBC4++;
}

void func_807040C8(void) {
    D_8076CBC4--;
    if ((D_800CD2D4 != NULL) && (D_8076CBC4 == 0) && (D_8076CBCC == 0)) {
        osStartThread(D_800CD2D4);
    }
}

s32 func_80704120(LEODiskID diskId) {
    s32 i;

    if (diskId.company[0] != D_8079F9C4[0]) {
        return 1;
    }
    if (diskId.company[1] != D_8079F9C4[1]) {
        return 1;
    }

    if (diskId.gameName[0] < D_8079F9C8[0]) {
        return 1;
    }

    for (i = 1; i < ARRAY_COUNT(diskId.gameName); i++) {
        if (D_8079F9C8[i] != diskId.gameName[i]) {
            return 1;
        }
    }
    return 2;
}

s32 func_807041C0(LEODiskID diskId) {
    s32 i;

    if (diskId.company[0] != D_8079F9C4[0]) {
        return 1;
    }
    if (diskId.company[1] != D_8079F9C4[1]) {
        return 1;
    }

    for (i = 0; i < ARRAY_COUNT(diskId.gameName); i++) {
        if (D_8079F9C8[i] != diskId.gameName[i]) {
            return 1;
        }
    }
    return 2;
}

s32 SLMFSLoadSpecial(u16 dirId, char* name, char* extension, u8* buf, s32 sizeToLoad) {
    PRINTF("SLMFSLoadSpecial LOOP\n");

    while (true) {
        func_80707B08();
        D_8079F9B4 = Mfs_LoadFileInDir(dirId, name, extension, buf, sizeToLoad);

        if (D_8079F9B4 == 0) {
            PRINTF("SLMFSLoadSP Good Return\n");
            return D_8079F9B4;
        }

        sSLLeoError = gMfsError;
        if (gMfsError == N64DD_NOT_FOUND) {
            PRINTF("SLMFSLoadSP error N64DD_NOT_FOUND %s\n", name);
        }
        PRINTF("SLMFSLoadSP error 0x%X\n", gMfsError);
        PRINTF("name %s, type %s\n", name, extension);

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                return 0;
            case N64DD_NOT_FOUND:
                PRINTF("FILE NOT FOUND\n");
                return sSLLeoError;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                PRINTF("hoge43\n");
                PRINTF("hoge44\n");
                PRINTF("UNRECOVERD_READ_ERROR ON SLMFSLoadSP\n");
                return N64DD_NOT_FOUND;
            case 0x10A:
                return 0x10A;
            case N64DD_MEDIA_NOT_INIT:
                PRINTF("MEDIAINIT_AND_WAIT 12\n");
                PRINTF("MEDIAINIT_AND_WAIT 13\n");
                return N64DD_MEDIA_NOT_INIT;
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

extern s32 D_80794CDC;

s32 SLMFSLoadSpecial2(u16 dirId, char* name, char* extension, u8* buf, s32 sizeToLoad) {
    PRINTF("hoge45\n");

    PRINTF("SLMFSLoadSpecial2 LOOP\n");

    while (true) {
        func_80707B08();
        D_8079F9B4 = Mfs_LoadFileInDir(dirId, name, extension, buf, sizeToLoad);

        if (D_8079F9B4 == 0) {
            PRINTF("SLMFSLoadSpecial2 Good Return\n");
            return D_8079F9B4;
        }

        sSLLeoError = gMfsError;

        if (gMfsError == N64DD_NOT_FOUND) {
            PRINTF("SLMFSLoadSP2 error N64DD_NOT_FOUND %s\n", name);
        }
        PRINTF("SLMFSLoadSP2 error 0x%X\n", gMfsError);
        PRINTF("name %s, type %s\n", name, extension);
        if (1) {}

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                return 0;
            case N64DD_NOT_FOUND:
                PRINTF("FILE NOT FOUND SP2\n");
                return sSLLeoError;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                PRINTF("hoge432\n");
                PRINTF("hoge442\n");
                PRINTF("UNRECOVERD_READ_ERROR ON SLMFSLoadSP2\n");
                PRINTF("MEDIAINIT_AND_WAIT SP2\n");
                if (D_80794CDC == 4) {
                    func_80703948();
                    SLMFSRecoverManageArea();
                    return N64DD_NOT_FOUND;
                }
                if (D_80794CDC == 1) {
                    PRINTF("FILE DELETE ON SLMFSLoadSP2\n");
                    SLMFSDeleteFile(dirId, name, extension, 1);
                }
                return N64DD_NOT_FOUND;
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case N64DD_MEDIA_NOT_INIT:
                PRINTF("MEDIAINIT_AND_WAIT SP2\n");
                PRINTF("MEDIAINIT_AND_WAIT SP2\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                break;
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

extern char gEditCupTrackNames[6 * 4][9];

void func_8070470C(void) {
    s32 i;
    PRINTF("hoge45\n");

    if (D_8076CBC8 == 0) {
        return;
    }

    gEditCupTrackNames[0][0] = '\0';
    gEditCupTrackNames[1][0] = '\0';
    gEditCupTrackNames[2][0] = '\0';
    gEditCupTrackNames[3][0] = '\0';
    gEditCupTrackNames[4][0] = '\0';
    gEditCupTrackNames[5][0] = '\0';

    SLMFSLoadSpecial(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames));

    PRINTF("===============================================\n");
    PRINTF("ENTRY LOAD AGAIN\n");
    PRINTF("===============================================\n");

    for (i = 0; i < 6; i++) {
        if (Mfs_ValidateFileName(gEditCupTrackNames[i]) != 0) {
            gEditCupTrackNames[i][0] = '\0';
        }
    }
}

void func_807047AC(void) {
    if (D_8076CBC8 == 0) {
        return;
    }

    gEditCupTrackNames[0][0] = '\0';
    gEditCupTrackNames[1][0] = '\0';
    gEditCupTrackNames[2][0] = '\0';
    gEditCupTrackNames[3][0] = '\0';
    gEditCupTrackNames[4][0] = '\0';
    gEditCupTrackNames[5][0] = '\0';
    SLMFSLoadSpecial2(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames));

    PRINTF("Mesg Wait Before\n");
    PRINTF("===============================================\n");
    PRINTF("ENTRY LOAD AGAIN\n");
    PRINTF("===============================================\n");
}

void func_80704810(bool arg0) {
    D_8076CBB4 = arg0;
}

void func_8070481C(void) {
    PRINTF("NEWDISK_FOR_FZERO2\n");
    D_8076CB70 = leoBootID;
}

void func_80704870(void) {
    func_80704050(true);
    SLLeoReadDiskID(&D_8079FA10);

    if (func_807041C0(D_8079FA10) == 2) {
        PRINTF("RECORD_GAME_DISK_ID\n");
        D_8076CB70 = D_8079FA10;
    } else {
        PRINTF("ID INT NOT EQUAL IN RECORD_GAME_DISKID\n");
        D_8076CB70 = leoBootID;
    }
    if (SLLeoDiskCompare(D_8079FA10, D_800CD2B0)) {
        D_800CD2B0 = D_8079FA10;
        SLMFSNewDisk();
    }
    func_80704050(false);
}

void func_80704AA8(void) {
    func_80704050(true);
    SLLeoReadDiskID(&D_8079FA10);

    if (func_807041C0(D_8079FA10) == 2) {
        PRINTF("RECORD_GAME_DISK_GHOT_COPY_ID\n");
        D_8076CB90 = D_8079FA10;
    } else {
        PRINTF("ID INT NOT EQUAL IN RECORD_GAME_DISKID\n");
        D_8076CB90 = leoBootID;
    }
    if (SLLeoDiskCompare(D_8079FA10, D_800CD2B0)) {
        D_800CD2B0 = D_8079FA10;
        SLMFSNewDisk();
    }
    func_80704050(false);
}

void func_80704CE0(void) {
    OSTime initTime = osGetTime();

    while (osGetTime() - initTime <= OS_NSEC_TO_CYCLES(16226646)) {}
}

void SLForceWritebackDCacheAll(void) {
    OSIntMask prevMask = osGetIntMask();

    osSetIntMask(OS_IM_NONE);
    osWritebackDCacheAll();
    osSetIntMask(prevMask);
}

void func_80704DB0(char* companyCode, char* gameCode) {
    s32 i;

    for (i = 0; i < 2; i++) {
        D_8079F9C4[i] = *companyCode++;
    }

    for (i = 0; i < 4; i++) {
        D_8079F9C8[i] = *gameCode++;
    }
}

bool SLCheckDiskChange(void) {

    PRINTF("SLCheckDiskChange LOOP\n");

    while (true) {
        sSLLeoError = LeoTestUnitReady(&D_800E32E0);

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                return false;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                return true;
            case LEO_ERROR_BUSY:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                return false;
            case LEO_ERROR_COMMAND_TERMINATED:
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

extern LEODiskID D_i1_80428618;
extern u16 gWorkingDirectory;
extern s32 D_i1_80428644;
extern MfsRamArea gMfsRamArea;

void func_80704EB8(void) {
    D_i1_80428618 = D_800CD2B0;
    func_i1_80404204();
    gWorkingDirectory = MFS_ENTRY_ROOT_DIR;
    D_i1_80428644 = 0;
    gMfsRamArea.id.diskId[0] = '\0';
}

void func_80075230(OSThread* arg0) {
    D_800CD2D4 = arg0;
}

bool SLLeoDiskCompare(LEODiskID diskId1, LEODiskID diskId2) {
    s32 i;
    s32* ptr1 = (s32*) &diskId1;
    s32* ptr2 = (s32*) &diskId2;

    PRINTF("hoge0\n");

    for (i = 0; i < sizeof(LEODiskID) / sizeof(s32); i++, ptr1++, ptr2++) {
        if (*ptr1 != *ptr2) {
            return true;
        }
    }

    return false;
}

s32 SLLeoReadDiskID(LEODiskID* diskId) {
    PRINTF("SLLeoReadDiskID LOOP\n");

    while (true) {
        LeoReadDiskID(&D_800E32E8, diskId, &sSLLeoMesgQueue);
        osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);

        PRINTF("GAME ID IS %c%c%c%c\n", diskId->gameName[0], diskId->gameName[2], diskId->gameName[2],
               diskId->gameName[3]);
        PRINTF("KO-JO- LINE NUM iS %d\n", diskId->serialNumber.lineNumber);
        PRINTF("TIME is %d\n", diskId->serialNumber.rawTime);

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                D_800CD2D0 = true;
                return sSLLeoError;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                break;
            case LEO_ERROR_COMMAND_TERMINATED:
            case LEO_ERROR_QUEUE_FULL:
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

s32 SLLeoReadDiskID_for_start(void) {
    PRINTF("hoge2\n");
    PRINTF("hoge3\n");
    PRINTF("hoge4\n");
    PRINTF("SLLeoReadDiskID_for_start\n");

    LeoReadDiskID(&D_800E32E8, &D_800CD2B0, &sSLLeoMesgQueue);
    osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);

    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
            D_800CD2D0 = true;
            return sSLLeoError;
        case LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED:
            return LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            func_8070F8A4(sSLLeoError, 2);
            while (func_80707780() != 0) {}
            break;
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            func_8070F8A4(sSLLeoError, 1);
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
        default:
            func_8070F8A4(sSLLeoError, 0);
            while (true) {}
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            break;
    }

    PRINTF("SLLeoReadDiskID_for_start end\n");
    return sSLLeoError;
}

s32 func_80705270(void) {
    PRINTF("hoge5\n");
    PRINTF("hoge6\n");
    PRINTF("hoge7\n");

    sSLLeoError = LeoTestUnitReady(&D_800E32E0);

    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            SLMFSNewDisk();
            break;
        case LEO_ERROR_BUSY:
            return 1;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            func_8070F8A4(sSLLeoError, 0);
            while (true) {}
    }

    if (D_800E32E0 & LEO_TEST_UNIT_MR) {
        return 1;
    } else {
        return 0;
    }
}

s32 SLLeoReadWrite_DATA(LEOCmd* cmdBlock, s32 direction, s32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq) {
    PRINTF("hoge10\n");

    PRINTF("SLLeoReadWrite_DATA LOOP %d-%d LBA\n", lba, lba + nLbas);

    while (true) {
        func_80707B08();
        if (D_8076CBB0) {
            SLMFSNewDisk();
            D_8076CBB0 = false;
        }
        LeoLBAToByte(lba, nLbas, &sSLLeoReadWriteBlocksSize);
        osInvalDCache(osPhysicalToVirtual(vAddr), sSLLeoReadWriteBlocksSize);
        LeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, &sSLLeoMesgQueue);
        osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);

        PRINTF("SLLeoReadWrite_DATA Finished\n");

        if (sSLLeoError == NULL) {
            PRINTF("MFSMesgQ Send 12\n");
            osSendMesg(mq, sSLLeoError, OS_MESG_NOBLOCK);
        }

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                return 0;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_80704068();
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_QUEUE_FULL:
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

s32 SLLeoReadWrite(LEOCmd* cmdBlock, s32 direction, s32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq) {
    PRINTF("hoge11\n");
    PRINTF("hoge12\n");
    PRINTF("hoge13\n");

    PRINTF("SLLeoReadWrite %d LBA\n", lba);
    PRINTF("SLLeoReadWrite LOOP\n");

    while (true) {
        func_80704068();
        while (SLLeoDiskCompare(D_800CD2B0, leoBootID)) {
            func_8070F8A4(sSLLeoError, 5);
            while (func_80707780() != 0) {}
            while (SLCheckDiskInsert() != 0) {}
        }
        if (D_8076CBB0) {
            SLMFSNewDisk();
            D_8076CBB0 = false;
        }

        if (0) {
            PRINTF("SLLeoReadWrite 0\n");
            PRINTF("SLLeoReadWrite 1\n");
            PRINTF("SLLeoReadWrite 2\n");
        }

        func_807040C8();
        LeoLBAToByte(lba, nLbas, &sSLLeoReadWriteBlocksSize);
        osInvalDCache(osPhysicalToVirtual(vAddr), sSLLeoReadWriteBlocksSize);
        LeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, &sSLLeoMesgQueue);
        osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);

        PRINTF("SLLeoReadWrite ERROR %d\n", sSLLeoError);

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                PRINTF("MFSMesgQ Send 14\n");
                osSendMesg(mq, sSLLeoError, OS_MESG_NOBLOCK);
                if (0) {
                    PRINTF("Stop on SLLeoReadWrite 0\n");
                    PRINTF("Stop on SLLeoReadWrite 1\n");
                    PRINTF("Stop on SLLeoReadWrite 2\n");
                }
                return 0;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_80704068();
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                func_80704068();
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_80704068();
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_80704068();
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_QUEUE_FULL:
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                if (direction == OS_READ) {
                    PRINTF("hoge14\n");
                    PRINTF("hoge15\n");
                    PRINTF("MFSMesgQ Send 14\n");
                    osSendMesg(mq, sSLLeoError, OS_MESG_NOBLOCK);
                    return 0;
                }
                /* fallthrough */
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

s32 func_8070595C(void) {
    static s32 D_8079FA30;

    if (!D_8076CBB8) {
        return 0;
    }

    while ((D_8079FA30 = SLCheckDiskInsert()) == 2) {}

    if (D_8079FA30 == 0) {
        if (func_807041C0(D_800CD2B0) == 2) {
            return 2;
        }
        return 1;
    }

    return 0;
}

void func_80705A38(LEODiskID diskId) {
    D_800CD2B0 = diskId;
}

void func_80705A98(void) {
    osCreateMesgQueue(&sSLLeoMesgQueue, sSLLeoMsgBuf, 1);
    osCreateMesgQueue(&gMFSMesgQ, D_8079F9B0, 1);
}

s32 SLLeoCreateManager(s32 arg0) {

    func_80705A98();
    switch (arg0) {
        case 0:
            sSLLeoError = LeoCreateLeoManager(0x95, 0x96, sSLLeoCmdMsgBuf, ARRAY_COUNT(sSLLeoCmdMsgBuf));
            break;
        case 1:
            sSLLeoError = LeoCJCreateLeoManager(0x95, 0x96, sSLLeoCmdMsgBuf, ARRAY_COUNT(sSLLeoCmdMsgBuf));
            break;
        case 2:
            sSLLeoError = LeoCACreateLeoManager(0x95, 0x96, sSLLeoCmdMsgBuf, ARRAY_COUNT(sSLLeoCmdMsgBuf));
            break;
    }
    if (sSLLeoError == LEO_ERROR_DEVICE_COMMUNICATION_FAILURE) {
        func_8070F8A4(sSLLeoError, 0);
        while (true) {}
    }
    D_8076CBB8 = true;
    return 0;
}

void SLLeoResetClear(void) {
    s32 i;
    PRINTF("hoge16\n");

    for (i = 0; i < 30; i++) {
        if (0) {
            PRINTF("hoge17\n");
            PRINTF("Reset Clear Try\n");
            PRINTF("Reset Clear Try2\n");
            PRINTF("Reset Clear Try3\n");
        }
        func_80704CE0();
        LeoResetClear();
        sSLLeoError = SLLeoReadDiskID_for_start();
        if (sSLLeoError != LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED) {
            PRINTF("Leo Reset Clear Success\n");
            return;
        }
    }
    func_8070F8A4(sSLLeoError, 0);
    while (true) {}
}

void SLLeo_mfs_newdisk(void) {
    PRINTF("hoge18\n");

    PRINTF("mfs_newdisk LOOP\n");

    while (true) {
        switch (SLLeoReadDiskID(&D_800CD2B0)) {
            case LEO_ERROR_GOOD:
                func_80704EB8();
                PRINTF("Stop on mfs_newdisk\n");
                return;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_80704068();
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_80704068();
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
        }
    }
}

void SLLeoModeSelectAsync(u32 standby, u32 sleep) {
    PRINTF("hoge20\n");

    PRINTF("SLLeoModeSelectAsync LOOP\n");

    while (true) {
        LeoModeSelectAsync(&D_800E32E8, standby, sleep, &sSLLeoMesgQueue);
        osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);
        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                return;
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_COMMAND_TERMINATED:
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

extern FrameBuffer* gFrameBuffers[];

void func_80705E18(void) {
    func_80704050(true);
    if (SLCheckDiskChange()) {
        SLMFSNewDisk();
        D_800CD2B0 = D_i1_80428618;
    }
    while (SLLeoDiskCompare(D_800CD2B0, leoBootID) != 0) {

        osViSwapBuffer(gFrameBuffers[0]);
        while (osViGetNextFramebuffer() != gFrameBuffers[0]) {}
        func_8070F8A4(-1, 5);
        osViSwapBuffer(gFrameBuffers[1]);
        while (osViGetNextFramebuffer() != gFrameBuffers[1]) {}
        func_8070F8A4(-1, 5);
        osViSwapBuffer(gFrameBuffers[2]);
        while (osViGetNextFramebuffer() != gFrameBuffers[2]) {}
        func_8070F8A4(-1, 5);
        while (func_80707780() != 0) {}
        while (SLCheckDiskInsert() != 0) {}
    }
    func_80704050(false);
}

void SLMFSRecoverManageArea(void) {
    PRINTF("hoge21\n");
    PRINTF("WAIT_SET_BOOT_DISK\n");
    PRINTF("SLMFSRecoverManageArea LOOP\n");

    while (true) {
        func_80707B08();
        if (D_8076CBB0) {
            SLMFSNewDisk2();
            D_8076CBB0 = false;
        }
        if (Mfs_CopyRamAreaFromBackup() == 0) {
            PRINTF("SLMFSRecoverManageArea Good Return\n");
            break;
        }

        sSLLeoError = gMfsError;
        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                PRINTF("SLMFSRecoverManageArea Good Return\n");
                return;
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                PRINTF("hoge22\n");
                PRINTF("hoge23\n");
                PRINTF("MEDIAINIT_AND_WAIT 0\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return;
            case N64DD_MEDIA_NOT_INIT:
                PRINTF("MEDIA_NOT_INIT on RecoverManageArea\n");
                PRINTF("MEDIAINIT_AND_WAIT 1\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return;
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

void SLMFSGetFilesPreparation(u16 dirId) {
    PRINTF("hoge24\n");
    PRINTF("SLMFSGetFilesPreparation\n");
    PRINTF("SLMFSGetFilesPreparation LOOP\n");

    while (true) {
        func_80707B08();
        if (D_8076CBB0) {
            SLMFSNewDisk();
            D_8076CBB0 = false;
        }
        if (Mfs_GetFilesPreparation(dirId) == 0) {
            return;
        }
        sSLLeoError = gMfsError;
        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case N64DD_MEDIA_NOT_INIT:
                PRINTF("hoge25\n");
                PRINTF("hoge26\n");
                PRINTF("MEDIAINIT_AND_WAIT 2\n");
                PRINTF("MEDIAINIT_AND_WAIT 3\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return;
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

extern u8 D_34E[];
extern u8 D_391[];
extern u8 D_i1_80415190[];
extern OSMesgQueue gDmaMesgQueue;

void func_80706518(s32 copyCount, s32 arg1, char* extension) {
    PRINTF("hoge27\n");
    PRINTF("SLMFSMediaInit Mario Artist Custum !!\n");
    PRINTF("correct disk !!\n");
    PRINTF("MEDIA INIT OK !!\n");

    func_80707B08();

    for (D_8079F9CC = 0; D_8079F9CC < D_391 - D_34E; D_8079F9CC++) {
        osWritebackDCacheAll();
        SLLeoReadWrite_DATA(&D_800E32E8, OS_READ, (u32) D_34E + D_8079F9CC, D_i1_80415190, 1, &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
        osWritebackDCacheAll();
        SLLeoReadWrite_DATA(&D_800E32E8, OS_WRITE, 3062 + D_8079F9CC, D_i1_80415190, 1, &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
    }
    osWritebackDCacheAll();
    SLMFSNewDisk();
}

void SLMFSDeleteFile(u16 dirId, char* name, char* extension, bool writeChanges) {
    PRINTF("SLMFSDeleteFile name:%s, type:%s\n", name, extension);
    PRINTF("SLMFSDeleteFile LOOP\n");

    while (true) {
        func_80707B08();
        if (D_8076CBB0) {
            SLMFSNewDisk();
            D_8076CBB0 = false;
        }
        if (Mfs_DeleteFileInDir(dirId, name, extension, writeChanges) == 0) {
            PRINTF("SLMFSDeleteFile Good Return\n");
            return;
        }

        sSLLeoError = gMfsError;
        PRINTF("SLMFSDeleteFile Return %d\n", sSLLeoError);

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
            case N64DD_NOT_FOUND:
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case N64DD_MEDIA_NOT_INIT:
                PRINTF("hoge40\n");
                PRINTF("hoge41\n");
                PRINTF("MEDIAINIT_AND_WAIT 9\n");
                PRINTF("MEDIAINIT_AND_WAIT 10\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return;
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

s32 SLMFSLoad(u16 dirId, char* name, char* extension, u8* buf, s32 sizeToLoad) {
    PRINTF("hoge42\n");
    PRINTF("============================================================\n");
    PRINTF("SLMFSLoad LOOP %s\n", name);

    osRecvMesg(&gMFSMesgQ, NULL, OS_MESG_NOBLOCK);

    while (true) {
        func_80707B08();
        if (D_8076CBB0) {
            SLMFSNewDisk();
            D_8076CBB0 = false;
        }
        D_8079F9B4 = Mfs_LoadFileInDir(dirId, name, extension, buf, sizeToLoad);
        if (D_8079F9B4 == 0) {
            PRINTF("SLMFSLoad good\n");
            PRINTF("MFSMesgQ Send 16\n");
            osSendMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
            return D_8079F9B4;
        }
        sSLLeoError = gMfsError;

        PRINTF("SLMFSLoad error N64DD_NOT_FOUND %s\n", name);
        PRINTF("SLMFSLoad error 0x%2X\n", sSLLeoError);
        PRINTF("name %s, type %s\n", name, extension);

        if (gMfsError == N64DD_NOT_FOUND) {}
        if (1) {}

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                PRINTF("MFSMesgQ Send 17\n");
                osSendMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
                PRINTF("FILE NOT FOUND\n");
                return 0;
            case N64DD_NOT_FOUND:
                PRINTF("MFSMesgQ Send 18\n");
                osSendMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
                return sSLLeoError;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                PRINTF("hoge43\n");
                PRINTF("hoge44\n");
                PRINTF("UNRECOVERD_READ_ERROR ON SLMFSLoad\n");
                PRINTF("MEDIAINIT_AND_WAIT 11\n");
                if (D_80794CDC == 4) {
                    func_80703948();
                    SLMFSRecoverManageArea();
                } else if (D_80794CDC == 1) {
                    PRINTF("FILE DELETE ON SLMFSLoad\n");
                    SLMFSDeleteFile(dirId, name, extension, 1);
                }
                PRINTF("MFSMesgQ Send 19\n");
                osSendMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
                return N64DD_NOT_FOUND;
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case N64DD_MEDIA_NOT_INIT:
                PRINTF("MEDIAINIT_AND_WAIT 12\n");
                PRINTF("MEDIAINIT_AND_WAIT 13\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                break;
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

s32 SLMFSLoadHalfway(u16 dirId, char* name, char* extension, u8* buf, s32 offset, s32 sizeToLoad) {
    PRINTF("hoge45\n");
    PRINTF("SLMFSLoadHalfway LOOP\n");

    osRecvMesg(&gMFSMesgQ, NULL, OS_MESG_NOBLOCK);

    while (true) {
        func_80707B08();
        if (D_8076CBB0) {
            SLMFSNewDisk();
            D_8076CBB0 = false;
        }
        D_8079F9B4 = Mfs_LoadFileInDirFromOffset(dirId, name, extension, buf, offset, sizeToLoad);

        if (D_8079F9B4 == 0) {
            PRINTF("MFSMesgQ Send 20\n");
            osSendMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
            PRINTF("SLMFSLoadHalfway Finished\n");
            return 0;
        }
        sSLLeoError = gMfsError;
        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                PRINTF("MFSMesgQ Send 21\n");
                osSendMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
                return 0;
            case N64DD_NOT_FOUND:
                PRINTF("MFSMesgQ Send 22\n");
                osSendMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
                return sSLLeoError;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                PRINTF("MAY_HAVE_CHANGED_IN_LOAD_HALFWAY\n");
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                PRINTF("hoge46\n");
                PRINTF("hoge47\n");
                PRINTF("UNRECOVERD_READ_ERROR ON SLMFSLoadHalfway\n");
                PRINTF("MEDIAINIT_AND_WAIT 14\n");
                if (D_80794CDC == 4) {
                    func_80703948();
                    SLMFSRecoverManageArea();
                } else if (D_80794CDC == 1) {
                    PRINTF("FILE DELETE ON SLMFSLoadHalfway\n");
                    SLMFSDeleteFile(dirId, name, extension, true);
                }
                PRINTF("MFSMesgQ Send 23\n");
                osSendMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
                return N64DD_NOT_FOUND;
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case N64DD_MEDIA_NOT_INIT:
                PRINTF("MEDIAINIT_AND_WAIT 15\n");
                PRINTF("MEDIAINIT_AND_WAIT 16\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return N64DD_NOT_FOUND;
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

void SLMFSSave(u16 dirId, char* name, char* extension, u8* buf, u32 fileSize, s32 attr, s32 copyCount,
               bool writeChanges) {
    PRINTF("hoge48\n");
    PRINTF("SLMFSSave\n");
    PRINTF("SLMFSSave LOOP\n");

    osRecvMesg(&gMFSMesgQ, NULL, OS_MESG_NOBLOCK);
    while (true) {
        func_80704068();
        func_80707B08();
        if (D_8076CBB0) {
            SLMFSNewDisk();
            D_8076CBB0 = false;
        }
        func_807040C8();
        if (Mfs_SaveFile(dirId, name, extension, buf, fileSize, attr, copyCount, writeChanges) == 0) {
            PRINTF("MFSMesgQ Send 24\n");
            osSendMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
            return;
        }
        sSLLeoError = gMfsError;
        PRINTF("SLMFSSave Error %d\n", sSLLeoError);

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                PRINTF("MFSMesgQ Send 25\n");
                osSendMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
                if (0) {
                    PRINTF("SLMFSSave 0\n");
                    PRINTF("SLMFSSave 1\n");
                    PRINTF("SLMFSSave 2\n");
                    PRINTF("hoge49\n");
                    PRINTF("SLMFSSave 3\n");
                    PRINTF("hoge50\n");
                }
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_80704068();
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                func_80704068();
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_80704068();
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_80704068();
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case N64DD_MEDIA_NOT_INIT:
                PRINTF("MEDIAINIT_AND_WAIT 17\n");
                PRINTF("MEDIAINIT_AND_WAIT 18\n");
                PRINTF("MEDIAINIT_AND_WAIT 19\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                break;
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

s32 SLMFSCreateManager(s32 region) {
    PRINTF("hoge51\n");
    PRINTF("hoge52\n");

    func_80705A98();
    if ((Mfs_CreateLeoManager(region, sSLLeoCmdMsgBuf, 0x10) != 0) &&
        (gMfsError == LEO_ERROR_DEVICE_COMMUNICATION_FAILURE)) {
        func_8070F8A4(sSLLeoError, 0);
        while (true) {}
    }
    PRINTF("MFS Create Manager Success\n");
    D_8076CBB8 = true;
    return 0;
}

void SLMFSNewDisk(void) {
    PRINTF("SLMFSNewDisk\n");
    PRINTF("SLMFSNewDisk LOOP\n");

    while (true) {
        func_80707B08();
        D_8079F9BC = func_i1_8040428C();
        if (D_8079F9BC == 0) {
            func_8070470C();
            PRINTF("SLMFSNewDisk return %d\n", D_8079F9BC);
            return;
        }
        sSLLeoError = gMfsError;

        PRINTF("SLMFSNewDisk OK (ENTRY LOAD BEFORE)\n");
        PRINTF("SLMFSNewDisk OK (ENTRY LOAD AFTER)\n");
        PRINTF("ERROR SLMFSNewDisk %d\n", sSLLeoError);

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
            case N64DD_READ_ONLY_MEDIA:
                PRINTF("SLMFSNewDisk Good case\n");
                PRINTF("hoge53\n");
                PRINTF("hoge54\n");
                PRINTF("hoge55 %d <-> %d\n");
                PRINTF("hoge55_2\n");
                PRINTF("SLMFSNewDisk Function End\n");
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_COMMAND_TERMINATED:
            case N64DD_MANAGER_NOT_CREATED:
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

void SLMFSNewDisk2(void) {
    PRINTF("SLMFSNewDisk\n");
    PRINTF("SLMFSNewDisk LOOP\n");

    while (true) {
        func_80707B08();
        D_8079F9BC = func_i1_8040428C();

        if (D_8079F9BC == 0) {
            PRINTF("SLMFSNewDisk return %d\n", D_8079F9BC);
            return;
        }

        sSLLeoError = gMfsError;
        PRINTF("ERROR SLMFSNewDisk %d\n", sSLLeoError);

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
            case N64DD_READ_ONLY_MEDIA:
                PRINTF("SLMFSNewDisk Good case\n");
                PRINTF("hoge53\n");
                PRINTF("hoge54\n");
                PRINTF("hoge55 %d <-> %d\n");
                PRINTF("hoge55_2\n");
                PRINTF("SLMFSNewDisk Function End\n");
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_COMMAND_TERMINATED:
            case N64DD_MANAGER_NOT_CREATED:
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

void SLMFSFlushManageArea(void) {
    PRINTF("SLMFSFlushManageArea LOOP\n");

    while (true) {
        func_80704068();
        func_80707B08();
        if (D_8076CBB0) {
            SLMFSNewDisk();
            D_8076CBB0 = false;
        }
        func_807040C8();
        if (Mfs_BackupRamArea() == 0) {
            return;
        }
        sSLLeoError = gMfsError;
        PRINTF("SLMFSFlushManageArea Error %d\n", sSLLeoError);

        if (0) {
            PRINTF("SLMFSFlush 0\n");
            PRINTF("SLMFSFlush 1\n");
            PRINTF("SLMFSFlush 2\n");
            PRINTF("hoge56\n");
            PRINTF("SLMFSFlush 3\n");
        }

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_80704068();
                func_8070F8A4(sSLLeoError, 4);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                func_80704068();
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_80704068();
                func_8070F8A4(sSLLeoError, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_80704068();
                func_8070F8A4(sSLLeoError, 1);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case N64DD_MEDIA_NOT_INIT:
                PRINTF("hoge57\n");
                PRINTF("MEDIAINIT_AND_WAIT 20\n");
                PRINTF("hoge58\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return;
            case LEO_ERROR_COMMAND_TERMINATED:
            case LEO_ERROR_DEVICE_COMMUNICATION_FAILURE:
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

extern LEOCmd D_800E32E8;

s32 func_80707780(void) {
    while (true) {
        LeoSpdlMotor(&D_800E32E8, LEO_MOTOR_BRAKE, &sSLLeoMesgQueue);
        osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);
        switch (sSLLeoError) {
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_GOOD:
                return 1;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                return 0;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                return 0;
            case LEO_ERROR_COMMAND_TERMINATED:
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

s32 func_80707868(LEODiskID* diskId) {
    PRINTF("hoge1\n");

    LeoReadDiskID(&D_800E32E8, diskId, &sSLLeoMesgQueue);
    osRecvMesg(&sSLLeoMesgQueue, &sSLLeoError, OS_MESG_BLOCK);

    PRINTF("GAME ID IS %c%c%c%c\n", diskId->gameName[0], diskId->gameName[1], diskId->gameName[2], diskId->gameName[3]);

    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
            D_800CD2D0 = true;
            return sSLLeoError;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            break;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            func_8070F8A4(sSLLeoError, 2);
            while (func_80707780() != 0) {}
            break;
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            func_8070F8A4(sSLLeoError, 1);
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        case LEO_ERROR_QUEUE_FULL:
        default:
            func_8070F8A4(sSLLeoError, 0);
            while (true) {}
    }
    return sSLLeoError;
}

s32 SLCheckDiskInsert(void) {
    PRINTF("hoge4\n");

    sSLLeoError = LeoTestUnitReady(&D_800E32E0);
    switch (sSLLeoError) {
        case LEO_ERROR_GOOD:
            PRINTF("Test Unit Ready In check_insert -> GOOD\n");
            if (!D_800CD2D0) {
                if (func_80707868(&D_800CD2B0) == 0) {
                    D_8076CBB0 = true;
                    return 0;
                }
                return 1;
            }
            return 0;
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            PRINTF("Test Unit Ready -> MAY_HAVE_CHANGED\n");
            if (func_80707868(&D_800CD2B0) == 0) {
                D_8076CBB0 = true;
                return 0;
            }
            break;
        case LEO_ERROR_BUSY:
            return 2;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            return 1;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            func_8070F8A4(sSLLeoError, 0);
            while (true) {}
    }
    return 1;
}

bool SLCheckDiskChange2(void) {
    PRINTF("hoge8\n");
    PRINTF("hoge0\n");

    while (true) {
        sSLLeoError = LeoTestUnitReady(&D_800E32E0);

        switch (sSLLeoError) {
            case LEO_ERROR_GOOD:
                return false;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                PRINTF("MAY_HAVE_CHANGE in SLCheckDiskChange2 newdisk request\n");
                PRINTF("In Edit\n");
                return true;
            case LEO_ERROR_BUSY:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                PRINTF("In Game\n");
                PRINTF("MAY_HAVE_CHANGE in SLCheckDiskChange2 newdisk request\n");
                return true;
            case LEO_ERROR_COMMAND_TERMINATED:
            default:
                func_8070F8A4(sSLLeoError, 0);
                while (true) {}
        }
    }
}

void func_80707B08(void) {
    if (SLCheckDiskChange2()) {
        SLLeoReadDiskID(&D_800CD2B0);
        D_8076CBB0 = true;
    }
    if (!D_8076CBB4) {
        func_80704068();
        while (func_807041C0(D_800CD2B0) != 2) {
            func_8070F8A4(sSLLeoError, 3);
            while (func_80707780() != 0) {}
            while (SLCheckDiskInsert() != 0) {}
            D_8076CBB0 = true;
        }
        func_807040C8();
    } else {
        func_80704068();
        while (SLLeoDiskCompare(D_800CD2B0, D_8076CB70)) {
            func_8070F8A4(sSLLeoError, 8);
            while (func_80707780() == 1) {}
            while (SLCheckDiskInsert() != 0) {}
            D_8076CBB0 = true;
        }
        func_807040C8();
    }
}

void func_80707E58(void) {
    if (SLCheckDiskChange2()) {
        SLLeoReadDiskID(&D_800CD2B0);
        D_8076CBB0 = true;
    }
    while (SLLeoDiskCompare(D_800CD2B0, D_8076CB90) != 0) {
        func_8070F8A4(-1, 12);
        while (func_80707780() == 1) {}
        while (SLCheckDiskInsert() != 0) {}
        D_8076CBB0 = true;
    }
}
