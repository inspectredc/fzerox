#include "global.h"
#include "machine_create.h"
#include "leo/mfs.h"

u8 D_xk3_80137160 = 0;

extern unk_8003A5D8 D_xk1_8003A5D8[];
extern u8 D_i2_80111848[];

void func_xk3_80135F90(void) {
    u8 i;

    D_xk3_80137160 = 0;

    for (i = 0; i < 30; i++) {
        D_xk3_80137160 += D_i2_80111848[i];
    }
    if (gWorksMachineMode == MACHINE_MODE_ENTRY_GET_FILE) {
        if (D_xk3_80137160 != 0) {
            func_8076877C(1, "CARD");
            mfsStrCpy(D_xk1_8003A5D8[0].name, "SUPER");
        } else {
            func_8076877C(0, "CARD");
        }
    } else {
        mfsStrCpy(D_xk1_8003A5D8[0].name, "NEW");
        if (D_xk3_80137160 != 0) {
            func_8076877C(2, "CARD");
            D_xk1_8003A5D8[1].attr = 0;
            D_xk1_8003A5D8[1].unk_22 = 1;
            mfsStrCpy(D_xk1_8003A5D8[1].name, "SUPER");
        } else {
            func_8076877C(1, "CARD");
        }
    }
}

extern const char* gSuperMachineNames[];

void func_xk3_801360B8(void) {
    u8 i;
    u8 var_s1;

    for (i = 0, var_s1 = 0; i < 30; i++) {
        if (D_i2_80111848[Character_GetCharacterFromSlot(i)] != 0) {
            D_xk1_8003A5D8[var_s1].attr = 0;
            D_xk1_8003A5D8[var_s1].unk_22 = 0;
            mfsStrCpy(D_xk1_8003A5D8[var_s1].name, gSuperMachineNames[i]);
            var_s1++;
        }
    }
    func_xk1_8002D284(var_s1);
    func_xk1_8002D290();
}

extern CustomMachinesInfo gCustomMachinesInfo;

u8 func_xk3_8013618C(s32 arg0) {
    u8 var_s3;
    u8 i;

    var_s3 = 0;
    for (i = 0, D_xk3_80137160 = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] == -1) {
            D_xk3_80137160++;
        }
    }
    if (D_xk3_80137160 != 0) {
        D_xk1_8003A5D8[0].attr = 0;
        D_xk1_8003A5D8[0].unk_22 = 1;
        mfsStrCpy(D_xk1_8003A5D8[0].name, "SUPER");
        var_s3 = 1;
    }

    for (i = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] > 0) {
            D_xk1_8003A5D8[var_s3].attr = 0;
            D_xk1_8003A5D8[var_s3].unk_22 = 0;
            mfsStrCpy(D_xk1_8003A5D8[var_s3].name, gCustomMachinesInfo.customMachines[i].machineName);
            var_s3++;
        }
    }
    if (arg0 == 1) {
        func_xk1_8002D278(0);
    }
    func_xk1_8002D284(var_s3);
    func_xk1_8002D290();
    if (D_xk3_80137160 != 0) {
        func_xk1_8002CEF8(D_xk1_8003A5D8[1].name, var_s3 - 1, 0x24, func_xk1_8002CA98);
    } else {
        func_xk1_8002CEF8(D_xk1_8003A5D8[0].name, var_s3, 0x24, func_xk1_8002CA98);
    }
    return var_s3;
}

u8 func_xk3_80136320(void) {
    u8 i;
    u8 var_s1;

    for (i = 0, var_s1 = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] == -1) {
            D_xk1_8003A5D8[var_s1].attr = 0;
            D_xk1_8003A5D8[var_s1].unk_22 = 0;
            mfsStrCpy(D_xk1_8003A5D8[var_s1].name, gSuperMachineNames[i]);
            var_s1++;
        }
    }
    func_xk1_8002D284(var_s1);
    func_xk1_8002D290();
    return var_s1;
}

s32 func_xk3_801363F8(unk_8003A5D8* arg0) {
    bool var_v0;
    u8 i;

    for (i = 0; i < 30; i++) {
        if ((gCustomMachinesInfo.characterCustomState[i] > 0 &&
             mfsStrCmp(arg0->name, gCustomMachinesInfo.customMachines[i].machineName) == 0) ||
            (gCustomMachinesInfo.characterCustomState[i] == -1 && mfsStrCmp(arg0->name, gSuperMachineNames[i]) == 0)) {
            if (arg0->unk_22 == 0) {
                return 1;
            }
        }
    }
    var_v0 = false;

    for (i = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] == -1) {
            var_v0 = true;
            break;
        }
    }
    if (var_v0 && (arg0->unk_22 == 1) && (mfsStrCmp(arg0->name, "SUPER") == 0)) {
        return 1;
    }
    return 0;
}
