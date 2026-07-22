#include "global.h"
#include "fzx_game.h"
#include "fzx_save.h"
#include "fzx_course.h"
#include "fzx_machine.h"
#include ASSET_HEADER(staff_ghost_records.h)

OSIoMesg sSramIoMesg;
OSPiHandle sSramPiHandle;
OSPiHandle* gSramPiHandlePtr;
s16 gSettingSoundMode;
u8 D_i2_80111848[30];
#ifdef EXPANSION_KIT
u16 sDDStaffGhostCompletion;
#endif

uintptr_t D_i2_80106DF0[][3] = {
    { &aMuteCity1StaffGhostRecord, &aMuteCity1StaffGhostReplayInfo, aMuteCity1StaffGhostData },
    { &aSilence1StaffGhostRecord, &aSilence1StaffGhostReplayInfo, aSilence1StaffGhostData },
    { &aSandOcean1StaffGhostRecord, &aSandOcean1StaffGhostReplayInfo, aSandOcean1StaffGhostData },
    { &aDevilsForest1StaffGhostRecord, &aDevilsForest1StaffGhostReplayInfo, aDevilsForest1StaffGhostData },
    { &aBigBlue1StaffGhostRecord, &aBigBlue1StaffGhostReplayInfo, aBigBlue1StaffGhostData },
    { &aPortTown1StaffGhostRecord, &aPortTown1StaffGhostReplayInfo, aPortTown1StaffGhostData },
    { &aSectorAlphaStaffGhostRecord, &aSectorAlphaStaffGhostReplayInfo, aSectorAlphaStaffGhostData },
    { &aRedCanyon1StaffGhostRecord, &aRedCanyon1StaffGhostReplayInfo, aRedCanyon1StaffGhostData },
    { &aDevilsForest2StaffGhostRecord, &aDevilsForest2StaffGhostReplayInfo, aDevilsForest2StaffGhostData },
    { &aMuteCity2StaffGhostRecord, &aMuteCity2StaffGhostReplayInfo, aMuteCity2StaffGhostData },
    { &aBigBlue2StaffGhostRecord, &aBigBlue2StaffGhostReplayInfo, aBigBlue2StaffGhostData },
    { &aWhiteLand1StaffGhostRecord, &aWhiteLand1StaffGhostReplayInfo, aWhiteLand1StaffGhostData },
    { &aFireFieldStaffGhostRecord, &aFireFieldStaffGhostReplayInfo, aFireFieldStaffGhostData },
    { &aSilence2StaffGhostRecord, &aSilence2StaffGhostReplayInfo, aSilence2StaffGhostData },
    { &aSectorBetaStaffGhostRecord, &aSectorBetaStaffGhostReplayInfo, aSectorBetaStaffGhostData },
    { &aRedCanyon2StaffGhostRecord, &aRedCanyon2StaffGhostReplayInfo, aRedCanyon2StaffGhostData },
    { &aWhiteLand2StaffGhostRecord, &aWhiteLand2StaffGhostReplayInfo, aWhiteLand2StaffGhostData },
    { &aMuteCity3StaffGhostRecord, &aMuteCity3StaffGhostReplayInfo, aMuteCity3StaffGhostData },
    { &aRainbowRoadStaffGhostRecord, &aRainbowRoadStaffGhostReplayInfo, aRainbowRoadStaffGhostData },
    { &aDevilsForest3StaffGhostRecord, &aDevilsForest3StaffGhostReplayInfo, aDevilsForest3StaffGhostData },
    { &aSpacePlantStaffGhostRecord, &aSpacePlantStaffGhostReplayInfo, aSpacePlantStaffGhostData },
    { &aSandOcean2StaffGhostRecord, &aSandOcean2StaffGhostReplayInfo, aSandOcean2StaffGhostData },
    { &aPortTown2StaffGhostRecord, &aPortTown2StaffGhostReplayInfo, aPortTown2StaffGhostData },
    { &aBigHandStaffGhostRecord, &aBigHandStaffGhostReplayInfo, aBigHandStaffGhostData },
};

extern char gEditCupTrackNames[][9];

const char D_i2_8010ADE0[] = { 'F', '-', 'Z', 'E', 'R', 'O', ' ', 'X' };
const char D_i2_8010ADE8[] = { 'D', 'A', 'I', '&', 'E', 'A', 'D', '!' };

void Save_ReadGhostRecord(GhostRecord* ghostRecord) {
    Sram_ReadWrite(OS_READ, (uintptr_t) &gSaveContext.ghostSave.record - (uintptr_t) &gSaveContext, ghostRecord,
                   sizeof(GhostRecord));
}

void Save_ReadGhostData(GhostData* ghostData) {
    Sram_ReadWrite(OS_READ, (uintptr_t) &gSaveContext.ghostSave.data - (uintptr_t) &gSaveContext, ghostData,
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
#ifndef EXPANSION_KIT
            sp18 = Save_LoadPlayerGhost_impl(courseIndex, encodedCourseIndex, -1);
#else
            sp18 = func_i2_800A5F58(courseIndex, encodedCourseIndex);
#endif
            break;
        case GHOST_STAFF:
            sp18 = Save_LoadStaffGhost_impl(courseIndex, encodedCourseIndex);
            break;
    }
    return sp18;
}

#ifdef EXPANSION_KIT
typedef struct unk_SaveLoadGhost {
    s16 unk_00;
    s16 unk_02;
    s32 raceTime;
} unk_SaveLoadGhost;

s32 func_i2_800A5F58(s32 courseIndex, s32 encodedCourseIndex) {
    s32 i;
    s32 j;
    unk_SaveLoadGhost* var_s3;
    s32 temp_t3;
    s32 pad[2];
    bool var_v1;
    GhostInfo sp164;
    GhostRecord spA4[3];
    unk_SaveLoadGhost sp6C[7];
    unk_SaveLoadGhost sp64;
    s16 sp5C[3];

    for (i = 0, var_s3 = sp6C; i < 7; i++) {
        var_s3->unk_00 = 0;
        var_s3++;
    }

    for (i = 0; i < 3; i++) {
        sp5C[i] = 0;
    }

    var_s3 = sp6C;
    for (i = 0; i < 3; i++) {
        if (gGhosts[i].encodedCourseIndex == encodedCourseIndex && gGhosts[i].ghostType == GHOST_PLAYER) {
            var_s3->unk_00 = 1;
            var_s3->unk_02 = i;
            var_s3->raceTime = gGhosts[i].raceTime;
            var_s3++;
        }
    }

    if (1) {}

    Save_LoadGhostInfo(&sp164);

    if ((sp164.encodedCourseIndex == encodedCourseIndex) && (func_i2_80100B38(&sp164) == 0)) {
        var_s3->unk_00 = 2;
        var_s3->unk_02 = 0;
        var_s3->raceTime = sp164.raceTime;
        var_s3++;
    }

    DDSave_LoadCourseGhostRecords(courseIndex, spA4);

    for (i = 0; i < 3; i++) {
        func_i2_80101590(&spA4[i], &sp164);
        if (spA4[i].encodedCourseIndex == encodedCourseIndex && func_i2_80100B38(&sp164) == 0) {
            var_s3->unk_00 = 3;
            var_s3->unk_02 = i;
            var_s3->raceTime = spA4[i].raceTime;
            var_s3++;
        }
    }

    temp_t3 = var_s3 - sp6C;
    if (temp_t3 > 1) {
        for (i = 0; i < temp_t3 - 1; i++) {
            for (j = i + 1; j < temp_t3; j++) {
                var_v1 = false;
                if (sp6C[i].raceTime > sp6C[j].raceTime) {
                    var_v1 = true;
                } else if (sp6C[i].raceTime == sp6C[j].raceTime) {
                    if (sp6C[i].unk_00 > sp6C[j].unk_00) {
                        var_v1 = true;
                    } else if (sp6C[i].unk_00 == sp6C[j].unk_00) {
                        if (sp6C[i].unk_02 > sp6C[j].unk_02) {
                            var_v1 = true;
                        }
                    }
                }

                if (var_v1) {
                    sp64 = sp6C[i];
                    sp6C[i] = sp6C[j];
                    sp6C[j] = sp64;
                }
            }
        }
    }

    for (i = 0, var_s3 = sp6C; i < 3; i++) {
        if (var_s3->unk_00 == 1) {
            sp5C[i] = 1;
        }
        var_s3++;
    }

    for (i = 0, var_s3 = sp6C; i < 3; i++) {
        switch (var_s3->unk_00) {
            case 0:
            case 1:
                break;
            case 2:
                for (j = 0; j < 3; j++) {
                    if (sp5C[j] == 0) {
                        break;
                    }
                }
                sp5C[j] = 1;
                Save_LoadPlayerGhost_impl(courseIndex, encodedCourseIndex, j);
                break;
            case 3:
                for (j = 0; j < 3; j++) {
                    if (sp5C[j] == 0) {
                        break;
                    }
                }
                sp5C[j] = 1;
                gSaveContext.ghostSave.record = spA4[var_s3->unk_02];
                DDSave_LoadCourseGhostData(courseIndex, var_s3->unk_02, &gSaveContext.ghostSave.data);
                Save_LoadGhostRecord(&gSaveContext.ghostSave.record, &gSaveContext.ghostSave.data, &gGhosts[j], false);
                Save_LoadGhostData(&gSaveContext.ghostSave.record, &gSaveContext.ghostSave.data, &gGhosts[j], false);

                break;
            default:
                break;
        }
        var_s3++;
    }

    return 0;
}
#endif

s32 func_i2_801005CC_impl(s32 courseIndex, s32 encodedCourseIndex) {
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
#ifndef EXPANSION_KIT
        if (courseIndex != (ghost->encodedCourseIndex & 0x1F)) {
#else
        if (encodedCourseIndex != ghost->encodedCourseIndex) {
#endif
            var_v1 = i;
            var_a0 = ghost->raceTime;
            break;
        }
    }

    if (var_a0 != -1) {
        for (i = var_v1 + 1, ghost = &gGhosts[i]; i < 3; i++, ghost++) {
#ifndef EXPANSION_KIT
            if (courseIndex != (ghost->encodedCourseIndex & 0x1F)) {
#else
            if (encodedCourseIndex != ghost->encodedCourseIndex) {
#endif
                if (var_a0 < ghost->raceTime) {
                    var_a0 = ghost->raceTime;
                    var_v1 = i;
                }
            }
        }
    } else {
        for (i = 0, ghost = gGhosts; i < 3; i++, ghost++) {
#ifndef EXPANSION_KIT
            if (courseIndex == (ghost->encodedCourseIndex & 0x1F)) {
#else
            if (encodedCourseIndex == ghost->encodedCourseIndex) {
#endif
                if (var_a0 < ghost->raceTime) {
                    var_a0 = ghost->raceTime;
                    var_v1 = i;
                }
            }
        }
    }
    return var_v1;
}

s32 Save_LoadPlayerGhost_impl(s32 courseIndex, s32 encodedCourseIndex, s32 ghostIndex) {
#ifndef EXPANSION_KIT
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];
#else
    GhostRecord* ghostRecord = &gSaveContext.ghostSave.record;
    GhostData* ghostData = &gSaveContext.ghostSave.data;
#endif
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
        var_t0 = func_i2_801005CC_impl(courseIndex, encodedCourseIndex);

        if ((gGhosts[var_t0].encodedCourseIndex != 0) && (gGhosts[var_t0].ghostType == GHOST_PLAYER) &&
#ifndef EXPANSION_KIT
            (sp24.courseIndex == (gGhosts[var_t0].encodedCourseIndex & 0x1F)) &&
#else
            (sp24.encodedCourseIndex == gGhosts[var_t0].encodedCourseIndex) &&
#endif
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

bool func_i2_80100B38(GhostInfo* ghostInfo) {
    bool matchingGhostInfo;
    s32 i;
    Ghost* ghost = gGhosts;

    for (i = 0; i < 3; i++) {
        matchingGhostInfo = true;
        if (ghost->ghostType != ghostInfo->ghostType) {
            matchingGhostInfo = false;
        } else if (ghost->replayChecksum != ghostInfo->replayChecksum) {
            matchingGhostInfo = false;
        } else if (ghost->encodedCourseIndex != ghostInfo->encodedCourseIndex) {
            matchingGhostInfo = false;
        } else if (ghost->raceTime != ghostInfo->raceTime) {
            matchingGhostInfo = false;
        } else if (!func_i2_80100950(&ghost->machineInfo, &ghostInfo->unk_1D)) {
            matchingGhostInfo = false;
        }

        if (matchingGhostInfo) {
            break;
        }
        ghost++;
    }
    return matchingGhostInfo;
}

s32 Save_UpdateCharacterSave(s32 courseIndex) {
#ifndef EXPANSION_KIT
    CharacterSave* characterSave = ((CharacterSave*) gSaveBuffer) + courseIndex;
#else
    CharacterSave* characterSave = &gSaveContext.characterSaves[courseIndex];
#endif

    Save_ReadCharacterSave(characterSave, courseIndex);
    Save_LoadCharacterSave(characterSave, courseIndex);
    return 0;
}

s32 Save_UpdateCupSave(u8* cupCompletion) {
#ifndef EXPANSION_KIT
    CupSave* cupSave = (CupSave*) gSaveBuffer;
#else
    CupSave* cupSave = &gSaveContext.cupSave;
#endif

    Save_ReadCupSave(cupSave);
    Save_LoadCupSave(cupSave, cupCompletion);
#ifdef EXPANSION_KIT
    Save_ReadProfileSaves(gSaveContext.profileSaves);
    Save_LoadDDCups(gSaveContext.profileSaves, cupCompletion, NULL);
#endif
    return 0;
}

void Save_InitWrite(SaveContext* saveContext) {
    s32 i;
    s32 j;
    u16 checksum;
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
        checksum = Save_CalculateProfileSaveCourseRecordChecksum(saveContext->profileSaves, j);

        for (i = 0, profileSave = saveContext->profileSaves; i < 2; i++, profileSave++) {
            profileSave->courses[j].checksum = checksum;
        }
    }
    checksum = Save_CalculateSaveEditCupChecksum(saveContext->profileSaves);

    for (i = 0, profileSave = saveContext->profileSaves; i < 2; i++, profileSave++) {
        profileSave->editCup.checksum = checksum;
    }
    saveContext->ghostSave.record.checksum = Save_CalculateGhostRecordChecksum(&saveContext->ghostSave.record);
    saveContext->ghostSave.data.replayInfo.checksum = Save_CalculateGhostDataChecksum(&saveContext->ghostSave.data);

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

#ifndef EXPANSION_KIT
void Save_WriteSaveEditCup(ProfileSave* profileSaves, s32 profileIndex, u16 checksum) {
    ProfileSave* profileSave = &profileSaves[profileIndex];

    profileSave->editCup.checksum = checksum;
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.profileSaves[profileIndex].editCup - (uintptr_t) &gSaveContext,
                   &profileSave->editCup, sizeof(SaveEditCup));
}
#else
void Save_WriteSaveEditCup(void) {
}

void Save_WriteSaveDDCups(ProfileSave* profileSaves, s32 profileIndex, u16 checksum) {
    ProfileSave* profileSave = &profileSaves[profileIndex];

    profileSave->ddCups.checksum = checksum;
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.profileSaves[profileIndex].ddCups - (uintptr_t) &gSaveContext,
                   &profileSave->ddCups, sizeof(SaveDDCups));
}
#endif

void Save_WriteGhostRecord(GhostRecord* ghostRecord) {
    ghostRecord->checksum = Save_CalculateGhostRecordChecksum(ghostRecord);
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.ghostSave.record - (uintptr_t) &gSaveContext, ghostRecord,
                   sizeof(GhostRecord));
}

void Save_WriteGhostData(GhostData* ghostData) {
    ghostData->replayInfo.checksum = Save_CalculateGhostDataChecksum(ghostData);
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.ghostSave.data - (uintptr_t) &gSaveContext, ghostData,
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

s32 Save_SaveCourseRecordProfiles(s32 courseIndex) {
    u16 checksum;
    s32 i;
#ifndef EXPANSION_KIT
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;
#else
    ProfileSave* profileSaves = gSaveContext.profileSaves;
#endif

#if BUILD_REVISION >= REVISION_C
    if ((courseIndex >= COURSE_MUTE_CITY) && (courseIndex <= COURSE_BIG_HAND)) {
#endif
        Save_SaveCourseRecord(&profileSaves[0].courses[courseIndex], courseIndex);
        profileSaves[1].courses[courseIndex] = profileSaves[0].courses[courseIndex];

        checksum = Save_CalculateProfileSaveCourseRecordChecksum(profileSaves, courseIndex);

        for (i = 0; i < 2; i++) {
            Save_WriteSaveCourseRecord(profileSaves, i, courseIndex, checksum);
        }
#if BUILD_REVISION >= REVISION_D
    } else {
        SaveCourseRecords* saveCourseRecord;
        Save_SaveCourseRecord(gSaveContext.profileSaves[0].courses, courseIndex);
        gSaveContext.profileSaves[0].courses[0].checksum =
            Save_CalculateProfileSaveCourseRecordChecksum(gSaveContext.profileSaves, 0);
        saveCourseRecord = DDSave_GetCachedCourseRecord();
        *saveCourseRecord = gSaveContext.profileSaves[0].courses[0];
        DDSave_SaveCourseGhost(courseIndex);
    }
#elif BUILD_REVISION == REVISION_C
}
#endif

    return 0;
}

extern bool gRamDDCompatible;

#ifndef EXPANSION_KIT
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
#endif

s32 Save_UpdateCourseCharacterSave(s32 courseIndex) {
    s32 pad[2];
#ifndef EXPANSION_KIT
    CharacterSave* characterSave = ((CharacterSave*) gSaveBuffer) + courseIndex;
#else
    CharacterSave* characterSave = &gSaveContext.characterSaves[courseIndex];
#endif

    Save_SaveCharacterSave(characterSave);
    Save_WriteCharacterSave(characterSave, courseIndex);
    return 0;
}

s32 Save_UpdateCupCompletion(s32 difficulty, s32 cupType, s32 character) {
    s32 i;
#ifndef EXPANSION_KIT
    CupSave* cupSave = (CupSave*) gSaveBuffer;
#else
    CupSave* cupSave = &gSaveContext.cupSave;
#endif

#ifdef EXPANSION_KIT
    if (cupType == EDIT_CUP) {
        return 2;
    } else if (cupType == DD_1_CUP) {
        i = 0;
    } else if (cupType == DD_2_CUP) {
        i = 1;
    } else {
        i = -1;
    }

    if (i != -1) {
        ProfileSave* profileSaves = gSaveContext.profileSaves;
        s8 completion;
        u16 checksum;

        Save_ReadProfileSaves(profileSaves);
        Save_LoadDDCups(profileSaves, NULL, NULL);
        completion = profileSaves[0].ddCups.cupCompletion[character * 2 + i];
        completion |= 1 << (difficulty * 2);
        profileSaves[0].ddCups.cupCompletion[character * 2 + i] = completion;
        profileSaves[0].ddCups.staffGhostCompletion = sDDStaffGhostCompletion;
        profileSaves[1].ddCups = profileSaves[0].ddCups;
        i = 1;
        checksum = Save_CalculateSaveDDCupsChecksum(profileSaves);

        for (i = 0; i < 2; i++) {
            Save_WriteSaveDDCups(profileSaves, i, checksum);
        }
    } else {
#endif
        u16 cupCompletion;

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
#ifdef EXPANSION_KIT
    }
#endif

    return 0;
}

s32 Save_SaveSettingsProfiles(void) {
    u16 checksum;
    s32 i;
#ifndef EXPANSION_KIT
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;
#else
    ProfileSave* profileSaves = gSaveContext.profileSaves;
#endif

    Save_SaveSettings(&profileSaves[0].saveSettings);
    profileSaves[1].saveSettings = profileSaves[0].saveSettings;

    checksum = Save_CalculateSaveSettingsChecksum(profileSaves);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveSettings(profileSaves, i, checksum);
    }

    return 0;
}

s32 Save_LoadGhostInfo(GhostInfo* ghostInfo) {
    s32 pad;
    s32 var_v1;
#ifndef EXPANSION_KIT
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];
#else
    GhostRecord* ghostRecord = &gSaveContext.ghostSave.record;
    GhostData* ghostData = &gSaveContext.ghostSave.data;
#endif

    Save_ReadGhostRecord(ghostRecord);
    var_v1 = 0;

    if (ghostRecord->checksum != Save_CalculateGhostRecordChecksum(ghostRecord)) {
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

s32 Save_SaveGhost(s32 courseIndex, Ghost* ghost) {
#ifndef EXPANSION_KIT
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];
#else
    GhostRecord* ghostRecord = &gSaveContext.ghostSave.record;
    GhostData* ghostData = &gSaveContext.ghostSave.data;
#endif

    Save_SaveGhostRecord(ghost);
    Save_WriteGhostRecord(ghostRecord);
    Save_SaveGhostData(ghost);
    Save_WriteGhostData(ghostData);
    return 0;
}

s32 Save_SaveDeathRaceProfiles(void) {
    u16 checksum;
    s32 i;
#ifndef EXPANSION_KIT
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;
#else
    ProfileSave* profileSaves = gSaveContext.profileSaves;
#endif

    Save_SaveDeathRace(&profileSaves[0].deathRace);
    profileSaves[1].deathRace = profileSaves[0].deathRace;

    checksum = Save_CalculateSaveDeathRaceChecksum(profileSaves);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveDeathRace(profileSaves, i, checksum);
    }

    return 0;
}

s32 Save_Init(SaveContext* saveContext, s32 arg1) {
    Save_CreateNew(saveContext, arg1);
    Save_InitWrite(saveContext);
    Save_Load(saveContext);
    return 0;
}

s32 func_i2_801017B8(s32 courseIndex) {
    u16 checksum;
    s32 i;
#ifndef EXPANSION_KIT
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;
#else
    ProfileSave* profileSaves = gSaveContext.profileSaves;
#endif

    Save_InitCourseRecord(&profileSaves[0].courses[courseIndex], true);
    profileSaves[1].courses[courseIndex] = profileSaves[0].courses[courseIndex];

    checksum = Save_CalculateProfileSaveCourseRecordChecksum(profileSaves, courseIndex);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveCourseRecord(profileSaves, i, courseIndex, checksum);
    }

    Save_LoadCourseRecord(profileSaves, courseIndex);

    return 0;
}

s32 Save_InitGhost(s32 courseIndex) {
    s32 i;
    Ghost* ghost;
#ifndef EXPANSION_KIT
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];
#else
    GhostRecord* ghostRecord = &gSaveContext.ghostSave.record;
    GhostData* ghostData = &gSaveContext.ghostSave.data;
#endif

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

void Save_CreateNew(SaveContext* saveContext, s32 arg1) {
    s32 i;
    s32 j;
    u64* ptr;
    ProfileSave* profileSave;
    SaveCourseRecords* courseRecord;
    CharacterSave* characterSave;
    u8 spB7;
#ifndef EXPANSION_KIT
    SaveEditCup editCup;
    s32 pad;
#endif

    // Load current save and remember n64dd related data that will be restored
    if ((arg1 != 0) && (arg1 == 1)) {
        Save_ReadProfileSaves(saveContext->profileSaves);
        Save_LoadSaveSettings(saveContext->profileSaves, false);
        spB7 = saveContext->profileSaves[0].saveSettings.customUnlocks;
#ifndef EXPANSION_KIT
        Save_LoadEditCup(saveContext->profileSaves, false);
        editCup = saveContext->profileSaves[0].editCup;
#endif
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

    Save_InitGhostRecord(&saveContext->ghostSave.record, false);
    Save_InitGhostData(&saveContext->ghostSave.data, false);

    for (i = 0, characterSave = saveContext->characterSaves; i < 24; i++, characterSave++) {
        Save_InitCharacterSave(characterSave, false);
    }

    // Restore the n64dd related save data
    if ((arg1 != 0) && (arg1 == 1)) {
        saveContext->profileSaves[0].saveSettings.customUnlocks =
            saveContext->profileSaves[1].saveSettings.customUnlocks = spB7;
#ifndef EXPANSION_KIT
        saveContext->profileSaves[0].editCup = saveContext->profileSaves[1].editCup = editCup;
#endif
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
    saveSettings->customUnlocks = 0;
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

#ifdef EXPANSION_KIT
void Save_InitDDCups(SaveDDCups* ddCups, bool shouldClear) {
    s32 i;

    if (shouldClear) {
        Save_ClearData(ddCups, sizeof(SaveDDCups));
    }

    for (i = 0; i < 60; i++) {
        ddCups->cupCompletion[i] = 0;
    }
    ddCups->staffGhostCompletion = 0;
}
#endif

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
#ifndef EXPANSION_KIT
    ghostRecord->raceTime = 0;
#else
    ghostRecord->raceTime = MAX_TIMER;
#endif
    ghostRecord->unk_10 = 0;

    func_i2_80101C78(&ghostRecord->unk_20);

    for (i = 0; i < 9; i++) {
        ghostRecord->trackName[i] = 0;
    }
}

#ifdef EXPANSION_KIT
void Save_ClearGhostRecord(GhostRecord* ghostRecord) {
    Save_InitGhostRecord(ghostRecord, true);
    ghostRecord->checksum = Save_CalculateGhostRecordChecksum(ghostRecord);
}

void Save_ClearCourseRecord(SaveCourseRecords* courseRecords) {
    Save_InitCourseRecord(courseRecords, true);
    courseRecords->checksum = Save_CalculateSaveCourseRecordChecksum(courseRecords);
}
#endif

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
    if (gSettingEverythingUnlocked) {
        settingLowerFlags |= 8;
    }

    saveSettings->settings = settingHigherFlags | settingLowerFlags;

    for (i = JACK_CUP; i <= JOKER_CUP; i++) {
        saveSettings->cupDifficultiesCleared[i] = gCupNumDifficultiesCleared[i];
    }

    saveSettings->customUnlocks = 0;

    if (D_i2_80111848[CAPTAIN_FALCON] != 0) {
        saveSettings->customUnlocks |= 1;
    }
    if (D_i2_80111848[SAMURAI_GOROH] != 0) {
        saveSettings->customUnlocks |= 2;
    }
    if (D_i2_80111848[JODY_SUMMER] != 0) {
        saveSettings->customUnlocks |= 4;
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

#ifndef EXPANSION_KIT
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
#else
void Save_SaveEditCup(void) {
}
#endif

void Save_SaveGhostRecord(Ghost* ghost) {
#ifndef EXPANSION_KIT
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
#else
    GhostRecord* ghostRecord = &gSaveContext.ghostSave.record;
#endif
    s32 i;

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

#ifdef EXPANSION_KIT
    ghostRecord->checksum = Save_CalculateGhostRecordChecksum(&gSaveContext.ghostSave.record);
#endif
}

void Save_SaveGhostData(Ghost* ghost) {
    s32 i;
    u8* var_a1;
    s8* var_v1;
#ifndef EXPANSION_KIT
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];
#else
    GhostData* ghostData = &gSaveContext.ghostSave.data;
#endif

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

#ifdef EXPANSION_KIT
    ghostData->replayInfo.checksum = Save_CalculateGhostDataChecksum(&gSaveContext.ghostSave.data);
#endif
}

extern f32 gCharacterLastEngine[];

void Save_SaveCharacterSave(CharacterSave* characterSave) {
    s32 i;

    for (i = 0; i < 30; i++) {
        characterSave->characterEngine[i] = gCharacterLastEngine[i];
    }

    characterSave->unk_02 = 0;
    characterSave->unk_04 = 0;
}

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

#ifndef EXPANSION_KIT
    for (i = 0; i < 30; i++) {
        D_i2_80111848[i] = 0;
    }
#else
    D_i2_80111848[CAPTAIN_FALCON] = 1;
    D_i2_80111848[SAMURAI_GOROH] = 1;
    D_i2_80111848[JODY_SUMMER] = 1;
#endif

#ifdef EXPANSION_KIT
    Save_LoadDDCups(saveContext->profileSaves, 0, &sDDStaffGhostCompletion);
#endif
    Save_LoadGhostData(&saveContext->ghostSave.record, &saveContext->ghostSave.data, gGhosts, true);

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
        if (profileSave->saveSettings.checksum != Save_CalculateSaveSettingsChecksum(profileSave)) {
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
        gSettingEverythingUnlocked = true;
    } else {
        gSettingEverythingUnlocked = false;
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

    if (saveSettings->customUnlocks & 1) {
        D_i2_80111848[CAPTAIN_FALCON] = 1;
    }
    if (saveSettings->customUnlocks & 2) {
        D_i2_80111848[SAMURAI_GOROH] = 1;
    }
    if (saveSettings->customUnlocks & 4) {
        D_i2_80111848[JODY_SUMMER] = 1;
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
        if (profileSave->deathRace.checksum != Save_CalculateSaveDeathRaceChecksum(profileSave)) {
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
    s32 i;
    s32 j;
#if BUILD_REVISION <= REVISION_B
    u16 checksum;
    s32 invalidSaveIndex;
#else
    s32 invalidSaveIndex;
    u16 checksum;
#endif
    CourseInfo* courseInfo;
    ProfileSave* profileSave;
    s32 backupSaveIndex;
    SaveCourseRecords* courseRecord;

    j = 0;

    for (i = 0, profileSave = profileSaves; i < 2; i++) {
        if (Save_CalculateProfileSaveCourseRecordChecksum(profileSave, courseIndex) !=
            profileSave->courses[courseIndex].checksum) {
            j++;
            invalidSaveIndex = i;
        }
        profileSave++;
    }

    if (j == 2) {
        Save_InitCourseRecord(&profileSaves[0].courses[courseIndex], true);
        profileSaves[1].courses[courseIndex] = profileSaves[0].courses[courseIndex];

        checksum = Save_CalculateProfileSaveCourseRecordChecksum(profileSaves, courseIndex);

        for (i = 0; i < 2; i++) {
            Save_WriteSaveCourseRecord(profileSaves, i, courseIndex, checksum);
        }

    } else if (j == 1) {
        backupSaveIndex = (invalidSaveIndex == 0) ? 1 : 0;

        (profileSaves + invalidSaveIndex)->courses[courseIndex] =
            (profileSaves + backupSaveIndex)->courses[courseIndex];

        Save_WriteSaveCourseRecord(profileSaves, invalidSaveIndex, courseIndex,
                                   Save_CalculateProfileSaveCourseRecordChecksum(profileSaves, courseIndex));
    }

    courseRecord = &profileSaves->courses[courseIndex];
#if BUILD_REVISION >= REVISION_C
    // Split into sub-function
    Save_LoadCourseRecord2(courseRecord, courseIndex);
}

void func_i2_800A8CE4(SaveCourseRecords* courseRecord, s32 courseIndex) {
#ifdef EXPANSION_KIT
    Save_LoadCourseRecord2(courseRecord, courseIndex);
#endif
}

void Save_LoadCourseRecord2(SaveCourseRecords* courseRecord, s32 courseIndex) {
    u16 checksum;
    s32 i;
    s32 j;
    CourseInfo* courseInfo;
#endif

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
        if (ghostRecord->checksum != Save_CalculateGhostRecordChecksum(ghostRecord)) {
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
#ifndef EXPANSION_KIT
    GhostRecord* ghostRecord2 = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData2 = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];
#else
    GhostRecord* ghostRecord2 = &gSaveContext.ghostSave.record;
    GhostData* ghostData2 = &gSaveContext.ghostSave.data;
#endif

    if (arg3) {
        if (ghostData->replayInfo.checksum != Save_CalculateGhostDataChecksum(ghostData)) {
            Save_InitGhostRecord(ghostRecord2, true);
            Save_WriteGhostRecord(ghostRecord2);
            Save_InitGhostData(ghostData2, true);
            Save_WriteGhostData(ghostData2);
            ghost->encodedCourseIndex = 0;
        }
    }

#ifdef EXPANSION_KIT
    if (ghost == NULL) {
        return;
    }
#endif

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

#ifndef EXPANSION_KIT
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
        if (profileSave->editCup.checksum != Save_CalculateSaveEditCupChecksum(profileSave)) {
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
#else
void Save_LoadEditCup(void) {
}
#endif

void Save_LoadCharacterSave(CharacterSave* characterSave, s32 courseIndex) {
    s32 i;

    if (characterSave->checksum != Save_CalculateCharacterSaveChecksum(characterSave)) {
        Save_InitCharacterSave(characterSave, true);
        Save_WriteCharacterSave(characterSave, courseIndex);
    }

    for (i = 0; i < 30; i++) {
        gCharacterLastEngine[i] = characterSave->characterEngine[i];
    }
}

void Save_LoadCupSave(CupSave* cupSave, u8* cupCompletion) {
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    u8 temp_v1;
    s8* var_a0;
    s32 temp;

    if (cupSave->checksum != Save_CalculateCupSaveChecksum(cupSave)) {
        Save_InitCupSave(cupSave, true);
        Save_WriteCupSave(cupSave);
    }

    if (cupCompletion == NULL) {
        return;
    }

    var_a0 = (s8*) cupCompletion;

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
#ifdef EXPANSION_KIT
                // Account for additional cups added
                var_a0 += 2;
#endif
            }
        }
    }
}

#ifdef EXPANSION_KIT
void Save_LoadDDCups(ProfileSave* profileSaves, u8* cupCompletion, u16* staffGhostCompletion) {
    s32 i;
    s32 j;
    s32 k;
    u16 checksum;
    s32 invalidSaveIndex;
    s32 invalidSaveCount;
    s32 backupSaveIndex;
    SaveDDCups* ddCups;
    ProfileSave* profileSave;
    s8 temp_v0;

    invalidSaveCount = 0;

    for (i = 0, profileSave = profileSaves; i < 2; i++) {
        if (profileSave->ddCups.checksum != Save_CalculateSaveDDCupsChecksum(profileSave)) {
            invalidSaveCount++;
            invalidSaveIndex = i;
        }
        profileSave++;
    }

    if (invalidSaveCount == 2) {
        Save_InitDDCups(&profileSaves[0].ddCups, true);
        profileSaves[1].ddCups = profileSaves[0].ddCups;

        checksum = Save_CalculateSaveDDCupsChecksum(profileSaves);
        for (i = 0; i < 2; i++) {
            Save_WriteSaveDDCups(profileSaves, i, checksum);
        }
    } else if (invalidSaveCount == 1) {
        backupSaveIndex = (invalidSaveIndex == 0) ? 1 : 0;

        (profileSaves + invalidSaveIndex)->ddCups = (profileSaves + backupSaveIndex)->ddCups;

        Save_WriteSaveDDCups(profileSaves, invalidSaveIndex, Save_CalculateSaveDDCupsChecksum(profileSaves));
    }

    if (NULL != cupCompletion) {
        ddCups = &profileSaves[0].ddCups;

        for (k = 0; k < 4; k++) {
            for (i = 0; i < 30; i++) {
                for (j = 0; j < 2; j++) {
                    temp_v0 = (ddCups->cupCompletion[i * 2 + j] >> k * 2) & 3;
                    cupCompletion[k * 30 * 7 + i * 7 + j + 5] = temp_v0;
                }
            }
        }
    }

    if (staffGhostCompletion != NULL) {
        *staffGhostCompletion = ddCups->staffGhostCompletion;
    }
}
#endif

u16 Save_CalculateChecksum(void* data, s32 size) {
    u8* dataPtr = data;
    u16 checksum = 0;
    s32 i;

    for (i = 0; i < size; i++) {
        checksum += *dataPtr++;
    }

    return checksum;
}

u16 Save_CalculateSaveSettingsChecksum(ProfileSave* profileSave) {
    return Save_CalculateChecksum(&profileSave->saveSettings.fileName, sizeof(SaveSettings) - sizeof(u16));
}

u16 Save_CalculateSaveDeathRaceChecksum(ProfileSave* profileSave) {
    return Save_CalculateChecksum(&profileSave->deathRace.unk_02, sizeof(SaveDeathRace) - sizeof(u16));
}

u16 Save_CalculateProfileSaveCourseRecordChecksum(ProfileSave* profileSave, s32 courseIndex) {
    return Save_CalculateChecksum(&profileSave->courses[courseIndex].unk_02, sizeof(SaveCourseRecords) - sizeof(u16));
}

#ifdef EXPANSION_KIT
u16 Save_CalculateSaveCourseRecordChecksum(SaveCourseRecords* courseRecords) {
    return Save_CalculateChecksum(&courseRecords->unk_02, sizeof(SaveCourseRecords) - sizeof(u16));
}
#endif

u16 Save_CalculateSaveEditCupChecksum(ProfileSave* profileSave) {
    return Save_CalculateChecksum(&profileSave->editCup.unk_02, sizeof(SaveEditCup) - sizeof(u16));
}

#ifdef EXPANSION_KIT
u16 Save_CalculateSaveDDCupsChecksum(ProfileSave* profileSave) {
    return Save_CalculateChecksum(&profileSave->ddCups.staffGhostCompletion, sizeof(SaveEditCup) - sizeof(u16));
}
#endif

u16 Save_CalculateGhostRecordChecksum(GhostRecord* ghostRecord) {
    return Save_CalculateChecksum(&ghostRecord->ghostType, sizeof(GhostRecord) - sizeof(u16));
}

u16 Save_CalculateGhostDataChecksum(GhostData* ghostData) {
    return Save_CalculateChecksum(&ghostData->replayInfo.unk_02, sizeof(GhostData) - sizeof(u16));
}

u16 Save_CalculateCharacterSaveChecksum(CharacterSave* characterSave) {
    return Save_CalculateChecksum(&characterSave->unk_02, sizeof(CharacterSave) - sizeof(u16));
}

u16 Save_CalculateCupSaveChecksum(CupSave* cupSave) {
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
#ifndef EXPANSION_KIT
    osEPiStartDma(gSramPiHandlePtr, &sSramIoMesg, direction);
#else
    func_80768B88(gSramPiHandlePtr, &sSramIoMesg, direction);
#endif
    osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
}

s32 Save_LoadStaffGhostRecord(GhostInfo* ghostInfo, s32 courseIndex) {
#ifndef EXPANSION_KIT
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
#else
    GhostRecord* ghostRecord = &gSaveContext.ghostSave.record;
#endif

    if (!((courseIndex >= COURSE_MUTE_CITY) && (courseIndex <= COURSE_BIG_HAND))) {
        return 2;
    }
    Save_RomCopyGhostRecord(ghostRecord, courseIndex);
    if (ghostInfo != NULL) {
        func_i2_80101590(ghostRecord, ghostInfo);
#if OS_TV_TYPE == OS_TV_TYPE_PAL
        ghostInfo->raceTime = Math_Round(ghostInfo->raceTime * (60.0f / 50.0f));
#endif
    }
    return 0;
}

#ifdef EXPANSION_KIT
s32 sDDStaffGhostRecordTimes[] = {
    -1, -1, -1,    -1,     -1,     -1,     -1,     -1,     -1,    -1,    -1,    -1,    -1,    -1,
    -1, -1, -1,    -1,     -1,     -1,     -1,     -1,     -1,    -1,    -1,    -1,    -1,    -1,
    -1, -1, 99673, 114711, 113302, 108732, 111797, 120590, 91079, 90956, 98553, 99392, 98495, 97194,
};

s32 Save_GetDDStaffGhostRecordTime(s32 courseIndex) {
    if (!(courseIndex >= COURSE_MUTE_CITY && courseIndex <= COURSE_BIG_FOOT)) {
        return -1;
    }
    return sDDStaffGhostRecordTimes[courseIndex];
}

s32 Save_LoadDDStaffGhostRecord(GhostInfo* ghostInfo, s32 courseIndex) {
    GhostRecord* ghostRecord = &gSaveContext.ghostSave.record;

    if (!(courseIndex >= COURSE_SILENCE_3 && courseIndex <= COURSE_BIG_FOOT)) {
        return 2;
    }
    DDSave_LoadDDCourseGhosts(courseIndex);
    DDSave_LoadCachedGhostRecord(0, ghostRecord);
    if (ghostInfo != 0) {
        func_i2_80101590(ghostRecord, ghostInfo);
    }
    return 0;
}

s32 Save_LoadStaffGhostLapTimes(s32* lapTimes, s32 courseIndex) {
    GhostData* ghostData = &gSaveContext.ghostSave.data;
    s32 i;

    if (!((courseIndex >= COURSE_MUTE_CITY) && (courseIndex <= COURSE_BIG_HAND))) {
        return 2;
    }
    Save_RomCopyGhostReplayInfo(ghostData, courseIndex);

    if (lapTimes != NULL) {
        for (i = 0; i < 3; i++) {
            lapTimes[i] = ghostData->replayInfo.lapTimes[i];
        }
    }
    return 0;
}
#endif

void Save_RomCopyGhostRecord(GhostRecord* ghostRecord, s32 courseIndex) {
#ifndef EXPANSION_KIT
    Dma_RomCopyAsync(SEGMENT_ROM_START(staff_ghost_records) + D_i2_80106DF0[courseIndex][0], ghostRecord,
                     sizeof(GhostRecord));
#else
    Dma_RomCopyAsync(gRomSegmentPairs[13][0] + D_i2_80106DF0[courseIndex][0], ghostRecord, sizeof(GhostRecord));
#endif
}

#ifdef EXPANSION_KIT
void Save_RomCopyGhostReplayInfo(GhostData* ghostData, s32 courseIndex) {
    Dma_RomCopyAsync(gRomSegmentPairs[13][0] + D_i2_80106DF0[courseIndex][1], &ghostData->replayInfo,
                     sizeof(GhostReplayInfo));
}
#endif

s32 Save_LoadStaffGhost_impl(s32 courseIndex, s32 encodedCourseIndex) {
    s32 ghostIndex;
    GhostInfo ghostInfo;
#ifndef EXPANSION_KIT
    GhostRecord* ghostRecord = (GhostRecord*) gSaveBuffer;
    GhostData* ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];
#else
    GhostRecord* ghostRecord = &gSaveContext.ghostSave.record;
    GhostData* ghostData = &gSaveContext.ghostSave.data;
#endif

#if defined(EXPANSION_KIT)
    bool isEditCupCourse;

    if ((courseIndex >= COURSE_SILENCE_3) && (courseIndex <= COURSE_BIG_FOOT)) {
        isEditCupCourse = true;
    } else {
        isEditCupCourse = false;
    }
#endif

#ifdef EXPANSION_KIT
    if (isEditCupCourse) {
        Save_LoadDDStaffGhostRecord(&ghostInfo, courseIndex);
    } else {
#endif
        Save_LoadStaffGhostRecord(&ghostInfo, courseIndex);
#ifdef EXPANSION_KIT
    }
#endif
    if (func_i2_80100B38(&ghostInfo)) {
        return 0;
    }

    ghostIndex = func_i2_801005CC_impl(courseIndex, encodedCourseIndex);
#ifdef EXPANSION_KIT
    if (isEditCupCourse) {
        DDSave_LoadCachedGhostData(0, ghostData);
    } else {
#endif
        Save_RomCopyGhostData(ghostData, courseIndex);
#ifdef EXPANSION_KIT
    }
#endif

#if OS_TV_TYPE == OS_TV_TYPE_PAL
    {
        s32 i;
        ghostRecord = (GhostRecord*) gSaveBuffer;
        ghostData = (GhostData*) &gSaveBuffer[sizeof(GhostRecord)];

        ghostRecord->raceTime = Math_Round(ghostRecord->raceTime * (60.0f / 50.0f));

        for (i = 0; i < 3; i++) {
            ghostData->replayInfo.lapTimes[i] = Math_Round(ghostData->replayInfo.lapTimes[i] * (60.0f / 50.0f));
        }
    }
#endif

    Save_LoadGhostRecord(ghostRecord, ghostData, &gGhosts[ghostIndex], false);
    Save_LoadGhostData(ghostRecord, ghostData, &gGhosts[ghostIndex], false);

    return 0;
}

void Save_RomCopyGhostData(GhostData* ghostData, s32 courseIndex) {
    uintptr_t* offsets = D_i2_80106DF0[courseIndex];
    RomOffset romOffset;

#ifndef EXPANSION_KIT
    romOffset = SEGMENT_ROM_START(staff_ghost_records);

    Dma_RomCopyAsync(romOffset + offsets[1], &ghostData->replayInfo, sizeof(GhostReplayInfo));
    Dma_RomCopyAsync(romOffset + offsets[2], ghostData->replayData, ALIGN_2(ghostData->replayInfo.size + 1));
#else
    Dma_RomCopyAsync(gRomSegmentPairs[13][0] + offsets[1], &ghostData->replayInfo, sizeof(GhostReplayInfo));
    Dma_RomCopyAsync(gRomSegmentPairs[13][0] + offsets[2], ghostData->replayData,
                     ALIGN_2(ghostData->replayInfo.size + 1));
#endif
}

void func_i2_801039BC(s32 arg0) {
#ifndef EXPANSION_KIT
    ProfileSave* profileSaves = (ProfileSave*) gSaveBuffer;
#else
    ProfileSave* profileSaves = gSaveContext.profileSaves;
#endif
    s32 i;
    s32 j;

    // FAKE! this needs to be fixed by caller function
    if (arg0) {}

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            profileSaves[i].saveSettings.fileName[j] = D_i2_8010ADE8[j];
            Save_WriteSaveSettings(profileSaves, i, 0x1234);
        }
    }
}

#ifdef EXPANSION_KIT
u16 Save_GetDDStaffGhostCompletion(void) {
    sDDStaffGhostCompletion &= 0xFFF;
    return sDDStaffGhostCompletion;
}

s32 Save_SetDDStaffGhostComplete(s32 courseIndex) {
    ProfileSave* profileSaves = gSaveContext.profileSaves;
    u16 checksum;
    s32 i;

    if (!(courseIndex >= COURSE_SILENCE_3 && courseIndex <= COURSE_BIG_FOOT)) {
        return 2;
    }
    sDDStaffGhostCompletion |= (u16) (1 << (courseIndex - COURSE_SILENCE_3));
    Save_ReadProfileSaves(profileSaves);
    Save_LoadDDCups(profileSaves, NULL, NULL);
    profileSaves[0].ddCups.staffGhostCompletion = sDDStaffGhostCompletion;
    profileSaves[1].ddCups = profileSaves[0].ddCups;
    checksum = Save_CalculateSaveDDCupsChecksum(profileSaves);

    for (i = 0; i < 2; i++) {
        Save_WriteSaveDDCups(profileSaves, i, checksum);
    }
    return 0;
}
#endif
