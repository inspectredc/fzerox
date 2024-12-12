#include "global.h"
#include "unk_leo.h"

extern unk_leo_80419EA0 D_i1_80419EA0;
extern s32 D_i1_80428610;

s32 func_i1_8040B480(u16 arg0, u16 arg1, u16 arg2) {
    u16 sp6;

    if (!(D_i1_80419EA0.unk_16B0[arg0].unk_00 & 0x4000) || (D_i1_80419EA0.unk_16B0[arg0].unk_00 & 0x8000)) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if ((arg1 & 0x8000) || (arg2 & 0x4000)) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    sp6 = D_i1_80419EA0.unk_16B0[arg0].unk_00;
    sp6 |= arg1;
    sp6 &= arg2 ^ 0xFFFF;
    D_i1_80419EA0.unk_16B0[arg0].unk_00 = sp6;
    return 0;
}

s32 func_i1_804045AC(void);
s32 func_i1_80404830(void);

s32 func_i1_8040B584(u16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (func_i1_8040B480(arg0, arg1, arg2) < 0) {
        return -1;
    }
    if ((arg3 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

extern u16 D_i1_80428614;
s32 func_i1_80406F70(s32);
u16 func_i1_8040567C(s32);

s32 func_i1_8040B618(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u16 sp1E;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (func_i1_80406F70(arg1) < 0) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_i1_8040567C(0xFFFB);
    }
    sp1E = func_i1_80403680(arg0, arg1, arg2);
    if (sp1E == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (func_i1_8040B480(sp1E, arg3, arg4) < 0) {
        return -1;
    }
    if ((arg5 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_8040B740(u16 arg0) {

    D_i1_80428610 = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }

    if (!(D_i1_80419EA0.unk_16B0[arg0].unk_00 & 0x4000) || (D_i1_80419EA0.unk_16B0[arg0].unk_00 & 0x8000)) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    return D_i1_80419EA0.unk_16B0[arg0].unk_00;
}

s32 func_i1_8040B7EC(u16 arg0, s32 arg1, s32 arg2) {
    u16 sp1E;

    D_i1_80428610 = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (func_i1_80406F70(arg1) < 0) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_i1_8040567C(0xFFFB);
    }
    sp1E = func_i1_80403680(arg0, arg1, arg2);
    if (sp1E == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }

    return D_i1_80419EA0.unk_16B0[sp1E].unk_00;
}
