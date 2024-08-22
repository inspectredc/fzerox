#include "global.h"

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/18410/func_8007E410.s")

void func_8007ECCC(u16* arg0, s32 arg1) {
    s32 i;
    u32 colorBlend;
    u32 red, green, blue, alpha;

    for (i = 0; i < (arg1 / 2); i++, arg0++) {
        red = ((*arg0 & 0xF800) >> 11) * 77;
        green = ((*arg0 & 0x7C0) >> 6) * 150;
        blue = ((*arg0 & 0x3E) >> 1) * 29;
        alpha = *arg0 & 0x1;

        colorBlend = (0x1F00 - red - green - blue) >> 8;

        *arg0 = (colorBlend << 1) + (colorBlend << 6) + (colorBlend << 11) + alpha;
    }
}

s32 func_8007EF68(u16* arg0, s32 arg1, u16 arg2) {
    s32 i;
    s32 index;

    if (arg1 == 0) {
        return -1;
    }
    index = -1;

    for (i = 0; i < arg1; i++, arg0++) {
        if (*arg0 == arg2) {
            index = i;
            break;
        }
    }

    return index;
}

s32 func_8007EFBC(u16* arg0, u16* arg1, s32 arg2) {
    s32 i;
    s32 temp_v0;
    u8* var_s0 = (u8*) arg0;
    s32 var_s2 = 0;
    u16* var_s3 = arg1;

    for (i = 0; i < arg2; i++, arg0++) {
        temp_v0 = func_8007EF68(arg1, var_s2, *arg0);
        if (temp_v0 == -1) {
            if (var_s2 >= 0x100) {
                return -1;
            }
            *var_s0 = var_s2;
            *var_s3 = *arg0;
            var_s0++;
            var_s3++;
            var_s2++;
        } else {
            *var_s0 = temp_v0;
            var_s0++;
        }
    }

    return var_s2;
}

extern s32 D_800CCFE0;

Gfx* func_8007F090(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    u32 red;
    u32 green;
    u32 blue;
    s32 temp_v0 = D_800CCFE0 & 0x10;
    s32 temp_t0 = D_800CCFE0 & 0xF;
    f32 temp_fv0 = temp_t0 / 15.0f;

    if (!temp_v0) {
        red = (arg1 - 255) * temp_fv0 + 255.0f;
        green = (arg2 - 255) * temp_fv0 + 255.0f;
        blue = (arg3 - 255) * temp_fv0 + 255.0f;
    } else {
        red = arg1 + (255 - arg1) * temp_fv0;
        green = arg2 + (255 - arg2) * temp_fv0;
        blue = arg3 + (255 - arg3) * temp_fv0;
    }

    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);

    return gfx;
}
