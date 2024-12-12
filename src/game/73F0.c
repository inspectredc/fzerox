#include "global.h"
#include "fzxthread.h"
#include "segment_symbols.h"
#include "assets/segment_17B1E0.h"

Gfx* func_8006F3D8(Gfx* gfx);
Gfx* func_8006F444(Gfx* gfx);
Gfx* func_8006F478(Gfx* gfx);
Gfx* func_8006F4E4(Gfx* gfx);
Gfx* func_8006F514(Gfx* gfx);
Gfx* func_8006F57C(Gfx* gfx);
Gfx* func_8006F5E4(Gfx* gfx);
Gfx* func_8006F68C(Gfx* gfx);
Gfx* func_8006F6FC(Gfx* gfx);
Gfx* func_8006F7A4(Gfx* gfx);
Gfx* func_8006F89C(Gfx* gfx);
Gfx* func_8006F998(Gfx* gfx);
Gfx* func_8006FA94(Gfx* gfx);
Gfx* func_8006FB90(Gfx* gfx);

s32 D_800CD180 = 0;

Gfx* (*D_800CD184[])(Gfx*) = { func_8006F3D8, func_8006F444, func_8006F478, func_8006F4E4, func_8006F4E4, func_8006F514,
                               func_8006F514, func_8006F57C, func_8006F57C, func_8006F5E4, func_8006F68C, func_8006F6FC,
                               func_8006F7A4, func_8006F7A4, func_8006F89C, func_8006F89C, func_8006F998, func_8006F998,
                               func_8006FA94, func_8006FA94, func_8006FB90, func_8006FB90 };

bool func_8006D3F0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x16)) {
        return true;
    }
    return false;
}

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
extern unk_36ED0 D_802A9FC0[];
extern unk_802D1B60 D_802D1B60;
extern unk_802D08E0 D_802D08E0[];
extern s16 D_8022F0C0[];
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

extern GfxPool D_1000000;
extern Gfx D_801EAA8[];

Gfx* func_8006F5E4(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    if (D_800E32C8 != 11) {
        gSPDisplayList(gfx++, D_3000688);
    }
    D_800E32C8 = 11;

    gSPDisplayList(gfx++, D_30006D0);

    gSPMatrix(gfx++, K0_TO_PHYS(D_1000000.unk_2C5E8), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EAA8);

    return gfx;
}

Gfx* func_8006F68C(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    gSPDisplayList(gfx++, D_30006D0);

    gSPMatrix(gfx++, K0_TO_PHYS(D_1000000.unk_2C628), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EAA8);

    return gfx;
}

extern Gfx D_801EBF8[];

Gfx* func_8006F6FC(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    if (D_800E32C8 != 12) {
        gSPDisplayList(gfx++, D_3000590);
    }
    D_800E32C8 = 12;

    gSPDisplayList(gfx++, D_30005D8);

    gSPMatrix(gfx++, K0_TO_PHYS(D_1000000.unk_2C668), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

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

extern s32 D_800E12C8[];

void func_8006FD7C(s32 arg0, s32 arg1, f32 arg2) {
    s32 i = 0;
    s32 temp_v0;
    s32 pad;
    s32 sp0;

    if (D_800CD180 == 0) {
        sp0 = D_800F8518;
    }

    while (true) {
        temp_v0 = (i + sp0 - 1) % sp0;

        if ((D_802A9FC0[temp_v0].unk_04 < arg1 ||
             (arg1 == D_802A9FC0[temp_v0].unk_04 && D_802A9FC0[temp_v0].unk_08 <= arg2)) &&
            (arg1 < D_802A9FC0[i].unk_04 || (arg1 == D_802A9FC0[i].unk_04 && arg2 < D_802A9FC0[i].unk_08))) {
            break;
        }
        i++;
    }
    D_800E12C8[arg0] = temp_v0;
}

f32 func_8006FE90(s32 arg0, f32 arg1) {
    s32 i;
    s32 sp0;

    i = 0;
    if (D_800CD180 == 0) {
        sp0 = D_800F8518;
    }

    do {
        if (arg0 == D_802A9FC0[i].unk_04) {
            goto next;
        }
        i++;
    } while (i < sp0);

    if (arg1 <= 0.00001f) {
        return 0.0001f;
    }

    return 1.0f;

next:
    while (true) {

        if (arg0 == D_802A9FC0[i].unk_04 && arg1 < D_802A9FC0[i].unk_08) {
            break;
        }

        i++;

        if (i == D_800F8518) {
            return 1.0f;
        }

        if (arg0 != D_802A9FC0[i].unk_04) {
            return 1.0f;
        }
    }

    return D_802A9FC0[i].unk_08;
}

extern unk_802D2D78 D_802D2D78[];
extern unk_802D3E38 D_802D3E38[];

s32 func_80074BB4(Vec3f* arg0, f32 arg1);

f32 D_800CD1DC = 150.0f;
f32 D_800CD1E0 = 50.0f;
f32 D_800CD1E4 = 50.0f;

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
    temp_s0->unk_00 = Math_Round(((arg1->unk_10 * sp30.xz) + sp60.x) + (sp30.xx * D_800CD1E4));
    temp_s0->unk_02 = Math_Round(((arg1->unk_10 * sp30.yz) + sp60.y) + (sp30.yx * D_800CD1E4));
    temp_s0->unk_04 = Math_Round(((arg1->unk_10 * sp30.zz) + sp60.z) + (sp30.zx * D_800CD1E4));
    temp_s0->unk_08 = 0x400;
    temp_s0->unk_0A = 0x200;
    temp_s0++;
    temp_s0->unk_00 = Math_Round(((arg1->unk_10 + D_800CD1E0) * sp30.xz) + sp60.x);
    temp_s0->unk_02 = Math_Round(((arg1->unk_10 + D_800CD1E0) * sp30.yz) + sp60.y);
    temp_s0->unk_04 = Math_Round(((arg1->unk_10 + D_800CD1E0) * sp30.zz) + sp60.z);
    temp_s0->unk_08 = 0;
    temp_s0->unk_0A = 0;
    temp_s0++;
    temp_s0->unk_00 = Math_Round(((arg1->unk_10 - D_800CD1E0) * sp30.xz) + sp60.x);
    temp_s0->unk_02 = Math_Round(((arg1->unk_10 - D_800CD1E0) * sp30.yz) + sp60.y);
    temp_s0->unk_04 = Math_Round(((arg1->unk_10 - D_800CD1E0) * sp30.zz) + sp60.z);
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
    temp_s0->unk_00 = Math_Round((arg1->unk_10 * sp30.xz) + sp60.x);
    temp_s0->unk_02 = Math_Round((arg1->unk_10 * sp30.yz) + sp60.y);
    temp_s0->unk_04 = Math_Round((arg1->unk_10 * sp30.zz) + sp60.z);
    temp_s0->unk_08 = 0x400;
    temp_s0->unk_0A = 0x800;
    temp_s0++;
    temp_s0->unk_00 = Math_Round((((arg1->unk_10 + D_800CD1E0) * sp30.xz) + sp60.x) - (sp30.xx * D_800CD1E4));
    temp_s0->unk_02 = Math_Round((((arg1->unk_10 + D_800CD1E0) * sp30.yz) + sp60.y) - (sp30.yx * D_800CD1E4));
    temp_s0->unk_04 = Math_Round((((arg1->unk_10 + D_800CD1E0) * sp30.zz) + sp60.z) - (sp30.zx * D_800CD1E4));
    temp_s0->unk_08 = 0;
    temp_s0->unk_0A = 0x600;
    temp_s0++;
    temp_s0->unk_00 = Math_Round((((arg1->unk_10 - D_800CD1E0) * sp30.xz) + sp60.x) - (sp30.xx * D_800CD1E4));
    temp_s0->unk_02 = Math_Round((((arg1->unk_10 - D_800CD1E0) * sp30.yz) + sp60.y) - (sp30.yx * D_800CD1E4));
    temp_s0->unk_04 = Math_Round((((arg1->unk_10 - D_800CD1E0) * sp30.zz) + sp60.z) - (sp30.zx * D_800CD1E4));
    temp_s0->unk_08 = 0x800;
    temp_s0->unk_0A = 0x600;
    D_802D2D78[arg0].unk_00 = arg1->unk_04;
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

    temp_s0->unk_00 = Math_Round((sp8C.xx * 50.0f) + spC8.x);
    temp_s0->unk_02 = Math_Round((sp8C.yx * 50.0f) + spC8.y);
    temp_s0->unk_04 = Math_Round((sp8C.zx * 50.0f) + spC8.z);
    temp_s0->unk_08 = 0x400;
    temp_s0->unk_0A = 0x200;
    temp_s0++;
    temp_s0->unk_00 = Math_Round((sp8C.xz * 50.0f) + spC8.x);
    temp_s0->unk_02 = Math_Round((sp8C.yz * 50.0f) + spC8.y);
    temp_s0->unk_04 = Math_Round((sp8C.zz * 50.0f) + spC8.z);
    temp_s0->unk_08 = 0;
    temp_s0->unk_0A = 0;
    spB0.x = temp_s0->unk_00 - spD4.x;
    spB0.y = temp_s0->unk_02 - spD4.y;
    spB0.z = temp_s0->unk_04 - spD4.z;
    func_80074BB4(&spB0, 1.0f);

    D_802D3E38[arg0].unk_0C = spB0;
    temp_s0++;

    temp_s0->unk_00 = Math_Round(spC8.x - (sp8C.xz * 50.0f));
    temp_s0->unk_02 = Math_Round(spC8.y - (sp8C.yz * 50.0f));
    temp_s0->unk_04 = Math_Round(spC8.z - (sp8C.zz * 50.0f));
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
    temp_s0->unk_00 = Math_Round(spC8.x);
    temp_s0->unk_02 = Math_Round(spC8.y);
    temp_s0->unk_04 = Math_Round(spC8.z);
    temp_s0->unk_08 = 0x400;
    temp_s0->unk_0A = 0x800;
    temp_s0++;
    temp_s0->unk_00 = Math_Round(((sp8C.xz * 50.0f) + spC8.x) - (sp8C.xx * 50.0f));
    temp_s0->unk_02 = Math_Round(((sp8C.yz * 50.0f) + spC8.y) - (sp8C.yx * 50.0f));
    temp_s0->unk_04 = Math_Round(((sp8C.zz * 50.0f) + spC8.z) - (sp8C.zx * 50.0f));
    temp_s0->unk_08 = 0;
    temp_s0->unk_0A = 0x600;
    temp_s0++;
    temp_s0->unk_00 = Math_Round((spC8.x - (sp8C.xz * 50.0f)) - (sp8C.xx * 50.0f));
    temp_s0->unk_02 = Math_Round((spC8.y - (sp8C.yz * 50.0f)) - (sp8C.yx * 50.0f));
    temp_s0->unk_04 = Math_Round((spC8.z - (sp8C.zz * 50.0f)) - (sp8C.zx * 50.0f));
    temp_s0->unk_08 = 0x800;
    temp_s0->unk_0A = 0x600;
    D_802D2D78[arg0].unk_00 = arg1->unk_04;
    temp_s0++;
    *arg2 = temp_s0;
}

s32 D_800CD1E8 = 0;

extern s32 D_800E32CC;
extern unk_8006FF90_arg_2* D_800E32D0;
f32 func_80074A20(Vec3f, Vec3f);
void func_8006FD7C(s32 arg0, s32 arg1, f32 arg2);
f32 func_8006FE90(s32 arg0, f32 arg1);

unk_8006FF90_arg_2* func_80070B5C(unk_8006FC8C* arg0, f32 arg1, unk_8006FF90_arg_1* arg2, unk_8006FF90_arg_2* arg3,
                                  f32 arg4, f32 arg5) {
    bool sp114 = false;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 var_fs2;
    f32 var_fs3;
    s32 var_s2;
    unk_8006FC8C* temp_v0;
    f32 spF4;
    Vec3f spE8;
    Vec3f spDC;
    Vec3f spD0 = { 0.0f, 0.0f, 0.0f };
    Vec3f spC4 = { 0.0f, 0.0f, 0.0f };
    Vec3f spB8 = { 0.0f, 0.0f, 0.0f };
    Vec3f spAC = { 0.0f, 0.0f, 0.0f };
    Mtx3F sp88;
    f32 temp = 1.0f;

    var_s2 = 0;

    while (true) {
        func_8006FD7C((s32) (arg3 - D_800E32D0) / 2, arg0->unk_30, arg1);
        func_8009E538(arg0, arg1, &spDC);
        func_8006FC8C(arg0, arg1, &spE8);
        temp_fv0 = func_8009E108(arg0, arg1, &spF4);
        func_8009E85C(arg0, arg1, &sp88, temp_fv0);
        spE8.x += sp88.y.x * 10.0f;
        spE8.y += sp88.y.y * 10.0f;
        spE8.z += sp88.y.z * 10.0f;

        temp_fv1 = arg0->unk_18 + arg0->unk_1C;
        temp_fv1 = (((arg0->unk_34->unk_18 + arg0->unk_34->unk_1C) - temp_fv1) * temp_fv0) + temp_fv1;
        temp_fv1 /= 2;

        if (arg2->unk_10 < -1.0f * temp_fv1) {
            var_fs2 = -1.0f * temp_fv1;
        } else {
            var_fs2 = arg2->unk_10;
        }

        if (temp_fv1 < arg2->unk_14) {
            var_fs3 = temp_fv1;
        } else {
            var_fs3 = arg2->unk_14;
        }
        spC4.x = Math_Round((sp88.z.x * var_fs2) + spE8.x);
        spC4.y = Math_Round((sp88.z.y * var_fs2) + spE8.y);
        spC4.z = Math_Round((sp88.z.z * var_fs2) + spE8.z);
        spAC.x = Math_Round((sp88.z.x * var_fs3) + spE8.x);
        spAC.y = Math_Round((sp88.z.y * var_fs3) + spE8.y);
        spAC.z = Math_Round((sp88.z.z * var_fs3) + spE8.z);
        if (!sp114) {
            spD0 = spC4;
            spB8 = spAC;
            sp114 = true;
        }
        arg4 += 9.0f * func_80074A20(spC4, spD0);
        arg5 += 9.0f * func_80074A20(spAC, spB8);
        if ((arg4 > 32768.0f) || (arg5 > 32768.0f)) {
            arg4 = (func_80074A20(spC4, spD0) * 9.0f) + -32768.0f;
            arg5 = (func_80074A20(spAC, spB8) * 9.0f) + -32768.0f;
        }
        arg3->unk_00 = spC4.x;
        arg3->unk_02 = spC4.y;
        arg3->unk_04 = spC4.z;
        spD0 = spC4;
        arg3->unk_08 = 0;
        arg3->unk_0A = arg4 * 1;
        arg3++;
        D_800CD1E8++;
        var_s2++;

        arg3->unk_00 = spAC.x;
        arg3->unk_02 = spAC.y;
        arg3->unk_04 = spAC.z;
        spB8 = spAC;
        arg3->unk_08 = func_80074A20(spC4, spAC) * 6.0f * 1;
        arg3->unk_0A = arg5 * 1;
        arg3++;
        D_800CD1E8++;
        var_s2++;

        if (D_800CD1E8 >= D_800E32CC) {
            return arg3;
        }

        if (arg1 == arg2->unk_0C) {
            break;
        }

        if (var_s2 == 0x20) {
            var_s2 = 0;
            while (true) {
                arg4 -= 1024.0f;
                arg5 -= 1024.0f;
                if (arg4 < -31744.0f || arg5 < -31744.0f) {
                    break;
                }
            }

        } else {
            arg1 = func_8006FE90(arg0->unk_30, arg1);

            if (arg2->unk_0C <= arg1) {
                if (1) {}
                arg1 = arg2->unk_0C;
            }
        }
    }
    return arg3;
}

extern unk_8006FF90_arg_2* D_800E32D0;
extern unk_8006FF90_arg_2 D_802268C0[];
extern unk_8006FF90_arg_2 D_8022E8C0[];
extern unk_802D2D70 D_802D2D70;

void func_80071260(s32 arg0) {
    s32 i;
    s32 j;
    s32 pad;
    unk_8006FC8C* temp_s5;
    unk_8006FF90_arg_1* temp_s0;
    unk_8006FF90_arg_2* temp_v0_2;
    unk_802D2D78* var_s7;
    unk_802D3E38* var_s6;
    f32 temp_fa0;
    unk_8006FF90_arg_2* spA8;
    unk_8006FF90_arg_2* spA4;
    f32 temp_fv0;
    unk_802D2D70* var_s2; // sp9C
    s32 temp_v0;
    f32 var_fv0;
    f32 var_fv1;

    D_800CD1E8 = 0;
    if (D_800CD180 != 0) {
        //! @bug Uninitalised pointers!
        D_800E32CC = 0x400;
    } else {
        D_800E32CC = 0x800;
        D_800E32D0 = D_802268C0;
        spA8 = D_802268C0;
        spA4 = D_8022E8C0;
        if (1) {}
        if (1) {}
        if (1) {}
        if (1) {}
        var_s2 = &D_802D2D70;
    }

    for (i = 0; i < var_s2->index; i++) {
        temp_s0 = &var_s2->unk_00[i];
        temp_s5 = &D_800F8510->unk_10[temp_s0->unk_00];

        D_802D2D78[i].unk_00 = temp_s0->unk_04;
        D_802D2D78[i].unk_04 = spA8;
        D_802D3E38[i].unk_00 = temp_s0->unk_04;
        D_802D3E38[i].unk_04 = temp_s0->unk_08;
        D_802D3E38[i].unk_08 = temp_s0->unk_0C;
        D_802D3E38[i].unk_0C.x = temp_s0->unk_10;
        D_802D3E38[i].unk_18.x = temp_s0->unk_14;
        temp_fa0 = temp_s0->unk_08;

        if (temp_s0->unk_04 == 3) {
            var_fv1 = (temp_s5->unk_18 + temp_s5->unk_1C) / 520.0f;
            if (var_fv1 < 1.0f) {
                var_fv1 = 1.0f;
            }
            D_800CD1DC = 150.0f * var_fv1;
            D_800CD1E0 = 50.0f * var_fv1;
            D_800CD1E4 = 50.0f * var_fv1;

            switch (temp_s5->unk_20 & 0x1C0) {
                case 0:
                case 0x40:
                case 0x140:
                case 0x1C0:
                    func_8006FF90(i, temp_s0, &spA4);
                    break;
                default:
                    func_8007049C(i, temp_s0, &spA4);
                    break;
            }
        } else {
            var_fv0 = -32768.0f;
            var_fv1 = -32768.0f;

            for (j = 0; j < i; j++) {
                if ((temp_s0->unk_00 == (var_s2->unk_00[j].unk_00 + 1)) &&
                    (temp_s0->unk_04 == var_s2->unk_00[j].unk_04) && (var_s2->unk_00[j].unk_0C == 1.0f) &&
                    (temp_s0->unk_10 == var_s2->unk_00[j].unk_10) && (temp_s0->unk_14 == var_s2->unk_00[j].unk_14)) {
                    // UB?
                    // float calculation just needs to be 1.0f
                    var_fv0 = D_802D2D78[j].unk_08[-2].unk_0A / (2.0f - 1.0f);
                    var_fv1 = D_802D2D78[j].unk_08[-1].unk_0A / (2.0f - 1.0f);
                    while (true) {
                        var_fv0 -= 1024.0f;
                        var_fv1 -= 1024.0f;
                        if (var_fv0 < -31744.0f || var_fv1 < -31744.0f) {
                            break;
                        }
                    }
                }
            }
            spA8 = func_80070B5C(temp_s5, temp_fa0, temp_s0, spA8, var_fv0, var_fv1);
            if (D_800CD1E8 >= D_800E32CC) {
                var_s2->index = i - 1;
            }
            D_802D2D78[i].unk_00 = temp_s0->unk_04;
        }

        D_802D2D78[i].unk_08 = spA8;
    }

    for (i = 0; i < D_800F8510->unk_08; i++) {
        D_800F8510->unk_10[i].unk_54 = NULL;
        D_800F8510->unk_10[i].unk_58 = NULL;
    }

    for (i = 0; i < D_800F8510->unk_08; i++) {
        for (j = 0; j < var_s2->index; j++) {
            temp_s0 = &var_s2->unk_00[j];
            if (i == temp_s0->unk_00) {
                D_800F8510->unk_10[i].unk_58 = &D_802D3E38[j + 1];
            }
        }
    }

    for (i = 0; i < D_800F8510->unk_08; i++) {
        for (j = var_s2->index - 1; j >= 0; j--) {
            temp_s0 = &var_s2->unk_00[j];
            if (i == temp_s0->unk_00) {
                D_800F8510->unk_10[i].unk_54 = &D_802D3E38[j];
            }
        }
    }

    for (i = 0; i < var_s2->index; i++) {}
}

void func_80071790(s32, s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071790.s")
extern unk_8006FF90_arg_1 D_802D1B70[];
extern s8 D_i2_8010BD50[];

void func_800718D0(s32, s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_800718D0.s")

void func_80071A58(s32, s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071A58.s")

void func_80071BE4(s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071BE4.s")

extern unk_8010B7B0 D_8010B7B0[];
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
    } else if (D_8010B7B0[0].unk_001 < 4) {
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

void func_8007392C(s32 arg0) {
    s32 i;

    if (D_800CD180 != 0) {
        if (D_802CDFD0 < 4) {
            return;
        }
    } else if (D_8010B7B0[0].unk_001 < 4) {
        return;
    }

    D_802D2D70.index = 0;

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

void func_80073E28(void* romAddr, void* ramAddr, size_t size) {
    osInvalDCache(osPhysicalToVirtual(ramAddr), size);
    D_800DCCA8.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800DCCA8.hdr.retQueue = &D_800DCA68;
    D_800DCCA8.dramAddr = osPhysicalToVirtual(ramAddr);
    D_800DCCA8.devAddr = (uintptr_t) romAddr;
    D_800DCCA8.size = size;
    D_800DCCDC->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(D_800DCCDC, &D_800DCCA8, OS_READ);
    MQ_WAIT_FOR_MESG(&D_800DCA68, NULL);
}

void func_80073ED0(void* romAddr, void* ramAddr, size_t size) {
    OSMesg sp20[8];

    if (D_800DCA68.validCount >= D_800DCA68.msgCount) {
        MQ_WAIT_FOR_MESG(&D_800DCA68, sp20);
    }
    osInvalDCache(osPhysicalToVirtual(ramAddr), size);
    D_800DCCA8.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800DCCA8.hdr.retQueue = &D_800DCA68;
    D_800DCCA8.dramAddr = osPhysicalToVirtual(ramAddr);
    D_800DCCA8.devAddr = (uintptr_t) romAddr;
    D_800DCCA8.size = size;
    D_800DCCDC->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(D_800DCCDC, &D_800DCCA8, OS_READ);
    MQ_WAIT_FOR_MESG(&D_800DCA68, sp20);
}

void func_80073FA0(u8* romAddr, u8* ramAddr, size_t size) {
    s32 remainder;
    s32 i;
    s32 numBlocks = size / 1024;

    for (i = 0; i < numBlocks; i++) {
        func_80073ED0(romAddr, ramAddr, 0x400);

        romAddr += 0x400;
        ramAddr += 0x400;
    }

    remainder = size % 1024;
    if (remainder) {
        func_80073ED0(romAddr, ramAddr, remainder);
    }
}

// todo: move these to appropriate places
static const char devrostr0[] = "\n/***\nCOURSE GADGET TEXTURE OVER!! %f,%f\n***/\n";
static const char devrostr1[] = "GADGET OVER !! OVER !! OVER !!\n";
static const char devrostr2[] = "Gadget Vtx Over %d!!\n";
static const char devrostr3[] = "move start position %d\n";
static const char devrostr4[] = "look index %d\n";
static const char devrostr5[] = "index %d\n";
static const char devrostr6[] = "ENTRY CHECK\n";

extern u8 D_i2_8010D730[][9];
extern s16 D_80106F48;

void func_80074428(s32 arg0);

void func_8007402C(s32 arg0) {
    s32 pad;
    s32 sp28;

    if (arg0 >= 54) {
        func_80073FA0(SEGMENT_ROM_START(segment_2AD1E0) + (arg0 - 30) * sizeof(unk_8010B7B0),
                      osVirtualToPhysical(D_8010B7B0), sizeof(unk_8010B7B0));
        if ((D_80106F48 >= 4) && (arg0 == 55)) {
            D_8010B7B0[0].unk_003 = 3;
        }
    } else if (arg0 >= 48) {
        func_800A3044();
        return;
    } else if (arg0 >= 24) {
        sp28 = arg0 - 24;
        if (func_800760F8() != 2) {
            osWritebackDCacheAll();
            func_8007FE98();
            osWritebackDCacheAll();
        }

        while (func_800760F8() != 2) {}

        if (func_i1_80403680(0xFFFB, D_i2_8010D730[sp28], "CRSD\0\0\0\0ENTRY CHECK OK\n") != 0xFFFF) {
            func_i1_804096C8(0xFFFB, D_i2_8010D730[sp28], "CRSD\0\0\0\0ENTRY LOAD OK\n\0\0UNPACK\n\0UNPACK OK\n",
                             D_8010B7B0, 0);
        }
    } else {
        func_80073FA0(SEGMENT_ROM_START(segment_2AD1E0) + arg0 * sizeof(unk_8010B7B0), osVirtualToPhysical(D_8010B7B0),
                      sizeof(unk_8010B7B0));
    }

    func_80074428(arg0);
}

void func_800741DC(s32 arg0) {
    func_80073894(arg0);
    func_8007392C(arg0);
}

void func_80074204(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        D_8010B7B0[0].unk_520[i] = 0;
        D_8010B7B0[0].unk_5A0[i] = -1;
        D_8010B7B0[0].unk_5E0[i] = -1;
        D_8010B7B0[0].unk_620[i] = -1;
        D_8010B7B0[0].unk_660[i] = -1;
        D_8010B7B0[0].unk_6A0[i] = -1;
        D_8010B7B0[0].unk_6E0[i] = -1;
        D_8010B7B0[0].unk_720[i] = -1;
        D_8010B7B0[0].unk_760[i] = -1;
        D_8010B7B0[0].unk_7A0[i] = -1;
    }
}

void func_80074204(void);

void func_800742D0(void) {
    func_80074204();
    D_8010B7B0[0].unk_002 = 0;
    D_8010B7B0[0].unk_003 = 0;
}

extern unk_8010B7B0 D_8010CF50;
extern s32 D_802A6B50;
extern unk_8006FC8C D_802C2020[];
extern unk_8006FF90_arg_1 D_802D1B70[];
extern unk_802D1B60_unk_00 D_802D0FE0[];

void func_800742FC(void) {
    s32 i;

    bzero(SEGMENT_VRAM_START(unk_context), SEGMENT_BSS_SIZE(unk_context));
    func_80074204();
    D_802CDFD0 = 0;
    D_8010B7B0[0].unk_000 = 4;
    D_8010B7B0[0].unk_001 = 0;
    D_8010B7B0[0].unk_002 = 0;
    D_8010B7B0[0].unk_003 = 0;
    D_8010CF50 = D_8010B7B0[0];
    D_802D1B60.unk_00 = D_802D0FE0;
    D_802A6B50 = D_802C2020;
    D_802D2D70.unk_00 = D_802D1B70;

    for (i = 0; i < ARRAY_COUNT(D_802A6B40); i++) {}

    func_8007402C(0);
    func_80074204();
    D_8010CF50 = D_8010B7B0[0];
    D_8010B7B0[0].unk_001 = 0;
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
                D_8010B7B0[0].unk_5A0[i] = -1;
                D_8010B7B0[0].unk_620[i] = -1;
                D_8010B7B0[0].unk_660[i] = -1;
                D_8010B7B0[0].unk_6A0[i] = -1;
                D_8010B7B0[0].unk_6E0[i] = -1;
                break;
        }
        switch (temp) {
            case 0:
            case 0x1C0:
                break;
            default:
                D_8010B7B0[0].unk_720[i] = -1;
                D_8010B7B0[0].unk_7A0[i] = -1;
                break;
        }
    }
}

UNUSED s32 D_800CD21C = 0;
s32 D_800CD220[] = { 1, 0, 0, 0, 2, 3, 4, 0, 0, 0, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void func_800747EC(s32 arg0) {
    void* sp1C = (D_800CD220[arg0] * 0x800) + SEGMENT_ROM_START(segment_2747F0);

    func_80073FA0(sp1C, func_80076BD4(D_8014A20), 0x800);
}

s32 D_800CD298 = 0;
s32 D_800CD29C = 0;
UNUSED s32 D_800CD2A0 = -1;

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074844.s")

f32 func_80074A20(Vec3f arg0, Vec3f arg1) {
    return sqrtf(SQ(arg1.x - arg0.x) + SQ(arg1.y - arg0.y) + SQ(arg1.z - arg0.z));
}
