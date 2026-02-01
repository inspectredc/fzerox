#include "global.h"
#include ASSET_HEADER_EK(course_edit_textures.h)

u8 D_xk2_80104280[] = {
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

char* func_xk2_800ED930(char* buffer, const char* fmt, size_t size) {
    return (char*) memcpy(buffer, fmt, size) + size;
}

Gfx* func_xk2_800ED954(Gfx* gfx, s32 arg1, s32 arg2, u8 arg3) {

    gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (arg1 + 6) << 2, (arg2 + 8) << 2, 0, ((arg3 % 10) * 6) << 5,
                        ((arg3 / 10) * 8) << 5, 1 << 10, 1 << 10);

    return gfx;
}

void func_xk2_800EDA34(Gfx** gfxP) {
    Gfx* gfx;

    gfx = *gfxP;

    gDPLoadTextureBlock_4b(gfx++, aCourseEditInfoFontSheetTex, G_IM_FMT_I, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    *gfxP = gfx;
}

void func_xk2_800EDAD0(Gfx** gfxP, s32 xPos, s32 yPos, const char* fmt, ...) {
    s32 charRemaining;
    u8* charPtr;
    char buffer[0x100];
    Gfx* gfx;
    u8 var_s0;
    va_list args;
    va_start(args, fmt);

    gfx = *gfxP;

    gDPLoadTextureBlock_4b(gfx++, aCourseEditInfoFontSheetTex, G_IM_FMT_I, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    charRemaining = _Printf(func_xk2_800ED930, buffer, fmt, args);

    if (charRemaining > 0) {
        charPtr = (s8*) buffer;
        while (charRemaining > 0) {
            var_s0 = *charPtr;
            if (var_s0 == ' ') {
                xPos += 6;
            } else {
                var_s0 = D_xk2_80104280[var_s0];
                gfx = func_xk2_800ED954(gfx, xPos, yPos, var_s0);
                if ((var_s0 == 0x14) || (var_s0 == 0x1D)) {
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

void func_xk2_800EDC88(Gfx** gfxP, s32 xPos, s32 yPos, const char* fmt, ...) {
    s32 charRemaining;
    u8* charPtr;
    char buffer[0x100];
    Gfx* gfx;
    u8 var_s0;
    va_list args;
    va_start(args, fmt);

    gfx = *gfxP;

    charRemaining = _Printf(func_xk2_800ED930, buffer, fmt, args);

    if (charRemaining > 0) {
        charPtr = (s8*) buffer;
        while (charRemaining > 0) {
            var_s0 = *charPtr;
            if (var_s0 == ' ') {
                xPos += 6;
            } else {
                var_s0 = D_xk2_80104280[var_s0];
                gfx = func_xk2_800ED954(gfx, xPos, yPos, var_s0);
                if ((var_s0 == 0x14) || (var_s0 == 0x1D)) {
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

void func_xk2_800EDD94(s8* arg0, s32 arg1) {
    bool var_v1;
    s16 i;
    s16 j;
    s8 sp8[0x10];

    i = 0;
    var_v1 = false;
    if (arg1 < 0) {
        arg1 = -arg1;
        var_v1 = true;
    }
    do {
        sp8[i++] = (arg1 % 10) + '0';
        arg1 /= 10;
    } while (arg1 > 0);

    if (var_v1) {
        sp8[i++] = '-';
    }

    for (j = 0; j < i; j++) {
        arg0[j] = sp8[i - j - 1];
    }
    arg0[j] = 0;
}

void func_xk2_800EDE68(s8* arg0, s32 arg1, s32 arg2) {
    bool var_v1;
    s16 i;
    s16 j;
    s8 sp8[0x10];
    s16 var_a0;

    i = 0;
    var_v1 = false;
    if (arg1 < 0) {
        arg1 = -arg1;
        var_v1 = true;
    }
    do {
        sp8[i++] = (arg1 % 10) + '0';
        arg1 /= 10;
    } while (arg1 > 0);

    if (var_v1) {
        sp8[i++] = '-';
    }

    if (i < arg2) {
        var_a0 = arg2 - i;
        for (j = 0; j < var_a0; j++) {
            sp8[i++] = ' ';
        }
    }

    for (j = 0; j < i; j++) {
        arg0[j] = sp8[i - j - 1];
    }
    arg0[j] = 0;
}
