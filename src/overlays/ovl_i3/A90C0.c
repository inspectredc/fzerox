#include "global.h"
#include "ovl_i3.h"
#include "fzx_racer.h"
#include "assets/segment_2B9EA0.h"

s32 D_80141900;
s32 D_i3_80141904;
s32 D_i3_80141908;
s32 D_i3_8014190C;
Racer* D_i3_80141910;
UNUSED s32 D_i3_80141914;
s32 D_i3_80141918;
s32 D_i3_8014191C;
s32 D_i3_80141920;
s32 D_i3_80141924;
s32 D_i3_80141928;
s32 D_i3_8014192C;
s32 D_i3_80141930;
s32 D_i3_80141934;
s32 D_i3_80141938;
s32 D_i3_8014193C;
s32 D_i3_80141940;
s32 D_i3_80141944;
s32 D_i3_80141948;
s32 D_i3_8014194C;
s32 D_i3_80141950;
s32 D_i3_80141954;
s32 D_i3_80141958;
s32 D_i3_8014195C;
s32 D_i3_80141960;
s32 D_i3_80141964;
s32 D_i3_80141968;
s32 D_i3_8014196C;
s32 D_i3_80141970;
s32 D_i3_80141974;
s32 D_i3_80141978;
s32 D_i3_8014197C;
s32 D_i3_80141980;
s32 D_i3_80141984;
s32 D_i3_80141988;
s32 D_i3_8014198C;
s32 D_i3_80141990;
s32 D_i3_80141994;
s32 D_i3_80141998;

void* D_i3_8013DB80[] = {
    D_F264110, D_F264340, D_F264450, D_F2641D8, D_F264690, D_F264540, D_F264920, D_F264860,
    D_F264740, D_F264C80, D_F264B40, D_F2652B0, D_F264DE0, D_F264F08, D_F2650B0, D_F2651C8,
    D_F264A58, D_F2656C8, D_F265530, D_F2659E0, D_F2658D0, D_F265B70, D_F2653E8, D_F265D08,
};

UNUSED Gfx D_i3_8013DBE0[] = { gsSPEndDisplayList() };

s16* D_i3_8013DBE8 = NULL;

s32 D_i3_8013DBEC = 0;

f32 D_i3_8013DBF0[] = { 0.99f, 0.98f, 0.96f, 0.94f, 0.0f };

f32 D_i3_8013DC04[] = { 0.99f, 0.98f, 0.96f, 0.94f, 0.0f };

f32 D_i3_8013DC18[] = {
    0.40f, 0.5f,  0.55f, 0.60f, 0.45f, 0.60f, 0.65f, 0.65f, 0.39f, 0.46f, 0.5f,  0.5f,  0.39f, 0.46f, 0.5f,  0.60f,
    0.41f, 0.5f,  0.5f,  0.55f, 0.38f, 0.44f, 0.5f,  0.60f, 0.39f, 0.42f, 0.5f,  0.55f, 0.41f, 0.55f, 0.60f, 1.0f,
    0.44f, 0.48f, 0.60f, 0.65f, 0.37f, 0.43f, 0.5f,  0.60f, 0.38f, 0.45f, 0.5f,  0.5f,  0.39f, 0.48f, 0.60f, 0.65f,
    0.45f, 0.5f,  0.60f, 1.0f,  0.38f, 0.5f,  0.55f, 0.60f, 0.40f, 0.45f, 0.5f,  0.70f, 0.36f, 0.37f, 0.45f, 0.5f,
    0.37f, 0.39f, 0.43f, 0.55f, 0.39f, 0.60f, 0.62f, 0.65f, 0.37f, 0.39f, 0.41f, 0.45f, 0.36f, 0.38f, 0.42f, 0.45f,
    0.38f, 0.39f, 0.42f, 0.55f, 0.38f, 0.40f, 0.43f, 0.60f, 0.36f, 0.38f, 0.5f,  0.55f, 0.40f, 0.5f,  1.0f,  1.0f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.37f, 0.38f, 0.40f, 0.41f, 0.37f, 0.38f, 0.40f, 0.41f, 0.37f, 0.38f, 0.40f, 0.41f, 0.37f, 0.38f, 0.40f, 0.41f,
    0.37f, 0.38f, 0.40f, 0.41f, 0.37f, 0.38f, 0.40f, 0.41f, 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
    1.0f,  1.0f
};

f32 D_i3_8013DFA0[] = {
    0.0f,  0.0f,  0.25f, 0.68f, 0.0f,  0.02f, 0.35f, 0.73f, 0.0f,  0.02f, 0.1f,  0.35f, 0.0f,  0.0f,  0.2f,  0.55f,
    0.0f,  0.2f,  0.75,  1.0f,  0.0f,  0.0f,  0.1f,  0.3f,  0.0f,  0.0f,  0.0f,  0.3f,  0.0f,  0.15f, 0.70f, 1.6f,
    0.0f,  0.0f,  0.2f,  0.75,  0.0f,  0.0f,  0.1f,  0.6f,  0.0f,  0.2f,  0.5f,  0.6f,  0.0f,  0.1f,  0.5f,  0.9f,
    0.0f,  0.3f,  1.0f,  1.6f,  0.0f,  0.2f,  0.35f, 0.8f,  0.0f,  0.05f, 0.15f, 0.53f, 0.0f,  0.1f,  0.1f,  0.6f,
    0.0f,  0.1f,  0.1f,  0.33f, 0.0f,  0.2f,  0.5f,  1.4f,  0.0f,  0.15f, 0.2f,  0.24f, 0.0f,  0.1f,  0.3f,  0.55f,
    0.0f,  0.1f,  0.1f,  0.45f, 0.0f,  0.1f,  0.3f,  0.8f,  0.0f,  0.1f,  0.3f,  0.62f, 0.0f,  0.3f,  0.6f,  1.2f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.0f,  0.1f,  0.2f,  0.25f, 0.0f,  0.1f,  0.2f,  0.25f, 0.0f,  0.1f,  0.2f,  0.25f, 0.0f,  0.1f,  0.2f,  0.25f,
    0.0f,  0.1f,  0.2f,  0.25f, 0.0f,  0.1f,  0.2f,  0.25f, 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    0.0f,  0.0f,
};

u32 D_i3_8013E328[] = {
    107000, 99000,  90000,  82000,  91000,  82000,  76000,  70500,  93000,  83000,  78000,  74000,  99000,  92000,
    86000,  81500,  110000, 104000, 98500,  92000,  108000, 102000, 98000,  92500,  96000,  91000,  85000,  79500,
    97000,  90000,  83000,  76000,  102000, 96000,  89000,  83000,  90000,  85000,  82000,  78500,  77000,  73000,
    68500,  64500,  110000, 105000, 101000, 96500,  97000,  92000,  87000,  82500,  109000, 104000, 99500,  95500,
    120000, 114000, 108500, 103500, 118000, 112000, 106500, 102000, 86000,  83000,  77000,  72000,  121000, 116000,
    109000, 101000, 155000, 148000, 141000, 134500, 91000,  86000,  82500,  79000,  137000, 130000, 125000, 120500,
    114000, 108000, 102500, 97500,  125000, 120000, 114000, 109000, 161000, 155000, 148500, 143000,
};

u32 D_i3_8013E4A8[] = {
    35000, 33000, 32000, 30000, 31000, 29000, 27500, 26300, 28000, 27000, 26200, 24500, 29000, 28000, 26500, 26000,
    35000, 33500, 32000, 31000, 34000, 33000, 32000, 31000, 31000, 29500, 29000, 28000, 30500, 29000, 27500, 27000,
    33000, 32000, 29500, 28000, 30000, 28500, 27000, 26000, 23000, 22500, 21700, 21000, 35500, 34500, 34000, 33000,
    30000, 29500, 28000, 27500, 35000, 34000, 33000, 31000, 38000, 37000, 36000, 35000, 37000, 36000, 34500, 33000,
    25500, 24500, 23500, 22000, 40000, 38000, 36000, 34000, 51000, 49000, 47000, 45500, 31000, 29000, 27500, 26000,
    44000, 42000, 40000, 39000, 35500, 34000, 32500, 31500, 40000, 39000, 38000, 37000, 51000, 49500, 48500, 47000,
};

u32 D_i3_8013E628[] = {
    350, 300, 250, 200, 400, 350, 270, 200, 400, 350, 300, 300, 600, 500, 350, 300, 450, 350, 300, 250,
    400, 300, 250, 200, 300, 280, 250, 230, 600, 500, 250, 150, 400, 350, 300, 250, 500, 350, 330, 300,
    500, 400, 300, 250, 500, 400, 350, 250, 600, 500, 300, 250, 600, 500, 450, 350, 400, 350, 300, 280,
    500, 500, 500, 500, 450, 400, 350, 350, 250, 240, 220, 200, 450, 400, 350, 300, 300, 290, 270, 250,
    500, 450, 350, 300, 550, 450, 300, 250, 600, 500, 400, 300, 550, 400, 350, 300,
};

unk_8013E7A8 D_i3_8013E7A8[] = {
    { 61, 4, { 15, 29, 255, 1, 2, 11, 26, 3, 255, 255, 255 } },
    { 63, 5, { 255, 255, 255, 15, 3, 11, 26, 2, 255, 255, 255 } },
    { 61, 3, { 255, 255, 255, 1, 15, 16, 11, 26, 14, 255, 255 } },
    { 61, 1, { 14, 255, 255, 15, 29, 0, 2, 255, 255, 255, 255 } },
    { 6, 3, { 8, 255, 255, 22, 19, 17, 7, 18, 255, 255, 255 } },
    { 7, 5, { 255, 255, 255, 6, 28, 23, 255, 255, 255, 255, 255 } },
    { 4, 1, { 255, 255, 255, 5, 12, 23, 24, 13, 28, 27, 255 } },
    { 4, 1, { 255, 255, 255, 4, 19, 10, 17, 255, 255, 255, 255 } },
    { 4, 2, { 4, 255, 255, 20, 7, 10, 9, 18, 255, 255, 255 } },
    { 6, 2, { 255, 255, 255, 18, 19, 20, 4, 8, 17, 255, 255 } },
    { 6, 3, { 255, 255, 255, 7, 19, 17, 255, 255, 255, 255, 255 } },
    { 6, 4, { 255, 255, 255, 1, 16, 29, 14, 255, 255, 255, 255 } },
    { 29, 4, { 255, 255, 255, 25, 27, 13, 24, 28, 5, 6, 255 } },
    { 5, 4, { 255, 255, 255, 27, 21, 5, 255, 255, 255, 255, 255 } },
    { 6, 4, { 3, 255, 255, 26, 11, 29, 16, 255, 255, 255, 255 } },
    { 61, 3, { 255, 255, 255, 0, 16, 2, 1, 255, 255, 255, 0 } },
    { 4, 0, { 255, 255, 255, 2, 15, 14, 255, 255, 255, 255, 255 } },
    { 29, 5, { 255, 255, 255, 10, 4, 20, 22, 9, 255, 255, 255 } },
    { 63, 1, { 22, 255, 255, 9, 20, 255, 255, 255, 255, 255, 255 } },
    { 7, 4, { 255, 255, 255, 22, 9, 10, 8, 7, 255, 255, 255 } },
    { 6, 1, { 255, 255, 255, 8, 18, 22, 10, 7, 17, 9, 255 } },
    { 6, 0, { 13, 27, 255, 24, 28, 25, 255, 255, 255, 255, 255 } },
    { 29, 0, { 18, 255, 255, 19, 8, 20, 4, 255, 255, 255, 255 } },
    { 4, 1, { 255, 255, 255, 25, 27, 6, 24, 255, 255, 255, 255 } },
    { 6, 5, { 255, 255, 255, 23, 13, 21, 25, 12, 6, 255, 255 } },
    { 36, 3, { 255, 255, 255, 28, 21, 23, 24, 255, 255, 255, 255 } },
    { 6, 2, { 255, 255, 255, 16, 14, 1, 29, 255, 255, 255, 255 } },
    { 4, 2, { 255, 255, 255, 13, 21, 12, 5, 255, 255, 255, 255 } },
    { 5, 3, { 255, 255, 255, 5, 25, 21, 23, 12, 6, 255, 255 } },
    { 5, 0, { 255, 255, 255, 0, 3, 26, 11, 255, 255, 255, 255 } },
};

// fabsf
f32 func_i3_80115DF0(f32 num) {
    if (num < 0.0f) {
        return 0.0f - num;
    }
    return num;
}

// abs
s32 func_i3_80115E1C(s32 num) {
    if (num < 0) {
        return -num;
    }
    return num;
}

void func_i3_80115E34(Racer* arg0) {

    arg0->unk_34D = (arg0->unk_00 % 5) + 2;
    if ((arg0->unk_00 < 0xF) && (arg0->unk_34D == 2)) {
        arg0->unk_34D = 1;
    }
}

s16 D_i3_8013E94C[] = {
    0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000,
};

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i3/A90C0/func_i3_80115E74.s")

extern s32 gDifficulty;
extern unk_800F8510* D_800F8510;
extern s32 D_800F8514;

void func_i3_80116974(void) {
    s32 sp1C[19];

    if (D_800F8514 < 0x18) {
        if (func_i2_801037CC(&sp1C, D_800F8514) == 0) {
            D_i3_80141990 = D_i3_8013E328[D_800F8514 * 4 + gDifficulty];
        } else {
            D_i3_80141990 = MAX_TIMER;
        }
        if (gDifficulty >= EXPERT) {
            if (D_800F8510->unk_20[0] < sp1C[2]) {
                D_i3_80141990 = D_800F8510->unk_20[0] + (D_i3_80141990 - sp1C[2]);
            }
        }
    } else {
        D_i3_80141990 = MAX_TIMER;
    }
    D_i3_80141994 = D_i3_80141990;
}

extern s32 gNumPlayers;
extern s32 D_800CD00C;
extern s32 D_800E5EC0;

f32 D_i3_8013E9E0[] = { 5000.0f, 2000.0f, 1000.0f, 1000.0f };

s32 D_i3_8013E9F0[] = {
    0,     860,   1780,  2760,  3800,  4900,  6060,  7280,  8560,  9900,  11300, 12760, 14280, 15860, 17500,
    19200, 20960, 22780, 24660, 26600, 28600, 30660, 32780, 34960, 37200, 39500, 41860, 44280, 46760, 49300,
    0,     680,   1440,  2280,  3200,  4200,  5280,  6440,  7680,  9000,  10400, 11880, 13440, 15080, 16800,
    18600, 20480, 22440, 24480, 26600, 28800, 31080, 33440, 35880, 38400, 41000, 43680, 46440, 49280, 52200,
    0,     560,   1180,  1860,  2600,  3400,  4260,  5180,  6160,  7200,  8300,  9460,  10680, 11960, 13300,
    14700, 16160, 17680, 19260, 20900, 22600, 24360, 26180, 28060, 30000, 32000, 34060, 36180, 38360, 40600,
    0,     560,   1180,  1860,  2600,  3400,  4260,  5180,  6160,  7200,  8300,  9460,  10680, 11960, 13300,
    14700, 16160, 17680, 19260, 20900, 22600, 24360, 26180, 28060, 30000, 32000, 34060, 36180, 38360, 40600,
};

void func_i3_80116A50(Racer* arg0) {
    s32 var_s3;
    s32 i;
    Racer* var_s0;
    f32 temp_ft3;
    f32 temp_fv0;
    f32 var_fs0;

    temp_ft3 = D_800F8510->unk_0C * D_800CD00C;

    if (D_800E5EC0 < arg0->unk_368) {
        for (i = gNumPlayers, var_fs0 = temp_ft3, var_s3 = 0; i < D_800E5EC0; i++) {
            var_s0 = &gRacers[i];
            if ((D_800E5EC0 >= var_s0->unk_368) && (arg0->unk_00 != var_s0->unk_00)) {
                temp_fv0 = func_i3_80115DF0(arg0->unk_23C - var_s0->unk_23C);
                if (temp_fv0 < var_fs0) {
                    var_fs0 = temp_fv0;
                    var_s3 = i;
                }
            }
        }
        arg0->unk_368 = gRacers[var_s3].unk_368;
        if (D_800E5EC0 < arg0->unk_368) {
            arg0->unk_368 = 1;
        }
        func_i3_801175A4();
    }

    arg0->unk_398 = D_i3_80141990 - ((temp_ft3 - arg0->unk_23C) / temp_ft3) * D_i3_8013E9E0[gDifficulty] +
                    D_i3_8013E9F0[arg0->unk_368 + gDifficulty * 30 - 1];
}

void func_i3_80116C4C(void) {
    D_i3_8013DBE8 = func_800768F4(0, 0x400);
}

f32 D_i3_8013EBD0[] = {
    0.0f, 0.0f, 0.04f, 0.08f, 0.0f, 0.0f, 0.03f, 0.05f, 0.0f, 0.0f, 0.0f, 0.02f,
    0.0f, 0.0f, 0.05f, 0.09f, 0.0f, 0.0f, 0.02f, 0.03f, 0.0f, 0.0f, 0.0f, 0.0f,
};

f32 D_i3_8013EC30[] = {
    0.0f, 0.0f, 0.02f, 0.01f, 0.0f, 0.0f, 0.02f, 0.01f,  0.0f, 0.0f, 0.03f, 0.03f,
    0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.01f, 0.005f, 0.0f, 0.0f, 0.0f,  0.0f,
};

extern s32 D_800CD004;
extern s32 D_800DCE44;

void func_i3_80116C74(Racer* arg0) {
    f32 var_fa0;
    s32 padC0[7];
    s32 sp48[30];
    s32 pad[3];
    s32 i;
    s32 j;

    D_i3_80141910 = gRacers;
    D_80141900 = 0;
    if (arg0->unk_00 == 0) {
        func_i3_80116974();
        if (D_800F8514 < ARRAY_COUNT(D_i3_8013DB80)) {
            func_80077CF0(D_i3_8013DB80[D_800F8514], 0x400, D_i3_8013DBE8);
        } else {
            for (i = 0; i < 0x200; i += 2) {
                D_i3_8013DBE8[i + 0] = 0x45;
                D_i3_8013DBE8[i + 1] = 0;
            }
        }

        if (D_800DCE44 == 6) {
            arg0->unk_1A8 = 0.5f;
        }

        if ((D_800CD004 == 4) || (D_800CD004 == 5)) {
            D_i3_80141904 = 0;
        } else {
            D_i3_80141904 = 1;
        }

        for (i = 0; i < 30; i++) {
            sp48[i] = 0xFF;
            for (j = 0; j < D_800E5EC0; j++) {
                if (gRacers[j].character == i) {
                    sp48[i] = j;
                    break;
                }
            }
        }

        D_i3_80141918 = sp48[0];
        D_i3_8014191C = sp48[1];
        D_i3_80141920 = sp48[2];
        D_i3_80141924 = sp48[3];
        D_i3_80141928 = sp48[4];
        D_i3_8014192C = sp48[5];
        D_i3_80141930 = sp48[6];
        D_i3_80141934 = sp48[7];
        D_i3_80141938 = sp48[8];
        D_i3_8014193C = sp48[9];
        D_i3_80141940 = sp48[10];
        D_i3_80141944 = sp48[11];
        D_i3_80141948 = sp48[12];
        D_i3_8014194C = sp48[13];
        D_i3_80141950 = sp48[14];
        D_i3_80141954 = sp48[15];
        D_i3_80141958 = sp48[16];
        D_i3_8014195C = sp48[17];
        D_i3_80141960 = sp48[18];
        D_i3_80141964 = sp48[19];
        D_i3_80141968 = sp48[20];
        D_i3_8014196C = sp48[21];
        D_i3_80141970 = sp48[22];
        D_i3_80141974 = sp48[23];
        D_i3_80141978 = sp48[24];
        D_i3_8014197C = sp48[25];
        D_i3_80141980 = sp48[26];
        D_i3_80141984 = sp48[27];
        D_i3_80141988 = sp48[28];
        D_i3_8014198C = sp48[29];
    }

    arg0->unk_358 = 0xFFFF;
    arg0->unk_330 = 0.01f;
    arg0->unk_334 = Math_Rand1() % 32768 / 32767.0f * 20.0f + 350.0f;
    arg0->unk_338 = Math_Rand2() % 32768 / 32767.0f * 0.01f + 0.3f;
    arg0->unk_354 = Math_Rand1() % 32768 / 32767.0f + 5.0f;
    arg0->unk_340 = Math_Rand1() % 8 + 15;
    arg0->unk_3A4 = 0;
    arg0->unk_39C = 0;
    arg0->unk_398 = 0;
    arg0->unk_394 = 0;
    arg0->unk_390 = 0;
    arg0->unk_36C = 0;
    arg0->unk_384 = 0;
    arg0->unk_1E8 = 0.0f;
    arg0->unk_364 = 0.0f;
    arg0->unk_360 = 0.0f;
    arg0->unk_38C = 0.0f;
    arg0->unk_3A0 = D_800E5EC0;
    arg0->unk_1EC = 2500.0f / 27.0f;

    if (D_800DCE44 == 1) {
        arg0->unk_360 = D_i3_8013EBD0[D_i3_8013E7A8[arg0->character].unk_02 * 4 + gDifficulty];
        arg0->unk_364 = D_i3_8013EC30[D_i3_8013E7A8[arg0->character].unk_02 * 4 + gDifficulty] + arg0->unk_360;
    }

    arg0->unk_370 = 0;
    arg0->unk_33C = ((arg0->unk_24C.z.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.z.y * arg0->unk_0C.unk_28.y) +
                     (arg0->unk_24C.z.z * arg0->unk_0C.unk_28.z)) *
                    -1.0f;
    arg0->unk_340 = Math_Rand2() % 2 + 1;

    arg0->unk_36C = D_i3_8013E7A8[arg0->character].unk_00;

    if (D_i3_8013E7A8[arg0->character].unk_02 < 2) {
        arg0->unk_36C |= 0x200;
    }

    arg0->unk_380 = 0;
    arg0->unk_37C = 0;
    arg0->unk_378 = 0;
    arg0->unk_374 = 0;

    if (D_800DCE44 == 0x11) {
        arg0->unk_1A8 = func_8008960C(0.1f);
        arg0->unk_1EC = 2500.0f / 27.0f;
        arg0->unk_1E8 = 0.0f;
        arg0->unk_330 = 0.01f;
        arg0->unk_334 = Math_Rand1() % 32768 / 32767.0f * 20.0f + 500.0f;
    }

    if (arg0->unk_00 >= gNumPlayers) {
        if (D_800F8514 < 0x18) {
            if (D_800E5EC0 >= arg0->unk_368) {
                arg0->unk_39C = D_i3_8013E4A8[D_800F8514 * 4 + gDifficulty] +
                                D_i3_8013E628[D_800F8514 * 4 + gDifficulty] * (arg0->unk_368 - 1);
            }
        }
        if ((D_i3_80141910->unk_2AC == arg0->unk_2AC - 4) || (D_i3_80141910->unk_2AC == (arg0->unk_2AC + 4)) ||
            (gNumPlayers >= 2)) {
            var_fa0 = D_i3_80141910->unk_1A8;
            if (var_fa0 > 0.95f) {
                var_fa0 = 0.95f;
            }
            if (var_fa0 < 0.0f) {
                var_fa0 = 0.0f;
            }
            arg0->unk_1A8 = var_fa0;
        } else if ((gDifficulty == MASTER) && (D_i3_8013E94C[D_800F8514] != 0)) {
            var_fa0 = (Math_Rand1() % 256 / 255.0f + 10.0f) / 14.0f;
            if (var_fa0 > 0.95f) {
                var_fa0 = 0.95f;
            }
            if (var_fa0 < 0.0f) {
                var_fa0 = 0.0f;
            }
            arg0->unk_1A8 = func_8008960C(var_fa0);
        } else {
            var_fa0 = D_i3_80141910->unk_1A8;
            var_fa0 += Math_Rand2() % 32768 / 32767.0f * 0.2f - 0.1f;
            if (var_fa0 > 0.95f) {
                var_fa0 = 0.95f;
            }
            if (var_fa0 < 0.0f) {
                var_fa0 = 0.0f;
            }
            arg0->unk_1A8 = var_fa0;
        }
        if (D_800F8514 == 0xC) {
            if (arg0->unk_1A8 > 0.8f) {
                arg0->unk_1A8 = 0.8f;
            }
            if (arg0->unk_1A8 < 0.6f) {
                arg0->unk_1A8 = 0.6f;
            }
        }
        if (D_800DCE44 == 0x15) {
            arg0->unk_1A8 = (Math_Rand1() % 256 / 255.0f) * 0.2f;
        }
        arg0->unk_1EC = 2500.0f / 27.0f;
        arg0->unk_1E8 = 0.0f;
    }
}

extern s32 D_800CD00C;
extern s16 D_80115DE0;
extern Racer* D_800E5F40[];

void func_i3_801175A4(void) {
    f32 temp_fv0;
    s32 temp_a1;
    s32 var_t0;
    s32 var_a3;
    s32 i;
    s32 temp1;
    s16 sp54[30];
    s32 temp2;
    s32 temp_v0;
    s32 temp_t3;
    s32 var_v0_2;

    D_i3_80141910 = gRacers;

    temp_fv0 = D_800F8510->unk_0C * D_800CD00C;
    if ((D_800E5F40[0]->unk_2A8 == 2) && (D_i3_80141904 == 0)) {
        var_a3 = 0;
        var_t0 = 0;
        for (i = 0; i < D_800E5EC0; i++) {
            if (gRacers[i].unk_2A8 >= 2) {
                var_t0++;
                var_a3 += gRacers[i].unk_290[0];
            }
        }

        if (var_t0 != 0) {
            if (D_800CD004 == 5) {
                var_v0_2 = D_i3_8013DC04[gDifficulty] * ((f32) (s32) ((f32) var_a3 / var_t0) * D_800CD00C);
            } else {
                var_v0_2 = D_i3_8013DBF0[gDifficulty] * ((f32) (s32) ((f32) var_a3 / var_t0) * D_800CD00C);
            }
            if (var_v0_2 < D_i3_80141994) {
                D_i3_80141990 = var_v0_2;
                D_i3_80141994 = D_i3_80141990;
            }
            if (var_t0 >= D_80115DE0) {
                D_i3_80141904 = 1;
            }
        }
    }
    if ((D_i3_80141910->unk_2AC == 1) && (D_i3_80141910->unk_2A8 >= 2)) {
        for (i = 0; i < D_800E5EC0; i++) {
            if (D_800E5F40[i]->unk_368 < D_800E5EC0) {
                break;
            }
        }

        if (i < ((D_800E5EC0 * 2) / 3)) {
            if ((D_i3_80141910->unk_23C - D_800E5F40[i]->unk_23C) > 3000.0f) {
                temp_a1 = ((temp_fv0 - D_i3_80141910->unk_23C) / temp_fv0) * 1000.0f;
                temp_a1 += 1000;
                temp2 = ((D_i3_80141910->unk_2A0 / D_i3_80141910->unk_23C) * temp_fv0) + temp_a1;
                if (temp2 < D_i3_80141994) {
                    D_i3_80141990 = temp2;
                }
            }
        }
    }

    for (i = 0; i < D_800E5EC0; i++) {
        sp54[i] = i;
    }

    for (i = 0; i < D_800E5EC0 - 1; i++) {
        for (temp_a1 = i + 1; temp_a1 < D_800E5EC0; temp_a1++) {
            if ((gRacers[sp54[i]].unk_368 > gRacers[sp54[temp_a1]].unk_368) ||
                ((gRacers[sp54[i]].unk_368 == gRacers[sp54[temp_a1]].unk_368) &&
                 (gRacers[sp54[i]].unk_23C < gRacers[sp54[temp_a1]].unk_23C))) {
                temp_t3 = sp54[i];
                sp54[i] = sp54[temp_a1];
                sp54[temp_a1] = temp_t3;
            }
        }
    }

    for (i = 0; i < D_800E5EC0; i++) {
        if (gRacers[sp54[i]].unk_368 <= D_800E5EC0) {
            gRacers[sp54[i]].unk_368 = i + 1;
        }
    }
}

f32 func_i3_801179DC(Racer* arg0) {
    return D_i3_8013DC18[D_800F8514 * 4 + gDifficulty] * (2500.0f / 27.0f);
}

f32 func_i3_80117A1C(Racer* arg0) {
    return D_i3_8013DFA0[D_800F8514 * 4 + gDifficulty];
}

void func_i3_80117A4C(Racer* arg0, s32 arg1) {
    Racer* temp_v0 = &gRacers[arg1];

    if ((arg0->unk_368 < D_800E5EC0) && (arg1 < D_800E5EC0)) {
        if (temp_v0->unk_368 < D_800E5EC0) {
            arg0->unk_368 = temp_v0->unk_368;
            arg0->unk_398 = temp_v0->unk_398;

            if (temp_v0->unk_33C < arg0->unk_33C) {
                arg0->unk_33C = temp_v0->unk_33C + 92.0f;
            } else {
                arg0->unk_33C = temp_v0->unk_33C - 92.0f;
            }
            arg0->unk_352 = 255;
        }
    }
}

void func_i3_80117B04(Racer* arg0, Controller* arg1) {
}

void func_i3_80117B10(Racer* arg0, Controller* arg1) {
    func_i3_80117A4C(arg0, D_i3_80141960);
}

void func_i3_80117B38(Racer* arg0, Controller* arg1) {
    func_i3_80117A4C(arg0, D_i3_80141944);
}

void func_i3_80117B60(Racer* arg0, Controller* arg1) {
    func_i3_80117A4C(arg0, D_i3_80141940);
}

void func_i3_80117B88(Racer* arg0, Controller* arg1) {
    if ((arg0->unk_2B4 != 0) && (D_i3_80141910->unk_23C < arg0->unk_23C) && (arg0->unk_04 & 0x04000000)) {
        arg1->unk_7C |= 0x80;
    }
}

void func_i3_80117BD8(Racer* arg0, Controller* arg1) {
}

void func_i3_80117BE4(Racer* arg0, Controller* arg1) {
}

void (*D_i3_8013EC90[])(Racer*, Controller*) = {
    func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04,
    func_i3_80117BE4, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04,
    func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117BD8, func_i3_80117B04,
    func_i3_80117B04, func_i3_80117B10, func_i3_80117B60, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04,
    func_i3_80117B04, func_i3_80117B04, func_i3_80117B38, func_i3_80117B88, func_i3_80117B04, func_i3_80117B04,
};

UNUSED f32 D_i3_8013ED08[] = { 0.05f, 3.5f };

f32 D_i3_8013ED10[] = { 0.0f, 138.0f, 138.0f };

f32 D_i3_8013ED1C[] = { 0.0f, 2.0f, -2.0f };

extern u32 gGameFrameCount;
extern s32 D_800CD00C;
extern s8 D_800CD010;
extern s32 D_800F80A8[];
extern unk_8010B7B0 D_8010B7B0;

#ifdef NON_MATCHING
// regalloc (0.0f vs 0.f vs 0?) and missing branch instruction
void func_i3_80117BF0(Racer* arg0, Controller* arg1) {
    f32 spBC;
    s32 temps;
    f32 spB4;
    s32 i;
    s32 pad;
    f32 temp_fa1;
    f32 temp_fv1;
    f32 var_fv0;
    f32 sp9C;
    s32 var_a1;
    f32 sp94;
    f32 temp4;
    f32 temp5;
    f32 temp6;
    s32 var_a3; // sp84
    f32 temp1;
    s32 sp7C;
    f32 temp2;
    bool sp74;
    bool sp70;
    Mtx3F sp4C;
    f32 temp3;
    Racer* sp44;
    Racer* sp40;

    if ((arg0->unk_00 & 3) != (gGameFrameCount % 4) && (D_800DCE44 != 0x11)) {
        arg1->unk_7E = 0;
        arg1->stickX = arg0->unk_374;
        arg1->stickY = arg0->unk_378;
        arg1->unk_7C = 0;
        arg1->unk_7A = arg0->unk_380;
        return;
    }
    arg1->unk_7A = arg1->unk_7C = arg1->unk_7E = 0;
    if (arg0->unk_2B4 != 0) {
        sp70 = true;
    } else {
        sp70 = false;
    }
    sp44 = arg0->unk_2B8;
    sp40 = arg0->unk_2BC;
    sp94 = ((-arg0->unk_0C.unk_28.x * arg0->unk_24C.z.x) - (arg0->unk_0C.unk_28.y * arg0->unk_24C.z.y)) -
           (arg0->unk_0C.unk_28.z * arg0->unk_24C.z.z);
    if (arg0->unk_1F8 < 2.0f) {
        arg0->unk_1F8 = 10.0f;
        arg0->unk_1E0 = 0.108f;
        arg0->unk_1E4 = 0.06f;
        if (arg0->unk_00 >= gNumPlayers) {
            arg0->unk_1AC = 0.f;
        }
    }
    if ((D_800DCE44 == 3) || (D_800DCE44 == 4)) {
        if (arg0->unk_00 >= gNumPlayers) {
            if (gNumPlayers == 3) {
                var_a1 = 0x1E;
                for (i = 0; i < gNumPlayers; i++) {
                    if (gRacers[i].unk_2AC < var_a1) {
                        var_a1 = gRacers[i].unk_2AC;
                        var_a3 = i;
                    }
                }
            } else if (arg0->unk_00 == 2) {
                var_a3 = 0;
            } else {
                var_a3 = 1;
            }

            temp_fv1 = (gRacers[var_a3].unk_23C + arg0->unk_38C) - arg0->unk_23C;
            if (temp_fv1 > 0) {
                arg0->unk_1EC = 69.44444f;
                arg0->unk_1E8 = temp_fv1 * 0.0003f;
                if (arg0->unk_1E8 > 1.0f) {
                    arg0->unk_1E8 = 1.0f;
                }
            } else {
                arg0->unk_1EC = gRacers[var_a3].unk_98 - (temp_fv1 * 0.0002f);
                if ((D_800CD00C == arg0->unk_2A8) &&
                    (((s32) (D_800F8510->unk_08 * 2) / 3) < arg0->unk_0C.unk_00->unk_30)) {
                    arg0->unk_1EC = gRacers[var_a3].unk_98 - (temp_fv1 * 0.002f);
                }
                arg0->unk_1E8 = 0.f;
            }
            if ((D_800CD00C == arg0->unk_2A8) && (((s32) (D_800F8510->unk_08 * 2) / 3) < arg0->unk_0C.unk_00->unk_30)) {
                arg0->unk_1E8 = 0.f;
            }
            arg0->unk_38C = 0.0f;
        }
    }
    if (D_i3_80141998 != 0) {
        if (D_800DCE44 == 2) {
            arg0->unk_1EC = func_i3_801179DC(arg0);
            arg0->unk_1E8 = func_i3_80117A1C(arg0);
        }
    } else if (((gNumPlayers == 1) && (D_i3_80141910->unk_04 & 0x02000000)) || (arg0->unk_04 & 0x02000000) ||
               (arg0->unk_00 < gNumPlayers)) {
        arg0->unk_1E8 = 0.f;
        arg0->unk_1EC = (2500.0f / 27.0f);
        arg0->unk_1B4 = 1.00894f;
        arg0->unk_1B0 = 1.156336f;
        arg0->unk_1B8 = 0.119168f;
        arg0->unk_1BC = 36.769516f;
        arg0->unk_1C4 = 1.726068f;
        arg0->unk_1D0 = 0.198282f;
        if ((gNumPlayers == 1) && (D_800E5EC0 != 1) && (arg0->unk_00 != 0) && (D_i3_80141910->unk_04 & 0x02000000)) {
            if ((sp44->unk_00 == 0) && (arg0->unk_2C0 < 2000.0f)) {
                arg0->unk_1EC = (625.0f / 27.0f);
            } else if ((sp40->unk_00 == 0) && (arg0->unk_2C4 < 2000.0f)) {
                arg0->unk_1E8 = 1.0f;
                arg1->unk_7C |= 0x4000;
            }
        }
    } else if ((arg0->unk_274 + arg0->unk_270) < 184.0f) {
        arg0->unk_1E8 = 0.f;
        arg0->unk_1EC = (2500.0f / 27.0f);
    } else if (gNumPlayers == 1) {
        if (arg0->unk_352 != 0xFF) {
            spBC = (gRacers[arg0->unk_352].unk_23C + arg0->unk_38C) - arg0->unk_23C;
            func_i3_80115DF0(D_i3_80141910->unk_23C - arg0->unk_23C);
            if ((func_i3_80115DF0(spBC) < 460.0f) && sp70 && (arg0->unk_2A0 > 1000)) {
                if ((arg0->unk_352 >= gNumPlayers) && ((arg0->unk_00 + gGameFrameCount) % 16) < 4) {
                    spB4 = ((-gRacers[arg0->unk_352].unk_0C.unk_28.x * gRacers[arg0->unk_352].unk_24C.z.x) -
                            (gRacers[arg0->unk_352].unk_0C.unk_28.y * gRacers[arg0->unk_352].unk_24C.z.y)) -
                           (gRacers[arg0->unk_352].unk_0C.unk_28.z * gRacers[arg0->unk_352].unk_24C.z.z);
                    if (Math_Rand2() % 2) {
                        arg0->unk_33C = spB4 + 23.0f;
                    } else {
                        arg0->unk_33C = spB4 - 23.0f;
                    }
                }
            }
            if (spBC < 2000.0f) {
                arg0->unk_1EC = gRacers[arg0->unk_352].unk_98 + (spBC * 0.01f);
            } else {
                arg0->unk_1EC = (625.0f / 9.0f);
            }
            arg0->unk_1E8 = 1.2f;
            if (sp70 && (arg0->unk_2A0 > 1000) && ((arg0->unk_274 + arg0->unk_270) > 138.0f) &&
                (func_i3_80115DF0(gRacers[arg0->unk_352].unk_23C - arg0->unk_23C) < 184.0f)) {
                spB4 = ((f32) (Math_Rand1() % 32768) / 32767.0f) + 0.00001f;

                if (func_i3_80115DF0(gRacers[arg0->unk_352].unk_33C - arg0->unk_33C) < 92.0f) {
                    if (((arg0->unk_352 != 0) && (spB4 < 0.15f) && (arg0->unk_36C & 0x200)) || (spB4 < arg0->unk_360)) {
                        if (arg0->unk_390 == 0) {
                            if (arg0->unk_33C < gRacers[arg0->unk_352].unk_33C) {
                                arg0->unk_390 = 5;
                            } else {
                                arg0->unk_390 = -5;
                            }
                        }
                    } else if ((((arg0->unk_352 != 0) && (spB4 < 0.2f) && (arg0->unk_36C & 0x200)) ||
                                (spB4 < arg0->unk_364)) &&
                               (((gDifficulty >= EXPERT) && (D_i3_80141910->unk_23C < arg0->unk_23C)) ||
                                ((D_i3_80141910->unk_23C + 138.0f) < arg0->unk_23C))) {
                        if (Math_Rand2() % 2) {
                            arg1->unk_7C |= 0x80;
                        } else {
                            arg1->unk_7C |= 0x40;
                        }
                    }
                }
            }
            if (arg0->unk_2A8 == 1) {
                var_fv0 = func_i3_801179DC(arg0);
                if (var_fv0 < arg0->unk_1EC) {
                    arg0->unk_1EC = var_fv0;
                }
                var_fv0 = func_i3_80117A1C(arg0);
                if (var_fv0 < arg0->unk_1E8) {
                    arg0->unk_1E8 = var_fv0;
                }
            }
            if ((u32) (u8) (arg0->unk_00 + gGameFrameCount) < 4) {
                if (arg0->unk_352 < gNumPlayers) {
                    arg0->unk_38C =
                        ((Math_Rand2() % 32768 / 32767.0f * 400.0f + 30.0f) + 200.0f) - (80 * -gDifficulty + 240);
                } else {
                    arg0->unk_38C = 30.0f;
                }
            }

            if (((D_800CD00C == arg0->unk_2A8) &&
                 (((s32) (D_800F8510->unk_08 * 2) / 3) < arg0->unk_0C.unk_00->unk_30)) ||
                ((gRacers[arg0->unk_352].unk_368 == 0xFE) && (D_800DCE44 != 2) && (D_800DCE44 != 0x15))) {
                arg0->unk_352 = 255;
                if (arg0->unk_2A8 >= 2) {
                    func_i3_80116A50(arg0);
                }
            }
        } else if ((arg0->unk_2A8 >= 2) || (D_800CD010 == 1)) {
            if ((arg0->unk_398 == 0) || ((u32) (arg0->unk_00 + gGameFrameCount) % 64) < 4) {
                func_i3_80116A50(arg0);
            }

            var_fv0 = (D_800F8510->unk_0C * (D_800CD00C - 1)) / (arg0->unk_398 - arg0->unk_290[0]);
            spBC = (((arg0->unk_2A0 - arg0->unk_290[0]) * var_fv0) + D_800F8510->unk_0C) - arg0->unk_23C;
            spB4 = ((((arg0->unk_2A0 - arg0->unk_290[0]) - 0x11) * var_fv0) + D_800F8510->unk_0C) - arg0->unk_23C;

            var_fv0 = func_i3_80115DF0(D_i3_80141910->unk_23C - arg0->unk_23C);
            arg0->unk_1EC = (spBC * 0.05f) + (spBC - spB4);
            arg0->unk_1E8 = 0.3f;
            if (spBC > 0.0f) {
                if (spBC > 200.0f) {
                    arg0->unk_1E8 = 0.0f;
                    arg1->unk_7C |= 0x4000;
                    if (spBC > 1000.0f) {
                        arg0->unk_1EC = (2500.0f / 27.0f);
                    }
                }
            } else if ((var_fv0 < 2000.0f) && (D_800CD00C == arg0->unk_2A8) &&
                       (((s32) (D_800F8510->unk_08 * 2) / 3) < arg0->unk_0C.unk_00->unk_30)) {
                spBC = D_i3_80141910->unk_98 - 2.3148148f;
                if ((var_fv0 < 0.0f) && (arg0->unk_1EC < spBC)) {
                    arg0->unk_1EC = spBC;
                }
            }
        } else {
            if (arg0->unk_39C != 0) {
                spBC = (arg0->unk_2A0 * (D_800F8510->unk_0C / arg0->unk_39C)) - arg0->unk_23C;
                temp_fa1 = ((arg0->unk_2A0 - 0x11) * (D_800F8510->unk_0C / arg0->unk_39C)) - arg0->unk_23C;
                if (arg0->unk_23C > 0.0f) {
                    arg0->unk_1EC = (spBC * 0.05f) + (spBC - temp_fa1);
                    arg0->unk_1E8 = 1.0f;
                } else {
                    arg0->unk_1EC = (2500.0f / 27.0f);
                    arg0->unk_1E8 = 0.0f;
                }
            } else {
                arg0->unk_1EC = func_i3_801179DC(arg0);
                arg0->unk_1E8 = func_i3_80117A1C(arg0);
            }
        }
    }
    var_a3 = arg0->unk_0C.unk_00->unk_30 * 4;
    if (arg0->unk_0C.unk_08 >= 0.5f) {
        var_a3 += 2;
    }

    if (D_i3_8013DBE8[var_a3] < arg0->unk_1EC) {
        arg0->unk_1EC = D_i3_8013DBE8[var_a3];
    }
    if (((D_80141900 >= 0x15) || (D_800F80A8[0] >= 0x1F)) && (gNumPlayers == 1) && (arg0->unk_00 != 0) &&
        (arg0->unk_2A0 >= 0x2711) && !(D_i3_80141910->unk_04 & 0x08000000) &&
        (func_i3_80115DF0(D_i3_80141910->unk_33C - sp94) < 138.0f)) {

        var_fv0 = D_i3_80141910->unk_23C - arg0->unk_23C;
        while (var_fv0 > D_800F8510->unk_0C * 0.5f) {
            var_fv0 -= D_800F8510->unk_0C;
        }

        while (var_fv0 < D_800F8510->unk_0C * -0.5f) {
            var_fv0 += D_800F8510->unk_0C;
        }

        if (var_fv0 < 0) {
            var_fv0 = 0.0f - var_fv0;
        }
        if (var_fv0 < 500.0f) {
            if (Math_Rand1() % 2) {
                arg1->unk_7C |= 0x80;
            } else {
                arg1->unk_7C |= 0x40;
            }
        }
    }
    if (D_800F8514 == 0xC) {
        sp7C = arg0->unk_0C.unk_00->unk_30;
        if ((sp7C >= 4) && (sp7C < 0x10)) {
            arg0->unk_1EC = (2500.0f / 27.0f);
            arg0->unk_1E8 = 1.0f;
        }
    }
    arg1->unk_7A |= 0x8000;
    if (arg0->unk_340 < arg0->unk_20C) {
        arg1->unk_7C |= 0x8000;
    }

    sp74 = false;
    if ((arg0->unk_0C.unk_00->unk_20 & 0x1C0) == 0x80) {
        if ((arg0->unk_0C.unk_00->unk_34->unk_34->unk_34->unk_20 & 0x1C0) != 0x80) {
            sp74 = true;
            arg0->unk_330 = 10.0f;
        } else if ((arg0->unk_0C.unk_00->unk_34->unk_34->unk_20 & 0x1C0) != 0x80) {
            sp74 = true;
            arg0->unk_330 = 10.0f;
        } else if ((arg0->unk_0C.unk_00->unk_34->unk_20 & 0x1C0) != 0x80) {
            sp74 = true;
            arg0->unk_330 = 10.0f;
        }
    }

    if (func_8009D16C(&arg0->unk_0C, arg0->unk_0C.unk_34.x + (arg0->unk_330 * arg0->unk_74.x),
                      arg0->unk_0C.unk_34.y + (arg0->unk_330 * arg0->unk_74.y),
                      arg0->unk_0C.unk_34.z + (arg0->unk_330 * arg0->unk_74.z), &sp4C) == 0) {
        if (((arg0->unk_0C.unk_00->unk_20 & 0x1C0) != 0x80) && ((arg0->unk_0C.unk_00->unk_20 & 0x1C0) != 0xC0)) {
            temp4 = arg0->unk_C0.x.x;
            temp5 = arg0->unk_C0.x.y;
            temp6 = arg0->unk_C0.x.z;
            if (D_800DCE44 == 0x11) {
                arg0->unk_33C = D_i3_8013ED1C[arg0->unk_00] * 46.0f;
                if (arg0->unk_00 != 0) {
                    temp3 = ((gRacers[0].unk_23C - D_i3_8013ED10[arg0->unk_00]) - arg0->unk_23C);
                    arg0->unk_1EC = gRacers[0].unk_98 + (temp3 * 0.1f);
                    arg0->unk_1E8 = 1.0f;
                }
            }
            temp1 = (arg0->unk_338 * (((arg0->unk_33C + (arg0->unk_0C.unk_28.x * arg0->unk_24C.z.x)) +
                                       (arg0->unk_0C.unk_28.y * arg0->unk_24C.z.y)) +
                                      (arg0->unk_0C.unk_28.z * arg0->unk_24C.z.z))) *
                    1.2f;
            temp1 += (arg0->unk_334 * ((temp4 * sp4C.z.x) + (temp5 * sp4C.z.y) + (temp6 * sp4C.z.z)) * 1.2f);
            var_a3 = Math_Round(temp1);
        } else if (!sp74) {
            var_a3 = Math_Round(-arg0->unk_334 * ((arg0->unk_C0.z.x * sp4C.x.x) + (arg0->unk_C0.z.y * sp4C.x.y) +
                                                  (arg0->unk_C0.z.z * sp4C.x.z)));
            if (!(Math_Rand2() % 64)) {
                if (Math_Rand1() % 2) {
                    arg0->unk_370 = (Math_Rand2() % 16) + 20;
                } else {
                    arg0->unk_370 = -20 - (Math_Rand1() % 16);
                }
            }

            if (arg0->unk_370 != 0) {
                var_a3 += (s32) (arg0->unk_334 / 20.0f);
                arg0->unk_370--;
            }
        } else {
            arg0->unk_370 = 0;
            temp1 = (arg0->unk_338 * DOT_XYZ(&arg0->unk_C0.z, &arg0->unk_24C.y) * 160.0f);
            var_a3 = Math_Round(temp1 - (arg0->unk_334 * 0.5f *
                                         ((arg0->unk_C0.z.x * sp4C.x.x) + (arg0->unk_C0.z.y * -sp4C.x.y) +
                                          (arg0->unk_C0.z.z * sp4C.x.z))));
        }
        if (arg0->unk_04 & 0x04000000) {
            var_a1 = Math_Round(-arg0->unk_334 * 0.1f * DOT_XYZ(&arg0->unk_C0.y, &sp4C.x));

            if (D_800F8514 == 0xC) {
                if ((arg0->unk_0C.unk_00->unk_30 >= 7) && (arg0->unk_0C.unk_00->unk_30 < 0xF)) {
                    if (arg0->unk_A0 > 400.0f) {
                        var_a3 = 0;
                    }
                    var_a1 = (s32) ((var_a1 * 0.25f) - (arg0->unk_A0 * 0.015f));
                    var_a3 *= 5;
                }
            }

            if (var_a1 < -0x46) {
                var_a1 = -0x46;
            } else if (var_a1 >= 0x47) {
                var_a1 = 0x46;
            }
            var_a3 /= 5;
            if (((arg0->unk_0C.unk_00->unk_20 & 0x1C0) == 0xC0) ||
                ((arg0->unk_0C.unk_00->unk_34->unk_20 & 0x1C0) == 0x180) ||
                ((arg0->unk_0C.unk_00->unk_34->unk_34->unk_20 & 0x1C0) == 0x180)) {
                var_a1 = 0x46;
                arg1->unk_7A &= 0x7FFF;
                arg1->unk_7C &= 0x7FFF;
                arg1->unk_7E &= 0x7FFF;
            }

            if (arg0->unk_33C > 0.0f) {
                arg0->unk_33C -= arg0->unk_354;
            } else {
                arg0->unk_33C += arg0->unk_354;
            }
            arg0->unk_1EC = (2500.0f / 27.0f);
            if (arg0->unk_1E8 >= 1.0f) {
                arg0->unk_1E8 = 1.0f;
            }
        } else {
            var_a1 = 0x46;
            if (((arg0->unk_0C.unk_00->unk_34->unk_20 & 0x1C0) == 0x180) && (arg0->unk_0C.unk_08 > 0.5f)) {
                arg0->unk_1EC = 69.44444f;
            }
        }
        if (var_a3 < -0x46) {
            var_a3 = -0x46;
            arg1->unk_7A |= 0x2000;
        } else if (var_a3 >= 0x47) {
            var_a3 = 0x46;
            arg1->unk_7A |= 0x10;
        }
        arg1->stickX = (var_a3 * 5) / 8;
        arg1->stickY = var_a1;
        if (gNumPlayers == 1) {
            if (sp70 && (arg0->unk_2A0 > 1000) && (gDifficulty >= EXPERT) && (arg0->unk_00 != 0) && (D_800E5EC0 != 1) &&
                (arg0->unk_36C & 0x200)) {
                if ((arg0->unk_2C4 < 23.0f) &&
                    (((gDifficulty >= EXPERT) && (D_i3_80141910->unk_23C < arg0->unk_23C)) ||
                     ((D_i3_80141910->unk_23C + 138.0f) < arg0->unk_23C)) &&
                    ((Math_Rand2() % 32768) < 16)) {
                    if (Math_Rand2() % 2) {
                        arg1->unk_7C |= 0x80;
                    } else {
                        arg1->unk_7C |= 0x40;
                    }
                }
                if ((arg0->unk_2C4 < 23.0f) && (func_i3_80115DF0(sp40->unk_33C - arg0->unk_33C) < 138.0f) &&
                    (arg0->unk_390 == 0) && (((f32) (Math_Rand1() % 32768) / 32767.0f) < 0.01f)) {
                    if (arg0->unk_33C < sp40->unk_33C) {
                        arg0->unk_390 = 5;
                    } else {
                        arg0->unk_390 = -5;
                    }
                }
            }

            if (arg0->unk_390 < 0) {
                arg0->unk_390++;
                if (((arg0->unk_390 == -3) || (arg0->unk_390 == -1)) &&
                    ((gDifficulty >= EXPERT) || (func_i3_80115DF0(D_i3_80141910->unk_23C - arg0->unk_23C) > 184.0f)) &&
                    (D_i3_80141910->unk_23C < arg0->unk_23C)) {
                    arg1->unk_7C |= 0x2000;
                }
            } else if (arg0->unk_390 > 0) {
                arg0->unk_390--;
                if (((arg0->unk_390 == 3) || (arg0->unk_390 == 1)) &&
                    ((gDifficulty >= EXPERT) || ((arg0->unk_23C - D_i3_80141910->unk_23C) > 184.0f)) &&
                    (D_i3_80141910->unk_23C < arg0->unk_23C)) {
                    arg1->unk_7C |= 0x10;
                }
            }
            if (!(Math_Rand2() % 2048)) {
                arg0->unk_36C &= ~0xC00;
            }
        }
        if (arg0->unk_04 & 1) {
            arg0->unk_394 = 0xB4;
        }

        if (arg0->unk_394 > 0) {
            arg0->unk_394--;
        }

        var_a3 = arg0->unk_0C.unk_00->unk_30;
        if (var_a3 != arg0->unk_358) {
            arg0->unk_344 = D_8010B7B0.unk_6E0[var_a3];
            arg0->unk_345 = D_8010B7B0.unk_6A0[var_a3];
            arg0->unk_346 = D_8010B7B0.unk_620[var_a3];
            arg0->unk_347 = D_8010B7B0.unk_660[var_a3];
            arg0->unk_348 = D_8010B7B0.unk_5A0[var_a3];
            if (gDifficulty >= EXPERT) {
                arg0->unk_349 = D_8010B7B0.unk_5E0[var_a3];
            } else {
                arg0->unk_349 = -1;
            }

            arg0->unk_35C = arg0->unk_0C.unk_00->unk_20 & 0x38000;
            arg0->unk_358 = var_a3;

            if (++var_a3 >= D_800F8510->unk_08) {
                var_a3 = 0;
            }
            arg0->unk_34A = D_8010B7B0.unk_6E0[var_a3];
            arg0->unk_34B = D_8010B7B0.unk_620[var_a3];
            arg0->unk_34C = D_8010B7B0.unk_5E0[var_a3];
            arg0->unk_34E = 6;
            if (arg0->unk_344 != -1) {
                arg0->unk_34E = 5;
            }
            if (arg0->unk_346 != -1) {
                arg0->unk_34E = 4;
            }
            if (arg0->unk_348 != -1) {
                arg0->unk_34E = 3;
            }
            if (arg0->unk_345 == 1) {
                arg0->unk_34E = 2;
            }
            if (arg0->unk_345 == 2) {
                arg0->unk_34E = 1;
            }
        }

        if (arg0->unk_36C & 0x800) {
            var_a3 = (arg0->unk_0C.unk_00->unk_20 & 0x1C0);
            if ((var_a3 == 0x80) || (var_a3 == 0xC0)) {
                if (arg0->character & 1) {
                    arg1->stickX += 42;
                    if (arg1->stickX > 70) {
                        arg1->stickX = 70;
                    }
                } else {
                    arg1->stickX -= 42;
                    if (arg1->stickX < -70) {
                        arg1->stickX = -70;
                    }
                }
            } else {
                var_a3 = (u32) ((arg0->character * 5) + gGameFrameCount) % 280U;
                if (var_a3 >= 0x8D) {
                    var_a3 = -var_a3;
                }
                if (var_a3 >= 0x47) {
                    var_a3 = 0x8C - var_a3;
                }
                if (var_a3 < -0x46) {
                    var_a3 = -0x8C - var_a3;
                }
                arg1->stickX = var_a3;
                if (D_i3_80141910->unk_23C < arg0->unk_23C) {
                    if (Math_Rand2() % 2) {
                        arg1->unk_7C |= 0x80;
                    } else {
                        arg1->unk_7C |= 0x40;
                    }
                }
            }
        } else {
            if (((arg0->unk_0C.unk_00->unk_20 & 0x1C0) != 0x80) && ((arg0->unk_0C.unk_00->unk_20 & 0x1C0) != 0xC0) &&
                (D_800DCE44 != 0x11)) {
                if ((D_800F8514 < 0x18) && (((arg0->unk_2A0 >= 0x7D1) &&
                                             (((arg0->unk_368 % 6) < 2) ||
                                              (func_i3_80115DF0(arg0->unk_23C - D_i3_80141910->unk_23C) > 5000.0f))) ||
                                            (arg0->unk_00 < gNumPlayers))) {
                    var_a3 = arg0->unk_0C.unk_00->unk_30 * 4;
                    if (arg0->unk_0C.unk_08 >= 0.5f) {
                        var_a3 += 2;
                    }
                    var_a1 = var_a3 + 2;
                    if (var_a1 >= (D_800F8510->unk_08 * 4)) {
                        var_a1 = 0;
                    }
                    sp7C = D_i3_8013DBE8[var_a3 + 1];
                    temps = D_i3_8013DBE8[var_a1 + 1];
                    spBC = (temps - sp7C) * arg0->unk_0C.unk_08 + sp7C;
                    if (D_800E5EC0 != 1) {
                        if (sp44->unk_00 != arg0->unk_352) {
                            if ((arg0->unk_2C0 < 92.0f) && (func_i3_80115DF0(sp44->unk_33C - spBC) < 69.0f)) {
                                if (spBC < sp44->unk_33C) {
                                    arg0->unk_33C = spBC - 92.0f;
                                } else {
                                    arg0->unk_33C = spBC + 92.0f;
                                }
                            } else {
                                arg0->unk_33C = spBC;
                            }
                        }
                    } else {
                        arg0->unk_33C = spBC;
                    }
                    if ((var_a3 != arg0->unk_358) && (sp7C & 1) && (arg0->unk_00 < gNumPlayers)) {
                        var_fv0 = arg0->unk_228 / arg0->unk_22C;
                        if (var_fv0 > 0.3f) {
                            arg1->unk_7C |= 0xC000;
                        }
                        arg0->unk_358 = arg0->unk_0C.unk_00->unk_30;
                    }
                    arg0->unk_388 = var_a3;
                    arg0->unk_330 = 0.1f;
                } else {
                    arg0->unk_330 = arg0->unk_98 * 0.1f;
                    sp9C = (arg0->unk_274 - arg0->unk_270) * 0.5f;
                    var_fv0 = arg0->unk_228 / arg0->unk_22C;
                    switch (arg0->unk_34E) {
                        case 1:
                            if (D_800F8514 != 0x11) {
                                if (arg0->unk_33C < sp9C + 92.0f) {
                                    arg0->unk_33C = sp9C + 92.0f;
                                }
                            } else {
                                if (arg0->unk_33C > sp9C - 230.0f) {
                                    arg0->unk_33C = sp9C - 230.0f;
                                }
                            }
                            break;
                        case 2:
                            if (D_800F8514 != 0x11) {
                                if (arg0->unk_33C > sp9C - 230.0f) {
                                    arg0->unk_33C = sp9C - 230.0f;
                                }
                            } else {
                                if (arg0->unk_33C < sp9C + 92.0f) {
                                    arg0->unk_33C = sp9C + 92.0f;
                                }
                            }
                            break;
                        case 3:
                            if ((arg0->unk_348 == 0) && (var_fv0 < 0.99f)) {
                                arg0->unk_33C = ((-arg0->unk_0C.unk_28.x * arg0->unk_24C.z.x) -
                                                 (arg0->unk_0C.unk_28.y * arg0->unk_24C.z.y)) -
                                                (arg0->unk_0C.unk_28.z * arg0->unk_24C.z.z);

                                if (func_i3_80115DF0(sp9C - arg0->unk_33C) < 146.0f) {
                                    if (arg0->unk_33C > sp9C) {
                                        arg0->unk_33C += arg0->unk_354 * 10.0f;
                                    } else {
                                        arg0->unk_33C -= arg0->unk_354 * 10.0f;
                                    }
                                }
                                break;
                            }

                            if ((arg0->unk_348 == 1) && (var_fv0 < 0.99f)) {
                                arg0->unk_33C = sp94;
                                if ((D_800DCE44 == 0x15) && (arg0->unk_00 >= gNumPlayers)) {
                                    if (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f)) {
                                        arg0->unk_33C += (arg0->unk_354 * 10.0f);
                                    }
                                } else {
                                    if (arg0->unk_33C > ((sp9C - 100.0f) - 46.0f)) {
                                        arg0->unk_33C -= arg0->unk_354 * 10.0f;
                                    }
                                }
                                break;
                            }

                            if ((arg0->unk_348 == 2) && ((arg0->unk_2A8 == 1) || (var_fv0 < 0.99f))) {
                                arg0->unk_33C = sp94;
                                if (arg0->unk_33C < (sp9C + 100.0f + 46.0f)) {
                                    arg0->unk_33C += arg0->unk_354 * 10.0f;
                                }
                                break;
                            }
                            /* fallthrough */
                        case 4:
                            if ((arg0->unk_346 != -1) && (arg0->unk_36C & 4)) {
                                if ((arg0->unk_346 == 0) && (func_i3_80115DF0(sp9C - arg0->unk_33C) > 77.0f)) {
                                    if (arg0->unk_33C > sp9C) {
                                        arg0->unk_33C -= arg0->unk_354 * 4.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 4.0f;
                                    }
                                    break;
                                }

                                if ((arg0->unk_346 == 2) && (arg0->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 4.0f;
                                    break;
                                }

                                if (arg0->unk_346 == 1) {
                                    if (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f)) {
                                        arg0->unk_33C += arg0->unk_354 * 4.0f;
                                        goto block_359;
                                    }
                                }
                                if (arg0->unk_346 == 3) {
                                    if (func_i3_80115DF0(sp9C - arg0->unk_33C) > 146.0f) {
                                        if (arg0->unk_33C < sp9C) {
                                            arg0->unk_33C -= arg0->unk_354 * 4.0f;
                                        } else {
                                            arg0->unk_33C += arg0->unk_354 * 4.0f;
                                        }
                                        break;
                                    }
                                }
                            }
                            /* fallthrough */
                        case 5:
                        block_359:
                            if (arg0->unk_344 != -1) {
                                if ((arg0->unk_344 == 2) && (arg0->unk_33C > (sp9C - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                } else if ((arg0->unk_344 == 1) && (arg0->unk_33C < (sp9C + 46.0f))) {
                                    arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    break;
                                }
                            }
                            /* fallthrough */
                        case 6:
                            if ((D_800E5EC0 != 1) && (sp44->unk_00 != arg0->unk_352) && (arg0->unk_2C0 < 92.0f) &&
                                (func_i3_80115DF0(sp44->unk_33C - arg0->unk_33C) < 92.0f)) {
                                if ((arg0->unk_33C > 0.0f) && (arg0->unk_274 < (arg0->unk_33C + 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354;
                                    break;
                                }
                                if ((arg0->unk_33C < 0.0f) && ((46.0f - arg0->unk_33C) < arg0->unk_270)) {
                                    arg0->unk_33C += arg0->unk_354;
                                    break;
                                }
                                if (sp44->unk_33C < arg0->unk_33C) {
                                    arg0->unk_33C += arg0->unk_354;
                                    break;
                                }

                                arg0->unk_33C -= arg0->unk_354;
                                break;
                            }

                            if ((arg0->unk_349 != -1) && (arg0->unk_36C & 1)) {
                                if ((arg0->unk_349 == 0) && (arg0->unk_0C.unk_08 < 0.8f) &&
                                    (func_i3_80115DF0(arg0->unk_33C - sp9C) < 230.0f)) {
                                    arg0->unk_33C = sp9C;
                                    break;
                                }
                                if ((arg0->unk_349 == 1) && (arg0->unk_0C.unk_08 < 0.8f) &&
                                    (func_i3_80115DF0(arg0->unk_33C - ((-1.0f * arg0->unk_270) + 100.0f)) < 230.0f)) {
                                    arg0->unk_33C = (arg0->unk_270 * -1.0f) + 100.0f;
                                    break;
                                }
                                if ((arg0->unk_349 == 2) && (arg0->unk_0C.unk_08 < 0.8f)) {
                                    if (func_i3_80115DF0(arg0->unk_33C - (arg0->unk_274 - 100.0f)) < 230.0f) {
                                        arg0->unk_33C = arg0->unk_274 - 100.0f;
                                        break;
                                    }
                                }
                            }
                            if ((arg0->unk_347 != -1) && (arg0->unk_36C & 1)) {
                                if ((arg0->unk_347 == 0) && (func_i3_80115DF0(sp9C - arg0->unk_33C) > 77.0f)) {
                                    if (sp9C < arg0->unk_33C) {
                                        arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    }
                                    break;
                                }

                                if ((arg0->unk_347 == 2) && (arg0->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                }

                                if ((arg0->unk_347 == 1) && (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f))) {
                                    arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    break;
                                }

                                if ((arg0->unk_347 == 3) && (func_i3_80115DF0(sp9C - arg0->unk_33C) > 146.0f)) {
                                    if (arg0->unk_33C < sp9C) {
                                        arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    }
                                    break;
                                }
                            }

                            if ((arg0->unk_34B != -1) && (arg0->unk_36C & 0x10)) {
                                if ((arg0->unk_34B == 0) && (func_i3_80115DF0(sp9C - arg0->unk_33C) > 77.0f)) {
                                    if (arg0->unk_33C > sp9C) {
                                        arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    }
                                    break;
                                }

                                if ((arg0->unk_34B == 2) && (arg0->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                }
                                if (arg0->unk_34B == 1) {
                                    if (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f)) {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    } else {
                                        goto block_429;
                                    }
                                } else {
                                block_429:
                                    if ((arg0->unk_34B == 3) && (func_i3_80115DF0(sp9C - arg0->unk_33C) > 146.0f)) {
                                        if (arg0->unk_33C < sp9C) {
                                            arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                        } else {
                                            arg0->unk_33C += arg0->unk_354 * 3.0f;
                                        }
                                        break;
                                    }
                                }
                            }
                            if ((arg0->unk_34A != -1) && (arg0->unk_36C & 8)) {
                                if ((arg0->unk_34A == 2) && (arg0->unk_33C > (sp9C - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                } else if ((arg0->unk_34A == 1) && (arg0->unk_33C < (sp9C + 46.0f))) {
                                    arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    break;
                                }
                            }

                            if ((arg0->unk_34C != -1) && (arg0->unk_36C & 0x20)) {
                                if ((arg0->unk_34C == 0) && (arg0->unk_0C.unk_08 < 0.5f) &&
                                    (func_i3_80115DF0(arg0->unk_33C - sp9C) < 230.0f)) {
                                    arg0->unk_33C = sp9C;
                                    break;
                                } else {
                                    if ((arg0->unk_34C == 1) && (arg0->unk_0C.unk_08 < 0.5f) &&
                                        (func_i3_80115DF0(arg0->unk_33C - ((-1.0f * arg0->unk_270) + 100.0f)) <
                                         230.0f)) {
                                        arg0->unk_33C = (arg0->unk_270 * -1.0f) + 100.0f;
                                        break;
                                    }
                                    if ((arg0->unk_34C == 2) && (arg0->unk_0C.unk_08 < 0.5f) &&
                                        (func_i3_80115DF0(arg0->unk_33C - (arg0->unk_274 - 100.0f)) < 230.0f)) {
                                        arg0->unk_33C = arg0->unk_274 - 100.0f;
                                        break;
                                    }
                                }
                            }

                            if ((arg0->unk_2A0 >= 0x7D1) && !(Math_Rand1() & 0x7F0)) {
                                if (!(Math_Rand1() % 2)) {
                                    arg0->unk_33C -= 46.0f;
                                } else {
                                    arg0->unk_33C += 46.0f;
                                }
                            }
                            break;
                    }
                }
            }
        }
        D_i3_8013EC90[arg0->character](arg0, arg1);
        if ((gNumPlayers == 1) && (arg0->unk_00 != 0)) {
            var_fv0 = arg0->unk_23C - D_i3_80141910->unk_23C;
            if ((var_fv0 > -230.0f) && (var_fv0 < -11.5f) &&
                (func_i3_80115DF0(sp94 - D_i3_80141910->unk_33C) < 92.0f)) {
                if (D_i3_80141910->unk_33C < sp94) {
                    arg0->unk_33C = D_i3_80141910->unk_33C + 92.0f;
                } else {
                    arg0->unk_33C = D_i3_80141910->unk_33C - 92.0f;
                }
            }
        }

        if ((arg0->unk_0C.unk_00->unk_20 & 0x1C0) == 0x100) {
            spBC = 92.0f;
        } else if ((arg0->unk_0C.unk_00->unk_20 & 0x1C0) != 0x1C0) {
            if (arg0->unk_35C == 0x8000) {
                spBC = 23.0f;
            } else {
                spBC = 50.600002f;
            }
        } else {
            spBC = 92.0f;
        }
        if ((arg0->unk_35C == 0x18000) || ((arg0->unk_35C == 0x20000) && (arg0->unk_0C.unk_08 > 0.6f)) ||
            ((arg0->unk_35C == 0x28000) && (arg0->unk_0C.unk_08 < 0.4f))) {
            if (arg0->unk_33C < 0.0f) {
                if (arg0->unk_270 < ((arg0->unk_33C * -1.0f) + spBC)) {
                    arg0->unk_33C = (arg0->unk_270 - spBC) * -1.0f;
                }
            } else {
                if (arg0->unk_274 < (arg0->unk_33C + (spBC * 0.5f))) {
                    arg0->unk_33C = arg0->unk_274 - (spBC * 0.5f);
                }
            }
        } else if ((arg0->unk_35C == 0x10000) || ((arg0->unk_35C == 0x20000) && (arg0->unk_0C.unk_08 < 0.4f)) ||
                   ((arg0->unk_35C == 0x28000) && (arg0->unk_0C.unk_08 > 0.6f))) {
            if (arg0->unk_33C < 0.0f) {
                if (arg0->unk_270 < ((arg0->unk_33C * -1.0f) + (spBC * 0.5f))) {
                    arg0->unk_33C = (arg0->unk_270 - (spBC * 0.5f)) * -1.0f;
                }
            } else {
                if (arg0->unk_274 < (arg0->unk_33C + spBC)) {
                    arg0->unk_33C = arg0->unk_274 - spBC;
                }
            }
        } else {
            if (arg0->unk_33C < 0.0f) {
                if (arg0->unk_270 < ((arg0->unk_33C * -1.0f) + spBC)) {
                    arg0->unk_33C = (arg0->unk_270 - spBC) * -1.0f;
                }
            } else {
                if (arg0->unk_274 < (arg0->unk_33C + spBC)) {
                    arg0->unk_33C = arg0->unk_274 - spBC;
                }
            }
        }
        if ((gNumPlayers == 1) && (arg0->unk_00 != 0)) {
            var_fv0 = D_i3_80141910->unk_23C - arg0->unk_23C;
            if ((var_fv0 > 0.0f) && (var_fv0 < spBC) &&
                (func_i3_80115DF0(D_i3_80141910->unk_33C - arg0->unk_33C) < 69.0f)) {
                if (D_i3_80141910->unk_98 < arg0->unk_1EC) {
                    arg0->unk_1EC = D_i3_80141910->unk_98;
                }
            }
        }
        if (arg0->unk_1EC < (625.0f / 27.0f)) {
            arg0->unk_1EC = (625.0f / 27.0f);
        }
        if ((arg0->unk_04 & 0x02000000) || (D_800DCE44 == 0x11)) {
            arg0->unk_36C &= ~0xA00;
            if (arg0->unk_00 < gNumPlayers) {
                arg1->unk_7C &= ~0x4000;
            }
            if (D_i3_80141908 != 0) {
                // FAKE!
                if (1) {}
                var_a1 = 0;
                for (i = 0; i < D_800E5EC0; i++) {
                    if (gRacers[i].unk_35C == 0x8000) {
                        var_a1++;
                    }
                }

                if (var_a1 == D_800E5EC0) {
                    if (arg0->unk_00 == 0) {
                        D_i3_8014190C++;
                    }
                    if (D_i3_8014190C > 60) {
                        arg0->unk_1EC = arg0->unk_98 * 0.1f;
                        arg1->unk_7A |= 4;
                        arg1->unk_7A &= 0x7FFF;
                        arg1->unk_7C &= 0x7FFF;
                        arg1->unk_7E &= 0x7FFF;
                    }
                }
            }
            if (arg0->unk_36C & 0x1000) {
                arg1->unk_7A |= 4;
                arg1->unk_7A &= 0x7FFF;
                arg1->unk_7C &= 0x7FFF;
                arg1->unk_7E &= 0x7FFF;
            }
        }
        arg0->unk_374 = arg1->stickX;
        arg0->unk_378 = arg1->stickY;
        arg0->unk_37C = arg1->unk_7C;
        arg0->unk_380 = arg1->unk_7A;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i3/A90C0/func_i3_80117BF0.s")
void func_i3_80117BF0(Racer* arg0, Controller* arg1);
#endif
