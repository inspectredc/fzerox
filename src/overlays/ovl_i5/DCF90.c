#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "ovl_i5.h"
#include "assets/segment_2B9EA0.h"

/* potentially in a shared data file */
Vp D_i5_80118FF0[2][6] = { 0 };
s32 D_i5_801190B0 = 0;
s32 D_i5_801190B4 = 0;
s32 D_i5_801190B8 = 0;
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
unk_80077D50 sRecordsArrowCompTexInfo[] = { { 17, aRecordsArrowTex, 32, 32, 0x120 }, { 0 } };
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
extern s32 D_800CD380;
extern s32 D_800CD3B8;
extern s32 D_800CD3BC;
extern s8 D_800CD3C0;
extern s8 gSettingEverythingUnlocked;
extern s32 gCurrentGhostType;
extern s32 gGameMode;

void func_i5_80116934(void) {
    s32 var_a1;
    s32 var_a2;
    s32 var_v0;
    s32 var_v1;

    D_800CCFE8 = 3;
    sSelectedGhostOption = D_i5_80119544[gCurrentGhostType];
    D_i5_801197E4 = -1;
    if (gGameMode == GAMEMODE_800A) {
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
    if ((gCupSelectOption == 4) && ((gGameMode == GAMEMODE_8013) || (D_800CD380 == 1))) {
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
    func_800794B0(OBJECT_5, 0, 0, 1);
    func_800794B0(OBJECT_120, 0, 0, 2);
    if (gGameMode != GAMEMODE_8013) {
        var_a1 = 80;
        var_a2 = 17;
    } else {
        var_a1 = 112;
        var_a2 = 21;
    }
    func_800794B0(OBJECT_131, var_a1, var_a2, 4);
    func_800794B0(OBJECT_128, 0, 0, 10);
    func_800794B0(OBJECT_121, 0, 0, 8);
    if (((gSettingEverythingUnlocked != 0) || (D_800CD3C0 >= 2)) && (gGameMode != GAMEMODE_8013) && (D_800CD380 != 1)) {
        func_800794B0(OBJECT_122_4, 0, -100, 6);
    }
    if ((D_800CD3C0 > 0) || (gSettingEverythingUnlocked != 0)) {
        func_800794B0(OBJECT_122_3, 0, -100, 6);
    }
    func_800794B0(OBJECT_122_2, 0, -100, 6);
    func_800794B0(OBJECT_122_1, 0, -100, 6);
    func_800794B0(OBJECT_122_0, 0, -100, 6);
    if (D_800CD380 != 0) {
        func_800794B0(OBJECT_129, 0, 0, 8);
    }
    func_800794B0(OBJECT_130, 0, 0, 8);
    switch (D_800CD380) {
        case 1:
            if (gGameMode != GAMEMODE_8013) {
                func_800794B0(OBJECT_133, 0, 0, 10);
            }
            /* fallthrough */
        case 2:
            func_800794B0(OBJECT_132, 190, 160, 10);
            break;
    }
}

void func_i5_80116D00(void) {
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
    func_800794B0(OBJECT_5, 0, 0, 1);
    func_800794B0(OBJECT_120, 0, 0, 2);
    func_800794B0(OBJECT_121, 0, 0, 8);
    if (gCupSelectOption >= 10) {
        func_800794B0(OBJECT_122_5, 0, -100, 6);
    } else {
        func_800794B0(OBJECT_122_0 + gCupSelectOption, 0, -100, 6);
    }
    func_800794B0(OBJECT_130, 0, 0, 8);
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

s32 func_i5_80116EEC(void) {
    s32 pad[2];
    s32 originalCupSelectOption;
    s8 originalSelectedGhostOption;
    s32 unlockedGhost;
    s32 var_v1;
    unk_800E3A28* temp_v0_2;

    func_8008675C();
    if (D_i2_80106DA4 != 0) {
        return gGameMode;
    }
    if ((D_800CD380 == 1) && (gGameMode != GAMEMODE_8013)) {
        func_i5_80116830();
    }
    func_8007DABC(&gSharedController);
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
                if ((gCupSelectOption == 4) && ((gGameMode == GAMEMODE_8013) || (D_800CD380 == 1))) {
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
                if (gGameMode == GAMEMODE_800A) {
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
                } else if (D_800CD380 == 0) {
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
                func_80079E88(OBJECT_121)->unk_0C = 0x190 - (sCourseSelectTrackNo * 0x500);
            }
            break;
        case 2:
            D_i5_801190D0 = 1;
            if ((D_800CD380 == 1) && (gGameMode != GAMEMODE_8013)) {
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
                temp_v0_2 = func_80079E88(OBJECT_129);
                temp_v0_2->unk_04 += 0x200;
                func_800BA8D8(30);
            }

            if ((gInputPressed & BTN_RIGHT) && (sCourseSelectTrackNo < 5)) {
                sCourseSelectTrackNo++;
                D_800E5220[0].unk_18 = 1;
                temp_v0_2 = func_80079E88(OBJECT_129);
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
                if ((D_800CD380 == 0) || (gCupSelectOption == 4)) {
                    D_i5_801190C0 = 0;
                } else {
                    D_i5_801190C0 = 2;
                }
                func_800BA8D8(0x10);
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_800BA8D8(0x3E);
                D_i5_801190C0 = 4;
                if (gGameMode == GAMEMODE_800A) {
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

s32 func_i5_801175D0(void) {
    func_8008675C();
    func_8007DABC(&gSharedController);
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

Gfx* func_i5_80117664(Gfx* gfx) {
    return func_80079BC8(gfx);
}

extern s8 D_800CD3C4;

void func_i5_80117684(unk_800E3A28* arg0) {
    size_t var_a1;
    unk_80077D50* sp20;

    arg0->unk_04 = D_800CD3C4;
    sp20 = sTitleBackgroundCompTexInfos[arg0->unk_04];
    func_80077D50(sp20, 0);

    if (arg0->unk_04 == 0) {
        arg0->unk_0C = 8;
    }
    if (gGameMode == GAMEMODE_8013) {
        func_80077D50(sOptionsFalconHelmetCompTexInfo, 0);
        if (arg0->unk_04 == 0) {
            var_a1 = 0x23A00;
        } else {
            var_a1 = 0x25800;
        }

        func_8007A828(func_800783AC(sp20->unk_04), var_a1, 135, 135, 255);
    }
}

void func_i5_80117758(void) {
    s32 i;

    func_i5_80115DF0();
    if (sCourseSelectCup <= X_CUP) {
        func_i5_80116658(sCourseSelectCup);
        D_i5_801190B4 -= 2;

        for (i = 0; i < 6; i++) {
            func_i5_80116678(D_i5_801190B0);
            D_i5_801190B4--;
        }
    }
}

void func_i5_801177EC(unk_800E3A28* arg0) {
    s32 cupType;
    s32 var_v0;
    s32 i;

    cupType = arg0->id - OBJECT_122_0;
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
        arg0->unk_1C = 0xC;
    }
    arg0->unk_0C = 0x80;
    arg0->unk_10 = 0x55;
}

void func_i5_801178D8(unk_800E3A28* arg0) {
    if (gGameMode != GAMEMODE_8013) {
        func_80077D50(sSelectCourseCompTexInfo, 0);
        arg0->unk_1C = 0xC;
    } else {
        func_80077D50(sRecordsCompTexInfo, 0);
    }
}

void func_i5_80117934(unk_800E3A28* arg0) {
    func_80077D50(sOKCompTexInfo, 0);
    arg0->unk_0C = 50;
}

void func_i5_8011796C(unk_800E3A28* arg0) {
    func_80077D50(sRecordsArrowCompTexInfo, 0);
    arg0->unk_04 = 0x80;
    arg0->unk_08 = 0x80;
}

void func_i5_801179A8(unk_800E3A28* arg0) {
    GhostInfo sp20;
    s32 pad;

    if (Save_LoadGhostInfo(&sp20) != 0) {
        arg0->id = OBJECT_FREE;
    }
    if (sp20.encodedCourseIndex == 0) {
        arg0->id = OBJECT_FREE;
    }
    arg0->unk_0C += (sp20.courseIndex % 6) * 320;
    arg0->unk_04 = sp20.courseIndex;
    func_80077D50(sHasGhostMarkerCompTexInfo, 0);
}

void func_i5_80117A2C(unk_800E3A28* arg0) {
    s32 i;

    func_80077D50(sStaffGhostBeatenCompTexInfo, 0);

    for (i = 0; i < 5; i++) {
        func_80077D50(sTimeAttackGhostOptionCompTexInfos[i], 0);
    }

    arg0->unk_0C = 150;
}

Gfx* func_i5_80117A98(Gfx* gfx, unk_800E3A28* arg1) {

    if (gGameMode != GAMEMODE_8013) {
        gDPSetPrimColor(gfx++, 0, 0, 75, 75, 75, 180);
        gfx = func_80078EA0(gfx, sTitleBackgroundCompTexInfos[arg1->unk_04], arg1->unk_0C, arg1->unk_10, 1, 0, 0, 1.0f,
                            1.0f);
    } else {
        gfx = func_80078EA0(gfx, sTitleBackgroundCompTexInfos[arg1->unk_04], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f,
                            1.0f);
        gfx = func_80078EA0(gfx, sOptionsFalconHelmetCompTexInfo, 0x35, 4, 2, 1, 0, 1.0f, 1.0f);
        gfx = func_80078EA0(gfx, sOptionsFalconHelmetCompTexInfo, 0xCB, 4, 0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

Gfx* func_i5_80117BE0(Gfx* gfx, unk_800E3A28* arg1) {

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

Gfx* func_i5_80117C48(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    s32 alpha;
    s32 cupDifficultiesCleared;
    s32 var_s1;
    s32 var_v0;
    s32 sp80;
    s32 var_v1;

    i = arg1->id - OBJECT_122_0;
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
            arg1->unk_1C++;
            if (arg1->unk_1C > 12) {
                D_i5_801190C0 = 6;
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

    cupDifficultiesCleared = gCupNumDifficultiesCleared[i];
    sp80 = (SQ(arg1->unk_1C) * 3) / 2;

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

    gfx = func_80078EA0(gfx, sCupSelectCompTexInfos[i], arg1->unk_0C, arg1->unk_10 + sp80, 1, 0, 0, 1.0f, 1.0f);

    if ((D_800CD380 == 0) && (i <= JOKER_CUP)) {
        alpha = ((arg1->unk_10 - 49) * 255) / 36;
        if (var_s1 == i) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
        }

        for (i = 0; i < cupDifficultiesCleared; i++) {
            gfx = func_80078EA0(gfx, sCupClearedDifficultyCompTexInfos[i], arg1->unk_0C + (i * 16) + ((12 - i * 8) / 2),
                                (arg1->unk_10 + sp80) - 12, 1, 0, 0, 1.0f, 1.0f);
        }
    }
    return gfx;
}

Gfx* func_i5_80117FB4(Gfx* gfx, unk_800E3A28* arg1) {
    s32 temp_v1;

    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    if (gGameMode != GAMEMODE_8013) {
        switch (D_i5_801190C0) {
            case 5:
            case 6:
                arg1->unk_1C++;
                if (arg1->unk_1C > 12) {
                    D_i5_801190C0 = 6;
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
        temp_v1 = (SQ(arg1->unk_1C) * 3) / 2;

        gfx = func_80078EA0(gfx, sSelectCourseCompTexInfo, arg1->unk_0C, arg1->unk_10 + temp_v1, 0, 0, 0, 1.0f, 1.0f);
    } else {
        gfx = func_80078EA0(gfx, sRecordsCompTexInfo, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

Gfx* func_i5_80118100(Gfx* gfx, unk_800E3A28* arg1) {
    gfx = func_8007DB28(gfx, 0);
    return func_80078EA0(gfx, sOKCompTexInfo, arg1->unk_0C + 0x10B, arg1->unk_10 + 0xD0, 1, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i5_80118168(Gfx* gfx, unk_800E3A28* arg1) {
    f32 temp_fv0 = (SIN(arg1->unk_1C) + 1.0) / 2;
    f32 temp_fa1 = (SIN(arg1->unk_20) + 1.0) / 2;

    gfx = func_80078EA0(gfx, sRecordsArrowCompTexInfo, arg1->unk_0C + 0x2B, (((1.0 - temp_fv0) * 16.0) + 112.0), 3, 0,
                        0, 1.0f, temp_fv0);
    return func_80078EA0(gfx, sRecordsArrowCompTexInfo, arg1->unk_10 + 0xF5, (((1.0 - temp_fa1) * 16.0) + 112.0), 5, 0,
                         0, 1.0f, temp_fa1);
}

Gfx* func_i5_801182DC(Gfx* gfx) {
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
            func_i2_80105DB0(sCourseSelectTrackNo + 1, cupTrackNoStr);
            cupTrackNoStr[1] = ':';
            cupTrackNoStr[2] = ' ';
            cupTrackNoStr[3] = '\0';
            cupTrackNoWidth = func_i2_801062E4(cupTrackNoStr, 3, 0);
            if (sCourseSelectCup == EDIT_CUP) {
                trackNameWidth = func_i2_801062E4(gCurrentTrackName, 3, 0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = func_i2_80106450(gfx, (-(trackNameWidth / 2) - (func_i2_801062E4(cupTrackNoStr, 3, 0) / 2)) + 160,
                                       200, cupTrackNoStr, 0, 3, 0);
                gfx = func_i2_80106450(gfx,
                                       ((cupTrackNoWidth / 2) - (func_i2_801062E4(gCurrentTrackName, 3, 0) / 2)) + 160,
                                       200, gCurrentTrackName, 0, 3, 0);
            } else {
                trackNameWidth = func_i2_801062E4(gCurrentTrackName, 3, 0);
                cupColors = &sCourseSelectCupColors[sCourseSelectCup * 3];
                gDPSetPrimColor(gfx++, 0, 0, cupColors[0], cupColors[1], cupColors[2], 255);
                gfx = func_i2_80106450(gfx, (-(trackNameWidth / 2) - (func_i2_801062E4(cupTrackNoStr, 3, 0) / 2)) + 160,
                                       200, cupTrackNoStr, 0, 3, 0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = func_i2_80106450(gfx,
                                       ((cupTrackNoWidth / 2) - (func_i2_801062E4(gCurrentTrackName, 3, 0) / 2)) + 160,
                                       200, gCurrentTrackName, 0, 3, 0);
                gfx = func_i2_80106450(
                    gfx,
                    160 - (func_i2_801062E4(sTrackSubtitles[sCourseSelectCup * 6 + sCourseSelectTrackNo], 4, 0) / 2),
                    210, sTrackSubtitles[sCourseSelectCup * 6 + sCourseSelectTrackNo], 0, 4, 0);
            }
            break;
    }
    return gfx;
}

Gfx* func_i5_80118674(Gfx* gfx, unk_800E3A28* arg1) {

    // If Cup Does Not Match
    if ((arg1->unk_04 / 6) != (gCourseIndex / 6)) {
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
            gfx = func_80078EA0(gfx, sHasGhostMarkerCompTexInfo, arg1->unk_0C + arg1->unk_1C, arg1->unk_10, 0, 0, 0,
                                1.0f, 1.0f);
            break;
    }

    return gfx;
}

Gfx* func_i5_80118790(Gfx* gfx, unk_800E3A28* arg1) {
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
        gfx = func_80078EA0(gfx, sTimeAttackGhostOptionCompTexInfos[i], arg1->unk_0C + 0xC3, i * 20 + 0x2D, 0, 0, 0,
                            1.0f, 1.0f);

        if ((i == 2) && sStaffGhostTimeBeaten) {
            gfx = func_80078EA0(gfx, sStaffGhostBeatenCompTexInfo, arg1->unk_0C + 0x109, i * 20 + 0x2D, 0, 0, 0, 1.0f,
                                1.0f);
        }
    }
    return gfx;
}

void func_i5_80118928(unk_800E3A28* arg0) {
    s32 temp_a1;

    if (((D_i5_801190C0 != 0) && (D_i5_801190C0 != 1)) || (gCupSelectOption < 4)) {
        func_i5_80115E10();
    }
    temp_a1 = -(sCourseSelectTrackNo * 0x500);
    if (gGameMode == GAMEMODE_800F) {
        arg0->unk_0C = temp_a1;
    } else {
        func_8007A0A0(arg0, temp_a1, 0xC0);
    }
    func_i5_801164A8(arg0->unk_0C);
}

void func_i5_801189C4(unk_800E3A28* arg0) {
    s32 var_v1;
    s32 var_a1;
    s32 var_v0;

    if (gGameMode == GAMEMODE_800F) {
        arg0->unk_0C = 0x80;
        arg0->unk_10 = 0x31;
        return;
    }

    var_v1 = arg0->id - OBJECT_122_0;
    switch (arg0->unk_04) {
        case 0:
            if (var_v1 != 5) {
                if (arg0->unk_10 < 0x55) {
                    func_80079FFC(arg0, 0x55);
                } else {
                    arg0->unk_04 = 1;
                }
            } else if (arg0->unk_10 >= 0xAB) {
                func_80079FFC(arg0, 0xAA);
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
                arg0->unk_14 = 7;
            } else {
                arg0->unk_14 = 6;
            }

            switch (D_i5_801190C0) {
                case 0:
                case 1:
                case 5:
                case 6:
                    if (var_v1 != 5) {
                        var_a1 = 0x55;
                    } else {
                        var_a1 = 0xAA;
                    }
                    func_80079FFC(arg0, var_a1);

                    if (arg0->unk_04 == 2) {
                        arg0->unk_04 = 3;
                    }
                    break;
                case 2:
                case 3:
                case 4:
                default:
                    if (D_800CD380 == 0) {
                        func_80079FFC(arg0, 0x31);
                    } else {
                        func_80079FFC(arg0, 0x2D);
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
                        if ((gGameMode != GAMEMODE_8013) && (D_800CD380 != 1)) {
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
                arg0->unk_0C = var_a1;
            } else if (arg0->unk_04 >= 2) {
                func_8007A0A0(arg0, var_a1, 0x80);
            } else {
                func_80079F54(arg0, var_a1, 0x10 / arg0->unk_04);
            }
            break;
    }
}

void func_i5_80118D44(unk_800E3A28* arg0) {
    switch (D_i5_801190C0) {
        case 3:
        case 4:
            func_8007A0A0(arg0, 0, 0xC0);
            break;
        default:
            func_8007A0A0(arg0, 50, 0xC0);
            break;
    }
}

void func_i5_80118D94(unk_800E3A28* arg0) {

    switch (D_i5_801190C0) {
        case 0:
        case 1:
        case 5:
        case 6:
            arg0->unk_15 = 0;
            arg0->unk_0C = -100;
            arg0->unk_10 = 100;
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

            arg0->unk_15 = 1;
            if ((sCourseSelectTrackNo == 0) || (D_i5_801190C0 == 3) || (D_i5_801190C0 == 4)) {
                func_8007A0A0(arg0, -100, 0xC0);
            } else {
                func_8007A0A0(arg0, 0, 0xC0);
            }
            if ((sCourseSelectTrackNo == 5) || (D_i5_801190C0 == 3) || (D_i5_801190C0 == 4)) {
                func_8007A154(arg0, 100);
            } else {
                func_8007A154(arg0, 0);
            }
            break;
    }
}

void func_i5_80118F24(unk_800E3A28* arg0) {
    s32 temp_v1;

    arg0->unk_1C = func_80079E88(OBJECT_121)->unk_0C >> 2;
    temp_v1 = arg0->unk_0C + arg0->unk_1C;

    if ((temp_v1 < -30) || (temp_v1 > 320)) {
        arg0->unk_15 = 0;
    } else {
        arg0->unk_15 = 1;
    }
}

void func_i5_80118F84(unk_800E3A28* arg0) {
    switch (D_i5_801190C0) {
        case 0:
        case 1:
        case 5:
        case 6:
            func_8007A0A0(arg0, 150, 0xC0);
            break;
        case 2:
        case 3:
        case 4:
        default:
            func_8007A0A0(arg0, 0, 0xC0);
            break;
    }
}
