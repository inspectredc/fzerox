#include "global.h"
#include "audio.h"
#include "audiothread_cmd.h"
#include "fzx_racer.h"
#include "fzx_game.h"

void func_800BAE98(u8 channelIndex, u8 ioData);
void func_800BAEDC(u8);
void func_800BA7C0(u8);
void func_800BB45C(void);

s32 func_800B71D0(u8 arg0) {
    u8 var_v1;

    if (arg0 == 0x3F) {
        return 0x3F;
    }

    if (arg0 >= 0x40) {
        var_v1 = (arg0 >= 0x5F) ? 0x7F : arg0 * 2 - 0x3F;
        return var_v1;
    }

    if (arg0 < 0x3F) {
        var_v1 = (arg0 < 0x20) ? 0 : arg0 * 2 - 0x3F;
        return var_v1;
    }
}

extern u8 D_800D1A18;
extern u8 D_800D1BF8[][8];

void func_800B7244(u8 playerNum, u8 arg1) {

    if (D_800D1BF8[playerNum][0] == 0) {
        D_800D1BF8[playerNum][0] = arg1;
    } else if (D_800D1BF8[playerNum][1] == 0) {
        D_800D1BF8[playerNum][1] = D_800D1BF8[playerNum][0];
        D_800D1BF8[playerNum][0] = arg1;
    } else if (D_800D1BF8[playerNum][2] == 0) {
        D_800D1BF8[playerNum][2] = D_800D1BF8[playerNum][1];
        D_800D1BF8[playerNum][1] = D_800D1BF8[playerNum][0];
        D_800D1BF8[playerNum][0] = arg1;
    } else if (D_800D1BF8[playerNum][3] == 0) {
        D_800D1BF8[playerNum][3] = D_800D1BF8[playerNum][2];
        D_800D1BF8[playerNum][2] = D_800D1BF8[playerNum][1];
        D_800D1BF8[playerNum][1] = D_800D1BF8[playerNum][0];
        D_800D1BF8[playerNum][0] = arg1;
    } else if (D_800D1BF8[playerNum][4] == 0) {
        D_800D1BF8[playerNum][4] = D_800D1BF8[playerNum][3];
        D_800D1BF8[playerNum][3] = D_800D1BF8[playerNum][2];
        D_800D1BF8[playerNum][2] = D_800D1BF8[playerNum][1];
        D_800D1BF8[playerNum][1] = D_800D1BF8[playerNum][0];
        D_800D1BF8[playerNum][0] = arg1;
    } else if (D_800D1BF8[playerNum][5] == 0) {
        D_800D1BF8[playerNum][5] = D_800D1BF8[playerNum][4];
        D_800D1BF8[playerNum][4] = D_800D1BF8[playerNum][3];
        D_800D1BF8[playerNum][3] = D_800D1BF8[playerNum][2];
        D_800D1BF8[playerNum][2] = D_800D1BF8[playerNum][1];
        D_800D1BF8[playerNum][1] = D_800D1BF8[playerNum][0];
        D_800D1BF8[playerNum][0] = arg1;
    } else if (D_800D1BF8[playerNum][6] == 0) {
        D_800D1BF8[playerNum][6] = D_800D1BF8[playerNum][5];
        D_800D1BF8[playerNum][5] = D_800D1BF8[playerNum][4];
        D_800D1BF8[playerNum][4] = D_800D1BF8[playerNum][3];
        D_800D1BF8[playerNum][3] = D_800D1BF8[playerNum][2];
        D_800D1BF8[playerNum][2] = D_800D1BF8[playerNum][1];
        D_800D1BF8[playerNum][1] = D_800D1BF8[playerNum][0];
        D_800D1BF8[playerNum][0] = arg1;
    } else if (D_800D1BF8[playerNum][7] == 0) {
        D_800D1BF8[playerNum][7] = D_800D1BF8[playerNum][6];
        D_800D1BF8[playerNum][6] = D_800D1BF8[playerNum][5];
        D_800D1BF8[playerNum][5] = D_800D1BF8[playerNum][4];
        D_800D1BF8[playerNum][4] = D_800D1BF8[playerNum][3];
        D_800D1BF8[playerNum][3] = D_800D1BF8[playerNum][2];
        D_800D1BF8[playerNum][2] = D_800D1BF8[playerNum][1];
        D_800D1BF8[playerNum][1] = D_800D1BF8[playerNum][0];
        D_800D1BF8[playerNum][0] = arg1;
    }
    switch (D_800D1A18) {
        case 0:
            func_800B6934(0x03000600, 0x3F);
            func_800BAE98(6, arg1);
            break;
        case 1:
            switch (playerNum) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    func_800BAE98(6, arg1 + 10);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0x7F);
                    func_800BAE98(7, arg1 + 10);
                    break;
            }
            break;
        case 2:
            switch (playerNum) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    func_800BAE98(6, arg1 + 20);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0);
                    func_800BAE98(7, arg1 + 20);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 8, 0x7F);
                    func_800BAE98(8, arg1 + 20);
                    break;
            }
            break;
        case 3:
            switch (playerNum) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    func_800BAE98(6, arg1 + 20);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0);
                    func_800BAE98(7, arg1 + 20);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 8, 0x7F);
                    func_800BAE98(8, arg1 + 20);
                    break;
                case 3:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 9, 0x7F);
                    func_800BAE98(9, arg1 + 20);
                    break;
            }
            break;
    }
}

extern u8 D_800D1BE8[][4];

void func_800B759C(u8 arg0) {

    if (D_800D1BE8[arg0][0] != 0) {
        func_800B7244(arg0, D_800D1BE8[arg0][0]);
        D_800D1BE8[arg0][0] = D_800D1BE8[arg0][1];
        D_800D1BE8[arg0][1] = D_800D1BE8[arg0][2];
        D_800D1BE8[arg0][2] = D_800D1BE8[arg0][3];
        D_800D1BE8[arg0][3] = 0;
    }
}

extern u8 D_800D1A1C;
extern u8 D_800D1A20;
extern f32 D_800D1A30;
extern f32 D_800D1A38;
extern u8 D_800D1A3C;
extern u8 D_800D1A74[];
extern u8 D_800D1AD8[];
extern f32 D_800D1AF8[];
extern unk_struct_1DC D_800E5220[];

void func_800B7600(u8 arg0, u8 arg1) {
    f32 volumeScale;
    f32 freqScale;
    f32 var_fv1;
    Vec3f vec;
    u8 pan;

    if ((D_800D1A74[arg0] != 0) || (arg1 == 0x16) || (arg1 == 0x10) || (arg1 == 0x21) || (arg1 == 0x1E) ||
        (arg1 == 5) || (arg1 == 8) || (arg1 == 0xF) || (arg1 == 0x30) || (arg1 == 0x31) || (arg1 == 0x34) ||
        (arg1 == 0x35) || (arg1 == 0x3E)) {
        D_800D1AD8[arg0] = arg1;
        switch (D_800D1A18) {
            case 0:
                if (arg0 == 0) {
                    AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0x3F);
                    volumeScale = D_800D1AF8[arg0];
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);

                    if (arg1 >= 0x3F || arg1 < 0) {
                        arg1 = 0;
                    }
                    func_800BAE98(10, arg1);
                } else if (D_800D1A1C != 0) {
                    if (arg0 == D_800D1A20) {
                        var_fv1 = D_800D1A30;
                    } else {
                        vec.x = gRacers[arg0].unk_0C.unk_34.x - D_800E5220[0].unk_50.x;
                        vec.y = gRacers[arg0].unk_0C.unk_34.y - D_800E5220[0].unk_50.y;
                        vec.z = gRacers[arg0].unk_0C.unk_34.z - D_800E5220[0].unk_50.z;

                        var_fv1 = sqrtf(SQ_SUM(&vec));
                    }
                    if ((var_fv1 < 10000.0f) && (var_fv1 > 0.0f)) {
                        volumeScale = (-(9.0f / 190000.0f) * var_fv1) + 1.0f;
                        if (volumeScale > 0.3f) {
                            if (volumeScale > 0.85f) {
                                volumeScale = 0.85f;
                            }

                            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 15, volumeScale);
                            if (arg0 == D_800D1A20) {
                                freqScale = (D_800D1A38 * (2.0f / 7.0f)) + 0.2f;
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

                            if (arg0 == D_800D1A20) {
                                pan = func_800B71D0(D_800D1A3C);
                            } else {
                                pan = 0x3F;
                            }
                            AUDIOCMD_CHANNEL_SET_PAN(0, 15, pan);
                            func_800BAE98(15, arg1);
                        }
                    }
                }
                break;
            case 1:
                volumeScale = D_800D1AF8[arg0] * 0.9f;
                switch (arg0) {
                    case 0:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);
                        func_800BAE98(10, arg1);
                        break;
                    case 1:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 11, 0x7F);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 11, volumeScale);
                        func_800BAE98(11, arg1);
                        break;
                }
                break;
            case 2:
                volumeScale = D_800D1AF8[arg0] * 0.85f;
                switch (arg0) {
                    case 0:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);
                        func_800BAE98(10, arg1);
                        break;
                    case 1:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 11, 0);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 11, volumeScale);
                        func_800BAE98(11, arg1);
                        break;
                    case 2:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 12, 0x7F);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 12, volumeScale);
                        func_800BAE98(12, arg1);
                        break;
                }
                break;
            case 3:
                volumeScale = D_800D1AF8[arg0] * 0.85f;
                switch (arg0) {
                    case 0:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);
                        func_800BAE98(10, arg1);
                        break;
                    case 1:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 11, 0);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 11, volumeScale);
                        func_800BAE98(11, arg1);
                        break;
                    case 2:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 12, 0x7F);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 12, volumeScale);
                        func_800BAE98(12, arg1);
                        break;
                    case 3:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 13, 0x7F);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 13, volumeScale);
                        func_800BAE98(13, arg1);
                        break;
                }
                break;
        }
    }
}

extern u8 D_800D1B70[][4];

void func_800B7C40(u8 racerId) {

    if (D_800D1B70[racerId][0] != 0) {
        func_800B7600(racerId, D_800D1B70[racerId][0]);
        D_800D1B70[racerId][0] = D_800D1B70[racerId][1];
        D_800D1B70[racerId][1] = D_800D1B70[racerId][2];
        D_800D1B70[racerId][2] = D_800D1B70[racerId][3];
        D_800D1B70[racerId][3] = 0;
    }
}

extern u8 D_800D1A40;
extern u16 D_800D1A50;
extern u8 D_800D1A58;
extern u8 D_800D1A90[];
extern f32 D_800D1A98[];
extern u8 D_800D1C00;
extern u8 D_800D1C08;
extern u8 D_800D1C10;

void func_800B7CA4(void) {
    f32 volumeScale;
    s8 reverbVolume;

    if (D_800D1A58 == 0 || D_800D1A40 == 2) {
        return;
    }

    D_800D1A50++;
    if (D_800D1A50 == 29) {
        D_800D1A58 = 0;
        D_800D1A50 = 0;
        func_800BAEDC(2);
        func_800BAEDC(3);
        func_800BAEDC(4);
        func_800BAEDC(5);
        func_800BAEDC(6);
        func_800BAEDC(7);
        func_800BAEDC(8);
        func_800BAEDC(9);
        func_800BAEDC(14);
        D_800D1A74[0] = 0;
        D_800D1A74[1] = 0;
        D_800D1A74[2] = 0;
        D_800D1A74[3] = 0;
        return;
    }
    reverbVolume = 0x50 - (D_800D1A50 * 2);
    if (D_800D1A74[0] == 1) {
        volumeScale = D_800D1A98[2] - ((D_800D1A98[2] / 30.0f) * D_800D1A50);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 2, volumeScale);
        if (D_800D1A90[0] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, reverbVolume);
        }
    }
    if (D_800D1A74[1] == 1) {
        volumeScale = D_800D1A98[3] - ((D_800D1A98[3] / 30.0f) * D_800D1A50);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 3, volumeScale);
        if (D_800D1A90[1] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, reverbVolume);
        }
    }
    if (D_800D1A74[2] == 1) {
        volumeScale = D_800D1A98[4] - ((D_800D1A98[4] / 30.0f) * D_800D1A50);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 4, volumeScale);
        if (D_800D1A90[2] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, reverbVolume);
        }
    }
    if (D_800D1A74[3] == 1) {
        volumeScale = D_800D1A98[5] - ((D_800D1A98[5] / 30.0f) * D_800D1A50);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 5, volumeScale);
        if (D_800D1A90[3] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 5, reverbVolume);
        }
    }
    if ((D_800D1A74[0] != 0) && (D_800D1BF8[0][0] != 0) && (D_800D1A98[6] != 0.0f)) {
        volumeScale = D_800D1A98[6] - ((D_800D1A98[6] / 30.0f) * D_800D1A50);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 6, volumeScale);
        if (D_800D1A90[0] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, reverbVolume);
        }
    }
    if ((D_800D1A74[1] != 0) && (D_800D1C00 != 0) && (D_800D1A98[7] != 0.0f)) {
        volumeScale = D_800D1A98[7] - ((D_800D1A98[7] / 30.0f) * D_800D1A50);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 7, volumeScale);
        if (D_800D1A90[1] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, reverbVolume);
        }
    }
    if ((D_800D1A74[2] != 0) && (D_800D1C08 != 0) && (D_800D1A98[8] != 0.0f)) {
        volumeScale = D_800D1A98[8] - ((D_800D1A98[8] / 30.0f) * D_800D1A50);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 8, volumeScale);
        if (D_800D1A90[2] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, reverbVolume);
        }
    }
    if ((D_800D1A74[3] != 0) && (D_800D1C10 != 0) && (D_800D1A98[9] != 0.0f)) {
        volumeScale = D_800D1A98[9] - ((D_800D1A98[9] / 30.0f) * D_800D1A50);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 9, volumeScale);
        if (D_800D1A90[3] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 9, reverbVolume);
        }
    }
    if ((D_800D1A1C != 0) && (D_800D1A98[14] != 0.0f)) {
        volumeScale = D_800D1A98[14] - ((D_800D1A98[14] / 30.0f) * D_800D1A50);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, volumeScale);
        if (D_800D1A90[0] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, reverbVolume);
        }
    }
}

extern u8 D_800D1A48;
extern u16 D_800D1A4C;

void func_800B82C8(void) {
    f32 volumeScale;

    switch (D_800D1A48) {
        case 0:
            break;
        case 1:
            if (++D_800D1A4C == (70 / 2) - 1) {
                D_800D1A48 = 0;
                D_800D1A4C = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                func_800BAEDC(0);
            } else {
                volumeScale = 1.0f - (D_800D1A4C * (2.0f / 70.0f));
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
            break;
        case 2:
            if (++D_800D1A4C == (70 / 1) - 1) {
                D_800D1A48 = 0;
                D_800D1A4C = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                func_800BAEDC(0);
            } else {
                volumeScale = 1.0f - (D_800D1A4C * (1.0f / 70.0f));
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
            break;
        case 3:
            if (++D_800D1A4C == (700 / 2) - 1) {
                D_800D1A48 = 0;
                D_800D1A4C = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                func_800BAEDC(0);
            } else {
                volumeScale = 1.0f - (D_800D1A4C * (2.0f / 700.0f));
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
            break;
    }
}

extern s32 gNumPlayers;
extern s8 D_800CD010;
extern u8 D_800D1A60;
extern s32 gGameMode;

void func_800B84B8(void) {
    s32 temp_lo;
    SequenceLayer* layer;
    Note* note;

    if ((D_800D1A60 == 0xD) && (&gSeqChannelNone != gSeqPlayers[0].channels[0])) {
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

extern u16 D_800D1A44;

void func_800B8598(void) {
    f32 volumeScale;

    if (D_800D1A40 == 2) {
        if (++D_800D1A44 == 0x31) {
            D_800D1A40 = 0;
            D_800D1A44 = 0;
            func_800BAEDC(0);
        } else {
            volumeScale = 0.4f - (D_800D1A44 * 0.008f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
        }
    }
}

extern u8 D_800D19E0;
extern u8 D_800D1A08;
extern u8 D_800D1A24;
extern f32 D_800D1A28;
extern f32 D_800D1A2C;
extern f32 D_800D1A34;
extern u8 D_800D1A8C[];
extern f32 D_800D1AD0;

void func_800B8640(void) {
    Vec3f vec;

    if ((D_800D19E0 != 1) && (D_800D1A18 == 0) && (D_800D1A20 != 0) && (D_800D1A40 != 1) && (D_800D1A40 != 2) &&
        ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) &&
        (D_800D1A58 == 0)) {
        vec.x = gRacers[D_800D1A20].unk_0C.unk_34.x - D_800E5220[0].unk_50.x;
        vec.y = gRacers[D_800D1A20].unk_0C.unk_34.y - D_800E5220[0].unk_50.y;
        vec.z = gRacers[D_800D1A20].unk_0C.unk_34.z - D_800E5220[0].unk_50.z;
        D_800D1A30 = sqrtf(SQ_SUM(&vec));
        if ((D_800D1A30 < 820.0f) && (D_800D1A30 != 0.0f)) {
            if (D_800D1A1C == 0) {
                if (D_800D1A8C[0] == 0) {
                    if (D_800D1A08 == 0) {
                        func_800BAE98(14, 1);
                    }
                    D_800D1A1C = 2;
                }
            } else {
                D_800D1A1C = 1;
            }
        } else {
            if (D_800D1A1C == 1) {
                func_800BAEDC(14);
                D_800D1A1C = 0;
            }
        }
        if (D_800D1A1C != 0) {
            D_800D1A34 = 1.0f - (D_800D1A30 * (1.0f / 1000.0f));
            if (D_800D1A34 > 0.9f) {
                D_800D1A34 = 0.9f;
            }
            if (D_800D1A34 < 0.001f) {
                D_800D1A34 = 0.001f;
            }
            if (D_800D1A20 == D_800D1A24) {
                D_800D1A2C = (D_800D1A28 - D_800D1A30) * (1.0f / 30.0f);
            }
            D_800D1A28 = D_800D1A30;
            D_800D1A24 = D_800D1A20;

            D_800D1A38 = ((gRacers[D_800D1A20].unk_98 + 0.01f) * (1.0f / 21.0f)) + 0.5f + D_800D1A2C;
            if (D_800D1A38 < 0.1f) {
                D_800D1A38 = 0.1f;
            }

            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, D_800D1A34);
            D_800D1AD0 = D_800D1A34;
            AUDIOCMD_CHANNEL_SET_PAN(0, 14, func_800B71D0(D_800D1A3C));
            AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, 14, D_800D1A38);
        }
    }
}

extern f32 D_800D1A64[];
extern u8 D_800D1A78[];
extern f32 D_800D1A7C[];
extern f32 D_800D1AA0[];
extern u8 D_800D1A94[];

void func_800B899C(u8 arg0) {
    f32 freqScale;
    f32 volumeScale;

    if ((D_800D1A40 != 1) && (D_800D1A40 != 2)) {
        if (D_800D1A74[arg0] == 0) {
            if (D_800D1A94[arg0] == 0) {
                return;
            }
        }

        if (gRacers[arg0].unk_98 < D_800D1A7C[arg0]) {
            D_800D1A78[arg0] = 1;
        } else {
            D_800D1A78[arg0] = 0;
        }
        D_800D1A7C[arg0] = gRacers[arg0].unk_98;
        if (D_800D1A94[arg0] == 0) {
            if ((gRacers[arg0].unk_1D4 != 0.0f) && (gRacers[arg0].unk_98 > 27.0f)) {
                if (D_800D1A78[arg0] == 1) {
                    if (D_800D1A64[arg0] > -0.5f) {
                        D_800D1A64[arg0] -= 0.004f;
                    }
                } else {
                    D_800D1A64[arg0] += 0.004f;
                }
            } else {
                D_800D1A64[arg0] = 0.0f;
            }
            if (gRacers[arg0].unk_20C != 0) {
                D_800D1A64[arg0] = 0.0f;
            }
        } else {
            // FAKE
        }

        freqScale = (((0.01f + gRacers[arg0].unk_98) * (1.0f / 21.0f)) + 0.25f) + D_800D1A64[arg0];
        AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, arg0 + 2, freqScale);

        if ((gRacers[arg0].unk_1D4 == 0.0f) && (gRacers[arg0].unk_1D8 == 0.0f)) {
            if (D_800D1A94[arg0] == 1) {
                Vec3f vec;
                f32 temp;

                vec.x = gRacers[arg0].unk_0C.unk_34.x - D_800E5220[arg0].unk_50.x;
                vec.y = gRacers[arg0].unk_0C.unk_34.y - D_800E5220[arg0].unk_50.y;
                vec.z = gRacers[arg0].unk_0C.unk_34.z - D_800E5220[arg0].unk_50.z;
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
        } else if (D_800D1A94[arg0] == 1) {
            Vec3f vec;
            f32 temp;

            vec.x = gRacers[arg0].unk_0C.unk_34.x - D_800E5220[arg0].unk_50.x;
            vec.y = gRacers[arg0].unk_0C.unk_34.y - D_800E5220[arg0].unk_50.y;
            vec.z = gRacers[arg0].unk_0C.unk_34.z - D_800E5220[arg0].unk_50.z;
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

        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, arg0 + 2, volumeScale);
        D_800D1AA0[(s32) arg0] = volumeScale;
    }
}

extern u8 D_800D1A40;
extern u8 D_800D1A58;
extern f32 D_800D1AB0[];

void func_800B8DAC(u8 arg0) {
    f32 freqScale;
    f32 volumeScale;

    if ((D_800D1A40 != 1) && (D_800D1A40 != 2) && (D_800D1A74[arg0] != 0) && (D_800D1A58 == 0)) {
        switch (D_800D1BF8[arg0][0]) {
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
                volumeScale = (gRacers[arg0].unk_98 * (1.0f / 45.0f)) + 0.5f;
                if (gRacers[arg0].unk_98 < 0.1f) {
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
                volumeScale = (gRacers[arg0].unk_98 * (1.0f / 45.0f)) + 0.5f;
                if (gRacers[arg0].unk_98 < 0.1f) {
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
                freqScale = (gRacers[arg0].unk_98 * (1.0f / 30.0f)) - (8.0f / 10.0f);
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
                freqScale = gRacers[arg0].unk_98 * (1.0f / 20.0f);
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
                if (gRacers[arg0].unk_5C.x > 0.0f) {
                    volumeScale = gRacers[arg0].unk_5C.x * (2.0f / 30.0f);
                    freqScale = (gRacers[arg0].unk_5C.x * (1.0f / 80.0f)) + 1.0f;
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
                    volumeScale = -gRacers[arg0].unk_5C.x * (1.0f / 15.0f);
                    freqScale = (-gRacers[arg0].unk_5C.x * (1.0f / 80.0f)) + 1.0f;
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

        D_800D1AB0[(s32) arg0] = volumeScale;
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, arg0 + 6, volumeScale);
        AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, arg0 + 6, freqScale);
    }
}

void func_800B9240(u8 arg0) {
    switch (D_800D1A18) {
        case 0:
            if (D_800D1A90[0] == 1) {
                gSynthReverbs[0].volume = 0x7FFF;
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, 80);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 15, 80);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((D_800D1AD8[0] == 19) || (D_800D1AD8[0] == 20) || (D_800D1AD8[0] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((D_800D1BF8[0][0] == 3) || (D_800D1BF8[0][0] == 4)) {
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
            if ((D_800D1A90[0] == 1) || (D_800D1A90[1] == 1)) {
                gSynthReverbs[0].volume = 0x7FFF;
            } else {
                gSynthReverbs[0].volume = 0;
            }
            if (D_800D1A90[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((D_800D1AD8[0] == 19) || (D_800D1AD8[0] == 20) || (D_800D1AD8[0] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((D_800D1BF8[0][0] == 3) || (D_800D1BF8[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            if (D_800D1A90[1] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 80);
                if ((D_800D1AD8[1] == 19) || (D_800D1AD8[1] == 20) || (D_800D1AD8[1] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 80);
                }
                if ((D_800D1C00 == 3) || (D_800D1C00 == 4)) {
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
            if ((D_800D1A90[0] == 1) || (D_800D1A90[1] == 1) || (D_800D1A90[2] == 1)) {
                gSynthReverbs[0].volume = 0x7FFF;
            } else {
                gSynthReverbs[0].volume = 0;
            }
            if (D_800D1A90[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((D_800D1AD8[0] == 19) || (D_800D1AD8[0] == 20) || (D_800D1AD8[0] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((D_800D1BF8[0][0] == 3) || (D_800D1BF8[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            if (D_800D1A90[1] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 80);
                if ((D_800D1AD8[1] == 19) || (D_800D1AD8[1] == 20) || (D_800D1AD8[1] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 80);
                }
                if ((D_800D1C00 == 3) || (D_800D1C00 == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
            }
            if (D_800D1A90[2] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 80);
                if ((D_800D1AD8[2] == 19) || (D_800D1AD8[2] == 20) || (D_800D1AD8[2] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 80);
                }
                if ((D_800D1C08 == 3) || (D_800D1C08 == 4)) {
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
            if ((D_800D1A90[0] == 1) || (D_800D1A90[1] == 1) || (D_800D1A90[2] == 1) || (D_800D1A90[3] == 1)) {
                gSynthReverbs[0].volume = 0x7FFF;
            } else {
                gSynthReverbs[0].volume = 0;
            }
            if (D_800D1A90[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((D_800D1AD8[0] == 19) || (D_800D1AD8[0] == 20) || (D_800D1AD8[0] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((D_800D1BF8[0][0] == 3) || (D_800D1BF8[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            if (D_800D1A90[1] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 80);
                if ((D_800D1AD8[1] == 19) || (D_800D1AD8[1] == 20) || (D_800D1AD8[1] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 80);
                }
                if ((D_800D1C00 == 3) || (D_800D1C00 == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
            }
            if (D_800D1A90[2] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 80);
                if ((D_800D1AD8[2] == 19) || (D_800D1AD8[2] == 20) || (D_800D1AD8[2] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 80);
                }
                if ((D_800D1C08 == 3) || (D_800D1C08 == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
            }
            if (D_800D1A90[3] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 5, 80);
                if ((D_800D1AD8[3] == 19) || (D_800D1AD8[3] == 20) || (D_800D1AD8[3] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 13, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 13, 80);
                }
                if ((D_800D1C10 == 3) || (D_800D1C10 == 4)) {
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

extern u8 D_800D19E4;
extern u8 D_800D19E8;
extern u8 D_800D19EC;
extern u8 D_800D19F0;
extern u8 D_800D19F4;
extern u16 D_800D19F8;
extern u16 D_800D19FC;
extern u16 D_800D1A00;
extern u16 D_800D1A04;

void func_800B9C54(void) {

    if ((D_800D19E4 == 0) && (D_800D19E8 != 0)) {
        func_800BA7C0(D_800D19E8);
    }

    D_800D19E4 = D_800D19E8;
    if (D_800D19F8 != 0) {
        D_800D19F8--;
        if (D_800D19F8 == 0) {
            D_800D19E8 = D_800D19EC;
            D_800D19F8 = D_800D19FC;
            D_800D19EC = D_800D19F0;
            D_800D19FC = D_800D1A00;
            D_800D19F0 = D_800D19F4;
            D_800D1A00 = D_800D1A04;
            D_800D19E4 = 0;
            D_800D19F4 = 0;
            D_800D1A04 = 0;
        }
    }
}

void func_800B9D3C(void) {
    u8 i;

    func_800B8640();
    func_800B84B8();
    func_800B9C54();

    for (i = 0; i < D_800D1A18 + 1; i++) {
        func_800B899C(i);
        func_800B9240(i);
        func_800B759C(i);
        func_800B8DAC(i);
    }

    if (D_800D1A18 == 0) {
        for (i = 0; i < 30; i++) {
            func_800B7C40(i);
        }
    } else {
        for (i = 0; i < D_800D1A18 + 1; i++) {
            func_800B7C40(i);
        }
    }
}

void func_800B9E28(void) {
    func_800B9D3C();
    func_800B6994();
}

void func_800B9E50(s32 seqPlayerIndex, s32 channelIndex, s32 muted) {
    AUDIOCMD_CHANNEL_SET_MUTE(seqPlayerIndex, channelIndex, muted);
}

void func_800B9E94(void) {
    AUDIOCMD_GLOBAL_SYNC_LOAD_INSTRUMENT(0, 0x7F, 0);
}

void func_800B9EBC(s32 arg0, s32 arg1, s32 arg2) {
}

void func_800B9ECC(void) {
}

extern u8 D_800D1A0C;

void func_800B9ED4(void) {
    u8 i;

    func_800BAEDC(0);
    func_800BAEDC(2);
    func_800BAEDC(3);
    func_800BAEDC(4);
    func_800BAEDC(5);
    func_800BAEDC(6);
    func_800BAEDC(7);
    func_800BAEDC(8);
    func_800BAEDC(9);
    func_800BAEDC(14);
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
    D_800D19E0 = 0;
    D_800D1A08 = 0;
    D_800D1A0C = 0;
    D_800D1A1C = 0;
    D_800D1A20 = 0;
    D_800D1A24 = 0;
    D_800D1A28 = 0.0f;
    D_800D1A2C = 1.0f;
    D_800D1A30 = 0.0f;
    D_800D1A34 = 0.0f;
    D_800D1A38 = 0.0f;
    D_800D1A3C = 64;
    D_800D1A40 = 0;
    D_800D1A58 = 0;
    D_800D1A50 = 0;
    D_800D1A48 = 0;

    for (i = 0; i < 4; i++) {
        D_800D1A64[i] = 0.0f;
        D_800D1A74[i] = 0;
        D_800D1A78[i] = 0;
        D_800D1A7C[i] = 0;
        D_800D1A8C[i] = 0;
        D_800D1BF8[i][0] = 0;
        D_800D1BF8[i][1] = 0;
        D_800D1BF8[i][2] = 0;
        D_800D1BF8[i][3] = 0;
        D_800D1BF8[i][4] = 0;
        D_800D1BF8[i][5] = 0;
        D_800D1BF8[i][6] = 0;
        D_800D1BF8[i][7] = 0;
        D_800D1A90[i] = 0;
        D_800D1AD8[i] = 0;
        D_800D1BE8[i][0] = 0;
        D_800D1BE8[i][1] = 0;
        D_800D1BE8[i][2] = 0;
        D_800D1BE8[i][3] = 0;
        D_800D1A94[i] = 0;
    }

    for (i = 0; i < 16; i++) {
        D_800D1A98[i] = 0.0f;
    }

    for (i = 0; i < 30; i++) {
        D_800D1B70[i][0] = 0;
        D_800D1B70[i][1] = 0;
        D_800D1B70[i][2] = 0;
        D_800D1B70[i][3] = 0;
    }
}

void func_800BA248(void) {
    func_800B6F58();
}

void func_800BA268(void) {
    func_800B079C(NULL, 0);
}

void func_800BA28C(u8 soundMode) {
    AUDIOCMD_GLOBAL_SET_SOUND_MODE(soundMode);
}

void func_800BA2B4(u8 arg0) {
    D_800D1A8C[arg0] = 1;
}

void func_800BA2D0(u8 arg0) {
    D_800D1A3C = arg0;
}

void func_800BA2E0(u8 arg0) {
    D_800D1A20 = arg0;
}

void func_800BA2F0(u8 playerNum, u8 arg1) {

    if ((D_800D1A8C[playerNum] != 1) && (arg1 != D_800D1BF8[playerNum][0]) && (arg1 != D_800D1BF8[playerNum][1]) &&
        (arg1 != D_800D1BF8[playerNum][2]) && (arg1 != D_800D1BF8[playerNum][3]) &&
        (arg1 != D_800D1BF8[playerNum][4]) && (arg1 != D_800D1BF8[playerNum][5]) &&
        (arg1 != D_800D1BF8[playerNum][6]) && (arg1 != D_800D1BF8[playerNum][7])) {
        if (D_800D1BE8[playerNum][0] != 0) {
            if (D_800D1BE8[playerNum][1] != 0) {
                if (D_800D1BE8[playerNum][2] != 0) {
                    if (D_800D1BE8[playerNum][3] == 0) {
                        D_800D1BE8[playerNum][3] = arg1;
                    }
                } else {
                    D_800D1BE8[playerNum][2] = arg1;
                }
            } else {
                D_800D1BE8[playerNum][1] = arg1;
            }
        } else {
            D_800D1BE8[playerNum][0] = arg1;
        }
    }
}

void func_800BA3E4(u8 playerNum, u8 arg1) {
    s32 temp;

    if (arg1 == D_800D1BE8[playerNum][0]) {
        D_800D1BE8[playerNum][0] = 0;
        if (D_800D1BE8[playerNum][1] != 0) {
            D_800D1BE8[playerNum][0] = D_800D1BE8[playerNum][1];
            D_800D1BE8[playerNum][1] = D_800D1BE8[playerNum][2];
            D_800D1BE8[playerNum][2] = D_800D1BE8[playerNum][3];
            D_800D1BE8[playerNum][3] = 0;
        }
    }
    if (arg1 == D_800D1BE8[playerNum][1]) {
        D_800D1BE8[playerNum][1] = 0;
        if (D_800D1BE8[playerNum][2] != 0) {
            D_800D1BE8[playerNum][1] = D_800D1BE8[playerNum][2];
            D_800D1BE8[playerNum][2] = D_800D1BE8[playerNum][3];
            D_800D1BE8[playerNum][3] = 0;
        }
    }
    if (arg1 == D_800D1BE8[playerNum][2]) {
        D_800D1BE8[playerNum][2] = 0;
        if (D_800D1BE8[playerNum][3] != 0) {
            D_800D1BE8[playerNum][2] = D_800D1BE8[playerNum][3];
            D_800D1BE8[playerNum][3] = 0;
        }
    }
    if (arg1 == D_800D1BE8[playerNum][3]) {
        D_800D1BE8[playerNum][3] = 0;
    }

    if (arg1 == D_800D1BF8[playerNum][0]) {
        D_800D1BF8[playerNum][0] = D_800D1BF8[playerNum][1];
        D_800D1BF8[playerNum][1] = D_800D1BF8[playerNum][2];
        D_800D1BF8[playerNum][2] = D_800D1BF8[playerNum][3];
        D_800D1BF8[playerNum][3] = D_800D1BF8[playerNum][4];
        D_800D1BF8[playerNum][4] = D_800D1BF8[playerNum][5];
        D_800D1BF8[playerNum][5] = D_800D1BF8[playerNum][6];
        D_800D1BF8[playerNum][6] = D_800D1BF8[playerNum][7];
        D_800D1BF8[playerNum][7] = 0;
        if (D_800D1BF8[playerNum][0] == 0) {
            func_800BAEDC(playerNum + 6);
        } else {
            func_800BAEDC(playerNum + 6);
            temp = D_800D1BF8[playerNum][0];
            D_800D1BF8[playerNum][0] = 0;
            func_800BA2F0(playerNum, temp);
        }
    } else if (arg1 == D_800D1BF8[playerNum][1]) {
        D_800D1BF8[playerNum][1] = D_800D1BF8[playerNum][2];
        D_800D1BF8[playerNum][2] = D_800D1BF8[playerNum][3];
        D_800D1BF8[playerNum][3] = D_800D1BF8[playerNum][4];
        D_800D1BF8[playerNum][4] = D_800D1BF8[playerNum][5];
        D_800D1BF8[playerNum][5] = D_800D1BF8[playerNum][6];
        D_800D1BF8[playerNum][6] = D_800D1BF8[playerNum][7];
        D_800D1BF8[playerNum][7] = 0;
    } else if (arg1 == D_800D1BF8[playerNum][2]) {
        D_800D1BF8[playerNum][2] = D_800D1BF8[playerNum][3];
        D_800D1BF8[playerNum][3] = D_800D1BF8[playerNum][4];
        D_800D1BF8[playerNum][4] = D_800D1BF8[playerNum][5];
        D_800D1BF8[playerNum][5] = D_800D1BF8[playerNum][6];
        D_800D1BF8[playerNum][6] = D_800D1BF8[playerNum][7];
        D_800D1BF8[playerNum][7] = 0;
    } else if (arg1 == D_800D1BF8[playerNum][3]) {
        D_800D1BF8[playerNum][3] = D_800D1BF8[playerNum][4];
        D_800D1BF8[playerNum][4] = D_800D1BF8[playerNum][5];
        D_800D1BF8[playerNum][5] = D_800D1BF8[playerNum][6];
        D_800D1BF8[playerNum][6] = D_800D1BF8[playerNum][7];
        D_800D1BF8[playerNum][7] = 0;
    } else if (arg1 == D_800D1BF8[playerNum][4]) {
        D_800D1BF8[playerNum][4] = D_800D1BF8[playerNum][5];
        D_800D1BF8[playerNum][5] = D_800D1BF8[playerNum][6];
        D_800D1BF8[playerNum][6] = D_800D1BF8[playerNum][7];
        D_800D1BF8[playerNum][7] = 0;
    } else if (arg1 == D_800D1BF8[playerNum][5]) {
        D_800D1BF8[playerNum][5] = D_800D1BF8[playerNum][6];
        D_800D1BF8[playerNum][6] = D_800D1BF8[playerNum][7];
        D_800D1BF8[playerNum][7] = 0;
    } else if (arg1 == D_800D1BF8[playerNum][6]) {
        D_800D1BF8[playerNum][6] = D_800D1BF8[playerNum][7];
        D_800D1BF8[playerNum][7] = 0;
    } else if (arg1 == D_800D1BF8[playerNum][7]) {
        D_800D1BF8[playerNum][7] = 0;
    }
}

void func_800BA67C(u8 racerId, u8 arg1) {

    if (arg1 != D_800D1B70[racerId][0] && arg1 != D_800D1B70[racerId][1] && arg1 != D_800D1B70[racerId][2] &&
        arg1 != D_800D1B70[racerId][3]) {
        if (D_800D1B70[racerId][0] != 0) {
            if (D_800D1B70[racerId][1] != 0) {
                if (D_800D1B70[racerId][2] != 0) {
                    if (D_800D1B70[racerId][3] == 0) {
                        D_800D1B70[racerId][3] = arg1;
                    }
                } else {
                    D_800D1B70[racerId][2] = arg1;
                }
            } else {
                D_800D1B70[racerId][1] = arg1;
            }
        } else {
            D_800D1B70[racerId][0] = arg1;
        }
    }
}

void func_800BA710(u8 arg0, u8 arg1) {

    if (arg1 == 0x1E) {
        goto block_5;
    }
    if (arg1 == 0x21) {
        goto block_5;
    }
    if (D_800D19E0 == 1) {
        return;
    }
block_5:

    if ((arg0 == 0) || (arg0 == 1) || (arg0 == 2) || (arg0 == 3)) {
        D_800D1AF8[arg0] = 0.83f;
    } else if (D_800D1A0C == 1) {
        return;
    }
    func_800BA67C(arg0, arg1);
}

void func_800BA7C0(u8 ioData) {
    AUDIOCMD_CHANNEL_SET_PAN(0, 1, 0x3F);
    func_800BAE98(1, ioData);
}

void func_800BA7F8(u8 arg0, u16 arg1) {

    if ((arg0 != D_800D19E8) && (arg0 != D_800D19EC) && (arg0 != D_800D19F0) && (arg0 != D_800D19F4)) {
        if (D_800D19F8 != 0) {
            if (D_800D19FC != 0) {
                if (D_800D1A00 != 0) {
                    if (D_800D1A04 == 0) {
                        D_800D19F4 = arg0;
                        D_800D1A04 = arg1;
                    }
                } else {
                    D_800D19F0 = arg0;
                    D_800D1A00 = arg1;
                }
            } else {
                D_800D19EC = arg0;
                D_800D19FC = arg1;
            }
        } else {
            D_800D19E8 = arg0;
            D_800D19F8 = arg1;
        }
    }
}

void func_800BA8D8(u8 arg0) {

    if (arg0 == 0x11) {
        func_800BA7F8(arg0, 0x83);
    } else if (arg0 == 0x12) {
        func_800BA7F8(arg0, 0xB3);
    } else if (arg0 == 0x2A) {
        func_800BA7F8(arg0, 0xBE);
    } else if (arg0 == 0x2C) {
        func_800BA7F8(arg0, 0xC6);
    } else if (arg0 == 0x30) {
        func_800BA7F8(arg0, 0x9A);
    } else if (arg0 == 0x33) {
        func_800BA7F8(arg0, 0x9B);
    } else if (arg0 == 0x34) {
        func_800BA7F8(arg0, 0xE9);
    } else if (arg0 == 0x35) {
        func_800BA7F8(arg0, 0xCD);
    } else if (arg0 == 0x38) {
        func_800BA7F8(arg0, 0x71);
    } else if (arg0 == 0x3A) {
        func_800BA7F8(arg0, 0x68);
    } else if (arg0 == 0x3B) {
        func_800BA7F8(arg0, 0xB5);
    } else if (arg0 == 0x3C) {
        func_800BA7F8(arg0, 0x99);
    } else if (arg0 == 0x3D) {
        func_800BA7F8(arg0, 0x83);
    } else if (arg0 == 0x43) {
        func_800BA7F8(arg0, 0x9B);
    } else {
        func_800BA7C0(arg0);
    }
}

void func_800BAA88(u8 arg0, u8 arg1) {
    f32 volumeScale;

    AUDIOCMD_CHANNEL_SET_PAN(0, 15, func_800B71D0(arg0));

    if (arg1 >= 0x80) {
        arg1 = 0x7F;
    }
    if (arg1 < 0) {
        arg1 = 0;
    }

    volumeScale = arg1 / 127.0f;
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 15, volumeScale);
    func_800BAE98(15, 0x2D);
}

void func_800BAB34(u8 arg0) {
    D_800D1A90[arg0] = 1;
}

void func_800BAB50(u8 arg0) {
    D_800D1A90[arg0] = 0;
}

void func_800BAB68(u8 arg0) {
    func_800BAEDC(arg0 + 2);
    D_800D1A74[arg0] = 0;
}

void func_800BABA0(u8 arg0) {

    switch (D_800D1A18) {
        case 0:
            AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0x3F);
            if (D_800D1A94[arg0] == 0) {
                func_800BAE98(arg0 + 2, 2U);
            } else {
                func_800BAE98(arg0 + 2, 7U);
            }
            break;
        case 1:
            switch (arg0) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 3, 0x7F);
                    break;
            }
            if (D_800D1A94[arg0] == 0) {
                func_800BAE98(arg0 + 2, 0xCU);
            } else {
                func_800BAE98(arg0 + 2, 0x11U);
            }
            break;
        case 2:
            switch (arg0) {
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
            if (D_800D1A94[arg0] == 0) {
                func_800BAE98(arg0 + 2, 0x16U);
            } else {
                func_800BAE98(arg0 + 2, 0x1BU);
            }
            break;
        case 3:
            switch (arg0) {
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
            if (D_800D1A94[arg0] == 0) {
                func_800BAE98(arg0 + 2, 0x16U);
            } else {
                func_800BAE98(arg0 + 2, 0x1BU);
            }
    }
}

void func_800BAE5C(u8 arg0) {
    D_800D1A74[arg0] = 1;
    func_800BABA0(arg0);
}

void func_800BAE90(u8 arg0) {
}

void func_800BAE98(u8 channelIndex, u8 ioData) {
    AUDIOCMD_CHANNEL_SET_IO(0, channelIndex, 0, ioData);
}

void func_800BAEDC(u8 channelIndex) {
    AUDIOCMD_CHANNEL_SET_IO(0, channelIndex, 5, 1);
}

void func_800BAF18(u8 arg0) {
}

void func_800BAF20(u8 arg0) {
}

void func_800BAF28(void) {
}

void func_800BAF30(u8 ioData) {
    D_800D1A48 = 0;
    D_800D1A4C = 0;
    D_800D1A60 = ioData;
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 1.0f);
    func_800BAE98(0, ioData);
}

void func_800BAF80(void) {
    if (D_800D1A48 == 0) {
        D_800D1A48 = 1;
    }
}

void func_800BAFA4(u8 ioData) {
    D_800D1A48 = 0;
    D_800D1A4C = 0;
    D_800D1A60 = ioData;
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 1.0f);
    func_800BAE98(0, ioData);
}

void func_800BAFF4(void) {
    if (D_800D1A48 == 0) {
        D_800D1A48 = 1;
    }
}

void func_800BB018(void) {
    func_800BAFA4(0x17);
}

void func_800BB038(void) {
    D_800D19E0 = 1;
}

void func_800BB048(void) {
    func_800BB45C();
    D_800D1A58 = 1;
    D_800D1A08 = 1;
}

void func_800BB078(void) {
    if (D_800D1A48 == 0) {
        D_800D1A48 = 2;
    }
}

void func_800BB09C(void) {
    if (D_800D1A48 == 0) {
        D_800D1A48 = 3;
    }
}

void func_800BB0C0(u8 arg0) {

    switch (arg0) {
        case 0:
            D_800D1A40 = 0;
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 1.0f);
            break;
        case 1:
            D_800D1A40 = 1;
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
            func_800BAEDC(0);
            func_800BAEDC(2);
            func_800BAEDC(3);
            func_800BAEDC(4);
            func_800BAEDC(5);
            func_800BAEDC(6);
            func_800BAEDC(7);
            func_800BAEDC(8);
            func_800BAEDC(9);
            func_800BAEDC(14);
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
            D_800D1A40 = 2;
            break;
    }
}

extern u8 D_800D1A5C;

void func_800BB2E0(s32 specId) {
    if (specId != D_800D1A5C) {
        D_800D1A5C = specId;
        func_800B6EC0(specId);

        do { } while (!func_800B6E14()); }
}

void func_800BB324(u8 numPlayersIndex) {
    D_800D1A18 = numPlayersIndex;
}

void func_800BB334(void) {
    func_800B9ED4();
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(0, 0);
    func_800BB2E0(0);
    func_800B6994();
}

void func_800BB370(void) {
    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(0, 0, 0, 0);
    func_800B6994();
}

void func_800BB39C(s32 arg0) {
    func_800B9ED4();
    func_800B6994();
}

void func_800BB3C4(u8 racerId, f32 arg1) {

    if (arg1 < -48.0f) {
        arg1 = -48.0f;
    }
    if (arg1 > -2.5f) {
        return;
    }

    D_800D1AF8[racerId] = 0.2f - (arg1 / 58.0f);

    if (D_800D1AF8[racerId] > 0.75f) {
        D_800D1AF8[racerId] = 0.75f;
    }
    func_800BA67C(racerId, 0x36);
}

void func_800BB45C(void) {
    D_800D1A0C = 1;
}

void func_800BB46C(void) {
    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, 1, 0, 0);
    func_800BB370();
}

extern AudioTask* D_800D1C18;

AudioTask* func_800BB49C(void) {
    AudioTask* curAudioTask;

    func_800B82C8();
    func_800B7CA4();
    func_800B8598();
    func_800B6994();
    D_800D1C18 = curAudioTask = func_800B5FB0();
    return curAudioTask;
}

// Todo: Migrate these to their appropriate places in the above functions

static const char devrostring00[] = "LEVEL SE INTERNAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring01[] = "LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring02[] = "LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring03[] = "LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring04[] = "LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring05[] = "LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring06[] = "LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring07[] = "LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring08[] = "LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring09[] = "LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring10[] = "LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring11[] = "Ouch!! UN-SUPORTED TRG SE NUM WAS CALLED !!!!!!! num = %02x\n";
static const char devrostring12[] = "LEVEL SE FADEOUT COMPLETE ROUTINE\n";
static const char devrostring13[] = "BGM FADEOUT1 COMPLETE ROUTINE\n";
static const char devrostring14[] = "BGM FADEOUT2 COMPLETE ROUTINE\n";
static const char devrostring15[] = "BGM FADEOUT3 COMPLETE ROUTINE\n";
static const char devrostring16[] = "BGM FADEOUT COMPLETE ROUTINE (in the PAUSE ROUTINE)\n";
static const char devrostring17[] = "ENEMY ENGINE START MACHINE No.= %02x\n";
static const char devrostring18[] = "ENEMY ENGINE STOP!\n";
static const char devrostring19[] = "len = %d\n";
static const char devrostring20[] = "Player Level SE Start !! player =  %02x SE number = %02x\n";
static const char devrostring21[] = "PLAYER LEVEL SE STACK OVER!!\n";
static const char devrostring22[] = "Na_PlyLevelSE_Stop Called player = %02x num = %02x \n";
static const char devrostring23[] = "NON ENTRIED LEVEL SE STOPED! SE NUMBER = %02x\n";
static const char devrostring24[] = "VOICE SE STACK OVER!!\n";
static const char devrostring25[] = "System SE = %02x\n";
static const char devrostring26[] = "hanabi se called. pan = %02x volume = %02x \n";
static const char devrostring27[] = "ENGINE SOUND ECHO START MACHINE NO = %02x\n";
static const char devrostring28[] = "ENGINE SOUND ECHO STOPED! MACHINE No.= %02x\n";
static const char devrostring29[] = "ENGINE SOUND STOPED! MACHINE No.= %02x\n";
static const char devrostring30[] = "ENGINE SOUND START! MACHINE No.= %02x\n";
static const char devrostring31[] = "WINING RUN ENGINE SOUND START! MACHINE No.= %02x\n";
static const char devrostring32[] = "64DD STREEM BGM Ready %02x\n";
static const char devrostring33[] = "64DD STREEM BGM Start%02x\n";
static const char devrostring34[] = "Na_DDBgm_Stop Called\n";
static const char devrostring35[] = "Na_BetaBgm_Start num = %02x\n";
static const char devrostring36[] = "Na_BetaBgm_Stop Called\n";
static const char devrostring37[] = "Na_ROMBgm_Start Called num = %02x\n";
static const char devrostring38[] = "Na_ROMBgm_Stop Called\n";
static const char devrostring39[] = "RETIRE FUNCTION CALLED!!\n";
static const char devrostring40[] = "Level SE Fadeout !!\n";
static const char devrostring41[] = "Na_BetaBgm_Stop2 Called\n";
static const char devrostring42[] = "Na_BetaBgm_Stop3 Called\n";
static const char devrostring43[] = "Pause Called!! Status =  %02x\n";
static const char devrostring44[] = "Spec Change No = %02x\n";
static const char devrostring45[] = "Player Mode = %02x\n";
static const char devrostring46[] = "All Sound Off\n";
static const char devrostring47[] = "Na_SeSeq_Start for ROM Called\n";
static const char devrostring48[] = "Change Sound Mode No = %02x\n";
static const char devrostring49[] = "Na_chakuchi Called player = %02x volume = %f \n";
static const char devrostring50[] = "Na_chakuchi Edited volume = %f \n";
static const char devrostring51[] = "Na_Guitor_Start Called\n";
static const char devrostring52[] = "Na_Guitor_Start for ROM Called\n";
