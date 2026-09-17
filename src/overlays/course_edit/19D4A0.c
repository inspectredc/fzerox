#include "global.h"
#include "course_edit.h"
#include "leo/mfs.h"
#include "fzx_expansion_kit.h"

s32 gCourseEditCourseRegisterIndex = 0;
s32 sCourseEditRegisterFileMenuIndex = 0;

extern char gEditCupTrackNames[4 * 6][9];
extern CourseEditContext gCourseEditContext;

void func_xk2_800EB9E0(void) {
    if (SLCheckDiskChange2()) {
        func_807685D8(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames));
    }
    gCourseEditContext.state = COURSE_EDIT_VALIDATE_FILE_NAMES;
}

void CourseEdit_ValidateRegisteredTrackNames(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (Mfs_ValidateFileName(gEditCupTrackNames[i]) != 0) {
            gEditCupTrackNames[i][0] = '\0';
        }
    }

    for (i = 0; i < 6; i++) {
        if ((gEditCupTrackNames[i][0] != '\0') &&
            (Mfs_GetFileIndex(MFS_ENTRY_WORKING_DIR, gEditCupTrackNames[i], "CRSD") == MFS_ENTRY_DOES_NOT_EXIST) &&
            (Mfs_GetFileIndex(MFS_ENTRY_WORKING_DIR, gEditCupTrackNames[i], "CRSE") == MFS_ENTRY_DOES_NOT_EXIST)) {
            gEditCupTrackNames[i][0] = '\0';
        }
    }
    sCourseEditRegisterFileMenuIndex = 0;
    gCourseEditContext.state = COURSE_EDIT_REGISTER_FILE_MENU;
}

extern Gfx D_8014940[];

extern s32 gCourseEditMenuCursorYPos;
extern s32 gExpansionKitEncStrEncType;

Gfx* CourseEdit_DrawFileRegisterMenu(Gfx* gfx) {
    s32 highlightedIndex;
    s32 i;
    s32 top;
    u8* trackNameEncStr;

    highlightedIndex = (gCourseEditMenuCursorYPos - 52) / 8;

    if (gCourseEditContext.state != COURSE_EDIT_REGISTER_FILE_MENU) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_8014940);

    EKFileMenu_DrawFileMenuBorder(&gfx, 200, 80, 12, 8);

    for (i = 0; i < 6; i++) {
        trackNameEncStr = gEditCupTrackNames[i];
        top = (i * 8) + 88;
        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

        if (i == highlightedIndex) {
            gDPSetPrimColor(gfx++, 0, 0, 190, 175, 255, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 0);
        }

        gSPTextureRectangle(gfx++, 206 << 2, top << 2, 290 << 2, (top + 8) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gDPPipeSync(gfx++);

        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);

        if (trackNameEncStr[0] == '\0') {
            gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
            if (i == highlightedIndex) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
            }
            gExpansionKitEncStrEncType = 0;
            gfx = ExpansionKit_DrawEncStr(gfx, 208, top, "%d:", i + 1);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            if (i == highlightedIndex) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
            }
            gfx = ExpansionKit_DrawEncStr(gfx, 208, top, "%d:%s", i + 1, trackNameEncStr);
        }
    }
    PRINTF("ENTRY.c\n");
    PRINTF("EDIT_MODE_COURSE 40\n");

    return gfx;
}

extern s32 gCourseEditEntryOption;

void CourseEdit_RegisterFileMenuHandleBPress(void) {
    if ((gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) &&
        (gCourseEditContext.state == COURSE_EDIT_REGISTER_FILE_MENU)) {
        Audio_TriggerSystemSE(NA_SE_37);
        gCourseEditContext.state = 0;
        gCourseEditEntryOption = -1;
    }
}

void CourseEdit_UpdateRegisterFileMenuOption(void) {
    s32 prevIndex;

    prevIndex = sCourseEditRegisterFileMenuIndex;
    EKController_UpdateVerticalOptionSlow(&sCourseEditRegisterFileMenuIndex, 5, 0);

    if (prevIndex != sCourseEditRegisterFileMenuIndex) {
        Audio_TriggerSystemSE(NA_SE_35);
    }
    gCourseEditMenuCursorYPos = (sCourseEditRegisterFileMenuIndex * 8) + 0x38;
}

extern s32 D_80119880;
extern s32 gCourseEditRegistrationState;
extern s32 gExpansionKitYesNoOptionIndex;
extern u8 D_xk2_800F7400;

void CourseEdit_RegisterFileMenuHandleAPress(void) {
    if ((gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) &&
        (gCourseEditContext.state == COURSE_EDIT_REGISTER_FILE_MENU)) {
        Audio_TriggerSystemSE(NA_SE_36);
        gCourseEditCourseRegisterIndex = (gCourseEditMenuCursorYPos - 52) / 8;
        switch (gCourseEditRegistrationState) {
            case 0:
                gCourseEditContext.state = COURSE_EDIT_STATE_49;
                D_80119880 = 5;
                func_8076877C(0, "CRSD");
                D_xk2_800F7400 = 1;
                break;
            case 1:
                gExpansionKitYesNoOptionIndex = 0;
                gCourseEditContext.state = 0x23;
                break;
        }
    }

    PRINTF("(%s)-(%s) CLEAR\n");
}

void CourseEdit_EraseTrackName(char* name) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (mfsStrCmp(name, gEditCupTrackNames[i]) == 0) {
            gEditCupTrackNames[i][0] = '\0';
        }
    }
}

extern EKLoadedFile gExpansionKitLoadedFiles[];

void func_xk2_800EC04C(void) {
    bool var_s3;
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        var_s3 = true;
        if (gEditCupTrackNames[i][0] != '\0') {
            for (j = 0; j < EKFileMenu_GetFileCount(); j++) {
                if (mfsStrCmp(gExpansionKitLoadedFiles[j].name, gEditCupTrackNames[i]) == 0) {
                    var_s3 = false;
                }
            }
            if (var_s3) {
                gEditCupTrackNames[i][0] = '\0';
            }
        }
    }
}

void func_xk2_800EC110(void) {
    func_8070405C(false);
    func_80768434(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames), 0, 0xFF,
                  1);
    gCourseEditEntryOption = -1;
    PRINTF("ENTRY SAVE AFTER DELETE OR RENAME\n");
}

void func_xk2_800EC174(void) {
    func_8070405C(false);
    func_807682C0(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames), 0, 0xFF,
                  1);
    gCourseEditEntryOption = -1;
}

void func_xk2_800EC1D8(void) {
    func_8070405C(false);
    func_8076833C(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames), 0, 0xFF,
                  1);
}

bool func_xk2_800EC234(EKLoadedFile* arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (mfsStrCmp(arg0->name, gEditCupTrackNames[i]) == 0) {
            return true;
        }
    }
    return false;
}
