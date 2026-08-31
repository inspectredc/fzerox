#include "global.h"
#include "leo/mfs.h"
#include "fzx_game.h"
#include ASSET_HEADER(course_track_gfx.h)
#include ASSET_HEADER(setup_gfx.h)
#include ASSET_HEADER_EK(expansion_kit_textures.h)

s32 sExpansionKitExistingFileCount;
EKLoadedFile gExpansionKitLoadedFiles[102];
u16 sExpansionKitFileMenuFileIds[900];
s32 sExpansionKitFileMenuSortElementSize;
s32 (*sExpansionKitFileMenuCompareFunc)(u8*, u8*);
s32 sExpansionKitFileMenuSort4ElementsSize;
s32 sExpansionKitFileMenuSort6ElementsSize;

s32 sExpansionKitFileListArrowFlashLength = 4;
s32 sExpansionKitEnableDrawFileMenu = false;
s32 sExpansionKitFileMenuEnableDrawConfirmText = false;
s32 sExpansionKitFileOptionIndex = 0;
UNUSED s32 D_xk1_80032BE0 = 8;
s32 sExpansionKitFileMenuLeft = 24;
s32 sExpansionKitFileMenuTop = 52;
s32 sExpansionKitFileListScroll = 0;
s32* sExpansionKitFileMenuCursorPosXPtr = NULL;
s32* sExpansionKitFileMenuCursorPosYPtr = NULL;
bool D_xk1_80032BF8 = false;

void func_xk1_8002AED0(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gExpansionKitLoadedFiles); i++) {
        gExpansionKitLoadedFiles[i].extension[3] = '\0';
    }
}

void EKFileMenu_SetFileListArrowFlashLength(s32 flashLength) {
    sExpansionKitFileListArrowFlashLength = flashLength;
}

void EKFileMenu_DrawFileMenuBorder(Gfx** gfxP, s32 left, s32 top, s32 numColumns, s32 numRows) {
    s32 texSOffset;
    s32 texTOffset;
    s32 row;
    s32 column;
    Gfx* gfx;

    gfx = *gfxP;
    gSPDisplayList(gfx++, D_8014940);

    gDPLoadTextureBlock(gfx++, aExpansionKitFileMenuBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 24, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    for (row = 0; row < numRows; row++) {
        for (column = 0; column < numColumns; column++) {
            texSOffset = 8;
            texTOffset = 8;
            if (column == 0) {
                texSOffset = 0;
            }
            if (column == numColumns - 1) {
                texSOffset = 16;
            }
            if (row == 0) {
                texTOffset = 0;
            }
            if (row == numRows - 1) {
                texTOffset = 16;
            }
            gSPTextureRectangle(gfx++, (left + (column * 8)) << 2, (top + (row * 8)) << 2,
                                (left + ((column + 1) * 8)) << 2, (top + ((row + 1) * 8) << 2), 0, texSOffset << 5,
                                texTOffset << 5, 1 << 10, 1 << 10);
        }
    }
    *gfxP = gfx;
}

void EKFileMenu_InitFileMenu(s32 left, s32 top, s32* cursorPosXPtr, s32* cursorPosYPtr) {
    sExpansionKitFileOptionIndex = 0;
    sExpansionKitFileMenuLeft = left;
    sExpansionKitFileMenuTop = top;
    sExpansionKitFileMenuCursorPosXPtr = cursorPosXPtr;
    sExpansionKitFileMenuCursorPosYPtr = cursorPosYPtr;
}

extern u32 gGameFrameCount;
extern s32 gGameMode;
extern s32 D_80119880;

Gfx* EKFileMenu_DrawFileMenu(Gfx* gfx, s32 maxFileNameLength) {
    s32 fileNameTop;
    s32 arrowLeft;
    s32 arrowTop;
    s32 visibleFileCount;
    s32 fileMenuOptionIndex;
    s32 sp4C;
    s32 i;

    if (sExpansionKitFileMenuCursorPosXPtr == NULL) {
        PRINTF("CURSOR POINTER IS NOT INITIALIZED !!\n");
        return gfx;
    }
    if (!sExpansionKitEnableDrawFileMenu) {
        return gfx;
    }

    // TODO: Move to appropriate place
    PRINTF("FILELISTc\n");
    PRINTF("FILE LISTS %d\n");

    fileMenuOptionIndex = sExpansionKitFileOptionIndex;
    gSPDisplayList(gfx++, D_8014940);

    visibleFileCount = sExpansionKitExistingFileCount;
    if (sExpansionKitExistingFileCount > 13) {
        visibleFileCount = 13;
    }
    EKFileMenu_DrawFileMenuBorder(&gfx, sExpansionKitFileMenuLeft - 8, sExpansionKitFileMenuTop - 8,
                                  maxFileNameLength + 2, visibleFileCount + 2);

    gDPPipeSync(gfx++);

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sExpansionKitFileMenuLeft - 10, sExpansionKitFileMenuTop,
                  (maxFileNameLength * 8) + sExpansionKitFileMenuLeft + 2, sExpansionKitFileMenuTop + 13 * 8);

    for (i = 0; i < sExpansionKitExistingFileCount; i++) {

        fileNameTop = ((i * 8) + sExpansionKitFileMenuTop) - sExpansionKitFileListScroll;
        if (fileNameTop < (sExpansionKitFileMenuTop - 8)) {
            continue;
        }
        if (fileNameTop > (sExpansionKitFileMenuTop + 13 * 8 + 8)) {
            continue;
        }

        gSPDisplayList(gfx++, D_3000510);
        if (i == fileMenuOptionIndex) {
            gDPSetPrimColor(gfx++, 0, 0, 190, 175, 255, 255);
        } else {
            if (gExpansionKitLoadedFiles[i].unk_22 != 0) {
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 0);
            }
        }
        gSPTextureRectangle(gfx++, (sExpansionKitFileMenuLeft - 2) << 2, fileNameTop << 2,
                            ((maxFileNameLength * 8) + sExpansionKitFileMenuLeft + 2) << 2, (fileNameTop + 8) << 2, 0,
                            0, 0, 1 << 10, 1 << 10);
        gDPPipeSync(gfx++);

        if (gGameMode == GAMEMODE_COURSE_EDIT) {
            if (i == fileMenuOptionIndex) {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
            } else if (gExpansionKitLoadedFiles[i].unk_22 != 0) {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else if (D_80119880 == 6) {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else if (func_xk2_800EC234(&gExpansionKitLoadedFiles[i])) {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
            } else {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
        } else {
            if (i == fileMenuOptionIndex) {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
            } else if (MachineCreate_FileListIsFileForSuperMachine(&gExpansionKitLoadedFiles[i])) {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
            } else {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
        }

        gfx = ExpansionKit_DrawEncStr(gfx, sExpansionKitFileMenuLeft, fileNameTop, gExpansionKitLoadedFiles[i].name);
        if ((gExpansionKitLoadedFiles[i].extension[3] == 'E') && ((gGameFrameCount % 16) < 8)) {
            gSPDisplayList(gfx++, D_7020808);
            gSPTextureRectangle(gfx++, (sExpansionKitFileMenuLeft + 28) << 2, fileNameTop << 2,
                                (sExpansionKitFileMenuLeft + 36) << 2, (fileNameTop + 8) << 2, 0, 0, 0, 1 << 10,
                                1 << 10);
        }
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gfx++, aExpansionKitScrollArrowIndicatorTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);

    if (sExpansionKitFileListScroll != 0) {
        if (((gGameFrameCount % sExpansionKitFileListArrowFlashLength) < (sExpansionKitFileListArrowFlashLength / 2))) {
            arrowLeft = sExpansionKitFileMenuLeft + 24;
            arrowTop = sExpansionKitFileMenuTop - 16;
            gSPTextureRectangle(gfx++, arrowLeft << 2, arrowTop << 2, (arrowLeft + 16) << 2, (arrowTop + 8) << 2, 0, 0,
                                16 << 5, 0x800, -0x800);
        }
    }

    if ((sExpansionKitExistingFileCount > 13) &&
        (sExpansionKitFileListScroll < (((sExpansionKitExistingFileCount - 13) * 8)))) {
        if ((gGameFrameCount % sExpansionKitFileListArrowFlashLength) < (sExpansionKitFileListArrowFlashLength / 2)) {
            arrowLeft = sExpansionKitFileMenuLeft + 24;
            arrowTop = sExpansionKitFileMenuTop + 13 * 8 + 8;
            gSPTextureRectangle(gfx++, arrowLeft << 2, arrowTop << 2, (arrowLeft + 16) << 2, (arrowTop + 8) << 2, 0, 0,
                                0, 0x800, 0x800);
        }
    }

    return gfx;
}

void EKFileMenu_UpdateScroll(void) {

    if (sExpansionKitFileOptionIndex >= ((sExpansionKitFileListScroll / 8) + 13)) {
        sExpansionKitFileListScroll += 8;
    } else if (sExpansionKitFileOptionIndex < (sExpansionKitFileListScroll / 8)) {
        sExpansionKitFileListScroll -= 8;
    }
}

void EKFileMenu_UpdateOptionIndex(void) {
    s32 prevOptionIndex;

    prevOptionIndex = sExpansionKitFileOptionIndex;
    if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z) {
        if (gGameMode == GAMEMODE_COURSE_EDIT) {
            EKController_UpdateVerticalOptionFast(&sExpansionKitFileOptionIndex, sExpansionKitExistingFileCount - 1, 0);
        } else {
            EKController_UpdateVerticalOptionStaggered(&sExpansionKitFileOptionIndex,
                                                       sExpansionKitExistingFileCount - 1, 0);
        }
    } else {
        EKController_UpdateVerticalOptionSlow(&sExpansionKitFileOptionIndex, sExpansionKitExistingFileCount - 1, 0);
    }

    if (prevOptionIndex != sExpansionKitFileOptionIndex) {
        Audio_TriggerSystemSE(NA_SE_35);
    }

    if (sExpansionKitFileOptionIndex >= ((sExpansionKitFileListScroll / 8) + 13)) {
        sExpansionKitFileListScroll += 8;
    } else if (sExpansionKitFileOptionIndex < (sExpansionKitFileListScroll / 8)) {
        sExpansionKitFileListScroll -= 8;
    }
}

char* EKFileMenu_GetFileNameForDisplay(void) {
    s32 fileIndex;

    sExpansionKitEnableDrawFileMenu = false;
    sExpansionKitFileMenuEnableDrawConfirmText = true;

    fileIndex = sExpansionKitFileOptionIndex;
    if (fileIndex > sExpansionKitExistingFileCount - 1) {
        fileIndex = sExpansionKitExistingFileCount - 1;
    }
    return gExpansionKitLoadedFiles[fileIndex].name;
}

s32 EKFileMenu_GetFileIndex(void) {
    s32 fileIndex;

    sExpansionKitEnableDrawFileMenu = false;
    sExpansionKitFileMenuEnableDrawConfirmText = true;
    fileIndex = sExpansionKitFileOptionIndex;
    return fileIndex;
}

void func_xk1_8002BD34(void) {
    Audio_TriggerSystemSE(NA_SE_37);
    sExpansionKitEnableDrawFileMenu = false;
}

void func_xk1_8002BD58(void) {
    sExpansionKitEnableDrawFileMenu = false;
}

extern MfsRamArea gMfsRamArea;

s32 EKFileMenu_LoadFiles(u8 fileStartOffset, char* extension) {
    s32 i;
    s32 pad[4];
    s32 filesInDirWithExtension;
    u16* fileIdPtr;
    EKLoadedFile* file;

    fileIdPtr = sExpansionKitFileMenuFileIds;
    D_xk1_80032BF8 = false;
    gExpansionKitLoadedFiles[0].attr = 0;
    gExpansionKitLoadedFiles[0].unk_22 = 1;
    sExpansionKitExistingFileCount = fileStartOffset;

    if (Mfs_GetFilesPreparation(MFS_ENTRY_WORKING_DIR)) {
        return sExpansionKitExistingFileCount;
    }

    filesInDirWithExtension = 0;
    while (true) {

        if ((*fileIdPtr = Mfs_GetNextFileInPreparedDir()) == MFS_ENTRY_DOES_NOT_EXIST) {
            break;
        }
        if ((extension == NULL) || (mfsStrnCmp(gMfsRamArea.directoryEntry[*fileIdPtr].extension, extension, 3) == 0)) {
            file = &gExpansionKitLoadedFiles[sExpansionKitExistingFileCount];
            file->unk_22 = 0;
            mfsStrCpy(file->name, gMfsRamArea.directoryEntry[*fileIdPtr].name);
            mfsStrCpy(file->extension, gMfsRamArea.directoryEntry[*fileIdPtr].extension);
            file->attr = gMfsRamArea.directoryEntry[*fileIdPtr].attr;
            filesInDirWithExtension++;

            if (++sExpansionKitExistingFileCount == ARRAY_COUNT(gExpansionKitLoadedFiles)) {
                break;
            }
        }

        fileIdPtr++;
    }

    sExpansionKitFileListScroll = 0;
    sExpansionKitEnableDrawFileMenu = true;
    EKFileMenu_QSort(&gExpansionKitLoadedFiles[fileStartOffset], sExpansionKitExistingFileCount - fileStartOffset,
                     sizeof(EKLoadedFile), EKFileMenu_Compare);
    D_xk1_80032BF8 = true;

    if (filesInDirWithExtension > 100) {
        for (i = 0; i < filesInDirWithExtension - 100; i++) {
            file = &gExpansionKitLoadedFiles[sExpansionKitExistingFileCount - (i + 1)];
            Mfs_DeleteFileInDir(MFS_ENTRY_WORKING_DIR, file->name, file->extension, true);
            sExpansionKitExistingFileCount--;
        }
    }

    return sExpansionKitExistingFileCount;
}

s32 EKFileMenu_GetFileCount(void) {
    return sExpansionKitExistingFileCount;
}

// FAKE! -- requires some very specific permutation of temps for matching
void EKFileMenu_DrawYesNoWithAB(Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    s32 x = 136;
    s32 y = 120;
    int new_var = 1 << 10;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
    gSPTextureRectangle(gfx++, (x - 2) << 2, (y - 2) << 2, (x + 50) << 2, y << 2, 0, 0, 0, new_var, 1 << 10);
    gSPTextureRectangle(gfx++, (x - 2) << 2, (y + 32) << 2, (x + 50) << 2, (y + 34) << 2, 0, 0, 0, 1 << 10, new_var);
    gSPTextureRectangle(gfx++, (x - 2) << 2, y << 2, 136 << 2, (y + 32) << 2, 0, 0, 0, new_var, new_var);
    gSPTextureRectangle(gfx++, (x + 48) << 2, y << 2, (x + 50) << 2, (y + 32) << 2, 0, 0, 0, new_var, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 48) << 2, (y + 32) << 2, 0, 0, 0, new_var, 1 << 10);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPLoadTextureBlock_4b(gfx++, aExpansionKitYesNoTex, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 32) << 2, x << 2, 0, 0, 16 << 5, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, x << 2, x << 2, (x + 32) << 2, (y + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPLoadTextureBlock(gfx++, aExpansionKitABButtonTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gfx++, (x + 32) << 2, y << 2, (x + 48) << 2, (y + 16) << 2, 0, 0, 16 << 5, new_var, 1 << 10);
    gSPTextureRectangle(gfx++, (x + 32) << 2, (y + 16) << 2, (x + 48) << 2, (y + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    *gfxP = gfx;
}

Gfx* EKFileMenu_DrawSelectFileText(Gfx* gfx, s32 left, s32 top) {
    s32 width;

    if (!sExpansionKitEnableDrawFileMenu) {
        return gfx;
    }
    if ((D_80119880 != 7) && (D_80119880 != 8)) {
        width = 176;
    } else {
        width = 256;
    }
    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);

    gSPTextureRectangle(gfx++, (left - 2) << 2, (top - 2) << 2, (left + width + 2) << 2, top << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (left - 2) << 2, (top + 16) << 2, (left + width + 2) << 2, (top + 16 + 2) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left - 2) << 2, top << 2, left << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left + width) << 2, top << 2, (left + width + 2) << 2, (top + 16) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    if ((D_80119880 == 7) || (D_80119880 == 8)) {
        gfx = func_xk1_800264C0(gfx, left, top, 15);
    } else {
        gfx = func_xk1_800264C0(gfx, left, top, 0);
    }

    return gfx;
}

extern char* gCourseEditMessageStrs[];

void EKFileMenu_DrawFileSelectedConfirmText(Gfx** gfxP, s32 left, s32 top, char* fileNameEncStr, s32 messageId) {
    Gfx* gfx;
    s32 strLen;
    s32 strWidth;
    char fileNameStr[0x100];
    char messageStr[0x100];

    gfx = *gfxP;
    if (!sExpansionKitFileMenuEnableDrawConfirmText) {
        return;
    }
    ExpansionKit_DecodeStr(fileNameEncStr, fileNameStr);
    mfsStrCpy(messageStr, gCourseEditMessageStrs[messageId + 1]);
    strLen = mfsStrLen(fileNameStr) + mfsStrLen(messageStr);
    strWidth = strLen * 8;
    left = (((34 - strLen) / 2) * 8) + 24;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
    gSPTextureRectangle(gfx++, (left - 2) << 2, (top - 2) << 2, (left + strWidth + 2) << 2, top << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (left - 2) << 2, (top + 16) << 2, (left + strWidth + 2) << 2, (top + 16 + 2) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left - 2) << 2, top << 2, left << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left + strWidth) << 2, top << 2, (left + strWidth + 2) << 2, (top + 16) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + strWidth) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 64, 64, 255);
    gfx = func_xk1_800262F4(gfx, left, top, fileNameStr);
    left += mfsStrLen(fileNameStr) * 8;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_xk1_800264C0(gfx, left, top, messageId + 1);

    *gfxP = gfx;
}

s32 EKFileMenu_GetEnableDrawConfirmText(void) {
    return sExpansionKitFileMenuEnableDrawConfirmText;
}

void EKFileMenu_DisableDrawConfirmText(void) {
    sExpansionKitFileMenuEnableDrawConfirmText = false;
}

s32 EKFileMenu_Compare(u8* a, u8* b) {
    s32 i;

    for (i = 0; i < 8; i++, a++, b++) {
        if (*a != *b) {
            return *a - *b;
        }
    }

    return 0;
}

void EKFileMenu_QuickSort(s8* startPtr, s8* endPtr) {
    s32 temp;
    s32 elementByteCount;
    s32 sortRange;
    s8* pivotElement;
    s8* medianElement;
    s8* rightPtr;
    s8* partitionElement;
    s8* lastElement;
    s8* swapElement;

    sortRange = endPtr - startPtr;
    do {
        pivotElement =
            (((sortRange / sExpansionKitFileMenuSortElementSize) >> 1) * sExpansionKitFileMenuSortElementSize) +
            startPtr;
        partitionElement = pivotElement;
        if (sortRange >= sExpansionKitFileMenuSort6ElementsSize) {
            if (sExpansionKitFileMenuCompareFunc(startPtr, pivotElement) > 0) {
                medianElement = startPtr;
            } else {
                medianElement = pivotElement;
            }
            lastElement = endPtr - sExpansionKitFileMenuSortElementSize;
            if (sExpansionKitFileMenuCompareFunc(medianElement, lastElement) > 0) {
                if (medianElement == startPtr) {
                    medianElement = pivotElement;
                } else {
                    medianElement = startPtr;
                }
                if (sExpansionKitFileMenuCompareFunc(medianElement, lastElement) < 0) {
                    medianElement = lastElement;
                }
            }
            if (medianElement != pivotElement) {
                elementByteCount = sExpansionKitFileMenuSortElementSize;
                do {
                    temp = *pivotElement;
                    *pivotElement = *medianElement;
                    *medianElement = temp;
                    elementByteCount--;
                    pivotElement++;
                    medianElement++;
                } while (elementByteCount != 0);
            }
        }
        pivotElement = startPtr;
        rightPtr = endPtr - sExpansionKitFileMenuSortElementSize;

        while (true) {
            while ((pivotElement < partitionElement) &&
                   (sExpansionKitFileMenuCompareFunc(pivotElement, partitionElement) <= 0)) {
                pivotElement += sExpansionKitFileMenuSortElementSize;
            }
            while (partitionElement < rightPtr) {
                if (sExpansionKitFileMenuCompareFunc(partitionElement, rightPtr) <= 0) {
                    rightPtr -= sExpansionKitFileMenuSortElementSize;
                } else {
                    lastElement = pivotElement + sExpansionKitFileMenuSortElementSize;
                    if (pivotElement == partitionElement) {
                        swapElement = rightPtr;
                        partitionElement = rightPtr;
                    } else {
                        swapElement = rightPtr;
                        rightPtr -= sExpansionKitFileMenuSortElementSize;
                    }
                    goto swap;
                }
            }
            if (pivotElement == partitionElement) {
                break;
            }
            swapElement = partitionElement;
            partitionElement = pivotElement;
            lastElement = pivotElement;
            rightPtr -= sExpansionKitFileMenuSortElementSize;

        swap:
            elementByteCount = sExpansionKitFileMenuSortElementSize;
            do {
                temp = *pivotElement;
                *pivotElement = *swapElement;
                *swapElement = temp;
                elementByteCount--;
                pivotElement++;
                swapElement++;
            } while (elementByteCount != 0);
            pivotElement = lastElement;
        }

        pivotElement = partitionElement + sExpansionKitFileMenuSortElementSize;
        if ((sortRange = (partitionElement - startPtr)) <= endPtr - pivotElement) {
            if ((partitionElement - startPtr) >= sExpansionKitFileMenuSort4ElementsSize) {
                EKFileMenu_QuickSort(startPtr, partitionElement);
            }
            startPtr = pivotElement;
            sortRange = endPtr - pivotElement;
        } else {
            if (endPtr - pivotElement >= sExpansionKitFileMenuSort4ElementsSize) {
                EKFileMenu_QuickSort(pivotElement, endPtr);
            }
            endPtr = partitionElement;
        }
    } while (sortRange >= sExpansionKitFileMenuSort4ElementsSize);
}

void EKFileMenu_QSort(s8* startPtr, s32 listLength, s32 elementSize, s32 (*compareFunc)(u8*, u8*)) {
    s32 temp;
    s8* endPtr;
    s8* var_s0;
    s8* var_s1;
    s8* var_s2;
    s8* var_s4;
    s8* var_v0;
    s32 i;

    if (listLength < 2) {
        return;
    }
    sExpansionKitFileMenuSortElementSize = elementSize;
    sExpansionKitFileMenuCompareFunc = compareFunc;
    sExpansionKitFileMenuSort4ElementsSize = sExpansionKitFileMenuSortElementSize * 4;
    sExpansionKitFileMenuSort6ElementsSize = sExpansionKitFileMenuSortElementSize * 6;
    endPtr = startPtr + (listLength * sExpansionKitFileMenuSortElementSize);
    if (listLength >= 4) {
        EKFileMenu_QuickSort(startPtr, endPtr);
        var_s2 = startPtr + sExpansionKitFileMenuSort4ElementsSize;
    } else {
        var_s2 = endPtr;
    }
    var_s1 = startPtr + sExpansionKitFileMenuSortElementSize;
    var_s0 = startPtr;
    while (var_s1 < var_s2) {
        if (sExpansionKitFileMenuCompareFunc(var_s0, var_s1) > 0) {
            var_s0 = var_s1;
        }
        var_s1 += sExpansionKitFileMenuSortElementSize;
    }

    var_s2 = startPtr;
    var_s2 += sExpansionKitFileMenuSortElementSize;

    if (var_s0 != startPtr) {
        for (var_v0 = startPtr; var_v0 < var_s2; var_v0++, var_s0++) {
            temp = *var_s0;
            *var_s0 = *var_v0;
            *var_v0 = temp;
        }
    }
    var_s4 = startPtr + sExpansionKitFileMenuSortElementSize;
    while (var_s4 < endPtr) {
        var_s2 = var_s4 - sExpansionKitFileMenuSortElementSize;
        while (sExpansionKitFileMenuCompareFunc(var_s2, var_s4) > 0) {
            var_s2 -= sExpansionKitFileMenuSortElementSize;
        }

        var_s2 += sExpansionKitFileMenuSortElementSize;
        if (var_s2 != var_s4) {
            var_s1 = (var_s4 + sExpansionKitFileMenuSortElementSize) - 1;
            while (var_s1 >= var_s4) {
                var_v0 = var_s1;
                temp = *var_s1;
                var_s0 = var_s1 - sExpansionKitFileMenuSortElementSize;
                var_s1--;
                while (var_s0 >= var_s2) {
                    *var_v0 = *var_s0;
                    var_v0 = var_s0;
                    var_s0 -= sExpansionKitFileMenuSortElementSize;
                }
                *var_v0 = temp;
            }
        }
        var_s4 += sExpansionKitFileMenuSortElementSize;
    }
}

void func_xk1_8002D16C(void) {
    s32 i;
    s32 j;
    s32 k;
    char cupStrs[][6] = { "JACK", "QUEEN", "KING", "JOKER", "DD1-", "DD2-" };
    EKLoadedFile* file;

    sExpansionKitEnableDrawFileMenu = true;
    k = 0;
    for (i = 0, file = gExpansionKitLoadedFiles; i < 6; i++) {
        for (j = 0; j < 6; j++, k++, file++) {
            file->attr = 0;
            file->unk_22 = 0;
            file->extension[3] = '\0';
            sprintf(file->name, "%s%d", cupStrs[i], j + 1);
        }
    }
    sExpansionKitExistingFileCount = k;
}

s32 EKFileMenu_GetFileListScroll(void) {
    return sExpansionKitFileListScroll;
}

void EKFileMenu_SetFileListScroll(s32 scroll) {
    sExpansionKitFileListScroll = scroll;
}

void EKFileMenu_SetFileCount(s32 fileCount) {
    sExpansionKitExistingFileCount = fileCount;
}

void EKFileMenu_EnableFileMenuDraw(void) {
    sExpansionKitEnableDrawFileMenu = true;
}

bool EKFileMenu_CanScrollDown(void) {
    if ((sExpansionKitExistingFileCount > 13) &&
        (sExpansionKitFileListScroll < ((sExpansionKitExistingFileCount - 13) * 8))) {
        return true;
    }
    return false;
}

void EKFileMenu_SetOptionIndex(s32 optionIndex) {
    sExpansionKitFileOptionIndex = optionIndex;
}

s32 gExpansionKitYesNoOptionIndex = 0;

void EKFileMenu_UpdateYesNoOption(void) {
    s32 prevIndex = gExpansionKitYesNoOptionIndex;

    EKController_UpdateVerticalOptionSlow(&gExpansionKitYesNoOptionIndex, 1, 1);
    if (prevIndex != gExpansionKitYesNoOptionIndex) {
        Audio_TriggerSystemSE(NA_SE_35);
    }
}

void EKFileMenu_DrawYesNoOption(Gfx** gfxP) {
    s32 x = 136;
    s32 y = 120;
    s32 width = 48;
    s32 pulseTimer;
    Gfx* gfx;

    gfx = *gfxP;
    if (gGameMode == GAMEMODE_COURSE_EDIT) {
        pulseTimer = 3;
    } else {
        pulseTimer = 1;
    }

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
    gSPTextureRectangle(gfx++, (x - 2) << 2, (y - 2) << 2, (x + width + 2) << 2, y << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (x - 2) << 2, (y + 32) << 2, (x + width + 2) << 2, (y + 32 + 2) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (x - 2) << 2, y << 2, x << 2, (y + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (x + width) << 2, y << 2, (x + width + 2) << 2, (y + 32) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + width) << 2, (y + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    // FAKE
    x += 0;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 160);
    gSPTextureRectangle(gfx++, x << 2, ((gExpansionKitYesNoOptionIndex * 16) + 120) << 2, (x + width) << 2,
                        (((gExpansionKitYesNoOptionIndex + 1) * 16) + 120) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    x += 8;
    gSPDisplayList(gfx++, D_3000540);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPLoadTextureBlock_4b(gfx++, aExpansionKitYesNoTex, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    if (gExpansionKitYesNoOptionIndex == 0) {
        gfx = func_i3_80059EC0(gfx, pulseTimer);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }

    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 32) << 2, (y + 16) << 2, 0, 0, 16 << 5, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);

    if (gExpansionKitYesNoOptionIndex != 0) {
        gfx = func_i3_80059EC0(gfx, pulseTimer);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    gSPTextureRectangle(gfx++, x << 2, (y + 16) << 2, (x + 32) << 2, (y + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    *gfxP = gfx;
}
