#include "global.h"
#include "fzxthread.h"

bool func_8006D3F0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x16)) {
        return true;
    }
    return false;
}

typedef struct unk_802D3978 {
    s32 unk_00;
    Vec3f unk_04;
    s8 unk_10[0x4];
} unk_802D3978; // size = 0x14

extern unk_802D3978 D_802D3978[];

void func_8006D414(void) {
    s32 i;

    for (i = 0; i < 48; i++) {
        D_802D3978[i].unk_00 = 1;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8006D448.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8006DAAC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8006E478.s")

extern unk_800F8510* D_800F8510;

typedef struct unk_802A9FC0 {
    s8 unk_00[0x14];
    Vec3f unk_14;
    s8 unk_20[0x40];
} unk_802A9FC0; // size = 0x60

typedef struct unk_802D08E0 {
    Vec3f unk_00;
    Mtx3F unk_0C;
    f32 unk_30;
    unk_802A9FC0* unk_34;
} unk_802D08E0; // size = 0x38

extern unk_802A9FC0 D_802A9FC0[];
extern unk_802D1B60 D_802D1B60;
extern unk_802D08E0 D_802D08E0[];
extern s16 D_8022F0C0[];
extern s32 D_800CD180;
extern s32 D_800F8518;

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8006EC7C.s")

extern s32 D_800E32C8;
extern Gfx D_8017220[];
extern Gfx D_80172A0[];

Gfx* func_8006F3D8(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    if (D_800E32C8 != 5) {
        gSPDisplayList(gfx++, D_8017220);
    }
    D_800E32C8 = 5;
    gSPDisplayList(gfx++, D_80172A0);

    return gfx;
}

extern Gfx D_8018618[];

Gfx* func_8006F444(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    gSPDisplayList(gfx++, D_8018618);

    return gfx;
}

extern Gfx D_801A1F8[];
extern Gfx D_801A278[];

Gfx* func_8006F478(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    if (D_800E32C8 != 7) {
        gSPDisplayList(gfx++, D_801A1F8);
    }
    D_800E32C8 = 7;
    gSPDisplayList(gfx++, D_801A278);

    return gfx;
}

extern Gfx D_801AEF8[];

Gfx* func_8006F4E4(Gfx* gfx) {

    gSPClearGeometryMode(gfx++, G_CULL_BACK);
    gSPDisplayList(gfx++, D_801AEF8);

    return gfx;
}

extern Gfx D_801D030[];
extern Gfx D_801D0B0[];

Gfx* func_8006F514(Gfx* gfx) {

    gSPClearGeometryMode(gfx++, G_CULL_BACK);
    if (D_800E32C8 != 9) {
        gSPDisplayList(gfx++, D_801D030);
    }
    D_800E32C8 = 9;
    gSPDisplayList(gfx++, D_801D0B0);

    return gfx;
}

extern Gfx D_801E178[];
extern Gfx D_801E1F8[];

Gfx* func_8006F57C(Gfx* gfx) {

    gSPClearGeometryMode(gfx++, G_CULL_BACK);
    if (D_800E32C8 != 10) {
        gSPDisplayList(gfx++, D_801E178);
    }
    D_800E32C8 = 10;
    gSPDisplayList(gfx++, D_801E1F8);

    return gfx;
}

extern Mtx D_102C5E8;
extern Gfx D_3000688[];
extern Gfx D_30006D0[];
extern Gfx D_801EAA8[];

Gfx* func_8006F5E4(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    if (D_800E32C8 != 11) {
        gSPDisplayList(gfx++, D_3000688);
    }
    D_800E32C8 = 11;

    gSPDisplayList(gfx++, D_30006D0);

    gSPMatrix(gfx++, (uintptr_t) &D_102C5E8 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EAA8);

    return gfx;
}

extern Mtx D_102C628;

Gfx* func_8006F68C(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    gSPDisplayList(gfx++, D_30006D0);

    gSPMatrix(gfx++, (uintptr_t) &D_102C628 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EAA8);

    return gfx;
}

extern Mtx D_102C668;
extern Gfx D_3000590[];
extern Gfx D_30005D8[];
extern Gfx D_801EBF8[];

Gfx* func_8006F6FC(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    if (D_800E32C8 != 12) {
        gSPDisplayList(gfx++, D_3000590);
    }
    D_800E32C8 = 12;

    gSPDisplayList(gfx++, D_30005D8);

    gSPMatrix(gfx++, (uintptr_t) &D_102C668 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EBF8);

    return gfx;
}

extern u16 D_8014A20[];
extern Gfx D_801ED28[];

Gfx* func_8006F7A4(Gfx* gfx) {

    if (D_800E32C8 != 0) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_8014A20, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_801ED28);
    D_800E32C8 = 0;
    return gfx;
}

extern Gfx D_801EEA0[];
extern u16 D_801F018[];

Gfx* func_8006F89C(Gfx* gfx) {

    if (D_800E32C8 != 1) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_801F018, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_801EEA0);
    D_800E32C8 = 1;
    return gfx;
}

extern Gfx D_801F818[];
extern u16 D_801F8C8[];

Gfx* func_8006F998(Gfx* gfx) {

    if (D_800E32C8 != 2) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_801F8C8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_801F818);
    D_800E32C8 = 2;
    return gfx;
}

extern Gfx D_80200C8[];
extern u16 D_8020208[];

Gfx* func_8006FA94(Gfx* gfx) {

    if (D_800E32C8 != 3) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_8020208, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_80200C8);
    D_800E32C8 = 3;
    return gfx;
}

extern Gfx D_8021208[];
extern u16 D_8021380[];

Gfx* func_8006FB90(Gfx* gfx) {

    if (D_800E32C8 != 4) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_8021380, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_8021208);
    D_800E32C8 = 4;
    return gfx;
}

void func_8006FC8C(unk_8006FC8C* arg0, f32 arg1, Vec3f* arg2) {
    s32 pad;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 temp_fv0;
    Mtx3F sp28;

    temp_fv0 = func_8009E108(arg0, arg1, &sp58);

    sp54 = ((arg0->unk_34->unk_18 - arg0->unk_18) * temp_fv0) + arg0->unk_18;
    sp50 = ((arg0->unk_34->unk_1C - arg0->unk_1C) * temp_fv0) + arg0->unk_1C;

    func_8009E85C(arg0, arg1, &sp28, temp_fv0);
    func_8009E6F0(arg0, arg1, arg2);
    sp58 = (sp54 - sp50) / 2.0f;

    arg2->x += sp58 * sp28.xz;
    arg2->y += sp58 * sp28.yz;
    arg2->z += sp58 * sp28.zz;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8006FD7C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8006FE90.s")

extern s32 D_802D2D78[][4];
extern unk_802D3E38 D_802D3E38[];

s32 func_80074BB4(Vec3f* arg0, f32 arg1);

extern f32 D_800CD1DC;
extern f32 D_800CD1E0;
extern f32 D_800CD1E4;

void func_8006FF90(s32 arg0, unk_8006FF90_arg_1* arg1, unk_8006FF90_arg_2** arg2) {
    unk_8006FF90_arg_2* temp_s0;
    f32 sp78;
    f32 sp74;
    s32 pad;
    f32 sp6C;
    Vec3f sp60;
    Vec3f sp54;
    Mtx3F sp30;
    unk_8006FC8C* sp2C;

    sp78 = arg1->unk_08;
    sp2C = &D_800F8510->unk_10[arg1->unk_00];
    temp_s0 = *arg2;

    sp74 = func_8009E538(sp2C, sp78, &sp54);
    func_8009E85C(sp2C, arg1->unk_08, &sp30, func_8009E108(sp2C, arg1->unk_08, &sp6C));
    func_8006FC8C(sp2C, arg1->unk_08, &sp60);
    sp60.x += 5.0f * sp30.xy;
    sp60.y += 5.0f * sp30.yy;
    sp60.z += 5.0f * sp30.zy;
    temp_s0->unk_00 = func_8006A9E0(((arg1->unk_10 * sp30.xz) + sp60.x) + (sp30.xx * D_800CD1E4));
    temp_s0->unk_02 = func_8006A9E0(((arg1->unk_10 * sp30.yz) + sp60.y) + (sp30.yx * D_800CD1E4));
    temp_s0->unk_04 = func_8006A9E0(((arg1->unk_10 * sp30.zz) + sp60.z) + (sp30.zx * D_800CD1E4));
    temp_s0->unk_08 = 0x400;
    temp_s0->unk_0A = 0x200;
    temp_s0++;
    temp_s0->unk_00 = func_8006A9E0(((arg1->unk_10 + D_800CD1E0) * sp30.xz) + sp60.x);
    temp_s0->unk_02 = func_8006A9E0(((arg1->unk_10 + D_800CD1E0) * sp30.yz) + sp60.y);
    temp_s0->unk_04 = func_8006A9E0(((arg1->unk_10 + D_800CD1E0) * sp30.zz) + sp60.z);
    temp_s0->unk_08 = 0;
    temp_s0->unk_0A = 0;
    temp_s0++;
    temp_s0->unk_00 = func_8006A9E0(((arg1->unk_10 - D_800CD1E0) * sp30.xz) + sp60.x);
    temp_s0->unk_02 = func_8006A9E0(((arg1->unk_10 - D_800CD1E0) * sp30.yz) + sp60.y);
    temp_s0->unk_04 = func_8006A9E0(((arg1->unk_10 - D_800CD1E0) * sp30.zz) + sp60.z);
    temp_s0->unk_08 = 0x800;
    temp_s0->unk_0A = 0;

    sp78 += D_800CD1DC / sp74;
    D_802D3E38[arg0].unk_08 = sp78;
    D_802D3E38[arg0].unk_0C.x = arg1->unk_10 - D_800CD1E0;
    D_802D3E38[arg0].unk_18.x = arg1->unk_10 + D_800CD1E0;

    sp60.x = sp60.x + sp30.xx * D_800CD1DC;
    sp60.y = sp60.y + sp30.yx * D_800CD1DC;
    sp60.z = sp60.z + sp30.zx * D_800CD1DC;

    temp_s0++;
    temp_s0->unk_00 = func_8006A9E0((arg1->unk_10 * sp30.xz) + sp60.x);
    temp_s0->unk_02 = func_8006A9E0((arg1->unk_10 * sp30.yz) + sp60.y);
    temp_s0->unk_04 = func_8006A9E0((arg1->unk_10 * sp30.zz) + sp60.z);
    temp_s0->unk_08 = 0x400;
    temp_s0->unk_0A = 0x800;
    temp_s0++;
    temp_s0->unk_00 = func_8006A9E0((((arg1->unk_10 + D_800CD1E0) * sp30.xz) + sp60.x) - (sp30.xx * D_800CD1E4));
    temp_s0->unk_02 = func_8006A9E0((((arg1->unk_10 + D_800CD1E0) * sp30.yz) + sp60.y) - (sp30.yx * D_800CD1E4));
    temp_s0->unk_04 = func_8006A9E0((((arg1->unk_10 + D_800CD1E0) * sp30.zz) + sp60.z) - (sp30.zx * D_800CD1E4));
    temp_s0->unk_08 = 0;
    temp_s0->unk_0A = 0x600;
    temp_s0++;
    temp_s0->unk_00 = func_8006A9E0((((arg1->unk_10 - D_800CD1E0) * sp30.xz) + sp60.x) - (sp30.xx * D_800CD1E4));
    temp_s0->unk_02 = func_8006A9E0((((arg1->unk_10 - D_800CD1E0) * sp30.yz) + sp60.y) - (sp30.yx * D_800CD1E4));
    temp_s0->unk_04 = func_8006A9E0((((arg1->unk_10 - D_800CD1E0) * sp30.zz) + sp60.z) - (sp30.zx * D_800CD1E4));
    temp_s0->unk_08 = 0x800;
    temp_s0->unk_0A = 0x600;
    D_802D2D78[arg0][0] = arg1->unk_04;
    temp_s0++;
    *arg2 = temp_s0;
}

void func_8007049C(s32 arg0, unk_8006FF90_arg_1* arg1, unk_8006FF90_arg_2** arg2) {
    unk_8006FF90_arg_2* temp_s0;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    Vec3f spD4;
    Vec3f spC8;
    Vec3f spBC;
    Vec3f spB0;
    Mtx3F sp8C;
    unk_8006FC8C* sp88;
    s32 pad;
    MtxF sp44;

    spF0 = arg1->unk_08;
    sp88 = &D_800F8510->unk_10[arg1->unk_00];
    temp_s0 = *arg2;

    spEC = func_8009E538(sp88, spF0, &spBC);
    spE8 = func_8009E108(sp88, arg1->unk_08, &spE4);

    func_8009E85C(sp88, arg1->unk_08, &sp8C, spE8);

    spE0 = sp88->unk_18 + sp88->unk_1C;
    spE0 = (((sp88->unk_34->unk_18 + sp88->unk_34->unk_1C) - spE0) * spE8) + spE0;
    spE0 /= 2;

    func_8006FC8C(sp88, arg1->unk_08, &spC8);
    func_8006C520(NULL, &sp44, 1.0f, (arg1->unk_10 * 4096.0f) / 360.0f, sp8C.xx, sp8C.yx, sp8C.zx, 0.0f, 0.0f, 0.0f);
    spBC.x = sp44.m[0][0] * sp8C.xz + sp44.m[1][0] * sp8C.yz + sp44.m[2][0] * sp8C.zz;
    spBC.y = sp44.m[0][1] * sp8C.xz + sp44.m[1][1] * sp8C.yz + sp44.m[2][1] * sp8C.zz;
    spBC.z = sp44.m[0][2] * sp8C.xz + sp44.m[1][2] * sp8C.yz + sp44.m[2][2] * sp8C.zz;
    func_80074BB4(&spBC, 1.0f);
    sp8C.xz = spBC.x;
    sp8C.yz = spBC.y;
    sp8C.zz = spBC.z;
    spBC.x = sp44.m[0][0] * sp8C.xy + sp44.m[1][0] * sp8C.yy + sp44.m[2][0] * sp8C.zy;
    spBC.y = sp44.m[0][1] * sp8C.xy + sp44.m[1][1] * sp8C.yy + sp44.m[2][1] * sp8C.zy;
    spBC.z = sp44.m[0][2] * sp8C.xy + sp44.m[1][2] * sp8C.yy + sp44.m[2][2] * sp8C.zy;
    func_80074BB4(&spBC, 1.0f);
    sp8C.xy = spBC.x;
    sp8C.yy = spBC.y;
    sp8C.zy = spBC.z;
    spD4 = spC8;
    spC8.x += (5.0f - spE0) * spBC.x;
    spC8.y += (5.0f - spE0) * spBC.y;
    spC8.z += (5.0f - spE0) * spBC.z;

    temp_s0->unk_00 = func_8006A9E0((sp8C.xx * 50.0f) + spC8.x);
    temp_s0->unk_02 = func_8006A9E0((sp8C.yx * 50.0f) + spC8.y);
    temp_s0->unk_04 = func_8006A9E0((sp8C.zx * 50.0f) + spC8.z);
    temp_s0->unk_08 = 0x400;
    temp_s0->unk_0A = 0x200;
    temp_s0++;
    temp_s0->unk_00 = func_8006A9E0((sp8C.xz * 50.0f) + spC8.x);
    temp_s0->unk_02 = func_8006A9E0((sp8C.yz * 50.0f) + spC8.y);
    temp_s0->unk_04 = func_8006A9E0((sp8C.zz * 50.0f) + spC8.z);
    temp_s0->unk_08 = 0;
    temp_s0->unk_0A = 0;
    spB0.x = temp_s0->unk_00 - spD4.x;
    spB0.y = temp_s0->unk_02 - spD4.y;
    spB0.z = temp_s0->unk_04 - spD4.z;
    func_80074BB4(&spB0, 1.0f);

    D_802D3E38[arg0].unk_0C = spB0;
    temp_s0++;

    temp_s0->unk_00 = func_8006A9E0(spC8.x - (sp8C.xz * 50.0f));
    temp_s0->unk_02 = func_8006A9E0(spC8.y - (sp8C.yz * 50.0f));
    temp_s0->unk_04 = func_8006A9E0(spC8.z - (sp8C.zz * 50.0f));
    temp_s0->unk_08 = 0x800;
    temp_s0->unk_0A = 0;
    spB0.x = temp_s0->unk_00 - spD4.x;
    spB0.y = temp_s0->unk_02 - spD4.y;
    spB0.z = temp_s0->unk_04 - spD4.z;
    func_80074BB4(&spB0, 1.0f);
    D_802D3E38[arg0].unk_18 = spB0;
    D_802D3E38[arg0].unk_04 = spF0;
    spF0 += (150.0f / spEC);
    D_802D3E38[arg0].unk_08 = spF0;
    spC8.x = spC8.x + sp8C.xx * 150.0f;
    spC8.y = spC8.y + sp8C.yx * 150.0f;
    spC8.z = spC8.z + sp8C.zx * 150.0f;

    temp_s0++;
    temp_s0->unk_00 = func_8006A9E0(spC8.x);
    temp_s0->unk_02 = func_8006A9E0(spC8.y);
    temp_s0->unk_04 = func_8006A9E0(spC8.z);
    temp_s0->unk_08 = 0x400;
    temp_s0->unk_0A = 0x800;
    temp_s0++;
    temp_s0->unk_00 = func_8006A9E0(((sp8C.xz * 50.0f) + spC8.x) - (sp8C.xx * 50.0f));
    temp_s0->unk_02 = func_8006A9E0(((sp8C.yz * 50.0f) + spC8.y) - (sp8C.yx * 50.0f));
    temp_s0->unk_04 = func_8006A9E0(((sp8C.zz * 50.0f) + spC8.z) - (sp8C.zx * 50.0f));
    temp_s0->unk_08 = 0;
    temp_s0->unk_0A = 0x600;
    temp_s0++;
    temp_s0->unk_00 = func_8006A9E0((spC8.x - (sp8C.xz * 50.0f)) - (sp8C.xx * 50.0f));
    temp_s0->unk_02 = func_8006A9E0((spC8.y - (sp8C.yz * 50.0f)) - (sp8C.yx * 50.0f));
    temp_s0->unk_04 = func_8006A9E0((spC8.z - (sp8C.zz * 50.0f)) - (sp8C.zx * 50.0f));
    temp_s0->unk_08 = 0x800;
    temp_s0->unk_0A = 0x600;
    D_802D2D78[arg0][0] = arg1->unk_04;
    temp_s0++;
    *arg2 = temp_s0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80070B5C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071260.s")

void func_80071790(s32, s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071790.s")

void func_800718D0(s32, s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_800718D0.s")

void func_80071A58(s32, s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071A58.s")

void func_80071BE4(s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071BE4.s")

extern unk_8010B7B0 D_8010B7B0;
void func_8007243C(s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8007243C.s")

void func_80072758(s32, s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80072758.s")

void func_80072BB0(s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80072BB0.s")

void func_80072D00(s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80072D00.s")

void func_80072ECC(s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80072ECC.s")

void func_800730A4(s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_800730A4.s")

void func_8007327C(s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8007327C.s")

void func_80073510(s32 arg0) {
    func_80072D00(arg0);
    func_80072ECC(arg0);
    func_800730A4(arg0);
    func_8007327C(arg0);
}

void func_80073548(s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80073548.s")

extern s32 D_802CDFD0;

void func_80073894(s32 arg0) {
    if (D_800CD180 != 0) {
        if (D_802CDFD0 < 4) {
            return;
        }
    } else if (D_8010B7B0.unk_000[1] < 4) {
        return;
    }

    D_802D1B60.unk_08 = 0;
    D_802D1B60.unk_0C = 0;
    D_802D1B60.unk_04 = 0;
    func_80071BE4(arg0);
    func_8007243C(arg0);
    func_80072BB0(arg0);
    func_80073510(arg0);
    func_80073548(arg0);
}

extern s32 D_800CD180;
extern s32 D_802D2D74;

void func_8007392C(s32 arg0) {
    s32 i;

    if (D_800CD180 != 0) {
        if (D_802CDFD0 < 4) {
            return;
        }
    } else if (D_8010B7B0.unk_000[1] < 4) {
        return;
    }

    D_802D2D74 = 0;

    for (i = 0; i < D_802A6B40[arg0].unk_08; i++) {
        func_80071A58(arg0, i);
        func_800718D0(arg0, i);
        func_80071790(arg0, i);
        func_80072758(arg0, i);
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80073A04.s")

extern OSMesgQueue D_800DCA68;
extern OSIoMesg D_800DCCA8;
extern OSPiHandle* D_800DCCDC;

void func_80073E28(void* arg0, void* arg1, size_t arg2) {
    osInvalDCache(osPhysicalToVirtual(arg1), arg2);
    D_800DCCA8.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800DCCA8.hdr.retQueue = &D_800DCA68;
    D_800DCCA8.dramAddr = osPhysicalToVirtual(arg1);
    D_800DCCA8.devAddr = (uintptr_t) arg0;
    D_800DCCA8.size = arg2;
    D_800DCCDC->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(D_800DCCDC, &D_800DCCA8, OS_READ);
    MQ_WAIT_FOR_MESG(&D_800DCA68, NULL);
}

void func_80073ED0(void* arg0, void* arg1, size_t arg2) {
    OSMesg sp20[8];

    if (D_800DCA68.validCount >= D_800DCA68.msgCount) {
        MQ_WAIT_FOR_MESG(&D_800DCA68, sp20);
    }
    osInvalDCache(osPhysicalToVirtual(arg1), arg2);
    D_800DCCA8.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800DCCA8.hdr.retQueue = &D_800DCA68;
    D_800DCCA8.dramAddr = osPhysicalToVirtual(arg1);
    D_800DCCA8.devAddr = (uintptr_t) arg0;
    D_800DCCA8.size = arg2;
    D_800DCCDC->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(D_800DCCDC, &D_800DCCA8, OS_READ);
    MQ_WAIT_FOR_MESG(&D_800DCA68, sp20);
}

void func_80073FA0(u32 arg0, u32 arg1, u32 arg2) {
    s32 temp_a2;
    s32 i;
    s32 temp_s3 = (arg2 >> 10);

    for (i = 0; i < temp_s3; i++) {
        func_80073ED0(arg0, arg1, 0x400);

        arg0 += 0x400;
        arg1 += 0x400;
    }

    temp_a2 = arg2 & 0x3FF;
    if (temp_a2) {
        func_80073ED0(arg0, arg1, temp_a2);
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/D_800D3400.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8007402C.s")

void func_800741DC(s32 arg0) {
    func_80073894(arg0);
    func_8007392C(arg0);
}

void func_80074204(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        D_8010B7B0.unk_520[i] = 0;
        D_8010B7B0.unk_5A0[i] = -1;
        D_8010B7B0.unk_5E0[i] = -1;
        D_8010B7B0.unk_620[i] = -1;
        D_8010B7B0.unk_660[i] = -1;
        D_8010B7B0.unk_6A0[i] = -1;
        D_8010B7B0.unk_6E0[i] = -1;
        D_8010B7B0.unk_720[i] = -1;
        D_8010B7B0.unk_760[i] = -1;
        D_8010B7B0.unk_7A0[i] = -1;
    }
}

void func_80074204(void);

void func_800742D0(void) {
    func_80074204();
    D_8010B7B0.unk_000[2] = 0;
    D_8010B7B0.unk_000[3] = 0;
}

// Pre-buffers segment
extern u8 D_802D5C40[];
extern u8 D_802A6B40_2[];
extern u8 D_802A6B40_3[];

extern unk_8010B7B0 D_8010CF50;
extern s32 D_802A6B50;
extern s32 D_802C2020;
extern s32 D_802D1B70;
extern s32 D_802D2D70;
extern unk_802D1B60_unk_00 D_802D0FE0;

void func_800742FC(void) {
    s32 i;

    bzero(D_802A6B40_3, D_802D5C40 - D_802A6B40_2);
    func_80074204();
    D_802CDFD0 = 0;
    D_8010B7B0.unk_000[0] = 4;
    D_8010B7B0.unk_000[1] = 0;
    D_8010B7B0.unk_000[2] = 0;
    D_8010B7B0.unk_000[3] = 0;
    D_8010CF50 = D_8010B7B0;
    D_802D1B60.unk_00 = &D_802D0FE0;
    D_802A6B50 = &D_802C2020;
    D_802D2D70 = &D_802D1B70;

    for (i = 0; i < 56; i++) {}
    func_8007402C(0);
    func_80074204();
    D_8010CF50 = D_8010B7B0;
    D_8010B7B0.unk_000[1] = 0;
    D_802CDFD0 = 0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074428.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074594.s")

void func_80074634(unk_800F8510* arg0) {
    unk_8006FC8C* temp_a1;
    s32 i;
    f32 var_fv0 = 65536.0f;
    f32 var_fv1 = -65536.0f;
    f32 var_fa0 = 65536.0f;
    f32 var_fa1 = -65536.0f;

    for (i = 0; i < arg0->unk_08; i++) {

        temp_a1 = &arg0->unk_10[i];

        if (temp_a1->unk_00.x < var_fv0) {
            var_fv0 = temp_a1->unk_00.x;
        }
        if (var_fv1 < temp_a1->unk_00.x) {
            var_fv1 = temp_a1->unk_00.x;
        }

        if (temp_a1->unk_00.z < var_fa0) {
            var_fa0 = temp_a1->unk_00.z;
        }
        if (var_fa1 < temp_a1->unk_00.z) {
            var_fa1 = temp_a1->unk_00.z;
        }
    }

    for (i = 0; i < arg0->unk_08; i++) {

        temp_a1 = &arg0->unk_10[i];

        temp_a1->unk_00.x -= ((var_fv0 + var_fv1) / 2);
        temp_a1->unk_00.z -= ((var_fa0 + var_fa1) / 2);
    }
}

extern unk_8006FC8C D_802CB6D0[];

void func_80074744(void) {
    unk_8006FC8C* var_a0;
    s32 i;
    s32 temp;

    for (i = 0; i < D_802CDFD0; i++) {
        var_a0 = &D_802CB6D0[i];
        temp = var_a0->unk_20 & 0x1C0;
        switch (temp) {
            case 0x80:
            case 0xC0:
            case 0x100:
            case 0x180:
                D_8010B7B0.unk_5A0[i] = -1;
                D_8010B7B0.unk_620[i] = -1;
                D_8010B7B0.unk_660[i] = -1;
                D_8010B7B0.unk_6A0[i] = -1;
                D_8010B7B0.unk_6E0[i] = -1;
                break;
        }
        switch (temp) {
            case 0:
            case 0x1C0:
                break;
            default:
                D_8010B7B0.unk_720[i] = -1;
                D_8010B7B0.unk_7A0[i] = -1;
                break;
        }
    }
}

extern s32 D_800CD220[];
extern u8 D_2747F0[];
void func_800747EC(s32 arg0) {
    void* sp1C = (D_800CD220[arg0] << 0xB) + D_2747F0;

    func_80073FA0(sp1C, func_80076BD4(D_8014A20), 0x800);
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074844.s")

f32 func_80074A20(Vec3f arg0, Vec3f arg1) {
    return sqrtf(SQ(arg1.x - arg0.x) + SQ(arg1.y - arg0.y) + SQ(arg1.z - arg0.z));
}
