#include "global.h"
#include "audio.h"
#include "audiothread_cmd.h"
#include "fzxthread.h"

void AudioThread_ProcessCmds(u32 msg);
void AudioThread_ProcessSeqPlayerCmd(SequenceChannel* channel, AudioCmd* cmd);

static char devstr0[] = "DAC:Lost 1 Frame.\n";
static char devstr1[] = "Address Error %x\n";
static char devstr2[] = "DMA: Request queue over.( %d )\n";
static char devstr3[] = "Audio:now-max tasklen is %d / %d\n";
static char devstr4[] = "Audio:Warning:ABI Tasklist length over (%d)\n";

AudioTask* AudioThread_CreateTask(void) {
    static s32 gMaxAbiCmdCnt = 128;
    static AudioTask* gWaitingAudioTask = NULL;
    u32 aiSamplesLeft;
    s32 abiCmdCount;
    s32 aiBufIndex;
    s32 pad48;
    OSTask_t* task;
    s16* aiBuffer;
    s32 pad3C;
    u32 specId;
    u32 msg;
    s32 pad30;
    s32 i;

    gTotalTaskCount++;

    osSendMesg(gAudioTaskStartQueuePtr, (OSMesg) gTotalTaskCount, OS_MESG_NOBLOCK);
    gRspTaskIndex ^= 1;
    gCurAiBufIndex++;
    gCurAiBufIndex %= 3;

    aiBufIndex = (gCurAiBufIndex + 1) % 3;
    aiSamplesLeft = osAiGetLength() / 4;

    if (gResetTimer < 16) {
        if (gAiBufLengths[aiBufIndex] != 0) {
            osAiSetNextBuffer(gAiBuffers[aiBufIndex], gAiBufLengths[aiBufIndex] * 4);
            if (gAiBuffers[aiBufIndex]) {}
            if (gAiBufLengths[aiBufIndex]) {}
        }
    }

    if (gCurAudioFrameDmaCount && gCurAudioFrameDmaCount) {}

    gCurAudioFrameDmaCount = 0;

    AudioLoad_DecreaseSampleDmaTtls();
    AudioLoad_ProcessLoads(gResetStatus);

    if (gResetStatus != 0 && !AudioHeap_ResetStep()) {
        if (gResetStatus == 0) {
            osSendMesg(gAudioResetQueuePtr, (OSMesg) (s32) gSpecId, OS_MESG_NOBLOCK);
        }
        gWaitingAudioTask = NULL;
        return NULL;
    }
    if (gResetTimer > 16) {
        return NULL;
    }
    if (gResetTimer != 0) {
        gResetTimer++;
    }
    gCurTask = &gRspTask[gRspTaskIndex];
    gCurAbiCmdBuffer = gAbiCmdBuffs[gRspTaskIndex];
    aiBufIndex = gCurAiBufIndex;
    aiBuffer = gAiBuffers[aiBufIndex];
    gAiBufLengths[aiBufIndex] = ((gAudioBufferParams.samplesPerFrameTarget - aiSamplesLeft + 0x80) & 0xFFF0) + 0x10;

    if (gAiBufLengths[aiBufIndex] < gAudioBufferParams.minAiBufferLength) {
        gAiBufLengths[aiBufIndex] = gAudioBufferParams.minAiBufferLength;
    }
    if (gAiBufLengths[aiBufIndex] > gAudioBufferParams.maxAiBufferLength) {
        gAiBufLengths[aiBufIndex] = gAudioBufferParams.maxAiBufferLength;
    }

    i = 0;
    if (gResetStatus == 0) {
        while (MQ_GET_MESG(gThreadCmdProcQueuePtr, &msg)) {
            AudioThread_ProcessCmds(msg);
            i++;
        }
        if (i == 0 && gThreadCmdQueueFinished) {
            AudioThread_ScheduleProcessCmds();
        }
    }
    gCurAbiCmdBuffer = AudioSynth_Update(gCurAbiCmdBuffer, &abiCmdCount, aiBuffer, gAiBufLengths[aiBufIndex]);
    gAudioRandom = osGetCount() * (gAudioRandom + gTotalTaskCount);
    gAudioRandom = gAiBuffers[aiBufIndex][gTotalTaskCount & 0xFF] + gAudioRandom;

    aiBufIndex = gRspTaskIndex;

    gCurTask->msgQueue = NULL;
    gCurTask->msg = NULL;

    task = &gCurTask->task.t;

    task->type = 2;
    task->flags = 0;
    task->ucode_boot = (u64*) aspMainTextStart;
    task->ucode_boot_size = SP_UCODE_SIZE;

    task->ucode_data_size = (size_t) (aspMainDataEnd - aspMainDataStart) * sizeof(u64) - 1;
    task->ucode = (u64*) aspMainTextStart;
    task->ucode_data = (u64*) aspMainDataStart;
    task->ucode_size = SP_UCODE_SIZE;

    task->dram_stack = NULL;
    task->dram_stack_size = 0;

    task->output_buff = NULL;
    task->output_buff_size = NULL;
    if (1) {}
    task->data_ptr = (u64*) gAbiCmdBuffs[aiBufIndex];
    task->data_size = abiCmdCount * sizeof(Acmd);

    task->yield_data_ptr = NULL;
    task->yield_data_size = 0;

    if (gMaxAbiCmdCnt < abiCmdCount) {
        gMaxAbiCmdCnt = abiCmdCount;
    }

    return gCurTask;
}

static char devstr5[] = "BGLOAD Start %d\n";
static char devstr6[] = "Error: OverFlow Your Request\n";
static char devstr7[] = "---AudioSending (%d->%d) \n";
static char devstr8[] = "AudioSend: %d -> %d (%d)\n";
static char devstr9[] = "Warning: MesgQ is Full, Retry Next Send.\n";
static char devstr10[] = "Next Start %d \n";

void AudioThread_SetFadeOutTimer(s32 seqPlayId, s32 fadeTime);
void AudioThread_SetFadeInTimer(s32 seqPlayId, s32 fadeTime);

void AudioThread_ProcessGlobalCmd(AudioCmd* cmd) {
    s32 i;

    switch (cmd->op) {
        case AUDIOCMD_OP_GLOBAL_SYNC_LOAD_SEQ_PARTS:
            AudioLoad_SyncLoadSeqParts(cmd->arg1, 3);
            break;
        case AUDIOCMD_OP_GLOBAL_INIT_SEQPLAYER:
        case AUDIOCMD_OP_GLOBAL_INIT_SEQPLAYER_ALT:
            AudioLoad_SyncInitSeqPlayer(cmd->arg0, cmd->arg1, cmd->arg2);
            AudioThread_SetFadeInTimer(cmd->arg0, cmd->data);
            break;
        case AUDIOCMD_OP_GLOBAL_INIT_SEQPLAYER_SKIP_TICKS:
            AudioLoad_SyncInitSeqPlayerSkipTicks(cmd->arg0, cmd->arg1, cmd->data);
            break;
        case AUDIOCMD_OP_GLOBAL_DISABLE_SEQPLAYER:
            if (gSeqPlayers[cmd->arg0].enabled) {
                if (cmd->asInt == 0) {
                    AudioSeq_SequencePlayerDisable(&gSeqPlayers[cmd->arg0]);
                } else {
                    AudioThread_SetFadeOutTimer(cmd->arg0, cmd->asInt);
                }
            }
            break;
        case AUDIOCMD_OP_GLOBAL_SET_SOUND_MODE:
            gSoundMode = cmd->asUInt;
            break;
        case AUDIOCMD_OP_GLOBAL_MUTE:
            for (i = 0; i < gAudioBufferParams.numSequencePlayers; i++) {
                SequencePlayer* seqPlayer = &gSeqPlayers[i];

                seqPlayer->muted = true;
                seqPlayer->recalculateVolume = true;
            }
            break;
        case AUDIOCMD_OP_GLOBAL_UNMUTE:
            if (cmd->asUInt == 1) {
                for (i = 0; i < gNumNotes; i++) {
                    Note* note = &gNotes[i];
                    NoteSubEu* noteSub = &note->noteSubEu;

                    if ((noteSub->bitField.enabled) && (note->playbackState.unk_04 == 0) &&
                        (note->playbackState.parentLayer->channel->muteBehavior & 8)) {
                        noteSub->bitField.finished = true;
                    }
                }
            }
            for (i = 0; i < gAudioBufferParams.numSequencePlayers; i++) {
                SequencePlayer* seqPlayer = &gSeqPlayers[i];

                seqPlayer->muted = false;
                seqPlayer->recalculateVolume = true;
            }
            break;
        case AUDIOCMD_OP_GLOBAL_SYNC_LOAD_INSTRUMENT:
            AudioLoad_SyncLoadInstrument(cmd->arg0, cmd->arg1, cmd->arg2);
            break;
        case AUDIOCMD_OP_GLOBAL_ASYNC_LOAD_SAMPLE_BANK:
            AudioLoad_AsyncLoadSampleBank(cmd->arg0, cmd->arg1, cmd->arg2, &gExternalLoadQueue);
            break;
        case AUDIOCMD_OP_GLOBAL_ASYNC_LOAD_FONT:
            AudioLoad_AsyncLoadSeq(cmd->arg0, cmd->arg1, cmd->arg2, &gExternalLoadQueue);
            break;
        case AUDIOCMD_OP_GLOBAL_DISCARD_SEQ_FONTS:
            AudioLoad_DiscardSeqFonts(cmd->arg1);
            break;
        case AUDIOCMD_OP_GLOBAL_SET_CHANNEL_MASK:
            gThreadCmdChannelMask[cmd->arg0] = cmd->asUShort;
            break;
        case AUDIOCMD_OP_GLOBAL_RESET_AUDIO_HEAP:
            gResetStatus = 5;
            gSpecId = cmd->asUInt;
            break;
        default:
            break;
    }
}

void AudioThread_SetFadeOutTimer(s32 seqPlayId, s32 fadeTime) {
    if (fadeTime == 0) {
        fadeTime = 1;
    }

    gSeqPlayers[seqPlayId].state = 2;
    gSeqPlayers[seqPlayId].fadeTimer = fadeTime;
    gSeqPlayers[seqPlayId].fadeVelocity = -(gSeqPlayers[seqPlayId].fadeVolume / fadeTime);
}

void AudioThread_SetFadeInTimer(s32 seqPlayId, s32 fadeTime) {
    if (fadeTime != 0) {
        gSeqPlayers[seqPlayId].state = 1;
        gSeqPlayers[seqPlayId].fadeTimerUnkEu = fadeTime;
        gSeqPlayers[seqPlayId].fadeTimer = fadeTime;
        gSeqPlayers[seqPlayId].fadeVolume = 0.0f;
        gSeqPlayers[seqPlayId].fadeVelocity = 0.0f;
    }
}

void AudioThread_InitQueues(void) {
    gThreadCmdWritePos = 0;
    gThreadCmdReadPos = 0;
    gThreadCmdQueueFinished = false;

    gAudioTaskStartQueuePtr = &gAudioTaskStartQueue;
    gThreadCmdProcQueuePtr = &gThreadCmdProcQueue;
    gAudioResetQueuePtr = &gAudioResetQueue;
    osCreateMesgQueue(gAudioTaskStartQueuePtr, gAudioTaskStartMsg, 1);
    osCreateMesgQueue(gThreadCmdProcQueuePtr, gThreadCmdProcMsg, 4);
    osCreateMesgQueue(gAudioResetQueuePtr, gAudioResetMsg, 1);
}

void AudioThread_QueueCmd(u32 opArgs, void** data) {
    AudioCmd* audioCmd = &gThreadCmdBuffer[gThreadCmdWritePos & 0xFF];

    audioCmd->opArgs = opArgs;
    audioCmd->data = *data;

    gThreadCmdWritePos++;
    if (gThreadCmdWritePos == gThreadCmdReadPos) {
        gThreadCmdWritePos--;
    }
}

void AudioThread_QueueCmdF32(u32 opArgs, f32 data) {
    AudioThread_QueueCmd(opArgs, (void**) &data);
}

void AudioThread_QueueCmdU32(u32 opArgs, u32 data) {
    AudioThread_QueueCmd(opArgs, (void**) &data);
}

void AudioThread_QueueCmdS8(u32 opArgs, s8 data) {
    u32 uData = data << 0x18;

    AudioThread_QueueCmd(opArgs, (void**) &uData);
}

void AudioThread_QueueCmdU16(u32 opArgs, u16 data) {
    u32 uData = data << 0x10;

    AudioThread_QueueCmd(opArgs, (void**) &uData);
}

void AudioThread_ScheduleProcessCmds(void) {
    static s32 D_800D185C = 0;
    OSMesg msg;

    if (D_800D185C < (((gThreadCmdWritePos - gThreadCmdReadPos) + 0x100) & 0xFF)) {
        D_800D185C = (((gThreadCmdWritePos - gThreadCmdReadPos) + 0x100) & 0xFF);
    }

    msg = ((gThreadCmdReadPos & 0xFF) << 8) | (gThreadCmdWritePos & 0xFF);

    if (osSendMesg(gThreadCmdProcQueuePtr, msg, OS_MESG_NOBLOCK) != -1) {
        gThreadCmdReadPos = gThreadCmdWritePos;
    }
}

static char devstr11[] = "Continue Port\n";
static char devstr12[] = "%d -> %d\n";
static char devstr13[] = "Sync-Frame  Break. (Remain %d [%d,%d])\n";

void AudioThread_ResetCmdQueue(void) {
    gThreadCmdReadPos = gThreadCmdWritePos;
    gThreadCmdQueueFinished = false;
}

void AudioThread_ProcessCmds(u32 msg) {
    static u8 gCurCmdReadPos = 0;
    AudioCmd* cmd;
    SequenceChannel* channel;
    SequencePlayer* seqPlayer;
    f32 fadeVolume;
    s32 i;
    u16 threadCmdChannelMask;
    u8 writePos;

    if (!gThreadCmdQueueFinished) {
        gCurCmdReadPos = (msg >> 8) & 0xFF;
    }
    writePos = msg & 0xFF;
    while (true) {
        if (gCurCmdReadPos == writePos) {
            gThreadCmdQueueFinished = false;
            break;
        }
        cmd = &gThreadCmdBuffer[gCurCmdReadPos & 0xFF];
        gCurCmdReadPos++;
        if (cmd->op == AUDIOCMD_OP_GLOBAL_STOP_AUDIOCMDS) {
            gThreadCmdQueueFinished = true;
            break;
        }
        if ((cmd->op & 0xF0) == 0xF0) {
            AudioThread_ProcessGlobalCmd(cmd);
        } else if (cmd->arg0 < gAudioBufferParams.numSequencePlayers) {
            seqPlayer = &gSeqPlayers[cmd->arg0];
            if (cmd->op & 0x80) {
                AudioThread_ProcessGlobalCmd(cmd);
            } else if (cmd->op & 0x40) {
                switch (cmd->op) {
                    case AUDIOCMD_OP_SEQPLAYER_FADE_VOLUME_SCALE:
                        if (seqPlayer->fadeVolumeScale != cmd->asFloat) {
                            seqPlayer->fadeVolumeScale = cmd->asFloat;
                            seqPlayer->recalculateVolume = true;
                        }
                        break;
                    case AUDIOCMD_OP_SEQPLAYER_SET_TEMPO:
                        seqPlayer->tempo = cmd->asInt * 48;
                        break;
                    case AUDIOCMD_OP_SEQPLAYER_CHANGE_TEMPO:
                        seqPlayer->tempoChange = cmd->asInt * 48;
                        break;
                    case AUDIOCMD_OP_SEQPLAYER_SET_TRANSPOSITION:
                        seqPlayer->transposition = cmd->asSbyte;
                        break;
                    case AUDIOCMD_OP_SEQPLAYER_SET_IO:
                        seqPlayer->seqScriptIO[cmd->arg2] = cmd->asSbyte;
                        break;
                    case AUDIOCMD_OP_SEQPLAYER_FADE_TO_SET_VOLUME:
                        fadeVolume = (s32) cmd->arg1 / 127.0f;
                        goto apply_fade;

                    case AUDIOCMD_OP_SEQPLAYER_FADE_TO_SCALED_VOLUME:
                        fadeVolume = ((s32) cmd->arg1 / 100.0f) * seqPlayer->fadeVolume;
                    apply_fade:
                        if (seqPlayer->state != 2) {
                            seqPlayer->volume = seqPlayer->fadeVolume;
                            if (cmd->asInt == 0) {
                                seqPlayer->fadeVolume = fadeVolume;
                            } else {
                                s32 fadeTimer = cmd->asInt;

                                seqPlayer->state = 0;
                                seqPlayer->fadeTimer = fadeTimer;
                                seqPlayer->fadeVelocity = (fadeVolume - seqPlayer->fadeVolume) / fadeTimer;
                            }
                        }
                        break;
                    case AUDIOCMD_OP_SEQPLAYER_RESET_VOLUME:
                        if (seqPlayer->state != 2) {
                            if (cmd->asInt == 0) {
                                seqPlayer->fadeVolume = seqPlayer->volume;
                            } else {
                                s32 fadeTimer = cmd->asInt;

                                seqPlayer->state = 0;
                                seqPlayer->fadeTimer = fadeTimer;
                                seqPlayer->fadeVelocity = (seqPlayer->volume - seqPlayer->fadeVolume) / fadeTimer;
                            }
                        }
                        break;
                }
            } else if (seqPlayer->enabled) {
                if (cmd->arg1 < 16) {
                    AudioThread_ProcessSeqPlayerCmd(seqPlayer->channels[cmd->arg1], cmd);
                } else if (cmd->arg1 == 0xFF) {
                    threadCmdChannelMask = gThreadCmdChannelMask[cmd->arg0];
                    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
                        if (threadCmdChannelMask & 1) {
                            AudioThread_ProcessSeqPlayerCmd(seqPlayer->channels[i], cmd);
                        }
                        threadCmdChannelMask = threadCmdChannelMask >> 1;
                    }
                }
            }
        }
        cmd->op = 0;
    }
}

static char devstr14[] = "specchg conjunction error (Msg:%d Cur:%d)\n";
static char devstr15[] = "Warning : Queue is not empty,drop this (number %d ) \n";
static char devstr16[] = "Warning: SpecChange is processing now[number %d]\n";
static char devstr17[] = "Same SpecChange...  Cancel.\n";
static char devstr18[] = "Overwrite SpecNumber.[->%d]\n";
static char devstr19[] = "Coherency safety wait..\n";
static char devstr20[] = "Normal SpecChange [num %d]\n";
static char devstr21[] = "Undefined Port Command %d\n";

u32 AudioThread_GetAsyncLoadStatus(u32* outData) {
    u32 loadStatus;

    if (!MQ_GET_MESG(&gExternalLoadQueue, &loadStatus)) {
        *outData = 0;
        return 0;
    }
    *outData = loadStatus & 0xFFFFFF;
    return loadStatus >> 0x18;
}

u8* AudioThread_GetFontsForSequence(s32 seqId, u32* outNumFonts) {
    return AudioLoad_GetFontsForSequence(seqId, outNumFonts);
}

bool AudioThread_ResetComplete(void) {
    s32 pad;
    s32 specId;

    if (!MQ_GET_MESG(gAudioResetQueuePtr, &specId)) {
        return false;
    }
    if (specId != gSpecId) {
        return false;
    }
    return true;
}

void AudioThread_ClearResetQueue(void) {
    MQ_CLEAR_QUEUE(gAudioResetQueuePtr);
}

s32 AudioThread_ResetAudioHeap(s32 specId) {
    s32 resetStatus;
    OSMesg msg;

    AudioThread_ClearResetQueue();
    resetStatus = gResetStatus;
    if (resetStatus != 0) {
        AudioThread_ResetCmdQueue();
        if (gSpecId == specId) {
            return 0;
        } else if (resetStatus > 2) {
            return 0;
        } else {
            MQ_WAIT_FOR_MESG(gAudioResetQueuePtr, &msg);
        }
    }

    AudioThread_ClearResetQueue();
    AUDIOCMD_GLOBAL_RESET_AUDIO_HEAP(specId);

    AudioThread_ScheduleProcessCmds();
}

void AudioThread_PreNMIInternal(void) {
    gResetTimer = 1;
    if (gAudioContextInitialized) {
        AudioThread_ResetAudioHeap(0);
        gResetStatus = 0;
    }
}

s8 AudioThread_GetChannelIO(s32 seqPlayerIndex, s32 channelIndex, s32 ioPort) {
    SequencePlayer* seqPlayer = &gSeqPlayers[seqPlayerIndex];
    SequenceChannel* channel;

    if (seqPlayer->enabled) {
        channel = seqPlayer->channels[channelIndex];
        return channel->seqScriptIO[ioPort];
    } else {
        return SEQ_IO_VAL_NONE;
    }
}

s8 AudioThread_GetSeqPlayerIO(s32 seqPlayerIndex, s32 ioPort) {
    return gSeqPlayers[seqPlayerIndex].seqScriptIO[ioPort];
}

void AudioThread_InitExternalPool(void* ramAddr, size_t size) {
    AudioHeap_InitPool(&gExternalPool, ramAddr, size);
}

void AudioThread_ResetExternalPool(void) {
    gExternalPool.startRamAddr = NULL;
}

void AudioThread_ProcessSeqPlayerCmd(SequenceChannel* channel, AudioCmd* cmd) {
    switch (cmd->op) {
        case AUDIOCMD_OP_CHANNEL_SET_VOL_SCALE:
            if (channel->volumeScale != cmd->asFloat) {
                channel->volumeScale = cmd->asFloat;
                channel->changes.s.volume = true;
            }
            break;

        case AUDIOCMD_OP_CHANNEL_SET_VOL:
            if (channel->volume != cmd->asFloat) {
                channel->volume = cmd->asFloat;
                channel->changes.s.volume = true;
            }
            break;

        case AUDIOCMD_OP_CHANNEL_SET_PAN:
            if (channel->unkPan != cmd->asSbyte) {
                channel->unkPan = cmd->asSbyte;
                channel->changes.s.pan = true;
            }
            break;

        case AUDIOCMD_OP_CHANNEL_SET_FREQ_SCALE:
            if (channel->freqScale != cmd->asFloat) {
                channel->freqScale = cmd->asFloat;
                channel->changes.s.freqScale = true;
            }
            break;

        case AUDIOCMD_OP_CHANNEL_SET_REVERB_VOLUME:
            if (channel->targetReverbVol != cmd->asSbyte) {
                channel->targetReverbVol = cmd->asSbyte;
            }
            break;

        case AUDIOCMD_OP_CHANNEL_SET_IO:
            if (cmd->arg2 < ARRAY_COUNT(channel->seqScriptIO)) {
                channel->seqScriptIO[cmd->arg2] = cmd->asSbyte;
            }
            break;

        case AUDIOCMD_OP_CHANNEL_SET_MUTE:
            channel->muted = cmd->asSbyte;
            break;

        case AUDIOCMD_OP_CHANNEL_SET_MUTE_BEHAVIOR:
            channel->muteBehavior = cmd->asSbyte;
            break;

        default:
            break;
    }
}

void AudioThread_InitMesgQueues(void) {
    AudioThread_InitQueues();
}
