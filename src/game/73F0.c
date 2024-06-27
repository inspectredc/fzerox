#include "global.h"

bool func_8006D3F0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x16)) {
        return true;
    }
    return false;
}

typedef struct unk_802D3978 {
    s32 unk_00;
    s8 unk_04[0x10];
} unk_802D3978;

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

void func_8006FC8C(unk_8006FC8C* arg0, f32 arg1, f32* arg2) {
    s32 pad;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 temp_fv0;
    unk_struct_24 sp28;

    temp_fv0 = func_8009E108(arg0, arg1, &sp58);

    sp54 = ((arg0->unk_34->unk_18 - arg0->unk_18) * temp_fv0) + arg0->unk_18;
    sp50 = ((arg0->unk_34->unk_1C - arg0->unk_1C) * temp_fv0) + arg0->unk_1C;

    func_8009E85C(arg0, arg1, &sp28, temp_fv0);
    func_8009E6F0(arg0, arg1, arg2);
    sp58 = (sp54 - sp50) * 0.5f;

    arg2[0] += sp58 * sp28.unk_00[6];
    arg2[1] += sp58 * sp28.unk_00[7];
    arg2[2] += sp58 * sp28.unk_00[8];
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8006FD7C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8006FE90.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8006FF90.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8007049C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80070B5C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071260.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071790.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_800718D0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071A58.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80071BE4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8007243C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80072758.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80072BB0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80072D00.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80072ECC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_800730A4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8007327C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80073510.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80073548.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80073894.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8007392C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80073A04.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80073E28.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80073ED0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80073FA0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/D_800D3400.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_8007402C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_800741DC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074204.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_800742D0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_800742FC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074428.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074594.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074634.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074744.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_800747EC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074844.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/73F0/func_80074A20.s")
