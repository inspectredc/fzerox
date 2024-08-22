#include "global.h"

#define VERTEX_MODIFIED_ST(s, t) ((((s) << 15) & 0xFFFF0000) | ((t) &0xFFFF))

typedef struct unk_800CF528 {
    s32 texture;
    f32 unk_04;
    s32 width;
    s32 tile;
    s32 unk_10;
    s8 unk_14[0x2];
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
    s16 unk_1C;
    s16 unk_1E;
} unk_800CF528; // size = 0x20

typedef struct unk_800F8958 {
    unk_36ED0* unk_00;
    Gfx* unk_04;
    Gfx* unk_08;
    Gfx* unk_0C;
    Gfx* unk_10;
    Gfx* unk_14;
    Gfx* unk_18;
    Gfx* unk_1C;
    Gfx* unk_20;
    Gfx* unk_24;
    Gfx* unk_28;
    s32 unk_2C;
} unk_800F8958; // size = 0x30

extern unk_800CF528 D_800CF528[];
extern unk_800CF528 D_800CF868[];
extern f32 D_800CF60C;

void func_8009CED0(u32 arg0) {
    switch (arg0) {
        case 0:
            D_800CF528[2].unk_04 = D_800CF528[3].unk_04 = D_800CF528[4].unk_04 = D_800CF528[5].unk_04 =
                D_800CF528[6].unk_04 = 16.0f;
            D_800CF868[0].unk_04 = 14.0f;
            D_800CF60C = 7.0f;
            break;
        case 2:
            D_800CF528[2].unk_04 = D_800CF528[3].unk_04 = 14.0f;
            D_800CF528[5].unk_04 = 1.0f;
            D_800CF868[0].unk_04 = 1.0f;
            D_800CF528[4].unk_04 = 2.0f;
            D_800CF528[6].unk_04 = 6.0f;
            D_800CF60C = 7.0f;
            break;
        case 4:
            D_800CF528[2].unk_04 = D_800CF528[3].unk_04 = D_800CF528[4].unk_04 = D_800CF528[5].unk_04 =
                D_800CF528[6].unk_04 = D_800CF868[0].unk_04 = 14.0f;
            D_800CF60C = 3.5f;
            break;
        case 6:
            D_800CF868[0].unk_04 = 7.0f;
            D_800CF528[4].unk_04 = 5.0f;
            D_800CF528[2].unk_04 = D_800CF528[3].unk_04 = D_800CF528[5].unk_04 = D_800CF528[6].unk_04 = 10.0f;
            D_800CF60C = 3.5f;
            break;
        case 7:
            D_800CF528[2].unk_04 = D_800CF528[3].unk_04 = D_800CF528[4].unk_04 = D_800CF528[5].unk_04 =
                D_800CF528[6].unk_04 = D_800CF868[0].unk_04 = 14.0f;
            D_800CF60C = 3.5f;
            break;
        case 9:
            D_800CF528[2].unk_04 = D_800CF528[3].unk_04 = D_800CF528[5].unk_04 = D_800CF528[6].unk_04 =
                D_800CF868[0].unk_04 = 14.0f;
            D_800CF528[4].unk_04 = 7.0f;
            D_800CF60C = 7.0f;
            break;
        case 10:
            D_800CF528[2].unk_04 = D_800CF528[3].unk_04 = D_800CF528[4].unk_04 = D_800CF528[5].unk_04 =
                D_800CF528[6].unk_04 = 5.5f;
            D_800CF868[0].unk_04 = 14.0f;
            D_800CF60C = 7.0f;
            break;
        default:
            D_800CF528[2].unk_04 = D_800CF528[3].unk_04 = D_800CF528[4].unk_04 = D_800CF528[5].unk_04 =
                D_800CF528[6].unk_04 = D_800CF868[0].unk_04 = 14.0f;
            D_800CF60C = 7.0f;
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/36ED0/func_8009D16C.s")

void func_8009DB28(unk_8006FC8C*, f32*, f32*);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/36ED0/func_8009DB28.s")

s32 func_8009DEAC(unk_800F8510* arg0) {
    f32 sp4C;
    f32 sp48;
    unk_8006FC8C* var_s0 = arg0->unk_10;

    do {
        func_8009DB28(var_s0, &sp4C, &sp48);
        if ((sp4C < 0.0f) || (sp4C > 2.0f) || (sp48 < 0.0f) || (sp48 > 2.0f)) {
            return -1;
        }
        var_s0->unk_24 = (sp4C + sp48) * 0.5f;
        var_s0 = var_s0->unk_34;
    } while (var_s0 != arg0->unk_10);

    return 0;
}

f32 func_8009DFA0(unk_802C4920_unk_C* arg0) {
    f32 var_fv1;
    f32 var_ft4;
    f32 var_fa1;
    f32 var_fv0;

    if (arg0->unk_04 < 0.5f) {
        if (arg0->unk_04 < 0.25f) {
            var_fv1 = 0.0f;
            var_fv0 = arg0->unk_1C.x - arg0->unk_00->unk_00.x;
            var_fa1 = arg0->unk_1C.y - arg0->unk_00->unk_00.y;
            var_ft4 = arg0->unk_1C.z - arg0->unk_00->unk_00.z;
        } else {
            var_fv1 = arg0->unk_00->unk_98;
            var_fv0 = arg0->unk_1C.x - arg0->unk_00->unk_74.x;
            var_fa1 = arg0->unk_1C.y - arg0->unk_00->unk_74.y;
            var_ft4 = arg0->unk_1C.z - arg0->unk_00->unk_74.z;
        }
    } else if (arg0->unk_04 < 0.75f) {
        var_fv1 = arg0->unk_00->unk_9C;
        var_fv0 = arg0->unk_1C.x - arg0->unk_00->unk_80.x;
        var_fa1 = arg0->unk_1C.y - arg0->unk_00->unk_80.y;
        var_ft4 = arg0->unk_1C.z - arg0->unk_00->unk_80.z;
    } else {
        var_fv1 = arg0->unk_00->unk_A0;
        var_fv0 = arg0->unk_1C.x - arg0->unk_00->unk_8C.x;
        var_fa1 = arg0->unk_1C.y - arg0->unk_00->unk_8C.y;
        var_ft4 = arg0->unk_1C.z - arg0->unk_00->unk_8C.z;
    }

    var_fv1 += sqrtf(SQ(var_fv0) + SQ(var_fa1) + SQ(var_ft4));
    arg0->unk_08 = var_fv1 / arg0->unk_00->unk_28;
    return arg0->unk_00->unk_2C + var_fv1;
}

f32 func_8009E108(unk_8006FC8C* arg0, f32 arg1, f32* arg2) {
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 var_fs0;
    f32 temp_fs2;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 square;
    f32 cube;
    f32 spB4;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 spA4;
    Vec3f sp98;
    Vec3f sp8C;
    unk_8006FC8C* temp_s0 = arg0->unk_34;
    unk_8006FC8C* temp_s1 = arg0->unk_38;
    unk_8006FC8C* temp_s2 = temp_s0->unk_34;

    spDC = arg0->unk_24;
    spD8 = spDC - 2.0f;
    spD4 = spDC - 3.0f;
    spD0 = 3.0f - (2.0f * spDC);
    *arg2 = 0.0f;
    if (arg1 < 0.5f) {
        var_fs0 = 0.0f;
        spB4 = arg1;
    } else {
        var_fs0 = arg1;
        spB4 = 1.0f;
    }

    square = SQ(var_fs0);
    cube = square * var_fs0;
    temp_fa0 = (2.0f * square - var_fs0 - cube) * spDC;
    temp_fa1 = spD4 * square - spD8 * cube + 1.0f;
    temp_ft4 = spD8 * cube + spD0 * square + spDC * var_fs0;
    spA4 = (cube - square) * spDC;

    sp98.x = temp_fa0 * temp_s1->unk_00.x + temp_fa1 * arg0->unk_00.x + temp_ft4 * temp_s0->unk_00.x +
             spA4 * temp_s2->unk_00.x;
    sp98.y = temp_fa0 * temp_s1->unk_00.y + temp_fa1 * arg0->unk_00.y + temp_ft4 * temp_s0->unk_00.y +
             spA4 * temp_s2->unk_00.y;
    sp98.z = temp_fa0 * temp_s1->unk_00.z + temp_fa1 * arg0->unk_00.z + temp_ft4 * temp_s0->unk_00.z +
             spA4 * temp_s2->unk_00.z;

    while (var_fs0 < spB4) {
        var_fs0 += 0.05f;
        if (spB4 < var_fs0) {
            var_fs0 = spB4;
        }

        square = SQ(var_fs0);
        cube = square * var_fs0;
        temp_fa0 = (2.0f * square - var_fs0 - cube) * spDC;
        temp_fa1 = spD4 * square - spD8 * cube + 1.0f;
        temp_ft4 = spD8 * cube + spD0 * square + spDC * var_fs0;
        spA4 = (cube - square) * spDC;

        sp8C.x = (temp_s1->unk_00.x * temp_fa0) + (temp_fa1 * arg0->unk_00.x) + (temp_ft4 * temp_s0->unk_00.x) +
                 (spA4 * temp_s2->unk_00.x);
        temp_fs2 = sp8C.x - sp98.x;
        sp8C.y = (temp_s1->unk_00.y * temp_fa0) + (temp_fa1 * arg0->unk_00.y) + (temp_ft4 * temp_s0->unk_00.y) +
                 (spA4 * temp_s2->unk_00.y);
        temp_fv0 = sp8C.y - sp98.y;
        sp8C.z = (temp_s1->unk_00.z * temp_fa0) + (temp_fa1 * arg0->unk_00.z) + (temp_ft4 * temp_s0->unk_00.z) +
                 (spA4 * temp_s2->unk_00.z);
        temp_fv1 = sp8C.z - sp98.z;

        *arg2 += sqrtf(SQ(temp_fs2) + SQ(temp_fv0) + SQ(temp_fv1));

        sp98 = sp8C;
    }

    if (arg1 >= 0.5f) {
        *arg2 = arg0->unk_28 - *arg2;
    }

    var_fs0 = *arg2 / arg0->unk_28;
    if (var_fs0 < 0.0f) {
        var_fs0 = 0.0f;
    } else if (var_fs0 > 1.0f) {
        var_fs0 = 1.0f;
    }
    *arg2 += arg0->unk_2C;
    return var_fs0;
}

f32 func_8009E538(unk_8006FC8C* arg0, f32 arg1, Vec3f* arg2) {
    f32 square;
    f32 temp_fv0;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    unk_8006FC8C* temp_v0 = arg0->unk_34;
    unk_8006FC8C* temp_v1 = arg0->unk_38;
    unk_8006FC8C* temp_a1 = temp_v0->unk_34;

    square = SQ(arg1);
    temp_fv0 = arg0->unk_24;

    sp44 = (4.0f * arg1 - 1.0f - 3.0f * square) * temp_fv0;
    sp40 = (6.0f - 3.0f * temp_fv0) * square + (2.0f * temp_fv0 - 6.0f) * arg1;
    sp3C = (3.0f * temp_fv0 - 6.0f) * square + (6.0f - 4.0f * temp_fv0) * arg1 + temp_fv0;
    sp38 = (3.0f * square - 2.0f * arg1) * temp_fv0;

    arg2->x = sp44 * temp_v1->unk_00.x + sp40 * arg0->unk_00.x + sp3C * temp_v0->unk_00.x + sp38 * temp_a1->unk_00.x;
    arg2->y = sp44 * temp_v1->unk_00.y + sp40 * arg0->unk_00.y + sp3C * temp_v0->unk_00.y + sp38 * temp_a1->unk_00.y;
    arg2->z = sp44 * temp_v1->unk_00.z + sp40 * arg0->unk_00.z + sp3C * temp_v0->unk_00.z + sp38 * temp_a1->unk_00.z;

    return sqrtf(SQ(arg2->x) + SQ(arg2->y) + SQ(arg2->z));
}

void func_8009E6F0(unk_8006FC8C* arg0, f32 arg1, Vec3f* arg2) {
    f32 temp_fv0;
    f32 square;
    f32 cube;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    unk_8006FC8C* temp_v0 = arg0->unk_38;
    unk_8006FC8C* temp_v1 = arg0->unk_34;
    unk_8006FC8C* temp_a1 = temp_v1->unk_34;

    temp_fv0 = arg0->unk_24;
    square = SQ(arg1);
    cube = square * arg1;
    sp30 = (2.0f * square - arg1 - cube) * temp_fv0;
    sp2C = (2.0f - temp_fv0) * cube + (temp_fv0 - 3.0f) * square + 1.0f;
    sp28 = (temp_fv0 - 2.0f) * cube + (3.0f - 2.0f * temp_fv0) * square + temp_fv0 * arg1;
    sp24 = (cube - square) * temp_fv0;

    arg2->x = sp30 * temp_v0->unk_00.x + sp2C * arg0->unk_00.x + sp28 * temp_v1->unk_00.x + sp24 * temp_a1->unk_00.x;
    arg2->y = sp30 * temp_v0->unk_00.y + sp2C * arg0->unk_00.y + sp28 * temp_v1->unk_00.y + sp24 * temp_a1->unk_00.y;
    arg2->z = sp30 * temp_v0->unk_00.z + sp2C * arg0->unk_00.z + sp28 * temp_v1->unk_00.z + sp24 * temp_a1->unk_00.z;
}

f32 func_8009E85C(unk_8006FC8C* arg0, f32 arg1, Mtx3F* arg2, f32 arg3) {
    f32 temp_fa0;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    unk_8006FC8C* temp_v0 = arg0->unk_34;
    unk_8006FC8C* temp_v1 = arg0->unk_38;
    unk_8006FC8C* temp_a1 = temp_v0->unk_34;

    temp_fa0 = arg0->unk_24;
    sp50 = SQ(arg1);
    sp4C = (4.0f * arg1 - 1.0f - 3.0f * sp50) * temp_fa0;
    sp48 = (6.0f - 3.0f * temp_fa0) * sp50 + (2.0f * temp_fa0 - 6.0f) * arg1;
    sp44 = (3.0f * temp_fa0 - 6.0f) * sp50 + (6.0f - 4.0f * temp_fa0) * arg1 + temp_fa0;
    sp40 = (3.0f * sp50 - 2.0f * arg1) * temp_fa0;

    arg2->xx = sp4C * temp_v1->unk_00.x + sp48 * arg0->unk_00.x + sp44 * temp_v0->unk_00.x + sp40 * temp_a1->unk_00.x;
    arg2->yx = sp4C * temp_v1->unk_00.y + sp48 * arg0->unk_00.y + sp44 * temp_v0->unk_00.y + sp40 * temp_a1->unk_00.y;
    arg2->zx = sp4C * temp_v1->unk_00.z + sp48 * arg0->unk_00.z + sp44 * temp_v0->unk_00.z + sp40 * temp_a1->unk_00.z;

    sp50 = sqrtf(SQ(arg2->xx) + SQ(arg2->yx) + SQ(arg2->zx));
    temp_fa0 = 1.0f / sp50;

    arg2->xx *= temp_fa0;
    arg2->yx *= temp_fa0;
    arg2->zx *= temp_fa0;

    arg2->xy = (arg0->unk_34->unk_0C.x - arg0->unk_0C.x) * arg3 + arg0->unk_0C.x;
    arg2->yy = (arg0->unk_34->unk_0C.y - arg0->unk_0C.y) * arg3 + arg0->unk_0C.y;
    arg2->zy = (arg0->unk_34->unk_0C.z - arg0->unk_0C.z) * arg3 + arg0->unk_0C.z;

    arg2->xz = arg2->yy * arg2->zx - arg2->zy * arg2->yx;
    arg2->yz = arg2->zy * arg2->xx - arg2->xy * arg2->zx;
    arg2->zz = arg2->xy * arg2->yx - arg2->yy * arg2->xx;

    temp_fa0 = 1.0f / sqrtf(SQ(arg2->xz) + SQ(arg2->yz) + SQ(arg2->zz));

    arg2->xz *= temp_fa0;
    arg2->yz *= temp_fa0;
    arg2->zz *= temp_fa0;

    arg2->xy = arg2->yx * arg2->zz - arg2->zx * arg2->yz;
    arg2->yy = arg2->zx * arg2->xz - arg2->xx * arg2->zz;
    arg2->zy = arg2->xx * arg2->yz - arg2->yx * arg2->xz;

    return sp50;
}

s32 func_8009EBEC(unk_802C4920_unk_C* arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, f32 arg5) {
    s32 i;
    Vec3f spD0;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 spBC;
    f32 temp_fa0;
    f32 spB4;
    s32 pad;
    f32 sp78;
    f32 var_fs3;
    f32 var_fs5;
    f32 square;
    f32 temp_fv1;
    unk_8006FC8C* var_s1;
    unk_8006FC8C* var_s2;
    unk_8006FC8C* var_s3;
    unk_8006FC8C* var_s4;

    spD0.x = arg1 - arg0->unk_44.x;
    spD0.y = arg2 - arg0->unk_44.y;
    spD0.z = arg3 - arg0->unk_44.z;

    i = arg4 - 1;

    var_s3 = arg0->unk_00;
    var_s4 = var_s3->unk_34;
    var_s1 = var_s3->unk_38;
    var_s2 = var_s4->unk_34;

    var_fs3 = var_s3->unk_24;
    var_fs5 = var_fs3 - 2.0f;

    spBC = ((var_fs5 - 1.0f) + var_fs3) - 3.0f;
    sp78 = spBC + var_fs3;

    spB4 = sp78 + var_fs3;
    while ((arg5 < (SQ_SUM(&spD0))) && (i != 0)) {

        arg0->unk_04 += DOT_XYZ(&spD0, &arg0->unk_0C) / SQ(arg0->unk_18);

        if (arg0->unk_04 >= 1.0f) {
            if (arg0->unk_04 > 1.9f) {
                return -1;
            }
            arg0->unk_00 = arg0->unk_00->unk_34;
            var_s1 = var_s3;
            var_s3 = var_s4;
            var_s4 = var_s2;
            var_s2 = arg0->unk_00->unk_34->unk_34;
            var_fs3 = arg0->unk_00->unk_24;

            var_fs5 = var_fs3 - 2.0f;

            spBC = ((var_fs5 - 1.0f) + var_fs3) - 3.0f;
            sp78 = spBC + var_fs3;

            spB4 = sp78 + var_fs3;
            arg0->unk_04 -= 1.0f;

            arg0->unk_04 *= arg0->unk_18 / func_8009E538(arg0->unk_00, 0.0f, &spD0);
        } else if (arg0->unk_04 < 0.0f) {
            if (arg0->unk_04 < -0.9f) {
                return -1;
            }
            arg0->unk_00 = arg0->unk_00->unk_38;
            var_s2 = var_s4;
            var_s4 = var_s3;
            var_s3 = var_s1;
            var_s1 = arg0->unk_00->unk_38;
            var_fs3 = arg0->unk_00->unk_24;

            var_fs5 = var_fs3 - 2.0f;

            spBC = ((var_fs5 - 1.0f) + var_fs3) - 3.0f;
            sp78 = spBC + var_fs3;
            spB4 = sp78 + var_fs3;

            arg0->unk_04 *= arg0->unk_18 / func_8009E538(arg0->unk_00, 1.0f, &spD0);
            arg0->unk_04 += 1.0f;
        }

        square = SQ(arg0->unk_04);
        // FAKE
        temp_fv1 = arg0->unk_04 * (0, square);
        temp_ft4 = (((2.0f * square) - arg0->unk_04) - temp_fv1) * var_fs3;
        temp_ft5 = (((var_fs5 - 1.0f) * square) - var_fs5 * temp_fv1) + 1.0f;
        temp_fs1 = (var_fs5 * temp_fv1 - (((var_fs5 - 1.0f) + var_fs3) * square)) + (var_fs3 * arg0->unk_04);
        temp_fs2 = (temp_fv1 - square) * var_fs3;

        arg0->unk_1C.x = (temp_ft4 * var_s1->unk_00.x) + (temp_ft5 * var_s3->unk_00.x) + (temp_fs1 * var_s4->unk_00.x) +
                         (temp_fs2 * var_s2->unk_00.x);
        arg0->unk_1C.y = (temp_ft4 * var_s1->unk_00.y) + (temp_ft5 * var_s3->unk_00.y) + (temp_fs1 * var_s4->unk_00.y) +
                         (temp_fs2 * var_s2->unk_00.y);
        arg0->unk_1C.z = (temp_ft4 * var_s1->unk_00.z) + (temp_ft5 * var_s3->unk_00.z) + (temp_fs1 * var_s4->unk_00.z) +
                         (temp_fs2 * var_s2->unk_00.z);

        temp_fv1 = 3.0f * square;
        temp_ft4 = (((arg0->unk_04 * 4.0f) - 1.0f) - temp_fv1) * var_fs3;
        temp_ft5 = (arg0->unk_04 * spBC) - sp78 * square;
        temp_fs1 = (sp78 * square - (spB4 * arg0->unk_04)) + var_fs3;
        temp_fs2 = (temp_fv1 - (2.0f * arg0->unk_04)) * var_fs3;

        arg0->unk_0C.x = (temp_ft4 * var_s1->unk_00.x) + (temp_ft5 * var_s3->unk_00.x) + (temp_fs1 * var_s4->unk_00.x) +
                         (temp_fs2 * var_s2->unk_00.x);
        arg0->unk_0C.y = (temp_ft4 * var_s1->unk_00.y) + (temp_ft5 * var_s3->unk_00.y) + (temp_fs1 * var_s4->unk_00.y) +
                         (temp_fs2 * var_s2->unk_00.y);
        arg0->unk_0C.z = (temp_ft4 * var_s1->unk_00.z) + (temp_ft5 * var_s3->unk_00.z) + (temp_fs1 * var_s4->unk_00.z) +
                         (temp_fs2 * var_s2->unk_00.z);

        arg0->unk_18 = sqrtf(SQ_SUM(&arg0->unk_0C));
        arg0->unk_28.x = arg1 - arg0->unk_1C.x;
        arg0->unk_28.y = arg2 - arg0->unk_1C.y;
        arg0->unk_28.z = arg3 - arg0->unk_1C.z;
        arg0->unk_40 = sqrtf(SQ_SUM(&arg0->unk_28));

        if (arg0->unk_40 < 0.001f) {
            break;
        }

        arg0->unk_34.x = CROSS_X(&arg0->unk_28, &arg0->unk_0C);
        arg0->unk_34.y = CROSS_Y(&arg0->unk_28, &arg0->unk_0C);
        arg0->unk_34.z = CROSS_Z(&arg0->unk_28, &arg0->unk_0C);

        arg0->unk_28.x = CROSS_X(&arg0->unk_0C, &arg0->unk_34);
        arg0->unk_28.y = CROSS_Y(&arg0->unk_0C, &arg0->unk_34);
        arg0->unk_28.z = CROSS_Z(&arg0->unk_0C, &arg0->unk_34);

        temp_fa0 = arg0->unk_40 / sqrtf(SQ_SUM(&arg0->unk_28));

        arg0->unk_28.x *= temp_fa0;
        arg0->unk_44.x = temp_fv1 = arg0->unk_28.x + arg0->unk_1C.x;
        spD0.x = arg1 - arg0->unk_44.x;

        arg0->unk_28.y *= temp_fa0;
        arg0->unk_44.y = temp_fv1 = arg0->unk_28.y + arg0->unk_1C.y;
        spD0.y = arg2 - arg0->unk_44.y;

        arg0->unk_28.z *= temp_fa0;
        arg0->unk_44.z = temp_fv1 = arg0->unk_28.z + arg0->unk_1C.z;
        spD0.z = arg3 - arg0->unk_44.z;

        i--;
    }

    arg0->unk_28.x = arg1 - arg0->unk_1C.x;
    arg0->unk_28.y = arg2 - arg0->unk_1C.y;
    arg0->unk_28.z = arg3 - arg0->unk_1C.z;

    arg0->unk_34.x = arg1;
    arg0->unk_34.y = arg2;
    arg0->unk_34.z = arg3;
    arg0->unk_40 = sqrtf(SQ_SUM(&arg0->unk_28));

    return 0;
}

s32 func_8009F334(unk_800F8510* arg0) {
    unk_8006FC8C* var_s0 = arg0->unk_10;
    Mtx3F sp30;

    do {
        sp30.xy = var_s0->unk_0C.x;
        sp30.yy = var_s0->unk_0C.y;
        sp30.zy = var_s0->unk_0C.z;
        func_8009E538(var_s0, 0.0f, &sp30.x);
        if (func_8006AA38(&sp30) != 0) {
            return -1;
        }
        var_s0->unk_0C.x = sp30.xy;
        var_s0->unk_0C.y = sp30.yy;
        var_s0->unk_0C.z = sp30.zy;
        var_s0 = var_s0->unk_34;
    } while (var_s0 != arg0->unk_10);

    return 0;
}

extern f32 D_800CF8E8[];

s32 func_8009F3E0(unk_800F8510* arg0) {
    s32 var_v1 = 0;
    unk_8006FC8C* var_v0 = arg0->unk_10;

    do {
        var_v0->unk_20 &= ~0x600;
        if (var_v0->unk_20 & 0x10000000) {
            continue;
        }

        if (var_v0->unk_38->unk_20 & 0x10000000) {
            var_v0->unk_20 |= 0x200;
        }

        if (var_v0->unk_34->unk_20 & 0x10000000) {
            var_v0->unk_20 |= 0x400;
        }

        switch (var_v0->unk_20 & 0x600) {
            case 0x200:
            case 0x400:
                if (var_v0->unk_28 <= (D_800CF8E8[(u32) (var_v0->unk_20 & 0x1C0) >> 6] + 100.0f)) {
                    var_v1 = -1;
                }
                break;
            case 0x600:
                if (var_v0->unk_28 <= ((2.0f * D_800CF8E8[(u32) (var_v0->unk_20 & 0x1C0) >> 6]) + 100.0f)) {
                    var_v1 = -1;
                }
                break;
            default:
                break;
        }

    } while ((var_v0 = var_v0->unk_34) != arg0->unk_10);

    return var_v1;
}

void func_8009F508(unk_800F8510* arg0) {
    unk_8006FC8C* var_s1 = arg0->unk_10;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 cube;
    f32 square;
    f32 temp_fv1;
    f32 temp_fa1;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fv0;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    Vec3f sp9C;
    Vec3f sp90;
    s32 i;

    arg0->unk_0C = 0.0f;
    do {
        f32 temp_fs2 = var_s1->unk_24;
        unk_8006FC8C* temp_s4 = var_s1->unk_34;
        unk_8006FC8C* temp_s2 = var_s1->unk_38;
        unk_8006FC8C* temp_s3 = temp_s4->unk_34;

        spD8 = temp_fs2 - 2.0f;
        spD4 = temp_fs2 - 3.0f;
        spD0 = 3.0f - (2.0f * temp_fs2);

        sp9C = var_s1->unk_00;
        var_s1->unk_28 = 0.0f;

        for (i = 1; i <= 50; i++) {
            temp_fv1 = (f32) i / 50.0f;
            square = SQ(temp_fv1);
            cube = square * temp_fv1;
            temp_fa1 = (2.0f * square - temp_fv1 - cube) * temp_fs2;
            spB0 = (spD4 * square - spD8 * cube) + 1.0f;
            spAC = spD8 * cube + spD0 * square + temp_fs2 * temp_fv1;
            spA8 = (cube - square) * temp_fs2;

            sp90.x = temp_fa1 * temp_s2->unk_00.x + spB0 * var_s1->unk_00.x + spAC * temp_s4->unk_00.x +
                     spA8 * temp_s3->unk_00.x;
            temp_fs3 = sp90.x - sp9C.x;
            sp90.y = temp_fa1 * temp_s2->unk_00.y + spB0 * var_s1->unk_00.y + spAC * temp_s4->unk_00.y +
                     spA8 * temp_s3->unk_00.y;
            temp_fs4 = sp90.y - sp9C.y;
            sp90.z = temp_fa1 * temp_s2->unk_00.z + spB0 * var_s1->unk_00.z + spAC * temp_s4->unk_00.z +
                     spA8 * temp_s3->unk_00.z;
            temp_fv0 = sp90.z - sp9C.z;

            var_s1->unk_28 += sqrtf(SQ(temp_fs3) + SQ(temp_fs4) + SQ(temp_fv0));
            sp9C = sp90;
        }

        arg0->unk_0C += var_s1->unk_28;
        var_s1 = temp_s4;
        var_s1->unk_2C = arg0->unk_0C;
    } while (var_s1 != arg0->unk_10);
    arg0->unk_10->unk_2C = 0.0f;
    var_s1 = arg0->unk_10;
    do {
        func_8009E6F0(var_s1, 0.25f, &var_s1->unk_74);
        func_8009E6F0(var_s1, 0.5f, &var_s1->unk_80);
        func_8009E6F0(var_s1, 0.75f, &var_s1->unk_8C);
        func_8009E108(var_s1, 0.25f, &var_s1->unk_98);
        var_s1->unk_98 -= var_s1->unk_2C;
        func_8009E108(var_s1, 0.5f, &var_s1->unk_9C);
        var_s1->unk_9C -= var_s1->unk_2C;
        func_8009E108(var_s1, 0.75f, &var_s1->unk_A0);
        var_s1->unk_A0 -= var_s1->unk_2C;
        var_s1 = var_s1->unk_34;
    } while (var_s1 != arg0->unk_10);
}

f32 func_8009F87C(Mtx3F* arg0, Mtx3F* arg1, Vec3f* arg2, Vec3f* arg3) {
    f32 temp_v1;
    Vec3fFlip sp80;
    Vec3fFlip sp74;
    Vec3fFlip sp68;

    sp80.x = arg0->xy + arg1->xy;
    sp80.y = arg0->yy + arg1->yy;
    sp80.z = arg0->zy + arg1->zy;

    // normalize sp80
    if (SQ_SUM(&sp80) < 0.1f) {
        return 0.0f;
    }
    temp_v1 = 1.0f / sqrtf(SQ_SUM(&sp80));
    sp80.x *= temp_v1;
    sp80.y *= temp_v1;
    sp80.z *= temp_v1;

    // MAG(arg0->x()) * cos
    temp_v1 = DOT_XYZ(&arg0->x, &sp80);

    sp68.x = arg0->x.x - temp_v1 * sp80.x;
    sp68.y = arg0->x.y - temp_v1 * sp80.y;
    sp68.z = arg0->x.z - temp_v1 * sp80.z;

    // FAKE (Compiler Stack)
    goto dummy_label;
dummy_label:;

    // normalize sp68
    if (SQ_SUM(&sp68) < 0.1f) {
        return 0.0f;
    }
    temp_v1 = 1.0f / sqrtf(SQ_SUM(&sp68));
    sp68.x *= temp_v1;
    sp68.y *= temp_v1;
    sp68.z *= temp_v1;

    // Perpendicular and normalized vector to sp80/sp68
    sp74.x = CROSS_X(&sp80, &sp68);
    sp74.y = CROSS_Y(&sp80, &sp68);
    sp74.z = CROSS_Z(&sp80, &sp68);

    temp_v1 = DOT_XYZ(&arg1->x, &sp80);

    sp68.x = arg1->x.x - temp_v1 * sp80.x;
    sp68.y = arg1->x.y - temp_v1 * sp80.y;
    sp68.z = arg1->x.z - temp_v1 * sp80.z;

    // normalize sp68
    if (SQ_SUM(&sp68) < 0.1f) {
        return 0.0f;
    }
    temp_v1 = 1.0f / sqrtf(SQ_SUM(&sp68));
    sp68.x *= temp_v1;
    sp68.y *= temp_v1;
    sp68.z *= temp_v1;

    temp_v1 = DOT_XYZ(&sp74, &sp68);
    if ((temp_v1 < 0.1f) && (temp_v1 > -0.1f)) {
        return 0.0f;
    }

    // sp68 . (arg3 - arg2)
    temp_v1 = DIST_DOT_XYZ(&sp68, arg3, arg2) / temp_v1;

    sp80.x = sp74.x * temp_v1 + arg2->x;
    sp80.y = sp74.y * temp_v1 + arg2->y;
    sp80.z = sp74.z * temp_v1 + arg2->z;

    sp74.x = arg2->x - sp80.x;
    sp74.y = arg2->y - sp80.y;
    sp74.z = arg2->z - sp80.z;

    sp68.x = arg3->x - sp80.x;
    sp68.y = arg3->y - sp80.y;
    sp68.z = arg3->z - sp80.z;

    return (sqrtf(SQ_SUM(&sp74)) + sqrtf(SQ_SUM(&sp68))) / 2.0f;
}

void func_8009FC84(unk_800F8510* arg0) {
    unk_8006FC8C* var_s0 = arg0->unk_10;
    Mtx3F sp110;
    Mtx3F spEC;
    Mtx3F spC8;
    Vec3f spBC;
    Vec3f spB0;
    Vec3f spA4;
    Vec3fFlip sp98;
    Vec3fFlip sp8C;
    f32 sp88;
    f32 sp7C;
    f32 temp_fs0;
    f32 temp_ft3;
    f32 temp_fv0;

    do {
        var_s0->unk_20 &= ~(0x10000 | 0x20000 | 0x8000);
        func_8009E85C(var_s0, 0.0f, &sp110, 0.0f);
        func_8009E85C(var_s0, 0.5f, &spEC, 0.5f);
        func_8009E85C(var_s0, 1.0f, &spC8, 1.0f);
        sp98.x = CROSS_X(&sp110.x, &spEC.x);
        sp98.y = CROSS_Y(&sp110.x, &spEC.x);
        sp98.z = CROSS_Z(&sp110.x, &spEC.x);
        sp8C.x = CROSS_X(&spEC.x, &spC8.x);
        sp8C.y = CROSS_Y(&spEC.x, &spC8.x);
        sp8C.z = CROSS_Z(&spEC.x, &spC8.x);
        sp88 = DOT_XYZ(&sp98, &spEC.y);
        sp7C = DOT_XYZ(&sp8C, &spEC.y);
        func_8009E6F0(var_s0, 0.0f, &spBC);
        func_8009E6F0(var_s0, 0.5f, &spB0);
        func_8009E6F0(var_s0, 1.0f, &spA4);
        temp_fs0 = func_8009F87C(&sp110, &spEC, &spBC, &spB0);
        temp_fv0 = func_8009F87C(&spEC, &spC8, &spB0, &spA4);
        if (temp_fs0 != 0.0f) {
            if (temp_fv0 != 0.0f) {
                if (temp_fs0 < temp_fv0) {
                    var_s0->unk_64 = temp_fs0;
                } else {
                    var_s0->unk_64 = temp_fv0;
                }
                if (sp88 < 0.0f) {
                    if (sp7C < 0.0f) {
                        var_s0->unk_20 |= 0x10000 | 0x8000;
                    } else {
                        var_s0->unk_20 |= 0x20000 | 0x8000;
                    }
                } else if (sp7C < 0.0f) {
                    var_s0->unk_20 |= 0x20000;
                } else {
                    var_s0->unk_20 |= 0x10000;
                }
            } else {
                var_s0->unk_64 = temp_fs0;
                if (sp88 < 0.0f) {
                    var_s0->unk_20 |= 0x10000 | 0x8000;
                } else {
                    var_s0->unk_20 |= 0x10000;
                }
            }
        } else if (temp_fv0 != 0.0f) {
            var_s0->unk_64 = temp_fv0;
            if (sp7C < 0.0f) {
                var_s0->unk_20 |= 0x10000 | 0x8000;
            } else {
                var_s0->unk_20 |= 0x10000;
            }
        } else {
            var_s0->unk_64 = 0.0f;
            var_s0->unk_20 |= 0x8000;
        }
        var_s0 = var_s0->unk_34;
    } while (var_s0 != arg0->unk_10);
}

void func_800A0010(unk_800F8510* arg0) {
    unk_8006FC8C* var_v0 = arg0->unk_10;
    unk_8006FC8C* var_v1 = var_v0->unk_38;

    do {
        if ((var_v1->unk_20 & 0x1FF) == (var_v0->unk_20 & 0x1FF)) {
            var_v0->unk_20 |= 0x40000000;
        } else {
            var_v0->unk_20 &= ~0x40000000;
        }
        var_v1 = var_v0;
        var_v0 = var_v0->unk_34;
    } while (var_v0 != arg0->unk_10);
}

void func_800A0068(unk_36ED0* arg0, f32 arg1, f32 arg2, Mtx3F* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6, Vec3f* arg7,
                   Vec3f* arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/36ED0/func_800A0068.s")

void func_800A0458(unk_36ED0* arg0, f32 arg1, f32 arg2, Mtx3F* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6, Vec3f* arg7,
                   Vec3f* arg8) {
    func_800A0068(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, 30.0f, 10.0f, 10.0f, 50.0f, 50.0f);
}

void func_800A04D8(unk_36ED0* arg0, f32 arg1, f32 arg2, Mtx3F* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6, Vec3f* arg7,
                   Vec3f* arg8) {
    func_800A0068(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, 30.0f, 20.0f, 120.0f, 155.0f, 50.0f);
}

void func_800A05CC(unk_36ED0* arg0, f32 arg1, f32 arg2, Mtx3F* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6, Vec3f* arg7,
                   Vec3f* arg8);
extern f32 D_800DE634;

void func_800A0568(unk_36ED0* arg0, f32 arg1, f32 arg2, Mtx3F* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6, Vec3f* arg7,
                   Vec3f* arg8) {
    func_800A05CC(arg0, arg1 / D_800DE634, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

extern f32 D_800DDA30;

void func_800A05CC(unk_36ED0* arg0, f32 arg1, f32 arg2, Mtx3F* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6, Vec3f* arg7,
                   Vec3f* arg8) {
    f32 sp64;
    f32 sp60;
    f32 temp_fs1;
    f32 temp_fs0;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_fs4;

    arg0->unk_32[0] = func_8006A9E0(arg4->x = (arg8->x = arg0->unk_14.x) + (sp54 = arg3->xz * arg1));
    arg0->unk_32[1] = func_8006A9E0(arg4->y = (arg8->y = arg0->unk_14.y) + (sp50 = arg3->yz * arg1));
    arg0->unk_32[2] = func_8006A9E0(arg4->z = (arg8->z = arg0->unk_14.z) + (sp4C = arg3->zz * arg1));

    arg0->unk_44[0] = func_8006A9E0(arg5->x = arg0->unk_14.x - sp54);
    arg0->unk_44[1] = func_8006A9E0(arg5->y = arg0->unk_14.y - sp50);
    arg0->unk_44[2] = func_8006A9E0(arg5->z = arg0->unk_14.z - sp4C);

    arg0->unk_26[0] = func_8006A9E0(arg6->x = (temp_fs2 = arg3->xy * arg1) + arg0->unk_14.x);
    arg0->unk_26[1] = func_8006A9E0(arg6->y = (temp_fs3 = arg3->yy * arg1) + arg0->unk_14.y);
    arg0->unk_26[2] = func_8006A9E0(arg6->z = (temp_fs4 = arg3->zy * arg1) + arg0->unk_14.z);

    arg0->unk_20[0] = func_8006A9E0(arg7->x = arg0->unk_14.x - temp_fs2);
    arg0->unk_20[1] = func_8006A9E0(arg7->y = arg0->unk_14.y - temp_fs3);
    arg0->unk_20[2] = func_8006A9E0(arg7->z = arg0->unk_14.z - temp_fs4);

    sp64 = D_800DDA30 * arg1;

    arg0->unk_38[0] = func_8006A9E0((sp60 = (sp54 = arg3->xz * sp64) + arg0->unk_14.x) + (temp_fs2 = arg3->xy * sp64));
    arg0->unk_38[1] =
        func_8006A9E0((temp_fs1 = (sp50 = arg3->yz * sp64) + arg0->unk_14.y) + (temp_fs3 = arg3->yy * sp64));
    arg0->unk_38[2] =
        func_8006A9E0((temp_fs0 = (sp4C = arg3->zz * sp64) + arg0->unk_14.z) + (temp_fs4 = arg3->zy * sp64));

    arg0->unk_2C[0] = func_8006A9E0(sp60 - temp_fs2);
    arg0->unk_2C[1] = func_8006A9E0(temp_fs1 - temp_fs3);
    arg0->unk_2C[2] = func_8006A9E0(temp_fs0 - temp_fs4);

    arg0->unk_4A[0] = func_8006A9E0((sp60 = arg0->unk_14.x - sp54) + temp_fs2);
    arg0->unk_4A[1] = func_8006A9E0((temp_fs1 = arg0->unk_14.y - sp50) + temp_fs3);
    arg0->unk_4A[2] = func_8006A9E0((temp_fs0 = arg0->unk_14.z - sp4C) + temp_fs4);

    arg0->unk_3E[0] = func_8006A9E0(sp60 - temp_fs2);
    arg0->unk_3E[1] = func_8006A9E0(temp_fs1 - temp_fs3);
    arg0->unk_3E[2] = func_8006A9E0(temp_fs0 - temp_fs4);
}

extern f32 D_800DD230[];

void func_800A0900(unk_36ED0* arg0, f32 arg1, f32 arg2, Mtx3F* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6, Vec3f* arg7,
                   Vec3f* arg8) {
    f32 sp64;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 sp58;
    f32 sp54;
    f32 temp_fs0;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;

    sp64 = arg1 / D_800DD230[0x4C1];
    temp_fs1 = D_800DD230[0xD00] * sp64;
    temp_fs2 = D_800DD230[0x900] * sp64;

    arg0->unk_44[0] =
        func_8006A9E0(arg5->x = (sp58 = arg0->unk_14.x + (temp_fs2 * arg3->xy)) + (temp_fs3 = arg3->xz * temp_fs1));
    arg0->unk_44[1] =
        func_8006A9E0(arg5->y = (sp54 = arg0->unk_14.y + (temp_fs2 * arg3->yy)) + (temp_fs4 = arg3->yz * temp_fs1));
    arg0->unk_44[2] =
        func_8006A9E0(arg5->z = (temp_fs0 = arg0->unk_14.z + (temp_fs2 * arg3->zy)) + (temp_fs5 = arg3->zz * temp_fs1));

    arg0->unk_32[0] = func_8006A9E0(arg4->x = sp58 - temp_fs3);
    arg0->unk_32[1] = func_8006A9E0(arg4->y = sp54 - temp_fs4);
    arg0->unk_32[2] = func_8006A9E0(arg4->z = temp_fs0 - temp_fs5);

    temp_fs1 = D_800DD230[0xE80] * sp64;
    temp_fs2 = D_800DD230[0xA80] * sp64;

    arg0->unk_4A[0] = func_8006A9E0((sp58 = arg0->unk_14.x + (temp_fs2 * arg3->xy)) + (temp_fs3 = arg3->xz * temp_fs1));
    arg0->unk_4A[1] = func_8006A9E0((sp54 = arg0->unk_14.y + (temp_fs2 * arg3->yy)) + (temp_fs4 = arg3->yz * temp_fs1));
    arg0->unk_4A[2] =
        func_8006A9E0((temp_fs0 = arg0->unk_14.z + (temp_fs2 * arg3->zy)) + (temp_fs5 = arg3->zz * temp_fs1));

    arg0->unk_38[0] = func_8006A9E0(sp58 - temp_fs3);
    arg0->unk_38[1] = func_8006A9E0(sp54 - temp_fs4);
    arg0->unk_38[2] = func_8006A9E0(temp_fs0 - temp_fs5);

    arg0->unk_26[0] = func_8006A9E0(arg7->x = arg0->unk_14.x - (sp64 * arg3->xy));
    arg0->unk_26[1] = func_8006A9E0(arg7->y = arg0->unk_14.y - (sp64 * arg3->yy));
    arg0->unk_26[2] = func_8006A9E0(arg7->z = arg0->unk_14.z - (sp64 * arg3->zy));

    sp64 *= 1.2f;
    temp_fs1 = D_800DD230[0xE80] * sp64;
    temp_fs2 = D_800DD230[0xA80] * sp64;

    arg0->unk_3E[0] = func_8006A9E0((sp58 = arg0->unk_14.x + (temp_fs2 * arg3->xy)) + (temp_fs3 = arg3->xz * temp_fs1));
    arg0->unk_3E[1] = func_8006A9E0((sp54 = arg0->unk_14.y + (temp_fs2 * arg3->yy)) + (temp_fs4 = arg3->yz * temp_fs1));
    arg0->unk_3E[2] =
        func_8006A9E0((temp_fs0 = arg0->unk_14.z + (temp_fs2 * arg3->zy)) + (temp_fs5 = arg3->zz * temp_fs1));

    arg0->unk_2C[0] = func_8006A9E0(sp58 - temp_fs3);
    arg0->unk_2C[1] = func_8006A9E0(sp54 - temp_fs4);
    arg0->unk_2C[2] = func_8006A9E0(temp_fs0 - temp_fs5);

    arg0->unk_20[0] = func_8006A9E0((arg6->x = arg8->x = arg0->unk_14.x) - (sp64 * arg3->xy));
    arg0->unk_20[1] = func_8006A9E0((arg6->y = arg8->y = arg0->unk_14.y) - (sp64 * arg3->yy));
    arg0->unk_20[2] = func_8006A9E0((arg6->z = arg8->z = arg0->unk_14.z) - (sp64 * arg3->zy));
}

void func_800A0CF0(unk_36ED0* arg0, f32 arg1, f32 arg2, Mtx3F* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6, Vec3f* arg7,
                   Vec3f* arg8) {
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;

    temp_fs4 = arg1 + 11.5f;
    temp_fs5 = arg2 + 11.5f;

    temp_fs1 = (temp_fs4 - temp_fs5) / 2.0f;

    arg0->unk_20[0] = func_8006A9E0(arg8->x = arg0->unk_14.x + (temp_fs1 * arg3->xz));
    arg0->unk_20[1] = func_8006A9E0(arg8->y = arg0->unk_14.y + (temp_fs1 * arg3->yz));
    arg0->unk_20[2] = func_8006A9E0(arg8->z = arg0->unk_14.z + (temp_fs1 * arg3->zz));

    arg0->unk_26[0] = func_8006A9E0(arg6->x = (temp_fs2 = arg3->xy * 185.0f) + arg8->x);
    arg0->unk_26[1] = func_8006A9E0(arg6->y = (temp_fs3 = arg3->yy * 185.0f) + arg8->y);
    arg0->unk_26[2] = func_8006A9E0(arg6->z = (sp68 = arg3->zy * 185.0f) + arg8->z);

    arg7->x = arg8->x - temp_fs2;
    arg7->y = arg8->y - temp_fs3;
    arg7->z = arg8->z - sp68;
    temp_fs1 = (temp_fs4 + temp_fs5) / 2.0f;

    arg0->unk_2C[0] = func_8006A9E0(arg4->x = (sp64 = arg3->xz * temp_fs1) + arg8->x);
    arg0->unk_2C[1] = func_8006A9E0(arg4->y = (sp60 = arg3->yz * temp_fs1) + arg8->y);
    arg0->unk_2C[2] = func_8006A9E0(arg4->z = (sp5C = arg3->zz * temp_fs1) + arg8->z);

    arg0->unk_3E[0] = func_8006A9E0(arg5->x = arg8->x - sp64);
    arg0->unk_3E[1] = func_8006A9E0(arg5->y = arg8->y - sp60);
    arg0->unk_3E[2] = func_8006A9E0(arg5->z = arg8->z - sp5C);

    arg0->unk_32[0] = func_8006A9E0((temp_fs2 = arg3->xy * 85.0f) + arg4->x);
    arg0->unk_32[1] = func_8006A9E0((temp_fs3 = arg3->yy * 85.0f) + arg4->y);
    arg0->unk_32[2] = func_8006A9E0((sp68 = arg3->zy * 85.0f) + arg4->z);

    arg0->unk_44[0] = func_8006A9E0(arg5->x + temp_fs2);
    arg0->unk_44[1] = func_8006A9E0(arg5->y + temp_fs3);
    arg0->unk_44[2] = func_8006A9E0(arg5->z + sp68);

    temp_fs1 *= 0.625f;

    arg0->unk_38[0] = func_8006A9E0((temp_fs2 = arg8->x + (160.0f * arg3->xy)) + (sp64 = arg3->xz * temp_fs1));
    arg0->unk_38[1] = func_8006A9E0((temp_fs3 = arg8->y + (160.0f * arg3->yy)) + (sp60 = arg3->yz * temp_fs1));
    arg0->unk_38[2] = func_8006A9E0((sp68 = arg8->z + (160.0f * arg3->zy)) + (sp5C = arg3->zz * temp_fs1));

    arg0->unk_4A[0] = func_8006A9E0(temp_fs2 - sp64);
    arg0->unk_4A[1] = func_8006A9E0(temp_fs3 - sp60);
    arg0->unk_4A[2] = func_8006A9E0(sp68 - sp5C);
}

void func_800A10E4(unk_36ED0* arg0, f32 arg1, f32 arg2, Mtx3F* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6, Vec3f* arg7,
                   Vec3f* arg8) {
    func_800A0068(arg0, arg1 - 15.410001f, arg2 - 15.410001f, arg3, arg4, arg5, arg6, arg7, arg8, 10.0f, 0.0f, -10.0f,
                  40.0f, 40.0f);
}

void func_800A1178(s16* arg0, s16* arg1, f32 arg2, s16* arg3) {
    arg3[0] = (s16) func_8006A9E0((arg1[0] - arg0[0]) * arg2) + arg0[0];
    arg3[1] = (s16) func_8006A9E0((arg1[1] - arg0[1]) * arg2) + arg0[1];
    arg3[2] = (s16) func_8006A9E0((arg1[2] - arg0[2]) * arg2) + arg0[2];
}

void func_800A1258(unk_36ED0* arg0, unk_36ED0* arg1, f32 arg2) {
    func_800A1178(arg0->unk_26, arg1->unk_20, arg2, arg1->unk_26);
    func_800A1178(arg0->unk_20, arg1->unk_20, arg2, arg1->unk_20);
    func_800A1178(arg0->unk_32, arg1->unk_32, arg2, arg1->unk_32);
    func_800A1178(arg0->unk_44, arg1->unk_44, arg2, arg1->unk_44);
    func_800A1178(arg0->unk_38, arg1->unk_2C, arg2, arg1->unk_38);
    func_800A1178(arg0->unk_2C, arg1->unk_2C, arg2, arg1->unk_2C);
    func_800A1178(arg0->unk_4A, arg1->unk_3E, arg2, arg1->unk_4A);
    func_800A1178(arg0->unk_3E, arg1->unk_3E, arg2, arg1->unk_3E);
}

void func_800A133C(unk_36ED0* arg0, unk_36ED0* arg1, f32 arg2) {

    if (arg2 == 0.0f) {
        arg1->unk_20[0] = arg0->unk_20[0];
        arg1->unk_20[1] = arg0->unk_20[1];
        arg1->unk_20[2] = arg0->unk_20[2];
        arg1->unk_26[0] = arg0->unk_26[0];
        arg1->unk_26[1] = arg0->unk_26[1];
        arg1->unk_26[2] = arg0->unk_26[2];
        arg1->unk_2C[0] = arg0->unk_2C[0];
        arg1->unk_2C[1] = arg0->unk_2C[1];
        arg1->unk_2C[2] = arg0->unk_2C[2];
        arg1->unk_32[0] = arg0->unk_32[0];
        arg1->unk_32[1] = arg0->unk_32[1];
        arg1->unk_32[2] = arg0->unk_32[2];
        arg1->unk_38[0] = arg0->unk_38[0];
        arg1->unk_38[1] = arg0->unk_38[1];
        arg1->unk_38[2] = arg0->unk_38[2];
        arg1->unk_3E[0] = arg0->unk_3E[0];
        arg1->unk_3E[1] = arg0->unk_3E[1];
        arg1->unk_3E[2] = arg0->unk_3E[2];
        arg1->unk_44[0] = arg0->unk_44[0];
        arg1->unk_44[1] = arg0->unk_44[1];
        arg1->unk_44[2] = arg0->unk_44[2];
        arg1->unk_4A[0] = arg0->unk_4A[0];
        arg1->unk_4A[1] = arg0->unk_4A[1];
        arg1->unk_4A[2] = arg0->unk_4A[2];
    } else {
        func_800A1178(arg0->unk_26, arg1->unk_20, arg2, arg1->unk_20);
        func_800A1178(arg0->unk_26, arg1->unk_26, arg2, arg1->unk_26);
        func_800A1178(arg0->unk_26, arg1->unk_2C, arg2, arg1->unk_2C);
        func_800A1178(arg0->unk_26, arg1->unk_32, arg2, arg1->unk_32);
        func_800A1178(arg0->unk_26, arg1->unk_38, arg2, arg1->unk_38);
        func_800A1178(arg0->unk_26, arg1->unk_3E, arg2, arg1->unk_3E);
        func_800A1178(arg0->unk_26, arg1->unk_44, arg2, arg1->unk_44);
        func_800A1178(arg0->unk_26, arg1->unk_4A, arg2, arg1->unk_4A);
    }
}

void func_800A14F0(unk_36ED0* arg0, unk_36ED0* arg1, f32 arg2) {
    func_800A1178(arg0->unk_20, arg1->unk_20, arg2, arg1->unk_20);
    func_800A1178(arg0->unk_26, arg1->unk_26, arg2, arg1->unk_26);
    func_800A1178(arg0->unk_2C, arg1->unk_2C, arg2, arg1->unk_2C);
    func_800A1178(arg0->unk_32, arg1->unk_32, arg2, arg1->unk_32);
    func_800A1178(arg0->unk_38, arg1->unk_38, arg2, arg1->unk_38);
    func_800A1178(arg0->unk_3E, arg1->unk_3E, arg2, arg1->unk_3E);
    func_800A1178(arg0->unk_44, arg1->unk_44, arg2, arg1->unk_44);
    func_800A1178(arg0->unk_4A, arg1->unk_4A, arg2, arg1->unk_4A);
}

f32 func_800A15C8(unk_8006FC8C* arg0) {
    f32 temp_fv1;
    f32 var_fs3;
    f32 var_fs1;
    Vec3f sp58;

    arg0->unk_70 = -1.0f;
    var_fs3 = D_800CF8E8[(u32) (arg0->unk_20 & 0x1C0) >> 6];
    if (arg0->unk_20 & 0x200) {
        arg0->unk_68 = 0.0f;
        var_fs1 = 0.0f;
        do {
            temp_fv1 = 50.0f / func_8009E538(arg0, arg0->unk_68, &sp58);
            arg0->unk_68 += temp_fv1;

            if (arg0->unk_68 >= 1.0f) {
                var_fs3 = var_fs1;
                arg0->unk_68 -= temp_fv1;
                break;
            }
            var_fs1 += 50.0f;
        } while (var_fs1 < var_fs3);
        arg0->unk_70 = var_fs1 / arg0->unk_28;
    } else {
        arg0->unk_68 = -99.0f;
    }

    if (arg0->unk_20 & 0x400) {
        arg0->unk_6C = 1.0f;

        var_fs1 = 0.0f;
        do {
            temp_fv1 = 50.0f / func_8009E538(arg0, arg0->unk_6C, &sp58);
            arg0->unk_6C -= temp_fv1;
            if (arg0->unk_6C <= 0.0f) {
                var_fs3 = var_fs1;
                arg0->unk_6C += temp_fv1;
                break;
            }
            var_fs1 += 50.0f;
        } while (var_fs1 < var_fs3);
        arg0->unk_70 = var_fs1 / arg0->unk_28;
    } else if (!(arg0->unk_20 & 0x1FF) && (arg0->unk_34->unk_20 & 0x1FF)) {
        arg0->unk_6C = 1.0f - (100.0f / func_8009E538(arg0, 1.0f, &sp58));
    } else {
        arg0->unk_6C = 99.0f;
    }
    if (arg0->unk_6C <= arg0->unk_68) {
        arg0->unk_68 = 0.49f;
        arg0->unk_6C = 0.51f;
        arg0->unk_70 = 0.49f;
        var_fs3 = arg0->unk_28 * 0.49f;
    }
    return var_fs3;
}

extern f32 D_800F89E8;

bool func_800A1818(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    Vec3f vec;
    f32 temp_fa1;

    vec.x = arg2->x - arg0->x;
    vec.y = arg2->y - arg0->y;
    vec.z = arg2->z - arg0->z;
    temp_fa1 = DOT_XYZ(arg1, &vec);
    if (SQ_SUM(&vec) - SQ(temp_fa1) < D_800F89E8) {
        return false;
    }
    return true;
}

f32 func_800A18A8(Vec3f* arg0, Vec3f* arg1) {
    f32 diff;
    f32 sum;

    diff = arg0->x - arg1->x;
    sum = SQ(diff);
    diff = arg0->y - arg1->y;
    sum += SQ(diff);
    diff = arg0->z - arg1->z;
    sum += SQ(diff);

    return sqrtf(sum);
}

extern unk_800CF528* D_800CF8C8[];

s32 func_800A18FC(s32 arg0, f32 arg1) {

    if ((arg0 & 0x3F) != 0x3F) {
        return (s32) (D_800CF8C8[(s32) (arg0 & 0x1C0) >> 6][arg0 & 0x3F].unk_04 * arg1) - 0x8000;
    }
    return -0x8000;
}

s32 func_800A1954(unk_800F8510* arg0);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/36ED0/func_800A1954.s")

Vtx* func_800A2BDC(Vtx* arg0, Vec3f* arg1, Mtx3F* arg2) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    temp_fs0 = arg2->xy * 115.47f;
    temp_fs1 = arg2->yy * 115.47f;
    temp_fs2 = arg2->zy * 115.47f;
    sp40 = arg2->xz * 200.0f;
    sp3C = arg2->yz * 200.0f;
    sp38 = arg2->zz * 200.0f;

    arg0->v.ob[0] = func_8006A9E0(arg1->x + temp_fs0 + temp_fs0);
    arg0->v.ob[1] = func_8006A9E0(arg1->y + temp_fs1 + temp_fs1);
    arg0->v.ob[2] = func_8006A9E0(arg1->z + temp_fs2 + temp_fs2);
    arg0++;
    arg0->v.ob[0] = func_8006A9E0((temp_fs0 = arg1->x - temp_fs0) + sp40);
    arg0->v.ob[1] = func_8006A9E0((temp_fs1 = arg1->y - temp_fs1) + sp3C);
    arg0->v.ob[2] = func_8006A9E0((temp_fs2 = arg1->z - temp_fs2) + sp38);
    arg0++;
    arg0->v.ob[0] = func_8006A9E0(temp_fs0 - sp40);
    arg0->v.ob[1] = func_8006A9E0(temp_fs1 - sp3C);
    arg0->v.ob[2] = func_8006A9E0(temp_fs2 - sp38);
    return ++arg0;
}

// TODO: figure out migration of unused float
#ifdef RODATA
const static f32 D_800D5AA8[2] = { 3000.0f, 131071.0f };

s32 func_800A2D2C(unk_800F8510* arg0, Vtx* arg1) {
    unk_8006FC8C* var_s0;
    f32 spD0;
    f32 var_fs1;
    f32 var_fs2;
    Vec3f spBC;
    Vec3f spB0;
    Vec3f spA4;
    Mtx3F sp80;
    s32 var_s2;
    Vtx* var_s3;

    // D_800F89E8 = D_800D5AA8[0];
    D_800F89E8 = 3000.0f;
    var_s0 = arg0->unk_10;
    var_fs1 = 0.0f;
    var_fs2 = func_8009E85C(var_s0, 0.0f, &sp80, 0.0f);
    func_8009E6F0(var_s0, 0.0f, &spA4);
    var_s3 = func_800A2BDC(arg1, &spA4, &sp80);
    spBC.x = sp80.x.x;
    spBC.y = sp80.x.y;
    spBC.z = sp80.x.z;
    spB0 = spA4;
    var_s2 = 3;

    while (true) {
        var_fs1 += 300.0f / var_fs2;
        if (var_fs1 >= 1.0f) {
            var_s0 = var_s0->unk_34;
            var_fs1 -= 1.0f;
            if (var_s0 != arg0->unk_10) {
                var_fs1 *= (var_fs2 / func_8009E538(var_s0, 0.0f, &spA4));
            } else {
                break;
            }
        }

        var_fs2 = func_8009E85C(var_s0, var_fs1, &sp80, func_8009E108(var_s0, var_fs1, &spD0));
        func_8009E6F0(var_s0, var_fs1, &spA4);
        if (func_800A1818(&spB0, &spBC, &spA4) != 0) {

            spBC.x = spA4.x - spB0.x;
            spBC.y = spA4.y - spB0.y;
            spBC.z = spA4.z - spB0.z;

            spD0 = SQ_SUM(&spBC);
            spD0 = 1.0f / sqrtf(spD0);
            spB0 = spA4;

            var_s2 += 3;

            spBC.x *= spD0;
            spBC.y *= spD0;
            spBC.z *= spD0;

            if (var_s2 < 0xC00) {
                var_s3 = func_800A2BDC(var_s3, &spA4, &sp80);
                continue;
            }
            return 0;
        }
    }

    var_s2 += 3;

    if (var_s2 < 0xC00) {
        var_s3[0] = arg1[0];
        var_s3[1] = arg1[1];
        var_s3[2] = arg1[2];
        return var_s2;
    } else {
        return 0;
    }
}
#else
s32 func_800A2D2C(unk_800F8510* arg0, Vtx* arg1);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/36ED0/func_800A2D2C.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/36ED0/func_800A3044.s")

extern unk_8006FC8C D_802C2020[];

void func_800A4B54(void) {
    s32 i;

    for (i = 0; i < 56; i++) {
        D_802A6B40[i].unk_04 = i;
        D_802A6B40[i].unk_10 = D_802C2020;
    }
}

extern unk_800F8958 D_800F8958[];
extern Gfx D_80140F0[];
extern Gfx D_8014138[];
extern Gfx D_8014180[];
extern Gfx D_80141C8[];
extern Gfx D_8014210[];
extern Gfx D_8014268[];
extern Gfx D_80142C0[];
extern Gfx D_8014308[];
extern Gfx D_8014350[];
extern Gfx D_8014398[];
extern Gfx D_80143E0[];
extern Gfx D_8014430[];
extern Gfx D_8014480[];
extern Gfx D_80144D0[];
extern Gfx D_8014520[];
extern Gfx D_8014580[];
extern Gfx D_80145E0[];
extern Gfx D_8014640[];
extern Vtx D_8028A3D8[];
extern Vtx D_8025DCE8[];

void func_800A4BAC(void) {
    Vtx* var_a0;
    Vtx* var_v1;
    s32 i;

    D_800F8958[0].unk_04 = D_80140F0;
    D_800F8958[0].unk_08 = D_8014180;
    D_800F8958[0].unk_0C = D_80140F0;
    D_800F8958[0].unk_10 = D_8014210;
    D_800F8958[0].unk_14 = D_80142C0;
    D_800F8958[0].unk_18 = D_8014308;
    D_800F8958[0].unk_1C = D_80143E0;
    D_800F8958[0].unk_20 = D_8014430;
    D_800F8958[0].unk_24 = D_8014520;
    D_800F8958[0].unk_28 = D_80145E0;
    D_800F8958[0].unk_2C = 0;
    D_800F8958[1].unk_04 = D_8014138;
    D_800F8958[1].unk_08 = D_80141C8;
    D_800F8958[1].unk_0C = D_8014138;
    D_800F8958[1].unk_10 = D_8014268;
    D_800F8958[1].unk_14 = D_8014350;
    D_800F8958[1].unk_18 = D_8014398;
    D_800F8958[1].unk_1C = D_8014480;
    D_800F8958[1].unk_20 = D_80144D0;
    D_800F8958[1].unk_24 = D_8014580;
    D_800F8958[1].unk_28 = D_8014640;
    D_800F8958[1].unk_2C = 8;

    var_a0 = &D_8025DCE8[0xFFF];
    var_v1 = &D_8028A3D8[0xFFF];
    goto dummy;
dummy:;
    do {
        var_a0->v.cn[0] = var_a0->v.cn[1] = var_a0->v.cn[2] = var_v1->v.cn[0] = var_v1->v.cn[1] = var_v1->v.cn[2] = 0;
        var_a0->v.cn[3] = var_v1->v.cn[3] = 255;

        var_a0--;
        var_v1--;
    } while ((u32) var_v1 >= (u32) D_8028A3D8);

    func_800A4B54();
}

extern s32 D_800F8524;
extern f32 D_800F894C;
extern f32 D_800F8950;
extern f32 D_800F89E0;
extern f32 D_800F89E4;

void func_800A4D0C(s32 arg0) {
    D_800F8524 = arg0;
    switch (D_800F8524) {
        case 0:
            D_800F89E0 = 300.0f;
            break;
        case 1:
            D_800F894C = 2000.0f;
            D_800F8950 = 300.0f;
            D_800F89E8 = 400.0f;
            D_800F89E0 = 20.0f;
            D_800F89E4 = 2000.0f;
            break;
        case 2:
            D_800F894C = 1500.0f;
            D_800F8950 = 100.0f;
            D_800F89E8 = 700.0f;
            D_800F89E0 = 20.0f;
            D_800F89E4 = 4000.0f;
            break;
    }
}

extern unk_800F8510* D_800F8510;
extern s32 D_800F8514;

extern unk_8010B7B0 D_8010B7B0;
s32 func_800AA394(void);

void func_800A4DF0(void) {

    D_800F8510 = &D_802A6B40[D_800F8514];
    func_8007402C(D_800F8514);
    func_800747EC(D_8010B7B0.unk_000[2]);
    func_8009CED0(D_8010B7B0.unk_000[2]);
    func_80074634(D_800F8510);
    func_8009DEAC(D_800F8510);
    if (D_800F8510->unk_04 >= 24) {
        D_800F8510->unk_00 = 24;
    } else {
        D_800F8510->unk_00 = D_800F8510->unk_04;
    }
    D_800F8510->unk_00 |= func_800AA394() << 5;
}

extern s32 D_800CD000;
extern f32 D_800CF520;
extern f32 D_800CF524;

void func_800A4EAC(void) {
    unk_8006FC8C* var_v0;

    if (D_800F8514 >= ARRAY_COUNT(D_802A6B40)) {
        D_800F8514 = ARRAY_COUNT(D_802A6B40) - 1;
    }
    if (D_800CD000 >= 3) {
        func_800A4D0C(2);
    } else {
        func_800A4D0C(1);
    }
    func_800A4DF0();
    func_80073A04();
    func_8009F508(D_800F8510);
    func_800741DC(D_800F8514);
    func_8009F3E0(D_800F8510);
    func_800A0010(D_800F8510);
    func_8009FC84(D_800F8510);
    func_800A1954(D_800F8510);
    D_800CF524 = 900.0f;
    var_v0 = D_800F8510->unk_10;
    do {

        if (D_800CF524 < var_v0->unk_18) {
            D_800CF524 = var_v0->unk_18;
        }

        if (D_800CF524 < var_v0->unk_1C) {
            D_800CF524 = var_v0->unk_1C;
        }
        var_v0 = var_v0->unk_34;
    } while (var_v0 != D_800F8510->unk_10);
    D_800CF524 += 100.0f;
    D_800CF520 = D_800CF524 + 4500.0f;
    D_800F894C += D_800CF524 - 1000.0f;
    D_800F8950 += D_800CF524 - 1000.0f;
}

void func_800A5028(void) {
}

extern Vtx* D_800F8520;

void func_800A5030(unk_36ED0* arg0) {
    D_800F8520[0].v.ob[0] = arg0->unk_20[0];
    D_800F8520[0].v.ob[1] = arg0->unk_20[1];
    D_800F8520[0].v.ob[2] = arg0->unk_20[2];
    D_800F8520[1].v.ob[0] = arg0->unk_3E[0];
    D_800F8520[1].v.ob[1] = arg0->unk_3E[1];
    D_800F8520[1].v.ob[2] = arg0->unk_3E[2];
    D_800F8520[2].v.ob[0] = arg0->unk_44[0];
    D_800F8520[2].v.ob[1] = arg0->unk_44[1];
    D_800F8520[2].v.ob[2] = arg0->unk_44[2];
    D_800F8520[3].v.ob[0] = arg0->unk_4A[0];
    D_800F8520[3].v.ob[1] = arg0->unk_4A[1];
    D_800F8520[3].v.ob[2] = arg0->unk_4A[2];
    D_800F8520[4].v.ob[0] = arg0->unk_26[0];
    D_800F8520[4].v.ob[1] = arg0->unk_26[1];
    D_800F8520[4].v.ob[2] = arg0->unk_26[2];
    D_800F8520[5].v.ob[0] = arg0->unk_38[0];
    D_800F8520[5].v.ob[1] = arg0->unk_38[1];
    D_800F8520[5].v.ob[2] = arg0->unk_38[2];
    D_800F8520[6].v.ob[0] = arg0->unk_32[0];
    D_800F8520[6].v.ob[1] = arg0->unk_32[1];
    D_800F8520[6].v.ob[2] = arg0->unk_32[2];
    D_800F8520[7].v.ob[0] = arg0->unk_2C[0];
    D_800F8520[7].v.ob[1] = arg0->unk_2C[1];
    D_800F8520[7].v.ob[2] = arg0->unk_2C[2];
    D_800F8520 += 8;
}

extern s16 D_800F8930[];

void func_800A5168(unk_36ED0* arg0) {
    D_800F8520[0].v.tc[0] = D_800F8930[4];
    D_800F8520[1].v.tc[0] = D_800F8520[7].v.tc[0] = D_800F8930[3];
    D_800F8520[2].v.tc[0] = D_800F8520[6].v.tc[0] = D_800F8930[2];
    D_800F8520[3].v.tc[0] = D_800F8520[5].v.tc[0] = D_800F8930[1];
    D_800F8520[4].v.tc[0] = D_800F8930[0];
    D_800F8520[0].v.ob[0] = arg0->unk_20[0];
    D_800F8520[0].v.ob[1] = arg0->unk_20[1];
    D_800F8520[0].v.ob[2] = arg0->unk_20[2];
    D_800F8520[1].v.ob[0] = arg0->unk_3E[0];
    D_800F8520[1].v.ob[1] = arg0->unk_3E[1];
    D_800F8520[1].v.ob[2] = arg0->unk_3E[2];
    D_800F8520[2].v.ob[0] = arg0->unk_44[0];
    D_800F8520[2].v.ob[1] = arg0->unk_44[1];
    D_800F8520[2].v.ob[2] = arg0->unk_44[2];
    D_800F8520[3].v.ob[0] = arg0->unk_4A[0];
    D_800F8520[3].v.ob[1] = arg0->unk_4A[1];
    D_800F8520[3].v.ob[2] = arg0->unk_4A[2];
    D_800F8520[4].v.ob[0] = arg0->unk_26[0];
    D_800F8520[4].v.ob[1] = arg0->unk_26[1];
    D_800F8520[4].v.ob[2] = arg0->unk_26[2];
    D_800F8520[5].v.ob[0] = arg0->unk_38[0];
    D_800F8520[5].v.ob[1] = arg0->unk_38[1];
    D_800F8520[5].v.ob[2] = arg0->unk_38[2];
    D_800F8520[6].v.ob[0] = arg0->unk_32[0];
    D_800F8520[6].v.ob[1] = arg0->unk_32[1];
    D_800F8520[6].v.ob[2] = arg0->unk_32[2];
    D_800F8520[7].v.ob[0] = arg0->unk_2C[0];
    D_800F8520[7].v.ob[1] = arg0->unk_2C[1];
    D_800F8520[7].v.ob[2] = arg0->unk_2C[2];
    D_800F8520 += 8;
}

void func_800A52FC(unk_36ED0* arg0, s32 arg1) {
    s32 var_a1;
    s32 var_v1;

    if (arg1 != 0) {
        var_v1 = arg0->unk_5E;
        var_a1 = arg0->unk_5C;
    } else {
        var_v1 = arg0->unk_56;
        var_a1 = arg0->unk_54;
    }

    D_800F8520[1].v.tc[1] = D_800F8520[2].v.tc[1] = D_800F8520[3].v.tc[1] = var_v1;
    D_800F8520[5].v.tc[1] = D_800F8520[6].v.tc[1] = D_800F8520[7].v.tc[1] = var_a1;
    D_800F8520[0].v.tc[1] = D_800F8520[4].v.tc[1] = (var_v1 + var_a1) >> 1;
    func_800A5168(arg0);
}

void func_800A5380(unk_36ED0* arg0, s32 arg1) {
    s32 var_a0;
    s32 var_a2;
    s32 var_a3;
    s32 var_t0;

    if (arg1 != 0) {
        var_a2 = arg0->unk_5E;
        var_a3 = arg0->unk_5C;
        var_t0 = arg0->unk_58;
        var_a0 = arg0->unk_5A;
    } else {
        var_a2 = arg0->unk_56;
        var_a3 = arg0->unk_54;
        var_t0 = arg0->unk_50;
        var_a0 = arg0->unk_52;
    }
    if (arg0->unk_00 & 0x600) {
        D_800F8520[0].v.tc[1] = D_800F8520[4].v.tc[1] = var_a0;
        D_800F8520[1].v.tc[1] = D_800F8520[3].v.tc[1] = (var_a0 + var_a2) >> 1;
        D_800F8520[2].v.tc[1] = var_a2;
        D_800F8520[6].v.tc[1] = var_a3;
        D_800F8520[7].v.tc[1] = D_800F8520[5].v.tc[1] = (var_a3 + var_a0) >> 1;
        D_800F8520[0].v.tc[0] = D_800F8930[4];
        D_800F8520[1].v.tc[0] = D_800F8520[7].v.tc[0] = D_800F8930[3];
        D_800F8520[2].v.tc[0] = D_800F8520[6].v.tc[0] = D_800F8930[2];
        D_800F8520[3].v.tc[0] = D_800F8520[5].v.tc[0] = D_800F8930[3];
        D_800F8520[4].v.tc[0] = D_800F8930[4];
    } else {
        D_800F8520[0].v.tc[1] = var_a0;
        D_800F8520[1].v.tc[1] = (var_a0 + var_a2) >> 1;
        D_800F8520[2].v.tc[1] = var_a2;
        D_800F8520[3].v.tc[1] = (var_a2 + var_t0) >> 1;
        D_800F8520[4].v.tc[1] = var_t0;
        D_800F8520[5].v.tc[1] = (var_t0 + var_a3) >> 1;
        D_800F8520[6].v.tc[1] = var_a3;
        D_800F8520[7].v.tc[1] = (var_a3 + var_a0) >> 1;
        D_800F8520[0].v.tc[0] = D_800F8930[4];
        D_800F8520[1].v.tc[0] = D_800F8520[7].v.tc[0] = D_800F8930[3];
        D_800F8520[2].v.tc[0] = D_800F8520[6].v.tc[0] = D_800F8930[2];
        D_800F8520[3].v.tc[0] = D_800F8520[5].v.tc[0] = D_800F8930[1];
        D_800F8520[4].v.tc[0] = D_800F8930[0];
    }
    func_800A5030(arg0);
}

extern Gfx* D_800F89C4;
extern Vtx* D_800F8520;

void func_800A5560(unk_36ED0* arg0) {
    Gfx* gfx;

    D_800F8520[0].v.ob[0] = ((arg0->unk_44[0] - arg0->unk_32[0]) >> 5) + arg0->unk_44[0];
    D_800F8520[0].v.ob[1] = ((arg0->unk_44[1] - arg0->unk_32[1]) >> 5) + arg0->unk_44[1];
    D_800F8520[0].v.ob[2] = ((arg0->unk_44[2] - arg0->unk_32[2]) >> 5) + arg0->unk_44[2];

    D_800F8520[1].v.ob[0] = ((arg0->unk_4A[0] - arg0->unk_2C[0]) >> 5) + arg0->unk_4A[0];
    D_800F8520[1].v.ob[1] = ((arg0->unk_4A[1] - arg0->unk_2C[1]) >> 5) + arg0->unk_4A[1];
    D_800F8520[1].v.ob[2] = ((arg0->unk_4A[2] - arg0->unk_2C[2]) >> 5) + arg0->unk_4A[2];

    D_800F8520[2].v.ob[0] = ((arg0->unk_26[0] - arg0->unk_20[0]) >> 5) + arg0->unk_26[0];
    D_800F8520[2].v.ob[1] = ((arg0->unk_26[1] - arg0->unk_20[1]) >> 5) + arg0->unk_26[1];
    D_800F8520[2].v.ob[2] = ((arg0->unk_26[2] - arg0->unk_20[2]) >> 5) + arg0->unk_26[2];

    D_800F8520[3].v.ob[0] = ((arg0->unk_38[0] - arg0->unk_3E[0]) >> 5) + arg0->unk_38[0];
    D_800F8520[3].v.ob[1] = ((arg0->unk_38[1] - arg0->unk_3E[1]) >> 5) + arg0->unk_38[1];
    D_800F8520[3].v.ob[2] = ((arg0->unk_38[2] - arg0->unk_3E[2]) >> 5) + arg0->unk_38[2];

    D_800F8520[4].v.ob[0] = ((arg0->unk_32[0] - arg0->unk_44[0]) >> 5) + arg0->unk_32[0];
    D_800F8520[4].v.ob[1] = ((arg0->unk_32[1] - arg0->unk_44[1]) >> 5) + arg0->unk_32[1];
    D_800F8520[4].v.ob[2] = ((arg0->unk_32[2] - arg0->unk_44[2]) >> 5) + arg0->unk_32[2];

    gSPVertex(D_800F89C4 - 1, D_800F8520, 5, 16);

    D_800F8520 += 5;
}

void func_800A573C(unk_36ED0* arg0, s32 arg1) {
    s16 var_a1;
    s16 var_a2;
    s16 var_a3;
    s16 var_v1;

    if (arg1 != 0) {
        var_v1 = arg0->unk_5E;
        var_a1 = arg0->unk_5C;
        var_a2 = arg0->unk_58;
        var_a3 = arg0->unk_5A;
    } else {
        var_v1 = arg0->unk_56;
        var_a1 = arg0->unk_54;
        var_a2 = arg0->unk_50;
        var_a3 = arg0->unk_52;
    }
    D_800F8520[0].v.tc[1] = var_a3;
    D_800F8520[1].v.tc[1] = (var_a3 + var_v1) >> 1;
    D_800F8520[2].v.tc[1] = var_v1;
    D_800F8520[3].v.tc[1] = (var_v1 + var_a2) >> 1;
    D_800F8520[4].v.tc[1] = var_a2;
    D_800F8520[5].v.tc[1] = (var_a2 + var_a1) >> 1;
    D_800F8520[6].v.tc[1] = var_a1;
    D_800F8520[7].v.tc[1] = (var_a1 + var_a3) >> 1;
    func_800A5168(arg0);
}

void func_800A57E8(unk_36ED0* arg0, s32 arg1) {
    s32 var_a3;
    s32 var_t0;
    s32 var_v1;

    if (arg1 != 0) {
        var_a3 = arg0->unk_5E;
        var_t0 = arg0->unk_5C;
        var_v1 = arg0->unk_5A;
    } else {
        var_a3 = arg0->unk_56;
        var_t0 = arg0->unk_54;
        var_v1 = arg0->unk_52;
    }

    D_800F8520[1].v.tc[1] = var_a3;
    D_800F8520[2].v.tc[1] = D_800F8520[3].v.tc[1] = (var_a3 + var_v1) >> 1;
    D_800F8520[0].v.tc[1] = var_v1;
    D_800F8520[4].v.tc[1] = var_v1;
    D_800F8520[5].v.tc[1] = D_800F8520[6].v.tc[1] = (var_t0 + var_v1) >> 1;
    D_800F8520[7].v.tc[1] = var_t0;
    func_800A5168(arg0);
}

extern Gfx D_80140F0[];
extern unk_36ED0* D_800F89CC;
extern unk_36ED0* D_800F89D0;
extern unk_36ED0* D_800F8988;

void func_800A587C(void) {

    gSPVertex(D_800F89C4++, D_800F8520, 16, 0);
    gSPDisplayList(D_800F89C4++, D_80140F0);

    func_800A52FC(D_800F89CC, D_800F89CC->unk_00 & 0x80000000);
    D_800F8958[0].unk_00 = D_800F89CC;
    func_800A52FC(D_800F89D0, 0);
    D_800F8988 = D_800F89D0;
}

extern unk_800F8958* D_800F89B8;
extern unk_800F8958* D_800F89BC;
extern s32 D_800F89C0;

void func_800A5924(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (D_800F89CC == D_800F89B8->unk_00) {
        if (D_800F89CC->unk_00 & 0x80000000) {
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], (D_800F89CC->unk_5C + D_800F89CC->unk_5E) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], D_800F89CC->unk_5E));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89CC->unk_5E));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], D_800F89CC->unk_5E));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], (D_800F89CC->unk_5C + D_800F89CC->unk_5E) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], D_800F89CC->unk_5C));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89CC->unk_5C));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], D_800F89CC->unk_5C));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);

        gSPDisplayList(D_800F89C4++, D_800F89B8->unk_04);

        func_800A52FC(D_800F89D0, 0);
        D_800F89BC->unk_00 = D_800F89D0;
    } else {
        D_800F89C0 = 1;
        func_800A587C();
    }
}

void func_800A5CF0(void) {
    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (D_800F89D0 == D_800F89B8->unk_00) {
        if (D_800F89D0->unk_00 & 0x80000000) {
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], (D_800F89D0->unk_54 + D_800F89D0->unk_56) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], D_800F89D0->unk_56));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89D0->unk_56));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], D_800F89D0->unk_56));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], (D_800F89D0->unk_54 + D_800F89D0->unk_56) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], D_800F89D0->unk_54));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89D0->unk_54));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], D_800F89D0->unk_54));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];
        gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);
        gSPDisplayList(D_800F89C4++, D_800F89BC->unk_04);
        func_800A52FC(D_800F89CC, D_800F89CC->unk_00 & 0x80000000);
        D_800F89BC->unk_00 = D_800F89CC;
    } else {
        D_800F89C0 = 0;
        func_800A587C();
    }
}

extern s32 D_800F892C;
extern s32 D_800F89D4;
extern s32 D_800F89D8;
extern s32 D_800F89DC;

void func_800A60CC(void) {

    gSPVertex(D_800F89C4++, D_800F8520, 16, 0);
    if (D_800F89DC != 0) {
        if (D_800F892C != D_800F89D4) {
            gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
            gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
            D_800F892C = D_800F89D4;
        }

        switch (D_800F89CC->unk_00 & 0x6000) {
            case 0x0:
                gSPDisplayList(D_800F89C4++, D_80140F0);
                break;
            case 0x2000:
                gSPDisplayList(D_800F89C4++, D_80142C0);
                break;
            default:
                gSPDisplayList(D_800F89C4++, D_8014308);
                if (1) {}
                break;
        }
    } else {
        if (D_800F892C != D_800F89D4) {
            gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
            gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
            D_800F892C = D_800F89D4;
        }

        gSPDisplayList(D_800F89C4++, D_8014180);
        if (D_800F89D8 != 0) {
            if (D_800F892C != (D_800F89D4 + 1)) {
                gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4 + 1, G_ON);
                D_800F892C = D_800F89D4 + 1;
            }
            gSPDisplayList(D_800F89C4++, D_80140F0);
        }
    }
    func_800A5380(D_800F89CC, D_800F89CC->unk_00 & 0x80000000);
    D_800F8958[0].unk_00 = D_800F89CC;
    func_800A5380(D_800F89D0, 0);
    D_800F8988 = D_800F89D0;
}

void func_800A63A0(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (D_800F89CC == D_800F89B8->unk_00) {
        if (D_800F89CC->unk_00 & 0x80000000) {
            if (D_800F89CC->unk_00 & 0x600) {
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], D_800F89CC->unk_5A));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 1, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89CC->unk_5A + D_800F89CC->unk_5E) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89CC->unk_5E));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 3, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89CC->unk_5A + D_800F89CC->unk_5E) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], D_800F89CC->unk_5A));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 5, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89CC->unk_5A + D_800F89CC->unk_5C) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89CC->unk_5C));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 7, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89CC->unk_5A + D_800F89CC->unk_5C) >> 1));
            } else {
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], D_800F89CC->unk_5A));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 1, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89CC->unk_5A + D_800F89CC->unk_5E) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89CC->unk_5E));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 3, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89CC->unk_5E + D_800F89CC->unk_58) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[0], D_800F89CC->unk_58));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 5, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89CC->unk_58 + D_800F89CC->unk_5C) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89CC->unk_5C));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 7, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89CC->unk_5C + D_800F89CC->unk_5A) >> 1));
            }
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);

        if (D_800F89DC != 0) {
            if (D_800F892C != D_800F89D4) {
                gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            switch (D_800F89CC->unk_00 & 0x6000) {
                case 0x0:
                    gSPDisplayList(D_800F89C4++, D_800F89B8->unk_04);
                    break;
                case 0x2000:
                    gSPDisplayList(D_800F89C4++, D_800F89B8->unk_14);
                    break;
                default:
                    func_800A5560(D_800F89CC);
                    gSPDisplayList(D_800F89C4++, D_800F89B8->unk_20);
                    gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);
                    gSPDisplayList(D_800F89C4++, D_800F89B8->unk_18);
                    break;
            }
        } else {
            if (D_800F892C != D_800F89D4) {
                gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            gSPDisplayList(D_800F89C4++, D_800F89B8->unk_08);

            if (D_800F89D8 != 0) {
                if (D_800F892C != (D_800F89D4 + 1)) {
                    gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
                    gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4 + 1, G_ON);
                    D_800F892C = D_800F89D4 + 1;
                }

                gSPDisplayList(D_800F89C4++, D_800F89B8->unk_04);
            }
        }
        func_800A5380(D_800F89D0, 0);
        D_800F89BC->unk_00 = D_800F89D0;
    } else {
        D_800F89C0 = 1;
        func_800A60CC();
    }
}

void func_800A6CF4(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (D_800F89D0 == D_800F89B8->unk_00) {
        if (D_800F89D0->unk_00 & 0x80000000) {
            if (D_800F89D0->unk_00 & 0x600) {
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], D_800F89D0->unk_52));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 1, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89D0->unk_52 + D_800F89D0->unk_56) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89D0->unk_56));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 3, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89D0->unk_52 + D_800F89D0->unk_56) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], D_800F89D0->unk_52));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 5, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89D0->unk_52 + D_800F89D0->unk_54) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89D0->unk_54));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 7, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89D0->unk_52 + D_800F89D0->unk_54) >> 1));
            } else {
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], D_800F89D0->unk_52));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 1, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89D0->unk_52 + D_800F89D0->unk_56) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89D0->unk_56));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 3, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89D0->unk_56 + D_800F89D0->unk_50) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[0], D_800F89D0->unk_50));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 5, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89D0->unk_50 + D_800F89D0->unk_54) >> 1));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89D0->unk_54));
                gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 7, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89D0->unk_54 + D_800F89D0->unk_52) >> 1));
            }
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];
        gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);

        if (D_800F89DC != 0) {
            if (D_800F892C != D_800F89D4) {
                gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            switch (D_800F89CC->unk_00 & 0x6000) {
                case 0x0:
                    gSPDisplayList(D_800F89C4++, D_800F89BC->unk_04);
                    break;
                case 0x2000:
                    func_800A5560(D_800F89D0);
                    gSPDisplayList(D_800F89C4++, D_800F89B8->unk_1C);
                    gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);
                    gSPDisplayList(D_800F89C4++, D_800F89BC->unk_14);
                    break;
                default:
                    gSPDisplayList(D_800F89C4++, D_800F89BC->unk_18);
                    if (1) {}
                    break;
            }
        } else {
            if (D_800F892C != D_800F89D4) {
                gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }
            gSPDisplayList(D_800F89C4++, D_800F89BC->unk_08);

            if (D_800F89D8 != 0) {
                if (D_800F892C != (D_800F89D4 + 1)) {
                    gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
                    gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4 + 1, G_ON);
                    D_800F892C = D_800F89D4 + 1;
                }
                gSPDisplayList(D_800F89C4++, D_800F89BC->unk_04);
            }
        }
        func_800A5380(D_800F89CC, D_800F89CC->unk_00 & 0x80000000);
        D_800F89BC->unk_00 = D_800F89CC;
    } else {
        D_800F89C0 = 0;
        func_800A60CC();
    }
}

void func_800A7650(void) {

    gSPVertex(D_800F89C4++, D_800F8520, 16, 0);

    switch (D_800F89CC->unk_00 & 0x1800) {
        case 0x0:
            gSPDisplayList(D_800F89C4++, D_80140F0);
            break;
        case 0x800:
            gSPDisplayList(D_800F89C4++, D_8014520);
            break;
        default:
            gSPDisplayList(D_800F89C4++, D_80145E0);
            if (1) {}
            break;
    }
    func_800A573C(D_800F89CC, D_800F89CC->unk_00 & 0x80000000);
    D_800F8958[0].unk_00 = D_800F89CC;
    func_800A573C(D_800F89D0, 0);
    D_800F8988 = D_800F89D0;
}

void func_800A7764(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (D_800F89CC == D_800F89B8->unk_00) {
        if (D_800F89CC->unk_00 & 0x80000000) {
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], D_800F89CC->unk_5A));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89CC->unk_5A + D_800F89CC->unk_5E) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89CC->unk_5E));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89CC->unk_5E + D_800F89CC->unk_58) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], D_800F89CC->unk_58));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89CC->unk_58 + D_800F89CC->unk_5C) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89CC->unk_5C));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89CC->unk_5C + D_800F89CC->unk_5A) >> 1));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);

        switch (D_800F89CC->unk_00 & 0x1800) {
            case 0x0:
                gSPDisplayList(D_800F89C4++, D_800F89B8->unk_04);
                break;
            case 0x800:
                gSPDisplayList(D_800F89C4++, D_800F89B8->unk_24);
                break;
            default:
                gSPDisplayList(D_800F89C4++, D_800F89B8->unk_28);
                if (1) {}
                break;
        }

        func_800A573C(D_800F89D0, 0);
        D_800F89BC->unk_00 = D_800F89D0;
    } else {
        D_800F89C0 = 1;
        func_800A7650();
    }
}

void func_800A7BC0(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];
    if (D_800F89D0 == D_800F89B8->unk_00) {
        if (D_800F89D0->unk_00 & 0x80000000) {
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], D_800F89D0->unk_52));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89D0->unk_52 + D_800F89D0->unk_56) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89D0->unk_56));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89D0->unk_56 + D_800F89D0->unk_50) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], D_800F89D0->unk_50));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89D0->unk_50 + D_800F89D0->unk_54) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], D_800F89D0->unk_54));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], (D_800F89D0->unk_54 + D_800F89D0->unk_52) >> 1));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);

        switch (D_800F89CC->unk_00 & 0x1800) {
            case 0x0:
                gSPDisplayList(D_800F89C4++, D_800F89BC->unk_04);
                break;
            case 0x800:
                gSPDisplayList(D_800F89C4++, D_800F89BC->unk_24);
                break;
            default:
                gSPDisplayList(D_800F89C4++, D_800F89BC->unk_28);
                if (1) {}
                break;
        }

        func_800A573C(D_800F89CC, D_800F89CC->unk_00 & 0x80000000);
        D_800F89BC->unk_00 = D_800F89CC;
    } else {
        D_800F89C0 = 0;
        func_800A7650();
    }
}

void func_800A8028(void) {

    gSPVertex(D_800F89C4++, D_800F8520, 16, 0);
    gSPDisplayList(D_800F89C4++, D_80140F0);

    func_800A57E8(D_800F89CC, D_800F89CC->unk_00 & 0x80000000);
    D_800F8958[0].unk_00 = D_800F89CC;
    func_800A57E8(D_800F89D0, 0);
    D_800F8988 = D_800F89D0;
}

void func_800A80D0(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (D_800F89CC == D_800F89B8->unk_00) {
        if (D_800F89CC->unk_00 & 0x80000000) {
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], D_800F89CC->unk_5A));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], D_800F89CC->unk_5E));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], (D_800F89CC->unk_5E + D_800F89CC->unk_5A) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89CC->unk_5E + D_800F89CC->unk_5A) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], D_800F89CC->unk_5A));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89CC->unk_5C + D_800F89CC->unk_5A) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], (D_800F89CC->unk_5C + D_800F89CC->unk_5A) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], D_800F89CC->unk_5C));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];
        gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);
        gSPDisplayList(D_800F89C4++, D_800F89B8->unk_0C);
        func_800A57E8(D_800F89D0, 0);
        D_800F89BC->unk_00 = D_800F89D0;
    } else {
        D_800F89C0 = 1;
        func_800A8028();
    }
}

void func_800A84B8(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (D_800F89D0 == D_800F89B8->unk_00) {
        if (D_800F89D0->unk_00 & 0x80000000) {
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], D_800F89D0->unk_52));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], D_800F89D0->unk_56));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], (D_800F89D0->unk_56 + D_800F89D0->unk_52) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89D0->unk_56 + D_800F89D0->unk_52) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], D_800F89D0->unk_52));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (D_800F89D0->unk_54 + D_800F89D0->unk_52) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], (D_800F89D0->unk_54 + D_800F89D0->unk_52) >> 1));
            gSPModifyVertex(D_800F89C4++, D_800F89B8->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], D_800F89D0->unk_54));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];
        gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);
        gSPDisplayList(D_800F89C4++, D_800F89BC->unk_0C);
        func_800A57E8(D_800F89CC, D_800F89CC->unk_00 & 0x80000000);
        D_800F89BC->unk_00 = D_800F89CC;
    } else {
        D_800F89C0 = 0;
        func_800A8028();
    }
}

void func_800A88AC(void) {

    gSPVertex(D_800F89C4++, D_800F8520, 16, 0);
    gSPDisplayList(D_800F89C4++, D_8014210);
    func_800A52FC(D_800F89CC, 0);
    D_800F8958[0].unk_00 = D_800F89CC;
    func_800A52FC(D_800F89D0, 0);
    D_800F8988 = D_800F89D0;
}

void func_800A894C(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];
    if (D_800F89CC == D_800F89B8->unk_00) {
        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);
        gSPDisplayList(D_800F89C4++, D_800F89B8->unk_10);
        func_800A52FC(D_800F89D0, 0);
        D_800F89BC->unk_00 = D_800F89D0;
    } else {
        D_800F89C0 = 1;
        func_800A88AC();
    }
}

void func_800A8A5C(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];
    if (D_800F89D0 == D_800F89B8->unk_00) {
        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(D_800F89C4++, D_800F8520, 8, D_800F89BC->unk_2C);
        gSPDisplayList(D_800F89C4++, D_800F89BC->unk_10);
        func_800A52FC(D_800F89CC, D_800F89CC->unk_00 & 0x80000000);
        D_800F89BC->unk_00 = D_800F89CC;
    } else {
        D_800F89C0 = 0;
        func_800A88AC();
    }
}

typedef struct unk_800A8B74_arg_0 {
    unk_36ED0* unk_00;
    unk_36ED0* unk_04;
} unk_800A8B74_arg_0;

extern unk_36ED0 D_802A9FC0[];
extern unk_36ED0* D_800F851C;
extern unk_36ED0* D_800F89C8;
extern s32 D_800F8928;
extern void (*D_800CF948[])(void);

void func_800A8B74(unk_800A8B74_arg_0* arg0) {
    f32 var_fv0;
    s32 temp_a3;
    u32 temp_t1;
    unk_800CF528* temp_a1;

    D_800F89CC = arg0->unk_00;
    D_800F89D0 = arg0->unk_00 + 1;

    if (D_800F89D0 == D_800F851C) {
        D_800F89D0 = D_802A9FC0;
    }

    do {
        if (D_800F89D0->unk_00 & 0x40000000) {
            if (D_800F89D0 != arg0->unk_04) {

                D_800F89C8 = D_800F89D0 + 1;
                if (D_800F89C8 == D_800F851C) {
                    D_800F89C8 = D_802A9FC0;
                }
                var_fv0 = D_800F894C;

                do {
                    var_fv0 += D_800F8950;
                    if (D_800F89C8->unk_0C < var_fv0) {
                        break;
                    }

                    if ((D_800F89D0 = D_800F89C8) == arg0->unk_04) {
                        break;
                    }

                    D_800F89C8++;
                    if (D_800F89C8 == D_800F851C) {
                        D_800F89C8 = D_802A9FC0;
                    }
                } while (D_800F89D0->unk_00 & 0x40000000);
            }
        }

        temp_t1 = (u32) (D_800F89CC->unk_00 & 0x1C0) >> 6;
        temp_a3 = D_800F89CC->unk_00 & 0x3F;
        if (temp_a3 != 0x3F) {
            temp_a1 = &D_800CF8C8[temp_t1][temp_a3];
            D_800F89D4 = temp_a1->unk_10;

            if (D_800F892C != D_800F89D4) {
                gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            temp_a3 = D_800F89CC->unk_00 & 0x1FF;
            if (temp_a3 != D_800F8928) {
                gDPLoadSync(D_800F89C4++);
                gDPSetTextureImage(D_800F89C4++, G_IM_FMT_RGBA, G_IM_SIZ_16b, temp_a1->width, temp_a1->texture);
                gDPLoadBlock(D_800F89C4++, temp_a1->tile, 0, 0, 2047, CALC_DXT(temp_a1->width, G_IM_SIZ_16b));

                D_800F8928 = temp_a3;
                D_800F8930[0] = temp_a1->unk_16;
                D_800F8930[1] = temp_a1->unk_18;
                D_800F8930[2] = temp_a1->unk_1A;
                D_800F8930[3] = temp_a1->unk_1C;
                D_800F8930[4] = temp_a1->unk_1E;
            }
        }
        D_800F89DC = D_800F89CC->unk_00 & 0x7E00;
        D_800CF948[temp_t1]();

        D_800F89CC = D_800F89D0++;
        if (D_800F89D0 == D_800F851C) {
            D_800F89D0 = D_802A9FC0;
        }
    } while (D_800F89CC != arg0->unk_04);
}

extern void (*D_800CF968[])(void);

void func_800A8F1C(unk_800A8B74_arg_0* arg0) {
    f32 var_fv0;
    s32 temp_a3;
    u32 temp_t1;
    unk_800CF528* temp_a2;
    unk_36ED0* tempLimit = D_802A9FC0;

    D_800F89CC = arg0->unk_04 - 1;
    if ((u32) D_800F89CC < (u32) tempLimit) {
        D_800F89CC = D_800F851C - 1;
    }
    D_800F89D0 = arg0->unk_04;

    do {
        if (D_800F89CC->unk_00 & 0x40000000) {
            if (D_800F89CC != arg0->unk_00) {
                D_800F89C8 = D_800F89CC - 1;
                if ((u32) D_800F89C8 < (u32) tempLimit) {
                    D_800F89C8 = D_800F851C - 1;
                }
                var_fv0 = D_800F894C;

                do {
                    var_fv0 += D_800F8950;
                    if (D_800F89C8->unk_0C < var_fv0) {
                        break;
                    }

                    if ((D_800F89CC = D_800F89C8) == arg0->unk_00) {
                        break;
                    }

                    D_800F89C8--;
                    if ((u32) D_800F89C8 < (u32) tempLimit) {
                        D_800F89C8 = D_800F851C - 1;
                    }
                } while (D_800F89CC->unk_00 & 0x40000000);
            }
        }
        temp_t1 = (u32) (D_800F89CC->unk_00 & 0x1C0) >> 6;
        temp_a3 = D_800F89CC->unk_00 & 0x3F;
        if (temp_a3 != 0x3F) {
            temp_a2 = &D_800CF8C8[temp_t1][temp_a3];
            D_800F89D4 = temp_a2->unk_10;

            if (D_800F892C != D_800F89D4) {
                gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            temp_a3 = D_800F89CC->unk_00 & 0x1FF;
            if (temp_a3 != D_800F8928) {
                gDPLoadSync(D_800F89C4++);
                gDPSetTextureImage(D_800F89C4++, G_IM_FMT_RGBA, G_IM_SIZ_16b, temp_a2->width, temp_a2->texture);
                gDPLoadBlock(D_800F89C4++, temp_a2->tile, 0, 0, 2047, CALC_DXT(temp_a2->width, G_IM_SIZ_16b));
                D_800F8928 = temp_a3;
                D_800F8930[0] = temp_a2->unk_16;
                D_800F8930[1] = temp_a2->unk_18;
                D_800F8930[2] = temp_a2->unk_1A;
                D_800F8930[3] = temp_a2->unk_1C;
                D_800F8930[4] = temp_a2->unk_1E;
            }
        }
        D_800F89DC = D_800F89CC->unk_00 & 0x7E00;
        D_800CF968[temp_t1]();

        D_800F89D0 = D_800F89CC--;
        if ((u32) D_800F89CC < (u32) tempLimit) {
            D_800F89CC = D_800F851C - 1;
        }
    } while (D_800F89D0 != arg0->unk_00);
}

Gfx* func_800A92FC(Gfx* gfx, Vtx* arg1, s32 arg2) {
    s32 i;

    while (arg2 > 30) {
        gSPVertex(gfx++, arg1, 30, 0);

        for (i = 0; i < 27; i += 3) {
            gSP2Triangles(gfx++, i + 1, i + 0, i + 4, 0, i + 4, i + 0, i + 3, 0);
            gSP2Triangles(gfx++, i + 0, i + 2, i + 3, 0, i + 3, i + 2, i + 5, 0);
            gSP2Triangles(gfx++, i + 2, i + 1, i + 5, 0, i + 5, i + 1, i + 4, 0);
        }
        arg2 -= 27;
        arg1 += 27;
    }

    gSPVertex(gfx++, arg1, arg2, 0);

    i = 0;
    do {
        gSP2Triangles(gfx++, i + 1, i + 0, i + 4, 0, i + 4, i + 0, i + 3, 0);
        gSP2Triangles(gfx++, i + 0, i + 2, i + 3, 0, i + 3, i + 2, i + 5, 0);
        gSP2Triangles(gfx++, i + 2, i + 1, i + 5, 0, i + 5, i + 1, i + 4, 0);
        i += 3;
        arg2 -= 3;
    } while (arg2 > 3);

    return gfx;
}

extern s32 D_800CCFE0;
extern s32 D_800F8518;
extern Gfx D_8014040[];
extern Gfx D_8014078[];

Gfx* func_800A95B4(Gfx* gfx) {
    s32 temp_t0;
    u32 temp_t1;
    unk_800CF528* temp_a1;

    if (D_800F8518 < 3) {
        return gfx;
    }
    D_800F89D8 = 1;
    D_800F89C4 = gfx;
    gSPDisplayList(D_800F89C4++, D_8014040);
    gSPDisplayList(D_800F89C4++, D_8014078);
    gDPSetPrimColor(D_800F89C4++, 0, 0, (255 - (u8) (D_800CCFE0 * 8)), 0, 0, 255);

    D_800F8928 = D_800F892C = -1;
    D_800F8958[0].unk_00 = D_800F8958[1].unk_00 = 0;
    D_800F89C0 = 0;
    D_800F89CC = D_802A9FC0;
    D_800F89D0 = &D_802A9FC0[1];
    do {

        temp_t1 = (u32) (D_800F89CC->unk_00 & 0x1C0) >> 6;
        temp_t0 = D_800F89CC->unk_00 & 0x3F;
        if (temp_t0 != 0x3F) {
            temp_a1 = &D_800CF8C8[temp_t1][temp_t0];
            D_800F89D4 = temp_a1->unk_10;
            if (D_800F892C != D_800F89D4) {
                gSPTexture(D_800F89C4++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(D_800F89C4++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            temp_t0 = D_800F89CC->unk_00 & 0x1FF;
            if (temp_t0 != D_800F8928) {
                gDPLoadSync(D_800F89C4++);
                gDPSetTextureImage(D_800F89C4++, G_IM_FMT_RGBA, G_IM_SIZ_16b, temp_a1->width, temp_a1->texture);
                gDPLoadBlock(D_800F89C4++, temp_a1->tile, 0, 0, 2047, CALC_DXT(temp_a1->width, G_IM_SIZ_16b));

                D_800F8928 = temp_t0;
                D_800F8930[0] = temp_a1->unk_16;
                D_800F8930[1] = temp_a1->unk_18;
                D_800F8930[2] = temp_a1->unk_1A;
                D_800F8930[3] = temp_a1->unk_1C;
                D_800F8930[4] = temp_a1->unk_1E;
            }
        }
        D_800F89DC = D_800F89CC->unk_00 & 0x7E00;
        D_800CF948[temp_t1]();

        D_800F89CC = D_800F89D0++;

    } while (D_800F89CC != D_800F851C);

    return D_800F89C4;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/36ED0/func_800A9938.s")

s32 func_800AA394(void) {
    s32 i;
    u32 var_v1 = D_8010B7B0.unk_000[1];

    for (i = 0; i < D_8010B7B0.unk_000[1]; i++) {

        D_8010B7B0.unk_020[i].unk_10 &= ~0x600;
        D_8010B7B0.unk_020[i].unk_10 &= ~0x38000;
        D_8010B7B0.unk_020[i].unk_10 &= ~0x40000000;

        var_v1 += (s32) ((D_8010B7B0.unk_020[i].unk_00.x + ((1.1f + (0.7f * i)) * D_8010B7B0.unk_020[i].unk_00.y)) +
                         ((2.2f + (1.2f * i)) * D_8010B7B0.unk_020[i].unk_00.z * (4.4f + (0.9f * i))) +
                         D_8010B7B0.unk_020[i].unk_0C + ((5.5f + (0.8f * i)) * D_8010B7B0.unk_020[i].unk_0E * 4.8f)) +
                  D_8010B7B0.unk_020[i].unk_10 * (0xFE - i) + D_8010B7B0.unk_520[i] * (0x93DE - i * 2);
    }

    for (i = 0; i < D_8010B7B0.unk_000[1]; i++) {
        var_v1 += (D_8010B7B0.unk_5A0[i] * i);
        var_v1 += (D_8010B7B0.unk_5E0[i] * (i + 0x10));
        var_v1 += (D_8010B7B0.unk_620[i] * (i + 0x80));
        var_v1 += (D_8010B7B0.unk_660[i] * (i + 0x100));
        var_v1 += (D_8010B7B0.unk_6A0[i] * (i + 0x800));
        var_v1 += (D_8010B7B0.unk_6E0[i] * (i + 0x1000));
        var_v1 += (D_8010B7B0.unk_720[i] * (i + 0x8000));
        var_v1 += (D_8010B7B0.unk_760[i] * (i + 0x10000));
        var_v1 += (D_8010B7B0.unk_7A0[i] * (i + 0x80000));
    }

    return var_v1;
}
