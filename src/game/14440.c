#include "global.h"
#include "audio.h"

extern Gfx D_3000088[];

Gfx* func_8007A440(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha) {

    red &= 0xFF;
    green &= 0xFF;
    blue &= 0xFF;
    alpha &= 0xFF;
    if ((left >= SCREEN_WIDTH) || (top >= SCREEN_HEIGHT)) {
        return gfx;
    }

    if (left < 0) {
        left = 0;
    }
    if (top < 0) {
        top = 0;
    }
    if ((right < 0) || (bottom < 0)) {
        return gfx;
    }

    if (right > SCREEN_WIDTH) {
        right = SCREEN_WIDTH;
    }
    if (bottom > SCREEN_HEIGHT) {
        bottom = SCREEN_HEIGHT;
    }

    gSPDisplayList(gfx++, D_3000088);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gDPFillRectangle(gfx++, left, top, right, bottom);
    gDPPipeSync(gfx++);
    return gfx;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/func_8007A59C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/func_8007A828.s")

extern Gfx D_30001A8[];

Gfx* func_8007AB88(Gfx* gfx) {
    gSPDisplayList(gfx++, D_30001A8);
    return gfx;
}

extern s16 D_800CCFE4;
extern FrameBuffer* D_800DCCD0[];
extern s32 D_800DCCFC;
extern s32 D_800DCD04;

Gfx* func_8007ABA4(Gfx* gfx) {

    gDPPipeSync(gfx++);

    if (D_800CCFE4 == 2) {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCCFC]));
    } else {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCD04]));
    }
    return gfx;
}

#define PACK_5551(r, g, b, a) (((((r) << 11) | ((g) << 6)) | ((b) << 1)) | (a))

Gfx* func_8007AC48(Gfx* gfx, u16 red, u16 green, u16 blue) {

    if ((red < 0) || (red > 255) || (green < 0) || (green > 255) || (blue < 0) || (blue > 255)) {
        return gfx;
    }

    red >>= 3;
    green >>= 3;
    blue >>= 3;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetFillColor(gfx++, PACK_5551(red, green, blue, 1) << 16 | PACK_5551(red, green, blue, 1));
    gDPFillRectangle(gfx++, 12, 8, 307, 231);
    return gfx;
}

Gfx* func_8007AD44(Gfx* gfx, u16 red, u16 green, u16 blue, s32 left, s32 top, s32 right, s32 bottom) {

    if ((red < 0) || (red > 255) || (green < 0) || (green > 255) || (blue < 0) || (blue > 255)) {
        return gfx;
    }

    red >>= 3;
    green >>= 3;
    blue >>= 3;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetFillColor(gfx++, PACK_5551(red, green, blue, 1) << 16 | PACK_5551(red, green, blue, 1));
    gDPFillRectangle(gfx++, left, top, right, bottom);
    return gfx;
}

extern Gfx D_3000170[];

Gfx* func_8007AE70(Gfx* gfx) {
    gSPDisplayList(gfx++, D_3000170);
    return gfx;
}

extern Gfx D_3000000[];

Gfx* func_8007AE8C(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha) {
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPDisplayList(gfx++, D_3000000);
    gDPFillRectangle(gfx++, left, top, right, bottom);

    return gfx;
}

extern Gfx D_3000028[];

Gfx* func_8007AF40(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha) {
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPDisplayList(gfx++, D_3000028);
    gDPFillRectangle(gfx++, left, top, right, bottom);

    return gfx;
}

extern Gfx D_3000270[];
extern s32 D_800CCFE0;

Gfx* func_8007AFF4(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom) {
    gSPDisplayList(gfx++, D_3000270);
    gSPTextureRectangle(gfx++, (left + 1) << 2, (top + 1) << 2, (right - 1) << 2, (bottom - 1) << 2, G_TX_RENDERTILE, 0,
                        (D_800CCFE0 & 0x1F) << 5, 1 << 10, 1 << 10);

    return gfx;
}

Gfx* func_8007B0A8(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom) {
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++,
                     IM_RD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | FORCE_BL |
                         GBL_c1(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA),
                     IM_RD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | FORCE_BL |
                         GBL_c2(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA));
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPFillRectangle(gfx++, left, top, right, bottom);

    return gfx;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/func_8007B14C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/func_8007CDB0.s")

#ifdef IMPORT_BSS
extern s32 D_800CD3D0[];

typedef struct unk9 {
    u8 v0, v1, v2, v3, v4, v5, v6, v7, v8;
} unk9;
extern unk9 D_8010D730[];

void func_8007D9D0(void) {
    static s32 D_800E4180[55];
    s32 i;

    for (i = 0; i < 24; i++) {
        D_800E4180[i] = D_800CD3D0[i];
    }

    for (i = 24; i < 30; i++) {
        if (D_8010D730[i - 24].v0 == 0) {
            D_800E4180[i] = D_800CD3D0[i];
        } else {
            D_800E4180[i] = &D_8010D730[i - 24];
        }
    }

    for (i = 30; i < 48; i++) {
        D_800E4180[i] = D_800CD3D0[31];
    }

    for (i = 48; i < 54; i++) {
        D_800E4180[i] = D_800CD3D0[30];
    }

    D_800E4180[54] = D_800CD3D0[31];
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/func_8007D9D0.s")
#endif

extern s16 D_800E416C;
extern u16 D_800E416E;
extern u16 D_800E4170;

typedef struct unk_8007DABC_arg_0 {
    s8 unk_00[0x6E];
    u8 unk_6E;
    u8 unk_6F;
    s8 unk_70[0xA];
    u16 unk_7A;
    u16 unk_7C;
    s8 unk_7E[0x2];
    s8 unk_80[0x2];
    u16 unk_82;
} unk_8007DABC_arg_0;

void func_8007DABC(unk_8007DABC_arg_0* arg0) {
    D_800E416E = arg0->unk_7C | (arg0->unk_6F << 4);
    if (arg0->unk_82 != 0) {
        D_800E4170 = arg0->unk_7A | (arg0->unk_6E << 4);
    } else {
        D_800E4170 = 0;
    }
    D_800E416C = D_800E416E | D_800E4170;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/func_8007DB28.s")

#ifdef IMPORT_BSS
static s8 D_800E4174[4];
void func_8007DED8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800E4174[i] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/func_8007DED8.s")
#endif

void func_80101414(void);
extern s32 D_800CD004;
extern s32 D_800CD008;
extern s8 D_800E4174[4];

extern s16 D_800E42CC;

void func_8007DEF0(void) {
    s32 i;
    s32 var_v1 = 0;
    s32 var_a0;

    for (i = 0; i < 4; i++) {
        if (D_800E4174[i] < 3) {
            var_v1 = 1;
            break;
        }
    }
    var_a0 = D_800CD008 + 1;
    if ((D_800CD004 >= 0) || (D_800CD004 < 4)) {
        if (var_a0 > 4) {
            var_a0 = 4;
        }

        if (D_800E4174[D_800CD004] < var_a0) {
            D_800E4174[D_800CD004] = var_a0;
        }
        if (var_v1 != 0) {
            for (i = 0; i < 4; i++) {
                if (D_800E4174[i] < 3) {
                    var_v1 = 0;
                    if (D_800CD004) {}
                }
            }

            if (var_v1 != 0) {
                D_800E42CC = 1;
            }
        }
        func_80101414();
    }
}

extern s8 D_800E4174[4];

s32 func_8007E008(void) {
    s32 sum = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        sum += D_800E4174[i];
    }
    return sum;
}

extern s32 D_800CCFC0;
extern bool D_800DCCCC;

s32 func_8007E038(void) {
    if ((D_800CCFC0 != 0) && D_800DCCCC && (func_800760F8() == 2)) {
        return 1;
    }
    return 0;
}

void func_8007E08C(void) {
    func_800BB39C(0);
}

void func_8007E0AC(s32 arg0) {
    func_800BAF30(arg0);
}

void func_8007E0CC(void) {
    func_800BAF80();
}

void func_8007E0EC(void) {
    func_800BB078();
}

extern const s8 D_800D4690[];

s8 func_8007E10C(s32 arg0) {
    return D_800D4690[arg0];
}

s32 func_8007E11C(s32 arg0) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (arg0 == D_800D4690[i]) {
            return i;
        }
    }

    return 0;
}

s32 func_801037CC(s32*, s32);
extern s8 D_800CD3C0;
extern s8 D_800CD3C4;

void func_8007E1C0(void) {
    s32 sp40[16];
    s32 pad;
    bool sp38;
    s32 i;

    sp38 = false;

    for (i = 0; i < 24; i++) {
        if (func_801037CC(sp40, i) != 0) {
            sp38 = true;
            break;
        } else {
            if (D_802A6B40[i].unk_20 >= sp40[2]) {
                sp38 = true;
                break;
            }
        }
    }
    if (!sp38 || (D_800CD3C0 >= 3)) {
        D_800CD3C4 = 2;
    } else if (D_800CD3C0 >= 2) {
        D_800CD3C4 = 1;
    } else {
        D_800CD3C4 = 0;
    }
}

extern s8 D_800CD3C0;

void func_8007E2B4(void) {
    bool var_a0;
    s32 i;

    if (func_8007E008() >= 0x10) {
        D_800CD3C0 = 3;
    } else {
        var_a0 = false;
        for (i = 0; i < 4; i++) {
            if (D_800E4174[i] < 3) {
                var_a0 = true;
                break;
            }
        }

        if (!var_a0) {
            D_800CD3C0 = 2;
        } else {
            var_a0 = false;
            for (i = 0; i < 3; i++) {
                if (D_800E4174[i] < 2) {
                    var_a0 = true;
                    break;
                }
            }

            if (!var_a0) {
                D_800CD3C0 = 1;
            } else {
                D_800CD3C0 = 0;
            }
        }
    }
    func_8007E1C0();
}

extern s32 D_800CD388[];
extern s32 D_800CD3B8;
extern s32 D_800CD3BC;
extern s32 D_800CD3CC;

extern s16 D_800E5EE0[];
extern s16 D_800E5EE8[];

void func_8007E398(void) {
    s32 i;
    s32 j;

    for (i = 3; i >= 0; i--) {
        D_800E5EE0[i] = i;
        D_800E5EE8[i] = 0;
    }

    for (i = 0; i < 8; i++) {
        D_800CD388[i] = 0;
    }

    D_800CD3B8 = 0;
    D_800CD3BC = 0;
    D_800CD3CC = 1;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4310.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D431C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4324.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4330.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4340.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D434C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4358.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4364.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4370.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4384.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4390.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D439C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D43A8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D43B4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D43C0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D43CC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D43DC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D43EC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D43F8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4408.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D441C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4428.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4438.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4444.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4450.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D445C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4468.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4474.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4480.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D448C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4498.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D449C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D44A0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D44AC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D44B8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D44C4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D44D4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D44E0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D44EC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D44F8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4504.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4510.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4520.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4530.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4544.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4554.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4564.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4574.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4580.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D458C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4598.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D45A4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D45B4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D45C0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D45D0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D45E0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D45EC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D45FC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4608.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4618.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4624.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4634.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4640.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4650.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D465C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4668.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4678.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4684.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/14440/D_800D4690.s")
