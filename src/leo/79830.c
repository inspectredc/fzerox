#include "global.h"
#include "unk_leo.h"

extern s32 D_i1_8042860C;
extern OSMesg D_i1_80428610;
extern unk_leo_804285D0 D_i1_804285D0;
extern unk_leo_804285D0 D_i1_8041B550[];
s32 func_i1_80403420(u16);
s32 func_i1_804031C0(s32);
s32 func_i1_80403274(s32);
s32 func_i1_804033A4(u16);
s32 func_i1_804045AC(void);
s32 func_i1_80404830(void);

s32 func_i1_8040A720(u16 arg0, s32 arg1, s32 arg2) {
    s32 sp1C = func_i1_80403420(arg0);

    func_i1_804031C0(arg1);
    func_i1_80403274(arg2);
    if (func_i1_80403680(D_i1_804285D0.unk_02, D_i1_804285D0.unk_10, D_i1_804285D0.unk_24) != 0xFFFF) {
        D_i1_80428610 = 0x105;
        return -1;
    }
    func_i1_804033A4(arg0);
    return 0;
}

s32 func_i1_8040A7B4(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u16 sp1E;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    sp1E = func_i1_80403680(arg0, arg1, arg2);
    if (sp1E == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (D_i1_8041B550[sp1E].unk_00 & 0x2000) {
        D_i1_80428610 = 0x106;
        return -1;
    }
    func_i1_8040A720(sp1E, arg3, arg4);
    if ((arg5 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_8040A8AC(u16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg0 < 0 || arg0 > D_i1_8042860C) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (!(D_i1_8041B550[arg0].unk_00 & 0x4000)) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (D_i1_8041B550[arg0].unk_00 & 0x8000) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    func_i1_8040A720(arg0, arg1, arg2);
    if ((arg3 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}
