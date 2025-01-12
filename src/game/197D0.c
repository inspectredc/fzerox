#include "global.h"
#include "fzxthread.h"
#include "PR/leo.h"

OSIoMesg sLeoFontIoMsg;
s16* sLeoPrintFrameBuffer;
s16* sLeoPrintCurPixel;
s32 sLeoFontWidths[96];
s32 sLeoFontHeights[96];
s32 sLeoFontAlignments[96];

s32 sLeoFontCodes[] = {
    0x6CA06F18, 0x6CB82A14, 0x6CBE4314, 0x6CC29A14, 0x6CDE8D16, 0x6CFADB14, 0x6D249B14, 0x6D422314, 0x6D445D14,
    0x6D594D14, 0x6D675414, 0x6D6F870E, 0x6D7F2402, 0x6D829108, 0x6D872102, 0x6D885A14, 0x6D998B14, 0x6DB15A14,
    0x6DC28A14, 0x6DD88B14, 0x6DF08A14, 0x6E068B14, 0x6E1E8B14, 0x6E368A14, 0x6E4C8B14, 0x6E648B14, 0x6E7C270E,
    0x6E802A0E, 0x6E86970E, 0x6E9A850C, 0x6EA6970E, 0x6EBA7A14, 0x6ED0DB14, 0x6EFAAA14, 0x6F169A14, 0x6F32AB14,
    0x6F509A14, 0x6F6C9A14, 0x6F889A14, 0x6FA4AB14, 0x6FC2AA14, 0x6FDE2A14, 0x6FE47B14, 0x6FFC9A14, 0x70188A14,
    0x702EBA14, 0x704F9A14, 0x706BBB14, 0x708F9A14, 0x70ABBB14, 0x70CF9A14, 0x70EB9B14, 0x7109AA14, 0x71259B14,
    0x7143AA14, 0x715FEA14, 0x7186AA14, 0x71A2AA14, 0x71BE9A14, 0x71DA3D14, 0x71E87A14, 0x71FE4D14, 0x720C5214,
    0x721190FC, 0x6CA06F18, 0x722C8910, 0x72408B14, 0x72588910, 0x726C7C16, 0x72868910, 0x729A6A14, 0x72AB8C10,
    0x72C57A14, 0x72DB2A14, 0x72E14E14, 0x72F07A14, 0x73062A14, 0x730CB810, 0x73277810, 0x73398910, 0x734D8C10,
    0x73678C10, 0x73815810, 0x738F7910, 0x73A34A12, 0x73AE780E, 0x73C0870E, 0x73D0B70E, 0x73E8770E, 0x73F88B0E,
    0x7410770E, 0x74205D14, 0x74352A14, 0x743B6D14, 0x74506114, 0x00000000
};

u16 sLeoFontPallete[] = {
    GPACK_RGBA5551(0, 0, 0, 1),       GPACK_RGBA5551(16, 16, 16, 1),    GPACK_RGBA5551(32, 32, 32, 1),
    GPACK_RGBA5551(48, 48, 48, 1),    GPACK_RGBA5551(64, 64, 64, 1),    GPACK_RGBA5551(80, 80, 80, 1),
    GPACK_RGBA5551(96, 96, 96, 1),    GPACK_RGBA5551(112, 112, 112, 1), GPACK_RGBA5551(136, 136, 136, 1),
    GPACK_RGBA5551(152, 152, 152, 1), GPACK_RGBA5551(168, 168, 168, 1), GPACK_RGBA5551(184, 184, 184, 1),
    GPACK_RGBA5551(200, 200, 200, 1), GPACK_RGBA5551(216, 216, 216, 1), GPACK_RGBA5551(232, 232, 232, 1),
    GPACK_RGBA5551(255, 255, 255, 1),
};

extern OSMesgQueue gDmaMesgQueue;
extern OSPiHandle* gDriveRomHandle;

void LeoDD_CopyFontToRam(s32* code, u8* ramAddr, s32* width, s32* height, s32* alignment) {
    uintptr_t fontAddr = LeoGetAAdr2(code, width, height, alignment) + DDROM_FONT_START;

    sLeoFontIoMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    sLeoFontIoMsg.hdr.retQueue = &gDmaMesgQueue;
    sLeoFontIoMsg.dramAddr = ramAddr;
    sLeoFontIoMsg.devAddr = fontAddr;
    sLeoFontIoMsg.size = 0x80; // leo font size
    gDriveRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(gDriveRomHandle, &sLeoFontIoMsg, OS_READ);
    MQ_WAIT_FOR_MESG(&gDmaMesgQueue, NULL);
}

void LeoDD_LoadFontSet(s32* codes, u8* fontRamAddr, s32* widths, s32* heights, s32* alignments) {
    s32 i;
    s32 fontOffset;

    for (i = 0, fontOffset = 0; codes[i] != 0; fontOffset += 0x80, i++) {
        LeoDD_CopyFontToRam(codes[i], fontRamAddr + fontOffset, &widths[i], &heights[i], &alignments[i]);
    }
}

extern u8 gLeoFontBuffer[];

void LeoDD_LoadFonts(void) {
    LeoDD_LoadFontSet(sLeoFontCodes, gLeoFontBuffer, sLeoFontWidths, sLeoFontHeights, sLeoFontAlignments);
}

void LeoDD_SetFramebuffer(void) {
    sLeoPrintFrameBuffer = osViGetNextFramebuffer();
}

void LeoDD_DrawErrorBox(void) {
    u8 i;
    u16 j;

    for (i = 75; i < 191; i++) {
        for (j = 22; j < 298; j++) {
            sLeoPrintCurPixel = sLeoPrintFrameBuffer + (i * SCREEN_WIDTH) + j;
            *sLeoPrintCurPixel = 1;
        }
    }
}

extern FrameBuffer* D_800DCCD0[];

void func_8007F9E0(void) {
    u8 i;
    u64* temp_v1;
    u64* var_v0;

    LeoDD_ForceWritebackDCacheAll();

    for (i = 0; i < 3; i++) {
        temp_v1 = (u64*) D_800DCCD0[i];
        var_v0 = &temp_v1[19199];

        // FAKE
        while (var_v0 >= temp_v1) {
            var_v0--;
            var_v0[1] = 0x0001000100010001;
        }
    }

    LeoDD_ForceWritebackDCacheAll();
}

void func_8007FA64(s32 posX, s32 posY, u8* fontCharData, s32 width, s32 height, s32 alignment) {
    u8 i;
    u16 j;
    u8 temp_a3;
    u32 temp_t1;
    u8* fontPtr = fontCharData;

    posY += 12;

    for (i = (posY - alignment); i < (posY - alignment) + height; i++) {
        for (j = posX; j < posX + width; j += 2, fontPtr++) {
            temp_a3 = *fontPtr >> 4;
            temp_t1 = *fontPtr & 0xFF;
            sLeoPrintCurPixel = sLeoPrintFrameBuffer + (i * SCREEN_WIDTH) + j;
            temp_t1 &= 0xF;
            if (temp_a3 != 0) {
                *sLeoPrintCurPixel = sLeoFontPallete[temp_a3];
            }
            if (j + 1 < posX + width) {
                sLeoPrintCurPixel++;
                if (temp_t1) {
                    *sLeoPrintCurPixel = sLeoFontPallete[temp_t1];
                }
            }
        }
    }
}

void LeoDD_DrawErrorMessage(s32 posX, s32 posY, s8* str) {
    s32 fontChar;
    s32 i;

    for (i = 0; str[i] != 0; i++) {
        fontChar = str[i] - ' ';
        func_8007FA64(posX, posY, gLeoFontBuffer + fontChar * 0x80, sLeoFontWidths[fontChar], sLeoFontHeights[fontChar],
                      sLeoFontAlignments[fontChar]);
        // FAKE
        posX = posX + sLeoFontWidths[fontChar] + (0, 1);
    }
}

void LeoDD_DrawErrorNumber(s32 errNo) {
    char errNoStr[4];

    sprintf(errNoStr, "%02d", errNo);
    LeoDD_DrawErrorMessage(97, 80, "Error Number");
    LeoDD_DrawErrorMessage(201, 80, errNoStr);
}

void LeoDD_DrawReferUserGuide(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
    LeoDD_DrawErrorMessage(40, 110, "Please refer to the User's Guide.");
}

void LeoDD_DrawCautionDoNotRemove(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
    LeoDD_DrawErrorMessage(45, 90, "Caution : Please do not remove");
    LeoDD_DrawErrorMessage(45, 110, "the disk while the access lamp");
    LeoDD_DrawErrorMessage(45, 130, "is blinking.");
}

void LeoDD_DrawCautionDoNotRemovePleaseInsert(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
    LeoDD_DrawErrorMessage(45, 110, "Caution : Please do not remove");
    LeoDD_DrawErrorMessage(45, 130, "the disk while the access lamp");
    LeoDD_DrawErrorMessage(45, 150, "is blinking.");
    LeoDD_DrawErrorMessage(45, 170, "Please insert the disk.");
}

void LeoDD_DrawReinsertDisk(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
    LeoDD_DrawErrorMessage(53, 110, "The eject button may have");
    LeoDD_DrawErrorMessage(53, 130, "been pushed. Please remove");
    LeoDD_DrawErrorMessage(53, 150, "the Disk once and completely");
    LeoDD_DrawErrorMessage(53, 170, "reinsert it.");
}

void LeoDD_DrawWrongDisk(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
    LeoDD_DrawErrorMessage(56, 100, "The wrong disk may have");
    LeoDD_DrawErrorMessage(56, 120, "been inserted. Please check.");
}

void LeoDD_DrawIsDiskInserted(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
    LeoDD_DrawErrorMessage(59, 110, "Has the disk been inserted?");
}

void LeoDD_DrawInsertInitialDiskUsed(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
    LeoDD_DrawErrorMessage(55, 100, "Please insert initial disk");
    LeoDD_DrawErrorMessage(55, 120, "used when turned power ON.");
}
