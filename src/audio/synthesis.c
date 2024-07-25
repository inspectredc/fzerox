#include "global.h"
#include "audio.h"

void func_800B4C40(s32 sampleCount, s32 itemIndex, s32 reverbIndex) {
    ReverbRingBufferItem* ringItem;
    SynthesisReverb* reverb = &gSynthReverbs[reverbIndex];
    s32 extraSamples;
    s32 i;
    s32 j;

    ringItem = &reverb->items[reverb->curFrame][itemIndex];
    extraSamples = reverb->nextRingBufPos + sampleCount - reverb->bufSizePerChan;

    if (extraSamples < 0) {
        ringItem->lengthA = sampleCount * SAMPLE_SIZE;
        ringItem->lengthB = 0;
        ringItem->startPos = reverb->nextRingBufPos;
        reverb->nextRingBufPos += sampleCount;
    } else {
        ringItem->lengthA = (sampleCount - extraSamples) * SAMPLE_SIZE;
        ringItem->lengthB = extraSamples * SAMPLE_SIZE;
        ringItem->startPos = reverb->nextRingBufPos;
        reverb->nextRingBufPos = extraSamples;
    }
    ringItem->numSamplesAfterDownsampling = sampleCount;
    ringItem->chunkLen = sampleCount;
}

Acmd* func_800B4CEC(Acmd* aList, u16 dmem, u16 startPos, s32 size, s32 reverbIndex) {
    aLoadBuffer(aList++, OS_K0_TO_PHYSICAL(&gSynthReverbs[reverbIndex].leftRingBuf[startPos]), dmem, size);
    aLoadBuffer(aList++, OS_K0_TO_PHYSICAL(&gSynthReverbs[reverbIndex].rightRingBuf[startPos]), dmem + DMEM_1CH_SIZE,
                size);
    return aList;
}

Acmd* func_800B4D80(Acmd* aList, u16 dmem, u16 startPos, s32 size, s32 reverbIndex) {
    aSaveBuffer(aList++, dmem, OS_K0_TO_PHYSICAL(&gSynthReverbs[reverbIndex].leftRingBuf[startPos]), size);
    aSaveBuffer(aList++, dmem + DMEM_1CH_SIZE, OS_K0_TO_PHYSICAL(&gSynthReverbs[reverbIndex].rightRingBuf[startPos]),
                size);
    return aList;
}

void func_800B4E14(s32 updateIndex, s32 noteIndex) {
    NoteSubEu* noteSubEu;
    s32 i;

    for (i = updateIndex + 1; i < gAudioBufferParams.ticksPerUpdate; i++) {
        if (!gNoteSubsEu[(gNumNotes * i) + noteIndex].bitField.needsInit) {
            gNoteSubsEu[(gNumNotes * i) + noteIndex].bitField.enabled = false;
        } else {
            break;
        }
    }
}

void func_800B4E94(s32 updateIndex) {
    NoteSubEu* subEu;
    NoteSubEu* subEu2;
    s32 i;

    for (i = 0; i < gNumNotes; i++) {
        subEu = &gNotes[i].noteSubEu;
        subEu2 = &gNoteSubsEu[gNumNotes * updateIndex + i];
        if (subEu->bitField.enabled) {
            *subEu2 = *subEu;
            subEu->bitField.needsInit = false;
        } else {
            subEu2->bitField.enabled = false;
        }
    }
}

Acmd* func_800B5358(s16* aiBuf, s32 aiBufLen, Acmd* aList, s32 updateIndex);

Acmd* func_800B4F4C(Acmd* aList, s32* cmdCount, s16* aiBufStart, s32 aiBufLen) {
    Acmd* aCmdPtr;
    s32* aiBufPtr;
    s32 chunkLen;
    s32 i;
    s32 j;

    aCmdPtr = aList;
    for (i = gAudioBufferParams.ticksPerUpdate; i > 0; i--) {
        func_800AE624(i - 1);
        func_800B4E94(gAudioBufferParams.ticksPerUpdate - i);
    }

    aiBufPtr = (s32*) aiBufStart;
    gCurLoadedBook = NULL;

    for (i = gAudioBufferParams.ticksPerUpdate; i > 0; i--) {
        if (i == 1) {
            chunkLen = aiBufLen;
        } else if ((aiBufLen / i) >= gAudioBufferParams.samplesPerTickMax) {
            chunkLen = gAudioBufferParams.samplesPerTickMax;
        } else if (gAudioBufferParams.samplesPerTickMin >= (aiBufLen / i)) {
            chunkLen = gAudioBufferParams.samplesPerTickMin;
        } else {
            chunkLen = gAudioBufferParams.samplesPerTick;
        }
        for (j = 0; j < gNumSynthReverbs; j++) {
            if (gSynthReverbs[j].useReverb) {
                func_800B4C40(chunkLen, gAudioBufferParams.ticksPerUpdate - i, j);
            }
        }
        aCmdPtr = func_800B5358((s16*) aiBufPtr, chunkLen, aCmdPtr, gAudioBufferParams.ticksPerUpdate - i);
        aiBufLen -= chunkLen;
        aiBufPtr += chunkLen;
    }
    for (j = 0; j < gNumSynthReverbs; j++) {
        if (gSynthReverbs[j].framesToIgnore != 0) {
            gSynthReverbs[j].framesToIgnore--;
        }
        gSynthReverbs[j].curFrame ^= 1;
    }
    *cmdCount = aCmdPtr - aList;
    return aCmdPtr;
}

Acmd* func_800B5160(Acmd* aList, s32 aiBufLen, s16 reverbIndex, s16 updateIndex) {
    ReverbRingBufferItem* bufItem = &gSynthReverbs[reverbIndex].items[gSynthReverbs[reverbIndex].curFrame][updateIndex];
    s32 pad;

    aList = func_800B4CEC(aList, DMEM_WET_LEFT_CH, bufItem->startPos, bufItem->lengthA, reverbIndex);
    if (bufItem->lengthB != 0) {
        aList = func_800B4CEC(aList, bufItem->lengthA + DMEM_WET_LEFT_CH, 0, bufItem->lengthB, reverbIndex);
    }
    aMix(aList++, DMEM_2CH_SIZE >> 4, gSynthReverbs[reverbIndex].volume, DMEM_WET_LEFT_CH, DMEM_LEFT_CH);
    aMix(aList++, DMEM_2CH_SIZE >> 4, gSynthReverbs[reverbIndex].decayRatio + 0x8000, DMEM_WET_LEFT_CH,
         DMEM_WET_LEFT_CH);

    return aList;
}

void func_800B5278(void) {
}

Acmd* func_800B5280(Acmd* aList, s16 reverbIndex, s16 updateIndex) {
    ReverbRingBufferItem* bufItem = &gSynthReverbs[reverbIndex].items[gSynthReverbs[reverbIndex].curFrame][updateIndex];

    aList = func_800B4D80(aList, 0xC80, bufItem->startPos, bufItem->lengthA, reverbIndex);
    if (bufItem->lengthB != 0) {
        aList = func_800B4D80(aList, bufItem->lengthA + 0xC80, 0, bufItem->lengthB, reverbIndex);
    }

    gSynthReverbs[reverbIndex].resampleFlags = 0;

    return aList;
}

void func_800B5350(void) {
}

Acmd* func_800B5588(s32 noteIndex, NoteSubEu* noteSub, NoteSynthesisState* synthState, s16* aiBuf, s32 aiBufLen,
                    Acmd* aList, s32 updateIndex);

Acmd* func_800B5358(s16* aiBuf, s32 aiBufLen, Acmd* aList, s32 updateIndex) {
    u8 noteIndices[0x3C];
    s32 i;
    s16 count = 0;

    aClearBuffer(aList++, DMEM_LEFT_CH, DMEM_2CH_SIZE);

    gUseReverb = gSynthReverbs[0].useReverb;

    if (gUseReverb) {
        aList = func_800B5160(aList, aiBufLen, 0, updateIndex);
    }

    for (i = 0; i < gNumNotes; i++) {
        if (gNoteSubsEu[gNumNotes * updateIndex + i].bitField.enabled) {
            noteIndices[count++] = i;
        }
    }

    for (i = 0; i < count; i++) {
        aList = func_800B5588(noteIndices[i], &gNoteSubsEu[updateIndex * gNumNotes + noteIndices[i]],
                              &gNotes[noteIndices[i]].synthesisState, aiBuf, aiBufLen, aList, updateIndex);
    }

    if (gSynthReverbs[0].useReverb) {
        aList = func_800B5280(aList, 0, updateIndex);
    }

    i = aiBufLen * SAMPLE_SIZE;

    aInterleave(aList++, DMEM_TEMP, DMEM_LEFT_CH, DMEM_RIGHT_CH, aiBufLen * 2);
    aSaveBuffer(aList++, DMEM_TEMP, OS_K0_TO_PHYSICAL(aiBuf), i * 2);
    return aList;
}

Acmd* func_800B5CE8(Acmd* aList, NoteSynthesisState* synthState, s32 size, u16 pitch, u16 inpDmem, u32 resampleFlags);
Acmd* func_800B5D80(Acmd* aList, NoteSubEu* noteSub, NoteSynthesisState* synthState, s32 aiBufLen, u16 dmemSrc,
                    s32 delaySide, s32 flags);

Acmd* func_800B5588(s32 noteIndex, NoteSubEu* noteSub, NoteSynthesisState* synthState, s16* aiBuf, s32 aiBufLen,
                    Acmd* aList, s32 updateIndex) {
    s16 addr;
    s32 frameIndex;
    Sample* bookSample;
    s32 padX[0x1];
    AdpcmLoop* loopInfo;
    s32 nSamplesUntilLoopEnd;
    s32 sampleDataStartPad;
    s32 noteFinished;
    s32 restart;
    s32 nFramesToDecode;
    u16 resamplingRateFixedPoint;
    s32 flags;
    u8* sampleData;
    s32 nSamplesProcessed;
    s32 aligned;
    s32 skipBytes;
    s32 var_t4;
    s32 var_t2;
    s32 sampleDataOffset;
    u8* sampleAddr;
    u32 sampleslenFixedPoint;
    u32 nSamplesToLoad;
    u32 nEntries;
    u32 loopEndPos;
    s32 nSamplesToProcess;
    s32 pad0[0x1];
    s32 nFirstFrameSamplesToIgnore;
    s32 nSamplesToDecode;
    s32 pad1[0x1];
    s32 nSamplesInFirstFrame;
    s32 nTrailingSamplesToIgnore;
    s32 pad2[0x3];
    s32 frameSize;
    s32 nSamplesInThisIteration;
    s32 skipInitialSamples;
    s32 sampleDataStart;
    s32 pad3[0xA];
    Note* note;
    s32 pad4[0x3];

    note = &gNotes[noteIndex];
    if (noteSub->tunedSample != NULL) {
        flags = 0;
        if (noteSub->bitField.needsInit == 1) {
            flags = 1;
            synthState->restart = 0;
            synthState->samplePosInt = 0;
            synthState->samplePosFrac = 0;
            synthState->curVolLeft = 0;
            synthState->curVolRight = 0;
            synthState->prevHaasEffectLeftDelaySize = 0;
            synthState->prevHaasEffectRightDelaySize = 0;
            synthState->reverbVol = noteSub->bitField.reverb;
            synthState->numParts = 0;
            note->noteSubEu.bitField.finished = 0;
        }
        resamplingRateFixedPoint = noteSub->resampleRate;
        nSamplesProcessed = 0;

        var_t2 = 0;
        sampleslenFixedPoint = resamplingRateFixedPoint * aiBufLen * 2 + synthState->samplePosFrac;
        synthState->samplePosFrac = sampleslenFixedPoint & 0xFFFF;

        bookSample = noteSub->tunedSample->sample;
        loopInfo = bookSample->loop;
        loopEndPos = loopInfo->end;
        sampleAddr = bookSample->sampleAddr;

        nSamplesToLoad = sampleslenFixedPoint >> 16;
        if (bookSample->codec == 0 && gCurLoadedBook != bookSample->book->book) {
            gCurLoadedBook = bookSample->book->book;
            nEntries = 16 * bookSample->book->order * bookSample->book->numPredictors;
            aLoadADPCM(aList++, nEntries, OS_K0_TO_PHYSICAL(gCurLoadedBook));
        }

        while (nSamplesProcessed != nSamplesToLoad) {

            noteFinished = 0;
            restart = 0;
            nFirstFrameSamplesToIgnore = synthState->samplePosInt & 0xF;
            nSamplesUntilLoopEnd = loopEndPos - synthState->samplePosInt;
            nSamplesToProcess = nSamplesToLoad - nSamplesProcessed;
            var_t4 = 0;

            if ((nFirstFrameSamplesToIgnore == 0) && (synthState->restart == 0)) {
                nFirstFrameSamplesToIgnore = SAMPLES_PER_FRAME;
            }
            nSamplesInFirstFrame = SAMPLES_PER_FRAME - nFirstFrameSamplesToIgnore;

            if (nSamplesToProcess < nSamplesUntilLoopEnd) {
                nFramesToDecode = (s32) ((nSamplesToProcess - nSamplesInFirstFrame) + 0xF) / SAMPLES_PER_FRAME;
                nSamplesToDecode = nFramesToDecode * SAMPLES_PER_FRAME;
                nTrailingSamplesToIgnore = (nSamplesInFirstFrame + nSamplesToDecode) - nSamplesToProcess;
            } else {
                nSamplesToDecode = nSamplesUntilLoopEnd - nSamplesInFirstFrame;
                nTrailingSamplesToIgnore = 0;
                if (nSamplesToDecode <= 0) {
                    nSamplesToDecode = 0;
                    nSamplesInFirstFrame = nSamplesUntilLoopEnd;
                }
                nFramesToDecode = (s32) (nSamplesToDecode + SAMPLES_PER_FRAME - 1) / SAMPLES_PER_FRAME;
                if (loopInfo->count != 0) {
                    restart = true;
                } else {
                    noteFinished = true;
                }
            }
            switch (bookSample->codec) {
                case 0:
                    frameSize = 9;
                    skipInitialSamples = SAMPLES_PER_FRAME;
                    sampleDataStart = 0;
                    break;
                case 1:
                    frameSize = 16;
                    skipInitialSamples = SAMPLES_PER_FRAME;
                    sampleDataStart = 0;
                    break;
            }

            if (nFramesToDecode != 0) {
                frameIndex =
                    (synthState->samplePosInt + skipInitialSamples - nFirstFrameSamplesToIgnore) / SAMPLES_PER_FRAME;
                sampleDataOffset = frameIndex * frameSize;
                if (bookSample->medium == 0) {
                    sampleData = sampleDataStart + sampleDataOffset + sampleAddr;
                } else {
                    sampleData = func_800AEB28(sampleDataStart + sampleDataOffset + sampleAddr,
                                               ALIGN16((nFramesToDecode * frameSize) + SAMPLES_PER_FRAME), flags,
                                               &synthState->sampleDmaIndex, bookSample->medium);
                }
                sampleDataStartPad = (u32) sampleData & 0xF;
                aligned = ALIGN16((nFramesToDecode * frameSize) + SAMPLES_PER_FRAME);
                addr = DMEM_COMPRESSED_ADPCM_DATA - aligned;
                aLoadBuffer(aList++, OS_K0_TO_PHYSICAL(sampleData - sampleDataStartPad), addr, aligned);
            } else {
                nSamplesToDecode = 0;
                sampleDataStartPad = 0;
            }
            if (synthState->restart != 0) {
                aSetLoop(aList++, OS_K0_TO_PHYSICAL(bookSample->loop->predictorState));
                flags = 2;
                synthState->restart = 0;
            }

            if (nSamplesProcessed == 0) {
                skipBytes = nFirstFrameSamplesToIgnore * SAMPLE_SIZE;
            } else {
                var_t4 = ALIGN16(var_t2 + SAMPLES_PER_FRAME);
            }
            switch (bookSample->codec) {
                case 0:
                    aligned = ALIGN16((nFramesToDecode * frameSize) + SAMPLES_PER_FRAME);
                    addr = DMEM_COMPRESSED_ADPCM_DATA - aligned;
                    aSetBuffer(aList++, 0, addr + sampleDataStartPad, DMEM_UNCOMPRESSED_NOTE + var_t4,
                               nSamplesToDecode * SAMPLE_SIZE);
                    aADPCMdec(aList++, flags, OS_K0_TO_PHYSICAL(synthState->synthesisBuffers));
                    break;
                case 1:
                    aligned = ALIGN16((nFramesToDecode * frameSize) + SAMPLES_PER_FRAME);
                    addr = DMEM_COMPRESSED_ADPCM_DATA - aligned;
                    aSetBuffer(aList++, 0, addr + sampleDataStartPad, DMEM_UNCOMPRESSED_NOTE + var_t4,
                               nSamplesToDecode * SAMPLE_SIZE);
                    aS8Dec(aList++, flags, OS_K0_TO_PHYSICAL(synthState->synthesisBuffers));
                    break;
            }
            if (nSamplesProcessed != 0) {
                aDMEMMove(aList++, (var_t4 + (nFirstFrameSamplesToIgnore * SAMPLE_SIZE) + DMEM_UNCOMPRESSED_NOTE),
                          var_t2 + DMEM_UNCOMPRESSED_NOTE,
                          (((nSamplesToDecode + nSamplesInFirstFrame) - nTrailingSamplesToIgnore) * SAMPLE_SIZE));
            }
            nSamplesInThisIteration = (nSamplesToDecode + nSamplesInFirstFrame) - nTrailingSamplesToIgnore;
            nSamplesProcessed += nSamplesInThisIteration;
            switch (flags) {
                case 1:
                    skipBytes = SAMPLES_PER_FRAME * SAMPLE_SIZE;
                    var_t2 = (nSamplesToDecode * SAMPLE_SIZE) + (SAMPLES_PER_FRAME * SAMPLE_SIZE);
                    break;
                case 2:
                    var_t2 = nSamplesInThisIteration * SAMPLE_SIZE + var_t2;
                    break;
                default:
                    if (var_t2 != 0) {
                        var_t2 = nSamplesInThisIteration * SAMPLE_SIZE + var_t2;
                    } else {
                        var_t2 = (nFirstFrameSamplesToIgnore + nSamplesInThisIteration) * SAMPLE_SIZE;
                    }
                    break;
            }
            flags = 0;

            if (noteFinished) {
                aClearBuffer(aList++, var_t2 + DMEM_UNCOMPRESSED_NOTE,
                             (nSamplesToLoad - nSamplesProcessed) * SAMPLE_SIZE);
                noteSub->bitField.finished = true;
                note->noteSubEu.bitField.finished = true;
                func_800B4E14(updateIndex, noteIndex);
                break;
            }

            if (restart) {
                synthState->restart = true;
                synthState->samplePosInt = (s32) loopInfo->start;
            } else {
                synthState->samplePosInt += nSamplesToProcess;
            }
        }
        flags = 0;
        if (noteSub->bitField.needsInit == 1) {
            flags = 1;
            noteSub->bitField.needsInit = 0;
        }
        aList = func_800B5CE8(aList, synthState, aiBufLen * 2, resamplingRateFixedPoint,
                              (u16) (skipBytes + DMEM_UNCOMPRESSED_NOTE), flags);
        aList = func_800B5D80(aList, noteSub, synthState, aiBufLen, DMEM_TEMP, 0, flags);
    }
    return aList;
}

Acmd* func_800B5CE8(Acmd* aList, NoteSynthesisState* synthState, s32 size, u16 pitch, u16 inpDmem, u32 resampleFlags) {
    if (pitch == 0) {
        aClearBuffer(aList++, 0x3C0, size);
    } else {
        aSetBuffer(aList++, 0, inpDmem, 0x3C0, size);
        aResample(aList++, resampleFlags, pitch, OS_K0_TO_PHYSICAL(synthState->synthesisBuffers->finalResampleState));
    }
    return aList;
}

Acmd* func_800B5D80(Acmd* aList, NoteSubEu* noteSub, NoteSynthesisState* synthState, s32 aiBufLen, u16 dmemSrc,
                    s32 delaySide, s32 flags) {
    s16 rampRight;
    s16 rampLeft;
    u16 targetVolLeft;
    u16 targetVolRight;
    u16 curVolLeft;
    u16 curVolRight;
    s32 sourceReverbVol;
    s32 temp = 0;
    s16 rampReverb;

    curVolLeft = synthState->curVolLeft;
    curVolRight = synthState->curVolRight;

    targetVolLeft = noteSub->panVolLeft;
    targetVolRight = noteSub->panVolRight;

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

    if (noteSub->bitField.reverb != sourceReverbVol) {
        temp = (((noteSub->bitField.reverb & 0x7F) - (sourceReverbVol & 0x7F)) << 9);
        rampReverb = temp / (aiBufLen >> 3);
        synthState->reverbVol = noteSub->bitField.reverb;
    } else {
        rampReverb = 0;
    }
    synthState->curVolLeft = curVolLeft + (rampLeft * (aiBufLen >> 3));
    synthState->curVolRight = curVolRight + (rampRight * (aiBufLen >> 3));

    aEnvSetup1(aList++, (sourceReverbVol & 0x7F) << 1, rampReverb, rampLeft, rampRight);
    aEnvSetup2(aList++, curVolLeft, curVolRight);
    aEnvMixer(aList++, dmemSrc, aiBufLen, 0, 0, ((sourceReverbVol & 0x80) >> 7), 0, 0,
              AUDIO_MK_CMD(DMEM_LEFT_CH >> 4, DMEM_RIGHT_CH >> 4, DMEM_WET_LEFT_CH >> 4, DMEM_WET_RIGHT_CH >> 4));

    return aList;
}
