#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "fzx_camera.h"
#include "fzx_font.h"
#include "fzx_save.h"
#include "fzx_cache.h"
#include "src/overlays/ovl_i2/transition.h"
#include "course_select.h"
#include ASSET_HEADER(common_assets_compressed.h)

s32 sCourseSelectCup;
s32 sLastCourseIndex;
#ifdef EXPANSION_KIT
s8 D_i5_8007C2A8[7];
s8 D_i5_8007C2AF;

UNUSED s32 D_i5_8007B080 = 0;
#include ASSET_SOURCE_EK(overlays/course_select/course_select/course_select.c)
#endif

s32 sCourseSelectState = COURSE_SELECT_CUP_SELECT;
UNUSED s32 D_i5_801190C4 = 0;
s8 gCupSelectOption = 0;
s8 sCourseSelectTrackNo = 0;
s8 D_i5_801190D0 = 0;
s8 sSelectedGhostOption = 0;
s8 sUnlockedGhosts = 1;
s8 sStaffGhostTimeBeaten = 0;
#ifdef EXPANSION_KIT
s8 D_i5_8007B9EC[42] = { 0 };
#endif
UNUSED s32 D_i5_801190E0 = 64;
UNUSED s32 D_i5_801190E4 = 0;
UNUSED s32 D_i5_801190E8 = 60;
UNUSED s32 D_i5_801190EC = 40;
UNUSED s32 D_i5_801190F0 = 70;

CacheTexInfo sCupSelectJackCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aCupSelectJackTex);
CacheTexInfo sCupSelectQueenCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aCupSelectQueenTex);
CacheTexInfo sCupSelectKingCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aCupSelectKingTex);
CacheTexInfo sCupSelectJokerCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aCupSelectJokerTex);
CacheTexInfo sCupSelectXCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aCupSelectXTex);
CacheTexInfo sCupSelectEditCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aCupSelectEditTex);
#ifdef EXPANSION_KIT
CacheTexInfo sCupSelectDD1CacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aCupSelectDD1Tex);
CacheTexInfo sCupSelectDD2CacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aCupSelectDD2Tex);
#endif
CacheTexInfo sCupSelectQuestionMarkCacheTexInfo[] =
    CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aCupSelectQuestionMarkTex);

CacheTexInfo* sCupSelectCacheTexInfos[] = {
    sCupSelectJackCacheTexInfo,         sCupSelectQueenCacheTexInfo, sCupSelectKingCacheTexInfo,
    sCupSelectJokerCacheTexInfo,        sCupSelectXCacheTexInfo,     sCupSelectEditCacheTexInfo,
#ifdef EXPANSION_KIT
    sCupSelectDD1CacheTexInfo,          sCupSelectDD2CacheTexInfo,
#endif
    sCupSelectQuestionMarkCacheTexInfo,
};

CacheTexInfo sSelectCourseCacheTexInfo[] = CACHE_TEX_INFO(TEX_CACHE_FMT_I4, aSelectCourseTex, 0);
CacheTexInfo sRecordsCacheTexInfo[] = CACHE_TEX_INFO(TEX_CACHE_FMT_I4, aRecordsTex, 0);
static CacheTexInfo sOKCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aOKTex);
CacheTexInfo sYellowArrowCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aYellowArrowTex);
CacheTexInfo sOptionsFalconHelmetCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aOptionsFalconHelmetTex);

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

CacheTexInfo sCupCleared1CacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aCupCleared1Tex);
CacheTexInfo sCupCleared2CacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aCupCleared2Tex);
CacheTexInfo sCupCleared3CacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aCupCleared3Tex);
CacheTexInfo sCupCleared4CacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aCupCleared4Tex);

CacheTexInfo* sCupClearedDifficultyCacheTexInfos[] = {
    sCupCleared1CacheTexInfo,
    sCupCleared2CacheTexInfo,
    sCupCleared3CacheTexInfo,
    sCupCleared4CacheTexInfo,
};

CacheTexInfo sHasGhostMarkerCacheTexInfo[] = CACHE_TEX_INFO(TEX_CACHE_FMT_I4, aHasGhostMarkerTex, 0);
CacheTexInfo sStaffGhostBeatenCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aStaffGhostBeatenTex);

CacheTexInfo sMenuWithGhostCacheTexInfo[] = CACHE_TEX_INFO(TEX_CACHE_FMT_I4, aMenuWithGhostTex, 0);
CacheTexInfo sMenuWithoutGhostCacheTexInfo[] = CACHE_TEX_INFO(TEX_CACHE_FMT_I4, aMenuWithoutGhostTex, 0);
CacheTexInfo sMenuStaffGhostCacheTexInfo[] = CACHE_TEX_INFO(TEX_CACHE_FMT_I4, aMenuStaffGhostTex, 0);
CacheTexInfo sMenuCelebrityGhostCacheTexInfo[] = CACHE_TEX_INFO(TEX_CACHE_FMT_I4, aMenuCelebrityGhostTex, 0);
CacheTexInfo sMenuChampGhostCacheTexInfo[] = CACHE_TEX_INFO(TEX_CACHE_FMT_I4, aMenuChampGhostTex, 0);

CacheTexInfo* sTimeAttackGhostOptionCacheTexInfos[] = {
    sMenuWithGhostCacheTexInfo,      sMenuWithoutGhostCacheTexInfo, sMenuStaffGhostCacheTexInfo,
    sMenuCelebrityGhostCacheTexInfo, sMenuChampGhostCacheTexInfo,
};

// clang-format off
s32 sCourseSelectCupColors[] = {
    192, 64,  64,
    100, 150, 255,
    255, 255, 100,
    0,   255, 0,
    200, 90,  255,
    200, 90,  255,
#ifdef EXPANSION_KIT
    200, 90,  255,
#endif
};
// clang-format on

extern s32 gCourseIndex;
extern s8 gSettingEverythingUnlocked;
extern s8 gUnlockableLevel;

#ifdef EXPANSION_KIT
void func_i5_80077D60(void) {
    s32 var_v0;

    var_v0 = gUnlockableLevel;
    if ((var_v0 >= 3) || gSettingEverythingUnlocked) {
        var_v0 = 2;
    }

    if (var_v0 + 2 < gCupSelectOption) {
        gCupSelectOption = var_v0 + 2;
    }
}

s32 func_i5_80077DAC(s32 cupType) {
    s32 var_v0;

    var_v0 = gUnlockableLevel;

    if ((var_v0 >= 3) || gSettingEverythingUnlocked) {
        var_v0 = 2;
    }
    if (var_v0 < cupType - 2) {
        cupType = 6;
    }
    return cupType;
}
#endif

void CourseSelect_UpdateUnlockedGhosts(void) {
    GhostInfo ghostInfo;
    s32 staffTime;
    s32 timeRecord;

#ifdef EXPANSION_KIT
    // TODO: move to appropriate functions
    PRINTF("setup start %d\n");
    PRINTF("setup end cup:%d, crs:%d\n");
    PRINTF("ghost time %d:%d:%d\n");
    PRINTF("GHOET IRU\n");
    PRINTF("GHOET INAI\n");
    PRINTF("GHOET INAI2\n");
    PRINTF("setup end %d\n");
    PRINTF("");
#endif

#ifdef EXPANSION_KIT
    if (sLastCourseIndex < -1) {
        sLastCourseIndex++;
        return;
    }
#endif

    if (sLastCourseIndex != gCourseIndex) {
        sStaffGhostTimeBeaten = false;
#ifndef EXPANSION_KIT
        if (Save_LoadStaffGhostRecord(&ghostInfo, gCourseIndex) != 0) {
#else
        ghostInfo.raceTime = Save_GetDDStaffGhostRecordTime(gCourseIndex);
        if (ghostInfo.raceTime == -1) {
#endif
            sUnlockedGhosts = 1;
        } else {
            // Within 115% of staff ghost time
            timeRecord = gCourseInfos[gCourseIndex].timeRecord[0];
            if (timeRecord < ((ghostInfo.raceTime * 115) / 100)) {
                sUnlockedGhosts = 2;
            } else {
                sUnlockedGhosts = 1;
            }
            if (timeRecord < ghostInfo.raceTime) {
                sStaffGhostTimeBeaten = true;
            }
        }
        sLastCourseIndex = gCourseIndex;
    }
}

#ifdef VERSION_JP
const char* sTrackSubtitles[] = {
    "エイトロード",
    "ハイスピード",
    "パイプ",
    "スクリュー",
    "シリンダー",
    "ハイジャンプ",
    "ロールオーバー",
    "ジャンプジャンプ",
    "アップダウン",
    "テクニカル",
    "クイックターン",
    "ステップアップロード",
    "ジグザグジャンプ",
    "ウェーブロード",
    "ムーンサルト",
    "スリムライン",
    "ハーフパイプ",
    "クランククランク",
    "レインボーロード",
    "ミラーロード",
    "シリンダー&ハイジャンプ",
    "ウェーブパニック",
    "スネークロード",
    "ビッグハンド",
    "",
    "",
    "",
    "",
    "",
    "",
#ifdef EXPANSION_KIT
    "アウトサイドループ",
    "シリンダーループ",
    "ダイビング",
    "ジグザグクランク",
    "エックス",
    "ジャポン",
    "スリムハーフパイプ",
    "ストレートジャンプ",
    "トラップロード",
    "180ローリング",
    "スター",
    "ビッグフット",
    "",
    "",
    "",
    "",
    "",
    "",
#endif
    "",
};
#else
const char* sTrackSubtitles[] = {
    "FIGURE EIGHT",
    "HIGH SPEED",
    "PIPE",
    "CORKSCREW",
    "CYLINDER",
    "HIGH JUMP",
    "INVERTED LOOP",
    "MULTI JUMP",
    "UP AND DOWN",
    "TECHNIQUE",
    "QUICK TURN",
    "DANGEROUS STEPS",
    "ZIG-ZAG JUMP",
    "WAVY ROAD",
    "DOUBLE SOMERSAULT",
    "SLIM LINE",
    "HALF PIPE",
    "JUMPS OF DOOM",
    "PSYCHEDELIC EXPERIENCE",
    "MIRROR ROAD",
    "CYLINDER & HIGH JUMP",
    "WAVE PANIC",
    "SNAKE ROAD",
    "DEADLY CURVES",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};
#endif

s8 sGhostOptionTypeMap[] = { 1, 0, 2, 3, 4 };

#ifdef EXPANSION_KIT
s8 D_i5_8007BDF0[] = {
    11, 10, 12, 0, 0, 11, 10, 10, 12, 0, 11, 11, 10, 12, 12, 0,  1,  0,
    2,  1,  0,  3, 2, 1,  3,  0,  0,  0, 11, 11, 10, 0,  12, 10, 12,
};
#endif

extern char* gCurrentTrackName;
extern char* gTrackNames[];

void func_i5_80116910(void) {
    gCurrentTrackName = gTrackNames[gCourseIndex];
}

extern s16 D_800CCFE8;
extern s32 gSelectedMode;
extern s32 gLastCourseSelectCourseIndex;
extern s32 gLastRecordsCourseIndex;
extern s32 gCurrentGhostType;
extern s32 gGameMode;
extern s8 D_8079FB28[];

void CourseSelect_Init(void) {
    s32 i;
    s32 j;
    s32 k;
    s8* cupCompletion;
    bool var_a1;
    s32 var_v1;

    D_800CCFE8 = 3;
#ifdef EXPANSION_KIT
    sCourseSelectState = COURSE_SELECT_CUP_SELECT;
#endif
    sSelectedGhostOption = sGhostOptionTypeMap[gCurrentGhostType];
    sLastCourseIndex = -1;

#ifdef EXPANSION_KIT
    for (i = 0; i < 42; i++) {
        D_i5_8007B9EC[i] = 0;
    }

    cupCompletion = Arena_Allocate(ALLOC_FRONT, 4 * 30 * 7);
    Save_UpdateCupSave(cupCompletion);

    for (i = 0; i < 2; i++) {
        var_a1 = false;
        for (j = 3; j >= 0; j--) {
            for (k = 0; k < 30; k++) {
                if (((s8*) cupCompletion)[(j * 30 * 7) + (k * 7) + i + 5] != 0) {
                    var_a1 = true;
                    break;
                }
            }

            if (var_a1) {
                break;
            }
        }

        if (var_a1) {
            D_8079FB28[i] = j + 1;
        } else {
            D_8079FB28[i] = 0;
        }
    }
    D_i5_8007C2AF = -1;
#endif

    if (gGameMode == GAMEMODE_FLX_COURSE_SELECT) {
        k = gLastCourseSelectCourseIndex;
    } else {
        k = gLastRecordsCourseIndex;
    }
    if (k >= COURSE_X_1) {
        gCupSelectOption = 4;
        sCourseSelectTrackNo = 0;
        gCourseIndex = COURSE_X_1;
    } else {
        sCourseSelectTrackNo = k % 6;
        if (k >= COURSE_EDIT_1) {
#ifndef EXPANSION_KIT
            gCupSelectOption = 10;
#else
            gCupSelectOption = (k / 6) + 6;
            if (gCupSelectOption >= 13) {
                gCupSelectOption = 10;
            }
#endif
        } else {
            gCupSelectOption = k / 6;
        }
        gCourseIndex = k;
    }
    CourseSelect_UpdateUnlockedGhosts();
#ifndef EXPANSION_KIT
    var_v1 = gUnlockableLevel;
    if ((var_v1 >= 3) || gSettingEverythingUnlocked) {
        var_v1 = 2;
    }

    if (var_v1 + 2 < gCupSelectOption) {
        gCupSelectOption = var_v1 + 2;
    }
#else
    if (gCupSelectOption < 10) {
        func_i5_80077D60();
    }
#endif
    if ((gCupSelectOption == 4) &&
        ((gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) || (gSelectedMode == MODE_TIME_ATTACK))) {
        gCupSelectOption = 3;
    }
    if (gCupSelectOption >= 10) {
#ifdef EXPANSION_KIT
        if (gCupSelectOption == 10) {
#endif
            sCourseSelectCup = 4;
#ifdef EXPANSION_KIT
        } else {
            sCourseSelectCup = gCupSelectOption - 6;
        }
#endif
    } else if (gCupSelectOption == 4) {
        sCourseSelectCup = NUM_COMPETITIVE_CUPS;
    } else {
        sCourseSelectCup = gCupSelectOption;
    }

    Camera_Init();
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_COURSE_SELECT_BACKGROUND, 0, 0, 2);
    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        i = 80;
        j = 17;
    } else {
        i = 112;
        j = 21;
    }
    Object_Init(OBJECT_COURSE_SELECT_HEADER, i, j, 4);
    Object_Init(OBJECT_COURSE_SELECT_OK, 0, 0, 10);
    Object_Init(OBJECT_COURSE_SELECT_MODEL, 0, 0, 8);
#ifdef EXPANSION_KIT
    Object_Init(OBJECT_COURSE_SELECT_CUP_7, 128, 0, 6);
    Object_Init(OBJECT_COURSE_SELECT_CUP_5, 128, 0, 6);
    Object_Init(OBJECT_COURSE_SELECT_CUP_6, 128, 0, 6);
#endif
    if ((gSettingEverythingUnlocked || (gUnlockableLevel >= 2)) && (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) &&
        (gSelectedMode != MODE_TIME_ATTACK)) {
        Object_Init(OBJECT_COURSE_SELECT_CUP_4, 0, -100, 6);
    }
    if ((gUnlockableLevel >= 1) || gSettingEverythingUnlocked) {
        Object_Init(OBJECT_COURSE_SELECT_CUP_3, 0, -100, 6);
    }
    Object_Init(OBJECT_COURSE_SELECT_CUP_2, 0, -100, 6);
    Object_Init(OBJECT_COURSE_SELECT_CUP_1, 0, -100, 6);
    Object_Init(OBJECT_COURSE_SELECT_CUP_0, 0, -100, 6);
    if (gSelectedMode != MODE_GP_RACE) {
        Object_Init(OBJECT_COURSE_SELECT_ARROWS, 0, 0, 8);
    }
    Object_Init(OBJECT_COURSE_SELECT_NAME, 0, 0, 8);
    switch (gSelectedMode) {
        case MODE_TIME_ATTACK:
            if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
                Object_Init(OBJECT_COURSE_SELECT_GHOST_OPTION, 0, 0, 10);
            }
            /* fallthrough */
        case MODE_DEATH_RACE:
            Object_Init(OBJECT_COURSE_SELECT_GHOST_MARKER, 190, 160, 10);
            break;
    }
}

void NextCourseSelect_Init(void) {
    D_800CCFE8 = 3;
    sCourseSelectState = COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT;
    if (gCourseIndex >= COURSE_X_1) {
        gCupSelectOption = 4;
        sCourseSelectTrackNo = gCourseIndex % 6;
    } else {
        sCourseSelectTrackNo = gCourseIndex % 6;
        if (gCourseIndex >= COURSE_EDIT_1) {
#ifndef EXPANSION_KIT
            gCupSelectOption = 10;
#else
            gCupSelectOption = (gCourseIndex / 6) + 6;
#endif
        } else {
            gCupSelectOption = gCourseIndex / 6;
        }
    }
    func_i5_80116910();
    if (gCupSelectOption >= 10) {
#ifdef EXPANSION_KIT
        if (gCupSelectOption == 10) {
#endif
            sCourseSelectCup = 4;
#ifdef EXPANSION_KIT
        } else {
            sCourseSelectCup = gCupSelectOption - 6;
        }
#endif
    } else if (gCupSelectOption == 4) {
        sCourseSelectCup = NUM_COMPETITIVE_CUPS;
    } else {
        sCourseSelectCup = gCupSelectOption;
    }
    Camera_Init();
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_COURSE_SELECT_BACKGROUND, 0, 0, 2);
    Object_Init(OBJECT_COURSE_SELECT_MODEL, 0, 0, 8);
    if (gCupSelectOption >= 10) {
#ifndef EXPANSION_KIT
        Object_Init(OBJECT_COURSE_SELECT_CUP_5, 0, -100, 6);
#else
        Object_Init(OBJECT_COURSE_SELECT_CUP_5 + gCupSelectOption - 10, 0, -100, 6);
#endif
    } else {
        Object_Init(OBJECT_COURSE_SELECT_CUP_0 + gCupSelectOption, 0, -100, 6);
    }
    Object_Init(OBJECT_COURSE_SELECT_NAME, 0, 0, 8);
}

extern s32 gCupType;
extern s16 gGameModeChangeState;
extern s16 gMenuChangeMode;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;
extern Camera gCameras[];
extern s32 gTransitionState;
extern char gEditCupTrackNames[][9];

s32 CourseSelect_Update(void) {
    s32 originalCupSelectOption;
    bool sp110;
    s32 var_v1;
    s8 originalSelectedGhostOption;
#ifdef EXPANSION_KIT
    s32 i;
    s32 temp_lo;
    s32 j;
    CourseInfo* courseInfo;
    GhostRecord ghostRecords[3];
    bool var_v1_2;
#endif
    s32 unlockedGhost;

#ifdef EXPANSION_KIT
    if (Object_Get(OBJECT_COURSE_SELECT_CUP_5) != NULL) {
        sp110 = true;
    } else {
        sp110 = false;
    }
#endif

    Camera_Update();
    if (gTransitionState != TRANSITION_INACTIVE) {
        return gGameMode;
    }
    if ((gSelectedMode == MODE_TIME_ATTACK) && (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT)) {
        CourseSelect_UpdateUnlockedGhosts();
    }
    Controller_SetGlobalInputs(&gSharedController);
    switch (sCourseSelectState) {
        case COURSE_SELECT_CUP_SELECT:
            D_i5_801190D0 = 1;
            originalCupSelectOption = gCupSelectOption;

#ifdef EXPANSION_KIT
            if (sp110) {
                var_v1 = gUnlockableLevel;
                if ((var_v1 >= 3) || gSettingEverythingUnlocked) {
                    var_v1 = 2;
                }

                if ((var_v1 == 2) &&
                    ((gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) || (gSelectedMode == MODE_TIME_ATTACK))) {
                    var_v1 = 1;
                }

                if (gInputPressed & BTN_DOWN) {
                    if (gCupSelectOption < 10) {
                        if (D_i5_8007C2AF >= 10) {
                            gCupSelectOption = D_i5_8007C2AF;
                        } else {
                            gCupSelectOption = D_i5_8007BDF0[var_v1 * 5 + gCupSelectOption];
                        }
                        D_i5_8007C2AF = originalCupSelectOption;
                    }
                } else if (gInputPressed & BTN_UP) {
                    if (gCupSelectOption >= 10) {
                        if ((D_i5_8007C2AF < 10) && (D_i5_8007C2AF >= 0)) {
                            gCupSelectOption = D_i5_8007C2AF;
                        } else {
                            // FAKE!
                            gCupSelectOption = D_i5_8007BDF0[(var_v1 & 0xFFFFFFFF) * 3 + gCupSelectOption + 6];
                        }
                        D_i5_8007C2AF = originalCupSelectOption;
                    }
                }
            }
#endif

            if (gCupSelectOption < 10) {
                if ((gInputPressed & BTN_LEFT) && (gCupSelectOption > 0)) {
                    gCupSelectOption--;
                }
                if ((gInputPressed & BTN_RIGHT) && (gCupSelectOption < 4)) {
                    gCupSelectOption++;
                }
#ifndef EXPANSION_KIT
                var_v1 = gUnlockableLevel;
                if ((var_v1 >= 3) || gSettingEverythingUnlocked) {
                    var_v1 = 2;
                }

                if (var_v1 + 2 < gCupSelectOption) {
                    gCupSelectOption = var_v1 + 2;
                }
#else
                func_i5_80077D60();
#endif
                if ((gCupSelectOption == 4) &&
                    ((gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) || (gSelectedMode == MODE_TIME_ATTACK))) {
                    gCupSelectOption = 3;
                }
#ifdef EXPANSION_KIT
            } else {
                if (gInputPressed & BTN_LEFT) {
                    gCupSelectOption = D_i5_8007BDF0[gCupSelectOption + 18];
                }
                if (gInputPressed & BTN_RIGHT) {
                    gCupSelectOption = D_i5_8007BDF0[gCupSelectOption + 22];
                }
#endif
            }
            if (gCupSelectOption >= 10) {
#ifdef EXPANSION_KIT
                if (gCupSelectOption == 10) {
#endif
                    sCourseSelectCup = 4;
#ifdef EXPANSION_KIT
                } else {
                    sCourseSelectCup = gCupSelectOption - 6;
                }
#endif
            } else if (gCupSelectOption == 4) {
                sCourseSelectCup = NUM_COMPETITIVE_CUPS;
            } else {
                sCourseSelectCup = gCupSelectOption;
            }
            if (originalCupSelectOption != gCupSelectOption) {
#ifdef EXPANSION_KIT
                if (gInputPressed & (BTN_LEFT | BTN_RIGHT)) {
                    D_i5_8007C2AF = -1;
                }
#endif
                sCourseSelectTrackNo = 0;
                if (sCourseSelectCup < NUM_COMPETITIVE_CUPS) {
                    CourseModel_Init(sCourseSelectCup);
                }
                Audio_TriggerSystemSE(NA_SE_30);
            }
            if (gCupSelectOption < 10) {
                gCupType = gCupSelectOption;
            } else {
#ifndef EXPANSION_KIT
                gCupType = EDIT_CUP;
#else
                gCupType = gCupSelectOption - 5;
#endif
            }
            if (gCupSelectOption >= 10) {
#ifndef EXPANSION_KIT
                gCourseIndex = sCourseSelectTrackNo + COURSE_EDIT_1;
#else
                gCourseIndex = (sCourseSelectCup * 6) + sCourseSelectTrackNo;
#endif
            } else if (gCupSelectOption == 4) {
                gCourseIndex = COURSE_X_1;
            } else {
                gCourseIndex = (gCupSelectOption * 6) + sCourseSelectTrackNo;
            }
            if (gInputButtonPressed & BTN_B) {
                Audio_TriggerSystemSE(NA_SE_16);
                if (gGameMode == GAMEMODE_FLX_COURSE_SELECT) {
                    gLastCourseSelectCourseIndex = gCourseIndex;
                    sCourseSelectState = COURSE_SELECT_START_EXIT;
                } else {
                    gLastRecordsCourseIndex = gCourseIndex;
                    sCourseSelectState = COURSE_SELECT_EXIT_RECORDS;
#ifdef EXPANSION_KIT
                    Audio_RomBgmReady(BGM_SELECT);
#endif
                    gMenuChangeMode = MENU_CHANGE_EXIT_RECORDS;
                }
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                Audio_TriggerSystemSE(NA_SE_33);
                if (gCupSelectOption == 4) {
                    sCourseSelectTrackNo = 0;
                    sCourseSelectState = COURSE_SELECT_AWAIT_OK;
                } else if (gSelectedMode == MODE_GP_RACE) {
                    if (gCupSelectOption >= 10) {
#ifndef EXPANSION_KIT
                        gCourseIndex = COURSE_EDIT_1;
#else
                        gCourseIndex = sCourseSelectCup * 6;
#endif
                    } else {
                        gCourseIndex = gCupSelectOption * 6;
                    }
                    sCourseSelectTrackNo = 0;
                    sCourseSelectState = COURSE_SELECT_AWAIT_OK;
                } else {
                    sCourseSelectState = COURSE_SELECT_CHOOSE_COURSE;
#ifdef EXPANSION_KIT
                    if ((gSelectedMode == MODE_TIME_ATTACK) && (gCupSelectOption < 10)) {
                        temp_lo = gCupSelectOption * 6;

                        if (D_i5_8007C2A8[temp_lo / 6] == 0) {
                            for (i = temp_lo; i < temp_lo + 6; i++) {
                                courseInfo = &gCourseInfos[i];
                                DDSave_LoadCourseGhostRecords(i, ghostRecords);
                                D_i5_8007B9EC[i] = 0;
                                for (j = 0; j < 3; j++) {
                                    if (courseInfo->encodedCourseIndex == 0) {
                                        break;
                                    }
                                    if (courseInfo->encodedCourseIndex == ghostRecords[j].encodedCourseIndex) {
                                        D_i5_8007B9EC[i] |= 1;
                                        break;
                                    }
                                }
                            }
                        }
                        D_i5_8007C2A8[temp_lo / 6] = 1;
                    } else {
                        sLastCourseIndex = -3;
                    }
#endif
                }
                OBJECT_LEFT(Object_Get(OBJECT_COURSE_SELECT_MODEL)) = 400 - (sCourseSelectTrackNo * 0x500);
            }
            break;
        case COURSE_SELECT_CHOOSE_COURSE:
            D_i5_801190D0 = 1;
#ifndef EXPANSION_KIT
            if ((gSelectedMode == MODE_TIME_ATTACK) && (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT)) {
#else

            var_v1_2 = false;
            if ((gSelectedMode == MODE_TIME_ATTACK) && (gCupType == EDIT_CUP) &&
                (gEditCupTrackNames[gCourseIndex - COURSE_EDIT_1][0] == '\0')) {
                var_v1_2 = true;
            }
            if ((gSelectedMode == MODE_TIME_ATTACK) && (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) && !var_v1_2) {
#endif
                unlockedGhost = sUnlockedGhosts;
                originalSelectedGhostOption = sSelectedGhostOption;
                if ((gInputPressed & BTN_UP) && (sSelectedGhostOption > 0)) {
                    sSelectedGhostOption--;
                }
                if ((gInputPressed & BTN_DOWN) && (sSelectedGhostOption < unlockedGhost)) {
                    sSelectedGhostOption++;
                }
                if (originalSelectedGhostOption != sSelectedGhostOption) {
                    Audio_TriggerSystemSE(NA_SE_30);
                }
                if (unlockedGhost < sSelectedGhostOption) {
                    sSelectedGhostOption = 0;
                }
                gCurrentGhostType = sGhostOptionTypeMap[sSelectedGhostOption];
            }

            if ((gInputPressed & BTN_LEFT) && (sCourseSelectTrackNo > 0)) {
                sCourseSelectTrackNo--;
                gCameras[0].state = CAMERA_COURSE_SELECT_DISABLED;
                LEFT_ARROW_ROTATION_CHANGE(Object_Get(OBJECT_COURSE_SELECT_ARROWS)) += 0x200;
                Audio_TriggerSystemSE(NA_SE_30);
            }

            if ((gInputPressed & BTN_RIGHT) && (sCourseSelectTrackNo < 5)) {
                sCourseSelectTrackNo++;
                gCameras[0].state = CAMERA_COURSE_SELECT_DISABLED;
                RIGHT_ARROW_ROTATION_CHANGE(Object_Get(OBJECT_COURSE_SELECT_ARROWS)) += 0x200;
                Audio_TriggerSystemSE(NA_SE_30);
            }
            if (gCupSelectOption >= 10) {
#ifndef EXPANSION_KIT
                gCourseIndex = sCourseSelectTrackNo + COURSE_EDIT_1;
#else
                gCourseIndex = (sCourseSelectCup * 6) + sCourseSelectTrackNo;
#endif
            } else {
                gCourseIndex = (gCupSelectOption * 6) + sCourseSelectTrackNo;
            }
            if (gInputButtonPressed & BTN_B) {
                sCourseSelectState = COURSE_SELECT_CUP_SELECT;
                Audio_TriggerSystemSE(NA_SE_16);
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
#ifdef EXPANSION_KIT
                if ((gSelectedMode == MODE_TIME_ATTACK) && (gCupType == EDIT_CUP) &&
                    (gEditCupTrackNames[gCourseIndex - COURSE_EDIT_1][0] == '\0')) {
                    Audio_TriggerSystemSE(NA_SE_32);
                } else {
#endif
                    Audio_TriggerSystemSE(NA_SE_33);
                    sCourseSelectState = COURSE_SELECT_AWAIT_OK;
                    D_i5_801190D0 = 0;
#ifdef EXPANSION_KIT
                }
#endif
            }
            break;
        case COURSE_SELECT_AWAIT_OK:
            if (gInputButtonPressed & BTN_B) {
                if ((gSelectedMode == MODE_GP_RACE) || (gCupSelectOption == 4)) {
                    sCourseSelectState = COURSE_SELECT_CUP_SELECT;
                } else {
                    sCourseSelectState = COURSE_SELECT_CHOOSE_COURSE;
                }
                Audio_TriggerSystemSE(NA_SE_16);
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                Audio_TriggerSystemSE(NA_SE_62);
                sCourseSelectState = COURSE_SELECT_CONTINUE;
                if (gGameMode == GAMEMODE_FLX_COURSE_SELECT) {
                    gLastCourseSelectCourseIndex = gCourseIndex;
                    return GAMEMODE_FLX_MACHINE_SELECT;
                } else {
                    gLastRecordsCourseIndex = gCourseIndex;
                    return GAMEMODE_RECORDS;
                }
            }
            break;
        case COURSE_SELECT_START_EXIT:
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                Audio_TriggerSystemSE(NA_SE_33);
                sCourseSelectState = COURSE_SELECT_CUP_SELECT;
            }
            break;
        case COURSE_SELECT_EXIT:
            if (gGameModeChangeState == GAMEMODE_UPDATE) {
                gMenuChangeMode = MENU_CHANGE_EXIT_COURSE_SELECT;
            }
            break;
        default:
            break;
    }

    func_i5_80116910();
#ifdef EXPANSION_KIT
    func_8070D220();
#endif
    return gGameMode;
}

s32 NextCourseSelect_Update(void) {
    Camera_Update();
#ifdef EXPANSION_KIT
    if (gTransitionState != TRANSITION_INACTIVE) {
        return gGameMode;
    }
#endif
    Controller_SetGlobalInputs(&gSharedController);
    D_i5_801190D0 = 1;
    switch (sCourseSelectState) {
        case COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT:
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                sCourseSelectState = COURSE_SELECT_NEXT_COURSE_CONTINUE;
                Audio_TriggerSystemSE(NA_SE_62);
                return GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS;
            }
            break;
        case COURSE_SELECT_NEXT_COURSE_CONTINUE:
        default:
            break;
    }
#ifdef EXPANSION_KIT
    func_8070D220();
#endif
    return gGameMode;
}

Gfx* CourseSelect_Draw(Gfx* gfx) {
    return Object_UpdateAndDrawAll(gfx);
}

extern s8 D_800CD3C4;

void CourseSelect_BackgroundInit(Object* backgroundObj) {
    size_t size;
    CacheTexInfo* sp20;

    OBJECT_STATE(backgroundObj) = D_800CD3C4;
    sp20 = sTitleBackgroundCacheTexInfos[OBJECT_STATE(backgroundObj)];
    TextureCache_LoadCacheTexInfoList_impl(sp20, false, true);

    if (OBJECT_STATE(backgroundObj) == 0) {
        OBJECT_LEFT(backgroundObj) = 8;
    }
    if (gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        TextureCache_LoadCacheTexInfoList_impl(sOptionsFalconHelmetCacheTexInfo, false, true);
        if (OBJECT_STATE(backgroundObj) == 0) {
            size = 0x23A00;
        } else {
            size = 0x25800;
        }

        TextureUtils_ConvertToTintedGreyscale(TextureCache_GetCached(sp20->segAddr), size, 135, 135, 255);
    }
}

void CourseSelect_ModelInit(void) {
    s32 i;

    func_i5_80115DF0();
    if (sCourseSelectCup < NUM_COMPETITIVE_CUPS) {
        CourseModel_Init(sCourseSelectCup);
#ifndef EXPANSION_KIT
        D_i5_801190B4 -= 2;

        for (i = 0; i < 6; i++) {
            func_i5_80116678(gCourseModelCupType);
            D_i5_801190B4--;
        }
#endif
    }
}

void CourseSelect_CupInit(Object* cupObj) {
    s32 cupType;
    s32 var_v0;
    s32 i;

    cupType = cupObj->cmdId - OBJECT_COURSE_SELECT_CUP_0;
    if (cupType == JOKER_CUP || cupType == X_CUP) {
#ifndef EXPANSION_KIT
        var_v0 = gUnlockableLevel;
        if ((var_v0 >= 3) || gSettingEverythingUnlocked) {
            var_v0 = 2;
        }
        if (var_v0 < (cupType - 2)) {
            cupType = 6;
        }
#else
        cupType = func_i5_80077DAC(cupType);
#endif
    }

#ifdef EXPANSION_KIT
    if (cupType >= DD_1_CUP) {
        TextureCache_LoadCacheTexInfoListEK(sCupSelectCacheTexInfos[cupType], false);
    } else {
#endif
        TextureCache_LoadCacheTexInfoList_impl(sCupSelectCacheTexInfos[cupType], false, false);
#ifdef EXPANSION_KIT
    }
#endif

    for (i = 0; i < 4; i++) {
        TextureCache_LoadCacheTexInfoList_impl(sCupClearedDifficultyCacheTexInfos[i], false, true);
    }

    if (gGameModeChangeState == GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_INIT)) {
        OBJECT_COUNTER(cupObj) = 12;
    }
    OBJECT_LEFT(cupObj) = 0x80;
    OBJECT_TOP(cupObj) = 0x55;
}

void CourseSelect_HeaderInit(Object* headerObj) {
    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        TextureCache_LoadCacheTexInfoList_impl(sSelectCourseCacheTexInfo, false, true);
        OBJECT_COUNTER(headerObj) = 12;
    } else {
        TextureCache_LoadCacheTexInfoList_impl(sRecordsCacheTexInfo, false, true);
    }
}

void CourseSelect_OkInit(Object* okObj) {
    TextureCache_LoadCacheTexInfoList_impl(sOKCacheTexInfo, false, true);
    OBJECT_LEFT(okObj) = 50;
}

void CourseSelect_ArrowsInit(Object* arrowsObj) {
    TextureCache_LoadCacheTexInfoList_impl(sYellowArrowCacheTexInfo, false, true);
    LEFT_ARROW_ROTATION_CHANGE(arrowsObj) = 0x80;
    RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) = 0x80;
}

void CourseSelect_GhostMarkerInit(Object* ghostMarkerObj) {
    GhostInfo ghostInfo;
#ifdef EXPANSION_KIT
    s32 pad[50];
#endif
#ifndef VERSION_PAL
    s32 i;
#endif

#ifndef EXPANSION_KIT
    if (Save_LoadGhostInfo(&ghostInfo) != 0) {
        ghostMarkerObj->cmdId = OBJECT_FREE;
    }
    if (ghostInfo.encodedCourseIndex == 0) {
        ghostMarkerObj->cmdId = OBJECT_FREE;
    }
    OBJECT_LEFT(ghostMarkerObj) += (ghostInfo.courseIndex % 6) * SCREEN_WIDTH;
    GHOST_MARKER_COURSE(ghostMarkerObj) = ghostInfo.courseIndex;
#else
    for (i = 0; i < 7; i++) {
        D_i5_8007C2A8[i] = 0;
    }

    GHOST_MARKER_COURSE(ghostMarkerObj) = -1;
    if ((Save_LoadGhostInfo(&ghostInfo) == 0) && (ghostInfo.encodedCourseIndex != 0)) {
        GHOST_MARKER_COURSE(ghostMarkerObj) = ghostInfo.courseIndex;
    }
#endif

    TextureCache_LoadCacheTexInfoList_impl(sHasGhostMarkerCacheTexInfo, false, true);
}

void CourseSelect_GhostOptionInit(Object* ghostOptionObj) {
    s32 i;

    TextureCache_LoadCacheTexInfoList_impl(sStaffGhostBeatenCacheTexInfo, false, true);

    for (i = 0; i < 5; i++) {
        TextureCache_LoadCacheTexInfoList_impl(sTimeAttackGhostOptionCacheTexInfos[i], false, true);
    }

    OBJECT_LEFT(ghostOptionObj) = 150;
}

Gfx* CourseSelect_BackgroundDraw(Gfx* gfx, Object* backgroundObj) {

    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        gDPSetPrimColor(gfx++, 0, 0, 75, 75, 75, 180);
        gfx = TextureCache_DrawList_impl(gfx, sTitleBackgroundCacheTexInfos[OBJECT_STATE(backgroundObj)],
                                         OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj),
                                         TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
    } else {
        gfx = TextureCache_DrawList_impl(gfx, sTitleBackgroundCacheTexInfos[OBJECT_STATE(backgroundObj)],
                                         OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj), TEXTURE_CACHE_DRAW,
                                         false, false, 1.0f, 1.0f, true);
        gfx = TextureCache_DrawList_impl(gfx, sOptionsFalconHelmetCacheTexInfo, 53, 4, TEXTURE_CACHE_DRAW_MIRROR, true,
                                         false, 1.0f, 1.0f, true);
        gfx = TextureCache_DrawList_impl(gfx, sOptionsFalconHelmetCacheTexInfo, 203, 4, TEXTURE_CACHE_DRAW, false,
                                         false, 1.0f, 1.0f, true);
    }
    return gfx;
}

Gfx* CourseSelect_ModelDraw(Gfx* gfx, Object* modelObj) {

    switch (sCourseSelectState) {
        case COURSE_SELECT_CHOOSE_COURSE:
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
        case COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT:
        case COURSE_SELECT_NEXT_COURSE_CONTINUE:
            if (sCourseSelectCup < NUM_COMPETITIVE_CUPS) {
                gfx = func_i5_80115E64(gfx);
            }
            break;
        case COURSE_SELECT_CUP_SELECT:
        default:
            break;
    }
    return gfx;
}

extern u32 gGameFrameCount;
extern s8 gCupNumDifficultiesCleared[];

Gfx* CourseSelect_CupDraw(Gfx* gfx, Object* cupObj) {
    s32 spA4;
    s32 i;
    s32 cupDifficultiesCleared;
    s32 cupOption;
    s32 alpha;
#ifdef EXPANSION_KIT
    s32 var_v0;
#endif
    s32 yOffset;
    s32 greyness;

    spA4 = cupObj->cmdId - OBJECT_COURSE_SELECT_CUP_0;
    if (gCupSelectOption >= 10) {
#ifndef EXPANSION_KIT
        cupOption = EDIT_CUP;
#else
        cupOption = gCupSelectOption - 5;
#endif
    } else {
        cupOption = gCupSelectOption;
    }
    if (cupOption == spA4) {
        if ((sCourseSelectState == COURSE_SELECT_CUP_SELECT) || (sCourseSelectState == COURSE_SELECT_EXIT_RECORDS)) {
            greyness = gGameFrameCount;
            greyness %= 30U;
            if (greyness >= 15) {
                greyness = 30 - greyness;
            }
            gDPSetPrimColor(gfx++, 0, 0, 255 - (greyness * 5), 255 - (greyness * 5), 255 - (greyness * 5), 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
    } else {
#ifndef EXPANSION_KIT
        alpha = 255;
#else
        if (cupOption >= 5) {
            if (gSelectedMode == 0) {
                var_v0 = 49;
            } else {
                var_v0 = 45;
            }

            alpha = ((OBJECT_TOP(cupObj) - var_v0) * 300) / (85 - var_v0);
            if (alpha > 255) {
                alpha = 255;
                if (1) {}
            }
        } else {
            alpha = 255;
        }
#endif
        gDPSetPrimColor(gfx++, 0, 0, 100, 100, 100, alpha);
    }

    switch (sCourseSelectState) {
        case COURSE_SELECT_START_EXIT:
        case COURSE_SELECT_EXIT:
            OBJECT_COUNTER(cupObj)++;
            if (OBJECT_COUNTER(cupObj) > 12) {
                sCourseSelectState = COURSE_SELECT_EXIT;
                OBJECT_COUNTER(cupObj) = 12;
            }
            break;
        default:
            if (OBJECT_COUNTER(cupObj) > 0) {
                OBJECT_COUNTER(cupObj)--;
            }
            break;
    }

    if (OBJECT_COUNTER(cupObj) < 0) {
        OBJECT_COUNTER(cupObj) = 0;
    }

    cupDifficultiesCleared = gCupNumDifficultiesCleared[spA4];
    yOffset = (SQ(OBJECT_COUNTER(cupObj)) * 3) / 2;

    switch (spA4) {
        case JOKER_CUP:
        case X_CUP:
#ifndef EXPANSION_KIT
            i = gUnlockableLevel;
            if ((i >= 3) || gSettingEverythingUnlocked) {
                i = 2;
            }
            if (i < (spA4 - 2)) {
                spA4 = 6;
            }
#else
            spA4 = func_i5_80077DAC(spA4);
#endif
            break;
    }

    gfx = TextureCache_DrawList_impl(gfx, sCupSelectCacheTexInfos[spA4], OBJECT_LEFT(cupObj),
                                     OBJECT_TOP(cupObj) + yOffset, TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f,
                                     false);

    if ((gSelectedMode == MODE_GP_RACE) && (spA4 <= JOKER_CUP)) {
        alpha = ((OBJECT_TOP(cupObj) - 49) * 255) / 36;
        if (cupOption == spA4) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
        }

        for (i = 0; i < cupDifficultiesCleared; i++) {
            gfx = TextureCache_DrawList_impl(
                gfx, sCupClearedDifficultyCacheTexInfos[i], OBJECT_LEFT(cupObj) + (i * 16) + ((12 - i * 8) / 2),
                (OBJECT_TOP(cupObj) + yOffset) - 12, TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
        }
    }

#ifdef EXPANSION_KIT
    cupDifficultiesCleared = D_8079FB28[spA4 - DD_1_CUP];
    if ((gSelectedMode == MODE_GP_RACE) && (spA4 >= DD_1_CUP)) {
        alpha = ((OBJECT_TOP(cupObj) - 49) * 255) / 121;
        if (cupOption == spA4) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
        }

        for (i = 0; i < cupDifficultiesCleared; i++) {
            gfx = TextureCache_DrawList_impl(
                gfx, sCupClearedDifficultyCacheTexInfos[i], OBJECT_LEFT(cupObj) + (i * 16) + ((12 - i * 8) / 2),
                (OBJECT_TOP(cupObj) + yOffset) - 9, TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
        }
    }
#endif
    return gfx;
}

Gfx* CourseSelect_HeaderDraw(Gfx* gfx, Object* headerObj) {
    s32 yOffset;

    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        switch (sCourseSelectState) {
            case COURSE_SELECT_START_EXIT:
            case COURSE_SELECT_EXIT:
                OBJECT_COUNTER(headerObj)++;
                if (OBJECT_COUNTER(headerObj) > 12) {
                    sCourseSelectState = COURSE_SELECT_EXIT;
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
        yOffset = (SQ(OBJECT_COUNTER(headerObj)) * 3) / 2;

        gfx = TextureCache_DrawList_impl(gfx, sSelectCourseCacheTexInfo, OBJECT_LEFT(headerObj),
                                         OBJECT_TOP(headerObj) + yOffset, TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f,
                                         true);
    } else {
        gfx = TextureCache_DrawList_impl(gfx, sRecordsCacheTexInfo, OBJECT_LEFT(headerObj), OBJECT_TOP(headerObj),
                                         TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
    }
    return gfx;
}

Gfx* CourseSelect_OkDraw(Gfx* gfx, Object* okObj) {
    gfx = func_8007DB28(gfx, 0);
    return TextureCache_DrawList_impl(gfx, sOKCacheTexInfo, OBJECT_LEFT(okObj) + 0x10B, OBJECT_TOP(okObj) + 0xD0,
                                      TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
}

Gfx* CourseSelect_ArrowsDraw(Gfx* gfx, Object* arrowsObj) {
    f32 temp_fv0 = (SIN(LEFT_ARROW_ROTATION(arrowsObj)) + 1.0) / 2;
    f32 temp_fa1 = (SIN(RIGHT_ARROW_ROTATION(arrowsObj)) + 1.0) / 2;

    // left and top represent x positions for left and right arrows for this object
    gfx = TextureCache_DrawList_impl(gfx, sYellowArrowCacheTexInfo, LEFT_ARROW_LEFT(arrowsObj) + 0x2B,
                                     (((1.0 - temp_fv0) * 16.0) + 112.0), TEXTURE_CACHE_DRAW_SCALED, false, false, 1.0f,
                                     temp_fv0, true);
    return TextureCache_DrawList_impl(gfx, sYellowArrowCacheTexInfo, RIGHT_ARROW_LEFT(arrowsObj) + 0xF5,
                                      (((1.0 - temp_fa1) * 16.0) + 112.0), TEXTURE_CACHE_DRAW_SCALED_MIRROR, false,
                                      false, 1.0f, temp_fa1, true);
}

Gfx* CourseSelect_NameDraw(Gfx* gfx) {
    char cupTrackNoStr[4];
    s32 cupTrackNoWidth;
    s32 trackNameWidth;
    s32* cupColors;
#ifdef EXPANSION_KIT
    s32 greyFactor;

    greyFactor = 1;
    if ((gSelectedMode == MODE_TIME_ATTACK) && (gCupType == EDIT_CUP) &&
        (gEditCupTrackNames[gCourseIndex - COURSE_EDIT_1][0] == '\0')) {
        greyFactor = 2;
        switch (sCourseSelectState) {
            case COURSE_SELECT_CUP_SELECT:
            case COURSE_SELECT_EXIT_RECORDS:
            case COURSE_SELECT_START_EXIT:
            case COURSE_SELECT_EXIT:
            case COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT:
            case COURSE_SELECT_NEXT_COURSE_CONTINUE:
                break;
            default:
                if ((gGameFrameCount / 15) % 4) {
                    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                    gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth("センタク デキマセン", 4, 0) / 2), 0x84,
                                          "センタク デキマセン", 0, 4, 0);
                }
                break;
        }
    }
#endif

    switch (sCourseSelectState) {
        case COURSE_SELECT_CUP_SELECT:
        default:
            break;
        case COURSE_SELECT_CHOOSE_COURSE:
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
        case COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT:
        case COURSE_SELECT_NEXT_COURSE_CONTINUE:
            Font_IntToString(sCourseSelectTrackNo + 1, cupTrackNoStr);
            cupTrackNoStr[1] = ':';
            cupTrackNoStr[2] = ' ';
            cupTrackNoStr[3] = '\0';
            cupTrackNoWidth = Font_GetStringWidth(cupTrackNoStr, FONT_SET_3, 0);
            if (sCourseSelectCup == NUM_COMPETITIVE_CUPS) {
                trackNameWidth = Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = Font_DrawString(
                    gfx, (-(trackNameWidth / 2) - (Font_GetStringWidth(cupTrackNoStr, FONT_SET_3, 0) / 2)) + 160, 200,
                    cupTrackNoStr, 0, FONT_SET_3, 0);
                gfx = Font_DrawString(
                    gfx, ((cupTrackNoWidth / 2) - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 0) / 2)) + 160,
                    200, gCurrentTrackName, 0, FONT_SET_3, 0);
            } else {
                trackNameWidth = Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 0);
                cupColors = &sCourseSelectCupColors[sCourseSelectCup * 3];
                gDPSetPrimColor(gfx++, 0, 0, cupColors[0], cupColors[1], cupColors[2], 255);
                gfx = Font_DrawString(
                    gfx, (-(trackNameWidth / 2) - (Font_GetStringWidth(cupTrackNoStr, FONT_SET_3, 0) / 2)) + 160, 200,
                    cupTrackNoStr, 0, FONT_SET_3, 0);
#ifndef EXPANSION_KIT
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
#else
                gDPSetPrimColor(gfx++, 0, 0, 255 / greyFactor, 255 / greyFactor, 255 / greyFactor, 255);
#endif
                gfx = Font_DrawString(
                    gfx, ((cupTrackNoWidth / 2) - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 0) / 2)) + 160,
                    200, gCurrentTrackName, 0, FONT_SET_3, 0);
                gfx = Font_DrawString(
                    gfx,
                    160 - (Font_GetStringWidth(sTrackSubtitles[sCourseSelectCup * 6 + sCourseSelectTrackNo], FONT_SET_4,
                                               0) /
                           2),
                    210, sTrackSubtitles[sCourseSelectCup * 6 + sCourseSelectTrackNo], 0, FONT_SET_4, 0);
            }
            break;
    }
    return gfx;
}

Gfx* CourseSelect_GhostMarkerDraw(Gfx* gfx, Object* ghostMarkerObj) {
    s32 i;
    s32 cupCourseIndex;
    s32 left;

#ifndef EXPANSION_KIT
    // If Cup Does Not Match
    if ((GHOST_MARKER_COURSE(ghostMarkerObj) / 6) != (gCourseIndex / 6)) {
        return gfx;
    }
#endif

    switch (sCourseSelectState) {
        case COURSE_SELECT_CUP_SELECT:
        case COURSE_SELECT_EXIT_RECORDS:
        case COURSE_SELECT_START_EXIT:
        case COURSE_SELECT_EXIT:
            break;
        case COURSE_SELECT_CHOOSE_COURSE:
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
#ifndef EXPANSION_KIT
            gfx = TextureCache_DrawList_impl(
                gfx, sHasGhostMarkerCacheTexInfo, OBJECT_LEFT(ghostMarkerObj) + GHOST_MARKER_OFFSET(ghostMarkerObj),
                OBJECT_TOP(ghostMarkerObj), TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
#else
            if (gCupSelectOption >= 10) {
                cupCourseIndex = sCourseSelectCup * 6;
            } else {
                cupCourseIndex = gCupSelectOption * 6;
            }

            for (i = 0; i < 6; i++) {
                left = OBJECT_LEFT(ghostMarkerObj) + i * SCREEN_WIDTH + GHOST_MARKER_OFFSET(ghostMarkerObj);
                if (left >= -30 && left <= SCREEN_WIDTH &&
                    ((D_i5_8007B9EC[cupCourseIndex + i] & 1) ||
                     (GHOST_MARKER_COURSE(ghostMarkerObj) == cupCourseIndex + i))) {
                    gfx = TextureCache_DrawList_impl(gfx, sHasGhostMarkerCacheTexInfo, left, OBJECT_TOP(ghostMarkerObj),
                                                     TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
                }
            }
#endif
            break;
    }

    return gfx;
}

Gfx* CourseSelect_GhostOptionDraw(Gfx* gfx, Object* ghostOptionObj) {
    s32 i;
    s32 numUnlockedGhosts;

#ifdef EXPANSION_KIT
    if ((gSelectedMode == MODE_TIME_ATTACK) && (gCupType == EDIT_CUP) &&
        (gEditCupTrackNames[gCourseIndex - COURSE_EDIT_1][0] == '\0')) {
        return gfx;
    }
#endif

    numUnlockedGhosts = sUnlockedGhosts + 1;

    for (i = 0; i < numUnlockedGhosts; i++) {
        if (i == sSelectedGhostOption) {
            switch (sCourseSelectState) {
                case COURSE_SELECT_AWAIT_OK:
                case COURSE_SELECT_CONTINUE:
                    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                    break;
                default:
                    gfx = func_8007DB28(gfx, 0);
                    break;
            }
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
        gfx = TextureCache_DrawList_impl(gfx, sTimeAttackGhostOptionCacheTexInfos[i], OBJECT_LEFT(ghostOptionObj) + 195,
                                         i * 20 + 0x2D, TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);

        if ((i == 2) && sStaffGhostTimeBeaten) {
            gfx = TextureCache_DrawList_impl(gfx, sStaffGhostBeatenCacheTexInfo, OBJECT_LEFT(ghostOptionObj) + 265,
                                             i * 20 + 0x2D, TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
        }
    }
    return gfx;
}

void CourseSelect_ModelUpdate(Object* modelObj) {
    s32 temp_a1;
    bool var_v1;

#ifdef EXPANSION_KIT
    if (D_i5_801190B4 == 0) {
        OBJECT_COUNTER(modelObj) = 1;
    }
    var_v1 = false;
    switch (sCourseSelectState) {
        case COURSE_SELECT_EXIT_RECORDS:
        case COURSE_SELECT_START_EXIT:
        case COURSE_SELECT_EXIT:
            var_v1 = true;
            break;
        case COURSE_SELECT_CUP_SELECT:
            if (gCupSelectOption < 10) {
                break;
            }
            /* fallthrough */
        default:
            if (OBJECT_COUNTER(modelObj) == 0) {
                if ((func_80742510() == 0) || (gCupSelectOption < 10)) {
                    func_i5_80115E10();
                }
                var_v1 = true;
            }
            break;
    }
#endif

#ifndef EXPANSION_KIT
    if (((sCourseSelectState != COURSE_SELECT_CUP_SELECT) && (sCourseSelectState != COURSE_SELECT_EXIT_RECORDS)) ||
        (gCupSelectOption < 4)) {
#else
    if (!var_v1 &&
        (((sCourseSelectState != COURSE_SELECT_CUP_SELECT) && (sCourseSelectState != COURSE_SELECT_EXIT_RECORDS)) ||
         (gCupSelectOption < 4))) {
#endif
        func_i5_80115E10();
    }
    temp_a1 = -(sCourseSelectTrackNo * 0x500);
    if (gGameMode == GAMEMODE_FLX_GP_RACE_NEXT_COURSE) {
        OBJECT_LEFT(modelObj) = temp_a1;
    } else {
        Object_LerpPosXToClampedTargetMaxStep(modelObj, temp_a1, 192);
    }
    func_i5_801164A8(OBJECT_LEFT(modelObj));
}

void CourseSelect_CupUpdate(Object* cupObj) {
    s32 var_v1;
    s32 var_a1;
    s32 var_v0;
    s32 state;

    if (gGameMode == GAMEMODE_FLX_GP_RACE_NEXT_COURSE) {
        OBJECT_LEFT(cupObj) = 128;
        OBJECT_TOP(cupObj) = 49;
        return;
    }

    var_v1 = cupObj->cmdId - OBJECT_COURSE_SELECT_CUP_0;
    state = OBJECT_STATE(cupObj);
    switch (state) {
        case 0:
#ifndef EXPANSION_KIT
            if (var_v1 != 5) {
#else
            if (var_v1 >= 5) {
#endif
                if (OBJECT_TOP(cupObj) < 85) {
                    Object_LerpPosYToTarget(cupObj, 85);
                } else {
                    OBJECT_STATE(cupObj) = 1;
                }
            } else if (OBJECT_TOP(cupObj) > 170) {
                Object_LerpPosYToTarget(cupObj, 170);
            } else {
                OBJECT_STATE(cupObj) = 1;
            }
            if ((sCourseSelectState != COURSE_SELECT_CUP_SELECT) &&
                (sCourseSelectState != COURSE_SELECT_EXIT_RECORDS)) {
                OBJECT_STATE(cupObj) = 1;
            }
            break;
        case 1:
        case 2:
        case 3:
#ifndef EXPANSION_KIT
            if ((var_v1 == gCupSelectOption) || ((gCupSelectOption >= 10) && (var_v1 == 5))) {
#else
            if ((var_v1 == gCupSelectOption) || ((gCupSelectOption >= 10) && (var_v1 == gCupSelectOption - 5))) {
#endif
                cupObj->priority = 7;
            } else {
                cupObj->priority = 6;
            }

            switch (sCourseSelectState) {
                case COURSE_SELECT_CUP_SELECT:
                case COURSE_SELECT_EXIT_RECORDS:
                case COURSE_SELECT_START_EXIT:
                case COURSE_SELECT_EXIT:
#ifndef EXPANSION_KIT
                    Object_LerpPosYToTarget(cupObj, (var_v1 != 5) ? 85 : 170);
#else
                    Object_LerpPosYToTarget(cupObj, (var_v1 < 5) ? 85 : 170);
#endif

                    if (OBJECT_STATE(cupObj) == 2) {
                        OBJECT_STATE(cupObj) = 3;
                    }
                    break;
                case COURSE_SELECT_CHOOSE_COURSE:
                case COURSE_SELECT_AWAIT_OK:
                case COURSE_SELECT_CONTINUE:
                default:
                    if (gSelectedMode == MODE_GP_RACE) {
                        Object_LerpPosYToTarget(cupObj, 0x31);
                    } else {
                        Object_LerpPosYToTarget(cupObj, 0x2D);
                    }
                    OBJECT_STATE(cupObj) = 2;
                    break;
            }
#ifndef EXPANSION_KIT
            if ((OBJECT_STATE(cupObj) == 2) || (var_v1 == 5)) {
#else
            if (OBJECT_STATE(cupObj) == 2) {
#endif
                var_a1 = 128;
#ifdef EXPANSION_KIT
            } else if (var_v1 >= 5) {

                switch (var_v1) {
                    case 5:
                        var_a1 = 128;
                        break;
                    case 6:
                        var_a1 = 54;
                        break;
                    case 7:
                        var_a1 = 202;
                        break;
                }
#endif
            } else {
                var_v0 = gUnlockableLevel;
                if (gSettingEverythingUnlocked) {
                    var_v0 = 2;
                }
                switch (var_v0) {
                    case 0:
                        if (var_v1 >= 3) {
                            var_v1 = 2;
                        }
                        var_a1 = (((s32) ((var_v1 << 7) + 0x80) / 2) + (var_v1 * 0xA)) - 0xA;
                        break;
                    default:
                    case 2:
                    case 3:
                        if ((gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) && (gSelectedMode != MODE_TIME_ATTACK)) {
                            var_a1 = ((s32) (var_v1 << 7) / 2) + (var_v1 * -8) + 0x10;
                            break;
                        }
                    /* fallthrough */
                    case 1:
                        if (var_v1 >= 4) {
                            var_v1 = 3;
                        }
                        var_a1 = (((s32) ((var_v1 * 0xC) + 0x12E) / 2) + (var_v1 << 6)) - 0x80;
                        break;
                }
            }

            if (OBJECT_COUNTER(cupObj) == 0xB) {
                OBJECT_LEFT(cupObj) = var_a1;
            } else if (OBJECT_STATE(cupObj) >= 2) {
                Object_LerpPosXToClampedTargetMaxStep(cupObj, var_a1, 0x80);
            } else {
                Object_LerpPosXToTarget(cupObj, var_a1, 0x10 / OBJECT_STATE(cupObj));
            }
            break;
    }
}

void CourseSelect_OkUpdate(Object* okObj) {
    switch (sCourseSelectState) {
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 0, 192);
            break;
        default:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 50, 192);
            break;
    }
}

void CourseSelect_ArrowsUpdate(Object* arrowsObj) {

    switch (sCourseSelectState) {
        case COURSE_SELECT_CUP_SELECT:
        case COURSE_SELECT_EXIT_RECORDS:
        case COURSE_SELECT_START_EXIT:
        case COURSE_SELECT_EXIT:
            arrowsObj->shouldDraw = false;
            LEFT_ARROW_LEFT(arrowsObj) = -100;
            RIGHT_ARROW_LEFT(arrowsObj) = 100;
            LEFT_ARROW_ROTATION_CHANGE(arrowsObj) = 0x80;
            RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) = 0x80;
            break;
        case COURSE_SELECT_CHOOSE_COURSE:
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
        default:
            if (LEFT_ARROW_ROTATION_CHANGE(arrowsObj) > 640) {
                LEFT_ARROW_ROTATION_CHANGE(arrowsObj) = 640;
            }
            if (LEFT_ARROW_ROTATION_CHANGE(arrowsObj) > 128) {
                LEFT_ARROW_ROTATION_CHANGE(arrowsObj) -= 16;
            } else {
                LEFT_ARROW_ROTATION_CHANGE(arrowsObj) = 128;
            }
            LEFT_ARROW_ROTATION(arrowsObj) += LEFT_ARROW_ROTATION_CHANGE(arrowsObj);

            if (RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) > 640) {
                RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) = 640;
            }
            if (RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) > 128) {
                RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) -= 16;
            } else {
                RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) = 128;
            }
            RIGHT_ARROW_ROTATION(arrowsObj) += RIGHT_ARROW_ROTATION_CHANGE(arrowsObj);

            arrowsObj->shouldDraw = true;
            if ((sCourseSelectTrackNo == 0) || (sCourseSelectState == COURSE_SELECT_AWAIT_OK) ||
                (sCourseSelectState == COURSE_SELECT_CONTINUE)) {
                Object_LerpPosXToClampedTargetMaxStep(arrowsObj, -100, 192);
            } else {
                Object_LerpPosXToClampedTargetMaxStep(arrowsObj, 0, 192);
            }
            if ((sCourseSelectTrackNo == 5) || (sCourseSelectState == COURSE_SELECT_AWAIT_OK) ||
                (sCourseSelectState == COURSE_SELECT_CONTINUE)) {
                Object_LerpPosYToClampedTarget(arrowsObj, 100);
            } else {
                Object_LerpPosYToClampedTarget(arrowsObj, 0);
            }
            break;
    }
}

void CourseSelect_GhostMarkerUpdate(Object* ghostMarkerObj) {
    s32 xPos;

    GHOST_MARKER_OFFSET(ghostMarkerObj) = OBJECT_LEFT(Object_Get(OBJECT_COURSE_SELECT_MODEL)) >> 2;
#ifndef EXPANSION_KIT
    xPos = OBJECT_LEFT(ghostMarkerObj) + GHOST_MARKER_OFFSET(ghostMarkerObj);

    if ((xPos < -30) || (xPos > SCREEN_WIDTH)) {
        ghostMarkerObj->shouldDraw = false;
    } else {
        ghostMarkerObj->shouldDraw = true;
    }
#endif
}

void CourseSelect_GhostOptionUpdate(Object* ghostOptionObj) {
    switch (sCourseSelectState) {
        case COURSE_SELECT_CUP_SELECT:
        case COURSE_SELECT_EXIT_RECORDS:
        case COURSE_SELECT_START_EXIT:
        case COURSE_SELECT_EXIT:
            Object_LerpPosXToClampedTargetMaxStep(ghostOptionObj, 150, 192);
            break;
        case COURSE_SELECT_CHOOSE_COURSE:
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
        default:
            Object_LerpPosXToClampedTargetMaxStep(ghostOptionObj, 0, 192);
            break;
    }
}
