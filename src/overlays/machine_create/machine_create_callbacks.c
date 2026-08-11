#include "global.h"
#include "machine_create.h"
#include "leo/mfs.h"
#include "fzx_machine.h"
#include "fzx_bordered_box.h"

s32 gWorksMachineMode = MACHINE_MODE_0;

extern s32 gMachineRegistrationOption;

void MachineCreate_RegistrationMenuCallback(void) {
    gMachineRegistrationOption = 0;
    PRINTF("WORKS MACHINE MODE : MENU\n");
    gWorksMachineMode = MACHINE_MODE_MENU;
}

extern s32 gMachineDesignOption;

void MachineCreate_DesignMenuCallback(void) {
    gMachineDesignOption = 0;
    PRINTF("WORKS MACHINE MODE : MENU\n");
    gWorksMachineMode = MACHINE_MODE_MENU;
}

extern s32 gColorOption;
extern volatile unk_807C6EA8 D_807C6EA8;
extern CustomMachine gCustomMachine;
extern CustomMachine gCustomMachineWork;

void MachineCreate_ColorMenuCallback(void) {
    D_807C6EA8.unk_08 = 0;
    gColorOption = 0;
    gCustomMachineWork = gCustomMachine;
    PRINTF("WORKS MACHINE MODE : MENU_COLOR\n");
    gWorksMachineMode = MACHINE_MODE_MENU_COLOR;
}

extern s32 gMachineCreateEntryOption;

void MachineCreate_EntryMenuCallback(void) {
    gMachineCreateEntryOption = 0;
    PRINTF("WORKS MACHINE MODE : MENU\n");
    gWorksMachineMode = MACHINE_MODE_MENU;
}

void MachineCreate_UseEntryCallback(void) {
    PRINTF("WORKS MACHINE MODE : ENTRY_GET_FILE\n");
    gWorksMachineMode = MACHINE_MODE_ENTRY_GET_FILE;
    MachineCreate_FileListSetup();
}

extern volatile u8 D_80794E1C;

void MachineCreate_ClearEntryCallback(void) {
    if (MachineCreate_FileListClearSetup(1) != 0) {
        MachineCreate_InitFileMenu();
        PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SELECT_FILE\n");
        gWorksMachineMode = MACHINE_MODE_ENTRY_CLEAR_SELECT_FILE;
    } else {
        PRINTF("WORKS MACHINE MODE : 0\n");
        gWorksMachineMode = MACHINE_MODE_0;
        D_80794E1C = 1;
        D_807C6EA8.unk_08 = 27;
    }
}

void MachineCreate_ClearAllEntryCallback(void) {
    D_807C6EA8.unk_08 = 20;
    PRINTF("WORKS MACHINE MODE : ENTRY_ALLCLEAR_CONFIRM\n");
    gWorksMachineMode = MACHINE_MODE_ENTRY_ALLCLEAR_CONFIRM;
}

void MachineCreate_LoadFileCallback(void) {
    PRINTF("WORKS MACHINE MODE : LOAD_GET_FILE\n");
    gWorksMachineMode = MACHINE_MODE_LOAD_GET_FILE;
    MachineCreate_FileListSetup();
}

void MachineCreate_DeleteFileCallback(void) {
    PRINTF("WORKS MACHINE MODE : DELETE_GET_FILE\n");
    gWorksMachineMode = MACHINE_MODE_DELETE_GET_FILE;
    func_8076877C(0, "CARD");
}

extern f32 gMachineCreatePartsLightSourceX;
extern MachineCreateGrid gMachineCreatePartsGrid;

void MachineCreate_PartsMenuCallback(void) {
    D_807C6EA8.unk_08 = 0;
    gCustomMachineWork = gCustomMachine;
    PRINTF("WORKS MACHINE MODE : PARTS\n");
    gWorksMachineMode = MACHINE_MODE_PARTS;
    gMachineCreatePartsGrid.x = 0;
    gMachineCreatePartsGrid.y = 0;
    gMachineCreatePartsLightSourceX = -7000.0f;
}

extern s32 gDecalOption;

void MachineCreate_DecalMenuCallback(void) {
    D_807C6EA8.unk_08 = 0;
    gDecalOption = gCustomMachine.decal - 1;
    PRINTF("WORKS MACHINE MODE : SELECT_LINE\n");
    gWorksMachineMode = MACHINE_MODE_SELECT_LINE;
    gCustomMachineWork = gCustomMachine;
}

void MachineCreate_DecalStripeCallback(void) {
    gCustomMachine.decal = MACHINE_DECAL(DECAL_STRIPE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_DecalThinStripeCallback(void) {
    gCustomMachine.decal = MACHINE_DECAL(DECAL_THIN_STRIPE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_DecalDoubleStripeCallback(void) {
    gCustomMachine.decal = MACHINE_DECAL(DECAL_DOUBLE_STRIPE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_DecalTripleStripeUnevenCallback(void) {
    gCustomMachine.decal = MACHINE_DECAL(DECAL_TRIPLE_STRIPE_UNEVEN);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_DecalBlockCallback(void) {
    gCustomMachine.decal = MACHINE_DECAL(DECAL_BLOCK);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

extern s32 gLogoOption;

void MachineCreate_LogoMenuCallback(void) {
    D_807C6EA8.unk_08 = 0;
    gLogoOption = gCustomMachine.logo - 1;
    PRINTF("WORKS MACHINE MODE : SELECT_MARK\n");
    gWorksMachineMode = MACHINE_MODE_SELECT_MARK;
    gCustomMachineWork = gCustomMachine;
}

void MachineCreate_LogoShieldCallback(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_SHIELD);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_LogoArrowCallback(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_ARROW_PLANE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_LogoCircleCallback(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_CIRCLE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_LogoSkullCallback(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_SKULL);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_LogoYellowGreenCallback(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_YELLOW_GREEN);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_LogoKanjiCallback(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_KANJI);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_LogoXCallback(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_X);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void MachineCreate_LogoN64Callback(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_N64);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

extern MachineCreateGrid gMachineCreateColorGrid;
extern BorderedBoxWidget* gMachineCreateColorBox;

void MachineCreate_BodyColorMenuCallback(void) {
    PRINTF("WORKS MACHINE MODE : BODY_COLOR\n");
    gWorksMachineMode = MACHINE_MODE_BODY_COLOR;
    gMachineCreateColorGrid.x = 0;
    gMachineCreateColorGrid.y = 0;
    gMachineCreateColorBox =
        BorderedBox_Init(1, 168, 44, 121, 121, 1, GPACK_RGBA5551(0, 0, 0, 1), MachineCreate_DrawColorSelection);
}

void MachineCreate_LineColorMenuCallback(void) {
    PRINTF("WORKS MACHINE MODE : LINE_COLOR\n");
    gWorksMachineMode = MACHINE_MODE_LINE_COLOR;
    gMachineCreateColorGrid.x = 0;
    gMachineCreateColorGrid.y = 0;
    gMachineCreateColorBox =
        BorderedBox_Init(1, 168, 44, 121, 121, 1, GPACK_RGBA5551(0, 0, 0, 1), MachineCreate_DrawColorSelection);
}

void MachineCreate_NumberColorMenuCallback(void) {
    PRINTF("WORKS MACHINE MODE : NUMBER_COLOR\n");
    gWorksMachineMode = MACHINE_MODE_NUMBER_COLOR;
    gMachineCreateColorGrid.x = 0;
    gMachineCreateColorGrid.y = 0;
    gMachineCreateColorBox =
        BorderedBox_Init(1, 168, 44, 121, 121, 1, GPACK_RGBA5551(0, 0, 0, 1), MachineCreate_DrawColorSelection);
}

void MachineCreate_CockpitColorMenuCallback(void) {
    PRINTF("WORKS MACHINE MODE : COCKPIT_COLOR\n");
    gWorksMachineMode = MACHINE_MODE_COCKPIT_COLOR;
    gMachineCreateColorGrid.x = 0;
    gMachineCreateColorGrid.y = 0;
    gMachineCreateColorBox =
        BorderedBox_Init(1, 168, 44, 121, 121, 1, GPACK_RGBA5551(0, 0, 0, 1), MachineCreate_DrawColorSelection);
}

extern u8 gExpansionKitNameEntryStr[];

void MachineCreate_NameEntryCallback(void) {
    D_807C6EA8.unk_08 = 0;
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        PRINTF("WORKS MACHINE MODE : 0\n");
        gWorksMachineMode = MACHINE_MODE_0;
        return;
    }
    mfsStrCpy(gCustomMachine.machineName, gExpansionKitNameEntryStr);
    gCustomMachineWork = gCustomMachine;
    gCustomMachineWork.number = 31;
    MachineCreate_UpdateMachineNumber();
    PRINTF("WORKS MACHINE MODE : SAVE_FILE_EXIST_BEFORE\n");
    gWorksMachineMode = MACHINE_MODE_SAVE_FILE_EXIST_BEFORE;
}

extern u8 gCustomMachineIsSuper;

void MachineCreate_NameFileCallback(void) {
    if (gCustomMachineIsSuper) {
        D_807C6EA8.unk_08 = 23;
        PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
        gWorksMachineMode = MACHINE_MODE_MESSAGE_BUTTON;
        Audio_TriggerSystemSE(NA_SE_32);
    } else {
        PRINTF("WORKS MACHINE MODE : MNAME\n");
        gWorksMachineMode = MACHINE_MODE_MNAME;
        D_807C6EA8.unk_08 = 17;
        EKController_SetRepeatDelay(27, 6);
        EKController_SetDeadZone(40);
        ExpansionKit_NameEntryClear();
        mfsStrCpy(gExpansionKitNameEntryStr, gCustomMachine.machineName);
        ExpansionKit_NameEntryInit(MachineCreate_NameEntryCallback);
    }
}

extern MachineCreateGrid gMachineCreateMachineSettingsGrid;
extern BorderedBoxWidget* gMachineCreateStatsBox;

void MachineCreate_StatsMenuCallback(void) {
    gCustomMachineWork = gCustomMachine;
    PRINTF("WORKS MACHINE MODE : SETTING\n");
    gWorksMachineMode = MACHINE_MODE_SETTING;
    gMachineCreateMachineSettingsGrid.x = 0;
    gMachineCreateMachineSettingsGrid.y = 0;
    gMachineCreateStatsBox =
        BorderedBox_Init(1, 122, 38, 174, 79, 1, GPACK_RGBA5551(0, 0, 0, 1), MachineCreate_DrawStatSelection);
}
