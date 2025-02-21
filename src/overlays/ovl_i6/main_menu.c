#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
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
unk_80077D50 sMenuSignGpRaceCompTexInfo[] = { { 17, aMenuSignGpRaceTex, 64, 86, 0xF57 }, { 0 } };

// TIME ATTACK
unk_80077D50 sMenuSignTimeAttackCompTexInfo[] = { { 17, aMenuSignTimeAttackTex, 64, 86, 0x1049 }, { 0 } };

// VS BATTLE
unk_80077D50 sMenuSignVsBattleCompTexInfo[] = { { 17, aMenuSignVsBattleTex, 64, 86, 0xF98 }, { 0 } };

// PRACTICE
unk_80077D50 sMenuSignPracticeCompTexInfo[] = { { 17, aMenuSignPracticeTex, 64, 86, 0xF76 }, { 0 } };

// DEATH RACE
unk_80077D50 sMenuSignDeathRaceCompTexInfo[] = { { 17, aMenuSignDeathRaceTex, 64, 86, 0xE83 }, { 0 } };

// OPTIONS
unk_80077D50 sMenuSignOptionsCompTexInfo[] = { { 17, aMenuSignOptionsTex, 64, 86, 0xF8F }, { 0 } };

// COURSE EDIT
unk_80077D50 sMenuSignCourseEditCompTexInfo[] = { { 17, aMenuSignCourseEditTex, 64, 86, 0x1016 }, { 0 } };

// CREATE MACHINE
unk_80077D50 sMenuSignCreateMachineCompTexInfo[] = { { 17, aMenuSignCreateMachineTex, 64, 86, 0x1012 }, { 0 } };

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
static unk_80077D50 sTitleBackgroundMainCompTexInfo[] = { { 17, aTitleBackgroundMainTex, 304, 240, 0x14A5D }, { 0 } };

// COMIC STRIP
static unk_80077D50 sTitleBackgroundComicCompTexInfo[] = { { 17, aTitleBackgroundComicTex, 320, 240, 0x118DB }, { 0 } };

// BLUE FALCON, SEMI-TRANSPARENT
static unk_80077D50 sTitleBackgroundFalconCompTexInfo[] = { { 17, aTitleBackgroundFalconTex, 320, 240, 0x9E0A },
                                                            { 0 } };

static unk_80077D50* sTitleBackgroundCompTexInfos[] = {
    sTitleBackgroundMainCompTexInfo,
    sTitleBackgroundComicCompTexInfo,
    sTitleBackgroundFalconCompTexInfo,
};

/*
    MENU SECOND OPTIONS
 */

// SELECT MODE
unk_80077D50 sSelectModeCompTexInfo[] = { { 4, aSelectModeTex, 128, 24, 0 }, { 0 } };

// FLAMES
unk_80077D50 sSelectModeOptionFlamesCompTexInfo[] = { { 17, aSelectModeOptionFlamesTex, 128, 80, 0x2A0E }, { 0 } };

// NOVICE
static unk_80077D50 sNoviceCompTexInfo[] = { { 17, aNoviceTex, 64, 18, 0x144 }, { 0 } };

// STANDARD
static unk_80077D50 sStandardCompTexInfo[] = { { 17, aStandardTex, 64, 18, 0x14C }, { 0 } };

// EXPERT
static unk_80077D50 sExpertCompTexInfo[] = { { 17, aExpertTex, 64, 18, 0x149 }, { 0 } };

// MASTER
static unk_80077D50 sMasterCompTexInfo[] = { { 17, aMasterTex, 64, 18, 0x14E }, { 0 } };

// 2 PLAYERS
unk_80077D50 s2PlayersCompTexInfo[] = { { 17, a2PlayersTex, 64, 18, 0x146 }, { 0 } };

// 3 PLAYERS
unk_80077D50 s3PlayersCompTexInfo[] = { { 17, a3PlayersTex, 64, 18, 0x142 }, { 0 } };

// 4 PLAYERS
unk_80077D50 s4PlayersCompTexInfo[] = { { 17, a4PlayersTex, 64, 18, 0x143 }, { 0 } };

// TIME ATTACK
unk_80077D50 sTimeAttackCompTexInfo[] = { { 18, aTimeAttackTex, 88, 18, 0x1B1 }, { 0 } };

// RECORDS
unk_80077D50 sRecordsOptionCompTexInfo[] = { { 17, aRecordsOptionTex, 64, 18, 0x149 }, { 0 } };

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
static unk_80077D50 sOkCompTexInfo[] = { { 17, aOKTex, 32, 16, 0x112 }, { 0 } };

extern u32 gGameFrameCount;
extern s16 D_800CCFE8;
extern s32 gNumPlayers;
extern u32 D_800CD384;

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
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_1, 0, 0, 0xA);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_2, 0, 0, 0xA);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_3, 0, 0, 0xA);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_4, 0, 0, 0xA);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_5, 0, 0, 0xA);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_6, 0, 0, 0xA);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_7, 0, 0, 0xA);
    Object_Init(OBJECT_MAIN_MENU_HEADER, 0x64, 0xD, 0xA);
    Object_Init(OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS, 0x60, 0x50, 0xE);
    Object_Init(OBJECT_MAIN_MENU_OK, 0, 0, 0xE);
    Object_Init(OBJECT_MAIN_MENU_SELECT_DIFFICULTY, 0x60, 0x50, 0xE);
    Object_Init(OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE, 0x60, 0x50, 0xE);
}

extern unk_800DCE48 D_800DCE48;
extern s32 gModeSubOption[];
extern char* gTrackNames[];

extern s32 gNumPlayers;
extern s32 gDifficulty;
extern s16 D_800CD044;
extern s16 D_800CD048;
extern s32 gSelectedMode;
extern s8 D_800CD3C0;
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
    if (Object_Get(OBJECT_MAIN_MENU_BACKGROUND)->unk_04 >= 3) {
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
            if ((gSelectedMode == MODE_VS_BATTLE) && (gControllersConnected < 2)) {
                gSelectedMode = MODE_DEATH_RACE;
            }
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

            if ((gInputButtonPressed & BTN_START) && (Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)->unk_04 == 7)) {
                break;
            }

            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_800BA8D8(0x3E);
                D_800DCE48.unk_10 = (Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)->unk_1C & 0xFFFF) - 0x997A;
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
                        gCourseIndex = 54;
                        gCurrentTrackName = gTrackNames[gCourseIndex];
                        gNumPlayers = 1;
                        func_800BB324(gNumPlayers - 1);
                        gDifficulty = D_800DCE48.unk_10 + MASTER;
                        return GAMEMODE_FLX_MACHINE_SELECT;
                    case MODE_OPTIONS:
                        D_800CD384 = 5;
                        D_800CD048 = 0xD;
                        break;
                    case MODE_COURSE_EDIT:
                        D_800CD384 = 5;
                        return GAMEMODE_D;
                    case MODE_CREATE_MACHINE:
                        D_800CD384 = 5;
                        return GAMEMODE_10;
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
            if ((D_800CD3C0 < 2) && !gSettingEverythingUnlocked) {
                if (gDefaultSubOptionLimits[gSelectedMode] < gModeSubOption[gSelectedMode]) {
                    gModeSubOption[gSelectedMode] = gDefaultSubOptionLimits[gSelectedMode];
                }
            } else {
                if (gMaxSubOptionLimits[gSelectedMode] < gModeSubOption[gSelectedMode]) {
                    gModeSubOption[gSelectedMode] = gMaxSubOptionLimits[gSelectedMode];
                }
            }
            if (gSelectedMode == MODE_VS_BATTLE && (gControllersConnected < gModeSubOption[gSelectedMode] + 2)) {
                gModeSubOption[gSelectedMode] = gControllersConnected - 2;
                if (gModeSubOption[gSelectedMode] < 0) {
                    gModeSubOption[gSelectedMode] = 0;
                    D_800CD384 = 0;
                    func_800BA8D8(0x10);
                    break;
                }
            }

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
                       (Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)->unk_04 == 7)) {
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
                        gDifficulty = D_800DCE48.unk_10 + gModeSubOption[gSelectedMode];
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
            if ((gInputButtonPressed & BTN_START) && (Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)->unk_04 == 7)) {
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
            if (Object_Get(OBJECT_MAIN_MENU_MODE_SIGN_3)->unk_1C == 12) {
                var_v1_2 = false;
                switch (gSelectedMode) {
                    case MODE_TIME_ATTACK:
                        if (Object_Get(OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE)->unk_1C == 12) {
                            var_v1_2 = true;
                        }
                        break;
                    case MODE_GP_RACE:
                    case MODE_PRACTICE:
                        if (Object_Get(OBJECT_MAIN_MENU_SELECT_DIFFICULTY)->unk_1C == 12) {
                            var_v1_2 = true;
                        }
                        break;
                    case MODE_VS_BATTLE:
                        if (Object_Get(OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS)->unk_1C == 12) {
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
                D_800CD048 = 0xB;
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

    backgroundObj->unk_04 = D_800CD3C4;
    func_80077D50(sTitleBackgroundCompTexInfos[backgroundObj->unk_04], 0);

    switch (backgroundObj->unk_04) {
        case 0:
            backgroundObj->left = 8;
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
    if (D_800CD044 == 0x21) {
        signObj->unk_1C = 0xC;
    }
}

void MainMenu_HeaderInit(Object* headerObj) {

    func_80077D50(sSelectModeCompTexInfo, 0);
    if (D_800CD044 == 0x21) {
        headerObj->unk_1C = 0xC;
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
    okObj->left = 50;
}

s32 func_i6_8011DBD0(void);

void MainMenu_UnlockEverythingInit(Object* unlockEverythingObj) {
    unlockEverythingObj->unk_1C = func_i6_8011DBD0();
}

extern u32 gGameFrameCount;
extern s32 gSelectedMode;

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

    switch ((s32) D_800CD384) {
        case 3:
        case 4:
            if (++signObj->unk_1C > 12) {
                signObj->unk_1C = 12;
            }
            break;
        default:
            if (signObj->unk_1C > 0) {
                signObj->unk_1C--;
            }
            break;
    }

    if (signObj->unk_1C < 0) {
        signObj->unk_1C = 0;
    }

    temp1 = (((mode % 4) * 0x40) - (SQ(signObj->unk_1C) * 2)) + 0x20;
    temp2 = ((mode / 4) * 0x5B) + 0x26;

    return func_80078EA0(gfx, sMenuSignCompTexInfos[mode], temp1, temp2, 1, 0, 0, 1.0f, 1.0f);
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

    if (backgroundObj->unk_04 < 3) {
        sp44 = sTitleBackgroundCompTexInfos[backgroundObj->unk_04];
        gfx = func_80078EA0(gfx, sp44, backgroundObj->left, backgroundObj->top, 0, 0, 0, 1.0f, 1.0f);
        gfx = func_8007A440(gfx, backgroundObj->left, backgroundObj->top, backgroundObj->left + sp44->width,
                            backgroundObj->top + sp44->height, D_i6_8011DC60, D_i6_8011DC64, D_i6_8011DC68,
                            D_i6_8011DC6C);
    } else {
        sp44 = sTitleBackgroundCompTexInfos[D_800CD3C4];
        gfx = func_80078EA0(gfx, sp44, backgroundObj->left, backgroundObj->top, 0, 0, 0, 1.0f, 1.0f);
        var_t1 = (backgroundObj->unk_04 / 10);
        var_ra = sTitleBackgroundCompTexInfos[var_t1 - 1];

        texture = func_800783AC(var_ra->unk_04);

        sp58 = backgroundObj->left;
        sp54 = backgroundObj->top;
        gSPDisplayList(gfx++, D_3000088);

        switch (backgroundObj->unk_04) {
            case 10:
            case 20:
                backgroundObj->unk_1C += 4;
                break;
            case 11:
            case 21:
                alpha = 0;

                backgroundObj->unk_1C++;

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
                backgroundObj->unk_1C += 4;
                break;
        }

        for (var_t1 = 0; var_t1 < 240; var_t1++) {

            switch (backgroundObj->unk_04) {
                case 10:
                case 20:
                    if (var_t1 < backgroundObj->unk_1C) {
                        // alpha variable re-used with different purpose here
                        alpha = SQ(backgroundObj->unk_1C - var_t1) / 32;
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
                    i = ((((var_t1 * 0x1000) * (backgroundObj->unk_1C + 64)) / 64) / 240);
                    sp50 = (SIN(i) * backgroundObj->unk_1C);
                    alpha = 255 - backgroundObj->unk_1C;
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

        gfx = func_8007A440(gfx, backgroundObj->left, backgroundObj->top, backgroundObj->left + sp44->width,
                            backgroundObj->top + sp44->height, D_i6_8011DC60, D_i6_8011DC64, D_i6_8011DC68,
                            D_i6_8011DC6C);
        switch (backgroundObj->unk_04) {
            case 10:
            case 20:
                if (D_i6_8011F910[SCREEN_HEIGHT - 1] >= SCREEN_WIDTH) {
                    backgroundObj->unk_04 = D_800CD3C4;
                }
                break;
            case 11:
            case 21:
                if (backgroundObj->unk_1C > 80) {
                    backgroundObj->unk_04 = D_800CD3C4;
                }
                break;
            case 12:
            case 22:
                if (backgroundObj->unk_1C > 256) {
                    backgroundObj->unk_04 = D_800CD3C4;
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
            if (++headerObj->unk_1C > 12) {
                headerObj->unk_1C = 12;
            }
            break;
        default:
            if (headerObj->unk_1C > 0) {
                headerObj->unk_1C--;
            }
            break;
    }

    if (headerObj->unk_1C < 0) {
        headerObj->unk_1C = 0;
    }

    temp = SQ(headerObj->unk_1C) * 2;

    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    return func_80078EA0(gfx, sSelectModeCompTexInfo, headerObj->left - temp, headerObj->top, 0, 0, 0, 1.0f, 1.0f);
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
            numPlayersObj->unk_1C = -12;
            break;
        case 3:
        case 4:
            if (++numPlayersObj->unk_1C > 12) {
                numPlayersObj->unk_1C = 12;
            }
            break;
        default:
            if (numPlayersObj->unk_1C > 0) {
                numPlayersObj->unk_1C--;
            }
            if (numPlayersObj->unk_1C < 0) {
                numPlayersObj->unk_1C++;
            }
            break;
    }
    temp_s7 = SQ(numPlayersObj->unk_1C) * 2;
    gfx = func_80078EA0(gfx, sSelectModeOptionFlamesCompTexInfo, numPlayersObj->left - temp_s7, numPlayersObj->top, 0,
                        0, 0, 1.0f, 1.0f);

    for (i = 0; i < 3; i++) {
        if (gModeSubOption[gSelectedMode] == i) {
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
            if ((gControllersConnected - 2) < i) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 128);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
        }
        gfx = func_80078EA0(gfx, sNumPlayersCompTexInfos[i], (numPlayersObj->left - temp_s7) + 0x20,
                            numPlayersObj->top + (i * 20) + 0xC, 1, 0, 0, 1.0f, 1.0f);
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
            difficultyObj->unk_1C = -12;
            break;
        case 3:
        case 4:
            if (++difficultyObj->unk_1C > 12) {
                difficultyObj->unk_1C = 12;
            }
            break;
        default:
            if (difficultyObj->unk_1C > 0) {
                difficultyObj->unk_1C--;
            }
            if (difficultyObj->unk_1C < 0) {
                difficultyObj->unk_1C++;
            }
            break;
    }

    temp_s6 = SQ(difficultyObj->unk_1C) * 2;
    gfx = func_80078EA0(gfx, sSelectModeOptionFlamesCompTexInfo, difficultyObj->left - temp_s6, difficultyObj->top, 0,
                        0, 0, 1.0f, 1.0f);

    for (i = 0; i < 4; i++) {
        if (gModeSubOption[gSelectedMode] == i) {
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
        if ((D_800CD3C0 < 2) && (gSettingEverythingUnlocked == 0)) {
            if (i < 3) {
                gfx = func_80078EA0(gfx, sDifficultyCompTexInfos[i], (difficultyObj->left - temp_s6) + 0x20,
                                    difficultyObj->top + (i * 20) + 0xE, 1, 0, 0, 1.0f, 1.0f);
            }
        } else {
            gfx = func_80078EA0(gfx, sDifficultyCompTexInfos[i], (difficultyObj->left - temp_s6) + 0x20,
                                difficultyObj->top + (i * 18) + 7, 1, 0, 0, 1.0f, 1.0f);
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
            timeAttackModeObj->unk_1C = -12;
            break;
        case 3:
        case 4:
            if (++timeAttackModeObj->unk_1C > 12) {
                timeAttackModeObj->unk_1C = 12;
            }
            break;
        case 6:
        default:
            if (timeAttackModeObj->unk_1C > 0) {
                timeAttackModeObj->unk_1C--;
            }
            if (timeAttackModeObj->unk_1C < 0) {
                timeAttackModeObj->unk_1C++;
            }
            break;
    }

    temp_s7 = SQ(timeAttackModeObj->unk_1C) * 2;
    gfx = func_80078EA0(gfx, sSelectModeOptionFlamesCompTexInfo, timeAttackModeObj->left - temp_s7,
                        timeAttackModeObj->top, 0, 0, 0, 1.0f, 1.0f);

    for (i = 0; i < 2; i++) {
        if (gModeSubOption[MODE_TIME_ATTACK] == i) {
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
        temp_a1 = sTimeAttackModeCompTexInfos[i];
        gfx = func_80078EA0(gfx, temp_a1, (((s32) (0x80 - temp_a1->width) / 2) + timeAttackModeObj->left) - temp_s7,
                            timeAttackModeObj->top + (i * 28) + 0x15, 1, 0, 0, 1.0f, 1.0f);
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
            gfx = func_80078EA0(gfx, sOkCompTexInfo, okObj->left + 0x10B, okObj->top + 0xD0, 1, 0, 0, 1.0f, 1.0f);
            break;
        default:
            gfx = func_8007DB28(gfx, 0);
            gfx = func_80078EA0(gfx, sOkCompTexInfo, okObj->left + 0x10B, okObj->top + 0xD0, 1, 0, 0, 1.0f, 1.0f);
            break;
    }
    return gfx;
}

void MainMenu_OkUpdate(Object* okObj) {

    switch (D_800CD384) {
        case 2:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 0, 192);
            okObj->unk_1C = 9;
            break;
        case 3:
        case 4:
            if (okObj->unk_1C != 0) {
                okObj->unk_1C--;
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

void MainMenu_UnlockEverythingUpdate(Object* unlockEverythingObj) {
    Object* sp1C;

    if ((unlockEverythingObj->unk_04 < 8) && (gInputButtonPressed != 0)) {
        if (gUnlockEverythingInputs[unlockEverythingObj->unk_04] & gInputPressed) {
            if (++unlockEverythingObj->unk_04 == 8) {
                gSettingEverythingUnlocked = 1;
                Save_SaveSettingsProfiles();
                func_800BA8D8(0x2E);
                sp1C = Object_Get(OBJECT_MAIN_MENU_BACKGROUND);
                if (sp1C->unk_04 < 2) {
                    sp1C->unk_04 = (Math_Rand1() % 3) + (sp1C->unk_04 * 10) + 10;
                }
            }
        } else {
            if (gUnlockEverythingInputs[0] & gInputButtonPressed) {
                unlockEverythingObj->unk_04 = 1;
            } else {
                unlockEverythingObj->unk_04 = 0;
            }
        }
    }
}
