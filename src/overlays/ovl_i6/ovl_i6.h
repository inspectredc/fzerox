#ifndef OVL_I6_H
#define OVL_I6_H

#include "fzx_save.h"

typedef enum OptionsRow {
    /* 0 */ OPTIONS_VS_COM,
    /* 1 */ OPTIONS_VS_SLOT,
    /* 2 */ OPTIONS_VS_HANDICAP,
    /* 3 */ OPTIONS_SOUND_MODE,
    /* 4 */ OPTIONS_DATA_CLEAR,
    /* 5 */ OPTIONS_GHOST_COPY,
    /* 6 */ OPTIONS_EXIT,
    /* 7 */ OPTIONS_MAX
} OptionsRow;

#define OPTIONS_DATA_CLEAR_MENU_CLOSED 0
#define OPTIONS_DATA_CLEAR_MENU_OPEN 1

typedef struct unk_8011DC40 {
    f32 unk_00;
    f32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
} unk_8011DC40; // UNUSED?

#define OPTIONS_REQUIRE_SELECTING 1
#define OPTIONS_SHOWN 2

typedef struct OptionsInfo {
    /* 0x00 */ OptionsRow row;
    /* 0x04 */ u16 flags;
    /* 0x08 */ s32 totalSelectionStates;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ TextureInfo* selectionStateTextureInfo;
    /* 0x18 */ TextureInfo optionTextureInfo;
} OptionsInfo; // size = 0x20

bool func_i6_8011C788(void);
void func_i6_80083390(void);
Gfx* func_i6_8011D168(Gfx*, s32, s32);

#endif // OVL_I6_H
