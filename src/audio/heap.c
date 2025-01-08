#include "global.h"
#include "audio.h"

static char D_800D1130[] = "Warning:Kill Note  %x \n";
static char D_800D1148[] = "Kill Voice %d (ID %d) %d\n";
static char D_800D1164[] = "Warning: Running Sequence's data disappear!\n";
static char D_800D1194[] = "%x %x %x\n";
static char D_800D11A0[] = "Audio:Memory:Heap OverFlow : Not Allocate %d!\n";
static char D_800D11D0[] = "%x %x %x\n";
static char D_800D11DC[] = "Audio:Memory:Heap OverFlow : Not Allocate %d!\n";
static char D_800D120C[] = "Audio:Memory:DataHeap Not Allocate \n";
static char D_800D1234[] = "StayHeap Not Allocate %d\n";
static char D_800D1250[] = "AutoHeap Not Allocate %d\n";
static char D_800D126C[] = "Status ID0 : %d  ID1 : %d\n";
static char D_800D1288[] = "id 0 is Stopping\n";
static char D_800D129C[] = "id 0 is Stop\n";
static char D_800D12AC[] = "id 1 is Stopping\n";
static char D_800D12C0[] = "id 1 is Stop\n";
static char D_800D12D0[] = "WARNING: NO FREE AUTOSEQ AREA.\n";
static char D_800D12F0[] = "WARNING: NO STOP AUTO AREA.\n";
static char D_800D1310[] = "         AND TRY FORCE TO STOP SIDE \n";
static char D_800D1338[] = "Check ID0  (seq ID %d) Useing ...\n";
static char D_800D135C[] = "Check ID1  (seq ID %d) Useing ...\n";
static char D_800D1380[] = "No Free Seq area.\n";
static char D_800D1394[] = "CH %d: ID %d\n";
static char D_800D13A4[] = "TWO SIDES ARE LOADING... ALLOC CANCELED.\n";
static char D_800D13D0[] = "WARNING: Before Area Overlaid After.";
static char D_800D13F8[] = "WARNING: After Area Overlaid Before.";
static char D_800D1420[] = "MEMORY:SzHeapAlloc ERROR: sza->side %d\n";
static char D_800D1448[] = "Audio:MEMORY:SzHeap Overflow error. (%d bytes)\n";
static char D_800D1478[] = "Auto Heap Unhit for ID %d\n";
static char D_800D1494[] = "Heap Reconstruct Start %x\n";
static char D_800D14B0[] = "---------------------------------------TEMPO %d %f\n";
static char D_800D14E4[] = "%f \n";
static char D_800D14EC[] = "%f \n";
static char D_800D14F4[] = "AHPBASE %x\n";
static char D_800D1500[] = "AHPCUR  %x\n";
static char D_800D150C[] = "HeapTop %x\n";
static char D_800D1518[] = "SynoutRate %d / %d \n";
static char D_800D1530[] = "FXSIZE %d\n";
static char D_800D153C[] = "FXCOMP %d\n";
static char D_800D1548[] = "FXDOWN %d\n";
static char D_800D1554[] = "WaveCacheLen: %d\n";
static char D_800D1568[] = "SpecChange Finished\n";
static char D_800D1580[] = "Warning:Emem Over,not alloc %d\n";
static char D_800D15A0[] = "Single AutoSize %d\n";
static char D_800D15B4[] = "Single Ptr %x\n";
static char D_800D15C4[] = "Request--------Single-Auto, %d\n";
static char D_800D15E4[] = "Retry %x, %x, len %x\n";
static char D_800D15FC[] = "DMAing list %d is killed.\n";
static char D_800D1618[] = "Try Kill %d \n";
static char D_800D1628[] = "Try Kill %x %x\n";
static char D_800D1638[] = "Try Kill %x %x %x\n";
static char D_800D164C[] = "Rom back %x %x \n";
static char D_800D1660[] = "Error sw NULL \n";
static char D_800D1670[] = "Request--------Single-Stay, %d\n";
static char D_800D1690[] = "Try Kill %d \n";
static char D_800D16A0[] = "Try Kill %x %x\n";
static char D_800D16B0[] = "Try Kill %x %x %x\n";

#define CALCULATE_ADSR_DECAY(scaleInv) ((256.0f * gAudioBufferParams.ticksPerUpdateInvScaled) / (scaleInv))

/**
 * Initialize the decay rate table used for decaying notes as part of adsr
 */
void AudioHeap_InitAdsrDecayTable(void) {
    s32 i;

    gAdsrDecayTable[255] = CALCULATE_ADSR_DECAY(0.25f);
    gAdsrDecayTable[254] = CALCULATE_ADSR_DECAY(0.33f);
    gAdsrDecayTable[253] = CALCULATE_ADSR_DECAY(0.5f);
    gAdsrDecayTable[252] = CALCULATE_ADSR_DECAY(0.66f);
    gAdsrDecayTable[251] = CALCULATE_ADSR_DECAY(0.75f);

    for (i = 128; i < 251; i++) {
        gAdsrDecayTable[i] = CALCULATE_ADSR_DECAY(251 - i);
    }

    for (i = 16; i < 128; i++) {
        gAdsrDecayTable[i] = CALCULATE_ADSR_DECAY(60 + (128 - i) * 4.0f);
    }

    for (i = 1; i < 16; i++) {
        gAdsrDecayTable[i] = CALCULATE_ADSR_DECAY(480 + (15 - i) * 60.0f);
    }

    gAdsrDecayTable[0] = 0.0f;
}

void AudioHeap_ResetLoadStatus(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gFontLoadStatus); i++) {
        if (gFontLoadStatus[i] != LOAD_STATUS_PERMANENTLY_LOADED) {
            gFontLoadStatus[i] = LOAD_STATUS_NOT_LOADED;
        }
    }

    for (i = 0; i < ARRAY_COUNT(gSampleFontLoadStatus); i++) {
        if (gSampleFontLoadStatus[i] != LOAD_STATUS_PERMANENTLY_LOADED) {
            gSampleFontLoadStatus[i] = LOAD_STATUS_NOT_LOADED;
        }
    }

    for (i = 0; i < ARRAY_COUNT(gSeqLoadStatus); i++) {
        if (gSeqLoadStatus[i] != LOAD_STATUS_PERMANENTLY_LOADED) {
            gSeqLoadStatus[i] = LOAD_STATUS_NOT_LOADED;
        }
    }
}

void AudioHeap_DiscardFont(s32 fontId) {
    s32 i;

    for (i = 0; i < gNumNotes; i++) {
        Note* note = &gNotes[i];

        if (note->playbackState.fontId == fontId) {
            if (note->playbackState.unk_04 == 0 && note->playbackState.priority != 0) {
                note->playbackState.parentLayer->enabled = false;
                note->playbackState.parentLayer->finished = true;
            }
            Audio_NoteDisable(note);
            Audio_AudioListRemove(note);
            AudioSeq_AudioListPushBack(&gNoteFreeLists.disabled, &note->listItem);
        }
    }
}

void AudioHeap_DiscardSequence(s32 seqId) {
    s32 i;

    for (i = 0; i < gAudioBufferParams.numSequencePlayers; i++) {
        if (gSeqPlayers[i].enabled && gSeqPlayers[i].seqId == seqId) {
            AudioSeq_SequencePlayerDisable(&gSeqPlayers[i]);
        }
    }
}

void* AudioHeap_AllocZeroed(AudioAllocPool* pool, size_t size) {
    size_t aligned = ALIGN16(size);
    u8* ramAddr = pool->curRamAddr;
    u8* ptr;

    if (pool->startRamAddr + pool->size >= pool->curRamAddr + aligned) {
        pool->curRamAddr += aligned;
        for (ptr = ramAddr; ptr < pool->curRamAddr; ptr++) {
            *ptr = 0;
        }
    } else {
        return NULL;
    }
    pool->numEntries++;
    return ramAddr;
}

void* AudioHeap_Alloc(AudioAllocPool* pool, size_t size) {
    size_t aligned = ALIGN16(size);
    u8* ramAddr = pool->curRamAddr;

    if (pool->startRamAddr + pool->size >= pool->curRamAddr + aligned) {
        pool->curRamAddr += aligned;
    } else {
        return NULL;
    }
    pool->numEntries++;
    return ramAddr;
}

void AudioHeap_InitPool(AudioAllocPool* pool, void* ramAddr, size_t size) {
    pool->curRamAddr = pool->startRamAddr = (u8*) ALIGN16((uintptr_t) ramAddr);
    pool->size = size - ((uintptr_t) ramAddr & 0xF);
    pool->numEntries = 0;
}

void AudioHeap_InitPersistentCache(AudioPersistentCache* persistent) {
    persistent->pool.numEntries = 0;
    persistent->numEntries = 0;
    persistent->pool.curRamAddr = persistent->pool.startRamAddr;
}

void AudioHeap_InitTemporaryCache(AudioTemporaryCache* temporary) {
    temporary->pool.numEntries = 0;
    temporary->pool.curRamAddr = temporary->pool.startRamAddr;
    temporary->nextSide = 0;
    temporary->entries[0].ramAddr = temporary->pool.startRamAddr;
    temporary->entries[1].ramAddr = temporary->pool.startRamAddr + temporary->pool.size;
    temporary->entries[0].id = -1;
    temporary->entries[1].id = -1;
}

void AudioHeap_ResetPool(AudioAllocPool* pool) {
    pool->numEntries = 0;
    pool->curRamAddr = pool->startRamAddr;
}

void AudioHeap_InitMainPools(size_t initPoolSize) {
    AudioHeap_InitPool(&gInitPool, gAudioHeap, initPoolSize);
    AudioHeap_InitPool(&gSessionPool, gAudioHeap + initPoolSize, gAudioHeapSize - initPoolSize);
    gExternalPool.startRamAddr = NULL;
}

void AudioHeap_InitSessionPools(AudioSessionPoolSplit* split) {
    gSessionPool.curRamAddr = gSessionPool.startRamAddr;
    AudioHeap_InitPool(&gMiscPool, AudioHeap_Alloc(&gSessionPool, split->miscPoolSize), split->miscPoolSize);
    AudioHeap_InitPool(&gCachePool, AudioHeap_Alloc(&gSessionPool, split->cachePoolSize), split->cachePoolSize);
}

void AudioHeap_InitCachePools(AudioCachePoolSplit* split) {
    gCachePool.curRamAddr = gCachePool.startRamAddr;
    AudioHeap_InitPool(&gPersistentCommonPool, AudioHeap_Alloc(&gCachePool, split->persistentCommonPoolSize),
                       split->persistentCommonPoolSize);
    AudioHeap_InitPool(&gTemporaryCommonPool, AudioHeap_Alloc(&gCachePool, split->temporaryCommonPoolSize),
                       split->temporaryCommonPoolSize);
}

void AudioHeap_InitPersistentPoolsAndCaches(AudioCommonPoolSplit* split) {
    gPersistentCommonPool.curRamAddr = gPersistentCommonPool.startRamAddr;
    AudioHeap_InitPool(&gSeqCache.persistent.pool, AudioHeap_Alloc(&gPersistentCommonPool, split->seqCacheSize),
                       split->seqCacheSize);
    AudioHeap_InitPool(&gFontCache.persistent.pool, AudioHeap_Alloc(&gPersistentCommonPool, split->fontCacheSize),
                       split->fontCacheSize);
    AudioHeap_InitPool(&gSampleBankCache.persistent.pool,
                       AudioHeap_Alloc(&gPersistentCommonPool, split->sampleBankCacheSize), split->sampleBankCacheSize);
    AudioHeap_InitPersistentCache(&gSeqCache.persistent);
    AudioHeap_InitPersistentCache(&gFontCache.persistent);
    AudioHeap_InitPersistentCache(&gSampleBankCache.persistent);
}

void AudioHeap_InitTemporaryPoolsAndCaches(AudioCommonPoolSplit* split) {
    gTemporaryCommonPool.curRamAddr = gTemporaryCommonPool.startRamAddr;
    AudioHeap_InitPool(&gSeqCache.temporary.pool, AudioHeap_Alloc(&gTemporaryCommonPool, split->seqCacheSize),
                       split->seqCacheSize);
    AudioHeap_InitPool(&gFontCache.temporary.pool, AudioHeap_Alloc(&gTemporaryCommonPool, split->fontCacheSize),
                       split->fontCacheSize);
    AudioHeap_InitPool(&gSampleBankCache.temporary.pool,
                       AudioHeap_Alloc(&gTemporaryCommonPool, split->sampleBankCacheSize), split->sampleBankCacheSize);
    AudioHeap_InitTemporaryCache(&gSeqCache.temporary);
    AudioHeap_InitTemporaryCache(&gFontCache.temporary);
    AudioHeap_InitTemporaryCache(&gSampleBankCache.temporary);
}

void* AudioHeap_AllocCached(s32 tableType, size_t size, s32 cache, s32 id) {
    AudioCache* loadedCache;
    AudioTemporaryCache* temporaryCache;
    AudioAllocPool* temporaryPool;
    void* persistentRamAddr;
    void* temporaryRamAddr;
    u8 loadStatusEntry0;
    u8 loadStatusEntry1;
    s32 i;
    u8* loadStatus;

    switch (tableType) {
        case SEQUENCE_TABLE:
            loadedCache = &gSeqCache;
            loadStatus = gSeqLoadStatus;
            break;

        case FONT_TABLE:
            loadedCache = &gFontCache;
            loadStatus = gFontLoadStatus;
            break;

        case SAMPLE_TABLE:
            loadedCache = &gSampleBankCache;
            loadStatus = gSampleFontLoadStatus;
            break;
    }

    if (cache == CACHE_TEMPORARY) {
        temporaryCache = &loadedCache->temporary;
        temporaryPool = &temporaryCache->pool;

        if (temporaryCache->entries[0].id == -1) {
            loadStatusEntry0 = LOAD_STATUS_NOT_LOADED;
        } else {
            loadStatusEntry0 = loadStatus[temporaryCache->entries[0].id];
        }

        if (temporaryCache->entries[1].id == -1) {
            loadStatusEntry1 = LOAD_STATUS_NOT_LOADED;
        } else {
            loadStatusEntry1 = loadStatus[temporaryCache->entries[1].id];
        }

        if (tableType == FONT_TABLE) {
            if (loadStatusEntry0 == LOAD_STATUS_MAYBE_DISCARDABLE) {
                for (i = 0; i < gNumNotes; i++) {
                    if (gNotes[i].playbackState.fontId == temporaryCache->entries[0].id &&
                        gNotes[i].noteSubEu.bitField.enabled) {
                        break;
                    }
                }

                if (i == gNumNotes) {
                    AudioLoad_SetFontLoadStatus(temporaryCache->entries[0].id, LOAD_STATUS_DISCARDABLE);
                    loadStatusEntry0 = LOAD_STATUS_DISCARDABLE;
                }
            }

            if (loadStatusEntry1 == LOAD_STATUS_MAYBE_DISCARDABLE) {
                for (i = 0; i < gNumNotes; i++) {
                    if (gNotes[i].playbackState.fontId == temporaryCache->entries[1].id &&
                        gNotes[i].noteSubEu.bitField.enabled) {
                        break;
                    }
                }

                if (i == gNumNotes) {
                    AudioLoad_SetFontLoadStatus(temporaryCache->entries[1].id, LOAD_STATUS_DISCARDABLE);
                    loadStatusEntry1 = LOAD_STATUS_DISCARDABLE;
                }
            }
        }

        if (loadStatusEntry0 == LOAD_STATUS_NOT_LOADED) {
            temporaryCache->nextSide = 0;
        } else if (loadStatusEntry1 == LOAD_STATUS_NOT_LOADED) {
            temporaryCache->nextSide = 1;
        } else if (loadStatusEntry0 == LOAD_STATUS_DISCARDABLE && loadStatusEntry1 == LOAD_STATUS_DISCARDABLE) {
            // Use the opposite side from last time.
        } else if (loadStatusEntry0 == LOAD_STATUS_DISCARDABLE) {
            temporaryCache->nextSide = 0;
        } else if (loadStatusEntry1 == LOAD_STATUS_DISCARDABLE) {
            temporaryCache->nextSide = 1;
        } else {
            // Check if there is a side which isn't in active use, if so, evict that one.
            if (tableType == SEQUENCE_TABLE) {
                if (loadStatusEntry0 == LOAD_STATUS_COMPLETE) {
                    for (i = 0; i < gAudioBufferParams.numSequencePlayers; i++) {
                        if (gSeqPlayers[i].enabled && gSeqPlayers[i].seqId == temporaryCache->entries[0].id) {
                            break;
                        }
                    }

                    if (i == gAudioBufferParams.numSequencePlayers) {
                        temporaryCache->nextSide = 0;
                        goto done;
                    }
                }

                if (loadStatusEntry1 == LOAD_STATUS_COMPLETE) {
                    for (i = 0; i < gAudioBufferParams.numSequencePlayers; i++) {
                        if (gSeqPlayers[i].enabled && gSeqPlayers[i].seqId == temporaryCache->entries[1].id) {
                            break;
                        }
                    }

                    if (i == gAudioBufferParams.numSequencePlayers) {
                        temporaryCache->nextSide = 1;
                        goto done;
                    }
                }
            } else if (tableType == FONT_TABLE) {
                if (loadStatusEntry0 == LOAD_STATUS_COMPLETE) {
                    for (i = 0; i < gNumNotes; i++) {
                        if (gNotes[i].playbackState.fontId == temporaryCache->entries[0].id &&
                            gNotes[i].noteSubEu.bitField.enabled) {
                            break;
                        }
                    }
                    if (i == gNumNotes) {
                        temporaryCache->nextSide = 0;
                        goto done;
                    }
                }

                if (loadStatusEntry1 == LOAD_STATUS_COMPLETE) {
                    for (i = 0; i < gNumNotes; i++) {
                        if (gNotes[i].playbackState.fontId == temporaryCache->entries[1].id &&
                            gNotes[i].noteSubEu.bitField.enabled) {
                            break;
                        }
                    }
                    if (i == gNumNotes) {
                        temporaryCache->nextSide = 1;
                        goto done;
                    }
                }
            }

            // No such luck. Evict the side that wasn't chosen last time, except
            // if it is being loaded into.
            if (temporaryCache->nextSide == 0) {
                if (loadStatusEntry0 == LOAD_STATUS_IN_PROGRESS) {
                    if (loadStatusEntry1 == LOAD_STATUS_IN_PROGRESS) {
                        goto fail;
                    }
                    temporaryCache->nextSide = 1;
                }
            } else {
                if (loadStatusEntry1 == LOAD_STATUS_IN_PROGRESS) {
                    if (loadStatusEntry0 == LOAD_STATUS_IN_PROGRESS) {
                        goto fail;
                    }
                    temporaryCache->nextSide = 0;
                }
            }

            if (0) {
            fail:
                // Both sides are being loaded into.
                return NULL;
            }
        }
    done:

        if (temporaryCache->entries[temporaryCache->nextSide].id != -1) {

            loadStatus[temporaryCache->entries[temporaryCache->nextSide].id] = LOAD_STATUS_NOT_LOADED;

            if (tableType == FONT_TABLE) {
                AudioHeap_DiscardFont(temporaryCache->entries[temporaryCache->nextSide].id);
            }
        }

        switch (temporaryCache->nextSide) {
            case 0:
                temporaryCache->entries[0].ramAddr = temporaryPool->startRamAddr;
                temporaryCache->entries[0].id = id;
                temporaryCache->entries[0].size = size;
                temporaryPool->curRamAddr = temporaryPool->startRamAddr + size;

                if (temporaryCache->entries[1].id != -1 &&
                    temporaryCache->entries[1].ramAddr < temporaryPool->curRamAddr) {

                    loadStatus[temporaryCache->entries[1].id] = LOAD_STATUS_NOT_LOADED;

                    switch (tableType) {
                        case SEQUENCE_TABLE:
                            AudioHeap_DiscardSequence((s32) temporaryCache->entries[1].id);
                            break;

                        case FONT_TABLE:
                            AudioHeap_DiscardFont((s32) temporaryCache->entries[1].id);
                            break;
                    }

                    temporaryCache->entries[1].id = -1;
                    temporaryCache->entries[1].ramAddr = temporaryPool->startRamAddr + temporaryPool->size;
                }

                temporaryRamAddr = temporaryCache->entries[0].ramAddr;
                break;

            case 1:
                temporaryCache->entries[1].ramAddr =
                    (u8*) ((u32) (temporaryPool->startRamAddr + temporaryPool->size - size) & ~0xF);
                temporaryCache->entries[1].id = id;
                temporaryCache->entries[1].size = size;
                if (temporaryCache->entries[0].id != -1 &&
                    temporaryCache->entries[1].ramAddr < temporaryPool->curRamAddr) {

                    loadStatus[temporaryCache->entries[0].id] = LOAD_STATUS_NOT_LOADED;
                    switch (tableType) {
                        case SEQUENCE_TABLE:
                            AudioHeap_DiscardSequence(temporaryCache->entries[0].id);
                            break;

                        case FONT_TABLE:
                            AudioHeap_DiscardFont(temporaryCache->entries[0].id);
                            break;
                    }

                    temporaryCache->entries[0].id = -1;
                    temporaryPool->curRamAddr = temporaryPool->startRamAddr;
                }
                temporaryRamAddr = temporaryCache->entries[1].ramAddr;
                break;

            default:
                return NULL;
        }

        temporaryCache->nextSide ^= 1;
        return temporaryRamAddr;
    }

    persistentRamAddr = AudioHeap_Alloc(&loadedCache->persistent.pool, size);
    loadedCache->persistent.entries[loadedCache->persistent.numEntries].ramAddr = persistentRamAddr;

    if (persistentRamAddr == NULL) {
        switch (cache) {
            case CACHE_EITHER:
                return AudioHeap_AllocCached(tableType, size, CACHE_TEMPORARY, id);
            case CACHE_TEMPORARY:
            case CACHE_PERSISTENT:
                return NULL;
        }
    }

    loadedCache->persistent.entries[loadedCache->persistent.numEntries].id = id;
    loadedCache->persistent.entries[loadedCache->persistent.numEntries].size = size;
    return loadedCache->persistent.entries[loadedCache->persistent.numEntries++].ramAddr;
}

void* AudioHeap_SearchRegularCaches(s32, s32, s32);
void* AudioHeap_SearchPermanentCache(s32, s32);

void* AudioHeap_SearchCaches(s32 tableType, s32 cache, s32 id) {
    void* ramAddr;

    ramAddr = AudioHeap_SearchPermanentCache(tableType, id);
    if (ramAddr != NULL) {
        return ramAddr;
    }
    if (cache == CACHE_PERMANENT) {
        return NULL;
    }
    return AudioHeap_SearchRegularCaches(tableType, cache, id);
}

void* AudioHeap_SearchRegularCaches(s32 tableType, s32 cache, s32 id) {
    u32 i;
    AudioCache* loadedCache;
    AudioTemporaryCache* temporary;
    AudioPersistentCache* persistent;

    switch (tableType) {
        case SEQUENCE_TABLE:
            loadedCache = &gSeqCache;
            break;

        case FONT_TABLE:
            loadedCache = &gFontCache;
            break;

        case SAMPLE_TABLE:
            loadedCache = &gSampleBankCache;
            break;
    }

    temporary = &loadedCache->temporary;
    if (cache == CACHE_TEMPORARY) {
        if (temporary->entries[0].id == id) {
            temporary->nextSide = 1;
            return temporary->entries[0].ramAddr;
        } else if (temporary->entries[1].id == id) {
            temporary->nextSide = 0;
            return temporary->entries[1].ramAddr;
        } else {
            return NULL;
        }
    }

    persistent = &loadedCache->persistent;
    for (i = 0; i < persistent->numEntries; i++) {
        if (persistent->entries[i].id == id) {
            return persistent->entries[i].ramAddr;
        }
    }

    if (cache == CACHE_EITHER) {
        return AudioHeap_SearchCaches(tableType, CACHE_TEMPORARY, id);
    }
    return NULL;
}

void AudioHeap_UpdateReverbs(void) {
    s32 i;
    s32 count = 1;
    s32 reverbIndex;

    for (reverbIndex = 0; reverbIndex < gNumSynthReverbs; reverbIndex++) {
        for (i = 0; i < count; i++) {
            gSynthReverbs[reverbIndex].decayRatio -= gSynthReverbs[reverbIndex].decayRatio / 3;
        }
    }
}

void AudioHeap_ClearCurrentAiBuffer(void) {
    s32 index = gCurAiBufIndex;
    s32 i;

    gAiBufLengths[index] = gAudioBufferParams.minAiBufferLength;

    for (i = 0; i < AIBUF_LEN; i++) {
        gAiBuffers[index][i] = 0;
    }
}

void AudioHeap_Init(void);
void AudioHeap_DiscardSampleCaches(void);

bool AudioHeap_ResetStep(void) {
    s32 i;
    s32 j;
    s32 fadeOutFactor = 1;

    switch (gResetStatus) {
        case 5:
            for (i = 0; i < gAudioBufferParams.numSequencePlayers; i++) {
                AudioSeq_SequencePlayerDisable(&gSeqPlayers[i]);
            }
            gResetFadeoutFramesLeft = 4 / fadeOutFactor;
            gResetStatus--;
            break;
        case 4:
            if (gResetFadeoutFramesLeft != 0) {
                gResetFadeoutFramesLeft--;
                AudioHeap_UpdateReverbs();
            } else {
                for (i = 0; i < gNumNotes; i++) {
                    if (gNotes[i].noteSubEu.bitField.enabled && (gNotes[i].playbackState.adsr.state != 0)) {
                        gNotes[i].playbackState.adsr.fadeOutVel = gAudioBufferParams.ticksPerUpdateInv;
                        gNotes[i].playbackState.adsr.action.asByte |= 0x10;
                    }
                }

                gResetFadeoutFramesLeft = 16 / fadeOutFactor;
                gResetStatus--;
            }
            break;
        case 3:
            if (gResetFadeoutFramesLeft != 0) {
                gResetFadeoutFramesLeft--;
                AudioHeap_UpdateReverbs();
            } else {
                gResetFadeoutFramesLeft = 4 / fadeOutFactor;
                gResetStatus--;
            }
            break;
        case 2:
            AudioHeap_ClearCurrentAiBuffer();
            if (gResetFadeoutFramesLeft != 0) {
                gResetFadeoutFramesLeft--;
            } else {
                gResetStatus--;
                AudioHeap_DiscardSampleCaches();
            }
            break;
        case 1:
            AudioHeap_Init();
            gResetStatus = 0;
            for (i = 0; i < 3; i++) {
                gAiBufLengths[i] = gAudioBufferParams.maxAiBufferLength;
                for (j = 0; j < AIBUF_LEN; j++) {
                    gAiBuffers[i][j] = 0;
                }
            }
            break;
    }
    if (gResetStatus < 3) {
        return false;
    }
    return true;
}

s32 AudioHeap_InitSampleCaches(size_t, size_t);

void AudioHeap_Init(void) {
    s32 pad[11];
    s32 i;
    s32 j;
    AudioSpec* spec = &gAudioSpecs[gSpecId];
    ReverbSettings* settings;
    SynthesisReverb* reverb;
    s16* ramAddr;
    size_t persistentSize;
    size_t temporarySize;
    size_t cachePoolSize;
    size_t miscPoolSize;

    gSampleDmaCount = 0;
    gAudioBufferParams.samplingFrequency = spec->samplingFrequency;
    gAudioBufferParams.aiSamplingFrequency = osAiSetFrequency(gAudioBufferParams.samplingFrequency);
    gAudioBufferParams.samplesPerFrameTarget = ALIGN16(gAudioBufferParams.samplingFrequency / gRefreshRate);

    gAudioBufferParams.minAiBufferLength = gAudioBufferParams.samplesPerFrameTarget - 0x10;
    gAudioBufferParams.maxAiBufferLength = gAudioBufferParams.samplesPerFrameTarget + 0x10;
    gAudioBufferParams.ticksPerUpdate = ((gAudioBufferParams.samplesPerFrameTarget + 0x10) / 208) + 1;

    gAudioBufferParams.samplesPerTick =
        (gAudioBufferParams.samplesPerFrameTarget / gAudioBufferParams.ticksPerUpdate) & ~7;
    gAudioBufferParams.samplesPerTickMax = gAudioBufferParams.samplesPerTick + 8;
    gAudioBufferParams.samplesPerTickMin = gAudioBufferParams.samplesPerTick - 8;

    gAudioBufferParams.resampleRate = 32000.0f / (s32) gAudioBufferParams.samplingFrequency;
    gAudioBufferParams.ticksPerUpdateInvScaled = (1.0f / 256.0f) / gAudioBufferParams.ticksPerUpdate;
    gAudioBufferParams.ticksPerUpdateScaled = gAudioBufferParams.ticksPerUpdate / 4.0f;
    gAudioBufferParams.ticksPerUpdateInv = 1.0f / gAudioBufferParams.ticksPerUpdate;
    gNumNotes = spec->numNotes;
    gAudioBufferParams.numSequencePlayers = spec->numSequencePlayers;
    D_80025D50 = spec->unk_14;
    gMaxTempo = (u16) ((gAudioBufferParams.ticksPerUpdate * 2880000.0f / gSeqTicksPerBeat) / gMaxTempoTvTypeFactors);
    gAudioBufferParams.count = spec->numBuffers;
    gAudioBufferParams.samplesPerFrameTarget *= gAudioBufferParams.count;
    gAudioBufferParams.maxAiBufferLength *= gAudioBufferParams.count;
    gAudioBufferParams.minAiBufferLength *= gAudioBufferParams.count;
    gAudioBufferParams.ticksPerUpdate *= gAudioBufferParams.count;
    if (gAudioBufferParams.count >= 2) {
        gAudioBufferParams.maxAiBufferLength -= 0x10;
    }
    gMaxAudioCmds = (gNumNotes * 20 * gAudioBufferParams.ticksPerUpdate) + (spec->numReverbs * 32) + 480;
    persistentSize = spec->persistentSeqCacheSize + spec->persistentFontCacheSize +
                     spec->persistentSampleBankCacheSize + spec->persistentSampleCacheSize + 0x10;
    temporarySize = spec->temporarySeqCacheSize + spec->temporaryFontCacheSize + spec->temporarySampleBankCacheSize +
                    spec->temporarySampleCacheSize + 0x10;
    cachePoolSize = persistentSize + temporarySize;
    miscPoolSize = gSessionPool.size - cachePoolSize - 0x100;
    gSessionPoolSplit.miscPoolSize = miscPoolSize;
    gSessionPoolSplit.cachePoolSize = cachePoolSize;
    AudioHeap_InitSessionPools(&gSessionPoolSplit);
    gCachePoolSplit.persistentCommonPoolSize = persistentSize;
    gCachePoolSplit.temporaryCommonPoolSize = temporarySize;
    AudioHeap_InitCachePools(&gCachePoolSplit);
    gPersistentCommonPoolSplit.seqCacheSize = spec->persistentSeqCacheSize;
    gPersistentCommonPoolSplit.fontCacheSize = spec->persistentFontCacheSize;
    gPersistentCommonPoolSplit.sampleBankCacheSize = spec->persistentSampleBankCacheSize;
    AudioHeap_InitPersistentPoolsAndCaches(&gPersistentCommonPoolSplit);
    gTemporaryCommonPoolSplit.seqCacheSize = spec->temporarySeqCacheSize;
    gTemporaryCommonPoolSplit.fontCacheSize = spec->temporaryFontCacheSize;
    gTemporaryCommonPoolSplit.sampleBankCacheSize = spec->temporarySampleBankCacheSize;
    AudioHeap_InitTemporaryPoolsAndCaches(&gTemporaryCommonPoolSplit);
    AudioHeap_InitSampleCaches(spec->persistentSampleCacheSize, spec->temporarySampleCacheSize);
    if (gExternalPool.startRamAddr != NULL) {
        gExternalPool.curRamAddr = gExternalPool.startRamAddr;
    }
    AudioHeap_ResetLoadStatus();
    gNotes = AudioHeap_AllocZeroed(&gMiscPool, gNumNotes * sizeof(Note));
    Audio_NoteInitAll();
    Audio_InitNoteFreeList();
    gNoteSubsEu = AudioHeap_AllocZeroed(&gMiscPool, gAudioBufferParams.ticksPerUpdate * gNumNotes * sizeof(NoteSubEu));
    for (j = 0; j != 2; j++) {
        gAbiCmdBuffs[j] = AudioHeap_AllocZeroed(&gMiscPool, gMaxAudioCmds * 8);
    }
    gAdsrDecayTable = AudioHeap_Alloc(&gMiscPool, 0x100 * sizeof(f32));
    AudioHeap_InitAdsrDecayTable();
    for (i = 0; i < ARRAY_COUNT(gSynthReverbs); i++) {
        gSynthReverbs[i].useReverb = 0;
    }
    gNumSynthReverbs = spec->numReverbs;
    for (i = 0; i < gNumSynthReverbs; i++) {
        settings = &spec->reverbSettings[i];
        reverb = &gSynthReverbs[i];
        reverb->downsampleRate = settings->downsampleRate;
        reverb->windowSize = settings->windowSize * 64;
        reverb->windowSize /= reverb->downsampleRate;
        reverb->decayRatio = settings->decayRatio;
        reverb->volume = settings->volume;
        reverb->leakRtL = settings->leakRtL;
        reverb->leakLtR = settings->leakLtR;
        reverb->unk_05 = settings->unk_0A;
        reverb->unk_08 = settings->unk_0C;
        reverb->useReverb = 8;

        reverb->leftRingBuf = AudioHeap_AllocZeroed(&gMiscPool, reverb->windowSize * 2);
        reverb->rightRingBuf = AudioHeap_AllocZeroed(&gMiscPool, reverb->windowSize * 2);
        reverb->nextRingBufPos = 0;
        reverb->unk_20 = 0;
        reverb->curFrame = 0;
        reverb->bufSizePerChan = reverb->windowSize;
        reverb->framesToIgnore = 2;
        reverb->resampleFlags = 1;
        reverb->tunedSample.sample = &reverb->sample;
        reverb->sample.loop = &reverb->loop;
        reverb->tunedSample.tuning = 1.0f;
        reverb->sample.codec = CODEC_SMALL_ADPCM;
        reverb->sample.medium = MEDIUM_RAM;
        reverb->sample.size = reverb->windowSize * SAMPLE_SIZE;
        reverb->sample.sampleAddr = (u8*) reverb->leftRingBuf;
        reverb->loop.start = 0;
        reverb->loop.count = 1;
        reverb->loop.end = reverb->windowSize;
    }

    AudioSeq_InitSequencePlayers();

    for (j = 0; j < gAudioBufferParams.numSequencePlayers; j++) {
        AudioSeq_InitSequencePlayerChannels(j);
        AudioSeq_ResetSequencePlayer(j);
    }

    AudioLoad_InitSampleDmaBuffers(gNumNotes);
    gPreloadSampleStackTop = 0;
    D_80025D54 = 0x1000;
    AudioLoad_LoadPermanentSamples();
    osWritebackDCacheAll();
}

void* AudioHeap_SearchPermanentCache(s32 tableType, s32 id) {
    s32 i;

    for (i = 0; i < gPermanentCache.pool.numEntries; i++) {
        if ((tableType == gPermanentCache.entries[i].tableType) && (id == gPermanentCache.entries[i].id)) {
            return gPermanentCache.entries[i].ramAddr;
        }
    }
    return NULL;
}

u8* AudioHeap_AllocPermanent(s32 tableType, s32 id, u32 size) {
    u8* ramAddr;
    s32 index = gPermanentCache.pool.numEntries;

    ramAddr = AudioHeap_Alloc(&gPermanentCache.pool, size);
    gPermanentCache.entries[index].ramAddr = ramAddr;

    if (ramAddr == NULL) {
        return NULL;
    }

    gPermanentCache.entries[index].tableType = tableType;
    gPermanentCache.entries[index].id = id;
    gPermanentCache.entries[index].size = size;
}

SampleCacheEntry* AudioHeap_AllocTemporarySampleCacheEntry(size_t);
SampleCacheEntry* AudioHeap_AllocPersistentSampleCacheEntry(size_t);

void* AudioHeap_AllocTemporarySampleCache(size_t size, s32 fontId, void* sampleAddr, s8 medium) {
    SampleCacheEntry* entry = AudioHeap_AllocTemporarySampleCacheEntry(size);

    if (entry != NULL) {
        entry->sampleBankId = fontId;
        entry->sampleAddr = sampleAddr;
        entry->origMedium = medium;
        return entry->allocatedAddr;
    } else {
        return NULL;
    }
}

void* AudioHeap_AllocPersistentSampleCache(size_t size, s32 fontId, void* sampleAddr, s8 medium) {
    SampleCacheEntry* entry = AudioHeap_AllocPersistentSampleCacheEntry(size);

    if (entry != NULL) {
        entry->sampleBankId = fontId;
        entry->sampleAddr = sampleAddr;
        entry->origMedium = medium;
        return entry->allocatedAddr;
    } else {
        return NULL;
    }
}

s32 AudioHeap_InitSampleCaches(size_t persistentSampleCacheSize, size_t temporarySampleCacheSize) {
    void* ramAddr;

    ramAddr = AudioHeap_Alloc(&gPersistentCommonPool, persistentSampleCacheSize);
    if (ramAddr == NULL) {
        gPersistentSampleCache.pool.size = 0;
    } else {
        AudioHeap_InitPool(&gPersistentSampleCache.pool, ramAddr, persistentSampleCacheSize);
    }
    ramAddr = AudioHeap_Alloc(&gTemporaryCommonPool, temporarySampleCacheSize);
    if (ramAddr == NULL) {
        gTemporarySampleCache.pool.size = 0;
    } else {
        AudioHeap_InitPool(&gTemporarySampleCache.pool, ramAddr, temporarySampleCacheSize);
    }
    gPersistentSampleCache.numEntries = 0;
    gTemporarySampleCache.numEntries = 0;
}

void AudioHeap_DiscardSampleCacheEntry(SampleCacheEntry* entry);

SampleCacheEntry* AudioHeap_AllocTemporarySampleCacheEntry(size_t size) {
    u8* endRamAddr;
    u8* old;
    u8* ramAddr;
    s32 i;
    s32 entryIdx;
    SampleCacheEntry* entry;
    AudioPreloadReq* preload;
    AudioSampleCache* cache;
    u8* allocAfter;
    u8* startRamAddr;
    u8* allocBefore;

    cache = &gTemporarySampleCache;
    allocBefore = cache->pool.curRamAddr;
    ramAddr = AudioHeap_Alloc(&cache->pool, size);
    if (ramAddr == NULL) {
        old = cache->pool.curRamAddr;
        cache->pool.curRamAddr = cache->pool.startRamAddr;
        ramAddr = AudioHeap_Alloc(&cache->pool, size);
        if (ramAddr == NULL) {
            cache->pool.curRamAddr = old;
            return NULL;
        }
        allocBefore = cache->pool.startRamAddr;
    }
    allocAfter = cache->pool.curRamAddr;
    entryIdx = -1;
    for (i = 0; i < gPreloadSampleStackTop; i++) {
        preload = &gPreloadSampleStack[i];
        if (preload->isFree == 0) {
            startRamAddr = preload->ramAddr;
            endRamAddr = preload->ramAddr + preload->sample->size - 1;
            if ((endRamAddr < allocBefore) && (startRamAddr < allocBefore)) {
                continue;
            }
            if ((endRamAddr >= allocAfter) && (startRamAddr >= allocAfter)) {
                continue;
            }
            preload->isFree = 1;
        }
    }
    for (i = 0; i < cache->numEntries; i++) {
        if (cache->entries[i].inUse == 0) {
            continue;
        }
        startRamAddr = cache->entries[i].allocatedAddr;
        endRamAddr = startRamAddr + cache->entries[i].size - 1;
        if ((endRamAddr < allocBefore) && (startRamAddr < allocBefore)) {
            continue;
        }
        if ((endRamAddr >= allocAfter) && (startRamAddr >= allocAfter)) {
            continue;
        }
        AudioHeap_DiscardSampleCacheEntry(&cache->entries[i]);
        if (entryIdx == -1) {
            entryIdx = i;
        }
    }
    if (entryIdx == -1) {
        entryIdx = cache->numEntries++;
    }
    entry = &cache->entries[entryIdx];
    entry->inUse = 1;
    entry->allocatedAddr = ramAddr;
    entry->size = size;
    return entry;
}

void AudioHeap_UnapplySampleCache(SampleCacheEntry* entry, Sample* sample);

void AudioHeap_DiscardSampleCacheEntry(SampleCacheEntry* entry) {
    s32 fontId;
    s32 numFonts;
    Drum* drum;
    Instrument* instrument;
    s32 instId;
    s32 drumId;
    s32 sampleBankId2;
    s32 sampleBankId1;

    numFonts = gSoundFontTable->numEntries;
    for (fontId = 0; fontId < numFonts; fontId++) {
        sampleBankId1 = gSoundFontList[fontId].sampleBankId1;
        sampleBankId2 = gSoundFontList[fontId].sampleBankId2;
        if (((sampleBankId1 != SAMPLES_NONE) && (entry->sampleBankId == sampleBankId1)) ||
            ((sampleBankId2 != SAMPLES_NONE) && (entry->sampleBankId == sampleBankId2)) ||
            (entry->sampleBankId == SAMPLES_SFX)) {
            if ((AudioHeap_SearchCaches(FONT_TABLE, CACHE_EITHER, fontId) != NULL) &&
                AudioLoad_IsFontLoadComplete(fontId)) {
                for (instId = 0; instId < gSoundFontList[fontId].numInstruments; instId++) {
                    instrument = Audio_GetInstrument(fontId, instId);
                    if (instrument != NULL) {
                        if (instrument->normalRangeLo != 0) {
                            AudioHeap_UnapplySampleCache(entry, instrument->lowPitchTunedSample.sample);
                        }
                        if (instrument->normalRangeHi != 0x7F) {
                            AudioHeap_UnapplySampleCache(entry, instrument->highPitchTunedSample.sample);
                        }
                        AudioHeap_UnapplySampleCache(entry, instrument->normalPitchTunedSample.sample);
                    }
                }
                for (drumId = 0; drumId < gSoundFontList[fontId].numDrums; drumId++) {
                    drum = Audio_GetDrum(fontId, drumId);
                    if (drum != NULL) {
                        // FAKE
                        if (1) {
                            AudioHeap_UnapplySampleCache(entry, drum->tunedSample.sample);
                        }
                    }
                }
            }
        }
    }
}

void AudioHeap_UnapplySampleCache(SampleCacheEntry* entry, Sample* sample) {
    if (sample != NULL && sample->sampleAddr == entry->allocatedAddr) {
        sample->sampleAddr = entry->sampleAddr;
        sample->medium = entry->origMedium;
    }
}

SampleCacheEntry* AudioHeap_AllocPersistentSampleCacheEntry(size_t size) {
    AudioSampleCache* cache = &gPersistentSampleCache;
    SampleCacheEntry* entry;
    u8* ramAddr;

    ramAddr = AudioHeap_Alloc(&cache->pool, size);
    if (ramAddr == NULL) {
        return NULL;
    }
    entry = &cache->entries[cache->numEntries];
    entry->inUse = 1;
    entry->allocatedAddr = ramAddr;
    entry->size = size;
    cache->numEntries++;
    return entry;
}

void AudioHeap_DiscardSampleCaches(void) {
    s32 fontId;
    s32 i;
    s32 numFonts = gSoundFontTable->numEntries;
    s32 pad[5];
    u32 sampleBankId1;
    s32 sampleBankId2;
    s32 instId;
    s32 drumId;
    Drum* drum;
    Instrument* instrument;
    SampleCacheEntry* entry;

    for (fontId = 0; fontId < numFonts; fontId++) {
        sampleBankId1 = gSoundFontList[fontId].sampleBankId1;
        sampleBankId2 = gSoundFontList[fontId].sampleBankId2;
        if ((sampleBankId1 != SAMPLES_NONE) || (sampleBankId2 != SAMPLES_NONE)) {
            if (AudioHeap_SearchCaches(FONT_TABLE, CACHE_PERMANENT, fontId) != NULL &&
                AudioLoad_IsFontLoadComplete(fontId)) {

                for (i = 0; i < gPersistentSampleCache.numEntries; i++) {
                    entry = &gPersistentSampleCache.entries[i];
                    if (sampleBankId1 != entry->sampleBankId && sampleBankId2 != entry->sampleBankId &&
                        entry->sampleBankId != SAMPLES_SFX) {
                        break;
                    }
                    for (instId = 0; instId < gSoundFontList[fontId].numInstruments; instId++) {
                        instrument = Audio_GetInstrument(fontId, instId);
                        if (instrument != NULL) {
                            if (instrument->normalRangeLo != 0) {
                                AudioHeap_UnapplySampleCache(entry, instrument->lowPitchTunedSample.sample);
                            }
                            if (instrument->normalRangeHi != 0x7F) {
                                AudioHeap_UnapplySampleCache(entry, instrument->highPitchTunedSample.sample);
                            }
                            AudioHeap_UnapplySampleCache(entry, instrument->normalPitchTunedSample.sample);
                        }
                    }
                    for (drumId = 0; drumId < gSoundFontList[fontId].numDrums; drumId++) {
                        drum = Audio_GetDrum(fontId, drumId);
                        if (drum != NULL) {
                            AudioHeap_UnapplySampleCache(entry, drum->tunedSample.sample);
                        }
                    }
                }
            }
        }
    }
}
