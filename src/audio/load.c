#include "global.h"
#include "audio.h"
#include "fzxthread.h"

void func_800AEA10(void) {
    u32 i;

    for (i = 0; i < gSampleDmaListSize1; i++) {
        SampleDma* dma = &gSampleDmas[i];

        if (dma->ttl != 0) {
            dma->ttl--;
            if (dma->ttl == 0) {
                dma->reuseIndex = gSampleDmaReuseQueue1WrPos;
                gSampleDmaReuseQueue1[gSampleDmaReuseQueue1WrPos] = i;
                gSampleDmaReuseQueue1WrPos++;
            }
        }
    }

    for (i = gSampleDmaListSize1; i < gSampleDmaCount; i++) {
        SampleDma* dma = &gSampleDmas[i];

        if (dma->ttl != 0) {
            dma->ttl--;
            if (dma->ttl == 0) {
                dma->reuseIndex = gSampleDmaReuseQueue2WrPos;
                gSampleDmaReuseQueue2[gSampleDmaReuseQueue2WrPos] = i;
                gSampleDmaReuseQueue2WrPos++;
            }
        }
    }

    gSampleDmaListSize2 = 0;
}

extern const char D_800D0AE4[]; // "SUPERDMA"

s32 func_800B03A0(OSIoMesg*, u32, s32, uintptr_t, void*, size_t, OSMesgQueue*, s32, const char*);

void* func_800AEB28(uintptr_t devAddr, size_t size, s32 arg2, u8* dmaIndexRef, s32 medium) {
    s32 pad1;
    SampleDma* dma;
    s32 hasDma = false;
    u32 dmaDevAddr;
    u32 pad2;
    u32 dmaIndex;
    u32 transfer;
    s32 bufferPos;
    u32 i;

    if (arg2 != 0 || *dmaIndexRef >= gSampleDmaListSize1) {
        for (i = gSampleDmaListSize1; i < gSampleDmaCount; i++) {
            dma = &gSampleDmas[i];
            bufferPos = devAddr - dma->devAddr;
            if (0 <= bufferPos && (u32) bufferPos <= dma->size - size) {
                // We already have a DMA request for this memory range.
                if (dma->ttl == 0 && gSampleDmaReuseQueue2RdPos != gSampleDmaReuseQueue2WrPos) {
                    // Move the DMA out of the reuse queue, by swapping it with the
                    // read pos, and then incrementing the read pos.
                    if (dma->reuseIndex != gSampleDmaReuseQueue2RdPos) {
                        gSampleDmaReuseQueue2[dma->reuseIndex] = gSampleDmaReuseQueue2[gSampleDmaReuseQueue2RdPos];
                        gSampleDmas[gSampleDmaReuseQueue2[gSampleDmaReuseQueue2RdPos]].reuseIndex = dma->reuseIndex;
                    }
                    gSampleDmaReuseQueue2RdPos++;
                }
                dma->ttl = 32;
                *dmaIndexRef = (u8) i;
                return &dma->ramAddr[devAddr - dma->devAddr];
            }
        }

        if (arg2 == 0) {
            goto search_short_lived;
        }

        if (gSampleDmaReuseQueue2RdPos != gSampleDmaReuseQueue2WrPos && arg2 != 0) {
            // Allocate a DMA from reuse queue 2, unless full.
            dmaIndex = gSampleDmaReuseQueue2[gSampleDmaReuseQueue2RdPos];
            gSampleDmaReuseQueue2RdPos++;
            dma = gSampleDmas + dmaIndex;
            hasDma = true;
        }
    } else {
    search_short_lived:
        dma = &gSampleDmas[*dmaIndexRef];
        i = 0;
    again:
        bufferPos = devAddr - dma->devAddr;
        if (0 <= bufferPos && (u32) bufferPos <= dma->size - size) {
            // We already have DMA for this memory range.
            if (dma->ttl == 0) {
                // FAKE
                if (1) {}
                if (1) {}
                // Move the DMA out of the reuse queue, by swapping it with the
                // read pos, and then incrementing the read pos.
                if (dma->reuseIndex != gSampleDmaReuseQueue1RdPos) {
                    gSampleDmaReuseQueue1[dma->reuseIndex] = gSampleDmaReuseQueue1[gSampleDmaReuseQueue1RdPos];
                    gSampleDmas[gSampleDmaReuseQueue1[gSampleDmaReuseQueue1RdPos]].reuseIndex = dma->reuseIndex;
                }
                gSampleDmaReuseQueue1RdPos++;
            }
            dma->ttl = 2;
            return dma->ramAddr + (devAddr - dma->devAddr);
        }
        dma = gSampleDmas + i++;
        if (i <= gSampleDmaListSize1) {
            goto again;
        }
    }

    if (!hasDma) {
        if (gSampleDmaReuseQueue1RdPos == gSampleDmaReuseQueue1WrPos) {
            return NULL;
        }
        // Allocate a DMA from reuse queue 1.
        dmaIndex = gSampleDmaReuseQueue1[gSampleDmaReuseQueue1RdPos++];
        dma = gSampleDmas + dmaIndex;
        hasDma = true;
    }

    transfer = dma->size;
    dmaDevAddr = devAddr & ~0xF;
    dma->ttl = 3;
    dma->devAddr = dmaDevAddr;
    dma->sizeUnused = transfer;
    func_800B03A0(&gCurAudioFrameDmaIoMsgBuf[gCurAudioFrameDmaCount++], OS_MESG_PRI_NORMAL, OS_READ, dmaDevAddr,
                  dma->ramAddr, transfer, &gCurAudioFrameDmaQueue, medium, D_800D0AE4);
    *dmaIndexRef = dmaIndex;
    return (devAddr - dmaDevAddr) + dma->ramAddr;
}

void* func_800B2A8C(AudioAllocPool*, u32);

void func_800AEEA0(s32 numNotes) {
    void* ramAddr;
    s32 i;

    gSampleDmaBufSize = 0x2D0;
    gSampleDmas = func_800B2A8C(&gMiscPool, 4 * gNumNotes * sizeof(SampleDma));

    for (i = 0; i < gNumNotes * 3; i++) {
        ramAddr = func_800B2A8C(&gMiscPool, gSampleDmaBufSize);
        gSampleDmas[gSampleDmaCount].ramAddr = ramAddr;
        if (ramAddr == NULL) {
            if (gExternalPool.startRamAddr == NULL) {
                break;
            }
            ramAddr = func_800B2A8C(&gExternalPool, gSampleDmaBufSize);
            gSampleDmas[gSampleDmaCount].ramAddr = ramAddr;
            if (ramAddr == NULL) {
                break;
            }
        }
        gSampleDmas[gSampleDmaCount].size = gSampleDmaBufSize;
        gSampleDmas[gSampleDmaCount].devAddr = 0;
        gSampleDmas[gSampleDmaCount].sizeUnused = 0;
        gSampleDmas[gSampleDmaCount].unused = 0;
        gSampleDmas[gSampleDmaCount].ttl = 0;
        gSampleDmaCount++;
    }

    for (i = 0; i < gSampleDmaCount; i++) {
        gSampleDmaReuseQueue1[i] = i;
        gSampleDmas[i].reuseIndex = i;
    }

    for (i = gSampleDmaCount; i < 0x100; i++) {
        gSampleDmaReuseQueue1[i] = 0;
    }

    gSampleDmaReuseQueue1RdPos = 0;
    gSampleDmaReuseQueue1WrPos = gSampleDmaCount;
    gSampleDmaListSize1 = gSampleDmaCount;
    gSampleDmaBufSize = 0x400;

    for (i = 0; i < gNumNotes; i++) {
        ramAddr = func_800B2A8C(&gMiscPool, gSampleDmaBufSize);
        gSampleDmas[gSampleDmaCount].ramAddr = ramAddr;
        if (ramAddr == NULL) {
            if (gExternalPool.startRamAddr == NULL) {
                break;
            }
            ramAddr = func_800B2A8C(&gExternalPool, gSampleDmaBufSize);
            gSampleDmas[gSampleDmaCount].ramAddr = ramAddr;
            if (ramAddr == NULL) {
                break;
            }
        }
        gSampleDmas[gSampleDmaCount].size = gSampleDmaBufSize;
        gSampleDmas[gSampleDmaCount].devAddr = 0U;
        gSampleDmas[gSampleDmaCount].sizeUnused = 0;
        gSampleDmas[gSampleDmaCount].unused = 0;
        gSampleDmas[gSampleDmaCount].ttl = 0;
        gSampleDmaCount++;
    }

    for (i = gSampleDmaListSize1; (u32) i < gSampleDmaCount; i++) {
        gSampleDmaReuseQueue2[i - gSampleDmaListSize1] = i;
        gSampleDmas[i].reuseIndex = i - gSampleDmaListSize1;
    }

    for (i = gSampleDmaCount; i < 0x100; i++) {
        gSampleDmaReuseQueue2[i] = gSampleDmaListSize1;
    }

    gSampleDmaReuseQueue2RdPos = 0;
    gSampleDmaReuseQueue2WrPos = gSampleDmaCount - gSampleDmaListSize1;
}

bool func_800AF288(s32 fontId) {
    if (fontId == 0xFF) {
        return true;
    } else if (gFontLoadStatus[fontId] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else {
        return false;
    }
}

bool func_800AF2C4(s32 seqId) {
    if (seqId == 0xFF) {
        return true;
    } else if (gSeqLoadStatus[seqId] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else {
        return false;
    }
}

bool func_800AF300(s32 sampleBankId) {
    if (sampleBankId == 0xFF) {
        return true;
    } else if (gSampleFontLoadStatus[sampleBankId] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else {
        return false;
    }
}

void func_800AF33C(s32 fontId, s32 loadStatus) {
    if ((fontId != 0xFF) && (gFontLoadStatus[fontId] != LOAD_STATUS_PERMANENTLY_LOADED)) {
        gFontLoadStatus[fontId] = loadStatus;
    }
}

void func_800AF36C(s32 seqId, s32 loadStatus) {
    if ((seqId != 0xFF) && (gSeqLoadStatus[seqId] != LOAD_STATUS_PERMANENTLY_LOADED)) {
        gSeqLoadStatus[seqId] = loadStatus;
    }
}

void func_800AF39C(s32 sampleBankId, s32 loadStatus) {
    if ((sampleBankId != 0xFF) && (gSampleFontLoadStatus[sampleBankId] != LOAD_STATUS_PERMANENTLY_LOADED)) {
        gSampleFontLoadStatus[sampleBankId] = loadStatus;
    }
}

void func_800AF3CC(AudioTable* table, u32 romAddr, u16 unkMediumParam) {
    s32 i;

    table->unkMediumParam = unkMediumParam;
    table->romAddr = romAddr;

    for (i = 0; i < table->numEntries; i++) {
        if ((table->entries[i].size != 0) && (table->entries[i].medium == MEDIUM_CART)) {
            table->entries[i].romAddr += romAddr;
        }
    }
}

s32 func_800AFFC4(s32, u32);
void* func_800AFCF4(s32);

void* func_800AF42C(s32 seqId, u32* outFontId) {
    s32 index = ((u16*) gSeqFontTable)[func_800AFFC4(SEQUENCE_TABLE, seqId)];
    s32 fontId = 0xFF;
    s32 numFonts;
    void* soundFontData;

    for (numFonts = gSeqFontTable[index++]; numFonts > 0; numFonts--) {
        fontId = gSeqFontTable[index++];
        soundFontData = func_800AFCF4(fontId);
    }
    *outFontId = fontId;
    return soundFontData;
}

void* func_800AFBE8(s32);

void func_800AF4D8(s32 seqId, s32 flags) {
    s32 pad;
    u32 fontId;

    seqId = func_800AFFC4(SEQUENCE_TABLE, seqId);
    if (flags & 2) {
        func_800AF42C(seqId, &fontId);
    }
    if (flags & 1) {
        func_800AFBE8(seqId);
    }
}

void* func_800B43A0(size_t, s32, uintptr_t, s8);
void func_800B038C(uintptr_t, u8*, size_t, s32);
void func_800B0268(uintptr_t, u8*, size_t, s32);

s32 func_800AF540(Sample* sample, s32 fontId) {
    u8* sampleAddr;

    if ((sample->isRelocated == 1) && (sample->medium != 0)) {
        sampleAddr = func_800B43A0(sample->size, fontId, sample->sampleAddr, sample->medium);
        if (sampleAddr == NULL) {
            return -1;
        }
        if (sample->medium == MEDIUM_UNK) {
            func_800B038C(sample->sampleAddr, sampleAddr, sample->size, gSampleBankTable->unkMediumParam);
        } else {
            func_800B0268(sample->sampleAddr, sampleAddr, sample->size, sample->medium);
        }
        sample->medium = MEDIUM_RAM;
        sample->sampleAddr = sampleAddr;
    }
}

s32 func_800AF624(s32 fontId, s32 instId, s32 drumId) {
    Instrument* instrument;
    Drum* drum;

    if (instId < 0x7F) {
        instrument = func_800AAD2C(fontId, instId);
        if (instrument == NULL) {
            return -1;
        }
        if (instrument->normalRangeLo != 0) {
            func_800AF540(instrument->lowPitchTunedSample.sample, fontId);
        }
        func_800AF540(instrument->normalPitchTunedSample.sample, fontId);
        if (instrument->normalRangeHi != 0x7F) {
            func_800AF540(instrument->highPitchTunedSample.sample, fontId);
        }
    } else if (instId == 0x7F) {
        drum = func_800AAD58(fontId, drumId);
        if (drum == NULL) {
            return -1;
        }
        func_800AF540(drum->tunedSample.sample, fontId);
        return 0;
    }
}

void* func_800B04C4(s32, s32, s32, s32, OSMesgQueue*);

void func_800AF6F4(s32 sampleBankId, s32 nChunks, s32 retData, OSMesgQueue* retQueue) {
    if (func_800B04C4(SAMPLE_TABLE, func_800AFFC4(SAMPLE_TABLE, sampleBankId), nChunks, retData, retQueue) == NULL) {
        osSendMesg(retQueue, NULL, OS_MESG_NOBLOCK);
    }
}

void func_800AF758(s32 seqId, s32 nChunks, s32 retData, OSMesgQueue* retQueue) {
    s32 index = ((u16*) gSeqFontTable)[func_800AFFC4(SEQUENCE_TABLE, seqId)];
    s32 fontsLeft;

    for (fontsLeft = gSeqFontTable[index++]; fontsLeft > 0; fontsLeft--) {
        func_800B04C4(FONT_TABLE, func_800AFFC4(FONT_TABLE, gSeqFontTable[index++]), nChunks, retData, retQueue);
    }
}

u8* func_800AF820(s32 seqId, u32* outNumFonts) {
    s32 index = ((u16*) gSeqFontTable)[func_800AFFC4(SEQUENCE_TABLE, seqId)];

    *outNumFonts = gSeqFontTable[index++];
    if (*outNumFonts == 0) {
        return NULL;
    }
    return &gSeqFontTable[index];
}

void* func_800B4278(s32, s32);
void func_800AF944(s32);

void func_800AF888(s32 seqId) {
    s32 index = ((u16*) gSeqFontTable)[func_800AFFC4(SEQUENCE_TABLE, seqId)];
    s32 numFonts = gSeqFontTable[index++];
    u32 fontId;

    while (numFonts > 0) {
        numFonts--;
        fontId = func_800AFFC4(FONT_TABLE, gSeqFontTable[index++]);
        if (func_800B4278(FONT_TABLE, fontId) == NULL) {
            func_800AF944(fontId);
            func_800AF33C(fontId, LOAD_STATUS_NOT_LOADED);
        }
    }
}

void func_800B289C(s32);

void func_800AF944(s32 fontId) {
    AudioCache* cache = &gFontCache;
    AudioTemporaryCache* tcache;
    AudioPersistentCache* pcache;
    s32 i;

    tcache = &cache->temporary;
    if (tcache->entries[0].id == fontId) {
        tcache->entries[0].id = -1;
    } else if (tcache->entries[1].id == fontId) {
        tcache->entries[1].id = -1;
    }
    pcache = &cache->persistent;
    for (i = 0; i < pcache->numEntries; i++) {
        if (pcache->entries[i].id == fontId) {
            pcache->entries[i].id = -1;
        }
    }
    func_800B289C(fontId);
}

void func_800AFAAC(s32, s32, s32);

s32 func_800AF9EC(s32 seqPlayerIndex, s32 seqId, s32 arg2) {
    if (gResetTimer != 0) {
        return 0;
    }
    gSeqPlayers[seqPlayerIndex].skipTicks = 0;
    func_800AFAAC(seqPlayerIndex, seqId, arg2);
}

s32 func_800AFA48(s32 seqPlayerIndex, s32 seqId, s32 skipTicks) {
    if (gResetTimer != 0) {
        return 0;
    }
    gSeqPlayers[seqPlayerIndex].skipTicks = skipTicks;
    func_800AFAAC(seqPlayerIndex, seqId, 0);
}

void func_800AFAAC(s32 seqPlayerIndex, s32 seqId, s32 arg2) {
    s32 index;
    s32 numFonts;
    u8* seqData;
    s32 fontId;
    s32 i;

    seqId = func_800AFFC4(SEQUENCE_TABLE, seqId);
    func_800AC744(&gSeqPlayers[seqPlayerIndex]);
    index = ((u16*) gSeqFontTable)[seqId];
    fontId = 0xFF;
    for (numFonts = gSeqFontTable[index++]; numFonts > 0; numFonts--) {
        fontId = gSeqFontTable[index++];
        func_800AFCF4(fontId);
    }
    seqData = func_800AFBE8(seqId);
    func_800AE700(seqPlayerIndex);
    gSeqPlayers[seqPlayerIndex].seqId = seqId;
    gSeqPlayers[seqPlayerIndex].defaultFont = fontId;
    gSeqPlayers[seqPlayerIndex].enabled = true;
    gSeqPlayers[seqPlayerIndex].seqData = seqData;
    gSeqPlayers[seqPlayerIndex].scriptState.pc = seqData;
    gSeqPlayers[seqPlayerIndex].scriptState.depth = 0;
    gSeqPlayers[seqPlayerIndex].delay = 0;
    gSeqPlayers[seqPlayerIndex].finished = false;
    func_800AE6B0(&gSeqPlayers[seqPlayerIndex]);
    for (i = 0; i < 16; i++) {}
}

void* func_800AFDD0(u32, u32, s32*);

void* func_800AFBE8(s32 seqId) {
    s32 seqIdx = func_800AFFC4(SEQUENCE_TABLE, seqId);
    s32 didAllocate;

    return func_800AFDD0(SEQUENCE_TABLE, seqIdx, &didAllocate);
}

AudioTable* func_800B0054(s32);
void* func_800B0000(s32, u32);

void* func_800AFC1C(u32 sampleBankId, u32* outMedium) {
    void* ramAddr;
    AudioTable* sampleBankTable = func_800B0054(SAMPLE_TABLE);
    s32 cachePolicy;
    s32 noLoad;

    sampleBankId = func_800AFFC4(SAMPLE_TABLE, sampleBankId);
    ramAddr = func_800B0000(SAMPLE_TABLE, sampleBankId);
    if (ramAddr != NULL) {
        func_800AF39C(sampleBankId, LOAD_STATUS_COMPLETE);
        *outMedium = MEDIUM_RAM;
        return ramAddr;
    }
    cachePolicy = sampleBankTable->entries[sampleBankId].cachePolicy;
    if (cachePolicy == CACHEPOLICY_4) {
        *outMedium = sampleBankTable->entries[sampleBankId].medium;
        return sampleBankTable->entries[sampleBankId].romAddr;
    }
    ramAddr = func_800AFDD0(SAMPLE_TABLE, sampleBankId, &noLoad);
    if (ramAddr != NULL) {
        *outMedium = MEDIUM_RAM;
        return ramAddr;
    }
    *outMedium = sampleBankTable->entries[sampleBankId].medium;
    return sampleBankTable->entries[sampleBankId].romAddr;
}

void func_800B17AC(s32, u32, SampleBankRelocInfo*, s32);

void* func_800AFCF4(s32 fontId) {
    void* fontData;
    s32 sampleBankId1;
    u32 sampleBankId2;
    s32 didAllocate;
    SampleBankRelocInfo relocInfo;

    fontId = func_800AFFC4(FONT_TABLE, fontId);
    sampleBankId1 = gSoundFontList[fontId].sampleBankId1;
    sampleBankId2 = gSoundFontList[fontId].sampleBankId2;

    relocInfo.sampleBankId1 = sampleBankId1;
    relocInfo.sampleBankId2 = sampleBankId2;
    if (sampleBankId1 != SAMPLES_NONE) {
        relocInfo.baseAddr1 = func_800AFC1C(sampleBankId1, &relocInfo.medium1);
    } else {
        relocInfo.baseAddr1 = NULL;
    }
    if (sampleBankId2 != SAMPLES_NONE) {
        relocInfo.baseAddr2 = func_800AFC1C(sampleBankId2, &relocInfo.medium2);
    } else {
        relocInfo.baseAddr2 = NULL;
    }
    fontData = func_800AFDD0(FONT_TABLE, fontId, &didAllocate);
    if (fontData == NULL) {
        return NULL;
    }
    if (didAllocate == 1) {
        func_800B17AC(fontId, fontData, &relocInfo, AUDIOLOAD_SYNC);
    }
    return fontData;
}

u8* func_800B42D0(s32 tableType, s32 id, u32 size);
void* func_800B2E30(s32 tableType, s32 size, s32 cache, s32 id);

void* func_800AFDD0(u32 tableType, u32 id, s32* didAllocate) {
    u32 size;
    AudioTable* table;
    u8* ramAddr;
    u32 medium;
    s32 loadStatus;
    u32 romAddr;
    s32 pad;
    s32 cachePolicy;

    ramAddr = func_800B0000(tableType, id);
    if (ramAddr != NULL) {
        loadStatus = LOAD_STATUS_COMPLETE;
        *didAllocate = false;
    } else {
        table = func_800B0054(tableType);
        size = table->entries[id].size;
        size = ALIGN16(size);
        medium = table->entries[id].medium;
        cachePolicy = table->entries[id].cachePolicy;
        romAddr = table->entries[id].romAddr;
        switch (cachePolicy) {
            case CACHEPOLICY_0:
                ramAddr = func_800B42D0(tableType, id, size);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
            case CACHEPOLICY_1:
                ramAddr = func_800B2E30(tableType, size, CACHE_PERSISTENT, id);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
            case CACHEPOLICY_2:
                ramAddr = func_800B2E30(tableType, size, CACHE_TEMPORARY, id);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
            case CACHEPOLICY_3:
            case CACHEPOLICY_4:
                ramAddr = func_800B2E30(tableType, size, CACHE_EITHER, id);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
        }

        *didAllocate = true;
        if (medium == MEDIUM_UNK) {
            func_800B038C(romAddr, ramAddr, size, table->unkMediumParam);
        } else {
            func_800B0268(romAddr, ramAddr, size, medium);
        }
        loadStatus = (cachePolicy == CACHEPOLICY_0) ? LOAD_STATUS_PERMANENTLY_LOADED : LOAD_STATUS_COMPLETE;
    }
    switch (tableType) {
        case SEQUENCE_TABLE:
            func_800AF36C(id, loadStatus);
            break;
        case FONT_TABLE:
            func_800AF33C(id, loadStatus);
            break;
        case SAMPLE_TABLE:
            func_800AF39C(id, loadStatus);
            break;
    }
    return ramAddr;
}

s32 func_800AFFC4(s32 tableType, u32 entryId) {
    AudioTable* table = func_800B0054(tableType);

    if (table->entries[entryId].size == 0) {
        entryId = table->entries[entryId].romAddr;
    }
    return entryId;
}

void* func_800B0000(s32 tableType, u32 id) {
    void* ramAddr;

    ramAddr = func_800B4278(tableType, id);
    if (ramAddr != NULL) {
        return ramAddr;
    }
    ramAddr = func_800B3534(tableType, CACHE_EITHER, id);
    if (ramAddr != NULL) {
        return ramAddr;
    }
    return NULL;
}

AudioTable* func_800B0054(s32 tableType) {
    AudioTable* table;

    switch (tableType) {
        case SEQUENCE_TABLE:
            table = gSequenceTable;
            break;
        case FONT_TABLE:
            table = gSoundFontTable;
            break;
        case SAMPLE_TABLE:
            table = gSampleBankTable;
            break;
        default:
            table = NULL;
            break;
    }
    return table;
}

void func_800B166C(TunedSample*, uintptr_t, SampleBankRelocInfo*);

void func_800B0098(s32 fontId, uintptr_t fontBaseAddr, void* relocData) {
    uintptr_t* fontDataPtrs = fontBaseAddr;
    Drum*** drumDataPtrs = fontBaseAddr;
    Drum* drum;
    Instrument* instrument;
    uintptr_t offset;
    s32 i;
    s32 numDrums = gSoundFontList[fontId].numDrums;
    s32 numInstruments = gSoundFontList[fontId].numInstruments;

    if ((fontDataPtrs[0] != 0) && (numDrums != 0)) {
        fontDataPtrs[0] += fontBaseAddr;

        for (i = 0; i < numDrums; i++) {
            offset = (*drumDataPtrs)[i];
            if (offset != 0) {
                drum = offset += fontBaseAddr;
                (*drumDataPtrs)[i] = drum;
                if (!drum->isRelocated) {
                    func_800B166C(&drum->tunedSample, fontBaseAddr, relocData);
                    offset = (uintptr_t) drum->envelope;
                    drum->envelope = (EnvelopePoint*) (offset + fontBaseAddr);
                    drum->isRelocated = true;
                }
            }
        }
    }
    for (i = 1; i <= numInstruments; i++) {
        if (fontDataPtrs[i] != 0) {

            fontDataPtrs[i] += fontBaseAddr;

            instrument = fontDataPtrs[i];
            if (instrument->isRelocated == 0) {
                if (instrument->normalRangeLo != 0) {
                    func_800B166C(&instrument->lowPitchTunedSample, fontBaseAddr, relocData);
                }
                func_800B166C(&instrument->normalPitchTunedSample, fontBaseAddr, relocData);
                if (instrument->normalRangeHi != 0x7F) {
                    func_800B166C(&instrument->highPitchTunedSample, fontBaseAddr, relocData);
                }
                offset = (uintptr_t) instrument->envelope;
                instrument->envelope = (EnvelopePoint*) (offset + fontBaseAddr);
                instrument->isRelocated = true;
            }
        }
    }
    gSoundFontList[fontId].drums = fontDataPtrs[0];
    gSoundFontList[fontId].instruments = (Instrument**) &fontDataPtrs[1];
}

extern const char D_800D0C14[]; // "FastCopy"
extern const char D_800D0C20[]; // "FastCopy"

void func_800B0268(uintptr_t devAddr, u8* ramAddr, size_t size, s32 medium) {
    size = ALIGN16(size);
    osInvalDCache(ramAddr, size);
    while (true) {
        if (size < 0x400) {
            break;
        }
        func_800B03A0(&gSyncDmaIoMsg, OS_MESG_PRI_HIGH, OS_READ, devAddr, ramAddr, 0x400, &gSyncDmaQueue, medium,
                      D_800D0C14);
        MQ_WAIT_FOR_MESG(&gSyncDmaQueue, NULL);
        size -= 0x400;
        devAddr += 0x400;
        ramAddr += 0x400;
    }
    if (size != 0) {
        func_800B03A0(&gSyncDmaIoMsg, OS_MESG_PRI_HIGH, OS_READ, devAddr, ramAddr, size, &gSyncDmaQueue, medium,
                      D_800D0C20);
        MQ_WAIT_FOR_MESG(&gSyncDmaQueue, NULL);
    }
}

void func_800B038C(uintptr_t devAddr, u8* ramAddr, size_t size, s32 unkMediumParam) {
}

// osEPiStartDma
extern DmaHandler sDmaHandler;

s32 func_800B03A0(OSIoMesg* mesg, u32 priority, s32 direction, uintptr_t devAddr, void* ramAddr, size_t size,
                  OSMesgQueue* retQueue, s32 medium, const char* dmaType) {
    OSPiHandle* handle;

    if (gResetTimer > 16) {
        return -1;
    }

    switch (medium) {
        case MEDIUM_CART:
            handle = osCartRomInit();
            break;
        case MEDIUM_DISK_DRIVE:
            handle = osDriveRomInit();
            break;
        default:
            return 0;
    }

    if (size & 0xF) {
        size = ALIGN16(size);
    }
    mesg->hdr.pri = priority;
    mesg->hdr.retQueue = retQueue;
    mesg->dramAddr = ramAddr;
    mesg->devAddr = devAddr;
    mesg->size = size;
    handle->transferInfo.cmdType = 2;
    sDmaHandler(handle, mesg, direction);

    return 0;
}

void func_800B049C(void) {
}

void func_800B04A4(u32 tableType, u32 id) {
    s32 didAllocate;

    func_800AFDD0(tableType, id, &didAllocate);
}

AudioAsyncLoad* func_800B11D8(uintptr_t, u8*, size_t, s32, s32, OSMesgQueue*, u32);

void* func_800B04C4(s32 tableType, s32 id, s32 nChunks, s32 retData, OSMesgQueue* retQueue) {
    u32 size;
    AudioTable* table;
    u8* ramAddr;
    s32 medium;
    s32 cachePolicy;
    u32 romAddr;
    s32 loadStatus;

    switch (tableType) {
        case SEQUENCE_TABLE:
            if (gSeqLoadStatus[id] == LOAD_STATUS_IN_PROGRESS) {
                return NULL;
            }
            break;
        case FONT_TABLE:
            if (gFontLoadStatus[id] == LOAD_STATUS_IN_PROGRESS) {
                return NULL;
            }
            break;
        case SAMPLE_TABLE:
            if (gSampleFontLoadStatus[id] == LOAD_STATUS_IN_PROGRESS) {
                return NULL;
            }
            break;
    }
    ramAddr = func_800B0000(tableType, id);
    if (ramAddr != NULL) {
        loadStatus = LOAD_STATUS_COMPLETE;
        osSendMesg(retQueue, (OSMesg) (retData << 0x18), OS_MESG_NOBLOCK);
    } else {
        table = func_800B0054(tableType);
        size = table->entries[id].size;
        size = ALIGN16(size);
        medium = table->entries[id].medium;
        cachePolicy = table->entries[id].cachePolicy;
        romAddr = table->entries[id].romAddr;
        loadStatus = LOAD_STATUS_COMPLETE;
        switch (cachePolicy) {
            case CACHEPOLICY_0:
                ramAddr = func_800B42D0(tableType, id, size);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                loadStatus = LOAD_STATUS_PERMANENTLY_LOADED;
                break;
            case CACHEPOLICY_1:
                ramAddr = func_800B2E30(tableType, size, CACHE_PERSISTENT, id);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
            case CACHEPOLICY_2:
                ramAddr = func_800B2E30(tableType, size, CACHE_TEMPORARY, id);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
            case CACHEPOLICY_3:
            case CACHEPOLICY_4:
                ramAddr = func_800B2E30(tableType, size, CACHE_EITHER, id);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
        }
        func_800B11D8(romAddr, ramAddr, size, medium, nChunks, retQueue,
                      (retData << 0x18) | (tableType << 0x10) | (id << 8) | loadStatus);
        loadStatus = LOAD_STATUS_IN_PROGRESS;
    }
    switch (tableType) {
        case SEQUENCE_TABLE:
            func_800AF36C(id, loadStatus);
            break;
        case FONT_TABLE:
            func_800AF33C(id, loadStatus);
            break;
        case SAMPLE_TABLE:
            func_800AF39C(id, loadStatus);
            break;
    }

    return ramAddr;
}

void func_800B0FB4(s32);
bool func_800B1B40(s32);
void func_800B12EC(s32);

void func_800B0754(s32 resetStatus) {
    func_800B0FB4(resetStatus);
    func_800B1B40(resetStatus);
    func_800B12EC(resetStatus);
}

void func_800B0784(DmaHandler callback) {
    sDmaHandler = callback;
}

extern void* sUnusedHandler;

void func_800B0790(void* callback) {
    sUnusedHandler = callback;
}

void func_800B2B60(s32);

void func_800B079C(void* heap, size_t heapSize) {
    s32 numFonts;
    void* ramAddr;
    s32 i;

    gResetTimer = 0;

    for (i = 0; i < gAudioHeapSize / (s32) sizeof(s64); i++) {
        ((s64*) gAudioHeap)[i] = 0;
    }

    {
        s32 i;
        s64* audioContextPtr = (s64*) SEGMENT_BSS_START(audio_context);
        size_t audioContextSize = SEGMENT_BSS_SIZE(audio_context);

        for (i = audioContextSize / sizeof(s64); i >= 0; i--) {
            *audioContextPtr++ = 0;
        }
    }

    gMaxTempoTvTypeFactors = 1000 * REFRESH_RATE_DEVIATION_NTSC / REFRESH_RATE_NTSC;
    gRefreshRate = REFRESH_RATE_NTSC;

    func_800B71A4();

    for (i = 0; i < 3; i++) {
        gAiBufLengths[i] = 0xA0;
    }

    gTotalTaskCount = 0;
    gRspTaskIndex = 0;
    gCurAiBufIndex = 0;
    gSoundMode = SOUNDMODE_STEREO;
    gCurTask = NULL;
    gRspTask[0].task.t.data_size = 0;
    gRspTask[1].task.t.data_size = 0;
    osCreateMesgQueue(&gSyncDmaQueue, &gSyncDmaMsg, 1);
    osCreateMesgQueue(&gCurAudioFrameDmaQueue, gCurAudioFrameDmaMsgBuf, ARRAY_COUNT(gCurAudioFrameDmaMsgBuf));
    osCreateMesgQueue(&gExternalLoadQueue, gExternalLoadMsgBuf, ARRAY_COUNT(gExternalLoadMsgBuf));
    osCreateMesgQueue(&gPreloadSampleQueue, gPreloadSampleMsgBuf, ARRAY_COUNT(gPreloadSampleMsgBuf));
    gCurAudioFrameDmaCount = 0;
    gSampleDmaCount = 0;

    // Main Pool Split (split entirety of audio heap into initPool and sessionPool)
    func_800B2B60(gInitPoolSize);

    // Initialize the audio interface buffers
    for (i = 0; i < ARRAY_COUNT(gAiBuffers); i++) {
        s16* ramAddr = gAiBuffers[i] = func_800B2A8C(&gInitPool, AIBUF_SIZE);
        s32 j;

        for (j = 0; j < 0x580; j++, ramAddr++) {
            *ramAddr = 0;
        }
    }
    gSpecId = 0;
    gResetStatus = 1; // Set reset to immediately initialize the audio heap

    func_800B38AC();

    // Set audio tables pointers
    gSequenceTable = (AudioTable*) gSequenceTableData;
    gSoundFontTable = (AudioTable*) gSoundFontTableData;
    gSampleBankTable = (AudioTable*) gSampleBankTableData;
    gSeqFontTable = gSequenceFontTableData;

    gNumSequences = gSequenceTable->numEntries;

    // Initialize audio tables
    func_800AF3CC(gSequenceTable, SEGMENT_ROM_START(audio_seq), 0);
    func_800AF3CC(gSoundFontTable, SEGMENT_ROM_START(audio_bank), 0);
    func_800AF3CC(gSampleBankTable, SEGMENT_ROM_START(audio_table), 0);
    numFonts = gSoundFontTable->numEntries;
    gSoundFontList = func_800B2A8C(&gInitPool, numFonts * sizeof(SoundFont));

    for (i = 0; i < numFonts; i++) {
        gSoundFontList[i].sampleBankId1 = (gSoundFontTable->entries[i].shortData1 >> 8) & 0xFF;
        gSoundFontList[i].sampleBankId2 = (gSoundFontTable->entries[i].shortData1) & 0xFF;
        gSoundFontList[i].numInstruments = (gSoundFontTable->entries[i].shortData2 >> 8) & 0xFF;
        gSoundFontList[i].numDrums = gSoundFontTable->entries[i].shortData2 & 0xFF;
    }

    ramAddr = func_800B2A8C(&gInitPool, gPermanentPoolSize);
    if (ramAddr == NULL) {
        gPermanentPoolSize = 0;
    }

    func_800B2AE4(&gPermanentCache.pool, ramAddr, gPermanentPoolSize);
    gAudioContextInitialized = true;
}

Sample* func_800B0EE0(s32, s32);

s32 func_800B0D30(s32 fontId, u8 instId, s8* status) {
    Sample* sample;
    AudioSlowLoad* slowLoad;

    sample = func_800B0EE0(fontId, instId);
    if (sample == NULL) {
        *status = 0;
        return -1;
    }

    if (sample->medium == MEDIUM_RAM) {
        *status = 2;
        return 0;
    }

    slowLoad = &gSlowLoads.slowLoad[gSlowLoads.slowLoadPos];
    if (slowLoad->state == SLOW_LOAD_DONE) {
        slowLoad->state = SLOW_LOAD_WAITING;
    }

    slowLoad->sample = *sample;
    slowLoad->status = status;
    slowLoad->curRamAddr = func_800B4350(sample->size, fontId, sample->sampleAddr, sample->medium);

    if (slowLoad->curRamAddr == NULL) {
        if (sample->medium == MEDIUM_UNK || sample->codec == CODEC_S16_INMEMORY) {
            *status = SLOW_LOAD_STATUS_0;
            return -1;
        } else {
            *status = SLOW_LOAD_STATUS_3;
            return -1;
        }
    }

    slowLoad->state = SLOW_LOAD_START;
    slowLoad->bytesRemaining = ALIGN16(sample->size);
    slowLoad->ramAddr = slowLoad->curRamAddr;
    slowLoad->curDevAddr = sample->sampleAddr;
    slowLoad->medium = sample->medium;
    slowLoad->seqOrFontId = fontId;
    slowLoad->instId = instId;

    gSlowLoads.slowLoadPos ^= 1;
    return 0;
}

Sample* func_800B0EE0(s32 fontId, s32 instId) {
    Sample* sample;
    Drum* drum;
    Instrument* instrument;

    if (instId < 0x80) {
        instrument = func_800AAD2C(fontId, instId);
        if (instrument == NULL) {
            return NULL;
        }
        sample = instrument->normalPitchTunedSample.sample;
    } else {
        drum = func_800AAD58(fontId, instId - 0x80);
        if (drum == NULL) {
            return NULL;
        }
        sample = drum->tunedSample.sample;
    }
    return sample;
}

void func_800B0F44(void) {
}

void func_800B0F4C(AudioSlowLoad* slowLoad) {
    Sample* sample = func_800B0EE0(slowLoad->seqOrFontId, slowLoad->instId);

    if (sample != NULL) {
        slowLoad->sample = *sample;
        sample->sampleAddr = slowLoad->ramAddr;
        sample->medium = MEDIUM_RAM;
    }
}

void func_800B1140(AudioSlowLoad*, s32);
void func_800B11C4(uintptr_t, u8*, size_t, s32);

void func_800B0FB4(s32 resetStatus) {
    AudioTable* sampleBankTable = gSampleBankTable;
    AudioSlowLoad* slowLoad;
    s32 i;

    for (i = 0; i < 2; i++) {
        slowLoad = &gSlowLoads.slowLoad[i];
        switch (slowLoad->state) {
            case SLOW_LOAD_LOADING:
                MQ_WAIT_FOR_MESG(&slowLoad->msgQueue, NULL);
                if (resetStatus != 0) {
                    slowLoad->state = SLOW_LOAD_DONE;
                    break;
                }
            case SLOW_LOAD_START:
                slowLoad->state = SLOW_LOAD_LOADING;
                if (slowLoad->bytesRemaining == 0) {
                    func_800B0F4C(&gSlowLoads.slowLoad[i]);
                    slowLoad->state = SLOW_LOAD_DONE;
                    *slowLoad->status = SLOW_LOAD_STATUS_1;
                } else if (slowLoad->bytesRemaining < 0x1000) {
                    if (slowLoad->medium == MEDIUM_UNK) {
                        func_800B11C4(slowLoad->curDevAddr, slowLoad->curRamAddr, slowLoad->bytesRemaining,
                                      sampleBankTable->unkMediumParam);
                    } else {
                        func_800B1140(&gSlowLoads.slowLoad[i], slowLoad->bytesRemaining);
                    }
                    slowLoad->bytesRemaining = 0;
                } else {
                    if (slowLoad->medium == MEDIUM_UNK) {
                        func_800B11C4(slowLoad->curDevAddr, slowLoad->curRamAddr, 0x1000,
                                      sampleBankTable->unkMediumParam);
                    } else {
                        func_800B1140(&gSlowLoads.slowLoad[i], 0x1000);
                    }
                    slowLoad->bytesRemaining -= 0x1000;
                    slowLoad->curRamAddr += 0x1000;
                    slowLoad->curDevAddr += 0x1000;
                }
                break;
        }
    }
}

extern const char D_800D0E38[]; // "SLOWCOPY"

void func_800B1140(AudioSlowLoad* slowLoad, s32 size) {
    osInvalDCache(slowLoad->curRamAddr, size);
    osCreateMesgQueue(&slowLoad->msgQueue, &slowLoad->msg, 1);
    func_800B03A0(&slowLoad->ioMesg, OS_MESG_PRI_NORMAL, OS_READ, slowLoad->curDevAddr, slowLoad->curRamAddr, size,
                  &slowLoad->msgQueue, slowLoad->medium, D_800D0E38);
}

void func_800B11C4(uintptr_t devAddr, u8* ramAddr, size_t size, s32 unkMediumParam) {
}

AudioAsyncLoad* func_800B11D8(uintptr_t devAddr, u8* ramAddr, size_t size, s32 medium, s32 nChunks,
                              OSMesgQueue* retQueue, u32 retMesg) {
    AudioAsyncLoad* asyncLoad;
    s32 i;

    for (i = 0; i < 16; i++) {
        if (gAsyncLoads[i].status == 0) {
            asyncLoad = &gAsyncLoads[i];
            break;
        }
    }
    if (i == 16) {
        return NULL;
    }
    asyncLoad->status = 1;
    asyncLoad->curDevAddr = devAddr;
    asyncLoad->ramAddr = ramAddr;
    asyncLoad->curRamAddr = ramAddr;
    asyncLoad->bytesRemaining = size;

    if (nChunks == 0) {
        asyncLoad->chunkSize = 0x1000;
    } else {
        asyncLoad->chunkSize = ALIGN256((s32) size / nChunks);
        if (asyncLoad->chunkSize < 0x100) {
            asyncLoad->chunkSize = 0x100;
        }
    }
    asyncLoad->retQueue = retQueue;

    asyncLoad->delay = 3;
    asyncLoad->medium = medium;
    asyncLoad->retMsg = retMesg;

    osCreateMesgQueue(&asyncLoad->mesgQueue, &asyncLoad->msg, 1);
    return asyncLoad;
}

void func_800B1370(AudioAsyncLoad*, s32);

void func_800B12EC(s32 resetStatus) {
    s32 i;

    if (gResetTimer == 1) {
        return;
    }

    for (i = 0; i < 16; i++) {
        if (gAsyncLoads[i].status == 1) {
            func_800B1370(&gAsyncLoads[i], resetStatus);
        }
    }
}

void func_800B15C8(AudioAsyncLoad*, size_t);
void func_800B1658(uintptr_t, u8*, size_t, s32);

void func_800B1370(AudioAsyncLoad* asyncLoad, s32 resetStatus) {
    AudioTable* sampleTable = gSampleBankTable;
    s32 tableType;
    s32 loadStatus;
    u32 msg;
    s32 tableIndex;
    s32 sampleBankId1;
    s32 sampleBankId2;
    SampleBankRelocInfo relocInfo;

    if (asyncLoad->delay > 1) {
        asyncLoad->delay--;
        return;
    }
    if (asyncLoad->delay == 1) {
        asyncLoad->delay = 0;
    } else {
        if (resetStatus != 0) {
            MQ_WAIT_FOR_MESG(&asyncLoad->mesgQueue, NULL);
            asyncLoad->status = 0;
            return;
        }
        if (!MQ_GET_MESG(&asyncLoad->mesgQueue, NULL)) {
            return;
        }
    }
    if (asyncLoad->bytesRemaining == 0) {
        msg = asyncLoad->retMsg;
        tableType = (msg >> 0x10) & 0xFF;
        tableIndex = (msg >> 8) & 0xFF;
        loadStatus = msg & 0xFF;
        switch (tableType) {
            case SEQUENCE_TABLE:
                func_800AF36C(tableIndex, loadStatus);
                break;
            case SAMPLE_TABLE:
                func_800AF39C(tableIndex, loadStatus);
                break;
            case FONT_TABLE:
                func_800AF33C(tableIndex, loadStatus);
                sampleBankId1 = gSoundFontList[tableIndex].sampleBankId1;
                sampleBankId2 = gSoundFontList[tableIndex].sampleBankId2;
                relocInfo.sampleBankId1 = sampleBankId1;
                relocInfo.sampleBankId2 = sampleBankId2;
                if (sampleBankId1 != SAMPLES_NONE) {
                    relocInfo.baseAddr1 = func_800AFC1C(sampleBankId1, &relocInfo.medium1);
                } else {
                    relocInfo.baseAddr1 = NULL;
                }
                if (sampleBankId2 != SAMPLES_NONE) {
                    relocInfo.baseAddr2 = func_800AFC1C(sampleBankId2, &relocInfo.medium2);
                } else {
                    relocInfo.baseAddr2 = NULL;
                }
                func_800B17AC(tableIndex, asyncLoad->ramAddr, &relocInfo, AUDIOLOAD_ASYNC);
                break;
        }
        asyncLoad->status = 0;
        osSendMesg(asyncLoad->retQueue, asyncLoad->retMsg, OS_MESG_NOBLOCK);
    } else if (asyncLoad->bytesRemaining < asyncLoad->chunkSize) {
        if (asyncLoad->medium == MEDIUM_UNK) {
            func_800B1658(asyncLoad->curDevAddr, asyncLoad->curRamAddr, asyncLoad->bytesRemaining,
                          sampleTable->unkMediumParam);
        } else {
            func_800B15C8(asyncLoad, asyncLoad->bytesRemaining);
        }
        asyncLoad->bytesRemaining = 0;
    } else {
        if (asyncLoad->medium == MEDIUM_UNK) {
            func_800B1658(asyncLoad->curDevAddr, asyncLoad->curRamAddr, asyncLoad->chunkSize,
                          sampleTable->unkMediumParam);
        } else {
            func_800B15C8(asyncLoad, asyncLoad->chunkSize);
        }
        asyncLoad->bytesRemaining -= asyncLoad->chunkSize;
        asyncLoad->curDevAddr += asyncLoad->chunkSize;
        asyncLoad->curRamAddr += asyncLoad->chunkSize;
    }
}

extern const char D_800D0F00[]; // "BGCOPY"

void func_800B15C8(AudioAsyncLoad* asyncLoad, size_t size) {
    size = ALIGN16(size);
    osInvalDCache(asyncLoad->curRamAddr, size);
    osCreateMesgQueue(&asyncLoad->mesgQueue, &asyncLoad->msg, 1);
    if (size) {}
    func_800B03A0(&asyncLoad->ioMesg, OS_MESG_PRI_NORMAL, OS_READ, asyncLoad->curDevAddr, asyncLoad->curRamAddr, size,
                  &asyncLoad->mesgQueue, asyncLoad->medium, D_800D0F00);
}

void func_800B1658(uintptr_t devAddr, u8* ramAddr, size_t size, s32 unkMediumParam) {
}

void func_800B166C(TunedSample* tSample, u32 fontDataAddr, SampleBankRelocInfo* relocInfo) {
    void* reloc;
    Sample* sample;

    // "Error: Already wavetable is touched %x.\n";
    if ((u32) tSample->sample <= AUDIO_RELOCATED_ADDRESS_START) {
        sample = tSample->sample = reloc = (u32) tSample->sample + fontDataAddr;
        // "Touch Warning: Length zero %x\n";
        if ((sample->size != 0) && (sample->isRelocated != 1)) {
            sample->loop = reloc = (u32) sample->loop + fontDataAddr;
            sample->book = reloc = (u32) sample->book + fontDataAddr;
            switch (sample->medium) { /* irregular */
                case MEDIUM_RAM:
                    sample->sampleAddr = reloc = sample->sampleAddr + relocInfo->baseAddr1;
                    sample->medium = relocInfo->medium1;
                    break;
                case MEDIUM_UNK:
                    sample->sampleAddr = reloc = sample->sampleAddr + relocInfo->baseAddr2;
                    sample->medium = relocInfo->medium2;
                    break;
                case MEDIUM_CART:
                case MEDIUM_DISK_DRIVE:
                    break;
            }
            sample->isRelocated = true;
            if (sample->unk_bit26 && (sample->medium != 0)) {
                gUsedSamples[gNumUsedSamples++] = sample;
            }
        }
    }
}

extern s32 D_800F8AB8;

void func_800B17AC(s32 fontId, u32 fontDataAddr, SampleBankRelocInfo* relocData, s32 isAsync) {
    s32 i;
    Sample* sample;
    u8* sampleRamAddr;
    s32 size;
    s32 pad;
    u32 nChunks;
    s32 inProgress;

    inProgress = false;
    if (gPreloadSampleStackTop != 0) {
        inProgress = true;
    } else {
        D_800F8AB8 = 0;
    }
    gNumUsedSamples = 0;
    func_800B0098(fontId, fontDataAddr, relocData);
    size = 0;
    for (i = 0; i < gNumUsedSamples; i++) {
        size += ALIGN16(gUsedSamples[i]->size);
    }

    for (i = 0; i < gNumUsedSamples; i++) {
        if (gPreloadSampleStackTop == 120) {
            break;
        }
        sample = gUsedSamples[i];

        switch (isAsync) {
            case AUDIOLOAD_SYNC:
                if (sample->medium == relocData->medium1) {
                    sampleRamAddr =
                        func_800B43A0(sample->size, relocData->sampleBankId1, sample->sampleAddr, sample->medium);
                } else if (sample->medium == relocData->medium2) {
                    sampleRamAddr =
                        func_800B43A0(sample->size, relocData->sampleBankId2, sample->sampleAddr, sample->medium);
                }
                break;
            case AUDIOLOAD_ASYNC:
                if (sample->medium == relocData->medium1) {
                    sampleRamAddr =
                        func_800B4350(sample->size, relocData->sampleBankId1, sample->sampleAddr, sample->medium);
                } else if (sample->medium == relocData->medium2) {
                    sampleRamAddr =
                        func_800B4350(sample->size, relocData->sampleBankId2, sample->sampleAddr, sample->medium);
                }
                break;
        }
        if (sampleRamAddr == NULL) {
            continue;
        }
        switch (isAsync) {
            case AUDIOLOAD_SYNC:
                if (sample->medium == MEDIUM_UNK) {
                    func_800B038C(sample->sampleAddr, sampleRamAddr, sample->size, gSampleBankTable->unkMediumParam);
                    sample->sampleAddr = sampleRamAddr;
                    sample->medium = MEDIUM_RAM;
                } else {
                    func_800B0268(sample->sampleAddr, sampleRamAddr, sample->size, sample->medium);
                    sample->sampleAddr = sampleRamAddr;
                    sample->medium = MEDIUM_RAM;
                }
                break;
            case AUDIOLOAD_ASYNC:
                size = gPreloadSampleStackTop;
                gPreloadSampleStack[size].sample = sample;
                // FAKE
                if (1) {}
                gPreloadSampleStack[size].ramAddr = sampleRamAddr;
                gPreloadSampleStack[size].encodedInfo = (size << 24) | 0xFFFFFF;
                gPreloadSampleStack[size].isFree = 0;
                gPreloadSampleStack[size].endAndMediumKey =
                    (uintptr_t) sample->sampleAddr + sample->size + sample->medium;
                gPreloadSampleStackTop++;
                break;
        }
    }
    gNumUsedSamples = 0;
    if ((gPreloadSampleStackTop != 0) && !inProgress) {
        sample = gPreloadSampleStack[gPreloadSampleStackTop - 1].sample;
        nChunks = (sample->size / 0x1000) + 1;
        func_800B11D8(sample->sampleAddr, gPreloadSampleStack[gPreloadSampleStackTop - 1].ramAddr, sample->size,
                      sample->medium, nChunks, &gPreloadSampleQueue,
                      gPreloadSampleStack[gPreloadSampleStackTop - 1].encodedInfo);
    }
}

bool func_800B1B40(s32 resetStatus) {
    Sample* sample;
    u32 preloadIndex;
    u32 key;
    size_t size;
    s32 nChunks;

    if (gPreloadSampleStackTop > 0) {
        if (resetStatus != 0) {
            MQ_GET_MESG(&gPreloadSampleQueue, &preloadIndex);
            gPreloadSampleStackTop = 0;
            return false;
        }
        if (!MQ_GET_MESG(&gPreloadSampleQueue, &preloadIndex)) {
            return false;
        }
        // "Receive %d\n"
        preloadIndex >>= 0x18;

        if (gPreloadSampleStack[preloadIndex].isFree == 0) {
            sample = gPreloadSampleStack[preloadIndex].sample;
            key = (uintptr_t) sample->sampleAddr + sample->size + sample->medium;
            if (key == gPreloadSampleStack[preloadIndex].endAndMediumKey) {
                sample->sampleAddr = gPreloadSampleStack[preloadIndex].ramAddr;
                sample->medium = MEDIUM_RAM;
            }
            //  "============Error: Magic is Broken after loading.\n"
            gPreloadSampleStack[preloadIndex].isFree = 1;
        }
        while (true) {
            if (gPreloadSampleStackTop <= 0) {
                break;
            }

            if (gPreloadSampleStack[gPreloadSampleStackTop - 1].isFree == 1) {
                gPreloadSampleStackTop--;
                continue;
            }

            sample = gPreloadSampleStack[gPreloadSampleStackTop - 1].sample;
            nChunks = (sample->size >> 0xC) + 1;
            key = (uintptr_t) sample->sampleAddr + sample->size + sample->medium;
            if (key != gPreloadSampleStack[gPreloadSampleStackTop - 1].endAndMediumKey) {
                // "============Error: Magic is Broken: %x\n";
                gPreloadSampleStack[gPreloadSampleStackTop - 1].isFree = 1;
                gPreloadSampleStackTop--;
            } else {
                func_800B11D8(sample->sampleAddr, gPreloadSampleStack[gPreloadSampleStackTop - 1].ramAddr, sample->size,
                              sample->medium, nChunks, &gPreloadSampleQueue,
                              gPreloadSampleStack[gPreloadSampleStackTop - 1].encodedInfo);
                break;
            }
        }
    }
    return true;
}

s32 func_800B1D00(Sample* sample, s32 numSamples, Sample** sampleSet) {
    s32 i;

    for (i = 0; i < numSamples; i++) {
        if (sample->sampleAddr == sampleSet[i]->sampleAddr) {
            break;
        }
    }
    if (i == numSamples) {
        sampleSet[numSamples++] = sample;
    }
    return numSamples;
}

s32 func_800B1D48(s32 fontId, Sample** sampleSet) {
    s32 i;
    Drum* drum;
    Instrument* inst;
    s32 numLoaded;
    s32 numDrums;
    s32 numInstruments;

    numLoaded = 0;
    numDrums = gSoundFontList[fontId].numDrums;
    numInstruments = gSoundFontList[fontId].numInstruments;

    for (i = 0; i < numDrums; i++) {
        drum = func_800AAD58(fontId, i);
        if (drum == NULL) {
            continue;
        }
        numLoaded = func_800B1D00(drum->tunedSample.sample, numLoaded, sampleSet);
    }
    for (i = 0; i < numInstruments; i++) {
        inst = func_800AAD2C(fontId, i);
        if (inst == NULL) {
            continue;
        }
        if (inst->normalRangeLo != 0) {
            numLoaded = func_800B1D00(inst->lowPitchTunedSample.sample, numLoaded, sampleSet);
        }
        if (inst->normalRangeHi != 127) {
            numLoaded = func_800B1D00(inst->highPitchTunedSample.sample, numLoaded, sampleSet);
        }
        numLoaded = func_800B1D00(inst->normalPitchTunedSample.sample, numLoaded, sampleSet);
    }
    return numLoaded;
}

void func_800B1E7C(TunedSample* tunedSample) {
    Sample* sample = tunedSample->sample;

    if ((sample->size != 0) && sample->unk_bit26 && (sample->medium != MEDIUM_RAM)) {
        gUsedSamples[gNumUsedSamples++] = sample;
    }
}

void func_800B1ED4(s32 fontId, s32 async, SampleBankRelocInfo* sampleBankReloc) {
    s32 numDrums;
    s32 numInstruments;
    s32 pad[2]; // For SFX
    Drum* drum;
    Instrument* instrument;
    u8* addr;
    s32 size;
    s32 i;
    Sample* sample;
    s32 preloadInProgress;
    s32 nChunks;

    preloadInProgress = false;
    if (gPreloadSampleStackTop != 0) {
        preloadInProgress = true;
    }

    gNumUsedSamples = 0;

    numDrums = gSoundFontList[fontId].numDrums;
    numInstruments = gSoundFontList[fontId].numInstruments;

    for (i = 0; i < numInstruments; i++) {
        instrument = func_800AAD2C(fontId, i);
        if (instrument != NULL) {
            if (instrument->normalRangeLo != 0) {
                func_800B1E7C(&instrument->lowPitchTunedSample);
            }
            if (instrument->normalRangeHi != 0x7F) {
                func_800B1E7C(&instrument->highPitchTunedSample);
            }
            func_800B1E7C(&instrument->normalPitchTunedSample);
        }
    }

    for (i = 0; i < numDrums; i++) {
        drum = func_800AAD58(fontId, i);
        if (drum != NULL) {
            func_800B1E7C(&drum->tunedSample);
        }
    }

    if (gNumUsedSamples == 0) {
        return;
    }

    size = 0;
    for (i = 0; i < gNumUsedSamples; i++) {
        size += ALIGN16(gUsedSamples[i]->size);
    }

    for (i = 0; i < gNumUsedSamples; i++) {
        if (gPreloadSampleStackTop == 120) {
            break;
        }

        sample = gUsedSamples[i];

        switch (async) {
            case AUDIOLOAD_SYNC:
                if (sample->medium == sampleBankReloc->medium1) {
                    addr =
                        func_800B43A0(sample->size, sampleBankReloc->sampleBankId1, sample->sampleAddr, sample->medium);
                } else if (sample->medium == sampleBankReloc->medium2) {
                    addr =
                        func_800B43A0(sample->size, sampleBankReloc->sampleBankId2, sample->sampleAddr, sample->medium);
                }
                break;

            case AUDIOLOAD_ASYNC:
                if (sample->medium == sampleBankReloc->medium1) {
                    addr =
                        func_800B4350(sample->size, sampleBankReloc->sampleBankId1, sample->sampleAddr, sample->medium);
                } else if (sample->medium == sampleBankReloc->medium2) {
                    addr =
                        func_800B4350(sample->size, sampleBankReloc->sampleBankId2, sample->sampleAddr, sample->medium);
                }
                break;
            default:
                break;
        }
        if (addr == NULL) {
            continue;
        }

        switch (async) {
            case AUDIOLOAD_SYNC:
                if (sample->medium == MEDIUM_UNK) {
                    func_800B038C(sample->sampleAddr, addr, sample->size, gSampleBankTable->unkMediumParam);
                    sample->sampleAddr = addr;
                    sample->medium = MEDIUM_RAM;
                } else {
                    func_800B0268(sample->sampleAddr, addr, sample->size, sample->medium);
                    sample->sampleAddr = addr;
                    sample->medium = MEDIUM_RAM;
                }
                break;

            case AUDIOLOAD_ASYNC:
                gPreloadSampleStack[gPreloadSampleStackTop].sample = sample;
                gPreloadSampleStack[gPreloadSampleStackTop].ramAddr = addr;
                gPreloadSampleStack[gPreloadSampleStackTop].encodedInfo = (gPreloadSampleStackTop << 24) | 0xFFFFFF;
                gPreloadSampleStack[gPreloadSampleStackTop].isFree = false;
                gPreloadSampleStack[gPreloadSampleStackTop].endAndMediumKey =
                    (uintptr_t) sample->sampleAddr + sample->size + sample->medium;
                gPreloadSampleStackTop++;
            default:
                break;
        }
    }
    gNumUsedSamples = 0;

    if (gPreloadSampleStackTop != 0 && !preloadInProgress) {
        sample = gPreloadSampleStack[gPreloadSampleStackTop - 1].sample;
        nChunks = (sample->size >> 12) + 1;
        func_800B11D8(sample->sampleAddr, gPreloadSampleStack[gPreloadSampleStackTop - 1].ramAddr, sample->size,
                      sample->medium, nChunks, &gPreloadSampleQueue,
                      gPreloadSampleStack[gPreloadSampleStackTop - 1].encodedInfo);
    }
}

void func_800B2324(void) {
    s32 pad[2];
    s32 i;
    s32 fontId;
    AudioTable* sampleBankTable;

    sampleBankTable = func_800B0054(SAMPLE_TABLE);
    for (i = 0; i < gPermanentCache.pool.numEntries; i++) {
        SampleBankRelocInfo sampleBankReloc;

        if (gPermanentCache.entries[i].tableType == FONT_TABLE) {
            fontId = func_800AFFC4(FONT_TABLE, gPermanentCache.entries[i].id);

            sampleBankReloc.sampleBankId1 = gSoundFontList[fontId].sampleBankId1;
            sampleBankReloc.sampleBankId1 = func_800AFFC4(SAMPLE_TABLE, sampleBankReloc.sampleBankId1);

            sampleBankReloc.sampleBankId2 = gSoundFontList[fontId].sampleBankId2;
            sampleBankReloc.sampleBankId2 = func_800AFFC4(SAMPLE_TABLE, sampleBankReloc.sampleBankId2);

            sampleBankReloc.medium1 = sampleBankTable->entries[sampleBankReloc.sampleBankId1].medium;
            sampleBankReloc.medium2 = sampleBankTable->entries[sampleBankReloc.sampleBankId2].medium;

            func_800B1ED4(fontId, false, &sampleBankReloc);
        }
    }
}
