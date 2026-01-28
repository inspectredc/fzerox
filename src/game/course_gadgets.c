#include "global.h"
#include "fzx_racer.h"
#include "fzx_thread.h"
#include "fzx_course.h"
#include "segment_symbols.h"
#include "leo/mfs.h"
#include "assets/course_track_gfx.h"
#include "assets/setup_gfx.h"

OSMesg D_800E12B0;
UNUSED s8 D_800E12B8[0x10];
s32 D_800E12C8[0x800];
s32 sCourseDecorationTextureLoadState;
s32 D_800E32CC;
Vtx* sTerrainEffectVtxStart;

bool gInCourseEditor = false;

Gfx* (*sCourseDecorationDrawFuncs[])(Gfx*) = {
    Course_FeatureDrawGateSquare,       // COURSE_FEATURE_GATE_SQUARE
    Course_FeatureDrawGateStart,        // COURSE_FEATURE_GATE_START
    Course_FeatureDrawGateHexagonal,    // COURSE_FEATURE_GATE_HEXAGONAL
    Course_FeatureDrawSignTV,           // COURSE_FEATURE_SIGN_TV_RIGHT
    Course_FeatureDrawSignTV,           // COURSE_FEATURE_SIGN_TV_LEFT
    Course_FeatureDrawSign2,            // COURSE_FEATURE_SIGN_2_RIGHT
    Course_FeatureDrawSign2,            // COURSE_FEATURE_SIGN_2_LEFT
    Course_FeatureDrawSign1,            // COURSE_FEATURE_SIGN_1_RIGHT
    Course_FeatureDrawSign1,            // COURSE_FEATURE_SIGN_1_LEFT
    Course_FeatureDrawSignNinTexRight,  // COURSE_FEATURE_SIGN_NINTEX_RIGHT
    Course_FeatureDrawSignNinTexLeft,   // COURSE_FEATURE_SIGN_NINTEX_LEFT
    Course_FeatureDrawSignOverhead,     // COURSE_FEATURE_SIGN_OVERHEAD
    Course_FeatureDrawBuildingTall,     // COURSE_FEATURE_BUILDING_TALL_LEFT
    Course_FeatureDrawBuildingTall,     // COURSE_FEATURE_BUILDING_TALL_RIGHT
    Course_FeatureDrawBuildingShort,    // COURSE_FEATURE_BUILDING_SHORT_LEFT
    Course_FeatureDrawBuildingShort,    // COURSE_FEATURE_BUILDING_SHORT_RIGHT
    Course_FeatureDrawBuildingSpire,    // COURSE_FEATURE_BUILDING_SPIRE_LEFT
    Course_FeatureDrawBuildingSpire,    // COURSE_FEATURE_BUILDING_SPIRE_RIGHT
    Course_FeatureDrawBuildingMountain, // COURSE_FEATURE_BUILDING_MOUNTAIN_LEFT
    Course_FeatureDrawBuildingMountain, // COURSE_FEATURE_BUILDING_MOUNTAIN_RIGHT
    Course_FeatureDrawBuildingTallGold, // COURSE_FEATURE_BUILDING_TALL_GOLD_LEFT
    Course_FeatureDrawBuildingTallGold, // COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT
};

bool Course_FeatureIsDecorational(s32 courseFeature) {
    if ((courseFeature >= COURSE_FEATURE_GATE_SQUARE) && (courseFeature <= COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT)) {
        return true;
    }
    return false;
}

extern Landmine gLandmines[48];

void func_8006D414(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gLandmines); i++) {
        gLandmines[i].unk_00 = 1;
    }
}

extern unk_80225800 D_80225800;
extern Jump gJumps[];
extern CourseInfo* gCurrentCourseInfo;
extern CourseFeaturesInfo gCourseFeaturesInfo;

void Course_LandminesViewInteractDataInit(void) {
    CourseFeature* feature;
    s32 i;
    s32 j;
    s32 k;
    f32 lengthFromStart;
    Vtx* vtx;
    CourseSegment* segment;
    CourseFeaturesInfo* courseFeaturesInfo = &gCourseFeaturesInfo;
    f32 lengthProportionAlongSegment;
    Vec3f pos;
    Mtx3F segmentBasis;

    if (gInCourseEditor) {
        //! @bug vtx uninitialised
    } else {
        vtx = D_80225800.landmineVtx;
    }

    courseFeaturesInfo->landmineCount = 0;

    for (i = 0; i < courseFeaturesInfo->featureCount; i++) {
        feature = &courseFeaturesInfo->features[i];
        if (feature->featureType != COURSE_FEATURE_LANDMINE) {
            continue;
        }

        segment = &gCurrentCourseInfo->courseSegments[feature->segmentIndex];
        lengthProportionAlongSegment = Course_SplineGetLengthInfo(segment, feature->segmentTValue, &lengthFromStart);
        Course_SplineGetBasis(segment, feature->segmentTValue, &segmentBasis, lengthProportionAlongSegment);
        Course_SplineGetPosition(segment, feature->segmentTValue, &pos);

        pos.x += (feature->lateralOffset * segmentBasis.z.x) + (2 * segmentBasis.y.x);
        pos.y += (feature->lateralOffset * segmentBasis.z.y) + (2 * segmentBasis.y.y);
        pos.z += (feature->lateralOffset * segmentBasis.z.z) + (2 * segmentBasis.y.z);

        vtx->v.ob[0] = pos.x + 16.0f * segmentBasis.y.x;
        vtx->v.ob[1] = pos.y + 16.0f * segmentBasis.y.y;
        vtx->v.ob[2] = pos.z + 16.0f * segmentBasis.y.z;
        vtx->v.tc[0] = 0x400;
        vtx->v.tc[1] = 0;
        vtx++;
        vtx->v.ob[0] = pos.x - (16.0f * 1.1547f) * segmentBasis.x.x;
        vtx->v.ob[1] = pos.y - (16.0f * 1.1547f) * segmentBasis.x.y;
        vtx->v.ob[2] = pos.z - (16.0f * 1.1547f) * segmentBasis.x.z;
        vtx->v.tc[0] = 0;
        vtx->v.tc[1] = 0x800;
        vtx++;
        vtx->v.ob[0] = pos.x - (16.0f * 1.1547f) * segmentBasis.z.x;
        vtx->v.ob[1] = pos.y - (16.0f * 1.1547f) * segmentBasis.z.y;
        vtx->v.ob[2] = pos.z - (16.0f * 1.1547f) * segmentBasis.z.z;
        vtx->v.tc[0] = 0x800;
        vtx->v.tc[1] = 0x800;
        vtx++;
        vtx->v.ob[0] = pos.x + (16.0f * 1.1547f) * segmentBasis.x.x;
        vtx->v.ob[1] = pos.y + (16.0f * 1.1547f) * segmentBasis.x.y;
        vtx->v.ob[2] = pos.z + (16.0f * 1.1547f) * segmentBasis.x.z;
        vtx->v.tc[0] = 0;
        vtx->v.tc[1] = 0x800;
        vtx++;
        vtx->v.ob[0] = pos.x + (16.0f * 1.1547f) * segmentBasis.z.x;
        vtx->v.ob[1] = pos.y + (16.0f * 1.1547f) * segmentBasis.z.y;
        vtx->v.ob[2] = pos.z + (16.0f * 1.1547f) * segmentBasis.z.z;
        vtx->v.tc[0] = 0x800;
        vtx->v.tc[1] = 0x800;
        vtx++;
        gLandmines[courseFeaturesInfo->landmineCount].pos.x = pos.x;
        gLandmines[courseFeaturesInfo->landmineCount].pos.y = pos.y;
        gLandmines[courseFeaturesInfo->landmineCount].pos.z = pos.z;
        gLandmines[courseFeaturesInfo->landmineCount].unk_00 = 1;
        courseFeaturesInfo->landmineCount++;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        gCurrentCourseInfo->courseSegments[i].landminesStart = NULL;
        gCurrentCourseInfo->courseSegments[i].landminesEnd = NULL;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = 0, k = 0; k < courseFeaturesInfo->featureCount; k++) {
            feature = &courseFeaturesInfo->features[k];
            if (feature->featureType != COURSE_FEATURE_LANDMINE) {
                continue;
            }

            if (i == feature->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].landminesEnd = &gLandmines[j + 1];
            }
            j++;
        }
    }

    //! @bug j is potentially uninitialised here
    courseFeaturesInfo->landmineCount = j;

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = courseFeaturesInfo->landmineCount, k = courseFeaturesInfo->featureCount - 1; k >= 0; k--) {
            feature = &courseFeaturesInfo->features[k];
            if (feature->featureType != COURSE_FEATURE_LANDMINE) {
                continue;
            }

            if (i == feature->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].landminesStart = &gLandmines[j - 1];
            }
            j--;
        }
    }
}

extern CourseDecoration gCourseDecorations[];
extern SegmentChunk gSegmentChunks[];
extern CourseEffectsInfo gCourseEffectsInfo;
extern EffectDrawData gEffectsDrawData[];
#define VERTEX_MODIFIED_ST(s, t) ((((s) << 15) & 0xFFFF0000) | ((t) &0xFFFF))
#define VERTEX_MODIFIED_ST2(s, t) ((((s) << 16) & 0xFFFF0000) | ((t) &0xFFFF))

// Draw Course Effects and Features
Gfx* Course_GadgetsDraw(Gfx* gfx, s32 arg1) {
    s32 pad[12];
    CourseFeaturesInfo* featuresInfo;
    s32 j;
    s32 k;
    Mtx* decorationMtx;
    Vtx* dashVtx;
    EffectDrawData* effectDrawData;
    EffectDrawData* effectDrawDataEnd;
    s32 totalVtxGroups;
    s32 numVtxs;
    s32 sp1D4;
    s32 remainderVtxGroupNum;
    Vtx* vtx;
    s16* var_t0;
    CourseFeature* feature;
    CourseFeature* featuresEnd;
    CourseDecoration* decoration;
    s32 var_v1;
    s32 temp_v1;
    s32 temp_s3;
    unk_80225800* var_s7;
    CourseEffectsInfo* effectsInfo;
    Vtx* tempVtx;

    gSPDisplayList(gfx++, aSetupLandmineTextureDL);

#ifdef EXPANSION_KIT

#endif

    featuresInfo = &gCourseFeaturesInfo;

    if ((featuresInfo->landmineCount != 0)) {
        if (gInCourseEditor) {
#ifdef EXPANSION_KIT

#endif
        } else {
            vtx = &D_80225800.landmineVtx[(featuresInfo->landmineCount - 1) * 5];
            do {
                gSPVertex(gfx++, vtx, 5, 0);
                gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
                gSP2Triangles(gfx++, 0, 3, 4, 0, 0, 4, 1, 0);
                vtx -= 5;
            } while (vtx >= D_80225800.landmineVtx);
        }
    }
    if (featuresInfo->jumpCount != 0) {
        gDPLoadTextureBlock(gfx++, aJumpFeatureTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        if (gInCourseEditor) {
#ifdef EXPANSION_KIT

#endif
        } else {
            vtx = &D_80225800.jumpVtx[(featuresInfo->jumpCount - 1) * 6];
            do {
                gSPVertex(gfx++, vtx, 6, 0);
                gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 5, 4, 0);
                gSP2Triangles(gfx++, 0, 3, 1, 0, 1, 3, 4, 0);
                gSP2Triangles(gfx++, 0, 5, 3, 0, 0, 2, 5, 0);
                vtx -= 6;
            } while (vtx >= D_80225800.jumpVtx);
        }
    }

    effectsInfo = &gCourseEffectsInfo;

    if (effectsInfo->count != 0) {

        gSPDisplayList(gfx++, aSetupCourseEffectTextureDL);

        if (gInCourseEditor) {
#ifdef EXPANSION_KIT

#endif
        } else {
            effectDrawDataEnd = gEffectsDrawData + effectsInfo->count;
            dashVtx = D_80225800.dashVtx;
            for (effectDrawData = gEffectsDrawData; effectDrawData < effectDrawDataEnd; effectDrawData++) {
                gSPTexture(gfx++, 0x8000, 0x8000, 0, effectDrawData->effectType, G_ON);
                if (effectDrawData->effectType == COURSE_EFFECT_DASH) {
                    gSPVertex(gfx++, dashVtx, 6, 0);
                    gSP2Triangles(gfx++, 0, 4, 1, 0, 0, 3, 4, 0);
                    gSP2Triangles(gfx++, 0, 2, 3, 0, 2, 5, 3, 0);
                    dashVtx += 6;
                    continue;
                }
                numVtxs = effectDrawData->vtxEnd - effectDrawData->vtxStart;
                totalVtxGroups = (numVtxs >> 5) + 1;
                remainderVtxGroupNum = numVtxs & 0x1F;
                if (remainderVtxGroupNum == 0) {
                    remainderVtxGroupNum = 32;
                    totalVtxGroups--;
                }

                vtx = effectDrawData->vtxStart;
                temp_s3 = totalVtxGroups - 1;
                for (j = 0; j < temp_s3; j++) {

                    temp_v1 = (effectDrawData->vtxStart - D_80225800.terrainEffectVtx + (j << 5)) >> 1;
                    gSPVertex(gfx++, vtx, 32, 0);

                    for (k = 0; k < 15; k++) {
                        tempVtx = &vtx[(k << 1)];
                        if (gSegmentChunks[D_800E12C8[k + temp_v1]].drawState == 0) {
                            continue;
                        }
                        if ((tempVtx[2].v.tc[1] < tempVtx[0].v.tc[1]) || (tempVtx[3].v.tc[1] < tempVtx[1].v.tc[1])) {
                            gSPModifyVertex(gfx++, (k << 1), G_MWO_POINT_ST,
                                            VERTEX_MODIFIED_ST(tempVtx[0].v.tc[0], 0x8000));
                            gSPModifyVertex(gfx++, (k << 1) + 1, G_MWO_POINT_ST,
                                            VERTEX_MODIFIED_ST(tempVtx[1].v.tc[0], 0x8000));
                        }
                        gSP2Triangles(gfx++, (k << 1), (k << 1) + 2, (k << 1) + 1, 0, (k << 1) + 1, (k << 1) + 2,
                                      (k << 1) + 3, 0);
                    }
                    vtx += 32;
                }

                temp_v1 = (effectDrawData->vtxStart - D_80225800.terrainEffectVtx + (j << 5)) >> 1;
                gSPVertex(gfx++, effectDrawData->vtxStart + (j << 5), remainderVtxGroupNum, 0);

                temp_s3 = (remainderVtxGroupNum >> 1) - 1;
                for (k = 0; k < temp_s3; k++) {
                    tempVtx = &vtx[(k << 1)];
                    if (gSegmentChunks[D_800E12C8[k + temp_v1]].drawState == 0) {
                        continue;
                    }
                    if ((tempVtx[2].v.tc[1] < tempVtx[0].v.tc[1]) || (tempVtx[3].v.tc[1] < tempVtx[1].v.tc[1])) {
                        tempVtx = &vtx[k * 2];
                        gSPModifyVertex(gfx++, (k << 1), G_MWO_POINT_ST,
                                        VERTEX_MODIFIED_ST2((tempVtx[0].v.tc[0]), 0x8000));
                        tempVtx = &vtx[k * 2];
                        gSPModifyVertex(gfx++, (k << 1) + 1, G_MWO_POINT_ST,
                                        VERTEX_MODIFIED_ST2((tempVtx[1].v.tc[0]), 0x8000));
                    }
                    gSP2Triangles(gfx++, (k << 1), (k << 1) + 2, (k << 1) + 1, 0, (k << 1) + 1, (k << 1) + 2,
                                  (k << 1) + 3, 0);
                }
            }
        }
    }
    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gSPFogPosition(gfx++, 980, 1000);
    gDPPipeSync(gfx++);

    if (COURSE_CONTEXT()->courseData.skybox == SKYBOX_NIGHT) {
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPSetRenderMode(gfx++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
    } else {
        gDPSetCombineMode(gfx++, G_CC_BLENDRGBA, G_CC_BLENDRGBA);
        gDPSetRenderMode(gfx++, Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | FORCE_BL | G_RM_FOG_SHADE_A,
                         Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | FORCE_BL |
                             GBL_c2(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA));
    }

    decoration = gCourseDecorations;
    sCourseDecorationTextureLoadState = -1;
    if (gInCourseEditor) {
#ifdef EXPANSION_KIT

#endif
    } else {
        featuresEnd = featuresInfo->features + featuresInfo->featureCount;
        decorationMtx = D_80225800.decorationMtx;
        for (feature = featuresInfo->features; feature < featuresEnd; feature++) {
            if (!Course_FeatureIsDecorational(feature->featureType)) {
                continue;
            }
            if ((decoration->loadChunk->drawState != 0) && (feature->featureType <= COURSE_FEATURE_SIGN_OVERHEAD)) {
                gSPMatrix(gfx++, K0_TO_PHYS(decorationMtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gfx = sCourseDecorationDrawFuncs[feature->featureType](gfx);
            }
            decorationMtx++;
            decoration++;
        }
        if (COURSE_CONTEXT()->courseData.skybox == SKYBOX_NIGHT) {
            gDPPipeSync(gfx++);
            gDPSetCombineMode(gfx++, G_CC_BLENDRGBA, G_CC_BLENDRGBA);
            gDPSetRenderMode(gfx++,
                             Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | FORCE_BL | G_RM_FOG_SHADE_A,
                             Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | FORCE_BL |
                                 GBL_c2(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA));
        }

        decoration = gCourseDecorations;
        decorationMtx = D_80225800.decorationMtx;
        for (feature = featuresInfo->features; feature < featuresEnd; feature++) {
            if (!Course_FeatureIsDecorational(feature->featureType)) {
                continue;
            }

            if ((decoration->loadChunk->drawState != 0) && COURSE_FEATURE_IS_BUILDING(feature->featureType)) {
                gSPMatrix(gfx++, K0_TO_PHYS(decorationMtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gfx = sCourseDecorationDrawFuncs[feature->featureType](gfx);
            }
            decorationMtx++;
            decoration++;
        }
    }
    return gfx;
}

void Course_JumpsViewInteractDataInit(void) {
    CourseFeaturesInfo* featuresInfo = &gCourseFeaturesInfo;
    s32 i;
    s32 j;
    s32 k;
    f32 lengthFromStart;
    Vtx* vtx;
    s32 pad[3];
    Vec3f pos;
    f32 lengthProportionAlongSegment;
    CourseSegment* segment;
    CourseFeature* feature;
    Mtx3F segmentBasis;

    if (gInCourseEditor) {
        //! @bug vtx uninitialised
    } else {
        vtx = D_80225800.jumpVtx;
    }
    featuresInfo->jumpCount = 0;

    for (i = 0; i < featuresInfo->featureCount; i++) {
        feature = &featuresInfo->features[i];

        if (feature->featureType != COURSE_FEATURE_JUMP) {
            continue;
        }
        segment = &gCurrentCourseInfo->courseSegments[feature->segmentIndex];
        lengthProportionAlongSegment = Course_SplineGetLengthInfo(segment, feature->segmentTValue, &lengthFromStart);
        Course_SplineGetBasis(segment, feature->segmentTValue, &segmentBasis, lengthProportionAlongSegment);
        Course_SplineGetPosition(segment, feature->segmentTValue, &pos);

        pos.x += feature->lateralOffset * segmentBasis.z.x - 0.5 * feature->dimensions.x * segmentBasis.z.x;
        pos.y += feature->lateralOffset * segmentBasis.z.y - 0.5 * feature->dimensions.x * segmentBasis.z.y;
        pos.z += feature->lateralOffset * segmentBasis.z.z - 0.5 * feature->dimensions.x * segmentBasis.z.z;

        gJumps[featuresInfo->jumpCount].pos.x = pos.x;
        gJumps[featuresInfo->jumpCount].pos.y = pos.y;
        gJumps[featuresInfo->jumpCount].pos.z = pos.z;

        vtx->v.ob[0] =
            ((feature->dimensions.y * segmentBasis.y.x) + pos.x) + (0.5 * feature->dimensions.z * segmentBasis.x.x);
        vtx->v.ob[1] =
            ((feature->dimensions.y * segmentBasis.y.y) + pos.y) + (0.5 * feature->dimensions.z * segmentBasis.x.y);
        vtx->v.ob[2] =
            ((feature->dimensions.y * segmentBasis.y.z) + pos.z) + (0.5 * feature->dimensions.z * segmentBasis.x.z);
        vtx->v.tc[0] = 0x400;
        vtx->v.tc[1] = 0x240;
        vtx++;
        vtx->v.ob[0] = pos.x;
        vtx->v.ob[1] = pos.y;
        vtx->v.ob[2] = pos.z;
        vtx->v.tc[0] = 0x400;
        vtx->v.tc[1] = 0x700;
        vtx++;
        vtx->v.ob[0] = ((feature->dimensions.z * segmentBasis.x.x) + pos.x);
        vtx->v.ob[1] = ((feature->dimensions.z * segmentBasis.x.y) + pos.y);
        vtx->v.ob[2] = ((feature->dimensions.z * segmentBasis.x.z) + pos.z);
        vtx->v.tc[0] = 0;
        pos.x += feature->dimensions.x * segmentBasis.z.x;
        pos.y += feature->dimensions.x * segmentBasis.z.y;
        pos.z += feature->dimensions.x * segmentBasis.z.z;

        vtx++;
        vtx->v.ob[0] =
            ((feature->dimensions.y * segmentBasis.y.x) + pos.x) + (0.5 * feature->dimensions.z * segmentBasis.x.x);
        vtx->v.ob[1] =
            ((feature->dimensions.y * segmentBasis.y.y) + pos.y) + (0.5 * feature->dimensions.z * segmentBasis.x.y);
        vtx->v.ob[2] =
            ((feature->dimensions.y * segmentBasis.y.z) + pos.z) + (0.5 * feature->dimensions.z * segmentBasis.x.z);
        vtx->v.tc[0] = 0x400;
        vtx->v.tc[1] = 0x240;
        vtx++;
        vtx->v.ob[0] = pos.x;
        vtx->v.ob[1] = pos.y;
        vtx->v.ob[2] = pos.z;
        vtx->v.tc[0] = 0x400;
        vtx->v.tc[1] = 0x700;
        vtx++;
        vtx->v.ob[0] = (feature->dimensions.z * segmentBasis.x.x) + pos.x;
        vtx->v.ob[1] = (feature->dimensions.z * segmentBasis.x.y) + pos.y;
        vtx->v.ob[2] = (feature->dimensions.z * segmentBasis.x.z) + pos.z;
        vtx->v.tc[0] = 0;
        vtx++;

        gJumps[featuresInfo->jumpCount].basis = segmentBasis;
        gJumps[featuresInfo->jumpCount].dimensions = feature->dimensions;

        featuresInfo->jumpCount++;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        gCurrentCourseInfo->courseSegments[i].jumpsStart = NULL;
        gCurrentCourseInfo->courseSegments[i].jumpsEnd = NULL;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = 0, k = 0; k < featuresInfo->featureCount; k++) {
            feature = &featuresInfo->features[k];
            if (feature->featureType != COURSE_FEATURE_JUMP) {
                continue;
            }

            if (i == feature->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].jumpsEnd = &gJumps[j + 1];
            }
            j++;
        }
    }
    //! @bug j is potentially uninitialised here
    featuresInfo->jumpCount = j;

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = featuresInfo->jumpCount, k = featuresInfo->featureCount - 1; k >= 0; k--) {
            feature = &featuresInfo->features[k];
            if (feature->featureType != COURSE_FEATURE_JUMP) {
                continue;
            }

            if (i == feature->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].jumpsStart = &gJumps[j - 1];
            }
            j--;
        }
    }
}

extern s32 gSegmentChunkCount;

void Course_DecorationsViewInteractDataInit(void) {
    CourseSegment* segment;
    SegmentChunk* chunk;
    CourseDecoration* decoration;
    s32 i;
    f32 lengthFromStart;
    s32 j;
    f32 xDist;
    f32 yDist;
    f32 zDist;
    f32 sqDist;
    s32 pad[2];
    CourseFeaturesInfo* featuresInfo;
    f32 closestDist;
    CourseFeature* feature;
    f32 lengthProportionAlongSegment;
    Mtx* mtx;
    MtxF mtxF;
    Vec3f pos;
    Mtx3F segmentBasis;

    featuresInfo = &gCourseFeaturesInfo;
    if (gInCourseEditor) {
        //! @bug mtx uninitialised
    } else {
        mtx = D_80225800.decorationMtx;
    }

    decoration = gCourseDecorations;
    for (i = 0; i < featuresInfo->featureCount; i++) {
        feature = &featuresInfo->features[i];
        if (!Course_FeatureIsDecorational(feature->featureType)) {
            continue;
        }
        segment = &gCurrentCourseInfo->courseSegments[feature->segmentIndex];

        lengthProportionAlongSegment = Course_SplineGetLengthInfo(segment, feature->segmentTValue, &lengthFromStart);
        Course_SplineGetBasis(segment, feature->segmentTValue, &segmentBasis, lengthProportionAlongSegment);
        Course_SplineGetPosition(segment, feature->segmentTValue, &pos);

        if (COURSE_FEATURE_IS_BUILDING(feature->featureType)) {
            if (SQ(segmentBasis.x.y) > 0.95) {
                if (segmentBasis.y.y > 0) {
                    segmentBasis.x.x = -1.0f * segmentBasis.y.x;
                    segmentBasis.x.y = 0;
                    segmentBasis.x.z = -1.0f * segmentBasis.y.z;
                    Math_NormalizeXZ(&segmentBasis.x.x, &segmentBasis.x.z);
                    segmentBasis.y.x = 0.0f;
                    segmentBasis.y.y = 1.0f;
                    segmentBasis.y.z = 0.0f;
                    segmentBasis.z.x = segmentBasis.x.z;
                    segmentBasis.z.y = 0.0f;
                    segmentBasis.z.z = 0.0f - segmentBasis.x.x;
                } else {
                    segmentBasis.x.x = segmentBasis.y.x;
                    segmentBasis.x.y = 0;
                    segmentBasis.x.z = segmentBasis.y.z;
                    Math_NormalizeXZ(&segmentBasis.x.x, &segmentBasis.x.z);
                    segmentBasis.y.x = 0.0f;
                    segmentBasis.y.y = 1.0f;
                    segmentBasis.y.z = 0.0f;
                    segmentBasis.z.x = segmentBasis.x.z;
                    segmentBasis.z.y = 0.0f;
                    segmentBasis.z.z = 0.0f - segmentBasis.x.x;
                }
            } else {
                segmentBasis.x.y = 0.0f;
                Math_NormalizeXZ(&segmentBasis.x.x, &segmentBasis.x.z);
                segmentBasis.y.x = 0.0f;
                segmentBasis.y.y = 1.0f;
                segmentBasis.y.z = 0.0f;
                segmentBasis.z.x = segmentBasis.x.z;
                segmentBasis.z.y = 0.0f;
                segmentBasis.z.z = 0.0f - segmentBasis.x.x;
            }
        }

        pos.x += feature->lateralOffset * segmentBasis.z.x;
        pos.y += feature->lateralOffset * segmentBasis.z.y;
        pos.z += feature->lateralOffset * segmentBasis.z.z;
        decoration->pos.x = pos.x;
        decoration->pos.y = pos.y;
        decoration->pos.z = pos.z;
        decoration->basis = segmentBasis;

        switch (feature->featureType) {
            case COURSE_FEATURE_GATE_SQUARE:
            case COURSE_FEATURE_GATE_START:
            case COURSE_FEATURE_GATE_HEXAGONAL:
                decoration->scale = (segment->radiusLeft + segment->radiusRight + 165.0f) / 120.0f;
                break;
            case COURSE_FEATURE_SIGN_OVERHEAD:
                decoration->scale = (segment->radiusLeft + segment->radiusRight + 165.0f) / 520.0f;
                break;
            default:
                decoration->scale = 1.0f;
                break;
        }

        switch (feature->featureType) {
            case COURSE_FEATURE_SIGN_TV_LEFT:
            case COURSE_FEATURE_SIGN_2_LEFT:
            case COURSE_FEATURE_SIGN_1_LEFT:
                Matrix_SetLockedLookAt(mtx, &mtxF, decoration->scale, decoration->scale, decoration->scale,
                                       decoration->basis.x.x * -1.0f, decoration->basis.x.y * -1.0f,
                                       decoration->basis.x.z * -1.0f, decoration->basis.y.x, decoration->basis.y.y,
                                       decoration->basis.y.z, decoration->pos.x, decoration->pos.y, decoration->pos.z);
                break;
            case COURSE_FEATURE_SIGN_NINTEX_RIGHT:
                Matrix_SetLockedLookAt(mtx, &mtxF, decoration->scale, decoration->scale, decoration->scale,
                                       decoration->basis.x.x, decoration->basis.x.y, decoration->basis.x.z,
                                       decoration->basis.y.x, decoration->basis.y.y, decoration->basis.y.z,
                                       decoration->pos.x + (decoration->basis.y.x * 50.0f),
                                       decoration->pos.y + (decoration->basis.y.y * 50.0f),
                                       decoration->pos.z + (decoration->basis.y.z * 50.0f));
                break;
            case COURSE_FEATURE_SIGN_OVERHEAD:
                Matrix_SetLockedLookAt(mtx, &mtxF, decoration->scale, decoration->scale, decoration->scale,
                                       decoration->basis.x.x, decoration->basis.x.y, decoration->basis.x.z,
                                       decoration->basis.y.x, decoration->basis.y.y, decoration->basis.y.z,
                                       decoration->pos.x + (decoration->basis.y.x * 100.0f * decoration->scale),
                                       decoration->pos.y + (decoration->basis.y.y * 100.0f * decoration->scale),
                                       decoration->pos.z + (decoration->basis.y.z * 100.0f * decoration->scale));
                break;
            case COURSE_FEATURE_SIGN_NINTEX_LEFT:
                Matrix_SetLockedLookAt(mtx, &mtxF, decoration->scale, decoration->scale, decoration->scale,
                                       decoration->basis.x.x * -1.0f, decoration->basis.x.y * -1.0f,
                                       decoration->basis.x.z * -1.0f, decoration->basis.y.x, decoration->basis.y.y,
                                       decoration->basis.y.z, decoration->pos.x + (decoration->basis.y.x * 50.0f),
                                       decoration->pos.y + (decoration->basis.y.y * 50.0f),
                                       decoration->pos.z + (decoration->basis.y.z * 50.0f));
                break;
            case COURSE_FEATURE_BUILDING_TALL_LEFT:
            case COURSE_FEATURE_BUILDING_TALL_RIGHT:
            case COURSE_FEATURE_BUILDING_SHORT_LEFT:
            case COURSE_FEATURE_BUILDING_SHORT_RIGHT:
            case COURSE_FEATURE_BUILDING_SPIRE_LEFT:
            case COURSE_FEATURE_BUILDING_SPIRE_RIGHT:
            case COURSE_FEATURE_BUILDING_MOUNTAIN_LEFT:
            case COURSE_FEATURE_BUILDING_MOUNTAIN_RIGHT:
            case COURSE_FEATURE_BUILDING_TALL_GOLD_LEFT:
            case COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT:
                Matrix_SetLockedLookAt(mtx, &mtxF, decoration->scale, decoration->scale, decoration->scale,
                                       decoration->basis.x.x, decoration->basis.x.y, decoration->basis.x.z, 0.0f, 1.0f,
                                       0.0f, decoration->pos.x, -750.0f, decoration->pos.z);
                break;
            default:
                Matrix_SetLockedLookAt(mtx, &mtxF, decoration->scale, decoration->scale, decoration->scale,
                                       decoration->basis.x.x, decoration->basis.x.y, decoration->basis.x.z,
                                       decoration->basis.y.x, decoration->basis.y.y, decoration->basis.y.z,
                                       decoration->pos.x, decoration->pos.y, decoration->pos.z);
                break;
        }
        mtx++;

        closestDist = 100000000.0f;
        chunk = gSegmentChunks;
        for (j = 0; j < gSegmentChunkCount; j++) {

            xDist = chunk->pos.x - decoration->pos.x;
            yDist = chunk->pos.y - decoration->pos.y;
            zDist = chunk->pos.z - decoration->pos.z;
            sqDist = SQ(xDist) + SQ(yDist) + SQ(zDist);
            if (sqDist < closestDist) {
                decoration->loadChunk = chunk;
                closestDist = sqDist;
            }
            chunk++;
        }
        decoration++;
    }
}

Gfx* Course_FeatureDrawGateSquare(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    if (sCourseDecorationTextureLoadState != 5) {
        gSPDisplayList(gfx++, D_8017220);
    }
    sCourseDecorationTextureLoadState = 5;
    gSPDisplayList(gfx++, D_80172A0);

    return gfx;
}

Gfx* Course_FeatureDrawGateStart(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    gSPDisplayList(gfx++, D_8018618);

    return gfx;
}

Gfx* Course_FeatureDrawGateHexagonal(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    if (sCourseDecorationTextureLoadState != 7) {
        gSPDisplayList(gfx++, D_801A1F8);
    }
    sCourseDecorationTextureLoadState = 7;
    gSPDisplayList(gfx++, D_801A278);

    return gfx;
}

Gfx* Course_FeatureDrawSignTV(Gfx* gfx) {

    gSPClearGeometryMode(gfx++, G_CULL_BACK);
    gSPDisplayList(gfx++, D_801AEF8);

    return gfx;
}

Gfx* Course_FeatureDrawSign2(Gfx* gfx) {

    gSPClearGeometryMode(gfx++, G_CULL_BACK);
    if (sCourseDecorationTextureLoadState != 9) {
        gSPDisplayList(gfx++, D_801D030);
    }
    sCourseDecorationTextureLoadState = 9;
    gSPDisplayList(gfx++, D_801D0B0);

    return gfx;
}

Gfx* Course_FeatureDrawSign1(Gfx* gfx) {

    gSPClearGeometryMode(gfx++, G_CULL_BACK);
    if (sCourseDecorationTextureLoadState != 10) {
        gSPDisplayList(gfx++, D_801E178);
    }
    sCourseDecorationTextureLoadState = 10;
    gSPDisplayList(gfx++, D_801E1F8);

    return gfx;
}

extern GfxPool D_1000000;

Gfx* Course_FeatureDrawSignNinTexRight(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    if (sCourseDecorationTextureLoadState != 11) {
        gSPDisplayList(gfx++, D_3000688);
    }
    sCourseDecorationTextureLoadState = 11;

    gSPDisplayList(gfx++, D_30006D0);

    gSPMatrix(gfx++, K0_TO_PHYS(D_1000000.unk_2C5E8), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EAA8);

    return gfx;
}

Gfx* Course_FeatureDrawSignNinTexLeft(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    gSPDisplayList(gfx++, D_30006D0);

    gSPMatrix(gfx++, K0_TO_PHYS(D_1000000.unk_2C628), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EAA8);

    return gfx;
}

Gfx* Course_FeatureDrawSignOverhead(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    if (sCourseDecorationTextureLoadState != 12) {
        gSPDisplayList(gfx++, D_3000590);
    }
    sCourseDecorationTextureLoadState = 12;

    gSPDisplayList(gfx++, D_30005D8);

    gSPMatrix(gfx++, K0_TO_PHYS(D_1000000.unk_2C668), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EBF8);

    return gfx;
}

Gfx* Course_FeatureDrawBuildingTall(Gfx* gfx) {

    if (sCourseDecorationTextureLoadState != 0) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_8014A20, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_801ED28);
    sCourseDecorationTextureLoadState = 0;
    return gfx;
}

Gfx* Course_FeatureDrawBuildingShort(Gfx* gfx) {

    if (sCourseDecorationTextureLoadState != 1) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_801F018, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_801EEA0);
    sCourseDecorationTextureLoadState = 1;
    return gfx;
}

Gfx* Course_FeatureDrawBuildingSpire(Gfx* gfx) {

    if (sCourseDecorationTextureLoadState != 2) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_801F8C8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_801F818);
    sCourseDecorationTextureLoadState = 2;
    return gfx;
}

Gfx* Course_FeatureDrawBuildingMountain(Gfx* gfx) {

    if (sCourseDecorationTextureLoadState != 3) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_8020208, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_80200C8);
    sCourseDecorationTextureLoadState = 3;
    return gfx;
}

Gfx* Course_FeatureDrawBuildingTallGold(Gfx* gfx) {

    if (sCourseDecorationTextureLoadState != 4) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_8021380, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_8021208);
    sCourseDecorationTextureLoadState = 4;
    return gfx;
}

void Course_SegmentGetCenterPosition(CourseSegment* segment, f32 t, Vec3f* pos) {
    s32 pad;
    f32 sp58;
    f32 radiusLeft;
    f32 radiusRight;
    f32 lengthProportionAlongSegment;
    Mtx3F segmentBasis;

    lengthProportionAlongSegment = Course_SplineGetLengthInfo(segment, t, &sp58);

    radiusLeft =
        ((segment->next->radiusLeft - segment->radiusLeft) * lengthProportionAlongSegment) + segment->radiusLeft;
    radiusRight =
        ((segment->next->radiusRight - segment->radiusRight) * lengthProportionAlongSegment) + segment->radiusRight;

    Course_SplineGetBasis(segment, t, &segmentBasis, lengthProportionAlongSegment);
    Course_SplineGetPosition(segment, t, pos);
    sp58 = (radiusLeft - radiusRight) / 2.0f;

    pos->x += sp58 * segmentBasis.z.x;
    pos->y += sp58 * segmentBasis.z.y;
    pos->z += sp58 * segmentBasis.z.z;
}

void func_8006FD7C(s32 arg0, s32 arg1, f32 arg2) {
    s32 i = 0;
    s32 temp_v0;
    s32 pad;
    s32 sp0;

    //! @bug sp0 may not be initialised
    if (!gInCourseEditor) {
        sp0 = gSegmentChunkCount;
    }

    while (true) {
        temp_v0 = (i + sp0 - 1) % sp0;

        if ((gSegmentChunks[temp_v0].segmentIndex < arg1 ||
             (arg1 == gSegmentChunks[temp_v0].segmentIndex && gSegmentChunks[temp_v0].segmentTValue <= arg2)) &&
            (arg1 < gSegmentChunks[i].segmentIndex ||
             (arg1 == gSegmentChunks[i].segmentIndex && arg2 < gSegmentChunks[i].segmentTValue))) {
            break;
        }
        i++;
    }
    D_800E12C8[arg0] = temp_v0;
}

f32 func_8006FE90(s32 segmentIndex, f32 t) {
    s32 i;
    s32 sp0;

    i = 0;
    //! @bug sp0 may not be initialised
    if (!gInCourseEditor) {
        sp0 = gSegmentChunkCount;
    }

    do {
        if (segmentIndex == gSegmentChunks[i].segmentIndex) {
            goto next;
        }
        i++;
    } while (i < sp0);

    if (t <= 0.00001f) {
        return 0.0001f;
    }

    return 1.0f;

next:
    while (true) {

        if (segmentIndex == gSegmentChunks[i].segmentIndex && t < gSegmentChunks[i].segmentTValue) {
            break;
        }

        i++;

        if (i == gSegmentChunkCount) {
            return 1.0f;
        }

        if (segmentIndex != gSegmentChunks[i].segmentIndex) {
            return 1.0f;
        }
    }

    return gSegmentChunks[i].segmentTValue;
}

extern Effect gEffects[];

f32 sDashScaleForward = 150.0f;
f32 sDashScaleWidth = 50.0f;
f32 sDashArrowPointScale = 50.0f;

void Course_FlatDashVerticesInit(s32 effectIndex, CourseEffect* effect, Vtx** vtxs) {
    Vtx* vtx;
    f32 t;
    f32 forwardMagnitude;
    s32 pad;
    f32 lengthFromStart;
    Vec3f pos;
    Vec3f forward;
    Mtx3F segmentBasis;
    CourseSegment* segment;

    t = effect->segmentTValueStart;
    segment = &gCurrentCourseInfo->courseSegments[effect->segmentIndex];
    vtx = *vtxs;

    forwardMagnitude = Course_SplineGetTangent(segment, t, &forward);
    Course_SplineGetBasis(segment, effect->segmentTValueStart, &segmentBasis,
                          Course_SplineGetLengthInfo(segment, effect->segmentTValueStart, &lengthFromStart));
    Course_SegmentGetCenterPosition(segment, effect->segmentTValueStart, &pos);
    pos.x += 5.0f * segmentBasis.y.x;
    pos.y += 5.0f * segmentBasis.y.y;
    pos.z += 5.0f * segmentBasis.y.z;
    vtx->v.ob[0] = Math_Round(((DASH_LATERAL_OFFSET(effect) * segmentBasis.z.x) + pos.x) +
                              (segmentBasis.x.x * sDashArrowPointScale));
    vtx->v.ob[1] = Math_Round(((DASH_LATERAL_OFFSET(effect) * segmentBasis.z.y) + pos.y) +
                              (segmentBasis.x.y * sDashArrowPointScale));
    vtx->v.ob[2] = Math_Round(((DASH_LATERAL_OFFSET(effect) * segmentBasis.z.z) + pos.z) +
                              (segmentBasis.x.z * sDashArrowPointScale));
    vtx->v.tc[0] = 0x400;
    vtx->v.tc[1] = 0x200;
    vtx++;
    vtx->v.ob[0] = Math_Round(((DASH_LATERAL_OFFSET(effect) + sDashScaleWidth) * segmentBasis.z.x) + pos.x);
    vtx->v.ob[1] = Math_Round(((DASH_LATERAL_OFFSET(effect) + sDashScaleWidth) * segmentBasis.z.y) + pos.y);
    vtx->v.ob[2] = Math_Round(((DASH_LATERAL_OFFSET(effect) + sDashScaleWidth) * segmentBasis.z.z) + pos.z);
    vtx->v.tc[0] = 0;
    vtx->v.tc[1] = 0;
    vtx++;
    vtx->v.ob[0] = Math_Round(((DASH_LATERAL_OFFSET(effect) - sDashScaleWidth) * segmentBasis.z.x) + pos.x);
    vtx->v.ob[1] = Math_Round(((DASH_LATERAL_OFFSET(effect) - sDashScaleWidth) * segmentBasis.z.y) + pos.y);
    vtx->v.ob[2] = Math_Round(((DASH_LATERAL_OFFSET(effect) - sDashScaleWidth) * segmentBasis.z.z) + pos.z);
    vtx->v.tc[0] = 0x800;
    vtx->v.tc[1] = 0;

    t += sDashScaleForward / forwardMagnitude;
    gEffects[effectIndex].segmentTValueEnd = t;
    gEffects[effectIndex].unk_0C.x = DASH_LATERAL_OFFSET(effect) - sDashScaleWidth;
    gEffects[effectIndex].unk_18.x = DASH_LATERAL_OFFSET(effect) + sDashScaleWidth;

    pos.x = pos.x + segmentBasis.x.x * sDashScaleForward;
    pos.y = pos.y + segmentBasis.x.y * sDashScaleForward;
    pos.z = pos.z + segmentBasis.x.z * sDashScaleForward;
    vtx++;

    vtx->v.ob[0] = Math_Round((DASH_LATERAL_OFFSET(effect) * segmentBasis.z.x) + pos.x);
    vtx->v.ob[1] = Math_Round((DASH_LATERAL_OFFSET(effect) * segmentBasis.z.y) + pos.y);
    vtx->v.ob[2] = Math_Round((DASH_LATERAL_OFFSET(effect) * segmentBasis.z.z) + pos.z);
    vtx->v.tc[0] = 0x400;
    vtx->v.tc[1] = 0x800;
    vtx++;
    vtx->v.ob[0] = Math_Round((((DASH_LATERAL_OFFSET(effect) + sDashScaleWidth) * segmentBasis.z.x) + pos.x) -
                              (segmentBasis.x.x * sDashArrowPointScale));
    vtx->v.ob[1] = Math_Round((((DASH_LATERAL_OFFSET(effect) + sDashScaleWidth) * segmentBasis.z.y) + pos.y) -
                              (segmentBasis.x.y * sDashArrowPointScale));
    vtx->v.ob[2] = Math_Round((((DASH_LATERAL_OFFSET(effect) + sDashScaleWidth) * segmentBasis.z.z) + pos.z) -
                              (segmentBasis.x.z * sDashArrowPointScale));
    vtx->v.tc[0] = 0;
    vtx->v.tc[1] = 0x600;
    vtx++;
    vtx->v.ob[0] = Math_Round((((DASH_LATERAL_OFFSET(effect) - sDashScaleWidth) * segmentBasis.z.x) + pos.x) -
                              (segmentBasis.x.x * sDashArrowPointScale));
    vtx->v.ob[1] = Math_Round((((DASH_LATERAL_OFFSET(effect) - sDashScaleWidth) * segmentBasis.z.y) + pos.y) -
                              (segmentBasis.x.y * sDashArrowPointScale));
    vtx->v.ob[2] = Math_Round((((DASH_LATERAL_OFFSET(effect) - sDashScaleWidth) * segmentBasis.z.z) + pos.z) -
                              (segmentBasis.x.z * sDashArrowPointScale));
    vtx->v.tc[0] = 0x800;
    vtx->v.tc[1] = 0x600;
    gEffectsDrawData[effectIndex].effectType = effect->effectType;

    vtx++;
    *vtxs = vtx;
}

void Course_CurvedDashVerticesInit(s32 effectIndex, CourseEffect* effect, Vtx** vtxs) {
    Vtx* vtx;
    f32 t;
    f32 forwardMagnitude;
    f32 lengthProportionAlongSegment;
    f32 lengthFromStart;
    f32 radius;
    Vec3f spD4;
    Vec3f pos;
    Vec3f vec;
    Vec3f spB0;
    Mtx3F segmentBasis;
    CourseSegment* segment;
    s32 pad;
    MtxF rotationMtxF;

    t = effect->segmentTValueStart;
    segment = &gCurrentCourseInfo->courseSegments[effect->segmentIndex];
    vtx = *vtxs;

    forwardMagnitude = Course_SplineGetTangent(segment, t, &vec);
    lengthProportionAlongSegment = Course_SplineGetLengthInfo(segment, effect->segmentTValueStart, &lengthFromStart);

    Course_SplineGetBasis(segment, effect->segmentTValueStart, &segmentBasis, lengthProportionAlongSegment);

    radius = segment->radiusLeft + segment->radiusRight;
    radius =
        (((segment->next->radiusLeft + segment->next->radiusRight) - radius) * lengthProportionAlongSegment) + radius;
    radius /= 2;

    Course_SegmentGetCenterPosition(segment, effect->segmentTValueStart, &pos);
    Matrix_SetAxisRotation(NULL, &rotationMtxF, 1.0f, DEG_TO_FZXANG(DASH_ANGLE(effect)), segmentBasis.x.x,
                           segmentBasis.x.y, segmentBasis.x.z, 0.0f, 0.0f, 0.0f);
    vec.x = rotationMtxF.m[0][0] * segmentBasis.z.x + rotationMtxF.m[1][0] * segmentBasis.z.y +
            rotationMtxF.m[2][0] * segmentBasis.z.z;
    vec.y = rotationMtxF.m[0][1] * segmentBasis.z.x + rotationMtxF.m[1][1] * segmentBasis.z.y +
            rotationMtxF.m[2][1] * segmentBasis.z.z;
    vec.z = rotationMtxF.m[0][2] * segmentBasis.z.x + rotationMtxF.m[1][2] * segmentBasis.z.y +
            rotationMtxF.m[2][2] * segmentBasis.z.z;
    Math_VectorSetScale(&vec, 1.0f);
    segmentBasis.z.x = vec.x;
    segmentBasis.z.y = vec.y;
    segmentBasis.z.z = vec.z;
    vec.x = rotationMtxF.m[0][0] * segmentBasis.y.x + rotationMtxF.m[1][0] * segmentBasis.y.y +
            rotationMtxF.m[2][0] * segmentBasis.y.z;
    vec.y = rotationMtxF.m[0][1] * segmentBasis.y.x + rotationMtxF.m[1][1] * segmentBasis.y.y +
            rotationMtxF.m[2][1] * segmentBasis.y.z;
    vec.z = rotationMtxF.m[0][2] * segmentBasis.y.x + rotationMtxF.m[1][2] * segmentBasis.y.y +
            rotationMtxF.m[2][2] * segmentBasis.y.z;
    Math_VectorSetScale(&vec, 1.0f);
    segmentBasis.y.x = vec.x;
    segmentBasis.y.y = vec.y;
    segmentBasis.y.z = vec.z;
    spD4 = pos;
    pos.x += (5.0f - radius) * vec.x;
    pos.y += (5.0f - radius) * vec.y;
    pos.z += (5.0f - radius) * vec.z;

    vtx->v.ob[0] = Math_Round((segmentBasis.x.x * 50.0f) + pos.x);
    vtx->v.ob[1] = Math_Round((segmentBasis.x.y * 50.0f) + pos.y);
    vtx->v.ob[2] = Math_Round((segmentBasis.x.z * 50.0f) + pos.z);
    vtx->v.tc[0] = 0x400;
    vtx->v.tc[1] = 0x200;
    vtx++;
    vtx->v.ob[0] = Math_Round((segmentBasis.z.x * 50.0f) + pos.x);
    vtx->v.ob[1] = Math_Round((segmentBasis.z.y * 50.0f) + pos.y);
    vtx->v.ob[2] = Math_Round((segmentBasis.z.z * 50.0f) + pos.z);
    vtx->v.tc[0] = 0;
    vtx->v.tc[1] = 0;
    spB0.x = vtx->v.ob[0] - spD4.x;
    spB0.y = vtx->v.ob[1] - spD4.y;
    spB0.z = vtx->v.ob[2] - spD4.z;
    Math_VectorSetScale(&spB0, 1.0f);

    gEffects[effectIndex].unk_0C = spB0;
    vtx++;

    vtx->v.ob[0] = Math_Round(pos.x - (segmentBasis.z.x * 50.0f));
    vtx->v.ob[1] = Math_Round(pos.y - (segmentBasis.z.y * 50.0f));
    vtx->v.ob[2] = Math_Round(pos.z - (segmentBasis.z.z * 50.0f));
    vtx->v.tc[0] = 0x800;
    vtx->v.tc[1] = 0;
    spB0.x = vtx->v.ob[0] - spD4.x;
    spB0.y = vtx->v.ob[1] - spD4.y;
    spB0.z = vtx->v.ob[2] - spD4.z;
    Math_VectorSetScale(&spB0, 1.0f);
    gEffects[effectIndex].unk_18 = spB0;
    gEffects[effectIndex].segmentTValueStart = t;
    t += (150.0f / forwardMagnitude);
    gEffects[effectIndex].segmentTValueEnd = t;
    pos.x = pos.x + segmentBasis.x.x * 150.0f;
    pos.y = pos.y + segmentBasis.x.y * 150.0f;
    pos.z = pos.z + segmentBasis.x.z * 150.0f;
    vtx++;

    vtx->v.ob[0] = Math_Round(pos.x);
    vtx->v.ob[1] = Math_Round(pos.y);
    vtx->v.ob[2] = Math_Round(pos.z);
    vtx->v.tc[0] = 0x400;
    vtx->v.tc[1] = 0x800;
    vtx++;
    vtx->v.ob[0] = Math_Round(((segmentBasis.z.x * 50.0f) + pos.x) - (segmentBasis.x.x * 50.0f));
    vtx->v.ob[1] = Math_Round(((segmentBasis.z.y * 50.0f) + pos.y) - (segmentBasis.x.y * 50.0f));
    vtx->v.ob[2] = Math_Round(((segmentBasis.z.z * 50.0f) + pos.z) - (segmentBasis.x.z * 50.0f));
    vtx->v.tc[0] = 0;
    vtx->v.tc[1] = 0x600;
    vtx++;
    vtx->v.ob[0] = Math_Round((pos.x - (segmentBasis.z.x * 50.0f)) - (segmentBasis.x.x * 50.0f));
    vtx->v.ob[1] = Math_Round((pos.y - (segmentBasis.z.y * 50.0f)) - (segmentBasis.x.y * 50.0f));
    vtx->v.ob[2] = Math_Round((pos.z - (segmentBasis.z.z * 50.0f)) - (segmentBasis.x.z * 50.0f));
    vtx->v.tc[0] = 0x800;
    vtx->v.tc[1] = 0x600;
    gEffectsDrawData[effectIndex].effectType = effect->effectType;
    vtx++;
    *vtxs = vtx;
}

s32 D_800CD1E8 = 0;

// This just needs to be something equating to 1.0f
#define EFFECT_TEXTURE_SCALAR (2.0f - 1.0f)

Vtx* Course_TerrainEffectVerticesInit(CourseSegment* segment, f32 t, CourseEffect* effect, Vtx* vtx,
                                      f32 rightTextureTCoordinate, f32 leftTextureTCoordinate) {
    bool startPositionSet = false;
    f32 temp_fa1;
    f32 lengthProportionAlongSegment;
    f32 radius;
    f32 rightEdgeDistance;
    f32 leftEdgeDistance;
    s32 textureUnit;
    s32 pad;
    f32 lengthFromStart;
    Vec3f pos;
    Vec3f forward;
    Vec3f lastEdgeRightPos = { 0.0f, 0.0f, 0.0f };
    Vec3f edgeRightPos = { 0.0f, 0.0f, 0.0f };
    Vec3f lastEdgeLeftPos = { 0.0f, 0.0f, 0.0f };
    Vec3f edgeLeftPos = { 0.0f, 0.0f, 0.0f };
    Mtx3F segmentBasis;

    textureUnit = 0;

    while (true) {
        func_8006FD7C((s32) (vtx - sTerrainEffectVtxStart) / 2, segment->segmentIndex, t);
        Course_SplineGetTangent(segment, t, &forward);
        Course_SegmentGetCenterPosition(segment, t, &pos);
        lengthProportionAlongSegment = Course_SplineGetLengthInfo(segment, t, &lengthFromStart);
        Course_SplineGetBasis(segment, t, &segmentBasis, lengthProportionAlongSegment);
        pos.x += segmentBasis.y.x * 10.0f;
        pos.y += segmentBasis.y.y * 10.0f;
        pos.z += segmentBasis.y.z * 10.0f;

        radius = segment->radiusLeft + segment->radiusRight;
        radius = (((segment->next->radiusLeft + segment->next->radiusRight) - radius) * lengthProportionAlongSegment) +
                 radius;
        radius /= 2;

        if (effect->rightEdgeDistance < -1.0f * radius) {
            rightEdgeDistance = -1.0f * radius;
        } else {
            rightEdgeDistance = effect->rightEdgeDistance;
        }

        if (radius < effect->leftEdgeDistance) {
            leftEdgeDistance = radius;
        } else {
            leftEdgeDistance = effect->leftEdgeDistance;
        }
        edgeRightPos.x = Math_Round((segmentBasis.z.x * rightEdgeDistance) + pos.x);
        edgeRightPos.y = Math_Round((segmentBasis.z.y * rightEdgeDistance) + pos.y);
        edgeRightPos.z = Math_Round((segmentBasis.z.z * rightEdgeDistance) + pos.z);
        edgeLeftPos.x = Math_Round((segmentBasis.z.x * leftEdgeDistance) + pos.x);
        edgeLeftPos.y = Math_Round((segmentBasis.z.y * leftEdgeDistance) + pos.y);
        edgeLeftPos.z = Math_Round((segmentBasis.z.z * leftEdgeDistance) + pos.z);
        if (!startPositionSet) {
            lastEdgeRightPos = edgeRightPos;
            lastEdgeLeftPos = edgeLeftPos;
            startPositionSet = true;
        }
        rightTextureTCoordinate += 9.0f * Math_VectorGetDistance(edgeRightPos, lastEdgeRightPos);
        leftTextureTCoordinate += 9.0f * Math_VectorGetDistance(edgeLeftPos, lastEdgeLeftPos);
        if ((rightTextureTCoordinate > 0x8000) || (leftTextureTCoordinate > 0x8000)) {
            rightTextureTCoordinate = (Math_VectorGetDistance(edgeRightPos, lastEdgeRightPos) * 9.0f) + -0x8000;
            leftTextureTCoordinate = (Math_VectorGetDistance(edgeLeftPos, lastEdgeLeftPos) * 9.0f) + -0x8000;
        }
        vtx->v.ob[0] = edgeRightPos.x;
        vtx->v.ob[1] = edgeRightPos.y;
        vtx->v.ob[2] = edgeRightPos.z;
        lastEdgeRightPos = edgeRightPos;
        vtx->v.tc[0] = 0;
        vtx->v.tc[1] = rightTextureTCoordinate * EFFECT_TEXTURE_SCALAR;
        vtx++;
        D_800CD1E8++;
        textureUnit++;

        vtx->v.ob[0] = edgeLeftPos.x;
        vtx->v.ob[1] = edgeLeftPos.y;
        vtx->v.ob[2] = edgeLeftPos.z;
        lastEdgeLeftPos = edgeLeftPos;
        vtx->v.tc[0] = Math_VectorGetDistance(edgeRightPos, edgeLeftPos) * 6.0f * EFFECT_TEXTURE_SCALAR;
        vtx->v.tc[1] = leftTextureTCoordinate * EFFECT_TEXTURE_SCALAR;
        vtx++;
        D_800CD1E8++;
        textureUnit++;

        if (D_800CD1E8 >= D_800E32CC) {
            return vtx;
        }

        if (t == effect->segmentTValueEnd) {
            break;
        }

        if (textureUnit == 32) {
            textureUnit = 0;
            while (true) {
                rightTextureTCoordinate -= 0x400;
                leftTextureTCoordinate -= 0x400;
                if (rightTextureTCoordinate < -0x7C00 || leftTextureTCoordinate < -0x7C00) {
                    break;
                }
            }

        } else {
            t = func_8006FE90(segment->segmentIndex, t);

            if (effect->segmentTValueEnd <= t) {
                if (1) {}
                t = effect->segmentTValueEnd;
            }
        }
    }
    return vtx;
}

void Course_EffectsViewInteractDataInit(s32 arg0) {
    s32 i;
    s32 j;
    CourseSegment* segment;
    CourseEffect* effect;
    s32 pad[3];
    f32 segmentScale;
    CourseEffectsInfo* temp;
    Vtx* vtx;
    Vtx* dashVtx;
    f32 t;
    CourseEffectsInfo* effectsInfo;
    f32 rightTextureTCoordinate;
    f32 leftTextureTCoordinate;
    s32 pad2;

    D_800CD1E8 = 0;
    if (gInCourseEditor) {
        //! @bug Uninitalised pointers!
        D_800E32CC = 0x400;
    } else {
        D_800E32CC = 0x800;
        sTerrainEffectVtxStart = D_80225800.terrainEffectVtx;
        vtx = D_80225800.terrainEffectVtx;
        dashVtx = D_80225800.dashVtx;
        // FAKE
        if (1) {}
        if (1) {}
        if (1) {}
        if (1) {}
        effectsInfo = &gCourseEffectsInfo;
    }

    for (i = 0; i < effectsInfo->count; i++) {
        effect = &effectsInfo->effects[i];
        segment = &gCurrentCourseInfo->courseSegments[effect->segmentIndex];

        gEffectsDrawData[i].effectType = effect->effectType;
        gEffectsDrawData[i].vtxStart = vtx;
        gEffects[i].effectType = effect->effectType;
        gEffects[i].segmentTValueStart = effect->segmentTValueStart;
        gEffects[i].segmentTValueEnd = effect->segmentTValueEnd;
        gEffects[i].unk_0C.x = effect->rightEdgeDistance;
        gEffects[i].unk_18.x = effect->leftEdgeDistance;
        t = effect->segmentTValueStart;

        if (effect->effectType == COURSE_EFFECT_DASH) {
            segmentScale = (segment->radiusLeft + segment->radiusRight) / 520.0f;
            if (segmentScale < 1.0f) {
                segmentScale = 1.0f;
            }
            sDashScaleForward = 150.0f * segmentScale;
            sDashScaleWidth = 50.0f * segmentScale;
            sDashArrowPointScale = 50.0f * segmentScale;

            switch (segment->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_ROAD:
                case TRACK_SHAPE_WALLED_ROAD:
                case TRACK_SHAPE_TUNNEL:
                case TRACK_SHAPE_BORDERLESS_ROAD:
                    Course_FlatDashVerticesInit(i, effect, &dashVtx);
                    break;
                default:
                    Course_CurvedDashVerticesInit(i, effect, &dashVtx);
                    break;
            }
        } else {
            rightTextureTCoordinate = -0x8000;
            leftTextureTCoordinate = -0x8000;

            for (j = 0; j < i; j++) {
                if ((effect->segmentIndex == (effectsInfo->effects[j].segmentIndex + 1)) &&
                    (effect->effectType == effectsInfo->effects[j].effectType) &&
                    (effectsInfo->effects[j].segmentTValueEnd == 1.0f) &&
                    (effect->rightEdgeDistance == effectsInfo->effects[j].rightEdgeDistance) &&
                    (effect->leftEdgeDistance == effectsInfo->effects[j].leftEdgeDistance)) {
                    // float calculation just needs to be 1.0f
                    rightTextureTCoordinate = (gEffectsDrawData[j].vtxEnd - 2)->v.tc[1] / EFFECT_TEXTURE_SCALAR;
                    leftTextureTCoordinate = (gEffectsDrawData[j].vtxEnd - 1)->v.tc[1] / EFFECT_TEXTURE_SCALAR;
                    while (true) {
                        rightTextureTCoordinate -= 0x400;
                        leftTextureTCoordinate -= 0x400;
                        if (rightTextureTCoordinate < -0x7C00 || leftTextureTCoordinate < -0x7C00) {
                            break;
                        }
                    }
                }
            }
            vtx = Course_TerrainEffectVerticesInit(segment, t, effect, vtx, rightTextureTCoordinate,
                                                   leftTextureTCoordinate);
            if (D_800CD1E8 >= D_800E32CC) {
                effectsInfo->count = i - 1;
            }
            gEffectsDrawData[i].effectType = effect->effectType;
        }

        gEffectsDrawData[i].vtxEnd = vtx;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        gCurrentCourseInfo->courseSegments[i].effectsStart = NULL;
        gCurrentCourseInfo->courseSegments[i].effectsEnd = NULL;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = 0; j < effectsInfo->count; j++) {
            effect = &effectsInfo->effects[j];
            if (i == effect->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].effectsEnd = &gEffects[j + 1];
            }
        }
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = effectsInfo->count - 1; j >= 0; j--) {
            effect = &effectsInfo->effects[j];
            if (i == effect->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].effectsStart = &gEffects[j];
            }
        }
    }

    for (i = 0; i < effectsInfo->count; i++) {}
}

extern CourseInfo gCourseInfos[56];
extern CourseEffect gCourseEffects[];

#ifndef EXPANSION_KIT
#define effectDistanceFromCenter 100.0f
#endif

void Course_SegmentPitInit(s32 courseIndex, s32 segmentIndex) {
    s32 effectCount = gCourseEffectsInfo.count;
    CourseEffect* effect = &gCourseEffectsInfo.effects[effectCount];
    CourseSegment* segment;
#ifdef EXPANSION_KIT
    f32 effectDistanceFromCenter = 100.0f;
#endif
    f32 minimumSegmentWidth;
    f32 segmentWidth;
    f32 nextSegmentWidth;
    f32 segmentCenterVariance;
    f32 segmentCenterDistance;
    f32 minimumDistanceFromCenter;
    s32 pad[6];

    segment = &gCourseInfos[courseIndex].courseSegments[segmentIndex];
    segmentWidth = segment->radiusLeft + segment->radiusRight;
    nextSegmentWidth = segment->next->radiusLeft + segment->next->radiusRight;

    segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
    segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
    segmentCenterVariance -= segmentCenterDistance;

#ifdef EXPANSION_KIT
    if (courseIndex >= COURSE_EDIT_1 || gInCourseEditTestRun) {
        if (segmentWidth < nextSegmentWidth) {
            minimumSegmentWidth = segmentWidth;
        } else {
            minimumSegmentWidth = nextSegmentWidth;
        }
        minimumDistanceFromCenter = minimumSegmentWidth / 2.0f;
        if (minimumDistanceFromCenter < 101.0f) {
            effectDistanceFromCenter = minimumDistanceFromCenter - 10.0f;
        }
    }
#endif

    // clang-format off
    switch (COURSE_CONTEXT()->courseData.pit[segmentIndex]) {
        case PIT_LEFT:
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_PIT;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = effectDistanceFromCenter;
            effect->leftEdgeDistance = 5000.0f;
            effectCount++;
            break;
        case PIT_RIGHT:
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_PIT;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = -5000.0f;
            effect->leftEdgeDistance = -1.0f * effectDistanceFromCenter;
            effectCount++;
            break;
        case PIT_BOTH:
            effect->effectType = COURSE_EFFECT_PIT;
            effect->segmentIndex = segmentIndex;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = effectDistanceFromCenter;
            effect->leftEdgeDistance = 5000.0f;
            effect++;
            effectCount++;
            effect->effectType = COURSE_EFFECT_PIT;
            effect->segmentIndex = segmentIndex;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = -5000.0f;
            effect->leftEdgeDistance = -1.0f * effectDistanceFromCenter;
            effectCount++;
            break;
#ifdef EXPANSION_KIT
        case PIT_MIDDLE:
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_PIT;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = -1.0f * effectDistanceFromCenter;
            effect->leftEdgeDistance = effectDistanceFromCenter;
            effectCount++;
            break;
#endif
    }
    // clang-format on
    gCourseEffectsInfo.effects = gCourseEffects;
    gCourseEffectsInfo.count = effectCount;
}

void Course_SegmentDirtInit(s32 courseIndex, s32 segmentIndex) {
    s32 effectCount;
    CourseEffect* effect;
    CourseSegment* segment;
    f32 segmentWidth;
    f32 nextSegmentWidth;
#ifdef EXPANSION_KIT
    f32 effectDistanceFromCenter = 100.0f;
#endif
    f32 minimumSegmentWidth;
    f32 minimumDistanceFromCenter;
    f32 segmentCenterVariance;
    f32 segmentCenterDistance;
    s32 pad[6];

#ifdef EXPANSION_KIT
    if (courseIndex == COURSE_RED_CANYON_2) {
        return;
    }
#endif

    effectCount = gCourseEffectsInfo.count;
    effect = &gCourseEffectsInfo.effects[effectCount];

    segment = &gCourseInfos[courseIndex].courseSegments[segmentIndex];

    segmentWidth = segment->radiusLeft + segment->radiusRight;
    nextSegmentWidth = segment->next->radiusLeft + segment->next->radiusRight;

    segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
    segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
    segmentCenterVariance -= segmentCenterDistance;

#ifdef EXPANSION_KIT
    if (segmentWidth < nextSegmentWidth) {
        minimumSegmentWidth = segmentWidth;
    } else {
        minimumSegmentWidth = nextSegmentWidth;
    }
    minimumDistanceFromCenter = minimumSegmentWidth / 2.0f;
    if (minimumDistanceFromCenter < 101.0f) {
        effectDistanceFromCenter = minimumDistanceFromCenter - 10.0f;
    }
#endif

    // clang-format off
    switch (COURSE_CONTEXT()->courseData.dirt[segmentIndex]) {
        case DIRT_LEFT:
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_DIRT;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = effectDistanceFromCenter;
            effect->leftEdgeDistance = 5000.0f;
            effectCount++;
            break;
        case DIRT_RIGHT:
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_DIRT;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = -5000.0f;
            effect->leftEdgeDistance = -1.0f * effectDistanceFromCenter;
            effectCount++;
            break;
        case DIRT_BOTH:
            effect->effectType = COURSE_EFFECT_DIRT;
            effect->segmentIndex = segmentIndex;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = effectDistanceFromCenter;
            effect->leftEdgeDistance = 5000.0f;
            effect++;
            effectCount++;
            effect->effectType = COURSE_EFFECT_DIRT;
            effect->segmentIndex = segmentIndex;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = -5000.0f;
            effect->leftEdgeDistance = -1.0f * effectDistanceFromCenter;
            effectCount++;
            break;
        case DIRT_MIDDLE:
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_DIRT;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = -1.0f * effectDistanceFromCenter;
            effect->leftEdgeDistance = effectDistanceFromCenter;
            effectCount++;
            break;
    }
    // clang-format on

    gCourseEffectsInfo.effects = gCourseEffects;
    gCourseEffectsInfo.count = effectCount;
}

void Course_SegmentIceInit(s32 courseIndex, s32 segmentIndex) {
    s32 effectCount;
    CourseEffect* effect;
    CourseSegment* segment;
    f32 segmentWidth;
    f32 nextSegmentWidth;
#ifdef EXPANSION_KIT
    f32 effectDistanceFromCenter = 100.0f;
#endif
    f32 minimumSegmentWidth;
    f32 minimumDistanceFromCenter;
    f32 segmentCenterVariance;
    f32 segmentCenterDistance;
    s32 pad[6];

    effectCount = gCourseEffectsInfo.count;
    effect = &gCourseEffectsInfo.effects[effectCount];

    segment = &gCourseInfos[courseIndex].courseSegments[segmentIndex];

    segmentWidth = segment->radiusLeft + segment->radiusRight;
    nextSegmentWidth = segment->next->radiusLeft + segment->next->radiusRight;

    segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
    segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
    segmentCenterVariance -= segmentCenterDistance;

#ifdef EXPANSION_KIT
    if (segmentWidth < nextSegmentWidth) {
        minimumSegmentWidth = segmentWidth;
    } else {
        minimumSegmentWidth = nextSegmentWidth;
    }
    minimumDistanceFromCenter = minimumSegmentWidth / 2.0f;
    if (minimumDistanceFromCenter < 101.0f) {
        effectDistanceFromCenter = minimumDistanceFromCenter - 10.0f;
    }
#endif

    // clang-format off
    switch (COURSE_CONTEXT()->courseData.ice[segmentIndex]) {
        case ICE_LEFT:
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_ICE;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = effectDistanceFromCenter; \
            effect->leftEdgeDistance = 5000.0f;
            effectCount++;
            break;
        case ICE_RIGHT:
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_ICE;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = -5000.0f;
            effect->leftEdgeDistance = -1.0f * effectDistanceFromCenter;
            effectCount++;
            break;
        case ICE_BOTH:
            effect->effectType = COURSE_EFFECT_ICE;
            effect->segmentIndex = segmentIndex;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = effectDistanceFromCenter; \
            effect->leftEdgeDistance = 5000.0f;
            effect++;
            effectCount++;
            effect->effectType = COURSE_EFFECT_ICE;
            effect->segmentIndex = segmentIndex;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = -5000.0f;
            effect->leftEdgeDistance = -1.0f * effectDistanceFromCenter;
            effectCount++;
            break;
        case ICE_MIDDLE:
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_ICE;
            effect->segmentTValueStart = 0.0f;
            effect->segmentTValueEnd = 1.0f;
            effect->rightEdgeDistance = -1.0f * effectDistanceFromCenter; \
            effect->leftEdgeDistance = effectDistanceFromCenter;
            effectCount++;
            break;
    }
    // clang-format on

    gCourseEffectsInfo.effects = gCourseEffects;
    gCourseEffectsInfo.count = effectCount;
}

void Course_LandminesInit(s32 courseIndex) {
    CourseFeature* feature;
    s32 i;
    s32 jumpCount;
    CourseSegment* segment;
    f32 t;
    f32 lengthFactor;
    f32 segmentWidth;
    f32 segmentCenterDistance;
    f32 segmentWidthVariance;
    f32 segmentCenterVariance;
    s32 featureCount;
    s32 landmineCount;
    f32 forwardMagnitude;
    Vec3f tangent;

    featureCount = gCourseFeaturesInfo.featureCount;
    landmineCount = gCourseFeaturesInfo.landmineCount;
    jumpCount = gCourseFeaturesInfo.jumpCount;
    feature = &gCourseFeaturesInfo.features[featureCount];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        segment = &gCourseInfos[courseIndex].courseSegments[i];
        lengthFactor = segment->length;

        segmentWidth = segment->radiusLeft + segment->radiusRight;
        segmentWidthVariance = (segment->next->radiusLeft + segment->next->radiusRight);
        segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
        segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
        segmentWidthVariance -= segmentWidth;
        segmentCenterVariance -= segmentCenterDistance;

        t = 0.0f;

        switch (COURSE_CONTEXT()->courseData.landmine[i]) {
            case LANDMINE_MIDDLE:
                lengthFactor /= 5.0f;
                forwardMagnitude = Course_SplineGetTangent(segment, 0.0f, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) -
                                         ((segmentWidth + (segmentWidthVariance * t)) / 4);
                feature++;
                featureCount++;
                landmineCount++;

                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) +
                                         ((segmentWidth + (segmentWidthVariance * t)) / 4);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                feature->segmentIndex = i;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = (segmentCenterVariance * t) + segmentCenterDistance;
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) -
                                         ((segmentWidth + (segmentWidthVariance * t)) / 4);
                feature++;
                featureCount++;
                landmineCount++;

                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) +
                                         ((segmentWidth + (segmentWidthVariance * t)) / 4);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                feature->segmentIndex = i;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = (segmentCenterVariance * t) + segmentCenterDistance;
                feature++;
                featureCount++;
                landmineCount++;
                break;
            case LANDMINE_LEFT:
                lengthFactor /= 6.0f;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->lateralOffset = t + segmentCenterDistance + ((segmentWidth + t) / 8);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, 0.0f, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = (segmentCenterVariance * t) + segmentCenterDistance +
                                         (((segmentWidth + (segmentWidthVariance * t)) * 3.0f) / 8);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = (segmentCenterVariance * t) + segmentCenterDistance +
                                         ((segmentWidth + (segmentWidthVariance * t)) / 8);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = (segmentCenterVariance * t) + segmentCenterDistance +
                                         (((segmentWidth + (segmentWidthVariance * t)) * 3.0f) / 8);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = (segmentCenterVariance * t) + segmentCenterDistance +
                                         ((segmentWidth + (segmentWidthVariance * t)) / 8);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = (segmentCenterVariance * t) + segmentCenterDistance +
                                         (((segmentWidth + (segmentWidthVariance * t)) * 3.0f) / 8);
                feature++;
                featureCount++;
                landmineCount++;
                break;
            case LANDMINE_RIGHT:
                lengthFactor /= 6.0f;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->lateralOffset = (t + segmentCenterDistance) - ((segmentWidth + t) / 8);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, 0.0f, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) -
                                         (((segmentWidth + (segmentWidthVariance * t)) * 3.0f) / 8);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) -
                                         ((segmentWidth + (segmentWidthVariance * t)) / 8);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) -
                                         (((segmentWidth + (segmentWidthVariance * t)) * 3.0f) / 8);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) -
                                         ((segmentWidth + (segmentWidthVariance * t)) / 8);
                feature++;
                featureCount++;
                landmineCount++;

                forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
                t += lengthFactor / forwardMagnitude;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) -
                                         (((segmentWidth + (segmentWidthVariance * t)) * 3.0f) / 8);
                feature++;
                featureCount++;
                landmineCount++;
                break;
        }
    }

    gCourseFeaturesInfo.landmineCount = landmineCount;
    gCourseFeaturesInfo.jumpCount = jumpCount;
    gCourseFeaturesInfo.featureCount = featureCount;
}

void Course_JumpsInit(s32 courseIndex) {
    CourseFeature* feature;
    s32 landmineCount;
    f32 segmentWidthVariance;
    f32 segmentCenterVariance;
    f32 segmentWidth;
    f32 segmentCenterDistance;
    s32 i;
    s32 pad[2];
    s32 featureCount;
    s32 jumpCount;
    f32 t;
    CourseSegment* segment;
    Vec3f tangent;

    landmineCount = gCourseFeaturesInfo.landmineCount;
    jumpCount = gCourseFeaturesInfo.jumpCount;
    featureCount = gCourseFeaturesInfo.featureCount;

    feature = &gCourseFeaturesInfo.features[featureCount];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        segment = &gCourseInfos[courseIndex].courseSegments[i];

        segmentWidth = segment->radiusLeft + segment->radiusRight;
        segmentWidthVariance = segment->next->radiusLeft + segment->next->radiusRight;
        segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
        segmentCenterVariance = ((segment->next->radiusLeft - segment->next->radiusRight) / 2);
        segmentWidthVariance -= segmentWidth;
        segmentCenterVariance -= segmentCenterDistance;

        t = 0.0f;

        switch (COURSE_CONTEXT()->courseData.jump[i]) {
            case JUMP_ALL:
                t -= 100.0f / Course_SplineGetTangent(segment, 1.0f, &tangent);
                t += 1.0f;

                feature->featureType = COURSE_FEATURE_JUMP;
                feature->segmentIndex = i;
                feature->segmentTValue = t;
                feature->lateralOffset = (segmentCenterVariance * t) + segmentCenterDistance;
                feature->dimensions.x = segmentWidth + (segmentWidthVariance * t);
                feature->dimensions.y = 30.0f;
                feature->dimensions.z = 60.0f;
                feature++;
                featureCount++;
                jumpCount++;
                break;
            case JUMP_LEFT:
                t -= 100.0f / Course_SplineGetTangent(segment, 1.0f, &tangent);
                t += 1.0f;

                feature->featureType = COURSE_FEATURE_JUMP;
                feature->segmentIndex = i;
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) +
                                         ((segmentWidth + (segmentWidthVariance * t)) / 4);
                feature->dimensions.x = (segmentWidth + (segmentWidthVariance * t)) / 2;
                feature->dimensions.y = 30.0f;
                feature->dimensions.z = 60.0f;
                feature++;
                featureCount++;
                jumpCount++;
                break;
            case JUMP_RIGHT:
                t -= 100.0f / Course_SplineGetTangent(segment, 1.0f, &tangent);
                t += 1.0f;

                feature->featureType = COURSE_FEATURE_JUMP;
                feature->segmentIndex = i;
                feature->segmentTValue = t;
                feature->lateralOffset = ((segmentCenterVariance * t) + segmentCenterDistance) -
                                         ((segmentWidth + (segmentWidthVariance * t)) / 4);
                feature->dimensions.x = (segmentWidth + (segmentWidthVariance * t)) / 2;
                feature->dimensions.y = 30.0f;
                feature->dimensions.z = 60.0f;
                feature++;
                featureCount++;
                jumpCount++;
                break;
        }
    }

    gCourseFeaturesInfo.landmineCount = landmineCount;
    gCourseFeaturesInfo.jumpCount = jumpCount;
    gCourseFeaturesInfo.featureCount = featureCount;
}

void Course_SegmentDashInit(s32 courseIndex, s32 segmentIndex) {
    s32 effectCount;
    f32 lengthFactor;
    f32 forwardMagnitude;
    f32 t;
    f32 width;
    f32 widthVariance;
    f32 segmentCenterDistance;
    f32 segmentCenterVariance;
    CourseSegment* segment;
    CourseEffect* effect;
    Vec3f tangent;

    effectCount = gCourseEffectsInfo.count;
    effect = &gCourseEffectsInfo.effects[effectCount];
    segment = &gCourseInfos[courseIndex].courseSegments[segmentIndex];
    width = segment->radiusLeft + segment->radiusRight;
    widthVariance = segment->next->radiusLeft + segment->next->radiusRight;
    segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
    segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
    widthVariance -= width;
    segmentCenterVariance -= segmentCenterDistance;
    lengthFactor = segment->length;

    t = 0;

    switch (COURSE_CONTEXT()->courseData.dash[segmentIndex]) {
        case DASH_MIDDLE:
            lengthFactor /= 2;
            forwardMagnitude = Course_SplineGetTangent(segment, 0, &tangent);
            t += lengthFactor / forwardMagnitude;
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_DASH;
            effect->segmentTValueStart = t;
            effect->segmentTValueEnd = 1.0f;

            switch (segment->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_HALF_PIPE:
                    DASH_ANGLE(effect) = DASH_ANGLE2(effect) = 0.0f;
                    break;
                case TRACK_SHAPE_PIPE:
                    DASH_ANGLE(effect) = DASH_ANGLE2(effect) = 22.5f;
                    break;
                case TRACK_SHAPE_CYLINDER:
                    DASH_ANGLE(effect) = DASH_ANGLE2(effect) = 202.5f;
                    break;
                default:
                    DASH_LATERAL_OFFSET(effect) = 0.0f;
                    DASH_LATERAL_OFFSET2(effect) = 0.0f;
                    break;
            }
            effectCount++;
            break;
        case DASH_LEFT:
            lengthFactor /= 2;
            forwardMagnitude = Course_SplineGetTangent(segment, 0, &tangent);
            t += lengthFactor / forwardMagnitude;
            width = (t * widthVariance) + width;
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_DASH;
            effect->segmentTValueStart = t;
            effect->segmentTValueEnd = 1.0f;
            DASH_LATERAL_OFFSET(effect) = (width / 2.0) - 100.0f;
            DASH_LATERAL_OFFSET2(effect) = DASH_LATERAL_OFFSET(effect);
            if (DASH_LATERAL_OFFSET(effect) < 0.0f) {
                DASH_LATERAL_OFFSET(effect) = 0.0f;
            }
            DASH_LATERAL_OFFSET2(effect) = DASH_LATERAL_OFFSET(effect);

            switch (segment->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_HALF_PIPE:
                    DASH_ANGLE(effect) = DASH_ANGLE2(effect) = 45.0f;
                    break;
                case TRACK_SHAPE_PIPE:
                    DASH_ANGLE(effect) = DASH_ANGLE2(effect) = 157.5f;
                    break;
                case TRACK_SHAPE_CYLINDER:
                    DASH_ANGLE(effect) = DASH_ANGLE2(effect) = 337.5f;
                    break;
            }
            effectCount++;
            break;
        case DASH_RIGHT:
            lengthFactor /= 2;
            forwardMagnitude = Course_SplineGetTangent(segment, 0, &tangent);
            t += lengthFactor / forwardMagnitude;
            width = (t * widthVariance) + width;
            effect->segmentIndex = segmentIndex;
            effect->effectType = COURSE_EFFECT_DASH;
            effect->segmentTValueStart = t;
            effect->segmentTValueEnd = 1.0f;
            DASH_LATERAL_OFFSET(effect) = ((width / 2.0) - 100.0f) * -1.0f;

            if (DASH_LATERAL_OFFSET(effect) > 0.0f) {
                DASH_LATERAL_OFFSET(effect) = 0.0f;
            }
            DASH_LATERAL_OFFSET2(effect) = DASH_LATERAL_OFFSET(effect);

            switch (segment->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_HALF_PIPE:
                    DASH_ANGLE(effect) = DASH_ANGLE2(effect) = 315.0f;
                    break;
                case TRACK_SHAPE_PIPE:
                    DASH_ANGLE(effect) = DASH_ANGLE2(effect) = 247.5f;
                    break;
                case TRACK_SHAPE_CYLINDER:
                    DASH_ANGLE(effect) = DASH_ANGLE2(effect) = 67.5f;
                    break;
            }
            effectCount++;
            break;
    }

    gCourseEffectsInfo.effects = gCourseEffects;
    gCourseEffectsInfo.count = effectCount;
}

void Course_GatesInit(s32 courseIndex) {
    s32 j;
    s32 i;
    s32 featureCount;
    CourseSegment* segment;
    CourseFeature* feature;
    s32 landmineCount = gCourseFeaturesInfo.landmineCount;
    s32 jumpCount = gCourseFeaturesInfo.jumpCount;
    f32 segmentWidthVariance;
    f32 segmentCenterVariance;
    f32 segmentWidth;
    f32 segmentCenterDistance;

    featureCount = gCourseFeaturesInfo.featureCount;

    feature = &gCourseFeaturesInfo.features[featureCount];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gCourseInfos[courseIndex].segmentCount; j++) {
            segment = &gCourseInfos[courseIndex].courseSegments[j];

            if (i == 3) {}

            segmentWidth = segment->radiusLeft + segment->radiusRight;
            segmentWidthVariance = segment->next->radiusLeft + segment->next->radiusRight;
            segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
            segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
            segmentWidthVariance -= segmentWidth;
            segmentCenterVariance -= segmentCenterDistance;

            if (i == COURSE_CONTEXT()->courseData.gate[j]) {
                switch (COURSE_CONTEXT()->courseData.gate[j]) {
                    case GATE_SQUARE:
                        feature->featureType = COURSE_FEATURE_GATE_SQUARE;
                        break;
                    case GATE_START:
                        feature->featureType = COURSE_FEATURE_GATE_START;
                        break;
                    case GATE_HEXAGONAL:
                        feature->featureType = COURSE_FEATURE_GATE_HEXAGONAL;
                        break;
                }
                feature->segmentIndex = j;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segmentCenterDistance;
                feature->dimensions.x = 0.0f;
                feature->dimensions.y = 0.0f;
                feature->dimensions.z = 0.0f;
                featureCount++;
                feature++;
            }
        }
    }
    gCourseFeaturesInfo.landmineCount = landmineCount;
    gCourseFeaturesInfo.jumpCount = jumpCount;
    gCourseFeaturesInfo.featureCount = featureCount;
}

void Course_TallBuildingsInit(s32 courseIndex) {
    s32 featureCount;
    s32 i;
    CourseSegment* segment;
    CourseFeature* feature;
    s32 landmineCount = gCourseFeaturesInfo.landmineCount;
    s32 jumpCount = gCourseFeaturesInfo.jumpCount;
    f32 segmentWidthVariance;
    f32 segmentCenterVariance;
    f32 segmentWidth;
    f32 segmentCenterDistance;

    featureCount = gCourseFeaturesInfo.featureCount;

    feature = &gCourseFeaturesInfo.features[featureCount];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        segment = &gCourseInfos[courseIndex].courseSegments[i];

        segmentWidth = segment->radiusLeft + segment->radiusRight;
        segmentWidthVariance = segment->next->radiusLeft + segment->next->radiusRight;
        segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
        segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
        segmentWidthVariance -= segmentWidth;
        segmentCenterVariance -= segmentCenterDistance;

        switch (COURSE_CONTEXT()->courseData.building[i]) {
            case BUILDING_TALL_LEFT:
                feature->featureType = COURSE_FEATURE_BUILDING_TALL_LEFT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segment->radiusLeft + 500.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_TALL_RIGHT:
                feature->featureType = COURSE_FEATURE_BUILDING_TALL_RIGHT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = (segment->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_TALL_BOTH:
                feature->featureType = COURSE_FEATURE_BUILDING_TALL_LEFT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segment->radiusLeft + 500.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_BUILDING_TALL_RIGHT;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = (segment->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
        }
    }
    gCourseFeaturesInfo.landmineCount = landmineCount;
    gCourseFeaturesInfo.jumpCount = jumpCount;
    gCourseFeaturesInfo.featureCount = featureCount;
}

void Course_ShortBuildingsInit(s32 courseIndex) {
    s32 featureCount;
    s32 i;
    s32 j;
    CourseSegment* segment;
    CourseFeature* feature;
    s32 landmineCount = gCourseFeaturesInfo.landmineCount;
    s32 jumpCount = gCourseFeaturesInfo.jumpCount;
    f32 segmentWidthVariance;
    f32 segmentCenterVariance;
    f32 segmentWidth;
    f32 segmentCenterDistance;

    featureCount = gCourseFeaturesInfo.featureCount;

    feature = &gCourseFeaturesInfo.features[featureCount];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        segment = &gCourseInfos[courseIndex].courseSegments[i];

        segmentWidth = segment->radiusLeft + segment->radiusRight;
        segmentWidthVariance = segment->next->radiusLeft + segment->next->radiusRight;
        segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
        segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
        segmentWidthVariance -= segmentWidth;
        segmentCenterVariance -= segmentCenterDistance;

        switch (COURSE_CONTEXT()->courseData.building[i]) {
            case BUILDING_SHORT_LEFT:
                feature->featureType = COURSE_FEATURE_BUILDING_SHORT_LEFT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segment->radiusLeft + 500.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_SHORT_RIGHT:
                feature->featureType = COURSE_FEATURE_BUILDING_SHORT_RIGHT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = (segment->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_SHORT_BOTH:
                feature->featureType = COURSE_FEATURE_BUILDING_SHORT_LEFT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segment->radiusLeft + 500.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_BUILDING_SHORT_RIGHT;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = (segment->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
        }
    }

    gCourseFeaturesInfo.landmineCount = landmineCount;
    gCourseFeaturesInfo.jumpCount = jumpCount;
    gCourseFeaturesInfo.featureCount = featureCount;
}

void Course_SpireBuildingsInit(s32 courseIndex) {
    s32 featureCount;
    s32 i;
    s32 j;
    CourseSegment* segment;
    CourseFeature* feature;
    s32 landmineCount = gCourseFeaturesInfo.landmineCount;
    s32 jumpCount = gCourseFeaturesInfo.jumpCount;
    f32 segmentWidthVariance;
    f32 segmentCenterVariance;
    f32 segmentWidth;
    f32 segmentCenterDistance;

    featureCount = gCourseFeaturesInfo.featureCount;
    feature = &gCourseFeaturesInfo.features[featureCount];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        segment = &gCourseInfos[courseIndex].courseSegments[i];

        segmentWidth = segment->radiusLeft + segment->radiusRight;
        segmentWidthVariance = segment->next->radiusLeft + segment->next->radiusRight;
        segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
        segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
        segmentWidthVariance -= segmentWidth;
        segmentCenterVariance -= segmentCenterDistance;

        switch (COURSE_CONTEXT()->courseData.building[i]) {
            case BUILDING_SPIRE_LEFT:
                feature->featureType = COURSE_FEATURE_BUILDING_SPIRE_LEFT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segment->radiusLeft + 500.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_SPIRE_RIGHT:
                feature->featureType = COURSE_FEATURE_BUILDING_SPIRE_RIGHT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = (segment->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_SPIRE_BOTH:
                feature->featureType = COURSE_FEATURE_BUILDING_SPIRE_LEFT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segment->radiusLeft + 500.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_BUILDING_SPIRE_RIGHT;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = (segment->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
        }
    }

    gCourseFeaturesInfo.landmineCount = landmineCount;
    gCourseFeaturesInfo.jumpCount = jumpCount;
    gCourseFeaturesInfo.featureCount = featureCount;
}

void Course_ExtraBuildingsInit(s32 courseIndex) {
    s32 featureCount;
    s32 i;
    s32 j;
    CourseSegment* segment;
    CourseFeature* feature;
    s32 landmineCount = gCourseFeaturesInfo.landmineCount;
    s32 jumpCount = gCourseFeaturesInfo.jumpCount;
    f32 segmentWidthVariance;
    f32 segmentCenterVariance;
    f32 segmentWidth;
    f32 segmentCenterDistance;

    featureCount = gCourseFeaturesInfo.featureCount;

    feature = &gCourseFeaturesInfo.features[featureCount];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        segment = &gCourseInfos[courseIndex].courseSegments[i];

        segmentWidth = segment->radiusLeft + segment->radiusRight;
        segmentWidthVariance = segment->next->radiusLeft + segment->next->radiusRight;
        segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
        segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
        segmentWidthVariance -= segmentWidth;
        segmentCenterVariance -= segmentCenterDistance;

        switch (COURSE_CONTEXT()->courseData.building[i]) {
            case BUILDING_MOUNTAIN_BOTH:
                feature->featureType = COURSE_FEATURE_BUILDING_MOUNTAIN_LEFT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segment->radiusLeft + 500.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_BUILDING_MOUNTAIN_RIGHT;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = (segment->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_MOUNTAIN_LEFT:
                feature->featureType = COURSE_FEATURE_BUILDING_MOUNTAIN_LEFT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segment->radiusLeft + 500.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_MOUNTAIN_RIGHT:
                feature->featureType = COURSE_FEATURE_BUILDING_MOUNTAIN_RIGHT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = (segment->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_TALL_GOLD_BOTH:
                feature->featureType = COURSE_FEATURE_BUILDING_TALL_GOLD_LEFT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segment->radiusLeft + 500.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                feature->segmentIndex = i;
                feature->featureType = COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = (segment->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_TALL_GOLD_LEFT:
                feature->featureType = COURSE_FEATURE_BUILDING_TALL_GOLD_LEFT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = segment->radiusLeft + 500.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
            case BUILDING_TALL_GOLD_RIGHT:
                feature->featureType = COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT;
                feature->segmentIndex = i;
                feature->segmentTValue = 0.0f;
                feature->lateralOffset = (segment->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                feature->dimensions.x = 0.0f; \
                feature->dimensions.y = 0.0f; \
                feature->dimensions.z = 0.0f;
                // clang-format on
                feature++;
                featureCount++;
                break;
        }
    }

    gCourseFeaturesInfo.landmineCount = landmineCount;
    gCourseFeaturesInfo.jumpCount = jumpCount;
    gCourseFeaturesInfo.featureCount = featureCount;
}

void Course_BuildingsInit(s32 courseIndex) {
    Course_TallBuildingsInit(courseIndex);
    Course_ShortBuildingsInit(courseIndex);
    Course_SpireBuildingsInit(courseIndex);
    Course_ExtraBuildingsInit(courseIndex);
}

void Course_SignsInit(s32 courseIndex) {
    CourseFeature* feature;
    s32 featureCount = gCourseFeaturesInfo.featureCount;
    s32 landmineCount = gCourseFeaturesInfo.landmineCount;
    s32 jumpCount = gCourseFeaturesInfo.jumpCount;
    f32 segmentWidthVariance;
    f32 segmentCenterVariance;
    f32 segmentWidth;
    f32 segmentCenterDistance;
    CourseSegment* segment;
    s32 i;
    s32 j;

    feature = &gCourseFeaturesInfo.features[featureCount];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < gCourseInfos[courseIndex].segmentCount; j++) {
            segment = &gCourseInfos[courseIndex].courseSegments[j];

            if (i == 5) {}

            segmentWidth = segment->radiusLeft + segment->radiusRight;
            segmentWidthVariance = segment->next->radiusLeft + segment->next->radiusRight;
            segmentCenterDistance = (segment->radiusLeft - segment->radiusRight) / 2;
            segmentCenterVariance = (segment->next->radiusLeft - segment->next->radiusRight) / 2;
            segmentWidthVariance -= segmentWidth;
            segmentCenterVariance -= segmentCenterDistance;

            if (i == COURSE_CONTEXT()->courseData.sign[j]) {
                switch (COURSE_CONTEXT()->courseData.sign[j]) {
                    case SIGN_TV:
                        feature->featureType = COURSE_FEATURE_SIGN_TV_RIGHT;
                        feature->segmentIndex = j;
                        feature->segmentTValue = 0.0f;
                        feature->lateralOffset = (segment->radiusRight + 23.0f + 20.0f) * -1.0f;
                        // clang-format off
                        feature->dimensions.x = 0.0f; \
                        feature->dimensions.y = 0.0f; \
                        feature->dimensions.z = 0.0f;
                        // clang-format on
                        feature++;
                        featureCount++;
                        feature->segmentIndex = j;
                        feature->featureType = COURSE_FEATURE_SIGN_TV_LEFT;
                        feature->segmentTValue = 0.0f;
                        feature->lateralOffset = segment->radiusLeft + 23.0f + 20.0f;
                        // clang-format off
                        feature->dimensions.x = 0.0f; \
                        feature->dimensions.y = 0.0f; \
                        feature->dimensions.z = 0.0f;
                        // clang-format on
                        feature++;
                        featureCount++;
                        break;
                    case SIGN_2:
                        feature->featureType = COURSE_FEATURE_SIGN_2_RIGHT;
                        feature->segmentIndex = j;
                        feature->segmentTValue = 0.0f;
                        feature->lateralOffset = (segment->radiusRight + 23.0f + 20.0f) * -1.0f;
                        // clang-format off
                        feature->dimensions.x = 0.0f; \
                        feature->dimensions.y = 0.0f; \
                        feature->dimensions.z = 0.0f;
                        // clang-format on
                        feature++;
                        featureCount++;
                        feature->segmentIndex = j;
                        feature->featureType = COURSE_FEATURE_SIGN_2_LEFT;
                        feature->segmentTValue = 0.0f;
                        feature->lateralOffset = segment->radiusLeft + 23.0f + 20.0f;
                        // clang-format off
                        feature->dimensions.x = 0.0f; \
                        feature->dimensions.y = 0.0f; \
                        feature->dimensions.z = 0.0f;
                        // clang-format on
                        feature++;
                        featureCount++;
                        break;
                    case SIGN_1:
                        feature->featureType = COURSE_FEATURE_SIGN_1_RIGHT;
                        feature->segmentIndex = j;
                        feature->segmentTValue = 0.0f;
                        feature->lateralOffset = (segment->radiusRight + 23.0f + 20.0f) * -1.0f;
                        // clang-format off
                        feature->dimensions.x = 0.0f; \
                        feature->dimensions.y = 0.0f; \
                        feature->dimensions.z = 0.0f;
                        // clang-format on
                        feature++;
                        featureCount++;
                        feature->segmentIndex = j;
                        feature->featureType = COURSE_FEATURE_SIGN_1_LEFT;
                        feature->segmentTValue = 0.0f;
                        feature->lateralOffset = segment->radiusLeft + 23.0f + 20.0f;
                        // clang-format off
                        feature->dimensions.x = 0.0f; \
                        feature->dimensions.y = 0.0f; \
                        feature->dimensions.z = 0.0f;
                        // clang-format on
                        feature++;
                        featureCount++;
                        break;
                    case SIGN_NINTEX:
                        feature->featureType = COURSE_FEATURE_SIGN_NINTEX_RIGHT;
                        feature->segmentIndex = j;
                        feature->segmentTValue = 0.0f;
                        feature->lateralOffset = (segment->radiusRight + 23.0f + 20.0f) * -1.0f;
                        // clang-format off
                        feature->dimensions.x = 0.0f; \
                        feature->dimensions.y = 0.0f; \
                        feature->dimensions.z = 0.0f;
                        // clang-format on
                        feature++;
                        featureCount++;
                        feature->segmentIndex = j;
                        feature->featureType = COURSE_FEATURE_SIGN_NINTEX_LEFT;
                        feature->segmentTValue = 0.0f;
                        feature->lateralOffset = segment->radiusLeft + 23.0f + 20.0f;
                        // clang-format off
                        feature->dimensions.x = 0.0f; \
                        feature->dimensions.y = 0.0f; \
                        feature->dimensions.z = 0.0f;
                        // clang-format on
                        feature++;
                        featureCount++;
                        break;
                    case SIGN_OVERHEAD:
                        feature->featureType = COURSE_FEATURE_SIGN_OVERHEAD;
                        feature->segmentIndex = j;
                        feature->segmentTValue = 0.0f;
                        feature->lateralOffset = segmentCenterDistance;
                        // clang-format off
                        feature->dimensions.x = 0.0f; \
                        feature->dimensions.y = 0.0f; \
                        feature->dimensions.z = 0.0f;
                        // clang-format on
                        feature++;
                        featureCount++;
                        break;
                }
            }
        }
    }

    gCourseFeaturesInfo.featureCount = featureCount;
    gCourseFeaturesInfo.landmineCount = landmineCount;
    gCourseFeaturesInfo.jumpCount = jumpCount;
}

extern s32 D_802CDFD0;

void Course_FeaturesInit(s32 courseIndex) {
    if (gInCourseEditor) {
        if (D_802CDFD0 < 4) {
            return;
        }
    } else if (COURSE_CONTEXT()->courseData.controlPointCount < 4) {
        return;
    }

    gCourseFeaturesInfo.landmineCount = 0;
    gCourseFeaturesInfo.jumpCount = 0;
    gCourseFeaturesInfo.featureCount = 0;
    Course_LandminesInit(courseIndex);
    Course_JumpsInit(courseIndex);
    Course_GatesInit(courseIndex);
    Course_BuildingsInit(courseIndex);
    Course_SignsInit(courseIndex);
}

void Course_EffectsInit(s32 courseIndex) {
    s32 i;

    if (gInCourseEditor) {
        if (D_802CDFD0 < 4) {
            return;
        }
    } else if (COURSE_CONTEXT()->courseData.controlPointCount < 4) {
        return;
    }

    gCourseEffectsInfo.count = 0;

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        Course_SegmentIceInit(courseIndex, i);
        Course_SegmentDirtInit(courseIndex, i);
        Course_SegmentPitInit(courseIndex, i);
        Course_SegmentDashInit(courseIndex, i);
    }
}

extern s32 gCourseIndex;
extern CourseData D_8010C770;
extern CourseSegment D_802CDFD8[];
extern CourseSegment D_802C2020[];

void Course_SegmentsInit(void) {
    CourseSegment* segment;
    CourseInfo* courseInfo;
    s32 segmentIndex;
    s32 i;

    courseInfo = &gCourseInfos[gCourseIndex];
    segment = D_802C2020;
    courseInfo->courseSegments = D_802C2020;

    for (i = 0; i < courseInfo->segmentCount; i++) {
        segment->segmentIndex = i;
        segment->next = segment + 1;
        segment->prev = segment - 1;
        segment++;
    }

    courseInfo->courseSegments[0].prev = &courseInfo->courseSegments[courseInfo->segmentCount - 1];
    courseInfo->courseSegments[courseInfo->segmentCount - 1].next = courseInfo->courseSegments;

    segmentIndex = 0;
    for (i = 0; i < courseInfo->segmentCount; i++) {
        segment = &courseInfo->courseSegments[i];
        if (!(segment->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
            segmentIndex = i;
            break;
        }
    }

    segment = &courseInfo->courseSegments[segmentIndex];

    for (i = 0; i < courseInfo->segmentCount; i++) {
        if (segment->next->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) {
            segmentIndex = segment->segmentIndex;
            break;
        }
        segment = segment->next;
    }

    segmentIndex = courseInfo->courseSegments[segmentIndex].next->segmentIndex;
    segment = &courseInfo->courseSegments[segmentIndex];
    for (i = 0; i < courseInfo->segmentCount; i++) {
        D_802CDFD8[i] = *segment;

        D_8010C770.bankAngle[i] = COURSE_CONTEXT()->courseData.bankAngle[segment->segmentIndex];
        D_8010C770.pit[i] = COURSE_CONTEXT()->courseData.pit[segment->segmentIndex];
        D_8010C770.dash[i] = COURSE_CONTEXT()->courseData.dash[segment->segmentIndex];
        D_8010C770.dirt[i] = COURSE_CONTEXT()->courseData.dirt[segment->segmentIndex];
        D_8010C770.ice[i] = COURSE_CONTEXT()->courseData.ice[segment->segmentIndex];
        D_8010C770.jump[i] = COURSE_CONTEXT()->courseData.jump[segment->segmentIndex];
        D_8010C770.landmine[i] = COURSE_CONTEXT()->courseData.landmine[segment->segmentIndex];
        D_8010C770.gate[i] = COURSE_CONTEXT()->courseData.gate[segment->segmentIndex];
        D_8010C770.building[i] = COURSE_CONTEXT()->courseData.building[segment->segmentIndex];
        D_8010C770.sign[i] = COURSE_CONTEXT()->courseData.sign[segment->segmentIndex];
        segment = segment->next;
    }

    for (i = 0; i < courseInfo->segmentCount; i++) {
        D_802C2020[i] = D_802CDFD8[i];
        courseInfo->courseSegments[i] = D_802CDFD8[i];

        COURSE_CONTEXT()->courseData.bankAngle[i] = D_8010C770.bankAngle[i];
        COURSE_CONTEXT()->courseData.pit[i] = D_8010C770.pit[i];
        COURSE_CONTEXT()->courseData.dash[i] = D_8010C770.dash[i];
        COURSE_CONTEXT()->courseData.dirt[i] = D_8010C770.dirt[i];
        COURSE_CONTEXT()->courseData.ice[i] = D_8010C770.ice[i];
        COURSE_CONTEXT()->courseData.jump[i] = D_8010C770.jump[i];
        COURSE_CONTEXT()->courseData.landmine[i] = D_8010C770.landmine[i];
        COURSE_CONTEXT()->courseData.gate[i] = D_8010C770.gate[i];
        COURSE_CONTEXT()->courseData.building[i] = D_8010C770.building[i];
        COURSE_CONTEXT()->courseData.sign[i] = D_8010C770.sign[i];
    }

    segment = courseInfo->courseSegments;
    for (i = 0; i < courseInfo->segmentCount; i++) {
        segment->segmentIndex = i;
        segment->next = segment + 1;
        segment->prev = segment - 1;
        segment++;
    }
    courseInfo->courseSegments[0].prev = &courseInfo->courseSegments[courseInfo->segmentCount - 1];
    courseInfo->courseSegments[courseInfo->segmentCount - 1].next = courseInfo->courseSegments;
}

extern OSMesgQueue gDmaMesgQueue;
extern OSIoMesg gDmaIOMsg;
extern OSPiHandle* gCartRomHandle;

void Dma_ClearRomCopy(void* romAddr, void* ramAddr, size_t size) {
    osInvalDCache(osPhysicalToVirtual(ramAddr), size);
    gDmaIOMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    gDmaIOMsg.hdr.retQueue = &gDmaMesgQueue;
    gDmaIOMsg.dramAddr = osPhysicalToVirtual(ramAddr);
    gDmaIOMsg.devAddr = (uintptr_t) romAddr;
    gDmaIOMsg.size = size;
    gCartRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(gCartRomHandle, &gDmaIOMsg, OS_READ);
    MQ_WAIT_FOR_MESG(&gDmaMesgQueue, NULL);
}

void Dma_RomCopyAsync(void* romAddr, void* ramAddr, size_t size) {
    OSMesg sp20[8];

    if (gDmaMesgQueue.validCount >= gDmaMesgQueue.msgCount) {
        MQ_WAIT_FOR_MESG(&gDmaMesgQueue, sp20);
    }
    osInvalDCache(osPhysicalToVirtual(ramAddr), size);
    gDmaIOMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    gDmaIOMsg.hdr.retQueue = &gDmaMesgQueue;
    gDmaIOMsg.dramAddr = osPhysicalToVirtual(ramAddr);
    gDmaIOMsg.devAddr = (uintptr_t) romAddr;
    gDmaIOMsg.size = size;
    gCartRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(gCartRomHandle, &gDmaIOMsg, OS_READ);
    MQ_WAIT_FOR_MESG(&gDmaMesgQueue, sp20);
}

void Dma_LoadAssetsAsync(u8* romAddr, u8* ramAddr, size_t size) {
    s32 remainder;
    s32 i;
    s32 numBlocks = size / 1024;

    for (i = 0; i < numBlocks; i++) {
        Dma_RomCopyAsync(romAddr, ramAddr, 0x400);

        romAddr += 0x400;
        ramAddr += 0x400;
    }

    remainder = size % 1024;
    if (remainder) {
        Dma_RomCopyAsync(romAddr, ramAddr, remainder);
    }
}

// todo: move these to appropriate places
static const char devrostr0[] = "\n/***\nCOURSE GADGET TEXTURE OVER!! %f,%f\n***/\n";
static const char devrostr1[] = "GADGET OVER !! OVER !! OVER !!\n";
static const char devrostr2[] = "Gadget Vtx Over %d!!\n";
static const char devrostr3[] = "move start position %d\n";
static const char devrostr4[] = "look index %d\n";
static const char devrostr5[] = "index %d\n";

extern u8 gEditCupTrackNames[][9];
extern s16 gPlayer1OverallPosition;

void Course_Load(s32 courseIndex) {
    s32 pad;
    s32 diskCourseIndex;

    if (courseIndex >= COURSE_DEATH_RACE) {
        Dma_LoadAssetsAsync(SEGMENT_ROM_START(course_data) + (courseIndex - 30) * sizeof(CourseData),
                            osVirtualToPhysical(&COURSE_CONTEXT()->courseData), sizeof(CourseData));
        if ((gPlayer1OverallPosition >= 4) && (courseIndex == COURSE_ENDING)) {
            COURSE_CONTEXT()->courseData.skybox = SKYBOX_BLUE;
        }
    } else if (courseIndex >= COURSE_X_1) {
        Course_GenerateRandomCourse();
        return;
    } else if (courseIndex >= COURSE_EDIT_1) {
        diskCourseIndex = courseIndex - COURSE_EDIT_1;
        if (func_800760F8() != 2) {
            osWritebackDCacheAll();
            LeoFault_DrawIsDiskInserted();
            osWritebackDCacheAll();
        }

        while (func_800760F8() != 2) {}

        PRINTF("ENTRY CHECK\n");
        if (Mfs_GetFileIndex(0xFFFB, gEditCupTrackNames[diskCourseIndex], "CRSD") != 0xFFFF) {
            PRINTF("ENTRY CHECK OK\n");
            Mfs_LoadFileInDir(0xFFFB, gEditCupTrackNames[diskCourseIndex], "CRSD", &COURSE_CONTEXT()->courseData, 0);
            PRINTF("ENTRY LOAD OK\n");
        }
    } else {
        PRINTF("UNPACK\n");
        Dma_LoadAssetsAsync(SEGMENT_ROM_START(course_data) + courseIndex * sizeof(CourseData),
                            osVirtualToPhysical(&COURSE_CONTEXT()->courseData), sizeof(CourseData));
        PRINTF("UNPACK OK\n");
    }

    func_80074428(courseIndex);
}

void Course_GadgetsInit(s32 courseIndex) {
    Course_FeaturesInit(courseIndex);
    Course_EffectsInit(courseIndex);
}

void func_80074204(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        COURSE_CONTEXT()->courseData.bankAngle[i] = 0;
        COURSE_CONTEXT()->courseData.pit[i] = PIT_NONE;
        COURSE_CONTEXT()->courseData.dash[i] = DASH_NONE;
        COURSE_CONTEXT()->courseData.dirt[i] = DIRT_NONE;
        COURSE_CONTEXT()->courseData.ice[i] = ICE_NONE;
        COURSE_CONTEXT()->courseData.jump[i] = JUMP_NONE;
        COURSE_CONTEXT()->courseData.landmine[i] = LANDMINE_NONE;
        COURSE_CONTEXT()->courseData.gate[i] = GATE_NONE;
        COURSE_CONTEXT()->courseData.building[i] = BUILDING_NONE;
        COURSE_CONTEXT()->courseData.sign[i] = SIGN_NONE;
    }
}

void func_800742D0(void) {
    func_80074204();
    COURSE_CONTEXT()->courseData.venue = VENUE_MUTE_CITY;
    COURSE_CONTEXT()->courseData.skybox = SKYBOX_PURPLE;
}

extern CourseFeature gCourseFeatures[];
extern CourseData D_8010CF50;

void func_800742FC(void) {
    s32 i;

    bzero(SEGMENT_VRAM_START(game_context), SEGMENT_BSS_SIZE(game_context));
    func_80074204();
    D_802CDFD0 = 0;
    COURSE_CONTEXT()->courseData.creatorId = CREATOR_NINTENDO;
    COURSE_CONTEXT()->courseData.controlPointCount = 0;
    COURSE_CONTEXT()->courseData.venue = VENUE_MUTE_CITY;
    COURSE_CONTEXT()->courseData.skybox = SKYBOX_PURPLE;
    D_8010CF50 = COURSE_CONTEXT()->courseData;
    gCourseFeaturesInfo.features = gCourseFeatures;
    gCourseInfos[0].courseSegments = D_802C2020;
    gCourseEffectsInfo.effects = gCourseEffects;

    for (i = 0; i < ARRAY_COUNT(gCourseInfos); i++) {}

    Course_Load(COURSE_MUTE_CITY);
    func_80074204();
    D_8010CF50 = COURSE_CONTEXT()->courseData;
    COURSE_CONTEXT()->courseData.controlPointCount = 0;
    D_802CDFD0 = 0;
}

void func_80074428(s32 courseIndex) {
    s32 i;
    CourseSegment* var_v0;
    CourseData* courseData = &COURSE_CONTEXT()->courseData;

    if (courseData->controlPointCount == 0) {
        return;
    }

    gCourseInfos[courseIndex].courseSegments = D_802C2020;
    gCourseInfos[courseIndex].segmentCount = courseData->controlPointCount;

    for (i = 0; i < courseData->controlPointCount; i++) {
        D_802C2020[i].pos = courseData->controlPoint[i].pos;
        D_802C2020[i].radiusLeft = courseData->controlPoint[i].radiusLeft;
        D_802C2020[i].radiusRight = courseData->controlPoint[i].radiusRight;
        D_802C2020[i].trackSegmentInfo = courseData->controlPoint[i].trackSegmentInfo;
    }

    var_v0 = D_802C2020;
    for (i = 0; i < courseData->controlPointCount; i++, var_v0++) {
        var_v0->segmentIndex = i;
        var_v0->next = var_v0 + 1;
        var_v0->prev = var_v0 - 1;
    }

    D_802C2020[0].prev = &D_802C2020[courseData->controlPointCount - 1];
    D_802C2020[courseData->controlPointCount - 1].next = &D_802C2020[0];

    if (courseData->controlPointCount < 4) {
        return;
    }

    Course_SplineCalculateTensions(&gCourseInfos[courseIndex]);
    func_80074CE4(&gCourseInfos[courseIndex]);
    Course_SegmentLengthsInit(&gCourseInfos[courseIndex]);
}

extern CourseSegment D_802CB6D0[];

void func_80074594(void) {
    s32 i;
    CourseData* courseData = &COURSE_CONTEXT()->courseData;

    courseData->controlPointCount = D_802CDFD0;

    for (i = 0; i < courseData->controlPointCount; i++) {
        courseData->controlPoint[i].pos = D_802CB6D0[i].pos;
        courseData->controlPoint[i].radiusLeft = D_802CB6D0[i].radiusLeft;
        courseData->controlPoint[i].radiusRight = D_802CB6D0[i].radiusRight;
        courseData->controlPoint[i].trackSegmentInfo = D_802CB6D0[i].trackSegmentInfo;
    }
}

// Centre the course around origin
void func_80074634(CourseInfo* courseInfo) {
    CourseSegment* courseSegment;
    s32 i;
    f32 minX = 65536.0f;
    f32 maxX = -65536.0f;
    f32 minZ = 65536.0f;
    f32 maxZ = -65536.0f;

    for (i = 0; i < courseInfo->segmentCount; i++) {

        courseSegment = &courseInfo->courseSegments[i];

        if (courseSegment->pos.x < minX) {
            minX = courseSegment->pos.x;
        }
        if (maxX < courseSegment->pos.x) {
            maxX = courseSegment->pos.x;
        }

        if (courseSegment->pos.z < minZ) {
            minZ = courseSegment->pos.z;
        }
        if (maxZ < courseSegment->pos.z) {
            maxZ = courseSegment->pos.z;
        }
    }

    for (i = 0; i < courseInfo->segmentCount; i++) {

        courseSegment = &courseInfo->courseSegments[i];

        courseSegment->pos.x -= ((minX + maxX) / 2);
        courseSegment->pos.z -= ((minZ + maxZ) / 2);
    }
}

extern CourseSegment D_802CB6D0[];

void func_80074744(void) {
    CourseSegment* segment;
    s32 i;
    s32 trackShape;

    for (i = 0; i < D_802CDFD0; i++) {
        segment = &D_802CB6D0[i];
        trackShape = segment->trackSegmentInfo & TRACK_SHAPE_MASK;
        switch (trackShape) {
            case TRACK_SHAPE_PIPE:
            case TRACK_SHAPE_CYLINDER:
            case TRACK_SHAPE_HALF_PIPE:
            case TRACK_SHAPE_AIR:
                COURSE_CONTEXT()->courseData.pit[i] = PIT_NONE;
                COURSE_CONTEXT()->courseData.dirt[i] = DIRT_NONE;
                COURSE_CONTEXT()->courseData.ice[i] = ICE_NONE;
                COURSE_CONTEXT()->courseData.jump[i] = JUMP_NONE;
                COURSE_CONTEXT()->courseData.landmine[i] = LANDMINE_NONE;
                break;
        }
        switch (trackShape) {
            case TRACK_SHAPE_ROAD:
            case TRACK_SHAPE_BORDERLESS_ROAD:
                break;
            default:
                COURSE_CONTEXT()->courseData.gate[i] = GATE_NONE;
                COURSE_CONTEXT()->courseData.sign[i] = SIGN_NONE;
                break;
        }
    }
}

UNUSED s32 D_800CD21C = 0;

s32 D_800CD220[] = { 1, 0, 0, 0, 2, 3, 4, 0, 0, 0, 0 };
s32 D_800CD24C[] = { 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// Load Venue Building Textures
void func_800747EC(s32 venue) {
    RomOffset romOffset = (D_800CD220[venue] * 0x800) + SEGMENT_ROM_START(super_textures);

    Dma_LoadAssetsAsync(romOffset, Segment_SegmentedToVirtual(D_8014A20), 0x800);
}

extern GfxPool* gGfxPool;
extern s8 gGamePaused;

void func_80074844(void) {
    static s32 D_800CD298 = 0;
    static s32 D_800CD29C = 0;
    f32 temp;
    MtxF sp3C;

    if (!gGamePaused) {
        D_800CD298 = (D_800CD298 + 0xFE9) & 0xFFF;
        D_800CD29C = (D_800CD29C + 0xFDE) & 0xFFF;
    }

    sp3C.m[2][1] = sp3C.m[0][1] = sp3C.m[1][0] = sp3C.m[1][2] = sp3C.m[3][0] = sp3C.m[3][1] = sp3C.m[3][2] =
        sp3C.m[0][3] = sp3C.m[1][3] = sp3C.m[2][3] = 0.0f;

    sp3C.m[3][3] = sp3C.m[1][1] = 1.0f;

    sp3C.m[2][0] = temp = SIN(0x1000 - D_800CD298);
    sp3C.m[0][2] = -temp;

    sp3C.m[0][0] = sp3C.m[2][2] = temp = COS(0x1000 - D_800CD298);

    Matrix_ToMtx(&sp3C, gGfxPool->unk_2C5E8);

    sp3C.m[2][0] = temp = SIN(D_800CD298);
    sp3C.m[0][2] = -temp;
    sp3C.m[0][0] = sp3C.m[2][2] = temp = COS(D_800CD298);

    Matrix_ToMtx(&sp3C, gGfxPool->unk_2C628);
    sp3C.m[1][2] = temp = SIN(D_800CD29C);
    sp3C.m[2][1] = -temp;
    sp3C.m[2][2] = sp3C.m[1][1] = temp = COS(D_800CD29C);

    sp3C.m[2][0] = sp3C.m[0][2] = 0.0f;
    sp3C.m[0][0] = 1.0f;
    Matrix_ToMtx(&sp3C, gGfxPool->unk_2C668);
}
