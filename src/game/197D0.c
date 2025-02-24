#include "global.h"
#include "fzx_thread.h"
#include "PR/leo.h"

OSIoMesg sLeoFontIoMsg;
s16* sLeoPrintFrameBuffer;
s16* sLeoPrintCurPixel;
#ifdef VERSION_JP
s32 sLeoFontOffsets[24];
#else
s32 sLeoFontWidths[96];
s32 sLeoFontHeights[96];
s32 sLeoFontAlignments[96];
#endif

#ifdef VERSION_JP
#define SHIFT_JIS(x) ((((x) & 0xFF00) >> 8), ((x) & 0xFF))
u8 D_800CD580[] = { SHIFT_JIS(0x824F), SHIFT_JIS(0) }; // 0

u8 D_800CD584[] = { SHIFT_JIS(0x8250), SHIFT_JIS(0) }; // 1

u8 D_800CD588[] = { SHIFT_JIS(0x8251), SHIFT_JIS(0) }; // 2

u8 D_800CD58C[] = { SHIFT_JIS(0x8252), SHIFT_JIS(0) }; // 3

u8 D_800CD590[] = { SHIFT_JIS(0x8253), SHIFT_JIS(0) }; // 4

u8 D_800CD594[] = { SHIFT_JIS(0x8254), SHIFT_JIS(0) }; // 5

u8 D_800CD598[] = { SHIFT_JIS(0x8255), SHIFT_JIS(0) }; // 6

u8 D_800CD59C[] = { SHIFT_JIS(0x8256), SHIFT_JIS(0) }; // 7

u8 D_800CD5A0[] = { SHIFT_JIS(0x8257), SHIFT_JIS(0) }; // 8

u8 D_800CD5A4[] = { SHIFT_JIS(0x8258), SHIFT_JIS(0) }; // 9

u8 D_800CD5A8[] = { // エラー番号
    SHIFT_JIS(0x8347), SHIFT_JIS(0x8389), SHIFT_JIS(0x815B), SHIFT_JIS(0x94D4), SHIFT_JIS(0x8D86), SHIFT_JIS(0),
};

u8 D_800CD5B4[] = { // 取り扱い説明書をお読みください。
    SHIFT_JIS(0x8EE6), SHIFT_JIS(0x82E8), SHIFT_JIS(0x88B5), SHIFT_JIS(0x82A2), SHIFT_JIS(0x90E0), SHIFT_JIS(0x96BE),
    SHIFT_JIS(0x8F91), SHIFT_JIS(0x82F0), SHIFT_JIS(0x82A8), SHIFT_JIS(0x93C7), SHIFT_JIS(0x82DD), SHIFT_JIS(0x82AD),
    SHIFT_JIS(0x82BE), SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_800CD5D8[] = { // 【注意】アクセスランプ点滅中に
    SHIFT_JIS(0x8179), SHIFT_JIS(0x928D), SHIFT_JIS(0x88D3), SHIFT_JIS(0x817A), SHIFT_JIS(0x8341), SHIFT_JIS(0x834E),
    SHIFT_JIS(0x835A), SHIFT_JIS(0x8358), SHIFT_JIS(0x8389), SHIFT_JIS(0x8393), SHIFT_JIS(0x8376), SHIFT_JIS(0x935F),
    SHIFT_JIS(0x96C5), SHIFT_JIS(0x9286), SHIFT_JIS(0x82C9), SHIFT_JIS(0),
};

u8 D_800CD5F8[] = { // ディスクを抜かないでください。
    SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82F0), SHIFT_JIS(0x94B2),
    SHIFT_JIS(0x82A9), SHIFT_JIS(0x82C8), SHIFT_JIS(0x82A2), SHIFT_JIS(0x82C5), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE),
    SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_800CD618[] = { // もう一度ディスクを挿入して
    SHIFT_JIS(0x82E0), SHIFT_JIS(0x82A4), SHIFT_JIS(0x88EA), SHIFT_JIS(0x9378), SHIFT_JIS(0x8366),
    SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82F0), SHIFT_JIS(0x917D),
    SHIFT_JIS(0x93FC), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82C4), SHIFT_JIS(0),
};

u8 D_800CD634[] = { // ください。
    SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE), SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_800CD640[] = { // イジェクトボタンが押されてい
    SHIFT_JIS(0x8343), SHIFT_JIS(0x8357), SHIFT_JIS(0x8346), SHIFT_JIS(0x834E), SHIFT_JIS(0x8367),
    SHIFT_JIS(0x837B), SHIFT_JIS(0x835E), SHIFT_JIS(0x8393), SHIFT_JIS(0x82AA), SHIFT_JIS(0x899F),
    SHIFT_JIS(0x82B3), SHIFT_JIS(0x82EA), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82A2), SHIFT_JIS(0),
};

u8 D_800CD660[] = { // ませんか。
    SHIFT_JIS(0x82DC), SHIFT_JIS(0x82B9), SHIFT_JIS(0x82F1), SHIFT_JIS(0x82A9), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_800CD66C[] = { // 一度ディスクを抜いてきちんと
    SHIFT_JIS(0x88EA), SHIFT_JIS(0x9378), SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358),
    SHIFT_JIS(0x834E), SHIFT_JIS(0x82F0), SHIFT_JIS(0x94B2), SHIFT_JIS(0x82A2), SHIFT_JIS(0x82C4),
    SHIFT_JIS(0x82AB), SHIFT_JIS(0x82BF), SHIFT_JIS(0x82F1), SHIFT_JIS(0x82C6), SHIFT_JIS(0),
};

u8 D_800CD68C[] = { // 差し込んでください。
    SHIFT_JIS(0x8DB7), SHIFT_JIS(0x82B5), SHIFT_JIS(0x8D9E), SHIFT_JIS(0x82F1), SHIFT_JIS(0x82C5), SHIFT_JIS(0x82AD),
    SHIFT_JIS(0x82BE), SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_800CD6A4[] = { // 間違ったディスクが挿入されている
    SHIFT_JIS(0x8AD4), SHIFT_JIS(0x88E1), SHIFT_JIS(0x82C1), SHIFT_JIS(0x82BD), SHIFT_JIS(0x8366), SHIFT_JIS(0x8342),
    SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82AA), SHIFT_JIS(0x917D), SHIFT_JIS(0x93FC), SHIFT_JIS(0x82B3),
    SHIFT_JIS(0x82EA), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82A2), SHIFT_JIS(0x82E9), SHIFT_JIS(0),
};

u8 D_800CD6C8[] = { // 可能性があります。確認して
    SHIFT_JIS(0x89C2), SHIFT_JIS(0x945C), SHIFT_JIS(0x90AB), SHIFT_JIS(0x82AA), SHIFT_JIS(0x82A0),
    SHIFT_JIS(0x82E8), SHIFT_JIS(0x82DC), SHIFT_JIS(0x82B7), SHIFT_JIS(0x8142), SHIFT_JIS(0x8A6D),
    SHIFT_JIS(0x9446), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82C4), SHIFT_JIS(0),
};

u8 D_800CD6E4[] = { // ディスクが差し込まれていますか。
    SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82AA), SHIFT_JIS(0x8DB7),
    SHIFT_JIS(0x82B5), SHIFT_JIS(0x8D9E), SHIFT_JIS(0x82DC), SHIFT_JIS(0x82EA), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82A2),
    SHIFT_JIS(0x82DC), SHIFT_JIS(0x82B7), SHIFT_JIS(0x82A9), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_800CD708[] = { // 起動時のディスクを挿入して
    SHIFT_JIS(0x8B4E), SHIFT_JIS(0x93AE), SHIFT_JIS(0x8E9E), SHIFT_JIS(0x82CC), SHIFT_JIS(0x8366),
    SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82F0), SHIFT_JIS(0x917D),
    SHIFT_JIS(0x93FC), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82C4), SHIFT_JIS(0),
};

u8* sLeoErrorMessages[] = {
    D_800CD580, D_800CD584, D_800CD588, D_800CD58C, D_800CD590, D_800CD594, D_800CD598, D_800CD59C,
    D_800CD5A0, D_800CD5A4, D_800CD5A8, D_800CD5B4, D_800CD5D8, D_800CD5F8, D_800CD618, D_800CD634,
    D_800CD640, D_800CD660, D_800CD66C, D_800CD68C, D_800CD6A4, D_800CD6C8, D_800CD6E4, D_800CD708,
};
#else
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
#endif

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

#ifdef VERSION_JP
void LeoDD_CopyFontToRam(s32* code, u8* ramAddr) {
    uintptr_t fontAddr = LeoGetKAdr(code) + DDROM_FONT_START;
#else
void LeoDD_CopyFontToRam(s32* code, u8* ramAddr, s32* width, s32* height, s32* alignment) {
    uintptr_t fontAddr = LeoGetAAdr2(code, width, height, alignment) + DDROM_FONT_START;
#endif

    sLeoFontIoMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    sLeoFontIoMsg.hdr.retQueue = &gDmaMesgQueue;
    sLeoFontIoMsg.dramAddr = ramAddr;
    sLeoFontIoMsg.devAddr = fontAddr;
    sLeoFontIoMsg.size = 0x80; // leo font size
    gDriveRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(gDriveRomHandle, &sLeoFontIoMsg, OS_READ);
    MQ_WAIT_FOR_MESG(&gDmaMesgQueue, NULL);
}

#ifdef VERSION_JP
s32 LeoDD_LoadFontSet(u8* codes, s32 fontOffset, s32 fontRamAddr) {
    s16 i;

    for (i = 0; codes[i] != 0; fontOffset += 0x80, i += 2) {
        LeoDD_CopyFontToRam((codes[i] << 8) + codes[i + 1], fontRamAddr + fontOffset);
    }

    return fontOffset;
}

void func_8007F8F8(u32 messageCount, u8** messages, u8* fontRamAddr, s32* offsets) {
    s32 fontOffset;
    s32 i;

    fontOffset = 0;

    for (i = 0; i < messageCount; i++) {
        offsets[i] = fontOffset;
        fontOffset = LeoDD_LoadFontSet(messages[i], fontOffset, fontRamAddr);
    }
}
#else
void LeoDD_LoadFontSet(s32* codes, u8* fontRamAddr, s32* widths, s32* heights, s32* alignments) {
    s32 i;
    s32 fontOffset;

    for (i = 0, fontOffset = 0; codes[i] != 0; fontOffset += 0x80, i++) {
        LeoDD_CopyFontToRam(codes[i], fontRamAddr + fontOffset, &widths[i], &heights[i], &alignments[i]);
    }
}
#endif

extern u8 gLeoFontBuffer[];

#ifdef VERSION_JP
void LeoDD_LoadFonts(void) {
    func_8007F8F8(ARRAY_COUNT(sLeoErrorMessages), sLeoErrorMessages, gLeoFontBuffer, sLeoFontOffsets);
}
#else
void LeoDD_LoadFonts(void) {
    LeoDD_LoadFontSet(sLeoFontCodes, gLeoFontBuffer, sLeoFontWidths, sLeoFontHeights, sLeoFontAlignments);
}
#endif

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
            *(--var_v0 + 1) = 0x0001000100010001;
        }
    }

    LeoDD_ForceWritebackDCacheAll();
}

#ifdef VERSION_JP
void func_8007FA64(s32 posX, s32 posY, u8* fontCharData) {
    u8 i;
    u16 j;
    s32 temp_a3;
    s32 temp_t1;
    u8* fontPtr = fontCharData;

    for (i = posY; i < posY + 16; i++) {
        for (j = posX; j < posX + 16; j += 2, fontPtr++) {
            temp_a3 = (*fontPtr >> 4) & 0xFF;
            temp_t1 = *fontPtr & 0xFF;
            sLeoPrintCurPixel = sLeoPrintFrameBuffer + (i * SCREEN_WIDTH) + j;
            temp_t1 &= 0xF;
            if (temp_a3 != 0) {
                *sLeoPrintCurPixel = sLeoFontPallete[temp_a3];
            }

            sLeoPrintCurPixel++;
            if (temp_t1) {
                *sLeoPrintCurPixel = sLeoFontPallete[temp_t1];
            }
        }
    }
}
#else
void func_8007FA64(s32 posX, s32 posY, u8* fontCharData, s32 width, s32 height, s32 alignment) {
    u8 i;
    u16 j;
    s32 temp_a3;
    s32 temp_t1;
    u8* fontPtr = fontCharData;

    posY += 12;

    for (i = (posY - alignment); i < (posY - alignment) + height; i++) {
        for (j = posX; j < posX + width; j += 2, fontPtr++) {
            temp_a3 = (*fontPtr >> 4) & 0xFF;
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
#endif

#ifdef VERSION_JP
void LeoDD_DrawErrorMessage(s32 posX, s32 posY, u16 messageNo) {
    s32 messageOffset;
    s32 offset;
    s32 i;

    messageOffset = sLeoFontOffsets[messageNo];
    for (i = 0, offset = 0; sLeoErrorMessages[messageNo][i] != 0; i += 2) {
        func_8007FAD4(posX, posY, gLeoFontBuffer + messageOffset + offset);

        posX += 16;
        offset += 0x80;
    }
}

void LeoDD_DrawErrorMessageNumber(s32 posX, s32 posY, s8* str) {
    s8 var_v1;
    s32 offset;
    s8* var_s1;

    if (*str == '1') {
        posX -= 2;
    }

    var_s1 = str;
    while (*var_s1 != 0) {
        offset = sLeoFontOffsets[*var_s1 - '0'];
        func_8007FAD4(posX, posY, gLeoFontBuffer + offset);
        if (*var_s1 == '1') {
            posX += 7;
        } else {
            posX += 9;
        }
        var_s1++;
    }
}
#else
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
#endif

typedef enum LeoErrorMessageJP {
    /* Digits 0-9 Are 0-9 */
    LEO_ERROR_MESSAGE_ERROR_NUMBER = 10,
    LEO_ERROR_MESSAGE_USER_GUIDE,
    LEO_ERROR_MESSAGE_CAUTION_WHILE_BLINKING,
    LEO_ERROR_MESSAGE_DO_NOT_REMOVE_DISC,
    LEO_ERROR_MESSAGE_INSERT_DISC_AGAIN,
    LEO_ERROR_MESSAGE_PLEASE,
    LEO_ERROR_MESSAGE_IS_EJECT_BUTTON,
    LEO_ERROR_MESSAGE_PRESSED,
    LEO_ERROR_MESSAGE_PLEASE_REMOVE_DISC_ONCE,
    LEO_ERROR_MESSAGE_INSERT_IT_PROPERLY,
    LEO_ERROR_MESSAGE_WRONG_DISK_MAY,
    LEO_ERROR_MESSAGE_BE_INSERTED_HAVE_YOU_CHECKED,
    LEO_ERROR_MESSAGE_CHECK_DISK_IS_INSERTED,
    LEO_ERROR_MESSAGE_INSERT_DISK_AT_STARTUP,
} LeoErrorMessageJP;

void LeoDD_DrawErrorNumber(s32 errNo) {
    char errNoStr[4];

    sprintf(errNoStr, "%02d", errNo);
#ifdef VERSION_JP
    LeoDD_DrawErrorMessage(108, 80, LEO_ERROR_MESSAGE_ERROR_NUMBER);
    LeoDD_DrawErrorMessageNumber(190, 80, errNoStr);
#else
    LeoDD_DrawErrorMessage(97, 80, "Error Number");
    LeoDD_DrawErrorMessage(201, 80, errNoStr);
#endif
}

void LeoDD_DrawReferUserGuide(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
#ifdef VERSION_JP
    LeoDD_DrawErrorMessage(36, 110, LEO_ERROR_MESSAGE_USER_GUIDE);
#else
    LeoDD_DrawErrorMessage(40, 110, "Please refer to the User's Guide.");
#endif
}

void LeoDD_DrawCautionDoNotRemove(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
#ifdef VERSION_JP
    LeoDD_DrawErrorMessage(40, 100, LEO_ERROR_MESSAGE_CAUTION_WHILE_BLINKING);
    LeoDD_DrawErrorMessage(40, 120, LEO_ERROR_MESSAGE_DO_NOT_REMOVE_DISC);
#else
    LeoDD_DrawErrorMessage(45, 90, "Caution : Please do not remove");
    LeoDD_DrawErrorMessage(45, 110, "the disk while the access lamp");
    LeoDD_DrawErrorMessage(45, 130, "is blinking.");
#endif
}

void LeoDD_DrawCautionDoNotRemovePleaseInsert(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
#ifdef VERSION_JP
    LeoDD_DrawErrorMessage(40, 110, LEO_ERROR_MESSAGE_CAUTION_WHILE_BLINKING);
    LeoDD_DrawErrorMessage(40, 130, LEO_ERROR_MESSAGE_DO_NOT_REMOVE_DISC);
    LeoDD_DrawErrorMessage(40, 150, LEO_ERROR_MESSAGE_INSERT_DISC_AGAIN);
    LeoDD_DrawErrorMessage(40, 170, LEO_ERROR_MESSAGE_PLEASE);
#else
    LeoDD_DrawErrorMessage(45, 110, "Caution : Please do not remove");
    LeoDD_DrawErrorMessage(45, 130, "the disk while the access lamp");
    LeoDD_DrawErrorMessage(45, 150, "is blinking.");
    LeoDD_DrawErrorMessage(45, 170, "Please insert the disk.");
#endif
}

void LeoDD_DrawReinsertDisk(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
#ifdef VERSION_JP
    LeoDD_DrawErrorMessage(48, 110, LEO_ERROR_MESSAGE_IS_EJECT_BUTTON);
    LeoDD_DrawErrorMessage(48, 130, LEO_ERROR_MESSAGE_PRESSED);
    LeoDD_DrawErrorMessage(48, 150, LEO_ERROR_MESSAGE_PLEASE_REMOVE_DISC_ONCE);
    LeoDD_DrawErrorMessage(48, 170, LEO_ERROR_MESSAGE_INSERT_IT_PROPERLY);
#else
    LeoDD_DrawErrorMessage(53, 110, "The eject button may have");
    LeoDD_DrawErrorMessage(53, 130, "been pushed. Please remove");
    LeoDD_DrawErrorMessage(53, 150, "the Disk once and completely");
    LeoDD_DrawErrorMessage(53, 170, "reinsert it.");
#endif
}

void LeoDD_DrawWrongDisk(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
#ifdef VERSION_JP
    LeoDD_DrawErrorMessage(32, 90, LEO_ERROR_MESSAGE_WRONG_DISK_MAY);
    LeoDD_DrawErrorMessage(32, 110, LEO_ERROR_MESSAGE_BE_INSERTED_HAVE_YOU_CHECKED);
    LeoDD_DrawErrorMessage(32, 130, LEO_ERROR_MESSAGE_PLEASE);
#else
    LeoDD_DrawErrorMessage(56, 100, "The wrong disk may have");
    LeoDD_DrawErrorMessage(56, 120, "been inserted. Please check.");
#endif
}

void LeoDD_DrawIsDiskInserted(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
#ifdef VERSION_JP
    LeoDD_DrawErrorMessage(36, 110, LEO_ERROR_MESSAGE_CHECK_DISK_IS_INSERTED);
#else
    LeoDD_DrawErrorMessage(59, 110, "Has the disk been inserted?");
#endif
}

void LeoDD_DrawInsertInitialDiskUsed(void) {
    LeoDD_SetFramebuffer();
    LeoDD_DrawErrorBox();
#ifdef VERSION_JP
    LeoDD_DrawErrorMessage(56, 100, LEO_ERROR_MESSAGE_INSERT_DISK_AT_STARTUP);
    LeoDD_DrawErrorMessage(56, 120, LEO_ERROR_MESSAGE_PLEASE);
#else
    LeoDD_DrawErrorMessage(55, 100, "Please insert initial disk");
    LeoDD_DrawErrorMessage(55, 120, "used when turned power ON.");
#endif
}
