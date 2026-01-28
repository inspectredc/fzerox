#include "leo/mfs.h"
#include "macros.h"

#if MFS_VERSION == MFS_VERSION_A
s32 func_i1_8040A9E0(u16 entryId, MfsRamDirectoryEntry** directoryEntry) {
    gMfsError = LEO_ERROR_GOOD;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (!(gMfsRamArea.directoryEntry[entryId].attr & (MFS_FILE_ATTR_FILE | MFS_FILE_ATTR_DIRECTORY))) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    *directoryEntry = &gMfsRamArea.directoryEntry[entryId];
    return 0;
}

s32 func_i1_8040AA94(u16 dirId, char* name, char* extension, MfsRamDirectoryEntry** directoryEntry) {
    u16 entryId;

    entryId = Mfs_GetFileIndex(dirId, name, extension);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    return func_i1_8040A9E0(entryId, directoryEntry);
}

s32 func_i1_8040AB10(u16 dirId, char* name, MfsRamDirectoryEntry** directoryEntry) {
    u16 entryId;

    entryId = Mfs_GetDirectoryIndexFromParent(dirId, name);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    return func_i1_8040A9E0(entryId, directoryEntry);
}
#endif

u16 gPreparedDirectoryId;
u16 gPreparedEntryIndexCounter;

s32 Mfs_GetFilesPreparation(u16 dirId) {
#if MFS_VERSION == MFS_VERSION_B
    UNUSED s32 pad;
#endif
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
        if ((dirId == MFS_ENTRY_ROOT_PARENT_DIR) || (dirId == MFS_ENTRY_DOES_NOT_EXIST)) {
            gMfsError = 0x104;
            return -1;
        }
    }
#if MFS_VERSION == MFS_VERSION_B
    if ((dirId == MFS_ENTRY_DOES_NOT_EXIST) || (Mfs_GetDirectoryIndex(dirId) == MFS_ENTRY_DOES_NOT_EXIST)) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_READ | MFS_VALIDATION_CHECK_DIRECTORY, 0, 0, dirId) < 0) {
        gMfsError = 0x106;
        return -1;
    }
#endif

    gPreparedEntryIndexCounter = 0;
    gPreparedDirectoryId = dirId;
#if MFS_VERSION == MFS_VERSION_A
    //! @bug bad return
#else // MFS_VERSION_B
    return 0;
#endif
}

u16 Mfs_GetNextFileInPreparedDir(void) {
    while (gPreparedEntryIndexCounter < gDirectoryEntryCount) {
        if ((gMfsRamArea.directoryEntry[gPreparedEntryIndexCounter].parentDirId == gPreparedDirectoryId) &&
            (gMfsRamArea.directoryEntry[gPreparedEntryIndexCounter].attr & MFS_FILE_ATTR_FILE)) {
            return gPreparedEntryIndexCounter++;
        }
        gPreparedEntryIndexCounter++;
    }

    return MFS_ENTRY_DOES_NOT_EXIST;
}

#if MFS_VERSION == MFS_VERSION_A
s32 func_i1_8040AD08(u16 dirId) {
    s32 i;
    s32 fileCount;

    fileCount = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if ((dirId != MFS_ENTRY_GLOBAL_DIR) && (Mfs_GetDirectoryIndex(dirId) == MFS_ENTRY_DOES_NOT_EXIST)) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }

    switch (dirId) {
        case MFS_ENTRY_GLOBAL_DIR:
            for (i = 0; i < gDirectoryEntryCount; i++) {
                if (gMfsRamArea.directoryEntry[i].attr & MFS_FILE_ATTR_FILE) {
                    fileCount++;
                }
            }
            break;
        default:
            for (i = 0; i < gDirectoryEntryCount; i++) {
                if ((gMfsRamArea.directoryEntry[i].attr & MFS_FILE_ATTR_FILE) &&
                    (gMfsRamArea.directoryEntry[i].parentDirId == dirId)) {
                    fileCount++;
                }
            }
            break;
    }

    return fileCount;
}

s32 func_i1_8040AECC(u16 dirId) {
    s32 i;
    s32 directoryCount;

    directoryCount = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if ((dirId != MFS_ENTRY_GLOBAL_DIR) && (Mfs_GetDirectoryIndex(dirId) == MFS_ENTRY_DOES_NOT_EXIST)) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    switch (dirId) {
        case MFS_ENTRY_GLOBAL_DIR:
            for (i = 0; i < gDirectoryEntryCount; i++) {
                if (gMfsRamArea.directoryEntry[i].attr & MFS_FILE_ATTR_DIRECTORY) {
                    directoryCount++;
                }
            }
            break;
        default:
            for (i = 0; i < gDirectoryEntryCount; i++) {
                if ((gMfsRamArea.directoryEntry[i].attr & MFS_FILE_ATTR_DIRECTORY) &&
                    (gMfsRamArea.directoryEntry[i].parentDirId == dirId)) {
                    directoryCount++;
                }
            }
            break;
    }
    return directoryCount;
}
#endif
