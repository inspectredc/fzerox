#include "global.h"
#include "machine_create.h"
#include "leo/mfs.h"

u8 gMachineCreateSuperMachinesCount = 0;

extern EKLoadedFile gExpansionKitLoadedFiles[];
extern u8 gMachineHasSuperVersion[];

void MachineCreate_FileListSetup(void) {
    u8 i;

    gMachineCreateSuperMachinesCount = 0;

    for (i = 0; i < 30; i++) {
        gMachineCreateSuperMachinesCount += gMachineHasSuperVersion[i];
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

void MachineCreate_FileSuperMachineListSetup(void) {
    u8 i;
    u8 fileCount;

    for (i = 0, fileCount = 0; i < 30; i++) {
        if (gMachineHasSuperVersion[Character_GetCharacterFromSlot(i)]) {
            gExpansionKitLoadedFiles[fileCount].attr = 0;
            gExpansionKitLoadedFiles[fileCount].unk_22 = 0;
            mfsStrCpy(gExpansionKitLoadedFiles[fileCount].name, gSuperMachineNames[i]);
            fileCount++;
        }
    }
    EKFileMenu_SetFileCount(fileCount);
    EKFileMenu_EnableFileMenuDraw();
}

extern CustomMachinesInfo gCustomMachinesInfo;

u8 MachineCreate_FileListClearSetup(s32 bringToTopOption) {
    u8 fileCount;
    u8 i;

    fileCount = 0;
    for (i = 0, gMachineCreateSuperMachinesCount = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] == -1) {
            gMachineCreateSuperMachinesCount++;
        }
    }
    if (gMachineCreateSuperMachinesCount != 0) {
        gExpansionKitLoadedFiles[0].attr = 0;
        gExpansionKitLoadedFiles[0].unk_22 = 1;
        mfsStrCpy(gExpansionKitLoadedFiles[0].name, "SUPER");
        fileCount = 1;
    }

    for (i = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] > 0) {
            gExpansionKitLoadedFiles[fileCount].attr = 0;
            gExpansionKitLoadedFiles[fileCount].unk_22 = 0;
            mfsStrCpy(gExpansionKitLoadedFiles[fileCount].name, gCustomMachinesInfo.customMachines[i].machineName);
            fileCount++;
        }
    }
    if (bringToTopOption == 1) {
        EKFileMenu_SetFileListScroll(0);
    }
    EKFileMenu_SetFileCount(fileCount);
    EKFileMenu_EnableFileMenuDraw();
    if (gMachineCreateSuperMachinesCount != 0) {
        EKFileMenu_QSort(gExpansionKitLoadedFiles[1].name, fileCount - 1, sizeof(EKLoadedFile), EKFileMenu_Compare);
    } else {
        EKFileMenu_QSort(gExpansionKitLoadedFiles[0].name, fileCount, sizeof(EKLoadedFile), EKFileMenu_Compare);
    }
    return fileCount;
}

u8 MachineCreate_FileListClearSuperSetup(void) {
    u8 i;
    u8 fileCount;

    for (i = 0, fileCount = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] == -1) {
            gExpansionKitLoadedFiles[fileCount].attr = 0;
            gExpansionKitLoadedFiles[fileCount].unk_22 = 0;
            mfsStrCpy(gExpansionKitLoadedFiles[fileCount].name, gSuperMachineNames[i]);
            fileCount++;
        }
    }
    EKFileMenu_SetFileCount(fileCount);
    EKFileMenu_EnableFileMenuDraw();
    return fileCount;
}

bool MachineCreate_FileListIsFileForSuperMachine(EKLoadedFile* file) {
    bool superMachineFileExists;
    u8 i;

    for (i = 0; i < 30; i++) {
        if ((gCustomMachinesInfo.characterCustomState[i] > 0 &&
             mfsStrCmp(file->name, gCustomMachinesInfo.customMachines[i].machineName) == 0) ||
            (gCustomMachinesInfo.characterCustomState[i] == -1 && mfsStrCmp(file->name, gSuperMachineNames[i]) == 0)) {
            if (file->unk_22 == 0) {
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
    if (superMachineFileExists && (file->unk_22 == 1) && (mfsStrCmp(file->name, "SUPER") == 0)) {
        return true;
    }
    return false;
}
