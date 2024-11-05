#include "global.h"
#include "fzx_racer.h"
#include "ovl_i3.h"
#include "tex_assets.h"

s16 D_i3_801419A0;
s16 D_i3_801419A2;
s16 D_i3_801419A4;
s16 D_i3_801419A6;
s32 D_i3_801419A8;
s32 D_i3_801419AC;
s32 D_i3_801419B0;
s32 D_i3_801419B4;
s32 D_i3_801419B8;
bool D_i3_801419BC;
UNUSED s32 D_i3_801419C0[4];
s32 D_i3_801419D0[30];
UNUSED s32 D_i3_80141A48;
bool sCannotSaveGhost;
s16 D_i3_80141A50[4][3];
s16 D_i3_80141A68[4];
f32 D_i3_80141A70[4][3];
Vec3f D_i3_80141AA0[4];
Vec3f D_i3_80141AD0;
TexturePtr D_i3_80141AE0[8][3];
u16 D_i3_80141B40[8][3];
s16 D_i3_80141B70[4];
s32 D_i3_80141B78[4];
s32 D_i3_80141B88[4];
s32 D_i3_80141B98;
s32 D_i3_80141B9C;
s32 D_i3_80141BA0;
s32 D_i3_80141BA4;
s32 D_i3_80141BA8;
s32 D_i3_80141BAC;
s32 D_i3_80141BB0;
s32 D_i3_80141BB4;
s32 D_i3_80141BB8;
s32 D_i3_80141BC0[4];
s32 D_i3_80141BD0[4];
s32 D_i3_80141BE0[4];
s32 D_i3_80141BF0[4];
f32 D_i3_80141C00[4];
f32 D_i3_80141C10[4];
s32 D_i3_80141C20[4];
s32 D_i3_80141C30[4];
f32 D_i3_80141C40[4];
f32 D_i3_80141C50[4];
u8* sRetireTexture;
u8* sRetirePalette;
u8* sWinnerTexture;
u8* sWinnerPalette;
u8* sLoserTexture;
u8* sLoserPalette;
s32 D_80141C78;
s32 D_i3_80141C7C;
s32 D_i3_80141C80;
s32 D_i3_80141C84;
unk_80141C88 D_i3_80141C88;
f32 D_i3_80141CC8;
s32 D_i3_80141CD0[4];
s32 D_i3_80141CE0[4];
s32 D_i3_80141CF0[4];
f32 D_i3_80141D00;
f32 D_i3_80141D04;
f32 D_i3_80141D08;
f32 D_i3_80141D0C;
s32 D_i3_80141D10;
s32 D_i3_80141D18[4];
s32 D_i3_80141D28[4];
s32 D_i3_80141D38[4];
s32 D_i3_80141D48[4];
s32 D_i3_80141D58[4];
s32 D_i3_80141D68;
s32 D_80141D6C;
s32 D_80141D70;
s32 D_i3_80141D78[4];
s32 D_i3_80141D88;
s32 D_i3_80141D8C;
s32 D_i3_80141D90;
s32 sRaceMenuOptionIndex;
s32 D_i3_80141D98;
s32 D_i3_80141D9C;
s32 D_i3_80141DA0;
s32 D_i3_80141DA4;
s32 D_i3_80141DA8;
s32 sPausePlayerNum;
bool sSaveGhostMenuOpen;
s32 D_i3_80141DB4;
s32 sOverwriteGhostOption;
s32 D_i3_80141DBC;
s32 D_i3_80141DC0;
s32 D_i3_80141DC4;
s32 sGhostSaveTimer;
s16 D_i3_80141DCC;
Racer* D_i3_80141DD0;
UNUSED s32 D_i3_80141DD4;
f32 D_i3_80141DD8;
f32 D_i3_80141DDC;
s32 D_i3_80141DE0[4];
s32 D_i3_80141DF0[4];
s32 D_i3_80141E00;
char D_i3_80141E08[32];
s32 D_i3_80141E28;

TexturePtr D_i3_8013ED30[] = {
    D_4029A20, D_4029AE0, D_4029BA0, D_4029C60, D_4029D20, D_4029DE0,
};

s16 D_i3_8013ED48[][4][2] = {
    { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },   { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },
    { { 118, 83 }, { 118, 196 }, { 200, 80 }, { 200, 193 } }, { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },
    { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },
};

void* sRaceMenuTextures[RACE_MENU_MAX] = {
    D_F25F0B0, // RACE_MENU_RETRY
    D_F25F1B0, // RACE_MENU_SETTINGS
    D_F25F334, // RACE_MENU_QUIT
    D_F25F400, // RACE_MENU_CHANGE_MACHINE
    D_F25F69C, // RACE_MENU_CHANGE_COURSE
    D_F25F914, // RACE_MENU_GHOST_SAVE
    D_F25FAD0, // RACE_MENU_OVERWRITE_DATA1
    D_F25FD70, // RACE_MENU_SAVING
    D_F25FE94, // RACE_MENU_NO_GAME_PAK
    D_F26008C, // RACE_MENU_NO_DISK
    D_F2601C0, // RACE_MENU_OVERWRITE_DATA2
    D_F260460, // RACE_MENU_CLEAR_RECORD
    D_F26064C, // RACE_MENU_ERASE_COURSE_DATA1
    D_F260A98, // RACE_MENU_CLEAR_GHOST
    D_F260C64, // RACE_MENU_ERASE_COURSE_DATA2
    D_F2610B0, // RACE_MENU_CONTINUE
    D_F2636F0, // RACE_MENU_YES
    D_F2637DC, // RACE_MENU_NO
    D_F261224, // RACE_MENU_SAVED
    D_F261364, // RACE_MENU_NEW_GHOST
    D_F261528, // RACE_MENU_SAVED_GHOST
    D_F2638B4, // RACE_MENU_CANNOT_SAVE_GHOST
    D_F263648, // RACE_MENU_LEFT_ARROW
    D_F26369C, // RACE_MENU_RIGHT_ARROW
};

s32 sRaceMenuDimensions[RACE_MENU_MAX * 2] = {
    40,  16, // RACE_MENU_RETRY
    64,  16, // RACE_MENU_SETTINGS
    24,  16, // RACE_MENU_QUIT
    64,  16, // RACE_MENU_CHANGE_MACHINE
    64,  16, // RACE_MENU_CHANGE_COURSE
    64,  16, // RACE_MENU_GHOST_SAVE
    128, 16, // RACE_MENU_OVERWRITE_DATA1
    40,  16, // RACE_MENU_SAVING
    64,  16, // RACE_MENU_NO_GAME_PAK
    40,  16, // RACE_MENU_NO_DISK
    128, 16, // RACE_MENU_OVERWRITE_DATA2
    64,  16, // RACE_MENU_CLEAR_RECORD
    96,  32, // RACE_MENU_ERASE_COURSE_DATA1
    64,  16, // RACE_MENU_CLEAR_GHOST
    96,  32, // RACE_MENU_ERASE_COURSE_DATA2
    64,  16, // RACE_MENU_CONTINUE
    32,  16, // RACE_MENU_YES
    32,  16, // RACE_MENU_NO
    64,  16, // RACE_MENU_SAVED
    64,  16, // RACE_MENU_NEW_GHOST
    128, 16, // RACE_MENU_SAVED_GHOST
    128, 32, // RACE_MENU_CANNOT_SAVE_GHOST
    16,  16, // RACE_MENU_LEFT_ARROW
    16,  16, // RACE_MENU_RIGHT_ARROW
};

void func_i3_8011AE70(void) {
    D_i3_801419B0 = D_i3_801419B4 = 0;
}

void func_i3_8011AE88(void) {
    D_i3_801419A8 = D_i3_801419AC = 0;
}

extern s8 D_800DCE5C;
extern s32 D_800DD218[];
extern s32 D_i2_80106F10;
extern s32 D_i3_801419B0;
extern Controller D_800DCE98[];
extern s32 D_800DD218[];
extern s32 gNumPlayers;
extern s32 D_800DCE44;
extern s32 D_800F8514;
extern s16 D_800CD048;
extern s32 D_800E5EC0;
extern s16 D_80115D50[];

void func_i3_8013BF50(s32);
void func_i3_8013C008(void);
void func_i2_801016DC(void);

void func_i3_8011AEA0(void) {
    s32 i;

    if (D_i3_801419B0 != 0) {
        if (D_i3_801419B0 & 1) {
            D_800DCE5C = 1;
            func_800BB0C0(1);
            func_800BA8D8(12);
            func_80069700();
        }
        if (D_i3_801419B0 & 2) {
            D_800DCE5C = 0;
            D_i2_80106F10 = 4;
            for (i = 0; i < gNumPlayers; i++) {
                D_800DCE98[D_800DD218[i]].unk_72 = 1;
            }
            func_800BB0C0(0);
            func_800BA8D8(13);
        }
        if ((D_i3_801419B0 & 4) && (D_i3_801419A0 == 0)) {
            if (D_800DCE44 == 0xE) {
                if (D_800F8514 < 0x30) {
                    func_80089BD0();
                    func_i3_8013C008();
                }
                if (D_800F8514 < 0x18) {
                    func_i2_80101118(D_800F8514);
                }
            } else if (D_800DCE44 == 1) {
                func_i3_8013BF50(D_800F8514);
            } else if (D_800DCE44 == 0x15) {
                func_80089BD0();
                func_i2_801016DC();
            }
            D_i3_801419A0 = 1;
        }
        if ((D_i3_801419A4 == 0) && (D_i3_801419A6 == 0)) {
            if (D_i3_801419B0 & 8) {
                func_80095144();
                D_800CD048 = 1;
                D_i3_801419A4 = 1;
            }
            if (D_i3_801419B0 & 0x10) {
                func_80095144();
                D_800CD048 = 2;
                D_i3_801419A4 = 1;
            }
            if (D_i3_801419B0 & 0x20) {
                func_80095144();
                D_800CD048 = 7;
                D_i3_801419A4 = 1;
            }
            if (D_i3_801419B0 & 0x40) {
                func_80095144();
                D_800CD048 = 3;
                D_i3_801419A4 = 1;
            }
            if (D_i3_801419B0 & 0x80) {
                func_80095144();
                D_800CD048 = 15;
                D_i3_801419A4 = 1;
            }
            if (D_i3_801419B0 & 0x100) {
                func_80095144();
                D_800CD048 = 6;
                D_i3_801419A4 = 1;
            }
            if (D_i3_801419B0 & 0x200) {
                if ((gNumPlayers == 1) && (D_800DCE44 == 1)) {
                    for (i = 0; i < D_800E5EC0; i++) {
                        D_80115D50[i] = gRacers[i].unk_2AC;
                    }
                }
                func_80095144();
                D_800CD048 = 4;
                D_i3_801419A4 = 1;
            }
            if (D_i3_801419B0 & 0x400) {
                func_80095144();
                D_800CD048 = 5;
                D_i3_801419A4 = 1;
            }
        }
    }
    if (D_i3_801419A6 == 0) {
        func_i3_8011AE70();
    } else {
        D_i3_801419A6--;
    }
}

extern Gfx D_8014940[];

Gfx* func_i3_DrawBeveledBox(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue,
                            s32 alpha) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 10, 1 << 10);
    // Draw Border At Top and Bottom
    gSPTextureRectangle(gfx++, (left + 1) << 2, (top - 1) << 2, (right - 1) << 2, top << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left + 1) << 2, bottom << 2, (right - 1) << 2, (bottom + 1) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    return gfx;
}

extern Gfx D_8014940[];

Gfx* func_i3_8011B41C(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

void func_i3_80122C3C(void);
void func_i3_8013C080(void);
extern unk_800CD970 D_800CD970[];
extern s32* D_800CD9AC[];

extern unk_800F5DF0* D_800F5E90;
extern s16 D_800E5ED8[];
extern s16 D_80115DE0;

extern unk_800F8510* D_800F8510;
extern s32 D_80141900;

void func_i3_8011B520(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 index2;
    s32 temp_a1;
    s32 pad;

    D_i3_80141AD0.x = Math_Rand2() % 256 / 255.0f * 0.3f + 6.04f - 0.15f;
    D_i3_80141AD0.y = Math_Rand1() % 256 / 255.0f * 0.3f + 4.18f - 0.15f;
    D_i3_80141AD0.z = Math_Rand2() % 256 / 255.0f * 0.3f + 5.12f - 0.15f;

    D_80115DE0 = D_800E5EC0;
    D_i3_80141E00 = 0;

    for (i = 0; i < 5; i++) {
        D_i3_80141E00 += D_800CD970[i].unk_02;
    }

    for (i = 0; i < 4; i++) {
        D_i3_80141A68[i] = 0;

        for (j = 0; j < 3; j++) {
            D_i3_80141A50[i][j] = Math_Rand2() % 6;
            D_i3_80141A70[i][j] = (Math_Rand2() % 10) * -1.0f;
        }

        D_i3_80141BC0[i] = D_i3_80141DE0[i] = D_i3_80141DF0[i] = 0;

        D_i3_80141AA0[i].x = D_i3_80141AD0.x;
        D_i3_80141AA0[i].y = D_i3_80141AD0.y;
        D_i3_80141AA0[i].z = D_i3_80141AD0.z;

        D_i3_80141C20[i] = D_i3_80141CF0[i] = D_i3_80141CD0[i] = D_i3_80141CE0[i] = D_i3_80141BE0[i] =
            D_i3_80141B78[i] = D_i3_80141B88[i] = D_i3_80141D78[i] = D_i3_80141BF0[i] = D_i3_80141BD0[i] =
                D_i3_80141B70[i] = D_i3_80141C30[i] = 0;

        D_i3_80141C10[i] = D_i3_80141C50[i] = 0.0f;
        D_i3_80141C40[i] = -20.0f;
        D_i3_80141C00[i] = 10.0f;
    }

    sGhostSaveTimer = sOverwriteGhostOption = sSaveGhostMenuOpen = D_i3_80141DC4 = D_i3_80141DBC = D_i3_80141B98 =
        D_i3_80141B9C = D_80141D6C = D_i3_80141D88 = D_i3_80141D8C = sRaceMenuOptionIndex = D_i3_80141D9C =
            D_i3_801419A2 = D_i3_801419A0 = D_i3_80141DCC = D_i3_801419A4 = D_i3_801419A6 = D_i3_801419BC = D_80141900 =
                D_i3_80141D90 = 0;

    D_i3_80141D08 = D_i3_80141CC8 = 0.0f;
    D_i3_80141DC0 = D_i3_80141DB4 = 90;
    D_i3_80141DA0 = D_i3_80141D98 = 60;
    D_i3_80141DCC = 0;
    D_i3_801419B8 = D_800E5ED8[0];
    sRetireTexture = func_80078104(D_F25A8F0, 0x1000, 0, 0, 0);
    sRetirePalette = func_80078104(D_F25B8F0, 0x200, 0, 0, 0);
    func_80078104(D_F25F070, 0x200, 0, 0, 0);
    func_80078104(D_F25F0B0, 0x280, 0, 1, 0);
    func_80078104(D_F25F1B0, 0x400, 0, 1, 0);
    func_80078104(D_F25F334, 0x180, 0, 1, 0);
    func_80078104(D_F2610B0, 0x400, 0, 1, 0);

    if (D_800DCE44 == 0x15) {
        func_80078104(D_F25F400, 0x400, 0, 1, 0);
        func_80078104(D_F243290, 0x180, 0, 0, 0);
    }
    if (D_800DCE44 == 0xE) {
        func_80078104(D_F25F400, 0x400, 0, 1, 0);
        func_80078104(D_F25F69C, 0x400, 0, 1, 0);
        func_80078104(D_F25F914, 0x400, 0, 1, 0);
        func_80078104(D_F25FAD0, 0x800, 0, 1, 0);
        func_80078104(D_F261224, 0x400, 0, 1, 0);
        func_80078104(D_F25FD70, 0x280, 0, 1, 0);
        func_80078104(D_F2636F0, 0x200, 0, 1, 0);
        func_80078104(D_F2637DC, 0x200, 0, 1, 0);
        func_80078104(D_F261364, 0x400, 0, 1, 0);
        func_80078104(D_F261528, 0x800, 0, 1, 0);
        func_80078104(D_F2638B4, 0x1000, 0, 1, 0);
        func_80078104(D_F263648, 0x100, 0, 1, 0);
        func_80078104(D_F26369C, 0x100, 0, 1, 0);
        sLoserTexture = func_80078104(D_F25CCF0, 0x960, 0, 0, 0);
        sLoserPalette = func_80078104(D_F25D650, 0x200, 0, 0, 0);
        func_i3_80122C3C();
        if (D_i3_80141C84 >= 0) {
            D_i3_80141DD0 = D_800F5E90->unk_30;
            D_i3_80141DD8 = D_i3_80141DD0->unk_244;
            D_i3_80141DDC = D_800F8510->unk_0C * -1.0f;
        }
    }

    if ((D_800DCE44 == 3) || (D_800DCE44 == 4) || (D_800DCE44 == 5) || (D_800DCE44 == 0xE)) {
        sWinnerTexture = func_80078104(D_F25BAF0, 0x1000, 0, 0, 0);
        sWinnerPalette = func_80078104(D_F25CAF0, 0x200, 0, 0, 0);
    }
    if ((D_800DCE44 == 2) || (D_800DCE44 == 3) || (D_800DCE44 == 4) || (D_800DCE44 == 5)) {
        func_80078104(D_F25F400, 0x400, 0, 1, 0);
        func_80078104(D_F25F69C, 0x400, 0, 1, 0);
        func_80078104(D_F25D858, 0x800, 0, 0, 0);
        func_80078104(D_F25E060, 0x800, 0, 0, 0);
        func_80078104(D_F25E868, 0x800, 0, 0, 0);

        for (j = 0; j < 3; j++) {
            D_i3_80141B40[0][j] = 0x20;
            D_i3_80141B40[1][j] = 0x20;
            D_i3_80141B40[2][j] = 0x20;
            D_i3_80141B40[3][j] = 0x20;
            D_i3_80141B40[4][j] = 0x1E;
            D_i3_80141B40[5][j] = 0x1E;
            D_i3_80141B40[6][j] = 0x1F;
            D_i3_80141B40[7][j] = 0x1F;

            for (i = 0; i < gNumPlayers; i++) {
                D_i3_80141B40[i][j] = gRacers[i].character;
            }

            for (i = 0; i < 3; i++) {
                for (k = 1; k < 4; k++) {
                    if (i != k) {
                        if (D_i3_80141B40[i][j] == D_i3_80141B40[k][j]) {
                            D_i3_80141B40[k][j] = 0x20;
                        }
                    }
                }
            }

            for (i = 0; i < 30; i++) {
                k = Math_Rand2() % 8;
                index2 = Math_Rand1() % 8;

                temp_a1 = D_i3_80141B40[k][j];
                D_i3_80141B40[k][j] = D_i3_80141B40[index2][j];
                D_i3_80141B40[index2][j] = temp_a1;
            }

            for (i = 0; i < 8; i++) {
                if (D_i3_80141B40[i][j] < 30) {
                    D_i3_80141AE0[i][j] = sCharacterPortraitTextures[D_i3_80141B40[i][j]];
                } else {
                    switch (D_i3_80141B40[i][j]) {
                        case 30:
                            D_i3_80141AE0[i][j] = func_800783AC(D_F25D858);
                            break;
                        case 31:
                            D_i3_80141AE0[i][j] = func_800783AC(D_F25E060);
                            break;
                        case 32:
                            D_i3_80141AE0[i][j] = func_800783AC(D_F25E868);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    func_i3_8011AE70();
    func_i3_80139D20();
    func_i3_8013C080();
}

extern u8 D_4011778[];
extern u8 D_401A120[];

extern Racer* D_800E5F40[];
extern Gfx D_80149D0[];

extern u32 gGameFrameCount;
extern s8 D_800CD010;

Gfx* func_i3_8011C25C(Gfx* gfx, s32 playerNum) {
    s32 i;
    s32 var_v1;
    f32 var_ft5;
    s32 var_a2_2;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 temp_ft0;
    s32 pad[2];

    if ((D_800DCE5C == 0) && (D_800CD010 == 0)) {
        if (D_i3_80141AA0[playerNum].x != 0.0f) {
            D_i3_80141A70[playerNum][0] += D_i3_80141AA0[playerNum].x;
            if (D_i3_80141A70[playerNum][0] > 0.0f) {
                D_i3_80141A70[playerNum][0] -= 32.0f;
                D_i3_80141A50[playerNum][0]++;
                if (D_i3_80141A50[playerNum][0] >= 8) {
                    D_i3_80141A50[playerNum][0] = 0;
                }
            }
            if (D_i3_80141AA0[playerNum].x < (D_i3_80141AD0.x * 0.4f)) {
                if ((D_i3_80141AD0.x * (-0.4f)) < D_i3_80141A70[playerNum][0]) {
                    D_i3_80141A70[playerNum][0] = 0.0f;
                    D_i3_80141AA0[playerNum].x = 0.0f;
                } else {
                    D_i3_80141AA0[playerNum].x = D_i3_80141AD0.x * 0.4f;
                }
            }
        }
        if (D_i3_80141AA0[playerNum].y != 0.0f) {
            D_i3_80141A70[playerNum][1] += D_i3_80141AA0[playerNum].y;
            if (D_i3_80141A70[playerNum][1] > 0.0f) {
                D_i3_80141A70[playerNum][1] -= 32.0f;
                D_i3_80141A50[playerNum][1]++;
                if (D_i3_80141A50[playerNum][1] >= 8) {
                    D_i3_80141A50[playerNum][1] = 0;
                }
            }
            if (D_i3_80141AA0[playerNum].y < (D_i3_80141AD0.y * 0.4f)) {
                if ((D_i3_80141AD0.y * (-0.4f)) < D_i3_80141A70[playerNum][1]) {
                    D_i3_80141A70[playerNum][1] = 0.0f;
                    D_i3_80141AA0[playerNum].y = 0.0f;
                } else {
                    D_i3_80141AA0[playerNum].y = D_i3_80141AD0.y * 0.4f;
                }
            }
        }
        if (D_i3_80141AA0[playerNum].z != 0.0f) {
            D_i3_80141A70[playerNum][2] += D_i3_80141AA0[playerNum].z;
            if (D_i3_80141A70[playerNum][2] > 0.0f) {
                D_i3_80141A70[playerNum][2] -= 32.0f;
                D_i3_80141A50[playerNum][2]++;
                if (D_i3_80141A50[playerNum][2] >= 8) {
                    D_i3_80141A50[playerNum][2] = 0;
                }
            }
            if (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == D_i3_80141B40[D_i3_80141A50[playerNum][1]][1]) {
                if (D_i3_80141AA0[playerNum].z < (D_i3_80141AD0.z * 0.2f)) {
                    if ((D_i3_80141AD0.z * (-0.2f)) < D_i3_80141A70[playerNum][2]) {
                        D_i3_80141A70[playerNum][2] = 0.0f;
                        D_i3_80141AA0[playerNum].z = 0.0f;
                    } else {
                        D_i3_80141AA0[playerNum].z = D_i3_80141AD0.z * 0.2f;
                    }
                }
            } else if (D_i3_80141AA0[playerNum].z < (D_i3_80141AD0.z * 0.4f)) {
                if ((D_i3_80141AD0.z * (-0.4f)) < D_i3_80141A70[playerNum][2]) {
                    D_i3_80141A70[playerNum][2] = 0.0f;
                    D_i3_80141AA0[playerNum].z = 0.0f;
                } else {
                    D_i3_80141AA0[playerNum].z = D_i3_80141AD0.z * 0.4f;
                }
            }
        }
        if (D_i3_80141A68[playerNum] > 0) {
            D_i3_80141AA0[playerNum].x *= 0.8f;
        }
        if (D_i3_80141A68[playerNum] >= 2) {
            D_i3_80141AA0[playerNum].y *= 0.8f;
        }
        if (D_i3_80141A68[playerNum] >= 3) {
            if (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == D_i3_80141B40[D_i3_80141A50[playerNum][1]][1]) {
                D_i3_80141AA0[playerNum].z *= 0.91f;
            } else {
                D_i3_80141AA0[playerNum].z *= 0.8f;
            }
        }
        if (D_i3_80141B70[playerNum] != 0) {
            D_i3_80141B70[playerNum]--;
        } else if (D_i3_80141A68[playerNum] < 4) {
            if (D_i3_80141A68[playerNum] < 3) {
                if ((D_800DCE98[D_800DD218[playerNum]].unk_7C & BTN_A) &&
                    (((D_i3_80141A68[playerNum] == 0) ||
                      ((D_i3_80141A68[playerNum] == 1) && (D_i3_80141AA0[playerNum].x == 0.0f))) ||
                     ((D_i3_80141A68[playerNum] == 2) && (D_i3_80141AA0[playerNum].y == 0.0f)))) {
                    D_i3_80141A68[playerNum]++;
                    func_800BA710(playerNum, 0x31);
                }
            }
            if ((D_i3_80141A68[playerNum] == 3) &&
                (((D_i3_80141AA0[playerNum].x + D_i3_80141AA0[playerNum].y) + D_i3_80141AA0[playerNum].z) == 0.0f)) {
                D_i3_80141A68[playerNum]++;
                if ((D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == D_i3_80141B40[D_i3_80141A50[playerNum][1]][1]) &&
                    (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == D_i3_80141B40[D_i3_80141A50[playerNum][2]][2])) {
                    func_800BA710(playerNum, 0x30);
                    D_i3_80141B70[playerNum] = 0x78;
                    var_v1 = 0;
                    for (i = 0; i < D_800E5EC0; i++) {
                        if ((D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == gRacers[i].character) &&
                            (!(gRacers[i].unk_04 & 0x08000000))) {
                            gRacers[i].unk_228 = 0.0f;
                            var_v1++;
                        }
                    }

                    if ((var_v1 == 0) && (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] < 0x1E)) {
                        for (i = 0; i < D_800E5EC0; i++) {
                            gRacers[i].unk_228 /= 2.0f;
                        }
                    }
                    if (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == 0x1E) {
                        D_800E5F40[0]->unk_228 = 0.0f;
                    }
                    if (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == 0x1F) {
                        for (i = 0; i < D_800E5EC0; i++) {
                            gRacers[i].unk_228 = 0.0f;
                        }
                    }
                    if (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == 0x20) {
                        for (i = 0; i < D_800E5EC0; i++) {
                            gRacers[i].unk_228 /= 2.0f;
                        }
                    }
                }
            }
        } else {
            D_i3_80141A68[playerNum]++;
            if (D_i3_80141A68[playerNum] >= 5) {
                D_i3_80141A68[playerNum] = 5;
            }
            if (D_i3_80141A68[playerNum] >= 5) {
                if (D_800DCE98[D_800DD218[playerNum]].unk_7C & BTN_B) {
                    D_i3_80141A68[playerNum] = 0;
                    D_i3_80141AA0[playerNum].x = D_i3_80141AD0.x;
                    D_i3_80141AA0[playerNum].y = D_i3_80141AD0.y;
                    D_i3_80141AA0[playerNum].z = D_i3_80141AD0.z;
                }
            }
        }
        gSPDisplayList(gfx++, D_80149D0);
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, D_4011778, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, D_i3_8013ED48[gNumPlayers][playerNum][0] << 2,
                            (D_i3_8013ED48[gNumPlayers][playerNum][1] - 12) << 2,
                            (D_i3_8013ED48[gNumPlayers][playerNum][0] + 63) << 2,
                            (D_i3_8013ED48[gNumPlayers][playerNum][1] - 1) << 2, 0, 0, 0, 1 << 12, 1 << 10);
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_8013ED48[gNumPlayers][playerNum][0],
                      D_i3_8013ED48[gNumPlayers][playerNum][1], D_i3_8013ED48[gNumPlayers][playerNum][0] + 127,
                      D_i3_8013ED48[gNumPlayers][playerNum][1] + 32);
        for (i = 0; i < 3; i++) {
            var_a2_2 = D_i3_80141A50[playerNum][i] - 1;
            if (var_a2_2 < 0) {
                var_a2_2 = 7;
            }
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_i3_80141AE0[var_a2_2][i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            temp_ft0 = D_i3_80141A70[playerNum][i];
            left = D_i3_8013ED48[gNumPlayers][playerNum][0] + (i * 32);
            top = D_i3_8013ED48[gNumPlayers][playerNum][1] + temp_ft0 + 32;
            right = D_i3_8013ED48[gNumPlayers][playerNum][0] + (i * 32) + 31;
            bottom = D_i3_8013ED48[gNumPlayers][playerNum][1] + temp_ft0 + 63;
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 12, 1 << 10);
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_i3_80141AE0[D_i3_80141A50[playerNum][i]][i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32,
                                32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            top = D_i3_8013ED48[gNumPlayers][playerNum][1] + temp_ft0;
            bottom = D_i3_8013ED48[gNumPlayers][playerNum][1] + temp_ft0 + 31;
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 12, 1 << 10);
        }

        left = D_i3_8013ED48[gNumPlayers][playerNum][0];
        right = D_i3_8013ED48[gNumPlayers][playerNum][0] + 96;
        top = bottom = D_i3_8013ED48[gNumPlayers][playerNum][1];
        gfx = func_i3_DrawBeveledBox(gfx, left, top, right, bottom, 255, 255, 255, 255);
        top = bottom = D_i3_8013ED48[gNumPlayers][playerNum][1] + 32;
        gfx = func_i3_DrawBeveledBox(gfx, left, top, right, bottom, 255, 255, 255, 255);
        gSPDisplayList(gfx++, D_80149D0);
        if ((D_i3_80141AA0[playerNum].x + D_i3_80141AA0[playerNum].y) == 0.0f) {
            if ((((D_i3_80141B40[D_i3_80141A50[playerNum][0]][0]) == D_i3_80141B40[D_i3_80141A50[playerNum][1]][1]) &&
                 ((gGameFrameCount % 20) >= 5)) &&
                ((D_i3_80141A68[playerNum] == 2) ||
                 ((D_i3_80141A68[playerNum] >= 3) && (D_i3_80141AA0[playerNum].z != 0.0f)))) {
                gSPDisplayList(gfx++, D_80149D0);
                gDPPipeSync(gfx++);
                gDPLoadTextureBlock(gfx++, D_401A120, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gfx++, (D_i3_8013ED48[gNumPlayers][playerNum][0] + 64) << 2,
                                    D_i3_8013ED48[gNumPlayers][playerNum][1] << 2,
                                    (D_i3_8013ED48[gNumPlayers][playerNum][0] + 95) << 2,
                                    (D_i3_8013ED48[gNumPlayers][playerNum][1] + 31) << 2, 0, 0, 0, 1 << 12, 1 << 10);
            }
        }
        if ((((D_i3_80141AA0[playerNum].x + D_i3_80141AA0[playerNum].y) + D_i3_80141AA0[playerNum].z) == 0.0f) &&
            (D_i3_80141A68[playerNum] >= 3)) {
            if (((D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == D_i3_80141B40[D_i3_80141A50[playerNum][1]][1]) &&
                 (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == D_i3_80141B40[D_i3_80141A50[playerNum][2]][2])) &&
                ((gGameFrameCount % 20) >= 5)) {
                gSPDisplayList(gfx++, D_80149D0);
                gDPLoadTextureBlock(gfx++, D_401A120, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gfx++, (D_i3_8013ED48[gNumPlayers][playerNum][0] + 64) << 2,
                                    D_i3_8013ED48[gNumPlayers][playerNum][1] << 2,
                                    (D_i3_8013ED48[gNumPlayers][playerNum][0] + 95) << 2,
                                    (D_i3_8013ED48[gNumPlayers][playerNum][1] + 31) << 2, 0, 0, 0, 1 << 12, 1 << 10);
                for (i = 0; i < 3; i++) {
                    gSPTextureRectangle(gfx++, (D_i3_8013ED48[gNumPlayers][playerNum][0] + (i * 32)) << 2,
                                        D_i3_8013ED48[gNumPlayers][playerNum][1] << 2,
                                        ((D_i3_8013ED48[gNumPlayers][playerNum][0] + (i * 32)) + 31) << 2,
                                        (D_i3_8013ED48[gNumPlayers][playerNum][1] + 31) << 2, 0, 0, 0, 1 << 12,
                                        1 << 10);
                }
            }
        }
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    }
    return gfx;
}

extern Gfx D_8014940[];
extern u8 D_303C3F0[];
Gfx* func_i3_8012F8E4(Gfx*, s32, s32);

Gfx* func_i3_8011D8F0(Gfx* gfx, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return func_i3_8012F8E4(gfx, left + 8, top);
}

Gfx* func_i3_8012F9F4(Gfx*, s32, s32);

Gfx* func_i3_8011DA44(Gfx* gfx, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return func_i3_8012F9F4(gfx, left + 8, top);
}

Gfx* func_i3_8011DB98(Gfx* gfx, s32 time, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }
    if (time <= -MAX_TIMER) {
        time = -MAX_TIMER;
    }

    return func_i3_80133944(gfx, time, left, top, 1.0f);
}

extern u8 D_303D1F0[];
extern u8 D_40131E0[];
extern u8 D_4019CA0[];
extern s32 D_800CD00C;
extern s16 D_800E5FE2;
extern s16 D_800E5FE6;

Gfx* func_i3_8011DD30(Gfx* gfx, s32 arg1) {
    s32 sp144;
    s32 left;
    s32 top;
    s32 i;
    f32 scale = 1.0f;

    gSPDisplayList(gfx++, D_80149D0);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left = D_i3_80141BA0 - D_i3_80141B9C;
    if (left >= 0) {
        for (i = 1; i <= D_800CD00C; i++) {
            top = ((i - 1) * D_i3_80141BA8) + D_i3_80141BA4 + 3;
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (15.0f * scale)) << 2,
                                    (s32) (top + (11.0f * scale)) << 2, 0, 0, 0, (s32) (4096.0f / scale),
                                    (s32) (1024.0f / scale));
        }
    }
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, D_4019CA0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left += 0x11;

    if (left >= 0) {
        for (i = 1; i <= D_800CD00C; i++) {
            top = ((i - 1) * D_i3_80141BA8) + D_i3_80141BA4 + 3;

            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (7.0f * scale)) << 2,
                                    (s32) (top + (11.0f * scale)) << 2, 0, 0, (i * 12) << 5, (s32) (4096.0f / scale),
                                    (s32) (1024.0f / scale));
        }
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, D_40131E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left = D_i3_80141BA0 - D_i3_80141B9C;
    top = (D_800CD00C * D_i3_80141BA8) + (D_i3_80141BA8 / 2) + D_i3_80141BA4;
    if (left > 0) {
        gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (23.0f * scale)) << 2,
                                (s32) (top + (15.0f * scale)) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (sp144 = 0; sp144 < D_800CD00C; sp144++) {
        top = (sp144 * D_i3_80141BA8) + D_i3_80141BA4;
        if (D_i3_80141B88[arg1] < ((D_i3_80141BB4 * sp144) + D_i3_80141BB0)) {
            top += (((D_i3_80141BB4 * sp144) + D_i3_80141BB0) - D_i3_80141B88[arg1]) * D_i3_80141BB8;
        }
        if ((D_800DCE44 == 0xE) && ((((D_i3_80141BB4 * sp144) + D_i3_80141BB0) - D_i3_80141B88[arg1]) == 1) &&
            (D_800CD010 == 0)) {
            func_800BA8D8(0x22);
        }
        if (top < 240) {
            gDPPipeSync(gfx++);
            if ((sp144 + 1) == D_800E5FE6) {
                gfx = func_8007F090(gfx, 255, 0, 0);
                gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
            gfx = func_i3_8012F554(gfx, gRacers[arg1].unk_290[sp144], D_i3_80141BA0 + D_i3_80141BAC + D_i3_80141B9C,
                                   top, 1.0f);
        }
    }

    top = (D_800CD00C * D_i3_80141BA8) + (D_i3_80141BA8 / 2) + D_i3_80141BA4;
    if (D_i3_80141B88[arg1] < ((D_i3_80141BB4 * sp144) + D_i3_80141BB0)) {
        top += (((D_i3_80141BB4 * D_800CD00C) + D_i3_80141BB0) - D_i3_80141B88[arg1]) * D_i3_80141BB8;
    }
    if ((D_800DCE44 == 0xE) && ((((D_i3_80141BB4 * D_800CD00C) + D_i3_80141BB0) - D_i3_80141B88[arg1]) == 1) &&
        (D_800CD010 == 0)) {
        func_800BA8D8(0x22);
    }
    if ((D_800DCE44 == 0xE) && ((((D_i3_80141BB4 * (D_800CD00C + 1)) + D_i3_80141BB0) - D_i3_80141B88[arg1]) == 1) &&
        (D_800E5FE2 == 1) && (D_800CD010 == 0)) {
        func_800BA8D8(0x2A);
    }
    if (top < 240) {
        gDPPipeSync(gfx++);
        if (D_800E5FE2 != 0) {
            gfx = func_8007F090(gfx, 255, 0, 0);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
        gfx = func_i3_8012F554(gfx, gRacers[arg1].unk_2A0, D_i3_80141BA0 + D_i3_80141BAC + D_i3_80141B9C, top, 1.0f);
    }

    D_i3_80141B88[arg1]++;
    if (D_i3_80141B88[arg1] >= 3000) {
        D_i3_80141B88[arg1] = 3000;
    }
    return gfx;
}

extern Gfx D_8014940[];

Gfx* func_i3_8011ECF0(Gfx* gfx) {
    f32 scale;
    s32 temp_v0;
    s32 left;
    s32 i;
    s32 top;
    s32 character;
    s32 var_s6;
    s32 index;
    s32* new_var;

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gSPDisplayList(gfx++, D_80149D0);

    for (i = 0; i < 6; i++) {
        if (i == D_800E5EC0) {
            break;
        }
        top = 130;
        left = (i * 40 + 45);

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, D_i3_8013ED30[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 6, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, left << 2, top << 2, (left + 15) << 2, (top + 5) << 2, 0, 0, 0, 1 << 12,
                                1 << 10);
    }
    gSPDisplayList(gfx++, D_8014940);

    index = 0;
    for (i = 0; i < 6; i++) {
        scale = 1.0f;
        top = 136;
        left = (i * 40 + 45);
        var_s6 = (i * 10 + 60);

        if (D_i3_80141B88[index] < var_s6) {
            temp_v0 = (((i * 10) - D_i3_80141B88[index]) * 10) + 600;
            left += temp_v0;
            scale += (temp_v0 * 0.03f);
        }

        if (D_i3_80141B88[index] == var_s6) {
            switch (i) {
                case 0:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x18);
                    }
                    break;
                case 1:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x19);
                    }
                    break;
                case 2:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x1A);
                    }
                    break;
                case 3:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x1B);
                    }
                    break;
                case 4:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x1C);
                    }
                    break;
                case 5:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x1D);
                    }
                    break;
            }
        }

        if (left < 0x140) {
            gDPPipeSync(gfx++);
            character = D_800E5F40[i]->character;
            gDPLoadTextureBlock(gfx++, sCharacterPortraitTextures[character], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * scale) << 2,
                                    (s32) (top + 32.0f * scale) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                    (s32) (1024.0f / scale));

            if ((D_800E5F40[i]->unk_00 == 0) && ((gGameFrameCount % 20) >= 5)) {
                gDPPipeSync(gfx++);
                gDPLoadTextureBlock(gfx++, D_401A120, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * scale) << 2,
                                        (s32) (top + 32.0f * scale) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                        (s32) (1024.0f / scale));
            }
        }
    }
    return gfx;
}

Gfx* func_i3_8011F560(Gfx* gfx, s32 arg1, s32 character, s32 left, s32 top, f32 arg5) {
    s32 pad;

    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTextureBlock(gfx++, sCharacterPortraitTextures[character], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * arg5) << 2,
                            (s32) (top + 32.0f * arg5) << 2, 0, 0, 0, (s32) (1024.0f / arg5), (s32) (1024.0f / arg5));

    if ((arg1 == 0) && ((gGameFrameCount % 20) >= 5)) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, D_401A120, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * arg5) << 2,
                                (s32) (top + 32.0f * arg5) << 2, 0, 0, 0, (s32) (1024.0f / arg5),
                                (s32) (1024.0f / arg5));
    }
    return gfx;
}

Gfx* func_i3_8011FAE4(Gfx* gfx) {

    gfx = func_i3_8011ECF0(gfx);
    D_i3_80141BA0 = 196;
    D_i3_80141BA4 = 16;
    D_i3_80141BA8 = 24;
    D_i3_80141BAC = 30;
    D_i3_80141BB0 = 30;
    D_i3_80141BB4 = 10;
    D_i3_80141BB8 = 10;
    return func_i3_8011DD30(gfx, 0);
}

Gfx* func_i3_DrawLoser(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;

    gSPDisplayList(gfx++, D_8014940);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTLUT_pal256(gfx++, sLoserPalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 3; i++) {

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, sLoserTexture + ALIGN_2(i * 0x320), G_IM_FMT_CI, G_IM_SIZ_8b, 80, 10, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + (i * 10) * scale) << 2,
                                (s32) (left + 80.0f * scale) << 2, (s32) (top + ((i + 1) * 10) * scale) << 2, 0, 0, 0,
                                (s32) (1024.0f / scale), (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return gfx;
}

Gfx* func_i3_DrawWinner(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;

    gSPDisplayList(gfx++, D_8014940);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTLUT_pal256(gfx++, sWinnerPalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 4; i++) {

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, sWinnerTexture + ALIGN_2(i * 0x400), G_IM_FMT_CI, G_IM_SIZ_8b, 128, 8, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + (i * 8) * scale) << 2,
                                (s32) (left + 128.0f * scale) << 2, (s32) (top + ((i + 1) * 8) * scale) << 2, 0, 0, 0,
                                (s32) (1024.0f / scale), (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return gfx;
}

Gfx* func_i3_8012040C(Gfx* gfx, s32 arg1) {
    s32 i;
    s32 j;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    s32 spA8;
    s32 var_a1;
    s32 winnerLeft;
    s32 winnerTop;
    f32 scale;
    f32 temp_fv0;
    s32 temp;
    s32 pad[2];
    f32 sp84;
    f32 sp80;
    s32 sp60[8];

    if (gRacers[arg1].unk_2AC == 1) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }

    switch (gNumPlayers) {
        case 1:
            spAC = 100;
            spB4 = 100;
            spB0 = 100;
            spA8 = 170;
            sp84 = 1.0f;
            sp80 = 1.0f;
            break;
        case 2:
            sp84 = 1.0f;
            sp80 = 0.6f;
            spB4 = 100;
            spAC = 210;
            switch (arg1) {
                case 0:
                    spB0 = 43;
                    spA8 = 21;
                    break;
                case 1:
                    spA8 = 133;
                    spB0 = 0x9B;
                    break;
                case 2:
                case 3:
                    var_a1 = 0;
                    D_80141D70 = 1;
                    break;
            }
            break;
        case 3:
            sp84 = 0.75f;
            sp80 = 0.4f;
            switch (arg1) {
                case 0:
                    spB4 = 43;
                    spB0 = 43;
                    break;
                case 1:
                    spB0 = 0x9B;
                    spB4 = 43;
                    break;
                case 2:
                    spB0 = 43;
                    spB4 = 0xB7;
                    break;
                case 3:
                    var_a1 = 0;
                    D_80141D70 = 1;
                    break;
            }
            spA8 = spB0 - 0x14;
            spAC = spB4 + 0x36;
            break;
        case 4:
            sp84 = 0.75f;
            sp80 = 0.4f;
            switch (arg1) {
                case 0:
                    spB4 = 43;
                    spB0 = 43;
                    break;
                case 1:
                    spB4 = 43;
                    spB0 = 0x9B;
                    break;
                case 2:
                    spB4 = 0xB7;
                    spB0 = 43;
                    break;
                case 3:
                    spB4 = 0xB7;
                    spB0 = 0x9B;
                    break;
            }
            spA8 = spB0 - 0x14;
            spAC = spB4 + 0x36;
            break;
    }
    if (var_a1 == 1) {
        if (D_i3_80141BE0[arg1] < 0x3D) {
            winnerLeft = spB4;
            winnerTop = spB0;
            scale = sp84;
        } else if (D_i3_80141BE0[arg1] >= 0x46) {
            winnerLeft = spAC;
            winnerTop = spA8;
            scale = sp80;
        } else {
            temp_fv0 = D_i3_80141BE0[arg1] - 60;
            winnerLeft = (spB4 + (((spAC - spB4) / 10.0f) * temp_fv0));
            winnerTop = (spB0 + (((spA8 - spB0) / 10.0f) * temp_fv0));
            scale = (((sp80 - sp84) / 10.0f) * temp_fv0) + sp84;
        }
        if ((D_i3_80141BE0[arg1] >= 0x3D) || (gGameFrameCount & 4)) {
            gfx = func_i3_DrawWinner(gfx, winnerLeft, winnerTop, scale);
        }
    }

    D_i3_80141BE0[arg1]++;
    if ((gNumPlayers >= 2) && (((D_i3_80141BE0[arg1] == 1)) || (D_i3_80141BE0[arg1] == 0x3C)) && (arg1 < gNumPlayers)) {

        for (i = 0; i < D_800E5EC0; i++) {
            sp60[i] = i;
        }

        for (i = 0; i < D_800E5EC0 - 1; i++) {
            for (j = i + 1; j < D_800E5EC0; j++) {
                if (sp60[i] >= gNumPlayers) {
                    temp = sp60[i];
                    sp60[i] = sp60[j];
                    sp60[j] = temp;
                } else if ((sp60[j] < gNumPlayers) && (gRacers[sp60[j]].unk_2AC < gRacers[sp60[i]].unk_2AC)) {
                    temp = sp60[i];
                    sp60[i] = sp60[j];
                    sp60[j] = temp;
                }
            }
        }

        if (arg1 == sp60[0]) {
            if (D_i3_80141BE0[arg1] == 60) {

                if (gRacers[arg1].unk_04 & 0x08000000) {
                    if (D_800CD010 == 0) {
                        func_800BAFA4(0x13);
                    }
                } else if (D_800CD010 == 0) {
                    func_800BAFA4(0x11);
                }
                for (i = 0; i < gNumPlayers; i++) {
                    if ((gRacers[i].unk_04 & 0x08000000) || (gRacers[arg1].unk_04 & 0x02000000)) {
                        func_800BA3E4(i, 3);
                        func_800BA3E4(i, 4);
                        func_800BA3E4(i, 5);
                        func_800BA3E4(i, 8);
                        func_800BA3E4(i, 9);
                        func_800BA3E4(i, 10);
                        func_800BA3E4(i, 11);
                    }
                }

            } else if (D_800CD010 == 0) {
                func_8007E0CC();
            }
        }
    }
    if (D_i3_80141BE0[arg1] >= 600) {
        D_i3_80141BE0[arg1] = 600;
    }
    return gfx;
}

Gfx* func_i3_801209C8(Gfx* gfx, s32 arg1) {
    s32 i;
    s32 j;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    s32 spA8;
    s32 var_a1;
    s32 loserLeft;
    s32 loserTop;
    f32 scale;
    f32 temp_fv0;
    s32 temp;
    s32 pad[2];
    f32 sp84;
    f32 sp80;

    if (gRacers[arg1].unk_2AC == 1) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }

    switch (gNumPlayers) {
        case 1:
            spB4 = 130;
            spAC = 130;
            spB0 = 100;
            spA8 = 170;
            sp84 = 1.0f;
            sp80 = 1.0f;
            break;
        case 2:
            sp84 = 1.0f;
            sp80 = 0.6f;
            spB4 = 100;
            spAC = 210;
            switch (arg1) {
                case 0:
                    spB0 = 43;
                    spA8 = 21;
                    break;
                case 1:
                    spA8 = 133;
                    spB0 = 155;
                    break;
                case 2:
                case 3:
                    var_a1 = 0;
                    D_80141D70 = 1;
                    break;
            }
            break;
        case 3:
            sp84 = 0.75f;
            sp80 = 0.4f;
            switch (arg1) {
                case 0:
                    spB4 = 43;
                    spB0 = 43;
                    break;
                case 1:
                    spB0 = 155;
                    spB4 = 43;
                    break;
                case 2:
                    spB0 = 43;
                    spB4 = 183;
                    break;
                case 3:
                    var_a1 = 0;
                    D_80141D70 = 1;
                    break;
            }
            spA8 = spB0 - 0x14;
            spAC = spB4 + 0x36;
            break;
        case 4:
            sp84 = 0.75f;
            sp80 = 0.4f;
            switch (arg1) {
                case 0:
                    spB4 = 43;
                    spB0 = 43;
                    break;
                case 1:
                    spB4 = 43;
                    spB0 = 155;
                    break;
                case 2:
                    spB4 = 183;
                    spB0 = 43;
                    break;
                case 3:
                    spB4 = 183;
                    spB0 = 155;
                    break;
            }
            spA8 = spB0 - 20;
            spAC = spB4 + 54;
            break;
    }
    if (var_a1 == 1) {
        if (D_i3_80141BE0[arg1] < 0x3D) {
            loserLeft = spB4;
            loserTop = spB0;
            scale = sp84;
        } else if (D_i3_80141BE0[arg1] >= 0x46) {
            loserLeft = spAC;
            loserTop = spA8;
            scale = sp80;
        } else {
            temp_fv0 = D_i3_80141BE0[arg1] - 60;
            loserLeft = (spB4 + (((spAC - spB4) / 10.0f) * temp_fv0));
            loserTop = (spB0 + (((spA8 - spB0) / 10.0f) * temp_fv0));
            scale = (((sp80 - sp84) / 10.0f) * temp_fv0) + sp84;
        }
        if ((D_i3_80141BE0[arg1] >= 0x3D) || (gGameFrameCount & 4)) {
            gfx = func_i3_DrawLoser(gfx, loserLeft, loserTop, scale);
        }
    }

    D_i3_80141BE0[arg1]++;

    if (D_i3_80141BE0[arg1] >= 600) {
        D_i3_80141BE0[arg1] = 600;
    }
    return gfx;
}

extern u8 D_400ECE8[];
extern u8 D_400F4E8[];

Gfx* func_i3_80120D28(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;

    gSPDisplayList(gfx++, D_8014940);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gDPLoadTLUT_pal256(gfx++, D_400F4E8);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 1; i++) {

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, (D_400ECE8 + (i * 0x800)), G_IM_FMT_CI, G_IM_SIZ_8b, 128, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + (i * 16) * scale) << 2,
                                (s32) (left + 128.0f * scale) << 2, (s32) (top + ((i + 1) * 16) * scale) << 2, 0, 0, 0,
                                (s32) (1024.0f / scale), (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

Gfx* func_i3_80121178(Gfx* gfx, s32 arg1) {
    s32 left;
    s32 top;
    s32 pad;
    f32 scale;

    switch (gNumPlayers) {
        case 1:
            left = 100;
            top = 88;
            scale = 1.0f;
            break;
        case 2:
            scale = 1.0f;
            left = 100;
            switch (arg1) {
                case 0:
                    top = 35;
                    break;
                case 1:
                    top = 147;
                    break;
            }
            break;
        case 3:
        case 4:
            scale = 0.75f;
            switch (arg1) {
                case 0:
                    left = 43;
                    top = 56;
                    break;
                case 1:
                    left = 43;
                    top = 168;
                    break;
                case 2:
                    left = 183;
                    top = 56;
                    break;
                case 3:
                    left = 183;
                    top = 168;
                    break;
            }
            break;
    }
    return func_i3_80120D28(gfx, left, top, scale);
}

extern u8 D_400F508[];
extern u8 D_400FA08[];

Gfx* func_i3_801212A8(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;
    f32 blockTop;
    f32 temp;
    s32 pad[2];

    gSPDisplayList(gfx++, D_8014940);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gDPLoadTLUT_pal256(gfx++, D_400FA08);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    blockTop = top;

    for (i = 0; i < 2; i++) {

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, (D_400F508 + (i * 0x280)), G_IM_FMT_CI, G_IM_SIZ_8b, 80, 8, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        temp = (8.0f * scale);
        gSPScisTextureRectangle(gfx++, left << 2, (s32) (blockTop) << 2, (s32) (left + 80.0f * scale) << 2,
                                (s32) (blockTop + temp) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                (s32) (1024.0f / scale));
        blockTop += temp;
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

Gfx* func_i3_801216C0(Gfx* gfx, s32 arg1) {
    s32 left;
    s32 top;
    s32 pad;
    f32 scale;

    switch (gNumPlayers) {
        case 1:
            left = 120;
            top = 90;
            scale = 1.0f;
            break;
        case 2:
            scale = 1.0f;
            left = 120;
            switch (arg1) {
                case 0:
                    top = 37;
                    break;
                case 1:
                    top = 149;
                    break;
            }
            break;
        case 3:
        case 4:
            scale = 1.0f;
            switch (arg1) {
                case 0:
                    left = 43;
                    top = 56;
                    break;
                case 1:
                    left = 43;
                    top = 168;
                    break;
                case 2:
                    left = 193;
                    top = 56;
                    break;
                case 3:
                    left = 193;
                    top = 168;
                    break;
            }
            break;
    }
    return func_i3_801212A8(gfx, left, top, scale);
}

void func_i3_801217F0(s32 arg0) {
    D_i3_80141C00[arg0] = gRacers[arg0].unk_98 * 0.05f;
    D_i3_80141C10[arg0] = 0.0f;
    D_i3_80141D78[arg0] = 0;
    D_i3_80141BF0[arg0] = 0;
}

extern GfxPool D_1000000;
extern Gfx D_400A258[];
extern Gfx D_400FC08[];
extern unk_struct_1DC D_800E5220[];
extern f32 D_800DD230[];
extern GfxPool* D_800DCCF0;
#ifdef NON_MATCHING
// 0 vs 0.0f -> zero loading float regalloc
Gfx* func_i3_80121860(Gfx* gfx, s32 arg1) {
    s32 pad[6];
    s32 i;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fa1;
    f32 spB0;
    f32 spAC;
    f32 temp;
    f32 spA4;
    f32 spA0;
    f32 temp_fv0_2;
    s32 index;

    temp_fv0 = D_800E5220[arg1].unk_5C.x.x;
    temp_fv1 = D_800E5220[arg1].unk_5C.x.y;
    temp_fa1 = D_800E5220[arg1].unk_5C.x.z;
    sqrtf(SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa1));

    if (D_i3_80141BF0[arg1] < 0xB) {
        spC0 = 0;
        spC4 = 0;
        spC8 = 180.0f;
    } else if (D_i3_80141BF0[arg1] >= 0x1E) {
        spC0 = 0;
        spC4 = -40.0f;
        spC8 = 40.0f + 180.0f;
    } else {
        temp_fv0_2 = D_i3_80141BF0[arg1] - 0xA;
        spC0 = temp_fv0_2 * 0;
        spC4 = temp_fv0_2 * -2;
        spC8 = (temp_fv0_2 * 2) + 180.0f;
    }

    D_i3_80141C10[arg1] += D_i3_80141C00[arg1];
    D_i3_80141C00[arg1] *= 0.92f;
    if (D_i3_80141C00[arg1] < 0.08f) {
        D_i3_80141C00[arg1] = 0.08f;
    }
    while (D_i3_80141C10[arg1] < 0.0f) {
        D_i3_80141C10[arg1] += 2 * M_PI;
    }
    while (D_i3_80141C10[arg1] > 2 * M_PI) {
        D_i3_80141C10[arg1] -= 2 * M_PI;
    }
    if ((D_i3_80141C00[arg1] <= 0.08f) && (D_i3_80141C10[arg1] >= (1.84f * M_PI))) {
        D_i3_80141C10[arg1] = (1.84f * M_PI);
        D_i3_80141C00[arg1] = 0.0f;
    }
    temp = D_i3_80141C10[arg1] * 4096.0f;
    index = temp / (2 * D_PI);
    spA0 = D_800DD230[index & 0xFFF];
    spA4 = -D_800DD230[(index + 0x400) & 0xFFF];
    spAC = D_800DD230[(index + 0x400) & 0xFFF];
    spB0 = D_800DD230[index & 0xFFF];

    gfx = func_i3_8012EE90(gfx, arg1);

    gSPMatrix(gfx++, &D_1000000.unk_20008[arg1], G_MTX_PUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_20108[arg1], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_400A258);
    gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BACK);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    func_8006BC84(D_800DCCF0->unk_21988, NULL, 0.07f, 0.07f, 0.07f, 0.0f, spA0, spA4, 0.0f, spAC, spB0, spC0, spC4,
                  spC8);
    gSPMatrix(gfx++, D_800DCCF0->unk_21988, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_400FC08);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);

    D_i3_80141BE0[arg1]++;
    if (D_i3_80141BE0[arg1] == 2) {
        if ((D_800DCE44 == 0xE) || (D_800DCE44 == 1)) {
            if (D_800CD00C == 3) {
                D_i3_801419B0 |= 4;
            }
        } else if (D_800DCE44 == 0x15) {
            D_i3_801419B0 |= 4;
        }
    }

    if (D_i3_80141BE0[arg1] == 60) {
        if (D_800CD010 == 0) {
            func_800BAFA4(0x11);
        }
        for (i = 0; i < gNumPlayers; i++) {
            if ((gRacers[i].unk_04 & 0x08000000) || (gRacers[arg1].unk_04 & 0x02000000)) {
                func_800BA3E4(i, 3);
                func_800BA3E4(i, 4);
                func_800BA3E4(i, 5);
                func_800BA3E4(i, 8);
                func_800BA3E4(i, 9);
                func_800BA3E4(i, 10);
                func_800BA3E4(i, 11);
            }
        }
    }

    if (D_i3_80141C00[arg1] == 0) {
        D_i3_80141BF0[arg1]++;
        if (D_i3_80141BF0[arg1] >= 0x258) {
            D_i3_80141BF0[arg1] = 0x258;
        }
    }
    return gfx;
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i3/AE140/func_i3_80121860.s")
Gfx* func_i3_80121860(Gfx* gfx, s32 arg1);
#endif

void func_i3_80121E28(s32 arg0) {
    D_i3_80141C00[arg0] = 0.25f;
    D_i3_80141BF0[arg0] = 0;
    D_i3_80141C10[arg0] = 0.0f;
    D_i3_80141D0C = 0.001f;
}

extern Gfx D_400C9C0[];

// TODO: figure out calculation from D_PI and M_PI which gives correct rodata values
#define D_TWO_PI 6.283185958862305
#define M_TWO_PI 6.283186f

Gfx* func_i3_80121E70(Gfx* gfx, s32 arg1) {
    s32 pad[7];
    f32 sp88;
    f32 sp84;
    f32 sp80;
    s32 row;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 index;
    s32 alpha;
    f32 sp64;
    f32 temp_fv0_2;
    f32 sp5C;

    temp_fv0 = D_800E5220[arg1].unk_5C.x.x;
    temp_fv1 = D_800E5220[arg1].unk_5C.x.y;
    temp_fa1 = D_800E5220[arg1].unk_5C.x.z;
    sqrtf(SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa1));
    if ((gNumPlayers == 1) && (D_i3_80141C00[arg1] <= 0.02f)) {
        D_800DCE98[gGameFrameCount % 4].unk_78 = 1;
        D_i3_80141BC0[0] += 2;
        if (D_i3_80141BC0[0] == 250) {
            func_800BB038();
            func_800BB048();
        }
        if (D_i3_80141BC0[0] > 1000) {
            D_i3_80141BC0[0] = 1000;
        }
        gSPDisplayList(gfx++, D_8014940);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);

        for (row = 16; row < 224; row++) {
            alpha = (row - 124);
            if (row < 124) {
                alpha = -alpha;
            }
            alpha = (D_i3_80141BC0[0] + alpha) - 150;
            if (alpha < 0) {
                alpha = 0;
            }
            if (alpha > 255) {
                alpha = 255;
            }
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, alpha);
            gSPTextureRectangle(gfx++, 12 << 2, row << 2, 308 << 2, (row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }

    if (gRacers[arg1].unk_04 & 0x02000000) {
        if (D_i3_80141BF0[arg1] <= 10) {
            sp80 = 0;
            sp84 = 0.f;
            sp88 = 20.0f;
        } else if (D_i3_80141BF0[arg1] >= 30) {
            sp80 = 0;
            sp84 = 20.0f * -0.15f;
            sp88 = 20.0f;
        } else {
            temp_fv0_2 = D_i3_80141BF0[arg1] - 10;
            sp80 = temp_fv0_2 * 0;
            sp84 = temp_fv0_2 * -0.15f;
            sp88 = sp80 + 20.0f;
        }
    } else {
        sp80 = 0;
        sp84 = 0;
        sp88 = 20.0f;
    }

    D_i3_80141C10[arg1] += D_i3_80141C00[arg1];
    D_i3_80141C00[arg1] *= 0.99f;
    if (D_i3_80141C00[arg1] < 0.02f) {
        D_i3_80141C00[arg1] = 0.02f;
    }
    if ((D_i3_80141C00[arg1] <= 0.02f) && (D_i3_80141C10[arg1] >= M_TWO_PI)) {
        D_i3_80141C10[arg1] = M_TWO_PI;
        D_i3_80141C00[arg1] = 0.0f;
    }

    if (D_i3_80141C00[arg1] == 0.0f) {
        D_i3_80141BF0[arg1]++;
        if (D_i3_80141BF0[arg1] >= 600) {
            D_i3_80141BF0[arg1] = 600;
        }
    }
    while (D_i3_80141C10[arg1] < 0.0f) {
        D_i3_80141C10[arg1] += M_TWO_PI;
    }
    while (D_i3_80141C10[arg1] > M_TWO_PI) {
        D_i3_80141C10[arg1] -= M_TWO_PI;
    }

    index = (D_i3_80141C10[arg1] * 4096.0f) / D_TWO_PI;

    sp5C = D_800DD230[index & 0xFFF];
    sp64 = -D_800DD230[(index + 0x400) & 0xFFF];
    gfx = func_i3_8012EE90(gfx, arg1);
    gSPMatrix(gfx++, &D_1000000.unk_20008[arg1], G_MTX_PUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_20108[arg1], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_400A258);

    D_i3_80141D0C += 0.00005f;
    if (D_i3_80141D0C >= 0.009f) {
        D_i3_80141D0C = 0.009f;
        if ((D_800DCE98[D_800DD218[arg1]].unk_7C & (BTN_A | BTN_START)) && (D_i3_80141BF0[arg1] >= 60) &&
            (D_i3_801419A2 == 0)) {
            if (D_800CD010 == 0) {
                func_800BB048();
            }
            if (D_800CD010 == 0) {
                func_8007E0CC();
            }
            D_i3_801419A2 = 1;
            D_i3_801419B0 |= 0x10;
        }
    }

    func_8006BC84(D_800DCCF0->unk_21988, NULL, D_i3_80141D0C, D_i3_80141D0C, D_i3_80141D0C, sp5C, 0.0f, sp64, 0.0f,
                  1.0f, 0.0f, sp80, sp84, sp88);
    gSPMatrix(gfx++, D_800DCCF0->unk_21988, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_400C9C0);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);

    D_i3_80141BE0[arg1]++;
    return gfx;
}

Gfx* func_i3_8012266C(Gfx* gfx, s32 arg1) {
    s32 pad;
    s32 left;
    s32 top;

    if (gNumPlayers < 3) {
        switch (arg1) {
            case 0:
                left = 24;
                top = 20;
                break;
            case 1:
                left = 24;
                top = 132;
                break;
        }
    } else {
        switch (arg1) {
            case 0:
                left = 21;
                top = 20;
                break;
            case 1:
                left = 21;
                top = 132;
                break;
            case 2:
                left = 165;
                top = 20;
                break;
            case 3:
                left = 165;
                top = 132;
                break;
        }
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return func_i3_8012F554(gfx, gRacers[arg1].unk_2A0, left, top, 1.0f);
}

Gfx* func_i3_DrawRaceMenuTexture(Gfx* gfx, s32 textureIndex, s32 left, s32 top) {

    if (textureIndex >= 24) {
        return gfx;
    }

    return func_8007E410(gfx, func_800783AC(sRaceMenuTextures[textureIndex]), NULL, G_IM_FMT_CI, 1, left, top,
                         sRaceMenuDimensions[textureIndex * 2 + 0], sRaceMenuDimensions[textureIndex * 2 + 1], 2);
}

s32 func_i3_801228F8(s32 playerNum, s32 highlightedOption, s32 maxOptionValue) {
    s32 var_v0 = 0;
    s32 stickY = D_800DCE98[D_800DD218[playerNum]].stickY;

    if (stickY > 50) {
        var_v0 = -1;
        D_i3_80141D90++;
    } else if (stickY < -50) {
        var_v0 = 1;
        D_i3_80141D90++;
    } else {
        if (D_800DCE98[D_800DD218[playerNum]].unk_7C & BTN_UP) {
            var_v0 = -1;
            D_i3_80141D90 = 1;
        } else if (D_800DCE98[D_800DD218[playerNum]].unk_7C & BTN_DOWN) {
            var_v0 = 1;
            D_i3_80141D90 = 1;
        } else {
            D_i3_80141D90 = 0;
        }
    }

    if ((D_i3_80141D90 == 1) || (D_i3_80141D90 == 60)) {
        highlightedOption += var_v0;
        if (highlightedOption == -1) {
            highlightedOption = maxOptionValue;
        }
        if (highlightedOption == (maxOptionValue + 1)) {
            highlightedOption = 0;
        }
        if (D_800CD010 == 0) {
            func_800BA8D8(0x1E);
        }
    }
    if (D_i3_80141D90 >= 0x4B) {
        D_i3_80141D90 = 0x3B;
    }

    Math_Rand1();
    Math_Rand2();
    return highlightedOption;
}

s32 func_i3_80122A6C(s32 playerNum, s32 highlightedOption, s32 maxOptionValue) {
    s32 var_v0 = 0;
    s32 stickX = D_800DCE98[D_800DD218[playerNum]].stickX;

    if (stickX > 50) {
        var_v0 = -1;
        D_i3_80141D90++;
    } else if (stickX < -50) {
        var_v0 = 1;
        D_i3_80141D90++;
    } else {
        if (D_800DCE98[D_800DD218[playerNum]].unk_7C & BTN_LEFT) {
            var_v0 = -1;
            D_i3_80141D90 = 1;
        } else if (D_800DCE98[D_800DD218[playerNum]].unk_7C & BTN_RIGHT) {
            var_v0 = 1;
            D_i3_80141D90 = 1;
        } else {
            D_i3_80141D90 = 0;
        }
    }

    if ((D_i3_80141D90 == 1) || (D_i3_80141D90 == 60)) {
        highlightedOption += var_v0;
        if (highlightedOption == -1) {
            highlightedOption = maxOptionValue;
        }
        if (highlightedOption == (maxOptionValue + 1)) {
            highlightedOption = 0;
        }
        if (D_800CD010 == 0) {
            func_800BA8D8(0x1E);
        }
    }
    if (D_i3_80141D90 >= 0x4B) {
        D_i3_80141D90 = 0x3B;
    }

    Math_Rand1();
    Math_Rand2();
    return highlightedOption;
}

Gfx* func_i3_SetOptionColor(Gfx* gfx, s32 arg1) {

    gDPPipeSync(gfx++);

    if (arg1 == 0) {
        gfx = func_8007DB28(gfx, 0);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    return gfx;
}

extern unk_800E5FF8 D_800E5FF8[];
extern unk_800E5FF8* D_800F1E78;

void func_i3_80122C3C(void) {

    if (D_800F5E90 == NULL) {
        D_i3_80141C84 = -1;
        D_80141C78 = MAX_TIMER;
    } else {
        D_i3_80141C84 = D_800F5E90->unk_04 - D_800E5FF8;
        D_80141C78 = D_800F5E90->unk_04->unk_0004;
    }
    if (D_800F1E78 == NULL) {
        D_i3_80141C80 = -1;
        return;
    }
    D_i3_80141C80 = D_800F1E78 - D_800E5FF8;
    D_i3_80141C7C = D_800F1E78->unk_0004;
}

void func_i2_80101690(s32, unk_800E5FF8*);

s32 func_i3_80122CEC(void) {
    func_i3_80122C3C();
    if (D_i3_80141C80 == -1) {
        sCannotSaveGhost = true;
        sSaveGhostMenuOpen = false;
        return -1;
    }
    if (func_i2_801014D4(&D_i3_80141C88) != 0) {
        if (D_800F8514 < 0x18) {
            func_i2_80101690(D_800F8514, D_800F1E78);
        }
        sSaveGhostMenuOpen = false;
        sGhostSaveTimer = 60;
        return 0;
    }
    return 0;
}

s32 func_i3_80122D88(void) {
    sCannotSaveGhost = false;
    if (D_800F8514 >= 0x30) {
        sCannotSaveGhost = true;
        return 0;
    }
    func_i3_80122C3C();
    if (D_i3_80141C80 == -1) {
        sCannotSaveGhost = true;
        sSaveGhostMenuOpen = false;
        return -1;
    }
    if (func_i2_801014D4(&D_i3_80141C88) != 0) {
        return 0;
    }
    if ((D_i3_80141C88.unk_00 == D_800F8514) && (D_i3_80141C7C >= D_i3_80141C88.unk_08)) {
        sCannotSaveGhost = true;
    }
    return 0;
}

extern Gfx D_4011D78[];

Gfx* func_i3_DrawSaved(Gfx* gfx) {

    if (sGhostSaveTimer > 0) {
        sGhostSaveTimer--;
    } else {
        sGhostSaveTimer = 0;
    }

    if (sGhostSaveTimer == 1) {
        sCannotSaveGhost = true;
        sRaceMenuOptionIndex = 0;
        D_i3_80141DCC = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 85, 105, 165, 135);

    gfx = func_i3_DrawBeveledBox(gfx, 90, 110, 160, 130, 0, 0, 0, 255);
    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SAVED, 93, 112);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    D_i3_80141DCC = 0;
    return gfx;
}

Gfx* func_i3_DrawSaving(Gfx* gfx) {

    if (sGhostSaveTimer == 1) {
        sRaceMenuOptionIndex = 0;
        D_i3_80141DCC = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 80, 105, 170, 135);

    gfx = func_i3_DrawBeveledBox(gfx, 90, 110, 160, 130, 0, 0, 0, 255);
    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SAVING, 95, 112);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    D_i3_80141DCC = 0;
    return gfx;
}

extern char* D_800E4178;
extern char* D_800E4180[];

Gfx* func_i3_DrawGhostSave(Gfx* gfx) {
    s32 pad[7];

    if (D_i3_80141DB4 > 0) {
        D_i3_80141DB4 -= 8;
    } else {
        D_i3_80141DB4 = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_80141DB4 + 20, D_i3_80141DB4 + 40, 210 - D_i3_80141DB4,
                  226 - D_i3_80141DB4);

    gfx = func_i3_DrawBeveledBox(gfx, 25, 45, 205, 221, 0, 0, 0, 255);
    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gfx = func_i3_8012F554(gfx, D_i3_80141C7C, 115, 77, 1.0f);
    gfx = func_i3_8012F554(gfx, D_i3_80141C88.unk_08, 115, 141, 1.0f);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = func_i2_80106450(gfx, 124 - (func_i2_801062E4(D_800E4178, 6, 1) / 2), 78, D_800E4178, 1, 6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_i2_80106450(gfx, 123 - (func_i2_801062E4(D_800E4178, 6, 1) / 2), 77, D_800E4178, 1, 6, 0);

    if ((D_i3_80141C88.unk_00 >= 0) && (D_i3_80141C88.unk_00 < 24)) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
        gfx = func_i2_80106450(gfx, 124 - (func_i2_801062E4(D_800E4180[D_i3_80141C88.unk_00], 6, 1) / 2), 142,
                               D_800E4180[D_i3_80141C88.unk_00], 1, 6, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = func_i2_80106450(gfx, 123 - (func_i2_801062E4(D_800E4180[D_i3_80141C88.unk_00], 6, 1) / 2), 141,
                               D_800E4180[D_i3_80141C88.unk_00], 1, 6, 0);
    } else {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
        gfx = func_i2_80106450(gfx, 124 - (func_i2_801062E4(D_i3_80141C88.unk_14, 6, 1) / 2), 142, D_i3_80141C88.unk_14,
                               1, 6, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = func_i2_80106450(gfx, 123 - (func_i2_801062E4(D_i3_80141C88.unk_14, 6, 1) / 2), 141, D_i3_80141C88.unk_14,
                               1, 6, 0);
    }

    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_NEW_GHOST, 43, 45);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SAVED_GHOST, 11, 109);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_OVERWRITE_DATA1, 21, 171);
    gfx = func_8007DB28(gfx, 0);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_LEFT_ARROW, 70, 197);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RIGHT_ARROW, 144, 197);
    if (sOverwriteGhostOption == 0) {
        gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_NO, 99, 197);
    } else {
        gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_YES, 99, 197);
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    sOverwriteGhostOption = func_i3_80122A6C(0, sOverwriteGhostOption, 1);
    if (D_800DCE98[D_800DD218[0]].unk_7C & (BTN_A | BTN_START)) {
        if (sOverwriteGhostOption == 0) {
            if (D_800CD010 == 0) {
                func_800BA8D8(0x10);
            }
            sSaveGhostMenuOpen = false;
        } else {
            if (D_800CD010 == 0) {
                func_800BA8D8(0x21);
            }
            func_i2_80101690(D_800F8514, D_800F1E78);
            sSaveGhostMenuOpen = false;
            sGhostSaveTimer = 60;
        }
    }
    if (D_800DCE98[D_800DD218[0]].unk_7C & BTN_B) {
        if (D_800CD010 == 0) {
            func_800BA8D8(0x10);
        }
        sSaveGhostMenuOpen = false;
        sRaceMenuOptionIndex = 0;
        D_i3_80141DCC = 0;
    }
    return gfx;
}

Gfx* func_i3_801239D0(Gfx* gfx) {

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);

    gfx = func_i3_DrawBeveledBox(gfx, 20, 56, 140, 86, 0, 0, 0, 180);
    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));
    gfx = func_8007DB28(gfx, 0);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CANNOT_SAVE_GHOST, 16, 54);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return gfx;
}

Gfx* func_i3_DrawTimeAttackFinishMenu(Gfx* gfx) {
    bool sp4C;

    sp4C = false;
    if (D_i3_80141D98 > 0) {
        D_i3_80141D98--;
    } else {
        D_i3_80141D98 = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_80141D98 + 205, D_i3_80141D98 + 132, 305 - D_i3_80141D98,
                  225 - D_i3_80141D98);
    gfx = func_i3_DrawBeveledBox(gfx, 210, 137, 300, 220, 0, 0, 0, 180);
    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - TIME_ATTACK_RETRY);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 230, 140);
    if (!sCannotSaveGhost) {
        gfx = func_i3_SetOptionColor(gfx, (sRaceMenuOptionIndex - TIME_ATTACK_SAVE_GHOST) | sSaveGhostMenuOpen |
                                              sGhostSaveTimer);
    } else {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    }
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_GHOST_SAVE, 230, 152);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - TIME_ATTACK_SETTINGS);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 230, 164);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - TIME_ATTACK_CHANGE_MACHINE);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 230, 176);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - TIME_ATTACK_CHANGE_COURSE);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_COURSE, 230, 188);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - TIME_ATTACK_QUIT);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 230, 200);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPPipeSync(gfx++);
    gfx = func_i3_SetOptionColor(gfx, sSaveGhostMenuOpen + sGhostSaveTimer);
    gfx = func_i2_80106700(gfx, 215, (sRaceMenuOptionIndex * 12) + 157, "Ｍ", 1, 5, 0, 0.8f, 0.8f);

    if (sSaveGhostMenuOpen) {
        gfx = func_i3_DrawGhostSave(gfx);
        sp4C = true;
    } else {
        D_i3_80141DC0 = D_i3_80141DB4 = 90;
        D_i3_80141DBC = D_i3_80141DC4 = sOverwriteGhostOption = 0;
    }
    if (sGhostSaveTimer != 0) {
        if ((D_i3_80141DCC == 0) || (D_i3_80141DCC == 1)) {
            gfx = func_i3_DrawSaved(gfx);
        } else if (D_i3_80141DCC == 2) {
            gfx = func_i3_DrawSaving(gfx);
            sGhostSaveTimer--;
        }
    }
    if ((D_i3_80141D98 == 0) && !sSaveGhostMenuOpen && (D_i3_80141DB4 != 0) && (sGhostSaveTimer == 0) &&
        (D_i3_80141DCC == 0) && !sp4C) {
        if (D_i3_801419A2 == 0) {
            sRaceMenuOptionIndex = func_i3_801228F8(0, sRaceMenuOptionIndex, 5);
            // Skip over save ghost option when greyed out
            if ((sRaceMenuOptionIndex == TIME_ATTACK_SAVE_GHOST) && (sCannotSaveGhost)) {
                if ((D_800DCE98[D_800DD218[0]].stickY > 40) || (D_800DCE98[D_800DD218[0]].unk_7C & BTN_UP)) {
                    sRaceMenuOptionIndex--;
                } else {
                    sRaceMenuOptionIndex++;
                }
            }
        }
        if ((D_800DCE98[D_800DD218[0]].unk_7C & (BTN_A | BTN_START)) && (D_i3_801419A2 == 0) && (D_i3_80141DCC == 0)) {
            switch (sRaceMenuOptionIndex) {
                case TIME_ATTACK_RETRY:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 8;
                    break;
                case TIME_ATTACK_QUIT:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x10;
                    break;
                case TIME_ATTACK_SAVE_GHOST:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    sSaveGhostMenuOpen = true;
                    D_i3_80141DCC = 0;
                    func_i3_80122CEC();
                    break;
                case TIME_ATTACK_SETTINGS:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x80;
                    break;
                case TIME_ATTACK_CHANGE_MACHINE:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x20;
                    break;
                case TIME_ATTACK_CHANGE_COURSE:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x40;
                    break;
            }
        }
    }
    return gfx;
}

Gfx* func_i3_80124370(Gfx* gfx) {

    if (D_i3_80141DA0 > 0) {
        D_i3_80141DA0--;
    } else {
        D_i3_80141DA0 = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_80141DA0 + 205, D_i3_80141DA0 + 132, 305 - D_i3_80141DA0,
                  225 - D_i3_80141DA0);
    gfx = func_i3_DrawBeveledBox(gfx, 210, 137, 300, 220, 0, 0, 0, 180);
    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141D9C);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 230, 140);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141D9C - 1);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 230, 155);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141D9C - 2);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 230, 170);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141D9C - 3);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_COURSE, 230, 185);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141D9C - 4);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 230, 200);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_i3_SetOptionColor(gfx, 0);
    gfx = func_i2_80106700(gfx, 215, (D_i3_80141D9C * 15) + 157, "Ｍ", 1, 5, 0, 0.8f, 0.8f);
    if ((D_i3_80141DA0 == 0) && (D_i3_801419A2 == 0)) {
        D_i3_80141D9C = func_i3_801228F8(0, D_i3_80141D9C, 4);
        if (D_800DCE98[D_800DD218[0]].unk_7C & (BTN_A | BTN_START)) {
            switch (D_i3_80141D9C) {
                case 0:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 8;
                    break;
                case 1:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x80;
                    break;
                case 4:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x10;
                    break;
                case 2:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x20;
                    break;
                case 3:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x40;
                    break;
            }
        }
    }
    return gfx;
}

Gfx* func_i3_8012492C(Gfx* gfx) {

    if (D_i3_80141D98 > 0) {
        D_i3_80141D98--;
    } else {
        D_i3_80141D98 = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_80141D98 + 205, D_i3_80141D98 + 132, 305 - D_i3_80141D98,
                  226 - D_i3_80141D98);
    gfx = func_i3_DrawBeveledBox(gfx, 210, 137, 300, 221, 0, 0, 200, 127);
    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 230, 140);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - 1);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 230, 155);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - 4);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 230, 200);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - 2);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 230, 170);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - 3);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_COURSE, 230, 185);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = func_i2_80106700(gfx, 215, (sRaceMenuOptionIndex * 15) + 157, "Ｍ", 1, 5, 0, 0.8f, 0.8f);
    if ((D_i3_80141D98 == 0) && (D_i3_801419A2 == 0)) {
        sRaceMenuOptionIndex = func_i3_801228F8(0, sRaceMenuOptionIndex, 4);
        if (D_800DCE98[D_800DD218[0]].unk_7C & (BTN_A | BTN_START)) {
            switch (sRaceMenuOptionIndex) {
                case 0:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 8;
                    break;
                case 4:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x10;
                    break;
                case 2:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x20;
                    break;
                case 3:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x40;
                    break;
                case 1:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x80;
                    break;
            }
        }
    }
    return gfx;
}

Gfx* func_i3_80124EEC(Gfx* gfx) {

    if (D_i3_80141D98 > 0) {
        D_i3_80141D98--;
    } else {
        D_i3_80141D98 = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_80141D98 + 205, D_i3_80141D98 + 132, 305 - D_i3_80141D98,
                  210 - D_i3_80141D98);
    if (gRacers[0].unk_04 & 0x02000000) {
        gfx = func_i3_DrawBeveledBox(gfx, 210, 137, 300, 205, 0, 0, 0, 180);
    } else {
        gfx = func_i3_DrawBeveledBox(gfx, 210, 137, 300, 205, 0, 0, 200, 127);
    }
    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 230, 140);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - 1);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 230, 155);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - 3);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 230, 185);
    gfx = func_i3_SetOptionColor(gfx, sRaceMenuOptionIndex - 2);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 230, 170);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = func_i2_80106700(gfx, 215, (sRaceMenuOptionIndex * 15) + 157, "Ｍ", 1, 5, 0, 0.8f, 0.8f);
    if ((D_i3_80141D98 == 0) && (D_i3_801419A2 == 0)) {
        sRaceMenuOptionIndex = func_i3_801228F8(0, sRaceMenuOptionIndex, 3);
        if (D_800DCE98[D_800DD218[0]].unk_7C & (BTN_A | BTN_START)) {
            switch (sRaceMenuOptionIndex) {
                case 0:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 8;
                    break;
                case 3:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x10;
                    break;
                case 2:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x20;
                    break;
                case 1:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x80;
                    break;
            }
        }
    }
    return gfx;
}

Gfx* func_i3_8012548C(Gfx* gfx) {
    s32 pad[2];

    if (D_i3_80141DA8 > 0) {
        D_i3_80141DA8 -= 8;
    } else {
        D_i3_80141DA8 = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_80141DA8 + 100, D_i3_80141DA8 + 41, 230 - D_i3_80141DA8,
                  197 - D_i3_80141DA8);
    gfx = func_i3_DrawBeveledBox(gfx, 120, 61, 210, 177, 0, 0, 0, 220);
    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));

    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CONTINUE, 140, 80);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 1);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 140, 95);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 2);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 140, 110);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 5);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 140, 155);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 3);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 140, 125);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 4);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_COURSE, 140, 140);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = func_i2_80106700(gfx, 125, (D_i3_80141DA4 * 15) + 97, "Ｍ", 1, 5, 0, 0.8f, 0.8f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = func_i2_80106450(gfx, 166 - (func_i2_801062E4("PAUSE", 6, 1) / 2), 78, "PAUSE", 1, 6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_i2_80106450(gfx, 165 - (func_i2_801062E4("PAUSE", 6, 1) / 2), 77, "PAUSE", 1, 6, 0);
    if ((D_i3_80141DA8 == 0) && (D_i3_801419A2 == 0)) {
        D_i3_80141DA4 = func_i3_801228F8(sPausePlayerNum, D_i3_80141DA4, 5);
        if (D_800DCE98[D_800DD218[sPausePlayerNum]].unk_7C & (BTN_A | BTN_START)) {
            switch (D_i3_80141DA4) {
                case 0:
                    D_i3_801419B0 |= 2;
                    break;
                case 1:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0xE);
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 8;
                    break;
                case 5:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0xE);
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x10;
                    break;
                case 3:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0xE);
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x20;
                    break;
                case 4:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0xE);
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x40;
                    break;
                case 2:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0xE);
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x80;
                    break;
            }
        }
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

Gfx* func_i3_80125C34(Gfx* gfx) {
    s32 pad[2];

    if (D_i3_80141DA8 > 0) {
        D_i3_80141DA8 -= 8;
    } else {
        D_i3_80141DA8 = 0;
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_80141DA8 + 100, D_i3_80141DA8 + 56, 230 - D_i3_80141DA8,
                  166 - D_i3_80141DA8);
    gfx = func_i3_DrawBeveledBox(gfx, 120, 61, 210, 161, 0, 0, 0, 220);
    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));

    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CONTINUE, 140, 80);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 1);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 140, 95);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 2);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 140, 110);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 4);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 140, 140);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 3);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 140, 125);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = func_i2_80106700(gfx, 125, (D_i3_80141DA4 * 15) + 97, "Ｍ", 1, 5, 0, 0.8f, 0.8f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = func_i2_80106450(gfx, 166 - (func_i2_801062E4("PAUSE", 6, 1) / 2), 78, "PAUSE", 1, 6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_i2_80106450(gfx, 165 - (func_i2_801062E4("PAUSE", 6, 1) / 2), 77, "PAUSE", 1, 6, 0);
    if ((D_i3_80141DA8 == 0) && (D_i3_801419A2 == 0)) {
        D_i3_80141DA4 = func_i3_801228F8(sPausePlayerNum, D_i3_80141DA4, 4);
        if (D_800DCE98[D_800DD218[sPausePlayerNum]].unk_7C & (BTN_A | BTN_START)) {
            switch (D_i3_80141DA4) {
                case 0:
                    D_i3_801419B0 |= 2;
                    break;
                case 1:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0xE);
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 8;
                    break;
                case 4:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0xE);
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x10;
                    break;
                case 3:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0xE);
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x20;
                    break;
                case 2:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0xE);
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x80;
                    break;
            }
        }
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

void func_i3_801345C8(void);

Gfx* func_i3_80126330(Gfx* gfx) {
    s32 pad[2];

    if (D_i3_80141DA8 > 0) {
        D_i3_80141DA8 -= 8;
    } else {
        D_i3_80141DA8 = 0;
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_80141DA8 + 100, D_i3_80141DA8 + 56, 220 - D_i3_80141DA8,
                  150 - D_i3_80141DA8);
    gfx = func_i3_DrawBeveledBox(gfx, 120, 61, 200, 145, 0, 0, 0, 220);
    gSPDisplayList(gfx++, D_4011D78);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(D_F25F070));

    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CONTINUE, 140, 80);
    if (D_i3_801419B8 <= 0) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    } else {
        gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 1);
    }
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 140, 95);
    gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 3);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 140, 125);
    if (D_i3_801419B8 <= 0) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    } else {
        gfx = func_i3_SetOptionColor(gfx, D_i3_80141DA4 - 2);
    }
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 140, 110);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = func_i2_80106700(gfx, 125, (D_i3_80141DA4 * 15) + 97, "Ｍ", 1, 5, 0, 0.8f, 0.8f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = func_i2_80106450(gfx, 162 - (func_i2_801062E4("PAUSE", 6, 1) / 2), 78, "PAUSE", 1, 6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_i2_80106450(gfx, 161 - (func_i2_801062E4("PAUSE", 6, 1) / 2), 77, "PAUSE", 1, 6, 0);
    if ((D_i3_80141DA8 == 0) && (D_i3_801419A2 == 0)) {
        D_i3_80141DA4 = func_i3_801228F8(sPausePlayerNum, D_i3_80141DA4, 3);
        if (((D_i3_80141DA4 == 1) || (D_i3_80141DA4 == 2)) && (D_i3_801419B8 <= 0)) {
            if ((D_800DCE98[D_800DD218[0]].stickY > 40) || (D_800DCE98[D_800DD218[0]].unk_7C & BTN_UP)) {
                D_i3_80141DA4 = 0;
            } else {
                D_i3_80141DA4 = 3;
            }
        }
        if (D_800DCE98[D_800DD218[sPausePlayerNum]].unk_7C & (BTN_A | BTN_START)) {
            switch (D_i3_80141DA4) {
                case 0:
                    D_i3_801419B0 |= 2;
                    break;
                case 1:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if ((D_800DCE44 == 1) && (gRacers->unk_00 < gNumPlayers)) {
                        D_800E5ED8[gRacers->unk_00]--;
                        if (D_800E5ED8[gRacers->unk_00] >= 0) {
                            func_i3_801345C8();
                        }
                        if (D_800CD010 == 0) {
                            func_800BA8D8(0x2C);
                        }
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 8;
                    break;
                case 3:
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0xE);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x10;
                    break;
                case 2:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if ((D_800DCE44 == 1) && (gRacers->unk_00 < gNumPlayers)) {
                        D_800E5ED8[gRacers->unk_00]--;
                        if (D_800E5ED8[gRacers->unk_00] >= 0) {
                            func_i3_801345C8();
                        }
                        if (D_800CD010 == 0) {
                            func_800BA8D8(0x2C);
                        }
                    }
                    D_i3_801419A2 = 1;
                    D_i3_801419B0 |= 0x80;
                    break;
            }
        }
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

extern s16 D_800E5FE4;
extern u8 D_303AA70[];
extern u8 D_303B270[];
extern u8 D_303C170[];

Gfx* func_i3_80126B40(Gfx* gfx, s32 arg1) {
    s32 i;
    s32 sp108;
    s32 sp104;
    s32 sp100;
    s32 spFC;
    s32 temp_lo;
    s32 spF4;

    switch (gNumPlayers) {
        case 1:
            if (D_800DCE44 == 0xE) {
                sp108 = 0x82;
                sp104 = 0xC0;
            } else {
                sp108 = 0x28;
                sp104 = 0x44;
            }
            break;
        case 2:
            sp108 = 0xDC;
            switch (arg1) {
                case 0:
                    sp104 = 0x5C;
                    break;
                case 1:
                    sp104 = 0xCC;
                    break;
            }
            break;
        case 3:
        case 4:
            switch (arg1) {
                case 0:
                    sp108 = 0x51;
                    sp104 = 0x62;
                    break;
                case 1:
                    sp108 = 0x51;
                    sp104 = 0xD2;
                    break;
                case 2:
                    sp108 = 0xE1;
                    sp104 = 0x62;
                    break;
                case 3:
                    sp108 = 0xE1;
                    sp104 = 0xD2;
                    break;
            }
            break;
    }
    sp104 += D_i3_80141B9C;
    spF4 = 1000;
    spFC = sp100 = Math_Round(gRacers[arg1].unk_9C * 21.6f);

    gDPPipeSync(gfx++);

    if (gNumPlayers == 1) {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    } else {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    }

    gfx = func_i3_8011B41C(gfx, sp108, sp104, sp108 + 71, sp104 + 16, 0, 0, 0, 255);
    gSPDisplayList(gfx++, D_80149D0);
    gDPLoadTextureBlock(gfx++, D_303AA70, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPScisTextureRectangle(gfx++, (sp108 + 2) << 2, (sp104 - 16) << 2, (sp108 + 65) << 2, (sp104 - 1) << 2, 0, 0, 0,
                            1 << 12, 1 << 10);

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);

    if (D_800E5FE4 != 0) {
        gfx = func_8007F090(gfx, 255, 0, 0);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    }
    gDPLoadTextureBlock(gfx++, D_303B270, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 160, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < 4; i++) {
        temp_lo = spFC / spF4;
        if ((i != 3) && (temp_lo == 0) && (sp100 == spFC)) {
            spFC %= spF4;
            spF4 /= 10;
        } else {
            gSPScisTextureRectangle(gfx++, (sp108 + (i * 12)) << 2, sp104 << 2, (sp108 + (i * 12) + 11) << 2,
                                    (sp104 + 15) << 2, 0, 0, (temp_lo * 16) << 5, 1 << 10, 1 << 10);
            spFC %= spF4;
            spF4 /= 10;
        }
    }

    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, D_303C170, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPScisTextureRectangle(gfx++, (sp108 + (i * 12)) << 2, sp104 << 2, (sp108 + (i * 12) + 19) << 2, (sp104 + 15) << 2,
                            0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

Gfx* func_i3_801274EC(Gfx* gfx) {

    D_i3_80141BA0 = 110;
    D_i3_80141BA4 = 45;
    D_i3_80141BA8 = 30;
    D_i3_80141BAC = 35;
    D_i3_80141BB0 = 60;
    D_i3_80141BB4 = 10;
    D_i3_80141BB8 = 10;
    gfx = func_i3_8011DD30(gfx, 0);
    if (D_800E5FE2 != 0) {
        D_i3_801419BC = true;
    }
    return gfx;
}

Gfx* func_i3_8012757C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_ra;
    s32 var_t1;
    s32 var_t2;
    s32 var_t3;
    s32 var_t4;

    temp_ra = func_i2_801062E4(D_800E4178, 3, 1);

    gDPPipeSync(gfx++);

    var_t1 = ((arg1 - (temp_ra / 2)) + arg3) - 7;
    var_t2 = (arg2 + arg3) - 21;
    var_t3 = (((temp_ra / 2) + arg1) - arg3) + 7;
    var_t4 = (arg2 - arg3) + 5;

    if (var_t1 < 12) {
        var_t1 = 12;
    }
    if (var_t2 < 16) {
        var_t2 = 16;
    }
    if (var_t3 > 308) {
        var_t3 = 308;
    }
    if (var_t4 > 224) {
        var_t4 = 224;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, var_t1, var_t2, var_t3, var_t4);

    gfx = func_i3_DrawBeveledBox(gfx, (arg1 - (temp_ra / 2)) - 7, arg2 - 19, (temp_ra / 2) + arg1 + 7, arg2 + 3, 0, 0,
                                 200, 128);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gfx = func_i2_80106450(gfx, (arg1 - (func_i2_801062E4(D_800E4178, 3, 1) / 2)) + 2, arg2 + 2, D_800E4178, 1, 3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_i2_80106450(gfx, arg1 - (func_i2_801062E4(D_800E4178, 3, 1) / 2), arg2, D_800E4178, 1, 3, 0);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

Gfx* func_i3_80127854(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_ra;
    s32 var_t1;
    s32 var_t2;
    s32 var_t3;
    s32 var_t4;

    temp_ra = func_i2_801062E4("TIME ATTACK", 3, 1);

    gDPPipeSync(gfx++);

    var_t1 = ((arg1 - (temp_ra / 2)) + arg3) - 7;
    var_t2 = (arg2 + arg3) - 0x15;
    var_t3 = (((temp_ra / 2) + arg1) - arg3) + 7;
    var_t4 = (arg2 - arg3) + 5;

    if (var_t1 < 12) {
        var_t1 = 12;
    }
    if (var_t2 < 16) {
        var_t2 = 16;
    }
    if (var_t3 > 308) {
        var_t3 = 308;
    }
    if (var_t4 > 224) {
        var_t4 = 224;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, var_t1, var_t2, var_t3, var_t4);

    gfx = func_i3_DrawBeveledBox(gfx, (arg1 - (temp_ra / 2)) - 7, arg2 - 0x13, (temp_ra / 2) + arg1 + 7, arg2 + 3, 0,
                                 150, 0, 200);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gfx = func_i2_80106450(gfx, (arg1 - (func_i2_801062E4("TIME ATTACK", 3, 1) / 2)) + 2, arg2 + 2, "TIME ATTACK", 1, 3,
                           0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_i2_80106450(gfx, arg1 - (func_i2_801062E4("TIME ATTACK", 3, 1) / 2), arg2, "TIME ATTACK", 1, 3, 0);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

Gfx* func_i3_80127B2C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad;
    s32 var_t2;
    s32 var_t3;
    s32 var_t4;
    s32 var_t5;

    gDPPipeSync(gfx++);

    var_t2 = (arg1 + arg3) - 72;
    var_t3 = (arg2 + arg3) - 21;
    var_t4 = (arg1 - arg3) + 72;
    var_t5 = (arg2 - arg3) + 21;

    if (var_t2 < 12) {
        var_t2 = 12;
    }
    if (var_t3 < 16) {
        var_t3 = 16;
    }
    if (var_t4 > 308) {
        var_t4 = 308;
    }
    if (var_t5 > 224) {
        var_t5 = 224;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, var_t2, var_t3, var_t4, var_t5);

    gfx = func_i3_DrawBeveledBox(gfx, arg1 - 72, arg2 - 19, arg1 + 72, arg2 + 19, 180, 0, 0, 150);
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_i3_8012F554(gfx, D_800F8510->unk_20[0], ((s32) (var_t2 + var_t4) / 2) - 60, (s32) (var_t3 + var_t5) / 2,
                           1.0f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);

    gfx = func_i2_80106450(gfx, arg1 - 39, arg2 - 1, "BEST TIME", 1, 6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_i2_80106450(gfx, arg1 - 41, arg2 - 3, "BEST TIME", 1, 6, 0);
    gfx = func_i2_80106450(gfx, arg1 + 19, arg2 + 16, D_800F8510->unk_AC, 1, 1, 0);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

Gfx* func_i3_80127E88(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad;
    s32 var_t2;
    s32 var_t3;
    s32 var_t4;
    s32 var_t5;

    gDPPipeSync(gfx++);

    var_t2 = (arg1 + arg3) - 52;
    var_t3 = (arg2 + arg3) - 21;
    var_t4 = (arg1 - arg3) + 52;
    var_t5 = (arg2 - arg3) + 21;

    if (var_t2 < 12) {
        var_t2 = 12;
    }
    if (var_t3 < 16) {
        var_t3 = 16;
    }
    if (var_t4 > 308) {
        var_t4 = 308;
    }
    if (var_t5 > 224) {
        var_t5 = 224;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, var_t2, var_t3, var_t4, var_t5);

    gfx = func_i3_DrawBeveledBox(gfx, arg1 - 52, arg2 - 19, arg1 + 52, arg2 + 19, 180, 0, 0, 150);
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_i3_8012F554(gfx, D_800F8510->unk_20[0], ((s32) (var_t2 + var_t4) / 2) - 35, (s32) (var_t3 + var_t5) / 2,
                           1.0f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);

    gfx = func_i2_80106450(gfx, arg1 - 39, arg2 - 1, "BEST TIME", 1, 6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_i2_80106450(gfx, arg1 - 41, arg2 - 3, "BEST TIME", 1, 6, 0);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

extern s32 gDifficulty;

const char* sDifficultyNames[] = { "NOVICE", "STANDARD", "EXPERT", "MASTER" };

Gfx* func_i3_801281B4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp3C;
    s32 sp38;
    s32 temp_t0;
    s32 temp_t1;
    s32 var_t2;
    s32 var_t3;
    s32 var_t4;
    s32 var_t5;

    if (D_800DCE44 == 1) {
        sp38 = func_i2_801062E4("GP RACE", 3, 1);
        sp3C = func_i2_801062E4(sDifficultyNames[gDifficulty], 3, 1);
    } else if (D_800DCE44 == 2) {
        sp38 = func_i2_801062E4("PRACTICE", 3, 1);
        sp3C = func_i2_801062E4(sDifficultyNames[gDifficulty], 3, 1);
    } else if (D_800DCE44 == 0x15) {
        sp38 = func_i2_801062E4("DEATH RACE", 3, 1);
        sp3C = 0;
        arg2 += 0x10;
    }

    if (sp3C < sp38) {
        sp3C = sp38;
    }
    gDPPipeSync(gfx++);
    temp_t0 = arg1 - (sp3C / 2);
    temp_t1 = arg1 + (sp3C / 2);

    var_t2 = (temp_t0 + arg3) - 7;
    var_t3 = (arg2 + arg3) - 37;
    var_t4 = (temp_t1 - arg3) + 7;

    if (D_800DCE44 == 21) {
        var_t5 = (arg2 - arg3) - 11;
    } else {
        var_t5 = (arg2 - arg3) + 5;
    }
    if (var_t2 < 12) {
        var_t2 = 12;
    }
    if (var_t3 < 16) {
        var_t3 = 16;
    }
    if (var_t4 > 308) {
        var_t4 = 308;
    }
    if (var_t5 > 224) {
        var_t5 = 224;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, var_t2, var_t3, var_t4, var_t5);

    if (D_800DCE44 == 21) {
        gfx = func_i3_DrawBeveledBox(gfx, temp_t0 - 7, arg2 - 35, temp_t1 + 7, arg2 - 13, 0, 220, 0, 200);
    } else {
        gfx = func_i3_DrawBeveledBox(gfx, temp_t0 - 7, arg2 - 35, temp_t1 + 7, arg2 + 3, 0, 220, 0, 200);
    }

    if (D_800DCE44 == 1) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx =
            func_i2_80106450(gfx, (arg1 - (func_i2_801062E4("GP RACE", 3, 1) / 2)) + 2, arg2 - 14, "GP RACE", 1, 3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = func_i2_80106450(gfx, arg1 - (func_i2_801062E4("GP RACE", 3, 1) / 2), arg2 - 16, "GP RACE", 1, 3, 0);
    } else if (D_800DCE44 == 2) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = func_i2_80106450(gfx, (arg1 - (func_i2_801062E4("PRACTICE", 3, 1) / 2)) + 2, arg2 - 14, "PRACTICE", 1, 3,
                               0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = func_i2_80106450(gfx, arg1 - (func_i2_801062E4("PRACTICE", 3, 1) / 2), arg2 - 16, "PRACTICE", 1, 3, 0);
    } else if (D_800DCE44 == 21) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = func_i2_80106450(gfx, (arg1 - (func_i2_801062E4("DEATH RACE", 3, 1) / 2)) + 2, arg2 - 14, "DEATH RACE", 1,
                               3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx =
            func_i2_80106450(gfx, arg1 - (func_i2_801062E4("DEATH RACE", 3, 1) / 2), arg2 - 16, "DEATH RACE", 1, 3, 0);
    }

    if (D_800DCE44 != 21) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = func_i2_80106450(gfx, (arg1 - (func_i2_801062E4(sDifficultyNames[gDifficulty], 3, 1) / 2)) + 2, arg2 + 2,
                               sDifficultyNames[gDifficulty], 1, 3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = func_i2_80106450(gfx, arg1 - (func_i2_801062E4(sDifficultyNames[gDifficulty], 3, 1) / 2), arg2,
                               sDifficultyNames[gDifficulty], 1, 3, 0);
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

Gfx* func_i3_DrawRetire(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;

    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTLUT_pal256(gfx++, sRetirePalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 2; i++) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, sRetireTexture + ALIGN_2(i * 0x800), G_IM_FMT_CI, G_IM_SIZ_8b, 128, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + (i * 16) * scale) << 2,
                                (s32) (left + 128.0f * scale) << 2, (s32) (top + ((i + 1) * 16) * scale) << 2, 0, 0, 0,
                                (s32) (1024.0f / scale), (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);

    return gfx;
}

void func_i3_80128D8C(void) {
    D_i3_801419B8++;
}

Gfx* func_i3_80128DA4(Gfx* gfx, s32 arg1) {
    s32 row;
    s32 alpha;
    s32 sp84;
    s32 sp80;
    s32 temp_t9;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 pad[2];
    f32 sp58;

    if ((gNumPlayers == 1) && ((D_800DCE44 != 1) || (D_i3_801419B8 > 0)) && (D_i3_80141C30[0] > 120)) {
        D_800DCE98[gGameFrameCount % 4].unk_78 = 1;

        D_i3_80141BC0[0] += 2;
        if (D_i3_80141BC0[0] == 250) {
            func_800BB038();
            func_800BB048();
        }
        if (D_i3_80141BC0[0] > 1000) {
            D_i3_80141BC0[0] = 1000;
        }

        gSPDisplayList(gfx++, D_8014940);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);

        for (row = 16; row < 224; row++) {
            alpha = (row - 120);
            if (row < 120) {
                alpha = -alpha;
            }
            alpha = (D_i3_80141BC0[0] + alpha) - 150;
            if (alpha < 0) {
                alpha = 0;
            }
            if (alpha > 255) {
                alpha = 255;
            }
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, alpha);
            gSPTextureRectangle(gfx++, 12 << 2, row << 2, 308 << 2, (row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }

    switch (gNumPlayers) {
        case 1:
            sp58 = 1.0f;
            sp84 = 0x64;
            sp80 = 0x4C;
            break;
        case 2:
            sp58 = 1.0f;
            sp84 = 0x64;
            switch (arg1) {
                case 0:
                    sp80 = 0x2B;
                    break;
                case 1:
                    sp80 = 0x9B;
                    break;
            }
            break;
        case 3:
        case 4:
            sp58 = 0.5f;
            switch (arg1) {
                case 0:
                    sp84 = 0x37;
                    sp80 = 0x31;
                    break;
                case 1:
                    sp84 = 0x37;
                    sp80 = 0xA1;
                    break;
                case 2:
                    sp84 = 0xCB;
                    sp80 = 0x31;
                    break;
                case 3:
                    sp84 = 0xCB;
                    sp80 = 0xA1;
                    break;
            }
            break;
    }

    temp_t9 = sp84;
    sp84 = D_i3_80141C50[arg1] + sp84;
    D_i3_80141C50[arg1] += D_i3_80141C40[arg1];
    if (D_i3_80141C50[arg1] < 0.0f) {
        sp84 = temp_t9;
        D_i3_80141C50[arg1] = 0.0f;
        D_i3_80141C40[arg1] *= -1.0f;
    }
    D_i3_80141C40[arg1] -= 2.0f;
    D_i3_80141C40[arg1] *= 0.9f;
    switch (gNumPlayers) {
        case 1:
            sp78 = 0xC;
            sp74 = 8;
            sp70 = 0x131;
            sp6C = 0xE8;
            break;
        case 2:
            switch (arg1) {
                case 0:
                    sp78 = 0xC;
                    sp74 = 8;
                    sp70 = 0x131;
                    sp6C = 0x75;
                    break;
                case 1:
                    sp78 = 0xC;
                    sp74 = 0x78;
                    sp70 = 0x131;
                    sp6C = 0xE8;
                    break;
            }
            break;
        case 3:
        case 4:
            switch (arg1) {
                case 0:
                    sp78 = 0xC;
                    sp74 = 8;
                    sp70 = 0x9A;
                    sp6C = 0x75;
                    break;
                case 1:
                    sp78 = 0xC;
                    sp74 = 0x78;
                    sp70 = 0x9A;
                    sp6C = 0xE8;
                    break;
                case 2:
                    sp78 = 0xA0;
                    sp74 = 8;
                    sp70 = 0x131;
                    sp6C = 0x75;
                    break;
                case 3:
                    sp78 = 0xA0;
                    sp74 = 0x78;
                    sp70 = 0x131;
                    sp6C = 0xE8;
                    break;
            }
            break;
    }
    if (sp84 < sp70) {
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sp78, sp74, sp70, sp6C);
        gfx = func_i3_DrawRetire(gfx, sp84, sp80, sp58);
    }
    if (gNumPlayers == 1) {
        if ((D_i3_80141C30[arg1] == 1) && (D_800CD010 == 0)) {
            func_8007E0CC();
        }
        if ((D_i3_80141C30[arg1] == 0x3C) && (D_800CD010 == 0)) {
            func_800BAFA4(0x12);
        }
    }

    D_i3_80141C30[arg1]++;
    if (D_i3_80141C30[arg1] >= 600) {
        D_i3_80141C30[arg1] = 600;
    }
    return gfx;
}

Gfx* func_i3_8012952C(Gfx* gfx, s32 arg1) {
    s32 pad;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;

    sp48 = arg1 + 30;
    sp44 = arg1 + 25;
    sp40 = 290 - arg1;
    sp3C = 220 - arg1;

    gfx = func_i3_DrawBeveledBox(gfx, sp48, sp44, sp40, sp3C, 0, 0, 0, 127 - arg1);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sp48, sp44, sp40, sp3C);

    return gfx;
}

const char* sCharacterNames[] = { "CAPTAIN FALCON", "Dr. STEWART",   "PICO",          "SAMURAI GOROH", "JODY SUMMER",
                                  "MIGHTY GAZELLE", "Mr. EAD",       "BABA",          "OCTOMAN",       "GOMAR&SHIOH",
                                  "KATE ALEN",      "ROGER BUSTER",  "JAMES McCLOUD", "LEON",          "ANTONIO GUSTER",
                                  "BLACK SHADOW",   "MICHAEL CHAIN", "JACK LEVIN",    "SUPER ARROW",   "Mrs. ARROW",
                                  "JOHN TANAKA",    "BEASTMAN",      "ZODA",          "Dr. CLASH",     "SILVER NEELSEN",
                                  "BIO REX",        "DRAQ",          "BILLY",         "THE SKULL",     "BLOOD FALCON" };

Gfx* func_i3_8012963C(Gfx* gfx, s32 arg1, s32 character, s32 arg3, s32 arg4) {
    gfx = func_i3_SetOptionColor(gfx, arg1);
    return func_i2_80106450(gfx, arg3, arg4, sCharacterNames[character], 1, 4, 0);
}

Gfx* func_i3_80129698(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    gfx = func_i3_SetOptionColor(gfx, arg1);
    return func_i2_80106450(gfx, arg2, arg3, "RETIRE", 1, 4, 0);
}

void func_i3_801296E8(s32 num) {
    s32 digitIndex = 0;
    s32 remainingNum;

    if (num > 999) {
        num = 999;
    }
    if (num < 0) {
        num = 0;
    }
    remainingNum = num;

    if (remainingNum >= 100) {
        D_i3_80141E08[digitIndex + 0] = (remainingNum / 100) + '0';
        remainingNum -= (remainingNum / 100) * 100;
        D_i3_80141E08[digitIndex + 1] = D_i3_80141E08[digitIndex + 2] = '0';
        D_i3_80141E08[digitIndex + 3] = '\0';
    }
    if (num >= 100) {
        digitIndex++;
    }
    if (remainingNum >= 10) {
        D_i3_80141E08[digitIndex + 0] = (remainingNum / 10) + '0';
        remainingNum -= (remainingNum / 10) * 10;
        D_i3_80141E08[digitIndex + 1] = '0';
        D_i3_80141E08[digitIndex + 2] = '\0';
    }

    if (num >= 10) {
        digitIndex++;
    }
    D_i3_80141E08[digitIndex + 0] = remainingNum + '0';
    D_i3_80141E08[digitIndex + 1] = '\0';
}

Gfx* func_i3_80129800(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    gfx = func_i3_SetOptionColor(gfx, arg1);
    func_i3_801296E8(arg2);
    return func_i2_80106450(gfx, arg3 - func_i2_801062E4(D_i3_80141E08, 4, 0), arg4, D_i3_80141E08, 0, 4, 0);
}

Gfx* func_i3_80129870(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    gfx = func_i3_SetOptionColor(gfx, arg1);
    return func_i2_80106450(gfx, arg2 - func_i2_801062E4("+     $", 4, 1), arg3, "+     $", 1, 4, 0);
}

Gfx* func_i3_801298DC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    gfx = func_i3_SetOptionColor(gfx, arg1);
    return func_i2_80106450(gfx, arg2 - func_i2_801062E4("    $", 4, 1), arg3, "    $", 1, 4, 0);
}

extern s16 D_800E5FE2;

Gfx* func_i3_80129948(Gfx* gfx) {
    s32 temp_v1;
    f32 oneScalar = 1.0f;
    s32 xl;
    s32 yl;
    s32 pad[5];

    temp_v1 = func_i2_801062E4("death race  results", 3, 1) / 2;
    gfx = func_i3_DrawBeveledBox(gfx, 155 - temp_v1, 25, temp_v1 + 169, 43, 0, 0, 200, 127);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gfx = func_i2_80106450(gfx, 0xA2 - (func_i2_801062E4("death race  results", 3, 1) / 2), 0x2C, "death race  results",
                           1, 3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gfx = func_i2_80106450(gfx, 0xA0 - (func_i2_801062E4("death race  results", 3, 1) / 2), 0x2A, "death race  results",
                           1, 3, 0);
    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTextureBlock(gfx++, D_40131E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    xl = 213;
    yl = 60;
    gSPScisTextureRectangle(gfx++, xl << 2, yl << 2, (s32) (xl + (24 - 1) * oneScalar) << 2,
                            (s32) (yl + (16 - 1) * oneScalar) << 2, 0, 0, 0, (s32) ((1 << 10) / oneScalar),
                            (s32) ((1 << 10) / oneScalar));

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    xl = 213;
    yl = 101;
    gDPLoadTextureBlock(gfx++, func_800783AC(D_F243290), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gfx++, xl << 2, yl << 2, (xl + 16) << 2, (yl + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPDisplayList(gfx++, D_8014940);

    if (D_800E5FE2 == 1) {
        gfx = func_8007F090(gfx, 255, 0, 0);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gfx = func_i3_8012F554(gfx, gRacers[0].unk_2A0, 0xD5, 0x4B, 1.0f);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    return func_i3_8012F554(gfx, D_800F8510->unk_20[0], 0xD5, 0x72, 1.0f);
}

extern s32 D_800E5F00[];
extern s32 D_800E5F10[];
extern s32 D_80115DD0[];

UNUSED s32 D_i3_8013EF40 = 0;

s32 D_i3_8013EF44[][4] = {
    { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 5, 0, 0, 0 }, { 5, 3, 0, 0 }, { 5, 3, 1, 0 },
};

s32 D_i3_8013EF94[] = { 0, 255, 0, 255 };

s32 D_i3_8013EFA4[] = { 255, 255, 255, 127 };

s32 D_i3_8013EFB4[] = { 255, 0, 0, 255 };

s32 D_i3_8013EFC4[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

Gfx* func_i3_80129F40(Gfx* gfx) {
    s32 var_a1;
    s32 i;
    s32 j;
    s32 var_s1;
    s32 pad[8];
    s32 temp_v1_2;
    s32 sp58;

    var_a1 = 0;
    if (D_i3_80141D10 < 30) {
        var_a1 = (-D_i3_80141D10 * 4) + 120;
    } else if (D_i3_80141D10 > 60030) {
        var_a1 = (D_i3_80141D10 * 4) - 240120;
    }
    gfx = func_i3_8012952C(gfx, var_a1);

    sp58 = 0;
    for (i = 0; i < D_800E5EC0; i++) {
        sp58 += D_800E5F00[i];
    }

    if ((D_i3_80141D10 > 30) && (D_i3_80141D10 < 30030)) {
        temp_v1_2 = func_i2_801062E4("vs results", 3, 1) / 2;
        gfx = func_i3_DrawBeveledBox(gfx, 0x9B - temp_v1_2, 0x21, temp_v1_2 + 0xA9, 0x33, 0, 0, 0xC8, 0x7F);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = func_i2_80106450(gfx, 0xA2 - (func_i2_801062E4("vs results", 3, 1) / 2), 0x34, "vs results", 1, 3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = func_i2_80106450(gfx, 0xA0 - (func_i2_801062E4("vs results", 3, 1) / 2), 0x32, "vs results", 1, 3, 0);
    } else if ((D_i3_80141D10 > 30030) && (D_i3_80141D10 < 60030)) {
        temp_v1_2 = func_i2_801062E4("vs total ranking", 3, 1) / 2;
        gfx = func_i3_DrawBeveledBox(gfx, 0x9B - temp_v1_2, 0x21, temp_v1_2 + 0xA9, 0x33, 0, 0, 0xC8, 0x7F);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = func_i2_80106450(gfx, 0xA2 - (func_i2_801062E4("vs total ranking", 3, 1) / 2), 0x34, "vs total ranking",
                               1, 3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = func_i2_80106450(gfx, 0xA0 - (func_i2_801062E4("vs total ranking", 3, 1) / 2), 0x32, "vs total ranking",
                               1, 3, 0);
    }
    if ((D_i3_80141D10 >= 30) && (D_i3_80141D10 < 30030)) {
        var_a1 = 0;
        if (D_i3_80141D10 < 60) {
            var_a1 = (-D_i3_80141D10 * 4) + 240;
        } else if (D_i3_80141D10 > 30000) {
            var_a1 = (D_i3_80141D10 * 4) - 120000;
        }
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, var_a1 + 30, var_a1 + 25, 290 - var_a1, 220 - var_a1);

        if (D_i3_80141D10 == 30) {
            for (i = 0; i < D_800E5EC0; i++) {
                D_i3_80141D18[i] = D_800E5F10[i] - D_i3_8013EF44[D_800E5EC0][gRacers[i].unk_2AC - 1];
                D_i3_80141D28[i] = D_i3_8013EF44[D_800E5EC0][gRacers[i].unk_2AC - 1];
            }
            D_i3_80141E28 = 0;
            D_i3_80141D68 = 0;
        }
        for (i = 0, j = 0; i < 4; i++) {
            D_i3_80141D48[i] = i;
        }

        for (i = 0; i < D_800E5EC0; i++) {
            j += D_800E5F10[i];
        }

        if (sp58 == 1) {
            for (i = 0; i < D_800E5EC0; i++) {
                for (j = 0; j < D_800E5EC0; j++) {
                    if (gRacers[i].unk_2AC == j + 1) {
                        D_i3_80141D48[j] = i;
                    }
                }
            }
        } else {
            for (i = 0; i < D_800E5EC0; i++) {
                for (j = i + 1; j < D_800E5EC0; j++) {
                    if (D_800E5F10[D_i3_80141D48[i]] -
                            D_i3_8013EF44[D_800E5EC0][gRacers[D_i3_80141D48[i]].unk_2AC - 1] <
                        D_800E5F10[D_i3_80141D48[j]] -
                            D_i3_8013EF44[D_800E5EC0][gRacers[D_i3_80141D48[j]].unk_2AC - 1]) {
                        var_s1 = D_i3_80141D48[i];
                        D_i3_80141D48[i] = D_i3_80141D48[j];
                        D_i3_80141D48[j] = var_s1;
                    }
                    if ((D_800E5F10[D_i3_80141D48[i]] -
                             D_i3_8013EF44[D_800E5EC0][gRacers[D_i3_80141D48[i]].unk_2AC - 1] ==
                         D_800E5F10[D_i3_80141D48[j]] -
                             D_i3_8013EF44[D_800E5EC0][gRacers[D_i3_80141D48[j]].unk_2AC - 1]) &&
                        (D_800E5F00[D_i3_80141D48[i]] - D_i3_8013EFC4[gRacers[D_i3_80141D48[i]].unk_2AC - 1] <
                         D_800E5F00[D_i3_80141D48[j]] - D_i3_8013EFC4[gRacers[D_i3_80141D48[j]].unk_2AC - 1])) {
                        var_s1 = D_i3_80141D48[i];
                        D_i3_80141D48[i] = D_i3_80141D48[j];
                        D_i3_80141D48[j] = var_s1;
                    }
                    if ((D_800E5F10[D_i3_80141D48[i]] -
                             D_i3_8013EF44[D_800E5EC0][gRacers[D_i3_80141D48[i]].unk_2AC - 1] ==
                         D_800E5F10[D_i3_80141D48[j]] -
                             D_i3_8013EF44[D_800E5EC0][gRacers[D_i3_80141D48[j]].unk_2AC - 1]) &&
                        (D_800E5F00[D_i3_80141D48[i]] - D_i3_8013EFC4[gRacers[D_i3_80141D48[i]].unk_2AC - 1] ==
                         D_800E5F00[D_i3_80141D48[j]] - D_i3_8013EFC4[gRacers[D_i3_80141D48[j]].unk_2AC - 1]) &&
                        (D_80115DD0[D_i3_80141D48[i]] > D_80115DD0[D_i3_80141D48[j]])) {
                        var_s1 = D_i3_80141D48[i];
                        D_i3_80141D48[i] = D_i3_80141D48[j];
                        D_i3_80141D48[j] = var_s1;
                    }
                }
            }
        }

        D_i3_80141E28++;
        if (D_i3_80141E28 > 30000) {
            D_i3_80141E28 = 0;
        }

        if ((D_i3_80141E28 > 120) && !(D_i3_80141E28 & 7)) {
            for (i = 0; i < D_800E5EC0; i++) {
                for (j = 0; j < D_800E5EC0; j++) {
                    if (gRacers[j].unk_2AC == i + 1) {
                        break;
                    }
                }

                if (D_i3_80141D28[gRacers[j].unk_00] != 0) {
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x1F);
                    }
                    D_i3_80141D28[gRacers[j].unk_00]--;
                    D_i3_80141D18[gRacers[j].unk_00]++;
                    break;
                }
            }
        }

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        gfx = func_i2_80106450(gfx, 0x30, 0x50, "1Ｓ", 1, 5, 0);
        gfx = func_i2_80106450(gfx, 0x30, 0x69, "2Ｎ", 1, 5, 0);

        if (D_800E5EC0 >= 3) {
            gfx = func_i2_80106450(gfx, 0x30, 0x82, "3Ｒ", 1, 5, 0);
        }
        if (D_800E5EC0 >= 4) {
            gfx = func_i2_80106450(gfx, 0x30, 0x9B, "4Ｔ", 1, 5, 0);
        }

        for (i = 0; i < D_800E5EC0; i++) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, D_i3_8013EF94[D_i3_80141D48[i]], D_i3_8013EFA4[D_i3_80141D48[i]],
                            D_i3_8013EFB4[D_i3_80141D48[i]], 255);
            j = D_i3_80141D48[i];

            if (gRacers[j].unk_00 < gNumPlayers) {
                gfx = func_i2_80106450(gfx, 0x4D, 80 + i * 25, "Ｐ", 1, 5, 0);
            } else {
                gfx = func_i2_80106450(gfx, 0x4D, 80 + i * 25, "Ａ", 1, 5, 0);
            }

            if (gRacers[j].unk_00 < gNumPlayers) {
                func_i3_801296E8(gRacers[j].unk_00 + 1);
            } else {
                func_i3_801296E8((gRacers[j].unk_00 - gNumPlayers) + 1);
            }

            gfx = func_i2_80106450(gfx, 0x93, 80 + i * 25, D_i3_80141E08, 1, 5, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
            func_i3_801296E8(D_i3_80141D18[gRacers[j].unk_00]);
            gfx = func_i2_80106450(gfx, 0xD3 - func_i2_801062E4(D_i3_80141E08, 5, 1), 80 + i * 25, D_i3_80141E08, 1, 5,
                                   0);
            gfx = func_i2_80106450(gfx, 0xD3, 80 + i * 25, "$", 1, 5, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 100, 100, 255, 255);
            gfx = func_i2_80106450(gfx, 0xED, 80 + i * 25, "+", 1, 5, 0);
            func_i3_801296E8(D_i3_80141D28[gRacers[j].unk_00]);
            gfx = func_i2_80106450(gfx, 0xFA, 80 + i * 25, D_i3_80141E08, 1, 5, 0);

            if (gRacers[j].unk_2AC == 1) {
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                gfx = func_i2_80106450(gfx, 0x10E, 80 + i * 25, "v", 1, 5, 0);
            }
        }
    } else if (D_i3_80141D10 >= 30030) {
        if (D_i3_80141D10 < 60030) {
            var_a1 = 0;
            if (D_i3_80141D10 < 30060) {
                var_a1 = -D_i3_80141D10 * 4 + 120240;
            } else if (D_i3_80141D10 > 60000) {
                var_a1 = D_i3_80141D10 * 4 - 240000;
            }
            gDPPipeSync(gfx++);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, var_a1 + 30, var_a1 + 25, 290 - var_a1, 220 - var_a1);

            if (D_i3_80141D68 == 0) {
                gDPPipeSync(gfx++);
                gfx = func_8007DB28(gfx, 0);
                gfx = func_i2_80106700(gfx, 0x82, 0xC3, "Ｃ", 1, 5, 0, 0.8f, 0.8f);
                gfx = func_i2_80106700(gfx, 0x6E, 0xC3, "Ｍ", 1, 5, 0, 0.8f, 0.8f);
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = func_i2_80106700(gfx, 0x82, 0xD2, "Ｅ", 1, 5, 0, 0.8f, 0.8f);
            } else {
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = func_i2_80106700(gfx, 0x82, 0xC3, "Ｃ", 1, 5, 0, 0.8f, 0.8f);
                gDPPipeSync(gfx++);
                gfx = func_8007DB28(gfx, 0);
                gfx = func_i2_80106700(gfx, 0x82, 0xD2, "Ｅ", 1, 5, 0, 0.8f, 0.8f);
                gfx = func_i2_80106700(gfx, 0x6E, 0xD2, "Ｍ", 1, 5, 0, 0.8f, 0.8f);
            }

            for (i = 0; i < 4; i++) {
                D_i3_80141D38[i] = i;
            }

            for (i = 0; i < D_800E5EC0; i++) {
                for (j = i + 1; j < D_800E5EC0; j++) {
                    if (D_800E5F10[D_i3_80141D38[i]] < D_800E5F10[D_i3_80141D38[j]]) {
                        var_s1 = D_i3_80141D38[i];
                        D_i3_80141D38[i] = D_i3_80141D38[j];
                        D_i3_80141D38[j] = var_s1;
                    }
                    if ((D_800E5F10[D_i3_80141D38[i]] == D_800E5F10[D_i3_80141D38[j]]) &&
                        (D_800E5F00[D_i3_80141D38[i]] < D_800E5F00[D_i3_80141D38[j]])) {
                        var_s1 = D_i3_80141D38[i];
                        D_i3_80141D38[i] = D_i3_80141D38[j];
                        D_i3_80141D38[j] = var_s1;
                    }
                    if ((D_800E5F10[D_i3_80141D38[i]] == D_800E5F10[D_i3_80141D38[j]]) &&
                        (D_800E5F00[D_i3_80141D38[i]] == D_800E5F00[D_i3_80141D38[j]]) &&
                        (gRacers[D_i3_80141D38[i]].unk_2AC > gRacers[D_i3_80141D38[j]].unk_2AC)) {
                        var_s1 = D_i3_80141D38[i];
                        D_i3_80141D38[i] = D_i3_80141D38[j];
                        D_i3_80141D38[j] = var_s1;
                    }
                }
            }

            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = func_i2_80106450(gfx, 0x30, 0x50, "1Ｓ", 1, 5, 0);
            gfx = func_i2_80106450(gfx, 0x30, 0x69, "2Ｎ", 1, 5, 0);

            if (D_800E5EC0 >= 3) {
                gfx = func_i2_80106450(gfx, 0x30, 0x82, "3Ｒ", 1, 5, 0);
            }
            if (D_800E5EC0 >= 4) {
                gfx = func_i2_80106450(gfx, 0x30, 0x9B, "4Ｔ", 1, 5, 0);
            }

            for (i = 0; i < D_800E5EC0; i++) {
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, D_i3_8013EF94[D_i3_80141D38[i]], D_i3_8013EFA4[D_i3_80141D38[i]],
                                D_i3_8013EFB4[D_i3_80141D38[i]], 255);

                if (D_i3_80141D38[i] < gNumPlayers) {
                    gfx = func_i2_80106450(gfx, 0x4D, 80 + i * 25, "Ｐ", 1, 5, 0);
                } else {
                    gfx = func_i2_80106450(gfx, 0x4D, 80 + i * 25, "Ａ", 1, 5, 0);
                }

                if (D_i3_80141D38[i] < gNumPlayers) {
                    func_i3_801296E8(D_i3_80141D38[i] + 1);
                } else {
                    func_i3_801296E8((D_i3_80141D38[i] - gNumPlayers) + 1);
                }

                gfx = func_i2_80106450(gfx, 0x93, 80 + i * 25, D_i3_80141E08, 1, 5, 0);
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
                func_i3_801296E8(D_800E5F10[D_i3_80141D38[i]]);
                gfx = func_i2_80106450(gfx, 0xD3 - func_i2_801062E4(D_i3_80141E08, 5, 1), 80 + i * 25, D_i3_80141E08, 1,
                                       5, 0);
                gfx = func_i2_80106450(gfx, 0xD3, 80 + i * 25, "$", 1, 5, 0);

                if (D_800E5F00[D_i3_80141D38[i]] > 0) {
                    gDPPipeSync(gfx++);
                    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                    gfx = func_i2_80106450(gfx, 0xF0, 80 + i * 25, "v", 1, 5, 0);
                    j = D_800E5F00[D_i3_80141D38[i]];
                    if (j > 99) {
                        j = 99;
                    }
                    func_i3_801296E8(j);
                    gfx = func_i2_80106450(gfx, 0xFE, 80 + i * 25, D_i3_80141E08, 1, 5, 0);
                }

                if (sp58 != 1) {
                    for (j = 0; j < D_800E5EC0; j++) {
                        if (D_i3_80141D48[j] == D_i3_80141D38[i]) {
                            var_s1 = j;
                        }
                    }

                    if (var_s1 < i) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
                        gfx = func_i2_80106450(gfx, 0x21, 80 + i * 25, "Ｄ", 1, 5, 0);
                    }

                    if (var_s1 > i) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                        gfx = func_i2_80106450(gfx, 0x21, 80 + i * 25, "Ｕ", 1, 5, 0);
                    }
                }

                if (D_i3_801419A2 == 0) {
                    j = D_800DCE98[D_800DD218[i]].stickY;
                    if (D_i3_80141D68 == 1) {
                        if (j > 50) {
                            D_i3_80141D68 = 0;
                            if (D_800CD010 == 0) {
                                func_800BA8D8(0x1E);
                            }
                        }
                        if (D_800DCE98[D_800DD218[i]].unk_7C & BTN_UP) {
                            D_i3_80141D68 = 0;
                            if (D_800CD010 == 0) {
                                func_800BA8D8(0x1E);
                            }
                        }
                    }
                    if (D_i3_80141D68 == 0) {
                        if (j < -50) {
                            D_i3_80141D68 = 1;
                            if (D_800CD010 == 0) {
                                func_800BA8D8(0x1E);
                            }
                        }
                        if (D_800DCE98[D_800DD218[i]].unk_7C & BTN_DOWN) {
                            D_i3_80141D68 = 1;
                            if (D_800CD010 == 0) {
                                func_800BA8D8(0x1E);
                            }
                        }
                    }
                }
            }
        }
    }
    D_i3_80141D10++;

    if (D_i3_80141D10) {}

    if (D_i3_801419A2 == 0) {
        for (i = 0; i < gNumPlayers; i++) {
            if (D_800DCE98[D_800DD218[i]].unk_7C & (BTN_A | BTN_START)) {
                if ((D_i3_80141D10 > 60) && (D_i3_80141D10 < 30000)) {
                    D_i3_80141D10 = 30000;
                } else if ((D_i3_80141D10 > 30060) && (D_i3_80141D10 < 60000)) {
                    D_i3_80141D10 = 60000;
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x21);
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0EC();
                    }
                }
            }
        }
    }

    if ((D_i3_80141D10 == 60060) && (D_i3_801419A2 == 0)) {
        for (i = 0; i < D_800E5EC0; i++) {
            D_80115DD0[i] = gRacers[i].unk_2AC;
        }

        if (D_800CD010 == 0) {
            func_8007E08C();
        }

        if (D_i3_80141D68 == 0) {
            D_i3_801419A2 = 1;
            D_i3_801419B0 |= 0x40;
        } else {
            D_i3_801419A2 = 1;
            D_i3_801419B0 |= 0x10;
        }
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

extern s32 D_800CE6C0[];

Gfx* func_i3_8012BBAC(Gfx* gfx, s32 arg1) {
    s32 i;
    s32 var_a2;
    s32 temp_ft3;
    f32 var_fv1;
    s32 pad[2];

    var_a2 = 0;
    if (D_i3_80141B88[arg1] < 30) {
        var_a2 = (-D_i3_80141B88[arg1] * 4) + 120;
    } else if (D_i3_80141B88[arg1] > 30030) {
        var_a2 = (D_i3_80141B88[arg1] * 4) - 120120;
    }

    gfx = func_i3_8012952C(gfx, var_a2);

    if ((D_i3_80141B88[arg1] > 30) && (D_i3_80141B88[arg1] < 30030)) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = func_i2_80106450(gfx, 0xA2 - (func_i2_801062E4("results", 3, 1) / 2), 0x34, "results", 1, 3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = func_i2_80106450(gfx, 0xA0 - (func_i2_801062E4("results", 3, 1) / 2), 0x32, "results", 1, 3, 0);
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 30, 55, 290, 204);

        for (i = 0; i < D_800E5EC0; i++) {
            temp_ft3 = (58 + i * 25) - D_i3_80141D08;
            if (temp_ft3 > 20 && temp_ft3 < 220) {
                if (D_800DCE44 == 1) {
                    gfx = func_i3_8011F560(gfx, D_800E5F40[i]->unk_00, D_800E5F40[i]->character, 0x2D,
                                           (s32) ((55 + i * 25) - D_i3_80141D08), 0.75f);
                    gfx = func_i3_80129800(gfx, D_800E5F40[i]->unk_00, i + 1, 0x2C,
                                           (s32) ((64 + i * 25) - D_i3_80141D08));
                    gfx = func_i3_8012963C(gfx, D_800E5F40[i]->unk_00, D_800E5F40[i]->character, 0x49,
                                           (s32) ((70 + i * 25) - D_i3_80141D08));
                    gfx = func_i3_80129870(gfx, D_800E5F40[i]->unk_00, 0xD8, (s32) ((70 + i * 25) - D_i3_80141D08));
                    if (D_800E5F40[i]->unk_2A0 != 0) {
                        gfx = func_i3_80129800(gfx, D_800E5F40[i]->unk_00, D_800CE6C0[i], 0xC7,
                                               (s32) ((70 + i * 25) - D_i3_80141D08));
                    } else {
                        gfx = func_i3_80129800(gfx, D_800E5F40[i]->unk_00, 0, 0xC7,
                                               (s32) ((70 + i * 25) - D_i3_80141D08));
                        gfx = func_i3_80129698(gfx, D_800E5F40[i]->unk_00, 0xDC, (s32) ((70 + i * 25) - D_i3_80141D08));
                    }
                } else {
                    gfx = func_i3_8011F560(gfx, D_800E5F40[i]->unk_00, (s32) D_800E5F40[i]->character, 0x39,
                                           (s32) ((55 + i * 25) - D_i3_80141D08), 0.75f);
                    gfx = func_i3_80129800(gfx, D_800E5F40[i]->unk_00, i + 1, 0x38,
                                           (s32) ((64 + i * 25) - D_i3_80141D08));
                    gfx = func_i3_8012963C(gfx, D_800E5F40[i]->unk_00, (s32) D_800E5F40[i]->character, 0x55,
                                           (s32) ((70 + i * 25) - D_i3_80141D08));
                    if (D_800E5F40[i]->unk_2A0 == 0) {
                        gfx = func_i3_80129698(gfx, D_800E5F40[i]->unk_00, 0xBE, (s32) ((70 + i * 25) - D_i3_80141D08));
                    }
                }
            }
        }

        gSPDisplayList(gfx++, D_8014940);
        gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        for (i = 0; i < D_800E5EC0; i++) {

            if (D_800E5F40[i]->unk_2A0 != 0) {
                temp_ft3 = (58 + i * 25) - D_i3_80141D08;
                if ((temp_ft3 > 20) && (temp_ft3 < 220)) {
                    gDPPipeSync(gfx++);
                    if (D_800E5F40[i]->unk_00 == 0) {
                        gfx = func_8007F090(gfx, 255, 0, 0);
                        gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
                    } else {
                        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                    }
                    if (D_800DCE44 == 1) {
                        gfx = func_i3_8012F554(gfx, D_800E5F40[i]->unk_2A0, 0xD5, (s32) ((58 + i * 25) - D_i3_80141D08),
                                               1.0f);
                    } else {
                        gfx = func_i3_8012F554(gfx, D_800E5F40[i]->unk_2A0, 0xB9, (s32) ((58 + i * 25) - D_i3_80141D08),
                                               1.0f);
                    }
                }
            }
        }
    }
    var_fv1 = D_800DCE98[D_800DD218[0]].stickY * -1.0f;
    if ((var_fv1 > 0.0f) && (var_fv1 < 14.0f)) {
        var_fv1 = 0.0f;
    }
    if ((var_fv1 < 0.0f) && (var_fv1 > -14.0f)) {
        var_fv1 = 0.0f;
    }
    var_fv1 *= 0.075f;
    D_i3_80141D08 += var_fv1;
    if (D_i3_80141D08 < 0.0f) {
        D_i3_80141D08 = 0.0f;
    }

    if ((D_800E5EC0 - 6) * 25.0f < D_i3_80141D08) {
        D_i3_80141D08 = (D_800E5EC0 - 6) * 25.0f;
    }
    if ((D_i3_80141D08 != (D_800E5EC0 - 6) * 25.0f) && (D_i3_80141D08 != 0.0f)) {
        if ((s32) (D_i3_80141D08 * 0.06f) != ((s32) ((D_i3_80141D08 - var_fv1) * 0.06f))) {
            func_800BA8D8(0x3FU);
        }
    }

    D_i3_80141B88[arg1]++;
    if ((D_i3_80141B88[arg1] < 30030) && (D_800DCE98[D_800DD218[0]].unk_7C & (BTN_A | BTN_START))) {
        D_i3_80141B88[arg1] = 30030;
    }
    if (D_i3_80141B88[arg1] >= 30060) {
        D_i3_80141B88[arg1] = 0;
        if (D_800DCE44 == 1) {
            D_i3_80141B98 = 2;
        } else {
            D_i3_80141B98 = 3;
            D_i3_80141DA0 = 60;
        }
    }
    return gfx;
}

void func_i2_80101310(s32, s32, s32);
extern s32 D_800CD004;
extern s16 D_80106F48;
extern s16 D_80115D90[];

Gfx* func_i3_8012C4D8(Gfx* gfx, s32 arg1) {
    s32 i;
    s32 j;
    s32 var_a2;
    s32 temp_ft2;
    s32 var_s0;
    s32 temp_a2;
    f32 var_fv0;
    s32 pad;

    var_a2 = 0;
    if (D_i3_80141B88[arg1] < 30) {
        var_a2 = -D_i3_80141B88[arg1] * 4 + 120;
    } else if (D_i3_80141B88[arg1] > 40030) {
        var_a2 = D_i3_80141B88[arg1] * 4 - 160120;
    }
    gfx = func_i3_8012952C(gfx, var_a2);

    if ((D_i3_80141B88[arg1] > 30) && (D_i3_80141B88[arg1] < 40030)) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx =
            func_i2_80106450(gfx, 0xA2 - (func_i2_801062E4("total ranking", 3, 1) / 2), 0x34, "total ranking", 1, 3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx =
            func_i2_80106450(gfx, 0xA0 - (func_i2_801062E4("total ranking", 3, 1) / 2), 0x32, "total ranking", 1, 3, 0);

        for (i = 0; i < D_800E5EC0; i++) {
            D_i3_801419D0[i] = i;
        }

        for (i = 0; i < D_800E5EC0; i++) {
            for (j = i + 1; j < D_800E5EC0; j++) {
                if (gRacers[D_i3_801419D0[i]].unk_0A < gRacers[D_i3_801419D0[j]].unk_0A) {
                    var_s0 = D_i3_801419D0[i];
                    D_i3_801419D0[i] = D_i3_801419D0[j];
                    D_i3_801419D0[j] = var_s0;
                }
                if (gRacers[D_i3_801419D0[i]].unk_0A == gRacers[D_i3_801419D0[j]].unk_0A) {
                    if (gRacers[D_i3_801419D0[i]].unk_2AC > gRacers[D_i3_801419D0[j]].unk_2AC) {
                        var_s0 = D_i3_801419D0[i];
                        D_i3_801419D0[i] = D_i3_801419D0[j];
                        D_i3_801419D0[j] = var_s0;
                    }

                    if (gRacers[D_i3_801419D0[j]].unk_00 == 0) {
                        var_s0 = D_i3_801419D0[i];
                        D_i3_801419D0[i] = D_i3_801419D0[j];
                        D_i3_801419D0[j] = var_s0;
                    }
                }
            }
        }

        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 30, 55, 290, 212);

        D_i3_80141D00 -= D_i3_80141D04;
        D_i3_80141D04 -= 0.01f;
        if (D_i3_80141D04 < 0.01f) {
            D_i3_80141D04 = 0.01f;
        }
        if (D_i3_80141D00 < -62.0f) {
            D_i3_80141D00 = -62.0f;
        } else if ((s32) (D_i3_80141D00 * 0.06f) != (s32) ((D_i3_80141D00 - D_i3_80141D04) * 0.06f)) {
            func_800BA8D8(0x3F);
        }

        for (i = 0; i < D_800E5EC0; i++) {
            temp_ft2 = (i * 25) - D_i3_80141D00 - D_i3_80141CC8;
            if ((temp_ft2 > 10) && (temp_ft2 < 220)) {
                if (D_800F8514 % 6) {
                    if (D_80115D90[D_i3_801419D0[i]] < i + 1) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
                        gfx = func_i2_80106450(gfx, 0x2F, temp_ft2 + 0x13, "Ｄ", 1, 5, 0);
                        var_s0 = 0x3D;
                        if ((i - D_80115D90[D_i3_801419D0[i]]) + 1 < 0xA) {
                            var_s0 = 0x3A;
                        }
                        gfx = func_i3_80129800(gfx, 1, (i - D_80115D90[D_i3_801419D0[i]]) + 1, var_s0, temp_ft2 + 0x10);
                    }
                    if (D_80115D90[D_i3_801419D0[i]] > i + 1) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                        gfx = func_i2_80106450(gfx, 0x2F, temp_ft2 + 0x16, "Ｕ", 1, 5, 0);
                        var_s0 = 0x3D;
                        if ((i - D_80115D90[D_i3_801419D0[i]]) + 1 > -10) {
                            var_s0 = 0x3A;
                        }
                        gfx = func_i3_80129800(gfx, 1, (D_80115D90[D_i3_801419D0[i]] - i) - 1, var_s0, temp_ft2 + 0x13);
                    }
                }

                gfx = func_i3_8011F560(gfx, gRacers[D_i3_801419D0[i]].unk_00, gRacers[D_i3_801419D0[i]].character, 0x51,
                                       temp_ft2, 0.75f);
                gfx = func_i3_80129800(gfx, gRacers[D_i3_801419D0[i]].unk_00, i + 1, 0x51, temp_ft2 + 9);
                gfx = func_i3_8012963C(gfx, gRacers[D_i3_801419D0[i]].unk_00, gRacers[D_i3_801419D0[i]].character, 0x6D,
                                       temp_ft2 + 0xF);
                gfx = func_i3_801298DC(gfx, gRacers[D_i3_801419D0[i]].unk_00, 0x103, temp_ft2 + 0xF);
                gfx = func_i3_80129800(gfx, gRacers[D_i3_801419D0[i]].unk_00, gRacers[D_i3_801419D0[i]].unk_0A, 0xF3,
                                       temp_ft2 + 0xF);
            }

            if (D_i3_801419D0[i] == 0) {
                D_80106F48 = i + 1;
            }
        }
    }

    if ((D_800DCE44 == 1) && (D_i3_80141B88[arg1] == 60) && (D_i3_801419D0[0] == 0) && ((D_800F8514 % 6) == 5) &&
        (D_800CD004 < 5)) {
        func_8007DEF0();
        if ((s8) gRacers[0].unk_164 == 0) {
            func_i2_80101310(gDifficulty, D_800CD004, gRacers[0].character);
        }
    }

    D_i3_80141B88[arg1]++;

    if (D_800DCE98[D_800DD218[0]].unk_7C & (BTN_A | BTN_START)) {
        D_i3_80141D04 = 8.0f;
    }
    if ((D_i3_80141B88[arg1] < 40030) && (D_i3_80141D00 <= -62.0f)) {
        if (D_800DCE98[D_800DD218[0]].unk_7C & (BTN_A | BTN_START)) {
            D_i3_80141B88[arg1] = 40030;
        }
        var_fv0 = D_800DCE98[D_800DD218[0]].stickY * -1.0f;
        if ((var_fv0 > 0.0f) && (var_fv0 < 14.0f)) {
            var_fv0 = 0.0f;
        }
        if ((var_fv0 < 0.0f) && (var_fv0 > -14.0f)) {
            var_fv0 = 0.0f;
        }
        var_fv0 *= 0.075f;
        D_i3_80141CC8 += var_fv0;
        if (D_i3_80141CC8 < 0.0f) {
            D_i3_80141CC8 = 0.0f;
        }

        if (((D_800E5EC0 - 6) * 25.0f + 7.0f) < D_i3_80141CC8) {
            D_i3_80141CC8 = (D_800E5EC0 - 6) * 25.0f + 7.0f;
        }
        if ((D_i3_80141CC8 != 0.0f) && (D_i3_80141CC8 != ((D_800E5EC0 - 6) * 25.0f + 7.0f)) &&
            (s32) (D_i3_80141CC8 * 0.06f) != (s32) ((D_i3_80141CC8 - var_fv0) * 0.06f)) {
            func_800BA8D8(0x3F);
        }
    }
    if (D_i3_80141B88[arg1] >= 40060) {
        D_i3_80141B98 = 5;

        for (i = 0; i < D_800E5EC0; i++) {
            for (j = 0; j < D_800E5EC0; j++) {
                if (D_i3_801419D0[j] == i) {
                    D_80115D90[i] = j + 1;
                }
            }
        }
    }
    return gfx;
}

extern s32 D_800CD00C;
extern s32 D_800CD3CC;

Gfx* func_i3_8012CF34(Gfx* gfx, s32 arg1) {
    s32 i;

    if (D_800E5220[arg1].unk_04 == 10) {
        if ((D_800DCE44 != 0xE) || ((D_800DCE44 == 0xE) && (D_800CD3CC < 2))) {
            if (D_i3_80141BD0[arg1] == 0) {
                D_i3_80141BD0[arg1] = 1;
                func_i3_801217F0(arg1);
            }

            if (D_i3_80141D78[arg1] < 300) {
                gfx = func_i3_80121860(gfx, arg1);
            }
        } else {
            if ((D_i3_80141D78[arg1] < 300) && ((gGameFrameCount & 4) || (D_i3_80141D78[arg1] >= 0x3D))) {
                gRacers[0].unk_36C |= 0x1000;
                gfx = func_i3_801209C8(gfx, 0);
            }
            if (D_i3_80141D78[arg1] == 120) {
                if (D_800CD010 == 0) {
                    func_800BAFA4(0x10);
                }

                for (i = 0; i < gNumPlayers; i++) {
                    if ((gRacers[i].unk_04 & 0x08000000) || (gRacers[arg1].unk_04 & 0x02000000)) {
                        func_800BA3E4(i, 3);
                        func_800BA3E4(i, 4);
                        func_800BA3E4(i, 5);
                        func_800BA3E4(i, 8);
                        func_800BA3E4(i, 9);
                        func_800BA3E4(i, 10);
                        func_800BA3E4(i, 11);
                    }
                }
            }

            if ((D_i3_80141D78[arg1] == 2) && (D_800F8514 < 0x30) && (D_800CD00C == 3)) {
                D_i3_801419B0 |= 4;
            }
        }
        D_i3_80141D78[arg1]++;
    } else if (D_i3_80141DF0[arg1] == 1) {
        if ((D_800DCE44 != 0xE) || ((D_800DCE44 == 0xE) && (D_800CD3CC < 2))) {
            if (D_i3_80141BD0[arg1] == 0) {
                D_i3_80141BD0[arg1] = 1;
                func_i3_801217F0(arg1);
            }
            gfx = func_i3_80121860(gfx, arg1);
        } else {

            if ((D_i3_80141BE0[arg1] > 60) || (gGameFrameCount & 4)) {
                gfx = func_i3_8012040C(gfx, 0);
            }
            if (D_i3_80141BE0[arg1] == 30) {
                if (D_800CD010 == 0) {
                    func_800BAFA4(0x11);
                }

                for (i = 0; i < gNumPlayers; i++) {
                    if ((gRacers[i].unk_04 & 0x08000000) || (gRacers[arg1].unk_04 & 0x02000000)) {
                        func_800BA3E4(i, 3);
                        func_800BA3E4(i, 4);
                        func_800BA3E4(i, 5);
                        func_800BA3E4(i, 8);
                        func_800BA3E4(i, 9);
                        func_800BA3E4(i, 10);
                        func_800BA3E4(i, 11);
                    }
                }
            }
            if ((D_i3_80141BE0[arg1] == 2) && (D_800F8514 < 0x30) && (D_800CD00C == 3)) {
                D_i3_801419B0 |= 4;
            }
        }
    } else {
        D_i3_80141BD0[arg1] = 0;
    }
    return gfx;
}

extern s32 D_800CD00C;
extern char* D_800E4178;
extern s16 D_800E5FBC;
extern s16 D_800E5FC2;
extern s16 D_800E5FE2;
extern s16 D_800F5DE6;
extern s32 D_800F5E98;
extern s32 D_800F80A8[];
extern s32 D_80106F40;
extern s32 D_80106F44;

Gfx* func_i3_8012D3D4(Gfx* gfx) {
    s32 i = 0;
    s32 j;
    Racer* racer;
    s32 pad[4];
    f32 temp_ft5;
    f32 var_fa0;
    s32 playerIndex = 0;

    D_80115DE0 = D_800E5EC0 - D_800E5FC2;
    if ((gNumPlayers == 1) && (D_800E5EC0 != 1) && !(gGameFrameCount % 64) && (D_800DCE5C == 0)) {
        func_i3_801175A4();
    }
    if (gNumPlayers == 1) {
        if (D_800DCE44 == 0x15) {
            if (gRacers[playerIndex].unk_98 < (500.0f / 27.0f)) {
                D_80141900++;
            } else {
                D_80141900 = 0;
            }
        } else {
            if (gRacers[playerIndex].unk_98 < (250.0f / 27.0f)) {
                D_80141900++;
            } else {
                D_80141900 = 0;
            }
        }
    }

    for (i = 0; i < gNumPlayers; i++) {
        if (gRacers[i].unk_04 & 0x02000000) {
            D_i3_80141DE0[i]++;
            if (D_i3_80141DE0[i] > 36000) {
                D_i3_80141DE0[i] = 36000;
            }

            if (D_i3_80141E00 < D_i3_80141DE0[i]) {
                D_i3_80141DF0[i] = 2;
            } else {
                D_i3_80141DF0[i] = 1;
            }
        }
        if ((gNumPlayers >= 2) && (D_800E5FBC == 1)) {
            D_i3_80141DF0[i] = 2;
        }
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, 320, 240);

    if (D_80141D6C == 0) {
        if (gNumPlayers == 3) {
            gfx = func_i3_DrawBeveledBox(gfx, 0xA0, 0x78, 0x131, 0xE8, 0, 0, 0, 0xFF);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 250, 255);
            gfx = func_i2_80106700(gfx, (234.0f - ((func_i2_801062E4(D_800E4178, 3, 1) * 0.7f) / 2)), 0x94, D_800E4178,
                                   1, 3, 0, 0.7f, 0.7f);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
            gfx = func_i2_80106700(gfx, (232.0f - ((func_i2_801062E4(D_800E4178, 3, 1) * 0.7f) / 2)), 0x92, D_800E4178,
                                   1, 3, 0, 0.7f, 0.7f);
        }

        gDPPipeSync(gfx++);
        if (gNumPlayers == 1) {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
        } else {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
        }

        if ((gNumPlayers != 1) || (D_800DCE44 != 1) || (D_i3_801419B8 > 0) || (D_i3_80141C20[0] < 2)) {
            if (((gNumPlayers != 1) || (D_i3_80141DF0[0] != 2)) &&
                ((gNumPlayers != 1) || (D_800E5220[playerIndex].unk_04 != 10) || (D_i3_80141D78[0] < 300))) {
                gfx = func_i3_DrawHUD(gfx);
            }
            for (i = 0; i < gNumPlayers; i++) {
                if ((gNumPlayers != 1) ||
                    ((D_i3_80141DF0[i] != 2) && ((D_800E5220[playerIndex].unk_04 != 10) || (D_i3_80141D78[0] < 300)))) {
                    if (gNumPlayers == 1) {
                        gfx = func_i3_80132EEC(gfx);
                    }
                    if ((D_800DCE44 != 0x15) && (D_i3_80141C20[i] == 0) && !(gRacers[i].unk_04 & 0x02000000)) {
                        gfx = func_i3_80135B20(gfx, gNumPlayers - 1, i);
                    }
                    if (gNumPlayers == 3) {
                        gfx = func_i3_80135B20(gfx, gNumPlayers - 1, 3);
                    }
                    gfx = func_i3_801312DC(gfx, gNumPlayers - 1, i);
                }
                if (((gNumPlayers != 1) || (D_i3_80141C20[i] == 0)) && !(gRacers[i].unk_04 & 0x02000000)) {
                    gfx = func_i3_80130824(gfx, gNumPlayers - 1, i);
                }
            }
        }
    }
    if (((gGameFrameCount % 120) == 0) && (D_800DCE5C == 0)) {
        for (i = 0; i < D_800E5EC0; i++) {
            if (!(gRacers[i].unk_04 & 0x02000000) && (gRacers[i].unk_04 & 0x08000000)) {
                gRacers[i].unk_368 = 254;
            }
        }

        if (D_800CD010 != 0) {
            j = 0;
            for (i = 0; i < gNumPlayers; i++) {
                if (gRacers[i].unk_04 & 0x08000000) {
                    j++;
                }
            }

            if (((gNumPlayers == j) || (D_800E5FBC == 1)) && (D_800CD010 == 1)) {
                D_800CD010 = 3;
            }
        }
    }
    if (gNumPlayers == 1) {
        if (((D_800E5220[playerIndex].unk_04 == 4) || (D_800E5220[playerIndex].unk_04 == 6)) &&
            (D_i3_80141C20[0] == 0)) {
            temp_ft5 = gRacers[playerIndex].unk_23C / gRacers[playerIndex].unk_2A0;
            if (D_800DCE44 == 1) {
                if (D_80106F44 != 0) {
                    if ((temp_ft5 > 0.1f) && (D_80115DE0 >= 2)) {
                        if (gRacers[playerIndex].unk_2AC != 1) {
                            var_fa0 = ((D_800E5F40[0]->unk_23C - gRacers[playerIndex].unk_23C) / temp_ft5) * 0.8892f;
                        } else {
                            var_fa0 = ((D_800E5F40[1]->unk_23C - gRacers[playerIndex].unk_23C) / temp_ft5) * 0.8892f;
                        }
                        if (D_800E5F40[0]->unk_04 & 0x02000000) {
                            var_fa0 = ((gRacers[playerIndex].unk_2A0 / gRacers[playerIndex].unk_23C) *
                                       D_800F8510->unk_0C * D_800CD00C) -
                                      D_800E5F40[0]->unk_2A0;
                        }
                        if ((var_fa0 < 30000.0f) && (var_fa0 > -30000.0f) && (D_800F80A8[0] < 10)) {
                            gfx = func_i3_8011DB98(gfx, var_fa0, 0xDE, 0x36);
                        } else {
                            gfx = func_i3_8011D8F0(gfx, 0xDE, 0x36);
                        }
                    } else {
                        gfx = func_i3_8011D8F0(gfx, 0xDE, 0x36);
                    }
                }
                if ((D_800CD010 == 0) && (D_800DCE98[D_800DD218[0]].unk_7C & BTN_L)) {
                    D_80106F44 ^= 1;
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x31);
                    }
                }
            } else if ((D_800DCE44 == 0xE) && (D_i3_80141C84 >= 0)) {

                if (D_i3_80141DD0->unk_244 - D_i3_80141DD8 < -(D_800F8510->unk_0C * 0.5f)) {
                    D_i3_80141DDC += D_800F8510->unk_0C;
                }

                if (D_800F8510->unk_0C * 0.5f < D_i3_80141DD0->unk_244 - D_i3_80141DD8) {
                    D_i3_80141DDC -= D_800F8510->unk_0C;
                }
                D_i3_80141DD0->unk_23C = D_i3_80141DD0->unk_244 + D_i3_80141DDC;
                if (D_80106F44 != 0) {
                    if (temp_ft5 > 0.1f) {
                        var_fa0 = ((D_i3_80141DD0->unk_23C - gRacers[playerIndex].unk_23C) / temp_ft5) * 0.8892f;
                        if ((D_800F8510->unk_0C * (D_800CD00C - 0.01f)) <= D_i3_80141DD0->unk_23C) {
                            var_fa0 = ((gRacers[playerIndex].unk_2A0 / gRacers[playerIndex].unk_23C) *
                                       D_800F8510->unk_0C * D_800CD00C) -
                                      D_80141C78;
                        }
                        if ((var_fa0 < 30000.0f) && (var_fa0 > -30000.0f) && (D_800F80A8[0] < 0xA)) {
                            gfx = func_i3_8011DB98(gfx, var_fa0, 0xDE, 0x36);
                        } else {
                            gfx = func_i3_8011D8F0(gfx, 0xDE, 0x36);
                        }
                    } else {
                        gfx = func_i3_8011D8F0(gfx, 0xDE, 0x36);
                    }
                }
                D_i3_80141DD8 = D_i3_80141DD0->unk_244;
                if ((D_800CD010 == 0) && (D_800DCE98[D_800DD218[0]].unk_7C & BTN_L)) {
                    D_80106F44 ^= 1;
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x31);
                    }
                }
            }
        }

        if ((D_800DCE44 == 0xE) && (D_800DCE5C == 0) && (D_800F5DE6 != 0) && (D_800E5220[playerIndex].unk_04 == 6) &&
            (D_i3_80141C20[0] == 0)) {
            gfx = func_i3_801239D0(gfx);
        }
        if (D_800DCE44 != 2) {
            if ((gRacers[playerIndex].unk_2A8 == D_800CD00C) && (D_800CD010 == 0) &&
                (D_i3_80141EA8[playerIndex].unk_04 > 0) && (D_800DCE5C == 0)) {
                if (((D_i3_80141EA8[playerIndex].unk_04 % 20) >= 5) && (D_i3_80141EA8[playerIndex].unk_04 > 120)) {
                    gfx = func_i3_80121178(gfx, 0);
                }
                D_i3_80141CD0[playerIndex]++;
            }
            if ((gRacers[playerIndex].unk_2A8 == 2) && (D_800CD010 == 0) && (D_800DCE5C == 0) &&
                (D_i3_80141EA8[playerIndex].unk_04 > 0)) {
                if (((D_i3_80141EA8[playerIndex].unk_04 % 20) >= 5) && (D_i3_80141EA8[playerIndex].unk_04 > 120)) {
                    gfx = func_i3_801216C0(gfx, 0);
                }
                D_i3_80141CE0[playerIndex]++;
            }
        }
        if ((D_800DCE5C == 0) && (D_800E5220[playerIndex].unk_04 == 4)) {
            gDPPipeSync(gfx++);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
            D_i3_80141D8C++;
            if (D_i3_80141D8C >= 4) {
                j = D_i3_80141D8C - 200;
                if (D_i3_80141D8C < 250) {
                    if (j < 0) {
                        j = 0;
                    }

                    if (D_800DCE44 != 0x15) {
                        i = 320 - (D_i3_80141D8C * 8);
                        if (i < 160) {
                            i = 160;
                        }
                        gfx = func_i3_8012757C(gfx, i, 120, j);
                    }
                    i = D_i3_80141D8C * 8;
                    if (i > 160) {
                        i = 160;
                    }
                    if ((D_800DCE44 == 1) || (D_800DCE44 == 2) || (D_800DCE44 == 0x15)) {
                        gfx = func_i3_801281B4(gfx, i, 93, j);
                        if ((D_800DCE44 == 0x15) && (D_800F8510->unk_20[0] != MAX_TIMER)) {
                            i = 300 - (D_i3_80141D8C * 8);
                            if (i < 160) {
                                i = 140;
                            }
                            gfx = func_i3_80127E88(gfx, 160, i, j);
                        }
                    } else {
                        gfx = func_i3_80127854(gfx, i, 86, j);
                        if (D_800F8510->unk_20[0] != MAX_TIMER) {
                            i = 320 - (D_i3_80141D8C * 8);
                            if (i < 160) {
                                i = 160;
                            }
                            gfx = func_i3_80127B2C(gfx, 160, i, j);
                        }
                    }
                }
            }
        }
        if ((D_i3_80141DF0[0] == 2) || ((D_800E5220[playerIndex].unk_04 == 10) && (D_i3_80141D78[0] > 300))) {
            if (D_i3_80141B78[playerIndex] == 0) {
                D_i3_80141B78[playerIndex] = 1;
                if (D_800DCE44 != 0xE) {
                    func_8008AA8C();
                }
            }
            if (D_800DCE44 == 0xE) {
                if (D_i3_80141B9C < 0x190) {
                    gfx = func_i3_801274EC(gfx);
                    gfx = func_i3_80126B40(gfx, 0);
                }
                gfx = func_i3_8012757C(gfx, 160, 0x26, 0);
                if ((D_i3_80141B88[playerIndex] > 100) && (D_800DCE98[D_800DD218[0]].unk_7C & (BTN_A | BTN_START)) &&
                    (D_i3_80141B9C == 0)) {
                    D_i3_80141B9C = 1;
                }

                if (D_i3_80141B9C != 0) {
                    D_i3_80141B9C += 8;
                }
                if ((D_i3_80141B9C >= 0x188) && (D_i3_80141B9C < 0x190)) {
                    if (D_800E5FE2 == 0) {
                        func_i3_80139FF4();
                    }
                    func_i3_80122D88();
                }
                if (D_i3_80141B9C >= 0x190) {
                    D_i3_80141B9C = 0x190;
                    if (D_i3_801419BC) {
                        func_i3_8013C15C();
                        gfx = func_i3_8013D2BC(gfx);
                    } else {
                        i = func_i3_8013A004();
                        gfx = func_i3_8013A360(gfx, D_800F8514);
                        if (i) {
                            gfx = func_i3_DrawTimeAttackFinishMenu(gfx);
                        }
                    }
                }
            } else if (D_800DCE44 == 1) {
                switch (D_i3_80141B98) {
                    case 0:
                        gfx = func_i3_8012757C(gfx, 160, 200, 0);
                        gfx = func_i3_8011FAE4(gfx);
                        gfx = func_i3_80126B40(gfx, 0);
                        if ((D_i3_80141B88[playerIndex] >= 600) ||
                            (D_800DCE98[D_800DD218[0]].unk_7C & (BTN_A | BTN_START))) {
                            D_i3_80141B98 = 1;
                            D_i3_80141B88[playerIndex] = 0;
                        }
                        break;
                    case 1:
                        gfx = func_i3_8012BBAC(gfx, 0);
                        D_i3_80141D00 = D_800E5EC0 * 25;
                        D_i3_80141D04 = 4.2f;
                        break;
                    case 2:
                        gfx = func_i3_8012C4D8(gfx, 0);
                        break;
                    case 5:
                        if (D_800CD010 == 0) {
                            func_800BB048();
                        }
                        if (D_800CD010 == 0) {
                            func_8007E0EC();
                        }
                        D_i3_801419A2 = 1;
                        D_i3_801419A6 = 30;
                        D_i3_801419B0 |= 0x200;
                        D_i3_80141B98 = 255;
                        break;
                    case 3:
                        gfx = func_i3_80124370(gfx);
                        break;
                    case 4:
                        if (D_800CD010 == 0) {
                            func_800BB048();
                        }
                        if (D_800CD010 == 0) {
                            func_8007E0CC();
                        }
                        D_i3_801419A2 = 1;
                        D_i3_801419B0 |= 0x10;
                        D_i3_80141B98 = 255;
                        break;
                    case 255:
                        break;
                }
            } else if (D_800DCE44 == 0x15) {
                gfx = func_i3_80129948(gfx);
                gfx = func_i3_80124EEC(gfx);
            }
        }
        if (!(gRacers[playerIndex].unk_04 & 0x02000000) && (gRacers[playerIndex].unk_04 & 0x08000000)) {
            if (D_i3_80141C20[0] == 0) {
                D_i3_80141C30[0] = 0;
                D_i3_80141C50[0] = 200.0f;
                D_i3_80141C40[0] = -20.0f;
                D_i3_80141C20[0] = 1;
            }
            if ((D_800DCE44 == 1) && (D_i3_801419B8 <= 0)) {
                switch (D_i3_80141C20[0]) {
                    case 1:
                        gfx = func_i3_80128DA4(gfx, 0);
                        if (D_i3_80141C30[0] > 500) {
                            D_i3_80141C20[0] = 2;
                            func_i3_80121E28(0);
                            if (D_800CD010 == 0) {
                                func_800BAFA4(0x14);
                            }
                        }
                        break;
                    case 2:
                        gfx = func_i3_80121E70(gfx, 0);
                        break;
                }
            } else {
                gfx = func_i3_80128DA4(gfx, 0);
                if (D_800CD010 == 0) {
                    if (D_800DCE44 == 1) {
                        if (D_i3_80141C30[0] == 400) {
                            if (D_800CD010 == 0) {
                                func_800BB048();
                            }
                            if (D_800CD010 == 0) {
                                func_8007E0CC();
                            }
                            D_i3_801419A2 = 1;
                            D_i3_801419B0 |= 0x400;
                        }
                    } else if (D_i3_80141C30[0] > 200) {
                        if (D_800DCE44 != 0x15) {
                            gfx = func_i3_8012492C(gfx);
                        } else {
                            gfx = func_i3_80124EEC(gfx);
                        }
                    }
                }
            }
        }
    } else {
        if (D_80141D6C == 0) {
            for (i = 0; i < D_800E5EC0; i++) {
                racer = &gRacers[i];
                if (i < gNumPlayers) {
                    if (racer->unk_2A8 == D_800CD00C) {
                        if ((D_i3_80141EA8[i].unk_04 > 0) && (D_800DCE5C == 0)) {
                            if (((D_i3_80141EA8[i].unk_04 % 20) >= 5) && (D_i3_80141EA8[i].unk_04 > 120)) {
                                gfx = func_i3_80121178(gfx, i);
                            }
                            D_i3_80141CD0[i]++;
                        }
                    }

                    if ((racer->unk_2A8 == 2) && (D_800CD010 == 0) && (D_800DCE5C == 0)) {
                        if (D_i3_80141EA8[i].unk_04 > 0) {
                            if (((D_i3_80141EA8[i].unk_04 % 20) >= 5) && (D_i3_80141EA8[i].unk_04 > 120)) {
                                gfx = func_i3_801216C0(gfx, i);
                            }
                            D_i3_80141CE0[i]++;
                        }
                    }
                }

                // FAKE
                if (1) {}

                if (((racer->unk_04 & 0x02000000) && (i < gNumPlayers)) || (D_800E5FBC == 1)) {
                    gfx = func_i3_8012040C(gfx, i);
                }

                if (D_i3_8013F008[i] >= D_800CD00C + 1) {
                    D_i3_80141D58[i]++;

                    if (D_i3_80141D58[i] > 3000) {
                        D_i3_80141D58[i] = 3000;
                    }
                    if (D_i3_80141D58[i] > 180) {
                        gfx = func_i3_8012266C(gfx, i);
                    }
                } else {
                    D_i3_80141D58[i] = 0;
                }
                if ((racer->unk_04 & 0x02000000) && (i < gNumPlayers) && !(racer->unk_04 & 0x08000000)) {
                    gfx = func_i3_80126B40(gfx, i);
                } else if ((racer->unk_04 & 0x08000000) && !(racer->unk_04 & 0x02000000) && (i < gNumPlayers) &&
                           (D_i3_80141DF0[i] != 2)) {
                    if (D_i3_80141C20[i] == 0) {
                        D_i3_80141C30[i] = 0;
                        D_i3_80141C50[i] = 200.0f;
                        D_i3_80141C40[i] = -20.0f;
                        D_i3_80141C20[i] = 1;
                    }
                    if ((D_800E5FBC != 1) || (racer->unk_2AC != 1)) {
                        gfx = func_i3_80128DA4(gfx, i);
                    }
                }
            }
        }
        if ((D_800E5FBC == 1) && (D_800CD010 == 0)) {
            if (D_i3_80141D10 > 0) {
                D_80141D6C = 1;
                if (D_80141D70 != 0) {
                    gfx = func_i3_80129F40(gfx);
                }
            } else {
                D_80141D6C = 0;
                D_i3_80141D10++;
            }
            if ((D_i3_80141D10 == 0) && (D_800CD010 == 0)) {
                func_800BB048();
            }
        } else {
            D_80141D6C = 0;
            D_i3_80141D10 = -420;
        }
    }
    if ((D_80106F40 != 0) && (D_800E5FBC != 1) && (gNumPlayers >= 2)) {
        for (i = 0; i < gNumPlayers; i++) {
            if ((gRacers[i].unk_04 & 0x08000000) && !(gRacers[i].unk_04 & 0x02000000)) {
                gfx = func_i3_8011C25C(gfx, i);
            }
        }
    }
    if (D_800CD010 == 0) {
        if (D_800DCE5C != 0) {
            if (D_800DCE44 == 1) {
                gfx = func_i3_80126330(gfx);
            } else if (D_800DCE44 == 0x15) {
                gfx = func_i3_80125C34(gfx);
            } else {
                gfx = func_i3_8012548C(gfx);
            }
        } else {
            D_i3_80141DA8 = 60;
            D_i3_80141DA4 = 0;
            for (i = 0; i < gNumPlayers; i++) {
                if ((D_800DCE98[D_800DD218[i]].unk_7C & BTN_START) && (D_800CD010 == 0) && (D_800E5FBC == 0) &&
                    (D_800F5E98 < 320)) {
                    D_i3_801419B0 |= 1;
                    sPausePlayerNum = i;
                    break;
                }
            }
        }
    }
    return gfx;
}
