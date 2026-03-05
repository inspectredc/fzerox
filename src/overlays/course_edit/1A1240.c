#include "global.h"
#include "fzx_expansion_kit.h"
#include "fzx_course.h"

f32 D_xk2_80128CB0;
f32 D_xk2_80128CB4;
Vec3f D_xk2_80128CB8[5];
s32 D_xk2_80128CF4;

s32 D_xk2_80104BC0 = 0;

s32 func_xk2_800EF780(void) {
    return D_xk2_80104BC0;
}

extern u8 D_80030060[];
extern u8 D_8003006C[];
extern s32 D_xk2_80119800;
extern unk_80128690 D_80128690[];
extern unk_80128690 D_xk2_80128990[];
extern unk_807B3C20 D_807B6528;
extern unk_807B3C20 D_802CB6D0;
extern CourseData D_8010CF50;
extern unk_800D6CA0 D_800D6CA0;

void func_xk2_800EF78C(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        D_xk2_80128990[i] = D_80128690[i];
    }

    for (i = 0; i < 9; i++) {
        D_8003006C[i] = D_80030060[i];
    }
    D_807B6528 = D_802CB6D0;
    D_8010CF50 = COURSE_CONTEXT()->courseData;
    D_xk2_80119800 = D_800D6CA0.unk_0C;
    D_xk2_80104BC0 = 1;
}

extern s32 D_xk2_800F703C;
extern s32 D_xk2_800F7040;
extern CourseSegment* D_xk2_801197EC;
extern s32 gVenueOption;
extern s32 gSkyboxOption;

void func_xk2_800EF8B0(void) {
    s32 i;

    if ((D_800D6CA0.unk_08 == 1) || (D_800D6CA0.unk_08 == 3) || (D_800D6CA0.unk_08 == 2) ||
        (D_800D6CA0.unk_08 == 0x10) || (D_800D6CA0.unk_08 == 0x20) || (D_xk2_80104BC0 == 0)) {
        return;
    }
    D_xk2_80104BC0 = 0;
    Audio_TriggerSystemSE(NA_SE_37);
    D_xk2_800F703C = -1;
    for (i = 0; i < 64; i++) {
        D_80128690[i] = D_xk2_80128990[i];
    }

    for (i = 0; i < 9; i++) {
        D_80030060[i] = D_8003006C[i];
    }
    D_802CB6D0 = D_807B6528;
    COURSE_CONTEXT()->courseData = D_8010CF50;
    D_xk2_801197EC = D_802CB6D0.unk_0000;
    func_xk2_800DC3F8();
    func_xk2_800F5C50();
    D_800D6CA0.unk_0C = D_xk2_80119800;
    D_xk2_800F7040 = 3;
    gVenueOption = COURSE_CONTEXT()->courseData.venue;
    gSkyboxOption = COURSE_CONTEXT()->courseData.skybox;
    func_800747EC(gVenueOption);
    func_80077AD8(gVenueOption);
}

void func_xk2_800EFA94(CourseSegment* arg0, CourseSegment* arg1) {
    CourseSegment* var_s0;
    s32 i;
    s32 j;
    Vec3f sp64[64];

    i = 0;
    var_s0 = arg0;
    while (var_s0 != arg1) {
        func_xk2_800F267C(&sp64[i], var_s0->pos, arg0->pos, arg1->pos);
        var_s0 = var_s0->next;
        i++;
    }

    sp64[i] = arg1->pos;
    i++;

    for (j = 0; j < i; j++) {}

    if (i < 3) {
        Audio_TriggerSystemSE(NA_SE_32);
        return;
    }

    for (j = 0; j < i - 1; j++) {
        if (Math_VectorGetDistance(sp64[j], sp64[j + 1]) < 498.0f) {
            Audio_TriggerSystemSE(NA_SE_32);
            return;
        }
    }

    Audio_TriggerSystemSE(NA_SE_39);
    var_s0 = arg0;
    while (var_s0 != arg1) {
        func_xk2_800F267C(&var_s0->pos, var_s0->pos, arg0->pos, arg1->pos);
        var_s0 = var_s0->next;
    }
}

void func_xk2_800EFCD0(void) {
    CourseSegment* temp_t0;
    s32 var_a0;
    s32 var_a2;
    s32 sp30;
    s32 var_v1;
    s32 var_v1_2;
    CourseSegment* sp24;
    CourseSegment* sp20;
    CourseSegment* sp1C;
    CourseSegment* var_a0_2;
    CourseSegment* var_v0_2;
    s32 i;

    var_v1 = 0;
    var_a2 = 0;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 != 0) {
            var_v1++;
            continue;
        }
        sp30 = i;
        break;
    }
    if (var_v1 == D_802CB6D0.controlPointCount) {
        return;
    }
    var_v1 = 0;
    var_v0_2 = &D_802CB6D0.unk_0000[sp30];
    temp_t0 = var_v0_2;
    // FAKE!
    // clang-format off
    var_a0_2 = sp1C; \
    do {
        if (D_80128690[var_v0_2->segmentIndex].unk_08 != 0) {
            if (var_v1 == 0) {
                var_a0_2 = var_v0_2;
            }

            var_v1++;
            if (var_a2 < var_v1) {
                var_a2 = var_v1;
                sp24 = var_a0_2;
                sp20 = var_v0_2;
                if (1) {}
            }
        } else {
            var_v1 = 0;
        }
        var_v0_2 = var_v0_2->next;
    } while (temp_t0 != var_v0_2);
    // clang-format on

    if (var_a2 != 0) {
        func_xk2_800EFA94(sp24, sp20);
        D_xk2_800F7040 = 3;
    }
}

extern s32 gCourseEditCursorXPos;
extern s32 gCourseEditCursorYPos;

s32 func_xk2_800EFDE4(f32 arg0) {
    s32 i;
    s32 sp70;
    s32 sp6C;
    s32 var_fp;
    f32 temp_fv0;
    Vec3f sp58;

    var_fp = -1;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {

        sp58 = D_802CB6D0.unk_0000[i].pos;
        if (func_xk2_800EF090(sp58, &sp70, &sp6C) != 0) {
            continue;
        }
        temp_fv0 = SQ(gCourseEditCursorXPos - sp70) + SQ(gCourseEditCursorYPos - sp6C);
        if (temp_fv0 < arg0) {
            arg0 = temp_fv0;
            var_fp = i;
        }
    }
    return var_fp;
}

void func_xk2_800EFF40(void) {
    f32 temp_fv0;
    s32 i;
    s32 temp_a0;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {

        if (!(D_802CB6D0.unk_0000[i].trackSegmentInfo & TRACK_FLAG_8000000)) {
            temp_fv0 = (D_802CB6D0.unk_0000[i].radiusLeft + D_802CB6D0.unk_0000[i].radiusRight) / 2.0f;
            D_802CB6D0.unk_0000[i].radiusLeft = temp_fv0;
            D_802CB6D0.unk_0000[i].radiusRight = temp_fv0;
        }
        temp_a0 = D_802CB6D0.unk_0000[i].prev->segmentIndex;
        if (!(D_802CB6D0.unk_0000[temp_a0].trackSegmentInfo & TRACK_FLAG_8000000)) {
            temp_fv0 = (D_802CB6D0.unk_0000[i].radiusLeft + D_802CB6D0.unk_0000[i].radiusRight) / 2.0f;
            D_802CB6D0.unk_0000[i].radiusLeft = temp_fv0;
            D_802CB6D0.unk_0000[i].radiusRight = temp_fv0;
        }
    }
}

s32 func_xk2_800EFFF0(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if ((D_xk2_80128CB8[i].x < -15000.0f) || (D_xk2_80128CB8[i].x > 15000.0f)) {
            return -1;
        }
        if ((D_xk2_80128CB8[i].z < -15000.0f) || (D_xk2_80128CB8[i].z > 15000.0f)) {
            return -1;
        }
        if ((D_xk2_80128CB8[i].y < 0.0f) || (D_xk2_80128CB8[i].y > 5000.0f)) {
            return -1;
        }
    }
    return 0;
}

#ifdef NON_MATCHING
s32 func_xk2_800F01C4(Vec3f arg0, Mtx3F arg3) {
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv1;

    D_xk2_80128CF4 = 0;
    temp_fa1 = D_xk2_80128CB4 + 150.0f;
    temp_fv1 = temp_fa1 * D_xk2_80128CB0;

    sp84 = temp_fv1 * arg3.z.x;
    D_xk2_80128CB8[0].x = arg0.x - sp84;
    sp80 = temp_fv1 * arg3.z.y;
    D_xk2_80128CB8[0].y = arg0.y - sp80;
    sp7C = temp_fv1 * arg3.z.z;
    D_xk2_80128CB8[0].z = arg0.z - sp7C;

    temp_fa0 = D_xk2_80128CB0 * 0.5f * temp_fa1;
    sp78 = (arg3.y.x + arg3.x.x) * 2000.0f;
    sp74 = temp_fa0 * arg3.z.x;
    D_xk2_80128CB8[1].x = (sp78 + arg0.x) - sp74;
    sp70 = (arg3.y.y + arg3.x.y) * 2000.0f;
    sp6C = temp_fa0 * arg3.z.y;
    D_xk2_80128CB8[1].y = (sp70 + arg0.y) - sp6C;
    sp68 = (arg3.y.z + arg3.x.z) * 2000.0f;
    sp64 = temp_fa0 * arg3.z.z;
    D_xk2_80128CB8[1].z = (sp68 + arg0.z) - sp64;

    sp60 = 2.0f * arg3.y.x * 2000.0f;
    D_xk2_80128CB8[2].x = sp60 + arg0.x;
    sp5C = 2.0f * arg3.y.y * 2000.0f;
    D_xk2_80128CB8[2].y = sp5C + arg0.y;
    sp58 = 2.0f * arg3.y.z * 2000.0f;
    D_xk2_80128CB8[2].z = sp58 + arg0.z;
    D_xk2_80128CB8[3].x = ((arg3.y.x - arg3.x.x) * 2000.0f) + arg0.x + sp74;
    D_xk2_80128CB8[3].y = ((arg3.y.y - arg3.x.y) * 2000.0f) + arg0.y + sp6C;
    D_xk2_80128CB8[3].z = ((arg3.y.z - arg3.x.z) * 2000.0f) + arg0.z + sp64;
    // Need to figure out 0.0f here
    sp54 = (0.0f * arg3.z.x) + arg0.x;
    D_xk2_80128CB8[4].x = sp54 + sp84;
    sp50 = (0.0f * arg3.z.y) + arg0.y;
    D_xk2_80128CB8[4].y = sp50 + sp80;
    sp4C = (0.0f * arg3.z.z) + arg0.z;
    D_xk2_80128CB8[4].z = sp4C + sp7C;
    if (func_xk2_800EFFF0() == 0) {
        return 0;
    }
    D_xk2_80128CF4 = 1;
    temp_fa1 = D_xk2_80128CB4 + 150.0f;
    temp_fv1 = temp_fa1 * D_xk2_80128CB0;

    sp84 = temp_fv1 * arg3.z.x;
    D_xk2_80128CB8[0].x = arg0.x - sp84;
    sp80 = temp_fv1 * arg3.z.y;
    D_xk2_80128CB8[0].y = arg0.y - sp80;
    sp7C = temp_fv1 * arg3.z.z;
    D_xk2_80128CB8[0].z = arg0.z - sp7C;
    temp_fa0 = D_xk2_80128CB0 * 0.5f * temp_fa1;
    sp74 = temp_fa0 * arg3.z.x;
    D_xk2_80128CB8[1].x = (((arg3.x.x - arg3.y.x) * 2000.0f) + arg0.x) - sp74;
    sp6C = temp_fa0 * arg3.z.y;
    D_xk2_80128CB8[1].y = (((arg3.x.y - arg3.y.y) * 2000.0f) + arg0.y) - sp6C;
    sp64 = temp_fa0 * arg3.z.z;
    D_xk2_80128CB8[1].z = (((arg3.x.z - arg3.y.z) * 2000.0f) + arg0.z) - sp64;
    D_xk2_80128CB8[2].x = arg0.x - sp60;
    D_xk2_80128CB8[2].y = arg0.y - sp5C;
    D_xk2_80128CB8[2].z = arg0.z - sp58;
    D_xk2_80128CB8[3].x = (arg0.x - sp78) + sp74;
    D_xk2_80128CB8[3].y = (arg0.y - sp70) + sp6C;
    D_xk2_80128CB8[3].z = (arg0.z - sp68) + sp64;
    D_xk2_80128CB8[4].x = sp54 + sp84;
    D_xk2_80128CB8[4].y = sp50 + sp80;
    D_xk2_80128CB8[4].z = sp4C + sp7C;
    if (func_xk2_800EFFF0() == 0) {
        return 0;
    }
    return -1;
}
#else
#pragma GLOBAL_ASM("asm/jp/ek/nonmatchings/overlays/course_edit/1A1240/func_xk2_800F01C4.s")
#endif

f32 func_xk2_800F05C0(CourseSegment* arg0, Vec3f arg1) {
    f32 var_fv1;
    f32 sp58;
    f32 sp54;
    s32 pad;
    Vec3f sp44;
    Mtx3F sp20;

    sp58 = Course_SplineGetLengthInfo(arg0, 0.0f, &sp54);
    Course_SplineGetBasis(arg0, 0.0f, &sp20, sp58);
    sp44.x = (arg1.y * sp20.x.z) - (arg1.z * sp20.x.y);
    sp44.y = (arg1.z * sp20.x.x) - (arg1.x * sp20.x.z);
    sp44.z = (arg1.x * sp20.x.y) - (arg1.y * sp20.x.x);
    Math_VectorSetScale(&sp44, 1.0f);
    arg1.x = (sp44.z * sp20.x.y) - (sp44.y * sp20.x.z);
    arg1.y = (sp44.x * sp20.x.z) - (sp44.z * sp20.x.x);
    arg1.z = (sp44.y * sp20.x.x) - (sp44.x * sp20.x.y);
    Math_VectorSetScale(&arg1, 1.0f);
    var_fv1 = func_xk2_800EF52C((arg0->up.x * arg1.x) + (arg0->up.y * arg1.y) + (arg0->up.z * arg1.z));
    sp44.x = (arg0->up.z * sp20.x.y) - (arg0->up.y * sp20.x.z);
    sp44.y = (arg0->up.x * sp20.x.z) - (arg0->up.z * sp20.x.x);
    sp44.z = (arg0->up.y * sp20.x.x) - (arg0->up.x * sp20.x.y);
    Math_VectorSetScale(&sp44, 1.0f);

    if (((sp44.x * arg1.x) + (sp44.y * arg1.y) + (sp44.z * arg1.z)) < 0.0f) {
        var_fv1 = 360.0f - var_fv1;
    }
    return var_fv1;
}

extern s32 gCreateOption;
extern s32 gDesignStyleOption;
extern CourseInfo* gCurrentCourseInfo;

void func_xk2_800F07A4(void) {
    s32 i;
    s32 sp1C0;
    f32 sp1BC;
    CourseSegment* temp_s2;
    s32 pad[3];
    CourseSegment sp108;
    Vec3f spFC;
    Vec3f spF0;
    Mtx3F spCC;

    if ((gCourseEditCursorYPos < 0x38) || (D_800D6CA0.unk_08 == 1) || (D_800D6CA0.unk_08 == 3) ||
        (D_800D6CA0.unk_08 == 2) || (D_800D6CA0.unk_08 == 0x10) ||
        !((gCreateOption == CREATE_OPTION_DESIGN) && (gDesignStyleOption == TRACK_DESIGN_STYLE_LOOP)) ||
        !(gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) || (D_800D6CA0.unk_0C == 0)) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }
    if (D_802CB6D0.controlPointCount >= 60) {
        Audio_TriggerSystemSE(NA_SE_32);
        return;
    }
    if (gCurrentCourseInfo->length > 300000.0f) {
        Audio_TriggerSystemSE(NA_SE_32);
        return;
    }
    func_xk2_800EF78C();
    Audio_TriggerSystemSE(NA_SE_39);
    sp1C0 = D_800D6CA0.unk_0C;
    temp_s2 = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];

    D_xk2_80128CB4 = (temp_s2->radiusLeft + temp_s2->radiusRight) * 0.5f;
    Course_SplineGetBasis(temp_s2, 0.0f, &spCC, Course_SplineGetLengthInfo(temp_s2, 0.0f, &sp1BC));
    spFC.x = temp_s2->next->pos.x - temp_s2->pos.x;
    spFC.y = temp_s2->next->pos.y - temp_s2->pos.y;
    spFC.z = temp_s2->next->pos.z - temp_s2->pos.z;

    sqrtf(SQ(spFC.x) + SQ(spFC.y) + SQ(spFC.z));
    Math_VectorSetScale(&spFC, 1.0f);
    if (((spFC.x * spCC.z.x) + (spFC.y * spCC.z.y) + (spFC.z * spCC.z.z)) > 0.0f) {
        D_xk2_80128CB0 = 1.0f;
    } else {
        D_xk2_80128CB0 = -1.0f;
    }
    if (1) {}
    Course_SplineGetPosition(temp_s2, 0.5f, &spF0);
    Course_SplineGetBasis(temp_s2, 0.5f, &spCC, Course_SplineGetLengthInfo(temp_s2, 0.5f, &sp1BC));

    if (func_xk2_800F01C4(spF0, spCC) != 0) {
        Audio_TriggerSystemSE(NA_SE_32);
        return;
    }
    sp108.radiusLeft = temp_s2->radiusLeft;
    sp108.radiusRight = temp_s2->radiusRight;
    // clang-format off
    sp108.up.x = 0;    \
    sp108.up.y = 1.0f; \
    sp108.up.z = 0;
    // clang-format on
    sp108.trackSegmentInfo = temp_s2->trackSegmentInfo;

    for (i = 0; i < 5; i++) {
        sp108.pos = D_xk2_80128CB8[i];
        func_xk2_800E6CA8(D_800D6CA0.unk_0C, sp108);
        COURSE_CONTEXT()->courseData.bankAngle[D_800D6CA0.unk_0C] = 0;
    }
    func_i2_800BE8BC(gCurrentCourseInfo);
    temp_s2 = D_802CB6D0.unk_0000[sp1C0].next;
    func_80074CE4(gCurrentCourseInfo);
    if (D_xk2_80128CF4 != 0) {
        spFC.x = spCC.y.x;
        spFC.y = spCC.y.y;
        spFC.z = spCC.y.z;
        COURSE_CONTEXT()->courseData.bankAngle[temp_s2->segmentIndex] = func_xk2_800F05C0(temp_s2, spFC);
        temp_s2 = temp_s2->next;
        // clang-format off
        spFC.x = spCC.x.x; \
        spFC.y = spCC.x.y; \
        spFC.z = spCC.x.z;
        // clang-format on
        COURSE_CONTEXT()->courseData.bankAngle[temp_s2->segmentIndex] = func_xk2_800F05C0(temp_s2, spFC);
        temp_s2 = temp_s2->next;
        spFC.x = -1.0f * spCC.y.x;
        spFC.y = -1.0f * spCC.y.y;
        spFC.z = -1.0f * spCC.y.z;
        COURSE_CONTEXT()->courseData.bankAngle[temp_s2->segmentIndex] = func_xk2_800F05C0(temp_s2, spFC);
        temp_s2 = temp_s2->next;
        spFC.x = -1.0f * spCC.x.x;
        spFC.y = -1.0f * spCC.x.y;
        spFC.z = -1.0f * spCC.x.z;
        COURSE_CONTEXT()->courseData.bankAngle[temp_s2->segmentIndex] = func_xk2_800F05C0(temp_s2, spFC);
        temp_s2 = temp_s2->next;
        // clang-format off
        spFC.x = spCC.y.x; \
        spFC.y = spCC.y.y; \
        spFC.z = spCC.y.z;
        // clang-format on
        COURSE_CONTEXT()->courseData.bankAngle[temp_s2->segmentIndex] = func_xk2_800F05C0(temp_s2, spFC);
    } else {
        spFC.x = spCC.y.x;
        spFC.y = spCC.y.y;
        spFC.z = spCC.y.z;
        COURSE_CONTEXT()->courseData.bankAngle[temp_s2->segmentIndex] = func_xk2_800F05C0(temp_s2, spFC);
        temp_s2 = temp_s2->next;
        spFC.x = -1.0f * spCC.x.x;
        spFC.y = -1.0f * spCC.x.y;
        spFC.z = -1.0f * spCC.x.z;
        COURSE_CONTEXT()->courseData.bankAngle[temp_s2->segmentIndex] = func_xk2_800F05C0(temp_s2, spFC);
        temp_s2 = temp_s2->next;
        spFC.x = -1.0f * spCC.y.x;
        spFC.y = -1.0f * spCC.y.y;
        spFC.z = -1.0f * spCC.y.z;
        COURSE_CONTEXT()->courseData.bankAngle[temp_s2->segmentIndex] = func_xk2_800F05C0(temp_s2, spFC);
        temp_s2 = temp_s2->next;
        // clang-format off
        spFC.x = spCC.x.x; \
        spFC.y = spCC.x.y; \
        spFC.z = spCC.x.z;
        // clang-format on
        COURSE_CONTEXT()->courseData.bankAngle[temp_s2->segmentIndex] = func_xk2_800F05C0(temp_s2, spFC);
        temp_s2 = temp_s2->next;
        // clang-format off
        spFC.x = spCC.y.x; \
        spFC.y = spCC.y.y; \
        spFC.z = spCC.y.z;
        // clang-format on
        COURSE_CONTEXT()->courseData.bankAngle[temp_s2->segmentIndex] = func_xk2_800F05C0(temp_s2, spFC);
    }
    D_xk2_800F7040 = 3;
}

void func_xk2_800F0FE8(void) {
    D_xk2_80104BC0 = 0;
}

extern CourseData D_8010C770;
extern CourseSegment D_xk2_80119920[];

void func_xk2_800F0FF4(void) {
    s32 i;
    s32 temp_a0;
    s32 temp_a2;
    CourseSegment* var_v1;

    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }

    var_v1 = &D_802CB6D0.unk_0000[1];
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        temp_a0 = var_v1->segmentIndex;
        D_8010C770.bankAngle[i] = 360 - COURSE_CONTEXT()->courseData.bankAngle[temp_a0];

        temp_a2 = var_v1->prev->segmentIndex;
        D_8010C770.pit[i] = COURSE_CONTEXT()->courseData.pit[temp_a2];
        D_8010C770.dash[i] = COURSE_CONTEXT()->courseData.dash[temp_a2];
        D_8010C770.dirt[i] = COURSE_CONTEXT()->courseData.dirt[temp_a2];
        D_8010C770.ice[i] = COURSE_CONTEXT()->courseData.ice[temp_a2];
        D_8010C770.jump[i] = COURSE_CONTEXT()->courseData.jump[temp_a2];
        D_8010C770.landmine[i] = COURSE_CONTEXT()->courseData.landmine[temp_a2];
        D_8010C770.gate[i] = COURSE_CONTEXT()->courseData.gate[temp_a0];
        D_8010C770.building[i] = COURSE_CONTEXT()->courseData.building[temp_a0];
        D_8010C770.sign[i] = COURSE_CONTEXT()->courseData.sign[temp_a0];
        D_xk2_80119920[i] = D_802CB6D0.unk_0000[temp_a0];

        D_xk2_80119920[i].trackSegmentInfo = var_v1->prev->trackSegmentInfo;
        var_v1 = var_v1->prev;
    }
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        D_802CB6D0.unk_0000[i] = D_xk2_80119920[i];

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

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        D_802CB6D0.unk_0000[i].segmentIndex = i;
        D_802CB6D0.unk_0000[i].next = &D_802CB6D0.unk_0000[i + 1];
        D_802CB6D0.unk_0000[i].prev = &D_802CB6D0.unk_0000[i - 1];
    }
    D_802CB6D0.unk_0000[0].prev = &D_802CB6D0.unk_0000[D_802CB6D0.controlPointCount - 1];
    D_802CB6D0.unk_0000[D_802CB6D0.controlPointCount - 1].next = &D_802CB6D0.unk_0000[0];

    PRINTF("BACKUP\n");
    PRINTF("EFFECT c\n");
    PRINTF("edit_mode %d\n");
    PRINTF("STRAIGHT LOOP\n");
    PRINTF("points %d\n");
    PRINTF("%f, %f, %f\n");
    PRINTF("BUBU 00\n");
    PRINTF("BUBU 01\n");
    PRINTF("IF DO STRAIGHT, POINTS NEAR!!\n");
    PRINTF("max %d\n");
    PRINTF("from %d to %d\n");
    PRINTF("LEFT\n");
    PRINTF("RIGHT\n");
    PRINTF("BUBU 02\n");
}
