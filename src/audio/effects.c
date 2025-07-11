#include "global.h"
#include "audio.h"

static char D_800D0840[] = "Audio:Envp: overflow  %f\n";

void Audio_SequenceChannelProcessSound(SequenceChannel* channel, bool updateVolume) {
    s32 i;

    if (channel->changes.s.volume || updateVolume) {
        f32 channelVolume = channel->volume * channel->volumeScale * channel->seqPlayer->appliedFadeVolume;

        channel->appliedVolume = SQ(channelVolume);
    }
    if (channel->changes.s.pan) {
        channel->pan = channel->unkPan;
    }
    for (i = 0; i < ARRAY_COUNT(channel->layers); i++) {
        SequenceLayer* layer = channel->layers[i];

        if ((layer != NULL) && layer->enabled && (layer->note != NULL)) {
            if (layer->notePropertiesNeedInit) {
                layer->noteFreqScale = layer->freqScale * channel->freqScale;
                layer->noteVelocity = layer->velocitySquare * channel->appliedVolume;
                if (channel->unkPan2 == 0) {
                    layer->notePan = layer->pan;
                } else {
                    layer->notePan = channel->pan;
                }
                layer->notePropertiesNeedInit = false;
            } else {
                if (channel->changes.s.freqScale) {
                    layer->noteFreqScale = layer->freqScale * channel->freqScale;
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

void Audio_SequencePlayerProcessSound(SequencePlayer* seqPlayer) {
    s32 i;

    if (seqPlayer->recalculateVolume) {
        seqPlayer->appliedFadeVolume = seqPlayer->fadeVolume * seqPlayer->fadeVolumeScale;
    }

    for (i = 0; i < 16; i++) {
        if (seqPlayer->channels[i]->enabled == 1) {
            Audio_SequenceChannelProcessSound(seqPlayer->channels[i], seqPlayer->recalculateVolume);
        }
    }

    seqPlayer->recalculateVolume = false;
}

f32 Audio_GetPortamentoFreqScale(Portamento* portamento) {
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

void Audio_NotePortamentoUpdate(Note* note) {
    if (note->playbackState.portamento.mode != 0) {
        note->playbackState.portamentoFreqScale = Audio_GetPortamentoFreqScale(&note->playbackState.portamento);
    }
}

void Audio_NotePortamentoInit(Note* note) {
    NotePlaybackState* noteState = &note->playbackState;

    noteState->portamentoFreqScale = 1.0f;

    noteState->portamento = noteState->parentLayer->portamento;
}

void Audio_AdsrInit(AdsrState* adsr, EnvelopePoint* envelope, s16* arg2) {
    adsr->action.asByte = 0;
    adsr->state = 0;
    adsr->delay = 0;
    adsr->envelope = envelope;
    adsr->sustain = 0.0f;
    adsr->current = 0.0f;
}

f32 Audio_AdsrUpdate(AdsrState* adsr) {
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
                    adsr->delay *= gAudioBufferParams.ticksPerUpdateScaled;

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
