#include "global.h"
#include "audio.h"
#include "assets/segment_16C8A0.h"

f32 gSinTable[0x1000];
Mtx D_800E1230;
MtxF D_800E1270;

extern OSContStatus D_800DCE70[];
extern Controller gControllers[];

Controller* Controller_GetMouse(void) {
    s32 i;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if ((D_800DCE70[i].type & CONT_TYPE_MASK) == CONT_TYPE_MOUSE) {
            return &gControllers[i];
        }
    }

    return NULL;
}

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
        Dma_ClearRomCopy((uintptr_t) SEGMENT_ROM_START(segment_2787F0) + var_s1 + sizeof(Gfx), var_s0, 0x100);
    }
}

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
            gSPViewport(gfx++, &D_80146A8);
            scissorBox = &D_800CD9C0;
            break;
        case 1:
            gSPViewport(gfx++, &D_80146B8);
            scissorBox = &D_800CD9D0;
            break;
        case 2:
            gSPViewport(gfx++, &D_80146C8);
            scissorBox = &D_800CD9E0;
            break;
        case 3:
            gSPViewport(gfx++, &D_80146D8);
            scissorBox = &D_800CD9F0;
            break;
        case 4:
            gSPViewport(gfx++, &D_80146E8);
            scissorBox = &D_800CDA00;
            break;
        case 5:
            gSPViewport(gfx++, &D_80146F8);
            scissorBox = &D_800CDA10;
            break;
        case 6:
            gSPViewport(gfx++, &D_8014708);
            scissorBox = &D_800CDA20;
            break;
        case 7:
            gSPViewport(gfx++, &D_8014718);
            scissorBox = &D_800CDA30;
            break;
        case 8:
            gSPViewport(gfx++, &D_8014728);
            scissorBox = &D_800CDA40;
            break;
        case 9:
            gSPViewport(gfx++, &D_8014738);
            scissorBox = &D_800CDA50;
            break;
        case 10:
            gSPViewport(gfx++, &D_8014748);
            scissorBox = &D_800CDA60;
            break;
        case 11:
            gSPViewport(gfx++, &D_8014758);
            scissorBox = &D_800CDA70;
            break;
        case 12:
            gSPViewport(gfx++, &D_8014768);
            scissorBox = &D_800CDA80;
            break;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, scissorBox->left, scissorBox->top, scissorBox->right, scissorBox->bottom);

    return gfx;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/3ED0/func_8006A3AC.s")

void Math_SinTableInit(void) {
    f64 denominator;
    f64 minusSquareX;
    f64 x;
    f64 numerator;
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(gSinTable); i++) {
        x = (i * (2 * 3.1415926535)) / ARRAY_COUNT(gSinTable);
        numerator = -x * x * x;
        minusSquareX = -x * x;
        denominator = 1 * 2 * 3; // 3!

        // sinx = x - (x^3/3!) + (x^5/5!) - (x^7/7!) + ...
        for (j = 2; j < 14; j++) {
            x += (numerator / denominator);
            numerator *= minusSquareX;
            denominator *= j * ((j << 2) + 2);
        }

        gSinTable[i] = x;
    }
}

s32 gRandSeed1 = 12345;
u32 gRandMask1 = 6789;
s32 gRandSeed2 = 9876;
u32 gRandMask2 = 54321;

void Math_Rand1Init(s32 seed, s32 mask) {
    gRandSeed1 = seed;
    gRandMask1 = mask;
}

void Math_Rand2Init(s32 seed, s32 mask) {
    gRandSeed2 = seed;
    gRandMask2 = mask;
}

u32 Math_Rand1(void) {

    gRandSeed1 = gRandSeed1 * LCG_MULTIPLIER + LCG_INCREMENT_1;
    if (gRandMask1 & 1) {
        gRandMask1 ^= 0x11020;
    }

    gRandMask1 >>= 1;

    return gRandSeed1 ^ gRandMask1;
}

u32 Math_Rand2(void) {

    gRandSeed2 = gRandSeed2 * LCG_MULTIPLIER + LCG_INCREMENT_2;
    if (gRandMask2 & 1) {
        gRandMask2 ^= 0x11020;
    }

    gRandMask2 >>= 1;

    return gRandSeed2 + gRandMask2;
}

s32 Math_Round(f32 num) {
    if (num < 0.0f) {
        return num - 0.5f;
    }
    return num + 0.5f;
}

// Orthonormalise vectors, possibly camera/light related?
s32 func_8006AA38(Mtx3F* mtx) {
    f32 temp_fs0;

    temp_fs0 = SQ(mtx->x.x) + SQ(mtx->x.y) + SQ(mtx->x.z);

    if (temp_fs0 == 0.0f) {
        return -1;
    }

    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    mtx->x.x *= temp_fs0;
    mtx->x.y *= temp_fs0;
    mtx->x.z *= temp_fs0;

    mtx->z.x = mtx->y.y * mtx->x.z - mtx->y.z * mtx->x.y;
    mtx->z.y = mtx->y.z * mtx->x.x - mtx->y.x * mtx->x.z;
    mtx->z.z = mtx->y.x * mtx->x.y - mtx->y.y * mtx->x.x;

    temp_fs0 = SQ(mtx->z.x) + SQ(mtx->z.y) + SQ(mtx->z.z);

    if (temp_fs0 == 0.0f) {
        return -1;
    }

    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    mtx->z.x *= temp_fs0;
    mtx->z.y *= temp_fs0;
    mtx->z.z *= temp_fs0;

    mtx->y.x = mtx->x.y * mtx->z.z - mtx->x.z * mtx->z.y;
    mtx->y.y = mtx->x.z * mtx->z.x - mtx->x.x * mtx->z.z;
    mtx->y.z = mtx->x.x * mtx->z.y - mtx->x.y * mtx->z.x;
    return 0;
}

// Orthonormalise vectors, possibly camera/light related?
s32 func_8006AC10(Mtx3F* mtx) {
    f32 temp_fs0;

    temp_fs0 = SQ(mtx->y.x) + SQ(mtx->y.y) + SQ(mtx->y.z);
    if (temp_fs0 == 0.0f) {
        return -1;
    }
    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    mtx->y.x *= temp_fs0;
    mtx->y.y *= temp_fs0;
    mtx->y.z *= temp_fs0;

    mtx->z.x = mtx->y.y * mtx->x.z - mtx->y.z * mtx->x.y;
    mtx->z.y = mtx->y.z * mtx->x.x - mtx->y.x * mtx->x.z;
    mtx->z.z = mtx->y.x * mtx->x.y - mtx->y.y * mtx->x.x;

    temp_fs0 = SQ(mtx->z.x) + SQ(mtx->z.y) + SQ(mtx->z.z);
    if (temp_fs0 == 0.0f) {
        return -1;
    }
    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    mtx->z.x *= temp_fs0;
    mtx->z.y *= temp_fs0;
    mtx->z.z *= temp_fs0;

    mtx->x.x = mtx->z.y * mtx->y.z - mtx->z.z * mtx->y.y;
    mtx->x.y = mtx->z.z * mtx->y.x - mtx->z.x * mtx->y.z;
    mtx->x.z = mtx->z.x * mtx->y.y - mtx->z.y * mtx->y.x;
    return 0;
}

void func_8006ADE4(s32 arg0, s32 arg1, s32 arg2, s32* red, s32* green, s32* blue) {
    s32 temp_lo;
    s32 temp_t0;
    s32 var_v1;

    if ((arg0 >> 8) & 1) {
        var_v1 = 255 - (arg0 & 255);
    } else {
        var_v1 = arg0 & 255;
    }
    switch (arg0 >> 8) {
        case 0:
            *red = 255;
            *green = var_v1;
            *blue = 0;
            break;
        case 1:
            *red = var_v1;
            *green = 255;
            *blue = 0;
            break;
        case 2:
            *red = 0;
            *green = 255;
            *blue = var_v1;
            break;
        case 3:
            *red = 0;
            *green = var_v1;
            *blue = 255;
            break;
        case 4:
            *red = var_v1;
            *green = 0;
            *blue = 255;
            break;
        case 5:
            *red = 255;
            *green = 0;
            *blue = var_v1;
            break;
    }
    temp_lo = arg1 * arg2;
    temp_t0 = (arg2 * SQ(255)) - (temp_lo * 255);
    *red = (s32) ((*red * temp_lo) + temp_t0) / SQ(255);
    *green = (s32) ((*green * temp_lo) + temp_t0) / SQ(255);
    *blue = (s32) ((*blue * temp_lo) + temp_t0) / SQ(255);
}

void Lights_SetAmbient(Ambient* ambient, s32 r, s32 g, s32 b) {
    ambient->l.col[0] = ambient->l.colc[0] = r;
    ambient->l.col[1] = ambient->l.colc[1] = g;
    ambient->l.col[2] = ambient->l.colc[2] = b;
}

void Lights_SetColor(Light* light, s32 r, s32 g, s32 b) {
    light->l.col[0] = light->l.colc[0] = r;
    light->l.col[1] = light->l.colc[1] = g;
    light->l.col[2] = light->l.colc[2] = b;
}

void Lights_SetDirection(Light* light, s32 x, s32 y, s32 z) {
    light->l.dir[0] = x;
    light->l.dir[1] = y;
    light->l.dir[2] = z;
}

void Lights_SetSource(Lights1* light, s32 ambientR, s32 ambientG, s32 ambientB, s32 r, s32 g, s32 b, s32 x, s32 y,
                      s32 z) {

    // FAKE
    ((s8*) light)[3] = ((s8*) light)[7] = ((s8*) light)[11] = ((s8*) light)[15] = ((s8*) light)[19] = 0;
    // light->a.l.pad1 = light->a.l.pad2 = light->l[0].l.pad1 = light->l[0].l.pad2 = light->l[0].l.pad3 = 0;

    Lights_SetAmbient(&light->a, ambientR, ambientG, ambientB);
    Lights_SetColor(&light->l[0], r, g, b);
    Lights_SetDirection(&light->l[0], x, y, z);
}

void Light_SetLookAtSource(LookAt* lookAt, MtxF* mtx) {

    // FAKE
    ((s8*) lookAt)[3] = ((s8*) lookAt)[7] = ((s8*) lookAt)[19] = ((s8*) lookAt)[23] = 0;
    // lookAt->l[0].l.pad1 = lookAt->l[0].l.pad2 = lookAt->l[1].l.pad1 = lookAt->l[1].l.pad2 = 0;

    Lights_SetColor(&lookAt->l[0], 0, 0, 0);
    Lights_SetColor(&lookAt->l[1], 0, 128, 0);

    Lights_SetDirection(&lookAt->l[0], Math_Round(mtx->m[0][0] * 120.0f), Math_Round(mtx->m[1][0] * 120.0f),
                        Math_Round(mtx->m[2][0] * 120.0f));
    Lights_SetDirection(&lookAt->l[1], Math_Round(mtx->m[0][1] * 120.0f), Math_Round(mtx->m[1][1] * 120.0f),
                        Math_Round(mtx->m[2][1] * 120.0f));
}

void func_8006B18C(LookAt* lookAt, s32* arg1, MtxF* arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv1;

    Light_SetLookAtSource(lookAt, arg2);
    temp_fa1 = arg2->m[0][2] + arg3;
    temp_ft4 = arg2->m[1][2] + arg4;
    temp_ft5 = arg2->m[2][2] + arg5;
    temp_fa0 = SQ(temp_fa1) + SQ(temp_ft4) + SQ(temp_ft5);
    if (temp_fa0 > 0.01f) {
        temp_fv1 = 1.0 / sqrtf(temp_fa0);
        temp_fa1 *= temp_fv1;
        temp_ft4 *= temp_fv1;
        temp_ft5 *= temp_fv1;

        arg1[0] =
            (temp_fa1 * arg2->m[0][0] + temp_ft4 * arg2->m[1][0] + temp_ft5 * arg2->m[2][0]) * (arg6 * 2) + arg6 * 4;
        arg1[1] =
            (temp_fa1 * arg2->m[0][1] + temp_ft4 * arg2->m[1][1] + temp_ft5 * arg2->m[2][1]) * (arg7 * 2) + arg7 * 4;
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

void Matrix_FromMtx(Mtx* src2, MtxF* dest) {
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

void Matrix_ToMtx(MtxF* src, Mtx* dest2) {
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
    Matrix_ToMtx(arg1, arg0);
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
    Matrix_ToMtx(arg1, arg0);
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

    Matrix_ToMtx(arg1, arg0);
}

void func_8006C378(Mtx* arg0, MtxF* arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 temp_fv1;
    f32 sp28;
    f32 sp24;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 sp18;
    f32 temp;
    f32 temp2;
    f32 temp3;
    f32 temp4;

    if (arg0 == NULL) {
        arg0 = &D_800E1230;
    }
    if (arg1 == NULL) {
        arg1 = &D_800E1270;
    }

    arg1->yz = -(temp_fv1 = SIN(arg3));
    sp28 = SIN(arg4);
    arg1->xz = (sp28 = SIN(arg4)) * (temp_fv0 = COS(arg3));
    arg1->zz = (temp_ft5 = COS(arg4)) * temp_fv0;
    arg1->yx = (sp24 = SIN(arg5)) * temp_fv0;
    arg1->yy = (sp18 = COS(arg5)) * temp_fv0;

    // FAKE
    temp = sp28 * sp24;
    temp4 = temp_ft5 * sp18;
    temp2 = sp28 * sp18;
    temp3 = sp24 * temp_ft5;
    arg1->xx = (temp_ft5 * sp18) + temp_fv1 * (sp28 * sp24);
    arg1->xy = temp_fv1 * temp2 - temp3;
    arg1->zx = temp_fv1 * temp3 - temp2;
    arg1->zy = temp_fv1 * temp4 + temp;

    arg1->xw = arg6;
    arg1->yw = arg7;
    arg1->zw = arg8;
    arg1->wx = arg1->wy = arg1->wz = 0.0f;
    arg1->ww = 1.0f;
    Matrix_ToMtx(arg1, arg0);
}

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
        Matrix_ToMtx(arg1, arg0);
    }
}

void func_8006CC98(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                   f32 arg9, f32 argA) {
    f32 temp_fa0;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;

    if (arg0 == NULL) {
        arg0 = &D_800E1230;
    }
    if (arg1 == NULL) {
        arg1 = &D_800E1270;
    }

    sp68 = arg2 - arg5;
    sp64 = arg3 - arg6;
    sp60 = arg4 - arg7;

    temp_fa0 = SQ(sp68) + SQ(sp64) + SQ(sp60);
    if (temp_fa0 <= 0.0f) {
        return;
    }

    temp_fa0 = 1.0f / sqrtf(temp_fa0);
    {
        MtxF* mtxF = arg1;
        mtxF->zy = sp64 * temp_fa0;
        mtxF->zx = sp68 * temp_fa0;
        mtxF->zz = sp60 * temp_fa0;

        mtxF->zw = -arg2 * mtxF->zx - arg3 * mtxF->zy - mtxF->zz * arg4;
    }

    sp8C = (arg9 * sp60) - (argA * sp64);
    sp88 = (argA * sp68) - (arg8 * sp60);
    sp84 = (arg8 * sp64) - (arg9 * sp68);

    temp_fa0 = SQ(sp8C) + SQ(sp88) + SQ(sp84);
    if (temp_fa0 <= 0.0f) {
        return;
    }

    temp_fa0 = 1.0f / sqrtf(temp_fa0);
    {
        MtxF* mtxF = arg1;
        mtxF->xy = sp88 * temp_fa0;
        mtxF->xx = sp8C * temp_fa0;
        mtxF->xz = sp84 * temp_fa0;

        mtxF->xw = -arg2 * mtxF->xx - arg3 * mtxF->xy - mtxF->xz * arg4;
    }

    sp80 = (sp64 * sp84) - (sp60 * sp88);
    sp7C = (sp60 * sp8C) - (sp68 * sp84);
    sp78 = (sp68 * sp88) - (sp64 * sp8C);

    temp_fa0 = SQ(sp80) + SQ(sp7C) + SQ(sp78);
    if (temp_fa0 <= 0.0f) {
        return;
    }

    temp_fa0 = 1.0f / sqrtf(temp_fa0);
    {
        MtxF* mtxF = arg1;
        mtxF->yy = sp7C * temp_fa0;
        mtxF->yx = sp80 * temp_fa0;
        mtxF->yz = sp78 * temp_fa0;

        mtxF->yw = -arg2 * mtxF->yx - arg3 * mtxF->yy - mtxF->yz * arg4;
    }

    arg1->wx = 0.0f;
    arg1->wy = 0.0f;
    arg1->wz = 0.0f;
    arg1->ww = 1.0f;
    Matrix_ToMtx(arg1, arg0);
}

void func_8006D03C(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                   u16* arg9) {
    s32 angle;
    f32 sp58;
    f32 temp_fv1;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    if (arg0 == NULL) {
        arg0 = &D_800E1230;
    }
    if (arg1 == NULL) {
        arg1 = &D_800E1270;
    }

    angle = Math_Round(arg2 * ((0x1000 / 360.0f) / 2));
    sp58 = TAN(angle) * arg3;
    arg6 *= (sp58 + sp58) / arg5;

    sp4C = arg6 + sp58;
    sp50 = arg6 - sp58;

    angle = Math_Round(arg2 * ((0x1000 / 360.0f) / 2));

    sp58 *= arg7 / arg5;
    arg8 *= (sp58 + sp58) / arg7;

    sp48 = arg8 + sp58;
    sp44 = arg8 - sp58;

    arg1->m[0][0] = (arg3 + arg3) * (1.0f / (sp4C - sp50));
    arg1->m[2][0] = (sp4C + sp50) * (1.0f / (sp4C - sp50));

    // Unused
    sp58 *= arg7 / arg5;

    arg1->m[1][1] = (arg3 + arg3) * (1.0f / (sp48 - sp44));
    arg1->m[2][1] = (sp48 + sp44) * (1.0f / (sp48 - sp44));

    arg1->m[3][2] = (arg3 + arg3) * arg4 * (1.0f / (arg3 - arg4));
    arg1->m[2][2] = (arg3 + arg4) * (1.0f / (arg3 - arg4));

    if ((arg3 + arg4) > 2.0f) {
        u16 temp_v0;

        *arg9 = temp_v0 = 131072.0f / (arg3 + arg4);
        if (!temp_v0) {
            *arg9 = 1;
        }
    } else {
        *arg9 = -1;
    }

    arg1->m[0][1] = arg1->m[0][2] = arg1->m[0][3] = arg1->m[1][0] = arg1->m[1][2] = arg1->m[1][3] = arg1->m[3][0] =
        arg1->m[3][1] = arg1->m[3][3] = 0.0f;
    arg1->m[2][3] = -1.0f;
    Matrix_ToMtx(arg1, arg0);
}

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
    Matrix_ToMtx(arg1, arg0);
}
