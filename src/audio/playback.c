#include "global.h"
#include "audio.h"

void func_800AA7D4(Note* note, f32 arg1);

void func_800AA6D0(Note* note, NoteAttributes* noteAttr) {
    NoteSubEu* noteSub;
    f32 panVolumeLeft;
    f32 pamVolumeRight;
    f32 velocity;
    s32 temp_t0;
    s32 var_a0;
    s32 strongRight;
    s32 strongLeft;
    u8 pan;
    u8 reverb;

    func_800AA7D4(note, noteAttr->freqScale);
    noteSub = &note->noteSubEu;
    velocity = noteAttr->velocity;
    pan = noteAttr->pan;
    reverb = noteAttr->reverb;

    if (gSoundMode == SOUNDMODE_MONO) {
        panVolumeLeft = 0.707f;
        pamVolumeRight = 0.707f;
    } else {
        panVolumeLeft = gDefaultPanVolume[pan];
        pamVolumeRight = gDefaultPanVolume[ARRAY_COUNT(gDefaultPanVolume) - 1 - pan];
    }

    noteSub->panVolLeft = (s32) (velocity * panVolumeLeft * 4095.999f);
    noteSub->panVolRight = (s32) (velocity * pamVolumeRight * 4095.999f);

    if (noteSub->bitField.reverb != reverb) {
        noteSub->bitField.reverb = reverb;
        noteSub->bitField.unused = true;
    } else if (noteSub->bitField.needsInit) {
        noteSub->bitField.unused = true;
    } else {
        noteSub->bitField.unused = false;
    }
}

void func_800AA7D4(Note* note, f32 arg1) {
    NoteSubEu* noteSub = &note->noteSubEu;
    f32 var_fv0;

    if (arg1 < 2.0f) {
        noteSub->bitField.hasTwoParts = 0;
        if (arg1 > 1.99998f) {
            var_fv0 = 1.99998f;
        } else {
            var_fv0 = arg1;
        }
    } else {
        var_fv0 = 1.99998f;
    }
    note->noteSubEu.resampleRate = (s32) (var_fv0 * 32768.0f);
}

void func_800ABCE8(AdsrState* adsr, EnvelopePoint* envelope, s16* arg2);
extern NoteSubEu gDefaultNoteSub;

void func_800AA84C(Note* note) {
    if (note->playbackState.parentLayer->adsr.decayIndex == 0) {
        func_800ABCE8(&note->playbackState.adsr, note->playbackState.parentLayer->channel->adsr.envelope,
                      &note->playbackState.adsrVolScaleUnused);
    } else {
        func_800ABCE8(&note->playbackState.adsr, note->playbackState.parentLayer->adsr.envelope,
                      &note->playbackState.adsrVolScaleUnused);
    }
    note->playbackState.unk_04 = 0;
    note->playbackState.adsr.state = 1;
    note->noteSubEu = gDefaultNoteSub;
}

void func_800AA8E4(Note* note) {
    if (note->noteSubEu.bitField.needsInit == 1) {
        note->noteSubEu.bitField.needsInit = 0;
    }
    note->playbackState.priority = 0;
    note->playbackState.unk_04 = 0;
    note->noteSubEu.bitField.enabled = 0;
    note->playbackState.parentLayer = NO_LAYER;
    note->playbackState.prevParentLayer = NO_LAYER;
    note->noteSubEu.bitField.finished = 0;
    note->playbackState.adsr.state = 0;
    note->playbackState.adsr.current = 0.0f;
}

void func_800AC4C8(SequenceChannel* channel);
void func_800AAF7C(SequenceLayer* layer);
void func_800AB340(AudioListItem* item1, AudioListItem* item2);
void func_800AB41C(Note* note, SequenceLayer* layer);
f32 func_800ABD0C(AdsrState* adsr);
void func_800ABC78(Note* note);

void func_800AA940(void) {
    s32 pad[4];
    Note* note;
    NoteAttributes* attr;
    s32 i;
    NoteAttributes sp70;
    SequenceLayer* parentLayer;
    SequenceChannel* parentChannel;
    NotePlaybackState* playbackState;
    f32 temp_fs0;

    for (i = 0; i < gNumNotes; i++) {
        note = &gNotes[i];

        playbackState = &note->playbackState;
        if ((playbackState->parentLayer != NO_LAYER)) {
            if ((u32) playbackState->parentLayer < 0x7FFFFFFF) {
                continue;
            }

            if ((note != playbackState->parentLayer->note) && (playbackState->unk_04 == 0)) {
                playbackState->adsr.action.asByte |= 0x10;
                playbackState->adsr.fadeOutVel = gAudioBufferParams.ticksPerUpdateInv;
                playbackState->priority = 1;
                playbackState->unk_04 = 2;
                goto block_21;
            } else {
                if ((playbackState->parentLayer->enabled) || (playbackState->unk_04 != 0) ||
                    (playbackState->priority <= 0)) {
                    if (playbackState->parentLayer->channel->seqPlayer == NULL) {
                        func_800AC4C8(playbackState->parentLayer->channel);
                        playbackState->priority = 1;
                        playbackState->unk_04 = 1;
                        continue;
                    }
                    goto block_21;
                }
                func_800AAF7C(playbackState->parentLayer);
                func_800AB380(note);
                func_800AB340(&note->listItem.pool->decaying, &note->listItem);
                playbackState->priority = 1;
                playbackState->unk_04 = 2;
            }
        } else if ((playbackState->unk_04 == 0) && (playbackState->priority > 0)) {
            continue;
        }
    block_21:

        if (playbackState->priority != 0) {
            NoteSubEu* noteSub = &note->noteSubEu;
            if (0) {}
            if ((playbackState->unk_04 > 0) || noteSub->bitField.finished) {
                if ((playbackState->adsr.state == 0) || noteSub->bitField.finished) {
                    if (playbackState->wantedParentLayer != NO_LAYER) {
                        func_800AA8E4(note);
                        if (playbackState->wantedParentLayer->channel != NULL) {
                            func_800AB41C(note, playbackState->wantedParentLayer);
                            func_800ABCB4(note);
                            func_800AB380(note);
                            func_800AC7F0(&note->listItem.pool->active, &note->listItem);
                            playbackState->wantedParentLayer = NO_LAYER;
                        } else {
                            func_800AA8E4(note);
                            func_800AB380(note);
                            func_800AC7F0(&note->listItem.pool->disabled, &note->listItem);
                            playbackState->wantedParentLayer = NO_LAYER;
                            goto next;
                        }
                    } else {
                        if (playbackState->parentLayer != NO_LAYER) {
                            playbackState->parentLayer->bit8 = true;
                        }
                        func_800AA8E4(note);
                        func_800AB380(note);
                        func_800AC7F0(&note->listItem.pool->disabled, &note->listItem);
                        goto next;
                    }
                }
            } else if (playbackState->adsr.state == 0) {
                if (playbackState->parentLayer != NO_LAYER) {
                    playbackState->parentLayer->bit8 = true;
                }
                func_800AA8E4(note);
                func_800AB380(note);
                func_800AC7F0(&note->listItem.pool->disabled, &note->listItem);
                goto next;
            }

            temp_fs0 = func_800ABD0C(&playbackState->adsr);
            func_800ABC78(note);
            attr = &playbackState->attributes;
            if ((playbackState->unk_04 != 1) && (playbackState->unk_04 != 2)) {
                parentChannel = playbackState->parentLayer->channel;
                parentLayer = playbackState->parentLayer;

                sp70.freqScale = parentLayer->noteFreqScale;
                sp70.velocity = parentLayer->noteVelocity;
                sp70.pan = parentLayer->notePan;
                sp70.reverb = parentChannel->targetReverbVol;
            } else {
                sp70.freqScale = attr->freqScale;
                sp70.velocity = attr->velocity;
                sp70.pan = attr->pan;
                sp70.reverb = attr->reverb;
            }
            sp70.freqScale *= playbackState->portamentoFreqScale;
            sp70.velocity *= temp_fs0;
            func_800AA6D0(note, &sp70);
        next:;
        }
    }
}

TunedSample* func_800AACF0(Instrument* instrument, s32 semitone) {
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

Instrument* func_800AAD2C(s32 fontId, s32 instId) {
    return gSoundFontList[fontId].instruments[instId];
}

Drum* func_800AAD58(s32 fontId, s32 drumId) {
    return gSoundFontList[fontId].drums[drumId];
}

void func_800AB380(Note*);
void func_800AB340(AudioListItem*, AudioListItem*);

void func_800AAD84(SequenceLayer* layer, s32 arg1) {
    Note* note;
    NoteAttributes* noteAttr;

    if (layer == NO_LAYER) {
        return;
    }
    layer->unk_2 = 0;
    if (layer->note == NULL) {
        return;
    }
    note = layer->note;
    if (layer == note->playbackState.wantedParentLayer) {
        note->playbackState.wantedParentLayer = NO_LAYER;
    }

    if (layer != note->playbackState.parentLayer) {
        if ((note->playbackState.parentLayer == NO_LAYER) && (note->playbackState.wantedParentLayer == NO_LAYER) &&
            (layer == note->playbackState.prevParentLayer) && (arg1 != 6)) {
            note->playbackState.adsr.fadeOutVel = gAudioBufferParams.ticksPerUpdateInv;
            note->playbackState.adsr.action.asByte |= 0x10;
        }
    } else {
        noteAttr = &note->playbackState.attributes;
        if (note->playbackState.adsr.state != 6) {
            noteAttr->freqScale = layer->noteFreqScale;
            noteAttr->velocity = layer->noteVelocity;
            noteAttr->pan = layer->notePan;
            if (layer->channel != NULL) {
                noteAttr->reverb = layer->channel->targetReverbVol;
                note->playbackState.priority = layer->channel->notePriority2;
            } else {
                note->playbackState.priority = 1;
            }
            note->playbackState.prevParentLayer = note->playbackState.parentLayer;
            note->playbackState.parentLayer = NO_LAYER;

            if (arg1 == 7) {
                note->playbackState.adsr.fadeOutVel = gAudioBufferParams.ticksPerUpdateInv;
                note->playbackState.adsr.action.asByte |= 0x10;
                note->playbackState.unk_04 = 2;

            } else {
                note->playbackState.unk_04 = 1;
                note->playbackState.adsr.action.asByte |= 0x20;
                if (layer->adsr.decayIndex == 0) {
                    note->playbackState.adsr.fadeOutVel = gAdsrDecayTable[layer->channel->adsr.decayIndex];
                } else {
                    note->playbackState.adsr.fadeOutVel = gAdsrDecayTable[layer->adsr.decayIndex];
                }
                note->playbackState.adsr.sustain =
                    (s32) layer->channel->adsr.sustain * note->playbackState.adsr.current / 256.0f;
            }
        }
        if (arg1 == 6) {
            func_800AB380(note);
            func_800AB340(&note->listItem.pool->decaying, &note->listItem);
        }
    }
}

void func_800AAF5C(SequenceLayer* layer) {
    func_800AAD84(layer, 6);
}

void func_800AAF7C(SequenceLayer* layer) {
    func_800AAD84(layer, 7);
}

void func_800AAF9C(AudioListItem* item) {
    item->prev = item;
    item->next = item;
    item->u.value = NULL;
}

void func_800AAFAC(NotePool* pool) {
    func_800AAF9C(&pool->disabled);
    func_800AAF9C(&pool->decaying);
    func_800AAF9C(&pool->releasing);
    func_800AAF9C(&pool->active);
    pool->disabled.pool = pool;
    pool->decaying.pool = pool;
    pool->releasing.pool = pool;
    pool->active.pool = pool;
}

void func_800AAFFC(void) {
    s32 i;

    func_800AAFAC(&gNoteFreeLists);
    for (i = 0; i < gNumNotes; i++) {
        gNotes[i].listItem.u.value = &gNotes[i];
        gNotes[i].listItem.prev = NULL;
        func_800AC7F0(&gNoteFreeLists.disabled, &gNotes[i].listItem);
    }
}

void func_800AB0AC(NotePool* pool) {
    s32 poolType;
    AudioListItem* poolItem;
    AudioListItem* nextPoolItem;
    AudioListItem* freeList;

    for (poolType = 0; poolType < 4; poolType++) {
        switch (poolType) {
            case 0:
                poolItem = &pool->disabled;
                freeList = &gNoteFreeLists.disabled;
                break;
            case 1:
                poolItem = &pool->decaying;
                freeList = &gNoteFreeLists.decaying;
                break;
            case 2:
                poolItem = &pool->releasing;
                freeList = &gNoteFreeLists.releasing;
                break;
            case 3:
                poolItem = &pool->active;
                freeList = &gNoteFreeLists.active;
                break;
        }

        while (true) {
            nextPoolItem = poolItem->next;
            if (nextPoolItem == poolItem) {
                break;
            }
            func_800AB380((Note*) nextPoolItem);
            func_800AC7F0(freeList, nextPoolItem);
        }
    }
}

void* func_800AC830(AudioListItem* list);

void func_800AB204(NotePool* pool, s32 arg1) {
    s32 var_s0;
    s32 poolType;
    AudioListItem* note;
    AudioListItem* freeList;
    AudioListItem* poolList;

    func_800AB0AC(pool);
    poolType = 0;
    var_s0 = 0;
    while (var_s0 < arg1) {
        if (poolType == 4) {
            return;
        }
        switch (poolType) {
            case 0:
                freeList = &gNoteFreeLists.disabled;
                poolList = &pool->disabled;
                break;
            case 1:
                freeList = &gNoteFreeLists.decaying;
                poolList = &pool->decaying;
                break;
            case 2:
                freeList = &gNoteFreeLists.releasing;
                poolList = &pool->releasing;
                break;
            case 3:
                freeList = &gNoteFreeLists.active;
                poolList = &pool->active;
                break;
        }
        while (var_s0 < arg1) {
            note = func_800AC830(freeList);
            if (note == NULL) {
                break;
            }
            func_800AC7F0(poolList, note);
            var_s0++;
        }
        poolType++;
    }
}

void func_800AB340(AudioListItem* item1, AudioListItem* item2) {
    if (item2->prev == NULL) {
        item2->prev = item1;
        item2->next = item1->next;
        item1->next->prev = item2;
        item1->next = item2;
        item1->u.count++;
        item2->pool = item1->pool;
    }
}

void func_800AB380(Note* note) {
    if (note->listItem.prev != NULL) {
        note->listItem.prev->next = note->listItem.next;
        note->listItem.next->prev = note->listItem.prev;
        note->listItem.prev = NULL;
    }
}

Note* func_800AB3AC(AudioListItem* item, s32 priority) {
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

    if (((Note*) priorityItem->u.value)->playbackState.priority >= priority) {
        return NULL;
    }
    return (Note*) priorityItem->u.value;
}

void func_800AB41C(Note* note, SequenceLayer* layer) {
    s32 pad[3];
    s16 instId;
    NotePlaybackState* playbackState = &note->playbackState;
    NoteSubEu* sub = &note->noteSubEu;

    note->playbackState.prevParentLayer = NO_LAYER;
    note->playbackState.parentLayer = layer;
    playbackState->priority = layer->channel->notePriority;
    layer->notePropertiesNeedInit = true;
    layer->unk_2 = 3;
    layer->note = note;
    layer->channel->noteUnused = note;
    layer->channel->layerUnused = layer;
    layer->noteVelocity = 0.0f;
    func_800AA84C(note);
    instId = layer->instOrWave;

    if (instId == 0xFF) {
        instId = layer->channel->instOrWave;
    }
    sub->tunedSample = layer->tunedSample;

    if (instId >= 0x80 && instId < 0xC0) {
        sub->bitField.isSyntheticWave = true;
    } else {
        sub->bitField.isSyntheticWave = false;
    }

    playbackState->fontId = layer->channel->fontId;
    sub->bitField.reverbIndex = layer->channel->reverbIndex;
}

void func_800AB51C(Note* note, SequenceLayer* layer) {
    func_800AAF7C(note->playbackState.parentLayer);
    note->playbackState.wantedParentLayer = layer;
}

void func_800AB550(Note* note, SequenceLayer* layer) {
    note->playbackState.wantedParentLayer = layer;
    note->playbackState.priority = layer->channel->notePriority;
    note->playbackState.adsr.fadeOutVel = gAudioBufferParams.ticksPerUpdateInv;
    note->playbackState.adsr.action.asByte |= 0x10;
}

Note* func_800AB57C(NotePool* pool, SequenceLayer* layer) {
    Note* note = func_800AC830(&pool->disabled);

    if (note != NULL) {
        func_800AB41C(note, layer);
        func_800AB340(&pool->active, &note->listItem);
    }
    return note;
}

Note* func_800AB5C8(NotePool* pool, SequenceLayer* layer) {
    Note* note = func_800AC830(&pool->decaying);

    if (note != NULL) {
        func_800AB550(note, layer);
        func_800AC7F0(&pool->releasing, &note->listItem);
    }
    return note;
}

Note* func_800AB618(NotePool* pool, SequenceLayer* layer) {
    Note* rNote;
    Note* aNote;
    s32 rPriority;
    s32 aPriority;

    rPriority = aPriority = 0x10;
    rNote = func_800AB3AC(&pool->releasing, layer->channel->notePriority);
    if (rNote != NULL) {
        rPriority = rNote->playbackState.priority;
    }
    aNote = func_800AB3AC(&pool->active, layer->channel->notePriority);
    if (aNote != NULL) {
        aPriority = aNote->playbackState.priority;
    }
    if (rNote == NULL && aNote == NULL) {
        return NULL;
    }
    if (aPriority < rPriority) {
        func_800AB380(aNote);
        func_800AB51C(aNote, layer);
        func_800AC7F0(&pool->releasing, &aNote->listItem);
        aNote->playbackState.priority = layer->channel->notePriority;
        return aNote;
    } else {
        rNote->playbackState.wantedParentLayer = layer;
        rNote->playbackState.priority = layer->channel->notePriority;
        return rNote;
    }
}

Note* func_800AB710(SequenceLayer* layer) {
    Note* note;

    if (layer->channel->noteAllocPolicy & 1) {
        note = layer->note;
        if ((note != NULL) && (layer == note->playbackState.prevParentLayer) &&
            (note->playbackState.wantedParentLayer == NO_LAYER)) {

            func_800AB550(note, layer);
            func_800AB380(note);
            func_800AC7F0(&note->listItem.pool->releasing, &note->listItem);
            return note;
        }
    }

    if (layer->channel->noteAllocPolicy & 2) {
        if (((note = func_800AB57C(&layer->channel->notePool, layer)) != NULL) ||
            ((note = func_800AB5C8(&layer->channel->notePool, layer)) != NULL) ||
            ((note = func_800AB618(&layer->channel->notePool, layer)) != NULL)) {
            return note;
        }
    } else {
        if (((note = func_800AB57C(&layer->channel->notePool, layer)) != NULL) ||
            ((note = func_800AB57C(&gNoteFreeLists, layer)) != NULL) ||
            ((note = func_800AB5C8(&layer->channel->notePool, layer)) != NULL) ||
            ((note = func_800AB5C8(&gNoteFreeLists, layer)) != NULL) ||
            ((note = func_800AB618(&layer->channel->notePool, layer)) != NULL) ||
            ((note = func_800AB618(&gNoteFreeLists, layer)) != NULL)) {
            return note;
        }
    }
    layer->unk_2 = 0;
    return NULL;
}

void* func_800B2A8C(AudioAllocPool* pool, u32 size);

void func_800AB888(void) {
    s32 i;
    Note* note;

    for (i = 0; i < gNumNotes; i++) {
        note = &gNotes[i];

        note->noteSubEu = gZeroNoteSub;

        note->playbackState.priority = 0;
        note->playbackState.unk_04 = 0;
        note->playbackState.parentLayer = NO_LAYER;
        note->playbackState.wantedParentLayer = NO_LAYER;
        note->playbackState.prevParentLayer = NO_LAYER;
        note->playbackState.waveId = 0;
        note->playbackState.attributes.velocity = 0.0f;
        note->playbackState.adsrVolScaleUnused = 0;
        note->playbackState.adsr.state = 0;
        note->playbackState.adsr.action.asByte = 0;
        note->playbackState.portamento.cur = 0.0f;
        note->playbackState.portamento.speed = 0.0f;

        note->synthesisState.synthesisBuffers = func_800B2A8C(&gMiscPool, sizeof(NoteSynthesisBuffers));
    }
}
