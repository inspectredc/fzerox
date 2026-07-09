#include "leo/mfs.h"

s32 Mfs_ChangeFileAttr(u16 entryId, u16 attributeToAdd, u16 attributeToRemove) {
    u16 attr;

    if (!(gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_FILE) ||
        (gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_DIRECTORY)) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if ((attributeToAdd & MFS_FILE_ATTR_DIRECTORY) || (attributeToRemove & MFS_FILE_ATTR_FILE)) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    attr = gMfsRamArea.directoryEntry[entryId].attr;
    attr |= attributeToAdd;
    attr &= attributeToRemove ^ 0xFFFF;
    gMfsRamArea.directoryEntry[entryId].attr = attr;
    return 0;
}

s32 Mfs_CheckAndChangeFileAttr(u16 entryId, s32 attributeToAdd, s32 attributeToRemove, bool writeChanges) {
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (Mfs_ChangeFileAttr(entryId, attributeToAdd, attributeToRemove) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_ChangeFileInDirAttr(u16 dirId, char* name, char* extension, s32 attributeToAdd, s32 attributeToRemove,
                            bool writeChanges) {
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
    entryId = Mfs_GetFileIndex(dirId, name, extension);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_ChangeFileAttr(entryId, attributeToAdd, attributeToRemove) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

#if MFS_VERSION <= MFS_VERSION_B
s32 Mfs_GetEntryAttr(u16 entryId) {

    gMfsError = LEO_ERROR_GOOD;
    if (func_i1_80404830() < 0) {
        return -1;
    }

    if (!(gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_FILE) ||
        (gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_DIRECTORY)) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    return gMfsRamArea.directoryEntry[entryId].attr;
}
#endif

s32 Mfs_GetFileInDirAttr(u16 dirId, char* name, char* extension) {
    u16 entryId;

    gMfsError = LEO_ERROR_GOOD;
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
    entryId = Mfs_GetFileIndex(dirId, name, extension);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    return gMfsRamArea.directoryEntry[entryId].attr;
}

#if MFS_VERSION >= MFS_VERSION_B
s32 Mfs_ValidateFileSystemOperation(s32 validationFlags, u16 entryIndex, u16 subEntryIndex, u16 dirId) {
    u16 dirEntryIndex;
    s32 entryValidGameCodeErr;

    dirEntryIndex = MFS_ENTRY_DOES_NOT_EXIST;
#if MFS_VERSION == MFS_VERSION_B
    entryValidGameCodeErr = 1;
#endif
    if (validationFlags & MFS_VALIDATION_CHECK_WRITE) {
        if (gMfsRamArea.id.attr & MFS_VOLUME_ATTR_WPROTECT) {
            return -1;
        }
        if ((gMfsRamArea.id.attr & MFS_VOLUME_ATTR_VPROTECT_WRITE) &&
            ((mfsStrnCmp(D_i1_80428618.company, gCompanyCode, 2) != 0) ||
             (mfsStrnCmp(D_i1_80428618.gameName, gGameCode, 4) != 0))) {
            return -1;
        }
        if ((validationFlags & MFS_VALIDATION_CHECK_MAIN_ENTRY) &&
            (gMfsRamArea.directoryEntry[entryIndex].attr & MFS_FILE_ATTR_FORBID_W)) {
            return -1;
        }
        if ((validationFlags & MFS_VALIDATION_CHECK_SUB_ENTRY) &&
            (gMfsRamArea.directoryEntry[subEntryIndex].attr & MFS_FILE_ATTR_FORBID_W)) {
            return -1;
        }
        if ((validationFlags & MFS_VALIDATION_CHECK_PARENT) &&
            (gMfsRamArea.directoryEntry[gMfsRamArea.directoryEntry[entryIndex].parentDirId].attr &
             MFS_FILE_ATTR_FORBID_W)) {
            return -1;
        }
        if (validationFlags & MFS_VALIDATION_CHECK_DIRECTORY) {
#if MFS_VERSION == MFS_VERSION_B
            entryIndex = Mfs_GetDirectoryIndex(dirId);
            if (gMfsRamArea.directoryEntry[entryIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                return -1;
            }
#else
            dirEntryIndex = Mfs_GetDirectoryIndex(dirId);
            if (gMfsRamArea.directoryEntry[dirEntryIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                return -1;
            }
#endif
        }
        if (validationFlags & MFS_VALIDATION_CHECK_ENTRY_AS_DIRECTORY) {
#if MFS_VERSION == MFS_VERSION_B
            if (entryIndex == MFS_ENTRY_DOES_NOT_EXIST) {
                entryIndex = Mfs_GetDirectoryIndex(dirId);
            }
            if (gMfsRamArea.directoryEntry[entryIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                return -1;
            }
#else
            if ((dirEntryIndex = entryIndex) == MFS_ENTRY_DOES_NOT_EXIST) {
                dirEntryIndex = Mfs_GetDirectoryIndex(dirId);
            }
            if (gMfsRamArea.directoryEntry[dirEntryIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                return -1;
            }
#endif
        }
    }

    dirEntryIndex = MFS_ENTRY_DOES_NOT_EXIST;
    if (validationFlags & MFS_VALIDATION_CHECK_READ) {
#if MFS_VERSION == MFS_VERSION_C
        entryValidGameCodeErr = Mfs_ValidateGameCode(entryIndex);
#endif
        if ((gMfsRamArea.id.attr & MFS_VOLUME_ATTR_VPROTECT_READ) &&
            ((mfsStrnCmp(D_i1_80428618.company, gCompanyCode, 2) != 0) ||
             (mfsStrnCmp(&D_i1_80428618, gGameCode, 4) != 0))) {
            return -1;
        }

        if ((validationFlags & MFS_VALIDATION_CHECK_MAIN_ENTRY) &&
            (gMfsRamArea.directoryEntry[entryIndex].attr & MFS_FILE_ATTR_FORBID_R)) {
#if MFS_VERSION == MFS_VERSION_B
            if (Mfs_ValidateGameCode(entryIndex) < 0) {
#else
            if (entryValidGameCodeErr < 0) {
#endif
                return -1;
#if MFS_VERSION == MFS_VERSION_B
            } else {
                entryValidGameCodeErr = 0;
#endif
            }
        }
        if ((validationFlags & MFS_VALIDATION_CHECK_SUB_ENTRY) &&
            (gMfsRamArea.directoryEntry[subEntryIndex].attr & MFS_FILE_ATTR_FORBID_R)) {
#if MFS_VERSION == MFS_VERSION_B
            if (entryValidGameCodeErr != 0 && Mfs_ValidateGameCode(entryIndex) < 0) {
#else
            if (entryValidGameCodeErr < 0) {
#endif
                return -1;
#if MFS_VERSION == MFS_VERSION_B
            } else {
                entryValidGameCodeErr = 0;
#endif
            }
        }
        if ((validationFlags & MFS_VALIDATION_CHECK_PARENT) &&
            (gMfsRamArea.directoryEntry[gMfsRamArea.directoryEntry[entryIndex].parentDirId].attr &
             MFS_FILE_ATTR_FORBID_R)) {
#if MFS_VERSION == MFS_VERSION_B
            if (entryValidGameCodeErr != 0 && Mfs_ValidateGameCode(entryIndex) < 0) {
#else
            if (Mfs_ValidateGameCode(gMfsRamArea.directoryEntry[entryIndex].parentDirId) < 0) {
#endif
                return -1;
#if MFS_VERSION == MFS_VERSION_B
            } else {
                entryValidGameCodeErr = 0;
#endif
            }
        }
        if (validationFlags & MFS_VALIDATION_CHECK_DIRECTORY) {
#if MFS_VERSION == MFS_VERSION_B
            entryIndex = Mfs_GetDirectoryIndex(dirId);
            if ((gMfsRamArea.directoryEntry[entryIndex].attr & MFS_FILE_ATTR_FORBID_R)) {
                if (entryValidGameCodeErr != 0 && Mfs_ValidateGameCode(entryIndex) < 0) {
                    return -1;
                } else {
                    entryValidGameCodeErr = 0;
                }
            }
#else
            dirEntryIndex = Mfs_GetDirectoryIndex(dirId);
            if ((gMfsRamArea.directoryEntry[dirEntryIndex].attr & MFS_FILE_ATTR_FORBID_R)) {
                if (Mfs_ValidateGameCode(dirEntryIndex) < 0) {
                    return -1;
                }
            }
#endif
        }
        if (validationFlags & MFS_VALIDATION_CHECK_ENTRY_AS_DIRECTORY) {
#if MFS_VERSION == MFS_VERSION_B
            if (entryIndex == MFS_ENTRY_DOES_NOT_EXIST) {
                entryIndex = Mfs_GetDirectoryIndex(dirId);
            }
            if ((gMfsRamArea.directoryEntry[entryIndex].attr & MFS_FILE_ATTR_FORBID_W)) {
                if (entryValidGameCodeErr != 0 && Mfs_ValidateGameCode(entryIndex) < 0) {
                    return -1;
                } else {
                    entryValidGameCodeErr = 0;
                }
            }
#else
            //! @bug dirEntryIndex should be set instead of entryIndex, otherwise an OOB read in the directory entries
            //! can occur
            //       To fix, copy the section from the writing validation (potentially using FORBID_R instead also!)
            if (dirEntryIndex == MFS_ENTRY_DOES_NOT_EXIST) {
                entryIndex = Mfs_GetDirectoryIndex(dirId);
            }
            if ((gMfsRamArea.directoryEntry[dirEntryIndex].attr & MFS_FILE_ATTR_FORBID_W)) {
                if (Mfs_ValidateGameCode(dirEntryIndex) < 0) {
                    return -1;
                }
            }
#endif
        }
    }
    return 0;
}
#endif
