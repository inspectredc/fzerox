#include "global.h"
#include "unk_leo.h"

s32 func_i1_804039F8(u32, s32*, s32*, u32*);
void func_i1_80408B90(void);
void func_i1_80408C18(s32*, s32, s32);
s32 func_i1_8040A4D4(s32, s32, s32, s32);
extern s32 D_i1_80428610;
extern LEOCapacity D_i1_80428638;

s32 func_i1_80407160(s32 arg0, u32 arg1, s32 arg2) {
    u32 sp2C = arg1;
    u32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C = -1;
    s32 sp18 = arg0;

    func_i1_80408B90();

    while (sp2C != 0) {
        if (func_i1_804039F8(sp2C, &sp24, &sp20, &sp28) < 0) {
            D_i1_80428610 = 0xF1;
            return -1;
        }
        if (func_i1_8040A4D4(sp24 + D_i1_80428638.startLBA, sp18, sp20, arg2) < 0) {
            return -1;
        }
        func_i1_80408C18(&sp1C, sp24, sp20);
        if (sp28 >= sp2C) {
            sp2C = 0;
        } else {
            sp2C -= sp28;
        }
        sp18 += sp28;
    }
    return 0;
}

void func_i1_804030D0(s32);
void func_i1_80403274(u8*);
void func_i1_804032D0(s32);
void func_i1_804032E8(u16, u8*);
void func_i1_80403340(s32);
void func_i1_80403358(u8);
void func_i1_80403374(void);
void func_i1_804033A4(u16);
void func_i1_80403544(u16);
u16 func_i1_8040397C(void);
s32 func_i1_80408BD4(void);

u8 D_i1_804286E0 = 0;

s32 func_i1_80407278(u16 arg0, u8* arg1, u8* arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u16 sp26;

    func_i1_80403374();
    if ((arg6 < 0) || (arg6 >= 0x100)) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (arg5 & 0x8000) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    arg5 |= 0x4000;
    if ((arg6 > 0) && (arg6 < 0xFE)) {
        arg5 |= 0x200;
    }
    sp26 = func_i1_8040397C();
    if (sp26 == 0xFFFF) {
        D_i1_80428610 = 0xF1;
        return -1;
    }

    if (func_i1_80407160(arg3, arg4, (arg5 & 0x400) ? 1 : 0) < 0) {
        return -1;
    }
    func_i1_804032E8(arg0, arg1);
    func_i1_804030D0(arg5);
    func_i1_804032D0(arg4);
    func_i1_80403274(arg2);
    func_i1_80403340(arg6);
    func_i1_80403358(D_i1_804286E0);
    func_i1_804033A4(sp26);
    func_i1_80403544(sp26);
    func_i1_80408BD4();
}

extern unk_leo_80419EA0 D_i1_80419EA0;
extern u16 D_i1_80428614;

void func_i1_804040EC(void);
s32 func_i1_804045AC(void);
s32 func_i1_80404830(void);
u32 func_i1_80404924(void);
u16 func_i1_8040567C(u16);
s32 func_i1_80406F70(s32);
void func_i1_8040911C(u16, u8*, u8*, s32);

s32 func_i1_804073F4(u16 arg0, u8* arg1, u8* arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u16 sp2E;

    D_i1_80428610 = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg4 == 0) {
        D_i1_80428610 = 0xF4;
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
    D_i1_804286E0 = 0;
    sp2E = func_i1_80403680(arg0, arg1, arg2);
    if (sp2E != 0xFFFF) {
        D_i1_804286E0 = D_i1_80419EA0.unk_16B0[sp2E].unk_2A;
        if (D_i1_80419EA0.unk_16B0[sp2E].unk_00 & 0x2000) {
            D_i1_80428610 = 0x106;
            return -1;
        }
        func_i1_8040911C(arg0, arg1, arg2, 0);
        if (func_i1_80404924() < arg4) {
            func_i1_804040EC();
            D_i1_80428610 = 0xF1;
            return -1;
        }
    }

    if (func_i1_80404924() < arg4) {
        D_i1_80428610 = 0xF1;
        return -1;
    }
    if (func_i1_80407278(arg0, arg1, arg2, arg3, arg4, arg5, arg6) < 0) {
        return -1;
    }
    if ((arg7 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

void func_i1_8040A7B4(u16, u8*, u8*, u8*, u8*, s32);

s32 func_i1_80407628(u16 arg0, u8* arg1, u8* arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u16 sp2E;

    D_i1_80428610 = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg4 == 0) {
        D_i1_80428610 = 0xF4;
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
    D_i1_804286E0 = 0;
    sp2E = func_i1_80403680(arg0, arg1, arg2);
    if (sp2E != 0xFFFF) {
        D_i1_804286E0 = D_i1_80419EA0.unk_16B0[sp2E].unk_2A;
        if (D_i1_80419EA0.unk_16B0[sp2E].unk_00 & 0x2000) {
            D_i1_80428610 = 0x106;
            return -1;
        }
        if (func_i1_80404924() < arg4) {
            D_i1_80428610 = 0xF1;
            return -1;
        }
        if (func_i1_80407278(arg0, "__TMP__", "_!TMP", arg3, arg4, arg5, arg6) < 0) {
            return -1;
        }
        func_i1_8040911C(arg0, arg1, arg2, 0);
        func_i1_8040A7B4(arg0, "__TMP__", "_!TMP", arg1, arg2, 0);
    } else {
        if (func_i1_80404924() < arg4) {
            D_i1_80428610 = 0xF1;
            return -1;
        }
        if (func_i1_80407278(arg0, arg1, arg2, arg3, arg4, arg5, arg6) < 0) {
            return -1;
        }
    }

    if ((arg7 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

void func_i1_8040321C(void);
s32 func_i1_8040A5F8(s32, u8*, s32, s32);
void func_i1_80408D94(s32*, s32, u32*);

extern u8 D_i1_80415190[];

s32 func_i1_804078C8(u16 arg0, u8* arg1, u32 arg2, s32 arg3) {
    s32 sp44;
    u32 sp40;
    u32 sp3C;
    u32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    u8* sp28;

    sp40 = arg2;
    sp28 = arg1;
    sp44 = D_i1_80419EA0.unk_16B0[arg0].unk_0C;
    sp34 = D_i1_80419EA0.unk_16B0[arg0].unk_0A;
    func_i1_80408B90();
    func_i1_80408D94(&sp34, sp44, &sp3C);
    if (sp3C != 0) {
        LeoLBAToByte(sp34 + D_i1_80428638.startLBA, 1, &sp38);
        if (func_i1_8040A5F8(sp34 + D_i1_80428638.startLBA, D_i1_80415190, 1, arg3) < 0) {
            return -1;
        }

        bcopy(sp28, (sp38 - sp3C) + D_i1_80415190, (sp3C > sp40) ? sp40 : sp3C);
        if (func_i1_8040A4D4(sp34 + D_i1_80428638.startLBA, D_i1_80415190, 1, arg3) < 0) {
            return -1;
        }
    }

    sp40 -= (sp3C > sp40) ? sp40 : sp3C;
    sp28 += (sp3C > sp40) ? sp40 : sp3C;
    while (sp40 != 0) {
        if (func_i1_804039F8(sp40, &sp30, &sp2C, &sp38) < 0) {
            D_i1_80428610 = 0xF1;
            return -1;
        }
        if (func_i1_8040A4D4(sp30 + D_i1_80428638.startLBA, sp28, sp2C, arg3) < 0) {
            return -1;
        }
        func_i1_80408C18(&sp34, sp30, sp2C);
        if (sp38 >= sp40) {
            sp40 = 0;
        } else {
            sp40 -= sp38;
        }
        sp28 += sp38;
    }

    func_i1_804032D0(sp44 + arg2);
    func_i1_8040321C();
    func_i1_804033A4(arg0);
    func_i1_80403544(arg0);
    func_i1_80408BD4();
    return 0;
}

s32 func_i1_80404A08(void);
void func_i1_80408CDC(s32);

s32 func_i1_80407B90(u16 arg0, s32 arg1, s32 arg2) {
    u32 sp2C;
    s32 sp28;

    if (arg2 == 0) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    sp2C = D_i1_80419EA0.unk_16B0[arg0].unk_0C + arg2;

    func_i1_80408B90();
    func_i1_80408CDC(D_i1_80419EA0.unk_16B0[arg0].unk_0A);
    if (func_i1_80404A08() < sp2C) {
        func_i1_804040EC();
        D_i1_80428610 = 0xF1;
        return -1;
    }
    sp28 = D_i1_80419EA0.unk_16B0[arg0].unk_00;

    if (func_i1_804078C8(arg0, arg1, arg2, (sp28 & 0x400) ? 1 : 0) < 0) {
        return -1;
    }
    return 0;
}

s32 func_i1_80407CD0(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
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
    if (func_i1_80407B90(sp1E, arg3, arg4) < 0) {
        return -1;
    }
    if ((arg5 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

extern s32 D_i1_8042860C;

s32 func_i1_80407E00(u16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_i1_80428610 = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if ((arg0 < 0) || (arg0 > D_i1_8042860C)) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (!(D_i1_80419EA0.unk_16B0[arg0].unk_00 & 0x4000)) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (D_i1_80419EA0.unk_16B0[arg0].unk_00 & 0x8000) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (func_i1_80407B90(arg0, arg1, arg2) < 0) {
        return -1;
    }
    if ((arg3 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

extern u16 D_i1_80428F70[];

void func_i1_80408EE4(s32*, s32, u32*);
s32 func_i1_80408FDC(s32);

s32 func_i1_80407F48(u16 arg0, u8* arg1, s32 arg2, u32 arg3, s32 arg4) {
    s32 sp4C;
    u32 sp48;
    u32 sp44;
    u32 sp40;
    s32 sp3C;
    s32 pad[2];
    s32 sp30;
    s32 sp2C;
    u8* sp28;

    sp48 = arg3;
    sp28 = arg1;

    sp4C = D_i1_80419EA0.unk_16B0[arg0].unk_0C;
    sp3C = D_i1_80419EA0.unk_16B0[arg0].unk_0A;

    func_i1_80408B90();
    func_i1_80408EE4(&sp3C, arg2, &sp44);
    if (sp44 != 0) {
        LeoLBAToByte(sp3C + D_i1_80428638.startLBA, 1, &sp40);
        if (func_i1_8040A5F8(sp3C + D_i1_80428638.startLBA, D_i1_80415190, 1, arg4) < 0) {
            return -1;
        }

        bcopy(sp28, (sp40 - sp44) + D_i1_80415190, (sp44 > sp48) ? sp48 : sp44);
        if (func_i1_8040A4D4(sp3C + D_i1_80428638.startLBA, D_i1_80415190, 1, arg4) < 0) {
            return -1;
        }

        sp48 -= (sp44 > sp48) ? sp48 : sp44;

        sp28 += (sp44 > sp48) ? sp48 : sp44;

        if (sp48 != 0) {
            sp3C = D_i1_80428F70[sp3C];
            if (sp3C == 0xFFFF) {
                D_i1_80428610 = 0xF3;
                return -1;
            }
        }
    }

    while (sp48 != 0) {
        sp30 = func_i1_80408FDC(sp3C);

        for (sp2C = 1; sp2C <= sp30; sp2C++) {
            LeoLBAToByte(sp3C + D_i1_80428638.startLBA, sp2C, &sp40);
            if (sp40 >= sp48) {
                break;
            }
        }
        if (sp40 == sp48) {
            if (func_i1_8040A4D4(sp3C + D_i1_80428638.startLBA, sp28, sp2C, arg4) < 0) {
                return -1;
            }
            sp48 = 0;
        } else if (--sp2C > 0) {
            LeoLBAToByte(sp3C + D_i1_80428638.startLBA, sp2C, &sp40);
            if (func_i1_8040A4D4(sp3C + D_i1_80428638.startLBA, sp28, sp2C, arg4) < 0) {
                return -1;
            }
            sp3C += sp2C;
            sp48 -= sp40;
            sp28 += sp40;
        } else {
            break;
        }

        if (sp2C < sp30) {
            break;
        }
        sp3C = (sp3C + sp30) - 1;

        if ((sp3C = D_i1_80428F70[sp3C]) == 0xFFFF) {
            D_i1_80428610 = 0xF3;
            return -1;
        }
    }
    if (sp48 != 0) {
        if (func_i1_8040A5F8(sp3C + D_i1_80428638.startLBA, D_i1_80415190, 1, arg4) < 0) {
            return -1;
        }
        bcopy(sp28, D_i1_80415190, sp48);
        if (func_i1_8040A4D4(sp3C + D_i1_80428638.startLBA, D_i1_80415190, 1, arg4) < 0) {
            return -1;
        }
    }

    func_i1_8040321C();
    func_i1_804033A4(arg0);
    return 0;
}

s32 func_i1_804083C8(u16 arg0, s32 arg1, u32 arg2, u32 arg3) {
    s32 sp2C;

    if (arg3 == 0) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (D_i1_80419EA0.unk_16B0[arg0].unk_0C < arg2 + arg3) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    sp2C = D_i1_80419EA0.unk_16B0[arg0].unk_00;

    if (func_i1_80407F48(arg0, arg1, arg2, arg3, (sp2C & 0x400) ? 1 : 0) < 0) {
        return -1;
    }
    return 0;
}

s32 func_i1_804084D4(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
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
    if (func_i1_804083C8(sp1E, arg3, arg4, arg5) < 0) {
        return -1;
    }
    if ((arg6 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_80408608(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_i1_80428610 = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if ((arg0 < 0) || (arg0 > D_i1_8042860C)) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (!(D_i1_80419EA0.unk_16B0[arg0].unk_00 & 0x4000)) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (D_i1_80419EA0.unk_16B0[arg0].unk_00 & 0x8000) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (func_i1_804083C8(arg0, arg1, arg2, arg3) < 0) {
        return -1;
    }
    if ((arg4 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_80408754(u16 arg0, s32 arg1, u32 arg2, u32 arg3) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    sp30 = 0;
    sp2C = 0;
    if (arg3 == 0) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (D_i1_80419EA0.unk_16B0[arg0].unk_0C < arg2 + arg3) {
        sp30 = D_i1_80419EA0.unk_16B0[arg0].unk_0C - arg2;
        sp2C = (arg2 + arg3) - D_i1_80419EA0.unk_16B0[arg0].unk_0C;
    } else {
        sp30 = arg3;
    }
    sp34 = D_i1_80419EA0.unk_16B0[arg0].unk_00;

    if (func_i1_80407F48(arg0, arg1, arg2, sp30, (sp34 & 0x400) ? 1 : 0) < 0) {
        return -1;
    }
    if (sp2C != 0) {
        if (func_i1_804078C8(arg0, arg1 + sp30, sp2C, (sp34 & 0x400) ? 1 : 0) < 0) {
            return -1;
        }
    }

    return 0;
}

s32 func_i1_8040890C(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
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
    if (func_i1_80408754(sp1E, arg3, arg4, arg5) < 0) {
        return -1;
    }
    if ((arg6 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_80408A40(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_i1_80428610 = 0;
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if ((arg0 < 0) || (arg0 > D_i1_8042860C)) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (!(D_i1_80419EA0.unk_16B0[arg0].unk_00 & 0x4000)) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (D_i1_80419EA0.unk_16B0[arg0].unk_00 & 0x8000) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (func_i1_80408754(arg0, arg1, arg2, arg3) < 0) {
        return -1;
    }
    if ((arg4 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}
