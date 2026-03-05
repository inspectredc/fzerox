#include "global.h"

void func_xk2_800F2560(Vec3f arg0, Vec3f arg1, Vec3f arg2) {
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 pad;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    temp_fv0 = arg2.x - arg1.x;
    temp_fv1 = arg2.y - arg1.y;
    temp_fa1 = arg2.z - arg1.z;

    temp_ft4 = ((temp_fv0 * (arg0.x - arg1.x)) + (temp_fv1 * (arg0.y - arg1.y)) + (temp_fa1 * (arg0.z - arg1.z))) /
               (SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa1));
    sp3C = ((temp_fv0 * temp_ft4) + arg1.x) - arg0.x;
    sp38 = ((temp_fv1 * temp_ft4) + arg1.y) - arg0.y;
    sp34 = ((temp_fa1 * temp_ft4) + arg1.z) - arg0.z;
    sqrtf(SQ(sp3C) + SQ(sp38) + SQ(sp34));
}

Vec3f* func_xk2_800F267C(Vec3f* arg0, Vec3f arg1, Vec3f arg2, Vec3f arg3) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 pad[4];
    Vec3f sp14;

    temp_fv0 = arg3.x - arg2.x;
    temp_fv1 = arg3.y - arg2.y;
    temp_fa0 = arg3.z - arg2.z;
    temp_fa1 = ((temp_fv0 * (arg1.x - arg2.x)) + (temp_fv1 * (arg1.y - arg2.y)) + (temp_fa0 * (arg1.z - arg2.z))) /
               (SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa0));
    sp14.x = (temp_fv0 * temp_fa1) + arg2.x;
    sp14.y = (temp_fv1 * temp_fa1) + arg2.y;
    sp14.z = (temp_fa0 * temp_fa1) + arg2.z;
    *arg0 = sp14;

    return arg0;
}
