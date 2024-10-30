#include "global.h"

s32 D_i2_80106F40 = 0;

unk_80111870 D_80111870[32];
s32 D_80111CF0;
s32 D_80111CF4;
unk_80111870 D_80111CF8[32];
s32 D_80112178;
s32 D_8011217C;
unk_80111870 D_80112180[8];
s32 D_801122A0;
s32 D_801122A4;
unk_801122A8 D_801122A8[32];
s32 D_80112B28;
s32 D_80112B2C;
unk_80111870 D_80112B30[32];
s32 D_80112FB0;
s32 D_80112FB4;
unk_80112FB8 D_80112FB8[32];
s32 D_80113138;
s32 D_8011313C;
unk_80113140 D_80113140[128];
s32 D_80115D40;
s32 D_80115D44;

UNUSED u8 D_80115D48[0xA0];

void func_i2_801044F0(void) {
    s32 i;

    D_80111CF0 = D_80111CF4 = 0;

    for (i = 0; i < ARRAY_COUNT(D_80111870); i++) {
        D_80111870[i].unk_1C = 0;
    }

    D_80112178 = D_8011217C = 0;

    for (i = 0; i < ARRAY_COUNT(D_80111CF8); i++) {
        D_80111CF8[i].unk_1C = 0;
    }

    D_801122A0 = D_801122A4 = 0;

    for (i = 0; i < ARRAY_COUNT(D_80112180); i++) {
        D_80112180[i].unk_1C = 0;
    }

    D_80112B28 = D_80112B2C = 0;

    for (i = 0; i < ARRAY_COUNT(D_801122A8); i++) {
        D_801122A8[i].unk_3C = 0;
    }

    D_80112FB0 = D_80112FB4 = 0;

    for (i = 0; i < ARRAY_COUNT(D_80112B30); i++) {
        D_80112B30[i].unk_1C = 0;
    }

    D_80113138 = D_8011313C = 0;

    for (i = 0; i < ARRAY_COUNT(D_80112FB8); i++) {
        D_80112FB8[i].unk_04 = 0;
    }

    D_80115D40 = D_80115D44 = 0;

    for (i = 0; i < ARRAY_COUNT(D_80113140); i++) {
        D_80113140[i].unk_50 = 0;
    }
}

void func_i2_8010466C(void);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9FE40/func_i2_8010466C.s")
extern s8 D_800DCE5C;
extern f32 D_800DD230[];

s32 func_i2_801054C0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Racer* arg7) {
    unk_80111870* temp_v1;

    if (D_80111CF4 < 0x20) {
        if (arg7->unk_220 != 0) {
            return -1;
        }
        arg7->unk_220 = 5;
        temp_v1 = &D_80111870[D_80111CF0];
        temp_v1->unk_00.x = arg0 + arg3;
        temp_v1->unk_00.y = arg1 + arg4;
        temp_v1->unk_00.z = arg2 + arg5;
        temp_v1->unk_0C.x = arg3;
        temp_v1->unk_0C.y = arg4;
        temp_v1->unk_0C.z = arg5;
        temp_v1->unk_18 = arg6;
        temp_v1->unk_20 = arg7;
        D_80111CF0 = (D_80111CF0 + 1) % 32U;
        D_80111CF4++;
        return 0;
    }
    return -1;
}

s32 func_i2_80105590(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Racer* arg7) {
    unk_80111870* temp_v1;

    if (D_8011217C < 0x20) {
        temp_v1 = &D_80111CF8[D_80112178];
        temp_v1->unk_00.x = arg0 + arg3;
        temp_v1->unk_00.y = arg1 + arg4;
        temp_v1->unk_00.z = arg2 + arg5;
        temp_v1->unk_0C.x = arg3;
        temp_v1->unk_0C.y = arg4;
        temp_v1->unk_0C.z = arg5;
        temp_v1->unk_18 = arg6;
        temp_v1->unk_20 = arg7;
        D_80112178 = (D_80112178 + 1) % 32U;
        D_8011217C++;
        return 0;
    }
    return -1;
}

s32 func_i2_80105648(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Racer* arg7) {
    unk_80111870* temp_v1;

    if (D_801122A4 < 8) {
        temp_v1 = &D_80112180[D_801122A0];
        temp_v1->unk_00.x = arg0 + arg3;
        temp_v1->unk_00.y = arg1 + arg4;
        temp_v1->unk_00.z = arg2 + arg5;
        temp_v1->unk_0C.x = arg3;
        temp_v1->unk_0C.y = arg4;
        temp_v1->unk_0C.z = arg5;
        temp_v1->unk_18 = arg6;
        temp_v1->unk_20 = arg7;
        D_801122A0 = (D_801122A0 + 1) % 8U;
        D_801122A4++;
        return 0;
    }
    return -1;
}

s32 func_i2_80105700(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, Racer* arg6) {
    unk_801122A8* temp_v1;
    f32 temp_fa1;

    if (D_80112B2C < 0x20) {
        temp_v1 = &D_801122A8[D_80112B28];
        temp_fa1 = SQ(arg3) + SQ(arg4) + SQ(arg5);
        if (temp_fa1 < 0.01f) {
            return -1;
        }

        temp_fa1 = 1.0f / sqrtf(temp_fa1);

        temp_v1->unk_18.x = temp_fa1 * arg3;
        temp_v1->unk_18.y = temp_fa1 * arg4;
        temp_v1->unk_18.z = temp_fa1 * arg5;

        temp_fa1 = SQ(temp_v1->unk_18.z) + SQ(temp_v1->unk_18.x);

        if (temp_fa1 < 0.01f) {
            return -1;
        }

        temp_fa1 = 1.0f / sqrtf(temp_fa1);

        temp_v1->unk_30.x = temp_v1->unk_18.z * temp_fa1;
        temp_v1->unk_30.y = 0.0f;
        temp_v1->unk_30.z = -temp_v1->unk_18.x * temp_fa1;

        temp_v1->unk_24.x = temp_v1->unk_18.y * temp_v1->unk_30.z;
        temp_v1->unk_24.y = (temp_v1->unk_18.z * temp_v1->unk_30.x) - (temp_v1->unk_18.x * temp_v1->unk_30.z);
        temp_v1->unk_24.z = -temp_v1->unk_18.y * temp_v1->unk_30.x;
        temp_v1->unk_00.x = arg0 + arg3;
        temp_v1->unk_00.y = arg1 + arg4;
        temp_v1->unk_00.z = arg2 + arg5;
        temp_v1->unk_0C.x = arg3;
        temp_v1->unk_0C.y = arg4;
        temp_v1->unk_0C.z = arg5;
        temp_v1->unk_40 = arg6;
        D_80112B28 = (D_80112B28 + 1) % 32U;
        D_80112B2C++;
        return 0;
    }

    return -1;
}

s32 func_i2_801058FC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Racer* arg7) {
    unk_80111870* temp_v1;

    if (D_80112FB4 < 0x20) {
        temp_v1 = &D_80112B30[D_80112FB0];
        temp_v1->unk_00.x = arg0 + arg3;
        temp_v1->unk_00.y = arg1 + arg4;
        temp_v1->unk_00.z = arg2 + arg5;
        temp_v1->unk_0C.x = arg3;
        temp_v1->unk_0C.y = arg4;
        temp_v1->unk_0C.z = arg5;
        temp_v1->unk_18 = arg6;
        temp_v1->unk_20 = arg7;
        D_80112FB0 = (D_80112FB0 + 1) % 32U;
        D_80112FB4++;
        return 0;
    }

    return -1;
}

s32 func_i2_801059B4(f32 arg0, Racer* arg1) {
    unk_80112FB8* temp_v1;

    if (D_8011313C < 32) {
        temp_v1 = &D_80112FB8[D_80113138];
        temp_v1->unk_00 = arg0;
        temp_v1->unk_08 = arg1;
        D_80113138 = (D_80113138 + 1) % 32U;
        D_8011313C++;
        return 0;
    }
    return -1;
}

s32 func_i2_80105A28(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, Mtx3F* arg6, s32 arg7, s32 arg8,
                     s32 arg9, Racer* argA) {
    unk_80113140* temp_s1;
    f32 temp_fs0;
    f32 temp_fv0;

    if (D_80115D44 < 128) {
        temp_s1 = &D_80113140[D_80115D40];
        temp_fs0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_fv0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_s1->unk_00.x = arg0 + (temp_fs0 * arg6->z.x) + (temp_fv0 * arg6->x.x);
        temp_s1->unk_00.y = arg1 + (temp_fs0 * arg6->z.y) + (temp_fv0 * arg6->x.y);
        temp_s1->unk_00.z = arg2 + (temp_fs0 * arg6->z.z) + (temp_fv0 * arg6->x.z);

        temp_fs0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_fv0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_s1->unk_0C.x = arg0 + (temp_fs0 * arg6->z.x) + (temp_fv0 * arg6->x.x);
        temp_s1->unk_0C.y = arg1 + (temp_fs0 * arg6->z.y) + (temp_fv0 * arg6->x.y);
        temp_s1->unk_0C.z = arg2 + (temp_fs0 * arg6->z.z) + (temp_fv0 * arg6->x.z);

        temp_fs0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_fv0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_s1->unk_18.x = arg0 + (temp_fs0 * arg6->z.x) + (temp_fv0 * arg6->x.x);
        temp_s1->unk_18.y = arg1 + (temp_fs0 * arg6->z.y) + (temp_fv0 * arg6->x.y);
        temp_s1->unk_18.z = arg2 + (temp_fs0 * arg6->z.z) + (temp_fv0 * arg6->x.z);
        temp_s1->unk_24.x = Math_Rand1() % 4096;
        temp_s1->unk_24.y = Math_Rand1() % 4096;
        temp_s1->unk_24.z = Math_Rand1() % 4096;
        temp_s1->unk_30.x = arg3;
        temp_s1->unk_30.y = arg4;
        temp_s1->unk_30.z = arg5;
        temp_s1->unk_3C.x = arg6->y.x;
        temp_s1->unk_3C.y = arg6->y.y;
        temp_s1->unk_3C.z = arg6->y.z;
        temp_s1->unk_48 = arg7;
        temp_s1->unk_4A = arg8;
        temp_s1->unk_4C = arg9;
        temp_s1->unk_4E = 0;
        temp_s1->unk_54 = argA;
        D_80115D40 = (D_80115D40 + 1) % 128U;
        D_80115D44++;
        return 0;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9FE40/D_i2_8010AE10.s")
