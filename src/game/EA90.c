#include "global.h"
#include "fzx_course.h"

void Math_NormalizeXZ(f32* x, f32* z) {
    f32 magnitude;
    f32 normalizingFactor;

    magnitude = SQ(*x) + SQ(*z);
    if (magnitude < 1e-07) {
        return;
    }
    normalizingFactor = 1.0f / sqrtf(magnitude);
    *x *= normalizingFactor;
    *z *= normalizingFactor;
}

void Math_NormalizeXYZ(f32* x, f32* y, f32* z) {
    f32 magnitude;
    f32 normalizingFactor;

    magnitude = SQ(*x) + SQ(*y) + SQ(*z);
    if (magnitude < 1e-07) {
        return;
    }
    normalizingFactor = 1.0f / sqrtf(magnitude);
    *x *= normalizingFactor;
    *y *= normalizingFactor;
    *z *= normalizingFactor;
}

s32 Math_VectorSetScale(Vec3f* vec, f32 scale) {
    f32 magnitude;
    f32 scaleFactor;

    magnitude = SQ(vec->x) + SQ(vec->y) + SQ(vec->z);
    if (magnitude < 1e-07) {
        return -1;
    }
    scaleFactor = scale / sqrtf(magnitude);
    vec->x *= scaleFactor;
    vec->y *= scaleFactor;
    vec->z *= scaleFactor;
    return 0;
}

extern CourseInfo* gCurrentCourseInfo;

#ifndef EXPANSION_KIT
Mtx3F* func_80074C60(Mtx3F* basisPtr) {
    f32 lengthProportionAlongSegment;
    f32 lengthFromStart;
    CourseSegment* segment;
    Mtx3F basis;

    segment = gCurrentCourseInfo->courseSegments;
    lengthProportionAlongSegment = Course_SplineGetLengthInfo(segment, 0.0f, &lengthFromStart);
    Course_SplineGetBasis(segment, 0.0f, &basis, lengthProportionAlongSegment);
    *basisPtr = basis;
    return basisPtr;
}
#endif

// Set segment up vectors
void func_80074CE4(CourseInfo* courseInfo) {
    s32 pad[4];
    f32 baseUpX;
    f32 baseUpY;
    f32 baseUpZ;
    f32 rightVecX;
    f32 rightVecY;
    f32 rightVecZ;
    Vec3f segmentTangentVec;
    MtxF mtxF;
    s32 i;
    CourseSegment* segment;

    segment = courseInfo->courseSegments;
    for (i = 0; i < courseInfo->segmentCount; i++) {
        Course_SplineGetTangent(segment, 0.0f, &segmentTangentVec);
        Math_VectorSetScale(&segmentTangentVec, 1);
        if ((SQ(segmentTangentVec.x) + SQ(segmentTangentVec.z)) != 0.0f) {
            rightVecX = segmentTangentVec.z;
            rightVecY = 0.0f;
            rightVecZ = -1.0f * segmentTangentVec.x;
        } else {
            rightVecX = 0.0f;
            rightVecY = 0.0f;
            rightVecZ = segmentTangentVec.y;
        }

        Math_NormalizeXYZ(&rightVecX, &rightVecY, &rightVecZ);
        baseUpX = ((rightVecY * segmentTangentVec.z) - (rightVecZ * segmentTangentVec.y)) * -1.0f;
        baseUpY = ((rightVecZ * segmentTangentVec.x) - (rightVecX * segmentTangentVec.z)) * -1.0f;
        baseUpZ = ((rightVecX * segmentTangentVec.y) - (rightVecY * segmentTangentVec.x)) * -1.0f;
        Math_NormalizeXYZ(&baseUpX, &baseUpY, &baseUpZ);
        Matrix_SetAxisRotation(NULL, &mtxF, 1.0f, DEG_TO_FZXANG(COURSE_CONTEXT()->courseData.bankAngle[i]),
                               segmentTangentVec.x, segmentTangentVec.y, segmentTangentVec.z, 0.0f, 0.0f, 0.0f);
        segment->up.x = mtxF.m[0][0] * baseUpX + mtxF.m[1][0] * baseUpY + mtxF.m[2][0] * baseUpZ;
        segment->up.y = mtxF.m[0][1] * baseUpX + mtxF.m[1][1] * baseUpY + mtxF.m[2][1] * baseUpZ;
        segment->up.z = mtxF.m[0][2] * baseUpX + mtxF.m[1][2] * baseUpY + mtxF.m[2][2] * baseUpZ;
        segment = segment->next;
    }
}

// Test Function?
#ifndef EXPANSION_KIT
void func_80074F98(void) {
    f32 sp2C;
    s64 temp;
    bcmp(NULL, NULL, 0);
    osEPiReadIo(NULL, 0, NULL);
    osEPiWriteIo(NULL, 0, 0);
    __osSetHWIntrRoutine(0, NULL);
    osStopThread(NULL);
    LeoBootGame(NULL);
    osEPiLinkHandle(NULL);
    osPfsInitPak(NULL, NULL, 0);
    osPfsAllocateFile(NULL, 0, 0, NULL, NULL, 0, NULL);
    osPfsReadWriteFile(NULL, 0, 0, 0, 0, NULL);
    osPfsFindFile(NULL, 0, 0, NULL, NULL, NULL);
    sprintf(NULL, "");
    guOrtho(NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    temp = sp2C;
}
#else
void func_80074F98(void) {
    f32 sp2C;
    s64 temp;
    bcmp(NULL, NULL, 0);
    osEPiReadIo(NULL, 0, NULL);
    osEPiWriteIo(NULL, 0, 0);
    __osSetHWIntrRoutine(0, NULL, NULL);
    osStopThread(NULL);
    osGetIntMask();
    osEPiLinkHandle(NULL);
    osPfsInitPak(NULL, NULL, 0);
    osPfsAllocateFile(NULL, 0, 0, NULL, NULL, 0, NULL);
    osPfsReadWriteFile(NULL, 0, 0, 0, 0, NULL);
    osPfsFindFile(NULL, 0, 0, NULL, NULL, NULL);
    __osSetCause(0);
    __osSetCount(0);
    sprintf(NULL, "");
    temp = sp2C;
}
#endif
