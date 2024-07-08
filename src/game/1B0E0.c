#include "global.h"

typedef struct unk_struct_8 {
    s32 unk_00;
    s32 unk_04;
} unk_struct_8; // size = 0x8

typedef struct unk_struct_20_2 {
    unk_struct_8 unk_00[4];
} unk_struct_20_2; // size = 0x20

typedef struct unk_struct_14 {
    s32 unk_00;
    f32* unk_04[1];
    s32* unk_08;
    s8 unk_0C[0x4];
    s32* unk_10;
} unk_struct_14; // size = 0x14

typedef struct unk_struct_20 {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18;
    f32 unk_1C;
} unk_struct_20; // size = 0x20

typedef struct unk_struct_54 {
    unk_struct_20 unk_00;
    f32 unk_20;
    Vec3f unk_24;
    Vec3f unk_30;
    Vec3f unk_3C;
    Vec3f unk_48;
} unk_struct_54; // size = 0x54

typedef struct unk_struct_68 {
    unk_struct_54 unk_00;
    Vec3f unk_54;
    f32 unk_60;
    f32 unk_64;
} unk_struct_68; // size = 0x68

typedef struct unk_struct_9C {
    unk_struct_68 unk_00;
    f32 unk_68[10];
    f32 unk_90;
    s8 unk_94[0x4];
    s32 unk_98;
} unk_struct_9C; // size = 0x9C

typedef struct unk_struct_58 {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18[16];
} unk_struct_58; // size = 0x58

typedef struct unk_8008112C_arg_1 {
    unk_struct_58 unk_00;
    unk_struct_9C unk_58;
} unk_8008112C_arg_1; // size = 0xF4

typedef struct unk_struct_F8 {
    s32 unk_00;
    unk_8008112C_arg_1 unk_04;
} unk_struct_F8; // size = 0xF8
extern unk_struct_F8 D_800E5990[];

typedef struct unk_struct_1DC {
    s32 unk_00;
    u32 unk_04;
    s32 unk_08;
    s8 unk_0C[0x44];
    Vec3f unk_50;
    Mtx3F unk_5C;
    f32 unk_80;
    f32 unk_84;
    Vec3f unk_88;
    Vec3f unk_94;
    s8 unk_A0[0x10];
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    f32 unk_BC;
    s8 unk_C0[0x20];
    s32 unk_E0;
    s8 unk_E4[0xF8];
} unk_struct_1DC; // size = 0x1DC
extern unk_struct_1DC D_800E5220[];

typedef struct unk_802C4920 {
    s8 unk_00[0x4];
    s32 unk_04;
    s8 unk_08[0x4];
    s32* unk_0C;
    s8 unk_10[0x30];
    Vec3f unk_40;
    s8 unk_4C[0x4C];
    f32 unk_98;
    s8 unk_9C[0x18];
    Vec3f unk_B4;
    s8 unk_C0[0x2E8];
} unk_802C4920; // size = 0x3A8
extern unk_802C4920 D_802C4920[];

typedef struct unk_struct_C {
    s32 unk_00;
    void* unk_04;
    void* unk_08;
} unk_struct_C; // size = 0xC

typedef struct unk_800E5D70 {
    unk_struct_F8* unk_00;
    unk_struct_C* unk_04;
    s32 unk_08;
    unk_struct_20_2* unk_0C;
    Vec3f* unk_10;
    Mtx3F* unk_14;
    unk_802C4920* unk_18;
    Vec3f* unk_1C;
    Mtx3F* unk_20;
} unk_800E5D70; // size = 0x24
extern unk_800E5D70 D_800E5D70[];

typedef struct unk_80085434_arg_0 {
    Vec3f unk_00[2];
    f32 unk_18;
} unk_80085434_arg_0; // size = 0x1C

typedef struct unk_80085494_arg_0 {
    Vec3f unk_00[3];
    f32 unk_24;
} unk_80085494_arg_0; // size = 0x28

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

    var->unk_00.unk_00.x += (var->unk_58.unk_00.unk_00.unk_00.unk_00.x - var->unk_00.unk_00.x) * var->unk_58.unk_00.unk_00.unk_00.unk_18;
    var->unk_00.unk_00.y += (var->unk_58.unk_00.unk_00.unk_00.unk_00.y - var->unk_00.unk_00.y) * var->unk_58.unk_00.unk_00.unk_00.unk_18;
    var->unk_00.unk_00.z += (var->unk_58.unk_00.unk_00.unk_00.unk_00.z - var->unk_00.unk_00.z) * var->unk_58.unk_00.unk_00.unk_00.unk_18;
    var->unk_00.unk_0C.x += (var->unk_58.unk_00.unk_00.unk_00.unk_0C.x - var->unk_00.unk_0C.x) * var->unk_58.unk_00.unk_00.unk_00.unk_1C;
    var->unk_00.unk_0C.y += (var->unk_58.unk_00.unk_00.unk_00.unk_0C.y - var->unk_00.unk_0C.y) * var->unk_58.unk_00.unk_00.unk_00.unk_1C;
    var->unk_00.unk_0C.z += (var->unk_58.unk_00.unk_00.unk_00.unk_0C.z - var->unk_00.unk_0C.z) * var->unk_58.unk_00.unk_00.unk_00.unk_1C;
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

    arg0->unk_04.unk_58.unk_00.unk_00.unk_30.x += (arg0->unk_04.unk_58.unk_00.unk_00.unk_30.y - arg0->unk_04.unk_58.unk_00.unk_00.unk_30.x) * arg0->unk_04.unk_58.unk_00.unk_00.unk_30.z;
    arg0->unk_04.unk_58.unk_00.unk_00.unk_3C.x += (arg0->unk_04.unk_58.unk_00.unk_00.unk_3C.y - arg0->unk_04.unk_58.unk_00.unk_00.unk_3C.x) * arg0->unk_04.unk_58.unk_00.unk_00.unk_3C.z;
    arg0->unk_04.unk_58.unk_00.unk_00.unk_48.x += (arg0->unk_04.unk_58.unk_00.unk_00.unk_48.y - arg0->unk_04.unk_58.unk_00.unk_00.unk_48.x) * arg0->unk_04.unk_58.unk_00.unk_00.unk_48.z;
    temp_v1 = &arg0->unk_04.unk_58;
    temp_v0 = func_8006A9E0(arg0->unk_04.unk_58.unk_00.unk_00.unk_3C.x * 11.377778f);

    sp3C = temp_v1->unk_00.unk_00.unk_30.x * D_800DD230[temp_v0 & 0xFFF];
    sp40 = temp_v1->unk_00.unk_00.unk_30.x * D_800DD230[(temp_v0 + 0x400) & 0xFFF];

    temp_v0 = func_8006A9E0(temp_v1->unk_00.unk_00.unk_48.x * 11.377778f);
    temp_fv0 = D_800DD230[temp_v0 & 0xFFF] * sp40;
    temp_fv1 = D_800DD230[(temp_v0 + 0x400) & 0xFFF] * sp40;
    
    temp_fa0 = (temp_v1->unk_00.unk_00.unk_00.unk_0C.x * temp_fv1) + (temp_v1->unk_00.unk_00.unk_24.x * temp_fv0) + (temp_v1->unk_00.unk_00.unk_00.unk_18 * sp3C);
    temp_ft5 = (temp_v1->unk_00.unk_00.unk_00.unk_0C.y * temp_fv1) + (temp_v1->unk_00.unk_00.unk_24.y * temp_fv0) + (temp_v1->unk_00.unk_00.unk_00.unk_1C * sp3C);
    sp28 = (temp_v1->unk_00.unk_00.unk_00.unk_0C.z * temp_fv1) + (temp_v1->unk_00.unk_00.unk_24.z * temp_fv0) + (temp_v1->unk_00.unk_00.unk_20 * sp3C);

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

void func_80081794(unk_struct_F8* arg0, void* arg1);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80081794.s")

void func_80081E24(unk_struct_F8* arg0) {
    s32 pad;
    unk_8008112C_arg_1* var = &arg0->unk_04;

    var->unk_58.unk_00.unk_00.unk_30.x += (var->unk_58.unk_00.unk_00.unk_3C.x - var->unk_58.unk_00.unk_00.unk_30.x) * var->unk_58.unk_00.unk_60;
    var->unk_58.unk_00.unk_00.unk_30.y += (var->unk_58.unk_00.unk_00.unk_3C.y - var->unk_58.unk_00.unk_00.unk_30.y) * var->unk_58.unk_00.unk_60;
    var->unk_58.unk_00.unk_00.unk_30.z += (var->unk_58.unk_00.unk_00.unk_3C.z - var->unk_58.unk_00.unk_00.unk_30.z) * var->unk_58.unk_00.unk_60;


    var->unk_58.unk_00.unk_00.unk_48.x += (var->unk_58.unk_00.unk_54.x - var->unk_58.unk_00.unk_00.unk_48.x) * var->unk_58.unk_00.unk_64;
    var->unk_58.unk_00.unk_00.unk_48.y += (var->unk_58.unk_00.unk_54.y - var->unk_58.unk_00.unk_00.unk_48.y) * var->unk_58.unk_00.unk_64;
    var->unk_58.unk_00.unk_00.unk_48.z += (var->unk_58.unk_00.unk_54.z - var->unk_58.unk_00.unk_00.unk_48.z) * var->unk_58.unk_00.unk_64;
    
    var->unk_00.unk_00.x = var->unk_58.unk_00.unk_00.unk_00.unk_00.x + (var->unk_58.unk_00.unk_00.unk_24.x * var->unk_58.unk_00.unk_00.unk_30.x) + (var->unk_58.unk_00.unk_00.unk_00.unk_18 * var->unk_58.unk_00.unk_00.unk_30.y) + (var->unk_58.unk_00.unk_00.unk_00.unk_0C.x * var->unk_58.unk_00.unk_00.unk_30.z);
    var->unk_00.unk_00.y = var->unk_58.unk_00.unk_00.unk_00.unk_00.y + (var->unk_58.unk_00.unk_00.unk_24.y * var->unk_58.unk_00.unk_00.unk_30.x) + (var->unk_58.unk_00.unk_00.unk_00.unk_1C * var->unk_58.unk_00.unk_00.unk_30.y) + (var->unk_58.unk_00.unk_00.unk_00.unk_0C.y * var->unk_58.unk_00.unk_00.unk_30.z);
    var->unk_00.unk_00.z = var->unk_58.unk_00.unk_00.unk_00.unk_00.z + (var->unk_58.unk_00.unk_00.unk_24.z * var->unk_58.unk_00.unk_00.unk_30.x) + (var->unk_58.unk_00.unk_00.unk_20 * var->unk_58.unk_00.unk_00.unk_30.y) + (var->unk_58.unk_00.unk_00.unk_00.unk_0C.z * var->unk_58.unk_00.unk_00.unk_30.z);
    
    var->unk_00.unk_0C.x = var->unk_58.unk_00.unk_00.unk_00.unk_00.x + (var->unk_58.unk_00.unk_00.unk_24.x * var->unk_58.unk_00.unk_00.unk_48.x) + (var->unk_58.unk_00.unk_00.unk_00.unk_18 * var->unk_58.unk_00.unk_00.unk_48.y) + (var->unk_58.unk_00.unk_00.unk_00.unk_0C.x * var->unk_58.unk_00.unk_00.unk_48.z);
    var->unk_00.unk_0C.y = var->unk_58.unk_00.unk_00.unk_00.unk_00.y + (var->unk_58.unk_00.unk_00.unk_24.y * var->unk_58.unk_00.unk_00.unk_48.x) + (var->unk_58.unk_00.unk_00.unk_00.unk_1C * var->unk_58.unk_00.unk_00.unk_48.y) + (var->unk_58.unk_00.unk_00.unk_00.unk_0C.y * var->unk_58.unk_00.unk_00.unk_48.z);
    var->unk_00.unk_0C.z = var->unk_58.unk_00.unk_00.unk_00.unk_00.z + (var->unk_58.unk_00.unk_00.unk_24.z * var->unk_58.unk_00.unk_00.unk_48.x) + (var->unk_58.unk_00.unk_00.unk_20 * var->unk_58.unk_00.unk_00.unk_48.y) + (var->unk_58.unk_00.unk_00.unk_00.unk_0C.z * var->unk_58.unk_00.unk_00.unk_48.z);
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
        func_8006AA38((Mtx3F* ) &arg0->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C);
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

    sp54 = (s32)arg2 / 20;
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

void func_80082624(unk_80082624_arg_0* arg0, f32* arg1, f32* arg2, s32 arg3) {
    Vec3f* var_v0;
    f32 temp_fv0;
    s32 temp_v1;

    if (arg3 == 2) {
        var_v0 = &D_800D5328[arg0->unk_08];
    } else {
        var_v0 = &D_800D52F8[arg0->unk_08];
    }
    arg2[28] = var_v0->y;
    arg2[31] = var_v0->z;

    arg1[14] = arg0->unk_14 = var_v0->x;

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

            if (arg1){}
            arg1->u.i[i][j] = var_v1 >> 0x10;
            arg1->u.f[i][j] = var_v1 & 0xFFFF;
        }
    }
}

void func_80082A6C(void*, unk_struct_1DC*);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80082A6C.s")

void func_800BA2D0(u8);
extern s32 D_800E5FB8;

void func_80082C80(unk_struct_1DC* arg0) {
    s32 pad[3];
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fa0;
    f32 var_fv1;
    unk_802C4920* temp_v0;

    temp_v0 = &D_802C4920[D_800E5FB8];
    temp_fa1 = temp_v0->unk_40.x - arg0->unk_50.x;
    temp_ft4 = temp_v0->unk_40.y - arg0->unk_50.y;
    temp_ft5 = temp_v0->unk_40.z - arg0->unk_50.z;
    
    var_fv1 = sqrtf(SQ(temp_fa1) + SQ(temp_ft4) + SQ(temp_ft5));

    if (var_fv1 != 0.0f) {
        temp_fa0 = (-((temp_fa1 * arg0->unk_5C.xz) + (temp_ft4 * arg0->unk_5C.yz) + (temp_ft5 * arg0->unk_5C.zz))) / var_fv1;
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
    temp_v0 = func_8006A9E0(arg1 * 11.377778f);
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

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80083034.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80083074.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80083210.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800832EC.s")

// #pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800833AC.s")
Gfx* func_8006A00C(Gfx*, s32);
extern s32 D_800CD000;
extern s32 D_800DCE44;
// Todo: figure out what this array is
extern Vp D_1000000[];

Gfx* func_800833AC(Gfx* gfx, s32 arg1, s32 arg2) {
    unk_struct_1DC* temp_v0 = &D_800E5220[arg2];

    if (temp_v0->unk_E0 == 1) {
        // FAKE
        gSPViewport(gfx++, (s8*)&D_1000000[arg2] + 0x2C2C8);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, temp_v0->unk_B0, temp_v0->unk_B4, temp_v0->unk_B8, temp_v0->unk_BC);

    } else {
        if (1) {}
        gfx = func_8006A00C(gfx, arg1);
        if ((D_800CD000 == 1) && (D_800DCE44 != 6) && (D_800DCE44 != 0x11)) {
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

void func_80083558(unk_800E5D70* arg0, void* arg1, void* arg2, unk_802C4920* arg3) {
    arg0->unk_10 = arg1;
    arg0->unk_14 = arg2;
    arg0->unk_18 = arg3;
}

void func_80083568(unk_800E5D70* arg0, void* arg1, void* arg2) {
    arg0->unk_1C = arg1;
    arg0->unk_20 = arg2;
}

void func_80083574(unk_800E5D70* arg0, void* arg1) {
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

    sp30.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp48[1].z + arg0->unk_20->mf[1][0] * sp48[1].y + arg0->unk_20->mf[2][0] * sp48[1].x;
    sp30.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp48[1].z + arg0->unk_20->mf[1][1] * sp48[1].y + arg0->unk_20->mf[2][1] * sp48[1].x;
    sp30.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp48[1].z + arg0->unk_20->mf[1][2] * sp48[1].y + arg0->unk_20->mf[2][2] * sp48[1].x;
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

    sp2C.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp44[1].z + arg0->unk_20->mf[1][0] * sp44[1].y + arg0->unk_20->mf[2][0] * sp44[1].x;
    sp2C.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp44[1].z + arg0->unk_20->mf[1][1] * sp44[1].y + arg0->unk_20->mf[2][1] * sp44[1].x;
    sp2C.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp44[1].z + arg0->unk_20->mf[1][2] * sp44[1].y + arg0->unk_20->mf[2][2] * sp44[1].x;
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

    sp2C.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp44.unk_00[1].z + arg0->unk_20->mf[1][0] * sp44.unk_00[1].y + arg0->unk_20->mf[2][0] * sp44.unk_00[1].x;
    sp2C.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp44.unk_00[1].z + arg0->unk_20->mf[1][1] * sp44.unk_00[1].y + arg0->unk_20->mf[2][1] * sp44.unk_00[1].x;
    sp2C.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp44.unk_00[1].z + arg0->unk_20->mf[1][2] * sp44.unk_00[1].y + arg0->unk_20->mf[2][2] * sp44.unk_00[1].x;
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

    sp30.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp48.unk_00[1].z + arg0->unk_20->mf[1][0] * sp48.unk_00[1].y + arg0->unk_20->mf[2][0] * sp48.unk_00[1].x;
    sp30.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp48.unk_00[1].z + arg0->unk_20->mf[1][1] * sp48.unk_00[1].y + arg0->unk_20->mf[2][1] * sp48.unk_00[1].x;
    sp30.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp48.unk_00[1].z + arg0->unk_20->mf[1][2] * sp48.unk_00[1].y + arg0->unk_20->mf[2][2] * sp48.unk_00[1].x;
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
    sp64 = func_8006A9E0(sp5C * 11.377778f);
    temp_v0 = func_8006A9E0(sp58 * 11.377778f);
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
    sp6C = func_8006A9E0(sp64 * 11.377778f);
    temp_v0 = func_8006A9E0(sp60 * 11.377778f);
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
    sp64 = func_8006A9E0(sp5C * 11.377778f);
    temp_v0 = func_8006A9E0(sp58 * 11.377778f);
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
    sp74 = func_8006A9E0(sp6C * 11.377778f);
    temp_v0 = func_8006A9E0(sp68 * 11.377778f);
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
    unk_802C4920* temp_v1;
    Vec3f sp38[2];
    Vec3f sp2C;

    func_80085390(sp38, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*)&temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*)&temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->unk_98;
    temp_v0->unk_98 = temp_v1->unk_0C[8];
    sp2C.x = sp38[0].x + arg0->unk_10->x;
    sp2C.y = sp38[0].y + arg0->unk_10->y;
    sp2C.z = sp38[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp2C, &sp38[1], 0, 0);
}

void func_80084A04(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    unk_802C4920* temp_v1;
    Vec3f sp34[3];
    Vec3f sp28;

    func_800853D4(sp34, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*)&temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*)&temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->unk_98;
    temp_v0->unk_98 = temp_v1->unk_0C[8];
    sp28.x = sp34[0].x + arg0->unk_10->x;
    sp28.y = sp34[0].y + arg0->unk_10->y;
    sp28.z = sp34[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp28, &sp34[1], &sp34[2], 0);
}

void func_80084AF4(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[6];
    unk_struct_9C* temp_v0;
    unk_802C4920* temp_v1;
    unk_80085434_arg_0 sp34;
    Vec3f sp28;

    func_80085434(&sp34, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*)&temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*)&temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->unk_98;
    temp_v0->unk_98 = temp_v1->unk_0C[8];
    sp28.x = sp34.unk_00[0].x + arg0->unk_10->x;
    sp28.y = sp34.unk_00[0].y + arg0->unk_10->y;
    sp28.z = sp34.unk_00[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp28, &sp34.unk_00[1], 0, &sp34.unk_18);
}

void func_80084BE8(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    unk_802C4920* temp_v1;
    unk_80085494_arg_0 sp38;
    Vec3f sp2C;

    func_80085494(&sp38, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*)&temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*)&temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->unk_98;
    temp_v0->unk_98 = temp_v1->unk_0C[8];
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

    *arg0 = func_80084D50((f32) arg1->unk_00 / (f32) arg2->unk_08[arg1->unk_04], arg1->unk_04, arg2->unk_04[0], arg2->unk_00);

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
        arg0->v[i] = func_80084D50((f32) arg1->unk_00 / (f32) arg2->unk_10[arg1->unk_04], arg1->unk_04, arg2->unk_04[i], arg2->unk_00);
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
    unk_802C4920* temp_a3;
    unk_struct_1DC* var_s0;
    unk_struct_20_2* var_s4;
    unk_struct_F8* var_s3;

    for (i = 0, var_s0 = D_800E5220, var_s1 = D_800E5D70, var_s3 = D_800E5990, var_s4 = D_800E5E00; i < 4; i++) {
        var_s0->unk_00 = (s16)i;
        var_s0->unk_08 = 2;
        var_s0->unk_E0 = 0;
        func_80083548(var_s1, var_s3);
        func_80083550(var_s1, var_s4);
        temp_a3 = &D_802C4920[var_s0->unk_00];
        func_80083558(var_s1, &temp_a3->unk_C0[0xC0], &temp_a3->unk_C0[0], temp_a3);

        var_s1++;
        var_s3++;
        var_s4++;
        var_s0++;
    }
    D_800E5E8A = 0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80085610.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80085B80.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80086400.s")

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
extern void* D_800DCCF0;

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
                    break;
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

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800876A8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800879E0.s")

void func_80087DB8(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 index = arg0->unk_00;
    
    if (D_802C4920[index].unk_04 & 0x80000) {
        arg0->unk_04 = 7;
        func_80085B80(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80087E14.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80087F60.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80087FAC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80088408.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800885F0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80088660.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800888D0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80088CAC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80088CB8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80088CE0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80088D28.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800890B4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80089220.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008927C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800892E0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800894C0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008960C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80089654.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008969C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80089724.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80089800.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80089934.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80089A74.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80089BD0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008A978.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008AA8C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008AD38.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008B150.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008B1CC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008B23C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008B2D8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008C14C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008C7C8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008D33C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008D3C4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008D5F4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008D7E8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008D824.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008D8E8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008D97C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008DA68.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008DB98.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008DBB8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008DCD8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008E188.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008E418.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008E504.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008E54C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008EC38.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008EC58.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008EC78.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008EC98.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008F550.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008FC80.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80090490.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80090568.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80090AFC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80090BCC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80094FF4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800950E8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80095144.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800951DC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800952F4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80096CE8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8009CBE8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8009CCBC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8009CD60.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8009CE70.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8009CEA0.s")

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
