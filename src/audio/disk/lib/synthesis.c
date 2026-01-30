#include "global.h"
#include "audio.h"

s32 D_80771930 = 0;

u32 sEnvMixerOp = _SHIFTL(A_ENVMIXER, 24, 8);

// Store the left dry channel in a temp space to be delayed to produce the haas effect
u32 sEnvMixerLeftHaasDmemDests =
    AUDIO_MK_CMD(DMEM_HAAS_TEMP >> 4, DMEM_RIGHT_CH >> 4, DMEM_WET_LEFT_CH >> 4, DMEM_WET_RIGHT_CH >> 4);

// Store the right dry channel in a temp space to be delayed to produce the haas effect
u32 sEnvMixerRightHaasDmemDests =
    AUDIO_MK_CMD(DMEM_LEFT_CH >> 4, DMEM_HAAS_TEMP >> 4, DMEM_WET_LEFT_CH >> 4, DMEM_WET_RIGHT_CH >> 4);

u32 sEnvMixerDefaultDmemDests =
    AUDIO_MK_CMD(DMEM_LEFT_CH >> 4, DMEM_RIGHT_CH >> 4, DMEM_WET_LEFT_CH >> 4, DMEM_WET_RIGHT_CH >> 4);

u16 D_80771944[] = {
    0x7FFF, 0xD001, 0x3FFF, 0xF001, 0x5FFF, 0x9001, 0x7FFF, 0x8001,
};

void AudioSynth_InitNextRingBuf(s32 chunkLen, s32 updateIndex, s32 reverbIndex) {
    ReverbRingBufferItem* bufItem;
    s32 pad[3];
    SynthesisReverb* reverb = &gAudioCtx.synthesisReverbs[reverbIndex];
    s32 temp_a0_2;
    s32 temp_a0_4;
    s32 numSamples;
    s32 extraSamples;
    s32 i;
    s32 j;

    if (reverb->downsampleRate >= 2) {
        if (reverb->framesToIgnore == 0) {
            bufItem = &reverb->items[reverb->curFrame][updateIndex];
            Audio_InvalDCache(bufItem->toDownsampleLeft, DMEM_2CH_SIZE);

            for (j = 0, i = 0; i < bufItem->lengthA / (s32) SAMPLE_SIZE; j += reverb->downsampleRate, i++) {
                reverb->leftRingBuf[bufItem->startPos + i] = bufItem->toDownsampleLeft[j];
                reverb->rightRingBuf[bufItem->startPos + i] = bufItem->toDownsampleRight[j];
            }

            for (i = 0; i < bufItem->lengthB / (s32) SAMPLE_SIZE; j += reverb->downsampleRate, i++) {
                reverb->leftRingBuf[i] = bufItem->toDownsampleLeft[j];
                reverb->rightRingBuf[i] = bufItem->toDownsampleRight[j];
            }
        }
    }

    bufItem = &reverb->items[reverb->curFrame][updateIndex];
    numSamples = chunkLen / reverb->downsampleRate;
    extraSamples = (numSamples + reverb->nextRingBufPos) - reverb->bufSizePerChan;
    temp_a0_2 = reverb->nextRingBufPos;
    if (extraSamples < 0) {
        bufItem->lengthA = numSamples * SAMPLE_SIZE;
        bufItem->lengthB = 0;
        bufItem->startPos = reverb->nextRingBufPos;
        reverb->nextRingBufPos += numSamples;
    } else {
        // End of the buffer is reached. Loop back around
        bufItem->lengthA = (numSamples - extraSamples) * SAMPLE_SIZE;
        bufItem->lengthB = extraSamples * SAMPLE_SIZE;
        bufItem->startPos = reverb->nextRingBufPos;
        reverb->nextRingBufPos = extraSamples;
    }

    bufItem->numSamplesAfterDownsampling = numSamples;
    bufItem->chunkLen = chunkLen;

    if (reverb->unk_14 != 0) {
        temp_a0_4 = reverb->unk_14 + temp_a0_2;
        if (temp_a0_4 >= reverb->bufSizePerChan) {
            temp_a0_4 -= reverb->bufSizePerChan;
        }
        bufItem = &reverb->items2[reverb->curFrame][updateIndex];
        numSamples = chunkLen / reverb->downsampleRate;
        extraSamples = (temp_a0_4 + numSamples) - reverb->bufSizePerChan;
        if (extraSamples < 0) {
            bufItem->lengthA = numSamples * SAMPLE_SIZE;
            bufItem->lengthB = 0;
            bufItem->startPos = temp_a0_4;
        } else {
            // End of the buffer is reached. Loop back around
            bufItem->lengthA = (numSamples - extraSamples) * SAMPLE_SIZE;
            bufItem->lengthB = extraSamples * SAMPLE_SIZE;
            bufItem->startPos = temp_a0_4;
        }
        bufItem->numSamplesAfterDownsampling = numSamples;
        bufItem->chunkLen = chunkLen;
    }
}

void AudioSynth_SyncSampleStates(s32 updateIndex) {
    NoteSubEu* subEu;
    NoteSubEu* subEu2;
    s32 i;
    s32 baseIndex = gAudioCtx.numNotes * updateIndex;

    for (i = 0; i < gAudioCtx.numNotes; i++) {
        subEu = &gAudioCtx.notes[i].noteSubEu;
        subEu2 = &gAudioCtx.noteSubsEu[baseIndex + i];
        if (subEu->bitField0.enabled) {
            *subEu2 = *subEu;
            subEu->bitField0.needsInit = false;
        } else {
            subEu2->bitField0.enabled = false;
        }
        subEu->harmonicIndexCurAndPrev = 0;
    }
}

Acmd* AudioSynth_Update(Acmd* aList, s32* cmdCount, s16* aiStart, s32 aiBufLen) {
    s32 chunkLen;
    s16* aiBufP;
    Acmd* aCmdPtr;
    s32 i;
    s32 j;
    SynthesisReverb* reverb;

    aCmdPtr = aList;
    for (i = gAudioCtx.audioBufferParameters.ticksPerUpdate; i > 0; i--) {
        AudioSeq_ProcessSequences(i - 1);
        AudioSynth_SyncSampleStates(gAudioCtx.audioBufferParameters.ticksPerUpdate - i);
    }

    aiBufP = aiStart;
    gAudioCtx.curLoadedBook = NULL;

    for (i = gAudioCtx.audioBufferParameters.ticksPerUpdate; i > 0; i--) {
        if (i == 1) {
            chunkLen = aiBufLen;
        } else if ((aiBufLen / i) >= gAudioCtx.audioBufferParameters.samplesPerTickMax) {
            chunkLen = gAudioCtx.audioBufferParameters.samplesPerTickMax;
        } else if (gAudioCtx.audioBufferParameters.samplesPerTickMin >= (aiBufLen / i)) {
            chunkLen = gAudioCtx.audioBufferParameters.samplesPerTickMin;
        } else {
            chunkLen = gAudioCtx.audioBufferParameters.samplesPerTick;
        }

        for (j = 0; j < gAudioCtx.numSynthesisReverbs; j++) {
            if (gAudioCtx.synthesisReverbs[j].useReverb) {
                AudioSynth_InitNextRingBuf(chunkLen, gAudioCtx.audioBufferParameters.ticksPerUpdate - i, j);
            }
        }

        aCmdPtr =
            AudioSynth_SingleAudioUpdate(aiBufP, chunkLen, aCmdPtr, gAudioCtx.audioBufferParameters.ticksPerUpdate - i);
        aiBufLen -= chunkLen;
        aiBufP += 2 * chunkLen;
    }

    for (j = 0; j < gAudioCtx.numSynthesisReverbs; j++) {
        if (gAudioCtx.synthesisReverbs[j].framesToIgnore != 0) {
            gAudioCtx.synthesisReverbs[j].framesToIgnore--;
        }
        gAudioCtx.synthesisReverbs[j].curFrame ^= 1;
    }

    *cmdCount = aCmdPtr - aList;
    return aCmdPtr;
}

void func_8072EAA0(s32 updateIndex, s32 noteIndex) {
    NoteSubEu* noteSubEu;
    s32 i;

    for (i = updateIndex + 1; i < gAudioCtx.audioBufferParameters.ticksPerUpdate; i++) {
        noteSubEu = &gAudioCtx.noteSubsEu[(gAudioCtx.numNotes * i) + noteIndex];
        if (noteSubEu->bitField0.needsInit) {
            break;
        }
        noteSubEu->bitField0.enabled = false;
    }
}

Acmd* AudioSynth_LoadRingBuffer(Acmd* aList, SynthesisReverb* reverb, s16 updateIndex) {
    ReverbRingBufferItem* bufItem = &reverb->items[reverb->curFrame][updateIndex];

    aList = AudioSynth_LoadRingBufferPart(aList, DMEM_WET_TEMP, bufItem->startPos, bufItem->lengthA, reverb);
    if (bufItem->lengthB != 0) {
        aList = AudioSynth_LoadRingBufferPart(aList, DMEM_WET_TEMP + bufItem->lengthA, 0, bufItem->lengthB, reverb);
    }
    return aList;
}

Acmd* AudioSynth_SaveRingBuffer(Acmd* aList, SynthesisReverb* reverb, s16 updateIndex) {
    ReverbRingBufferItem* bufItem = &reverb->items[reverb->curFrame][updateIndex];

    aList = AudioSynth_SaveRingBufferPart(aList, DMEM_WET_TEMP, bufItem->startPos, bufItem->lengthA, reverb);
    if (bufItem->lengthB != 0) {
        aList = AudioSynth_SaveRingBufferPart(aList, DMEM_WET_TEMP + bufItem->lengthA, 0, bufItem->lengthB, reverb);
    }
    return aList;
}

Acmd* AudioSynth_LeakReverb(Acmd* aList, SynthesisReverb* reverb) {
    aDMEMMove(aList++, DMEM_WET_LEFT_CH, DMEM_WET_SCRATCH, DMEM_1CH_SIZE);
    aMix(aList++, DMEM_1CH_SIZE >> 4, reverb->leakRtl, DMEM_WET_RIGHT_CH, DMEM_WET_LEFT_CH);
    aMix(aList++, DMEM_1CH_SIZE >> 4, reverb->leakLtr, DMEM_WET_SCRATCH, DMEM_WET_RIGHT_CH);
    return aList;
}

Acmd* func_8072ECC4(Acmd* aList, s32 aiBufLen, SynthesisReverb* reverb, s16 updateIndex) {
    ReverbRingBufferItem* item = &reverb->items[reverb->curFrame][updateIndex];
    s16 offsetA;
    s16 offsetB;

    offsetA = (item->startPos & 7) * SAMPLE_SIZE;
    offsetB = ALIGN16(offsetA + item->lengthA);

    aList = AudioSynth_LoadRingBufferPart(aList, DMEM_WET_TEMP, item->startPos - (offsetA / (s32) SAMPLE_SIZE),
                                          DMEM_1CH_SIZE, reverb);
    if (item->lengthB != 0) {
        aList = AudioSynth_LoadRingBufferPart(aList, DMEM_WET_TEMP + offsetB, 0, DMEM_1CH_SIZE - offsetB, reverb);
    }
    aSetBuffer(aList++, 0, DMEM_WET_TEMP + offsetA, DMEM_WET_LEFT_CH, aiBufLen * SAMPLE_SIZE);
    aResample(aList++, reverb->resampleFlags, reverb->unk_0E, reverb->unk_30);
    aSetBuffer(aList++, 0, DMEM_WET_TEMP + DMEM_1CH_SIZE + offsetA, DMEM_WET_RIGHT_CH, aiBufLen * SAMPLE_SIZE);
    aResample(aList++, reverb->resampleFlags, reverb->unk_0E, reverb->unk_34);
    return aList;
}

Acmd* func_8072EE60(Acmd* aList, SynthesisReverb* reverb, s16 updateIndex) {
    ReverbRingBufferItem* bufItem = &reverb->items[reverb->curFrame][updateIndex];

    aSetBuffer(aList++, 0, DMEM_WET_LEFT_CH, DMEM_WET_SCRATCH, bufItem->unk_18 * SAMPLE_SIZE);
    aResample(aList++, reverb->resampleFlags, bufItem->unk_16, reverb->unk_38);

    aList =
        AudioSynth_SaveBufferOffset(aList, DMEM_WET_SCRATCH, bufItem->startPos, bufItem->lengthA, reverb->leftRingBuf);
    if (bufItem->lengthB != 0) {
        aList = AudioSynth_SaveBufferOffset(aList, DMEM_WET_SCRATCH + bufItem->lengthA, 0, bufItem->lengthB,
                                            reverb->leftRingBuf);
    }
    aSetBuffer(aList++, 0, DMEM_WET_RIGHT_CH, DMEM_WET_SCRATCH, bufItem->unk_18 * SAMPLE_SIZE);
    aResample(aList++, reverb->resampleFlags, bufItem->unk_16, reverb->unk_3C);
    aList =
        AudioSynth_SaveBufferOffset(aList, DMEM_WET_SCRATCH, bufItem->startPos, bufItem->lengthA, reverb->rightRingBuf);

    if (bufItem->lengthB != 0) {
        aList = AudioSynth_SaveBufferOffset(aList, DMEM_WET_SCRATCH + bufItem->lengthA, 0, bufItem->lengthB,
                                            reverb->rightRingBuf);
    }

    return aList;
}

Acmd* func_8072F008(Acmd* aList, s32 aiBufLen, SynthesisReverb* reverb, s16 updateIndex) {
    ReverbRingBufferItem* item = &reverb->items[reverb->curFrame][updateIndex];
    s16 offsetA;
    s16 offsetB;

    item->unk_14 = (item->unk_18 << 0xF) / aiBufLen;
    offsetA = (item->startPos & 7) * SAMPLE_SIZE;
    item->unk_16 = (aiBufLen << 0xF) / item->unk_18;
    offsetB = ALIGN16(offsetA + item->lengthA);
    aList = AudioSynth_LoadRingBufferPart(aList, DMEM_WET_TEMP, item->startPos - (offsetA / (s32) SAMPLE_SIZE),
                                          DMEM_1CH_SIZE, reverb);
    if (item->lengthB != 0) {
        aList = AudioSynth_LoadRingBufferPart(aList, DMEM_WET_TEMP + offsetB, 0, DMEM_1CH_SIZE - offsetB, reverb);
    }
    aSetBuffer(aList++, 0, DMEM_WET_TEMP + offsetA, DMEM_WET_LEFT_CH, aiBufLen * SAMPLE_SIZE);
    aResample(aList++, reverb->resampleFlags, item->unk_14, reverb->unk_30);
    aSetBuffer(aList++, 0, DMEM_WET_TEMP + DMEM_1CH_SIZE + offsetA, DMEM_WET_RIGHT_CH, aiBufLen * SAMPLE_SIZE);
    aResample(aList++, reverb->resampleFlags, item->unk_14, reverb->unk_34);
    return aList;
}

Acmd* AudioSynth_FilterReverb(Acmd* aList, s32 size, SynthesisReverb* reverb) {
    if (reverb->filterLeft != NULL) {
        aFilter(aList++, 2, size, reverb->filterLeft);
        aFilter(aList++, reverb->resampleFlags, DMEM_WET_LEFT_CH, reverb->filterLeftState);
    }

    if (reverb->filterRight != NULL) {
        aFilter(aList++, 2, size, reverb->filterRight);
        aFilter(aList++, reverb->resampleFlags, DMEM_WET_RIGHT_CH, reverb->filterRightState);
    }
    return aList;
}

Acmd* AudioSynth_MaybeMixRingBuffer1(Acmd* aList, SynthesisReverb* reverb, s32 updateIndex) {
    SynthesisReverb* temp_a3;

    if (reverb->unk_05 >= gAudioCtx.numSynthesisReverbs) {
        return aList;
    }

    temp_a3 = &gAudioCtx.synthesisReverbs[reverb->unk_05];
    if (temp_a3->downsampleRate == 1) {
        aList = AudioSynth_LoadRingBuffer(aList, temp_a3, updateIndex);
        aMix(aList++, DMEM_2CH_SIZE >> 4, reverb->unk_08, DMEM_WET_LEFT_CH, DMEM_WET_TEMP);
        aList = AudioSynth_SaveRingBuffer(aList, temp_a3, updateIndex);
    }
    return aList;
}

void func_8072F388(void) {
}

void AudioSynth_ClearBuffer(Acmd* aList, s32 dmem, size_t size) {
    aClearBuffer(aList, dmem, size);
}

void func_8072F3B0(void) {
}

void func_8072F3B8(void) {
}

void func_8072F3C0(void) {
}

void func_8072F3C8(void) {
}

void func_8072F3D0(void) {
}

void func_8072F3D8(void) {
}

void func_8072F3E0(void) {
}

void AudioSynth_SetBuffer(Acmd* aList, s32 flags, s32 dmemIn, s32 dmemOut, size_t size) {
    aSetBuffer(aList, flags, dmemIn, dmemOut, size);
}

void func_8072F41C(void) {
}

void func_8072F424(void) {
}

void func_8072F42C(void) {
}

void func_8072F434(void) {
}

void func_8072F43C(void) {
}

void func_8072F444(void) {
}

void func_8072F44C(void) {
}

void AudioSynth_InterL(Acmd* aList, s32 dmemIn, s32 dmemOut, s32 numSamples) {
    aList->words.w0 = _SHIFTL(A_INTERL, 24, 8) | _SHIFTL(numSamples, 0, 16);
    aList->words.w1 = _SHIFTL(dmemIn, 16, 16) | _SHIFTL(dmemOut, 0, 16);
}

void func_8072F478(void) {
}

void func_8072F480(void) {
}

void func_8072F488(void) {
}

void AudioSynth_SaveBuffer(Acmd* aList, s32 dmemSrc, s32 size, void* addrDest) {
    aSaveBuffer(aList, dmemSrc, addrDest, size);
}

void func_8072F4B8(void) {
}

void func_8072F4C0(void) {
}

void func_8072F4C8(void) {
}

void func_8072F4D0(void) {
}

void AudioSynth_S8Dec(Acmd* aList, s32 flags, s16* state) {
    aS8Dec(aList, flags, state);
}

void AudioSynth_HiLoGain(Acmd* aList, s32 gain, s32 dmemIn, s32 dmemOut, s32 size) {
    aList->words.w0 = _SHIFTL(A_HILOGAIN, 24, 8) | _SHIFTL(gain, 16, 8) | _SHIFTL(size, 0, 16);
    aList->words.w1 = _SHIFTL(dmemIn, 16, 16) | _SHIFTL(dmemOut, 0, 16);
}

void AudioSynth_UnkCmd19(Acmd* aList, s32 arg1, s32 arg2, s32 size, s32 arg4) {
    aList->words.w0 = _SHIFTL(A_UNK19, 24, 8) | _SHIFTL(arg4, 16, 8) | _SHIFTL(size, 0, 16);
    aList->words.w1 = _SHIFTL(arg1, 16, 16) | _SHIFTL(arg2, 0, 16);
}

void func_8072F55C(void) {
}

void func_8072F564(void) {
}

void func_8072F56C(void) {
}

void func_8072F574(void) {
}

void func_8072F57C(void) {
}

void func_8072F584(void) {
}

void func_8072F58C(void) {
}

void func_8072F594(void) {
}

void AudioSynth_LoadFilterBuffer(Acmd* aList, s32 flags, s32 buf, void* addr) {
    aFilter(aList, flags, buf, addr);
}

void AudioSynth_LoadFilterSize(Acmd* aList, s32 size, void* addr) {
    aFilter(aList, 2, size, addr);
}

Acmd* AudioSynth_LoadRingBuffer1(Acmd* aList, s32 aiBufLen, SynthesisReverb* reverb, s16 updateIndex) {
    ReverbRingBufferItem* ringBufferItem = &reverb->items[reverb->curFrame][updateIndex];

    aList = AudioSynth_LoadRingBufferPart(aList, DMEM_WET_LEFT_CH, ringBufferItem->startPos, ringBufferItem->lengthA,
                                          reverb);
    if (ringBufferItem->lengthB != 0) {
        aList = AudioSynth_LoadRingBufferPart(aList, DMEM_WET_LEFT_CH + ringBufferItem->lengthA, 0,
                                              ringBufferItem->lengthB, reverb);
    }

    return aList;
}

Acmd* AudioSynth_LoadRingBuffer2(Acmd* aList, s32 aiBufLen, SynthesisReverb* reverb, s16 updateIndex) {
    ReverbRingBufferItem* ringBufferItem = &reverb->items2[reverb->curFrame][updateIndex];

    aList = AudioSynth_LoadRingBufferPart(aList, DMEM_WET_LEFT_CH, ringBufferItem->startPos, ringBufferItem->lengthA,
                                          reverb);
    if (ringBufferItem->lengthB != 0) {
        aList = AudioSynth_LoadRingBufferPart(aList, DMEM_WET_LEFT_CH + ringBufferItem->lengthA, 0,
                                              ringBufferItem->lengthB, reverb);
    }
    return aList;
}

Acmd* AudioSynth_LoadRingBufferPart(Acmd* aList, u16 dmem, u16 startPos, s32 size, SynthesisReverb* reverb) {
    aLoadBuffer(aList++, &reverb->leftRingBuf[startPos], dmem, size);
    aLoadBuffer(aList++, &reverb->rightRingBuf[startPos], dmem + DMEM_1CH_SIZE, size);
    return aList;
}

Acmd* AudioSynth_SaveRingBufferPart(Acmd* aList, u16 dmem, u16 startPos, s32 size, SynthesisReverb* reverb) {
    aSaveBuffer(aList++, dmem, &reverb->leftRingBuf[startPos], size);
    aSaveBuffer(aList++, dmem + DMEM_1CH_SIZE, &reverb->rightRingBuf[startPos], size);
    return aList;
}

Acmd* AudioSynth_SaveBufferOffset(Acmd* aList, u16 dmem, u16 offset, s32 size, s16* buf) {
    aSaveBuffer(aList++, dmem, &buf[offset], size);
    return aList;
}

Acmd* AudioSynth_MaybeLoadRingBuffer2(Acmd* aList, s32 aiBufLen, SynthesisReverb* reverb, s16 updateIndex) {
    if (reverb->downsampleRate == 1) {
        aList = AudioSynth_LoadRingBuffer2(aList, aiBufLen, reverb, updateIndex);
    }

    return aList;
}

Acmd* AudioSynth_LoadReverbSamples(Acmd* aList, s32 aiBufLen, SynthesisReverb* reverb, s16 updateIndex) {
    if (reverb->downsampleRate == 1) {
        if (reverb->unk_18 != 0) {
            aList = func_8072F008(aList, aiBufLen, reverb, updateIndex);
        } else {
            aList = AudioSynth_LoadRingBuffer1(aList, aiBufLen, reverb, updateIndex);
        }
    } else {
        aList = func_8072ECC4(aList, aiBufLen, reverb, updateIndex);
    }
    return aList;
}

Acmd* AudioSynth_SaveReverbSamples(Acmd* aList, SynthesisReverb* reverb, s16 updateIndex) {
    ReverbRingBufferItem* bufItem = &reverb->items[reverb->curFrame][updateIndex];

    if (reverb->downsampleRate == 1) {
        if (reverb->unk_18 != 0) {
            aList = func_8072EE60(aList, reverb, updateIndex);
        } else {
            // Put the oldest samples in the ring buffer into the wet channels
            aList = AudioSynth_SaveRingBufferPart(aList, DMEM_WET_LEFT_CH, bufItem->startPos, bufItem->lengthA, reverb);
            if (bufItem->lengthB != 0) {
                // Ring buffer wrapped
                aList = AudioSynth_SaveRingBufferPart(aList, DMEM_WET_LEFT_CH + bufItem->lengthA, 0, bufItem->lengthB,
                                                      reverb);
            }
        }
    } else {
        // Downsampling is done later by CPU when RSP is done, therefore we need to have
        // double buffering. Left and right buffers are adjacent in memory.
        AudioSynth_SaveBuffer(aList++, DMEM_WET_LEFT_CH, DMEM_2CH_SIZE,
                              reverb->items[reverb->curFrame][updateIndex].toDownsampleLeft);
    }

    reverb->resampleFlags = 0;
    return aList;
}

Acmd* AudioSynth_SaveRingBuffer2(Acmd* aList, SynthesisReverb* reverb, s16 updateIndex) {
    ReverbRingBufferItem* bufItem = &reverb->items2[reverb->curFrame][updateIndex];

    aList = AudioSynth_SaveRingBufferPart(aList, DMEM_WET_LEFT_CH, bufItem->startPos, bufItem->lengthA, reverb);
    if (bufItem->lengthB != 0) {
        aList = AudioSynth_SaveRingBufferPart(aList, DMEM_WET_LEFT_CH + bufItem->lengthA, 0, bufItem->lengthB, reverb);
    }
    return aList;
}

Acmd* AudioSynth_SingleAudioUpdate(s16* aiBuf, s32 aiBufLen, Acmd* aList, s32 updateIndex) {
    u8 noteIndices[0x5C];
    s16 count;
    s16 reverbIndex;
    SynthesisReverb* reverb;
    s32 useReverb;
    s32 t;
    s32 i;
    NoteSubEu* noteSubEu;
    NoteSubEu* noteSubEu2;
    s32 unk14;

    t = gAudioCtx.numNotes * updateIndex;
    count = 0;
    if (gAudioCtx.numSynthesisReverbs == 0) {
        for (i = 0; i < gAudioCtx.numNotes; i++) {
            if (gAudioCtx.noteSubsEu[t + i].bitField0.enabled) {
                noteIndices[count++] = i;
            }
        }
    } else {
        for (reverbIndex = 0; reverbIndex < gAudioCtx.numSynthesisReverbs; reverbIndex++) {
            for (i = 0; i < gAudioCtx.numNotes; i++) {
                noteSubEu = &gAudioCtx.noteSubsEu[t + i];
                if (noteSubEu->bitField0.enabled && noteSubEu->bitField1.reverbIndex == reverbIndex) {
                    noteIndices[count++] = i;
                }
            }
        }

        for (i = 0; i < gAudioCtx.numNotes; i++) {
            noteSubEu = &gAudioCtx.noteSubsEu[t + i];
            if (noteSubEu->bitField0.enabled && noteSubEu->bitField1.reverbIndex >= gAudioCtx.numSynthesisReverbs) {
                noteIndices[count++] = i;
            }
        }
    }

    aClearBuffer(aList++, DMEM_LEFT_CH, DMEM_2CH_SIZE);

    i = 0;
    for (reverbIndex = 0; reverbIndex < gAudioCtx.numSynthesisReverbs; reverbIndex++) {
        reverb = &gAudioCtx.synthesisReverbs[reverbIndex];
        useReverb = reverb->useReverb;
        if (useReverb) {

            // Loads reverb samples from RDRAM (ringBuffer) into DMEM (DMEM_WET_LEFT_CH)
            aList = AudioSynth_LoadReverbSamples(aList, aiBufLen, reverb, updateIndex);

            // Mixes reverb sample into the main dry channel
            // reverb->volume is always set to 0x7FFF (audio spec), and DMEM_LEFT_CH is cleared before the loop.
            // So for the first iteration, this is essentially a DMEMmove from DMEM_WET_LEFT_CH to DMEM_LEFT_CH
            aMix(aList++, DMEM_2CH_SIZE >> 4, reverb->volume, DMEM_WET_LEFT_CH, DMEM_LEFT_CH);

            unk14 = reverb->unk_14;
            if (unk14) {
                aDMEMMove(aList++, DMEM_WET_LEFT_CH, DMEM_WET_TEMP, DMEM_2CH_SIZE);
            }

            // Decays reverb over time. The (+ 0x8000) here is -100%
            aMix(aList++, DMEM_2CH_SIZE >> 4, reverb->decayRatio + 0x8000, DMEM_WET_LEFT_CH, DMEM_WET_LEFT_CH);

            // Leak reverb between the left and right channels

            if (((reverb->leakRtl != 0) || (reverb->leakLtr != 0)) && (gAudioCtx.soundMode != SOUNDMODE_MONO)) {
                aList = AudioSynth_LeakReverb(aList, reverb);
            }

            if (unk14) {
                // Saves the wet channel sample from DMEM (DMEM_WET_LEFT_CH) into RDRAM (ringBuffer) for future use
                aList = AudioSynth_SaveReverbSamples(aList, reverb, updateIndex);
                if (reverb->unk_05 != -1) {
                    aList = AudioSynth_MaybeMixRingBuffer1(aList, reverb, updateIndex);
                }
                aList = AudioSynth_MaybeLoadRingBuffer2(aList, aiBufLen, reverb, updateIndex);
                aMix(aList++, DMEM_2CH_SIZE >> 4, reverb->unk_16, DMEM_WET_TEMP, DMEM_WET_LEFT_CH);
            }
        }

        while (i < count) {
            noteSubEu2 = &gAudioCtx.noteSubsEu[noteIndices[i] + t];
            if (noteSubEu2->bitField1.reverbIndex == reverbIndex) {
                aList =
                    AudioSynth_ProcessNote(noteIndices[i], noteSubEu2, &gAudioCtx.notes[noteIndices[i]].synthesisState,
                                           aiBuf, aiBufLen, aList, updateIndex);
            } else {
                break;
            }
            i++;
        }

        if (useReverb) {
            if (reverb->filterLeft != NULL || reverb->filterRight != NULL) {
                aList = AudioSynth_FilterReverb(aList, aiBufLen * SAMPLE_SIZE, reverb);
            }

            // Saves the wet channel sample from DMEM (DMEM_WET_LEFT_CH) into RDRAM (ringBuffer) for future use
            if (unk14) {
                aList = AudioSynth_SaveRingBuffer2(aList, reverb, updateIndex);
            } else {
                aList = AudioSynth_SaveReverbSamples(aList, reverb, updateIndex);
                if (reverb->unk_05 != -1) {
                    aList = AudioSynth_MaybeMixRingBuffer1(aList, reverb, updateIndex);
                }
            }
        }
    }

    while (i < count) {
        aList = AudioSynth_ProcessNote(noteIndices[i], &gAudioCtx.noteSubsEu[t + noteIndices[i]],
                                       &gAudioCtx.notes[noteIndices[i]].synthesisState, aiBuf, aiBufLen, aList,
                                       updateIndex);
        i++;
    }

    aInterleave(aList++, DMEM_TEMP, DMEM_LEFT_CH, DMEM_RIGHT_CH, 2 * aiBufLen);
    aSaveBuffer(aList++, DMEM_TEMP, aiBuf, 2 * (aiBufLen * (s32) SAMPLE_SIZE));

    return aList;
}

Acmd* AudioSynth_ProcessNote(s32 noteIndex, NoteSubEu* noteSubEu, NoteSynthesisState* synthState, s16* aiBuf,
                             s32 aiBufLen, Acmd* aList, s32 updateIndex) {
    s32 pad1[3];
    Sample* sample;
    AdpcmLoop* loopInfo;
    s32 nSamplesUntilLoopEnd;
    s32 nSamplesInThisIteration;
    s32 noteFinished;
    s32 restart;
    s32 flags;
    u16 resamplingRateFixedPoint;
    s32 gain;
    s32 frameIndex;
    s16* combFilterState;
    s32 nSamplesToDecode;
    s32 skipBytes;
    u32 samplesLenFixedPoint;
    s32 nSamplesProcessed;
    s32 temp_v1_6;
    uintptr_t sampleAddr;
    s32 phi_s4;
    s32 samplesLenAdjusted;
    u8* sampleData;
    s32 loopEndPos;
    s32 nSamplesToProcess;
    s32 nFirstFrameSamplesToIgnore;
    s32 nFramesToDecode;
    s32 pad3;
    s32 nTrailingSamplesToIgnore;
    s32 nSamplesInFirstFrame;
    s32 sampleDataStartPad;
    s32 haasEffectDelaySide;
    s32 sampleDataOffset;
    s32 pad5;
    s32 frameSize;
    s32 pad7;
    s32 skipInitialSamples;
    s32 sampleDataStart;
    s32 pad4;
    s32 nParts;
    s32 curPart;
    s32 s5;
    s32 pad6;
    s32 resampledTempLen;
    u16 sampleDmemBeforeResampling;
    s32 pad2;
    u32 nEntries;
    u32 numSamplesToLoad;
    Note* note;
    s16* filter;
    s32 aligned;
    s16 addr;
    s32 bookOffset;
    s32 finished;

    bookOffset = noteSubEu->bitField1.bookOffset;
    finished = noteSubEu->bitField0.finished;
    note = &gAudioCtx.notes[noteIndex];

    if (noteSubEu->tunedSample != NULL) {
        flags = A_CONTINUE;
        if (noteSubEu->bitField0.needsInit == true) {
            flags = A_INIT;
            synthState->restart = 0;
            synthState->samplePosInt = note->playbackState.startSamplePos;
            synthState->samplePosFrac = 0;
            synthState->curVolLeft = 0;
            synthState->curVolRight = 0;
            synthState->prevHaasEffectLeftDelaySize = 0;
            synthState->prevHaasEffectRightDelaySize = 0;
            synthState->reverbVol = noteSubEu->reverbVol;
            synthState->numParts = 0;
            synthState->combFilterNeedsInit = true;
            note->noteSubEu.bitField0.finished = false;
            finished = false;
            synthState->unk_1B = note->playbackState.unk_7C;
        }

        resamplingRateFixedPoint = noteSubEu->resamplingRateFixedPoint;
        nParts = noteSubEu->bitField1.hasTwoParts + 1;
        samplesLenFixedPoint = (resamplingRateFixedPoint * aiBufLen * 2) + synthState->samplePosFrac;
        numSamplesToLoad = samplesLenFixedPoint >> 16;

        if (numSamplesToLoad == 0) {
            skipBytes = 0;
        }

        synthState->samplePosFrac = samplesLenFixedPoint & 0xFFFF;

        if (synthState->numParts == 1 && nParts == 2) {
        } else if (synthState->numParts == 2 && nParts == 1) {
        } else {
        }

        synthState->numParts = nParts;
        sample = noteSubEu->tunedSample->sample;
        loopInfo = sample->loop;
        loopEndPos = loopInfo->header.end;
        sampleAddr = (uintptr_t) sample->sampleAddr;
        resampledTempLen = 0;

        for (curPart = 0; curPart < nParts; curPart++) {
            nSamplesProcessed = 0;
            s5 = 0;

            if (nParts == 1) {
                samplesLenAdjusted = numSamplesToLoad;
            } else if (numSamplesToLoad & 1) {
                samplesLenAdjusted = (numSamplesToLoad & ~1) + (curPart * 2);
            } else {
                samplesLenAdjusted = numSamplesToLoad;
            }

            if (sample->codec == CODEC_ADPCM || sample->codec == CODEC_SMALL_ADPCM) {
                if (gAudioCtx.curLoadedBook != sample->book->book) {

                    switch (bookOffset) {
                        case 1:
                            gAudioCtx.curLoadedBook = &D_80771228[1];
                            break;
                        case 2:
                        case 3:
                        default:
                            gAudioCtx.curLoadedBook = sample->book->book;
                            break;
                    }

                    nEntries = SAMPLES_PER_FRAME * sample->book->header.order * sample->book->header.numPredictors;
                    aLoadADPCM(aList++, nEntries, gAudioCtx.curLoadedBook);
                }
            }

            while (nSamplesProcessed != samplesLenAdjusted) {
                noteFinished = false;
                restart = false;
                phi_s4 = 0;

                nFirstFrameSamplesToIgnore = synthState->samplePosInt & 0xF;
                nSamplesUntilLoopEnd = loopEndPos - synthState->samplePosInt;
                nSamplesToProcess = samplesLenAdjusted - nSamplesProcessed;

                if (nFirstFrameSamplesToIgnore == 0 && !synthState->restart) {
                    nFirstFrameSamplesToIgnore = SAMPLES_PER_FRAME;
                }
                nSamplesInFirstFrame = SAMPLES_PER_FRAME - nFirstFrameSamplesToIgnore;

                if (nSamplesToProcess < nSamplesUntilLoopEnd) {
                    nFramesToDecode =
                        (s32) (nSamplesToProcess - nSamplesInFirstFrame + SAMPLES_PER_FRAME - 1) / SAMPLES_PER_FRAME;
                    nSamplesToDecode = nFramesToDecode * SAMPLES_PER_FRAME;
                    nTrailingSamplesToIgnore = nSamplesInFirstFrame + nSamplesToDecode - nSamplesToProcess;
                } else {
                    nSamplesToDecode = nSamplesUntilLoopEnd - nSamplesInFirstFrame;
                    nTrailingSamplesToIgnore = 0;
                    if (nSamplesToDecode <= 0) {
                        nSamplesToDecode = 0;
                        nSamplesInFirstFrame = nSamplesUntilLoopEnd;
                    }
                    nFramesToDecode = (nSamplesToDecode + SAMPLES_PER_FRAME - 1) / SAMPLES_PER_FRAME;
                    if (loopInfo->header.count != 0) {
                        // Loop around and restart
                        restart = true;
                    } else {
                        noteFinished = true;
                    }
                }

                switch (sample->codec) {
                    case CODEC_ADPCM:
                        // 16 2-byte samples (32 bytes) compressed into 4-bit samples (8 bytes) + 1 header byte
                        frameSize = 9;
                        skipInitialSamples = SAMPLES_PER_FRAME;
                        sampleDataStart = 0;
                        break;

                    case CODEC_SMALL_ADPCM:
                        // 16 2-byte samples (32 bytes) compressed into 2-bit samples (4 bytes) + 1 header byte
                        frameSize = 5;
                        skipInitialSamples = SAMPLES_PER_FRAME;
                        sampleDataStart = 0;
                        break;

                    case CODEC_S8:
                        // 16 2-byte samples (32 bytes) compressed into 8-bit samples (16 bytes)
                        frameSize = 16;
                        skipInitialSamples = SAMPLES_PER_FRAME;
                        sampleDataStart = 0;
                        break;

                    case CODEC_S16_INMEMORY:
                    case CODEC_UNK6:
                        AudioSynth_ClearBuffer(aList++, DMEM_UNCOMPRESSED_NOTE,
                                               (samplesLenAdjusted + SAMPLES_PER_FRAME) * SAMPLE_SIZE);
                        flags = A_CONTINUE;
                        skipBytes = 0;
                        nSamplesProcessed = samplesLenAdjusted;
                        s5 = samplesLenAdjusted;
                        goto skip;

                    case CODEC_S16:
                        AudioSynth_ClearBuffer(aList++, DMEM_UNCOMPRESSED_NOTE,
                                               (samplesLenAdjusted + SAMPLES_PER_FRAME) * SAMPLE_SIZE);
                        flags = A_CONTINUE;
                        skipBytes = 0;
                        nSamplesProcessed = samplesLenAdjusted;
                        s5 = samplesLenAdjusted;
                        goto skip;
                }

                if (nFramesToDecode != 0) {
                    frameIndex = (synthState->samplePosInt + skipInitialSamples - nFirstFrameSamplesToIgnore) /
                                 SAMPLES_PER_FRAME;
                    sampleDataOffset = frameIndex * frameSize;
                    if (sample->medium == MEDIUM_RAM) {
                        sampleData = (u8*) (sampleDataStart + sampleDataOffset + sampleAddr);
                    } else if (gAudioCtx.unk_215C != 0) {
                        return aList;
                    } else if (sample->medium == MEDIUM_LBA) {
                        return aList;
                    } else {
                        sampleData = AudioLoad_DmaSampleData(sampleDataStart + sampleDataOffset + sampleAddr,
                                                             ALIGN16((nFramesToDecode * frameSize) + SAMPLES_PER_FRAME),
                                                             flags, &synthState->sampleDmaIndex, sample->medium);
                    }

                    if (sampleData == NULL) {
                        return aList;
                    }

                    sampleDataStartPad = (u32) sampleData & 0xF;
                    aligned = ALIGN16((nFramesToDecode * frameSize) + SAMPLES_PER_FRAME);
                    addr = DMEM_COMPRESSED_ADPCM_DATA - aligned;
                    aLoadBuffer(aList++, sampleData - sampleDataStartPad, addr, aligned);
                } else {
                    nSamplesToDecode = 0;
                    sampleDataStartPad = 0;
                }

                if (synthState->restart) {
                    aSetLoop(aList++, sample->loop->predictorState);
                    flags = A_LOOP;
                    synthState->restart = false;
                }

                nSamplesInThisIteration = nSamplesToDecode + nSamplesInFirstFrame - nTrailingSamplesToIgnore;
                if (nSamplesProcessed == 0) {
                    skipBytes = nFirstFrameSamplesToIgnore * SAMPLE_SIZE;
                } else {
                    phi_s4 = ALIGN16(s5 + 8 * SAMPLE_SIZE);
                }

                switch (sample->codec) {
                    case CODEC_ADPCM:
                        aligned = ALIGN16((nFramesToDecode * frameSize) + SAMPLES_PER_FRAME);
                        addr = DMEM_COMPRESSED_ADPCM_DATA - aligned;
                        aSetBuffer(aList++, 0, addr + sampleDataStartPad, DMEM_UNCOMPRESSED_NOTE + phi_s4,
                                   nSamplesToDecode * SAMPLE_SIZE);
                        aADPCMdec(aList++, flags, synthState->synthesisBuffers->adpcmdecState);
                        break;

                    case CODEC_SMALL_ADPCM:
                        aligned = ALIGN16((nFramesToDecode * frameSize) + SAMPLES_PER_FRAME);
                        addr = DMEM_COMPRESSED_ADPCM_DATA - aligned;
                        aSetBuffer(aList++, 0, addr + sampleDataStartPad, DMEM_UNCOMPRESSED_NOTE + phi_s4,
                                   nSamplesToDecode * SAMPLE_SIZE);
                        aADPCMdec(aList++, flags | 4, synthState->synthesisBuffers->adpcmdecState);
                        break;

                    case CODEC_S8:
                        aligned = ALIGN16((nFramesToDecode * frameSize) + SAMPLES_PER_FRAME);
                        addr = DMEM_COMPRESSED_ADPCM_DATA - aligned;
                        AudioSynth_SetBuffer(aList++, 0, addr + sampleDataStartPad, DMEM_UNCOMPRESSED_NOTE + phi_s4,
                                             nSamplesToDecode * SAMPLE_SIZE);
                        AudioSynth_S8Dec(aList++, flags, synthState->synthesisBuffers->adpcmdecState);
                        break;
                }

                if (nSamplesProcessed != 0) {
                    aDMEMMove(aList++, DMEM_UNCOMPRESSED_NOTE + phi_s4 + (nFirstFrameSamplesToIgnore * SAMPLE_SIZE),
                              DMEM_UNCOMPRESSED_NOTE + s5, nSamplesInThisIteration * SAMPLE_SIZE);
                }

                nSamplesProcessed += nSamplesInThisIteration;

                switch (flags) {
                    case A_INIT:
                        skipBytes = SAMPLES_PER_FRAME * SAMPLE_SIZE;
                        s5 = (nSamplesToDecode + SAMPLES_PER_FRAME) * SAMPLE_SIZE;
                        break;

                    case A_LOOP:
                        s5 = nSamplesInThisIteration * SAMPLE_SIZE + s5;
                        break;

                    default:
                        if (s5 != 0) {
                            s5 = nSamplesInThisIteration * SAMPLE_SIZE + s5;
                        } else {
                            s5 = (nFirstFrameSamplesToIgnore + nSamplesInThisIteration) * SAMPLE_SIZE;
                        }
                        break;
                }

                flags = A_CONTINUE;
            skip:

                if (noteFinished) {
                    AudioSynth_ClearBuffer(aList++, DMEM_UNCOMPRESSED_NOTE + s5,
                                           (samplesLenAdjusted - nSamplesProcessed) * SAMPLE_SIZE);
                    finished = true;
                    note->noteSubEu.bitField0.finished = true;
                    func_8072EAA0(updateIndex, noteIndex);
                    break;
                } else {
                    if (restart) {
                        synthState->restart = true;
                        synthState->samplePosInt = loopInfo->header.start;
                    } else {
                        synthState->samplePosInt += nSamplesToProcess;
                    }
                }
            }

            switch (nParts) {
                case 1:
                    sampleDmemBeforeResampling = DMEM_UNCOMPRESSED_NOTE + skipBytes;
                    break;

                case 2:
                    switch (curPart) {
                        case 0:
                            AudioSynth_InterL(aList++, DMEM_UNCOMPRESSED_NOTE + skipBytes,
                                              DMEM_TEMP + (SAMPLES_PER_FRAME * SAMPLE_SIZE),
                                              ALIGN8(samplesLenAdjusted / 2));
                            resampledTempLen = samplesLenAdjusted;
                            sampleDmemBeforeResampling = DMEM_TEMP + (SAMPLES_PER_FRAME * SAMPLE_SIZE);
                            if (finished) {
                                AudioSynth_ClearBuffer(aList++, sampleDmemBeforeResampling + resampledTempLen,
                                                       samplesLenAdjusted + SAMPLES_PER_FRAME);
                            }
                            break;

                        case 1:
                            AudioSynth_InterL(aList++, DMEM_UNCOMPRESSED_NOTE + skipBytes,
                                              DMEM_TEMP + (SAMPLES_PER_FRAME * SAMPLE_SIZE) + resampledTempLen,
                                              ALIGN8(samplesLenAdjusted / 2));
                            break;
                    }
            }
            if (finished) {
                break;
            }
        }

        flags = A_CONTINUE;
        if (noteSubEu->bitField0.needsInit == true) {
            noteSubEu->bitField0.needsInit = false;
            flags = A_INIT;
        }

        aList = AudioSynth_FinalResample(aList, synthState, aiBufLen * (s32) SAMPLE_SIZE, resamplingRateFixedPoint,
                                         sampleDmemBeforeResampling, flags);
        if (bookOffset == 3) {
            AudioSynth_UnkCmd19(aList++, DMEM_TEMP, DMEM_TEMP, aiBufLen * SAMPLE_SIZE, 0);
        }

        gain = noteSubEu->gain;
        if (gain != 0) {
            if (gain < 0x10) {
                gain = 0x10;
            }
            AudioSynth_HiLoGain(aList++, gain, DMEM_TEMP, 0, (aiBufLen + SAMPLES_PER_FRAME) * SAMPLE_SIZE);
        }

        filter = noteSubEu->filter;
        if (filter != NULL) {
            AudioSynth_LoadFilterSize(aList++, aiBufLen * SAMPLE_SIZE, filter);
            AudioSynth_LoadFilterBuffer(aList++, flags, DMEM_TEMP, synthState->synthesisBuffers->mixEnvelopeState);
        }

        if ((noteSubEu->haasEffectLeftDelaySize != 0) || (synthState->prevHaasEffectLeftDelaySize != 0)) {
            haasEffectDelaySide = HAAS_EFFECT_DELAY_LEFT;
        } else if ((noteSubEu->haasEffectRightDelaySize != 0) || (synthState->prevHaasEffectRightDelaySize != 0)) {
            haasEffectDelaySide = HAAS_EFFECT_DELAY_RIGHT;
        } else {
            haasEffectDelaySide = HAAS_EFFECT_DELAY_NONE;
        }

        aList =
            AudioSynth_ProcessEnvelope(aList, noteSubEu, synthState, aiBufLen, DMEM_TEMP, haasEffectDelaySide, flags);
    }

    return aList;
}

Acmd* AudioSynth_FinalResample(Acmd* aList, NoteSynthesisState* synthState, s32 size, u16 pitch, u16 inpDmem,
                               s32 resampleFlags) {
    if (pitch == 0) {
        AudioSynth_ClearBuffer(aList++, DMEM_TEMP, size);
    } else {
        aSetBuffer(aList++, 0, inpDmem, DMEM_TEMP, size);
        aResample(aList++, resampleFlags, pitch, synthState->synthesisBuffers->finalResampleState);
    }
    return aList;
}

Acmd* AudioSynth_ProcessEnvelope(Acmd* aList, NoteSubEu* noteSubEu, NoteSynthesisState* synthState, s32 aiBufLen,
                                 u16 dmemSrc, s32 haasEffectDelaySide, s32 flags) {
    u32 dmemDests;
    u16 curVolLeft;
    u16 targetVolLeft;
    s32 phi_t1;
    s16 reverbVol;
    u16 curVolRight;
    s16 rampLeft;
    s16 rampRight;
    s16 rampReverb;
    s16 sourceReverbVol;
    u16 targetVolRight;
    s32 pad;

    reverbVol = noteSubEu->reverbVol;
    curVolLeft = synthState->curVolLeft;
    curVolRight = synthState->curVolRight;
    targetVolLeft = noteSubEu->targetVolLeft;
    targetVolRight = noteSubEu->targetVolRight;
    targetVolLeft <<= 4;
    targetVolRight <<= 4;

    if (targetVolLeft != curVolLeft) {
        rampLeft = (targetVolLeft - curVolLeft) / (aiBufLen >> 3);
    } else {
        rampLeft = 0;
    }
    if (targetVolRight != curVolRight) {
        rampRight = (targetVolRight - curVolRight) / (aiBufLen >> 3);
    } else {
        rampRight = 0;
    }

    sourceReverbVol = synthState->reverbVol;
    phi_t1 = sourceReverbVol & 0x7F;

    if (sourceReverbVol != reverbVol) {
        rampReverb = (((reverbVol & 0x7F) - phi_t1) << 9) / (aiBufLen >> 3);
        synthState->reverbVol = reverbVol;
    } else {
        rampReverb = 0;
    }

    synthState->curVolLeft = curVolLeft + (rampLeft * (aiBufLen >> 3));
    synthState->curVolRight = curVolRight + (rampRight * (aiBufLen >> 3));

    aEnvSetup1(aList++, phi_t1 * 2, rampReverb, rampLeft, rampRight);
    aEnvSetup2(aList++, curVolLeft, curVolRight);
    dmemDests = sEnvMixerDefaultDmemDests;

    aEnvMixer(aList++, dmemSrc, aiBufLen, (sourceReverbVol & 0x80) >> 7, noteSubEu->bitField0.stereoHeadsetEffects,
              noteSubEu->bitField0.usesHeadsetPanEffects, noteSubEu->bitField0.stereoStrongRight,
              noteSubEu->bitField0.stereoStrongLeft, dmemDests, sEnvMixerOp);

    return aList;
}
