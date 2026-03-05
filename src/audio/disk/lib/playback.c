#include "global.h"
#include "audio.h"

extern f32 gDefaultPanVolume[];
extern f32 gHeadsetPanVolume[];
extern f32 gStereoPanVolume[];
extern u16 gHaasEffectDelaySizes[];

void Audio_InitNoteSub(Note* note, NoteSubAttributes* noteAttr) {
    f32 volLeft;
    f32 volRight;
    s32 halfPanIndex;
    s32 pad[3];
    u8 strongLeft;
    u8 strongRight;
    f32 velocity;
    u8 pan;
    u8 reverbVol;
    StereoData stereoData;
    NoteSubEu* noteSub;
    s32 stereoHeadsetEffects = note->playbackState.stereoHeadsetEffects;

    Audio_NoteSetResamplingRate(note, noteAttr->frequency);
    noteSub = &note->noteSubEu;
    velocity = noteAttr->velocity;
    pan = noteAttr->pan;
    reverbVol = noteAttr->reverbVol;
    stereoData = noteAttr->stereo.s;

    pan &= 0x7F;

    noteSub->bitField0.stereoStrongRight = false;
    noteSub->bitField0.stereoStrongLeft = false;
    noteSub->bitField0.stereoHeadsetEffects = stereoData.stereoHeadsetEffects;
    noteSub->bitField0.usesHeadsetPanEffects = stereoData.usesHeadsetPanEffects;
    if (stereoHeadsetEffects && (gAudioCtx.soundMode == SOUNDMODE_HEADSET)) {
        halfPanIndex = pan >> 1;
        if (halfPanIndex > 0x3F) {
            halfPanIndex = 0x3F;
        }

        noteSub->haasEffectRightDelaySize = gHaasEffectDelaySizes[halfPanIndex];
        noteSub->haasEffectLeftDelaySize = gHaasEffectDelaySizes[0x3F - halfPanIndex];
        noteSub->bitField1.useHaasEffect = true;

        volLeft = gHeadsetPanVolume[pan];
        volRight = gHeadsetPanVolume[0x7F - pan];
    } else if (stereoHeadsetEffects && (gAudioCtx.soundMode == SOUNDMODE_STEREO)) {
        strongLeft = strongRight = 0;
        noteSub->haasEffectLeftDelaySize = 0;
        noteSub->haasEffectRightDelaySize = 0;
        noteSub->bitField1.useHaasEffect = false;

        volLeft = gStereoPanVolume[pan];
        volRight = gStereoPanVolume[0x7F - pan];
        if (pan < 0x20) {
            strongLeft = 1;
        } else if (pan > 0x60) {
            strongRight = 1;
        }

        noteSub->bitField0.stereoStrongRight = strongRight;
        noteSub->bitField0.stereoStrongLeft = strongLeft;

        switch (stereoData.bit2) {
            case 0:
                break;

            case 1:
                noteSub->bitField0.stereoStrongRight = stereoData.strongRight;
                noteSub->bitField0.stereoStrongLeft = stereoData.strongLeft;
                break;

            case 2:
                noteSub->bitField0.stereoStrongRight = stereoData.strongRight | strongRight;
                noteSub->bitField0.stereoStrongLeft = stereoData.strongLeft | strongLeft;
                break;

            case 3:
                noteSub->bitField0.stereoStrongRight = stereoData.strongRight ^ strongRight;
                noteSub->bitField0.stereoStrongLeft = stereoData.strongLeft ^ strongLeft;
                break;
        }

    } else if (gAudioCtx.soundMode == SOUNDMODE_MONO) {
        noteSub->bitField0.stereoHeadsetEffects = false;
        noteSub->bitField0.usesHeadsetPanEffects = false;
        volLeft = 0.707f;
        volRight = 0.707f;
    } else {
        noteSub->bitField0.stereoStrongRight = stereoData.strongRight;
        noteSub->bitField0.stereoStrongLeft = stereoData.strongLeft;
        volLeft = gDefaultPanVolume[pan];
        volRight = gDefaultPanVolume[0x7F - pan];
    }

    velocity = 0.0f > velocity ? 0.0f : velocity;
    velocity = 1.0f < velocity ? 1.0f : velocity;

    noteSub->targetVolLeft = (s32) ((velocity * volLeft) * (0x1000 - 0.001f));
    noteSub->targetVolRight = (s32) ((velocity * volRight) * (0x1000 - 0.001f));

    noteSub->gain = noteAttr->gain;
    noteSub->filter = noteAttr->filter;
    noteSub->reverbVol = reverbVol;
}

void Audio_NoteSetResamplingRate(Note* note, f32 freqScale) {
    NoteSubEu* noteSub = &note->noteSubEu;
    f32 resamplingRate = 0.0f;

    if (freqScale < 2.0f) {
        noteSub->bitField1.hasTwoParts = false;
        if (freqScale > 1.99998f) {
            resamplingRate = 1.99998f;
        } else {
            resamplingRate = freqScale;
        }

    } else {
        noteSub->bitField1.hasTwoParts = true;
        if (freqScale > 3.99996f) {
            resamplingRate = 1.99998f;
        } else {
            resamplingRate = freqScale * 0.5f;
        }
    }
    note->noteSubEu.resamplingRateFixedPoint = (s32) (resamplingRate * 32768.0f);
}

extern NoteSubEu gDefaultNoteSub;

void Audio_NoteInit(Note* note) {
    if (note->playbackState.parentLayer->adsr.decayIndex == 0) {
        Audio_AdsrInit(&note->playbackState.adsr, note->playbackState.parentLayer->channel->adsr.envelope,
                       &note->playbackState.adsrVolScaleUnused);
    } else {
        Audio_AdsrInit(&note->playbackState.adsr, note->playbackState.parentLayer->adsr.envelope,
                       &note->playbackState.adsrVolScaleUnused);
    }

    note->playbackState.unk_04 = 0;
    note->playbackState.adsr.action.s.state = ADSR_STATE_INITIAL;
    note->noteSubEu = gDefaultNoteSub;
}

void Audio_NoteDisable(Note* note) {
    if (note->noteSubEu.bitField0.needsInit == true) {
        note->noteSubEu.bitField0.needsInit = false;
    }
    note->playbackState.priority = 0;
    note->noteSubEu.bitField0.enabled = false;
    note->playbackState.unk_04 = 0;
    note->noteSubEu.bitField0.finished = false;
    note->playbackState.parentLayer = NO_LAYER;
    note->playbackState.prevParentLayer = NO_LAYER;
    note->playbackState.adsr.action.s.state = ADSR_STATE_DISABLED;
    note->playbackState.adsr.current = 0;
}

void Audio_ProcessNotes(void) {
    s32 pad[2];
    NoteAttributes* noteAttr;
    NoteSubEu* noteSubEu;
    Note* note;
    NotePlaybackState* playbackState;
    NoteSubAttributes subAttrs;
    u8 bookOffset;
    f32 scale;
    s32 i;

    for (i = 0; i < gAudioCtx.numNotes; i++) {
        note = &gAudioCtx.notes[i];
        playbackState = &note->playbackState;
        if (playbackState->parentLayer != NO_LAYER) {
            if ((u32) playbackState->parentLayer < 0x7FFFFFFF) {
                continue;
            }

            if (note != playbackState->parentLayer->note && playbackState->unk_04 == 0) {
                playbackState->adsr.action.s.release = true;
                playbackState->adsr.fadeOutVel = gAudioCtx.audioBufferParameters.ticksPerUpdateInv;
                playbackState->priority = 1;
                playbackState->unk_04 = 2;
                goto out;
            } else if (!playbackState->parentLayer->enabled && playbackState->unk_04 == 0 &&
                       playbackState->priority >= 1) {
                // do nothing
            } else if (playbackState->parentLayer->channel->seqPlayer == NULL) {
                AudioSeq_SequenceChannelDisable(playbackState->parentLayer->channel);
                playbackState->priority = 1;
                playbackState->unk_04 = 1;
                continue;
            } else if (playbackState->parentLayer->channel->seqPlayer->muted &&
                       (playbackState->parentLayer->channel->muteBehavior & MUTE_BEHAVIOR_STOP_NOTES)) {
                // do nothing
            } else {
                goto out;
            }

            Audio_SeqLayerNoteRelease(playbackState->parentLayer);
            Audio_AudioListRemove(&note->listItem);
            Audio_AudioListPushFront(&note->listItem.pool->decaying, &note->listItem);
            playbackState->priority = 1;
            playbackState->unk_04 = 2;
        } else if (playbackState->unk_04 == 0 && playbackState->priority >= 1) {
            continue;
        }

    out:
        if (playbackState->priority != 0) {
            if (1) {}
            noteSubEu = &note->noteSubEu;
            if (playbackState->unk_04 >= 1 || noteSubEu->bitField0.finished) {
                if (playbackState->adsr.action.s.state == ADSR_STATE_DISABLED || noteSubEu->bitField0.finished) {
                    if (playbackState->wantedParentLayer != NO_LAYER) {
                        Audio_NoteDisable(note);
                        if (playbackState->wantedParentLayer->channel != NULL) {
                            Audio_NoteInitForLayer(note, playbackState->wantedParentLayer);
                            Audio_NoteVibratoInit(note);
                            Audio_NotePortamentoInit(note);
                            Audio_AudioListRemove(&note->listItem);
                            AudioSeq_AudioListPushBack(&note->listItem.pool->active, &note->listItem);
                            playbackState->wantedParentLayer = NO_LAYER;
                        } else {
                            Audio_NoteDisable(note);
                            Audio_AudioListRemove(&note->listItem);
                            AudioSeq_AudioListPushBack(&note->listItem.pool->disabled, &note->listItem);
                            playbackState->wantedParentLayer = NO_LAYER;
                            goto next;
                        }
                    } else {
                        if (playbackState->parentLayer != NO_LAYER) {
                            playbackState->parentLayer->bit1 = true;
                        }
                        Audio_NoteDisable(note);
                        Audio_AudioListRemove(&note->listItem);
                        AudioSeq_AudioListPushBack(&note->listItem.pool->disabled, &note->listItem);
                        goto next;
                    }
                }
            } else if (playbackState->adsr.action.s.state == ADSR_STATE_DISABLED) {
                if (playbackState->parentLayer != NO_LAYER) {
                    playbackState->parentLayer->bit1 = true;
                }
                Audio_NoteDisable(note);
                Audio_AudioListRemove(&note->listItem);
                AudioSeq_AudioListPushBack(&note->listItem.pool->disabled, &note->listItem);
                goto next;
            }

            scale = Audio_AdsrUpdate(&playbackState->adsr);
            Audio_NoteVibratoUpdate(note);
            noteAttr = &playbackState->attributes;
            if (playbackState->unk_04 == 1 || playbackState->unk_04 == 2) {
                subAttrs.frequency = noteAttr->freqScale;
                subAttrs.velocity = noteAttr->velocity;
                subAttrs.pan = noteAttr->pan;
                subAttrs.reverbVol = noteAttr->reverb;
                subAttrs.stereo = noteAttr->stereo;
                subAttrs.gain = noteAttr->gain;
                subAttrs.filter = noteAttr->filter;
                bookOffset = noteSubEu->bitField1.bookOffset;
            } else {
                SequenceLayer* layer = playbackState->parentLayer;
                SequenceChannel* channel = layer->channel;

                subAttrs.frequency = layer->noteFreqScale;
                subAttrs.velocity = layer->noteVelocity;
                subAttrs.pan = layer->notePan;
                if (layer->stereo.asByte == 0) {
                    subAttrs.stereo = channel->stereo;
                } else {
                    subAttrs.stereo = layer->stereo;
                }
                subAttrs.reverbVol = channel->targetReverbVol;
                subAttrs.gain = channel->gain;
                subAttrs.filter = channel->filter;
                bookOffset = channel->bookOffset & 0x7;

                if (channel->seqPlayer->muted && (channel->muteBehavior & MUTE_BEHAVIOR_3)) {
                    subAttrs.frequency = 0.0f;
                    subAttrs.velocity = 0.0f;
                }
            }

            subAttrs.frequency *= playbackState->vibratoFreqScale * playbackState->portamentoFreqScale;
            subAttrs.frequency *= gAudioCtx.audioBufferParameters.resampleRate;
            subAttrs.velocity *= scale;
            Audio_InitNoteSub(note, &subAttrs);
            noteSubEu->bitField1.bookOffset = bookOffset;
        next:;
        }
    }
}

TunedSample* Audio_GetInstrumentTunedSample(Instrument* instrument, s32 semitone) {
    TunedSample* sample;

    if (semitone < instrument->normalRangeLo) {
        sample = &instrument->lowPitchTunedSample;
    } else if (semitone <= instrument->normalRangeHi) {
        sample = &instrument->normalPitchTunedSample;
    } else {
        sample = &instrument->highPitchTunedSample;
    }
    return sample;
}

Instrument* Audio_GetInstrument(s32 fontId, s32 instId) {
    Instrument* inst;

    if (fontId == 0xFF) {
        return NULL;
    }

    if (!AudioLoad_IsFontLoadComplete(fontId)) {
        gAudioCtx.audioErrorFlags = fontId + 0x10000000;
        return NULL;
    }

    if (instId >= gAudioCtx.soundFontList[fontId].numInstruments) {
        gAudioCtx.audioErrorFlags = ((fontId << 8) + instId) + 0x3000000;
        return NULL;
    }

    inst = gAudioCtx.soundFontList[fontId].instruments[instId];
    if (inst == NULL) {
        gAudioCtx.audioErrorFlags = ((fontId << 8) + instId) + 0x1000000;
        return inst;
    }

    return inst;
}

Drum* Audio_GetDrum(s32 fontId, s32 drumId) {
    Drum* drum;

    if (fontId == 0xFF) {
        return NULL;
    }

    if (!AudioLoad_IsFontLoadComplete(fontId)) {
        gAudioCtx.audioErrorFlags = fontId + 0x10000000;
        return NULL;
    }

    if (drumId >= gAudioCtx.soundFontList[fontId].numDrums) {
        gAudioCtx.audioErrorFlags = ((fontId << 8) + drumId) + 0x4000000;
        return NULL;
    }
    if ((uintptr_t) gAudioCtx.soundFontList[fontId].drums < AUDIO_RELOCATED_ADDRESS_START) {
        return NULL;
    }
    drum = gAudioCtx.soundFontList[fontId].drums[drumId];

    if (drum == NULL) {
        gAudioCtx.audioErrorFlags = ((fontId << 8) + drumId) + 0x5000000;
    }

    return drum;
}

SoundEffect* Audio_GetSoundEffect(s32 fontId, s32 sfxId) {
    SoundEffect* soundEffect;

    if (fontId == 0xFF) {
        return NULL;
    }

    if (!AudioLoad_IsFontLoadComplete(fontId)) {
        gAudioCtx.audioErrorFlags = fontId + 0x10000000;
        return NULL;
    }

    if (sfxId >= gAudioCtx.soundFontList[fontId].numSfx) {
        gAudioCtx.audioErrorFlags = ((fontId << 8) + sfxId) + 0x4000000;
        return NULL;
    }

    if ((uintptr_t) gAudioCtx.soundFontList[fontId].soundEffects < AUDIO_RELOCATED_ADDRESS_START) {
        return NULL;
    }

    soundEffect = &gAudioCtx.soundFontList[fontId].soundEffects[sfxId];

    if (soundEffect == NULL) {
        gAudioCtx.audioErrorFlags = ((fontId << 8) + sfxId) + 0x5000000;
    }

    if (soundEffect->tunedSample.sample == NULL) {
        return NULL;
    }

    return soundEffect;
}

s32 Audio_SetFontInstrument(s32 instrumentType, s32 fontId, s32 index, void* value) {
    if (fontId == 0xFF) {
        return -1;
    }

    if (!AudioLoad_IsFontLoadComplete(fontId)) {
        return -2;
    }

    switch (instrumentType) {
        case 0:
            if (index >= gAudioCtx.soundFontList[fontId].numDrums) {
                return -3;
            }
            gAudioCtx.soundFontList[fontId].drums[index] = value;
            break;

        case 1:
            if (index >= gAudioCtx.soundFontList[fontId].numSfx) {
                return -3;
            }
            gAudioCtx.soundFontList[fontId].soundEffects[index] = *(SoundEffect*) value;
            break;

        default:
            if (index >= gAudioCtx.soundFontList[fontId].numInstruments) {
                return -3;
            }
            gAudioCtx.soundFontList[fontId].instruments[index] = value;
            break;
    }

    return 0;
}

void Audio_SeqLayerDecayRelease(SequenceLayer* layer, s32 target) {
    Note* note;
    NoteAttributes* noteAttr;
    SequenceChannel* channel;
    s32 i;

    if (layer == NO_LAYER) {
        return;
    }

    layer->bit3 = false;

    if (layer->note == NULL) {
        return;
    }

    note = layer->note;
    noteAttr = &note->playbackState.attributes;

    if (note->playbackState.wantedParentLayer == layer) {
        note->playbackState.wantedParentLayer = NO_LAYER;
    }

    if (note->playbackState.parentLayer != layer) {
        if (note->playbackState.parentLayer == NO_LAYER && note->playbackState.wantedParentLayer == NO_LAYER &&
            note->playbackState.prevParentLayer == layer && target != ADSR_STATE_DECAY) {
            note->playbackState.adsr.fadeOutVel = gAudioCtx.audioBufferParameters.ticksPerUpdateInv;
            note->playbackState.adsr.action.s.release = true;
        }
        return;
    }

    if (note->playbackState.adsr.action.s.state != ADSR_STATE_DECAY) {
        noteAttr->freqScale = layer->noteFreqScale;
        noteAttr->velocity = layer->noteVelocity;
        noteAttr->pan = layer->notePan;

        if (layer->channel != NULL) {
            channel = layer->channel;
            noteAttr->reverb = channel->targetReverbVol;
            noteAttr->gain = channel->gain;
            noteAttr->filter = channel->filter;

            if (channel->seqPlayer->muted && (channel->muteBehavior & MUTE_BEHAVIOR_3)) {
                note->noteSubEu.bitField0.finished = true;
            }

            if (layer->stereo.asByte == 0) {
                noteAttr->stereo = channel->stereo;
            } else {
                noteAttr->stereo = layer->stereo;
            }
            note->playbackState.priority = channel->someOtherPriority;
        } else {
            noteAttr->stereo = layer->stereo;
            note->playbackState.priority = 1;
        }

        note->playbackState.prevParentLayer = note->playbackState.parentLayer;
        note->playbackState.parentLayer = NO_LAYER;
        if (target == ADSR_STATE_RELEASE) {
            note->playbackState.adsr.fadeOutVel = gAudioCtx.audioBufferParameters.ticksPerUpdateInv;
            note->playbackState.adsr.action.s.release = true;
            note->playbackState.unk_04 = 2;
        } else {
            note->playbackState.unk_04 = 1;
            note->playbackState.adsr.action.s.decay = true;
            if (layer->adsr.decayIndex == 0) {
                note->playbackState.adsr.fadeOutVel = gAudioCtx.adsrDecayTable[layer->channel->adsr.decayIndex];
            } else {
                note->playbackState.adsr.fadeOutVel = gAudioCtx.adsrDecayTable[layer->adsr.decayIndex];
            }
            note->playbackState.adsr.sustain =
                ((f32) (s32) (layer->channel->adsr.sustain) * note->playbackState.adsr.current) / 256.0f;
        }
    }

    if (target == ADSR_STATE_DECAY) {
        Audio_AudioListRemove(&note->listItem);
        Audio_AudioListPushFront(&note->listItem.pool->decaying, &note->listItem);
    }
}

void Audio_SeqLayerNoteDecay(SequenceLayer* layer) {
    Audio_SeqLayerDecayRelease(layer, ADSR_STATE_DECAY);
}

void Audio_SeqLayerNoteRelease(SequenceLayer* layer) {
    Audio_SeqLayerDecayRelease(layer, ADSR_STATE_RELEASE);
}

void Audio_InitNoteList(AudioListItem* list) {
    list->prev = list;
    list->next = list;
    list->u.count = 0;
}

void Audio_InitNoteLists(NotePool* pool) {
    Audio_InitNoteList(&pool->disabled);
    Audio_InitNoteList(&pool->decaying);
    Audio_InitNoteList(&pool->releasing);
    Audio_InitNoteList(&pool->active);
    pool->disabled.pool = pool;
    pool->decaying.pool = pool;
    pool->releasing.pool = pool;
    pool->active.pool = pool;
}

void Audio_InitNoteFreeList(void) {
    s32 i;

    Audio_InitNoteLists(&gAudioCtx.noteFreeLists);
    for (i = 0; i < gAudioCtx.numNotes; i++) {
        gAudioCtx.notes[i].listItem.u.value = &gAudioCtx.notes[i];
        gAudioCtx.notes[i].listItem.prev = NULL;
        AudioSeq_AudioListPushBack(&gAudioCtx.noteFreeLists.disabled, &gAudioCtx.notes[i].listItem);
    }
}

void Audio_NotePoolClear(NotePool* pool) {
    s32 poolType;
    AudioListItem* poolItem;
    AudioListItem* nextPoolItem;
    AudioListItem* freeList;

    for (poolType = 0; poolType < 4; poolType++) {
        switch (poolType) {
            case 0:
                poolItem = &pool->disabled;
                freeList = &gAudioCtx.noteFreeLists.disabled;
                break;
            case 1:
                poolItem = &pool->decaying;
                freeList = &gAudioCtx.noteFreeLists.decaying;
                break;
            case 2:
                poolItem = &pool->releasing;
                freeList = &gAudioCtx.noteFreeLists.releasing;
                break;
            case 3:
                poolItem = &pool->active;
                freeList = &gAudioCtx.noteFreeLists.active;
                break;
        }

        while (true) {
            nextPoolItem = poolItem->next;
            if (nextPoolItem == poolItem || nextPoolItem == NULL) {
                break;
            }
            Audio_AudioListRemove(nextPoolItem);
            AudioSeq_AudioListPushBack(freeList, nextPoolItem);
        }
    }
}

void Audio_NotePoolFill(NotePool* pool, s32 count) {
    s32 i;
    s32 poolType;
    AudioListItem* note;
    AudioListItem* freeList;
    AudioListItem* poolList;

    Audio_NotePoolClear(pool);
    poolType = 0;
    i = 0;
    while (i < count) {
        if (poolType == 4) {
            return;
        }
        switch (poolType) {
            case 0:
                freeList = &gAudioCtx.noteFreeLists.disabled;
                poolList = &pool->disabled;
                break;
            case 1:
                freeList = &gAudioCtx.noteFreeLists.decaying;
                poolList = &pool->decaying;
                break;
            case 2:
                freeList = &gAudioCtx.noteFreeLists.releasing;
                poolList = &pool->releasing;
                break;
            case 3:
                freeList = &gAudioCtx.noteFreeLists.active;
                poolList = &pool->active;
                break;
        }
        while (i < count) {
            note = AudioSeq_AudioListPopBack(freeList);
            if (note == NULL) {
                break;
            }
            AudioSeq_AudioListPushBack(poolList, note);
            i++;
        }
        poolType++;
    }
}

void Audio_AudioListPushFront(AudioListItem* item1, AudioListItem* item2) {
    if (item2->prev != NULL) {
        return;
    }
    item2->prev = item1;
    item2->next = item1->next;
    item1->next->prev = item2;
    item1->next = item2;
    item1->u.count++;
    item2->pool = item1->pool;
}

void Audio_AudioListRemove(AudioListItem* item) {
    if (item->prev == NULL) {
        return;
    }
    item->prev->next = item->next;
    item->next->prev = item->prev;
    item->prev = NULL;
}

Note* Audio_FindLowerPriorityNode(AudioListItem* item, s32 priority) {
    AudioListItem* priorityItem;
    AudioListItem* nextItem = item->next;

    if (nextItem == item) {
        return NULL;
    }
    priorityItem = nextItem;
    for (; nextItem != item; nextItem = nextItem->next) {
        if (((Note*) nextItem->u.value)->playbackState.priority <=
            ((Note*) priorityItem->u.value)->playbackState.priority) {
            priorityItem = nextItem;
        }
    }

    if (priorityItem == NULL) {
        return NULL;
    }

    if (((Note*) priorityItem->u.value)->playbackState.priority >= priority) {
        return NULL;
    }
    return (Note*) priorityItem->u.value;
}

void Audio_NoteInitForLayer(Note* note, SequenceLayer* layer) {
    s32 pad[3];
    s16 instId;
    SequenceChannel* channel = layer->channel;
    NotePlaybackState* playbackState = &note->playbackState;
    NoteSubEu* sub = &note->noteSubEu;

    note->playbackState.prevParentLayer = NO_LAYER;
    note->playbackState.parentLayer = layer;
    playbackState->priority = channel->notePriority;
    layer->notePropertiesNeedInit = true;
    layer->bit3 = true;
    layer->note = note;
    channel->noteUnused = note;
    channel->layerUnused = layer;
    layer->noteVelocity = 0.0f;
    Audio_NoteInit(note);
    instId = layer->instOrWave;

    if (instId == 0xFF) {
        instId = channel->instOrWave;
    }
    sub->tunedSample = layer->tunedSample;

    if (instId >= 0x80 && instId < 0xC0) {
        sub->bitField1.isSyntheticWave = true;
    } else {
        sub->bitField1.isSyntheticWave = false;
    }

    if (channel->startSamplePos == 1) {
        playbackState->startSamplePos = sub->tunedSample->sample->loop->header.start;
    } else {
        playbackState->startSamplePos = channel->startSamplePos;
        if (playbackState->startSamplePos >= sub->tunedSample->sample->loop->header.end) {
            playbackState->startSamplePos = 0;
        }
    }

    playbackState->fontId = channel->fontId;
    playbackState->stereoHeadsetEffects = channel->stereoHeadsetEffects;
    sub->bitField1.reverbIndex = channel->reverbIndex & 3;
}

void func_8073C0C4(Note* note, SequenceLayer* layer) {
    Audio_SeqLayerNoteRelease(note->playbackState.parentLayer);
    note->playbackState.wantedParentLayer = layer;
}

void Audio_NoteReleaseAndTakeOwnership(Note* note, SequenceLayer* layer) {
    note->playbackState.wantedParentLayer = layer;
    note->playbackState.priority = layer->channel->notePriority;
    note->playbackState.adsr.fadeOutVel = gAudioCtx.audioBufferParameters.ticksPerUpdateInv;
    note->playbackState.adsr.action.s.release = true;
}

Note* Audio_AllocNoteFromDisabled(NotePool* pool, SequenceLayer* layer) {
    Note* note = AudioSeq_AudioListPopBack(&pool->disabled);

    if (note != NULL) {
        Audio_NoteInitForLayer(note, layer);
        Audio_AudioListPushFront(&pool->active, &note->listItem);
    }
    return note;
}

Note* Audio_AllocNoteFromDecaying(NotePool* pool, SequenceLayer* layer) {
    Note* note = AudioSeq_AudioListPopBack(&pool->decaying);

    if (note != NULL) {
        Audio_NoteReleaseAndTakeOwnership(note, layer);
        AudioSeq_AudioListPushBack(&pool->releasing, &note->listItem);
    }
    return note;
}

Note* Audio_AllocNoteFromActive(NotePool* pool, SequenceLayer* layer) {
    Note* rNote;
    Note* aNote;
    s32 rPriority;
    s32 aPriority;

    rPriority = aPriority = 0x10;
    rNote = Audio_FindLowerPriorityNode(&pool->releasing, layer->channel->notePriority);
    if (rNote != NULL) {
        rPriority = rNote->playbackState.priority;
    }
    aNote = Audio_FindLowerPriorityNode(&pool->active, layer->channel->notePriority);
    if (aNote != NULL) {
        aPriority = aNote->playbackState.priority;
    }
    if (rNote == NULL && aNote == NULL) {
        return NULL;
    }
    if (aPriority < rPriority) {
        Audio_AudioListRemove(&aNote->listItem);
        func_8073C0C4(aNote, layer);
        AudioSeq_AudioListPushBack(&pool->releasing, &aNote->listItem);
        aNote->playbackState.priority = layer->channel->notePriority;
        return aNote;
    } else {
        rNote->playbackState.wantedParentLayer = layer;
        rNote->playbackState.priority = layer->channel->notePriority;
        return rNote;
    }
}

Note* Audio_AllocNote(SequenceLayer* layer) {
    Note* note;
    u32 policy = layer->channel->noteAllocPolicy;

    if (policy & 1) {
        note = layer->note;
        if (note != NULL && note->playbackState.prevParentLayer == layer &&
            note->playbackState.wantedParentLayer == NO_LAYER) {
            Audio_NoteReleaseAndTakeOwnership(note, layer);
            Audio_AudioListRemove(&note->listItem);
            AudioSeq_AudioListPushBack(&note->listItem.pool->releasing, &note->listItem);
            return note;
        }
    }

    if (policy & 2) {
        if ((note = Audio_AllocNoteFromDisabled(&layer->channel->notePool, layer)) ||
            (note = Audio_AllocNoteFromDecaying(&layer->channel->notePool, layer)) ||
            (note = Audio_AllocNoteFromActive(&layer->channel->notePool, layer))) {
            return note;
        }
    }

    else if (policy & 4) {
        if ((note = Audio_AllocNoteFromDisabled(&layer->channel->notePool, layer)) ||
            (note = Audio_AllocNoteFromDisabled(&layer->channel->seqPlayer->notePool, layer)) ||
            (note = Audio_AllocNoteFromDecaying(&layer->channel->notePool, layer)) ||
            (note = Audio_AllocNoteFromDecaying(&layer->channel->seqPlayer->notePool, layer)) ||
            (note = Audio_AllocNoteFromActive(&layer->channel->notePool, layer)) ||
            (note = Audio_AllocNoteFromActive(&layer->channel->seqPlayer->notePool, layer))) {
            return note;
        }
    }

    else if (policy & 8) {
        if ((note = Audio_AllocNoteFromDisabled(&gAudioCtx.noteFreeLists, layer)) ||
            (note = Audio_AllocNoteFromDecaying(&gAudioCtx.noteFreeLists, layer)) ||
            (note = Audio_AllocNoteFromActive(&gAudioCtx.noteFreeLists, layer))) {
            return note;
        }
    }

    else if ((note = Audio_AllocNoteFromDisabled(&layer->channel->notePool, layer)) ||
             (note = Audio_AllocNoteFromDisabled(&layer->channel->seqPlayer->notePool, layer)) ||
             (note = Audio_AllocNoteFromDisabled(&gAudioCtx.noteFreeLists, layer)) ||
             (note = Audio_AllocNoteFromDecaying(&layer->channel->notePool, layer)) ||
             (note = Audio_AllocNoteFromDecaying(&layer->channel->seqPlayer->notePool, layer)) ||
             (note = Audio_AllocNoteFromDecaying(&gAudioCtx.noteFreeLists, layer)) ||
             (note = Audio_AllocNoteFromActive(&layer->channel->notePool, layer)) ||
             (note = Audio_AllocNoteFromActive(&layer->channel->seqPlayer->notePool, layer)) ||
             (note = Audio_AllocNoteFromActive(&gAudioCtx.noteFreeLists, layer))) {
        return note;
    }

    layer->bit3 = true;
    return NULL;
}
extern NoteSubEu gZeroNoteSub;

void Audio_NoteInitAll(void) {
    Note* note;
    s32 i;

    for (i = 0; i < gAudioCtx.numNotes; i++) {
        note = &gAudioCtx.notes[i];
        note->noteSubEu = gZeroNoteSub;
        note->playbackState.priority = 0;
        note->playbackState.unk_04 = 0;
        note->playbackState.parentLayer = NO_LAYER;
        note->playbackState.wantedParentLayer = NO_LAYER;
        note->playbackState.prevParentLayer = NO_LAYER;
        note->playbackState.waveId = 0;
        note->playbackState.attributes.velocity = 0.0f;
        note->playbackState.adsrVolScaleUnused = 0;
        note->playbackState.adsr.action.asByte = 0;
        note->playbackState.vibratoState.active = 0;
        note->playbackState.portamento.cur = 0;
        note->playbackState.portamento.speed = 0;
        note->playbackState.stereoHeadsetEffects = false;
        note->playbackState.startSamplePos = 0;
        note->synthesisState.synthesisBuffers =
            AudioHeap_AllocDmaMemory(&gAudioCtx.miscPool, sizeof(NoteSynthesisBuffers));
    }
}
