#include "global.h"
#include "leo/mfs.h"
#include "fzx_save.h"
#include "fzx_course.h"

u8 D_xk2_800F7400 = 255;
s32 D_xk2_800F7404 = 0;
CourseContext D_xk2_800F7408 = {
    { CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } },
    { 0 },
    { 0 }
};

void func_xk2_800EA9B0(s8* arg0, s8* arg1) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
    arg0[4] = arg1[4];
}

extern s32 gMfsError;

void func_xk2_800EA9DC(char* errorMessage) {
    if (gMfsError < 0x2A) {
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

extern u8 D_80030060[];
extern u8 D_8003006C[];
extern s32 D_80119880;
extern unk_8003A5D8 D_xk1_8003A598;
extern s32 D_xk2_80104378;
extern unk_800D6CA0 D_800D6CA0;
extern s32 D_xk1_80032C20;
extern unk_807B3C20 D_802CB6D0;

s32 func_xk2_800EAA1C(u8* arg0) {
    SaveCourseRecords* courseRecords = &COURSE_CONTEXT()->saveCourseRecord;
    GhostSave* ghostSave;
    s32 i;
    u32 sp18;

    if ((func_xk1_8002BFA4() > 100) && (D_80119880 == -1)) {
        D_xk2_80104378 = 6;
        D_xk1_80032C20 = 0;
        D_800D6CA0.unk_08 = 0x10;
        return -1;
    }
    COURSE_CONTEXT()->courseData.creatorId = CREATOR_NINTENDO;
    COURSE_CONTEXT()->courseData.controlPointCount = D_802CB6D0.controlPointCount;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        COURSE_CONTEXT()->courseData.controlPoint[i].pos = D_802CB6D0.unk_0000[i].pos;
        COURSE_CONTEXT()->courseData.controlPoint[i].radiusLeft = D_802CB6D0.unk_0000[i].radiusLeft;
        COURSE_CONTEXT()->courseData.controlPoint[i].radiusRight = D_802CB6D0.unk_0000[i].radiusRight;
        COURSE_CONTEXT()->courseData.controlPoint[i].trackSegmentInfo = D_802CB6D0.unk_0000[i].trackSegmentInfo;
    }
    sp18 = Course_CalculateChecksum();
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
    COURSE_CONTEXT()->courseData.checksum = sp18;
    if ((D_80119880 == -1) || (D_80119880 == 1)) {
        if (COURSE_CONTEXT()->courseData.flag != 0) {
            mfsStrCpy(D_xk1_8003A598.name, arg0);
            func_xk2_800EA9B0(D_xk1_8003A598.extension, "CRSD");
            D_800D6CA0.unk_08 = 0x14;
        } else {
            mfsStrCpy(D_xk1_8003A598.name, arg0);
            func_xk2_800EA9B0(D_xk1_8003A598.extension, "CRSE");
            D_800D6CA0.unk_08 = 0x14;
        }
    }
    mfsStrCpy(D_80030060, arg0);
    mfsStrCpy(D_8003006C, arg0);
    return 0;
}

s32 func_xk2_800EAC28(u8* arg0) {
    if (D_xk2_800F7408.courseData.flag != 0) {
        mfsStrCpy(&D_xk1_8003A598, arg0);
        func_xk2_800EA9B0(D_xk1_8003A598.extension, "CRSD");
        D_800D6CA0.unk_08 = 0x14;
    } else {
        mfsStrCpy(&D_xk1_8003A598, arg0);
        func_xk2_800EA9B0(D_xk1_8003A598.extension, "CRSE");
        D_800D6CA0.unk_08 = 0x14;
    }
    return 0;
}

extern s32 D_80119880;
extern volatile u8 D_80794E10;
extern s32 D_xk2_800F7060;
extern s32 D_xk2_800F7064;
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
        D_802CB6D0.unk_0000[i] = D_802D0620[i];
        D_802CB6D0.unk_0000[i].segmentIndex = i;
        D_802CB6D0.unk_0000[i].next = &D_802CB6D0.unk_0000[i + 1];
        D_802CB6D0.unk_0000[i].prev = &D_802CB6D0.unk_0000[i - 1];
    }

    D_800D6CA0.unk_0C = 0;
    D_802CB6D0.unk_0000[0].prev = &D_802CB6D0.unk_0000[courseInfo->segmentCount - 1];
    D_802CB6D0.unk_0000[courseInfo->segmentCount - 1].next = &D_802CB6D0.unk_0000[0];
    func_xk2_800DC3F8();
    func_xk2_800EF78C();
    func_xk2_800F0FE8();
    D_xk2_800F7040 = 3;
    D_xk2_800F7060 = Math_Rand2() % 30;
    D_xk2_800F7064 = Math_Rand2() & 3;
    D_xk2_800F7404 = 1;
}

extern unk_8003A5D8 D_xk1_8003A5D8[];
extern s32 D_xk2_80119884;

s32 func_xk2_800EAF24(unk_8003A5D8* arg0) {
    D_80794E10 = 0;
    D_xk2_800F7400 = 0;
    func_80768574(MFS_ENTRY_WORKING_DIR, arg0->name, &D_xk1_8003A5D8[D_xk2_80119884].extension, &D_xk2_800F7408,
                  sizeof(CourseContext));
    mfsStrCpy(&D_80030060, arg0);
    return 0;
}

s32 func_xk2_800EAFA8(unk_8003A5D8* arg0) {
    D_80794E10 = 0;
    D_xk2_800F7400 = 0;
    func_80768574(MFS_ENTRY_WORKING_DIR, arg0->name, &D_xk1_8003A5D8[D_xk2_80119884].extension, &D_xk2_800F7408,
                  sizeof(CourseContext));
    return 0;
}

extern s32 gCourseEditFileOption;
extern s32 gCourseEditEntryOption;
extern s32 D_xk1_80032BF8;
extern s32 D_xk2_800F684C;
extern s32 D_xk1_8003A550;
extern s32 D_xk1_8003A554;

void func_xk2_800EB018(void) {
    s32 pad;
    u8 sp20[9] = { 0x20, 0x8E, 0xCC, 0xAB, 0xD9, 0xC4, 0x00, 0x00, 0x00 };

    if ((D_xk1_80032BF8 != 0) && (D_xk2_800F7400 == 1)) {
        D_xk1_80032BF8 = 0;
        D_xk2_800F7400 = 0xFF;
        if ((func_xk1_8002BFA4() == 0) && (D_80119880 != 1)) {
            gCourseEditFileOption = -1;
            gCourseEditEntryOption = -1;
            D_800D6CA0.unk_08 = 0;
            return;
        }
        D_800D6CA0.unk_08 = 3;
        switch (D_80119880) {
            case 0:
                mfsStrCpy(D_xk1_8003A5D8[0].name, "OFFICIAL");
                mfsStrCpy(D_xk1_8003A5D8[0].extension, "CRSD");
                func_xk1_8002B150(0xA8, 0x68, &D_xk1_8003A550, &D_xk1_8003A554);
                D_xk2_800F684C = 0;
                break;
            case 1:
                mfsStrCpy(D_xk1_8003A5D8[0].name, "NEWFILE");
                mfsStrCpy(D_xk1_8003A5D8[0].extension, "CRSD");
                PRINTF("EDIT_MODE_COURSE 08\n");
                PRINTF("EDIT_MODE_COURSE 09\n");
                PRINTF("EDIT_MODE_FILE_LOADING 0\n");
                PRINTF("EDIT_MODE_COURSE 11\n");
                func_xk1_8002B150(0xA8, 0x68, &D_xk1_8003A550, &D_xk1_8003A554);
                D_xk2_800F684C = 0;
                break;
            case 5:
                func_xk1_8002B150(0xD8, 0x68, &D_xk1_8003A550, &D_xk1_8003A554);
                D_xk2_800F684C = 0;
                break;
            case 7:
                func_xk1_8002B150(0xA8, 0x68, &D_xk1_8003A550, &D_xk1_8003A554);
                D_xk2_800F684C = 0;
                break;
            default:
                D_xk2_800F684C = 0;
                func_xk1_8002B150(0xA8, 0x68, &D_xk1_8003A550, &D_xk1_8003A554);
                break;
        }
    }
}

void func_xk2_800EB20C(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        D_xk1_8003A5D8[i].unk_1C = '0';
        D_xk1_8003A5D8[i].extension[4] = '0';
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

void func_xk2_800EB304(char* name, s32 attr) {
    if (attr & MFS_FILE_ATTR_FORBID_W) {
        func_807689BC(MFS_ENTRY_WORKING_DIR, name, &D_xk1_8003A5D8[D_xk2_80119884].extension, 0, MFS_FILE_ATTR_FORBID_W,
                      true);
    } else {
        func_807689BC(MFS_ENTRY_WORKING_DIR, name, &D_xk1_8003A5D8[D_xk2_80119884].extension, MFS_FILE_ATTR_FORBID_W, 0,
                      true);
    }
}

void func_xk2_800EB3B4(void) {
    if (D_800D6CA0.unk_08 != 3) {
        return;
    }
    func_xk1_8002BD34();
    D_800D6CA0.unk_08 = 0;
    gCourseEditFileOption = -1;
    gCourseEditEntryOption = -1;
}

extern u8 gExpansionKitNameEntryStr[];
extern s32 D_xk2_80103F10;
extern s32 D_xk2_80104378;
extern s32 D_xk2_80119884;
extern char gEditCupTrackNames[][9];

void func_xk2_800EB400(void) {
    s32 courseIndex;
    unk_8003A5D8* temp_v1;

    if (D_800D6CA0.unk_08 != 3) {
        return;
    }
    Audio_TriggerSystemSE(NA_SE_36);
    courseIndex = func_xk1_8002BD14();
    D_xk2_80119884 = courseIndex;
    temp_v1 = &D_xk1_8003A5D8[D_xk2_80119884];
    switch (D_80119880) {
        case 6:
            if (D_802CB6D0.controlPointCount == 0) {
                func_xk2_800F5C50();
                if (courseIndex >= COURSE_EDIT_1) {
                    Course_Load(courseIndex + 6);
                } else {
                    Course_Load(courseIndex);
                }
                D_80030060[0] = 0;
                func_xk2_800EACB0();
                gCourseEditFileOption = -1;
                D_800D6CA0.unk_08 = 0;
                D_xk2_800F7040 = 3;
                D_xk2_800F7060 = Math_Rand2() % 30;
                D_xk2_800F7064 = Math_Rand2() % 4;
            } else {
                D_xk2_80104378 = 1;
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
            }
            break;
        case 8:
            Course_Load(courseIndex);
            func_xk2_800EACB0();
            gCourseEditFileOption = -1;
            D_800D6CA0.unk_08 = 0x30;
            D_80119880 = 7;
            D_xk2_800F7040 = 3;
            D_xk2_800F7060 = Math_Rand2() % 30;
            D_xk2_800F7064 = Math_Rand2() % 4;
            break;
        case 0:
            if (courseIndex == 0) {
                func_xk1_8002D16C();
                D_80119880 = 6;
            } else if (D_802CB6D0.controlPointCount == 0) {
                func_xk2_800F5C50();
                func_xk2_800EAF24(&D_xk1_8003A5D8[courseIndex]);
                gCourseEditFileOption = -1;
                D_800D6CA0.unk_08 = 0x13;
            } else {
                D_xk2_80104378 = 1;
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
            }
            break;
        case 1:
            if (courseIndex == 0) {
                D_80119880 = -1;
                if ((func_xk1_8002BFA4() - 1) >= 100) {
                    D_xk2_80104378 = 6;
                    D_xk1_80032C20 = 0;
                    D_800D6CA0.unk_08 = 0x10;
                } else {
                    func_xk1_800294AC();
                    ExpansionKit_NameEntryInit(func_xk1_8002AC24);
                    D_xk1_8003A550 = 0x58;
                    D_xk1_8003A554 = 0x68;
                    D_800D6CA0.unk_08 = 2;
                }
            } else {
                if (D_xk1_8003A5D8[courseIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                    D_xk2_80104378 = 8;
                    D_xk1_80032C20 = 0;
                    D_800D6CA0.unk_08 = 0x10;
                } else {
                    D_xk2_80104378 = 2;
                    D_xk1_80032C20 = 0;
                    D_800D6CA0.unk_08 = 0x10;
                }
            }
            break;
        case 3:

            D_xk1_8003A598 = *temp_v1;
            if (D_xk1_8003A5D8[courseIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                D_xk2_80104378 = 8;
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
            } else {
                func_xk1_800294AC();
                ExpansionKit_NameEntryInit(func_xk1_8002AC24);
                D_xk1_8003A550 = 0x58;
                D_xk1_8003A554 = 0x68;
                D_800D6CA0.unk_08 = 2;
            }
            break;
        case 2:
            if (D_xk1_8003A5D8[courseIndex].attr & MFS_FILE_ATTR_FORBID_W) {
                D_xk2_80104378 = 8;
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
            } else {
                D_xk2_80104378 = 3;
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
            }
            break;
        case 4:
            func_xk2_800EB304(D_xk1_8003A5D8[courseIndex].name, D_xk1_8003A5D8[courseIndex].attr);
            gCourseEditFileOption = -1;
            D_800D6CA0.unk_08 = 0;
            break;
        case 5:
            if (D_xk1_8003A5D8[D_xk2_80119884].extension[3] == 'E') {
                Audio_TriggerSystemSE(NA_SE_32);
                func_xk1_8002D290();
                break;
            }
            mfsStrCpy(gEditCupTrackNames[D_xk2_80103F10], D_xk1_8003A5D8[courseIndex].name);
            func_xk2_800EC110();
            D_800D6CA0.unk_08 = 0x37;
            break;
        case 7:
            func_xk1_800294AC();
            mfsStrCpy(gExpansionKitNameEntryStr, D_xk1_8003A5D8[courseIndex].name);
            func_xk2_800EAFA8(D_xk1_8003A5D8[courseIndex].name);
            gCourseEditFileOption = -1;
            D_800D6CA0.unk_08 = 0x33;
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
