#include "global.h"
#include "audio.h"

extern u8 sSeqInstructionArgsTable[];
u8 func_800AC8F4(SeqScriptState*);
s16 func_800AC908(SeqScriptState*);

s32 func_800ABFD0(SeqScriptState* state, u8 cmd) {
    u8 highBits = sSeqInstructionArgsTable[cmd - 0xB0];
    u8 lowBits = highBits & 3;
    u16 cmdArg = 0;

    // only 1 argument
    if (lowBits == 1) {
        if (!(highBits & 0x80)) {
            cmdArg = func_800AC8F4(state);
        } else {
            cmdArg = func_800AC908(state);
        }
    }

    return cmdArg;
}

u16 func_800AC940(SeqScriptState*);

s32 func_800AC038(SequencePlayer* seqPlayer, SeqScriptState* state, s32 cmd, s32 cmdArg) {
    switch (cmd) {
        case 0xFF:
            if (state->depth == 0) {
                return -1;
            }
            state->pc = state->stack[--state->depth];
            break;
        case 0xFD:
            return func_800AC940(state);
        case 0xFE:
            return 1;
        case 0xFC:
            state->stack[state->depth++] = state->pc;
            state->pc = seqPlayer->seqData + (u16) cmdArg;
            break;
        case 0xF8:
            state->remLoopIters[state->depth] = cmdArg;
            state->stack[state->depth++] = state->pc;
            break;
        case 0xF7:
            state->remLoopIters[state->depth - 1]--;
            if (state->remLoopIters[state->depth - 1] != 0) {
                state->pc = state->stack[state->depth - 1];
            } else {
                state->depth--;
            }
            break;
        case 0xF6:
            state->depth--;
            break;
        case 0xF5:
        case 0xF9:
        case 0xFA:
        case 0xFB:
            if (cmd == 0xFA && state->value != 0) {
                break;
            }
            if (cmd == 0xF9 && state->value >= 0) {
                break;
            }
            if (cmd == 0xF5 && state->value < 0) {
                break;
            }
            state->pc = seqPlayer->seqData + (u16) cmdArg;
            break;
        case 0xF2:
        case 0xF3:
        case 0xF4:
            if (cmd == 0xF3 && state->value != 0) {
                break;
            }
            if (cmd == 0xF2 && state->value >= 0) {
                break;
            }
            state->pc += (s8) (cmdArg & 0xFF);
            break;
    }

    return 0;
}

extern SequenceChannel D_80028DD8; // gAudioCtx.sequenceChannelNone

void func_800AC214(SequenceChannel* channel) {
    s32 i;

    if (channel == &D_80028DD8) {
        return;
    }

    channel->enabled = 0;
    channel->finished = 0;
    channel->stopScript = 0;
    channel->muted = 0;
    channel->hasInstrument = false;
    channel->reverbIndex = 0;
    channel->transposition = 0;
    channel->largeNotes = 0;

    channel->changes.asByte = 0xFF;
    channel->scriptState.depth = 0;

    channel->unkPan = 0x40;
    channel->unkPan2 = 0x80;

    channel->velocityRandomVariance = 0;
    channel->gateTimeRandomVariance = 0;

    channel->noteUnused = NULL;
    channel->targetReverbVol = 0;

    channel->notePriority = 3;
    channel->notePriority2 = 1;

    channel->delay = 0;

    channel->adsr.envelope = gDefaultEnvelope;
    channel->adsr.decayIndex = 0xF0;
    channel->adsr.sustain = 0;

    channel->volume = 1.0f;
    channel->volumeMod = 1.0f;
    channel->freqMod = 1.0f;

    for (i = 0; i < 8; i++) {
        channel->seqScriptIO[i] = -1;
    }
    channel->unused = 0;
    func_800AAFAC(&channel->notePool);
}

extern AudioListItem gLayerFreeList;
void* func_800AC830(AudioListItem*);

s32 func_800AC328(SequenceChannel* channel, s32 arg1) {
    SequenceLayer* newLayer;
    SequenceLayer* layer;

    if (channel->layers[arg1] == NULL) {
        newLayer = func_800AC830(&gLayerFreeList);
        channel->layers[arg1] = newLayer;
        if (newLayer == NULL) {
            channel->layers[arg1] = NULL;
            return -1;
        }
    } else {
        func_800AAF5C(channel->layers[arg1]);
    }

    layer = channel->layers[arg1];
    layer->channel = channel;
    layer->adsr = channel->adsr;
    layer->enabled = 1;
    layer->muted = 0;
    layer->continuousNotes = 0;
    layer->finished = 0;
    layer->adsr.decayIndex = 0;
    layer->ignoreDrumPan = false;
    layer->bit8 = 0;

    layer->portamento.mode = 0;
    layer->state.depth = 0;
    layer->unk_2 = 0;
    layer->gateTime = 0x80;
    layer->pan = 0x40;
    layer->transposition = 0;
    layer->delay = 0;
    layer->gateDelay = 0;
    layer->delay2 = 0;
    layer->note = NULL;
    layer->instrument = NULL;
    layer->instOrWave = 0xFF;
    layer->freqMod = 1.0f;
    layer->bend = 1.0f;
    layer->velocitySquare = 0.0f;

    return 0;
}

void func_800AC43C(SequenceLayer* layer) {
    if (layer != NULL) {
        func_800AAF5C(layer);
        layer->enabled = 0;
        layer->finished = 1;
    }
}

void func_800AC7F0(AudioListItem* list, AudioListItem* item);

void func_800AC478(SequenceChannel* channel, s32 layerIndex) {
    SequenceLayer* layer = channel->layers[layerIndex];

    if (layer != NULL) {
        func_800AC7F0(&gLayerFreeList, &layer->listItem);
        func_800AC43C(layer);
        channel->layers[layerIndex] = NULL;
    }
}

void func_800AB0AC(NotePool*);

void func_800AC4C8(SequenceChannel* channel) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_800AC478(channel, i);
    }

    func_800AB0AC(&channel->notePool);
    channel->enabled = false;
    channel->finished = true;
}

void func_800AC534(SequencePlayer* seqPlayer, u16 channelBits) {
    SequenceChannel* channel;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
        if (channelBits & 1) {
            channel = seqPlayer->channels[i];
            channel->fontId = seqPlayer->defaultFont;
            channel->muteBehavior = seqPlayer->muteBehavior;
            channel->noteAllocPolicy = seqPlayer->noteAllocPolicy;
        }
        channelBits = channelBits >> 1;
    }
}

void func_800AC62C(SequencePlayer* seqPlayer, u16 channelBitsUnused) {
    SequenceChannel* channel;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
        channel = seqPlayer->channels[i];
        if (IS_SEQUENCE_CHANNEL_VALID(channel) == 1) {
            func_800AC4C8(channel);
        }
    }
}

void func_800AC6AC(SequencePlayer* seqPlayer, u8 channelIndex, void* script) {
    SequenceChannel* channel = seqPlayer->channels[channelIndex];
    s32 i;

    channel->enabled = true;
    channel->finished = false;
    channel->scriptState.depth = 0;
    channel->scriptState.pc = script;
    channel->delay = 0;

    for (i = 0; i < ARRAY_COUNT(channel->layers); i++) {
        if (channel->layers[i] != NULL) {
            func_800AC478(channel, i);
        }
    }
}

extern AudioCache gFontCache;
void func_800AF36C(s32, s32);

void func_800AC744(SequencePlayer* seqPlayer) {
    func_800AC62C(seqPlayer, 0xFFFF);
    func_800AB0AC(&seqPlayer->notePool);

    seqPlayer->finished = true;
    seqPlayer->enabled = false;

    if (func_800AF2C4(seqPlayer->seqId)) {
        func_800AF36C(seqPlayer->seqId, LOAD_STATUS_DISCARDABLE);
    }

    if (func_800AF288(seqPlayer->defaultFont)) {
        func_800AF33C(seqPlayer->defaultFont, LOAD_STATUS_MAYBE_DISCARDABLE);
    }

    if (seqPlayer->defaultFont == gFontCache.temporary.entries[0].id) {
        gFontCache.temporary.nextSide = 1;
    } else if (seqPlayer->defaultFont == gFontCache.temporary.entries[1].id) {
        gFontCache.temporary.nextSide = 0;
    }
}

void func_800AC7F0(AudioListItem* list, AudioListItem* item) {
    if (item->prev == NULL) {
        list->prev->next = item;
        item->prev = list->prev;
        item->next = list;
        list->prev = item;
        list->u.count++;
        item->pool = list->pool;
    }
}

void* func_800AC830(AudioListItem* list) {
    AudioListItem* item = list->prev;

    if (item == list) {
        return NULL;
    }

    item->prev->next = list;
    list->prev = item->prev;
    item->prev = NULL;
    list->u.count--;

    return item->u.value;
}

void func_800AC870(void) {
    s32 i;

    gLayerFreeList.prev = &gLayerFreeList;
    gLayerFreeList.next = &gLayerFreeList;
    gLayerFreeList.u.value = NULL;
    gLayerFreeList.pool = NULL;

    for (i = 0; i < 64; i++) {
        gSeqLayers[i].listItem.u.value = &gSeqLayers[i];
        gSeqLayers[i].listItem.prev = NULL;
        func_800AC7F0(&gLayerFreeList, &gSeqLayers[i].listItem);
    }
}

u8 func_800AC8F4(SeqScriptState* state) {
    return *(state->pc++);
}

s16 func_800AC908(SeqScriptState* state) {
    s16 ret = *(state->pc++) << 8;

    ret = *(state->pc++) | ret;
    return ret;
}

u16 func_800AC940(SeqScriptState* state) {
    u16 ret = *(state->pc++);

    if (ret & 0x80) {
        ret = (ret << 8) & 0x7F00;
        ret = *(state->pc++) | ret;
    }
    return ret;
}

void func_800ACA84(SequenceLayer*);
s32 func_800ACC28(SequenceLayer*);
s32 func_800AD378(SequenceLayer*, s32);
s32 func_800ACF94(SequenceLayer*, s32);
s32 func_800ACB10(SequenceLayer*, s32);

void func_800AC980(SequenceLayer* layer) {
    s32 cmd;

    if (!layer->enabled) {
        return;
    }

    if (layer->delay > 1) {
        layer->delay--;
        if (!layer->muted && (layer->delay <= layer->gateDelay)) {
            func_800AAF5C(layer);
            layer->muted = true;
        }
        return;
    }

    func_800ACA84(layer);

    cmd = func_800ACC28(layer);
    if (cmd == -1) {
        return;
    }

    cmd = func_800AD378(layer, cmd);

    if (cmd != -1) {
        cmd = func_800ACF94(layer, cmd);
    }

    if (cmd != -1) {
        func_800ACB10(layer, cmd);
    }

    if (layer->muted == true) {
        if ((layer->note != NULL) || layer->continuousNotes) {
            func_800AAF5C(layer);
        }
    }
}

void func_800ACA84(SequenceLayer* layer) {
    if (!layer->continuousNotes) {
        func_800AAF5C(layer);
    } else if (layer->note != NULL && layer->note->playbackState.wantedParentLayer == layer) {
        func_800AAF5C(layer);
    }

    if ((layer->portamento.mode & ~0x80) == 1 || (layer->portamento.mode & ~0x80) == 2) {
        layer->portamento.mode = 0;
    }
    layer->notePropertiesNeedInit = true;
}

s32 func_800ACB10(SequenceLayer* layer, s32 sameTunedSample) {
    Note* note;

    if (!layer->muted && (layer->tunedSample != NULL) && (layer->tunedSample->sample->codec == CODEC_S16_INMEMORY) &&
        (layer->tunedSample->sample->medium != MEDIUM_RAM)) {
        layer->muted = true;
        return -1;
    }

    if (layer->continuousNotes == true && layer->bit8 == 1) {
        return 0;
    }

    if (layer->continuousNotes == true && layer->note != NULL && layer->unk_2 != 0 && sameTunedSample == true &&
        layer->note->playbackState.parentLayer == layer) {
        // Empty since no synthetic wave initialisation
    } else {
        if (!sameTunedSample) {
            func_800AAF5C(layer);
        }

        layer->note = func_800AB710(layer);
    }

    if (layer->note != NULL && layer->note->playbackState.parentLayer == layer) {
        note = layer->note;

        func_800ABCB4(note);
    }

    return 0;
}

u8 func_800AD704(SequenceChannel* channel, u8 instId, Instrument** instOut, AdsrSettings* adsr);

s32 func_800ACC28(SequenceLayer* layer) {
    SequenceChannel* channel = layer->channel;
    SeqScriptState* state = &layer->state;
    SequencePlayer* seqPlayer = channel->seqPlayer;
    u8 cmd;
    s32 cmdArg;
    u16 velocity;

    while (true) {
        cmd = func_800AC8F4(state);

        if (cmd <= 0xC0) {
            return cmd;
        }

        if (cmd >= 0xF2) {
            cmdArg = func_800ABFD0(state, cmd);

            if (func_800AC038(seqPlayer, state, cmd, cmdArg) == 0) {
                continue;
            }
            func_800AC43C(layer);
            return -1;
        }

        switch (cmd) {
            case 0xC1:
            case 0xCA:
                cmdArg = *(state->pc++);
                if (cmd == 0xC1) {
                    layer->velocitySquare2 = SQ(cmdArg) / SQ(127.0f);
                } else {
                    layer->pan = cmdArg;
                }
                break;

            case 0xC9:
            case 0xC2:
                cmdArg = *(state->pc++);
                if (cmd == 0xC9) {
                    layer->gateTime = cmdArg;
                } else {
                    layer->transposition = cmdArg;
                }
                break;

            case 0xC4:
            case 0xC5:
                if (cmd == 0xC4) {
                    layer->continuousNotes = true;
                } else {
                    layer->continuousNotes = false;
                }
                layer->bit8 = false;
                func_800AAF5C(layer);
                break;

            case 0xC3:
                cmdArg = func_800AC940(state);
                layer->shortNoteDefaultDelay = cmdArg;
                break;

            case 0xC6:
                cmd = func_800AC8F4(state);
                if (cmd >= 0x7F) {
                    if (cmd == 0x7F) {
                        layer->instOrWave = 0;
                    } else {
                        layer->instOrWave = cmd;
                        layer->instrument = NULL;
                    }

                    if (cmd == 0xFF) {
                        layer->adsr.decayIndex = 0;
                    }
                } else {
                    if ((layer->instOrWave = func_800AD704(channel, cmd, &layer->instrument, &layer->adsr)) == 0) {
                        layer->instOrWave = 0xFF;
                    }
                }
                break;

            case 0xC7:
                layer->portamento.mode = func_800AC8F4(state);

                cmd = func_800AC8F4(state);
                cmd += channel->transposition;
                cmd += layer->transposition;
                cmd += seqPlayer->transposition;

                if (cmd >= 0x80) {
                    cmd = 0;
                }

                layer->portamentoTargetNote = cmd;

                if (layer->portamento.mode & 0x80) {
                    layer->portamentoTime = *(state->pc++);
                    break;
                }

                cmdArg = func_800AC940(state);
                layer->portamentoTime = cmdArg;
                break;

            case 0xC8:
                layer->portamento.mode = 0;
                break;

            case 0xCB:
                cmdArg = func_800AC908(state);
                layer->adsr.envelope = (EnvelopePoint*) (seqPlayer->seqData + (u16) cmdArg);
                /* fallthrough */
            case 0xCF:
                layer->adsr.decayIndex = func_800AC8F4(state);
                break;

            case 0xCC:
                layer->ignoreDrumPan = true;
                break;

            case 0xCD:
                func_800AC8F4(state);
                break;

            case 0xCE:
                cmdArg = func_800AC8F4(state);
                layer->bend = gBendPitchTwoSemitonesFrequencies[(u8) (cmdArg + 0x80)];
                break;

            default:
                switch (cmd & 0xF0) {
                    case 0xD0:
                        velocity = seqPlayer->shortNoteVelocityTable[cmd & 0xF];
                        layer->velocitySquare2 = SQ(velocity) / SQ(127.0f);
                        break;

                    case 0xE0:
                        layer->gateTime = seqPlayer->shortNoteGateTimeTable[cmd & 0xF];
                        break;
                }
        }
    }
}

extern f32 gPitchFrequencies[];
Drum* func_800AAD58(s32 fontId, s32 drumId);

s32 func_800ACF94(SequenceLayer* layer, s32 cmd) {
    s32 sameTunedSample = true;
    s32 instOrWave;
    f32 temp_fa1;
    f32 temp_fv1;
    Portamento* portamento;
    f32 freqMod;
    f32 freqMod2;
    TunedSample* tunedSample;
    Instrument* instrument;
    SequenceChannel* channel;
    Drum* drum;
    s32 vel;
    f32 tuning;
    SequencePlayer* seqPlayer;
    u8 semitone = cmd;

    instOrWave = layer->instOrWave;
    channel = layer->channel;
    seqPlayer = channel->seqPlayer;

    if (instOrWave == 0xFF) {
        if (!channel->hasInstrument) {
            return -1;
        }
        instOrWave = channel->instOrWave;
    }

    switch (instOrWave) {
        case 0:
            // Drums
            semitone += channel->transposition + layer->transposition;

            drum = func_800AAD58(channel->fontId, semitone);
            if (drum == NULL) {
                layer->muted = true;
                layer->delay2 = layer->delay;
                return -1;
            }

            tunedSample = &drum->tunedSample;
            layer->adsr.envelope = drum->envelope;
            layer->adsr.decayIndex = drum->adsrDecayIndex;
            if (!layer->ignoreDrumPan) {
                layer->pan = drum->pan;
            }
            layer->tunedSample = tunedSample;
            layer->freqMod = tunedSample->tuning;
            break;

        default:
            semitone += seqPlayer->transposition + channel->transposition + layer->transposition;

            if (semitone >= 0x80) {
                layer->muted = true;
                return -1;
            }

            if (layer->instOrWave == 0xFF) {
                instrument = channel->instrument;
            } else {
                instrument = layer->instrument;
            }

            if (layer->portamento.mode != 0) {
                portamento = &layer->portamento;
                vel = (semitone > layer->portamentoTargetNote) ? semitone : layer->portamentoTargetNote;

                if (instrument != NULL) {
                    tunedSample = func_800AACF0(instrument, vel);
                    sameTunedSample = (layer->tunedSample == tunedSample);
                    layer->tunedSample = tunedSample;
                    tuning = tunedSample->tuning;
                } else {
                    layer->tunedSample = NULL;
                    tuning = 1.0f;
                    if (instOrWave >= 0xC0) {
                        layer->tunedSample = &gSynthesisReverbs[instOrWave - 0xC0].tunedSample;
                    }
                }

                temp_fv1 = gPitchFrequencies[(s32) semitone] * tuning;
                temp_fa1 = gPitchFrequencies[layer->portamentoTargetNote] * tuning;

                switch (layer->portamento.mode & ~0x80) {
                    case 1:
                    case 3:
                    case 5:
                        freqMod2 = temp_fv1;
                        freqMod = temp_fa1;
                        break;
                    case 2:
                    case 4:
                        freqMod = temp_fv1;
                        freqMod2 = temp_fa1;
                        break;
                    default:
                        freqMod = temp_fv1;
                        freqMod2 = temp_fv1;
                        break;
                }

                portamento->extent = (freqMod2 / freqMod) - 1.0f;

                if (layer->portamento.mode & 0x80) {
                    portamento->speed = ((s32) seqPlayer->tempo * 32512.0f) /
                                        ((f32) layer->delay * (f32) gMaxTempo * (f32) (s32) layer->portamentoTime);
                } else {
                    portamento->speed = 127.0f / (s32) layer->portamentoTime;
                }

                portamento->cur = 0;
                layer->freqMod = freqMod;
                if ((layer->portamento.mode & ~0x80) == 5) {
                    layer->portamentoTargetNote = semitone;
                }
                break;
            }

            if (instrument != NULL) {
                tunedSample = func_800AACF0(instrument, semitone);
                sameTunedSample = (tunedSample == layer->tunedSample);
                layer->tunedSample = tunedSample;
                layer->freqMod = gPitchFrequencies[(s32) semitone] * tunedSample->tuning;
            } else {
                layer->tunedSample = NULL;
                layer->freqMod = gPitchFrequencies[(s32) semitone];
                if (instOrWave >= 0xC0) {
                    layer->tunedSample = &gSynthesisReverbs[instOrWave - 0xC0].tunedSample;
                }
            }
            break;
    }

    layer->delay2 = layer->delay;
    layer->freqMod *= layer->bend;

    return sameTunedSample;
}

extern u32 gAudioRandom;

s32 func_800AD378(SequenceLayer* layer, s32 cmd) {
    SeqScriptState* state = &layer->state;
    u16 delay;
    s32 velocity;
    SequenceChannel* channel = layer->channel;
    SequencePlayer* seqPlayer = channel->seqPlayer;
    s32 intDelta;
    f32 floatDelta;

    if (cmd == 0xC0) {
        layer->delay = func_800AC940(state);
        layer->muted = true;
        layer->bit8 = false;
        return -1;
    }

    layer->muted = false;

    switch (cmd & 0xC0) {
        case 0x00:
            delay = func_800AC940(state);
            velocity = *(state->pc++);
            layer->gateTime = *(state->pc++);
            layer->lastDelay = delay;
            break;

        case 0x40:
            delay = func_800AC940(state);
            velocity = *(state->pc++);
            layer->gateTime = 0;
            layer->lastDelay = delay;
            break;

        case 0x80:
            delay = layer->lastDelay;
            velocity = *(state->pc++);
            layer->gateTime = *(state->pc++);
            break;
    }

    layer->velocitySquare2 = SQ((f32) velocity) / SQ(127.0f);
    cmd -= (cmd & 0xC0);

    if (channel->velocityRandomVariance != 0) {
        floatDelta = layer->velocitySquare2 * (gAudioRandom % channel->velocityRandomVariance) / 100.0f;
        if ((gAudioRandom & 0x8000) != 0) {
            floatDelta = -floatDelta;
        }

        layer->velocitySquare = layer->velocitySquare2 + floatDelta;

        if (layer->velocitySquare < 0.0f) {
            layer->velocitySquare = 0.0f;
        } else if (layer->velocitySquare > 1.0f) {
            layer->velocitySquare = 1.0f;
        }
    } else {
        layer->velocitySquare = layer->velocitySquare2;
    }

    layer->delay = delay;
    layer->gateDelay = (layer->gateTime * delay) >> 8;

    if (channel->gateTimeRandomVariance != 0) {
        //! @bug should probably be gateTimeRandomVariance
        intDelta = (layer->gateDelay * (gAudioRandom % channel->velocityRandomVariance)) / 100;
        if ((gAudioRandom & 0x4000) != 0) {
            intDelta = -intDelta;
        }

        layer->gateDelay += intDelta;
        if (layer->gateDelay < 0) {
            layer->gateDelay = 0;
        } else if (layer->gateDelay > layer->delay) {
            layer->gateDelay = layer->delay;
        }
    }

    if (channel->muted) {
        layer->muted = true;
        return -1;
    }

    if (seqPlayer->skipTicks != 0) {
        layer->muted = true;
        return -1;
    }

    return cmd;
}

void func_800AD6D4(SequenceChannel* channel, u8 priority) {
    if ((priority & 0xF) != 0) {
        channel->notePriority = priority & 0xF;
    }

    priority = priority >> 4;
    if (priority != 0) {
        channel->notePriority2 = priority;
    }
}

u8 func_800AD704(SequenceChannel* channel, u8 instId, Instrument** instOut, AdsrSettings* adsr) {
    Instrument* inst = func_800AAD2C(channel->fontId, instId);

    if (inst == NULL) {
        *instOut = NULL;
        return 0;
    }

    adsr->envelope = inst->envelope;
    adsr->decayIndex = inst->adsrDecayIndex;
    *instOut = inst;

    return ++instId;
}

void func_800AD774(SequenceChannel* channel, u8 instId) {
    if (instId >= 0x80) {
        // Synthetic Waves
        channel->instOrWave = instId;
        channel->instrument = NULL;
    } else if (instId == 0x7F) {
        // Drums
        channel->instOrWave = 0;
        channel->instrument = (Instrument*) 1; // invalid pointer, never dereferenced
    } else {
        // Instruments
        if ((channel->instOrWave = func_800AD704(channel, instId, &channel->instrument, &channel->adsr)) == 0) {
            channel->hasInstrument = false;
            return;
        }
    }

    channel->hasInstrument = true;
}

void func_800AD804(SequenceChannel* channel, u8 volume) {
    channel->volume = (s32) volume / 127.0f;
}

extern u8 sSeqInstructionArgsTable[];

void func_800AD828(SequenceChannel* channel) {
    u8* data;
    u8* seqData;
    s8 cmdArgS8;
    u8 cmd;
    u8 highBits;
    u8 lowBits;
    s32 i;
    SequencePlayer* seqPlayer;
    SeqScriptState* scriptState = &channel->scriptState;
    s32 param;
    u32 cmdArgs[3];
    s32 delay;
    u16 cmdArgU16;

    if (channel->stopScript) {
        goto exit_loop;
    }

    seqPlayer = channel->seqPlayer;
    if (channel->delay >= 2) {
        channel->delay--;
        goto exit_loop;
    }

    while (true) {
        cmd = func_800AC8F4(scriptState);
        if (cmd >= 0xB0) {
            highBits = sSeqInstructionArgsTable[cmd - 0xB0];
            lowBits = highBits & 3;

            // read in arguments for the instruction
            for (i = 0; i < lowBits; i++, highBits <<= 1) {
                if (!(highBits & 0x80)) {
                    cmdArgs[i] = func_800AC8F4(scriptState);
                } else {
                    cmdArgs[i] = func_800AC908(scriptState);
                }
            }

            // Control Flow Commands
            if (cmd >= 0xF2) {
                delay = func_800AC038(seqPlayer, scriptState, cmd, cmdArgs[0]);

                if (delay != 0) {
                    if (delay == -1) {
                        func_800AC4C8(channel);
                    } else {
                        channel->delay = delay;
                    }
                    break;
                }
                continue;
            }

            switch (cmd) {
                case 0xEA:
                    channel->stopScript = true;
                    goto exit_loop;

                case 0xF1:
                    func_800AB0AC(&channel->notePool);
                    cmd = (u8) cmdArgs[0];
                    func_800AB204(&channel->notePool, cmd);
                    break;

                case 0xF0:
                    func_800AB0AC(&channel->notePool);
                    break;

                case 0xC2:
                    cmdArgU16 = (u16) cmdArgs[0];
                    channel->dynTable = (void*) &seqPlayer->seqData[cmdArgU16];
                    break;

                case 0xC5:
                    if (scriptState->value != -1) {
                        data = (*channel->dynTable)[scriptState->value];
                        cmdArgU16 = (u16) ((data[0] << 8) + data[1]);

                        channel->dynTable = (void*) &seqPlayer->seqData[cmdArgU16];
                    }
                    break;

                case 0xEB:
                    cmd = (u8) cmdArgs[0];

                    cmdArgU16 = ((u16*) gSeqFontTable)[seqPlayer->seqId];
                    lowBits = gSeqFontTable[cmdArgU16];
                    cmd = gSeqFontTable[cmdArgU16 + lowBits - cmd];

                    if (func_800B3534(FONT_TABLE, CACHE_EITHER, cmd)) {
                        channel->fontId = cmd;
                    }

                    cmdArgs[0] = cmdArgs[1];
                    /* fallthrough */
                case 0xC1:
                    cmd = (u8) cmdArgs[0];
                    func_800AD774(channel, cmd);
                    break;

                case 0xC3:
                    channel->largeNotes = false;
                    break;

                case 0xC4:
                    channel->largeNotes = true;
                    break;

                case 0xDF:
                    cmd = (u8) cmdArgs[0];
                    func_800AD804(channel, cmd);
                    channel->changes.s.volume = true;
                    break;

                case 0xE0:
                    cmd = (u8) cmdArgs[0];
                    channel->volumeMod = (s32) cmd / 128.0f;
                    channel->changes.s.volume = true;
                    break;

                case 0xDE:
                    cmdArgU16 = (u16) cmdArgs[0];
                    channel->freqMod = (s32) cmdArgU16 / 32768.0f;
                    channel->changes.s.freqMod = true;
                    break;

                case 0xD3:
                    cmd = (u8) cmdArgs[0];
                    cmd += 0x80;
                    channel->freqMod = gBendPitchOneOctaveFrequencies[cmd];
                    channel->changes.s.freqMod = true;
                    break;

                case 0xEE:
                    cmd = (u8) cmdArgs[0];
                    cmd += 0x80;
                    channel->freqMod = gBendPitchTwoSemitonesFrequencies[cmd];
                    channel->changes.s.freqMod = true;
                    break;

                case 0xDD:
                    cmd = (u8) cmdArgs[0];
                    channel->unkPan = cmd;
                    channel->changes.s.pan = true;
                    break;

                case 0xDC:
                    cmd = (u8) cmdArgs[0];
                    channel->unkPan2 = cmd;
                    channel->changes.s.pan = true;
                    break;

                case 0xDB:
                    cmdArgS8 = (s8) cmdArgs[0];
                    channel->transposition = cmdArgS8;
                    break;

                case 0xDA:
                    cmdArgU16 = (u16) cmdArgs[0];
                    channel->adsr.envelope = (EnvelopePoint*) &seqPlayer->seqData[cmdArgU16];
                    break;

                case 0xD9:
                    cmd = (u8) cmdArgs[0];
                    channel->adsr.decayIndex = cmd;
                    break;

                case 0xD4:
                    cmd = (u8) cmdArgs[0];
                    channel->targetReverbVol = cmd;
                    break;

                case 0xC6:
                    cmd = (u8) cmdArgs[0];

                    cmdArgU16 = ((u16*) gSeqFontTable)[seqPlayer->seqId];
                    lowBits = gSeqFontTable[cmdArgU16];
                    cmd = gSeqFontTable[cmdArgU16 + lowBits - cmd];

                    if (func_800B3534(FONT_TABLE, CACHE_EITHER, cmd)) {
                        channel->fontId = cmd;
                    }
                    break;

                case 0xC7:
                    cmd = (u8) cmdArgs[0];
                    cmdArgU16 = (u16) cmdArgs[1];
                    seqData = &seqPlayer->seqData[cmdArgU16];
                    seqData[0] = (u8) scriptState->value + cmd;
                    break;

                case 0xC8:
                case 0xCC:
                case 0xC9:
                    cmdArgS8 = (s8) cmdArgs[0];

                    if (cmd == 0xC8) {
                        scriptState->value -= cmdArgS8;
                    } else if (cmd == 0xCC) {
                        scriptState->value = cmdArgS8;
                    } else {
                        scriptState->value &= cmdArgS8;
                    }
                    break;

                case 0xCD:
                    cmd = (u8) cmdArgs[0];
                    func_800AC4C8(seqPlayer->channels[cmd]);
                    break;

                case 0xCB:
                    cmdArgU16 = (u16) cmdArgs[0];
                    scriptState->value = *(seqPlayer->seqData + (u32) (cmdArgU16 + scriptState->value));
                    break;

                case 0xD0:
                    cmd = (u8) cmdArgs[0];
                    channel->reverbIndex = cmd;
                    break;

                case 0xD1:
                    cmd = (u8) cmdArgs[0];
                    channel->noteAllocPolicy = cmd;
                    break;

                case 0xD2:
                    cmd = (u8) cmdArgs[0];
                    channel->adsr.sustain = cmd;
                    break;

                case 0xE4:
                    if (scriptState->value != -1) {
                        data = (*channel->dynTable)[scriptState->value];
                        //! @bug: Missing a stack depth check here
                        scriptState->stack[scriptState->depth++] = scriptState->pc;
                        cmdArgU16 = (u16) ((data[0] << 8) + data[1]);
                        scriptState->pc = seqPlayer->seqData + cmdArgU16;
                    }
                    break;

                case 0xE7:
                    cmdArgU16 = (u16) cmdArgs[0];
                    data = &seqPlayer->seqData[cmdArgU16];
                    channel->muteBehavior = *data++;
                    channel->noteAllocPolicy = *data++;
                    func_800AD6D4(channel, *data++);
                    channel->transposition = (s8) *data++;
                    channel->unkPan = *data++;
                    channel->unkPan2 = *data++;
                    channel->targetReverbVol = *data++;
                    channel->changes.s.pan = true;
                    break;

                case 0xE8:
                    channel->muteBehavior = cmdArgs[0];
                    channel->noteAllocPolicy = cmdArgs[1];
                    cmd = (u8) cmdArgs[2];
                    func_800AD6D4(channel, cmd);
                    channel->transposition = (s8) func_800AC8F4(scriptState);
                    channel->unkPan = func_800AC8F4(scriptState);
                    channel->unkPan2 = func_800AC8F4(scriptState);
                    channel->targetReverbVol = func_800AC8F4(scriptState);
                    func_800AC8F4(scriptState);
                    //! @bug: Not marking reverb state as changed
                    channel->changes.s.pan = true;
                    break;
                case 0xEC:
                    channel->adsr.sustain = 0;
                    channel->velocityRandomVariance = 0;
                    channel->gateTimeRandomVariance = 0;
                    channel->freqMod = 1.0f;
                    break;

                case 0xE9:
                    func_800AD6D4(channel, (u8) cmdArgs[0]);
                    break;

                case 0xCE:
                    cmdArgU16 = (u16) cmdArgs[0];
                    channel->unkB8 = cmdArgU16;
                    break;

                case 0xCF:
                    cmdArgU16 = (u16) cmdArgs[0];
                    seqData = seqPlayer->seqData + cmdArgU16;
                    seqData[0] = (channel->unkB8 >> 8) & 0xFF;
                    seqData[1] = channel->unkB8 & 0xFF;
                    break;

                case 0xB2:
                    cmdArgU16 = (u16) cmdArgs[0];
                    channel->unkB8 = *(u16*) (seqPlayer->seqData + (u32) (cmdArgU16 + scriptState->value * 2));
                    break;

                case 0xB4:
                    channel->dynTable = (void*) &seqPlayer->seqData[channel->unkB8];
                    break;

                case 0xB5:
                    channel->unkB8 = ((u16*) (channel->dynTable))[scriptState->value];
                    break;

                case 0xB6:
                    scriptState->value = (*channel->dynTable)[0][scriptState->value];
                    break;
            }
            continue;
        }

        if (cmd >= 0x80) {
            lowBits = cmd & 0x7;

            switch (cmd & 0xF8) {
                case 0x80:
                    if (channel->layers[lowBits] != NULL) {
                        scriptState->value = channel->layers[lowBits]->finished;
                    } else {
                        scriptState->value = -1;
                    }
                    break;

                case 0x88:
                    cmdArgU16 = func_800AC908(scriptState);
                    if (!func_800AC328(channel, lowBits)) {
                        channel->layers[lowBits]->state.pc = &seqPlayer->seqData[cmdArgU16];
                    }
                    break;

                case 0x90:
                    func_800AC478(channel, lowBits);
                    break;

                case 0x98:
                    if (scriptState->value != -1 && func_800AC328(channel, lowBits) != -1) {
                        data = (*channel->dynTable)[scriptState->value];
                        cmdArgU16 = (data[0] << 8) + data[1];
                        channel->layers[lowBits]->state.pc = &seqPlayer->seqData[cmdArgU16];
                    }
                    break;
            }
            continue;
        }

        lowBits = cmd & 0xF;

        switch (cmd & 0xF0) {
            case 0x00:
                channel->delay = lowBits;
                goto exit_loop;

            case 0x10:

                channel->seqScriptIO[lowBits] = SEQ_IO_VAL_NONE;
                if (func_800B0D30(channel->fontId, scriptState->value, &channel->seqScriptIO[lowBits]) == -1) {}

                break;
            case 0x70:
                channel->seqScriptIO[lowBits] = scriptState->value;
                break;

            case 0x60:
                scriptState->value = channel->seqScriptIO[lowBits];
                if (lowBits < 2) {
                    channel->seqScriptIO[lowBits] = SEQ_IO_VAL_NONE;
                }
                break;

            case 0x50:
                scriptState->value -= channel->seqScriptIO[lowBits];
                break;

            case 0x20:
                cmdArgU16 = func_800AC908(scriptState);
                func_800AC6AC(seqPlayer, lowBits, &seqPlayer->seqData[cmdArgU16]);
                break;

            case 0x30:
                cmd = func_800AC8F4(scriptState);
                seqPlayer->channels[lowBits]->seqScriptIO[cmd] = scriptState->value;
                break;

            case 0x40:
                cmd = func_800AC8F4(scriptState);
                scriptState->value = seqPlayer->channels[lowBits]->seqScriptIO[cmd];
                break;
        }
    }
exit_loop:

    for (i = 0; i < ARRAY_COUNT(channel->layers); i++) {
        if (channel->layers[i] != NULL) {
            func_800AC980(channel->layers[i]);
        }
    }
}

void func_800AE19C(SequencePlayer* seqPlayer) {
    u8 cmd;
    u8 cmdLowBits;
    u16 temp;
    SeqScriptState* seqScript = &seqPlayer->scriptState;
    s32 i;
    s32 value;
    u8* data;
    u8* data2;
    u8* data3;
    s32 dummy;
    s32 delay;

    if (!seqPlayer->enabled) {
        return;
    }

    if (!func_800AF2C4(seqPlayer->seqId) || !func_800AF288(seqPlayer->defaultFont)) {
        func_800AC744(seqPlayer);
        return;
    }

    func_800AF36C(seqPlayer->seqId, LOAD_STATUS_COMPLETE);
    func_800AF33C(seqPlayer->defaultFont, LOAD_STATUS_COMPLETE);

    seqPlayer->scriptCounter++;

    seqPlayer->tempoAcc += seqPlayer->tempo;
    seqPlayer->tempoAcc += (s16) seqPlayer->tempoChange;
    if (seqPlayer->tempoAcc < gMaxTempo) {
        return;
    }
    seqPlayer->tempoAcc -= (u16) gMaxTempo;

    if (seqPlayer->delay > 1) {
        seqPlayer->delay--;
    } else {
        seqPlayer->recalculateVolume = true;

        while (true) {
            cmd = func_800AC8F4(seqScript);

            if (cmd >= 0xF2) {
                delay = func_800AC038(seqPlayer, seqScript, cmd, func_800ABFD0(&seqPlayer->scriptState, cmd));

                if (delay != 0) {
                    if (delay == -1) {
                        func_800AC744(seqPlayer);
                    } else {
                        seqPlayer->delay = delay;
                    }
                    break;
                }
                continue;
            }

            if (cmd >= 0xC0) {
                switch (cmd) {
                    case 0xDF:
                        seqPlayer->transposition = 0;
                        /* fallthrough */
                    case 0xDE:
                        seqPlayer->transposition += (s8) func_800AC8F4(seqScript);
                        break;

                    case 0xDD:
                        seqPlayer->tempo = func_800AC8F4(seqScript) * SEQTICKS_PER_BEAT;
                        if (seqPlayer->tempo > gMaxTempo) {
                            seqPlayer->tempo = (u16) gMaxTempo;
                        }

                        if ((s16) seqPlayer->tempo <= 0) {
                            seqPlayer->tempo = 1;
                        }
                        break;

                    case 0xDC:
                        seqPlayer->tempoChange = (s8) func_800AC8F4(seqScript) * SEQTICKS_PER_BEAT;
                        break;

                    case 0xDA:
                        func_800AC8F4(seqScript);
                        func_800AC908(seqScript);
                        break;

                    case 0xDB:
                        seqPlayer->fadeVolume = (s32) func_800AC8F4(seqScript) / 127.0f;
                        break;

                    case 0xD9:
                        seqPlayer->fadeVolumeMod = (s8) func_800AC8F4(seqScript) / 127.0f;
                        break;

                    case 0xD7:
                        temp = func_800AC908(seqScript);
                        func_800AC534(seqPlayer, temp);
                        break;

                    case 0xD6:
                        func_800AC908(seqScript);
                        break;

                    case 0xD5:
                        func_800AC8F4(seqScript);
                        break;

                    case 0xD3:
                        func_800AC8F4(seqScript);
                        break;

                    case 0xD0:
                        seqPlayer->noteAllocPolicy = func_800AC8F4(seqScript);
                        break;

                    case 0xCC:
                        seqScript->value = func_800AC8F4(seqScript);
                        break;

                    case 0xC9:
                        seqScript->value &= func_800AC8F4(seqScript);
                        break;

                    case 0xC8:
                        seqScript->value -= func_800AC8F4(seqScript);
                        break;

                    case 0xC7:
                        cmd = func_800AC8F4(seqScript);
                        temp = func_800AC908(seqScript);
                        data2 = &seqPlayer->seqData[temp];
                        *data2 = (u8) seqScript->value + cmd;
                        break;
                }
                continue;
            }

            cmdLowBits = cmd & 0x0F;

            switch (cmd & 0xF0) {
                case 0x00:
                    seqScript->value = seqPlayer->channels[cmdLowBits]->finished;
                    break;

                case 0x50:
                    seqScript->value -= seqPlayer->seqScriptIO[cmdLowBits];
                    break;

                case 0x70:
                    seqPlayer->seqScriptIO[cmdLowBits] = seqScript->value;
                    break;

                case 0x80:
                    seqScript->value = seqPlayer->seqScriptIO[cmdLowBits];
                    if (cmdLowBits < 2) {
                        seqPlayer->seqScriptIO[cmdLowBits] = SEQ_IO_VAL_NONE;
                    }
                    break;

                case 0x40:
                    func_800AC4C8(seqPlayer->channels[cmdLowBits]);
                    break;

                case 0x90:
                    temp = func_800AC908(seqScript);
                    func_800AC6AC(seqPlayer, cmdLowBits, (void*) &seqPlayer->seqData[temp]);
                    break;
            }
        }
    }

    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
        if (seqPlayer->channels[i]->enabled) {
            func_800AD828(seqPlayer->channels[i]);
        }
    }
}

void func_800ABAFC(SequencePlayer* seqPlayer);

void func_800AE624(s32 arg0) {
    SequencePlayer* seqPlayer;
    u32 i;

    for (i = 0; i < (u32) gAudioBufferParams.numSequencePlayers; i++) {
        seqPlayer = &gSeqPlayers[i];
        if (seqPlayer->enabled == true) {
            func_800AE19C(seqPlayer);
            func_800ABAFC(seqPlayer);
        }
    }

    func_800AA940();
}

void func_800AE6B0(SequencePlayer* seqPlayer) {
    while (seqPlayer->skipTicks > 0) {
        func_800AE19C(seqPlayer);
        func_800ABAFC(seqPlayer);
        seqPlayer->skipTicks--;
    }
}

extern u8 gDefaultShortNoteVelocityTable[];
extern u8 gDefaultShortNoteGateTimeTable[];

void func_800AE700(s32 seqPlayerIndex) {
    SequencePlayer* seqPlayer = &gSeqPlayers[seqPlayerIndex];
    s32 i;

    func_800AC744(seqPlayer);
    seqPlayer->stopScript = false;
    seqPlayer->delay = 0;
    seqPlayer->state = 1;
    seqPlayer->fadeTimer = 0;
    seqPlayer->fadeTimerUnkEu = 0;
    seqPlayer->tempoAcc = 0;
    seqPlayer->tempo = 120 * SEQTICKS_PER_BEAT; // 120 BPM
    seqPlayer->tempoChange = 0;
    seqPlayer->transposition = 0;
    seqPlayer->noteAllocPolicy = 0;
    seqPlayer->shortNoteVelocityTable = gDefaultShortNoteVelocityTable;
    seqPlayer->shortNoteGateTimeTable = gDefaultShortNoteGateTimeTable;
    seqPlayer->scriptCounter = 0;
    seqPlayer->fadeVolume = 1.0f;
    seqPlayer->fadeVolumeMod = 1.0f;
    seqPlayer->fadeVelocity = 0.0f;
    seqPlayer->volume = 0.0f;
    seqPlayer->muteVolumeMod = 0.5f;

    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
        func_800AC214(seqPlayer->channels[i]);
    }
}

void* func_800B2A0C(AudioAllocPool* pool, u32 size);

void func_800AE7F8(s32 seqPlayerIndex) {
    SequenceChannel* channel;
    SequencePlayer* seqPlayer = &gSeqPlayers[seqPlayerIndex];
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
        seqPlayer->channels[i] = func_800B2A0C(&gMiscPool, sizeof(SequenceChannel));
        if (seqPlayer->channels[i] == NULL) {
            seqPlayer->channels[i] = &gSeqChannelNone;
        } else {
            channel = seqPlayer->channels[i];
            channel->seqPlayer = seqPlayer;
            channel->enabled = false;
            //! @bug uses size of gSeqLayers instead of channel->layers
            for (j = 0; j < ARRAY_COUNT(gSeqLayers); j++) {
                channel->layers[j] = NULL;
            }
        }
        func_800AC214(seqPlayer->channels[i]);
    }
}

void func_800AE8F0(void) {
    SequencePlayer* seqPlayer;
    s32 i;
    s32 j;

    func_800AC870();

    for (i = 0; i < ARRAY_COUNT(gSeqLayers); i++) {
        gSeqLayers[i].channel = NULL;
        gSeqLayers[i].enabled = false;
    }

    for (i = 0; i < 3; i++) {
        seqPlayer = &gSeqPlayers[i];
        for (j = 0; j < ARRAY_COUNT(seqPlayer->channels); j++) {
            seqPlayer->channels[j] = &gSeqChannelNone;
        }
        seqPlayer->seqScriptIO[0] = SEQ_IO_VAL_NONE;
        seqPlayer->muteBehavior = 0x60;
        seqPlayer->enabled = false;
        seqPlayer->muted = false;
        seqPlayer->fontDmaInProgress = false;
        seqPlayer->seqDmaInProgress = false;

        func_800AAFAC(&seqPlayer->notePool);
        func_800AE700(i);
    }
}
