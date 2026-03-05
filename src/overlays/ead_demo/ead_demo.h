#ifndef OVL_EAD_DEMO_H
#define OVL_EAD_DEMO_H

#include "libultra/ultra64.h"
#include "fzx_math.h"
#include "sys.h"

typedef struct EADDemoLimb {
    /* 0x00 */ Gfx* dl;
    /* 0x04 */ Vec3f scale;
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ Vec3s rot;
    /* 0x24 */ struct EADDemoLimb* nextLimb;
    /* 0x28 */ struct EADDemoLimb* childLimb;
    /* 0x2C */ struct EADDemoLimb* associatedLimb;
    /* 0x30 */ Gfx* associatedLimbDL;
    /* 0x34 */ s16 limbId;
} EADDemoLimb; // size = 0x36

typedef struct EADDemoAnimationInfo {
    /* 0x00 */ s16 frameCount;
    /* 0x02 */ s16 limbCount;
    /* 0x04 */ f32* scaleData;
    /* 0x08 */ s32* scaleInfo;
    /* 0x0C */ s16* rotationData;
    /* 0x10 */ s32* rotationInfo;
    /* 0x14 */ s16* positionData;
    /* 0x18 */ s32* positionInfo;
} EADDemoAnimationInfo; // size = 0x1C

void EADDemo_SinTableInit(void);
Gfx* EADDemo_DrawBackground(Gfx* gfx, FrameBuffer* fb, s32 topR, s32 topG, s32 topB, s32 bottomR, s32 bottomG, s32 bottomB);
void EADDemo_DrawEADSkeleton(Gfx** gfxP);

#endif // OVL_EAD_DEMO_H
