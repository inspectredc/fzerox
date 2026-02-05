#include "global.h"
#include "leo/mfs.h"
#include "fzx_course.h"
#include "fzx_save.h"
#include "segment_symbols.h"

char sDDSaveGhostFileName[] = "GHOST00";

extern OSMesgQueue gMFSMesgQ;
extern u8 gEditCupTrackNames[][9];

void DDSave_LoadCourseGhostRecords(s32 courseIndex, GhostRecord* ghostRecord) {
    s32 i;
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;
    SaveCourseRecords* courseRecords = &COURSE_CONTEXT()->saveCourseRecord;

    PRINTF("Load Ghost Info\n");
    PRINTF("Load Ghost Info2\n");
    PRINTF("idCourse info %d\n");
    PRINTF("machine No %d\n");

    sDDSaveGhostFileName[5] = (courseIndex / 10) + '0';
    sDDSaveGhostFileName[6] = (courseIndex % 10) + '0';
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6) &&
        gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
        for (i = 0; i < 3; i++, ghostRecord++, ghostSave++) {
            *ghostRecord = ghostSave->record;
        }
        return;
    }
    DDSave_ClearCachedGhostSaves();
    func_807684AC(MFS_ENTRY_WORKING_DIR, sDDSaveGhostFileName, "GOST", COURSE_CONTEXT()->ghostSave,
                  offsetof(CourseContext, ghostSave), 3 * sizeof(GhostSave) + sizeof(SaveCourseRecords));
    osRecvMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
    for (i = 0; i < 3; i++, ghostRecord++, ghostSave++) {
        PRINTF("Ghost Name %s\n");
        if (ghostSave->record.checksum != Save_CalculateGhostRecordChecksum(&ghostSave->record)) {
            PRINTF("GHOST_INFO_DATA_BROKEN\n");
            Save_ClearGhostRecord(&ghostSave->record);
            Save_ClearCourseRecord(courseRecords);
            PRINTF("ghost time %d:%d:%d\n");
            COURSE_CONTEXT()->courseData.fileName[0] = '\0';
        }
        *ghostRecord = ghostSave->record;
    }
}

void DDSave_LoadCachedCourseGhostRecords(s32 courseIndex, GhostRecord* ghostRecord) {
    s32 i;
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;
    SaveCourseRecords* courseRecords = &COURSE_CONTEXT()->saveCourseRecord;

    for (i = 0; i < 3; i++, ghostRecord++, ghostSave++) {
        if (ghostSave->record.checksum != Save_CalculateGhostRecordChecksum(&ghostSave->record)) {
            PRINTF("GHOST_INFO_DATA_BROKEN\n");
            Save_ClearGhostRecord(&ghostSave->record);
            Save_ClearCourseRecord(courseRecords);
        }
        *ghostRecord = ghostSave->record;
        PRINTF("ghost time %d:%d:%d\n");
    }
}

bool DDSave_ValidateCachedGhostRecords(void) {
    s32 i;
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;
    SaveCourseRecords* courseRecord = &COURSE_CONTEXT()->saveCourseRecord;

    for (i = 0; i < 3; i++, ghostSave++) {
        if (ghostSave->record.checksum != Save_CalculateGhostRecordChecksum(&ghostSave->record)) {
            PRINTF("GHOST_INFO_DATA_BROKEN\n");
            return true;
        }
    }

    if (courseRecord->checksum != Save_CalculateSaveCourseRecordChecksum(courseRecord)) {
        PRINTF("RECORD_DATA_BROKEN\n");
        return true;
    }
    return false;
}

void DDSave_LoadCourseGhostData(s32 courseIndex, s32 ghostIndex, GhostData* ghostData) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;

    PRINTF("Load Ghost Data\n");
    sDDSaveGhostFileName[5] = (courseIndex / 10) + '0';
    sDDSaveGhostFileName[6] = (courseIndex % 10) + '0';
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6) &&
        gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
        *ghostData = ghostSave[ghostIndex].data;
        return;
    }
    DDSave_ClearCachedGhostSaves();
    func_807684AC(MFS_ENTRY_WORKING_DIR, sDDSaveGhostFileName, "GOST", COURSE_CONTEXT()->ghostSave,
                  offsetof(CourseContext, ghostSave), 3 * sizeof(GhostSave));
    osRecvMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
    *ghostData = ghostSave[ghostIndex].data;
}

void DDSave_LoadCachedCourseGhostData(s32 courseIndex, s32 ghostIndex, GhostData* ghostData) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;

    *ghostData = ghostSave[ghostIndex].data;
}

extern CourseData D_i2_800D0130;

void DDSave_SaveGhost(s32 courseIndex, s32 ghostIndex, Ghost* ghost) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave + ghostIndex;

    sDDSaveGhostFileName[5] = (courseIndex / 10) + '0';
    sDDSaveGhostFileName[6] = (courseIndex % 10) + '0';
    COURSE_CONTEXT()->courseData = D_i2_800D0130;
    func_80707E58();
    if (ghost != NULL) {
        Save_SaveGhostRecord(ghost);
        Save_SaveGhostData(ghost);
    }
    *ghostSave = gSaveContext.ghostSave;

    func_807680EC(MFS_ENTRY_WORKING_DIR, sDDSaveGhostFileName, "GOST", COURSE_CONTEXT(), sizeof(CourseContext), 0, 0xFF,
                  true);
}

void DDSave_SaveGhostWithCustomSupport(s32 courseIndex, s32 ghostIndex, Ghost* ghost) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave + ghostIndex;

    sDDSaveGhostFileName[5] = (courseIndex / 10) + '0';
    sDDSaveGhostFileName[6] = (courseIndex % 10) + '0';

    COURSE_CONTEXT()->courseData = D_i2_800D0130;
    if (ghost != NULL) {
        Save_SaveGhostRecord(ghost);
        Save_SaveGhostData(ghost);
    }
    *ghostSave = gSaveContext.ghostSave;
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6)) {
        if (gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
            func_807680EC(MFS_ENTRY_WORKING_DIR, gEditCupTrackNames[courseIndex - COURSE_EDIT_1], "CRSD",
                          COURSE_CONTEXT(), sizeof(CourseContext), 0, 0xFF, true);
            return;
        }
    }
    func_807680EC(MFS_ENTRY_WORKING_DIR, sDDSaveGhostFileName, "GOST", COURSE_CONTEXT(), sizeof(CourseContext), 0, 0xFF,
                  true);
}

void DDSave_EraseDiskGhostSave(s32 courseIndex) {
    GhostSave* ghostSave;

    PRINTF("ERASE DISK GHOST %d\n");

    sDDSaveGhostFileName[5] = (courseIndex / 10) + '0';
    sDDSaveGhostFileName[6] = (courseIndex % 10) + '0';

    ghostSave = COURSE_CONTEXT()->ghostSave;
    Save_ClearGhostRecord(&ghostSave->record);
    ghostSave++;
    Save_ClearGhostRecord(&ghostSave->record);
    ghostSave++;
    Save_ClearGhostRecord(&ghostSave->record);
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6)) {
        if (gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
            COURSE_CONTEXT()->courseData = D_i2_800D0130;
            func_807680EC(MFS_ENTRY_WORKING_DIR, gEditCupTrackNames[courseIndex - COURSE_EDIT_1], "CRSD",
                          COURSE_CONTEXT(), sizeof(CourseContext), 0, 0xFF, true);
            return;
        }
    }
    func_807680EC(MFS_ENTRY_WORKING_DIR, sDDSaveGhostFileName, "GOST", COURSE_CONTEXT(), sizeof(CourseContext), 0, 0xFF,
                  true);
}

void DDSave_EraseDiskCourseRecord(s32 courseIndex) {
    SaveCourseRecords* courseRecords = &COURSE_CONTEXT()->saveCourseRecord;

    sDDSaveGhostFileName[5] = (courseIndex / 10) + '0';
    sDDSaveGhostFileName[6] = (courseIndex % 10) + '0';

    Save_ClearCourseRecord(courseRecords);
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6)) {
        if (gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
            COURSE_CONTEXT()->courseData = D_i2_800D0130;
            func_807680EC(MFS_ENTRY_WORKING_DIR, gEditCupTrackNames[courseIndex - COURSE_EDIT_1], "CRSD",
                          COURSE_CONTEXT(), sizeof(CourseContext), 0, 0xFF, true);
            func_i2_800A8CE4(courseRecords, courseIndex);
            return;
        }
    }
    func_807680EC(MFS_ENTRY_WORKING_DIR, sDDSaveGhostFileName, "GOST", COURSE_CONTEXT(), sizeof(CourseContext), 0, 0xFF,
                  true);
    func_i2_800A8CE4(courseRecords, courseIndex);
}

void DDSave_ClearCachedGhostSaves(void) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;

    Save_ClearGhostRecord(&ghostSave->record);
    ghostSave++;
    Save_ClearGhostRecord(&ghostSave->record);
    ghostSave++;
    Save_ClearGhostRecord(&ghostSave->record);
}

SaveCourseRecords* DDSave_GetCachedCourseRecord(void) {
    return &COURSE_CONTEXT()->saveCourseRecord;
}

GhostSave* DDSave_GetCachedGhostSaves(void) {
    return COURSE_CONTEXT()->ghostSave;
}

void DDSave_SaveCourseGhost(s32 courseIndex) {

    COURSE_CONTEXT()->courseData = D_i2_800D0130;

    sDDSaveGhostFileName[5] = (courseIndex / 10) + '0';
    sDDSaveGhostFileName[6] = (courseIndex % 10) + '0';

    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6)) {
        if (gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
            func_807680EC(MFS_ENTRY_WORKING_DIR, gEditCupTrackNames[courseIndex - COURSE_EDIT_1], "CRSD",
                          COURSE_CONTEXT(), sizeof(CourseContext), 0, 0xFF, true);
            return;
        }
    }
    func_807680EC(MFS_ENTRY_WORKING_DIR, sDDSaveGhostFileName, "GOST", COURSE_CONTEXT(), sizeof(CourseContext), 0, 0xFF,
                  true);
}

void DDSave_LoadBaseCourses(void) {
    s32 courseIndex;
    s32 courseIndexToEncode;

    for (courseIndex = 0; courseIndex < COURSE_EDIT_1; courseIndex++) {
        if (courseIndex >= COURSE_EDIT_1) {
            courseIndexToEncode = COURSE_EDIT_1;
        } else {
            courseIndexToEncode = courseIndex;
        }
        Course_Load(courseIndex);

        PRINTF("=========================================\n");
        PRINTF("courseID 0x%X -> right data is 0x7B4113D8\n");
        PRINTF("=========================================\n");
        gCourseInfos[courseIndex].encodedCourseIndex = (Course_CalculateChecksum() << 5) | courseIndexToEncode;
    }
}

void DDSave_LoadCachedGhostRecord(s32 ghostIndex, GhostRecord* ghostRecord) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;

    if (1) {}
    *ghostRecord = ghostSave[ghostIndex].record;
}

void DDSave_LoadCachedGhostData(s32 ghostIndex, GhostData* ghostData) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;

    if (1) {}
    *ghostData = ghostSave[ghostIndex].data;
}

void DDSave_LoadDDCourseGhosts(s32 courseIndex) {

    courseIndex -= COURSE_SILENCE_3;
    if (courseIndex < 0) {
        courseIndex = 0;
    }
    DiskDrive_LoadData(SEGMENT_DISK_START(silence_3_staff_ghost) + courseIndex, COURSE_CONTEXT()->ghostSave,
                       3 * sizeof(GhostSave), 0);
}

void DDSave_EraseCourseGhostFile(s32 courseIndex) {
    GhostSave* ghostSave;

    sDDSaveGhostFileName[5] = (courseIndex / 10) + '0';
    sDDSaveGhostFileName[6] = (courseIndex % 10) + '0';

    PRINTF("STUFF GHOST IS READING BY REAL DISK\n");

    ghostSave = COURSE_CONTEXT()->ghostSave;
    Save_ClearGhostRecord(&ghostSave->record);
    ghostSave++;
    Save_ClearGhostRecord(&ghostSave->record);
    ghostSave++;
    Save_ClearGhostRecord(&ghostSave->record);
    func_80704050(true);
    PRINTF("ERASE DISK GHOST %d\n");
    SLMFSDeleteFile(MFS_ENTRY_WORKING_DIR, sDDSaveGhostFileName, "GOST", false);
    func_80704050(false);
}
