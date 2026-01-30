#include "global.h"
#include "ead_demo.h"
#include "assets/overlays/ead_demo/ead_demo_assets.h"

f32 sEADDemoSinTable[0x1400];
f32* sEADDemoCosTable;
Gfx* sEADDemoDisplayList;
UNUSED s32 D_xk4_800F6AE8;
UNUSED s32 D_xk4_800F6AEC;
s32 D_xk4_800F6AF0[16];
s16 sLimbsProcessed;
s32* sLimbAnimScaleInfo;
s32* sLimbAnimRotationInfo;
s32* sLimbAnimPositionInfo;
f32* sLimbAnimScaleData;
s16* sLimbAnimRotationData;
s16* sLimbAnimPositionData;
Mtx* sEADDemoMatrix;
UNUSED s32 D_xk4_800F6B50;

// clang-format off
UNUSED Mtx sEADDemoClearMtx = gdSPDefMtx(
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
);
// clang-format on

#include "src/assets/overlays/ead_demo/ead_demo_assets/ead_demo_assets.c"

f32 EADDemo_CalculateSinTableValue(f32 input) {
    s32 i;
    f64 x = input;
    f64 numerator = -x * x * x;
    f64 minusSquareX = -x * x;
    f64 denominator = 1 * 2 * 3; // 3!
    f64 term;

    for (i = 2; i < 14; i++) {
        term = numerator / denominator;
        numerator *= minusSquareX;
        denominator *= i * ((i << 2) + 2);
        x += term;
    }
    return x;
}

void EADDemo_SinTableInit(void) {
    s32 i;

    for (i = 0; i < 0x1400; i++) {
        sEADDemoSinTable[i] = EADDemo_CalculateSinTableValue(2.0f * (((f32) i / 0x1000) * 3.1415927f));
    }
    sEADDemoCosTable = &sEADDemoSinTable[0x400];
}

void EADDemo_MatrixToMtxTranspose(Mtx* dest, MtxF* src) {
    s32 temp_ft2;

    temp_ft2 = src->m[3][3] * 65536.0f;
    dest->u.i[3][3] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[3][3] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[3][2] * 65536.0f;
    dest->u.i[2][3] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[2][3] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[3][1] * 65536.0f;
    dest->u.i[1][3] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[1][3] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[3][0] * 65536.0f;
    dest->u.i[0][3] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[0][3] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[2][3] * 65536.0f;
    dest->u.i[3][2] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[3][2] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[2][2] * 65536.0f;
    dest->u.i[2][2] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[2][2] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[2][1] * 65536.0f;
    dest->u.i[1][2] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[1][2] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[2][0] * 65536.0f;
    dest->u.i[0][2] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[0][2] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[1][3] * 65536.0f;
    dest->u.i[3][1] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[3][1] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[1][2] * 65536.0f;
    dest->u.i[2][1] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[2][1] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[1][1] * 65536.0f;
    dest->u.i[1][1] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[1][1] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[1][0] * 65536.0f;
    dest->u.i[0][1] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[0][1] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[0][3] * 65536.0f;
    dest->u.i[3][0] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[3][0] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[0][2] * 65536.0f;
    dest->u.i[2][0] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[2][0] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[0][1] * 65536.0f;
    dest->u.i[1][0] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[1][0] = temp_ft2 & 0xFFFF;
    temp_ft2 = src->m[0][0] * 65536.0f;
    dest->u.i[0][0] = ((u32) temp_ft2 >> 0x10);
    dest->u.f[0][0] = temp_ft2 & 0xFFFF;
}

void EADDemo_AffineMatrixMultiply(MtxF* dest, MtxF* mtxFA, MtxF* mtxFB) {
    dest->m[0][0] =
        (mtxFA->m[0][0] * mtxFB->m[0][0]) + (mtxFA->m[0][1] * mtxFB->m[1][0]) + (mtxFA->m[0][2] * mtxFB->m[2][0]);
    dest->m[0][1] =
        (mtxFA->m[0][0] * mtxFB->m[0][1]) + (mtxFA->m[0][1] * mtxFB->m[1][1]) + (mtxFA->m[0][2] * mtxFB->m[2][1]);
    dest->m[0][2] =
        (mtxFA->m[0][0] * mtxFB->m[0][2]) + (mtxFA->m[0][1] * mtxFB->m[1][2]) + (mtxFA->m[0][2] * mtxFB->m[2][2]);
    dest->m[0][3] = (mtxFA->m[0][0] * mtxFB->m[0][3]) + (mtxFA->m[0][1] * mtxFB->m[1][3]) +
                    (mtxFA->m[0][2] * mtxFB->m[2][3]) + mtxFA->m[0][3];
    dest->m[1][0] =
        (mtxFA->m[1][0] * mtxFB->m[0][0]) + (mtxFA->m[1][1] * mtxFB->m[1][0]) + (mtxFA->m[1][2] * mtxFB->m[2][0]);
    dest->m[1][1] =
        (mtxFA->m[1][0] * mtxFB->m[0][1]) + (mtxFA->m[1][1] * mtxFB->m[1][1]) + (mtxFA->m[1][2] * mtxFB->m[2][1]);
    dest->m[1][2] =
        (mtxFA->m[1][0] * mtxFB->m[0][2]) + (mtxFA->m[1][1] * mtxFB->m[1][2]) + (mtxFA->m[1][2] * mtxFB->m[2][2]);
    dest->m[1][3] = (mtxFA->m[1][0] * mtxFB->m[0][3]) + (mtxFA->m[1][1] * mtxFB->m[1][3]) +
                    (mtxFA->m[1][2] * mtxFB->m[2][3]) + mtxFA->m[1][3];
    dest->m[2][0] =
        (mtxFA->m[2][0] * mtxFB->m[0][0]) + (mtxFA->m[2][1] * mtxFB->m[1][0]) + (mtxFA->m[2][2] * mtxFB->m[2][0]);
    dest->m[2][1] =
        (mtxFA->m[2][0] * mtxFB->m[0][1]) + (mtxFA->m[2][1] * mtxFB->m[1][1]) + (mtxFA->m[2][2] * mtxFB->m[2][1]);
    dest->m[2][2] =
        (mtxFA->m[2][0] * mtxFB->m[0][2]) + (mtxFA->m[2][1] * mtxFB->m[1][2]) + (mtxFA->m[2][2] * mtxFB->m[2][2]);
    dest->m[2][3] = (mtxFA->m[2][0] * mtxFB->m[0][3]) + (mtxFA->m[2][1] * mtxFB->m[1][3]) +
                    (mtxFA->m[2][2] * mtxFB->m[2][3]) + mtxFA->m[2][3];
    dest->m[3][0] = 0.0f;
    dest->m[3][1] = 0.0f;
    dest->m[3][2] = 0.0f;
    dest->m[3][3] = 1.0f;
}

void EADDemo_SetIdentityMatrix(MtxF* mtxF) {
    mtxF->m[0][0] = mtxF->m[1][1] = mtxF->m[2][2] = mtxF->m[3][3] = 1.0f;
    mtxF->m[0][1] = mtxF->m[0][2] = mtxF->m[0][3] = mtxF->m[1][0] = mtxF->m[1][2] = mtxF->m[1][3] = mtxF->m[2][0] =
        mtxF->m[2][1] = mtxF->m[2][3] = mtxF->m[3][0] = mtxF->m[3][1] = mtxF->m[3][2] = 0.0f;
}

void EADDemo_SetScalarMatrix(MtxF* mtxF, f32 xScale, f32 yScale, f32 zScale) {
    mtxF->m[0][0] = xScale;
    mtxF->m[1][1] = yScale;
    mtxF->m[2][2] = zScale;
    mtxF->m[0][1] = 0.0f;
    mtxF->m[0][2] = 0.0f;
    mtxF->m[1][0] = 0.0f;
    mtxF->m[1][2] = 0.0f;
    mtxF->m[2][0] = 0.0f;
    mtxF->m[2][1] = 0.0f;
    mtxF->m[3][0] = 0.0f;
    mtxF->m[3][1] = 0.0f;
    mtxF->m[3][2] = 0.0f;
    mtxF->m[0][3] = 0.0f;
    mtxF->m[1][3] = 0.0f;
    mtxF->m[2][3] = 0.0f;
    mtxF->m[3][3] = 1.0f;
}

s32 func_xk4_800D7504(s32 index, s32 value) {
    D_xk4_800F6AF0[index] = value;
    return value;
}

s32 func_xk4_800D751C(s32 index) {
    return D_xk4_800F6AF0[index];
}

Gfx* EADDemo_DrawBackground(Gfx* gfx, FrameBuffer* fb, s32 topR, s32 topG, s32 topB, s32 bottomR, s32 bottomG,
                            s32 bottomB) {
    s32 color;
    s32 i;
    s32 r;
    s32 g;
    s32 b;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(fb));
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    for (i = 8; i < 232; i++) {
        gDPPipeSync(gfx++);
        r = ((topR * (239 - i)) / 239) + ((bottomR * i) / 239);
        g = ((topG * (239 - i)) / 239) + ((bottomG * i) / 239);
        b = ((topB * (239 - i)) / 239) + ((bottomB * i) / 239);
        gDPSetFillColor(gfx++, GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1));
        gDPFillRectangle(gfx++, 12, i, 307, i);
    }
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);

    return gfx;
}

extern uintptr_t gSegments[];

intptr_t EADDemo_SegmentedToVirtual(uintptr_t segmentedAddr) {
    return OS_PHYSICAL_TO_K0(gSegments[SEGMENT_NUMBER(segmentedAddr)] + SEGMENT_OFFSET(segmentedAddr));
}

typedef struct unk_800D7894 {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0x4];
    s16** unk_0C;
} unk_800D7894;

void func_xk4_800D7894(unk_800D7894* arg0, s32 arg1) {
    s32 sp1C;
    s16** temp;
    s16 temp_a0;

    sp1C = arg0->unk_00;
    temp = (s16**) EADDemo_SegmentedToVirtual(arg0->unk_0C);
    temp_a0 = *(s16*) EADDemo_SegmentedToVirtual(temp[sp1C]);

    arg0->unk_04 += arg1;
    if (arg0->unk_04 >= temp_a0) {
        arg0->unk_04 -= temp_a0;
    } else if (arg0->unk_04 < 0) {
        arg0->unk_04 += temp_a0;
    }
}

void EADDemo_SetTransRotMatrix(MtxF* mtxF, s16 xRot, s16 yRot, s16 zRot, f32 xPos, f32 yPos, f32 zPos) {
    f32 xSin;
    f32 xCos;
    f32 ySin;
    f32 yCos;
    f32 zSin;
    f32 zCos;
    s32 angle;
    s32 pad;

    angle = (xRot * 0x1000) >> 0x10;
    if (angle < 0) {
        angle += 0x1000;
    }
    xSin = sEADDemoSinTable[angle];
    xCos = sEADDemoCosTable[angle];

    angle = (yRot * 0x1000) >> 0x10;
    if (angle < 0) {
        angle += 0x1000;
    }
    ySin = sEADDemoSinTable[angle];
    yCos = sEADDemoCosTable[angle];

    angle = (zRot * 0x1000) >> 0x10;
    if (angle < 0) {
        angle += 0x1000;
    }
    zSin = sEADDemoSinTable[angle];
    zCos = sEADDemoCosTable[angle];

    mtxF->m[0][0] = yCos * zCos;
    mtxF->m[1][0] = yCos * zSin;
    mtxF->m[2][0] = -ySin;
    mtxF->m[0][1] = (xSin * ySin * zCos) - (xCos * zSin);
    mtxF->m[1][1] = (xSin * ySin * zSin) + (xCos * zCos);
    mtxF->m[2][1] = xSin * yCos;
    mtxF->m[0][2] = (xCos * ySin * zCos) + (xSin * zSin);
    mtxF->m[1][2] = (xCos * ySin * zSin) - (xSin * zCos);
    mtxF->m[2][2] = xCos * yCos;
    mtxF->m[0][3] = xPos;
    mtxF->m[1][3] = yPos;
    mtxF->m[2][3] = zPos;
    mtxF->m[3][0] = 0.0f;
    mtxF->m[3][1] = 0.0f;
    mtxF->m[3][2] = 0.0f;
    mtxF->m[3][3] = 1.0f;
}

void func_xk4_800D7AAC(void) {
}

void EADDemo_CalculateLimbInfoOnAnimFrame(EADDemoLimb* limb, s32 animFrame) {
    s32 xDataOffset;
    s32 yFrameCount;
    s32 yDataOffset;
    s32 zFrameCount;
    s32 zDataOffset;
    s32 xFrameCount;
    s32* scanPtr;

    scanPtr = &sLimbAnimScaleInfo[sLimbsProcessed * 6];
    xFrameCount = *scanPtr++;
    xDataOffset = *scanPtr++;
    yFrameCount = *scanPtr++;
    yDataOffset = *scanPtr++;
    zFrameCount = *scanPtr++;
    zDataOffset = *scanPtr++;

    if (animFrame < xFrameCount) {
        limb->scale.x = sLimbAnimScaleData[xDataOffset + animFrame];
    } else {
        limb->scale.x = sLimbAnimScaleData[xDataOffset + xFrameCount - 1];
    }
    if (animFrame < yFrameCount) {
        limb->scale.y = sLimbAnimScaleData[yDataOffset + animFrame];
    } else {
        limb->scale.y = sLimbAnimScaleData[yDataOffset + yFrameCount - 1];
    }
    if (animFrame < zFrameCount) {
        limb->scale.z = sLimbAnimScaleData[zDataOffset + animFrame];
    } else {
        limb->scale.z = sLimbAnimScaleData[zDataOffset + zFrameCount - 1];
    }
    scanPtr = &sLimbAnimRotationInfo[sLimbsProcessed * 6];
    xFrameCount = *scanPtr++;
    xDataOffset = *scanPtr++;
    yFrameCount = *scanPtr++;
    yDataOffset = *scanPtr++;
    zFrameCount = *scanPtr++;
    zDataOffset = *scanPtr++;

    if (animFrame < xFrameCount) {
        limb->rot.x = sLimbAnimRotationData[xDataOffset + animFrame];
    } else {
        limb->rot.x = sLimbAnimRotationData[xDataOffset + xFrameCount - 1];
    }
    if (animFrame < yFrameCount) {
        limb->rot.y = sLimbAnimRotationData[yDataOffset + animFrame];
    } else {
        limb->rot.y = sLimbAnimRotationData[yDataOffset + yFrameCount - 1];
    }
    if (animFrame < zFrameCount) {
        limb->rot.z = sLimbAnimRotationData[zDataOffset + animFrame];
    } else {
        limb->rot.z = sLimbAnimRotationData[zDataOffset + zFrameCount - 1];
    }
    scanPtr = &sLimbAnimPositionInfo[sLimbsProcessed * 6];
    xFrameCount = *scanPtr++;
    xDataOffset = *scanPtr++;
    yFrameCount = *scanPtr++;
    yDataOffset = *scanPtr++;
    zFrameCount = *scanPtr++;
    zDataOffset = *scanPtr++;

    if (animFrame < xFrameCount) {
        limb->pos.x = sLimbAnimPositionData[xDataOffset + animFrame];
    } else {
        limb->pos.x = sLimbAnimPositionData[xDataOffset + xFrameCount - 1];
    }
    if (animFrame < yFrameCount) {
        limb->pos.y = sLimbAnimPositionData[yDataOffset + animFrame];
    } else {
        limb->pos.y = sLimbAnimPositionData[yDataOffset + yFrameCount - 1];
    }
    if (animFrame < zFrameCount) {
        limb->pos.z = sLimbAnimPositionData[zDataOffset + animFrame];
    } else {
        limb->pos.z = sLimbAnimPositionData[zDataOffset + zFrameCount - 1];
    }
}

void func_xk4_800D7E58(void) {
}

void func_xk4_800D7E60(void) {
}

void EADDemo_CalculateSkeletonDraw(EADDemoLimb* segmentedLimb, MtxF* baseMatrix, Vec3f* skeletonScaleVec,
                                   s32 animFrame) {
    EADDemoLimb* limb;
    MtxF workMatrix1;
    MtxF workMatrix2;
    MtxF workMatrix3;
    s32 limbId;
    Vec3f limbScaleVec;

    while (segmentedLimb != 0) {
        limb = (EADDemoLimb*) EADDemo_SegmentedToVirtual(segmentedLimb);
        if ((limb->associatedLimb != NULL) && (limb->associatedLimbDL != NULL)) {
            limbId = ((EADDemoLimb*) EADDemo_SegmentedToVirtual(limb->associatedLimb))->limbId;

            gSPMatrix(sEADDemoDisplayList++, &sEADDemoMatrix[limbId], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            gSPDisplayList(sEADDemoDisplayList++, limb->associatedLimbDL);
            gSPPopMatrix(sEADDemoDisplayList++, G_MTX_MODELVIEW);
        }
        limbId = limb->limbId;
        EADDemo_CalculateLimbInfoOnAnimFrame(limb, animFrame);
        EADDemo_SetTransRotMatrix(&workMatrix1, limb->rot.x, limb->rot.y, limb->rot.z,
                                  limb->pos.x * skeletonScaleVec->x, limb->pos.y * skeletonScaleVec->y,
                                  limb->pos.z * skeletonScaleVec->z);
        limbScaleVec.x = skeletonScaleVec->x * limb->scale.x;
        limbScaleVec.y = skeletonScaleVec->y * limb->scale.y;
        limbScaleVec.z = skeletonScaleVec->z * limb->scale.z;
        EADDemo_AffineMatrixMultiply(&workMatrix2, baseMatrix, &workMatrix1);
        EADDemo_SetScalarMatrix(&workMatrix3, limbScaleVec.x, limbScaleVec.y, limbScaleVec.z);
        EADDemo_AffineMatrixMultiply(&workMatrix1, &workMatrix2, &workMatrix3);

        EADDemo_MatrixToMtxTranspose(&sEADDemoMatrix[limbId], &workMatrix1);
        gSPMatrix(sEADDemoDisplayList++, &sEADDemoMatrix[limbId], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        if (limb->dl != NULL) {
            gSPDisplayList(sEADDemoDisplayList++, limb->dl);
        }

        gSPPopMatrix(sEADDemoDisplayList++, G_MTX_MODELVIEW);
        sLimbsProcessed++;
        segmentedLimb = limb->childLimb;
        if (segmentedLimb != 0) {
            EADDemo_CalculateSkeletonDraw(segmentedLimb, &workMatrix2, &limbScaleVec, animFrame);
        }
        segmentedLimb = limb->nextLimb;
    }
}

extern GfxPool* gGfxPool;

UNUSED s32 D_xk4_800F1A78 = 0;
Vec3f sSkeletonScaleVec = { 1.0f, 1.0f, 1.0f };

void EADDemo_SetupSkeleton(EADDemoLimb** segmentedSkeleton, EADDemoAnimationInfo* segmentedAnimInfo, s32 animFrame) {
    EADDemoAnimationInfo* animInfo;
    EADDemoLimb** skeleton;
    MtxF identityMtxF;
    Vec3f scaleVec;

    animInfo = EADDemo_SegmentedToVirtual(segmentedAnimInfo);
    skeleton = EADDemo_SegmentedToVirtual(segmentedSkeleton);
    scaleVec = sSkeletonScaleVec;
    sLimbsProcessed = 0;
    sLimbAnimScaleInfo = EADDemo_SegmentedToVirtual(animInfo->scaleInfo);
    sLimbAnimRotationInfo = EADDemo_SegmentedToVirtual(animInfo->rotationInfo);
    sLimbAnimPositionInfo = EADDemo_SegmentedToVirtual(animInfo->positionInfo);
    sLimbAnimScaleData = EADDemo_SegmentedToVirtual(animInfo->scaleData);
    sLimbAnimRotationData = EADDemo_SegmentedToVirtual(animInfo->rotationData);
    sLimbAnimPositionData = EADDemo_SegmentedToVirtual(animInfo->positionData);

    // UB! Reuses machine matrix, overlapping into next section of gfxPool matrices
    sEADDemoMatrix = gGfxPool->unk_20308;
    EADDemo_SetIdentityMatrix(&identityMtxF);
    EADDemo_CalculateSkeletonDraw(*skeleton, &identityMtxF, &scaleVec, animFrame);
}

void EADDemo_DrawEADSkeleton(Gfx** gfxP) {
    static s32 sAnimFrame = 0;

    sEADDemoDisplayList = *gfxP;
    sAnimFrame = (sAnimFrame + 1) % 40;

    EADDemo_SetupSkeleton(aEADDemoSkeleton, &aEADDemoAnimationInfo, sAnimFrame);
    *gfxP = sEADDemoDisplayList;
}
