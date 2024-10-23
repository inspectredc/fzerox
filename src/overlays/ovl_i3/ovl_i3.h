#ifndef OVL_I3_H
#define OVL_I3_H

#include "unk_structs.h"

#define MAX_TIMER (60 * 60 * 1000 - 1)

typedef struct unk_8013E7A8 {
    s16 unk_00;
    s8 unk_02;
    s8 unk_03[11];
} unk_8013E7A8; // size = 0xE

typedef struct CourseBackgroundFloor {
    void* unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
} CourseBackgroundFloor; // size = 0x14

typedef struct CourseSkyboxes {
    void* unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u8 unk_0D[0x1];
    u16 unk_0E;
} CourseSkyboxes; // size = 0x10

typedef struct unk_80142180 {
    CourseBackgroundFloor* unk_00;
    CourseSkyboxes* unk_04;
} unk_80142180; // size = 0x8

typedef struct unk_80141860 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
} unk_80141860; // size = 0x20 (possibly unk_struct_20)

typedef struct unk_80141FF0 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    unk_80141860 unk_1C;
    unk_80141860 unk_3C;
    f32 unk_5C;
} unk_80141FF0; // size = 0x60

typedef struct unk_80140E58 {
    s16 unk_00;
    f32 unk_04;
} unk_80140E58; // size = 0x8

typedef struct unk_801421A0 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s8 unk_06[0x2];
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    TexturePtr unk_14;
    u16* unk_18;
} unk_801421A0; // size = 0x1C

typedef struct unk_80142248 {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04[16];
} unk_80142248; // size = 0x24

typedef struct unk_80142320 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    s8 unk_04[4];
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14[4][2];
} unk_80142320; // size = 0x34

typedef struct unk_801437C0 {
    s8 unk_00;
    s8 unk_01;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
} unk_801437C0; // size = 0xA

typedef struct unk_80141EA8 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    unk_8012F450 unk_0C;
    s8 unk_18[0x30];
} unk_80141EA8; // size = 0x48


typedef enum RaceMenuTextures{
    /* 0x00 */ RACE_MENU_RETRY,                 // retry
    /* 0x01 */ RACE_MENU_SETTINGS,              // settings
    /* 0x02 */ RACE_MENU_QUIT,                  // quit
    /* 0x03 */ RACE_MENU_CHANGE_MACHINE,        // change machine
    /* 0x04 */ RACE_MENU_CHANGE_COURSE,         // change course
    /* 0x05 */ RACE_MENU_GHOST_SAVE,            // ghost save
    /* 0x06 */ RACE_MENU_OVERWRITE_DATA1,       // overwrite data?
    /* 0x07 */ RACE_MENU_SAVING,                // saving
    /* 0x08 */ RACE_MENU_NO_GAME_PAK,           // no game pak
    /* 0x09 */ RACE_MENU_NO_DISK,               // no disk
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

void func_i3_801175A4(void);
Gfx* func_i3_DrawBeveledBox(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha);

Gfx* func_i3_8012EE90(Gfx* gfx, s32 arg1);

Gfx* func_i3_8012F554(Gfx* gfx, s32 time, s32 left, s32 top, f32 scale);
Gfx* func_i3_80130824(Gfx*, s32, s32);
Gfx* func_i3_801312DC(Gfx*, s32, s32);
Gfx* func_i3_DrawHUD(Gfx*);
Gfx* func_i3_80132EEC(Gfx*);
Gfx* func_i3_80133944(Gfx* gfx, s32 time, s32 left, s32 top, f32 scale);
Gfx* func_i3_80135B20(Gfx*, s32, s32);
void func_i3_80139FF4(void);
bool func_i3_8013A004(void);
Gfx* func_i3_8013A360(Gfx*, s32);
void func_i3_8013C15C(void);
Gfx* func_i3_8013D2BC(Gfx*);

extern s32 D_80141900;

extern bool D_i3_801419BC;

extern unk_80141EA8 D_i3_80141EA8[];

extern s32 D_i3_8013F008[];
extern TexturePtr sCharacterPortraitTextures[];

extern s32 D_i3_80140788[];

#endif // OVL_I3_H
