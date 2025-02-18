#include "libultra/ultra64.h"
#include "unk_structs.h"
#include "fzx_course.h"

CourseData D_8010B7B0 = {
    CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
};
CourseData D_8010BF90 = { 0 };
CourseData D_8010C770 = {
    CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
};
CourseData D_8010CF50 = {
    CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
};

u8 gEditCupTrackNames[6][9] = { 0 };

s32 gLivesChangeCounter = 0;
s32 gPreviousLivesCount = 0;
