#ifndef OVL_I2_H
#define OVL_I2_H

#include "PR/ultratypes.h"
#include "other_types.h"

typedef struct unk_8010D778_unk_18 {
    s8 unk_00;
    u8 unk_01;
} unk_8010D778_unk_18; // size = 0x2

typedef struct unk_8010D778_unk_18_2 {
    s8 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
} unk_8010D778_unk_18_2; // size = 0x1C

typedef struct unk_8010D778_unk_18_3 {
    s8 unk_00;
    s8 unk_01;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
} unk_8010D778_unk_18_3; // size = 0x14

typedef struct unk_8010D778_unk_1C {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
} unk_8010D778_unk_1C; // size = 0x14

typedef struct unk_8010D778 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s16 unk_0C;
    s16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    TexturePtr unk_14;
    void* unk_18;
    unk_8010D778_unk_1C unk_1C;
} unk_8010D778; // size = 0x30

typedef enum FontSet {
    /* 1 */ FONT_SET_1 = 1,
    /* 2 */ FONT_SET_2,
    /* 3 */ FONT_SET_3,
    /* 4 */ FONT_SET_4,
    /* 5 */ FONT_SET_5,
    /* 6 */ FONT_SET_6,
} FontSet;

typedef enum FontSetCase {
    /* 0 */ FONT_SET_UPPERCASE_ONLY,
    /* 1 */ FONT_SET_HAS_LOWERCASE,
} FontSetCase;

// More font symbols are shared than enums may imply
typedef enum FontChar {
    /* -2 */ FONT_CHAR_UNKNOWN = -2,
    /* -1 */ FONT_CHAR_SPACE = -1,
    /* 0 - 26, A-Z */
    /* 26 */ FONT_CHAR_PRIME = 26,
    /* 27 */ FONT_CHAR_DOUBLE_PRIME,
    /* 28 */ FONT_CHAR_AMPERSAND,
    /* 29 */ FONT_CHAR_PLUS,
    /* 30 */ FONT_CHAR_MINUS,
    /* 31 */ FONT_CHAR_POINTS_KG,
    /* 32 - 42, 0-9 */
    /* 42 */ FONT_CHAR_COLON = 42,
    /* 43 */ FONT_CHAR_PERIOD,
    /* 44 */ FONT_CHAR_ELLIPSIS,
    /* 45 */ FONT_CHAR_OPEN_PARENTHESIS,
    /* 46 */ FONT_CHAR_CLOSE_PARENTHESIS,
    /* 47 */ FONT_CHAR_COMMA,
    /* 48 ->, a-z/katakana */
} FontChar;

extern u8 gSaveBuffer[];

#endif // OVL_I2_H
