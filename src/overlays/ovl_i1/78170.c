#include "global.h"
#include "unk_leo.h"

extern s32 D_i1_8042860C;
extern OSMesg D_i1_80428610;
extern u16 D_i1_80428614;
extern unk_leo_804285D0 D_i1_8041B550[];
extern unk_leo_80419EA0 D_i1_80419EA0;
extern u8 D_i1_80415190[];
extern s32 D_i1_80428638;
extern u16 D_i1_80428F70[];
s32 func_i1_80408B90(void);
s32 func_i1_80408BD4(void);
s32 func_i1_80408CDC(s32);
s32 func_i1_804045AC(void);
s32 func_i1_80404830(void);
s32 func_i1_80409060(u16);
s32 func_i1_80403680(u16, s32, s32);
s32 func_i1_80408FDC(s32);
s32 func_i1_8040A5F8(s32, u8*, s32, s32);
s32 func_i1_8040D530(s32, s32, u32*);
s32 func_i1_804035DC(u16);
u16 func_i1_8040567C(u16);
s32 func_i1_80406F70(s32);
s32 func_i1_80408EE4(s32*, s32, u32*);

s32 func_i1_80409060(u16 arg0) {
    s32 sp1C;

    if (D_i1_8041B550[arg0].unk_00 & 0x2000) {
        D_i1_80428610 = 0x106;
        return -1;
    }
    func_i1_80408B90();
    sp1C = D_i1_8041B550[arg0].unk_0A;
    func_i1_80408CDC(sp1C);
    func_i1_80408BD4();
    D_i1_8041B550[arg0].unk_00 = 0;
    return 0;
}

s32 func_i1_8040911C(u16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u16 sp1E;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    sp1E = func_i1_80403680(arg0, arg1, arg2);
    if (sp1E == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (func_i1_80409060(sp1E) < 0) {
        return -1;
    }
    if ((arg3 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_804091E0(u16 arg0, s32 arg1) {
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
    if (func_i1_80409060(arg0) < 0) {
        return -1;
    }
    if ((arg1 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_80409310(s32 arg0, u8* arg1, u32 arg2, s32* arg3, OSMesg* arg4, s32* arg5, s32 arg6) {
    s32 sp24;
    s32 sp20;
    u32 sp1C;

    sp24 = func_i1_80408FDC(arg0);

    for (sp20 = 1; sp20 <= sp24; sp20++) {
        func_i1_8040D530(arg0 + D_i1_80428638, sp20, &sp1C);
        if (sp1C > arg2) {
            break;
        }
    }

    sp20--;
    if (sp20 > 0) {
        if (func_i1_8040A5F8(arg0 + D_i1_80428638, arg1, sp20, arg6) < 0) {
            return -1;
        }
        func_i1_8040D530(arg0 + D_i1_80428638, sp20, &sp1C);
    } else {
        if (func_i1_8040A5F8(arg0 + D_i1_80428638, D_i1_80415190, 1, arg6) < 0) {
            return -1;
        }
        bcopy(D_i1_80415190, arg1, arg2);
        sp1C = arg2;
    }
    
    *arg3 = D_i1_80419EA0.unk_3C[arg0 + sp20 - 1];
    *arg4 = arg1 + sp1C;
    
    if (arg2 <= sp1C) {
        *arg5 = 0;
    } else {
        *arg5 = arg2 - sp1C;
    }
    return 0;
}

s32 func_i1_804094E0(u16 arg0, s32 arg1, s32 arg2) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    OSMesg sp40;
    s32 sp3C;
    s32 sp38 = 0;

    sp4C = D_i1_8041B550[arg0].unk_0A;

    while (arg2 != 0) {
        sp44 = D_i1_8041B550[arg0].unk_00;

        func_i1_80409310(sp4C, arg1, arg2, &sp48, &sp40, &sp3C, (sp44 & 0x400) ? 1 : 0);
        sp4C = sp48;
        arg1 = sp40;
        arg2 = sp3C;
        
        if (sp38++ == 4) {
            while (true) {}
        }
    }

    return 0;
}

s32 func_i1_804095F4(u16 arg0, s32 arg1, u32 arg2) {
    u32 sp1C;

    if (D_i1_8041B550[arg0].unk_00 & 0x1000) {
       if (func_i1_804035DC(arg0) < 0) {
            D_i1_80428610 = 0x106;
            return -1;
       }
    }
    sp1C = D_i1_8041B550[arg0].unk_0C;
    if ((arg2 == 0) || (sp1C < arg2)) {
        arg2 = sp1C;
    }
    return func_i1_804094E0(arg0, arg1, arg2);
}

s32 func_i1_804096C8(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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
    return func_i1_804095F4(sp1E, arg3, arg4);
}

s32 func_i1_804097BC(u16 arg0, s32 arg1, s32 arg2) {
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
    return func_i1_804095F4(arg0, arg1, arg2);
}

s32 func_i1_804098C4(u16 arg0, u8* arg1, s32 arg2, u32 arg3) {
    s32 sp44;
    u32 sp40;
    u32 sp3C;
    s32 sp38;
    u32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    u8* sp24;

    sp40 = arg3;
    sp24 = arg1;
    sp44 = D_i1_8041B550[arg0].unk_0C;
    sp30 = D_i1_8041B550[arg0].unk_0A;
    if (D_i1_8041B550[arg0].unk_00 & 0x400) {
        sp38 = 1;
    } else {
        sp38 = 0;
    }
    func_i1_80408B90();
    func_i1_80408EE4(&sp30, arg2, &sp3C);
    if (sp3C != 0) {
        func_i1_8040D530(sp30 + D_i1_80428638, 1, &sp34);
        if (func_i1_8040A5F8(sp30 + D_i1_80428638, D_i1_80415190, 1, sp38) < 0) {
            return -1;
        }

        bcopy((sp34 - sp3C) + D_i1_80415190, arg1, (sp3C > sp40) ? sp40 : sp3C);

        sp24 += (sp3C > sp40) ? sp40 : sp3C;
        sp40 -= (sp3C > sp40) ? sp40 : sp3C;
        if (sp40 != 0) {
            sp30 = D_i1_80428F70[sp30];
            if (sp30 == 0xFFFF) {
                D_i1_80428610 = 0xF3;
                return -1;
            }
        }
    }

    while (sp40 != 0) {
        sp2C = func_i1_80408FDC(sp30);

        for (sp28 = 1; sp28 <= sp2C; sp28++) {
            func_i1_8040D530(sp30 + D_i1_80428638, sp28, &sp34);
            if (sp34 < sp40) {
                continue;
            }
            
            if (sp34 == sp40) {
                if (func_i1_8040A5F8(sp30 + D_i1_80428638, sp24, sp28, sp38) < 0) {
                    return -1;
                }
                sp40 = 0;
                break;
            }
            if (--sp28 == 0) {
                break;
            } 
            
            func_i1_8040D530(sp30 + D_i1_80428638, sp28, &sp34);
            if (func_i1_8040A5F8(sp30 + D_i1_80428638, sp24, sp28, sp38) < 0) {
                return -1;
            }
            sp30 += sp28;
            sp40 -= sp34;
            sp24 += sp34;
            break;
        }

        if (sp28 <= sp2C) {
            break;
        }
        if (func_i1_8040A5F8(sp30 + D_i1_80428638, sp24, sp2C, sp38) < 0) {
            return -1;
        }
        func_i1_8040D530(sp30 + D_i1_80428638, sp2C, &sp34);
        sp40 -= sp34;
        sp24 += sp34;
        sp30 = (sp30 + sp2C) - 1;

        if ((sp30 = D_i1_80428F70[sp30]) == 0xFFFF) {
            D_i1_80428610 = 0xF3;
            return -1;
        }
    }

    if (sp40 != 0) {
        if (func_i1_8040A5F8(sp30 + D_i1_80428638, D_i1_80415190, 1, sp38) < 0) {
            return -1;
        }
        bcopy(D_i1_80415190, sp24, sp40);
    }

    return 0;
}

s32 func_i1_80409D78(u16 arg0, s32 arg1, s32 arg2, u32 arg3) {
    s32 sp1C;

    if (D_i1_8041B550[arg0].unk_00 & 0x1000) {
        if (func_i1_804035DC(arg0) < 0) {
            D_i1_80428610 = 0x106;
            return -1;
        }
    }
    sp1C = D_i1_8041B550[arg0].unk_0C;
    if (arg3 == 0 || (sp1C - arg2) < arg3) {
        arg3 = sp1C - arg2;
    }
    return func_i1_804098C4(arg0, arg1, arg2, arg3);
}

s32 func_i1_80409E64(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
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
    return func_i1_80409D78(sp1E, arg3, arg4, arg5);
}

s32 func_i1_80409F5C(u16 arg0, s32 arg1, s32 arg2, s32 arg3) {
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
    return func_i1_80409D78(arg0, arg1, arg2, arg3);
}
