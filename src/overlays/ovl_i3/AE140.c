#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_save.h"
#include "fzx_course.h"
#include "src/overlays/ovl_i2/ovl_i2.h"
#include "ovl_i3.h"
#include "assets/segment_17B960.h"
#include "assets/segment_1B8550.h"
#include "assets/segment_2B9EA0.h"

s16 sRaceFinishSaveTriggered;
s16 sMenuIsBusy;
s16 sMenuOptionTriggered;
s16 D_i3_801419A6;
s32 D_i3_801419A8;
s32 D_i3_801419AC;
s32 sMenuStateFlags;
s32 D_i3_801419B4;
s32 sPlayer1Lives;
bool D_i3_801419BC;
UNUSED s32 D_i3_801419C0[4];
s32 gRacerIdsByPosition[30];
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
s32 gFastestGhostTime;
s32 sFastestGhostTime;
s32 sFastestGhostIndex;
s32 gFastestGhostIndex;
GhostInfo gSavedGhostInfo;
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
s32 sPauseMenuOptionIndex;
s32 sPauseMenuScissorBoxTimer;
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
    aPortraitPositionFirstTex,  aPortraitPositionSecondTex, aPortraitPositionThirdTex,
    aPortraitPositionFourthTex, aPortraitPositionFifthTex,  aPortraitPositionSixthTex,
};

s16 D_i3_8013ED48[][4][2] = {
    { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },   { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },
    { { 118, 83 }, { 118, 196 }, { 200, 80 }, { 200, 193 } }, { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },
    { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },
};

void* sRaceMenuTextures[RACE_MENU_MAX] = {
    aMenuRetryTex,                 // RACE_MENU_RETRY
    aMenuSettingsTex,              // RACE_MENU_SETTINGS
    aMenuQuitTex,                  // RACE_MENU_QUIT
    aMenuChangeMachineTex,         // RACE_MENU_CHANGE_MACHINE
    aMenuChangeCourseTex,          // RACE_MENU_CHANGE_COURSE
    aMenuGhostSaveTex,             // RACE_MENU_GHOST_SAVE
    aMenuOverwriteData1Tex,        // RACE_MENU_OVERWRITE_DATA1
    aMenuSavingTex,                // RACE_MENU_SAVING
    aMenuNoGamePakTex,             // RACE_MENU_NO_GAME_PAK
    aMenuNoDiskTex,                // RACE_MENU_NO_DISK
    aMenuOverwriteData2Tex,        // RACE_MENU_OVERWRITE_DATA2
    aMenuClearRecordTex,           // RACE_MENU_CLEAR_RECORD
    aMenuEraseCourseSavedData1Tex, // RACE_MENU_ERASE_COURSE_DATA1
    aMenuClearGhostTex,            // RACE_MENU_CLEAR_GHOST
    aMenuEraseCourseSavedData2Tex, // RACE_MENU_ERASE_COURSE_DATA2
    aMenuContinueTex,              // RACE_MENU_CONTINUE
    aMenuYesTex,                   // RACE_MENU_YES
    aMenuNoTex,                    // RACE_MENU_NO
    aMenuSavedTex,                 // RACE_MENU_SAVED
    aMenuNewGhostTex,              // RACE_MENU_NEW_GHOST
    aMenuSavedGhostTex,            // RACE_MENU_SAVED_GHOST
    aMenuCannotSaveGhostTex,       // RACE_MENU_CANNOT_SAVE_GHOST
    aMenuLeftArrowTex,             // RACE_MENU_LEFT_ARROW
    aMenuRightArrowTex,            // RACE_MENU_RIGHT_ARROW
};

s32 sRaceMenuDimensions[RACE_MENU_MAX * 2] = {
    TEX_WIDTH(aMenuRetryTex),
    TEX_HEIGHT(aMenuRetryTex), // RACE_MENU_RETRY
    TEX_WIDTH(aMenuSettingsTex),
    TEX_HEIGHT(aMenuSettingsTex), // RACE_MENU_SETTINGS
    TEX_WIDTH(aMenuQuitTex),
    TEX_HEIGHT(aMenuQuitTex), // RACE_MENU_QUIT
    TEX_WIDTH(aMenuChangeMachineTex),
    TEX_HEIGHT(aMenuChangeMachineTex), // RACE_MENU_CHANGE_MACHINE
    TEX_WIDTH(aMenuChangeCourseTex),
    TEX_HEIGHT(aMenuChangeCourseTex), // RACE_MENU_CHANGE_COURSE
    TEX_WIDTH(aMenuGhostSaveTex),
    TEX_HEIGHT(aMenuGhostSaveTex), // RACE_MENU_GHOST_SAVE
    TEX_WIDTH(aMenuOverwriteData1Tex),
    TEX_HEIGHT(aMenuOverwriteData1Tex), // RACE_MENU_OVERWRITE_DATA1
    TEX_WIDTH(aMenuSavingTex),
    TEX_HEIGHT(aMenuSavingTex), // RACE_MENU_SAVING
    TEX_WIDTH(aMenuNoGamePakTex),
    TEX_HEIGHT(aMenuNoGamePakTex), // RACE_MENU_NO_GAME_PAK
    TEX_WIDTH(aMenuNoDiskTex),
    TEX_HEIGHT(aMenuNoDiskTex), // RACE_MENU_NO_DISK
    TEX_WIDTH(aMenuOverwriteData2Tex),
    TEX_HEIGHT(aMenuOverwriteData2Tex), // RACE_MENU_OVERWRITE_DATA2
    TEX_WIDTH(aMenuClearRecordTex),
    TEX_HEIGHT(aMenuClearRecordTex), // RACE_MENU_CLEAR_RECORD
    TEX_WIDTH(aMenuEraseCourseSavedData1Tex),
    TEX_HEIGHT(aMenuEraseCourseSavedData1Tex), // RACE_MENU_ERASE_COURSE_DATA1
    TEX_WIDTH(aMenuClearGhostTex),
    TEX_HEIGHT(aMenuClearGhostTex), // RACE_MENU_CLEAR_GHOST
    TEX_WIDTH(aMenuEraseCourseSavedData2Tex),
    TEX_HEIGHT(aMenuEraseCourseSavedData2Tex), // RACE_MENU_ERASE_COURSE_DATA2
    TEX_WIDTH(aMenuContinueTex),
    TEX_HEIGHT(aMenuContinueTex), // RACE_MENU_CONTINUE
    TEX_WIDTH(aMenuYesTex),
    TEX_HEIGHT(aMenuYesTex), // RACE_MENU_YES
    TEX_WIDTH(aMenuNoTex),
    TEX_HEIGHT(aMenuNoTex), // RACE_MENU_NO
    TEX_WIDTH(aMenuSavedTex),
    TEX_HEIGHT(aMenuSavedTex), // RACE_MENU_SAVED
    TEX_WIDTH(aMenuNewGhostTex),
    TEX_HEIGHT(aMenuNewGhostTex), // RACE_MENU_NEW_GHOST
    TEX_WIDTH(aMenuSavedGhostTex),
    TEX_HEIGHT(aMenuSavedGhostTex), // RACE_MENU_SAVED_GHOST
    TEX_WIDTH(aMenuCannotSaveGhostTex),
    TEX_HEIGHT(aMenuCannotSaveGhostTex), // RACE_MENU_CANNOT_SAVE_GHOST
    TEX_WIDTH(aMenuLeftArrowTex),
    TEX_HEIGHT(aMenuLeftArrowTex), // RACE_MENU_LEFT_ARROW
    TEX_WIDTH(aMenuRightArrowTex),
    TEX_HEIGHT(aMenuRightArrowTex), // RACE_MENU_RIGHT_ARROW
};

void func_i3_8011AE70(void) {
    sMenuStateFlags = D_i3_801419B4 = 0;
}

void func_i3_8011AE88(void) {
    D_i3_801419A8 = D_i3_801419AC = 0;
}

extern s8 gGamePaused;
extern s32 gPlayerControlPorts[];
extern s32 D_i2_80106F10;
extern s32 sMenuStateFlags;
extern Controller gControllers[];
extern s32 gPlayerControlPorts[];
extern s32 gNumPlayers;
extern s32 gGameMode;
extern s32 gCourseIndex;
extern s16 D_800CD048;
extern s32 gTotalRacers;
extern s16 D_80115D50[];

void func_i3_8013BF50(s32);
void func_i3_8013C008(void);
void Save_SaveDeathRaceProfiles(void);

void func_i3_8011AEA0(void) {
    s32 i;

    if (sMenuStateFlags != 0) {
        if (sMenuStateFlags & MENU_STATE_PAUSE_GAME) {
            gGamePaused = true;
            func_800BB0C0(1);
            func_800BA8D8(12);
            func_80069700();
        }
        if (sMenuStateFlags & MENU_STATE_UNPAUSE_GAME) {
            gGamePaused = false;
            D_i2_80106F10 = 4;
            for (i = 0; i < gNumPlayers; i++) {
                gControllers[gPlayerControlPorts[i]].unk_72 = 1;
            }
            func_800BB0C0(0);
            func_800BA8D8(13);
        }
        if ((sMenuStateFlags & MENU_STATE_RACE_FINISH_SAVE) && !sRaceFinishSaveTriggered) {
            if (gGameMode == GAMEMODE_TIME_ATTACK) {
                if (gCourseIndex < COURSE_X_1) {
                    func_80089BD0();
                    func_i3_8013C008();
                }
                if (gCourseIndex < COURSE_EDIT_1) {
                    Save_SaveCourseRecordProfiles(gCourseIndex);
                }
            } else if (gGameMode == GAMEMODE_GP_RACE) {
                func_i3_8013BF50(gCourseIndex);
            } else if (gGameMode == GAMEMODE_DEATH_RACE) {
                func_80089BD0();
                Save_SaveDeathRaceProfiles();
            }
            sRaceFinishSaveTriggered = true;
        }
        if (!sMenuOptionTriggered && (D_i3_801419A6 == 0)) {
            if (sMenuStateFlags & MENU_STATE_RETRY) {
                func_80095144();
                D_800CD048 = 1;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_QUIT) {
                func_80095144();
                D_800CD048 = 2;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_CHANGE_MACHINE) {
                func_80095144();
                D_800CD048 = 7;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_CHANGE_COURSE) {
                func_80095144();
                D_800CD048 = 3;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_SETTINGS) {
                func_80095144();
                D_800CD048 = 15;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_100) {
                func_80095144();
                D_800CD048 = 6;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_GP_NEXT_COURSE) {
                if ((gNumPlayers == 1) && (gGameMode == GAMEMODE_GP_RACE)) {
                    for (i = 0; i < gTotalRacers; i++) {
                        D_80115D50[i] = gRacers[i].position;
                    }
                }
                func_80095144();
                D_800CD048 = 4;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_400) {
                func_80095144();
                D_800CD048 = 5;
                sMenuOptionTriggered = true;
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

extern GhostRacer* gFastestGhostRacer;
extern s16 gPlayerLives[];
extern s16 gRacersRemaining;

extern CourseRecordInfo* gCurrentCourseRecordInfo;
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

    gRacersRemaining = gTotalRacers;
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
            sMenuIsBusy = sRaceFinishSaveTriggered = D_i3_80141DCC = sMenuOptionTriggered = D_i3_801419A6 = D_i3_801419BC = D_80141900 =
                D_i3_80141D90 = 0;

    D_i3_80141D08 = D_i3_80141CC8 = 0.0f;
    D_i3_80141DC0 = D_i3_80141DB4 = 90;
    D_i3_80141DA0 = D_i3_80141D98 = 60;
    D_i3_80141DCC = 0;
    sPlayer1Lives = gPlayerLives[0];
    sRetireTexture = func_80078104(aRetireTex, TEX_SIZE(aRetireTex, sizeof(u8)), 0, 0, 0);
    sRetirePalette = func_80078104(aRetireTLUT, TEX_SIZE(aRetireTLUT, sizeof(u16)), 0, 0, 0);
    func_80078104(aMenuTextTLUT, 0x200, 0, 0, 0);
    func_80078104(aMenuRetryTex, TEX_SIZE(aMenuRetryTex, sizeof(u8)), 0, 1, 0);
    func_80078104(aMenuSettingsTex, TEX_SIZE(aMenuSettingsTex, sizeof(u8)), 0, 1, 0);
    func_80078104(aMenuQuitTex, TEX_SIZE(aMenuQuitTex, sizeof(u8)), 0, 1, 0);
    func_80078104(aMenuContinueTex, TEX_SIZE(aMenuContinueTex, sizeof(u8)), 0, 1, 0);

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        func_80078104(aMenuChangeMachineTex, TEX_SIZE(aMenuChangeMachineTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aBestTex, TEX_SIZE(aBestTex, sizeof(u16)), 0, 0, 0);
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        func_80078104(aMenuChangeMachineTex, TEX_SIZE(aMenuChangeMachineTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuChangeCourseTex, TEX_SIZE(aMenuChangeCourseTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuGhostSaveTex, TEX_SIZE(aMenuGhostSaveTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuOverwriteData1Tex, TEX_SIZE(aMenuOverwriteData1Tex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuSavedTex, TEX_SIZE(aMenuSavedTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuSavingTex, TEX_SIZE(aMenuSavingTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuYesTex, TEX_SIZE(aMenuYesTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuNoTex, TEX_SIZE(aMenuNoTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuNewGhostTex, TEX_SIZE(aMenuNewGhostTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuSavedGhostTex, TEX_SIZE(aMenuSavedGhostTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuCannotSaveGhostTex, TEX_SIZE(aMenuCannotSaveGhostTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuLeftArrowTex, TEX_SIZE(aMenuLeftArrowTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuRightArrowTex, TEX_SIZE(aMenuRightArrowTex, sizeof(u8)), 0, 1, 0);
        sLoserTexture = func_80078104(aLoserTex, TEX_SIZE(aLoserTex, sizeof(u8)), 0, 0, 0);
        sLoserPalette = func_80078104(aLoserTLUT, TEX_SIZE(aLoserTLUT, sizeof(u16)), 0, 0, 0);
        func_i3_80122C3C();
        if (gFastestGhostIndex >= 0) {
            D_i3_80141DD0 = gFastestGhostRacer->racer;
            D_i3_80141DD8 = D_i3_80141DD0->lapDistance;
            D_i3_80141DDC = gCurrentCourseRecordInfo->length * -1.0f;
        }
    }

    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P) || (gGameMode == GAMEMODE_VS_4P) ||
        (gGameMode == GAMEMODE_TIME_ATTACK)) {
        sWinnerTexture = func_80078104(aWinnerTex, TEX_SIZE(aWinnerTex, sizeof(u8)), 0, 0, 0);
        sWinnerPalette = func_80078104(aWinnerTLUT, TEX_SIZE(aWinnerTLUT, sizeof(u16)), 0, 0, 0);
    }
    if ((gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P) ||
        (gGameMode == GAMEMODE_VS_4P)) {
        func_80078104(aMenuChangeMachineTex, TEX_SIZE(aMenuChangeMachineTex, sizeof(u8)), 0, 1, 0);
        func_80078104(aMenuChangeCourseTex, TEX_SIZE(aMenuChangeCourseTex, sizeof(u8)), 0, 1, 0);
        func_80078104(D_F25D858, TEX_SIZE(D_F25D858, sizeof(u16)), 0, 0, 0);
        func_80078104(D_F25E060, TEX_SIZE(D_F25E060, sizeof(u16)), 0, 0, 0);
        func_80078104(D_F25E868, TEX_SIZE(D_F25E868, sizeof(u16)), 0, 0, 0);

        for (j = 0; j < 3; j++) {
            D_i3_80141B40[0][j] = 32;
            D_i3_80141B40[1][j] = 32;
            D_i3_80141B40[2][j] = 32;
            D_i3_80141B40[3][j] = 32;
            D_i3_80141B40[4][j] = 30;
            D_i3_80141B40[5][j] = 30;
            D_i3_80141B40[6][j] = 31;
            D_i3_80141B40[7][j] = 31;

            for (i = 0; i < gNumPlayers; i++) {
                D_i3_80141B40[i][j] = gRacers[i].character;
            }

            for (i = 0; i < 3; i++) {
                for (k = 1; k < 4; k++) {
                    if (i != k) {
                        if (D_i3_80141B40[i][j] == D_i3_80141B40[k][j]) {
                            D_i3_80141B40[k][j] = 32;
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
                    D_i3_80141AE0[i][j] = gCharacterPortraitTextures[D_i3_80141B40[i][j]];
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

extern Racer* gRacersByPosition[];
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

    if (!gGamePaused && (D_800CD010 == 0)) {
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
                if ((gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_A) &&
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
                    for (i = 0; i < gTotalRacers; i++) {
                        if ((D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == gRacers[i].character) &&
                            (!(gRacers[i].stateFlags & RACER_STATE_FLAGS_8000000))) {
                            gRacers[i].energy = 0.0f;
                            var_v1++;
                        }
                    }

                    if ((var_v1 == 0) && (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] < 30)) {
                        for (i = 0; i < gTotalRacers; i++) {
                            gRacers[i].energy /= 2.0f;
                        }
                    }
                    if (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == 30) {
                        gRacersByPosition[0]->energy = 0.0f;
                    }
                    if (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == 31) {
                        for (i = 0; i < gTotalRacers; i++) {
                            gRacers[i].energy = 0.0f;
                        }
                    }
                    if (D_i3_80141B40[D_i3_80141A50[playerNum][0]][0] == 32) {
                        for (i = 0; i < gTotalRacers; i++) {
                            gRacers[i].energy /= 2.0f;
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
                if (gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_B) {
                    D_i3_80141A68[playerNum] = 0;
                    D_i3_80141AA0[playerNum].x = D_i3_80141AD0.x;
                    D_i3_80141AA0[playerNum].y = D_i3_80141AD0.y;
                    D_i3_80141AA0[playerNum].z = D_i3_80141AD0.z;
                }
            }
        }
        gSPDisplayList(gfx++, D_80149D0);
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, aStartStopGuideTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
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
                gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
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
                gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
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
Gfx* func_i3_DrawBlankTimeHundredths(Gfx*, s32, s32);

Gfx* func_i3_8011D8F0(Gfx* gfx, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return func_i3_DrawBlankTimeHundredths(gfx, left + 8, top);
}

Gfx* func_i3_DrawBlankTimeThousandths(Gfx*, s32, s32);

Gfx* func_i3_8011DA44(Gfx* gfx, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return func_i3_DrawBlankTimeThousandths(gfx, left + 8, top);
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

    return func_i3_DrawRaceTimeInterval(gfx, time, left, top, 1.0f);
}

extern s32 gTotalLapCount;
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
        for (i = 1; i <= gTotalLapCount; i++) {
            top = ((i - 1) * D_i3_80141BA8) + D_i3_80141BA4 + 3;
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (15.0f * scale)) << 2,
                                    (s32) (top + (11.0f * scale)) << 2, 0, 0, 0, (s32) (4096.0f / scale),
                                    (s32) (1024.0f / scale));
        }
    }
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left += 0x11;

    if (left >= 0) {
        for (i = 1; i <= gTotalLapCount; i++) {
            top = ((i - 1) * D_i3_80141BA8) + D_i3_80141BA4 + 3;

            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (7.0f * scale)) << 2,
                                    (s32) (top + (11.0f * scale)) << 2, 0, 0, (i * 12) << 5, (s32) (4096.0f / scale),
                                    (s32) (1024.0f / scale));
        }
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, aHudTimeTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left = D_i3_80141BA0 - D_i3_80141B9C;
    top = (gTotalLapCount * D_i3_80141BA8) + (D_i3_80141BA8 / 2) + D_i3_80141BA4;
    if (left > 0) {
        gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (23.0f * scale)) << 2,
                                (s32) (top + (15.0f * scale)) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (sp144 = 0; sp144 < gTotalLapCount; sp144++) {
        top = (sp144 * D_i3_80141BA8) + D_i3_80141BA4;
        if (D_i3_80141B88[arg1] < ((D_i3_80141BB4 * sp144) + D_i3_80141BB0)) {
            top += (((D_i3_80141BB4 * sp144) + D_i3_80141BB0) - D_i3_80141B88[arg1]) * D_i3_80141BB8;
        }
        if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
            ((((D_i3_80141BB4 * sp144) + D_i3_80141BB0) - D_i3_80141B88[arg1]) == 1) && (D_800CD010 == 0)) {
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
            gfx = func_i3_DrawTimerScisThousandths(gfx, gRacers[arg1].lapTimes[sp144],
                                                   D_i3_80141BA0 + D_i3_80141BAC + D_i3_80141B9C, top, 1.0f);
        }
    }

    top = (gTotalLapCount * D_i3_80141BA8) + (D_i3_80141BA8 / 2) + D_i3_80141BA4;
    if (D_i3_80141B88[arg1] < ((D_i3_80141BB4 * sp144) + D_i3_80141BB0)) {
        top += (((D_i3_80141BB4 * gTotalLapCount) + D_i3_80141BB0) - D_i3_80141B88[arg1]) * D_i3_80141BB8;
    }
    if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
        ((((D_i3_80141BB4 * gTotalLapCount) + D_i3_80141BB0) - D_i3_80141B88[arg1]) == 1) && (D_800CD010 == 0)) {
        func_800BA8D8(0x22);
    }
    if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
        ((((D_i3_80141BB4 * (gTotalLapCount + 1)) + D_i3_80141BB0) - D_i3_80141B88[arg1]) == 1) && (D_800E5FE2 == 1) &&
        (D_800CD010 == 0)) {
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
        gfx = func_i3_DrawTimerScisThousandths(gfx, gRacers[arg1].raceTime,
                                               D_i3_80141BA0 + D_i3_80141BAC + D_i3_80141B9C, top, 1.0f);
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
        if (i == gTotalRacers) {
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
            character = gRacersByPosition[i]->character;
            gDPLoadTextureBlock(gfx++, gCharacterPortraitTextures[character], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * scale) << 2,
                                    (s32) (top + 32.0f * scale) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                    (s32) (1024.0f / scale));

            if ((gRacersByPosition[i]->id == 0) && ((gGameFrameCount % 20) >= 5)) {
                gDPPipeSync(gfx++);
                gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
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
    gDPLoadTextureBlock(gfx++, gCharacterPortraitTextures[character], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * arg5) << 2,
                            (s32) (top + 32.0f * arg5) << 2, 0, 0, 0, (s32) (1024.0f / arg5), (s32) (1024.0f / arg5));

    if ((arg1 == 0) && ((gGameFrameCount % 20) >= 5)) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
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

    if (gRacers[arg1].position == 1) {
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

        for (i = 0; i < gTotalRacers; i++) {
            sp60[i] = i;
        }

        for (i = 0; i < gTotalRacers - 1; i++) {
            for (j = i + 1; j < gTotalRacers; j++) {
                if (sp60[i] >= gNumPlayers) {
                    temp = sp60[i];
                    sp60[i] = sp60[j];
                    sp60[j] = temp;
                } else if ((sp60[j] < gNumPlayers) && (gRacers[sp60[j]].position < gRacers[sp60[i]].position)) {
                    temp = sp60[i];
                    sp60[i] = sp60[j];
                    sp60[j] = temp;
                }
            }
        }

        if (arg1 == sp60[0]) {
            if (D_i3_80141BE0[arg1] == 60) {

                if (gRacers[arg1].stateFlags & RACER_STATE_FLAGS_8000000) {
                    if (D_800CD010 == 0) {
                        func_800BAFA4(0x13);
                    }
                } else if (D_800CD010 == 0) {
                    func_800BAFA4(0x11);
                }
                for (i = 0; i < gNumPlayers; i++) {
                    if ((gRacers[i].stateFlags & RACER_STATE_FLAGS_8000000) ||
                        (gRacers[arg1].stateFlags & RACER_STATE_FLAGS_2000000)) {
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

    if (gRacers[arg1].position == 1) {
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

Gfx* func_i3_DrawFinalLap(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;

    gSPDisplayList(gfx++, D_8014940);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gDPLoadTLUT_pal256(gfx++, aFinalLapPalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 1; i++) {

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, (aFinalLapTex + (i * 0x800)), G_IM_FMT_CI, G_IM_SIZ_8b, 128, 16, 0,
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
    return func_i3_DrawFinalLap(gfx, left, top, scale);
}

Gfx* func_i3_DrawBoosterOk(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;
    f32 blockTop;
    f32 temp;
    s32 pad[2];

    gSPDisplayList(gfx++, D_8014940);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gDPLoadTLUT_pal256(gfx++, aBoosterOkPalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    blockTop = top;

    for (i = 0; i < 2; i++) {

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, (aBoosterOkTex + (i * 0x280)), G_IM_FMT_CI, G_IM_SIZ_8b, 80, 8, 0,
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

Gfx* func_i3_801216C0(Gfx* gfx, s32 playerNum) {
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
            switch (playerNum) {
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
            switch (playerNum) {
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
    return func_i3_DrawBoosterOk(gfx, left, top, scale);
}

void func_i3_801217F0(s32 playerIndex) {
    D_i3_80141C00[playerIndex] = gRacers[playerIndex].speed * 0.05f;
    D_i3_80141C10[playerIndex] = 0.0f;
    D_i3_80141D78[playerIndex] = 0;
    D_i3_80141BF0[playerIndex] = 0;
}

extern GfxPool D_1000000;
extern unk_struct_1DC D_800E5220[];
extern GfxPool* gGfxPool;

Gfx* func_i3_80121860(Gfx* gfx, s32 playerIndex) {
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
    s32 angle;

    temp_fv0 = D_800E5220[playerIndex].unk_5C.x.x;
    temp_fv1 = D_800E5220[playerIndex].unk_5C.x.y;
    temp_fa1 = D_800E5220[playerIndex].unk_5C.x.z;
    sqrtf(SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa1));

    if (D_i3_80141BF0[playerIndex] < 11) {
        spC0 = 0 * 0;
        spC4 = 0 * -2;
        spC8 = 0 * 2 + 180.0f;
    } else if (D_i3_80141BF0[playerIndex] >= 30) {
        spC0 = 20.0f * 0;
        spC4 = 20.0f * -2;
        spC8 = 20.0f * 2 + 180.0f;
    } else {
        temp_fv0_2 = D_i3_80141BF0[playerIndex] - 10;
        spC0 = temp_fv0_2 * 0;
        spC4 = temp_fv0_2 * -2;
        spC8 = (temp_fv0_2 * 2) + 180.0f;
    }

    D_i3_80141C10[playerIndex] += D_i3_80141C00[playerIndex];
    D_i3_80141C00[playerIndex] *= 0.92f;
    if (D_i3_80141C00[playerIndex] < 0.08f) {
        D_i3_80141C00[playerIndex] = 0.08f;
    }
    while (D_i3_80141C10[playerIndex] < 0.0f) {
        D_i3_80141C10[playerIndex] += M_TWO_PI;
    }
    while (D_i3_80141C10[playerIndex] > M_TWO_PI) {
        D_i3_80141C10[playerIndex] -= M_TWO_PI;
    }
    if ((D_i3_80141C00[playerIndex] <= 0.08f) && (D_i3_80141C10[playerIndex] >= (0.92f * M_TWO_PI))) {
        D_i3_80141C10[playerIndex] = (0.92f * M_TWO_PI);
        D_i3_80141C00[playerIndex] = 0.0f;
    }
    temp = D_i3_80141C10[playerIndex];
    angle = RAD_TO_FZXANG(temp);
    spA0 = SIN(angle);
    spA4 = -COS(angle);
    spAC = COS(angle);
    spB0 = SIN(angle);

    gfx = func_i3_8012EE90(gfx, playerIndex);

    gSPMatrix(gfx++, &D_1000000.unk_20008[playerIndex], G_MTX_PUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_20108[playerIndex], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_400A258);
    gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BACK);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    func_8006BC84(gGfxPool->unk_21988, NULL, 0.07f, 0.07f, 0.07f, 0, spA0, spA4, 0, spAC, spB0, spC0, spC4, spC8);
    gSPMatrix(gfx++, gGfxPool->unk_21988, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, aFinishDL);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);

    D_i3_80141BE0[playerIndex]++;
    if (D_i3_80141BE0[playerIndex] == 2) {
        if ((gGameMode == GAMEMODE_TIME_ATTACK) || (gGameMode == GAMEMODE_GP_RACE)) {
            if (gTotalLapCount == 3) {
                sMenuStateFlags |= MENU_STATE_RACE_FINISH_SAVE;
            }
        } else if (gGameMode == GAMEMODE_DEATH_RACE) {
            sMenuStateFlags |= MENU_STATE_RACE_FINISH_SAVE;
        }
    }

    if (D_i3_80141BE0[playerIndex] == 60) {
        if (D_800CD010 == 0) {
            func_800BAFA4(0x11);
        }
        for (i = 0; i < gNumPlayers; i++) {
            if ((gRacers[i].stateFlags & RACER_STATE_FLAGS_8000000) ||
                (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000)) {
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

    if (D_i3_80141C00[playerIndex] == 0.0f) {
        D_i3_80141BF0[playerIndex]++;
        if (D_i3_80141BF0[playerIndex] >= 600) {
            D_i3_80141BF0[playerIndex] = 600;
        }
    }
    return gfx;
}

void func_i3_80121E28(s32 arg0) {
    D_i3_80141C00[arg0] = 0.25f;
    D_i3_80141BF0[arg0] = 0;
    D_i3_80141C10[arg0] = 0.0f;
    D_i3_80141D0C = 0.001f;
}

Gfx* func_i3_80121E70(Gfx* gfx, s32 arg1) {
    s32 pad[7];
    f32 sp88;
    f32 sp84;
    f32 sp80;
    s32 row;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 angle;
    s32 alpha;
    f32 sp64;
    f32 temp_fv0_2;
    f32 sp5C;

    temp_fv0 = D_800E5220[arg1].unk_5C.x.x;
    temp_fv1 = D_800E5220[arg1].unk_5C.x.y;
    temp_fa1 = D_800E5220[arg1].unk_5C.x.z;
    sqrtf(SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa1));
    if ((gNumPlayers == 1) && (D_i3_80141C00[arg1] <= 0.02f)) {
        gControllers[gGameFrameCount % 4].unk_78 = 1;
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

    if (gRacers[arg1].stateFlags & RACER_STATE_FLAGS_2000000) {
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

    angle = RAD_TO_FZXANG(D_i3_80141C10[arg1]);

    sp5C = SIN(angle);
    sp64 = -COS(angle);
    gfx = func_i3_8012EE90(gfx, arg1);
    gSPMatrix(gfx++, &D_1000000.unk_20008[arg1], G_MTX_PUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_20108[arg1], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_400A258);

    D_i3_80141D0C += 0.00005f;
    if (D_i3_80141D0C >= 0.009f) {
        D_i3_80141D0C = 0.009f;
        if ((gControllers[gPlayerControlPorts[arg1]].buttonPressed & (BTN_A | BTN_START)) &&
            (D_i3_80141BF0[arg1] >= 60) && !sMenuIsBusy) {
            if (D_800CD010 == 0) {
                func_800BB048();
            }
            if (D_800CD010 == 0) {
                func_8007E0CC();
            }
            sMenuIsBusy = true;
            sMenuStateFlags |= MENU_STATE_QUIT;
        }
    }

    func_8006BC84(gGfxPool->unk_21988, NULL, D_i3_80141D0C, D_i3_80141D0C, D_i3_80141D0C, sp5C, 0.0f, sp64, 0.0f,
                  1.0f, 0.0f, sp80, sp84, sp88);
    gSPMatrix(gfx++, gGfxPool->unk_21988, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, aExecuteGameoverDL);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);

    D_i3_80141BE0[arg1]++;
    return gfx;
}

Gfx* func_i3_8012266C(Gfx* gfx, s32 playerNum) {
    s32 pad;
    s32 left;
    s32 top;

    if (gNumPlayers < 3) {
        switch (playerNum) {
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
        switch (playerNum) {
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

    return func_i3_DrawTimerScisThousandths(gfx, gRacers[playerNum].raceTime, left, top, 1.0f);
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
    s32 stickY = gControllers[gPlayerControlPorts[playerNum]].stickY;

    if (stickY > 50) {
        var_v0 = -1;
        D_i3_80141D90++;
    } else if (stickY < -50) {
        var_v0 = 1;
        D_i3_80141D90++;
    } else {
        if (gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_UP) {
            var_v0 = -1;
            D_i3_80141D90 = 1;
        } else if (gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_DOWN) {
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
    s32 stickX = gControllers[gPlayerControlPorts[playerNum]].stickX;

    if (stickX > 50) {
        var_v0 = -1;
        D_i3_80141D90++;
    } else if (stickX < -50) {
        var_v0 = 1;
        D_i3_80141D90++;
    } else {
        if (gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_LEFT) {
            var_v0 = -1;
            D_i3_80141D90 = 1;
        } else if (gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_RIGHT) {
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

extern Ghost gGhosts[];
extern Ghost* gFastestGhost;

void func_i3_80122C3C(void) {

    if (gFastestGhostRacer == NULL) {
        gFastestGhostIndex = -1;
        gFastestGhostTime = MAX_TIMER;
    } else {
        gFastestGhostIndex = gFastestGhostRacer->ghost - gGhosts;
        gFastestGhostTime = gFastestGhostRacer->ghost->raceTime;
    }
    if (gFastestGhost == NULL) {
        sFastestGhostIndex = -1;
        return;
    }
    sFastestGhostIndex = gFastestGhost - gGhosts;
    sFastestGhostTime = gFastestGhost->raceTime;
}

void Save_SaveGhost(s32, Ghost*);

s32 func_i3_80122CEC(void) {
    func_i3_80122C3C();
    if (sFastestGhostIndex == -1) {
        sCannotSaveGhost = true;
        sSaveGhostMenuOpen = false;
        return -1;
    }
    if (Save_LoadGhostInfo(&gSavedGhostInfo) != 0) {
        if (gCourseIndex < COURSE_EDIT_1) {
            Save_SaveGhost(gCourseIndex, gFastestGhost);
        }
        sSaveGhostMenuOpen = false;
        sGhostSaveTimer = 60;
        return 0;
    }
    return 0;
}

s32 func_i3_80122D88(void) {
    sCannotSaveGhost = false;
    if (gCourseIndex >= COURSE_X_1) {
        sCannotSaveGhost = true;
        return 0;
    }
    func_i3_80122C3C();
    if (sFastestGhostIndex == -1) {
        sCannotSaveGhost = true;
        sSaveGhostMenuOpen = false;
        return -1;
    }
    if (Save_LoadGhostInfo(&gSavedGhostInfo) != 0) {
        return 0;
    }
    if ((gSavedGhostInfo.courseIndex == gCourseIndex) && (sFastestGhostTime >= gSavedGhostInfo.raceTime)) {
        sCannotSaveGhost = true;
    }
    return 0;
}

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
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));
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
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SAVING, 95, 112);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    D_i3_80141DCC = 0;
    return gfx;
}

extern char* gCurrentTrackName;
extern char* gTrackNames[];

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

    gfx = func_i3_DrawTimerScisThousandths(gfx, sFastestGhostTime, 115, 77, 1.0f);
    gfx = func_i3_DrawTimerScisThousandths(gfx, gSavedGhostInfo.raceTime, 115, 141, 1.0f);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = Font_DrawString(gfx, 124 - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_6, 1) / 2), 78, gCurrentTrackName,
                          1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, 123 - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_6, 1) / 2), 77, gCurrentTrackName,
                          1, FONT_SET_6, 0);

    if ((gSavedGhostInfo.courseIndex >= COURSE_MUTE_CITY) && (gSavedGhostInfo.courseIndex < COURSE_EDIT_1)) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
        gfx = Font_DrawString(gfx,
                              124 - (Font_GetStringWidth(gTrackNames[gSavedGhostInfo.courseIndex], FONT_SET_6, 1) / 2),
                              142, gTrackNames[gSavedGhostInfo.courseIndex], 1, FONT_SET_6, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx,
                              123 - (Font_GetStringWidth(gTrackNames[gSavedGhostInfo.courseIndex], FONT_SET_6, 1) / 2),
                              141, gTrackNames[gSavedGhostInfo.courseIndex], 1, FONT_SET_6, 0);
    } else {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
        gfx = Font_DrawString(gfx, 124 - (Font_GetStringWidth(gSavedGhostInfo.trackName, FONT_SET_6, 1) / 2), 142,
                              gSavedGhostInfo.trackName, 1, FONT_SET_6, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, 123 - (Font_GetStringWidth(gSavedGhostInfo.trackName, FONT_SET_6, 1) / 2), 141,
                              gSavedGhostInfo.trackName, 1, FONT_SET_6, 0);
    }

    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
#ifdef VERSION_JP
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_NEW_GHOST, 83, 45);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SAVED_GHOST, 51, 109);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_OVERWRITE_DATA1, 51, 171);
#else
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_NEW_GHOST, 43, 45);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SAVED_GHOST, 11, 109);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_OVERWRITE_DATA1, 21, 171);
#endif
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
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
        if (sOverwriteGhostOption == 0) {
            if (D_800CD010 == 0) {
                func_800BA8D8(0x10);
            }
            sSaveGhostMenuOpen = false;
        } else {
            if (D_800CD010 == 0) {
                func_800BA8D8(0x21);
            }
            Save_SaveGhost(gCourseIndex, gFastestGhost);
            sSaveGhostMenuOpen = false;
            sGhostSaveTimer = 60;
        }
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
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
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));
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
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));
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
    gfx = Font_DrawScaledString(gfx, 215, (sRaceMenuOptionIndex * 12) + 157, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);

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
        if (!sMenuIsBusy) {
            sRaceMenuOptionIndex = func_i3_801228F8(0, sRaceMenuOptionIndex, 5);
            // Skip over save ghost option when greyed out
            if ((sRaceMenuOptionIndex == TIME_ATTACK_SAVE_GHOST) && (sCannotSaveGhost)) {
                if ((gControllers[gPlayerControlPorts[0]].stickY > 40) ||
                    (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_UP)) {
                    sRaceMenuOptionIndex--;
                } else {
                    sRaceMenuOptionIndex++;
                }
            }
        }
        if ((gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) && !sMenuIsBusy &&
            (D_i3_80141DCC == 0)) {
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_COURSE;
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
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));
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
    gfx = Font_DrawScaledString(gfx, 215, (D_i3_80141D9C * 15) + 157, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
    if ((D_i3_80141DA0 == 0) && !sMenuIsBusy) {
        D_i3_80141D9C = func_i3_801228F8(0, D_i3_80141D9C, 4);
        if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_COURSE;
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
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));
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
    gfx = Font_DrawScaledString(gfx, 215, (sRaceMenuOptionIndex * 15) + 157, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
    if ((D_i3_80141D98 == 0) && !sMenuIsBusy) {
        sRaceMenuOptionIndex = func_i3_801228F8(0, sRaceMenuOptionIndex, 4);
        if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_COURSE;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
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
    if (gRacers[0].stateFlags & RACER_STATE_FLAGS_2000000) {
        gfx = func_i3_DrawBeveledBox(gfx, 210, 137, 300, 205, 0, 0, 0, 180);
    } else {
        gfx = func_i3_DrawBeveledBox(gfx, 210, 137, 300, 205, 0, 0, 200, 127);
    }
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));
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
    gfx = Font_DrawScaledString(gfx, 215, (sRaceMenuOptionIndex * 15) + 157, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
    if ((D_i3_80141D98 == 0) && !sMenuIsBusy) {
        sRaceMenuOptionIndex = func_i3_801228F8(0, sRaceMenuOptionIndex, 3);
        if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
                    break;
            }
        }
    }
    return gfx;
}

Gfx* func_i3_DrawGeneralPause(Gfx* gfx) {
    s32 pad[2];

    if (sPauseMenuScissorBoxTimer > 0) {
        sPauseMenuScissorBoxTimer -= 8;
    } else {
        sPauseMenuScissorBoxTimer = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sPauseMenuScissorBoxTimer + 100, sPauseMenuScissorBoxTimer + 41, 230 - sPauseMenuScissorBoxTimer,
                  197 - sPauseMenuScissorBoxTimer);
    gfx = func_i3_DrawBeveledBox(gfx, 120, 61, 210, 177, 0, 0, 0, 220);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));

    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_CONTINUE);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CONTINUE, 140, 80);
    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_RETRY);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 140, 95);
    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_SETTINGS);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 140, 110);
    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_QUIT);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 140, 155);
    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_CHANGE_MACHINE);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 140, 125);
    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_CHANGE_COURSE);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_COURSE, 140, 140);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = Font_DrawScaledString(gfx, 125, (sPauseMenuOptionIndex * 15) + 97, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = Font_DrawString(gfx, 166 - (Font_GetStringWidth("PAUSE", FONT_SET_6, 1) / 2), 78, "PAUSE", 1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, 165 - (Font_GetStringWidth("PAUSE", FONT_SET_6, 1) / 2), 77, "PAUSE", 1, FONT_SET_6, 0);
    if ((sPauseMenuScissorBoxTimer == 0) && !sMenuIsBusy) {
        sPauseMenuOptionIndex = func_i3_801228F8(sPausePlayerNum, sPauseMenuOptionIndex, 5);
        if (gControllers[gPlayerControlPorts[sPausePlayerNum]].buttonPressed & (BTN_A | BTN_START)) {
            switch (sPauseMenuOptionIndex) {
                case PAUSE_GENERAL_CONTINUE:
                    sMenuStateFlags |= MENU_STATE_UNPAUSE_GAME;
                    break;
                case PAUSE_GENERAL_RETRY:
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
                    break;
                case PAUSE_GENERAL_QUIT:
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
                    break;
                case PAUSE_GENERAL_CHANGE_MACHINE:
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
                    break;
                case PAUSE_GENERAL_CHANGE_COURSE:
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_COURSE;
                    break;
                case PAUSE_GENERAL_SETTINGS:
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
                    break;
            }
        }
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

Gfx* func_i3_DrawDeathRacePause(Gfx* gfx) {
    s32 pad[2];

    if (sPauseMenuScissorBoxTimer > 0) {
        sPauseMenuScissorBoxTimer -= 8;
    } else {
        sPauseMenuScissorBoxTimer = 0;
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sPauseMenuScissorBoxTimer + 100, sPauseMenuScissorBoxTimer + 56, 230 - sPauseMenuScissorBoxTimer,
                  166 - sPauseMenuScissorBoxTimer);
    gfx = func_i3_DrawBeveledBox(gfx, 120, 61, 210, 161, 0, 0, 0, 220);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));

    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_DEATH_RACE_CONTINUE);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CONTINUE, 140, 80);
    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_DEATH_RACE_RETRY);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 140, 95);
    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_DEATH_RACE_SETTINGS);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 140, 110);
    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_DEATH_RACE_QUIT);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 140, 140);
    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_DEATH_RACE_CHANGE_MACHINE);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 140, 125);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = Font_DrawScaledString(gfx, 125, (sPauseMenuOptionIndex * 15) + 97, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = Font_DrawString(gfx, 166 - (Font_GetStringWidth("PAUSE", FONT_SET_6, 1) / 2), 78, "PAUSE", 1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, 165 - (Font_GetStringWidth("PAUSE", FONT_SET_6, 1) / 2), 77, "PAUSE", 1, FONT_SET_6, 0);
    if ((sPauseMenuScissorBoxTimer == 0) && !sMenuIsBusy) {
        sPauseMenuOptionIndex = func_i3_801228F8(sPausePlayerNum, sPauseMenuOptionIndex, 4);
        if (gControllers[gPlayerControlPorts[sPausePlayerNum]].buttonPressed & (BTN_A | BTN_START)) {
            switch (sPauseMenuOptionIndex) {
                case PAUSE_DEATH_RACE_CONTINUE:
                    sMenuStateFlags |= MENU_STATE_UNPAUSE_GAME;
                    break;
                case PAUSE_DEATH_RACE_RETRY:
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
                    break;
                case PAUSE_DEATH_RACE_QUIT:
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
                    break;
                case PAUSE_DEATH_RACE_CHANGE_MACHINE:
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
                    break;
                case PAUSE_DEATH_RACE_SETTINGS:
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
                    break;
            }
        }
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

void func_i3_TriggerLivesDecrease(void);

Gfx* func_i3_DrawGpRacePause(Gfx* gfx) {
    s32 pad[2];

    if (sPauseMenuScissorBoxTimer > 0) {
        sPauseMenuScissorBoxTimer -= 8;
    } else {
        sPauseMenuScissorBoxTimer = 0;
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sPauseMenuScissorBoxTimer + 100, sPauseMenuScissorBoxTimer + 56, 220 - sPauseMenuScissorBoxTimer,
                  150 - sPauseMenuScissorBoxTimer);
    gfx = func_i3_DrawBeveledBox(gfx, 120, 61, 200, 145, 0, 0, 0, 220);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));

    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GP_CONTINUE);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_CONTINUE, 140, 80);
    if (sPlayer1Lives <= 0) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    } else {
        gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GP_RETRY);
    }
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 140, 95);
    gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GP_QUIT);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 140, 125);
    if (sPlayer1Lives <= 0) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    } else {
        gfx = func_i3_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GP_SETTINGS);
    }
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 140, 110);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = Font_DrawScaledString(gfx, 125, (sPauseMenuOptionIndex * 15) + 97, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = Font_DrawString(gfx, 162 - (Font_GetStringWidth("PAUSE", FONT_SET_6, 1) / 2), 78, "PAUSE", 1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, 161 - (Font_GetStringWidth("PAUSE", FONT_SET_6, 1) / 2), 77, "PAUSE", 1, FONT_SET_6, 0);
    if ((sPauseMenuScissorBoxTimer == 0) && !sMenuIsBusy) {
        sPauseMenuOptionIndex = func_i3_801228F8(sPausePlayerNum, sPauseMenuOptionIndex, 3);
        if (((sPauseMenuOptionIndex == 1) || (sPauseMenuOptionIndex == 2)) && (sPlayer1Lives <= 0)) {
            if ((gControllers[gPlayerControlPorts[0]].stickY > 40) ||
                (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_UP)) {
                sPauseMenuOptionIndex = 0;
            } else {
                sPauseMenuOptionIndex = 3;
            }
        }
        if (gControllers[gPlayerControlPorts[sPausePlayerNum]].buttonPressed & (BTN_A | BTN_START)) {
            switch (sPauseMenuOptionIndex) {
                case PAUSE_GP_CONTINUE:
                    sMenuStateFlags |= MENU_STATE_UNPAUSE_GAME;
                    break;
                case PAUSE_GP_RETRY:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].id < gNumPlayers)) {
                        gPlayerLives[gRacers[0].id]--;
                        if (gPlayerLives[gRacers[0].id] >= 0) {
                            func_i3_TriggerLivesDecrease();
                        }
                        if (D_800CD010 == 0) {
                            func_800BA8D8(0x2C);
                        }
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
                    break;
                case PAUSE_GP_QUIT:
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
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
                    break;
                case PAUSE_GP_SETTINGS:
                    if (D_800CD010 == 0) {
                        func_800BB0C0(2);
                    }
                    if (D_800CD010 == 0) {
                        func_800BB048();
                    }
                    if (D_800CD010 == 0) {
                        func_8007E0CC();
                    }
                    if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].id < gNumPlayers)) {
                        gPlayerLives[gRacers[0].id]--;
                        if (gPlayerLives[gRacers[0].id] >= 0) {
                            func_i3_TriggerLivesDecrease();
                        }
                        if (D_800CD010 == 0) {
                            func_800BA8D8(0x2C);
                        }
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
                    break;
            }
        }
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

extern s16 D_800E5FE4;

Gfx* func_i3_80126B40(Gfx* gfx, s32 playerNum) {
    s32 i;
    s32 left;
    s32 top;
    s32 speed;
    s32 speedRemainder;
    s32 digit;
    s32 digitMask;

    switch (gNumPlayers) {
        case 1:
            if (gGameMode == GAMEMODE_TIME_ATTACK) {
                left = 0x82;
                top = 0xC0;
            } else {
                left = 0x28;
                top = 0x44;
            }
            break;
        case 2:
            left = 0xDC;
            switch (playerNum) {
                case 0:
                    top = 0x5C;
                    break;
                case 1:
                    top = 0xCC;
                    break;
            }
            break;
        case 3:
        case 4:
            switch (playerNum) {
                case 0:
                    left = 0x51;
                    top = 0x62;
                    break;
                case 1:
                    left = 0x51;
                    top = 0xD2;
                    break;
                case 2:
                    left = 0xE1;
                    top = 0x62;
                    break;
                case 3:
                    left = 0xE1;
                    top = 0xD2;
                    break;
            }
            break;
    }
    top += D_i3_80141B9C;
    digitMask = 1000;
    speedRemainder = speed = Math_Round(gRacers[playerNum].maxSpeed * 21.6f);

    gDPPipeSync(gfx++);

    if (gNumPlayers == 1) {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    } else {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    }

    gfx = func_i3_8011B41C(gfx, left, top, left + 71, top + 16, 0, 0, 0, 255);
    gSPDisplayList(gfx++, D_80149D0);
    gDPLoadTextureBlock(gfx++, D_303AA70, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPScisTextureRectangle(gfx++, (left + 2) << 2, (top - 16) << 2, (left + 65) << 2, (top - 1) << 2, 0, 0, 0, 1 << 12,
                            1 << 10);

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);

    if (D_800E5FE4 != 0) {
        gfx = func_8007F090(gfx, 255, 0, 0);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    }
    gDPLoadTextureBlock(gfx++, D_303B270, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 160, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < 4; i++) {
        digit = speedRemainder / digitMask;
        if ((i != 3) && (digit == 0) && (speed == speedRemainder)) {
            speedRemainder %= digitMask;
            digitMask /= 10;
        } else {
            gSPScisTextureRectangle(gfx++, (left + (i * 12)) << 2, top << 2, (left + (i * 12) + 11) << 2,
                                    (top + 15) << 2, 0, 0, (digit * 16) << 5, 1 << 10, 1 << 10);
            speedRemainder %= digitMask;
            digitMask /= 10;
        }
    }

    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, D_303C170, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPScisTextureRectangle(gfx++, (left + (i * 12)) << 2, top << 2, (left + (i * 12) + 19) << 2, (top + 15) << 2, 0, 0,
                            0, 1 << 10, 1 << 10);

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

    temp_ra = Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 1);

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
    gfx = Font_DrawString(gfx, (arg1 - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 1) / 2)) + 2, arg2 + 2,
                          gCurrentTrackName, 1, FONT_SET_3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, arg1 - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 1) / 2), arg2,
                          gCurrentTrackName, 1, FONT_SET_3, 0);
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

    temp_ra = Font_GetStringWidth("TIME ATTACK", FONT_SET_3, 1);

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
    gfx = Font_DrawString(gfx, (arg1 - (Font_GetStringWidth("TIME ATTACK", FONT_SET_3, 1) / 2)) + 2, arg2 + 2,
                          "TIME ATTACK", 1, FONT_SET_3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, arg1 - (Font_GetStringWidth("TIME ATTACK", FONT_SET_3, 1) / 2), arg2, "TIME ATTACK", 1,
                          FONT_SET_3, 0);
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

    gfx = func_i3_DrawTimerScisThousandths(gfx, gCurrentCourseRecordInfo->timeRecord[0],
                                           ((s32) (var_t2 + var_t4) / 2) - 60, (s32) (var_t3 + var_t5) / 2, 1.0f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);

    gfx = Font_DrawString(gfx, arg1 - 39, arg2 - 1, "BEST TIME", 1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, arg1 - 41, arg2 - 3, "BEST TIME", 1, FONT_SET_6, 0);
    gfx = Font_DrawString(gfx, arg1 + 19, arg2 + 16, gCurrentCourseRecordInfo->name[0], 1, 1, 0);
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

    gfx = func_i3_DrawTimerScisThousandths(gfx, gCurrentCourseRecordInfo->timeRecord[0],
                                           ((s32) (var_t2 + var_t4) / 2) - 35, (s32) (var_t3 + var_t5) / 2, 1.0f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);

    gfx = Font_DrawString(gfx, arg1 - 39, arg2 - 1, "BEST TIME", 1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, arg1 - 41, arg2 - 3, "BEST TIME", 1, FONT_SET_6, 0);
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

    if (gGameMode == GAMEMODE_GP_RACE) {
        sp38 = Font_GetStringWidth("GP RACE", FONT_SET_3, 1);
        sp3C = Font_GetStringWidth(sDifficultyNames[gDifficulty], 3, 1);
    } else if (gGameMode == GAMEMODE_PRACTICE) {
        sp38 = Font_GetStringWidth("PRACTICE", FONT_SET_3, 1);
        sp3C = Font_GetStringWidth(sDifficultyNames[gDifficulty], 3, 1);
    } else if (gGameMode == GAMEMODE_DEATH_RACE) {
        sp38 = Font_GetStringWidth("DEATH RACE", FONT_SET_3, 1);
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

    if (gGameMode == GAMEMODE_DEATH_RACE) {
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

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        gfx = func_i3_DrawBeveledBox(gfx, temp_t0 - 7, arg2 - 35, temp_t1 + 7, arg2 - 13, 0, 220, 0, 200);
    } else {
        gfx = func_i3_DrawBeveledBox(gfx, temp_t0 - 7, arg2 - 35, temp_t1 + 7, arg2 + 3, 0, 220, 0, 200);
    }

    if (gGameMode == GAMEMODE_GP_RACE) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, (arg1 - (Font_GetStringWidth("GP RACE", FONT_SET_3, 1) / 2)) + 2, arg2 - 14,
                              "GP RACE", 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, arg1 - (Font_GetStringWidth("GP RACE", FONT_SET_3, 1) / 2), arg2 - 16, "GP RACE", 1,
                              FONT_SET_3, 0);
    } else if (gGameMode == GAMEMODE_PRACTICE) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, (arg1 - (Font_GetStringWidth("PRACTICE", FONT_SET_3, 1) / 2)) + 2, arg2 - 14,
                              "PRACTICE", 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, arg1 - (Font_GetStringWidth("PRACTICE", FONT_SET_3, 1) / 2), arg2 - 16, "PRACTICE",
                              1, FONT_SET_3, 0);
    } else if (gGameMode == GAMEMODE_DEATH_RACE) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, (arg1 - (Font_GetStringWidth("DEATH RACE", FONT_SET_3, 1) / 2)) + 2, arg2 - 14,
                              "DEATH RACE", 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, arg1 - (Font_GetStringWidth("DEATH RACE", FONT_SET_3, 1) / 2), arg2 - 16,
                              "DEATH RACE", 1, FONT_SET_3, 0);
    }

    if (gGameMode != GAMEMODE_DEATH_RACE) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, (arg1 - (Font_GetStringWidth(sDifficultyNames[gDifficulty], FONT_SET_3, 1) / 2)) + 2,
                              arg2 + 2, sDifficultyNames[gDifficulty], 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, arg1 - (Font_GetStringWidth(sDifficultyNames[gDifficulty], FONT_SET_3, 1) / 2), arg2,
                              sDifficultyNames[gDifficulty], 1, FONT_SET_3, 0);
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
    sPlayer1Lives++;
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

    if ((gNumPlayers == 1) && ((gGameMode != GAMEMODE_GP_RACE) || (sPlayer1Lives > 0)) && (D_i3_80141C30[0] > 120)) {
        gControllers[gGameFrameCount % 4].unk_78 = 1;

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

#ifdef VERSION_JP
const char* sCharacterNames[] = {
    "キャプテン ファルコン",
    "ドクター スチュワート",
    "ピコ",
    "サムライ ゴロー",
    "ジョディ サマー",
    "MM ガゼル",
    "ミスター EAD",
    "ババ",
    "オクトマン",
    "ゴマー&シオー",
    "ケイト アレン",
    "ロジャー バスター",
    "ジェームズ マクラウド",
    "レオン",
    "アントニオ ガスター",
    "ブラック シャドー",
    "マイケル チェーン",
    "ジャック レビン",
    "スーパー アロー",
    "ミセス アロー",
    "ジョン タナカ",
    "ビーストマン",
    "ゾーダ",
    "ドクター クラッシュ",
    "シルバー ニールセン",
    "バイオレックス",
    "ドラク",
    "ビリー",
    "アービン ゴードン",
    "ブラッド ファルコン",
};
#else
const char* sCharacterNames[] = { "CAPTAIN FALCON", "Dr. STEWART",   "PICO",          "SAMURAI GOROH", "JODY SUMMER",
                                  "MIGHTY GAZELLE", "Mr. EAD",       "BABA",          "OCTOMAN",       "GOMAR&SHIOH",
                                  "KATE ALEN",      "ROGER BUSTER",  "JAMES McCLOUD", "LEON",          "ANTONIO GUSTER",
                                  "BLACK SHADOW",   "MICHAEL CHAIN", "JACK LEVIN",    "SUPER ARROW",   "Mrs. ARROW",
                                  "JOHN TANAKA",    "BEASTMAN",      "ZODA",          "Dr. CLASH",     "SILVER NEELSEN",
                                  "BIO REX",        "DRAQ",          "BILLY",         "THE SKULL",     "BLOOD FALCON" };
#endif

Gfx* func_i3_ResultsDrawCharacterName(Gfx* gfx, s32 arg1, s32 character, s32 arg3, s32 arg4) {
    gfx = func_i3_SetOptionColor(gfx, arg1);
    return Font_DrawString(gfx, arg3, arg4, sCharacterNames[character], 1, FONT_SET_4, 0);
}

Gfx* func_i3_ResultsDrawRetireStatus(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    gfx = func_i3_SetOptionColor(gfx, arg1);
#ifdef VERSION_JP
    return Font_DrawString(gfx, arg2, arg3, "リタイア", 1, FONT_SET_4, 0);
#else
    return Font_DrawString(gfx, arg2, arg3, "RETIRE", 1, FONT_SET_4, 0);
#endif
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
    return Font_DrawString(gfx, arg3 - Font_GetStringWidth(D_i3_80141E08, FONT_SET_4, 0), arg4, D_i3_80141E08, 0,
                           FONT_SET_4, 0);
}

Gfx* func_i3_80129870(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    gfx = func_i3_SetOptionColor(gfx, arg1);
    return Font_DrawString(gfx, arg2 - Font_GetStringWidth("+     $", FONT_SET_4, 1), arg3, "+     $", 1, FONT_SET_4,
                           0);
}

Gfx* func_i3_801298DC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    gfx = func_i3_SetOptionColor(gfx, arg1);
    return Font_DrawString(gfx, arg2 - Font_GetStringWidth("    $", FONT_SET_4, 1), arg3, "    $", 1, FONT_SET_4, 0);
}

extern s16 D_800E5FE2;

Gfx* func_i3_DrawDeathRaceResultsS(Gfx* gfx) {
    s32 temp_v1;
    f32 oneScalar = 1.0f;
    s32 xl;
    s32 yl;
    s32 pad[5];

    temp_v1 = Font_GetStringWidth("death race  results", FONT_SET_3, 1) / 2;
    gfx = func_i3_DrawBeveledBox(gfx, 155 - temp_v1, 25, temp_v1 + 169, 43, 0, 0, 200, 127);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gfx = Font_DrawString(gfx, 0xA2 - (Font_GetStringWidth("death race  results", FONT_SET_3, 1) / 2), 0x2C,
                          "death race  results", 1, FONT_SET_3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gfx = Font_DrawString(gfx, 0xA0 - (Font_GetStringWidth("death race  results", FONT_SET_3, 1) / 2), 0x2A,
                          "death race  results", 1, FONT_SET_3, 0);
    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTextureBlock(gfx++, aHudTimeTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
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
    gDPLoadTextureBlock(gfx++, func_800783AC(aBestTex), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0,
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

    gfx = func_i3_DrawTimerScisThousandths(gfx, gRacers[0].raceTime, 0xD5, 0x4B, 1.0f);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    return func_i3_DrawTimerScisThousandths(gfx, gCurrentCourseRecordInfo->timeRecord[0], 0xD5, 0x72, 1.0f);
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

Gfx* func_i3_DrawVsResultsScreen(Gfx* gfx) {
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
    for (i = 0; i < gTotalRacers; i++) {
        sp58 += D_800E5F00[i];
    }

    if ((D_i3_80141D10 > 30) && (D_i3_80141D10 < 30030)) {
        temp_v1_2 = Font_GetStringWidth("vs results", FONT_SET_3, 1) / 2;
        gfx = func_i3_DrawBeveledBox(gfx, 0x9B - temp_v1_2, 0x21, temp_v1_2 + 0xA9, 0x33, 0, 0, 0xC8, 0x7F);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, 0xA2 - (Font_GetStringWidth("vs results", FONT_SET_3, 1) / 2), 0x34, "vs results", 1,
                              FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = Font_DrawString(gfx, 0xA0 - (Font_GetStringWidth("vs results", FONT_SET_3, 1) / 2), 0x32, "vs results", 1,
                              FONT_SET_3, 0);
    } else if ((D_i3_80141D10 > 30030) && (D_i3_80141D10 < 60030)) {
        temp_v1_2 = Font_GetStringWidth("vs total ranking", FONT_SET_3, 1) / 2;
        gfx = func_i3_DrawBeveledBox(gfx, 0x9B - temp_v1_2, 0x21, temp_v1_2 + 0xA9, 0x33, 0, 0, 0xC8, 0x7F);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, 0xA2 - (Font_GetStringWidth("vs total ranking", FONT_SET_3, 1) / 2), 0x34,
                              "vs total ranking", 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = Font_DrawString(gfx, 0xA0 - (Font_GetStringWidth("vs total ranking", FONT_SET_3, 1) / 2), 0x32,
                              "vs total ranking", 1, FONT_SET_3, 0);
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
            for (i = 0; i < gTotalRacers; i++) {
                D_i3_80141D18[i] = D_800E5F10[i] - D_i3_8013EF44[gTotalRacers][gRacers[i].position - 1];
                D_i3_80141D28[i] = D_i3_8013EF44[gTotalRacers][gRacers[i].position - 1];
            }
            D_i3_80141E28 = 0;
            D_i3_80141D68 = 0;
        }
        for (i = 0, j = 0; i < 4; i++) {
            D_i3_80141D48[i] = i;
        }

        for (i = 0; i < gTotalRacers; i++) {
            j += D_800E5F10[i];
        }

        if (sp58 == 1) {
            for (i = 0; i < gTotalRacers; i++) {
                for (j = 0; j < gTotalRacers; j++) {
                    if (gRacers[i].position == j + 1) {
                        D_i3_80141D48[j] = i;
                    }
                }
            }
        } else {
            for (i = 0; i < gTotalRacers; i++) {
                for (j = i + 1; j < gTotalRacers; j++) {
                    if (D_800E5F10[D_i3_80141D48[i]] -
                            D_i3_8013EF44[gTotalRacers][gRacers[D_i3_80141D48[i]].position - 1] <
                        D_800E5F10[D_i3_80141D48[j]] -
                            D_i3_8013EF44[gTotalRacers][gRacers[D_i3_80141D48[j]].position - 1]) {
                        var_s1 = D_i3_80141D48[i];
                        D_i3_80141D48[i] = D_i3_80141D48[j];
                        D_i3_80141D48[j] = var_s1;
                    }
                    if ((D_800E5F10[D_i3_80141D48[i]] -
                             D_i3_8013EF44[gTotalRacers][gRacers[D_i3_80141D48[i]].position - 1] ==
                         D_800E5F10[D_i3_80141D48[j]] -
                             D_i3_8013EF44[gTotalRacers][gRacers[D_i3_80141D48[j]].position - 1]) &&
                        (D_800E5F00[D_i3_80141D48[i]] - D_i3_8013EFC4[gRacers[D_i3_80141D48[i]].position - 1] <
                         D_800E5F00[D_i3_80141D48[j]] - D_i3_8013EFC4[gRacers[D_i3_80141D48[j]].position - 1])) {
                        var_s1 = D_i3_80141D48[i];
                        D_i3_80141D48[i] = D_i3_80141D48[j];
                        D_i3_80141D48[j] = var_s1;
                    }
                    if ((D_800E5F10[D_i3_80141D48[i]] -
                             D_i3_8013EF44[gTotalRacers][gRacers[D_i3_80141D48[i]].position - 1] ==
                         D_800E5F10[D_i3_80141D48[j]] -
                             D_i3_8013EF44[gTotalRacers][gRacers[D_i3_80141D48[j]].position - 1]) &&
                        (D_800E5F00[D_i3_80141D48[i]] - D_i3_8013EFC4[gRacers[D_i3_80141D48[i]].position - 1] ==
                         D_800E5F00[D_i3_80141D48[j]] - D_i3_8013EFC4[gRacers[D_i3_80141D48[j]].position - 1]) &&
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
            for (i = 0; i < gTotalRacers; i++) {
                for (j = 0; j < gTotalRacers; j++) {
                    if (gRacers[j].position == i + 1) {
                        break;
                    }
                }

                if (D_i3_80141D28[gRacers[j].id] != 0) {
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x1F);
                    }
                    D_i3_80141D28[gRacers[j].id]--;
                    D_i3_80141D18[gRacers[j].id]++;
                    break;
                }
            }
        }

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        gfx = Font_DrawString(gfx, 0x30, 0x50, "1Ｓ", 1, FONT_SET_5, 0);
        gfx = Font_DrawString(gfx, 0x30, 0x69, "2Ｎ", 1, FONT_SET_5, 0);

        if (gTotalRacers >= 3) {
            gfx = Font_DrawString(gfx, 0x30, 0x82, "3Ｒ", 1, FONT_SET_5, 0);
        }
        if (gTotalRacers >= 4) {
            gfx = Font_DrawString(gfx, 0x30, 0x9B, "4Ｔ", 1, FONT_SET_5, 0);
        }

        for (i = 0; i < gTotalRacers; i++) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, D_i3_8013EF94[D_i3_80141D48[i]], D_i3_8013EFA4[D_i3_80141D48[i]],
                            D_i3_8013EFB4[D_i3_80141D48[i]], 255);
            j = D_i3_80141D48[i];

            if (gRacers[j].id < gNumPlayers) {
                gfx = Font_DrawString(gfx, 0x4D, 80 + i * 25, "Ｐ", 1, FONT_SET_5, 0);
            } else {
                gfx = Font_DrawString(gfx, 0x4D, 80 + i * 25, "Ａ", 1, FONT_SET_5, 0);
            }

            if (gRacers[j].id < gNumPlayers) {
                func_i3_801296E8(gRacers[j].id + 1);
            } else {
                func_i3_801296E8((gRacers[j].id - gNumPlayers) + 1);
            }

            gfx = Font_DrawString(gfx, 0x93, 80 + i * 25, D_i3_80141E08, 1, FONT_SET_5, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
            func_i3_801296E8(D_i3_80141D18[gRacers[j].id]);
            gfx = Font_DrawString(gfx, 0xD3 - Font_GetStringWidth(D_i3_80141E08, FONT_SET_5, 1), 80 + i * 25,
                                  D_i3_80141E08, 1, FONT_SET_5, 0);
            gfx = Font_DrawString(gfx, 0xD3, 80 + i * 25, "$", 1, FONT_SET_5, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 100, 100, 255, 255);
            gfx = Font_DrawString(gfx, 0xED, 80 + i * 25, "+", 1, FONT_SET_5, 0);
            func_i3_801296E8(D_i3_80141D28[gRacers[j].id]);
            gfx = Font_DrawString(gfx, 0xFA, 80 + i * 25, D_i3_80141E08, 1, FONT_SET_5, 0);

            if (gRacers[j].position == 1) {
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                gfx = Font_DrawString(gfx, 0x10E, 80 + i * 25, "v", 1, FONT_SET_5, 0);
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
                gfx = Font_DrawScaledString(gfx, 0x82, 0xC3, "Ｃ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
                gfx = Font_DrawScaledString(gfx, 0x6E, 0xC3, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = Font_DrawScaledString(gfx, 0x82, 0xD2, "Ｅ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
            } else {
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = Font_DrawScaledString(gfx, 0x82, 0xC3, "Ｃ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
                gDPPipeSync(gfx++);
                gfx = func_8007DB28(gfx, 0);
                gfx = Font_DrawScaledString(gfx, 0x82, 0xD2, "Ｅ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
                gfx = Font_DrawScaledString(gfx, 0x6E, 0xD2, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
            }

            for (i = 0; i < 4; i++) {
                D_i3_80141D38[i] = i;
            }

            for (i = 0; i < gTotalRacers; i++) {
                for (j = i + 1; j < gTotalRacers; j++) {
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
                        (gRacers[D_i3_80141D38[i]].position > gRacers[D_i3_80141D38[j]].position)) {
                        var_s1 = D_i3_80141D38[i];
                        D_i3_80141D38[i] = D_i3_80141D38[j];
                        D_i3_80141D38[j] = var_s1;
                    }
                }
            }

            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = Font_DrawString(gfx, 0x30, 0x50, "1Ｓ", 1, FONT_SET_5, 0);
            gfx = Font_DrawString(gfx, 0x30, 0x69, "2Ｎ", 1, FONT_SET_5, 0);

            if (gTotalRacers >= 3) {
                gfx = Font_DrawString(gfx, 0x30, 0x82, "3Ｒ", 1, FONT_SET_5, 0);
            }
            if (gTotalRacers >= 4) {
                gfx = Font_DrawString(gfx, 0x30, 0x9B, "4Ｔ", 1, FONT_SET_5, 0);
            }

            for (i = 0; i < gTotalRacers; i++) {
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, D_i3_8013EF94[D_i3_80141D38[i]], D_i3_8013EFA4[D_i3_80141D38[i]],
                                D_i3_8013EFB4[D_i3_80141D38[i]], 255);

                if (D_i3_80141D38[i] < gNumPlayers) {
                    gfx = Font_DrawString(gfx, 0x4D, 80 + i * 25, "Ｐ", 1, FONT_SET_5, 0);
                } else {
                    gfx = Font_DrawString(gfx, 0x4D, 80 + i * 25, "Ａ", 1, FONT_SET_5, 0);
                }

                if (D_i3_80141D38[i] < gNumPlayers) {
                    func_i3_801296E8(D_i3_80141D38[i] + 1);
                } else {
                    func_i3_801296E8((D_i3_80141D38[i] - gNumPlayers) + 1);
                }

                gfx = Font_DrawString(gfx, 0x93, 80 + i * 25, D_i3_80141E08, 1, FONT_SET_5, 0);
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
                func_i3_801296E8(D_800E5F10[D_i3_80141D38[i]]);
                gfx = Font_DrawString(gfx, 0xD3 - Font_GetStringWidth(D_i3_80141E08, FONT_SET_5, 1), 80 + i * 25,
                                      D_i3_80141E08, 1, FONT_SET_5, 0);
                gfx = Font_DrawString(gfx, 0xD3, 80 + i * 25, "$", 1, FONT_SET_5, 0);

                if (D_800E5F00[D_i3_80141D38[i]] > 0) {
                    gDPPipeSync(gfx++);
                    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                    gfx = Font_DrawString(gfx, 0xF0, 80 + i * 25, "v", 1, FONT_SET_5, 0);
                    j = D_800E5F00[D_i3_80141D38[i]];
                    if (j > 99) {
                        j = 99;
                    }
                    func_i3_801296E8(j);
                    gfx = Font_DrawString(gfx, 0xFE, 80 + i * 25, D_i3_80141E08, 1, FONT_SET_5, 0);
                }

                if (sp58 != 1) {
                    for (j = 0; j < gTotalRacers; j++) {
                        if (D_i3_80141D48[j] == D_i3_80141D38[i]) {
                            var_s1 = j;
                        }
                    }

                    if (var_s1 < i) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
                        gfx = Font_DrawString(gfx, 0x21, 80 + i * 25, "Ｄ", 1, FONT_SET_5, 0);
                    }

                    if (var_s1 > i) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                        gfx = Font_DrawString(gfx, 0x21, 80 + i * 25, "Ｕ", 1, FONT_SET_5, 0);
                    }
                }

                if (!sMenuIsBusy) {
                    j = gControllers[gPlayerControlPorts[i]].stickY;
                    if (D_i3_80141D68 == 1) {
                        if (j > 50) {
                            D_i3_80141D68 = 0;
                            if (D_800CD010 == 0) {
                                func_800BA8D8(0x1E);
                            }
                        }
                        if (gControllers[gPlayerControlPorts[i]].buttonPressed & BTN_UP) {
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
                        if (gControllers[gPlayerControlPorts[i]].buttonPressed & BTN_DOWN) {
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

    if (!sMenuIsBusy) {
        for (i = 0; i < gNumPlayers; i++) {
            if (gControllers[gPlayerControlPorts[i]].buttonPressed & (BTN_A | BTN_START)) {
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

    if ((D_i3_80141D10 == 60060) && !sMenuIsBusy) {
        for (i = 0; i < gTotalRacers; i++) {
            D_80115DD0[i] = gRacers[i].position;
        }

        if (D_800CD010 == 0) {
            func_8007E08C();
        }

        if (D_i3_80141D68 == 0) {
            sMenuIsBusy = true;
            sMenuStateFlags |= MENU_STATE_CHANGE_COURSE;
        } else {
            sMenuIsBusy = true;
            sMenuStateFlags |= MENU_STATE_QUIT;
        }
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

extern s32 gRacePositionPoints[];

Gfx* func_i3_DrawGPResultsScreen(Gfx* gfx, s32 arg1) {
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
        gfx = Font_DrawString(gfx, 0xA2 - (Font_GetStringWidth("results", FONT_SET_3, 1) / 2), 0x34, "results", 1,
                              FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = Font_DrawString(gfx, 0xA0 - (Font_GetStringWidth("results", FONT_SET_3, 1) / 2), 0x32, "results", 1,
                              FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 30, 55, 290, 204);

        for (i = 0; i < gTotalRacers; i++) {
            temp_ft3 = (58 + i * 25) - D_i3_80141D08;
            if (temp_ft3 > 20 && temp_ft3 < 220) {
                if (gGameMode == GAMEMODE_GP_RACE) {
                    gfx = func_i3_8011F560(gfx, gRacersByPosition[i]->id, gRacersByPosition[i]->character, 0x2D,
                                           (s32) ((55 + i * 25) - D_i3_80141D08), 0.75f);
                    gfx = func_i3_80129800(gfx, gRacersByPosition[i]->id, i + 1, 0x2C,
                                           (s32) ((64 + i * 25) - D_i3_80141D08));
                    gfx =
                        func_i3_ResultsDrawCharacterName(gfx, gRacersByPosition[i]->id, gRacersByPosition[i]->character,
                                                         0x49, (s32) ((70 + i * 25) - D_i3_80141D08));
                    gfx = func_i3_80129870(gfx, gRacersByPosition[i]->id, 0xD8, (s32) ((70 + i * 25) - D_i3_80141D08));
                    if (gRacersByPosition[i]->raceTime != 0) {
                        gfx = func_i3_80129800(gfx, gRacersByPosition[i]->id, gRacePositionPoints[i], 0xC7,
                                               (s32) ((70 + i * 25) - D_i3_80141D08));
                    } else {
                        gfx = func_i3_80129800(gfx, gRacersByPosition[i]->id, 0, 0xC7,
                                               (s32) ((70 + i * 25) - D_i3_80141D08));
                        gfx = func_i3_ResultsDrawRetireStatus(gfx, gRacersByPosition[i]->id, 0xDC,
                                                              (s32) ((70 + i * 25) - D_i3_80141D08));
                    }
                } else {
                    gfx = func_i3_8011F560(gfx, gRacersByPosition[i]->id, (s32) gRacersByPosition[i]->character, 0x39,
                                           (s32) ((55 + i * 25) - D_i3_80141D08), 0.75f);
                    gfx = func_i3_80129800(gfx, gRacersByPosition[i]->id, i + 1, 0x38,
                                           (s32) ((64 + i * 25) - D_i3_80141D08));
                    gfx = func_i3_ResultsDrawCharacterName(gfx, gRacersByPosition[i]->id,
                                                           (s32) gRacersByPosition[i]->character, 0x55,
                                                           (s32) ((70 + i * 25) - D_i3_80141D08));
                    if (gRacersByPosition[i]->raceTime == 0) {
                        gfx = func_i3_ResultsDrawRetireStatus(gfx, gRacersByPosition[i]->id, 0xBE,
                                                              (s32) ((70 + i * 25) - D_i3_80141D08));
                    }
                }
            }
        }

        gSPDisplayList(gfx++, D_8014940);
        gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        for (i = 0; i < gTotalRacers; i++) {

            if (gRacersByPosition[i]->raceTime != 0) {
                temp_ft3 = (58 + i * 25) - D_i3_80141D08;
                if ((temp_ft3 > 20) && (temp_ft3 < 220)) {
                    gDPPipeSync(gfx++);
                    if (gRacersByPosition[i]->id == 0) {
                        gfx = func_8007F090(gfx, 255, 0, 0);
                        gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
                    } else {
                        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                    }
                    if (gGameMode == GAMEMODE_GP_RACE) {
                        gfx = func_i3_DrawTimerScisThousandths(gfx, gRacersByPosition[i]->raceTime, 0xD5,
                                                               (s32) ((58 + i * 25) - D_i3_80141D08), 1.0f);
                    } else {
                        gfx = func_i3_DrawTimerScisThousandths(gfx, gRacersByPosition[i]->raceTime, 0xB9,
                                                               (s32) ((58 + i * 25) - D_i3_80141D08), 1.0f);
                    }
                }
            }
        }
    }
    var_fv1 = gControllers[gPlayerControlPorts[0]].stickY * -1.0f;
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

    if ((gTotalRacers - 6) * 25.0f < D_i3_80141D08) {
        D_i3_80141D08 = (gTotalRacers - 6) * 25.0f;
    }
    if ((D_i3_80141D08 != (gTotalRacers - 6) * 25.0f) && (D_i3_80141D08 != 0.0f)) {
        if ((s32) (D_i3_80141D08 * 0.06f) != ((s32) ((D_i3_80141D08 - var_fv1) * 0.06f))) {
            func_800BA8D8(0x3F);
        }
    }

    D_i3_80141B88[arg1]++;
    if ((D_i3_80141B88[arg1] < 30030) && (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START))) {
        D_i3_80141B88[arg1] = 30030;
    }
    if (D_i3_80141B88[arg1] >= 30060) {
        D_i3_80141B88[arg1] = 0;
        if (gGameMode == GAMEMODE_GP_RACE) {
            D_i3_80141B98 = 2;
        } else {
            D_i3_80141B98 = 3;
            D_i3_80141DA0 = 60;
        }
    }
    return gfx;
}

void Save_UpdateCupCompletion(s32, s32, s32);
extern s32 gCupType;
extern s16 gPlayer1OverallPosition;
extern s16 gRacerPositionsById[];

Gfx* func_i3_8012C4D8(Gfx* gfx, s32 playerIndex) {
    s32 i;
    s32 j;
    s32 var_a2;
    s32 temp_ft2;
    s32 var_s0;
    s32 temp_a2;
    f32 var_fv0;
    s32 pad;

    var_a2 = 0;
    if (D_i3_80141B88[playerIndex] < 30) {
        var_a2 = -D_i3_80141B88[playerIndex] * 4 + 120;
    } else if (D_i3_80141B88[playerIndex] > 40030) {
        var_a2 = D_i3_80141B88[playerIndex] * 4 - 160120;
    }
    gfx = func_i3_8012952C(gfx, var_a2);

    if ((D_i3_80141B88[playerIndex] > 30) && (D_i3_80141B88[playerIndex] < 40030)) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, 0xA2 - (Font_GetStringWidth("total ranking", FONT_SET_3, 1) / 2), 0x34,
                              "total ranking", 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = Font_DrawString(gfx, 0xA0 - (Font_GetStringWidth("total ranking", FONT_SET_3, 1) / 2), 0x32,
                              "total ranking", 1, FONT_SET_3, 0);

        for (i = 0; i < gTotalRacers; i++) {
            gRacerIdsByPosition[i] = i;
        }

        for (i = 0; i < gTotalRacers; i++) {
            for (j = i + 1; j < gTotalRacers; j++) {
                if (gRacers[gRacerIdsByPosition[i]].points < gRacers[gRacerIdsByPosition[j]].points) {
                    var_s0 = gRacerIdsByPosition[i];
                    gRacerIdsByPosition[i] = gRacerIdsByPosition[j];
                    gRacerIdsByPosition[j] = var_s0;
                }
                if (gRacers[gRacerIdsByPosition[i]].points == gRacers[gRacerIdsByPosition[j]].points) {
                    if (gRacers[gRacerIdsByPosition[i]].position > gRacers[gRacerIdsByPosition[j]].position) {
                        var_s0 = gRacerIdsByPosition[i];
                        gRacerIdsByPosition[i] = gRacerIdsByPosition[j];
                        gRacerIdsByPosition[j] = var_s0;
                    }

                    if (gRacers[gRacerIdsByPosition[j]].id == 0) {
                        var_s0 = gRacerIdsByPosition[i];
                        gRacerIdsByPosition[i] = gRacerIdsByPosition[j];
                        gRacerIdsByPosition[j] = var_s0;
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

        for (i = 0; i < gTotalRacers; i++) {
            temp_ft2 = (i * 25) - D_i3_80141D00 - D_i3_80141CC8;
            if ((temp_ft2 > 10) && (temp_ft2 < 220)) {
                if (gCourseIndex % 6) {
                    // Change In Positions
                    if (gRacerPositionsById[gRacerIdsByPosition[i]] < i + 1) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
                        gfx = Font_DrawString(gfx, 0x2F, temp_ft2 + 0x13, "Ｄ", 1, FONT_SET_5, 0);
                        var_s0 = 61;
                        if ((i - gRacerPositionsById[gRacerIdsByPosition[i]]) + 1 < 10) {
                            var_s0 = 58;
                        }
                        gfx = func_i3_80129800(gfx, 1, (i - gRacerPositionsById[gRacerIdsByPosition[i]]) + 1, var_s0,
                                               temp_ft2 + 0x10);
                    }
                    if (gRacerPositionsById[gRacerIdsByPosition[i]] > i + 1) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                        gfx = Font_DrawString(gfx, 0x2F, temp_ft2 + 0x16, "Ｕ", 1, FONT_SET_5, 0);
                        var_s0 = 61;
                        if ((i - gRacerPositionsById[gRacerIdsByPosition[i]]) + 1 > -10) {
                            var_s0 = 58;
                        }
                        gfx = func_i3_80129800(gfx, 1, (gRacerPositionsById[gRacerIdsByPosition[i]] - i) - 1, var_s0,
                                               temp_ft2 + 0x13);
                    }
                }

                gfx = func_i3_8011F560(gfx, gRacers[gRacerIdsByPosition[i]].id,
                                       gRacers[gRacerIdsByPosition[i]].character, 0x51, temp_ft2, 0.75f);
                gfx = func_i3_80129800(gfx, gRacers[gRacerIdsByPosition[i]].id, i + 1, 0x51, temp_ft2 + 9);
                gfx = func_i3_ResultsDrawCharacterName(gfx, gRacers[gRacerIdsByPosition[i]].id,
                                                       gRacers[gRacerIdsByPosition[i]].character, 0x6D, temp_ft2 + 0xF);
                gfx = func_i3_801298DC(gfx, gRacers[gRacerIdsByPosition[i]].id, 0x103, temp_ft2 + 0xF);
                gfx = func_i3_80129800(gfx, gRacers[gRacerIdsByPosition[i]].id, gRacers[gRacerIdsByPosition[i]].points,
                                       0xF3, temp_ft2 + 0xF);
            }

            if (gRacerIdsByPosition[i] == 0) {
                gPlayer1OverallPosition = i + 1;
            }
        }
    }

    if ((gGameMode == GAMEMODE_GP_RACE) && (D_i3_80141B88[playerIndex] == 60) && (gRacerIdsByPosition[0] == 0) &&
        ((gCourseIndex % 6) == 5) && (gCupType <= X_CUP)) {
        func_8007DEF0();
        if (gRacers[0].customType == 0) {
            Save_UpdateCupCompletion(gDifficulty, gCupType, gRacers[0].character);
        }
    }

    D_i3_80141B88[playerIndex]++;

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
        D_i3_80141D04 = 8.0f;
    }
    if ((D_i3_80141B88[playerIndex] < 40030) && (D_i3_80141D00 <= -62.0f)) {
        if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
            D_i3_80141B88[playerIndex] = 40030;
        }
        var_fv0 = gControllers[gPlayerControlPorts[0]].stickY * -1.0f;
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

        if (((gTotalRacers - 6) * 25.0f + 7.0f) < D_i3_80141CC8) {
            D_i3_80141CC8 = (gTotalRacers - 6) * 25.0f + 7.0f;
        }
        if ((D_i3_80141CC8 != 0.0f) && (D_i3_80141CC8 != ((gTotalRacers - 6) * 25.0f + 7.0f)) &&
            (s32) (D_i3_80141CC8 * 0.06f) != (s32) ((D_i3_80141CC8 - var_fv0) * 0.06f)) {
            func_800BA8D8(0x3F);
        }
    }
    if (D_i3_80141B88[playerIndex] >= 40060) {
        D_i3_80141B98 = 5;

        for (i = 0; i < gTotalRacers; i++) {
            for (j = 0; j < gTotalRacers; j++) {
                if (gRacerIdsByPosition[j] == i) {
                    gRacerPositionsById[i] = j + 1;
                }
            }
        }
    }
    return gfx;
}

extern s32 gTotalLapCount;
extern s32 gCurrentGhostType;

Gfx* func_i3_8012CF34(Gfx* gfx, s32 playerIndex) {
    s32 i;

    if (D_800E5220[playerIndex].unk_04 == 10) {
        if ((gGameMode != GAMEMODE_TIME_ATTACK) ||
            ((gGameMode == GAMEMODE_TIME_ATTACK) && (gCurrentGhostType < GHOST_STAFF))) {
            if (D_i3_80141BD0[playerIndex] == 0) {
                D_i3_80141BD0[playerIndex] = 1;
                func_i3_801217F0(playerIndex);
            }

            if (D_i3_80141D78[playerIndex] < 300) {
                gfx = func_i3_80121860(gfx, playerIndex);
            }
        } else {
            if ((D_i3_80141D78[playerIndex] < 300) && ((gGameFrameCount & 4) || (D_i3_80141D78[playerIndex] >= 0x3D))) {
                gRacers[0].unk_36C |= 0x1000;
                gfx = func_i3_801209C8(gfx, 0);
            }
            if (D_i3_80141D78[playerIndex] == 120) {
                if (D_800CD010 == 0) {
                    func_800BAFA4(0x10);
                }

                for (i = 0; i < gNumPlayers; i++) {
                    if ((gRacers[i].stateFlags & RACER_STATE_FLAGS_8000000) ||
                        (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000)) {
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

            if ((D_i3_80141D78[playerIndex] == 2) && (gCourseIndex < COURSE_X_1) && (gTotalLapCount == 3)) {
                sMenuStateFlags |= MENU_STATE_RACE_FINISH_SAVE;
            }
        }
        D_i3_80141D78[playerIndex]++;
    } else if (D_i3_80141DF0[playerIndex] == 1) {
        if ((gGameMode != GAMEMODE_TIME_ATTACK) ||
            ((gGameMode == GAMEMODE_TIME_ATTACK) && (gCurrentGhostType < GHOST_STAFF))) {
            if (D_i3_80141BD0[playerIndex] == 0) {
                D_i3_80141BD0[playerIndex] = 1;
                func_i3_801217F0(playerIndex);
            }
            gfx = func_i3_80121860(gfx, playerIndex);
        } else {

            if ((D_i3_80141BE0[playerIndex] > 60) || (gGameFrameCount & 4)) {
                gfx = func_i3_8012040C(gfx, 0);
            }
            if (D_i3_80141BE0[playerIndex] == 30) {
                if (D_800CD010 == 0) {
                    func_800BAFA4(0x11);
                }

                for (i = 0; i < gNumPlayers; i++) {
                    if ((gRacers[i].stateFlags & RACER_STATE_FLAGS_8000000) ||
                        (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000)) {
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
            if ((D_i3_80141BE0[playerIndex] == 2) && (gCourseIndex < COURSE_X_1) && (gTotalLapCount == 3)) {
                sMenuStateFlags |= MENU_STATE_RACE_FINISH_SAVE;
            }
        }
    } else {
        D_i3_80141BD0[playerIndex] = 0;
    }
    return gfx;
}

extern s32 gTotalLapCount;
extern char* gCurrentTrackName;
extern s16 D_800E5FBC;
extern s16 gRacersRetired;
extern s16 D_800E5FE2;
extern s16 D_800F5DE6;
extern s32 gRaceIntroTimer;
extern s32 D_800F80A8[];
extern s32 gSettingVsSlot;
extern s32 gRaceTimeIntervalToggle;

Gfx* func_i3_8012D3D4(Gfx* gfx) {
    s32 i = 0;
    s32 j;
    Racer* racer;
    s32 pad[4];
    f32 temp_ft5;
    f32 var_fa0;
    s32 playerIndex = 0;

    gRacersRemaining = gTotalRacers - gRacersRetired;
    if ((gNumPlayers == 1) && (gTotalRacers != 1) && !(gGameFrameCount % 64) && !gGamePaused) {
        func_i3_801175A4();
    }
    if (gNumPlayers == 1) {
        if (gGameMode == GAMEMODE_DEATH_RACE) {
            if (gRacers[playerIndex].speed < (500.0f / 27.0f)) {
                D_80141900++;
            } else {
                D_80141900 = 0;
            }
        } else {
            if (gRacers[playerIndex].speed < (250.0f / 27.0f)) {
                D_80141900++;
            } else {
                D_80141900 = 0;
            }
        }
    }

    for (i = 0; i < gNumPlayers; i++) {
        if (gRacers[i].stateFlags & RACER_STATE_FLAGS_2000000) {
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
            gfx = Font_DrawScaledString(gfx,
                                        (234.0f - ((Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 1) * 0.7f) / 2)),
                                        0x94, gCurrentTrackName, 1, FONT_SET_3, 0, 0.7f, 0.7f);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
            gfx = Font_DrawScaledString(gfx,
                                        (232.0f - ((Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 1) * 0.7f) / 2)),
                                        0x92, gCurrentTrackName, 1, FONT_SET_3, 0, 0.7f, 0.7f);
        }

        gDPPipeSync(gfx++);
        if (gNumPlayers == 1) {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
        } else {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
        }

        if ((gNumPlayers != 1) || (gGameMode != GAMEMODE_GP_RACE) || (sPlayer1Lives > 0) || (D_i3_80141C20[0] < 2)) {
            if (((gNumPlayers != 1) || (D_i3_80141DF0[0] != 2)) &&
                ((gNumPlayers != 1) || (D_800E5220[playerIndex].unk_04 != 10) || (D_i3_80141D78[0] < 300))) {
                gfx = func_i3_DrawHUD(gfx);
            }
            for (i = 0; i < gNumPlayers; i++) {
                if ((gNumPlayers != 1) ||
                    ((D_i3_80141DF0[i] != 2) && ((D_800E5220[playerIndex].unk_04 != 10) || (D_i3_80141D78[0] < 300)))) {
                    if (gNumPlayers == 1) {
                        gfx = func_i3_DrawRacePortraits(gfx);
                    }
                    if ((gGameMode != GAMEMODE_DEATH_RACE) && (D_i3_80141C20[i] == 0) &&
                        !(gRacers[i].stateFlags & RACER_STATE_FLAGS_2000000)) {
                        gfx = func_i3_DrawCourseMinimap(gfx, gNumPlayers - 1, i);
                    }
                    if (gNumPlayers == 3) {
                        gfx = func_i3_DrawCourseMinimap(gfx, gNumPlayers - 1, 3);
                    }
                    gfx = func_i3_DrawPosition(gfx, gNumPlayers - 1, i);
                }
                if (((gNumPlayers != 1) || (D_i3_80141C20[i] == 0)) &&
                    !(gRacers[i].stateFlags & RACER_STATE_FLAGS_2000000)) {
                    gfx = func_i3_DrawPlayerSpeed(gfx, gNumPlayers - 1, i);
                }
            }
        }
    }
    if (((gGameFrameCount % 120) == 0) && !gGamePaused) {
        for (i = 0; i < gTotalRacers; i++) {
            if (!(gRacers[i].stateFlags & RACER_STATE_FLAGS_2000000) &&
                (gRacers[i].stateFlags & RACER_STATE_FLAGS_8000000)) {
                gRacers[i].unk_368 = 254;
            }
        }

        if (D_800CD010 != 0) {
            j = 0;
            for (i = 0; i < gNumPlayers; i++) {
                if (gRacers[i].stateFlags & RACER_STATE_FLAGS_8000000) {
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
            temp_ft5 = gRacers[playerIndex].raceDistance / gRacers[playerIndex].raceTime;
            if (gGameMode == GAMEMODE_GP_RACE) {
                if (gRaceTimeIntervalToggle) {
                    if ((temp_ft5 > 0.1f) && (gRacersRemaining >= 2)) {
                        if (gRacers[playerIndex].position != 1) {
                            var_fa0 =
                                ((gRacersByPosition[0]->raceDistance - gRacers[playerIndex].raceDistance) / temp_ft5) *
                                0.8892f;
                        } else {
                            var_fa0 =
                                ((gRacersByPosition[1]->raceDistance - gRacers[playerIndex].raceDistance) / temp_ft5) *
                                0.8892f;
                        }
                        if (gRacersByPosition[0]->stateFlags & RACER_STATE_FLAGS_2000000) {
                            var_fa0 = ((gRacers[playerIndex].raceTime / gRacers[playerIndex].raceDistance) *
                                       gCurrentCourseRecordInfo->length * gTotalLapCount) -
                                      gRacersByPosition[0]->raceTime;
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
                if ((D_800CD010 == 0) && (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_L)) {
                    gRaceTimeIntervalToggle ^= 1;
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x31);
                    }
                }
            } else if ((gGameMode == GAMEMODE_TIME_ATTACK) && (gFastestGhostIndex >= 0)) {

                if (D_i3_80141DD0->lapDistance - D_i3_80141DD8 < -(gCurrentCourseRecordInfo->length * 0.5f)) {
                    D_i3_80141DDC += gCurrentCourseRecordInfo->length;
                }

                if (gCurrentCourseRecordInfo->length * 0.5f < D_i3_80141DD0->lapDistance - D_i3_80141DD8) {
                    D_i3_80141DDC -= gCurrentCourseRecordInfo->length;
                }
                D_i3_80141DD0->raceDistance = D_i3_80141DD0->lapDistance + D_i3_80141DDC;
                if (gRaceTimeIntervalToggle) {
                    if (temp_ft5 > 0.1f) {
                        var_fa0 =
                            ((D_i3_80141DD0->raceDistance - gRacers[playerIndex].raceDistance) / temp_ft5) * 0.8892f;
                        if ((gCurrentCourseRecordInfo->length * (gTotalLapCount - 0.01f)) <=
                            D_i3_80141DD0->raceDistance) {
                            var_fa0 = ((gRacers[playerIndex].raceTime / gRacers[playerIndex].raceDistance) *
                                       gCurrentCourseRecordInfo->length * gTotalLapCount) -
                                      gFastestGhostTime;
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
                D_i3_80141DD8 = D_i3_80141DD0->lapDistance;
                if ((D_800CD010 == 0) && (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_L)) {
                    gRaceTimeIntervalToggle ^= 1;
                    if (D_800CD010 == 0) {
                        func_800BA8D8(0x31);
                    }
                }
            }
        }

        if ((gGameMode == GAMEMODE_TIME_ATTACK) && !gGamePaused && (D_800F5DE6 != 0) &&
            (D_800E5220[playerIndex].unk_04 == 6) && (D_i3_80141C20[0] == 0)) {
            gfx = func_i3_801239D0(gfx);
        }
        if (gGameMode != GAMEMODE_PRACTICE) {
            if ((gRacers[playerIndex].lap == gTotalLapCount) && (D_800CD010 == 0) &&
                (D_i3_80141EA8[playerIndex].unk_04 > 0) && !gGamePaused) {
                if (((D_i3_80141EA8[playerIndex].unk_04 % 20) >= 5) && (D_i3_80141EA8[playerIndex].unk_04 > 120)) {
                    gfx = func_i3_80121178(gfx, 0);
                }
                D_i3_80141CD0[playerIndex]++;
            }
            if ((gRacers[playerIndex].lap == 2) && (D_800CD010 == 0) && !gGamePaused &&
                (D_i3_80141EA8[playerIndex].unk_04 > 0)) {
                if (((D_i3_80141EA8[playerIndex].unk_04 % 20) >= 5) && (D_i3_80141EA8[playerIndex].unk_04 > 120)) {
                    gfx = func_i3_801216C0(gfx, 0);
                }
                D_i3_80141CE0[playerIndex]++;
            }
        }
        if (!gGamePaused && (D_800E5220[playerIndex].unk_04 == 4)) {
            gDPPipeSync(gfx++);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
            D_i3_80141D8C++;
            if (D_i3_80141D8C >= 4) {
                j = D_i3_80141D8C - 200;
                if (D_i3_80141D8C < 250) {
                    if (j < 0) {
                        j = 0;
                    }

                    if (gGameMode != GAMEMODE_DEATH_RACE) {
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
                    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) ||
                        (gGameMode == GAMEMODE_DEATH_RACE)) {
                        gfx = func_i3_801281B4(gfx, i, 93, j);
                        if ((gGameMode == GAMEMODE_DEATH_RACE) &&
                            (gCurrentCourseRecordInfo->timeRecord[0] != MAX_TIMER)) {
                            i = 300 - (D_i3_80141D8C * 8);
                            if (i < 160) {
                                i = 140;
                            }
                            gfx = func_i3_80127E88(gfx, 160, i, j);
                        }
                    } else {
                        gfx = func_i3_80127854(gfx, i, 86, j);
                        if (gCurrentCourseRecordInfo->timeRecord[0] != MAX_TIMER) {
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
                if (gGameMode != GAMEMODE_TIME_ATTACK) {
                    func_8008AA8C();
                }
            }
            if (gGameMode == GAMEMODE_TIME_ATTACK) {
                if (D_i3_80141B9C < 0x190) {
                    gfx = func_i3_801274EC(gfx);
                    gfx = func_i3_80126B40(gfx, 0);
                }
                gfx = func_i3_8012757C(gfx, 160, 0x26, 0);
                if ((D_i3_80141B88[playerIndex] > 100) &&
                    (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) &&
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
                        gfx = func_i3_8013A360(gfx, gCourseIndex);
                        if (i) {
                            gfx = func_i3_DrawTimeAttackFinishMenu(gfx);
                        }
                    }
                }
            } else if (gGameMode == GAMEMODE_GP_RACE) {
                switch (D_i3_80141B98) {
                    case 0:
                        gfx = func_i3_8012757C(gfx, 160, 200, 0);
                        gfx = func_i3_8011FAE4(gfx);
                        gfx = func_i3_80126B40(gfx, 0);
                        if ((D_i3_80141B88[playerIndex] >= 600) ||
                            (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START))) {
                            D_i3_80141B98 = 1;
                            D_i3_80141B88[playerIndex] = 0;
                        }
                        break;
                    case 1:
                        gfx = func_i3_DrawGPResultsScreen(gfx, 0);
                        D_i3_80141D00 = gTotalRacers * 25;
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
                        sMenuIsBusy = true;
                        D_i3_801419A6 = 30;
                        sMenuStateFlags |= MENU_STATE_GP_NEXT_COURSE;
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
                        sMenuIsBusy = true;
                        sMenuStateFlags |= MENU_STATE_QUIT;
                        D_i3_80141B98 = 255;
                        break;
                    case 255:
                        break;
                }
            } else if (gGameMode == GAMEMODE_DEATH_RACE) {
                gfx = func_i3_DrawDeathRaceResultsS(gfx);
                gfx = func_i3_80124EEC(gfx);
            }
        }
        if (!(gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000) &&
            (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_8000000)) {
            if (D_i3_80141C20[0] == 0) {
                D_i3_80141C30[0] = 0;
                D_i3_80141C50[0] = 200.0f;
                D_i3_80141C40[0] = -20.0f;
                D_i3_80141C20[0] = 1;
            }
            if ((gGameMode == GAMEMODE_GP_RACE) && (sPlayer1Lives <= 0)) {
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
                    if (gGameMode == GAMEMODE_GP_RACE) {
#ifdef VERSION_JP
                        if (D_i3_80141C30[0] > 400) {
#else
                        if (D_i3_80141C30[0] == 400) {
#endif
                            if (D_800CD010 == 0) {
                                func_800BB048();
                            }
                            if (D_800CD010 == 0) {
                                func_8007E0CC();
                            }
                            sMenuIsBusy = true;
                            sMenuStateFlags |= MENU_STATE_400;
                        }
                    } else if (D_i3_80141C30[0] > 200) {
                        if (gGameMode != GAMEMODE_DEATH_RACE) {
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
            for (i = 0; i < gTotalRacers; i++) {
                racer = &gRacers[i];
                if (i < gNumPlayers) {
                    if (racer->lap == gTotalLapCount) {
                        if ((D_i3_80141EA8[i].unk_04 > 0) && !gGamePaused) {
                            if (((D_i3_80141EA8[i].unk_04 % 20) >= 5) && (D_i3_80141EA8[i].unk_04 > 120)) {
                                gfx = func_i3_80121178(gfx, i);
                            }
                            D_i3_80141CD0[i]++;
                        }
                    }

                    if ((racer->lap == 2) && (D_800CD010 == 0) && !gGamePaused) {
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

                if (((racer->stateFlags & RACER_STATE_FLAGS_2000000) && (i < gNumPlayers)) || (D_800E5FBC == 1)) {
                    gfx = func_i3_8012040C(gfx, i);
                }

                if (gPlayerLapNumbers[i] >= gTotalLapCount + 1) {
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
                if ((racer->stateFlags & RACER_STATE_FLAGS_2000000) && (i < gNumPlayers) &&
                    !(racer->stateFlags & RACER_STATE_FLAGS_8000000)) {
                    gfx = func_i3_80126B40(gfx, i);
                } else if ((racer->stateFlags & RACER_STATE_FLAGS_8000000) &&
                           !(racer->stateFlags & RACER_STATE_FLAGS_2000000) && (i < gNumPlayers) &&
                           (D_i3_80141DF0[i] != 2)) {
                    if (D_i3_80141C20[i] == 0) {
                        D_i3_80141C30[i] = 0;
                        D_i3_80141C50[i] = 200.0f;
                        D_i3_80141C40[i] = -20.0f;
                        D_i3_80141C20[i] = 1;
                    }
                    if ((D_800E5FBC != 1) || (racer->position != 1)) {
                        gfx = func_i3_80128DA4(gfx, i);
                    }
                }
            }
        }
        if ((D_800E5FBC == 1) && (D_800CD010 == 0)) {
            if (D_i3_80141D10 > 0) {
                D_80141D6C = 1;
                if (D_80141D70 != 0) {
                    gfx = func_i3_DrawVsResultsScreen(gfx);
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
    if ((gSettingVsSlot != 0) && (D_800E5FBC != 1) && (gNumPlayers >= 2)) {
        for (i = 0; i < gNumPlayers; i++) {
            if ((gRacers[i].stateFlags & RACER_STATE_FLAGS_8000000) &&
                !(gRacers[i].stateFlags & RACER_STATE_FLAGS_2000000)) {
                gfx = func_i3_8011C25C(gfx, i);
            }
        }
    }
    if (D_800CD010 == 0) {
        if (gGamePaused) {
            if (gGameMode == GAMEMODE_GP_RACE) {
                gfx = func_i3_DrawGpRacePause(gfx);
            } else if (gGameMode == GAMEMODE_DEATH_RACE) {
                gfx = func_i3_DrawDeathRacePause(gfx);
            } else {
                gfx = func_i3_DrawGeneralPause(gfx);
            }
        } else {
            sPauseMenuScissorBoxTimer = 60;
            sPauseMenuOptionIndex = 0;
            for (i = 0; i < gNumPlayers; i++) {
                if ((gControllers[gPlayerControlPorts[i]].buttonPressed & BTN_START) && (D_800CD010 == 0) &&
                    (D_800E5FBC == 0) && (gRaceIntroTimer < 320)) {
                    sMenuStateFlags |= MENU_STATE_PAUSE_GAME;
                    sPausePlayerNum = i;
                    break;
                }
            }
        }
    }
    return gfx;
}
