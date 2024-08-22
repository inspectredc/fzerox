#include "global.h"
#include "audio.h"

extern u16 D_800DCE70;
extern u16 D_800DCE74;
extern u16 D_800DCE78;
extern u16 D_800DCE7C;

extern s32 D_800DCF2C;
extern s32 D_800DCFC0;
extern s32 D_800DD054;

extern unk_800DCE98 D_800DCE98[];

void* func_80069ED0(void) {
    if ((D_800DCE70 & 0x1F07) == 2) {
        return &D_800DCE98;
    }
    if ((D_800DCE74 & 0x1F07) == 2) {
        return &D_800DCF2C;
    }
    if ((D_800DCE78 & 0x1F07) == 2) {
        return &D_800DCFC0;
    }
    if ((D_800DCE7C & 0x1F07) == 2) {
        return &D_800DD054;
    }
    return NULL;
}

// n64 boot logo
extern u8 D_2787F0[];

void func_80069F5C(u64* arg0) {
    u64* var_s0 = &arg0[19199];
    s32 var_s1;

    // FAKE?
    while (var_s0 >= arg0) {
        *(--var_s0 + 1) = 0x1000100010001;
    }
    osWritebackDCache(arg0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(u16));

    var_s0 = &arg0[5624];

    for (var_s1 = 0; var_s1 < 0x6A00; var_s1 += 0x100, var_s0 += 80) {
        func_80073E28((uintptr_t) D_2787F0 + var_s1 + 8, var_s0, 0x100);
    }
}

extern Vp D_80146A8[];
extern Vp D_80146B8[];
extern Vp D_80146C8[];
extern Vp D_80146D8[];
extern Vp D_80146E8[];
extern Vp D_80146F8[];
extern Vp D_8014708[];
extern Vp D_8014718[];
extern Vp D_8014728[];
extern Vp D_8014738[];
extern Vp D_8014748[];
extern Vp D_8014758[];
extern Vp D_8014768[];

extern ScissorBox D_800CD9C0;
extern ScissorBox D_800CD9D0;
extern ScissorBox D_800CD9E0;
extern ScissorBox D_800CD9F0;
extern ScissorBox D_800CDA00;
extern ScissorBox D_800CDA10;
extern ScissorBox D_800CDA20;
extern ScissorBox D_800CDA30;
extern ScissorBox D_800CDA40;
extern ScissorBox D_800CDA50;
extern ScissorBox D_800CDA60;
extern ScissorBox D_800CDA70;
extern ScissorBox D_800CDA80;

Gfx* func_8006A00C(Gfx* gfx, s32 arg1) {
    ScissorBox* scissorBox;

    switch (arg1) {
        case 0:
            gSPViewport(gfx++, D_80146A8);
            scissorBox = &D_800CD9C0;
            break;
        case 1:
            gSPViewport(gfx++, D_80146B8);
            scissorBox = &D_800CD9D0;
            break;
        case 2:
            gSPViewport(gfx++, D_80146C8);
            scissorBox = &D_800CD9E0;
            break;
        case 3:
            gSPViewport(gfx++, D_80146D8);
            scissorBox = &D_800CD9F0;
            break;
        case 4:
            gSPViewport(gfx++, D_80146E8);
            scissorBox = &D_800CDA00;
            break;
        case 5:
            gSPViewport(gfx++, D_80146F8);
            scissorBox = &D_800CDA10;
            break;
        case 6:
            gSPViewport(gfx++, D_8014708);
            scissorBox = &D_800CDA20;
            break;
        case 7:
            gSPViewport(gfx++, D_8014718);
            scissorBox = &D_800CDA30;
            break;
        case 8:
            gSPViewport(gfx++, D_8014728);
            scissorBox = &D_800CDA40;
            break;
        case 9:
            gSPViewport(gfx++, D_8014738);
            scissorBox = &D_800CDA50;
            break;
        case 10:
            gSPViewport(gfx++, D_8014748);
            scissorBox = &D_800CDA60;
            break;
        case 11:
            gSPViewport(gfx++, D_8014758);
            scissorBox = &D_800CDA70;
            break;
        case 12:
            gSPViewport(gfx++, D_8014768);
            scissorBox = &D_800CDA80;
            break;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, scissorBox->left, scissorBox->top, scissorBox->right, scissorBox->bottom);

    return gfx;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/3ED0/func_8006A3AC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/3ED0/func_8006A6E4.s")

extern s32 D_800CD170;
extern u32 D_800CD174;
extern s32 D_800CD178;
extern u32 D_800CD17C;

void func_8006A8F0(s32 arg0, s32 arg1) {
    D_800CD170 = arg0;
    D_800CD174 = arg1;
}

void func_8006A904(s32 arg0, s32 arg1) {
    D_800CD178 = arg0;
    D_800CD17C = arg1;
}

u32 func_8006A918(void) {

    D_800CD170 = D_800CD170 * 0x41C64E6D + 0x3039;
    if (D_800CD174 & 1) {
        D_800CD174 ^= 0x11020;
    }

    D_800CD174 >>= 1;

    return D_800CD170 ^ D_800CD174;
}

u32 func_8006A978(void) {

    D_800CD178 = D_800CD178 * 0x41C64E6D + 0x10932;
    if (D_800CD17C & 1) {
        D_800CD17C ^= 0x11020;
    }

    D_800CD17C >>= 1;

    return D_800CD178 + D_800CD17C;
}

s32 func_8006A9E0(f32 arg0) {
    if (arg0 < 0.0f) {
        return arg0 - 0.5f;
    }
    return arg0 + 0.5f;
}

s32 func_8006AA38(Mtx3F* mtx) {
    f32 temp_fs0;

    temp_fs0 = SQ(mtx->xx) + SQ(mtx->yx) + SQ(mtx->zx);

    if (temp_fs0 == 0.0f) {
        return -1;
    }

    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    mtx->xx *= temp_fs0;
    mtx->yx *= temp_fs0;
    mtx->zx *= temp_fs0;

    mtx->xz = mtx->yy * mtx->zx - mtx->zy * mtx->yx;
    mtx->yz = mtx->zy * mtx->xx - mtx->xy * mtx->zx;
    mtx->zz = mtx->xy * mtx->yx - mtx->yy * mtx->xx;

    temp_fs0 = SQ(mtx->xz) + SQ(mtx->yz) + SQ(mtx->zz);

    if (temp_fs0 == 0.0f) {
        return -1;
    }

    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    mtx->xz *= temp_fs0;
    mtx->yz *= temp_fs0;
    mtx->zz *= temp_fs0;

    mtx->xy = mtx->yx * mtx->zz - mtx->zx * mtx->yz;
    mtx->yy = mtx->zx * mtx->xz - mtx->xx * mtx->zz;
    mtx->zy = mtx->xx * mtx->yz - mtx->yx * mtx->xz;
    return 0;
}

s32 func_8006AC10(Mtx3F* mtx) {
    f32 temp_fs0;

    temp_fs0 = SQ(mtx->xy) + SQ(mtx->yy) + SQ(mtx->zy);
    if (temp_fs0 == 0.0f) {
        return -1;
    }
    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    mtx->xy *= temp_fs0;
    mtx->yy *= temp_fs0;
    mtx->zy *= temp_fs0;

    mtx->xz = mtx->yy * mtx->zx - mtx->zy * mtx->yx;
    mtx->yz = mtx->zy * mtx->xx - mtx->xy * mtx->zx;
    mtx->zz = mtx->xy * mtx->yx - mtx->yy * mtx->xx;

    temp_fs0 = SQ(mtx->xz) + SQ(mtx->yz) + SQ(mtx->zz);
    if (temp_fs0 == 0.0f) {
        return -1;
    }
    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    mtx->xz *= temp_fs0;
    mtx->yz *= temp_fs0;
    mtx->zz *= temp_fs0;

    mtx->xx = mtx->yz * mtx->zy - mtx->zz * mtx->yy;
    mtx->yx = mtx->zz * mtx->xy - mtx->xz * mtx->zy;
    mtx->zx = mtx->xz * mtx->yy - mtx->yz * mtx->xy;
    return 0;
}

void func_8006ADE4(s32 arg0, s32 arg1, s32 arg2, s32* arg3, s32* arg4, s32* arg5) {
    s32 temp_lo;
    s32 temp_t0;
    s32 var_v1;

    if ((arg0 >> 8) & 1) {
        var_v1 = 0xFF - (arg0 & 0xFF);
    } else {
        var_v1 = arg0 & 0xFF;
    }
    switch (arg0 >> 8) {
        case 0:
            *arg3 = 0xFF;
            *arg4 = var_v1;
            *arg5 = 0;
            break;
        case 1:
            *arg3 = var_v1;
            *arg4 = 0xFF;
            *arg5 = 0;
            break;
        case 2:
            *arg3 = 0;
            *arg4 = 0xFF;
            *arg5 = var_v1;
            break;
        case 3:
            *arg3 = 0;
            *arg4 = var_v1;
            *arg5 = 0xFF;
            break;
        case 4:
            *arg3 = var_v1;
            *arg4 = 0;
            *arg5 = 0xFF;
            break;
        case 5:
            *arg3 = 0xFF;
            *arg4 = 0;
            *arg5 = var_v1;
            break;
    }
    temp_lo = arg1 * arg2;
    temp_t0 = (arg2 * 0xFE01) - (temp_lo * 0xFF);
    *arg3 = (s32) ((*arg3 * temp_lo) + temp_t0) / 65025;
    *arg4 = (s32) ((*arg4 * temp_lo) + temp_t0) / 65025;
    *arg5 = (s32) ((*arg5 * temp_lo) + temp_t0) / 65025;
}

void func_8006AFC8(s8* arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0[4] = arg1;
    arg0[0] = arg1;
    arg0[5] = arg2;
    arg0[1] = arg2;
    arg0[6] = arg3;
    arg0[2] = arg3;
}

void func_8006AFE4(s8* arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0[4] = arg1;
    arg0[0] = arg1;
    arg0[5] = arg2;
    arg0[1] = arg2;
    arg0[6] = arg3;
    arg0[2] = arg3;
}

void func_8006B000(s8* arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0[8] = arg1;
    arg0[9] = arg2;
    arg0[10] = arg3;
}

void func_8006B010(s8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {

    arg0[3] = arg0[7] = arg0[11] = arg0[15] = arg0[19] = 0;

    func_8006AFC8(arg0, arg1, arg2, arg3);
    func_8006AFE4(&arg0[8], arg4, arg5, arg6);
    func_8006B000(&arg0[8], arg7, arg8, arg9);
}

void func_8006B07C(s8* arg0, f32* arg1) {

    arg0[3] = arg0[7] = arg0[19] = arg0[23] = 0;
    func_8006AFE4(arg0, 0, 0, 0);
    func_8006AFE4(&arg0[16], 0, 128, 0);

    func_8006B000(arg0, func_8006A9E0(arg1[0] * 120.0f), func_8006A9E0(arg1[4] * 120.0f),
                  func_8006A9E0(arg1[8] * 120.0f));

    func_8006B000(&arg0[16], func_8006A9E0(arg1[1] * 120.0f), func_8006A9E0(arg1[5] * 120.0f),
                  func_8006A9E0(arg1[9] * 120.0f));
}

void func_8006B18C(s8* arg0, s32* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv1;

    func_8006B07C(arg0, arg2);
    temp_fa1 = arg2[2] + arg3;
    temp_ft4 = arg2[6] + arg4;
    temp_ft5 = arg2[10] + arg5;
    temp_fa0 = SQ(temp_fa1) + SQ(temp_ft4) + SQ(temp_ft5);
    if (temp_fa0 > 0.01f) {
        temp_fv1 = 1.0 / sqrtf(temp_fa0);
        temp_fa1 *= temp_fv1;
        temp_ft4 *= temp_fv1;
        temp_ft5 *= temp_fv1;

        arg1[0] = (temp_fa1 * arg2[0] + temp_ft4 * arg2[4] + arg2[8] * temp_ft5) * (arg6 * 2) + arg6 * 4;
        arg1[1] = (temp_fa1 * arg2[1] + temp_ft4 * arg2[5] + arg2[9] * temp_ft5) * (arg7 * 2) + arg7 * 4;
        return;
    }
    arg1[0] = arg6 * 2;
    arg1[1] = arg7 * 2;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/3ED0/func_8006B33C.s")

void func_8006B908(MtxF* arg0, MtxF* arg1, MtxF* arg2) {
    arg2->m[0][0] = arg0->m[0][0] * arg1->m[0][0] + arg0->m[1][0] * arg1->m[0][1] + arg0->m[2][0] * arg1->m[0][2];
    arg2->m[0][1] = arg0->m[0][1] * arg1->m[0][0] + arg0->m[1][1] * arg1->m[0][1] + arg0->m[2][1] * arg1->m[0][2];
    arg2->m[0][2] = arg0->m[0][2] * arg1->m[0][0] + arg0->m[1][2] * arg1->m[0][1] + arg0->m[2][2] * arg1->m[0][2];

    arg2->m[1][0] = arg0->m[0][0] * arg1->m[1][0] + arg0->m[1][0] * arg1->m[1][1] + arg0->m[2][0] * arg1->m[1][2];
    arg2->m[1][1] = arg0->m[0][1] * arg1->m[1][0] + arg0->m[1][1] * arg1->m[1][1] + arg0->m[2][1] * arg1->m[1][2];
    arg2->m[1][2] = arg0->m[0][2] * arg1->m[1][0] + arg0->m[1][2] * arg1->m[1][1] + arg0->m[2][2] * arg1->m[1][2];

    arg2->m[2][0] = arg0->m[0][0] * arg1->m[2][0] + arg0->m[1][0] * arg1->m[2][1] + arg0->m[2][0] * arg1->m[2][2];
    arg2->m[2][1] = arg0->m[0][1] * arg1->m[2][0] + arg0->m[1][1] * arg1->m[2][1] + arg0->m[2][1] * arg1->m[2][2];
    arg2->m[2][2] = arg0->m[0][2] * arg1->m[2][0] + arg0->m[1][2] * arg1->m[2][1] + arg0->m[2][2] * arg1->m[2][2];

    arg2->m[3][0] =
        arg0->m[0][0] * arg1->m[3][0] + arg0->m[1][0] * arg1->m[3][1] + arg0->m[2][0] * arg1->m[3][2] + arg0->m[3][0];
    arg2->m[3][1] =
        arg0->m[0][1] * arg1->m[3][0] + arg0->m[1][1] * arg1->m[3][1] + arg0->m[2][1] * arg1->m[3][2] + arg0->m[3][1];
    arg2->m[3][2] =
        arg0->m[0][2] * arg1->m[3][0] + arg0->m[1][2] * arg1->m[3][1] + arg0->m[2][2] * arg1->m[3][2] + arg0->m[3][2];

    arg2->m[0][3] = 0.0f;
    arg2->m[1][3] = 0.0f;
    arg2->m[2][3] = 0.0f;
    arg2->m[3][3] = 1.0f;
}

// Matrix_FromMtx
void func_8006BB80(Mtx* src2, MtxF* dest) {
    s32 i;
    s32 j;
    // Potential Re-cast?
    Mtx* src = src2;

    for (i = 3; i >= 0; i--) {
        for (j = 3; j >= 0; j--) {
            dest->m[i][j] = (((s16) src->u.i[i][j] << 0x10) | (src->u.f[i][j])) / 65536.0f;
        }
    }
}

// Matrix_ToMtx
void func_8006BBE8(MtxF* src, Mtx* dest2) {
    s32 i;
    s32 j;
    s32 intValue;
    f32 temp_fv0;
    Mtx* dest = dest2;

    for (i = 3; i >= 0; i--) {
        for (j = 3; j >= 0; j--) {
            temp_fv0 = src->m[i][j] * 65536.0f;
            // Round Value
            if (temp_fv0 < 0.0f) {
                intValue = temp_fv0 - 0.5f;
            } else {
                intValue = temp_fv0 + 0.5f;
            }
            dest->u.i[i][j] = intValue >> 0x10;
            dest->u.f[i][j] = intValue;
        }
    }
}

void func_8006C378(Mtx* arg0, MtxF* arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7, f32 arg8);
extern Mtx D_800E1230;
extern MtxF D_800E1270;

void func_8006BC84(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                   f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD) {
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;

    if (arg0 == NULL) {
        arg0 = &D_800E1230;
    }
    if (arg1 == NULL) {
        arg1 = &D_800E1270;
    }
    sp7C = SQ(arg5) + SQ(arg6) + SQ(arg7);
    if (sp7C < 0.001f) {
        func_8006C378(arg0, arg1, arg2, 0, 0, 0, argB, argC, argD);
        return;
    }
    sp60 = arg2 / sqrtf(sp7C);
    arg1->m[2][0] = sp60 * arg5;
    arg1->m[2][1] = sp60 * arg6;
    arg1->m[2][2] = sp60 * arg7;
    sp78 = (arg9 * arg7) - (argA * arg6);
    sp74 = (argA * arg5) - (arg8 * arg7);
    sp70 = (arg8 * arg6) - (arg9 * arg5);

    sp7C = SQ(sp78) + SQ(sp74) + SQ(sp70);
    if (sp7C < 0.001f) {
        func_8006C378(arg0, arg1, arg2, 0, 0, 0, argB, argC, argD);
        return;
    }

    sp60 = arg4 / sqrtf(sp7C);
    arg1->m[0][0] = sp60 * sp78;
    arg1->m[0][1] = sp60 * sp74;
    arg1->m[0][2] = sp60 * sp70;

    sp6C = (arg6 * sp70) - (arg7 * sp74);
    sp68 = (arg7 * sp78) - (arg5 * sp70);
    sp64 = (arg5 * sp74) - (arg6 * sp78);
    sp7C = SQ(sp6C) + SQ(sp68) + SQ(sp64);
    if (sp7C < 0.001f) {
        func_8006C378(arg0, arg1, arg2, 0, 0, 0, argB, argC, argD);
        return;
    }
    sp60 = arg3 / sqrtf(sp7C);
    arg1->m[1][0] = sp60 * sp6C;
    arg1->m[1][1] = sp60 * sp68;
    arg1->m[1][2] = sp60 * sp64;
    arg1->m[3][0] = argB;
    arg1->m[3][1] = argC;
    arg1->m[3][2] = argD;
    arg1->m[0][3] = 0.0f;
    arg1->m[1][3] = 0.0f;
    arg1->m[2][3] = 0.0f;
    arg1->m[3][3] = 1.0f;
    func_8006BBE8(arg1, arg0);
}

void func_8006BFCC(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32* arg5, f32* arg6, f32* arg7) {
    f32 sp84;
    f32 sp80;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;

    if (arg0 == NULL) {
        arg0 = &D_800E1230;
    }
    if (arg1 == NULL) {
        arg1 = &D_800E1270;
    }
    arg1->m[2][0] = arg5[0] * arg2;
    arg1->m[2][1] = arg5[1] * arg2;
    arg1->m[2][2] = arg5[2] * arg2;

    sp80 = (arg6[1] * arg5[2]) - (arg5[1] * arg6[2]);
    sp6C = (arg6[2] * arg5[0]) - (arg5[2] * arg6[0]);
    sp5C = (arg6[0] * arg5[1]) - (arg5[0] * arg6[1]);
    sp84 = SQ(sp80) + SQ(sp6C) + SQ(sp5C);
    if (sp84 < 0.001f) {
        func_8006C378(arg0, arg1, arg2, 0, 0, 0, arg7[0], arg7[1], arg7[2]);
        return;
    }

    sp84 = arg4 / sqrtf(sp84);
    arg1->m[0][0] = sp84 * sp80;
    arg1->m[0][1] = sp84 * sp6C;
    arg1->m[0][2] = sp84 * sp5C;

    sp68 = (arg5[1] * sp5C) - (arg5[2] * sp6C);

    sp64 = (arg5[2] * sp80) - (arg5[0] * sp5C);

    sp60 = (arg5[0] * sp6C) - (arg5[1] * sp80);

    sp84 = SQ(sp68) + SQ(sp64) + SQ(sp60);
    if (sp84 < 0.001f) {
        func_8006C378(arg0, arg1, arg2, 0, 0, 0, arg7[0], arg7[1], arg7[2]);
        return;
    }
    sp84 = arg3 / sqrtf(sp84);
    arg1->m[1][0] = sp84 * sp68;
    arg1->m[1][1] = sp84 * sp64;
    arg1->m[1][2] = sp84 * sp60;
    arg1->m[3][0] = arg7[0];
    arg1->m[3][1] = arg7[1];
    arg1->m[3][2] = arg7[2];
    arg1->m[0][3] = 0.0f;
    arg1->m[1][3] = 0.0f;
    arg1->m[2][3] = 0.0f;
    arg1->m[3][3] = 1.0f;
    func_8006BBE8(arg1, arg0);
}

void func_8006C278(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32* arg5, f32* arg6) {

    if (arg0 == NULL) {
        arg0 = &D_800E1230;
    }
    if (arg1 == NULL) {
        arg1 = &D_800E1270;
    }
    arg1->m[2][0] = arg5[0] * arg2;
    arg1->m[2][1] = arg5[1] * arg2;
    arg1->m[2][2] = arg5[2] * arg2;
    arg1->m[0][0] = arg5[6] * arg4;
    arg1->m[0][1] = arg5[7] * arg4;
    arg1->m[0][2] = arg5[8] * arg4;
    arg1->m[1][0] = arg5[3] * arg3;
    arg1->m[1][1] = arg5[4] * arg3;
    arg1->m[1][2] = arg5[5] * arg3;
    arg1->m[3][0] = arg6[0];
    arg1->m[3][1] = arg6[1];
    arg1->m[3][2] = arg6[2];
    arg1->m[0][3] = 0.0f;
    arg1->m[1][3] = 0.0f;
    arg1->m[2][3] = 0.0f;
    arg1->m[3][3] = 1.0f;

    func_8006BBE8(arg1, arg0);
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/3ED0/func_8006C378.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/3ED0/func_8006C520.s")

void func_8006CB0C(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                   f32 arg9, f32 argA) {
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp;

    if (arg0 == NULL) {
        arg0 = &D_800E1230;
    }
    if (arg1 == NULL) {
        arg1 = &D_800E1270;
    }
    temp_fv1 = (arg2 * arg8) + (arg3 * arg9) + (arg4 * argA);

    if (!(SQ(temp_fv1) < 0.01)) {
        temp_fv1 = -1.0f / temp_fv1;
        temp_fv0 = (((-arg8 * arg5) - (arg9 * arg6)) - (argA * arg7)) * temp_fv1;
        arg8 *= temp_fv1;
        arg9 *= temp_fv1;
        argA *= temp_fv1;
        arg1->xx = arg8 * arg2 + 1.0f;
        arg1->yx = arg8 * arg3;
        arg1->zx = arg8 * arg4;
        arg1->xy = arg9 * arg2;
        arg1->yy = arg9 * arg3 + 1.0f;
        arg1->zy = arg9 * arg4;
        arg1->xz = argA * arg2;
        arg1->yz = argA * arg3;
        arg1->zz = argA * arg4 + 1.0f;
        arg1->xw = temp_fv0 * arg2;
        arg1->yw = temp_fv0 * arg3;
        arg1->zw = temp_fv0 * arg4;
        arg1->wx = arg1->wy = arg1->wz = 0.0f;
        arg1->ww = 1.0f;
        func_8006BBE8(arg1, arg0);
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/3ED0/func_8006CC98.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/3ED0/func_8006D03C.s")

void func_8006D2E0(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv1;

    if (arg0 == NULL) {
        arg0 = &D_800E1230;
    }
    if (arg1 == NULL) {
        arg1 = &D_800E1270;
    }

    temp_fv1 = arg2 / (arg3 - arg4);
    arg1->m[0][0] = temp_fv1 * -2.0f;
    arg1->m[3][0] = (arg4 + arg3) * temp_fv1;

    temp_fa0 = arg2 / (arg5 - arg6);
    arg1->m[1][1] = temp_fa0 * -2.0f;
    arg1->m[3][1] = (arg6 + arg5) * temp_fa0;

    temp_fv0 = arg2 / (arg7 - arg8);
    arg1->m[2][2] = 2.0f * temp_fv0;
    arg1->m[3][2] = (arg8 + arg7) * temp_fv0;

    arg1->m[3][3] = arg2;
    arg1->m[0][1] = arg1->m[0][2] = arg1->m[0][3] = arg1->m[1][0] = arg1->m[1][2] = arg1->m[1][3] = arg1->m[2][0] =
        arg1->m[2][1] = arg1->m[2][3] = 0.0f;
    func_8006BBE8(arg1, arg0);
}
