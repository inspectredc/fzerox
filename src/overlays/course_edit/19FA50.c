#include "global.h"
#include "leo/mfs.h"
#include ASSET_HEADER_EK(expansion_kit_textures.h)
#include ASSET_HEADER_EK(course_edit_textures.h)

s32 D_xk2_80128CA0;
s32 D_xk2_80128CA4;

s32 D_xk2_80104360 = 1;
s32 D_xk2_80104364 = 0;
s32 D_xk2_80104368 = 0;
UNUSED s32 D_xk2_8010436C = 0;
UNUSED s32 D_xk2_80104370 = 0;
UNUSED s32 D_xk2_80104374 = 0;
s32 D_xk2_80104378 = 0;
s32 D_xk2_8010437C = 0;
s32 D_xk2_80104380 = 0;

extern s32 D_xk2_80104378;

extern unk_800D6CA0 D_800D6CA0;
extern s32 D_80119880;

Gfx* func_xk2_800EDF90(Gfx* gfx) {

    D_xk2_80128CA4 = 0;
    D_xk2_80104360 = 1;
    if (D_800D6CA0.unk_08 == 3) {
        if (D_80119880 == 5) {
            gfx = func_xk1_8002C420(gfx, 0x18, (D_xk2_80104360 * 0x10) + 0x38);
            D_xk2_80104360++;
        } else {
            switch (D_80119880) {
                case 7:
                case 8:
                    if (1) {}
                    gfx = func_xk1_8002C420(gfx, 0x18, (D_xk2_80104360 * 0x10) + 0x38);
                    break;
                default:
                    gfx = func_xk1_8002C420(gfx, 0x58, (D_xk2_80104360 * 0x10) + 0x38);
                    break;
            }
            D_xk2_80104360++;
        }
    }
    gfx = func_xk2_800EE158(gfx);
    gfx = func_xk2_800EE268(gfx);

    if (D_800D6CA0.unk_08 == 0x10) {
        switch (D_xk2_80104378) {
            case 1:
            case 2:
            case 3:
                if (func_xk1_8002CA80 != NULL) {
                    func_xk1_8002D340(&gfx);
                }
                break;
        }
    }
    return gfx;
}

s32 func_xk2_800EE0EC(s8* arg0, s8** arg1) {
    s8* var_v1;

    var_v1 = *arg1;

    while ((*var_v1 != 0) && (*var_v1 != 0xA)) {
        *arg0++ = *var_v1++;
    }
    *arg0 = 0;
    if (*var_v1 == 0) {
        *arg1 = var_v1;
        return 1;
    }
    *arg1 = var_v1 + 1;
    return 0;
}

extern Gfx D_3000510[];
extern Gfx D_3000540[];
extern u8* D_xk1_800331F0[];
extern s32 D_xk2_80119884;
extern unk_8003A5D8 D_xk1_8003A5D8[];

Gfx* func_xk2_800EE158(Gfx* gfx) {
    s32 sp12C;
    u8* var_a3;
    s8 sp20[0x108];

    if (D_800D6CA0.unk_08 != 0x10) {
        return gfx;
    }
    gSPDisplayList(gfx++, D_3000510);

    sp20[0] = 0;
    switch (D_xk2_80104378) {
        case 1:
        case 2:
        case 3:
            func_xk1_8002C720(&gfx, sp12C, (D_xk2_80104360 * 0x10) + 0x38, D_xk1_8003A5D8[D_xk2_80119884].name,
                              D_xk2_80104378 - 1);
            D_xk2_80104360++;
            return gfx;
        default:
            var_a3 = D_xk1_800331F0[D_xk2_80104378];
            func_xk2_800EECD4(&gfx, 0x18, (D_xk2_80104360 * 0x10) + 0x38, var_a3, D_xk2_80104378);
            return gfx;
    }
}

extern u8* D_xk1_8003339C[];
extern u8 D_xk2_80104CA0[];
extern s32 gCourseEditCursorYPos;

Gfx* func_xk2_800EE268(Gfx* gfx) {
    s32 i;
    s32 left;
    s32 top;
    s32 width;
    s32 temp_v0;

    for (i = 0; i < 12; i++) {
        if (D_xk2_80104CA0[i] == 0) {
            continue;
        }

        temp_v0 = mfsStrLen(D_xk1_8003339C[i]);
        width = temp_v0 * 8;
        left = func_xk2_800EE578(temp_v0);

        top = (D_xk2_80104360 * 0x10) + 0x38;
        if ((gCourseEditCursorYPos + 0x10) >= top) {
            if ((top + 0x10) >= gCourseEditCursorYPos) {
                D_xk2_80104360 += 2;
            }
        }
        top = (D_xk2_80104360 * 0x10) + 0x3C;

        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 160);
        gSPTextureRectangle(gfx++, (left - 2) << 2, (top - 2) << 2, (left + width + 2) << 2, top << 2, 0, 0, 0, 1 << 10,
                            1 << 10);
        gSPTextureRectangle(gfx++, (left - 2) << 2, (top + 16) << 2, (left + width + 2) << 2, (top + 16 + 2) << 2, 0, 0,
                            0, 1 << 10, 1 << 10);
        gSPTextureRectangle(gfx++, (left - 2) << 2, top << 2, left << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gSPTextureRectangle(gfx++, (left + width) << 2, top << 2, (left + width + 2) << 2, (top + 16) << 2, 0, 0, 0,
                            1 << 10, 1 << 10);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);
        gSPDisplayList(gfx++, D_3000540);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        gfx = func_xk1_80026670(gfx, left, top, i);
        D_xk2_80104360++;
    }
    return gfx;
}

extern s32 gCourseEditCursorXPos;
extern s32 D_xk2_800F703C;

s32 func_xk2_800EE578(s32 arg0) {
    s32 var_a1;
    s32 temp_v0;

    temp_v0 = (D_xk2_80128CA0 + 7) / 8;

    var_a1 = (((0x22 - temp_v0 - arg0) / 2) * 8) + 0x18;
    if (var_a1 < 0x18) {
        var_a1 = 0x18;
    }
    if (var_a1 < D_xk2_80128CA4) {
        var_a1 = D_xk2_80128CA4;
    }
    if ((gCourseEditCursorXPos > 0xE0) && (D_xk2_800F703C != -1)) {
        var_a1 = D_xk2_80128CA0 + 0x20;
        if (((arg0 * 8) + var_a1) > 0x128) {
            var_a1 = (((0x22 - arg0) / 2) * 8) + 0x18;
        }
    }
    return var_a1;
}

void func_xk2_800EE640(void) {
    if (D_xk2_8010437C > 4) {
        D_xk2_8010437C -= 4;
    }
}

void func_xk2_800EE664(s32 arg0) {
    D_xk2_80104380 = arg0;
    D_xk2_8010437C = 0x3C;
}

extern Gfx D_8014940[];
extern s32 D_8076C960;

void func_xk2_800EE67C(Gfx** gfxP) {
    s32 left = 128;
    s32 top = 88;
    s32 width = 16;
    s32 height = 16;
    s32 temp_v0;
    Gfx* gfx;

    gfx = *gfxP;
    if (D_xk2_8010437C == 0) {
        return;
    }
    D_xk2_8010437C--;
    if (D_xk2_8010437C == 0) {
        D_8076C960 = 0;
    }
    func_xk2_800F2AC0(D_xk1_800331F0[D_xk2_80104380]);
    temp_v0 = func_xk2_800F2AF4(D_xk1_800331F0[D_xk2_80104380]);
    func_xk2_800EECD4(&gfx, (((0x22 - temp_v0) / 2) * 8) + 0x18, 0x58, D_xk1_800331F0[D_xk2_80104380], D_xk2_80104380);

    if (D_8076C960 != 0) {
        gSPDisplayList(gfx++, D_8014940);
        gDPLoadTextureBlock(gfx++, aCourseEditQuestionIconTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);
    }
    *gfxP = gfx;
}

void func_xk2_800EE8A0(Gfx** gfxP) {
    Gfx* gfx;
    s32 left;
    s32 width;
    s32 top;
    s32 temp_v0;

    gfx = *gfxP;
    if (D_800D6CA0.unk_08 != 0x30) {
        return;
    }

    temp_v0 = mfsStrLen(D_xk1_800331F0[12]);
    width = temp_v0 * 8;

    left = 0x22 - temp_v0;
    left = ((left / 2) * 8) + 0x18;
    top = 88;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);

    gSPTextureRectangle(gfx++, (left - 2) << 2, (top - 2) << 2, (left + width + 2) << 2, top << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (left - 2) << 2, (top + 64) << 2, (left + width + 2) << 2, (top + 64 + 2) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left - 2) << 2, top << 2, left << 2, (top + 64) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left + width) << 2, top << 2, (left + width + 2) << 2, (top + 64) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + 64) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);

    gfx = func_xk1_800264C0(gfx, left, top, 12);
    left = 0x22 - mfsStrLen(D_xk1_800331F0[13]);
    left = ((left / 2) * 8) + 0x18;
    top = 104;

    gSPDisplayList(gfx++, D_3000540);

    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gfx = func_xk1_800264C0(gfx, left, top, 13);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_xk1_800264C0(gfx, left + 72, top + 24, 14);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gfx++, aExpansionKitABButtonTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    top += 24;
    left += 0x70;

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    *gfxP = gfx;
}

void func_xk2_800EECD4(Gfx** gfxP, s32 left, s32 top, s8* arg3, s32 arg4) {
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s7;
    s8* sp1BC;
    s8 spBC[0x100];
    Gfx* gfx;

    gfx = *gfxP;

    var_s3 = 0;
    var_s4 = SCREEN_WIDTH;
    var_s7 = 0;
    sp1BC = arg3;
    do {
        if (1) {}
        temp_s0 = func_xk2_800EE0EC(spBC, &sp1BC);
        temp_v0 = mfsStrLen(spBC);
        temp_v1 = (((0x22 - temp_v0) / 2) * 8) + 0x18;
        if (temp_v1 < var_s4) {
            var_s4 = temp_v1;
            var_s7 = temp_v0;
        }
        var_s3++;

    } while (temp_s0 == 0);
    left = var_s4;

    gSPDisplayList(gfx++, D_3000510);
    if (D_xk2_80104378 == 6) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
    }

    gSPTextureRectangle(gfx++, (left - 2) << 2, (top - 2) << 2, (left + 2 + (var_s7 * 8)) << 2, top << 2, 0, 0, 0,
                        1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left - 2) << 2, (top + (var_s3 * 0x10)) << 2, (left + 2 + (var_s7 * 8)) << 2,
                        (top + (var_s3 * 0x10) + 2) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left - 2) << 2, top << 2, left << 2, (top + (var_s3 * 0x10)) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (left + (var_s7 * 8)) << 2, top << 2, (left + 2 + (var_s7 * 8)) << 2,
                        (top + (var_s3 * 0x10)) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
    gSPTextureRectangle(gfx++, (left - 1) << 2, top << 2, (left + (var_s7 * 8)) << 2, (top + (var_s3 * 0x10)) << 2, 0,
                        0, 0, 1 << 10, 1 << 10);
    sp1BC = arg3;
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    var_s3 = 0;
    do {
        if (1) {}
        temp_s0 = func_xk2_800EE0EC(spBC, &arg3);
        gfx = func_xk1_8002656C(gfx, left, top, arg4, var_s3);
        top += 0x10;
        D_xk2_80104360++;
        var_s3++;
    } while (temp_s0 == 0);
    *gfxP = gfx;
}
