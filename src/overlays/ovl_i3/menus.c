#include "global.h"
#include "fzx_cache.h"
#include "menus.h"
#include "hud.h"
#include "minimap.h"
#include "ovl_i3.h"
#include "records_entry.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_save.h"
#include "fzx_course.h"
#include "fzx_machine.h"
#include "fzx_camera.h"
#include "fzx_font.h"
#include "controller.h"
#include ASSET_HEADER(course_track_gfx.h)
#include ASSET_HEADER(machine_custom_gfx.h)
#include ASSET_HEADER(hud_gfx.h)
#include ASSET_HEADER(common_assets_compressed.h)

s16 sRaceFinishSaveTriggered;
s16 sMenuIsBusy;
s16 sMenuOptionTriggered;
s16 D_i3_801419A6;
s32 D_i3_801419A8;
#ifdef EXPANSION_KIT
s32 sVsRacePointsAddTimer; // bss reordered
#endif
s32 D_i3_801419AC;
s32 sMenuStateFlags;
s32 D_i3_801419B4;
s32 sPlayer1Lives;
bool gShowNameEntryMenu;
#if defined(EXPANSION_KIT) || defined(VERSION_PAL)
s32 D_i3_8006D0B4;
#endif
UNUSED s32 D_i3_801419C0[4];
s32 gRacerIdsByPosition[30];
#ifndef EXPANSION_KIT
UNUSED s32 D_i3_80141A48;
#endif
bool sCannotSaveGhost; // possibly bss reordered or below is?
#ifdef EXPANSION_KIT
UNUSED s32 D_i3_8006D144;
#endif
s16 sVsSlotResultIndex[4][3];
s16 sVsSlotCurrentSlotState[4];
f32 sVsSlotScrollPosition[4][3];
f32 sVsSlotSpeed[4][3];
f32 sVsSlotInitialSpeed[3];
TexturePtr sVsSlotPortraits[8][3];
u16 sVsSlotResultIndexToPortraitResult[8][3];
s16 sVsSlotCooldownTimer[4];
#ifdef EXPANSION_KIT // TODO BSS Reordering
GhostRecord sDDGhostRecords[3];
#endif
bool D_i3_80141B78[4];
#ifdef EXPANSION_KIT // TODO BSS Reordering
GhostRecord* sSortedDDGhostRecordPtrs[3];
#endif
s32 sPlayerResultsTimer[4];
#ifdef EXPANSION_KIT // TODO BSS Reordering
GhostRecord* sTempDDGhostRecordPtr;
#endif
s32 sGpRaceResultsState;
#ifdef EXPANSION_KIT // TODO BSS Reordering
s32 sSortedDDGhostRecordIndices[3];
#endif
s32 sTimeAttackResultsTimer;
s32 sResultsTimesLapLeft;
s32 sResultsTimesTop;
s32 sResultsTimesVerticalSpacing;
s32 sResultsTimesLapLeftFromLap;
s32 sResultsTimesStartTopOffset;
#ifdef EXPANSION_KIT
UNUSED s32 D_i3_8006D38C;
#endif
s32 sResultsTimesStartLapSpacing;
s32 sResultsTimesSpeed;
s32 sPlayerRetireGameoverFadeTransitionTimer[4];
bool sPlayerFinishInitialized[4];
s32 sPlayerWinnerLoserFinishGameoverTimer[4];
s32 sFinishGameoverTimer[4];
f32 sFinishGameoverRotationSpeed[4];
f32 sFinishGameoverRotation[4];
s32 sPlayerGameoverState[4];
s32 sPlayerRetireTimer[4];
f32 sPlayerRetireHorizontalSpeed[4];
f32 sPlayerRetireRelativeLeftPos[4];
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
f32 sTotalRankingsManualScrollPosition;
s32 sPlayerFinalLapTimer[4];
s32 sPlayerBoosterOkTimer[4];
s32 D_i3_80141CF0[4];
f32 sTotalRankingsForcedScrollPosition;
f32 sTotalRankingsForcedScrollSpeed;
f32 sGpResultsRankingScrollPosition;
f32 sGameoverScale;
s32 sVsResultsTimer;
s32 sVsRaceResultsPlayerDisplayPoints[4];
s32 sVsRacePlayerPointsIncrease[4];
s32 sVsRacePlayerByOverallPosition[4];
s32 sVsRacePreviousPlayerByOverallPosition[4];
s32 sPlayerShowFinishedTimeTimer[4];
s32 sVsRaceResultsMenuOptionIndex;
bool D_80141D6C;
bool D_80141D70;
s32 sPlayerLoserFinishTimer[4];
s32 D_i3_80141D88;
s32 sMenuRaceIntroTimer;
s32 sMenuHighlightedOptionMoveTimer;
s32 sRaceMenuOptionIndex;
s32 sGeneralRaceMenuScissorBoxTimer;
s32 sGpResultsEndMenuOptionIndex;
s32 sGpResultsEndMenuScissorBoxTimer;
s32 sPauseMenuOptionIndex;
s32 sPauseMenuScissorBoxTimer;
s32 sPausePlayerNum;
bool sSaveGhostMenuOpen;
s32 sGhostSaveMenuScissorBoxTimer;
s32 sOverwriteGhostOptionIndex;
s32 sSaveGhostMenuOptionState;
s32 sSaveGhostMenuOptionsScissorBoxTimer;
s32 sSaveGhostMenuOptionIndex;
s32 sGhostSaveTimer;
s16 sSaveGhostMenuState;
Racer* sFastestGhostRacerRacer;
UNUSED s32 D_i3_80141DD4;
f32 sFastestGhostRacerLapDistance;
f32 sFastestGhostRacerLapsCompletedDistance;
s32 sPlayerFinishTimer[4];
s32 sPlayerFinishState[4];
s32 sFinishedSuccessTime;
char sMenusLoadedNumberStr[32];
#ifndef EXPANSION_KIT
s32 sVsRacePointsAddTimer;
#endif

TexturePtr D_i3_8013ED30[] = {
    aPortraitPositionFirstTex,  aPortraitPositionSecondTex, aPortraitPositionThirdTex,
    aPortraitPositionFourthTex, aPortraitPositionFifthTex,  aPortraitPositionSixthTex,
};

s16 sPlayersVsSlotPositions[][4][2] = {
    { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },   { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },
    { { 118, 83 }, { 118, 196 }, { 200, 80 }, { 200, 193 } }, { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },
    { { 58, 80 }, { 58, 193 }, { 200, 80 }, { 200, 193 } },
};

TexturePtr sRaceMenuTextures[RACE_MENU_MAX] = {
    aMenuRetryTex,                 // RACE_MENU_RETRY
    aMenuSettingsTex,              // RACE_MENU_SETTINGS
    aMenuQuitTex,                  // RACE_MENU_QUIT
    aMenuChangeMachineTex,         // RACE_MENU_CHANGE_MACHINE
    aMenuChangeCourseTex,          // RACE_MENU_CHANGE_COURSE
    aMenuGhostSaveTex,             // RACE_MENU_GHOST_SAVE
    aMenuOverwriteData1Tex,        // RACE_MENU_OVERWRITE_DATA1
    aMenuSavingTex,                // RACE_MENU_SAVING
    aMenuToGamePakTex,             // RACE_MENU_TO_GAME_PAK
    aMenuToDiskTex,                // RACE_MENU_TO_DISK
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

// clang-format off
s32 sRaceMenuDimensions[RACE_MENU_MAX * 2] = {
    TEX_WIDTH(aMenuRetryTex),                 TEX_HEIGHT(aMenuRetryTex),                 // RACE_MENU_RETRY
    TEX_WIDTH(aMenuSettingsTex),              TEX_HEIGHT(aMenuSettingsTex),              // RACE_MENU_SETTINGS
    TEX_WIDTH(aMenuQuitTex),                  TEX_HEIGHT(aMenuQuitTex),                  // RACE_MENU_QUIT
    TEX_WIDTH(aMenuChangeMachineTex),         TEX_HEIGHT(aMenuChangeMachineTex),         // RACE_MENU_CHANGE_MACHINE
    TEX_WIDTH(aMenuChangeCourseTex),          TEX_HEIGHT(aMenuChangeCourseTex),          // RACE_MENU_CHANGE_COURSE
    TEX_WIDTH(aMenuGhostSaveTex),             TEX_HEIGHT(aMenuGhostSaveTex),             // RACE_MENU_GHOST_SAVE
    TEX_WIDTH(aMenuOverwriteData1Tex),        TEX_HEIGHT(aMenuOverwriteData1Tex),        // RACE_MENU_OVERWRITE_DATA1
    TEX_WIDTH(aMenuSavingTex),                TEX_HEIGHT(aMenuSavingTex),                // RACE_MENU_SAVING
    TEX_WIDTH(aMenuToGamePakTex),             TEX_HEIGHT(aMenuToGamePakTex),             // RACE_MENU_TO_GAME_PAK
    TEX_WIDTH(aMenuToDiskTex),                TEX_HEIGHT(aMenuToDiskTex),                // RACE_MENU_TO_DISK
    TEX_WIDTH(aMenuOverwriteData2Tex),        TEX_HEIGHT(aMenuOverwriteData2Tex),        // RACE_MENU_OVERWRITE_DATA2
    TEX_WIDTH(aMenuClearRecordTex),           TEX_HEIGHT(aMenuClearRecordTex),           // RACE_MENU_CLEAR_RECORD
    TEX_WIDTH(aMenuEraseCourseSavedData1Tex), TEX_HEIGHT(aMenuEraseCourseSavedData1Tex), // RACE_MENU_ERASE_COURSE_DATA1
    TEX_WIDTH(aMenuClearGhostTex),            TEX_HEIGHT(aMenuClearGhostTex),            // RACE_MENU_CLEAR_GHOST
    TEX_WIDTH(aMenuEraseCourseSavedData2Tex), TEX_HEIGHT(aMenuEraseCourseSavedData2Tex), // RACE_MENU_ERASE_COURSE_DATA2
    TEX_WIDTH(aMenuContinueTex),              TEX_HEIGHT(aMenuContinueTex),              // RACE_MENU_CONTINUE
    TEX_WIDTH(aMenuYesTex),                   TEX_HEIGHT(aMenuYesTex),                   // RACE_MENU_YES
    TEX_WIDTH(aMenuNoTex),                    TEX_HEIGHT(aMenuNoTex),                    // RACE_MENU_NO
    TEX_WIDTH(aMenuSavedTex),                 TEX_HEIGHT(aMenuSavedTex),                 // RACE_MENU_SAVED
    TEX_WIDTH(aMenuNewGhostTex),              TEX_HEIGHT(aMenuNewGhostTex),              // RACE_MENU_NEW_GHOST
    TEX_WIDTH(aMenuSavedGhostTex),            TEX_HEIGHT(aMenuSavedGhostTex),            // RACE_MENU_SAVED_GHOST
    TEX_WIDTH(aMenuCannotSaveGhostTex),       TEX_HEIGHT(aMenuCannotSaveGhostTex),       // RACE_MENU_CANNOT_SAVE_GHOST
    TEX_WIDTH(aMenuLeftArrowTex),             TEX_HEIGHT(aMenuLeftArrowTex),             // RACE_MENU_LEFT_ARROW
    TEX_WIDTH(aMenuRightArrowTex),            TEX_HEIGHT(aMenuRightArrowTex),            // RACE_MENU_RIGHT_ARROW
};
// clang-format on

void func_i3_8011AE70(void) {
    sMenuStateFlags = D_i3_801419B4 = 0;
}

void func_i3_8011AE88(void) {
    D_i3_801419A8 = D_i3_801419AC = 0;
}

extern s8 gGamePaused;
extern s32 D_i2_80106F10;
extern s32 sMenuStateFlags;
extern s32 gNumPlayers;
extern s32 gGameMode;
extern s32 gCourseIndex;
extern s16 gMenuChangeMode;
extern s32 gTotalRacers;
extern s16 D_80115D50[];

void Menus_Update(void) {
    s32 i;

    if (sMenuStateFlags != 0) {
        if (sMenuStateFlags & MENU_STATE_PAUSE_GAME) {
            gGamePaused = true;
            Audio_PauseSet(AUDIO_PAUSE_PAUSED);
            Audio_TriggerSystemSE(NA_SE_12);
            Controller_Reset();
        }
        if (sMenuStateFlags & MENU_STATE_UNPAUSE_GAME) {
            gGamePaused = false;
            D_i2_80106F10 = 4;
            for (i = 0; i < gNumPlayers; i++) {
                gControllers[gPlayerControlPorts[i]].unk_72 = 1;
            }
            Audio_PauseSet(AUDIO_PAUSE_UNPAUSED);
            Audio_TriggerSystemSE(NA_SE_13);
        }
        if ((sMenuStateFlags & MENU_STATE_RACE_FINISH_SAVE) && !sRaceFinishSaveTriggered) {
            if (gGameMode == GAMEMODE_TIME_ATTACK) {
                if (gCourseIndex < COURSE_X_1) {
                    func_80089BD0();
                    RecordsEntry_ClearCurrentRecordName();
                }
                if (gCourseIndex < COURSE_EDIT_1) {
                    Save_SaveCourseRecordProfiles(gCourseIndex);
                }
            } else if (gGameMode == GAMEMODE_GP_RACE) {
                RecordsEntry_UpdateRaceStats(gCourseIndex);
            } else if (gGameMode == GAMEMODE_DEATH_RACE) {
                func_80089BD0();
                Save_SaveDeathRaceProfiles();
            }
            sRaceFinishSaveTriggered = true;
        }
        if (!sMenuOptionTriggered && (D_i3_801419A6 == 0)) {
            if (sMenuStateFlags & MENU_STATE_RETRY) {
                func_80095144();
                gMenuChangeMode = MENU_CHANGE_RETRY;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_QUIT) {
                func_80095144();
                gMenuChangeMode = MENU_CHANGE_QUIT;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_CHANGE_MACHINE) {
                func_80095144();
                gMenuChangeMode = MENU_CHANGE_CHANGE_MACHINE;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_CHANGE_COURSE) {
                func_80095144();
                gMenuChangeMode = MENU_CHANGE_CHANGE_COURSE;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_SETTINGS) {
                func_80095144();
                gMenuChangeMode = MENU_CHANGE_SETTINGS;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_100) {
                func_80095144();
                gMenuChangeMode = MENU_CHANGE_6;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_GP_NEXT_COURSE) {
                if ((gNumPlayers == 1) && (gGameMode == GAMEMODE_GP_RACE)) {
                    for (i = 0; i < gTotalRacers; i++) {
                        D_80115D50[i] = gRacers[i].position;
                    }
                }
                func_80095144();
                gMenuChangeMode = MENU_CHANGE_NEXT_COURSE;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_RETIRE_RESTART) {
                func_80095144();
                gMenuChangeMode = MENU_CHANGE_CRASH_RESTART;
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

Gfx* Menus_DrawBeveledBox(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha) {

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

Gfx* Menus_DrawBox(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

extern FinishedSuccessScript gFinishedSuccessScript[];
extern GhostRacer* gFastestGhostRacer;
extern s16 gPlayerLives[];
extern s16 gRacersRemaining;
extern CourseInfo* gCurrentCourseInfo;
extern s32 D_80141900;

void Menus_Init(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 index2;
    s32 temp_a1;
    s32 pad;

    sVsSlotInitialSpeed[VS_SLOT_0] = 6.04f + (Math_Rand2() % 256 / 255.0f * 0.3f) - 0.15f;
    sVsSlotInitialSpeed[VS_SLOT_1] = 4.18f + (Math_Rand1() % 256 / 255.0f * 0.3f) - 0.15f;
    sVsSlotInitialSpeed[VS_SLOT_2] = 5.12f + (Math_Rand2() % 256 / 255.0f * 0.3f) - 0.15f;

    gRacersRemaining = gTotalRacers;
    sFinishedSuccessTime = 0;

    for (i = 0; i < 5; i++) {
        sFinishedSuccessTime += gFinishedSuccessScript[i].time;
    }

    for (i = 0; i < 4; i++) {
        sVsSlotCurrentSlotState[i] = VS_SLOT_STATE_CURRENT_SLOT_0;

        for (j = 0; j < 3; j++) {
            sVsSlotResultIndex[i][j] = Math_Rand2() % 6;
            sVsSlotScrollPosition[i][j] = (Math_Rand2() % 10) * -1.0f;
        }

        sPlayerRetireGameoverFadeTransitionTimer[i] = sPlayerFinishTimer[i] = sPlayerFinishState[i] = 0;

        sVsSlotSpeed[i][VS_SLOT_0] = sVsSlotInitialSpeed[VS_SLOT_0];
        sVsSlotSpeed[i][VS_SLOT_1] = sVsSlotInitialSpeed[VS_SLOT_1];
        sVsSlotSpeed[i][VS_SLOT_2] = sVsSlotInitialSpeed[VS_SLOT_2];

#if !defined(EXPANSION_KIT) && !defined(VERSION_PAL)
        sPlayerGameoverState[i] = D_i3_80141CF0[i] = sPlayerFinalLapTimer[i] = sPlayerBoosterOkTimer[i] =
            sPlayerWinnerLoserFinishGameoverTimer[i] = D_i3_80141B78[i] = sPlayerResultsTimer[i] =
                sPlayerLoserFinishTimer[i] = sFinishGameoverTimer[i] = sPlayerFinishInitialized[i] =
                    sVsSlotCooldownTimer[i] = sPlayerRetireTimer[i] = 0;
#else
        D_i3_8006D0B4 = sPlayerGameoverState[i] = D_i3_80141CF0[i] = sPlayerFinalLapTimer[i] =
            sPlayerBoosterOkTimer[i] = sPlayerWinnerLoserFinishGameoverTimer[i] = D_i3_80141B78[i] =
                sPlayerResultsTimer[i] = sPlayerLoserFinishTimer[i] = sFinishGameoverTimer[i] =
                    sPlayerFinishInitialized[i] = sVsSlotCooldownTimer[i] = sPlayerRetireTimer[i] = 0;
#endif

        sFinishGameoverRotation[i] = sPlayerRetireRelativeLeftPos[i] = 0.0f;
        sPlayerRetireHorizontalSpeed[i] = -20.0f;
        sFinishGameoverRotationSpeed[i] = 10.0f;
    }

    sGhostSaveTimer = sOverwriteGhostOptionIndex = sSaveGhostMenuOpen = sSaveGhostMenuOptionIndex =
        sSaveGhostMenuOptionState = sGpRaceResultsState = sTimeAttackResultsTimer = D_80141D6C = D_i3_80141D88 =
            sMenuRaceIntroTimer = sRaceMenuOptionIndex = sGpResultsEndMenuOptionIndex = sMenuIsBusy =
                sRaceFinishSaveTriggered = sSaveGhostMenuState = sMenuOptionTriggered = D_i3_801419A6 =
                    gShowNameEntryMenu = D_80141900 = sMenuHighlightedOptionMoveTimer = 0;

    sGpResultsRankingScrollPosition = sTotalRankingsManualScrollPosition = 0.0f;
    sSaveGhostMenuOptionsScissorBoxTimer = sGhostSaveMenuScissorBoxTimer = 90;
    sGpResultsEndMenuScissorBoxTimer = sGeneralRaceMenuScissorBoxTimer = 60;
    sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
    sPlayer1Lives = gPlayerLives[0];
    sRetireTexture = TextureCache_LoadAndCache(aRetireTex, TEX_SIZE(aRetireTex, sizeof(u8)), false, false, false);
    sRetirePalette = TextureCache_LoadAndCache(aRetireTLUT, TEX_SIZE(aRetireTLUT, sizeof(u16)), false, false, false);
    TextureCache_LoadAndCache(aMenuTextTLUT, 0x200, false, false, false);
    TextureCache_LoadAndCache(aMenuRetryTex, TEX_SIZE(aMenuRetryTex, sizeof(u8)), false, true, false);
    TextureCache_LoadAndCache(aMenuSettingsTex, TEX_SIZE(aMenuSettingsTex, sizeof(u8)), false, true, false);
    TextureCache_LoadAndCache(aMenuQuitTex, TEX_SIZE(aMenuQuitTex, sizeof(u8)), false, true, false);
    TextureCache_LoadAndCache(aMenuContinueTex, TEX_SIZE(aMenuContinueTex, sizeof(u8)), false, true, false);

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        TextureCache_LoadAndCache(aMenuChangeMachineTex, TEX_SIZE(aMenuChangeMachineTex, sizeof(u8)), false, true,
                                  false);
        TextureCache_LoadAndCache(aBestTex, TEX_SIZE(aBestTex, sizeof(u16)), false, false, false);
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        TextureCache_LoadAndCache(aMenuChangeMachineTex, TEX_SIZE(aMenuChangeMachineTex, sizeof(u8)), false, true,
                                  false);
        TextureCache_LoadAndCache(aMenuChangeCourseTex, TEX_SIZE(aMenuChangeCourseTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuGhostSaveTex, TEX_SIZE(aMenuGhostSaveTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuOverwriteData1Tex, TEX_SIZE(aMenuOverwriteData1Tex, sizeof(u8)), false, true,
                                  false);
        TextureCache_LoadAndCache(aMenuSavedTex, TEX_SIZE(aMenuSavedTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuSavingTex, TEX_SIZE(aMenuSavingTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuYesTex, TEX_SIZE(aMenuYesTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuNoTex, TEX_SIZE(aMenuNoTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuNewGhostTex, TEX_SIZE(aMenuNewGhostTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuSavedGhostTex, TEX_SIZE(aMenuSavedGhostTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuCannotSaveGhostTex, TEX_SIZE(aMenuCannotSaveGhostTex, sizeof(u8)), false, true,
                                  false);
        TextureCache_LoadAndCache(aMenuLeftArrowTex, TEX_SIZE(aMenuLeftArrowTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuRightArrowTex, TEX_SIZE(aMenuRightArrowTex, sizeof(u8)), false, true, false);
#ifdef EXPANSION_KIT
        TextureCache_LoadAndCache(aMenuToGamePakTex, TEX_SIZE(aMenuToGamePakTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuToDiskTex, TEX_SIZE(aMenuToDiskTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(aMenuOverwriteData2Tex, TEX_SIZE(aMenuOverwriteData2Tex, sizeof(u8)), false, true,
                                  false);
#endif
        sLoserTexture = TextureCache_LoadAndCache(aLoserTex, TEX_SIZE(aLoserTex, sizeof(u8)), false, false, false);
        sLoserPalette = TextureCache_LoadAndCache(aLoserTLUT, TEX_SIZE(aLoserTLUT, sizeof(u16)), false, false, false);
        Menus_GetFastestGhostInfo();
        if (gFastestGhostIndex >= 0) {
            sFastestGhostRacerRacer = gFastestGhostRacer->racer;
            sFastestGhostRacerLapDistance = sFastestGhostRacerRacer->lapDistance;
            sFastestGhostRacerLapsCompletedDistance = gCurrentCourseInfo->length * -1.0f;
        }
    }

    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P) || (gGameMode == GAMEMODE_VS_4P) ||
        (gGameMode == GAMEMODE_TIME_ATTACK)) {
        sWinnerTexture = TextureCache_LoadAndCache(aWinnerTex, TEX_SIZE(aWinnerTex, sizeof(u8)), false, false, false);
        sWinnerPalette =
            TextureCache_LoadAndCache(aWinnerTLUT, TEX_SIZE(aWinnerTLUT, sizeof(u16)), false, false, false);
    }
    if ((gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P) ||
        (gGameMode == GAMEMODE_VS_4P)) {
        TextureCache_LoadAndCache(aMenuChangeMachineTex, TEX_SIZE(aMenuChangeMachineTex, sizeof(u8)), false, true,
                                  false);
        TextureCache_LoadAndCache(aMenuChangeCourseTex, TEX_SIZE(aMenuChangeCourseTex, sizeof(u8)), false, true, false);
        TextureCache_LoadAndCache(D_F25D858, TEX_SIZE(D_F25D858, sizeof(u16)), false, false, false);
        TextureCache_LoadAndCache(D_F25E060, TEX_SIZE(D_F25E060, sizeof(u16)), false, false, false);
        TextureCache_LoadAndCache(D_F25E868, TEX_SIZE(D_F25E868, sizeof(u16)), false, false, false);

        for (j = 0; j < 3; j++) {
            sVsSlotResultIndexToPortraitResult[0][j] = VS_SLOT_PORTRAIT_MR_ZERO;
            sVsSlotResultIndexToPortraitResult[1][j] = VS_SLOT_PORTRAIT_MR_ZERO;
            sVsSlotResultIndexToPortraitResult[2][j] = VS_SLOT_PORTRAIT_MR_ZERO;
            sVsSlotResultIndexToPortraitResult[3][j] = VS_SLOT_PORTRAIT_MR_ZERO;
            sVsSlotResultIndexToPortraitResult[4][j] = VS_SLOT_PORTRAIT_X;
            sVsSlotResultIndexToPortraitResult[5][j] = VS_SLOT_PORTRAIT_X;
            sVsSlotResultIndexToPortraitResult[6][j] = VS_SLOT_PORTRAIT_SKULL;
            sVsSlotResultIndexToPortraitResult[7][j] = VS_SLOT_PORTRAIT_SKULL;

            for (i = 0; i < gNumPlayers; i++) {
                sVsSlotResultIndexToPortraitResult[i][j] = gRacers[i].character;
            }

            for (i = 0; i < 3; i++) {
                for (k = 1; k < 4; k++) {
                    if (i != k) {
                        if (sVsSlotResultIndexToPortraitResult[i][j] == sVsSlotResultIndexToPortraitResult[k][j]) {
                            sVsSlotResultIndexToPortraitResult[k][j] = VS_SLOT_PORTRAIT_MR_ZERO;
                        }
                    }
                }
            }

            for (i = 0; i < 30; i++) {
                k = Math_Rand2() % 8;
                index2 = Math_Rand1() % 8;

                temp_a1 = sVsSlotResultIndexToPortraitResult[k][j];
                sVsSlotResultIndexToPortraitResult[k][j] = sVsSlotResultIndexToPortraitResult[index2][j];
                sVsSlotResultIndexToPortraitResult[index2][j] = temp_a1;
            }

            for (i = 0; i < 8; i++) {
                if (sVsSlotResultIndexToPortraitResult[i][j] < 30) {
                    sVsSlotPortraits[i][j] = gCharacterPortraitTextures[sVsSlotResultIndexToPortraitResult[i][j]];
                } else {
                    switch (sVsSlotResultIndexToPortraitResult[i][j]) {
                        case VS_SLOT_PORTRAIT_X:
                            sVsSlotPortraits[i][j] = TextureCache_GetCached(D_F25D858);
                            break;
                        case VS_SLOT_PORTRAIT_SKULL:
                            sVsSlotPortraits[i][j] = TextureCache_GetCached(D_F25E060);
                            break;
                        case VS_SLOT_PORTRAIT_MR_ZERO:
                            sVsSlotPortraits[i][j] = TextureCache_GetCached(D_F25E868);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    func_i3_8011AE70();
    RecordsEntry_Init();
    RecordsEntry_InitNameEntry();

#ifdef EXPANSION_KIT
    Font_LoadString("Ｍ", FONT_SET_5);
    Font_LoadString("ABCDEFGHIJKLMNOPQRSTUVWXYZＡＢ23", FONT_SET_6);
    Font_LoadString("ABCDEFGHIJKLMNOPQRSTUVWXYZ", FONT_SET_3);
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        Font_LoadString(gCurrentCourseInfo->recordNames[0], FONT_SET_1);
    }
#endif
}

extern Racer* gRacersByPosition[];
extern u32 gGameFrameCount;
extern s8 gTitleDemoState;

Gfx* Menus_DrawVsSlot(Gfx* gfx, s32 playerIndex) {
    s32 i;
    s32 slotCharacterMatchCount;
    f32 var_ft5;
    s32 upcomingSlotResultIndex;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 scrollAmount;
    s32 pad[2];

    if (!gGamePaused && (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
        if (sVsSlotSpeed[playerIndex][VS_SLOT_0] != 0.0f) {
            sVsSlotScrollPosition[playerIndex][VS_SLOT_0] += sVsSlotSpeed[playerIndex][VS_SLOT_0];
            if (sVsSlotScrollPosition[playerIndex][VS_SLOT_0] > 0.0f) {
                sVsSlotScrollPosition[playerIndex][VS_SLOT_0] -= 32.0f;
                sVsSlotResultIndex[playerIndex][VS_SLOT_0]++;
                if (sVsSlotResultIndex[playerIndex][VS_SLOT_0] >= 8) {
                    sVsSlotResultIndex[playerIndex][VS_SLOT_0] = 0;
                }
            }
            if (sVsSlotSpeed[playerIndex][VS_SLOT_0] < (sVsSlotInitialSpeed[VS_SLOT_0] * 0.4f)) {
                if ((sVsSlotInitialSpeed[VS_SLOT_0] * -0.4f) < sVsSlotScrollPosition[playerIndex][VS_SLOT_0]) {
                    sVsSlotScrollPosition[playerIndex][VS_SLOT_0] = 0.0f;
                    sVsSlotSpeed[playerIndex][VS_SLOT_0] = 0.0f;
                } else {
                    sVsSlotSpeed[playerIndex][VS_SLOT_0] = sVsSlotInitialSpeed[VS_SLOT_0] * 0.4f;
                }
            }
        }
        if (sVsSlotSpeed[playerIndex][VS_SLOT_1] != 0.0f) {
            sVsSlotScrollPosition[playerIndex][VS_SLOT_1] += sVsSlotSpeed[playerIndex][VS_SLOT_1];
            if (sVsSlotScrollPosition[playerIndex][VS_SLOT_1] > 0.0f) {
                sVsSlotScrollPosition[playerIndex][VS_SLOT_1] -= 32.0f;
                sVsSlotResultIndex[playerIndex][VS_SLOT_1]++;
                if (sVsSlotResultIndex[playerIndex][VS_SLOT_1] >= 8) {
                    sVsSlotResultIndex[playerIndex][VS_SLOT_1] = 0;
                }
            }
            if (sVsSlotSpeed[playerIndex][VS_SLOT_1] < (sVsSlotInitialSpeed[VS_SLOT_1] * 0.4f)) {
                if ((sVsSlotInitialSpeed[VS_SLOT_1] * -0.4f) < sVsSlotScrollPosition[playerIndex][VS_SLOT_1]) {
                    sVsSlotScrollPosition[playerIndex][VS_SLOT_1] = 0.0f;
                    sVsSlotSpeed[playerIndex][VS_SLOT_1] = 0.0f;
                } else {
                    sVsSlotSpeed[playerIndex][VS_SLOT_1] = sVsSlotInitialSpeed[VS_SLOT_1] * 0.4f;
                }
            }
        }
        if (sVsSlotSpeed[playerIndex][VS_SLOT_2] != 0.0f) {
            sVsSlotScrollPosition[playerIndex][VS_SLOT_2] += sVsSlotSpeed[playerIndex][VS_SLOT_2];
            if (sVsSlotScrollPosition[playerIndex][VS_SLOT_2] > 0.0f) {
                sVsSlotScrollPosition[playerIndex][VS_SLOT_2] -= 32.0f;
                sVsSlotResultIndex[playerIndex][VS_SLOT_2]++;
                if (sVsSlotResultIndex[playerIndex][VS_SLOT_2] >= 8) {
                    sVsSlotResultIndex[playerIndex][VS_SLOT_2] = 0;
                }
            }
            if (sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0] ==
                sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_1]][VS_SLOT_1]) {
                if (sVsSlotSpeed[playerIndex][VS_SLOT_2] < (sVsSlotInitialSpeed[VS_SLOT_2] * 0.2f)) {
                    if ((sVsSlotInitialSpeed[VS_SLOT_2] * -0.2f) < sVsSlotScrollPosition[playerIndex][VS_SLOT_2]) {
                        sVsSlotScrollPosition[playerIndex][VS_SLOT_2] = 0.0f;
                        sVsSlotSpeed[playerIndex][VS_SLOT_2] = 0.0f;
                    } else {
                        sVsSlotSpeed[playerIndex][VS_SLOT_2] = sVsSlotInitialSpeed[VS_SLOT_2] * 0.2f;
                    }
                }
            } else if (sVsSlotSpeed[playerIndex][VS_SLOT_2] < (sVsSlotInitialSpeed[VS_SLOT_2] * 0.4f)) {
                if ((sVsSlotInitialSpeed[VS_SLOT_2] * -0.4f) < sVsSlotScrollPosition[playerIndex][VS_SLOT_2]) {
                    sVsSlotScrollPosition[playerIndex][VS_SLOT_2] = 0.0f;
                    sVsSlotSpeed[playerIndex][VS_SLOT_2] = 0.0f;
                } else {
                    sVsSlotSpeed[playerIndex][VS_SLOT_2] = sVsSlotInitialSpeed[VS_SLOT_2] * 0.4f;
                }
            }
        }
        if (sVsSlotCurrentSlotState[playerIndex] > VS_SLOT_STATE_CURRENT_SLOT_0) {
            sVsSlotSpeed[playerIndex][VS_SLOT_0] *= 0.8f;
        }
        if (sVsSlotCurrentSlotState[playerIndex] > VS_SLOT_STATE_CURRENT_SLOT_1) {
            sVsSlotSpeed[playerIndex][VS_SLOT_1] *= 0.8f;
        }
        if (sVsSlotCurrentSlotState[playerIndex] > VS_SLOT_STATE_CURRENT_SLOT_2) {
            if (sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0] ==
                sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_1]][VS_SLOT_1]) {
                sVsSlotSpeed[playerIndex][VS_SLOT_2] *= 0.91f;
            } else {
                sVsSlotSpeed[playerIndex][VS_SLOT_2] *= 0.8f;
            }
        }
        if (sVsSlotCooldownTimer[playerIndex] != 0) {
            sVsSlotCooldownTimer[playerIndex]--;
        } else if (sVsSlotCurrentSlotState[playerIndex] < VS_SLOT_STATE_APPLY_RESULT) {
            if (sVsSlotCurrentSlotState[playerIndex] < VS_SLOT_STATE_CHECK_RESULT) {
                if ((gControllers[gPlayerControlPorts[playerIndex]].buttonPressed & BTN_A) &&
                    (((sVsSlotCurrentSlotState[playerIndex] == VS_SLOT_STATE_CURRENT_SLOT_0) ||
                      ((sVsSlotCurrentSlotState[playerIndex] == VS_SLOT_STATE_CURRENT_SLOT_1) &&
                       (sVsSlotSpeed[playerIndex][VS_SLOT_0] == 0.0f))) ||
                     ((sVsSlotCurrentSlotState[playerIndex] == VS_SLOT_STATE_CURRENT_SLOT_2) &&
                      (sVsSlotSpeed[playerIndex][VS_SLOT_1] == 0.0f)))) {
                    sVsSlotCurrentSlotState[playerIndex]++;
                    Audio_PlayerTriggerSEStart(playerIndex, NA_SE_49);
                }
            }
            if ((sVsSlotCurrentSlotState[playerIndex] == VS_SLOT_STATE_CHECK_RESULT) &&
                ((sVsSlotSpeed[playerIndex][VS_SLOT_0] + sVsSlotSpeed[playerIndex][VS_SLOT_1] +
                  sVsSlotSpeed[playerIndex][VS_SLOT_2]) == 0.0f)) {
                sVsSlotCurrentSlotState[playerIndex]++;
                if ((sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0] ==
                     sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_1]][VS_SLOT_1]) &&
                    (sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0] ==
                     sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_2]][VS_SLOT_2])) {
                    Audio_PlayerTriggerSEStart(playerIndex, NA_SE_48);
                    sVsSlotCooldownTimer[playerIndex] = 120;
                    slotCharacterMatchCount = 0;
                    for (i = 0; i < gTotalRacers; i++) {
                        if ((sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]]
                                                               [VS_SLOT_0] == gRacers[i].character) &&
                            (!(gRacers[i].stateFlags & RACER_STATE_CRASHED))) {
                            gRacers[i].energy = 0.0f;
                            slotCharacterMatchCount++;
                        }
                    }

                    if ((slotCharacterMatchCount == 0) &&
                        (sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0] <
                         TOTAL_RACER_COUNT)) {
                        for (i = 0; i < gTotalRacers; i++) {
                            gRacers[i].energy /= 2.0f;
                        }
                    }
                    if (sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0] ==
                        VS_SLOT_PORTRAIT_X) {
                        gRacersByPosition[0]->energy = 0.0f;
                    }
                    if (sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0] ==
                        VS_SLOT_PORTRAIT_SKULL) {
                        for (i = 0; i < gTotalRacers; i++) {
                            gRacers[i].energy = 0.0f;
                        }
                    }
                    if (sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0] ==
                        VS_SLOT_PORTRAIT_MR_ZERO) {
                        for (i = 0; i < gTotalRacers; i++) {
                            gRacers[i].energy /= 2.0f;
                        }
                    }
                }
            }
        } else {
            sVsSlotCurrentSlotState[playerIndex]++;
            if (sVsSlotCurrentSlotState[playerIndex] >= VS_SLOT_STATE_WAIT_FOR_RESPIN) {
                sVsSlotCurrentSlotState[playerIndex] = VS_SLOT_STATE_WAIT_FOR_RESPIN;
            }
            if (sVsSlotCurrentSlotState[playerIndex] >= VS_SLOT_STATE_WAIT_FOR_RESPIN) {
                if (gControllers[gPlayerControlPorts[playerIndex]].buttonPressed & BTN_B) {
                    sVsSlotCurrentSlotState[playerIndex] = VS_SLOT_STATE_CURRENT_SLOT_0;
                    sVsSlotSpeed[playerIndex][VS_SLOT_0] = sVsSlotInitialSpeed[VS_SLOT_0];
                    sVsSlotSpeed[playerIndex][VS_SLOT_1] = sVsSlotInitialSpeed[VS_SLOT_1];
                    sVsSlotSpeed[playerIndex][VS_SLOT_2] = sVsSlotInitialSpeed[VS_SLOT_2];
                }
            }
        }
        gSPDisplayList(gfx++, D_80149D0);
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, aStartStopGuideTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gfx++, sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] << 2,
                            (sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] - 12) << 2,
                            (sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + 63) << 2,
                            (sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] - 1) << 2, 0, 0, 0, 1 << 12, 1 << 10);
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sPlayersVsSlotPositions[gNumPlayers][playerIndex][0],
                      sPlayersVsSlotPositions[gNumPlayers][playerIndex][1],
                      sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + 127,
                      sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] + 32);
        for (i = 0; i < 3; i++) {
            upcomingSlotResultIndex = sVsSlotResultIndex[playerIndex][i] - 1;
            if (upcomingSlotResultIndex < 0) {
                upcomingSlotResultIndex = 7;
            }
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, sVsSlotPortraits[upcomingSlotResultIndex][i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32,
                                32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            scrollAmount = sVsSlotScrollPosition[playerIndex][i];
            left = sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + (i * 32);
            top = sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] + scrollAmount + 32;
            right = sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + (i * 32) + 31;
            bottom = sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] + scrollAmount + 63;
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 12, 1 << 10);
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, sVsSlotPortraits[sVsSlotResultIndex[playerIndex][i]][i], G_IM_FMT_RGBA,
                                G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            top = sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] + scrollAmount;
            bottom = sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] + scrollAmount + 31;
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 12, 1 << 10);
        }

        left = sPlayersVsSlotPositions[gNumPlayers][playerIndex][0];
        right = sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + 96;
        top = bottom = sPlayersVsSlotPositions[gNumPlayers][playerIndex][1];
        gfx = Menus_DrawBeveledBox(gfx, left, top, right, bottom, 255, 255, 255, 255);
        top = bottom = sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] + 32;
        gfx = Menus_DrawBeveledBox(gfx, left, top, right, bottom, 255, 255, 255, 255);
        gSPDisplayList(gfx++, D_80149D0);
        if ((sVsSlotSpeed[playerIndex][VS_SLOT_0] + sVsSlotSpeed[playerIndex][VS_SLOT_1]) == 0.0f) {
            if ((((sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0]) ==
                  sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_1]][VS_SLOT_1]) &&
                 ((gGameFrameCount % 20) >= 5)) &&
                ((sVsSlotCurrentSlotState[playerIndex] == VS_SLOT_STATE_CURRENT_SLOT_2) ||
                 ((sVsSlotCurrentSlotState[playerIndex] >= VS_SLOT_STATE_CHECK_RESULT) &&
                  (sVsSlotSpeed[playerIndex][VS_SLOT_2] != 0.0f)))) {
                gSPDisplayList(gfx++, D_80149D0);
                gDPPipeSync(gfx++);
                gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gfx++, (sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + 64) << 2,
                                    sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] << 2,
                                    (sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + 95) << 2,
                                    (sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] + 31) << 2, 0, 0, 0, 1 << 12,
                                    1 << 10);
            }
        }
        if (((sVsSlotSpeed[playerIndex][VS_SLOT_0] + sVsSlotSpeed[playerIndex][VS_SLOT_1] +
              sVsSlotSpeed[playerIndex][VS_SLOT_2]) == 0.0f) &&
            (sVsSlotCurrentSlotState[playerIndex] >= VS_SLOT_STATE_CHECK_RESULT)) {
            if (((sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0] ==
                  sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_1]][VS_SLOT_1]) &&
                 (sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_0]][VS_SLOT_0] ==
                  sVsSlotResultIndexToPortraitResult[sVsSlotResultIndex[playerIndex][VS_SLOT_2]][VS_SLOT_2])) &&
                ((gGameFrameCount % 20) >= 5)) {
                gSPDisplayList(gfx++, D_80149D0);
                gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gfx++, (sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + 64) << 2,
                                    sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] << 2,
                                    (sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + 95) << 2,
                                    (sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] + 31) << 2, 0, 0, 0, 1 << 12,
                                    1 << 10);
                for (i = 0; i < 3; i++) {
                    gSPTextureRectangle(gfx++, (sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + (i * 32)) << 2,
                                        sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] << 2,
                                        ((sPlayersVsSlotPositions[gNumPlayers][playerIndex][0] + (i * 32)) + 31) << 2,
                                        (sPlayersVsSlotPositions[gNumPlayers][playerIndex][1] + 31) << 2, 0, 0, 0,
                                        1 << 12, 1 << 10);
                }
            }
        }
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    }
    return gfx;
}

Gfx* Menus_DrawBlankTimeHundredths(Gfx* gfx, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return Hud_DrawBlankTimeHundredths(gfx, left + 8, top);
}

Gfx* Menus_DrawBlankTimeThousandths(Gfx* gfx, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return Hud_DrawBlankTimeThousandths(gfx, left + 8, top);
}

Gfx* Menus_DrawRaceTimeInterval(Gfx* gfx, s32 time, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }
    if (time <= -MAX_TIMER) {
        time = -MAX_TIMER;
    }

    return Hud_DrawRaceTimeInterval(gfx, time, left, top, 1.0f);
}

extern s32 gTotalLapCount;
extern s16 gCurrentTimeAttackRecordPosition;
extern s16 gBestTimedLap;

Gfx* Menus_DrawRaceResultsTimes(Gfx* gfx, s32 playerIndex) {
    s32 lap;
    s32 left;
    s32 top;
    s32 i;
    f32 scale = 1.0f;

    gSPDisplayList(gfx++, D_80149D0);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, aLapTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left = sResultsTimesLapLeft - sTimeAttackResultsTimer;
    if (left >= 0) {
        for (i = 1; i <= gTotalLapCount; i++) {
            top = ((i - 1) * sResultsTimesVerticalSpacing) + sResultsTimesTop + 3;
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (15.0f * scale)) << 2,
                                    (s32) (top + (11.0f * scale)) << 2, 0, 0, 0, (s32) (4096.0f / scale),
                                    (s32) (1024.0f / scale));
        }
    }
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left += 17;

    if (left >= 0) {
        for (i = 1; i <= gTotalLapCount; i++) {
            top = ((i - 1) * sResultsTimesVerticalSpacing) + sResultsTimesTop + 3;

            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (7.0f * scale)) << 2,
                                    (s32) (top + (11.0f * scale)) << 2, 0, 0, (i * 12) << 5, (s32) (4096.0f / scale),
                                    (s32) (1024.0f / scale));
        }
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, aHudTimeTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left = sResultsTimesLapLeft - sTimeAttackResultsTimer;
    top = (gTotalLapCount * sResultsTimesVerticalSpacing) + (sResultsTimesVerticalSpacing / 2) + sResultsTimesTop;
    if (left > 0) {
        gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (23.0f * scale)) << 2,
                                (s32) (top + (15.0f * scale)) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (lap = 0; lap < gTotalLapCount; lap++) {
        top = (lap * sResultsTimesVerticalSpacing) + sResultsTimesTop;
        if (sPlayerResultsTimer[playerIndex] < ((sResultsTimesStartLapSpacing * lap) + sResultsTimesStartTopOffset)) {
            top += (((sResultsTimesStartLapSpacing * lap) + sResultsTimesStartTopOffset) -
                    sPlayerResultsTimer[playerIndex]) *
                   sResultsTimesSpeed;
        }
        if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
            ((((sResultsTimesStartLapSpacing * lap) + sResultsTimesStartTopOffset) -
              sPlayerResultsTimer[playerIndex]) == 1) &&
            (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
            Audio_TriggerSystemSE(NA_SE_34);
        }
        if (top < SCREEN_HEIGHT) {
            gDPPipeSync(gfx++);
            if ((lap + 1) == gBestTimedLap) {
                gfx = TextureUtils_SetPulsingColor(gfx, 255, 0, 0);
                gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
            gfx = Hud_DrawTimerScisThousandths(
                gfx, gRacers[playerIndex].lapTimes[lap],
                sResultsTimesLapLeft + sResultsTimesLapLeftFromLap + sTimeAttackResultsTimer, top, 1.0f);
        }
    }

    top = (gTotalLapCount * sResultsTimesVerticalSpacing) + (sResultsTimesVerticalSpacing / 2) + sResultsTimesTop;
    if (sPlayerResultsTimer[playerIndex] < ((sResultsTimesStartLapSpacing * lap) + sResultsTimesStartTopOffset)) {
        top += (((sResultsTimesStartLapSpacing * gTotalLapCount) + sResultsTimesStartTopOffset) -
                sPlayerResultsTimer[playerIndex]) *
               sResultsTimesSpeed;
    }
    if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
        ((((sResultsTimesStartLapSpacing * gTotalLapCount) + sResultsTimesStartTopOffset) -
          sPlayerResultsTimer[playerIndex]) == 1) &&
        (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
        Audio_TriggerSystemSE(NA_SE_34);
    }
    if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
        ((((sResultsTimesStartLapSpacing * (gTotalLapCount + 1)) + sResultsTimesStartTopOffset) -
          sPlayerResultsTimer[playerIndex]) == 1) &&
        (gCurrentTimeAttackRecordPosition == 1) && (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
        Audio_TriggerSystemSE(NA_SE_42);
    }
    if (top < SCREEN_HEIGHT) {
        gDPPipeSync(gfx++);
        if (gCurrentTimeAttackRecordPosition != 0) {
            gfx = TextureUtils_SetPulsingColor(gfx, 255, 0, 0);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
        gfx = Hud_DrawTimerScisThousandths(gfx, gRacers[playerIndex].raceTime,
                                           sResultsTimesLapLeft + sResultsTimesLapLeftFromLap + sTimeAttackResultsTimer,
                                           top, 1.0f);
    }

    sPlayerResultsTimer[playerIndex]++;
    if (sPlayerResultsTimer[playerIndex] >= 3000) {
        sPlayerResultsTimer[playerIndex] = 3000;
    }
    return gfx;
}

Gfx* Menu_DrawGpResultsCharacterPortraits(Gfx* gfx) {
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

        if (sPlayerResultsTimer[index] < var_s6) {
            temp_v0 = (((i * 10) - sPlayerResultsTimer[index]) * 10) + 600;
            left += temp_v0;
            scale += (temp_v0 * 0.03f);
        }

        if (sPlayerResultsTimer[index] == var_s6) {
            switch (i) {
                case 0:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_24);
                    }
                    break;
                case 1:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_25);
                    }
                    break;
                case 2:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_26);
                    }
                    break;
                case 3:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_27);
                    }
                    break;
                case 4:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_28);
                    }
                    break;
                case 5:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_29);
                    }
                    break;
            }
        }

        if (left < SCREEN_WIDTH) {
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

Gfx* Menus_DrawResultsRankingCharacterPortrait(Gfx* gfx, s32 racerId, s32 character, s32 left, s32 top, f32 scale) {
    s32 pad;

    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTextureBlock(gfx++, gCharacterPortraitTextures[character], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * scale) << 2,
                            (s32) (top + 32.0f * scale) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                            (s32) (1024.0f / scale));

    if ((racerId == 0) && ((gGameFrameCount % 20) >= 5)) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * scale) << 2,
                                (s32) (top + 32.0f * scale) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                (s32) (1024.0f / scale));
    }
    return gfx;
}

Gfx* Menus_DrawGpResultsPortraitsTimes(Gfx* gfx) {

    gfx = Menu_DrawGpResultsCharacterPortraits(gfx);
    sResultsTimesLapLeft = 196;
    sResultsTimesTop = 16;
    sResultsTimesVerticalSpacing = 24;
    sResultsTimesLapLeftFromLap = 30;
    sResultsTimesStartTopOffset = 30;
    sResultsTimesStartLapSpacing = 10;
    sResultsTimesSpeed = 10;
    gfx = Menus_DrawRaceResultsTimes(gfx, 0);
    return gfx;
}

Gfx* Menus_DrawLoser(Gfx* gfx, s32 left, s32 top, f32 scale) {
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

Gfx* Menus_DrawWinner(Gfx* gfx, s32 left, s32 top, f32 scale) {
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

Gfx* Menus_DrawPlayerWinner(Gfx* gfx, s32 playerIndex) {
    s32 i;
    s32 j;
    s32 startLeft;
    s32 startTop;
    s32 endLeft;
    s32 endTop;
    s32 isWinner;
    s32 winnerLeft;
    s32 winnerTop;
    f32 scale;
    f32 lerpFactor;
    s32 temp;
    s32 pad[2];
    f32 startScale;
    f32 endScale;
    s32 sortedPlayersByPosition[8];

    if (gRacers[playerIndex].position == 1) {
        isWinner = 1;
    } else {
        isWinner = 0;
    }

    switch (gNumPlayers) {
        case 1:
            endLeft = 100;
            startLeft = 100;
            startTop = 100;
            endTop = 170;
            startScale = 1.0f;
            endScale = 1.0f;
            break;
        case 2:
            startScale = 1.0f;
            endScale = 0.6f;
            startLeft = 100;
            endLeft = 210;
            switch (playerIndex) {
                case 0:
                    startTop = 43;
                    endTop = 21;
                    break;
                case 1:
                    endTop = 133;
                    startTop = 155;
                    break;
                case 2:
                case 3:
                    isWinner = 0;
                    D_80141D70 = true;
                    break;
            }
            break;
        case 3:
            startScale = 0.75f;
            endScale = 0.4f;
            switch (playerIndex) {
                case 0:
                    startLeft = 43;
                    startTop = 43;
                    break;
                case 1:
                    startTop = 155;
                    startLeft = 43;
                    break;
                case 2:
                    startTop = 43;
                    startLeft = 183;
                    break;
                case 3:
                    isWinner = 0;
                    D_80141D70 = true;
                    break;
            }
            endTop = startTop - 20;
            endLeft = startLeft + 54;
            break;
        case 4:
            startScale = 0.75f;
            endScale = 0.4f;
            switch (playerIndex) {
                case 0:
                    startLeft = 43;
                    startTop = 43;
                    break;
                case 1:
                    startLeft = 43;
                    startTop = 155;
                    break;
                case 2:
                    startLeft = 183;
                    startTop = 43;
                    break;
                case 3:
                    startLeft = 183;
                    startTop = 155;
                    break;
            }
            endTop = startTop - 20;
            endLeft = startLeft + 54;
            break;
    }
    if (isWinner == 1) {
        if (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] <= 60) {
            winnerLeft = startLeft;
            winnerTop = startTop;
            scale = startScale;
        } else if (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] >= 70) {
            winnerLeft = endLeft;
            winnerTop = endTop;
            scale = endScale;
        } else {
            lerpFactor = sPlayerWinnerLoserFinishGameoverTimer[playerIndex] - 60;
            winnerLeft = (startLeft + (((endLeft - startLeft) / 10.0f) * lerpFactor));
            winnerTop = (startTop + (((endTop - startTop) / 10.0f) * lerpFactor));
            scale = (((endScale - startScale) / 10.0f) * lerpFactor) + startScale;
        }
        if ((sPlayerWinnerLoserFinishGameoverTimer[playerIndex] > 60) || (gGameFrameCount & 4)) {
            gfx = Menus_DrawWinner(gfx, winnerLeft, winnerTop, scale);
        }
    }

    sPlayerWinnerLoserFinishGameoverTimer[playerIndex]++;
    if ((gNumPlayers >= 2) &&
        (((sPlayerWinnerLoserFinishGameoverTimer[playerIndex] == 1)) ||
         (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] == 60)) &&
        (playerIndex < gNumPlayers)) {

        for (i = 0; i < gTotalRacers; i++) {
            sortedPlayersByPosition[i] = i;
        }

        for (i = 0; i < gTotalRacers - 1; i++) {
            for (j = i + 1; j < gTotalRacers; j++) {
                if (sortedPlayersByPosition[i] >= gNumPlayers) {
                    temp = sortedPlayersByPosition[i];
                    sortedPlayersByPosition[i] = sortedPlayersByPosition[j];
                    sortedPlayersByPosition[j] = temp;
                } else if ((sortedPlayersByPosition[j] < gNumPlayers) &&
                           (gRacers[sortedPlayersByPosition[j]].position <
                            gRacers[sortedPlayersByPosition[i]].position)) {
                    temp = sortedPlayersByPosition[i];
                    sortedPlayersByPosition[i] = sortedPlayersByPosition[j];
                    sortedPlayersByPosition[j] = temp;
                }
            }
        }

        if (playerIndex == sortedPlayersByPosition[0]) {
            if (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] == 60) {

                if (gRacers[playerIndex].stateFlags & RACER_STATE_CRASHED) {
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
#ifndef EXPANSION_KIT
                        Audio_RomBgmStart(BGM_24);
#else
                        func_8070DAD4(BGM_24);
#endif
                    }
                } else if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
#ifndef EXPANSION_KIT
                    Audio_RomBgmStart(BGM_22);
#else
                    func_8070DAD4(BGM_22);
#endif
                }
                for (i = 0; i < gNumPlayers; i++) {
                    if ((gRacers[i].stateFlags & RACER_STATE_CRASHED) ||
                        (gRacers[playerIndex].stateFlags & RACER_STATE_FINISHED)) {
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_3);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_4);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_5);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_8);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_9);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_10);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_11);
                    }
                }

            } else if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                func_8007E0CC();
            }
        }
    }
    if (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] >= 600) {
        sPlayerWinnerLoserFinishGameoverTimer[playerIndex] = 600;
    }
    return gfx;
}

Gfx* Menus_DrawPlayerLoser(Gfx* gfx, s32 playerIndex) {
    s32 i;
    s32 j;
    s32 startLeft;
    s32 startTop;
    s32 endLeft;
    s32 endTop;
    s32 isLoser;
    s32 loserLeft;
    s32 loserTop;
    f32 scale;
    f32 lerpFactor;
    s32 temp;
    s32 pad[2];
    f32 startScale;
    f32 endScale;

    if (gRacers[playerIndex].position == 1) {
        isLoser = 1;
    } else {
        isLoser = 0;
    }

    switch (gNumPlayers) {
        case 1:
            startLeft = 130;
            endLeft = 130;
            startTop = 100;
            endTop = 170;
            startScale = 1.0f;
            endScale = 1.0f;
            break;
        case 2:
            startScale = 1.0f;
            endScale = 0.6f;
            startLeft = 100;
            endLeft = 210;
            switch (playerIndex) {
                case 0:
                    startTop = 43;
                    endTop = 21;
                    break;
                case 1:
                    endTop = 133;
                    startTop = 155;
                    break;
                case 2:
                case 3:
                    isLoser = 0;
                    D_80141D70 = true;
                    break;
            }
            break;
        case 3:
            startScale = 0.75f;
            endScale = 0.4f;
            switch (playerIndex) {
                case 0:
                    startLeft = 43;
                    startTop = 43;
                    break;
                case 1:
                    startTop = 155;
                    startLeft = 43;
                    break;
                case 2:
                    startTop = 43;
                    startLeft = 183;
                    break;
                case 3:
                    isLoser = 0;
                    D_80141D70 = true;
                    break;
            }
            endTop = startTop - 20;
            endLeft = startLeft + 54;
            break;
        case 4:
            startScale = 0.75f;
            endScale = 0.4f;
            switch (playerIndex) {
                case 0:
                    startLeft = 43;
                    startTop = 43;
                    break;
                case 1:
                    startLeft = 43;
                    startTop = 155;
                    break;
                case 2:
                    startLeft = 183;
                    startTop = 43;
                    break;
                case 3:
                    startLeft = 183;
                    startTop = 155;
                    break;
            }
            endTop = startTop - 20;
            endLeft = startLeft + 54;
            break;
    }
    if (isLoser == 1) {
        if (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] <= 60) {
            loserLeft = startLeft;
            loserTop = startTop;
            scale = startScale;
        } else if (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] >= 70) {
            loserLeft = endLeft;
            loserTop = endTop;
            scale = endScale;
        } else {
            lerpFactor = sPlayerWinnerLoserFinishGameoverTimer[playerIndex] - 60;
            loserLeft = (startLeft + (((endLeft - startLeft) / 10.0f) * lerpFactor));
            loserTop = (startTop + (((endTop - startTop) / 10.0f) * lerpFactor));
            scale = (((endScale - startScale) / 10.0f) * lerpFactor) + startScale;
        }
        if ((sPlayerWinnerLoserFinishGameoverTimer[playerIndex] > 60) || (gGameFrameCount & 4)) {
            gfx = Menus_DrawLoser(gfx, loserLeft, loserTop, scale);
        }
    }

    sPlayerWinnerLoserFinishGameoverTimer[playerIndex]++;

    if (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] >= 600) {
        sPlayerWinnerLoserFinishGameoverTimer[playerIndex] = 600;
    }
    return gfx;
}

Gfx* Menus_DrawFinalLap(Gfx* gfx, s32 left, s32 top, f32 scale) {
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

Gfx* Menus_DrawPlayerFinalLap(Gfx* gfx, s32 playerIndex) {
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
            switch (playerIndex) {
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
            switch (playerIndex) {
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
    return Menus_DrawFinalLap(gfx, left, top, scale);
}

Gfx* Menus_DrawBoosterOk(Gfx* gfx, s32 left, s32 top, f32 scale) {
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

Gfx* Menus_DrawPlayerBoosterOk(Gfx* gfx, s32 playerIndex) {
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
            switch (playerIndex) {
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
            switch (playerIndex) {
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
    return Menus_DrawBoosterOk(gfx, left, top, scale);
}

void Menus_InitFinish(s32 playerIndex) {
    sFinishGameoverRotationSpeed[playerIndex] = gRacers[playerIndex].speed * 0.05f;
    sFinishGameoverRotation[playerIndex] = 0.0f;
    sPlayerLoserFinishTimer[playerIndex] = 0;
    sFinishGameoverTimer[playerIndex] = 0;
}

extern GfxPool D_1000000;
extern GfxPool* gGfxPool;

Gfx* Menus_DrawFinish(Gfx* gfx, s32 playerIndex) {
    s32 pad[4];
    f32 temp;
    f32 temp_fv0_2;
    s32 i;
    Vec3f pos;
    Vec3f forward;
    Vec3f up;
    Vec3f lookAt;
    s32 angle;

    forward.x = gCameras[playerIndex].basis.x.x;
    forward.y = gCameras[playerIndex].basis.x.y;
    forward.z = gCameras[playerIndex].basis.x.z;
    sqrtf(SQ(forward.x) + SQ(forward.y) + SQ(forward.z));

    if (sFinishGameoverTimer[playerIndex] <= 10) {
        pos.x = 0 * 0;
        pos.y = 0 * -2;
        pos.z = 0 * 2 + 180.0f;
    } else if (sFinishGameoverTimer[playerIndex] >= 30) {
        pos.x = 20.0f * 0;
        pos.y = 20.0f * -2;
        pos.z = 20.0f * 2 + 180.0f;
    } else {
        temp_fv0_2 = sFinishGameoverTimer[playerIndex] - 10;
        pos.x = temp_fv0_2 * 0;
        pos.y = temp_fv0_2 * -2;
        pos.z = (temp_fv0_2 * 2) + 180.0f;
    }

    sFinishGameoverRotation[playerIndex] += sFinishGameoverRotationSpeed[playerIndex];
    sFinishGameoverRotationSpeed[playerIndex] *= 0.92f;
    if (sFinishGameoverRotationSpeed[playerIndex] < 0.08f) {
        sFinishGameoverRotationSpeed[playerIndex] = 0.08f;
    }
    while (sFinishGameoverRotation[playerIndex] < 0.0f) {
        sFinishGameoverRotation[playerIndex] += M_TWO_PI;
    }
    while (sFinishGameoverRotation[playerIndex] > M_TWO_PI) {
        sFinishGameoverRotation[playerIndex] -= M_TWO_PI;
    }
    if ((sFinishGameoverRotationSpeed[playerIndex] <= 0.08f) &&
        (sFinishGameoverRotation[playerIndex] >= (0.92f * M_TWO_PI))) {
        sFinishGameoverRotation[playerIndex] = (0.92f * M_TWO_PI);
        sFinishGameoverRotationSpeed[playerIndex] = 0.0f;
    }
    temp = sFinishGameoverRotation[playerIndex];
    angle = RAD_TO_FZXANG(temp);

    lookAt.x = 0;
    lookAt.y = SIN(angle);
    lookAt.z = -COS(angle);

    up.x = 0;
    up.y = COS(angle);
    up.z = SIN(angle);

    gfx = func_i3_8012EE90(gfx, playerIndex);

    gSPMatrix(gfx++, &D_1000000.unk_20008[playerIndex], G_MTX_PUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_20108[playerIndex], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_400A258);
    gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BACK);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    Matrix_SetLockedLookAt(gGfxPool->unk_21988, NULL, 0.07f, 0.07f, 0.07f, lookAt.x, lookAt.y, lookAt.z, up.x, up.y,
                           up.z, pos.x, pos.y, pos.z);
    gSPMatrix(gfx++, gGfxPool->unk_21988, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, aFinishDL);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);

    sPlayerWinnerLoserFinishGameoverTimer[playerIndex]++;
    if (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] == 2) {
        if ((gGameMode == GAMEMODE_TIME_ATTACK) || (gGameMode == GAMEMODE_GP_RACE)) {
            if (gTotalLapCount == 3) {
                sMenuStateFlags |= MENU_STATE_RACE_FINISH_SAVE;
            }
        } else if (gGameMode == GAMEMODE_DEATH_RACE) {
            sMenuStateFlags |= MENU_STATE_RACE_FINISH_SAVE;
        }
    }

    if (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] == 60) {
        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
#ifndef EXPANSION_KIT
            Audio_RomBgmStart(BGM_22);
#else
            func_8070DAD4(BGM_22);
#endif
        }
        for (i = 0; i < gNumPlayers; i++) {
            if ((gRacers[i].stateFlags & RACER_STATE_CRASHED) ||
                (gRacers[playerIndex].stateFlags & RACER_STATE_FINISHED)) {
                Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_3);
                Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_4);
                Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_5);
                Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_8);
                Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_9);
                Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_10);
                Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_11);
            }
        }
    }

    if (sFinishGameoverRotationSpeed[playerIndex] == 0.0f) {
        sFinishGameoverTimer[playerIndex]++;
        if (sFinishGameoverTimer[playerIndex] >= 600) {
            sFinishGameoverTimer[playerIndex] = 600;
        }
    }
    return gfx;
}

void Menus_InitGameover(s32 playerIndex) {
    sFinishGameoverRotationSpeed[playerIndex] = 0.25f;
    sFinishGameoverTimer[playerIndex] = 0;
    sFinishGameoverRotation[playerIndex] = 0.0f;
    sGameoverScale = 0.001f;
}

Gfx* Menus_DrawGameover(Gfx* gfx, s32 playerIndex) {
    s32 pad[4];
    f32 temp_fv0_2;
    s32 row;
    s32 alpha;
    Vec3f pos;
    Vec3f forward;
    Vec3f up;
    Vec3f lookAt;
    s32 angle;

    forward.x = gCameras[playerIndex].basis.x.x;
    forward.y = gCameras[playerIndex].basis.x.y;
    forward.z = gCameras[playerIndex].basis.x.z;
    sqrtf(SQ(forward.x) + SQ(forward.y) + SQ(forward.z));
    if ((gNumPlayers == 1) && (sFinishGameoverRotationSpeed[playerIndex] <= 0.02f)) {
        gControllers[gGameFrameCount % 4].unk_78 = 1;
        sPlayerRetireGameoverFadeTransitionTimer[0] += 2;
        if (sPlayerRetireGameoverFadeTransitionTimer[0] == 250) {
            Audio_Retire();
            Audio_LevelSEFadeout();
        }
        if (sPlayerRetireGameoverFadeTransitionTimer[0] > 1000) {
            sPlayerRetireGameoverFadeTransitionTimer[0] = 1000;
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
            alpha = (sPlayerRetireGameoverFadeTransitionTimer[0] + alpha) - 150;
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

    if (gRacers[playerIndex].stateFlags & RACER_STATE_FINISHED) {
        if (sFinishGameoverTimer[playerIndex] <= 10) {
            pos.x = 0;
            pos.y = 0.f;
            pos.z = 20.0f;
        } else if (sFinishGameoverTimer[playerIndex] >= 30) {
            pos.x = 0;
            pos.y = 20.0f * -0.15f;
            pos.z = 20.0f;
        } else {
            temp_fv0_2 = sFinishGameoverTimer[playerIndex] - 10;
            pos.x = temp_fv0_2 * 0;
            pos.y = temp_fv0_2 * -0.15f;
            pos.z = pos.x + 20.0f;
        }
    } else {
        pos.x = 0;
        pos.y = 0;
        pos.z = 20.0f;
    }

    sFinishGameoverRotation[playerIndex] += sFinishGameoverRotationSpeed[playerIndex];
    sFinishGameoverRotationSpeed[playerIndex] *= 0.99f;
    if (sFinishGameoverRotationSpeed[playerIndex] < 0.02f) {
        sFinishGameoverRotationSpeed[playerIndex] = 0.02f;
    }
    if ((sFinishGameoverRotationSpeed[playerIndex] <= 0.02f) && (sFinishGameoverRotation[playerIndex] >= M_TWO_PI)) {
        sFinishGameoverRotation[playerIndex] = M_TWO_PI;
        sFinishGameoverRotationSpeed[playerIndex] = 0.0f;
    }

    if (sFinishGameoverRotationSpeed[playerIndex] == 0.0f) {
        sFinishGameoverTimer[playerIndex]++;
        if (sFinishGameoverTimer[playerIndex] >= 600) {
            sFinishGameoverTimer[playerIndex] = 600;
        }
    }
    while (sFinishGameoverRotation[playerIndex] < 0.0f) {
        sFinishGameoverRotation[playerIndex] += M_TWO_PI;
    }
    while (sFinishGameoverRotation[playerIndex] > M_TWO_PI) {
        sFinishGameoverRotation[playerIndex] -= M_TWO_PI;
    }

    angle = RAD_TO_FZXANG(sFinishGameoverRotation[playerIndex]);

    lookAt.x = SIN(angle);
    lookAt.y = 0.0f;
    lookAt.z = -COS(angle);

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;

    gfx = func_i3_8012EE90(gfx, playerIndex);
    gSPMatrix(gfx++, &D_1000000.unk_20008[playerIndex], G_MTX_PUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_20108[playerIndex], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_400A258);

    sGameoverScale += 0.00005f;
    if (sGameoverScale >= 0.009f) {
        sGameoverScale = 0.009f;
        if ((gControllers[gPlayerControlPorts[playerIndex]].buttonPressed & (BTN_A | BTN_START)) &&
            (sFinishGameoverTimer[playerIndex] >= 60) && !sMenuIsBusy) {
            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                Audio_LevelSEFadeout();
            }
            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                func_8007E0CC();
            }
            sMenuIsBusy = true;
            sMenuStateFlags |= MENU_STATE_QUIT;
        }
    }

    Matrix_SetLockedLookAt(gGfxPool->unk_21988, NULL, sGameoverScale, sGameoverScale, sGameoverScale, lookAt.x,
                           lookAt.y, lookAt.z, up.x, up.y, up.z, pos.x, pos.y, pos.z);
    gSPMatrix(gfx++, gGfxPool->unk_21988, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, aExecuteGameoverDL);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);

    sPlayerWinnerLoserFinishGameoverTimer[playerIndex]++;
    return gfx;
}

Gfx* Menus_DrawPlayerFinishTime(Gfx* gfx, s32 playerIndex) {
    s32 pad;
    s32 left;
    s32 top;

    if (gNumPlayers < 3) {
        switch (playerIndex) {
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
        switch (playerIndex) {
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
    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return Hud_DrawTimerScisThousandths(gfx, gRacers[playerIndex].raceTime, left, top, 1.0f);
}

Gfx* Menus_DrawRaceMenuTexture(Gfx* gfx, s32 textureIndex, s32 left, s32 top) {

    if (textureIndex >= 24) {
        return gfx;
    }

    return TextureUtils_DrawIndexedBlocks(gfx, TextureCache_GetCached(sRaceMenuTextures[textureIndex]), NULL,
                                          G_IM_FMT_CI, 1, left, top, sRaceMenuDimensions[textureIndex * 2 + 0],
                                          sRaceMenuDimensions[textureIndex * 2 + 1], INDEXED_DRAW_TINT_PRIM_COLOR);
}

s32 Menus_UpdateHighlightedOptionVertical(s32 playerIndex, s32 highlightedOption, s32 maxOptionValue) {
    s32 optionChange = 0;
    s32 stickY = gControllers[gPlayerControlPorts[playerIndex]].stickY;

    if (stickY > 50) {
        optionChange = -1;
        sMenuHighlightedOptionMoveTimer++;
    } else if (stickY < -50) {
        optionChange = 1;
        sMenuHighlightedOptionMoveTimer++;
    } else {
        if (gControllers[gPlayerControlPorts[playerIndex]].buttonPressed & BTN_UP) {
            optionChange = -1;
            sMenuHighlightedOptionMoveTimer = 1;
        } else if (gControllers[gPlayerControlPorts[playerIndex]].buttonPressed & BTN_DOWN) {
            optionChange = 1;
            sMenuHighlightedOptionMoveTimer = 1;
        } else {
            sMenuHighlightedOptionMoveTimer = 0;
        }
    }

    if ((sMenuHighlightedOptionMoveTimer == 1) || (sMenuHighlightedOptionMoveTimer == 60)) {
        highlightedOption += optionChange;
        if (highlightedOption == -1) {
            highlightedOption = maxOptionValue;
        }
        if (highlightedOption == (maxOptionValue + 1)) {
            highlightedOption = 0;
        }
        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
            Audio_TriggerSystemSE(NA_SE_30);
        }
    }
    if (sMenuHighlightedOptionMoveTimer >= 75) {
        sMenuHighlightedOptionMoveTimer = 59;
    }

    Math_Rand1();
    Math_Rand2();
    return highlightedOption;
}

s32 Menus_UpdateHighlightedOptionHorizontal(s32 playerIndex, s32 highlightedOption, s32 maxOptionValue) {
    s32 optionChange = 0;
    s32 stickX = gControllers[gPlayerControlPorts[playerIndex]].stickX;

    if (stickX > 50) {
        optionChange = -1;
        sMenuHighlightedOptionMoveTimer++;
    } else if (stickX < -50) {
        optionChange = 1;
        sMenuHighlightedOptionMoveTimer++;
    } else {
        if (gControllers[gPlayerControlPorts[playerIndex]].buttonPressed & BTN_LEFT) {
            optionChange = -1;
            sMenuHighlightedOptionMoveTimer = 1;
        } else if (gControllers[gPlayerControlPorts[playerIndex]].buttonPressed & BTN_RIGHT) {
            optionChange = 1;
            sMenuHighlightedOptionMoveTimer = 1;
        } else {
            sMenuHighlightedOptionMoveTimer = 0;
        }
    }

    if ((sMenuHighlightedOptionMoveTimer == 1) || (sMenuHighlightedOptionMoveTimer == 60)) {
        highlightedOption += optionChange;
        if (highlightedOption == -1) {
            highlightedOption = maxOptionValue;
        }
        if (highlightedOption == (maxOptionValue + 1)) {
            highlightedOption = 0;
        }
        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
            Audio_TriggerSystemSE(NA_SE_30);
        }
    }
    if (sMenuHighlightedOptionMoveTimer >= 75) {
        sMenuHighlightedOptionMoveTimer = 59;
    }

    Math_Rand1();
    Math_Rand2();
    return highlightedOption;
}

Gfx* Menus_SetOptionColor(Gfx* gfx, s32 arg1) {

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

void Menus_GetFastestGhostInfo(void) {

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

s32 Menus_AttemptSaveGhost(void) {
    Menus_GetFastestGhostInfo();
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

#ifdef EXPANSION_KIT
void Menus_LoadSortedDDGhostRecords(void) {
    s32 tempIndex;
    s32 i;
    s32 j;

    sDDGhostRecords[0].raceTime = sDDGhostRecords[1].raceTime = sDDGhostRecords[2].raceTime = MAX_TIMER;

    DDSave_LoadCachedCourseGhostRecords(gCourseIndex, sDDGhostRecords);

    for (i = 0; i < 3; i++) {
        sSortedDDGhostRecordPtrs[i] = &sDDGhostRecords[i];
        sSortedDDGhostRecordIndices[i] = i;
    }

    for (i = 0; i < 2; i++) {
        for (j = i + 1; j < 3; j++) {
            if (sSortedDDGhostRecordPtrs[i]->raceTime > sSortedDDGhostRecordPtrs[j]->raceTime) {
                sTempDDGhostRecordPtr = sSortedDDGhostRecordPtrs[i];
                sSortedDDGhostRecordPtrs[i] = sSortedDDGhostRecordPtrs[j];
                sSortedDDGhostRecordPtrs[j] = sTempDDGhostRecordPtr;
                tempIndex = sSortedDDGhostRecordIndices[i];
                sSortedDDGhostRecordIndices[i] = sSortedDDGhostRecordIndices[j];
                sSortedDDGhostRecordIndices[j] = tempIndex;
            }
        }
    }
}
#endif

extern s32 gCupType;

s32 Menus_CheckGhostCanSave(void) {
#ifdef EXPANSION_KIT
    s32 sp1C;
    s32 i;
#endif

    sCannotSaveGhost = false;
    if (gCourseIndex >= COURSE_X_1) {
        sCannotSaveGhost = true;
        return 0;
    }
    Menus_GetFastestGhostInfo();
    if (sFastestGhostIndex == -1) {
        sCannotSaveGhost = true;
        sSaveGhostMenuOpen = false;
        return -1;
    }
#ifndef EXPANSION_KIT
    if (Save_LoadGhostInfo(&gSavedGhostInfo) != 0) {
        return 0;
    }
    if ((gSavedGhostInfo.courseIndex == gCourseIndex) && (sFastestGhostTime >= gSavedGhostInfo.raceTime)) {
        sCannotSaveGhost = true;
    }
#else
    sp1C = Save_LoadGhostInfo(&gSavedGhostInfo);
    Menus_LoadSortedDDGhostRecords();
    if ((sp1C == 0) && (gSavedGhostInfo.courseIndex == gCourseIndex) &&
        (sFastestGhostTime >= gSavedGhostInfo.raceTime)) {
        sCannotSaveGhost = true;
    }

    for (i = 0; i < 3; i++) {
        if ((sFastestGhostTime >= sDDGhostRecords[i].raceTime) &&
            (sDDGhostRecords[i].encodedCourseIndex == gCourseInfos[gCourseIndex].encodedCourseIndex)) {
            sCannotSaveGhost = true;
        }
    }

    if (gCupType == X_CUP) {
        sCannotSaveGhost = true;
    } else if ((gSavedGhostInfo.courseIndex == gCourseIndex) && (sFastestGhostTime == gSavedGhostInfo.raceTime) &&
               (gSavedGhostInfo.replayChecksum == gFastestGhost->replayChecksum)) {
        sCannotSaveGhost = true;
    } else if ((sFastestGhostTime == sDDGhostRecords[0].raceTime) &&
               (gFastestGhost->replayChecksum == sDDGhostRecords[0].replayChecksum)) {
        sCannotSaveGhost = true;
    } else if ((sFastestGhostTime == sDDGhostRecords[1].raceTime) &&
               (gFastestGhost->replayChecksum == sDDGhostRecords[1].replayChecksum)) {
        sCannotSaveGhost = true;
    } else if ((sFastestGhostTime == sDDGhostRecords[2].raceTime) &&
               (gFastestGhost->replayChecksum == sDDGhostRecords[2].replayChecksum)) {
        sCannotSaveGhost = true;
    }
#endif
    return 0;
}

Gfx* Menus_DrawSaved(Gfx* gfx) {

    if (sGhostSaveTimer > 0) {
        sGhostSaveTimer--;
    } else {
        sGhostSaveTimer = 0;
    }

    if (sGhostSaveTimer == 1) {
        sCannotSaveGhost = true;
        sRaceMenuOptionIndex = 0;
        sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 85, 105, 165, 135);

    gfx = Menus_DrawBeveledBox(gfx, 90, 110, 160, 130, 0, 0, 0, 255);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SAVED, 93, 112);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
    return gfx;
}

Gfx* Menus_DrawSaving(Gfx* gfx) {

    if (sGhostSaveTimer == 1) {
        sRaceMenuOptionIndex = 0;
        sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 80, 105, 170, 135);

    gfx = Menus_DrawBeveledBox(gfx, 90, 110, 160, 130, 0, 0, 0, 255);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SAVING, 95, 112);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
    return gfx;
}

extern char* gCurrentTrackName;
extern char* gTrackNames[];

#ifdef EXPANSION_KIT
s32 sSaveGhostToDiskMenuOptionIndex = 0;
s32 sSaveGhostToDiskMenuScissorBoxTimer = 0;
const char* sDDGhostSavePositionsStr[] = { "1ST", "2ND", "3RD" };

Gfx* Menus_DrawGhostSaveToDiskMenu(Gfx* gfx) {
    s32 i;

    if (sSaveGhostToDiskMenuScissorBoxTimer > 0) {
        sSaveGhostToDiskMenuScissorBoxTimer -= 8;
    } else {
        sSaveGhostToDiskMenuScissorBoxTimer = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sSaveGhostToDiskMenuScissorBoxTimer + 20,
                  sSaveGhostToDiskMenuScissorBoxTimer + 40, 210 - sSaveGhostToDiskMenuScissorBoxTimer,
                  226 - sSaveGhostToDiskMenuScissorBoxTimer);

    gfx = Menus_DrawBeveledBox(gfx, 25, 45, 205, 221, 0, 0, 0, 255);

    gSPDisplayList(gfx++, D_8014940);

    sSaveGhostToDiskMenuOptionIndex = Menus_UpdateHighlightedOptionHorizontal(0, sSaveGhostToDiskMenuOptionIndex, 1);

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sSaveGhostToDiskMenuScissorBoxTimer + 20,
                  sSaveGhostToDiskMenuScissorBoxTimer + 40, 210 - sSaveGhostToDiskMenuScissorBoxTimer,
                  226 - sSaveGhostToDiskMenuScissorBoxTimer);

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
        if (sSaveGhostToDiskMenuOptionIndex == MENU_OPTION_YES) {
            sGhostSaveTimer = 60;
            DDSave_SaveGhostWithCustomSupport(gCourseIndex, sSortedDDGhostRecordIndices[2], gFastestGhost);
            sSaveGhostMenuOpen = false;
            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                Audio_TriggerSystemSE(NA_SE_33);
            }
        } else { // MENU_OPTION_NO
            sGhostSaveTimer = 0;
            sSaveGhostMenuOpen = false;
            sRaceMenuOptionIndex = 0;
            sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                Audio_TriggerSystemSE(NA_SE_16);
            }
        }
    } else if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        sGhostSaveTimer = 0;
        sSaveGhostMenuOpen = false;
        sRaceMenuOptionIndex = 0;
        sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
            Audio_TriggerSystemSE(NA_SE_16);
        }
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sSaveGhostToDiskMenuScissorBoxTimer + 20,
                  sSaveGhostToDiskMenuScissorBoxTimer + 40, 210 - sSaveGhostToDiskMenuScissorBoxTimer,
                  226 - sSaveGhostToDiskMenuScissorBoxTimer);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gfx++, G_TF_POINT);

    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_NEW_GHOST, 83, 45);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_OVERWRITE_DATA2, 51, 114);

    gfx = func_8007DB28(gfx, 0);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_LEFT_ARROW, 70, 197);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_RIGHT_ARROW, 144, 197);
    if (sSaveGhostToDiskMenuOptionIndex == MENU_OPTION_NO) {
        gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_NO, 99, 197);
    } else { // MENU_OPTION_YES
        gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_YES, 99, 197);
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sSaveGhostToDiskMenuScissorBoxTimer + 20,
                  sSaveGhostToDiskMenuScissorBoxTimer + 40, 210 - sSaveGhostToDiskMenuScissorBoxTimer,
                  226 - sSaveGhostToDiskMenuScissorBoxTimer);

    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gfx = Hud_DrawTimerScisThousandths(gfx, gFastestGhost->raceTime, 115, 77, 1.0f);

    for (i = 0; i < 3; i++) {
        if (sSortedDDGhostRecordPtrs[i]->raceTime != MAX_TIMER) {
            gfx = Hud_DrawTimerScisThousandths(gfx, sSortedDDGhostRecordPtrs[i]->raceTime, 95, 139 + i * 16, 1.0f);
        } else {
            gfx = Menus_DrawBlankTimeThousandths(gfx, 87, 139 + i * 16);
        }
    }

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = Font_DrawString(gfx, 116 - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_6, 1) / 2), 78, gCurrentTrackName,
                          1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, 115 - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_6, 1) / 2), 77, gCurrentTrackName,
                          1, FONT_SET_6, 0);

    for (i = 0; i < 3; i++) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
        gfx = Font_DrawString(gfx, 46, 156 + i * 16, sDDGhostSavePositionsStr[i], 1, FONT_SET_6, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, 45, 155 + i * 16, sDDGhostSavePositionsStr[i], 1, FONT_SET_6, 0);
    }

    return gfx;
}

Gfx* Menus_DrawGhostSaveOptionsMenu(Gfx* gfx) {
    s32 ghostSaveFlags = 0;

    switch (sSaveGhostMenuOptionState) {
        case GHOST_SAVE_MENU_SHOW_OPTIONS:
            if (sSaveGhostMenuOptionsScissorBoxTimer > 0) {
                sSaveGhostMenuOptionsScissorBoxTimer -= 8;
            } else {
                sSaveGhostMenuOptionsScissorBoxTimer = 0;
            }

            if (((gSavedGhostInfo.encodedCourseIndex != 0) && (gSavedGhostInfo.courseIndex == gCourseIndex) &&
                 (sFastestGhostTime >= gSavedGhostInfo.raceTime)) ||
                (gCourseIndex >= COURSE_EDIT_1)) {
                ghostSaveFlags |= GHOST_SAVE_CANNOT_SAVE_TO_PAK;
            }
            if ((sFastestGhostTime >= sDDGhostRecords[0].raceTime) &&
                (sFastestGhostTime >= sDDGhostRecords[1].raceTime) &&
                (sFastestGhostTime >= sDDGhostRecords[2].raceTime)) {
                ghostSaveFlags |= GHOST_SAVE_CANNOT_SAVE_TO_DISK;
            }

            gDPPipeSync(gfx++);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sSaveGhostMenuOptionsScissorBoxTimer + 65,
                          sSaveGhostMenuOptionsScissorBoxTimer + 40, 155 - sSaveGhostMenuOptionsScissorBoxTimer,
                          105 - sSaveGhostMenuOptionsScissorBoxTimer);
            gfx = Menus_DrawBeveledBox(gfx, 70, 45, 150, 100, 0, 0, 0, 255);
            gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
            gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));

            switch (ghostSaveFlags) {
                case 0:
                    gfx = Menus_SetOptionColor(gfx, sSaveGhostMenuOptionIndex - GHOST_SAVE_MENU_OPTION_SAVE_TO_PAK);
                    break;
                case GHOST_SAVE_CANNOT_SAVE_TO_PAK:
                case (GHOST_SAVE_CANNOT_SAVE_TO_PAK | GHOST_SAVE_CANNOT_SAVE_TO_DISK):
                    gDPPipeSync(gfx++);
                    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
                    break;
                case GHOST_SAVE_CANNOT_SAVE_TO_DISK:
                    gfx = Menus_SetOptionColor(gfx, 0);
                    break;
            }

            gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_TO_GAME_PAK, 90, 55);

            switch (ghostSaveFlags) {
                case 0:
                    gfx = Menus_SetOptionColor(gfx, sSaveGhostMenuOptionIndex - GHOST_SAVE_MENU_OPTION_SAVE_TO_DISK);
                    break;
                case GHOST_SAVE_CANNOT_SAVE_TO_PAK:
                    gDPPipeSync(gfx++);
                    gfx = Menus_SetOptionColor(gfx, 0);
                    break;
                case GHOST_SAVE_CANNOT_SAVE_TO_DISK:
                case (GHOST_SAVE_CANNOT_SAVE_TO_PAK | GHOST_SAVE_CANNOT_SAVE_TO_DISK):
                    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
                    break;
            }

            gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_TO_DISK, 90, 71);

            gDPPipeSync(gfx++);
            gDPSetTextureLUT(gfx++, G_TT_NONE);

            if (sSaveGhostMenuOptionsScissorBoxTimer != 0) {
                break;
            }

            switch (ghostSaveFlags) {
                case 0:
                case (GHOST_SAVE_CANNOT_SAVE_TO_PAK | GHOST_SAVE_CANNOT_SAVE_TO_DISK):
                    sSaveGhostMenuOptionIndex = Menus_UpdateHighlightedOptionVertical(0, sSaveGhostMenuOptionIndex, 1);
                    break;
                case GHOST_SAVE_CANNOT_SAVE_TO_PAK:
                    sSaveGhostMenuOptionIndex = GHOST_SAVE_MENU_OPTION_SAVE_TO_DISK;
                    break;
                case GHOST_SAVE_CANNOT_SAVE_TO_DISK:
                    sSaveGhostMenuOptionIndex = GHOST_SAVE_MENU_OPTION_SAVE_TO_PAK;
                    break;
            }

            gfx = Menus_SetOptionColor(gfx, 0);
            gfx = Font_DrawScaledString(gfx, 76, (sSaveGhostMenuOptionIndex * 16) + 71, "Ｍ", 1, FONT_SET_5, 0, 0.8f,
                                        0.8f);

            if ((gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START))) {
                if (sSaveGhostMenuOptionIndex == 0) {
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    sSaveGhostMenuState = GHOST_SAVE_MENU_SAVE_TO_PAK;
                    Menus_AttemptSaveGhost();
                } else {
                    sSaveGhostToDiskMenuOptionIndex = MENU_OPTION_NO;
                    sSaveGhostToDiskMenuScissorBoxTimer = 0;
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    sSaveGhostMenuOptionState = GHOST_SAVE_MENU_SAVE_TO_DISK;
                }
            }
            if ((gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B)) {
                if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                    Audio_TriggerSystemSE(NA_SE_32);
                }
                sSaveGhostMenuOpen = false;
                sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
            }
            break;
        case GHOST_SAVE_MENU_SAVE_TO_DISK:
            gfx = Menus_DrawGhostSaveToDiskMenu(gfx);
            break;
    }
    return gfx;
}
#endif

Gfx* Menus_DrawGhostSaveMenu(Gfx* gfx) {
    s32 pad[7];

    if (sGhostSaveMenuScissorBoxTimer > 0) {
        sGhostSaveMenuScissorBoxTimer -= 8;
    } else {
        sGhostSaveMenuScissorBoxTimer = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sGhostSaveMenuScissorBoxTimer + 20, sGhostSaveMenuScissorBoxTimer + 40,
                  210 - sGhostSaveMenuScissorBoxTimer, 226 - sGhostSaveMenuScissorBoxTimer);

    gfx = Menus_DrawBeveledBox(gfx, 25, 45, 205, 221, 0, 0, 0, 255);
    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gfx = Hud_DrawTimerScisThousandths(gfx, sFastestGhostTime, 115, 77, 1.0f);
    gfx = Hud_DrawTimerScisThousandths(gfx, gSavedGhostInfo.raceTime, 115, 141, 1.0f);

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
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
#ifdef VERSION_JP
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_NEW_GHOST, 83, 45);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SAVED_GHOST, 51, 109);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_OVERWRITE_DATA1, 51, 171);
#else
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_NEW_GHOST, 43, 45);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SAVED_GHOST, 11, 109);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_OVERWRITE_DATA1, 21, 171);
#endif
    gfx = func_8007DB28(gfx, 0);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_LEFT_ARROW, 70, 197);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_RIGHT_ARROW, 144, 197);
    if (sOverwriteGhostOptionIndex == MENU_OPTION_NO) {
        gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_NO, 99, 197);
    } else { // MENU_OPTION_YES
        gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_YES, 99, 197);
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    sOverwriteGhostOptionIndex = Menus_UpdateHighlightedOptionHorizontal(0, sOverwriteGhostOptionIndex, 1);
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
        if (sOverwriteGhostOptionIndex == MENU_OPTION_NO) {
            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                Audio_TriggerSystemSE(NA_SE_16);
            }
            sSaveGhostMenuOpen = false;
#ifdef EXPANSION_KIT
            sRaceMenuOptionIndex = 0;
            sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
#endif
        } else { // MENU_OPTION_YES
            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                Audio_TriggerSystemSE(NA_SE_33);
            }
            Save_SaveGhost(gCourseIndex, gFastestGhost);
            sSaveGhostMenuOpen = false;
            sGhostSaveTimer = 60;
        }
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
            Audio_TriggerSystemSE(NA_SE_16);
        }
        sSaveGhostMenuOpen = false;
        sRaceMenuOptionIndex = 0;
        sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
    }
    return gfx;
}

Gfx* Menus_DrawCannotSaveGhost(Gfx* gfx) {

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);

    gfx = Menus_DrawBeveledBox(gfx, 20, 56, 140, 86, 0, 0, 0, 180);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));
    gfx = func_8007DB28(gfx, 0);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CANNOT_SAVE_GHOST, 16, 54);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return gfx;
}

Gfx* Menus_DrawTimeAttackFinishMenu(Gfx* gfx) {
    bool sp4C;

    sp4C = false;
    if (sGeneralRaceMenuScissorBoxTimer > 0) {
        sGeneralRaceMenuScissorBoxTimer--;
    } else {
        sGeneralRaceMenuScissorBoxTimer = 0;
    }

#if defined(EXPANSION_KIT) || defined(VERSION_PAL)
    if ((sGeneralRaceMenuScissorBoxTimer == 1) && (gCourseIndex >= COURSE_EDIT_1) && (gCourseIndex < COURSE_X_1)) {
        Save_SaveCourseRecordProfiles(gCourseIndex);
    }
#endif

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sGeneralRaceMenuScissorBoxTimer + 205,
                  sGeneralRaceMenuScissorBoxTimer + 132, 305 - sGeneralRaceMenuScissorBoxTimer,
                  225 - sGeneralRaceMenuScissorBoxTimer);
    gfx = Menus_DrawBeveledBox(gfx, 210, 137, 300, 220, 0, 0, 0, 180);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - TIME_ATTACK_RETRY);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 230, 140);
    if (!sCannotSaveGhost) {
        gfx = Menus_SetOptionColor(gfx, (sRaceMenuOptionIndex - TIME_ATTACK_SAVE_GHOST) | sSaveGhostMenuOpen |
                                            sGhostSaveTimer);
    } else {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    }
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_GHOST_SAVE, 230, 152);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - TIME_ATTACK_SETTINGS);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 230, 164);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - TIME_ATTACK_CHANGE_MACHINE);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 230, 176);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - TIME_ATTACK_CHANGE_COURSE);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_COURSE, 230, 188);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - TIME_ATTACK_QUIT);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 230, 200);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPPipeSync(gfx++);
    gfx = Menus_SetOptionColor(gfx, sSaveGhostMenuOpen + sGhostSaveTimer);
    gfx = Font_DrawScaledString(gfx, 215, (sRaceMenuOptionIndex * 12) + 157, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);

    if (sSaveGhostMenuOpen) {
#ifdef EXPANSION_KIT
        if ((sSaveGhostMenuState == GHOST_SAVE_MENU_CLOSED) || (sSaveGhostMenuState == GHOST_SAVE_MENU_SAVE_TO_PAK)) {
#endif
            gfx = Menus_DrawGhostSaveMenu(gfx);
#ifdef EXPANSION_KIT
        } else {
            gfx = Menus_DrawGhostSaveOptionsMenu(gfx);
        }
#endif
        sp4C = true;
    } else {
        sSaveGhostMenuOptionsScissorBoxTimer = sGhostSaveMenuScissorBoxTimer = 90;
        sSaveGhostMenuOptionState = sSaveGhostMenuOptionIndex = sOverwriteGhostOptionIndex = 0;
    }
    if (sGhostSaveTimer != 0) {
        if ((sSaveGhostMenuState == GHOST_SAVE_MENU_CLOSED) || (sSaveGhostMenuState == GHOST_SAVE_MENU_SAVE_TO_PAK)) {
            gfx = Menus_DrawSaved(gfx);
        } else if (sSaveGhostMenuState == GHOST_SAVE_MENU_DISK_OPTIONS) {
            gfx = Menus_DrawSaving(gfx);
            sGhostSaveTimer--;
        }
    }
    if ((sGeneralRaceMenuScissorBoxTimer == 0) && !sSaveGhostMenuOpen && (sGhostSaveMenuScissorBoxTimer != 0) &&
        (sGhostSaveTimer == 0) && (sSaveGhostMenuState == GHOST_SAVE_MENU_CLOSED) && !sp4C) {
        if (!sMenuIsBusy) {
            sRaceMenuOptionIndex = Menus_UpdateHighlightedOptionVertical(0, sRaceMenuOptionIndex, 5);
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
            (sSaveGhostMenuState == GHOST_SAVE_MENU_CLOSED)) {
            switch (sRaceMenuOptionIndex) {
                case TIME_ATTACK_RETRY:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
                    break;
                case TIME_ATTACK_QUIT:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuStateFlags |= MENU_STATE_QUIT;
                    break;
                case TIME_ATTACK_SAVE_GHOST:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    sSaveGhostMenuOpen = true;
#ifndef EXPANSION_KIT
                    sSaveGhostMenuState = GHOST_SAVE_MENU_CLOSED;
                    Menus_AttemptSaveGhost();
#else
                    sSaveGhostMenuState = GHOST_SAVE_MENU_DISK_OPTIONS;
#endif
                    break;
                case TIME_ATTACK_SETTINGS:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
                    break;
                case TIME_ATTACK_CHANGE_MACHINE:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
                    break;
                case TIME_ATTACK_CHANGE_COURSE:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_COURSE;
                    break;
            }
        }
    }
    return gfx;
}

Gfx* Menus_DrawGpResultsEndMenu(Gfx* gfx) {

    if (sGpResultsEndMenuScissorBoxTimer > 0) {
        sGpResultsEndMenuScissorBoxTimer--;
    } else {
        sGpResultsEndMenuScissorBoxTimer = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sGpResultsEndMenuScissorBoxTimer + 205,
                  sGpResultsEndMenuScissorBoxTimer + 132, 305 - sGpResultsEndMenuScissorBoxTimer,
                  225 - sGpResultsEndMenuScissorBoxTimer);
    gfx = Menus_DrawBeveledBox(gfx, 210, 137, 300, 220, 0, 0, 0, 180);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));
    gfx = Menus_SetOptionColor(gfx, sGpResultsEndMenuOptionIndex);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 230, 140);
    gfx = Menus_SetOptionColor(gfx, sGpResultsEndMenuOptionIndex - 1);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 230, 155);
    gfx = Menus_SetOptionColor(gfx, sGpResultsEndMenuOptionIndex - 2);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 230, 170);
    gfx = Menus_SetOptionColor(gfx, sGpResultsEndMenuOptionIndex - 3);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_COURSE, 230, 185);
    gfx = Menus_SetOptionColor(gfx, sGpResultsEndMenuOptionIndex - 4);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 230, 200);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = Menus_SetOptionColor(gfx, 0);
    gfx =
        Font_DrawScaledString(gfx, 215, (sGpResultsEndMenuOptionIndex * 15) + 157, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
    if ((sGpResultsEndMenuScissorBoxTimer == 0) && !sMenuIsBusy) {
        sGpResultsEndMenuOptionIndex = Menus_UpdateHighlightedOptionVertical(0, sGpResultsEndMenuOptionIndex, 4);
        if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
            switch (sGpResultsEndMenuOptionIndex) {
                case GP_RESULTS_END_RETRY:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
                    break;
                case GP_RESULTS_END_SETTINGS:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    break;
                case GP_RESULTS_END_QUIT:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    break;
                case GP_RESULTS_END_CHANGE_MACHINE:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    break;
                case GP_RESULTS_END_CHANGE_COURSE:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_COURSE;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    break;
            }
        }
    }
    return gfx;
}

Gfx* Menus_DrawRetiredEndMenu(Gfx* gfx) {

    if (sGeneralRaceMenuScissorBoxTimer > 0) {
        sGeneralRaceMenuScissorBoxTimer--;
    } else {
        sGeneralRaceMenuScissorBoxTimer = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sGeneralRaceMenuScissorBoxTimer + 205,
                  sGeneralRaceMenuScissorBoxTimer + 132, 305 - sGeneralRaceMenuScissorBoxTimer,
                  226 - sGeneralRaceMenuScissorBoxTimer);
    gfx = Menus_DrawBeveledBox(gfx, 210, 137, 300, 221, 0, 0, 200, 127);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - 0);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 230, 140);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - 1);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 230, 155);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - 4);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 230, 200);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - 2);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 230, 170);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - 3);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_COURSE, 230, 185);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = Font_DrawScaledString(gfx, 215, (sRaceMenuOptionIndex * 15) + 157, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
    if ((sGeneralRaceMenuScissorBoxTimer == 0) && !sMenuIsBusy) {
        sRaceMenuOptionIndex = Menus_UpdateHighlightedOptionVertical(0, sRaceMenuOptionIndex, 4);
        if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
            switch (sRaceMenuOptionIndex) {
                case 0:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
                    break;
                case 4:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuStateFlags |= MENU_STATE_QUIT;
                    break;
                case 2:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
                    break;
                case 3:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuStateFlags |= MENU_STATE_CHANGE_COURSE;
                    break;
                case 1:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
                    break;
            }
        }
    }
    return gfx;
}

Gfx* Menus_DrawDeathRaceEndMenu(Gfx* gfx) {

    if (sGeneralRaceMenuScissorBoxTimer > 0) {
        sGeneralRaceMenuScissorBoxTimer--;
    } else {
        sGeneralRaceMenuScissorBoxTimer = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sGeneralRaceMenuScissorBoxTimer + 205,
                  sGeneralRaceMenuScissorBoxTimer + 132, 305 - sGeneralRaceMenuScissorBoxTimer,
                  210 - sGeneralRaceMenuScissorBoxTimer);
    if (gRacers[0].stateFlags & RACER_STATE_FINISHED) {
        gfx = Menus_DrawBeveledBox(gfx, 210, 137, 300, 205, 0, 0, 0, 180);
    } else {
        gfx = Menus_DrawBeveledBox(gfx, 210, 137, 300, 205, 0, 0, 200, 127);
    }
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - 0);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 230, 140);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - 1);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 230, 155);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - 3);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 230, 185);
    gfx = Menus_SetOptionColor(gfx, sRaceMenuOptionIndex - 2);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 230, 170);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = Font_DrawScaledString(gfx, 215, (sRaceMenuOptionIndex * 15) + 157, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
    if ((sGeneralRaceMenuScissorBoxTimer == 0) && !sMenuIsBusy) {
        sRaceMenuOptionIndex = Menus_UpdateHighlightedOptionVertical(0, sRaceMenuOptionIndex, 3);
        if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
            switch (sRaceMenuOptionIndex) {
                case 0:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
                    break;
                case 3:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuStateFlags |= MENU_STATE_QUIT;
                    break;
                case 2:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
                    break;
                case 1:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    sMenuIsBusy = true;
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuStateFlags |= MENU_STATE_SETTINGS;
                    break;
            }
        }
    }
    return gfx;
}

Gfx* Menus_DrawGeneralPause(Gfx* gfx) {
    s32 pad[2];

    if (sPauseMenuScissorBoxTimer > 0) {
        sPauseMenuScissorBoxTimer -= 8;
    } else {
        sPauseMenuScissorBoxTimer = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sPauseMenuScissorBoxTimer + 100, sPauseMenuScissorBoxTimer + 41,
                  230 - sPauseMenuScissorBoxTimer, 197 - sPauseMenuScissorBoxTimer);
    gfx = Menus_DrawBeveledBox(gfx, 120, 61, 210, 177, 0, 0, 0, 220);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));

    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_CONTINUE);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CONTINUE, 140, 80);
    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_RETRY);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 140, 95);
    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_SETTINGS);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 140, 110);
    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_QUIT);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 140, 155);
    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_CHANGE_MACHINE);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 140, 125);
    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GENERAL_CHANGE_COURSE);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_COURSE, 140, 140);
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
        sPauseMenuOptionIndex = Menus_UpdateHighlightedOptionVertical(sPausePlayerNum, sPauseMenuOptionIndex, 5);
        if (gControllers[gPlayerControlPorts[sPausePlayerNum]].buttonPressed & (BTN_A | BTN_START)) {
            switch (sPauseMenuOptionIndex) {
                case PAUSE_GENERAL_CONTINUE:
                    sMenuStateFlags |= MENU_STATE_UNPAUSE_GAME;
                    break;
                case PAUSE_GENERAL_RETRY:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_14);
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
                    break;
                case PAUSE_GENERAL_QUIT:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_14);
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
                    break;
                case PAUSE_GENERAL_CHANGE_MACHINE:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_14);
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
                    break;
                case PAUSE_GENERAL_CHANGE_COURSE:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_14);
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_COURSE;
                    break;
                case PAUSE_GENERAL_SETTINGS:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_14);
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

Gfx* Menus_DrawDeathRacePause(Gfx* gfx) {
    s32 pad[2];

    if (sPauseMenuScissorBoxTimer > 0) {
        sPauseMenuScissorBoxTimer -= 8;
    } else {
        sPauseMenuScissorBoxTimer = 0;
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sPauseMenuScissorBoxTimer + 100, sPauseMenuScissorBoxTimer + 56,
                  230 - sPauseMenuScissorBoxTimer, 166 - sPauseMenuScissorBoxTimer);
    gfx = Menus_DrawBeveledBox(gfx, 120, 61, 210, 161, 0, 0, 0, 220);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));

    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_DEATH_RACE_CONTINUE);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CONTINUE, 140, 80);
    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_DEATH_RACE_RETRY);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 140, 95);
    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_DEATH_RACE_SETTINGS);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 140, 110);
    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_DEATH_RACE_QUIT);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 140, 140);
    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_DEATH_RACE_CHANGE_MACHINE);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CHANGE_MACHINE, 140, 125);
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
        sPauseMenuOptionIndex = Menus_UpdateHighlightedOptionVertical(sPausePlayerNum, sPauseMenuOptionIndex, 4);
        if (gControllers[gPlayerControlPorts[sPausePlayerNum]].buttonPressed & (BTN_A | BTN_START)) {
            switch (sPauseMenuOptionIndex) {
                case PAUSE_DEATH_RACE_CONTINUE:
                    sMenuStateFlags |= MENU_STATE_UNPAUSE_GAME;
                    break;
                case PAUSE_DEATH_RACE_RETRY:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_14);
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
                    break;
                case PAUSE_DEATH_RACE_QUIT:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_14);
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
                    break;
                case PAUSE_DEATH_RACE_CHANGE_MACHINE:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_14);
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_CHANGE_MACHINE;
                    break;
                case PAUSE_DEATH_RACE_SETTINGS:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_14);
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
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

Gfx* Menus_DrawGpRacePause(Gfx* gfx) {
    s32 pad[2];

    if (sPauseMenuScissorBoxTimer > 0) {
        sPauseMenuScissorBoxTimer -= 8;
    } else {
        sPauseMenuScissorBoxTimer = 0;
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sPauseMenuScissorBoxTimer + 100, sPauseMenuScissorBoxTimer + 56,
                  220 - sPauseMenuScissorBoxTimer, 150 - sPauseMenuScissorBoxTimer);
    gfx = Menus_DrawBeveledBox(gfx, 120, 61, 200, 145, 0, 0, 0, 220);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));

    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GP_CONTINUE);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_CONTINUE, 140, 80);
    if (sPlayer1Lives <= 0) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    } else {
        gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GP_RETRY);
    }
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_RETRY, 140, 95);
    gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GP_QUIT);
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_QUIT, 140, 125);
    if (sPlayer1Lives <= 0) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    } else {
        gfx = Menus_SetOptionColor(gfx, sPauseMenuOptionIndex - PAUSE_GP_SETTINGS);
    }
    gfx = Menus_DrawRaceMenuTexture(gfx, RACE_MENU_SETTINGS, 140, 110);
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
        sPauseMenuOptionIndex = Menus_UpdateHighlightedOptionVertical(sPausePlayerNum, sPauseMenuOptionIndex, 3);
        if (((sPauseMenuOptionIndex == PAUSE_GP_RETRY) || (sPauseMenuOptionIndex == PAUSE_GP_SETTINGS)) &&
            (sPlayer1Lives <= 0)) {
            if ((gControllers[gPlayerControlPorts[0]].stickY > 40) ||
                (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_UP)) {
                sPauseMenuOptionIndex = PAUSE_GP_CONTINUE;
            } else {
                sPauseMenuOptionIndex = PAUSE_GP_QUIT;
            }
        }
        if (gControllers[gPlayerControlPorts[sPausePlayerNum]].buttonPressed & (BTN_A | BTN_START)) {
            switch (sPauseMenuOptionIndex) {
                case PAUSE_GP_CONTINUE:
                    sMenuStateFlags |= MENU_STATE_UNPAUSE_GAME;
                    break;
                case PAUSE_GP_RETRY:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].id < gNumPlayers)) {
                        gPlayerLives[gRacers[0].id]--;
                        if (gPlayerLives[gRacers[0].id] >= 0) {
                            Hud_TriggerLivesDecrease();
                        }
                        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                            Audio_TriggerSystemSE(NA_SE_44);
                        }
                    }
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_RETRY;
                    break;
                case PAUSE_GP_QUIT:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_14);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
                    sMenuIsBusy = true;
                    sMenuStateFlags |= MENU_STATE_QUIT;
                    break;
                case PAUSE_GP_SETTINGS:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_PauseSet(AUDIO_PAUSE_TRANSITION);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_LevelSEFadeout();
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0CC();
                    }
                    if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].id < gNumPlayers)) {
                        gPlayerLives[gRacers[0].id]--;
                        if (gPlayerLives[gRacers[0].id] >= 0) {
                            Hud_TriggerLivesDecrease();
                        }
                        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                            Audio_TriggerSystemSE(NA_SE_44);
                        }
                    }
#ifdef EXPANSION_KIT
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_RomBgmReady(BGM_SELECT);
                    }
#endif
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

extern s16 gCurrentTimeAttackHasMaxSpeed;

Gfx* Menus_DrawMaxSpeed(Gfx* gfx, s32 playerIndex) {
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
                left = 130;
                top = 192;
            } else {
                left = 40;
                top = 68;
            }
            break;
        case 2:
            left = 220;
            switch (playerIndex) {
                case 0:
                    top = 92;
                    break;
                case 1:
                    top = 204;
                    break;
            }
            break;
        case 3:
        case 4:
            switch (playerIndex) {
                case 0:
                    left = 81;
                    top = 98;
                    break;
                case 1:
                    left = 81;
                    top = 210;
                    break;
                case 2:
                    left = 225;
                    top = 98;
                    break;
                case 3:
                    left = 225;
                    top = 210;
                    break;
            }
            break;
    }
    top += sTimeAttackResultsTimer;
    digitMask = 1000;
    speedRemainder = speed = Math_Round(gRacers[playerIndex].maxSpeed * SPEED_CONVERSION);

    gDPPipeSync(gfx++);

    if (gNumPlayers == 1) {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    } else {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    }

    gfx = Menus_DrawBox(gfx, left, top, left + 71, top + 16, 0, 0, 0, 255);
    gSPDisplayList(gfx++, D_80149D0);
    gDPLoadTextureBlock(gfx++, aMaxSpeedTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPScisTextureRectangle(gfx++, (left + 2) << 2, (top - 16) << 2, (left + 65) << 2, (top - 1) << 2, 0, 0, 0, 1 << 12,
                            1 << 10);

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);

    if (gCurrentTimeAttackHasMaxSpeed) {
        gfx = TextureUtils_SetPulsingColor(gfx, 255, 0, 0);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    }
    gDPLoadTextureBlock(gfx++, aSpeedDigitsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 160, 0, G_TX_NOMIRROR | G_TX_WRAP,
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
    gDPLoadTextureBlock(gfx++, aKmhTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPScisTextureRectangle(gfx++, (left + (i * 12)) << 2, top << 2, (left + (i * 12) + 19) << 2, (top + 15) << 2, 0, 0,
                            0, 1 << 10, 1 << 10);

    return gfx;
}

Gfx* Menu_DrawTimeAttackResultsTimes(Gfx* gfx) {

    sResultsTimesLapLeft = 110;
    sResultsTimesTop = 45;
    sResultsTimesVerticalSpacing = 30;
    sResultsTimesLapLeftFromLap = 35;
    sResultsTimesStartTopOffset = 60;
    sResultsTimesStartLapSpacing = 10;
    sResultsTimesSpeed = 10;
    gfx = Menus_DrawRaceResultsTimes(gfx, 0);
    if (gCurrentTimeAttackRecordPosition != 0) {
        gShowNameEntryMenu = true;
    }
    return gfx;
}

Gfx* Menus_DrawCourseName(Gfx* gfx, s32 left, s32 top, s32 paddingSize) {
    s32 trackNameWidth;
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;

    trackNameWidth = Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 1);

    gDPPipeSync(gfx++);

    ulx = ((left - (trackNameWidth / 2)) + paddingSize) - 7;
    uly = (top + paddingSize) - 21;
    lrx = (((trackNameWidth / 2) + left) - paddingSize) + 7;
    lry = (top - paddingSize) + 5;

    if (ulx < 12) {
        ulx = 12;
    }
    if (uly < 16) {
        uly = 16;
    }
    if (lrx > 308) {
        lrx = 308;
    }
    if (lry > 224) {
        lry = 224;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);

    gfx = Menus_DrawBeveledBox(gfx, (left - (trackNameWidth / 2)) - 7, top - 19, (trackNameWidth / 2) + left + 7,
                               top + 3, 0, 0, 200, 128);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gfx = Font_DrawString(gfx, (left - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 1) / 2)) + 2, top + 2,
                          gCurrentTrackName, 1, FONT_SET_3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, left - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 1) / 2), top,
                          gCurrentTrackName, 1, FONT_SET_3, 0);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

Gfx* Menus_DrawTimeAttackIntroDisplay(Gfx* gfx, s32 left, s32 top, s32 paddingSize) {
    s32 timeAttackStringWidth;
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;

    timeAttackStringWidth = Font_GetStringWidth("TIME ATTACK", FONT_SET_3, 1);

    gDPPipeSync(gfx++);

    ulx = ((left - (timeAttackStringWidth / 2)) + paddingSize) - 7;
    uly = (top + paddingSize) - 21;
    lrx = (((timeAttackStringWidth / 2) + left) - paddingSize) + 7;
    lry = (top - paddingSize) + 5;

    if (ulx < 12) {
        ulx = 12;
    }
    if (uly < 16) {
        uly = 16;
    }
    if (lrx > 308) {
        lrx = 308;
    }
    if (lry > 224) {
        lry = 224;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);

    gfx = Menus_DrawBeveledBox(gfx, (left - (timeAttackStringWidth / 2)) - 7, top - 19,
                               (timeAttackStringWidth / 2) + left + 7, top + 3, 0, 150, 0, 200);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gfx = Font_DrawString(gfx, (left - (Font_GetStringWidth("TIME ATTACK", FONT_SET_3, 1) / 2)) + 2, top + 2,
                          "TIME ATTACK", 1, FONT_SET_3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, left - (Font_GetStringWidth("TIME ATTACK", FONT_SET_3, 1) / 2), top, "TIME ATTACK", 1,
                          FONT_SET_3, 0);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

Gfx* Menus_DrawTimeAttackIntroBestTimeDisplay(Gfx* gfx, s32 left, s32 top, s32 paddingSize) {
    s32 pad;
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;

    gDPPipeSync(gfx++);

    ulx = (left + paddingSize) - 72;
    uly = (top + paddingSize) - 21;
    lrx = (left - paddingSize) + 72;
    lry = (top - paddingSize) + 21;

    if (ulx < 12) {
        ulx = 12;
    }
    if (uly < 16) {
        uly = 16;
    }
    if (lrx > 308) {
        lrx = 308;
    }
    if (lry > 224) {
        lry = 224;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);

    gfx = Menus_DrawBeveledBox(gfx, left - 72, top - 19, left + 72, top + 19, 180, 0, 0, 150);
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = Hud_DrawTimerScisThousandths(gfx, gCurrentCourseInfo->timeRecord[0], ((s32) (ulx + lrx) / 2) - 60,
                                       (s32) (uly + lry) / 2, 1.0f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);

    gfx = Font_DrawString(gfx, left - 39, top - 1, "BEST TIME", 1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, left - 41, top - 3, "BEST TIME", 1, FONT_SET_6, 0);
    gfx = Font_DrawString(gfx, left + 19, top + 16, gCurrentCourseInfo->recordNames[0], 1, 1, 0);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

Gfx* Menus_DrawDeathRaceIntroBestTimeDisplay(Gfx* gfx, s32 left, s32 top, s32 paddingSize) {
    s32 pad;
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;

    gDPPipeSync(gfx++);

    ulx = (left + paddingSize) - 52;
    uly = (top + paddingSize) - 21;
    lrx = (left - paddingSize) + 52;
    lry = (top - paddingSize) + 21;

    if (ulx < 12) {
        ulx = 12;
    }
    if (uly < 16) {
        uly = 16;
    }
    if (lrx > 308) {
        lrx = 308;
    }
    if (lry > 224) {
        lry = 224;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);

    gfx = Menus_DrawBeveledBox(gfx, left - 52, top - 19, left + 52, top + 19, 180, 0, 0, 150);
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = Hud_DrawTimerScisThousandths(gfx, gCurrentCourseInfo->timeRecord[0], ((s32) (ulx + lrx) / 2) - 35,
                                       (s32) (uly + lry) / 2, 1.0f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);

    gfx = Font_DrawString(gfx, left - 39, top - 1, "BEST TIME", 1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, left - 41, top - 3, "BEST TIME", 1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

extern s32 gDifficulty;

const char* gDifficultyNames[] = { "NOVICE", "STANDARD", "EXPERT", "MASTER" };

Gfx* Menus_DrawRaceIntroDisplay(Gfx* gfx, s32 left, s32 top, s32 paddingSize) {
    s32 strWidth;
    s32 headerWidth;
    s32 boxLeft;
    s32 boxRight;
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;

    if (gGameMode == GAMEMODE_GP_RACE) {
        headerWidth = Font_GetStringWidth("GP RACE", FONT_SET_3, 1);
        strWidth = Font_GetStringWidth(gDifficultyNames[gDifficulty], FONT_SET_3, 1);
    } else if (gGameMode == GAMEMODE_PRACTICE) {
        headerWidth = Font_GetStringWidth("PRACTICE", FONT_SET_3, 1);
        strWidth = Font_GetStringWidth(gDifficultyNames[gDifficulty], FONT_SET_3, 1);
    } else if (gGameMode == GAMEMODE_DEATH_RACE) {
        headerWidth = Font_GetStringWidth("DEATH RACE", FONT_SET_3, 1);
        strWidth = 0;
        top += 16;
    }

    if (strWidth < headerWidth) {
        strWidth = headerWidth;
    }
    gDPPipeSync(gfx++);
    boxLeft = left - (strWidth / 2);
    boxRight = left + (strWidth / 2);

    ulx = (boxLeft + paddingSize) - 7;
    uly = (top + paddingSize) - 37;
    lrx = (boxRight - paddingSize) + 7;

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        lry = (top - paddingSize) - 11;
    } else {
        lry = (top - paddingSize) + 5;
    }
    if (ulx < 12) {
        ulx = 12;
    }
    if (uly < 16) {
        uly = 16;
    }
    if (lrx > 308) {
        lrx = 308;
    }
    if (lry > 224) {
        lry = 224;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        gfx = Menus_DrawBeveledBox(gfx, boxLeft - 7, top - 35, boxRight + 7, top - 13, 0, 220, 0, 200);
    } else {
        gfx = Menus_DrawBeveledBox(gfx, boxLeft - 7, top - 35, boxRight + 7, top + 3, 0, 220, 0, 200);
    }

    if (gGameMode == GAMEMODE_GP_RACE) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, (left - (Font_GetStringWidth("GP RACE", FONT_SET_3, 1) / 2)) + 2, top - 14,
                              "GP RACE", 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, left - (Font_GetStringWidth("GP RACE", FONT_SET_3, 1) / 2), top - 16, "GP RACE", 1,
                              FONT_SET_3, 0);
    } else if (gGameMode == GAMEMODE_PRACTICE) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, (left - (Font_GetStringWidth("PRACTICE", FONT_SET_3, 1) / 2)) + 2, top - 14,
                              "PRACTICE", 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, left - (Font_GetStringWidth("PRACTICE", FONT_SET_3, 1) / 2), top - 16, "PRACTICE", 1,
                              FONT_SET_3, 0);
    } else if (gGameMode == GAMEMODE_DEATH_RACE) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, (left - (Font_GetStringWidth("DEATH RACE", FONT_SET_3, 1) / 2)) + 2, top - 14,
                              "DEATH RACE", 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, left - (Font_GetStringWidth("DEATH RACE", FONT_SET_3, 1) / 2), top - 16,
                              "DEATH RACE", 1, FONT_SET_3, 0);
    }

    if (gGameMode != GAMEMODE_DEATH_RACE) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, (left - (Font_GetStringWidth(gDifficultyNames[gDifficulty], FONT_SET_3, 1) / 2)) + 2,
                              top + 2, gDifficultyNames[gDifficulty], 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, left - (Font_GetStringWidth(gDifficultyNames[gDifficulty], FONT_SET_3, 1) / 2), top,
                              gDifficultyNames[gDifficulty], 1, FONT_SET_3, 0);
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

Gfx* Menus_DrawRetire(Gfx* gfx, s32 left, s32 top, f32 scale) {
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

Gfx* Menus_DrawPlayerRetire(Gfx* gfx, s32 playerIndex) {
    s32 row;
    s32 alpha;
    s32 left;
    s32 top;
    s32 leftBound;
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 pad[2];
    f32 scale;

    if ((gNumPlayers == 1) && ((gGameMode != GAMEMODE_GP_RACE) || (sPlayer1Lives > 0)) &&
        (sPlayerRetireTimer[0] > 120)) {
        gControllers[gGameFrameCount % 4].unk_78 = 1;

        sPlayerRetireGameoverFadeTransitionTimer[0] += 2;
        if (sPlayerRetireGameoverFadeTransitionTimer[0] == 250) {
            Audio_Retire();
            Audio_LevelSEFadeout();
        }
        if (sPlayerRetireGameoverFadeTransitionTimer[0] > 1000) {
            sPlayerRetireGameoverFadeTransitionTimer[0] = 1000;
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
            alpha = (sPlayerRetireGameoverFadeTransitionTimer[0] + alpha) - 150;
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
            scale = 1.0f;
            left = 100;
            top = 76;
            break;
        case 2:
            scale = 1.0f;
            left = 100;
            switch (playerIndex) {
                case 0:
                    top = 43;
                    break;
                case 1:
                    top = 155;
                    break;
            }
            break;
        case 3:
        case 4:
            scale = 0.5f;
            switch (playerIndex) {
                case 0:
                    left = 55;
                    top = 49;
                    break;
                case 1:
                    left = 55;
                    top = 161;
                    break;
                case 2:
                    left = 203;
                    top = 49;
                    break;
                case 3:
                    left = 203;
                    top = 161;
                    break;
            }
            break;
    }

    leftBound = left;
    left = sPlayerRetireRelativeLeftPos[playerIndex] + left;
    sPlayerRetireRelativeLeftPos[playerIndex] += sPlayerRetireHorizontalSpeed[playerIndex];
    if (sPlayerRetireRelativeLeftPos[playerIndex] < 0.0f) {
        // "Bounce" against left bound
        left = leftBound;
        sPlayerRetireRelativeLeftPos[playerIndex] = 0.0f;
        sPlayerRetireHorizontalSpeed[playerIndex] *= -1.0f;
    }
    sPlayerRetireHorizontalSpeed[playerIndex] -= 2.0f;
    sPlayerRetireHorizontalSpeed[playerIndex] *= 0.9f;
    switch (gNumPlayers) {
        case 1:
            ulx = 12;
            uly = 8;
            lrx = 305;
            lry = 232;
            break;
        case 2:
            switch (playerIndex) {
                case 0:
                    ulx = 12;
                    uly = 8;
                    lrx = 305;
                    lry = 117;
                    break;
                case 1:
                    ulx = 12;
                    uly = 120;
                    lrx = 305;
                    lry = 232;
                    break;
            }
            break;
        case 3:
        case 4:
            switch (playerIndex) {
                case 0:
                    ulx = 12;
                    uly = 8;
                    lrx = 154;
                    lry = 117;
                    break;
                case 1:
                    ulx = 12;
                    uly = 120;
                    lrx = 154;
                    lry = 232;
                    break;
                case 2:
                    ulx = 160;
                    uly = 8;
                    lrx = 305;
                    lry = 117;
                    break;
                case 3:
                    ulx = 160;
                    uly = 120;
                    lrx = 305;
                    lry = 232;
                    break;
            }
            break;
    }
    if (left < lrx) {
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);
        gfx = Menus_DrawRetire(gfx, left, top, scale);
    }
    if (gNumPlayers == 1) {
        if ((sPlayerRetireTimer[playerIndex] == 1) && (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
            func_8007E0CC();
        }
        if ((sPlayerRetireTimer[playerIndex] == 60) && (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
#ifndef EXPANSION_KIT
            Audio_RomBgmStart(BGM_23);
#else
            func_8070DAD4(BGM_23);
#endif
        }
    }

    sPlayerRetireTimer[playerIndex]++;
    if (sPlayerRetireTimer[playerIndex] >= 600) {
        sPlayerRetireTimer[playerIndex] = 600;
    }
    return gfx;
}

Gfx* Menus_DrawResultsBox(Gfx* gfx, s32 boxScale) {
    s32 pad;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;

    left = boxScale + 30;
    top = boxScale + 25;
    right = 290 - boxScale;
    bottom = 220 - boxScale;

    gfx = Menus_DrawBeveledBox(gfx, left, top, right, bottom, 0, 0, 0, 127 - boxScale);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, left, top, right, bottom);

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
const char* sCharacterNames[] = {
    "CAPTAIN FALCON", "Dr. STEWART", "PICO",           "SAMURAI GOROH", "JODY SUMMER",   "MIGHTY GAZELLE",
    "Mr. EAD",        "BABA",        "OCTOMAN",        "GOMAR&SHIOH",   "KATE ALEN",     "ROGER BUSTER",
    "JAMES McCLOUD",  "LEON",        "ANTONIO GUSTER", "BLACK SHADOW",  "MICHAEL CHAIN", "JACK LEVIN",
    "SUPER ARROW",    "Mrs. ARROW",  "JOHN TANAKA",    "BEASTMAN",      "ZODA",          "Dr. CLASH",
    "SILVER NEELSEN", "BIO REX",     "DRAQ",           "BILLY",         "THE SKULL",     "BLOOD FALCON",
};
#endif

Gfx* Menus_DrawResultsCharacterName(Gfx* gfx, s32 highlightType, s32 character, s32 left, s32 top) {
    gfx = Menus_SetOptionColor(gfx, highlightType);
    return Font_DrawString(gfx, left, top, sCharacterNames[character], 1, FONT_SET_4, 0);
}

Gfx* Menus_DrawResultsRetireStatus(Gfx* gfx, s32 highlightType, s32 left, s32 top) {
    gfx = Menus_SetOptionColor(gfx, highlightType);
#ifdef VERSION_JP
    return Font_DrawString(gfx, left, top, "リタイア", 1, FONT_SET_4, 0);
#else
    return Font_DrawString(gfx, left, top, "RETIRE", 1, FONT_SET_4, 0);
#endif
}

void Menus_LoadNumberToStr(s32 num) {
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
        sMenusLoadedNumberStr[digitIndex + 0] = (remainingNum / 100) + '0';
        sMenusLoadedNumberStr[digitIndex + 1] = sMenusLoadedNumberStr[digitIndex + 2] = '0';
        sMenusLoadedNumberStr[digitIndex + 3] = '\0';
        remainingNum -= (remainingNum / 100) * 100;
    }
    if (num >= 100) {
        digitIndex++;
    }
    if (remainingNum >= 10) {
        sMenusLoadedNumberStr[digitIndex + 0] = (remainingNum / 10) + '0';
        remainingNum -= (remainingNum / 10) * 10;
        sMenusLoadedNumberStr[digitIndex + 1] = '0';
        sMenusLoadedNumberStr[digitIndex + 2] = '\0';
    }

    if (num >= 10) {
        digitIndex++;
    }
    sMenusLoadedNumberStr[digitIndex + 0] = remainingNum + '0';
    sMenusLoadedNumberStr[digitIndex + 1] = '\0';
}

Gfx* Menus_DrawPositionNumber(Gfx* gfx, s32 highlightType, s32 position, s32 left, s32 top) {
    gfx = Menus_SetOptionColor(gfx, highlightType);
    Menus_LoadNumberToStr(position);
    return Font_DrawString(gfx, left - Font_GetStringWidth(sMenusLoadedNumberStr, FONT_SET_4, 0), top,
                           sMenusLoadedNumberStr, 0, FONT_SET_4, 0);
}

Gfx* Menus_DrawPlusPoints(Gfx* gfx, s32 highlightType, s32 left, s32 top) {
    gfx = Menus_SetOptionColor(gfx, highlightType);
    return Font_DrawString(gfx, left - Font_GetStringWidth("+     $", FONT_SET_4, 1), top, "+     $", 1, FONT_SET_4, 0);
}

Gfx* Menus_DrawPoints(Gfx* gfx, s32 highlightType, s32 left, s32 top) {
    gfx = Menus_SetOptionColor(gfx, highlightType);
    return Font_DrawString(gfx, left - Font_GetStringWidth("    $", FONT_SET_4, 1), top, "    $", 1, FONT_SET_4, 0);
}

Gfx* Menus_DrawDeathRaceResults(Gfx* gfx) {
    s32 halfStringWidth;
    f32 scale = 1.0f;
    s32 left;
    s32 top;
    s32 pad[5];

    halfStringWidth = Font_GetStringWidth("death race  results", FONT_SET_3, 1) / 2;
    gfx = Menus_DrawBeveledBox(gfx, 155 - halfStringWidth, 25, halfStringWidth + 169, 43, 0, 0, 200, 127);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gfx = Font_DrawString(gfx, 162 - (Font_GetStringWidth("death race  results", FONT_SET_3, 1) / 2), 44,
                          "death race  results", 1, FONT_SET_3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth("death race  results", FONT_SET_3, 1) / 2), 42,
                          "death race  results", 1, FONT_SET_3, 0);
    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTextureBlock(gfx++, aHudTimeTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    left = 213;
    top = 60;
    gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (24 - 1) * scale) << 2,
                            (s32) (top + (16 - 1) * scale) << 2, 0, 0, 0, (s32) ((1 << 10) / scale),
                            (s32) ((1 << 10) / scale));

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    left = 213;
    top = 101;
    gDPLoadTextureBlock(gfx++, TextureCache_GetCached(aBestTex), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPDisplayList(gfx++, D_8014940);

    if (gCurrentTimeAttackRecordPosition == 1) {
        gfx = TextureUtils_SetPulsingColor(gfx, 255, 0, 0);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gfx = Hud_DrawTimerScisThousandths(gfx, gRacers[0].raceTime, 213, 75, 1.0f);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    return Hud_DrawTimerScisThousandths(gfx, gCurrentCourseInfo->timeRecord[0], 213, 114, 1.0f);
}

extern s32 gVsRacePlayerVictoryCount[];
extern s32 gVsRacePlayerPoints[];
extern s32 gVsPreviousRacePosition[];

UNUSED s32 D_i3_8013EF40 = 0;

s32 sVsRaceRacerCountPositionPoints[][4] = {
    { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 5, 0, 0, 0 }, { 5, 3, 0, 0 }, { 5, 3, 1, 0 },
};

s32 sVsPlayerColorRed[] = { 0, 255, 0, 255 };

s32 sVsPlayerColorGreen[] = { 255, 255, 255, 127 };

s32 sVsPlayerColorBlue[] = { 255, 0, 0, 255 };

s32 sVsPositionToVictoryGivenCount[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

Gfx* Menus_DrawVsResultsScreen(Gfx* gfx) {
    s32 boxScale;
    s32 i;
    s32 j;
    s32 var_s1;
    s32 pad[8];
    s32 stringHalfWidth;
    s32 totalVsVictories;

    boxScale = 0;
    if (sVsResultsTimer < 30) {
        boxScale = (30 - sVsResultsTimer) * 4;
    } else if (sVsResultsTimer > 60030) {
        boxScale = (sVsResultsTimer - 60030) * 4;
    }
    gfx = Menus_DrawResultsBox(gfx, boxScale);

    totalVsVictories = 0;
    for (i = 0; i < gTotalRacers; i++) {
        totalVsVictories += gVsRacePlayerVictoryCount[i];
    }

    if ((sVsResultsTimer > 30) && (sVsResultsTimer < 30030)) {
        stringHalfWidth = Font_GetStringWidth("vs results", FONT_SET_3, 1) / 2;
        gfx = Menus_DrawBeveledBox(gfx, 155 - stringHalfWidth, 33, stringHalfWidth + 169, 51, 0, 0, 200, 127);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, 162 - (Font_GetStringWidth("vs results", FONT_SET_3, 1) / 2), 52, "vs results", 1,
                              FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth("vs results", FONT_SET_3, 1) / 2), 50, "vs results", 1,
                              FONT_SET_3, 0);
    } else if ((sVsResultsTimer > 30030) && (sVsResultsTimer < 60030)) {
        stringHalfWidth = Font_GetStringWidth("vs total ranking", FONT_SET_3, 1) / 2;
        gfx = Menus_DrawBeveledBox(gfx, 155 - stringHalfWidth, 33, stringHalfWidth + 169, 51, 0, 0, 200, 127);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, 162 - (Font_GetStringWidth("vs total ranking", FONT_SET_3, 1) / 2), 52,
                              "vs total ranking", 1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth("vs total ranking", FONT_SET_3, 1) / 2), 50,
                              "vs total ranking", 1, FONT_SET_3, 0);
    }
    if ((sVsResultsTimer >= 30) && (sVsResultsTimer < 30030)) {
        boxScale = 0;
        if (sVsResultsTimer < 60) {
            boxScale = (-sVsResultsTimer * 4) + 240;
        } else if (sVsResultsTimer > 30000) {
            boxScale = (sVsResultsTimer * 4) - 120000;
        }
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, boxScale + 30, boxScale + 25, 290 - boxScale, 220 - boxScale);

        if (sVsResultsTimer == 30) {
            for (i = 0; i < gTotalRacers; i++) {
                sVsRaceResultsPlayerDisplayPoints[i] =
                    gVsRacePlayerPoints[i] - sVsRaceRacerCountPositionPoints[gTotalRacers][gRacers[i].position - 1];
                sVsRacePlayerPointsIncrease[i] = sVsRaceRacerCountPositionPoints[gTotalRacers][gRacers[i].position - 1];
            }
            sVsRacePointsAddTimer = 0;
            sVsRaceResultsMenuOptionIndex = VS_RESULTS_COURSE_SELECT;
        }
        for (i = 0, j = 0; i < 4; i++) {
            sVsRacePreviousPlayerByOverallPosition[i] = i;
        }

        for (i = 0; i < gTotalRacers; i++) {
            j += gVsRacePlayerPoints[i];
        }

        if (totalVsVictories == 1) {
            for (i = 0; i < gTotalRacers; i++) {
                for (j = 0; j < gTotalRacers; j++) {
                    if (gRacers[i].position == j + 1) {
                        sVsRacePreviousPlayerByOverallPosition[j] = i;
                    }
                }
            }
        } else {
            for (i = 0; i < gTotalRacers; i++) {
                for (j = i + 1; j < gTotalRacers; j++) {
                    if (gVsRacePlayerPoints[sVsRacePreviousPlayerByOverallPosition[i]] -
                            sVsRaceRacerCountPositionPoints
                                [gTotalRacers][gRacers[sVsRacePreviousPlayerByOverallPosition[i]].position - 1] <
                        gVsRacePlayerPoints[sVsRacePreviousPlayerByOverallPosition[j]] -
                            sVsRaceRacerCountPositionPoints
                                [gTotalRacers][gRacers[sVsRacePreviousPlayerByOverallPosition[j]].position - 1]) {
                        var_s1 = sVsRacePreviousPlayerByOverallPosition[i];
                        sVsRacePreviousPlayerByOverallPosition[i] = sVsRacePreviousPlayerByOverallPosition[j];
                        sVsRacePreviousPlayerByOverallPosition[j] = var_s1;
                    }
                    if ((gVsRacePlayerPoints[sVsRacePreviousPlayerByOverallPosition[i]] -
                             sVsRaceRacerCountPositionPoints
                                 [gTotalRacers][gRacers[sVsRacePreviousPlayerByOverallPosition[i]].position - 1] ==
                         gVsRacePlayerPoints[sVsRacePreviousPlayerByOverallPosition[j]] -
                             sVsRaceRacerCountPositionPoints
                                 [gTotalRacers][gRacers[sVsRacePreviousPlayerByOverallPosition[j]].position - 1]) &&
                        (gVsRacePlayerVictoryCount[sVsRacePreviousPlayerByOverallPosition[i]] -
                             sVsPositionToVictoryGivenCount
                                 [gRacers[sVsRacePreviousPlayerByOverallPosition[i]].position - 1] <
                         gVsRacePlayerVictoryCount[sVsRacePreviousPlayerByOverallPosition[j]] -
                             sVsPositionToVictoryGivenCount
                                 [gRacers[sVsRacePreviousPlayerByOverallPosition[j]].position - 1])) {
                        var_s1 = sVsRacePreviousPlayerByOverallPosition[i];
                        sVsRacePreviousPlayerByOverallPosition[i] = sVsRacePreviousPlayerByOverallPosition[j];
                        sVsRacePreviousPlayerByOverallPosition[j] = var_s1;
                    }
                    if ((gVsRacePlayerPoints[sVsRacePreviousPlayerByOverallPosition[i]] -
                             sVsRaceRacerCountPositionPoints
                                 [gTotalRacers][gRacers[sVsRacePreviousPlayerByOverallPosition[i]].position - 1] ==
                         gVsRacePlayerPoints[sVsRacePreviousPlayerByOverallPosition[j]] -
                             sVsRaceRacerCountPositionPoints
                                 [gTotalRacers][gRacers[sVsRacePreviousPlayerByOverallPosition[j]].position - 1]) &&
                        (gVsRacePlayerVictoryCount[sVsRacePreviousPlayerByOverallPosition[i]] -
                             sVsPositionToVictoryGivenCount
                                 [gRacers[sVsRacePreviousPlayerByOverallPosition[i]].position - 1] ==
                         gVsRacePlayerVictoryCount[sVsRacePreviousPlayerByOverallPosition[j]] -
                             sVsPositionToVictoryGivenCount
                                 [gRacers[sVsRacePreviousPlayerByOverallPosition[j]].position - 1]) &&
                        (gVsPreviousRacePosition[sVsRacePreviousPlayerByOverallPosition[i]] >
                         gVsPreviousRacePosition[sVsRacePreviousPlayerByOverallPosition[j]])) {
                        var_s1 = sVsRacePreviousPlayerByOverallPosition[i];
                        sVsRacePreviousPlayerByOverallPosition[i] = sVsRacePreviousPlayerByOverallPosition[j];
                        sVsRacePreviousPlayerByOverallPosition[j] = var_s1;
                    }
                }
            }
        }

        sVsRacePointsAddTimer++;
        if (sVsRacePointsAddTimer > 30000) {
            sVsRacePointsAddTimer = 0;
        }

        if ((sVsRacePointsAddTimer > 120) && !(sVsRacePointsAddTimer & 7)) {
            for (i = 0; i < gTotalRacers; i++) {
                for (j = 0; j < gTotalRacers; j++) {
                    if (gRacers[j].position == i + 1) {
                        break;
                    }
                }

                if (sVsRacePlayerPointsIncrease[gRacers[j].id] != 0) {
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_31);
                    }
                    sVsRacePlayerPointsIncrease[gRacers[j].id]--;
                    sVsRaceResultsPlayerDisplayPoints[gRacers[j].id]++;
                    break;
                }
            }
        }

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        gfx = Font_DrawString(gfx, 48, 80, "1Ｓ", 1, FONT_SET_5, 0);
        gfx = Font_DrawString(gfx, 48, 105, "2Ｎ", 1, FONT_SET_5, 0);

        if (gTotalRacers >= 3) {
            gfx = Font_DrawString(gfx, 48, 130, "3Ｒ", 1, FONT_SET_5, 0);
        }
        if (gTotalRacers >= 4) {
            gfx = Font_DrawString(gfx, 48, 155, "4Ｔ", 1, FONT_SET_5, 0);
        }

        for (i = 0; i < gTotalRacers; i++) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, sVsPlayerColorRed[sVsRacePreviousPlayerByOverallPosition[i]],
                            sVsPlayerColorGreen[sVsRacePreviousPlayerByOverallPosition[i]],
                            sVsPlayerColorBlue[sVsRacePreviousPlayerByOverallPosition[i]], 255);
            j = sVsRacePreviousPlayerByOverallPosition[i];

            if (gRacers[j].id < gNumPlayers) {
                gfx = Font_DrawString(gfx, 77, 80 + i * 25, "Ｐ", 1, FONT_SET_5, 0);
            } else {
                gfx = Font_DrawString(gfx, 77, 80 + i * 25, "Ａ", 1, FONT_SET_5, 0);
            }

            if (gRacers[j].id < gNumPlayers) {
                Menus_LoadNumberToStr(gRacers[j].id + 1);
            } else {
                Menus_LoadNumberToStr((gRacers[j].id - gNumPlayers) + 1);
            }

            gfx = Font_DrawString(gfx, 147, 80 + i * 25, sMenusLoadedNumberStr, 1, FONT_SET_5, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
            Menus_LoadNumberToStr(sVsRaceResultsPlayerDisplayPoints[gRacers[j].id]);
            gfx = Font_DrawString(gfx, 211 - Font_GetStringWidth(sMenusLoadedNumberStr, FONT_SET_5, 1), 80 + i * 25,
                                  sMenusLoadedNumberStr, 1, FONT_SET_5, 0);
            gfx = Font_DrawString(gfx, 211, 80 + i * 25, "$", 1, FONT_SET_5, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 100, 100, 255, 255);
            gfx = Font_DrawString(gfx, 237, 80 + i * 25, "+", 1, FONT_SET_5, 0);
            Menus_LoadNumberToStr(sVsRacePlayerPointsIncrease[gRacers[j].id]);
            gfx = Font_DrawString(gfx, 250, 80 + i * 25, sMenusLoadedNumberStr, 1, FONT_SET_5, 0);

            if (gRacers[j].position == 1) {
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                gfx = Font_DrawString(gfx, 270, 80 + i * 25, "v", 1, FONT_SET_5, 0);
            }
        }
    } else if (sVsResultsTimer >= 30030) {
        if (sVsResultsTimer < 60030) {
            boxScale = 0;
            if (sVsResultsTimer < 30060) {
                boxScale = -sVsResultsTimer * 4 + 120240;
            } else if (sVsResultsTimer > 60000) {
                boxScale = sVsResultsTimer * 4 - 240000;
            }
            gDPPipeSync(gfx++);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, boxScale + 30, boxScale + 25, 290 - boxScale, 220 - boxScale);

            if (sVsRaceResultsMenuOptionIndex == VS_RESULTS_COURSE_SELECT) {
                gDPPipeSync(gfx++);
                gfx = func_8007DB28(gfx, 0);
                gfx = Font_DrawScaledString(gfx, 130, 195, "Ｃ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
                gfx = Font_DrawScaledString(gfx, 110, 195, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = Font_DrawScaledString(gfx, 130, 210, "Ｅ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
            } else {
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = Font_DrawScaledString(gfx, 130, 195, "Ｃ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
                gDPPipeSync(gfx++);
                gfx = func_8007DB28(gfx, 0);
                gfx = Font_DrawScaledString(gfx, 130, 210, "Ｅ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
                gfx = Font_DrawScaledString(gfx, 110, 210, "Ｍ", 1, FONT_SET_5, 0, 0.8f, 0.8f);
            }

            for (i = 0; i < 4; i++) {
                sVsRacePlayerByOverallPosition[i] = i;
            }

            for (i = 0; i < gTotalRacers; i++) {
                for (j = i + 1; j < gTotalRacers; j++) {
                    if (gVsRacePlayerPoints[sVsRacePlayerByOverallPosition[i]] <
                        gVsRacePlayerPoints[sVsRacePlayerByOverallPosition[j]]) {
                        var_s1 = sVsRacePlayerByOverallPosition[i];
                        sVsRacePlayerByOverallPosition[i] = sVsRacePlayerByOverallPosition[j];
                        sVsRacePlayerByOverallPosition[j] = var_s1;
                    }
                    if ((gVsRacePlayerPoints[sVsRacePlayerByOverallPosition[i]] ==
                         gVsRacePlayerPoints[sVsRacePlayerByOverallPosition[j]]) &&
                        (gVsRacePlayerVictoryCount[sVsRacePlayerByOverallPosition[i]] <
                         gVsRacePlayerVictoryCount[sVsRacePlayerByOverallPosition[j]])) {
                        var_s1 = sVsRacePlayerByOverallPosition[i];
                        sVsRacePlayerByOverallPosition[i] = sVsRacePlayerByOverallPosition[j];
                        sVsRacePlayerByOverallPosition[j] = var_s1;
                    }
                    if ((gVsRacePlayerPoints[sVsRacePlayerByOverallPosition[i]] ==
                         gVsRacePlayerPoints[sVsRacePlayerByOverallPosition[j]]) &&
                        (gVsRacePlayerVictoryCount[sVsRacePlayerByOverallPosition[i]] ==
                         gVsRacePlayerVictoryCount[sVsRacePlayerByOverallPosition[j]]) &&
                        (gRacers[sVsRacePlayerByOverallPosition[i]].position >
                         gRacers[sVsRacePlayerByOverallPosition[j]].position)) {
                        var_s1 = sVsRacePlayerByOverallPosition[i];
                        sVsRacePlayerByOverallPosition[i] = sVsRacePlayerByOverallPosition[j];
                        sVsRacePlayerByOverallPosition[j] = var_s1;
                    }
                }
            }

            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = Font_DrawString(gfx, 48, 80, "1Ｓ", 1, FONT_SET_5, 0);
            gfx = Font_DrawString(gfx, 48, 105, "2Ｎ", 1, FONT_SET_5, 0);

            if (gTotalRacers >= 3) {
                gfx = Font_DrawString(gfx, 48, 130, "3Ｒ", 1, FONT_SET_5, 0);
            }
            if (gTotalRacers >= 4) {
                gfx = Font_DrawString(gfx, 48, 155, "4Ｔ", 1, FONT_SET_5, 0);
            }

            for (i = 0; i < gTotalRacers; i++) {
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, sVsPlayerColorRed[sVsRacePlayerByOverallPosition[i]],
                                sVsPlayerColorGreen[sVsRacePlayerByOverallPosition[i]],
                                sVsPlayerColorBlue[sVsRacePlayerByOverallPosition[i]], 255);

                if (sVsRacePlayerByOverallPosition[i] < gNumPlayers) {
                    gfx = Font_DrawString(gfx, 77, 80 + i * 25, "Ｐ", 1, FONT_SET_5, 0);
                } else {
                    gfx = Font_DrawString(gfx, 77, 80 + i * 25, "Ａ", 1, FONT_SET_5, 0);
                }

                if (sVsRacePlayerByOverallPosition[i] < gNumPlayers) {
                    Menus_LoadNumberToStr(sVsRacePlayerByOverallPosition[i] + 1);
                } else {
                    Menus_LoadNumberToStr((sVsRacePlayerByOverallPosition[i] - gNumPlayers) + 1);
                }

                gfx = Font_DrawString(gfx, 147, 80 + i * 25, sMenusLoadedNumberStr, 1, FONT_SET_5, 0);
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
                Menus_LoadNumberToStr(gVsRacePlayerPoints[sVsRacePlayerByOverallPosition[i]]);
                gfx = Font_DrawString(gfx, 211 - Font_GetStringWidth(sMenusLoadedNumberStr, FONT_SET_5, 1), 80 + i * 25,
                                      sMenusLoadedNumberStr, 1, FONT_SET_5, 0);
                gfx = Font_DrawString(gfx, 211, 80 + i * 25, "$", 1, FONT_SET_5, 0);

                if (gVsRacePlayerVictoryCount[sVsRacePlayerByOverallPosition[i]] > 0) {
                    gDPPipeSync(gfx++);
                    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                    gfx = Font_DrawString(gfx, 240, 80 + i * 25, "v", 1, FONT_SET_5, 0);
                    j = gVsRacePlayerVictoryCount[sVsRacePlayerByOverallPosition[i]];
                    if (j > 99) {
                        j = 99;
                    }
                    Menus_LoadNumberToStr(j);
                    gfx = Font_DrawString(gfx, 254, 80 + i * 25, sMenusLoadedNumberStr, 1, FONT_SET_5, 0);
                }

                if (totalVsVictories != 1) {
                    for (j = 0; j < gTotalRacers; j++) {
                        if (sVsRacePreviousPlayerByOverallPosition[j] == sVsRacePlayerByOverallPosition[i]) {
                            var_s1 = j;
                        }
                    }

                    if (var_s1 < i) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
                        gfx = Font_DrawString(gfx, 33, 80 + i * 25, "Ｄ", 1, FONT_SET_5, 0);
                    }

                    if (var_s1 > i) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                        gfx = Font_DrawString(gfx, 33, 80 + i * 25, "Ｕ", 1, FONT_SET_5, 0);
                    }
                }

                if (!sMenuIsBusy) {
                    j = gControllers[gPlayerControlPorts[i]].stickY;
                    if (sVsRaceResultsMenuOptionIndex == VS_RESULTS_QUIT) {
                        if (j > 50) {
                            sVsRaceResultsMenuOptionIndex = VS_RESULTS_COURSE_SELECT;
                            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                                Audio_TriggerSystemSE(NA_SE_30);
                            }
                        }
                        if (gControllers[gPlayerControlPorts[i]].buttonPressed & BTN_UP) {
                            sVsRaceResultsMenuOptionIndex = VS_RESULTS_COURSE_SELECT;
                            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                                Audio_TriggerSystemSE(NA_SE_30);
                            }
                        }
                    }
                    if (sVsRaceResultsMenuOptionIndex == VS_RESULTS_COURSE_SELECT) {
                        if (j < -50) {
                            sVsRaceResultsMenuOptionIndex = VS_RESULTS_QUIT;
                            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                                Audio_TriggerSystemSE(NA_SE_30);
                            }
                        }
                        if (gControllers[gPlayerControlPorts[i]].buttonPressed & BTN_DOWN) {
                            sVsRaceResultsMenuOptionIndex = VS_RESULTS_QUIT;
                            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                                Audio_TriggerSystemSE(NA_SE_30);
                            }
                        }
                    }
                }
            }
        }
    }
    sVsResultsTimer++;

    if (sVsResultsTimer) {}

    if (!sMenuIsBusy) {
        for (i = 0; i < gNumPlayers; i++) {
            if (gControllers[gPlayerControlPorts[i]].buttonPressed & (BTN_A | BTN_START)) {
                if ((sVsResultsTimer > 60) && (sVsResultsTimer < 30000)) {
                    sVsResultsTimer = 30000;
                } else if ((sVsResultsTimer > 30060) && (sVsResultsTimer < 60000)) {
                    sVsResultsTimer = 60000;
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_33);
                    }
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8007E0EC();
                    }
                }
            }
        }
    }

    if ((sVsResultsTimer == 60060) && !sMenuIsBusy) {
        for (i = 0; i < gTotalRacers; i++) {
            gVsPreviousRacePosition[i] = gRacers[i].position;
        }

        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
            func_8007E08C();
        }
#ifdef EXPANSION_KIT
        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
            Audio_RomBgmReady(BGM_SELECT);
        }
#endif

        if (sVsRaceResultsMenuOptionIndex == VS_RESULTS_COURSE_SELECT) {
            sMenuIsBusy = true;
            sMenuStateFlags |= MENU_STATE_CHANGE_COURSE;
        } else { // VS_RESULTS_QUIT
            sMenuIsBusy = true;
            sMenuStateFlags |= MENU_STATE_QUIT;
        }
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    return gfx;
}

extern s32 gRacePositionPoints[];

Gfx* Menus_DrawGpResultsScreen(Gfx* gfx, s32 playerIndex) {
    s32 i;
    s32 boxScale;
    s32 scrollTop;
    f32 manualScrollSpeed;
    s32 pad[2];

    boxScale = 0;
    if (sPlayerResultsTimer[playerIndex] < 30) {
        boxScale = (30 - sPlayerResultsTimer[playerIndex]) * 4;
    } else if (sPlayerResultsTimer[playerIndex] > 30030) {
        boxScale = (sPlayerResultsTimer[playerIndex] - 30030) * 4;
    }

    gfx = Menus_DrawResultsBox(gfx, boxScale);

    if ((sPlayerResultsTimer[playerIndex] > 30) && (sPlayerResultsTimer[playerIndex] < 30030)) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, 162 - (Font_GetStringWidth("results", FONT_SET_3, 1) / 2), 52, "results", 1,
                              FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth("results", FONT_SET_3, 1) / 2), 50, "results", 1,
                              FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 30, 55, 290, 204);

        for (i = 0; i < gTotalRacers; i++) {
            scrollTop = (58 + i * 25) - sGpResultsRankingScrollPosition;
            if (scrollTop > 20 && scrollTop < 220) {
                if (gGameMode == GAMEMODE_GP_RACE) {
                    gfx = Menus_DrawResultsRankingCharacterPortrait(
                        gfx, gRacersByPosition[i]->id, gRacersByPosition[i]->character, 45,
                        (s32) ((55 + i * 25) - sGpResultsRankingScrollPosition), 0.75f);
                    gfx = Menus_DrawPositionNumber(gfx, gRacersByPosition[i]->id, i + 1, 44,
                                                   (s32) ((64 + i * 25) - sGpResultsRankingScrollPosition));
                    gfx = Menus_DrawResultsCharacterName(gfx, gRacersByPosition[i]->id, gRacersByPosition[i]->character,
                                                         73, (s32) ((70 + i * 25) - sGpResultsRankingScrollPosition));
                    gfx = Menus_DrawPlusPoints(gfx, gRacersByPosition[i]->id, 216,
                                               (s32) ((70 + i * 25) - sGpResultsRankingScrollPosition));
                    if (gRacersByPosition[i]->raceTime != 0) {
                        gfx = Menus_DrawPositionNumber(gfx, gRacersByPosition[i]->id, gRacePositionPoints[i], 199,
                                                       (s32) ((70 + i * 25) - sGpResultsRankingScrollPosition));
                    } else {
                        gfx = Menus_DrawPositionNumber(gfx, gRacersByPosition[i]->id, 0, 199,
                                                       (s32) ((70 + i * 25) - sGpResultsRankingScrollPosition));
                        gfx = Menus_DrawResultsRetireStatus(gfx, gRacersByPosition[i]->id, 220,
                                                            (s32) ((70 + i * 25) - sGpResultsRankingScrollPosition));
                    }
                } else {
                    gfx = Menus_DrawResultsRankingCharacterPortrait(
                        gfx, gRacersByPosition[i]->id, (s32) gRacersByPosition[i]->character, 57,
                        (s32) ((55 + i * 25) - sGpResultsRankingScrollPosition), 0.75f);
                    gfx = Menus_DrawPositionNumber(gfx, gRacersByPosition[i]->id, i + 1, 56,
                                                   (s32) ((64 + i * 25) - sGpResultsRankingScrollPosition));
                    gfx = Menus_DrawResultsCharacterName(gfx, gRacersByPosition[i]->id,
                                                         (s32) gRacersByPosition[i]->character, 85,
                                                         (s32) ((70 + i * 25) - sGpResultsRankingScrollPosition));
                    if (gRacersByPosition[i]->raceTime == 0) {
                        gfx = Menus_DrawResultsRetireStatus(gfx, gRacersByPosition[i]->id, 190,
                                                            (s32) ((70 + i * 25) - sGpResultsRankingScrollPosition));
                    }
                }
            }
        }

        gSPDisplayList(gfx++, D_8014940);
        gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        for (i = 0; i < gTotalRacers; i++) {

            if (gRacersByPosition[i]->raceTime != 0) {
                scrollTop = (58 + i * 25) - sGpResultsRankingScrollPosition;
                if ((scrollTop > 20) && (scrollTop < 220)) {
                    gDPPipeSync(gfx++);
                    if (gRacersByPosition[i]->id == 0) {
                        gfx = TextureUtils_SetPulsingColor(gfx, 255, 0, 0);
                        gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
                    } else {
                        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                    }
                    if (gGameMode == GAMEMODE_GP_RACE) {
                        gfx =
                            Hud_DrawTimerScisThousandths(gfx, gRacersByPosition[i]->raceTime, 213,
                                                         (s32) ((58 + i * 25) - sGpResultsRankingScrollPosition), 1.0f);
                    } else {
                        gfx =
                            Hud_DrawTimerScisThousandths(gfx, gRacersByPosition[i]->raceTime, 185,
                                                         (s32) ((58 + i * 25) - sGpResultsRankingScrollPosition), 1.0f);
                    }
                }
            }
        }
    }
    manualScrollSpeed = gControllers[gPlayerControlPorts[0]].stickY * -1.0f;
    if ((manualScrollSpeed > 0.0f) && (manualScrollSpeed < 14.0f)) {
        manualScrollSpeed = 0.0f;
    }
    if ((manualScrollSpeed < 0.0f) && (manualScrollSpeed > -14.0f)) {
        manualScrollSpeed = 0.0f;
    }
    manualScrollSpeed *= 0.075f;
    sGpResultsRankingScrollPosition += manualScrollSpeed;
    if (sGpResultsRankingScrollPosition < 0.0f) {
        sGpResultsRankingScrollPosition = 0.0f;
    }

    if ((gTotalRacers - 6) * 25.0f < sGpResultsRankingScrollPosition) {
        sGpResultsRankingScrollPosition = (gTotalRacers - 6) * 25.0f;
    }
    if ((sGpResultsRankingScrollPosition != (gTotalRacers - 6) * 25.0f) && (sGpResultsRankingScrollPosition != 0.0f)) {
        if ((s32) (sGpResultsRankingScrollPosition * 0.06f) !=
            ((s32) ((sGpResultsRankingScrollPosition - manualScrollSpeed) * 0.06f))) {
            Audio_TriggerSystemSE(NA_SE_63);
        }
    }

    sPlayerResultsTimer[playerIndex]++;
    if ((sPlayerResultsTimer[playerIndex] < 30030) &&
        (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START))) {
        sPlayerResultsTimer[playerIndex] = 30030;
    }
    if (sPlayerResultsTimer[playerIndex] >= 30060) {
        sPlayerResultsTimer[playerIndex] = 0;
        if (gGameMode == GAMEMODE_GP_RACE) {
            sGpRaceResultsState = GP_RESULTS_TOTAL_RANKING;
        } else {
            sGpRaceResultsState = GP_RESULTS_END_MENU;
            sGpResultsEndMenuScissorBoxTimer = 60;
        }
    }
    return gfx;
}

extern s16 gPlayer1OverallPosition;
extern s16 gRacerPositionsById[];

Gfx* Menus_DrawGpResultsTotalRanking(Gfx* gfx, s32 playerIndex) {
    s32 i;
    s32 j;
    s32 boxScale;
    s32 scrollTop;
    s32 var_s0;
    s32 temp_a2;
    f32 manualScrollSpeed;
    s32 pad;

    boxScale = 0;
    if (sPlayerResultsTimer[playerIndex] < 30) {
        boxScale = (30 - sPlayerResultsTimer[playerIndex]) * 4;
    } else if (sPlayerResultsTimer[playerIndex] > 40030) {
        boxScale = (sPlayerResultsTimer[playerIndex] - 40030) * 4;
    }
    gfx = Menus_DrawResultsBox(gfx, boxScale);

    if ((sPlayerResultsTimer[playerIndex] > 30) && (sPlayerResultsTimer[playerIndex] < 40030)) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gfx = Font_DrawString(gfx, 162 - (Font_GetStringWidth("total ranking", FONT_SET_3, 1) / 2), 52, "total ranking",
                              1, FONT_SET_3, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth("total ranking", FONT_SET_3, 1) / 2), 50, "total ranking",
                              1, FONT_SET_3, 0);

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

        sTotalRankingsForcedScrollPosition -= sTotalRankingsForcedScrollSpeed;
        sTotalRankingsForcedScrollSpeed -= 0.01f;
        if (sTotalRankingsForcedScrollSpeed < 0.01f) {
            sTotalRankingsForcedScrollSpeed = 0.01f;
        }
        if (sTotalRankingsForcedScrollPosition < -62.0f) {
            sTotalRankingsForcedScrollPosition = -62.0f;
        } else if ((s32) (sTotalRankingsForcedScrollPosition * 0.06f) !=
                   (s32) ((sTotalRankingsForcedScrollPosition - sTotalRankingsForcedScrollSpeed) * 0.06f)) {
            Audio_TriggerSystemSE(NA_SE_63);
        }

        for (i = 0; i < gTotalRacers; i++) {
            scrollTop = (i * 25) - sTotalRankingsForcedScrollPosition - sTotalRankingsManualScrollPosition;
            if ((scrollTop > 10) && (scrollTop < 220)) {
                if (gCourseIndex % 6) {
                    // Change In Positions
                    if (gRacerPositionsById[gRacerIdsByPosition[i]] < i + 1) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
                        gfx = Font_DrawString(gfx, 47, scrollTop + 19, "Ｄ", 1, FONT_SET_5, 0);
                        var_s0 = 61;
                        if ((i - gRacerPositionsById[gRacerIdsByPosition[i]]) + 1 < 10) {
                            var_s0 = 58;
                        }
                        gfx = Menus_DrawPositionNumber(gfx, 1, (i - gRacerPositionsById[gRacerIdsByPosition[i]]) + 1,
                                                       var_s0, scrollTop + 16);
                    }
                    if (gRacerPositionsById[gRacerIdsByPosition[i]] > i + 1) {
                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
                        gfx = Font_DrawString(gfx, 47, scrollTop + 22, "Ｕ", 1, FONT_SET_5, 0);
                        var_s0 = 61;
                        if ((i - gRacerPositionsById[gRacerIdsByPosition[i]]) + 1 > -10) {
                            var_s0 = 58;
                        }
                        gfx = Menus_DrawPositionNumber(gfx, 1, (gRacerPositionsById[gRacerIdsByPosition[i]] - i) - 1,
                                                       var_s0, scrollTop + 19);
                    }
                }

                gfx = Menus_DrawResultsRankingCharacterPortrait(gfx, gRacers[gRacerIdsByPosition[i]].id,
                                                                gRacers[gRacerIdsByPosition[i]].character, 81,
                                                                scrollTop, 0.75f);
                gfx = Menus_DrawPositionNumber(gfx, gRacers[gRacerIdsByPosition[i]].id, i + 1, 81, scrollTop + 9);
                gfx = Menus_DrawResultsCharacterName(gfx, gRacers[gRacerIdsByPosition[i]].id,
                                                     gRacers[gRacerIdsByPosition[i]].character, 109, scrollTop + 15);
                gfx = Menus_DrawPoints(gfx, gRacers[gRacerIdsByPosition[i]].id, 259, scrollTop + 15);
                gfx = Menus_DrawPositionNumber(gfx, gRacers[gRacerIdsByPosition[i]].id,
                                               gRacers[gRacerIdsByPosition[i]].points, 243, scrollTop + 15);
            }

            if (gRacerIdsByPosition[i] == 0) {
                gPlayer1OverallPosition = i + 1;
            }
        }
    }

#ifndef EXPANSION_KIT
    if ((gGameMode == GAMEMODE_GP_RACE) && (sPlayerResultsTimer[playerIndex] == 60) && (gRacerIdsByPosition[0] == 0) &&
        ((gCourseIndex % 6) == 5) && (gCupType <= X_CUP)) {
#else
    if ((gGameMode == GAMEMODE_GP_RACE) && (sPlayerResultsTimer[playerIndex] == 60) && (gRacerIdsByPosition[0] == 0) &&
        ((gCourseIndex % 6) == 5)) {
#endif
        func_8007DEF0();
#ifndef EXPANSION_KIT
        if (gRacers[0].customType == CUSTOM_MACHINE_DEFAULT) {
#endif
            Save_UpdateCupCompletion(gDifficulty, gCupType, gRacers[0].character);
#ifndef EXPANSION_KIT
        }
#endif
    }

    sPlayerResultsTimer[playerIndex]++;

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
        sTotalRankingsForcedScrollSpeed = 8.0f;
    }
    if ((sPlayerResultsTimer[playerIndex] < 40030) && (sTotalRankingsForcedScrollPosition <= -62.0f)) {
        if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
            sPlayerResultsTimer[playerIndex] = 40030;
        }
        manualScrollSpeed = gControllers[gPlayerControlPorts[0]].stickY * -1.0f;
        if ((manualScrollSpeed > 0.0f) && (manualScrollSpeed < 14.0f)) {
            manualScrollSpeed = 0.0f;
        }
        if ((manualScrollSpeed < 0.0f) && (manualScrollSpeed > -14.0f)) {
            manualScrollSpeed = 0.0f;
        }
        manualScrollSpeed *= 0.075f;
        sTotalRankingsManualScrollPosition += manualScrollSpeed;
        if (sTotalRankingsManualScrollPosition < 0.0f) {
            sTotalRankingsManualScrollPosition = 0.0f;
        }

        if (((gTotalRacers - 6) * 25.0f + 7.0f) < sTotalRankingsManualScrollPosition) {
            sTotalRankingsManualScrollPosition = (gTotalRacers - 6) * 25.0f + 7.0f;
        }
        if ((sTotalRankingsManualScrollPosition != 0.0f) &&
            (sTotalRankingsManualScrollPosition != ((gTotalRacers - 6) * 25.0f + 7.0f)) &&
            (s32) (sTotalRankingsManualScrollPosition * 0.06f) !=
                (s32) ((sTotalRankingsManualScrollPosition - manualScrollSpeed) * 0.06f)) {
            Audio_TriggerSystemSE(NA_SE_63);
        }
    }
    if (sPlayerResultsTimer[playerIndex] >= 40060) {
        sGpRaceResultsState = GP_RESULTS_TO_NEXT_COURSE;
#ifdef EXPANSION_KIT
        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
            Audio_RomBgmReady(BGM_SELECT);
        }
#endif

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

Gfx* Menus_Player1SpecialDraw(Gfx* gfx, s32 playerIndex) {
    s32 i;

    if (gCameras[playerIndex].mode == CAMERA_MODE_FINISHED_LOSER) {
        if ((gGameMode != GAMEMODE_TIME_ATTACK) ||
            ((gGameMode == GAMEMODE_TIME_ATTACK) && (gCurrentGhostType < GHOST_STAFF))) {
            if (!sPlayerFinishInitialized[playerIndex]) {
                sPlayerFinishInitialized[playerIndex] = true;
                Menus_InitFinish(playerIndex);
            }

            if (sPlayerLoserFinishTimer[playerIndex] < 300) {
                gfx = Menus_DrawFinish(gfx, playerIndex);
            }
        } else {
            if ((sPlayerLoserFinishTimer[playerIndex] < 300) &&
                ((gGameFrameCount & 4) || (sPlayerLoserFinishTimer[playerIndex] > 60))) {
                gRacers[0].awarenessFlags |= 0x1000;
                gfx = Menus_DrawPlayerLoser(gfx, 0);
            }
            if (sPlayerLoserFinishTimer[playerIndex] == 120) {
                if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
#ifndef EXPANSION_KIT
                    Audio_RomBgmStart(BGM_21);
#else
                    func_8070DAD4(BGM_21);
#endif
                }

                for (i = 0; i < gNumPlayers; i++) {
                    if ((gRacers[i].stateFlags & RACER_STATE_CRASHED) ||
                        (gRacers[playerIndex].stateFlags & RACER_STATE_FINISHED)) {
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_3);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_4);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_5);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_8);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_9);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_10);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_11);
                    }
                }
            }

            if ((sPlayerLoserFinishTimer[playerIndex] == 2) && (gCourseIndex < COURSE_X_1) && (gTotalLapCount == 3)) {
                sMenuStateFlags |= MENU_STATE_RACE_FINISH_SAVE;
            }
        }
        sPlayerLoserFinishTimer[playerIndex]++;
    } else if (sPlayerFinishState[playerIndex] == PLAYER_FINISH_CAMERA_SUCCESS) {
        if ((gGameMode != GAMEMODE_TIME_ATTACK) ||
            ((gGameMode == GAMEMODE_TIME_ATTACK) && (gCurrentGhostType < GHOST_STAFF))) {
            if (!sPlayerFinishInitialized[playerIndex]) {
                sPlayerFinishInitialized[playerIndex] = true;
                Menus_InitFinish(playerIndex);
            }
            gfx = Menus_DrawFinish(gfx, playerIndex);
        } else {

            if ((sPlayerWinnerLoserFinishGameoverTimer[playerIndex] > 60) || (gGameFrameCount & 4)) {
                gfx = Menus_DrawPlayerWinner(gfx, 0);
            }
            if (sPlayerWinnerLoserFinishGameoverTimer[playerIndex] == 30) {
#ifdef EXPANSION_KIT
                Save_SetDDStaffGhostComplete(gCourseIndex);
#endif
                if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
#ifndef EXPANSION_KIT
                    Audio_RomBgmStart(BGM_22);
#else
                    func_8070DAD4(BGM_22);
#endif
                }

                for (i = 0; i < gNumPlayers; i++) {
                    if ((gRacers[i].stateFlags & RACER_STATE_CRASHED) ||
                        (gRacers[playerIndex].stateFlags & RACER_STATE_FINISHED)) {
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_3);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_4);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_5);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_8);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_9);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_10);
                        Audio_PlayerLevelSEStop(i, NA_LEVEL_SE_11);
                    }
                }
            }
            if ((sPlayerWinnerLoserFinishGameoverTimer[playerIndex] == 2) && (gCourseIndex < COURSE_X_1) &&
                (gTotalLapCount == 3)) {
                sMenuStateFlags |= MENU_STATE_RACE_FINISH_SAVE;
            }
        }
    } else {
        sPlayerFinishInitialized[playerIndex] = false;
    }
    return gfx;
}

extern s32 gTotalLapCount;
extern char* gCurrentTrackName;
extern s16 D_800E5FBC;
extern s16 gRacersRetired;
extern s16 gUnableToRecordGhost;
extern s32 gRaceIntroTimer;
extern s32 gPlayerReverseTimer[];
extern s32 gSettingVsSlot;
extern s32 gRaceTimeIntervalToggle;
extern s32 sEADDemoQueueState;

Gfx* Menus_Draw(Gfx* gfx) {
    s32 i = 0;
    s32 j;
    Racer* racer;
    s32 pad[4];
    f32 averageSpeed;
    f32 intervalTime;
    s32 playerIndex = 0;

    gRacersRemaining = gTotalRacers - gRacersRetired;
    if ((gNumPlayers == 1) && (gTotalRacers != 1) && !(gGameFrameCount % 64) && !gGamePaused) {
        func_i3_801175A4();
    }
    if (gNumPlayers == 1) {
        if (gGameMode == GAMEMODE_DEATH_RACE) {
            //! @bug These speed checks do not account for PAL changes correctly
#ifndef VERSION_PAL
            if (gRacers[playerIndex].speed < 400.0f / SPEED_CONVERSION) {
#else
            if (gRacers[playerIndex].speed < 18.518517f) {
#endif
                D_80141900++;
            } else {
                D_80141900 = 0;
            }
        } else {
#ifndef VERSION_PAL
            if (gRacers[playerIndex].speed < 200.0f / SPEED_CONVERSION) {
#else
            if (gRacers[playerIndex].speed < 9.2592585f) {
#endif
                D_80141900++;
            } else {
                D_80141900 = 0;
            }
        }
    }

    for (i = 0; i < gNumPlayers; i++) {
        if (gRacers[i].stateFlags & RACER_STATE_FINISHED) {
            sPlayerFinishTimer[i]++;
            if (sPlayerFinishTimer[i] > 36000) {
                sPlayerFinishTimer[i] = 36000;
            }

            if (sFinishedSuccessTime < sPlayerFinishTimer[i]) {
                sPlayerFinishState[i] = PLAYER_FINISH_SUCCESS_COMPLETE;
            } else {
                sPlayerFinishState[i] = PLAYER_FINISH_CAMERA_SUCCESS;
            }
        }
        if ((gNumPlayers >= 2) && (D_800E5FBC == 1)) {
            sPlayerFinishState[i] = PLAYER_FINISH_SUCCESS_COMPLETE;
        }
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    if (!D_80141D6C) {
        if (gNumPlayers == 3) {
            gfx = Menus_DrawBeveledBox(gfx, 160, 120, 305, 232, 0, 0, 0, 255);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 250, 255);
            gfx = Font_DrawScaledString(gfx,
                                        (234.0f - ((Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 1) * 0.7f) / 2)),
                                        148, gCurrentTrackName, 1, FONT_SET_3, 0, 0.7f, 0.7f);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
            gfx = Font_DrawScaledString(gfx,
                                        (232.0f - ((Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 1) * 0.7f) / 2)),
                                        146, gCurrentTrackName, 1, FONT_SET_3, 0, 0.7f, 0.7f);
        }

        gDPPipeSync(gfx++);
        if (gNumPlayers == 1) {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
        } else {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
        }

        if ((gNumPlayers != 1) || (gGameMode != GAMEMODE_GP_RACE) || (sPlayer1Lives > 0) ||
            (sPlayerGameoverState[0] < PLAYER_GAMEOVER_DISPLAY)) {
            if (!((gNumPlayers == 1) && (sPlayerFinishState[0] == PLAYER_FINISH_SUCCESS_COMPLETE)) &&
                !((gNumPlayers == 1) && (gCameras[playerIndex].mode == CAMERA_MODE_FINISHED_LOSER) &&
                  (sPlayerLoserFinishTimer[0] >= 300))) {
                gfx = Hud_DrawHud(gfx);
            }
            for (i = 0; i < gNumPlayers; i++) {
                if (!((gNumPlayers == 1) && ((sPlayerFinishState[i] == PLAYER_FINISH_SUCCESS_COMPLETE) ||
                                             ((gCameras[playerIndex].mode == CAMERA_MODE_FINISHED_LOSER) &&
                                              (sPlayerLoserFinishTimer[0] >= 300))))) {
                    if (gNumPlayers == 1) {
                        gfx = Hud_DrawRacePortraits(gfx);
                    }
                    if ((gGameMode != GAMEMODE_DEATH_RACE) && (sPlayerGameoverState[i] == PLAYER_GAMEOVER_NONE) &&
                        !(gRacers[i].stateFlags & RACER_STATE_FINISHED)) {
                        gfx = Minimap_DrawCourseMinimap(gfx, gNumPlayers - 1, i);
                    }
                    if (gNumPlayers == 3) {
                        gfx = Minimap_DrawCourseMinimap(gfx, gNumPlayers - 1, 3);
                    }
                    gfx = Hud_DrawPosition(gfx, gNumPlayers - 1, i);
                }
                if (((gNumPlayers != 1) || (sPlayerGameoverState[i] == PLAYER_GAMEOVER_NONE)) &&
                    !(gRacers[i].stateFlags & RACER_STATE_FINISHED)) {
                    gfx = Hud_DrawPlayerSpeed(gfx, gNumPlayers - 1, i);
                }
            }
        }
    }
    if (((gGameFrameCount % 120) == 0) && !gGamePaused) {
        for (i = 0; i < gTotalRacers; i++) {
            if (!(gRacers[i].stateFlags & RACER_STATE_FINISHED) && (gRacers[i].stateFlags & RACER_STATE_CRASHED)) {
                gRacers[i].unk_368 = 254;
            }
        }

        if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
            j = 0;
            for (i = 0; i < gNumPlayers; i++) {
                if (gRacers[i].stateFlags & RACER_STATE_CRASHED) {
                    j++;
                }
            }

            if (((gNumPlayers == j) || (D_800E5FBC == 1)) && (gTitleDemoState == TITLE_DEMO_ACTIVE)) {
                gTitleDemoState = TITLE_DEMO_START_EXIT;
            }
        }
    }
    if (gNumPlayers == 1) {
        if (((gCameras[playerIndex].mode == CAMERA_MODE_RACE_INTRO) ||
             (gCameras[playerIndex].mode == CAMERA_MODE_RACE)) &&
            (sPlayerGameoverState[0] == PLAYER_GAMEOVER_NONE)) {
            averageSpeed = gRacers[playerIndex].raceDistance / gRacers[playerIndex].raceTime;
            if (gGameMode == GAMEMODE_GP_RACE) {
                if (gRaceTimeIntervalToggle) {
                    if ((averageSpeed > 0.1f) && (gRacersRemaining >= 2)) {
                        if (gRacers[playerIndex].position != 1) {
                            intervalTime = ((gRacersByPosition[0]->raceDistance - gRacers[playerIndex].raceDistance) /
                                            averageSpeed) *
                                           0.8892f;
                        } else {
                            intervalTime = ((gRacersByPosition[1]->raceDistance - gRacers[playerIndex].raceDistance) /
                                            averageSpeed) *
                                           0.8892f;
                        }
                        if (gRacersByPosition[0]->stateFlags & RACER_STATE_FINISHED) {
                            intervalTime = ((gRacers[playerIndex].raceTime / gRacers[playerIndex].raceDistance) *
                                            gCurrentCourseInfo->length * gTotalLapCount) -
                                           gRacersByPosition[0]->raceTime;
                        }
                        if ((intervalTime < 30000.0f) && (intervalTime > -30000.0f) && (gPlayerReverseTimer[0] < 10)) {
                            gfx = Menus_DrawRaceTimeInterval(gfx, intervalTime, 222, 54);
                        } else {
                            gfx = Menus_DrawBlankTimeHundredths(gfx, 222, 54);
                        }
                    } else {
                        gfx = Menus_DrawBlankTimeHundredths(gfx, 222, 54);
                    }
                }
                if ((gTitleDemoState == TITLE_DEMO_INACTIVE) &&
                    (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_L)) {
                    gRaceTimeIntervalToggle ^= 1;
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_49);
                    }
                }
            } else if ((gGameMode == GAMEMODE_TIME_ATTACK) && (gFastestGhostIndex >= 0)) {

                if (sFastestGhostRacerRacer->lapDistance - sFastestGhostRacerLapDistance <
                    -(gCurrentCourseInfo->length * 0.5f)) {
                    sFastestGhostRacerLapsCompletedDistance += gCurrentCourseInfo->length;
                }

                if (gCurrentCourseInfo->length * 0.5f <
                    sFastestGhostRacerRacer->lapDistance - sFastestGhostRacerLapDistance) {
                    sFastestGhostRacerLapsCompletedDistance -= gCurrentCourseInfo->length;
                }
                sFastestGhostRacerRacer->raceDistance =
                    sFastestGhostRacerRacer->lapDistance + sFastestGhostRacerLapsCompletedDistance;
                if (gRaceTimeIntervalToggle) {
                    if (averageSpeed > 0.1f) {
                        intervalTime = ((sFastestGhostRacerRacer->raceDistance - gRacers[playerIndex].raceDistance) /
                                        averageSpeed) *
                                       0.8892f;
                        if ((gCurrentCourseInfo->length * (gTotalLapCount - 0.01f)) <=
                            sFastestGhostRacerRacer->raceDistance) {
                            intervalTime = ((gRacers[playerIndex].raceTime / gRacers[playerIndex].raceDistance) *
                                            gCurrentCourseInfo->length * gTotalLapCount) -
                                           gFastestGhostTime;
                        }
                        if ((intervalTime < 30000.0f) && (intervalTime > -30000.0f) && (gPlayerReverseTimer[0] < 10)) {
                            gfx = Menus_DrawRaceTimeInterval(gfx, intervalTime, 222, 54);
                        } else {
                            gfx = Menus_DrawBlankTimeHundredths(gfx, 222, 54);
                        }
                    } else {
                        gfx = Menus_DrawBlankTimeHundredths(gfx, 222, 54);
                    }
                }
                sFastestGhostRacerLapDistance = sFastestGhostRacerRacer->lapDistance;
                if ((gTitleDemoState == TITLE_DEMO_INACTIVE) &&
                    (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_L)) {
                    gRaceTimeIntervalToggle ^= 1;
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        Audio_TriggerSystemSE(NA_SE_49);
                    }
                }
            }
        }

        if ((gGameMode == GAMEMODE_TIME_ATTACK) && !gGamePaused && gUnableToRecordGhost &&
            (gCameras[playerIndex].mode == CAMERA_MODE_RACE) && (sPlayerGameoverState[0] == PLAYER_GAMEOVER_NONE)) {
            gfx = Menus_DrawCannotSaveGhost(gfx);
        }
        if (gGameMode != GAMEMODE_PRACTICE) {
            if ((gRacers[playerIndex].lap == gTotalLapCount) && (gTitleDemoState == TITLE_DEMO_INACTIVE) &&
                (D_i3_80141EA8[playerIndex].lapFlashTimer > 0) && !gGamePaused) {
                if (((D_i3_80141EA8[playerIndex].lapFlashTimer % 20) >= 5) &&
                    (D_i3_80141EA8[playerIndex].lapFlashTimer > 120)) {
                    gfx = Menus_DrawPlayerFinalLap(gfx, 0);
                }
                sPlayerFinalLapTimer[playerIndex]++;
            }
            if ((gRacers[playerIndex].lap == 2) && (gTitleDemoState == TITLE_DEMO_INACTIVE) && !gGamePaused &&
                (D_i3_80141EA8[playerIndex].lapFlashTimer > 0)) {
                if (((D_i3_80141EA8[playerIndex].lapFlashTimer % 20) >= 5) &&
                    (D_i3_80141EA8[playerIndex].lapFlashTimer > 120)) {
                    gfx = Menus_DrawPlayerBoosterOk(gfx, 0);
                }
                sPlayerBoosterOkTimer[playerIndex]++;
            }
        }
        if (!gGamePaused && (gCameras[playerIndex].mode == CAMERA_MODE_RACE_INTRO)) {
            gDPPipeSync(gfx++);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
            sMenuRaceIntroTimer++;
            if (sMenuRaceIntroTimer >= 4) {
                j = sMenuRaceIntroTimer - 200;
                if (sMenuRaceIntroTimer < 250) {
                    if (j < 0) {
                        j = 0;
                    }

                    if (gGameMode != GAMEMODE_DEATH_RACE) {
                        i = 320 - (sMenuRaceIntroTimer * 8);
                        if (i < 160) {
                            i = 160;
                        }
                        gfx = Menus_DrawCourseName(gfx, i, 120, j);
                    }
                    i = sMenuRaceIntroTimer * 8;
                    if (i > 160) {
                        i = 160;
                    }
                    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) ||
                        (gGameMode == GAMEMODE_DEATH_RACE)) {
                        gfx = Menus_DrawRaceIntroDisplay(gfx, i, 93, j);
                        if ((gGameMode == GAMEMODE_DEATH_RACE) && (gCurrentCourseInfo->timeRecord[0] != MAX_TIMER)) {
                            i = 300 - (sMenuRaceIntroTimer * 8);
                            if (i < 160) {
                                i = 140;
                            }
                            gfx = Menus_DrawDeathRaceIntroBestTimeDisplay(gfx, 160, i, j);
                        }
                    } else {
                        gfx = Menus_DrawTimeAttackIntroDisplay(gfx, i, 86, j);
                        if (gCurrentCourseInfo->timeRecord[0] != MAX_TIMER) {
                            i = 320 - (sMenuRaceIntroTimer * 8);
                            if (i < 160) {
                                i = 160;
                            }
                            gfx = Menus_DrawTimeAttackIntroBestTimeDisplay(gfx, 160, i, j);
                        }
                    }
                }
            }
        }
        if ((sPlayerFinishState[0] == PLAYER_FINISH_SUCCESS_COMPLETE) ||
            ((gCameras[playerIndex].mode == CAMERA_MODE_FINISHED_LOSER) && (sPlayerLoserFinishTimer[0] > 300))) {
            if (!D_i3_80141B78[playerIndex]) {
                D_i3_80141B78[playerIndex] = true;
                if (gGameMode != GAMEMODE_TIME_ATTACK) {
                    func_8008AA8C();
                }
            }
            if (gGameMode == GAMEMODE_TIME_ATTACK) {
                if (sTimeAttackResultsTimer < 400) {
                    gfx = Menu_DrawTimeAttackResultsTimes(gfx);
                    gfx = Menus_DrawMaxSpeed(gfx, 0);
                }
                gfx = Menus_DrawCourseName(gfx, 160, 38, 0);
                if ((sPlayerResultsTimer[playerIndex] > 100) &&
                    (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) &&
                    (sTimeAttackResultsTimer == 0)) {
                    sTimeAttackResultsTimer = 1;
                }

                if (sTimeAttackResultsTimer != 0) {
                    sTimeAttackResultsTimer += 8;
                }
                if ((sTimeAttackResultsTimer >= 392) && (sTimeAttackResultsTimer < 400)) {
                    if (gCurrentTimeAttackRecordPosition == 0) {
                        RecordsEntry_ToRecordsState();
                    }
#if !defined(EXPANSION_KIT) && !defined(VERSION_PAL)
                    Menus_CheckGhostCanSave();
#endif
                }
                if (sTimeAttackResultsTimer >= 400) {
                    sTimeAttackResultsTimer = 400;
                    if (gShowNameEntryMenu) {
                        RecordsEntry_UpdateNameEntry();
                        gfx = RecordsEntry_DrawNameEntry(gfx);
                    } else {
#if defined(EXPANSION_KIT) || defined(VERSION_PAL)
                        if (D_i3_8006D0B4 == 0) {
                            Menus_CheckGhostCanSave();
                            D_i3_8006D0B4 = 1;
#ifdef EXPANSION_KIT
                            {
                                s32 courseIndex;
                                bool beatAllDDStaffGhosts;
                                beatAllDDStaffGhosts = true;
                                for (courseIndex = COURSE_MUTE_CITY; courseIndex <= COURSE_BIG_HAND; courseIndex++) {
                                    if (gCourseInfos[courseIndex].timeRecord[0] >=
                                        Save_GetDDStaffGhostRecordTime(courseIndex)) {
                                        beatAllDDStaffGhosts = false;
                                        break;
                                    }
                                }
                                if ((gCurrentGhostType == GHOST_STAFF) && (Save_GetDDStaffGhostCompletion() == 0xFFF) &&
                                    beatAllDDStaffGhosts) {
                                    sEADDemoQueueState = 1;
                                }
                            }
#endif
                        }
#endif
                        i = RecordsEntry_Update();
                        gfx = RecordsEntry_DrawRecords(gfx, gCourseIndex);
                        if (i) {
                            gfx = Menus_DrawTimeAttackFinishMenu(gfx);
                        }
                    }
                }
            } else if (gGameMode == GAMEMODE_GP_RACE) {
                switch (sGpRaceResultsState) {
                    case GP_RESULTS_TOP_6_TIMING:
                        gfx = Menus_DrawCourseName(gfx, 160, 200, 0);
                        gfx = Menus_DrawGpResultsPortraitsTimes(gfx);
                        gfx = Menus_DrawMaxSpeed(gfx, 0);
                        if ((sPlayerResultsTimer[playerIndex] >= 600) ||
                            (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START))) {
                            sGpRaceResultsState = GP_RESULTS_RACE_RESULT;
                            sPlayerResultsTimer[playerIndex] = 0;
                        }
                        break;
                    case GP_RESULTS_RACE_RESULT:
                        gfx = Menus_DrawGpResultsScreen(gfx, 0);
                        sTotalRankingsForcedScrollPosition = gTotalRacers * 25;
                        sTotalRankingsForcedScrollSpeed = 4.2f;
                        break;
                    case GP_RESULTS_TOTAL_RANKING:
                        gfx = Menus_DrawGpResultsTotalRanking(gfx, 0);
                        break;
                    case GP_RESULTS_TO_NEXT_COURSE:
                        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                            Audio_LevelSEFadeout();
                        }
                        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                            func_8007E0EC();
                        }
                        sMenuIsBusy = true;
                        D_i3_801419A6 = 30;
                        sMenuStateFlags |= MENU_STATE_GP_NEXT_COURSE;
                        sGpRaceResultsState = GP_RESULTS_COMPLETE;
                        break;
                    case GP_RESULTS_END_MENU:
                        gfx = Menus_DrawGpResultsEndMenu(gfx);
                        break;
                    case GP_RESULTS_QUIT:
                        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                            Audio_LevelSEFadeout();
                        }
                        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                            func_8007E0CC();
                        }
                        sMenuIsBusy = true;
                        sMenuStateFlags |= MENU_STATE_QUIT;
                        sGpRaceResultsState = GP_RESULTS_COMPLETE;
                        break;
                    case GP_RESULTS_COMPLETE:
                        break;
                }
            } else if (gGameMode == GAMEMODE_DEATH_RACE) {
                gfx = Menus_DrawDeathRaceResults(gfx);
                gfx = Menus_DrawDeathRaceEndMenu(gfx);
            }
        }

        // CRASHED
        if (!(gRacers[playerIndex].stateFlags & RACER_STATE_FINISHED) &&
            (gRacers[playerIndex].stateFlags & RACER_STATE_CRASHED)) {
            if (sPlayerGameoverState[0] == PLAYER_GAMEOVER_NONE) {
                sPlayerRetireTimer[0] = 0;
                sPlayerRetireRelativeLeftPos[0] = 200.0f;
                sPlayerRetireHorizontalSpeed[0] = -20.0f;
                sPlayerGameoverState[0] = PLAYER_GAMEOVER_CRASHED;
            }
            if ((gGameMode == GAMEMODE_GP_RACE) && (sPlayer1Lives <= 0)) {
                switch (sPlayerGameoverState[0]) {
                    case PLAYER_GAMEOVER_CRASHED:
                        gfx = Menus_DrawPlayerRetire(gfx, 0);
                        if (sPlayerRetireTimer[0] > 500) {
                            sPlayerGameoverState[0] = PLAYER_GAMEOVER_DISPLAY;
                            Menus_InitGameover(0);
                            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
#ifndef EXPANSION_KIT
                                Audio_RomBgmStart(BGM_GAMEOVER);
#else
                                func_8070DAD4(BGM_GAMEOVER);
#endif
                            }
                        }
                        break;
                    case PLAYER_GAMEOVER_DISPLAY:
                        gfx = Menus_DrawGameover(gfx, 0);
                        break;
                }
            } else {
                gfx = Menus_DrawPlayerRetire(gfx, 0);
                if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                    if (gGameMode == GAMEMODE_GP_RACE) {
#if defined(VERSION_US) || defined(VERSION_PAL) || defined(EXPANSION_KIT)
                        if (sPlayerRetireTimer[0] == 400) {
#else
                        if (sPlayerRetireTimer[0] > 400) {
#endif
                            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                                Audio_LevelSEFadeout();
                            }
                            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                                func_8007E0CC();
                            }
                            sMenuIsBusy = true;
                            sMenuStateFlags |= MENU_STATE_RETIRE_RESTART;
                        }
                    } else if (sPlayerRetireTimer[0] > 200) {
                        if (gGameMode != GAMEMODE_DEATH_RACE) {
                            gfx = Menus_DrawRetiredEndMenu(gfx);
                        } else {
                            gfx = Menus_DrawDeathRaceEndMenu(gfx);
                        }
                    }
                }
            }
        }
    } else { // VS MODE
        if (!D_80141D6C) {
            for (i = 0; i < gTotalRacers; i++) {
                racer = &gRacers[i];
                if (i < gNumPlayers) {
                    if (racer->lap == gTotalLapCount) {
                        if ((D_i3_80141EA8[i].lapFlashTimer > 0) && !gGamePaused) {
                            if (((D_i3_80141EA8[i].lapFlashTimer % 20) >= 5) &&
                                (D_i3_80141EA8[i].lapFlashTimer > 120)) {
                                gfx = Menus_DrawPlayerFinalLap(gfx, i);
                            }
                            sPlayerFinalLapTimer[i]++;
                        }
                    }

                    if ((racer->lap == 2) && (gTitleDemoState == TITLE_DEMO_INACTIVE) && !gGamePaused) {
                        if (D_i3_80141EA8[i].lapFlashTimer > 0) {
                            if (((D_i3_80141EA8[i].lapFlashTimer % 20) >= 5) &&
                                (D_i3_80141EA8[i].lapFlashTimer > 120)) {
                                gfx = Menus_DrawPlayerBoosterOk(gfx, i);
                            }
                            sPlayerBoosterOkTimer[i]++;
                        }
                    }
                }

                // FAKE
                if (1) {}

                if (((racer->stateFlags & RACER_STATE_FINISHED) && (i < gNumPlayers)) || (D_800E5FBC == 1)) {
                    gfx = Menus_DrawPlayerWinner(gfx, i);
                }

                if (gPlayerLapNumbers[i] >= gTotalLapCount + 1) {
                    sPlayerShowFinishedTimeTimer[i]++;

                    if (sPlayerShowFinishedTimeTimer[i] > 3000) {
                        sPlayerShowFinishedTimeTimer[i] = 3000;
                    }
                    if (sPlayerShowFinishedTimeTimer[i] > 180) {
                        gfx = Menus_DrawPlayerFinishTime(gfx, i);
                    }
                } else {
                    sPlayerShowFinishedTimeTimer[i] = 0;
                }
                if ((racer->stateFlags & RACER_STATE_FINISHED) && (i < gNumPlayers) &&
                    !(racer->stateFlags & RACER_STATE_CRASHED)) {
                    gfx = Menus_DrawMaxSpeed(gfx, i);
                } else if ((racer->stateFlags & RACER_STATE_CRASHED) && !(racer->stateFlags & RACER_STATE_FINISHED) &&
                           (i < gNumPlayers) && (sPlayerFinishState[i] != PLAYER_FINISH_SUCCESS_COMPLETE)) {
                    if (sPlayerGameoverState[i] == PLAYER_GAMEOVER_NONE) {
                        sPlayerRetireTimer[i] = 0;
                        sPlayerRetireRelativeLeftPos[i] = 200.0f;
                        sPlayerRetireHorizontalSpeed[i] = -20.0f;
                        sPlayerGameoverState[i] = PLAYER_GAMEOVER_CRASHED;
                    }
                    if ((D_800E5FBC != 1) || (racer->position != 1)) {
                        gfx = Menus_DrawPlayerRetire(gfx, i);
                    }
                }
            }
        }
        if ((D_800E5FBC == 1) && (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
            if (sVsResultsTimer > 0) {
                D_80141D6C = true;
                if (D_80141D70 != 0) {
                    gfx = Menus_DrawVsResultsScreen(gfx);
                }
            } else {
                D_80141D6C = false;
                sVsResultsTimer++;
            }
            if ((sVsResultsTimer == 0) && (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
                Audio_LevelSEFadeout();
            }
        } else {
            D_80141D6C = false;
            sVsResultsTimer = -420;
        }
    }
    if ((gSettingVsSlot != 0) && (D_800E5FBC != 1) && (gNumPlayers >= 2)) {
        for (i = 0; i < gNumPlayers; i++) {
            if ((gRacers[i].stateFlags & RACER_STATE_CRASHED) && !(gRacers[i].stateFlags & RACER_STATE_FINISHED)) {
                gfx = Menus_DrawVsSlot(gfx, i);
            }
        }
    }
    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
        if (gGamePaused) {
            if (gGameMode == GAMEMODE_GP_RACE) {
                gfx = Menus_DrawGpRacePause(gfx);
            } else if (gGameMode == GAMEMODE_DEATH_RACE) {
                gfx = Menus_DrawDeathRacePause(gfx);
            } else {
                gfx = Menus_DrawGeneralPause(gfx);
            }
        } else {
            sPauseMenuScissorBoxTimer = 60;
            sPauseMenuOptionIndex = 0;
            for (i = 0; i < gNumPlayers; i++) {
                if ((gControllers[gPlayerControlPorts[i]].buttonPressed & BTN_START) &&
                    (gTitleDemoState == TITLE_DEMO_INACTIVE) && (D_800E5FBC == 0) && (gRaceIntroTimer < 320)) {
                    sMenuStateFlags |= MENU_STATE_PAUSE_GAME;
                    sPausePlayerNum = i;
                    break;
                }
            }
        }
    }
    return gfx;
}
