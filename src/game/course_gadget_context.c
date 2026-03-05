#include "global.h"

#ifndef EXPANSION_KIT
#define MAX_FEATURE_COUNT 105
#define MAX_JUMP_COUNT 4
#else
#define MAX_FEATURE_COUNT 120
#define MAX_JUMP_COUNT 8
#endif

unk_807B3C20 D_802CB6D0;
#ifdef EXPANSION_KIT
unk_807B3C20 D_807B6528;
#endif
unk_807B3C20 D_802CDFD8;
CourseDecoration gCourseDecorations[32];
CourseFeature gCourseFeatures[MAX_FEATURE_COUNT];
CourseFeaturesInfo gCourseFeaturesInfo;
CourseEffect gCourseEffects[192];
CourseEffectsInfo gCourseEffectsInfo;
#ifndef EXPANSION_KIT
EffectDrawData gEffectsDrawData[192];
#else
EffectDrawData gEffectsDrawData[2][192];
#endif
Landmine gLandmines[48];
Jump gJumps[MAX_JUMP_COUNT];
Effect gEffects[192];
