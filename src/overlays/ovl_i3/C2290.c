#include "global.h"
#include "fzx_racer.h"
#include "ovl_i3.h"
#include "tex_assets.h"
#include "segment_symbols.h"

f32 D_i3_80141E30[30];
unk_80141EA8 D_i3_80141EA8[4];
s32 D_i3_80141FC8[4];
s32 D_i3_80141FD8[4];

s32 D_i3_8013EFF0 = 0;
s32 D_i3_8013EFF4 = 0;
s32 D_i3_8013EFF8 = 0;
s32 D_i3_8013EFFC = 180;
s32 D_i3_8013F000 = 3;
UNUSED s32 D_i3_8013F004 = 0;

s32 D_i3_8013F008[] = { 1, 1, 1, 1 };

UNUSED s32 D_i3_8013F018 = 0;
UNUSED s32 D_i3_8013F01C = 0;

s32 D_i3_8013F020[6][3] = { 0 };

f32 D_i3_8013F068[] = { 1.0f, 1.0f, 1.0f, 1.0f };

s32 D_i3_8013F078[] = { 0, 0, 0, 0 };

TexturePtr D_i3_8013F088[] = {
    D_401AA20, D_4026A20, D_4024A20, D_401B220, D_401BA20, D_4026220, D_4020A20, D_4027A20, D_4024220, D_4021220,
    D_4023220, D_401F220, D_4022220, D_4025220, D_401C220, D_401EA20, D_4023A20, D_4021A20, D_401CA20, D_4028220,
    D_4027220, D_401DA20, D_4028A20, D_4020220, D_4022A20, D_4025A20, D_401FA20, D_401E220, D_4029220, D_401D220,
};

UNUSED u32 D_8013F100 = 0x2800;

TexturePtr D_i3_8013F104[] = {
    D_4029A20, D_4029AE0, D_4029BA0, D_4029C60, D_4029D20, D_4029DE0,
};

s32 D_i3_8013F11C[][4][2] = {
    { { 230, 38 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 24, 20 }, { 24, 132 }, { 0, 0 }, { 0, 0 } },
    { { 24, 20 }, { 24, 132 }, { 168, 20 }, { 0, 0 } },
    { { 24, 20 }, { 24, 132 }, { 168, 20 }, { 168, 132 } },
};

s32 D_i3_8013F19C[][4][2] = {
    { { 198, 38 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 100, 20 }, { 100, 132 }, { 0, 0 }, { 0, 0 } },
    { { 26, 20 }, { 26, 132 }, { 164, 20 }, { 0, 0 } },
    { { 26, 20 }, { 26, 132 }, { 164, 20 }, { 164, 132 } },
};

s32 D_i3_8013F21C[] = { 0, 0, 0, 0 };

u32 D_i3_8013F22C[] = {
    (GPACK_RGBA5551(155, 0, 0, 1) << 16 | GPACK_RGBA5551(155, 0, 0, 1)),
    (GPACK_RGBA5551(220, 0, 0, 1) << 16 | GPACK_RGBA5551(220, 0, 0, 1)),
    (GPACK_RGBA5551(255, 0, 0, 1) << 16 | GPACK_RGBA5551(255, 0, 0, 1)),
    (GPACK_RGBA5551(220, 0, 0, 1) << 16 | GPACK_RGBA5551(230, 0, 0, 1)),
    (GPACK_RGBA5551(155, 0, 0, 1) << 16 | GPACK_RGBA5551(155, 0, 0, 1)),
    (GPACK_RGBA5551(0, 255, 0, 1) << 16 | GPACK_RGBA5551(0, 255, 0, 1)),
    (GPACK_RGBA5551(0, 255, 20, 1) << 16 | GPACK_RGBA5551(0, 255, 20, 1)),
    (GPACK_RGBA5551(0, 195, 35, 1) << 16 | GPACK_RGBA5551(0, 195, 35, 1)),
    (GPACK_RGBA5551(0, 160, 50, 1) << 16 | GPACK_RGBA5551(0, 160, 50, 1)),
    (GPACK_RGBA5551(0, 135, 70, 1) << 16 | GPACK_RGBA5551(0, 135, 70, 1)),
};

s32 D_i3_8013F254[][4][2] = {
    { { 220, 20 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 224, 20 }, { 224, 132 }, { 0, 0 }, { 0, 0 } },
    { { 96, 20 }, { 96, 132 }, { 240, 20 }, { 0, 0 } },
    { { 96, 20 }, { 96, 132 }, { 240, 20 }, { 240, 132 } },
};

s32 D_i3_8013F2D4[][4][2] = {
    { { 222, 28 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 226, 28 }, { 226, 140 }, { 0, 0 }, { 0, 0 } },
    { { 98, 26 }, { 98, 138 }, { 242, 26 }, { 0, 0 } },
    { { 98, 26 }, { 98, 138 }, { 242, 26 }, { 242, 138 } },
};

s32 D_i3_8013F354[][4][2] = {
    { { 226, 204 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 226, 92 }, { 226, 204 }, { 0, 0 }, { 0, 0 } },
    { { 24, 20 }, { 24, 132 }, { 168, 20 }, { 0, 0 } },
    { { 24, 20 }, { 24, 132 }, { 168, 20 }, { 168, 132 } },
};

s32 D_i3_8013F3D4[][4][2] = {
    { { 118, 20 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { -4, 76 }, { -4, 188 }, { 0, 0 }, { 0, 0 } },
    { { 4, 84 }, { 4, 196 }, { 146, 84 }, { 0, 0 } },
    { { 4, 84 }, { 4, 196 }, { 146, 84 }, { 146, 196 } },
};

s32 D_i3_8013F454[][4][2] = {
    { { 66, 20 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 24, 40 }, { 24, 152 }, { 0, 0 }, { 0, 0 } },
    { { 130, 87 }, { 130, 199 }, { 272, 87 }, { 0, 0 } },
    { { 130, 87 }, { 130, 199 }, { 272, 87 }, { 272, 199 } },
};

s32 D_i3_8013F4D4[] = { 18, 56, 94, 132, 162, 192 };

s32 D_i3_8013F4EC[] = { 50, 88, 126, 156, 186, 216 };

s32 D_i3_8013F504[][4][2] = {
    { { 120, 72 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 120, 20 }, { 120, 132 }, { 0, 0 }, { 0, 0 } },
    { { 48, 40 }, { 48, 152 }, { 196, 40 }, { 0, 0 } },
    { { 48, 40 }, { 48, 152 }, { 196, 40 }, { 196, 152 } },
};

s32 D_i3_8013F584[][4][2] = {
    { { 104, 64 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 104, 20 }, { 104, 132 }, { 0, 0 }, { 0, 0 } },
    { { 44, 40 }, { 44, 152 }, { 188, 40 }, { 0, 0 } },
    { { 44, 40 }, { 44, 152 }, { 188, 40 }, { 188, 152 } },
};

s32 D_i3_8013F604[][4][2] = {
    { { 68, 48 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
};

s32 D_i3_8013F684[] = { 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

Gfx* func_i3_8012EFC0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {

    if (arg3 >= 15) {
        return gfx;
    }

    gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (s32) (arg1 + 8.0f) << 2, (s32) (arg2 + 16.0f * arg4) << 2, 0, 0,
                        (arg3 * 16) << 5, 1 << 10, (s32) (1024.0f / arg4));
    return gfx;
}

Gfx* func_i3_8012F0B0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {

    if (arg3 >= 15) {
        return gfx;
    }

    gSPScisTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (s32) (arg1 + 8.0f * arg4) << 2,
                            (s32) (arg2 + 16.0f * arg4) << 2, 0, 0, (arg3 * 16) << 5, (s32) (1024.0f / arg4),
                            (s32) (1024.0f / arg4));
    return gfx;
}

extern s32 D_800DCE44;

void func_i3_8012F324(void) {
    s32 i;

    D_i3_8013EFF0 = 0;
    D_i3_8013EFF4 = 0;
    D_i3_8013EFF8 = 0;

    func_80078104(D_F243290, 0x180, 0, 0, 0);

    if (D_800DCE44 == 2) {
        D_i3_8013EFFC = 360;
    } else {
        D_i3_8013EFFC = 180;
    }

    for (i = 0; i < 4; i++) {
        D_i3_80141EA8[i].unk_00 = 0;
        D_i3_80141EA8[i].unk_04 = 0;
        D_i3_80141EA8[i].unk_08 = 0;
        D_i3_80141EA8[i].unk_0C.unk_00 = 0;

        D_i3_8013F068[i] = 1.0f;
        D_i3_8013F008[i] = 1;
    }
}

void func_i3_8012F450(unk_8012F450* arg0) {

    if (arg0->unk_00 < 360000) {
        arg0->unk_00++;
    }

    arg0->unk_04 = (arg0->unk_00) / 3600;
    arg0->unk_05 = (arg0->unk_00) / 60 % 60;
    arg0->unk_08 = (arg0->unk_00) % 60 / 60.0f;

    if (arg0->unk_04 >= 100) {
        arg0->unk_08 = 0.99f;
        arg0->unk_05 = 60 - 1;
        arg0->unk_04 = 100 - 1;
    }
}

Gfx* func_i3_8012F0B0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, f32 arg4);

Gfx* func_i3_8012F554(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    s32 var_s0 = 0;
    s32 var_s1;

    if (arg1 >= (3600000 - 1)) {
        arg1 = (3600000 - 1);
    }

    var_s1 = arg1 / 60000;

    if (var_s1 < 10) {
        gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, 0, arg4);
        var_s0 += 8.0f * arg4;
        gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, var_s1, arg4);
        var_s0 += 8.0f * arg4;
    } else {
        gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, var_s1 / 10, arg4);
        var_s0 += 8.0f * arg4;
        gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, var_s1 % 10, arg4);
        var_s0 += 8.0f * arg4;
    }

    arg1 -= var_s1 * 60000;
    var_s1 = arg1 / 1000;

    gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, 10, arg4);
    var_s0 += 8.0f * arg4;

    if (var_s1 < 10) {
        gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, 0, arg4);
        var_s0 += 8.0f * arg4;
        gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, var_s1, arg4);
        var_s0 += 8.0f * arg4;
    } else {
        gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, var_s1 / 10, arg4);
        var_s0 += 8.0f * arg4;
        gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, var_s1 % 10, arg4);
        var_s0 += 8.0f * arg4;
    }

    arg1 -= var_s1 * 1000;
    var_s1 = arg1 / 100;

    gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, 11, arg4);
    var_s0 += 8.0f * arg4;

    gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, var_s1, arg4);
    var_s0 += 8.0f * arg4;

    arg1 -= var_s1 * 100;
    var_s1 = arg1 / 10;

    gfx = func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, var_s1, arg4);
    var_s0 += 8.0f * arg4;

    arg1 -= var_s1 * 10;

    return func_i3_8012F0B0(gfx, arg2 + var_s0, arg3, arg1, arg4);
}

Gfx* func_i3_8012F8E4(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 var = 0;

    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 10, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 11, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    return func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
}

Gfx* func_i3_8012F9F4(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 var = 0;

    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 10, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 11, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    gfx = func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
    var += 8;
    return func_i3_8012EFC0(gfx, arg1 + var, arg2, 13, 1.0f);
}

Gfx* func_i3_8012FB20(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad;
    s32 temp_s1;
    s32 temp_t0;
    s32 var_s0 = 0;
    s32 var_s1;
    f32 var_fs0;

    if (arg1 >= (3600000 - 1)) {
        arg1 = (3600000 - 1);
    }

    temp_t0 = D_i3_8013F11C[arg2][arg3][0];
    temp_s1 = D_i3_8013F11C[arg2][arg3][1];

    switch (arg2) {
        case 0:
        case 1:
            var_fs0 = 1.0f;
            break;
        case 2:
        case 3:
            var_fs0 = 0.75f;
            break;
    }

    if (arg1 >= (3600000 - 1)) {
        arg1 = (3600000 - 1);
    }

    var_s1 = arg1 / 60000;

    if (var_s1 < 10) {
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, 0, var_fs0);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, var_s1, var_fs0);
        var_s0 += 8;
    } else {
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, var_s1 / 10, var_fs0);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, var_s1 % 10, var_fs0);
        var_s0 += 8;
    }

    arg1 -= var_s1 * 60000;
    var_s1 = arg1 / 1000;

    gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, 10, var_fs0);

    var_s0 += 8;

    if (var_s1 < 10) {
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, 0, var_fs0);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, var_s1, var_fs0);
        var_s0 += 8;
    } else {
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, var_s1 / 10, var_fs0);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, var_s1 % 10, var_fs0);
        var_s0 += 8;
    }

    arg1 -= var_s1 * 1000;
    var_s1 = arg1 / 10;

    gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, 11, var_fs0);
    var_s0 += 8;
    if (var_s1 < 10) {
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, 0, var_fs0);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, var_s1, var_fs0);
    } else {
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, var_s1 / 10, var_fs0);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, temp_t0 + var_s0, temp_s1, var_s1 % 10, var_fs0);
    }
    return gfx;
}

extern Gfx D_80149D0[];

Gfx* func_i3_8012FE8C(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 temp_a3;
    s32 temp_v0;

    if (D_800DCE44 == 2) {
        return gfx;
    }

    temp_v0 = D_i3_8013F19C[arg1][arg2][0];
    temp_a3 = D_i3_8013F19C[arg1][arg2][1];

    gSPDisplayList(gfx++, D_80149D0);
    gSPTextureRectangle(gfx++, temp_v0 << 2, temp_a3 << 2, (temp_v0 + 23) << 2, (temp_a3 + 15) << 2, 0, 0, 0, 1 << 12,
                        1 << 10);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

extern s32 D_800CD00C;
extern s16 D_800E5FBC;
extern s16 D_800E5FD0;
extern s8 D_800DCE5C;

Gfx* func_i3_8012FF7C(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 pad[2];
    s32 var_a1;
    bool var_a0;

    if (D_800DCE44 == 0x15) {
        return gfx;
    }

    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    var_a1 = gRacers[arg2].unk_2A8;
    var_a0 = false;

    if (D_800DCE44 == 2) {
        if (gRacers[arg2].unk_2B0 != 0) {
            var_a0 = true;
        }
    } else if (D_i3_8013F008[arg2] < var_a1) {
        var_a0 = true;
    }
    if (var_a0) {
        gRacers[arg2].unk_2B0 = 0;
        D_i3_8013F008[arg2] = var_a1;

        D_i3_80141EA8[arg2].unk_04 = D_i3_8013EFFC;
        if ((gRacers[arg2].unk_2AC != 1) || (D_800DCE44 == 0xE)) {
            D_i3_80141EA8[arg2].unk_08 = 0x5A;
        }
        if ((var_a1 == 2) && (D_i3_8013EFF4 == 0) && (D_800E5FD0 != 0) && (D_800DCE44 != 2)) {
            func_800BA8D8(0x11U);
            D_i3_8013EFF4 = 1;
        }
        if ((var_a1 == D_800CD00C) && (D_i3_8013EFF8 == 0) && (D_800E5FD0 != 0) && (D_800DCE44 != 2)) {
            func_800BA8D8(0x12U);
            D_i3_8013EFF8 = 1;
        }
    }

    if (D_i3_8013EFFC == D_i3_80141EA8[arg2].unk_04) {
        D_i3_8013F21C[arg2] = gRacers[arg2].unk_290[(var_a1 + 1) % 3];
    }

    func_i3_8012F450(&D_i3_80141EA8[arg2].unk_0C);

    if (D_i3_80141EA8[arg2].unk_04 > 0) {
        if (D_800DCE5C == 0) {
            D_i3_80141EA8[arg2].unk_04--;
        }
        if ((D_i3_80141EA8[arg2].unk_04 % 20) >= 5) {
            if ((arg1 != 0) && (D_800E5FBC != 0) && (gRacers[arg2].unk_2AC != 1)) {
                return gfx;
            }

            gfx = func_i3_8012FB20(gfx, D_i3_8013F21C[arg2] + 5, arg1, arg2);
        }
    } else if (arg1 < 2) {
        if (D_800DCE44 == 2) {
            return gfx;
        }
        if ((arg1 == 1) && (D_800E5FBC != 0)) {
            return gfx;
        }

        gfx = func_i3_8012FB20(gfx, gRacers[arg2].unk_2A0 + 5, arg1, arg2);
    }
    return gfx;
}

extern Gfx D_80149A0[];

Gfx* func_i3_80130304(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 i;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s3;
    s32 var_s4;
    f32 sp58;

    if (gRacers[arg2].unk_04 & 0x02000000) {
        return gfx;
    }

    var_s0 = D_i3_8013F2D4[arg1][arg2][0];
    var_s3 = D_i3_8013F2D4[arg1][arg2][1];

    switch (arg1) {
        case 0:
        case 1:
            var_s4 = 5;
            sp58 = 1.0f;
            break;
        case 2:
        case 3:
            var_s4 = 3;
            var_s3++;
            sp58 = 0.75f;
            break;
    }

    temp_v0 = func_8006A9E0((gRacers[arg2].unk_228 / gRacers[arg2].unk_22C) * 68.0f * sp58);

    gSPDisplayList(gfx++, D_80149A0);

    for (i = 0; i < var_s4; i++) {
        gDPPipeSync(gfx++);
        if (gRacers[arg2].unk_04 & 0x100000) {
            gDPSetFillColor(gfx++, D_i3_8013F22C[i + 5]);
        } else {
            gDPSetFillColor(gfx++, D_i3_8013F22C[i]);
        }

        gDPFillRectangle(gfx++, var_s0, var_s3 + i, var_s0 + temp_v0 - 1, var_s3 + i);
    }

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

Gfx* func_i3_8013064C(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 pad;
    s32 temp_t0;
    s32 temp_v1;
    s32 sp8;
    s32 sp4;
    f32 var_fv0;

    if (gRacers[arg2].unk_04 & 0x02000000) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_80149D0);

    temp_v1 = D_i3_8013F254[arg1][arg2][0];
    temp_t0 = D_i3_8013F254[arg1][arg2][1];

    switch (arg1) {
        case 0:
        case 1:
            var_fv0 = 1.0f;
            sp8 = 71.0f * var_fv0;
            sp4 = 15.0f * var_fv0;
            break;
        case 2:
        case 3:
            var_fv0 = 0.75f;
            sp8 = 72.0f * var_fv0;
            sp4 = 16.0f * var_fv0;
            break;
    }

    gSPTextureRectangle(gfx++, temp_v1 << 2, temp_t0 << 2, (temp_v1 + sp8) << 2, (temp_t0 + sp4) << 2, 0, 0, 0,
                        (s32) ((1 << 12) / var_fv0), (s32) ((1 << 10) / var_fv0));

    return gfx;
}

extern u8 D_303B270[];
extern u8 D_303C170[];
extern Gfx D_80149A0[];

Gfx* func_i3_80130824(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 i;
    s32 temp_t3;
    s32 temp_t4;
    s32 sp48;
    s32 temp_lo;
    s32 var_t0;
    s32 temp_v0;
    s32 var_a2;
    f32 sp34;

    if ((arg1 >= 2) && (D_i3_80141EA8[arg2].unk_04 != 0)) {
        return gfx;
    }

    switch (arg1) {
        case 0:
        case 1:
            sp34 = 1.0f;
            sp48 = 15;
            break;
        case 2:
        case 3:
            sp34 = 0.75f;
            sp48 = 16.0f * sp34;
            break;
    }

    var_a2 = 1000;
    var_t0 = temp_v0 = func_8006A9E0(gRacers[arg2].unk_98 * 21.6f);
    temp_t3 = D_i3_8013F354[arg1][arg2][0];
    temp_t4 = D_i3_8013F354[arg1][arg2][1];

    gSPDisplayList(gfx++, D_80149A0);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));

    gDPFillRectangle(gfx++, temp_t3 + 12, temp_t4, temp_t3 + 35, temp_t4 + sp48);

    gSPDisplayList(gfx++, D_80149D0);

    gDPLoadTextureBlock(gfx++, D_303B270, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 160, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < 4; i++) {
        temp_lo = var_t0 / var_a2;
        if ((i != 3) && (temp_lo == 0) && (temp_v0 == var_t0)) {
            var_t0 %= var_a2;
            var_a2 /= 10;
        } else {
            gSPTextureRectangle(gfx++, (temp_t3 + (i * 12)) << 2, temp_t4 << 2, (temp_t3 + (i * 12) + 11) << 2,
                                (temp_t4 + sp48) << 2, 0, 0, (temp_lo * 16) << 5, 1 << 12, (s32) ((1 << 10) / sp34));
            var_t0 %= var_a2;
            var_a2 /= 10;
        }
    }

    gDPLoadTextureBlock(gfx++, D_303C170, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (temp_t3 + (i * 12)) << 2, temp_t4 << 2, (temp_t3 + (i * 12) + 19) << 2,
                        (temp_t4 + sp48) << 2, 0, 0, 0, 1 << 12, (s32) ((1 << 10) / sp34));

    return gfx;
}

extern s16 D_800E5FC6;
extern s32 D_800E5EC0;
extern u8 D_40183E0[];
extern u8 D_40187E0[];

Gfx* func_i3_80130D78(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 i;
    s32 temp_ft3;
    s32 temp_lo;
    s32 var_a3;
    s32 var_v0;
    f32 temp = 0.25f;
    ;

    var_v0 = 10;
    var_a3 = D_800E5EC0 - D_800E5FC6;

    if (D_800DCE44 == 0x15) {
        gDPPipeSync(gfx++);

        arg1 -= 88;
        arg2 += 16;

        gDPLoadTextureBlock(gfx++, D_40183E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (arg1 + 32) << 2, (arg2 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        return gfx;
    }

    gDPPipeSync(gfx++);

    arg2 += 20;

    gDPLoadTextureBlock(gfx++, D_40187E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 132, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (arg1 - 2) << 2, arg2 << 2, ((arg1 - 2) + 8) << 2, (arg2 + 12) << 2, 0, 0,
                        (10 * 12) << 5, 1 << 10, 1 << 10);

    temp_ft3 = 28.0f * temp;

    arg1 += 6;

    for (i = 0; i < 2; i++) {
        temp_lo = var_a3 / var_v0;
        if ((i == 0) && (temp_lo == 0)) {
            arg1 += temp_ft3;
            var_v0 /= 10;
        } else {
            gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (arg1 + 8) << 2, (arg2 + 12) << 2, 0, 0,
                                (temp_lo * 12) << 5, 1 << 10, 1 << 10);

            arg1 += temp_ft3;
            var_a3 %= var_v0;
            var_v0 /= 10;
        }
    }

    return gfx;
}

Gfx* func_i3_801311FC(Gfx* gfx, s32 arg1, s32 arg2, f32 arg3) {

    gSPTextureRectangle(gfx++, arg1 << 2, (s32) (arg2 + (12.0f * arg3)) << 2, (s32) (arg1 + (20.0f * arg3)) << 2,
                        (s32) (arg2 + (12.0f * arg3) + (20.0f * arg3)) << 2, 0, 0, 0, (s32) ((1 << 10) / arg3),
                        (s32) ((1 << 10) / arg3));

    return gfx;
}

extern u8 D_4013DE0[];
extern u8 D_4019020[];
extern Gfx D_8014940[];

Gfx* func_i3_801312DC(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 i;
    u8* texturePtr;
    s32 temp_lo;
    f32 var_ft4;
    f32 var_fv0;
    s32 spC0;
    s32 temp_ft2;
    s32 var_s2;
    f32 var_fv1;
    f32 var_fa1;
    s32 var_t3;
    s32 var_t4;

    if (D_800DCE44 == 2) {
        return gfx;
    }
    if (D_800DCE44 == 0xE) {
        return gfx;
    }

    if (gRacers[arg2].unk_04 & 0x02040000) {
        D_i3_8013F068[arg2] += 0.04f;
    }
    if (D_i3_8013F068[arg2] > 1.5f) {
        D_i3_8013F068[arg2] = 1.5f;
    }

    var_s2 = D_i3_8013F3D4[arg1][arg2][0];
    temp_ft2 = D_i3_8013F3D4[arg1][arg2][1];

    var_t3 = 10;

    switch (arg1) {
        case 0:
            D_i3_8013F068[arg2] = 1.0f;
        /* fallthrough */
        case 1:
            var_fa1 = var_fv1 = 1.0f;
            break;
        case 2:
        case 3:
            var_fa1 = var_fv1 = 0.75f;
            break;
        default:
            break;
    }
    var_fv1 *= D_i3_8013F068[arg2];

    if (D_800DCE44 == 0x15) {
        var_t4 = (D_800E5EC0 - D_800E5FC6) - 1;
    } else {
        var_t4 = gRacers[arg2].unk_2AC;
    }

    if (arg1 != 0) {
        var_fv0 = var_fv1 - var_fa1;
        var_ft4 = (var_fv0 * 28.0f) / 2;
    } else {
        var_fv0 = var_fv1 - var_fa1;
        var_ft4 = var_fv0 * 28.0f;
    }

    switch (var_t4) {
        case 1:
            spC0 = 0;
            break;
        case 2:
            spC0 = 1;
            break;
        case 3:
            spC0 = 2;
            break;
        default:
            spC0 = 3;
            break;
    }

    gSPDisplayList(gfx++, D_8014940);

    var_s2 -= var_ft4;
    temp_ft2 -= ((var_fv0 * 32.0f) / 2);

    texturePtr = (u8*) D_4013DE0;

    for (i = 0; i < 2; i++) {
        if ((i == 0) & arg1) {
            var_s2 += (s32) (28.0f * var_fa1);
            var_t4 %= var_t3;
            var_t3 /= 10;
        } else {
            temp_lo = var_t4 / var_t3;

            var_s2 += (i == 0 && temp_lo == 1) * 5;

            if ((i == 0) && (temp_lo == 0)) {
                var_s2 += (s32) (28.0f * var_fv1);
                var_t4 %= var_t3;
                var_t3 /= 10;
            } else {
                gDPPipeSync(gfx++);

                gDPLoadTextureBlock(gfx++, texturePtr + ((temp_lo * 0x380) << 1), G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 32,
                                    0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);

                gSPTextureRectangle(gfx++, var_s2 << 2, temp_ft2 << 2, (s32) (var_s2 + 28.0f * var_fv1) << 2,
                                    (s32) (temp_ft2 + (32.0f * var_fv1)) << 2, 0, 0, 0, (s32) (1024.0f / var_fv1),
                                    (s32) (1024.0f / var_fv1));

                var_s2 += (s32) (28.0f * var_fv1) - (i == 0 && temp_lo == 1) * 5;
                var_t4 %= var_t3;
                var_t3 /= 10;
            }
        }
    }

    gDPPipeSync(gfx++);

    gDPLoadTextureBlock(gfx++, (D_4019020 + (spC0 * 0x320)), G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    if (arg1 == 0) {
        gfx = func_i3_80130D78(gfx, var_s2, temp_ft2);
    }

    if (arg1 == 1) {
        gfx = func_i3_801311FC(gfx, var_s2, temp_ft2, var_fv1);
    }

    return gfx;
}

Gfx* func_i3_80131A68(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 temp_a3;
    s32 temp_v0;

    if (D_800DCE44 == 2) {
        return gfx;
    }
    if (D_800DCE44 == 0x15) {
        return gfx;
    }
    if (gRacers[arg2].unk_04 & 0x02000000) {
        return gfx;
    }
    if ((D_i3_80140788[arg2] != 0) && (arg1 >= 2)) {
        return gfx;
    }

    temp_v0 = D_i3_8013F454[arg1][arg2][0];
    temp_a3 = D_i3_8013F454[arg1][arg2][1];

    gSPTextureRectangle(gfx++, temp_v0 << 2, temp_a3 << 2, (temp_v0 + 15) << 2, (temp_a3 + 11) << 2, 0, 0, 0, 1 << 12,
                        1 << 10);

    return gfx;
}

Gfx* func_i3_80131B90(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 temp_a3;
    s32 temp_v0;
    s32 var_t4;

    if (D_800DCE44 == 2) {
        return gfx;
    }
    if (D_800DCE44 == 0x15) {
        return gfx;
    }
    if (gRacers[arg2].unk_04 & 0x02000000) {
        return gfx;
    }
    if ((D_i3_80140788[arg2] != 0) && (arg1 >= 2)) {
        return gfx;
    }

    var_t4 = D_i3_8013F008[arg2];
    if (D_800CD00C < var_t4) {
        var_t4 = D_800CD00C;
    }

    temp_v0 = D_i3_8013F454[arg1][arg2][0];
    temp_a3 = D_i3_8013F454[arg1][arg2][1];

    temp_a3 += 14;

    gSPTextureRectangle(gfx++, temp_v0 << 2, temp_a3 << 2, (temp_v0 + 7) << 2, (temp_a3 + 11) << 2, 0, 0,
                        (var_t4 * 12) << 5, 1 << 12, 1 << 10);
    temp_v0 += 8;

    gSPTextureRectangle(gfx++, temp_v0 << 2, temp_a3 << 2, (temp_v0 + 7) << 2, (temp_a3 + 11) << 2, 0, 0, 0, 1 << 12,
                        1 << 10);
    temp_v0 += 8;

    gSPTextureRectangle(gfx++, temp_v0 << 2, temp_a3 << 2, (temp_v0 + 7) << 2, (temp_a3 + 11) << 2, 0, 0,
                        (D_800CD00C * 12) << 5, 1 << 12, 1 << 10);

    return gfx;
}

Gfx* func_i3_80133D4C(Gfx* gfx, s32 arg1, s32 arg2, f32 arg3);
Gfx* func_i3_801340F4(Gfx* gfx, s32 arg1, s32 arg2);
Gfx* func_i3_801345EC(Gfx* gfx, s32 arg1, s32 arg2);
Gfx* func_i3_801347AC(Gfx* gfx, s32 arg1, s32 arg2);
Gfx* func_i3_80134D0C(Gfx* gfx);
Gfx* func_i3_80134FFC(Gfx* gfx, s32 arg1, s32 arg2);
Gfx* func_i3_801353C0(Gfx* gfx, s32 arg1, s32 arg2);
Gfx* func_i3_80135598(Gfx* gfx, s32 arg1, s32 arg2);

extern u8 D_303C3F0[];
extern u8 D_303D1F0[];
extern u8 D_40131E0[];
extern u8 D_40134E0[];
extern u8 D_4019CA0[];

extern s32 D_800CD000;

Gfx* func_i3_80131DF4(Gfx* gfx) {

    gSPDisplayList(gfx++, D_8014940);

    switch (D_800CD000) {
        case 1:
            gDPPipeSync(gfx++);

            gDPLoadTextureBlock(gfx++, D_40131E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_8012FE8C(gfx, 0, 0);
            gfx = func_i3_801353C0(gfx, 0, 0);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gDPSetTextureFilter(gfx++, G_TF_POINT);

            gfx = func_i3_8012FF7C(gfx, 0, 0);
            gfx = func_i3_80133D4C(gfx, 0, 0, 1.0f);
            gfx = func_i3_80134D0C(gfx);
            gfx = func_i3_80134FFC(gfx, 0, 0);
            gfx = func_i3_80135598(gfx, 0, 0);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_40134E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_8013064C(gfx, 0, 0);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_80131A68(gfx, 0, 0);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_4019CA0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_80131B90(gfx, 0, 0);
            gfx = func_i3_80130304(gfx, 0, 0);
            gfx = func_i3_801340F4(gfx, 0, 0);
            gfx = func_i3_801347AC(gfx, 0, 0);
            gfx = func_i3_801345EC(gfx, 0, 0);
            break;
        case 2:
            gDPPipeSync(gfx++);
            gDPSetTextureFilter(gfx++, G_TF_POINT);

            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_8012FF7C(gfx, 1, 0);
            gfx = func_i3_8012FF7C(gfx, 1, 1);
            gfx = func_i3_80133D4C(gfx, 1, 0, 1.0f);
            gfx = func_i3_80133D4C(gfx, 1, 1, 1.0f);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_40134E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_8013064C(gfx, 1, 0);
            gfx = func_i3_8013064C(gfx, 1, 1);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_80131A68(gfx, 1, 0);
            gfx = func_i3_80131A68(gfx, 1, 1);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_4019CA0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_80131B90(gfx, 1, 0);
            gfx = func_i3_80131B90(gfx, 1, 1);
            gfx = func_i3_80130304(gfx, 1, 0);
            gfx = func_i3_80130304(gfx, 1, 1);
            gfx = func_i3_801340F4(gfx, 1, 0);
            gfx = func_i3_801340F4(gfx, 1, 1);
            break;
        case 3:
            gDPPipeSync(gfx++);
            gDPSetTextureFilter(gfx++, G_TF_POINT);
            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_8012FF7C(gfx, 2, 0);
            gfx = func_i3_8012FF7C(gfx, 2, 1);
            gfx = func_i3_8012FF7C(gfx, 2, 2);
            gfx = func_i3_80133D4C(gfx, 2, 0, 0.75f);
            gfx = func_i3_80133D4C(gfx, 2, 1, 0.75f);
            gfx = func_i3_80133D4C(gfx, 2, 2, 0.75f);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_40134E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_8013064C(gfx, 2, 0);
            gfx = func_i3_8013064C(gfx, 2, 1);
            gfx = func_i3_8013064C(gfx, 2, 2);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_80131A68(gfx, 2, 0);
            gfx = func_i3_80131A68(gfx, 2, 1);
            gfx = func_i3_80131A68(gfx, 2, 2);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_4019CA0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_80131B90(gfx, 2, 0);
            gfx = func_i3_80131B90(gfx, 2, 1);
            gfx = func_i3_80131B90(gfx, 2, 2);
            gfx = func_i3_80130304(gfx, 2, 0);
            gfx = func_i3_80130304(gfx, 2, 1);
            gfx = func_i3_80130304(gfx, 2, 2);
            gfx = func_i3_801340F4(gfx, 2, 0);
            gfx = func_i3_801340F4(gfx, 2, 1);
            gfx = func_i3_801340F4(gfx, 2, 2);
            break;
        case 4:
            gDPPipeSync(gfx++);
            gDPSetTextureFilter(gfx++, G_TF_POINT);

            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_8012FF7C(gfx, 3, 0);
            gfx = func_i3_8012FF7C(gfx, 3, 1);
            gfx = func_i3_8012FF7C(gfx, 3, 2);
            gfx = func_i3_8012FF7C(gfx, 3, 3);
            gfx = func_i3_80133D4C(gfx, 3, 0, 0.75f);
            gfx = func_i3_80133D4C(gfx, 3, 1, 0.75f);
            gfx = func_i3_80133D4C(gfx, 3, 2, 0.75f);
            gfx = func_i3_80133D4C(gfx, 3, 3, 0.75f);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_40134E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_8013064C(gfx, 3, 0);
            gfx = func_i3_8013064C(gfx, 3, 1);
            gfx = func_i3_8013064C(gfx, 3, 2);
            gfx = func_i3_8013064C(gfx, 3, 3);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_80131A68(gfx, 3, 0);
            gfx = func_i3_80131A68(gfx, 3, 1);
            gfx = func_i3_80131A68(gfx, 3, 2);
            gfx = func_i3_80131A68(gfx, 3, 3);

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_4019CA0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_80131B90(gfx, 3, 0);
            gfx = func_i3_80131B90(gfx, 3, 1);
            gfx = func_i3_80131B90(gfx, 3, 2);
            gfx = func_i3_80131B90(gfx, 3, 3);
            gfx = func_i3_80130304(gfx, 3, 0);
            gfx = func_i3_80130304(gfx, 3, 1);
            gfx = func_i3_80130304(gfx, 3, 2);
            gfx = func_i3_80130304(gfx, 3, 3);
            gfx = func_i3_801340F4(gfx, 3, 0);
            gfx = func_i3_801340F4(gfx, 3, 1);
            gfx = func_i3_801340F4(gfx, 3, 2);
            gfx = func_i3_801340F4(gfx, 3, 3);
            break;
    }

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

void func_i3_80132CD8(void) {
    s32 i;

    for (i = 0; i < D_800E5EC0; i++) {
        if (gRacers[i].unk_04 & 0x2000000) {
            D_i3_80141E30[i] = 1.0f;
        } else if (gRacers[i].unk_04 & 0x80000) {
            D_i3_80141E30[i] -= 0.01f;
            if (D_i3_80141E30[i] < 0.01f) {
                D_i3_80141E30[i] = 0.01f;
            }
        }
    }
}

extern unk_802C4920* D_800E5F40[];

void func_i3_80132D78(void) {
    s32 i;
    s32 var_v1;
    unk_802C4920* racer;

    for (i = 0; i < 6; i++) {
        racer = D_800E5F40[i];
        if (racer->unk_04 & 0x80000 && racer->unk_2AC < 6) {
            D_i3_8013F020[i][1] = 90;
            D_i3_8013F020[i][2] = racer->unk_2C8;
        }
    }

    for (i = 0, var_v1 = 0; i < 6; i++) {
        if (D_i3_8013F020[i][1] != 0) {
            if (D_i3_8013F020[i][1] != 0) {
                D_i3_8013F020[i][1]--;
            }
        } else {
            D_i3_8013F020[i][2] = var_v1;
            var_v1++;
        }
    }
}

extern u32 D_800CCFE0;
extern u8 D_401A120[];

void func_i3_80134CA0(void);

Gfx* func_i3_80132EEC(Gfx* gfx) {
    s32 i;
    s32 sp128;
    s32 var_s1;
    s32 var_s6;
    s32 var_s4;
    s32 var_s5;
    f32 var_fs1;
    unk_802C4920* racer;
    s32 index;

    if (D_i3_8013F000 != 0) {
        D_i3_8013F000--;
        func_i3_80134CA0();
    }

    gSPDisplayList(gfx++, D_8014940);

    func_i3_80132CD8();

    for (sp128 = 0, i = 0; i < 6; i++, sp128++) {
        if (D_800E5EC0 == i) {
            break;
        }

        if ((D_800DCE44 == 2) || (D_800DCE44 == 0x15)) {
            racer = gRacers;
        } else {
            racer = D_800E5F40[sp128];
        }
        if (i < 3) {
            var_fs1 = D_i3_80141E30[racer->unk_00];

            var_s1 = func_8006A9E0(32.0f * var_fs1);
            var_s6 = func_8006A9E0(32.0f * var_fs1);
            var_s4 = (0x20 - var_s1) / 2;
            var_s5 = (0x20 - var_s6) / 2;
        } else {
            var_fs1 = 0.75f;
            var_fs1 *= D_i3_80141E30[racer->unk_00];

            var_s1 = func_8006A9E0(32.0f * var_fs1);
            var_s6 = func_8006A9E0(32.0f * var_fs1);
            var_s4 = (24.0f - var_s1) / 2;
            var_s5 = (24.0f - var_s6) / 2;
        }
        index = racer->unk_2C8;
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, D_i3_8013F088[index], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, (var_s4 + 24) << 2, (var_s5 + D_i3_8013F4D4[i]) << 2,
                            func_8006A9E0(var_s4 + 24 + var_s1) << 2,
                            func_8006A9E0(var_s5 + D_i3_8013F4D4[i] + var_s6) << 2, 0, 0, 0,
                            func_8006A9E0(1024.0f / var_fs1), func_8006A9E0(1024.0f / var_fs1));

        if (D_800DCE44 != 1) {
            break;
        }

        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_i3_8013F104[sp128], G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 6, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gfx++, 24 << 2, D_i3_8013F4EC[i] << 2, (24 + 16) << 2, (D_i3_8013F4EC[i] + 6) << 2, 0, 0, 0,
                            func_8006A9E0(1024.0f), func_8006A9E0(1024.0f));

        if ((gRacers[0].unk_2AC - 1 == i) && ((D_800CCFE0 % 20) >= 5)) {
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_401A120, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (var_s4 + 24) << 2, (var_s5 + D_i3_8013F4D4[i]) << 2,
                                func_8006A9E0(var_s4 + 24 + var_s1) << 2,
                                func_8006A9E0(var_s5 + D_i3_8013F4D4[i] + var_s6) << 2, 0, 0, 0,
                                (s32) (1024.0f / var_fs1), (s32) (1024.0f / var_fs1));
        }
    }
    return gfx;
}

Gfx* func_i3_801335F0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    s32 var_s0 = 0;
    s32 pad;
    s32 sp4C;

    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    if (arg1 >= (3600000 - 1)) {
        arg1 = (3600000 - 1);
    }
    sp4C = arg1 / 60000;

    if (sp4C < 0xA) {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 0, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp4C, arg4);
        var_s0 += 8;
    } else {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp4C / 10, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp4C % 10, arg4);
        var_s0 += 8;
    }
    arg1 -= (sp4C * 60000);
    sp4C = arg1 / 1000;

    gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 0xA, arg4);
    var_s0 += 8;
    if (sp4C < 10) {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 0, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp4C, arg4);
        var_s0 += 8;
    } else {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp4C / 10, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp4C % 10, arg4);
        var_s0 += 8;
    }

    arg1 -= sp4C * 1000;
    sp4C = arg1 / 10;

    gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 0xB, arg4);
    var_s0 += 8;
    if (sp4C < 10) {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 0, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp4C, arg4);
    } else {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp4C / 10, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp4C % 10, arg4);
    }
    return gfx;
}

Gfx* func_i3_80133944(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    s32 var_s0 = 0;
    s32 pad;
    s32 sp5C;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    if (arg1 >= (3600000 - 1)) {
        arg1 = (3600000 - 1);
    }
    if (arg1 <= -(3600000 - 1)) {
        arg1 = -(3600000 - 1);
    }
    if (arg1 < -4) {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 13, arg4);
        arg1 = -arg1;
    } else {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 12, arg4);
    }
    if (arg1 < 0) {
        arg1 = -arg1;
    }

    var_s0 += 8;

    sp5C = arg1 / 60000;

    if (sp5C < 10) {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 0, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp5C, arg4);
        var_s0 += 8;
    } else {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp5C / 10, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp5C % 10, arg4);
        var_s0 += 8;
    }

    arg1 -= sp5C * 60000;
    sp5C = arg1 / 1000;

    gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 10, arg4);

    var_s0 += 8;

    if (sp5C < 10) {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 0, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp5C, arg4);
        var_s0 += 8;
    } else {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp5C / 10, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp5C % 10, arg4);
        var_s0 += 8;
    }

    arg1 -= sp5C * 1000;
    sp5C = arg1 / 10;

    gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 11, arg4);

    var_s0 += 8;

    if (sp5C < 10) {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, 0, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp5C, arg4);
    } else {
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp5C / 10, arg4);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, arg2 + var_s0, arg3, sp5C % 10, arg4);
    }
    return gfx;
}

extern unk_800F5DF0* D_800F5E90;

Gfx* func_i3_80133D4C(Gfx* gfx, s32 arg1, s32 arg2, f32 arg3) {
    unk_802C4920* var_a2;
    s32 i;
    s32 var_v1;
    s32 temp_a3;

    if (D_i3_80141EA8[arg2].unk_08 != 0) {
        D_i3_80141EA8[arg2].unk_08--;
    } else {
        return gfx;
    }

    if (D_800DCE44 == 2) {
        return gfx;
    }
    if ((D_800DCE44 == 0xE) && (D_800F5E90 == NULL)) {
        return gfx;
    }

    if (D_i3_80141EA8[arg2].unk_08 == 0x59) {

        temp_a3 = D_i3_8013F008[arg2] - 1;

        if (gRacers[arg2].unk_2AC == 1) {
            var_a2 = D_800E5F40[1];
        } else {
            var_a2 = D_800E5F40[0];
        }

        D_i3_80141FD8[arg2] = 0;

        if (D_800DCE44 == 0xE) {
            for (i = 0; i < temp_a3; i++) {
                D_i3_80141FD8[arg2] += D_800F5E90->unk_04->unk_0008[i];
            }
        } else {
            for (i = 0; i < temp_a3; i++) {
                D_i3_80141FD8[arg2] += var_a2->unk_290[i];
            }
        }

        var_v1 = 0;
        for (i = 0; i < temp_a3; i++) {
            var_v1 += gRacers[arg2].unk_290[i];
        }

        D_i3_80141FC8[arg2] = var_v1 - D_i3_80141FD8[arg2];

        if (D_i3_80141FC8[arg2] >= 0) {
            D_i3_80141FC8[arg2] += 5;
        } else {
            D_i3_80141FC8[arg2] -= 5;
        }
    }
    if ((D_i3_80141EA8[arg2].unk_08 % 20) >= 5) {
        gfx = func_i3_80133944(gfx, D_i3_80141FC8[arg2], D_i3_8013F504[arg1][arg2][0], D_i3_8013F504[arg1][arg2][1],
                               arg3);
    }

    return gfx;
}

extern u8 D_4011DA0[];
extern u8 D_40131C0[];
extern s32 D_800F80A8[];

Gfx* func_i3_801340F4(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 i;
    f32 var_fv1;
    s32 temp_t2;
    s32 temp;
    s32 sp44;
    s32 pad[3];

    if (D_800F80A8[arg2] < 0x64) {
        if (D_i3_8013F078[arg2] != 0) {
            func_800BA3E4(arg2, 3);
            D_i3_8013F078[arg2] = 0;
        }
        return gfx;
    }
    if (D_800DCE5C != 0) {
        return gfx;
    }
    switch (arg1) {
        case 0:
        case 1:
            var_fv1 = 1.0f;
            sp44 = 111;
            break;
        case 2:
        case 3:
            var_fv1 = 0.75f;
            sp44 = 112.0f * var_fv1;
            break;
    }

    if (D_i3_8013F078[arg2] == 0) {
        func_800BA2F0(arg2, 3);
        D_i3_8013F078[arg2] = 1;
    }
    if ((D_800CCFE0 % 20) >= 5) {
        return gfx;
    }

    temp_t2 = D_i3_8013F584[arg1][arg2][0];
    temp = D_i3_8013F584[arg1][arg2][1];

    gSPDisplayList(gfx++, D_80149D0);
    gDPLoadTLUT_pal256(gfx++, D_40131C0);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 23; i++) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, (D_4011DA0 + i * 0xE0), G_IM_FMT_CI, G_IM_SIZ_8b, 112, 2, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, temp_t2 << 2, (s32) (temp + (i * 2 * var_fv1)) << 2, (temp_t2 + sp44) << 2,
                            (s32) (temp + ((i * 2 + 1) * var_fv1)) << 2, 0, 0, 0, (s32) (4096.0f / var_fv1),
                            (s32) (1024.0f / var_fv1));
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return gfx;
}

void func_i3_80134548(void) {
    s32 i;

    D_i3_8013F000 = 3;

    for (i = 0; i < ARRAY_COUNT(D_i3_80141E30); i++) {
        D_i3_80141E30[i] = 1.0f;
    }
}

extern s32 D_i2_8010D768;

void func_i3_80134598(void) {
    D_i2_8010D768 = 0;
}

extern s32 D_8010D76C;
extern s16 D_800E5ED8[];

void func_i3_801345A4(void) {
    D_8010D76C = D_800E5ED8[0] - 1;
    D_i2_8010D768 = 90;
}

void func_i3_801345C8(void) {
    D_8010D76C = D_800E5ED8[0] + 1;
    D_i2_8010D768 = 90;
}

extern s16 D_800E5FD2;
extern u8 D_401A9A0[];

Gfx* func_i3_801345EC(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 i;
    s32 var_v0;
    s32 var_a2;

    if ((D_800DCE44 != 1) && (D_800DCE44 != 2) && (D_800DCE44 != 0x15)) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_80149D0);

    gDPLoadTextureBlock(gfx++, D_401A9A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    var_a2 = 0x1D0;
    i = D_800E5FD2;
    while (i != 0) {
        var_v0 = 1140;
        while (var_v0 > 940) {
            gSPTextureRectangle(gfx++, var_v0, var_a2, var_v0 + 28, var_a2 + 28, 0, 0, 0, 1 << 12, 1 << 10);

            var_v0 -= 40;
            if (--i == 0) {
                break;
            }
        }
        var_a2 -= 0x24;
    }

    return gfx;
}

extern u8 D_401A920[];

Gfx* func_i3_801347AC(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 i;
    s32 var_a1;
    s32 var_v0;
    s32 var_v1;

    if (D_800DCE44 != 1) {
        return gfx;
    }

    if (D_i2_8010D768 > 0) {
        D_i2_8010D768--;
    }
    if (D_i2_8010D768 != 0) {
        if (D_800E5ED8[arg2] < D_8010D76C) {
            var_a1 = D_800E5ED8[arg2];
        } else {
            var_a1 = D_8010D76C;
        }
    } else {
        var_a1 = D_800E5ED8[arg2];
    }

    var_v0 = D_i3_8013F604[arg1][arg2][0];
    var_v1 = D_i3_8013F604[arg1][arg2][1];

    gSPDisplayList(gfx++, D_80149D0);
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, D_401A920, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < var_a1; i++) {
        gSPTextureRectangle(gfx++, var_v0 << 2, var_v1 << 2, (var_v0 + 7) << 2, (var_v1 + 7) << 2, 0, 0, 0, 1 << 12,
                            1 << 10);
        var_v0 += 10;
        if ((i % 5) == 4) {
            var_v0 -= 50;
            var_v1 += 9;
        }
    }

    if ((D_i2_8010D768 != 0) && ((D_800CCFE0 % 20) >= 5)) {
        gSPTextureRectangle(gfx++, var_v0 << 2, var_v1 << 2, (var_v0 + 7) << 2, (var_v1 + 7) << 2, 0, 0, 0, 1 << 12,
                            1 << 10);
    }

    return gfx;
}

extern u8 D_2800[];

void func_i3_80134C24(s32 arg0) {
    s32 temp_v1;
    s32 sp18;
    s32 temp;
    s32 temp2;

    // FAKE!!
    sp18 = D_i3_8013F684[arg0];

    temp_v1 = sp18 << 0xB;
    temp = (func_80076BB8(4) + SEGMENT_OFFSET(D_401AA20)) + temp_v1;

    temp_v1 = sp18 << 0xB;
    temp2 = (SEGMENT_ROM_START(segment_2747F0) + SEGMENT_OFFSET(D_2800)) + temp_v1;

    func_80073FA0(temp2, temp, 0x800);
}

void func_i3_80134CA0(void) {
    s32 i;

    for (i = 0; i < D_800E5EC0; i++) {
        if ((s8) gRacers[i].unk_164 >= 2) {
            func_i3_80134C24(gRacers[i].unk_2C8);
        }
    }
}

extern s32 D_800E5FDC;
extern s16 D_800E5FE0;

extern u8 D_F243290[];

Gfx* func_i3_80134D0C(Gfx* gfx) {
    s32 xl;
    s32 yl;

    if (D_800DCE44 != 2) {
        return gfx;
    }
    if (D_800E5FE0 != 0) {
        func_800BA8D8(0x38);
        D_800E5FE0 = 0;
        D_i3_8013EFF0 = 180;
    }

    if (D_i3_8013EFF0 != 0) {
        if (D_800DCE5C == 0) {
            D_i3_8013EFF0--;
        }
        if ((D_i3_8013EFF0 % 20) >= 5) {
            gfx = func_i3_801335F0(gfx, D_800E5FDC + 5, 0x80, 0x24, 1.0f);
        }
    } else {
        if (D_800E5FDC == (600000 - 1)) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
            gfx = func_i3_8012F8E4(gfx, 0x80, 0x24);
        } else {
            gfx = func_i3_801335F0(gfx, D_800E5FDC + 5, 0x80, 0x24, 1.0f);
        }
    }

    xl = 128;
    yl = 20;

    gDPLoadTextureBlock(gfx++, func_800783AC(D_F243290), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gfx++, xl << 2, yl << 2, (xl + 16) << 2, (yl + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    xl = 144;
    yl = 20;

    gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, xl << 2, yl << 2, (xl + 16) << 2, (yl + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

Gfx* func_i3_80134FFC(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 var_s0 = 0;
    s32 var_s1;
    s32 var_t0;
    s32 pad[2];
    s32 sp50;
    s32 var_s2;

    if (D_800DCE44 != 0x15) {
        return gfx;
    }

    var_s2 = gRacers[arg2].unk_2A0 + 5;
    var_t0 = D_i3_8013F11C[arg1][arg2][0];
    var_s1 = D_i3_8013F11C[arg1][arg2][1];

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    if (var_s2 >= (3600000 - 1)) {
        var_s2 = (3600000 - 1);
    }
    sp50 = var_s2 / 60000;

    if (sp50 < 0xA) {
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, 0, 1.0f);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, sp50, 1.0f);
        var_s0 += 8;
    } else {
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, sp50 / 10, 1.0f);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, sp50 % 10, 1.0f);
        var_s0 += 8;
    }

    var_s2 -= sp50 * 60000;
    sp50 = var_s2 / 1000;

    gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, 0xA, 1.0f);
    var_s0 += 8;
    if (sp50 < 0xA) {
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, 0, 1.0f);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, sp50, 1.0f);
        var_s0 += 8;
    } else {
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, sp50 / 10, 1.0f);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, sp50 % 10, 1.0f);
        var_s0 += 8;
    }
    var_s2 -= sp50 * 1000;
    sp50 = var_s2 / 10;
    gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, 0xB, 1.0f);
    var_s0 += 8;

    if (sp50 < 0xA) {
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, 0, 1.0f);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, sp50, 1.0f);
    } else {
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, sp50 / 10, 1.0f);
        var_s0 += 8;
        gfx = func_i3_8012EFC0(gfx, var_t0 + var_s0, var_s1, sp50 % 10, 1.0f);
    }

    return gfx;
}

Gfx* func_i3_801353C0(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 xl;
    s32 yl;

    if (D_800DCE44 != 0x15) {
        return gfx;
    }

    xl = D_i3_8013F19C[arg1][arg2][0];
    yl = D_i3_8013F19C[arg1][arg2][1];
    yl += 16;

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    gDPLoadTextureBlock(gfx++, func_800783AC(D_F243290), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gfx++, xl << 2, yl << 2, (xl + 16) << 2, (yl + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

extern unk_800F8510* D_800F8510;

Gfx* func_i3_80135598(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 xl;
    s32 yl;

    if (D_800DCE44 != 0x15) {
        return gfx;
    }

    xl = D_i3_8013F19C[arg1][arg2][0] + 32;
    yl = D_i3_8013F19C[arg1][arg2][1] + 16;

    if (D_800F8510->unk_20[0] == (3600000 - 1)) {
        gDPPipeSync(gfx++);
        gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE,
                          0, TEXEL0, 0);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = func_i3_8012F8E4(gfx, xl, yl);
    } else {
        gfx = func_i3_801335F0(gfx, D_800F8510->unk_20[0] + 5, xl, yl, 1.0f);
    }

    return gfx;
}
