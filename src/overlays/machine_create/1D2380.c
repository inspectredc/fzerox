#include "global.h"
#include "machine_create.h"
#include "leo/mfs.h"
#include "fzx_machine.h"
#include "fzx_bordered_box.h"

s32 gWorksMachineMode = MACHINE_MODE_0;

extern s32 gMachineRegistrationOption;

void func_xk3_801326C0(void) {
    gMachineRegistrationOption = 0;
    PRINTF("WORKS MACHINE MODE : MENU\n");
    gWorksMachineMode = MACHINE_MODE_MENU;
}

extern s32 gMachineDesignOption;

void func_xk3_801326D8(void) {
    gMachineDesignOption = 0;
    PRINTF("WORKS MACHINE MODE : MENU\n");
    gWorksMachineMode = MACHINE_MODE_MENU;
}

extern s32 gColorOption;
extern volatile unk_807C6EA8 D_807C6EA8;
extern CustomMachine gCustomMachine;
extern CustomMachine gCustomMachineWork;

void func_xk3_801326F0(void) {
    D_807C6EA8.unk_08 = 0;
    gColorOption = 0;
    gCustomMachineWork = gCustomMachine;
    PRINTF("WORKS MACHINE MODE : MENU_COLOR\n");
    gWorksMachineMode = MACHINE_MODE_MENU_COLOR;
}

extern s32 gMachineCreateEntryOption;

void func_xk3_80132764(void) {
    gMachineCreateEntryOption = 0;
    PRINTF("WORKS MACHINE MODE : MENU\n");
    gWorksMachineMode = MACHINE_MODE_MENU;
}

void func_xk3_8013277C(void) {
    PRINTF("WORKS MACHINE MODE : ENTRY_GET_FILE\n");
    gWorksMachineMode = MACHINE_MODE_ENTRY_GET_FILE;
    func_xk3_80135F90();
}

extern volatile u8 D_80794E1C;

void func_xk3_801327A4(void) {
    if (func_xk3_8013618C(1) != 0) {
        func_xk3_8012B950();
        PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SELECT_FILE\n");
        gWorksMachineMode = MACHINE_MODE_ENTRY_CLEAR_SELECT_FILE;
    } else {
        PRINTF("WORKS MACHINE MODE : 0\n");
        gWorksMachineMode = MACHINE_MODE_0;
        D_80794E1C = 1;
        D_807C6EA8.unk_08 = 0x1B;
    }
}

void func_xk3_80132808(void) {
    D_807C6EA8.unk_08 = 0x14;
    PRINTF("WORKS MACHINE MODE : ENTRY_ALLCLEAR_CONFIRM\n");
    gWorksMachineMode = MACHINE_MODE_ENTRY_ALLCLEAR_CONFIRM;
}

void func_xk3_80132828(void) {
    PRINTF("WORKS MACHINE MODE : LOAD_GET_FILE\n");
    gWorksMachineMode = MACHINE_MODE_LOAD_GET_FILE;
    func_xk3_80135F90();
}

void func_xk3_80132850(void) {
    PRINTF("WORKS MACHINE MODE : DELETE_GET_FILE\n");
    gWorksMachineMode = MACHINE_MODE_DELETE_GET_FILE;
    func_8076877C(0, "CARD");
}

extern f32 D_xk3_80136540;
extern unk_80140E60 D_xk3_80140E60;

void func_xk3_80132884(void) {
    D_807C6EA8.unk_08 = 0;
    gCustomMachineWork = gCustomMachine;
    PRINTF("WORKS MACHINE MODE : PARTS\n");
    gWorksMachineMode = MACHINE_MODE_PARTS;
    D_xk3_80140E60.unk_00 = 0;
    D_xk3_80140E60.unk_04 = 0;
    D_xk3_80136540 = -7000.0f;
}

extern s32 gDecalOption;

void func_xk3_80132910(void) {
    D_807C6EA8.unk_08 = 0;
    gDecalOption = gCustomMachine.decal - 1;
    PRINTF("WORKS MACHINE MODE : SELECT_LINE\n");
    gWorksMachineMode = MACHINE_MODE_SELECT_LINE;
    gCustomMachineWork = gCustomMachine;
}

void func_xk3_8013298C(void) {
    gCustomMachine.decal = MACHINE_DECAL(DECAL_STRIPE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_801329A4(void) {
    gCustomMachine.decal = MACHINE_DECAL(DECAL_THIN_STRIPE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_801329BC(void) {
    gCustomMachine.decal = MACHINE_DECAL(DECAL_DOUBLE_STRIPE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_801329D4(void) {
    gCustomMachine.decal = MACHINE_DECAL(DECAL_TRIPLE_STRIPE_UNEVEN);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_801329EC(void) {
    gCustomMachine.decal = MACHINE_DECAL(DECAL_BLOCK);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

extern s32 gLogoOption;

void func_xk3_80132A04(void) {
    D_807C6EA8.unk_08 = 0;
    gLogoOption = gCustomMachine.logo - 1;
    PRINTF("WORKS MACHINE MODE : SELECT_MARK\n");
    gWorksMachineMode = MACHINE_MODE_SELECT_MARK;
    gCustomMachineWork = gCustomMachine;
}

void func_xk3_80132A80(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_SHIELD);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_80132A98(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_ARROW_PLANE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_80132AB0(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_CIRCLE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_80132AC8(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_SKULL);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_80132AE0(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_YELLOW_GREEN);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_80132AF8(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_KANJI);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_80132B10(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_X);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

void func_xk3_80132B28(void) {
    gCustomMachine.logo = MACHINE_LOGO(LOGO_N64);
    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
}

extern unk_80140E60 D_xk3_80140E68;
extern BorderedBoxWidget* gMachineCreateColorBox;

void func_xk3_80132B40(void) {
    PRINTF("WORKS MACHINE MODE : BODY_COLOR\n");
    gWorksMachineMode = MACHINE_MODE_BODY_COLOR;
    D_xk3_80140E68.unk_00 = 0;
    D_xk3_80140E68.unk_04 = 0;
    gMachineCreateColorBox =
        BorderedBox_Init(1, 168, 44, 121, 121, 1, GPACK_RGBA5551(0, 0, 0, 1), MachineCreate_DrawColorSelection);
}

void func_xk3_80132BB0(void) {
    PRINTF("WORKS MACHINE MODE : LINE_COLOR\n");
    gWorksMachineMode = MACHINE_MODE_LINE_COLOR;
    D_xk3_80140E68.unk_00 = 0;
    D_xk3_80140E68.unk_04 = 0;
    gMachineCreateColorBox =
        BorderedBox_Init(1, 168, 44, 121, 121, 1, GPACK_RGBA5551(0, 0, 0, 1), MachineCreate_DrawColorSelection);
}

void func_xk3_80132C20(void) {
    PRINTF("WORKS MACHINE MODE : NUMBER_COLOR\n");
    gWorksMachineMode = MACHINE_MODE_NUMBER_COLOR;
    D_xk3_80140E68.unk_00 = 0;
    D_xk3_80140E68.unk_04 = 0;
    gMachineCreateColorBox =
        BorderedBox_Init(1, 168, 44, 121, 121, 1, GPACK_RGBA5551(0, 0, 0, 1), MachineCreate_DrawColorSelection);
}

void func_xk3_80132C90(void) {
    PRINTF("WORKS MACHINE MODE : COCKPIT_COLOR\n");
    gWorksMachineMode = MACHINE_MODE_COCKPIT_COLOR;
    D_xk3_80140E68.unk_00 = 0;
    D_xk3_80140E68.unk_04 = 0;
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
    func_xk3_8012D700();
    PRINTF("WORKS MACHINE MODE : SAVE_FILE_EXIST_BEFORE\n");
    gWorksMachineMode = MACHINE_MODE_SAVE_FILE_EXIST_BEFORE;
}

extern u8 D_xk1_800333F0;

void func_xk3_80132DDC(void) {
    if (D_xk1_800333F0 != 0) {
        D_807C6EA8.unk_08 = 0x17;
        PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
        gWorksMachineMode = MACHINE_MODE_MESSAGE_BUTTON;
        Audio_TriggerSystemSE(NA_SE_32);
    } else {
        PRINTF("WORKS MACHINE MODE : MNAME\n");
        gWorksMachineMode = MACHINE_MODE_MNAME;
        D_807C6EA8.unk_08 = 0x11;
        func_xk1_8002D86C(0x1B, 6);
        func_xk1_8002D880(0x28);
        func_xk1_800294AC();
        mfsStrCpy(gExpansionKitNameEntryStr, gCustomMachine.machineName);
        ExpansionKit_NameEntryInit(MachineCreate_NameEntryCallback);
    }
}

extern unk_80140E60 D_xk3_80140E70;
extern BorderedBoxWidget* gMachineCreateStatsBox;

void func_xk3_80132E84(void) {
    gCustomMachineWork = gCustomMachine;
    PRINTF("WORKS MACHINE MODE : SETTING\n");
    gWorksMachineMode = MACHINE_MODE_SETTING;
    D_xk3_80140E70.unk_00 = 0;
    D_xk3_80140E70.unk_04 = 0;
    gMachineCreateStatsBox =
        BorderedBox_Init(1, 122, 38, 174, 79, 1, GPACK_RGBA5551(0, 0, 0, 1), MachineCreate_DrawStatSelection);
}
