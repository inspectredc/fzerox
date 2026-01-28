#ifndef MENUS_H
#define MENUS_H

#include "gfx.h"
#include "fzx_racer.h"

typedef enum RaceMenuTextures{
    /* 0x00 */ RACE_MENU_RETRY,                 // retry
    /* 0x01 */ RACE_MENU_SETTINGS,              // settings
    /* 0x02 */ RACE_MENU_QUIT,                  // quit
    /* 0x03 */ RACE_MENU_CHANGE_MACHINE,        // change machine
    /* 0x04 */ RACE_MENU_CHANGE_COURSE,         // change course
    /* 0x05 */ RACE_MENU_GHOST_SAVE,            // ghost save
    /* 0x06 */ RACE_MENU_OVERWRITE_DATA1,       // overwrite data?
    /* 0x07 */ RACE_MENU_SAVING,                // saving
    /* 0x08 */ RACE_MENU_TO_GAME_PAK,           // to game pak
    /* 0x09 */ RACE_MENU_TO_DISK,               // to disk
    /* 0x0A */ RACE_MENU_OVERWRITE_DATA2,       // overwrite data?
    /* 0x0B */ RACE_MENU_CLEAR_RECORD,          // clear record
    /* 0x0C */ RACE_MENU_ERASE_COURSE_DATA1,    // erase saved data for this course?
    /* 0x0D */ RACE_MENU_CLEAR_GHOST,           // clear ghost
    /* 0x0E */ RACE_MENU_ERASE_COURSE_DATA2,    // erase saved data for this course?
    /* 0x0F */ RACE_MENU_CONTINUE,              // continue
    /* 0x10 */ RACE_MENU_YES,                   // yes
    /* 0x11 */ RACE_MENU_NO,                    // no
    /* 0x12 */ RACE_MENU_SAVED,                 // saved
    /* 0x13 */ RACE_MENU_NEW_GHOST,             // new ghost
    /* 0x14 */ RACE_MENU_SAVED_GHOST,           // saved ghost
    /* 0x15 */ RACE_MENU_CANNOT_SAVE_GHOST,     // race data cannot be saved for ghost
    /* 0x16 */ RACE_MENU_LEFT_ARROW,            // left arrow
    /* 0x17 */ RACE_MENU_RIGHT_ARROW,           // right arrow
    /* 0x18 */ RACE_MENU_MAX,
} RaceMenuTextures;

typedef enum TimeAttackFinishOptions {
    /* 0 */ TIME_ATTACK_RETRY,
    /* 1 */ TIME_ATTACK_SAVE_GHOST,
    /* 2 */ TIME_ATTACK_SETTINGS,
    /* 3 */ TIME_ATTACK_CHANGE_MACHINE,
    /* 4 */ TIME_ATTACK_CHANGE_COURSE,
    /* 5 */ TIME_ATTACK_QUIT,
} TimeAttackFinishOptions;

typedef enum GpResultsEndMenuOptions {
    /* 0 */ GP_RESULTS_END_RETRY,
    /* 1 */ GP_RESULTS_END_SETTINGS,
    /* 2 */ GP_RESULTS_END_CHANGE_MACHINE,
    /* 3 */ GP_RESULTS_END_CHANGE_COURSE,
    /* 4 */ GP_RESULTS_END_QUIT,
} GpResultsEndMenuOptions;

typedef enum VsResultsOptions {
    /* 0 */ VS_RESULTS_COURSE_SELECT,
    /* 1 */ VS_RESULTS_QUIT,
} VsResultsOptions;

typedef enum GhostSaveMenuState {
    /* 0 */ GHOST_SAVE_MENU_CLOSED,
    /* 1 */ GHOST_SAVE_MENU_SAVE_TO_PAK,
    /* 2 */ GHOST_SAVE_MENU_DISK_OPTIONS,
} GhostSaveMenuState;

typedef enum GhostSaveMenuOptionState {
    /* 0 */ GHOST_SAVE_MENU_SHOW_OPTIONS,
    /* 1 */ GHOST_SAVE_MENU_SAVE_TO_DISK,
} GhostSaveMenuOptionState;

typedef enum GhostSaveMenuOption {
    /* 0 */ GHOST_SAVE_MENU_OPTION_SAVE_TO_PAK,
    /* 1 */ GHOST_SAVE_MENU_OPTION_SAVE_TO_DISK,
} GhostSaveMenuOption;

typedef enum NoYesMenuOption {
    /* 0 */ MENU_OPTION_NO,
    /* 1 */ MENU_OPTION_YES,
} NoYesMenuOption;

#define GHOST_SAVE_CANNOT_SAVE_TO_PAK 1
#define GHOST_SAVE_CANNOT_SAVE_TO_DISK 2

typedef enum PauseGeneralOptions {
    /* 0 */ PAUSE_GENERAL_CONTINUE,
    /* 1 */ PAUSE_GENERAL_RETRY,
    /* 2 */ PAUSE_GENERAL_SETTINGS,
    /* 3 */ PAUSE_GENERAL_CHANGE_MACHINE,
    /* 4 */ PAUSE_GENERAL_CHANGE_COURSE,
    /* 5 */ PAUSE_GENERAL_QUIT,
} PauseGeneralOptions;

typedef enum PauseDeathRaceOptions {
    /* 0 */ PAUSE_DEATH_RACE_CONTINUE,
    /* 1 */ PAUSE_DEATH_RACE_RETRY,
    /* 2 */ PAUSE_DEATH_RACE_SETTINGS,
    /* 3 */ PAUSE_DEATH_RACE_CHANGE_MACHINE,
    /* 4 */ PAUSE_DEATH_RACE_QUIT,
} PauseDeathRaceOptions;

typedef enum PauseGpOptions {
    /* 0 */ PAUSE_GP_CONTINUE,
    /* 1 */ PAUSE_GP_RETRY,
    /* 2 */ PAUSE_GP_SETTINGS,
    /* 3 */ PAUSE_GP_QUIT,
} PauseGpOptions;

typedef enum VsSlotNumber {
    /* 0 */ VS_SLOT_0,
    /* 1 */ VS_SLOT_1,
    /* 2 */ VS_SLOT_2,
} VsSlotNumber;

typedef enum VsSlotState {
    /* 0 */ VS_SLOT_STATE_CURRENT_SLOT_0,
    /* 1 */ VS_SLOT_STATE_CURRENT_SLOT_1,
    /* 2 */ VS_SLOT_STATE_CURRENT_SLOT_2,
    /* 3 */ VS_SLOT_STATE_CHECK_RESULT,
    /* 4 */ VS_SLOT_STATE_APPLY_RESULT,
    /* 5 */ VS_SLOT_STATE_WAIT_FOR_RESPIN,
} VsSlotState;

typedef enum VsSlotPortrait {
    /* 30 */ VS_SLOT_PORTRAIT_X = TOTAL_RACER_COUNT,
    /* 31 */ VS_SLOT_PORTRAIT_SKULL,
    /* 32 */ VS_SLOT_PORTRAIT_MR_ZERO,
} VsSlotPortrait;

typedef enum GpResultsState {
    /*   0 */ GP_RESULTS_TOP_6_TIMING,
    /*   1 */ GP_RESULTS_RACE_RESULT,
    /*   2 */ GP_RESULTS_TOTAL_RANKING,
    /*   3 */ GP_RESULTS_END_MENU,
    /*   4 */ GP_RESULTS_QUIT,
    /*   5 */ GP_RESULTS_TO_NEXT_COURSE,
    /* 255 */ GP_RESULTS_COMPLETE = 255,
} GpResultsState;

typedef enum PlayerFinishState {
    /* 0 */ PLAYER_FINISH_NONE,
    /* 1 */ PLAYER_FINISH_CAMERA_SUCCESS,
    /* 2 */ PLAYER_FINISH_SUCCESS_COMPLETE,
} PlayerFinishState;

typedef enum PlayerGameoverState {
    /* 0 */ PLAYER_GAMEOVER_NONE,
    /* 1 */ PLAYER_GAMEOVER_CRASHED,
    /* 2 */ PLAYER_GAMEOVER_DISPLAY,
} PlayerGameoverState;

#define MENU_STATE_PAUSE_GAME (1 << 0)
#define MENU_STATE_UNPAUSE_GAME (1 << 1)
#define MENU_STATE_RACE_FINISH_SAVE (1 << 2)
#define MENU_STATE_RETRY (1 << 3)
#define MENU_STATE_QUIT (1 << 4)
#define MENU_STATE_CHANGE_MACHINE (1 << 5)
#define MENU_STATE_CHANGE_COURSE (1 << 6)
#define MENU_STATE_SETTINGS (1 << 7)
#define MENU_STATE_100 (1 << 8)
#define MENU_STATE_GP_NEXT_COURSE (1 << 9)
#define MENU_STATE_RETIRE_RESTART (1 << 10)

Gfx* Menus_DrawBeveledBox(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha);

void Menus_GetFastestGhostInfo(void);

#endif // MENUS_H
