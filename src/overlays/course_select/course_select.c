#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "src/overlays/ovl_i2/ovl_i2.h"
#include "course_select.h"
#include "assets/segment_2B9EA0.h"

/* potentially in a shared data file */
Vp D_i5_80118FF0[2][6] = { 0 };
s32 gCourseModelCupType = 0;
s32 D_i5_801190B4 = 0;
s32 gCourseModelCupCourseNo = 0;
UNUSED s32 D_i5_801190BC = 0;

s32 D_i5_801190C0 = 0;
UNUSED s32 D_i5_801190C4 = 0;
s8 gCupSelectOption = 0;
s8 sCourseSelectTrackNo = 0;
s8 D_i5_801190D0 = 0;
s8 sSelectedGhostOption = 0;
s8 sUnlockedGhosts = 1;
s8 sStaffGhostTimeBeaten = 0;
UNUSED s32 D_i5_801190E0 = 64;
UNUSED s32 D_i5_801190E4 = 0;
UNUSED s32 D_i5_801190E8 = 60;
UNUSED s32 D_i5_801190EC = 40;
UNUSED s32 D_i5_801190F0 = 70;

unk_80077D50 sCupSelectJackCompTexInfo[] = { { 17, aCupSelectJackTex, 64, 96, 0x6DF }, { 0 } };
unk_80077D50 sCupSelectQueenCompTexInfo[] = { { 17, aCupSelectQueenTex, 64, 96, 0x72D }, { 0 } };
unk_80077D50 sCupSelectKingCompTexInfo[] = { { 17, aCupSelectKingTex, 64, 96, 0x738 }, { 0 } };
unk_80077D50 sCupSelectJokerCompTexInfo[] = { { 17, aCupSelectJokerTex, 64, 96, 0x6D4 }, { 0 } };
unk_80077D50 sCupSelectXCompTexInfo[] = { { 17, aCupSelectXTex, 64, 96, 0x6C5 }, { 0 } };
unk_80077D50 sCupSelectEditCompTexInfo[] = { { 17, aCupSelectEditTex, 64, 64, 0x483 }, { 0 } };
unk_80077D50 sCupSelectQuestionMarkCompTexInfo[] = { { 17, aCupSelectQuestionMarkTex, 64, 96, 0x7CE }, { 0 } };

unk_80077D50* sCupSelectCompTexInfos[] = {
    sCupSelectJackCompTexInfo,         sCupSelectQueenCompTexInfo, sCupSelectKingCompTexInfo,
    sCupSelectJokerCompTexInfo,        sCupSelectXCompTexInfo,     sCupSelectEditCompTexInfo,
    sCupSelectQuestionMarkCompTexInfo,
};

unk_80077D50 sSelectCourseCompTexInfo[] = { { 4, aSelectCourseTex, 160, 24, 0 }, { 0 } };
unk_80077D50 sRecordsCompTexInfo[] = { { 4, aRecordsTex, 96, 24, 0 }, { 0 } };
static unk_80077D50 sOKCompTexInfo[] = { { 17, aOKTex, 32, 16, 0x112 }, { 0 } };
unk_80077D50 sYellowArrowCompTexInfo[] = { { 17, aYellowArrowTex, 32, 32, 0x120 }, { 0 } };
unk_80077D50 sOptionsFalconHelmetCompTexInfo[] = { { 17, aOptionsFalconHelmetTex, 64, 64, 0x9E8 }, { 0 } };

static unk_80077D50 sTitleBackgroundMainCompTexInfo[] = { { 17, aTitleBackgroundMainTex, 304, 240, 0x14A5D }, { 0 } };
static unk_80077D50 sTitleBackgroundComicCompTexInfo[] = { { 17, aTitleBackgroundComicTex, 320, 240, 0x118DB }, { 0 } };
static unk_80077D50 sTitleBackgroundFalconCompTexInfo[] = { { 17, aTitleBackgroundFalconTex, 320, 240, 0x9E0A },
                                                            { 0 } };

static unk_80077D50* sTitleBackgroundCompTexInfos[] = {
    sTitleBackgroundMainCompTexInfo,
    sTitleBackgroundComicCompTexInfo,
    sTitleBackgroundFalconCompTexInfo,
};

unk_80077D50 sCupCleared1CompTexInfo[] = { { 17, aCupCleared1Tex, 16, 16, 0x75 }, { 0 } };
unk_80077D50 sCupCleared2CompTexInfo[] = { { 17, aCupCleared2Tex, 16, 16, 0x75 }, { 0 } };
unk_80077D50 sCupCleared3CompTexInfo[] = { { 17, aCupCleared3Tex, 16, 16, 0x76 }, { 0 } };
unk_80077D50 sCupCleared4CompTexInfo[] = { { 17, aCupCleared4Tex, 16, 16, 0x75 }, { 0 } };

unk_80077D50* sCupClearedDifficultyCompTexInfos[] = {
    sCupCleared1CompTexInfo,
    sCupCleared2CompTexInfo,
    sCupCleared3CompTexInfo,
    sCupCleared4CompTexInfo,
};

unk_80077D50 sHasGhostMarkerCompTexInfo[] = { { 4, aHasGhostMarkerTex, 32, 16, 0 }, { 0 } };
unk_80077D50 sStaffGhostBeatenCompTexInfo[] = { { 17, aStaffGhostBeatenTex, 16, 16, 0x75 }, { 0 } };

unk_80077D50 sMenuWithGhostCompTexInfo[] = { { 4, aMenuWithGhostTex, 64, 16, 0 }, { 0 } };
unk_80077D50 sMenuWithoutGhostCompTexInfo[] = { { 4, aMenuWithoutGhostTex, 64, 16, 0 }, { 0 } };
unk_80077D50 sMenuStaffGhostCompTexInfo[] = { { 4, aMenuStaffGhostTex, 64, 16, 0 }, { 0 } };
unk_80077D50 sMenuCelebrityGhostCompTexInfo[] = { { 4, aMenuCelebrityGhostTex, 64, 16, 0 }, { 0 } };
unk_80077D50 sMenuChampGhostCompTexInfo[] = { { 4, aMenuChampGhostTex, 64, 16, 0 }, { 0 } };

unk_80077D50* sTimeAttackGhostOptionCompTexInfos[] = {
    sMenuWithGhostCompTexInfo,      sMenuWithoutGhostCompTexInfo, sMenuStaffGhostCompTexInfo,
    sMenuCelebrityGhostCompTexInfo, sMenuChampGhostCompTexInfo,
};

// clang-format off
s32 sCourseSelectCupColors[] = {
    192, 64,  64,
    100, 150, 255,
    255, 255, 100,
    0,   255, 0,
    200, 90,  255,
    200, 90,  255
};
// clang-format on

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

s8 D_i5_80119544[] = { 1, 0, 2, 3, 4 };

s32 sCourseSelectCup;
s32 D_i5_801197E4;

extern s32 gCourseIndex;

void func_i5_80116830(void) {
    GhostInfo sp28;
    s32 pad;

    if (D_i5_801197E4 != gCourseIndex) {
        sStaffGhostTimeBeaten = false;
        if (Save_LoadStaffGhostRecord(&sp28, gCourseIndex) != 0) {
            sUnlockedGhosts = 1;
        } else {
            // Within 115% of staff ghost time
            if (gCourseRecordInfos[gCourseIndex].timeRecord[0] < ((sp28.raceTime * 115) / 100)) {
                sUnlockedGhosts = 2;
            } else {
                sUnlockedGhosts = 1;
            }
            if (gCourseRecordInfos[gCourseIndex].timeRecord[0] < sp28.raceTime) {
                sStaffGhostTimeBeaten = true;
            }
        }
        D_i5_801197E4 = gCourseIndex;
    }
}

extern char* gCurrentTrackName;
extern char* gTrackNames[];

void func_i5_80116910(void) {
    gCurrentTrackName = gTrackNames[gCourseIndex];
}

extern s16 D_800CCFE8;
extern s32 gSelectedMode;
extern s32 D_800CD3B8;
extern s32 D_800CD3BC;
extern s8 D_800CD3C0;
extern s8 gSettingEverythingUnlocked;
extern s32 gCurrentGhostType;
extern s32 gGameMode;

void CourseSelect_Init(void) {
    s32 var_a1;
    s32 var_a2;
    s32 var_v0;
    s32 var_v1;

    D_800CCFE8 = 3;
    sSelectedGhostOption = D_i5_80119544[gCurrentGhostType];
    D_i5_801197E4 = -1;
    if (gGameMode == GAMEMODE_FLX_COURSE_SELECT) {
        var_v0 = D_800CD3B8;
    } else {
        var_v0 = D_800CD3BC;
    }
    if (var_v0 >= 48) {
        gCupSelectOption = 4;
        sCourseSelectTrackNo = 0;
        gCourseIndex = 48;
    } else {
        sCourseSelectTrackNo = var_v0 % 6;
        if (var_v0 >= 24) {
            gCupSelectOption = 10;
        } else {
            gCupSelectOption = var_v0 / 6;
        }
        gCourseIndex = var_v0;
    }
    func_i5_80116830();
    var_v1 = D_800CD3C0;
    if ((var_v1 >= 3) || (gSettingEverythingUnlocked != 0)) {
        var_v1 = 2;
    }

    if (var_v1 + 2 < gCupSelectOption) {
        gCupSelectOption = var_v1 + 2;
    }
    if ((gCupSelectOption == 4) &&
        ((gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) || (gSelectedMode == MODE_TIME_ATTACK))) {
        gCupSelectOption = 3;
    }
    if (gCupSelectOption >= 10) {
        sCourseSelectCup = X_CUP;
    } else if (gCupSelectOption == 4) {
        sCourseSelectCup = EDIT_CUP;
    } else {
        sCourseSelectCup = gCupSelectOption;
    }

    func_80085610();
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_COURSE_SELECT_BACKGROUND, 0, 0, 2);
    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        var_a1 = 80;
        var_a2 = 17;
    } else {
        var_a1 = 112;
        var_a2 = 21;
    }
    Object_Init(OBJECT_COURSE_SELECT_HEADER, var_a1, var_a2, 4);
    Object_Init(OBJECT_COURSE_SELECT_OK, 0, 0, 10);
    Object_Init(OBJECT_COURSE_SELECT_MODEL, 0, 0, 8);
    if (((gSettingEverythingUnlocked != 0) || (D_800CD3C0 >= 2)) && (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) &&
        (gSelectedMode != MODE_TIME_ATTACK)) {
        Object_Init(OBJECT_COURSE_SELECT_CUP_4, 0, -100, 6);
    }
    if ((D_800CD3C0 > 0) || (gSettingEverythingUnlocked != 0)) {
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
    D_i5_801190C0 = 10;
    if (gCourseIndex >= 48) {
        gCupSelectOption = 4;
        sCourseSelectTrackNo = gCourseIndex % 6;
    } else {
        sCourseSelectTrackNo = gCourseIndex % 6;
        if (gCourseIndex >= 24) {
            gCupSelectOption = 10;
        } else {
            gCupSelectOption = gCourseIndex / 6;
        }
    }
    func_i5_80116910();
    if (gCupSelectOption >= 10) {
        sCourseSelectCup = X_CUP;
    } else if (gCupSelectOption == 4) {
        sCourseSelectCup = EDIT_CUP;
    } else {
        sCourseSelectCup = gCupSelectOption;
    }
    func_80085610();
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_COURSE_SELECT_BACKGROUND, 0, 0, 2);
    Object_Init(OBJECT_COURSE_SELECT_MODEL, 0, 0, 8);
    if (gCupSelectOption >= 10) {
        Object_Init(OBJECT_COURSE_SELECT_CUP_5, 0, -100, 6);
    } else {
        Object_Init(OBJECT_COURSE_SELECT_CUP_0 + gCupSelectOption, 0, -100, 6);
    }
    Object_Init(OBJECT_COURSE_SELECT_NAME, 0, 0, 8);
}

void func_i5_80116658(s32 arg0);

extern s32 gCupType;
extern s16 D_800CD044;
extern s16 D_800CD048;
extern Controller gSharedController;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;
extern unk_struct_1DC D_800E5220[];
extern s32 D_i2_80106DA4;

s32 CourseSelect_Update(void) {
    s32 pad[2];
    s32 originalCupSelectOption;
    s8 originalSelectedGhostOption;
    s32 unlockedGhost;
    s32 var_v1;
    Object* temp_v0_2;

    func_8008675C();
    if (D_i2_80106DA4 != 0) {
        return gGameMode;
    }
    if ((gSelectedMode == MODE_TIME_ATTACK) && (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT)) {
        func_i5_80116830();
    }
    Controller_SetGlobalInputs(&gSharedController);
    switch (D_i5_801190C0) {
        case 0:
            D_i5_801190D0 = 1;
            originalCupSelectOption = gCupSelectOption;
            if (gCupSelectOption < 10) {
                if ((gInputPressed & BTN_LEFT) && (gCupSelectOption > 0)) {
                    gCupSelectOption--;
                }
                if ((gInputPressed & BTN_RIGHT) && (gCupSelectOption < 4)) {
                    gCupSelectOption++;
                }
                var_v1 = D_800CD3C0;
                if ((var_v1 >= 3) || (gSettingEverythingUnlocked != 0)) {
                    var_v1 = 2;
                }

                if (var_v1 + 2 < gCupSelectOption) {
                    gCupSelectOption = var_v1 + 2;
                }
                if ((gCupSelectOption == 4) &&
                    ((gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) || (gSelectedMode == MODE_TIME_ATTACK))) {
                    gCupSelectOption = 3;
                }
            }
            if (gCupSelectOption >= 10) {
                sCourseSelectCup = X_CUP;
            } else if (gCupSelectOption == 4) {
                sCourseSelectCup = EDIT_CUP;
            } else {
                sCourseSelectCup = gCupSelectOption;
            }
            if (originalCupSelectOption != gCupSelectOption) {
                sCourseSelectTrackNo = 0;
                if (sCourseSelectCup <= X_CUP) {
                    func_i5_80116658(sCourseSelectCup);
                }
                func_800BA8D8(30);
            }
            if (gCupSelectOption < 10) {
                gCupType = gCupSelectOption;
            } else {
                gCupType = EDIT_CUP;
            }
            if (gCupSelectOption >= 10) {
                gCourseIndex = sCourseSelectTrackNo + 24;
            } else if (gCupSelectOption == 4) {
                gCourseIndex = 48;
            } else {
                gCourseIndex = (gCupSelectOption * 6) + sCourseSelectTrackNo;
            }
            if (gInputButtonPressed & BTN_B) {
                func_800BA8D8(0x10);
                if (gGameMode == GAMEMODE_FLX_COURSE_SELECT) {
                    D_800CD3B8 = gCourseIndex;
                    D_i5_801190C0 = 5;
                } else {
                    D_800CD3BC = gCourseIndex;
                    D_i5_801190C0 = 1;
                    D_800CD048 = 10;
                }
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_800BA8D8(0x21);
                if (gCupSelectOption == 4) {
                    sCourseSelectTrackNo = 0;
                    D_i5_801190C0 = 3;
                } else if (gSelectedMode == MODE_GP_RACE) {
                    if (gCupSelectOption >= 10) {
                        gCourseIndex = 24;
                    } else {
                        gCourseIndex = gCupSelectOption * 6;
                    }
                    sCourseSelectTrackNo = 0;
                    D_i5_801190C0 = 3;
                } else {
                    D_i5_801190C0 = 2;
                }
                Object_Get(OBJECT_COURSE_SELECT_MODEL)->left = 400 - (sCourseSelectTrackNo * 0x500);
            }
            break;
        case 2:
            D_i5_801190D0 = 1;
            if ((gSelectedMode == MODE_TIME_ATTACK) && (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT)) {
                unlockedGhost = sUnlockedGhosts;
                originalSelectedGhostOption = sSelectedGhostOption;
                if ((gInputPressed & BTN_UP) && (sSelectedGhostOption > 0)) {
                    sSelectedGhostOption--;
                }
                if ((gInputPressed & BTN_DOWN) && (sSelectedGhostOption < unlockedGhost)) {
                    sSelectedGhostOption++;
                }
                if (originalSelectedGhostOption != sSelectedGhostOption) {
                    func_800BA8D8(30);
                }
                if (unlockedGhost < sSelectedGhostOption) {
                    sSelectedGhostOption = 0;
                }
                gCurrentGhostType = D_i5_80119544[sSelectedGhostOption];
            }

            if ((gInputPressed & BTN_LEFT) && (sCourseSelectTrackNo > 0)) {
                sCourseSelectTrackNo--;
                D_800E5220[0].unk_18 = 1;
                temp_v0_2 = Object_Get(OBJECT_COURSE_SELECT_ARROWS);
                temp_v0_2->unk_04 += 0x200;
                func_800BA8D8(30);
            }

            if ((gInputPressed & BTN_RIGHT) && (sCourseSelectTrackNo < 5)) {
                sCourseSelectTrackNo++;
                D_800E5220[0].unk_18 = 1;
                temp_v0_2 = Object_Get(OBJECT_COURSE_SELECT_ARROWS);
                temp_v0_2->unk_08 += 0x200;
                func_800BA8D8(30);
            }
            if (gCupSelectOption >= 10) {
                gCourseIndex = sCourseSelectTrackNo + 24;
            } else {
                gCourseIndex = (gCupSelectOption * 6) + sCourseSelectTrackNo;
            }
            if (gInputButtonPressed & BTN_B) {
                D_i5_801190C0 = 0;
                func_800BA8D8(0x10);
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_800BA8D8(0x21);
                D_i5_801190C0 = 3;
                D_i5_801190D0 = 0;
            }
            break;
        case 3:
            if (gInputButtonPressed & BTN_B) {
                if ((gSelectedMode == MODE_GP_RACE) || (gCupSelectOption == 4)) {
                    D_i5_801190C0 = 0;
                } else {
                    D_i5_801190C0 = 2;
                }
                func_800BA8D8(0x10);
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_800BA8D8(0x3E);
                D_i5_801190C0 = 4;
                if (gGameMode == GAMEMODE_FLX_COURSE_SELECT) {
                    D_800CD3B8 = gCourseIndex;
                    return GAMEMODE_FLX_MACHINE_SELECT;
                }
                D_800CD3BC = gCourseIndex;
                return GAMEMODE_RECORDS;
            }
            break;
        case 5:
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_800BA8D8(0x21);
                D_i5_801190C0 = 0;
            }
            break;
        case 6:
            if (D_800CD044 == 0) {
                D_800CD048 = 0xC;
            }
            break;
        default:
            break;
    }

    func_i5_80116910();
    return gGameMode;
}

s32 NextCourseSelect_Update(void) {
    func_8008675C();
    Controller_SetGlobalInputs(&gSharedController);
    D_i5_801190D0 = 1;
    switch (D_i5_801190C0) {
        case 10:
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                D_i5_801190C0 = 11;
                func_800BA8D8(0x3E);
                return GAMEMODE_4012;
            }
            break;
        case 11:
        default:
            break;
    }
    return gGameMode;
}

Gfx* CourseSelect_Draw(Gfx* gfx) {
    return Object_UpdateAndDrawAll(gfx);
}

extern s8 D_800CD3C4;

void CourseSelect_BackgroundInit(Object* backgroundObj) {
    size_t var_a1;
    unk_80077D50* sp20;

    backgroundObj->unk_04 = D_800CD3C4;
    sp20 = sTitleBackgroundCompTexInfos[backgroundObj->unk_04];
    func_80077D50(sp20, 0);

    if (backgroundObj->unk_04 == 0) {
        backgroundObj->left = 8;
    }
    if (gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        func_80077D50(sOptionsFalconHelmetCompTexInfo, 0);
        if (backgroundObj->unk_04 == 0) {
            var_a1 = 0x23A00;
        } else {
            var_a1 = 0x25800;
        }

        func_8007A828(func_800783AC(sp20->unk_04), var_a1, 135, 135, 255);
    }
}

void CourseSelect_ModelInit(void) {
    s32 i;

    func_i5_80115DF0();
    if (sCourseSelectCup <= X_CUP) {
        func_i5_80116658(sCourseSelectCup);
        D_i5_801190B4 -= 2;

        for (i = 0; i < 6; i++) {
            func_i5_80116678(gCourseModelCupType);
            D_i5_801190B4--;
        }
    }
}

void CourseSelect_CupInit(Object* cupObj) {
    s32 cupType;
    s32 var_v0;
    s32 i;

    cupType = cupObj->cmdId - OBJECT_COURSE_SELECT_CUP_0;
    if (cupType == JOKER_CUP || cupType == X_CUP) {
        var_v0 = D_800CD3C0;
        if ((var_v0 >= 3) || (gSettingEverythingUnlocked != 0)) {
            var_v0 = 2;
        }
        if (var_v0 < (cupType - 2)) {
            cupType = 6;
        }
    }
    func_80077D50(sCupSelectCompTexInfos[cupType], 0);

    for (i = 0; i < 4; i++) {
        func_80077D50(sCupClearedDifficultyCompTexInfos[i], 0);
    }

    if (D_800CD044 == 0x21) {
        cupObj->unk_1C = 0xC;
    }
    cupObj->left = 0x80;
    cupObj->top = 0x55;
}

void CourseSelect_HeaderInit(Object* headerObj) {
    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        func_80077D50(sSelectCourseCompTexInfo, 0);
        headerObj->unk_1C = 0xC;
    } else {
        func_80077D50(sRecordsCompTexInfo, 0);
    }
}

void CourseSelect_OkInit(Object* okObj) {
    func_80077D50(sOKCompTexInfo, 0);
    okObj->left = 50;
}

void CourseSelect_ArrowsInit(Object* arrowsObj) {
    func_80077D50(sYellowArrowCompTexInfo, 0);
    arrowsObj->unk_04 = 0x80;
    arrowsObj->unk_08 = 0x80;
}

void CourseSelect_GhostMarkerInit(Object* ghostMarkerObj) {
    GhostInfo sp20;
    s32 pad;

    if (Save_LoadGhostInfo(&sp20) != 0) {
        ghostMarkerObj->cmdId = OBJECT_FREE;
    }
    if (sp20.encodedCourseIndex == 0) {
        ghostMarkerObj->cmdId = OBJECT_FREE;
    }
    ghostMarkerObj->left += (sp20.courseIndex % 6) * 320;
    ghostMarkerObj->unk_04 = sp20.courseIndex;
    func_80077D50(sHasGhostMarkerCompTexInfo, 0);
}

void CourseSelect_GhostOptionInit(Object* ghostOptionObj) {
    s32 i;

    func_80077D50(sStaffGhostBeatenCompTexInfo, 0);

    for (i = 0; i < 5; i++) {
        func_80077D50(sTimeAttackGhostOptionCompTexInfos[i], 0);
    }

    ghostOptionObj->left = 150;
}

Gfx* CourseSelect_BackgroundDraw(Gfx* gfx, Object* backgroundObj) {

    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        gDPSetPrimColor(gfx++, 0, 0, 75, 75, 75, 180);
        gfx = func_80078EA0(gfx, sTitleBackgroundCompTexInfos[backgroundObj->unk_04], backgroundObj->left,
                            backgroundObj->top, 1, 0, 0, 1.0f, 1.0f);
    } else {
        gfx = func_80078EA0(gfx, sTitleBackgroundCompTexInfos[backgroundObj->unk_04], backgroundObj->left,
                            backgroundObj->top, 0, 0, 0, 1.0f, 1.0f);
        gfx = func_80078EA0(gfx, sOptionsFalconHelmetCompTexInfo, 0x35, 4, 2, 1, 0, 1.0f, 1.0f);
        gfx = func_80078EA0(gfx, sOptionsFalconHelmetCompTexInfo, 0xCB, 4, 0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

Gfx* CourseSelect_ModelDraw(Gfx* gfx, Object* modelObj) {

    switch (D_i5_801190C0) {
        case 2:
        case 3:
        case 4:
        case 10:
        case 11:
            if (sCourseSelectCup <= X_CUP) {
                gfx = func_i5_80115E64(gfx);
            }
            break;
        case 0:
        default:
            break;
    }
    return gfx;
}

extern u32 gGameFrameCount;
extern s8 gCupNumDifficultiesCleared[];

Gfx* CourseSelect_CupDraw(Gfx* gfx, Object* cupObj) {
    s32 i;
    s32 alpha;
    s32 cupDifficultiesCleared;
    s32 var_s1;
    s32 var_v0;
    s32 sp80;
    s32 var_v1;

    i = cupObj->cmdId - OBJECT_COURSE_SELECT_CUP_0;
    if (gCupSelectOption >= 10) {
        var_s1 = EDIT_CUP;
    } else {
        var_s1 = gCupSelectOption;
    }
    if (var_s1 == i) {
        if ((D_i5_801190C0 == 0) || (D_i5_801190C0 == 1)) {
            var_v1 = gGameFrameCount;
            var_v1 %= 30U;
            if (var_v1 >= 15) {
                var_v1 = 30 - var_v1;
            }
            gDPSetPrimColor(gfx++, 0, 0, 255 - (var_v1 * 5), 255 - (var_v1 * 5), 255 - (var_v1 * 5), 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 100, 100, 100, 255);
    }

    switch (D_i5_801190C0) {
        case 5:
        case 6:
            cupObj->unk_1C++;
            if (cupObj->unk_1C > 12) {
                D_i5_801190C0 = 6;
                cupObj->unk_1C = 12;
            }
            break;
        default:
            if (cupObj->unk_1C > 0) {
                cupObj->unk_1C--;
            }
            break;
    }

    if (cupObj->unk_1C < 0) {
        cupObj->unk_1C = 0;
    }

    cupDifficultiesCleared = gCupNumDifficultiesCleared[i];
    sp80 = (SQ(cupObj->unk_1C) * 3) / 2;

    switch (i) {
        case JOKER_CUP:
        case X_CUP:
            var_v0 = D_800CD3C0;
            if ((var_v0 >= 3) || (gSettingEverythingUnlocked != 0)) {
                var_v0 = 2;
            }
            if (var_v0 < (i - 2)) {
                i = 6;
            }
            break;
    }

    gfx = func_80078EA0(gfx, sCupSelectCompTexInfos[i], cupObj->left, cupObj->top + sp80, 1, 0, 0, 1.0f, 1.0f);

    if ((gSelectedMode == MODE_GP_RACE) && (i <= JOKER_CUP)) {
        alpha = ((cupObj->top - 49) * 255) / 36;
        if (var_s1 == i) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
        }

        for (i = 0; i < cupDifficultiesCleared; i++) {
            gfx = func_80078EA0(gfx, sCupClearedDifficultyCompTexInfos[i], cupObj->left + (i * 16) + ((12 - i * 8) / 2),
                                (cupObj->top + sp80) - 12, 1, 0, 0, 1.0f, 1.0f);
        }
    }
    return gfx;
}

Gfx* CourseSelect_HeaderDraw(Gfx* gfx, Object* headerObj) {
    s32 temp_v1;

    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        switch (D_i5_801190C0) {
            case 5:
            case 6:
                headerObj->unk_1C++;
                if (headerObj->unk_1C > 12) {
                    D_i5_801190C0 = 6;
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
        temp_v1 = (SQ(headerObj->unk_1C) * 3) / 2;

        gfx = func_80078EA0(gfx, sSelectCourseCompTexInfo, headerObj->left, headerObj->top + temp_v1, 0, 0, 0, 1.0f,
                            1.0f);
    } else {
        gfx = func_80078EA0(gfx, sRecordsCompTexInfo, headerObj->left, headerObj->top, 0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

Gfx* CourseSelect_OkDraw(Gfx* gfx, Object* okObj) {
    gfx = func_8007DB28(gfx, 0);
    return func_80078EA0(gfx, sOKCompTexInfo, okObj->left + 0x10B, okObj->top + 0xD0, 1, 0, 0, 1.0f, 1.0f);
}

Gfx* CourseSelect_ArrowsDraw(Gfx* gfx, Object* arrowsObj) {
    f32 temp_fv0 = (SIN(arrowsObj->unk_1C) + 1.0) / 2;
    f32 temp_fa1 = (SIN(arrowsObj->unk_20) + 1.0) / 2;

    // left and top represent x positions for left and right arrows for this object
    gfx = func_80078EA0(gfx, sYellowArrowCompTexInfo, arrowsObj->left + 0x2B, (((1.0 - temp_fv0) * 16.0) + 112.0), 3, 0,
                        0, 1.0f, temp_fv0);
    return func_80078EA0(gfx, sYellowArrowCompTexInfo, arrowsObj->top + 0xF5, (((1.0 - temp_fa1) * 16.0) + 112.0), 5, 0,
                         0, 1.0f, temp_fa1);
}

Gfx* CourseSelect_NameDraw(Gfx* gfx) {
    char cupTrackNoStr[4];
    s32 cupTrackNoWidth;
    s32 trackNameWidth;
    s32* cupColors;

    switch (D_i5_801190C0) {
        case 0:
        default:
            break;
        case 2:
        case 3:
        case 4:
        case 10:
        case 11:
            Font_IntToString(sCourseSelectTrackNo + 1, cupTrackNoStr);
            cupTrackNoStr[1] = ':';
            cupTrackNoStr[2] = ' ';
            cupTrackNoStr[3] = '\0';
            cupTrackNoWidth = Font_GetStringWidth(cupTrackNoStr, FONT_SET_3, 0);
            if (sCourseSelectCup == EDIT_CUP) {
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
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
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

    // If Cup Does Not Match
    if ((ghostMarkerObj->unk_04 / 6) != (gCourseIndex / 6)) {
        return gfx;
    }

    switch (D_i5_801190C0) {
        case 0:
        case 1:
        case 5:
        case 6:
            break;
        case 2:
        case 3:
        case 4:
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = func_80078EA0(gfx, sHasGhostMarkerCompTexInfo, ghostMarkerObj->left + ghostMarkerObj->unk_1C,
                                ghostMarkerObj->top, 0, 0, 0, 1.0f, 1.0f);
            break;
    }

    return gfx;
}

Gfx* CourseSelect_GhostOptionDraw(Gfx* gfx, Object* ghostOptionObj) {
    s32 i;
    s32 numUnlockedGhosts = sUnlockedGhosts + 1;

    for (i = 0; i < numUnlockedGhosts; i++) {
        if (i == sSelectedGhostOption) {
            switch (D_i5_801190C0) {
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
        gfx = func_80078EA0(gfx, sTimeAttackGhostOptionCompTexInfos[i], ghostOptionObj->left + 0xC3, i * 20 + 0x2D, 0,
                            0, 0, 1.0f, 1.0f);

        if ((i == 2) && sStaffGhostTimeBeaten) {
            gfx = func_80078EA0(gfx, sStaffGhostBeatenCompTexInfo, ghostOptionObj->left + 0x109, i * 20 + 0x2D, 0, 0, 0,
                                1.0f, 1.0f);
        }
    }
    return gfx;
}

void CourseSelect_ModelUpdate(Object* modelObj) {
    s32 temp_a1;

    if (((D_i5_801190C0 != 0) && (D_i5_801190C0 != 1)) || (gCupSelectOption < 4)) {
        func_i5_80115E10();
    }
    temp_a1 = -(sCourseSelectTrackNo * 0x500);
    if (gGameMode == GAMEMODE_FLX_GP_RACE_NEXT_COURSE) {
        modelObj->left = temp_a1;
    } else {
        Object_LerpPosXToClampedTargetMaxStep(modelObj, temp_a1, 0xC0);
    }
    func_i5_801164A8(modelObj->left);
}

void CourseSelect_CupUpdate(Object* arg0) {
    s32 var_v1;
    s32 var_a1;
    s32 var_v0;

    if (gGameMode == GAMEMODE_FLX_GP_RACE_NEXT_COURSE) {
        arg0->left = 0x80;
        arg0->top = 0x31;
        return;
    }

    var_v1 = arg0->cmdId - OBJECT_COURSE_SELECT_CUP_0;
    switch (arg0->unk_04) {
        case 0:
            if (var_v1 != 5) {
                if (arg0->top < 85) {
                    Object_LerpPosYToTarget(arg0, 85);
                } else {
                    arg0->unk_04 = 1;
                }
            } else if (arg0->top > 170) {
                Object_LerpPosYToTarget(arg0, 170);
            } else {
                arg0->unk_04 = 1;
            }
            if ((D_i5_801190C0 != 0) && (D_i5_801190C0 != 1)) {
                arg0->unk_04 = 1;
            }
            break;
        case 1:
        case 2:
        case 3:
            if ((var_v1 == gCupSelectOption) || ((gCupSelectOption >= 10) && (var_v1 == 5))) {
                arg0->priority = 7;
            } else {
                arg0->priority = 6;
            }

            switch (D_i5_801190C0) {
                case 0:
                case 1:
                case 5:
                case 6:
                    if (var_v1 != 5) {
                        var_a1 = 85;
                    } else {
                        var_a1 = 170;
                    }
                    Object_LerpPosYToTarget(arg0, var_a1);

                    if (arg0->unk_04 == 2) {
                        arg0->unk_04 = 3;
                    }
                    break;
                case 2:
                case 3:
                case 4:
                default:
                    if (gSelectedMode == MODE_GP_RACE) {
                        Object_LerpPosYToTarget(arg0, 0x31);
                    } else {
                        Object_LerpPosYToTarget(arg0, 0x2D);
                    }
                    arg0->unk_04 = 2;
                    break;
            }
            if ((arg0->unk_04 == 2) || (var_v1 == 5)) {
                var_a1 = 0x80;
            } else {
                var_v0 = D_800CD3C0;
                if (gSettingEverythingUnlocked != 0) {
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
            if (arg0->unk_1C == 0xB) {
                arg0->left = var_a1;
            } else if (arg0->unk_04 >= 2) {
                Object_LerpPosXToClampedTargetMaxStep(arg0, var_a1, 0x80);
            } else {
                Object_LerpPosXToTarget(arg0, var_a1, 0x10 / arg0->unk_04);
            }
            break;
    }
}

void CourseSelect_OkUpdate(Object* arg0) {
    switch (D_i5_801190C0) {
        case 3:
        case 4:
            Object_LerpPosXToClampedTargetMaxStep(arg0, 0, 0xC0);
            break;
        default:
            Object_LerpPosXToClampedTargetMaxStep(arg0, 50, 0xC0);
            break;
    }
}

void CourseSelect_ArrowsUpdate(Object* arg0) {

    switch (D_i5_801190C0) {
        case 0:
        case 1:
        case 5:
        case 6:
            arg0->shouldDraw = false;
            arg0->left = -100;
            arg0->top = 100;
            arg0->unk_04 = 0x80;
            arg0->unk_08 = 0x80;
            break;
        case 2:
        case 3:
        case 4:
        default:
            if (arg0->unk_04 > 640) {
                arg0->unk_04 = 640;
            }
            if (arg0->unk_04 > 128) {
                arg0->unk_04 -= 16;
            } else {
                arg0->unk_04 = 128;
            }
            arg0->unk_1C += arg0->unk_04;

            if (arg0->unk_08 > 640) {
                arg0->unk_08 = 640;
            }
            if (arg0->unk_08 > 128) {
                arg0->unk_08 -= 16;
            } else {
                arg0->unk_08 = 128;
            }
            arg0->unk_20 += arg0->unk_08;

            arg0->shouldDraw = true;
            if ((sCourseSelectTrackNo == 0) || (D_i5_801190C0 == 3) || (D_i5_801190C0 == 4)) {
                Object_LerpPosXToClampedTargetMaxStep(arg0, -100, 0xC0);
            } else {
                Object_LerpPosXToClampedTargetMaxStep(arg0, 0, 0xC0);
            }
            if ((sCourseSelectTrackNo == 5) || (D_i5_801190C0 == 3) || (D_i5_801190C0 == 4)) {
                Object_LerpPosYToClampedTarget(arg0, 100);
            } else {
                Object_LerpPosYToClampedTarget(arg0, 0);
            }
            break;
    }
}

void CourseSelect_GhostMarkerUpdate(Object* arg0) {
    s32 temp_v1;

    arg0->unk_1C = Object_Get(OBJECT_COURSE_SELECT_MODEL)->left >> 2;
    temp_v1 = arg0->left + arg0->unk_1C;

    if ((temp_v1 < -30) || (temp_v1 > 320)) {
        arg0->shouldDraw = false;
    } else {
        arg0->shouldDraw = true;
    }
}

void CourseSelect_GhostOptionUpdate(Object* arg0) {
    switch (D_i5_801190C0) {
        case 0:
        case 1:
        case 5:
        case 6:
            Object_LerpPosXToClampedTargetMaxStep(arg0, 150, 0xC0);
            break;
        case 2:
        case 3:
        case 4:
        default:
            Object_LerpPosXToClampedTargetMaxStep(arg0, 0, 0xC0);
            break;
    }
}
