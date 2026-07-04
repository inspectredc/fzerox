/******************************
 *  MFS Version A and B Only  *
 ******************************/

#include "leo/mfs.h"

s32 Mfs_UpdateEntryCreationDate(u16 entryId, MfsTimeFormat* creationDate) {
    bcopy(creationDate, &gMfsRamArea.directoryEntry[entryId].creationDate, sizeof(MfsTimeFormat));
    //! @bug bad return (return value is used)
}

s32 Mfs_UpdateFileCreationDate(u16 dirId, char* name, char* extension, MfsTimeFormat* creationDate, bool writeChanges) {
    u16 entryId;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    entryId = Mfs_GetFileIndex(dirId, name, extension);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
#if MFS_VERSION == MFS_VERSION_A
    if (gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_FORBID_W) {
#else
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
#endif
        gMfsError = 0x106;
        return -1;
    }
    if (Mfs_UpdateEntryCreationDate(entryId, creationDate) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_CheckAndUpdateEntryCreationDate(u16 entryId, MfsTimeFormat* creationDate, bool writeChanges) {
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (entryId < 0 || entryId > gDirectoryEntryCount) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (!(gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_FILE)) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_DIRECTORY) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_UpdateEntryCreationDate(entryId, creationDate) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}
