#include "global.h"
#include "audio.h"

#define CALCULATE_ADSR_DECAY(scaleInv) ((256.0f * gAudioBufferParams.ticksPerUpdateInvScaled) / (scaleInv))

/**
 * Initialize the decay rate table used for decaying notes as part of adsr
 */
void func_800B2460(void) {
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

void func_800B27D4(void) {
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

void func_800B289C(s32 fontId) {
    s32 i;

    for (i = 0; i < gNumNotes; i++) {
        Note* note = &gNotes[i];

        if (note->playbackState.fontId == fontId) {
            if (note->playbackState.unk_04 == 0 && note->playbackState.priority != 0) {
                note->playbackState.parentLayer->enabled = false;
                note->playbackState.parentLayer->finished = true;
            }
            func_800AA8E4(note);
            func_800AB380(note);
            func_800AC7F0(&gNoteFreeLists.disabled, &note->listItem);
        }
    }
}

void func_800B2988(s32 seqId) {
    s32 i;

    for (i = 0; i < gAudioBufferParams.numSequencePlayers; i++) {
        if (gSeqPlayers[i].enabled && gSeqPlayers[i].seqId == seqId) {
            func_800AC744(&gSeqPlayers[i]);
        }
    }
}

void* func_800B2A0C(AudioAllocPool* pool, size_t size) {
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

void* func_800B2A8C(AudioAllocPool* pool, size_t size) {
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

void func_800B2AE4(AudioAllocPool* pool, void* ramAddr, size_t size) {
    pool->curRamAddr = pool->startRamAddr = (u8*) ALIGN16((uintptr_t) ramAddr);
    pool->size = size - ((uintptr_t) ramAddr & 0xF);
    pool->numEntries = 0;
}

void func_800B2B0C(AudioPersistentCache* persistent) {
    persistent->pool.numEntries = 0;
    persistent->numEntries = 0;
    persistent->pool.curRamAddr = persistent->pool.startRamAddr;
}

void func_800B2B20(AudioTemporaryCache* temporary) {
    temporary->pool.numEntries = 0;
    temporary->pool.curRamAddr = temporary->pool.startRamAddr;
    temporary->nextSide = 0;
    temporary->entries[0].ramAddr = temporary->pool.startRamAddr;
    temporary->entries[1].ramAddr = temporary->pool.startRamAddr + temporary->pool.size;
    temporary->entries[0].id = -1;
    temporary->entries[1].id = -1;
}

void func_800B2B50(AudioAllocPool* pool) {
    pool->numEntries = 0;
    pool->curRamAddr = pool->startRamAddr;
}

void func_800B2B60(size_t initPoolSize) {
    func_800B2AE4(&gInitPool, gAudioHeap, initPoolSize);
    func_800B2AE4(&gSessionPool, gAudioHeap + initPoolSize, gAudioHeapSize - initPoolSize);
    gExternalPool.startRamAddr = NULL;
}

void func_800B2BC0(AudioSessionPoolSplit* split) {
    gSessionPool.curRamAddr = gSessionPool.startRamAddr;
    func_800B2AE4(&gMiscPool, func_800B2A8C(&gSessionPool, split->miscPoolSize), split->miscPoolSize);
    func_800B2AE4(&gCachePool, func_800B2A8C(&gSessionPool, split->cachePoolSize), split->cachePoolSize);
}

void func_800B2C3C(AudioCachePoolSplit* split) {
    gCachePool.curRamAddr = gCachePool.startRamAddr;
    func_800B2AE4(&gPersistentCommonPool, func_800B2A8C(&gCachePool, split->persistentCommonPoolSize),
                  split->persistentCommonPoolSize);
    func_800B2AE4(&gTemporaryCommonPool, func_800B2A8C(&gCachePool, split->temporaryCommonPoolSize),
                  split->temporaryCommonPoolSize);
}

void func_800B2CB8(AudioCommonPoolSplit* split) {
    gPersistentCommonPool.curRamAddr = gPersistentCommonPool.startRamAddr;
    func_800B2AE4(&gSeqCache.persistent.pool, func_800B2A8C(&gPersistentCommonPool, split->seqCacheSize),
                  split->seqCacheSize);
    func_800B2AE4(&gFontCache.persistent.pool, func_800B2A8C(&gPersistentCommonPool, split->fontCacheSize),
                  split->fontCacheSize);
    func_800B2AE4(&gSampleBankCache.persistent.pool, func_800B2A8C(&gPersistentCommonPool, split->sampleBankCacheSize),
                  split->sampleBankCacheSize);
    func_800B2B0C(&gSeqCache.persistent);
    func_800B2B0C(&gFontCache.persistent);
    func_800B2B0C(&gSampleBankCache.persistent);
}

void func_800B2D74(AudioCommonPoolSplit* split) {
    gTemporaryCommonPool.curRamAddr = gTemporaryCommonPool.startRamAddr;
    func_800B2AE4(&gSeqCache.temporary.pool, func_800B2A8C(&gTemporaryCommonPool, split->seqCacheSize),
                  split->seqCacheSize);
    func_800B2AE4(&gFontCache.temporary.pool, func_800B2A8C(&gTemporaryCommonPool, split->fontCacheSize),
                  split->fontCacheSize);
    func_800B2AE4(&gSampleBankCache.temporary.pool, func_800B2A8C(&gTemporaryCommonPool, split->sampleBankCacheSize),
                  split->sampleBankCacheSize);
    func_800B2B20(&gSeqCache.temporary);
    func_800B2B20(&gFontCache.temporary);
    func_800B2B20(&gSampleBankCache.temporary);
}

void* func_800B2E30(s32 tableType, size_t size, s32 cache, s32 id) {
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
                    func_800AF33C(temporaryCache->entries[0].id, LOAD_STATUS_DISCARDABLE);
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
                    func_800AF33C(temporaryCache->entries[1].id, LOAD_STATUS_DISCARDABLE);
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
                func_800B289C(temporaryCache->entries[temporaryCache->nextSide].id);
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
                            func_800B2988((s32) temporaryCache->entries[1].id);
                            break;

                        case FONT_TABLE:
                            func_800B289C((s32) temporaryCache->entries[1].id);
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
                            func_800B2988(temporaryCache->entries[0].id);
                            break;

                        case FONT_TABLE:
                            func_800B289C(temporaryCache->entries[0].id);
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

    persistentRamAddr = func_800B2A8C(&loadedCache->persistent.pool, size);
    loadedCache->persistent.entries[loadedCache->persistent.numEntries].ramAddr = persistentRamAddr;

    if (persistentRamAddr == NULL) {
        switch (cache) {
            case CACHE_EITHER:
                return func_800B2E30(tableType, size, CACHE_TEMPORARY, id);
            case CACHE_TEMPORARY:
            case CACHE_PERSISTENT:
                return NULL;
        }
    }

    loadedCache->persistent.entries[loadedCache->persistent.numEntries].id = id;
    loadedCache->persistent.entries[loadedCache->persistent.numEntries].size = size;
    return loadedCache->persistent.entries[loadedCache->persistent.numEntries++].ramAddr;
}

void* func_800B358C(s32, s32, s32);
void* func_800B4278(s32, s32);

void* func_800B3534(s32 tableType, s32 cache, s32 id) {
    void* ramAddr;

    ramAddr = func_800B4278(tableType, id);
    if (ramAddr != NULL) {
        return ramAddr;
    }
    if (cache == CACHE_PERMANENT) {
        return NULL;
    }
    return func_800B358C(tableType, cache, id);
}

void* func_800B358C(s32 tableType, s32 cache, s32 id) {
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
        return func_800B3534(tableType, CACHE_TEMPORARY, id);
    }
    return NULL;
}

void func_800B3698(void) {
    s32 i;
    s32 count = 1;
    s32 reverbIndex;

    for (reverbIndex = 0; reverbIndex < gNumSynthReverbs; reverbIndex++) {
        for (i = 0; i < count; i++) {
            gSynthReverbs[reverbIndex].decayRatio -= gSynthReverbs[reverbIndex].decayRatio / 3;
        }
    }
}

void func_800B3834(void) {
    s32 index = gCurAiBufIndex;
    s32 i;

    gAiBufLengths[index] = gAudioBufferParams.minAiBufferLength;

    for (i = 0; i < AIBUF_LEN; i++) {
        gAiBuffers[index][i] = 0;
    }
}

void func_800B3B68(void);
void func_800B49A8(void);

bool func_800B38AC(void) {
    s32 i;
    s32 j;
    s32 fadeOutFactor = 1;

    switch (gResetStatus) {
        case 5:
            for (i = 0; i < gAudioBufferParams.numSequencePlayers; i++) {
                func_800AC744(&gSeqPlayers[i]);
            }
            gResetFadeoutFramesLeft = 4 / fadeOutFactor;
            gResetStatus--;
            break;
        case 4:
            if (gResetFadeoutFramesLeft != 0) {
                gResetFadeoutFramesLeft--;
                func_800B3698();
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
                func_800B3698();
            } else {
                gResetFadeoutFramesLeft = 4 / fadeOutFactor;
                gResetStatus--;
            }
            break;
        case 2:
            func_800B3834();
            if (gResetFadeoutFramesLeft != 0) {
                gResetFadeoutFramesLeft--;
            } else {
                gResetStatus--;
                func_800B49A8();
            }
            break;
        case 1:
            func_800B3B68();
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

s32 func_800B43F0(size_t, size_t);

void func_800B3B68(void) {
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
    func_800B2BC0(&gSessionPoolSplit);
    gCachePoolSplit.persistentCommonPoolSize = persistentSize;
    gCachePoolSplit.temporaryCommonPoolSize = temporarySize;
    func_800B2C3C(&gCachePoolSplit);
    gPersistentCommonPoolSplit.seqCacheSize = spec->persistentSeqCacheSize;
    gPersistentCommonPoolSplit.fontCacheSize = spec->persistentFontCacheSize;
    gPersistentCommonPoolSplit.sampleBankCacheSize = spec->persistentSampleBankCacheSize;
    func_800B2CB8(&gPersistentCommonPoolSplit);
    gTemporaryCommonPoolSplit.seqCacheSize = spec->temporarySeqCacheSize;
    gTemporaryCommonPoolSplit.fontCacheSize = spec->temporaryFontCacheSize;
    gTemporaryCommonPoolSplit.sampleBankCacheSize = spec->temporarySampleBankCacheSize;
    func_800B2D74(&gTemporaryCommonPoolSplit);
    func_800B43F0(spec->persistentSampleCacheSize, spec->temporarySampleCacheSize);
    if (gExternalPool.startRamAddr != NULL) {
        gExternalPool.curRamAddr = gExternalPool.startRamAddr;
    }
    func_800B27D4();
    gNotes = func_800B2A0C(&gMiscPool, gNumNotes * sizeof(Note));
    func_800AB888();
    func_800AAFFC();
    gNoteSubsEu = func_800B2A0C(&gMiscPool, gAudioBufferParams.ticksPerUpdate * gNumNotes * sizeof(NoteSubEu));
    for (j = 0; j != 2; j++) {
        gAbiCmdBuffs[j] = func_800B2A0C(&gMiscPool, gMaxAudioCmds * 8);
    }
    gAdsrDecayTable = func_800B2A8C(&gMiscPool, 0x100 * sizeof(f32));
    func_800B2460();
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

        reverb->leftRingBuf = func_800B2A0C(&gMiscPool, reverb->windowSize * 2);
        reverb->rightRingBuf = func_800B2A0C(&gMiscPool, reverb->windowSize * 2);
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

    func_800AE8F0();

    for (j = 0; j < gAudioBufferParams.numSequencePlayers; j++) {
        func_800AE7F8(j);
        func_800AE700(j);
    }

    func_800AEEA0(gNumNotes);
    gPreloadSampleStackTop = 0;
    D_80025D54 = 0x1000;
    func_800B2324();
    osWritebackDCacheAll();
}

void* func_800B4278(s32 tableType, s32 id) {
    s32 i;

    for (i = 0; i < gPermanentCache.pool.numEntries; i++) {
        if ((tableType == gPermanentCache.entries[i].tableType) && (id == gPermanentCache.entries[i].id)) {
            return gPermanentCache.entries[i].ramAddr;
        }
    }
    return NULL;
}

u8* func_800B42D0(s32 tableType, s32 id, u32 size) {
    u8* ramAddr;
    s32 index = gPermanentCache.pool.numEntries;

    ramAddr = func_800B2A8C(&gPermanentCache.pool, size);
    gPermanentCache.entries[index].ramAddr = ramAddr;

    if (ramAddr == NULL) {
        return NULL;
    }

    gPermanentCache.entries[index].tableType = tableType;
    gPermanentCache.entries[index].id = id;
    gPermanentCache.entries[index].size = size;
}

SampleCacheEntry* func_800B4484(size_t);
SampleCacheEntry* func_800B4920(size_t);

void* func_800B4350(size_t size, s32 fontId, void* sampleAddr, s8 medium) {
    SampleCacheEntry* entry = func_800B4484(size);

    if (entry != NULL) {
        entry->sampleBankId = fontId;
        entry->sampleAddr = sampleAddr;
        entry->origMedium = medium;
        return entry->allocatedAddr;
    } else {
        return NULL;
    }
}

void* func_800B43A0(size_t size, s32 fontId, void* sampleAddr, s8 medium) {
    SampleCacheEntry* entry = func_800B4920(size);

    if (entry != NULL) {
        entry->sampleBankId = fontId;
        entry->sampleAddr = sampleAddr;
        entry->origMedium = medium;
        return entry->allocatedAddr;
    } else {
        return NULL;
    }
}

s32 func_800B43F0(size_t persistentSampleCacheSize, size_t temporarySampleCacheSize) {
    void* ramAddr;

    ramAddr = func_800B2A8C(&gPersistentCommonPool, persistentSampleCacheSize);
    if (ramAddr == NULL) {
        gPersistentSampleCache.pool.size = 0;
    } else {
        func_800B2AE4(&gPersistentSampleCache.pool, ramAddr, persistentSampleCacheSize);
    }
    ramAddr = func_800B2A8C(&gTemporaryCommonPool, temporarySampleCacheSize);
    if (ramAddr == NULL) {
        gTemporarySampleCache.pool.size = 0;
    } else {
        func_800B2AE4(&gTemporarySampleCache.pool, ramAddr, temporarySampleCacheSize);
    }
    gPersistentSampleCache.numEntries = 0;
    gTemporarySampleCache.numEntries = 0;
}

void func_800B4718(SampleCacheEntry* entry);

SampleCacheEntry* func_800B4484(size_t size) {
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
    ramAddr = func_800B2A8C(&cache->pool, size);
    if (ramAddr == NULL) {
        old = cache->pool.curRamAddr;
        cache->pool.curRamAddr = cache->pool.startRamAddr;
        ramAddr = func_800B2A8C(&cache->pool, size);
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
        func_800B4718(&cache->entries[i]);
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

void func_800B48DC(SampleCacheEntry* entry, Sample* sample);

void func_800B4718(SampleCacheEntry* entry) {
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
            if ((func_800B3534(FONT_TABLE, CACHE_EITHER, fontId) != NULL) && func_800AF288(fontId)) {
                for (instId = 0; instId < gSoundFontList[fontId].numInstruments; instId++) {
                    instrument = func_800AAD2C(fontId, instId);
                    if (instrument != NULL) {
                        if (instrument->normalRangeLo != 0) {
                            func_800B48DC(entry, instrument->lowPitchTunedSample.sample);
                        }
                        if (instrument->normalRangeHi != 0x7F) {
                            func_800B48DC(entry, instrument->highPitchTunedSample.sample);
                        }
                        func_800B48DC(entry, instrument->normalPitchTunedSample.sample);
                    }
                }
                for (drumId = 0; drumId < gSoundFontList[fontId].numDrums; drumId++) {
                    drum = func_800AAD58(fontId, drumId);
                    if (drum != NULL) {
                        // FAKE
                        if (1) {
                            func_800B48DC(entry, drum->tunedSample.sample);
                        }
                    }
                }
            }
        }
    }
}

void func_800B48DC(SampleCacheEntry* entry, Sample* sample) {
    if (sample != NULL && sample->sampleAddr == entry->allocatedAddr) {
        sample->sampleAddr = entry->sampleAddr;
        sample->medium = entry->origMedium;
    }
}

SampleCacheEntry* func_800B4920(size_t size) {
    AudioSampleCache* cache = &gPersistentSampleCache;
    SampleCacheEntry* entry;
    u8* ramAddr;

    ramAddr = func_800B2A8C(&cache->pool, size);
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

void func_800B49A8(void) {
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
            if (func_800B3534(FONT_TABLE, CACHE_PERMANENT, fontId) != NULL && func_800AF288(fontId)) {

                for (i = 0; i < gPersistentSampleCache.numEntries; i++) {
                    entry = &gPersistentSampleCache.entries[i];
                    if (sampleBankId1 != entry->sampleBankId && sampleBankId2 != entry->sampleBankId &&
                        entry->sampleBankId != SAMPLES_SFX) {
                        break;
                    }
                    for (instId = 0; instId < gSoundFontList[fontId].numInstruments; instId++) {
                        instrument = func_800AAD2C(fontId, instId);
                        if (instrument != NULL) {
                            if (instrument->normalRangeLo != 0) {
                                func_800B48DC(entry, instrument->lowPitchTunedSample.sample);
                            }
                            if (instrument->normalRangeHi != 0x7F) {
                                func_800B48DC(entry, instrument->highPitchTunedSample.sample);
                            }
                            func_800B48DC(entry, instrument->normalPitchTunedSample.sample);
                        }
                    }
                    for (drumId = 0; drumId < gSoundFontList[fontId].numDrums; drumId++) {
                        drum = func_800AAD58(fontId, drumId);
                        if (drum != NULL) {
                            func_800B48DC(entry, drum->tunedSample.sample);
                        }
                    }
                }
            }
        }
    }
}
