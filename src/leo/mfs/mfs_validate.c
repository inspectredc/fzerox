/*****************************
 *    MFS Version B Only     *
 *****************************/

#include "leo/mfs.h"

s32 Mfs_ValidateFileSystemOperation(s32 validationFlags, u16 entryIndex, u16 subEntryIndex, u16 dirId) {
    u16 dirEntryIndex;
    s32 entryValidGameCodeErr;

    dirEntryIndex = MFS_ENTRY_DOES_NOT_EXIST;
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
            dirEntryIndex = Mfs_GetDirectoryIndex(dirId);
            if (gMfsRamArea.directoryEntry[dirEntryIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                return -1;
            }
        }
        if (validationFlags & MFS_VALIDATION_CHECK_ENTRY_AS_DIRECTORY) {
            if ((dirEntryIndex = entryIndex) == MFS_ENTRY_DOES_NOT_EXIST) {
                dirEntryIndex = Mfs_GetDirectoryIndex(dirId);
            }
            if (gMfsRamArea.directoryEntry[dirEntryIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                return -1;
            }
        }
    }

    dirEntryIndex = MFS_ENTRY_DOES_NOT_EXIST;
    if (validationFlags & MFS_VALIDATION_CHECK_READ) {
        entryValidGameCodeErr = Mfs_ValidateGameCode(entryIndex);
        if ((gMfsRamArea.id.attr & MFS_VOLUME_ATTR_VPROTECT_READ) &&
            ((mfsStrnCmp(D_i1_80428618.company, gCompanyCode, 2) != 0) ||
             (mfsStrnCmp(&D_i1_80428618, gGameCode, 4) != 0))) {
            return -1;
        }
        if ((validationFlags & MFS_VALIDATION_CHECK_MAIN_ENTRY) &&
            (gMfsRamArea.directoryEntry[entryIndex].attr & MFS_FILE_ATTR_FORBID_R) && (entryValidGameCodeErr < 0)) {
            return -1;
        }
        if ((validationFlags & MFS_VALIDATION_CHECK_SUB_ENTRY) &&
            (gMfsRamArea.directoryEntry[subEntryIndex].attr & MFS_FILE_ATTR_FORBID_R) && (entryValidGameCodeErr < 0)) {
            return -1;
        }
        if ((validationFlags & MFS_VALIDATION_CHECK_PARENT) &&
            (gMfsRamArea.directoryEntry[gMfsRamArea.directoryEntry[entryIndex].parentDirId].attr &
             MFS_FILE_ATTR_FORBID_R)) {
            if (Mfs_ValidateGameCode(gMfsRamArea.directoryEntry[entryIndex].parentDirId) < 0) {
                return -1;
            }
        }
        if (validationFlags & MFS_VALIDATION_CHECK_DIRECTORY) {
            dirEntryIndex = Mfs_GetDirectoryIndex(dirId);
            if ((gMfsRamArea.directoryEntry[dirEntryIndex].attr & MFS_FILE_ATTR_FORBID_R)) {
                if (Mfs_ValidateGameCode(dirEntryIndex) < 0) {
                    return -1;
                }
            }
        }
        if (validationFlags & MFS_VALIDATION_CHECK_ENTRY_AS_DIRECTORY) {
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
        }
    }
    return 0;
}
