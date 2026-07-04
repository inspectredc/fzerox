/******************************
 *  MFS Version B and C Only  *
 ******************************/

#include "leo/mfs.h"

// TODO: Sort out mfs_data files
#if MFS_VERSION == MFS_VERSION_B
u8 D_807801E0[0x4D10] = { 0 };
#endif

void Mfs_GetFATBlockSizeInfo(s32* totalBlocksSizePtr, s32* unusedBlocksSizePtr) {
    s32 i;
    s32 fatId;
    s32 validBlocksSize;
    s32 unusedBlocksSize;
    s32 blockSize;

    validBlocksSize = 0;
    unusedBlocksSize = 0;

    for (i = 6; i < gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA; i++) {
#if MFS_VERSION == MFS_VERSION_B
        LeoLBAToByte(i, 1, &blockSize);
#else // MFS_VERSION_C
        LeoLBAToByte(i + gRamAreaCapacity.startLBA, 1, &blockSize);
#endif
        fatId = gMfsRamArea.fileAllocationTable[i];
        if (fatId == MFS_FAT_UNUSED) {
            unusedBlocksSize += blockSize;
        }
        if ((fatId == MFS_FAT_LAST_BLOCK) || (fatId < 0x7FFF)) {
            validBlocksSize += blockSize;
        }
    }
    if (unusedBlocksSizePtr != NULL) {
        *unusedBlocksSizePtr = unusedBlocksSize;
    }
    if (totalBlocksSizePtr != NULL) {
        *totalBlocksSizePtr = validBlocksSize;
    }
}

s32 Mfs_MakeFileCopy(s32* offsetCopiedPtr, s32* offsetBlockSizePtr, s32* fatIdPtr, s32 totalSizeToCopy) {
    s32 offsetCopied;
    s32 offsetBlockSize;
    s32 fatId;
    s32 sizeRead;
    s32 sizeToCopy;
    s32 sizeRemaining;

    offsetCopied = *offsetCopiedPtr;
    offsetBlockSize = *offsetBlockSizePtr;
    fatId = *fatIdPtr;
    sizeRead = 0;
    sizeRemaining = totalSizeToCopy;
    while (sizeRemaining > 0) {
        if (offsetBlockSize == offsetCopied) {
            Mfs_ReadLBA(fatId + gRamAreaCapacity.startLBA, D_i1_80415190, 1);
            offsetCopied = 0;
            LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, 1, &offsetBlockSize);
#if MFS_VERSION == MFS_VERSION_B
            fatId = gMfsRamArea.fileAllocationTable[fatId];
#else
            fatId = gFileAllocationTable[fatId];
#endif
        }
        sizeToCopy = offsetBlockSize - offsetCopied;
        if (sizeToCopy < sizeRemaining) {
            bcopy(D_i1_80415190 + offsetCopied, D_807801E0 + sizeRead, sizeToCopy);
            offsetCopied += sizeToCopy;
            sizeRead += sizeToCopy;
        } else {
            bcopy(D_i1_80415190 + offsetCopied, D_807801E0 + sizeRead, sizeRemaining);
            offsetCopied += sizeRemaining;
            sizeRead += sizeRemaining;
        }
        sizeRemaining = totalSizeToCopy - sizeRead;
    }
    *offsetCopiedPtr = offsetCopied;
    *offsetBlockSizePtr = offsetBlockSize;
    *fatIdPtr = fatId;
    return 0;
}

s32 Mfs_CopyFileToDir(s32 entryId, char* name, u16 parentDirId) {
    u16 nextFreeEntryId;
    s32 fileSize;
    s32 unusedBlocksSize;
    s32 originalFatId;
    s32 newFatId;
    s32 sizeToCopy;
    s32 offsetCopied;
    s32 offsetBlockSize;
    s32 firstLba;
    s32 nLBAs;
    s32 bestBlockSize;
    s32 lbaOffset;
    s32 rollingFatId;

    newFatId = -1;
    offsetCopied = 0;
    offsetBlockSize = 0;
    bcopy(&gMfsRamArea.directoryEntry[entryId], &gCurrentDirectoryEntry, sizeof(MfsRamDirectoryEntry));
    if (gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_COPYLIMIT) {
        if (gMfsRamArea.directoryEntry[entryId].copyCount == 0) {
            gMfsError = 0x110;
            return -1;
        }
    }
    fileSize = gMfsRamArea.directoryEntry[entryId].fileSize;
    nextFreeEntryId = Mfs_GetNextFreeDirectoryEntry();
    if (nextFreeEntryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_AREA_LACKED;
        return -1;
    }
    Mfs_GetFATBlockSizeInfo(NULL, &unusedBlocksSize);
    if (unusedBlocksSize < fileSize) {
        gMfsError = N64DD_AREA_LACKED;
        return -1;
    }
    originalFatId = gMfsRamArea.directoryEntry[entryId].fileAllocationTableId;
    Mfs_CopyFATFromRam();
    while (fileSize > 0) {
        Mfs_FindBlocksForSize(fileSize, &firstLba, &nLBAs, &bestBlockSize);
#if MFS_VERSION == MFS_VERSION_C
        if (firstLba == -1) {
            gMfsError = N64DD_AREA_LACKED;
            return -1;
        }
#endif
        lbaOffset = 0;
        while ((lbaOffset < nLBAs) && (fileSize > 0)) {
            LeoLBAToByte(firstLba + gRamAreaCapacity.startLBA + lbaOffset, 1, &sizeToCopy);
            if (fileSize < sizeToCopy) {
                sizeToCopy = fileSize;
            }
            Mfs_MakeFileCopy(&offsetCopied, &offsetBlockSize, &originalFatId, sizeToCopy);
            Mfs_WriteLBA(firstLba + gRamAreaCapacity.startLBA + lbaOffset, D_807801E0, 1);
            rollingFatId = firstLba + lbaOffset;
            if (newFatId < 0) {
                gCurrentDirectoryEntry.fileAllocationTableId = rollingFatId;
            } else {
#if MFS_VERSION == MFS_VERSION_B
                gMfsRamArea.fileAllocationTable[newFatId] = rollingFatId;
#else
                gFileAllocationTable[newFatId] = rollingFatId;
#endif
            }
            newFatId = rollingFatId;
#if MFS_VERSION == MFS_VERSION_C
            lbaOffset++;
#endif
            fileSize -= sizeToCopy;
        }
#if MFS_VERSION == MFS_VERSION_C
        gFileAllocationTable[newFatId] = MFS_FAT_LAST_BLOCK;
#endif
    }

    if (newFatId < 0) {
        gCurrentDirectoryEntry.fileAllocationTableId = MFS_FAT_LAST_BLOCK;
    } else {
#if MFS_VERSION == MFS_VERSION_B
        gMfsRamArea.fileAllocationTable[newFatId] = MFS_FAT_LAST_BLOCK;
#else
        gFileAllocationTable[newFatId] = MFS_FAT_LAST_BLOCK;
#endif
    }
#if MFS_VERSION == MFS_VERSION_C
    Mfs_CopyFATToRam();
#endif
    Mfs_CreateDirEntry(parentDirId, name);
    Mfs_SetDirEntryRenewalCounter(0);
    Mfs_SetDirEntryExtension(gMfsRamArea.directoryEntry[entryId].extension);
    Mfs_CopyDirEntryToRam(nextFreeEntryId);
}
