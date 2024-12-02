#include "global.h"

void func_80074A90(f32* arg0, f32* arg1) {
    f32 temp_fa0;
    f32 temp_fv1;

    temp_fa0 = SQ(*arg0) + SQ(*arg1);
    if (temp_fa0 < 1e-07) {
        return;
    }
    temp_fv1 = 1.0f / sqrtf(temp_fa0);
    *arg0 *= temp_fv1;
    *arg1 *= temp_fv1;
}

void func_80074B10(f32* arg0, f32* arg1, f32* arg2) {
    f32 temp_fa1;
    f32 temp_fv1;

    temp_fa1 = SQ(*arg0) + SQ(*arg1) + SQ(*arg2);
    if (temp_fa1 < 1e-07) {
        return;
    }
    temp_fv1 = 1.0f / sqrtf(temp_fa1);
    *arg0 *= temp_fv1;
    *arg1 *= temp_fv1;
    *arg2 *= temp_fv1;
}

s32 func_80074BB4(Vec3f* arg0, f32 arg1) {
    f32 temp_fa1;
    f32 temp_fv1;

    temp_fa1 = SQ(arg0->x) + SQ(arg0->y) + SQ(arg0->z);
    if (temp_fa1 < 1e-07) {
        return -1;
    }
    temp_fv1 = arg1 / sqrtf(temp_fa1);
    arg0->x *= temp_fv1;
    arg0->y *= temp_fv1;
    arg0->z *= temp_fv1;
    return 0;
}

extern unk_800F8510* D_800F8510;

Mtx3F* func_80074C60(Mtx3F* arg0) {
    f32 sp44;
    f32 sp40;
    unk_8006FC8C* temp_a0;
    Mtx3F sp18;

    temp_a0 = D_800F8510->unk_10;
    sp44 = func_8009E108(temp_a0, 0.0f, &sp40);
    func_8009E85C(temp_a0, 0.0f, &sp18, sp44);
    *arg0 = sp18;
    return arg0;
}

extern unk_8010B7B0 D_8010B7B0;

void func_80074CE4(unk_800F8510* arg0) {
    s32 pad[4];
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    Vec3f spD4;
    MtxF sp94;
    s32 i;
    unk_8006FC8C* var_s0;

    var_s0 = arg0->unk_10;
    for (i = 0; i < arg0->unk_08; i++) {
        func_8009E538(var_s0, 0.0f, &spD4);
        func_80074BB4(&spD4, 1);
        if ((SQ(spD4.x) + SQ(spD4.z)) != 0.0f) {
            spE8 = spD4.z;
            spE4 = 0.0f;
            spE0 = -1.0f * spD4.x;
        } else {
            spE8 = 0.0f;
            spE4 = 0.0f;
            spE0 = spD4.y;
        }

        func_80074B10(&spE8, &spE4, &spE0);
        spF4 = ((spE4 * spD4.z) - (spE0 * spD4.y)) * -1.0f;
        spF0 = ((spE0 * spD4.x) - (spE8 * spD4.z)) * -1.0f;
        spEC = ((spE8 * spD4.y) - (spE4 * spD4.x)) * -1.0f;
        func_80074B10(&spF4, &spF0, &spEC);
        func_8006C520(NULL, &sp94, 1.0f, (D_8010B7B0.unk_520[i] << 0xC) / 360, spD4.x, spD4.y, spD4.z, 0.0f, 0.0f,
                      0.0f);
        var_s0->unk_0C.x = sp94.m[0][0] * spF4 + sp94.m[1][0] * spF0 + sp94.m[2][0] * spEC;
        var_s0->unk_0C.y = sp94.m[0][1] * spF4 + sp94.m[1][1] * spF0 + sp94.m[2][1] * spEC;
        var_s0->unk_0C.z = sp94.m[0][2] * spF4 + sp94.m[1][2] * spF0 + sp94.m[2][2] * spEC;
        var_s0 = var_s0->unk_34;
    }
}

void func_800BB4E0(s32);

// Test Function?
void func_80074F98(void) {
    f32 sp2C;
    s64 temp;
    bcmp(NULL, NULL, 0);
    osEPiReadIo(NULL, 0, NULL);
    osEPiWriteIo(NULL, 0, 0);
    __osSetHWIntrRoutine(0, NULL);
    osStopThread(NULL);
    func_800BB4E0(0);
    osEPiLinkHandle(NULL);
    osPfsInitPak(NULL, NULL, 0);
    osPfsAllocateFile(NULL, 0, 0, NULL, NULL, 0, NULL);
    osPfsReadWriteFile(NULL, 0, 0, 0, 0, NULL);
    osPfsFindFile(NULL, 0, 0, NULL, NULL, NULL);
    sprintf(NULL, "\0\0\0\0\0\0\0");
    guOrtho(NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    temp = sp2C;
}
