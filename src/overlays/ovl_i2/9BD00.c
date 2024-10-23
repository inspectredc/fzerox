#include "global.h"

extern unk_801247C0 D_801247C0;

void func_i2_80103728(s32, size_t, void*, size_t);

void func_i2_801003B0(unk_struct_40* arg0) {
    func_i2_80103728(0, (uintptr_t) &D_801247C0.unk_33C0 - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_40));
}

void func_i2_801003EC(unk_struct_3F80* arg0) {
    func_i2_80103728(0, (uintptr_t) &D_801247C0.unk_3400 - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_3F80));
}

void func_i2_80100428(unk_struct_80* arg0, s32 arg1) {
    func_i2_80103728(0, (uintptr_t) &D_801247C0.unk_7380[arg1] - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_80));
}

void func_i2_8010046C(unk_struct_60* arg0) {
    func_i2_80103728(0, (uintptr_t) &D_801247C0.unk_7F80 - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_60));
}

void func_i2_801004A8(unk_struct_19E0* arg0) {
    s32 i;
    unk_struct_19E0* var_s2;
    unk_struct_19E0* var_s0;

    for (var_s0 = D_801247C0.unk_00, i = 0, var_s2 = arg0; i < 2 * sizeof(unk_struct_19E0);
         i += sizeof(unk_struct_19E0), var_s0++, var_s2++) {
        func_i2_80103728(0, (uintptr_t) var_s0 - (uintptr_t) &D_801247C0, var_s2, 0x19E0);
    }
}

extern unk_800E5FF8 D_800E5FF8[];
extern u32 D_800CD3CC;

s32 func_i2_80100810(s32, s32);
s32 func_i2_8010387C(s32);

s32 func_i2_80100520(s32 arg0) {
    s32 i;
    s32 sp18;
    s32 temp_a1 = D_802A6B40[arg0].unk_00;
    unk_800E5FF8* var_v0 = D_800E5FF8;

    for (i = 0; i < 3; i++) {
        if (temp_a1 != var_v0->unk_0000) {
            var_v0->unk_0000 = 0;
        }
        var_v0++;
    }
    switch (D_800CD3CC) {
        case 3:
        case 4:
            break;
        case 0:
        case 1:
            sp18 = func_i2_80100810(arg0, -1);
            break;
        case 2:
            sp18 = func_i2_8010387C(arg0);
            break;
    }
    return sp18;
}

s32 func_i2_801005CC(s32 arg0) {
    s32 i;
    s32 var_a0;
    s32 var_v1;
    unk_800E5FF8* var_a1;

    var_v1 = -1;

    for (i = 0, var_a1 = D_800E5FF8; i < 3; i++, var_a1++) {
        if (var_a1->unk_0000 == 0) {
            var_v1 = i;
            break;
        }
    }

    if (var_v1 != -1) {
        return var_v1;
    }

    for (i = 0, var_a1 = D_800E5FF8; i < 3; i++, var_a1++) {
        if (var_a1->unk_3F68 != 1) {
            var_v1 = i;
            break;
        }
    }

    var_a0 = -1;
    if (var_v1 != -1) {
        return var_v1;
    }

    for (i = 0, var_a1 = D_800E5FF8; i < 3; i++, var_a1++) {
        if (arg0 != (var_a1->unk_0000 % 32)) {
            var_v1 = i;
            var_a0 = var_a1->unk_0004;
            break;
        }
    }

    if (var_a0 != -1) {
        for (i = var_v1 + 1, var_a1 = &D_800E5FF8[i]; i < 3; i++, var_a1++) {
            if (arg0 != (var_a1->unk_0000 % 32)) {
                if (var_a0 < var_a1->unk_0004) {
                    var_a0 = var_a1->unk_0004;
                    var_v1 = i;
                }
            }
        }
    } else {
        for (i = 0, var_a1 = D_800E5FF8; i < 3; i++, var_a1++) {
            if (arg0 == (var_a1->unk_0000 % 32)) {
                if (var_a0 < var_a1->unk_0004) {
                    var_a0 = var_a1->unk_0004;
                    var_v1 = i;
                }
            }
        }
    }
    return var_v1;
}

bool func_i2_80100B38(unk_80141C88*);
s32 func_i2_801014D4(unk_80141C88*);
s32 func_i2_801005CC(s32);
void func_i2_80102F70(unk_struct_19E0*, void*, unk_800E5FF8*, s32);
void func_i2_8010300C(unk_struct_19E0*, void*, unk_800E5FF8*, s32);
extern unk_struct_19E0 D_i2_8010D7F0[];
extern u16 D_i2_8010D830[];

s32 func_i2_80100810(s32 arg0, s32 arg1) {
    s32 pad[2];
    s32 var_t0;
    s32 pad2[4];
    unk_80141C88 sp24;
    s32 temp_v0;

    temp_v0 = func_i2_801014D4(&sp24);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    if (sp24.unk_00 != arg0) {
        return 2;
    }

    if (func_i2_80100B38(&sp24)) {
        return 0;
    }
    if (arg1 == -1) {
        var_t0 = func_i2_801005CC(arg0);

        if ((D_800E5FF8[var_t0].unk_0000 != 0) && (D_800E5FF8[var_t0].unk_3F68 == 1) &&
            (sp24.unk_00 == (D_800E5FF8[var_t0].unk_0000 & 0x1F)) && (D_800E5FF8[var_t0].unk_0004 < sp24.unk_08)) {
            return 0;
        }
    } else {
        var_t0 = arg1;
    }

    func_i2_801003EC(D_i2_8010D830);
    func_i2_80102F70(D_i2_8010D7F0, D_i2_8010D830, &D_800E5FF8[var_t0], 1);
    func_i2_8010300C(D_i2_8010D7F0, D_i2_8010D830, &D_800E5FF8[var_t0], 1);

    return 0;
}

bool func_i2_80100950(u8* arg0, u8* arg1) {
    bool var_v1 = true;

    if (arg1[0] != arg0[0]) {
        var_v1 = false;
    } else if (arg1[1] != arg0[1]) {
        var_v1 = false;
    } else if (arg1[2] != arg0[2]) {
        var_v1 = false;
    } else if (arg1[3] != arg0[3]) {
        var_v1 = false;
    } else if (arg1[4] != arg0[4]) {
        var_v1 = false;
    } else if (arg1[5] != arg0[5]) {
        var_v1 = false;
    } else if (arg1[6] != arg0[6]) {
        var_v1 = false;
    } else if (arg1[7] != arg0[7]) {
        var_v1 = false;
    } else if (arg1[8] != arg0[8]) {
        var_v1 = false;
    } else if (arg1[9] != arg0[9]) {
        var_v1 = false;
    } else if (arg1[10] != arg0[10]) {
        var_v1 = false;
    } else if (arg1[11] != arg0[11]) {
        var_v1 = false;
    } else if (arg1[12] != arg0[12]) {
        var_v1 = false;
    } else if (arg1[13] != arg0[13]) {
        var_v1 = false;
    } else if (arg1[14] != arg0[14]) {
        var_v1 = false;
    } else if (arg1[15] != arg0[15]) {
        var_v1 = false;
    } else if (arg1[16] != arg0[16]) {
        var_v1 = false;
    } else if (arg1[17] != arg0[17]) {
        var_v1 = false;
    } else if (arg1[18] != arg0[18]) {
        var_v1 = false;
    } else if (arg1[19] != arg0[19]) {
        var_v1 = false;
    }
    return var_v1;
}

bool func_i2_80100B38(unk_80141C88* arg0) {
    s32 var_s1;
    s32 i;
    unk_800E5FF8* var_s0 = D_800E5FF8;

    for (i = 0; i < 3; i++) {
        var_s1 = true;
        if (var_s0->unk_3F68 != arg0->unk_10) {
            var_s1 = false;
        } else if (var_s0->unk_3F64 != arg0->unk_0C) {
            var_s1 = false;
        } else if (var_s0->unk_0000 != arg0->unk_04) {
            var_s1 = false;
        } else if (var_s0->unk_0004 != arg0->unk_08) {
            var_s1 = false;
        } else if (!func_i2_80100950(var_s0->unk_3F6A, arg0->unk_1D)) {
            var_s1 = false;
        }

        if (var_s1) {
            break;
        }
        var_s0++;
    }
    return var_s1;
}

void func_i2_80103310(unk_struct_80*, s32);

// FAKE!! FIX THIS!
s32 func_i2_80100C18(s32 arg0) {
    unk_struct_80* temp_a0 = (arg0 << 7) + (u8*) D_i2_8010D7F0;

    func_i2_80100428(temp_a0, arg0);
    func_i2_80103310(temp_a0, arg0);
    return 0;
}

s32 func_i2_80100C60(s32 arg0) {
    func_i2_8010046C(D_i2_8010D7F0);
    func_i2_801033B8(D_i2_8010D7F0, arg0);
    return 0;
}

s32 func_i2_8010356C(unk_struct_19E0*);
s32 func_i2_8010358C(unk_struct_19E0*);
s32 func_i2_801035B0(void*, s32);
s32 func_i2_801035E4(void*);
s32 func_i2_80103608(unk_struct_40*);
s32 func_i2_8010362C(unk_struct_3F80*);
s32 func_i2_80103650(unk_struct_80*);
s32 func_i2_80103674(void*);

void func_i2_80100C9C(unk_801247C0* arg0) {
    s32 i;
    s32 j;
    s32 temp_v0;
    unk_struct_80* var_s1;
    unk_struct_19E0* var_v1;

    temp_v0 = func_i2_8010356C(arg0->unk_00);

    for (i = 0, var_v1 = arg0->unk_00; i < 2; i++, var_v1++) {
        var_v1->unk_00.unk_0E = temp_v0;
    }
    temp_v0 = func_i2_8010358C(arg0->unk_00);

    for (i = 0, var_v1 = arg0->unk_00; i < 2; i++, var_v1++) {
        var_v1->unk_10.unk_00 = temp_v0;
    }

    for (j = 0; j < 24; j++) {
        temp_v0 = func_i2_801035B0(arg0, j);

        for (i = 0, var_v1 = arg0->unk_00; i < 2; i++, var_v1++) {
            var_v1->unk_20[j].unk_00 = temp_v0;
        }
    }
    temp_v0 = func_i2_801035E4(arg0);

    for (i = 0, var_v1 = arg0->unk_00; i < 2; i++, var_v1++) {
        var_v1->unk_19A0.unk_00 = temp_v0;
    }
    arg0->unk_33C0.unk_00 = func_i2_80103608(&arg0->unk_33C0);
    arg0->unk_3400.unk_00 = func_i2_8010362C(&arg0->unk_3400);

    for (i = 0, var_s1 = arg0->unk_7380; i < 24; i++, var_s1++) {
        var_s1->unk_00 = func_i2_80103650(var_s1);
    }
    arg0->unk_7F80.unk_00 = func_i2_80103674(&arg0->unk_7F80);
    func_i2_80103728(1, 0, arg0, 0x8000);
}

void func_i2_80100DDC(unk_struct_19E0* arg0, s32 arg1, u16 arg2) {
    unk_struct_19E0* temp_a2 = &arg0[arg1];

    temp_a2->unk_00.unk_0E = arg2;
    func_i2_80103728(1, (uintptr_t) &D_801247C0.unk_00[arg1].unk_00 - (uintptr_t) &D_801247C0, temp_a2,
                     sizeof(unk_struct_10));
}

void func_i2_80100E64(unk_struct_19E0* arg0, s32 arg1, u16 arg2) {
    unk_struct_19E0* temp_v1 = &arg0[arg1];
    temp_v1->unk_10.unk_00 = arg2;

    func_i2_80103728(1, (uintptr_t) &D_801247C0.unk_00[arg1].unk_10 - (uintptr_t) &D_801247C0, &temp_v1->unk_10, 0x10);
}

void func_i2_80100ED4(unk_struct_19E0* arg0, s32 arg1, s32 arg2, u16 arg3) {
    unk_struct_19E0* temp_v1 = &arg0[arg1];
    unk_struct_110* temp_v0 = &temp_v1->unk_20[arg2];

    temp_v0->unk_00 = arg3;
    func_i2_80103728(1, (uintptr_t) &D_801247C0.unk_00[arg1].unk_20[arg2] - (uintptr_t) &D_801247C0, temp_v0,
                     sizeof(unk_struct_110));
}

void func_i2_80100F7C(unk_struct_19E0* arg0, s32 arg1, u16 arg2) {
    unk_struct_19E0* temp_v1 = &arg0[arg1];

    temp_v1->unk_19A0.unk_00 = arg2;
    func_i2_80103728(1, (uintptr_t) &D_801247C0.unk_00[arg1].unk_19A0 - (uintptr_t) &D_801247C0, &temp_v1->unk_19A0,
                     sizeof(unk_struct_40_2));
}

void func_i2_80100FEC(unk_struct_40* arg0) {
    arg0->unk_00 = func_i2_80103608(arg0);
    func_i2_80103728(1, (uintptr_t) &D_801247C0.unk_33C0 - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_40));
}

void func_i2_80101034(unk_struct_3F80* arg0) {
    arg0->unk_00 = func_i2_8010362C(arg0);
    func_i2_80103728(1, (uintptr_t) &D_801247C0.unk_3400 - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_3F80));
}

void func_i2_8010107C(unk_struct_80* arg0, s32 arg1) {
    arg0->unk_00 = func_i2_80103650(arg0);
    func_i2_80103728(1, (uintptr_t) &D_801247C0.unk_7380[arg1] - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_80));
}

void func_i2_801010D0(unk_struct_60* arg0) {
    arg0->unk_00 = func_i2_80103674(arg0);
    func_i2_80103728(1, (uintptr_t) &D_801247C0.unk_7F80 - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_60));
}

s32 func_i2_80101118(s32 arg0) {
    u16 temp_s2;
    s32 i;

    func_i2_80102214(&D_i2_8010D7F0[0].unk_20[arg0], arg0);
    D_i2_8010D7F0[1].unk_20[arg0] = D_i2_8010D7F0[0].unk_20[arg0];

    temp_s2 = func_i2_801035B0(D_i2_8010D7F0, arg0);

    for (i = 0; i < 2; i++) {
        func_i2_80100ED4(D_i2_8010D7F0, i, arg0, temp_s2);
    }

    return 0;
}

extern s32 D_800CCFC0;

s32 func_i2_801011FC(void) {
    u16 temp_s1;
    s32 i;

    if (D_800CCFC0 == 0) {
        return 3;
    }
    func_i2_80102350(&D_i2_8010D7F0[0].unk_19A0);

    D_i2_8010D7F0[1].unk_19A0 = D_i2_8010D7F0[0].unk_19A0;

    temp_s1 = func_i2_801035E4(&D_i2_8010D7F0);

    for (i = 0; i < 2; i++) {
        func_i2_80100F7C(&D_i2_8010D7F0, i, temp_s1);
    }

    return 0;
}

s32 func_i2_801012CC(s32 arg0) {
    s32 pad[2];
    void* temp_a0;

    temp_a0 = (arg0 << 7) + (u8*) D_i2_8010D7F0;

    func_i2_8010259C(temp_a0);
    func_i2_8010107C(temp_a0, arg0);
    return 0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101310.s")

s32 func_i2_80101414(void) {
    u16 temp_s2;
    s32 i;

    func_i2_80101FEC(&D_i2_8010D7F0);
    D_i2_8010D7F0[1].unk_00 = D_i2_8010D7F0[0].unk_00;

    temp_s2 = func_i2_8010356C(&D_i2_8010D7F0);

    for (i = 0; i < 2; i++) {
        func_i2_80100DDC(&D_i2_8010D7F0, i, temp_s2);
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801014D4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101590.s")

s32 func_i2_80101690(s32 arg0, s32 arg1) {
    func_i2_801023D8(arg1);
    func_i2_80100FEC(&D_i2_8010D7F0);
    func_i2_801024F8(arg1);
    func_i2_80101034(&D_i2_8010D830);
    return 0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801016DC.s")

s32 func_i2_80101784(unk_801247C0* arg0, s32 arg1) {
    func_i2_80101944(arg0, arg1);
    func_i2_80100C9C(arg0);
    func_i2_80102600(arg0);
    return 0;
}

s32 func_i2_801017B8(s32 arg0) {
    u16 temp_s2;
    s32 i;

    func_i2_80101D18(&D_i2_8010D7F0[0].unk_20[arg0], 1);
    D_i2_8010D7F0[1].unk_20[arg0] = D_i2_8010D7F0[0].unk_20[arg0];

    temp_s2 = func_i2_801035B0(D_i2_8010D7F0, arg0);

    for (i = 0; i < 2; i++) {
        func_i2_80100ED4(D_i2_8010D7F0, i, arg0, temp_s2);
    }

    func_i2_80102CA4(&D_i2_8010D7F0, arg0);

    return 0;
}

s32 func_i2_801018A8(s32 arg0) {
    s32 i;
    unk_800E5FF8* var_v0;

    for (i = 0, var_v0 = D_800E5FF8; i < 3; i++, var_v0++) {
        if (var_v0->unk_0000 == D_802A6B40[arg0].unk_00) {
            var_v0->unk_0000 = 0;
        }
    }
    func_i2_80101DE8(&D_i2_8010D7F0, 1);
    func_i2_80100FEC(&D_i2_8010D7F0);
    func_i2_80101E68(&D_i2_8010D830, 1);
    func_i2_80101034(&D_i2_8010D830);
    return 0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101944.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101B8C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101C04.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101C78.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101CCC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101D18.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101DE8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101E68.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101EBC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101F24.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101F9C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101FEC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102110.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801021B4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102214.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102350.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801023D8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801024F8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010259C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102600.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102784.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102A7C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102B20.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102CA4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102F70.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010300C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103108.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103310.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801033B8.s")

s32 func_i2_801034F8(u8* arg0, s32 arg1) {
    u16 var_v1;
    u8* var_v0;
    s32 i;

    var_v0 = arg0;
    var_v1 = 0;

    for (i = 0; i < arg1; i++) {
        var_v1 += *var_v0++;
    }

    return var_v1;
}

s32 func_i2_8010356C(unk_struct_19E0* arg0) {
    return func_i2_801034F8(arg0->unk_00.unk_00, 14);
}

s32 func_i2_8010358C(unk_struct_19E0* arg0) {
    return func_i2_801034F8(arg0->unk_10.unk_02, 14);
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801035B0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801035E4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103608.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010362C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103650.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103674.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103698.s")

extern OSMesgQueue D_800DCA68;
extern OSIoMesg D_i2_801117B0;
extern OSPiHandle* D_i2_8011183C;

void func_i2_80103728(s32 arg0, size_t arg1, void* arg2, size_t arg3) {
    osWritebackDCache(arg2, arg3);
    osInvalDCache(osPhysicalToVirtual((uintptr_t) arg2), arg3);
    D_i2_801117B0.hdr.pri = 0;
    D_i2_801117B0.hdr.retQueue = &D_800DCA68;
    D_i2_801117B0.dramAddr = arg2;
    D_i2_801117B0.devAddr = arg1 + 0x08000000;
    D_i2_801117B0.size = arg3;
    osEPiStartDma(D_i2_8011183C, &D_i2_801117B0, arg0);
    osRecvMesg(&D_800DCA68, NULL, OS_MESG_BLOCK);
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801037CC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010382C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010387C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103930.s")

extern u8 D_i2_8010ADE8[];

void func_i2_801039BC(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            D_i2_8010D7F0[i].unk_00.unk_00[j] = D_i2_8010ADE8[j];
            func_i2_80100DDC(D_i2_8010D7F0, i, 0x1234);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/D_i2_8010ADE0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/D_i2_8010ADE8.s")
