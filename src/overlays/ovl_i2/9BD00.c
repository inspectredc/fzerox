#include "global.h"
#include "fzx_game.h"
#include "ovl_i2.h"

OSIoMesg D_i2_801117B0;
OSPiHandle D_i2_801117C8;
OSPiHandle* D_i2_8011183C;
s16 D_80111840;
u8 D_i2_80111848[30];

uintptr_t D_i2_80106DF0[][3] = {
    { 0x0, 0x40, 0x60 },           { 0x1B30, 0x1B70, 0x1B90 },    { 0x37B0, 0x37F0, 0x3810 },
    { 0x5070, 0x50B0, 0x50D0 },    { 0x6B50, 0x6B90, 0x6BB0 },    { 0x8A30, 0x8A70, 0x8A90 },
    { 0xA920, 0xA960, 0xA980 },    { 0xC410, 0xC450, 0xC470 },    { 0xDDC0, 0xDE00, 0xDE20 },
    { 0xF920, 0xF960, 0xF980 },    { 0x11370, 0x113B0, 0x113D0 }, { 0x12980, 0x129C0, 0x129E0 },
    { 0x149F0, 0x14A30, 0x14A50 }, { 0x16550, 0x16590, 0x165B0 }, { 0x18410, 0x18450, 0x18470 },
    { 0x1A6B0, 0x1A6F0, 0x1A710 }, { 0x1C6E0, 0x1C720, 0x1C740 }, { 0x1DF00, 0x1DF40, 0x1DF60 },
    { 0x20100, 0x20140, 0x20160 }, { 0x22B60, 0x22BA0, 0x22BC0 }, { 0x24580, 0x245C0, 0x245E0 },
    { 0x26E10, 0x26E50, 0x26E70 }, { 0x28D00, 0x28D40, 0x28D60 }, { 0x2B130, 0x2B170, 0x2B190 },
};

void func_i2_801033B8(unk_struct_60* arg0, u8* arg1);
void func_i2_8010300C(unk_struct_40* arg0, unk_struct_3F80* arg1, unk_800E5FF8* arg2, s32 arg3);
void func_i2_80102F70(unk_struct_40* arg0, unk_struct_3F80* arg1, unk_800E5FF8* arg2, s32 arg3);
void func_i2_80102CA4(unk_struct_19E0* arg0, s32 courseIndex);
void func_i2_80101F9C(void* arg0, s32 arg1);

extern u8 D_i2_8010D730[6][9];

extern unk_801247C0 D_801247C0;

// alignment issues with jumptable
extern const char D_i2_8010ADE0[];
extern const char D_i2_8010ADE8[];

// const char D_i2_8010ADE0[] = "F-ZERO X";
// const char D_i2_8010ADE8[] = "DAI&EAD!";

void func_i2_80103728(s32, size_t, void*, size_t);

void func_i2_801003B0(unk_struct_40* arg0) {
    func_i2_80103728(OS_READ, (uintptr_t) &D_801247C0.unk_33C0 - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_40));
}

void func_i2_801003EC(unk_struct_3F80* arg0) {
    func_i2_80103728(OS_READ, (uintptr_t) &D_801247C0.unk_3400 - (uintptr_t) &D_801247C0, arg0,
                     sizeof(unk_struct_3F80));
}

void func_i2_80100428(unk_struct_80* arg0, s32 arg1) {
    func_i2_80103728(OS_READ, (uintptr_t) &D_801247C0.unk_7380[arg1] - (uintptr_t) &D_801247C0, arg0,
                     sizeof(unk_struct_80));
}

void func_i2_8010046C(unk_struct_60* arg0) {
    func_i2_80103728(OS_READ, (uintptr_t) &D_801247C0.unk_7F80 - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_60));
}

void func_i2_801004A8(unk_struct_19E0* arg0) {
    s32 i;
    unk_struct_19E0* var_s2;
    unk_struct_19E0* var_s0;

    for (var_s0 = D_801247C0.unk_00, i = 0, var_s2 = arg0; i < 2 * sizeof(unk_struct_19E0);
         i += sizeof(unk_struct_19E0), var_s0++, var_s2++) {
        func_i2_80103728(OS_READ, (uintptr_t) var_s0 - (uintptr_t) &D_801247C0, var_s2, sizeof(unk_struct_19E0));
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
s32 func_i2_801005CC(s32);

s32 func_i2_80100810(s32 arg0, s32 arg1) {
    unk_struct_40* var = (unk_struct_40*) D_i2_8010D7F0;
    unk_struct_3F80* var2 = (unk_struct_3F80*) &D_i2_8010D7F0[sizeof(unk_struct_40)];
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

    func_i2_801003EC(var2);
    func_i2_80102F70(var, var2, &D_800E5FF8[var_t0], 1);
    func_i2_8010300C(var, var2, &D_800E5FF8[var_t0], 1);

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
        } else if (!func_i2_80100950(var_s0->unk_3F6A, arg0->unk_1D.unk_00)) {
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

s32 func_i2_80100C18(s32 courseIndex) {
    unk_struct_80* var = (unk_struct_80*) D_i2_8010D7F0;

    func_i2_80100428(&var[courseIndex], courseIndex);
    func_i2_80103310(&var[courseIndex], courseIndex);
    return 0;
}

s32 func_i2_80100C60(u8* courseIndex) {
    unk_struct_60* var = (unk_struct_60*) D_i2_8010D7F0;

    func_i2_8010046C(var);
    func_i2_801033B8(var, courseIndex);
    return 0;
}

s32 func_i2_8010356C(unk_struct_19E0*);
s32 func_i2_8010358C(unk_struct_19E0*);
s32 func_i2_801035B0(unk_struct_19E0*, s32);
s32 func_i2_801035E4(unk_struct_19E0*);
s32 func_i2_80103608(unk_struct_40*);
s32 func_i2_8010362C(unk_struct_3F80*);
s32 func_i2_80103650(unk_struct_80*);
s32 func_i2_80103674(unk_struct_60*);

void func_i2_80100C9C(unk_801247C0* arg0) {
    s32 i;
    s32 j;
    s32 checksum;
    unk_struct_80* var_s1;
    unk_struct_19E0* var_v1;

    checksum = func_i2_8010356C(arg0->unk_00);

    for (i = 0, var_v1 = arg0->unk_00; i < 2; i++, var_v1++) {
        var_v1->unk_00.checksum = checksum;
    }
    checksum = func_i2_8010358C(arg0->unk_00);

    for (i = 0, var_v1 = arg0->unk_00; i < 2; i++, var_v1++) {
        var_v1->unk_10.checksum = checksum;
    }

    for (j = 0; j < 24; j++) {
        checksum = func_i2_801035B0(arg0->unk_00, j);

        for (i = 0, var_v1 = arg0->unk_00; i < 2; i++, var_v1++) {
            var_v1->unk_20[j].checksum = checksum;
        }
    }
    checksum = func_i2_801035E4(arg0->unk_00);

    for (i = 0, var_v1 = arg0->unk_00; i < 2; i++, var_v1++) {
        var_v1->unk_19A0.checksum = checksum;
    }
    arg0->unk_33C0.checksum = func_i2_80103608(&arg0->unk_33C0);
    arg0->unk_3400.checksum = func_i2_8010362C(&arg0->unk_3400);

    for (i = 0, var_s1 = arg0->unk_7380; i < 24; i++, var_s1++) {
        var_s1->checksum = func_i2_80103650(var_s1);
    }
    arg0->unk_7F80.checksum = func_i2_80103674(&arg0->unk_7F80);
    func_i2_80103728(OS_WRITE, 0, arg0, sizeof(unk_801247C0));
}

void func_i2_80100DDC(unk_struct_19E0* arg0, s32 arg1, u16 checksum) {
    unk_struct_19E0* temp_a2 = &arg0[arg1];

    temp_a2->unk_00.checksum = checksum;
    func_i2_80103728(OS_WRITE, (uintptr_t) &D_801247C0.unk_00[arg1].unk_00 - (uintptr_t) &D_801247C0, temp_a2,
                     sizeof(unk_struct_10));
}

void func_i2_80100E64(unk_struct_19E0* arg0, s32 arg1, u16 checksum) {
    unk_struct_19E0* temp_v1 = &arg0[arg1];
    temp_v1->unk_10.checksum = checksum;

    func_i2_80103728(OS_WRITE, (uintptr_t) &D_801247C0.unk_00[arg1].unk_10 - (uintptr_t) &D_801247C0, &temp_v1->unk_10,
                     sizeof(unk_struct_10_2));
}

void func_i2_80100ED4(unk_struct_19E0* arg0, s32 arg1, s32 arg2, u16 checksum) {
    unk_struct_19E0* temp_v1 = &arg0[arg1];
    unk_struct_110* temp_v0 = &temp_v1->unk_20[arg2];

    temp_v0->checksum = checksum;
    func_i2_80103728(OS_WRITE, (uintptr_t) &D_801247C0.unk_00[arg1].unk_20[arg2] - (uintptr_t) &D_801247C0, temp_v0,
                     sizeof(unk_struct_110));
}

void func_i2_80100F7C(unk_struct_19E0* arg0, s32 arg1, u16 checksum) {
    unk_struct_19E0* temp_v1 = &arg0[arg1];

    temp_v1->unk_19A0.checksum = checksum;
    func_i2_80103728(OS_WRITE, (uintptr_t) &D_801247C0.unk_00[arg1].unk_19A0 - (uintptr_t) &D_801247C0,
                     &temp_v1->unk_19A0, sizeof(unk_struct_40_2));
}

void func_i2_80100FEC(unk_struct_40* arg0) {
    arg0->checksum = func_i2_80103608(arg0);
    func_i2_80103728(OS_WRITE, (uintptr_t) &D_801247C0.unk_33C0 - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_40));
}

void func_i2_80101034(unk_struct_3F80* arg0) {
    arg0->checksum = func_i2_8010362C(arg0);
    func_i2_80103728(OS_WRITE, (uintptr_t) &D_801247C0.unk_3400 - (uintptr_t) &D_801247C0, arg0,
                     sizeof(unk_struct_3F80));
}

void func_i2_8010107C(unk_struct_80* arg0, s32 arg1) {
    arg0->checksum = func_i2_80103650(arg0);
    func_i2_80103728(OS_WRITE, (uintptr_t) &D_801247C0.unk_7380[arg1] - (uintptr_t) &D_801247C0, arg0,
                     sizeof(unk_struct_80));
}

void func_i2_801010D0(unk_struct_60* arg0) {
    arg0->checksum = func_i2_80103674(arg0);
    func_i2_80103728(OS_WRITE, (uintptr_t) &D_801247C0.unk_7F80 - (uintptr_t) &D_801247C0, arg0, sizeof(unk_struct_60));
}

void func_i2_80102214(unk_struct_110* arg0, s32 courseIndex);

s32 func_i2_80101118(s32 arg0) {
    u16 checksum;
    s32 i;
    unk_struct_19E0* var = (unk_struct_19E0*) D_i2_8010D7F0;

    func_i2_80102214(&var[0].unk_20[arg0], arg0);
    var[1].unk_20[arg0] = var[0].unk_20[arg0];

    checksum = func_i2_801035B0(var, arg0);

    for (i = 0; i < 2; i++) {
        func_i2_80100ED4(var, i, arg0, checksum);
    }

    return 0;
}

extern s32 D_800CCFC0;
void func_i2_80102350(unk_struct_40_2* arg0);

s32 func_i2_801011FC(void) {
    u16 checksum;
    s32 i;
    unk_struct_19E0* var = (unk_struct_19E0*) D_i2_8010D7F0;

    if (D_800CCFC0 == 0) {
        return 3;
    }
    func_i2_80102350(&var[0].unk_19A0);

    var[1].unk_19A0 = var[0].unk_19A0;

    checksum = func_i2_801035E4(var);

    for (i = 0; i < 2; i++) {
        func_i2_80100F7C(var, i, checksum);
    }

    return 0;
}

void func_i2_8010259C(unk_struct_80*);

s32 func_i2_801012CC(s32 arg0) {
    s32 pad[2];
    unk_struct_80* var = (unk_struct_80*) D_i2_8010D7F0;

    func_i2_8010259C(&var[arg0]);
    func_i2_8010107C(&var[arg0], arg0);
    return 0;
}

s32 func_i2_80101310(s32 difficulty, s32 cupType, s32 character) {
    s32 i;
    s32 temp;
    unk_struct_60* var = (unk_struct_60*) D_i2_8010D7F0;

    func_i2_8010046C(var);
    func_i2_801033B8(var, NULL);

    temp = var->unk_10[difficulty][character / 3];
    temp |= (1 << ((character % 3) * 5)) << cupType;

    var->unk_10[difficulty][character / 3] = temp;

    // clang-format off
    for (i = 0; i < 14; i++) { \
        var->unk_02[i] = 0;
    }
    // clang-format on

    func_i2_801010D0(var);

    return 0;
}

void func_i2_80101FEC(unk_struct_10* arg0);

s32 func_i2_80101414(void) {
    u16 checksum;
    s32 i;
    unk_struct_19E0* var = (unk_struct_19E0*) D_i2_8010D7F0;

    func_i2_80101FEC(&var[0].unk_00);
    var[1].unk_00 = var[0].unk_00;

    checksum = func_i2_8010356C(var);

    for (i = 0; i < 2; i++) {
        func_i2_80100DDC(var, i, checksum);
    }

    return 0;
}

void func_i2_80101590(unk_struct_40* arg0, unk_80141C88* arg1);
void func_i2_80101E68(unk_struct_3F80* arg0, s32 arg1);
void func_i2_80101DE8(unk_struct_40* arg0, s32 arg1);

s32 func_i2_801014D4(unk_80141C88* arg0) {
    s32 pad;
    s32 var_v1;
    unk_struct_40* var = (unk_struct_40*) D_i2_8010D7F0;
    unk_struct_3F80* var2 = (unk_struct_3F80*) &D_i2_8010D7F0[sizeof(unk_struct_40)];

    func_i2_801003B0(var);
    var_v1 = 0;

    if (var->checksum != func_i2_80103608(var) * 1) {
        func_i2_80101DE8(var, 1);
        func_i2_80100FEC(var);
        func_i2_80101E68(var2, 1);
        func_i2_80101034(var2);
        var_v1 = 1;
    }

    if (arg0 != 0) {
        func_i2_80101590(var, arg0);
    }
    if ((var_v1 == 0) && (var->unk_08 == 0)) {
        var_v1 = 2;
    }
    return var_v1;
}

void func_i2_80101590(unk_struct_40* arg0, unk_80141C88* arg1) {
    s32 i;

    arg1->unk_00 = arg0->unk_08 % 32U;

    arg1->unk_04 = arg0->unk_08;
    arg1->unk_08 = arg0->unk_0C;
    arg1->unk_0C = arg0->unk_04;
    arg1->unk_10 = arg0->unk_02;
    arg1->unk_12 = arg0->unk_10;

    for (i = 0; i < 9; i++) {
        arg1->unk_14[i] = arg0->unk_17[i];
    }
    arg1->unk_1D = arg0->unk_20;
}

void func_i2_801023D8(unk_800E5FF8*);
void func_i2_801024F8(unk_800E5FF8*);

s32 func_i2_80101690(s32 arg0, unk_800E5FF8* arg1) {
    unk_struct_40* var = (unk_struct_40*) D_i2_8010D7F0;
    unk_struct_3F80* var2 = (unk_struct_3F80*) &D_i2_8010D7F0[sizeof(unk_struct_40)];

    func_i2_801023D8(arg1);
    func_i2_80100FEC(var);
    func_i2_801024F8(arg1);
    func_i2_80101034(var2);
    return 0;
}

void func_i2_801021B4(unk_struct_10_2* arg0);

s32 func_i2_801016DC(void) {
    u16 temp_s1;
    s32 i;
    unk_struct_19E0* var = (unk_struct_19E0*) D_i2_8010D7F0;

    func_i2_801021B4(&var[0].unk_10);
    var[1].unk_10 = var[0].unk_10;

    temp_s1 = func_i2_8010358C(var);

    for (i = 0; i < 2; i++) {
        func_i2_80100E64(var, i, temp_s1);
    }

    return 0;
}

void func_i2_80102600(unk_801247C0* arg0);
void func_i2_80101944(unk_801247C0* arg0, s32 arg1);

s32 func_i2_80101784(unk_801247C0* arg0, s32 arg1) {
    func_i2_80101944(arg0, arg1);
    func_i2_80100C9C(arg0);
    func_i2_80102600(arg0);
    return 0;
}

void func_i2_80101D18(unk_struct_110*, s32);

s32 func_i2_801017B8(s32 courseIndex) {
    u16 checksum;
    s32 i;
    unk_struct_19E0* var = (unk_struct_19E0*) D_i2_8010D7F0;

    func_i2_80101D18(&var[0].unk_20[courseIndex], 1);
    var[1].unk_20[courseIndex] = var[0].unk_20[courseIndex];

    checksum = func_i2_801035B0(var, courseIndex);

    for (i = 0; i < 2; i++) {
        func_i2_80100ED4(var, i, courseIndex, checksum);
    }

    func_i2_80102CA4(var, courseIndex);

    return 0;
}

s32 func_i2_801018A8(s32 courseIndex) {
    s32 i;
    unk_800E5FF8* var_v0;
    unk_struct_40* var = (unk_struct_40*) D_i2_8010D7F0;
    unk_struct_3F80* var2 = (unk_struct_3F80*) &D_i2_8010D7F0[sizeof(unk_struct_40)];

    for (i = 0, var_v0 = D_800E5FF8; i < 3; i++, var_v0++) {
        if (var_v0->unk_0000 == D_802A6B40[courseIndex].unk_00) {
            var_v0->unk_0000 = 0;
        }
    }
    func_i2_80101DE8(var, 1);
    func_i2_80100FEC(var);
    func_i2_80101E68(var2, 1);
    func_i2_80101034(var2);
    return 0;
}

void func_i2_80101B8C(unk_struct_10*, s32);
void func_i2_80101C04(unk_struct_40_2*, s32);
void func_i2_80101CCC(unk_struct_10_2*, s32);
void func_i2_80101E68(unk_struct_3F80*, s32);
void func_i2_80101EBC(unk_struct_80*, s32);
void func_i2_80102784(unk_struct_19E0*, s32);
void func_i2_80103108(unk_struct_19E0*, s32);

#ifdef NON_MATCHING
// compiler stack
void func_i2_80101944(unk_801247C0* arg0, s32 arg1) {
    s32 i;
    s32 j;
    u64* var_v0;
    unk_struct_19E0* var_s4;
    unk_struct_110* var_s1;
    unk_struct_80* var_s0;
    u8 spB7;
    unk_struct_40_2 sp74;

    if ((arg1 != 0) && (arg1 == 1)) {
        func_i2_801004A8(arg0->unk_00);
        func_i2_80102784(arg0->unk_00, 0);
        spB7 = arg0->unk_00[0].unk_00.unk_09;
        func_i2_80103108(arg0->unk_00, 0);
        sp74 = arg0->unk_00[0].unk_19A0;
    }

    for (i = 0, var_v0 = (u64*) arg0; i < (s32) (sizeof(unk_801247C0) / sizeof(u64)); i++) {
        var_v0[i] = 0;
    }

    for (i = 0, var_s4 = arg0->unk_00; i < 2; i++, var_s4++) {
        func_i2_80101B8C(&var_s4->unk_00, 0);
        func_i2_80101CCC(&var_s4->unk_10, 0);

        for (j = 0, var_s1 = var_s4->unk_20; j < 24; j++, var_s1++) {
            func_i2_80101D18(var_s1, 0);
        }

        func_i2_80101C04(&var_s4->unk_19A0, 0);
    }

    func_i2_80101DE8(&arg0->unk_33C0, 0);
    func_i2_80101E68(&arg0->unk_3400, 0);

    for (i = 0, var_s0 = arg0->unk_7380; i < 24; i++, var_s0++) {
        func_i2_80101EBC(var_s0, 0);
    }

    if ((arg1 != 0) && (arg1 == 1)) {
        arg0->unk_00[0].unk_00.unk_09 = arg0->unk_00[1].unk_00.unk_09 = spB7;
        arg0->unk_00[0].unk_19A0 = arg0->unk_00[1].unk_19A0 = sp74;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101944.s")
#endif

void func_i2_80101B8C(unk_struct_10* arg0, s32 arg1) {
    s32 i;

    if (arg1 != 0) {
        func_i2_80101F9C(arg0, sizeof(unk_struct_10));
    }

    for (i = 0; i < 8; i++) {
        arg0->unk_00[i] = D_i2_8010ADE0[i];
    }

    // clang-format off
    for (i = 0; i < 4; i++) { \
        arg0->unk_0A[i] = 0;
    }
    // clang-format on

    arg0->unk_08 = 1;
    arg0->unk_09 = 0;
}

void func_i2_80101C04(unk_struct_40_2* arg0, s32 arg1) {
    s32 i;
    s32 j;

    if (arg1 != 0) {
        func_i2_80101F9C(arg0, sizeof(unk_struct_40_2));
    }

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 9; j++) {
            arg0->unk_0A[i][j] = 0;
        }
    }
}

void func_i2_80101C78(u8* arg0) {

    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[4] = 0;
    arg0[5] = 0;
    arg0[6] = 0;
    arg0[7] = 0;
    arg0[8] = 0;
    arg0[9] = 0;
    arg0[10] = 0;
    arg0[11] = 0;
    arg0[12] = 0;
    arg0[13] = 0;
    arg0[14] = 0;
    arg0[15] = 0;
    arg0[16] = 0;
    arg0[17] = 0;
    arg0[18] = 0;
    arg0[19] = 0;
}

void func_i2_80101CCC(unk_struct_10_2* arg0, s32 arg1) {
    s32 i;

    if (arg1 != 0) {
        func_i2_80101F9C(arg0, sizeof(unk_struct_10_2));
    }

    for (i = 0; i < 1; i++) {
        arg0->unk_04[i] = MAX_TIMER;
    }
}

void func_i2_80101D18(unk_struct_110* arg0, s32 arg1) {
    s32 i;
    s32 j;

    if (arg1 != 0) {
        func_i2_80101F9C(arg0, 0x110);
    }

    for (i = 0; i < 5; i++) {
        arg0->unk_04[i] = MAX_TIMER;
        arg0->unk_18[i] = 0.5f;
        func_i2_80101C78(arg0->unk_50[i]);
        // clang-format off
        for (j = 0; j < 4; j++) { \
            arg0->unk_34[i][j] = 0;
        }
        // clang-format on
    }

    arg0->unk_2C = 0.0f;
    arg0->unk_30 = MAX_TIMER;

    func_i2_80101C78(arg0->unk_F0);
}

void func_i2_80101DE8(unk_struct_40* arg0, s32 arg1) {
    s32 i;

    if (arg1 != 0) {
        func_i2_80101F9C(arg0, sizeof(unk_struct_40));
    }

    arg0->unk_04 = 0;
    arg0->unk_02 = 0;
    arg0->unk_08 = 0;
    arg0->unk_0C = 0;
    arg0->unk_10 = 0;

    func_i2_80101C78(arg0->unk_20.unk_00);

    for (i = 0; i < 9; i++) {
        arg0->unk_17[i] = 0;
    }
}

void func_i2_80101E68(unk_struct_3F80* arg0, s32 arg1) {
    s32 i;

    if (arg1 != 0) {
        func_i2_80101F9C(arg0, sizeof(unk_struct_3F80));
    }

    // clang-format off
    for (i = 0; i < 3; i++) { \
        arg0->unk_04[i] = 0;
    }
    // clang-format on

    arg0->unk_10 = 0;
    arg0->unk_14 = 0;
}

void func_i2_80101EBC(unk_struct_80* arg0, s32 arg1) {
    s32 i;

    if (arg1 != 0) {
        func_i2_80101F9C(arg0, sizeof(unk_struct_80));
    }

    for (i = 0; i < 30; i++) {
        arg0->unk_08[i] = 0.5f;
    }
}

void func_i2_80101F24(unk_struct_60* arg0, s32 arg1) {
    s32 i;
    s32 j;

    if (arg1 != 0) {
        func_i2_80101F9C(arg0, sizeof(unk_struct_60));
    }

    for (i = 0; i < 4; i++) {
        // clang-format off
        for (j = 0; j < 10; j++) { \
            arg0->unk_10[i][j] = 0;
        }
        // clang-format on
    }
}

void func_i2_80101F9C(void* arg0, s32 arg1) {
    s32 i;
    u8* var_v1;

    // clang-format off
    for (i = 0, var_v1 = arg0; i < arg1; i++, var_v1++) { \
        *var_v1 = 0;
    }
    // clang-format on
}

extern s8 D_800CD3C8;
extern s16 D_800CE4D0;
extern s32 D_i2_80106F40;
extern s8 D_800E4174[];
extern s16 D_800CE4D4;

void func_i2_80101FEC(unk_struct_10* arg0) {
    u8 var_v1_2;
    u8 var;
    s32 i;

    for (i = 0; i < 8; i++) {
        arg0->unk_00[i] = D_i2_8010ADE0[i];
    }

    var = ((u8) D_800CE4D0 * 0x10);

    var_v1_2 = 0;

    if (D_800CE4D4 != 0) {
        var_v1_2 |= 1;
    }
    if (D_i2_80106F40 != 0) {
        var_v1_2 |= 2;
    }
    if (D_80111840 != 0) {
        var_v1_2 |= 4;
    }
    if (D_800CD3C8 != 0) {
        var_v1_2 |= 8;
    }

    arg0->unk_08 = var | var_v1_2;

    for (i = JACK_CUP; i <= JOKER_CUP; i++) {
        arg0->unk_0A[i] = D_800E4174[i];
    }

    arg0->unk_09 = 0;

    if (D_i2_80111848[0] != 0) {
        arg0->unk_09 |= 1;
    }
    if (D_i2_80111848[3] != 0) {
        arg0->unk_09 |= 2;
    }
    if (D_i2_80111848[4] != 0) {
        arg0->unk_09 |= 4;
    }
}

void func_i2_80102110(u8* arg0, u8* arg1) {

    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
    arg1[3] = arg0[3];
    arg1[4] = arg0[4];
    arg1[5] = arg0[5];
    arg1[6] = arg0[6];
    arg1[7] = arg0[7];
    arg1[8] = arg0[8];
    arg1[9] = arg0[9];
    arg1[10] = arg0[10];
    arg1[11] = arg0[11];
    arg1[12] = arg0[12];
    arg1[13] = arg0[13];
    arg1[14] = arg0[14];
    arg1[15] = arg0[15];
    arg1[16] = arg0[16];
    arg1[17] = arg0[17];
    arg1[18] = arg0[18];
    arg1[19] = arg0[19];
}

void func_i2_801021B4(unk_struct_10_2* arg0) {
    unk_800F8510* var_a1 = &D_802A6B40[54];
    s32 i;

    for (i = 0; i < 1; i++) {
        arg0->unk_04[i] = var_a1->timeRecord[i];
    }
    arg0->unk_02 = 0;

    // clang-format off
    for (i = 0; i < 8; i++) { \
        arg0->unk_08[i] = 0;
    }
    // clang-format on
}

void func_i2_80102214(unk_struct_110* arg0, s32 courseIndex) {
    unk_800F8510* temp_s5;
    s32 i;
    s32 j;

    temp_s5 = &D_802A6B40[courseIndex];

    for (i = 0; i < 5; i++) {
        arg0->unk_04[i] = temp_s5->timeRecord[i];
        arg0->unk_18[i] = temp_s5->unk_98[i];
        func_i2_80102110(temp_s5->unk_34[i], arg0->unk_50[i]);
        for (j = 0; j < 4; j++) {
            arg0->unk_34[i][j] = temp_s5->unk_AC[i][j];
        }
    }
    arg0->unk_2C = temp_s5->unk_C0;
    arg0->unk_30 = temp_s5->unk_D8;
    func_i2_80102110(temp_s5->unk_C4, arg0->unk_F0);
    arg0->unk_02 = 0;

    // clang-format off
    for (i = 0; i < 8; i++) { \
        arg0->unk_48[i] = 0;
    }
    // clang-format on
}

void func_i2_80102350(unk_struct_40_2* arg0) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 9; j++) {
            arg0->unk_0A[i][j] = D_i2_8010D730[i][j];
        }
    }
    arg0->unk_02 = 0;
    arg0->unk_04 = 0;
    arg0->unk_08 = 0;
}

void func_i2_801023D8(unk_800E5FF8* arg0) {
    s32 i;
    unk_struct_40* var = (unk_struct_40*) D_i2_8010D7F0;

    var->unk_04 = arg0->unk_3F64;
    var->unk_02 = arg0->unk_3F68;
    var->unk_10 = 0;
    var->unk_08 = arg0->unk_0000;

    var->unk_0C = arg0->unk_0004;
    var->unk_20.unk_00[0] = arg0->unk_3F6A[0];
    var->unk_20.unk_00[1] = arg0->unk_3F6A[1];
    var->unk_20.unk_00[2] = arg0->unk_3F6A[2];
    var->unk_20.unk_00[3] = arg0->unk_3F6A[3];
    var->unk_20.unk_00[4] = arg0->unk_3F6A[4];
    var->unk_20.unk_00[5] = arg0->unk_3F6A[5];
    var->unk_20.unk_00[6] = arg0->unk_3F6A[6];
    var->unk_20.unk_00[7] = arg0->unk_3F6A[7];
    var->unk_20.unk_00[8] = arg0->unk_3F6A[8];
    var->unk_20.unk_00[9] = arg0->unk_3F6A[9];
    var->unk_20.unk_00[10] = arg0->unk_3F6A[10];
    var->unk_20.unk_00[11] = arg0->unk_3F6A[11];
    var->unk_20.unk_00[12] = arg0->unk_3F6A[12];
    var->unk_20.unk_00[13] = arg0->unk_3F6A[13];
    var->unk_20.unk_00[14] = arg0->unk_3F6A[14];
    var->unk_20.unk_00[15] = arg0->unk_3F6A[15];
    var->unk_20.unk_00[16] = arg0->unk_3F6A[16];
    var->unk_20.unk_00[17] = arg0->unk_3F6A[17];
    var->unk_20.unk_00[18] = arg0->unk_3F6A[18];
    var->unk_20.unk_00[19] = arg0->unk_3F6A[19];

    for (i = 0; i < 9; i++) {
        var->unk_17[i] = 0;
    }

    for (i = 0; i < 5; i++) {
        var->unk_12[i] = 0;
    }
}

void func_i2_801024F8(unk_800E5FF8* arg0) {
    s32 i;
    u8* var_a1;
    s8* var_v1;
    unk_struct_3F80* var2 = (unk_struct_3F80*) &D_i2_8010D7F0[sizeof(unk_struct_40)];

    for (i = 0; i < 3; i++) {
        var2->unk_04[i] = arg0->unk_0008[i];
    }

    var2->unk_10 = arg0->unk_0014;
    var2->unk_14 = arg0->unk_0018;

    var_v1 = arg0->unk_001C;
    var_a1 = var2->unk_20;

    for (i = 0; i < 16200; i++) {
        *var_a1++ = *var_v1++;
    }

    var2->unk_02 = 0;
    var2->unk_18 = 0;
    var2->unk_1C = 0;
}

extern f32 D_800E40F0[30];

void func_i2_8010259C(unk_struct_80* arg0) {
    s32 i;

    for (i = 0; i < 30; i++) {
        arg0->unk_08[i] = D_800E40F0[i];
    }

    arg0->unk_02 = 0;
    arg0->unk_04 = 0;
}

void func_i2_80102B20(unk_struct_19E0* arg0);
void func_i2_80102A7C(u8* arg0, u8* arg1);

void func_i2_80102600(unk_801247C0* arg0) {
    s32 i;
    s32 j;
    unk_800F8510* var_s7;
    s32 pad[4];
    u8 sp60[20];
    unk_800E5FF8* var_s0;

    for (i = 0, var_s7 = D_802A6B40; i < ARRAY_COUNT(D_802A6B40); i++, var_s7++) {
        if (i < 24) {
            func_i2_80102CA4(arg0->unk_00, i);
        } else {
            func_i2_80101C78(sp60);

            for (j = 0; j < 5; j++) {
                var_s7->timeRecord[j] = MAX_TIMER;
                var_s7->unk_98[j] = 0.5f;
                func_i2_80102A7C(sp60, var_s7->unk_34[j]);
            }

            var_s7->unk_C0 = 0.0f;

            func_i2_80102A7C(sp60, var_s7->unk_C4);
            if (i == 54) {
                func_i2_80102B20(arg0->unk_00);
            }
        }
    }

    func_i2_80102784(arg0->unk_00, 1);

    for (i = 0; i < 30; i++) {
        D_i2_80111848[i] = 0;
    }

    func_i2_8010300C(&arg0->unk_33C0, &arg0->unk_3400, D_800E5FF8, 1);

    for (i = 0, var_s0 = D_800E5FF8; i < 3; i++, var_s0++) {
        var_s0->unk_0000 = 0;
    }
}

void func_i2_80102784(unk_struct_19E0* arg0, s32 arg1) {
    u16 checksum;
    s32 var_v1;
    s32 sp2C;
    s32 i;
    s32 var_v0;
    unk_struct_19E0* var_s1;
    unk_struct_10* var_v1_2;

    var_v1 = 0;

    for (i = 0, var_s1 = arg0; i < 2; i++) {
        if (var_s1->unk_00.checksum != func_i2_8010356C(var_s1) * 1) {
            var_v1++;
            sp2C = i;
        }
        var_s1++;
    }

    if (var_v1 == 2) {
        func_i2_80101B8C(&arg0[0].unk_00, 1);
        arg0[1].unk_00 = arg0[0].unk_00;

        checksum = func_i2_8010356C(arg0);

        for (i = 0; i < 2; i++) {
            func_i2_80100DDC(arg0, i, checksum);
        }
    } else if (var_v1 == 1) {
        var_v0 = (sp2C == 0) ? 1 : 0;

        (arg0 + sp2C)->unk_00 = (arg0 + var_v0)->unk_00;

        func_i2_80100DDC(arg0, sp2C, func_i2_8010356C(arg0));
    }

    if (arg1 == 0) {
        return;
    }

    var_v1_2 = &arg0->unk_00;

    D_800CE4D0 = ((u8) (var_v1_2->unk_08 >> 4) & 0xFF) & 0xF;
    if (var_v1_2->unk_08 & 1) {
        D_800CE4D4 = 1;
    } else {
        D_800CE4D4 = 0;
    }
    if (var_v1_2->unk_08 & 2) {
        D_i2_80106F40 = 1;
    } else {
        D_i2_80106F40 = 0;
    }
    if (var_v1_2->unk_08 & 4) {
        D_80111840 = 1;
    } else {
        D_80111840 = 0;
    }
    if (var_v1_2->unk_08 & 8) {
        D_800CD3C8 = 1;
    } else {
        D_800CD3C8 = 0;
    }

    for (i = JACK_CUP; i <= JOKER_CUP; i++) {
        D_800E4174[i] = var_v1_2->unk_0A[i];
    }

    func_8007E2B4();

    // clang-format off
    for (i = 0; i < 30; i++) { \
        D_i2_80111848[i] = 0;
    }
    // clang-format on

    if (var_v1_2->unk_09 & 1) {
        D_i2_80111848[0] = 1;
    }
    if (var_v1_2->unk_09 & 2) {
        D_i2_80111848[3] = 1;
    }
    if (var_v1_2->unk_09 & 4) {
        D_i2_80111848[4] = 1;
    }
}

void func_i2_80102A7C(u8* arg0, u8* arg1) {

    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
    arg1[3] = arg0[3];
    arg1[4] = arg0[4];
    arg1[5] = arg0[5];
    arg1[6] = arg0[6];
    arg1[7] = arg0[7];
    arg1[8] = arg0[8];
    arg1[9] = arg0[9];
    arg1[10] = arg0[10];
    arg1[11] = arg0[11];
    arg1[12] = arg0[12];
    arg1[13] = arg0[13];
    arg1[14] = arg0[14];
    arg1[15] = arg0[15];
    arg1[16] = arg0[16];
    arg1[17] = arg0[17];
    arg1[18] = arg0[18];
    arg1[19] = arg0[19];
}

void func_i2_80102B20(unk_struct_19E0* arg0) {
    u16 checksum;
    s32 var_s2;
    s32 var_v0;
    s32 sp30;
    unk_800F8510* var_v0_2;
    unk_struct_10_2* var_v1;
    unk_struct_19E0* var_s1;
    s32 i;

    var_s2 = 0;

    for (i = 0, var_s1 = arg0; i < 2; i++) {
        if (var_s1->unk_10.checksum != func_i2_8010358C(var_s1) * 1) {
            var_s2++;
            sp30 = i;
        }
        var_s1++;
    }

    if (var_s2 == 2) {
        func_i2_80101CCC(&arg0[0].unk_10, 1);
        arg0[1].unk_10 = arg0[0].unk_10;

        checksum = func_i2_8010358C(arg0);

        for (i = 0; i < 2; i++) {
            func_i2_80100E64(arg0, i, checksum);
        }
    } else if (var_s2 == 1) {
        var_v0 = (sp30 == 0) ? 1 : 0;

        (arg0 + sp30)->unk_10 = (arg0 + var_v0)->unk_10;

        func_i2_80100E64(arg0, sp30, func_i2_8010358C(arg0));
    }
    var_v0_2 = &D_802A6B40[54];
    var_v1 = &arg0->unk_10;
    for (i = 0; i < 1; i++) {
        var_v0_2->timeRecord[i] = var_v1->unk_04[i];
    }
}

void func_i2_80102CA4(unk_struct_19E0* arg0, s32 courseIndex) {
    u16 checksum;
    s32 j;
    s32 i;
    s32 var_s4;
    unk_800F8510* var_s3;
    unk_struct_19E0* var_s0;
    s32 var_v0;
    unk_struct_110* sp40;

    j = 0;

    for (i = 0, var_s0 = arg0; i < 2; i++) {
        if (var_s0->unk_20[courseIndex].checksum != func_i2_801035B0(var_s0, courseIndex)) {
            j++;
            var_s4 = i;
        }
        var_s0++;
    }

    if (j == 2) {

        func_i2_80101D18(&arg0[0].unk_20[courseIndex], 1);
        arg0[1].unk_20[courseIndex] = arg0[0].unk_20[courseIndex];

        checksum = func_i2_801035B0(arg0, courseIndex);

        for (i = 0; i < 2; i++) {
            func_i2_80100ED4(arg0, i, courseIndex, checksum);
        }

    } else if (j == 1) {
        var_v0 = (var_s4 == 0) ? 1 : 0;

        (arg0 + var_s4)->unk_20[courseIndex] = (arg0 + var_v0)->unk_20[courseIndex];

        func_i2_80100ED4(arg0, var_s4, courseIndex, func_i2_801035B0(arg0, courseIndex));
    }

    sp40 = &arg0->unk_20[courseIndex];
    var_s3 = &D_802A6B40[courseIndex];

    for (i = 0; i < 5; i++) {
        var_s3->timeRecord[i] = sp40->unk_04[i];
        var_s3->unk_98[i] = sp40->unk_18[i];
        func_i2_80102A7C(sp40->unk_50[i], var_s3->unk_34[i]);
        for (j = 0; j < 4; j++) {
            var_s3->unk_AC[i][j] = sp40->unk_34[i][j];
        }
    }
    var_s3->unk_C0 = sp40->unk_2C;
    var_s3->unk_D8 = sp40->unk_30;
    func_i2_80102A7C(sp40->unk_F0, var_s3->unk_C4);
}

void func_i2_80102F70(unk_struct_40* arg0, unk_struct_3F80* arg1, unk_800E5FF8* arg2, s32 arg3) {

    if (arg3 != 0) {
        if (arg0->checksum != func_i2_80103608(arg0) * 1) {
            func_i2_80101DE8(arg0, 1);
            func_i2_80100FEC(arg0);
            func_i2_80101E68(arg1, 1);
            func_i2_80101034(arg1);
        }
    }

    arg2->unk_3F64 = arg0->unk_04;
    arg2->unk_3F68 = arg0->unk_02;
    arg2->unk_0000 = arg0->unk_08;
    arg2->unk_0004 = arg0->unk_0C;
    func_i2_80102A7C(arg0->unk_20.unk_00, arg2->unk_3F6A);
}

void func_i2_8010300C(unk_struct_40* arg0, unk_struct_3F80* arg1, unk_800E5FF8* arg2, s32 arg3) {
    s32 i;
    u8* var_v0;
    s8* var_v1;
    unk_struct_40* var = (unk_struct_40*) D_i2_8010D7F0;
    unk_struct_3F80* var2 = (unk_struct_3F80*) &D_i2_8010D7F0[sizeof(unk_struct_40)];

    if (arg3 != 0) {
        if (arg1->checksum != func_i2_8010362C(arg1) * 1) {
            func_i2_80101DE8(var, 1);
            func_i2_80100FEC(var);
            func_i2_80101E68(var2, 1);
            func_i2_80101034(var2);
            arg2->unk_0000 = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        arg2->unk_0008[i] = arg1->unk_04[i];
    }

    arg2->unk_0014 = arg1->unk_10;
    arg2->unk_0018 = arg1->unk_14;

    var_v0 = arg1->unk_20;
    var_v1 = arg2->unk_001C;

    for (i = 0; i < 16200; i++) {
        *var_v1++ = *var_v0++;
    }
}

void func_i2_80103108(unk_struct_19E0* arg0, s32 arg1) {
    unk_struct_40_2* var_a3;
    s32 i;
    s32 j;
    s32 sp30;
    u16 checksum;
    s32 var_s2;
    s32 var_v0;
    unk_struct_19E0* var_s1;

    var_s2 = 0;

    for (i = 0, var_s1 = arg0; i < 2; i++) {
        if (var_s1->unk_19A0.checksum != func_i2_801035E4(var_s1) * 1) {
            var_s2++;
            sp30 = i;
        }
        var_s1++;
    }

    if (var_s2 == 2) {
        func_i2_80101C04(&arg0[0].unk_19A0, 1);
        arg0[1].unk_19A0 = arg0[0].unk_19A0;

        checksum = func_i2_801035E4(arg0);
        for (i = 0; i < 2; i++) {
            func_i2_80100F7C(arg0, i, checksum);
        }
    } else if (var_s2 == 1) {
        var_v0 = (sp30 == 0) ? 1 : 0;

        (arg0 + sp30)->unk_19A0 = (arg0 + var_v0)->unk_19A0;

        func_i2_80100F7C(arg0, sp30, func_i2_801035E4(arg0));
    }

    if (arg1 == 0) {
        return;
    }

    var_a3 = &arg0[0].unk_19A0;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 9; j++) {
            D_i2_8010D730[i][j] = var_a3->unk_0A[i][j];
        }
    }
}

extern f32 D_800E40F0[];

void func_i2_80103310(unk_struct_80* arg0, s32 arg1) {
    s32 i;

    if (arg0->checksum != func_i2_80103650(arg0) * 1) {
        func_i2_80101EBC(arg0, 1);
        func_i2_8010107C(arg0, arg1);
    }

    for (i = 0; i < 30; i++) {
        D_800E40F0[i] = arg0->unk_08[i];
    }
}

void func_i2_801033B8(unk_struct_60* arg0, u8* arg1) {
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    u8 temp_v1;
    s8* var_a0;
    s32 temp;

    if (arg0->checksum != func_i2_80103674(arg0) * 1) {
        func_i2_80101F24(arg0, 1);
        func_i2_801010D0(arg0);
    }

    if (arg1 == NULL) {
        return;
    }

    var_a0 = arg1;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 10; j++) {
            temp = arg0->unk_10[i][j];
            for (k = 0; k < 3; k++) {
                temp_v1 = (u32) (temp >> (k * 5)) % 32;
                for (m = 0; m < 5; m++) {
                    if (temp_v1 & 1) {
                        *var_a0 = 1;
                    } else {
                        *var_a0 = 0;
                    }
                    var_a0++;
                    temp_v1 >>= 1;
                }
            }
        }
    }
}

// Basic checksum calculation
u16 func_i2_801034F8(void* data, s32 size) {
    u8* dataPtr = data;
    u16 checksum = 0;
    s32 i;

    for (i = 0; i < size; i++) {
        checksum += *dataPtr++;
    }

    return checksum;
}

s32 func_i2_8010356C(unk_struct_19E0* arg0) {
    return func_i2_801034F8(&arg0->unk_00.unk_00, sizeof(unk_struct_10) - sizeof(u16));
}

s32 func_i2_8010358C(unk_struct_19E0* arg0) {
    return func_i2_801034F8(&arg0->unk_10.unk_02, sizeof(unk_struct_10_2) - sizeof(u16));
}

s32 func_i2_801035B0(unk_struct_19E0* arg0, s32 arg1) {
    return func_i2_801034F8(&arg0->unk_20[arg1].unk_02, sizeof(unk_struct_110) - sizeof(u16));
}

s32 func_i2_801035E4(unk_struct_19E0* arg0) {
    return func_i2_801034F8(&arg0->unk_19A0.unk_02, sizeof(unk_struct_40_2) - sizeof(u16));
}

s32 func_i2_80103608(unk_struct_40* arg0) {
    return func_i2_801034F8(&arg0->unk_02, sizeof(unk_struct_40) - sizeof(u16));
}

s32 func_i2_8010362C(unk_struct_3F80* arg0) {
    return func_i2_801034F8(&arg0->unk_02, sizeof(unk_struct_3F80) - sizeof(u16));
}

s32 func_i2_80103650(unk_struct_80* arg0) {
    return func_i2_801034F8(&arg0->unk_02, sizeof(unk_struct_80) - sizeof(u16));
}

s32 func_i2_80103674(unk_struct_60* arg0) {
    return func_i2_801034F8(&arg0->unk_02, sizeof(unk_struct_60) - sizeof(u16));
}

OSPiHandle* func_i2_80103698(void) {
    if (D_i2_801117C8.baseAddress == PHYS_TO_K1(PI_DOM2_ADDR2)) {
        return &D_i2_801117C8;
    }
    D_i2_801117C8.type = DEVICE_TYPE_SRAM;
    D_i2_801117C8.baseAddress = PHYS_TO_K1(PI_DOM2_ADDR2);
    D_i2_801117C8.latency = 5;
    D_i2_801117C8.pulse = 12;
    D_i2_801117C8.pageSize = 13;
    D_i2_801117C8.relDuration = 2;
    D_i2_801117C8.domain = PI_DOMAIN2;
    D_i2_801117C8.speed = 0;
    bzero(&D_i2_801117C8.transferInfo, sizeof(__OSTranxInfo));
    osEPiLinkHandle(&D_i2_801117C8);
    return &D_i2_801117C8;
}

extern OSMesgQueue D_800DCA68;

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

void func_i2_8010382C(unk_struct_40* arg0, s32 arg1);

s32 func_i2_801037CC(unk_80141C88* arg0, s32 arg1) {
    unk_struct_40* var = (unk_struct_40*) D_i2_8010D7F0;

    if ((arg1 < 0) || (arg1 >= 24)) {
        return 2;
    }
    func_i2_8010382C(var, arg1);
    if (arg0 != NULL) {
        func_i2_80101590(var, arg0);
    }
    return 0;
}

void func_i2_8010382C(unk_struct_40* arg0, s32 arg1) {
    func_80073ED0(SEGMENT_ROM_START(segment_27F200) + D_i2_80106DF0[arg1][0], arg0, sizeof(unk_struct_40));
}

void func_i2_80103930(unk_struct_3F80* arg0, s32 arg1);

s32 func_i2_8010387C(s32 arg0) {
    s32 sp64;
    unk_80141C88 sp24;
    unk_struct_40* var = (unk_struct_40*) D_i2_8010D7F0;
    unk_struct_3F80* var2 = (unk_struct_3F80*) &D_i2_8010D7F0[sizeof(unk_struct_40)];

    func_i2_801037CC(&sp24, arg0);
    if (func_i2_80100B38(&sp24) != 0) {
        return 0;
    }

    sp64 = func_i2_801005CC(arg0);
    func_i2_80103930(var2, arg0);
    func_i2_80102F70(var, var2, &D_800E5FF8[sp64], 0);
    func_i2_8010300C(var, var2, &D_800E5FF8[sp64], 0);

    return 0;
}

void func_i2_80103930(unk_struct_3F80* arg0, s32 arg1) {
    uintptr_t* offsets = D_i2_80106DF0[arg1];
    RomOffset romOffset = SEGMENT_ROM_START(segment_27F200);

    func_80073ED0(romOffset + offsets[1], arg0, 0x20);
    func_80073ED0(romOffset + offsets[2], arg0->unk_20, ALIGN_2(arg0->unk_14 + 1));
}

void func_i2_801039BC(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            ((unk_struct_19E0*) D_i2_8010D7F0)[i].unk_00.unk_00[j] = D_i2_8010ADE8[j];
            func_i2_80100DDC(((unk_struct_19E0*) D_i2_8010D7F0), i, 0x1234);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/D_i2_8010ADE0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/D_i2_8010ADE8.s")
