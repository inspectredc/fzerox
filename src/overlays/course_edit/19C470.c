#include "global.h"
#include "course_edit.h"
#include "leo/mfs.h"
#include "fzx_save.h"
#include "fzx_course.h"
#include "fzx_expansion_kit.h"

u8 D_xk2_800F7400 = 0xFF;
s32 D_xk2_800F7404 = 0;
CourseContext D_xk2_800F7408 = { { CREATOR_NINTENDO, 0, 0, 0, 0, 0, { 0 }, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } } };

void CourseEdit_WriteExtension(s8* extensionOut, s8* extension) {
    extensionOut[0] = extension[0];
    extensionOut[1] = extension[1];
    extensionOut[2] = extension[2];
    extensionOut[3] = extension[3];
    extensionOut[4] = extension[4];
}

extern s32 gMfsError;

void func_xk2_800EA9DC(char* errorMessage) {
    if (gMfsError <= LEO_ERROR_DEVICE_COMMUNICATION_FAILURE) {
        PRINTF("%s DEVICE COMMUNICATION FAILURE\n", errorMessage);
        return;
    }

    switch (gMfsError) {
        case N64DD_MEDIA_NOT_INIT:
            PRINTF("%s MEDIA_NOT_INIT\n", errorMessage);
            break;
        case N64DD_AREA_LACKED:
            PRINTF("%s AREA_LACKED\n", errorMessage);
            break;
        case N64DD_NOT_FOUND:
            PRINTF("%s NOT_FOUND\n", errorMessage);
            break;
        case N64DD_DISK_DAMAGED:
            PRINTF("%s DISK_DAMAGED\n", errorMessage);
            break;
        case N64DD_ARGUMENT_ILLEGAL:
            PRINTF("%s ARGUMENT_ILLEGAL\n", errorMessage);
            break;
        case N64DD_DISKID_ILLEGAL:
            PRINTF("%s DISKID_ILLEGAL\n", errorMessage);
            break;
        case N64DD_READ_ONLY_MEDIA:
            PRINTF("%s READ_ONLY_MEDIA\n", errorMessage);
            break;
        case N64DD_MANAGER_NOT_CREATED:
            PRINTF("%s MANAGER_NOT_CREATED\n", errorMessage);
            break;
        default:
            PRINTF("%s UNKNOWN ERROR -> 0x%X\n", errorMessage, gMfsError);
            break;
    }
    // TODO: move to more appropriate place
    PRINTF("FILE OVER\n");
    PRINTF("saving checksum is %d\n");
    PRINTF("file_access_mode %d\n");
}

extern u8 gCourseEditCourseTitleEncStr[];
extern u8 D_8003006C[];
extern s32 D_80119880;
extern EKLoadedFile D_xk1_8003A598;
extern s32 D_xk2_80104378;
extern CourseEditContext gCourseEditContext;
extern s32 gExpansionKitYesNoOptionIndex;
extern unk_807B3C20 D_802CB6D0;

s32 func_xk2_800EAA1C(u8* name) {
    SaveCourseRecords* courseRecords = &COURSE_CONTEXT()->saveCourseRecord;
    GhostSave* ghostSave;
    s32 i;
    u32 checksum;

    if ((EKFileMenu_GetFileCount() > 100) && (D_80119880 == -1)) {
        D_xk2_80104378 = 6;
        gExpansionKitYesNoOptionIndex = 0;
        gCourseEditContext.state = 0x10;
        return -1;
    }
    COURSE_CONTEXT()->courseData.creatorId = CREATOR_NINTENDO;
    COURSE_CONTEXT()->courseData.controlPointCount = D_802CB6D0.controlPointCount;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        COURSE_CONTEXT()->courseData.controlPoint[i].pos = D_802CB6D0.segments[i].pos;
        COURSE_CONTEXT()->courseData.controlPoint[i].radiusLeft = D_802CB6D0.segments[i].radiusLeft;
        COURSE_CONTEXT()->courseData.controlPoint[i].radiusRight = D_802CB6D0.segments[i].radiusRight;
        COURSE_CONTEXT()->courseData.controlPoint[i].trackSegmentInfo = D_802CB6D0.segments[i].trackSegmentInfo;
    }
    checksum = Course_CalculateChecksum();
    ghostSave = COURSE_CONTEXT()->ghostSave;
    ghostSave->record.encodedCourseIndex = 0;
    ghostSave->record.raceTime = MAX_TIMER;
    ghostSave++;
    ghostSave->record.encodedCourseIndex = 0;
    ghostSave->record.raceTime = MAX_TIMER;
    ghostSave++;
    ghostSave->record.encodedCourseIndex = 0;
    ghostSave->record.raceTime = MAX_TIMER;
    Save_InitCourseRecord(courseRecords, true);
    COURSE_CONTEXT()->courseData.checksum = checksum;
    if ((D_80119880 == -1) || (D_80119880 == 1)) {
        if (COURSE_CONTEXT()->courseData.flag != 0) {
            mfsStrCpy(D_xk1_8003A598.name, name);
            CourseEdit_WriteExtension(D_xk1_8003A598.extension, "CRSD");
            gCourseEditContext.state = 0x14;
        } else {
            mfsStrCpy(D_xk1_8003A598.name, name);
            CourseEdit_WriteExtension(D_xk1_8003A598.extension, "CRSE");
            gCourseEditContext.state = 0x14;
        }
    }
    mfsStrCpy(gCourseEditCourseTitleEncStr, name);
    mfsStrCpy(D_8003006C, name);
    return 0;
}

s32 func_xk2_800EAC28(u8* name) {
    if (D_xk2_800F7408.courseData.flag != 0) {
        mfsStrCpy(D_xk1_8003A598.name, name);
        CourseEdit_WriteExtension(D_xk1_8003A598.extension, "CRSD");
        gCourseEditContext.state = 0x14;
    } else {
        mfsStrCpy(D_xk1_8003A598.name, name);
        CourseEdit_WriteExtension(D_xk1_8003A598.extension, "CRSE");
        gCourseEditContext.state = 0x14;
    }
    return 0;
}

extern s32 D_80119880;
extern volatile u8 D_80794E10;
extern s32 gCourseEditMiniMachineCharacter;
extern s32 gCourseEditMiniMachineColorPalette;
extern CourseSegment D_802D0620[];
extern s32 gVenueOption;
extern s32 gSkyboxOption;
extern s32 gBGMOption;
extern s32 gBGMOptionToCourseBGM[];
extern MenuWidget gVenueWidget;
extern s32 D_xk2_800F7040;

void func_xk2_800EACB0(void) {
    CourseInfo* courseInfo;
    s32 i;

    D_80794E10 = 0;
    D_xk2_800F7400 = 0xFF;
    if (D_80119880 == 7) {
        return;
    }
    if (D_80119880 == 0) {
        *COURSE_CONTEXT() = D_xk2_800F7408;
    }
    if ((Course_CalculateChecksum() != COURSE_CONTEXT()->courseData.checksum) ||
        (COURSE_CONTEXT()->courseData.creatorId != CREATOR_NINTENDO) ||
        (COURSE_CONTEXT()->courseData.bgm > BGM_NEW_04)) {
        PRINTF("COURSE DATA CHECK SUM ERROR 0x%x(DATA WAS BROKEN 0x%x)\n");
        func_xk2_800EE664(0xA);
        func_xk2_800EF8B0();
        return;
    }
    PRINTF("CHECK SUM IS OK 0x%x\n", COURSE_CONTEXT()->courseData.checksum);
    PRINTF("UNPACK BEFORE\n");
    PRINTF("UNPACK AFTER\n");
    PRINTF("LOAD TYPE %c%c%c%c\n");
    PRINTF("WAIT GET FILE NAMES\n");

    gVenueWidget.highlightedIndex = gVenueOption = COURSE_CONTEXT()->courseData.venue;
    gSkyboxOption = COURSE_CONTEXT()->courseData.skybox;
    gBGMOption = gBGMOptionToCourseBGM[COURSE_CONTEXT()->courseData.bgm];
    func_80077AD8(COURSE_CONTEXT()->courseData.venue);
    func_800747EC(gVenueOption);
    func_80074428(0);

    courseInfo = &gCourseInfos[0];
    D_802CB6D0.controlPointCount = courseInfo->segmentCount;
    for (i = 0; i < courseInfo->segmentCount; i++) {
        D_802CB6D0.segments[i] = D_802D0620[i];
        D_802CB6D0.segments[i].segmentIndex = i;
        D_802CB6D0.segments[i].next = &D_802CB6D0.segments[i + 1];
        D_802CB6D0.segments[i].prev = &D_802CB6D0.segments[i - 1];
    }

    gCourseEditContext.selectedControlPoint = 0;
    D_802CB6D0.segments[0].prev = &D_802CB6D0.segments[courseInfo->segmentCount - 1];
    D_802CB6D0.segments[courseInfo->segmentCount - 1].next = &D_802CB6D0.segments[0];
    CourseEdit_ClearSegmentSplitSelection();
    func_xk2_800EF78C();
    func_xk2_800F0FE8();
    D_xk2_800F7040 = 3;
    gCourseEditMiniMachineCharacter = Math_Rand2() % 30;
    gCourseEditMiniMachineColorPalette = Math_Rand2() % 4;
    D_xk2_800F7404 = 1;
}

extern EKLoadedFile gExpansionKitLoadedFiles[];
extern s32 gCourseEditSelectedFileIndex;

s32 CourseEdit_LoadCourseAndName(EKLoadedFile* file) {
    D_80794E10 = 0;
    D_xk2_800F7400 = 0;
    func_80768574(MFS_ENTRY_WORKING_DIR, file->name, &gExpansionKitLoadedFiles[gCourseEditSelectedFileIndex].extension,
                  &D_xk2_800F7408, sizeof(CourseContext));
    mfsStrCpy(gCourseEditCourseTitleEncStr, file->name);
    return 0;
}

s32 CourseEdit_LoadCourse(EKLoadedFile* file) {
    D_80794E10 = 0;
    D_xk2_800F7400 = 0;
    func_80768574(MFS_ENTRY_WORKING_DIR, file->name, &gExpansionKitLoadedFiles[gCourseEditSelectedFileIndex].extension,
                  &D_xk2_800F7408, sizeof(CourseContext));
    return 0;
}

extern s32 gCourseEditFileOption;
extern s32 gCourseEditEntryOption;
extern bool D_xk1_80032BF8;
extern s32 D_xk2_800F684C;
extern s32 gCourseEditMenuCursorXPos;
extern s32 gCourseEditMenuCursorYPos;

void CourseEdit_SetupFileMenu(void) {
    s32 pad;
    //  デフォルト
    u8 defaultEncStr[9] = { 0x20, 0x8E, 0xCC, 0xAB, 0xD9, 0xC4, 0x00, 0x00, 0x00 };

    if (D_xk1_80032BF8 && (D_xk2_800F7400 == 1)) {
        D_xk1_80032BF8 = false;
        D_xk2_800F7400 = 0xFF;
        if ((EKFileMenu_GetFileCount() == 0) && (D_80119880 != 1)) {
            gCourseEditFileOption = -1;
            gCourseEditEntryOption = -1;
            gCourseEditContext.state = 0;
            return;
        }
        gCourseEditContext.state = COURSE_EDIT_IN_FILE_MENU;
        switch (D_80119880) {
            case 0:
                mfsStrCpy(gExpansionKitLoadedFiles[0].name, "OFFICIAL");
                mfsStrCpy(gExpansionKitLoadedFiles[0].extension, "CRSD");
                EKFileMenu_InitFileMenu(168, 104, &gCourseEditMenuCursorXPos, &gCourseEditMenuCursorYPos);
                D_xk2_800F684C = 0;
                break;
            case 1:
                mfsStrCpy(gExpansionKitLoadedFiles[0].name, "NEWFILE");
                mfsStrCpy(gExpansionKitLoadedFiles[0].extension, "CRSD");
                PRINTF("EDIT_MODE_COURSE 08\n");
                PRINTF("EDIT_MODE_COURSE 09\n");
                PRINTF("EDIT_MODE_FILE_LOADING 0\n");
                PRINTF("EDIT_MODE_COURSE 11\n");
                EKFileMenu_InitFileMenu(168, 104, &gCourseEditMenuCursorXPos, &gCourseEditMenuCursorYPos);
                D_xk2_800F684C = 0;
                break;
            case 5:
                EKFileMenu_InitFileMenu(216, 104, &gCourseEditMenuCursorXPos, &gCourseEditMenuCursorYPos);
                D_xk2_800F684C = 0;
                break;
            case 7:
                EKFileMenu_InitFileMenu(168, 104, &gCourseEditMenuCursorXPos, &gCourseEditMenuCursorYPos);
                D_xk2_800F684C = 0;
                break;
            default:
                D_xk2_800F684C = 0;
                EKFileMenu_InitFileMenu(168, 104, &gCourseEditMenuCursorXPos, &gCourseEditMenuCursorYPos);
                break;
        }
    }
}

void func_xk2_800EB20C(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        gExpansionKitLoadedFiles[i].unk_1C = '0';
        gExpansionKitLoadedFiles[i].extension[4] = '0';
    }
}

void func_xk2_800EB250(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        COURSE_CONTEXT()->courseData.pit[i] = PIT_NONE;
        COURSE_CONTEXT()->courseData.dash[i] = DASH_NONE;
        COURSE_CONTEXT()->courseData.dirt[i] = DIRT_NONE;
        COURSE_CONTEXT()->courseData.ice[i] = ICE_NONE;
        COURSE_CONTEXT()->courseData.jump[i] = JUMP_NONE;
        COURSE_CONTEXT()->courseData.landmine[i] = LANDMINE_NONE;
        COURSE_CONTEXT()->courseData.gate[i] = GATE_NONE;
        COURSE_CONTEXT()->courseData.building[i] = BUILDING_NONE;
        COURSE_CONTEXT()->courseData.sign[i] = SIGN_NONE;
    }
}

void CourseEdit_ToggleFileForbidWriteAttr(char* name, s32 attr) {
    if (attr & MFS_FILE_ATTR_FORBID_W) {
        func_807689BC(MFS_ENTRY_WORKING_DIR, name, &gExpansionKitLoadedFiles[gCourseEditSelectedFileIndex].extension, 0,
                      MFS_FILE_ATTR_FORBID_W, true);
    } else {
        func_807689BC(MFS_ENTRY_WORKING_DIR, name, &gExpansionKitLoadedFiles[gCourseEditSelectedFileIndex].extension,
                      MFS_FILE_ATTR_FORBID_W, 0, true);
    }
}

void CourseEdit_FileMenuHandleBPress(void) {
    if (gCourseEditContext.state != COURSE_EDIT_IN_FILE_MENU) {
        return;
    }
    func_xk1_8002BD34();
    gCourseEditContext.state = 0;
    gCourseEditFileOption = -1;
    gCourseEditEntryOption = -1;
}

extern u8 gExpansionKitNameEntryStr[];
extern s32 gCourseEditCourseRegisterIndex;
extern s32 D_xk2_80104378;
extern s32 gCourseEditSelectedFileIndex;
extern char gEditCupTrackNames[][9];

void CourseEdit_FileMenuHandleAPress(void) {
    s32 fileIndex;
    EKLoadedFile* file;

    if (gCourseEditContext.state != COURSE_EDIT_IN_FILE_MENU) {
        return;
    }
    Audio_TriggerSystemSE(NA_SE_36);
    fileIndex = EKFileMenu_GetFileIndex();
    gCourseEditSelectedFileIndex = fileIndex;
    file = &gExpansionKitLoadedFiles[gCourseEditSelectedFileIndex];
    switch (D_80119880) {
        case 6:
            if (D_802CB6D0.controlPointCount == 0) {
                CourseEdit_ClearControlPointHighlight();
                if (fileIndex >= COURSE_EDIT_1) {
                    Course_Load(fileIndex + 6);
                } else {
                    Course_Load(fileIndex);
                }
                gCourseEditCourseTitleEncStr[0] = '\0';
                func_xk2_800EACB0();
                gCourseEditFileOption = -1;
                gCourseEditContext.state = 0;
                D_xk2_800F7040 = 3;
                gCourseEditMiniMachineCharacter = Math_Rand2() % 30;
                gCourseEditMiniMachineColorPalette = Math_Rand2() % 4;
            } else {
                D_xk2_80104378 = 1;
                gExpansionKitYesNoOptionIndex = 0;
                gCourseEditContext.state = 0x10;
            }
            break;
        case 8:
            Course_Load(fileIndex);
            func_xk2_800EACB0();
            gCourseEditFileOption = -1;
            gCourseEditContext.state = 0x30;
            D_80119880 = 7;
            D_xk2_800F7040 = 3;
            gCourseEditMiniMachineCharacter = Math_Rand2() % 30;
            gCourseEditMiniMachineColorPalette = Math_Rand2() % 4;
            break;
        case 0:
            if (fileIndex == 0) {
                EKFileMenu_LoadOfficialCourseList();
                D_80119880 = 6;
            } else if (D_802CB6D0.controlPointCount == 0) {
                CourseEdit_ClearControlPointHighlight();
                CourseEdit_LoadCourseAndName(&gExpansionKitLoadedFiles[fileIndex]);
                gCourseEditFileOption = -1;
                gCourseEditContext.state = 0x13;
            } else {
                D_xk2_80104378 = 1;
                gExpansionKitYesNoOptionIndex = 0;
                gCourseEditContext.state = 0x10;
            }
            break;
        case 1:
            if (fileIndex == 0) {
                D_80119880 = -1;
                if ((EKFileMenu_GetFileCount() - 1) >= 100) {
                    D_xk2_80104378 = 6;
                    gExpansionKitYesNoOptionIndex = 0;
                    gCourseEditContext.state = 0x10;
                } else {
                    ExpansionKit_NameEntryClear();
                    ExpansionKit_NameEntryInit(ExpansionKit_CourseEditNameEntryCallback);
                    gCourseEditMenuCursorXPos = 88;
                    gCourseEditMenuCursorYPos = 104;
                    gCourseEditContext.state = COURSE_EDIT_NAME_ENTRY;
                }
            } else {
                if (gExpansionKitLoadedFiles[fileIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                    D_xk2_80104378 = 8;
                    gExpansionKitYesNoOptionIndex = 0;
                    gCourseEditContext.state = 0x10;
                } else {
                    D_xk2_80104378 = 2;
                    gExpansionKitYesNoOptionIndex = 0;
                    gCourseEditContext.state = 0x10;
                }
            }
            break;
        case 3:
            D_xk1_8003A598 = *file;
            if (gExpansionKitLoadedFiles[fileIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                D_xk2_80104378 = 8;
                gExpansionKitYesNoOptionIndex = 0;
                gCourseEditContext.state = 0x10;
            } else {
                ExpansionKit_NameEntryClear();
                ExpansionKit_NameEntryInit(ExpansionKit_CourseEditNameEntryCallback);
                gCourseEditMenuCursorXPos = 88;
                gCourseEditMenuCursorYPos = 104;
                gCourseEditContext.state = COURSE_EDIT_NAME_ENTRY;
            }
            break;
        case 2:
            if (gExpansionKitLoadedFiles[fileIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                D_xk2_80104378 = 8;
                gExpansionKitYesNoOptionIndex = 0;
                gCourseEditContext.state = 0x10;
            } else {
                D_xk2_80104378 = 3;
                gExpansionKitYesNoOptionIndex = 0;
                gCourseEditContext.state = 0x10;
            }
            break;
        case 4:
            CourseEdit_ToggleFileForbidWriteAttr(gExpansionKitLoadedFiles[fileIndex].name, gExpansionKitLoadedFiles[fileIndex].attr);
            gCourseEditFileOption = -1;
            gCourseEditContext.state = 0;
            break;
        case 5:
            if (gExpansionKitLoadedFiles[gCourseEditSelectedFileIndex].extension[3] == 'E') {
                Audio_TriggerSystemSE(NA_SE_32);
                EKFileMenu_EnableFileMenuDraw();
            } else {
                mfsStrCpy(gEditCupTrackNames[gCourseEditCourseRegisterIndex], gExpansionKitLoadedFiles[fileIndex].name);
                func_xk2_800EC110();
                gCourseEditContext.state = 0x37;
            }
            break;
        case 7:
            ExpansionKit_NameEntryClear();
            mfsStrCpy(gExpansionKitNameEntryStr, gExpansionKitLoadedFiles[fileIndex].name);
            CourseEdit_LoadCourse(&gExpansionKitLoadedFiles[fileIndex]);
            gCourseEditFileOption = -1;
            gCourseEditContext.state = 0x33;
            break;
        default:
            break;
    }
}

void func_xk2_800EB938(u16 dirId, char* name, char* extension, u8* buf, u32 fileSize, s32 attr, s32 copyCount,
                       bool writeChanges) {
    if (extension[3] == 'D') {
        SLMFSDeleteFile(dirId, name, "CRSE", writeChanges);
    } else {
        SLMFSDeleteFile(dirId, name, "CRSD", writeChanges);
    }
    SLMFSSave(dirId, name, extension, buf, fileSize, attr, copyCount, writeChanges);
}
