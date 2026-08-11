#include "global.h"
#include "fzx_cache.h"
#include "machine_create.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_font.h"
#include "fzx_camera.h"
#include "fzx_machine.h"
#include ASSET_HEADER(machine_custom_gfx.h)
#include ASSET_HEADER(common_assets_compressed.h)
#include ASSET_HEADER_EK(expansion_kit_textures.h)
#include ASSET_HEADER_EK(overlays/machine_create/machine_create_assets.h)

static s32 sMachineSelectIndex;
static s32 sMachinesUnlocked;
s32 sPreviousMachineSelectIndex;

static CacheTexInfo sSmallPortraitDrStewartCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitDrStewartTex);
static CacheTexInfo sSmallPortraitCaptainFalconCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitCaptainFalconTex);
static CacheTexInfo sSmallPortraitJodySummerCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitJodySummerTex);
static CacheTexInfo sSmallPortraitSamuraiGorohCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitSamuraiGorohTex);
static CacheTexInfo sSmallPortraitMightyGazelleCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitMightyGazelleTex);
static CacheTexInfo sSmallPortraitPicoCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitPicoTex);
static CacheTexInfo sSmallPortraitBabaCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitBabaTex);
static CacheTexInfo sSmallPortraitMrEadCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitMrEadTex);
static CacheTexInfo sSmallPortraitOctomanCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitOctomanTex);
static CacheTexInfo sSmallPortraitTheSkullCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitTheSkullTex);
static CacheTexInfo sSmallPortraitBeastmanCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitBeastmanTex);
static CacheTexInfo sSmallPortraitAntonioGusterCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitAntonioGusterTex);
static CacheTexInfo sSmallPortraitDraqCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitDraqTex);
static CacheTexInfo sSmallPortraitRogerBusterCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitRogerBusterTex);
static CacheTexInfo sSmallPortraitSilverNeelsenCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitSilverNeelsenTex);
static CacheTexInfo sSmallPortraitSuperArrowCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitSuperArrowTex);
static CacheTexInfo sSmallPortraitMrsArrowCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitMrsArrowTex);
static CacheTexInfo sSmallPortraitZodaCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitZodaTex);
static CacheTexInfo sSmallPortraitJohnTanakaCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitJohnTanakaTex);
static CacheTexInfo sSmallPortraitBioRexCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitBioRexTex);
static CacheTexInfo sSmallPortraitKateAlenCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitKateAlenTex);
static CacheTexInfo sSmallPortraitGomarAndShiohCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitGomarAndShiohTex);
static CacheTexInfo sSmallPortraitMichaelChainCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitMichaelChainTex);
static CacheTexInfo sSmallPortraitBillyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitBillyTex);
static CacheTexInfo sSmallPortraitDrClashCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitDrClashTex);
static CacheTexInfo sSmallPortraitJackLevinCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitJackLevinTex);
static CacheTexInfo sSmallPortraitBloodFalconCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitBloodFalconTex);
static CacheTexInfo sSmallPortraitLeonCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitLeonTex);
static CacheTexInfo sSmallPortraitJamesMcCloudCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitJamesMcCloudTex);
static CacheTexInfo sSmallPortraitBlackShadowCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitBlackShadowTex);
static CacheTexInfo sSmallPortraitCaptainFalconAltCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitCaptainFalconAltTex);
static CacheTexInfo sSmallPortraitSamuraiGorohAltCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitSamuraiGorohAltTex);
static CacheTexInfo sSmallPortraitJodySummerAltCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aSmallPortraitJodySummerAltTex);

TextureSwapEntry D_xk3_80136C50[] = { { sSmallPortraitDrStewartCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136C60[] = { { sSmallPortraitCaptainFalconCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136C70[] = { { sSmallPortraitJodySummerCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136C80[] = { { sSmallPortraitSamuraiGorohCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136C90[] = { { sSmallPortraitMightyGazelleCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136CA0[] = { { sSmallPortraitPicoCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136CB0[] = { { sSmallPortraitBabaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136CC0[] = { { sSmallPortraitMrEadCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136CD0[] = { { sSmallPortraitOctomanCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136CE0[] = { { sSmallPortraitTheSkullCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136CF0[] = { { sSmallPortraitBeastmanCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136D00[] = { { sSmallPortraitAntonioGusterCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136D10[] = { { sSmallPortraitDraqCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136D20[] = { { sSmallPortraitRogerBusterCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136D30[] = { { sSmallPortraitSilverNeelsenCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136D40[] = { { sSmallPortraitSuperArrowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136D50[] = { { sSmallPortraitMrsArrowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136D60[] = { { sSmallPortraitZodaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136D70[] = { { sSmallPortraitJohnTanakaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136D80[] = { { sSmallPortraitBioRexCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136D90[] = { { sSmallPortraitKateAlenCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136DA0[] = { { sSmallPortraitGomarAndShiohCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136DB0[] = { { sSmallPortraitMichaelChainCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136DC0[] = { { sSmallPortraitBillyCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136DD0[] = { { sSmallPortraitDrClashCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136DE0[] = { { sSmallPortraitJackLevinCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136DF0[] = { { sSmallPortraitBloodFalconCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136E00[] = { { sSmallPortraitLeonCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136E10[] = { { sSmallPortraitJamesMcCloudCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136E20[] = { { sSmallPortraitBlackShadowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136E30[] = { { sSmallPortraitCaptainFalconAltCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136E40[] = { { sSmallPortraitSamuraiGorohAltCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_xk3_80136E50[] = { { sSmallPortraitJodySummerAltCacheTexInfo, 60 }, { 0 } };

TextureSwapEntry* D_xk3_80136E60[] = {
    D_xk3_80136C60, D_xk3_80136C50, D_xk3_80136CA0, D_xk3_80136C80, D_xk3_80136C70, D_xk3_80136C90,
    D_xk3_80136CC0, D_xk3_80136CB0, D_xk3_80136CD0, D_xk3_80136DA0, D_xk3_80136D90, D_xk3_80136D20,
    D_xk3_80136E10, D_xk3_80136E00, D_xk3_80136D00, D_xk3_80136E20, D_xk3_80136DB0, D_xk3_80136DE0,
    D_xk3_80136D40, D_xk3_80136D50, D_xk3_80136D70, D_xk3_80136CF0, D_xk3_80136D60, D_xk3_80136DD0,
    D_xk3_80136D30, D_xk3_80136D80, D_xk3_80136D10, D_xk3_80136DC0, D_xk3_80136CE0, D_xk3_80136DF0,
    D_xk3_80136E30, D_xk3_80136E30, D_xk3_80136E30, D_xk3_80136E40, D_xk3_80136E50, D_xk3_80136E30,
};

static CacheTexInfo sMachineSelectCursorCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aMachineSelectCursorTex);
static CacheTexInfo sBoostCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aBoostTex);
//! @bug should be 0x46 size
static CacheTexInfo sBodyCacheTexInfo[] = CACHE_TEX_INFO_PAD(TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16), aBodyTex, 0x4E);
static CacheTexInfo sGripCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aGripTex);

static CacheTexInfo* sMachineStatCacheTexInfos[] = {
    sBodyCacheTexInfo,
    sBoostCacheTexInfo,
    sGripCacheTexInfo,
};

static const char* sMachineStatValueStr[] = { "a", "b", "c", "d", "e" };

u8 sMachineCreateCanUndoStep = 0;

extern s16 gGreyscaleMachinePart;
extern u8 gCustomMachineCurrentSuperIndex;
extern u8 gCustomMachineIsSuper;
extern s8 gSettingEverythingUnlocked;

void MachineCreate_MachineSelectInit(void) {
    Camera_Init();
    gGreyscaleMachinePart = true;
    func_8008D97C();
    if (gCustomMachineIsSuper) {
        sMachineSelectIndex = gCustomMachineCurrentSuperIndex;
    } else {
        sMachineSelectIndex = 0;
    }
    sMachinesUnlocked = ((func_8007E008() / 3) * 6) + 6;
    if (gSettingEverythingUnlocked != 0) {
        sMachinesUnlocked = 30;
    }
    if (sMachinesUnlocked > 30) {
        sMachinesUnlocked = 30;
    }
    Camera_Update();
}

extern u16 gInputPressed;

void MachineCreate_MachineSelectHandleStickInputs(void) {
    s32 originalIndex;

    Controller_SetGlobalInputs(&gControllers[gPlayerControlPorts[0]]);
    originalIndex = sMachineSelectIndex;

    if (gCustomMachineIsSuper) {
        if (sMachineSelectIndex == 30) {
            if ((gInputPressed & BTN_DOWN) || (gInputPressed & BTN_LEFT)) {
                sMachineSelectIndex = gCustomMachineCurrentSuperIndex;
                sMachineCreateCanUndoStep = 0;
            }
        } else if ((gInputPressed & BTN_UP) || (gInputPressed & BTN_RIGHT)) {
            sMachineSelectIndex = 30;
        }
    } else if (sMachineSelectIndex == 30) {
        if (gInputPressed & BTN_UP) {
            sMachineSelectIndex = sMachinesUnlocked - 1;
            sMachineCreateCanUndoStep = 0;
        } else if ((gInputPressed & BTN_DOWN) && (gInputPressed & BTN_LEFT)) {
            sMachineSelectIndex = 4;
            sMachineCreateCanUndoStep = 0;
        } else if (gInputPressed & BTN_DOWN) {
            sMachineSelectIndex = 5;
            sMachineCreateCanUndoStep = 0;
        }
    } else {
        if (gInputPressed & BTN_LEFT) {
            if ((sMachineSelectIndex % 6) != 0) {
                sMachineSelectIndex--;
            } else {
                sMachineSelectIndex += 5;
            }
        } else if (gInputPressed & BTN_RIGHT) {
            if ((sMachineSelectIndex % 6) < 5) {
                sMachineSelectIndex++;
            } else {
                sMachineSelectIndex -= 5;
            }
        }
        if (gInputPressed & BTN_UP) {
            if (sMachineSelectIndex == 5) {
                sMachineSelectIndex = 30;
            } else {
                sMachineSelectIndex -= 6;
            }
        } else if (gInputPressed & BTN_DOWN) {
            if (sMachineSelectIndex == sMachinesUnlocked - 1) {
                sMachineSelectIndex = 30;
            } else if (sMachineSelectIndex == 24) {
                sMachineSelectIndex = 0;
            } else {
                sMachineSelectIndex += 6;
            }
        }
        if (sMachineSelectIndex != 30) {
            sMachineSelectIndex += sMachinesUnlocked;
            sMachineSelectIndex %= sMachinesUnlocked;
        }
    }
    if (originalIndex != sMachineSelectIndex) {
        Audio_TriggerSystemSE(NA_SE_30);
    }
}

extern u8 D_xk3_80141290;
extern u8 D_xk3_80141291;
extern u8 kCharacterNumbers[];
extern CustomMachinesInfo gCustomMachinesInfoBackup;
extern CustomMachinesInfo gCustomMachinesInfo;
extern CustomMachine gCustomMachine;
extern CustomMachine gCustomMachineWork;
extern CustomMachine gCustomMachineBackup;

void MachineCreate_MachineSelectHandleAPress(void) {
    u8 i;

    if (sMachineSelectIndex == 30) {
        for (i = 0; i < 30; i++) {
            if (gCustomMachinesInfo.characterCustomState[i] == 1) {
                gCustomMachinesInfo.characterCustomState[i] = 2;
                break;
            }
        }
        gGreyscaleMachinePart = false;
        sMachineCreateCanUndoStep = 0;
        PRINTF("WORKS MACHINE MODE : 0\n");
        gWorksMachineMode = MACHINE_MODE_0;
        Audio_TriggerSystemSE(NA_SE_36);
        gCustomMachine = gCustomMachineBackup;
        gCustomMachineIsSuper = D_xk3_80141290;
        gCustomMachineCurrentSuperIndex = D_xk3_80141291;
        func_xk3_8012D700();
    } else {
        gCustomMachinesInfoBackup = gCustomMachinesInfo;

        if (gCustomMachineIsSuper) {
            gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] = -1;
            func_8008D33C();
        } else {
            gCustomMachineWork = gCustomMachine;

            for (i = 0; i < 30; i++) {
                if (gCustomMachinesInfo.characterCustomState[i] == 1) {
                    gCustomMachinesInfo.characterCustomState[i] = 0;
                    gCustomMachinesInfo.customMachines[i].number = 31;
                    func_8008D33C();
                    break;
                }
            }
            gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] = 1;
            gCustomMachine.number = kCharacterNumbers[sMachineSelectIndex];
            gCustomMachinesInfo.customMachines[sMachineSelectIndex] = gCustomMachine;
        }
        Audio_TriggerSystemSE(NA_SE_39);
        sPreviousMachineSelectIndex = sMachineSelectIndex;
        sMachineSelectIndex = 30;
        sMachineCreateCanUndoStep = 1;
    }
}

void MachineCreate_MachineSelectHandleBPress(void) {

    if (sMachineSelectIndex < 30) {
        if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] == 0) {
            return;
        }

        gCustomMachinesInfoBackup = gCustomMachinesInfo;

        if (!gCustomMachineIsSuper) {
            gCustomMachineWork = gCustomMachine;
            if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] == 1) {
                if (1) {}
                gCustomMachine.number = 31;
            }
        }
        gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] = 0;
        gCustomMachinesInfo.customMachines[sMachineSelectIndex].number = 31;
        sPreviousMachineSelectIndex = sMachineSelectIndex;
        sMachineSelectIndex = 30;
        sMachineCreateCanUndoStep = 1;
    } else if (sMachineSelectIndex == 30) {
        if (sMachineCreateCanUndoStep == 0) {
            return;
        }
        if (sMachineCreateCanUndoStep == 1) {
            sMachineCreateCanUndoStep = 0;
            gCustomMachinesInfo = gCustomMachinesInfoBackup;
            if (!gCustomMachineIsSuper) {
                gCustomMachine = gCustomMachineWork;
            }
            sMachineSelectIndex = sPreviousMachineSelectIndex;
        }
    }
    Audio_TriggerSystemSE(NA_SE_37);
    func_8008D33C();
}

extern s32 sMachineSelectIndex;

void MachineCreate_MachineSelectUpdate(void) {

    Camera_Update();
    MachineCreate_MachineSelectHandleStickInputs();

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        MachineCreate_MachineSelectHandleAPress();
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        MachineCreate_MachineSelectHandleBPress();
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_START) {
        sMachineSelectIndex = 30;
    }
}

Gfx* MachineCreate_DrawMachineSelect(Gfx* gfx) {

    gfx = Object_UpdateAndDrawAll(gfx);
    TextureCache_ProcessLoadQueue();
    gSPDisplayList(gfx++, D_xk3_80137378);

    if (sMachineSelectIndex == 30) {
        gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aMachineCreateHighlightedOkTex, 244, 18, 32, 16);
    } else {
        gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aMachineCreateOkTex, 244, 18, 32, 16);
        if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] > 0) {
            gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aMachineCreateEditMarkerTex, 70, 19, 28, 8);
        } else if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] < 0) {
            gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aMachineCreateSuperMarkerTex, 70, 19, 36, 8);
        }
    }

    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gDPLoadTextureBlock(gfx++, aExpansionKitABButtonTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    // Draw A Button
    gSPTextureRectangle(gfx++, 120 << 2, 212 << 2, (120 + 16 - 1) << 2, (212 + 16 - 1) << 2, 0, 0, 0, 4 * (1 << 10),
                        1 << 10);

    // Draw B Button
    gSPTextureRectangle(gfx++, 214 << 2, 212 << 2, (214 + 16 - 1) << 2, (212 + 16 - 1) << 2, 0, 0, 16 << 5,
                        4 * (1 << 10), 1 << 10);

    gSPDisplayList(gfx++, D_xk3_801373F0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateEnterTex, 140, 216, 56, 8);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateReturnTex, 234, 216, 48, 8);

    return gfx;
}

void MachineCreate_MachineSelectPortraitInit(Object* portraitObj) {
    OBJECT_CACHE_INDEX(portraitObj) = TextureCache_AllocSwapSlot(D_xk3_80136E60[0]);
    OBJECT_STATE(portraitObj) = -1;
}

void MachineCreate_MachineSelectStatsInit(void) {
    s32 i;

    for (i = BODY_STAT; i <= GRIP_STAT; i++) {
        TextureCache_LoadCacheTexInfoList_impl(sMachineStatCacheTexInfos[i], false, false);
    }
}

void MachineCreate_MachineSelectMachineInit(Object* machineObj) {
    Vp* vp;
    s32 i;
    s32 j;

    vp = Arena_Allocate(ALLOC_FRONT, 30 * sizeof(Vp));
    MACHINE_VIEWPORT(machineObj) = vp;
    for (i = 0; i < 30; i++) {
        vp[i].vp.vscale[0] = (SCREEN_WIDTH / 2) << 2;
        vp[i].vp.vscale[1] = (SCREEN_HEIGHT / 2) << 2;
        vp[i].vp.vscale[2] = 0x1FF;
        vp[i].vp.vscale[3] = 0;
        vp[i].vp.vtrans[0] = (((i % 6) * 0x28) + 0x3B) << 2;
        vp[i].vp.vtrans[1] = (((i / 6) * 0x22) + 0x3B) << 2;
        vp[i].vp.vtrans[2] = 0x1FF;
        vp[i].vp.vtrans[3] = 0;
    }

    for (j = 1; j >= 0; j--) {
        gRacers[j].segmentPositionInfo.pos.x = gRacers[j].segmentPositionInfo.pos.y =
            gRacers[j].segmentPositionInfo.pos.z = 0.0f;
        gRacers[j].trueBasis.x.z = 1.0f;
        gRacers[j].trueBasis.y.y = 1.0f;
        gRacers[j].trueBasis.z.x = 1.0f;
        gRacers[j].trueBasis.x.x = 0.0f;
        gRacers[j].trueBasis.y.z = 0.0f;
        gRacers[j].trueBasis.z.y = 0.0f;
        gRacers[j].trueBasis.x.y = 0.0f;
        gRacers[j].trueBasis.y.x = 0.0f;
        gRacers[j].trueBasis.z.z = 0.0f;
    }
}

void MachineCreate_MachineSelectCursorInit(void) {
    TextureCache_LoadCacheTexInfoList_impl(sMachineSelectCursorCacheTexInfo, false, false);
}

extern const char* gMachineNames[];
extern TexSwapSlot gTextureSwapSlots[];
extern const char* gSuperMachineNames[];

Gfx* MachineCreate_MachineSelectPortraitDraw(Gfx* gfx, Object* portraitObj) {

    if (gWorksMachineMode != MACHINE_MODE_ENTRY) {
        return gfx;
    }
    if (sMachineSelectIndex < 30) {
        gfx = TextureCache_DrawSwapSlot_impl(gfx, &gTextureSwapSlots[OBJECT_CACHE_INDEX(portraitObj)], OBJECT_LEFT(portraitObj),
                                             OBJECT_TOP(portraitObj), TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, false);
        if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] > 0) {
            gfx = Font_DrawString(gfx, 70, 37, gCustomMachinesInfo.customMachines[sMachineSelectIndex].machineName,
                                  0, 2, 0);
        } else if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] < 0) {
            gfx = Font_DrawString(gfx, 70, 37, gSuperMachineNames[sMachineSelectIndex], 0, 2, 0);
        } else {
            gfx = Font_DrawString(gfx, 70, 37, gMachineNames[Character_GetCharacterFromSlot(sMachineSelectIndex)],
                                  0, 2, 0);
        }
    }
    return gfx;
}

extern u8 kSuperMachineStatValues[][3];
extern Machine gMachines[];

Gfx* MachineCreate_MachineSelectStatsDraw(Gfx* gfx, Object* statsObj) {
    s32 pad;
    s32 var_s6;
    s32 i;
    s8* machineStats;
    char* statValueStr;

    if (gWorksMachineMode != MACHINE_MODE_ENTRY) {
        return gfx;
    }

    if (sMachineSelectIndex < 30) {
        machineStats = gMachines[Character_GetCharacterFromSlot(sMachineSelectIndex)].machineStats;

        var_s6 = 53;
        for (i = BODY_STAT; i <= GRIP_STAT; i++) {
            gfx = TextureCache_DrawList_impl(gfx, sMachineStatCacheTexInfos[i], 19, var_s6 + i * 20, TEXTURE_CACHE_DRAW,
                                             false, false, 1.0f, 1.0f, false);

            if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] > 0) {
                switch (i) {
                    case BODY_STAT:
                        MachineCreate_StatValueToString(&statValueStr,
                                                        gCustomMachinesInfo.customMachines[sMachineSelectIndex].body);
                        break;
                    case BOOST_STAT:
                        MachineCreate_StatValueToString(&statValueStr,
                                                        gCustomMachinesInfo.customMachines[sMachineSelectIndex].boost);
                        break;
                    case GRIP_STAT:
                        MachineCreate_StatValueToString(&statValueStr,
                                                        gCustomMachinesInfo.customMachines[sMachineSelectIndex].grip);
                        break;
                }
            } else if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] < 0) {
                MachineCreate_StatValueToString(&statValueStr, kSuperMachineStatValues[sMachineSelectIndex][i]);
            } else {
                statValueStr = sMachineStatValueStr[machineStats[i]];
            }
            gfx = Font_DrawString(gfx, 24, 70 + i * 20, statValueStr, 0, 2, 0);
        }
    }
    return gfx;
}

Gfx* MachineCreate_MachineSelectMachineCustomDraw(Gfx* gfx, s32 characterSlot) {

    gfx = Machine_DrawLoadCustomTextures(gfx, gCustomMachinesInfo.customMachines[characterSlot].logo - 1,
                                         gCustomMachinesInfo.customMachines[characterSlot].number - 1,
                                         gCustomMachinesInfo.customMachines[characterSlot].decal - 1);
    gDPSetEnvColor(gfx++, gCustomMachinesInfo.customMachines[characterSlot].red,
                   gCustomMachinesInfo.customMachines[characterSlot].green,
                   gCustomMachinesInfo.customMachines[characterSlot].blue, 255);

    gfx = Machine_DrawCustom(gfx, 0, gCustomMachinesInfo.customMachines[characterSlot].frontType,
                             gCustomMachinesInfo.customMachines[characterSlot].rearType,
                             gCustomMachinesInfo.customMachines[characterSlot].wingType,
                             gCustomMachinesInfo.customMachines[characterSlot].decalR,
                             gCustomMachinesInfo.customMachines[characterSlot].decalG,
                             gCustomMachinesInfo.customMachines[characterSlot].decalB,
                             gCustomMachinesInfo.customMachines[characterSlot].numberR,
                             gCustomMachinesInfo.customMachines[characterSlot].numberG,
                             gCustomMachinesInfo.customMachines[characterSlot].numberB, 255, 255, 255,
                             gCustomMachinesInfo.customMachines[characterSlot].cockpitR,
                             gCustomMachinesInfo.customMachines[characterSlot].cockpitG,
                             gCustomMachinesInfo.customMachines[characterSlot].cockpitB);

    return gfx;
}

extern GfxPool D_1000000;
extern GfxPool* gGfxPool;

Gfx* MachineCreate_MachineSelectMachineDraw(Gfx* gfx, Object* machineObj) {
    s32 i;

    if (gWorksMachineMode != MACHINE_MODE_ENTRY) {
        return gfx;
    }
    gSPLoadUcodeL(gfx++, gspF3DEX2_Rej_fifo);
    gfx = Segment_SetTableAddresses(gfx);
    gSPClipRatio(gfx++, FRUSTRATIO_3);
    gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
    gSPMatrix(gfx++, &D_1000000.unk_20208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gfx++, D_303A5F8);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].a, 2);
    gSPNumLights(gfx++, NUMLIGHTS_1);
    Lights_SetSource(gGfxPool->unk_21A88, 0, 0, 0, 255, 255, 255, 100, 50, 69);
    Lights_SetSource(&gGfxPool->unk_21A88[1], 0, 0, 0, 100, 70, 70, 100, 50, 69);

    for (i = 0; i < 30; i++) {

        if (i < sMachinesUnlocked) {
            gSPLight(gfx++, &D_1000000.unk_21A88[0].l[0], 1);
            gSPLight(gfx++, &D_1000000.unk_21A88[0].a, 2);
        } else {
            gSPLight(gfx++, &D_1000000.unk_21A88[1].l[0], 1);
            gSPLight(gfx++, &D_1000000.unk_21A88[1].a, 2);
        }

        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i);

        if (i == sMachineSelectIndex) {
            gSPMatrix(gfx++, &D_1000000.unk_20308[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        } else {
            gSPMatrix(gfx++, &D_1000000.unk_20308[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        }
        gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);

        if (gCustomMachinesInfo.characterCustomState[i] > 0) {
            gfx = MachineCreate_MachineSelectMachineCustomDraw(gfx, i);
        } else if (gCustomMachinesInfo.characterCustomState[i] < 0) {
            gGreyscaleMachinePart = false;
            switch (i) {
                case CAPTAIN_FALCON:
                    gfx = Machine_DrawLoadBlueFalconTextures(gfx);
                    gDPSetEnvColor(gfx++, 223, 199, 33, 255);
                    gfx = Machine_DrawSuperFalconLod1(gfx);
                    break;
                case SAMURAI_GOROH:
                    gfx = Machine_DrawLoadFireStingrayTextures(gfx);
                    gDPSetEnvColor(gfx++, 55, 55, 55, 255);
                    gfx = Machine_DrawSuperStingrayLod1(gfx);
                    break;
                case JODY_SUMMER:
                    gfx = Machine_DrawLoadWhiteCatTextures(gfx);
                    gDPSetEnvColor(gfx++, 33, 55, 137, 255);
                    gfx = Machine_DrawSuperCatLod1(gfx);
                    break;
            }
            gGreyscaleMachinePart = true;
        } else {
            gfx = func_8009CCBC(gfx, Character_GetCharacterFromSlot(i), 0);
        }
    }

    return gfx;
}

extern u32 gGameFrameCount;

Gfx* MachineCreate_MachineSelectCursorDraw(Gfx* gfx, Object* cursorObj) {
    u16 counter;
    s32 green;
    s32 blue;

    if (gWorksMachineMode != MACHINE_MODE_ENTRY) {
        return gfx;
    }
    if (sMachineSelectIndex < 30) {
        counter = gGameFrameCount % 30;
        green = 255;
        blue = 255;
        if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] != 0) {
            green = 155;
            blue = 55;
        }
        if (counter >= 15) {
            gDPSetPrimColor(gfx++, 0, 0, 255, green, blue, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, green, blue, 255 - ((counter * 510) / 30));
        }
        OBJECT_LEFT(cursorObj) = ((sMachineSelectIndex % 6) * 0x28) + 0x28;
        OBJECT_TOP(cursorObj) = ((sMachineSelectIndex / 6) * 0x22) + 0x27;
        gfx = TextureCache_DrawList_impl(gfx, sMachineSelectCursorCacheTexInfo, OBJECT_LEFT(cursorObj), OBJECT_TOP(cursorObj),
                                         TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, false);
    }
    return gfx;
}

void MachineCreate_MachineSelectPortraitUpdate(Object* portraitObj) {
    s32 character;

    if (gWorksMachineMode != MACHINE_MODE_ENTRY) {
        return;
    }

    if (sMachineSelectIndex != OBJECT_STATE(portraitObj)) {
        character = Character_GetCharacterFromSlot(sMachineSelectIndex);
        if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] == -1) {
            character += 30;
            if (character >= 36) {
                character %= 30;
            }
        }
        TextureCache_SetSwapSlotEntry(OBJECT_CACHE_INDEX(portraitObj), 0, D_xk3_80136E60[character]);
    }
    OBJECT_STATE(portraitObj) = sMachineSelectIndex;
}

extern f32 D_800CE748;
extern f32 D_800CE74C;
extern f32 D_800CE750;

void MachineCreate_MachineSelectMachineUpdate(Object* machineObj) {
    Racer* racer;
    f32 rotationSpeed;
    s32 i;

    if (gWorksMachineMode != MACHINE_MODE_ENTRY) {
        return;
    }

    for (i = 1, racer = &gRacers[i]; racer >= gRacers; i--, racer--) {

        if (racer == gRacers) {
            rotationSpeed = 0.03f;
        } else {
            rotationSpeed = 0.0f;
        }
        racer->trueBasis.x.x += rotationSpeed * racer->trueBasis.z.x;
        racer->trueBasis.x.y += rotationSpeed * racer->trueBasis.z.y;
        racer->trueBasis.x.z += rotationSpeed * racer->trueBasis.z.z;
        Math_OrthonormalizeAroundForward(&racer->trueBasis);
        Matrix_SetLockedLookAt(&gGfxPool->unk_20308[i], NULL, D_800CE748, D_800CE74C, D_800CE750, racer->trueBasis.x.x,
                               racer->trueBasis.x.y, racer->trueBasis.x.z, racer->trueBasis.y.x, racer->trueBasis.y.y,
                               racer->trueBasis.y.z, racer->segmentPositionInfo.pos.x, racer->segmentPositionInfo.pos.y,
                               racer->segmentPositionInfo.pos.z);
    }
}
