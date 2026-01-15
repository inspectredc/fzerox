#ifndef OVL_I2_H
#define OVL_I2_H

#include "PR/ultratypes.h"
#include "other_types.h"

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
