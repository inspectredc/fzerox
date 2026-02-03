#include "global.h"

bool D_800CD510 = false;
s32 gSkyboxType;
s32 gVenueType;
RaceStats gCupRaceStats[1][6];

void func_8007F4E0(s32 venue, s32 skybox) {
    D_800CD510 = true;
    gVenueType = venue;
    gSkyboxType = skybox;
}

s8 gRecordNameEntered[4];
s16 gForceCredits;

void func_8007F500(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gRecordNameEntered[i] = 0;
    }

    gForceCredits = false;
}

#ifdef EXPANSION_KIT
Gfx D_8076CE28[] = {
    gsSPClipRatio(FRUSTRATIO_2),
    gsSPMatrix(0x02000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetDepthImage(0x003DBC00),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x003DBC00),
    gsDPSetFillColor(0xFFFCFFFC),
    gsDPSetScissor(G_SC_NON_INTERLACE, 12, 8, 308, 232),
    gsDPFillRectangle(12, 8, 307, 231),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPEndDisplayList(),
};

Gfx D_8076CF10[] = {
    gsSPClipRatio(FRUSTRATIO_2),
    gsSPMatrix(0x02000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetDepthImage(0x003DBC00),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x003DBC00),
    gsDPSetFillColor(0xFFFCFFFC),
    gsDPSetScissor(G_SC_NON_INTERLACE, 12, 16, 308, 224),
    gsDPFillRectangle(12, 16, 307, 223),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPEndDisplayList(),
};
#endif
