#include "global.h"
#include "machine_create.h"
#include "fzx_bordered_box.h"
#include ASSET_HEADER_EK(overlays/machine_create/machine_create_assets.h)

u8 sColorSelectXPos;
u8 sColorSelectYPos;

u8 sColorSelections[][8][3] = {
    { { 255, 0, 0 },
      { 201, 0, 0 },
      { 147, 0, 0 },
      { 93, 0, 0 },
      { 0, 255, 0 },
      { 0, 201, 0 },
      { 0, 147, 0 },
      { 0, 93, 0 } },
    { { 255, 127, 0 },
      { 201, 100, 0 },
      { 147, 73, 0 },
      { 93, 46, 0 },
      { 0, 154, 80 },
      { 0, 121, 63 },
      { 0, 89, 45 },
      { 0, 56, 28 } },
    { { 255, 255, 0 },
      { 201, 201, 0 },
      { 147, 147, 0 },
      { 93, 93, 0 },
      { 255, 255, 127 },
      { 201, 201, 100 },
      { 147, 147, 73 },
      { 93, 93, 46 } },
    { { 0, 0, 255 },
      { 0, 0, 201 },
      { 0, 0, 147 },
      { 0, 0, 93 },
      { 127, 0, 255 },
      { 100, 0, 201 },
      { 73, 0, 147 },
      { 46, 0, 93 } },
    { { 0, 255, 255 },
      { 0, 201, 201 },
      { 0, 147, 147 },
      { 0, 93, 93 },
      { 255, 0, 255 },
      { 201, 0, 201 },
      { 147, 0, 147 },
      { 93, 0, 93 } },
    { { 159, 223, 223 },
      { 125, 175, 175 },
      { 91, 128, 128 },
      { 57, 81, 81 },
      { 223, 159, 223 },
      { 175, 125, 175 },
      { 128, 91, 128 },
      { 81, 57, 81 } },
    { { 101, 101, 255 },
      { 178, 101, 255 },
      { 255, 101, 255 },
      { 255, 101, 178 },
      { 255, 101, 101 },
      { 255, 178, 101 },
      { 255, 229, 101 },
      { 255, 244, 182 } },
    { { 0, 0, 0 },
      { 34, 34, 34 },
      { 68, 68, 68 },
      { 102, 102, 102 },
      { 136, 136, 136 },
      { 170, 170, 170 },
      { 204, 204, 204 },
      { 255, 255, 255 } },
};

void MachineCreate_GetColorSelectionPos(u8 red, u8 green, u8 blue) {

    for (sColorSelectYPos = 0; sColorSelectYPos < 8; sColorSelectYPos++) {
        for (sColorSelectXPos = 0; sColorSelectXPos < 8; sColorSelectXPos++) {
            if ((red == sColorSelections[sColorSelectYPos][sColorSelectXPos][0]) &&
                (green == sColorSelections[sColorSelectYPos][sColorSelectXPos][1]) &&
                (blue == sColorSelections[sColorSelectYPos][sColorSelectXPos][2])) {
                return;
            }
        }
    }
}

extern CustomMachine gCustomMachine;

Gfx* MachineCreate_DrawColorSelectionBorder(Gfx* gfx) {

    switch (gWorksMachineMode) {
        case MACHINE_MODE_BODY_COLOR:
            MachineCreate_GetColorSelectionPos(gCustomMachine.red, gCustomMachine.green, gCustomMachine.blue);
            break;
        case MACHINE_MODE_LINE_COLOR:
            MachineCreate_GetColorSelectionPos(gCustomMachine.decalR, gCustomMachine.decalG, gCustomMachine.decalB);
            break;
        case MACHINE_MODE_NUMBER_COLOR:
            MachineCreate_GetColorSelectionPos(gCustomMachine.numberR, gCustomMachine.numberG, gCustomMachine.numberB);
            break;
        case MACHINE_MODE_COCKPIT_COLOR:
            MachineCreate_GetColorSelectionPos(gCustomMachine.cockpitR, gCustomMachine.cockpitG,
                                               gCustomMachine.cockpitB);
            break;
    }
    if ((sColorSelectXPos != 8) && (sColorSelectYPos != 8)) {
        gfx = ExpansionKit_DrawRectangleBorder(gfx, sColorSelectXPos * 15 + 168, sColorSelectYPos * 15 + 44,
                                               (sColorSelectXPos + 1) * 15 + 168, (sColorSelectYPos + 1) * 15 + 44,
                                               GPACK_RGBA5551(255, 255, 255, 1), 2, 2);
    }
    return gfx;
}

extern unk_80140E60 D_xk3_80140E68;

Gfx* MachineCreate_DrawColorSelectionCursor(Gfx* gfx) {

    if (D_xk3_80140E68.unk_04 == 8) {
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aMachineCreateHighlightedOkTex, 257, 165, 32, 16);
    } else {

        gfx = ExpansionKit_DrawRectangleBorderHighlight(
            gfx, D_xk3_80140E68.unk_00 * 15 + 168, D_xk3_80140E68.unk_04 * 15 + 44,
            (D_xk3_80140E68.unk_00 + 1) * 15 + 168, (D_xk3_80140E68.unk_04 + 1) * 15 + 44, 255, 64, 64,
            func_xk1_800290C0(), 2, 2);
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aMachineCreateOkTex, 257, 165, 32, 16);
    }
    return gfx;
}

Gfx* MachineCreate_DrawColorSelection(Gfx* gfx, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_xk3_80137440);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1))
        gDPFillRectangle(gfx++, 168, 44, 288, 164);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    for (sColorSelectYPos = 0; sColorSelectYPos < 8; sColorSelectYPos++) {
        for (sColorSelectXPos = 0; sColorSelectXPos < 8; sColorSelectXPos++) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, sColorSelections[sColorSelectYPos][sColorSelectXPos][0],
                            sColorSelections[sColorSelectYPos][sColorSelectXPos][1],
                            sColorSelections[sColorSelectYPos][sColorSelectXPos][2], 255);
            gDPFillRectangle(gfx++, sColorSelectXPos * 15 + 169, sColorSelectYPos * 15 + 45,
                             (sColorSelectXPos + 1) * 15 + 168, (sColorSelectYPos + 1) * 15 + 44);
        }
    }
    gfx = MachineCreate_DrawColorSelectionBorder(gfx);
    gfx = MachineCreate_DrawColorSelectionCursor(gfx);
    return gfx;
}

extern BorderedBoxWidget* gMachineCreateColorBox;

void func_xk3_80135E58(u8* red, u8* green, u8* blue) {

    if (!BorderedBox_GetInfo(gMachineCreateColorBox, IS_BORDERED_BOX_OPENED)) {
        return;
    }

    if (D_xk3_80140E68.unk_04 == 8) {
        func_xk3_8012BC98();
        Audio_TriggerSystemSE(NA_SE_36);
    } else if ((*red != sColorSelections[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][0]) ||
               (*green != sColorSelections[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][1]) ||
               (*blue != sColorSelections[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][2])) {
        *red = sColorSelections[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][0];
        *green = sColorSelections[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][1];
        *blue = sColorSelections[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][2];
        Audio_TriggerSystemSE(NA_SE_39);
    }
}
