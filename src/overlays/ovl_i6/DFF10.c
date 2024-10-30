#include "global.h"
#include "ovl_i6.h"
#include "tex_assets.h"

s16 D_i6_8011F910[240];

// UNUSED?
UNUSED unk_8011DC40 D_i6_8011DC40 = { 1.0f, 1.0f, 32, 12, 0, 2, 17, 20 };

s32 D_i6_8011DC60 = 0;
s32 D_i6_8011DC64 = 0;
s32 D_i6_8011DC68 = 0;
s32 D_i6_8011DC6C = 180;

/*
    MENU OPTIONS
 */

// GP RACE
unk_80077D50 D_i6_8011DC70[] = { { 17, D_F129C54, 64, 86, 0xF57 }, { 0 } };

// TIME ATTACK
unk_80077D50 D_i6_8011DC90[] = { { 17, D_F12ABB0, 64, 86, 0x1049 }, { 0 } };

// VS BATTLE
unk_80077D50 D_i6_8011DCB0[] = { { 17, D_F12BC00, 64, 86, 0xF98 }, { 0 } };

// PRACTICE
unk_80077D50 D_i6_8011DCD0[] = { { 17, D_F12CB9C, 64, 86, 0xF76 }, { 0 } };

// DEATH RACE
unk_80077D50 D_i6_8011DCF0[] = { { 17, D_F12DB18, 64, 86, 0xE83 }, { 0 } };

// OPTIONS
unk_80077D50 D_i6_8011DD10[] = { { 17, D_F12E9A0, 64, 86, 0xF8F }, { 0 } };

// COURSE EDIT
unk_80077D50 D_i6_8011DD30[] = { { 17, D_F12F934, 64, 86, 0x1016 }, { 0 } };

// CREATE MACHINE
unk_80077D50 D_i6_8011DD50[] = { { 17, D_F130950, 64, 86, 0x1012 }, { 0 } };

unk_80077D50* D_i6_8011DD70[] = {
    D_i6_8011DC70, D_i6_8011DC90, D_i6_8011DCF0, D_i6_8011DCB0,
    D_i6_8011DD30, D_i6_8011DCD0, D_i6_8011DD10, D_i6_8011DD50,
};

/*
    LARGE WALLPAPER-STYLE IMAGES/COMIC STYLE IMAGE
 */

// TITLE SCREEN BACKGROUND
unk_80077D50 D_i6_8011DD90[] = { { 17, D_F000004, 304, 240, 0x14A5D }, { 0 } };

// COMIC STRIP
unk_80077D50 D_i6_8011DDB0[] = { { 17, D_F014A68, 320, 240, 0x118DB }, { 0 } };

// BLUE FALCON, SEMI-TRANSPARENT
unk_80077D50 D_i6_8011DDD0[] = { { 17, D_F026348, 320, 240, 0x9E0A }, { 0 } };

unk_80077D50* D_i6_8011DDF0[] = {
    D_i6_8011DD90,
    D_i6_8011DDB0,
    D_i6_8011DDD0,
};

/*
    MENU SECOND OPTIONS
 */

// REMOVED?
unk_80077D50 D_i6_8011DDFC[] = { { 4, D_F134760, 128, 24, 0 }, { 0 } };

// FLAMES
unk_80077D50 D_i6_8011DE1C[] = { { 17, D_F131968, 128, 80, 0x2A0E }, { 0 } };

// NOVICE
unk_80077D50 D_i6_8011DE3C[] = { { 17, D_F134D64, 64, 18, 0x144 }, { 0 } };

// STANDARD
unk_80077D50 D_i6_8011DE5C[] = { { 17, D_F134EAC, 64, 18, 0x14C }, { 0 } };

// EXPERT
unk_80077D50 D_i6_8011DE7C[] = { { 17, D_F134FFC, 64, 18, 0x149 }, { 0 } };

// MASTER
unk_80077D50 D_i6_8011DE9C[] = { { 17, D_F13514C, 64, 18, 0x14E }, { 0 } };

// 2 PLAYERS
unk_80077D50 D_i6_8011DEBC[] = { { 17, D_F13437C, 64, 18, 0x146 }, { 0 } };

// 3 PLAYERS
unk_80077D50 D_i6_8011DEDC[] = { { 17, D_F1344C8, 64, 18, 0x142 }, { 0 } };

// 4 PLAYERS
unk_80077D50 D_i6_8011DEFC[] = { { 17, D_F134610, 64, 18, 0x143 }, { 0 } };

// TIME ATTACK
unk_80077D50 D_i6_8011DF1C[] = { { 18, D_F1352A0, 88, 18, 0x1B1 }, { 0 } };

// RECORDS
unk_80077D50 D_i6_8011DF3C[] = { { 17, D_F135458, 64, 18, 0x149 }, { 0 } };

unk_80077D50* D_i6_8011DF5C[] = {
    D_i6_8011DE3C,
    D_i6_8011DE5C,
    D_i6_8011DE7C,
    D_i6_8011DE9C,
};

unk_80077D50* D_i6_8011DF6C[] = {
    D_i6_8011DEBC,
    D_i6_8011DEDC,
    D_i6_8011DEFC,
};

unk_80077D50* D_i6_8011DF78[] = {
    D_i6_8011DF1C,
    D_i6_8011DF3C,
};

// 'OK?'
unk_80077D50 D_i6_8011DF80[] = { { 17, D_F139710, 32, 16, 0x112 }, { 0 } };

extern u32 gGameFrameCount;
extern s16 D_800CCFE8;
extern s32 gNumPlayers;
extern u32 D_800CD384;

void func_i6_80115DF0(void) {
    D_800CCFE8 = 3;
    D_800CD384 = 0;
    gNumPlayers = 1;
    if ((gGameFrameCount % 4) == 0) {
        func_800794B0(0x5E, 0, 0, 0);
    }
    func_800794B0(5, 0, 0, 1);
    if ((gGameFrameCount % 4) == 1) {
        func_800794B0(0x5E, 0, 0, 0);
    }
    func_800794B0(0x50, 0, 0, 4);
    if ((gGameFrameCount % 4) == 2) {
        func_800794B0(0x5E, 0, 0, 0);
    }
    func_800794B0(0x51, 0, 0, 10);
    if ((gGameFrameCount % 4) == 3) {
        func_800794B0(0x5E, 0, 0, 0);
    }
    func_800794B0(0x52, 0, 0, 0xA);
    func_800794B0(0x53, 0, 0, 0xA);
    func_800794B0(0x54, 0, 0, 0xA);
    func_800794B0(0x55, 0, 0, 0xA);
    func_800794B0(0x56, 0, 0, 0xA);
    func_800794B0(0x57, 0, 0, 0xA);
    func_800794B0(0x58, 0, 0, 0xA);
    func_800794B0(0x59, 0x64, 0xD, 0xA);
    func_800794B0(0x5A, 0x60, 0x50, 0xE);
    func_800794B0(0x5D, 0, 0, 0xE);
    func_800794B0(0x5C, 0x60, 0x50, 0xE);
    func_800794B0(0x5F, 0x60, 0x50, 0xE);
}

extern unk_800DCE48 D_800DCE48;
extern s32 D_800CD388[];
extern char* D_800E4180[];

extern s32 gNumPlayers;
extern s32 gDifficulty;
extern s16 D_800CD044;
extern s16 D_800CD048;
extern s32 D_800CD380;
extern s8 D_800CD3C0;
extern s8 D_800CD3C8;
extern s32 D_800DCE44;
extern Controller D_800DD180;
extern s32 D_800DD228;
extern u16 D_800E416C;
extern u16 D_800E416E;
extern char* D_800E4178;
extern s32 D_800F8514;
extern s32 D_80106DA4;

s32 func_i6_80115FF0(void) {
    s32 temp_t0;
    s32 var_v1_2;

    if (D_80106DA4 != 0) {
        return D_800DCE44;
    }

    func_8007DABC(&D_800DD180);
    if (func_80079E88(0x50)->unk_04 >= 3) {
        return D_800DCE44;
    }
    switch (D_800CD384) {
        case 0:
            temp_t0 = D_800CD380;
            if (D_800E416C & BTN_RIGHT) {
                if ((D_800CD380 % 4) != 3) {
                    D_800CD380++;
                }
            }
            if (D_800E416C & BTN_LEFT) {
                if (D_800CD380 % 4) {
                    D_800CD380--;
                }
            }
            if (D_800E416C & BTN_DOWN) {
                if ((D_800CD380 / 4) == 0) {
                    D_800CD380 += 4;
                }
            }
            if (D_800E416C & BTN_UP) {
                if ((D_800CD380 / 4) != 0) {
                    D_800CD380 -= 4;
                }
            }
            if ((D_800CD380 == 3) && (D_800DD228 < 2)) {
                D_800CD380 = 2;
            }
            switch (D_800CD380) {
                case 4:
                    D_800CD380 = 5;
                    break;
                case 7:
                    D_800CD380 = 6;
                    break;
            }
            if (temp_t0 != D_800CD380) {
                func_800BA8D8(0x1E);
            }
            if (D_800E416E & BTN_B) {
                func_800BA8D8(0x10);
                func_8007E0CC();
                D_800CD384 = 5;
                return 0x8000;
            }

            if ((D_800E416E & BTN_START) && (func_80079E88(0x5E)->unk_04 == 7)) {
                break;
            }

            if (D_800E416E & (BTN_A | BTN_START)) {
                func_800BA8D8(0x3E);
                D_800DCE48.unk_10 = (func_80079E88(0x5E)->unk_1C & 0xFFFF) - 39290;
                switch (D_800CD380) {
                    case 0:
                    case 1:
                    case 3:
                    case 5:
                        func_800BA8D8(0x21);
                        D_800CD384 = 1;
                        break;
                    case 2:
                        D_800CD384 = 5;
                        D_800F8514 = 0x36;
                        D_800E4178 = D_800E4180[D_800F8514];
                        gNumPlayers = 1;
                        func_800BB324(gNumPlayers - 1);
                        gDifficulty = D_800DCE48.unk_10 + 3;
                        return 0x8008;
                    case 6:
                        D_800CD384 = 5;
                        D_800CD048 = 0xD;
                        break;
                    case 4:
                        D_800CD384 = 5;
                        return 0xD;
                    case 7:
                        D_800CD384 = 5;
                        return 0x10;
                    default:
                        D_800CD384 = 2;
                        break;
                }
            }
            break;
        case 1:
            temp_t0 = D_800CD388[D_800CD380];
            if (D_800E416C & BTN_DOWN) {
                D_800CD388[D_800CD380]++;
            }
            if ((D_800CD3C0 < 2) && (D_800CD3C8 == 0)) {
                if (D_i6_8011EED0[D_800CD380] < D_800CD388[D_800CD380]) {
                    D_800CD388[D_800CD380] = D_i6_8011EED0[D_800CD380];
                }
            } else {
                if (D_i6_8011EEF0[D_800CD380] < D_800CD388[D_800CD380]) {
                    D_800CD388[D_800CD380] = D_i6_8011EEF0[D_800CD380];
                }
            }
            if (D_800CD380 == 3 && (D_800DD228 < D_800CD388[D_800CD380] + 2)) {
                D_800CD388[D_800CD380] = D_800DD228 - 2;
                if (D_800CD388[D_800CD380] < 0) {
                    D_800CD388[D_800CD380] = 0;
                    D_800CD384 = 0;
                    func_800BA8D8(0x10);
                    break;
                }
            }

            if (D_800E416C & BTN_UP) {
                if (D_800CD388[D_800CD380] > 0) {
                    D_800CD388[D_800CD380]--;
                }
            }
            if (temp_t0 != D_800CD388[D_800CD380]) {
                func_800BA8D8(0x1E);
            }
            if (D_800E416E & BTN_B) {
                D_800CD384 = 0;
                func_800BA8D8(0x10);
            } else if ((D_800E416E & BTN_START) && (func_80079E88(0x5E)->unk_04 == 7)) {
                break;
            } else if (D_800E416E & (BTN_A | BTN_START)) {
                func_800BA8D8(0x21);
                D_800CD384 = 2;
                switch (D_800CD380) {
                    case 3:
                        gNumPlayers = D_800CD388[3] + 2;
                        break;
                    case 1:
                        if (D_800CD388[1] != 0) {
                            D_800CD384 = 6;
                            D_800CD048 = 9;
                            func_800BA8D8(0x3E);
                        } else {
                            gNumPlayers = 1;
                        }
                        break;
                    case 0:
                    case 5:
                        gNumPlayers = 1;
                        gDifficulty = D_800DCE48.unk_10 + D_800CD388[D_800CD380];
                        break;
                }
            }
            break;
        case 2:
            Math_Rand1();
            if (D_800E416E & BTN_B) {
                func_800BA8D8(0x10);
                switch (D_800CD380) {
                    case 0:
                    case 1:
                    case 3:
                    case 5:
                        D_800CD384 = 1;
                        break;
                    default:
                        D_800CD384 = 0;
                        break;
                }
                break;
            }
            if ((D_800E416E & BTN_START) && (func_80079E88(0x5E)->unk_04 == 7)) {
                break;
            }
            if (D_800E416E & (BTN_A | BTN_START)) {
                func_800BA8D8(0x3E);
                func_800BB324((gNumPlayers - 1) & 0xFF);
                switch (D_800CD380) {
                    case 0:
                    case 1:
                    case 3:
                    case 5:
                        func_8008B1CC();
                        D_800CD384 = 3;
                        break;
                    default:
                        return 0x8000;
                }
            }
            break;
        case 3:
            if (func_80079E88(0x54)->unk_1C == 12) {
                var_v1_2 = false;
                switch (D_800CD380) {
                    case 1:
                        if (func_80079E88(0x5F)->unk_1C == 12) {
                            var_v1_2 = true;
                        }
                        break;
                    case 0:
                    case 5:
                        if (func_80079E88(0x5C)->unk_1C == 12) {
                            var_v1_2 = true;
                        }
                        break;
                    case 3:
                        if (func_80079E88(0x5A)->unk_1C == 12) {
                            var_v1_2 = true;
                        }
                        break;
                }
                if (var_v1_2) {
                    D_800CD384 = 4;
                }
            }
            if (D_800E416E & BTN_B) {
                func_800BA8D8(0x10);
                switch (D_800CD380) {
                    case 0:
                    case 1:
                    case 3:
                    case 5:
                        D_800CD384 = 1;
                        break;
                }
            }
            break;
        case 4:
            if (D_800CD044 == 0) {
                D_800CD048 = 0xB;
            }
            break;
        default:
            break;
    }
    return 0x8007;
}

Gfx* func_i6_801167CC(Gfx* gfx) {
    return func_80079BC8(gfx);
}

extern s8 D_800CD3C4;

void func_i6_801167EC(unk_800E3A28* arg0) {
    s32 i;

    arg0->unk_04 = D_800CD3C4;
    func_80077D50(D_i6_8011DDF0[arg0->unk_04], 0);

    switch (arg0->unk_04) {
        case 0:
            arg0->unk_0C = 8;
            /* fallthrough */
        case 1:
            for (i = 0; i < 240; i++) {
                D_i6_8011F910[i] = 0;
            }

            func_80077D50(D_i6_8011DDF0[2], 0);
            break;
    }
}

extern s16 D_800CD044;

void func_i6_80116894(unk_800E3A28* arg0) {
    s32 index = arg0->unk_00 - 0x51;

    func_80077D50(D_i6_8011DD70[index], 0);
    if (D_800CD044 == 0x21) {
        arg0->unk_1C = 0xC;
    }
}

void func_i6_801168EC(unk_800E3A28* arg0) {

    func_80077D50(D_i6_8011DDFC, 0);
    if (D_800CD044 == 0x21) {
        arg0->unk_1C = 0xC;
    }
}

void func_i6_80116934(void) {
    s32 i;

    func_80077D50(D_i6_8011DE1C, 0);

    for (i = 0; i < 3; i++) {
        func_80077D50(D_i6_8011DF6C[i], 0);
    }
}

void func_i6_80116990(void) {
    s32 i;

    func_80077D50(D_i6_8011DE1C, 0);

    for (i = 0; i < 4; i++) {
        func_80077D50(D_i6_8011DF5C[i], 0);
    }
}

void func_i6_801169EC(void) {
    s32 i;

    func_80077D50(D_i6_8011DE1C, 0);

    for (i = 0; i < 2; i++) {
        func_80077D50(D_i6_8011DF78[i], 0);
    }
}

void func_i6_80116A48(unk_800E3A28* arg0) {
    func_80077D50(D_i6_8011DF80, 0);
    arg0->unk_0C = 0x32;
}

s32 func_i6_8011DBD0(void);

void func_i6_80116A80(unk_800E3A28* arg0) {
    arg0->unk_1C = func_i6_8011DBD0();
}

extern u32 gGameFrameCount;
extern s32 D_800CD380;

Gfx* func_i6_80116AA8(Gfx* gfx, unk_800E3A28* arg1) {
    s32 temp_t0;
    s32 var_v1;
    s32 temp1;
    s32 temp2;

    temp_t0 = arg1->unk_00 - 0x51;

    if ((temp_t0 == 4) || (temp_t0 == 7)) {
        return gfx;
    }

    if (temp_t0 == D_800CD380) {
        if (D_800CD384 == 0) {
            var_v1 = gGameFrameCount % 30;

            if (var_v1 >= 15) {
                var_v1 = 30 - var_v1;
            }

            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255 - var_v1 * 5);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 180);
    }

    switch ((s32) D_800CD384) {
        case 3:
        case 4:
            if (++arg1->unk_1C > 12) {
                arg1->unk_1C = 12;
            }
            break;
        default:
            if (arg1->unk_1C > 0) {
                arg1->unk_1C--;
            }
            break;
    }

    if (arg1->unk_1C < 0) {
        arg1->unk_1C = 0;
    }

    temp1 = (((temp_t0 % 4) << 6) - (SQ(arg1->unk_1C) * 2)) + 0x20;
    temp2 = ((temp_t0 / 4) * 0x5B) + 0x26;

    return func_80078EA0(gfx, D_i6_8011DD70[temp_t0], temp1, temp2, 1, 0, 0, 1.0f, 1.0f);
}

extern Gfx D_3000088[];
extern f32 D_800DD230[];
extern s8 D_800CD3C4;

Gfx* func_i6_80116C78(Gfx* gfx, unk_800E3A28* arg1) {
    s32 j;
    s32 i;
    s32 var_t1;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 alpha;
    TexturePtr texture;
    unk_80077D50* sp44;
    unk_80077D50* var_ra;

    if (arg1->unk_04 < 3) {
        sp44 = D_i6_8011DDF0[arg1->unk_04];
        gfx = func_80078EA0(gfx, sp44, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
        gfx = func_8007A440(gfx, arg1->unk_0C, arg1->unk_10, arg1->unk_0C + sp44->width, arg1->unk_10 + sp44->height,
                            D_i6_8011DC60, D_i6_8011DC64, D_i6_8011DC68, D_i6_8011DC6C);
    } else {
        sp44 = D_i6_8011DDF0[D_800CD3C4];
        gfx = func_80078EA0(gfx, sp44, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
        var_t1 = (arg1->unk_04 / 10);
        var_ra = D_i6_8011DDF0[var_t1 - 1];

        texture = func_800783AC(var_ra->unk_04);

        sp58 = arg1->unk_0C;
        sp54 = arg1->unk_10;
        gSPDisplayList(gfx++, D_3000088);

        switch (arg1->unk_04) {
            case 10:
            case 20:
                arg1->unk_1C += 4;
                break;
            case 11:
            case 21:
                alpha = 0;

                arg1->unk_1C++;

                for (i = 0; i <= 100; i++) {
                    j = Math_Rand1() % 240;
                    if (D_i6_8011F910[j] == 0) {
                        D_i6_8011F910[j] = 1;
                        alpha++;
                    }

                    if (alpha >= 4) {
                        goto label;
                    }
                }

                for (j = 0; j < 240; j++) {
                    if (D_i6_8011F910[j] == 0) {
                        D_i6_8011F910[j] = 1;
                        alpha++;
                    }

                    if (alpha >= 4) {
                        goto label;
                    }
                }

            label:
                break;
            case 12:
            case 22:
                arg1->unk_1C += 4;
                break;
        }

        for (var_t1 = 0; var_t1 < 240; var_t1++) {

            switch (arg1->unk_04) {
                case 10:
                case 20:
                    if (var_t1 < arg1->unk_1C) {
                        alpha = SQ(arg1->unk_1C - var_t1) / 32;
                        if (alpha > 320) {
                            alpha = 320;
                        }
                        D_i6_8011F910[var_t1] = alpha;
                    } else {
                        D_i6_8011F910[var_t1] = 0;
                    }
                    alpha = 255;
                    sp50 = D_i6_8011F910[var_t1];

                    break;
                case 11:
                case 21:
                    if (D_i6_8011F910[var_t1] != 0) {
                        D_i6_8011F910[var_t1]++;
                    }
                    if (D_i6_8011F910[var_t1] > 18) {
                        D_i6_8011F910[var_t1] = 18;
                    }
                    sp50 = SQ(D_i6_8011F910[var_t1]);
                    alpha = 255;
                    break;
                case 12:
                case 22:
                    i = ((s32) ((s32) ((var_t1 << 0xC) * (arg1->unk_1C + 0x40)) / 64) / 240);
                    sp50 = (D_800DD230[i & 0xFFF] * arg1->unk_1C);
                    alpha = 255 - arg1->unk_1C;
                    if (alpha < 0) {
                        alpha = 0;
                    }
                    break;
            }

            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
            gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, var_ra->width, 1 /* unused by macro */, 0,
                               var_t1, var_ra->width, var_t1 + 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(gfx++, (sp58 + sp50) << 2, (sp54 + var_t1) << 2,
                                    ((sp58 + sp50) + var_ra->width) << 2, (sp54 + var_t1 + 1) << 2, 0, 0, 0, 1 << 10,
                                    1 << 10);
        }

        gfx = func_8007A440(gfx, arg1->unk_0C, arg1->unk_10, arg1->unk_0C + sp44->width, arg1->unk_10 + sp44->height,
                            D_i6_8011DC60, D_i6_8011DC64, D_i6_8011DC68, D_i6_8011DC6C);
        switch (arg1->unk_04) {
            case 10:
            case 20:
                if (D_i6_8011F910[239] >= 0x140) {
                    arg1->unk_04 = D_800CD3C4;
                }
                break;
            case 11:
            case 21:
                if (arg1->unk_1C > 80) {
                    arg1->unk_04 = D_800CD3C4;
                }
                break;
            case 12:
            case 22:
                if (arg1->unk_1C > 256) {
                    arg1->unk_04 = D_800CD3C4;
                }
                break;
        }
    }
    return gfx;
}

Gfx* func_i6_80117400(Gfx* gfx, unk_800E3A28* arg1) {
    s32 temp;

    switch (D_800CD384) {
        case 3:
        case 4:
            if (++arg1->unk_1C > 12) {
                arg1->unk_1C = 12;
            }
            break;
        default:
            if (arg1->unk_1C > 0) {
                arg1->unk_1C--;
            }
            break;
    }

    if (arg1->unk_1C < 0) {
        arg1->unk_1C = 0;
    }

    temp = SQ(arg1->unk_1C) * 2;

    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    return func_80078EA0(gfx, D_i6_8011DDFC, arg1->unk_0C - temp, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i6_801174DC(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    s32 temp_s7;

    if (D_800CD380 != 3) {
        return gfx;
    }

    switch (D_800CD384) {
        case 0:
        case 5:
        case 6:
            arg1->unk_1C = -12;
            break;
        case 3:
        case 4:
            if (++arg1->unk_1C > 12) {
                arg1->unk_1C = 12;
            }
            break;
        default:
            if (arg1->unk_1C > 0) {
                arg1->unk_1C--;
            }
            if (arg1->unk_1C < 0) {
                arg1->unk_1C++;
            }
            break;
    }
    temp_s7 = SQ(arg1->unk_1C) * 2;
    gfx = func_80078EA0(gfx, D_i6_8011DE1C, arg1->unk_0C - temp_s7, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);

    for (i = 0; i < 3; i++) {
        if (D_800CD388[D_800CD380] == i) {
            switch ((s32) D_800CD384) {
                case 2:
                case 3:
                case 4:
                    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                    break;
                default:
                    gfx = func_8007DB28(gfx, 0);
                    break;
            }
        } else {
            if ((D_800DD228 - 2) < i) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 128);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
        }
        gfx = func_80078EA0(gfx, D_i6_8011DF6C[i], (arg1->unk_0C - temp_s7) + 0x20, arg1->unk_10 + (i * 20) + 0xC, 1, 0,
                            0, 1.0f, 1.0f);
    }

    if (D_800CD384 != 2) {
        gfx = func_8007DB28(gfx, 0);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }

    return gfx;
}

Gfx* func_i6_80117760(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    s32 temp_s6;

    if (D_800CD380 != 5 && D_800CD380 != 0) {
        return gfx;
    }

    switch (D_800CD384) {
        case 0:
        case 5:
        case 6:
            arg1->unk_1C = -12;
            break;
        case 3:
        case 4:
            if (++arg1->unk_1C > 12) {
                arg1->unk_1C = 12;
            }
            break;
        default:
            if (arg1->unk_1C > 0) {
                arg1->unk_1C--;
            }
            if (arg1->unk_1C < 0) {
                arg1->unk_1C++;
            }
            break;
    }

    temp_s6 = SQ(arg1->unk_1C) * 2;
    gfx = func_80078EA0(gfx, D_i6_8011DE1C, arg1->unk_0C - temp_s6, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);

    for (i = 0; i < 4; i++) {
        if (D_800CD388[D_800CD380] == i) {
            switch ((s32) D_800CD384) {
                case 2:
                case 3:
                case 4:
                    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                    break;
                default:
                    gfx = func_8007DB28(gfx, 0);
                    break;
            }
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
        if ((D_800CD3C0 < 2) && (D_800CD3C8 == 0)) {
            if (i < 3) {
                gfx = func_80078EA0(gfx, D_i6_8011DF5C[i], (arg1->unk_0C - temp_s6) + 0x20,
                                    arg1->unk_10 + (i * 20) + 0xE, 1, 0, 0, 1.0f, 1.0f);
            }
        } else {
            gfx = func_80078EA0(gfx, D_i6_8011DF5C[i], (arg1->unk_0C - temp_s6) + 0x20, arg1->unk_10 + (i * 18) + 7, 1,
                                0, 0, 1.0f, 1.0f);
        }
    }

    return gfx;
}

Gfx* func_i6_80117A18(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    s32 temp_s7;
    unk_80077D50* temp_a1;

    if (D_800CD380 != 1) {
        return gfx;
    }
    switch (D_800CD384) {
        case 0:
        case 5:
            arg1->unk_1C = -12;
            break;
        case 3:
        case 4:
            if (++arg1->unk_1C > 12) {
                arg1->unk_1C = 12;
            }
            break;
        case 6:
        default:
            if (arg1->unk_1C > 0) {
                arg1->unk_1C--;
            }
            if (arg1->unk_1C < 0) {
                arg1->unk_1C++;
            }
            break;
    }

    temp_s7 = SQ(arg1->unk_1C) * 2;
    gfx = func_80078EA0(gfx, D_i6_8011DE1C, arg1->unk_0C - temp_s7, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);

    for (i = 0; i < 2; i++) {
        if (D_800CD388[1] == i) {
            switch ((s32) D_800CD384) {
                case 2:
                case 3:
                case 4:
                    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                    break;
                default:
                    gfx = func_8007DB28(gfx, 0);
                    break;
            }
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
        temp_a1 = D_i6_8011DF78[i];
        gfx = func_80078EA0(gfx, temp_a1, (((s32) (0x80 - temp_a1->width) / 2) + arg1->unk_0C) - temp_s7,
                            arg1->unk_10 + (i * 28) + 0x15, 1, 0, 0, 1.0f, 1.0f);
    }

    return gfx;
}

Gfx* func_i6_80117C50(Gfx* gfx, unk_800E3A28* arg1) {

    switch (D_800CD384) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
            gfx = func_8007DB28(gfx, 1);
            gfx = func_80078EA0(gfx, D_i6_8011DF80, arg1->unk_0C + 0x10B, arg1->unk_10 + 0xD0, 1, 0, 0, 1.0f, 1.0f);
            break;
        default:
            gfx = func_8007DB28(gfx, 0);
            gfx = func_80078EA0(gfx, D_i6_8011DF80, arg1->unk_0C + 0x10B, arg1->unk_10 + 0xD0, 1, 0, 0, 1.0f, 1.0f);
            break;
    }
    return gfx;
}

void func_i6_80117D3C(unk_800E3A28* arg0) {

    switch (D_800CD384) {
        case 2:
            func_8007A0A0(arg0, 0, 0xC0);
            arg0->unk_1C = 9;
            break;
        case 3:
        case 4:
            if (arg0->unk_1C != 0) {
                arg0->unk_1C--;
                func_8007A0A0(arg0, 0, 0xC0);
            } else {
                func_80079F54(arg0, 0x32, 4);
            }
            break;
        default:
            func_8007A0A0(arg0, 0x32, 0xC0);
            break;
    }
}

extern s8 D_800CD3C8;
extern u16 D_800E416C;
extern u16 D_800E416E;

void func_i6_80117DE0(unk_800E3A28* arg0) {
    unk_800E3A28* sp1C;

    if ((arg0->unk_04 < 8) && (D_800E416E != 0)) {
        if (D_i6_8011EF10[arg0->unk_04] & D_800E416C) {
            if (++arg0->unk_04 == 8) {
                D_800CD3C8 = 1;
                func_i2_80101414();
                func_800BA8D8(0x2E);
                sp1C = func_80079E88(0x50);
                if (sp1C->unk_04 < 2) {
                    sp1C->unk_04 = (Math_Rand1() % 3) + (sp1C->unk_04 * 10) + 10;
                }
            }
        } else {
            if (D_i6_8011EF10[0] & D_800E416E) {
                arg0->unk_04 = 1;
            } else {
                arg0->unk_04 = 0;
            }
        }
    }
}
