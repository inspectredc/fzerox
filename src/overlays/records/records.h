#ifndef RECORDS_H
#define RECORDS_H

#include "unk_structs.h"

typedef struct RecordsMenuInfo {
    /* 0x0 */ s32 menuOption;
    /* 0x4 */ TextureInfo textureInfo;
#ifdef EXPANSION_KIT
    /* 0xC */ void* tlut;
#endif
} RecordsMenuInfo; // size = 0xC

typedef struct GhostMarkerRenderInfo {
    /* 0x00 */ Mtx mtx;
    /* 0x40 */ Vtx vtx[4];
} GhostMarkerRenderInfo; // size = 0x80

typedef enum RecordsState {
    /* 0 */ RECORDS_STATE_VIEW_RECORDS,
    /* 1 */ RECORDS_STATE_RECORDS_MENU,
    /* 2 */ RECORDS_STATE_CONFIRM_CLEAR,
    /* 3 */ RECORDS_STATE_3,
    /* 4 */ RECORDS_STATE_COPY_GHOST_MENU,
    /* 5 */ RECORDS_STATE_COPY_WHERE_MENU,
    /* 6 */ RECORDS_STATE_COPY_TO_DISK_MENU,
    /* 7 */ RECORDS_STATE_SHOW_COPYING_INFO,
} RecordsState;

typedef enum RecordsMenuOption {
    /* 0 */ RECORDS_MENU_CLEAR_RECORD,
    /* 1 */ RECORDS_MENU_CLEAR_GHOST,
    /* 2 */ RECORDS_MENU_QUIT,
    /* 3 */ RECORDS_MENU_CHANGE_COURSE,
    /* 4 */ RECORDS_MENU_COPY_GHOST,
} RecordsMenuOption;

typedef enum RecordsMoveDirection {
    /* 0 */ RECORDS_FROM_MENU,
    /* 1 */ RECORDS_MOVE_RIGHT,
    /* 2 */ RECORDS_MOVE_LEFT,
} RecordsMoveDirection;

typedef enum RecordsClearType {
    /* 0 */ RECORDS_CLEAR_RECORDS,
    /* 1 */ RECORDS_CLEAR_GHOST,
} RecordsClearType;

typedef enum RecordsClearSelection {
    /* 0 */ RECORDS_CLEAR_NO,
    /* 1 */ RECORDS_CLEAR_YES,
} RecordsClearSelection;

typedef enum RecordsGhostType {
    /* 0 */ RECORDS_GHOST_CASSETTE,
    /* 1 */ RECORDS_GHOST_DISK_1,
    /* 2 */ RECORDS_GHOST_DISK_2,
    /* 3 */ RECORDS_GHOST_DISK_3,
} RecordsGhostType;

typedef enum GhostMarkerState {
    /* 0 */ GHOST_MARKER_NONE,
    /* 1 */ GHOST_MARKER_SHOWN,
    /* 2 */ GHOST_MARKER_FADE_OUT,
} GhostMarkerState;

typedef enum RecordsCopyLocation {
    /* 0 */ RECORDS_COPY_TO_GAME_PAK,
    /* 1 */ RECORDS_COPY_TO_DISK,
} RecordsCopyLocation;

typedef enum RecordsCopyingState {
    /* 0 */ RECORDS_GHOST_COPIED,
    /* 1 */ RECORDS_INSERT_DISK,
} RecordsCopyingState;

void Records_InitData(void);
bool Records_CourseHasNoRecords(s32 courseIndex);
bool Records_CourseHasGhost(s32 courseIndex);
s32 Records_MenuUpdate(void);
s32 Records_ViewRecordsUpdate(void);
void Records_ClearConfirmUpdate(void);
void Records_UpdateGhostMarker(void);
Gfx* Records_DrawGhostMarker(Gfx* gfx);
Gfx* Records_MenuDraw(Gfx* gfx, s32 left, s32 top);
Gfx* Records_DrawClearConfirm(Gfx* gfx, s32 left, s32 top);

#endif // RECORDS_H
