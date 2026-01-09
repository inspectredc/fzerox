#ifndef MFS_H
#define MFS_H

#include "libultra/ultra64.h"
#include "PR/leo.h"
#include "libc/stdbool.h"

#define MFS_VERSION_A 0
#define MFS_VERSION_B 1

typedef struct MfsTimeFormat {
    union {
        struct {
            u8 unkb0, unkb1, unkb2, unkb3;
        };
        struct {
            u16 unks0, unks2;
        };
        u32 unki0;
    };
} MfsTimeFormat;

typedef struct MfsRamId {
    /* 0x00 */ char diskId[10]; // "64dd-Multi"
    /* 0x0A */ s8 fsType[2];
    /* 0x0C */ s8 fsVersion[2];
    /* 0x0E */ u8 attr;
    /* 0x0F */ u8 diskType;
    /* 0x10 */ char volumeName[20];
    /* 0x24 */ MfsTimeFormat formatDate;
    /* 0x28 */ u16 renewalCounter;
    /* 0x2A */ u8 destinationCode;
    /* 0x2B */ s8 reserve1;
    /* 0x2C */ u32 checksum;
    /* 0x30 */ s8 reserve2[0xC];
} MfsRamId; // size = 0x3C

typedef struct MfsRamDirectoryEntry {
    /* 0x00 */ u16 attr;
    /* 0x02 */ u16 parentDirId;
    /* 0x04 */ s8 companyCode[2];
    /* 0x06 */ s8 gameCode[4];
    union {
        /* 0x0A */ u16 dirId; // directories only
        /* 0x0A */ u16 fileAllocationTableId; // files only
    };
    union {
        /* 0x0C */ s8 reserve1[0x4]; // directories only
        /* 0x0C */ s32 fileSize; // files only
    };
    /* 0x10 */ char name[20];
    union {
        /* 0x24 */ s8 reserve2[0x6]; // directories only
        struct {
            /* 0x24 */ char extension[5];
            /* 0x29 */ u8 copyCount;
        }; // files only
    };
    /* 0x2A */ u8 renewalCounter;
    /* 0x2B */ s8 reserve3;
    /* 0x2C */ MfsTimeFormat creationDate;
} MfsRamDirectoryEntry; // size = 0x30

typedef struct MfsRamArea {
    /* 0x0000 */ MfsRamId id;
    /* 0x003C */ u16 fileAllocationTable[0xB3A];
    /* 0x16B0 */ MfsRamDirectoryEntry directoryEntry[1112];
} MfsRamArea; // size = 0xE730

#define LEO_MANAGER_REGION_NONE 0
#define LEO_MANAGER_REGION_JP 0x101
#define LEO_MANAGER_REGION_US 0x102

#define N64DD_MEDIA_NOT_INIT 0xF0
#define N64DD_AREA_LACKED 0xF1
#define N64DD_NOT_FOUND 0xF2
#define N64DD_DISK_DAMAGED 0xF3
#define N64DD_ARGUMENT_ILLEGAL 0xF4
#define N64DD_DISKID_ILLEGAL 0xF5
#define N64DD_READ_ONLY_MEDIA 0xF6
#define N64DD_MANAGER_NOT_CREATED 0xF7

#define MFS_VOLUME_ATTR_VPROTECT_WRITE (1 << 5) // Prohibits writes unless game and company code matches
#define MFS_VOLUME_ATTR_VPROTECT_READ (1 << 6) // Prohibits reads unless game and company code matches
#define MFS_VOLUME_ATTR_WPROTECT (1 << 7) // Prohibits all writes

#define MFS_FILE_ATTR_COPYLIMIT (1 << 9)
#define MFS_FILE_ATTR_ENCODE (1 << 10)
#define MFS_FILE_ATTR_HIDDEN (1 << 11)
#define MFS_FILE_ATTR_FORBID_R (1 << 12)
#define MFS_FILE_ATTR_FORBID_W (1 << 13)
#define MFS_FILE_ATTR_FILE (1 << 14)
#define MFS_FILE_ATTR_DIRECTORY (1 << 15)

#define MFS_VALIDATION_CHECK_SUB_ENTRY (1 << 1)
#define MFS_VALIDATION_CHECK_ENTRY_AS_DIRECTORY (1 << 2) // Effectively unused, unsure of purpose
#define MFS_VALIDATION_CHECK_DIRECTORY (1 << 3)
#define MFS_VALIDATION_CHECK_PARENT (1 << 4)
#define MFS_VALIDATION_CHECK_MAIN_ENTRY (1 << 5)
#define MFS_VALIDATION_CHECK_READ (1 << 6)
#define MFS_VALIDATION_CHECK_WRITE (1 << 7)

#define MFS_ENTRY_ROOT_DIR 0
#define MFS_ENTRY_WORKING_DIR 0xFFFB
#define MFS_ENTRY_WORKING_PARENT_DIR 0xFFFC
#define MFS_ENTRY_GLOBAL_DIR 0xFFFD
#define MFS_ENTRY_ROOT_PARENT_DIR 0xFFFE
#define MFS_ENTRY_DOES_NOT_EXIST 0xFFFF

#define MFS_FAT_UNUSED 0
#define MFS_FAT_OUT_OF_MANAGEMENT 0xFFFD
#define MFS_FAT_PROHIBITED 0xFFFE
#define MFS_FAT_LAST_BLOCK 0xFFFF

extern u8 D_i1_80415190[0x4D10];

#if MFS_VERSION == MFS_VERSION_B
extern u8 D_807801E0[0x4D10];
#endif

extern MfsRamArea gMfsRamArea;
extern MfsRamDirectoryEntry gCurrentDirectoryEntry;
extern u16 gFileAllocationTable[LEO_LBA_MAX - LEO_LBA_ROM_END0];
extern s32 D_i1_80428600;
extern OSMesgQueue* D_i1_80428604;
extern OSMesg D_i1_80428608;
extern s32 gDirectoryEntryCount;
extern s32 gMfsError;

#if MFS_VERSION == MFS_VERSION_B
extern s32 D_80794CD8;
extern s32 D_80794CDC;
#endif

extern u16 gWorkingDirectory;
extern LEODiskID D_i1_80428618;
extern OSMesg D_i1_8042A5E4[1];
extern OSMesgQueue D_i1_8042A5E8;
extern LEOCapacity gRamAreaCapacity;
extern s32 D_i1_80428644;
extern char D_i1_80428648[];
extern char gCompanyCode[2];
extern char gGameCode[4];

#if MFS_VERSION == MFS_VERSION_B
extern u8 D_80794D48;
#endif

extern s32 (*gLeoReadWriteFunc)(LEOCmd*, s32, u32, void*, u32, OSMesgQueue*);
extern s32 (*gLeoSeekFunc)(LEOCmd*, u32, OSMesgQueue*);
extern s32 (*gLeoSpdlMotorFunc)(LEOCmd*, u8, OSMesgQueue*);
extern s32 (*gLeoReadDiskIDFunc)(LEOCmd*, LEODiskID*, OSMesgQueue*);
extern s32 (*gLeoReadRTCFunc)(LEOCmd*, OSMesgQueue*);
extern s32 (*gLeoSetRTCFunc)(LEOCmd*, LEODiskTime*, OSMesgQueue*);
extern s32 (*gLeoModeSelectAsyncFunc)(LEOCmd*, u32, u32, OSMesgQueue*);
extern s32 (*gLeoRezeroFunc)(LEOCmd*, OSMesgQueue*);

void Mfs_SetGameCode(char* companyCode, char* gameCode);
u16 Mfs_GetNextFileInPreparedDir(void);
s32 Mfs_GetFilesPreparation(u16 dirId);
s32 Mfs_ChangeFileInDirAttr(u16 dirId, char* name, char* extension, s32 attributeToAdd, s32 attributeToRemove, bool writeChanges);
s32 Mfs_GetFileInDirAttr(u16 dirId, char* name, char* extension);
void Mfs_SetDirEntryAttr(u16 attr);
void Mfs_SetDirEntryName(char* name);
void Mfs_SetDirEntryCreateTime(void);
void Mfs_SetDirEntryDirId(u16 dirId);
void Mfs_SetDirEntryExtension(char* extension);
void Mfs_SetDirEntryFileSize(s32 fileSize);
void Mfs_CreateDirEntry(u16 parentDirId, char* name);
void Mfs_SetDirEntryCopyCount(s32 copyCount);
void Mfs_SetDirEntryRenewalCounter(u16 renewalCounter);
void Mfs_InitDirEntry(void);
s32 Mfs_CopyDirEntryToRam(u16 entryId);
s32 Mfs_CopyDirEntryFromRam(u16 entryId);
void Mfs_IncreaseFileRC(u16 entryId);
s32 Mfs_ValidateGameCode(u16 entryId);
u16 Mfs_GetFileIndex(u16 dirId, char* name, char* extension);
u16 Mfs_GetDirectoryIndexFromParent(u16 parentDirId, char* name);
u16 Mfs_GetDirectoryIndex(u16 dirId);
u16 Mfs_GetNextFreeDirectoryEntry(void);
s32 Mfs_FindBlocksForSize(u32 sizeRequired, s32* lbaPtr, s32* nLBAsPtr, s32* blockSizePtr);
s32 Mfs_CreateLeoManager(s32 region, OSMesg* cmdBuf, s32 cmdMsgCount);
s32 Mfs_ReadDiskId(LEODiskID* diskId);
s32 Mfs_BackupRamArea(void);
s32 Mfs_ValidateRamVolume(void);
s32 Mfs_RamGetFreeSize(void);
s32 Mfs_WorkGetFreeSize(void);
s32 Mfs_CreateRootDirectory(bool writeChanges);
u16 Mfs_GetParentDir(u16 dirId);
s32 Mfs_ReadRtc(LEODiskTime* diskTime);
void Mfs_LEODiskTimeToMfsTime(LEODiskTime* diskTime, MfsTimeFormat* mfsTime);
s32 Mfs_SpdlMotor(LEOSpdlMode mode);
s32 Mfs_ReadLBA(u32 startLBA, u8* buf, u32 nLBAs);
s32 Mfs_WriteLBA(u32 startLBA, u8* buf, u32 nLBAs);
s32 mfsStrnCmp(u8* b1, u8* b2, size_t length);
s32 mfsStrnCpy(u8* dest, u8* src, size_t length);
s32 mfsStrCpy(u8* dest, u8* src);
s32 mfsStrCmp(u8* s1, u8* s2);
s32 Mfs_DecodeTime(s32);
s32 Mfs_EncodeTime(s32);
s32 mfsStrLen(u8* str);
s32 Mfs_ValidateFileName(char* name);
s32 Mfs_SaveFile(u16 parentDirId, char* name, char* extension, u8* buf, u32 fileSize, s32 attr, s32 copyCount, bool writeChanges);
s32 Mfs_CopyFATFromRam(void);
s32 Mfs_CopyFATToRam(void);
s32 Mfs_AddFileAllocationTableEntry(s32* fatIdPtr, s32 lba, s32 nLBAs);
s32 Mfs_ClearFileAllocationTableEntry(s32 fatId);
s32 Mfs_GetFileExtraBlockSpace(s32* fatIdPtr, u32 fileSize, s32* extraSpace);
s32 Mfs_GetFileExtraBlockSpace2(s32* fatIdPtr, u32 fileSize, s32* extraSpace);
s32 Mfs_GetFileLbaCount(s32 fatId);
s32 Mfs_DeleteFileInDir(u16 dirId, char* name, char* extension, bool writeChanges);
s32 Mfs_LoadFileInDir(u16 dirId, char* name, char* extension, u8* buf, s32 sizeToLoad);
s32 Mfs_LoadFileInDirFromOffset(u16 dirId, char* name, char* extension, u8* buf, s32 offset, s32 sizeToLoad);
s32 Mfs_WriteFile(s32 startLBA, u8* buf, u32 nLBAs, bool isEncoded);
s32 Mfs_ReadFile(s32 startLBA, u8* buf, u32 nLBAs, bool isEncoded);
s32 Mfs_RenameFileInDir(u16 dirId, char* oldName, char* oldExtension, char* newName, char* newExtension, bool writeChanges);
void Mfs_SetDefaultLeoHandlerFuncs(void);
s32 Mfs_ModeSelectAsync(s32 standby, s32 sleep);
#if MFS_VERSION == MFS_VERSION_A
s32 Mfs_InitRamArea(s32 arg0);
#else // MFS_VERSION_B
s32 Mfs_InitRamArea(s32 arg0, u8 attr, u8* volumeName);
#endif
void func_i1_804040EC(void);
s32 func_i1_8040428C(void);
s32 func_i1_804046F0(void);
s32 func_i1_80404830(void);
s32 func_i1_804065C0(void);
s32 func_i1_804047F0(void);
#if MFS_VERSION == MFS_VERSION_B
s32 func_80760A84(void);
s32 Mfs_CalculateVolumeChecksum(void);
s32 Mfs_CheckChecksum(void);
s32 Mfs_ValidateFileSystemOperation(s32 validationFlags, u16 entryIndex, u16 subEntryIndex, u16 dirId);
#endif

#endif // MFS_H
