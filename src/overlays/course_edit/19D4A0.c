#include "global.h"
#include "leo/mfs.h"

s32 D_xk2_80103F10 = 0;
s32 D_xk2_80103F14 = 0;

extern u8 gEditCupTrackNames[4 * 6][9];
extern unk_800D6CA0 D_800D6CA0;

void func_xk2_800EB9E0(void) {
    if (SLCheckDiskChange2()) {
        func_807685D8(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames));
    }
    D_800D6CA0.unk_08 = 0x36;
}

void func_xk2_800EBA34(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (Mfs_ValidateFileName(gEditCupTrackNames[i]) != 0) {
            gEditCupTrackNames[i][0] = 0;
        }
    }

    for (i = 0; i < 6; i++) {
        if ((gEditCupTrackNames[i][0] != '\0') &&
            (Mfs_GetFileIndex(MFS_ENTRY_WORKING_DIR, gEditCupTrackNames[i], "CRSD") == MFS_ENTRY_DOES_NOT_EXIST) &&
            (Mfs_GetFileIndex(MFS_ENTRY_WORKING_DIR, gEditCupTrackNames[i], "CRSE") == MFS_ENTRY_DOES_NOT_EXIST)) {
            gEditCupTrackNames[i][0] = '\0';
        }
    }
    D_xk2_80103F14 = 0;
    D_800D6CA0.unk_08 = 0x20;
}

extern Gfx D_8014940[];

extern s32 D_xk1_8003A554;
extern s32 D_xk1_80032AD0;

Gfx* func_xk2_800EBB24(Gfx* gfx) {
    s32 temp_s4;
    s32 i;
    s32 var_s2;
    u8* var_s3;

    temp_s4 = (D_xk1_8003A554 - 0x34) / 8;

    if (D_800D6CA0.unk_08 != 0x20) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_8014940);

    func_xk1_8002AF1C(&gfx, 0xC8, 0x50, 0xC, 8);

    for (i = 0; i < 6; i++) {
        var_s3 = gEditCupTrackNames[i];
        var_s2 = (i * 8) + 0x58;
        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

        if (i == temp_s4) {
            gDPSetPrimColor(gfx++, 0, 0, 190, 175, 255, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 0);
        }

        gSPTextureRectangle(gfx++, 206 << 2, var_s2 << 2, 290 << 2, (var_s2 + 8) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gDPPipeSync(gfx++);

        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);

        if (var_s3[0] == '\0') {
            gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
            if (i == temp_s4) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
            }
            D_xk1_80032AD0 = 0;
            gfx = func_xk1_8002924C(gfx, 0xD0, var_s2, "%d:", i + 1);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            if (i == temp_s4) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
            }
            gfx = func_xk1_8002924C(gfx, 0xD0, var_s2, "%d:%s", i + 1, var_s3);
        }
    }
    PRINTF("ENTRY.c\n");
    PRINTF("EDIT_MODE_COURSE 40\n");

    return gfx;
}

extern s32 gCourseEditEntryOption;

void func_xk2_800EBE14(void) {
    if ((gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) && (D_800D6CA0.unk_08 == 0x20)) {
        Audio_TriggerSystemSE(NA_SE_37);
        D_800D6CA0.unk_08 = 0;
        gCourseEditEntryOption = -1;
    }
}

void func_xk2_800EBE90(void) {
    s32 sp1C;

    sp1C = D_xk2_80103F14;
    func_xk1_8002DBD4(&D_xk2_80103F14, 5, 0);

    if (sp1C != D_xk2_80103F14) {
        Audio_TriggerSystemSE(NA_SE_35);
    }
    D_xk1_8003A554 = (D_xk2_80103F14 * 8) + 0x38;
}

extern s32 D_80119880;
extern s32 D_80119890;
extern s32 D_xk1_80032C20;
extern u8 D_xk2_800F7400;

void func_xk2_800EBEF4(void) {
    if ((gControllers[gPlayerControlPorts[0]].buttonPressed & 0x8000) && (D_800D6CA0.unk_08 == 0x20)) {
        Audio_TriggerSystemSE(NA_SE_36);
        D_xk2_80103F10 = (D_xk1_8003A554 - 0x34) / 8;
        switch (D_80119890) {
            case 0:
                D_800D6CA0.unk_08 = 0x31;
                D_80119880 = 5;
                func_8076877C(0, "CRSD");
                D_xk2_800F7400 = 1;
                break;
            case 1:
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x23;
                break;
        }
    }

    PRINTF("(%s)-(%s) CLEAR\n");
}

void func_xk2_800EBFE8(char* name) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (mfsStrCmp(name, gEditCupTrackNames[i]) == 0) {
            gEditCupTrackNames[i][0] = '\0';
        }
    }
}

extern unk_8003A5D8 D_xk1_8003A5D8[];

void func_xk2_800EC04C(void) {
    bool var_s3;
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        var_s3 = true;
        if (gEditCupTrackNames[i][0] != '\0') {
            for (j = 0; j < func_xk1_8002BFA4(); j++) {
                if (mfsStrCmp(D_xk1_8003A5D8[j].name, gEditCupTrackNames[i]) == 0) {
                    var_s3 = false;
                }
            }
            if (var_s3) {
                gEditCupTrackNames[i][0] = '\0';
            }
        }
    }
}

void func_xk2_800EC110(void) {
    func_8070405C(false);
    func_80768434(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames), 0, 0xFF,
                  1);
    gCourseEditEntryOption = -1;
}

void func_xk2_800EC174(void) {
    PRINTF("ENTRY SAVE AFTER DELETE OR RENAME\n");

    func_8070405C(false);
    func_807682C0(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames), 0, 0xFF,
                  1);
    gCourseEditEntryOption = -1;
}

void func_xk2_800EC1D8(void) {
    func_8070405C(false);
    func_8076833C(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames), 0, 0xFF,
                  1);
}

s32 func_xk2_800EC234(unk_8003A5D8* arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (mfsStrCmp(arg0->name, gEditCupTrackNames[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
