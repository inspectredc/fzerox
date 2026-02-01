#include "global.h"

extern volatile unk_807C6EA8 D_807C6EA8;

void func_xk1_8002FB80(void) {
    func_xk1_8002FA50();
    D_807C6EA8.unk_04 = 0;
    D_807C6EA8.unk_08 = 0;
    D_807C6EA8.unk_0C = 0;
}

void func_xk1_8002FBB0(void) {
    D_807C6EA8.unk_04 = 0;
    D_807C6EA8.unk_08 = 0;
    D_807C6EA8.unk_0C = 0;
}

extern CustomMachinesInfo gCustomMachinesInfo;
extern u8 D_800D1308[];

void func_xk1_8002FBC8(void) {
    u8 i;

    for (i = 0; i < 30; i++) {
        if ((gCustomMachinesInfo.characterCustomState[i] < 0) && (D_800D1308[Character_GetCharacterFromSlot(i)] == 0)) {
            gCustomMachinesInfo.customMachines[i].number = 31;
            gCustomMachinesInfo.characterCustomState[i] = 0;
        }
    }
    func_8071E0C0();
}

extern CustomMachine gCustomMachine;

void func_xk1_8002FC70(void) {
    func_xk1_8002FFA0();
    gCustomMachine.number = 31;
    func_8071E0C0();
}

Gfx* ExpansionKit_DrawRectangleBorder(Gfx* gfx, u16 left, u16 top, u16 right, u16 bottom, u16 color, u8 borderWidth,
                                      u8 borderHeight) {

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetFillColor(gfx++, (color << 16) | color);
    gDPFillRectangle(gfx++, left, top, left + borderWidth - 1, bottom);
    gDPFillRectangle(gfx++, left, top, right, top + borderHeight - 1);
    gDPFillRectangle(gfx++, left, bottom - borderHeight + 1, right, bottom);
    gDPFillRectangle(gfx++, right - borderWidth + 1, top, right, bottom);

    return gfx;
}

Gfx* ExpansionKit_DrawRectangleBorderHighlight(Gfx* gfx, u16 left, u16 top, u16 right, u16 bottom, u8 red, u8 green,
                                               u8 blue, u8 alpha, u8 borderWidth, u8 borderHeight) {

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPFillRectangle(gfx++, left, top, left + borderWidth, bottom + 1);
    gDPFillRectangle(gfx++, left, top, right + 1, top + borderHeight);
    gDPFillRectangle(gfx++, left, bottom - borderHeight + 1, right + 1, bottom + 1);
    gDPFillRectangle(gfx++, right - borderWidth + 1, top, right + 1, bottom + 1);

    return gfx;
}
