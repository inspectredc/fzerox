#include "global.h"
#include "fzx_course.h"
#include "fzx_expansion_kit.h"
#include "fzx_segmentA.h"
#include ASSET_HEADER_EK(expansion_kit_textures.h)
#include ASSET_HEADER_EK(course_edit_textures.h)
#include ASSET_HEADER_EK(overlays/expansion_kit/aA3AE0.h)
#include ASSET_HEADER_EK(overlays/machine_create/machine_create_assets.h)

extern s32 D_80119890;

extern u16 D_4001B00[];
extern u16 D_4001D40[];
extern u16 D_4001F80[];
extern u16 D_40021C0[];
extern u16 D_4002400[];
extern u16 D_4002640[];
extern u16 D_4002880[];
extern u16 D_4002AC0[];
extern u16 D_4002D00[];
extern u16 D_4002F40[];
extern u16 D_4003180[];
extern u16 D_40033C0[];
extern u16 D_4003600[];
extern u16 aCreateMachineBodyTex[];
extern u16 aCreateMachineLineTex[];
extern u16 aCreateMachineNumberTex[];
extern u16 aCreateMachineCockpitTex[];
extern u16 aCreateMachineMarkTex[];
extern u16 aCreateMachineColorTex[];
extern u16 D_4001500[];
extern u16 aCreateMachineUseTex[];
extern u16 aCreateMachineClearTex[];
extern u16 aCreateMachinePartsTex[];
extern u16 aCreateMachineDesignTex[];
extern u16 aCreateMachineSettingsTex[];

s32 D_xk1_8003A550;
s32 D_xk1_8003A554;

#include ASSET_SOURCE_EK(overlays/expansion_kit/aA3AE0/aA3AE0.c)

bool sShouldDrawMenuHighlight = true;
s32 gLastCourseBGM = -1;
bool gMenuWidgetOpen = false;
s32 D_xk1_800305FC = 0;
s32 sMenuHighlightAlpha = 0;
s32 D_xk1_80030604 = 8;
s32 D_xk1_80030608 = 500;
s32 sMenuPageYOffset = 0;
s32 gCourseEditFileOption = INVALID_OPTION;
s32 gCreateOption = 0;
UNUSED s32 D_xk1_80030618 = 0;
s32 gPointOption = 0;
s32 gMoveOption = 0;
s32 gDesignStyleOption = 0;
s32 gPartsStyleOption = 0;
s32 gRoadTypeOption = 0;
s32 gHRoadTypeOption = 0;
s32 gTRoadTypeOption = 0;
s32 gTunnelTypeOption = 0;
s32 gPipeTypeOption = 0;
s32 gHalfPipeTypeOption = 0;
s32 gCylinderTypeOption = 0;
s32 gPitTypeOption = 0;
s32 gDashTypeOption = 0;
s32 gDirtTypeOption = 0;
s32 gIceTypeOption = 0;
s32 gJumpTypeOption = 0;
s32 gLandmineTypeOption = 0;
s32 gGateTypeOption = 0;
s32 gBuildingTypeOption = 0;
s32 gSignTypeOption = 0;
s32 gVenueOption = 0;
s32 gSkyboxOption = 0;
s32 gBGMOption = 0;
s32 gCourseEditEntryOption = INVALID_OPTION;
s32* gCourseEditMenuOptions[] = {
    &gCreateOption, &gPointOption, NULL, &gCourseEditFileOption, &gCourseEditEntryOption,
};

MenuDropItem sPitTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditPitBothTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditPitLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditPitRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditPitMiddleTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditClearTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget sPitTypeWidget = { 5,   INVALID_OPTION, INVALID_OPTION, 120, 36, 0, 16, sPitTypeMenuItems, 160, 48, 160,
                              112, &gPitTypeOption };

MenuDropItem sDashTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditDashMiddleTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditDashLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditDashRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditClearTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget sDashTypeWidget = { 4,  INVALID_OPTION,  INVALID_OPTION, 120, 36, 0, 16, sDashTypeMenuItems, 160, 48, 160,
                               96, &gDashTypeOption };

MenuDropItem sDirtTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditDirtBothTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditDirtLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditDirtRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditDirtMiddleTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditClearTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget sDirtTypeWidget = { 5,   INVALID_OPTION,  INVALID_OPTION, 120, 36, 0, 16, sDirtTypeMenuItems, 160, 48, 160,
                               112, &gDirtTypeOption };

MenuDropItem sIceTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditIceBothTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditIceLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditIceRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditIceMiddleTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditClearTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget sIceTypeWidget = { 5,   INVALID_OPTION, INVALID_OPTION, 120, 36, 0, 16, sIceTypeMenuItems, 160, 48, 160,
                              112, &gIceTypeOption };

MenuDropItem sJumpTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditJumpAllTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditJumpLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditJumpRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditClearTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget sJumpTypeWidget = { 4,  INVALID_OPTION,  INVALID_OPTION, 120, 36, 0, 16, sJumpTypeMenuItems, 160, 48, 160,
                               96, &gJumpTypeOption };

MenuDropItem sLandmineTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditLandmineMiddleTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditLandmineLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditLandmineRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditClearTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget sLandmineTypeWidget = {
    4, INVALID_OPTION, INVALID_OPTION, 120, 36, 0, 16, sLandmineTypeMenuItems, 160, 48, 160, 96, &gLandmineTypeOption
};

MenuDropItem sGateTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditGateSquareTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditGateStartTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditGateHexagonalTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditClearTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget sGateTypeWidget = { 4,  INVALID_OPTION,  INVALID_OPTION, 120, 36, 0, 16, sGateTypeMenuItems, 160, 48, 160,
                               96, &gGateTypeOption };

MenuDropItem sBuildingTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditBuildingTallBothTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditBuildingTallLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditBuildingTallRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditBuildingShortBothTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu5Tex, aCourseEditBuildingShortLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu6Tex, aCourseEditBuildingShortRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu7Tex, aCourseEditBuildingSpireBothTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu8Tex, aCourseEditBuildingSpireLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu9Tex, aCourseEditBuildingSpireRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu10Tex, aCourseEditBuildingMountainBothTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu11Tex, aCourseEditBuildingMountainLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu12Tex, aCourseEditBuildingMountainRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu13Tex, aCourseEditBuildingTallGoldBothTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu14Tex, aCourseEditBuildingTallGoldLeftTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu15Tex, aCourseEditBuildingTallGoldRightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditClearTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget sBuildingTypeWidget = {
    16, INVALID_OPTION, INVALID_OPTION, 120, 36, 0, 16, sBuildingTypeMenuItems, 160, 48, 160, 288, &gBuildingTypeOption
};

MenuDropItem sSignTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditSignTVTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditSign1Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditSign2Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditSignNintexTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu5Tex, aCourseEditSignOverheadTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditClearTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget sSignTypeWidget = { 6,   INVALID_OPTION,  INVALID_OPTION, 120, 36, 0, 16, sSignTypeMenuItems, 160, 48, 160,
                               128, &gSignTypeOption };

MenuDropItem sVenueMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditMuteCitySceneTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditPortTownSceneTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditBigBlueSceneTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditSandOceanSceneTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu5Tex, aCourseEditDevilsForestSceneTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu6Tex, aCourseEditWhiteLandSceneTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu7Tex, aCourseEditSectorSceneTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu8Tex, aCourseEditRedCanyonSceneTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu9Tex, aCourseEditFireFieldSceneTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu10Tex, aCourseEditSilenceSceneTex, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget gVenueWidget = { 10,  INVALID_OPTION, INVALID_OPTION, 72, 36, 0, 16, sVenueMenuItems, 112, 48, 112,
                            192, &gVenueOption };

MenuDropItem sSkyboxMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditSkyboxPurpleTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditSkyboxTurquoiseTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditSkyboxDesertTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditSkyboxBlueTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu5Tex, aCourseEditSkyboxNightTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu6Tex, aCourseEditSkyboxOrangeTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu7Tex, aCourseEditSkyboxSunsetTex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu8Tex, aCourseEditSkyboxSkyBlueTex, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget gSkyboxWidget = { 8,   INVALID_OPTION, INVALID_OPTION, 120, 36, 0, 16, sSkyboxMenuItems, 160, 48, 160,
                             160, &gSkyboxOption };

MenuDropItem sBGMMenuItems[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu1Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu2Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu3Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu4Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu5Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu6Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu7Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu8Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu9Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu10Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu11Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu12Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu13Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL,
      NULL, NULL, 48, 16, NULL, aExpansionKitMenu14Tex },
};

MenuWidget gBGMWidget = { 14,  INVALID_OPTION, INVALID_OPTION, 72, 36, 0, 16, sBGMMenuItems, 112, 48, 112,
                          256, &gBGMOption };

MenuDropItem gTunnelTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditTunnelType1Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditTunnelType2Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditTunnelType3Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditTunnelType4Tex, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget gTunnelTypeWidget = {
    4, INVALID_OPTION, INVALID_OPTION, 120, 36, 0, 16, gTunnelTypeMenuItems, 160, 48, 160, 96, &gTunnelTypeOption
};

MenuDropItem gPipeTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditPipeType1Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditPipeType2Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditPipeType3Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditPipeType4Tex, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget gPipeTypeWidget = { 4,  INVALID_OPTION,  INVALID_OPTION, 120, 36, 0, 16, gPipeTypeMenuItems, 160, 48, 160,
                               96, &gPipeTypeOption };

MenuDropItem gHalfPipeTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditHalfPipeType1Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditHalfPipeType2Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditHalfPipeType3Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditHalfPipeType4Tex, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget gHalfPipeTypeWidget = {
    4, INVALID_OPTION, INVALID_OPTION, 120, 36, 0, 16, gHalfPipeTypeMenuItems, 160, 48, 160, 96, &gHalfPipeTypeOption
};

MenuDropItem gCylinderTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, aCourseEditCylinderType1Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditCylinderType2Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditCylinderType3Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, aCourseEditCylinderType4Tex, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget gCylinderTypeWidget = {
    4, INVALID_OPTION, INVALID_OPTION, 120, 36, 0, 16, gCylinderTypeMenuItems, 160, 48, 160, 96, &gCylinderTypeOption
};

MenuDropItem sCourseEditEntryMenuItems[] = {
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex,
      aExpansionKitMenuAcceptTex, NULL, NULL, func_xk1_80026870, 48, 16, NULL, NULL },
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex,
      aExpansionKitMenuClearTex, NULL, NULL, func_xk1_800268A8, 48, 16, NULL, NULL },
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex,
      aExpansionKitMenuClearAllTex, NULL, NULL, func_xk1_800268E4, 48, 16, NULL, NULL },
};

MenuWidget gCourseEditEntryWidget = {
    3,  INVALID_OPTION,         INVALID_OPTION, 216, 36, 0, 16, sCourseEditEntryMenuItems, 256, 48, 256,
    80, &gCourseEditEntryOption
};

s32 gMachineDesignOption = INVALID_OPTION;
s32 gDecalOption = INVALID_OPTION;
s32 gLogoOption = INVALID_OPTION;
s32 gColorOption = INVALID_OPTION;
s32 gMachineRegistrationOption = INVALID_OPTION;
s32 gMachineCreateEntryOption = INVALID_OPTION;

MenuDropItem sDecalMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, D_4001B00, NULL, func_xk3_8013298C, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, D_4001D40, NULL, func_xk3_801329A4, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, D_4001F80, NULL, func_xk3_801329BC, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, D_40021C0, NULL, func_xk3_801329D4, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu5Tex, D_4002400, NULL, func_xk3_801329EC, 16, 16, NULL, NULL },
};

MenuWidget sDecalWidget = { 5,   INVALID_OPTION, INVALID_OPTION, 72, 52, 0, 16, sDecalMenuItems, 104, 56, 104,
                            120, &gDecalOption };

MenuDropItem sLogoMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, D_4002640, NULL, func_xk3_80132A80, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, D_4002880, NULL, func_xk3_80132A98, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, D_4002AC0, NULL, func_xk3_80132AB0, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, D_4002D00, NULL, func_xk3_80132AC8, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu5Tex, D_4002F40, NULL, func_xk3_80132AE0, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu6Tex, D_4003180, NULL, func_xk3_80132AF8, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu7Tex, D_40033C0, NULL, func_xk3_80132B10, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu8Tex, D_4003600, NULL, func_xk3_80132B28, 16, 16, NULL, NULL },
};

MenuWidget sLogoWidget = { 8,   INVALID_OPTION, INVALID_OPTION, 72, 52, 0, 16, sLogoMenuItems, 104, 56, 104,
                           168, &gLogoOption };

MenuDropItem sColorMenuItems[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCreateMachineBodyTex, NULL, NULL, func_xk3_80132B40, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCreateMachineLineTex, NULL, NULL, func_xk3_80132BB0, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCreateMachineNumberTex, NULL, NULL, func_xk3_80132C20, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCreateMachineCockpitTex, NULL, NULL, func_xk3_80132C90, 48, 16, NULL, NULL },
};

MenuWidget sColorWidget = { 4,   INVALID_OPTION, INVALID_OPTION, 72, 52, 0, 16, sColorMenuItems, 104, 56, 104,
                            104, &gColorOption };

MenuDropItem sMachineDesignMenuItems[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCreateMachineLineTex, NULL, &sDecalWidget, func_xk3_80132910, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCreateMachineMarkTex, NULL, &sLogoWidget, func_xk3_80132A04, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, aCreateMachineColorTex, NULL,
      &sColorWidget, func_xk3_801326F0, 48, 16, NULL, NULL },
};

MenuWidget sMachineDesignWidget = {
    3, INVALID_OPTION, INVALID_OPTION, 72, 36, 0, 16, sMachineDesignMenuItems, 104, 48, 104, 80, &gMachineDesignOption
};

MenuDropItem sMachineRegistrationMenuItems[] = {
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_4001500, NULL,
      NULL, func_xk3_80132828, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_xk3_80138B30, NULL,
      NULL, func_xk3_80132DDC, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_xk3_80138CB0, NULL,
      NULL, func_xk3_80132850, 48, 16, NULL, NULL },
};

MenuWidget sMachineRegistrationWidget = { 3,
                                          INVALID_OPTION,
                                          INVALID_OPTION,
                                          168,
                                          36,
                                          0,
                                          16,
                                          sMachineRegistrationMenuItems,
                                          200,
                                          48,
                                          200,
                                          80,
                                          &gMachineRegistrationOption };

MenuDropItem sMachineCreateEntryMenuItems[] = {
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex,
      aCreateMachineUseTex, NULL, NULL, func_xk3_8013277C, 48, 16, NULL, NULL },
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex,
      aCreateMachineClearTex, NULL, NULL, func_xk3_801327A4, 48, 16, NULL, NULL },
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex,
      aExpansionKitMenuClearAllTex, NULL, NULL, func_xk3_80132808, 48, 16, NULL, NULL },
};

MenuWidget sMachineCreateEntryWidget = { 3,
                                         INVALID_OPTION,
                                         INVALID_OPTION,
                                         216,
                                         36,
                                         0,
                                         16,
                                         sMachineCreateEntryMenuItems,
                                         248,
                                         48,
                                         248,
                                         80,
                                         &gMachineCreateEntryOption };

MenuDropItem gMachineCreateMenuItems[] = {
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, aCreateMachinePartsTex, NULL, NULL,
      func_xk3_80132884, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, aCreateMachineDesignTex, NULL,
      &sMachineDesignWidget, func_xk3_801326D8, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, aCreateMachineSettingsTex, NULL, NULL,
      func_xk3_80132E84, 48, 16, NULL, NULL },
    { aMachineCreateMachineRegistrationTex, aMachineCreateMachineRegistrationTex, NULL, NULL,
      &sMachineRegistrationWidget, func_xk3_801326C0, 48, 16, NULL, NULL },
    { aExpansionKitMenuEntryTex, aExpansionKitMenuEntryTex, NULL, NULL, &sMachineCreateEntryWidget, func_xk3_80132764,
      48, 16, NULL, NULL },
};

MenuWidget gMachineCreateWidget = { 5, INVALID_OPTION, INVALID_OPTION, 24,  20, 48, 0, gMachineCreateMenuItems, 0,
                                    0, SCREEN_WIDTH,   SCREEN_HEIGHT,  NULL };

MenuDropItem gRoadTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, D_A00B000, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, D_A00B240, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, D_A00B480, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu4Tex, D_A00B6C0, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu5Tex, D_A00B900, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget gRoadTypeWidget = { 5,   INVALID_OPTION,  INVALID_OPTION, 120, 36, 0, 16, gRoadTypeMenuItems, 160, 48, 160,
                               112, &gRoadTypeOption };

MenuDropItem gHRoadTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, D_A00BB40, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditHRoadType2Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditHRoadType3Tex, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget gHRoadTypeWidget = { 3,  INVALID_OPTION,   INVALID_OPTION, 120, 36, 0, 16, gHRoadTypeMenuItems, 160, 48, 160,
                                80, &gHRoadTypeOption };

MenuDropItem gTRoadTypeMenuItems[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu1Tex, D_A00BD80, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu2Tex, aCourseEditTRoadType2Tex, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex,
      aExpansionKitMenu3Tex, aCourseEditTRoadType3Tex, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget gTRoadTypeWidget = { 3,  INVALID_OPTION,   INVALID_OPTION, 120, 36, 0, 16, gTRoadTypeMenuItems, 160, 48, 160,
                                80, &gTRoadTypeOption };

MenuDropItem sCourseEditFileMenuItems[] = {
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, aCourseEditLoadTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, aCourseEditSaveTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, aCourseEditRenameTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex,
      aCourseEditEraseFileTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex,
      aExpansionKitMenuCopyTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget gCourseEditFileWidget = {
    5,   INVALID_OPTION,        INVALID_OPTION, 168, 36, 0, 16, sCourseEditFileMenuItems, 208, 48, 208,
    112, &gCourseEditFileOption
};

MenuDropItem sCreateMenuItems[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditCourseTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditPointTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditDesignTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditPartsTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCourseEditBackgroundTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_800302F0, NULL,
      NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget gCreateWidget = { 6,   INVALID_OPTION, INVALID_OPTION, 24, 36, 0, 16, sCreateMenuItems, 64, 48, 64,
                             128, &gCreateOption };

MenuDropItem sPointMenuItems[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditSetTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCourseEditMoveStartTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCourseEditCenteringTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aExpansionKitReverseTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aExpansionKitMenuClearAllTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget gPointWidget = { 5,   INVALID_OPTION, INVALID_OPTION, 72, 36, 0, 16, sPointMenuItems, 112, 48, 112,
                            112, &gPointOption };

MenuDropItem sMoveMenuItems[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCourseEditMoveXZIconTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCourseEditMoveYIconTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditWidthTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditBankTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditCenterTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditClearTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCourseEditStraightTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget gMoveWidget = { 7,   INVALID_OPTION, INVALID_OPTION, 72, 36, 0, 16, sMoveMenuItems, 112, 48, 112,
                           144, &gMoveOption };

MenuDropItem sDesignStyleMenuItems[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditRoadTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditHRoadTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditTRoadTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditTunnelTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditPipeTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCourseEditHalfpipeTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCourseEditCylinderTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditSpaceTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditLoopTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget gDesignStyleWidget = {
    9, INVALID_OPTION, INVALID_OPTION, 72, 36, 0, 16, sDesignStyleMenuItems, 112, 48, 112, 176, &gDesignStyleOption
};

MenuDropItem sPartsStyleMenuItems[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditPitTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditDashTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditDirtTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditSlipTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditJumpTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditTrapTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditGateTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
      aCourseEditBuildingTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditSignTex,
      NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget gPartsStyleWidget = {
    9, INVALID_OPTION, INVALID_OPTION, 72, 36, 0, 16, sPartsStyleMenuItems, 112, 48, 112, 176, &gPartsStyleOption
};

MenuDropItem gCourseEditMenuItems[] = {
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, aCourseEditCreateTex, NULL,
      &gCreateWidget, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, aCourseEditPointBoldTex, NULL,
      &gPointWidget, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, NULL, NULL, NULL, NULL, 48, 16, NULL,
      NULL },
    { aCourseEditFileTex, aCourseEditFileTex, NULL, NULL, &gCourseEditFileWidget, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuEntryTex, aExpansionKitMenuEntryTex, NULL, NULL, &gCourseEditEntryWidget, NULL, 48, 16, NULL,
      NULL },
    { NULL, NULL, NULL, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget gCourseEditWidget = { 6, INVALID_OPTION, INVALID_OPTION, 24,  20, 48, 0, gCourseEditMenuItems, 0,
                                 0, SCREEN_WIDTH,   SCREEN_HEIGHT,  NULL };

s32 gBGMOptionToCourseBGM[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 11, 10, 13 };

void func_xk1_80026870(void) {

    // TODO: move to appropriate place
    PRINTF("DEBUG\n");
    PRINTF("EDIT_MODE_COURSE **\n");
    PRINTF("VIRTUAL SCROLL %d\n");
    PRINTF("x,y %d, %d\n");

    D_80119890 = 0;
    func_xk2_800EB9E0();
    D_xk1_8003A550 = 0x110;
    D_xk1_8003A554 = 0x38;
}

void func_xk1_800268A8(void) {
    D_80119890 = 1;
    func_xk2_800EB9E0();
    D_xk1_8003A550 = 0x110;
    D_xk1_8003A554 = 0x38;
}

extern unk_800D6CA0 D_800D6CA0;
extern s32 D_xk1_80032C20;

void func_xk1_800268E4(void) {
    D_80119890 = 2;
    D_xk1_80032C20 = 0;
    D_800D6CA0.unk_08 = 0x23;
}

void ExpansionKit_SetMenuHighlightDrawFlag(bool shouldHighlight) {
    sShouldDrawMenuHighlight = shouldHighlight;
}

MenuWidget* func_xk1_80026914(MenuWidget* rootWidget) {
    MenuWidget* widget = rootWidget;

    while (true) {
        if (widget->openIndex == INVALID_OPTION) {
            break;
        }
        if (widget->menuItems[widget->openIndex].widget == NULL) {
            break;
        }
        widget = widget->menuItems[widget->openIndex].widget;
    }

    return widget;
}

s32 func_xk1_80026958(MenuWidget* widget, s32 cursorPosX, s32 cursorPosY) {
    s32 i;
    s32 index;

    index = INVALID_OPTION;
    for (i = 0; i < widget->numItems; i++) {
        if ((cursorPosX >= (widget->left + widget->itemXOffset * i)) &&
            (cursorPosX < ((widget->left + widget->itemXOffset * i) + 0x30))) {
            if (((cursorPosY + sMenuPageYOffset) >= (widget->top + (widget->itemYOffset * i))) &&
                ((cursorPosY + sMenuPageYOffset) < ((widget->top + (widget->itemYOffset * i)) + 0x10))) {
                index = i;
            }
        }
    }
    return index;
}

void func_xk1_800269F4(MenuWidget* widget, s32* cursorPosXPtr, s32* cursorPosYPtr) {
    s32 cursorPosX;
    s32 cursorPosY;

    while (true) {
        if (widget->openIndex == INVALID_OPTION) {
            break;
        }
        if (widget->menuItems[widget->openIndex].widget == NULL) {
            break;
        }
        widget = widget->menuItems[widget->openIndex].widget;
    }

    cursorPosX = *cursorPosXPtr;
    cursorPosY = *cursorPosYPtr;
    if (cursorPosX < widget->cursorMinPosX) {
        cursorPosX = widget->cursorMinPosX;
    }

    if (cursorPosX > widget->cursorMaxPosX) {
        cursorPosX = widget->cursorMaxPosX;
    }

    if (cursorPosY > widget->cursorMaxPosY) {
        cursorPosY = widget->cursorMaxPosY;
    }

    if (widget->numItems < 10) {
        if (cursorPosY < widget->cursorMinPosY) {
            cursorPosY = widget->cursorMinPosY;
        }
        *cursorPosXPtr = cursorPosX;
        *cursorPosYPtr = cursorPosY;
    } else {
        if ((widget->top + 160) < cursorPosY) {
            sMenuPageYOffset = ((sMenuPageYOffset + 16) / 16) * 16;
            cursorPosY = widget->top + 156;
        }

        if (widget->cursorMaxPosY < (cursorPosY + sMenuPageYOffset)) {
            sMenuPageYOffset = widget->cursorMaxPosY - cursorPosY;
        }

        if (cursorPosY < widget->top) {
            sMenuPageYOffset -= 16;
            cursorPosY = widget->cursorMinPosY;
        }
        if (sMenuPageYOffset < 0) {
            sMenuPageYOffset = 0;
        }
        *cursorPosXPtr = cursorPosX;
        *cursorPosYPtr = cursorPosY;
    }
}

void func_xk1_80026B44(Gfx** gfxP, MenuWidget* widget, s32 cursorPosX, s32 cursorPosY) {
    s32 temp_ra;
    s32 temp_s0;
    s32 highlightedIndex;
    MenuDropItem* menuItem;
    s32 width;
    s32 height;
    Gfx* gfx;
    s32 i;

    gfx = *gfxP;

    highlightedIndex = func_xk1_80026958(widget, cursorPosX, cursorPosY);

    for (i = 0; i < widget->numItems; i++) {
        menuItem = &widget->menuItems[i];

        temp_ra = widget->left + (i * widget->itemXOffset);
        temp_s0 = (widget->top + (i * widget->itemYOffset)) - (sMenuPageYOffset * (widget->itemXOffset == 0));

        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        if (i == highlightedIndex) {
            if (menuItem->backgroundSelectedTex != NULL) {
                gDPLoadTextureBlock(gfx++, menuItem->backgroundSelectedTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);

                gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + 48) << 2, (temp_s0 + 16) << 2, 0, 0,
                                    0, 1 << 10, 1 << 10);
            }
        } else {
            if (((widget == &gCourseEditWidget) || (widget == &gMachineCreateWidget)) && (i != highlightedIndex)) {
                gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0,
                                  PRIMITIVE, 0, TEXEL0, 0);
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
            if ((widget == &sMachineDesignWidget) && (highlightedIndex != 2) && (i == 2)) {
                gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0,
                                  PRIMITIVE, 0, TEXEL0, 0);
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
            if (menuItem->backgroundTex != NULL) {
                gDPLoadTextureBlock(gfx++, menuItem->backgroundTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);

                gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + 48) << 2, (temp_s0 + 16) << 2, 0, 0,
                                    0, 1 << 10, 1 << 10);
            }
        }
        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        if (widget->menuItems[i].subContentsRGBATex != NULL) {
            gDPLoadTextureBlock(gfx++, menuItem->subContentsRGBATex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (temp_ra + 19) << 2, (temp_s0 + 2) << 2, (temp_ra + 45) << 2,
                                (temp_s0 + 14) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
        if (widget->menuItems[i].contentsTex != NULL) {
            width = menuItem->contentsWidth;
            height = menuItem->contentsHeight;
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

            gDPLoadTextureBlock_4b(gfx++, menuItem->contentsTex, G_IM_FMT_I, width, height, 0,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                   G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + width) << 2, (temp_s0 + height) << 2, 0,
                                0, 0, 1 << 10, 1 << 10);
        }
        if (widget->menuItems[i].subContentsI4Tex != NULL) {
            width = 16;
            height = 16;
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

            gDPLoadTextureBlock_4b(gfx++, menuItem->subContentsI4Tex, G_IM_FMT_I, width, height, 0,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                   G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (temp_ra + 28) << 2, temp_s0 << 2, (temp_ra + 44) << 2, (temp_s0 + 16) << 2, 0,
                                0, 0, 1 << 10, 1 << 10);
        }
        if ((i == highlightedIndex) && (D_800D6CA0.unk_08 != 3) &&
            !((widget == &gCourseEditWidget) && (highlightedIndex == 5))) {
            gDPPipeSync(gfx++);
            gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0,
                              PRIMITIVE, 0, TEXEL0, 0);

            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, sMenuHighlightAlpha);

            gDPLoadTextureBlock(gfx++, aExpansionKitMenuHighlightTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            if (sShouldDrawMenuHighlight) {
                gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + 48) << 2, (temp_s0 + 16) << 2, 0, 0,
                                    0, 1 << 10, 1 << 10);
            }
        }
    }
    *gfxP = gfx;
}

extern u32 gGameFrameCount;

void func_xk1_800276B0(Gfx** gfxP, MenuWidget* widget, s32 cursorPosX, s32 cursorPosY) {
    Gfx* gfx;

    gfx = *gfxP;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    sMenuHighlightAlpha += D_xk1_80030604 * func_xk1_80025C0C();

    if (sMenuHighlightAlpha > 255) {
        sMenuHighlightAlpha = 255;
        D_xk1_80030604 = -4;
    }
    if (sMenuHighlightAlpha < 100) {
        // clang-format off
        sMenuHighlightAlpha = 100; \
        D_xk1_80030604 = 4;
        // clang-format on
    }
    func_xk1_80026B44(&gfx, widget, cursorPosX, cursorPosY);

    while (true) {
        if (widget->itemXOffset != 0) {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
        } else {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, widget->left, widget->top, widget->left + 48,
                          widget->top + (widget->itemYOffset * 9) + 16);
        }

        if (widget->openIndex == INVALID_OPTION) {
            break;
        }
        if (widget->menuItems[widget->openIndex].widget == NULL) {
            break;
        }
        widget = widget->menuItems[widget->openIndex].widget;
    }

    func_xk1_80026B44(&gfx, widget, cursorPosX, cursorPosY);

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);

    if ((widget->numItems > 10) && (sMenuPageYOffset < ((widget->numItems - 10) * widget->itemYOffset))) {
        if ((gGameFrameCount % 4) >= 2) {
            gDPPipeSync(gfx++);
            gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPLoadTextureBlock(gfx++, aExpansionKitScrollArrowIndicatorTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (widget->left + 8) << 2, (widget->top + (widget->itemYOffset * 10)) << 2,
                                (widget->left + 40) << 2, ((widget->top + (widget->itemYOffset * 10)) + 16) << 2, 0, 0,
                                0, 1 << 10, 1 << 10);
        }
    }
    *gfxP = gfx;
}

void func_xk1_80027B74(MenuWidget* arg0) {
    s32 temp_v0;

    if (!gMenuWidgetOpen) {
        return;
    }
    while (true) {
        temp_v0 = arg0->openIndex;
        if (temp_v0 == INVALID_OPTION) {
            break;
        }
        arg0->openIndex = INVALID_OPTION;
        if (arg0->menuItems[temp_v0].widget == NULL) {
            break;
        }
        arg0 = arg0->menuItems[temp_v0].widget;
    }
    if (arg0 != &gBGMWidget) {
        Audio_TriggerSystemSE(NA_SE_37);
    }
    gCourseEditFileOption = INVALID_OPTION;
    gCourseEditEntryOption = INVALID_OPTION;
    arg0->highlightedIndex = INVALID_OPTION;
    gMenuWidgetOpen = false;
    sMenuPageYOffset = 0;
}

void func_xk1_80027C1C(MenuWidget* widget) {
    s32 temp_v0;

    if (!gMenuWidgetOpen) {
        return;
    }
    while (true) {
        temp_v0 = widget->openIndex;
        if (temp_v0 == INVALID_OPTION) {
            break;
        }
        widget->openIndex = INVALID_OPTION;
        if (widget->menuItems[temp_v0].widget == NULL) {
            break;
        }
        widget = widget->menuItems[temp_v0].widget;
    }

    widget->highlightedIndex = INVALID_OPTION;
    gMenuWidgetOpen = false;
    sMenuPageYOffset = 0;
}

void func_xk1_80027C80(MenuWidget* widget) {
    s32 temp_v0;

    if (D_800D6CA0.unk_08 != 1 || !gMenuWidgetOpen) {
        return;
    }
    while (true) {
        temp_v0 = widget->openIndex;
        if (temp_v0 == INVALID_OPTION) {
            break;
        }
        widget->openIndex = INVALID_OPTION;
        if (widget->menuItems[temp_v0].widget == NULL) {
            break;
        }
        widget = widget->menuItems[temp_v0].widget;
    }

    widget->highlightedIndex = INVALID_OPTION;
    gMenuWidgetOpen = false;
    sMenuPageYOffset = 0;
    D_800D6CA0.unk_08 = 0;
}

extern s32 D_xk2_800F7048;

void func_xk1_80027CFC(MenuWidget* rootWidget, s32* cursorPosXPtr, s32* cursorPosYPtr) {
    s32 pad;
    MenuWidget* widget = rootWidget;
    s32 pad2;
    s32 var_a1;

    if (D_xk2_800F7048 == 1) {
        return;
    }

    while (true) {
        if (widget->openIndex == INVALID_OPTION) {
            break;
        }
        if (widget->menuItems[widget->openIndex].widget == NULL) {
            break;
        }
        widget = widget->menuItems[widget->openIndex].widget;
    }

    var_a1 = func_xk1_80026958(widget, *cursorPosXPtr, *cursorPosYPtr);

    if ((var_a1 != widget->highlightedIndex) && (widget->highlightedIndex != INVALID_OPTION) &&
        (widget != &gBGMWidget)) {
        Audio_TriggerSystemSE(NA_SE_35);
    }
    widget->highlightedIndex = var_a1;
}

void func_xk1_80027DC8(MenuWidget* rootWidget, s32* cursorPosXPtr, s32* cursorPosYPtr) {
    s32 pad;
    MenuWidget* widget;
    MenuWidget* selectedWidget;
    s32 selectedIndex;

    widget = rootWidget;
    while (true) {
        if (widget->openIndex == INVALID_OPTION) {
            break;
        }
        if (widget->menuItems[widget->openIndex].widget == NULL) {
            break;
        }
        widget = widget->menuItems[widget->openIndex].widget;
    }

    selectedIndex = func_xk1_80026958(widget, *cursorPosXPtr, *cursorPosYPtr);
    if (selectedIndex != INVALID_OPTION) {
        if (!((widget == &gCourseEditWidget) && (selectedIndex == 2) &&
              (gCourseEditWidget.menuItems[2].widget == NULL)) &&
            !((widget == &gCourseEditWidget) && (selectedIndex == 5)) &&
            !((widget == &gCourseEditWidget) && (selectedIndex == 5)) && (widget != &gBGMWidget)) {
            Audio_TriggerSystemSE(NA_SE_36);
        }
        if (widget != &gBGMWidget) {
            sMenuPageYOffset = 0;
        }

        widget->openIndex = selectedIndex;
        widget->highlightedIndex = INVALID_OPTION;
        if (widget->option != NULL) {
            *widget->option = selectedIndex;
        }

        selectedWidget = widget->menuItems[selectedIndex].widget;
        if (selectedWidget != NULL) {
            gMenuWidgetOpen = true;
        }
        if (selectedWidget != NULL) {
            if (widget->menuItems[selectedIndex].action != NULL) {
                widget->menuItems[selectedIndex].action();
            }

            if (selectedWidget->option != NULL) {
                if (*selectedWidget->option == INVALID_OPTION) {
                    D_xk1_800305FC = 0;
                    *cursorPosXPtr = selectedWidget->cursorMinPosX;
                    *cursorPosYPtr = selectedWidget->cursorMinPosY;
                } else {
                    D_xk1_800305FC = *selectedWidget->option;
                    if ((*selectedWidget->option + 1) > 10) {
                        sMenuPageYOffset = (*selectedWidget->option - 9) * selectedWidget->itemYOffset;
                    }
                    *cursorPosXPtr =
                        (*selectedWidget->option * selectedWidget->itemXOffset) + selectedWidget->cursorMinPosX;
                    *cursorPosYPtr =
                        ((*selectedWidget->option * selectedWidget->itemYOffset) + selectedWidget->cursorMinPosY) -
                        sMenuPageYOffset;
                }
            } else {
                *cursorPosXPtr = selectedWidget->cursorMinPosX;
                *cursorPosYPtr = selectedWidget->cursorMinPosY;
            }
        } else {
            if (widget->menuItems[selectedIndex].action != NULL) {
                func_xk1_80027C1C(rootWidget);
                widget->menuItems[selectedIndex].action();
            }
        }
    }
}

extern s32 D_80119880;
extern u8 D_xk2_800F7400;
extern s32 D_xk2_80104378;
extern unk_807B3C20 D_802CB6D0;
extern s32 D_xk1_80032BF8;
extern CourseInfo* gCurrentCourseInfo;

void func_xk1_80028064(void) {
    if (gCourseEditFileWidget.openIndex == INVALID_OPTION) {
        return;
    }

    func_xk1_80027C80(&gCourseEditWidget);
    D_xk2_800F7400 = 1;
    switch (gCourseEditFileOption) {
        case FILE_OPTION_LOAD:
            func_8076877C(1, "CRSD");
            PRINTF("LESS POINT\n");
            D_80119880 = 0;
            D_800D6CA0.unk_08 = 50;
            break;
        case FILE_OPTION_SAVE:
            D_80119880 = 1;
            func_xk2_800F27DC(gCurrentCourseInfo);
            if (D_802CB6D0.controlPointCount < 4) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 16;
                D_xk2_80104378 = 9;
                D_80119880 = -2;
            } else {
                D_xk1_80032BF8 = 0;
                func_8076877C(1, "CRSD");
                PRINTF("NAME\n");
                D_800D6CA0.unk_08 = 50;
            }
            break;
        case FILE_OPTION_RENAME:
            D_xk1_80032BF8 = 0;
            func_8076877C(0, "CRSD");
            PRINTF("DELETE\n");
            D_80119880 = 3;
            D_800D6CA0.unk_08 = 50;
            break;
        case FILE_OPTION_ERASE:
            D_xk1_80032BF8 = 0;
            func_8076877C(0, "CRSD");
            D_80119880 = 2;
            D_800D6CA0.unk_08 = 50;
            break;
        case FILE_OPTION_COPY:
            D_xk1_80032BF8 = 0;
            func_8076877C(0, "CRSD");
            PRINTF("BGM NO. SET %d\n");
            D_80119880 = 7;
            D_800D6CA0.unk_08 = 50;
            break;
    }
}

void func_xk1_8002820C(void) {
    gCreateOption = CREATE_OPTION_COURSE;
    gCourseEditMenuItems[1].contentsTex = aCourseEditPointBoldTex;
    gCourseEditMenuItems[1].widget = &gPointWidget;
    gCourseEditMenuOptions[1] = &gPointOption;
    gCourseEditMenuItems[2].contentsTex = NULL;
    gCourseEditMenuItems[2].widget = NULL;
}

void func_xk1_80028250(void) {
    MenuWidget* sCourseDesignTypeWidgets[] = {
        &gRoadTypeWidget,
        &gHRoadTypeWidget,
        &gTRoadTypeWidget,
        &gTunnelTypeWidget,
        &gPipeTypeWidget,
        &gHalfPipeTypeWidget,
        &gCylinderTypeWidget,
        NULL,
        NULL,
    };
    s32* sCourseDesignTypeOptions[] = {
        &gRoadTypeOption,
        &gHRoadTypeOption,
        &gTRoadTypeOption,
        &gTunnelTypeOption,
        &gPipeTypeOption,
        &gHalfPipeTypeOption,
        &gCylinderTypeOption,
        NULL,
        NULL,
    };
    MenuWidget* sCoursePartTypeWidgets[] = {
        &sPitTypeWidget,      &sDashTypeWidget, &sDirtTypeWidget,     &sIceTypeWidget,  &sJumpTypeWidget,
        &sLandmineTypeWidget, &sGateTypeWidget, &sBuildingTypeWidget, &sSignTypeWidget,
    };
    s32* sCoursePartTypeOptions[] = {
        &gPitTypeOption,      &gDashTypeOption, &gDirtTypeOption,     &gIceTypeOption,  &gJumpTypeOption,
        &gLandmineTypeOption, &gGateTypeOption, &gBuildingTypeOption, &gSignTypeOption,
    };

    if (gCreateWidget.openIndex == INVALID_OPTION) {
        return;
    }

    func_xk1_80027C80(&gCourseEditWidget);
    switch (gCreateOption) {
        case CREATE_OPTION_COURSE:
            gCourseEditMenuItems[1].contentsTex = aCourseEditPointBoldTex;
            gCourseEditMenuItems[1].widget = &gPointWidget;
            gCourseEditMenuOptions[1] = &gPointOption;
            gCourseEditMenuItems[2].contentsTex = NULL;
            gCourseEditMenuItems[2].widget = NULL;
            gPointOption = POINT_OPTION_SET;
            break;
        case CREATE_OPTION_POINT:
            gCourseEditMenuItems[1].contentsTex = aCourseEditMoveTex;
            gCourseEditMenuItems[1].widget = &gMoveWidget;
            gCourseEditMenuOptions[1] = &gMoveOption;
            gCourseEditMenuItems[2].contentsTex = NULL;
            gCourseEditMenuItems[2].widget = NULL;
            gMoveOption = 0;
            break;
        case CREATE_OPTION_DESIGN:
            gDesignStyleOption = 0;
            gRoadTypeOption = 0;
            gHRoadTypeOption = 0;
            gTRoadTypeOption = 0;
            gTunnelTypeOption = 0;
            gPipeTypeOption = 0;
            gHalfPipeTypeOption = 0;
            gCylinderTypeOption = 0;
            gCourseEditMenuItems[1].contentsTex = aCourseEditStyleTex;
            gCourseEditMenuItems[1].widget = &gDesignStyleWidget;
            gCourseEditMenuOptions[1] = &gDesignStyleOption;

            switch (gDesignStyleOption) {
                case TRACK_DESIGN_STYLE_SPACE:
                case TRACK_DESIGN_STYLE_LOOP:
                    gCourseEditMenuItems[2].contentsTex = NULL;
                    break;
                default:
                    gCourseEditMenuItems[2].contentsTex = aCourseEditTypeTex;
                    break;
            }

            gCourseEditMenuItems[2].widget = sCourseDesignTypeWidgets[gDesignStyleOption];
            gCourseEditMenuOptions[2] = sCourseDesignTypeOptions[gDesignStyleOption];
            break;
        case CREATE_OPTION_PARTS:
            gPartsStyleOption = 0;
            gPitTypeOption = 0;
            gDashTypeOption = 0;
            gDirtTypeOption = 0;
            gIceTypeOption = 0;
            gJumpTypeOption = 0;
            gLandmineTypeOption = 0;
            gGateTypeOption = 0;
            gBuildingTypeOption = 0;
            gSignTypeOption = 0;

            gCourseEditMenuItems[1].contentsTex = aCourseEditStyleTex;
            gCourseEditMenuItems[1].widget = &gPartsStyleWidget;
            gCourseEditMenuOptions[1] = &gPartsStyleOption;
            gCourseEditMenuItems[2].contentsTex = aCourseEditTypeTex;
            gCourseEditMenuItems[2].widget = sCoursePartTypeWidgets[gPartsStyleOption];
            gCourseEditMenuOptions[2] = sCoursePartTypeOptions[gPartsStyleOption];
            break;
        case CREATE_OPTION_BACKGROUND:
            gCourseEditMenuItems[1].contentsTex = aCourseEditSceneTex;
            gCourseEditMenuItems[1].widget = &gVenueWidget;
            gCourseEditMenuOptions[1] = &gVenueOption;
            gCourseEditMenuItems[2].contentsTex = aCourseEditSkyTex;
            gCourseEditMenuItems[2].widget = &gSkyboxWidget;
            gCourseEditMenuOptions[2] = &gSkyboxOption;
            break;
        case CREATE_OPTION_BGM:
            gCourseEditMenuItems[1].contentsTex = aCourseEditTypeTex;
            gCourseEditMenuItems[1].widget = &gBGMWidget;
            gCourseEditMenuOptions[1] = &gBGMOption;
            gCourseEditMenuItems[2].contentsTex = NULL;
            gCourseEditMenuItems[2].widget = NULL;
            break;
    }
}

extern u8 D_80030060[];
extern u8 D_xk2_80104CA0[];
extern s32 D_xk2_80104CB0;
extern s32 D_xk2_80104CB8;
extern s32 D_xk2_80104CC0;
extern s32 D_xk2_800F7044;
extern s32 D_xk2_800F7058;
extern f32 D_xk2_80119744;

extern CourseFeaturesInfo gCourseFeaturesInfo;
extern s32 gSegmentChunkCount;

void func_xk1_8002860C(void) {
    func_xk2_800EF78C();
    func_xk2_800F5C50();
    D_80030060[0] = '\0';
    D_xk2_80104CB8 = 0;
    D_xk2_80104CC0 = 0;
    D_xk2_80104CB0 = 90;
    D_800D6CA0.unk_14 = 0;
    D_xk2_800F7044 = 0;
    D_802CB6D0.controlPointCount = 0;
    gCurrentCourseInfo->segmentCount = 0;
    COURSE_CONTEXT()->courseData.controlPointCount = 0;
    D_800D6CA0.unk_0C = -1;
    D_800D6CA0.unk_04 = 0;
    D_800D6CA0.unk_1C = -1;
    if (D_800D6CA0.unk_08 != 0x10) {
        func_xk2_800F12B0();
    }
    D_xk2_80104CA0[3] = 0;
    D_xk2_80104CA0[7] = 0;
    gSegmentChunkCount = 0;
    D_xk2_800F7058 = 0;
    D_xk2_80119744 = 0.0f;
    gPointOption = POINT_OPTION_SET;
    func_xk2_800DC3F8();
    func_80074204();
    gCurrentCourseInfo->length = 0.0f;
    gCourseFeaturesInfo.jumpCount = 0;
    gCourseFeaturesInfo.landmineCount = 0;
}

extern s32 D_xk2_800F7040;

void func_xk1_80028708(void) {
    if (gPointWidget.openIndex == INVALID_OPTION) {
        return;
    }
    func_xk1_80027C80(&gCourseEditWidget);
    switch (gPointOption) {
        case POINT_OPTION_CENTERING:
            func_xk2_800EF78C();
            func_xk2_800E72BC();
            gPointOption = POINT_OPTION_SET;
            return;
        case POINT_OPTION_REVERSE:
            func_xk2_800EF78C();
            func_xk2_800F0FF4();
            D_xk2_800F7040 = 3;
            gPointOption = POINT_OPTION_SET;
            return;
        case POINT_OPTION_CLEAR_ALL:
            D_xk1_80032C20 = 0;
            D_800D6CA0.unk_08 = 0x11;
            break;
        case POINT_OPTION_SET:
        case POINT_OPTION_START:
            break;
    }
}

void func_xk1_800287BC(void) {
    if (gMoveWidget.openIndex == INVALID_OPTION) {
        return;
    }
    func_xk1_80027C80(&gCourseEditWidget);
    switch (gMoveOption) {
        case MOVE_OPTION_MOVE_XZ:
        case MOVE_OPTION_MOVE_Y:
        case MOVE_OPTION_WIDTH:
        case MOVE_OPTION_BANK:
        case MOVE_OPTION_CENTER:
        case MOVE_OPTION_CLEAR:
        case MOVE_OPTION_STRAIGHT:
            break;
    }
}

void func_xk1_80028818(void) {
    if (gDesignStyleWidget.openIndex == INVALID_OPTION) {
        return;
    }
    func_xk1_80027C80(&gCourseEditWidget);
    switch (gDesignStyleOption) {
        case TRACK_DESIGN_STYLE_ROAD:
            gCourseEditMenuItems[2].contentsTex = aCourseEditTypeTex;
            gCourseEditMenuItems[2].widget = &gRoadTypeWidget;
            gCourseEditMenuOptions[2] = &gRoadTypeOption;
            break;
        case TRACK_DESIGN_STYLE_H_ROAD:
            gCourseEditMenuItems[2].contentsTex = aCourseEditTypeTex;
            gCourseEditMenuItems[2].widget = &gHRoadTypeWidget;
            gCourseEditMenuOptions[2] = &gHRoadTypeOption;
            break;
        case TRACK_DESIGN_STYLE_T_ROAD:
            gCourseEditMenuItems[2].contentsTex = aCourseEditTypeTex;
            gCourseEditMenuItems[2].widget = &gTRoadTypeWidget;
            gCourseEditMenuOptions[2] = &gTRoadTypeOption;
            break;
        case TRACK_DESIGN_STYLE_PIPE:
            gCourseEditMenuItems[2].contentsTex = aCourseEditTypeTex;
            gCourseEditMenuItems[2].widget = &gPipeTypeWidget;
            gCourseEditMenuOptions[2] = &gPipeTypeOption;
            break;
        case TRACK_DESIGN_STYLE_TUNNEL:
            gCourseEditMenuItems[2].contentsTex = aCourseEditTypeTex;
            gCourseEditMenuItems[2].widget = &gTunnelTypeWidget;
            gCourseEditMenuOptions[2] = &gTunnelTypeOption;
            break;
        case TRACK_DESIGN_STYLE_HALF_PIPE:
            gCourseEditMenuItems[2].contentsTex = aCourseEditTypeTex;
            gCourseEditMenuItems[2].widget = &gHalfPipeTypeWidget;
            gCourseEditMenuOptions[2] = &gHalfPipeTypeOption;
            break;
        case TRACK_DESIGN_STYLE_CYLINDER:
            gCourseEditMenuItems[2].contentsTex = aCourseEditTypeTex;
            gCourseEditMenuItems[2].widget = &gCylinderTypeWidget;
            gCourseEditMenuOptions[2] = &gCylinderTypeOption;
            break;
        case TRACK_DESIGN_STYLE_SPACE:
            gCourseEditMenuItems[2].contentsTex = NULL;
            gCourseEditMenuItems[2].widget = NULL;
            break;
        case TRACK_DESIGN_STYLE_LOOP:
            gCourseEditMenuItems[2].contentsTex = NULL;
            gCourseEditMenuItems[2].widget = NULL;
            break;
    }
}

void func_xk1_80028A04(void) {

    if (gPartsStyleWidget.openIndex == INVALID_OPTION) {
        return;
    }
    func_xk1_80027C80(&gCourseEditWidget);
    switch (gPartsStyleOption) {
        case TRACK_PART_STYLE_PIT:
            gCourseEditMenuItems[2].widget = &sPitTypeWidget;
            gCourseEditMenuOptions[2] = &gPitTypeOption;
            break;
        case TRACK_PART_STYLE_DASH:
            gCourseEditMenuItems[2].widget = &sDashTypeWidget;
            gCourseEditMenuOptions[2] = &gDashTypeOption;
            break;
        case TRACK_PART_STYLE_DIRT:
            gCourseEditMenuItems[2].widget = &sDirtTypeWidget;
            gCourseEditMenuOptions[2] = &gDirtTypeOption;
            break;
        case TRACK_PART_STYLE_SLIP:
            gCourseEditMenuItems[2].widget = &sIceTypeWidget;
            gCourseEditMenuOptions[2] = &gIceTypeOption;
            break;
        case TRACK_PART_STYLE_JUMP:
            gCourseEditMenuItems[2].widget = &sJumpTypeWidget;
            gCourseEditMenuOptions[2] = &gJumpTypeOption;
            break;
        case TRACK_PART_STYLE_TRAP:
            gCourseEditMenuItems[2].widget = &sLandmineTypeWidget;
            gCourseEditMenuOptions[2] = &gLandmineTypeOption;
            break;
        case TRACK_PART_STYLE_GATE:
            gCourseEditMenuItems[2].widget = &sGateTypeWidget;
            gCourseEditMenuOptions[2] = &gGateTypeOption;
            break;
        case TRACK_PART_STYLE_BUILDING:
            gCourseEditMenuItems[2].widget = &sBuildingTypeWidget;
            gCourseEditMenuOptions[2] = &gBuildingTypeOption;
            break;
        case TRACK_PART_STYLE_SIGN:
            gCourseEditMenuItems[2].widget = &sSignTypeWidget;
            gCourseEditMenuOptions[2] = &gSignTypeOption;
            break;
    }
}

void func_xk1_80028BA0(void) {
    if (gRoadTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028BD4(void) {
    if (gHRoadTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028C08(void) {
    if (gTRoadTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028C3C(void) {
    if (gTunnelTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028C70(void) {
    if (gPipeTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028CA4(void) {
    if (gHalfPipeTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028CD8(void) {
    if (gCylinderTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028D0C(void) {
    if (sPitTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028D40(void) {
    if (sDashTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028D74(void) {
    if (sDirtTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028DA8(void) {
    if (sIceTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028DDC(void) {
    if (sJumpTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028E10(void) {
    if (sLandmineTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
        switch (gLandmineTypeOption) {
            case LANDMINE_MIDDLE:
            case LANDMINE_LEFT:
            case LANDMINE_RIGHT:
                break;
        }
    }
}

void func_xk1_80028E54(void) {
    if (sGateTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028E88(void) {
    if (sBuildingTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028EBC(void) {
    if (sSignTypeWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
    }
}

void func_xk1_80028EF0(void) {
    if (gVenueWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
        COURSE_CONTEXT()->courseData.venue = gVenueOption;
        func_800747EC(gVenueOption);
        func_80077AD8(gVenueOption);
        D_xk2_800F7040 = 3;
    }
}

void func_xk1_80028F50(void) {
    if (gSkyboxWidget.openIndex != INVALID_OPTION) {
        func_xk1_80027C80(&gCourseEditWidget);
        COURSE_CONTEXT()->courseData.skybox = gSkyboxOption;
    }
}

extern s32 D_800D11C8[];

void func_xk1_80028F94(void) {

    if ((gBGMWidget.openIndex != INVALID_OPTION) && (func_807424CC() == 0)) {
        if (gLastCourseBGM != gBGMOptionToCourseBGM[gBGMOption]) {
            if (D_800D11C8[3] != 0) {
                Audio_TriggerSystemSE(NA_SE_36);
            }
            gLastCourseBGM = gBGMOptionToCourseBGM[gBGMOption];
            Audio_DDBgmStart2(gBGMOptionToCourseBGM[gBGMWidget.openIndex]);
            gBGMWidget.openIndex = INVALID_OPTION;
            COURSE_CONTEXT()->courseData.bgm = gBGMOptionToCourseBGM[gBGMOption];
        }
    }
}

void func_xk1_80029070(void) {
    gCreateOption = CREATE_OPTION_COURSE;
    gCourseEditMenuItems[1].contentsTex = aCourseEditPointBoldTex;
    gCourseEditMenuItems[1].widget = &gPointWidget;
    gCourseEditMenuOptions[1] = &gPointOption;
    gCourseEditMenuItems[2].contentsTex = NULL;
    gCourseEditMenuItems[2].widget = NULL;
}

s32 func_xk1_800290B4(void) {
    return sMenuPageYOffset;
}

s32 func_xk1_800290C0(void) {
    return sMenuHighlightAlpha;
}
