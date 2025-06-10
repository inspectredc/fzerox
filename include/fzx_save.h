#ifndef FZX_SAVE_H
#define FZX_SAVE_H

#include "unk_structs.h"

typedef enum GhostType {
    /* 0 */ GHOST_NONE,
    /* 1 */ GHOST_PLAYER,
    /* 2 */ GHOST_STAFF,
    /* 3 */ GHOST_CELEBRITY,
    /* 4 */ GHOST_CHAMP,
} GhostType;

typedef struct SaveCourseRecords {
    u16 checksum;
    s16 unk_02;
    s32 timeRecord[5];
    f32 engines[5];
    f32 maxSpeed;
    s32 bestTime;
    u8 name[5][4];
    u8 unk_48[8];
    unk_80141C88_unk_1D unk_50[5];
    unk_80141C88_unk_1D unk_F0;
} SaveCourseRecords; // size = 0x110

typedef struct CharacterSave {
    u16 checksum;
    u16 unk_02;
    s32 unk_04;
    f32 characterEngine[30];
} CharacterSave; // size = 0x80

typedef struct SaveEditCup {
    u16 checksum;
    s16 unk_02;
    s32 unk_04;
    s16 unk_08;
    u8 editCupTrackNames[6][9];
} SaveEditCup; // size = 0x40

typedef struct SaveSettings {
    u8 fileName[8];
    u8 settings;
    u8 customUnlocks;
    u8 cupDifficultiesCleared[4];
    u16 checksum;
} SaveSettings; // size = 0x10

typedef struct SaveDeathRace {
    u16 checksum;
    s16 unk_02;
    s32 timeRecord[1];
    u8 unk_08[8];
} SaveDeathRace; // size = 0x10

typedef struct ProfileSave {
    SaveSettings saveSettings;
    SaveDeathRace deathRace;
    SaveCourseRecords courses[24];
    SaveEditCup editCup;
} ProfileSave; // size = 0x19E0

typedef struct GhostRecord {
    u16 checksum;
    u16 ghostType;
    s32 replayChecksum;
    s32 encodedCourseIndex;
    s32 raceTime;
    u16 unk_10;
    s8 unk_12[5];
    u8 trackName[9];
    unk_80141C88_unk_1D unk_20;
} GhostRecord; // size = 0x40

typedef struct GhostReplayInfo {
    /* 0x00 */ u16 checksum;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 lapTimes[3];
    /* 0x10 */ s32 end;
    /* 0x14 */ u32 size;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} GhostReplayInfo; // size = 0x20

typedef struct GhostData {
    /* 0x0000 */ GhostReplayInfo replayInfo;
    /* 0x0020 */ u8 replayData[16200];
    /* 0x3F68 */ s8 unk_3F68[0x18];
} GhostData; // size = 0x3F80

typedef struct CupSave {
    u16 checksum;
    s8 unk_02[0xE];
    u16 cupCompletion[4][10];
} CupSave; // size = 0x60

typedef struct SaveContext {
    ProfileSave profileSaves[2];
    GhostRecord ghostRecord;
    GhostData ghostData;
    CharacterSave characterSaves[24];
    CupSave cupSave;
    s8 unk_7FE0[0x20];
} SaveContext; // size = 0x8000

s32 Save_Init(SaveContext*, s32);

#define REPLAY_DATA_LARGE_FLAG -0x80
#define REPLAY_DATA_LARGE(x) REPLAY_DATA_LARGE_FLAG, (((x) >> 8) & 0xFF), ((x) & 0xFF)

#endif // FZX_SAVE_H
