#include "global.h"

s32 gSettingVsSlot = 0;
s32 gRaceTimeIntervalToggle = 0;
s16 gPlayer1OverallPosition = 0;

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

// TODO: move to new file
UNUSED u8 D_80115D48[8];
s16 D_80115D50[30];
s16 gRacerPositionsById[30];
s32 D_80115DD0[4];
s16 D_80115DE0;

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

extern s8 D_800DCE5C;

void func_i2_8010466C(void) {
    u32 var_s2;
    s32 var_s3;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    unk_80111870* var;
    unk_801122A8* var2;
    unk_80112FB8* var3;
    unk_80113140* var4;

    if (D_800DCE5C != 0) {
        return;
    }

    for (var_s3 = D_80111CF4, var_s2 = (D_80111CF0 - 1), var_s2 %= ARRAY_COUNT(D_80111870); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_80111870), var_s3--) {
        var = &D_80111870[var_s2];
        var->unk_1C = (var->unk_1C + 1) % 16;
        if (var->unk_1C != 0) {
            var->unk_18 *= 1.05f;
            var->unk_00.x += var->unk_0C.x;
            var->unk_00.y += var->unk_0C.y;
            var->unk_00.z += var->unk_0C.z;
        } else {
            D_80111CF4--;
        }
    }

    for (var_s3 = D_8011217C, var_s2 = (D_80112178 - 1), var_s2 %= ARRAY_COUNT(D_80111CF8); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_80111CF8), var_s3--) {
        var = &D_80111CF8[var_s2];
        var->unk_1C = (var->unk_1C + 1) % 16;
        if (var->unk_1C != 0) {
            var->unk_18 *= 1.02f;
            var->unk_00.x += var->unk_0C.x;
            var->unk_00.y += var->unk_0C.y;
            var->unk_00.z += var->unk_0C.z;
        } else {
            D_8011217C--;
        }
    }

    for (var_s3 = D_801122A4, var_s2 = (D_801122A0 - 1), var_s2 %= ARRAY_COUNT(D_80112180); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_80112180), var_s3--) {
        var = &D_80112180[var_s2];
        var->unk_1C = (var->unk_1C + 1) % 32;
        if (var->unk_1C != 0) {
            var->unk_18 *= 1.02f;
            var->unk_00.x += var->unk_0C.x;
            var->unk_00.y += var->unk_0C.y;
            var->unk_00.z += var->unk_0C.z;
        } else {
            D_801122A4--;
        }
    }

    for (var_s3 = D_80112B2C, var_s2 = (D_80112B28 - 1), var_s2 %= ARRAY_COUNT(D_801122A8); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_801122A8), var_s3--) {
        var2 = &D_801122A8[var_s2];
        var2->unk_3C = (var2->unk_3C + 1) % 64;

        if (var2->unk_3C != 0) {
            Racer* racer = var2->unk_40;
            var2->unk_00.x += var2->unk_0C.x -= 0.4f * racer->unk_A8.x;
            var2->unk_00.y += var2->unk_0C.y -= 0.4f * racer->unk_A8.y;
            var2->unk_00.z += var2->unk_0C.z -= 0.4f * racer->unk_A8.z;

            temp_fv1 = 1.0f / sqrtf(SQ(var2->unk_0C.x) + SQ(var2->unk_0C.y) + SQ(var2->unk_0C.z));
            var2->unk_18.x = var2->unk_0C.x * temp_fv1;
            var2->unk_18.y = var2->unk_0C.y * temp_fv1;
            var2->unk_18.z = var2->unk_0C.z * temp_fv1;

            var2->unk_24.x += var2->unk_30.x;
            var2->unk_24.y += var2->unk_30.y;
            var2->unk_24.z += var2->unk_30.z;

            var2->unk_30.x = (var2->unk_24.y * var2->unk_18.z) - (var2->unk_24.z * var2->unk_18.y);
            var2->unk_30.y = (var2->unk_24.z * var2->unk_18.x) - (var2->unk_24.x * var2->unk_18.z);
            var2->unk_30.z = (var2->unk_24.x * var2->unk_18.y) - (var2->unk_24.y * var2->unk_18.x);

            temp_fv1 = 1.0f / sqrtf(SQ(var2->unk_30.x) + SQ(var2->unk_30.y) + SQ(var2->unk_30.z));
            var2->unk_30.x *= temp_fv1;
            var2->unk_30.y *= temp_fv1;
            var2->unk_30.z *= temp_fv1;

            var2->unk_24.x = (var2->unk_18.y * var2->unk_30.z) - (var2->unk_18.z * var2->unk_30.y);
            var2->unk_24.y = (var2->unk_18.z * var2->unk_30.x) - (var2->unk_18.x * var2->unk_30.z);
            var2->unk_24.z = (var2->unk_18.x * var2->unk_30.y) - (var2->unk_18.y * var2->unk_30.x);
        } else {
            D_80112B2C--;
        }
    }

    for (var_s3 = D_80112FB4, var_s2 = (D_80112FB0 - 1), var_s2 %= ARRAY_COUNT(D_80112B30); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_80112B30), var_s3--) {
        var = &D_80112B30[var_s2];
        var->unk_1C = (var->unk_1C + 1) % 32;
        if (var->unk_1C != 0) {
            var->unk_18 *= 1.02f;
            var->unk_00.x += var->unk_0C.x;
            var->unk_00.y += var->unk_0C.y;
            var->unk_00.z += var->unk_0C.z;
        } else {
            D_80112FB4--;
        }
    }

    for (var_s3 = D_8011313C, var_s2 = (D_80113138 - 1), var_s2 %= ARRAY_COUNT(D_80112FB8); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_80112FB8), var_s3--) {
        var3 = &D_80112FB8[var_s2];
        var3->unk_04++;
        if (var3->unk_04 > 65) {
            var3->unk_04 = 0;
            D_8011313C--;
        }
        if (var3->unk_04 >= 53 && var3->unk_04 < 63) {
            Racer* racer = var3->unk_08;
            temp_fs2 = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 1.8f) - 0.9f;
            temp_fs0 = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 0.4f) + 0.4f;
            temp_fs1 = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 1.8f) - 0.9f;
            func_i2_801058FC(((s32) (Math_Rand1() % 16) - 8) + racer->unk_0C.unk_34.x,
                             ((s32) (Math_Rand1() % 16) - 8) + racer->unk_0C.unk_34.y,
                             ((s32) (Math_Rand1() % 16) - 8) + racer->unk_0C.unk_34.z,
                             racer->velocity.x + (temp_fs2 * racer->unk_C0.z.x) + (temp_fs0 * racer->unk_C0.y.x) +
                                 (temp_fs1 * racer->unk_C0.x.x),
                             racer->velocity.y + (temp_fs2 * racer->unk_C0.z.y) + (temp_fs0 * racer->unk_C0.y.y) +
                                 (temp_fs1 * racer->unk_C0.x.y),
                             racer->velocity.z + (temp_fs2 * racer->unk_C0.z.z) + (temp_fs0 * racer->unk_C0.y.z) +
                                 (temp_fs1 * racer->unk_C0.x.z),
                             30.0f, var3->unk_08);
        }
    }

    for (var_s3 = D_80115D44, var_s2 = (D_80115D40 - 1), var_s2 %= ARRAY_COUNT(D_80113140); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_80113140), var_s3--) {
        var4 = &D_80113140[var_s2];
        var4->unk_50 = (var4->unk_50 + 1) % 64;
        if (var4->unk_50 != 0) {
            var4->unk_24.x += 0xCC;

            temp_fv0 = SIN(var4->unk_24.x) * 1.5f;
            var4->unk_00.x += var4->unk_30.x + (temp_fv0 * var4->unk_3C.x);
            var4->unk_00.y += var4->unk_30.y + (temp_fv0 * var4->unk_3C.y);
            var4->unk_00.z += var4->unk_30.z + (temp_fv0 * var4->unk_3C.z);

            var4->unk_24.y += 0xCC;
            temp_fv0 = SIN(var4->unk_24.y) * 1.5f;
            var4->unk_0C.x += var4->unk_30.x + (temp_fv0 * var4->unk_3C.x);
            var4->unk_0C.y += var4->unk_30.y + (temp_fv0 * var4->unk_3C.y);
            var4->unk_0C.z += var4->unk_30.z + (temp_fv0 * var4->unk_3C.z);

            var4->unk_24.z += 0xCC;
            temp_fv0 = SIN(var4->unk_24.z) * 1.5f;
            var4->unk_18.x += var4->unk_30.x + (temp_fv0 * var4->unk_3C.x);
            var4->unk_18.y += var4->unk_30.y + (temp_fv0 * var4->unk_3C.y);
            var4->unk_18.z += var4->unk_30.z + (temp_fv0 * var4->unk_3C.z);

            var4->unk_30.x = (var4->unk_30.x * 0.98f) - (0.2f * var4->unk_54->unk_A8.x);
            var4->unk_30.y = (var4->unk_30.y * 0.98f) - (0.2f * var4->unk_54->unk_A8.y);
            var4->unk_30.z = (var4->unk_30.z * 0.98f) - (0.2f * var4->unk_54->unk_A8.z);
            var4->unk_4E = 255 - (s32) (SIN(var4->unk_24.x & 0x7FF) * 255.0f);
        } else {
            D_80115D44--;
        }
    }
}

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
