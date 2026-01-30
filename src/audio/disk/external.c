#include "global.h"
#include "audio.h"
#include "audiothread_cmd.h"
#include "fzx_camera.h"
#include "fzx_game.h"
#include "fzx_racer.h"

u8 sAudioRetireStatus = 0;
u8 sActiveVoiceSE = 0;
u8 sVoiceSEStack1 = 0;
u8 sVoiceSEStack2 = 0;
u8 sVoiceSEStack3 = 0;
u8 sVoiceSEStack4 = 0;
u16 sVoiceSEStackTimer1 = 0;
u16 sVoiceSEStackTimer2 = 0;
u16 sVoiceSEStackTimer3 = 0;
u16 sVoiceSEStackTimer4 = 0;
u8 sAudioDisableEnemyEngineSound = 0;
u8 sPlayerSEStatus = 0;
UNUSED s32 D_80771AF0 = 0;
UNUSED s32 D_80771AF4 = 0;
u8 sAudioPlayerMode = 0;
u8 sAudioEnemyEngineStatus = 0;
u8 sAudioClosestRacerId = 0;
u8 sAudioPreviousClosestRacerId = 0;
f32 sAudioPreviousClosestRacerDistance = 0.0f;
f32 D_80771B0C = 1.0f;
f32 sAudioClosestRacerDistance = 0.0f;
f32 sEnemyEngineVolume = 0.0f;
f32 sEnemyEngineFreqScale = 0.0f;
u8 sEnemyEngineLinearPan = 64;
u8 sAudioPauseStatus = 0;
u16 sBgmPauseFadeoutTimer = 0;
u8 sBgmPlayState = 0;
u16 sBgmFadeoutTimer = 0;
u16 sLevelFadeoutTimer = 0;
UNUSED s32 D_80771B34 = 0;
u8 sAudioLevelFadeoutActive = 0;
u8 sPreviousSpecId = 0;
u8 sActiveBgm = 0;
f32 D_80771B44[4] = { 0 };
u8 sPlayerEngineSoundState[4] = { 0 };
u8 D_80771B58[4] = { 0 };
f32 D_80771B5C[4] = { 0 };
u8 gAudioPlayerFinishedState[4] = { 0 };
u8 sPlayerEngineEchoSoundState[4] = { 0 };
u8 D_80771B74[4] = { 0 };
f32 sChannelVolume[16] = { 0 };
u8 sRacerActiveSE[30] = { 0 };
f32 sRacerAudioVolume[] = {
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
};
u8 sRomBgmQueuedBgm = 0;
u8 D_80771C54 = 0;
u8 D_80771C58 = 0;
u8 sDDBgmReadyQueuedBgm = 0;
u8 sDDBgmQueuedBgm = 0;
u8 D_80771C64 = 0;
u8 D_80771C68 = 0;
u16 D_80771C6C = 0;
u16 sSequenceLoadState = 0;
u8 D_80771C74 = 0;
u8 D_80771C78 = 0;
u8 D_80771C7C = 0;
u16 D_80771C80 = 0;
u8 sSpecChangeActive = 0;
u8 D_80771C88 = 0;
u16 D_80771C8C = 0;
u16 D_80771C90 = 0;
u8 D_80771C94 = 0;
u8 D_80771C98 = 0;
u16 D_80771C9C = 0;
u8 sBgmRomLoading = 0;
u8 D_80771CA4 = 0;
u8 D_80771CA8 = 0;
u8 D_80771CAC = 0;
u16 D_80771CB0 = 0;
u8 sSEBankLoadStatus = 0;
u8 D_80771CB8 = 0;
u8 D_80771CBC = 0;
u8 sAudioPlayerSEStack[30][4] = { 0 };
u8 sAudioLevelSEStack[4][4] = { 0 };
u8 sActivePlayerLevelSE[4][8] = { 0 };
AudioTask* gCurAudioTask = NULL;

RomOffset gAudioSequenceRomStart;
RomOffset gAudioBankRomStart;
RomOffset gAudioTableRomStart;

// Na_Reset
void Audio_Reset(u8 playerIndex) {

    PRINTF("==BANDO== Na_Reset Called\n");

    D_80771B44[playerIndex] = 0.0f;
    sPlayerEngineSoundState[playerIndex] = 0;
    D_80771B58[playerIndex] = 0;
    D_80771B5C[playerIndex] = 0;
    gAudioPlayerFinishedState[playerIndex] = 0;
    sActivePlayerLevelSE[playerIndex][0] = NA_SE_NONE;
    sActivePlayerLevelSE[playerIndex][1] = NA_SE_NONE;
    sActivePlayerLevelSE[playerIndex][2] = NA_SE_NONE;
    sActivePlayerLevelSE[playerIndex][3] = NA_SE_NONE;
    sActivePlayerLevelSE[playerIndex][4] = NA_SE_NONE;
    sActivePlayerLevelSE[playerIndex][5] = NA_SE_NONE;
    sActivePlayerLevelSE[playerIndex][6] = NA_SE_NONE;
    sActivePlayerLevelSE[playerIndex][7] = NA_SE_NONE;
    sPlayerEngineEchoSoundState[playerIndex] = 0;
    sAudioLevelSEStack[playerIndex][0] = NA_LEVEL_SE_NONE;
    sAudioLevelSEStack[playerIndex][1] = NA_LEVEL_SE_NONE;
    sAudioLevelSEStack[playerIndex][2] = NA_LEVEL_SE_NONE;
    sAudioLevelSEStack[playerIndex][3] = NA_LEVEL_SE_NONE;

    Audio_StopChannelSE(playerIndex + 2);
    Audio_StopChannelSE(playerIndex + 6);
    D_80771B74[playerIndex] = 0;
    AudioThread_ScheduleProcessCmds();
}

s32 Audio_AdjustPan(u8 pan) {
    u8 var_v1;

    if (pan == 0x3F) {
        return 0x3F;
    }

    if (pan >= 0x40) {
        var_v1 = (pan >= 0x5F) ? 0x7F : pan * 2 - 0x3F;
        return var_v1;
    }

    if (pan < 0x3F) {
        var_v1 = (pan < 0x20) ? 0 : pan * 2 - 0x3F;
        return var_v1;
    }
}

// Nas_InitAudio_DD
void Audio_InitAudio(void) {
    u8 i;

    PRINTF("==BANDO== Nas_InitAudio_DD Called\n");

    Audio_StopChannelSE(0);
    Audio_StopChannelSE(14);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, 0.0f);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, 0);
    if (D_80771C74 == 1) {
        AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 0.0f);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(1, sActiveBgm + 2, 0.0f);
        D_80771C74 = 0;
    }
    D_80771CA8 = 0;
    sAudioRetireStatus = 0;
    sAudioDisableEnemyEngineSound = false;
    sPlayerSEStatus = 0;
    sAudioEnemyEngineStatus = 0;
    sAudioClosestRacerId = 0;
    sAudioPreviousClosestRacerId = 0;
    sAudioPreviousClosestRacerDistance = 0.0f;
    D_80771B0C = 1.0f;
    sAudioClosestRacerDistance = 0.0f;
    sEnemyEngineVolume = 0.0f;
    sEnemyEngineFreqScale = 0.0f;
    sEnemyEngineLinearPan = 64;
    sAudioPauseStatus = AUDIO_PAUSE_UNPAUSED;
    sAudioLevelFadeoutActive = false;
    sLevelFadeoutTimer = 0;
    sBgmPlayState = 0;

    for (i = 0; i < 4; i++) {
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, i + 2, 0.0f);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, i + 6, 0.0f);
        AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, i + 2, 0);
        AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, i + 6, 0);
        Audio_Reset(i);
        sRacerActiveSE[i] = NA_SE_NONE;
    }

    for (i = 0; i < 16; i++) {
        sChannelVolume[i] = 0.0f;
    }

    for (i = 0; i < 30; i++) {
        sAudioPlayerSEStack[i][0] = 0;
        sAudioPlayerSEStack[i][1] = 0;
        sAudioPlayerSEStack[i][2] = 0;
        sAudioPlayerSEStack[i][3] = 0;
    }
}

u8 Audio_GetActiveBgm(void) {
    return sActiveBgm;
}

void Audio_PreNMI(void) {
    AudioThread_PreNMIInternal();
}

void Audio_Init(RomOffset audioSequenceStart, RomOffset audioBankStart, RomOffset audioTableStart) {
    PRINTF("==BANDO== SEQ ROM START = %x\n", audioSequenceStart);
    gAudioSequenceRomStart = audioSequenceStart;
    PRINTF("==BANDO== BNK ROM START = %x\n", audioBankStart);
    gAudioBankRomStart = audioBankStart;
    PRINTF("==BANDO== TBL ROM START = %x\n", audioTableStart);
    gAudioTableRomStart = audioTableStart;
    AudioLoad_Init(NULL, 0);
}

// Na_SetOutMode
void Audio_SetOutMode(u8 soundMode) {
    PRINTF("==BANDO== Na_SetOutMode Called. mode = %d\n", soundMode);
    AUDIOCMD_GLOBAL_SET_SOUND_MODE(soundMode);
}

void Audio_PlayerFinished(u8 playerIndex) {

    gAudioPlayerFinishedState[playerIndex] = 1;
    Audio_StopChannelSE(14);
    AudioThread_ScheduleProcessCmds();
}

void Audio_SetEnemyEnginePan(u8 pan) {
    sEnemyEngineLinearPan = pan;
}

// Na_Player_Goal
void Audio_SetNearestEnemy(u8 racerId) {
    PRINTF("==BANDO== Na_Player_Goal player = %d\n", racerId);
    sAudioClosestRacerId = racerId;
}

// Na_PlyLevelSE_Start
void Audio_PlayerLevelSEStart(u8 playerIndex, u8 sfxId) {

    PRINTF("==BANDO== Na_PlyLevelSE_Start Called player =  %02x SE number = %02x\n", playerIndex, sfxId);

    if (gAudioPlayerFinishedState[playerIndex] != 0) {
        return;
    }

    if ((sfxId != sActivePlayerLevelSE[playerIndex][0]) && (sfxId != sActivePlayerLevelSE[playerIndex][1]) &&
        (sfxId != sActivePlayerLevelSE[playerIndex][2]) && (sfxId != sActivePlayerLevelSE[playerIndex][3]) &&
        (sfxId != sActivePlayerLevelSE[playerIndex][4]) && (sfxId != sActivePlayerLevelSE[playerIndex][5]) &&
        (sfxId != sActivePlayerLevelSE[playerIndex][6]) && (sfxId != sActivePlayerLevelSE[playerIndex][7])) {
        if (sAudioLevelSEStack[playerIndex][0] != NA_LEVEL_SE_NONE) {
            if (sAudioLevelSEStack[playerIndex][1] != NA_LEVEL_SE_NONE) {
                if (sAudioLevelSEStack[playerIndex][2] != NA_LEVEL_SE_NONE) {
                    if (sAudioLevelSEStack[playerIndex][3] == NA_LEVEL_SE_NONE) {
                        sAudioLevelSEStack[playerIndex][3] = sfxId;
                    } else {
                        PRINTF("==BANDO== PLAYER LEVEL SE STACK OVER!!\n");
                    }
                } else {
                    sAudioLevelSEStack[playerIndex][2] = sfxId;
                }
            } else {
                sAudioLevelSEStack[playerIndex][1] = sfxId;
            }
        } else {
            sAudioLevelSEStack[playerIndex][0] = sfxId;
        }
    }
}

// Na_PlyLevelSE_Stop
void Audio_PlayerLevelSEStop(u8 playerIndex, u8 sfxId) {
    s32 temp;

    PRINTF("==BANDO== Na_PlyLevelSE_Stop Called player = %02x num = %02x \n", playerIndex, sfxId);

    if (sfxId == sAudioLevelSEStack[playerIndex][0]) {
        sAudioLevelSEStack[playerIndex][0] = NA_LEVEL_SE_NONE;
        if (sAudioLevelSEStack[playerIndex][1] != NA_LEVEL_SE_NONE) {
            sAudioLevelSEStack[playerIndex][0] = sAudioLevelSEStack[playerIndex][1];
            sAudioLevelSEStack[playerIndex][1] = sAudioLevelSEStack[playerIndex][2];
            sAudioLevelSEStack[playerIndex][2] = sAudioLevelSEStack[playerIndex][3];
            sAudioLevelSEStack[playerIndex][3] = NA_LEVEL_SE_NONE;
        }
    }
    if (sfxId == sAudioLevelSEStack[playerIndex][1]) {
        sAudioLevelSEStack[playerIndex][1] = NA_LEVEL_SE_NONE;
        if (sAudioLevelSEStack[playerIndex][2] != NA_LEVEL_SE_NONE) {
            sAudioLevelSEStack[playerIndex][1] = sAudioLevelSEStack[playerIndex][2];
            sAudioLevelSEStack[playerIndex][2] = sAudioLevelSEStack[playerIndex][3];
            sAudioLevelSEStack[playerIndex][3] = NA_LEVEL_SE_NONE;
        }
    }
    if (sfxId == sAudioLevelSEStack[playerIndex][2]) {
        sAudioLevelSEStack[playerIndex][2] = NA_LEVEL_SE_NONE;
        if (sAudioLevelSEStack[playerIndex][3] != NA_LEVEL_SE_NONE) {
            sAudioLevelSEStack[playerIndex][2] = sAudioLevelSEStack[playerIndex][3];
            sAudioLevelSEStack[playerIndex][3] = NA_LEVEL_SE_NONE;
        }
    }
    if (sfxId == sAudioLevelSEStack[playerIndex][3]) {
        sAudioLevelSEStack[playerIndex][3] = NA_LEVEL_SE_NONE;
    }

    if (sfxId == sActivePlayerLevelSE[playerIndex][0]) {
        PRINTF("==BANDO== NON ENTRIED LEVEL SE STOPED! SE NUMBER = %02x\n", sfxId);
        sActivePlayerLevelSE[playerIndex][0] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = NA_LEVEL_SE_NONE;
        if (sActivePlayerLevelSE[playerIndex][0] == NA_LEVEL_SE_NONE) {
            Audio_StopChannelSE(playerIndex + 6);
        } else {
            Audio_StopChannelSE(playerIndex + 6);
            temp = sActivePlayerLevelSE[playerIndex][0];
            sActivePlayerLevelSE[playerIndex][0] = NA_LEVEL_SE_NONE;
            Audio_PlayerLevelSEStart(playerIndex, temp);
        }
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][1]) {
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = NA_LEVEL_SE_NONE;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][2]) {
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = NA_LEVEL_SE_NONE;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][3]) {
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = NA_LEVEL_SE_NONE;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][4]) {
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = NA_LEVEL_SE_NONE;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][5]) {
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = NA_LEVEL_SE_NONE;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][6]) {
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = NA_LEVEL_SE_NONE;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][7]) {
        sActivePlayerLevelSE[playerIndex][7] = NA_LEVEL_SE_NONE;
    }
}

void Audio_PlayerTriggerSE(u8 racerId, u8 sfxId) {

    if (sfxId != sAudioPlayerSEStack[racerId][0] && sfxId != sAudioPlayerSEStack[racerId][1] &&
        sfxId != sAudioPlayerSEStack[racerId][2] && sfxId != sAudioPlayerSEStack[racerId][3]) {
        if (sAudioPlayerSEStack[racerId][0] != NA_SE_NONE) {
            if (sAudioPlayerSEStack[racerId][1] != NA_SE_NONE) {
                if (sAudioPlayerSEStack[racerId][2] != NA_SE_NONE) {
                    if (sAudioPlayerSEStack[racerId][3] == NA_SE_NONE) {
                        sAudioPlayerSEStack[racerId][3] = sfxId;
                    }
                } else {
                    sAudioPlayerSEStack[racerId][2] = sfxId;
                }
            } else {
                sAudioPlayerSEStack[racerId][1] = sfxId;
            }
        } else {
            sAudioPlayerSEStack[racerId][0] = sfxId;
        }
    }
}

// Na_PlyTrgSE_Start
void Audio_PlayerTriggerSEStart(u8 racerId, u8 sfxId) {

    PRINTF("==BANDO== Na_PlyTrgSE_Start Called. player = %02x num = %02x\n");

    switch (sAudioPlayerMode) {
        case 0:
        default:
            if (gAudioPlayerFinishedState[0] != 0) {
                PRINTF("==BANDO== Na_PlyTrgSE_Start Called BUT RETURN! cause GOAL\n");
                return;
            }
            break;
        case 1:
        case 2:
        case 3:
            if (gAudioPlayerFinishedState[racerId] != 0) {
                PRINTF("==BANDO== Na_PlyTrgSE_Start Called BUT RETURN! cause GOAL\n");
                return;
            }
            break;
    }

    if (sfxId == NA_SE_30) {
        goto block_5;
    }
    if (sfxId == NA_SE_33) {
        goto block_5;
    }
    if (sAudioRetireStatus == 1) {
        return;
    }
block_5:

    if ((racerId == 0) || (racerId == 1) || (racerId == 2) || (racerId == 3)) {
        sRacerAudioVolume[racerId] = 1.0f;
    } else if (sPlayerSEStatus == 1) {
        return;
    }
    Audio_PlayerTriggerSE(racerId, sfxId);
}

void Audio_SystemSEStart(u8 ioData) {
    AUDIOCMD_CHANNEL_SET_PAN(0, 1, 0x3F);
    Audio_SEStart(1, ioData);
    AudioThread_ScheduleProcessCmds();
}

void Audio_TriggerVoiceSEStart(u8 sfxId, u16 time) {

    if ((sfxId != sVoiceSEStack1) && (sfxId != sVoiceSEStack2) && (sfxId != sVoiceSEStack3) &&
        (sfxId != sVoiceSEStack4)) {
        if (sVoiceSEStackTimer1 != 0) {
            if (sVoiceSEStackTimer2 != 0) {
                if (sVoiceSEStackTimer3 != 0) {
                    if (sVoiceSEStackTimer4 == 0) {
                        sVoiceSEStack4 = sfxId;
                        sVoiceSEStackTimer4 = time;
                    } else {
                        PRINTF("==BANDO== VOICE SE STACK OVER!!\n");
                    }
                } else {
                    sVoiceSEStack3 = sfxId;
                    sVoiceSEStackTimer3 = time;
                }
            } else {
                sVoiceSEStack2 = sfxId;
                sVoiceSEStackTimer2 = time;
            }
        } else {
            sVoiceSEStack1 = sfxId;
            sVoiceSEStackTimer1 = time;
        }
    }
}

extern s32 D_800D11C8[];

void Audio_TriggerSystemSE(u8 sfxId) {
    u8 i;

    PRINTF("==BANDO== System SE = %02x\n", sfxId);

    if ((D_80771C94 == 1) && (D_800D11C8[3] == 0)) {
        return;
    }

    if (sfxId == NA_SE_11) {
        D_80771CA8 = 0;
        for (i = 0; i < sAudioPlayerMode + 1; i++) {
            if (sAudioRetireStatus == 0) {
                func_8074184C(i);
            }
        }
    }
    if (sfxId == NA_SE_17) {
        Audio_TriggerVoiceSEStart(sfxId, 131);
    } else if (sfxId == NA_SE_18) {
        Audio_TriggerVoiceSEStart(sfxId, 179);
    } else if (sfxId == NA_SE_42) {
        Audio_TriggerVoiceSEStart(sfxId, 190);
    } else if (sfxId == NA_SE_44) {
        Audio_TriggerVoiceSEStart(sfxId, 198);
    } else if (sfxId == NA_SE_48) {
        Audio_TriggerVoiceSEStart(sfxId, 154);
    } else if (sfxId == NA_SE_51) {
        Audio_TriggerVoiceSEStart(sfxId, 155);
    } else if (sfxId == NA_SE_52) {
        Audio_TriggerVoiceSEStart(sfxId, 233);
    } else if (sfxId == NA_SE_53) {
        Audio_TriggerVoiceSEStart(sfxId, 205);
    } else if (sfxId == NA_SE_56) {
        Audio_TriggerVoiceSEStart(sfxId, 113);
    } else if (sfxId == NA_SE_58) {
        Audio_TriggerVoiceSEStart(sfxId, 104);
    } else if (sfxId == NA_SE_59) {
        Audio_TriggerVoiceSEStart(sfxId, 181);
    } else if (sfxId == NA_SE_60) {
        Audio_TriggerVoiceSEStart(sfxId, 153);
    } else if (sfxId == NA_SE_61) {
        Audio_TriggerVoiceSEStart(sfxId, 131);
    } else if (sfxId == NA_SE_67) {
        Audio_TriggerVoiceSEStart(sfxId, 155);
    } else {
        Audio_SystemSEStart(sfxId);
    }
}

// Na_hanabi
void Audio_Hanabi(u8 pan, u8 volume) {
    f32 volumeScale;

    PRINTF("==BANDO== Na_hanabi Called. pan = %02x volume = %02x \n", pan, volume);

    AUDIOCMD_CHANNEL_SET_PAN(0, 15, Audio_AdjustPan(pan));

    if (volume >= 0x80) {
        volume = 0x7F;
    }
    if (volume < 0) {
        volume = 0;
    }

    volumeScale = volume / 127.0f;
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 15, volumeScale);
    Audio_SEStart(15, NA_SE_45);
}

void Audio_PlayerEngineEchoStart(u8 playerIndex) {
    PRINTF("==BANDO== ENGINE SOUND ECHO START MACHINE NO = %02x\n", playerIndex);
    sPlayerEngineEchoSoundState[playerIndex] = 1;
}

void Audio_PlayerEngineEchoStop(u8 playerIndex) {
    PRINTF("==BANDO== ENGINE SOUND ECHO STOPED! MACHINE No.= %02x\n", playerIndex);
    sPlayerEngineEchoSoundState[playerIndex] = 0;
}

void Audio_PlayerEngineStop(u8 playerIndex) {
    PRINTF("==BANDO== ENGINE SOUND STOPED! MACHINE No.= %02x\n", playerIndex);
    Audio_StopChannelSE(playerIndex + 2);
    sPlayerEngineSoundState[playerIndex] = 0;
}

// Na_PlyEng_Start
void Audio_PlayerEngineStart(u8 playerIndex) {

    PRINTF("==BANDO== Na_PlyEng_Start Called player = %02x\n", playerIndex);
    switch (sAudioPlayerMode) {
        case 0:
            AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0x3F);
            if (D_80771B74[playerIndex] == 0) {
                Audio_SEStart(playerIndex + 2, NA_LEVEL_SE_2);
            } else {
                Audio_SEStart(playerIndex + 2, NA_LEVEL_SE_7);
            }
            break;
        case 1:
            switch (playerIndex) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 3, 0x7F);
                    break;
            }
            if (D_80771B74[playerIndex] == 0) {
                Audio_SEStart(playerIndex + 2, LEVEL_SE_2P(NA_LEVEL_SE_2));
            } else {
                Audio_SEStart(playerIndex + 2, LEVEL_SE_2P(NA_LEVEL_SE_7));
            }
            break;
        case 2:
            switch (playerIndex) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 3, 0);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 4, 0x7F);
                    break;
            }
            if (D_80771B74[playerIndex] == 0) {
                Audio_SEStart(playerIndex + 2, LEVEL_SE_MP(NA_LEVEL_SE_2));
            } else {
                Audio_SEStart(playerIndex + 2, LEVEL_SE_MP(NA_LEVEL_SE_7));
            }
            break;
        case 3:
            switch (playerIndex) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 3, 0);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 4, 0x7F);
                    break;
                case 3:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 5, 0x7F);
                    break;
            }
            if (D_80771B74[playerIndex] == 0) {
                Audio_SEStart(playerIndex + 2, LEVEL_SE_MP(NA_LEVEL_SE_2));
            } else {
                Audio_SEStart(playerIndex + 2, LEVEL_SE_MP(NA_LEVEL_SE_7));
            }
    }
    AudioThread_ScheduleProcessCmds();
}

void func_8074184C(u8 playerIndex) {
    PRINTF("==BANDO== WINING RUN ENGINE SOUND START! MACHINE No.= %02x\n", playerIndex);
    Audio_PlayerEngineStart(playerIndex);
    sPlayerEngineSoundState[playerIndex] = 1;
}

void func_80741880(u8 arg0) {
}

// Na_SE_Start
void Audio_SEStart(u8 channelIndex, u8 ioData) {
    PRINTF("==BANDO== Na_SE_Start CALLED!! setype = %02x(hex) senum = %02x(hex) \n", channelIndex, ioData);
    AUDIOCMD_CHANNEL_SET_IO(0, channelIndex, 0, ioData);
    AudioThread_ScheduleProcessCmds();
}

void Audio_StopChannelSE(u8 channelIndex) {
    AUDIOCMD_CHANNEL_SET_IO(0, channelIndex, 5, 1);
}

// Na_DDBgm_Ready_Inter
void Audio_DDBgmReadyInter(u8 bgm) {

    PRINTF("==BANDO== Na_DDBgm_Ready_Inter Called num = %02x\n", bgm);

    if ((D_80771C80 != 0) || (D_80771C7C != 0)) {
        sDDBgmReadyQueuedBgm = bgm + 1;
        return;
    }
    D_80771C78 = bgm;
    D_80771C7C = 1;

    AUDIOCMD_GLOBAL_ASYNC_LOAD_SAMPLE_BANK(D_80771C78 + SAMPLE_DDBGM_MUTE_CITY, 0, AUDIO_LOAD_BGM_READY_INTER);
    AudioThread_ScheduleProcessCmds();
}

// Na_DDBgm_Ready_Taiki
void Audio_DDBgmReadyTaiki(void) {

    if (D_80771C6C == 0) {
        return;
    }

    D_80771C6C++;
    if (D_80771C6C == 30) {
        PRINTF("==BANDO== in dd_bgm_ready_taiki count up complete!\n");
        D_80771C6C = 0;
        PRINTF("==BANDO== in dd_bgm_ready_taiki calling Na_DDBgm_Ready_Inter...\n");
        Audio_DDBgmReadyInter(D_80771C68);
        D_80771C68 = 0;
    }
}

// Na_DDBgm_Ready
void Audio_DDBgmReady(u8 bgm) {
    PRINTF("==BANDO== Na_DDBgm_Ready Called num = %02x\n", bgm);
    D_80771C68 = bgm;
    D_80771C6C = 1;
}

// Na_DDBgm_Start
void Audio_DDBgmStart(u8 bgm) {

    PRINTF("==BANDO== Na_DDBgm_Start num =%d\n", bgm);

    if (sAudioRetireStatus == 1) {
        return;
    }

    if ((D_80771C7C != 0) || (D_80771CA4 == 1)) {
        sDDBgmQueuedBgm = bgm + 1;
        return;
    }
    sActiveBgm = bgm;
    sBgmRomLoading = true;
    D_80771C74 = 1;

    AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(1, bgm + 2, 1.0f);
    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, bgm + SEQ_DDBGM_MUTE_CITY, 0, 0);
    if (bgm == BGM_COURSE_EDITOR) {
        D_80771C98 = false;
        D_80771C9C = 0;
    }
    AudioThread_ScheduleProcessCmds();
}

// Na_DDBgm_Start2
void Audio_DDBgmStart2(u8 bgm) {

    PRINTF("==BANDO== Na_DDBgm_Start2 num = %d\n", bgm);

    if ((D_80771C7C != 0) || (D_80771CA4 == 1)) {
        D_80771C64 = bgm;
        return;
    }
    sBgmRomLoading = true;
    D_80771C74 = 1;
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 0);
    sActiveBgm = bgm;
    D_80771C64 = bgm;
    D_80771C98 = true;
    AudioThread_ScheduleProcessCmds();
}

// Na_DDBgm_Stop
void Audio_DDBgmStop(void) {
    PRINTF("==BANDO== Na_DDBgm_Stop Called\n");
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 120);
    sBgmRomLoading = false;
    D_80771C74 = 0;
    D_80771C98 = false;
    D_80771C9C = 0;
}

// Na_BetaBgm_Start
void Audio_BetaBgmStart(u8 bgm) {
    PRINTF("==BANDO== Na_BetaBgm_Start num = %02x\n", bgm);
}

// Na_BetaBgm_Stop
void Audio_BetaBgmStop(void) {
    PRINTF("==BANDO== Na_BetaBgm_Stop Called\n");
}

// Na_ROMBgm_Ready
void Audio_RomBgmReady(u8 bgm) {

    PRINTF("==BANDO== Na_ROMBgm_Ready Called %02x\n", bgm);

    if (bgm != BGM_TITLE) {
        PRINTF("==BANDO== in Na_ROMBgm_Ready Wave Data BG Load Start\n");
        if ((D_80771C80 == 0) && (D_80771C7C == 0)) {
            PRINTF("==BANDO== in Na_ROMBgm_Ready Ready Bgm Stack\n");
            D_80771C80 = 1;
            AUDIOCMD_GLOBAL_ASYNC_LOAD_SAMPLE_BANK(bgm + SAMPLE_DDBGM_MUTE_CITY, 0, AUDIO_LOAD_BGM_READY);
            return;
        }
        D_80771C58 = bgm + 1;
    }
}

// Na_ROMBgm_Ready_Taiki
void Audio_RomBgmReadyTaiki(void) {
    u8 bgm;

    if ((D_80771C58 != 0) && (D_80771C80 != 1)) {
        bgm = D_80771C58 - 1;
        if (D_80771C7C == 0) {
            D_80771C58 = 0;
            PRINTF("==BANDO== in rom_bgm_ready_taiki Na_ROMBgm_Ready Calling num = %02x\n", bgm);
            Audio_RomBgmReady(bgm);
        }
    }
}

// Na_ROMBgm_Start
void Audio_RomBgmStart(u8 bgm) {
    s32 pad;

    PRINTF("==BANDO== Na_ROMBgm_Start Called num = %02x\n", bgm);

    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 1.0f);

    sActiveBgm = bgm;
    sBgmPlayState = 0;
    sBgmFadeoutTimer = 0;
    if (bgm == BGM_GAMEOVER) {
        PRINTF("==BANDO== GAMEOVER BGM CALLED so DDBgm Stoping!! for ILLEGULALL COURSE MAKING\n");
        Audio_DDBgmStop();
    }
    switch (bgm) {
        case BGM_TITLE:
            AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
            AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, bgm + SEQ_DDBGM_MUTE_CITY, 0, 0);
            break;
        case BGM_SELECT:
        case BGM_OPTION:
            PRINTF("==BANDO== Na_ROMBgm_Start SELECT or OPTION BGM START\n");
            if (D_80771C80 == 0) {
                AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
                AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, bgm + SEQ_DDBGM_MUTE_CITY, 0, 0);
            } else {
                D_80771C54 = bgm + 1;
            }
            break;
        default:
            Audio_SEStart(0, bgm);
            break;
    }
    AudioThread_ScheduleProcessCmds();
}

// Na_ROMBgm_Stop
void Audio_RomBgmStop(void) {
    PRINTF("==BANDO== Na_ROMBgm_Stop Called\n");
    switch (sActiveBgm) {
        case BGM_TITLE:
            AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 200);
            break;
        case BGM_SELECT:
            AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 100);
            break;
        case BGM_OPTION:
            AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 100);
            break;
    }
    if (sBgmPlayState == 0) {
        sBgmPlayState = 1;
    }
}

// Na_ROMBgm_Stop2
void Audio_RomBgmStop2(void) {
    PRINTF("==BANDO== Na_ROMBgm_Stop Called\n");
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 200);
}

// Na_START_DEMO
void Audio_StartDemo(void) {
    PRINTF("==BANDO== Na_START_DEMO Called\n");
    D_80771CA8 = 1;
    Audio_RomBgmStart(BGM_DEMO);
}

// Na_RETIRE
void Audio_Retire(void) {
    PRINTF("==BANDO== Na_RETIRE CALLED!!\n");
    sAudioRetireStatus = 1;
}

// Na_Level_SE_Fadeout
void Audio_LevelSEFadeout(void) {
    PRINTF("==BANDO== Na_Level_SE_Fadeout Called\n");
    Audio_DisablePlayerSE();
    sAudioLevelFadeoutActive = true;
    sAudioDisableEnemyEngineSound = true;
}

// Na_Test_Run_Start
void Audio_TestRunStart(void) {
    PRINTF("==BANDO== Na_Test_Run_Start Called\n");
    sBgmPauseFadeoutTimer = 0;
    sAudioRetireStatus = 0;
    sAudioDisableEnemyEngineSound = false;
    sPlayerSEStatus = 0;
    sAudioEnemyEngineStatus = 0;
    sAudioClosestRacerId = 0;
    sAudioPreviousClosestRacerId = 0;
    sAudioPreviousClosestRacerDistance = 0.0f;
    D_80771B0C = 1.0f;
    sAudioClosestRacerDistance = 0.0f;
    sEnemyEngineVolume = 0.0f;
    sEnemyEngineFreqScale = 0.0f;
    sEnemyEngineLinearPan = 64;
    sAudioPauseStatus = AUDIO_PAUSE_UNPAUSED;
    sAudioLevelFadeoutActive = false;
    sLevelFadeoutTimer = 0;
    sBgmPlayState = 0;
    Audio_Reset(0);
    func_8074184C(0);
}

// Na_Test_Run_End
void Audio_TestRunEnd(void) {
    PRINTF("==BANDO== Na_Test_Run_End Called\n");
    sAudioDisableEnemyEngineSound = false;
    sLevelFadeoutTimer = 0;
    sAudioLevelFadeoutActive = false;
    sBgmPauseFadeoutTimer = 0;
    sAudioPauseStatus = AUDIO_PAUSE_UNPAUSED;
    Audio_StopChannelSE(14);
    Audio_Reset(0);
}

// Na_BetaBgm_Stop2
void Audio_BetaBgmStop2(void) {
    PRINTF("==BANDO== Na_BetaBgm_Stop2 Called\n");
    if (sBgmPlayState == 0) {
        sBgmPlayState = 2;
    }
}

// Na_BetaBgm_Stop3
void Audio_BetaBgmStop3(void) {
    PRINTF("==BANDO== Na_BetaBgm_Stop3 Called\n");
    if (sBgmPlayState == 0) {
        sBgmPlayState = 3;
    }
}

// Na_PauseSet
void Audio_PauseSet(u8 status) {
    u32 retMsg;
    u8 sp33;

    PRINTF("==BANDO== Pause Called!! Status =  %02x\n", status);

    switch (status) {
        case AUDIO_PAUSE_UNPAUSED:
            sAudioPauseStatus = AUDIO_PAUSE_UNPAUSED;
            if (D_80771C74 == 1) {
                AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
            }
            break;
        case AUDIO_PAUSE_PAUSED:
            sAudioPauseStatus = AUDIO_PAUSE_PAUSED;
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 2, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 3, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 4, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 5, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 6, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 7, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 8, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 9, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, 0.0f);
            if (D_80771C74 == 1) {
                PRINTF("==BANDO== Na_PauseSet DD BGM Volume Down\n");
                AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 0.4f);
            }
            break;
        case AUDIO_PAUSE_TRANSITION:
            Audio_StopChannelSE(2);
            Audio_StopChannelSE(3);
            Audio_StopChannelSE(4);
            Audio_StopChannelSE(5);
            Audio_StopChannelSE(6);
            Audio_StopChannelSE(7);
            Audio_StopChannelSE(8);
            Audio_StopChannelSE(9);
            Audio_StopChannelSE(14);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 2, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 3, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 4, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 5, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 6, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 7, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 8, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 9, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, 0.0f);
            AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 0);

            switch (D_80771C7C) {
                case 0:
                    break;
                case 1:
                    sp33 = true;
                    D_80771CAC = 1;
                    while (sp33) {
                        if ((AudioThread_GetAsyncLoadStatus(&retMsg) == AUDIO_LOAD_BGM_READY_INTER) ||
                            (D_80771CB0 > 300)) {
                            PRINTF("==BANDO== in Na_PauseSet Wave Data Load End\n");
                            D_80771CB0 = 0;
                            sDDBgmReadyQueuedBgm = 0;
                            sDDBgmQueuedBgm = 0;
                            sRomBgmQueuedBgm = 0;
                            D_80771C7C = 0;
                            sp33 = false;
                            D_80771CAC = 0;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
    }
    AudioThread_ScheduleProcessCmds();
}

void Audio_SetSpec(s32 specId) {
    PRINTF("==BANDO== Spec Change No = %02x\n", specId);
    if (specId != sPreviousSpecId) {
        sPreviousSpecId = specId;
        sSpecChangeActive = true;
        AudioThread_ResetAudioHeap(specId);
        do {
        } while (AudioThread_ResetComplete() == 0);
        sSpecChangeActive = false;
    }
}

void Audio_SetPlayerMode(u8 numPlayersIndex) {
    PRINTF("==BANDO== Player Mode = %02x\n", numPlayersIndex);
    sAudioPlayerMode = numPlayersIndex;
}

void Audio_AllSoundStop(void) {
    PRINTF("==BANDO== All Sound Off\n");
    Audio_InitAudio();
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(0, 0);
    AudioThread_ScheduleProcessCmds();
    if (D_80771C74 == 1) {
        AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 0);
    }
}

// Na_SeSeq_Start
void Audio_SESeqStart(void) {
    PRINTF("==BANDO== Na_SeSeq_Start for 64DD Called\n");
    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(0, SEQ_SOUND_EFFECTS, 0, 0);
    AudioThread_ScheduleProcessCmds();
}

// Na_ChangeSoundMode
void Audio_ChangeSoundMode(s32 courseIndex) {
    PRINTF("==BANDO== Na_ChangeSoundMode Called. course = %02x\n", courseIndex);
    Audio_InitAudio();
    AudioThread_ScheduleProcessCmds();
}

// Na_chakuchi
void Audio_Chakuchi(u8 racerId, f32 volume) {

    if (gAudioPlayerFinishedState[racerId] != 0) {
        PRINTF("==BANDO== Na_chakuchi Called BUT RETURN! cause GOAL\n");
        return;
    }

    if (volume < -48.0f) {
        volume = -48.0f;
    }

    if (volume > -2.5f) {
        return;
    }
    sRacerAudioVolume[racerId] = 0.2f - (volume / 58.0f);
    if (sRacerAudioVolume[racerId] > 0.75f) {
        sRacerAudioVolume[racerId] = 0.75f;
    }
    PRINTF("==BANDO== Na_chakuchi Edited volume = %f \n", sRacerAudioVolume[racerId]);
    Audio_PlayerTriggerSE(racerId, NA_SE_54);
}

s32 func_807424CC(void) {
    PRINTF("==BANDO== dd_bgm_data_load2 -SeqStart-\n");
    if (!sBgmRomLoading && (D_80771C7C == 0)) {
        D_80771CA4 = 0;
    } else {
        D_80771CA4 = 1;
    }
    return D_80771CA4;
}

u8 func_80742510(void) {
    PRINTF("==BANDO== dd_bgm_forground_load_check end num = %d\n", D_80771CBC);
    return D_80771CBC;
}

void Audio_DisablePlayerSE(void) {
    sPlayerSEStatus = 1;
}

void func_8074252C(void) {
    u8 bgm;

    if (!D_80771C98) {
        return;
    }

    D_80771C9C++;
    if (D_80771C9C == 30) {
        PRINTF("==BANDO== dd_bgm_data_load WAVE Data Load End\n");
        bgm = D_80771C64;
        AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(1, bgm + 2, 1.0f);
        AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, bgm + SEQ_DDBGM_MUTE_CITY, 0, 0);
        D_80771C9C = 0;
        D_80771C98 = false;
    }
}

void Audio_CheckBgmLoad(void) {
    u8 seqLoadComplete;
    u8 fontLoadComplete;
    u8 sampleLoadComplete;

    if (!sBgmRomLoading) {
        return;
    }

    seqLoadComplete = AudioLoad_IsSeqLoadComplete(sActiveBgm + SEQ_DDBGM_MUTE_CITY);
    fontLoadComplete = AudioLoad_IsFontLoadComplete(sActiveBgm + FONT_DDBGM_MUTE_CITY);
    sampleLoadComplete = AudioLoad_IsSampleLoadComplete(sActiveBgm + SAMPLE_DDBGM_MUTE_CITY);
    if ((seqLoadComplete == true) && (fontLoadComplete == true) && (sampleLoadComplete == true)) {
        PRINTF("==BANDO== ROM BGM LOAD OK!\n");
        sBgmRomLoading = false;
    }
}

void func_80742654(void) {
    u32 retMsg;

    PRINTF("==BANDO== TAIKI ROM BGM START!\n");

    if (D_80771C80 == 1) {
        return;
    }

    switch (D_80771C7C) {
        case 0:
            break;
        case 1:
            if (AudioThread_GetAsyncLoadStatus(&retMsg) == AUDIO_LOAD_BGM_READY_INTER) {
                if (sDDBgmReadyQueuedBgm != 0) {
                    Audio_DDBgmReady(sDDBgmReadyQueuedBgm - 1);
                    sDDBgmReadyQueuedBgm = 0;
                }
                if (sDDBgmQueuedBgm != 0) {
                    Audio_DDBgmStart(sDDBgmQueuedBgm - 1);
                    sDDBgmQueuedBgm = 0;
                }
                if (sRomBgmQueuedBgm != 0) {
                    Audio_RomBgmStart(sRomBgmQueuedBgm - 1);
                    sRomBgmQueuedBgm = 0;
                }
                D_80771C7C = 0;
            }
            break;
        default:
            break;
    }
}

void func_8074270C(void) {
    u32 retMsg;

    if (D_80771C80 != 1) {
        return;
    }

    if (AudioThread_GetAsyncLoadStatus(&retMsg) == AUDIO_LOAD_BGM_READY) {
        D_80771C80 = 0;
        if (D_80771C54 != 0) {
            AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
            AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, (D_80771C54 - 1) + SEQ_DDBGM_MUTE_CITY, 0, 0);
            D_80771C54 = 0;
        }
    }
}

s32 func_80742790(void) {
    return D_80771C88;
}

// Na_Guitor_Start
void Audio_GuitarSeqStart(void) {
    PRINTF("==BANDO== Na_Guitor_Start Called\n");
    PRINTF("==BANDO== Na_Guitor_Start for 64DD Called\n");
    sSequenceLoadState = SEQ_LOAD_BANK;
    sActiveBgm = BGM_NONE;
    D_80771C88 = 1;
}

void func_807427C0(void) {
    u8 loadStatus;
    u32 retMsg;
    u8 sampleLoadComplete;
    u8 fontLoadComplete;
    u8 seqLoadComplete;

    switch (sSequenceLoadState) {
        case SEQ_LOAD_BANK:
            PRINTF("==BANDO== SE BANK LOAD START\n");
            AUDIOCMD_GLOBAL_SYNC_LOAD_SEQ_PARTS(SEQ_SOUND_EFFECTS, 2);
            AUDIOCMD_GLOBAL_ASYNC_LOAD_SAMPLE_BANK(SAMPLE_GUITAR, 0, AUDIO_LOAD_GUITAR_WAVE);
            AUDIOCMD_GLOBAL_ASYNC_LOAD_SAMPLE_BANK(SAMPLE_DD_SOUND_EFFECTS, 0, AUDIO_LOAD_SE_WAVE);
            sSEBankLoadStatus = 0;
            sSequenceLoadState = SEQ_LOAD_WAVE;
            break;
        case SEQ_LOAD_WAVE:
            loadStatus = AudioThread_GetAsyncLoadStatus(&retMsg);
            if (loadStatus == AUDIO_LOAD_GUITAR_WAVE) {
                sSEBankLoadStatus |= BANK_GUITAR_LOAD_COMPLETE;
            }
            if (loadStatus == AUDIO_LOAD_SE_WAVE) {
                sSEBankLoadStatus |= BANK_SE_LOAD_COMPLETE;
            }
            if (sSEBankLoadStatus == (BANK_GUITAR_LOAD_COMPLETE | BANK_SE_LOAD_COMPLETE)) {
                PRINTF("==BANDO== GUITOR & SE ROM WAVE DMA END\n");
                AUDIOCMD_GLOBAL_INIT_SEQPLAYER(0, SEQ_GUITAR, 0, 0);
                sSequenceLoadState = SEQ_LOAD_DATA;
                break;
            }
            break;
        case SEQ_LOAD_DATA:
            sampleLoadComplete = AudioLoad_IsSampleLoadComplete(SAMPLE_GUITAR);
            fontLoadComplete = AudioLoad_IsFontLoadComplete(FONT_GUITAR);
            seqLoadComplete = AudioLoad_IsSeqLoadComplete(SEQ_GUITAR);
            PRINTF("==BANDO== ALL GUITOR DATA LOAD END CHECKING... wav =%d bnk=%d seq=%d\n", sampleLoadComplete,
                   fontLoadComplete, seqLoadComplete);
            if ((sampleLoadComplete == true) && (fontLoadComplete == true) && (seqLoadComplete == true)) {
                PRINTF("==BANDO== ALL GUITOR DATA LOAD END\n");
                D_80771C88 = 2;
                AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_SOUND_EFFECTS, AUDIO_LOAD_FONT_DDBGM_MUTE_CITY);
                sSequenceLoadState = SEQ_LOAD_BGM_DATA;
                break;
            }
            break;
        case SEQ_LOAD_BGM_DATA:
            PRINTF("==BANDO== SE DATA LOAD END\n");
            loadStatus = AudioThread_GetAsyncLoadStatus(&retMsg);
            switch (loadStatus) {
                case AUDIO_LOAD_FONT_DDBGM_MUTE_CITY:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_MUTE_CITY, 0, AUDIO_LOAD_FONT_DDBGM_SILENCE);
                    PRINTF("==BANDO== DDBGM_MUTE_CITY BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_SILENCE:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_SILENCE, 0, AUDIO_LOAD_FONT_DDBGM_SAND_OCEAN);
                    PRINTF("==BANDO== DDBGM_SILENCE BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_SAND_OCEAN:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_SAND_OCEAN, 0, AUDIO_LOAD_FONT_DDBGM_PORT_TOWN);
                    PRINTF("==BANDO== DDBGM_SAND_OCEAN BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_PORT_TOWN:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_PORT_TOWN, 0, AUDIO_LOAD_FONT_DDBGM_BIG_BLUE);
                    PRINTF("==BANDO== DDBGM_PORT_TOWN BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_BIG_BLUE:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_BIG_BLUE, 0, AUDIO_LOAD_FONT_DDBGM_DEVILS_FOREST);
                    PRINTF("==BANDO== DDBGM_BIG_BLUE BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_DEVILS_FOREST:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_DEVILS_FOREST, 0, AUDIO_LOAD_FONT_DDBGM_RED_CANYON);
                    PRINTF("==BANDO== DDBGM_DEVILS_FOREST BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_RED_CANYON:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_RED_CANYON, 0, AUDIO_LOAD_FONT_DDBGM_SECTOR);
                    PRINTF("==BANDO== DDBGM_RED_CANYON BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_SECTOR:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_SECTOR, 0, AUDIO_LOAD_FONT_DDBGM_WHITE_LAND);
                    PRINTF("==BANDO== DDBGM_SECTOR BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_WHITE_LAND:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_WHITE_LAND, 0, AUDIO_LOAD_FONT_DDBGM_RAINBOW_ROAD);
                    PRINTF("==BANDO== DDBGM_WHITE_LAND BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_RAINBOW_ROAD:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_RAINBOW_ROAD, 0, AUDIO_LOAD_FONT_DDBGM_NEW_03);
                    PRINTF("==BANDO== DDBGM_RAINBOW_ROAD BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_NEW_03:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_NEW_03, 0, AUDIO_LOAD_FONT_DDBGM_NEW_02);
                    PRINTF("==BANDO== DDBGM_NEW_03 BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_NEW_02:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_NEW_02, 0, AUDIO_LOAD_FONT_DDBGM_NEW_01);
                    PRINTF("==BANDO== DDBGM_NEW_02 BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_NEW_01:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_NEW_01, 0, AUDIO_LOAD_FONT_DDBGM_NEW_04);
                    PRINTF("==BANDO== DDBGM_NEW_01 BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_NEW_04:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_NEW_04, 0, AUDIO_LOAD_FONT_DDBGM_TITLE);
                    PRINTF("==BANDO== DDBGM_NEW_04 BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_TITLE:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_TITLE, 0, AUDIO_LOAD_FONT_DDBGM_SELECT);
                    PRINTF("==BANDO== DDBGM_TITLE BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_SELECT:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_SELECT, 0, AUDIO_LOAD_FONT_DDBGM_OPTION);
                    PRINTF("==BANDO== DDBGM_SELECT BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_OPTION:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_OPTION, 0, AUDIO_LOAD_FONT_DDBGM_DEATHRACE);
                    PRINTF("==BANDO== DDBGM_OPTION BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_DEATHRACE:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_DEATHRACE, 0, AUDIO_LOAD_FONT_DDBGM_COURSE_EDITOR);
                    PRINTF("==BANDO== DDBGM_DEATHRACE BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_COURSE_EDITOR:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_COURSE_EDITOR, 0, AUDIO_LOAD_FONT_DDBGM_MACHINE_EDITOR);
                    PRINTF("==BANDO== DDBGM_COURSE_EDITOR BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_MACHINE_EDITOR:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_MACHINE_EDITOR, 0, AUDIO_LOAD_FONT_DDBGM_EAD_DEMO);
                    PRINTF("==BANDO== DDBGM_MACHINE_EDITOR BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_FONT_DDBGM_EAD_DEMO:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(FONT_DDBGM_EAD_DEMO, 0, AUDIO_LOAD_SEQ_DDBGM_MUTE_CITY);
                    PRINTF("==BANDO== DDBGM_EAD_DEMO BANK DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_MUTE_CITY:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_MUTE_CITY, AUDIO_LOAD_SEQ_DDBGM_SILENCE);
                    PRINTF("==BANDO== DDBGM_MUTE_CITY SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_SILENCE:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_SILENCE, AUDIO_LOAD_SEQ_DDBGM_SAND_OCEAN);
                    PRINTF("==BANDO== DDBGM_SILENCE SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_SAND_OCEAN:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_SAND_OCEAN, AUDIO_LOAD_SEQ_DDBGM_PORT_TOWN);
                    PRINTF("==BANDO== DDBGM_SAND_OCEAN SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_PORT_TOWN:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_PORT_TOWN, AUDIO_LOAD_SEQ_DDBGM_BIG_BLUE);
                    PRINTF("==BANDO== DDBGM_PORT_TOWN SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_BIG_BLUE:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_BIG_BLUE, AUDIO_LOAD_SEQ_DDBGM_DEVILS_FOREST);
                    PRINTF("==BANDO== DDBGM_BIG_BLUE SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_DEVILS_FOREST:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_DEVILS_FOREST, AUDIO_LOAD_SEQ_DDBGM_RED_CANYON);
                    PRINTF("==BANDO== DDBGM_DEVILS_FOREST SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_RED_CANYON:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_RED_CANYON, AUDIO_LOAD_SEQ_DDBGM_SECTOR);
                    PRINTF("==BANDO== DDBGM_RED_CANYON SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_SECTOR:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_SECTOR, AUDIO_LOAD_SEQ_DDBGM_WHITE_LAND);
                    PRINTF("==BANDO== DDBGM_SECTOR SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_WHITE_LAND:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_WHITE_LAND, AUDIO_LOAD_SEQ_DDBGM_RAINBOW_ROAD);
                    PRINTF("==BANDO== DDBGM_WHITE_LAND SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_RAINBOW_ROAD:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_RAINBOW_ROAD, AUDIO_LOAD_SEQ_DDBGM_NEW_01);
                    PRINTF("==BANDO== DDBGM_RAINBOW_ROAD SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_NEW_01:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_NEW_01, AUDIO_LOAD_SEQ_DDBGM_NEW_02);
                    PRINTF("==BANDO== DDBGM_NEW_01 SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_NEW_02:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_NEW_02, AUDIO_LOAD_SEQ_DDBGM_NEW_03);
                    PRINTF("==BANDO== DDBGM_NEW_02 SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_NEW_03:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_NEW_03, AUDIO_LOAD_SEQ_DDBGM_NEW_04);
                    PRINTF("==BANDO== DDBGM_NEW_03 SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_NEW_04:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_NEW_04, AUDIO_LOAD_SEQ_DDBGM_TITLE);
                    PRINTF("==BANDO== DDBGM_NEW_04 SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_TITLE:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_TITLE, AUDIO_LOAD_SEQ_DDBGM_SELECT);
                    PRINTF("==BANDO== DDBGM_TITLE SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_SELECT:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_SELECT, AUDIO_LOAD_SEQ_DDBGM_OPTION);
                    PRINTF("==BANDO== DDBGM_SELECT SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_OPTION:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_OPTION, AUDIO_LOAD_SEQ_DDBGM_DEATHRACE);
                    PRINTF("==BANDO== DDBGM_OPTION SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_DEATHRACE:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_DEATHRACE, AUDIO_LOAD_SEQ_DDBGM_COURSE_EDITOR);
                    PRINTF("==BANDO== DDBGM_DEATHRACE SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_COURSE_EDITOR:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_COURSE_EDITOR, AUDIO_LOAD_SEQ_DDBGM_MACHINE_EDITOR);
                    PRINTF("==BANDO== DDBGM_COURSE_EDITOR SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_MACHINE_EDITOR:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_MACHINE_EDITOR, AUDIO_LOAD_SEQ_DDBGM_EAD_DEMO);
                    PRINTF("==BANDO== DDBGM_MACHINE_EDITOR SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_SEQ_DDBGM_EAD_DEMO:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(SEQ_DDBGM_EAD_DEMO, AUDIO_LOAD_COMPLETE);
                    PRINTF("==BANDO== DDBGM_EAD_DEMO SEQ DATA LOAD END\n");
                    break;
                case AUDIO_LOAD_COMPLETE:
                    sSequenceLoadState = SEQ_LOAD_INACTIVE;
                    break;
            }
            break;
        case SEQ_LOAD_INACTIVE:
        default:
            break;
    }
}

// Na_Init_Editor
void Audio_EditorInit(void) {
    PRINTF("==BANDO== Na_Init_Editor Called\n");
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 200);
    Audio_DDBgmReadyInter(BGM_COURSE_EDITOR);
    D_80771C8C = 1;
    Audio_SetPlayerMode(0);
}

void Audio_EditorBgmDelaySet(void) {

    PRINTF("==BANDO== dd_editor_bgm_delay_set -- SEQ START\n");

    if (D_80771C8C == 0) {
        return;
    }

    D_80771C8C++;
    if ((D_80771C8C > 180) && (D_80771C7C == 0)) {
        if (D_800D11C8[2] == 1) {
            AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, SEQ_DDBGM_COURSE_EDITOR, 0, 0);
            D_80771C74 = 1;
            sActiveBgm = BGM_COURSE_EDITOR;
        }
        D_80771C8C = 0;
        D_80771C94 = 1;
    }
}

// Na_Init_Editor2
void Audio_Editor2Init(void) {
    PRINTF("==BANDO== Na_Init_Editor2 Called\n");
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 100);
    Audio_DDBgmReadyInter(BGM_MACHINE_EDITOR);
    D_80771C90 = 1;
    Audio_SetPlayerMode(0);
}

void Audio_Editor2BgmDelaySet(void) {

    PRINTF("==BANDO== dd_editor2_bgm_delay_set -- SEQ START\n");

    if (D_80771C90 == 0) {
        return;
    }

    D_80771C90++;
    if ((D_80771C90 > 150) && (D_80771C7C == 0)) {
        if (D_800D11C8[2] == 1) {
            AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, SEQ_DDBGM_MACHINE_EDITOR, 0, 0);
            sActiveBgm = BGM_MACHINE_EDITOR;
        }
        D_80771C90 = 0;
        D_80771C94 = 1;
    }
    AudioThread_ScheduleProcessCmds();
}

// Na_Exit_Editor
void Audio_EditorExit(void) {
    PRINTF("==BANDO== Na_Exit_Editor Called\n");
    Audio_TriggerSystemSE(NA_SE_16);
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 100);
    Audio_DDBgmReady(BGM_SELECT);
    D_80771C94 = 0;
    AudioThread_ScheduleProcessCmds();
}

// Na_Editor_Bgm_Stop
void Audio_EditorBgmStop(void) {
    PRINTF("==BANDO== Na_Editor_Bgm_Stop Called \n");
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 200);
}

// Na_Editor_Bgm_Restart
void Audio_EditorBgmRestart(void) {
    PRINTF("==BANDO== Na_Editor_Bgm_Restart Called \n");
    if (D_800D11C8[2] == 1) {
        AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, SEQ_DDBGM_COURSE_EDITOR, 0, 0);
        D_80771C74 = 1;
        sActiveBgm = BGM_COURSE_EDITOR;
    }
}

void Audio_BgmFadeout(void) {
    f32 volumeScale;

    switch (sBgmPlayState) {
        case 1:
            sBgmFadeoutTimer++;
            if (sBgmFadeoutTimer == 34) {
                PRINTF("==BANDO== BGM FADEOUT1 COMPLETE ROUTINE\n");
                sBgmPlayState = 0;
                sBgmFadeoutTimer = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                Audio_StopChannelSE(0);
            } else {
                volumeScale = 1.0f - (sBgmFadeoutTimer * (1.0f / 35.0f));
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }

            break;
        case 2:
            sBgmFadeoutTimer++;
            if (sBgmFadeoutTimer == 69) {
                PRINTF("==BANDO== BGM FADEOUT2 COMPLETE ROUTINE\n");
                sBgmPlayState = 0;
                sBgmFadeoutTimer = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                Audio_StopChannelSE(0);
            } else {
                volumeScale = 1.0f - (sBgmFadeoutTimer * (1.0f / 70.0f));
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
            break;
        case 3:
            sBgmFadeoutTimer++;
            if (sBgmFadeoutTimer == 349) {
                PRINTF("==BANDO== BGM FADEOUT3 COMPLETE ROUTINE\n");
                sBgmPlayState = 0;
                sBgmFadeoutTimer = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                Audio_StopChannelSE(0);
            } else {
                volumeScale = 1.0f - (sBgmFadeoutTimer * (1.0f / 350.0f));
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
            break;
        case 0:
        default:
            break;
    }
}

void Audio_LevelSEFadeoutRoutine(void) {
    f32 volumeScale;
    s8 reverbVolume;

    if (!sAudioLevelFadeoutActive || sAudioPauseStatus == AUDIO_PAUSE_TRANSITION) {
        return;
    }

    sLevelFadeoutTimer++;
    if (sLevelFadeoutTimer == 29) {
        PRINTF("==BANDO== LEVEL SE FADEOUT COMPLETE ROUTINE\n");
        sAudioLevelFadeoutActive = false;
        sLevelFadeoutTimer = 0;
        Audio_StopChannelSE(2);
        Audio_StopChannelSE(3);
        Audio_StopChannelSE(4);
        Audio_StopChannelSE(5);
        Audio_StopChannelSE(6);
        Audio_StopChannelSE(7);
        Audio_StopChannelSE(8);
        Audio_StopChannelSE(9);
        Audio_StopChannelSE(14);
        sPlayerEngineSoundState[0] = 0;
        sPlayerEngineSoundState[1] = 0;
        sPlayerEngineSoundState[2] = 0;
        sPlayerEngineSoundState[3] = 0;
        return;
    }
    reverbVolume = 80 - (sLevelFadeoutTimer * 2);
    if (sPlayerEngineSoundState[0] == 1) {
        volumeScale = sChannelVolume[2] - ((sChannelVolume[2] / 30.0f) * sLevelFadeoutTimer);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 2, volumeScale);
        if (sPlayerEngineEchoSoundState[0] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, reverbVolume);
        }
    }
    if (sPlayerEngineSoundState[1] == 1) {
        volumeScale = sChannelVolume[3] - ((sChannelVolume[3] / 30.0f) * sLevelFadeoutTimer);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 3, volumeScale);
        if (sPlayerEngineEchoSoundState[1] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, reverbVolume);
        }
    }
    if (sPlayerEngineSoundState[2] == 1) {
        volumeScale = sChannelVolume[4] - ((sChannelVolume[4] / 30.0f) * sLevelFadeoutTimer);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 4, volumeScale);
        if (sPlayerEngineEchoSoundState[2] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, reverbVolume);
        }
    }
    if (sPlayerEngineSoundState[3] == 1) {
        volumeScale = sChannelVolume[5] - ((sChannelVolume[5] / 30.0f) * sLevelFadeoutTimer);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 5, volumeScale);
        if (sPlayerEngineEchoSoundState[3] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 5, reverbVolume);
        }
    }
    if ((sPlayerEngineSoundState[0] != 0) && (sActivePlayerLevelSE[0][0] != 0) && (sChannelVolume[6] != 0.0f)) {
        volumeScale = sChannelVolume[6] - ((sChannelVolume[6] / 30.0f) * sLevelFadeoutTimer);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 6, volumeScale);
        if (sPlayerEngineEchoSoundState[0] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, reverbVolume);
        }
    }
    if ((sPlayerEngineSoundState[1] != 0) && (sActivePlayerLevelSE[1][0] != 0) && (sChannelVolume[7] != 0.0f)) {
        volumeScale = sChannelVolume[7] - ((sChannelVolume[7] / 30.0f) * sLevelFadeoutTimer);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 7, volumeScale);
        if (sPlayerEngineEchoSoundState[1] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, reverbVolume);
        }
    }
    if ((sPlayerEngineSoundState[2] != 0) && (sActivePlayerLevelSE[2][0] != 0) && (sChannelVolume[8] != 0.0f)) {
        volumeScale = sChannelVolume[8] - ((sChannelVolume[8] / 30.0f) * sLevelFadeoutTimer);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 8, volumeScale);
        if (sPlayerEngineEchoSoundState[2] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, reverbVolume);
        }
    }
    if ((sPlayerEngineSoundState[3] != 0) && (sActivePlayerLevelSE[3][0] != 0) && (sChannelVolume[9] != 0.0f)) {
        volumeScale = sChannelVolume[9] - ((sChannelVolume[9] / 30.0f) * sLevelFadeoutTimer);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 9, volumeScale);
        if (sPlayerEngineEchoSoundState[3] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 9, reverbVolume);
        }
    }
    if ((sAudioEnemyEngineStatus != 0) && (sChannelVolume[14] != 0.0f)) {
        volumeScale = sChannelVolume[14] - ((sChannelVolume[14] / 30.0f) * sLevelFadeoutTimer);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, volumeScale);
        if (sPlayerEngineEchoSoundState[0] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, reverbVolume);
        }
    }
}

void Audio_BgmFadeoutPause(void) {
    f32 volumeScale;

    if (sAudioPauseStatus == AUDIO_PAUSE_TRANSITION) {
        sBgmPauseFadeoutTimer++;
        if (sBgmPauseFadeoutTimer == 49) {
            PRINTF("==BANDO== BGM FADEOUT COMPLETE ROUTINE (in the PAUSE ROUTINE)\n");
            sAudioPauseStatus = AUDIO_PAUSE_UNPAUSED;
            sBgmPauseFadeoutTimer = 0;
            Audio_StopChannelSE(0);
        } else {
            volumeScale = 0.4f - (sBgmPauseFadeoutTimer * 0.008f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
        }
    }
}

void Audio_LevelSEStart(u8 playerIndex, u8 sfxId) {

    PRINTF("==BANDO== LEVEL SE INTERNAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);

    if (sActivePlayerLevelSE[playerIndex][0] == NA_LEVEL_SE_NONE) {
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][1] == NA_LEVEL_SE_NONE) {
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][2] == NA_LEVEL_SE_NONE) {
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][3] == NA_LEVEL_SE_NONE) {
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][4] == NA_LEVEL_SE_NONE) {
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][5] == NA_LEVEL_SE_NONE) {
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][6] == NA_LEVEL_SE_NONE) {
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][7] == NA_LEVEL_SE_NONE) {
        sActivePlayerLevelSE[playerIndex][7] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    }
    switch (sAudioPlayerMode) {
        case 0:
            AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0x3F);
            PRINTF("==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
            Audio_SEStart(6, sfxId);
            break;
        case 1:
            switch (playerIndex) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    PRINTF("==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex,
                           LEVEL_SE_2P(sfxId));
                    Audio_SEStart(6, LEVEL_SE_2P(sfxId));
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0x7F);
                    PRINTF("==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex,
                           LEVEL_SE_2P(sfxId));
                    Audio_SEStart(7, LEVEL_SE_2P(sfxId));
                    break;
            }
            break;
        case 2:
            switch (playerIndex) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    PRINTF("==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex,
                           LEVEL_SE_MP(sfxId));
                    Audio_SEStart(6, LEVEL_SE_MP(sfxId));
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0);
                    PRINTF("==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex,
                           LEVEL_SE_MP(sfxId));
                    Audio_SEStart(7, LEVEL_SE_MP(sfxId));
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 8, 0x7F);
                    PRINTF("==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex,
                           LEVEL_SE_MP(sfxId));
                    Audio_SEStart(8, LEVEL_SE_MP(sfxId));
                    break;
            }
            break;
        case 3:
            switch (playerIndex) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    PRINTF("==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex,
                           LEVEL_SE_MP(sfxId));
                    Audio_SEStart(6, LEVEL_SE_MP(sfxId));
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0);
                    PRINTF("==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex,
                           LEVEL_SE_MP(sfxId));
                    Audio_SEStart(7, LEVEL_SE_MP(sfxId));
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 8, 0x7F);
                    PRINTF("==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex,
                           LEVEL_SE_MP(sfxId));
                    Audio_SEStart(8, LEVEL_SE_MP(sfxId));
                    break;
                case 3:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 9, 0x7F);
                    PRINTF("==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex,
                           LEVEL_SE_MP(sfxId));
                    Audio_SEStart(9, LEVEL_SE_MP(sfxId));
                    break;
            }
            break;
    }
}

void Audio_LevelSEPopStack(u8 playerIndex) {

    if (D_80771CA8 == 1) {
        return;
    }

    if (sAudioLevelSEStack[playerIndex][0] != NA_LEVEL_SE_NONE) {
        Audio_LevelSEStart(playerIndex, sAudioLevelSEStack[playerIndex][0]);
        sAudioLevelSEStack[playerIndex][0] = sAudioLevelSEStack[playerIndex][1];
        sAudioLevelSEStack[playerIndex][1] = sAudioLevelSEStack[playerIndex][2];
        sAudioLevelSEStack[playerIndex][2] = sAudioLevelSEStack[playerIndex][3];
        sAudioLevelSEStack[playerIndex][3] = NA_LEVEL_SE_NONE;
    }
}

void Audio_PlayerSEStart(u8 racerId, u8 sfxId) {
    f32 volumeScale;
    f32 freqScale;
    f32 distance;
    Vec3f vec;
    u8 pan;

    if ((sPlayerEngineSoundState[racerId] == 0) &&
        !((sfxId == NA_SE_22) || (sfxId == NA_SE_16) || (sfxId == NA_SE_33) || (sfxId == NA_SE_30) ||
          (sfxId == NA_SE_5) || (sfxId == NA_SE_8) || (sfxId == NA_SE_15) || (sfxId == NA_SE_48) ||
          (sfxId == NA_SE_49) || (sfxId == NA_SE_52) || (sfxId == NA_SE_53) || (sfxId == NA_SE_62))) {
        PRINTF("==BANDO== Ouch!! UN-SUPORTED TRG SE NUM WAS CALLED !!!!!!! num = %02x\n", sfxId);
        return;
    }
    sRacerActiveSE[racerId] = sfxId;
    switch (sAudioPlayerMode) {
        case 0:
            if (racerId == 0) {
                AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0x3F);
                volumeScale = sRacerAudioVolume[racerId];
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);

                if (sfxId >= NA_SE_PLAYER_MAX || sfxId < NA_SE_NONE) {
                    sfxId = NA_SE_NONE;
                }
                Audio_SEStart(10, sfxId);
            } else if (sAudioEnemyEngineStatus != 0) {
                if (racerId == sAudioClosestRacerId) {
                    distance = sAudioClosestRacerDistance;
                } else {
                    vec.x = gRacers[racerId].segmentPositionInfo.pos.x - gCameras[0].eye.x;
                    vec.y = gRacers[racerId].segmentPositionInfo.pos.y - gCameras[0].eye.y;
                    vec.z = gRacers[racerId].segmentPositionInfo.pos.z - gCameras[0].eye.z;

                    distance = sqrtf(SQ_SUM(&vec));
                }
                if ((distance < 10000.0f) && (distance > 0.0f)) {
                    volumeScale = (-(9.0f / 190000.0f) * distance) + 0.87f;
                    if (volumeScale > 0.24f) {
                        if (volumeScale > 0.68f) {
                            volumeScale = 0.68f;
                        }

                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 15, volumeScale);
                        if (racerId == sAudioClosestRacerId) {
                            freqScale = (sEnemyEngineFreqScale * (2.0f / 7.0f)) + 0.2f;
                        } else {
                            freqScale = volumeScale * 1.2f;
                        }
                        if (freqScale > 2.0f) {
                            freqScale = 2.0f;
                        }
                        if (freqScale < 0.1f) {
                            freqScale = 0.1f;
                        }

                        AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, 15, freqScale);

                        if (racerId == sAudioClosestRacerId) {
                            pan = Audio_AdjustPan(sEnemyEngineLinearPan);
                        } else {
                            pan = 0x3F;
                        }
                        AUDIOCMD_CHANNEL_SET_PAN(0, 15, pan);
                        Audio_SEStart(15, sfxId);
                    }
                }
            }
            break;
        case 1:
            volumeScale = sRacerAudioVolume[racerId] * 0.975f;
            switch (racerId) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0);
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);
                    Audio_SEStart(10, sfxId);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 11, 0x7F);
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 11, volumeScale);
                    Audio_SEStart(11, sfxId);
                    break;
            }
            break;
        case 2:
            volumeScale = sRacerAudioVolume[racerId] * 0.95f;
            switch (racerId) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0);
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);
                    Audio_SEStart(10, sfxId);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 11, 0);
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 11, volumeScale);
                    Audio_SEStart(11, sfxId);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 12, 0x7F);
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 12, volumeScale);
                    Audio_SEStart(12, sfxId);
                    break;
            }
            break;
        case 3:
            volumeScale = sRacerAudioVolume[racerId] * 0.95f;
            switch (racerId) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0);
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);
                    Audio_SEStart(10, sfxId);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 11, 0);
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 11, volumeScale);
                    Audio_SEStart(11, sfxId);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 12, 0x7F);
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 12, volumeScale);
                    Audio_SEStart(12, sfxId);
                    break;
                case 3:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 13, 0x7F);
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 13, volumeScale);
                    Audio_SEStart(13, sfxId);
                    break;
            }
            break;
    }
}

void Audio_PlayerSEPopStack(u8 racerId) {

    if (sAudioPlayerSEStack[racerId][0] != 0) {
        PRINTF("==BANDO== SE SEQ START\n");
        Audio_PlayerSEStart(racerId, sAudioPlayerSEStack[racerId][0]);
        sAudioPlayerSEStack[racerId][0] = sAudioPlayerSEStack[racerId][1];
        sAudioPlayerSEStack[racerId][1] = sAudioPlayerSEStack[racerId][2];
        sAudioPlayerSEStack[racerId][2] = sAudioPlayerSEStack[racerId][3];
        sAudioPlayerSEStack[racerId][3] = 0;
    }
}

extern s32 gNumPlayers;
extern s8 gTitleDemoState;
extern s32 gGameMode;

void func_807442E4(void) {
    s32 temp_lo;
    SequenceLayer* layer;
    Note* note;

    if ((sActiveBgm == BGM_TITLE) && (IS_SEQUENCE_CHANNEL_VALID(gAudioCtx.seqPlayers[1].channels[0]))) {
        layer = gAudioCtx.seqPlayers[1].channels[0]->layers[0];
        if (layer != NULL) {
            note = layer->note;
            if (note != NULL) {
                temp_lo = (s32) note->synthesisState.samplePosInt / 100;

                switch (gNumPlayers) {
                    case 1:
                    case 2:
                        break;
                    default:
                        // FAKE
                        if (note && note && note) {}
                        break;
                }

                if ((temp_lo > 2100) && (temp_lo < 2110) && (gGameMode == GAMEMODE_FLX_TITLE) &&
                    (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
                    if (!note) {}
                    gTitleDemoState = TITLE_DEMO_ACTIVE;
                }
                if ((temp_lo > 8200) && (temp_lo < 8210) && (gTitleDemoState == TITLE_DEMO_ACTIVE)) {
                    gTitleDemoState = TITLE_DEMO_START_EXIT;
                }
                if (temp_lo > 250 && temp_lo < 260) {
                    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(0, SEQ_SOUND_EFFECTS, 0, 0);
                }
            }
        }
    }
}

void Audio_UpdateEnemyEngine(void) {
    Vec3f vec;

    if (sAudioRetireStatus == 1) {
        return;
    }

    if (sAudioPlayerMode != 0) {
        return;
    }

    if (sAudioClosestRacerId == 0) {
        return;
    }

    if (sAudioPauseStatus == AUDIO_PAUSE_PAUSED || sAudioPauseStatus == AUDIO_PAUSE_TRANSITION) {
        return;
    }

    if (((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) &&
        !sAudioLevelFadeoutActive && (gAudioPlayerFinishedState[0] == 0)) {
        if (gRacers[sAudioClosestRacerId].unk_17C > 9.0f) {
            vec.x = gRacers[sAudioClosestRacerId].segmentPositionInfo.pos.x - gCameras[0].eye.x;
            vec.y = gRacers[sAudioClosestRacerId].segmentPositionInfo.pos.y - gCameras[0].eye.y;
            vec.z = gRacers[sAudioClosestRacerId].segmentPositionInfo.pos.z - gCameras[0].eye.z;
            sAudioClosestRacerDistance = sqrtf(SQ_SUM(&vec));
        }
        if (gRacers[sAudioClosestRacerId].unk_17C > 9.0f) {
            if ((sAudioClosestRacerDistance < 820.0f) && (sAudioClosestRacerDistance != 0.0f)) {
                if (sAudioEnemyEngineStatus == 0) {
                    if (gAudioPlayerFinishedState[0] == 0) {
                        if (!sAudioDisableEnemyEngineSound) {
                            PRINTF("==BANDO== ENEMY ENGINE START MACHINE No.= %02x\n", sAudioClosestRacerId);
                            Audio_SEStart(14, NA_LEVEL_SE_1);
                        }
                        sAudioEnemyEngineStatus = 2;
                    }
                } else {
                    sAudioEnemyEngineStatus = 1;
                }
            } else {
                if (sAudioEnemyEngineStatus == 1) {
                    PRINTF("==BANDO== ENEMY ENGINE STOP!\n");
                    Audio_StopChannelSE(14);
                    sAudioEnemyEngineStatus = 0;
                }
            }
        }
        if (sAudioEnemyEngineStatus != 0) {
            sEnemyEngineVolume = 1.0f - (sAudioClosestRacerDistance * (1.0f / 1000.0f));
            if (sEnemyEngineVolume > 0.9f) {
                sEnemyEngineVolume = 0.9f;
            }
            if (sEnemyEngineVolume < 0.001f) {
                sEnemyEngineVolume = 0.001f;
            }
            if (sAudioClosestRacerId == sAudioPreviousClosestRacerId) {
                D_80771B0C = (sAudioPreviousClosestRacerDistance - sAudioClosestRacerDistance) * (1.0f / 30.0f);
            }
            sAudioPreviousClosestRacerDistance = sAudioClosestRacerDistance;
            sAudioPreviousClosestRacerId = sAudioClosestRacerId;

            sEnemyEngineFreqScale =
                ((gRacers[sAudioClosestRacerId].speed + 0.01f) * (1.0f / 21.0f)) + 0.5f + D_80771B0C;
            if (sEnemyEngineFreqScale < 0.1f) {
                sEnemyEngineFreqScale = 0.1f;
            }

            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, sEnemyEngineVolume);
            sChannelVolume[14] = sEnemyEngineVolume;
            AUDIOCMD_CHANNEL_SET_PAN(0, 14, Audio_AdjustPan(sEnemyEngineLinearPan));
            AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, 14, sEnemyEngineFreqScale);
        }
    }
}

void func_807447CC(u8 playerId) {
    f32 freqScale;
    f32 volumeScale;

    if (sAudioPauseStatus == AUDIO_PAUSE_PAUSED || sAudioPauseStatus == AUDIO_PAUSE_TRANSITION) {
        return;
    }

    if (sPlayerEngineSoundState[playerId] == 0) {
        if (D_80771B74[playerId] == 0) {
            return;
        }
    }

    if (gRacers[playerId].speed < D_80771B5C[playerId]) {
        D_80771B58[playerId] = 1;
    } else {
        D_80771B58[playerId] = 0;
    }
    D_80771B5C[playerId] = gRacers[playerId].speed;
    if (D_80771B74[playerId] == 0) {
        if ((gRacers[playerId].accelerationForce != 0.0f) && (gRacers[playerId].speed > 27.0f)) {
            if (D_80771B58[playerId] == 1) {
                if (D_80771B44[playerId] > -0.5f) {
                    D_80771B44[playerId] -= 0.004f;
                }
            } else {
                D_80771B44[playerId] += 0.004f;
            }
        } else {
            D_80771B44[playerId] = 0.0f;
        }
        if (gRacers[playerId].unk_20C != 0) {
            D_80771B44[playerId] = 0.0f;
        }
    } else {
        // FAKE
    }

    freqScale = (((0.01f + gRacers[playerId].speed) * (1.0f / 21.0f)) + 0.25f) + D_80771B44[playerId];
    AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, playerId + 2, freqScale);

    if ((gRacers[playerId].accelerationForce == 0.0f) && (gRacers[playerId].driftAttackForce == 0.0f)) {
        if (D_80771B74[playerId] == 1) {
            Vec3f vec;
            f32 temp;

            vec.x = gRacers[playerId].segmentPositionInfo.pos.x - gCameras[playerId].eye.x;
            vec.y = gRacers[playerId].segmentPositionInfo.pos.y - gCameras[playerId].eye.y;
            vec.z = gRacers[playerId].segmentPositionInfo.pos.z - gCameras[playerId].eye.z;
            temp = sqrtf(SQ_SUM(&vec));
            volumeScale = (-0.002f * temp + 1.2f) * 0.65f;

            if (volumeScale > 0.7f) {
                volumeScale = 0.7f;
            }
            if (volumeScale < 0.01f) {
                volumeScale = 0.01f;
            }
        } else {
            volumeScale = 0.75f;
        }
    } else {
        if (D_80771B74[playerId] == 1) {
            Vec3f vec;
            f32 temp;

            vec.x = gRacers[playerId].segmentPositionInfo.pos.x - gCameras[playerId].eye.x;
            vec.y = gRacers[playerId].segmentPositionInfo.pos.y - gCameras[playerId].eye.y;
            vec.z = gRacers[playerId].segmentPositionInfo.pos.z - gCameras[playerId].eye.z;
            temp = sqrtf(SQ_SUM(&vec));
            volumeScale = -0.002f * temp + 1.2f;

            if (volumeScale > 0.73f) {
                volumeScale = 0.73f;
            }
            if (volumeScale < 0.01f) {
                volumeScale = 0.01f;
            }
        } else {
            volumeScale = 1.0f;
        }
    }

    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, playerId + 2, volumeScale);
    sChannelVolume[playerId + 2] = volumeScale;
}

void func_80744BDC(u8 playerIndex) {
    f32 freqScale;
    f32 volumeScale;

    if (D_80771CA8 == 1) {
        return;
    }

    if (gAudioPlayerFinishedState[playerIndex] != 0) {
        if (gAudioPlayerFinishedState[playerIndex] < 8) {
            gAudioPlayerFinishedState[playerIndex] += 1;
        }

        if (gAudioPlayerFinishedState[playerIndex] == 8) {
            Audio_StopChannelSE(playerIndex + 2);
            Audio_StopChannelSE(playerIndex + 6);
        }
    }

    if (sAudioPauseStatus == AUDIO_PAUSE_PAUSED || sAudioPauseStatus == AUDIO_PAUSE_TRANSITION) {
        return;
    }

    if ((sPlayerEngineSoundState[playerIndex] == 0) || sAudioLevelFadeoutActive) {
        return;
    }

    switch (sActivePlayerLevelSE[playerIndex][0]) {
        case 0:
            volumeScale = 0.0f;
            freqScale = 1.0f;
            break;
        case 3:
        case 13:
        case 23:
        case 4:
        case 14:
        case 24:
        case 10:
        case 20:
        case 30:
            volumeScale = 1.0f;
            freqScale = 1.0f;
            break;
        case 5:
        case 15:
        case 25:
            volumeScale = (gRacers[playerIndex].speed * (1.0f / 45.0f)) + 0.5f;
            if (gRacers[playerIndex].speed < 0.1f) {
                volumeScale = 0.0f;
            }
            if (volumeScale > 1.0f) {
                volumeScale = 1.0f;
            }
            if (volumeScale < 0.1f) {
                volumeScale = 0.0f;
            }
            freqScale = 1.0f;
            break;
        case 11:
        case 21:
        case 31:
            volumeScale = (gRacers[playerIndex].speed * (1.0f / 45.0f)) + 0.5f;
            if (gRacers[playerIndex].speed < 0.1f) {
                volumeScale = 0.0f;
            }
            if (volumeScale > 1.0f) {
                volumeScale = 1.0f;
            }
            if (volumeScale < 0.1f) {
                volumeScale = 0.0f;
            }
            freqScale = 1.0f;
            break;
        case 8:
        case 18:
        case 28:
            volumeScale = 0.8f;
            freqScale = (gRacers[playerIndex].speed * (1.0f / 30.0f)) - (8.0f / 10.0f);
            if (freqScale > 2.5f) {
                freqScale = 2.5f;
            }
            if (freqScale < 0.3f) {
                freqScale = 0.3f;
            }
            break;
        case 9:
        case 19:
        case 29:
            volumeScale = 0.85f;
            freqScale = gRacers[playerIndex].speed * (1.0f / 20.0f);
            if (freqScale > 8.0f) {
                freqScale = 8.0f;
            }
            if (freqScale < 0.1f) {
                freqScale = 0.1f;
            }
            break;
        case 6:
        case 16:
        case 26:
            if (gRacers[playerIndex].unk_5C.x > 0.0f) {
                volumeScale = gRacers[playerIndex].unk_5C.x * (2.0f / 30.0f);
                freqScale = (gRacers[playerIndex].unk_5C.x * (1.0f / 80.0f)) + 1.0f;
                if (volumeScale > 1.0f) {
                    volumeScale = 1.0f;
                }
                if (volumeScale < 0.1f) {
                    volumeScale = 0.0f;
                }
                if (freqScale > 1.3f) {
                    freqScale = 1.3f;
                }
                if (freqScale < 0.3f) {
                    freqScale = 0.3f;
                }
            } else {
                volumeScale = -gRacers[playerIndex].unk_5C.x * (1.0f / 15.0f);
                freqScale = (-gRacers[playerIndex].unk_5C.x * (1.0f / 80.0f)) + 1.0f;
                if (volumeScale > 1.0f) {
                    volumeScale = 1.0f;
                }
                if (volumeScale < 0.1f) {
                    volumeScale = 0.0f;
                }
                if (freqScale > 1.3f) {
                    freqScale = 1.3f;
                }
                if (freqScale < 0.3f) {
                    freqScale = 0.3f;
                }
            }
            break;
    }

    sChannelVolume[playerIndex + 6] = volumeScale;
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, playerIndex + 6, volumeScale);
    AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, playerIndex + 6, freqScale);
}

void Audio_UpdateReverb(u8 playerIndex) {
    switch (sAudioPlayerMode) {
        case 0:
            if (sPlayerEngineEchoSoundState[0] == 1) {
                gAudioCtx.synthesisReverbs[0].volume = 0x7FFF;
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, 80);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 15, 80);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((sRacerActiveSE[0] == NA_SE_LOW_ENERGY_SLOW) || (sRacerActiveSE[0] == NA_SE_LOW_ENERGY_MEDIUM) ||
                    (sRacerActiveSE[0] == NA_SE_LOW_ENERGY_FAST)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((sActivePlayerLevelSE[0][0] == 3) || (sActivePlayerLevelSE[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                gAudioCtx.synthesisReverbs[0].volume = 0;
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 15, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            break;
        case 1:
            if ((sPlayerEngineEchoSoundState[0] == 1) || (sPlayerEngineEchoSoundState[1] == 1)) {
                gAudioCtx.synthesisReverbs[0].volume = 0x7FFF;
            } else {
                gAudioCtx.synthesisReverbs[0].volume = 0;
            }
            if (sPlayerEngineEchoSoundState[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((sRacerActiveSE[0] == NA_SE_LOW_ENERGY_SLOW) || (sRacerActiveSE[0] == NA_SE_LOW_ENERGY_MEDIUM) ||
                    (sRacerActiveSE[0] == NA_SE_LOW_ENERGY_FAST)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((sActivePlayerLevelSE[0][0] == 3) || (sActivePlayerLevelSE[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            if (sPlayerEngineEchoSoundState[1] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 80);
                if ((sRacerActiveSE[1] == NA_SE_LOW_ENERGY_SLOW) || (sRacerActiveSE[1] == NA_SE_LOW_ENERGY_MEDIUM) ||
                    (sRacerActiveSE[1] == NA_SE_LOW_ENERGY_FAST)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 80);
                }
                if ((sActivePlayerLevelSE[1][0] == 3) || (sActivePlayerLevelSE[1][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
            }
            break;
        case 2:
            if ((sPlayerEngineEchoSoundState[0] == 1) || (sPlayerEngineEchoSoundState[1] == 1) ||
                (sPlayerEngineEchoSoundState[2] == 1)) {
                gAudioCtx.synthesisReverbs[0].volume = 0x7FFF;
            } else {
                gAudioCtx.synthesisReverbs[0].volume = 0;
            }
            if (sPlayerEngineEchoSoundState[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((sRacerActiveSE[0] == NA_SE_LOW_ENERGY_SLOW) || (sRacerActiveSE[0] == NA_SE_LOW_ENERGY_MEDIUM) ||
                    (sRacerActiveSE[0] == NA_SE_LOW_ENERGY_FAST)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((sActivePlayerLevelSE[0][0] == 3) || (sActivePlayerLevelSE[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            if (sPlayerEngineEchoSoundState[1] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 80);
                if ((sRacerActiveSE[1] == NA_SE_LOW_ENERGY_SLOW) || (sRacerActiveSE[1] == NA_SE_LOW_ENERGY_MEDIUM) ||
                    (sRacerActiveSE[1] == NA_SE_LOW_ENERGY_FAST)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 80);
                }
                if ((sActivePlayerLevelSE[1][0] == 3) || (sActivePlayerLevelSE[1][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
            }
            if (sPlayerEngineEchoSoundState[2] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 80);
                if ((sRacerActiveSE[2] == NA_SE_LOW_ENERGY_SLOW) || (sRacerActiveSE[2] == NA_SE_LOW_ENERGY_MEDIUM) ||
                    (sRacerActiveSE[2] == NA_SE_LOW_ENERGY_FAST)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 80);
                }
                if ((sActivePlayerLevelSE[2][0] == 3) || (sActivePlayerLevelSE[2][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
            }
            break;
        case 3:
            if ((sPlayerEngineEchoSoundState[0] == 1) || (sPlayerEngineEchoSoundState[1] == 1) ||
                (sPlayerEngineEchoSoundState[2] == 1) || (sPlayerEngineEchoSoundState[3] == 1)) {
                gAudioCtx.synthesisReverbs[0].volume = 0x7FFF;
            } else {
                gAudioCtx.synthesisReverbs[0].volume = 0;
            }
            if (sPlayerEngineEchoSoundState[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((sRacerActiveSE[0] == NA_SE_LOW_ENERGY_SLOW) || (sRacerActiveSE[0] == NA_SE_LOW_ENERGY_MEDIUM) ||
                    (sRacerActiveSE[0] == NA_SE_LOW_ENERGY_FAST)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((sActivePlayerLevelSE[0][0] == 3) || (sActivePlayerLevelSE[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            if (sPlayerEngineEchoSoundState[1] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 80);
                if ((sRacerActiveSE[1] == NA_SE_LOW_ENERGY_SLOW) || (sRacerActiveSE[1] == NA_SE_LOW_ENERGY_MEDIUM) ||
                    (sRacerActiveSE[1] == NA_SE_LOW_ENERGY_FAST)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 80);
                }
                if ((sActivePlayerLevelSE[1][0] == 3) || (sActivePlayerLevelSE[1][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
            }
            if (sPlayerEngineEchoSoundState[2] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 80);
                if ((sRacerActiveSE[2] == NA_SE_LOW_ENERGY_SLOW) || (sRacerActiveSE[2] == NA_SE_LOW_ENERGY_MEDIUM) ||
                    (sRacerActiveSE[2] == NA_SE_LOW_ENERGY_FAST)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 80);
                }
                if ((sActivePlayerLevelSE[2][0] == 3) || (sActivePlayerLevelSE[2][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
            }
            if (sPlayerEngineEchoSoundState[3] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 5, 80);
                if ((sRacerActiveSE[3] == NA_SE_LOW_ENERGY_SLOW) || (sRacerActiveSE[3] == NA_SE_LOW_ENERGY_MEDIUM) ||
                    (sRacerActiveSE[3] == NA_SE_LOW_ENERGY_FAST)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 13, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 13, 80);
                }
                if ((sActivePlayerLevelSE[3][0] == 3) || (sActivePlayerLevelSE[3][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 9, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 9, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 5, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 13, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 9, 0);
            }
            break;
    }
}

void Audio_VoiceSEPopStack(void) {

    if ((sActiveVoiceSE == 0) && (sVoiceSEStack1 != 0)) {
        PRINTF("==BANDO== len = %d\n", sVoiceSEStackTimer1); // Unsure on print location
        Audio_SystemSEStart(sVoiceSEStack1);
    }

    sActiveVoiceSE = sVoiceSEStack1;
    if (sVoiceSEStackTimer1 != 0) {
        sVoiceSEStackTimer1--;
        if (sVoiceSEStackTimer1 == 0) {
            sVoiceSEStack1 = sVoiceSEStack2;
            sVoiceSEStackTimer1 = sVoiceSEStackTimer2;
            sVoiceSEStack2 = sVoiceSEStack3;
            sVoiceSEStackTimer2 = sVoiceSEStackTimer3;
            sVoiceSEStack3 = sVoiceSEStack4;
            sVoiceSEStackTimer3 = sVoiceSEStackTimer4;
            sActiveVoiceSE = 0;
            sVoiceSEStack4 = 0;
            sVoiceSEStackTimer4 = 0;
        }
    }
}

extern s32 D_80771968;

AudioTask* Audio_SetupCreateTask(void) {
    AudioTask* curAudioTask;

    if (!sSpecChangeActive) {
        func_807427C0();
    }
    Audio_EditorBgmDelaySet();
    Audio_Editor2BgmDelaySet();
    if (D_80771CAC == 1) {
        D_80771CB0++;
    }
    if (D_80771968 == 0) {
        if (D_80771CB8 > 10) {
            D_80771CBC = 0;
        } else {
            D_80771CB8++;
        }
    } else {
        D_80771CB8 = 0;
        D_80771CBC = D_80771968;
    }
    Audio_BgmFadeout();
    Audio_LevelSEFadeoutRoutine();
    Audio_BgmFadeoutPause();
    AudioThread_ScheduleProcessCmds();
    gCurAudioTask = curAudioTask = AudioThread_CreateTask();

    return curAudioTask;
}

void Audio_Update(void) {
    u8 i;

    func_80742654();
    func_8074252C();
    func_8074270C();
    Audio_RomBgmReadyTaiki();
    Audio_CheckBgmLoad();
    Audio_DDBgmReadyTaiki();
    Audio_UpdateEnemyEngine();
    func_807442E4();
    Audio_VoiceSEPopStack();

    for (i = 0; i < sAudioPlayerMode + 1; i++) {
        func_807447CC(i);
        Audio_UpdateReverb(i);
        Audio_LevelSEPopStack(i);
        func_80744BDC(i);
    }
    if (sAudioPlayerMode == 0) {
        for (i = 0; i < 30; i++) {
            Audio_PlayerSEPopStack(i);
        }
    } else {
        for (i = 0; i < sAudioPlayerMode + 1; i++) {
            Audio_PlayerSEPopStack(i);
        }
    }
    AudioThread_ScheduleProcessCmds();
}
