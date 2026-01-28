#ifndef RECORDS_ENTRY_H
#define RECORDS_ENTRY_H

#include "gfx.h"
#include "unk_structs.h"

typedef struct KeyboardObject {
    signed char keyboardCharacter[2];
    s16 randLeftTarget;
    s16 randTopTarget;
    s16 left;
    s16 top;
} KeyboardObject; // size = 0xA

#define RECORDS_ENTRY_DRAW_COURSE_WITH_ARROWS (1 << 0)
#define RECORDS_ENTRY_FILTER_BACKGROUND (1 << 1)
#define RECORDS_ENTRY_DRAW_ENGINE_SETTINGS (1 << 2)
#define RECORDS_ENTRY_HIGHLIGHT_CURRENT (1 << 3)
#define RECORDS_ENTRY_LOAD_ARROWS (1 << 4)
#define RECORDS_ENTRY_DRAW_ARROWS (1 << 5)
#define RECORDS_ENTRY_DRAW_NAME_BOX (1 << 6)

#define KEYBOARD_COLUMN_COUNT 10
#define KEYBOARD_ROW_COUNT 5
#define KEYBOARD_TOTAL_COUNT KEYBOARD_COLUMN_COUNT * KEYBOARD_ROW_COUNT

typedef enum NameEntryState {
    /* 0 */ NAME_ENTRY_START,
    /* 1 */ NAME_ENTRY_TRANSITION_IN,
    /* 2 */ NAME_ENTRY_KEYBOARD,
    /* 3 */ NAME_ENTRY_TRANSITION_OUT,
} NameEntryState;

typedef enum RecordsEntryState {
    /* 0 */ RECORDS_ENTRY_WAIT_NAME_ENTRY,
    /* 1 */ RECORDS_ENTRY_TRANSITION_RECORDS,
    /* 2 */ RECORDS_ENTRY_RECORDS,
} NameEntrySRecordsEntryStatetate;

void RecordsEntry_Init(void);
void RecordsEntry_ToRecordsState(void);
bool RecordsEntry_Update(void);
Gfx* RecordsEntry_DrawRecords(Gfx* gfx, s32 courseIndex);
void RecordsEntry_SetDrawArrows(bool drawArrows);
Gfx* RecordsEntry_DrawRecordMachine(Gfx* gfx, s32 recordsIndex, MachineInfo* machineInfo);
Gfx* RecordsEntry_DrawRecordEngineSetting(Gfx* gfx, s32 left, s32 top, f32 engineValue);
void RecordsEntry_UpdateRaceStats(s32 courseIndex);
void RecordsEntry_ClearCurrentRecordName(void);
void RecordsEntry_InitNameEntry(void);
void RecordsEntry_UpdateNameEntry(void);
void RecordsEntry_UpdateNameEntryStart(void);
void RecordsEntry_UpdateNameEntryTransition(bool transitionKeysAway);
void RecordsEntry_UpdateNameEntryKeyboard(void);
s32 RecordsEntry_GetCharacterKeyboardIndex(s8 character);
void RecordsEntry_SaveRecordName(CourseInfo* courseInfo);
Gfx* RecordsEntry_DrawNameEntry(Gfx* gfx);

#endif // RECORDS_ENTRY_H
