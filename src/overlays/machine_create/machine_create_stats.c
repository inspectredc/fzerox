#include "global.h"
#include "fzx_racer.h"
#include "machine_create.h"
#include "fzx_bordered_box.h"
#include ASSET_HEADER(create_machine_textures.h)
#include ASSET_HEADER_EK(overlays/machine_create/machine_create_assets.h)

u8 sMachineCreateBodyStatE = MACHINE_STAT_SELECTED;
u8 sMachineCreateBodyStatD = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateBodyStatC = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateBodyStatB = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateBodyStatA = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateBoostStatE = MACHINE_STAT_SELECTED;
u8 sMachineCreateBoostStatD = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateBoostStatC = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateBoostStatB = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateBoostStatA = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateGripStatE = MACHINE_STAT_SELECTED;
u8 sMachineCreateGripStatD = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateGripStatC = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateGripStatB = MACHINE_STAT_AVAILABLE;
u8 sMachineCreateGripStatA = MACHINE_STAT_AVAILABLE;

u8* sMachineStatSelectionStates[][5] = {
    { &sMachineCreateBodyStatE, &sMachineCreateBodyStatD, &sMachineCreateBodyStatC, &sMachineCreateBodyStatB,
      &sMachineCreateBodyStatA },
    { &sMachineCreateBoostStatE, &sMachineCreateBoostStatD, &sMachineCreateBoostStatC, &sMachineCreateBoostStatB,
      &sMachineCreateBoostStatA },
    { &sMachineCreateGripStatE, &sMachineCreateGripStatD, &sMachineCreateGripStatC, &sMachineCreateGripStatB,
      &sMachineCreateGripStatA },
};

TexturePtr sMachineCreateStatTexs[][3] = {
    { aMachineCreateStatEInvalidTex, aMachineCreateStatETex, aMachineCreateStatSelectedETex },
    { aMachineCreateStatDInvalidTex, aMachineCreateStatDTex, aMachineCreateStatSelectedDTex },
    { aMachineCreateStatCInvalidTex, aMachineCreateStatCTex, aMachineCreateStatSelectedCTex },
    { aMachineCreateStatBInvalidTex, aMachineCreateStatBTex, aMachineCreateStatSelectedBTex },
    { aMachineCreateStatAInvalidTex, aMachineCreateStatATex, aMachineCreateStatSelectedATex },
};

u16 sMachineStatLeftPositions[][5] = {
    { 163, 189, 215, 241, 267 },
    { 163, 189, 215, 241, 267 },
    { 163, 189, 215, 241, 267 },
};

u8 sMachineStatTopPositions[][5] = {
    { 41, 41, 41, 41, 41 },
    { 60, 60, 60, 60, 60 },
    { 79, 79, 79, 79, 79 },
};

u8 sMachineStatWeightings[][5] = {
    { 0, 1, 2, 4, 5 },
    { 0, 1, 2, 6, 8 },
    { 0, 1, 2, 6, 8 },
};

void MachineCreate_CheckStateValidity(u8 statType, u8 selectedStatValue, u8 weightingRemaining, u8 statValue) {

    if ((sMachineStatWeightings[statType][statValue] - sMachineStatWeightings[statType][selectedStatValue]) <=
        weightingRemaining) {
        *sMachineStatSelectionStates[statType][statValue] = MACHINE_STAT_AVAILABLE;
    } else {
        *sMachineStatSelectionStates[statType][statValue] = MACHINE_STAT_INVALID;
    }
}

void MachineCreate_UpdateStatSelectionStates(u8 statType, u8 statValue, u8 weightingRemaining) {

    switch (statValue) {
        case MACHINE_STAT_E:
            *sMachineStatSelectionStates[statType][MACHINE_STAT_E] = MACHINE_STAT_SELECTED;
            MachineCreate_CheckStateValidity(statType, statValue, weightingRemaining, MACHINE_STAT_D);
            MachineCreate_CheckStateValidity(statType, statValue, weightingRemaining, MACHINE_STAT_C);
            MachineCreate_CheckStateValidity(statType, statValue, weightingRemaining, MACHINE_STAT_B);
            MachineCreate_CheckStateValidity(statType, statValue, weightingRemaining, MACHINE_STAT_A);
            break;
        case MACHINE_STAT_D:
            *sMachineStatSelectionStates[statType][MACHINE_STAT_E] = MACHINE_STAT_AVAILABLE;
            *sMachineStatSelectionStates[statType][MACHINE_STAT_D] = MACHINE_STAT_SELECTED;
            MachineCreate_CheckStateValidity(statType, statValue, weightingRemaining, MACHINE_STAT_C);
            MachineCreate_CheckStateValidity(statType, statValue, weightingRemaining, MACHINE_STAT_B);
            MachineCreate_CheckStateValidity(statType, statValue, weightingRemaining, MACHINE_STAT_A);
            break;
        case MACHINE_STAT_C:
            *sMachineStatSelectionStates[statType][MACHINE_STAT_E] = MACHINE_STAT_AVAILABLE;
            *sMachineStatSelectionStates[statType][MACHINE_STAT_D] = MACHINE_STAT_AVAILABLE;
            *sMachineStatSelectionStates[statType][MACHINE_STAT_C] = MACHINE_STAT_SELECTED;
            MachineCreate_CheckStateValidity(statType, statValue, weightingRemaining, MACHINE_STAT_B);
            MachineCreate_CheckStateValidity(statType, statValue, weightingRemaining, MACHINE_STAT_A);
            break;
        case MACHINE_STAT_B:
            *sMachineStatSelectionStates[statType][MACHINE_STAT_E] = MACHINE_STAT_AVAILABLE;
            *sMachineStatSelectionStates[statType][MACHINE_STAT_D] = MACHINE_STAT_AVAILABLE;
            *sMachineStatSelectionStates[statType][MACHINE_STAT_C] = MACHINE_STAT_AVAILABLE;
            *sMachineStatSelectionStates[statType][MACHINE_STAT_B] = MACHINE_STAT_SELECTED;
            MachineCreate_CheckStateValidity(statType, statValue, weightingRemaining, MACHINE_STAT_A);
            break;
        case MACHINE_STAT_A:
            *sMachineStatSelectionStates[statType][MACHINE_STAT_E] = MACHINE_STAT_AVAILABLE;
            *sMachineStatSelectionStates[statType][MACHINE_STAT_D] = MACHINE_STAT_AVAILABLE;
            *sMachineStatSelectionStates[statType][MACHINE_STAT_C] = MACHINE_STAT_AVAILABLE;
            *sMachineStatSelectionStates[statType][MACHINE_STAT_B] = MACHINE_STAT_AVAILABLE;
            *sMachineStatSelectionStates[statType][MACHINE_STAT_A] = MACHINE_STAT_SELECTED;
            break;
        default:
            break;
    }
}

void MachineCreate_UpdateStatSelectionWeighting(u8 bodyStatValue, u8 boostStatValue, u8 gripStatValue) {
    u8 weightingRemaining;
    u8 bodyWeighting;
    u8 boostWeighting;
    u8 gripWeighting;

    bodyWeighting = sMachineStatWeightings[BODY_STAT][bodyStatValue];
    boostWeighting = sMachineStatWeightings[BOOST_STAT][boostStatValue];
    gripWeighting = sMachineStatWeightings[GRIP_STAT][gripStatValue];
    weightingRemaining = MACHINE_STAT_MAX_WEIGHTING - (bodyWeighting + boostWeighting + gripWeighting);

    MachineCreate_UpdateStatSelectionStates(BODY_STAT, bodyStatValue, weightingRemaining);
    MachineCreate_UpdateStatSelectionStates(BOOST_STAT, boostStatValue, weightingRemaining);
    MachineCreate_UpdateStatSelectionStates(GRIP_STAT, gripStatValue, weightingRemaining);
}

Gfx* MachineCreate_DrawStatSelectionStats(Gfx* gfx) {
    u8 i;
    u8 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            gfx = MachineCreate_DrawTextureBlockRGBA16(
                gfx, sMachineCreateStatTexs[j][*sMachineStatSelectionStates[i][j]], sMachineStatLeftPositions[i][j],
                sMachineStatTopPositions[i][j], 24, 16);
        }
    }
    return gfx;
}

extern MachineCreateGrid gMachineCreateMachineSettingsGrid;
extern u16 aMachineCreateOkTex[];
extern u16 aMachineCreateHighlightedOkTex[];
extern Gfx D_xk3_80137378[];

Gfx* MachineCreate_DrawStatSelectionCursorAndOK(Gfx* gfx) {

    if (gMachineCreateMachineSettingsGrid.y == 3) {
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aMachineCreateHighlightedOkTex, 259, 98, 32, 16);
    } else {
        gfx = ExpansionKit_DrawRectangleBorderHighlight(
            gfx, sMachineStatLeftPositions[gMachineCreateMachineSettingsGrid.y][gMachineCreateMachineSettingsGrid.x],
            sMachineStatTopPositions[gMachineCreateMachineSettingsGrid.y][gMachineCreateMachineSettingsGrid.x],
            sMachineStatLeftPositions[gMachineCreateMachineSettingsGrid.y][gMachineCreateMachineSettingsGrid.x] +
                (24 - 1),
            sMachineStatTopPositions[gMachineCreateMachineSettingsGrid.y][gMachineCreateMachineSettingsGrid.x] +
                (16 - 1),
            255, 64, 64, func_xk1_800290C0(), 2, 2);
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aMachineCreateOkTex, 259, 98, 32, 16);
    }
    return gfx;
}

extern u8 aMachineCreateBodyTex[];
extern u8 aMachineCreateBoostTex[];
extern u8 aMachineCreateGripTex[];
extern CustomMachine gCustomMachine;

Gfx* MachineCreate_DrawStatSelection(Gfx* gfx, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_xk3_80137440);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1))
        gDPFillRectangle(gfx++, 122, 38, 295, 116);
    gSPDisplayList(gfx++, D_xk3_801373F0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateBodyTex, 127, 41, 32, 16);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateBoostTex, 127, 60, 32, 16);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateGripTex, 127, 79, 32, 16);
    gSPDisplayList(gfx++, D_xk3_80137378);
    MachineCreate_UpdateStatSelectionWeighting(gCustomMachine.body, gCustomMachine.boost, gCustomMachine.grip);
    gfx = MachineCreate_DrawStatSelectionStats(gfx);
    gfx = MachineCreate_DrawStatSelectionCursorAndOK(gfx);
    return gfx;
}

void MachineCreate_StatValueToString(char** statStrPtr, u8 statValue) {

    switch (statValue) {
        case MACHINE_STAT_A:
            *statStrPtr = "a";
            break;
        case MACHINE_STAT_B:
            *statStrPtr = "b";
            break;
        case MACHINE_STAT_C:
            *statStrPtr = "c";
            break;
        case MACHINE_STAT_D:
            *statStrPtr = "d";
            break;
        case MACHINE_STAT_E:
            *statStrPtr = "e";
            break;
        default:
            break;
    }
}

extern u8 gCustomMachineIsSuper;
extern u8 gCustomMachineCurrentSuperIndex;
extern u8 kSuperMachineStatValues[][3];

Gfx* MachineCreate_DrawStatsSummary(Gfx* gfx) {

    gSPDisplayList(gfx++, D_xk3_801373F0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateBodyTex, 190, 133, 32, 16);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateBoostTex, 190, 150, 32, 16);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateGripTex, 190, 167, 32, 16);

    gSPDisplayList(gfx++, D_xk3_80137378);
    if (gCustomMachineIsSuper) {
        gfx = MachineCreate_DrawTextureBlockRGBA16(
            gfx, sMachineCreateStatTexs[kSuperMachineStatValues[gCustomMachineCurrentSuperIndex][0]][2], 230, 133, 24,
            16);
        gfx = MachineCreate_DrawTextureBlockRGBA16(
            gfx, sMachineCreateStatTexs[kSuperMachineStatValues[gCustomMachineCurrentSuperIndex][1]][2], 230, 150, 24,
            16);
        gfx = MachineCreate_DrawTextureBlockRGBA16(
            gfx, sMachineCreateStatTexs[kSuperMachineStatValues[gCustomMachineCurrentSuperIndex][2]][2], 230, 167, 24,
            16);
    } else {
        gfx =
            MachineCreate_DrawTextureBlockRGBA16(gfx, sMachineCreateStatTexs[gCustomMachine.body][2], 230, 133, 24, 16);
        gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, sMachineCreateStatTexs[gCustomMachine.boost][2], 230, 150, 24,
                                                   16);
        gfx =
            MachineCreate_DrawTextureBlockRGBA16(gfx, sMachineCreateStatTexs[gCustomMachine.grip][2], 230, 167, 24, 16);
    }
    return gfx;
}

extern BorderedBoxWidget* gMachineCreateStatsBox;

void MachineCreate_UpdateMachineSettingAInput(void) {
    if (!BorderedBox_GetInfo(gMachineCreateStatsBox, IS_BORDERED_BOX_OPENED)) {
        return;
    }
    if (gMachineCreateMachineSettingsGrid.y == 3) {
        PRINTF("WORKS MACHINE MODE : 0\n");
        gWorksMachineMode = MACHINE_MODE_0;
        Audio_TriggerSystemSE(NA_SE_36);
        BorderedBox_StartClose(gMachineCreateStatsBox);
    } else if (*sMachineStatSelectionStates[gMachineCreateMachineSettingsGrid.y][gMachineCreateMachineSettingsGrid.x] !=
               MACHINE_STAT_INVALID) {
        switch (gMachineCreateMachineSettingsGrid.y) {
            case BODY_STAT:
                if (gMachineCreateMachineSettingsGrid.x != gCustomMachine.body) {
                    gCustomMachine.body = gMachineCreateMachineSettingsGrid.x;
                    Audio_TriggerSystemSE(NA_SE_39);
                    break;
                }
                break;
            case BOOST_STAT:
                if (gMachineCreateMachineSettingsGrid.x != gCustomMachine.boost) {
                    gCustomMachine.boost = gMachineCreateMachineSettingsGrid.x;
                    Audio_TriggerSystemSE(NA_SE_39);
                    break;
                }
                break;
            case GRIP_STAT:
                if (gMachineCreateMachineSettingsGrid.x != gCustomMachine.grip) {
                    gCustomMachine.grip = gMachineCreateMachineSettingsGrid.x;
                    Audio_TriggerSystemSE(NA_SE_39);
                    break;
                }
                break;
        }
    } else {
        Audio_TriggerSystemSE(NA_SE_32);
    }
}

bool MachineCreate_CustomMachineStatsIsValid(CustomMachine* customMachine) {
    if (sMachineStatWeightings[BODY_STAT][customMachine->body] +
            sMachineStatWeightings[BOOST_STAT][customMachine->boost] +
            sMachineStatWeightings[GRIP_STAT][customMachine->grip] >
        MACHINE_STAT_MAX_WEIGHTING) {
        return true;
    }
    return false;
}
