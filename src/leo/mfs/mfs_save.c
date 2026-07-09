#include "leo/mfs.h"

s32 Mfs_WriteNewFile(u8* buf, u32 fileSize, bool isEncoded) {
    u32 sizeRemaining = fileSize;
    s32 blockSize;
    s32 lba;
    s32 nLBAs;
    s32 fatId = -1;
    u8* bufPtr = buf;

    Mfs_CopyFATFromRam();

    while (sizeRemaining != 0) {
        if (Mfs_FindBlocksForSize(sizeRemaining, &lba, &nLBAs, &blockSize) < 0) {
            gMfsError = N64DD_AREA_LACKED;
            return -1;
        }
        if (Mfs_WriteFile(lba + gRamAreaCapacity.startLBA, bufPtr, nLBAs, isEncoded) < 0) {
            return -1;
        }
        Mfs_AddFileAllocationTableEntry(&fatId, lba, nLBAs);
        if (blockSize >= sizeRemaining) {
            sizeRemaining = 0;
        } else {
            sizeRemaining -= blockSize;
        }
        bufPtr += blockSize;
    }
    return 0;
}

u8 D_i1_804286E0 = 0;

s32 Mfs_WriteNewFileInDir(u16 parentDirId, char* name, char* extension, u8* buf, s32 fileSize, s32 attr,
                          s32 copyCount) {
    u16 entryId;

    Mfs_InitDirEntry();
    if ((copyCount < 0) || (copyCount >= 0x100)) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (attr & MFS_FILE_ATTR_DIRECTORY) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    attr |= MFS_FILE_ATTR_FILE;
    if ((copyCount > 0) && (copyCount < 0xFE)) {
        attr |= MFS_FILE_ATTR_COPYLIMIT;
    }
    entryId = Mfs_GetNextFreeDirectoryEntry();
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_AREA_LACKED;
        return -1;
    }

    if (Mfs_WriteNewFile(buf, fileSize, (attr & MFS_FILE_ATTR_ENCODE) ? true : false) < 0) {
        return -1;
    }
    Mfs_CreateDirEntry(parentDirId, name);
    Mfs_SetDirEntryAttr(attr);
    Mfs_SetDirEntryFileSize(fileSize);
    Mfs_SetDirEntryExtension(extension);
    Mfs_SetDirEntryCopyCount(copyCount);
    Mfs_SetDirEntryRenewalCounter(D_i1_804286E0);
    Mfs_CopyDirEntryToRam(entryId);
    Mfs_IncreaseFileRC(entryId);
    Mfs_CopyFATToRam();
#if MFS_VERSION <= MFS_VERSION_B
    //! @bug bad return
#else
    return 0;
#endif
}

#if MFS_VERSION <= MFS_VERSION_B
s32 func_i1_804073F4(u16 parentDirId, char* name, char* extension, u8* buf, u32 fileSize, s32 attr, s32 copyCount,
                     bool writeChanges) {
    u16 fileEntryId;
#if MFS_VERSION == MFS_VERSION_B
    u16 parentDirEntryId;
#endif

    gMfsError = LEO_ERROR_GOOD;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (fileSize == 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (parentDirId == MFS_ENTRY_WORKING_DIR) {
        parentDirId = gWorkingDirectory;
    }
    if (parentDirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        parentDirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
#if MFS_VERSION == MFS_VERSION_B
    parentDirEntryId = Mfs_GetDirectoryIndex(parentDirId);
    if (parentDirEntryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
#endif
    D_i1_804286E0 = 0;
    fileEntryId = Mfs_GetFileIndex(parentDirId, name, extension);
    if (fileEntryId != MFS_ENTRY_DOES_NOT_EXIST) {
        D_i1_804286E0 = gMfsRamArea.directoryEntry[fileEntryId].renewalCounter;
#if MFS_VERSION == MFS_VERSION_A
        if (gMfsRamArea.directoryEntry[fileEntryId].attr & MFS_FILE_ATTR_FORBID_W) {
#else
        if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                                MFS_VALIDATION_CHECK_PARENT,
                                            fileEntryId, 0, 0) < 0) {
#endif
            gMfsError = 0x106;
            return -1;
        }
        Mfs_DeleteFileInDir(parentDirId, name, extension, 0);
        if (Mfs_RamGetFreeSize() < fileSize) {
            func_i1_804040EC();
            gMfsError = N64DD_AREA_LACKED;
            return -1;
        }
#if MFS_VERSION == MFS_VERSION_B
    } else {
        if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY,
                                            parentDirEntryId, 0, 0) < 0) {
            gMfsError = 0x106;
            return -1;
        }
#endif
    }

    if (Mfs_RamGetFreeSize() < fileSize) {
        gMfsError = N64DD_AREA_LACKED;
        return -1;
    }
    if (Mfs_WriteNewFileInDir(parentDirId, name, extension, buf, fileSize, attr, copyCount) < 0) {
        return -1;
    }

    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}
#endif

s32 Mfs_SaveFile(u16 parentDirId, char* name, char* extension, u8* buf, u32 fileSize, s32 attr, s32 copyCount,
                 bool writeChanges) {
    u16 fileEntryId;
#if MFS_VERSION >= MFS_VERSION_B
    u16 parentDirEntryId;
#endif

    gMfsError = LEO_ERROR_GOOD;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (fileSize == 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (parentDirId == MFS_ENTRY_WORKING_DIR) {
        parentDirId = gWorkingDirectory;
    }
    if (parentDirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        parentDirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
#if MFS_VERSION >= MFS_VERSION_B
    parentDirEntryId = Mfs_GetDirectoryIndex(parentDirId);
    if (parentDirEntryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
#endif
    D_i1_804286E0 = 0;
    fileEntryId = Mfs_GetFileIndex(parentDirId, name, extension);
    if (fileEntryId != MFS_ENTRY_DOES_NOT_EXIST) {
        D_i1_804286E0 = gMfsRamArea.directoryEntry[fileEntryId].renewalCounter;
#if MFS_VERSION == MFS_VERSION_A
        if (gMfsRamArea.directoryEntry[fileEntryId].attr & MFS_FILE_ATTR_FORBID_W) {
#else
        if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                                MFS_VALIDATION_CHECK_PARENT,
                                            fileEntryId, 0, 0) < 0) {
#endif
            gMfsError = 0x106;
            return -1;
        }
        if (Mfs_RamGetFreeSize() < fileSize) {
            gMfsError = N64DD_AREA_LACKED;
            return -1;
        }
        if (Mfs_WriteNewFileInDir(parentDirId, "__TMP__", "_!TMP", buf, fileSize, attr, copyCount) < 0) {
            return -1;
        }
        Mfs_DeleteFileInDir(parentDirId, name, extension, 0);
        Mfs_RenameFileInDir(parentDirId, "__TMP__", "_!TMP", name, extension, 0);
    } else {
#if MFS_VERSION >= MFS_VERSION_B
        if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY,
                                            parentDirEntryId, 0, 0) < 0) {
            gMfsError = 0x106;
            return -1;
        }
#endif
        if (Mfs_RamGetFreeSize() < fileSize) {
            gMfsError = N64DD_AREA_LACKED;
            return -1;
        }
        if (Mfs_WriteNewFileInDir(parentDirId, name, extension, buf, fileSize, attr, copyCount) < 0) {
            return -1;
        }
    }

    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_AppendToFile(u16 entryId, u8* buf, u32 sizeToAppend, bool isEncoded) {
    s32 fileSize;
    u32 sizeRemaining;
    u32 extraSpace;
    u32 blocksSize;
#if MFS_VERSION == MFS_VERSION_C
    u32 sizeWritten;
#endif
    s32 fatId;
    s32 lba;
    s32 nLBAs;
    u8* bufPtr;

    sizeRemaining = sizeToAppend;
    bufPtr = buf;
    fileSize = gMfsRamArea.directoryEntry[entryId].fileSize;
    fatId = gMfsRamArea.directoryEntry[entryId].fileAllocationTableId;
    Mfs_CopyFATFromRam();
    Mfs_GetFileExtraBlockSpace(&fatId, fileSize, &extraSpace);
    if (extraSpace != 0) {
        LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, 1, &blocksSize);
        if (Mfs_ReadFile(fatId + gRamAreaCapacity.startLBA, D_i1_80415190, 1, isEncoded) < 0) {
            return -1;
        }

        bcopy(bufPtr, (blocksSize - extraSpace) + D_i1_80415190,
              (extraSpace > sizeRemaining) ? sizeRemaining : extraSpace);
        if (Mfs_WriteFile(fatId + gRamAreaCapacity.startLBA, D_i1_80415190, 1, isEncoded) < 0) {
            return -1;
        }
    }

#if MFS_VERSION <= MFS_VERSION_B
    sizeRemaining -= (extraSpace > sizeRemaining) ? sizeRemaining : extraSpace;
    bufPtr += (extraSpace > sizeRemaining) ? sizeRemaining : extraSpace;
#else
    sizeWritten = (extraSpace > sizeRemaining) ? sizeRemaining : extraSpace;
    sizeRemaining -= sizeWritten;
    bufPtr += sizeWritten;
#endif
    while (sizeRemaining != 0) {
        if (Mfs_FindBlocksForSize(sizeRemaining, &lba, &nLBAs, &blocksSize) < 0) {
            gMfsError = N64DD_AREA_LACKED;
            return -1;
        }
        if (Mfs_WriteFile(lba + gRamAreaCapacity.startLBA, bufPtr, nLBAs, isEncoded) < 0) {
            return -1;
        }
        Mfs_AddFileAllocationTableEntry(&fatId, lba, nLBAs);
        if (blocksSize >= sizeRemaining) {
            sizeRemaining = 0;
        } else {
            sizeRemaining -= blocksSize;
        }
        bufPtr += blocksSize;
    }

    Mfs_SetDirEntryFileSize(fileSize + sizeToAppend);
    Mfs_SetDirEntryCreateTime();
    Mfs_CopyDirEntryToRam(entryId);
    Mfs_IncreaseFileRC(entryId);
    Mfs_CopyFATToRam();
    return 0;
}

s32 Mfs_CheckNewSizeAndAppendToFile(u16 entryId, u8* buf, s32 sizeToAppend) {
    u32 newSize;
    s32 attr;

    if (sizeToAppend == 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    newSize = gMfsRamArea.directoryEntry[entryId].fileSize + sizeToAppend;

    Mfs_CopyFATFromRam();
    Mfs_ClearFileAllocationTableEntry(gMfsRamArea.directoryEntry[entryId].fileAllocationTableId);
    if (Mfs_WorkGetFreeSize() < newSize) {
        func_i1_804040EC();
        gMfsError = N64DD_AREA_LACKED;
        return -1;
    }
    attr = gMfsRamArea.directoryEntry[entryId].attr;

    if (Mfs_AppendToFile(entryId, buf, sizeToAppend, (attr & MFS_FILE_ATTR_ENCODE) ? true : false) < 0) {
        return -1;
    }
    return 0;
}

s32 Mfs_AppendToFileInDir(u16 dirId, char* name, char* extension, u8* buf, s32 sizeToAppend, bool writeChanges) {
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
#if MFS_VERSION >= MFS_VERSION_B
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
#endif
    if (Mfs_CheckNewSizeAndAppendToFile(entryId, buf, sizeToAppend) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_CheckAndAppendToFile(u16 entryId, u8* buf, s32 sizeToAppend, bool writeChanges) {
    gMfsError = LEO_ERROR_GOOD;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if ((entryId < 0) || (entryId > gDirectoryEntryCount)) {
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
#if MFS_VERSION >= MFS_VERSION_B
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
#endif
    if (Mfs_CheckNewSizeAndAppendToFile(entryId, buf, sizeToAppend) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_UpdateFileFromOffset(u16 entryId, u8* buf, s32 offset, u32 sizeToWrite, bool isEncoded) {
    s32 fileSize;
    u32 sizeRemaining;
    u32 extraSpace;
    s32 blocksSize;
#if MFS_VERSION == MFS_VERSION_C
    u32 sizeWritten;
#endif
    s32 fatId;
    s32 pad[2];
    s32 nLBAs;
    s32 lbasToUpdate;
    u8* bufPtr;

    sizeRemaining = sizeToWrite;
    bufPtr = buf;
    fileSize = gMfsRamArea.directoryEntry[entryId].fileSize;
    fatId = gMfsRamArea.directoryEntry[entryId].fileAllocationTableId;
    Mfs_CopyFATFromRam();
    Mfs_GetFileExtraBlockSpace2(&fatId, offset, &extraSpace);
    if (extraSpace != 0) {
        LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, 1, &blocksSize);
        if (Mfs_ReadFile(fatId + gRamAreaCapacity.startLBA, D_i1_80415190, 1, isEncoded) < 0) {
            return -1;
        }

        bcopy(bufPtr, (blocksSize - extraSpace) + D_i1_80415190,
              (extraSpace > sizeRemaining) ? sizeRemaining : extraSpace);
        if (Mfs_WriteFile(fatId + gRamAreaCapacity.startLBA, D_i1_80415190, 1, isEncoded) < 0) {
            return -1;
        }

#if MFS_VERSION <= MFS_VERSION_B
        sizeRemaining -= (extraSpace > sizeRemaining) ? sizeRemaining : extraSpace;
        bufPtr += (extraSpace > sizeRemaining) ? sizeRemaining : extraSpace;
#else
        sizeWritten = (extraSpace > sizeRemaining) ? sizeRemaining : extraSpace;
        sizeRemaining -= sizeWritten;
        bufPtr += sizeWritten;
#endif
        if (sizeRemaining != 0) {
            fatId = gFileAllocationTable[fatId];
            if (fatId == MFS_FAT_LAST_BLOCK) {
                gMfsError = N64DD_DISK_DAMAGED;
                return -1;
            }
        }
    }

    while (sizeRemaining != 0) {
        nLBAs = Mfs_GetFileLbaCount(fatId);

        for (lbasToUpdate = 1; lbasToUpdate <= nLBAs; lbasToUpdate++) {
            LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, lbasToUpdate, &blocksSize);
            if (blocksSize >= sizeRemaining) {
                break;
            }
        }
        if (blocksSize == sizeRemaining) {
            if (Mfs_WriteFile(fatId + gRamAreaCapacity.startLBA, bufPtr, lbasToUpdate, isEncoded) < 0) {
                return -1;
            }
            sizeRemaining = 0;
        } else {
            if (--lbasToUpdate > 0) {
                LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, lbasToUpdate, &blocksSize);
                if (Mfs_WriteFile(fatId + gRamAreaCapacity.startLBA, bufPtr, lbasToUpdate, isEncoded) < 0) {
                    return -1;
                }
                fatId += lbasToUpdate;
                sizeRemaining -= blocksSize;
                bufPtr += blocksSize;
            } else {
                break;
            }
        }

        if (lbasToUpdate < nLBAs) {
            break;
        }
        fatId = (fatId + nLBAs) - 1;
        if ((fatId = gFileAllocationTable[fatId]) == MFS_FAT_LAST_BLOCK) {
            gMfsError = N64DD_DISK_DAMAGED;
            return -1;
        }
    }

    if (sizeRemaining != 0) {
        if (Mfs_ReadFile(fatId + gRamAreaCapacity.startLBA, D_i1_80415190, 1, isEncoded) < 0) {
            return -1;
        }
        bcopy(bufPtr, D_i1_80415190, sizeRemaining);
        if (Mfs_WriteFile(fatId + gRamAreaCapacity.startLBA, D_i1_80415190, 1, isEncoded) < 0) {
            return -1;
        }
    }

    Mfs_SetDirEntryCreateTime();
    Mfs_CopyDirEntryToRam(entryId);
    return 0;
}

s32 Mfs_CheckSizeAndUpdateFileFromOffset(u16 entryId, u8* buf, u32 offset, s32 sizeToWrite) {
    s32 attr;

    if (sizeToWrite == 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (gMfsRamArea.directoryEntry[entryId].fileSize < offset + sizeToWrite) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    attr = gMfsRamArea.directoryEntry[entryId].attr;

    if (Mfs_UpdateFileFromOffset(entryId, buf, offset, sizeToWrite, (attr & MFS_FILE_ATTR_ENCODE) ? true : false) < 0) {
        return -1;
    }
    return 0;
}

s32 Mfs_UpdateFileInDirFromOffset(u16 dirId, char* name, char* extension, u8* buf, s32 offset, s32 sizeToWrite,
                                  bool writeChanges) {
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
#if MFS_VERSION >= MFS_VERSION_B
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
#endif
    if (Mfs_CheckSizeAndUpdateFileFromOffset(entryId, buf, offset, sizeToWrite) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_CheckAndUpdateFileFromOffset(u16 entryId, u8* buf, s32 offset, s32 sizeToWrite, bool writeChanges) {
    gMfsError = LEO_ERROR_GOOD;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if ((entryId < 0) || (entryId > gDirectoryEntryCount)) {
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
#if MFS_VERSION >= MFS_VERSION_B
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
#endif
    if (Mfs_CheckSizeAndUpdateFileFromOffset(entryId, buf, offset, sizeToWrite) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_CheckSizeAndUpdateAndExtendFile(u16 entryId, u8* buf, u32 offset, s32 sizeToWrite) {
    s32 attr;
    s32 sizeToUpdate;
    s32 sizeToAppend;

    sizeToUpdate = 0;
    sizeToAppend = 0;
    if (sizeToWrite == 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (gMfsRamArea.directoryEntry[entryId].fileSize < offset + sizeToWrite) {
        sizeToUpdate = gMfsRamArea.directoryEntry[entryId].fileSize - offset;
        sizeToAppend = (offset + sizeToWrite) - gMfsRamArea.directoryEntry[entryId].fileSize;
    } else {
        sizeToUpdate = sizeToWrite;
    }
    attr = gMfsRamArea.directoryEntry[entryId].attr;

    if (Mfs_UpdateFileFromOffset(entryId, buf, offset, sizeToUpdate, (attr & MFS_FILE_ATTR_ENCODE) ? true : false) <
        0) {
        return -1;
    }
    if (sizeToAppend != 0) {
        if (Mfs_AppendToFile(entryId, buf + sizeToUpdate, sizeToAppend, (attr & MFS_FILE_ATTR_ENCODE) ? true : false) <
            0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_UpdateAndExtendFileInDir(u16 dirId, char* name, char* extension, u8* buf, s32 offset, s32 sizeToWrite,
                                 bool writeChanges) {
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
#if MFS_VERSION >= MFS_VERSION_B
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
#endif
    if (Mfs_CheckSizeAndUpdateAndExtendFile(entryId, buf, offset, sizeToWrite) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_CheckAndUpdateAndExtendFile(u16 entryId, u8* buf, s32 offset, s32 sizeToWrite, bool writeChanges) {
    gMfsError = LEO_ERROR_GOOD;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if ((entryId < 0) || (entryId > gDirectoryEntryCount)) {
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
#if MFS_VERSION >= MFS_VERSION_B
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
#endif
    if (Mfs_CheckSizeAndUpdateAndExtendFile(entryId, buf, offset, sizeToWrite) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}
