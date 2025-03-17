#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "src/overlays/ovl_i2/ovl_i2.h"
#include "ovl_i6.h"
#include "assets/segment_2B9EA0.h"
#include "assets/segment_17B1E0.h"

s16 D_i6_8011F910[SCREEN_HEIGHT];

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
unk_80077D50 sMenuSignGpRaceCompTexInfo[] = { { 17, aMenuSignGpRaceTex, TEX_WIDTH(aMenuSignGpRaceTex),
                                                TEX_HEIGHT(aMenuSignGpRaceTex),
                                                TEX_COMPRESSED_SIZE(aMenuSignGpRaceTex) },
                                              { 0 } };

// TIME ATTACK
unk_80077D50 sMenuSignTimeAttackCompTexInfo[] = { { 17, aMenuSignTimeAttackTex, TEX_WIDTH(aMenuSignTimeAttackTex),
                                                    TEX_HEIGHT(aMenuSignTimeAttackTex),
                                                    TEX_COMPRESSED_SIZE(aMenuSignTimeAttackTex) },
                                                  { 0 } };

// VS BATTLE
unk_80077D50 sMenuSignVsBattleCompTexInfo[] = { { 17, aMenuSignVsBattleTex, TEX_WIDTH(aMenuSignVsBattleTex),
                                                  TEX_HEIGHT(aMenuSignVsBattleTex),
                                                  TEX_COMPRESSED_SIZE(aMenuSignVsBattleTex) },
                                                { 0 } };

// PRACTICE
unk_80077D50 sMenuSignPracticeCompTexInfo[] = { { 17, aMenuSignPracticeTex, TEX_WIDTH(aMenuSignPracticeTex),
                                                  TEX_HEIGHT(aMenuSignPracticeTex),
                                                  TEX_COMPRESSED_SIZE(aMenuSignPracticeTex) },
                                                { 0 } };

// DEATH RACE
unk_80077D50 sMenuSignDeathRaceCompTexInfo[] = { { 17, aMenuSignDeathRaceTex, TEX_WIDTH(aMenuSignDeathRaceTex),
                                                   TEX_HEIGHT(aMenuSignDeathRaceTex),
                                                   TEX_COMPRESSED_SIZE(aMenuSignDeathRaceTex) },
                                                 { 0 } };

// OPTIONS
unk_80077D50 sMenuSignOptionsCompTexInfo[] = { { 17, aMenuSignOptionsTex, TEX_WIDTH(aMenuSignOptionsTex),
                                                 TEX_HEIGHT(aMenuSignOptionsTex),
                                                 TEX_COMPRESSED_SIZE(aMenuSignOptionsTex) },
                                               { 0 } };

// COURSE EDIT
unk_80077D50 sMenuSignCourseEditCompTexInfo[] = { { 17, aMenuSignCourseEditTex, TEX_WIDTH(aMenuSignCourseEditTex),
                                                    TEX_HEIGHT(aMenuSignCourseEditTex),
                                                    TEX_COMPRESSED_SIZE(aMenuSignCourseEditTex) },
                                                  { 0 } };

// CREATE MACHINE
unk_80077D50 sMenuSignCreateMachineCompTexInfo[] = {
    { 17, aMenuSignCreateMachineTex, TEX_WIDTH(aMenuSignCreateMachineTex), TEX_HEIGHT(aMenuSignCreateMachineTex),
      TEX_COMPRESSED_SIZE(aMenuSignCreateMachineTex) },
    { 0 }
};

unk_80077D50* sMenuSignCompTexInfos[] = {
    sMenuSignGpRaceCompTexInfo,        // MODE_GP_RACE
    sMenuSignTimeAttackCompTexInfo,    // MODE_TIME_ATTACK
    sMenuSignDeathRaceCompTexInfo,     // MODE_DEATH_RACE
    sMenuSignVsBattleCompTexInfo,      // MODE_VS_BATTLE
    sMenuSignCourseEditCompTexInfo,    // MODE_COURSE_EDIT
    sMenuSignPracticeCompTexInfo,      // MODE_PRACTICE
    sMenuSignOptionsCompTexInfo,       // MODE_OPTIONS
    sMenuSignCreateMachineCompTexInfo, // MODE_CREATE_MACHINE
};

/*
    LARGE WALLPAPER-STYLE IMAGES/COMIC STYLE IMAGE
 */

// TITLE SCREEN BACKGROUND
static unk_80077D50 sTitleBackgroundMainCompTexInfo[] = {
    { 17, aTitleBackgroundMainTex, TEX_WIDTH(aTitleBackgroundMainTex), TEX_HEIGHT(aTitleBackgroundMainTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundMainTex) },
    { 0 }
};

// COMIC STRIP
static unk_80077D50 sTitleBackgroundComicCompTexInfo[] = {
    { 17, aTitleBackgroundComicTex, TEX_WIDTH(aTitleBackgroundComicTex), TEX_HEIGHT(aTitleBackgroundComicTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundComicTex) },
    { 0 }
};

// BLUE FALCON, SEMI-TRANSPARENT
static unk_80077D50 sTitleBackgroundFalconCompTexInfo[] = {
    { 17, aTitleBackgroundFalconTex, TEX_WIDTH(aTitleBackgroundFalconTex), TEX_HEIGHT(aTitleBackgroundFalconTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundFalconTex) },
    { 0 }
};

static unk_80077D50* sTitleBackgroundCompTexInfos[] = {
    sTitleBackgroundMainCompTexInfo,
    sTitleBackgroundComicCompTexInfo,
    sTitleBackgroundFalconCompTexInfo,
};

/*
    MENU SECOND OPTIONS
 */

// SELECT MODE
unk_80077D50 sSelectModeCompTexInfo[] = {
    { 4, aSelectModeTex, TEX_WIDTH(aSelectModeTex), TEX_HEIGHT(aSelectModeTex), 0 }, { 0 }
};

// FLAMES
unk_80077D50 sSelectModeOptionFlamesCompTexInfo[] = {
    { 17, aSelectModeOptionFlamesTex, TEX_WIDTH(aSelectModeOptionFlamesTex), TEX_HEIGHT(aSelectModeOptionFlamesTex),
      TEX_COMPRESSED_SIZE(aSelectModeOptionFlamesTex) },
    { 0 }
};

// NOVICE
static unk_80077D50 sNoviceCompTexInfo[] = {
    { 17, aNoviceTex, TEX_WIDTH(aNoviceTex), TEX_HEIGHT(aNoviceTex), TEX_COMPRESSED_SIZE(aNoviceTex) }, { 0 }
};

// STANDARD
static unk_80077D50 sStandardCompTexInfo[] = {
    { 17, aStandardTex, TEX_WIDTH(aStandardTex), TEX_HEIGHT(aStandardTex), TEX_COMPRESSED_SIZE(aStandardTex) }, { 0 }
};

// EXPERT
static unk_80077D50 sExpertCompTexInfo[] = {
    { 17, aExpertTex, TEX_WIDTH(aExpertTex), TEX_HEIGHT(aExpertTex), TEX_COMPRESSED_SIZE(aExpertTex) }, { 0 }
};

// MASTER
static unk_80077D50 sMasterCompTexInfo[] = {
    { 17, aMasterTex, TEX_WIDTH(aMasterTex), TEX_HEIGHT(aMasterTex), TEX_COMPRESSED_SIZE(aMasterTex) }, { 0 }
};

// 2 PLAYERS
unk_80077D50 s2PlayersCompTexInfo[] = {
    { 17, a2PlayersTex, TEX_WIDTH(a2PlayersTex), TEX_HEIGHT(a2PlayersTex), TEX_COMPRESSED_SIZE(a2PlayersTex) }, { 0 }
};

// 3 PLAYERS
unk_80077D50 s3PlayersCompTexInfo[] = {
    { 17, a3PlayersTex, TEX_WIDTH(a3PlayersTex), TEX_HEIGHT(a3PlayersTex), TEX_COMPRESSED_SIZE(a3PlayersTex) }, { 0 }
};

// 4 PLAYERS
unk_80077D50 s4PlayersCompTexInfo[] = {
    { 17, a4PlayersTex, TEX_WIDTH(a4PlayersTex), TEX_HEIGHT(a4PlayersTex), TEX_COMPRESSED_SIZE(a4PlayersTex) }, { 0 }
};

// TIME ATTACK
unk_80077D50 sTimeAttackCompTexInfo[] = { { 18, aTimeAttackTex, TEX_WIDTH(aTimeAttackTex), TEX_HEIGHT(aTimeAttackTex),
                                            TEX_COMPRESSED_SIZE(aTimeAttackTex) },
                                          { 0 } };

// RECORDS
unk_80077D50 sRecordsOptionCompTexInfo[] = { { 17, aRecordsOptionTex, TEX_WIDTH(aRecordsOptionTex),
                                               TEX_HEIGHT(aRecordsOptionTex), TEX_COMPRESSED_SIZE(aRecordsOptionTex) },
                                             { 0 } };

static unk_80077D50* sDifficultyCompTexInfos[] = {
    sNoviceCompTexInfo,
    sStandardCompTexInfo,
    sExpertCompTexInfo,
    sMasterCompTexInfo,
};

unk_80077D50* sNumPlayersCompTexInfos[] = {
    s2PlayersCompTexInfo,
    s3PlayersCompTexInfo,
    s4PlayersCompTexInfo,
};

unk_80077D50* sTimeAttackModeCompTexInfos[] = {
    sTimeAttackCompTexInfo,
    sRecordsOptionCompTexInfo,
};

// 'OK?'
static unk_80077D50 sOkCompTexInfo[] = {
    { 17, aOKTex, TEX_WIDTH(aOKTex), TEX_HEIGHT(aOKTex), TEX_COMPRESSED_SIZE(aOKTex) }, { 0 }
};

extern u32 gGameFrameCount;
extern s16 D_800CCFE8;
extern s32 gNumPlayers;
extern s32 D_800CD384;

const s32 gDefaultSubOptionLimits[] = { 2, 1, 0, 2, 0, 2, 0, 0 };

const s32 gMaxSubOptionLimits[] = { 3, 1, 0, 2, 0, 3, 0, 0 };

void MainMenu_Init(void) {
    D_800CCFE8 = 3;
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
extern s16 D_800CD044;
extern s16 D_800CD048;
extern s32 gSelectedMode;
extern s8 gUnlockableLevel;
extern s8 gSettingEverythingUnlocked;
extern s32 gGameMode;
extern Controller gSharedController;
extern s32 gControllersConnected;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;
extern char* gCurrentTrackName;
extern s32 gCourseIndex;
extern s32 D_i2_80106DA4;

s32 MainMenu_Update(void) {
    s32 previous;
    bool var_v1_2;

    if (D_i2_80106DA4 != 0) {
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
#ifndef VERSION_JP
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
            if (previous != gSelectedMode) {
                func_800BA8D8(0x1E);
            }
            if (gInputButtonPressed & BTN_B) {
                func_800BA8D8(0x10);
                func_8007E0CC();
                D_800CD384 = 5;
                return GAMEMODE_FLX_TITLE;
            }

            if ((gInputButtonPressed & BTN_START) &&
                (OBJECT_STATE(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) == 7)) {
                break;
            }

            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_800BA8D8(0x3E);
                gAntiPiracyAddedDifficulty =
                    (UNLOCK_EVERYTHING_ROMDATA(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) & 0xFFFF) - 0x997A;
                switch (gSelectedMode) {
                    case MODE_GP_RACE:
                    case MODE_TIME_ATTACK:
                    case MODE_VS_BATTLE:
                    case MODE_PRACTICE:
                        func_800BA8D8(0x21);
                        D_800CD384 = 1;
                        break;
                    case MODE_DEATH_RACE:
                        D_800CD384 = 5;
                        gCourseIndex = COURSE_DEATH_RACE;
                        gCurrentTrackName = gTrackNames[gCourseIndex];
                        gNumPlayers = 1;
                        func_800BB324(gNumPlayers - 1);
                        gDifficulty = gAntiPiracyAddedDifficulty + MASTER;
                        return GAMEMODE_FLX_MACHINE_SELECT;
                    case MODE_OPTIONS:
                        D_800CD384 = 5;
                        D_800CD048 = 13;
                        break;
                    case MODE_COURSE_EDIT:
                        D_800CD384 = 5;
                        return GAMEMODE_COURSE_EDIT;
                    case MODE_CREATE_MACHINE:
                        D_800CD384 = 5;
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
                if (gDefaultSubOptionLimits[gSelectedMode] < gModeSubOption[gSelectedMode]) {
                    gModeSubOption[gSelectedMode] = gDefaultSubOptionLimits[gSelectedMode];
                }
            } else {
                if (gMaxSubOptionLimits[gSelectedMode] < gModeSubOption[gSelectedMode]) {
                    gModeSubOption[gSelectedMode] = gMaxSubOptionLimits[gSelectedMode];
                }
            }
#ifndef VERSION_JP
            if (gSelectedMode == MODE_VS_BATTLE && (gControllersConnected < gModeSubOption[gSelectedMode] + 2)) {
                gModeSubOption[gSelectedMode] = gControllersConnected - 2;
                if (gModeSubOption[gSelectedMode] < 0) {
                    gModeSubOption[gSelectedMode] = 0;
                    D_800CD384 = 0;
                    func_800BA8D8(0x10);
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
                func_800BA8D8(0x1E);
            }
            if (gInputButtonPressed & BTN_B) {
                D_800CD384 = 0;
                func_800BA8D8(0x10);
            } else if ((gInputButtonPressed & BTN_START) &&
                       (OBJECT_STATE(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) == 7)) {
                break;
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_800BA8D8(0x21);
                D_800CD384 = 2;
                switch (gSelectedMode) {
                    case MODE_VS_BATTLE:
                        gNumPlayers = gModeSubOption[MODE_VS_BATTLE] + 2;
                        break;
                    case MODE_TIME_ATTACK:
                        if (gModeSubOption[MODE_TIME_ATTACK] != 0) {
                            D_800CD384 = 6;
                            D_800CD048 = 9;
                            func_800BA8D8(0x3E);
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
                func_800BA8D8(0x10);
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
                func_800BA8D8(0x3E);
                func_800BB324(gNumPlayers - 1);
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
                func_800BA8D8(0x10);
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
            if (D_800CD044 == 0) {
                D_800CD048 = 11;
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

    OBJECT_STATE(backgroundObj) = D_800CD3C4;
    func_80077D50(sTitleBackgroundCompTexInfos[OBJECT_STATE(backgroundObj)], 0);

    switch (OBJECT_STATE(backgroundObj)) {
        case 0:
            OBJECT_LEFT(backgroundObj) = 8;
            /* fallthrough */
        case 1:
            for (i = 0; i < 240; i++) {
                D_i6_8011F910[i] = 0;
            }

            func_80077D50(sTitleBackgroundCompTexInfos[2], 0);
            break;
    }
}

extern s16 D_800CD044;

void MainMenu_SignInit(Object* signObj) {
    s32 index = signObj->cmdId - OBJECT_MAIN_MENU_MODE_SIGN_0;

    func_80077D50(sMenuSignCompTexInfos[index], 0);
    if (D_800CD044 == 33) {
        OBJECT_COUNTER(signObj) = 12;
    }
}

void MainMenu_HeaderInit(Object* headerObj) {

    func_80077D50(sSelectModeCompTexInfo, 0);
    if (D_800CD044 == 33) {
        OBJECT_COUNTER(headerObj) = 12;
    }
}

void MainMenu_NumPlayersInit(void) {
    s32 i;

    func_80077D50(sSelectModeOptionFlamesCompTexInfo, 0);

    for (i = 0; i < 3; i++) {
        func_80077D50(sNumPlayersCompTexInfos[i], 0);
    }
}

void MainMenu_DifficultyInit(void) {
    s32 i;

    func_80077D50(sSelectModeOptionFlamesCompTexInfo, 0);

    for (i = 0; i < 4; i++) {
        func_80077D50(sDifficultyCompTexInfos[i], 0);
    }
}

void MainMenu_TimeAttackModeInit(void) {
    s32 i;

    func_80077D50(sSelectModeOptionFlamesCompTexInfo, 0);

    for (i = 0; i < 2; i++) {
        func_80077D50(sTimeAttackModeCompTexInfos[i], 0);
    }
}

void MainMenu_OkInit(Object* okObj) {
    func_80077D50(sOkCompTexInfo, 0);
    OBJECT_LEFT(okObj) = 50;
}

s32 func_i6_8011DBD0(void);

void MainMenu_UnlockEverythingInit(Object* unlockEverythingObj) {
    UNLOCK_EVERYTHING_ROMDATA(unlockEverythingObj) = func_i6_8011DBD0();
}

extern u32 gGameFrameCount;
extern s32 gSelectedMode;

#ifdef VERSION_JP
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

    if ((mode == MODE_COURSE_EDIT) || (mode == MODE_CREATE_MACHINE)) {
        return gfx;
    }

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

    gfx = func_80078EA0(gfx, sMenuSignCompTexInfos[mode], temp1, temp2, 1, 0, 0, 1.0f, 1.0f);

#ifdef VERSION_JP
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
    unk_80077D50* sp44;
    unk_80077D50* var_ra;

    if (OBJECT_STATE(backgroundObj) < 3) {
        sp44 = sTitleBackgroundCompTexInfos[OBJECT_STATE(backgroundObj)];
        gfx = func_80078EA0(gfx, sp44, OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj), 0, 0, 0, 1.0f, 1.0f);
        gfx = func_8007A440(gfx, OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj),
                            OBJECT_LEFT(backgroundObj) + sp44->width, OBJECT_TOP(backgroundObj) + sp44->height,
                            D_i6_8011DC60, D_i6_8011DC64, D_i6_8011DC68, D_i6_8011DC6C);
    } else {
        sp44 = sTitleBackgroundCompTexInfos[D_800CD3C4];
        gfx = func_80078EA0(gfx, sp44, OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj), 0, 0, 0, 1.0f, 1.0f);
        var_t1 = (OBJECT_STATE(backgroundObj) / 10);
        var_ra = sTitleBackgroundCompTexInfos[var_t1 - 1];

        texture = func_800783AC(var_ra->unk_04);

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
                OBJECT_COUNTER(backgroundObj) += 4;
                break;
        }

        for (var_t1 = 0; var_t1 < 240; var_t1++) {

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

        gfx = func_8007A440(gfx, OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj),
                            OBJECT_LEFT(backgroundObj) + sp44->width, OBJECT_TOP(backgroundObj) + sp44->height,
                            D_i6_8011DC60, D_i6_8011DC64, D_i6_8011DC68, D_i6_8011DC6C);
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

    return func_80078EA0(gfx, sSelectModeCompTexInfo, OBJECT_LEFT(headerObj) - temp, OBJECT_TOP(headerObj), 0, 0, 0,
                         1.0f, 1.0f);
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
    gfx = func_80078EA0(gfx, sSelectModeOptionFlamesCompTexInfo, OBJECT_LEFT(numPlayersObj) - temp_s7,
                        OBJECT_TOP(numPlayersObj), 0, 0, 0, 1.0f, 1.0f);

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
#ifdef VERSION_JP
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
#else
            if ((gControllersConnected - 2) < i) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 128);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
#endif
        }
        gfx = func_80078EA0(gfx, sNumPlayersCompTexInfos[i], (OBJECT_LEFT(numPlayersObj) - temp_s7) + 0x20,
                            OBJECT_TOP(numPlayersObj) + (i * 20) + 0xC, 1, 0, 0, 1.0f, 1.0f);
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
    gfx = func_80078EA0(gfx, sSelectModeOptionFlamesCompTexInfo, OBJECT_LEFT(difficultyObj) - temp_s6,
                        OBJECT_TOP(difficultyObj), 0, 0, 0, 1.0f, 1.0f);

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
        if ((gUnlockableLevel < 2) && (gSettingEverythingUnlocked == 0)) {
            if (i < 3) {
#ifdef VERSION_JP
                gfx = func_80078EA0(gfx, sDifficultyCompTexInfos[i], (OBJECT_LEFT(difficultyObj) - temp_s6) + 0x20,
                                    OBJECT_TOP(difficultyObj) + (i * 20) + 0xC, 1, 0, 0, 1.0f, 1.0f);
#else
                gfx = func_80078EA0(gfx, sDifficultyCompTexInfos[i], (OBJECT_LEFT(difficultyObj) - temp_s6) + 0x20,
                                    OBJECT_TOP(difficultyObj) + (i * 20) + 0xE, 1, 0, 0, 1.0f, 1.0f);
#endif
            }
        } else {
#ifdef VERSION_JP
            gfx = func_80078EA0(gfx, sDifficultyCompTexInfos[i], (OBJECT_LEFT(difficultyObj) - temp_s6) + 0x20,
                                OBJECT_TOP(difficultyObj) + (i * 18) + 5, 1, 0, 0, 1.0f, 1.0f);
#else
            gfx = func_80078EA0(gfx, sDifficultyCompTexInfos[i], (OBJECT_LEFT(difficultyObj) - temp_s6) + 0x20,
                                OBJECT_TOP(difficultyObj) + (i * 18) + 7, 1, 0, 0, 1.0f, 1.0f);
#endif
        }
    }

    return gfx;
}

Gfx* MainMenu_TimeAttackModeDraw(Gfx* gfx, Object* timeAttackModeObj) {
    s32 i;
    s32 temp_s7;
    unk_80077D50* temp_a1;

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
    gfx = func_80078EA0(gfx, sSelectModeOptionFlamesCompTexInfo, OBJECT_LEFT(timeAttackModeObj) - temp_s7,
                        OBJECT_TOP(timeAttackModeObj), 0, 0, 0, 1.0f, 1.0f);

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
        temp_a1 = sTimeAttackModeCompTexInfos[i];
#ifdef VERSION_JP
        gfx = func_80078EA0(gfx, temp_a1,
                            (((s32) (0x80 - temp_a1->width) / 2) + OBJECT_LEFT(timeAttackModeObj)) - temp_s7,
                            OBJECT_TOP(timeAttackModeObj) + (i * 28) + 0x11, 1, 0, 0, 1.0f, 1.0f);
#else
        gfx = func_80078EA0(gfx, temp_a1,
                            (((s32) (0x80 - temp_a1->width) / 2) + OBJECT_LEFT(timeAttackModeObj)) - temp_s7,
                            OBJECT_TOP(timeAttackModeObj) + (i * 28) + 0x15, 1, 0, 0, 1.0f, 1.0f);
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
            gfx = func_80078EA0(gfx, sOkCompTexInfo, OBJECT_LEFT(okObj) + 0x10B, OBJECT_TOP(okObj) + 0xD0, 1, 0, 0,
                                1.0f, 1.0f);
            break;
        default:
            gfx = func_8007DB28(gfx, 0);
            gfx = func_80078EA0(gfx, sOkCompTexInfo, OBJECT_LEFT(okObj) + 0x10B, OBJECT_TOP(okObj) + 0xD0, 1, 0, 0,
                                1.0f, 1.0f);
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

extern u16 gInputPressed;
extern u16 gInputButtonPressed;

const u16 gUnlockEverythingInputs[] = { BTN_L, BTN_Z, BTN_R, BTN_CUP, BTN_CDOWN, BTN_CLEFT, BTN_CRIGHT, BTN_START };

void MainMenu_UnlockEverythingUpdate(Object* unlockEverythingObj) {
    Object* backgroundObj;

    if ((OBJECT_STATE(unlockEverythingObj) < 8) && (gInputButtonPressed != 0)) {
        if (gUnlockEverythingInputs[OBJECT_STATE(unlockEverythingObj)] & gInputPressed) {
            if (++OBJECT_STATE(unlockEverythingObj) == 8) {
                gSettingEverythingUnlocked = 1;
                Save_SaveSettingsProfiles();
                func_800BA8D8(0x2E);
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
