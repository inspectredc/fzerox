#include "global.h"
#include "fzx_expansion_kit.h"

u8 sCourseEditSegmentJoinErrors[64];
u8 gCourseEditErrors[12] = { 0 };

extern unk_800D6CA0 D_800D6CA0;

void func_xk2_800F12B0(void) {
    s32 i;

    D_800D6CA0.overlappingControlPoint = -1;

    for (i = 0; i < 12; i++) {
        if ((i != COURSE_EDIT_ERROR_TOO_MUCH_TO_DISPLAY) && (i != COURSE_EDIT_ERROR_TOO_LONG) && (i != COURSE_EDIT_ERROR_ROADS_OVERLAP)) {
            gCourseEditErrors[i] = false;
        }
    }

    for (i = 0; i < 64; i++) {
        sCourseEditSegmentJoinErrors[i] = 0;
    }
}

void CourseEdit_SetSegmentJoinError(s32 controlPoint, u8 errorFlag) {
    sCourseEditSegmentJoinErrors[controlPoint] |= errorFlag;
}

u8 CourseEdit_GetSegmentJoinErrors(s32 controlPoint) {
    return sCourseEditSegmentJoinErrors[controlPoint];
}
