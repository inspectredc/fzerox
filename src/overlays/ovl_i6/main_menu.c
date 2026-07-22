#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "fzx_font.h"
#include "fzx_cache.h"
#include "src/overlays/ovl_i2/transition.h"
#include "ovl_i6.h"
#include ASSET_HEADER(common_assets_compressed.h)
#include ASSET_HEADER(setup_gfx.h)

#ifndef EXPANSION_KIT
s16 D_i6_8011F910[SCREEN_HEIGHT];
#else
s16* D_i6_8011F910;
#endif

#ifndef EXPANSION_KIT
// UNUSED?
UNUSED unk_8011DC40 D_i6_8011DC40 = { 1.0f, 1.0f, 32, 12, 0, 2, 17, 20 };
#endif

s32 D_i6_8011DC60 = 0;
s32 D_i6_8011DC64 = 0;
s32 D_i6_8011DC68 = 0;
s32 D_i6_8011DC6C = 180;

/*
    MENU OPTIONS
 */

CacheTexInfo sMenuSignGpRaceCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMenuSignGpRaceTex);
CacheTexInfo sMenuSignTimeAttackCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMenuSignTimeAttackTex);
CacheTexInfo sMenuSignVsBattleCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMenuSignVsBattleTex);
CacheTexInfo sMenuSignPracticeCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMenuSignPracticeTex);
CacheTexInfo sMenuSignDeathRaceCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMenuSignDeathRaceTex);
CacheTexInfo sMenuSignOptionsCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMenuSignOptionsTex);
CacheTexInfo sMenuSignCourseEditCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMenuSignCourseEditTex);
CacheTexInfo sMenuSignCreateMachineCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMenuSignCreateMachineTex);

CacheTexInfo* sMenuSignCacheTexInfos[] = {
    sMenuSignGpRaceCacheTexInfo,        // MODE_GP_RACE
    sMenuSignTimeAttackCacheTexInfo,    // MODE_TIME_ATTACK
    sMenuSignDeathRaceCacheTexInfo,     // MODE_DEATH_RACE
    sMenuSignVsBattleCacheTexInfo,      // MODE_VS_BATTLE
    sMenuSignCourseEditCacheTexInfo,    // MODE_COURSE_EDIT
    sMenuSignPracticeCacheTexInfo,      // MODE_PRACTICE
    sMenuSignOptionsCacheTexInfo,       // MODE_OPTIONS
    sMenuSignCreateMachineCacheTexInfo, // MODE_CREATE_MACHINE
};

/*
    LARGE WALLPAPER-STYLE IMAGES/COMIC STYLE IMAGE
 */

static CacheTexInfo sTitleBackgroundMainCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aTitleBackgroundMainTex);
static CacheTexInfo sTitleBackgroundComicCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aTitleBackgroundComicTex);
static CacheTexInfo sTitleBackgroundFalconCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aTitleBackgroundFalconTex);

static CacheTexInfo* sTitleBackgroundCacheTexInfos[] = {
    sTitleBackgroundMainCacheTexInfo,
    sTitleBackgroundComicCacheTexInfo,
    sTitleBackgroundFalconCacheTexInfo,
};

/*
    MENU SECOND OPTIONS
 */

CacheTexInfo sSelectModeCacheTexInfo[] = CACHE_TEX_INFO(TEX_CACHE_FMT_I4, aSelectModeTex, 0);
CacheTexInfo sSelectModeOptionFlamesCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSelectModeOptionFlamesTex);
static CacheTexInfo sNoviceCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aNoviceTex);
static CacheTexInfo sStandardCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aStandardTex);
static CacheTexInfo sExpertCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aExpertTex);
static CacheTexInfo sMasterCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMasterTex);
CacheTexInfo s2PlayersCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, a2PlayersTex);
CacheTexInfo s3PlayersCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, a3PlayersTex);
CacheTexInfo s4PlayersCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, a4PlayersTex);
CacheTexInfo sTimeAttackCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aTimeAttackTex);
CacheTexInfo sRecordsOptionCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aRecordsOptionTex);

static CacheTexInfo* sDifficultyCacheTexInfos[] = {
    sNoviceCacheTexInfo,
    sStandardCacheTexInfo,
    sExpertCacheTexInfo,
    sMasterCacheTexInfo,
};

CacheTexInfo* sNumPlayersCacheTexInfos[] = {
    s2PlayersCacheTexInfo,
    s3PlayersCacheTexInfo,
    s4PlayersCacheTexInfo,
};

CacheTexInfo* sTimeAttackModeCacheTexInfos[] = {
    sTimeAttackCacheTexInfo,
    sRecordsOptionCacheTexInfo,
};

static CacheTexInfo sOkCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aOKTex);

extern u32 gGameFrameCount;
extern s16 D_800CCFE8;
extern s32 gNumPlayers;
extern s32 D_800CD384;
extern f32 D_800CE748;
extern f32 D_800CE74C;
extern f32 D_800CE750;

void MainMenu_Init(void) {
    D_800CCFE8 = 3;
#ifdef EXPANSION_KIT
    D_800CE748 = D_800CE74C = D_800CE750 = 0.1f;
#endif
    D_800CD384 = 0;
    gNumPlayers = 1;
    if ((gGameFrameCount % 4) == 0) {
        Object_Init(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING, 0, 0, 0);
    }
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    if ((gGameFrameCount % 4) == 1) {
        Object_Init(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING, 0, 0, 0);
    }
    Object_Init(OBJECT_MAIN_MENU_BACKGROUND, 0, 0, 4);
    if ((gGameFrameCount % 4) == 2) {
        Object_Init(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING, 0, 0, 0);
    }
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_0, 0, 0, 10);
    if ((gGameFrameCount % 4) == 3) {
        Object_Init(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING, 0, 0, 0);
    }
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_1, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_2, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_3, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_4, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_5, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_6, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_7, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_HEADER, 100, 13, 10);
    Object_Init(OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS, 96, 80, 14);
    Object_Init(OBJECT_MAIN_MENU_OK, 0, 0, 14);
    Object_Init(OBJECT_MAIN_MENU_SELECT_DIFFICULTY, 96, 80, 14);
    Object_Init(OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE, 96, 80, 14);
}

extern s32 gAntiPiracyAddedDifficulty;
extern s32 gModeSubOption[];
extern char* gTrackNames[];

extern s32 gNumPlayers;
extern s32 gDifficulty;
extern s16 gGameModeChangeState;
extern s16 gMenuChangeMode;
extern s32 gSelectedMode;
extern s8 gUnlockableLevel;
extern s8 gSettingEverythingUnlocked;
extern s32 gGameMode;
extern s32 gControllersConnected;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;
extern char* gCurrentTrackName;
extern s32 gCourseIndex;
extern s32 gTransitionState;

const s32 kDefaultSubOptionLimits[] = { 2, 1, 0, 2, 0, 2, 0, 0 };
const s32 kMaxSubOptionLimits[] = { 3, 1, 0, 2, 0, 3, 0, 0 };

s32 MainMenu_Update(void) {
    s32 previous;
    bool var_v1_2;

    if (gTransitionState != TRANSITION_INACTIVE) {
        return gGameMode;
    }

    Controller_SetGlobalInputs(&gSharedController);
    if (OBJECT_STATE(Object_Get(OBJECT_MAIN_MENU_BACKGROUND)) >= 3) {
        return gGameMode;
    }
    switch (D_800CD384) {
        case 0:
            previous = gSelectedMode;
            if (gInputPressed & BTN_RIGHT) {
                if ((gSelectedMode % 4) != 3) {
                    gSelectedMode++;
                }
            }
            if (gInputPressed & BTN_LEFT) {
                if (gSelectedMode % 4) {
                    gSelectedMode--;
                }
            }
            if (gInputPressed & BTN_DOWN) {
                if ((gSelectedMode / 4) == 0) {
                    gSelectedMode += 4;
                }
            }
            if (gInputPressed & BTN_UP) {
                if ((gSelectedMode / 4) != 0) {
                    gSelectedMode -= 4;
                }
            }
#ifndef EXPANSION_KIT
#if BUILD_REVISION >= REVISION_B
            if ((gSelectedMode == MODE_VS_BATTLE) && (gControllersConnected < 2)) {
                gSelectedMode = MODE_DEATH_RACE;
            }
#endif
            switch (gSelectedMode) {
                case MODE_COURSE_EDIT:
                    gSelectedMode = MODE_PRACTICE;
                    break;
                case MODE_CREATE_MACHINE:
                    gSelectedMode = MODE_OPTIONS;
                    break;
            }
#endif
            if (previous != gSelectedMode) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            if (gInputButtonPressed & BTN_B) {
                Audio_TriggerSystemSE(NA_SE_16);
#ifndef EXPANSION_KIT
                func_8007E0CC();
#else
                func_8070DB48();
                Audio_RomBgmReady(BGM_TITLE);
#endif
                D_800CD384 = 5;
                return GAMEMODE_FLX_TITLE;
            }

            if ((gInputButtonPressed & BTN_START) &&
                (OBJECT_STATE(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) == 7)) {
                break;
            }

            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                Audio_TriggerSystemSE(NA_SE_62);
                gAntiPiracyAddedDifficulty =
                    (UNLOCK_EVERYTHING_ROMDATA(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) & 0xFFFF) - 0x997A;
                switch (gSelectedMode) {
                    case MODE_GP_RACE:
                    case MODE_TIME_ATTACK:
                    case MODE_VS_BATTLE:
                    case MODE_PRACTICE:
                        Audio_TriggerSystemSE(NA_SE_33);
                        D_800CD384 = 1;
                        break;
                    case MODE_DEATH_RACE:
                        D_800CD384 = 5;
                        gCourseIndex = COURSE_DEATH_RACE;
                        gCurrentTrackName = gTrackNames[gCourseIndex];
                        gNumPlayers = 1;
                        Audio_SetPlayerMode(gNumPlayers - 1);
                        gDifficulty = gAntiPiracyAddedDifficulty + MASTER;
                        return GAMEMODE_FLX_MACHINE_SELECT;
                    case MODE_OPTIONS:
#ifdef EXPANSION_KIT
                        Audio_RomBgmReady(BGM_OPTION);
#endif
                        D_800CD384 = 5;
                        gMenuChangeMode = MENU_CHANGE_TO_OPTIONS;
                        break;
                    case MODE_COURSE_EDIT:
                        D_800CD384 = 5;
#ifdef EXPANSION_KIT
                        Audio_EditorInit();
                        func_80704810(false);
                        func_8070481C();
#endif
                        return GAMEMODE_COURSE_EDIT;
                    case MODE_CREATE_MACHINE:
                        D_800CD384 = 5;
#ifdef EXPANSION_KIT
                        Audio_Editor2Init();
                        func_80704810(false);
                        func_8070481C();
#endif
                        return GAMEMODE_CREATE_MACHINE;
                    default:
                        D_800CD384 = 2;
                        break;
                }
            }
            break;
        case 1:
            previous = gModeSubOption[gSelectedMode];
            if (gInputPressed & BTN_DOWN) {
                gModeSubOption[gSelectedMode]++;
            }
            if ((gUnlockableLevel < 2) && !gSettingEverythingUnlocked) {
                if (kDefaultSubOptionLimits[gSelectedMode] < gModeSubOption[gSelectedMode]) {
                    gModeSubOption[gSelectedMode] = kDefaultSubOptionLimits[gSelectedMode];
                }
            } else {
                if (kMaxSubOptionLimits[gSelectedMode] < gModeSubOption[gSelectedMode]) {
                    gModeSubOption[gSelectedMode] = kMaxSubOptionLimits[gSelectedMode];
                }
            }
#if LANGUAGE == LANGUAGE_ENG
            if (gSelectedMode == MODE_VS_BATTLE && (gControllersConnected < gModeSubOption[gSelectedMode] + 2)) {
                gModeSubOption[gSelectedMode] = gControllersConnected - 2;
                if (gModeSubOption[gSelectedMode] < 0) {
                    gModeSubOption[gSelectedMode] = 0;
                    D_800CD384 = 0;
                    Audio_TriggerSystemSE(NA_SE_16);
                    break;
                }
            }
#endif

            if (gInputPressed & BTN_UP) {
                if (gModeSubOption[gSelectedMode] > 0) {
                    gModeSubOption[gSelectedMode]--;
                }
            }
            if (previous != gModeSubOption[gSelectedMode]) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            if (gInputButtonPressed & BTN_B) {
                D_800CD384 = 0;
                Audio_TriggerSystemSE(NA_SE_16);
            } else if ((gInputButtonPressed & BTN_START) &&
                       (OBJECT_STATE(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) == 7)) {
                break;
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                Audio_TriggerSystemSE(NA_SE_33);
                D_800CD384 = 2;
                switch (gSelectedMode) {
                    case MODE_VS_BATTLE:
                        gNumPlayers = gModeSubOption[MODE_VS_BATTLE] + 2;
                        break;
                    case MODE_TIME_ATTACK:
                        if (gModeSubOption[MODE_TIME_ATTACK] != 0) {
                            D_800CD384 = 6;
                            gMenuChangeMode = MENU_CHANGE_TO_RECORDS;
                            Audio_TriggerSystemSE(NA_SE_62);
#ifdef EXPANSION_KIT
                            Audio_RomBgmReady(BGM_OPTION);
#endif
                        } else {
                            gNumPlayers = 1;
                        }
                        break;
                    case MODE_GP_RACE:
                    case MODE_PRACTICE:
                        gNumPlayers = 1;
                        gDifficulty = gAntiPiracyAddedDifficulty + gModeSubOption[gSelectedMode];
                        break;
                }
            }
            break;
        case 2:
            Math_Rand1();
            if (gInputButtonPressed & BTN_B) {
                Audio_TriggerSystemSE(NA_SE_16);
                switch (gSelectedMode) {
                    case MODE_GP_RACE:
                    case MODE_TIME_ATTACK:
                    case MODE_VS_BATTLE:
                    case MODE_PRACTICE:
                        D_800CD384 = 1;
                        break;
                    default:
                        D_800CD384 = 0;
                        break;
                }
                break;
            }
            if ((gInputButtonPressed & BTN_START) &&
                (OBJECT_STATE(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) == 7)) {
                break;
            }
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                Audio_TriggerSystemSE(NA_SE_62);
                Audio_SetPlayerMode(gNumPlayers - 1);
                switch (gSelectedMode) {
                    case MODE_GP_RACE:
                    case MODE_TIME_ATTACK:
                    case MODE_VS_BATTLE:
                    case MODE_PRACTICE:
                        func_8008B1CC();
                        D_800CD384 = 3;
                        break;
                    default:
                        return GAMEMODE_FLX_TITLE;
                }
            }
            break;
        case 3:
            if (OBJECT_COUNTER(Object_Get(OBJECT_MAIN_MENU_MODE_SIGN_3)) == 12) {
                var_v1_2 = false;
                switch (gSelectedMode) {
                    case MODE_TIME_ATTACK:
                        if (OBJECT_COUNTER(Object_Get(OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE)) == 12) {
                            var_v1_2 = true;
                        }
                        break;
                    case MODE_GP_RACE:
                    case MODE_PRACTICE:
                        if (OBJECT_COUNTER(Object_Get(OBJECT_MAIN_MENU_SELECT_DIFFICULTY)) == 12) {
                            var_v1_2 = true;
                        }
                        break;
                    case MODE_VS_BATTLE:
                        if (OBJECT_COUNTER(Object_Get(OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS)) == 12) {
                            var_v1_2 = true;
                        }
                        break;
                }
                if (var_v1_2) {
                    D_800CD384 = 4;
                }
            }
            if (gInputButtonPressed & BTN_B) {
                Audio_TriggerSystemSE(NA_SE_16);
                switch (gSelectedMode) {
                    case MODE_GP_RACE:
                    case MODE_TIME_ATTACK:
                    case MODE_VS_BATTLE:
                    case MODE_PRACTICE:
                        D_800CD384 = 1;
                        break;
                }
            }
            break;
        case 4:
            if (gGameModeChangeState == GAMEMODE_UPDATE) {
                gMenuChangeMode = MENU_CHANGE_TO_COURSE_SELECT;
            }
            break;
        default:
            break;
    }
    return GAMEMODE_FLX_MAIN_MENU;
}

Gfx* MainMenu_Draw(Gfx* gfx) {
    return Object_UpdateAndDrawAll(gfx);
}

extern s8 D_800CD3C4;

void MainMenu_BackgroundInit(Object* backgroundObj) {
    s32 i;

#ifdef EXPANSION_KIT
#ifdef AVOID_UB
    D_i6_8011F910 = Arena_Allocate(ALLOC_FRONT, SCREEN_HEIGHT * sizeof(s16));
#else
    //! @bug This only allocates half the size needed
    D_i6_8011F910 = Arena_Allocate(ALLOC_FRONT, SCREEN_HEIGHT * sizeof(s16) / 2);
#endif
#endif

    OBJECT_STATE(backgroundObj) = D_800CD3C4;
    TextureCache_LoadCacheTexInfoList_impl(sTitleBackgroundCacheTexInfos[OBJECT_STATE(backgroundObj)], false, true);

    switch (OBJECT_STATE(backgroundObj)) {
        case 0:
            OBJECT_LEFT(backgroundObj) = 8;
            /* fallthrough */
        case 1:
            for (i = 0; i < SCREEN_HEIGHT; i++) {
                D_i6_8011F910[i] = 0;
            }

            TextureCache_LoadCacheTexInfoList_impl(sTitleBackgroundCacheTexInfos[2], false, true);
            break;
    }
}

void MainMenu_SignInit(Object* signObj) {
    s32 index = signObj->cmdId - OBJECT_MAIN_MENU_MODE_SIGN_0;

    TextureCache_LoadCacheTexInfoList_impl(sMenuSignCacheTexInfos[index], false, true);
    if (gGameModeChangeState == GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_INIT)) {
        OBJECT_COUNTER(signObj) = 12;
    }
}

void MainMenu_HeaderInit(Object* headerObj) {

    TextureCache_LoadCacheTexInfoList_impl(sSelectModeCacheTexInfo, false, true);
    if (gGameModeChangeState == GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_INIT)) {
        OBJECT_COUNTER(headerObj) = 12;
    }
}

void MainMenu_NumPlayersInit(void) {
    s32 i;

    TextureCache_LoadCacheTexInfoList_impl(sSelectModeOptionFlamesCacheTexInfo, false, true);

    for (i = 0; i < 3; i++) {
        TextureCache_LoadCacheTexInfoList_impl(sNumPlayersCacheTexInfos[i], false, true);
    }
}

void MainMenu_DifficultyInit(void) {
    s32 i;

    TextureCache_LoadCacheTexInfoList_impl(sSelectModeOptionFlamesCacheTexInfo, false, true);

    for (i = 0; i < 4; i++) {
        TextureCache_LoadCacheTexInfoList_impl(sDifficultyCacheTexInfos[i], false, true);
    }
}

void MainMenu_TimeAttackModeInit(void) {
    s32 i;

    TextureCache_LoadCacheTexInfoList_impl(sSelectModeOptionFlamesCacheTexInfo, false, true);

    for (i = 0; i < 2; i++) {
        TextureCache_LoadCacheTexInfoList_impl(sTimeAttackModeCacheTexInfos[i], false, true);
    }
}

void MainMenu_OkInit(Object* okObj) {
    TextureCache_LoadCacheTexInfoList_impl(sOkCacheTexInfo, false, true);
    OBJECT_LEFT(okObj) = 50;
}

s32 func_i6_8011DBD0(void);

void MainMenu_UnlockEverythingInit(Object* unlockEverythingObj) {
    UNLOCK_EVERYTHING_ROMDATA(unlockEverythingObj) = func_i6_8011DBD0();
}

extern u32 gGameFrameCount;
extern s32 gSelectedMode;

#if LANGUAGE == LANGUAGE_JPN
const char* D_i6_8011D850[] = {
    "グランプリ",       // Grand Prix
    "タイムアタック",   // Time Attack
    "デスレース",       // Death Race
    "バーサス",         // Versus
    "コースエディット", // Course Edit
    "プラクティス",     // Practice
    "オプション",       // Options
    "クリエイトマシン", // Create Machine
};
#endif

Gfx* MainMenu_SignDraw(Gfx* gfx, Object* signObj) {
    s32 mode;
    s32 var_v1;
    s32 temp1;
    s32 temp2;

    mode = signObj->cmdId - OBJECT_MAIN_MENU_MODE_SIGN_0;

#ifndef EXPANSION_KIT
    if ((mode == MODE_COURSE_EDIT) || (mode == MODE_CREATE_MACHINE)) {
        return gfx;
    }
#endif

    if (mode == gSelectedMode) {
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

    switch (D_800CD384) {
        case 3:
        case 4:
            if (++OBJECT_COUNTER(signObj) > 12) {
                OBJECT_COUNTER(signObj) = 12;
            }
            break;
        default:
            if (OBJECT_COUNTER(signObj) > 0) {
                OBJECT_COUNTER(signObj)--;
            }
            break;
    }

    if (OBJECT_COUNTER(signObj) < 0) {
        OBJECT_COUNTER(signObj) = 0;
    }

    temp1 = (((mode % 4) * 0x40) - (SQ(OBJECT_COUNTER(signObj)) * 2)) + 0x20;
    temp2 = ((mode / 4) * 0x5B) + 0x26;

    gfx = TextureCache_DrawList_impl(gfx, sMenuSignCacheTexInfos[mode], temp1, temp2, TEXTURE_CACHE_DRAW_TINTED, false,
                                     false, 1.0f, 1.0f, true);

#if LANGUAGE == LANGUAGE_JPN
    if (mode == gSelectedMode) {
        gfx = Font_DrawString(gfx, (temp1 - (Font_GetStringWidth(D_i6_8011D850[mode], FONT_SET_4, 0) / 2)) + 0x20,
                              temp2 + 0x5B, D_i6_8011D850[mode], 0, FONT_SET_4, 0);
    }
#endif

    return gfx;
}

extern s8 D_800CD3C4;

Gfx* MainMenu_BackgroundDraw(Gfx* gfx, Object* backgroundObj) {
    s32 j;
    s32 i;
    s32 var_t1;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 alpha;
    TexturePtr texture;
    CacheTexInfo* sp44;
    CacheTexInfo* var_ra;

    if (OBJECT_STATE(backgroundObj) < 3) {
        sp44 = sTitleBackgroundCacheTexInfos[OBJECT_STATE(backgroundObj)];
        gfx = TextureCache_DrawList_impl(gfx, sp44, OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj),
                                         TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
        gfx = TextureUtils_DrawRectangleClipped(
            gfx, OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj), OBJECT_LEFT(backgroundObj) + sp44->width,
            OBJECT_TOP(backgroundObj) + sp44->height, D_i6_8011DC60, D_i6_8011DC64, D_i6_8011DC68, D_i6_8011DC6C);
    } else {
        sp44 = sTitleBackgroundCacheTexInfos[D_800CD3C4];
        gfx = TextureCache_DrawList_impl(gfx, sp44, OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj),
                                         TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
        var_t1 = (OBJECT_STATE(backgroundObj) / 10);
        var_ra = sTitleBackgroundCacheTexInfos[var_t1 - 1];

        texture = TextureCache_GetCached(var_ra->segAddr);

        sp58 = OBJECT_LEFT(backgroundObj);
        sp54 = OBJECT_TOP(backgroundObj);
        gSPDisplayList(gfx++, D_3000088);

        switch (OBJECT_STATE(backgroundObj)) {
            case 10:
            case 20:
                OBJECT_COUNTER(backgroundObj) += 4;
                break;
            case 11:
            case 21:
                alpha = 0;

                OBJECT_COUNTER(backgroundObj)++;

                i = 0;
                while (i <= 100) {
                    j = Math_Rand1() % SCREEN_HEIGHT;
                    if (D_i6_8011F910[j] == 0) {
                        D_i6_8011F910[j] = 1;
                        alpha++;
                    }

                    if (alpha >= 4) {
                        goto label;
                    }
                    i++;
                }

                for (j = 0; j < SCREEN_HEIGHT; j++) {
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
                OBJECT_COUNTER(backgroundObj) += 4;
                break;
        }

        for (var_t1 = 0; var_t1 < SCREEN_HEIGHT; var_t1++) {

            switch (OBJECT_STATE(backgroundObj)) {
                case 10:
                case 20:
                    if (var_t1 < OBJECT_COUNTER(backgroundObj)) {
                        // alpha variable re-used with different purpose here
                        alpha = SQ(OBJECT_COUNTER(backgroundObj) - var_t1) / 32;
                        if (alpha > SCREEN_WIDTH) {
                            alpha = SCREEN_WIDTH;
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
                    i = ((((var_t1 * 0x1000) * (OBJECT_COUNTER(backgroundObj) + 64)) / 64) / 240);
                    sp50 = (SIN(i) * OBJECT_COUNTER(backgroundObj));
                    alpha = 255 - OBJECT_COUNTER(backgroundObj);
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

        gfx = TextureUtils_DrawRectangleClipped(
            gfx, OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj), OBJECT_LEFT(backgroundObj) + sp44->width,
            OBJECT_TOP(backgroundObj) + sp44->height, D_i6_8011DC60, D_i6_8011DC64, D_i6_8011DC68, D_i6_8011DC6C);
        switch (OBJECT_STATE(backgroundObj)) {
            case 10:
            case 20:
                if (D_i6_8011F910[SCREEN_HEIGHT - 1] >= SCREEN_WIDTH) {
                    OBJECT_STATE(backgroundObj) = D_800CD3C4;
                }
                break;
            case 11:
            case 21:
                if (OBJECT_COUNTER(backgroundObj) > 80) {
                    OBJECT_STATE(backgroundObj) = D_800CD3C4;
                }
                break;
            case 12:
            case 22:
                if (OBJECT_COUNTER(backgroundObj) > 256) {
                    OBJECT_STATE(backgroundObj) = D_800CD3C4;
                }
                break;
        }
    }
    return gfx;
}

Gfx* MainMenu_HeaderDraw(Gfx* gfx, Object* headerObj) {
    s32 temp;

    switch (D_800CD384) {
        case 3:
        case 4:
            if (++OBJECT_COUNTER(headerObj) > 12) {
                OBJECT_COUNTER(headerObj) = 12;
            }
            break;
        default:
            if (OBJECT_COUNTER(headerObj) > 0) {
                OBJECT_COUNTER(headerObj)--;
            }
            break;
    }

    if (OBJECT_COUNTER(headerObj) < 0) {
        OBJECT_COUNTER(headerObj) = 0;
    }

    temp = SQ(OBJECT_COUNTER(headerObj)) * 2;

    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    return TextureCache_DrawList_impl(gfx, sSelectModeCacheTexInfo, OBJECT_LEFT(headerObj) - temp,
                                      OBJECT_TOP(headerObj), TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
}

Gfx* MainMenu_NumPlayersDraw(Gfx* gfx, Object* numPlayersObj) {
    s32 i;
    s32 temp_s7;

    if (gSelectedMode != MODE_VS_BATTLE) {
        return gfx;
    }

    switch (D_800CD384) {
        case 0:
        case 5:
        case 6:
            OBJECT_COUNTER(numPlayersObj) = -12;
            break;
        case 3:
        case 4:
            if (++OBJECT_COUNTER(numPlayersObj) > 12) {
                OBJECT_COUNTER(numPlayersObj) = 12;
            }
            break;
        default:
            if (OBJECT_COUNTER(numPlayersObj) > 0) {
                OBJECT_COUNTER(numPlayersObj)--;
            }
            if (OBJECT_COUNTER(numPlayersObj) < 0) {
                OBJECT_COUNTER(numPlayersObj)++;
            }
            break;
    }
    temp_s7 = SQ(OBJECT_COUNTER(numPlayersObj)) * 2;
    gfx = TextureCache_DrawList_impl(gfx, sSelectModeOptionFlamesCacheTexInfo, OBJECT_LEFT(numPlayersObj) - temp_s7,
                                     OBJECT_TOP(numPlayersObj), TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);

    for (i = 0; i < 3; i++) {
        if (gModeSubOption[gSelectedMode] == i) {
            switch (D_800CD384) {
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
#if LANGUAGE == LANGUAGE_JPN
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
#else // LANGUAGE_ENG
            if ((gControllersConnected - 2) < i) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 128);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
#endif
        }
        gfx = TextureCache_DrawList_impl(
            gfx, sNumPlayersCacheTexInfos[i], (OBJECT_LEFT(numPlayersObj) - temp_s7) + 0x20,
            OBJECT_TOP(numPlayersObj) + (i * 20) + 0xC, TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
    }

    if (D_800CD384 != 2) {
        gfx = func_8007DB28(gfx, 0);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }

    return gfx;
}

Gfx* MainMenu_DifficultyDraw(Gfx* gfx, Object* difficultyObj) {
    s32 i;
    s32 temp_s6;

    if (gSelectedMode != MODE_PRACTICE && gSelectedMode != MODE_GP_RACE) {
        return gfx;
    }

    switch (D_800CD384) {
        case 0:
        case 5:
        case 6:
            OBJECT_COUNTER(difficultyObj) = -12;
            break;
        case 3:
        case 4:
            if (++OBJECT_COUNTER(difficultyObj) > 12) {
                OBJECT_COUNTER(difficultyObj) = 12;
            }
            break;
        default:
            if (OBJECT_COUNTER(difficultyObj) > 0) {
                OBJECT_COUNTER(difficultyObj)--;
            }
            if (OBJECT_COUNTER(difficultyObj) < 0) {
                OBJECT_COUNTER(difficultyObj)++;
            }
            break;
    }

    temp_s6 = SQ(OBJECT_COUNTER(difficultyObj)) * 2;
    gfx = TextureCache_DrawList_impl(gfx, sSelectModeOptionFlamesCacheTexInfo, OBJECT_LEFT(difficultyObj) - temp_s6,
                                     OBJECT_TOP(difficultyObj), TEXTURE_CACHE_DRAW, 0, 0, 1.0f, 1.0f, true);

    for (i = 0; i < 4; i++) {
        if (gModeSubOption[gSelectedMode] == i) {
            switch (D_800CD384) {
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
        if ((gUnlockableLevel < 2) && !gSettingEverythingUnlocked) {
            if (i < 3) {
#if LANGUAGE == LANGUAGE_JPN
                gfx = TextureCache_DrawList_impl(gfx, sDifficultyCacheTexInfos[i],
                                                 (OBJECT_LEFT(difficultyObj) - temp_s6) + 0x20,
                                                 OBJECT_TOP(difficultyObj) + (i * 20) + 0xC, TEXTURE_CACHE_DRAW_TINTED,
                                                 false, false, 1.0f, 1.0f, true);
#else // LANGUAGE_ENG
                gfx = TextureCache_DrawList_impl(gfx, sDifficultyCacheTexInfos[i],
                                                 (OBJECT_LEFT(difficultyObj) - temp_s6) + 0x20,
                                                 OBJECT_TOP(difficultyObj) + (i * 20) + 0xE, TEXTURE_CACHE_DRAW_TINTED,
                                                 false, false, 1.0f, 1.0f, true);
#endif
            }
        } else {
#if LANGUAGE == LANGUAGE_JPN
            gfx = TextureCache_DrawList_impl(
                gfx, sDifficultyCacheTexInfos[i], (OBJECT_LEFT(difficultyObj) - temp_s6) + 0x20,
                OBJECT_TOP(difficultyObj) + (i * 18) + 5, TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
#else // LANGUAGE_ENG
            gfx = TextureCache_DrawList_impl(
                gfx, sDifficultyCacheTexInfos[i], (OBJECT_LEFT(difficultyObj) - temp_s6) + 0x20,
                OBJECT_TOP(difficultyObj) + (i * 18) + 7, TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
#endif
        }
    }

    return gfx;
}

Gfx* MainMenu_TimeAttackModeDraw(Gfx* gfx, Object* timeAttackModeObj) {
    s32 i;
    s32 temp_s7;
    CacheTexInfo* temp_a1;

    if (gSelectedMode != MODE_TIME_ATTACK) {
        return gfx;
    }
    switch (D_800CD384) {
        case 0:
        case 5:
            OBJECT_COUNTER(timeAttackModeObj) = -12;
            break;
        case 3:
        case 4:
            if (++OBJECT_COUNTER(timeAttackModeObj) > 12) {
                OBJECT_COUNTER(timeAttackModeObj) = 12;
            }
            break;
        case 6:
        default:
            if (OBJECT_COUNTER(timeAttackModeObj) > 0) {
                OBJECT_COUNTER(timeAttackModeObj)--;
            }
            if (OBJECT_COUNTER(timeAttackModeObj) < 0) {
                OBJECT_COUNTER(timeAttackModeObj)++;
            }
            break;
    }

    temp_s7 = SQ(OBJECT_COUNTER(timeAttackModeObj)) * 2;
    gfx = TextureCache_DrawList_impl(gfx, sSelectModeOptionFlamesCacheTexInfo, OBJECT_LEFT(timeAttackModeObj) - temp_s7,
                                     OBJECT_TOP(timeAttackModeObj), TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);

    for (i = 0; i < 2; i++) {
        if (gModeSubOption[MODE_TIME_ATTACK] == i) {
            switch (D_800CD384) {
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
        temp_a1 = sTimeAttackModeCacheTexInfos[i];
#if LANGUAGE == LANGUAGE_JPN
        gfx = TextureCache_DrawList_impl(
            gfx, temp_a1, (((s32) (0x80 - temp_a1->width) / 2) + OBJECT_LEFT(timeAttackModeObj)) - temp_s7,
            OBJECT_TOP(timeAttackModeObj) + (i * 28) + 0x11, TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
#else // LANGUAGE_ENG
        gfx = TextureCache_DrawList_impl(
            gfx, temp_a1, (((s32) (0x80 - temp_a1->width) / 2) + OBJECT_LEFT(timeAttackModeObj)) - temp_s7,
            OBJECT_TOP(timeAttackModeObj) + (i * 28) + 0x15, TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
#endif
    }

    return gfx;
}

Gfx* MainMenu_OkDraw(Gfx* gfx, Object* okObj) {

    switch (D_800CD384) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
            gfx = func_8007DB28(gfx, 1);
            gfx = TextureCache_DrawList_impl(gfx, sOkCacheTexInfo, OBJECT_LEFT(okObj) + 0x10B, OBJECT_TOP(okObj) + 0xD0,
                                             TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
            break;
        default:
            gfx = func_8007DB28(gfx, 0);
            gfx = TextureCache_DrawList_impl(gfx, sOkCacheTexInfo, OBJECT_LEFT(okObj) + 0x10B, OBJECT_TOP(okObj) + 0xD0,
                                             TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
            break;
    }
    return gfx;
}

void MainMenu_OkUpdate(Object* okObj) {

    switch (D_800CD384) {
        case 2:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 0, 192);
            OBJECT_COUNTER(okObj) = 9;
            break;
        case 3:
        case 4:
            if (OBJECT_COUNTER(okObj) != 0) {
                OBJECT_COUNTER(okObj)--;
                Object_LerpPosXToClampedTargetMaxStep(okObj, 0, 192);
            } else {
                Object_LerpPosXToTarget(okObj, 50, 4);
            }
            break;
        default:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 50, 192);
            break;
    }
}

const u16 gUnlockEverythingInputs[] = { BTN_L, BTN_Z, BTN_R, BTN_CUP, BTN_CDOWN, BTN_CLEFT, BTN_CRIGHT, BTN_START };

void MainMenu_UnlockEverythingUpdate(Object* unlockEverythingObj) {
    Object* backgroundObj;

    if ((OBJECT_STATE(unlockEverythingObj) < 8) && (gInputButtonPressed != 0)) {
        if (gUnlockEverythingInputs[OBJECT_STATE(unlockEverythingObj)] & gInputPressed) {
            if (++OBJECT_STATE(unlockEverythingObj) == 8) {
                gSettingEverythingUnlocked = true;
                Save_SaveSettingsProfiles();
                Audio_TriggerSystemSE(NA_SE_46);
                backgroundObj = Object_Get(OBJECT_MAIN_MENU_BACKGROUND);
                if (OBJECT_STATE(backgroundObj) < 2) {
                    OBJECT_STATE(backgroundObj) = (Math_Rand1() % 3) + (OBJECT_STATE(backgroundObj) * 10) + 10;
                }
            }
        } else {
            if (gUnlockEverythingInputs[0] & gInputButtonPressed) {
                OBJECT_STATE(unlockEverythingObj) = 1;
            } else {
                OBJECT_STATE(unlockEverythingObj) = 0;
            }
        }
    }
}
