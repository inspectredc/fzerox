#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "ovl_i6.h"
#include "audio.h"
#include "assets/segment_2B9EA0.h"
#include "assets/segment_17B1E0.h"

SaveContext* sSaveContextPtr;
u8 D_i6_8011FB18[2][0x2580]; // Some kind of vtx buffer space?
void* D_i6_80124618;
s16 D_i6_80124620[176];
s32 sOptionsDataClearMenu;
s16 sOptionsDataAlreadyCleared;
s32 sOptionsSelectionState[7];
unk_800E51B8* D_i6_801247A4;
s16 D_i6_801247A8;
s16 D_i6_801247AA;
TexturePtr D_i6_801247AC;
s16 D_i6_801247B0;

/*
    OPTIONS MENU
 */

// 'WITH', 'W/O'
OptionsTextureInfo gOptionsVsComSelection[] = {
    { aMenuWithTex, 32, 16 },
    { aMenuWithoutTex, 32, 16 },
};

// 'WITH', 'W/O'
OptionsTextureInfo gOptionsVsSlotSelection[] = {
    { aMenuWithTex, 32, 16 },
    { aMenuWithoutTex, 32, 16 },
};

// 'W/O', '+1', '+2'
OptionsTextureInfo gOptionsVsHandicapSelection[] = {
    { aMenuWithoutTex, 32, 16 },
    { aMenuPlusOneTex, 32, 16 },
    { aMenuPlusTwoTex, 32, 16 },
};

// 'Stereo', 'Mono'
OptionsTextureInfo gOptionsSoundModeSelection[] = {
    { aMenuStereoTex, 64, 16 },
    { aMenuMonoTex, 64, 16 },
};

// 'No', 'Yes'
OptionsTextureInfo gOptionsAllDataClearSelection[] = {
    { aMenuNoTex, 32, 16 },
    { aMenuYesTex, 32, 16 },
};

s32 gOptionsCurrentRow = 0;

OptionsInfo gOptionsInfo[] = {
    // 'VS COM (2P,3P)'
    { OPTIONS_VS_COM,
      OPTIONS_SHOWN,
      2,
      0,
      0,
      gOptionsVsComSelection,
      { aOptionsVsCom2P3PTex, TEX_WIDTH(aOptionsVsCom2P3PTex), TEX_HEIGHT(aOptionsVsCom2P3PTex) } },
    // 'VS Slot'
    { OPTIONS_VS_SLOT,
      OPTIONS_SHOWN,
      2,
      0,
      0,
      gOptionsVsSlotSelection,
      { aOptionsVsSlotTex, TEX_WIDTH(aOptionsVsSlotTex), TEX_HEIGHT(aOptionsVsSlotTex) } },
    // 'VS Handicap'
    { OPTIONS_VS_HANDICAP,
      OPTIONS_SHOWN,
      3,
      0,
      0,
      gOptionsVsHandicapSelection,
      { aOptionsVsHandicapTex, TEX_WIDTH(aOptionsVsHandicapTex), TEX_HEIGHT(aOptionsVsHandicapTex) } },
#ifdef VERSION_JP
    // 'Sound Mode'
    { OPTIONS_SOUND_MODE,
      OPTIONS_SHOWN,
      2,
      0,
      4,
      gOptionsSoundModeSelection,
      { aOptionsSoundModeTex, TEX_WIDTH(aOptionsSoundModeTex), TEX_HEIGHT(aOptionsSoundModeTex) } },
#else
    // 'Sound Mode'
    { OPTIONS_SOUND_MODE,
      OPTIONS_SHOWN,
      2,
      0,
      0,
      gOptionsSoundModeSelection,
      { aOptionsSoundModeTex, TEX_WIDTH(aOptionsSoundModeTex), TEX_HEIGHT(aOptionsSoundModeTex) } },
#endif
    // 'All data clear'
    { OPTIONS_DATA_CLEAR,
      OPTIONS_REQUIRE_SELECTING | OPTIONS_SHOWN,
      0,
      0,
      0,
      NULL,
      { aOptionsAllDataClearTex, TEX_WIDTH(aOptionsAllDataClearTex), TEX_HEIGHT(aOptionsAllDataClearTex) } },
    // 'Copying ghost'
    { OPTIONS_GHOST_COPY,
      OPTIONS_REQUIRE_SELECTING,
      0,
      0,
      0,
      NULL,
      { aOptionsCopyingGhostTex, TEX_WIDTH(aOptionsCopyingGhostTex), TEX_HEIGHT(aOptionsCopyingGhostTex) } },
    // 'EXIT'
    { OPTIONS_EXIT,
      OPTIONS_REQUIRE_SELECTING | OPTIONS_SHOWN,
      0,
      0,
      0,
      NULL,
      { aOptionsExitTex, TEX_WIDTH(aOptionsExitTex), TEX_HEIGHT(aOptionsExitTex) } },
};

UNUSED char D_i6_8011EEBC[] = "Feel Mie";

extern s16 D_800CCFE8;
extern s8 D_800CD3C4;

void func_i6_8011C404(void);

void OptionsMenu_Init(void) {
    s32 i;
    OptionsInfo* option;

    D_800CCFE8 = 3;
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    func_80078104(aMenuTextTLUT, TEX_SIZE(aMenuTextTLUT, sizeof(u16)), 0, 0, false);
    func_80078104(aOptionsFalconHelmetTex, TEX_SIZE(aOptionsFalconHelmetTex, sizeof(u16)), 0, 1, false);
    func_80078104(aOptionsTex, TEX_SIZE(aOptionsTex, sizeof(u8)), 0, 1, false);
    func_80078104(aOptionsEraseAllSavedDataTex, TEX_SIZE(aOptionsEraseAllSavedDataTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuWithoutTex, TEX_SIZE(aMenuWithoutTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuWithTex, TEX_SIZE(aMenuWithTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuPlusOneTex, TEX_SIZE(aMenuPlusOneTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuPlusTwoTex, TEX_SIZE(aMenuPlusTwoTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuStereoTex, TEX_SIZE(aMenuStereoTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuMonoTex, TEX_SIZE(aMenuMonoTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuLeftArrowTex, TEX_SIZE(aMenuLeftArrowTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuRightArrowTex, TEX_SIZE(aMenuRightArrowTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuNoTex, TEX_SIZE(aMenuNoTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuYesTex, TEX_SIZE(aMenuYesTex, sizeof(u8)), 0, 1, false);

    for (i = 0, option = gOptionsInfo; i < OPTIONS_MAX; i++, option++) {
        func_80078104(option->optionTextureInfo.textureOffset,
                      option->optionTextureInfo.width * option->optionTextureInfo.height * sizeof(u8), 0, 1, 0);
    }

    func_80078104(aTitleBackgroundMainTex, TEX_SIZE(aTitleBackgroundMainTex, sizeof(u16)), 0, 1, false);
    func_8007A828(func_800783AC(aTitleBackgroundMainTex), TEX_SIZE(aTitleBackgroundMainTex, sizeof(u16)), 0xC3, 0x5F,
                  0x5F);

    if (D_800CD3C4 == 1) {
        D_i6_801247AC =
            func_80078104(aTitleBackgroundComicTex, TEX_SIZE(aTitleBackgroundComicTex, sizeof(u16)), 0, 1, false);
        func_8007A828(D_i6_801247AC, TEX_SIZE(aTitleBackgroundComicTex, sizeof(u16)), 0xC3, 0x5F, 0x5F);
    } else if (D_800CD3C4 == 2) {
        D_i6_801247AC =
            func_80078104(aTitleBackgroundFalconTex, TEX_SIZE(aTitleBackgroundFalconTex, sizeof(u16)), 0, 1, false);
        func_8007A828(D_i6_801247AC, TEX_SIZE(aTitleBackgroundFalconTex, sizeof(u16)), 0xC3, 0x5F, 0x5F);
    }
    if (D_800CD3C4 != 0) {
        D_i6_801247A8 = 1;
        // clang-format off
        for (i = 0; i < ARRAY_COUNT(D_i6_80124620); i++) { \
            D_i6_80124620[i] = 255;
        }
        // clang-format on
    } else {
        D_i6_801247A8 = 0;
    }
    sOptionsDataClearMenu = OPTIONS_DATA_CLEAR_MENU_CLOSED;
    sOptionsDataAlreadyCleared = false;
    D_i6_801247B0 = 0;
    gOptionsCurrentRow = 0;
    func_i6_8011C404();
    func_80080A40(&D_i6_801247A4);
    func_80080A48();
    sSaveContextPtr = &gSaveContext;
}

extern s16 gSettingVsHandicap;
extern s16 gSettingVsCom;
extern s32 gSettingVsSlot;
extern s16 gSettingSoundMode;

void func_i6_8011C404(void) {
    s32 state;
    s32 i;
    OptionsInfo* option;

    for (i = 0, option = gOptionsInfo; i < 7; i++, option++) {
        switch (option->row) {
            case OPTIONS_VS_COM:
                if (gSettingVsCom == 0) {
                    state = 1;
                } else {
                    state = 0;
                }
                break;
            case OPTIONS_VS_SLOT:
                if (gSettingVsSlot == 0) {
                    state = 1;
                } else {
                    state = 0;
                }
                break;
            case OPTIONS_VS_HANDICAP:
                if (gSettingVsHandicap == 0) {
                    state = 0;
                } else if (gSettingVsHandicap == 1) {
                    state = 1;
                } else {
                    state = 2;
                }
                break;
            case OPTIONS_SOUND_MODE:
                if (gSettingSoundMode == 0) {
                    state = 0;
                } else {
                    state = 1;
                }
                break;
            default:
                state = 0;
                break;
        }

        sOptionsSelectionState[i] = state;
    }
}

bool func_i6_8011C788(void);
void func_i6_8011CBB4(void);
void func_i6_8011D394(void);
extern s16 D_800CD048;
extern s32 D_i2_80106DA4;
extern Controller gSharedController;

s32 OptionsMenu_Update(void) {
    Controller_SetGlobalInputs(&gSharedController);
    func_80080C0C();
    func_i6_8011D394();
    if (!sOptionsDataAlreadyCleared) {
        switch (sOptionsDataClearMenu) {
            case OPTIONS_DATA_CLEAR_MENU_CLOSED:
                if (D_i2_80106DA4 == 0 && func_i6_8011C788()) {
                    sOptionsDataAlreadyCleared = true;
                    D_800CD048 = 14;
                }
                break;
            case OPTIONS_DATA_CLEAR_MENU_OPEN:
                func_i6_8011CBB4();
                break;
        }
    }
    return GAMEMODE_FLX_OPTIONS_MENU;
}

extern u16 gInputButtonPressed;
extern u16 gInputPressed;
Gfx* func_i6_8011D168(Gfx*, s32, s32);

bool func_i6_8011C788(void) {
    s32 lastRow;
    s32 lastSelectionState;
    bool updateSettings;
    OptionsInfo* option;

    if (func_8008108C(D_i6_801247A4, 0)) {
        return false;
    }
    lastRow = gOptionsCurrentRow;
    if (gInputPressed & BTN_UP) {
        if (--gOptionsCurrentRow < OPTIONS_VS_COM) {
            gOptionsCurrentRow = OPTIONS_EXIT;
        }
        while (!(gOptionsInfo[gOptionsCurrentRow].flags & OPTIONS_SHOWN)) {
            if (--gOptionsCurrentRow < OPTIONS_VS_COM) {
                gOptionsCurrentRow = OPTIONS_EXIT;
            }
        }
    }
    if (gInputPressed & BTN_DOWN) {
        if (++gOptionsCurrentRow > OPTIONS_EXIT) {
            gOptionsCurrentRow = OPTIONS_VS_COM;
        }
        while (!(gOptionsInfo[gOptionsCurrentRow].flags & OPTIONS_SHOWN)) {
            if (++gOptionsCurrentRow > OPTIONS_EXIT) {
                gOptionsCurrentRow = OPTIONS_VS_COM;
            }
        }
    }
    if (lastRow != gOptionsCurrentRow) {
        func_800BA8D8(0x1E);
        return false;
    }
    option = &gOptionsInfo[gOptionsCurrentRow];
    updateSettings = false;
    if (!(option->flags & OPTIONS_REQUIRE_SELECTING)) {
        lastSelectionState = sOptionsSelectionState[gOptionsCurrentRow];
        if (gInputButtonPressed & BTN_LEFT) {
            sOptionsSelectionState[gOptionsCurrentRow]--;
            if (sOptionsSelectionState[gOptionsCurrentRow] < 0) {
                sOptionsSelectionState[gOptionsCurrentRow] = option->totalSelectionStates - 1;
            }
        }
        if (gInputButtonPressed & BTN_RIGHT) {
            sOptionsSelectionState[gOptionsCurrentRow]++;
            if (sOptionsSelectionState[gOptionsCurrentRow] > option->totalSelectionStates - 1) {
                sOptionsSelectionState[gOptionsCurrentRow] = 0;
            }
        }
        if (lastSelectionState != sOptionsSelectionState[gOptionsCurrentRow]) {
            updateSettings = true;
            func_800BA8D8(0x21);
        }
    }
    if (gInputButtonPressed & BTN_B) {
        func_800BA8D8(0x10);
        return true;
    }

    switch (option->row) {
        case OPTIONS_VS_COM:
            if (updateSettings) {
                if (sOptionsSelectionState[gOptionsCurrentRow] == 1) {
                    gSettingVsCom = 0;
                } else {
                    gSettingVsCom = 1;
                }
            }
            break;
        case OPTIONS_VS_SLOT:
            if (updateSettings) {
                if (sOptionsSelectionState[gOptionsCurrentRow] == 1) {
                    gSettingVsSlot = 0;
                } else {
                    gSettingVsSlot = 1;
                }
            }
            break;
        case OPTIONS_VS_HANDICAP:
            if (updateSettings) {
                if (sOptionsSelectionState[gOptionsCurrentRow] == 0) {
                    gSettingVsHandicap = 0;
                } else if (sOptionsSelectionState[gOptionsCurrentRow] == 1) {
                    gSettingVsHandicap = 1;
                } else {
                    gSettingVsHandicap = 2;
                }
            }
            break;
        case OPTIONS_SOUND_MODE:
            if (updateSettings) {
                if (sOptionsSelectionState[gOptionsCurrentRow] == 0) {
                    gSettingSoundMode = 0;
                    Audio_SetSoundMode(SOUNDMODE_SURROUND); // Option says stereo, but sets surround anyway?
                } else {
                    gSettingSoundMode = 1;
                    Audio_SetSoundMode(SOUNDMODE_MONO);
                }
            }
            break;
        case OPTIONS_DATA_CLEAR:
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                D_i6_801247A4 =
                    func_80080AA8(0, 0x5A, 0x8C, 0x94, 0x50, GPACK_RGBA5551(255, 0, 0, 1), func_i6_8011D168);
                if (D_i6_801247A4 != NULL) {
                    sOptionsDataClearMenu = OPTIONS_DATA_CLEAR_MENU_OPEN;
                    sOptionsSelectionState[gOptionsCurrentRow] = 0;
                    func_800BA8D8(0x21);
                }
            }
            break;
        case OPTIONS_EXIT:
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_800BA8D8(0x10);
                return true;
            }
            break;
        default:
            break;
    }

    if (updateSettings) {
        Save_SaveSettingsProfiles();
    }
    return false;
}

extern s32 D_800E5F00[];
extern s32 D_800E5F10[];

void func_i6_8011CBB4(void) {
    s32 lastSelectionState;
    s32 pad;
    s32 i;
    bool updateSettings;

    if (func_8008108C(D_i6_801247A4, 1) != 0) {
        lastSelectionState = sOptionsSelectionState[gOptionsCurrentRow];
        if (gInputButtonPressed & BTN_LEFT) {
            if (--sOptionsSelectionState[gOptionsCurrentRow] < 0) {
                sOptionsSelectionState[gOptionsCurrentRow] = 1;
            }
        }
        if (gInputButtonPressed & BTN_RIGHT) {
            if (++sOptionsSelectionState[gOptionsCurrentRow] > 1) {
                sOptionsSelectionState[gOptionsCurrentRow] = 0;
            }
        }
        if (lastSelectionState != sOptionsSelectionState[gOptionsCurrentRow]) {
            func_800BA8D8(0x1E);
        }
        updateSettings = false;
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            updateSettings = true;
            if (sOptionsSelectionState[gOptionsCurrentRow] == 1) {
                Save_Init(sSaveContextPtr, 1);
                func_i6_8011C404();
                for (i = 0; i < 4; i++) {
                    D_800E5F00[i] = D_800E5F10[i] = 0;
                }
                func_8007E398();
                func_800BA8D8(5);
            } else {
                func_800BA8D8(0x10);
            }
        } else if (gInputButtonPressed & BTN_B) {
            updateSettings = true;
            func_800BA8D8(0x10);
        }
        if (updateSettings) {
            sOptionsDataClearMenu = OPTIONS_DATA_CLEAR_MENU_CLOSED;
            func_80080BDC(D_i6_801247A4);
        }
    }
}

Gfx* func_i6_8011D8C8(Gfx*);

Gfx* OptionsMenu_Draw(Gfx* gfx) {
    s32 temp_s4;
    s32 var_s5;
    s32 i;
    s32 var_s7;
    OptionsInfo* option;
    OptionsTextureInfo* selectionStateTextureInfo;
    OptionsTextureInfo* optionTextureInfo;

    gfx = Object_UpdateAndDrawAll(gfx);
    if (D_i6_801247A8 != 1) {
        gfx = func_8007B14C(gfx, func_800783AC(aTitleBackgroundMainTex), 8, 0, 304, 240, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0,
                            0, 0, 0);
    }
    if (D_i6_801247A8 != 0) {
        gfx = func_i6_8011D8C8(gfx);
    }
    gfx = func_8007B14C(gfx, func_800783AC(aOptionsFalconHelmetTex), 50, 4, 64, 64, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0,
                        1, 0);
    gfx = func_8007B14C(gfx, func_800783AC(aOptionsFalconHelmetTex), 206, 4, 64, 64, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0,
                        0, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_8007E410(gfx, func_800783AC(aOptionsTex), func_800783AC(aMenuTextTLUT), G_IM_FMT_CI, 1, 112, 22, 96, 24,
                        3);

    var_s5 = 60;

    if (D_i6_801247B0 != 0) {
        var_s7 = 0x17;
    } else {
        var_s7 = 0x1B;
    }

    for (i = 0, option = gOptionsInfo; i < 7; i++, option++) {
        if (!(option->flags & OPTIONS_SHOWN)) {
            continue;
        }

        gDPPipeSync(gfx++);
        if (gOptionsCurrentRow != i) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            gfx = func_8007DB28(gfx, 0);
        }
        optionTextureInfo = &option->optionTextureInfo;
        gfx = func_8007E410(gfx, func_800783AC(optionTextureInfo->textureOffset), NULL, G_IM_FMT_CI, 1,
                            option->unk_0C + 0x1E, var_s5, optionTextureInfo->width, optionTextureInfo->height, 0);

        if (!(option->flags & OPTIONS_REQUIRE_SELECTING)) {
            gfx =
                func_8007E410(gfx, func_800783AC(aMenuLeftArrowTex), NULL, G_IM_FMT_CI, 1, 0xBE, var_s5, 0x10, 0x10, 0);
            gfx = func_8007E410(gfx, func_800783AC(aMenuRightArrowTex), NULL, G_IM_FMT_CI, 1, 0x109, var_s5, 0x10, 0x10,
                                0);
            selectionStateTextureInfo = &option->selectionStateTextureInfo[sOptionsSelectionState[i]];
            temp_s4 = ((60 - selectionStateTextureInfo->width) / 2) + option->unk_10;
            gfx = func_8007E410(gfx, func_800783AC(selectionStateTextureInfo->textureOffset), NULL, G_IM_FMT_CI, 1,
                                temp_s4 + 0xD0, var_s5, selectionStateTextureInfo->width,
                                selectionStateTextureInfo->height, 0);
        }
        var_s5 += var_s7;
    }

    return func_80080E90(gfx);
}

Gfx* func_i6_8011D168(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 sp54;
    OptionsTextureInfo* dataClearTextureInfo;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    gfx = func_8007E410(gfx, func_800783AC(aOptionsEraseAllSavedDataTex), func_800783AC(aMenuTextTLUT), G_IM_FMT_CI, 1,
                        arg1 + 0xC, arg2 + 0xA, 128, 32, 3);

    gDPPipeSync(gfx++);
    gfx = func_8007DB28(gfx, 0);
    gfx =
        func_8007E410(gfx, func_800783AC(aMenuLeftArrowTex), NULL, G_IM_FMT_CI, 1, arg1 + 0x18, arg2 + 0x32, 16, 16, 0);
    gfx = func_8007E410(gfx, func_800783AC(aMenuRightArrowTex), NULL, G_IM_FMT_CI, 1, arg1 + 0x63, arg2 + 0x32, 16, 16,
                        0);
    dataClearTextureInfo = &gOptionsAllDataClearSelection[sOptionsSelectionState[gOptionsCurrentRow]];
    sp54 = (60 - dataClearTextureInfo->width) / 2;
    return func_8007E410(gfx, func_800783AC(dataClearTextureInfo->textureOffset), NULL, G_IM_FMT_CI, 1,
                         arg1 + sp54 + 0x2A, arg2 + 0x32, dataClearTextureInfo->width, dataClearTextureInfo->height, 0);
}

extern GfxPool* gGfxPool;
extern s32 D_800DCCFC;

#ifdef NON_MATCHING
void func_i6_8011D394(void) {
    s32 i;
    s32 j;
    s32 k;
    Vtx* vtx;
    s32 temp_a2;
    s32 temp_a3;
    s32 var_s0;
    s32 var_s1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 sp28[4];
    f32 sp38[4];
    f32 sp48[4];
    f32 sp58[4];
    s32 x;
    s32 y;
    s32 s;
    s32 t;

    switch (D_i6_801247A8) {
        case 0:
            break;
        case 1:
            if (D_800CD3C4 == 0) {
                D_i6_801247A8 = 2;
                D_i6_801247AA = 0;
            }
            break;
        case 2:
            temp_a2 = (11 - ((D_i6_801247AA * 11) / 120));
            temp_a3 = (16 - ((D_i6_801247AA * 16) / 120));
            for (i = 0; i < 16; i++) {

                if (i < temp_a3) {
                    continue;
                }

                for (j = 0; j < 11; j++) {
                    if (j < temp_a2) {
                        continue;
                    }
                    D_i6_80124620[i * 11 + j] -= 5;
                    if (D_i6_80124620[i * 11 + j] < 0) {
                        D_i6_80124620[i * 11 + j] = 0;
                    }
                }
            }
            D_i6_801247AA++;
            break;
    }
    if (D_i6_801247A8 == 0) {
        return;
    }

    D_i6_80124618 = D_i6_8011FB18[D_800DCCFC];
    func_8006D2E0(gGfxPool->unk_2B248, NULL, 1.0f, 0.0f, 319.0f, 239.0f, 0.0f, -100.0f, 100.0f);
    vtx = D_i6_80124618;

    var_s0 = 32;
    var_s1 = 16;

    for (i = 0; i < 15; i++) {

        for (j = 0; j < 10; j++) {
            temp_fv0 = i * var_s1;
            temp_fv1 = j * var_s0;

            sp48[0] = sp48[2] = temp_fv1 - 0.5f;
            sp48[1] = sp48[3] = sp48[0] + var_s0;

            sp58[0] = sp58[1] = temp_fv0 - 0.5f;
            sp58[2] = sp58[3] = sp58[0] + var_s1;

            sp28[0] = sp28[2] = (temp_fv1 + 0.0f) - 2.0f;
            sp28[1] = sp28[3] = sp28[0] + var_s0;

            sp38[0] = sp38[1] = (temp_fv0 + 0.0f) - 2.0f;
            sp38[2] = sp38[3] = sp38[0] + var_s1;

            for (k = 0; k < 4; k++) {
                x = sp28[k];
                y = sp38[k];
                s = sp48[k] * 32.0f;
                t = sp58[k] * 32.0f;
                SET_VTX(vtx, x, y, 0, s, t, 255, 255, 255, D_i6_80124620[i * 11 + j + (k & 1) + ((k >> 1) * 11)]);
                vtx++;
            }
        }
    }
}
#else
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/overlays/ovl_i6/options_menu/func_i6_8011D394.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i6/options_menu/func_i6_8011D394.s")
#endif
#endif

extern GfxPool D_1000000;
extern Mtx D_2000000[];
extern Gfx D_8014810[];

Gfx* func_i6_8011D8C8(Gfx* gfx) {
    s32 pad[27];
    s32 sp40;
    s32 lrt;
    s32 uls;
    s32 lrs;
    s32 ult;
    s32 var_s3;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 var_t5;

    if ((D_i6_801247A8 == 1) || (D_i6_801247A8 == 2)) {
        gfx = func_8006A00C(gfx, 0);
        gSPDisplayList(gfx++, D_8014810);
        gDPSetTextureFilter(gfx++, G_TF_POINT);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_NOOP2);
        gDPSetCombineMode(gfx++, G_CC_DECALRGB, G_CC_DECALRGB);
        gSPMatrix(gfx++, D_1000000.unk_2B248, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        for (sp40 = 0, var_s5 = 0x10, var_s4 = -1; var_s4 < SCREEN_HEIGHT - 1; var_s4 += 16, sp40 += 10, var_s5 += 16) {

            var_s3 = sp40 << 2;

            for (var_s2 = 32, var_t5 = -1; var_t5 < SCREEN_WIDTH - 1; var_t5 += 32, var_s3 += 4, var_s2 += 32) {
                uls = MAX(var_t5, 0);
                lrs = MIN(var_s2, SCREEN_WIDTH - 1);
                ult = MAX(var_s4, 0);
                lrt = MIN(var_s5, SCREEN_HEIGHT - 1);

                gSPVertex(gfx++, (u8*) D_i6_80124618 + (var_s3 << 4), 4, 0);
                gDPPipeSync(gfx++);
                gDPLoadTextureTile(gfx++, D_i6_801247AC, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                                   SCREEN_HEIGHT /* unused by macro */, uls, ult, lrs, lrt, 0,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                   G_TX_NOLOD, G_TX_NOLOD);
                gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
            }
        }
    }
    return gfx;
}
