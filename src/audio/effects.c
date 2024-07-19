#include "global.h"
#include "audio.h"

void func_800AB9A0(SequenceChannel* channel, s32 updateVolume) {
    s32 i;

    if (channel->changes.s.volume || updateVolume) {
        f32 channelVolume = channel->volume * channel->volumeMod * channel->seqPlayer->appliedFadeVolume;

        channel->appliedVolume = SQ(channelVolume);
    }
    if (channel->changes.s.pan) {
        channel->pan = channel->unkPan;
    }
    for (i = 0; i < ARRAY_COUNT(channel->layers); i++) {
        SequenceLayer* layer = channel->layers[i];

        if ((layer != NULL) && layer->enabled && (layer->note != NULL)) {
            if (layer->notePropertiesNeedInit) {
                layer->noteFreqMod = layer->freqMod * channel->freqMod;
                layer->noteVelocity = layer->velocitySquare * channel->appliedVolume;
                if (channel->unkPan2 == 0) {
                    layer->notePan = layer->pan;
                } else {
                    layer->notePan = channel->pan;
                }
                layer->notePropertiesNeedInit = false;
            } else {
                if (channel->changes.s.freqMod) {
                    layer->noteFreqMod = layer->freqMod * channel->freqMod;
                }
                if (channel->changes.s.volume || updateVolume) {
                    layer->noteVelocity = layer->velocitySquare * channel->appliedVolume;
                }
                if (channel->changes.s.pan && channel->unkPan2 != 0) {
                    layer->notePan = channel->pan;
                }
            }
        }
    }
    channel->changes.asByte = 0;
}

void func_800ABAFC(SequencePlayer* seqPlayer) {
    s32 i;

    if (seqPlayer->recalculateVolume) {
        seqPlayer->appliedFadeVolume = seqPlayer->fadeVolume * seqPlayer->fadeVolumeMod;
    }

    for (i = 0; i < 16; i++) {
        if (seqPlayer->channels[i]->enabled == 1) {
            func_800AB9A0(seqPlayer->channels[i], seqPlayer->recalculateVolume);
        }
    }

    seqPlayer->recalculateVolume = false;
}

f32 func_800ABBA4(Portamento* portamento) {
    u32 loResCur;
    f32 portamentoFreq;

    portamento->cur += portamento->speed;
    loResCur = portamento->cur;

    if (loResCur > 127) {
        loResCur = 127;
    }

    portamentoFreq = 1.0f + portamento->extent * (gBendPitchOneOctaveFrequencies[loResCur + 128] - 1.0f);

    return portamentoFreq;
}

void func_800ABC78(Note* note) {
    if (note->playbackState.portamento.mode != 0) {
        note->playbackState.portamentoFreqMod = func_800ABBA4(&note->playbackState.portamento);
    }
}

void func_800ABCB4(Note* note) {
    NotePlaybackState* noteState = &note->playbackState;

    noteState->portamentoFreqMod = 1.0f;

    noteState->portamento = noteState->parentLayer->portamento;
}

void func_800ABCE8(AdsrState* adsr, EnvelopePoint* envelope, s16* arg2) {
    adsr->action.asByte = 0;
    adsr->state = 0;
    adsr->delay = 0;
    adsr->envelope = envelope;
    adsr->sustain = 0.0f;
    adsr->current = 0.0f;
}

extern f32 D_8002AA44;

f32 func_800ABD0C(AdsrState* adsr) {
    u8 action = adsr->action.asByte;
    u8 state = adsr->state;

    switch (state) {
        case ADSR_STATE_DISABLED:
            return 0.0f;
        case ADSR_STATE_INITIAL:
            if (action & 0x40) {
                adsr->state = ADSR_STATE_HANG;
                break;
            }
        case ADSR_STATE_START_LOOP:
            adsr->envIndex = 0;
            adsr->state = ADSR_STATE_LOOP;
        case_ADSR_STATE_LOOP:
        case ADSR_STATE_LOOP:
            adsr->delay = adsr->envelope[adsr->envIndex].delay;
            switch (adsr->delay) {
                case ADSR_DISABLE:
                    adsr->state = ADSR_STATE_DISABLED;
                    break;
                case ADSR_HANG:
                    adsr->state = ADSR_STATE_HANG;
                    break;
                case ADSR_GOTO:
                    adsr->envIndex = adsr->envelope[adsr->envIndex].arg;
                    goto case_ADSR_STATE_LOOP;
                case ADSR_RESTART:
                    adsr->state = ADSR_STATE_INITIAL;
                    break;
                default:
                    adsr->delay *= D_8002AA44;

                    if (adsr->delay == 0) {
                        adsr->delay = 1;
                    }

                    adsr->target = adsr->envelope[adsr->envIndex].arg / 32767.0f;
                    adsr->target = SQ(adsr->target);
                    adsr->velocity = (adsr->target - adsr->current) / adsr->delay;
                    adsr->state = ADSR_STATE_FADE;
                    adsr->envIndex++;
                    break;
            }
            if (adsr->state != ADSR_STATE_FADE) {
                break;
            }
        case ADSR_STATE_FADE:
            adsr->delay--;
            adsr->current += adsr->velocity;
            if (adsr->delay <= 0) {
                adsr->state = ADSR_STATE_LOOP;
            }
            break;
        case ADSR_STATE_DECAY:
        case ADSR_STATE_RELEASE:
            adsr->current -= adsr->fadeOutVel;
            if ((adsr->sustain != 0.0f) && (state == ADSR_STATE_DECAY)) {
                if (adsr->current < adsr->sustain) {
                    adsr->current = adsr->sustain;
                    adsr->delay = 0x80;
                    adsr->state = ADSR_STATE_SUSTAIN;
                }
            } else if (adsr->current < 0.00001f) {
                adsr->current = 0.0f;
                adsr->state = ADSR_STATE_DISABLED;
            }
            break;
        case ADSR_STATE_SUSTAIN:
            adsr->delay--;
            if (adsr->delay == 0) {
                adsr->state = ADSR_STATE_RELEASE;
            }
            break;
    }
    if (action & 0x20) {
        adsr->state = ADSR_STATE_DECAY;
        adsr->action.asByte = action & ~0x20;
    }
    if (action & 0x10) {
        adsr->state = ADSR_STATE_RELEASE;
        adsr->action.asByte = action & ~0x10;
    }
    if (adsr->current < 0.0f) {
        return 0.0f;
    }
    if (adsr->current > 1.0f) {
        return 1.0f;
    }
    return adsr->current;
}
