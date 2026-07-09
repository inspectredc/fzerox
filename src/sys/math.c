#include "global.h"
#include "audio.h"
#include "fzx_camera.h"
#include ASSET_HEADER(course_track_gfx.h)

f32 gSinTable[0x1000];
Mtx sDefaultMtx;
MtxF sDefaultMtxF;

Controller* Controller_GetMouse(void) {
    s32 i;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if ((gControllerStatus[i].type & CONT_TYPE_MASK) == CONT_TYPE_MOUSE) {
            return &gControllers[i];
        }
    }

    return NULL;
}

void func_80069F5C(FrameBuffer* fb) {
    u64* var_s0 = &fb->array[SCREEN_HEIGHT - 1][SCREEN_WIDTH - 4];
    s32 var_s1;

    // FAKE?
    while (var_s0 >= fb->buffer) {
        *(--var_s0 + 1) = 0x1000100010001;
    }
    osWritebackDCache(fb, sizeof(FrameBuffer));

    var_s0 = &fb->array[70][96];

    for (var_s1 = 0; var_s1 < 0x6A00; var_s1 += 0x100, var_s0 += 80) {
#ifndef EXPANSION_KIT
        Dma_ClearRomCopy((uintptr_t) SEGMENT_ROM_START(boot_textures) + var_s1 + sizeof(Gfx), var_s0, 0x100);
#else
        Dma_ClearRomCopy(gRomSegmentPairs[3][0] + var_s1 + sizeof(Gfx), var_s0, 0x100);
#endif
    }
}

Gfx* func_8006A00C(Gfx* gfx, s32 scissorBoxType) {
    ScissorBox* scissorBox;

    switch (scissorBoxType) {
        case SCISSOR_BOX_FULL_SCREEN:
            gSPViewport(gfx++, &aVpFullScreen);
            scissorBox = &gScissorBoxFullScreen;
            break;
        case SCISSOR_BOX_TOP_HALF:
            gSPViewport(gfx++, &aVpTopHalf);
            scissorBox = &gScissorBoxTopHalf;
            break;
        case SCISSOR_BOX_BOTTOM_HALF:
            gSPViewport(gfx++, &aVpBottomHalf);
            scissorBox = &gScissorBoxBottomHalf;
            break;
        case SCISSOR_BOX_LEFT_HALF:
            gSPViewport(gfx++, &aVpLeftHalf);
            scissorBox = &gScissorBoxLeftHalf;
            break;
        case SCISSOR_BOX_RIGHT_HALF:
            gSPViewport(gfx++, &aVpRightHalf);
            scissorBox = &gScissorBoxRightHalf;
            break;
        case SCISSOR_BOX_TOP_LEFT_QUARTER:
            gSPViewport(gfx++, &aVpTopLeftQuarter);
            scissorBox = &gScissorBoxTopLeftQuarter;
            break;
        case SCISSOR_BOX_TOP_RIGHT_QUARTER:
            gSPViewport(gfx++, &aVpTopRightQuarter);
            scissorBox = &gScissorBoxTopRightQuarter;
            break;
        case SCISSOR_BOX_BOTTOM_LEFT_QUARTER:
            gSPViewport(gfx++, &aVpBottomLeftQuarter);
            scissorBox = &gScissorBoxBottomLeftQuarter;
            break;
        case SCISSOR_BOX_BOTTOM_RIGHT_QUARTER:
            gSPViewport(gfx++, &aVpBottomRightQuarter);
            scissorBox = &gScissorBoxBottomRightQuarter;
            break;
        case SCISSOR_BOX_TOP_CENTER_QUARTER:
            gSPViewport(gfx++, &aVpTopCenterQuarter);
            scissorBox = &gScissorBoxTopCenterQuarter;
            break;
        case SCISSOR_BOX_BOTTOM_CENTER_QUARTER:
            gSPViewport(gfx++, &aVpBottomCenterQuarter);
            scissorBox = &gScissorBoxBottomCenterQuarter;
            break;
        case SCISSOR_BOX_LEFT_CENTER_QUARTER:
            gSPViewport(gfx++, &aVpLeftCenterQuarter);
            scissorBox = &gScissorBoxLeftCenterQuarter;
            break;
        case SCISSOR_BOX_RIGHT_CENTER_QUARTER:
            gSPViewport(gfx++, &aVpRightCenterQuarter);
            scissorBox = &gScissorBoxRightCenterQuarter;
            break;
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, scissorBox->left, scissorBox->top, scissorBox->right, scissorBox->bottom);

    return gfx;
}

void Math_SetVtxTriNormal(Vtx* vtx, s32 targetVtxIndex, s32 triIndex1, s32 triIndex2, s32 triIndex3) {
    s32 var20;
    s32 var22;
    s32 var24;
    s32 var30;
    s32 var32;
    s32 var34;
    s32 var40;
    s32 var42;
    s32 var44;
    f32 normX;
    f32 normY;
    f32 normZ;
    f32 normalizingFactor;
    Vtx* vtx2;

    vtx2 = &vtx[triIndex1];
    var20 = vtx2->v.ob[0];
    var22 = vtx2->v.ob[1];
    var24 = vtx2->v.ob[2];

    vtx2 = &vtx[triIndex2];
    var30 = vtx2->v.ob[0];
    var32 = vtx2->v.ob[1];
    var34 = vtx2->v.ob[2];

    vtx2 = &vtx[triIndex3];
    var40 = vtx2->v.ob[0];
    var42 = vtx2->v.ob[1];
    var44 = vtx2->v.ob[2];

    normX = ((var24 - var34) * (var42 - var32)) - ((var22 - var32) * (var44 - var34));
    normY = ((var20 - var30) * (var44 - var34)) - ((var24 - var34) * (var40 - var30));
    normZ = ((var22 - var32) * (var40 - var30)) - ((var20 - var30) * (var42 - var32));

    normalizingFactor = SQ(normX) + SQ(normY) + SQ(normZ);

    if (normalizingFactor < 0.1f) {
        return;
    }

    normalizingFactor = 110.0f / sqrtf(normalizingFactor);

    vtx2 = &vtx[targetVtxIndex];
    vtx2->v.cn[0] = normX * normalizingFactor;
    vtx2->v.cn[1] = normY * normalizingFactor;
    vtx2->v.cn[2] = normZ * normalizingFactor;
}

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

s32 Math_OrthonormalizeAroundForward(Mtx3F* basis) {
    f32 temp_fs0;

    temp_fs0 = SQ(basis->x.x) + SQ(basis->x.y) + SQ(basis->x.z);

    if (temp_fs0 == 0.0f) {
        return -1;
    }

    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    basis->x.x *= temp_fs0;
    basis->x.y *= temp_fs0;
    basis->x.z *= temp_fs0;

    basis->z.x = basis->y.y * basis->x.z - basis->y.z * basis->x.y;
    basis->z.y = basis->y.z * basis->x.x - basis->y.x * basis->x.z;
    basis->z.z = basis->y.x * basis->x.y - basis->y.y * basis->x.x;

    temp_fs0 = SQ(basis->z.x) + SQ(basis->z.y) + SQ(basis->z.z);

    if (temp_fs0 == 0.0f) {
        return -1;
    }

    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    basis->z.x *= temp_fs0;
    basis->z.y *= temp_fs0;
    basis->z.z *= temp_fs0;

    basis->y.x = basis->x.y * basis->z.z - basis->x.z * basis->z.y;
    basis->y.y = basis->x.z * basis->z.x - basis->x.x * basis->z.z;
    basis->y.z = basis->x.x * basis->z.y - basis->x.y * basis->z.x;
    return 0;
}

s32 Math_OrthonormalizeAroundUp(Mtx3F* basis) {
    f32 temp_fs0;

    temp_fs0 = SQ(basis->y.x) + SQ(basis->y.y) + SQ(basis->y.z);
    if (temp_fs0 == 0.0f) {
        return -1;
    }
    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    basis->y.x *= temp_fs0;
    basis->y.y *= temp_fs0;
    basis->y.z *= temp_fs0;

    basis->z.x = basis->y.y * basis->x.z - basis->y.z * basis->x.y;
    basis->z.y = basis->y.z * basis->x.x - basis->y.x * basis->x.z;
    basis->z.z = basis->y.x * basis->x.y - basis->y.y * basis->x.x;

    temp_fs0 = SQ(basis->z.x) + SQ(basis->z.y) + SQ(basis->z.z);
    if (temp_fs0 == 0.0f) {
        return -1;
    }
    temp_fs0 = 1.0f / sqrtf(temp_fs0);

    basis->z.x *= temp_fs0;
    basis->z.y *= temp_fs0;
    basis->z.z *= temp_fs0;

    basis->x.x = basis->z.y * basis->y.z - basis->z.z * basis->y.y;
    basis->x.y = basis->z.z * basis->y.x - basis->z.x * basis->y.z;
    basis->x.z = basis->z.x * basis->y.y - basis->z.y * basis->y.x;
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

    light->a.l.pad1 = light->a.l.pad2 = light->l[0].l.pad1 = light->l[0].l.pad2 = light->l[0].l.pad3 = 0;

    Lights_SetAmbient(&light->a, ambientR, ambientG, ambientB);
    Lights_SetColor(&light->l[0], r, g, b);
    Lights_SetDirection(&light->l[0], x, y, z);
}

void Light_SetLookAtSource(LookAt* lookAt, MtxF* mtx) {

    lookAt->l[0].l.pad1 = lookAt->l[0].l.pad2 = lookAt->l[1].l.pad1 = lookAt->l[1].l.pad2 = 0;

    Lights_SetColor(&lookAt->l[0], 0, 0, 0);
    Lights_SetColor(&lookAt->l[1], 0, 128, 0);

    Lights_SetDirection(&lookAt->l[0], Math_Round(mtx->m[0][0] * 120.0f), Math_Round(mtx->m[1][0] * 120.0f),
                        Math_Round(mtx->m[2][0] * 120.0f));
    Lights_SetDirection(&lookAt->l[1], Math_Round(mtx->m[0][1] * 120.0f), Math_Round(mtx->m[1][1] * 120.0f),
                        Math_Round(mtx->m[2][1] * 120.0f));
}

void func_8006B18C(LookAt* lookAt, s32* arg1, MtxF* mtxF, f32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv1;

    Light_SetLookAtSource(lookAt, mtxF);
    temp_fa1 = mtxF->m[0][2] + arg3;
    temp_ft4 = mtxF->m[1][2] + arg4;
    temp_ft5 = mtxF->m[2][2] + arg5;
    temp_fa0 = SQ(temp_fa1) + SQ(temp_ft4) + SQ(temp_ft5);
    if (temp_fa0 > 0.01f) {
#ifndef EXPANSION_KIT
        temp_fv1 = 1.0 / sqrtf(temp_fa0);
#else
        temp_fv1 = 1.0f / sqrtf(temp_fa0);
#endif
        temp_fa1 *= temp_fv1;
        temp_ft4 *= temp_fv1;
        temp_ft5 *= temp_fv1;

        arg1[0] =
            (temp_fa1 * mtxF->m[0][0] + temp_ft4 * mtxF->m[1][0] + temp_ft5 * mtxF->m[2][0]) * (arg6 * 2) + arg6 * 4;
        arg1[1] =
            (temp_fa1 * mtxF->m[0][1] + temp_ft4 * mtxF->m[1][1] + temp_ft5 * mtxF->m[2][1]) * (arg7 * 2) + arg7 * 4;
    } else {
        arg1[0] = arg6 * 2;
        arg1[1] = arg7 * 2;
    }
}

#define FTO32(x) (long) ((x) *65536.0f)
#define MTXTOMTXF(mtx, i1, i2) ((((s16) mtx->u.i[(i1)][(i2)] << 0x10) | mtx->u.f[(i1)][(i2)]) / 65536.0f)

void Matrix_Interpolate(Mtx* src, Mtx* target, Mtx* dest, f32 t) {
    f32 temp_fa0;
    f32 temp_fv1;
    s32 x2;
    s32 y2;
    s32 z2;
    f32 x5;
    f32 y5;
    f32 z5;
    f32 x1;
    f32 y1;
    f32 z1;
    f32 x4;
    f32 y4;
    f32 z4;

    temp_fa0 = MTXTOMTXF(src, 1, 0);
    temp_fv1 = MTXTOMTXF(target, 1, 0);
    x1 = ((temp_fv1 - temp_fa0) * t) + temp_fa0;

    temp_fa0 = MTXTOMTXF(src, 1, 1);
    temp_fv1 = MTXTOMTXF(target, 1, 1);
    y1 = ((temp_fv1 - temp_fa0) * t) + temp_fa0;

    temp_fa0 = MTXTOMTXF(src, 1, 2);
    temp_fv1 = MTXTOMTXF(target, 1, 2);
    z1 = ((temp_fv1 - temp_fa0) * t) + temp_fa0;

    temp_fa0 = SQ(x1) + SQ(y1) + SQ(z1);
    if (temp_fa0 == 0.0f) {
        return;
    }

    temp_fa0 = 65536.0f / sqrtf(temp_fa0);
    x2 = (s32) (x1 * temp_fa0);
    y2 = (s32) (y1 * temp_fa0);
    z2 = (s32) (z1 * temp_fa0);

    dest->m[0][2] = (x2 & 0xFFFF0000) | ((u32) y2 >> 0x10);
    dest->m[0][3] = z2 & 0xFFFF0000;
    dest->m[2][2] = (x2 << 0x10) | (y2 & 0xFFFF);
    dest->m[2][3] = z2 << 0x10;

    temp_fa0 = MTXTOMTXF(src, 2, 0);
    temp_fv1 = MTXTOMTXF(target, 2, 0);
    x4 = ((temp_fv1 - temp_fa0) * t) + temp_fa0;

    temp_fa0 = MTXTOMTXF(src, 2, 1);
    temp_fv1 = MTXTOMTXF(target, 2, 1);
    y4 = ((temp_fv1 - temp_fa0) * t) + temp_fa0;

    temp_fa0 = MTXTOMTXF(src, 2, 2);
    temp_fv1 = MTXTOMTXF(target, 2, 2);
    z4 = ((temp_fv1 - temp_fa0) * t) + temp_fa0;

    x5 = ((z4 - z1) * y1) - (z1 * (y4 - y1));
    y5 = ((x4 - x1) * z1) - (x1 * (z4 - z1));
    z5 = ((y4 - y1) * x1) - (y1 * (x4 - x1));

    temp_fa0 = SQ(x5) + SQ(y5) + SQ(z5);

    if (temp_fa0 == 0.0f) {
        return;
    }

    temp_fa0 = 65536.0f / sqrtf(temp_fa0);

    x2 = (s32) (x5 * temp_fa0);
    y2 = (s32) (y5 * temp_fa0);
    z2 = (s32) (z5 * temp_fa0);

    dest->m[0][0] = (x2 & 0xFFFF0000) | ((u32) y2 >> 0x10);
    dest->m[0][1] = z2 & 0xFFFF0000;
    dest->m[2][0] = (x2 << 0x10) | (y2 & 0xFFFF);
    dest->m[2][1] = z2 << 0x10;

    x4 = ((z1 - z5) * y5) - (z5 * (y1 - y5));
    y4 = ((x1 - x5) * z5) - (x5 * (z1 - z5));
    z4 = ((y1 - y5) * x5) - (y5 * (x1 - x5));

    temp_fa0 = SQ(x4) + SQ(y4) + SQ(z4);

    if (temp_fa0 == 0.0f) {
        return;
    }

    temp_fa0 = 65536.0f / sqrtf(temp_fa0);

    x2 = (s32) (x4 * temp_fa0);
    y2 = (s32) (y4 * temp_fa0);
    z2 = (s32) (z4 * temp_fa0);

    dest->m[1][0] = (x2 & 0xFFFF0000) | ((u32) y2 >> 0x10);
    dest->m[1][1] = z2 & 0xFFFF0000;
    dest->m[3][0] = (x2 << 0x10) | (y2 & 0xFFFF);
    dest->m[3][1] = z2 << 0x10;

    temp_fa0 = MTXTOMTXF(src, 3, 0);
    temp_fv1 = MTXTOMTXF(target, 3, 0);
    x2 = FTO32(((temp_fv1 - temp_fa0) * t) + temp_fa0);

    temp_fa0 = MTXTOMTXF(src, 3, 1);
    temp_fv1 = MTXTOMTXF(target, 3, 1);
    y2 = FTO32(((temp_fv1 - temp_fa0) * t) + temp_fa0);

    temp_fa0 = MTXTOMTXF(src, 3, 2);
    temp_fv1 = MTXTOMTXF(target, 3, 2);
    z2 = FTO32(((temp_fv1 - temp_fa0) * t) + temp_fa0);

    dest->m[1][2] = (x2 & 0xFFFF0000) | ((u32) y2 >> 0x10);
    dest->m[1][3] = (z2 & 0xFFFF0000) | 1;
    dest->m[3][2] = (x2 << 0x10) | (y2 & 0xFFFF);
    dest->m[3][3] = z2 << 0x10;
}

void Matrix_AffineMultiply(MtxF* mtxFA, MtxF* mtxFB, MtxF* dest) {
    dest->m[0][0] = mtxFA->m[0][0] * mtxFB->m[0][0] + mtxFA->m[1][0] * mtxFB->m[0][1] + mtxFA->m[2][0] * mtxFB->m[0][2];
    dest->m[0][1] = mtxFA->m[0][1] * mtxFB->m[0][0] + mtxFA->m[1][1] * mtxFB->m[0][1] + mtxFA->m[2][1] * mtxFB->m[0][2];
    dest->m[0][2] = mtxFA->m[0][2] * mtxFB->m[0][0] + mtxFA->m[1][2] * mtxFB->m[0][1] + mtxFA->m[2][2] * mtxFB->m[0][2];

    dest->m[1][0] = mtxFA->m[0][0] * mtxFB->m[1][0] + mtxFA->m[1][0] * mtxFB->m[1][1] + mtxFA->m[2][0] * mtxFB->m[1][2];
    dest->m[1][1] = mtxFA->m[0][1] * mtxFB->m[1][0] + mtxFA->m[1][1] * mtxFB->m[1][1] + mtxFA->m[2][1] * mtxFB->m[1][2];
    dest->m[1][2] = mtxFA->m[0][2] * mtxFB->m[1][0] + mtxFA->m[1][2] * mtxFB->m[1][1] + mtxFA->m[2][2] * mtxFB->m[1][2];

    dest->m[2][0] = mtxFA->m[0][0] * mtxFB->m[2][0] + mtxFA->m[1][0] * mtxFB->m[2][1] + mtxFA->m[2][0] * mtxFB->m[2][2];
    dest->m[2][1] = mtxFA->m[0][1] * mtxFB->m[2][0] + mtxFA->m[1][1] * mtxFB->m[2][1] + mtxFA->m[2][1] * mtxFB->m[2][2];
    dest->m[2][2] = mtxFA->m[0][2] * mtxFB->m[2][0] + mtxFA->m[1][2] * mtxFB->m[2][1] + mtxFA->m[2][2] * mtxFB->m[2][2];

    dest->m[3][0] = mtxFA->m[0][0] * mtxFB->m[3][0] + mtxFA->m[1][0] * mtxFB->m[3][1] +
                    mtxFA->m[2][0] * mtxFB->m[3][2] + mtxFA->m[3][0];
    dest->m[3][1] = mtxFA->m[0][1] * mtxFB->m[3][0] + mtxFA->m[1][1] * mtxFB->m[3][1] +
                    mtxFA->m[2][1] * mtxFB->m[3][2] + mtxFA->m[3][1];
    dest->m[3][2] = mtxFA->m[0][2] * mtxFB->m[3][0] + mtxFA->m[1][2] * mtxFB->m[3][1] +
                    mtxFA->m[2][2] * mtxFB->m[3][2] + mtxFA->m[3][2];

    dest->m[0][3] = 0.0f;
    dest->m[1][3] = 0.0f;
    dest->m[2][3] = 0.0f;
    dest->m[3][3] = 1.0f;
}

void Matrix_FromMtx(Mtx* src2, MtxF* dest) {
    s32 i;
    s32 j;
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

void Matrix_SetLockedLookAt(Mtx* mtx, MtxF* mtxF, f32 scaleZ, f32 scaleY, f32 scaleX, f32 lookAtX, f32 lookAtY,
                            f32 lookAtZ, f32 upX, f32 upY, f32 upZ, f32 xPos, f32 yPos, f32 zPos) {
    f32 magnitude;
    f32 normalX;
    f32 normalY;
    f32 normalZ;
    f32 trueUpX;
    f32 trueUpY;
    f32 trueUpZ;
    f32 normalizedScale;

    if (mtx == NULL) {
        mtx = &sDefaultMtx;
    }
    if (mtxF == NULL) {
        mtxF = &sDefaultMtxF;
    }
    magnitude = SQ(lookAtX) + SQ(lookAtY) + SQ(lookAtZ);
    if (magnitude < 0.001f) {
        Matrix_SetTransRot(mtx, mtxF, scaleZ, 0, 0, 0, xPos, yPos, zPos);
        return;
    }
    normalizedScale = scaleZ / sqrtf(magnitude);
    mtxF->m[2][0] = normalizedScale * lookAtX;
    mtxF->m[2][1] = normalizedScale * lookAtY;
    mtxF->m[2][2] = normalizedScale * lookAtZ;
    normalX = (upY * lookAtZ) - (upZ * lookAtY);
    normalY = (upZ * lookAtX) - (upX * lookAtZ);
    normalZ = (upX * lookAtY) - (upY * lookAtX);

    magnitude = SQ(normalX) + SQ(normalY) + SQ(normalZ);
    if (magnitude < 0.001f) {
        Matrix_SetTransRot(mtx, mtxF, scaleZ, 0, 0, 0, xPos, yPos, zPos);
        return;
    }

    normalizedScale = scaleX / sqrtf(magnitude);
    mtxF->m[0][0] = normalizedScale * normalX;
    mtxF->m[0][1] = normalizedScale * normalY;
    mtxF->m[0][2] = normalizedScale * normalZ;

    trueUpX = (lookAtY * normalZ) - (lookAtZ * normalY);
    trueUpY = (lookAtZ * normalX) - (lookAtX * normalZ);
    trueUpZ = (lookAtX * normalY) - (lookAtY * normalX);
    magnitude = SQ(trueUpX) + SQ(trueUpY) + SQ(trueUpZ);
    if (magnitude < 0.001f) {
        Matrix_SetTransRot(mtx, mtxF, scaleZ, 0, 0, 0, xPos, yPos, zPos);
        return;
    }
    normalizedScale = scaleY / sqrtf(magnitude);
    mtxF->m[1][0] = normalizedScale * trueUpX;
    mtxF->m[1][1] = normalizedScale * trueUpY;
    mtxF->m[1][2] = normalizedScale * trueUpZ;
    mtxF->m[3][0] = xPos;
    mtxF->m[3][1] = yPos;
    mtxF->m[3][2] = zPos;
    mtxF->m[0][3] = 0.0f;
    mtxF->m[1][3] = 0.0f;
    mtxF->m[2][3] = 0.0f;
    mtxF->m[3][3] = 1.0f;
    Matrix_ToMtx(mtxF, mtx);
}

void Matrix_SetLockedLookAtFromVectors(Mtx* mtx, MtxF* mtxF, f32 scaleZ, f32 scaleY, f32 scaleX, Vec3f* lookAt,
                                       Vec3f* up, Vec3f* pos) {
    f32 normalizedScale;
    f32 normalX;
    f32 normalY;
    f32 normalZ;
    f32 trueUpX;
    f32 trueUpY;
    f32 trueUpZ;
    s32 pad;

    if (mtx == NULL) {
        mtx = &sDefaultMtx;
    }
    if (mtxF == NULL) {
        mtxF = &sDefaultMtxF;
    }
    mtxF->m[2][0] = lookAt->x * scaleZ;
    mtxF->m[2][1] = lookAt->y * scaleZ;
    mtxF->m[2][2] = lookAt->z * scaleZ;

    normalX = (up->y * lookAt->z) - (up->z * lookAt->y);
    normalY = (up->z * lookAt->x) - (up->x * lookAt->z);
    normalZ = (up->x * lookAt->y) - (up->y * lookAt->x);
    normalizedScale = SQ(normalX) + SQ(normalY) + SQ(normalZ);
    if (normalizedScale < 0.001f) {
        Matrix_SetTransRot(mtx, mtxF, scaleZ, 0, 0, 0, pos->x, pos->y, pos->z);
        return;
    }

    normalizedScale = scaleX / sqrtf(normalizedScale);
    mtxF->m[0][0] = normalizedScale * normalX;
    mtxF->m[0][1] = normalizedScale * normalY;
    mtxF->m[0][2] = normalizedScale * normalZ;

    trueUpX = (lookAt->y * normalZ) - (lookAt->z * normalY);
    trueUpY = (lookAt->z * normalX) - (lookAt->x * normalZ);
    trueUpZ = (lookAt->x * normalY) - (lookAt->y * normalX);

    normalizedScale = SQ(trueUpX) + SQ(trueUpY) + SQ(trueUpZ);
    if (normalizedScale < 0.001f) {
        Matrix_SetTransRot(mtx, mtxF, scaleZ, 0, 0, 0, pos->x, pos->y, pos->z);
        return;
    }
    normalizedScale = scaleY / sqrtf(normalizedScale);
    mtxF->m[1][0] = normalizedScale * trueUpX;
    mtxF->m[1][1] = normalizedScale * trueUpY;
    mtxF->m[1][2] = normalizedScale * trueUpZ;
    mtxF->m[3][0] = pos->x;
    mtxF->m[3][1] = pos->y;
    mtxF->m[3][2] = pos->z;
    mtxF->m[0][3] = 0.0f;
    mtxF->m[1][3] = 0.0f;
    mtxF->m[2][3] = 0.0f;
    mtxF->m[3][3] = 1.0f;
    Matrix_ToMtx(mtxF, mtx);
}

void Matrix_ScaleFrom3DMatrix(Mtx* mtx, MtxF* mtxF, f32 xScale, f32 yScale, f32 zScale, Mtx3F* matrix3D, Vec3f* pos) {

    if (mtx == NULL) {
        mtx = &sDefaultMtx;
    }
    if (mtxF == NULL) {
        mtxF = &sDefaultMtxF;
    }
    mtxF->m[2][0] = matrix3D->x.x * xScale;
    mtxF->m[2][1] = matrix3D->x.y * xScale;
    mtxF->m[2][2] = matrix3D->x.z * xScale;
    mtxF->m[0][0] = matrix3D->z.x * zScale;
    mtxF->m[0][1] = matrix3D->z.y * zScale;
    mtxF->m[0][2] = matrix3D->z.z * zScale;
    mtxF->m[1][0] = matrix3D->y.x * yScale;
    mtxF->m[1][1] = matrix3D->y.y * yScale;
    mtxF->m[1][2] = matrix3D->y.z * yScale;
    mtxF->m[3][0] = pos->x;
    mtxF->m[3][1] = pos->y;
    mtxF->m[3][2] = pos->z;
    mtxF->m[0][3] = 0.0f;
    mtxF->m[1][3] = 0.0f;
    mtxF->m[2][3] = 0.0f;
    mtxF->m[3][3] = 1.0f;

    Matrix_ToMtx(mtxF, mtx);
}

void Matrix_SetTransRot(Mtx* mtx, MtxF* mtxF, f32 scale, s32 xRot, s32 yRot, s32 zRot, f32 xPos, f32 yPos, f32 zPos) {
    f32 sinX;
    f32 sinY;
    f32 sinZ;
    f32 cosX;
    f32 cosY;
    f32 cosZ;
    f32 sinYsinZ;
    f32 sinYcosZ;
    f32 sinZcosY;
    f32 cosYcosZ;

    if (mtx == NULL) {
        mtx = &sDefaultMtx;
    }
    if (mtxF == NULL) {
        mtxF = &sDefaultMtxF;
    }

    mtxF->m[2][1] = -(sinX = SIN(xRot));
    mtxF->m[2][0] = (sinY = SIN(yRot)) * (cosX = COS(xRot));
    mtxF->m[2][2] = (cosY = COS(yRot)) * cosX;
    mtxF->m[0][1] = (sinZ = SIN(zRot)) * cosX;
    mtxF->m[1][1] = (cosZ = COS(zRot)) * cosX;

    mtxF->m[0][0] = sinX * (sinYsinZ = (sinY * sinZ)) + (cosYcosZ = (cosY * cosZ));
    mtxF->m[1][0] = sinX * (sinYcosZ = (sinY * cosZ)) - (sinZcosY = (sinZ * cosY));
    mtxF->m[0][2] = sinX * sinZcosY - sinYcosZ;
    mtxF->m[1][2] = sinX * cosYcosZ + sinYsinZ;

    mtxF->m[3][0] = xPos;
    mtxF->m[3][1] = yPos;
    mtxF->m[3][2] = zPos;
    mtxF->m[0][3] = mtxF->m[1][3] = mtxF->m[2][3] = 0.0f;
    mtxF->m[3][3] = 1.0f;
    Matrix_ToMtx(mtxF, mtx);
}

#ifdef NON_MATCHING
void Matrix_SetAxisRotation(Mtx* arg0, MtxF* arg1, f32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                            f32 arg9) {
    f32 sin;
    f32 cos;
    f32 sp8C;
    f32 sp84;
    f32 sp7C;
    f32 sp70;
    f32 sp6C;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;

    if (arg0 == NULL) {
        arg0 = &sDefaultMtx;
    }
    if (arg1 == NULL) {
        arg1 = &sDefaultMtxF;
    }
    cos = COS(arg3);
    sin = SIN(arg3);
    if (arg5 == 0.0f) {
        if (arg4 == 0.0f) {
            if (arg6 < 0.0f) {
                Matrix_SetTransRot(arg0, arg1, arg2, 0, 0, -arg3, arg7, arg8, arg9);
            } else {

                Matrix_SetTransRot(arg0, arg1, arg2, 0, 0, arg3, arg7, arg8, arg9);
            }
            return;
        }
        temp_fv0 = sqrtf(SQ(arg4) + SQ(arg6));
        temp_fv1 = arg4 / temp_fv0;
        temp_ft4 = arg2 * sin;
        temp_fa0 = arg6 / temp_fv0;
        temp_fa1 = -temp_fv1;
        temp_ft5 = temp_ft4 * temp_fa0;
        temp_fs0 = temp_ft4 * temp_fa1;
        temp_fs3 = cos * temp_fa0;
        arg1->m[0][1] = temp_ft5;
        arg1->m[1][0] = -temp_ft5;
        arg1->m[2][1] = temp_fs0;
        arg1->m[1][1] = arg2 * cos;
        arg1->m[1][2] = -temp_fs0;
        arg1->m[0][0] = ((temp_fs3 * temp_fa0) + SQ(temp_fv1)) * arg2;
        arg1->m[2][2] = ((cos * temp_fa1 * temp_fa1) + SQ(temp_fa0)) * arg2;
        temp_fs4 = ((temp_fs3 * temp_fa1) + (temp_fv1 * temp_fa0)) * arg2;
        arg1->m[2][0] = temp_fs4;
        arg1->m[0][2] = temp_fs4;
    } else if (arg6 == 0.0f) {
        temp_fv0 = sqrtf(SQ(arg4) + SQ(arg5));
        temp_fa1 = arg5 / temp_fv0;
        temp_ft4 = arg2 * sin;
        temp_fv1 = arg4 / temp_fv0;
        temp_fs0 = -temp_fa1;
        temp_fa0 = temp_ft4 * temp_fs0;
        arg1->m[0][2] = temp_fa0;
        temp_ft5 = temp_ft4 * temp_fv1;
        arg1->m[2][0] = -temp_fa0;
        arg1->m[1][2] = temp_ft5;
        arg1->m[2][1] = -temp_ft5;
        arg1->m[2][2] = arg2 * cos;
        sp7C = cos * temp_fs0;
        arg1->m[0][0] = ((sp7C * temp_fs0) + SQ(temp_fv1)) * arg2;
        arg1->m[1][1] = ((cos * temp_fv1 * temp_fv1) + SQ(temp_fa1)) * arg2;
        temp_fs4 = ((sp7C * temp_fv1) + (temp_fv1 * temp_fa1)) * arg2;
        arg1->m[1][0] = temp_fs4;
        arg1->m[0][1] = temp_fs4;
    } else if (arg4 == 0.0f) {
        temp_fv0 = sqrtf(SQ(arg5) + SQ(arg6));
        temp_fa1 = arg5 / temp_fv0;
        temp_ft4 = arg2 * sin;
        temp_fa0 = arg6 / temp_fv0;
        temp_fv1 = -temp_fa0;
        temp_ft5 = temp_ft4 * temp_fv1;
        temp_fs0 = temp_ft4 * temp_fa1;
        arg1->m[1][0] = temp_ft5;
        arg1->m[0][1] = -temp_ft5;
        arg1->m[0][2] = -temp_fs0;
        arg1->m[2][0] = temp_fs0;
        arg1->m[0][0] = arg2 * cos;
        sp7C = cos * temp_fv1;
        arg1->m[1][1] = ((sp7C * temp_fv1) + SQ(temp_fa1)) * arg2;
        arg1->m[2][2] = ((cos * temp_fa1 * temp_fa1) + SQ(temp_fa0)) * arg2;
        temp_fs4 = ((sp7C * temp_fa1) + (temp_fa1 * temp_fa0)) * arg2;
        arg1->m[2][1] = temp_fs4;
        arg1->m[1][2] = temp_fs4;
    } else {
        temp_fv0 = sqrtf(SQ(arg4) + SQ(arg5) + SQ(arg6));
        temp_fs4 = arg5 / temp_fv0;
        temp_ft5 = arg4 / temp_fv0;
        temp_ft4 = -temp_fs4;
        sp8C = temp_ft5;
        sp84 = arg6 / temp_fv0;
        temp_fv0 = sqrtf(SQ(temp_ft4) + SQ(temp_ft5));
        temp_ft5 /= temp_fv0;
        temp_ft4 /= temp_fv0;
        temp_fv1 = temp_ft5 * sp84;
        temp_fs3 = ((temp_fs4 - temp_ft5) * temp_ft4) - (temp_ft5 * (sp8C - temp_ft4));
        temp_fv0 = -temp_ft4 * sp84;
        arg1->m[0][0] = (((SQ(temp_fv1) + SQ(temp_ft4)) * cos) + SQ(sp8C)) * arg2;
        arg1->m[1][1] = (((SQ(temp_fv0) + SQ(temp_ft5)) * cos) + SQ(temp_fs4)) * arg2;
        arg1->m[2][2] = ((cos * temp_fs3 * temp_fs3) + SQ(sp84)) * arg2;
        temp_fa0 = (((temp_fv1 * temp_fv0) + (temp_ft4 * temp_ft5)) * cos) + (sp8C * temp_fs4);
        temp_fa1 = ((temp_fv0 * temp_ft4) - (temp_fv1 * temp_ft5)) * sin;
        arg1->m[1][0] = (temp_fa0 + temp_fa1) * arg2;
        arg1->m[0][1] = (temp_fa0 - temp_fa1) * arg2;
        sp6C = (cos * temp_fv1 * temp_fs3) + (sp8C * sp84);
        sp8C = sin * temp_fs3;
        sp70 = sp8C * temp_ft4;
        arg1->m[2][0] = (sp6C + sp70) * arg2;
        arg1->m[0][2] = (sp6C - sp70) * arg2;
        temp_fa0 = (cos * temp_fv0 * temp_fs3) + (temp_fs4 * sp84);
        temp_fv1 = sp8C * temp_ft5;
        arg1->m[2][1] = (temp_fa0 + temp_fv1) * arg2;
        arg1->m[1][2] = (temp_fa0 - temp_fv1) * arg2;
    }

    arg1->m[3][0] = arg7;
    arg1->m[3][1] = arg8;
    arg1->m[3][2] = arg9;
    arg1->m[3][3] = 1.0f;
    arg1->m[0][3] = arg1->m[1][3] = arg1->m[2][3] = 0.0f;
    Matrix_ToMtx(arg1, arg0);
}
#else
#ifndef EXPANSION_KIT
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/sys/math/Matrix_SetAxisRotation.s")
#elif VERSION_US
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/sys/math/Matrix_SetAxisRotation.s")
#elif VERSION_PAL
#pragma GLOBAL_ASM("asm/pal/rev0/nonmatchings/sys/math/Matrix_SetAxisRotation.s")
#endif
#else
#pragma GLOBAL_ASM("asm/jp/ek/nonmatchings/sys/math/Matrix_SetAxisRotation.s")
#endif
#endif

void Matrix_SetShadowProjection(Mtx* mtx, MtxF* mtxF, f32 lightProjectionX, f32 lightProjectionY, f32 lightProjectionZ,
                                f32 planePointX, f32 planePointY, f32 planePointZ, f32 planeNormalX, f32 planeNormalY,
                                f32 planeNormalZ) {
    f32 planeDistanceScale;
    f32 inverseDotProduct;

    if (mtx == NULL) {
        mtx = &sDefaultMtx;
    }
    if (mtxF == NULL) {
        mtxF = &sDefaultMtxF;
    }
    inverseDotProduct =
        (lightProjectionX * planeNormalX) + (lightProjectionY * planeNormalY) + (lightProjectionZ * planeNormalZ);

    if (SQ(inverseDotProduct) < 0.01) {
        return;
    }

    inverseDotProduct = -1.0f / inverseDotProduct;
    planeDistanceScale =
        (((-planeNormalX * planePointX) - (planeNormalY * planePointY)) - (planeNormalZ * planePointZ)) *
        inverseDotProduct;
    planeNormalX *= inverseDotProduct;
    planeNormalY *= inverseDotProduct;
    planeNormalZ *= inverseDotProduct;
    mtxF->m[0][0] = planeNormalX * lightProjectionX + 1.0f;
    mtxF->m[0][1] = planeNormalX * lightProjectionY;
    mtxF->m[0][2] = planeNormalX * lightProjectionZ;
    mtxF->m[1][0] = planeNormalY * lightProjectionX;
    mtxF->m[1][1] = planeNormalY * lightProjectionY + 1.0f;
    mtxF->m[1][2] = planeNormalY * lightProjectionZ;
    mtxF->m[2][0] = planeNormalZ * lightProjectionX;
    mtxF->m[2][1] = planeNormalZ * lightProjectionY;
    mtxF->m[2][2] = planeNormalZ * lightProjectionZ + 1.0f;
    mtxF->m[3][0] = planeDistanceScale * lightProjectionX;
    mtxF->m[3][1] = planeDistanceScale * lightProjectionY;
    mtxF->m[3][2] = planeDistanceScale * lightProjectionZ;
    mtxF->m[0][3] = mtxF->m[1][3] = mtxF->m[2][3] = 0.0f;
    mtxF->m[3][3] = 1.0f;
    Matrix_ToMtx(mtxF, mtx);
}

void Matrix_SetLookAt(Mtx* mtx, MtxF* mtxF, f32 eyeX, f32 eyeY, f32 eyeZ, f32 atX, f32 atY, f32 atZ, f32 upX, f32 upY,
                      f32 upZ) {
    f32 normalizeFactor;
    f32 lookAtX;
    f32 lookAtY;
    f32 lookAtZ;
    f32 normalX;
    f32 normalY;
    f32 normalZ;
    f32 trueUpX;
    f32 trueUpY;
    f32 trueUpZ;

    if (mtx == NULL) {
        mtx = &sDefaultMtx;
    }
    if (mtxF == NULL) {
        mtxF = &sDefaultMtxF;
    }

    lookAtX = eyeX - atX;
    lookAtY = eyeY - atY;
    lookAtZ = eyeZ - atZ;

    normalizeFactor = SQ(lookAtX) + SQ(lookAtY) + SQ(lookAtZ);
    if (normalizeFactor <= 0.0f) {
        return;
    }

    normalizeFactor = 1.0f / sqrtf(normalizeFactor);
    mtxF->m[3][2] = -eyeX * (mtxF->m[0][2] = lookAtX * normalizeFactor) -
                    eyeY * (mtxF->m[1][2] = lookAtY * normalizeFactor) -
                    eyeZ * (mtxF->m[2][2] = lookAtZ * normalizeFactor);

    normalX = (upY * lookAtZ) - (upZ * lookAtY);
    normalY = (upZ * lookAtX) - (upX * lookAtZ);
    normalZ = (upX * lookAtY) - (upY * lookAtX);

    normalizeFactor = SQ(normalX) + SQ(normalY) + SQ(normalZ);
    if (normalizeFactor <= 0.0f) {
        return;
    }

    normalizeFactor = 1.0f / sqrtf(normalizeFactor);
    mtxF->m[3][0] = -eyeX * (mtxF->m[0][0] = normalX * normalizeFactor) -
                    eyeY * (mtxF->m[1][0] = normalY * normalizeFactor) -
                    eyeZ * (mtxF->m[2][0] = normalZ * normalizeFactor);

    trueUpX = (lookAtY * normalZ) - (lookAtZ * normalY);
    trueUpY = (lookAtZ * normalX) - (lookAtX * normalZ);
    trueUpZ = (lookAtX * normalY) - (lookAtY * normalX);

    normalizeFactor = SQ(trueUpX) + SQ(trueUpY) + SQ(trueUpZ);
    if (normalizeFactor <= 0.0f) {
        return;
    }

    normalizeFactor = 1.0f / sqrtf(normalizeFactor);
    mtxF->m[3][1] = -eyeX * (mtxF->m[0][1] = trueUpX * normalizeFactor) -
                    eyeY * (mtxF->m[1][1] = trueUpY * normalizeFactor) -
                    eyeZ * (mtxF->m[2][1] = trueUpZ * normalizeFactor);

    mtxF->m[0][3] = 0.0f;
    mtxF->m[1][3] = 0.0f;
    mtxF->m[2][3] = 0.0f;
    mtxF->m[3][3] = 1.0f;
    Matrix_ToMtx(mtxF, mtx);
}

void Matrix_SetFrustrum(Mtx* mtx, MtxF* mtxF, f32 fovAngle, f32 near, f32 far, f32 fovScaleX, f32 frustumCenterX,
                        f32 fovScaleY, f32 frustumCenterY, u16* perspectiveScale) {
    s32 halfAngle;
    f32 frustrumRadius;
    s32 pad;
    f32 left;
    f32 right;
    f32 top;
    f32 bottom;

    if (mtx == NULL) {
        mtx = &sDefaultMtx;
    }
    if (mtxF == NULL) {
        mtxF = &sDefaultMtxF;
    }

    halfAngle = Math_Round(fovAngle * ((0x1000 / 360.0f) / 2));
    frustrumRadius = TAN(halfAngle) * near;
    frustumCenterX *= (2.0f * frustrumRadius) / fovScaleX;

    right = frustumCenterX + frustrumRadius;
    left = frustumCenterX - frustrumRadius;

    halfAngle = Math_Round(fovAngle * ((0x1000 / 360.0f) / 2));

    frustrumRadius *= fovScaleY / fovScaleX;
    frustumCenterY *= (2.0f * frustrumRadius) / fovScaleY;

    top = frustumCenterY + frustrumRadius;
    bottom = frustumCenterY - frustrumRadius;

    mtxF->m[0][0] = 2.0f * near * (1.0f / (right - left));
    mtxF->m[2][0] = (right + left) * (1.0f / (right - left));

    // Unused
    frustrumRadius *= fovScaleY / fovScaleX;

    mtxF->m[1][1] = 2.0f * near * (1.0f / (top - bottom));
    mtxF->m[2][1] = (top + bottom) * (1.0f / (top - bottom));

    mtxF->m[3][2] = 2.0f * near * far * (1.0f / (near - far));
    mtxF->m[2][2] = (near + far) * (1.0f / (near - far));

    if ((near + far) > 2.0f) {
        u16 scale;

        *perspectiveScale = scale = 0x20000 / (near + far);
        if (scale == 0) {
            *perspectiveScale = 1;
        }
    } else {
        *perspectiveScale = -1;
    }

    mtxF->m[0][1] = mtxF->m[0][2] = mtxF->m[0][3] = mtxF->m[1][0] = mtxF->m[1][2] = mtxF->m[1][3] = mtxF->m[3][0] =
        mtxF->m[3][1] = mtxF->m[3][3] = 0.0f;
    mtxF->m[2][3] = -1.0f;
    Matrix_ToMtx(mtxF, mtx);
}

void Matrix_SetOrtho(Mtx* mtx, MtxF* mtxF, f32 scale, f32 left, f32 right, f32 top, f32 bottom, f32 near, f32 far) {
    f32 verticalFactor;
    f32 depthFactor;
    f32 horizontalFactor;

    if (mtx == NULL) {
        mtx = &sDefaultMtx;
    }
    if (mtxF == NULL) {
        mtxF = &sDefaultMtxF;
    }

    horizontalFactor = scale / (left - right);
    mtxF->m[0][0] = horizontalFactor * -2.0f;
    mtxF->m[3][0] = (right + left) * horizontalFactor;

    verticalFactor = scale / (top - bottom);
    mtxF->m[1][1] = verticalFactor * -2.0f;
    mtxF->m[3][1] = (bottom + top) * verticalFactor;

    depthFactor = scale / (near - far);
    mtxF->m[2][2] = 2.0f * depthFactor;
    mtxF->m[3][2] = (far + near) * depthFactor;

    mtxF->m[3][3] = scale;
    mtxF->m[0][1] = mtxF->m[0][2] = mtxF->m[0][3] = mtxF->m[1][0] = mtxF->m[1][2] = mtxF->m[1][3] = mtxF->m[2][0] =
        mtxF->m[2][1] = mtxF->m[2][3] = 0.0f;
    Matrix_ToMtx(mtxF, mtx);
}
