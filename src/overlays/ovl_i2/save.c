#include "global.h"
#include "fzx_game.h"
#include "fzx_save.h"
#include "fzx_course.h"
#include "fzx_machine.h"
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

void Save_LoadCupSave(CupSave*, u8*);
void Save_LoadGhostData(GhostRecord*, GhostData*, Ghost*, bool);
void Save_LoadGhostRecord(GhostRecord*, GhostData*, Ghost*, bool);
void Save_LoadCourseRecord(ProfileSave*, s32);
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

s32 SaveLoadPlayerGhost(s32, s32);
s32 Save_LoadStaffGhost(s32);

s32 Save_LoadGhost(s32 courseIndex) {
    s32 i;
    s32 sp18;
    s32 encodedCourseIndex = gCourseInfos[courseIndex].encodedCourseIndex;
    Ghost* ghost = gGhosts;

    for (i = 0; i < 3; i++) {
        if (encodedCourseIndex != ghost->encodedCourseIndex) {
            ghost->encodedCourseIndex = 0;
        }
        ghost++;
    }
    switch (gCurrentGhostType) {
        case GHOST_CELEBRITY:
        case GHOST_CHAMP:
            break;
        case GHOST_NONE:
        case GHOST_PLAYER:
            sp18 = SaveLoadPlayerGhost(courseIndex, -1);
            break;
        case GHOST_STAFF:
            sp18 = Save_LoadStaffGhost(courseIndex);
            break;
    }
    return sp18;
}

s32 func_i2_801005CC(s32 courseIndex) {
    s32 i;
    s32 var_a0;
    s32 var_v1;
    Ghost* ghost;

    var_v1 = -1;

    for (i = 0, ghost = gGhosts; i < 3; i++, ghost++) {
        if (ghost->encodedCourseIndex == 0) {
            var_v1 = i;
            break;
        }
    }

    if (var_v1 != -1) {
        return var_v1;
    }

    for (i = 0, ghost = gGhosts; i < 3; i++, ghost++) {
        if (ghost->ghostType != GHOST_PLAYER) {
            var_v1 = i;
            break;
        }
    }

    var_a0 = -1;
    if (var_v1 != -1) {
        return var_v1;
    }

    for (i = 0, ghost = gGhosts; i < 3; i++, ghost++) {
        if (courseIndex != (ghost->encodedCourseIndex & 0x1F)) {
            var_v1 = i;
            var_a0 = ghost->raceTime;
            break;
        }
    }

    if (var_a0 != -1) {
        for (i = var_v1 + 1, ghost = &gGhosts[i]; i < 3; i++, ghost++) {
            if (courseIndex != (ghost->encodedCourseIndex & 0x1F)) {
                if (var_a0 < ghost->raceTime) {
                    var_a0 = ghost->raceTime;
                    var_v1 = i;
                }
            }
        }
    } else {
        for (i = 0, ghost = gGhosts; i < 3; i++, ghost++) {
            if (courseIndex == (ghost->encodedCourseIndex & 0x1F)) {
                if (var_a0 < ghost->raceTime) {
                    var_a0 = ghost->raceTime;
                    var_v1 = i;
                }
            }
        }
    }
    return var_v1;
}

bool func_i2_80100B38(GhostInfo*);
s32 func_i2_801005CC(s32);

s32 SaveLoadPlayerGhost(s32 courseIndex, s32 ghostIndex) {
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];
    s32 var_t0;
    s32 pad2[4];
    GhostInfo sp24;
    s32 temp_v0;

    temp_v0 = Save_LoadGhostInfo(&sp24);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    if (sp24.courseIndex != courseIndex) {
        return 2;
    }

    if (func_i2_80100B38(&sp24)) {
        return 0;
    }
    if (ghostIndex == -1) {
        var_t0 = func_i2_801005CC(courseIndex);

        if ((gGhosts[var_t0].encodedCourseIndex != 0) && (gGhosts[var_t0].ghostType == GHOST_PLAYER) &&
            (sp24.courseIndex == (gGhosts[var_t0].encodedCourseIndex & 0x1F)) &&
            (gGhosts[var_t0].raceTime < sp24.raceTime)) {
            return 0;
        }
    } else {
        var_t0 = ghostIndex;
    }

    Save_ReadGhostData(ghostData);
    Save_LoadGhostRecord(ghostRecord, ghostData, &gGhosts[var_t0], true);
    Save_LoadGhostData(ghostRecord, ghostData, &gGhosts[var_t0], true);

    return 0;
}

bool func_i2_80100950(MachineInfo* machineInfo, unk_80141C88_unk_1D* arg1) {
    bool matching = true;

    if (machineInfo->character != arg1->unk_00.character) {
        matching = false;
    } else if (machineInfo->customType != arg1->unk_00.customType) {
        matching = false;
    } else if (machineInfo->frontType != arg1->unk_00.frontType) {
        matching = false;
    } else if (machineInfo->rearType != arg1->unk_00.rearType) {
        matching = false;
    } else if (machineInfo->wingType != arg1->unk_00.wingType) {
        matching = false;
    } else if (machineInfo->logo != arg1->unk_00.logo) {
        matching = false;
    } else if (machineInfo->number != arg1->unk_00.number) {
        matching = false;
    } else if (machineInfo->decal != arg1->unk_00.decal) {
        matching = false;
    } else if (machineInfo->bodyR != arg1->unk_00.bodyR) {
        matching = false;
    } else if (machineInfo->bodyG != arg1->unk_00.bodyG) {
        matching = false;
    } else if (machineInfo->bodyB != arg1->unk_00.bodyB) {
        matching = false;
    } else if (machineInfo->numberR != arg1->unk_00.numberR) {
        matching = false;
    } else if (machineInfo->numberG != arg1->unk_00.numberG) {
        matching = false;
    } else if (machineInfo->numberB != arg1->unk_00.numberB) {
        matching = false;
    } else if (machineInfo->decalR != arg1->unk_00.decalR) {
        matching = false;
    } else if (machineInfo->decalG != arg1->unk_00.decalG) {
        matching = false;
    } else if (machineInfo->decalB != arg1->unk_00.decalB) {
        matching = false;
    } else if (machineInfo->cockpitR != arg1->unk_00.cockpitR) {
        matching = false;
    } else if (machineInfo->cockpitG != arg1->unk_00.cockpitG) {
        matching = false;
    } else if (machineInfo->cockpitB != arg1->unk_00.cockpitB) {
        matching = false;
    }
    return matching;
}

bool func_i2_80100B38(GhostInfo* arg0) {
    bool var_s1;
    s32 i;
    Ghost* ghost = gGhosts;

    for (i = 0; i < 3; i++) {
        var_s1 = true;
        if (ghost->ghostType != arg0->ghostType) {
            var_s1 = false;
        } else if (ghost->replayChecksum != arg0->replayChecksum) {
            var_s1 = false;
        } else if (ghost->encodedCourseIndex != arg0->encodedCourseIndex) {
            var_s1 = false;
        } else if (ghost->raceTime != arg0->raceTime) {
            var_s1 = false;
        } else if (!func_i2_80100950(&ghost->machineInfo, &arg0->unk_1D)) {
            var_s1 = false;
        }

        if (var_s1) {
            break;
        }
        ghost++;
    }
    return var_s1;
}

void Save_LoadCharacterSave(CharacterSave*, s32);

s32 Save_UpdateCharacterSave(s32 courseIndex) {
    CharacterSave* characterSaves = (CharacterSave*) gSaveBuffer;

    Save_ReadCharacterSave(&characterSaves[courseIndex], courseIndex);
    Save_LoadCharacterSave(&characterSaves[courseIndex], courseIndex);
    return 0;
}

s32 Save_UpdateCupSave(u8* arg0) {
    CupSave* cupSave = (CupSave*) gSaveBuffer;

    Save_ReadCupSave(cupSave);
    Save_LoadCupSave(cupSave, arg0);
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
    saveContext->ghostData.replayInfo.checksum = Save_CalculateGhostDataChecksum(&saveContext->ghostData);

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
    ghostData->replayInfo.checksum = Save_CalculateGhostDataChecksum(ghostData);
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

void Save_SaveCourseRecord(SaveCourseRecords*, s32);

s32 Save_SaveCourseRecordProfiles(s32 courseIndex) {
    u16 checksum;
    s32 i;
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;

    Save_SaveCourseRecord(&profileSaves[0].courses[courseIndex], courseIndex);
    profileSaves[1].courses[courseIndex] = profileSaves[0].courses[courseIndex];

    checksum = Save_CalculateSaveCourseRecordChecksum(profileSaves, courseIndex);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveCourseRecord(profileSaves, i, courseIndex, checksum);
    }

    return 0;
}

extern s32 gRamDDCompatible;
void Save_SaveEditCup(SaveEditCup*);

s32 Save_SaveEditCupProfiles(void) {
    u16 checksum;
    s32 i;
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;

    if (!gRamDDCompatible) {
        return 3;
    }
    Save_SaveEditCup(&profileSaves[0].editCup);

    profileSaves[1].editCup = profileSaves[0].editCup;

    checksum = Save_CalculateSaveEditCupChecksum(profileSaves);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveEditCup(profileSaves, i, checksum);
    }

    return 0;
}

void Save_SaveCharacterSave(CharacterSave*);

s32 Save_UpdateCourseCharacterSave(s32 courseIndex) {
    s32 pad[2];
    CharacterSave* characterSaves = (CharacterSave*) gSaveBuffer;

    Save_SaveCharacterSave(&characterSaves[courseIndex]);
    Save_WriteCharacterSave(&characterSaves[courseIndex], courseIndex);
    return 0;
}

s32 Save_UpdateCupCompletion(s32 difficulty, s32 cupType, s32 character) {
    s32 i;
    s32 cupCompletion;
    CupSave* cupSave = (CupSave*) gSaveBuffer;

    Save_ReadCupSave(cupSave);
    Save_LoadCupSave(cupSave, NULL);

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

void Save_SaveSettings(SaveSettings*);

s32 Save_SaveSettingsProfiles(void) {
    u16 checksum;
    s32 i;
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;

    Save_SaveSettings(&profileSaves[0].saveSettings);
    profileSaves[1].saveSettings = profileSaves[0].saveSettings;

    checksum = Save_CalculateSaveSettingsChecksum(profileSaves);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveSettings(profileSaves, i, checksum);
    }

    return 0;
}

void func_i2_80101590(GhostRecord*, GhostInfo*);
void Save_InitGhostData(GhostData*, bool);
void Save_InitGhostRecord(GhostRecord*, bool);

s32 Save_LoadGhostInfo(GhostInfo* ghostInfo) {
    s32 pad;
    s32 var_v1;
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    Save_ReadGhostRecord(ghostRecord);
    var_v1 = 0;

    if (ghostRecord->checksum != Save_CalculateGhostRecordChecksum(ghostRecord) * 1) {
        Save_InitGhostRecord(ghostRecord, true);
        Save_WriteGhostRecord(ghostRecord);
        Save_InitGhostData(ghostData, true);
        Save_WriteGhostData(ghostData);
        var_v1 = 1;
    }

    if (ghostInfo != NULL) {
        func_i2_80101590(ghostRecord, ghostInfo);
    }
    if ((var_v1 == 0) && (ghostRecord->encodedCourseIndex == 0)) {
        var_v1 = 2;
    }
    return var_v1;
}

void func_i2_80101590(GhostRecord* ghostRecord, GhostInfo* ghostInfo) {
    s32 i;

    ghostInfo->courseIndex = ghostRecord->encodedCourseIndex & 0x1F;

    ghostInfo->encodedCourseIndex = ghostRecord->encodedCourseIndex;
    ghostInfo->raceTime = ghostRecord->raceTime;
    ghostInfo->replayChecksum = ghostRecord->replayChecksum;
    ghostInfo->ghostType = ghostRecord->ghostType;
    ghostInfo->unk_12 = ghostRecord->unk_10;

    for (i = 0; i < 9; i++) {
        ghostInfo->trackName[i] = ghostRecord->trackName[i];
    }
    ghostInfo->unk_1D = ghostRecord->unk_20;
}

void Save_SaveGhostRecord(Ghost*);
void Save_SaveGhostData(Ghost*);

s32 Save_SaveGhost(s32 courseIndex, Ghost* ghost) {
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    Save_SaveGhostRecord(ghost);
    Save_WriteGhostRecord(ghostRecord);
    Save_SaveGhostData(ghost);
    Save_WriteGhostData(ghostData);
    return 0;
}

void Save_SaveDeathRace(SaveDeathRace*);

s32 Save_SaveDeathRaceProfiles(void) {
    u16 checksum;
    s32 i;
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;

    Save_SaveDeathRace(&profileSaves[0].deathRace);
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

void Save_InitCourseRecord(SaveCourseRecords*, bool);

s32 func_i2_801017B8(s32 courseIndex) {
    u16 checksum;
    s32 i;
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;

    Save_InitCourseRecord(&profileSaves[0].courses[courseIndex], true);
    profileSaves[1].courses[courseIndex] = profileSaves[0].courses[courseIndex];

    checksum = Save_CalculateSaveCourseRecordChecksum(profileSaves, courseIndex);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveCourseRecord(profileSaves, i, courseIndex, checksum);
    }

    Save_LoadCourseRecord(profileSaves, courseIndex);

    return 0;
}

s32 Save_InitGhost(s32 courseIndex) {
    s32 i;
    Ghost* ghost;
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    for (i = 0, ghost = gGhosts; i < 3; i++, ghost++) {
        if (ghost->encodedCourseIndex == gCourseInfos[courseIndex].encodedCourseIndex) {
            ghost->encodedCourseIndex = 0;
        }
    }
    Save_InitGhostRecord(ghostRecord, true);
    Save_WriteGhostRecord(ghostRecord);
    Save_InitGhostData(ghostData, true);
    Save_WriteGhostData(ghostData);
    return 0;
}

void Save_InitSaveSettings(SaveSettings*, bool);
void Save_InitEditCup(SaveEditCup*, bool);
void Save_InitDeathRace(SaveDeathRace*, bool);
void Save_InitGhostData(GhostData*, bool);
void Save_InitCharacterSave(CharacterSave*, bool);
void Save_LoadSaveSettings(ProfileSave*, bool);
void Save_LoadEditCup(ProfileSave*, bool);

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
        Save_LoadSaveSettings(saveContext->profileSaves, false);
        spB7 = saveContext->profileSaves[0].saveSettings.unk_09;
        Save_LoadEditCup(saveContext->profileSaves, false);
        editCup = saveContext->profileSaves[0].editCup;
    }

    for (i = 0, ptr = (u64*) saveContext; i < (s32) (sizeof(SaveContext) / sizeof(u64)); i++, ptr++) {
        *ptr = 0;
    }

    for (i = 0, profileSave = saveContext->profileSaves; i < 2; i++, profileSave++) {
        Save_InitSaveSettings(&profileSave->saveSettings, false);
        Save_InitDeathRace(&profileSave->deathRace, false);

        for (j = 0, courseRecord = profileSave->courses; j < 24; j++, courseRecord++) {
            Save_InitCourseRecord(courseRecord, false);
        }

        Save_InitEditCup(&profileSave->editCup, false);
    }

    Save_InitGhostRecord(&saveContext->ghostRecord, false);
    Save_InitGhostData(&saveContext->ghostData, false);

    for (i = 0, characterSave = saveContext->characterSaves; i < 24; i++, characterSave++) {
        Save_InitCharacterSave(characterSave, false);
    }

    // Restore the n64dd related save data
    if ((arg1 != 0) && (arg1 == 1)) {
        saveContext->profileSaves[0].saveSettings.unk_09 = saveContext->profileSaves[1].saveSettings.unk_09 = spB7;
        saveContext->profileSaves[0].editCup = saveContext->profileSaves[1].editCup = editCup;
    }
}

void Save_InitSaveSettings(SaveSettings* saveSettings, bool shouldClear) {
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

void Save_InitEditCup(SaveEditCup* editCup, bool shouldClear) {
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

    arg0->unk_00.character = CAPTAIN_FALCON;
    arg0->unk_00.customType = CUSTOM_MACHINE_DEFAULT;
    arg0->unk_00.frontType = 0;
    arg0->unk_00.rearType = 0;
    arg0->unk_00.wingType = 0;
    arg0->unk_00.logo = 0;
    arg0->unk_00.number = 0;
    arg0->unk_00.decal = 0;
    arg0->unk_00.bodyR = 0;
    arg0->unk_00.bodyG = 0;
    arg0->unk_00.bodyB = 0;
    arg0->unk_00.numberR = 0;
    arg0->unk_00.numberG = 0;
    arg0->unk_00.numberB = 0;
    arg0->unk_00.decalR = 0;
    arg0->unk_00.decalG = 0;
    arg0->unk_00.decalB = 0;
    arg0->unk_00.cockpitR = 0;
    arg0->unk_00.cockpitG = 0;
    arg0->unk_00.cockpitB = 0;
}

void Save_InitDeathRace(SaveDeathRace* deathRace, bool shouldClear) {
    s32 i;

    if (shouldClear) {
        Save_ClearData(deathRace, sizeof(SaveDeathRace));
    }

    for (i = 0; i < 1; i++) {
        deathRace->timeRecord[i] = MAX_TIMER;
    }
}

void Save_InitCourseRecord(SaveCourseRecords* courseRecords, bool shouldClear) {
    s32 i;
    s32 j;

    if (shouldClear) {
        Save_ClearData(courseRecords, sizeof(SaveCourseRecords));
    }

    for (i = 0; i < 5; i++) {
        courseRecords->timeRecord[i] = MAX_TIMER;
        courseRecords->engines[i] = 0.5f;
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

void Save_InitGhostRecord(GhostRecord* ghostRecord, bool shouldClear) {
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

void Save_InitGhostData(GhostData* ghostData, bool shouldClear) {
    s32 i;

    if (shouldClear) {
        Save_ClearData(ghostData, sizeof(GhostData));
    }

    // clang-format off
    for (i = 0; i < 3; i++) { \
        ghostData->replayInfo.lapTimes[i] = 0;
    }
    // clang-format on

    ghostData->replayInfo.end = 0;
    ghostData->replayInfo.size = 0;
}

void Save_InitCharacterSave(CharacterSave* characterSave, bool shouldClear) {
    s32 i;

    if (shouldClear) {
        Save_ClearData(characterSave, sizeof(CharacterSave));
    }

    for (i = 0; i < 30; i++) {
        characterSave->characterEngine[i] = 0.5f;
    }
}

void Save_InitCupSave(CupSave* cupSave, bool shouldClear) {
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

void Save_SaveSettings(SaveSettings* saveSettings) {
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

void func_i2_80102110(MachineInfo* machineInfo, unk_80141C88_unk_1D* arg1) {

    arg1->unk_00.character = machineInfo->character;
    arg1->unk_00.customType = machineInfo->customType;
    arg1->unk_00.frontType = machineInfo->frontType;
    arg1->unk_00.rearType = machineInfo->rearType;
    arg1->unk_00.wingType = machineInfo->wingType;
    arg1->unk_00.logo = machineInfo->logo;
    arg1->unk_00.number = machineInfo->number;
    arg1->unk_00.decal = machineInfo->decal;
    arg1->unk_00.bodyR = machineInfo->bodyR;
    arg1->unk_00.bodyG = machineInfo->bodyG;
    arg1->unk_00.bodyB = machineInfo->bodyB;
    arg1->unk_00.numberR = machineInfo->numberR;
    arg1->unk_00.numberG = machineInfo->numberG;
    arg1->unk_00.numberB = machineInfo->numberB;
    arg1->unk_00.decalR = machineInfo->decalR;
    arg1->unk_00.decalG = machineInfo->decalG;
    arg1->unk_00.decalB = machineInfo->decalB;
    arg1->unk_00.cockpitR = machineInfo->cockpitR;
    arg1->unk_00.cockpitG = machineInfo->cockpitG;
    arg1->unk_00.cockpitB = machineInfo->cockpitB;
}

void Save_SaveDeathRace(SaveDeathRace* deathRace) {
    CourseInfo* var_a1 = &gCourseInfos[54];
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

void Save_SaveCourseRecord(SaveCourseRecords* courseRecords, s32 courseIndex) {
    CourseInfo* courseInfo;
    s32 i;
    s32 j;

    courseInfo = &gCourseInfos[courseIndex];

    for (i = 0; i < 5; i++) {
        courseRecords->timeRecord[i] = courseInfo->timeRecord[i];
        courseRecords->engines[i] = courseInfo->recordEngines[i];
        func_i2_80102110(&courseInfo->recordMachineInfos[i], &courseRecords->unk_50[i]);
        for (j = 0; j < 4; j++) {
            courseRecords->name[i][j] = courseInfo->recordNames[i][j];
        }
    }
    courseRecords->maxSpeed = courseInfo->maxSpeed;
    courseRecords->bestTime = courseInfo->bestTime;
    func_i2_80102110(&courseInfo->maxSpeedMachine, &courseRecords->unk_F0);
    courseRecords->unk_02 = 0;

    // clang-format off
    for (i = 0; i < 8; i++) { \
        courseRecords->unk_48[i] = 0;
    }
    // clang-format on
}

void Save_SaveEditCup(SaveEditCup* editCup) {
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

void Save_SaveGhostRecord(Ghost* ghost) {
    s32 i;
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;

    ghostRecord->replayChecksum = ghost->replayChecksum;
    ghostRecord->ghostType = ghost->ghostType;
    ghostRecord->unk_10 = 0;
    ghostRecord->encodedCourseIndex = ghost->encodedCourseIndex;

    ghostRecord->raceTime = ghost->raceTime;
    ghostRecord->unk_20.unk_00.character = ghost->machineInfo.character;
    ghostRecord->unk_20.unk_00.customType = ghost->machineInfo.customType;
    ghostRecord->unk_20.unk_00.frontType = ghost->machineInfo.frontType;
    ghostRecord->unk_20.unk_00.rearType = ghost->machineInfo.rearType;
    ghostRecord->unk_20.unk_00.wingType = ghost->machineInfo.wingType;
    ghostRecord->unk_20.unk_00.logo = ghost->machineInfo.logo;
    ghostRecord->unk_20.unk_00.number = ghost->machineInfo.number;
    ghostRecord->unk_20.unk_00.decal = ghost->machineInfo.decal;
    ghostRecord->unk_20.unk_00.bodyR = ghost->machineInfo.bodyR;
    ghostRecord->unk_20.unk_00.bodyG = ghost->machineInfo.bodyG;
    ghostRecord->unk_20.unk_00.bodyB = ghost->machineInfo.bodyB;
    ghostRecord->unk_20.unk_00.numberR = ghost->machineInfo.numberR;
    ghostRecord->unk_20.unk_00.numberG = ghost->machineInfo.numberG;
    ghostRecord->unk_20.unk_00.numberB = ghost->machineInfo.numberB;
    ghostRecord->unk_20.unk_00.decalR = ghost->machineInfo.decalR;
    ghostRecord->unk_20.unk_00.decalG = ghost->machineInfo.decalG;
    ghostRecord->unk_20.unk_00.decalB = ghost->machineInfo.decalB;
    ghostRecord->unk_20.unk_00.cockpitR = ghost->machineInfo.cockpitR;
    ghostRecord->unk_20.unk_00.cockpitG = ghost->machineInfo.cockpitG;
    ghostRecord->unk_20.unk_00.cockpitB = ghost->machineInfo.cockpitB;

    for (i = 0; i < 9; i++) {
        ghostRecord->trackName[i] = '\0';
    }

    for (i = 0; i < 5; i++) {
        ghostRecord->unk_12[i] = 0;
    }
}

void Save_SaveGhostData(Ghost* ghost) {
    s32 i;
    u8* var_a1;
    s8* var_v1;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    for (i = 0; i < 3; i++) {
        ghostData->replayInfo.lapTimes[i] = ghost->lapTimes[i];
    }

    ghostData->replayInfo.end = ghost->replayEnd;
    ghostData->replayInfo.size = ghost->replaySize;

    var_v1 = ghost->replayData;
    var_a1 = ghostData->replayData;

    for (i = 0; i < 16200; i++) {
        *var_a1++ = *var_v1++;
    }

    ghostData->replayInfo.unk_02 = 0;
    ghostData->replayInfo.unk_18 = 0;
    ghostData->replayInfo.unk_1C = 0;
}

extern f32 gCharacterLastEngine[30];

void Save_SaveCharacterSave(CharacterSave* characterSave) {
    s32 i;

    for (i = 0; i < 30; i++) {
        characterSave->characterEngine[i] = gCharacterLastEngine[i];
    }

    characterSave->unk_02 = 0;
    characterSave->unk_04 = 0;
}

void Save_LoadDeathRace(ProfileSave*);
void func_i2_80102A7C(unk_80141C88_unk_1D*, MachineInfo*);

void Save_Load(SaveContext* saveContext) {
    s32 i;
    s32 j;
    CourseInfo* courseInfo;
    Ghost* ghost;
    unk_80141C88_unk_1D sp60;

    for (i = 0, courseInfo = gCourseInfos; i < ARRAY_COUNT(gCourseInfos); i++, courseInfo++) {
        if (i < 24) {
            Save_LoadCourseRecord(saveContext->profileSaves, i);
        } else {
            func_i2_80101C78(&sp60);

            for (j = 0; j < 5; j++) {
                courseInfo->timeRecord[j] = MAX_TIMER;
                courseInfo->recordEngines[j] = 0.5f;
                func_i2_80102A7C(&sp60, &courseInfo->recordMachineInfos[j]);
            }

            courseInfo->maxSpeed = 0.0f;

            func_i2_80102A7C(&sp60, &courseInfo->maxSpeedMachine);
            if (i == 54) {
                Save_LoadDeathRace(saveContext->profileSaves);
            }
        }
    }

    Save_LoadSaveSettings(saveContext->profileSaves, true);

    for (i = 0; i < 30; i++) {
        D_i2_80111848[i] = 0;
    }

    Save_LoadGhostData(&saveContext->ghostRecord, &saveContext->ghostData, gGhosts, true);

    for (i = 0, ghost = gGhosts; i < 3; i++, ghost++) {
        ghost->encodedCourseIndex = 0;
    }
}

void Save_LoadSaveSettings(ProfileSave* profileSaves, bool arg1) {
    u16 checksum;
    s32 invalidSaveCount;
    s32 invalidSaveIndex;
    s32 i;
    s32 backupSaveIndex;
    ProfileSave* profileSave;
    SaveSettings* saveSettings;

    invalidSaveCount = 0;

    for (i = 0, profileSave = profileSaves; i < 2; i++) {
        if (profileSave->saveSettings.checksum != Save_CalculateSaveSettingsChecksum(profileSave) * 1) {
            invalidSaveCount++;
            invalidSaveIndex = i;
        }
        profileSave++;
    }

    if (invalidSaveCount == 2) {
        Save_InitSaveSettings(&profileSaves[0].saveSettings, true);
        profileSaves[1].saveSettings = profileSaves[0].saveSettings;

        checksum = Save_CalculateSaveSettingsChecksum(profileSaves);

        for (i = 0; i < 2; i++) {
            Save_WriteSaveSettings(profileSaves, i, checksum);
        }
    } else if (invalidSaveCount == 1) {
        backupSaveIndex = (invalidSaveIndex == 0) ? 1 : 0;

        (profileSaves + invalidSaveIndex)->saveSettings = (profileSaves + backupSaveIndex)->saveSettings;

        Save_WriteSaveSettings(profileSaves, invalidSaveIndex, Save_CalculateSaveSettingsChecksum(profileSaves));
    }

    if (!arg1) {
        return;
    }

    saveSettings = &profileSaves->saveSettings;

    gSettingVsHandicap = ((u8) (saveSettings->settings >> 4) & 0xFF) & 0xF;
    if (saveSettings->settings & 1) {
        gSettingVsCom = 1;
    } else {
        gSettingVsCom = 0;
    }
    if (saveSettings->settings & 2) {
        gSettingVsSlot = 1;
    } else {
        gSettingVsSlot = 0;
    }
    if (saveSettings->settings & 4) {
        gSettingSoundMode = 1;
    } else {
        gSettingSoundMode = 0;
    }
    if (saveSettings->settings & 8) {
        gSettingEverythingUnlocked = 1;
    } else {
        gSettingEverythingUnlocked = 0;
    }

    for (i = JACK_CUP; i <= JOKER_CUP; i++) {
        gCupNumDifficultiesCleared[i] = saveSettings->cupDifficultiesCleared[i];
    }

    func_8007E2B4();

    // clang-format off
    for (i = 0; i < 30; i++) { \
        D_i2_80111848[i] = 0;
    }
    // clang-format on

    if (saveSettings->unk_09 & 1) {
        D_i2_80111848[0] = 1;
    }
    if (saveSettings->unk_09 & 2) {
        D_i2_80111848[3] = 1;
    }
    if (saveSettings->unk_09 & 4) {
        D_i2_80111848[4] = 1;
    }
}

void func_i2_80102A7C(unk_80141C88_unk_1D* arg0, MachineInfo* arg1) {

    arg1->character = arg0->unk_00.character;
    arg1->customType = arg0->unk_00.customType;
    arg1->frontType = arg0->unk_00.frontType;
    arg1->rearType = arg0->unk_00.rearType;
    arg1->wingType = arg0->unk_00.wingType;
    arg1->logo = arg0->unk_00.logo;
    arg1->number = arg0->unk_00.number;
    arg1->decal = arg0->unk_00.decal;
    arg1->bodyR = arg0->unk_00.bodyR;
    arg1->bodyG = arg0->unk_00.bodyG;
    arg1->bodyB = arg0->unk_00.bodyB;
    arg1->numberR = arg0->unk_00.numberR;
    arg1->numberG = arg0->unk_00.numberG;
    arg1->numberB = arg0->unk_00.numberB;
    arg1->decalR = arg0->unk_00.decalR;
    arg1->decalG = arg0->unk_00.decalG;
    arg1->decalB = arg0->unk_00.decalB;
    arg1->cockpitR = arg0->unk_00.cockpitR;
    arg1->cockpitG = arg0->unk_00.cockpitG;
    arg1->cockpitB = arg0->unk_00.cockpitB;
}

void Save_LoadDeathRace(ProfileSave* profileSaves) {
    u16 checksum;
    s32 invalidSaveCount;
    s32 backupSaveIndex;
    s32 invalidSaveIndex;
    CourseInfo* courseInfo;
    SaveDeathRace* deathRaceSave;
    ProfileSave* profileSave;
    s32 i;

    invalidSaveCount = 0;

    for (i = 0, profileSave = profileSaves; i < 2; i++) {
        if (profileSave->deathRace.checksum != Save_CalculateSaveDeathRaceChecksum(profileSave) * 1) {
            invalidSaveCount++;
            invalidSaveIndex = i;
        }
        profileSave++;
    }

    if (invalidSaveCount == 2) {
        Save_InitDeathRace(&profileSaves[0].deathRace, true);
        profileSaves[1].deathRace = profileSaves[0].deathRace;

        checksum = Save_CalculateSaveDeathRaceChecksum(profileSaves);

        for (i = 0; i < 2; i++) {
            Save_WriteSaveDeathRace(profileSaves, i, checksum);
        }
    } else if (invalidSaveCount == 1) {
        backupSaveIndex = (invalidSaveIndex == 0) ? 1 : 0;

        (profileSaves + invalidSaveIndex)->deathRace = (profileSaves + backupSaveIndex)->deathRace;

        Save_WriteSaveDeathRace(profileSaves, invalidSaveIndex, Save_CalculateSaveDeathRaceChecksum(profileSaves));
    }
    courseInfo = &gCourseInfos[54];
    deathRaceSave = &profileSaves->deathRace;
    for (i = 0; i < 1; i++) {
        courseInfo->timeRecord[i] = deathRaceSave->timeRecord[i];
    }
}

void Save_LoadCourseRecord(ProfileSave* profileSaves, s32 courseIndex) {
    u16 checksum;
    s32 j;
    s32 i;
    s32 invalidSaveIndex;
    CourseInfo* courseInfo;
    ProfileSave* profileSave;
    s32 backupSaveIndex;
    SaveCourseRecords* courseRecord;

    j = 0;

    for (i = 0, profileSave = profileSaves; i < 2; i++) {
        if (profileSave->courses[courseIndex].checksum !=
            Save_CalculateSaveCourseRecordChecksum(profileSave, courseIndex)) {
            j++;
            invalidSaveIndex = i;
        }
        profileSave++;
    }

    if (j == 2) {
        Save_InitCourseRecord(&profileSaves[0].courses[courseIndex], true);
        profileSaves[1].courses[courseIndex] = profileSaves[0].courses[courseIndex];

        checksum = Save_CalculateSaveCourseRecordChecksum(profileSaves, courseIndex);

        for (i = 0; i < 2; i++) {
            Save_WriteSaveCourseRecord(profileSaves, i, courseIndex, checksum);
        }

    } else if (j == 1) {
        backupSaveIndex = (invalidSaveIndex == 0) ? 1 : 0;

        (profileSaves + invalidSaveIndex)->courses[courseIndex] =
            (profileSaves + backupSaveIndex)->courses[courseIndex];

        Save_WriteSaveCourseRecord(profileSaves, invalidSaveIndex, courseIndex,
                                   Save_CalculateSaveCourseRecordChecksum(profileSaves, courseIndex));
    }

    courseRecord = &profileSaves->courses[courseIndex];
    courseInfo = &gCourseInfos[courseIndex];

    for (i = 0; i < 5; i++) {
        courseInfo->timeRecord[i] = courseRecord->timeRecord[i];
        courseInfo->recordEngines[i] = courseRecord->engines[i];
        func_i2_80102A7C(&courseRecord->unk_50[i], &courseInfo->recordMachineInfos[i]);
        for (j = 0; j < 4; j++) {
            courseInfo->recordNames[i][j] = courseRecord->name[i][j];
        }
    }
    courseInfo->maxSpeed = courseRecord->maxSpeed;
    courseInfo->bestTime = courseRecord->bestTime;
    func_i2_80102A7C(&courseRecord->unk_F0, &courseInfo->maxSpeedMachine);
}

void Save_LoadGhostRecord(GhostRecord* ghostRecord, GhostData* ghostData, Ghost* ghost, bool arg3) {

    if (arg3) {
        if (ghostRecord->checksum != Save_CalculateGhostRecordChecksum(ghostRecord) * 1) {
            Save_InitGhostRecord(ghostRecord, true);
            Save_WriteGhostRecord(ghostRecord);
            Save_InitGhostData(ghostData, true);
            Save_WriteGhostData(ghostData);
        }
    }

    ghost->replayChecksum = ghostRecord->replayChecksum;
    ghost->ghostType = ghostRecord->ghostType;
    ghost->encodedCourseIndex = ghostRecord->encodedCourseIndex;
    ghost->raceTime = ghostRecord->raceTime;
    func_i2_80102A7C(&ghostRecord->unk_20, &ghost->machineInfo);
}

void Save_LoadGhostData(GhostRecord* ghostRecord, GhostData* ghostData, Ghost* ghost, bool arg3) {
    s32 i;
    u8* var_v0;
    s8* var_v1;
    GhostRecord* ghostRecord2 = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData2 = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    if (arg3) {
        if (ghostData->replayInfo.checksum != Save_CalculateGhostDataChecksum(ghostData) * 1) {
            Save_InitGhostRecord(ghostRecord2, true);
            Save_WriteGhostRecord(ghostRecord2);
            Save_InitGhostData(ghostData2, true);
            Save_WriteGhostData(ghostData2);
            ghost->encodedCourseIndex = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        ghost->lapTimes[i] = ghostData->replayInfo.lapTimes[i];
    }

    ghost->replayEnd = ghostData->replayInfo.end;
    ghost->replaySize = ghostData->replayInfo.size;

    var_v0 = ghostData->replayData;
    var_v1 = ghost->replayData;

    for (i = 0; i < 16200; i++) {
        *var_v1++ = *var_v0++;
    }
}

void Save_LoadEditCup(ProfileSave* profileSaves, bool arg1) {
    SaveEditCup* editCup;
    s32 i;
    s32 j;
    s32 invalidSaveIndex;
    u16 checksum;
    s32 invalidSaveCount;
    s32 backupSaveIndex;
    ProfileSave* profileSave;

    invalidSaveCount = 0;

    for (i = 0, profileSave = profileSaves; i < 2; i++) {
        if (profileSave->editCup.checksum != Save_CalculateSaveEditCupChecksum(profileSave) * 1) {
            invalidSaveCount++;
            invalidSaveIndex = i;
        }
        profileSave++;
    }

    if (invalidSaveCount == 2) {
        Save_InitEditCup(&profileSaves[0].editCup, true);
        profileSaves[1].editCup = profileSaves[0].editCup;

        checksum = Save_CalculateSaveEditCupChecksum(profileSaves);
        for (i = 0; i < 2; i++) {
            Save_WriteSaveEditCup(profileSaves, i, checksum);
        }
    } else if (invalidSaveCount == 1) {
        backupSaveIndex = (invalidSaveIndex == 0) ? 1 : 0;

        (profileSaves + invalidSaveIndex)->editCup = (profileSaves + backupSaveIndex)->editCup;

        Save_WriteSaveEditCup(profileSaves, invalidSaveIndex, Save_CalculateSaveEditCupChecksum(profileSaves));
    }

    if (!arg1) {
        return;
    }

    editCup = &profileSaves[0].editCup;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 9; j++) {
            gEditCupTrackNames[i][j] = editCup->editCupTrackNames[i][j];
        }
    }
}

extern f32 gCharacterLastEngine[];

void Save_LoadCharacterSave(CharacterSave* characterSave, s32 courseIndex) {
    s32 i;

    if (characterSave->checksum != Save_CalculateCharacterSaveChecksum(characterSave) * 1) {
        Save_InitCharacterSave(characterSave, true);
        Save_WriteCharacterSave(characterSave, courseIndex);
    }

    for (i = 0; i < 30; i++) {
        gCharacterLastEngine[i] = characterSave->characterEngine[i];
    }
}

void Save_LoadCupSave(CupSave* cupSave, u8* arg1) {
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    u8 temp_v1;
    s8* var_a0;
    s32 temp;

    if (cupSave->checksum != Save_CalculateCupSaveChecksum(cupSave) * 1) {
        Save_InitCupSave(cupSave, true);
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
    return Save_CalculateChecksum(&ghostData->replayInfo.unk_02, sizeof(GhostData) - sizeof(u16));
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

void Save_RomCopyGhostRecord(GhostRecord*, s32);

s32 Save_LoadStaffGhostRecord(GhostInfo* arg0, s32 courseIndex) {
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;

    if (!((courseIndex >= COURSE_MUTE_CITY) && (courseIndex < COURSE_EDIT_1))) {
        return 2;
    }
    Save_RomCopyGhostRecord(ghostRecord, courseIndex);
    if (arg0 != NULL) {
        func_i2_80101590(ghostRecord, arg0);
    }
    return 0;
}

void Save_RomCopyGhostRecord(GhostRecord* ghostRecord, s32 courseIndex) {
    Dma_RomCopyAsync(SEGMENT_ROM_START(segment_27F200) + D_i2_80106DF0[courseIndex][0], ghostRecord,
                     sizeof(GhostRecord));
}

void Save_RomCopyGhostData(GhostData*, s32);

s32 Save_LoadStaffGhost(s32 courseIndex) {
    s32 ghostIndex;
    GhostInfo sp24;
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

    Save_LoadStaffGhostRecord(&sp24, courseIndex);
    if (func_i2_80100B38(&sp24)) {
        return 0;
    }

    ghostIndex = func_i2_801005CC(courseIndex);
    Save_RomCopyGhostData(ghostData, courseIndex);
    Save_LoadGhostRecord(ghostRecord, ghostData, &gGhosts[ghostIndex], false);
    Save_LoadGhostData(ghostRecord, ghostData, &gGhosts[ghostIndex], false);

    return 0;
}

void Save_RomCopyGhostData(GhostData* ghostData, s32 courseIndex) {
    uintptr_t* offsets = D_i2_80106DF0[courseIndex];
    RomOffset romOffset = SEGMENT_ROM_START(segment_27F200);

    Dma_RomCopyAsync(romOffset + offsets[1], &ghostData->replayInfo, sizeof(GhostReplayInfo));
    Dma_RomCopyAsync(romOffset + offsets[2], ghostData->replayData, ALIGN_2(ghostData->replayInfo.size + 1));
}

void func_i2_801039BC(s32 arg0) {
    s32 i;
    s32 j;

    // FAKE! this needs to be fixed by caller function
    if (arg0) {}

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            ((ProfileSave*) gSaveBuffer)[i].saveSettings.fileName[j] = D_i2_8010ADE8[j];
            Save_WriteSaveSettings(((ProfileSave*) gSaveBuffer), i, 0x1234);
        }
    }
}
