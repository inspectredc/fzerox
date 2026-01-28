#ifndef FZX_FONT_H
#define FZX_FONT_H

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

// FONT_SET_5 special strings
#define FONT_STR_ST "Ｓ"
#define FONT_STR_ND "Ｎ"
#define FONT_STR_RD "Ｒ"
#define FONT_STR_TH "Ｔ"
#define FONT_STR_PLAYER "Ｐ"
#define FONT_STR_COMPUTER "Ａ"
#define FONT_STR_SELECT_COURSE "Ｃ"
#define FONT_STR_QUIT "Ｅ"
#define FONT_STR_UP_ARROW "Ｕ"
#define FONT_STR_DOWN_ARROW "Ｄ"
#define FONT_STR_SIDE_ARROW "Ｍ"

// FONT_SET_6 special strings
#define FONT_STR_ALPHA "Ａ"
#define FONT_STR_BETA "Ｂ"

void Font_IntToString(s32 num, s8* str);
s32 Font_GetCharIndex(s8* str, s32 fontSetLowercase);
s32 Font_GetCharacterWidth(s8* str, s32 fontSet);
s32 Font_GetStringWidth(s8* str, s32 fontSet, s32 additionalSpacing);
void Font_LoadString(s8* str, s32 fontSet);
Gfx* Font_DrawString(Gfx* gfx, s32 left, s32 top, s8* str, s32 additionalSpacing, s32 fontSet, s32 arg6);
Gfx* Font_DrawScaledString(Gfx* gfx, s32 left, s32 top, s8* str, s32 additionalSpacing, s32 fontSet, s32 arg6, f32 scaleX, f32 scaleY);
Gfx* Font_DrawMachineStatValue(Gfx* gfx, s32 left, s32 top, s32 statValue);
Gfx* Font_DrawMachineStatValueSmall(Gfx* gfx, s32 left, s32 top, s32 statValue);
Gfx* Font_DrawMachineWeight(Gfx* gfx, s32 left, s32 top, u32 weight);
Gfx* Font_DrawMachineWeightSmall(Gfx* gfx, s32 left, s32 top, u32 weight);

#endif // FZX_FONT_H
