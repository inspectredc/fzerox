#include "macros.h"
#include "leo/mfs.h"

#if MFS_VERSION == MFS_VERSION_A
s32 func_i1_80404E50(u16 parentDirId, char* name, bool writeChanges) {
    u16 sp1E;
    u16 sp1C;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (parentDirId == MFS_ENTRY_WORKING_DIR) {
        parentDirId = gWorkingDirectory;
    }
    if ((parentDirId == MFS_ENTRY_WORKING_PARENT_DIR) &&
        ((parentDirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR), (parentDirId == MFS_ENTRY_ROOT_PARENT_DIR)) ||
         (parentDirId == MFS_ENTRY_DOES_NOT_EXIST))) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (Mfs_GetDirectoryIndex(parentDirId) == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_GetDirectoryIndexFromParent(parentDirId, name) != MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = 0x100;
        return -1;
    }
    sp1C = Mfs_GetNextFreeDirectoryEntry();
    if (sp1C == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_AREA_LACKED;
        return -1;
    }
    sp1E = sp1C;
    if (Mfs_GetDirectoryIndex(sp1E) != MFS_ENTRY_DOES_NOT_EXIST) {
        sp1E = 0x1000;
        while (true) {
            if (Mfs_GetDirectoryIndex(sp1E) == MFS_ENTRY_DOES_NOT_EXIST) {
                break;
            }

            sp1E = (sp1E < gDirectoryEntryCount) ? gDirectoryEntryCount : sp1E + 1;
        }
    }
    Mfs_InitDirEntry();
    Mfs_CreateDirEntry(parentDirId, name);
    Mfs_SetDirEntryAttr(MFS_FILE_ATTR_DIRECTORY);
    Mfs_SetDirEntryDirId(sp1E);
    Mfs_SetDirEntryRenewalCounter(0);
    Mfs_CopyDirEntryToRam(sp1C);
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}
#endif

s32 Mfs_CreateRootDirectory(bool writeChanges) {
    u16 dirId;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (Mfs_GetDirectoryIndexFromParent(MFS_ENTRY_ROOT_PARENT_DIR, "/") != MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = 0x100;
        return -1;
    }
    dirId = Mfs_GetNextFreeDirectoryEntry();
    if (dirId != MFS_ENTRY_ROOT_DIR) {
        gMfsError = 0x103;
        return -1;
    }
    Mfs_InitDirEntry();
    Mfs_CreateDirEntry(MFS_ENTRY_ROOT_PARENT_DIR, "/");
    Mfs_SetDirEntryAttr(MFS_FILE_ATTR_DIRECTORY);
    Mfs_SetDirEntryDirId(MFS_ENTRY_ROOT_DIR);
    Mfs_SetDirEntryRenewalCounter(0);
    Mfs_CopyDirEntryToRam(dirId);
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

#if MFS_VERSION == MFS_VERSION_A
s32 func_i1_80405174(u16 dirId, char* name) {
    u16 dirEntryIndex;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if ((dirId == MFS_ENTRY_WORKING_PARENT_DIR) &&
        ((dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR), (dirId == MFS_ENTRY_ROOT_PARENT_DIR)) ||
         (dirId == MFS_ENTRY_DOES_NOT_EXIST))) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    dirEntryIndex = Mfs_GetDirectoryIndexFromParent(dirId, name);
    if (dirEntryIndex == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    gWorkingDirectory = dirEntryIndex;
    return 0;
}
#endif

s32 Mfs_SetWorkingDirImpl(u16 dirId) {
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        return 0;
    }
    if ((dirId == MFS_ENTRY_WORKING_PARENT_DIR) &&
        ((dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR), (dirId == MFS_ENTRY_ROOT_PARENT_DIR)) ||
         (dirId == MFS_ENTRY_DOES_NOT_EXIST))) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (Mfs_GetDirectoryIndex(dirId) == MFS_ENTRY_DOES_NOT_EXIST) {
        return N64DD_NOT_FOUND;
    }
    gWorkingDirectory = dirId;
    return 0;
}

s32 Mfs_SetWorkingDir(u16 dirId) {
    return Mfs_SetWorkingDirImpl(dirId);
}

#if MFS_VERSION == MFS_VERSION_A
s32 func_i1_80405368(void) {
    return Mfs_SetWorkingDirImpl(MFS_ENTRY_WORKING_PARENT_DIR);
}

u16 D_i1_8042A600;
u16 D_i1_8042A602;

s32 func_i1_80405398(u16 dirId) {

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
        if (dirId == MFS_ENTRY_ROOT_PARENT_DIR) {
            gMfsError = N64DD_ARGUMENT_ILLEGAL;
            return -1;
        }
    }
    if ((dirId == MFS_ENTRY_DOES_NOT_EXIST) || Mfs_GetDirectoryIndex(dirId) == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    D_i1_8042A602 = 0;
    D_i1_8042A600 = dirId;
}

u16 func_i1_8040547C(void) {

    while (D_i1_8042A602 < gDirectoryEntryCount) {
        if ((gMfsRamArea.directoryEntry[D_i1_8042A602].parentDirId == D_i1_8042A600) &&
            (gMfsRamArea.directoryEntry[D_i1_8042A602].attr & MFS_FILE_ATTR_DIRECTORY)) {
            return gMfsRamArea.directoryEntry[D_i1_8042A602++].dirId;
        }
        D_i1_8042A602++;
    }

    return -1;
}

u16 func_i1_8040555C(u16 dirId, char* name) {
    u16 entryId;

    if (func_i1_80404830() < 0) {
        return 0xFFF0;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if ((dirId == MFS_ENTRY_WORKING_PARENT_DIR) &&
        ((dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR), (dirId == MFS_ENTRY_ROOT_PARENT_DIR)) ||
         (dirId == MFS_ENTRY_DOES_NOT_EXIST))) {
        gMfsError = N64DD_NOT_FOUND;
        return MFS_ENTRY_DOES_NOT_EXIST;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return MFS_ENTRY_DOES_NOT_EXIST;
    }
    entryId = Mfs_GetDirectoryIndexFromParent(dirId, name);
    if (entryId != MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return MFS_ENTRY_DOES_NOT_EXIST;
    }
    return gMfsRamArea.directoryEntry[entryId].dirId;
}
#endif

u16 Mfs_GetParentDir(u16 dirId) {
    u16 entryId;

    if (func_i1_80404830() < 0) {
        return 0xFFF0;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_ROOT_DIR) {
        return MFS_ENTRY_ROOT_PARENT_DIR;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    entryId = Mfs_GetDirectoryIndex(dirId);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return MFS_ENTRY_DOES_NOT_EXIST;
    }
    return gMfsRamArea.directoryEntry[dirId].parentDirId;
}

#if MFS_VERSION == MFS_VERSION_A
u16 func_i1_80405754(void) {
    if (func_i1_80404830() < 0) {
        return 0xFFF0;
    }
    return gWorkingDirectory;
}
#endif

s32 Mfs_MkDir(u16 dirId, u16 subDirId) {
    u16 parentDirId;
    u16 dirEntryIndex;
    u16 subDirEntryIndex;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (subDirId == MFS_ENTRY_WORKING_DIR) {
        subDirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if (subDirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        subDirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if (dirId == MFS_ENTRY_ROOT_DIR) {
        gMfsError = 0x104;
        return -1;
    }
    if (dirId == MFS_ENTRY_ROOT_PARENT_DIR) {
        gMfsError = 0x104;
        return -1;
    }
    if (dirId == subDirId) {
        gMfsError = 0x104;
        return -1;
    }
    dirEntryIndex = Mfs_GetDirectoryIndex(dirId);
    if (dirEntryIndex == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    subDirEntryIndex = Mfs_GetDirectoryIndex(subDirId);
    if (subDirEntryIndex == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
#if MFS_VERSION == MFS_VERSION_B
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT | MFS_VALIDATION_CHECK_SUB_ENTRY,
                                        dirEntryIndex, subDirEntryIndex, dirId) < 0) {
        gMfsError = 0x106;
        return -1;
    }
#endif
    parentDirId = gMfsRamArea.directoryEntry[dirEntryIndex].parentDirId;
    if (parentDirId == subDirId) {
        return 0;
    }
    if (Mfs_GetDirectoryIndexFromParent(subDirId, gMfsRamArea.directoryEntry[dirEntryIndex].name) !=
        MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = 0x100;
        return -1;
    }
    gMfsRamArea.directoryEntry[dirEntryIndex].parentDirId = subDirId;
    return 0;
}

#if MFS_VERSION == MFS_VERSION_A
s32 func_i1_804059B8(u16 dirId, char* name, bool writeChanges) {
    u16 parentId;
    u16 entryId;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if (dirId == MFS_ENTRY_ROOT_DIR) {
        gMfsError = 0x104;
        return -1;
    }
    if (dirId == MFS_ENTRY_ROOT_PARENT_DIR) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    entryId = Mfs_GetDirectoryIndex(dirId);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    parentId = gMfsRamArea.directoryEntry[entryId].parentDirId;
    if (Mfs_GetDirectoryIndexFromParent(parentId, name) != MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = 0x100;
        return -1;
    }
    bzero(gMfsRamArea.directoryEntry[entryId].name, 20);
    mfsStrnCpy(gMfsRamArea.directoryEntry[entryId].name, name, 20);
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 func_i1_80405B98(u16 arg0, char* arg1, char* arg2, bool writeChanges) {
    u16 sp1E = Mfs_GetDirectoryIndexFromParent(arg0, arg1);

    if (sp1E == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    func_i1_804059B8(sp1E, arg2, writeChanges);
}
#endif

s32 Mfs_DeleteDirEntry(u16 entryId, bool writeChanges) {
    u16 i;
    u16 dirId;
    s32 entriesInDir;

#if MFS_VERSION == MFS_VERSION_A
    if (gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_FORBID_W) {
#else // MFS_VERSION_B
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
#endif
        gMfsError = 0x106;
        return -1;
    }
    dirId = gMfsRamArea.directoryEntry[entryId].dirId;

    for (i = 0, entriesInDir = 0; i < gDirectoryEntryCount; i++) {
        if (gMfsRamArea.directoryEntry[i].attr == 0) {
            continue;
        }
        if (gMfsRamArea.directoryEntry[i].parentDirId == dirId) {
            entriesInDir++;
        }
    }
    if (entriesInDir != 0) {
        gMfsError = 0x103;
        return -1;
    }
    bzero(&gMfsRamArea.directoryEntry[entryId], sizeof(MfsRamDirectoryEntry));
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_DeleteDir(u16 dirId, char* name, bool writeChanges) {
    u16 entryId;
    UNUSED s32 pad[2];
    s32 sp18;

    sp18 = 0;
#if MFS_VERSION == MFS_VERSION_B
    D_80794CDC = 4;
#endif
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if (dirId == MFS_ENTRY_ROOT_DIR) {
        gMfsError = 0x106;
        return -1;
    }
    if (dirId == MFS_ENTRY_ROOT_PARENT_DIR) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    entryId = Mfs_GetDirectoryIndex(dirId);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_DeleteDirEntry(entryId, writeChanges) < 0) {
        return -1;
    }
    return 0;
}

#if MFS_VERSION == MFS_VERSION_A
s32 func_i1_80405EFC(u16 dirId, bool writeChanges) {
    u16 entryId;

    entryId = Mfs_GetDirectoryIndex(dirId);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_DeleteDirEntry(entryId, writeChanges) < 0) {
        return -1;
    }
    return 0;
}
#endif
