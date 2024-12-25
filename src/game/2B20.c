#include "global.h"
#include "audio.h"
#include "fzx_game.h"

// This needs to be used in a function earlier than this can be declared
extern s16 D_800CD16C;

s32 gNumPlayers = 1;
s32 gCupType = JACK_CUP;
s32 gDifficulty = NOVICE;
s32 gTotalLapCount = 3;
s8 D_800CD010 = 0;
s8 D_800CD014 = 0;
s8 D_800CD018 = 0;
UNUSED s32 D_800CD01C = 0;
u16 D_800CD020 = 0;
s32 D_800CD024[] = { GAMEMODE_GP_RACE, GAMEMODE_VS_2P, GAMEMODE_VS_4P };
s32 D_800CD030[] = { 1, 2, 4 };
s8 D_800CD03C[] = { 3, 1, 2, 4, 16 };
s16 D_800CD044 = 0;
s16 D_800CD048 = 0;

void (*D_800CD04C[])(void) = {
    func_i4_8011AD60,
    func_i2_80103AD4,
    func_i2_80103AD4,
    func_i2_80103AD4,
    func_i2_80103AD4,
    func_i2_80103AD4,
    func_i8_801439D0,
    func_i4_80115DF0,
    func_i6_80115DF0,
    func_i4_801160D8,
    func_i5_80116934,
    func_i6_8011BF50,
    func_i6_8011BF50,
    NULL,
    func_i2_80103AD4,
    func_i5_80116D00,
    NULL,
    func_i7_80143A90,
    func_i4_801160D8,
    func_i5_80116934,
    func_i6_8011C050,
    func_i2_80103AD4,
};

s32 (*D_800CD0A4[])(void) = {
    func_i4_8011AE2C,
    func_i2_80103B8C,
    func_i2_80103B8C,
    func_i2_80103B8C,
    func_i2_80103B8C,
    func_i2_80103B8C,
    func_i8_80143DDC,
    func_i6_80115FF0,
    func_i4_8011631C,
    func_i4_801168D4,
    func_i5_80116EEC,
    func_i6_8011BFB0,
    func_i6_8011BFB0,
    NULL,
    func_i2_80103B8C,
    func_i5_801175D0,
    NULL,
    func_i7_801441A0,
    func_i4_801168D4,
    func_i5_80116EEC,
    func_i6_8011C6DC,
    func_i2_80103B8C,
};

Gfx* (*D_800CD0FC[])(Gfx*) = {
    func_i4_8011AF84,
    func_i2_80103BE0,
    func_i2_80103BE0,
    func_i2_80103BE0,
    func_i2_80103BE0,
    func_i2_80103BE0,
    func_i8_80144568,
    func_i6_801167CC,
    func_i4_80116DC4,
    func_i4_80116E10,
    func_i5_80117664,
    func_i6_8011C01C,
    func_i6_8011C01C,
    NULL,
    func_i2_80103BE0,
    func_i5_80117664,
    NULL,
    func_i7_801447F4,
    func_i4_80116E10,
    func_i5_80117664,
    Menu_OptionsDraw,
    func_i2_80103BE0,
};

void func_80076848(void);
void func_8007D9D0(void);
void func_8007F500(void);
void func_80085510(void);
void func_8008DA68(void);
void func_8008DB98(void);
void func_800A4B54(void);
void func_800A4BAC(void);
void func_i2_800FC730(void);

extern s32 gGameMode;
extern unk_800DCE48 D_800DCE48;
extern s32 D_800DCE60;

void func_80068B20(void) {
    gGameMode = -1;
    D_800DCE48.gameMode = GAMEMODE_8000;
    if (D_800DCE60 != 0x20DE1529) {
        D_800DCE60 = 0x20DE1529;
        func_8008DB98();
        func_800A4BAC();
    } else {
        func_8008DA68();
        func_800A4B54();
    }
    func_80085510();
    func_i2_800FC730();
    func_8007F500();
    func_80076848();
    func_8007D9D0();
    D_800CD16C = 1;
}

extern f32 D_800E5EF0;
extern s32 gTrackIndex;

void func_80068BC0(void) {
    if (D_800CD044 == 0) {
        switch (D_800CD048) {
            case 1:
                D_800CD044 = 5;
                break;
            case 2:
                D_800CD044 = 1;
                D_800DCE48.gameMode = GAMEMODE_8007;
                break;
            case 3:
                D_800CD044 = 1;
                D_800DCE48.gameMode = GAMEMODE_800A;
                break;
            case 7:
                D_800CD044 = 1;
                D_800DCE48.gameMode = GAMEMODE_8008;
                break;
            case 4:
                D_800CD044 = 1;
                if (gTrackIndex % 6 == 5) {
                    D_800DCE48.gameMode = GAMEMODE_11;
                } else {
                    D_800DCE48.gameMode = GAMEMODE_800F;
                    gTrackIndex++;
                }
                D_800E5EF0 = 0.5f;
                break;
            case 5:
                D_800CD044 = 1;
                D_800DCE48.gameMode = GAMEMODE_800F;
                break;
            case 6:
                D_800CD044 = 0xB;
                D_800DCE48.gameMode = GAMEMODE_800F;
                break;
            case 8:
                D_800CD044 = 0x15;
                D_800DCE48.gameMode = GAMEMODE_6;
                break;
            case 9:
                D_800CD044 = 0x15;
                D_800DCE48.gameMode = GAMEMODE_8013;
                break;
            case 10:
            case 14:
                D_800CD044 = 0x15;
                D_800DCE48.gameMode = GAMEMODE_8007;
                break;
            case 11:
                D_800CD044 = 0x1F;
                D_800DCE48.gameMode = GAMEMODE_800A;
                break;
            case 12:
                D_800CD044 = 0x1F;
                D_800DCE48.gameMode = GAMEMODE_8007;
                break;
            case 13:
                D_800CD044 = 0x15;
                D_800DCE48.gameMode = GAMEMODE_8014;
                break;
            case 15:
                D_800CD044 = 0xB;
                if (gGameMode == GAMEMODE_GP_RACE) {
                    D_800DCE48.gameMode = GAMEMODE_4012;
                } else {
                    D_800DCE48.gameMode = GAMEMODE_4009;
                }
                break;
            case 16:
                D_800CD044 = 0xB;
                D_800DCE48.gameMode = gGameMode;
                break;
        }
    }
}

void func_80068DCC(void) {
    static u16 D_800CD154 = 0;
    s32 var_v1 = D_800CD154;

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            if (D_800CD010 == 0) {
                D_800CD154 = 0;
            }
            return;
        case GAMEMODE_8000:
            var_v1 = 0xD;
            break;
        case GAMEMODE_11:
            var_v1 = 0x15;
            break;
        case GAMEMODE_800B:
        case GAMEMODE_800C:
            var_v1 = 0x16;
            break;
        case GAMEMODE_8013:
        case GAMEMODE_8014:
            var_v1 = 0xF;
            break;
        case GAMEMODE_4009:
        case GAMEMODE_4012:
        case GAMEMODE_8007:
        case GAMEMODE_8008:
        case GAMEMODE_800A:
        case GAMEMODE_800F:
            var_v1 = 0xE;
            break;
        case 0xD:
        case 0x10:
            D_800CD154 = 0;
            return;
        default:
            break;
    }
    if (D_800CD154 != var_v1) {
        func_8007E0CC();
        func_8007E08C();
        func_800BAFA4(var_v1);
    }
    D_800CD154 = var_v1;
}

UNUSED s32 D_800CD158[2] = { 0 }; // New File?
s32 D_800CD160 = 15;
s32 D_800CD164 = 5;
s16 D_800CD168 = 0;
s16 D_800CD16C = 0;

extern Controller D_800DCE98[];
extern Controller D_800DD180;

extern s32 D_800DD228;
extern u16 D_800E416E;

void func_80068F04(void) {

    if (gGameMode != D_800DCE48.gameMode) {
        D_800CD010 = 0;
        D_800CD020 = 0;
        return;
    }
    func_8007DABC(&D_800DD180);
    switch (gGameMode) {
        case GAMEMODE_8000:
            if (D_800DD228 != 0) {
                D_800CD020++;
            }
            if ((D_800CD010 != 0) && (D_800DD228 != 0)) {

                D_800DCE48.gameMode = D_800CD024[D_800CD014];
                gNumPlayers = D_800CD030[D_800CD014];
                gTrackIndex = D_800CD03C[D_800CD018];
                D_800CD014++;
                D_800CD018++;
                if (D_800CD014 >= 3) {
                    D_800CD014 = 0;
                }
                if (D_800CD018 >= 5) {
                    D_800CD018 = 0;
                }
                D_800CD020 = 0;
                D_800CD010 = 1;
                gDifficulty = MASTER;
            }
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            if (D_800CD010 != 0) {
                D_800CD020++;
                switch (D_800CD010) {
                    case 1:
                        if (!(D_800E416E & (BTN_A | BTN_START))) {
                            break;
                        }
                        /* fallthrough */
                    case 3:
                        D_800DCE48.gameMode = GAMEMODE_8000;
                        D_800CD020 = 0;
                        D_800CD010 = 2;
                        break;
                    case 2:
                        break;
                }
            }
            break;
    }
}

extern OSMesgQueue D_800DCA80;
extern s8 D_800DCE5C;

void func_800690FC(void) {
    s32 sp24;

    if (gGameMode != D_800DCE48.gameMode) {
        if (D_800CD044 == 0) {
            if (gGameMode == -1) {
                D_800CD044 = 3;
            } else {
                D_800CD044 = 1;
            }
        }
    } else {
        func_80068BC0();
    }

    D_800CD048 = 0;
    switch (D_800CD044) {
        case 1:
        case 11:
        case 21:
        case 31:
            func_i2_800FC77C();
            if (D_800CD168 != 0) {
                func_80069820();
                D_800CD168 = 0;
            }
            D_800CD0A4[GET_MODE(gGameMode)]();
            func_i2_800FCE3C();
            if (D_800CD16C != 0) {
                osContStartReadData(&D_800DCA80);
                D_800CD168 = 1;
            }
            D_800CD044++;
            return;
        case 2:
        case 12:
        case 22:
        case 32:
            if (D_800CD168 != 0) {
                func_80069820();
                D_800CD168 = 0;
            }
            D_800CD0A4[GET_MODE(gGameMode)]();
            if (func_i2_800FCE3C() != 0) {
                if (gGameMode == GAMEMODE_GP_RACE) {
                    func_i3_ResetLivesChangeCounter();
                }
                D_800CD044++;
            }
            if (D_800CD16C != 0) {
                osContStartReadData(&D_800DCA80);
                D_800CD168 = 1;
                return;
            }
            return;
        case 3:
        case 13:
        case 23:
        case 33:
            func_80069700();
            switch (gGameMode) {
                case GAMEMODE_4009:
                case GAMEMODE_4012:
                    if ((gNumPlayers == 1) && (gTrackIndex < 0x18)) {
                        func_i2_801012CC(gTrackIndex);
                    }
                    break;
                case GAMEMODE_8008:
                    func_i4_8011A7B8();
                    break;
            }
            gGameMode = D_800DCE48.gameMode;
            if (D_800CD010 == 2) {
                D_800CD010 = 0;
            }
            D_800DCE5C = 0;
            func_800766F0();

            switch (gGameMode) {
                case GAMEMODE_GP_RACE:
                case GAMEMODE_PRACTICE:
                case GAMEMODE_VS_2P:
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                case GAMEMODE_D:
                case GAMEMODE_TIME_ATTACK:
                case GAMEMODE_10:
                case GAMEMODE_DEATH_RACE:
                    if (D_800CD010 == 0) {
                        func_8007E08C();
                    }
                    break;
            }
            sp24 = 0;
            switch (gGameMode) {
                case GAMEMODE_GP_RACE:
                case GAMEMODE_PRACTICE:
                case GAMEMODE_VS_2P:
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                case GAMEMODE_D:
                case GAMEMODE_DEATH_RACE:
                case GAMEMODE_4009:
                case GAMEMODE_4012:
                case GAMEMODE_8008:
                    sp24 = 1;
                    break;
                case GAMEMODE_TIME_ATTACK:
                    sp24 = 2;
                    break;
                case GAMEMODE_6:
                    sp24 = 3;
                    break;
            }
            if (sp24 != 0) {
                // clang-format off
                osInvalICache(SEGMENT_VRAM_START(ovl_i9), SEGMENT_DATA_START(ovl_i9) - SEGMENT_VRAM_START(ovl_i9));\
                osInvalDCache(SEGMENT_DATA_START(ovl_i9), SEGMENT_BSS_START(ovl_i9) - SEGMENT_DATA_START(ovl_i9));
                // clang-format on
                func_80076658(SEGMENT_ROM_START(ovl_i9), SEGMENT_VRAM_START(ovl_i9), SEGMENT_ROM_SIZE(ovl_i9),
                              SEGMENT_BSS_START(ovl_i9), SEGMENT_BSS_SIZE(ovl_i9));
                switch (sp24) {
                    case 1:
                        func_8008D7E8();
                        break;
                    case 2:
                        func_i2_80100520(gTrackIndex);
                        func_8008D8E8();
                        break;
                    case 3:
                        func_8008D824();
                        break;
                }
            }
            func_80077318();
            func_80079EC8();
            D_800CD04C[GET_MODE(gGameMode)]();
            func_80068DCC();
            func_80077C9C();
            func_i2_800FC9BC();
            D_800CD044 = 0;
            break;
        case 5:
            func_i2_800FC77C();
            func_i2_800FCE3C();
            D_800CD044 = 6;
            break;
        case 6:
            if (func_i2_800FCE3C() != 0) {
                func_i2_800FC9BC();
                if (gGameMode != GAMEMODE_6) {
                    func_8007E08C();
                }
                func_80068DCC();
                func_80079F1C();
                func_i2_80103A70();
                D_800CD044 = 0;
            }
            break;
        case 0:
        default:
            break;
    }

    if (D_800CD168 != 0) {
        func_80069820();
        D_800CD168 = 0;
    }
    D_800DCE48.gameMode = D_800CD0A4[GET_MODE(gGameMode)]();
    func_80068F04();
    switch (D_800CD044) {
        case 6:
            break;
        case 0:
            func_i2_800FCE3C();
            break;
    }
    if (D_800CD16C != 0) {
        osContStartReadData(&D_800DCA80);
        D_800CD168 = 1;
    }
}

extern s16 D_i2_80106DA0;

Gfx* func_80069698(Gfx* gfx) {

    if ((D_800CD044 != 3) && (D_i2_80106DA0 != 0)) {
        gfx = D_800CD0FC[GET_MODE(gGameMode)](gfx);
    }
    return func_i2_800FD184(gfx);
}

void func_80069700(void) {
    s32 i;

    if (D_800CD168 != 0) {
        func_80069820();
        D_800CD168 = 0;
    }

    for (i = 0; i < 4; i++) {
        if (osMotorStop(&D_800DCE98[i].pfs) == 0) {
            D_800DCE98[i].unk_74 = 1;
        } else {
            D_800DCE98[i].unk_74 = 0;
        }
        D_800DCE98[i].unk_72 = D_800DCE98[i].unk_76 = 0;
    }
}

void func_80069790(void) {
    Controller* var_v0;

    // clang-format off
    var_v0 = &D_800DCE98[4];\
    do {
        if (var_v0->unk_6B == 0) {
            var_v0->unk_82 = var_v0->unk_7A = var_v0->unk_7C = var_v0->unk_7E = var_v0->unk_80 = 0;
            var_v0->stickX = var_v0->stickY = var_v0->unk_6E = var_v0->unk_6F = var_v0->unk_70 = var_v0->unk_71 = 0;
            var_v0->unk_84 = 0;
        }
        var_v0--;
    } while (var_v0 >= D_800DCE98);
    // clang-format on

    D_800DD180.unk_82 = D_800DD180.unk_7A = D_800DD180.unk_7C = D_800DD180.unk_7E = 0;
    D_800DD180.stickX = D_800DD180.stickY = D_800DD180.unk_6E = D_800DD180.unk_6F = D_800DD180.unk_70 = 0;
}

extern s32 D_800CCFB0;
extern OSContPad D_800DCE80[];
extern s32 D_800DCCC8;
extern Controller D_800DD0E8;
extern s32 D_800DD218[];
extern OSMesg D_800E12B0;

void func_80069820(void) {
    s32 i;
    s32 j;
    u16 temp_a2;
    s32 var_fp;
    s32 var_s2;
    s32 var_s6;
    s32 var_s7;
    Controller* var_s0;
    OSContPad* var_s5;
    s32* var_v0;

    D_800DD180.unk_82 = D_800DD180.unk_7A = D_800DD180.unk_7C = D_800DD180.unk_7E = 0;
    var_s6 = 0;
    var_s7 = 0;
    var_fp = 0;
    D_800DD180.unk_6E = D_800DD180.unk_6F = D_800DD180.unk_70 = 0;

    var_s0 = &D_800DCE98[4];
    i = 4;
    var_s5 = &D_800DCE80[4];

    osRecvMesg(&D_800DCA80, &D_800E12B0, OS_MESG_BLOCK);
    osContGetReadData(D_800DCE80);
    do {
        var_s0--;
        var_s5--;
        i--;

        if (var_s0->unk_6B == 0) {
            if ((var_s0->unk_6B = var_s5->errno) != 0) {
                D_800DD228--;

                for (j = 3; j >= 0; j--) {
                    if (i == D_800DD218[j]) {
                        D_800DD218[j] = 4;
                        break;
                    }
                }
            } else {
                var_s6++;
                var_s0->unk_80 = var_s0->unk_7A;
                D_800DD180.unk_7A |= var_s0->unk_7A = var_s5->button & (u16) ~0xC0;

                temp_a2 = (var_s0->unk_80 ^ var_s0->unk_7A);

                D_800DD180.unk_7C |= var_s0->unk_7C = temp_a2 & var_s0->unk_7A;
                D_800DD180.unk_7E |= var_s0->unk_7E = temp_a2 & var_s0->unk_80;

                var_fp += var_s0->stickX = var_s5->stick_x;
                var_s7 += var_s0->stickY = var_s5->stick_y;

                var_s0->unk_71 = var_s0->unk_6E;

                if (var_s0->stickX < -50) {
                    var_s0->unk_6E = 0x20;
                } else if (var_s0->stickX > 50) {
                    var_s0->unk_6E = 0x10;
                } else {
                    var_s0->unk_6E = 0;
                }

                if (var_s0->stickY < -50) {
                    var_s0->unk_6E |= 0x40;
                } else if (var_s0->stickY > 50) {
                    var_s0->unk_6E |= 0x80;
                }

                D_800DD180.unk_6E |= var_s0->unk_6E;

                temp_a2 = (var_s0->unk_71 ^ var_s0->unk_6E);

                D_800DD180.unk_6F |= var_s0->unk_6F = temp_a2 & var_s0->unk_6E;
                D_800DD180.unk_70 |= var_s0->unk_70 = temp_a2 & var_s0->unk_71;

                var_s0->unk_82 = 0;
                if (((var_s0->unk_7A != 0) || (var_s0->unk_6E != 0)) && (var_s0->unk_80 == var_s0->unk_7A) &&
                    (var_s0->unk_71 == var_s0->unk_6E)) {
                    var_s0->unk_84++;
                    if ((var_s0->unk_84 >= D_800CD160) && (((var_s0->unk_84 - D_800CD160) % D_800CD164) == 0)) {
                        var_s0->unk_82 = 1;
                    }
                } else {
                    var_s0->unk_84 = 0;
                }
                D_800DD180.unk_82 |= var_s0->unk_82;
                if (var_s0->unk_78 != 0) {
                    if (osMotorInit(&D_800DCA80, &var_s0->pfs, i) == 0) {
                        osMotorStop(&var_s0->pfs);
                        var_s0->unk_74 = 1;
                    } else {
                        var_s0->unk_74 = 0;
                    }
                    var_s0->unk_76 = 0;
                    var_s0->unk_90 = 0;
                    var_s0->unk_8C = 0;
                    var_s0->unk_88 = 0;
                    var_s0->unk_78 = var_s0->unk_76;
                } else if ((var_s0->unk_72 == 0) || (D_800DCCC8 != 0)) {
                    if ((var_s0->unk_74 == 1) && ((var_s0->unk_76 == 1) || !(((i << 5) + D_800CCFB0) & 0x7F))) {
                        if (osMotorStop(&var_s0->pfs) == 0) {
                            var_s0->unk_76 = 0;
                        } else {
                            var_s0->unk_74 = 0;
                        }
                    }
                } else if (var_s0->unk_74 == 1) {
                    var_s0->unk_88 += var_s0->unk_8C;
                    var_s0->unk_8C -= var_s0->unk_90;
                    if (var_s0->unk_8C < 0) {
                        var_s0->unk_8C = 0;
                    }

                    if (var_s0->unk_88 >= 1000) {
                        var_s0->unk_88 -= 1000;
                        if (var_s0->unk_76 == 0) {
                            if (osMotorStart(&var_s0->pfs) == 0) {
                                var_s0->unk_76 = 1;
                            } else {
                                var_s0->unk_74 = 0;
                            }
                        }
                    } else if (var_s0->unk_76 == 1) {
                        if (osMotorStop(&var_s0->pfs) == 0) {
                            var_s0->unk_76 = 0;
                        } else {
                            var_s0->unk_74 = 0;
                        }
                    }
                }
            }
        }
    } while (var_s0 != D_800DCE98);

    if (var_s6 != 0) {
        D_800DD180.stickX = var_fp / var_s6;

        D_800DD180.stickY = var_s7 / var_s6;
    }
}

extern OSContStatus D_800DCE70[];

void func_80069D44(void) {
    s32 i;
    u8 sp53;

    osContInit(&D_800DCA80, &sp53, D_800DCE70);
    D_800DD228 = 0;

    for (i = 0; i < MAXCONTROLLERS; i++) {

        D_800DCE98[i].unk_6B = D_800DCE70[i].errno;
        D_800DCE98[i].unk_72 = D_800DCE98[i].unk_74 = D_800DCE98[i].unk_76 = D_800DCE98[i].unk_78 = 0;
        D_800DCE98[i].unk_88 = D_800DCE98[i].unk_8C = D_800DCE98[i].unk_90 = 0;
        if (D_800DCE70[i].errno == 0) {
            D_800DD218[D_800DD228] = i;
            D_800DD228++;
            if (osMotorInit(&D_800DCA80, &D_800DCE98[i].pfs, i) == 0) {
                osMotorStop(&D_800DCE98[i].pfs);
                D_800DCE98[i].unk_74 = 1;
            }
        }
    }

    for (i = D_800DD228; i < 4; i++) {
        D_800DD218[i] = 4;
    }

    func_80069790();
}
