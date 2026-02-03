#include "global.h"
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

static unk_80077D50 sSmallPortraitDrStewartCompTexInfo[] = {
    { 17, aSmallPortraitDrStewartTex, TEX_WIDTH(aSmallPortraitDrStewartTex), TEX_HEIGHT(aSmallPortraitDrStewartTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitDrStewartTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitCaptainFalconCompTexInfo[] = {
    { 17, aSmallPortraitCaptainFalconTex, TEX_WIDTH(aSmallPortraitCaptainFalconTex),
      TEX_HEIGHT(aSmallPortraitCaptainFalconTex), TEX_COMPRESSED_SIZE(aSmallPortraitCaptainFalconTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitJodySummerCompTexInfo[] = {
    { 17, aSmallPortraitJodySummerTex, TEX_WIDTH(aSmallPortraitJodySummerTex), TEX_HEIGHT(aSmallPortraitJodySummerTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitJodySummerTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitSamuraiGorohCompTexInfo[] = {
    { 17, aSmallPortraitSamuraiGorohTex, TEX_WIDTH(aSmallPortraitSamuraiGorohTex),
      TEX_HEIGHT(aSmallPortraitSamuraiGorohTex), TEX_COMPRESSED_SIZE(aSmallPortraitSamuraiGorohTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitMightyGazelleCompTexInfo[] = {
    { 17, aSmallPortraitMightyGazelleTex, TEX_WIDTH(aSmallPortraitMightyGazelleTex),
      TEX_HEIGHT(aSmallPortraitMightyGazelleTex), TEX_COMPRESSED_SIZE(aSmallPortraitMightyGazelleTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitPicoCompTexInfo[] = { { 17, aSmallPortraitPicoTex, TEX_WIDTH(aSmallPortraitPicoTex),
                                                          TEX_HEIGHT(aSmallPortraitPicoTex),
                                                          TEX_COMPRESSED_SIZE(aSmallPortraitPicoTex) },
                                                        { 0 } };
static unk_80077D50 sSmallPortraitBabaCompTexInfo[] = { { 17, aSmallPortraitBabaTex, TEX_WIDTH(aSmallPortraitBabaTex),
                                                          TEX_HEIGHT(aSmallPortraitBabaTex),
                                                          TEX_COMPRESSED_SIZE(aSmallPortraitBabaTex) },
                                                        { 0 } };
static unk_80077D50 sSmallPortraitMrEadCompTexInfo[] = {
    { 17, aSmallPortraitMrEadTex, TEX_WIDTH(aSmallPortraitMrEadTex), TEX_HEIGHT(aSmallPortraitMrEadTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitMrEadTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitOctomanCompTexInfo[] = {
    { 17, aSmallPortraitOctomanTex, TEX_WIDTH(aSmallPortraitOctomanTex), TEX_HEIGHT(aSmallPortraitOctomanTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitOctomanTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitTheSkullCompTexInfo[] = {
    { 17, aSmallPortraitTheSkullTex, TEX_WIDTH(aSmallPortraitTheSkullTex), TEX_HEIGHT(aSmallPortraitTheSkullTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitTheSkullTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitBeastmanCompTexInfo[] = {
    { 17, aSmallPortraitBeastmanTex, TEX_WIDTH(aSmallPortraitBeastmanTex), TEX_HEIGHT(aSmallPortraitBeastmanTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitBeastmanTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitAntonioGusterCompTexInfo[] = {
    { 17, aSmallPortraitAntonioGusterTex, TEX_WIDTH(aSmallPortraitAntonioGusterTex),
      TEX_HEIGHT(aSmallPortraitAntonioGusterTex), TEX_COMPRESSED_SIZE(aSmallPortraitAntonioGusterTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitDraqCompTexInfo[] = { { 17, aSmallPortraitDraqTex, TEX_WIDTH(aSmallPortraitDraqTex),
                                                          TEX_HEIGHT(aSmallPortraitDraqTex),
                                                          TEX_COMPRESSED_SIZE(aSmallPortraitDraqTex) },
                                                        { 0 } };
static unk_80077D50 sSmallPortraitRogerBusterCompTexInfo[] = {
    { 17, aSmallPortraitRogerBusterTex, TEX_WIDTH(aSmallPortraitRogerBusterTex),
      TEX_HEIGHT(aSmallPortraitRogerBusterTex), TEX_COMPRESSED_SIZE(aSmallPortraitRogerBusterTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitSilverNeelsenCompTexInfo[] = {
    { 17, aSmallPortraitSilverNeelsenTex, TEX_WIDTH(aSmallPortraitSilverNeelsenTex),
      TEX_HEIGHT(aSmallPortraitSilverNeelsenTex), TEX_COMPRESSED_SIZE(aSmallPortraitSilverNeelsenTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitSuperArrowCompTexInfo[] = {
    { 17, aSmallPortraitSuperArrowTex, TEX_WIDTH(aSmallPortraitSuperArrowTex), TEX_HEIGHT(aSmallPortraitSuperArrowTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitSuperArrowTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitMrsArrowCompTexInfo[] = {
    { 17, aSmallPortraitMrsArrowTex, TEX_WIDTH(aSmallPortraitMrsArrowTex), TEX_HEIGHT(aSmallPortraitMrsArrowTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitMrsArrowTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitZodaCompTexInfo[] = { { 17, aSmallPortraitZodaTex, TEX_WIDTH(aSmallPortraitZodaTex),
                                                          TEX_HEIGHT(aSmallPortraitZodaTex),
                                                          TEX_COMPRESSED_SIZE(aSmallPortraitZodaTex) },
                                                        { 0 } };
static unk_80077D50 sSmallPortraitJohnTanakaCompTexInfo[] = {
    { 17, aSmallPortraitJohnTanakaTex, TEX_WIDTH(aSmallPortraitJohnTanakaTex), TEX_HEIGHT(aSmallPortraitJohnTanakaTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitJohnTanakaTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitBioRexCompTexInfo[] = {
    { 17, aSmallPortraitBioRexTex, TEX_WIDTH(aSmallPortraitBioRexTex), TEX_HEIGHT(aSmallPortraitBioRexTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitBioRexTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitKateAlenCompTexInfo[] = {
    { 17, aSmallPortraitKateAlenTex, TEX_WIDTH(aSmallPortraitKateAlenTex), TEX_HEIGHT(aSmallPortraitKateAlenTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitKateAlenTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitGomarAndShiohCompTexInfo[] = {
    { 17, aSmallPortraitGomarAndShiohTex, TEX_WIDTH(aSmallPortraitGomarAndShiohTex),
      TEX_HEIGHT(aSmallPortraitGomarAndShiohTex), TEX_COMPRESSED_SIZE(aSmallPortraitGomarAndShiohTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitMichaelChainCompTexInfo[] = {
    { 17, aSmallPortraitMichaelChainTex, TEX_WIDTH(aSmallPortraitMichaelChainTex),
      TEX_HEIGHT(aSmallPortraitMichaelChainTex), TEX_COMPRESSED_SIZE(aSmallPortraitMichaelChainTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitBillyCompTexInfo[] = {
    { 17, aSmallPortraitBillyTex, TEX_WIDTH(aSmallPortraitBillyTex), TEX_HEIGHT(aSmallPortraitBillyTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitBillyTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitDrClashCompTexInfo[] = {
    { 17, aSmallPortraitDrClashTex, TEX_WIDTH(aSmallPortraitDrClashTex), TEX_HEIGHT(aSmallPortraitDrClashTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitDrClashTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitJackLevinCompTexInfo[] = {
    { 17, aSmallPortraitJackLevinTex, TEX_WIDTH(aSmallPortraitJackLevinTex), TEX_HEIGHT(aSmallPortraitJackLevinTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitJackLevinTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitBloodFalconCompTexInfo[] = {
    { 17, aSmallPortraitBloodFalconTex, TEX_WIDTH(aSmallPortraitBloodFalconTex),
      TEX_HEIGHT(aSmallPortraitBloodFalconTex), TEX_COMPRESSED_SIZE(aSmallPortraitBloodFalconTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitLeonCompTexInfo[] = { { 17, aSmallPortraitLeonTex, TEX_WIDTH(aSmallPortraitLeonTex),
                                                          TEX_HEIGHT(aSmallPortraitLeonTex),
                                                          TEX_COMPRESSED_SIZE(aSmallPortraitLeonTex) },
                                                        { 0 } };
static unk_80077D50 sSmallPortraitJamesMcCloudCompTexInfo[] = {
    { 17, aSmallPortraitJamesMcCloudTex, TEX_WIDTH(aSmallPortraitJamesMcCloudTex),
      TEX_HEIGHT(aSmallPortraitJamesMcCloudTex), TEX_COMPRESSED_SIZE(aSmallPortraitJamesMcCloudTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitBlackShadowCompTexInfo[] = {
    { 17, aSmallPortraitBlackShadowTex, TEX_WIDTH(aSmallPortraitBlackShadowTex),
      TEX_HEIGHT(aSmallPortraitBlackShadowTex), TEX_COMPRESSED_SIZE(aSmallPortraitBlackShadowTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitCaptainFalconAltCompTexInfo[] = {
    { 17, aSmallPortraitCaptainFalconAltTex, TEX_WIDTH(aSmallPortraitCaptainFalconAltTex),
      TEX_HEIGHT(aSmallPortraitCaptainFalconAltTex), TEX_COMPRESSED_SIZE(aSmallPortraitCaptainFalconAltTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitSamuraiGorohAltCompTexInfo[] = {
    { 17, aSmallPortraitSamuraiGorohAltTex, TEX_WIDTH(aSmallPortraitSamuraiGorohAltTex),
      TEX_HEIGHT(aSmallPortraitSamuraiGorohAltTex), TEX_COMPRESSED_SIZE(aSmallPortraitSamuraiGorohAltTex) },
    { 0 }
};
static unk_80077D50 sSmallPortraitJodySummerAltCompTexInfo[] = {
    { 17, aSmallPortraitJodySummerAltTex, TEX_WIDTH(aSmallPortraitJodySummerAltTex),
      TEX_HEIGHT(aSmallPortraitJodySummerAltTex), TEX_COMPRESSED_SIZE(aSmallPortraitJodySummerAltTex) },
    { 0 }
};

unk_800792D8 D_xk3_80136C50[] = { { sSmallPortraitDrStewartCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136C60[] = { { sSmallPortraitCaptainFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136C70[] = { { sSmallPortraitJodySummerCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136C80[] = { { sSmallPortraitSamuraiGorohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136C90[] = { { sSmallPortraitMightyGazelleCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CA0[] = { { sSmallPortraitPicoCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CB0[] = { { sSmallPortraitBabaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CC0[] = { { sSmallPortraitMrEadCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CD0[] = { { sSmallPortraitOctomanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CE0[] = { { sSmallPortraitTheSkullCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CF0[] = { { sSmallPortraitBeastmanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D00[] = { { sSmallPortraitAntonioGusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D10[] = { { sSmallPortraitDraqCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D20[] = { { sSmallPortraitRogerBusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D30[] = { { sSmallPortraitSilverNeelsenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D40[] = { { sSmallPortraitSuperArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D50[] = { { sSmallPortraitMrsArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D60[] = { { sSmallPortraitZodaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D70[] = { { sSmallPortraitJohnTanakaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D80[] = { { sSmallPortraitBioRexCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D90[] = { { sSmallPortraitKateAlenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DA0[] = { { sSmallPortraitGomarAndShiohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DB0[] = { { sSmallPortraitMichaelChainCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DC0[] = { { sSmallPortraitBillyCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DD0[] = { { sSmallPortraitDrClashCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DE0[] = { { sSmallPortraitJackLevinCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DF0[] = { { sSmallPortraitBloodFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E00[] = { { sSmallPortraitLeonCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E10[] = { { sSmallPortraitJamesMcCloudCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E20[] = { { sSmallPortraitBlackShadowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E30[] = { { sSmallPortraitCaptainFalconAltCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E40[] = { { sSmallPortraitSamuraiGorohAltCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E50[] = { { sSmallPortraitJodySummerAltCompTexInfo, 60 }, { 0 } };

unk_800792D8* D_xk3_80136E60[] = {
    D_xk3_80136C60, D_xk3_80136C50, D_xk3_80136CA0, D_xk3_80136C80, D_xk3_80136C70, D_xk3_80136C90,
    D_xk3_80136CC0, D_xk3_80136CB0, D_xk3_80136CD0, D_xk3_80136DA0, D_xk3_80136D90, D_xk3_80136D20,
    D_xk3_80136E10, D_xk3_80136E00, D_xk3_80136D00, D_xk3_80136E20, D_xk3_80136DB0, D_xk3_80136DE0,
    D_xk3_80136D40, D_xk3_80136D50, D_xk3_80136D70, D_xk3_80136CF0, D_xk3_80136D60, D_xk3_80136DD0,
    D_xk3_80136D30, D_xk3_80136D80, D_xk3_80136D10, D_xk3_80136DC0, D_xk3_80136CE0, D_xk3_80136DF0,
    D_xk3_80136E30, D_xk3_80136E30, D_xk3_80136E30, D_xk3_80136E40, D_xk3_80136E50, D_xk3_80136E30,
};

static unk_80077D50 sMachineSelectCursorCompTexInfo[] = {
    { 17, aMachineSelectCursorTex, TEX_WIDTH(aMachineSelectCursorTex), TEX_HEIGHT(aMachineSelectCursorTex),
      TEX_COMPRESSED_SIZE(aMachineSelectCursorTex) },
    { 0 }
};
static unk_80077D50 sBoostCompTexInfo[] = {
    { 17, aBoostTex, TEX_WIDTH(aBoostTex), TEX_HEIGHT(aBoostTex), TEX_COMPRESSED_SIZE(aBoostTex) }, { 0 }
};
static unk_80077D50 sBodyCompTexInfo[] = { { 17, aBodyTex, TEX_WIDTH(aBodyTex), TEX_HEIGHT(aBodyTex), 0x4E }, { 0 } };
static unk_80077D50 sGripCompTexInfo[] = {
    { 17, aGripTex, TEX_WIDTH(aGripTex), TEX_HEIGHT(aGripTex), TEX_COMPRESSED_SIZE(aGripTex) }, { 0 }
};

static unk_80077D50* sMachineStatCompTexInfos[] = {
    sBodyCompTexInfo,
    sBoostCompTexInfo,
    sGripCompTexInfo,
};

static const char* sMachineStatValueStr[] = { "a", "b", "c", "d", "e" };

u8 D_xk3_80136F90 = 0;

extern s16 gGreyscaleMachinePart;
extern u8 D_800333F4;
extern u8 D_xk1_800333F0;
extern s8 gSettingEverythingUnlocked;

void func_xk3_80132F50(void) {
    Camera_Init();
    gGreyscaleMachinePart = true;
    func_8071EB18();
    if (D_xk1_800333F0 != 0) {
        sMachineSelectIndex = D_800333F4;
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

    if (D_xk1_800333F0 != 0) {
        if (sMachineSelectIndex == 30) {
            if ((gInputPressed & BTN_DOWN) || (gInputPressed & BTN_LEFT)) {
                sMachineSelectIndex = D_800333F4;
                D_xk3_80136F90 = 0;
            }
        } else if ((gInputPressed & BTN_UP) || (gInputPressed & BTN_RIGHT)) {
            sMachineSelectIndex = 30;
        }
    } else if (sMachineSelectIndex == 30) {
        if (gInputPressed & BTN_UP) {
            sMachineSelectIndex = sMachinesUnlocked - 1;
            D_xk3_80136F90 = 0;
        } else if ((gInputPressed & BTN_DOWN) && (gInputPressed & BTN_LEFT)) {
            sMachineSelectIndex = 4;
            D_xk3_80136F90 = 0;
        } else if (gInputPressed & BTN_DOWN) {
            sMachineSelectIndex = 5;
            D_xk3_80136F90 = 0;
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
        D_xk3_80136F90 = 0;
        PRINTF("WORKS MACHINE MODE : 0\n");
        gWorksMachineMode = MACHINE_MODE_0;
        Audio_TriggerSystemSE(NA_SE_36);
        gCustomMachine = gCustomMachineBackup;
        D_xk1_800333F0 = D_xk3_80141290;
        D_800333F4 = D_xk3_80141291;
        func_xk3_8012D700();
    } else {
        gCustomMachinesInfoBackup = gCustomMachinesInfo;

        if (D_xk1_800333F0 != 0) {
            gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] = -1;
            func_8071E0C0();
        } else {
            gCustomMachineWork = gCustomMachine;

            for (i = 0; i < 30; i++) {
                if (gCustomMachinesInfo.characterCustomState[i] == 1) {
                    gCustomMachinesInfo.characterCustomState[i] = 0;
                    gCustomMachinesInfo.customMachines[i].number = 31;
                    func_8071E0C0();
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
        D_xk3_80136F90 = 1;
    }
}

void MachineCreate_MachineSelectHandleBPress(void) {

    if (sMachineSelectIndex < 30) {
        if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] == 0) {
            return;
        }

        gCustomMachinesInfoBackup = gCustomMachinesInfo;

        if (D_xk1_800333F0 == 0) {
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
        D_xk3_80136F90 = 1;
    } else if (sMachineSelectIndex == 30) {
        if (D_xk3_80136F90 == 0) {
            return;
        }
        if (D_xk3_80136F90 == 1) {
            D_xk3_80136F90 = 0;
            gCustomMachinesInfo = gCustomMachinesInfoBackup;
            if (D_xk1_800333F0 == 0) {
                gCustomMachine = gCustomMachineWork;
            }
            sMachineSelectIndex = sPreviousMachineSelectIndex;
        }
    }
    Audio_TriggerSystemSE(NA_SE_37);
    func_8071E0C0();
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
    func_800790D4();
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

void func_xk3_80133B4C(Object* arg0) {
    OBJECT_CACHE_INDEX(arg0) = func_800792D8(D_xk3_80136E60[0]);
    OBJECT_STATE(arg0) = -1;
}

void func_xk3_80133B84(void) {
    s32 i;

    for (i = BODY_STAT; i <= GRIP_STAT; i++) {
        func_80077D50_impl(sMachineStatCompTexInfos[i], 0, false);
    }
}

void func_xk3_80133BD4(Object* machineObj) {
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

void func_xk3_80133F40(void) {
    func_80077D50_impl(sMachineSelectCursorCompTexInfo, 0, false);
}

extern const char* gMachineNames[];
extern unk_800E3F28 D_800D63F8[];
extern const char* gSuperMachineNames[];

Gfx* func_xk3_80133F6C(Gfx* gfx, Object* arg1) {

    if (gWorksMachineMode != MACHINE_MODE_ENTRY) {
        return gfx;
    }
    if (sMachineSelectIndex < 30) {
        gfx = func_80078F80_impl(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(arg1)], OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 0, 0,
                                 0, 1.0f, 1.0f, false);
        if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] > 0) {
            gfx = Font_DrawString(gfx, 0x46, 0x25, gCustomMachinesInfo.customMachines[sMachineSelectIndex].machineName,
                                  0, 2, 0);
        } else if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] < 0) {
            gfx = Font_DrawString(gfx, 0x46, 0x25, gSuperMachineNames[sMachineSelectIndex], 0, 2, 0);
        } else {
            gfx = Font_DrawString(gfx, 0x46, 0x25, gMachineNames[Character_GetCharacterFromSlot(sMachineSelectIndex)],
                                  0, 2, 0);
        }
    }
    return gfx;
}

extern u8 kSuperMachineStatValues[][3];
extern Machine gMachines[];

Gfx* func_xk3_801340DC(Gfx* gfx, Object* arg1) {
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
            gfx = func_80078EA0_impl(gfx, sMachineStatCompTexInfos[i], 19, var_s6 + i * 20, 0, 0, 0, 1.0f, 1.0f, false);

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

Gfx* func_xk3_8013430C(Gfx* gfx, s32 characterSlot) {

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

Gfx* func_xk3_80134408(Gfx* gfx, Object* machineObj) {
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
            gfx = func_xk3_8013430C(gfx, i);
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
            gfx = func_8072DF40(gfx, Character_GetCharacterFromSlot(i), 0);
        }
    }

    return gfx;
}

extern u32 gGameFrameCount;

Gfx* func_xk3_80134854(Gfx* gfx, Object* arg1) {
    u16 temp_a3;
    s32 green;
    s32 blue;

    if (gWorksMachineMode != MACHINE_MODE_ENTRY) {
        return gfx;
    }
    if (sMachineSelectIndex < 30) {
        temp_a3 = gGameFrameCount % 30;
        green = 255;
        blue = 255;
        if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex] != 0) {
            green = 155;
            blue = 55;
        }
        if (temp_a3 >= 15) {
            gDPSetPrimColor(gfx++, 0, 0, 255, green, blue, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, green, blue, 255 - ((temp_a3 * 510) / 30));
        }
        OBJECT_LEFT(arg1) = ((sMachineSelectIndex % 6) * 0x28) + 0x28;
        OBJECT_TOP(arg1) = ((sMachineSelectIndex / 6) * 0x22) + 0x27;
        gfx = func_80078EA0_impl(gfx, sMachineSelectCursorCompTexInfo, OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 1, 0, 0,
                                 1.0f, 1.0f, false);
    }
    return gfx;
}

void func_xk3_80134A48(Object* portraitObj) {
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
        func_800793E8(OBJECT_CACHE_INDEX(portraitObj), 0, D_xk3_80136E60[character]);
    }
    OBJECT_STATE(portraitObj) = sMachineSelectIndex;
}

extern f32 D_8076E568;
extern f32 D_8076E56C;
extern f32 D_8076E570;

void func_xk3_80134B04(Object* machineObj) {
    Racer* racer;
    f32 var_fv0;
    s32 i;

    if (gWorksMachineMode != MACHINE_MODE_ENTRY) {
        return;
    }

    for (i = 1, racer = &gRacers[i]; racer >= gRacers; i--, racer--) {

        if (racer == gRacers) {
            var_fv0 = 0.03f;
        } else {
            var_fv0 = 0.0f;
        }
        racer->trueBasis.x.x += var_fv0 * racer->trueBasis.z.x;
        racer->trueBasis.x.y += var_fv0 * racer->trueBasis.z.y;
        racer->trueBasis.x.z += var_fv0 * racer->trueBasis.z.z;
        Math_OrthonormalizeAroundForward(&racer->trueBasis);
        Matrix_SetLockedLookAt(&gGfxPool->unk_20308[i], NULL, D_8076E568, D_8076E56C, D_8076E570, racer->trueBasis.x.x,
                               racer->trueBasis.x.y, racer->trueBasis.x.z, racer->trueBasis.y.x, racer->trueBasis.y.y,
                               racer->trueBasis.y.z, racer->segmentPositionInfo.pos.x, racer->segmentPositionInfo.pos.y,
                               racer->segmentPositionInfo.pos.z);
    }
}
