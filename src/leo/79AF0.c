#include "global.h"
#include "unk_leo.h"

s32 func_i1_80404830(void);
u16 func_i1_80403680(u16, s32, s32);
u16 func_i1_804037C4(u16, s32);
s32 func_i1_8040567C(u16);
u16 func_i1_804038A0(u16);
s32 func_i1_804045AC(void);
extern s32 D_i1_8042860C;
extern OSMesg D_i1_80428610;
extern u16 D_i1_80428614;
extern u16 D_i1_8042A610;
extern u16 D_i1_8042A612;
extern unk_leo_804285D0 D_i1_8041B550[];
extern unk_leo_80419EA0 D_i1_80419EA0;

s32 func_i1_8040A9E0(u16 arg0, unk_leo_804285D0** arg1) {
    D_i1_80428610 = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (!(D_i1_8041B550[arg0].unk_00 & 0xC000)) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    *arg1 = &D_i1_80419EA0.unk_16B0[arg0];
    return 0;
}

s32 func_i1_8040AA94(u16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u16 sp1E;

    sp1E = func_i1_80403680(arg0, arg1, arg2);
    if (sp1E == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    return func_i1_8040A9E0(sp1E, arg3);
}

s32 func_i1_8040AB10(u16 arg0, s32 arg1, s32 arg2) {
    u16 sp1E;

    sp1E = func_i1_804037C4(arg0, arg1);
    if (sp1E == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    return func_i1_8040A9E0(sp1E, arg2);
}

s32 func_i1_8040AB84(u16 arg0) {

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_i1_8040567C(0xFFFB);
        if ((arg0 == 0xFFFE) || (arg0 == 0xFFFF)) {
            D_i1_80428610 = 0x104;
            return -1;
        }
    }

    D_i1_8042A612 = 0;
    D_i1_8042A610 = arg0;
}

u16 func_i1_8040AC3C(void) {

    while (D_i1_8042A612 < D_i1_8042860C) {
        if ((D_i1_80419EA0.unk_16B0[D_i1_8042A612].unk_02 == D_i1_8042A610) &&
            (D_i1_80419EA0.unk_16B0[D_i1_8042A612].unk_00 & 0x4000)) {
            return D_i1_8042A612++;
        }
        D_i1_8042A612++;
    }

    return -1;
}

s32 func_i1_8040AD08(u16 arg0) {
    s32 i;
    s32 sp18;

    sp18 = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_i1_8040567C(0xFFFB);
    }
    if ((arg0 != 0xFFFD) && (func_i1_804038A0(arg0) == 0xFFFF)) {
        D_i1_80428610 = 0xF2;
        return -1;
    }

    switch (arg0) {
        case 0xFFFD:
            for (i = 0; i < D_i1_8042860C; i++) {
                if (D_i1_8041B550[i].unk_00 & 0x4000) {
                    sp18++;
                }
            }
            break;
        default:
            for (i = 0; i < D_i1_8042860C; i++) {
                if ((D_i1_80419EA0.unk_16B0[i].unk_00 & 0x4000) && (D_i1_80419EA0.unk_16B0[i].unk_02 == arg0)) {
                    sp18++;
                }
            }
            break;
    }

    return sp18;
}

s32 func_i1_8040AECC(u16 arg0) {
    s32 i;
    s32 sp18;

    sp18 = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_i1_8040567C(0xFFFB);
    }
    if ((arg0 != 0xFFFD) && (func_i1_804038A0(arg0) == 0xFFFF)) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    switch (arg0) {
        case 0xFFFD:
            for (i = 0; i < D_i1_8042860C; i++) {
                if (D_i1_8041B550[i].unk_00 & 0x8000) {
                    sp18++;
                }
            }
            break;
        default:
            for (i = 0; i < D_i1_8042860C; i++) {
                if ((D_i1_80419EA0.unk_16B0[i].unk_00 & 0x8000) && (D_i1_80419EA0.unk_16B0[i].unk_02 == arg0)) {
                    sp18++;
                }
            }
            break;
    }
    return sp18;
}

s32 func_i1_8040B090(u16 arg0, void* arg1) {
    bcopy(arg1, &D_i1_80419EA0.unk_16B0[arg0].unk_2C, 4);
    // @bug this function should return a value but doesn't (return value is used)
}

s32 func_i1_8040B0E4(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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
    if (func_i1_8040B090(sp1E, arg3) < 0) {
        return -1;
    }
    if ((arg4 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_8040B1E8(u16 arg0, s32 arg1, s32 arg2) {
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
    if (func_i1_8040B090(arg0, arg1) < 0) {
        return -1;
    }
    if ((arg2 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

// File split?

void func_i1_8040B320(void) {
    D_i1_8042A620 = LeoReadWrite;
    D_i1_8042A624 = LeoSeek;
    D_i1_8042A628 = LeoSpdlMotor;
    D_i1_8042A62C = LeoReadDiskID;
    D_i1_8042A630 = LeoReadRTC;
    D_i1_8042A634 = LeoSetRTC;
    D_i1_8042A638 = LeoModeSelectAsync;
    D_i1_8042A63C = LeoRezero;
    return;
}

void func_i1_8040B3B8(s32 arg0, void* arg1) {
    switch (arg0) {
        case 0:
            D_i1_8042A620 = arg1;
            break;
        case 1:
            D_i1_8042A624 = arg1;
            break;
        case 2:
            D_i1_8042A628 = arg1;
            break;
        case 3:
            D_i1_8042A62C = arg1;
            break;
        case 4:
            D_i1_8042A630 = arg1;
            break;
        case 5:
            D_i1_8042A634 = arg1;
            break;
        case 6:
            D_i1_8042A638 = arg1;
            break;
        case 7:
            D_i1_8042A63C = arg1;
            break;
        default:
            break;
    }
}
