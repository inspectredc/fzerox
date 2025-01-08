#include "global.h"
#include "audio.h"

void Audio_NoteSetResamplingRate(Note* note, f32 freqScale);

static char D_800D0680[] = "----------------------Double-Error CH: %x %f\n";
static char D_800D06B0[] = "----------------------Double-Error NT: %x\n";
static char D_800D06DC[] = "CAUTION:SUB IS SEPARATED FROM GROUP\n";
static char D_800D0704[] = "CAUTION:PAUSE EMERGENCY\n";
static char D_800D0720[] = "Error:Wait Track disappear\n";
static char D_800D073C[] = "ptr2 %x\n";
static char D_800D0748[] = "--4 %x\n";
static char D_800D0750[] = "NoteOff Comes during wait release %x (note %x)\n";
static char D_800D0780[] = "Slow Release Batting\n";
static char D_800D0798[] = "Alloc Error:Dim voice-Alloc %d";
static char D_800D07B8[] = "Error:Same List Add\n";
static char D_800D07D0[] = "Already Cut\n";
static char D_800D07E0[] = "Intterupt UseStop %d (Kill %d)\n";
static char D_80000800[] = "Intterupt RelWait %d (Kill %d)\n";
static char D_800D0820[] = "Drop Voice (Prio %x)\n";

void Audio_InitNoteSub(Note* note, NoteAttributes* noteAttr) {
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

    Audio_NoteSetResamplingRate(note, noteAttr->freqScale);
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

void Audio_NoteSetResamplingRate(Note* note, f32 freqScale) {
    NoteSubEu* noteSub = &note->noteSubEu;
    f32 var_fv0;

    if (freqScale < 2.0f) {
        noteSub->bitField.hasTwoParts = 0;
        if (freqScale > 1.99998f) {
            var_fv0 = 1.99998f;
        } else {
            var_fv0 = freqScale;
        }
    } else {
        var_fv0 = 1.99998f;
    }
    note->noteSubEu.resampleRate = (s32) (var_fv0 * 32768.0f);
}

void Audio_AdsrInit(AdsrState* adsr, EnvelopePoint* envelope, s16* arg2);
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
    note->playbackState.adsr.state = 1;
    note->noteSubEu = gDefaultNoteSub;
}

void Audio_NoteDisable(Note* note) {
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

void AudioSeq_SequenceChannelDisable(SequenceChannel* channel);
void Audio_SeqLayerNoteRelease(SequenceLayer* layer);
void Audio_AudioListPushFront(AudioListItem* item1, AudioListItem* item2);
void Audio_NoteInitForLayer(Note* note, SequenceLayer* layer);
f32 Audio_AdsrUpdate(AdsrState* adsr);
void Audio_NotePortamentoUpdate(Note* note);

void Audio_ProcessNotes(void) {
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
                        AudioSeq_SequenceChannelDisable(playbackState->parentLayer->channel);
                        playbackState->priority = 1;
                        playbackState->unk_04 = 1;
                        continue;
                    }
                    goto block_21;
                }
                Audio_SeqLayerNoteRelease(playbackState->parentLayer);
                Audio_AudioListRemove(note);
                Audio_AudioListPushFront(&note->listItem.pool->decaying, &note->listItem);
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
                        Audio_NoteDisable(note);
                        if (playbackState->wantedParentLayer->channel != NULL) {
                            Audio_NoteInitForLayer(note, playbackState->wantedParentLayer);
                            Audio_NotePortamentoInit(note);
                            Audio_AudioListRemove(note);
                            AudioSeq_AudioListPushBack(&note->listItem.pool->active, &note->listItem);
                            playbackState->wantedParentLayer = NO_LAYER;
                        } else {
                            Audio_NoteDisable(note);
                            Audio_AudioListRemove(note);
                            AudioSeq_AudioListPushBack(&note->listItem.pool->disabled, &note->listItem);
                            playbackState->wantedParentLayer = NO_LAYER;
                            goto next;
                        }
                    } else {
                        if (playbackState->parentLayer != NO_LAYER) {
                            playbackState->parentLayer->bit8 = true;
                        }
                        Audio_NoteDisable(note);
                        Audio_AudioListRemove(note);
                        AudioSeq_AudioListPushBack(&note->listItem.pool->disabled, &note->listItem);
                        goto next;
                    }
                }
            } else if (playbackState->adsr.state == 0) {
                if (playbackState->parentLayer != NO_LAYER) {
                    playbackState->parentLayer->bit8 = true;
                }
                Audio_NoteDisable(note);
                Audio_AudioListRemove(note);
                AudioSeq_AudioListPushBack(&note->listItem.pool->disabled, &note->listItem);
                goto next;
            }

            temp_fs0 = Audio_AdsrUpdate(&playbackState->adsr);
            Audio_NotePortamentoUpdate(note);
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
            Audio_InitNoteSub(note, &sp70);
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
    return gSoundFontList[fontId].instruments[instId];
}

Drum* Audio_GetDrum(s32 fontId, s32 drumId) {
    return gSoundFontList[fontId].drums[drumId];
}

void Audio_AudioListRemove(Note*);
void Audio_AudioListPushFront(AudioListItem*, AudioListItem*);

void Audio_SeqLayerDecayRelease(SequenceLayer* layer, s32 adsrState) {
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
            (layer == note->playbackState.prevParentLayer) && (adsrState != ADSR_STATE_DECAY)) {
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

            if (adsrState == ADSR_STATE_RELEASE) {
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
        if (adsrState == ADSR_STATE_DECAY) {
            Audio_AudioListRemove(note);
            Audio_AudioListPushFront(&note->listItem.pool->decaying, &note->listItem);
        }
    }
}

void Audio_SeqLayerNoteDecay(SequenceLayer* layer) {
    Audio_SeqLayerDecayRelease(layer, ADSR_STATE_DECAY);
}

void Audio_SeqLayerNoteRelease(SequenceLayer* layer) {
    Audio_SeqLayerDecayRelease(layer, ADSR_STATE_RELEASE);
}

void Audio_InitNoteList(AudioListItem* item) {
    item->prev = item;
    item->next = item;
    item->u.value = NULL;
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

    Audio_InitNoteLists(&gNoteFreeLists);
    for (i = 0; i < gNumNotes; i++) {
        gNotes[i].listItem.u.value = &gNotes[i];
        gNotes[i].listItem.prev = NULL;
        AudioSeq_AudioListPushBack(&gNoteFreeLists.disabled, &gNotes[i].listItem);
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
            Audio_AudioListRemove((Note*) nextPoolItem);
            AudioSeq_AudioListPushBack(freeList, nextPoolItem);
        }
    }
}

void* AudioSeq_AudioListPopBack(AudioListItem* list);

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
    if (item2->prev == NULL) {
        item2->prev = item1;
        item2->next = item1->next;
        item1->next->prev = item2;
        item1->next = item2;
        item1->u.count++;
        item2->pool = item1->pool;
    }
}

void Audio_AudioListRemove(Note* note) {
    if (note->listItem.prev != NULL) {
        note->listItem.prev->next = note->listItem.next;
        note->listItem.next->prev = note->listItem.prev;
        note->listItem.prev = NULL;
    }
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

    if (((Note*) priorityItem->u.value)->playbackState.priority >= priority) {
        return NULL;
    }
    return (Note*) priorityItem->u.value;
}

void Audio_NoteInitForLayer(Note* note, SequenceLayer* layer) {
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
    Audio_NoteInit(note);
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
    Audio_SeqLayerNoteRelease(note->playbackState.parentLayer);
    note->playbackState.wantedParentLayer = layer;
}

void func_800AB550(Note* note, SequenceLayer* layer) {
    note->playbackState.wantedParentLayer = layer;
    note->playbackState.priority = layer->channel->notePriority;
    note->playbackState.adsr.fadeOutVel = gAudioBufferParams.ticksPerUpdateInv;
    note->playbackState.adsr.action.asByte |= 0x10;
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
        func_800AB550(note, layer);
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
        Audio_AudioListRemove(aNote);
        func_800AB51C(aNote, layer);
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

    if (layer->channel->noteAllocPolicy & 1) {
        note = layer->note;
        if ((note != NULL) && (layer == note->playbackState.prevParentLayer) &&
            (note->playbackState.wantedParentLayer == NO_LAYER)) {

            func_800AB550(note, layer);
            Audio_AudioListRemove(note);
            AudioSeq_AudioListPushBack(&note->listItem.pool->releasing, &note->listItem);
            return note;
        }
    }

    if (layer->channel->noteAllocPolicy & 2) {
        if (((note = Audio_AllocNoteFromDisabled(&layer->channel->notePool, layer)) != NULL) ||
            ((note = Audio_AllocNoteFromDecaying(&layer->channel->notePool, layer)) != NULL) ||
            ((note = Audio_AllocNoteFromActive(&layer->channel->notePool, layer)) != NULL)) {
            return note;
        }
    } else {
        if (((note = Audio_AllocNoteFromDisabled(&layer->channel->notePool, layer)) != NULL) ||
            ((note = Audio_AllocNoteFromDisabled(&gNoteFreeLists, layer)) != NULL) ||
            ((note = Audio_AllocNoteFromDecaying(&layer->channel->notePool, layer)) != NULL) ||
            ((note = Audio_AllocNoteFromDecaying(&gNoteFreeLists, layer)) != NULL) ||
            ((note = Audio_AllocNoteFromActive(&layer->channel->notePool, layer)) != NULL) ||
            ((note = Audio_AllocNoteFromActive(&gNoteFreeLists, layer)) != NULL)) {
            return note;
        }
    }
    layer->unk_2 = 0;
    return NULL;
}

void* AudioHeap_Alloc(AudioAllocPool* pool, u32 size);

void Audio_NoteInitAll(void) {
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

        note->synthesisState.synthesisBuffers = AudioHeap_Alloc(&gMiscPool, sizeof(NoteSynthesisBuffers));
    }
}
