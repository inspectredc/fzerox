#include "global.h"
#include "audio.h"

s32 D_807C1890;
s32 D_807C1894[6];
OSMesgQueue sScriptLoadQueue;
OSMesg sScriptLoadMsgBuf[16];
s8* sScriptLoadDonePointers[16];

unk_807C1948 D_807C1948[4];
s32 D_807C1BD8;

DmaHandler sDmaHandler = osEPiStartDma;
LeoHandler sLeoHandler = LeoReadWrite;
s32 D_80771968 = 0;
s32 D_8077196C = 0;
s32 D_80771970 = 0;
s32 D_80771974 = 0;
// LEOBYTE_TBL2
s32 D_80771978[] = { 0x4D08, 0x47B8, 0x4510, 0x3FC0, 0x3A70, 0x3520, 0x2FD0, 0x2A80, 0x2530, 0 };
// LEOVZONE_TBL adjusted for system lbas
s32 D_807719A0[] = { 0x10C, 0x230, 0x342, 0x454, 0x566, 0x678, 0x78A, 0x89C,
                     0x9AE, 0xAD2, 0xBF6, 0xD08, 0xDD4, 0xEA0, 0xFB2, 0x10C4 };
// LEOVZONE_PZONEHD_TBL adjusted to be in range 0 - 7
s32 D_807719E0[] = { 0, 1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 6, 7, 8, 7, 6 };
bool gAudioContextInitialized = false;
UNUSED s32 D_80771A24 = 1;

void AudioLoad_DecreaseSampleDmaTtls(void) {
    u32 i;

    for (i = 0; i < gAudioCtx.sampleDmaListSize1; i++) {
        SampleDma* dma = &gAudioCtx.sampleDmas[i];

        if (dma->ttl != 0) {
            dma->ttl--;
            if (dma->ttl == 0) {
                dma->reuseIndex = gAudioCtx.sampleDmaReuseQueue1WrPos;
                gAudioCtx.sampleDmaReuseQueue1[gAudioCtx.sampleDmaReuseQueue1WrPos] = i;
                gAudioCtx.sampleDmaReuseQueue1WrPos++;
            }
        }
    }

    for (i = gAudioCtx.sampleDmaListSize1; i < gAudioCtx.sampleDmaCount; i++) {
        SampleDma* dma = &gAudioCtx.sampleDmas[i];

        if (dma->ttl != 0) {
            dma->ttl--;
            if (dma->ttl == 0) {
                dma->reuseIndex = gAudioCtx.sampleDmaReuseQueue2WrPos;
                gAudioCtx.sampleDmaReuseQueue2[gAudioCtx.sampleDmaReuseQueue2WrPos] = i;
                gAudioCtx.sampleDmaReuseQueue2WrPos++;
            }
        }
    }

    gAudioCtx.unused1DF8 = 0;
}

void* AudioLoad_DmaSampleData(uintptr_t devAddr, size_t size, s32 arg2, u8* dmaIndexRef, s32 medium) {
    s32 pad1;
    SampleDma* dma;
    s32 hasDma = false;
    u32 dmaDevAddr;
    u32 pad2;
    u32 dmaIndex;
    u32 transfer;
    s32 bufferPos;
    u32 i;

    if (arg2 != 0 || *dmaIndexRef >= gAudioCtx.sampleDmaListSize1) {
        for (i = gAudioCtx.sampleDmaListSize1; i < gAudioCtx.sampleDmaCount; i++) {
            dma = &gAudioCtx.sampleDmas[i];
            bufferPos = devAddr - dma->devAddr;
            if (0 <= bufferPos && bufferPos <= dma->size - size) {
                // We already have a DMA request for this memory range.
                if (dma->ttl == 0 && gAudioCtx.sampleDmaReuseQueue2RdPos != gAudioCtx.sampleDmaReuseQueue2WrPos) {
                    // Move the DMA out of the reuse queue, by swapping it with the
                    // read pos, and then incrementing the read pos.
                    if (dma->reuseIndex != gAudioCtx.sampleDmaReuseQueue2RdPos) {
                        gAudioCtx.sampleDmaReuseQueue2[dma->reuseIndex] =
                            gAudioCtx.sampleDmaReuseQueue2[gAudioCtx.sampleDmaReuseQueue2RdPos];
                        gAudioCtx.sampleDmas[gAudioCtx.sampleDmaReuseQueue2[gAudioCtx.sampleDmaReuseQueue2RdPos]]
                            .reuseIndex = dma->reuseIndex;
                    }
                    gAudioCtx.sampleDmaReuseQueue2RdPos++;
                }
                dma->ttl = 32;
                *dmaIndexRef = i;
                return &dma->ramAddr[devAddr - dma->devAddr];
            }
        }

        if (arg2 == 0) {
            goto search_short_lived;
        }

        if (gAudioCtx.sampleDmaReuseQueue2RdPos != gAudioCtx.sampleDmaReuseQueue2WrPos && arg2 != 0) {
            // Allocate a DMA from reuse queue 2, unless full.
            dmaIndex = gAudioCtx.sampleDmaReuseQueue2[gAudioCtx.sampleDmaReuseQueue2RdPos];
            gAudioCtx.sampleDmaReuseQueue2RdPos++;
            dma = gAudioCtx.sampleDmas + dmaIndex;
            hasDma = true;
        }
    } else {
    search_short_lived:
        dma = gAudioCtx.sampleDmas + *dmaIndexRef;
        i = 0;
    again:
        bufferPos = devAddr - dma->devAddr;
        if (0 <= bufferPos && bufferPos <= dma->size - size) {
            // We already have DMA for this memory range.
            if (dma->ttl == 0) {
                // Move the DMA out of the reuse queue, by swapping it with the
                // read pos, and then incrementing the read pos.
                if (dma->reuseIndex != gAudioCtx.sampleDmaReuseQueue1RdPos) {
                    gAudioCtx.sampleDmaReuseQueue1[dma->reuseIndex] =
                        gAudioCtx.sampleDmaReuseQueue1[gAudioCtx.sampleDmaReuseQueue1RdPos];
                    gAudioCtx.sampleDmas[gAudioCtx.sampleDmaReuseQueue1[gAudioCtx.sampleDmaReuseQueue1RdPos]]
                        .reuseIndex = dma->reuseIndex;
                }
                gAudioCtx.sampleDmaReuseQueue1RdPos++;
            }
            dma->ttl = 2;
            return dma->ramAddr + (devAddr - dma->devAddr);
        }
        dma = gAudioCtx.sampleDmas + i++;
        if (i <= gAudioCtx.sampleDmaListSize1) {
            goto again;
        }
    }

    if (!hasDma) {
        if (gAudioCtx.sampleDmaReuseQueue1RdPos == gAudioCtx.sampleDmaReuseQueue1WrPos) {
            return NULL;
        }
        // Allocate a DMA from reuse queue 1.
        dmaIndex = gAudioCtx.sampleDmaReuseQueue1[gAudioCtx.sampleDmaReuseQueue1RdPos++];
        dma = gAudioCtx.sampleDmas + dmaIndex;
        hasDma = true;
    }

    transfer = dma->size;
    dmaDevAddr = devAddr & ~0xF;
    dma->ttl = 3;
    dma->devAddr = dmaDevAddr;
    dma->sizeUnused = transfer;
    AudioLoad_Dma(&gAudioCtx.curAudioFrameDmaIoMsgBuf[gAudioCtx.curAudioFrameDmaCount++], OS_MESG_PRI_NORMAL, OS_READ,
                  dmaDevAddr, dma->ramAddr, transfer, &gAudioCtx.curAudioFrameDmaQueue, medium, "SUPERDMA");
    *dmaIndexRef = dmaIndex;
    return (devAddr - dmaDevAddr) + dma->ramAddr;
}

void AudioLoad_InitSampleDmaBuffers(s32 numNotes) {
    SampleDma* dma;
    s32 i;
    s32 temp_lo;
    s32 j;

    gAudioCtx.sampleDmaBufSize = gAudioCtx.sampleDmaBufSize1;
    gAudioCtx.sampleDmas = AudioHeap_Alloc(&gAudioCtx.miscPool, 4 * gAudioCtx.numNotes * sizeof(SampleDma) *
                                                                    gAudioCtx.audioBufferParameters.specUnk4);
    temp_lo = 3 * gAudioCtx.numNotes * gAudioCtx.audioBufferParameters.specUnk4;
    for (i = 0; i < temp_lo; i++) {
        dma = &gAudioCtx.sampleDmas[gAudioCtx.sampleDmaCount];
        dma->ramAddr = AudioHeap_AllocAttemptExternal(&gAudioCtx.miscPool, gAudioCtx.sampleDmaBufSize);
        if (dma->ramAddr == NULL) {
            break;
        } else {
            AudioHeap_WritebackDCache(dma->ramAddr, gAudioCtx.sampleDmaBufSize);
            dma->size = gAudioCtx.sampleDmaBufSize;
            dma->devAddr = 0;
            dma->sizeUnused = 0;
            dma->unused = 0;
            dma->ttl = 0;
            gAudioCtx.sampleDmaCount++;
        }
    }

    for (i = 0; i < gAudioCtx.sampleDmaCount; i++) {
        gAudioCtx.sampleDmaReuseQueue1[i] = i;
        gAudioCtx.sampleDmas[i].reuseIndex = i;
    }

    for (i = gAudioCtx.sampleDmaCount; i < 0x100; i++) {
        gAudioCtx.sampleDmaReuseQueue1[i] = 0;
    }

    gAudioCtx.sampleDmaReuseQueue1RdPos = 0;
    gAudioCtx.sampleDmaReuseQueue1WrPos = gAudioCtx.sampleDmaCount;
    gAudioCtx.sampleDmaListSize1 = gAudioCtx.sampleDmaCount;
    gAudioCtx.sampleDmaBufSize = gAudioCtx.sampleDmaBufSize2;

    for (j = 0; j < gAudioCtx.numNotes; j++) {
        dma = &gAudioCtx.sampleDmas[gAudioCtx.sampleDmaCount];
        dma->ramAddr = AudioHeap_AllocAttemptExternal(&gAudioCtx.miscPool, gAudioCtx.sampleDmaBufSize);
        if (dma->ramAddr == NULL) {
            break;
        } else {
            AudioHeap_WritebackDCache(dma->ramAddr, gAudioCtx.sampleDmaBufSize);
            dma->size = gAudioCtx.sampleDmaBufSize;
            dma->devAddr = 0;
            dma->sizeUnused = 0;
            dma->unused = 0;
            dma->ttl = 0;
            gAudioCtx.sampleDmaCount++;
        }
    }

    for (i = gAudioCtx.sampleDmaListSize1; i < gAudioCtx.sampleDmaCount; i++) {
        gAudioCtx.sampleDmaReuseQueue2[i - gAudioCtx.sampleDmaListSize1] = i;
        gAudioCtx.sampleDmas[i].reuseIndex = i - gAudioCtx.sampleDmaListSize1;
    }

    for (i = gAudioCtx.sampleDmaCount; i < 0x100; i++) {
        gAudioCtx.sampleDmaReuseQueue2[i] = gAudioCtx.sampleDmaListSize1;
    }

    gAudioCtx.sampleDmaReuseQueue2RdPos = 0;
    gAudioCtx.sampleDmaReuseQueue2WrPos = gAudioCtx.sampleDmaCount - gAudioCtx.sampleDmaListSize1;
}

bool AudioLoad_IsFontLoadComplete(s32 fontId) {
    if (fontId == 0xFF) {
        return true;
    } else if (gAudioCtx.fontLoadStatus[fontId] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else if (gAudioCtx.fontLoadStatus[AudioLoad_GetLoadTableIndex(FONT_TABLE, fontId)] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else {
        return false;
    }
}

bool AudioLoad_IsSeqLoadComplete(s32 seqId) {
    if (seqId == 0xFF) {
        return true;
    } else if (gAudioCtx.seqLoadStatus[seqId] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else if (gAudioCtx.seqLoadStatus[AudioLoad_GetLoadTableIndex(SEQUENCE_TABLE, seqId)] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else {
        return false;
    }
}

bool AudioLoad_IsSampleLoadComplete(s32 sampleBankId) {
    if (sampleBankId == 0xFF) {
        return true;
    } else if (gAudioCtx.sampleFontLoadStatus[sampleBankId] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else if (gAudioCtx.sampleFontLoadStatus[AudioLoad_GetLoadTableIndex(SAMPLE_TABLE, sampleBankId)] >=
               LOAD_STATUS_COMPLETE) {
        return true;
    } else {
        return false;
    }
}

void AudioLoad_SetFontLoadStatus(s32 fontId, s32 loadStatus) {
    if ((fontId != 0xFF) && (gAudioCtx.fontLoadStatus[fontId] != LOAD_STATUS_PERMANENTLY_LOADED)) {
        gAudioCtx.fontLoadStatus[fontId] = loadStatus;
    }
}

void AudioLoad_SetSeqLoadStatus(s32 seqId, s32 loadStatus) {
    if ((seqId != 0xFF) && (gAudioCtx.seqLoadStatus[seqId] != LOAD_STATUS_PERMANENTLY_LOADED)) {
        gAudioCtx.seqLoadStatus[seqId] = loadStatus;
    }
}

void AudioLoad_SetSampleFontLoadStatusAndApplyCaches(s32 sampleBankId, s32 loadStatus) {
    if (sampleBankId != 0xFF) {
        if (gAudioCtx.sampleFontLoadStatus[sampleBankId] != LOAD_STATUS_PERMANENTLY_LOADED) {
            gAudioCtx.sampleFontLoadStatus[sampleBankId] = loadStatus;
        }

        if ((gAudioCtx.sampleFontLoadStatus[sampleBankId] == LOAD_STATUS_PERMANENTLY_LOADED) ||
            (gAudioCtx.sampleFontLoadStatus[sampleBankId] == LOAD_STATUS_COMPLETE)) {
            AudioHeap_ApplySampleBankCache(sampleBankId);
        }
    }
}

void AudioLoad_SetSampleFontLoadStatus(s32 sampleBankId, s32 loadStatus) {
    if ((sampleBankId != 0xFF) && (gAudioCtx.sampleFontLoadStatus[sampleBankId] != LOAD_STATUS_PERMANENTLY_LOADED)) {
        gAudioCtx.sampleFontLoadStatus[sampleBankId] = loadStatus;
    }
}

void AudioLoad_InitTable(AudioTable* table, uintptr_t romAddr, u16 lba) {
    s32 i;

    table->header.diskLba = lba;
    table->header.romAddr = romAddr;

    for (i = 0; i < table->header.numEntries; i++) {
        if ((table->entries[i].size != 0) && (table->entries[i].medium == MEDIUM_CART)) {
            table->entries[i].romAddr += romAddr;
        }
    }
}

void* AudioLoad_SyncLoadSeqFonts(s32 seqId, u32* outDefaultFontId) {
    s32 pad[2];
    s32 index;
    void* fontData;
    s32 numFonts;
    s32 fontId;
    s32 i;

    fontId = 0xFF;
    index = ((u16*) gAudioCtx.sequenceFontTable)[seqId];
    numFonts = gAudioCtx.sequenceFontTable[index++];

    while (numFonts > 0) {
        fontId = gAudioCtx.sequenceFontTable[index++];
        fontData = AudioLoad_SyncLoadFont(fontId);
        numFonts--;
    }

    *outDefaultFontId = fontId;
    return fontData;
}

void AudioLoad_SyncLoadSeqParts(s32 seqId, s32 flags) {
    s32 pad;
    u32 defaultFontId;

    if (flags & 2) {
        AudioLoad_SyncLoadSeqFonts(seqId, &defaultFontId);
    }
    if (flags & 1) {
        AudioLoad_SyncLoadSeq(seqId);
    }
}

s32 AudioLoad_SyncLoadSample(Sample* sample, s32 fontId) {
    u8* sampleAddr;

    if ((sample->isRelocated == 1) && (sample->medium != 0)) {
        sampleAddr = AudioHeap_AllocSampleCache(sample->size, fontId, sample->sampleAddr, sample->medium, 1);
        if (sampleAddr == NULL) {
            return -1;
        }
        if (sample->medium == MEDIUM_LBA) {
            AudioLoad_SyncDiskDrive(sample->sampleAddr, sampleAddr, sample->size,
                                    gAudioCtx.sampleBankTable->header.diskLba);
        } else {
            AudioLoad_SyncDma(sample->sampleAddr, sampleAddr, sample->size, sample->medium);
        }
        sample->medium = MEDIUM_RAM;
        sample->sampleAddr = sampleAddr;
    }
    //! @bug Missing return.
}

s32 AudioLoad_SyncLoadInstrument(s32 fontId, s32 instId, s32 drumId) {
    Instrument* instrument;
    Drum* drum;

    if (instId < 0x7F) {
        instrument = Audio_GetInstrument(fontId, instId);
        if (instrument == NULL) {
            return -1;
        }
        if (instrument->normalRangeLo != 0) {
            AudioLoad_SyncLoadSample(instrument->lowPitchTunedSample.sample, fontId);
        }
        AudioLoad_SyncLoadSample(instrument->normalPitchTunedSample.sample, fontId);
        if (instrument->normalRangeHi != 0x7F) {
            AudioLoad_SyncLoadSample(instrument->highPitchTunedSample.sample, fontId);
        }
    } else if (instId == 0x7F) {
        drum = Audio_GetDrum(fontId, drumId);
        if (drum == NULL) {
            return -1;
        }
        AudioLoad_SyncLoadSample(drum->tunedSample.sample, fontId);
        return 0;
    }
    //! @bug Missing return.
}

void AudioLoad_AsyncLoad(s32 tableType, s32 id, s32 nChunks, s32 retData, OSMesgQueue* retQueue) {
    if (AudioLoad_AsyncLoadInner(tableType, id, nChunks, retData, retQueue) == NULL) {
        osSendMesg(retQueue, (OSMesg) -1, OS_MESG_NOBLOCK);
    }
}

void AudioLoad_AsyncLoadSeq(s32 seqId, s32 arg1, s32 retData, OSMesgQueue* retQueue) {
    AudioLoad_AsyncLoad(SEQUENCE_TABLE, seqId, 0, retData, retQueue);
}

void AudioLoad_AsyncLoadSampleBank(s32 sampleBankId, s32 arg1, s32 retData, OSMesgQueue* retQueue) {
    AudioLoad_AsyncLoad(SAMPLE_TABLE, sampleBankId, 0, retData, retQueue);
}

void AudioLoad_AsyncLoadFont(s32 fontId, s32 arg1, s32 retData, OSMesgQueue* retQueue) {
    AudioLoad_AsyncLoad(FONT_TABLE, fontId, 0, retData, retQueue);
}

u8* AudioLoad_GetFontsForSequence(s32 seqId, u32* outNumFonts) {
    s32 index = ((u16*) gAudioCtx.sequenceFontTable)[seqId];

    *outNumFonts = gAudioCtx.sequenceFontTable[index++];
    if (*outNumFonts == 0) {
        return NULL;
    }
    return &gAudioCtx.sequenceFontTable[index];
}

void AudioLoad_DiscardSeqFonts(s32 seqId) {
    s32 fontId;
    s32 index = ((u16*) gAudioCtx.sequenceFontTable)[seqId];
    s32 numFonts = gAudioCtx.sequenceFontTable[index++];

    while (numFonts > 0) {
        numFonts--;
        fontId = AudioLoad_GetLoadTableIndex(FONT_TABLE, gAudioCtx.sequenceFontTable[index++]);
        if (AudioHeap_SearchPermanentCache(FONT_TABLE, fontId) == NULL) {
            AudioLoad_DiscardFont(fontId);
            AudioLoad_SetFontLoadStatus(fontId, LOAD_STATUS_NOT_LOADED);
        }
    }
}

void AudioLoad_DiscardFont(s32 fontId) {
    AudioCache* cache = &gAudioCtx.fontCache;
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
    AudioHeap_DiscardFont(fontId);
}

s32 AudioLoad_SyncInitSeqPlayer(s32 playerIdx, s32 seqId, s32 arg2) {
    if (gAudioCtx.resetTimer != 0) {
        return 0;
    }

    gAudioCtx.seqPlayers[playerIdx].skipTicks = 0;
    AudioLoad_SyncInitSeqPlayerInternal(playerIdx, seqId, arg2);
    //! @bug Missing return.
}

s32 AudioLoad_SyncInitSeqPlayerSkipTicks(s32 playerIdx, s32 seqId, s32 skipTicks) {
    if (gAudioCtx.resetTimer != 0) {
        return 0;
    }

    gAudioCtx.seqPlayers[playerIdx].skipTicks = skipTicks;
    AudioLoad_SyncInitSeqPlayerInternal(playerIdx, seqId, 0);
    //! @bug Missing return.
}

s32 AudioLoad_SyncInitSeqPlayerInternal(s32 playerIdx, s32 seqId, s32 arg2) {
    SequencePlayer* seqPlayer = &gAudioCtx.seqPlayers[playerIdx];
    u8* seqData;
    s32 index;
    s32 numFonts;
    s32 fontId;

    AudioSeq_SequencePlayerDisable(seqPlayer);

    fontId = 0xFF;
    index = ((u16*) gAudioCtx.sequenceFontTable)[seqId];
    numFonts = gAudioCtx.sequenceFontTable[index++];

    while (numFonts > 0) {
        fontId = gAudioCtx.sequenceFontTable[index++];
        AudioLoad_SyncLoadFont(fontId);
        numFonts--;
    }

    seqData = AudioLoad_SyncLoadSeq(seqId);
    if (seqData == NULL) {
        return 0;
    }

    AudioSeq_ResetSequencePlayer(seqPlayer);
    seqPlayer->seqId = seqId;
    seqPlayer->defaultFont = AudioLoad_GetLoadTableIndex(FONT_TABLE, fontId);
    seqPlayer->seqData = seqData;
    seqPlayer->enabled = true;
    seqPlayer->scriptState.pc = seqData;
    seqPlayer->scriptState.depth = 0;
    seqPlayer->delay = 0;
    seqPlayer->finished = false;
    seqPlayer->playerIdx = playerIdx;
    AudioSeq_SkipForwardSequence(seqPlayer);
    //! @bug Missing return.
}

void* AudioLoad_SyncLoadSeq(s32 seqId) {
    s32 pad;
    bool didAllocate;

    if (gAudioCtx.seqLoadStatus[AudioLoad_GetLoadTableIndex(SEQUENCE_TABLE, seqId)] == LOAD_STATUS_IN_PROGRESS) {
        return NULL;
    }

    return AudioLoad_SyncLoad(SEQUENCE_TABLE, seqId, &didAllocate);
}

void* AudioLoad_GetSampleBank(u32 sampleBankId, u32* outMedium) {
    return AudioLoad_TrySyncLoadSampleBank(sampleBankId, outMedium, true);
}

void* AudioLoad_TrySyncLoadSampleBank(u32 sampleBankId, u32* outMedium, bool noLoad) {
    void* ramAddr;
    AudioTable* sampleBankTable;
    u32 realTableId = AudioLoad_GetLoadTableIndex(SAMPLE_TABLE, sampleBankId);
    s8 cachePolicy;

    sampleBankTable = AudioLoad_GetLoadTable(SAMPLE_TABLE);
    ramAddr = AudioLoad_SearchCaches(SAMPLE_TABLE, realTableId);
    if (ramAddr != NULL) {
        if (gAudioCtx.sampleFontLoadStatus[realTableId] != LOAD_STATUS_IN_PROGRESS) {
            AudioLoad_SetSampleFontLoadStatus(realTableId, LOAD_STATUS_COMPLETE);
        }
        *outMedium = MEDIUM_RAM;
        return ramAddr;
    }

    cachePolicy = sampleBankTable->entries[sampleBankId].cachePolicy;
    if (cachePolicy == 4 || noLoad == true) {
        *outMedium = sampleBankTable->entries[sampleBankId].medium;
        return sampleBankTable->entries[realTableId].romAddr;
    }

    ramAddr = AudioLoad_SyncLoad(SAMPLE_TABLE, sampleBankId, &noLoad);
    if (ramAddr != NULL) {
        *outMedium = MEDIUM_RAM;
        return ramAddr;
    }

    *outMedium = sampleBankTable->entries[sampleBankId].medium;
    return sampleBankTable->entries[realTableId].romAddr;
}

void* AudioLoad_SyncLoadFont(s32 fontId) {
    void* fontData;
    s32 sampleBankId1;
    s32 sampleBankId2;
    bool didAllocate;
    SampleBankRelocInfo sampleBankReloc;
    s32 realFontId = AudioLoad_GetLoadTableIndex(FONT_TABLE, fontId);

    if (gAudioCtx.fontLoadStatus[realFontId] == LOAD_STATUS_IN_PROGRESS) {
        return NULL;
    }
    sampleBankId1 = gAudioCtx.soundFontList[realFontId].sampleBankId1;
    sampleBankId2 = gAudioCtx.soundFontList[realFontId].sampleBankId2;

    sampleBankReloc.sampleBankId1 = sampleBankId1;
    sampleBankReloc.sampleBankId2 = sampleBankId2;
    if (sampleBankId1 != 0xFF) {
        sampleBankReloc.baseAddr1 = AudioLoad_TrySyncLoadSampleBank(sampleBankId1, &sampleBankReloc.medium1, false);
    } else {
        sampleBankReloc.baseAddr1 = 0;
    }

    if (sampleBankId2 != 0xFF) {
        sampleBankReloc.baseAddr2 = AudioLoad_TrySyncLoadSampleBank(sampleBankId2, &sampleBankReloc.medium2, false);
    } else {
        sampleBankReloc.baseAddr2 = 0;
    }

    fontData = AudioLoad_SyncLoad(FONT_TABLE, fontId, &didAllocate);
    if (fontData == NULL) {
        return NULL;
    }
    if (didAllocate == true) {
        AudioLoad_RelocateFontAndPreloadSamples(realFontId, fontData, &sampleBankReloc, AUDIOLOAD_SYNC);
    }

    return fontData;
}

void* AudioLoad_SyncLoad(u32 tableType, u32 id, bool* didAllocate) {
    size_t size;
    AudioTable* table;
    s32 pad;
    u32 medium;
    s32 loadStatus;
    uintptr_t romAddr;
    s32 cachePolicy;
    void* ramAddr;
    u32 realId;

    realId = AudioLoad_GetLoadTableIndex(tableType, id);
    ramAddr = AudioLoad_SearchCaches(tableType, realId);
    if (ramAddr != NULL) {
        *didAllocate = false;
        loadStatus = LOAD_STATUS_COMPLETE;
    } else {
        table = AudioLoad_GetLoadTable(tableType);
        size = table->entries[realId].size;
        size = ALIGN16(size);
        medium = table->entries[id].medium;
        cachePolicy = table->entries[id].cachePolicy;
        romAddr = table->entries[realId].romAddr;
        switch (cachePolicy) {
            case 0:
                ramAddr = AudioHeap_AllocPermanent(tableType, realId, size);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;

            case 1:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_PERSISTENT, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;

            case 2:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_TEMPORARY, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;

            case 3:
            case 4:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_EITHER, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
        }

        *didAllocate = true;
        if (medium == MEDIUM_LBA) {
            AudioLoad_SyncDiskDrive(romAddr, ramAddr, size, (s16) table->header.diskLba);
        } else {
            AudioLoad_SyncDma(romAddr, ramAddr, size, medium);
        }

        loadStatus = (cachePolicy == 0) ? LOAD_STATUS_PERMANENTLY_LOADED : LOAD_STATUS_COMPLETE;
    }

    switch (tableType) {
        case SEQUENCE_TABLE:
            AudioLoad_SetSeqLoadStatus(realId, loadStatus);
            break;

        case FONT_TABLE:
            AudioLoad_SetFontLoadStatus(realId, loadStatus);
            break;

        case SAMPLE_TABLE:
            AudioLoad_SetSampleFontLoadStatusAndApplyCaches(realId, loadStatus);
            break;

        default:
            break;
    }

    return ramAddr;
}

s32 AudioLoad_GetLoadTableIndex(s32 tableType, u32 entryId) {
    AudioTable* table = AudioLoad_GetLoadTable(tableType);

    if (table->entries[entryId].size == 0) {
        entryId = table->entries[entryId].romAddr;
    }
    return entryId;
}

void* AudioLoad_SearchCaches(s32 tableType, u32 id) {
    void* ramAddr;

    ramAddr = AudioHeap_SearchPermanentCache(tableType, id);
    if (ramAddr != NULL) {
        return ramAddr;
    }
    ramAddr = AudioHeap_SearchCaches(tableType, CACHE_EITHER, id);
    if (ramAddr != NULL) {
        return ramAddr;
    }
    return NULL;
}

AudioTable* AudioLoad_GetLoadTable(s32 tableType) {
    AudioTable* table;

    switch (tableType) {
        case SEQUENCE_TABLE:
            table = gAudioCtx.sequenceTable;
            break;
        case FONT_TABLE:
            table = gAudioCtx.soundFontTable;
            break;
        case SAMPLE_TABLE:
            table = gAudioCtx.sampleBankTable;
            break;
        default:
            table = NULL;
            break;
    }
    return table;
}

void AudioLoad_RelocateFont(s32 fontId, uintptr_t fontBaseAddr, SampleBankRelocInfo* relocData) {
    uintptr_t* fontDataPtrs = fontBaseAddr;
    Drum*** drumDataPtrs = fontBaseAddr;
    Drum* drum;
    Instrument* instrument;
    SoundEffect* soundEffect;
    uintptr_t offset;
    s32 numDrums = gAudioCtx.soundFontList[fontId].numDrums;
    s32 numInstruments = gAudioCtx.soundFontList[fontId].numInstruments;
    s32 numSfx = gAudioCtx.soundFontList[fontId].numSfx;
    s32 i;

    if ((fontDataPtrs[0] != 0) && (numDrums != 0)) {
        fontDataPtrs[0] += fontBaseAddr;

        for (i = 0; i < numDrums; i++) {
            offset = (*drumDataPtrs)[i];
            if (offset == 0) {
                continue;
            }
            drum = offset += fontBaseAddr;
            (*drumDataPtrs)[i] = drum;
            if (drum->isRelocated) {
                continue;
            }
            AudioLoad_RelocateSample(&drum->tunedSample, fontBaseAddr, relocData);
            offset = (uintptr_t) drum->envelope;
            drum->envelope = (EnvelopePoint*) (offset + fontBaseAddr);
            drum->isRelocated = true;
        }
    }

    if ((fontDataPtrs[1] != 0) && (numSfx != 0)) {

        fontDataPtrs[1] += fontBaseAddr;

        for (i = 0; i < numSfx; i++) {
            offset = (uintptr_t) (((SoundEffect*) fontDataPtrs[1]) + i);
            soundEffect = (SoundEffect*) offset;

            if ((soundEffect == NULL) || (soundEffect->tunedSample.sample == 0)) {
                continue;
            }

            AudioLoad_RelocateSample(&soundEffect->tunedSample, fontBaseAddr, relocData);
        }
    }

    if (numInstruments > 126) {
        numInstruments = 126;
    }

    for (i = 2; i <= numInstruments + 2 - 1; i++) {
        if (fontDataPtrs[i] != 0) {

            fontDataPtrs[i] += fontBaseAddr;

            instrument = fontDataPtrs[i];
            if (instrument->isRelocated == 0) {
                if (instrument->normalRangeLo != 0) {
                    AudioLoad_RelocateSample(&instrument->lowPitchTunedSample, fontBaseAddr, relocData);
                }
                AudioLoad_RelocateSample(&instrument->normalPitchTunedSample, fontBaseAddr, relocData);
                if (instrument->normalRangeHi != 0x7F) {
                    AudioLoad_RelocateSample(&instrument->highPitchTunedSample, fontBaseAddr, relocData);
                }
                offset = (uintptr_t) instrument->envelope;
                instrument->envelope = (EnvelopePoint*) (offset + fontBaseAddr);
                instrument->isRelocated = true;
            }
        }
    }
    gAudioCtx.soundFontList[fontId].drums = fontDataPtrs[0];
    gAudioCtx.soundFontList[fontId].soundEffects = (SoundEffect*) fontDataPtrs[1];
    gAudioCtx.soundFontList[fontId].instruments = (Instrument**) &fontDataPtrs[2];
}

void AudioLoad_SyncDma(uintptr_t devAddr, u8* ramAddr, size_t size, s32 medium) {

    size = ALIGN16(size);
    Audio_InvalDCache(ramAddr, size);
    while (true) {
        if (size < 0x400) {
            break;
        }
        AudioLoad_Dma(&gAudioCtx.syncDmaIoMesg, OS_MESG_PRI_HIGH, OS_READ, devAddr, ramAddr, 0x400,
                      &gAudioCtx.syncDmaQueue, medium, "FastCopy");
        osRecvMesg(&gAudioCtx.syncDmaQueue, NULL, OS_MESG_BLOCK);
        size -= 0x400;
        devAddr += 0x400;
        ramAddr += 0x400;
    }
    if (size != 0) {
        AudioLoad_Dma(&gAudioCtx.syncDmaIoMesg, OS_MESG_PRI_HIGH, OS_READ, devAddr, ramAddr, size,
                      &gAudioCtx.syncDmaQueue, medium, "FastCopy");
        osRecvMesg(&gAudioCtx.syncDmaQueue, NULL, OS_MESG_BLOCK);
    }
    PRINTF("Convert to %d %d\n");
}

void AudioLoad_SyncDiskDrive(uintptr_t devAddr, u8* ramAddr, size_t size, s32 lba) {
    uintptr_t adjustedDevAddr = devAddr;
    s32 pad;

    Audio_InvalDCache(ramAddr, size);
    AudioLoad_DiskDrive(AudioLoad_GetStartLbaAddr(lba, &adjustedDevAddr), adjustedDevAddr, ramAddr, size);
}

s32 AudioLoad_Dma(OSIoMesg* mesg, u32 priority, s32 direction, uintptr_t devAddr, void* ramAddr, size_t size,
                  OSMesgQueue* reqQueue, s32 medium, const char* dmaFuncType) {
    OSPiHandle* handle;

    if (gAudioCtx.resetTimer > 16) {
        return -1;
    }

    switch (medium) {
        case MEDIUM_CART:
            handle = gAudioCtx.cartHandle;
            break;

        case MEDIUM_DISK_DRIVE:
            handle = gAudioCtx.driveHandle;
            break;

        default:
            return 0;
    }

    if ((size % 0x10) != 0) {
        size = ALIGN16(size);
    }

    mesg->hdr.pri = priority;
    mesg->hdr.retQueue = reqQueue;
    mesg->dramAddr = ramAddr;
    mesg->devAddr = devAddr;
    mesg->size = size;
    handle->transferInfo.cmdType = 2;
    sDmaHandler(handle, mesg, direction);

    D_80771968++;
    D_8077196C = devAddr;
    D_80771970 = size;
    D_80771974 = medium;

    return 0;
}

s32 AudioLoad_LbaToBlockSize(s32 lba) {
    s32 i;
    s32 j = 0;

    for (i = 0; i < 15; i++, j++) {
        if (lba < D_807719A0[i]) {
            break;
        }
    }

    if (i == 15) {
        return 0;
    }

    j = D_807719E0[j];
    return D_80771978[j];
}

s32 AudioLoad_GetLbaAddrInfo(s32* lbaPtr, uintptr_t* devAddrPtr) {
    s32 blockSize;
    s32 lba;
    intptr_t devAddr;

    lba = *lbaPtr;
    devAddr = *devAddrPtr;

    while (true) {
        blockSize = AudioLoad_LbaToBlockSize(lba);
        if (blockSize == 0) {
            return -1;
        }
        if (devAddr < blockSize) {
            break;
        }
        devAddr -= blockSize;
        lba++;
    }
    *lbaPtr = lba;
    *devAddrPtr = devAddr;
    return 0;
}

s32 AudioLoad_GetStartLbaAddr(s32 lba, uintptr_t* devAddrPtr) {
    if (AudioLoad_GetLbaAddrInfo(&lba, devAddrPtr) == -1) {
        rmonPrintf("LBA ERROR! \n");
        while (true) {}
    }
    return lba;
}

void AudioLoad_SyncLoadSimple(u32 tableType, u32 fontId) {
    bool didAllocate;

    AudioLoad_SyncLoad(tableType, fontId, &didAllocate);
}

void* AudioLoad_AsyncLoadInner(s32 tableType, s32 id, s32 nChunks, s32 retData, OSMesgQueue* retQueue) {
    size_t size;
    AudioTable* table;
    void* ramAddr;
    s32 medium;
    s8 cachePolicy;
    uintptr_t devAddr;
    s32 loadStatus;
    s32 pad;
    u32 realId = AudioLoad_GetLoadTableIndex(tableType, id);

    switch (tableType) {
        case SEQUENCE_TABLE:
            if (gAudioCtx.seqLoadStatus[realId] == LOAD_STATUS_IN_PROGRESS) {
                return NULL;
            }
            break;

        case FONT_TABLE:
            if (gAudioCtx.fontLoadStatus[realId] == LOAD_STATUS_IN_PROGRESS) {
                return NULL;
            }
            break;

        case SAMPLE_TABLE:
            if (gAudioCtx.sampleFontLoadStatus[realId] == LOAD_STATUS_IN_PROGRESS) {
                return NULL;
            }
            break;
    }

    ramAddr = AudioLoad_SearchCaches(tableType, realId);
    if (ramAddr != NULL) {
        loadStatus = LOAD_STATUS_COMPLETE;
        osSendMesg(retQueue, (OSMesg) (retData << 0x18), OS_MESG_NOBLOCK);
    } else {
        table = AudioLoad_GetLoadTable(tableType);
        size = table->entries[realId].size;
        size = ALIGN16(size);
        medium = table->entries[id].medium;
        cachePolicy = table->entries[id].cachePolicy;
        devAddr = table->entries[realId].romAddr;
        loadStatus = LOAD_STATUS_COMPLETE;

        switch (cachePolicy) {
            case 0:
                ramAddr = AudioHeap_AllocPermanent(tableType, realId, size);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                loadStatus = LOAD_STATUS_PERMANENTLY_LOADED;
                break;

            case 1:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_PERSISTENT, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;

            case 2:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_TEMPORARY, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;

            case 3:
            case 4:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_EITHER, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
        }

        if (medium == MEDIUM_LBA) {
            AudioLoad_StartAsyncLoadDiskDrive(table->header.diskLba, devAddr, ramAddr, size, medium, nChunks, retQueue,
                                              (retData << 0x18) | (tableType << 0x10) | (id << 8) | loadStatus);
        } else {
            AudioLoad_StartAsyncLoad(devAddr, ramAddr, size, medium, nChunks, retQueue,
                                     (retData << 0x18) | (tableType << 0x10) | (realId << 8) | loadStatus);
        }
        loadStatus = LOAD_STATUS_IN_PROGRESS;
    }

    switch (tableType) {
        case SEQUENCE_TABLE:
            AudioLoad_SetSeqLoadStatus(realId, loadStatus);
            break;

        case FONT_TABLE:
            AudioLoad_SetFontLoadStatus(realId, loadStatus);
            break;

        case SAMPLE_TABLE:
            AudioLoad_SetSampleFontLoadStatusAndApplyCaches(realId, loadStatus);
            break;

        default:
            break;
    }

    return ramAddr;
}

void AudioLoad_ProcessLoads(s32 resetStatus) {
    AudioLoad_ProcessSlowLoads(resetStatus);
    AudioLoad_ProcessSamplePreloads(resetStatus);
    AudioLoad_ProcessAsyncLoads(resetStatus);
}

s32 AudioLoad_ReadWriteDisk(LEOCmd* cmdBlock, s32 direction, u32 lba, void* ptr, u32 nLbas, OSMesgQueue* mq,
                            bool usingLbaVaddrPair) {
    void* vAddr;
    LbaVaddrPair* lbaVaddrPair;

    if (usingLbaVaddrPair) {
        lbaVaddrPair = ptr;
        vAddr = lbaVaddrPair->vAddr;
        if ((lba == lbaVaddrPair->lba) && (nLbas == 1)) {
            osSendMesg(mq, NULL, 0);
            return 0;
        }
    } else {
        vAddr = ptr;
    }

    sLeoHandler(cmdBlock, direction, lba, vAddr, nLbas, mq);
    if ((nLbas == 1) && usingLbaVaddrPair) {
        lbaVaddrPair->lba = lba;
    }
    return 0;
}

void AudioLoad_SetDmaHandler(DmaHandler callback) {
    sDmaHandler = callback;
}

void AudioLoad_SetLeoHandler(LeoHandler callback) {
    sLeoHandler = callback;
}

void AudioLoad_InitSoundFont(s32 fontId) {
    SoundFont* font = &gAudioCtx.soundFontList[fontId];
    AudioTableEntry* entry = &gAudioCtx.soundFontTable->entries[fontId];

    font->sampleBankId1 = (entry->shortData1 >> 8) & 0xFF;
    font->sampleBankId2 = (entry->shortData1) & 0xFF;
    font->numInstruments = (entry->shortData2 >> 8) & 0xFF;
    font->numDrums = entry->shortData2 & 0xFF;
    font->numSfx = entry->shortData3;
}

extern s32 gAudioSequenceRomStart;
extern s32 gAudioBankRomStart;
extern s32 gAudioTableRomStart;

extern s32 gSoundFontTableLba;
extern s32 gSequenceTableLba;
extern s32 gSampleBankTableLba;

extern LbaVaddrPair D_806F2348;

extern OSMesgQueue D_806F2328;
extern OSMesg D_806F2340[1];

extern AudioCustomUpdateFunction gAudioCustomUpdateFunction;

extern bool gAudioContextInitialized;

extern AudioTable gSequenceTable;
extern AudioTable gSoundFontTable;
extern AudioTable gSampleBankTable;
extern u8 gSequenceFontTable[];

void AudioLoad_Init(void* heap, size_t heapSize) {
    s32 pad[18];
    s32 numFonts;
    void* ramAddr;
    s32 i;

    gAudioCustomUpdateFunction = NULL;
    gAudioCtx.resetTimer = 0;
    gAudioCtx.unk_215C = 0;

    {
        s32 i;
        u8* audioContextPtr = (u8*) &gAudioCtx;

        //! @bug This clearing loop sets one extra byte to 0 following gAudioCtx.
        for (i = sizeof(gAudioCtx); i >= 0; i--) {
            *audioContextPtr++ = 0;
        }
    }

    switch (osTvType) {
        case OS_TV_PAL:
            gAudioCtx.maxTempoTvTypeFactors = 1000 * REFRESH_RATE_DEVIATION_PAL / REFRESH_RATE_PAL;
            gAudioCtx.refreshRate = REFRESH_RATE_PAL;
            break;

        case OS_TV_MPAL:
            gAudioCtx.maxTempoTvTypeFactors = 1000 * REFRESH_RATE_DEVIATION_MPAL / REFRESH_RATE_MPAL;
            gAudioCtx.refreshRate = REFRESH_RATE_MPAL;
            break;

        case OS_TV_NTSC:
        default:
            gAudioCtx.maxTempoTvTypeFactors = 1000 * REFRESH_RATE_DEVIATION_NTSC / REFRESH_RATE_NTSC;
            gAudioCtx.refreshRate = REFRESH_RATE_NTSC;
            break;
    }

    AudioThread_InitMesgQueues();

    for (i = 0; i < 3; i++) {
        gAudioCtx.aiBufLengths[i] = 0xA0;
    }

    gAudioCtx.totalTaskCount = 0;
    gAudioCtx.rspTaskIndex = 0;
    gAudioCtx.curAiBufIndex = 0;
    gAudioCtx.soundMode = SOUNDMODE_STEREO;
    gAudioCtx.curTask = NULL;
    gAudioCtx.rspTask[0].task.t.data_size = 0;
    gAudioCtx.rspTask[1].task.t.data_size = 0;
    osCreateMesgQueue(&gAudioCtx.syncDmaQueue, &gAudioCtx.syncDmaMesg, 1);
    osCreateMesgQueue(&gAudioCtx.curAudioFrameDmaQueue, gAudioCtx.curAudioFrameDmaMsgBuf,
                      ARRAY_COUNT(gAudioCtx.curAudioFrameDmaMsgBuf));
    osCreateMesgQueue(&gAudioCtx.externalLoadQueue, gAudioCtx.externalLoadMsgBuf,
                      ARRAY_COUNT(gAudioCtx.externalLoadMsgBuf));
    osCreateMesgQueue(&gAudioCtx.preloadSampleQueue, gAudioCtx.preloadSampleMsgBuf,
                      ARRAY_COUNT(gAudioCtx.preloadSampleMsgBuf));
    gAudioCtx.curAudioFrameDmaCount = 0;
    gAudioCtx.sampleDmaCount = 0;
    gAudioCtx.cartHandle = osCartRomInit();
    gAudioCtx.driveHandle = osDriveRomInit();

    if (heap == NULL) {
        gAudioCtx.audioHeap = gAudioHeap;
        gAudioCtx.audioHeapSize = gAudioHeapInitSizes.heapSize;
    } else {
        gAudioCtx.audioHeap = heap;
        gAudioCtx.audioHeapSize = heapSize;
    }

    for (i = 0; i < (s32) gAudioCtx.audioHeapSize / 8; i++) {
        ((u64*) gAudioCtx.audioHeap)[i] = 0;
    }

    // Main Pool Split (split entirety of audio heap into initPool and sessionPool)
    AudioHeap_InitMainPools(gAudioHeapInitSizes.initPoolSize);

    // Initialize the audio interface buffers
    for (i = 0; i < ARRAY_COUNT(gAudioCtx.aiBuffers); i++) {
        gAudioCtx.aiBuffers[i] = AudioHeap_AllocZeroed(&gAudioCtx.initPool, AIBUF_SIZE);
    }

    // Set audio tables pointers
    gAudioCtx.sequenceTable = &gSequenceTable;
    gAudioCtx.soundFontTable = &gSoundFontTable;
    gAudioCtx.sampleBankTable = &gSampleBankTable;
    gAudioCtx.sequenceFontTable = gSequenceFontTable;

    gAudioCtx.numSequences = gAudioCtx.sequenceTable->header.numEntries;

    gAudioCtx.specId = 0;
    gAudioCtx.resetStatus = 1;

    AudioHeap_ResetStep();

    // Initialize audio tables
    AudioLoad_InitTable(gAudioCtx.sequenceTable, gAudioSequenceRomStart, gSequenceTableLba);
    AudioLoad_InitTable(gAudioCtx.soundFontTable, gAudioBankRomStart, gSoundFontTableLba);
    AudioLoad_InitTable(gAudioCtx.sampleBankTable, gAudioTableRomStart, gSampleBankTableLba);
    osCreateMesgQueue(&D_806F2328, D_806F2340, ARRAY_COUNT(D_806F2340));
    D_806F2348.vAddr = AudioHeap_Alloc(&gAudioCtx.initPool, 0x4D10);
    D_806F2348.lba = -1;
    numFonts = gAudioCtx.soundFontTable->header.numEntries;
    gAudioCtx.soundFontList = AudioHeap_Alloc(&gAudioCtx.initPool, numFonts * sizeof(SoundFont));

    for (i = 0; i < numFonts; i++) {
        AudioLoad_InitSoundFont(i);
    }

    ramAddr = AudioHeap_Alloc(&gAudioCtx.initPool, gAudioHeapInitSizes.permanentPoolSize);
    if (ramAddr == NULL) {
        gAudioHeapInitSizes.permanentPoolSize = 0;
    }

    AudioHeap_InitPool(&gAudioCtx.permanentPool, ramAddr, gAudioHeapInitSizes.permanentPoolSize);
    gAudioContextInitialized = true;
    osSendMesg(gAudioCtx.taskStartQueueP, (OSMesg) gAudioCtx.totalTaskCount, OS_MESG_NOBLOCK);
}

void AudioLoad_InitSlowLoads(void) {
    gAudioCtx.slowLoads[0].state = SLOW_LOAD_WAITING;
    gAudioCtx.slowLoads[1].state = SLOW_LOAD_WAITING;
}

s32 AudioLoad_SlowLoadSample(s32 fontId, s32 instId, s8* status) {
    Sample* sample;
    AudioSlowLoad* slowLoad;

    sample = AudioLoad_GetFontSample(fontId, instId);
    if (sample == NULL) {
        *status = 0;
        return -1;
    }

    if (sample->medium == MEDIUM_RAM) {
        *status = 2;
        return 0;
    }

    slowLoad = &gAudioCtx.slowLoads[gAudioCtx.slowLoadPos];
    if (slowLoad->state == SLOW_LOAD_DONE) {
        slowLoad->state = SLOW_LOAD_WAITING;
    }

    slowLoad->sample = *sample;
    slowLoad->status = status;
    slowLoad->curRamAddr =
        AudioHeap_AllocSampleCache(sample->size, fontId, sample->sampleAddr, sample->medium, CACHE_TEMPORARY);

    if (slowLoad->curRamAddr == NULL) {
        if (sample->medium == MEDIUM_LBA || sample->codec == CODEC_S16_INMEMORY) {
            *status = 0;
            return -1;
        } else {
            *status = 3;
            return -1;
        }
    }

    slowLoad->state = SLOW_LOAD_START;
    slowLoad->bytesRemaining = ALIGN16(sample->size);
    slowLoad->ramAddr = slowLoad->curRamAddr;
    slowLoad->curDevAddr = (u32) sample->sampleAddr;
    slowLoad->medium = sample->medium;
    slowLoad->seqOrFontId = fontId;
    slowLoad->instId = instId;
    if (slowLoad->medium == MEDIUM_LBA) {
        slowLoad->diskLba = gAudioCtx.sampleBankTable->header.diskLba;
    }

    gAudioCtx.slowLoadPos ^= 1;
    return 0;
}

Sample* AudioLoad_GetFontSample(s32 fontId, s32 instId) {
    Sample* sample;

    if (instId < 0x80) {
        Instrument* instrument = Audio_GetInstrument(fontId, instId);

        if (instrument == NULL) {
            return NULL;
        }
        sample = instrument->normalPitchTunedSample.sample;
    } else if (instId < 0x100) {
        Drum* drum = Audio_GetDrum(fontId, instId - 0x80);

        if (drum == NULL) {
            return NULL;
        }
        sample = drum->tunedSample.sample;
    } else {
        SoundEffect* soundEffect = Audio_GetSoundEffect(fontId, instId - 0x100);

        if (soundEffect == NULL) {
            return NULL;
        }
        sample = soundEffect->tunedSample.sample;
    }
    return sample;
}

void func_807369C8(void) {
}

void AudioLoad_FinishSlowLoad(AudioSlowLoad* slowLoad) {
    Sample* sample;

    if (slowLoad->sample.sampleAddr == NULL) {
        return;
    }

    sample = AudioLoad_GetFontSample(slowLoad->seqOrFontId, slowLoad->instId);

    if (sample != NULL) {
        slowLoad->sample = *sample;
        sample->sampleAddr = slowLoad->ramAddr;
        sample->medium = MEDIUM_RAM;
    }
}

void AudioLoad_ProcessSlowLoads(s32 resetStatus) {
    AudioSlowLoad* slowLoad;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gAudioCtx.slowLoads); i++) {
        slowLoad = &gAudioCtx.slowLoads[i];
        switch (gAudioCtx.slowLoads[i].state) {
            case SLOW_LOAD_LOADING:
                if (slowLoad->medium != MEDIUM_LBA) {
                    osRecvMesg(&slowLoad->msgQueue, NULL, OS_MESG_BLOCK);
                }

                if (resetStatus != 0) {
                    slowLoad->state = SLOW_LOAD_DONE;
                    break;
                }
            case SLOW_LOAD_START:
                slowLoad->state = SLOW_LOAD_LOADING;
                if (slowLoad->bytesRemaining == 0) {
                    AudioLoad_FinishSlowLoad(slowLoad);
                    slowLoad->state = SLOW_LOAD_DONE;
                    *slowLoad->status = 1;
                } else if (slowLoad->bytesRemaining < 0x1000) {
                    if (slowLoad->medium == MEDIUM_LBA) {
                        size_t size = slowLoad->bytesRemaining;

                        AudioLoad_DmaSlowCopyDiskDrive(slowLoad->curDevAddr, slowLoad->curRamAddr, size,
                                                       slowLoad->diskLba);
                    } else {
                        AudioLoad_DmaSlowCopy(slowLoad, slowLoad->bytesRemaining);
                    }
                    slowLoad->bytesRemaining = 0;
                } else {
                    if (slowLoad->medium == MEDIUM_LBA) {
                        AudioLoad_DmaSlowCopyDiskDrive(slowLoad->curDevAddr, slowLoad->curRamAddr, 0x1000,
                                                       slowLoad->diskLba);
                    } else {
                        AudioLoad_DmaSlowCopy(slowLoad, 0x1000);
                    }
                    slowLoad->bytesRemaining -= 0x1000;
                    slowLoad->curRamAddr += 0x1000;
                    slowLoad->curDevAddr += 0x1000;
                }
                break;
        }
    }
}

void AudioLoad_DmaSlowCopy(AudioSlowLoad* slowLoad, ssize_t size) {
    Audio_InvalDCache(slowLoad->curRamAddr, size);
    osCreateMesgQueue(&slowLoad->msgQueue, &slowLoad->msg, 1);
    AudioLoad_Dma(&slowLoad->ioMesg, OS_MESG_PRI_NORMAL, OS_READ, slowLoad->curDevAddr, slowLoad->curRamAddr, size,
                  &slowLoad->msgQueue, slowLoad->medium, "SLOWCOPY");
}

void AudioLoad_DmaSlowCopyDiskDrive(uintptr_t devAddr, u8* ramAddr, size_t size, s32 lba) {
    uintptr_t adjustedDevAddr;

    adjustedDevAddr = devAddr;
    Audio_InvalDCache(ramAddr, size);
    AudioLoad_DiskDrive(AudioLoad_GetStartLbaAddr(lba, &adjustedDevAddr), adjustedDevAddr, ramAddr, size);
}

s32 AudioLoad_SlowLoadSeq(s32 seqId, u8* ramAddr, s8* status) {
    AudioSlowLoad* slowLoad;
    AudioTable* seqTable;
    size_t size;

    seqId = AudioLoad_GetLoadTableIndex(SEQUENCE_TABLE, seqId);
    seqTable = AudioLoad_GetLoadTable(SEQUENCE_TABLE);
    slowLoad = &gAudioCtx.slowLoads[gAudioCtx.slowLoadPos];
    if (slowLoad->state == SLOW_LOAD_DONE) {
        slowLoad->state = SLOW_LOAD_WAITING;
    }

    slowLoad->sample.sampleAddr = NULL;
    slowLoad->status = status;
    size = seqTable->entries[seqId].size;
    size = ALIGN16(size);
    slowLoad->curRamAddr = ramAddr;
    slowLoad->state = SLOW_LOAD_START;
    slowLoad->bytesRemaining = size;
    slowLoad->ramAddr = ramAddr;
    slowLoad->curDevAddr = seqTable->entries[seqId].romAddr;
    slowLoad->medium = seqTable->entries[seqId].medium;
    slowLoad->seqOrFontId = seqId;

    if (slowLoad->medium == MEDIUM_LBA) {
        slowLoad->diskLba = seqTable->header.diskLba;
    }

    gAudioCtx.slowLoadPos ^= 1;
    return 0;
}

extern AudioDiskInfo D_806F2350;

void AudioLoad_InitAsyncLoads(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gAudioCtx.asyncLoads); i++) {
        gAudioCtx.asyncLoads[i].status = 0;
    }

    osCreateMesgQueue(&gAudioCtx.asyncLoadDiskDriveQueue, gAudioCtx.asyncLoadDiskDriveMsgBuf,
                      ARRAY_COUNT(gAudioCtx.asyncLoadDiskDriveMsgBuf));
    gAudioCtx.curDiskDriveLoad = NULL;
    D_806F2350.lbaVaddrPair = &D_806F2348;
}

AudioAsyncLoad* AudioLoad_StartAsyncLoadDiskDrive(s32 lba, uintptr_t devAddr, void* ramAddr, size_t size, s32 medium,
                                                  s32 nChunks, OSMesgQueue* retQueue, s32 retMsg) {
    AudioAsyncLoad* asyncLoad;

    asyncLoad = AudioLoad_StartAsyncLoad(devAddr, ramAddr, size, medium, nChunks, retQueue, retMsg);

    if (asyncLoad == NULL) {
        return NULL;
    }

    osSendMesg(&gAudioCtx.asyncLoadDiskDriveQueue, (OSMesg) asyncLoad, OS_MESG_NOBLOCK);
    asyncLoad->diskLba = lba;
    return asyncLoad;
}

AudioAsyncLoad* AudioLoad_StartAsyncLoad(uintptr_t devAddr, void* ramAddr, size_t size, s32 medium, s32 nChunks,
                                         OSMesgQueue* retQueue, s32 retMsg) {
    AudioAsyncLoad* asyncLoad;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gAudioCtx.asyncLoads); i++) {
        if (gAudioCtx.asyncLoads[i].status == 0) {
            asyncLoad = &gAudioCtx.asyncLoads[i];
            break;
        }
    }

    if (i == ARRAY_COUNT(gAudioCtx.asyncLoads)) {
        return NULL;
    }

    asyncLoad->status = 1;
    asyncLoad->curDevAddr = devAddr;
    asyncLoad->ramAddr = ramAddr;
    asyncLoad->curRamAddr = ramAddr;
    asyncLoad->bytesRemaining = size;

    if (nChunks == 0) {
        asyncLoad->chunkSize = 0x1000;
    } else if (nChunks == 1) {
        asyncLoad->chunkSize = size;
    } else {
        asyncLoad->chunkSize = ALIGN256((s32) size / nChunks);
        if (asyncLoad->chunkSize < 0x100) {
            asyncLoad->chunkSize = 0x100;
        }
    }

    asyncLoad->retQueue = retQueue;
    asyncLoad->delay = 3;
    asyncLoad->medium = medium;
    asyncLoad->retMsg = retMsg;
    osCreateMesgQueue(&asyncLoad->msgQueue, &asyncLoad->msg, 1);
    return asyncLoad;
}

void AudioLoad_ProcessAsyncLoads(s32 resetStatus) {
    AudioAsyncLoad* asyncLoad;
    s32 i;

    if (gAudioCtx.resetTimer == 1) {
        return;
    }

    if (gAudioCtx.curDiskDriveLoad == NULL) {
        if (resetStatus != 0) {
            // Clear and ignore queue if resetting.
            do {
            } while (osRecvMesg(&gAudioCtx.asyncLoadDiskDriveQueue, (OSMesg*) &asyncLoad, OS_MESG_NOBLOCK) != -1);
        } else if (osRecvMesg(&gAudioCtx.asyncLoadDiskDriveQueue, (OSMesg*) &asyncLoad, OS_MESG_NOBLOCK) == -1) {
            gAudioCtx.curDiskDriveLoad = NULL;
        } else {
            gAudioCtx.curDiskDriveLoad = asyncLoad;
        }
    }

    if (gAudioCtx.curDiskDriveLoad != NULL) {
        AudioLoad_ProcessAsyncLoadDiskDrive(gAudioCtx.curDiskDriveLoad, resetStatus);
    }

    for (i = 0; i < ARRAY_COUNT(gAudioCtx.asyncLoads); i++) {
        if (gAudioCtx.asyncLoads[i].status == 1) {
            asyncLoad = &gAudioCtx.asyncLoads[i];
            if (asyncLoad->medium != MEDIUM_LBA) {
                AudioLoad_ProcessAsyncLoad(asyncLoad, resetStatus);
            }
        }
    }
}

void AudioLoad_ProcessAsyncLoadDiskDrive(AudioAsyncLoad* asyncLoad, s32 resetStatus) {
    s32 pad[2];
    uintptr_t adjustedDevAddr;

    if (asyncLoad->delay == 3) {
        adjustedDevAddr = asyncLoad->curDevAddr;
        Audio_InvalDCache(asyncLoad->curRamAddr, asyncLoad->bytesRemaining);
        AudioLoad_DiskInit(&D_806F2350, AudioLoad_GetStartLbaAddr(asyncLoad->diskLba, &adjustedDevAddr),
                           adjustedDevAddr, asyncLoad->curRamAddr, asyncLoad->bytesRemaining);
        asyncLoad->delay = 0;
    } else if (resetStatus != 0) {
        do {
        } while (AudioLoad_DiskLoad(&D_806F2350) != 1);
        asyncLoad->status = 0;
        gAudioCtx.curDiskDriveLoad = NULL;
    } else if (AudioLoad_DiskLoad(&D_806F2350) == 1) {
        AudioLoad_FinishAsyncLoad(asyncLoad);
        gAudioCtx.curDiskDriveLoad = NULL;
    }
}

#define ASYNC_TBLTYPE(v) ((u8) (v >> 16))
#define ASYNC_ID(v) ((u8) (v >> 8))
#define ASYNC_LOAD_STATUS(v) ((u8) (v >> 0))

void AudioLoad_FinishAsyncLoad(AudioAsyncLoad* asyncLoad) {
    u32 retMsg = asyncLoad->retMsg;
    u32 fontId;
    u32 pad;
    OSMesg doneMsg;
    u32 sampleBankId1;
    u32 sampleBankId2;
    SampleBankRelocInfo sampleBankReloc;

    if (1) {}
    switch (ASYNC_TBLTYPE(retMsg)) {
        case SEQUENCE_TABLE:
            AudioLoad_SetSeqLoadStatus(ASYNC_ID(retMsg), ASYNC_LOAD_STATUS(retMsg));
            break;

        case SAMPLE_TABLE:
            AudioLoad_SetSampleFontLoadStatusAndApplyCaches(ASYNC_ID(retMsg), ASYNC_LOAD_STATUS(retMsg));
            break;

        case FONT_TABLE:
            fontId = ASYNC_ID(retMsg);
            sampleBankId1 = gAudioCtx.soundFontList[fontId].sampleBankId1;
            sampleBankId2 = gAudioCtx.soundFontList[fontId].sampleBankId2;
            sampleBankReloc.sampleBankId1 = sampleBankId1;
            sampleBankReloc.sampleBankId2 = sampleBankId2;
            sampleBankReloc.baseAddr1 =
                sampleBankId1 != 0xFF ? AudioLoad_GetSampleBank(sampleBankId1, &sampleBankReloc.medium1) : 0;
            sampleBankReloc.baseAddr2 =
                sampleBankId2 != 0xFF ? AudioLoad_GetSampleBank(sampleBankId2, &sampleBankReloc.medium2) : 0;
            AudioLoad_SetFontLoadStatus(fontId, ASYNC_LOAD_STATUS(retMsg));
            AudioLoad_RelocateFontAndPreloadSamples(fontId, asyncLoad->ramAddr, &sampleBankReloc, AUDIOLOAD_ASYNC);
            break;
    }

    doneMsg = (OSMesg) asyncLoad->retMsg;
    if (1) {}
    asyncLoad->status = 0;
    osSendMesg(asyncLoad->retQueue, doneMsg, OS_MESG_NOBLOCK);
}

void AudioLoad_ProcessAsyncLoad(AudioAsyncLoad* asyncLoad, s32 resetStatus) {
    AudioTable* sampleBankTable = gAudioCtx.sampleBankTable;

    if (asyncLoad->delay >= 2) {
        asyncLoad->delay--;
        return;
    }

    if (asyncLoad->delay == 1) {
        asyncLoad->delay = 0;
    } else if (resetStatus != 0) {
        // Await the previous DMA response synchronously, then return.
        osRecvMesg(&asyncLoad->msgQueue, NULL, OS_MESG_BLOCK);
        asyncLoad->status = 0;
        return;
    } else if (osRecvMesg(&asyncLoad->msgQueue, NULL, OS_MESG_NOBLOCK) == -1) {
        // If the previous DMA step isn't done, return.
        return;
    }

    if (asyncLoad->bytesRemaining == 0) {
        AudioLoad_FinishAsyncLoad(asyncLoad);
        return;
    }

    if (asyncLoad->bytesRemaining < asyncLoad->chunkSize) {
        if (asyncLoad->medium == MEDIUM_LBA) {
            AudioLoad_AsyncDiskDrive(asyncLoad->curDevAddr, asyncLoad->curRamAddr, asyncLoad->bytesRemaining,
                                     sampleBankTable->header.diskLba);
        } else {
            AudioLoad_AsyncDma(asyncLoad, asyncLoad->bytesRemaining);
        }
        asyncLoad->bytesRemaining = 0;
        return;
    }

    if (asyncLoad->medium == MEDIUM_LBA) {
        AudioLoad_AsyncDiskDrive(asyncLoad->curDevAddr, asyncLoad->curRamAddr, asyncLoad->chunkSize,
                                 sampleBankTable->header.diskLba);
    } else {
        AudioLoad_AsyncDma(asyncLoad, asyncLoad->chunkSize);
    }

    asyncLoad->bytesRemaining -= asyncLoad->chunkSize;
    asyncLoad->curDevAddr += asyncLoad->chunkSize;
    asyncLoad->curRamAddr += asyncLoad->chunkSize;
}

void AudioLoad_AsyncDma(AudioAsyncLoad* asyncLoad, size_t size) {
    size = ALIGN16(size);

    if (size) {}

    Audio_InvalDCache(asyncLoad->curRamAddr, size);
    osCreateMesgQueue(&asyncLoad->msgQueue, &asyncLoad->msg, 1);
    AudioLoad_Dma(&asyncLoad->ioMesg, OS_MESG_PRI_NORMAL, OS_READ, asyncLoad->curDevAddr, asyncLoad->curRamAddr, size,
                  &asyncLoad->msgQueue, asyncLoad->medium, "BGCOPY");
}

void AudioLoad_AsyncDiskDrive(uintptr_t devAddr, u8* ramAddr, size_t size, s32 lba) {
    uintptr_t adjustedDevAddr;

    adjustedDevAddr = devAddr;
    Audio_InvalDCache(ramAddr, size);
    AudioLoad_DiskDrive(AudioLoad_GetStartLbaAddr(lba, &adjustedDevAddr), adjustedDevAddr, ramAddr, size);
}

void AudioLoad_RelocateSample(TunedSample* tSample, uintptr_t fontDataAddr, SampleBankRelocInfo* relocInfo) {
    void* reloc;
    Sample* sample;

    // "Error: Already wavetable is touched %x.\n";
    if ((uintptr_t) tSample->sample <= AUDIO_RELOCATED_ADDRESS_START) {
        sample = tSample->sample = reloc = (uintptr_t) tSample->sample + fontDataAddr;
        // "Touch Warning: Length zero %x\n";
        if ((sample->size != 0) && (sample->isRelocated != 1)) {
            sample->loop = reloc = (uintptr_t) sample->loop + fontDataAddr;
            sample->book = reloc = (uintptr_t) sample->book + fontDataAddr;
            switch (sample->medium) {
                case MEDIUM_RAM:
                    sample->sampleAddr = reloc = sample->sampleAddr + relocInfo->baseAddr1;
                    sample->medium = relocInfo->medium1;
                    break;
                case MEDIUM_LBA:
                    sample->sampleAddr = reloc = sample->sampleAddr + relocInfo->baseAddr2;
                    sample->medium = relocInfo->medium2;
                    break;
                case MEDIUM_CART:
                case MEDIUM_DISK_DRIVE:
                    break;
            }
            sample->isRelocated = true;
            if (sample->unk_bit26 && (sample->medium != 0)) {
                gAudioCtx.usedSamples[gAudioCtx.numUsedSamples++] = sample;
            }
        }
    }
}

void AudioLoad_RelocateFontAndPreloadSamples(s32 fontId, uintptr_t fontData, SampleBankRelocInfo* sampleBankReloc,
                                             s32 async) {
    AudioPreloadReq* preload;
    AudioPreloadReq* topPreload;
    Sample* sample;
    s32 size;
    s32 nChunks;
    u8* sampleRamAddr;
    s32 preloadInProgress;
    s32 i;

    preloadInProgress = false;
    if (gAudioCtx.preloadSampleStackTop != 0) {
        preloadInProgress = true;
    } else {
        D_807C1890 = 0;
    }

    gAudioCtx.numUsedSamples = 0;
    AudioLoad_RelocateFont(fontId, fontData, sampleBankReloc);

    size = 0;
    for (i = 0; i < gAudioCtx.numUsedSamples; i++) {
        size += ALIGN16(gAudioCtx.usedSamples[i]->size);
    }
    if (size && size) {}

    for (i = 0; i < gAudioCtx.numUsedSamples; i++) {
        if (gAudioCtx.preloadSampleStackTop == 120) {
            break;
        }

        sample = gAudioCtx.usedSamples[i];
        sampleRamAddr = NULL;
        switch (async) {
            case AUDIOLOAD_SYNC:
                if (sample->medium == sampleBankReloc->medium1) {
                    sampleRamAddr = AudioHeap_AllocSampleCache(sample->size, sampleBankReloc->sampleBankId1,
                                                               sample->sampleAddr, sample->medium, CACHE_PERSISTENT);
                } else if (sample->medium == sampleBankReloc->medium2) {
                    sampleRamAddr = AudioHeap_AllocSampleCache(sample->size, sampleBankReloc->sampleBankId2,
                                                               sample->sampleAddr, sample->medium, CACHE_PERSISTENT);
                } else if (sample->medium == MEDIUM_DISK_DRIVE) {
                    sampleRamAddr = AudioHeap_AllocSampleCache(sample->size, 0xFE, sample->sampleAddr, sample->medium,
                                                               CACHE_PERSISTENT);
                }
                break;

            case AUDIOLOAD_ASYNC:
                if (sample->medium == sampleBankReloc->medium1) {
                    sampleRamAddr = AudioHeap_AllocSampleCache(sample->size, sampleBankReloc->sampleBankId1,
                                                               sample->sampleAddr, sample->medium, CACHE_TEMPORARY);
                } else if (sample->medium == sampleBankReloc->medium2) {
                    sampleRamAddr = AudioHeap_AllocSampleCache(sample->size, sampleBankReloc->sampleBankId2,
                                                               sample->sampleAddr, sample->medium, CACHE_TEMPORARY);
                } else if (sample->medium == MEDIUM_DISK_DRIVE) {
                    sampleRamAddr = AudioHeap_AllocSampleCache(sample->size, 0xFE, sample->sampleAddr, sample->medium,
                                                               CACHE_TEMPORARY);
                }
                break;
        }
        if (sampleRamAddr == NULL) {
            continue;
        }

        switch (async) {
            case AUDIOLOAD_SYNC:
                if (sample->medium == MEDIUM_LBA) {
                    AudioLoad_SyncDiskDrive((uintptr_t) sample->sampleAddr, sampleRamAddr, sample->size,
                                            gAudioCtx.sampleBankTable->header.diskLba);
                    sample->sampleAddr = sampleRamAddr;
                    sample->medium = MEDIUM_RAM;
                } else {
                    AudioLoad_SyncDma((uintptr_t) sample->sampleAddr, sampleRamAddr, sample->size, sample->medium);
                    sample->sampleAddr = sampleRamAddr;
                    sample->medium = MEDIUM_RAM;
                }
                if (sample->medium == MEDIUM_DISK_DRIVE) {}
                break;

            case AUDIOLOAD_ASYNC:
                preload = &gAudioCtx.preloadSampleStack[gAudioCtx.preloadSampleStackTop];
                preload->sample = sample;
                preload->ramAddr = sampleRamAddr;
                preload->encodedInfo = (gAudioCtx.preloadSampleStackTop << 24) | 0xFFFFFF;
                preload->isFree = false;
                preload->endAndMediumKey = (uintptr_t) sample->sampleAddr + sample->size + sample->medium;
                gAudioCtx.preloadSampleStackTop++;
                break;
        }
    }
    gAudioCtx.numUsedSamples = 0;

    if (gAudioCtx.preloadSampleStackTop != 0 && !preloadInProgress) {
        topPreload = &gAudioCtx.preloadSampleStack[gAudioCtx.preloadSampleStackTop - 1];
        sample = topPreload->sample;
        nChunks = (sample->size >> 12) + 1;
        AudioLoad_StartAsyncLoad((uintptr_t) sample->sampleAddr, topPreload->ramAddr, sample->size, sample->medium,
                                 nChunks, &gAudioCtx.preloadSampleQueue, topPreload->encodedInfo);
    }
}

bool AudioLoad_ProcessSamplePreloads(s32 resetStatus) {
    Sample* sample;
    AudioPreloadReq* preload;
    u32 preloadIndex;
    u32 key;
    u32 nChunks;
    s32 pad;

    if (gAudioCtx.preloadSampleStackTop > 0) {
        if (resetStatus != 0) {
            // Clear result queue and preload stack and return.
            osRecvMesg(&gAudioCtx.preloadSampleQueue, (OSMesg*) &preloadIndex, OS_MESG_NOBLOCK);
            gAudioCtx.preloadSampleStackTop = 0;
            return false;
        }
        if (osRecvMesg(&gAudioCtx.preloadSampleQueue, (OSMesg*) &preloadIndex, OS_MESG_NOBLOCK) == -1) {
            // Previous preload is not done yet.
            return false;
        }

        preloadIndex >>= 24;
        preload = &gAudioCtx.preloadSampleStack[preloadIndex];

        if (!preload->isFree) {
            sample = preload->sample;
            key = (u32) sample->sampleAddr + sample->size + sample->medium;
            if (key == preload->endAndMediumKey) {
                // Change storage for sample to the preloaded version.
                sample->sampleAddr = preload->ramAddr;
                sample->medium = MEDIUM_RAM;
            }
            preload->isFree = true;
        }

        // Pop requests with isFree = true off the stack, as far as possible,
        // and dispatch the next DMA.
        while (true) {
            if (gAudioCtx.preloadSampleStackTop <= 0) {
                break;
            }
            preload = &gAudioCtx.preloadSampleStack[gAudioCtx.preloadSampleStackTop - 1];
            if (preload->isFree == true) {
                gAudioCtx.preloadSampleStackTop--;
                continue;
            }

            sample = preload->sample;
            nChunks = (sample->size >> 12) + 1;
            key = (uintptr_t) sample->sampleAddr + sample->size + sample->medium;
            if (key != preload->endAndMediumKey) {
                preload->isFree = true;
                gAudioCtx.preloadSampleStackTop--;
            } else {
                AudioLoad_StartAsyncLoad((uintptr_t) sample->sampleAddr, preload->ramAddr, sample->size, sample->medium,
                                         nChunks, &gAudioCtx.preloadSampleQueue, preload->encodedInfo);
                break;
            }
        }
    }
    return true;
}

s32 AudioLoad_AddToSampleSet(Sample* sample, s32 numSamples, Sample** sampleSet) {
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

s32 AudioLoad_GetSamplesForFont(s32 fontId, Sample** sampleSet) {
    s32 i;
    s32 numSamples = 0;
    s32 numDrums = gAudioCtx.soundFontList[fontId].numDrums;
    s32 numInstruments = gAudioCtx.soundFontList[fontId].numInstruments;

    for (i = 0; i < numDrums; i++) {
        Drum* drum = Audio_GetDrum(fontId, i);

        if (drum == NULL) {
            continue;
        }

        numSamples = AudioLoad_AddToSampleSet(drum->tunedSample.sample, numSamples, sampleSet);
    }

    for (i = 0; i < numInstruments; i++) {
        Instrument* instrument = Audio_GetInstrument(fontId, i);

        if (instrument == NULL) {
            continue;
        }

        if (instrument->normalRangeLo != 0) {
            numSamples = AudioLoad_AddToSampleSet(instrument->lowPitchTunedSample.sample, numSamples, sampleSet);
        }
        if (instrument->normalRangeHi != 0x7F) {
            numSamples = AudioLoad_AddToSampleSet(instrument->highPitchTunedSample.sample, numSamples, sampleSet);
        }
        numSamples = AudioLoad_AddToSampleSet(instrument->normalPitchTunedSample.sample, numSamples, sampleSet);
    }

    return numSamples;
}

void AudioLoad_AddUsedSample(TunedSample* tunedSample) {
    Sample* sample = tunedSample->sample;

    if ((sample->size != 0) && sample->unk_bit26 && (sample->medium != MEDIUM_RAM)) {
        gAudioCtx.usedSamples[gAudioCtx.numUsedSamples++] = sample;
    }
}

void AudioLoad_PreloadSamplesForFont(s32 fontId, s32 async, SampleBankRelocInfo* sampleBankReloc) {
    s32 numDrums;
    s32 numInstruments;
    s32 numSfx;
    Drum* drum;
    Instrument* instrument;
    SoundEffect* soundEffect;
    AudioPreloadReq* preload;
    AudioPreloadReq* topPreload;
    u8* addr;
    s32 size;
    s32 i;
    Sample* sample;
    s32 preloadInProgress;
    s32 nChunks;

    preloadInProgress = false;
    if (gAudioCtx.preloadSampleStackTop != 0) {
        preloadInProgress = true;
    }

    gAudioCtx.numUsedSamples = 0;

    numDrums = gAudioCtx.soundFontList[fontId].numDrums;
    numInstruments = gAudioCtx.soundFontList[fontId].numInstruments;
    numSfx = gAudioCtx.soundFontList[fontId].numSfx;

    for (i = 0; i < numInstruments; i++) {
        instrument = Audio_GetInstrument(fontId, i);
        if (instrument != NULL) {
            if (instrument->normalRangeLo != 0) {
                AudioLoad_AddUsedSample(&instrument->lowPitchTunedSample);
            }
            if (instrument->normalRangeHi != 0x7F) {
                AudioLoad_AddUsedSample(&instrument->highPitchTunedSample);
            }
            AudioLoad_AddUsedSample(&instrument->normalPitchTunedSample);
        }
    }

    for (i = 0; i < numDrums; i++) {
        drum = Audio_GetDrum(fontId, i);
        if (drum != NULL) {
            AudioLoad_AddUsedSample(&drum->tunedSample);
        }
    }

    for (i = 0; i < numSfx; i++) {
        soundEffect = Audio_GetSoundEffect(fontId, i);
        if (soundEffect != NULL) {
            AudioLoad_AddUsedSample(&soundEffect->tunedSample);
        }
    }

    if (gAudioCtx.numUsedSamples == 0) {
        return;
    }

    size = 0;
    for (i = 0; i < gAudioCtx.numUsedSamples; i++) {
        size += ALIGN16(gAudioCtx.usedSamples[i]->size);
    }
    if (size) {}

    for (i = 0; i < gAudioCtx.numUsedSamples; i++) {
        if (gAudioCtx.preloadSampleStackTop == 120) {
            break;
        }

        sample = gAudioCtx.usedSamples[i];
        if (sample->medium == MEDIUM_RAM) {
            continue;
        }

        switch (async) {
            case AUDIOLOAD_SYNC:
                if (sample->medium == sampleBankReloc->medium1) {
                    addr = AudioHeap_AllocSampleCache(sample->size, sampleBankReloc->sampleBankId1, sample->sampleAddr,
                                                      sample->medium, CACHE_PERSISTENT);
                } else if (sample->medium == sampleBankReloc->medium2) {
                    addr = AudioHeap_AllocSampleCache(sample->size, sampleBankReloc->sampleBankId2, sample->sampleAddr,
                                                      sample->medium, CACHE_PERSISTENT);
                }
                break;

            case AUDIOLOAD_ASYNC:
                if (sample->medium == sampleBankReloc->medium1) {
                    addr = AudioHeap_AllocSampleCache(sample->size, sampleBankReloc->sampleBankId1, sample->sampleAddr,
                                                      sample->medium, CACHE_TEMPORARY);
                } else if (sample->medium == sampleBankReloc->medium2) {
                    addr = AudioHeap_AllocSampleCache(sample->size, sampleBankReloc->sampleBankId2, sample->sampleAddr,
                                                      sample->medium, CACHE_TEMPORARY);
                }
                break;
        }
        if (addr == NULL) {
            continue;
        }

        switch (async) {
            case AUDIOLOAD_SYNC:
                if (sample->medium == MEDIUM_LBA) {
                    AudioLoad_SyncDiskDrive((uintptr_t) sample->sampleAddr, addr, sample->size,
                                            gAudioCtx.sampleBankTable->header.diskLba);
                    sample->sampleAddr = addr;
                    sample->medium = MEDIUM_RAM;
                } else {
                    AudioLoad_SyncDma((uintptr_t) sample->sampleAddr, addr, sample->size, sample->medium);
                    sample->sampleAddr = addr;
                    sample->medium = MEDIUM_RAM;
                }
                break;

            case AUDIOLOAD_ASYNC:
                preload = &gAudioCtx.preloadSampleStack[gAudioCtx.preloadSampleStackTop];
                preload->sample = sample;
                preload->ramAddr = addr;
                preload->encodedInfo = (gAudioCtx.preloadSampleStackTop << 24) | 0xFFFFFF;
                preload->isFree = false;
                preload->endAndMediumKey = (uintptr_t) sample->sampleAddr + sample->size + sample->medium;
                gAudioCtx.preloadSampleStackTop++;
                break;
        }
    }
    gAudioCtx.numUsedSamples = 0;

    if (gAudioCtx.preloadSampleStackTop != 0 && !preloadInProgress) {
        topPreload = &gAudioCtx.preloadSampleStack[gAudioCtx.preloadSampleStackTop - 1];
        sample = topPreload->sample;
        nChunks = (sample->size >> 12) + 1;
        AudioLoad_StartAsyncLoad((uintptr_t) sample->sampleAddr, topPreload->ramAddr, sample->size, sample->medium,
                                 nChunks, &gAudioCtx.preloadSampleQueue, topPreload->encodedInfo);
    }
}

void AudioLoad_LoadPermanentSamples(void) {
    s32 pad;
    u32 fontId;
    AudioTable* sampleBankTable;
    s32 pad2;
    s32 i;

    sampleBankTable = AudioLoad_GetLoadTable(SAMPLE_TABLE);
    for (i = 0; i < gAudioCtx.permanentPool.numEntries; i++) {
        SampleBankRelocInfo sampleBankReloc;

        if (gAudioCtx.permanentCache[i].tableType == FONT_TABLE) {
            fontId = AudioLoad_GetLoadTableIndex(FONT_TABLE, gAudioCtx.permanentCache[i].id);
            sampleBankReloc.sampleBankId1 = gAudioCtx.soundFontList[fontId].sampleBankId1;
            sampleBankReloc.sampleBankId2 = gAudioCtx.soundFontList[fontId].sampleBankId2;

            if (sampleBankReloc.sampleBankId1 != 0xFF) {
                sampleBankReloc.sampleBankId1 =
                    AudioLoad_GetLoadTableIndex(SAMPLE_TABLE, sampleBankReloc.sampleBankId1);
                sampleBankReloc.medium1 = sampleBankTable->entries[sampleBankReloc.sampleBankId1].medium;
            }

            if (sampleBankReloc.sampleBankId2 != 0xFF) {
                sampleBankReloc.sampleBankId2 =
                    AudioLoad_GetLoadTableIndex(SAMPLE_TABLE, sampleBankReloc.sampleBankId2);
                sampleBankReloc.medium2 = sampleBankTable->entries[sampleBankReloc.sampleBankId2].medium;
            }
            AudioLoad_PreloadSamplesForFont(fontId, false, &sampleBankReloc);
        }
    }
}

void AudioLoad_DiskDrive(s32 lba, uintptr_t devAddr, u8* ramAddr, s32 totalSize) {
    s32 pad[2];
    LEOCmd cmdBlock;
    s32 blockSize;
    s32 size;
    u8* endRamAddr;
    s32 nLbas;
    s32 nextLba;
    s32 finalLba;

    AudioLoad_ReadWriteDisk(&cmdBlock, OS_READ, lba, &D_806F2348, 1, &D_806F2328, true);
    osRecvMesg(&D_806F2328, NULL, OS_MESG_BLOCK);
    size = AudioLoad_LbaToBlockSize(lba) - devAddr;
    if (totalSize < size) {
        size = totalSize;
    }
    bcopy(D_806F2348.vAddr + devAddr, ramAddr, size);
    totalSize -= size;
    finalLba = lba + 1;
    ramAddr += size;
    if (totalSize == 0) {
        return;
    }
    nLbas = 0;
    nextLba = finalLba;
    endRamAddr = ramAddr;
    while (true) {
        blockSize = AudioLoad_LbaToBlockSize(finalLba);
        if (totalSize < blockSize) {
            break;
        }
        finalLba++;
        totalSize -= blockSize;
        endRamAddr += blockSize;
        nLbas++;
    }

    if (nLbas != 0) {
        AudioLoad_ReadWriteDisk(&cmdBlock, OS_READ, nextLba, ramAddr, nLbas, &D_806F2328, false);
        osRecvMesg(&D_806F2328, NULL, OS_MESG_BLOCK);
    }

    if (totalSize != 0) {
        AudioLoad_ReadWriteDisk(&cmdBlock, OS_READ, finalLba, &D_806F2348, 1, &D_806F2328, true);
        osRecvMesg(&D_806F2328, NULL, OS_MESG_BLOCK);
        bcopy(D_806F2348.vAddr, endRamAddr, totalSize);
    }
}

s32 AudioLoad_DiskCheckQueue(AudioDiskInfo* diskInfo) {
    return osRecvMesg(&diskInfo->mq, NULL, OS_MESG_NOBLOCK);
}

s32 AudioLoad_DiskInit(AudioDiskInfo* diskInfo, s32 lba, uintptr_t devAddr, u8* ramAddr, s32 bytesRemaining) {

    diskInfo->lba = lba;
    diskInfo->devAddr = devAddr;
    diskInfo->ramAddr = ramAddr;
    diskInfo->bytesRemaining = bytesRemaining;
    diskInfo->transferState = 0;

    osCreateMesgQueue(&diskInfo->mq, diskInfo->msgBuf, ARRAY_COUNT(diskInfo->msgBuf));
    diskInfo->finalLba = diskInfo->lba;
    AudioLoad_ReadWriteDisk(&diskInfo->cmdBlock, OS_READ, diskInfo->finalLba, diskInfo->lbaVaddrPair, 1, &diskInfo->mq,
                            true);

    return 0;
}

s32 AudioLoad_DiskLoad(AudioDiskInfo* diskInfo) {

    switch (diskInfo->transferState) {
        case 0:
            if (AudioLoad_DiskCheckQueue(diskInfo) == -1) {
                return 0;
            }

            diskInfo->blockSize = AudioLoad_LbaToBlockSize(diskInfo->finalLba) - diskInfo->devAddr;
            if (diskInfo->bytesRemaining < diskInfo->blockSize) {
                diskInfo->blockSize = diskInfo->bytesRemaining;
            }
            bcopy(diskInfo->lbaVaddrPair->vAddr + diskInfo->devAddr, diskInfo->ramAddr, diskInfo->blockSize);
            diskInfo->bytesRemaining -= diskInfo->blockSize;
            diskInfo->ramAddr += diskInfo->blockSize;
            diskInfo->finalLba++;
            if (diskInfo->bytesRemaining == 0) {
                return 1;
            }

            diskInfo->nLbas = 0;
            diskInfo->nextLba = diskInfo->finalLba;
            diskInfo->endRamAddr = diskInfo->ramAddr;

            while (true) {
                diskInfo->blockSize = AudioLoad_LbaToBlockSize(diskInfo->finalLba);
                if (diskInfo->bytesRemaining < diskInfo->blockSize) {
                    diskInfo->blockSize = diskInfo->bytesRemaining;
                    break;
                }
                diskInfo->finalLba++;
                diskInfo->bytesRemaining -= diskInfo->blockSize;
                diskInfo->endRamAddr += diskInfo->blockSize;
                diskInfo->nLbas++;
            }

            if (diskInfo->nLbas != 0) {
                AudioLoad_ReadWriteDisk(&diskInfo->cmdBlock, OS_READ, diskInfo->nextLba, diskInfo->ramAddr,
                                        diskInfo->nLbas, &diskInfo->mq, false);
                diskInfo->transferState++;
                return 0;
            }
            diskInfo->transferState++;
        case 1:
            if ((diskInfo->nLbas != 0) && (AudioLoad_DiskCheckQueue(diskInfo) == -1)) {
                return 0;
            }
            if (diskInfo->blockSize != 0) {
                AudioLoad_ReadWriteDisk(&diskInfo->cmdBlock, OS_READ, diskInfo->finalLba, diskInfo->lbaVaddrPair, 1,
                                        &diskInfo->mq, true);
                diskInfo->transferState++;
                return 0;
            }
            return 1;
        case 2:
            if (AudioLoad_DiskCheckQueue(diskInfo) == -1) {
                return 0;
            }
            bcopy(diskInfo->lbaVaddrPair->vAddr, diskInfo->endRamAddr, diskInfo->blockSize);
            return 1;
        default:
            return 0;
    }
}

void AudioLoad_ScriptLoad(s32 tableType, s32 id, s8* status) {
    static u32 sLoadIndex = 0;

    sScriptLoadDonePointers[sLoadIndex] = status;
    AudioLoad_AsyncLoad(tableType, id, 0, sLoadIndex, &sScriptLoadQueue);
    sLoadIndex++;
    if (sLoadIndex == ARRAY_COUNT(sScriptLoadDonePointers)) {
        sLoadIndex = 0;
    }
}

void AudioLoad_ProcessScriptLoads(void) {
    u32 temp;
    u32 sp20;
    s8* status;

    if (osRecvMesg(&sScriptLoadQueue, (OSMesg*) &sp20, OS_MESG_NOBLOCK) != -1) {
        temp = sp20 >> 24;
        status = sScriptLoadDonePointers[temp];
        if (status != NULL) {
            *status = 0;
        }
    }
}

void AudioLoad_InitScriptLoads(void) {
    osCreateMesgQueue(&sScriptLoadQueue, sScriptLoadMsgBuf, ARRAY_COUNT(sScriptLoadMsgBuf));
}

void func_80738944(void) {
    s32 i;

    for (i = 0; i < D_807C1BD8; i++) {
        func_80738B84(&D_807C1948[i]);
    }
}

s32 func_807389AC(unk_807C1948* arg0) {
    if (arg0->unk_24 == 0) {
        return 0;
    }
    if (AudioLoad_DiskLoad(&arg0->diskInfo) == 1) {
        arg0->unk_24 = 0;
        return 1;
    }
    return -1;
}

s32 func_80738A04(unk_807C1948* arg0, s32 ramAddr, s32 bytesRemaining) {
    uintptr_t adjustedDevAddr;

    if (arg0->unk_24 != 0) {
        return 0;
    }
    adjustedDevAddr = arg0->sampleAddr + arg0->unk_20;
    arg0->unk_20 += bytesRemaining;
    if (arg0->sampleSize < arg0->unk_20) {
        bytesRemaining = (bytesRemaining - arg0->unk_20) + arg0->sampleSize;
        arg0->unk_20 = 0;
    }
    AudioLoad_DiskInit(&arg0->diskInfo, AudioLoad_GetStartLbaAddr(arg0->unk_10, &adjustedDevAddr), adjustedDevAddr,
                       ramAddr, bytesRemaining);
    arg0->unk_24 = 1;
    return bytesRemaining;
}

void func_80738AA8(void) {
    s32 i;

    D_807C1BD8 = 0;

    for (i = 0; i < 4; i++) {
        unk_807C1948* var_s1 = &D_807C1948[i];

        var_s1->unk_00 = AudioHeap_AllocAttemptExternal(&gAudioCtx.miscPool, 0x10A00);
        if (var_s1->unk_00 == NULL) {
            break;
        }
        D_807C1BD8++;
        var_s1->diskInfo.lbaVaddrPair = &var_s1->lbaVaddrPair;
        var_s1->lbaVaddrPair.vAddr = AudioHeap_AllocAttemptExternal(&gAudioCtx.miscPool, 0x4D10);
        var_s1->lbaVaddrPair.lba = -1;
        var_s1->unk_24 = 0;
        var_s1->unk_28 = 0;
        var_s1->unk_2C = 0;
    }
}

void func_80738B84(unk_807C1948* arg0) {

    if (arg0) {}

    if (arg0 != NULL) {
        do {
        } while (func_807389AC(arg0) == -1);
        arg0->unk_28 = 0;
    }
}

unk_807C1948* func_80738BC8(Sample* sample) {
    s32 i;
    unk_807C1948* sp0;

    if (sample == NULL) {
        return NULL;
    }
    if (sample->medium != MEDIUM_LBA) {
        return NULL;
    }

    for (i = 0; i < D_807C1BD8; i++) {
        sp0 = &D_807C1948[i];
        if (sp0->unk_28 == 0) {
            break;
        }
    }
    if (i == D_807C1BD8) {
        return NULL;
    }
    sp0->unk_04 = 0;
    sp0->unk_08 = 0x1000;
    sp0->unk_0C = 0;
    sp0->unk_10 = gAudioCtx.sampleBankTable->header.diskLba;
    sp0->sampleAddr = sample->sampleAddr;
    sp0->sampleSize = sample->size;
    sp0->unk_20 = 0;
    sp0->unk_2C = 0;
    sp0->unk_28 = 1;
    sp0->unk_1C = 0;
    return sp0;
}

s32 func_80738CA8(unk_807C1948* arg0) {
    s32 var_v0;
    s32 var_v1;
    s32 var_v0_2;
    s32 sp20;

    if (arg0->unk_28 == 0) {
        return 0;
    }
    sp20 = func_807389AC(arg0);

    if (arg0->unk_0C < 0x1000) {
        var_v0 = 2;
    } else {
        var_v0 = ((arg0->unk_0C - 0x1000) / 16000);
        var_v0 = (var_v0 + 3) % 4;
    }

    var_v1 = ((arg0->unk_08 - 0x1000) / 16000);
    if (var_v0 != var_v1) {

        if (arg0->unk_1C != 0) {
            var_v0_2 = func_80738A04(arg0, arg0->unk_00 + arg0->unk_08, arg0->unk_1C);
            if (var_v0_2 == 0) {
                return 0;
            }
            arg0->unk_1C = 0;
        } else {
            var_v0_2 = func_80738A04(arg0, arg0->unk_00 + arg0->unk_08, 16000);
            if (var_v0_2 == 0) {
                return 0;
            }
            if (var_v0_2 != 16000) {
                arg0->unk_1C = 16000 - var_v0_2;
            }
        }

        arg0->unk_08 += var_v0_2;
        if (arg0->unk_08 >= 0x10A00) {
            arg0->unk_08 = 0x1000;
        }
    }

    return sp20;
}

void* func_80738E1C(unk_807C1948* arg0, s32 arg1) {
    s32 sp2C;
    s32 sp28;

    if (gAudioCtx.resetStatus != 0) {
        return NULL;
    }
    if (arg0 == NULL) {
        return NULL;
    }

    sp2C = arg0->unk_0C;
    if (arg0->unk_0C < 0x1000) {
        rmonPrintf("Now IDLE 64DD\n");
        arg0->unk_0C += arg1;
        if (arg0->unk_0C > 0x1000) {
            if (arg0->unk_2C == 0) {
                arg0->unk_0C -= arg1;
            } else {
                arg0->unk_0C = 0x1000;
            }
        }
        if (func_80738CA8(arg0) == 1) {
            arg0->unk_2C = 1;
        }
        return NULL;
    }

    arg0->unk_0C += arg1;

    if (arg0->unk_0C >= 0x10A01) {
        sp28 = 0x10A00 - sp2C;
        Audio_InvalDCache(arg0->unk_00 + sp2C, sp28);
        bcopy(arg0->unk_00 + sp2C, (arg0->unk_00 - sp28) + 0x1000, sp28);
        Audio_WritebackDCache((arg0->unk_00 - sp28) + 0x1000, sp28);
        sp2C = 0x1000 - sp28;
    }
    if (arg0->unk_0C >= 0x10A00) {
        arg0->unk_0C -= 64000;
    }

    func_80738CA8(arg0);
    return arg0->unk_00 + sp2C;
}
