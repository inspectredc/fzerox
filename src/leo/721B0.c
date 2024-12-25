#include "global.h"
#include "unk_leo.h"

void func_i1_804030A0(void) {
    LeoByteToLBA(0, 1, 0);
}

extern unk_leo_804285D0 D_i1_804285D0;

void func_i1_804030D0(u16 arg0) {
    D_i1_804285D0.unk_00 = arg0;
}

void func_i1_804030EC(u16 arg0) {
    D_i1_804285D0.unk_02 = arg0;
}

s32 func_i1_80406DE4(void*, void*, size_t);

void func_i1_80403108(void* arg0) {
    bzero(D_i1_804285D0.unk_04, 2);
    if (arg0 != NULL) {
        func_i1_80406DE4(D_i1_804285D0.unk_04, arg0, 2);
    }
}

void func_i1_80403164(void* arg0) {
    bzero(D_i1_804285D0.unk_06, 4);
    if (arg0 != NULL) {
        func_i1_80406DE4(D_i1_804285D0.unk_06, arg0, 4);
    }
}

void func_i1_804031C0(void* arg0) {
    bzero(D_i1_804285D0.unk_10, 20);
    if (arg0 != NULL) {
        func_i1_80406DE4(D_i1_804285D0.unk_10, arg0, 20);
    }
}

void func_i1_80406390(void*);
void func_i1_8040641C(LEODiskTime*, void*);

void func_i1_8040321C(void) {
    LEODiskTime sp18;

    func_i1_80406390(&sp18);
    func_i1_8040641C(&sp18, &D_i1_804285D0.unk_2C);
}

void func_i1_80403258(u16 arg0) {
    D_i1_804285D0.unk_0A = arg0;
}

void func_i1_80403274(void* arg0) {
    bzero(D_i1_804285D0.unk_24, 5);
    if (arg0 != NULL) {
        func_i1_80406DE4(D_i1_804285D0.unk_24, arg0, 5);
    }
}

void func_i1_804032D0(s32 arg0) {
    D_i1_804285D0.unk_0C = arg0;
}

extern u8 D_i1_80428654[];
extern u8 D_i1_80428658[];

void func_i1_804032E8(u16 arg0, s32 arg1) {
    func_i1_804030EC(arg0);
    func_i1_804031C0(arg1);
    func_i1_8040321C();
    func_i1_80403108(D_i1_80428654);
    func_i1_80403164(D_i1_80428658);
}

void func_i1_80403340(s32 arg0) {
    D_i1_804285D0.unk_29 = arg0;
}

void func_i1_80403358(u16 arg0) {
    D_i1_804285D0.unk_2A = arg0;
}

void func_i1_80403374(void) {
    bzero(&D_i1_804285D0, sizeof(unk_leo_804285D0));
}

extern s32 D_i1_8042860C;
extern unk_leo_80419EA0 D_i1_80419EA0;

s32 func_i1_804033A4(u16 arg0) {
    if (arg0 > D_i1_8042860C) {
        return -1;
    }
    bcopy(&D_i1_804285D0, &D_i1_80419EA0.unk_16B0[arg0], sizeof(unk_leo_804285D0));
    return 0;
}

s32 func_i1_80403420(u16 arg0) {
    if (arg0 > D_i1_8042860C) {
        return -1;
    }
    bcopy(&D_i1_80419EA0.unk_16B0[arg0], &D_i1_804285D0, sizeof(unk_leo_804285D0));
    return 0;
}

s32 func_i1_80404830(void);

s32 func_i1_8040349C(void) {
    s32 i;
    s32 sp18 = 0;

    if (func_i1_80404830() < 0) {
        return -1;
    }

    for (i = 0; i < D_i1_8042860C; i++) {
        if (D_i1_80419EA0.unk_16B0[i].unk_00 == 0) {
            sp18++;
        }
    }

    return sp18;
}

void func_i1_80403544(u16 arg0) {

    if (D_i1_80419EA0.unk_16B0[arg0].unk_2A < 0xFF) {
        D_i1_80419EA0.unk_16B0[arg0].unk_2A++;
    }
}

void func_i1_804035B0(u16 arg0) {
    D_i1_80419EA0.unk_16B0[arg0].unk_2A = 0;
}

s32 func_i1_80406C10(void*, void*, size_t);

s32 func_i1_804035DC(u16 arg0) {

    if (func_i1_80406C10(D_i1_80419EA0.unk_16B0[arg0].unk_04, D_i1_80428654, 2) != 0) {
        return 0;
    }

    if (func_i1_80406C10(D_i1_80419EA0.unk_16B0[arg0].unk_06, D_i1_80428658, 4) != 0) {
        return 0;
    }
}

s32 func_i1_8040567C(u16);
extern OSMesg D_i1_80428610;
extern u16 D_i1_80428614;

u16 func_i1_80403680(u16 arg0, u8* arg1, u8* arg2) {
    s32 i;

    D_i1_80428610 = 0;
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_i1_8040567C(0xFFFB);
    }

    for (i = 0; i < D_i1_8042860C; i++) {
        if ((D_i1_80419EA0.unk_16B0[i].unk_00 & 0x4000) && (D_i1_80419EA0.unk_16B0[i].unk_02 == arg0) &&
            (func_i1_80406C10(D_i1_80419EA0.unk_16B0[i].unk_10, arg1, 0x14) == 0) &&
            (func_i1_80406C10(D_i1_80419EA0.unk_16B0[i].unk_24, arg2, 5) == 0)) {
            return i;
        }
    }

    D_i1_80428610 = 0xF2;
    return -1;
}

u16 func_i1_804037C4(u16 arg0, s32 arg1) {
    s32 i;

    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }

    for (i = 0; i < D_i1_8042860C; i++) {
        if ((D_i1_80419EA0.unk_16B0[i].unk_00 & 0x8000) && (D_i1_80419EA0.unk_16B0[i].unk_02 == arg0) &&
            (func_i1_80406C10(D_i1_80419EA0.unk_16B0[i].unk_10, arg1, 0x14) == 0)) {
            return i;
        }
    }

    return -1;
}

u16 func_i1_804038A0(u16 arg0) {
    s32 i;

    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_i1_8040567C(0xFFFB);
    }

    for (i = 0; i < D_i1_8042860C; i++) {
        if ((D_i1_80419EA0.unk_16B0[i].unk_00 & 0x8000) && (D_i1_80419EA0.unk_16B0[i].unk_0A == arg0)) {
            return i;
        }
    }

    return -1;
}

u16 func_i1_8040397C(void) {
    s32 i;

    for (i = 0; i < D_i1_8042860C; i++) {
        if (D_i1_80419EA0.unk_16B0[i].unk_00 == 0) {
            return i;
        }
    }

    return -1;
}

extern u16 D_i1_80428F70[];
extern LEOCapacity D_i1_80428638;

s32 func_i1_804039F8(u32 arg0, u32* arg1, s32* arg2, u32* arg3) {
    u32 sp34;
    s32 sp30;
    u32 sp2C;
    u32 sp28;
    s32 i;
    s32 j;
    s32 sp1C;
    s32 sp18;

    sp34 = -1;
    sp30 = -1;
    sp2C = 0;
    sp18 = 1;

    for (i = 4; i <= (D_i1_80428638.endLBA - D_i1_80428638.startLBA); i++) {
        if (D_i1_80428F70[i] != 0) {
            continue;
        }
        j = i;
        while (j < (D_i1_80428638.endLBA - D_i1_80428638.startLBA)) {
            if (D_i1_80428F70[j] != 0) {
                break;
            }
            j++;
        }

        LeoLBAToByte(i + D_i1_80428638.startLBA, (j - i) + 1, &sp28);
        sp1C = 0;
        if (sp18 != 0) {
            sp1C++;
            sp18 = 0;
        }
        if ((sp2C < arg0) && (sp28 > arg0)) {
            sp1C++;
        }
        if ((sp28 <= arg0) && (sp2C < sp28)) {
            sp1C++;
        }
        if ((sp28 >= arg0) && (sp2C > sp28)) {
            sp1C++;
        }
        if (sp1C != 0) {
            sp34 = i;
            sp30 = (j - i) + 1;
            sp2C = sp28;
        }
        i = j;
    }

    if (false) {
        *arg1 = -1;
        *arg2 = 0;
        *arg3 = 0;
        return -1;
    }

    if (sp2C > arg0) {
        for (j = 1; j <= sp30; j++) {
            LeoLBAToByte(sp34 + D_i1_80428638.startLBA, j, &sp28);
            if (sp28 >= arg0) {
                break;
            }
        }

        sp30 = j;
        sp2C = sp28;
    }
    *arg1 = sp34;
    *arg2 = sp30;
    *arg3 = sp2C;

    return 0;
}
