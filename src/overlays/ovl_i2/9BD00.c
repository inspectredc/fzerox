#include "global.h"
#include "fzx_game.h"
#include "fzx_save.h"
#include "ovl_i2.h"

OSIoMesg sSramIoMesg;
OSPiHandle sSramPiHandle;
OSPiHandle* gSramPiHandlePtr;
s16 gSettingSoundMode;
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

void func_i2_801033B8(CupSave*, u8*);
void func_i2_8010300C(GhostRecord*, GhostData*, Ghost*, bool);
void func_i2_80102F70(GhostRecord*, GhostData*, Ghost*, bool);
void func_i2_80102CA4(ProfileSave*, s32);
void Save_ClearData(void*, s32);

extern u8 gEditCupTrackNames[6][9];

extern SaveContext gSaveContext;

const char D_i2_8010ADE0[] = { 'F', '-', 'Z', 'E', 'R', 'O', ' ', 'X' };
const char D_i2_8010ADE8[] = { 'D', 'A', 'I', '&', 'E', 'A', 'D', '!' };

void Save_ReadGhostRecord(GhostRecord* ghostRecord) {
    Sram_ReadWrite(OS_READ, (uintptr_t) &gSaveContext.ghostRecord - (uintptr_t) &gSaveContext, ghostRecord,
                   sizeof(GhostRecord));
}

void Save_ReadGhostData(GhostData* ghostData) {
    Sram_ReadWrite(OS_READ, (uintptr_t) &gSaveContext.ghostData - (uintptr_t) &gSaveContext, ghostData,
                   sizeof(GhostData));
}

void Save_ReadCharacterSave(CharacterSave* characterSave, s32 courseIndex) {
    Sram_ReadWrite(OS_READ, (uintptr_t) &gSaveContext.characterSaves[courseIndex] - (uintptr_t) &gSaveContext,
                   characterSave, sizeof(CharacterSave));
}

void Save_ReadCupSave(CupSave* cupSave) {
    Sram_ReadWrite(OS_READ, (uintptr_t) &gSaveContext.cupSave - (uintptr_t) &gSaveContext, cupSave, sizeof(CupSave));
}

void Save_ReadProfileSaves(ProfileSave* profileSave) {
    s32 i;
    ProfileSave* outProfile;
    ProfileSave* savedProfile;

    for (savedProfile = gSaveContext.profileSaves, i = 0, outProfile = profileSave; i < 2 * sizeof(ProfileSave);
         i += sizeof(ProfileSave), savedProfile++, outProfile++) {
        Sram_ReadWrite(OS_READ, (uintptr_t) savedProfile - (uintptr_t) &gSaveContext, outProfile, sizeof(ProfileSave));
    }
}

extern Ghost gGhosts[];
extern s32 gCurrentGhostType;

s32 func_i2_80100810(s32, s32);
s32 func_i2_8010387C(s32);

s32 func_i2_80100520(s32 courseIndex) {
    s32 i;
    s32 sp18;
    s32 encodedCourseIndex = gCourseRecordInfos[courseIndex].encodedCourseIndex;
    Ghost* var_v0 = gGhosts;

    for (i = 0; i < 3; i++) {
        if (encodedCourseIndex != var_v0->encodedCourseIndex) {
            var_v0->encodedCourseIndex = 0;
        }
        var_v0++;
    }
    switch (gCurrentGhostType) {
        case GHOST_CELEBRITY:
        case GHOST_CHAMP:
            break;
        case GHOST_NONE:
        case GHOST_PLAYER:
            sp18 = func_i2_80100810(courseIndex, -1);
            break;
        case GHOST_STAFF:
            sp18 = func_i2_8010387C(courseIndex);
            break;
    }
    return sp18;
}

s32 func_i2_801005CC(s32 courseIndex) {
    s32 i;
    s32 var_a0;
    s32 var_v1;
    Ghost* var_a1;

    var_v1 = -1;

    for (i = 0, var_a1 = gGhosts; i < 3; i++, var_a1++) {
        if (var_a1->encodedCourseIndex == 0) {
            var_v1 = i;
            break;
        }
    }

    if (var_v1 != -1) {
        return var_v1;
    }

    for (i = 0, var_a1 = gGhosts; i < 3; i++, var_a1++) {
        if (var_a1->ghostType != GHOST_PLAYER) {
            var_v1 = i;
            break;
        }
    }

    var_a0 = -1;
    if (var_v1 != -1) {
        return var_v1;
    }

    for (i = 0, var_a1 = gGhosts; i < 3; i++, var_a1++) {
        if (courseIndex != (var_a1->encodedCourseIndex & 0x1F)) {
            var_v1 = i;
            var_a0 = var_a1->raceTime;
            break;
        }
    }

    if (var_a0 != -1) {
        for (i = var_v1 + 1, var_a1 = &gGhosts[i]; i < 3; i++, var_a1++) {
            if (courseIndex != (var_a1->encodedCourseIndex & 0x1F)) {
                if (var_a0 < var_a1->raceTime) {
                    var_a0 = var_a1->raceTime;
                    var_v1 = i;
                }
            }
        }
    } else {
        for (i = 0, var_a1 = gGhosts; i < 3; i++, var_a1++) {
            if (courseIndex == (var_a1->encodedCourseIndex & 0x1F)) {
                if (var_a0 < var_a1->raceTime) {
                    var_a0 = var_a1->raceTime;
                    var_v1 = i;
                }
            }
        }
    }
    return var_v1;
}

bool func_i2_80100B38(unk_80141C88*);
s32 func_i2_801005CC(s32);

s32 func_i2_80100810(s32 courseIndex, s32 arg1) {
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];
    s32 var_t0;
    s32 pad2[4];
    unk_80141C88 sp24;
    s32 temp_v0;

    temp_v0 = func_i2_801014D4(&sp24);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    if (sp24.courseIndex != courseIndex) {
        return 2;
    }

    if (func_i2_80100B38(&sp24)) {
        return 0;
    }
    if (arg1 == -1) {
        var_t0 = func_i2_801005CC(courseIndex);

        if ((gGhosts[var_t0].encodedCourseIndex != 0) && (gGhosts[var_t0].ghostType == GHOST_PLAYER) &&
            (sp24.courseIndex == (gGhosts[var_t0].encodedCourseIndex & 0x1F)) &&
            (gGhosts[var_t0].raceTime < sp24.raceTime)) {
            return 0;
        }
    } else {
        var_t0 = arg1;
    }

    Save_ReadGhostData(ghostData);
    func_i2_80102F70(ghostRecord, ghostData, &gGhosts[var_t0], true);
    func_i2_8010300C(ghostRecord, ghostData, &gGhosts[var_t0], true);

    return 0;
}

bool func_i2_80100950(CarInfo* carInfo, unk_80141C88_unk_1D* arg1) {
    bool matching = true;

    if (arg1->unk_00.unk_00[0] != carInfo->unk_00[0]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[1] != carInfo->unk_00[1]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[2] != carInfo->unk_00[2]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[3] != carInfo->unk_00[3]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[4] != carInfo->unk_00[4]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[5] != carInfo->unk_00[5]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[6] != carInfo->unk_00[6]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[7] != carInfo->unk_00[7]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[8] != carInfo->unk_00[8]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[9] != carInfo->unk_00[9]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[10] != carInfo->unk_00[10]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[11] != carInfo->unk_00[11]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[12] != carInfo->unk_00[12]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[13] != carInfo->unk_00[13]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[14] != carInfo->unk_00[14]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[15] != carInfo->unk_00[15]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[16] != carInfo->unk_00[16]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[17] != carInfo->unk_00[17]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[18] != carInfo->unk_00[18]) {
        matching = false;
    } else if (arg1->unk_00.unk_00[19] != carInfo->unk_00[19]) {
        matching = false;
    }
    return matching;
}

bool func_i2_80100B38(unk_80141C88* arg0) {
    s32 var_s1;
    s32 i;
    Ghost* var_s0 = gGhosts;

    for (i = 0; i < 3; i++) {
        var_s1 = true;
        if (var_s0->ghostType != arg0->ghostType) {
            var_s1 = false;
        } else if (var_s0->replayChecksum != arg0->replayChecksum) {
            var_s1 = false;
        } else if (var_s0->encodedCourseIndex != arg0->encodedCourseIndex) {
            var_s1 = false;
        } else if (var_s0->raceTime != arg0->raceTime) {
            var_s1 = false;
        } else if (!func_i2_80100950(&var_s0->carInfo, &arg0->unk_1D)) {
            var_s1 = false;
        }

        if (var_s1) {
            break;
        }
        var_s0++;
    }
    return var_s1;
}

void func_i2_80103310(CharacterSave*, s32);

s32 func_i2_80100C18(s32 courseIndex) {
    CharacterSave* characterSaves = (CharacterSave*) gSaveBuffer;

    Save_ReadCharacterSave(&characterSaves[courseIndex], courseIndex);
    func_i2_80103310(&characterSaves[courseIndex], courseIndex);
    return 0;
}

s32 func_i2_80100C60(u8* arg0) {
    CupSave* cupSave = (CupSave*) gSaveBuffer;

    Save_ReadCupSave(cupSave);
    func_i2_801033B8(cupSave, arg0);
    return 0;
}

s32 Save_CalculateSaveSettingsChecksum(ProfileSave*);
s32 Save_CalculateSaveDeathRaceChecksum(ProfileSave*);
s32 Save_CalculateSaveCourseRecordChecksum(ProfileSave*, s32);
s32 Save_CalculateSaveEditCupChecksum(ProfileSave*);
s32 Save_CalculateGhostRecordChecksum(GhostRecord*);
s32 Save_CalculateGhostDataChecksum(GhostData*);
s32 Save_CalculateCharacterSaveChecksum(CharacterSave*);
s32 Save_CalculateCupSaveChecksum(CupSave*);

void Save_InitWrite(SaveContext* saveContext) {
    s32 i;
    s32 j;
    s32 checksum;
    CharacterSave* characterSave;
    ProfileSave* profileSave;

    checksum = Save_CalculateSaveSettingsChecksum(saveContext->profileSaves);

    for (i = 0, profileSave = saveContext->profileSaves; i < 2; i++, profileSave++) {
        profileSave->saveSettings.checksum = checksum;
    }
    checksum = Save_CalculateSaveDeathRaceChecksum(saveContext->profileSaves);

    for (i = 0, profileSave = saveContext->profileSaves; i < 2; i++, profileSave++) {
        profileSave->deathRace.checksum = checksum;
    }

    for (j = 0; j < 24; j++) {
        checksum = Save_CalculateSaveCourseRecordChecksum(saveContext->profileSaves, j);

        for (i = 0, profileSave = saveContext->profileSaves; i < 2; i++, profileSave++) {
            profileSave->courses[j].checksum = checksum;
        }
    }
    checksum = Save_CalculateSaveEditCupChecksum(saveContext->profileSaves);

    for (i = 0, profileSave = saveContext->profileSaves; i < 2; i++, profileSave++) {
        profileSave->editCup.checksum = checksum;
    }
    saveContext->ghostRecord.checksum = Save_CalculateGhostRecordChecksum(&saveContext->ghostRecord);
    saveContext->ghostData.checksum = Save_CalculateGhostDataChecksum(&saveContext->ghostData);

    for (i = 0, characterSave = saveContext->characterSaves; i < 24; i++, characterSave++) {
        characterSave->checksum = Save_CalculateCharacterSaveChecksum(characterSave);
    }
    saveContext->cupSave.checksum = Save_CalculateCupSaveChecksum(&saveContext->cupSave);
    Sram_ReadWrite(OS_WRITE, 0, saveContext, sizeof(SaveContext));
}

void Save_WriteSaveSettings(ProfileSave* profileSaves, s32 profileIndex, u16 checksum) {
    ProfileSave* profileSave = &profileSaves[profileIndex];

    profileSave->saveSettings.checksum = checksum;
    Sram_ReadWrite(OS_WRITE,
                   (uintptr_t) &gSaveContext.profileSaves[profileIndex].saveSettings - (uintptr_t) &gSaveContext,
                   &profileSave->saveSettings, sizeof(SaveSettings));
}

void Save_WriteSaveDeathRace(ProfileSave* profileSaves, s32 profileIndex, u16 checksum) {
    ProfileSave* profileSave = &profileSaves[profileIndex];

    profileSave->deathRace.checksum = checksum;
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.profileSaves[profileIndex].deathRace - (uintptr_t) &gSaveContext,
                   &profileSave->deathRace, sizeof(SaveDeathRace));
}

void Save_WriteSaveCourseRecord(ProfileSave* profileSaves, s32 profileIndex, s32 courseIndex, u16 checksum) {
    ProfileSave* profileSave = &profileSaves[profileIndex];
    SaveCourseRecords* courseRecord = &profileSave->courses[courseIndex];

    courseRecord->checksum = checksum;
    Sram_ReadWrite(
        OS_WRITE, (uintptr_t) &gSaveContext.profileSaves[profileIndex].courses[courseIndex] - (uintptr_t) &gSaveContext,
        courseRecord, sizeof(SaveCourseRecords));
}

void Save_WriteSaveEditCup(ProfileSave* profileSaves, s32 profileIndex, u16 checksum) {
    ProfileSave* profileSave = &profileSaves[profileIndex];

    profileSave->editCup.checksum = checksum;
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.profileSaves[profileIndex].editCup - (uintptr_t) &gSaveContext,
                   &profileSave->editCup, sizeof(SaveEditCup));
}

void Save_WriteGhostRecord(GhostRecord* ghostRecord) {
    ghostRecord->checksum = Save_CalculateGhostRecordChecksum(ghostRecord);
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.ghostRecord - (uintptr_t) &gSaveContext, ghostRecord,
                   sizeof(GhostRecord));
}

void Save_WriteGhostData(GhostData* ghostData) {
    ghostData->checksum = Save_CalculateGhostDataChecksum(ghostData);
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.ghostData - (uintptr_t) &gSaveContext, ghostData,
                   sizeof(GhostData));
}

void Save_WriteCharacterSave(CharacterSave* characterSave, s32 courseIndex) {
    characterSave->checksum = Save_CalculateCharacterSaveChecksum(characterSave);
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.characterSaves[courseIndex] - (uintptr_t) &gSaveContext,
                   characterSave, sizeof(CharacterSave));
}

void Save_WriteCupSave(CupSave* cupSave) {
    cupSave->checksum = Save_CalculateCupSaveChecksum(cupSave);
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.cupSave - (uintptr_t) &gSaveContext, cupSave, sizeof(CupSave));
}

void func_i2_80102214(SaveCourseRecords*, s32);

s32 func_i2_80101118(s32 courseIndex) {
    u16 checksum;
    s32 i;
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;

    func_i2_80102214(&profileSaves[0].courses[courseIndex], courseIndex);
    profileSaves[1].courses[courseIndex] = profileSaves[0].courses[courseIndex];

    checksum = Save_CalculateSaveCourseRecordChecksum(profileSaves, courseIndex);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveCourseRecord(profileSaves, i, courseIndex, checksum);
    }

    return 0;
}

extern s32 gRamDDCompatible;
void func_i2_80102350(SaveEditCup*);

s32 func_i2_801011FC(void) {
    u16 checksum;
    s32 i;
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;

    if (!gRamDDCompatible) {
        return 3;
    }
    func_i2_80102350(&profileSaves[0].editCup);

    profileSaves[1].editCup = profileSaves[0].editCup;

    checksum = Save_CalculateSaveEditCupChecksum(profileSaves);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveEditCup(profileSaves, i, checksum);
    }

    return 0;
}

void func_i2_8010259C(CharacterSave*);

s32 func_i2_801012CC(s32 courseIndex) {
    s32 pad[2];
    CharacterSave* characterSaves = (CharacterSave*) gSaveBuffer;

    func_i2_8010259C(&characterSaves[courseIndex]);
    Save_WriteCharacterSave(&characterSaves[courseIndex], courseIndex);
    return 0;
}

s32 Save_UpdateCupCompletion(s32 difficulty, s32 cupType, s32 character) {
    s32 i;
    s32 cupCompletion;
    CupSave* cupSave = (CupSave*) gSaveBuffer;

    Save_ReadCupSave(cupSave);
    func_i2_801033B8(cupSave, NULL);

    cupCompletion = cupSave->cupCompletion[difficulty][character / 3];
    cupCompletion |= (1 << ((character % 3) * 5)) << cupType;

    cupSave->cupCompletion[difficulty][character / 3] = cupCompletion;

    // clang-format off
    for (i = 0; i < 14; i++) { \
        cupSave->unk_02[i] = 0;
    }
    // clang-format on

    Save_WriteCupSave(cupSave);

    return 0;
}

void func_i2_80101FEC(SaveSettings*);

s32 func_i2_80101414(void) {
    u16 checksum;
    s32 i;
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;

    func_i2_80101FEC(&profileSaves[0].saveSettings);
    profileSaves[1].saveSettings = profileSaves[0].saveSettings;

    checksum = Save_CalculateSaveSettingsChecksum(profileSaves);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveSettings(profileSaves, i, checksum);
    }

    return 0;
}

void func_i2_80101590(GhostRecord*, unk_80141C88*);
void func_i2_80101E68(GhostData*, bool);
void func_i2_80101DE8(GhostRecord*, bool);

s32 func_i2_801014D4(unk_80141C88* arg0) {
    s32 pad;
    s32 var_v1;
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    Save_ReadGhostRecord(ghostRecord);
    var_v1 = 0;

    if (ghostRecord->checksum != Save_CalculateGhostRecordChecksum(ghostRecord) * 1) {
        func_i2_80101DE8(ghostRecord, true);
        Save_WriteGhostRecord(ghostRecord);
        func_i2_80101E68(ghostData, true);
        Save_WriteGhostData(ghostData);
        var_v1 = 1;
    }

    if (arg0 != NULL) {
        func_i2_80101590(ghostRecord, arg0);
    }
    if ((var_v1 == 0) && (ghostRecord->encodedCourseIndex == 0)) {
        var_v1 = 2;
    }
    return var_v1;
}

void func_i2_80101590(GhostRecord* ghostRecord, unk_80141C88* arg1) {
    s32 i;

    arg1->courseIndex = ghostRecord->encodedCourseIndex & 0x1F;

    arg1->encodedCourseIndex = ghostRecord->encodedCourseIndex;
    arg1->raceTime = ghostRecord->raceTime;
    arg1->replayChecksum = ghostRecord->replayChecksum;
    arg1->ghostType = ghostRecord->ghostType;
    arg1->unk_12 = ghostRecord->unk_10;

    for (i = 0; i < 9; i++) {
        arg1->trackName[i] = ghostRecord->trackName[i];
    }
    arg1->unk_1D = ghostRecord->unk_20;
}

void func_i2_801023D8(Ghost*);
void func_i2_801024F8(Ghost*);

s32 func_i2_80101690(s32 courseIndex, Ghost* arg1) {
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    func_i2_801023D8(arg1);
    Save_WriteGhostRecord(ghostRecord);
    func_i2_801024F8(arg1);
    Save_WriteGhostData(ghostData);
    return 0;
}

void func_i2_801021B4(SaveDeathRace*);

s32 func_i2_801016DC(void) {
    u16 checksum;
    s32 i;
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;

    func_i2_801021B4(&profileSaves[0].deathRace);
    profileSaves[1].deathRace = profileSaves[0].deathRace;

    checksum = Save_CalculateSaveDeathRaceChecksum(profileSaves);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveDeathRace(profileSaves, i, checksum);
    }

    return 0;
}

void Save_Load(SaveContext*);
void Save_CreateNew(SaveContext*, s32);

s32 Save_Init(SaveContext* saveContext, s32 arg1) {
    Save_CreateNew(saveContext, arg1);
    Save_InitWrite(saveContext);
    Save_Load(saveContext);
    return 0;
}

void func_i2_80101D18(SaveCourseRecords*, bool);

s32 func_i2_801017B8(s32 courseIndex) {
    u16 checksum;
    s32 i;
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;

    func_i2_80101D18(&profileSaves[0].courses[courseIndex], true);
    profileSaves[1].courses[courseIndex] = profileSaves[0].courses[courseIndex];

    checksum = Save_CalculateSaveCourseRecordChecksum(profileSaves, courseIndex);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveCourseRecord(profileSaves, i, courseIndex, checksum);
    }

    func_i2_80102CA4(profileSaves, courseIndex);

    return 0;
}

s32 func_i2_801018A8(s32 courseIndex) {
    s32 i;
    Ghost* ghost;
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    for (i = 0, ghost = gGhosts; i < 3; i++, ghost++) {
        if (ghost->encodedCourseIndex == gCourseRecordInfos[courseIndex].encodedCourseIndex) {
            ghost->encodedCourseIndex = 0;
        }
    }
    func_i2_80101DE8(ghostRecord, true);
    Save_WriteGhostRecord(ghostRecord);
    func_i2_80101E68(ghostData, true);
    Save_WriteGhostData(ghostData);
    return 0;
}

void func_i2_80101B8C(SaveSettings*, bool);
void func_i2_80101C04(SaveEditCup*, bool);
void func_i2_80101CCC(SaveDeathRace*, bool);
void func_i2_80101E68(GhostData*, bool);
void func_i2_80101EBC(CharacterSave*, bool);
void func_i2_80102784(ProfileSave*, bool);
void func_i2_80103108(ProfileSave*, bool);

void Save_CreateNew(SaveContext* saveContext, s32 arg1) {
    s32 i;
    s32 j;
    u64* ptr;
    ProfileSave* profileSave;
    SaveCourseRecords* courseRecord;
    CharacterSave* characterSave;
    u8 spB7;
    SaveEditCup editCup;
    s32 pad;

    // Load current save and remember n64dd related data that will be restored
    if ((arg1 != 0) && (arg1 == 1)) {
        Save_ReadProfileSaves(saveContext->profileSaves);
        func_i2_80102784(saveContext->profileSaves, false);
        spB7 = saveContext->profileSaves[0].saveSettings.unk_09;
        func_i2_80103108(saveContext->profileSaves, false);
        editCup = saveContext->profileSaves[0].editCup;
    }

    for (i = 0, ptr = (u64*) saveContext; i < (s32) (sizeof(SaveContext) / sizeof(u64)); i++, ptr++) {
        *ptr = 0;
    }

    for (i = 0, profileSave = saveContext->profileSaves; i < 2; i++, profileSave++) {
        func_i2_80101B8C(&profileSave->saveSettings, false);
        func_i2_80101CCC(&profileSave->deathRace, false);

        for (j = 0, courseRecord = profileSave->courses; j < 24; j++, courseRecord++) {
            func_i2_80101D18(courseRecord, false);
        }

        func_i2_80101C04(&profileSave->editCup, false);
    }

    func_i2_80101DE8(&saveContext->ghostRecord, false);
    func_i2_80101E68(&saveContext->ghostData, false);

    for (i = 0, characterSave = saveContext->characterSaves; i < 24; i++, characterSave++) {
        func_i2_80101EBC(characterSave, false);
    }

    // Restore the n64dd related save data
    if ((arg1 != 0) && (arg1 == 1)) {
        saveContext->profileSaves[0].saveSettings.unk_09 = saveContext->profileSaves[1].saveSettings.unk_09 = spB7;
        saveContext->profileSaves[0].editCup = saveContext->profileSaves[1].editCup = editCup;
    }
}

void func_i2_80101B8C(SaveSettings* saveSettings, bool shouldClear) {
    s32 i;

    if (shouldClear) {
        Save_ClearData(saveSettings, sizeof(SaveSettings));
    }

    for (i = 0; i < 8; i++) {
        saveSettings->fileName[i] = D_i2_8010ADE0[i];
    }

    // clang-format off
    for (i = 0; i < 4; i++) { \
        saveSettings->cupDifficultiesCleared[i] = 0;
    }
    // clang-format on

    // vs com default on
    saveSettings->settings = 1;
    saveSettings->unk_09 = 0;
}

void func_i2_80101C04(SaveEditCup* editCup, bool shouldClear) {
    s32 i;
    s32 j;

    if (shouldClear) {
        Save_ClearData(editCup, sizeof(SaveEditCup));
    }

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 9; j++) {
            editCup->editCupTrackNames[i][j] = 0;
        }
    }
}

void func_i2_80101C78(unk_80141C88_unk_1D* arg0) {

    arg0->unk_00.unk_00[0] = 0;
    arg0->unk_00.unk_00[1] = 0;
    arg0->unk_00.unk_00[2] = 0;
    arg0->unk_00.unk_00[3] = 0;
    arg0->unk_00.unk_00[4] = 0;
    arg0->unk_00.unk_00[5] = 0;
    arg0->unk_00.unk_00[6] = 0;
    arg0->unk_00.unk_00[7] = 0;
    arg0->unk_00.unk_00[8] = 0;
    arg0->unk_00.unk_00[9] = 0;
    arg0->unk_00.unk_00[10] = 0;
    arg0->unk_00.unk_00[11] = 0;
    arg0->unk_00.unk_00[12] = 0;
    arg0->unk_00.unk_00[13] = 0;
    arg0->unk_00.unk_00[14] = 0;
    arg0->unk_00.unk_00[15] = 0;
    arg0->unk_00.unk_00[16] = 0;
    arg0->unk_00.unk_00[17] = 0;
    arg0->unk_00.unk_00[18] = 0;
    arg0->unk_00.unk_00[19] = 0;
}

void func_i2_80101CCC(SaveDeathRace* deathRace, bool shouldClear) {
    s32 i;

    if (shouldClear) {
        Save_ClearData(deathRace, sizeof(SaveDeathRace));
    }

    for (i = 0; i < 1; i++) {
        deathRace->timeRecord[i] = MAX_TIMER;
    }
}

void func_i2_80101D18(SaveCourseRecords* courseRecords, bool shouldClear) {
    s32 i;
    s32 j;

    if (shouldClear) {
        Save_ClearData(courseRecords, sizeof(SaveCourseRecords));
    }

    for (i = 0; i < 5; i++) {
        courseRecords->timeRecord[i] = MAX_TIMER;
        courseRecords->engine[i] = 0.5f;
        func_i2_80101C78(&courseRecords->unk_50[i]);
        // clang-format off
        for (j = 0; j < 4; j++) { \
            courseRecords->name[i][j] = '\0';
        }
        // clang-format on
    }

    courseRecords->maxSpeed = 0.0f;
    courseRecords->bestTime = MAX_TIMER;

    func_i2_80101C78(&courseRecords->unk_F0);
}

void func_i2_80101DE8(GhostRecord* ghostRecord, bool shouldClear) {
    s32 i;

    if (shouldClear) {
        Save_ClearData(ghostRecord, sizeof(GhostRecord));
    }

    ghostRecord->replayChecksum = 0;
    ghostRecord->ghostType = GHOST_NONE;
    ghostRecord->encodedCourseIndex = 0;
    ghostRecord->raceTime = 0;
    ghostRecord->unk_10 = 0;

    func_i2_80101C78(&ghostRecord->unk_20);

    for (i = 0; i < 9; i++) {
        ghostRecord->trackName[i] = 0;
    }
}

void func_i2_80101E68(GhostData* ghostData, bool shouldClear) {
    s32 i;

    if (shouldClear) {
        Save_ClearData(ghostData, sizeof(GhostData));
    }

    // clang-format off
    for (i = 0; i < 3; i++) { \
        ghostData->lapTimes[i] = 0;
    }
    // clang-format on

    ghostData->replayEnd = 0;
    ghostData->replaySize = 0;
}

void func_i2_80101EBC(CharacterSave* characterSave, bool shouldClear) {
    s32 i;

    if (shouldClear) {
        Save_ClearData(characterSave, sizeof(CharacterSave));
    }

    for (i = 0; i < 30; i++) {
        characterSave->characterEngine[i] = 0.5f;
    }
}

void func_i2_80101F24(CupSave* cupSave, bool shouldClear) {
    s32 i;
    s32 j;

    if (shouldClear) {
        Save_ClearData(cupSave, sizeof(CupSave));
    }

    for (i = 0; i < 4; i++) {
        // clang-format off
        for (j = 0; j < 10; j++) { \
            cupSave->cupCompletion[i][j] = 0;
        }
        // clang-format on
    }
}

void Save_ClearData(void* data, s32 size) {
    s32 i;
    u8* ptr;

    // clang-format off
    for (i = 0, ptr = data; i < size; i++, ptr++) { \
        *ptr = 0;
    }
    // clang-format on
}

extern s8 gSettingEverythingUnlocked;
extern s16 gSettingVsHandicap;
extern s32 gSettingVsSlot;
extern s8 gCupNumDifficultiesCleared[];
extern s16 gSettingVsCom;

void func_i2_80101FEC(SaveSettings* saveSettings) {
    u8 settingLowerFlags;
    u8 settingHigherFlags;
    s32 i;

    for (i = 0; i < 8; i++) {
        saveSettings->fileName[i] = D_i2_8010ADE0[i];
    }

    settingHigherFlags = ((u8) gSettingVsHandicap << 4);

    settingLowerFlags = 0;

    if (gSettingVsCom != 0) {
        settingLowerFlags |= 1;
    }
    if (gSettingVsSlot != 0) {
        settingLowerFlags |= 2;
    }
    if (gSettingSoundMode != 0) {
        settingLowerFlags |= 4;
    }
    if (gSettingEverythingUnlocked != 0) {
        settingLowerFlags |= 8;
    }

    saveSettings->settings = settingHigherFlags | settingLowerFlags;

    for (i = JACK_CUP; i <= JOKER_CUP; i++) {
        saveSettings->cupDifficultiesCleared[i] = gCupNumDifficultiesCleared[i];
    }

    saveSettings->unk_09 = 0;

    if (D_i2_80111848[0] != 0) {
        saveSettings->unk_09 |= 1;
    }
    if (D_i2_80111848[3] != 0) {
        saveSettings->unk_09 |= 2;
    }
    if (D_i2_80111848[4] != 0) {
        saveSettings->unk_09 |= 4;
    }
}

void func_i2_80102110(CarInfo* carInfo, unk_80141C88_unk_1D* arg1) {

    arg1->unk_00.unk_00[0] = carInfo->unk_00[0];
    arg1->unk_00.unk_00[1] = carInfo->unk_00[1];
    arg1->unk_00.unk_00[2] = carInfo->unk_00[2];
    arg1->unk_00.unk_00[3] = carInfo->unk_00[3];
    arg1->unk_00.unk_00[4] = carInfo->unk_00[4];
    arg1->unk_00.unk_00[5] = carInfo->unk_00[5];
    arg1->unk_00.unk_00[6] = carInfo->unk_00[6];
    arg1->unk_00.unk_00[7] = carInfo->unk_00[7];
    arg1->unk_00.unk_00[8] = carInfo->unk_00[8];
    arg1->unk_00.unk_00[9] = carInfo->unk_00[9];
    arg1->unk_00.unk_00[10] = carInfo->unk_00[10];
    arg1->unk_00.unk_00[11] = carInfo->unk_00[11];
    arg1->unk_00.unk_00[12] = carInfo->unk_00[12];
    arg1->unk_00.unk_00[13] = carInfo->unk_00[13];
    arg1->unk_00.unk_00[14] = carInfo->unk_00[14];
    arg1->unk_00.unk_00[15] = carInfo->unk_00[15];
    arg1->unk_00.unk_00[16] = carInfo->unk_00[16];
    arg1->unk_00.unk_00[17] = carInfo->unk_00[17];
    arg1->unk_00.unk_00[18] = carInfo->unk_00[18];
    arg1->unk_00.unk_00[19] = carInfo->unk_00[19];
}

void func_i2_801021B4(SaveDeathRace* deathRace) {
    CourseRecordInfo* var_a1 = &gCourseRecordInfos[54];
    s32 i;

    for (i = 0; i < 1; i++) {
        deathRace->timeRecord[i] = var_a1->timeRecord[i];
    }
    deathRace->unk_02 = 0;

    // clang-format off
    for (i = 0; i < 8; i++) { \
        deathRace->unk_08[i] = 0;
    }
    // clang-format on
}

void func_i2_80102214(SaveCourseRecords* courseRecords, s32 courseIndex) {
    CourseRecordInfo* courseRecordInfo;
    s32 i;
    s32 j;

    courseRecordInfo = &gCourseRecordInfos[courseIndex];

    for (i = 0; i < 5; i++) {
        courseRecords->timeRecord[i] = courseRecordInfo->timeRecord[i];
        courseRecords->engine[i] = courseRecordInfo->engine[i];
        func_i2_80102110(&courseRecordInfo->carInfo[i], &courseRecords->unk_50[i]);
        for (j = 0; j < 4; j++) {
            courseRecords->name[i][j] = courseRecordInfo->name[i][j];
        }
    }
    courseRecords->maxSpeed = courseRecordInfo->maxSpeed;
    courseRecords->bestTime = courseRecordInfo->bestTime;
    func_i2_80102110(&courseRecordInfo->maxSpeedCar, &courseRecords->unk_F0);
    courseRecords->unk_02 = 0;

    // clang-format off
    for (i = 0; i < 8; i++) { \
        courseRecords->unk_48[i] = 0;
    }
    // clang-format on
}

void func_i2_80102350(SaveEditCup* editCup) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 9; j++) {
            editCup->editCupTrackNames[i][j] = gEditCupTrackNames[i][j];
        }
    }
    editCup->unk_02 = 0;
    editCup->unk_04 = 0;
    editCup->unk_08 = 0;
}

void func_i2_801023D8(Ghost* ghost) {
    s32 i;
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;

    ghostRecord->replayChecksum = ghost->replayChecksum;
    ghostRecord->ghostType = ghost->ghostType;
    ghostRecord->unk_10 = 0;
    ghostRecord->encodedCourseIndex = ghost->encodedCourseIndex;

    ghostRecord->raceTime = ghost->raceTime;
    ghostRecord->unk_20.unk_00.unk_00[0] = ghost->carInfo.unk_00[0];
    ghostRecord->unk_20.unk_00.unk_00[1] = ghost->carInfo.unk_00[1];
    ghostRecord->unk_20.unk_00.unk_00[2] = ghost->carInfo.unk_00[2];
    ghostRecord->unk_20.unk_00.unk_00[3] = ghost->carInfo.unk_00[3];
    ghostRecord->unk_20.unk_00.unk_00[4] = ghost->carInfo.unk_00[4];
    ghostRecord->unk_20.unk_00.unk_00[5] = ghost->carInfo.unk_00[5];
    ghostRecord->unk_20.unk_00.unk_00[6] = ghost->carInfo.unk_00[6];
    ghostRecord->unk_20.unk_00.unk_00[7] = ghost->carInfo.unk_00[7];
    ghostRecord->unk_20.unk_00.unk_00[8] = ghost->carInfo.unk_00[8];
    ghostRecord->unk_20.unk_00.unk_00[9] = ghost->carInfo.unk_00[9];
    ghostRecord->unk_20.unk_00.unk_00[10] = ghost->carInfo.unk_00[10];
    ghostRecord->unk_20.unk_00.unk_00[11] = ghost->carInfo.unk_00[11];
    ghostRecord->unk_20.unk_00.unk_00[12] = ghost->carInfo.unk_00[12];
    ghostRecord->unk_20.unk_00.unk_00[13] = ghost->carInfo.unk_00[13];
    ghostRecord->unk_20.unk_00.unk_00[14] = ghost->carInfo.unk_00[14];
    ghostRecord->unk_20.unk_00.unk_00[15] = ghost->carInfo.unk_00[15];
    ghostRecord->unk_20.unk_00.unk_00[16] = ghost->carInfo.unk_00[16];
    ghostRecord->unk_20.unk_00.unk_00[17] = ghost->carInfo.unk_00[17];
    ghostRecord->unk_20.unk_00.unk_00[18] = ghost->carInfo.unk_00[18];
    ghostRecord->unk_20.unk_00.unk_00[19] = ghost->carInfo.unk_00[19];

    for (i = 0; i < 9; i++) {
        ghostRecord->trackName[i] = '\0';
    }

    for (i = 0; i < 5; i++) {
        ghostRecord->unk_12[i] = 0;
    }
}

void func_i2_801024F8(Ghost* ghost) {
    s32 i;
    u8* var_a1;
    s8* var_v1;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    for (i = 0; i < 3; i++) {
        ghostData->lapTimes[i] = ghost->lapTimes[i];
    }

    ghostData->replayEnd = ghost->replayEnd;
    ghostData->replaySize = ghost->replaySize;

    var_v1 = ghost->replayData;
    var_a1 = ghostData->replayData;

    for (i = 0; i < 16200; i++) {
        *var_a1++ = *var_v1++;
    }

    ghostData->unk_02 = 0;
    ghostData->unk_18 = 0;
    ghostData->unk_1C = 0;
}

extern f32 gCharacterLastEngine[30];

void func_i2_8010259C(CharacterSave* characterSave) {
    s32 i;

    for (i = 0; i < 30; i++) {
        characterSave->characterEngine[i] = gCharacterLastEngine[i];
    }

    characterSave->unk_02 = 0;
    characterSave->unk_04 = 0;
}

void func_i2_80102B20(ProfileSave*);
void func_i2_80102A7C(unk_80141C88_unk_1D*, CarInfo* arg1);

void Save_Load(SaveContext* saveContext) {
    s32 i;
    s32 j;
    CourseRecordInfo* courseRecordInfo;
    Ghost* ghost;
    unk_80141C88_unk_1D sp60;

    for (i = 0, courseRecordInfo = gCourseRecordInfos; i < ARRAY_COUNT(gCourseRecordInfos); i++, courseRecordInfo++) {
        if (i < 24) {
            func_i2_80102CA4(saveContext->profileSaves, i);
        } else {
            func_i2_80101C78(&sp60);

            for (j = 0; j < 5; j++) {
                courseRecordInfo->timeRecord[j] = MAX_TIMER;
                courseRecordInfo->engine[j] = 0.5f;
                func_i2_80102A7C(&sp60, &courseRecordInfo->carInfo[j]);
            }

            courseRecordInfo->maxSpeed = 0.0f;

            func_i2_80102A7C(&sp60, &courseRecordInfo->maxSpeedCar);
            if (i == 54) {
                func_i2_80102B20(saveContext->profileSaves);
            }
        }
    }

    func_i2_80102784(saveContext->profileSaves, true);

    for (i = 0; i < 30; i++) {
        D_i2_80111848[i] = 0;
    }

    func_i2_8010300C(&saveContext->ghostRecord, &saveContext->ghostData, gGhosts, true);

    for (i = 0, ghost = gGhosts; i < 3; i++, ghost++) {
        ghost->encodedCourseIndex = 0;
    }
}

void func_i2_80102784(ProfileSave* profileSaves, bool arg1) {
    u16 checksum;
    s32 var_v1;
    s32 sp2C;
    s32 i;
    s32 var_v0;
    ProfileSave* var_s1;
    SaveSettings* var_v1_2;

    var_v1 = 0;

    for (i = 0, var_s1 = profileSaves; i < 2; i++) {
        if (var_s1->saveSettings.checksum != Save_CalculateSaveSettingsChecksum(var_s1) * 1) {
            var_v1++;
            sp2C = i;
        }
        var_s1++;
    }

    if (var_v1 == 2) {
        func_i2_80101B8C(&profileSaves[0].saveSettings, true);
        profileSaves[1].saveSettings = profileSaves[0].saveSettings;

        checksum = Save_CalculateSaveSettingsChecksum(profileSaves);

        for (i = 0; i < 2; i++) {
            Save_WriteSaveSettings(profileSaves, i, checksum);
        }
    } else if (var_v1 == 1) {
        var_v0 = (sp2C == 0) ? 1 : 0;

        (profileSaves + sp2C)->saveSettings = (profileSaves + var_v0)->saveSettings;

        Save_WriteSaveSettings(profileSaves, sp2C, Save_CalculateSaveSettingsChecksum(profileSaves));
    }

    if (!arg1) {
        return;
    }

    var_v1_2 = &profileSaves->saveSettings;

    gSettingVsHandicap = ((u8) (var_v1_2->settings >> 4) & 0xFF) & 0xF;
    if (var_v1_2->settings & 1) {
        gSettingVsCom = 1;
    } else {
        gSettingVsCom = 0;
    }
    if (var_v1_2->settings & 2) {
        gSettingVsSlot = 1;
    } else {
        gSettingVsSlot = 0;
    }
    if (var_v1_2->settings & 4) {
        gSettingSoundMode = 1;
    } else {
        gSettingSoundMode = 0;
    }
    if (var_v1_2->settings & 8) {
        gSettingEverythingUnlocked = 1;
    } else {
        gSettingEverythingUnlocked = 0;
    }

    for (i = JACK_CUP; i <= JOKER_CUP; i++) {
        gCupNumDifficultiesCleared[i] = var_v1_2->cupDifficultiesCleared[i];
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

void func_i2_80102A7C(unk_80141C88_unk_1D* arg0, CarInfo* arg1) {

    arg1->unk_00[0] = arg0->unk_00.unk_00[0];
    arg1->unk_00[1] = arg0->unk_00.unk_00[1];
    arg1->unk_00[2] = arg0->unk_00.unk_00[2];
    arg1->unk_00[3] = arg0->unk_00.unk_00[3];
    arg1->unk_00[4] = arg0->unk_00.unk_00[4];
    arg1->unk_00[5] = arg0->unk_00.unk_00[5];
    arg1->unk_00[6] = arg0->unk_00.unk_00[6];
    arg1->unk_00[7] = arg0->unk_00.unk_00[7];
    arg1->unk_00[8] = arg0->unk_00.unk_00[8];
    arg1->unk_00[9] = arg0->unk_00.unk_00[9];
    arg1->unk_00[10] = arg0->unk_00.unk_00[10];
    arg1->unk_00[11] = arg0->unk_00.unk_00[11];
    arg1->unk_00[12] = arg0->unk_00.unk_00[12];
    arg1->unk_00[13] = arg0->unk_00.unk_00[13];
    arg1->unk_00[14] = arg0->unk_00.unk_00[14];
    arg1->unk_00[15] = arg0->unk_00.unk_00[15];
    arg1->unk_00[16] = arg0->unk_00.unk_00[16];
    arg1->unk_00[17] = arg0->unk_00.unk_00[17];
    arg1->unk_00[18] = arg0->unk_00.unk_00[18];
    arg1->unk_00[19] = arg0->unk_00.unk_00[19];
}

void func_i2_80102B20(ProfileSave* profileSaves) {
    u16 checksum;
    s32 var_s2;
    s32 var_v0;
    s32 sp30;
    CourseRecordInfo* var_v0_2;
    SaveDeathRace* var_v1;
    ProfileSave* var_s1;
    s32 i;

    var_s2 = 0;

    for (i = 0, var_s1 = profileSaves; i < 2; i++) {
        if (var_s1->deathRace.checksum != Save_CalculateSaveDeathRaceChecksum(var_s1) * 1) {
            var_s2++;
            sp30 = i;
        }
        var_s1++;
    }

    if (var_s2 == 2) {
        func_i2_80101CCC(&profileSaves[0].deathRace, true);
        profileSaves[1].deathRace = profileSaves[0].deathRace;

        checksum = Save_CalculateSaveDeathRaceChecksum(profileSaves);

        for (i = 0; i < 2; i++) {
            Save_WriteSaveDeathRace(profileSaves, i, checksum);
        }
    } else if (var_s2 == 1) {
        var_v0 = (sp30 == 0) ? 1 : 0;

        (profileSaves + sp30)->deathRace = (profileSaves + var_v0)->deathRace;

        Save_WriteSaveDeathRace(profileSaves, sp30, Save_CalculateSaveDeathRaceChecksum(profileSaves));
    }
    var_v0_2 = &gCourseRecordInfos[54];
    var_v1 = &profileSaves->deathRace;
    for (i = 0; i < 1; i++) {
        var_v0_2->timeRecord[i] = var_v1->timeRecord[i];
    }
}

void func_i2_80102CA4(ProfileSave* profileSaves, s32 courseIndex) {
    u16 checksum;
    s32 j;
    s32 i;
    s32 var_s4;
    CourseRecordInfo* var_s3;
    ProfileSave* var_s0;
    s32 var_v0;
    SaveCourseRecords* sp40;

    j = 0;

    for (i = 0, var_s0 = profileSaves; i < 2; i++) {
        if (var_s0->courses[courseIndex].checksum != Save_CalculateSaveCourseRecordChecksum(var_s0, courseIndex)) {
            j++;
            var_s4 = i;
        }
        var_s0++;
    }

    if (j == 2) {

        func_i2_80101D18(&profileSaves[0].courses[courseIndex], true);
        profileSaves[1].courses[courseIndex] = profileSaves[0].courses[courseIndex];

        checksum = Save_CalculateSaveCourseRecordChecksum(profileSaves, courseIndex);

        for (i = 0; i < 2; i++) {
            Save_WriteSaveCourseRecord(profileSaves, i, courseIndex, checksum);
        }

    } else if (j == 1) {
        var_v0 = (var_s4 == 0) ? 1 : 0;

        (profileSaves + var_s4)->courses[courseIndex] = (profileSaves + var_v0)->courses[courseIndex];

        Save_WriteSaveCourseRecord(profileSaves, var_s4, courseIndex,
                                   Save_CalculateSaveCourseRecordChecksum(profileSaves, courseIndex));
    }

    sp40 = &profileSaves->courses[courseIndex];
    var_s3 = &gCourseRecordInfos[courseIndex];

    for (i = 0; i < 5; i++) {
        var_s3->timeRecord[i] = sp40->timeRecord[i];
        var_s3->engine[i] = sp40->engine[i];
        func_i2_80102A7C(&sp40->unk_50[i], &var_s3->carInfo[i]);
        for (j = 0; j < 4; j++) {
            var_s3->name[i][j] = sp40->name[i][j];
        }
    }
    var_s3->maxSpeed = sp40->maxSpeed;
    var_s3->bestTime = sp40->bestTime;
    func_i2_80102A7C(&sp40->unk_F0, &var_s3->maxSpeedCar);
}

void func_i2_80102F70(GhostRecord* ghostRecord, GhostData* ghostData, Ghost* ghost, bool arg3) {

    if (arg3) {
        if (ghostRecord->checksum != Save_CalculateGhostRecordChecksum(ghostRecord) * 1) {
            func_i2_80101DE8(ghostRecord, true);
            Save_WriteGhostRecord(ghostRecord);
            func_i2_80101E68(ghostData, true);
            Save_WriteGhostData(ghostData);
        }
    }

    ghost->replayChecksum = ghostRecord->replayChecksum;
    ghost->ghostType = ghostRecord->ghostType;
    ghost->encodedCourseIndex = ghostRecord->encodedCourseIndex;
    ghost->raceTime = ghostRecord->raceTime;
    func_i2_80102A7C(&ghostRecord->unk_20, &ghost->carInfo);
}

void func_i2_8010300C(GhostRecord* ghostRecord, GhostData* ghostData, Ghost* ghost, bool arg3) {
    s32 i;
    u8* var_v0;
    s8* var_v1;
    GhostRecord* ghostRecord2 = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData2 = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    if (arg3) {
        if (ghostData->checksum != Save_CalculateGhostDataChecksum(ghostData) * 1) {
            func_i2_80101DE8(ghostRecord2, true);
            Save_WriteGhostRecord(ghostRecord2);
            func_i2_80101E68(ghostData2, true);
            Save_WriteGhostData(ghostData2);
            ghost->encodedCourseIndex = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        ghost->lapTimes[i] = ghostData->lapTimes[i];
    }

    ghost->replayEnd = ghostData->replayEnd;
    ghost->replaySize = ghostData->replaySize;

    var_v0 = ghostData->replayData;
    var_v1 = ghost->replayData;

    for (i = 0; i < 16200; i++) {
        *var_v1++ = *var_v0++;
    }
}

void func_i2_80103108(ProfileSave* profileSaves, bool arg1) {
    SaveEditCup* var_a3;
    s32 i;
    s32 j;
    s32 sp30;
    u16 checksum;
    s32 var_s2;
    s32 var_v0;
    ProfileSave* var_s1;

    var_s2 = 0;

    for (i = 0, var_s1 = profileSaves; i < 2; i++) {
        if (var_s1->editCup.checksum != Save_CalculateSaveEditCupChecksum(var_s1) * 1) {
            var_s2++;
            sp30 = i;
        }
        var_s1++;
    }

    if (var_s2 == 2) {
        func_i2_80101C04(&profileSaves[0].editCup, true);
        profileSaves[1].editCup = profileSaves[0].editCup;

        checksum = Save_CalculateSaveEditCupChecksum(profileSaves);
        for (i = 0; i < 2; i++) {
            Save_WriteSaveEditCup(profileSaves, i, checksum);
        }
    } else if (var_s2 == 1) {
        var_v0 = (sp30 == 0) ? 1 : 0;

        (profileSaves + sp30)->editCup = (profileSaves + var_v0)->editCup;

        Save_WriteSaveEditCup(profileSaves, sp30, Save_CalculateSaveEditCupChecksum(profileSaves));
    }

    if (!arg1) {
        return;
    }

    var_a3 = &profileSaves[0].editCup;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 9; j++) {
            gEditCupTrackNames[i][j] = var_a3->editCupTrackNames[i][j];
        }
    }
}

extern f32 gCharacterLastEngine[];

void func_i2_80103310(CharacterSave* characterSave, s32 courseIndex) {
    s32 i;

    if (characterSave->checksum != Save_CalculateCharacterSaveChecksum(characterSave) * 1) {
        func_i2_80101EBC(characterSave, true);
        Save_WriteCharacterSave(characterSave, courseIndex);
    }

    for (i = 0; i < 30; i++) {
        gCharacterLastEngine[i] = characterSave->characterEngine[i];
    }
}

void func_i2_801033B8(CupSave* cupSave, u8* arg1) {
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    u8 temp_v1;
    s8* var_a0;
    s32 temp;

    if (cupSave->checksum != Save_CalculateCupSaveChecksum(cupSave) * 1) {
        func_i2_80101F24(cupSave, true);
        Save_WriteCupSave(cupSave);
    }

    if (arg1 == NULL) {
        return;
    }

    var_a0 = arg1;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 10; j++) {
            temp = cupSave->cupCompletion[i][j];
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

u16 Save_CalculateChecksum(void* data, s32 size) {
    u8* dataPtr = data;
    u16 checksum = 0;
    s32 i;

    for (i = 0; i < size; i++) {
        checksum += *dataPtr++;
    }

    return checksum;
}

s32 Save_CalculateSaveSettingsChecksum(ProfileSave* profileSave) {
    return Save_CalculateChecksum(&profileSave->saveSettings.fileName, sizeof(SaveSettings) - sizeof(u16));
}

s32 Save_CalculateSaveDeathRaceChecksum(ProfileSave* profileSave) {
    return Save_CalculateChecksum(&profileSave->deathRace.unk_02, sizeof(SaveDeathRace) - sizeof(u16));
}

s32 Save_CalculateSaveCourseRecordChecksum(ProfileSave* profileSave, s32 courseIndex) {
    return Save_CalculateChecksum(&profileSave->courses[courseIndex].unk_02, sizeof(SaveCourseRecords) - sizeof(u16));
}

s32 Save_CalculateSaveEditCupChecksum(ProfileSave* profileSave) {
    return Save_CalculateChecksum(&profileSave->editCup.unk_02, sizeof(SaveEditCup) - sizeof(u16));
}

s32 Save_CalculateGhostRecordChecksum(GhostRecord* ghostRecord) {
    return Save_CalculateChecksum(&ghostRecord->ghostType, sizeof(GhostRecord) - sizeof(u16));
}

s32 Save_CalculateGhostDataChecksum(GhostData* ghostData) {
    return Save_CalculateChecksum(&ghostData->unk_02, sizeof(GhostData) - sizeof(u16));
}

s32 Save_CalculateCharacterSaveChecksum(CharacterSave* characterSave) {
    return Save_CalculateChecksum(&characterSave->unk_02, sizeof(CharacterSave) - sizeof(u16));
}

s32 Save_CalculateCupSaveChecksum(CupSave* cupSave) {
    return Save_CalculateChecksum(&cupSave->unk_02, sizeof(CupSave) - sizeof(u16));
}

OSPiHandle* Sram_Init(void) {
    if (sSramPiHandle.baseAddress == PHYS_TO_K1(PI_DOM2_ADDR2)) {
        return &sSramPiHandle;
    }
    sSramPiHandle.type = DEVICE_TYPE_SRAM;
    sSramPiHandle.baseAddress = PHYS_TO_K1(PI_DOM2_ADDR2);
    sSramPiHandle.latency = 5;
    sSramPiHandle.pulse = 12;
    sSramPiHandle.pageSize = 13;
    sSramPiHandle.relDuration = 2;
    sSramPiHandle.domain = PI_DOMAIN2;
    sSramPiHandle.speed = 0;
    bzero(&sSramPiHandle.transferInfo, sizeof(__OSTranxInfo));
    osEPiLinkHandle(&sSramPiHandle);
    return &sSramPiHandle;
}

extern OSMesgQueue gDmaMesgQueue;

void Sram_ReadWrite(s32 direction, u32 offset, void* dramAddr, size_t size) {
    osWritebackDCache(dramAddr, size);
    osInvalDCache(osPhysicalToVirtual((uintptr_t) dramAddr), size);
    sSramIoMesg.hdr.pri = 0;
    sSramIoMesg.hdr.retQueue = &gDmaMesgQueue;
    sSramIoMesg.dramAddr = dramAddr;
    sSramIoMesg.devAddr = offset + OS_K1_TO_PHYSICAL(0xA8000000);
    sSramIoMesg.size = size;
    osEPiStartDma(gSramPiHandlePtr, &sSramIoMesg, direction);
    osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
}

void func_i2_8010382C(GhostRecord*, s32);

s32 func_i2_801037CC(unk_80141C88* arg0, s32 courseIndex) {
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;

    if ((courseIndex < 0) || (courseIndex >= 24)) {
        return 2;
    }
    func_i2_8010382C(ghostRecord, courseIndex);
    if (arg0 != NULL) {
        func_i2_80101590(ghostRecord, arg0);
    }
    return 0;
}

void func_i2_8010382C(GhostRecord* ghostRecord, s32 courseIndex) {
    func_80073ED0(SEGMENT_ROM_START(segment_27F200) + D_i2_80106DF0[courseIndex][0], ghostRecord, sizeof(GhostRecord));
}

void func_i2_80103930(GhostData*, s32);

s32 func_i2_8010387C(s32 courseIndex) {
    s32 sp64;
    unk_80141C88 sp24;
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    func_i2_801037CC(&sp24, courseIndex);
    if (func_i2_80100B38(&sp24) != 0) {
        return 0;
    }

    sp64 = func_i2_801005CC(courseIndex);
    func_i2_80103930(ghostData, courseIndex);
    func_i2_80102F70(ghostRecord, ghostData, &gGhosts[sp64], false);
    func_i2_8010300C(ghostRecord, ghostData, &gGhosts[sp64], false);

    return 0;
}

void func_i2_80103930(GhostData* ghostData, s32 courseIndex) {
    uintptr_t* offsets = D_i2_80106DF0[courseIndex];
    RomOffset romOffset = SEGMENT_ROM_START(segment_27F200);

    func_80073ED0(romOffset + offsets[1], ghostData, 0x20);
    func_80073ED0(romOffset + offsets[2], ghostData->replayData, ALIGN_2(ghostData->replaySize + 1));
}

void func_i2_801039BC(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            ((ProfileSave*) gSaveBuffer)[i].saveSettings.fileName[j] = D_i2_8010ADE8[j];
            Save_WriteSaveSettings(((ProfileSave*) gSaveBuffer), i, 0x1234);
        }
    }
}
