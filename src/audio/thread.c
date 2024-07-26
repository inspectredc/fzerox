#include "global.h"
#include "audio.h"
#include "audiothread_cmd.h"
#include "fzxthread.h"

extern AudioTask* gAudioCurTask;
extern AudioTask gAudioRspTasks[2];
extern Acmd* gCurAbiCmdBuffer;
extern volatile s32 gAudioTaskCountQ;
extern s32 gAudioTaskIndexQ;

extern OSMesg sAudioTaskStartMsg[1];
extern OSMesg sThreadCmdProcMsg[4];
extern OSMesg sAudioResetMsg[1];

extern OSMesgQueue sAudioTaskStartQueue;
extern OSMesgQueue sThreadCmdProcQueue;
extern OSMesgQueue sAudioResetQueue;

extern OSMesgQueue* gAudioTaskStartQueue;
extern OSMesgQueue* gThreadCmdProcQueue;
extern OSMesgQueue* gAudioResetQueue;

extern AudioCmd gThreadCmdBuffer[256];

extern u8 gThreadCmdWritePos;
extern u8 gThreadCmdReadPos;
extern u8 gThreadCmdQueueFinished;

void func_800B6994(void);
void func_800B6A34(u32 msg);
void func_800B706C(SequenceChannel* channel, AudioCmd* cmd);

static char devstr0[] = "DAC:Lost 1 Frame.\n";
static char devstr1[] = "Address Error %x\n";
static char devstr2[] = "DMA: Request queue over.( %d )\n";
static char devstr3[] = "Audio:now-max tasklen is %d / %d\n";
static char devstr4[] = "Audio:Warning:ABI Tasklist length over (%d)\n";

AudioTask* func_800B5FB0(void) {
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

    gAudioTaskCountQ++;

    osSendMesg(gAudioTaskStartQueue, (OSMesg) gAudioTaskCountQ, OS_MESG_NOBLOCK);
    gAudioTaskIndexQ ^= 1;
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

    func_800AEA10();
    func_800B0754(gResetStatus);

    if (gResetStatus != 0 && !func_800B38AC()) {
        if (gResetStatus == 0) {
            osSendMesg(gAudioResetQueue, (OSMesg) (s32) gSpecId, OS_MESG_NOBLOCK);
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
    gAudioCurTask = &gAudioRspTasks[gAudioTaskIndexQ];
    gCurAbiCmdBuffer = gAbiCmdBuffs[gAudioTaskIndexQ];
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
        while (MQ_GET_MESG(gThreadCmdProcQueue, &msg)) {
            func_800B6A34(msg);
            i++;
        }
        if (i == 0 && gThreadCmdQueueFinished) {
            func_800B6994();
        }
    }
    gCurAbiCmdBuffer = func_800B4F4C(gCurAbiCmdBuffer, &abiCmdCount, aiBuffer, gAiBufLengths[aiBufIndex]);
    gAudioRandom = osGetCount() * (gAudioRandom + gAudioTaskCountQ);
    gAudioRandom = gAiBuffers[aiBufIndex][gAudioTaskCountQ & 0xFF] + gAudioRandom;

    aiBufIndex = gAudioTaskIndexQ;

    gAudioCurTask->msgQueue = NULL;
    gAudioCurTask->msg = NULL;

    task = &gAudioCurTask->task.t;

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

    return gAudioCurTask;
}

static char devstr5[] = "BGLOAD Start %d\n";
static char devstr6[] = "Error: OverFlow Your Request\n";
static char devstr7[] = "---AudioSending (%d->%d) \n";
static char devstr8[] = "AudioSend: %d -> %d (%d)\n";
static char devstr9[] = "Warning: MesgQ is Full, Retry Next Send.\n";
static char devstr10[] = "Next Start %d \n";

void func_800B6744(s32 seqPlayId, s32 fadeTime);
void func_800B679C(s32 seqPlayId, s32 fadeTime);

void func_800B641C(AudioCmd* cmd) {
    s32 i;

    switch (cmd->op) {
        case AUDIOCMD_OP_GLOBAL_SYNC_LOAD_SEQ_PARTS:
            func_800AF4D8(cmd->arg1, 3);
            break;
        case AUDIOCMD_OP_GLOBAL_INIT_SEQPLAYER:
        case AUDIOCMD_OP_GLOBAL_INIT_SEQPLAYER_ALT:
            func_800AF9EC(cmd->arg0, cmd->arg1, cmd->arg2);
            func_800B679C(cmd->arg0, cmd->data);
            break;
        case AUDIOCMD_OP_GLOBAL_INIT_SEQPLAYER_SKIP_TICKS:
            func_800AFA48(cmd->arg0, cmd->arg1, cmd->data);
            break;
        case AUDIOCMD_OP_GLOBAL_DISABLE_SEQPLAYER:
            if (gSeqPlayers[cmd->arg0].enabled) {
                if (cmd->asInt == 0) {
                    func_800AC744(&gSeqPlayers[cmd->arg0]);
                } else {
                    func_800B6744(cmd->arg0, cmd->asInt);
                }
            }
            break;
        case AUDIOCMD_OP_GLOBAL_SET_SOUND_MODE:
            gAudioSoundMode = cmd->asUInt;
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
            func_800AF624(cmd->arg0, cmd->arg1, cmd->arg2);
            break;
        case AUDIOCMD_OP_GLOBAL_ASYNC_LOAD_SAMPLE_BANK:
            func_800AF6F4(cmd->arg0, cmd->arg1, cmd->arg2, &gExternalLoadQueue);
            break;
        case AUDIOCMD_OP_GLOBAL_ASYNC_LOAD_FONT:
            func_800AF758(cmd->arg0, cmd->arg1, cmd->arg2, &gExternalLoadQueue);
            break;
        case AUDIOCMD_OP_GLOBAL_DISCARD_SEQ_FONTS:
            func_800AF888(cmd->arg1);
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

void func_800B6744(s32 seqPlayId, s32 fadeTime) {
    if (fadeTime == 0) {
        fadeTime = 1;
    }

    gSeqPlayers[seqPlayId].state = 2;
    gSeqPlayers[seqPlayId].fadeTimer = fadeTime;
    gSeqPlayers[seqPlayId].fadeVelocity = -(gSeqPlayers[seqPlayId].fadeVolume / fadeTime);
}

void func_800B679C(s32 seqPlayId, s32 fadeTime) {
    if (fadeTime != 0) {
        gSeqPlayers[seqPlayId].state = 1;
        gSeqPlayers[seqPlayId].fadeTimerUnkEu = fadeTime;
        gSeqPlayers[seqPlayId].fadeTimer = fadeTime;
        gSeqPlayers[seqPlayId].fadeVolume = 0.0f;
        gSeqPlayers[seqPlayId].fadeVelocity = 0.0f;
    }
}

void func_800B67EC(void) {
    gThreadCmdWritePos = 0;
    gThreadCmdReadPos = 0;
    gThreadCmdQueueFinished = false;

    gAudioTaskStartQueue = &sAudioTaskStartQueue;
    gThreadCmdProcQueue = &sThreadCmdProcQueue;
    gAudioResetQueue = &sAudioResetQueue;
    osCreateMesgQueue(gAudioTaskStartQueue, sAudioTaskStartMsg, 1);
    osCreateMesgQueue(gThreadCmdProcQueue, sThreadCmdProcMsg, 4);
    osCreateMesgQueue(gAudioResetQueue, sAudioResetMsg, 1);
}

void func_800B6894(u32 opArgs, void** data) {
    AudioCmd* audioCmd = &gThreadCmdBuffer[gThreadCmdWritePos & 0xFF];

    audioCmd->opArgs = opArgs;
    audioCmd->data = *data;

    gThreadCmdWritePos++;
    if (gThreadCmdWritePos == gThreadCmdReadPos) {
        gThreadCmdWritePos--;
    }
}

void func_800B68EC(u32 opArgs, f32 data) {
    func_800B6894(opArgs, (void**) &data);
}

void func_800B6910(u32 opArgs, u32 data) {
    func_800B6894(opArgs, (void**) &data);
}

void func_800B6934(u32 opArgs, u8 data) {
    u32 uData = data << 0x18;

    func_800B6894(opArgs, (void**) &uData);
}

void func_800B6964(u32 opArgs, u16 data) {
    u32 uData = data << 0x10;

    func_800B6894(opArgs, (void**) &uData);
}

void func_800B6994(void) {
    static s32 D_800D185C = 0;
    OSMesg msg;

    if (D_800D185C < (((gThreadCmdWritePos - gThreadCmdReadPos) + 0x100) & 0xFF)) {
        D_800D185C = (((gThreadCmdWritePos - gThreadCmdReadPos) + 0x100) & 0xFF);
    }

    msg = ((gThreadCmdReadPos & 0xFF) << 8) | (gThreadCmdWritePos & 0xFF);

    if (osSendMesg(gThreadCmdProcQueue, msg, 0) != -1) {
        gThreadCmdReadPos = gThreadCmdWritePos;
    }
}

static char devstr11[] = "Continue Port\n";
static char devstr12[] = "%d -> %d\n";
static char devstr13[] = "Sync-Frame  Break. (Remain %d [%d,%d])\n";

void func_800B6A18(void) {
    gThreadCmdReadPos = gThreadCmdWritePos;
    gThreadCmdQueueFinished = 0;
}

void func_800B6A34(u32 msg) {
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
            gThreadCmdQueueFinished = 0;
            break;
        }
        cmd = &gThreadCmdBuffer[gCurCmdReadPos & 0xFF];
        gCurCmdReadPos++;
        if (cmd->op == AUDIOCMD_OP_GLOBAL_STOP_AUDIOCMDS) {
            gThreadCmdQueueFinished = true;
            break;
        }
        if ((cmd->op & 0xF0) == 0xF0) {
            func_800B641C(cmd);
        } else if (cmd->arg0 < gAudioBufferParams.numSequencePlayers) {
            seqPlayer = &gSeqPlayers[cmd->arg0];
            if (cmd->op & 0x80) {
                func_800B641C(cmd);
            } else if (cmd->op & 0x40) {
                switch (cmd->op) {
                    case AUDIOCMD_OP_SEQPLAYER_FADE_VOLUME_SCALE:
                        if (seqPlayer->fadeVolumeMod != cmd->asFloat) {
                            seqPlayer->fadeVolumeMod = cmd->asFloat;
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
                    func_800B706C(seqPlayer->channels[cmd->arg1], cmd);
                } else if (cmd->arg1 == 0xFF) {
                    threadCmdChannelMask = gThreadCmdChannelMask[cmd->arg0];
                    for (i = 0; i < ARRAY_COUNT(seqPlayer->channels); i++) {
                        if (threadCmdChannelMask & 1) {
                            func_800B706C(seqPlayer->channels[i], cmd);
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

u32 func_800B6D90(u32* outData) {
    u32 loadStatus;

    if (!MQ_GET_MESG(&gExternalLoadQueue, &loadStatus)) {
        *outData = 0;
        return 0;
    }
    *outData = loadStatus & 0xFFFFFF;
    return loadStatus >> 0x18;
}

u8* func_800B6DF4(s32 seqId, u32* outNumFonts) {
    return func_800AF820(seqId, outNumFonts);
}

bool func_800B6E14(void) {
    s32 pad;
    s32 specId;

    if (!MQ_GET_MESG(gAudioResetQueue, &specId)) {
        return false;
    }
    if (specId != gSpecId) {
        return false;
    }
    return true;
}

void func_800B6E6C(void) {
    MQ_CLEAR_QUEUE(gAudioResetQueue);
}

s32 func_800B6EC0(s32 specId) {
    s32 resetStatus;
    OSMesg msg;

    func_800B6E6C();
    resetStatus = gResetStatus;
    if (resetStatus != 0) {
        func_800B6A18();
        if (gSpecId == specId) {
            return 0;
        } else if (resetStatus > 2) {
            return 0;
        } else {
            MQ_WAIT_FOR_MESG(gAudioResetQueue, &msg);
        }
    }

    func_800B6E6C();
    AUDIOCMD_GLOBAL_RESET_AUDIO_HEAP(specId);

    func_800B6994();
}

void func_800B6F58(void) {
    gResetTimer = 1;
    if (gAudioContextInitialized) {
        func_800B6EC0(0);
        gResetStatus = 0;
    }
}

s8 func_800B6FA4(s32 seqPlayerIndex, s32 channelIndex, s32 ioPort) {
    SequencePlayer* seqPlayer = &gSeqPlayers[seqPlayerIndex];
    SequenceChannel* channel;

    if (seqPlayer->enabled) {
        channel = seqPlayer->channels[channelIndex];
        return channel->seqScriptIO[ioPort];
    } else {
        return SEQ_IO_VAL_NONE;
    }
}

s8 func_800B7000(s32 seqPlayerIndex, s32 ioPort) {
    return gSeqPlayers[seqPlayerIndex].seqScriptIO[ioPort];
}

void func_800B7030(void* ramAddr, size_t size) {
    func_800B2AE4(&gExternalPool, ramAddr, size);
}

void func_800B7060(void) {
    gExternalPool.startRamAddr = NULL;
}

void func_800B706C(SequenceChannel* channel, AudioCmd* cmd) {
    switch (cmd->op) {
        case AUDIOCMD_OP_CHANNEL_SET_VOL_SCALE:
            if (channel->volumeMod != cmd->asFloat) {
                channel->volumeMod = cmd->asFloat;
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
            if (channel->freqMod != cmd->asFloat) {
                channel->freqMod = cmd->asFloat;
                channel->changes.s.freqMod = true;
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

void func_800B71A4(void) {
    func_800B67EC();
}
