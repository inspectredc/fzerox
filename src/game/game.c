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

s32 gNumPlayers = 1;
s32 gCupType = JACK_CUP;
s32 gDifficulty = NOVICE;
s32 gTotalLapCount = 3;
s8 gTitleDemoState = TITLE_DEMO_INACTIVE;
s8 sTitleDemoNumPlayerState = 0;
s8 sTitleDemoCoursesState = 0;
UNUSED s32 D_800CD01C = 0;
u16 sTitleDemoCounter = 0;
s32 sTitleDemoGameModes[] = { GAMEMODE_GP_RACE, GAMEMODE_VS_2P, GAMEMODE_VS_4P };
s32 sTitleDemoNumPlayers[] = { 1, 2, 4 };
s8 sTitleDemoCourses[] = { COURSE_DEVILS_FOREST, COURSE_SILENCE, COURSE_SAND_OCEAN, COURSE_BIG_BLUE,
                           COURSE_WHITE_LAND_2 };
s16 gGameModeChangeState = GAMEMODE_UPDATE;
s16 gMenuChangeMode = MENU_CHANGE_INACTIVE;

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

extern s16 D_800CD16C;

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
    Camera_StartInit();
    Transition_Init();
    func_8007F500();
    Arena_EndInit();
    func_8007D9D0();
    D_800CD16C = true;
}

extern f32 gPlayerEngine[];
extern s32 gCourseIndex;

void func_80068BC0(void) {
    if (gGameModeChangeState != GAMEMODE_UPDATE) {
        return;
    }
    switch (gMenuChangeMode) {
        case MENU_CHANGE_RETRY:
            gGameModeChangeState = GAMEMODE_CHANGE_START_RELOAD;
            break;
        case MENU_CHANGE_QUIT:
            gGameModeChangeState = GAMEMODE_CHANGE_START;
            gQueuedGameMode = GAMEMODE_FLX_MAIN_MENU;
            break;
        case MENU_CHANGE_CHANGE_COURSE:
            gGameModeChangeState = GAMEMODE_CHANGE_START;
            gQueuedGameMode = GAMEMODE_FLX_COURSE_SELECT;
            break;
        case MENU_CHANGE_CHANGE_MACHINE:
            gGameModeChangeState = GAMEMODE_CHANGE_START;
            gQueuedGameMode = GAMEMODE_FLX_MACHINE_SELECT;
            break;
        case MENU_CHANGE_NEXT_COURSE:
            gGameModeChangeState = GAMEMODE_CHANGE_START;
            if (gCourseIndex % 6 == 5) {
                gQueuedGameMode = GAMEMODE_GP_END_CS;
            } else {
                gQueuedGameMode = GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
                gCourseIndex++;
            }
            gPlayerEngine[0] = 0.5f;
            break;
        case MENU_CHANGE_CRASH_RESTART:
            gGameModeChangeState = GAMEMODE_CHANGE_START;
            gQueuedGameMode = GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
            break;
        case MENU_CHANGE_6:
            gGameModeChangeState = GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
            break;
        case MENU_CHANGE_CHANGE_RECORD_COURSE:
            gGameModeChangeState = GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_RECORDS;
            break;
        case MENU_CHANGE_TO_RECORDS:
            gGameModeChangeState = GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_RECORDS_COURSE_SELECT;
            break;
        case MENU_CHANGE_EXIT_RECORDS:
        case MENU_CHANGE_EXIT_OPTIONS:
            gGameModeChangeState = GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_MAIN_MENU;
            break;
        case MENU_CHANGE_TO_COURSE_SELECT:
            gGameModeChangeState = GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_COURSE_SELECT;
            break;
        case MENU_CHANGE_EXIT_COURSE_SELECT:
            gGameModeChangeState = GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_MAIN_MENU;
            break;
        case MENU_CHANGE_TO_OPTIONS:
            gGameModeChangeState = GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_OPTIONS_MENU;
            break;
        case MENU_CHANGE_SETTINGS:
            gGameModeChangeState = GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_START);
            if (gGameMode == GAMEMODE_GP_RACE) {
                gQueuedGameMode = GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS;
            } else {
                gQueuedGameMode = GAMEMODE_LX_MACHINE_SETTINGS;
            }
            break;
        case MENU_CHANGE_16:
            gGameModeChangeState = GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_START);
            gQueuedGameMode = gGameMode;
            break;
    }
}

void func_80068DCC(void) {
    static u16 D_800CD154 = BGM_MUTE_CITY;
    s32 bgm = D_800CD154;

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                D_800CD154 = BGM_MUTE_CITY;
            }
            return;
        case GAMEMODE_FLX_TITLE:
            bgm = BGM_TITLE;
            break;
        case GAMEMODE_GP_END_CS:
            bgm = BGM_END_CS;
            break;
        case GAMEMODE_FLX_SKIPPABLE_CREDITS:
        case GAMEMODE_FLX_UNSKIPPABLE_CREDITS:
            bgm = BGM_CREDITS;
            break;
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
        case GAMEMODE_FLX_OPTIONS_MENU:
            bgm = BGM_OPTION;
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_MAIN_MENU:
        case GAMEMODE_FLX_MACHINE_SELECT:
        case GAMEMODE_FLX_COURSE_SELECT:
        case GAMEMODE_FLX_GP_RACE_NEXT_COURSE:
            bgm = BGM_SELECT;
            break;
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_CREATE_MACHINE:
            D_800CD154 = BGM_MUTE_CITY;
            return;
        default:
            break;
    }
    if (D_800CD154 != bgm) {
        func_8007E0CC();
        func_8007E08C();
        Audio_RomBgmStart(bgm);
    }
    D_800CD154 = bgm;
}

extern s16 gControllerReadDataStarted;
extern Controller gSharedController;
extern s32 gControllersConnected;
extern u16 gInputButtonPressed;

void func_80068F04(void) {

    if (gGameMode != gQueuedGameMode) {
        gTitleDemoState = TITLE_DEMO_INACTIVE;
        sTitleDemoCounter = 0;
        return;
    }
    Controller_SetGlobalInputs(&gSharedController);
    switch (gGameMode) {
        case GAMEMODE_FLX_TITLE:
            if (gControllersConnected != 0) {
                sTitleDemoCounter++;
            }
            if ((gTitleDemoState != TITLE_DEMO_INACTIVE) && (gControllersConnected != 0)) {

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
                sTitleDemoCounter = 0;
                gTitleDemoState = TITLE_DEMO_ACTIVE;
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
            if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
                sTitleDemoCounter++;
                switch (gTitleDemoState) {
                    case TITLE_DEMO_ACTIVE:
                        if (!(gInputButtonPressed & (BTN_A | BTN_START))) {
                            break;
                        }
                        /* fallthrough */
                    case TITLE_DEMO_START_EXIT:
                        gQueuedGameMode = GAMEMODE_FLX_TITLE;
                        sTitleDemoCounter = 0;
                        gTitleDemoState = TITLE_DEMO_EXIT;
                        break;
                    case TITLE_DEMO_EXIT:
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
        if (gGameModeChangeState == GAMEMODE_UPDATE) {
            if (gGameMode == -1) {
                gGameModeChangeState = GAMEMODE_CHANGE_INIT;
            } else {
                gGameModeChangeState = GAMEMODE_CHANGE_START;
            }
        }
    } else {
        func_80068BC0();
    }

    gMenuChangeMode = MENU_CHANGE_INACTIVE;
    switch (gGameModeChangeState) {
        case GAMEMODE_CHANGE_START:
        case GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_START):
        case GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START):
        case GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_START):
            Transition_HideSet();
            if (gControllerReadDataStarted) {
                Controller_UpdateInputs();
                gControllerReadDataStarted = false;
            }
            sGamemodeUpdateFuncs[GET_MODE(gGameMode)]();
            Transition_Update();
            if (D_800CD16C) {
                osContStartReadData(&gSerialEventQueue);
                gControllerReadDataStarted = true;
            }
            gGameModeChangeState++;
            return;
        case GAMEMODE_CHANGE_WAIT_TRANSITION:
        case GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_WAIT_TRANSITION):
        case GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_WAIT_TRANSITION):
        case GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_WAIT_TRANSITION):
            if (gControllerReadDataStarted) {
                Controller_UpdateInputs();
                gControllerReadDataStarted = false;
            }
            sGamemodeUpdateFuncs[GET_MODE(gGameMode)]();
            if (Transition_Update() != 0) {
                if (gGameMode == GAMEMODE_GP_RACE) {
                    Hud_ResetLivesChangeCounter();
                }
                gGameModeChangeState++;
            }
            if (D_800CD16C) {
                osContStartReadData(&gSerialEventQueue);
                gControllerReadDataStarted = true;
                return;
            }
            return;
        case GAMEMODE_CHANGE_INIT:
        case GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_INIT):
        case GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_INIT):
        case GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_INIT):
            Controller_Reset();
            switch (gGameMode) {
                case GAMEMODE_LX_MACHINE_SETTINGS:
                case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
                    if ((gNumPlayers == 1) && (gCourseIndex < COURSE_EDIT_1)) {
                        Save_UpdateCourseCharacterSave(gCourseIndex);
                    }
                    break;
                case GAMEMODE_FLX_MACHINE_SELECT:
                    func_i4_8011A7B8();
                    break;
            }
            gGameMode = gQueuedGameMode;
            if (gTitleDemoState == TITLE_DEMO_EXIT) {
                gTitleDemoState = TITLE_DEMO_INACTIVE;
            }
            gGamePaused = false;
            Arena_StartInit();

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
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
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
                case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
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
                CLEAR_OVERLAY_CACHE(SEGMENT_VRAM_START(ovl_i9), SEGMENT_DATA_START(ovl_i9) - SEGMENT_VRAM_START(ovl_i9),
                                    SEGMENT_DATA_START(ovl_i9), SEGMENT_BSS_START(ovl_i9) - SEGMENT_DATA_START(ovl_i9));
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
            Segment_LoadOverlays();
            func_80079EC8();
            sGamemodeInitFuncs[GET_MODE(gGameMode)]();
            func_80068DCC();
            Segment_LoadAssets();
            Transition_AppearSet();
            gGameModeChangeState = GAMEMODE_UPDATE;
            break;
        case GAMEMODE_CHANGE_START_RELOAD:
            Transition_HideSet();
            Transition_Update();
            gGameModeChangeState = GAMEMODE_CHANGE_WAIT_TRANSITION_RELOAD;
            break;
        case GAMEMODE_CHANGE_WAIT_TRANSITION_RELOAD:
            if (Transition_Update() != 0) {
                Transition_AppearSet();
                if (gGameMode != GAMEMODE_RECORDS) {
                    func_8007E08C();
                }
                func_80068DCC();
                func_80079F1C();
                func_i2_80103A70();
                gGameModeChangeState = GAMEMODE_UPDATE;
            }
            break;
        case GAMEMODE_UPDATE:
        default:
            break;
    }

    if (gControllerReadDataStarted) {
        Controller_UpdateInputs();
        gControllerReadDataStarted = false;
    }
    gQueuedGameMode = sGamemodeUpdateFuncs[GET_MODE(gGameMode)]();
    func_80068F04();
    switch (gGameModeChangeState) {
        case GAMEMODE_CHANGE_WAIT_TRANSITION_RELOAD:
            break;
        case GAMEMODE_UPDATE:
            Transition_Update();
            break;
    }
    if (D_800CD16C) {
        osContStartReadData(&gSerialEventQueue);
        gControllerReadDataStarted = true;
    }
}

extern s16 D_i2_80106DA0;

Gfx* func_80069698(Gfx* gfx) {

    if ((gGameModeChangeState != GAMEMODE_CHANGE_INIT) && D_i2_80106DA0) {
        gfx = sGamemodeDrawFuncs[GET_MODE(gGameMode)](gfx);
    }
    return Transition_Draw(gfx);
}
