#include "global.h"
#include "audio.h"
#include "audiothread_cmd.h"
#include "fzx_racer.h"
#include "fzx_game.h"

void Audio_SEStart(u8 channelIndex, u8 ioData);
void Audio_StopChannelSE(u8);
void Audio_SystemSEStart(u8);
void Audio_DisablePlayerSE(void);

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
UNUSED s32 D_800D1A10 = 0;
UNUSED s32 D_800D1A14 = 0;
u8 sAudioPlayerMode = 0;
u8 sAudioEnemyEngineStatus = 0;
u8 sAudioClosestRacerId = 0;
u8 sAudioPreviousClosestRacerId = 0;
f32 sAudioPreviousClosestRacerDistance = 0.0f;
f32 D_800D1A2C = 1.0f;
f32 sAudioClosestRacerDistance = 0.0f;
f32 sEnemyEngineVolume = 0.0f;
f32 sEnemyEngineFreqScale = 0.0f;
u8 sEnemyEngineLinearPan = 64;
u8 sAudioPauseStatus = 0;
u16 sBGMPauseFadeoutTimer = 0;
u8 sBgmPlayState = 0;
u16 sBGMFadeoutTimer = 0;
u16 sLevelFadeoutTimer = 0;
UNUSED s32 D_800D1A54 = 0;
u8 sAudioLevelFadeoutActive = 0;
u8 sPreviousSpecId = 0;
u8 sActiveBgm = 0;
f32 D_800D1A64[4] = { 0 };
u8 sPlayerEngineSoundState[4] = { 0 };
u8 D_800D1A78[4] = { 0 };
f32 sAudioPlayerPreviousSpeed[4] = { 0 };
u8 D_800D1A8C[4] = { 0 };
u8 sPlayerEngineEchoSoundState[4] = { 0 };
u8 D_800D1A94[4] = { 0 };
f32 sChannelVolume[16] = { 0 };
u8 sRacerActiveSE[30] = { 0 };
f32 sRacerAudioVolume[] = {
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
};
u8 sAudioPlayerSEStack[30][4] = { 0 };
u8 sAudioLevelSEStack[4][4] = { 0 };
u8 sActivePlayerLevelSE[4][8] = { 0 };
AudioTask* gCurAudioTask = NULL;

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

void Audio_LevelSEStart(u8 playerIndex, u8 sfxId) {

    PRINTF("LEVEL SE INTERNAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);

    if (sActivePlayerLevelSE[playerIndex][0] == 0) {
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][1] == 0) {
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][2] == 0) {
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][3] == 0) {
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][4] == 0) {
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][5] == 0) {
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][6] == 0) {
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][0];
        sActivePlayerLevelSE[playerIndex][0] = sfxId;
    } else if (sActivePlayerLevelSE[playerIndex][7] == 0) {
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
            PRINTF("LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
            Audio_SEStart(6, sfxId);
            break;
        case 1:
            switch (playerIndex) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    PRINTF("LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
                    Audio_SEStart(6, sfxId + 10);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0x7F);
                    PRINTF("LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
                    Audio_SEStart(7, sfxId + 10);
                    break;
            }
            break;
        case 2:
            switch (playerIndex) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    PRINTF("LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
                    Audio_SEStart(6, sfxId + 20);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0);
                    PRINTF("LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
                    Audio_SEStart(7, sfxId + 20);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 8, 0x7F);
                    PRINTF("LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
                    Audio_SEStart(8, sfxId + 20);
                    break;
            }
            break;
        case 3:
            switch (playerIndex) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    PRINTF("LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
                    Audio_SEStart(6, sfxId + 20);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0);
                    PRINTF("LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
                    Audio_SEStart(7, sfxId + 20);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 8, 0x7F);
                    PRINTF("LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
                    Audio_SEStart(8, sfxId + 20);
                    break;
                case 3:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 9, 0x7F);
                    PRINTF("LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n", playerIndex, sfxId);
                    Audio_SEStart(9, sfxId + 20);
                    break;
            }
            break;
    }
}

void Audio_LevelSEPopStack(u8 playerIndex) {

    if (sAudioLevelSEStack[playerIndex][0] != 0) {
        Audio_LevelSEStart(playerIndex, sAudioLevelSEStack[playerIndex][0]);
        sAudioLevelSEStack[playerIndex][0] = sAudioLevelSEStack[playerIndex][1];
        sAudioLevelSEStack[playerIndex][1] = sAudioLevelSEStack[playerIndex][2];
        sAudioLevelSEStack[playerIndex][2] = sAudioLevelSEStack[playerIndex][3];
        sAudioLevelSEStack[playerIndex][3] = 0;
    }
}

extern Player gPlayers[];

void Audio_PlayerSEStart(u8 racerId, u8 sfxId) {
    f32 volumeScale;
    f32 freqScale;
    f32 distance;
    Vec3f vec;
    u8 pan;

    //! @bug OOB read in sPlayerEngineSoundState when using non-player racerIds
    if ((sPlayerEngineSoundState[racerId] == 0) &&
        !((sfxId == 0x16) || (sfxId == 0x10) || (sfxId == 0x21) || (sfxId == 0x1E) || (sfxId == 5) || (sfxId == 8) ||
          (sfxId == 0xF) || (sfxId == 0x30) || (sfxId == 0x31) || (sfxId == 0x34) || (sfxId == 0x35) || (sfxId == 0x3E))) {
        PRINTF("Ouch!! UN-SUPORTED TRG SE NUM WAS CALLED !!!!!!! num = %02x\n", sfxId);
        return;
    }
#ifdef VERSION_JP
    PRINTF("PLY TRG MYCAR NUM =  %02x SE NUM =  %02x VOL = %f \n", racerId, sfxId, sRacerAudioVolume[racerId]);
#endif
    sRacerActiveSE[racerId] = sfxId;
    switch (sAudioPlayerMode) {
        case 0:
            if (racerId == 0) {
                AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0x3F);
                volumeScale = sRacerAudioVolume[racerId];
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);

                if (sfxId >= 0x3F || sfxId < 0) {
                    sfxId = 0;
                }
                Audio_SEStart(10, sfxId);
            } else if (sAudioEnemyEngineStatus != 0) {
#ifdef VERSION_JP
                PRINTF("ENEMY NUMBER = %02x RANK = %d SE num = %02x MOST NEAR ENEMY = %02x \n", racerId, racerId, sfxId,
                       sAudioClosestRacerId);
#endif
                if (racerId == sAudioClosestRacerId) {
                    distance = sAudioClosestRacerDistance;
                } else {
                    vec.x = gRacers[racerId].unk_0C.unk_34.x - gPlayers[0].unk_50.x;
                    vec.y = gRacers[racerId].unk_0C.unk_34.y - gPlayers[0].unk_50.y;
                    vec.z = gRacers[racerId].unk_0C.unk_34.z - gPlayers[0].unk_50.z;

                    distance = sqrtf(SQ_SUM(&vec));
                }
                if ((distance < 10000.0f) && (distance > 0.0f)) {
                    volumeScale = (-(9.0f / 190000.0f) * distance) + 1.0f;
                    if (volumeScale > 0.3f) {
                        if (volumeScale > 0.85f) {
                            volumeScale = 0.85f;
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
#ifdef VERSION_JP
                        PRINTF("DISTANCE = %f PAN = %02x VOLUME = %f TUNING = %f \n\n", distance, pan, volumeScale,
                               freqScale);
#endif
                        AUDIOCMD_CHANNEL_SET_PAN(0, 15, pan);
                        Audio_SEStart(15, sfxId);
                    }
                }
            }
            break;
        case 1:
            volumeScale = sRacerAudioVolume[racerId] * 0.9f;
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
            volumeScale = sRacerAudioVolume[racerId] * 0.85f;
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
            volumeScale = sRacerAudioVolume[racerId] * 0.85f;
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
        Audio_PlayerSEStart(racerId, sAudioPlayerSEStack[racerId][0]);
        sAudioPlayerSEStack[racerId][0] = sAudioPlayerSEStack[racerId][1];
        sAudioPlayerSEStack[racerId][1] = sAudioPlayerSEStack[racerId][2];
        sAudioPlayerSEStack[racerId][2] = sAudioPlayerSEStack[racerId][3];
        sAudioPlayerSEStack[racerId][3] = 0;
    }
}

void Audio_LevelSEFadeoutRoutine(void) {
    f32 volumeScale;
    s8 reverbVolume;

    if (!sAudioLevelFadeoutActive || sAudioPauseStatus == 2) {
        return;
    }

    sLevelFadeoutTimer++;
    if (sLevelFadeoutTimer == 29) {
        PRINTF("LEVEL SE FADEOUT COMPLETE ROUTINE\n");
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

void Audio_BGMFadeout(void) {
    f32 volumeScale;

    switch (sBgmPlayState) {
        case 0:
            break;
        case 1:
#ifdef VERSION_JP
            if (++sBGMFadeoutTimer == (100 / 2) - 1) {
#else
            if (++sBGMFadeoutTimer == (70 / 2) - 1) {
#endif
                PRINTF("BGM FADEOUT1 COMPLETE ROUTINE\n");
                sBgmPlayState = 0;
                sBGMFadeoutTimer = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                Audio_StopChannelSE(0);
            } else {
#ifdef VERSION_JP
                volumeScale = 1.0f - (sBGMFadeoutTimer * (2.0f / 100.0f));
#else
                volumeScale = 1.0f - (sBGMFadeoutTimer * (2.0f / 70.0f));
#endif
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
            break;
        case 2:
#ifdef VERSION_JP
            if (++sBGMFadeoutTimer == (80 / 1) - 1) {
#else
            if (++sBGMFadeoutTimer == (70 / 1) - 1) {
#endif
                PRINTF("BGM FADEOUT2 COMPLETE ROUTINE\n");
                sBgmPlayState = 0;
                sBGMFadeoutTimer = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                Audio_StopChannelSE(0);
            } else {
#ifdef VERSION_JP
                volumeScale = 1.0f - (sBGMFadeoutTimer * (1.0f / 80.0f));
#else
                volumeScale = 1.0f - (sBGMFadeoutTimer * (1.0f / 70.0f));
#endif
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
            break;
        case 3:
            if (++sBGMFadeoutTimer == (700 / 2) - 1) {
                PRINTF("BGM FADEOUT3 COMPLETE ROUTINE\n");
                sBgmPlayState = 0;
                sBGMFadeoutTimer = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                Audio_StopChannelSE(0);
            } else {
                volumeScale = 1.0f - (sBGMFadeoutTimer * (2.0f / 700.0f));
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
            break;
    }
}

extern s32 gNumPlayers;
extern s8 D_800CD010;
extern s32 gGameMode;

void func_800B84B8(void) {
    s32 temp_lo;
    SequenceLayer* layer;
    Note* note;

    if ((sActiveBgm == 13) && (IS_SEQUENCE_CHANNEL_VALID(gSeqPlayers[0].channels[0]))) {
        layer = gSeqPlayers[0].channels[0]->layers[0];
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

                if ((temp_lo > 2100) && (temp_lo < 2110) && (gGameMode == GAMEMODE_FLX_TITLE) && (D_800CD010 == 0)) {
                    D_800CD010 = 1;
                }
                if ((temp_lo > 8200) && (temp_lo < 8210) && (D_800CD010 == 1)) {
                    D_800CD010 = 3;
                }
            }
        }
    }
}

void Audio_BGMFadeoutPause(void) {
    f32 volumeScale;

    if (sAudioPauseStatus == 2) {
        if (++sBGMPauseFadeoutTimer == (100 / 2) - 1) {
            PRINTF("BGM FADEOUT COMPLETE ROUTINE (in the PAUSE ROUTINE)\n");
            sAudioPauseStatus = 0;
            sBGMPauseFadeoutTimer = 0;
            Audio_StopChannelSE(0);
        } else {
            volumeScale = 0.4f - (sBGMPauseFadeoutTimer * (0.4f * (2.0f / 100.0f)));
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
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

    if (sAudioPauseStatus == 1 || sAudioPauseStatus == 2) {
        return;
    }

    if (((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) &&
        !sAudioLevelFadeoutActive) {
        vec.x = gRacers[sAudioClosestRacerId].unk_0C.unk_34.x - gPlayers[0].unk_50.x;
        vec.y = gRacers[sAudioClosestRacerId].unk_0C.unk_34.y - gPlayers[0].unk_50.y;
        vec.z = gRacers[sAudioClosestRacerId].unk_0C.unk_34.z - gPlayers[0].unk_50.z;
        sAudioClosestRacerDistance = sqrtf(SQ_SUM(&vec));
        if ((sAudioClosestRacerDistance < 820.0f) && (sAudioClosestRacerDistance != 0.0f)) {
            if (sAudioEnemyEngineStatus == 0) {
                if (D_800D1A8C[0] == 0) {
                    if (!sAudioDisableEnemyEngineSound) {
                        PRINTF("ENEMY ENGINE START MACHINE No.= %02x\n", sAudioClosestRacerId);
                        Audio_SEStart(14, 1);
                    }
                    sAudioEnemyEngineStatus = 2;
                }
            } else {
                sAudioEnemyEngineStatus = 1;
            }
        } else {
            if (sAudioEnemyEngineStatus == 1) {
                PRINTF("ENEMY ENGINE STOP!\n");
                Audio_StopChannelSE(14);
                sAudioEnemyEngineStatus = 0;
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
                D_800D1A2C = (sAudioPreviousClosestRacerDistance - sAudioClosestRacerDistance) * (1.0f / 30.0f);
            }
            sAudioPreviousClosestRacerDistance = sAudioClosestRacerDistance;
            sAudioPreviousClosestRacerId = sAudioClosestRacerId;

            sEnemyEngineFreqScale =
                ((gRacers[sAudioClosestRacerId].speed + 0.01f) * (1.0f / 21.0f)) + 0.5f + D_800D1A2C;
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

void func_800B899C(u8 playerIndex) {
    f32 freqScale;
    f32 volumeScale;

    if (sAudioPauseStatus == 1 || sAudioPauseStatus == 2) {
        return;
    }

    if (sPlayerEngineSoundState[playerIndex] == 0) {
        if (D_800D1A94[playerIndex] == 0) {
            return;
        }
    }

    if (gRacers[playerIndex].speed < sAudioPlayerPreviousSpeed[playerIndex]) {
        D_800D1A78[playerIndex] = 1;
    } else {
        D_800D1A78[playerIndex] = 0;
    }
    sAudioPlayerPreviousSpeed[playerIndex] = gRacers[playerIndex].speed;
    if (D_800D1A94[playerIndex] == 0) {
        if ((gRacers[playerIndex].unk_1D4 != 0.0f) && (gRacers[playerIndex].speed > 27.0f)) {
            if (D_800D1A78[playerIndex] == 1) {
                if (D_800D1A64[playerIndex] > -0.5f) {
                    D_800D1A64[playerIndex] -= 0.004f;
                }
            } else {
                D_800D1A64[playerIndex] += 0.004f;
            }
        } else {
            D_800D1A64[playerIndex] = 0.0f;
        }
        if (gRacers[playerIndex].unk_20C != 0) {
            D_800D1A64[playerIndex] = 0.0f;
        }
    } else {
        // FAKE
    }

    freqScale = (((0.01f + gRacers[playerIndex].speed) * (1.0f / 21.0f)) + 0.25f) + D_800D1A64[playerIndex];
    AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, playerIndex + 2, freqScale);

    if ((gRacers[playerIndex].unk_1D4 == 0.0f) && (gRacers[playerIndex].unk_1D8 == 0.0f)) {
        if (D_800D1A94[playerIndex] == 1) {
            Vec3f vec;
            f32 temp;

            vec.x = gRacers[playerIndex].unk_0C.unk_34.x - gPlayers[playerIndex].unk_50.x;
            vec.y = gRacers[playerIndex].unk_0C.unk_34.y - gPlayers[playerIndex].unk_50.y;
            vec.z = gRacers[playerIndex].unk_0C.unk_34.z - gPlayers[playerIndex].unk_50.z;
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
    } else if (D_800D1A94[playerIndex] == 1) {
        Vec3f vec;
        f32 temp;

        vec.x = gRacers[playerIndex].unk_0C.unk_34.x - gPlayers[playerIndex].unk_50.x;
        vec.y = gRacers[playerIndex].unk_0C.unk_34.y - gPlayers[playerIndex].unk_50.y;
        vec.z = gRacers[playerIndex].unk_0C.unk_34.z - gPlayers[playerIndex].unk_50.z;
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

    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, playerIndex + 2, volumeScale);
    sChannelVolume[playerIndex + 2] = volumeScale;
}

void func_800B8DAC(u8 playerIndex) {
    f32 freqScale;
    f32 volumeScale;

    if (sAudioPauseStatus == 1 || sAudioPauseStatus == 2) {
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
        case 4:
        case 10:
        case 13:
        case 14:
        case 20:
        case 23:
        case 24:
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
                gSynthReverbs[0].volume = 0x7FFF;
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, 80);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 15, 80);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((sRacerActiveSE[0] == 19) || (sRacerActiveSE[0] == 20) || (sRacerActiveSE[0] == 21)) {
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
                gSynthReverbs[0].volume = 0;
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 15, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            break;
        case 1:
            if ((sPlayerEngineEchoSoundState[0] == 1) || (sPlayerEngineEchoSoundState[1] == 1)) {
                gSynthReverbs[0].volume = 0x7FFF;
            } else {
                gSynthReverbs[0].volume = 0;
            }
            if (sPlayerEngineEchoSoundState[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((sRacerActiveSE[0] == 19) || (sRacerActiveSE[0] == 20) || (sRacerActiveSE[0] == 21)) {
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
                if ((sRacerActiveSE[1] == 19) || (sRacerActiveSE[1] == 20) || (sRacerActiveSE[1] == 21)) {
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
                gSynthReverbs[0].volume = 0x7FFF;
            } else {
                gSynthReverbs[0].volume = 0;
            }
            if (sPlayerEngineEchoSoundState[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((sRacerActiveSE[0] == 19) || (sRacerActiveSE[0] == 20) || (sRacerActiveSE[0] == 21)) {
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
                if ((sRacerActiveSE[1] == 19) || (sRacerActiveSE[1] == 20) || (sRacerActiveSE[1] == 21)) {
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
                if ((sRacerActiveSE[2] == 19) || (sRacerActiveSE[2] == 20) || (sRacerActiveSE[2] == 21)) {
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
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 80);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
            }
            break;
        case 3:
            if ((sPlayerEngineEchoSoundState[0] == 1) || (sPlayerEngineEchoSoundState[1] == 1) ||
                (sPlayerEngineEchoSoundState[2] == 1) || (sPlayerEngineEchoSoundState[3] == 1)) {
                gSynthReverbs[0].volume = 0x7FFF;
            } else {
                gSynthReverbs[0].volume = 0;
            }
            if (sPlayerEngineEchoSoundState[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((sRacerActiveSE[0] == 19) || (sRacerActiveSE[0] == 20) || (sRacerActiveSE[0] == 21)) {
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
                if ((sRacerActiveSE[1] == 19) || (sRacerActiveSE[1] == 20) || (sRacerActiveSE[1] == 21)) {
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
                if ((sRacerActiveSE[2] == 19) || (sRacerActiveSE[2] == 20) || (sRacerActiveSE[2] == 21)) {
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
                if ((sRacerActiveSE[3] == 19) || (sRacerActiveSE[3] == 20) || (sRacerActiveSE[3] == 21)) {
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
        PRINTF("len = %d\n", sVoiceSEStackTimer1); // Unsure on print location
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

void Audio_UpdateImpl(void) {
    u8 i;

    Audio_UpdateEnemyEngine();
    func_800B84B8();
    Audio_VoiceSEPopStack();

    for (i = 0; i < sAudioPlayerMode + 1; i++) {
        func_800B899C(i);
        Audio_UpdateReverb(i);
        Audio_LevelSEPopStack(i);
        func_800B8DAC(i);
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
}

void Audio_Update(void) {
    Audio_UpdateImpl();
    AudioThread_ScheduleProcessCmds();
}

void Audio_SetChannelMute(s32 seqPlayerIndex, s32 channelIndex, bool muted) {
    AUDIOCMD_CHANNEL_SET_MUTE(seqPlayerIndex, channelIndex, muted);
}

void Audio_LoadDrum(void) {
    AUDIOCMD_GLOBAL_SYNC_LOAD_INSTRUMENT(0, 0x7F, 0);
}

void func_800B9EBC(s32 arg0, s32 arg1, s32 arg2) {
}

void func_800B9ECC(void) {
}

void Audio_ResetSoundData(void) {
    u8 i;

    Audio_StopChannelSE(0);
    Audio_StopChannelSE(2);
    Audio_StopChannelSE(3);
    Audio_StopChannelSE(4);
    Audio_StopChannelSE(5);
    Audio_StopChannelSE(6);
    Audio_StopChannelSE(7);
    Audio_StopChannelSE(8);
    Audio_StopChannelSE(9);
    Audio_StopChannelSE(14);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 2, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 3, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 4, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 5, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 6, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 7, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 8, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 9, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, 0.0f);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 0);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 0);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 5, 0);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 9, 0);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, 0);
    sAudioRetireStatus = 0;
    sAudioDisableEnemyEngineSound = false;
    sPlayerSEStatus = 0;
    sAudioEnemyEngineStatus = 0;
    sAudioClosestRacerId = 0;
    sAudioPreviousClosestRacerId = 0;
    sAudioPreviousClosestRacerDistance = 0.0f;
    D_800D1A2C = 1.0f;
    sAudioClosestRacerDistance = 0.0f;
    sEnemyEngineVolume = 0.0f;
    sEnemyEngineFreqScale = 0.0f;
    sEnemyEngineLinearPan = 64;
    sAudioPauseStatus = 0;
    sAudioLevelFadeoutActive = false;
    sLevelFadeoutTimer = 0;
#ifndef VERSION_JP
    sBgmPlayState = 0;
#endif

    for (i = 0; i < 4; i++) {
        D_800D1A64[i] = 0.0f;
        sPlayerEngineSoundState[i] = 0;
        D_800D1A78[i] = 0;
        sAudioPlayerPreviousSpeed[i] = 0;
        D_800D1A8C[i] = 0;
        sActivePlayerLevelSE[i][0] = 0;
        sActivePlayerLevelSE[i][1] = 0;
        sActivePlayerLevelSE[i][2] = 0;
        sActivePlayerLevelSE[i][3] = 0;
        sActivePlayerLevelSE[i][4] = 0;
        sActivePlayerLevelSE[i][5] = 0;
        sActivePlayerLevelSE[i][6] = 0;
        sActivePlayerLevelSE[i][7] = 0;
        sPlayerEngineEchoSoundState[i] = 0;
        sRacerActiveSE[i] = 0;
        sAudioLevelSEStack[i][0] = 0;
        sAudioLevelSEStack[i][1] = 0;
        sAudioLevelSEStack[i][2] = 0;
        sAudioLevelSEStack[i][3] = 0;
        D_800D1A94[i] = 0;
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

void Audio_PreNMI(void) {
    AudioThread_PreNMIInternal();
}

void Audio_Init(void) {
    AudioLoad_Init(NULL, 0);
}

void Audio_SetSoundMode(u8 soundMode) {
    AUDIOCMD_GLOBAL_SET_SOUND_MODE(soundMode);
}

void func_800BA2B4(u8 playerIndex) {
    D_800D1A8C[playerIndex] = 1;
}

void Audio_SetEnemyEnginePan(u8 pan) {
    sEnemyEngineLinearPan = pan;
}

void Audio_SetNearestEnemy(u8 racerId) {
    sAudioClosestRacerId = racerId;
}

// Na_PlyLevelSE_Start
void Audio_PlayerLevelSEStart(u8 playerIndex, u8 sfxId) {

    PRINTF("Player Level SE Start !! player =  %02x SE number = %02x\n", playerIndex, sfxId);

    if (D_800D1A8C[playerIndex] == 1) {
        return;
    }

    if ((sfxId != sActivePlayerLevelSE[playerIndex][0]) && (sfxId != sActivePlayerLevelSE[playerIndex][1]) &&
        (sfxId != sActivePlayerLevelSE[playerIndex][2]) && (sfxId != sActivePlayerLevelSE[playerIndex][3]) &&
        (sfxId != sActivePlayerLevelSE[playerIndex][4]) && (sfxId != sActivePlayerLevelSE[playerIndex][5]) &&
        (sfxId != sActivePlayerLevelSE[playerIndex][6]) && (sfxId != sActivePlayerLevelSE[playerIndex][7])) {
        if (sAudioLevelSEStack[playerIndex][0] != 0) {
            if (sAudioLevelSEStack[playerIndex][1] != 0) {
                if (sAudioLevelSEStack[playerIndex][2] != 0) {
                    if (sAudioLevelSEStack[playerIndex][3] == 0) {
                        sAudioLevelSEStack[playerIndex][3] = sfxId;
                    } else {
                        PRINTF("PLAYER LEVEL SE STACK OVER!!\n");
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

    PRINTF("Na_PlyLevelSE_Stop Called player = %02x num = %02x \n", playerIndex, sfxId);

    if (sfxId == sAudioLevelSEStack[playerIndex][0]) {
        sAudioLevelSEStack[playerIndex][0] = 0;
        if (sAudioLevelSEStack[playerIndex][1] != 0) {
            sAudioLevelSEStack[playerIndex][0] = sAudioLevelSEStack[playerIndex][1];
            sAudioLevelSEStack[playerIndex][1] = sAudioLevelSEStack[playerIndex][2];
            sAudioLevelSEStack[playerIndex][2] = sAudioLevelSEStack[playerIndex][3];
            sAudioLevelSEStack[playerIndex][3] = 0;
        }
    }
    if (sfxId == sAudioLevelSEStack[playerIndex][1]) {
        sAudioLevelSEStack[playerIndex][1] = 0;
        if (sAudioLevelSEStack[playerIndex][2] != 0) {
            sAudioLevelSEStack[playerIndex][1] = sAudioLevelSEStack[playerIndex][2];
            sAudioLevelSEStack[playerIndex][2] = sAudioLevelSEStack[playerIndex][3];
            sAudioLevelSEStack[playerIndex][3] = 0;
        }
    }
    if (sfxId == sAudioLevelSEStack[playerIndex][2]) {
        sAudioLevelSEStack[playerIndex][2] = 0;
        if (sAudioLevelSEStack[playerIndex][3] != 0) {
            sAudioLevelSEStack[playerIndex][2] = sAudioLevelSEStack[playerIndex][3];
            sAudioLevelSEStack[playerIndex][3] = 0;
        }
    }
    if (sfxId == sAudioLevelSEStack[playerIndex][3]) {
        sAudioLevelSEStack[playerIndex][3] = 0;
    }

    if (sfxId == sActivePlayerLevelSE[playerIndex][0]) {
        PRINTF("NON ENTRIED LEVEL SE STOPED! SE NUMBER = %02x\n", sfxId);
        sActivePlayerLevelSE[playerIndex][0] = sActivePlayerLevelSE[playerIndex][1];
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = 0;
        if (sActivePlayerLevelSE[playerIndex][0] == 0) {
            Audio_StopChannelSE(playerIndex + 6);
        } else {
            Audio_StopChannelSE(playerIndex + 6);
            temp = sActivePlayerLevelSE[playerIndex][0];
            sActivePlayerLevelSE[playerIndex][0] = 0;
            Audio_PlayerLevelSEStart(playerIndex, temp);
        }
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][1]) {
        sActivePlayerLevelSE[playerIndex][1] = sActivePlayerLevelSE[playerIndex][2];
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = 0;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][2]) {
        sActivePlayerLevelSE[playerIndex][2] = sActivePlayerLevelSE[playerIndex][3];
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = 0;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][3]) {
        sActivePlayerLevelSE[playerIndex][3] = sActivePlayerLevelSE[playerIndex][4];
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = 0;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][4]) {
        sActivePlayerLevelSE[playerIndex][4] = sActivePlayerLevelSE[playerIndex][5];
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = 0;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][5]) {
        sActivePlayerLevelSE[playerIndex][5] = sActivePlayerLevelSE[playerIndex][6];
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = 0;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][6]) {
        sActivePlayerLevelSE[playerIndex][6] = sActivePlayerLevelSE[playerIndex][7];
        sActivePlayerLevelSE[playerIndex][7] = 0;
    } else if (sfxId == sActivePlayerLevelSE[playerIndex][7]) {
        sActivePlayerLevelSE[playerIndex][7] = 0;
    }
}

void Audio_PlayerTriggerSE(u8 racerId, u8 sfxId) {

    if (sfxId != sAudioPlayerSEStack[racerId][0] && sfxId != sAudioPlayerSEStack[racerId][1] &&
        sfxId != sAudioPlayerSEStack[racerId][2] && sfxId != sAudioPlayerSEStack[racerId][3]) {
        if (sAudioPlayerSEStack[racerId][0] != 0) {
            if (sAudioPlayerSEStack[racerId][1] != 0) {
                if (sAudioPlayerSEStack[racerId][2] != 0) {
                    if (sAudioPlayerSEStack[racerId][3] == 0) {
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

    if (sfxId == 0x1E) {
        goto block_5;
    }
    if (sfxId == 0x21) {
        goto block_5;
    }
    if (sAudioRetireStatus == 1) {
        return;
    }
block_5:

    if ((racerId == 0) || (racerId == 1) || (racerId == 2) || (racerId == 3)) {
        sRacerAudioVolume[racerId] = 0.83f;
    } else if (sPlayerSEStatus == 1) {
        return;
    }

#ifdef VERSION_JP
    PRINTF("Player Trger SE Start !! player =  %02x SE number = %02x\n", racerId, sfxId);
#endif

    Audio_PlayerTriggerSE(racerId, sfxId);
}

void Audio_SystemSEStart(u8 ioData) {
    AUDIOCMD_CHANNEL_SET_PAN(0, 1, 0x3F);
    Audio_SEStart(1, ioData);
}

void Audio_TriggerVoiceSEStart(u8 sfxId, u16 time) {

    if ((sfxId != sVoiceSEStack1) && (sfxId != sVoiceSEStack2) && (sfxId != sVoiceSEStack3) && (sfxId != sVoiceSEStack4)) {
        if (sVoiceSEStackTimer1 != 0) {
            if (sVoiceSEStackTimer2 != 0) {
                if (sVoiceSEStackTimer3 != 0) {
                    if (sVoiceSEStackTimer4 == 0) {
                        sVoiceSEStack4 = sfxId;
                        sVoiceSEStackTimer4 = time;
                    } else {
                        PRINTF("VOICE SE STACK OVER!!\n");
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

void Audio_TriggerSystemSE(u8 sfxId) {

    PRINTF("System SE = %02x\n", sfxId);
    if (sfxId == 0x11) {
        // You got boost power
        Audio_TriggerVoiceSEStart(sfxId, 0x83);
    } else if (sfxId == 0x12) {
        // Yeah! The final lap
        Audio_TriggerVoiceSEStart(sfxId, 0xB3);
    } else if (sfxId == 0x2A) {
        Audio_TriggerVoiceSEStart(sfxId, 0xBE);
    } else if (sfxId == 0x2C) {
        Audio_TriggerVoiceSEStart(sfxId, 0xC6);
    } else if (sfxId == 0x30) {
        Audio_TriggerVoiceSEStart(sfxId, 0x9A);
    } else if (sfxId == 0x33) {
        Audio_TriggerVoiceSEStart(sfxId, 0x9B);
    } else if (sfxId == 0x34) {
        Audio_TriggerVoiceSEStart(sfxId, 0xE9);
    } else if (sfxId == 0x35) {
        Audio_TriggerVoiceSEStart(sfxId, 0xCD);
    } else if (sfxId == 0x38) {
        Audio_TriggerVoiceSEStart(sfxId, 0x71);
    } else if (sfxId == 0x3A) {
        Audio_TriggerVoiceSEStart(sfxId, 0x68);
    } else if (sfxId == 0x3B) {
        Audio_TriggerVoiceSEStart(sfxId, 0xB5);
    } else if (sfxId == 0x3C) {
        Audio_TriggerVoiceSEStart(sfxId, 0x99);
    } else if (sfxId == 0x3D) {
        Audio_TriggerVoiceSEStart(sfxId, 0x83);
    } else if (sfxId == 0x43) {
        Audio_TriggerVoiceSEStart(sfxId, 0x9B);
    } else {
        Audio_SystemSEStart(sfxId);
    }
}

// Na_hanabi
void Audio_Hanabi(u8 pan, u8 volume) {
    f32 volumeScale;

    PRINTF("hanabi se called. pan = %02x volume = %02x \n", pan, volume);
    AUDIOCMD_CHANNEL_SET_PAN(0, 15, Audio_AdjustPan(pan));

    if (volume >= 0x80) {
        volume = 0x7F;
    }
    if (volume < 0) {
        volume = 0;
    }

    volumeScale = volume / 127.0f;
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 15, volumeScale);
    Audio_SEStart(15, 0x2D);
}

void Audio_PlayerEngineEchoStart(u8 playerIndex) {
    PRINTF("ENGINE SOUND ECHO START MACHINE NO = %02x\n", playerIndex);
    sPlayerEngineEchoSoundState[playerIndex] = 1;
}

void Audio_PlayerEngineEchoStop(u8 playerIndex) {
    PRINTF("ENGINE SOUND ECHO STOPED! MACHINE No.= %02x\n", playerIndex);
    sPlayerEngineEchoSoundState[playerIndex] = 0;
}

void Audio_PlayerEngineStop(u8 playerIndex) {
    PRINTF("ENGINE SOUND STOPED! MACHINE No.= %02x\n", playerIndex);
    Audio_StopChannelSE(playerIndex + 2);
    sPlayerEngineSoundState[playerIndex] = 0;
}

// Na_PlyEng_Start
void Audio_PlayerEngineStart(u8 playerIndex) {

    PRINTF("ENGINE SOUND START! MACHINE No.= %02x\n", playerIndex);
    switch (sAudioPlayerMode) {
        case 0:
            AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0x3F);
            if (D_800D1A94[playerIndex] == 0) {
                Audio_SEStart(playerIndex + 2, 2);
            } else {
                Audio_SEStart(playerIndex + 2, 7);
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
            if (D_800D1A94[playerIndex] == 0) {
                Audio_SEStart(playerIndex + 2, 0xC);
            } else {
                Audio_SEStart(playerIndex + 2, 0x11);
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
            if (D_800D1A94[playerIndex] == 0) {
                Audio_SEStart(playerIndex + 2, 0x16);
            } else {
                Audio_SEStart(playerIndex + 2, 0x1B);
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
            if (D_800D1A94[playerIndex] == 0) {
                Audio_SEStart(playerIndex + 2, 0x16);
            } else {
                Audio_SEStart(playerIndex + 2, 0x1B);
            }
    }
}

void func_800BAE5C(u8 playerIndex) {
    PRINTF("WINING RUN ENGINE SOUND START! MACHINE No.= %02x\n", playerIndex);
    sPlayerEngineSoundState[playerIndex] = 1;
    Audio_PlayerEngineStart(playerIndex);
}

void func_800BAE90(u8 arg0) {
}

// Na_SE_Start
void Audio_SEStart(u8 channelIndex, u8 ioData) {
    AUDIOCMD_CHANNEL_SET_IO(0, channelIndex, 0, ioData);
}

void Audio_StopChannelSE(u8 channelIndex) {
    AUDIOCMD_CHANNEL_SET_IO(0, channelIndex, 5, 1);
}

void func_800BAF18(u8 bgm) {
    PRINTF("64DD STREEM BGM Ready %02x\n", bgm);
}

void func_800BAF20(u8 bgm) {
    PRINTF("64DD STREEM BGM Start%02x\n", bgm);
}

// Na_DDBgm_Stop
void Audio_DDBgmStop(void) {
    PRINTF("Na_DDBgm_Stop Called\n");
}

// Na_BetaBgm_Start
void Audio_BetaBgmStart(u8 bgm) {
    PRINTF("Na_BetaBgm_Start num = %02x\n", bgm);
    sBgmPlayState = 0;
    sBGMFadeoutTimer = 0;
    sActiveBgm = bgm;
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 1.0f);
    Audio_SEStart(0, bgm);
}

// Na_BetaBgm_Stop
void Audio_BetaBgmStop(void) {
    PRINTF("Na_BetaBgm_Stop Called\n");
    if (sBgmPlayState == 0) {
        sBgmPlayState = 1;
    }
}

// Na_ROMBgm_Start
void Audio_RomBgmStart(u8 bgm) {
    PRINTF("Na_ROMBgm_Start Called num = %02x\n", bgm);
    sBgmPlayState = 0;
    sBGMFadeoutTimer = 0;
    sActiveBgm = bgm;
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 1.0f);
    Audio_SEStart(0, bgm);
}

// Na_ROMBgm_Stop
void Audio_RomBgmStop(void) {
    PRINTF("Na_ROMBgm_Stop Called\n");
    if (sBgmPlayState == 0) {
        sBgmPlayState = 1;
    }
}

void func_800BB018(void) {
    Audio_RomBgmStart(0x17);
}

// Na_RETIRE
void Audio_Retire(void) {
    PRINTF("RETIRE FUNCTION CALLED!!\n");
    sAudioRetireStatus = 1;
}

// Na_Level_SE_Fadeout
void Audio_LevelSEFadeout(void) {
    PRINTF("Level SE Fadeout !!\n");
    Audio_DisablePlayerSE();
    sAudioLevelFadeoutActive = true;
    sAudioDisableEnemyEngineSound = true;
}

// Na_BetaBgm_Stop2
void Audio_BetaBgmStop2(void) {
    PRINTF("Na_BetaBgm_Stop2 Called\n");
    if (sBgmPlayState == 0) {
        sBgmPlayState = 2;
    }
}

// Na_BetaBgm_Stop3
void Audio_BetaBgmStop3(void) {
    PRINTF("Na_BetaBgm_Stop3 Called\n");
    if (sBgmPlayState == 0) {
        sBgmPlayState = 3;
    }
}

// Na_PauseSet
void Audio_HandlePause(u8 status) {

    PRINTF("Pause Called!! Status =  %02x\n", status);

    switch (status) {
        case 0:
            sAudioPauseStatus = 0;
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 1.0f);
            break;
        case 1:
            sAudioPauseStatus = 1;
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.4f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 2, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 3, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 4, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 5, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 6, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 7, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 8, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 9, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, 0.0f);
            break;
        case 2:
            Audio_StopChannelSE(0);
            Audio_StopChannelSE(2);
            Audio_StopChannelSE(3);
            Audio_StopChannelSE(4);
            Audio_StopChannelSE(5);
            Audio_StopChannelSE(6);
            Audio_StopChannelSE(7);
            Audio_StopChannelSE(8);
            Audio_StopChannelSE(9);
            Audio_StopChannelSE(14);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 2, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 3, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 4, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 5, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 6, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 7, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 8, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 9, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, 0.0f);
            sAudioPauseStatus = 2;
            break;
    }
}

void Audio_SetSpec(s32 specId) {
    if (specId != sPreviousSpecId) {
        PRINTF("Spec Change No = %02x\n", specId);
        sPreviousSpecId = specId;
        AudioThread_ResetAudioHeap(specId);

        do { } while (!AudioThread_ResetComplete()); }
}

void Audio_SetPlayerMode(u8 numPlayersIndex) {
    PRINTF("Player Mode = %02x\n", numPlayersIndex);
    sAudioPlayerMode = numPlayersIndex;
}

void Audio_AllSoundStop(void) {
    PRINTF("All Sound Off\n");
    Audio_ResetSoundData();
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(0, 0);
    Audio_SetSpec(0);
    AudioThread_ScheduleProcessCmds();
}

// Na_SeSeq_Start
void Audio_SESeqStart(void) {
    PRINTF("Na_SeSeq_Start for ROM Called\n");
    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(0, 0, 0, 0);
    AudioThread_ScheduleProcessCmds();
}

// Na_ChangeSoundMode
void func_800BB39C(s32 courseIndex) {
    PRINTF("Change Sound Mode No = %02x\n", courseIndex);
    Audio_ResetSoundData();
#ifndef VERSION_JP
    AudioThread_ScheduleProcessCmds();
#endif
}

// Na_chakuchi
void Audio_Chakuchi(u8 racerId, f32 volume) {
    PRINTF("Na_chakuchi Called player = %02x volume = %f \n", racerId, volume);

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
    PRINTF("Na_chakuchi Edited volume = %f \n", sRacerAudioVolume[racerId]);
    Audio_PlayerTriggerSE(racerId, 0x36);
}

void Audio_DisablePlayerSE(void) {
    sPlayerSEStatus = 1;
}

// Na_Guitor_Start
void Audio_GuitarSeqStart(void) {
    PRINTF("Na_Guitor_Start Called\n");
    PRINTF("Na_Guitor_Start for ROM Called\n");
    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, 1, 0, 0);
    Audio_SESeqStart();
}

AudioTask* Audio_SetupCreateTask(void) {
    AudioTask* curAudioTask;

    Audio_BGMFadeout();
    Audio_LevelSEFadeoutRoutine();
    Audio_BGMFadeoutPause();
    AudioThread_ScheduleProcessCmds();
    gCurAudioTask = curAudioTask = AudioThread_CreateTask();
    return curAudioTask;
}
