#include "global.h"
#include ASSET_HEADER_EK(course_edit_textures.h)

u8 sCourseEditInfoFontMap[] = {
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 34,  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 39,
    19,  255, 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   255, 255, 255, 255, 255, 255, 255, 13,  255, 255, 255,
    255, 255, 15,  16,  255, 255, 255, 255, 35,  14,  255, 255, 255, 255, 255, 17,  255, 255, 255, 10,  11,  12,  255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 18,  255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 26,  255, 21,  37,  255, 255, 255, 255,
    255, 255, 255, 255, 30,  24,  255, 255, 33,  255, 255, 255, 27,  255, 255, 255, 28,  255, 20,  255, 22,  25,  255,
    255, 255, 29,  255, 255, 255, 255, 255, 255, 31,  29,  255, 38,  255, 32,  36,  23,
};

char* CourseEdit_InfoPrOut(char* buffer, const char* fmt, size_t size) {
    return (char*) memcpy(buffer, fmt, size) + size;
}

Gfx* CourseEdit_DrawInfoChar(Gfx* gfx, s32 left, s32 top, u8 charValue) {

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 6) << 2, (top + 8) << 2, 0, ((charValue % 10) * 6) << 5,
                        ((charValue / 10) * 8) << 5, 1 << 10, 1 << 10);

    return gfx;
}

void CourseEdit_LoadInfoFontSheet(Gfx** gfxP) {
    Gfx* gfx;

    gfx = *gfxP;

    gDPLoadTextureBlock_4b(gfx++, aCourseEditInfoFontSheetTex, G_IM_FMT_I, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    *gfxP = gfx;
}

void CourseEdit_DrawInfoEncStr(Gfx** gfxP, s32 xPos, s32 yPos, const char* fmt, ...) {
    s32 charRemaining;
    u8* charPtr;
    char buffer[0x100];
    Gfx* gfx;
    u8 charValue;
    va_list args;
    va_start(args, fmt);

    gfx = *gfxP;

    gDPLoadTextureBlock_4b(gfx++, aCourseEditInfoFontSheetTex, G_IM_FMT_I, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    charRemaining = _Printf(CourseEdit_InfoPrOut, buffer, fmt, args);

    if (charRemaining > 0) {
        charPtr = (s8*) buffer;
        while (charRemaining > 0) {
            charValue = *charPtr;
            if (charValue == ' ') {
                xPos += 6;
            } else {
                charValue = sCourseEditInfoFontMap[charValue];
                gfx = CourseEdit_DrawInfoChar(gfx, xPos, yPos, charValue);
                if ((charValue == 20) || (charValue == 29)) {
                    xPos += 4;
                } else {
                    xPos += 6;
                }
            }
            charRemaining--;
            charPtr++;
        }
    }
    va_end(args);

    *gfxP = gfx;
}

void CourseEdit_DrawLoadedInfoEncStr(Gfx** gfxP, s32 xPos, s32 yPos, const char* fmt, ...) {
    s32 charRemaining;
    u8* charPtr;
    char buffer[0x100];
    Gfx* gfx;
    u8 charValue;
    va_list args;
    va_start(args, fmt);

    gfx = *gfxP;

    charRemaining = _Printf(CourseEdit_InfoPrOut, buffer, fmt, args);

    if (charRemaining > 0) {
        charPtr = (s8*) buffer;
        while (charRemaining > 0) {
            charValue = *charPtr;
            if (charValue == ' ') {
                xPos += 6;
            } else {
                charValue = sCourseEditInfoFontMap[charValue];
                gfx = CourseEdit_DrawInfoChar(gfx, xPos, yPos, charValue);
                if ((charValue == 20) || (charValue == 29)) {
                    xPos += 4;
                } else {
                    xPos += 6;
                }
            }
            charRemaining--;
            charPtr++;
        }
    }
    va_end(args);

    *gfxP = gfx;
}

void CourseEdit_NumToInfoEncStr(s8* str, s32 num) {
    bool isNegative;
    s16 i;
    s16 j;
    s8 numStrReverse[0x10];

    i = 0;
    isNegative = false;
    if (num < 0) {
        num = -num;
        isNegative = true;
    }
    do {
        numStrReverse[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (isNegative) {
        numStrReverse[i++] = '-';
    }

    for (j = 0; j < i; j++) {
        str[j] = numStrReverse[i - j - 1];
    }
    str[j] = '\0';
}

void CourseEdit_NumToPaddedInfoEncStr(s8* str, s32 num, s32 padStrLen) {
    bool isNegative;
    s16 i;
    s16 j;
    s8 numStrReverse[0x10];
    s16 padSize;

    i = 0;
    isNegative = false;
    if (num < 0) {
        num = -num;
        isNegative = true;
    }
    do {
        numStrReverse[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (isNegative) {
        numStrReverse[i++] = '-';
    }

    if (i < padStrLen) {
        padSize = padStrLen - i;
        for (j = 0; j < padSize; j++) {
            numStrReverse[i++] = ' ';
        }
    }

    for (j = 0; j < i; j++) {
        str[j] = numStrReverse[i - j - 1];
    }
    str[j] = '\0';
}
