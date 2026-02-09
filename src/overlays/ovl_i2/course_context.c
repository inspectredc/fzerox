#include "libultra/ultra64.h"
#include "unk_structs.h"
#include "fzx_course.h"

#ifndef EXPANSION_KIT
CourseContext gCourseCtx = {
    { CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } }
};
#else
//! @bug gCourseCtx is treated as though it is size 0xC830 which overlaps with D_800CF950
#ifdef AVOID_UB
CourseContext gCourseCtx = {
    { CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } },
    { 0 }
};
#else
CourseBuffer gCourseCtx = {
    { CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } },
    { 0 }
};
#endif
#endif

#ifndef EXPANSION_KIT
CourseData D_8010BF90 = { 0 };
#endif

CourseData D_8010C770 = {
    CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
};

#ifdef EXPANSION_KIT
CourseData D_i2_800D0130 = {
    CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
};
#endif

CourseData D_8010CF50 = {
    CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
};

#ifndef EXPANSION_KIT
char gEditCupTrackNames[6][9] = { 0 };
#else
char gEditCupTrackNames[6 * 4][9] = { 0 };
#endif

#ifdef EXPANSION_KIT
s32 D_800D11C8[] = { 1, 1, 1, 1, 4, 0 };
#endif

s32 gLivesChangeCounter = 0;
s32 gPreviousLivesCount = 0;
