#include "global.h"
#include "audio.h"
#include "fzx_game.h"
#include "fzx_course.h"
#include "fzx_save.h"
#include "src/overlays/ovl_i4/ovl_i4.h"
#include "assets/setup_gfx.h"

f32 gCharacterLastEngine[30];
UNUSED s32 D_800E4168;
u16 gInputPressed;
u16 gInputButtonPressed;
u16 gRetriggeredButtonCurrentPressed;
s8 gCupNumDifficultiesCleared[4];
char* gCurrentTrackName;
char* gTrackNames[55];

s32 gSelectedMode = MODE_GP_RACE;
s32 D_800CD384 = 0;

s32 gModeSubOption[8] = { 0 };

s8 gPlayerSelectionLock[] = { SELECTION_FREE, SELECTION_FREE, SELECTION_FREE, SELECTION_FREE };
s8 D_800CD3AC[] = { 1, 1, 1, 1 };

s32 gMachineSelectState = MACHINE_SELECT_ACTIVE;
s32 gMachineSettingsState = MACHINE_SETTINGS_ACTIVE;
s32 gLastCourseSelectCourseIndex = 0;
s32 gLastRecordsCourseIndex = 0;
s8 gUnlockableLevel = 0;
s8 D_800CD3C4 = 0;
s8 gSettingEverythingUnlocked = false;
s32 gCurrentGhostType = GHOST_PLAYER;

const char* sTrackNames[] = { "mute city",
                              "silence",
                              "sand ocean",
                              "devil's forest",
                              "big blue",
                              "port town",
                              "sector Ａ",
                              "red canyon",
                              "devil's forest 2",
                              "mute city 2",
                              "big blue 2",
                              "white land",
                              "fire field",
                              "silence 2",
                              "sector Ｂ",
                              "red canyon 2",
                              "white land 2",
                              "mute city 3",
                              "rainbow road",
                              "devil's forest 3",
                              "space plant",
                              "sand ocean 2",
                              "port town 2",
                              "big hand",
                              "default 1",
                              "default 2",
                              "default 3",
                              "default 4",
                              "default 5",
                              "default 6",
                              "x",
                              "" };

#ifdef VERSION_JP
const char* gMachineNames[] = { "blue falcon",   "golden fox",       "wild goose",    "fire stingray",  "white cat",
                                "red gazelle",   "great star",       "iron tiger",    "deep claw",      "twin noritta",
                                "super piranha", "mighty hurricane", "little wyvern", "space angler",   "green panther",
                                "black bull",    "wild boar",        "astro robin",   "king meteor",    "queen meteor",
                                "wonder wasp",   "hyper speeder",    "death anchor",  "crazy bear",     "night thunder",
                                "big fang",      "mighty typhoon",   "mad wolf",      "sonic phantom",  "hell hawk",
                                "super falcon",  "golden fox",       "wild goose",    "super stingray", "super cat",
                                "red gazelle" };
#else
const char* gMachineNames[] = { "blue falcon",   "golden fox",       "wild goose",    "fire stingray",  "white cat",
                                "red gazelle",   "great star",       "iron tiger",    "deep claw",      "twin noritta",
                                "super piranha", "mighty hurricane", "little wyvern", "space angler",   "green panther",
                                "black bull",    "wild boar",        "astro robin",   "king meteor",    "queen meteor",
                                "wonder wasp",   "hyper speeder",    "death anchor",  "crazy bear",     "night thunder",
                                "big fang",      "mighty typhoon",   "mad wolf",      "sonic phantom",  "blood hawk",
                                "super falcon",  "golden fox",       "wild goose",    "super stingray", "super cat",
                                "red gazelle" };
#endif

// clang-format off
s32 D_800CD4E0[] = {
    255, 0, 0,
    0, 255, 0,
    255, 255, 100,
    255, 0, 0,
};
// clang-format on

extern u8 gEditCupTrackNames[][9];

void func_8007D9D0(void) {
    s32 i;

    for (i = 0; i < 24; i++) {
        gTrackNames[i] = sTrackNames[i];
    }

    for (i = 24; i < 30; i++) {
        if (gEditCupTrackNames[i - 24][0] == '\0') {
            gTrackNames[i] = sTrackNames[i];
        } else {
            gTrackNames[i] = gEditCupTrackNames[i - 24];
        }
    }

    for (i = 30; i < 48; i++) {
        gTrackNames[i] = sTrackNames[31];
    }

    for (i = 48; i < 54; i++) {
        gTrackNames[i] = sTrackNames[30];
    }

    gTrackNames[54] = sTrackNames[31];
}

void Controller_SetGlobalInputs(Controller* controller) {
    gInputButtonPressed = controller->buttonPressed | STICK_TO_BUTTON(controller->stickPressed);
    if (controller->retriggerCurrentButtonPress) {
        gRetriggeredButtonCurrentPressed = controller->buttonCurrent | STICK_TO_BUTTON(controller->stickCurrent);
    } else {
        gRetriggeredButtonCurrentPressed = 0;
    }
    gInputPressed = gInputButtonPressed | gRetriggeredButtonCurrentPressed;
}

extern u32 gGameFrameCount;

Gfx* func_8007DB28(Gfx* gfx, s32 arg1) {
    s32 temp_a3;
    s32 temp_a2;
    s32 red;
    s32 green;
    s32 blue;
    s32 temp_hi;
    s32* temp_a0;

    temp_hi = ((gGameFrameCount % 300) * 8) % 300;
    temp_a2 = temp_hi % 100;
    temp_a3 = 100 - temp_a2;
    temp_a0 = &D_800CD4E0[((temp_hi / 100) % 3) * 3];

    switch (arg1) {
        case 0:
            red = ((temp_a0[0] * temp_a3) + (temp_a0[3] * temp_a2)) / 100;
            green = ((temp_a0[1] * temp_a3) + (temp_a0[4] * temp_a2)) / 100;
            blue = ((temp_a0[2] * temp_a3) + (temp_a0[5] * temp_a2)) / 100;
            break;
        case 1:
        default:
            red = ((temp_a0[0] * temp_a2) + (temp_a0[3] * temp_a3)) / 100;
            green = ((temp_a0[1] * temp_a2) + (temp_a0[4] * temp_a3)) / 100;
            blue = ((temp_a0[2] * temp_a2) + (temp_a0[5] * temp_a3)) / 100;
            break;
    }

    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);
    return gfx;
}

void func_8007DED8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gCupNumDifficultiesCleared[i] = 0;
    }
}

extern s32 gCupType;
extern s32 gDifficulty;

extern s16 gForceCredits;

void func_8007DEF0(void) {
    s32 i;
    s32 var_v1 = 0;
    s32 var_a0;
    s32 cupType;

    for (i = 0; i < 4; i++) {
        if (gCupNumDifficultiesCleared[i] < 3) {
            var_v1 = 1;
            break;
        }
    }
    cupType = gCupType;
    var_a0 = gDifficulty + 1;
    //! @bug This always evaluates to false, and instead should use an ||
    //       The result of this could lead to an OOB array access of gCupNumDifficultiesCleared
    if ((cupType < JACK_CUP) && (cupType > JOKER_CUP)) {
        return;
    }
    if (var_a0 > MASTER + 1) {
        var_a0 = MASTER + 1;
    }

    if (gCupNumDifficultiesCleared[cupType] < var_a0) {
        gCupNumDifficultiesCleared[cupType] = var_a0;
    }
    if (var_v1 != 0) {
        for (i = 0; i < 4; i++) {
            if (gCupNumDifficultiesCleared[i] < 3) {
                var_v1 = 0;
            }
        }

        if (var_v1 != 0) {
            gForceCredits = true;
        }
    }
    Save_SaveSettingsProfiles();
}

s32 func_8007E008(void) {
    s32 sum = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        sum += gCupNumDifficultiesCleared[i];
    }
    return sum;
}

extern bool gRamDDCompatible;
extern s32 gLeoDriveConnectionState;

bool func_8007E038(void) {
    if (gRamDDCompatible && (gLeoDriveConnectionState != 0) && (func_800760F8() == 2)) {
        return true;
    }
    return false;
}

void func_8007E08C(void) {
    Audio_ChangeSoundMode(COURSE_MUTE_CITY);
}

void func_8007E0AC(s32 bgm) {
    Audio_RomBgmStart(bgm);
}

void func_8007E0CC(void) {
    Audio_RomBgmStop();
}

void func_8007E0EC(void) {
    Audio_BetaBgmStop2();
}

const s8 kMachineSelectCharacterList[] = { CAPTAIN_FALCON,
                                           DR_STEWART,
                                           PICO,
                                           SAMURAI_GOROH,
                                           JODY_SUMMER,
                                           MIGHTY_GAZELLE,
                                           BABA,
                                           OCTOMAN,
                                           DR_CLASH,
                                           MR_EAD,
                                           BIO_REX,
                                           BILLY,
                                           SILVER_NEELSEN,
                                           GOMAR_AND_SHIOH,
                                           JOHN_TANAKA,
                                           MRS_ARROW,
                                           BLOOD_FALCON,
                                           JACK_LEVIN,
                                           JAMES_MCCLOUD,
                                           ZODA,
                                           MICHAEL_CHAIN,
                                           SUPER_ARROW,
                                           KATE_ALEN,
                                           ROGER_BUSTER,
                                           LEON,
                                           DRAQ,
                                           BEASTMAN,
                                           ANTONIO_GUSTER,
                                           BLACK_SHADOW,
                                           THE_SKULL,
                                           30 };

s8 Character_GetCharacterFromSlot(s32 characterSlot) {
    return kMachineSelectCharacterList[characterSlot];
}

s32 Character_GetSlotFromCharacter(s32 character) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (character == kMachineSelectCharacterList[i]) {
            return i;
        }
    }

    return 0;
}

void func_8007E1C0(void) {
    GhostInfo sp40;
    s32 pad;
    bool sp38;
    s32 i;

    sp38 = false;

    for (i = 0; i < 24; i++) {
        if (Save_LoadStaffGhostRecord(&sp40, i) != 0) {
            sp38 = true;
            break;
        } else {
            if (gCourseInfos[i].timeRecord[0] >= sp40.raceTime) {
                sp38 = true;
                break;
            }
        }
    }
    if (!sp38 || (gUnlockableLevel >= 3)) {
        D_800CD3C4 = 2;
    } else if (gUnlockableLevel >= 2) {
        D_800CD3C4 = 1;
    } else {
        D_800CD3C4 = 0;
    }
}

extern s8 gUnlockableLevel;

void func_8007E2B4(void) {
    bool var_a0;
    s32 i;

    if (func_8007E008() >= 16) {
        gUnlockableLevel = 3;
    } else {
        var_a0 = false;
        for (i = JACK_CUP; i <= JOKER_CUP; i++) {
            if (gCupNumDifficultiesCleared[i] < 3) {
                var_a0 = true;
                break;
            }
        }

        if (!var_a0) {
            gUnlockableLevel = 2;
        } else {
            var_a0 = false;
            for (i = JACK_CUP; i <= KING_CUP; i++) {
                if (gCupNumDifficultiesCleared[i] < 2) {
                    var_a0 = true;
                    break;
                }
            }

            if (!var_a0) {
                gUnlockableLevel = 1;
            } else {
                gUnlockableLevel = 0;
            }
        }
    }
    func_8007E1C0();
}

extern s16 gPlayerCharacters[];
extern s16 gPlayerMachineSkins[];

void func_8007E398(void) {
    s32 i;
    s32 j;

    for (i = 3; i >= 0; i--) {
        gPlayerCharacters[i] = i;
        gPlayerMachineSkins[i] = 0;
    }

    for (i = 0; i < 8; i++) {
        gModeSubOption[i] = 0;
    }

    gLastCourseSelectCourseIndex = 0;
    gLastRecordsCourseIndex = 0;
    gCurrentGhostType = GHOST_PLAYER;
}
