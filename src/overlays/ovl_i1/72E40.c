#include "global.h"
#include "unk_leo.h"

extern void* D_i1_8042A5E4;
extern OSMesgQueue D_i1_8042A5E8;

void func_i1_80403D30(void) {
    osCreateMesgQueue(&D_i1_8042A5E8, &D_i1_8042A5E4, 1);
}

extern OSMesg D_i1_80428610;
extern LEODiskID D_i1_80428618;
s32 func_i1_80404108(LEODiskID*);
void func_i1_8040BD70(void);

s32 func_i1_80403D68(void) {
    s32 i = 0;

    func_i1_8040BD70();
    
    while (true) {
        if (func_i1_80404108(&D_i1_80428618) == 0) {
            break;
        }
    
        if (++i >= 4) {
            return -1;
        }
    
        switch ((s32)D_i1_80428610) {
            case 43:
                D_i1_80428610 = 0xF9;
                return -1;
            case 42:
            case 47:
                break;
            default:
                return -1;
        }
    }
    
    return 0;
}

s32 func_i1_80403D68(void);

s32 func_i1_80403E3C(void) {
    return func_i1_80403D68();
}

s32 func_i1_80403E6C(void) {
    s32 i = 0;

    while (true) {
        if (func_i1_80404108(&D_i1_80428618) == 0) {
            break;
        }

        if (++i >= 4) {
            return -1;
        }

        switch ((s32)D_i1_80428610) {
            case 0x2A:
            case 0x2F:
                return -1;
        }

        return -1;

    }
        
    if (bcmp(&leoBootID, &D_i1_80428618, sizeof(LEODiskID)) == 0) {
        return 0;
    }

    D_i1_80428610 = 0xF5;
    return -1;
}

extern s32 D_i1_80428600;
extern s32 D_i1_80428644;
extern u8 D_i1_80428654[2];
extern u8 D_i1_80428658[4];

void func_i1_8040B320(void);
void func_i1_804040EC(void);

s32 func_i1_80403F4C(s32 arg0, OSMesg* arg1, s32 arg2) {
    s32 i = 0;

    D_i1_80428600 = 0;
    func_i1_8040B320();
    
    
    if ((D_i1_80428654[0] == 0) || (D_i1_80428658[0] == 0)) {
        D_i1_80428644 = 0x107;
        D_i1_80428610 = 0x107;
        return -1;
    }
    
    func_i1_80403D30();
    func_i1_804040EC();
    switch (arg0) {
        case 0x0:
            D_i1_80428610 = LeoCreateLeoManager(0x95, 0x96, arg1, arg2);
            break;
        case 0x101:
            D_i1_80428610 = LeoCJCreateLeoManager(0x95, 0x96, arg1, arg2);
            break;
        case 0x102:
            D_i1_80428610 = LeoCACreateLeoManager(0x95, 0x96, arg1, arg2);
            break;
        default:
            D_i1_80428610 = 0xF4;
            return -1;
            break;
    }
    
    if ((s32)D_i1_80428610 != 0) {
        return -1;
    }
    
    if (arg0 == 0) {
        return func_i1_80403E6C();
    } else {
        return func_i1_80403E3C();
    }
}

extern unk_leo_80419EA0 D_i1_80419EA0;

void func_i1_804040EC(void) {
    D_i1_80419EA0.unk_00[0] = 0;
}

extern OSMesgQueue D_i1_8042A5E8;
extern s32 (*D_i1_8042A62C)(LEOCmd*, LEODiskID*, OSMesgQueue*);
s32 func_i1_804065C0(void);

s32 func_i1_80404108(LEODiskID* arg0) {
    LEOCmd sp1C;

    if (D_i1_8042A62C(&sp1C, arg0, &D_i1_8042A5E8) < 0) {
        D_i1_80428610 = 0xF7;
        return -1;
    }
    return func_i1_804065C0();
}

extern OSMesgQueue* D_i1_80428604;
extern s32 D_i1_80428608;

s32 func_i1_80404174(OSMesgQueue* arg0, s32 arg1) {
    D_i1_80428600 = 1;
    D_i1_80428604 = arg0;
    D_i1_80428608 = arg1;
    return 0;
}

s32 func_i1_804041A8(void) {
    D_i1_80428600 = 0;
    return 0;
}

void func_i1_80411760(s32);
void func_i1_804122A0(s32, s32, s32, s32);

void func_i1_804041C8(void) {
    func_i1_80411760(0);
    func_i1_804122A0(0, 0, 0, 0);
}

extern s32 D_i1_8042860C;
extern u32 D_i1_80428638;

s32 func_i1_80404204(void) {
    s32 sp1C;

    D_i1_80428610 = func_i1_80410C60(&D_i1_80428638, 1);
    if ((s32)D_i1_80428610 != 0) {
        return -1;
    }
    LeoLBAToByte(D_i1_80428638, 3, &sp1C);
    D_i1_8042860C = (sp1C - 0x16B0) / 48;
    return 0;
}

extern u16 D_i1_80428614;
extern s32 D_i1_80428640;

s32 func_i1_8040428C(void) {
    if (func_i1_80404108(&D_i1_80428618) != 0) {
        return -1;
    }
    if (func_i1_80404204() < 0) {
        return -1;
    }
    if (D_i1_80428640 == 0) {
        D_i1_80428644 = 0xF6;
        D_i1_80428610 = 0xF6;
        return -1;
    }
    D_i1_80428614 = 0;
    func_i1_804040EC();
    D_i1_80428644 = 0;
    return 0;
}

s32 func_i1_80404330(void) {
    u8 sp1F;

    D_i1_80428610 = 0;
    D_i1_80428610 = LeoTestUnitReady(&sp1F);
    if (!(sp1F & 1)) {
        if ((s32)D_i1_80428610 == 0x2F) {

        }
        return 1;
    }
    if ((s32)D_i1_80428610 == 0x2A) {
        return 0;
    }
    return -1;
}

extern char D_i1_80428648[]; // "64dd-Multi"

s32 func_i1_804047F0(void);
s32 func_i1_80404830(void);
void func_i1_80406390(void*);
void func_i1_8040641C(LEODiskTime*, void*);
s32 func_i1_80405078(s32);
s32 func_i1_804045AC(void);
s32 func_i1_80406DE4(void*, void*, size_t);

s32 func_i1_804043B8(s32 arg0) {
    LEODiskTime sp20;
    s32 i;
    s32 sp18;

    sp18 = 0;
    if (arg0 == 1) {
        sp18 = 1;
    } else if (arg0 == 2) {
        sp18 = 0;
    } else {
        D_i1_80428610 = 0xF4;
        return -1;
    }

    func_i1_804047F0();
    if (func_i1_80404330() <= 0) {
        return -1;
    }
    if ((sp18 == 0) && (func_i1_80404830() < 0)) {
        sp18 = 1;
    }
    func_i1_80406DE4(D_i1_80419EA0.unk_00, &D_i1_80428648, 10);
    D_i1_80419EA0.unk_0A[0] = '0';
    D_i1_80419EA0.unk_0A[1] = '1';
    D_i1_80419EA0.unk_0A[2] = '0';
    D_i1_80419EA0.unk_0A[3] = '1';
    D_i1_80419EA0.unk_28 = 0;
    func_i1_80406390(&sp20);
    func_i1_8040641C(&sp20, &D_i1_80419EA0.unk_24);
    if (sp18 != 0) {
        bzero(D_i1_80419EA0.unk_3C, sizeof(D_i1_80419EA0.unk_3C));
    } else {
        for (i = 0; i < ARRAY_COUNT(D_i1_80419EA0.unk_3C); i++) {
            if (D_i1_80419EA0.unk_3C[i] != 0xFFFD) {
                D_i1_80419EA0.unk_3C[i] = 0;
            }
        }
    }
    bzero(D_i1_80419EA0.unk_16B0, D_i1_8042860C * sizeof(unk_leo_804285D0));
    func_i1_80405078(0);
    D_i1_80428614 = 0;
    D_i1_80428644 = 0;
    return func_i1_804045AC();
}

s32 func_i1_804069DC(s32, void*, s32);
s32 func_i1_80406830(s32, void*, s32);

s32 func_i1_804045AC(void) {
    D_i1_80419EA0.unk_28++;
    if (func_i1_804069DC(D_i1_80428638, &D_i1_80419EA0, 3) < 0) {
        return -1;
    }
    return 0;
}

s32 func_i1_80404610(void) {
    if (func_i1_80406830(D_i1_80428638, &D_i1_80419EA0, 3) < 0) {
        return -1;
    }
    return 0;
}

s32 func_i1_80404660(void) {
    s32 i;
    s32 j = 0;

    D_i1_80428610 = 0;

    for (i = 0; i < 10; i++) {
        if (D_i1_80419EA0.unk_00[i] != D_i1_80428648[i]) {
            j++;
        }
    }

    if (j != 0) {
        D_i1_80428610 = 0xF0;
        return -1;
    }
    return 0;
}

s32 func_i1_804046F0(void) {
    s32 i = 0;

    D_i1_80428610 = 0;
    func_i1_804047F0();

    while (true) {
        if (((i++ < 5) ^ 1)) {
            return -1;
        }

        func_i1_80404610();
        if ((s32)D_i1_80428610 == 0) {
            break;
        }

        if ((s32)D_i1_80428610 == 0x2F) {
            if (func_i1_80404108(&D_i1_80428618) < 0) {
                return -1;
            }
        } else {
            return -1;
        }
    }

    osWritebackDCache(D_i1_80419EA0.unk_00, 10);

    if (func_i1_80404660() == 0) {
        return 1;
    }

    D_i1_80428610 = 0xF0;

    return 0;
}

s32 func_i1_804047F0(void) {
    if (D_i1_80428644 != 0) {
        D_i1_80428610 = D_i1_80428644;
        return -1;
    }
    return 0;
}

s32 func_i1_80404830(void) {
    s32 err;

    D_i1_80428610 = 0;
    func_i1_804047F0();
    err = func_i1_80404330();
    if (err <= 0) {
        return -1;
    }

    if ((s32)D_i1_80428610 == 0x2F) {
        func_i1_804040EC();
        D_i1_80428644 = 0x2F;
        return -1;
    } else {
        osWritebackDCache(&D_i1_80419EA0, 0xE730);
        if (func_i1_80404660() == 0) {
            return 0;
        }
        if (func_i1_80404610() < 0) {
            return -1;
        }
        if (func_i1_80404660() == 0) {
            return 0;
        }
    }

    D_i1_80428610 = 0xF0;
    return -1;
}

extern u32 D_i1_8042863C;

s32 func_i1_80404924(void) {
    s32 sp24;
    s32 sp20;
    s32 i;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    sp20 = 0;

    for (i = 4; i <= (D_i1_8042863C - D_i1_80428638); i++) {
        if (D_i1_80419EA0.unk_3C[i] != 0) {
            continue;
        }
        LeoLBAToByte(i + D_i1_80428638, 1, &sp24);
        sp20 += sp24;
    }

    return sp20;
}

extern u16 D_i1_80428F70[];

s32 func_i1_80404A08(void) {
    s32 sp24;
    s32 sp20;
    s32 i;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    sp20 = 0;

    for (i = 4; i <= (D_i1_8042863C - D_i1_80428638); i++) {
        if (D_i1_80428F70[i] != 0) {
            continue;
        }
        LeoLBAToByte(i + D_i1_80428638, 1, &sp24);
        sp20 += sp24;
    }

    return sp20;
}

void func_i1_80404AEC(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_i1_80406DE4(D_i1_80428654, arg0, 2);
    }
    if (arg1 != 0) {
        func_i1_80406DE4(D_i1_80428658, arg1, 4);
    }
}

void func_i1_80404B54(void) {
    D_i1_80419EA0.unk_28++;
}

void func_i1_80404B78(void) {
    D_i1_80419EA0.unk_28 = 0;
}

void func_i1_80408B90(void);
void func_i1_80408BD4(void);

s32 func_i1_80404B90(u16 arg0, u16 arg1, u16 arg2) {
    s32 i;

    if (func_i1_80404830() < 0) {
        return -1;
    }

    if ((arg0 < 4) || (D_i1_8042863C < (arg0 + D_i1_80428638 + arg1) - 1)) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    
    func_i1_80408B90();

    for (i = 0; i < arg1; i++) {
        if (D_i1_80428F70[D_i1_80428638 + arg0 + i] != 0) {
            D_i1_80428610 = 0x108;
            return -1;
        }
        D_i1_80428F70[D_i1_80428638 + arg0 + i] = 0xFFFD;
    }

    func_i1_80408BD4();
    if (arg2 != 0) {
        if (func_i1_804045AC() < 0) {
            return -1;
        }
    }
}

s32 func_i1_80404CF0(u16 arg0, u16 arg1, u16 arg2) {
    s32 i;

    if (func_i1_80404830() < 0) {
        return -1;
    }

    if ((arg0 < 4) || (D_i1_8042863C < (arg0 + D_i1_80428638 + arg1) - 1)) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    
    func_i1_80408B90();

    for (i = 0; i < arg1; i++) {
        if (D_i1_80428F70[D_i1_80428638 + arg0 + i] != 0xFFFD) {
            D_i1_80428610 = 0x109;
            return -1;
        }
        D_i1_80428F70[D_i1_80428638 + arg0 + i] = 0;
    }

    func_i1_80408BD4();
    if (arg2 != 0) {
        if (func_i1_804045AC() < 0) {
            return -1;
        }
    }
}

u16 func_i1_8040567C(u16);
s32 func_i1_80406F70(s32);
s32 func_i1_804038A0(s32);
s32 func_i1_804037C4(s32, s32);
s32 func_i1_8040397C(void);
void func_i1_80403374(void);
void func_i1_804032E8(s32, s32);
void func_i1_804030D0(s32);
s32 func_i1_80403258(u16);
void func_i1_80403358(s32);
void func_i1_804033A4(s32);

s32 func_i1_80404E50(u16 arg0, s32 arg1, s32 arg2) {
    u16 sp1E;
    u16 sp1C;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if ((arg0 == 0xFFFC) && ((arg0 = func_i1_8040567C(0xFFFB), (arg0 == 0xFFFE)) || (arg0 == 0xFFFF))) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (func_i1_80406F70(arg1) < 0) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (func_i1_804038A0(arg0) == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (func_i1_804037C4(arg0, arg1) != 0xFFFF) {
        D_i1_80428610 = 0x100;
        return -1;
    }
    sp1C = func_i1_8040397C();
    if (sp1C == 0xFFFF) {
        D_i1_80428610 = 0xF1;
        return -1;
    }
    sp1E = sp1C;
    if (func_i1_804038A0(sp1E) != 0xFFFF) {
        sp1E = 0x1000;
        while (true) {
            if (func_i1_804038A0(sp1E) == 0xFFFF) {
                break;
            }

            sp1E = (sp1E < D_i1_8042860C) ? D_i1_8042860C : sp1E + 1;
        }
    }
    func_i1_80403374();
    func_i1_804032E8(arg0, arg1);
    func_i1_804030D0(0x8000);
    func_i1_80403258(sp1E);
    func_i1_80403358(0);
    func_i1_804033A4(sp1C);
    if ((arg2 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_80405078(s32 arg0) {
    u16 sp1E;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (func_i1_804037C4(0xFFFE, "/") != 0xFFFF) {
        D_i1_80428610 = 0x100;
        return -1;
    }
    sp1E = func_i1_8040397C();
    if (sp1E != 0) {
        D_i1_80428610 = 0x103;
        return -1;
    }
    func_i1_80403374();
    func_i1_804032E8(0xFFFE, "/");
    func_i1_804030D0(0x8000);
    func_i1_80403258(0);
    func_i1_80403358(0);
    func_i1_804033A4(sp1E);
    if ((arg0 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_80405174(u16 arg0, s32 arg1) {
    u16 sp1E;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if ((arg0 == 0xFFFC) && ((arg0 = func_i1_8040567C(0xFFFB), (arg0 == 0xFFFE)) || (arg0 == 0xFFFF))) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    sp1E = func_i1_804037C4(arg0, arg1);
    if (sp1E == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    D_i1_80428614 = sp1E;
    return 0;
}

s32 func_i1_80405264(u16 arg0) {
    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        return 0;
    }
    if ((arg0 == 0xFFFC) && ((arg0 = func_i1_8040567C(0xFFFB), (arg0 == 0xFFFE)) || (arg0 == 0xFFFF))) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (func_i1_804038A0(arg0) == 0xFFFF) {
        return 0xF2;
    }
    D_i1_80428614 = arg0;
    return 0;
}

s32 func_i1_80405334(u16 arg0) {
    return func_i1_80405264(arg0);
}

s32 func_i1_80405368(void) {
    return func_i1_80405264(0xFFFC);
}

extern u16 D_i1_8042A600;
extern u16 D_i1_8042A602;

s32 func_i1_80405398(u16 arg0) {

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_i1_8040567C(0xFFFB);
        if (arg0 == 0xFFFE) {
            D_i1_80428610 = 0xF4;
            return -1;
        }
    }
    if ((arg0 == 0xFFFF) || func_i1_804038A0(arg0) == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    D_i1_8042A602 = 0;
    D_i1_8042A600 = arg0;
}

extern unk_leo_804285D0 D_i1_8041B550[];

u16 func_i1_8040547C(void) {

    while (D_i1_8042A602 < D_i1_8042860C) {
        if ((D_i1_80419EA0.unk_16B0[D_i1_8042A602].unk_02 == D_i1_8042A600) && (D_i1_80419EA0.unk_16B0[D_i1_8042A602].unk_00 & 0x8000)) {
            return  D_i1_8041B550[D_i1_8042A602++].unk_0A;
        }
        D_i1_8042A602++;
    }

    return -1;
}

u16 func_i1_8040555C(u16 arg0, s32 arg1) {
    u16 sp1E;

    if (func_i1_80404830() < 0) {
        return -16;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if ((arg0 == 0xFFFC) && ((arg0 = func_i1_8040567C(0xFFFB), (arg0 == 0xFFFE)) || (arg0 == 0xFFFF))) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (func_i1_80406F70(arg1) < 0) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    sp1E = func_i1_804037C4(arg0, arg1);
    if (sp1E != 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    return D_i1_8041B550[sp1E].unk_0A;
}

u16 func_i1_8040567C(u16 arg0) {
    u16 sp1E;

    if (func_i1_80404830() < 0) {
        return -16;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if (arg0 == 0) {
        return -2;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_i1_8040567C(0xFFFB);
    }
    sp1E = func_i1_804038A0(arg0);
    if (sp1E == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    return D_i1_8041B550[arg0].unk_02;
}

u16 func_i1_80405754(void) {
    if (func_i1_80404830() < 0) {
        return -16;
    }
    return D_i1_80428614;
}

s32 func_i1_80405798(u16 arg0, u16 arg1) {
    u16 sp1E;
    u16 sp1C;
    u16 sp1A;

    if (func_i1_80404830() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_i1_80428614;
    }
    if (arg1 == 0xFFFB) {
        arg1 = D_i1_80428614;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_i1_8040567C(0xFFFB);
    }
    if (arg1 == 0xFFFC) {
        arg1 = func_i1_8040567C(0xFFFB);
    }
    if (arg0 == 0) {
        D_i1_80428610 = 0x104;
        return -1;
    }
    if (arg0 == 0xFFFE) {
        D_i1_80428610 = 0x104;
        return -1;
    }
    if (arg0 == arg1) {
        D_i1_80428610 = 0x104;
        return -1;
    }
    sp1C = func_i1_804038A0(arg0);
    if (sp1C == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    sp1A = func_i1_804038A0(arg1);
    if (sp1A == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    sp1E = D_i1_8041B550[sp1C].unk_02;
    if (sp1E == arg1) {
        return 0;
    }
    if (func_i1_804037C4(arg1, D_i1_80419EA0.unk_16B0[sp1C].unk_10) != 0xFFFF) {
        D_i1_80428610 = 0x100;
        return -1;
    }
    D_i1_8041B550[sp1C].unk_02 = arg1;
    return 0;
}

s32 func_i1_804059B8(u16 arg0, s32 arg1, s32 arg2) {
    u16 sp1E;
    u16 sp1C;

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
    if (arg0 == 0) {
        D_i1_80428610 = 0x104;
        return -1;
    }
    if (arg0 == 0xFFFE) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    sp1C = func_i1_804038A0(arg0);
    if (sp1C == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    sp1E = D_i1_8041B550[sp1C].unk_02;
    if (func_i1_804037C4(sp1E, arg1) != 0xFFFF) {
        D_i1_80428610 = 0x100;
        return -1;
    }
    bzero(D_i1_80419EA0.unk_16B0[sp1C].unk_10, 0x14);
    func_i1_80406DE4(D_i1_80419EA0.unk_16B0[sp1C].unk_10, arg1, 0x14);
    if ((arg2 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_80405B98(u16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u16 sp1E = func_i1_804037C4(arg0, arg1);

    if (sp1E == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    func_i1_804059B8(sp1E, arg2, arg3);
}

s32 func_i1_80405C0C(u16 arg0, s32 arg1) {
    u16 i;
    u16 sp1C;
    s32 sp18;

    if (D_i1_8041B550[arg0].unk_00 & 0x2000) {
        D_i1_80428610 = 0x106;
        return -1;
    }
    sp1C = D_i1_8041B550[arg0].unk_0A;

    for (i = 0, sp18 = 0; i < D_i1_8042860C; i++) {
        if (D_i1_8041B550[i].unk_00 == 0) {
            continue;
        } 
        if (D_i1_8041B550[i].unk_02 == sp1C) {
            sp18++;
        }
    }

    if (sp18 != 0) {
        D_i1_80428610 = 0x103;
        return -1;
    }
    bzero(&D_i1_80419EA0.unk_16B0[arg0], 0x30);
    if ((arg1 != 0) && (func_i1_804045AC() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_i1_80405D9C(u16 arg0, s32 arg1, s32 arg2) {
    u16 sp26;
    s32 pad[2];
    s32 sp18;

    sp18 = 0;
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
    if (arg0 == 0) {
        D_i1_80428610 = 0x106;
        return -1;
    }
    if (arg0 == 0xFFFE) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    if (arg0 == 0xFFFB) {
        D_i1_80428610 = 0xF4;
        return -1;
    }
    sp26 = func_i1_804038A0(arg0);
    if (sp26 == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (func_i1_80405C0C(sp26, arg2) < 0) {
        return -1;
    }
    return 0;
}

s32 func_i1_80405EFC(u16 arg0, s32 arg1) {
    u16 sp1E;

    sp1E = func_i1_804038A0(arg0);
    if (sp1E == 0xFFFF) {
        D_i1_80428610 = 0xF2;
        return -1;
    }
    if (func_i1_80405C0C(sp1E, arg1) < 0) {
        return -1;
    }
    return 0;
}
