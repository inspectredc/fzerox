#include "global.h"
#include "fzx_game.h"
#include "ovl_i2.h"
#include "assets/segment_16C8A0.h"

s16 D_8010D770;
u16 D_i2_8010D772;
s16 D_i2_8010D774;
unk_8010D778 D_i2_8010D778;
s16 D_i2_8010D7A8;
s16 D_i2_8010D7AA;
u16* D_i2_8010D7AC;
u16 D_i2_8010D7B0[32];

s16 D_i2_80106DA0 = 1;
s32 D_i2_80106DA4 = 0;
s16 D_i2_80106DA8[] = { -75, -74, -73, -1, 1, 73, 74, 75 };

UNUSED Gfx D_i2_80106DB8[] = {
    gsSPEndDisplayList(),
};

f32 D_i2_80106DC0 = 3.25f;

s32 D_i2_80106DC4[] = { 7, 3, 3, 1, 1, 0, 0, 0 };

void func_i2_800FC730(void) {
    unk_8010D778* var = &D_i2_8010D778;

    var->unk_04 = 0;
    var->unk_00 = 0;
    var->unk_08 = 0;
    var->unk_0C = 0;
    var->unk_0E = 0;
    var->unk_12 = 0;
    var->unk_14 = NULL;
    var->unk_18 = NULL;
    D_i2_8010D7A8 = 0;
    D_i2_8010D7AA = 0;
    D_8010D770 = 0;
    D_i2_8010D774 = 0;
}

s32 func_i2_800FCB84(s32, s32);
s32 func_i2_800FCD4C(s32, s32);
extern s32 gNumPlayers;
extern s16 D_800CD044;
extern s32 gGameMode;

void func_i2_800FC77C(void) {
    D_i2_80106DA4 = 2;

    if (D_800CD044 == 31) {
        func_i2_800FCB84(0, 10);
        return;
    }

    switch (gGameMode) {
        case GAMEMODE_FLX_TITLE:
            func_i2_800FCB84(0, 7);
            break;
        case GAMEMODE_GP_END_CS:
            func_i2_800FCD38(5, 120);
            func_i2_800FCB84(0, 5);
            break;
        case GAMEMODE_COURSE_EDIT:
            func_i2_800FCB84(0, 10);
            break;
        case GAMEMODE_FLX_COURSE_SELECT:
            func_i2_800FCD38(5, 40);
            func_i2_800FCB84(0, 5);
            break;
        case GAMEMODE_FLX_MACHINE_SELECT:
            if (gNumPlayers == 1) {
                func_i2_800FCB84(0, 10);
                break;
            }
            func_i2_800FCB84(0, 5);
            break;
        case GAMEMODE_FLX_MAIN_MENU:
            if (D_800CD044 == 21) {
                func_i2_800FCB84(0, 10);
                break;
            }
            func_i2_800FCB84(0, 1);
            break;
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
        case GAMEMODE_FLX_OPTIONS_MENU:
            if (D_800CD044 == 21) {
                func_i2_800FCB84(0, 10);
                break;
            }
            func_i2_800FCD4C(0, 1);
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            func_i2_800FCB84(0, 5);
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_FLX_GP_RACE_NEXT_MACHINE_SETTINGS:
            func_i2_800FCB84(0, 6);
            break;
        case GAMEMODE_RECORDS:
            if (D_800CD044 != 21) {
                func_i2_800FCD4C(0, 1);
                break;
            }
            func_i2_800FCB84(0, 10);
            break;
        default:
            func_i2_800FCD4C(0, 1);
            break;
    }
}

extern s32 gQueuedGameMode;

void func_i2_800FC9BC(void) {
    D_i2_80106DA4 = 1;

    if (D_800CD044 == 33) {
        func_i2_800FCB84(1, 10);
        return;
    }

    switch (gQueuedGameMode) {
        case GAMEMODE_FLX_TITLE:
            func_i2_800FCB84(1, 1);
            break;
        case GAMEMODE_GP_END_CS:
            func_i2_800FCB84(1, 5);
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
        case GAMEMODE_FLX_MACHINE_SELECT:
            func_i2_800FCB84(1, 5);
            break;
        case GAMEMODE_COURSE_EDIT:
            func_i2_800FCB84(1, 10);
            break;
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
        case GAMEMODE_FLX_OPTIONS_MENU:
            if (D_800CD044 == 23) {
                func_i2_800FCD38(9, 2);
                func_i2_800FCB84(1, 9);
                break;
            }
            func_i2_800FCD4C(1, 1);
            break;
        case GAMEMODE_FLX_MAIN_MENU:
            if (D_800CD044 == 23) {
                func_i2_800FCD38(9, 3);
                func_i2_800FCB84(1, 9);
                break;
            }
            func_i2_800FCB84(1, 7);
            break;
        case GAMEMODE_RECORDS:
            if (D_800CD044 != 23) {
                func_i2_800FCD4C(1, 1);
                break;
            }
            func_i2_800FCB84(1, 9);
            break;
        case GAMEMODE_FLX_UNSKIPPABLE_CREDITS:
            func_i2_800FCD38(5, 60);
            func_i2_800FCB84(1, 5);
            break;
        default:
            func_i2_800FCD4C(1, 1);
            break;
    }
}

extern u32 gGameFrameCount;

s32 func_i2_800FCB84(s32 arg0, s32 arg1) {
    u32 var_a1;
    u32 var_a2;
    unk_8010D778* var = &D_i2_8010D778;

    var->unk_04 = arg1;
    var->unk_10 = arg0;
    if (var->unk_04 != D_i2_8010D7AA) {
        var->unk_0E = 0;
    } else {
        var->unk_0E = D_i2_8010D7A8;
        D_i2_8010D7AA = 0;
        D_i2_8010D7A8 = 0;
    }
    D_i2_8010D7AC = NULL;

    switch (arg1) {
        case 1:
            var_a1 = 0;
            var_a2 = 0x818;
            break;
        case 2:
            var_a1 = 0x20600;
            var_a2 = 0x80;
            break;
        case 3:
            var_a1 = 0x20600;
            var_a2 = 0x700;
            var->unk_0E = gGameFrameCount & 1;
            break;
        case 4:
            var_a1 = 0x20600;
            var_a2 = 0x500;
            break;
        case 5:
        case 6:
            var_a1 = 0;
            var_a2 = 0;
            break;
        case 9:
            var_a1 = 0x20600;
            var_a2 = 0;
            break;
        case 7:
            var_a1 = 0x20600;
            var_a2 = 0x380;
            break;
        case 8:
            if (arg0 != 0) {
                if (D_i2_8010D774 != 0) {
                    var->unk_04 = 6;
                    var_a1 = 0;
                    var_a2 = 0;
                    break;
                }
            }
            var_a1 = 0x20600;
            var_a2 = 0xC0;
            break;
        default:
            var_a1 = 0;
            var_a2 = 0;
            break;
    }

    if (((var->unk_14 = func_800768F4(2, var_a1)) == NULL) || ((var->unk_18 = func_800768F4(2, var_a2)) == NULL)) {
        var->unk_04 = 5;
        return 1;
    }
    if (var->unk_04 == 8) {
        D_i2_8010D7AC = D_i2_8010D7B0;
    }
    return 0;
}

void func_i2_800FCD38(s32 arg0, s32 arg1) {
    D_i2_8010D7AA = arg0;
    D_i2_8010D7A8 = arg1;
}

const s32 D_i2_8010AB60[] = { 1, 2, 3, 4, 5, 6, 7 };

s32 func_i2_800FCD4C(s32 arg0, s32 arg1) {
    s32 temp;
    u32 temp2;
    s32 var_v0;

    if (arg0 == 0) {
        temp = (Math_Rand1() % 8);
        if (arg1 != 0) {
            if (temp < 2) {
                temp2 = Math_Rand1();
                var_v0 = func_i2_800FCB84(arg0, D_i2_8010AB60[temp2 % 7]);
            } else {
                var_v0 = func_i2_800FCB84(arg0, 10);
            }
        } else {
            temp2 = Math_Rand1();
            var_v0 = func_i2_800FCB84(arg0, D_i2_8010AB60[temp2 % 7]);
        }
    } else {
        temp2 = Math_Rand1();
        var_v0 = func_i2_800FCB84(arg0, D_i2_8010AB60[temp2 % 7]);
    }
    return var_v0;
}

void func_i2_800FCF48(unk_8010D778*);
void func_i2_800FD58C(unk_8010D778*);
void func_i2_800FDC30(unk_8010D778*);
void func_i2_800FE4E4(unk_8010D778*);
void func_i2_800FF284(unk_8010D778*);
void func_i2_800FF7D4(unk_8010D778*);
void func_i2_800FFA34(unk_8010D778*);
void func_i2_800FFCAC(unk_8010D778*);
void func_i2_80100248(unk_8010D778*);

s32 func_i2_800FCE3C(void) {
    unk_8010D778* var = &D_i2_8010D778;

    if (var->unk_04 != 0) {
        func_i2_800FCF48(var);
    }

    switch (var->unk_00) {
        case 0:
            break;
        case 1:
            func_i2_800FD58C(var);
            break;
        case 2:
            func_i2_800FDC30(var);
            break;
        case 3:
            func_i2_800FE4E4(var);
            break;
        case 4:
            func_i2_800FF284(var);
            break;
        case 5:
        case 6:
            func_i2_800FF7D4(var);
            break;
        case 9:
            func_i2_800FFA34(var);
            break;
        case 7:
            func_i2_800FFCAC(var);
            break;
        case 8:
            func_i2_80100248(var);
            break;
        case 10:
        default:
            break;
    }

    if (D_i2_80106DA4 != 0 && var->unk_12 & 8) {
        D_i2_80106DA4 = 0;
    }

    return var->unk_12 & 8;
}

void func_i2_800FD4AC(unk_8010D778*);
void func_i2_800FDBDC(unk_8010D778*);
void func_i2_800FE13C(unk_8010D778*);
void func_i2_800FEED8(unk_8010D778*);
void func_i2_800FF7A8(unk_8010D778*, s32, s32);
void func_i2_800FF9C8(unk_8010D778*);
void func_i2_800FFC68(unk_8010D778*);
void func_i2_80100220(unk_8010D778*);

void func_i2_800FCF48(unk_8010D778* arg0) {
    s16 temp_t2;
    s32 temp_at;
    s32 temp_t6;
    u32 temp_t9;

    arg0->unk_00 = arg0->unk_04;
    arg0->unk_04 = 0;
    arg0->unk_0C = 0;
    arg0->unk_12 = 2;

    switch (arg0->unk_00 - 1) {
        case 9:

            arg0->unk_12 &= ~0x2;
            arg0->unk_12 |= 8;
            break;
        case 0:
            if (arg0->unk_10 != 0) {
                arg0->unk_08 = 3;
            } else {
                arg0->unk_08 = 1;
            }
            func_i2_800FD4AC(arg0);
            break;
        case 1:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_800FDBDC(arg0);
            break;
        case 2:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_800FE13C(arg0);
            break;
        case 3:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_800FEED8(arg0);
            break;
        case 4:
        case 5:
            if (arg0->unk_10 != 0) {
                arg0->unk_08 = 3;
                func_i2_800FF7A8(arg0, 255, 20);
            } else {
                arg0->unk_08 = 1;
                func_i2_800FF7A8(arg0, 0, 20);
            }
            break;
        case 8:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_800FF9C8(arg0);
            break;
        case 6:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_800FFC68(arg0);
            break;
        case 7:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_80100220(arg0);
            break;
    }

    if (arg0->unk_10 == 0) {
        if (arg0->unk_12 & 4) {
            D_i2_8010D774 = 1;
            return;
        }
        D_i2_8010D774 = 0;
    }
}

extern Gfx D_8014780[];
Gfx* func_i2_800FD9C8(Gfx*, unk_8010D778*);
Gfx* func_i2_800FDE84(Gfx*, unk_8010D778*);
Gfx* func_i2_800FEB2C(Gfx*, unk_8010D778*);
Gfx* func_i2_800FF91C(Gfx*, unk_8010D778*);
Gfx* func_i2_800FFBF4(Gfx*, unk_8010D778*);
Gfx* func_i2_800FFEEC(Gfx*, unk_8010D778*);
Gfx* func_i2_8010034C(Gfx*, unk_8010D778*);

Gfx* func_i2_800FD184(Gfx* gfx) {
    unk_8010D778* var = &D_i2_8010D778;

    if (!(var->unk_12 & 2)) {
        return gfx;
    }

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    gfx = func_8006A00C(gfx, 0);

    if (var->unk_12 & 4) {
        gSPDisplayList(gfx++, D_8014780);
        gDPFillRectangle(gfx++, 12, 8, 307, 231);
    }
    switch (var->unk_00) {
        case 1:
            gfx = func_i2_800FD9C8(gfx, var);
            break;
        case 2:
            gfx = func_i2_800FDE84(gfx, var);
            break;
        case 3:
            gfx = func_i2_800FEB2C(gfx, var);
            break;
        case 4:
            gfx = func_i2_800FEB2C(gfx, var);
            break;
        case 5:
        case 6:
            gfx = func_i2_800FF91C(gfx, var);
            break;
        case 9:
            gfx = func_i2_800FFBF4(gfx, var);
            break;
        case 7:
            gfx = func_i2_800FFEEC(gfx, var);
            break;
        case 8:
            gfx = func_i2_8010034C(gfx, var);
            break;
        case 10:
            break;
    }
    if (var->unk_12 & 8) {
        var->unk_00 = 0;
        var->unk_08 = 0;
        var->unk_12 &= ~2;
        func_80076848();
    }
    return gfx;
}

extern s16 D_800CCFE4;
extern s32 D_800DCD00;
extern s32 D_800DCD08;
extern FrameBuffer* D_800DCCD0[];

void func_i2_800FD344(void) {
    s32 pad;
    s32 var_a0;
    s32 var_a2;
    s32 var_v0;
    u16* var_v0_2;
    u16* var_v1;
    unk_8010D778* var = &D_i2_8010D778;

    if (!(var->unk_12 & 1)) {
        return;
    }

    var->unk_12 &= ~1;
    var_v1 = var->unk_14;
    if (D_800CCFE4 == 3) {
        var_v0 = D_800DCD08;
    } else {
        var_v0 = D_800DCD00;
    }

    osInvalDCache(D_800DCCD0[var_v0], 0x25800);

    for (var_a2 = 0; var_a2 < 224; var_a2++) {
        var_v0_2 = &D_800DCCD0[var_v0]->array[var_a2 + 8][12];

        for (var_a0 = 0; var_a0 < 296; var_a0++, var_v1++, var_v0_2++) {
            *var_v1 = *var_v0_2;
        }
    }

    if (var->unk_12 & 0x10) {
        func_8007A59C(var->unk_14, 0x20600);
    }
    if (var->unk_12 & 0x20) {
        func_8007ECCC(var->unk_14, 0x20600);
    }
    if (var->unk_12 & 0x40) {
        func_8007EFBC(var->unk_14, D_i2_8010D7AC, 0x20600);
    }
}

void func_i2_800FD978(unk_8010D778* arg0, s32 arg1, s8 arg2);

void func_i2_800FD4AC(unk_8010D778* arg0) {
    s32 i;
    u8* ptr = arg0->unk_18;
    s32 temp;
    s32 temp2;

    for (i = 0; i < 0x818; i++) {
        *ptr++ = 0;
    }

    for (i = 0; i < 5; i++) {
        temp = Math_Rand1() % 74;
        temp2 = Math_Rand1() % 56;
        func_i2_800FD978(arg0, (temp2 * 74) + temp, 1);
    }
}

bool func_i2_800FD638(unk_8010D778* arg0);

void func_i2_800FD58C(unk_8010D778* arg0) {

    switch (arg0->unk_08) {
        case 1:
            if (func_i2_800FD638(arg0) != 0) {
                arg0->unk_08 = 2;
                arg0->unk_0C = 0;
            }
            break;
        case 2:
            arg0->unk_0C++;
            if (arg0->unk_0C >= 3) {
                arg0->unk_08 = 4;
            }
            break;
        case 3:
            if (func_i2_800FD638(arg0) != 0) {
                arg0->unk_08 = 4;
            }
            break;
        case 4:
            arg0->unk_12 |= 8;
            break;
        case 0:
        default:
            break;
    }
}

s8 func_i2_800FD938(unk_8010D778* arg0, s32 arg1);
s32 func_i2_800FD840(unk_8010D778* arg0, s32 arg1, s32* arg2);

bool func_i2_800FD638(unk_8010D778* arg0) {
    s32 temp_v0;
    bool var_a0;
    s32 var_a1;
    s8* var_v0;
    u32 var_v1;
    s32 i;
    s32 sp40[14];

    for (i = 0; i < 0x1030; i++) {
        if (func_i2_800FD938(arg0, i) == 1) {
            temp_v0 = func_i2_800FD840(arg0, i, sp40);
            if (temp_v0 == 0) {
                func_i2_800FD978(arg0, i, 2);
                continue;
            }

            if ((Math_Rand1() & D_i2_80106DC4[temp_v0 - 1])) {
                continue;
            }

            var_v1 = Math_Rand1() % 8;

            while (!sp40[var_v1]) {
                var_v1++;
                var_v1 %= 8;
            }

            var_a1 = (D_i2_80106DA8[var_v1] % 2072) + i;
            if (var_a1 < 0) {
                var_a1 += 0x818;
            }
            func_i2_800FD978(arg0, var_a1, 1);
        }
    }

    if (++arg0->unk_0C < 0x3D) {
        var_a0 = true;

        for (i = 0, var_v0 = arg0->unk_18; i < 0x818; i++, var_v0++) {
            if (!(*var_v0 & 0xF0) || !(*var_v0 & 0xF)) {
                var_a0 = false;
                break;
            }
        }

    } else {
        var_a0 = true;
        // clang-format off
        for (i = 0, var_v0 = arg0->unk_18; i < 0x818; i++) { \
            *var_v0++ = 0x22;
        }
        // clang-format on
    }
    return var_a0;
}

s32 func_i2_800FD840(unk_8010D778* arg0, s32 arg1, s32* arg2) {
    s32 var_a1;
    s32 i;
    s32 var_s3 = 0;
    s16* var_s1 = D_i2_80106DA8;

    for (i = 0; i < 8; i++) {
        var_a1 = (*var_s1 % 2072) + arg1;
        if (var_a1 < 0) {
            var_a1 += 0x818;
        }
        if (func_i2_800FD938(arg0, var_a1) == 0) {
            var_s3++;
            arg2[i] = 1;
        } else {
            arg2[i] = 0;
        }
        var_s1++;
    }
    return var_s3;
}

s8 func_i2_800FD938(unk_8010D778* arg0, s32 arg1) {
    s8* temp_v0 = (s8*) arg0->unk_18 + (arg1 >> 1);
    s8 ret;

    if (arg1 & 1) {
        ret = (*temp_v0 & 0xF);
    } else {
        ret = (*temp_v0 >> 4);
    }
    return ret;
}

void func_i2_800FD978(unk_8010D778* arg0, s32 arg1, s8 arg2) {
    s8* temp_v0 = (s8*) arg0->unk_18 + (arg1 >> 1);

    if (arg1 & 1) {
        *temp_v0 = (*temp_v0 & 0xF0) | arg2;
    } else {
        *temp_v0 = (*temp_v0 & 0xF) | (arg2 << 4);
    }
}

Gfx* func_i2_800FD9C8(Gfx* gfx, unk_8010D778* arg1) {
    s32 temp_v0;
    s32 var_s0;
    s32 j;
    s32 var_s2;
    s32 var_s3;
    s32 i;
    s32 var_v1;

    gSPDisplayList(gfx++, D_8014780);
    var_s2 = 0;

    for (i = 0; i < 0x38; i++) {
        var_s0 = 0;
        for (j = 0; j < 0x4A; j++, var_s2++) {
            if (arg1->unk_10 != 0) {
                if (func_i2_800FD938(arg1, var_s2) != 0) {
                    var_v1 = (var_s3 * 4);
                    temp_v0 = ((i * 4) + 8);
                    if (var_s0 == 0) {
                        continue;
                    }
                } else {
                    if (var_s0 == 0) {
                        var_s3 = j;
                    }
                    var_s0++;
                    continue;
                }
            } else {
                if (func_i2_800FD938(arg1, var_s2) == 0) {
                    var_v1 = (var_s3 * 4);
                    temp_v0 = ((i * 4) + 8);
                    if (var_s0 == 0) {
                        continue;
                    }
                } else {
                    if (var_s0 == 0) {
                        var_s3 = j;
                    }
                    var_s0++;
                    continue;
                }
            }

            gDPFillRectangle(gfx++, var_v1 + 0xC, temp_v0, ((var_s0 * 4) + var_v1 + 0xB), (temp_v0 + 3));
            var_s0 = 0;
        }

        var_v1 = (var_s3 * 4);
        temp_v0 = ((i * 4) + 8);
        if (var_s0 != 0) {
            gDPFillRectangle(gfx++, var_v1 + 0xC, temp_v0, ((var_s0 * 4) + var_v1 + 0xB), (temp_v0 + 3));
            var_s0 = 0;
        }
    }
    return gfx;
}

void func_i2_800FDBDC(unk_8010D778* arg0) {
    s32 i;
    u8* var_v1;

    arg0->unk_1C.unk_00 = 0x40;
    arg0->unk_12 |= 1;

    for (i = 0, var_v1 = arg0->unk_18; i < 0x40; i++) {
        *var_v1++ = 0;
        *var_v1++ = -1;
    }
}

bool func_i2_800FDC98(unk_8010D778*);

void func_i2_800FDC30(unk_8010D778* arg0) {
    switch (arg0->unk_08) {
        case 0:
            break;
        case 1:
            if (func_i2_800FDC98(arg0)) {
                arg0->unk_08 = 2;
            }
            break;
        case 2:
            arg0->unk_12 |= 8;
            break;
    }
}

bool func_i2_800FDC98(unk_8010D778* arg0) {
    bool ret;
    s32 i;
    s32 var_v0;
    s32 var_v1;
    unk_8010D778_unk_1C* var_a2;
    unk_8010D778_unk_18* var_a1;

    var_a1 = arg0->unk_18;
    var_a2 = &arg0->unk_1C;
    arg0->unk_0C++;
    if (arg0->unk_0C > 0) {
        arg0->unk_0C = 0;
        for (i = 0; i < 2; i++) {
            if (var_a2->unk_00 > 0) {
                var_v1 = Math_Rand1() % 64;
                while ((var_a1 + var_v1)->unk_00) {
                    var_v1++;
                    var_v1 %= 64;
                }

                (var_a1 + var_v1)->unk_00 = 1;
                var_a2->unk_00--;
            }
        }
    }

    var_a1 = arg0->unk_18;
    ret = true;

    for (i = 0; i < 64; i++, var_a1++) {
        if (var_a1->unk_00 != 2) {
            ret = false;
        }
        if (var_a1->unk_00 == 1) {
            var_v0 = var_a1->unk_01 - 8;
            if (var_v0 < 0) {
                var_a1->unk_00 = 2;
                var_v0 = 0;
            }
            var_a1->unk_01 = var_v0;
        }
    }

    return ret;
}

extern Gfx D_80147B0[];

Gfx* func_i2_800FDE84(Gfx* gfx, unk_8010D778* arg1) {
    s32 i;
    s32 j;
    unk_8010D778_unk_18* temp_t1;

    gSPDisplayList(gfx++, D_80147B0);

    for (i = 0; i < 8; i++) {
        if (0) {}
        for (j = 0; j < 8; j++) {
            temp_t1 = (unk_8010D778_unk_18*) arg1->unk_18 + (i * 8 + j);
            if (temp_t1->unk_00 != 2) {
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, temp_t1->unk_01);

                gDPLoadTextureTile(gfx++, arg1->unk_14, G_IM_FMT_RGBA, G_IM_SIZ_16b, 296, 0, (j * 37), (i * 28),
                                   (j * 37) + 36, (i * 28) + 27, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gfx++, ((j * 37) + 12) << 2, ((i * 28) + 8) << 2, ((j * 37) + 49) << 2,
                                    ((i * 28) + 36) << 2, 0, (j * 37) << 5, (i * 28) << 5, 1 << 10, 1 << 10);
            }
        }
    }
    return gfx;
}

extern GfxPool D_8024DCE0[2];

void func_i2_800FE13C(unk_8010D778* arg0) {
    s32 pad[11];
    f32 sp104[4];
    f32 spF4[4];
    f32 spE4[4];
    f32 spD4[4];
    s32 pad2[5];
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    Vtx* vtx;
    s32 temp_ft0;
    s32 temp_ft3;
    s32 temp_s4;
    s32 temp_v0;
    s32 var_a1;
    unk_8010D778_unk_18_2* temp_v0_2;

    arg0->unk_12 |= 1;
    arg0->unk_1C.unk_00 = -1;

    for (i = 0; i < 2; i++) {
        vtx = D_8024DCE0[i].unk_2A248;
        sp104[0] = sp104[2] = -33.3f;
        sp104[1] = sp104[3] = sp104[0] + 66.6f + 1.0f;
        spF4[0] = spF4[1] = 25.199999f;
        spF4[2] = spF4[3] = spF4[0] - 50.399998f;

        for (j = 0; j < 8; j++) {
            for (k = 0; k < 8; k++) {
                for (m = 0; m < 4; m++) {
                    if (m & 1) {
                        spE4[m] = (k + 1) * 37;
                    } else {
                        spE4[m] = k * 37;
                    }
                    if (m >= 2) {
                        spD4[m] = (j + 1) * 28;
                    } else {
                        spD4[m] = j * 28;
                    }
                    temp_s4 = Math_Round(sp104[m]);
                    temp_v0 = Math_Round(spF4[m]);
                    temp_ft0 = spE4[m] * 32.0f;
                    temp_ft3 = spD4[m] * 32.0f;
                    SET_VTX(vtx, temp_s4, temp_v0, 0, temp_ft0, temp_ft3, 0, 0, 0, 0);
                    vtx++;
                }
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            temp_v0_2 = (unk_8010D778_unk_18_2*) arg0->unk_18 + (j + i * 8);
            temp_v0_2->unk_00 = 0;
            temp_v0_2->unk_04 = (j * 66.6f) + -233.09999f;
            temp_v0_2->unk_08 = 176.4f - (i * 50.399998f);
            temp_v0_2->unk_0C = 0.0f;
            temp_v0_2->unk_10 = 0.0f;
            temp_v0_2->unk_14 = 0.0f;
            temp_v0_2->unk_18 = 0.0f;
        }
    }
}

extern GfxPool* gGfxPool;
bool func_i2_800FE6F0(unk_8010D778* arg0);

void func_i2_800FE4E4(unk_8010D778* arg0) {
    s32 i;
    s32 temp_v0;
    s32 var_s0;
    unk_8010D778_unk_18_2* var_s0_2;
    MtxF sp70;

    var_s0 = 0;

    switch (arg0->unk_08) {
        case 0:
            break;
        case 1:
            var_s0 = 1;
            if (func_i2_800FE6F0(arg0) != 0) {
                arg0->unk_08 = 2;
                arg0->unk_0C = 0;
            }
            break;
        case 2:
            var_s0 = 1;
            arg0->unk_0C++;
            if (arg0->unk_0C >= 3) {
                arg0->unk_08 = 3;
                arg0->unk_0C = 0;
            }
            break;
        case 3:
            arg0->unk_12 |= 8;
            break;
    }
    if (var_s0 != 0) {
        func_8006D03C(gGfxPool->unk_2B248, &sp70, 60.0f, 16.0f, 8129.0f, 320.0f, 0.0f, 240.0f, 0.0f, &D_i2_8010D772);
        func_8006CC98(gGfxPool->unk_2B288, &sp70, 0.0f, 0.0f, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        var_s0_2 = arg0->unk_18;
        for (i = 0; i < 64; i++) {
            func_8006BC84(&gGfxPool->unk_2B2C8[i], &sp70, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                          var_s0_2->unk_04, var_s0_2->unk_08, var_s0_2->unk_0C);
            var_s0_2++;
        }
    }
}

bool func_i2_800FE6F0(unk_8010D778* arg0) {
    bool var_a0;
    s32 j;
    s32 i;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_4;
    unk_8010D778_unk_1C* temp_v0;
    unk_8010D778_unk_18_2* var_a3;

    temp_v0 = &arg0->unk_1C;
    arg0->unk_0C++;
    if (arg0->unk_0C >= 2) {
        arg0->unk_0C = 0;
        var_v1 = 0;

        if (temp_v0->unk_00 < 0xF) {
            temp_v0->unk_00++;
        }

        if (arg0->unk_0E != 0) {
            for (i = temp_v0->unk_00; i >= 0; i--, var_v1++) {
                if (i >= 8) {
                    continue;
                }

                for (j = 0; j < var_v1 + 1; j++) {
                    var_v1_2 = 7 - j;
                    if (var_v1_2 >= 0) {
                        var_a3 = (unk_8010D778_unk_18_2*) arg0->unk_18 + ((var_v1_2 * 8) + i);
                        if (var_a3->unk_00 == 0) {
                            var_a3->unk_00 = 1;
                        }
                    }
                }
            }
        } else {
            var_v1_4 = 0;
            for (i = 7 - temp_v0->unk_00; i < 8; i++, var_v1_4++) {
                if (i < 0) {
                    continue;
                }

                for (j = 0; j < var_v1_4 + 1; j++) {
                    if (j < 8) {
                        var_a3 = (unk_8010D778_unk_18_2*) arg0->unk_18 + ((j * 8) + i);
                        if (var_a3->unk_00 == 0) {
                            var_a3->unk_00 = 1;
                        }
                    }
                }
            }
        }
    }

    for (i = 0, var_a3 = arg0->unk_18; i < 64; i++, var_a3++) {
        if (var_a3->unk_00 == 1) {
            var_a3->unk_10 = var_a3->unk_10;
            var_a3->unk_14 = var_a3->unk_14;
            var_a3->unk_18 += -60.0f;
            var_a3->unk_04 += var_a3->unk_10;
            var_a3->unk_08 += var_a3->unk_14;
            var_a3->unk_0C += var_a3->unk_18;
            if (var_a3->unk_0C < -10000.0f) {
                var_a3->unk_00 = 2;
                var_a3->unk_0C = -10000.0f;
            }
        }
    }

    var_a0 = true;
    for (i = 0, var_a3 = arg0->unk_18; i < 64; i++, var_a3++) {
        if (var_a3->unk_00 != 2) {
            var_a0 = false;
        }
    }
    return var_a0;
}

extern Gfx D_8014810[];
extern GfxPool D_1000000;

Gfx* func_i2_800FEB2C(Gfx* gfx, unk_8010D778* arg1) {
    s32 pad[2];
    s32 i;
    s32 j;
    f32 var_fv0;
    unk_8010D778_unk_18_2* spA8;
    s32 var_t3;

    gSPDisplayList(gfx++, D_8014810);

    if (arg1->unk_00 == 3) {
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE);
        spA8 = arg1->unk_18;
    }
    gSPPerspNormalize(gfx++, D_i2_8010D772);
    gSPMatrix(gfx++, D_1000000.unk_2B248, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_1000000.unk_2B288, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            var_t3 = (i * 8) + j;
            if (arg1->unk_00 == 3) {
                var_fv0 = 1.0f - (spA8 + var_t3)->unk_0C / -10000.0f;
                if (var_fv0 < 0.0f) {
                    var_fv0 = 0.0f;
                }
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, (s32) (255.0f * var_fv0));
            }

            gSPMatrix(gfx++, &D_1000000.unk_2B2C8[var_t3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPVertex(gfx++, &D_1000000.unk_2A248[var_t3 * 4], 4, 0);

            gDPLoadTextureTile(gfx++, arg1->unk_14, G_IM_FMT_RGBA, G_IM_SIZ_16b, 296, 0, (j * 37), (i * 28),
                               (j * 37) + 36, (i * 28) + 27, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
        }
    }
    return gfx;
}

void func_i2_800FEED8(unk_8010D778* arg0) {
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    Vtx* vtx;
    s32 temp_ft0;
    s32 temp_ft3;
    s32 temp_s4;
    s32 temp_v0;
    s32 var_a1;
    unk_8010D778_unk_18_3* temp_v0_2;
    f32 spC4[4];
    f32 spB4[4];
    f32 spA4[4];
    f32 sp94[4];

    arg0->unk_12 |= 1;
    arg0->unk_1C.unk_00 = 0x40;
    arg0->unk_1C.unk_04 = -1;
    arg0->unk_1C.unk_08 = 0;
    arg0->unk_1C.unk_0C = 0;

    for (i = 0; i < 2; i++) {
        vtx = D_8024DCE0[i].unk_2A248;
        spC4[0] = spC4[2] = -33.3f;
        spC4[1] = spC4[3] = spC4[0] + 66.6f + 1;
        spB4[0] = spB4[1] = 25.199999f;
        spB4[2] = spB4[3] = spB4[0] - 50.399998f;

        for (j = 0; j < 8; j++) {
            for (k = 0; k < 8; k++) {
                for (m = 0; m < 4; m++) {
                    temp_s4 = Math_Round(spC4[m]);
                    temp_v0 = Math_Round(spB4[m]);
                    if (m & 1) {
                        spA4[m] = (k + 1) * 37;
                    } else {
                        spA4[m] = k * 37;
                    }
                    if (m >= 2) {
                        sp94[m] = (j + 1) * 28;
                    } else {
                        sp94[m] = j * 28;
                    }
                    temp_ft0 = spA4[m] * 32.0f;
                    temp_ft3 = sp94[m] * 32.0f;
                    SET_VTX(vtx, temp_s4, temp_v0, 0, temp_ft0, temp_ft3, 0, 0, 0, 0);
                    vtx++;
                }
            }
        }
    }

    for (j = 0; j < 8; j++) {
        for (k = 0; k < 8; k++) {
            temp_v0_2 = (unk_8010D778_unk_18_3*) arg0->unk_18 + (k + j * 8);
            temp_v0_2->unk_00 = 0;
            temp_v0_2->unk_04 = (k * 66.6f) + -233.09999f;
            temp_v0_2->unk_08 = 176.4f - (j * 50.399998f);
            temp_v0_2->unk_0C = 0.0f;
            temp_v0_2->unk_10 = 1.0f;
            temp_v0_2->unk_01 = 0;
        }
    }
}

bool func_i2_800FF494(unk_8010D778*);

void func_i2_800FF284(unk_8010D778* arg0) {
    s32 i;
    bool var_s0;
    unk_8010D778_unk_18_3* var_s0_2;
    MtxF sp74;

    var_s0 = false;
    switch (arg0->unk_08) {
        case 0:
            break;
        case 1:
            var_s0 = true;
            if (func_i2_800FF494(arg0)) {
                arg0->unk_08 = 2;
                arg0->unk_0C = 0;
            }
            break;
        case 2:
            var_s0 = true;
            arg0->unk_0C++;
            if (arg0->unk_0C >= 3) {
                arg0->unk_08 = 3;
                arg0->unk_0C = 0;
            }
            break;
        case 3:
            arg0->unk_12 |= 8;
            break;
    }

    if (var_s0) {
        func_8006D03C(gGfxPool->unk_2B248, &sp74, 60.0f, 16.0f, 8129.0f, 320.0f, 0.0f, 240.0f, 0.0f, &D_i2_8010D772);
        func_8006CC98(gGfxPool->unk_2B288, &sp74, 0.0f, 0.0f, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        var_s0_2 = arg0->unk_18;
        for (i = 0; i < 64; i++) {
            func_8006BC84(&gGfxPool->unk_2B2C8[i], &sp74, var_s0_2->unk_10, var_s0_2->unk_10, var_s0_2->unk_10, 0.0f,
                          0.0f, 1.0f, 0.0f, 1.0f, 0.0f, var_s0_2->unk_04, var_s0_2->unk_08, var_s0_2->unk_0C);
            var_s0_2++;
        }
    }
}

bool func_i2_800FF494(unk_8010D778* arg0) {
    bool var_a0;
    s32 i;
    s32 j;
    unk_8010D778_unk_1C* temp_v0;
    unk_8010D778_unk_18_3* var_a3;

    temp_v0 = &arg0->unk_1C;

    for (i = 0; i < 2; i++) {
        if (temp_v0->unk_00 <= 0) {
            continue;
        }

        temp_v0->unk_00--;

        switch (temp_v0->unk_0C) {
            case 0:
                temp_v0->unk_04++;
                var_a3 = (unk_8010D778_unk_18_3*) arg0->unk_18 + (temp_v0->unk_08 * 8 + temp_v0->unk_04);
                if (temp_v0->unk_04 >= 8 || var_a3->unk_00 != 0) {
                    temp_v0->unk_04--;
                    temp_v0->unk_08++;
                    temp_v0->unk_0C = 1;
                }
                break;
            case 1:
                temp_v0->unk_08++;
                var_a3 = (unk_8010D778_unk_18_3*) arg0->unk_18 + (temp_v0->unk_08 * 8 + temp_v0->unk_04);
                if (temp_v0->unk_08 >= 8 || var_a3->unk_00 != 0) {
                    temp_v0->unk_08--;
                    temp_v0->unk_04--;
                    temp_v0->unk_0C = 2;
                }
                break;
            case 2:
                temp_v0->unk_04--;
                var_a3 = (unk_8010D778_unk_18_3*) arg0->unk_18 + (temp_v0->unk_08 * 8 + temp_v0->unk_04);
                if (temp_v0->unk_04 < 0 || var_a3->unk_00 != 0) {
                    temp_v0->unk_04++;
                    temp_v0->unk_08--;
                    temp_v0->unk_0C = 3;
                }
                break;
            case 3:
                temp_v0->unk_08--;
                var_a3 = (unk_8010D778_unk_18_3*) arg0->unk_18 + (temp_v0->unk_08 * 8 + temp_v0->unk_04);
                if (temp_v0->unk_08 < 0 || var_a3->unk_00 != 0) {
                    temp_v0->unk_08++;
                    temp_v0->unk_04++;
                    temp_v0->unk_0C = 0;
                }
                break;
            default:
                break;
        }
        var_a3 = (unk_8010D778_unk_18_3*) arg0->unk_18 + (temp_v0->unk_08 * 8 + temp_v0->unk_04);
        var_a3->unk_00 = 1;
    }

    for (i = 0, var_a3 = arg0->unk_18; i < 64; i++, var_a3++) {
        if (var_a3->unk_00 == 1) {
            if (var_a3->unk_01 < 11) {
                var_a3->unk_10 = (10 - var_a3->unk_01) / 10.0f;
                var_a3->unk_01++;

            } else {
                var_a3->unk_00 = 2;
                var_a3->unk_10 = 0.0f;
            }
        }
    }

    var_a0 = true;
    for (i = 0, var_a3 = arg0->unk_18; i < 64; i++, var_a3++) {
        if (var_a3->unk_00 != 2) {
            var_a0 = false;
        }
    }
    return var_a0;
}

void func_i2_800FF7A8(unk_8010D778* arg0, s32 arg1, s32 arg2) {

    arg0->unk_1C.unk_00 = arg0->unk_1C.unk_04 = arg0->unk_1C.unk_08 = 0;
    arg0->unk_1C.unk_0C = arg1;

    if (arg0->unk_0E != 0) {
        arg0->unk_1C.unk_10 = arg0->unk_0E;
    } else {
        arg0->unk_1C.unk_10 = arg2;
    }
}

void func_i2_800FF7D4(unk_8010D778* arg0) {
    unk_8010D778_unk_1C* temp_v0;

    temp_v0 = &arg0->unk_1C;

    switch (arg0->unk_08) {
        case 1:
            temp_v0->unk_0C = (arg0->unk_0C * 255.0f) / temp_v0->unk_10;
            arg0->unk_0C++;
            if (temp_v0->unk_10 < arg0->unk_0C) {
                arg0->unk_08 = 2;
                arg0->unk_0C = 0;
                temp_v0->unk_0C = 255;
            }
            break;
        case 2:
            arg0->unk_0C++;
            if (arg0->unk_0C >= 2) {
                arg0->unk_08 = 4;
            }
            break;
        case 3:
            temp_v0->unk_0C = ((temp_v0->unk_10 - arg0->unk_0C) * 255.0f) / temp_v0->unk_10;
            arg0->unk_0C++;

            if (temp_v0->unk_10 < arg0->unk_0C) {
                arg0->unk_08 = 4;
                arg0->unk_0C = 0;
                temp_v0->unk_0C = 0;
            }
            break;
        case 4:
            arg0->unk_12 |= 8;
            break;
        case 0:
        default:
            break;
    }
}

extern Gfx D_8014888[];

Gfx* func_i2_800FF91C(Gfx* gfx, unk_8010D778* arg1) {
    unk_8010D778_unk_1C* temp_v1 = &arg1->unk_1C;

    gSPDisplayList(gfx++, D_8014888);

    if (arg1->unk_00 == 6) {
        gDPSetAlphaCompare(gfx++, G_AC_DITHER);
    }

    gDPSetPrimColor(gfx++, 0, 0, temp_v1->unk_00, temp_v1->unk_04, temp_v1->unk_08, temp_v1->unk_0C);

    gDPFillRectangle(gfx++, 12, 8, 308, 232);

    return gfx;
}

void func_i2_800FF9C8(unk_8010D778* arg0) {

    arg0->unk_1C.unk_00 = 0xC;
    arg0->unk_1C.unk_04 = 8;
    arg0->unk_12 |= 1;

    switch (arg0->unk_0E) {
        case 0:
        case 1:
            D_8010D770 = arg0->unk_1C.unk_00;
            break;
        case 2:
        case 3:
            D_8010D770 = arg0->unk_1C.unk_04;
            break;
    }
}

void func_i2_800FFA34(unk_8010D778* arg0) {
    unk_8010D778_unk_1C* temp_v0 = &arg0->unk_1C;

    switch (arg0->unk_08) {
        case 0:
            break;
        case 1:
            switch (arg0->unk_0E) {
                case 0:
                    temp_v0->unk_00 = 12 - (s32) ((arg0->unk_0C * 296.0f) / 20.0f);
                    D_8010D770 = temp_v0->unk_00;
                    break;
                case 1:
                    temp_v0->unk_00 = (s32) ((arg0->unk_0C * 296.0f) / 20.0f) + 12;
                    D_8010D770 = temp_v0->unk_00;
                    break;
                case 2:
                    temp_v0->unk_04 = 8 - (s32) ((arg0->unk_0C * 224.0f) / 20.0f);
                    D_8010D770 = temp_v0->unk_04;
                    break;
                case 3:
                    temp_v0->unk_04 = (s32) ((arg0->unk_0C * 224.0f) / 20.0f) + 8;
                    D_8010D770 = temp_v0->unk_04;
                    break;
            }

            arg0->unk_0C++;
            if (arg0->unk_0C >= 0x15) {
                arg0->unk_08 = 2;
                arg0->unk_0C = 0;
                arg0->unk_1C.unk_00 = 0x134;
            }
            break;
        case 2:
            arg0->unk_12 |= 8;
            break;
    }
}

Gfx* func_i2_800FFBF4(Gfx* gfx, unk_8010D778* arg1) {

    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return func_8007B14C(gfx, arg1->unk_14, arg1->unk_1C.unk_00, arg1->unk_1C.unk_04, 296, 224, G_IM_FMT_RGBA,
                         G_IM_SIZ_16b, 0, 0, 0, 0);
}

void func_i2_800FFC68(unk_8010D778* arg0) {
    s32 i;
    f32* var_v1;

    arg0->unk_12 |= 1;

    for (i = 0, var_v1 = arg0->unk_18; i < 224; i++, var_v1++) {
        *var_v1 = 12.0f;
    }
}

bool func_i2_800FFD4C(unk_8010D778*);

void func_i2_800FFCAC(unk_8010D778* arg0) {

    switch (arg0->unk_08) {
        case 0:
            break;
        case 1:
            if (func_i2_800FFD4C(arg0)) {
                arg0->unk_08 = 2;
                arg0->unk_0C = 0;
            }
            break;
        case 2:
            arg0->unk_0C++;
            if (arg0->unk_0C >= 2) {
                arg0->unk_08 = 3;
                arg0->unk_0C = 0;
            }
            break;
        case 3:
            arg0->unk_12 |= 8;
            break;
    }
}

bool func_i2_800FFD4C(unk_8010D778* arg0) {
    f32 var_fv0;
    s32 var_a2;
    s32 var_a3;
    s32 i;
    bool var_v1;
    f32* var_a1;
    s32 var = 224 / 2;

    var_v1 = true;

    for (i = 0, var_a1 = arg0->unk_18; i < 224; i++, var_a1++) {
        var_a2 = var - i;

        if (var_a2 < 0) {
            var_a2 = -var_a2;
        }

        var_a2 = var - var_a2;
        var_a3 = (arg0->unk_0C * D_i2_80106DC0) - var_a2;

        if (var_a3 < 0) {
            var_a3 = 0;
        }
        var_fv0 = var_a3 * 0.5f;

        if (i & 1) {
            var_fv0 = 0.0f - var_fv0;
        }
        *var_a1 += var_fv0;
        if ((*var_a1 >= 12.0f) && (*var_a1 < 308.0f)) {
            var_v1 = false;
        }
    }
    arg0->unk_0C++;

    return var_v1;
}

#ifdef NON_EQUIVALENT
Gfx* func_i2_800FFEEC(Gfx* gfx, unk_8010D778* arg1) {
    f32* var_t3;
    u16* var_s5;
    s32 i;
    s32 j;
    s32 sp30[2];
    s32 width = 296;
    s32 tileHeight = 4;
    s32 var;
    s32 xl;
    s32 xh;
    s32 yl;
    s32 yh;
    s32 var_t5;

    gSPDisplayList(gfx++, D_8014940);

    sp30[1] = 0x38;
    sp30[0] = 0;

    var_t5 = 4;
    var_s5 = arg1->unk_14;
    var_t3 = arg1->unk_18;

    for (i = 0; i < sp30[1]; i++) {
        gDPPipeSync(gfx++);
        gDPLoadTextureTile(gfx++, var_s5 + i * 0x4A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 296, 4, 0, 0, 296 - 1, 4 - 1, 0,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);

        for (j = 0; j < var_t5; j++) {
            if ((*var_t3 < -284.0f) || (*var_t3 > 308.0f)) {
                var_t3++;
                continue;
            }

            var = (i * 4) + j;
            xl = *var_t3 * 4.0f;
            xh = (*var_t3 + width) * 4.0f;

            var_t3++;

            gSPScisTextureRectangle(gfx++, xl, (var + 8) << 2, xh, (var + 9) << 2, 0, 0, j << 5, 1 << 10, 1 << 10);
        }
    }

    return gfx;
}
#else
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FFEEC.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FFEEC.s")
#endif
#endif

void func_i2_80100220(unk_8010D778* arg0) {
    arg0->unk_12 |= 1;
    arg0->unk_12 |= 0x10;
    arg0->unk_12 |= 0x40;
    arg0->unk_1C.unk_00 = -8;
}

bool func_i2_801002E8(unk_8010D778*);

void func_i2_80100248(unk_8010D778* arg0) {

    switch (arg0->unk_08) {
        case 0:
            break;
        case 1:
            if (func_i2_801002E8(arg0)) {
                arg0->unk_08 = 2;
                arg0->unk_0C = 0;
            }
            break;
        case 2:
            arg0->unk_0C++;
            if (arg0->unk_0C >= 4) {
                arg0->unk_08 = 3;
                arg0->unk_0C = 0;
            }
            break;
        case 3:
            arg0->unk_12 |= 8;
            break;
    }
}

bool func_i2_801002E8(unk_8010D778* arg0) {
    bool var_v1 = false;

    if (arg0->unk_1C.unk_00 >= 0) {
        D_i2_8010D7B0[arg0->unk_1C.unk_00] = 0;
    }
    arg0->unk_0C++;
    if (arg0->unk_0C >= 2) {
        arg0->unk_0C = 0;
        arg0->unk_1C.unk_00++;
        if (arg0->unk_1C.unk_00 > 31) {
            arg0->unk_1C.unk_00 = 31;
            var_v1 = true;
        }
    }
    return var_v1;
}

Gfx* func_i2_8010034C(Gfx* gfx, unk_8010D778* arg1) {
    return func_8007E410(gfx, arg1->unk_14, D_i2_8010D7AC, G_IM_FMT_CI, 1, 12, 8, 296, 224, 5);
}
