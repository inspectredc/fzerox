#include "global.h"
#include "audio.h"
#include "fzx_game.h"
#include "fzx_course.h"

UNUSED s32 D_800DCE40;
s32 gGameMode;
s32 gQueuedGameMode;
UNUSED s32 D_800DCE4C;
UNUSED s32 D_800DCE50;
UNUSED s32 D_800DCE54;
s32 gAntiPiracyAddedDifficulty;
s8 gGamePaused;
s32 D_800DCE60;
UNUSED s32 D_800DCE64;
UNUSED s32 D_800DCE68;
OSContStatus D_800DCE70[MAXCONTROLLERS];
OSContPad gControllerPads[MAXCONTROLLERS];
Controller gControllers[MAXCONTROLLERS + 1];
Controller gSharedController;
s32 gPlayerControlPorts[MAXCONTROLLERS];
s32 gControllersConnected;

// This needs to be used in a function earlier than this can be declared (i.e. todo: move this to a header)
extern s16 D_800CD16C;

s32 gNumPlayers = 1;
s32 gCupType = JACK_CUP;
s32 gDifficulty = NOVICE;
s32 gTotalLapCount = 3;
s8 D_800CD010 = 0;
s8 sTitleDemoNumPlayerState = 0;
s8 sTitleDemoCoursesState = 0;
UNUSED s32 D_800CD01C = 0;
u16 D_800CD020 = 0;
s32 sTitleDemoGameModes[] = { GAMEMODE_GP_RACE, GAMEMODE_VS_2P, GAMEMODE_VS_4P };
s32 sTitleDemoNumPlayers[] = { 1, 2, 4 };
s8 sTitleDemoCourses[] = { COURSE_DEVILS_FOREST, COURSE_SILENCE, COURSE_SAND_OCEAN, COURSE_BIG_BLUE,
                           COURSE_WHITE_LAND_2 };
s16 D_800CD044 = 0;
s16 D_800CD048 = 0;

void (*sGamemodeInitFuncs[])(void) = {
    Title_Init,            // GAMEMODE_TITLE
    Race_Init,             // GAMEMODE_GP_RACE
    Race_Init,             // GAMEMODE_PRACTICE
    Race_Init,             // GAMEMODE_VS_2P
    Race_Init,             // GAMEMODE_VS_3P
    Race_Init,             // GAMEMODE_VS_4P
    Records_Init,          // GAMEMODE_RECORDS
    MainMenu_Init,         // GAMEMODE_MAIN_MENU
    MachineSelect_Init,    // GAMEMODE_MACHINE_SELECT
    MachineSettings_Init,  // GAMEMODE_MACHINE_SETTINGS
    CourseSelect_Init,     // GAMEMODE_COURSE_SELECT
    Credits_Init,          // GAMEMODE_SKIPPABLE_CREDITS
    Credits_Init,          // GAMEMODE_UNSKIPPABLE_CREDITS
    NULL,                  // GAMEMODE_COURSE_EDIT
    Race_Init,             // GAMEMODE_TIME_ATTACK
    NextCourseSelect_Init, // GAMEMODE_GP_RACE_NEXT_COURSE
    NULL,                  // GAMEMODE_CREATE_MACHINE
    EndingCutscene_Init,   // GAMEMODE_GP_END_CS
    MachineSettings_Init,  // GAMEMODE_GP_RACE_NEXT_MACHINE_SETTINGS
    CourseSelect_Init,     // GAMEMODE_RECORDS_COURSE_SELECT
    OptionsMenu_Init,      // GAMEMODE_OPTIONS_MENU
    Race_Init,             // GAMEMODE_DEATH_RACE
};

s32 (*sGamemodeUpdateFuncs[])(void) = {
    Title_Update,            // GAMEMODE_TITLE
    Race_Update,             // GAMEMODE_GP_RACE
    Race_Update,             // GAMEMODE_PRACTICE
    Race_Update,             // GAMEMODE_VS_2P
    Race_Update,             // GAMEMODE_VS_3P
    Race_Update,             // GAMEMODE_VS_4P
    Records_Update,          // GAMEMODE_RECORDS
    MainMenu_Update,         // GAMEMODE_MAIN_MENU
    MachineSelect_Update,    // GAMEMODE_MACHINE_SELECT
    MachineSettings_Update,  // GAMEMODE_MACHINE_SETTINGS
    CourseSelect_Update,     // GAMEMODE_COURSE_SELECT
    Credits_Update,          // GAMEMODE_SKIPPABLE_CREDITS
    Credits_Update,          // GAMEMODE_UNSKIPPABLE_CREDITS
    NULL,                    // GAMEMODE_COURSE_EDIT
    Race_Update,             // GAMEMODE_TIME_ATTACK
    NextCourseSelect_Update, // GAMEMODE_GP_RACE_NEXT_COURSE
    NULL,                    // GAMEMODE_CREATE_MACHINE
    EndingCutscene_Update,   // GAMEMODE_GP_END_CS
    MachineSettings_Update,  // GAMEMODE_GP_RACE_NEXT_MACHINE_SETTINGS
    CourseSelect_Update,     // GAMEMODE_RECORDS_COURSE_SELECT
    OptionsMenu_Update,      // GAMEMODE_OPTIONS_MENU
    Race_Update,             // GAMEMODE_DEATH_RACE
};

Gfx* (*sGamemodeDrawFuncs[])(Gfx*) = {
    Title_Draw,           // GAMEMODE_TITLE
    Race_Draw,            // GAMEMODE_GP_RACE
    Race_Draw,            // GAMEMODE_PRACTICE
    Race_Draw,            // GAMEMODE_VS_2P
    Race_Draw,            // GAMEMODE_VS_3P
    Race_Draw,            // GAMEMODE_VS_4P
    Records_Draw,         // GAMEMODE_RECORDS
    MainMenu_Draw,        // GAMEMODE_MAIN_MENU
    MachineSelect_Draw,   // GAMEMODE_MACHINE_SELECT
    MachineSettings_Draw, // GAMEMODE_MACHINE_SETTINGS
    CourseSelect_Draw,    // GAMEMODE_COURSE_SELECT
    Credits_Draw,         // GAMEMODE_SKIPPABLE_CREDITS
    Credits_Draw,         // GAMEMODE_UNSKIPPABLE_CREDITS
    NULL,                 // GAMEMODE_COURSE_EDIT
    Race_Draw,            // GAMEMODE_TIME_ATTACK
    CourseSelect_Draw,    // GAMEMODE_GP_RACE_NEXT_COURSE
    NULL,                 // GAMEMODE_CREATE_MACHINE
    EndingCutscene_Draw,  // GAMEMODE_GP_END_CS
    MachineSettings_Draw, // GAMEMODE_GP_RACE_NEXT_MACHINE_SETTINGS
    CourseSelect_Draw,    // GAMEMODE_RECORDS_COURSE_SELECT
    OptionsMenu_Draw,     // GAMEMODE_OPTIONS_MENU
    Race_Draw,            // GAMEMODE_DEATH_RACE
};

void func_80076848(void);
void func_8007D9D0(void);
void func_8007F500(void);
void func_80085510(void);
void func_8008DA68(void);
void func_8008DB98(void);
void func_800A4B54(void);
void func_800A4BAC(void);
void func_i2_800FC730(void);

void Game_Init(void) {
    gGameMode = -1;
    gQueuedGameMode = GAMEMODE_FLX_TITLE;
    if (D_800DCE60 != 0x20DE1529) {
        D_800DCE60 = 0x20DE1529;
        func_8008DB98();
        func_800A4BAC();
    } else {
        func_8008DA68();
        func_800A4B54();
    }
    func_80085510();
    func_i2_800FC730();
    func_8007F500();
    func_80076848();
    func_8007D9D0();
    D_800CD16C = 1;
}

extern f32 gPlayerEngine[];
extern s32 gCourseIndex;

void func_80068BC0(void) {
    if (D_800CD044 == 0) {
        switch (D_800CD048) {
            case 1:
                D_800CD044 = 5;
                break;
            case 2:
                D_800CD044 = 1;
                gQueuedGameMode = GAMEMODE_FLX_MAIN_MENU;
                break;
            case 3:
                D_800CD044 = 1;
                gQueuedGameMode = GAMEMODE_FLX_COURSE_SELECT;
                break;
            case 7:
                D_800CD044 = 1;
                gQueuedGameMode = GAMEMODE_FLX_MACHINE_SELECT;
                break;
            case 4:
                D_800CD044 = 1;
                if (gCourseIndex % 6 == 5) {
                    gQueuedGameMode = GAMEMODE_GP_END_CS;
                } else {
                    gQueuedGameMode = GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
                    gCourseIndex++;
                }
                gPlayerEngine[0] = 0.5f;
                break;
            case 5:
                D_800CD044 = 1;
                gQueuedGameMode = GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
                break;
            case 6:
                D_800CD044 = 11;
                gQueuedGameMode = GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
                break;
            case 8:
                D_800CD044 = 21;
                gQueuedGameMode = GAMEMODE_RECORDS;
                break;
            case 9:
                D_800CD044 = 21;
                gQueuedGameMode = GAMEMODE_FLX_RECORDS_COURSE_SELECT;
                break;
            case 10:
            case 14:
                D_800CD044 = 21;
                gQueuedGameMode = GAMEMODE_FLX_MAIN_MENU;
                break;
            case 11:
                D_800CD044 = 31;
                gQueuedGameMode = GAMEMODE_FLX_COURSE_SELECT;
                break;
            case 12:
                D_800CD044 = 31;
                gQueuedGameMode = GAMEMODE_FLX_MAIN_MENU;
                break;
            case 13:
                D_800CD044 = 21;
                gQueuedGameMode = GAMEMODE_FLX_OPTIONS_MENU;
                break;
            case 15:
                D_800CD044 = 11;
                if (gGameMode == GAMEMODE_GP_RACE) {
                    gQueuedGameMode = GAMEMODE_FLX_GP_RACE_NEXT_MACHINE_SETTINGS;
                } else {
                    gQueuedGameMode = GAMEMODE_LX_MACHINE_SETTINGS;
                }
                break;
            case 16:
                D_800CD044 = 11;
                gQueuedGameMode = gGameMode;
                break;
        }
    }
}

void func_80068DCC(void) {
    static u16 D_800CD154 = 0;
    s32 var_v1 = D_800CD154;

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            if (D_800CD010 == 0) {
                D_800CD154 = 0;
            }
            return;
        case GAMEMODE_FLX_TITLE:
            var_v1 = 0xD;
            break;
        case GAMEMODE_GP_END_CS:
            var_v1 = 0x15;
            break;
        case GAMEMODE_FLX_SKIPPABLE_CREDITS:
        case GAMEMODE_FLX_UNSKIPPABLE_CREDITS:
            var_v1 = 0x16;
            break;
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
        case GAMEMODE_FLX_OPTIONS_MENU:
            var_v1 = 0xF;
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_FLX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_MAIN_MENU:
        case GAMEMODE_FLX_MACHINE_SELECT:
        case GAMEMODE_FLX_COURSE_SELECT:
        case GAMEMODE_FLX_GP_RACE_NEXT_COURSE:
            var_v1 = 0xE;
            break;
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_CREATE_MACHINE:
            D_800CD154 = 0;
            return;
        default:
            break;
    }
    if (D_800CD154 != var_v1) {
        func_8007E0CC();
        func_8007E08C();
        func_800BAFA4(var_v1);
    }
    D_800CD154 = var_v1;
}

UNUSED s32 D_800CD158[2] = { 0 }; // New File?
s32 D_800CD160 = 15;
s32 D_800CD164 = 5;
s16 D_800CD168 = 0;
s16 D_800CD16C = 0;

extern u16 gInputButtonPressed;

void func_80068F04(void) {

    if (gGameMode != gQueuedGameMode) {
        D_800CD010 = 0;
        D_800CD020 = 0;
        return;
    }
    Controller_SetGlobalInputs(&gSharedController);
    switch (gGameMode) {
        case GAMEMODE_FLX_TITLE:
            if (gControllersConnected != 0) {
                D_800CD020++;
            }
            if ((D_800CD010 != 0) && (gControllersConnected != 0)) {

                gQueuedGameMode = sTitleDemoGameModes[sTitleDemoNumPlayerState];
                gNumPlayers = sTitleDemoNumPlayers[sTitleDemoNumPlayerState];
                gCourseIndex = sTitleDemoCourses[sTitleDemoCoursesState];
                sTitleDemoNumPlayerState++;
                sTitleDemoCoursesState++;
                if (sTitleDemoNumPlayerState >= ARRAY_COUNT(sTitleDemoNumPlayers)) {
                    sTitleDemoNumPlayerState = 0;
                }
                if (sTitleDemoCoursesState >= ARRAY_COUNT(sTitleDemoCourses)) {
                    sTitleDemoCoursesState = 0;
                }
                D_800CD020 = 0;
                D_800CD010 = 1;
                gDifficulty = MASTER;
            }
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            if (D_800CD010 != 0) {
                D_800CD020++;
                switch (D_800CD010) {
                    case 1:
                        if (!(gInputButtonPressed & (BTN_A | BTN_START))) {
                            break;
                        }
                        /* fallthrough */
                    case 3:
                        gQueuedGameMode = GAMEMODE_FLX_TITLE;
                        D_800CD020 = 0;
                        D_800CD010 = 2;
                        break;
                    case 2:
                        break;
                }
            }
            break;
    }
}

extern OSMesgQueue gSerialEventQueue;

void func_800690FC(void) {
    s32 sp24;

    if (gGameMode != gQueuedGameMode) {
        if (D_800CD044 == 0) {
            if (gGameMode == -1) {
                D_800CD044 = 3;
            } else {
                D_800CD044 = 1;
            }
        }
    } else {
        func_80068BC0();
    }

    D_800CD048 = 0;
    switch (D_800CD044) {
        case 1:
        case 11:
        case 21:
        case 31:
            func_i2_800FC77C();
            if (D_800CD168 != 0) {
                Controller_UpdateInputs();
                D_800CD168 = 0;
            }
            sGamemodeUpdateFuncs[GET_MODE(gGameMode)]();
            func_i2_800FCE3C();
            if (D_800CD16C != 0) {
                osContStartReadData(&gSerialEventQueue);
                D_800CD168 = 1;
            }
            D_800CD044++;
            return;
        case 2:
        case 12:
        case 22:
        case 32:
            if (D_800CD168 != 0) {
                Controller_UpdateInputs();
                D_800CD168 = 0;
            }
            sGamemodeUpdateFuncs[GET_MODE(gGameMode)]();
            if (func_i2_800FCE3C() != 0) {
                if (gGameMode == GAMEMODE_GP_RACE) {
                    func_i3_ResetLivesChangeCounter();
                }
                D_800CD044++;
            }
            if (D_800CD16C != 0) {
                osContStartReadData(&gSerialEventQueue);
                D_800CD168 = 1;
                return;
            }
            return;
        case 3:
        case 13:
        case 23:
        case 33:
            func_80069700();
            switch (gGameMode) {
                case GAMEMODE_LX_MACHINE_SETTINGS:
                case GAMEMODE_FLX_GP_RACE_NEXT_MACHINE_SETTINGS:
                    if ((gNumPlayers == 1) && (gCourseIndex < COURSE_EDIT_1)) {
                        Save_UpdateCourseCharacterSave(gCourseIndex);
                    }
                    break;
                case GAMEMODE_FLX_MACHINE_SELECT:
                    func_i4_8011A7B8();
                    break;
            }
            gGameMode = gQueuedGameMode;
            if (D_800CD010 == 2) {
                D_800CD010 = 0;
            }
            gGamePaused = false;
            func_800766F0();

            switch (gGameMode) {
                case GAMEMODE_GP_RACE:
                case GAMEMODE_PRACTICE:
                case GAMEMODE_VS_2P:
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                case GAMEMODE_COURSE_EDIT:
                case GAMEMODE_TIME_ATTACK:
                case GAMEMODE_CREATE_MACHINE:
                case GAMEMODE_DEATH_RACE:
                    if (D_800CD010 == 0) {
                        func_8007E08C();
                    }
                    break;
            }
            sp24 = 0;
            switch (gGameMode) {
                case GAMEMODE_GP_RACE:
                case GAMEMODE_PRACTICE:
                case GAMEMODE_VS_2P:
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                case GAMEMODE_COURSE_EDIT:
                case GAMEMODE_DEATH_RACE:
                case GAMEMODE_LX_MACHINE_SETTINGS:
                case GAMEMODE_FLX_GP_RACE_NEXT_MACHINE_SETTINGS:
                case GAMEMODE_FLX_MACHINE_SELECT:
                    sp24 = 1;
                    break;
                case GAMEMODE_TIME_ATTACK:
                    sp24 = 2;
                    break;
                case GAMEMODE_RECORDS:
                    sp24 = 3;
                    break;
            }
            if (sp24 != 0) {
                // clang-format off
                osInvalICache(SEGMENT_VRAM_START(ovl_i9), SEGMENT_DATA_START(ovl_i9) - SEGMENT_VRAM_START(ovl_i9));\
                osInvalDCache(SEGMENT_DATA_START(ovl_i9), SEGMENT_BSS_START(ovl_i9) - SEGMENT_DATA_START(ovl_i9));
                // clang-format on
                Dma_LoadOverlay(SEGMENT_ROM_START(ovl_i9), SEGMENT_VRAM_START(ovl_i9), SEGMENT_ROM_SIZE(ovl_i9),
                                SEGMENT_BSS_START(ovl_i9), SEGMENT_BSS_SIZE(ovl_i9));
                switch (sp24) {
                    case 1:
                        func_8008D7E8();
                        break;
                    case 2:
                        Save_LoadGhost(gCourseIndex);
                        func_8008D8E8();
                        break;
                    case 3:
                        func_8008D824();
                        break;
                }
            }
            func_80077318();
            func_80079EC8();
            sGamemodeInitFuncs[GET_MODE(gGameMode)]();
            func_80068DCC();
            func_80077C9C();
            func_i2_800FC9BC();
            D_800CD044 = 0;
            break;
        case 5:
            func_i2_800FC77C();
            func_i2_800FCE3C();
            D_800CD044 = 6;
            break;
        case 6:
            if (func_i2_800FCE3C() != 0) {
                func_i2_800FC9BC();
                if (gGameMode != GAMEMODE_RECORDS) {
                    func_8007E08C();
                }
                func_80068DCC();
                func_80079F1C();
                func_i2_80103A70();
                D_800CD044 = 0;
            }
            break;
        case 0:
        default:
            break;
    }

    if (D_800CD168 != 0) {
        Controller_UpdateInputs();
        D_800CD168 = 0;
    }
    gQueuedGameMode = sGamemodeUpdateFuncs[GET_MODE(gGameMode)]();
    func_80068F04();
    switch (D_800CD044) {
        case 6:
            break;
        case 0:
            func_i2_800FCE3C();
            break;
    }
    if (D_800CD16C != 0) {
        osContStartReadData(&gSerialEventQueue);
        D_800CD168 = 1;
    }
}

extern s16 D_i2_80106DA0;

Gfx* func_80069698(Gfx* gfx) {

    if ((D_800CD044 != 3) && (D_i2_80106DA0 != 0)) {
        gfx = sGamemodeDrawFuncs[GET_MODE(gGameMode)](gfx);
    }
    return func_i2_800FD184(gfx);
}

void func_80069700(void) {
    s32 i;

    if (D_800CD168 != 0) {
        Controller_UpdateInputs();
        D_800CD168 = 0;
    }

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (osMotorStop(&gControllers[i].pfs) == 0) {
            gControllers[i].unk_74 = 1;
        } else {
            gControllers[i].unk_74 = 0;
        }
        gControllers[i].unk_72 = gControllers[i].unk_76 = 0;
    }
}

void Controller_ClearInputs(void) {
    Controller* var_v0;

    // clang-format off
    var_v0 = &gControllers[4];\
    do {
        if (var_v0->errno == 0) {
            var_v0->unk_82 = var_v0->buttonCurrent = var_v0->buttonPressed = var_v0->buttonReleased = var_v0->buttonPrev = 0;
            var_v0->stickX = var_v0->stickY = var_v0->stickCurrent = var_v0->stickPressed = var_v0->stickReleased = var_v0->stickPrev = 0;
            var_v0->unk_84 = 0;
        }
        var_v0--;
    } while (var_v0 >= gControllers);
    // clang-format on

    gSharedController.unk_82 = gSharedController.buttonCurrent = gSharedController.buttonPressed =
        gSharedController.buttonReleased = 0;
    gSharedController.stickX = gSharedController.stickY = gSharedController.stickCurrent =
        gSharedController.stickPressed = gSharedController.stickReleased = 0;
}

extern s32 D_800CCFB0;
extern bool gResetStarted;
extern OSMesg D_800E12B0;

void Controller_UpdateInputs(void) {
    s32 i;
    s32 j;
    u16 buttonDiff;
    s32 var_fp;
    s32 var_s2;
    s32 var_s6;
    s32 var_s7;
    Controller* controller;
    OSContPad* var_s5;
    s32* var_v0;

    gSharedController.unk_82 = gSharedController.buttonCurrent = gSharedController.buttonPressed =
        gSharedController.buttonReleased = 0;
    var_s6 = 0;
    var_s7 = 0;
    var_fp = 0;
    gSharedController.stickCurrent = gSharedController.stickPressed = gSharedController.stickReleased = 0;

    controller = &gControllers[4];
    i = 4;
    //! @bug OOB array access, no reads are done before going back in bounds
    var_s5 = &gControllerPads[4];

    osRecvMesg(&gSerialEventQueue, &D_800E12B0, OS_MESG_BLOCK);
    osContGetReadData(gControllerPads);
    do {
        controller--;
        var_s5--;
        i--;

        if (controller->errno == 0) {
            if ((controller->errno = var_s5->errno) != 0) {
                gControllersConnected--;

                for (j = 3; j >= 0; j--) {
                    if (i == gPlayerControlPorts[j]) {
                        gPlayerControlPorts[j] = PORT_DISCONNECTED;
                        break;
                    }
                }
            } else {
                var_s6++;
                controller->buttonPrev = controller->buttonCurrent;
                gSharedController.buttonCurrent |= controller->buttonCurrent = var_s5->button & CONT_MASK;

                buttonDiff = (controller->buttonPrev ^ controller->buttonCurrent);

                gSharedController.buttonPressed |= controller->buttonPressed = buttonDiff & controller->buttonCurrent;
                gSharedController.buttonReleased |= controller->buttonReleased = buttonDiff & controller->buttonPrev;

                var_fp += controller->stickX = var_s5->stick_x;
                var_s7 += controller->stickY = var_s5->stick_y;

                controller->stickPrev = controller->stickCurrent;

                if (controller->stickX < -50) {
                    controller->stickCurrent = STICK_LEFT;
                } else if (controller->stickX > 50) {
                    controller->stickCurrent = STICK_RIGHT;
                } else {
                    controller->stickCurrent = 0;
                }

                if (controller->stickY < -50) {
                    controller->stickCurrent |= STICK_DOWN;
                } else if (controller->stickY > 50) {
                    controller->stickCurrent |= STICK_UP;
                }

                gSharedController.stickCurrent |= controller->stickCurrent;

                buttonDiff = (controller->stickPrev ^ controller->stickCurrent);

                gSharedController.stickPressed |= controller->stickPressed = buttonDiff & controller->stickCurrent;
                gSharedController.stickReleased |= controller->stickReleased = buttonDiff & controller->stickPrev;

                controller->unk_82 = 0;
                if (((controller->buttonCurrent != 0) || (controller->stickCurrent != 0)) &&
                    (controller->buttonPrev == controller->buttonCurrent) &&
                    (controller->stickPrev == controller->stickCurrent)) {
                    controller->unk_84++;
                    if ((controller->unk_84 >= D_800CD160) && (((controller->unk_84 - D_800CD160) % D_800CD164) == 0)) {
                        controller->unk_82 = 1;
                    }
                } else {
                    controller->unk_84 = 0;
                }
                gSharedController.unk_82 |= controller->unk_82;
                if (controller->unk_78 != 0) {
                    if (osMotorInit(&gSerialEventQueue, &controller->pfs, i) == 0) {
                        osMotorStop(&controller->pfs);
                        controller->unk_74 = 1;
                    } else {
                        controller->unk_74 = 0;
                    }
                    controller->unk_76 = 0;
                    controller->unk_90 = 0;
                    controller->unk_8C = 0;
                    controller->unk_88 = 0;
                    controller->unk_78 = controller->unk_76;
                } else if ((controller->unk_72 == 0) || gResetStarted) {
                    if ((controller->unk_74 == 1) && ((controller->unk_76 == 1) || !(((i << 5) + D_800CCFB0) & 0x7F))) {
                        if (osMotorStop(&controller->pfs) == 0) {
                            controller->unk_76 = 0;
                        } else {
                            controller->unk_74 = 0;
                        }
                    }
                } else if (controller->unk_74 == 1) {
                    controller->unk_88 += controller->unk_8C;
                    controller->unk_8C -= controller->unk_90;
                    if (controller->unk_8C < 0) {
                        controller->unk_8C = 0;
                    }

                    if (controller->unk_88 >= 1000) {
                        controller->unk_88 -= 1000;
                        if (controller->unk_76 == 0) {
                            if (osMotorStart(&controller->pfs) == 0) {
                                controller->unk_76 = 1;
                            } else {
                                controller->unk_74 = 0;
                            }
                        }
                    } else if (controller->unk_76 == 1) {
                        if (osMotorStop(&controller->pfs) == 0) {
                            controller->unk_76 = 0;
                        } else {
                            controller->unk_74 = 0;
                        }
                    }
                }
            }
        }
    } while (controller != gControllers);

    if (var_s6 != 0) {
        gSharedController.stickX = var_fp / var_s6;

        gSharedController.stickY = var_s7 / var_s6;
    }
}

void Controller_Init(void) {
    s32 i;
    u8 sp53;

    osContInit(&gSerialEventQueue, &sp53, D_800DCE70);
    gControllersConnected = 0;

    for (i = 0; i < MAXCONTROLLERS; i++) {

        gControllers[i].errno = D_800DCE70[i].errno;
        gControllers[i].unk_72 = gControllers[i].unk_74 = gControllers[i].unk_76 = gControllers[i].unk_78 = 0;
        gControllers[i].unk_88 = gControllers[i].unk_8C = gControllers[i].unk_90 = 0;
        if (D_800DCE70[i].errno == 0) {
            gPlayerControlPorts[gControllersConnected] = i;
            gControllersConnected++;
            if (osMotorInit(&gSerialEventQueue, &gControllers[i].pfs, i) == 0) {
                osMotorStop(&gControllers[i].pfs);
                gControllers[i].unk_74 = 1;
            }
        }
    }

    for (i = gControllersConnected; i < 4; i++) {
        gPlayerControlPorts[i] = PORT_DISCONNECTED;
    }

    Controller_ClearInputs();
}
