#include "global.h"
#include "unk_leo.h"

extern u16 D_i1_80428F70[];
extern unk_leo_80419EA0 D_i1_80419EA0;
extern unk_leo_804285D0 D_i1_804285D0;
extern OSMesg D_i1_80428610;
extern s32 D_i1_80428638;

void func_i1_8040D530(s32, s32, u32*);

s32 func_i1_80408B90(void) {
    bcopy(D_i1_80419EA0.unk_3C, D_i1_80428F70, sizeof(D_i1_80419EA0.unk_3C));
    return 0;
}

s32 func_i1_80408BD4(void) {
    bcopy(D_i1_80428F70, D_i1_80419EA0.unk_3C, sizeof(D_i1_80419EA0.unk_3C));
    return 0;
}

s32 func_i1_80408C18(s32* arg0, s32 arg1, s32 arg2) {
    s32 sp4 = arg1;
    s32 sp0 = *arg0;

    while (arg2 > 0) {
        if (sp0 < 0) {
            sp0 = D_i1_804285D0.unk_0A = sp4;
        } else {
            D_i1_80428F70[sp0] = sp4;
            arg2--;
            sp0 = sp4++;
        }
    }

    if (sp0 < 0) {
        D_i1_804285D0.unk_0A = -1;
    } else {
        D_i1_80428F70[sp0] = -1;
    }
    *arg0 = sp0;
    return 0;
}

s32 func_i1_80408CDC(s32 arg0) {
    s32 sp4 = arg0;
    s32 sp0;

    while (true) {
        sp0 = D_i1_80428F70[sp4];
        D_i1_80428F70[sp4] = 0;
        if (sp0 == 0xFFFF) {
            break;
        }
        if (sp0 == 0) {
            D_i1_80428610 = 0xF3;
            return -1;
        }
        if (sp0 == 0xFFFE) {
            D_i1_80428610 = 0xF3;
            return -1;
        }
        sp4 = sp0;
    }
    return 0;
}

s32 func_i1_80408D94(s32* arg0, u32 arg1, s32* arg2) {
    s32 sp1C = *arg0;
    u32 sp18;

    while (D_i1_80428F70[sp1C] != 0xFFFF) {
        func_i1_8040D530(sp1C + D_i1_80428638, 1, &sp18);
        if (arg1 < sp18) {
            D_i1_80428610 = 0xF3;
            return -1;
        }
        arg1 -= sp18;
        sp1C = D_i1_80428F70[sp1C];
    }

    func_i1_8040D530(sp1C + D_i1_80428638, 1, &sp18);
    if (arg1 > sp18) {
        D_i1_80428610 = 0xF3;
        return -1;
    }
    *arg2 = sp18 - arg1;
    *arg0 = sp1C;
    return 0;
}

s32 func_i1_80408EE4(s32* arg0, u32 arg1, s32* arg2) {
    s32 sp1C = *arg0;
    u32 sp18;

    while (true) {
        func_i1_8040D530(sp1C + D_i1_80428638, 1, &sp18);
        if (arg1 < sp18) {
            break;
        }
        arg1 -= sp18;
        if (sp1C == 0xFFFF) {
            return 0xF4;
        }
        sp1C = D_i1_80428F70[sp1C];
    }

    if (arg1 == 0) {
        *arg2 = 0;
    } else {
        *arg2 = sp18 - arg1;
    }
    *arg0 = sp1C;
    return 0;
}

s32 func_i1_80408FDC(s32 arg0) {
    s32 i = 0;

    while (true) {
        i++;
        if (D_i1_80419EA0.unk_3C[arg0] == 0xFFFF) {
            break;
        }
        if (D_i1_80419EA0.unk_3C[arg0] != arg0 + 1) {
            break;
        }
        arg0++;
    }
    return i;
}
