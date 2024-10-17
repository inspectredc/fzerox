#include "global.h"
#include "audio.h"
#include "fzx_racer.h"

extern unk_struct_F8 D_800E5990[];
extern unk_struct_1DC D_800E5220[];
extern unk_800E5D70 D_800E5D70[];
extern unk_800CD970 D_800CD970[];

void func_800810E0(unk_struct_F8* arg0, unk_struct_20* arg1) {
    arg0->unk_00 = 1;
    arg0->unk_04.unk_58.unk_00.unk_00.unk_00 = *arg1;
}

void func_8008112C(unk_struct_F8* arg0, unk_8008112C_arg_1* arg1) {
    arg0->unk_00 = 1;
    arg0->unk_04.unk_00 = arg1->unk_00;
    arg0->unk_04.unk_58.unk_00.unk_00.unk_00 = arg1->unk_58.unk_00.unk_00.unk_00;
}

void func_800811B0(unk_struct_F8* arg0, unk_struct_9C* arg1) {
    arg0->unk_00 = 4;
    arg0->unk_04.unk_58 = *arg1;
}

void func_800811F0(unk_struct_F8* arg0, unk_8008112C_arg_1* arg1) {
    arg0->unk_00 = 4;
    arg0->unk_04.unk_00 = arg1->unk_00;
    arg0->unk_04.unk_58 = arg1->unk_58;
}

void func_80081268(unk_struct_F8* arg0, s32 arg1, unk_struct_9C* arg2) {
    arg0->unk_00 = arg1;
    arg0->unk_04.unk_58.unk_00.unk_00 = arg2->unk_00.unk_00;
}

void func_800812A4(unk_struct_F8* arg0, s32 arg1, unk_8008112C_arg_1* arg2) {
    arg0->unk_00 = arg1;
    arg0->unk_04.unk_00 = arg2->unk_00;
    arg0->unk_04.unk_58.unk_00.unk_00 = arg2->unk_58.unk_00.unk_00;
}

void func_80081318(unk_struct_F8* arg0, unk_struct_68* arg1) {
    arg0->unk_00 = 5;
    arg0->unk_04.unk_58.unk_00 = *arg1;
}

void func_80081364(unk_struct_F8* arg0, unk_8008112C_arg_1* arg1) {
    arg0->unk_00 = 5;
    arg0->unk_04.unk_00 = arg1->unk_00;
    arg0->unk_04.unk_58.unk_00 = arg1->unk_58.unk_00;
}

void func_800813E8(unk_struct_F8* arg0) {
    unk_8008112C_arg_1* var = &arg0->unk_04;

    var->unk_00.unk_18[0] += (var->unk_00.unk_18[3] - var->unk_00.unk_18[0]) * var->unk_00.unk_18[6];
    var->unk_00.unk_18[1] += (var->unk_00.unk_18[4] - var->unk_00.unk_18[1]) * var->unk_00.unk_18[6];
    var->unk_00.unk_18[2] += (var->unk_00.unk_18[5] - var->unk_00.unk_18[2]) * var->unk_00.unk_18[6];
    var->unk_00.unk_18[7] += (var->unk_00.unk_18[8] - var->unk_00.unk_18[7]) * var->unk_00.unk_18[9];
    var->unk_00.unk_18[10] += (var->unk_00.unk_18[12] - var->unk_00.unk_18[10]) * var->unk_00.unk_18[14];
    var->unk_00.unk_18[11] += (var->unk_00.unk_18[13] - var->unk_00.unk_18[11]) * var->unk_00.unk_18[15];
}

// Likely uses the previously defined structs
void func_8008149C(unk_struct_F8* arg0) {
    s32 pad;
    unk_8008112C_arg_1* var = &arg0->unk_04;

    var->unk_00.unk_00.x +=
        (var->unk_58.unk_00.unk_00.unk_00.unk_00.x - var->unk_00.unk_00.x) * var->unk_58.unk_00.unk_00.unk_00.unk_18;
    var->unk_00.unk_00.y +=
        (var->unk_58.unk_00.unk_00.unk_00.unk_00.y - var->unk_00.unk_00.y) * var->unk_58.unk_00.unk_00.unk_00.unk_18;
    var->unk_00.unk_00.z +=
        (var->unk_58.unk_00.unk_00.unk_00.unk_00.z - var->unk_00.unk_00.z) * var->unk_58.unk_00.unk_00.unk_00.unk_18;
    var->unk_00.unk_0C.x +=
        (var->unk_58.unk_00.unk_00.unk_00.unk_0C.x - var->unk_00.unk_0C.x) * var->unk_58.unk_00.unk_00.unk_00.unk_1C;
    var->unk_00.unk_0C.y +=
        (var->unk_58.unk_00.unk_00.unk_00.unk_0C.y - var->unk_00.unk_0C.y) * var->unk_58.unk_00.unk_00.unk_00.unk_1C;
    var->unk_00.unk_0C.z +=
        (var->unk_58.unk_00.unk_00.unk_00.unk_0C.z - var->unk_00.unk_0C.z) * var->unk_58.unk_00.unk_00.unk_00.unk_1C;
}

extern f32 D_800DD230[];
void func_80081550(unk_struct_F8* arg0) {
    f32 temp_fa0;
    f32 sp40;
    f32 sp3C;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 temp_v0;
    f32 sp28;
    unk_8008112C_arg_1* temp_v0_4;
    unk_struct_9C* temp_v1;

    arg0->unk_04.unk_58.unk_00.unk_00.unk_30.x +=
        (arg0->unk_04.unk_58.unk_00.unk_00.unk_30.y - arg0->unk_04.unk_58.unk_00.unk_00.unk_30.x) *
        arg0->unk_04.unk_58.unk_00.unk_00.unk_30.z;
    arg0->unk_04.unk_58.unk_00.unk_00.unk_3C.x +=
        (arg0->unk_04.unk_58.unk_00.unk_00.unk_3C.y - arg0->unk_04.unk_58.unk_00.unk_00.unk_3C.x) *
        arg0->unk_04.unk_58.unk_00.unk_00.unk_3C.z;
    arg0->unk_04.unk_58.unk_00.unk_00.unk_48.x +=
        (arg0->unk_04.unk_58.unk_00.unk_00.unk_48.y - arg0->unk_04.unk_58.unk_00.unk_00.unk_48.x) *
        arg0->unk_04.unk_58.unk_00.unk_00.unk_48.z;
    temp_v1 = &arg0->unk_04.unk_58;
    temp_v0 = Math_Round(arg0->unk_04.unk_58.unk_00.unk_00.unk_3C.x * 11.377778f);

    sp3C = temp_v1->unk_00.unk_00.unk_30.x * D_800DD230[temp_v0 & 0xFFF];
    sp40 = temp_v1->unk_00.unk_00.unk_30.x * D_800DD230[(temp_v0 + 0x400) & 0xFFF];

    temp_v0 = Math_Round(temp_v1->unk_00.unk_00.unk_48.x * 11.377778f);
    temp_fv0 = D_800DD230[temp_v0 & 0xFFF] * sp40;
    temp_fv1 = D_800DD230[(temp_v0 + 0x400) & 0xFFF] * sp40;

    temp_fa0 = (temp_v1->unk_00.unk_00.unk_00.unk_0C.x * temp_fv1) + (temp_v1->unk_00.unk_00.unk_24.x * temp_fv0) +
               (temp_v1->unk_00.unk_00.unk_00.unk_18 * sp3C);
    temp_ft5 = (temp_v1->unk_00.unk_00.unk_00.unk_0C.y * temp_fv1) + (temp_v1->unk_00.unk_00.unk_24.y * temp_fv0) +
               (temp_v1->unk_00.unk_00.unk_00.unk_1C * sp3C);
    sp28 = (temp_v1->unk_00.unk_00.unk_00.unk_0C.z * temp_fv1) + (temp_v1->unk_00.unk_00.unk_24.z * temp_fv0) +
           (temp_v1->unk_00.unk_00.unk_20 * sp3C);

    temp_v0_4 = &arg0->unk_04;
    switch (arg0->unk_00) {
        case 2:
            temp_v0_4->unk_00.unk_00 = temp_v1->unk_00.unk_00.unk_00.unk_00;
            temp_v0_4->unk_00.unk_0C.x = temp_v1->unk_00.unk_00.unk_00.unk_00.x + temp_fa0;
            temp_v0_4->unk_00.unk_0C.y = temp_v1->unk_00.unk_00.unk_00.unk_00.y + temp_ft5;
            temp_v0_4->unk_00.unk_0C.z = temp_v1->unk_00.unk_00.unk_00.unk_00.z + sp28;
            break;
        case 3:
            temp_v0_4->unk_00.unk_0C = temp_v1->unk_00.unk_00.unk_00.unk_00;
            temp_v0_4->unk_00.unk_00.x = temp_v1->unk_00.unk_00.unk_00.unk_00.x + temp_fa0;
            temp_v0_4->unk_00.unk_00.y = temp_v1->unk_00.unk_00.unk_00.unk_00.y + temp_ft5;
            temp_v0_4->unk_00.unk_00.z = temp_v1->unk_00.unk_00.unk_00.unk_00.z + sp28;
            break;
    }
}

void func_80081794(unk_struct_F8* arg0, unk_struct_1DC* arg1);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80081794.s")

void func_80081E24(unk_struct_F8* arg0) {
    s32 pad;
    unk_8008112C_arg_1* var = &arg0->unk_04;

    var->unk_58.unk_00.unk_00.unk_30.x +=
        (var->unk_58.unk_00.unk_00.unk_3C.x - var->unk_58.unk_00.unk_00.unk_30.x) * var->unk_58.unk_00.unk_60;
    var->unk_58.unk_00.unk_00.unk_30.y +=
        (var->unk_58.unk_00.unk_00.unk_3C.y - var->unk_58.unk_00.unk_00.unk_30.y) * var->unk_58.unk_00.unk_60;
    var->unk_58.unk_00.unk_00.unk_30.z +=
        (var->unk_58.unk_00.unk_00.unk_3C.z - var->unk_58.unk_00.unk_00.unk_30.z) * var->unk_58.unk_00.unk_60;

    var->unk_58.unk_00.unk_00.unk_48.x +=
        (var->unk_58.unk_00.unk_54.x - var->unk_58.unk_00.unk_00.unk_48.x) * var->unk_58.unk_00.unk_64;
    var->unk_58.unk_00.unk_00.unk_48.y +=
        (var->unk_58.unk_00.unk_54.y - var->unk_58.unk_00.unk_00.unk_48.y) * var->unk_58.unk_00.unk_64;
    var->unk_58.unk_00.unk_00.unk_48.z +=
        (var->unk_58.unk_00.unk_54.z - var->unk_58.unk_00.unk_00.unk_48.z) * var->unk_58.unk_00.unk_64;

    var->unk_00.unk_00.x = var->unk_58.unk_00.unk_00.unk_00.unk_00.x +
                           (var->unk_58.unk_00.unk_00.unk_24.x * var->unk_58.unk_00.unk_00.unk_30.x) +
                           (var->unk_58.unk_00.unk_00.unk_00.unk_18 * var->unk_58.unk_00.unk_00.unk_30.y) +
                           (var->unk_58.unk_00.unk_00.unk_00.unk_0C.x * var->unk_58.unk_00.unk_00.unk_30.z);
    var->unk_00.unk_00.y = var->unk_58.unk_00.unk_00.unk_00.unk_00.y +
                           (var->unk_58.unk_00.unk_00.unk_24.y * var->unk_58.unk_00.unk_00.unk_30.x) +
                           (var->unk_58.unk_00.unk_00.unk_00.unk_1C * var->unk_58.unk_00.unk_00.unk_30.y) +
                           (var->unk_58.unk_00.unk_00.unk_00.unk_0C.y * var->unk_58.unk_00.unk_00.unk_30.z);
    var->unk_00.unk_00.z = var->unk_58.unk_00.unk_00.unk_00.unk_00.z +
                           (var->unk_58.unk_00.unk_00.unk_24.z * var->unk_58.unk_00.unk_00.unk_30.x) +
                           (var->unk_58.unk_00.unk_00.unk_20 * var->unk_58.unk_00.unk_00.unk_30.y) +
                           (var->unk_58.unk_00.unk_00.unk_00.unk_0C.z * var->unk_58.unk_00.unk_00.unk_30.z);

    var->unk_00.unk_0C.x = var->unk_58.unk_00.unk_00.unk_00.unk_00.x +
                           (var->unk_58.unk_00.unk_00.unk_24.x * var->unk_58.unk_00.unk_00.unk_48.x) +
                           (var->unk_58.unk_00.unk_00.unk_00.unk_18 * var->unk_58.unk_00.unk_00.unk_48.y) +
                           (var->unk_58.unk_00.unk_00.unk_00.unk_0C.x * var->unk_58.unk_00.unk_00.unk_48.z);
    var->unk_00.unk_0C.y = var->unk_58.unk_00.unk_00.unk_00.unk_00.y +
                           (var->unk_58.unk_00.unk_00.unk_24.y * var->unk_58.unk_00.unk_00.unk_48.x) +
                           (var->unk_58.unk_00.unk_00.unk_00.unk_1C * var->unk_58.unk_00.unk_00.unk_48.y) +
                           (var->unk_58.unk_00.unk_00.unk_00.unk_0C.y * var->unk_58.unk_00.unk_00.unk_48.z);
    var->unk_00.unk_0C.z = var->unk_58.unk_00.unk_00.unk_00.unk_00.z +
                           (var->unk_58.unk_00.unk_00.unk_24.z * var->unk_58.unk_00.unk_00.unk_48.x) +
                           (var->unk_58.unk_00.unk_00.unk_20 * var->unk_58.unk_00.unk_00.unk_48.y) +
                           (var->unk_58.unk_00.unk_00.unk_00.unk_0C.z * var->unk_58.unk_00.unk_00.unk_48.z);
}

void func_80082068(unk_struct_F8* arg0, unk_struct_1DC* arg1) {

    switch (arg0->unk_00) {
        case 1:
            func_8008149C(arg0);
            break;
        case 4:
            func_80081794(arg0, arg1);
            break;
        case 2:
        case 3:
            func_80081550(arg0);
            break;
        case 5:
            func_80081E24(arg0);
            break;
    }
    func_800813E8(arg0);
}

void func_800820F4(unk_struct_F8* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    unk_8008112C_arg_1* temp_v0_3 = &arg0->unk_04;
    unk_struct_9C* temp_v0 = &arg0->unk_04.unk_58;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.unk_00.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_00.unk_00.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_00.unk_00.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.unk_0C.x = arg2->x;
        temp_v0->unk_00.unk_00.unk_00.unk_0C.y = arg2->y;
        temp_v0->unk_00.unk_00.unk_00.unk_0C.z = arg2->z;
    }
    if (arg3 != NULL) {
        temp_v0_3->unk_00.unk_18[3] = arg3->x;
        temp_v0_3->unk_00.unk_18[4] = arg3->y;
        temp_v0_3->unk_00.unk_18[5] = arg3->z;
    }
    if (arg4 != NULL) {
        arg0->unk_04.unk_00.unk_18[8] = *arg4;
    }
}

void func_8008217C(unk_struct_F8* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    unk_8008112C_arg_1* temp_v0_3 = &arg0->unk_04;
    unk_struct_9C* temp_v0 = &arg0->unk_04.unk_58;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.unk_00.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_00.unk_00.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_00.unk_00.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_00.unk_00.unk_30.y = arg2->x;
        temp_v0->unk_00.unk_00.unk_48.y = arg2->y;
        temp_v0->unk_00.unk_00.unk_3C.y = arg2->z;
    }
    if (arg3 != NULL) {
        temp_v0_3->unk_00.unk_18[3] = arg3->x;
        temp_v0_3->unk_00.unk_18[4] = arg3->y;
        temp_v0_3->unk_00.unk_18[5] = arg3->z;
    }
    if (arg4 != NULL) {
        arg0->unk_04.unk_00.unk_18[8] = *arg4;
    }
}

void func_80082204(unk_struct_F8* arg0, Vec3f* arg1, Mtx3F* arg2, Vec3f* arg3, Vec3f* arg4, Vec3f* arg5, f32* arg6) {
    unk_8008112C_arg_1* temp_v0_4 = &arg0->unk_04;
    unk_struct_9C* temp_v0 = &arg0->unk_04.unk_58;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.unk_00.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_00.unk_00.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_00.unk_00.z = arg1->z;
    }
    if (arg2 != NULL) {
        arg0->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C.x += arg2->mf[0][0] * 0.2f;
        arg0->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C.y += arg2->mf[0][1] * 0.2f;
        arg0->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C.z += arg2->mf[0][2] * 0.2f;
        arg0->unk_04.unk_58.unk_00.unk_00.unk_00.unk_18 += arg2->mf[1][0] * 0.2f;
        arg0->unk_04.unk_58.unk_00.unk_00.unk_00.unk_1C += arg2->mf[1][1] * 0.2f;
        arg0->unk_04.unk_58.unk_00.unk_00.unk_20 += arg2->mf[1][2] * 0.2f;
        arg0->unk_04.unk_58.unk_00.unk_00.unk_24.x += arg2->mf[2][0] * 0.2f;
        arg0->unk_04.unk_58.unk_00.unk_00.unk_24.y += arg2->mf[2][1] * 0.2f;
        arg0->unk_04.unk_58.unk_00.unk_00.unk_24.z += arg2->mf[2][2] * 0.2f;
        func_8006AA38((Mtx3F*) &arg0->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C);
    }
    if (arg3 != NULL) {
        temp_v0->unk_00.unk_00.unk_3C.x = arg3->x;
        temp_v0->unk_00.unk_00.unk_3C.y = arg3->y;
        temp_v0->unk_00.unk_00.unk_3C.z = arg3->z;
    }
    if (arg4 != NULL) {
        temp_v0->unk_00.unk_54.x = arg4->x;
        temp_v0->unk_00.unk_54.y = arg4->y;
        temp_v0->unk_00.unk_54.z = arg4->z;
    }
    if (arg5 != NULL) {
        temp_v0_4->unk_00.unk_18[3] = arg5->x;
        temp_v0_4->unk_00.unk_18[4] = arg5->y;
        temp_v0_4->unk_00.unk_18[5] = arg5->z;
    }
    if (arg6 != NULL) {
        arg0->unk_04.unk_00.unk_18[8] = *arg6;
    }
}

void func_800823A0(unk_struct_F8* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    unk_8008112C_arg_1* temp_v0_3 = &arg0->unk_04;
    unk_struct_9C* temp_v0 = &arg0->unk_04.unk_58;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_48.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_48.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_48.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_68[2] = arg2->x;
        temp_v0->unk_68[8] = arg2->y;
        temp_v0->unk_68[5] = arg2->z;
    }
    if (arg3 != NULL) {
        temp_v0_3->unk_00.unk_18[3] = arg3->x;
        temp_v0_3->unk_00.unk_18[4] = arg3->y;
        temp_v0_3->unk_00.unk_18[5] = arg3->z;
    }
    if (arg4 != NULL) {
        arg0->unk_04.unk_00.unk_18[8] = *arg4;
    }
}

f32 func_80082428(unk_8006FC8C** arg0, f32 arg1, f32 arg2) {
    f32 temp_fs3;
    s32 i;
    s32 sp54;
    s32 pad[4]; // potentially part of sp80
    Vec3f sp80;
    Mtx3F sp5C;

    sp54 = (s32) arg2 / 20;
    temp_fs3 = func_8009E85C(*arg0, arg1, &sp5C, 0.0f);

    for (i = 0; i < sp54; i++) {
        arg1 += 20.0f / temp_fs3;
        if (arg1 >= 1.0f) {
            *arg0 = (*arg0)->unk_34;
            arg1 -= 1.0f;
            arg1 *= (temp_fs3 / func_8009E538(*arg0, 0.0f, &sp80));
        }
    }

    arg1 += ((arg2 - ((f32) sp54 * 20.0f)) / temp_fs3);
    if (arg1 >= 1.0f) {
        *arg0 = (*arg0)->unk_34;
        arg1 -= 1.0f;
        arg1 *= (temp_fs3 / func_8009E538(*arg0, 0.0f, &sp80));
    }
    return arg1;
}

Mtx3F* func_800825A4(Mtx3F* arg0, unk_8006FC8C* arg1, f32 arg2) {
    s32 pad;
    f32 sp40;
    Mtx3F sp1C;

    func_8009E85C(arg1, arg2, &sp1C, func_8009E108(arg1, arg2, &sp40));
    *arg0 = sp1C;

    return arg0;
}

extern Vec3f D_800D52F8[];
extern Vec3f D_800D5328[];
typedef struct unk_80082624_arg_0 {
    s8 unk_00[0x8];
    s32 unk_08;
    s8 unk_0C[0x4];
    s32 unk_10;
    f32 unk_14;
} unk_80082624_arg_0;

void func_80082624(unk_struct_1DC* arg0, unk_8008112C_arg_1* arg1, unk_struct_9C* arg2, s32 arg3) {
    Vec3f* var_v0;

    if (arg3 == 2) {
        var_v0 = &D_800D5328[arg0->unk_08];
    } else {
        var_v0 = &D_800D52F8[arg0->unk_08];
    }
    arg2->unk_68[2] = var_v0->y;
    arg2->unk_68[5] = var_v0->z;
    arg1->unk_00.unk_18[8] = arg0->unk_14 = var_v0->x;

    arg0->unk_10 = 2;

    switch (arg0->unk_08) {
        case 1:
        case 2:
            arg0->unk_10 |= 1;
            break;
        default:
            break;
    }
}

void func_800826B8(unk_struct_1DC* arg0, unk_struct_F8* arg1) {
    arg0->unk_50 = arg1->unk_04.unk_00.unk_0C;

    arg0->unk_88 = arg1->unk_04.unk_00.unk_00;

    arg0->unk_5C.mf[1][0] = arg1->unk_04.unk_00.unk_18[0];
    arg0->unk_5C.mf[1][1] = arg1->unk_04.unk_00.unk_18[1];
    arg0->unk_5C.mf[1][2] = arg1->unk_04.unk_00.unk_18[2];
    arg0->unk_94.x = arg1->unk_04.unk_00.unk_18[7];
    arg0->unk_94.y = arg1->unk_04.unk_00.unk_18[10];
    arg0->unk_94.z = arg1->unk_04.unk_00.unk_18[11];
}

void func_8008271C(unk_struct_1DC* arg0) {
    Mtx3F* temp_a0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;

    arg0->unk_5C.mf[0][0] = arg0->unk_88.x - arg0->unk_50.x;
    arg0->unk_5C.mf[0][1] = arg0->unk_88.y - arg0->unk_50.y;
    arg0->unk_5C.mf[0][2] = arg0->unk_88.z - arg0->unk_50.z;

    func_8006AA38(&arg0->unk_5C);
    temp_fv0 = arg0->unk_5C.mf[0][0];
    temp_fv1 = arg0->unk_5C.mf[0][2];
    temp_fv0_2 = sqrtf(SQ(temp_fv0) + SQ(temp_fv1));
    if (temp_fv0_2 != 0.0f) {
        arg0->unk_80 = (f32) (arg0->unk_5C.mf[0][0] / temp_fv0_2);
        arg0->unk_84 = (f32) (arg0->unk_5C.mf[0][2] / temp_fv0_2);
    }
}

void func_800827C4(MtxF* arg0, MtxF* arg1, MtxF* arg2) {
    arg0->m[0][0] = (arg1->m[0][0] * arg2->m[0][0]) + (arg1->m[2][0] * arg2->m[0][2]);
    arg0->m[0][1] = (arg1->m[1][1] * arg2->m[0][1]) + (arg1->m[2][1] * arg2->m[0][2]);
    arg0->m[0][2] = arg1->m[2][2] * arg2->m[0][2];
    arg0->m[0][3] = -arg2->m[0][2];
    arg0->m[1][0] = (arg1->m[0][0] * arg2->m[1][0]) + (arg1->m[2][0] * arg2->m[1][2]);
    arg0->m[1][1] = (arg1->m[1][1] * arg2->m[1][1]) + (arg1->m[2][1] * arg2->m[1][2]);
    arg0->m[1][2] = arg1->m[2][2] * arg2->m[1][2];
    arg0->m[1][3] = -arg2->m[1][2];
    arg0->m[2][0] = (arg1->m[0][0] * arg2->m[2][0]) + (arg1->m[2][0] * arg2->m[2][2]);
    arg0->m[2][1] = (arg1->m[1][1] * arg2->m[2][1]) + (arg1->m[2][1] * arg2->m[2][2]);
    arg0->m[2][2] = arg1->m[2][2] * arg2->m[2][2];
    arg0->m[2][3] = -arg2->m[2][2];
    arg0->m[3][0] = (arg1->m[0][0] * arg2->m[3][0]) + (arg1->m[2][0] * arg2->m[3][2]);
    arg0->m[3][1] = (arg1->m[1][1] * arg2->m[3][1]) + (arg1->m[2][1] * arg2->m[3][2]);
    arg0->m[3][2] = (arg1->m[2][2] * arg2->m[3][2]) + arg1->m[3][2];
    arg0->m[3][3] = -arg2->m[3][2];
}

void func_80082960(MtxF* arg0, Mtx* arg1) {
    s32 pad[4];
    s64 var_v1;
    f32 temp_fv0;
    s32 i;
    s32 j;

    for (i = 3; i >= 0; i--) {
        for (j = 3; j >= 0; j--) {
            temp_fv0 = arg0->m[i][j] * 65536.0f;
            if (temp_fv0 < 0.0f) {
                var_v1 = temp_fv0 - 0.5f;
            } else {
                var_v1 = temp_fv0 + 0.5f;
            }

            if (arg1) {}
            arg1->u.i[i][j] = var_v1 >> 0x10;
            arg1->u.f[i][j] = var_v1 & 0xFFFF;
        }
    }
}

extern s32 D_800CCFB0;
extern f32 D_800CD8A8;
extern f32 D_800CD8AC;
extern s16 D_800E5E8C;

void func_80082A6C(GfxPool* arg0, unk_struct_1DC* arg1) {
    Vec3f sp64;
    Vec3f sp58;
    f32 var_fv0;
    f32 var_fv1;

    func_8006D03C(&arg0->unk_20008[arg1->unk_00], &arg1->unk_11C, arg1->unk_94.x, arg1->unk_A0, arg1->unk_A4,
                  arg1->unk_A8, arg1->unk_94.y, arg1->unk_AC, arg1->unk_94.z, &arg1->unk_118);

    if (D_800E5E8C != 0) {
        var_fv0 = D_800CD8AC;
        var_fv1 = D_800CD8A8;
        if (D_800CCFB0 & 1) {
            var_fv0 = 0.0f - var_fv0;
            var_fv1 = 0.0f - var_fv1;
        }
        sp58.x = arg1->unk_50.x + (arg1->unk_5C.xz * var_fv0);
        sp58.y = arg1->unk_50.y + (arg1->unk_5C.yz * var_fv0);
        sp58.z = arg1->unk_50.z + (arg1->unk_5C.zz * var_fv0);
        sp64.x = arg1->unk_88.x + (arg1->unk_5C.xz * var_fv1);
        sp64.y = arg1->unk_88.y + (arg1->unk_5C.yz * var_fv1);
        sp64.z = arg1->unk_88.z + (arg1->unk_5C.zz * var_fv1);
    } else {
        sp58 = arg1->unk_50;
        sp64 = arg1->unk_88;
    }

    func_8006CC98(&arg0->unk_20108[arg1->unk_00], &arg1->unk_15C, sp58.x, sp58.y, sp58.z, sp64.x, sp64.y, sp64.z,
                  arg1->unk_5C.mf[1][0], arg1->unk_5C.mf[1][1], arg1->unk_5C.mf[1][2]);

    func_800827C4(&arg1->unk_19C, &arg1->unk_11C, &arg1->unk_15C);
    func_80082960(&arg1->unk_19C, &arg0->unk_20208[arg1->unk_00]);
}

extern s32 D_800E5FB8;

void func_80082C80(unk_struct_1DC* arg0) {
    s32 pad[3];
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fa0;
    f32 var_fv1;
    Racer* temp_v0;

    temp_v0 = &gRacers[D_800E5FB8];
    temp_fa1 = temp_v0->unk_0C.unk_34.x - arg0->unk_50.x;
    temp_ft4 = temp_v0->unk_0C.unk_34.y - arg0->unk_50.y;
    temp_ft5 = temp_v0->unk_0C.unk_34.z - arg0->unk_50.z;

    var_fv1 = sqrtf(SQ(temp_fa1) + SQ(temp_ft4) + SQ(temp_ft5));

    if (var_fv1 != 0.0f) {
        temp_fa0 =
            (-((temp_fa1 * arg0->unk_5C.xz) + (temp_ft4 * arg0->unk_5C.yz) + (temp_ft5 * arg0->unk_5C.zz))) / var_fv1;
        var_fv1 *= temp_fa0;
    }
    if ((var_fv1 >= -1000.0f) && (var_fv1 <= 1000.0f)) {
        func_800BA2D0(((var_fv1 + 1000.0f) / 2000.0f) * 127.0f);
    }
}

void func_80082E40(f32* arg0, f32* arg1, f32* arg2) {
    f32 temp_fv0;

    temp_fv0 = 1.0f / (SQ(*arg0) + SQ(*arg1) + SQ(*arg2));
    *arg0 *= temp_fv0;
    *arg1 *= temp_fv0;
    *arg2 *= temp_fv0;
}

void func_80082E90(MtxF* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 pad[2];
    f32 temp_fa0;
    f32 temp_ft1;
    f32 temp_ft4;
    f32 sp18;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 temp_v0;

    func_80082E40(&arg2, &arg3, &arg4);
    temp_v0 = Math_Round(arg1 * 11.377778f);
    temp_fv1 = D_800DD230[temp_v0 & 0xFFF];
    temp_ft4 = D_800DD230[(temp_v0 + 0x400) & 0xFFF];
    temp_fv0 = 1.0f - temp_ft4;
    temp_ft1 = arg2 * arg3 * temp_fv0;
    temp_fa0 = arg3 * arg4 * temp_fv0;
    sp18 = arg4 * arg2 * temp_fv0;
    arg0->m[0][0] = ((1.0f - SQ(arg2)) * temp_ft4) + SQ(arg2);
    arg0->m[2][1] = temp_fa0 - (arg2 * temp_fv1);
    arg0->m[1][2] = (arg2 * temp_fv1) + temp_fa0;
    arg0->m[1][1] = ((1.0f - SQ(arg3)) * temp_ft4) + SQ(arg3);
    arg0->m[2][0] = (arg3 * temp_fv1) + sp18;
    arg0->m[0][2] = sp18 - (arg3 * temp_fv1);
    arg0->m[2][2] = ((1.0f - SQ(arg4)) * temp_ft4) + SQ(arg4);
    arg0->m[1][0] = temp_ft1 - (arg4 * temp_fv1);
    arg0->m[0][1] = (arg4 * temp_fv1) + temp_ft1;
    arg0->m[3][3] = 1.0f;
    arg0->m[0][3] = arg0->m[1][3] = arg0->m[2][3] = arg0->m[3][0] = arg0->m[3][1] = arg0->m[3][2] = 0.0f;
}

typedef struct unk_800832EC_arg_2 {
    u32 unk_00;
    u32 unk_04;
    s32* unk_08;
    u8* unk_0C;
} unk_800832EC_arg_2;

void func_80083034(unk_800832EC_arg_2* arg0) {
    u32 i;

    for (i = 0; i < arg0->unk_04; i++) {
        arg0->unk_08[i] = 0;
    }
}

u8* func_80083074(u32 arg0, unk_800832EC_arg_2* arg1) {
    s32 var_v0;
    u32 temp_a2;
    u32 temp_v0;
    s32 var_a0;
    u32 var_a3;

    if ((arg0 % arg1->unk_00) != 0) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }

    temp_a2 = var_v0 + (arg0 / arg1->unk_00);
    if (arg1->unk_04 < temp_a2) {
        return NULL;
    }

    temp_v0 = (arg1->unk_04 - temp_a2) + 1;

    for (var_a0 = 0; var_a0 < temp_v0; var_a0++) {
        for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
            if (arg1->unk_08[var_a0 + var_a3] != 0) {
                break;
            }
        }
        if (var_a3 >= temp_a2) {
            for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
                arg1->unk_08[var_a0 + var_a3] = temp_a2 - var_a3;
            }
            return &arg1->unk_0C[arg1->unk_00 * var_a0];
        }
    }
    return NULL;
}

void func_80083210(u8* arg0, unk_800832EC_arg_2* arg1) {
    s32 temp_v1;
    u32 i;
    u32 temp_lo;

    if (arg0 != NULL) {
        temp_lo = (size_t) (arg0 - arg1->unk_0C) / arg1->unk_00;
        temp_v1 = arg1->unk_08[temp_lo];

        for (i = 0; i < temp_v1; i++) {
            arg1->unk_08[temp_lo + i] = 0;
        }
    }
}

u8* func_800832EC(u8* arg0, u32 arg1, unk_800832EC_arg_2* arg2) {
    u8* temp_v0;
    u32 var_a2;
    s32 var_v1;

    temp_v0 = func_80083074(arg1, arg2);
    if (temp_v0 == NULL) {
        return NULL;
    }
    if (arg0 == NULL) {
        return temp_v0;
    }
    var_v1 = arg2->unk_08[(size_t) (arg0 - arg2->unk_0C) / arg2->unk_00];
    var_a2 = arg2->unk_00 * var_v1;
    if (arg1 < var_a2) {
        var_a2 = arg1;
    }

    bcopy(arg0, temp_v0, var_a2);
    func_80083210(arg0, arg2);
    return temp_v0;
}

extern s32 gNumPlayers;
extern s32 D_800DCE44;
extern GfxPool D_1000000;

Gfx* func_800833AC(Gfx* gfx, s32 arg1, s32 arg2) {
    unk_struct_1DC* temp_v0 = &D_800E5220[arg2];

    if (temp_v0->unk_E0 == 1) {
        gSPViewport(gfx++, &D_1000000.unk_2C2C8[arg2]);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, temp_v0->unk_B0, temp_v0->unk_B4, temp_v0->unk_B8, temp_v0->unk_BC);
    } else {
        // FAKE
        if (1) {}
        gfx = func_8006A00C(gfx, arg1);
        if ((gNumPlayers == 1) && (D_800DCE44 != 6) && (D_800DCE44 != 0x11)) {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
        }
    }
    return gfx;
}

void func_80083500(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {

    D_800E5990[arg0].unk_04.unk_58.unk_68[1] = D_800E5990[arg0].unk_04.unk_58.unk_68[2] = arg1;
    D_800E5990[arg0].unk_04.unk_58.unk_68[4] = D_800E5990[arg0].unk_04.unk_58.unk_68[5] = arg2;
    D_800E5990[arg0].unk_04.unk_58.unk_68[7] = D_800E5990[arg0].unk_04.unk_58.unk_68[8] = arg3;
}

void func_80083548(unk_800E5D70* arg0, unk_struct_F8* arg1) {
    arg0->unk_00 = arg1;
}

void func_80083550(unk_800E5D70* arg0, unk_struct_20_2* arg1) {
    arg0->unk_0C = arg1;
}

void func_80083558(unk_800E5D70* arg0, Vec3f* arg1, Mtx3F* arg2, Racer* arg3) {
    arg0->unk_10 = arg1;
    arg0->unk_14 = arg2;
    arg0->unk_18 = arg3;
}

void func_80083568(unk_800E5D70* arg0, Vec3f* arg1, Mtx3F* arg2) {
    arg0->unk_1C = arg1;
    arg0->unk_20 = arg2;
}

void func_80083574(unk_800E5D70* arg0, unk_struct_C* arg1) {
    arg0->unk_04 = arg1;
    arg0->unk_08 = 0;
}

void func_80084CDC(unk_struct_20_2* arg0, s32 arg1);

void func_80083580(unk_800E5D70* arg0, s32 arg1) {
    func_80084CDC(arg0->unk_0C, arg1);
}

void func_800835A0(unk_800E5D70* arg0, f32* arg1) {
    arg0->unk_00->unk_04.unk_00.unk_18[13] = *arg1;
}

bool func_800835B0(unk_800E5D70* arg0) {
    bool ret;
    unk_struct_C* var_s0;

    while (true) {
        ret = false;
        var_s0 = arg0->unk_04;
        if (var_s0 == NULL) {
            return true;
        }

        if (var_s0->unk_04 != NULL) {
            ((void (*)(unk_800E5D70*, void*)) var_s0->unk_04)(arg0, var_s0->unk_08);
        }
        switch (var_s0->unk_00) {
            case 0:
                arg0->unk_04++;
                continue;
            case -1:
                arg0->unk_08 = 0;
                var_s0 = NULL;
                ret = true;
                break;
            case -2:
                arg0->unk_08++;
                ret = true;
                break;
            default:
                if (++arg0->unk_08 >= var_s0->unk_00) {
                    var_s0++;
                    arg0->unk_08 = 0;
                }
                break;
        }
        break;
    }

    arg0->unk_04 = var_s0;
    return ret;
}

void func_800836A4(unk_800E5D70* arg0, unk_8008112C_arg_1* arg1) {
    func_8008112C(arg0->unk_00, arg1);
}

void func_800836C4(unk_800E5D70* arg0, unk_8008112C_arg_1* arg1) {
    func_800812A4(arg0->unk_00, 2, arg1);
}

void func_800836EC(unk_800E5D70* arg0, unk_8008112C_arg_1* arg1) {
    func_800812A4(arg0->unk_00, 3, arg1);
}

void func_80083714(unk_800E5D70* arg0, unk_8008112C_arg_1* arg1) {
    func_800811F0(arg0->unk_00, arg1);
}

void func_80083734(unk_800E5D70* arg0, unk_8008112C_arg_1* arg1) {
    func_80081364(arg0->unk_00, arg1);
}

void func_80085390(Vec3f*, unk_struct_20_2*, unk_struct_14*);

void func_80083754(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp38[2];
    Vec3f sp2C;

    func_80085390(sp38, arg0->unk_0C, arg1);
    sp2C.x = sp38[0].x + arg0->unk_10->x;
    sp2C.y = sp38[0].y + arg0->unk_10->y;
    sp2C.z = sp38[0].z + arg0->unk_10->z;
    func_800820F4(arg0->unk_00, &sp2C, &sp38[1], NULL, NULL);
}

void func_800853D4(Vec3f*, unk_struct_20_2*, unk_struct_14*);

void func_800837DC(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp34[3];
    Vec3f sp28;

    func_800853D4(sp34, arg0->unk_0C, arg1);
    sp28.x = sp34[0].x + arg0->unk_10->x;
    sp28.y = sp34[0].y + arg0->unk_10->y;
    sp28.z = sp34[0].z + arg0->unk_10->z;
    func_800820F4(arg0->unk_00, &sp28, &sp34[1], &sp34[2], NULL);
}

void func_80085434(unk_80085434_arg_0*, unk_struct_20_2*, unk_struct_14*);

void func_80083864(unk_800E5D70* arg0, unk_struct_14* arg1) {
    unk_80085434_arg_0 sp34;
    Vec3f sp28;

    func_80085434(&sp34, arg0->unk_0C, arg1);
    sp28.x = sp34.unk_00[0].x + arg0->unk_10->x;
    sp28.y = sp34.unk_00[0].y + arg0->unk_10->y;
    sp28.z = sp34.unk_00[0].z + arg0->unk_10->z;
    func_800820F4(arg0->unk_00, &sp28, &sp34.unk_00[1], NULL, &sp34.unk_18);
}

void func_80085494(unk_80085494_arg_0*, unk_struct_20_2*, unk_struct_14*);

void func_800838F0(unk_800E5D70* arg0, unk_struct_14* arg1) {
    unk_80085494_arg_0 sp38;
    Vec3f sp2C;

    func_80085494(&sp38, arg0->unk_0C, arg1);
    sp2C.x = sp38.unk_00[0].x + arg0->unk_10->x;
    sp2C.y = sp38.unk_00[0].y + arg0->unk_10->y;
    sp2C.z = sp38.unk_00[0].z + arg0->unk_10->z;
    func_800820F4(arg0->unk_00, &sp2C, &sp38.unk_00[1], &sp38.unk_00[2], &sp38.unk_24);
}

void func_8008397C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp48[2];
    Vec3f sp3C;
    Vec3f sp30;

    func_80085390(sp48, arg0->unk_0C, arg1);
    sp3C.x = sp48[0].x + arg0->unk_10->x;
    sp3C.y = sp48[0].y + arg0->unk_10->y;
    sp3C.z = sp48[0].z + arg0->unk_10->z;

    sp30.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp48[1].z + arg0->unk_20->mf[1][0] * sp48[1].y +
             arg0->unk_20->mf[2][0] * sp48[1].x;
    sp30.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp48[1].z + arg0->unk_20->mf[1][1] * sp48[1].y +
             arg0->unk_20->mf[2][1] * sp48[1].x;
    sp30.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp48[1].z + arg0->unk_20->mf[1][2] * sp48[1].y +
             arg0->unk_20->mf[2][2] * sp48[1].x;
    func_800820F4(arg0->unk_00, &sp3C, &sp30, NULL, NULL);
}

void func_80083AAC(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp44[3];
    Vec3f sp38;
    Vec3f sp2C;

    func_800853D4(sp44, arg0->unk_0C, arg1);
    sp38.x = sp44[0].x + arg0->unk_10->x;
    sp38.y = sp44[0].y + arg0->unk_10->y;
    sp38.z = sp44[0].z + arg0->unk_10->z;

    sp2C.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp44[1].z + arg0->unk_20->mf[1][0] * sp44[1].y +
             arg0->unk_20->mf[2][0] * sp44[1].x;
    sp2C.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp44[1].z + arg0->unk_20->mf[1][1] * sp44[1].y +
             arg0->unk_20->mf[2][1] * sp44[1].x;
    sp2C.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp44[1].z + arg0->unk_20->mf[1][2] * sp44[1].y +
             arg0->unk_20->mf[2][2] * sp44[1].x;
    func_800820F4(arg0->unk_00, &sp38, &sp2C, &sp44[2], NULL);
}

void func_80083BDC(unk_800E5D70* arg0, unk_struct_14* arg1) {
    unk_80085434_arg_0 sp44;
    Vec3f sp38;
    Vec3f sp2C;

    func_80085434(&sp44, arg0->unk_0C, arg1);
    sp38.x = sp44.unk_00[0].x + arg0->unk_10->x;
    sp38.y = sp44.unk_00[0].y + arg0->unk_10->y;
    sp38.z = sp44.unk_00[0].z + arg0->unk_10->z;

    sp2C.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp44.unk_00[1].z + arg0->unk_20->mf[1][0] * sp44.unk_00[1].y +
             arg0->unk_20->mf[2][0] * sp44.unk_00[1].x;
    sp2C.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp44.unk_00[1].z + arg0->unk_20->mf[1][1] * sp44.unk_00[1].y +
             arg0->unk_20->mf[2][1] * sp44.unk_00[1].x;
    sp2C.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp44.unk_00[1].z + arg0->unk_20->mf[1][2] * sp44.unk_00[1].y +
             arg0->unk_20->mf[2][2] * sp44.unk_00[1].x;
    func_800820F4(arg0->unk_00, &sp38, &sp2C, NULL, &sp44.unk_18);
}

void func_80083D10(unk_800E5D70* arg0, unk_struct_14* arg1) {
    unk_80085494_arg_0 sp48;
    Vec3f sp3C;
    Vec3f sp30;

    func_80085494(&sp48, arg0->unk_0C, arg1);
    sp3C.x = sp48.unk_00[0].x + arg0->unk_10->x;
    sp3C.y = sp48.unk_00[0].y + arg0->unk_10->y;
    sp3C.z = sp48.unk_00[0].z + arg0->unk_10->z;

    sp30.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp48.unk_00[1].z + arg0->unk_20->mf[1][0] * sp48.unk_00[1].y +
             arg0->unk_20->mf[2][0] * sp48.unk_00[1].x;
    sp30.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp48.unk_00[1].z + arg0->unk_20->mf[1][1] * sp48.unk_00[1].y +
             arg0->unk_20->mf[2][1] * sp48.unk_00[1].x;
    sp30.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp48.unk_00[1].z + arg0->unk_20->mf[1][2] * sp48.unk_00[1].y +
             arg0->unk_20->mf[2][2] * sp48.unk_00[1].x;
    func_800820F4(arg0->unk_00, &sp3C, &sp30, &sp48.unk_00[2], &sp48.unk_24);
}

void func_80083E44(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80085390(sp20, arg0->unk_0C, arg1);
    func_800820F4(arg0->unk_00, &sp20[0], &sp20[1], NULL, NULL);
}

void func_80083E90(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_800853D4(sp24, arg0->unk_0C, arg1);
    func_800820F4(arg0->unk_00, &sp24[0], &sp24[1], &sp24[2], NULL);
}

void func_80083EDC(unk_800E5D70* arg0, unk_struct_14* arg1) {
    unk_80085434_arg_0 sp24;

    func_80085434(&sp24, arg0->unk_0C, arg1);
    func_800820F4(arg0->unk_00, &sp24.unk_00[0], &sp24.unk_00[1], NULL, &sp24.unk_18);
}

void func_80083F2C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    unk_80085494_arg_0 sp20;

    func_80085494(&sp20, arg0->unk_0C, arg1);
    func_800820F4(arg0->unk_00, &sp20.unk_00[0], &sp20.unk_00[1], &sp20.unk_00[2], &sp20.unk_24);
}

void func_80083F7C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80085390(sp20, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp20[0], &sp20[1], NULL, NULL);
}

void func_80083FC8(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_800853D4(sp24, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp24[0], &sp24[1], &sp24[2], NULL);
}

void func_80084014(unk_800E5D70* arg0, unk_struct_14* arg1) {
    unk_80085434_arg_0 sp24;

    func_80085434(&sp24, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp24.unk_00[0], &sp24.unk_00[1], NULL, &sp24.unk_18);
}

void func_80084064(unk_800E5D70* arg0, unk_struct_14* arg1) {
    unk_80085494_arg_0 sp20;

    func_80085494(&sp20, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp20.unk_00[0], &sp20.unk_00[1], &sp20.unk_00[2], &sp20.unk_24);
}

void func_800840B4(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80085390(sp20, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp20[1], &sp20[0], NULL, NULL);
}

void func_80084100(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_800853D4(sp24, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp24[1], &sp24[0], &sp24[2], NULL);
}

void func_8008414C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    unk_80085434_arg_0 sp24;

    func_80085434(&sp24, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp24.unk_00[1], &sp24.unk_00[0], NULL, &sp24.unk_18);
}

void func_8008419C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    unk_80085494_arg_0 sp20;

    func_80085494(&sp20, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp20.unk_00[1], &sp20.unk_00[0], &sp20.unk_00[2], &sp20.unk_24);
}

// TODO: sp58/sp5C uninitialised?
void func_800841EC(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 sp64;
    s32 temp_v0;
    f32 sp5C;
    f32 sp58;
    f32 temp_fv0;
    Vec3f sp3C[2];
    Vec3f sp30;
    s32 pad;

    func_80085390(sp3C, arg0->unk_0C, arg1);
    sp64 = Math_Round(sp5C * 11.377778f);
    temp_v0 = Math_Round(sp58 * 11.377778f);
    temp_fv0 = D_800DD230[(temp_v0 + 0x400) & 0xFFF] * sp3C[0].x;
    sp30.x = D_800DD230[(sp64 + 0x400) & 0xFFF] * temp_fv0 + arg0->unk_10->x;
    sp30.y = sp3C[0].x * D_800DD230[temp_v0 & 0xFFF] + arg0->unk_10->y;
    sp30.z = arg0->unk_10->z - D_800DD230[sp64 & 0xFFF] * temp_fv0;
    func_8008217C(arg0->unk_00, &sp30, &sp3C[1], NULL, NULL);
}

void func_80084304(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 sp6C;
    s32 temp_v0;
    f32 sp64;
    f32 sp60;
    f32 temp_fv0;
    Vec3f sp38[3];
    Vec3f sp2C;
    s32 pad;

    func_800853D4(sp38, arg0->unk_0C, arg1);
    sp6C = Math_Round(sp64 * 11.377778f);
    temp_v0 = Math_Round(sp60 * 11.377778f);
    temp_fv0 = D_800DD230[(temp_v0 + 0x400) & 0xFFF] * sp38[0].x;
    sp2C.x = D_800DD230[(sp6C + 0x400) & 0xFFF] * temp_fv0 + arg0->unk_10->x;
    sp2C.y = sp38[0].x * D_800DD230[temp_v0 & 0xFFF] + arg0->unk_10->y;
    sp2C.z = arg0->unk_10->z - D_800DD230[sp6C & 0xFFF] * temp_fv0;
    func_8008217C(arg0->unk_00, &sp2C, &sp38[1], &sp38[2], NULL);
}

void func_8008441C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 sp64;
    s32 temp_v0;
    f32 sp5C;
    f32 sp58;
    f32 temp_fv0;
    unk_80085434_arg_0 sp38;
    Vec3f sp2C;
    s32 pad;

    func_80085434(&sp38, arg0->unk_0C, arg1);
    sp64 = Math_Round(sp5C * 11.377778f);
    temp_v0 = Math_Round(sp58 * 11.377778f);
    temp_fv0 = D_800DD230[(temp_v0 + 0x400) & 0xFFF] * sp38.unk_00[0].x;
    sp2C.x = D_800DD230[(sp64 + 0x400) & 0xFFF] * temp_fv0 + arg0->unk_10->x;
    sp2C.y = sp38.unk_00[0].x * D_800DD230[temp_v0 & 0xFFF] + arg0->unk_10->y;
    sp2C.z = arg0->unk_10->z - D_800DD230[sp64 & 0xFFF] * temp_fv0;
    func_8008217C(arg0->unk_00, &sp2C, &sp38.unk_00[1], NULL, &sp38.unk_18);
}

void func_80084538(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 sp74;
    s32 temp_v0;
    f32 sp6C;
    f32 sp68;
    f32 temp_fv0;
    unk_80085494_arg_0 sp3C;
    Vec3f sp30;
    s32 pad;

    func_80085494(&sp3C, arg0->unk_0C, arg1);
    sp74 = Math_Round(sp6C * 11.377778f);
    temp_v0 = Math_Round(sp68 * 11.377778f);
    temp_fv0 = D_800DD230[(temp_v0 + 0x400) & 0xFFF] * sp3C.unk_00[0].x;
    sp30.x = D_800DD230[(sp74 + 0x400) & 0xFFF] * temp_fv0 + arg0->unk_10->x;
    sp30.y = sp3C.unk_00[0].x * D_800DD230[temp_v0 & 0xFFF] + arg0->unk_10->y;
    sp30.z = arg0->unk_10->z - D_800DD230[sp74 & 0xFFF] * temp_fv0;
    func_8008217C(arg0->unk_00, &sp30, &sp3C.unk_00[1], &sp3C.unk_00[2], &sp3C.unk_24);
}

void func_80084654(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad;
    Vec3f sp64[2];
    Vec3f sp58;
    Mtx3F sp34;

    func_80085390(sp64, arg0->unk_0C, arg1);
    sp58.x = arg0->unk_10->x;
    sp58.y = arg0->unk_10->y;
    sp58.z = arg0->unk_10->z;
    sp34 = *arg0->unk_14;
    func_80082204(arg0->unk_00, &sp58, &sp34, &sp64[0], &sp64[1], NULL, NULL);
}

void func_80084700(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad;
    Vec3f sp60[3];
    Vec3f sp54;
    Mtx3F sp30;

    func_800853D4(sp60, arg0->unk_0C, arg1);
    sp54.x = arg0->unk_10->x;
    sp54.y = arg0->unk_10->y;
    sp54.z = arg0->unk_10->z;
    sp30 = *arg0->unk_14;
    func_80082204(arg0->unk_00, &sp54, &sp30, &sp60[0], &sp60[1], &sp60[2], NULL);
}

void func_800847B0(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad;
    unk_80085434_arg_0 sp60;
    Vec3f sp54;
    Mtx3F sp30;

    func_80085434(&sp60, arg0->unk_0C, arg1);
    sp54.x = arg0->unk_10->x;
    sp54.y = arg0->unk_10->y;
    sp54.z = arg0->unk_10->z;
    sp30 = *arg0->unk_14;
    func_80082204(arg0->unk_00, &sp54, &sp30, &sp60.unk_00[0], &sp60.unk_00[1], NULL, &sp60.unk_18);
}

void func_80084860(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad;
    unk_80085494_arg_0 sp64;
    Vec3f sp58;
    Mtx3F sp34;

    func_80085494(&sp64, arg0->unk_0C, arg1);
    sp58.x = arg0->unk_10->x;
    sp58.y = arg0->unk_10->y;
    sp58.z = arg0->unk_10->z;
    sp34 = *arg0->unk_14;
    func_80082204(arg0->unk_00, &sp58, &sp34, &sp64.unk_00[0], &sp64.unk_00[1], &sp64.unk_00[2], &sp64.unk_24);
}

// TODO: sort out unk_struct_20 and unk_struct_68 (conflicting struct copies)
void func_80084914(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    Vec3f sp38[2];
    Vec3f sp2C;

    func_80085390(sp38, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->unk_98;
    temp_v0->unk_98 = temp_v1->unk_0C.unk_00->unk_20;
    sp2C.x = sp38[0].x + arg0->unk_10->x;
    sp2C.y = sp38[0].y + arg0->unk_10->y;
    sp2C.z = sp38[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp2C, &sp38[1], 0, 0);
}

void func_80084A04(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    Vec3f sp34[3];
    Vec3f sp28;

    func_800853D4(sp34, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->unk_98;
    temp_v0->unk_98 = temp_v1->unk_0C.unk_00->unk_20;
    sp28.x = sp34[0].x + arg0->unk_10->x;
    sp28.y = sp34[0].y + arg0->unk_10->y;
    sp28.z = sp34[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp28, &sp34[1], &sp34[2], 0);
}

void func_80084AF4(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[6];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    unk_80085434_arg_0 sp34;
    Vec3f sp28;

    func_80085434(&sp34, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->unk_98;
    temp_v0->unk_98 = temp_v1->unk_0C.unk_00->unk_20;
    sp28.x = sp34.unk_00[0].x + arg0->unk_10->x;
    sp28.y = sp34.unk_00[0].y + arg0->unk_10->y;
    sp28.z = sp34.unk_00[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp28, &sp34.unk_00[1], 0, &sp34.unk_18);
}

void func_80084BE8(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    unk_80085494_arg_0 sp38;
    Vec3f sp2C;

    func_80085494(&sp38, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->unk_98;
    temp_v0->unk_98 = temp_v1->unk_0C.unk_00->unk_20;
    sp2C.x = sp38.unk_00[0].x + arg0->unk_10->x;
    sp2C.y = sp38.unk_00[0].y + arg0->unk_10->y;
    sp2C.z = sp38.unk_00[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp2C, &sp38.unk_00[1], &sp38.unk_00[2], &sp38.unk_24);
}

void func_80084CDC(unk_struct_20_2* arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        arg0->unk_00[i].unk_04 = 0;
        arg0->unk_00[i].unk_00 = 0;
    }
}

f32 func_80084D50(f32 arg0, s32 arg1, f32* arg2, s32 arg3) {
    s32 pad[2];
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 sp4;

    if (arg1 == 0) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        sp4 = CB(temp_fv0);
        temp_fa1 = temp_fv1 * arg0;
        sp8 = (((temp_fa1 * 21.0f) / 12.0f) - (temp_fv1 * 9.0f / 2.0f)) + (arg0 * 3.0f);
        spC = ((-temp_fa1 * 11.0f) / 12.0f) + (temp_fv1 * 3.0f / 2.0f);
        sp10 = temp_fa1 / 6.0f;
    } else if (arg1 == 1) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        sp4 = CB(temp_fv0) / 4.0f;
        temp_fa1 = temp_fv1 * arg0;
        sp8 = (((temp_fa1 * 7.0f) / 12.0f) - (temp_fv1 * 5.0f / 4.0f)) + (arg0 / 4.0f) + 7.0f / 12.0f;
        spC = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (arg0 / 2.0f) + 1.0f / 6.0f;
        sp10 = temp_fa1 / 6.0f;
    } else if ((arg3 < 7) || (arg1 < (arg3 - 5))) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        temp_fa1 = temp_fv1 * arg0;
        sp4 = CB(temp_fv0) / 6.0f;
        sp8 = ((temp_fa1 / 2.0f) - temp_fv1) + 2.0f / 3.0f;
        spC = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (arg0 / 2.0f) + 1.0f / 6.0f;
        sp10 = temp_fa1 / 6.0f;
    } else if (arg1 == arg3 - 5) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = temp_fv0 * temp_fv0;
        temp_fa1 = temp_fv1 * temp_fv0;
        sp4 = temp_fa1 / 6.0f;
        sp8 = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (temp_fv0 / 2.0f) + 1.0f / 6.0f;
        spC = (((temp_fa1 * 7.0f) / 12.0f) - (temp_fv1 * 5.0f / 4.0f)) + (temp_fv0 / 4.0f) + 7.0f / 12.0f;
        sp10 = CB(arg0) / 4.0f;
    } else if (arg1 == arg3 - 4) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = temp_fv0 * temp_fv0;
        temp_fa1 = temp_fv1 * temp_fv0;
        sp4 = temp_fa1 / 6.0f;
        sp8 = ((-temp_fa1 * 11.0f) / 12.0f) + (temp_fv1 * 3.0f / 2.0f);
        spC = (((temp_fa1 * 21.0f) / 12.0f) - (temp_fv1 * 9.0f / 2.0f)) + (temp_fv0 * 3.0f);
        sp10 = CB(arg0);
    }

    return sp4 * arg2[arg1] + sp8 * arg2[arg1 + 1] + spC * arg2[arg1 + 2] + sp10 * arg2[arg1 + 3];
}

void func_80085154(f32* arg0, unk_struct_8* arg1, unk_struct_14* arg2) {
    s32 temp_s0;
    s32 temp_t2;
    s32 temp_t6;
    s32 temp_t9;
    s32 var_s0;
    s32 var_v0;

    while (arg2->unk_08[arg1->unk_04] == 0) {
        arg1->unk_04++;
    }

    *arg0 = func_80084D50((f32) arg1->unk_00 / (f32) arg2->unk_08[arg1->unk_04], arg1->unk_04, arg2->unk_04[0],
                          arg2->unk_00);

    arg1->unk_00++;

    if (arg1->unk_00 >= arg2->unk_08[arg1->unk_04]) {
        arg1->unk_00 = 0;
        arg1->unk_04++;
        if (arg1->unk_04 >= (arg2->unk_00 - 3)) {
            arg1->unk_04 = -1;
        }
    }
}

// TODO: figure out potential bug or FAKE in the second loop, arg2->unk_04[i] overlaps with arg2->unk_08
void func_8008524C(Vec3f* arg0, unk_struct_8* arg1, unk_struct_14* arg2) {
    s32 temp_s0;
    s32 temp_t2;
    s32 temp_t6;
    s32 temp_t9;
    s32 var_s0;
    s32 var_v0;
    s32 i;

    while (arg2->unk_10[arg1->unk_04] == 0) {
        arg1->unk_04++;
    }

    for (i = 0; i < 3; i++) {
        arg0->v[i] = func_80084D50((f32) arg1->unk_00 / (f32) arg2->unk_10[arg1->unk_04], arg1->unk_04, arg2->unk_04[i],
                                   arg2->unk_00);
    }

    arg1->unk_00++;

    if (arg1->unk_00 >= arg2->unk_10[arg1->unk_04]) {
        arg1->unk_00 = 0;
        arg1->unk_04++;
        if (arg1->unk_04 >= (arg2->unk_00 - 3)) {
            arg1->unk_04 = -1;
        }
    }
}

void func_80085390(Vec3f* arg0, unk_struct_20_2* arg1, unk_struct_14* arg2) {
    func_8008524C(&arg0[0], &arg1->unk_00[0], &arg2[0]);
    func_8008524C(&arg0[1], &arg1->unk_00[1], &arg2[1]);
}

void func_800853D4(Vec3f* arg0, unk_struct_20_2* arg1, unk_struct_14* arg2) {
    func_8008524C(&arg0[0], &arg1->unk_00[0], &arg2[0]);
    func_8008524C(&arg0[1], &arg1->unk_00[1], &arg2[1]);
    func_8008524C(&arg0[2], &arg1->unk_00[2], &arg2[2]);
}

void func_80085434(unk_80085434_arg_0* arg0, unk_struct_20_2* arg1, unk_struct_14* arg2) {
    func_8008524C(&arg0->unk_00[0], &arg1->unk_00[0], &arg2[0]);
    func_8008524C(&arg0->unk_00[1], &arg1->unk_00[1], &arg2[1]);
    func_80085154(&arg0->unk_18, &arg1->unk_00[2], &arg2[2]);
}

void func_80085494(unk_80085494_arg_0* arg0, unk_struct_20_2* arg1, unk_struct_14* arg2) {
    func_8008524C(&arg0->unk_00[0], &arg1->unk_00[0], &arg2[0]);
    func_8008524C(&arg0->unk_00[1], &arg1->unk_00[1], &arg2[1]);
    func_8008524C(&arg0->unk_00[2], &arg1->unk_00[2], &arg2[2]);
    func_80085154(&arg0->unk_24, &arg1->unk_00[3], &arg2[3]);
}

extern s16 D_800E5E8A;
extern unk_struct_20_2 D_800E5E00[];
void func_80085510(void) {
    unk_800E5D70* var_s1;
    s32 i;
    Racer* temp_a3;
    unk_struct_1DC* var_s0;
    unk_struct_20_2* var_s4;
    unk_struct_F8* var_s3;

    for (i = 0, var_s0 = D_800E5220, var_s1 = D_800E5D70, var_s3 = D_800E5990, var_s4 = D_800E5E00; i < 4; i++) {
        var_s0->unk_00 = (s16) i;
        var_s0->unk_08 = 2;
        var_s0->unk_E0 = 0;
        func_80083548(var_s1, var_s3);
        func_80083550(var_s1, var_s4);
        temp_a3 = &gRacers[var_s0->unk_00];
        func_80083558(var_s1, &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);

        var_s1++;
        var_s3++;
        var_s4++;
        var_s0++;
    }
    D_800E5E8A = 0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80085610.s")

void func_80085B80(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80085B80.s")

extern s32* D_800CD9AC[];
extern u32 D_800CD9C0[];
extern u32 D_800CD9D0[];
extern u32 D_800CD9E0[];
extern u32 D_800CD9F0[];
extern u32 D_800CDA00[];
extern u32 D_800CDA10[];
extern u32 D_800CDA20[];
extern u32 D_800CDA30[];
extern u32 D_800CDA40[];
extern u32 D_800CDA50[];
extern u32 D_800CDA60[];
extern u32 D_800CDA70[];
extern u32 D_800CDA80[];
extern s32 D_800E5E80;
extern u8 D_80146A8[];
extern u8 D_80146B8[];
extern u8 D_80146C8[];
extern u8 D_80146D8[];
extern u8 D_80146E8[];
extern u8 D_80146F8[];
extern u8 D_8014708[];
extern u8 D_8014718[];
extern u8 D_8014728[];
extern u8 D_8014738[];
extern u8 D_8014748[];
extern u8 D_8014758[];
extern u8 D_8014768[];

void func_80086400(unk_struct_1DC* arg0) {
    s32* temp = D_800CD9AC[D_800E5E80];
    s32 temp2 = temp[arg0->unk_00];
    s16* sp24;
    u32* sp20;
    f32 var_fv0;
    f32 var_fv1;

    switch (temp2) {
        case 0:
            sp24 = func_80076BD4(D_80146A8);
            sp20 = D_800CD9C0;
            break;
        case 1:
            sp24 = func_80076BD4(D_80146B8);
            sp20 = D_800CD9D0;
            break;
        case 2:
            sp24 = func_80076BD4(D_80146C8);
            sp20 = D_800CD9E0;
            break;
        case 3:
            sp24 = func_80076BD4(D_80146D8);
            sp20 = D_800CD9F0;
            break;
        case 4:
            sp24 = func_80076BD4(D_80146E8);
            sp20 = D_800CDA00;
            break;
        case 5:
            sp24 = func_80076BD4(D_80146F8);
            sp20 = D_800CDA10;
            break;
        case 6:
            sp24 = func_80076BD4(D_8014708);
            sp20 = D_800CDA20;
            break;
        case 7:
            sp24 = func_80076BD4(D_8014718);
            sp20 = D_800CDA30;
            break;
        case 8:
            sp24 = func_80076BD4(D_8014728);
            sp20 = D_800CDA40;
            break;
        case 9:
            sp24 = func_80076BD4(D_8014738);
            sp20 = D_800CDA50;
            break;
        case 10:
            sp24 = func_80076BD4(D_8014748);
            sp20 = D_800CDA60;
            break;
        case 11:
            sp24 = func_80076BD4(D_8014758);
            sp20 = D_800CDA70;
            break;
        case 12:
            sp24 = func_80076BD4(D_8014768);
            sp20 = D_800CDA80;
            break;
    }

    var_fv0 = sp24[0] * 0.25f;
    arg0->unk_108 = var_fv0;
    arg0->unk_F8 = var_fv0;
    arg0->unk_E8 = var_fv0;

    var_fv0 = sp24[1] * 0.25f;
    arg0->unk_10C = var_fv0;
    arg0->unk_FC = var_fv0;
    arg0->unk_EC = var_fv0;

    arg0->unk_F0 = sp24[4] * 0.25f;
    arg0->unk_F4 = sp24[5] * 0.25f;

    var_fv1 = arg0->unk_F0 - arg0->unk_E8;
    arg0->unk_110 = var_fv1;
    arg0->unk_100 = var_fv1;
    var_fv1 = arg0->unk_F4 - arg0->unk_EC;
    arg0->unk_114 = var_fv1;
    arg0->unk_104 = var_fv1;

    var_fv0 = sp20[0];
    arg0->unk_D0 = var_fv0;
    arg0->unk_C0 = var_fv0;
    arg0->unk_B0 = var_fv0;

    var_fv0 = sp20[1];
    arg0->unk_D4 = var_fv0;
    arg0->unk_C4 = var_fv0;
    arg0->unk_B4 = var_fv0;

    var_fv0 = sp20[2];
    arg0->unk_D8 = var_fv0;
    arg0->unk_C8 = var_fv0;
    arg0->unk_B8 = var_fv0;

    var_fv0 = sp20[3];
    arg0->unk_DC = var_fv0;
    arg0->unk_CC = var_fv0;
    arg0->unk_BC = var_fv0;
}

void func_8008681C(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_80086FD0(void);
extern s32 D_800DCE44;
extern s32 D_800E5E80;

void func_8008675C(void) {
    s32 i;

    for (i = 0; i < D_800E5E80; i++) {
        func_8008681C(&D_800E5220[i], &D_800E5990[i], &D_800E5D70[i]);
    }

    if ((D_800DCE44 == 3) || (D_800DCE44 == 4) || (D_800DCE44 == 5)) {
        func_80086FD0();
    }
}

void func_80086B64(unk_struct_1DC*, unk_struct_F8*);
void func_800876A8(unk_struct_1DC*, unk_struct_F8*);
void func_800879E0(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_80087DB8(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_80087E14(unk_struct_1DC*, unk_struct_F8*);
void func_80087F60(unk_struct_1DC*, unk_struct_F8*);
void func_80087FAC(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_800885F0(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_80088660(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_800888D0(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);

extern s8 D_800DCE5C;
extern GfxPool* D_800DCCF0;

void func_8008681C(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_fv0;
    f32 var_fv1;
    f32 var_fv1_2;
    f32 var_fv1_3;
    f32 var_fv1_4;
    bool var_v0;
    u32 temp_s4;
    u32 var_v1;

    do {
        temp_s4 = var_v1 = arg0->unk_04;
        switch (var_v1) {
            case 0:
            case 1:
            case 2:
            case 16:
            default:
                break;
            case 3:
                func_80087E14(arg0, arg1);
                break;
            case 4:
                if (D_800DCE5C == 0) {
                    func_800876A8(arg0, arg1);
                }
                break;
            case 5:

                var_v0 = true;

                temp_fv0 = arg1->unk_04.unk_00.unk_18[8] - arg1->unk_04.unk_00.unk_18[7];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                temp_fv0 = arg1->unk_04.unk_00.unk_18[13] - arg1->unk_04.unk_00.unk_18[11];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                temp_fv0 = arg1->unk_04.unk_58.unk_68[2] - arg1->unk_04.unk_58.unk_68[1];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                temp_fv0 = arg1->unk_04.unk_58.unk_68[5] - arg1->unk_04.unk_58.unk_68[4];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                if (var_v0) {
                    arg0->unk_04 = 6;
                    arg1->unk_04.unk_00.unk_18[9] = 0.2f;
                    arg1->unk_04.unk_00.unk_18[6] = 1.0f;
                    arg1->unk_04.unk_00.unk_18[14] = 0.1f;
                    arg1->unk_04.unk_00.unk_18[15] = 0.2f;
                    arg1->unk_04.unk_58.unk_68[3] = 0.2f;
                    arg1->unk_04.unk_58.unk_68[6] = 0.2f;
                }
                break;
            case 6:
                func_800879E0(arg0, arg1, arg2);
                break;
            case 15:
                func_80087DB8(arg0, arg1, arg2);
                break;
            case 7:
                if (D_800DCE5C == 0) {
                    func_80087F60(arg0, arg1);
                }
                break;
            case 8:
                if (D_800DCE5C == 0) {
                    func_80087FAC(arg0, arg1, arg2);
                }
                break;
            case 9:
                if (D_800DCE5C == 0) {
                    func_80088660(arg0, arg1, arg2);
                }
                break;
            case 10:
                if (D_800DCE5C == 0) {
                    func_800885F0(arg0, arg1, arg2);
                }
                break;
            case 14:
                func_800888D0(arg0, arg1, arg2);
                break;
        }
        var_v1 = arg0->unk_04;
    } while (temp_s4 != var_v1);

    func_80082068(arg1, arg0);
    func_80086B64(arg0, arg1);
    func_800826B8(arg0, arg1);
    func_8008271C(arg0);
    func_80082A6C(D_800DCCF0, arg0);
    if ((D_800DCE44 == 1) || (D_800DCE44 == 2) || (D_800DCE44 == 0xE) || (D_800DCE44 == 0x15)) {
        func_80082C80(arg0);
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80086B64.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80086FD0.s")

extern s32 gNumPlayers;
extern Vec3f D_800D52F8[];
extern Vec3f D_800D5310[];
extern Vec3f D_800D5328[];
extern Vec3f D_800D5340[];
extern unk_struct_9C D_800D53B0;
extern unk_struct_9C D_800D54A4;

void func_800876A8(unk_struct_1DC* arg0, unk_struct_F8* arg1) {
    Vec3f* var_v1;
    f32 temp_fv0;
    s32 index;
    unk_8008112C_arg_1* temp_a0 = &arg1->unk_04;
    Racer* temp_t3 = &gRacers[arg0->unk_00];
    unk_struct_9C* temp_a3 = &arg1->unk_04.unk_58;
    Racer* temp_t4;
    s32 pad[5];

    temp_a3->unk_00.unk_00.unk_00.unk_00 = temp_t3->unk_180;

    *((Mtx3F*) &arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C) = temp_t3->unk_C0;

    temp_fv0 = (f32) arg0->unk_1C / 300.0f;
    temp_fv0 = (-2.0f * temp_fv0 * temp_fv0 * temp_fv0) + (3.0f * temp_fv0 * temp_fv0);
    arg1->unk_04.unk_58.unk_00.unk_00.unk_30.y = (-880.0f * temp_fv0) + 1000.0f;
    arg1->unk_04.unk_58.unk_00.unk_00.unk_48.y = (-360.0f * temp_fv0) + 180.0f;

    if (arg0->unk_1C >= 0x12C) {
        if (gNumPlayers == 2) {
            func_800811B0(arg1, &D_800D54A4);
            var_v1 = D_800D5340;
        } else {
            func_800811B0(arg1, &D_800D53B0);
            var_v1 = D_800D5310;
        }
        arg0->unk_04 = 5;
        temp_a3->unk_00.unk_00.unk_48.x = 0.0f;
        temp_a3->unk_00.unk_00.unk_48.y = 0.0f;
        temp_a3->unk_00.unk_00.unk_48.z = 0.0f;

        temp_a3->unk_68[1] = var_v1->y;
        temp_a3->unk_68[4] = var_v1->z;
        temp_a0->unk_00.unk_18[7] = var_v1->x;

        if (gNumPlayers == 2) {
            var_v1 = &D_800D5328[arg0->unk_08];
        } else {
            var_v1 = &D_800D52F8[arg0->unk_08];
        }
        temp_a3->unk_68[2] = var_v1->y;
        temp_a3->unk_68[5] = var_v1->z;
        temp_a0->unk_00.unk_18[8] = var_v1->x;

        temp_t4 = &gRacers[arg0->unk_00];
        temp_a3->unk_00.unk_54.x = temp_t4->unk_180.x - (var_v1->y * temp_t4->unk_C0.xx);
        temp_a3->unk_00.unk_54.y = temp_t4->unk_180.y - (var_v1->y * temp_t4->unk_C0.yx);
        temp_a3->unk_00.unk_54.z = temp_t4->unk_180.z - (var_v1->y * temp_t4->unk_C0.zx);

        arg0->unk_20 = temp_t4->unk_180;
        arg0->unk_2C = temp_t4->unk_C0;

        arg0->unk_14 = arg1->unk_04.unk_00.unk_18[8];
        arg0->unk_10 = 0;
        if ((arg0->unk_08 == 1) || (arg0->unk_08 == 2)) {
            arg0->unk_10 |= 1;
        }
        temp_a3->unk_68[6] = 0.1f;
        temp_a3->unk_68[3] = 0.1f;
        temp_a0->unk_00.unk_18[6] = 0.1f;
        temp_a0->unk_00.unk_18[9] = 0.1f;
        temp_a0->unk_00.unk_18[15] = 0.1f;
    } else {
        arg0->unk_1C++;
    }
}

extern Controller D_800DCE98[];
extern s32 D_800DD218[];
extern s32 gNumPlayers;
extern s32 D_800CD3CC;
extern s32 D_800CD8A4;
extern f32 D_800CDA90;
extern f32 D_800CDA94;
extern s32 D_800CDA9C;
extern s32 D_800DCE44;
extern s8 D_800DCE5C;
extern s16 D_800E5FBC;
extern s32 D_80141C78;

void func_800879E0(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    f32 var_fa0;
    f32 var_fv1;
    s32 index;
    bool var_v1;
    unk_8008112C_arg_1* temp_a1;
    s32 pad[4];
    Racer* temp_t0;
    unk_struct_9C* temp_a2 = &arg1->unk_04.unk_58;
    Controller* temp_t1;

    index = arg0->unk_00;
    temp_t0 = &gRacers[index];
    if (D_800DCE5C == 0) {
        if (temp_t0->unk_04 & 0x80000) {
            arg0->unk_04 = 7;
            func_80085B80(arg0, arg1, arg2);
            return;
        }
        if (temp_t0->unk_04 & 0x2000000) {
            if ((gNumPlayers >= 2) && (D_800E5FBC != 0)) {
                arg0->unk_04 = 9;
                func_80085B80(arg0, arg1, arg2);
                return;
            }
            if (D_800DCE44 == 0xE) {
                if ((D_800CD3CC != 2) && (D_800CD3CC != 3) && (D_800CD3CC != 4)) {
                    arg0->unk_04 = 8;
                } else if (temp_t0->unk_2A0 < D_80141C78) {
                    arg0->unk_04 = 8;
                } else {
                    arg0->unk_04 = 10;
                }
            } else {
                arg0->unk_04 = 8;
            }
            func_80085B80(arg0, arg1, arg2);
            return;
        }
    }

    temp_t1 = &D_800DCE98[D_800DD218[index]];
    var_v1 = false;

    if (!(temp_t0->unk_04 & 0x40000) && (temp_t1->unk_7C & 1)) {
        var_v1 = true;
        if (++arg0->unk_08 == 4) {
            arg0->unk_08 = 0;
        }
    }
    if (var_v1) {
        func_80082624(arg0, &arg1->unk_04, temp_a2, gNumPlayers);
    }
    temp_a1 = &arg1->unk_04;
    if ((D_800CD8A4 != 0) && (D_800DCE5C == 0)) {
        if ((temp_t1->unk_7A & 8) && !(temp_t0->unk_04 & 0x40000)) {
            if (++arg0->unk_0C > D_800CDA9C) {
                arg0->unk_0C = D_800CDA9C;
            }
        } else {
            if (--arg0->unk_0C < 0) {
                arg0->unk_0C = 0;
            }
        }
        temp_a2->unk_68[8] = (arg0->unk_0C * 180.0f) / D_800CDA9C;
    }
    if (arg0->unk_10 & 1) {

        var_fv1 = sqrtf(SQ(temp_t0->unk_5C) + SQ(temp_t0->unk_64)) - D_800CDA90;
        if (var_fv1 < 0.0f) {
            var_fa0 = arg0->unk_14;
        } else {
            var_fv1 /= (D_800CDA94 - D_800CDA90);
            if (var_fv1 > 1.0f) {
                var_fv1 = 1.0f;
            }

            var_fa0 = arg0->unk_14 + ((120.0f - arg0->unk_14) * var_fv1);
        }
        if (arg0->unk_10 & 2) {
            temp_a1->unk_00.unk_18[8] = var_fa0;
        } else {
            temp_a1->unk_00.unk_18[8] = var_fa0;
            temp_a1->unk_00.unk_18[7] = var_fa0;
        }
    }
    var_fv1 = temp_a1->unk_00.unk_18[8] - temp_a1->unk_00.unk_18[7];

    if (ABS(var_fv1) < 0.1f) {
        arg0->unk_10 &= ~2;
    }
}

void func_80087DB8(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 index = arg0->unk_00;

    if (gRacers[index].unk_04 & 0x80000) {
        arg0->unk_04 = 7;
        func_80085B80(arg0, arg1, arg2);
    }
}

extern s8 D_801190D0;

void func_80087E14(unk_struct_1DC* arg0, unk_struct_F8* arg1) {
    s32 i;
    unk_struct_9C* temp_v0 = &arg1->unk_04.unk_58;

    if (D_801190D0 != 0) {
        temp_v0->unk_00.unk_00.unk_48.y += 1.0f;
        if (temp_v0->unk_00.unk_00.unk_48.y >= 360.0f) {
            temp_v0->unk_00.unk_00.unk_48.y -= 360.0f;
        }
        if (arg0->unk_18 == 0) {
            for (i = 0; i < gNumPlayers; i++) {
                Controller* temp_a0 = &D_800DCE98[D_800DD218[i]];

                if (temp_a0->unk_7A & 8) {
                    temp_v0->unk_00.unk_00.unk_3C.y += 0.1f;
                }
                if (temp_a0->unk_7A & 4) {
                    temp_v0->unk_00.unk_00.unk_3C.y -= 0.1f;
                }
            }
        } else {
            arg0->unk_18 = 0;
            temp_v0->unk_00.unk_00.unk_3C.y = 20.0f;
        }

        if (temp_v0->unk_00.unk_00.unk_3C.y < -50.0f) {
            temp_v0->unk_00.unk_00.unk_3C.y = -50.0f;
        } else if (temp_v0->unk_00.unk_00.unk_3C.y > 90.0f) {
            temp_v0->unk_00.unk_00.unk_3C.y = 90.0f;
        }
    }
}

void func_80087F60(unk_struct_1DC* arg0, unk_struct_F8* arg1) {
    arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00 = gRacers[arg0->unk_00].unk_0C.unk_34;
}

void func_80088408(Vec3f* arg0, unk_8006FC8C* arg1, f32 arg2, unk_800CD970* arg3);
extern unk_struct_20 D_800D4CD8;
extern unk_struct_68 D_800D4EF0;
extern Vec3f D_800E5E90[];

void func_80087FAC(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    unk_struct_9C* temp_v1 = &arg1->unk_04.unk_58;
    Vec3f* temp_s1 = &D_800E5E90[arg0->unk_00];
    unk_800CD970* temp_a3 = &D_800CD970[arg0->unk_18];
    unk_8008112C_arg_1* temp_t0 = &arg1->unk_04;
    s16 temp_t1 = temp_a3->unk_00;
    Racer* temp_t2 = &gRacers[arg0->unk_00];
    unk_800CD8B0* temp_v0_2;
    s32 pad[2];

    if (temp_t2->unk_04 & 0x80000) {
        arg0->unk_04 = 7;
        func_80085B80(arg0, arg1, arg2);
        return;
    }
    switch (temp_a3->unk_00) {
        case 0:
            temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_t2->unk_180;
            temp_v1->unk_00.unk_00.unk_00.unk_0C.x = temp_s1->x;
            temp_v1->unk_00.unk_00.unk_00.unk_0C.y = temp_s1->y;
            temp_v1->unk_00.unk_00.unk_00.unk_0C.z = temp_s1->z;
            break;
        case 1:
            temp_v0_2 = temp_a3->unk_08;

            *((Mtx3F*) &temp_v1->unk_00.unk_00.unk_00.unk_0C) = temp_t2->unk_C0;

            temp_t0->unk_00.unk_18[3] = temp_v1->unk_00.unk_00.unk_00.unk_18;
            temp_t0->unk_00.unk_18[4] = temp_v1->unk_00.unk_00.unk_00.unk_1C;
            temp_t0->unk_00.unk_18[5] = temp_v1->unk_00.unk_00.unk_20;
            temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_t2->unk_180;

            temp_v1->unk_00.unk_00.unk_3C.x =
                temp_v0_2->unk_00.x +
                ((((temp_v0_2->unk_0C.x - temp_v0_2->unk_00.x) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_30);
            temp_v1->unk_00.unk_00.unk_3C.y =
                temp_v0_2->unk_00.y +
                ((((temp_v0_2->unk_0C.y - temp_v0_2->unk_00.y) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_30);
            temp_v1->unk_00.unk_00.unk_3C.z =
                temp_v0_2->unk_00.z +
                ((((temp_v0_2->unk_0C.z - temp_v0_2->unk_00.z) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_30);

            temp_v1->unk_00.unk_54.x =
                temp_v0_2->unk_18.x +
                ((((temp_v0_2->unk_24.x - temp_v0_2->unk_18.x) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_34);
            temp_v1->unk_00.unk_54.y =
                temp_v0_2->unk_18.y +
                ((((temp_v0_2->unk_24.y - temp_v0_2->unk_18.y) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_34);
            temp_v1->unk_00.unk_54.z =
                temp_v0_2->unk_18.z +
                ((((temp_v0_2->unk_24.z - temp_v0_2->unk_18.z) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_34);
        default:
            break;
    }

    if (arg0->unk_1C >= temp_a3->unk_02) {
        arg0->unk_1C = 0;
        if (++arg0->unk_18 >= 5) {
            arg0->unk_04 = 9;
            func_80085B80(arg0, arg1, arg2);
            return;
        }
        temp_a3 = &D_800CD970[arg0->unk_18];
        temp_t0->unk_00.unk_18[8] = temp_a3->unk_04;

        switch (temp_a3->unk_00) { /* irregular */
            case 0:
                if (temp_t1 != temp_a3->unk_00) {
                    func_800810E0(arg1, &D_800D4CD8);
                }
                temp_t0->unk_00.unk_18[3] = 0.0f;
                temp_t0->unk_00.unk_18[4] = 1.0f;
                temp_t0->unk_00.unk_18[5] = 0.0f;
                func_80088408(temp_s1, temp_t2->unk_0C.unk_00, temp_t2->unk_0C.unk_04, temp_a3);
                temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_t2->unk_180;
                temp_v1->unk_00.unk_00.unk_00.unk_0C.x = temp_s1->x;
                temp_v1->unk_00.unk_00.unk_00.unk_0C.y = temp_s1->y;
                temp_v1->unk_00.unk_00.unk_00.unk_0C.z = temp_s1->z;
                break;
            case 1:
                if (temp_t1 != temp_a3->unk_00) {
                    func_80081318(arg1, &D_800D4EF0);
                }
                temp_v0_2 = temp_a3->unk_08;
                temp_v1->unk_00.unk_00.unk_3C = temp_v0_2->unk_00;
                temp_v1->unk_00.unk_54 = temp_v0_2->unk_18;
                break;
            default:
                break;
        }
    } else {
        arg0->unk_1C++;
    }
}

extern f32 D_800CDA98;

void func_80088408(Vec3f* arg0, unk_8006FC8C* arg1, f32 arg2, unk_800CD970* arg3) {
    f32 abs;
    f32 sp60;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 var_fa0;
    f32 var_fv0;
    Mtx3F sp2C;
    unk_800CD8B0* sp28 = arg3->unk_08;

    sp60 = func_80082428(&arg1, arg2, sp28->unk_00.x);

    func_8009E6F0(arg1, sp60, arg0);
    func_800825A4(&sp2C, arg1, sp60);

    temp_ft4 = arg1->unk_18 * (1.0f - sp60) + arg1->unk_34->unk_18 * sp60;
    temp_fa1 = arg1->unk_1C * (1.0f - sp60) + arg1->unk_34->unk_1C * sp60;

    switch (arg1->unk_20 & 0x1C0) {
        case 0xC0:
            var_fv0 = sp28->unk_00.y * temp_fa1;
            var_fa0 = sp28->unk_00.z + temp_fa1;
            break;
        case 0x100:
            var_fv0 = sp28->unk_00.y * temp_ft4;
            var_fa0 = sp28->unk_00.z;
            break;
        default:
            if (sp28->unk_00.y >= 0.0f) {
                var_fv0 = sp28->unk_00.y * temp_ft4;
            } else {
                var_fv0 = sp28->unk_00.y * temp_fa1;
            }
            var_fa0 = sp28->unk_00.z;
            break;
    }

    abs = ABS(var_fv0);
    if (D_800CDA98 < abs) {
        abs = D_800CDA98;
        if (var_fv0 < 0) {
            var_fv0 = 0.0f - abs;
        } else {
            var_fv0 = abs;
        }
    }

    arg0->x += (sp2C.xy * var_fa0) + (sp2C.xz * var_fv0);
    arg0->y += (sp2C.yy * var_fa0) + (sp2C.yz * var_fv0);
    arg0->z += (sp2C.zy * var_fa0) + (sp2C.zz * var_fv0);
}

void func_800885F0(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {

    if (arg0->unk_1C <= 60) {
        arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00 = gRacers[arg0->unk_00].unk_0C.unk_34;
        arg0->unk_1C++;
    }
}

extern s32 gNumPlayers;
extern s32 D_800CD8A0;

void func_80088660(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 pad;
    f32 temp;
    unk_struct_9C* temp_v1 = &arg1->unk_04.unk_58;
    Racer* temp_a3 = &gRacers[arg0->unk_00];
    unk_8008112C_arg_1* temp_a0 = &arg1->unk_04;

    if (temp_a3->unk_04 & 0x80000) {
        arg0->unk_04 = 7;
        func_80085B80(arg0, arg1, arg2);
        return;
    }
    temp_v1->unk_00.unk_00.unk_00.unk_18 += temp_a3->unk_B4.x * 0.3f;
    temp_v1->unk_00.unk_00.unk_00.unk_1C += temp_a3->unk_B4.y * 0.3f;
    temp_v1->unk_00.unk_00.unk_20 += temp_a3->unk_B4.z * 0.3f;

    func_8006AC10((Mtx3F*) &temp_v1->unk_00.unk_00.unk_00.unk_0C);

    temp_a0->unk_00.unk_18[3] = temp_v1->unk_00.unk_00.unk_00.unk_18;
    temp_a0->unk_00.unk_18[4] = temp_v1->unk_00.unk_00.unk_00.unk_1C;
    temp_a0->unk_00.unk_18[5] = temp_v1->unk_00.unk_00.unk_20;

    temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_a3->unk_180;

    switch (arg0->unk_18) {
        case 0:
            if (++arg0->unk_1C >= 0xB4) {
                arg0->unk_18 = 1;
                arg0->unk_1C = 0;
                temp_v1->unk_00.unk_00.unk_30.z = 0.005f;
            }
            break;
        case 1:
            if (++arg0->unk_1C >= 0x12C) {
                arg0->unk_1C = 0;
                temp_v1->unk_00.unk_00.unk_30.y = (Math_Rand1() % 451) + 50.0f;
            }
            temp_v1->unk_00.unk_00.unk_48.y += 0.4f;

            if (temp_v1->unk_00.unk_00.unk_48.y >= 360.0f) {
                temp_v1->unk_00.unk_00.unk_48.y -= 360.0f;
            }
            break;
        default:
            break;
    }

    if ((D_800CD8A0 == arg0->unk_00) && (gNumPlayers == 2)) {

        if (arg0->unk_E4 < arg0->unk_E6) {
            temp = (f32) (arg0->unk_E4 + 1) / arg0->unk_E6;
            arg1->unk_04.unk_00.unk_18[13] = -30.0f - (-30.0f * temp);
        } else {
            arg1->unk_04.unk_00.unk_18[13] = 0.0f;
        }
    }
}

bool func_80088CB8(s32);

extern s16 D_800E5E88;
extern unk_struct_C D_i7_8014A4D0;
extern unk_struct_C D_i7_8014A7E0;
extern unk_struct_C D_i7_8014AB60;
extern unk_struct_C D_i7_8014B070;
extern unk_struct_C D_i7_8014B190;
extern unk_struct_C D_i7_8014B310;
extern u16 D_i7_8014BDF6;
extern Mtx3F D_802C49E0;
extern Vec3f D_802C4AA0;
extern Racer D_802C4CC8[];
extern Mtx3F D_802C4D88;
extern Vec3f D_802C4E48;
extern Racer D_802C5070;
extern Mtx3F D_802C5130;
extern Vec3f D_802C51F0;

void func_800888D0(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 var_s3 = true;
    Racer* temp_a3;
    unk_struct_9C* temp_v0;
    unk_struct_C* var_a1;

    while (var_s3) {

        var_s3 = false;
        switch (arg0->unk_18) {
            case 0:
                if (func_80088CB8(1)) {
                    if (D_i7_8014BDF6 & 0x40) {
                        var_s3 = true;
                        arg0->unk_18 = 2;
                        func_80081318(arg1, &D_800D4EF0);
                        arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.z = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.y = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.x = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_54.x = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_54.y = 37.0f;
                        arg1->unk_04.unk_58.unk_00.unk_54.z = -132.0f;
                    } else {
                        arg0->unk_18 = 1;
                        arg0->unk_1C = 0;
                        if (D_800E5E88 == 0) {
                            var_a1 = &D_i7_8014A4D0;
                        } else if (D_800E5E88 == 1) {
                            var_a1 = &D_i7_8014AB60;
                        } else {
                            var_a1 = &D_i7_8014A7E0;
                        }
                        func_80083574(arg2, var_a1);
                        temp_a3 = &gRacers[D_800E5E88];
                        func_80083558(&D_800E5D70[arg0->unk_00], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
                    }
                }
                break;
            case 1:
                if (func_800835B0(arg2)) {
                    arg0->unk_18 = 2;
                    arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.x = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.y = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.z = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_54.x = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_54.y = 37.0f;
                    var_s3 = true;
                    temp_v0 = &arg1->unk_04.unk_58;
                    if (D_i7_8014BDF6 & 2) {
                        temp_v0->unk_00.unk_54.z = 132.0f;
                    } else {
                        temp_v0->unk_00.unk_54.z = -132.0f;
                    }
                }
                break;
            case 2:
                temp_a3 = &gRacers[D_800E5E88];
                *((Mtx3F*) &arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C) = temp_a3->unk_C0;
                arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00 = temp_a3->unk_180;
                if (func_80088CB8(4)) {
                    arg0->unk_18 = 3;
                    arg0->unk_1C = 0;
                    func_80083558(&D_800E5D70[arg0->unk_00], &D_802C51F0, &D_802C5130, &D_802C5070);
                    func_80083574(arg2, &D_i7_8014B310);
                }
                break;
            case 3:
                if (func_800835B0(arg2) && func_80088CB8(3)) {
                    arg0->unk_18 = 4;
                    arg0->unk_1C = 0;
                    func_80083558(&D_800E5D70[arg0->unk_00], &D_802C4E48, &D_802C4D88, D_802C4CC8);
                    func_80083574(arg2, &D_i7_8014B190);
                }
                break;
            case 4:
                if (func_800835B0(arg2) && func_80088CB8(2)) {
                    arg0->unk_18 = 5;
                    arg0->unk_1C = 0;
                    func_80083558(&D_800E5D70[arg0->unk_00], &D_802C4AA0, &D_802C49E0, gRacers);
                    func_80083574(arg2, &D_i7_8014B070);
                }
                break;
            case 5:
                func_800835B0(arg2);
                break;
        }
    }
    // FAKE, likely some recast somewhere
    if (!arg1) {}
}

extern s32 D_800E5E84;

void func_80088CAC(s32 arg0) {
    D_800E5E84 = arg0;
}

bool func_80088CB8(s32 arg0) {
    bool var_v1 = false;

    if (arg0 == D_800E5E84) {
        var_v1 = true;
        D_800E5E84 = 0;
    }
    return var_v1;
}

extern s32 D_800E5EC0;

s32 func_80088CE0(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800E5EC0; i++) {
        if (arg0 == gRacers[i].unk_2AC) {
            return i;
        }
    }
    return -1;
}

void func_i3_80115E74(void);
s32 func_8009EBEC(Racer_unk_C*, f32, f32, f32, s32, f32);

extern s32 gNumPlayers;
extern s8 D_800CD010;
extern s32 D_800DCE44;
extern s32 D_800E5EC0;

extern unk_800F8510* D_800F8510;
extern Vec3f D_802C4938;

void func_80088D28(void) {
    f32 var_fs0;
    f32 var_fs4;
    f32 var_fv0;
    s32 i;
    s32 j;
    unk_8006FC8C* var_s2;
    Racer* temp_s1;
    s32 index;

    func_i3_80115E74();

    var_s2 = D_800F8510->unk_10->unk_38;
    var_fs0 = 1.0f;
    for (i = 20; i > 0; i--) {
        var_fs0 -= 7.3f / func_8009E538(var_s2, var_fs0, &D_802C4938);
    }

    if ((D_800DCE44 != 6) && (D_800DCE44 != 0x11) && (D_800CD010 == 0)) {
        if ((D_800DCE44 == 1) || (D_800DCE44 == 2) || (D_800DCE44 == 0x15)) {
            var_fs4 = 1.99f;
        } else {
            var_fs4 = 0;
        }
    } else {
        var_fs4 = 7.99f;
    }

    for (j = 1; j <= D_800E5EC0; j++) {
        index = func_80088CE0(j);
        temp_s1 = &gRacers[index];
        temp_s1->unk_0C.unk_00 = var_s2;
        temp_s1->unk_0C.unk_04 = var_fs0;
        func_8009E6F0(var_s2, var_fs0, &temp_s1->unk_0C.unk_1C);
        temp_s1->unk_0C.unk_34 = temp_s1->unk_0C.unk_44 = temp_s1->unk_0C.unk_1C;
        temp_s1->unk_0C.unk_28.x = 0.0f;
        temp_s1->unk_0C.unk_28.y = 0.0f;
        temp_s1->unk_0C.unk_28.z = 0.0f;
        temp_s1->unk_0C.unk_40 = 0.0f;
        temp_s1->unk_0C.unk_18 = func_8009E538(temp_s1->unk_0C.unk_00, temp_s1->unk_0C.unk_04, &temp_s1->unk_0C.unk_0C);
        temp_s1->unk_0C.unk_08 = func_8009E108(temp_s1->unk_0C.unk_00, temp_s1->unk_0C.unk_04, &temp_s1->unk_244);
        func_8009E85C(temp_s1->unk_0C.unk_00, temp_s1->unk_0C.unk_04, &temp_s1->unk_24C, temp_s1->unk_0C.unk_08);
        if (D_800E5EC0 >= 4) {
            var_fv0 = 3.0f;
        } else {
            var_fv0 = D_800E5EC0 - 1;
        }
        var_fv0 = (((j - 1) & 3) * 2 - var_fv0) * 50.0f;
        func_8009EBEC(&temp_s1->unk_0C,
                      temp_s1->unk_0C.unk_34.x + (var_fs4 * temp_s1->unk_24C.xy) + (var_fv0 * temp_s1->unk_24C.xz),
                      temp_s1->unk_0C.unk_34.y + (var_fs4 * temp_s1->unk_24C.yy) + (var_fv0 * temp_s1->unk_24C.yz),
                      temp_s1->unk_0C.unk_34.z + (var_fs4 * temp_s1->unk_24C.zy) + (var_fv0 * temp_s1->unk_24C.zz), 100,
                      1.0f);
        if (gNumPlayers == 1) {
            var_fv0 = 100.0f;
        } else {
            var_fv0 = 0.1f;
        }

        for (i = 20; i > 0; i--) {
            var_fs0 -= (var_fv0 / 20.0f) / temp_s1->unk_0C.unk_18;
            if (var_fs0 < 0.0f) {
                var_s2 = var_s2->unk_38;
                var_fs0 *= (temp_s1->unk_0C.unk_18 / func_8009E538(var_s2, 1.0f, &temp_s1->unk_0C.unk_0C));
                var_fs0 += 1.0f;
            }
        }
    }
}

extern s8 D_800CD010;
extern s32 D_800DCE44;
extern s32 D_800E5EC0;
extern Racer* D_800E5EC4;
extern Racer* D_800E5EC8;
extern s16 D_800E5FC2;

void func_800890B4(void) {
    s16 temp_a0;
    s16 temp_a1;
    s32 var_a2;
    s32 var_a3;
    s32 temp_t5;
    s32 temp_t9;
    Racer* temp;
    Racer* var_a0;
    Racer* var_v0;
    Racer* var_v1;

    if ((D_800DCE44 != 1) || ((D_800E5EC0 - D_800E5FC2) < 2) || (D_800CD010 != 0)) {
        D_800E5EC8 = NULL;
        return;
    }
    var_v0 = gRacers;
    while (var_v0->unk_04 & 0x40000) {
        var_v0++;
    }
    var_v1 = var_v0 + 1;
    while (var_v1->unk_04 & 0x40000) {
        var_v1++;
    }

    if (var_v0->unk_0A < var_v1->unk_0A) {
        temp = var_v0;
        var_v0 = var_v1;
        var_v1 = temp;
        var_a2 = var_v1->unk_0A;
        var_a3 = var_v0->unk_0A;
    } else {
        var_a2 = var_v0->unk_0A;
        var_a3 = var_v1->unk_0A;
    }

    var_a0 = D_800E5EC4;
    do {
        if (!(var_a0->unk_04 & 0x40000)) {
            if (var_a2 < var_a0->unk_0A) {
                var_v1 = var_v0;
                var_a3 = var_a2;
                var_v0 = var_a0;
                var_a2 = var_a0->unk_0A;
            } else if ((var_a3 < var_a0->unk_0A) && (var_a0 != var_v0)) {
                var_v1 = var_a0;
                var_a3 = var_a0->unk_0A;
            }
        }
        var_a0--;
    } while (var_a0 >= gRacers);

    if (var_a2 == 0) {
        D_800E5EC8 = NULL;
        return;
    }
    if (var_v0 == gRacers) {
        D_800E5EC8 = var_v1;
        return;
    }
    D_800E5EC8 = var_v0;
}

void func_i3_80128D8C(void);
void func_i3_801345A4(void);
extern s16 D_800E5ED8[];
extern s16 D_800E5FD0;
extern s16 D_800F80C4;

void func_80089220(s32 arg0) {

    D_800E5ED8[arg0]++;

    func_i3_80128D8C();
    func_i3_801345A4();
    if (D_800E5FD0 != 0) {
        func_800BA8D8(0);
    }
    D_800F80C4 = 0;
}

void func_i3_801345C8(void);

void func_8008927C(s32 arg0) {

    if (--D_800E5ED8[arg0] >= 0) {
        func_i3_801345C8();
    }
    if (D_800E5FD0 != 0) {
        func_800BA8D8(44);
    }
    D_800F80C4 = 0;
}

extern s16 D_800E5FC6;
extern s16 D_800E5FC8;
extern s32 D_800E5FD8;
extern s16 D_800F5DE8;

void func_800892E0(Racer* arg0) {

    if (!(arg0->unk_04 & 0x2040000)) {
        arg0->unk_04 |= 0x40000;
        arg0->unk_228 = 0.0f;
        D_800E5FC2++;
        if (arg0->unk_00 < gNumPlayers) {
            D_800E5FC8++;
        } else if (D_800E5FBC == 0) {
            D_800E5FC6++;
            if ((D_800DCE44 == 0x15) && (D_800E5EC0 == (D_800E5FC6 + 1))) {
                gRacers->unk_04 |= 0x2800000;
                gRacers->unk_2A0 += Math_Rand2() % 16;
                D_800E5FBC = 1;
                gRacers->unk_228 = gRacers->unk_22C;
                D_800F5DE8 = D_800E5FBC;
                func_800BA2B4(gRacers->unk_00);
                func_800BAB68(gRacers->unk_00);
                func_8007E0CC();
            }
        }
        arg0->unk_248 = (D_800E5FD8 + ((D_800E5EC0 - arg0->unk_2AC) / 10.0f)) - 600000.0f;
        if (D_800DCE44 == 1) {
            if (arg0->unk_00 < gNumPlayers) {
                D_800F80C4 = -1;
            }
            if (arg0 == D_800E5EC8) {
                func_800890B4();
            }
        }
    }
}

void func_800894C0(Racer* arg0) {

    if (D_800E5FD0 != 0) {
        if (arg0->unk_08 & 0x800) {
            arg0->unk_08 &= ~0x800;
            func_800BA3E4(arg0->unk_00, 4);
        }
        if (arg0->unk_08 & 0x400) {
            arg0->unk_08 &= ~0x400;
            func_800BA3E4(arg0->unk_00, 5);
        }
        if (arg0->unk_08 & 0x20) {
            arg0->unk_08 &= ~0x20;
            func_800BA3E4(arg0->unk_00, 11);
        }
        if (arg0->unk_08 & 0x200) {
            arg0->unk_08 &= ~0x200;
            func_800BA3E4(arg0->unk_00, 6);
        }
        if (arg0->unk_08 & 0x40) {
            arg0->unk_08 &= ~0x40;
            func_800BA3E4(arg0->unk_00, 10);
        }
        if (arg0->unk_08 & 0x2000) {
            arg0->unk_08 &= ~0x2000;
            func_800BA3E4(arg0->unk_00, 8);
        }
        if (arg0->unk_08 & 0x100) {
            arg0->unk_08 &= ~0x100;
            func_800BAB50(arg0->unk_00);
        }
        if (arg0->unk_08 & 0x80) {
            arg0->unk_08 &= ~0x80;
            func_800BA3E4(arg0->unk_00, 9);
        }
        func_800BAB68(arg0->unk_00);
    } else {
        arg0->unk_08 &= ~(0x800 | 0x400 | 0x20 | 0x200 | 0x40 | 0x2000 | 0x100 | 0x80);
    }
}

// todo: figure out 0.6899998f as a fraction
f32 func_8008960C(f32 arg0) {
    if (arg0 != 0.0f) {
        return 1.0f / (((1.0f + 0.6899998f) / arg0) - 0.6899998f);
    }
    return 0.0f;
}

f32 func_80089654(f32 arg0) {
    if (arg0 != 0.0f) {
        return (1.0f + 0.6899998f) / ((1.0f / arg0) + 0.6899998f);
    }
    return 0.0f;
}

extern s16 D_800E5EE0[];
extern s16 D_800E5EE8[];

void func_8008969C(void) {
    s32 i;

    for (i = gNumPlayers - 1; i >= 0; i--) {
        gRacers[i].character = D_800E5EE0[i];
        gRacers[i].unk_2CC = D_800E5EE8[i];
    }
}

extern f32 D_800E5EF0[];

void func_80089724(void) {
    s32 i;

    for (i = gNumPlayers - 1; i >= 0; i--) {
        D_800E5EE0[i] = gRacers[i].character;
        D_800E5EE8[i] = gRacers[i].unk_2CC;
        gRacers[i].unk_1A8 = func_8008960C(D_800E5EF0[i]);
    }
}

void func_80089800(void) {
    s32 i;
    s16 j;
    s32 index0;
    s32 index1;

    j = 0;

    for (i = 0; i < 29; i++) {
        if (j == D_800E5EE0[0]) {
            j++;
        }
        D_802C4CC8[i].character = j++;
        D_802C4CC8[i].unk_2CC = 0;
    }

    for (i = 0; i < 28; i++) {
        index0 = (Math_Rand1() & 0x1FFFF) % 29 + 1;
        index1 = (Math_Rand2() & 0x1FFFF) % 29 + 1;

        j = gRacers[index0].character;
        gRacers[index0].character = gRacers[index1].character;
        gRacers[index1].character = j;
    }
}

void func_80089934(void) {
    s32 i;
    s32 j;
    s32 var_s0;
    Racer* temp_s1;
    Racer* var_v0;

    for (i = 1; i < D_800E5EC0; i++) {
        if (i >= gNumPlayers) {
            do {
                gRacers[i].character = (Math_Rand2() & 0x1FFFF) % 30;
                gRacers[i].unk_2CC = (Math_Rand1() & 0x1FFFF) % 4;
                for (j = 0; j < gNumPlayers; j++) {
                    if ((gRacers[i].character == gRacers[j].character) && (gRacers[i].unk_2CC == gRacers[j].unk_2CC)) {
                        break;
                    }
                }
            } while (j < gNumPlayers);
        }
    }
}

typedef struct unk_800CF1B0 {
    s16 unk_00;
    u8 unk_02;
    s8 unk_03[0x1];
    u8 unk_04[4];
    u8 unk_08[4];
    u8 unk_0C[4];
    u8 unk_10[0x4];
    u16 unk_14;
} unk_800CF1B0; // size = 0x16
extern unk_800CF1B0 D_800F80C8[];
extern u8 D_800F8360[][14];

void func_80089A74(u8* arg0) {
    u8 var_v0;
    u8* temp_v0;

    arg0[0] = gRacers->character;
    arg0[8] = (s32) gRacers->unk_2E0;
    arg0[9] = (s32) gRacers->unk_2E4;
    arg0[10] = (s32) gRacers->unk_2E8;
    var_v0 = gRacers->unk_164;
    arg0[1] = var_v0;
    if (var_v0 == 1) {
        temp_v0 = D_800F8360[gRacers->character];
        arg0[2] = temp_v0[0];
        arg0[3] = temp_v0[1];
        arg0[4] = temp_v0[2];
        arg0[5] = temp_v0[3];
        arg0[6] = D_800F80C8[gRacers->character].unk_10[0] - 1;
        arg0[7] = temp_v0[4];
        arg0[11] = temp_v0[5];
        arg0[12] = temp_v0[6];
        arg0[13] = temp_v0[7];
        arg0[14] = temp_v0[8];
        arg0[15] = temp_v0[9];
        arg0[16] = temp_v0[10];
        arg0[17] = temp_v0[11];
        arg0[18] = temp_v0[12];
        arg0[19] = temp_v0[13];
    } else {
        arg0[2] = arg0[3] = arg0[4] = arg0[5] = arg0[6] = arg0[7] = arg0[11] = arg0[12] = arg0[13] = arg0[14] =
            arg0[15] = arg0[16] = arg0[17] = arg0[18] = arg0[19] = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80089BD0.s")

extern Racer* D_800E5F40[];

void func_8008A978(void) {
    Racer* var_a1;
    Racer* var_a2;
    s32 var_a3;
    Racer* var_v0;
    s32 var_v1;
    s32 var_a0;
    f32 var_fv0;

    var_v0 = D_800E5EC4;
    do {
        var_v0->unk_2AC = 0;
        var_v0--;
    } while (var_v0 >= gRacers);

    var_v1 = 1;
    var_a0 = D_800E5EC0;

    do {
        var_a1 = NULL;
        var_a2 = NULL;
        var_v0 = D_800E5EC4;
        // FAKE
        if (D_800E5F40) {}

        do {
            if (var_v0->unk_2AC == 0) {
                if (var_v0->unk_04 & 0x2000000) {
                    if ((var_a2 == NULL) || (var_v0->unk_2A0 < var_a3)) {
                        var_a3 = var_v0->unk_2A0;
                        var_a2 = var_v0;
                    }
                } else if ((var_a1 == NULL) || (var_v0->unk_248 < var_fv0)) {
                    var_fv0 = var_v0->unk_248;
                    var_a1 = var_v0;
                }
            }
            var_v0--;
        } while (var_v0 >= gRacers);

        if (var_a2 != NULL) {
            D_800E5F40[var_v1 - 1] = var_a2;

            var_a2->unk_2AC = var_v1;
            var_v1++;
        }
        if (var_a1 != NULL) {
            D_800E5F40[var_a0 - 1] = var_a1;

            var_a1->unk_2AC = var_a0;
            var_a0--;
        }
    } while (var_a0 >= var_v1);
}

extern s32 D_800CD00C;
extern s32 D_800CE6C0[];
extern s16 D_800E5FC0;
extern s16 D_800E5FD4;
extern s16 D_800E5FD6;

void func_8008AA8C(void) {
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    Racer* var_s0;
    Racer* var_v0;

    for (var_s0 = D_800E5EC4; var_s0 >= gRacers; var_s0--) {
        if (var_s0->unk_04 & 0x2000000) {
            continue;
        }

        if (var_s0->unk_04 & 0x8000000) {
            var_s0->unk_2A0 = 0;
        } else if (var_s0->unk_04 & 0x80000) {
            var_s0->unk_04 &= ~0x40000000;
            var_s0->unk_04 |= 0x8000000;
            D_800E5FC0++;
            func_800892E0(var_s0);
            var_s0->unk_2A0 = 0;
        } else {
            var_s0->unk_04 |= 0x2000000;
            var_a0 = 0;
            if (var_s0->unk_290[1] != 0) {
                var_a1 = var_s0->unk_290[0] - var_s0->unk_290[1];
                if (var_a1 < 0) {
                    var_a1 = 0;
                }
            } else {
                var_a1 = 0;
            }

            var_s0->unk_2A0 =
                (s32) (((var_s0->unk_2A0 - var_a1) * D_800CD00C) * D_800F8510->unk_0C / var_s0->unk_23C) + var_a1;

            var_a1 = 0;
            var_a0 = 0;
            while (true) {
                if (var_s0->unk_290[var_a0] == 0) {
                    break;
                }

                var_a1 += var_s0->unk_290[var_a0];

                var_a0++;

                if (var_a0 >= D_800CD00C) {
                    break;
                }
            }

            while (var_a0 < D_800CD00C) {
                var_s0->unk_290[var_a0] = (var_s0->unk_2A0 - var_a1) / (D_800CD00C - var_a0);
                var_a1 += var_s0->unk_290[var_a0];
                var_a0++;
            }
        }
    }
    func_8008A978();
    if ((D_800DCE44 == 1) && (gRacers->unk_04 & 0x2000000)) {
        var_v1 = D_800E5EC0 - 1;
        while (var_v1 >= 0) {
            if (D_800E5F40[var_v1]->unk_2A0 != 0) {
                break;
            }
            var_v1--;
        }

        while (var_v1 >= 0) {
            D_800E5F40[var_v1]->unk_0A += D_800CE6C0[var_v1];
            var_v1--;
        }
        D_800E5FD6 = D_800E5FD4;
    }
}

typedef struct unk_800F5EA0 {
    Racer* unk_00;
    Racer* unk_04;
    f32 unk_08;
    f32 unk_0C;
    s8 unk_10[0x4];
} unk_800F5EA0; // size = 0x14
extern unk_800F5EA0 D_800F5EA0[];

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008AD38.s")

extern s32 D_800E5EC0;
extern s32 D_800E5FB8;

void func_8008B150(void) {
    s32 i;
    f32 var_fv0;

    var_fv0 = D_800F8510->unk_0C;

    for (i = D_800E5EC0 - 1; i > 0; i--) {
        if (D_800F5EA0[(i * (i - 1)) >> 1].unk_08 < var_fv0) {
            var_fv0 = D_800F5EA0[(i * (i - 1)) >> 1].unk_08;
            D_800E5FB8 = i;
        }
    }
}

extern s32 gDifficulty;
extern s8 D_800CE4DC[];
extern s16 D_800CF504;
extern s16 D_800E5ED8[];
extern s32 D_800E5FF0;

void func_8008B1CC(void) {
    s32 size = ARRAY_COUNT(gRacers) - 1;
    s32 i;

    if (size) {}

    D_800E5FD6 = D_800E5FF0 = 0;
    D_800CF504 = -1;

    for (i = size; i >= 0; i--) {
        gRacers[i].unk_0A = 0;
    }

    D_800E5ED8[0] = D_800E5ED8[1] = D_800E5ED8[2] = D_800E5ED8[3] = D_800CE4DC[gDifficulty];
}

s32 func_8008B23C(u8* arg0, u8* arg1) {
    s32 i;
    u8* var_v0 = arg0;
    u8* var_v1 = arg1;

    for (i = 20; i > 0; i--, var_v0++, var_v1++) {
        if (*var_v0 != *var_v1) {
            return -1;
        }
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008B2D8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008C14C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008C7C8.s")

extern unk_800CF1B0 D_800CF1B0[];

void func_8008D33C(void) {
    s32 i;

    for (i = 29; i >= 0; i--) {
        D_800F80C8[i] = D_800CF1B0[i];
    }
}

extern Gfx* D_800CDD38[];
extern Gfx* D_800CDDB0[];
typedef Gfx* (*unk_800CE098)(Gfx*);
extern unk_800CE098 D_800CE098[];
extern unk_800CE098 D_800CE11C[][5];

void func_8008D3C4(s32 arg0, s32 arg1) {
    s32 pad[2];
    Gfx* gfx;
    s32 i;
    unk_800CF1B0* temp_v0 = &D_800F80C8[arg0];

    if (temp_v0->unk_00 == 1) {
        gfx = func_i9_80161050(D_800CDD38[arg1], D_800F8360[arg0][3], temp_v0->unk_10[0] - 1, D_800F8360[arg0][4]);
        gSPEndDisplayList(gfx);

        for (i = 4; i >= 0; i--) {
            gfx = func_i9_80115DF0(D_800CDDB0[arg1 * 6 + i], i, D_800F8360[arg0][0], D_800F8360[arg0][1],
                                   D_800F8360[arg0][2], D_800F8360[arg0][8], D_800F8360[arg0][9], D_800F8360[arg0][10],
                                   D_800F8360[arg0][5], D_800F8360[arg0][6], D_800F8360[arg0][7], 255, 255, 255,
                                   D_800F8360[arg0][11], D_800F8360[arg0][12], D_800F8360[arg0][13]);
            gSPEndDisplayList(gfx);
        }

        return;
    }
    if (temp_v0->unk_00 != 0) {
        arg0 = temp_v0->unk_00 + 28;
    } else {
        arg0 = arg0;
    }

    gfx = D_800CE098[arg0](D_800CDD38[arg1]);
    gSPEndDisplayList(gfx);

    for (i = 4; i >= 0; i--) {
        gfx = D_800CE11C[arg0][i](D_800CDDB0[arg1 * 6 + i]);
        gSPEndDisplayList(gfx);
    }
}

void func_8008D5F4(u8* arg0, s32 arg1) {
    s32 pad[2];
    s32 var_v1;
    Gfx* gfx;
    s32 i;

    if (arg0[1] == 1) {
        gfx = func_i9_80161050(D_800CDD38[arg1], arg0[5], arg0[6], arg0[7]);
        gSPEndDisplayList(gfx);

        for (i = 4; i >= 0; i--) {
            gfx = func_i9_80115DF0(D_800CDDB0[arg1 * 6 + i], i, arg0[2], arg0[3], arg0[4], arg0[14], arg0[15], arg0[16],
                                   arg0[11], arg0[12], arg0[13], 255, 255, 255, arg0[17], arg0[18], arg0[19]);
            gSPEndDisplayList(gfx);
        }

        return;
    }
    if (arg0[1] != 0) {
        var_v1 = arg0[1] + 28;
    } else {
        var_v1 = arg0[0];
    }

    gfx = D_800CE098[var_v1](D_800CDD38[arg1]);
    gSPEndDisplayList(gfx);

    for (i = 4; i >= 0; i--) {
        gfx = D_800CE11C[var_v1][i](D_800CDDB0[arg1 * 6 + i]);
        gSPEndDisplayList(gfx);
    }
}

void func_8008D7E8(void) {
    s32 i;

    for (i = 29; i >= 0; i--) {
        func_8008D3C4(i, i);
    }
}

extern u8 D_800F8504[];
extern s32 D_800F8514;

void func_8008D824(void) {
    unk_800F8510* sp2C;
    s32 i;
    u8 var;

    sp2C = &D_802A6B40[D_800F8514];

    for (i = 4; i >= 0; i--) {
        D_800F8504[i] = i + 1;
        func_8008D5F4(sp2C->unk_34[i], D_800F8504[i]);
    }

    var = 5;
    D_800F8504[var] = var + 1;
    func_8008D5F4(sp2C->unk_C4, D_800F8504[var]);
    var = 6;
    D_800F8504[var] = var + 1;
    func_8008D5F4(sp2C->unk_DC, D_800F8504[var]);
}

void func_800A4DF0(void);

extern unk_800E5FF8 D_800E5FF8[];

void func_8008D8E8(void) {
    s32 i;

    func_800A4DF0();
    func_8008D3C4(D_800E5EE0[0], 0);
    func_8008D824();

    for (i = 0; i < 3; i++) {
        if (D_800F8510->unk_00 == D_800E5FF8[i].unk_0000) {
            func_8008D5F4(D_800E5FF8[i].unk_3F6A, i + 7);
        }
    }
}

void func_8008D97C(void) {
    Gfx* gfx;
    s32 i;
    s32 index;
    s32 j;

    for (i = 29; i >= 0; i--) {
        index = i;
        gfx = D_800CE098[index](D_800CDD38[i]);
        gSPEndDisplayList(gfx);
        for (j = 4; j >= 0; j--) {
            gfx = D_800CE11C[index][j](D_800CDDB0[i * 6 + j]);
            gSPEndDisplayList(gfx);
        }
    }
}

extern s16 D_800E5FCC;
extern s16 D_800E5FCE;

void func_8008DA68(void) {
    s32 i;

    D_800E5FD6 = D_800E5FF0 = 0;
    D_800E5FCC = D_800E5FCE = 0;

    for (i = 0; i < ARRAY_COUNT(gRacers); i++) {
        gRacers[i].character = (s8) (i % ARRAY_COUNT(gRacers));
        gRacers[i].unk_2CC = 0;
        gRacers[i].unk_1A8 = func_8008960C(0.5f);
        if (i < 4) {
            D_800E5EE0[i] = (s16) gRacers[i].character;
            D_800E5EE8[i] = gRacers[i].unk_2CC;
            D_800E5EF0[i] = 0.5f;
        }
    }
    func_8008D33C();
}

void func_8008DB98(void) {
    func_8008DA68();
}

extern s16 D_800E5FD2;

void func_8008DBB8(Racer* arg0, s32 arg1) {
    Racer* temp_v0;

    if (arg1 >= arg0->unk_288) {
        temp_v0 = arg0->unk_28C;
        if ((temp_v0 != NULL) && !(temp_v0->unk_04 & 0x2044000)) {
            D_800E5FD4 += 1;
            D_800E5FD2 += 1;
            if ((D_800DCE44 == 1) && (D_800E5FD2 == 5)) {
                D_800E5ED8[0]++;
                func_i3_80128D8C();
                func_i3_801345A4();
                if (D_800E5FD0 != 0) {
                    func_800BA8D8(0);
                }
            }
            temp_v0->unk_230 += temp_v0->unk_22C * 0.125f;
            if ((gNumPlayers == 1) && (D_800E5FD0 != 0)) {
                func_800BA8D8(0x39);
            }
        }
    }
}

extern f32 D_800CE770;
void func_i2_80105648(f32, f32, f32, f32, f32, f32, f32, Racer*);
void func_i2_80105A28(f32, f32, f32, f32, f32, f32, Mtx3F*, s32, s32, s32, Racer*);

void func_8008DCD8(Racer* arg0, f32 arg1) {
    s32 pad[7];
    Vec3f sp90;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 i;

    if (arg0->unk_04 & 0xA000000) {
        if (((arg0->unk_04 & 0x48000000) == 0x48000000) && (D_800CE770 < arg1)) {
            arg0->unk_04 &= ~0x40000000;
            arg0->unk_C0 = arg0->unk_24C;
            D_800E5FC0++;
            if (arg0->unk_00 < gNumPlayers) {
                func_800894C0(arg0);
            }
            if (D_800E5FD0 != 0) {
                func_800BA710(arg0->unk_00, 8);
            }
            if (arg0->unk_2B4 != 0) {
                if (arg0->unk_28C == NULL) {
                    sp90.x = 0.0f;
                    sp90.y = 0.0f;
                    sp90.z = 0.0f;
                } else {
                    sp90.z = arg0->unk_28C->unk_74.x;
                    sp90.y = arg0->unk_28C->unk_74.y;
                    sp90.x = arg0->unk_28C->unk_74.z;
                }
                func_i2_80105648(arg0->unk_0C.unk_34.x, arg0->unk_0C.unk_34.y, arg0->unk_0C.unk_34.z, sp90.z, sp90.y,
                                 sp90.x, 40.0f, arg0);

                temp_s5 = arg0->unk_2E0;
                temp_s6 = arg0->unk_2E4;
                temp_s7 = arg0->unk_2E8;

                i = (arg0->unk_00 < gNumPlayers) ? 0x3C : 0x1E;
                do {

                    temp_fs2 = ((Math_Rand1() & 0x1FFFF) * 0.00011444179f) - 7.5f;

                    temp_fs0 = ((Math_Rand2() & 0x1FFFF) * 0.00005340617f) + 3.5f;

                    temp_fs1 = ((Math_Rand1() & 0x1FFFF) * 0.00011444179f) - 7.5f;

                    func_i2_80105A28(((s32) (Math_Rand2() % 32) - 0x10) + arg0->unk_0C.unk_34.x,
                                     ((s32) (Math_Rand1() % 32) - 0x10) + arg0->unk_0C.unk_34.y,
                                     ((s32) (Math_Rand1() % 32) - 0x10) + arg0->unk_0C.unk_34.z,
                                     (arg0->unk_C0.xz * temp_fs2) + sp90.z + (temp_fs0 * arg0->unk_C0.xy) +
                                         (temp_fs1 * arg0->unk_C0.xx),
                                     (arg0->unk_C0.yz * temp_fs2) + sp90.y + (temp_fs0 * arg0->unk_C0.yy) +
                                         (temp_fs1 * arg0->unk_C0.yx),
                                     (arg0->unk_C0.zz * temp_fs2) + sp90.x + (temp_fs0 * arg0->unk_C0.zy) +
                                         (temp_fs1 * arg0->unk_C0.zx),
                                     &arg0->unk_C0, temp_s5, temp_s6, temp_s7, arg0);
                    i--;
                } while (i != 0);
            }
        }
    } else {
        arg0->unk_04 |= 0x20000;
        arg0->unk_228 -= arg1;
        if (arg0->unk_228 < 0.0f) {
            if (arg0->unk_2B4 == 0) {
                arg0->unk_228 = 0.1f;
                return;
            }
            arg0->unk_228 = 0.0f;
            arg0->unk_238 = 0.2f * arg1;
            if (arg0->unk_238 > 1.0f) {
                arg0->unk_238 = 1.0f;
            }
            if (Math_Rand1() % 2) {
                arg0->unk_238 *= -1.0f;
            }

            if (!(arg0->unk_04 & 0x8004000)) {
                arg0->unk_04 |= 0x4000;
                arg0->unk_04 &= ~0x400000;
                arg0->unk_21C = 1;
                arg0->unk_234 = 2.0f;
                func_8008DBB8(arg0, 60);
            }
        }
    }
}

void func_i2_801054C0(f32, f32, f32, f32, f32, f32, f32, Racer*);

void func_8008E188(Racer* arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 pad;
    Racer* var;
    f32 var_fv0;

    var_fv0 = arg0->unk_24C.xz * arg3;
    arg0->unk_0C.unk_28.x -= var_fv0;
    arg0->unk_0C.unk_34.x -= var_fv0;
    arg0->unk_0C.unk_44.x -= var_fv0;

    var_fv0 = arg0->unk_24C.yz * arg3;
    arg0->unk_0C.unk_28.y -= var_fv0;
    arg0->unk_0C.unk_34.y -= var_fv0;
    arg0->unk_0C.unk_44.y -= var_fv0;

    var_fv0 = arg0->unk_24C.zz * arg3;
    arg0->unk_0C.unk_28.z -= var_fv0;
    arg0->unk_0C.unk_34.z -= var_fv0;
    arg0->unk_0C.unk_44.z -= var_fv0;

    arg0->unk_0C.unk_40 = sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));

    if (arg1 * arg2 <= 0.0f) {
        return;
    }

    if (arg1 * arg2 > 0.01f) {
        if (arg0->unk_2B4 != 0) {
            func_i2_801054C0(arg0->unk_0C.unk_34.x + ((arg2 * 15.0f) * arg0->unk_24C.xz),
                             arg0->unk_0C.unk_34.y + ((arg2 * 15.0f) * arg0->unk_24C.yz),
                             arg0->unk_0C.unk_34.z + ((arg2 * 15.0f) * arg0->unk_24C.zz), arg0->unk_74.x,
                             arg0->unk_74.y, arg0->unk_74.z, (arg1 * arg2 * 1.5f) + 18.0f, arg0);
        }
        if (D_800E5FD0 != 0) {
            func_800BA710(arg0->unk_00, 3);
        }
        func_8008DCD8(arg0, arg1 * arg2 * 0.7f);
    }

    arg0->unk_74.x = (arg0->unk_74.x - arg0->unk_234 * arg1 * arg0->unk_24C.xz) * 0.998f;
    arg0->unk_74.y = (arg0->unk_74.y - arg0->unk_234 * arg1 * arg0->unk_24C.yz) * 0.998f;
    arg0->unk_74.z = (arg0->unk_74.z - arg0->unk_234 * arg1 * arg0->unk_24C.zz) * 0.998f;

    // FAKE
    var = arg0;
    var->unk_118.x = var->unk_24C.xz * (-0.15f * arg1);
    var->unk_118.y = var->unk_24C.yz * (-0.15f * arg1);
    var->unk_118.z = var->unk_24C.zz * (-0.15f * arg1);

    arg0->unk_04 |= 0x2000;
}

void func_8008E418(Racer* arg0) {
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 =
        ((arg0->unk_A8.x * arg0->unk_B4.x) + (arg0->unk_A8.y * arg0->unk_B4.y) + (arg0->unk_A8.z * arg0->unk_B4.z)) *
        0.15f * arg0->unk_E4;

    arg0->unk_B4.x = arg0->unk_C0.xy + (temp_fv0 * arg0->unk_C0.xx);
    arg0->unk_B4.y = arg0->unk_C0.yy + (temp_fv0 * arg0->unk_C0.yx);
    arg0->unk_B4.z = arg0->unk_C0.zy + (temp_fv0 * arg0->unk_C0.zx);

    temp_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));
    arg0->unk_B4.x *= temp_fv1;
    arg0->unk_B4.y *= temp_fv1;
    arg0->unk_B4.z *= temp_fv1;
}

void func_8008E504(Racer* arg0) {

    arg0->unk_A8.x -= 0.5f * arg0->unk_A8.x;
    arg0->unk_A8.y += 0.5f * (1.0f - arg0->unk_A8.y);
    arg0->unk_A8.z -= 0.5f * arg0->unk_A8.z;
}

void func_80090568(Racer*);

void func_8008E54C(Racer* arg0, f32 arg1) {
    f32 temp_ft4;
    f32 sp50;
    f32 temp_fv0;

    if (arg0->unk_04 & 0x80000000) {
        arg0->unk_270 += 57.5f;
        arg0->unk_274 += 57.5f;
        func_80090568(arg0);

        arg0->unk_270 -= 57.5f;
        arg0->unk_274 -= 57.5f;
        if (arg0->unk_04 & 0x80000000) {
            return;
        }
        sp50 = (arg0->unk_24C.xz * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yz * arg0->unk_0C.unk_28.y) +
               (arg0->unk_24C.zz * arg0->unk_0C.unk_28.z);
        if ((sp50 < -arg0->unk_274) || (arg0->unk_270 < sp50)) {
            arg0->unk_04 |= 0x80000000;
            func_8008DCD8(arg0, 2.0f);
            func_i2_801054C0(arg0->unk_0C.unk_34.x, arg0->unk_0C.unk_34.y, arg0->unk_0C.unk_34.z, arg0->unk_74.x,
                             arg0->unk_74.y, arg0->unk_74.z, 40.0f, arg0);
            if (D_800E5FD0 != 0) {
                func_800BA710(arg0->unk_00, 3);
            }
        }
    } else {
        sp50 = (arg0->unk_24C.xz * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yz * arg0->unk_0C.unk_28.y) +
               (arg0->unk_24C.zz * arg0->unk_0C.unk_28.z);
        arg0->unk_A0 = (arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                       (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z);
        arg0->unk_19C.x = arg0->unk_24C.xy;
        arg0->unk_19C.y = arg0->unk_24C.yy;
        arg0->unk_19C.z = arg0->unk_24C.zy;

        if (arg1 < arg0->unk_A0) {
            arg0->unk_04 |= 0x84000000;
            if (arg0->unk_00 < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (D_800E5FD0 != 0) {
                        func_800BA2F0(arg0->unk_00, 8);
                    }
                }
            }
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }

        if (arg0->unk_A0 < 0.0f) {
            temp_fv0 = arg0->unk_A0 * arg0->unk_24C.xy;
            arg0->unk_0C.unk_28.x -= temp_fv0;
            arg0->unk_0C.unk_34.x -= temp_fv0;
            arg0->unk_0C.unk_44.x -= temp_fv0;

            temp_fv0 = arg0->unk_A0 * arg0->unk_24C.yy;
            arg0->unk_0C.unk_28.y -= temp_fv0;
            arg0->unk_0C.unk_34.y -= temp_fv0;
            arg0->unk_0C.unk_44.y -= temp_fv0;

            temp_fv0 = arg0->unk_A0 * arg0->unk_24C.zy;
            arg0->unk_0C.unk_28.z -= temp_fv0;
            arg0->unk_0C.unk_34.z -= temp_fv0;
            arg0->unk_0C.unk_44.z -= temp_fv0;

            arg0->unk_A0 = 0.0f;

            temp_ft4 = (arg0->unk_24C.xy * arg0->unk_74.x) + (arg0->unk_24C.yy * arg0->unk_74.y) +
                       (arg0->unk_24C.zy * arg0->unk_74.z);
            if (temp_ft4 < 0.0f) {
                arg0->unk_74.x -= temp_ft4 * arg0->unk_24C.xy;
                arg0->unk_74.y -= temp_ft4 * arg0->unk_24C.yy;
                arg0->unk_74.z -= temp_ft4 * arg0->unk_24C.zy;
                if ((arg0->unk_00 < gNumPlayers) && (D_800E5FD0 != 0)) {
                    func_800BB3C4(arg0->unk_00, temp_ft4);
                }
            }
        }

        if (arg0->unk_A0 <= 15.0f) {
            arg0->unk_04 &= ~0x4000000;
            if (arg0->unk_00 < gNumPlayers) {

                if (arg0->unk_08 & 0x2000) {
                    arg0->unk_08 &= ~0x2000;
                    if (D_800E5FD0 != 0) {
                        func_800BA3E4(arg0->unk_00, 8);
                    }
                }
            }

            arg0->unk_A8.x = arg0->unk_B4.x = arg0->unk_24C.xy;
            arg0->unk_A8.y = arg0->unk_B4.y = arg0->unk_24C.yy;
            arg0->unk_A8.z = arg0->unk_B4.z = arg0->unk_24C.zy;

        } else {
            arg0->unk_04 |= 0x4000000;
            if (arg0->unk_00 < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (D_800E5FD0 != 0) {
                        func_800BA2F0(arg0->unk_00, 8);
                    }
                }
            }
            func_8008E418(arg0);
            func_8008E504(arg0);

            if (arg0->unk_A0 < 30.0f) {

                temp_ft4 = (arg0->unk_A0 - 15.0f) / 15.0f;
                arg0->unk_A8.x = (arg0->unk_A8.x - arg0->unk_24C.xy) * temp_ft4 + arg0->unk_24C.xy;
                arg0->unk_A8.y = (arg0->unk_A8.y - arg0->unk_24C.yy) * temp_ft4 + arg0->unk_24C.yy;
                arg0->unk_A8.z = (arg0->unk_A8.z - arg0->unk_24C.zy) * temp_ft4 + arg0->unk_24C.zy;

                arg0->unk_B4.x = (arg0->unk_B4.x - arg0->unk_24C.xy) * temp_ft4 + arg0->unk_B4.x;
                arg0->unk_B4.y = (arg0->unk_B4.y - arg0->unk_24C.yy) * temp_ft4 + arg0->unk_B4.y;
                arg0->unk_B4.z = (arg0->unk_B4.z - arg0->unk_24C.zy) * temp_ft4 + arg0->unk_B4.z;

                temp_fv0 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));
                arg0->unk_B4.x *= temp_fv0;
                arg0->unk_B4.y *= temp_fv0;
                arg0->unk_B4.z *= temp_fv0;
            }
        }

        if (sp50 < -arg0->unk_274) {
            func_8008E188(arg0,
                          (arg0->unk_24C.xz * arg0->unk_74.x) + (arg0->unk_24C.yz * arg0->unk_74.y) +
                              (arg0->unk_24C.zz * arg0->unk_74.z),
                          -1.0f, arg0->unk_274 + sp50);
        } else if (arg0->unk_270 < sp50) {
            func_8008E188(arg0,
                          (arg0->unk_24C.xz * arg0->unk_74.x) + (arg0->unk_24C.yz * arg0->unk_74.y) +
                              (arg0->unk_24C.zz * arg0->unk_74.z),
                          1.0f, sp50 - arg0->unk_270);
        } else {
            arg0->unk_0C.unk_40 =
                sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
        }

        arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_24C.xy);
        arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_24C.yy);
        arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_24C.zy);
    }
}

void func_8008EC38(Racer* arg0) {
    func_8008E54C(arg0, 40.0f);
}

void func_8008EC58(Racer* arg0) {
    func_8008E54C(arg0, 145.0f);
}

void func_8008EC78(Racer* arg0) {
    func_8008E54C(arg0, 210.0f);
}

extern f32 D_800CF8E8[8];

void func_8008EC98(Racer* arg0) {
    f32 var_fv0;
    f32 temp_fv0;
    f32 var_fv1;
    f32 sp60;
    f32 var_fs0;
    f32 sp58;
    f32 sp54;

    if (arg0->unk_0C.unk_04 < arg0->unk_0C.unk_00->unk_68) {
        var_fv0 = sp60 = arg0->unk_0C.unk_08 / arg0->unk_0C.unk_00->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = arg0->unk_270;
    } else if (arg0->unk_0C.unk_00->unk_6C < arg0->unk_0C.unk_04) {
        var_fv0 = sp60 = (1.0f - arg0->unk_0C.unk_08) / arg0->unk_0C.unk_00->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = -arg0->unk_270;
    } else {
        var_fv0 = arg0->unk_270;
        var_fs0 = 0.0f;
    }

    arg0->unk_A0 = arg0->unk_270 - arg0->unk_0C.unk_40;
    if (arg0->unk_0C.unk_40 > 0.01f) {
        var_fv1 = -1.0f / arg0->unk_0C.unk_40;
        arg0->unk_19C.x = arg0->unk_0C.unk_28.x * var_fv1;
        arg0->unk_19C.y = arg0->unk_0C.unk_28.y * var_fv1;
        arg0->unk_19C.z = arg0->unk_0C.unk_28.z * var_fv1;
    }

    if (var_fs0 != 0.0f) {
        var_fv1 = ((arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                   (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z)) -
                  23.0f;
        if (arg0->unk_04 & 0x80000000) {
            if ((var_fv1 >= 0.0f) || (arg0->unk_270 < arg0->unk_0C.unk_40)) {
                func_8008E418(arg0);
                func_8008E504(arg0);
                arg0->unk_168.y = -54321.0f;
                return;
            }
            arg0->unk_04 &= ~0x80000000;
        } else if (var_fv1 >= 0.0f) {
            arg0->unk_04 |= 0x84000000;
            if (arg0->unk_00 < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (D_800E5FD0 != 0) {
                        func_800BA2F0(arg0->unk_00, 8);
                    }
                }
            }
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
    } else if (arg0->unk_04 & 0x80000000) {
        if (arg0->unk_270 < arg0->unk_0C.unk_40) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->unk_04 &= ~0x80000000;
    }

    if (var_fs0 != 0.0f) {
        var_fv1 = var_fv0 + (arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                  (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z);
        if (var_fv1 < arg0->unk_A0) {
            arg0->unk_A0 = var_fv1;
            arg0->unk_19C.x = arg0->unk_24C.xy;
            arg0->unk_19C.y = arg0->unk_24C.yy;
            arg0->unk_19C.z = arg0->unk_24C.zy;

            arg0->unk_B4.x = (D_800CF8E8[4] * arg0->unk_24C.xy) + (var_fs0 * arg0->unk_24C.xx);
            arg0->unk_B4.y = (D_800CF8E8[4] * arg0->unk_24C.yy) + (var_fs0 * arg0->unk_24C.yx);
            arg0->unk_B4.z = (D_800CF8E8[4] * arg0->unk_24C.zy) + (var_fs0 * arg0->unk_24C.zx);

            if (false) {
                // FAKE: ARTIFICIALLY INCREASE COMPILER STACK
                arg0->unk_B4.x = arg0->unk_B4.y = arg0->unk_B4.z;
            }

            var_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));

            arg0->unk_B4.x *= var_fv1;
            arg0->unk_B4.y *= var_fv1;
            arg0->unk_B4.z *= var_fv1;

            if (arg0->unk_A0 < 0.0f) {
                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.xy;
                arg0->unk_0C.unk_28.x -= temp_fv0;
                arg0->unk_0C.unk_34.x -= temp_fv0;
                arg0->unk_0C.unk_44.x -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.yy;
                arg0->unk_0C.unk_28.y -= temp_fv0;
                arg0->unk_0C.unk_34.y -= temp_fv0;
                arg0->unk_0C.unk_44.y -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.zy;
                arg0->unk_0C.unk_28.z -= temp_fv0;
                arg0->unk_0C.unk_34.z -= temp_fv0;
                arg0->unk_0C.unk_44.z -= temp_fv0;

                arg0->unk_0C.unk_40 =
                    sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
                arg0->unk_A0 = 0.0f;

                var_fs0 = (arg0->unk_24C.xy * arg0->unk_74.x) + (arg0->unk_24C.yy * arg0->unk_74.y) +
                          (arg0->unk_24C.zy * arg0->unk_74.z);
                if (var_fs0 < 0.0f) {
                    arg0->unk_74.x -= var_fs0 * arg0->unk_24C.xy;
                    arg0->unk_74.y -= var_fs0 * arg0->unk_24C.yy;
                    arg0->unk_74.z -= var_fs0 * arg0->unk_24C.zy;
                    if ((arg0->unk_00 < gNumPlayers) && (D_800E5FD0 != 0)) {
                        func_800BB3C4(arg0->unk_00, var_fs0);
                    }
                }
            }
        } else {
            arg0->unk_B4 = arg0->unk_19C;
        }
        var_fs0 = ((arg0->unk_B4.x - arg0->unk_24C.xy) * sp60) + arg0->unk_24C.xy;
        sp58 = ((arg0->unk_B4.y - arg0->unk_24C.yy) * sp60) + arg0->unk_24C.yy;
        sp54 = ((arg0->unk_B4.z - arg0->unk_24C.zy) * sp60) + arg0->unk_24C.zy;

        var_fv1 = sqrtf(SQ(var_fs0) + SQ(sp58) + SQ(sp54));
        if (var_fv1 > 0.01f) {
            var_fv1 = 1.0f / var_fv1;
            arg0->unk_B4.x = var_fv1 * var_fs0;
            arg0->unk_B4.y = var_fv1 * sp58;
            arg0->unk_B4.z = var_fv1 * sp54;
        }

        arg0->unk_A8.x = ((arg0->unk_19C.x - arg0->unk_24C.xy) * sp60) + arg0->unk_24C.xy;
        arg0->unk_A8.y = ((arg0->unk_19C.y - arg0->unk_24C.yy) * sp60) + arg0->unk_24C.yy;
        arg0->unk_A8.z = ((arg0->unk_19C.z - arg0->unk_24C.zy) * sp60) + arg0->unk_24C.zy;
    } else {
        arg0->unk_A8 = arg0->unk_B4 = arg0->unk_19C;
    }

    if (arg0->unk_270 < arg0->unk_0C.unk_40) {
        var_fv1 = arg0->unk_270 / arg0->unk_0C.unk_40;
        arg0->unk_0C.unk_40 = arg0->unk_270;

        arg0->unk_0C.unk_28.x *= var_fv1;
        arg0->unk_0C.unk_34.x = arg0->unk_0C.unk_44.x = arg0->unk_0C.unk_28.x + arg0->unk_0C.unk_1C.x;

        arg0->unk_0C.unk_28.y *= var_fv1;
        arg0->unk_0C.unk_34.y = arg0->unk_0C.unk_44.y = arg0->unk_0C.unk_28.y + arg0->unk_0C.unk_1C.y;

        arg0->unk_0C.unk_28.z *= var_fv1;
        arg0->unk_0C.unk_34.z = arg0->unk_0C.unk_44.z = arg0->unk_0C.unk_28.z + arg0->unk_0C.unk_1C.z;

        arg0->unk_A0 = 0.0f;

        var_fs0 = (arg0->unk_19C.x * arg0->unk_74.x) + (arg0->unk_19C.y * arg0->unk_74.y) +
                  (arg0->unk_19C.z * arg0->unk_74.z);
        if (var_fs0 < 0.0f) {
            arg0->unk_74.x -= var_fs0 * arg0->unk_19C.x;
            arg0->unk_74.y -= var_fs0 * arg0->unk_19C.y;
            arg0->unk_74.z -= var_fs0 * arg0->unk_19C.z;
            if ((arg0->unk_00 < gNumPlayers) && (D_800E5FD0 != 0)) {
                func_800BB3C4(arg0->unk_00, var_fs0);
            }
        }
    }

    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_19C.x);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_19C.y);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_19C.z);

    if (arg0->unk_A0 <= 15.0f) {
        arg0->unk_04 &= ~0x4000000;
        if (arg0->unk_00 < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA3E4(arg0->unk_00, 8);
                }
            }
        }
    } else {
        arg0->unk_04 |= 0x4000000;
        if (arg0->unk_00 < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->unk_00, 8);
                }
            }
        }
    }
}

// https://decomp.me/scratch/fHjsj stack
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008F550.s")

void func_8008FC80(Racer* arg0) {
    f32 var_fv0;
    f32 var_fs0;
    f32 temp_fv1;
    f32 sp58;
    f32 temp_fv0;
    f32 sp50;
    f32 sp4C;

    if (arg0->unk_0C.unk_04 < arg0->unk_0C.unk_00->unk_68) {
        var_fv0 = sp58 = arg0->unk_0C.unk_08 / arg0->unk_0C.unk_00->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = arg0->unk_270;
    } else if (arg0->unk_0C.unk_00->unk_6C < arg0->unk_0C.unk_04) {
        var_fv0 = sp58 = (1.0f - arg0->unk_0C.unk_08) / arg0->unk_0C.unk_00->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = -arg0->unk_270;
    } else {
        var_fv0 = arg0->unk_270;
        var_fs0 = 0.0f;
    }

    arg0->unk_A0 = arg0->unk_270 - arg0->unk_0C.unk_40;
    if (arg0->unk_0C.unk_40 > 0.01f) {
        temp_fv1 = -1.0f / arg0->unk_0C.unk_40;
        arg0->unk_19C.x = arg0->unk_0C.unk_28.x * temp_fv1;
        arg0->unk_19C.y = arg0->unk_0C.unk_28.y * temp_fv1;
        arg0->unk_19C.z = arg0->unk_0C.unk_28.z * temp_fv1;
    }

    temp_fv1 = (((arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                 (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z)) -
                23.0f) +
               (var_fv0 * 0.3826834f);
    if (arg0->unk_04 & 0x80000000) {
        if ((temp_fv1 >= 0.0f) || (arg0->unk_270 < arg0->unk_0C.unk_40)) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->unk_04 = arg0->unk_04 & ~0x80000000;

    } else if (temp_fv1 >= 0.0f) {
        arg0->unk_04 |= 0x84000000;
        if (arg0->unk_00 < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->unk_00, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);
        arg0->unk_168.y = -54321.0f;
        return;
    }

    if (var_fs0 != 0.0f) {
        temp_fv1 = var_fv0 + (arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                   (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z);
        if (temp_fv1 < arg0->unk_A0) {
            arg0->unk_A0 = temp_fv1;
            arg0->unk_19C.x = arg0->unk_24C.xy;
            arg0->unk_19C.y = arg0->unk_24C.yy;
            arg0->unk_19C.z = arg0->unk_24C.zy;
            arg0->unk_B4.x = (D_800CF8E8[4] * arg0->unk_19C.x) + (var_fs0 * arg0->unk_24C.xx);
            arg0->unk_B4.y = (D_800CF8E8[4] * arg0->unk_19C.y) + (var_fs0 * arg0->unk_24C.yx);
            arg0->unk_B4.z = (D_800CF8E8[4] * arg0->unk_19C.z) + (var_fs0 * arg0->unk_24C.zx);

            temp_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));

            arg0->unk_B4.x *= temp_fv1;
            arg0->unk_B4.y *= temp_fv1;
            arg0->unk_B4.z *= temp_fv1;

            if (arg0->unk_A0 < 0.0f) {
                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.xy;
                arg0->unk_0C.unk_28.x -= temp_fv0;
                arg0->unk_0C.unk_34.x -= temp_fv0;
                arg0->unk_0C.unk_44.x -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.yy;
                arg0->unk_0C.unk_28.y -= temp_fv0;
                arg0->unk_0C.unk_34.y -= temp_fv0;
                arg0->unk_0C.unk_44.y -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.zy;
                arg0->unk_0C.unk_28.z -= temp_fv0;
                arg0->unk_0C.unk_34.z -= temp_fv0;
                arg0->unk_0C.unk_44.z -= temp_fv0;

                arg0->unk_0C.unk_40 =
                    sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
                arg0->unk_A0 = 0.0f;

                var_fs0 = (arg0->unk_24C.xy * arg0->unk_74.x) + (arg0->unk_24C.yy * arg0->unk_74.y) +
                          (arg0->unk_24C.zy * arg0->unk_74.z);
                if (var_fs0 < 0.0f) {
                    arg0->unk_74.x -= var_fs0 * arg0->unk_24C.xy;
                    arg0->unk_74.y -= var_fs0 * arg0->unk_24C.yy;
                    arg0->unk_74.z -= var_fs0 * arg0->unk_24C.zy;
                    if ((arg0->unk_00 < gNumPlayers) && (D_800E5FD0 != 0)) {
                        func_800BB3C4(arg0->unk_00, var_fs0);
                    }
                }
            }
        } else {
            arg0->unk_B4 = arg0->unk_19C;
        }

        var_fs0 = ((arg0->unk_B4.x - arg0->unk_24C.xy) * sp58) + arg0->unk_24C.xy;
        sp50 = ((arg0->unk_B4.y - arg0->unk_24C.yy) * sp58) + arg0->unk_24C.yy;
        sp4C = ((arg0->unk_B4.z - arg0->unk_24C.zy) * sp58) + arg0->unk_24C.zy;

        temp_fv1 = sqrtf(SQ(var_fs0) + SQ(sp50) + SQ(sp4C));
        if (temp_fv1 > 0.01f) {
            temp_fv1 = 1.0f / temp_fv1;
            arg0->unk_B4.x = temp_fv1 * var_fs0;
            arg0->unk_B4.y = temp_fv1 * sp50;
            arg0->unk_B4.z = temp_fv1 * sp4C;
        }
    } else {
        arg0->unk_B4 = arg0->unk_19C;
    }

    if (arg0->unk_270 < arg0->unk_0C.unk_40) {
        temp_fv1 = arg0->unk_270 / arg0->unk_0C.unk_40;
        arg0->unk_0C.unk_40 = arg0->unk_270;

        arg0->unk_0C.unk_28.x *= temp_fv1;
        arg0->unk_0C.unk_34.x = arg0->unk_0C.unk_44.x = arg0->unk_0C.unk_28.x + arg0->unk_0C.unk_1C.x;
        arg0->unk_0C.unk_28.y *= temp_fv1;
        arg0->unk_0C.unk_34.y = arg0->unk_0C.unk_44.y = arg0->unk_0C.unk_28.y + arg0->unk_0C.unk_1C.y;
        arg0->unk_0C.unk_28.z *= temp_fv1;
        arg0->unk_0C.unk_34.z = arg0->unk_0C.unk_44.z = arg0->unk_0C.unk_28.z + arg0->unk_0C.unk_1C.z;

        arg0->unk_A0 = 0.0f;

        var_fs0 = (arg0->unk_19C.x * arg0->unk_74.x) + (arg0->unk_19C.y * arg0->unk_74.y) +
                  (arg0->unk_19C.z * arg0->unk_74.z);
        if (var_fs0 < 0.0f) {
            arg0->unk_74.x -= var_fs0 * arg0->unk_19C.x;
            arg0->unk_74.y -= var_fs0 * arg0->unk_19C.y;
            arg0->unk_74.z -= var_fs0 * arg0->unk_19C.z;
            if ((arg0->unk_00 < gNumPlayers) && (D_800E5FD0 != 0)) {
                func_800BB3C4(arg0->unk_00, var_fs0);
            }
        }
    }

    arg0->unk_A8.x = arg0->unk_24C.xy;
    arg0->unk_A8.y = arg0->unk_24C.yy;
    arg0->unk_A8.z = arg0->unk_24C.zy;
    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_19C.x);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_19C.y);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_19C.z);

    if (arg0->unk_A0 <= 15.0f) {
        arg0->unk_04 &= ~0x4000000;
        if (arg0->unk_00 < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA3E4(arg0->unk_00, 8);
                }
            }
        }
    } else {
        arg0->unk_04 |= 0x4000000;
        if (arg0->unk_00 < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->unk_00, 8);
                }
            }
        }
    }
}

void func_80090490(Racer* arg0) {

    arg0->unk_04 |= 0x84000000;
    if (arg0->unk_00 < gNumPlayers) {
        if (!(arg0->unk_08 & 0x2000)) {
            arg0->unk_08 |= 0x2000;
            if (D_800E5FD0 != 0) {
                func_800BA2F0(arg0->unk_00, 8);
            }
        }
    }

    arg0->unk_168.y = -54321.0f;

    arg0->unk_A0 = (arg0->unk_0C.unk_28.x * arg0->unk_24C.xy) + (arg0->unk_0C.unk_28.y * arg0->unk_24C.yy) +
                   (arg0->unk_0C.unk_28.z * arg0->unk_24C.zy);

    arg0->unk_19C.x = arg0->unk_24C.xy;
    arg0->unk_19C.y = arg0->unk_24C.yy;
    arg0->unk_19C.z = arg0->unk_24C.zy;
    func_8008E418(arg0);
    func_8008E504(arg0);
}

void func_80090568(Racer* arg0) {
    f32 temp_fv1;
    f32 sp48;
    f32 temp_fv0;

    sp48 = (arg0->unk_24C.xz * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yz * arg0->unk_0C.unk_28.y) +
           (arg0->unk_24C.zz * arg0->unk_0C.unk_28.z);

    arg0->unk_A0 = (arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                   (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z);

    arg0->unk_19C.x = arg0->unk_24C.xy;
    arg0->unk_19C.y = arg0->unk_24C.yy;
    arg0->unk_19C.z = arg0->unk_24C.zy;

    // FAKE
    if ((arg0->unk_04 ^ 0) & 0x80000000) {
        if ((arg0->unk_A0 < -100.0f) || (arg0->unk_A0 > 30.0f) || (sp48 < -arg0->unk_274) || (arg0->unk_270 < sp48)) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->unk_04 &= ~0x80000000;
    } else if ((arg0->unk_A0 > 30.0f) || (sp48 < -arg0->unk_274) || (arg0->unk_270 < sp48)) {
        arg0->unk_04 |= 0x84000000;
        if (arg0->unk_00 < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->unk_00, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);
        arg0->unk_168.y = -54321.0f;
        return;
    }

    if (arg0->unk_A0 < 0.0f) {

        temp_fv0 = arg0->unk_A0 * arg0->unk_24C.xy;
        arg0->unk_0C.unk_28.x -= temp_fv0;
        arg0->unk_0C.unk_34.x -= temp_fv0;
        arg0->unk_0C.unk_44.x -= temp_fv0;

        temp_fv0 = arg0->unk_A0 * arg0->unk_24C.yy;
        arg0->unk_0C.unk_28.y -= temp_fv0;
        arg0->unk_0C.unk_34.y -= temp_fv0;
        arg0->unk_0C.unk_44.y -= temp_fv0;

        temp_fv0 = arg0->unk_A0 * arg0->unk_24C.zy;
        arg0->unk_0C.unk_28.z -= temp_fv0;
        arg0->unk_0C.unk_34.z -= temp_fv0;
        arg0->unk_0C.unk_44.z -= temp_fv0;

        arg0->unk_A0 = 0.0f;
        sp48 = (arg0->unk_24C.xy * arg0->unk_74.x) + (arg0->unk_24C.yy * arg0->unk_74.y) +
               (arg0->unk_24C.zy * arg0->unk_74.z);

        if (sp48 < 0.0f) {
            arg0->unk_74.x -= sp48 * arg0->unk_24C.xy;
            arg0->unk_74.y -= sp48 * arg0->unk_24C.yy;
            arg0->unk_74.z -= sp48 * arg0->unk_24C.zy;
            if ((arg0->unk_00 < gNumPlayers) && (D_800E5FD0 != 0)) {
                func_800BB3C4(arg0->unk_00, sp48);
            }
        }
    }

    if (arg0->unk_A0 <= 15.0f) {
        arg0->unk_04 &= ~0x4000000;
        if (arg0->unk_00 < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA3E4(arg0->unk_00, 8);
                }
            }
        }
        arg0->unk_A8.x = arg0->unk_B4.x = arg0->unk_24C.xy;
        arg0->unk_A8.y = arg0->unk_B4.y = arg0->unk_24C.yy;
        arg0->unk_A8.z = arg0->unk_B4.z = arg0->unk_24C.zy;
    } else {
        arg0->unk_04 |= 0x4000000;
        if (arg0->unk_00 < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->unk_00, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);

        if (arg0->unk_A0 < 30.0f) {
            temp_fv1 = (arg0->unk_A0 - 15.0f) / 15.0f;

            arg0->unk_A8.x = ((arg0->unk_A8.x - arg0->unk_24C.xy) * temp_fv1) + arg0->unk_24C.xy;
            arg0->unk_A8.y = ((arg0->unk_A8.y - arg0->unk_24C.yy) * temp_fv1) + arg0->unk_24C.yy;
            arg0->unk_A8.z = ((arg0->unk_A8.z - arg0->unk_24C.zy) * temp_fv1) + arg0->unk_24C.zy;

            arg0->unk_B4.x = ((arg0->unk_B4.x - arg0->unk_24C.xy) * temp_fv1) + arg0->unk_B4.x;
            arg0->unk_B4.y = ((arg0->unk_B4.y - arg0->unk_24C.yy) * temp_fv1) + arg0->unk_B4.y;
            arg0->unk_B4.z = ((arg0->unk_B4.z - arg0->unk_24C.zy) * temp_fv1) + arg0->unk_B4.z;

            temp_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));
            arg0->unk_B4.x *= temp_fv1;
            arg0->unk_B4.y *= temp_fv1;
            arg0->unk_B4.z *= temp_fv1;
        }
    }
    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_24C.xy);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_24C.yy);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_24C.zy);
}

extern u8 D_800CE3B0[];

void func_80090AFC(Racer* arg0) {

    if (!(arg0->unk_04 & 0x08004000)) {
        func_8008DBB8(arg0, 120);
    }
    arg0->unk_04 = arg0->unk_04 & ~0x400000 | 0x80000;

    if ((arg0->unk_00 < gNumPlayers) && (D_800E5FD0 != 0)) {
        if (D_800CE3B0[arg0->character] != 0) {
            func_800BA710(arg0->unk_00, 52);
        } else {
            func_800BA710(arg0->unk_00, 53);
        }
        func_800894C0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80090BCC.s")

extern s32 D_800F5DC8;
extern s8* D_800F5DD4;
extern s16 D_800F5DE4;
extern s16 D_800F5DE6;

void func_80094FF4(s32 arg0) {
    if (!(arg0 > -0x80 && arg0 < 0x80)) {
        D_800F5DC8 += 3;
        if (D_800F5DC8 <= 16200) {
            *D_800F5DD4++ = -0x80;
            // FAKE
            *D_800F5DD4++ = ((u16) arg0 >> 8);
            *D_800F5DD4++ = arg0 & 0xFF;
        } else {
            D_800F5DC8 -= 3;
            D_800F5DE6 = 1;
            D_800F5DE4 = 0;
        }
    } else {
        D_800F5DC8++;
        if (D_800F5DC8 <= 16200) {
            *D_800F5DD4++ = arg0;
        } else {
            D_800F5DC8--;
            D_800F5DE6 = 1;
            D_800F5DE4 = 0;
        }
    }
}

s32 func_800950E8(unk_800F5DF0* arg0) {
    s32 temp1 = *arg0->unk_08++;

    if (temp1 == -0x80) {
        temp1 = *arg0->unk_08++;
        temp1 <<= 8;
        temp1 |= (u8) *arg0->unk_08++;
        arg0->unk_0C += 3;
    } else {
        arg0->unk_0C++;
    }

    return temp1;
}

void func_80095144(void) {
    s32 i;

    for (i = 0; i < gNumPlayers; i++) {
        D_800DCE98[D_800DD218[i]].unk_72 = 0;
    }

    if (D_800F80C4 == 1) {
        func_80089220(0);
    } else if (D_800F80C4 == -1) {
        func_8008927C(0);
    }
}

extern s32 D_800F5E98;
void func_80090BCC(Racer*, Controller*);
void func_i3_80117BF0(Racer*, Controller*);

void func_800951DC(Racer* arg0) {
    Controller sp24;
    f32 sp20;

    if (arg0->unk_04 & 0x800000) {
        sp20 = arg0->unk_228;
        func_i3_80117BF0(arg0, &sp24);
        if (sp20 < arg0->unk_228) {
            arg0->unk_228 = sp20;
        }
        if ((D_800F5E98 >= 0x29) && (arg0->unk_2A4 != 0)) {
            sp24.unk_7A = 0;
            if (D_800F5E98 < 250) {
                arg0->unk_2A4--;
            }
        }
        func_80090BCC(arg0, &sp24);
    } else {
        func_80090BCC(arg0, &D_800DCE98[D_800DD218[arg0->unk_00]]);
        arg0->unk_33C = -arg0->unk_0C.unk_28.x * arg0->unk_24C.xz - arg0->unk_0C.unk_28.y * arg0->unk_24C.yz -
                        arg0->unk_0C.unk_28.z * arg0->unk_24C.zz;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800952F4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80096CE8.s")

extern Gfx* D_800CDD38[];
extern Gfx* D_800CDDB0[];
extern u8 D_800F8500[];

Gfx* func_8009CBE8(Gfx* gfx, s32 arg1, s32 red, s32 green, s32 blue) {
    u8 var_v1;

    if (arg1 < 6) {
        var_v1 = D_800F8500[arg1 + 3];
    } else if (arg1 == 6) {
        var_v1 = D_800F8500[9];
    } else {
        var_v1 = D_800F8500[10];
    }

    gSPDisplayList(gfx++, D_800CDD38[var_v1]);
    gDPSetEnvColor(gfx++, red, green, blue, 255);
    gSPDisplayList(gfx++, D_800CDDB0[var_v1 * 6]);
    return gfx;
}

Gfx* func_8009CCBC(Gfx* gfx, s32 arg1, s32 arg2) {
    unk_800CF1B0* temp_t0 = &D_800F80C8[arg1];

    gSPDisplayList(gfx++, D_800CDD38[arg1]);
    gDPSetEnvColor(gfx++, temp_t0->unk_04[arg2], temp_t0->unk_08[arg2], temp_t0->unk_0C[arg2], 255);
    gSPDisplayList(gfx++, D_800CDDB0[arg1 * 6]);
    return gfx;
}

extern Vtx* D_800CDBA4[];
extern void* D_800CDC54[];

Gfx* func_8009CD60(Gfx* gfx, s32 arg1) {
    unk_800CF1B0* temp_v1 = &D_800F80C8[arg1];

    gDPLoadTextureBlock_4b(gfx++, D_800CDC54[temp_v1->unk_02], G_IM_FMT_I, 32, 64, 0, G_TX_MIRROR | G_TX_CLAMP,
                           G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);

    gSPVertex(gfx++, D_800CDBA4[temp_v1->unk_02], 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    return gfx;
}

Gfx* func_8009CE70(Gfx* gfx, s32 arg1) {
    gSPDisplayList(gfx++, D_800CDDB0[arg1 * 6]);
    return gfx;
}

extern Gfx* D_800CDAD8[];

Gfx* func_8009CEA0(Gfx* gfx, s32 arg1) {
    gSPDisplayList(gfx++, D_800CDAD8[arg1]);
    return gfx;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D4C80.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D4CD8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D4CF8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D4EF0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D4F58.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D5004.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D50B0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D515C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D524C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D52F8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D5308.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D5310.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D5328.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D5340.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D5358.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D53B0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D544C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D54A4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D5540.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D5544.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D554C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/D_800D5558.s")
