#include "leo/mfs.h"
#include "macros.h"
#include "libc/stddef.h"

#if VERSION_PAL
void func_i1_8040BF40(void) {
    UNUSED s32 pad;
}
#endif

void func_i1_80403D30(void) {
    osCreateMesgQueue(&D_i1_8042A5E8, D_i1_8042A5E4, ARRAY_COUNT(D_i1_8042A5E4));
}

s32 func_i1_80403D68(void) {
    s32 i = 0;

    LeoResetClear();

    while (true) {
        if (Mfs_ReadDiskId(&D_i1_80428618) == 0) {
            break;
        }

        if (++i >= 4) {
            return -1;
        }

        switch (gMfsError) {
            case LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED:
                gMfsError = 0xF9;
                return -1;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                break;
            default:
                return -1;
        }
    }

    return 0;
}

s32 func_i1_80403E3C(void) {
    return func_i1_80403D68();
}

s32 func_i1_80403E6C(void) {
    s32 i = 0;

    while (true) {
        if (Mfs_ReadDiskId(&D_i1_80428618) == 0) {
            break;
        }

        if (++i >= 4) {
            return -1;
        }

        switch (gMfsError) {
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                return -1;
        }

        return -1;
    }

    if (bcmp(&leoBootID, &D_i1_80428618, sizeof(LEODiskID)) == 0) {
        return 0;
    }

    gMfsError = N64DD_DISKID_ILLEGAL;
    return -1;
}

s32 Mfs_CreateLeoManager(s32 region, OSMesg* cmdBuf, s32 cmdMsgCount) {
    s32 i = 0;

    D_i1_80428600 = 0;
    Mfs_SetDefaultLeoHandlerFuncs();

    if ((gCompanyCode[0] == '\0') || (gGameCode[0] == '\0')) {
        D_i1_80428644 = 0x107;
        gMfsError = 0x107;
        return -1;
    }

    func_i1_80403D30();
    func_i1_804040EC();
    switch (region) {
        case LEO_MANAGER_REGION_NONE:
#if MFS_VERSION == MFS_VERSION_C
            D_80794CD8 = 0xD;
#endif
            gMfsError = LeoCreateLeoManager(0x95, 0x96, cmdBuf, cmdMsgCount);
            break;
        case LEO_MANAGER_REGION_JP:
#if MFS_VERSION == MFS_VERSION_C
            D_80794CD8 = 0xE;
#endif
            gMfsError = LeoCJCreateLeoManager(0x95, 0x96, cmdBuf, cmdMsgCount);
            break;
        case LEO_MANAGER_REGION_US:
#if MFS_VERSION == MFS_VERSION_C
            D_80794CD8 = 0xE;
#endif
            gMfsError = LeoCACreateLeoManager(0x95, 0x96, cmdBuf, cmdMsgCount);
            break;
        default:
            gMfsError = N64DD_ARGUMENT_ILLEGAL;
            return -1;
            break;
    }

    if (gMfsError != LEO_ERROR_GOOD) {
        return -1;
    }

    if (region == LEO_MANAGER_REGION_NONE) {
#if MFS_VERSION == MFS_VERSION_A
        return func_i1_80403E6C();
#endif
    } else {
        return func_i1_80403E3C();
    }

#if MFS_VERSION == MFS_VERSION_C
    D_i1_80428644 = LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED;
#endif
#if MFS_VERSION >= MFS_VERSION_B
    return 0;
#endif
}

void func_i1_804040EC(void) {
    gMfsRamArea.id.diskId[0] = '\0';
}

s32 Mfs_ReadDiskId(LEODiskID* diskId) {
    LEOCmd sp1C;

#if MFS_VERSION == MFS_VERSION_C
    D_80794CD8 = 8;
    osInvalDCache(diskId, 4);
#endif
    if (gLeoReadDiskIDFunc(&sp1C, diskId, &D_i1_8042A5E8) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_i1_804065C0();
}

#if MFS_VERSION <= MFS_VERSION_B
s32 func_i1_80404174(OSMesgQueue* arg0, OSMesg arg1) {
    D_i1_80428600 = 1;
    D_i1_80428604 = arg0;
    D_i1_80428608 = arg1;
    return 0;
}

s32 func_i1_804041A8(void) {
    D_i1_80428600 = 0;
    return 0;
}
#endif

void func_i1_804041C8(void) {
    LeoGetKAdr(0);
    LeoGetAAdr(0, NULL, NULL, NULL);
}

s32 func_i1_80404204(void) {
    s32 sp1C;

    gMfsError = LeoReadCapacity(&gRamAreaCapacity, OS_WRITE);
    if (gMfsError != LEO_ERROR_GOOD) {
        return -1;
    }
    LeoLBAToByte(gRamAreaCapacity.startLBA, 3, &sp1C);
    gDirectoryEntryCount = (sp1C - (s32) offsetof(MfsRamArea, directoryEntry)) / (s32) sizeof(MfsRamDirectoryEntry);
    return 0;
}

s32 func_i1_8040428C(void) {
    if (Mfs_ReadDiskId(&D_i1_80428618) != 0) {
        return -1;
    }
#if MFS_VERSION == MFS_VERSION_C
    if (D_i1_80428644 == LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED) {
        D_i1_80428644 = LEO_ERROR_GOOD;
    }
    if (D_i1_80428644 == 0x10A) {
        D_i1_80428644 = LEO_ERROR_GOOD;
    }
    if (func_80760A84() < 0) {
        return -1;
    }
#endif
    if (func_i1_80404204() < 0) {
        return -1;
    }
    if (gRamAreaCapacity.nbytes == 0) {
        D_i1_80428644 = N64DD_READ_ONLY_MEDIA;
        gMfsError = N64DD_READ_ONLY_MEDIA;
        return -1;
    }
    gWorkingDirectory = MFS_ENTRY_ROOT_DIR;
    func_i1_804040EC();
    D_i1_80428644 = LEO_ERROR_GOOD;
    return 0;
}

#if MFS_VERSION >= MFS_VERSION_B
s32 Mfs_RamGetDiskType(void) {
    if (gRamAreaCapacity.startLBA == LEO_LBA_RAM_TOP0) {
        return 0;
    }
    if (gRamAreaCapacity.startLBA == LEO_LBA_RAM_TOP1) {
        return 1;
    }
    if (gRamAreaCapacity.startLBA == LEO_LBA_RAM_TOP2) {
        return 2;
    }
    if (gRamAreaCapacity.startLBA == LEO_LBA_RAM_TOP3) {
        return 3;
    }
    if (gRamAreaCapacity.startLBA == LEO_LBA_RAM_TOP4) {
        return 4;
    }
    if (gRamAreaCapacity.startLBA == LEO_LBA_RAM_TOP5) {
        return 5;
    }
    return 6;
}
#endif

s32 func_i1_80404330(void) {
    LEOStatus status;

    gMfsError = LEO_ERROR_GOOD;
#if MFS_VERSION == MFS_VERSION_C
    D_80794CD8 = 15;
#endif
    gMfsError = LeoTestUnitReady(&status);
    if (!(status & LEO_TEST_UNIT_MR)) {
        if (gMfsError == LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED) {}
        return 1;
    }
    if (gMfsError == LEO_SENSE_MEDIUM_NOT_PRESENT) {
        return 0;
    }
    return -1;
}

#if MFS_VERSION == MFS_VERSION_A
s32 Mfs_InitRamArea(s32 arg0) {
#else
s32 Mfs_InitRamArea(s32 arg0, u8 attr, u8* volumeName) {
#endif
    LEODiskTime formatDate;
    s32 i;
    bool sp18;
#if MFS_VERSION >= MFS_VERSION_B
    s32 ramAreaSize;
#endif

    sp18 = false;
    if (arg0 == 1) {
        sp18 = true;
    } else if (arg0 == 2) {
        sp18 = false;
    } else {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }

#if MFS_VERSION >= MFS_VERSION_B
    if (D_i1_80428644 == 0x10A) {
        D_i1_80428644 = LEO_ERROR_GOOD;
    }
#endif
#if MFS_VERSION <= MFS_VERSION_B
    func_i1_804047F0();
#else
    if (func_i1_804047F0() < 0) {
        return -1;
    }
#endif

    if (func_i1_80404330() <= 0) {
        return -1;
    }
    if (!sp18 && func_i1_80404830() < 0) {
        sp18 = true;
    }
#if MFS_VERSION >= MFS_VERSION_B
    for (i = 0; i < (s32) sizeof(MfsRamId); i++) {
        ((u8*) &gMfsRamArea.id)[i] = 0;
    }
#endif
    mfsStrnCpy(gMfsRamArea.id.diskId, D_i1_80428648, 10);
    gMfsRamArea.id.fsType[0] = '0';
    gMfsRamArea.id.fsType[1] = '1';
    gMfsRamArea.id.fsVersion[0] = '0';
    gMfsRamArea.id.fsVersion[1] = '1';
#if MFS_VERSION >= MFS_VERSION_B
    gMfsRamArea.id.attr = attr;
    gMfsRamArea.id.diskType = Mfs_RamGetDiskType();
    if (volumeName != NULL) {
        mfsStrnCpy(&gMfsRamArea.id.volumeName, volumeName, 20);
    }
#endif
    gMfsRamArea.id.renewalCounter = 0;
    Mfs_ReadRtc(&formatDate);
    Mfs_LEODiskTimeToMfsTime(&formatDate, &gMfsRamArea.id.formatDate);
    if (sp18) {
        bzero(gMfsRamArea.fileAllocationTable, sizeof(gMfsRamArea.fileAllocationTable));
    } else {
        for (i = 0; i < ARRAY_COUNT(gMfsRamArea.fileAllocationTable); i++) {
            if (gMfsRamArea.fileAllocationTable[i] != MFS_FAT_OUT_OF_MANAGEMENT) {
                gMfsRamArea.fileAllocationTable[i] = MFS_FAT_UNUSED;
            }
        }
    }
#if MFS_VERSION == MFS_VERSION_A
    bzero(gMfsRamArea.directoryEntry, gDirectoryEntryCount * sizeof(MfsRamDirectoryEntry));
#else
    LeoLBAToByte(gRamAreaCapacity.startLBA, 3, &ramAreaSize);
    bzero(gMfsRamArea.directoryEntry, ramAreaSize - offsetof(MfsRamArea, directoryEntry));
#endif
    Mfs_CreateRootDirectory(false);
    gWorkingDirectory = MFS_ENTRY_ROOT_DIR;
    D_i1_80428644 = LEO_ERROR_GOOD;
#if MFS_VERSION <= MFS_VERSION_B
    return Mfs_BackupRamArea();
#else
    if (Mfs_BackupRamArea() < 0) {
        func_i1_804040EC();
        return -1;
    } else {
        return 0;
    }
#endif
}

s32 Mfs_BackupRamArea(void) {
#if MFS_VERSION == MFS_VERSION_C
    D_80794CDC = 0;
#endif
#if MFS_VERSION >= MFS_VERSION_B
    if (Mfs_ValidateRamVolume() < 0) {
        return -1;
    }
#endif
    gMfsRamArea.id.renewalCounter++;
#if MFS_VERSION >= MFS_VERSION_B
    Mfs_CalculateVolumeChecksum();
#endif
#if MFS_VERSION == MFS_VERSION_C
    D_80794CDC = 2;
#endif
    if (Mfs_WriteLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
#if MFS_VERSION == MFS_VERSION_C
    D_80794CDC = 3;
#endif
#if MFS_VERSION >= MFS_VERSION_B
    if (Mfs_WriteLBA(gRamAreaCapacity.startLBA + 3, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
#endif
    return 0;
}

s32 Mfs_ReadRamArea(void) {
#if MFS_VERSION == MFS_VERSION_B
    // TODO: FAKE
    ((u8*) (&gMfsRamArea.directoryEntry[0x382]))[0] = 0x12;
    ((u8*) (&gMfsRamArea.directoryEntry[0x382]))[1] = 0x34;
    ((u8*) (&gMfsRamArea.directoryEntry[0x382]))[2] = 0x56;
    ((u8*) (&gMfsRamArea.directoryEntry[0x382]))[3] = 0x78;
    ((u8*) (&gMfsRamArea.directoryEntry[0x382]))[4] = 0x9A;
#endif
    if (Mfs_ReadLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
#if MFS_VERSION >= MFS_VERSION_B
    if (Mfs_CheckChecksum() < 0) {
        D_i1_80428644 = 0x10A;
        gMfsError = 0x10A;
        return -1;
    }
#endif
    return 0;
}

s32 Mfs_ValidateRamVolume(void) {
    s32 i;
    s32 j = 0;

    gMfsError = LEO_ERROR_GOOD;

    for (i = 0; i < 10; i++) {
        if (gMfsRamArea.id.diskId[i] != D_i1_80428648[i]) {
            j++;
        }
    }

    if (j != 0) {
        gMfsError = N64DD_MEDIA_NOT_INIT;
        return -1;
    }
    return 0;
}

#if MFS_VERSION == MFS_VERSION_C
s32 func_80760A84(void) {
    if (D_i1_80428618.ramUsage != 1) {
        gMfsError = 0x111;
        return -1;
    }
}
#endif

s32 func_i1_804046F0(void) {
    s32 i = 0;

    gMfsError = LEO_ERROR_GOOD;
#if MFS_VERSION <= MFS_VERSION_B
    func_i1_804047F0();
#else
    if (func_i1_804047F0() < 0) {
        return -1;
    }
#endif

    while (true) {
        if (((i++ < 5) ^ 1)) {
            return -1;
        }
#if MFS_VERSION == MFS_VERSION_A
        Mfs_ReadRamArea();
#else
        if (Mfs_ReadRamArea() == 0) {
            break;
        }
#endif
        if (gMfsError == LEO_ERROR_GOOD) {
            break;
        }

        if (gMfsError == LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED) {
            if (Mfs_ReadDiskId(&D_i1_80428618) < 0) {
                return -1;
            }
        } else {
#if MFS_VERSION == MFS_VERSION_C
            if (gMfsError == LEO_ERROR_UNRECOVERED_READ_ERROR) {
                gMfsError = N64DD_MEDIA_NOT_INIT;
                return 0;
            }
            if (gMfsError == 0x10A) {
                gMfsError = N64DD_MEDIA_NOT_INIT;
                return 0;
            }
#endif
            return -1;
        }
    }

    osWritebackDCache(gMfsRamArea.id.diskId, 10);

    if (Mfs_ValidateRamVolume() == 0) {
        return 1;
    }

    gMfsError = N64DD_MEDIA_NOT_INIT;

    return 0;
}

s32 func_i1_804047F0(void) {
    if (D_i1_80428644 != LEO_ERROR_GOOD) {
        gMfsError = D_i1_80428644;
        return -1;
    }
    return 0;
}

s32 func_i1_80404830(void) {
    s32 err;

    gMfsError = LEO_ERROR_GOOD;
#if MFS_VERSION <= MFS_VERSION_B
    func_i1_804047F0();
#else
    if (func_i1_804047F0() < 0) {
        return -1;
    }
#endif
    err = func_i1_80404330();
    if (err <= 0) {
        return -1;
    }

    if (gMfsError == LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED) {
        func_i1_804040EC();
        D_i1_80428644 = LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED;
        return -1;
    } else {
        osWritebackDCache(&gMfsRamArea, sizeof(MfsRamArea));
        if (Mfs_ValidateRamVolume() == 0) {
            return 0;
        }
#if MFS_VERSION == MFS_VERSION_C
        if (gMfsError == N64DD_MEDIA_NOT_INIT) {
#endif
            if (Mfs_ReadRamArea() < 0) {
                return -1;
            }
            if (Mfs_ValidateRamVolume() == 0) {
                return 0;
            }
#if MFS_VERSION == MFS_VERSION_C
        }
#endif
    }

#if MFS_VERSION <= MFS_VERSION_B
    gMfsError = N64DD_MEDIA_NOT_INIT;
#endif
    return -1;
}

s32 Mfs_RamGetFreeSize(void) {
    s32 sp24;
    s32 sp20;
    s32 i;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    sp20 = 0;

#if MFS_VERSION == MFS_VERSION_A
    for (i = 4; i <= (gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA); i++) {
#else
    for (i = 6; i <= (gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA); i++) {
#endif
        if (gMfsRamArea.fileAllocationTable[i] != MFS_FAT_UNUSED) {
            continue;
        }
        LeoLBAToByte(i + gRamAreaCapacity.startLBA, 1, &sp24);
        sp20 += sp24;
    }

    return sp20;
}

s32 Mfs_WorkGetFreeSize(void) {
    s32 sp24;
    s32 sp20;
    s32 i;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    sp20 = 0;

#if MFS_VERSION == MFS_VERSION_A
    for (i = 4; i <= (gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA); i++) {
#else
    for (i = 6; i <= (gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA); i++) {
#endif
        if (gFileAllocationTable[i] != MFS_FAT_UNUSED) {
            continue;
        }
        LeoLBAToByte(i + gRamAreaCapacity.startLBA, 1, &sp24);
        sp20 += sp24;
    }

    return sp20;
}

void Mfs_SetGameCode(char* companyCode, char* gameCode) {
    if (companyCode != 0) {
        mfsStrnCpy(gCompanyCode, companyCode, 2);
    }
    if (gameCode != 0) {
        mfsStrnCpy(gGameCode, gameCode, 4);
    }
}

void Mfs_IncreaseVolumeRC(void) {
    gMfsRamArea.id.renewalCounter++;
}

void Mfs_ResetVolumeRC(void) {
    gMfsRamArea.id.renewalCounter = 0;
}

#if MFS_VERSION <= MFS_VERSION_B
s32 func_i1_80404B90(u16 arg0, u16 arg1, u16 writeChanges) {
    s32 i;

    if (func_i1_80404830() < 0) {
        return -1;
    }

#if MFS_VERSION == MFS_VERSION_A
    if ((arg0 < 4) || (gRamAreaCapacity.endLBA < (arg0 + gRamAreaCapacity.startLBA + arg1) - 1)) {
#else
    if ((arg0 < 6) || (gRamAreaCapacity.endLBA < (arg0 + gRamAreaCapacity.startLBA + arg1) - 1)) {
#endif
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }

    Mfs_CopyFATFromRam();

    for (i = 0; i < arg1; i++) {
        if (gFileAllocationTable[gRamAreaCapacity.startLBA + arg0 + i] != MFS_FAT_UNUSED) {
            gMfsError = 0x108;
            return -1;
        }
        gFileAllocationTable[gRamAreaCapacity.startLBA + arg0 + i] = MFS_FAT_OUT_OF_MANAGEMENT;
    }

    Mfs_CopyFATToRam();
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
}

s32 func_i1_80404CF0(u16 arg0, u16 arg1, u16 writeChanges) {
    s32 i;

    if (func_i1_80404830() < 0) {
        return -1;
    }

#if MFS_VERSION == MFS_VERSION_A
    if ((arg0 < 4) || (gRamAreaCapacity.endLBA < (arg0 + gRamAreaCapacity.startLBA + arg1) - 1)) {
#else
    if ((arg0 < 6) || (gRamAreaCapacity.endLBA < (arg0 + gRamAreaCapacity.startLBA + arg1) - 1)) {
#endif
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }

    Mfs_CopyFATFromRam();

    for (i = 0; i < arg1; i++) {
        if (gFileAllocationTable[gRamAreaCapacity.startLBA + arg0 + i] != MFS_FAT_OUT_OF_MANAGEMENT) {
            gMfsError = 0x109;
            return -1;
        }
        gFileAllocationTable[gRamAreaCapacity.startLBA + arg0 + i] = MFS_FAT_UNUSED;
    }

    Mfs_CopyFATToRam();
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
}
#endif

#if MFS_VERSION >= MFS_VERSION_B
s32 Mfs_CalculateVolumeChecksum(void) {
    s32 size;
    s32* ptr;
    u32 i;
    s32 checksum;

    ptr = (s32*) &gMfsRamArea;
    checksum = 0;
    gMfsRamArea.id.checksum = 0;
    LeoLBAToByte(gRamAreaCapacity.startLBA, 3, &size);

    for (i = 0; i < (size / (s32) sizeof(s32)); i++) {
        checksum ^= *ptr++;
    }
    gMfsRamArea.id.checksum = checksum;
    return 0;
}

s32 Mfs_CheckChecksum(void) {
    s32 size;
    s32* ptr;
    u32 i;
    s32 checksum;

    ptr = (s32*) &gMfsRamArea;
    checksum = 0;

    LeoLBAToByte(gRamAreaCapacity.startLBA, 3, &size);

    for (i = 0; i < (size / (s32) sizeof(s32)); i++) {
        if (*ptr != 0) {}
        checksum ^= *ptr++;
    }
    checksum ^= gMfsRamArea.id.checksum;
    checksum ^= gMfsRamArea.id.checksum;

    return (checksum != 0) ? -1 : 0;
}

s32 Mfs_RefreshRamArea(void) {
    UNUSED s32 pad;
    if (Mfs_ReadLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
    Mfs_CalculateVolumeChecksum();
    if (Mfs_WriteLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
    return 0;
}

s32 Mfs_CopyRamAreaFromBackup(void) {
#if MFS_VERSION == MFS_VERSION_C
    UNUSED s32 pad;
#endif

    D_80794CDC = 1;
#if MFS_VERSION == MFS_VERSION_B
    if (Mfs_ReadLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
#else
    if (Mfs_ReadLBA(gRamAreaCapacity.startLBA + 3, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
#endif
    if (Mfs_ValidateRamVolume() < 0) {
        return -1;
    }
    gMfsRamArea.id.renewalCounter++;
    Mfs_CalculateVolumeChecksum();
    D_80794CDC = 2;
    if (Mfs_WriteLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
#if MFS_VERSION == MFS_VERSION_B
    D_80794CDC = 3;
    if (Mfs_WriteLBA(gRamAreaCapacity.startLBA + 3, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
#endif
    if (D_i1_80428644 == 0x10A) {
        D_i1_80428644 = LEO_ERROR_GOOD;
    }
    return 0;
}
#endif

#if MFS_VERSION == MFS_VERSION_C
s32 Mfs_SpdlMotorBrake(void) {
    LEOCmd cmdBlock;

    if (gLeoSpdlMotorFunc(&cmdBlock, LEO_MOTOR_BRAKE, &D_i1_8042A5E8) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_i1_804065C0();
}
#endif
