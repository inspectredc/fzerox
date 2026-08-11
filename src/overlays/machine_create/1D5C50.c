#include "global.h"
#include "machine_create.h"
#include "leo/mfs.h"

u8 gMachineCreateSuperMachinesCount = 0;

extern EKLoadedFile gExpansionKitLoadedFiles[];
extern u8 D_i2_80111848[];

void func_xk3_80135F90(void) {
    u8 i;

    gMachineCreateSuperMachinesCount = 0;

    for (i = 0; i < 30; i++) {
        gMachineCreateSuperMachinesCount += D_i2_80111848[i];
    }
    if (gWorksMachineMode == MACHINE_MODE_ENTRY_GET_FILE) {
        if (gMachineCreateSuperMachinesCount != 0) {
            func_8076877C(1, "CARD");
            mfsStrCpy(gExpansionKitLoadedFiles[0].name, "SUPER");
        } else {
            func_8076877C(0, "CARD");
        }
    } else {
        mfsStrCpy(gExpansionKitLoadedFiles[0].name, "NEW");
        if (gMachineCreateSuperMachinesCount != 0) {
            func_8076877C(2, "CARD");
            gExpansionKitLoadedFiles[1].attr = 0;
            gExpansionKitLoadedFiles[1].unk_22 = 1;
            mfsStrCpy(gExpansionKitLoadedFiles[1].name, "SUPER");
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
            gExpansionKitLoadedFiles[var_s1].attr = 0;
            gExpansionKitLoadedFiles[var_s1].unk_22 = 0;
            mfsStrCpy(gExpansionKitLoadedFiles[var_s1].name, gSuperMachineNames[i]);
            var_s1++;
        }
    }
    EKFileMenu_SetFileCount(var_s1);
    func_xk1_8002D290();
}

extern CustomMachinesInfo gCustomMachinesInfo;

u8 func_xk3_8013618C(s32 arg0) {
    u8 var_s3;
    u8 i;

    var_s3 = 0;
    for (i = 0, gMachineCreateSuperMachinesCount = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] == -1) {
            gMachineCreateSuperMachinesCount++;
        }
    }
    if (gMachineCreateSuperMachinesCount != 0) {
        gExpansionKitLoadedFiles[0].attr = 0;
        gExpansionKitLoadedFiles[0].unk_22 = 1;
        mfsStrCpy(gExpansionKitLoadedFiles[0].name, "SUPER");
        var_s3 = 1;
    }

    for (i = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] > 0) {
            gExpansionKitLoadedFiles[var_s3].attr = 0;
            gExpansionKitLoadedFiles[var_s3].unk_22 = 0;
            mfsStrCpy(gExpansionKitLoadedFiles[var_s3].name, gCustomMachinesInfo.customMachines[i].machineName);
            var_s3++;
        }
    }
    if (arg0 == 1) {
        EKFileMenu_SetFileListScroll(0);
    }
    EKFileMenu_SetFileCount(var_s3);
    func_xk1_8002D290();
    if (gMachineCreateSuperMachinesCount != 0) {
        EKFileMenu_QSort(gExpansionKitLoadedFiles[1].name, var_s3 - 1, sizeof(EKLoadedFile), EKFileMenu_Compare);
    } else {
        EKFileMenu_QSort(gExpansionKitLoadedFiles[0].name, var_s3, sizeof(EKLoadedFile), EKFileMenu_Compare);
    }
    return var_s3;
}

u8 func_xk3_80136320(void) {
    u8 i;
    u8 var_s1;

    for (i = 0, var_s1 = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] == -1) {
            gExpansionKitLoadedFiles[var_s1].attr = 0;
            gExpansionKitLoadedFiles[var_s1].unk_22 = 0;
            mfsStrCpy(gExpansionKitLoadedFiles[var_s1].name, gSuperMachineNames[i]);
            var_s1++;
        }
    }
    EKFileMenu_SetFileCount(var_s1);
    func_xk1_8002D290();
    return var_s1;
}

bool func_xk3_801363F8(EKLoadedFile* arg0) {
    bool superMachineFileExists;
    u8 i;

    for (i = 0; i < 30; i++) {
        if ((gCustomMachinesInfo.characterCustomState[i] > 0 &&
             mfsStrCmp(arg0->name, gCustomMachinesInfo.customMachines[i].machineName) == 0) ||
            (gCustomMachinesInfo.characterCustomState[i] == -1 && mfsStrCmp(arg0->name, gSuperMachineNames[i]) == 0)) {
            if (arg0->unk_22 == 0) {
                return true;
            }
        }
    }
    superMachineFileExists = false;

    for (i = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] == -1) {
            superMachineFileExists = true;
            break;
        }
    }
    if (superMachineFileExists && (arg0->unk_22 == 1) && (mfsStrCmp(arg0->name, "SUPER") == 0)) {
        return true;
    }
    return false;
}
