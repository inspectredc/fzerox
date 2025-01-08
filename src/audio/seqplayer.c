#include "global.h"
#include "audio.h"

#define PORTAMENTO_IS_SPECIAL(x) ((x).mode & 0x80)
#define PORTAMENTO_MODE(x) ((x).mode & ~0x80)

typedef enum {
    /* 0 */ PORTAMENTO_MODE_OFF,
    /* 1 */ PORTAMENTO_MODE_1,
    /* 2 */ PORTAMENTO_MODE_2,
    /* 3 */ PORTAMENTO_MODE_3,
    /* 4 */ PORTAMENTO_MODE_4,
    /* 5 */ PORTAMENTO_MODE_5
} PortamentoMode;

/**
 * sSeqInstructionArgsTable is a table for each sequence instruction
 * that contains both how many arguments an instruction takes, as well
 * as the type of each argument
 *
 * sSeqInstructionArgsTable is bitpacked as follows:
 * abcUUUnn
 *
 * n - number of arguments that the sequence instruction takes
 *
 * a - bitFlag for the type of arg0 if it exists
 * b - bitFlag for the type of arg1 if it exists
 * c - bitFlag for the type of arg2 if it exists
 *
 * bitFlag on - argument is s16
 * bitFlag off - argument is u8
 *
 * U - Unused
 */

// CMD_ARGS_(NUMBER_OF_ARGS)
#define CMD_ARGS_0() 0
#define CMD_ARGS_1(arg0Type) (((sizeof(arg0Type) - 1) << 7) | 1)
#define CMD_ARGS_2(arg0Type, arg1Type) (((sizeof(arg0Type) - 1) << 7) | ((sizeof(arg1Type) - 1) << 6) | 2)
#define CMD_ARGS_3(arg0Type, arg1Type, arg2Type) \
    (((sizeof(arg0Type) - 1) << 7) | ((sizeof(arg1Type) - 1) << 6) | ((sizeof(arg2Type) - 1) << 5) | 3)

u8 sSeqInstructionArgsTable[] = {
    CMD_ARGS_1(s16),        // 0xB0
    CMD_ARGS_0(),           // 0xB1
    CMD_ARGS_1(s16),        // 0xB2
    CMD_ARGS_1(u8),         // 0xB3
    CMD_ARGS_0(),           // 0xB4
    CMD_ARGS_0(),           // 0xB5
    CMD_ARGS_0(),           // 0xB6
    CMD_ARGS_1(s16),        // 0xB7
    CMD_ARGS_1(u8),         // 0xB8
    CMD_ARGS_1(u8),         // 0xB9
    CMD_ARGS_1(u8),         // 0xBA
    CMD_ARGS_2(u8, s16),    // 0xBB
    CMD_ARGS_0(),           // 0xBC
    CMD_ARGS_0(),           // 0xBD
    CMD_ARGS_0(),           // 0xBE
    CMD_ARGS_0(),           // 0xBF
    CMD_ARGS_0(),           // 0xC0
    CMD_ARGS_1(u8),         // 0xC1
    CMD_ARGS_1(s16),        // 0xC2
    CMD_ARGS_0(),           // 0xC3
    CMD_ARGS_0(),           // 0xC4
    CMD_ARGS_0(),           // 0xC5
    CMD_ARGS_1(u8),         // 0xC6
    CMD_ARGS_2(u8, s16),    // 0xC7
    CMD_ARGS_1(u8),         // 0xC8
    CMD_ARGS_1(u8),         // 0xC9
    CMD_ARGS_1(u8),         // 0xCA
    CMD_ARGS_1(s16),        // 0xCB
    CMD_ARGS_1(u8),         // 0xCC
    CMD_ARGS_1(u8),         // 0xCD
    CMD_ARGS_1(s16),        // 0xCE
    CMD_ARGS_1(s16),        // 0xCF
    CMD_ARGS_1(u8),         // 0xD0
    CMD_ARGS_1(u8),         // 0xD1
    CMD_ARGS_1(u8),         // 0xD2
    CMD_ARGS_1(u8),         // 0xD3
    CMD_ARGS_1(u8),         // 0xD4
    CMD_ARGS_1(u8),         // 0xD5
    CMD_ARGS_1(u8),         // 0xD6
    CMD_ARGS_1(u8),         // 0xD7
    CMD_ARGS_1(u8),         // 0xD8
    CMD_ARGS_1(u8),         // 0xD9
    CMD_ARGS_1(s16),        // 0xDA
    CMD_ARGS_1(u8),         // 0xDB
    CMD_ARGS_1(u8),         // 0xDC
    CMD_ARGS_1(u8),         // 0xDD
    CMD_ARGS_1(s16),        // 0xDE
    CMD_ARGS_1(u8),         // 0xDF
    CMD_ARGS_1(u8),         // 0xE0
    CMD_ARGS_3(u8, u8, u8), // 0xE1
    CMD_ARGS_3(u8, u8, u8), // 0xE2
    CMD_ARGS_1(u8),         // 0xE3
    CMD_ARGS_0(),           // 0xE4
    CMD_ARGS_1(u8),         // 0xE5
    CMD_ARGS_1(u8),         // 0xE6
    CMD_ARGS_1(s16),        // 0xE7
    CMD_ARGS_3(u8, u8, u8), // 0xE8
    CMD_ARGS_1(u8),         // 0xE9
    CMD_ARGS_0(),           // 0xEA
    CMD_ARGS_2(u8, u8),     // 0xEB
    CMD_ARGS_0(),           // 0xEC
    CMD_ARGS_1(u8),         // 0xED
    CMD_ARGS_1(u8),         // 0xEE
    CMD_ARGS_2(s16, u8),    // 0xEF
    CMD_ARGS_0(),           // 0xF0
    CMD_ARGS_1(u8),         // 0xF1
    // Control flow instructions (>= 0xF2) can only have 0 or 1 args
    CMD_ARGS_1(u8),  // 0xF2
    CMD_ARGS_1(u8),  // 0xF3
    CMD_ARGS_1(u8),  // 0xF4
    CMD_ARGS_1(s16), // 0xF5
    CMD_ARGS_0(),    // 0xF6
    CMD_ARGS_0(),    // 0xF7
    CMD_ARGS_1(u8),  // 0xF8
    CMD_ARGS_1(s16), // 0xF9
    CMD_ARGS_1(s16), // 0xFA
    CMD_ARGS_1(s16), // 0xFB
    CMD_ARGS_1(s16), // 0xFC
    CMD_ARGS_0(),    // 0xFD
    CMD_ARGS_0(),    // 0xFE
    CMD_ARGS_0(),    // 0xFF
};

static char D_800D08B0[] = "Audio:Track:Warning: No Free Notetrack\n";
static char D_800D08D8[] = "Stop Release\n";
static char D_800D08E8[] = "Error:Same List Add\n";
static char D_800D0900[] = "Wait Time out!\n";
static char D_800D0910[] = "WARNING: NPRG: cannot change %d\n";
static char D_800D0934[] = "Audio:Track:NOTE:UNDEFINED NOTE COM. %x\n";
static char D_800D0960[] = "Error: Subtrack no prg.\n";
static char D_800D097C[] = "ERR %x\n";
static char D_800D0984[] = "Note OverFlow %d\n";
static char D_800D0998[] = "trs %d , %d, %d\n";
static char D_800D09AC[] = "SUB:ERR:BANK %d NOT CACHED.\n";
static char D_800D09CC[] = "SUB:ERR:BANK %d NOT CACHED.\n";
static char D_800D09EC[] = "[%2x] \n";
static char D_800D09F4[] = "Err :Sub %x ,address %x:Undefined SubTrack Function %x";
static char D_800D0A2C[] = "VoiceLoad Error Bank:%d,Prog:%d\n";
static char D_800D0A50[] = "Disappear Sequence or Bank %d\n";
static char D_800D0A70[] = "Group:Undefine upper C0h command (%x)\n";
static char D_800D0A98[] = "Group:Undefined Command\n";

u8 AudioSeq_ScriptReadU8(SeqScriptState*);
s16 AudioSeq_ScriptReadS16(SeqScriptState*);

s32 AudioSeq_GetScriptControlFlowArgument(SeqScriptState* state, u8 cmd) {
    u8 highBits = sSeqInstructionArgsTable[cmd - 0xB0];
    u8 lowBits = highBits & 3;
    u16 cmdArg = 0;

    // only 1 argument
    if (lowBits == 1) {
        if (!(highBits & 0x80)) {
            cmdArg = AudioSeq_ScriptReadU8(state);
        } else {
            cmdArg = AudioSeq_ScriptReadS16(state);
        }
    }

    return cmdArg;
}

u16 AudioSeq_ScriptReadCompressedU16(SeqScriptState*);

s32 AudioSeq_HandleScriptFlowControl(SequencePlayer* seqPlayer, SeqScriptState* state, s32 cmd, s32 cmdArg) {
    switch (cmd) {
        case 0xFF:
            if (state->depth == 0) {
                return -1;
            }
            state->pc = state->stack[--state->depth];
            break;
        case 0xFD:
            return AudioSeq_ScriptReadCompressedU16(state);
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

void AudioSeq_InitSequenceChannel(SequenceChannel* channel) {
    s32 i;

    if (channel == &gSeqChannelNone) {
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
    channel->volumeScale = 1.0f;
    channel->freqScale = 1.0f;

    for (i = 0; i < 8; i++) {
        channel->seqScriptIO[i] = -1;
    }
    channel->unused = 0;
    Audio_InitNoteLists(&channel->notePool);
}

void* AudioSeq_AudioListPopBack(AudioListItem*);

s32 AudioSeq_SeqChannelSetLayer(SequenceChannel* channel, s32 layerIndex) {
    SequenceLayer* newLayer;
    SequenceLayer* layer;

    if (channel->layers[layerIndex] == NULL) {
        newLayer = AudioSeq_AudioListPopBack(&gLayerFreeList);
        channel->layers[layerIndex] = newLayer;
        if (newLayer == NULL) {
            channel->layers[layerIndex] = NULL;
            return -1;
        }
    } else {
        Audio_SeqLayerNoteDecay(channel->layers[layerIndex]);
    }

    layer = channel->layers[layerIndex];
    layer->channel = channel;
    layer->adsr = channel->adsr;
    layer->enabled = 1;
    layer->muted = 0;
    layer->continuousNotes = 0;
    layer->finished = 0;
    layer->adsr.decayIndex = 0;
    layer->ignoreDrumPan = false;
    layer->bit8 = 0;

    layer->portamento.mode = PORTAMENTO_MODE_OFF;
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
    layer->freqScale = 1.0f;
    layer->bend = 1.0f;
    layer->velocitySquare = 0.0f;

    return 0;
}

void AudioSeq_SeqLayerDisable(SequenceLayer* layer) {
    if (layer != NULL) {
        Audio_SeqLayerNoteDecay(layer);
        layer->enabled = 0;
        layer->finished = 1;
    }
}

void AudioSeq_AudioListPushBack(AudioListItem* list, AudioListItem* item);

void AudioSeq_SeqLayerFree(SequenceChannel* channel, s32 layerIndex) {
    SequenceLayer* layer = channel->layers[layerIndex];

    if (layer != NULL) {
        AudioSeq_AudioListPushBack(&gLayerFreeList, &layer->listItem);
        AudioSeq_SeqLayerDisable(layer);
        channel->layers[layerIndex] = NULL;
    }
}

void Audio_NotePoolClear(NotePool*);

void AudioSeq_SequenceChannelDisable(SequenceChannel* channel) {
    s32 i;

    for (i = 0; i < 4; i++) {
        AudioSeq_SeqLayerFree(channel, i);
    }

    Audio_NotePoolClear(&channel->notePool);
    channel->enabled = false;
    channel->finished = true;
}

void AudioSeq_SequencePlayerSetupChannels(SequencePlayer* seqPlayer, u16 channelBits) {
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

void AudioSeq_SequencePlayerDisableChannels(SequencePlayer* seqPlayer, u16 channelBitsUnused) {
    SequenceChannel* channel;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
        channel = seqPlayer->channels[i];
        if (IS_SEQUENCE_CHANNEL_VALID(channel) == 1) {
            AudioSeq_SequenceChannelDisable(channel);
        }
    }
}

void AudioSeq_SequenceChannelEnable(SequencePlayer* seqPlayer, u8 channelIndex, void* script) {
    SequenceChannel* channel = seqPlayer->channels[channelIndex];
    s32 i;

    channel->enabled = true;
    channel->finished = false;
    channel->scriptState.depth = 0;
    channel->scriptState.pc = script;
    channel->delay = 0;

    for (i = 0; i < ARRAY_COUNT(channel->layers); i++) {
        if (channel->layers[i] != NULL) {
            AudioSeq_SeqLayerFree(channel, i);
        }
    }
}

void AudioLoad_SetSeqLoadStatus(s32, s32);

void AudioSeq_SequencePlayerDisable(SequencePlayer* seqPlayer) {
    AudioSeq_SequencePlayerDisableChannels(seqPlayer, 0xFFFF);
    Audio_NotePoolClear(&seqPlayer->notePool);

    seqPlayer->finished = true;
    seqPlayer->enabled = false;

    if (AudioLoad_IsSeqLoadComplete(seqPlayer->seqId)) {
        AudioLoad_SetSeqLoadStatus(seqPlayer->seqId, LOAD_STATUS_DISCARDABLE);
    }

    if (AudioLoad_IsFontLoadComplete(seqPlayer->defaultFont)) {
        AudioLoad_SetFontLoadStatus(seqPlayer->defaultFont, LOAD_STATUS_MAYBE_DISCARDABLE);
    }

    if (seqPlayer->defaultFont == gFontCache.temporary.entries[0].id) {
        gFontCache.temporary.nextSide = 1;
    } else if (seqPlayer->defaultFont == gFontCache.temporary.entries[1].id) {
        gFontCache.temporary.nextSide = 0;
    }
}

void AudioSeq_AudioListPushBack(AudioListItem* list, AudioListItem* item) {
    if (item->prev == NULL) {
        list->prev->next = item;
        item->prev = list->prev;
        item->next = list;
        list->prev = item;
        list->u.count++;
        item->pool = list->pool;
    }
}

void* AudioSeq_AudioListPopBack(AudioListItem* list) {
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

void AudioSeq_InitLayerFreelist(void) {
    s32 i;

    gLayerFreeList.prev = &gLayerFreeList;
    gLayerFreeList.next = &gLayerFreeList;
    gLayerFreeList.u.value = NULL;
    gLayerFreeList.pool = NULL;

    for (i = 0; i < 64; i++) {
        gSeqLayers[i].listItem.u.value = &gSeqLayers[i];
        gSeqLayers[i].listItem.prev = NULL;
        AudioSeq_AudioListPushBack(&gLayerFreeList, &gSeqLayers[i].listItem);
    }
}

u8 AudioSeq_ScriptReadU8(SeqScriptState* state) {
    return *(state->pc++);
}

s16 AudioSeq_ScriptReadS16(SeqScriptState* state) {
    s16 ret = *(state->pc++) << 8;

    ret = *(state->pc++) | ret;
    return ret;
}

u16 AudioSeq_ScriptReadCompressedU16(SeqScriptState* state) {
    u16 ret = *(state->pc++);

    if (ret & 0x80) {
        ret = (ret << 8) & 0x7F00;
        ret = *(state->pc++) | ret;
    }
    return ret;
}

void AudioSeq_SeqLayerProcessScriptStep1(SequenceLayer*);
s32 AudioSeq_SeqLayerProcessScriptStep2(SequenceLayer*);
s32 AudioSeq_SeqLayerProcessScriptStep3(SequenceLayer*, s32);
s32 AudioSeq_SeqLayerProcessScriptStep4(SequenceLayer*, s32);
s32 AudioSeq_SeqLayerProcessScriptStep5(SequenceLayer*, s32);

void AudioSeq_SeqLayerProcessScript(SequenceLayer* layer) {
    s32 cmd;

    if (!layer->enabled) {
        return;
    }

    if (layer->delay > 1) {
        layer->delay--;
        if (!layer->muted && (layer->delay <= layer->gateDelay)) {
            Audio_SeqLayerNoteDecay(layer);
            layer->muted = true;
        }
        return;
    }

    AudioSeq_SeqLayerProcessScriptStep1(layer);

    cmd = AudioSeq_SeqLayerProcessScriptStep2(layer);
    if (cmd == -1) {
        return;
    }

    cmd = AudioSeq_SeqLayerProcessScriptStep3(layer, cmd);

    if (cmd != -1) {
        cmd = AudioSeq_SeqLayerProcessScriptStep4(layer, cmd);
    }

    if (cmd != -1) {
        AudioSeq_SeqLayerProcessScriptStep5(layer, cmd);
    }

    if (layer->muted == true) {
        if ((layer->note != NULL) || layer->continuousNotes) {
            Audio_SeqLayerNoteDecay(layer);
        }
    }
}

void AudioSeq_SeqLayerProcessScriptStep1(SequenceLayer* layer) {
    if (!layer->continuousNotes) {
        Audio_SeqLayerNoteDecay(layer);
    } else if (layer->note != NULL && layer->note->playbackState.wantedParentLayer == layer) {
        Audio_SeqLayerNoteDecay(layer);
    }

    if (PORTAMENTO_MODE(layer->portamento) == PORTAMENTO_MODE_1 || PORTAMENTO_MODE(layer->portamento) == PORTAMENTO_MODE_2) {
        layer->portamento.mode = PORTAMENTO_MODE_OFF;
    }
    layer->notePropertiesNeedInit = true;
}

s32 AudioSeq_SeqLayerProcessScriptStep5(SequenceLayer* layer, s32 sameTunedSample) {
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
            Audio_SeqLayerNoteDecay(layer);
        }

        layer->note = Audio_AllocNote(layer);
    }

    if (layer->note != NULL && layer->note->playbackState.parentLayer == layer) {
        note = layer->note;

        Audio_NotePortamentoInit(note);
    }

    return 0;
}

u8 AudioSeq_GetInstrument(SequenceChannel* channel, u8 instId, Instrument** instOut, AdsrSettings* adsr);

s32 AudioSeq_SeqLayerProcessScriptStep2(SequenceLayer* layer) {
    SequenceChannel* channel = layer->channel;
    SeqScriptState* state = &layer->state;
    SequencePlayer* seqPlayer = channel->seqPlayer;
    u8 cmd;
    s32 cmdArg;
    u16 velocity;

    while (true) {
        cmd = AudioSeq_ScriptReadU8(state);

        if (cmd <= 0xC0) {
            return cmd;
        }

        if (cmd >= 0xF2) {
            cmdArg = AudioSeq_GetScriptControlFlowArgument(state, cmd);

            if (AudioSeq_HandleScriptFlowControl(seqPlayer, state, cmd, cmdArg) == 0) {
                continue;
            }
            AudioSeq_SeqLayerDisable(layer);
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
                Audio_SeqLayerNoteDecay(layer);
                break;

            case 0xC3:
                cmdArg = AudioSeq_ScriptReadCompressedU16(state);
                layer->shortNoteDefaultDelay = cmdArg;
                break;

            case 0xC6:
                cmd = AudioSeq_ScriptReadU8(state);
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
                    if ((layer->instOrWave = AudioSeq_GetInstrument(channel, cmd, &layer->instrument, &layer->adsr)) == 0) {
                        layer->instOrWave = 0xFF;
                    }
                }
                break;

            case 0xC7:
                layer->portamento.mode = AudioSeq_ScriptReadU8(state);

                cmd = AudioSeq_ScriptReadU8(state);
                cmd += channel->transposition;
                cmd += layer->transposition;
                cmd += seqPlayer->transposition;

                if (cmd >= 0x80) {
                    cmd = 0;
                }

                layer->portamentoTargetNote = cmd;

                if (PORTAMENTO_IS_SPECIAL(layer->portamento)) {
                    layer->portamentoTime = *(state->pc++);
                    break;
                }

                cmdArg = AudioSeq_ScriptReadCompressedU16(state);
                layer->portamentoTime = cmdArg;
                break;

            case 0xC8:
                layer->portamento.mode = PORTAMENTO_MODE_OFF;
                break;

            case 0xCB:
                cmdArg = AudioSeq_ScriptReadS16(state);
                layer->adsr.envelope = (EnvelopePoint*) (seqPlayer->seqData + (u16) cmdArg);
                /* fallthrough */
            case 0xCF:
                layer->adsr.decayIndex = AudioSeq_ScriptReadU8(state);
                break;

            case 0xCC:
                layer->ignoreDrumPan = true;
                break;

            case 0xCD:
                AudioSeq_ScriptReadU8(state);
                break;

            case 0xCE:
                cmdArg = AudioSeq_ScriptReadU8(state);
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
Drum* Audio_GetDrum(s32 fontId, s32 drumId);

s32 AudioSeq_SeqLayerProcessScriptStep4(SequenceLayer* layer, s32 cmd) {
    s32 sameTunedSample = true;
    s32 instOrWave;
    f32 temp_fa1;
    f32 temp_fv1;
    Portamento* portamento;
    f32 freqScale;
    f32 freqScale2;
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

            drum = Audio_GetDrum(channel->fontId, semitone);
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
            layer->freqScale = tunedSample->tuning;
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

            if (layer->portamento.mode != PORTAMENTO_MODE_OFF) {
                portamento = &layer->portamento;
                vel = (semitone > layer->portamentoTargetNote) ? semitone : layer->portamentoTargetNote;

                if (instrument != NULL) {
                    tunedSample = Audio_GetInstrumentTunedSample(instrument, vel);
                    sameTunedSample = (layer->tunedSample == tunedSample);
                    layer->tunedSample = tunedSample;
                    tuning = tunedSample->tuning;
                } else {
                    layer->tunedSample = NULL;
                    tuning = 1.0f;
                    if (instOrWave >= 0xC0) {
                        layer->tunedSample = &gSynthReverbs[instOrWave - 0xC0].tunedSample;
                    }
                }

                temp_fv1 = gPitchFrequencies[(s32) semitone] * tuning;
                temp_fa1 = gPitchFrequencies[layer->portamentoTargetNote] * tuning;

                switch (PORTAMENTO_MODE(layer->portamento)) {
                    case PORTAMENTO_MODE_1:
                    case PORTAMENTO_MODE_3:
                    case PORTAMENTO_MODE_5:
                        freqScale2 = temp_fv1;
                        freqScale = temp_fa1;
                        break;
                    case PORTAMENTO_MODE_2:
                    case PORTAMENTO_MODE_4:
                        freqScale = temp_fv1;
                        freqScale2 = temp_fa1;
                        break;
                    default:
                        freqScale = temp_fv1;
                        freqScale2 = temp_fv1;
                        break;
                }

                portamento->extent = (freqScale2 / freqScale) - 1.0f;

                if (PORTAMENTO_IS_SPECIAL(layer->portamento)) {
                    portamento->speed = ((s32) seqPlayer->tempo * 32512.0f) /
                                        ((f32) layer->delay * (f32) gMaxTempo * (f32) (s32) layer->portamentoTime);
                } else {
                    portamento->speed = 127.0f / (s32) layer->portamentoTime;
                }

                portamento->cur = 0;
                layer->freqScale = freqScale;
                if (PORTAMENTO_MODE(layer->portamento) == PORTAMENTO_MODE_5) {
                    layer->portamentoTargetNote = semitone;
                }
                break;
            }

            if (instrument != NULL) {
                tunedSample = Audio_GetInstrumentTunedSample(instrument, semitone);
                sameTunedSample = (tunedSample == layer->tunedSample);
                layer->tunedSample = tunedSample;
                layer->freqScale = gPitchFrequencies[(s32) semitone] * tunedSample->tuning;
            } else {
                layer->tunedSample = NULL;
                layer->freqScale = gPitchFrequencies[(s32) semitone];
                if (instOrWave >= 0xC0) {
                    layer->tunedSample = &gSynthReverbs[instOrWave - 0xC0].tunedSample;
                }
            }
            break;
    }

    layer->delay2 = layer->delay;
    layer->freqScale *= layer->bend;

    return sameTunedSample;
}

s32 AudioSeq_SeqLayerProcessScriptStep3(SequenceLayer* layer, s32 cmd) {
    SeqScriptState* state = &layer->state;
    u16 delay;
    s32 velocity;
    SequenceChannel* channel = layer->channel;
    SequencePlayer* seqPlayer = channel->seqPlayer;
    s32 intDelta;
    f32 floatDelta;

    if (cmd == 0xC0) {
        layer->delay = AudioSeq_ScriptReadCompressedU16(state);
        layer->muted = true;
        layer->bit8 = false;
        return -1;
    }

    layer->muted = false;

    switch (cmd & 0xC0) {
        case 0x00:
            delay = AudioSeq_ScriptReadCompressedU16(state);
            velocity = *(state->pc++);
            layer->gateTime = *(state->pc++);
            layer->lastDelay = delay;
            break;

        case 0x40:
            delay = AudioSeq_ScriptReadCompressedU16(state);
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

void AudioSeq_SetChannelPriorities(SequenceChannel* channel, u8 priority) {
    if ((priority & 0xF) != 0) {
        channel->notePriority = priority & 0xF;
    }

    priority = priority >> 4;
    if (priority != 0) {
        channel->notePriority2 = priority;
    }
}

u8 AudioSeq_GetInstrument(SequenceChannel* channel, u8 instId, Instrument** instOut, AdsrSettings* adsr) {
    Instrument* inst = Audio_GetInstrument(channel->fontId, instId);

    if (inst == NULL) {
        *instOut = NULL;
        return 0;
    }

    adsr->envelope = inst->envelope;
    adsr->decayIndex = inst->adsrDecayIndex;
    *instOut = inst;

    return ++instId;
}

void AudioSeq_SetInstrument(SequenceChannel* channel, u8 instId) {
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
        if ((channel->instOrWave = AudioSeq_GetInstrument(channel, instId, &channel->instrument, &channel->adsr)) == 0) {
            channel->hasInstrument = false;
            return;
        }
    }

    channel->hasInstrument = true;
}

void AudioSeq_SequenceChannelSetVolume(SequenceChannel* channel, u8 volume) {
    channel->volume = (s32) volume / 127.0f;
}

extern u8 sSeqInstructionArgsTable[];

void AudioSeq_SequenceChannelProcessScript(SequenceChannel* channel) {
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
        cmd = AudioSeq_ScriptReadU8(scriptState);
        if (cmd >= 0xB0) {
            highBits = sSeqInstructionArgsTable[cmd - 0xB0];
            lowBits = highBits & 3;

            // read in arguments for the instruction
            for (i = 0; i < lowBits; i++, highBits <<= 1) {
                if (!(highBits & 0x80)) {
                    cmdArgs[i] = AudioSeq_ScriptReadU8(scriptState);
                } else {
                    cmdArgs[i] = AudioSeq_ScriptReadS16(scriptState);
                }
            }

            // Control Flow Commands
            if (cmd >= 0xF2) {
                delay = AudioSeq_HandleScriptFlowControl(seqPlayer, scriptState, cmd, cmdArgs[0]);

                if (delay != 0) {
                    if (delay == -1) {
                        AudioSeq_SequenceChannelDisable(channel);
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
                    Audio_NotePoolClear(&channel->notePool);
                    cmd = (u8) cmdArgs[0];
                    Audio_NotePoolFill(&channel->notePool, cmd);
                    break;

                case 0xF0:
                    Audio_NotePoolClear(&channel->notePool);
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

                    if (AudioHeap_SearchCaches(FONT_TABLE, CACHE_EITHER, cmd)) {
                        channel->fontId = cmd;
                    }

                    cmdArgs[0] = cmdArgs[1];
                    /* fallthrough */
                case 0xC1:
                    cmd = (u8) cmdArgs[0];
                    AudioSeq_SetInstrument(channel, cmd);
                    break;

                case 0xC3:
                    channel->largeNotes = false;
                    break;

                case 0xC4:
                    channel->largeNotes = true;
                    break;

                case 0xDF:
                    cmd = (u8) cmdArgs[0];
                    AudioSeq_SequenceChannelSetVolume(channel, cmd);
                    channel->changes.s.volume = true;
                    break;

                case 0xE0:
                    cmd = (u8) cmdArgs[0];
                    channel->volumeScale = (s32) cmd / 128.0f;
                    channel->changes.s.volume = true;
                    break;

                case 0xDE:
                    cmdArgU16 = (u16) cmdArgs[0];
                    channel->freqScale = (s32) cmdArgU16 / 32768.0f;
                    channel->changes.s.freqScale = true;
                    break;

                case 0xD3:
                    cmd = (u8) cmdArgs[0];
                    cmd += 0x80;
                    channel->freqScale = gBendPitchOneOctaveFrequencies[cmd];
                    channel->changes.s.freqScale = true;
                    break;

                case 0xEE:
                    cmd = (u8) cmdArgs[0];
                    cmd += 0x80;
                    channel->freqScale = gBendPitchTwoSemitonesFrequencies[cmd];
                    channel->changes.s.freqScale = true;
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

                    if (AudioHeap_SearchCaches(FONT_TABLE, CACHE_EITHER, cmd)) {
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
                    AudioSeq_SequenceChannelDisable(seqPlayer->channels[cmd]);
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
                    AudioSeq_SetChannelPriorities(channel, *data++);
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
                    AudioSeq_SetChannelPriorities(channel, cmd);
                    channel->transposition = (s8) AudioSeq_ScriptReadU8(scriptState);
                    channel->unkPan = AudioSeq_ScriptReadU8(scriptState);
                    channel->unkPan2 = AudioSeq_ScriptReadU8(scriptState);
                    channel->targetReverbVol = AudioSeq_ScriptReadU8(scriptState);
                    AudioSeq_ScriptReadU8(scriptState);
                    //! @bug: Not marking reverb state as changed
                    channel->changes.s.pan = true;
                    break;
                case 0xEC:
                    channel->adsr.sustain = 0;
                    channel->velocityRandomVariance = 0;
                    channel->gateTimeRandomVariance = 0;
                    channel->freqScale = 1.0f;
                    break;

                case 0xE9:
                    AudioSeq_SetChannelPriorities(channel, (u8) cmdArgs[0]);
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
                    cmdArgU16 = AudioSeq_ScriptReadS16(scriptState);
                    if (!AudioSeq_SeqChannelSetLayer(channel, lowBits)) {
                        channel->layers[lowBits]->state.pc = &seqPlayer->seqData[cmdArgU16];
                    }
                    break;

                case 0x90:
                    AudioSeq_SeqLayerFree(channel, lowBits);
                    break;

                case 0x98:
                    if (scriptState->value != -1 && AudioSeq_SeqChannelSetLayer(channel, lowBits) != -1) {
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
                if (AudioLoad_SlowLoadSample(channel->fontId, scriptState->value, &channel->seqScriptIO[lowBits]) == -1) {}

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
                cmdArgU16 = AudioSeq_ScriptReadS16(scriptState);
                AudioSeq_SequenceChannelEnable(seqPlayer, lowBits, &seqPlayer->seqData[cmdArgU16]);
                break;

            case 0x30:
                cmd = AudioSeq_ScriptReadU8(scriptState);
                seqPlayer->channels[lowBits]->seqScriptIO[cmd] = scriptState->value;
                break;

            case 0x40:
                cmd = AudioSeq_ScriptReadU8(scriptState);
                scriptState->value = seqPlayer->channels[lowBits]->seqScriptIO[cmd];
                break;
        }
    }
exit_loop:

    for (i = 0; i < ARRAY_COUNT(channel->layers); i++) {
        if (channel->layers[i] != NULL) {
            AudioSeq_SeqLayerProcessScript(channel->layers[i]);
        }
    }
}

void AudioSeq_SequencePlayerProcessSequence(SequencePlayer* seqPlayer) {
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

    if (!AudioLoad_IsSeqLoadComplete(seqPlayer->seqId) || !AudioLoad_IsFontLoadComplete(seqPlayer->defaultFont)) {
        AudioSeq_SequencePlayerDisable(seqPlayer);
        return;
    }

    AudioLoad_SetSeqLoadStatus(seqPlayer->seqId, LOAD_STATUS_COMPLETE);
    AudioLoad_SetFontLoadStatus(seqPlayer->defaultFont, LOAD_STATUS_COMPLETE);

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
            cmd = AudioSeq_ScriptReadU8(seqScript);

            if (cmd >= 0xF2) {
                delay = AudioSeq_HandleScriptFlowControl(seqPlayer, seqScript, cmd, AudioSeq_GetScriptControlFlowArgument(&seqPlayer->scriptState, cmd));

                if (delay != 0) {
                    if (delay == -1) {
                        AudioSeq_SequencePlayerDisable(seqPlayer);
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
                        seqPlayer->transposition += (s8) AudioSeq_ScriptReadU8(seqScript);
                        break;

                    case 0xDD:
                        seqPlayer->tempo = AudioSeq_ScriptReadU8(seqScript) * SEQTICKS_PER_BEAT;
                        if (seqPlayer->tempo > gMaxTempo) {
                            seqPlayer->tempo = (u16) gMaxTempo;
                        }

                        if ((s16) seqPlayer->tempo <= 0) {
                            seqPlayer->tempo = 1;
                        }
                        break;

                    case 0xDC:
                        seqPlayer->tempoChange = (s8) AudioSeq_ScriptReadU8(seqScript) * SEQTICKS_PER_BEAT;
                        break;

                    case 0xDA:
                        AudioSeq_ScriptReadU8(seqScript);
                        AudioSeq_ScriptReadS16(seqScript);
                        break;

                    case 0xDB:
                        seqPlayer->fadeVolume = (s32) AudioSeq_ScriptReadU8(seqScript) / 127.0f;
                        break;

                    case 0xD9:
                        seqPlayer->fadeVolumeScale = (s8) AudioSeq_ScriptReadU8(seqScript) / 127.0f;
                        break;

                    case 0xD7:
                        temp = AudioSeq_ScriptReadS16(seqScript);
                        AudioSeq_SequencePlayerSetupChannels(seqPlayer, temp);
                        break;

                    case 0xD6:
                        AudioSeq_ScriptReadS16(seqScript);
                        break;

                    case 0xD5:
                        AudioSeq_ScriptReadU8(seqScript);
                        break;

                    case 0xD3:
                        AudioSeq_ScriptReadU8(seqScript);
                        break;

                    case 0xD0:
                        seqPlayer->noteAllocPolicy = AudioSeq_ScriptReadU8(seqScript);
                        break;

                    case 0xCC:
                        seqScript->value = AudioSeq_ScriptReadU8(seqScript);
                        break;

                    case 0xC9:
                        seqScript->value &= AudioSeq_ScriptReadU8(seqScript);
                        break;

                    case 0xC8:
                        seqScript->value -= AudioSeq_ScriptReadU8(seqScript);
                        break;

                    case 0xC7:
                        cmd = AudioSeq_ScriptReadU8(seqScript);
                        temp = AudioSeq_ScriptReadS16(seqScript);
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
                    AudioSeq_SequenceChannelDisable(seqPlayer->channels[cmdLowBits]);
                    break;

                case 0x90:
                    temp = AudioSeq_ScriptReadS16(seqScript);
                    AudioSeq_SequenceChannelEnable(seqPlayer, cmdLowBits, (void*) &seqPlayer->seqData[temp]);
                    break;
            }
        }
    }

    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
        if (seqPlayer->channels[i]->enabled) {
            AudioSeq_SequenceChannelProcessScript(seqPlayer->channels[i]);
        }
    }
}

void Audio_SequencePlayerProcessSound(SequencePlayer* seqPlayer);

void AudioSeq_ProcessSequences(s32 arg0) {
    SequencePlayer* seqPlayer;
    u32 i;

    for (i = 0; i < (u32) gAudioBufferParams.numSequencePlayers; i++) {
        seqPlayer = &gSeqPlayers[i];
        if (seqPlayer->enabled == true) {
            AudioSeq_SequencePlayerProcessSequence(seqPlayer);
            Audio_SequencePlayerProcessSound(seqPlayer);
        }
    }

    Audio_ProcessNotes();
}

void AudioSeq_SkipForwardSequence(SequencePlayer* seqPlayer) {
    while (seqPlayer->skipTicks > 0) {
        AudioSeq_SequencePlayerProcessSequence(seqPlayer);
        Audio_SequencePlayerProcessSound(seqPlayer);
        seqPlayer->skipTicks--;
    }
}

extern u8 gDefaultShortNoteVelocityTable[];
extern u8 gDefaultShortNoteGateTimeTable[];

void AudioSeq_ResetSequencePlayer(s32 seqPlayerIndex) {
    SequencePlayer* seqPlayer = &gSeqPlayers[seqPlayerIndex];
    s32 i;

    AudioSeq_SequencePlayerDisable(seqPlayer);
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
    seqPlayer->fadeVolumeScale = 1.0f;
    seqPlayer->fadeVelocity = 0.0f;
    seqPlayer->volume = 0.0f;
    seqPlayer->muteVolumeScale = 0.5f;

    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
        AudioSeq_InitSequenceChannel(seqPlayer->channels[i]);
    }
}

void* AudioHeap_AllocZeroed(AudioAllocPool* pool, u32 size);

void AudioSeq_InitSequencePlayerChannels(s32 seqPlayerIndex) {
    SequenceChannel* channel;
    SequencePlayer* seqPlayer = &gSeqPlayers[seqPlayerIndex];
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
        seqPlayer->channels[i] = AudioHeap_AllocZeroed(&gMiscPool, sizeof(SequenceChannel));
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
        AudioSeq_InitSequenceChannel(seqPlayer->channels[i]);
    }
}

void AudioSeq_InitSequencePlayers(void) {
    SequencePlayer* seqPlayer;
    s32 i;
    s32 j;

    AudioSeq_InitLayerFreelist();

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

        Audio_InitNoteLists(&seqPlayer->notePool);
        AudioSeq_ResetSequencePlayer(i);
    }
}
