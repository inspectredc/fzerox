#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "src/overlays/ovl_i2/ovl_i2.h"
#include "ovl_i4.h"
#include "assets/segment_2B9EA0.h"
#include "assets/segment_17B960.h"

UNUSED s32 D_8011D770;
s32 sMachinesUnlocked;
f32 D_i4_8011D778;
f32 D_i4_8011D77C;
s16 sMachineSelectIndex[8];

unk_80077D50 sPortraitDrStewartCompTexInfo[] = { { 17, aFullPortraitDrStewartTex, TEX_WIDTH(aFullPortraitDrStewartTex),
                                                   TEX_HEIGHT(aFullPortraitDrStewartTex),
                                                   TEX_COMPRESSED_SIZE(aFullPortraitDrStewartTex) },
                                                 { 0 } };
unk_80077D50 sPortraitCaptainFalconCompTexInfo[] = {
    { 17, aFullPortraitCaptainFalconTex, TEX_WIDTH(aFullPortraitCaptainFalconTex),
      TEX_HEIGHT(aFullPortraitCaptainFalconTex), TEX_COMPRESSED_SIZE(aFullPortraitCaptainFalconTex) },
    { 0 }
};
unk_80077D50 sPortraitJodySummerCompTexInfo[] = {
    { 17, aFullPortraitJodySummerTex, TEX_WIDTH(aFullPortraitJodySummerTex), TEX_HEIGHT(aFullPortraitJodySummerTex),
      TEX_COMPRESSED_SIZE(aFullPortraitJodySummerTex) },
    { 0 }
};
unk_80077D50 sPortraitSamuraiGorohCompTexInfo[] = {
    { 17, aFullPortraitSamuraiGorohTex, TEX_WIDTH(aFullPortraitSamuraiGorohTex),
      TEX_HEIGHT(aFullPortraitSamuraiGorohTex), TEX_COMPRESSED_SIZE(aFullPortraitSamuraiGorohTex) },
    { 0 }
};
unk_80077D50 sPortraitMightyGazelleCompTexInfo[] = {
    { 17, aFullPortraitMightyGazelleTex, TEX_WIDTH(aFullPortraitMightyGazelleTex),
      TEX_HEIGHT(aFullPortraitMightyGazelleTex), TEX_COMPRESSED_SIZE(aFullPortraitMightyGazelleTex) },
    { 0 }
};
unk_80077D50 sPortraitPicoCompTexInfo[] = { { 17, aFullPortraitPicoTex, TEX_WIDTH(aFullPortraitPicoTex),
                                              TEX_HEIGHT(aFullPortraitPicoTex),
                                              TEX_COMPRESSED_SIZE(aFullPortraitPicoTex) },
                                            { 0 } };
unk_80077D50 sPortraitBabaCompTexInfo[] = { { 17, aFullPortraitBabaTex, TEX_WIDTH(aFullPortraitBabaTex),
                                              TEX_HEIGHT(aFullPortraitBabaTex),
                                              TEX_COMPRESSED_SIZE(aFullPortraitBabaTex) },
                                            { 0 } };
unk_80077D50 sPortraitMrEadCompTexInfo[] = { { 17, aFullPortraitMrEadTex, TEX_WIDTH(aFullPortraitMrEadTex),
                                               TEX_HEIGHT(aFullPortraitMrEadTex),
                                               TEX_COMPRESSED_SIZE(aFullPortraitMrEadTex) },
                                             { 0 } };
unk_80077D50 sPortraitOctomanCompTexInfo[] = { { 17, aFullPortraitOctomanTex, TEX_WIDTH(aFullPortraitOctomanTex),
                                                 TEX_HEIGHT(aFullPortraitOctomanTex),
                                                 TEX_COMPRESSED_SIZE(aFullPortraitOctomanTex) },
                                               { 0 } };
unk_80077D50 sPortraitTheSkullCompTexInfo[] = { { 17, aFullPortraitTheSkullTex, TEX_WIDTH(aFullPortraitTheSkullTex),
                                                  TEX_HEIGHT(aFullPortraitTheSkullTex),
                                                  TEX_COMPRESSED_SIZE(aFullPortraitTheSkullTex) },
                                                { 0 } };
unk_80077D50 sPortraitBeastmanCompTexInfo[] = { { 17, aFullPortraitBeastmanTex, TEX_WIDTH(aFullPortraitBeastmanTex),
                                                  TEX_HEIGHT(aFullPortraitBeastmanTex),
                                                  TEX_COMPRESSED_SIZE(aFullPortraitBeastmanTex) },
                                                { 0 } };
unk_80077D50 sPortraitAntonioGusterCompTexInfo[] = {
    { 17, aFullPortraitAntonioGusterTex, TEX_WIDTH(aFullPortraitAntonioGusterTex),
      TEX_HEIGHT(aFullPortraitAntonioGusterTex), TEX_COMPRESSED_SIZE(aFullPortraitAntonioGusterTex) },
    { 0 }
};
unk_80077D50 sPortraitDraqCompTexInfo[] = { { 17, aFullPortraitDraqTex, TEX_WIDTH(aFullPortraitDraqTex),
                                              TEX_HEIGHT(aFullPortraitDraqTex),
                                              TEX_COMPRESSED_SIZE(aFullPortraitDraqTex) },
                                            { 0 } };
unk_80077D50 sPortraitRogerBusterCompTexInfo[] = {
    { 17, aFullPortraitRogerBusterTex, TEX_WIDTH(aFullPortraitRogerBusterTex), TEX_HEIGHT(aFullPortraitRogerBusterTex),
      TEX_COMPRESSED_SIZE(aFullPortraitRogerBusterTex) },
    { 0 }
};
unk_80077D50 sPortraitSilverNeelsenCompTexInfo[] = {
    { 17, aFullPortraitSilverNeelsenTex, TEX_WIDTH(aFullPortraitSilverNeelsenTex),
      TEX_HEIGHT(aFullPortraitSilverNeelsenTex), TEX_COMPRESSED_SIZE(aFullPortraitSilverNeelsenTex) },
    { 0 }
};
unk_80077D50 sPortraitSuperArrowCompTexInfo[] = {
    { 17, aFullPortraitSuperArrowTex, TEX_WIDTH(aFullPortraitSuperArrowTex), TEX_HEIGHT(aFullPortraitSuperArrowTex),
      TEX_COMPRESSED_SIZE(aFullPortraitSuperArrowTex) },
    { 0 }
};
unk_80077D50 sPortraitMrsArrowCompTexInfo[] = { { 17, aFullPortraitMrsArrowTex, TEX_WIDTH(aFullPortraitMrsArrowTex),
                                                  TEX_HEIGHT(aFullPortraitMrsArrowTex),
                                                  TEX_COMPRESSED_SIZE(aFullPortraitMrsArrowTex) },
                                                { 0 } };
unk_80077D50 sPortraitZodaCompTexInfo[] = { { 17, aFullPortraitZodaTex, TEX_WIDTH(aFullPortraitZodaTex),
                                              TEX_HEIGHT(aFullPortraitZodaTex),
                                              TEX_COMPRESSED_SIZE(aFullPortraitZodaTex) },
                                            { 0 } };
unk_80077D50 sPortraitJohnTanakaCompTexInfo[] = {
    { 17, aFullPortraitJohnTanakaTex, TEX_WIDTH(aFullPortraitJohnTanakaTex), TEX_HEIGHT(aFullPortraitJohnTanakaTex),
      TEX_COMPRESSED_SIZE(aFullPortraitJohnTanakaTex) },
    { 0 }
};
unk_80077D50 sPortraitBioRexCompTexInfo[] = { { 17, aFullPortraitBioRexTex, TEX_WIDTH(aFullPortraitBioRexTex),
                                                TEX_HEIGHT(aFullPortraitBioRexTex),
                                                TEX_COMPRESSED_SIZE(aFullPortraitBioRexTex) },
                                              { 0 } };
unk_80077D50 sPortraitKateAlenCompTexInfo[] = { { 17, aFullPortraitKateAlenTex, TEX_WIDTH(aFullPortraitKateAlenTex),
                                                  TEX_HEIGHT(aFullPortraitKateAlenTex),
                                                  TEX_COMPRESSED_SIZE(aFullPortraitKateAlenTex) },
                                                { 0 } };
unk_80077D50 sPortraitGomarAndShiohCompTexInfo[] = {
    { 17, aFullPortraitGomarAndShiohTex, TEX_WIDTH(aFullPortraitGomarAndShiohTex),
      TEX_HEIGHT(aFullPortraitGomarAndShiohTex), TEX_COMPRESSED_SIZE(aFullPortraitGomarAndShiohTex) },
    { 0 }
};
unk_80077D50 sPortraitMichaelChainCompTexInfo[] = {
    { 17, aFullPortraitMichaelChainTex, TEX_WIDTH(aFullPortraitMichaelChainTex),
      TEX_HEIGHT(aFullPortraitMichaelChainTex), TEX_COMPRESSED_SIZE(aFullPortraitMichaelChainTex) },
    { 0 }
};
unk_80077D50 sPortraitBillyCompTexInfo[] = { { 17, aFullPortraitBillyTex, TEX_WIDTH(aFullPortraitBillyTex),
                                               TEX_HEIGHT(aFullPortraitBillyTex),
                                               TEX_COMPRESSED_SIZE(aFullPortraitBillyTex) },
                                             { 0 } };
unk_80077D50 sPortraitDrClashCompTexInfo[] = { { 17, aFullPortraitDrClashTex, TEX_WIDTH(aFullPortraitDrClashTex),
                                                 TEX_HEIGHT(aFullPortraitDrClashTex),
                                                 TEX_COMPRESSED_SIZE(aFullPortraitDrClashTex) },
                                               { 0 } };
unk_80077D50 sPortraitJackLevinCompTexInfo[] = { { 17, aFullPortraitJackLevinTex, TEX_WIDTH(aFullPortraitJackLevinTex),
                                                   TEX_HEIGHT(aFullPortraitJackLevinTex),
                                                   TEX_COMPRESSED_SIZE(aFullPortraitJackLevinTex) },
                                                 { 0 } };
unk_80077D50 sPortraitBloodFalconCompTexInfo[] = {
    { 17, aFullPortraitBloodFalconTex, TEX_WIDTH(aFullPortraitBloodFalconTex), TEX_HEIGHT(aFullPortraitBloodFalconTex),
      TEX_COMPRESSED_SIZE(aFullPortraitBloodFalconTex) },
    { 0 }
};
unk_80077D50 sPortraitLeonCompTexInfo[] = { { 17, aFullPortraitLeonTex, TEX_WIDTH(aFullPortraitLeonTex),
                                              TEX_HEIGHT(aFullPortraitLeonTex),
                                              TEX_COMPRESSED_SIZE(aFullPortraitLeonTex) },
                                            { 0 } };
unk_80077D50 sPortraitJamesMcCloudCompTexInfo[] = {
    { 17, aFullPortraitJamesMcCloudTex, TEX_WIDTH(aFullPortraitJamesMcCloudTex),
      TEX_HEIGHT(aFullPortraitJamesMcCloudTex), TEX_COMPRESSED_SIZE(aFullPortraitJamesMcCloudTex) },
    { 0 }
};
unk_80077D50 sPortraitBlackShadowCompTexInfo[] = {
    { 17, aFullPortraitBlackShadowTex, TEX_WIDTH(aFullPortraitBlackShadowTex), TEX_HEIGHT(aFullPortraitBlackShadowTex),
      TEX_COMPRESSED_SIZE(aFullPortraitBlackShadowTex) },
    { 0 }
};
unk_80077D50 sPortraitCaptainFalconAltCompTexInfo[] = {
    { 17, aFullPortraitCaptainFalconAltTex, TEX_WIDTH(aFullPortraitCaptainFalconAltTex),
      TEX_HEIGHT(aFullPortraitCaptainFalconAltTex), TEX_COMPRESSED_SIZE(aFullPortraitCaptainFalconAltTex) },
    { 0 }
};
unk_80077D50 sPortraitSamuraiGorohAltCompTexInfo[] = {
    { 17, aFullPortraitSamuraiGorohAltTex, TEX_WIDTH(aFullPortraitSamuraiGorohAltTex),
      TEX_HEIGHT(aFullPortraitSamuraiGorohAltTex), TEX_COMPRESSED_SIZE(aFullPortraitSamuraiGorohAltTex) },
    { 0 }
};
unk_80077D50 sPortraitJodySummerAltCompTexInfo[] = {
    { 17, aFullPortraitJodySummerAltTex, TEX_WIDTH(aFullPortraitJodySummerAltTex),
      TEX_HEIGHT(aFullPortraitJodySummerAltTex), TEX_COMPRESSED_SIZE(aFullPortraitJodySummerAltTex) },
    { 0 }
};
unk_80077D50 sPortraitBackgroundCompTexInfo[] = {
    { 17, aFullPortraitBackgroundTex, TEX_WIDTH(aFullPortraitBackgroundTex), TEX_HEIGHT(aFullPortraitBackgroundTex),
      TEX_COMPRESSED_SIZE(aFullPortraitBackgroundTex) },
    { 0 }
};

unk_80077D50* sPortraitCompTexInfos[] = {
    sPortraitCaptainFalconCompTexInfo,    // CAPTAIN_FALCON
    sPortraitDrStewartCompTexInfo,        // DR_STEWART
    sPortraitPicoCompTexInfo,             // PICO
    sPortraitSamuraiGorohCompTexInfo,     // SAMURAI_GOROH
    sPortraitJodySummerCompTexInfo,       // JODY_SUMMER
    sPortraitMightyGazelleCompTexInfo,    // MIGHTY_GAZELLE
    sPortraitMrEadCompTexInfo,            // MR_EAD
    sPortraitBabaCompTexInfo,             // BABA
    sPortraitOctomanCompTexInfo,          // OCTOMAN
    sPortraitGomarAndShiohCompTexInfo,    // GOMAR_AND_SHIOH
    sPortraitKateAlenCompTexInfo,         // KATE_ALEN
    sPortraitRogerBusterCompTexInfo,      // ROGER_BUSTER
    sPortraitJamesMcCloudCompTexInfo,     // JAMES_MCCLOUD
    sPortraitLeonCompTexInfo,             // LEON
    sPortraitAntonioGusterCompTexInfo,    // ANTONIO_GUSTER
    sPortraitBlackShadowCompTexInfo,      // BLACK_SHADOW
    sPortraitMichaelChainCompTexInfo,     // MICHAEL_CHAIN
    sPortraitJackLevinCompTexInfo,        // JACK_LEVIN
    sPortraitSuperArrowCompTexInfo,       // SUPER_ARROW
    sPortraitMrsArrowCompTexInfo,         // MRS_ARROW
    sPortraitJohnTanakaCompTexInfo,       // JOHN_TANAKA
    sPortraitBeastmanCompTexInfo,         // BEASTMAN
    sPortraitZodaCompTexInfo,             // ZODA
    sPortraitDrClashCompTexInfo,          // DR_CLASH
    sPortraitSilverNeelsenCompTexInfo,    // SILVER_NEELSEN
    sPortraitBioRexCompTexInfo,           // BIO_REX
    sPortraitDraqCompTexInfo,             // DRAQ
    sPortraitBillyCompTexInfo,            // BILLY
    sPortraitTheSkullCompTexInfo,         // THE_SKULL
    sPortraitBloodFalconCompTexInfo,      // BLOOD_FALCON
    sPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sPortraitSamuraiGorohAltCompTexInfo,  // GOROH_ALT
    sPortraitJodySummerAltCompTexInfo,    // SUMMERS_ALT
};

unk_800792D8 D_i4_8011BE4C[] = { { sPortraitDrStewartCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BE5C[] = { { sPortraitCaptainFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BE6C[] = { { sPortraitJodySummerCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BE7C[] = { { sPortraitSamuraiGorohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BE8C[] = { { sPortraitMightyGazelleCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BE9C[] = { { sPortraitPicoCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BEAC[] = { { sPortraitBabaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BEBC[] = { { sPortraitMrEadCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BECC[] = { { sPortraitOctomanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BEDC[] = { { sPortraitTheSkullCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BEEC[] = { { sPortraitBeastmanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BEFC[] = { { sPortraitAntonioGusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF0C[] = { { sPortraitDraqCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF1C[] = { { sPortraitRogerBusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF2C[] = { { sPortraitSilverNeelsenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF3C[] = { { sPortraitSuperArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF4C[] = { { sPortraitMrsArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF5C[] = { { sPortraitZodaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF6C[] = { { sPortraitJohnTanakaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF7C[] = { { sPortraitBioRexCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF8C[] = { { sPortraitKateAlenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF9C[] = { { sPortraitGomarAndShiohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFAC[] = { { sPortraitMichaelChainCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFBC[] = { { sPortraitBillyCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFCC[] = { { sPortraitDrClashCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFDC[] = { { sPortraitJackLevinCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFEC[] = { { sPortraitBloodFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFFC[] = { { sPortraitLeonCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C00C[] = { { sPortraitJamesMcCloudCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C01C[] = { { sPortraitBlackShadowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C02C[] = { { sPortraitCaptainFalconAltCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C03C[] = { { sPortraitSamuraiGorohAltCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C04C[] = { { sPortraitJodySummerAltCompTexInfo, 60 }, { 0 } };

unk_800792D8* D_i4_8011C05C[] = {
    D_i4_8011BE5C, D_i4_8011BE4C, D_i4_8011BE9C, D_i4_8011BE7C, D_i4_8011BE6C, D_i4_8011BE8C, D_i4_8011BEBC,
    D_i4_8011BEAC, D_i4_8011BECC, D_i4_8011BF9C, D_i4_8011BF8C, D_i4_8011BF1C, D_i4_8011C00C, D_i4_8011BFFC,
    D_i4_8011BEFC, D_i4_8011C01C, D_i4_8011BFAC, D_i4_8011BFDC, D_i4_8011BF3C, D_i4_8011BF4C, D_i4_8011BF6C,
    D_i4_8011BEEC, D_i4_8011BF5C, D_i4_8011BFCC, D_i4_8011BF2C, D_i4_8011BF7C, D_i4_8011BF0C, D_i4_8011BFBC,
    D_i4_8011BEDC, D_i4_8011BFEC, D_i4_8011C02C, D_i4_8011C02C, D_i4_8011C02C, D_i4_8011C03C, D_i4_8011C04C,
};

unk_80077D50 sSmallPortraitDrStewartCompTexInfo[] = {
    { 17, aSmallPortraitDrStewartTex, TEX_WIDTH(aSmallPortraitDrStewartTex), TEX_HEIGHT(aSmallPortraitDrStewartTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitDrStewartTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitCaptainFalconCompTexInfo[] = {
    { 17, aSmallPortraitCaptainFalconTex, TEX_WIDTH(aSmallPortraitCaptainFalconTex),
      TEX_HEIGHT(aSmallPortraitCaptainFalconTex), TEX_COMPRESSED_SIZE(aSmallPortraitCaptainFalconTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitJodySummerCompTexInfo[] = {
    { 17, aSmallPortraitJodySummerTex, TEX_WIDTH(aSmallPortraitJodySummerTex), TEX_HEIGHT(aSmallPortraitJodySummerTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitJodySummerTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitSamuraiGorohCompTexInfo[] = {
    { 17, aSmallPortraitSamuraiGorohTex, TEX_WIDTH(aSmallPortraitSamuraiGorohTex),
      TEX_HEIGHT(aSmallPortraitSamuraiGorohTex), TEX_COMPRESSED_SIZE(aSmallPortraitSamuraiGorohTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitMightyGazelleCompTexInfo[] = {
    { 17, aSmallPortraitMightyGazelleTex, TEX_WIDTH(aSmallPortraitMightyGazelleTex),
      TEX_HEIGHT(aSmallPortraitMightyGazelleTex), TEX_COMPRESSED_SIZE(aSmallPortraitMightyGazelleTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitPicoCompTexInfo[] = { { 17, aSmallPortraitPicoTex, TEX_WIDTH(aSmallPortraitPicoTex),
                                                   TEX_HEIGHT(aSmallPortraitPicoTex),
                                                   TEX_COMPRESSED_SIZE(aSmallPortraitPicoTex) },
                                                 { 0 } };
unk_80077D50 sSmallPortraitBabaCompTexInfo[] = { { 17, aSmallPortraitBabaTex, TEX_WIDTH(aSmallPortraitBabaTex),
                                                   TEX_HEIGHT(aSmallPortraitBabaTex),
                                                   TEX_COMPRESSED_SIZE(aSmallPortraitBabaTex) },
                                                 { 0 } };
unk_80077D50 sSmallPortraitMrEadCompTexInfo[] = { { 17, aSmallPortraitMrEadTex, TEX_WIDTH(aSmallPortraitMrEadTex),
                                                    TEX_HEIGHT(aSmallPortraitMrEadTex),
                                                    TEX_COMPRESSED_SIZE(aSmallPortraitMrEadTex) },
                                                  { 0 } };
unk_80077D50 sSmallPortraitOctomanCompTexInfo[] = { { 17, aSmallPortraitOctomanTex, TEX_WIDTH(aSmallPortraitOctomanTex),
                                                      TEX_HEIGHT(aSmallPortraitOctomanTex),
                                                      TEX_COMPRESSED_SIZE(aSmallPortraitOctomanTex) },
                                                    { 0 } };
unk_80077D50 sSmallPortraitTheSkullCompTexInfo[] = {
    { 17, aSmallPortraitTheSkullTex, TEX_WIDTH(aSmallPortraitTheSkullTex), TEX_HEIGHT(aSmallPortraitTheSkullTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitTheSkullTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitBeastmanCompTexInfo[] = {
    { 17, aSmallPortraitBeastmanTex, TEX_WIDTH(aSmallPortraitBeastmanTex), TEX_HEIGHT(aSmallPortraitBeastmanTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitBeastmanTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitAntonioGusterCompTexInfo[] = {
    { 17, aSmallPortraitAntonioGusterTex, TEX_WIDTH(aSmallPortraitAntonioGusterTex),
      TEX_HEIGHT(aSmallPortraitAntonioGusterTex), TEX_COMPRESSED_SIZE(aSmallPortraitAntonioGusterTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitDraqCompTexInfo[] = { { 17, aSmallPortraitDraqTex, TEX_WIDTH(aSmallPortraitDraqTex),
                                                   TEX_HEIGHT(aSmallPortraitDraqTex),
                                                   TEX_COMPRESSED_SIZE(aSmallPortraitDraqTex) },
                                                 { 0 } };
unk_80077D50 sSmallPortraitRogerBusterCompTexInfo[] = {
    { 17, aSmallPortraitRogerBusterTex, TEX_WIDTH(aSmallPortraitRogerBusterTex),
      TEX_HEIGHT(aSmallPortraitRogerBusterTex), TEX_COMPRESSED_SIZE(aSmallPortraitRogerBusterTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitSilverNeelsenCompTexInfo[] = {
    { 17, aSmallPortraitSilverNeelsenTex, TEX_WIDTH(aSmallPortraitSilverNeelsenTex),
      TEX_HEIGHT(aSmallPortraitSilverNeelsenTex), TEX_COMPRESSED_SIZE(aSmallPortraitSilverNeelsenTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitSuperArrowCompTexInfo[] = {
    { 17, aSmallPortraitSuperArrowTex, TEX_WIDTH(aSmallPortraitSuperArrowTex), TEX_HEIGHT(aSmallPortraitSuperArrowTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitSuperArrowTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitMrsArrowCompTexInfo[] = {
    { 17, aSmallPortraitMrsArrowTex, TEX_WIDTH(aSmallPortraitMrsArrowTex), TEX_HEIGHT(aSmallPortraitMrsArrowTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitMrsArrowTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitZodaCompTexInfo[] = { { 17, aSmallPortraitZodaTex, TEX_WIDTH(aSmallPortraitZodaTex),
                                                   TEX_HEIGHT(aSmallPortraitZodaTex),
                                                   TEX_COMPRESSED_SIZE(aSmallPortraitZodaTex) },
                                                 { 0 } };
unk_80077D50 sSmallPortraitJohnTanakaCompTexInfo[] = {
    { 17, aSmallPortraitJohnTanakaTex, TEX_WIDTH(aSmallPortraitJohnTanakaTex), TEX_HEIGHT(aSmallPortraitJohnTanakaTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitJohnTanakaTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitBioRexCompTexInfo[] = { { 17, aSmallPortraitBioRexTex, TEX_WIDTH(aSmallPortraitBioRexTex),
                                                     TEX_HEIGHT(aSmallPortraitBioRexTex),
                                                     TEX_COMPRESSED_SIZE(aSmallPortraitBioRexTex) },
                                                   { 0 } };
unk_80077D50 sSmallPortraitKateAlenCompTexInfo[] = {
    { 17, aSmallPortraitKateAlenTex, TEX_WIDTH(aSmallPortraitKateAlenTex), TEX_HEIGHT(aSmallPortraitKateAlenTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitKateAlenTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitGomarAndShiohCompTexInfo[] = {
    { 17, aSmallPortraitGomarAndShiohTex, TEX_WIDTH(aSmallPortraitGomarAndShiohTex),
      TEX_HEIGHT(aSmallPortraitGomarAndShiohTex), TEX_COMPRESSED_SIZE(aSmallPortraitGomarAndShiohTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitMichaelChainCompTexInfo[] = {
    { 17, aSmallPortraitMichaelChainTex, TEX_WIDTH(aSmallPortraitMichaelChainTex),
      TEX_HEIGHT(aSmallPortraitMichaelChainTex), TEX_COMPRESSED_SIZE(aSmallPortraitMichaelChainTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitBillyCompTexInfo[] = { { 17, aSmallPortraitBillyTex, TEX_WIDTH(aSmallPortraitBillyTex),
                                                    TEX_HEIGHT(aSmallPortraitBillyTex),
                                                    TEX_COMPRESSED_SIZE(aSmallPortraitBillyTex) },
                                                  { 0 } };
unk_80077D50 sSmallPortraitDrClashCompTexInfo[] = { { 17, aSmallPortraitDrClashTex, TEX_WIDTH(aSmallPortraitDrClashTex),
                                                      TEX_HEIGHT(aSmallPortraitDrClashTex),
                                                      TEX_COMPRESSED_SIZE(aSmallPortraitDrClashTex) },
                                                    { 0 } };
unk_80077D50 sSmallPortraitJackLevinCompTexInfo[] = {
    { 17, aSmallPortraitJackLevinTex, TEX_WIDTH(aSmallPortraitJackLevinTex), TEX_HEIGHT(aSmallPortraitJackLevinTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitJackLevinTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitBloodFalconCompTexInfo[] = {
    { 17, aSmallPortraitBloodFalconTex, TEX_WIDTH(aSmallPortraitBloodFalconTex),
      TEX_HEIGHT(aSmallPortraitBloodFalconTex), TEX_COMPRESSED_SIZE(aSmallPortraitBloodFalconTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitLeonCompTexInfo[] = { { 17, aSmallPortraitLeonTex, TEX_WIDTH(aSmallPortraitLeonTex),
                                                   TEX_HEIGHT(aSmallPortraitLeonTex),
                                                   TEX_COMPRESSED_SIZE(aSmallPortraitLeonTex) },
                                                 { 0 } };
unk_80077D50 sSmallPortraitJamesMcCloudCompTexInfo[] = {
    { 17, aSmallPortraitJamesMcCloudTex, TEX_WIDTH(aSmallPortraitJamesMcCloudTex),
      TEX_HEIGHT(aSmallPortraitJamesMcCloudTex), TEX_COMPRESSED_SIZE(aSmallPortraitJamesMcCloudTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitBlackShadowCompTexInfo[] = {
    { 17, aSmallPortraitBlackShadowTex, TEX_WIDTH(aSmallPortraitBlackShadowTex),
      TEX_HEIGHT(aSmallPortraitBlackShadowTex), TEX_COMPRESSED_SIZE(aSmallPortraitBlackShadowTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitCaptainFalconAltCompTexInfo[] = {
    { 17, aSmallPortraitCaptainFalconAltTex, TEX_WIDTH(aSmallPortraitCaptainFalconAltTex),
      TEX_HEIGHT(aSmallPortraitCaptainFalconAltTex), TEX_COMPRESSED_SIZE(aSmallPortraitCaptainFalconAltTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitSamuraiGorohAltCompTexInfo[] = {
    { 17, aSmallPortraitSamuraiGorohAltTex, TEX_WIDTH(aSmallPortraitSamuraiGorohAltTex),
      TEX_HEIGHT(aSmallPortraitSamuraiGorohAltTex), TEX_COMPRESSED_SIZE(aSmallPortraitSamuraiGorohAltTex) },
    { 0 }
};
unk_80077D50 sSmallPortraitJodySummerAltCompTexInfo[] = {
    { 17, aSmallPortraitJodySummerAltTex, TEX_WIDTH(aSmallPortraitJodySummerAltTex),
      TEX_HEIGHT(aSmallPortraitJodySummerAltTex), TEX_COMPRESSED_SIZE(aSmallPortraitJodySummerAltTex) },
    { 0 }
};

unk_80077D50* sSmallPortraitCompTexInfos[] = {
    sSmallPortraitCaptainFalconCompTexInfo,    // CAPTAIN_FALCON
    sSmallPortraitDrStewartCompTexInfo,        // DR_STEWART
    sSmallPortraitPicoCompTexInfo,             // PICO
    sSmallPortraitSamuraiGorohCompTexInfo,     // SAMURAI_GOROH
    sSmallPortraitJodySummerCompTexInfo,       // JODY_SUMMER
    sSmallPortraitMightyGazelleCompTexInfo,    // MIGHTY_GAZELLE
    sSmallPortraitMrEadCompTexInfo,            // MR_EAD
    sSmallPortraitBabaCompTexInfo,             // BABA
    sSmallPortraitOctomanCompTexInfo,          // OCTOMAN
    sSmallPortraitGomarAndShiohCompTexInfo,    // GOMAR_AND_SHIOH
    sSmallPortraitKateAlenCompTexInfo,         // KATE_ALEN
    sSmallPortraitRogerBusterCompTexInfo,      // ROGER_BUSTER
    sSmallPortraitJamesMcCloudCompTexInfo,     // JAMES_MCCLOUD
    sSmallPortraitLeonCompTexInfo,             // LEON
    sSmallPortraitAntonioGusterCompTexInfo,    // ANTONIO_GUSTER
    sSmallPortraitBlackShadowCompTexInfo,      // BLACK_SHADOW
    sSmallPortraitMichaelChainCompTexInfo,     // MICHAEL_CHAIN
    sSmallPortraitJackLevinCompTexInfo,        // JACK_LEVIN
    sSmallPortraitSuperArrowCompTexInfo,       // SUPER_ARROW
    sSmallPortraitMrsArrowCompTexInfo,         // MRS_ARROW
    sSmallPortraitJohnTanakaCompTexInfo,       // JOHN_TANAKA
    sSmallPortraitBeastmanCompTexInfo,         // BEASTMAN
    sSmallPortraitZodaCompTexInfo,             // ZODA
    sSmallPortraitDrClashCompTexInfo,          // DR_CLASH
    sSmallPortraitSilverNeelsenCompTexInfo,    // SILVER_NEELSEN
    sSmallPortraitBioRexCompTexInfo,           // BIO_REX
    sSmallPortraitDraqCompTexInfo,             // DRAQ
    sSmallPortraitBillyCompTexInfo,            // BILLY
    sSmallPortraitTheSkullCompTexInfo,         // THE_SKULL
    sSmallPortraitBloodFalconCompTexInfo,      // BLOOD_FALCON
    sSmallPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sSmallPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sSmallPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sSmallPortraitSamuraiGorohAltCompTexInfo,  // GOROH_ALT
    sSmallPortraitJodySummerAltCompTexInfo,    // SUMMERS_ALT
};

unk_800792D8 D_i4_8011C594[] = { { sSmallPortraitDrStewartCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5A4[] = { { sSmallPortraitCaptainFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5B4[] = { { sSmallPortraitJodySummerCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5C4[] = { { sSmallPortraitSamuraiGorohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5D4[] = { { sSmallPortraitMightyGazelleCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5E4[] = { { sSmallPortraitPicoCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5F4[] = { { sSmallPortraitBabaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C604[] = { { sSmallPortraitMrEadCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C614[] = { { sSmallPortraitOctomanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C624[] = { { sSmallPortraitTheSkullCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C634[] = { { sSmallPortraitBeastmanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C644[] = { { sSmallPortraitAntonioGusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C654[] = { { sSmallPortraitDraqCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C664[] = { { sSmallPortraitRogerBusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C674[] = { { sSmallPortraitSilverNeelsenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C684[] = { { sSmallPortraitSuperArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C694[] = { { sSmallPortraitMrsArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6A4[] = { { sSmallPortraitZodaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6B4[] = { { sSmallPortraitJohnTanakaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6C4[] = { { sSmallPortraitBioRexCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6D4[] = { { sSmallPortraitKateAlenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6E4[] = { { sSmallPortraitGomarAndShiohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6F4[] = { { sSmallPortraitMichaelChainCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C704[] = { { sSmallPortraitBillyCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C714[] = { { sSmallPortraitDrClashCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C724[] = { { sSmallPortraitJackLevinCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C734[] = { { sSmallPortraitBloodFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C744[] = { { sSmallPortraitLeonCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C754[] = { { sSmallPortraitJamesMcCloudCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C764[] = { { sSmallPortraitBlackShadowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C774[] = { { sSmallPortraitCaptainFalconAltCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C784[] = { { sSmallPortraitSamuraiGorohAltCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011C794[] = { { sSmallPortraitJodySummerAltCompTexInfo, 60 }, { 0 } };

unk_800792D8* D_i4_8011C7A4[] = {
    D_i4_8011C5A4, D_i4_8011C594, D_i4_8011C5E4, D_i4_8011C5C4, D_i4_8011C5B4, D_i4_8011C5D4,
    D_i4_8011C604, D_i4_8011C5F4, D_i4_8011C614, D_i4_8011C6E4, D_i4_8011C6D4, D_i4_8011C664,
    D_i4_8011C754, D_i4_8011C744, D_i4_8011C644, D_i4_8011C764, D_i4_8011C6F4, D_i4_8011C724,
    D_i4_8011C684, D_i4_8011C694, D_i4_8011C6B4, D_i4_8011C634, D_i4_8011C6A4, D_i4_8011C714,
    D_i4_8011C674, D_i4_8011C6C4, D_i4_8011C654, D_i4_8011C704, D_i4_8011C624, D_i4_8011C734,
    D_i4_8011C774, D_i4_8011C774, D_i4_8011C774, D_i4_8011C784, D_i4_8011C794, D_i4_8011C774,
};

unk_80077D50 sNameCardCaptainFalconCompTexInfo[] = {
    { 18, aNameCardCaptainFalconTex, TEX_WIDTH(aNameCardCaptainFalconTex), TEX_HEIGHT(aNameCardCaptainFalconTex),
      TEX_COMPRESSED_SIZE(aNameCardCaptainFalconTex) },
    { 0 }
};
unk_80077D50 sNameCardDrStewartCompTexInfo[] = { { 18, aNameCardDrStewartTex, TEX_WIDTH(aNameCardDrStewartTex),
                                                   TEX_HEIGHT(aNameCardDrStewartTex),
                                                   TEX_COMPRESSED_SIZE(aNameCardDrStewartTex) },
                                                 { 0 } };
unk_80077D50 sNameCardPicoCompTexInfo[] = { { 18, aNameCardPicoTex, TEX_WIDTH(aNameCardPicoTex),
                                              TEX_HEIGHT(aNameCardPicoTex), TEX_COMPRESSED_SIZE(aNameCardPicoTex) },
                                            { 0 } };
unk_80077D50 sNameCardSamuraiGorohCompTexInfo[] = { { 18, aNameCardSamuraiGorohTex, TEX_WIDTH(aNameCardSamuraiGorohTex),
                                                      TEX_HEIGHT(aNameCardSamuraiGorohTex),
                                                      TEX_COMPRESSED_SIZE(aNameCardSamuraiGorohTex) },
                                                    { 0 } };
unk_80077D50 sNameCardJodySummerCompTexInfo[] = { { 18, aNameCardJodySummerTex, TEX_WIDTH(aNameCardJodySummerTex),
                                                    TEX_HEIGHT(aNameCardJodySummerTex),
                                                    TEX_COMPRESSED_SIZE(aNameCardJodySummerTex) },
                                                  { 0 } };
unk_80077D50 sNameCardMrEadCompTexInfo[] = { { 18, aNameCardMrEadTex, TEX_WIDTH(aNameCardMrEadTex),
                                               TEX_HEIGHT(aNameCardMrEadTex), TEX_COMPRESSED_SIZE(aNameCardMrEadTex) },
                                             { 0 } };
unk_80077D50 sNameCardBabaCompTexInfo[] = { { 18, aNameCardBabaTex, TEX_WIDTH(aNameCardBabaTex),
                                              TEX_HEIGHT(aNameCardBabaTex), TEX_COMPRESSED_SIZE(aNameCardBabaTex) },
                                            { 0 } };
unk_80077D50 sNameCardOctomanCompTexInfo[] = { { 18, aNameCardOctomanTex, TEX_WIDTH(aNameCardOctomanTex),
                                                 TEX_HEIGHT(aNameCardOctomanTex),
                                                 TEX_COMPRESSED_SIZE(aNameCardOctomanTex) },
                                               { 0 } };
unk_80077D50 sNameCardGomarAndShiohCompTexInfo[] = {
    { 18, aNameCardGomarAndShiohTex, TEX_WIDTH(aNameCardGomarAndShiohTex), TEX_HEIGHT(aNameCardGomarAndShiohTex),
      TEX_COMPRESSED_SIZE(aNameCardGomarAndShiohTex) },
    { 0 }
};
unk_80077D50 sNameCardKateAlenCompTexInfo[] = { { 18, aNameCardKateAlenTex, TEX_WIDTH(aNameCardKateAlenTex),
                                                  TEX_HEIGHT(aNameCardKateAlenTex),
                                                  TEX_COMPRESSED_SIZE(aNameCardKateAlenTex) },
                                                { 0 } };
unk_80077D50 sNameCardRogerBusterCompTexInfo[] = { { 18, aNameCardRogerBusterTex, TEX_WIDTH(aNameCardRogerBusterTex),
                                                     TEX_HEIGHT(aNameCardRogerBusterTex),
                                                     TEX_COMPRESSED_SIZE(aNameCardRogerBusterTex) },
                                                   { 0 } };
unk_80077D50 sNameCardJamesMcCloudCompTexInfo[] = { { 18, aNameCardJamesMcCloudTex, TEX_WIDTH(aNameCardJamesMcCloudTex),
                                                      TEX_HEIGHT(aNameCardJamesMcCloudTex),
                                                      TEX_COMPRESSED_SIZE(aNameCardJamesMcCloudTex) },
                                                    { 0 } };
unk_80077D50 sNameCardLeonCompTexInfo[] = { { 18, aNameCardLeonTex, TEX_WIDTH(aNameCardLeonTex),
                                              TEX_HEIGHT(aNameCardLeonTex), TEX_COMPRESSED_SIZE(aNameCardLeonTex) },
                                            { 0 } };
unk_80077D50 sNameCardAntonioGusterCompTexInfo[] = {
    { 18, aNameCardAntonioGusterTex, TEX_WIDTH(aNameCardAntonioGusterTex), TEX_HEIGHT(aNameCardAntonioGusterTex),
      TEX_COMPRESSED_SIZE(aNameCardAntonioGusterTex) },
    { 0 }
};
unk_80077D50 sNameCardBlackShadowCompTexInfo[] = { { 18, aNameCardBlackShadowTex, TEX_WIDTH(aNameCardBlackShadowTex),
                                                     TEX_HEIGHT(aNameCardBlackShadowTex),
                                                     TEX_COMPRESSED_SIZE(aNameCardBlackShadowTex) },
                                                   { 0 } };
unk_80077D50 sNameCardMichaelChainCompTexInfo[] = { { 18, aNameCardMichaelChainTex, TEX_WIDTH(aNameCardMichaelChainTex),
                                                      TEX_HEIGHT(aNameCardMichaelChainTex),
                                                      TEX_COMPRESSED_SIZE(aNameCardMichaelChainTex) },
                                                    { 0 } };
unk_80077D50 sNameCardJackLevinCompTexInfo[] = { { 18, aNameCardJackLevinTex, TEX_WIDTH(aNameCardJackLevinTex),
                                                   TEX_HEIGHT(aNameCardJackLevinTex),
                                                   TEX_COMPRESSED_SIZE(aNameCardJackLevinTex) },
                                                 { 0 } };
unk_80077D50 sNameCardSuperArrowCompTexInfo[] = { { 18, aNameCardSuperArrowTex, TEX_WIDTH(aNameCardSuperArrowTex),
                                                    TEX_HEIGHT(aNameCardSuperArrowTex),
                                                    TEX_COMPRESSED_SIZE(aNameCardSuperArrowTex) },
                                                  { 0 } };
unk_80077D50 sNameCardMrsArrowCompTexInfo[] = { { 18, aNameCardMrsArrowTex, TEX_WIDTH(aNameCardMrsArrowTex),
                                                  TEX_HEIGHT(aNameCardMrsArrowTex),
                                                  TEX_COMPRESSED_SIZE(aNameCardMrsArrowTex) },
                                                { 0 } };
unk_80077D50 sNameCardJohnTanakaCompTexInfo[] = { { 18, aNameCardJohnTanakaTex, TEX_WIDTH(aNameCardJohnTanakaTex),
                                                    TEX_HEIGHT(aNameCardJohnTanakaTex),
                                                    TEX_COMPRESSED_SIZE(aNameCardJohnTanakaTex) },
                                                  { 0 } };
unk_80077D50 sNameCardBeastmanCompTexInfo[] = { { 18, aNameCardBeastmanTex, TEX_WIDTH(aNameCardBeastmanTex),
                                                  TEX_HEIGHT(aNameCardBeastmanTex),
                                                  TEX_COMPRESSED_SIZE(aNameCardBeastmanTex) },
                                                { 0 } };
unk_80077D50 sNameCardZodaCompTexInfo[] = { { 18, aNameCardZodaTex, TEX_WIDTH(aNameCardZodaTex),
                                              TEX_HEIGHT(aNameCardZodaTex), TEX_COMPRESSED_SIZE(aNameCardZodaTex) },
                                            { 0 } };
unk_80077D50 sNameCardDrClashCompTexInfo[] = { { 18, aNameCardDrClashTex, TEX_WIDTH(aNameCardDrClashTex),
                                                 TEX_HEIGHT(aNameCardDrClashTex),
                                                 TEX_COMPRESSED_SIZE(aNameCardDrClashTex) },
                                               { 0 } };
unk_80077D50 sNameCardSilverNeelsenCompTexInfo[] = {
    { 18, aNameCardSilverNeelsenTex, TEX_WIDTH(aNameCardSilverNeelsenTex), TEX_HEIGHT(aNameCardSilverNeelsenTex),
      TEX_COMPRESSED_SIZE(aNameCardSilverNeelsenTex) },
    { 0 }
};
unk_80077D50 sNameCardBioRexCompTexInfo[] = { { 18, aNameCardBioRexTex, TEX_WIDTH(aNameCardBioRexTex),
                                                TEX_HEIGHT(aNameCardBioRexTex),
                                                TEX_COMPRESSED_SIZE(aNameCardBioRexTex) },
                                              { 0 } };
unk_80077D50 sNameCardDraqCompTexInfo[] = { { 18, aNameCardDraqTex, TEX_WIDTH(aNameCardDraqTex),
                                              TEX_HEIGHT(aNameCardDraqTex), TEX_COMPRESSED_SIZE(aNameCardDraqTex) },
                                            { 0 } };
unk_80077D50 sNameCardBillyCompTexInfo[] = { { 18, aNameCardBillyTex, TEX_WIDTH(aNameCardBillyTex),
                                               TEX_HEIGHT(aNameCardBillyTex), TEX_COMPRESSED_SIZE(aNameCardBillyTex) },
                                             { 0 } };
unk_80077D50 sNameCardBloodFalconCompTexInfo[] = { { 18, aNameCardBloodFalconTex, TEX_WIDTH(aNameCardBloodFalconTex),
                                                     TEX_HEIGHT(aNameCardBloodFalconTex),
                                                     TEX_COMPRESSED_SIZE(aNameCardBloodFalconTex) },
                                                   { 0 } };
unk_80077D50 sNameCardMightyGazelleCompTexInfo[] = {
    { 18, aNameCardMightyGazelleTex, TEX_WIDTH(aNameCardMightyGazelleTex), TEX_HEIGHT(aNameCardMightyGazelleTex),
      TEX_COMPRESSED_SIZE(aNameCardMightyGazelleTex) },
    { 0 }
};
unk_80077D50 sNameCardTheSkullCompTexInfo[] = { { 18, aNameCardTheSkullTex, TEX_WIDTH(aNameCardTheSkullTex),
                                                  TEX_HEIGHT(aNameCardTheSkullTex),
                                                  TEX_COMPRESSED_SIZE(aNameCardTheSkullTex) },
                                                { 0 } };

unk_80077D50* sNameCardCompTexInfos[] = {
    sNameCardCaptainFalconCompTexInfo, // CAPTAIN_FALCON
    sNameCardDrStewartCompTexInfo,     // DR_STEWART
    sNameCardPicoCompTexInfo,          // PICO
    sNameCardSamuraiGorohCompTexInfo,  // SAMURAI_GOROH
    sNameCardJodySummerCompTexInfo,    // JODY_SUMMER
    sNameCardMightyGazelleCompTexInfo, // MIGHTY_GAZELLE
    sNameCardMrEadCompTexInfo,         // MR_EAD
    sNameCardBabaCompTexInfo,          // BABA
    sNameCardOctomanCompTexInfo,       // OCTOMAN
    sNameCardGomarAndShiohCompTexInfo, // GOMAR_AND_SHIOH
    sNameCardKateAlenCompTexInfo,      // KATE_ALEN
    sNameCardRogerBusterCompTexInfo,   // ROGER_BUSTER
    sNameCardJamesMcCloudCompTexInfo,  // JAMES_MCCLOUD
    sNameCardLeonCompTexInfo,          // LEON
    sNameCardAntonioGusterCompTexInfo, // ANTONIO_GUSTER
    sNameCardBlackShadowCompTexInfo,   // BLACK_SHADOW
    sNameCardMichaelChainCompTexInfo,  // MICHAEL_CHAIN
    sNameCardJackLevinCompTexInfo,     // JACK_LEVIN
    sNameCardSuperArrowCompTexInfo,    // SUPER_ARROW
    sNameCardMrsArrowCompTexInfo,      // MRS_ARROW
    sNameCardJohnTanakaCompTexInfo,    // JOHN_TANAKA
    sNameCardBeastmanCompTexInfo,      // BEASTMAN
    sNameCardZodaCompTexInfo,          // ZODA
    sNameCardDrClashCompTexInfo,       // DR_CLASH
    sNameCardSilverNeelsenCompTexInfo, // SILVER_NEELSEN
    sNameCardBioRexCompTexInfo,        // BIO_REX
    sNameCardDraqCompTexInfo,          // DRAQ
    sNameCardBillyCompTexInfo,         // BILLY
    sNameCardTheSkullCompTexInfo,      // THE_SKULL
    sNameCardBloodFalconCompTexInfo,   // BLOOD_FALCON
    sNameCardCaptainFalconCompTexInfo,
};

unk_800792D8 D_i4_8011CC70[] = { { sNameCardCaptainFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CC80[] = { { sNameCardDrStewartCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CC90[] = { { sNameCardPicoCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCA0[] = { { sNameCardSamuraiGorohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCB0[] = { { sNameCardJodySummerCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCC0[] = { { sNameCardMightyGazelleCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCD0[] = { { sNameCardMrEadCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCE0[] = { { sNameCardBabaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCF0[] = { { sNameCardOctomanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD00[] = { { sNameCardGomarAndShiohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD10[] = { { sNameCardKateAlenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD20[] = { { sNameCardRogerBusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD30[] = { { sNameCardJamesMcCloudCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD40[] = { { sNameCardLeonCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD50[] = { { sNameCardAntonioGusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD60[] = { { sNameCardBlackShadowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD70[] = { { sNameCardMichaelChainCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD80[] = { { sNameCardJackLevinCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD90[] = { { sNameCardSuperArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDA0[] = { { sNameCardMrsArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDB0[] = { { sNameCardJohnTanakaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDC0[] = { { sNameCardBeastmanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDD0[] = { { sNameCardZodaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDE0[] = { { sNameCardDrClashCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDF0[] = { { sNameCardSilverNeelsenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CE00[] = { { sNameCardBioRexCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CE10[] = { { sNameCardDraqCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CE20[] = { { sNameCardBillyCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CE30[] = { { sNameCardTheSkullCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8011CE40[] = { { sNameCardBloodFalconCompTexInfo, 60 }, { 0 } };

unk_800792D8* D_i4_8011CE50[] = {
    D_i4_8011CC70, D_i4_8011CC80, D_i4_8011CC90, D_i4_8011CCA0, D_i4_8011CCB0, D_i4_8011CCC0, D_i4_8011CCD0,
    D_i4_8011CCE0, D_i4_8011CCF0, D_i4_8011CD00, D_i4_8011CD10, D_i4_8011CD20, D_i4_8011CD30, D_i4_8011CD40,
    D_i4_8011CD50, D_i4_8011CD60, D_i4_8011CD70, D_i4_8011CD80, D_i4_8011CD90, D_i4_8011CDA0, D_i4_8011CDB0,
    D_i4_8011CDC0, D_i4_8011CDD0, D_i4_8011CDE0, D_i4_8011CDF0, D_i4_8011CE00, D_i4_8011CE10, D_i4_8011CE20,
    D_i4_8011CE30, D_i4_8011CE40, D_i4_8011CC70,
};

unk_80077D50 sSelectMachineCompTexInfo[] = {
    { 4, aSelectMachineTex, TEX_WIDTH(aSelectMachineTex), TEX_HEIGHT(aSelectMachineTex), 0 }, { 0 }
};
unk_80077D50 s1PIconCompTexInfo[] = {
    { 17, a1PIconTex, TEX_WIDTH(a1PIconTex), TEX_HEIGHT(a1PIconTex), TEX_COMPRESSED_SIZE(a1PIconTex) }, { 0 }
};
unk_80077D50 s2PIconCompTexInfo[] = {
    { 17, a2PIconTex, TEX_WIDTH(a2PIconTex), TEX_HEIGHT(a2PIconTex), TEX_COMPRESSED_SIZE(a2PIconTex) }, { 0 }
};
unk_80077D50 s3PIconCompTexInfo[] = {
    { 17, a3PIconTex, TEX_WIDTH(a3PIconTex), TEX_HEIGHT(a3PIconTex), TEX_COMPRESSED_SIZE(a3PIconTex) }, { 0 }
};
unk_80077D50 s4PIconCompTexInfo[] = {
    { 17, a4PIconTex, TEX_WIDTH(a4PIconTex), TEX_HEIGHT(a4PIconTex), TEX_COMPRESSED_SIZE(a4PIconTex) }, { 0 }
};

unk_80077D50* sPlayerNumIconCompTexInfos[] = {
    s1PIconCompTexInfo,
    s2PIconCompTexInfo,
    s3PIconCompTexInfo,
    s4PIconCompTexInfo,
};

unk_80077D50 sMachineSelectCursorCompTexInfo[] = { { 17, aMachineSelectCursorTex, TEX_WIDTH(aMachineSelectCursorTex),
                                                     TEX_HEIGHT(aMachineSelectCursorTex),
                                                     TEX_COMPRESSED_SIZE(aMachineSelectCursorTex) },
                                                   { 0 } };
unk_80077D50 sMachineInfoGraphCompTexInfo[] = { { 17, aMachineInfoGraphTex, TEX_WIDTH(aMachineInfoGraphTex),
                                                  TEX_HEIGHT(aMachineInfoGraphTex),
                                                  TEX_COMPRESSED_SIZE(aMachineInfoGraphTex) },
                                                { 0 } };
unk_80077D50 sMachineAccelerationMaxSpeedCompTexInfo[] = {
    { 17, aMachineAccelerationMaxSpeedTex, TEX_WIDTH(aMachineAccelerationMaxSpeedTex),
      TEX_HEIGHT(aMachineAccelerationMaxSpeedTex), TEX_COMPRESSED_SIZE(aMachineAccelerationMaxSpeedTex) },
    { 0 }
};
unk_80077D50 sMachineBodyBoostGripCompTexInfo[] = { { 17, aMachineBodyBoostGripTex, TEX_WIDTH(aMachineBodyBoostGripTex),
                                                      TEX_HEIGHT(aMachineBodyBoostGripTex),
                                                      TEX_COMPRESSED_SIZE(aMachineBodyBoostGripTex) },
                                                    { 0 } };
unk_80077D50 sMachineInfoGraphSmallCompTexInfo[] = {
    { 18, aMachineInfoGraphSmallTex, TEX_WIDTH(aMachineInfoGraphSmallTex), TEX_HEIGHT(aMachineInfoGraphSmallTex),
      TEX_COMPRESSED_SIZE(aMachineInfoGraphSmallTex) },
    { 0 }
};
unk_80077D50 sMachineAccelerationMaxSpeedSmallCompTexInfo[] = {
    { 18, aMachineAccelerationMaxSpeedSmallTex, TEX_WIDTH(aMachineAccelerationMaxSpeedSmallTex),
      TEX_HEIGHT(aMachineAccelerationMaxSpeedSmallTex), TEX_COMPRESSED_SIZE(aMachineAccelerationMaxSpeedSmallTex) },
    { 0 }
};
unk_80077D50 sMachineBodyBoostGripSmallCompTexInfo[] = {
    { 17, aMachineBodyBoostGripSmallTex, TEX_WIDTH(aMachineBodyBoostGripSmallTex),
      TEX_HEIGHT(aMachineBodyBoostGripSmallTex), TEX_COMPRESSED_SIZE(aMachineBodyBoostGripSmallTex) },
    { 0 }
};
unk_80077D50 sEngineSliderCompTexInfo[] = { { 17, aEngineSliderTex, TEX_WIDTH(aEngineSliderTex),
                                              TEX_HEIGHT(aEngineSliderTex), TEX_COMPRESSED_SIZE(aEngineSliderTex) },
                                            { 0 } };
unk_80077D50 sNoviceJackTrophyCompTexInfo[] = { { 17, aNoviceJackTrophyTex, TEX_WIDTH(aNoviceJackTrophyTex),
                                                  TEX_HEIGHT(aNoviceJackTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aNoviceJackTrophyTex) },
                                                { 0 } };
unk_80077D50 sNoviceQueenTrophyCompTexInfo[] = { { 17, aNoviceQueenTrophyTex, TEX_WIDTH(aNoviceQueenTrophyTex),
                                                   TEX_HEIGHT(aNoviceQueenTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aNoviceQueenTrophyTex) },
                                                 { 0 } };
unk_80077D50 sNoviceKingTrophyCompTexInfo[] = { { 17, aNoviceKingTrophyTex, TEX_WIDTH(aNoviceKingTrophyTex),
                                                  TEX_HEIGHT(aNoviceKingTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aNoviceKingTrophyTex) },
                                                { 0 } };
unk_80077D50 sNoviceJokerTrophyCompTexInfo[] = { { 17, aNoviceJokerTrophyTex, TEX_WIDTH(aNoviceJokerTrophyTex),
                                                   TEX_HEIGHT(aNoviceJokerTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aNoviceJokerTrophyTex) },
                                                 { 0 } };
unk_80077D50 sNoviceXTrophyCompTexInfo[] = { { 17, aNoviceXTrophyTex, TEX_WIDTH(aNoviceXTrophyTex),
                                               TEX_HEIGHT(aNoviceXTrophyTex), TEX_COMPRESSED_SIZE(aNoviceXTrophyTex) },
                                             { 0 } };
unk_80077D50 sStandardJackTrophyCompTexInfo[] = { { 17, aStandardJackTrophyTex, TEX_WIDTH(aStandardJackTrophyTex),
                                                    TEX_HEIGHT(aStandardJackTrophyTex),
                                                    TEX_COMPRESSED_SIZE(aStandardJackTrophyTex) },
                                                  { 0 } };
unk_80077D50 sStandardQueenTrophyCompTexInfo[] = { { 17, aStandardQueenTrophyTex, TEX_WIDTH(aStandardQueenTrophyTex),
                                                     TEX_HEIGHT(aStandardQueenTrophyTex),
                                                     TEX_COMPRESSED_SIZE(aStandardQueenTrophyTex) },
                                                   { 0 } };
unk_80077D50 sStandardKingTrophyCompTexInfo[] = { { 17, aStandardKingTrophyTex, TEX_WIDTH(aStandardKingTrophyTex),
                                                    TEX_HEIGHT(aStandardKingTrophyTex),
                                                    TEX_COMPRESSED_SIZE(aStandardKingTrophyTex) },
                                                  { 0 } };
unk_80077D50 sStandardJokerTrophyCompTexInfo[] = { { 17, aStandardJokerTrophyTex, TEX_WIDTH(aStandardJokerTrophyTex),
                                                     TEX_HEIGHT(aStandardJokerTrophyTex),
                                                     TEX_COMPRESSED_SIZE(aStandardJokerTrophyTex) },
                                                   { 0 } };
unk_80077D50 sStandardXTrophyCompTexInfo[] = { { 17, aStandardXTrophyTex, TEX_WIDTH(aStandardXTrophyTex),
                                                 TEX_HEIGHT(aStandardXTrophyTex),
                                                 TEX_COMPRESSED_SIZE(aStandardXTrophyTex) },
                                               { 0 } };
unk_80077D50 sExpertJackTrophyCompTexInfo[] = { { 17, aExpertJackTrophyTex, TEX_WIDTH(aExpertJackTrophyTex),
                                                  TEX_HEIGHT(aExpertJackTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aExpertJackTrophyTex) },
                                                { 0 } };
unk_80077D50 sExpertQueenTrophyCompTexInfo[] = { { 17, aExpertQueenTrophyTex, TEX_WIDTH(aExpertQueenTrophyTex),
                                                   TEX_HEIGHT(aExpertQueenTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aExpertQueenTrophyTex) },
                                                 { 0 } };
unk_80077D50 sExpertKingTrophyCompTexInfo[] = { { 17, aExpertKingTrophyTex, TEX_WIDTH(aExpertKingTrophyTex),
                                                  TEX_HEIGHT(aExpertKingTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aExpertKingTrophyTex) },
                                                { 0 } };
unk_80077D50 sExpertJokerTrophyCompTexInfo[] = { { 17, aExpertJokerTrophyTex, TEX_WIDTH(aExpertJokerTrophyTex),
                                                   TEX_HEIGHT(aExpertJokerTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aExpertJokerTrophyTex) },
                                                 { 0 } };
unk_80077D50 sExpertXTrophyCompTexInfo[] = { { 17, aExpertXTrophyTex, TEX_WIDTH(aExpertXTrophyTex),
                                               TEX_HEIGHT(aExpertXTrophyTex), TEX_COMPRESSED_SIZE(aExpertXTrophyTex) },
                                             { 0 } };
unk_80077D50 sMasterJackTrophyCompTexInfo[] = { { 17, aMasterJackTrophyTex, TEX_WIDTH(aMasterJackTrophyTex),
                                                  TEX_HEIGHT(aMasterJackTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aMasterJackTrophyTex) },
                                                { 0 } };
unk_80077D50 sMasterQueenTrophyCompTexInfo[] = { { 17, aMasterQueenTrophyTex, TEX_WIDTH(aMasterQueenTrophyTex),
                                                   TEX_HEIGHT(aMasterQueenTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aMasterQueenTrophyTex) },
                                                 { 0 } };
unk_80077D50 sMasterKingTrophyCompTexInfo[] = { { 17, aMasterKingTrophyTex, TEX_WIDTH(aMasterKingTrophyTex),
                                                  TEX_HEIGHT(aMasterKingTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aMasterKingTrophyTex) },
                                                { 0 } };
unk_80077D50 sMasterJokerTrophyCompTexInfo[] = { { 17, aMasterJokerTrophyTex, TEX_WIDTH(aMasterJokerTrophyTex),
                                                   TEX_HEIGHT(aMasterJokerTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aMasterJokerTrophyTex) },
                                                 { 0 } };
unk_80077D50 sMasterXTrophyCompTexInfo[] = { { 17, aMasterXTrophyTex, TEX_WIDTH(aMasterXTrophyTex),
                                               TEX_HEIGHT(aMasterXTrophyTex), TEX_COMPRESSED_SIZE(aMasterXTrophyTex) },
                                             { 0 } };
unk_80077D50 sNoTrophyCompTexInfo[] = {
    { 17, aNoTrophyTex, TEX_WIDTH(aNoTrophyTex), TEX_HEIGHT(aNoTrophyTex), TEX_COMPRESSED_SIZE(aNoTrophyTex) }, { 0 }
};

unk_80077D50* sTrophyCompTexInfos[] = {
    sNoviceJackTrophyCompTexInfo,    sNoviceQueenTrophyCompTexInfo,  sNoviceKingTrophyCompTexInfo,
    sNoviceJokerTrophyCompTexInfo,   sNoviceXTrophyCompTexInfo,      sStandardJackTrophyCompTexInfo,
    sStandardQueenTrophyCompTexInfo, sStandardKingTrophyCompTexInfo, sStandardJokerTrophyCompTexInfo,
    sStandardXTrophyCompTexInfo,     sExpertJackTrophyCompTexInfo,   sExpertQueenTrophyCompTexInfo,
    sExpertKingTrophyCompTexInfo,    sExpertJokerTrophyCompTexInfo,  sExpertXTrophyCompTexInfo,
    sMasterJackTrophyCompTexInfo,    sMasterQueenTrophyCompTexInfo,  sMasterKingTrophyCompTexInfo,
    sMasterJokerTrophyCompTexInfo,   sMasterXTrophyCompTexInfo,      sNoTrophyCompTexInfo,
};

static unk_80077D50 sNoviceCompTexInfo[] = {
    { 17, aNoviceTex, TEX_WIDTH(aNoviceTex), TEX_HEIGHT(aNoviceTex), TEX_COMPRESSED_SIZE(aNoviceTex) }, { 0 }
};
static unk_80077D50 sStandardCompTexInfo[] = {
    { 17, aStandardTex, TEX_WIDTH(aStandardTex), TEX_HEIGHT(aStandardTex), TEX_COMPRESSED_SIZE(aStandardTex) }, { 0 }
};
static unk_80077D50 sExpertCompTexInfo[] = {
    { 17, aExpertTex, TEX_WIDTH(aExpertTex), TEX_HEIGHT(aExpertTex), TEX_COMPRESSED_SIZE(aExpertTex) }, { 0 }
};
static unk_80077D50 sMasterCompTexInfo[] = {
    { 17, aMasterTex, TEX_WIDTH(aMasterTex), TEX_HEIGHT(aMasterTex), TEX_COMPRESSED_SIZE(aMasterTex) }, { 0 }
};

static unk_80077D50* sDifficultyCompTexInfos[] = {
    sNoviceCompTexInfo,
    sStandardCompTexInfo,
    sExpertCompTexInfo,
    sMasterCompTexInfo,
};

unk_80077D50 sBoostCompTexInfo[] = {
    { 17, aBoostTex, TEX_WIDTH(aBoostTex), TEX_HEIGHT(aBoostTex), TEX_COMPRESSED_SIZE(aBoostTex) }, { 0 }
};
unk_80077D50 sBodyCompTexInfo[] = {
    { 17, aBodyTex, TEX_WIDTH(aBodyTex), TEX_HEIGHT(aBodyTex), TEX_COMPRESSED_SIZE(aBodyTex) }, { 0 }
};
unk_80077D50 sGripCompTexInfo[] = {
    { 17, aGripTex, TEX_WIDTH(aGripTex), TEX_HEIGHT(aGripTex), TEX_COMPRESSED_SIZE(aGripTex) }, { 0 }
};

unk_80077D50* sMachineStatCompTexInfos[] = {
    sBodyCompTexInfo,
    sBoostCompTexInfo,
    sGripCompTexInfo,
};

static unk_80077D50 sOKCompTexInfo[] = {
    { 17, aOKTex, TEX_WIDTH(aOKTex), TEX_HEIGHT(aOKTex), TEX_COMPRESSED_SIZE(aOKTex) }, { 0 }
};

const char* sMachineStatValues[] = { "a", "b", "c", "d", "e" };

UNUSED s32 D_i4_8011D4A0[] = { 100, 218, 252, 221 };

s32 D_i4_8011D4B0 = -4;
s32 D_i4_8011D4B4 = 10;
s32 D_i4_8011D4B8 = -6;
s32 D_i4_8011D4BC = 14;

UNUSED s32 D_i4_8011D4C0[] = { 0, 0, 0, 10, 0, 40 };

UNUSED f32 D_i4_8011D4D8 = 1.2f;

s16 D_i4_8011D4DC = 60; // alpha

s32 D_i4_8011D4E0 = 2600; // texture scale

s8 D_i4_8011D4E4[] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

const s32 D_i4_8011D674[] = { -4, 0, -6, -24, 2, -1, 5, -25 };

const s32 D_i4_8011D694[] = { 19, 60, 19, 136, 299, 60, 299, 136, 42, 10, 42, 120 };

const s32 D_i4_8011D6C4[] = { 25, 20, 25, 125, 164, 20, 164, 125 };

extern s16 D_800CCFE8;
extern s32 gSelectedMode;
extern s8 gPlayerSelectionLock[];
extern s32 gMachineSelectState;
extern s8 gSettingEverythingUnlocked;
extern f32 D_800CE748;
extern f32 D_800CE74C;
extern f32 D_800CE750;
extern s32 gNumPlayers;

void MachineSelect_Init(void) {
    s32 i;

    D_800CCFE8 = 3;
    D_800CE750 = 0.1f;
    D_800CE74C = D_800CE750;
    D_800CE748 = D_800CE74C;
    func_80085610();
    func_8008969C();
    gMachineSelectState = MACHINE_SELECT_ACTIVE;

    for (i = 0; i < 4; i++) {
        gPlayerSelectionLock[i] = SELECTION_FREE;
        sMachineSelectIndex[i] = func_8007E11C(gRacers[i].character);
    }
    sMachinesUnlocked = ((func_8007E008() / 3) * 6) + 6;
    if (gSettingEverythingUnlocked != 0) {
        sMachinesUnlocked = 30;
    }
    if (sMachinesUnlocked > 30) {
        sMachinesUnlocked = 30;
    }
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_MACHINE_SELECT_BACKGROUND, 0, 0, 4);
    Object_Init(OBJECT_MACHINE_SELECT_HEADER, 80, 13, 4);
    Object_Init(OBJECT_MACHINE_SELECT_CURSOR, 60, 10, 8);
    Object_Init(OBJECT_MACHINE_SELECT_CAR, 0, 0, 10);

    switch (gNumPlayers) {
        case 4:
            Object_Init(OBJECT_MACHINE_SELECT_STATS_3, 0, 0, 12);
            Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_3, 60, 10, 12);
            Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_3, 260, 190, 6);
            /* fallthrough */
        case 3:
            Object_Init(OBJECT_MACHINE_SELECT_STATS_2, 0, 0, 12);
            Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_2, 60, 10, 12);
            Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_2, 260, 10, 6);
            /* fallthrough */
        case 2:
            Object_Init(OBJECT_MACHINE_SELECT_STATS_1, 0, 0, 12);
            Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_1, 60, 10, 12);
            Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_1, 20, 190, 6);
            /* fallthrough */
        case 1:
            break;
    }

    if (gSelectedMode == MODE_GP_RACE) {
        Object_Init(OBJECT_MACHINE_SELECT_DIFFICULTY_CUPS, 0, 0, 12);
    }
    Object_Init(OBJECT_MACHINE_SELECT_STATS_0, 0, 0, 12);
    Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_0, 60, 10, 12);
    Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_0, 20, 10, 6);

    if (gNumPlayers == 1) {
        Object_Init(OBJECT_MACHINE_SELECT_NAME, 0, 0, 12);
    }

    Object_Init(OBJECT_MACHINE_SELECT_OK, 0, 0, 12);
}

extern s32 gMachineSettingsState;
extern s32 gGameMode;
extern s32 gCourseIndex;
extern f32 gCharacterLastEngine[];
extern f32 gPlayerEngine[];

void MachineSettings_Init(void) {
    s32 i;

    D_800CCFE8 = 3;
    func_80085610();
    func_8008969C();
    gMachineSettingsState = MACHINE_SETTINGS_ACTIVE;

    for (i = 0; i < 4; i++) {
        gPlayerSelectionLock[i] = SELECTION_FREE;
        if (gGameMode != GAMEMODE_FLX_GP_RACE_NEXT_MACHINE_SETTINGS) {
            gPlayerEngine[i] = 0.5f;
        }
    }

    if ((gNumPlayers == 1) && (gCourseIndex < COURSE_EDIT_1)) {
        Save_UpdateCharacterSave(gCourseIndex);
        gPlayerEngine[0] = gCharacterLastEngine[gRacers[0].character];
    }

    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_MACHINE_SETTINGS_BACKGROUND, 0, 0, 4);
    Object_Init(OBJECT_MACHINE_SETTINGS_NAME, 0, 0, 12);
    Object_Init(OBJECT_MACHINE_SETTINGS_ENGINE_WEIGHT, 160, 34, 10);
    Object_Init(OBJECT_MACHINE_SETTINGS_STATS, 160, 97, 10);
    if (gNumPlayers == 2) {
        Object_Init(OBJECT_58, 160, 97, 13);
    }
    Object_Init(OBJECT_MACHINE_SETTINGS_CAR, 0, 0, 12);
    Object_Init(OBJECT_MACHINE_SETTINGS_NAME_CARD, 20, 185, 12);
    Object_Init(OBJECT_MACHINE_SETTINGS_SLIDER, 208, 85, 11);
    Object_Init(OBJECT_MACHINE_SETTINGS_OK, 0, 0, 14);

    switch (gNumPlayers) {
        case 4:
            Object_Init(OBJECT_MACHINE_SETTINGS_PORTRAIT_3, -6, -5, 8);
            /* fallthrough */
        case 3:
            Object_Init(OBJECT_MACHINE_SETTINGS_PORTRAIT_2, -6, -5, 8);
            /* fallthrough */
        case 2:
            Object_Init(OBJECT_MACHINE_SETTINGS_SPLITSCREEN_BARS, 0, 0, 6);
            Object_Init(OBJECT_MACHINE_SETTINGS_PORTRAIT_1, -6, -5, 8);
            /* fallthrough */
        case 1:
            Object_Init(OBJECT_MACHINE_SETTINGS_PORTRAIT_0, -6, -5, 8);
            break;
    }
}

extern Controller gSharedController;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;
extern s32 gPlayerControlPorts[];
extern Controller gControllers[];
extern s8 D_800CD3AC[];

s32 MachineSelect_Update(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 pad;
    s16 pad2;
    s16 lastMachineIndex;

    func_8008675C();

    for (i = 3; i >= 0; i--) {

        Controller_SetGlobalInputs(&gControllers[gPlayerControlPorts[i]]);
        if (i >= gNumPlayers) {
            if ((gInputButtonPressed & BTN_B) && (gMachineSelectState == MACHINE_SELECT_ACTIVE)) {
                func_800BA8D8(0x10);
                gMachineSelectState = MACHINE_SELECT_EXIT;
                if (gSelectedMode == MODE_DEATH_RACE) {
                    return GAMEMODE_FLX_MAIN_MENU;
                }
                // FAKE
                if ((gRacers + i)->character) {}
                return GAMEMODE_FLX_COURSE_SELECT;
            }
            continue;
        }

        // Setup Mini Cars
        if (gInputButtonPressed & (BTN_L | BTN_R | BTN_CLEFT | BTN_CDOWN)) {
            if ((gSharedController.buttonCurrent & BTN_L) && (gSharedController.buttonCurrent & BTN_R) &&
                (gSharedController.buttonCurrent & BTN_CLEFT) && (gSharedController.buttonCurrent & BTN_CDOWN) &&
                (CAR_MINI_STATE(Object_Get(OBJECT_MACHINE_SELECT_CAR)) == 0) &&
                (gMachineSelectState != MACHINE_SELECT_CONTINUE)) {
                CAR_MINI_STATE(Object_Get(OBJECT_MACHINE_SELECT_CAR)) = 1;
                D_i4_8011D778 = 1.0f;
                D_i4_8011D77C = 0.0f;
                func_800BA8D8(0x17);
                return gGameMode;
            }
        }

        switch (gMachineSelectState) {
            case MACHINE_SELECT_ACTIVE:
                lastMachineIndex = sMachineSelectIndex[i];

                if (gPlayerSelectionLock[i] == SELECTION_FREE) {
                    if (gInputPressed & BTN_LEFT) {
                        if (sMachineSelectIndex[i] % 6) {
                            sMachineSelectIndex[i]--;
                        } else {
                            sMachineSelectIndex[i] += 5;
                        }
                    } else if (gInputPressed & BTN_RIGHT) {
                        if ((sMachineSelectIndex[i] % 6) < 5) {
                            sMachineSelectIndex[i]++;
                        } else {
                            sMachineSelectIndex[i] -= 5;
                        }
                    }
                    if (gInputPressed & BTN_UP) {
                        sMachineSelectIndex[i] -= 6;
                    } else if (gInputPressed & BTN_DOWN) {
                        sMachineSelectIndex[i] += 6;
                    }
                }

                sMachineSelectIndex[i] += sMachinesUnlocked;
                sMachineSelectIndex[i] %= sMachinesUnlocked;
                gRacers[i].character = func_8007E10C(sMachineSelectIndex[i]);

                if (lastMachineIndex != sMachineSelectIndex[i]) {
                    func_800BA710(i, 0x1E);
                    D_800CD3AC[i] = 1;
                    gPlayerEngine[i] = 0.5f;
                }

                if (gInputButtonPressed & BTN_B) {
                    func_800BA710(i, 0x10);

                    if (gPlayerSelectionLock[i] != SELECTION_FREE) {
                        gPlayerSelectionLock[i] = SELECTION_FREE;
                    } else {
                        gMachineSelectState = MACHINE_SELECT_EXIT;
                        if (gSelectedMode == MODE_DEATH_RACE) {
                            return GAMEMODE_FLX_MAIN_MENU;
                        }
                        return GAMEMODE_FLX_COURSE_SELECT;
                    }
                } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    if (gPlayerSelectionLock[i] == SELECTION_FREE) {
                        gPlayerSelectionLock[i] = SELECTION_LOCKED;
                        if (D_800CD3AC[i] != 0) {
                            D_800CD3AC[i] = 0;
                            for (j = 0; j < gNumPlayers; j++) {
                                for (k = 0; k < 4; k++) {
                                    if (i != k && gRacers[k].character == gRacers[i].character && D_800CD3AC[k] == 0 &&
                                        j == gRacers[k].unk_2CC) {
                                        break;
                                    }
                                }

                                if (k >= 4) {
                                    gRacers[i].unk_2CC = j;
                                    break;
                                }
                            }
                            if (j >= 4) {
                                gRacers[i].unk_2CC = 0;
                            }
                        }
                        func_800BA710(i, 0x21);
                    }
                }

                for (j = 0, k = 0; j < gNumPlayers; j++) {
                    if (gPlayerSelectionLock[j] == SELECTION_FREE) {
                        k++;
                        break;
                    }
                }

                if (k == 0) {
                    gMachineSelectState = MACHINE_SELECT_AWAIT_OK;
                }
                break;
            case 2:
                if (gInputButtonPressed & BTN_B) {
                    gPlayerSelectionLock[i] = SELECTION_FREE;
                    gMachineSelectState = MACHINE_SELECT_ACTIVE;
                    func_800BA710(i, 0x10);
                    break;
                }
                if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    func_800BA710(i, 0x3E);
                    gMachineSelectState = MACHINE_SELECT_CONTINUE;
                    return GAMEMODE_LX_MACHINE_SETTINGS;
                }
                break;
        }
    }
    return gGameMode;
}

extern s32 D_i2_80106DA4;

s32 MachineSettings_Update(void) {
    s32 i;
    s32 j;
    s32 k;
    Controller* temp_s1;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 var_fa1;
    s32 stickX;

    func_8008675C();
    if (D_i2_80106DA4 != 0) {
        return gGameMode;
    }

    for (i = gNumPlayers - 1; i >= 0; i--) {
        temp_s1 = &gControllers[gPlayerControlPorts[i]];
        Controller_SetGlobalInputs(temp_s1);

        switch (gMachineSettingsState) {
            case MACHINE_SETTINGS_ACTIVE:
                if (gPlayerSelectionLock[i] == SELECTION_FREE) {

                    k = gRacers[i].unk_2CC;

                    if (gInputButtonPressed & BTN_Z) {
                        gRacers[i].unk_2CC--;
                        gRacers[i].unk_2CC &= 3;
                    }
                    if (gInputButtonPressed & BTN_R) {
                        gRacers[i].unk_2CC++;
                        gRacers[i].unk_2CC &= 3;
                    }
                    if (k != gRacers[i].unk_2CC) {
                        func_800BA710(i, 0x1E);
                    }
                    stickX = temp_s1->stickX;
                    temp_fa0 = gPlayerEngine[i];
                    temp_fv0 = (f32) stickX * 0.003;
                    var_fa1 = SQ(temp_fv0);
                    if (var_fa1 < 0.001) {
                        var_fa1 = 0.0078125f;
                        stickX = 0;
                        if (gInputPressed & BTN_LEFT) {
                            stickX = -1;
                        } else if (!(gInputPressed & BTN_RIGHT)) {
                            var_fa1 = 0.0f;
                        }
                    }
                    if (stickX < 0) {
                        gPlayerEngine[i] -= var_fa1;
                        if (gPlayerEngine[i] < 0.0) {
                            gPlayerEngine[i] = 0.0f;
                        }
                    } else {
                        gPlayerEngine[i] += var_fa1;
                        if (gPlayerEngine[i] > 1.0) {
                            gPlayerEngine[i] = 1.0f;
                        }
                    }
                    if ((s32) (temp_fa0 / 0.1f) != (s32) (gPlayerEngine[i] / 0.1f)) {
                        func_800BA710(i, 0x16);
                    }
                    if (gNumPlayers == 1) {
                        gCharacterLastEngine[gRacers[0].character] = gPlayerEngine[0];
                    }
                }
                if (gInputButtonPressed & BTN_B) {
                    func_800BA710(i, 0x10);

                    if (gPlayerSelectionLock[i] != SELECTION_FREE) {
                        gPlayerSelectionLock[i] = SELECTION_FREE;
                    } else {
                        gMachineSettingsState = MACHINE_SETTINGS_EXIT;
                        if (gGameMode == GAMEMODE_LX_MACHINE_SETTINGS) {
                            return GAMEMODE_FLX_MACHINE_SELECT;
                        }
                        return GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
                    }
                } else if ((gInputButtonPressed & (BTN_A | BTN_START)) && (gPlayerSelectionLock[i] == SELECTION_FREE)) {
                    func_800BA710(i, 0x21);
                    gPlayerSelectionLock[i] = SELECTION_LOCKED;
                }

                for (k = 0, j = 0; j < gNumPlayers; j++) {
                    if (gPlayerSelectionLock[j] == SELECTION_FREE) {
                        k++;
                        break;
                    }
                }

                if (k == 0) {
                    gMachineSettingsState = MACHINE_SETTINGS_AWAIT_OK;
                }
                break;
            case MACHINE_SETTINGS_AWAIT_OK:
                if (gInputButtonPressed & BTN_B) {
                    gPlayerSelectionLock[i] = SELECTION_FREE;
                    gMachineSettingsState = MACHINE_SETTINGS_ACTIVE;
                    func_800BA710(i, 0x10);
                } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    func_800BA710(i, 0x3E);
                    func_8007E0CC();
                    gMachineSettingsState = MACHINE_SETTINGS_CONTINUE;
                    switch (gSelectedMode) {
                        case MODE_GP_RACE:
                            return GAMEMODE_GP_RACE;
                        case MODE_TIME_ATTACK:
                            return GAMEMODE_TIME_ATTACK;
                        case MODE_PRACTICE:
                            return GAMEMODE_PRACTICE;
                        case MODE_VS_BATTLE:
                            return gNumPlayers + 1;
                        case MODE_DEATH_RACE:
                            return GAMEMODE_DEATH_RACE;
                    }
                }
            case MACHINE_SETTINGS_EXIT:
            case MACHINE_SETTINGS_CONTINUE:
            default:
                break;
        }
    }

    return gGameMode;
}

extern s32 gQueuedGameMode;

Gfx* MachineSelect_Draw(Gfx* gfx) {
    gfx = Object_UpdateAndDrawAll(gfx);
    func_800790D4();
    if (gGameMode != gQueuedGameMode) {
        func_80089724();
    }
    return gfx;
}

Gfx* MachineSettings_Draw(Gfx* gfx) {
    gfx = Object_UpdateAndDrawAll(gfx);
    func_800790D4();
    if (gGameMode != gQueuedGameMode) {
        func_80089724();
    }
    return gfx;
}

s32 MachineSettings_GetCharacter(s32 character) {
    return character;
}

void MachineSelect_HeaderInit(void) {
    func_80077D50(sSelectMachineCompTexInfo, 0);
}

void func_i4_80116E8C(Object* arg0) {
    s32 i;

    if (gNumPlayers == 1) {
        func_80077D50(sPortraitCompTexInfos[gRacers[0].character], 0);
        return;
    }

    for (i = 0; i < gNumPlayers; i++) {
        func_80077D50(sSmallPortraitCompTexInfos[gRacers[i].character], 0);
    }
}

void MachineSettings_PortraitInit(Object* portraitObj) {
    s32 playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SETTINGS_PORTRAIT_0;

    OBJECT_STATE(portraitObj) = gRacers[playerIndex].character;
    OBJECT_STATE(portraitObj) = MachineSettings_GetCharacter(OBJECT_STATE(portraitObj));

    if (gNumPlayers == 1) {
        func_80077D50(sPortraitBackgroundCompTexInfo, 0);
        OBJECT_CACHE_INDEX(portraitObj) = func_800792D8(D_i4_8011C05C[OBJECT_STATE(portraitObj)]);
    } else {
        OBJECT_CACHE_INDEX(portraitObj) = func_800792D8(D_i4_8011C7A4[OBJECT_STATE(portraitObj)]);
    }
}

void MachineSelect_PortraitInit(Object* portraitObj) {
    OBJECT_CACHE_INDEX(portraitObj) = func_800792D8(D_i4_8011C7A4[0]);
}

void MachineSelect_CursorNumInit(Object* cursorNumObj) {
    func_80077D50(sPlayerNumIconCompTexInfos[cursorNumObj->cmdId - OBJECT_MACHINE_SELECT_CURSOR_NUM_0], 0);
}

void MachineSelect_CursorInit(void) {
    func_80077D50(sMachineSelectCursorCompTexInfo, 0);
}

void MachineSelect_CarInit(Object* carObj) {
    Vp* vp;
    s32 i;
    s32 j;

    vp = (Vp*) func_800768F4(0, 30 * sizeof(Vp));
    CAR_VIEWPORT(carObj) = vp;

    for (i = 0; i < 30; i++) {
        vp[i].vp.vscale[0] = 640;
        vp[i].vp.vscale[1] = 480;
        vp[i].vp.vscale[2] = 0x1FF;
        vp[i].vp.vscale[3] = 0;
        vp[i].vp.vtrans[0] = (((i % 6) * 0x28) + 0x39) << 2;
        vp[i].vp.vtrans[1] = (((i / 6) * 0x22) + 0x39) << 2;
        vp[i].vp.vtrans[2] = 0x1FF;
        vp[i].vp.vtrans[3] = 0;
    }

    for (j = 3; j >= 0; j--) {
        gRacers[j].unk_0C.unk_34.x = gRacers[j].unk_0C.unk_34.y = gRacers[j].unk_0C.unk_34.z = 0.0f;
        gRacers[j].unk_C0.x.z = 1.0f;
        gRacers[j].unk_C0.y.y = 1.0f;
        gRacers[j].unk_C0.z.x = 1.0f;
        gRacers[j].unk_C0.x.x = 0.0f;
        gRacers[j].unk_C0.y.z = 0.0f;
        gRacers[j].unk_C0.z.y = 0.0f;
        gRacers[j].unk_C0.x.y = 0.0f;
        gRacers[j].unk_C0.y.x = 0.0f;
        gRacers[j].unk_C0.z.z = 0.0f;
    }
}

void MachineSettings_CarInit(Object* carObj) {
    Vp* vp;
    s32 i;
    s32 j;
    s32 k;

    vp = (Vp*) func_800768F4(0, 2 * 4 * sizeof(Vp));
    CAR_VIEWPORT(carObj) = vp;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            vp[i * 4 + j].vp.vscale[0] = 0x280;
            vp[i * 4 + j].vp.vscale[1] = 0x1E0;
            vp[i * 4 + j].vp.vscale[2] = 0x1FF;
            vp[i * 4 + j].vp.vscale[3] = 0;

            switch (gNumPlayers) {
                case 1:
                    vp[i * 4 + j].vp.vtrans[0] = ((i * -4) + 0xDC) << 2;
                    vp[i * 4 + j].vp.vtrans[1] = ((i * 0xA) + 0xC8) << 2;
                    break;
                case 2:
                    vp[i * 4 + j].vp.vtrans[0] = ((i * -6) + 0xE9) << 2;
                    vp[i * 4 + j].vp.vtrans[1] = (((j % 2) * 0x69) + (i * 0xE) + 0x50) << 2;
                    break;
                default:
                    vp[i * 4 + j].vp.vtrans[0] = (((j / 2) * 0x8C) + (i * -2) + 0x2B) << 2;
                    vp[i * 4 + j].vp.vtrans[1] = (((j % 2) * 0x69) + (i * 5) + 0x35) << 2;
                    break;
            }

            vp[i * 4 + j].vp.vtrans[2] = 0x1FF;
            vp[i * 4 + j].vp.vtrans[3] = 0;
        }
    }

    for (k = 3; k >= 0; k--) {
        gRacers[k].unk_0C.unk_34.x = gRacers[k].unk_0C.unk_34.y = gRacers[k].unk_0C.unk_34.z = 0.0f;
        gRacers[k].unk_C0.x.z = 1.0f;
        gRacers[k].unk_C0.y.y = 1.0f;
        gRacers[k].unk_C0.z.x = 1.0f;
        gRacers[k].unk_C0.x.x = 0.0f;
        gRacers[k].unk_C0.y.z = 0.0f;
        gRacers[k].unk_C0.z.y = 0.0f;
        gRacers[k].unk_C0.x.y = 0.0f;
        gRacers[k].unk_C0.y.x = 0.0f;
        gRacers[k].unk_C0.z.z = 0.0f;
    }
}

void MachineSettings_EngineWeightInit(void) {
    if (gNumPlayers == 1) {
        func_80077D50(sMachineInfoGraphCompTexInfo, 0);
        func_80077D50(sMachineAccelerationMaxSpeedCompTexInfo, 0);
    } else {
        func_80077D50(sMachineInfoGraphSmallCompTexInfo, 0);
        func_80077D50(sMachineAccelerationMaxSpeedSmallCompTexInfo, 0);
    }
}

void MachineSettings_StatsInit(void) {
    if (gNumPlayers == 1) {
        func_80077D50(sMachineBodyBoostGripCompTexInfo, 0);
    } else {
        func_80077D50(sMachineBodyBoostGripSmallCompTexInfo, 0);
    }
}

void MachineSettings_NameCardInit(Object* nameCardObj) {
    if (gNumPlayers == 1) {
        OBJECT_CACHE_INDEX(nameCardObj) = func_800792D8(D_i4_8011CE50[0]);
    }
}

void MachineSettings_SliderInit(void) {
    func_80077D50(sEngineSliderCompTexInfo, 0);
}

void MachineSelect_DifficultyCupsInit(Object* difficultyCupsObj) {
    s32 i;

    OBJECT_BUFFER(difficultyCupsObj) = func_800768F4(0, 0x258);

    Save_UpdateCupSave(OBJECT_BUFFER(difficultyCupsObj));

    for (i = 0; i < 21; i++) {
        func_80077D50(sTrophyCompTexInfos[i], 0);
    }

    for (i = 0; i < 4; i++) {
        func_80077D50(sDifficultyCompTexInfos[i], 0);
    }
}

void MachineSelect_StatsInit(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        func_80077D50(sMachineStatCompTexInfos[i], 0);
    }
}

void MachineSelect_OkInit(Object* okObj) {
    func_80077D50(sOKCompTexInfo, 0);
    OBJECT_TOP(okObj) = 50;
}

void MachineSettings_OkInit(Object* okObj) {
    func_80077D50(sOKCompTexInfo, 0);
    OBJECT_LEFT(okObj) = 50;
}

#define PACK_5551(r, g, b, a) (((((r) << 11) | ((g) << 6)) | ((b) << 1)) | (a))

#ifdef NON_MATCHING
// loop unroll issue
Gfx* MachineSelect_BackgroundDraw(Gfx* gfx) {
    s32 color;
    s32 i;

    gDPSetCycleType(gfx++, G_CYC_FILL);

    for (i = 0; i < 0xE0; i++) {
        color = PACK_5551((i * 10) / 1792, (i * 0) / 1792, (i * 60) / 1792, 1);
        gDPPipeSync(gfx++);
        gDPSetFillColor(gfx++, color << 0x10 | color);
        gDPFillRectangle(gfx++, 12, i + 8, 307, i + 8);
    }
    return gfx;
}
#else
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/overlays/ovl_i4/machine/MachineSelect_BackgroundDraw.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i4/machine/MachineSelect_BackgroundDraw.s")
#endif
#endif

Gfx* MachineSelect_HeaderDraw(Gfx* gfx, Object* headerObj) {
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    return func_80078EA0(gfx, sSelectMachineCompTexInfo, OBJECT_LEFT(headerObj), OBJECT_TOP(headerObj), 0, 0, 0, 1.0f,
                         1.0f);
}

Gfx* func_i4_80117BE0(Gfx* gfx, Object* arg1) {
    s32 i;
    const s32* var_s0;

    if (gNumPlayers == 1) {
        gfx = func_80078EA0(gfx, sPortraitCompTexInfos[gRacers[0].character], OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 0, 0,
                            0, 1.0f, 1.0f);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_8011D6C4[i * 2];
            gfx = func_80078EA0(gfx, sSmallPortraitCompTexInfos[gRacers[i].character], var_s0[0], var_s0[1] + 55, 0, 0,
                                0, 1.0f, 1.0f);
        }
    }
    return gfx;
}

extern unk_800E3F28 D_800E3F28[];

Gfx* MachineSettings_PortraitDraw(Gfx* gfx, Object* portraitObj) {
    s32 playerIndex;
    const s32* positions;

    playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SETTINGS_PORTRAIT_0;
    positions = &D_i4_8011D6C4[playerIndex * 2];
    switch (gNumPlayers) {
        case 1:
            gfx = func_80078EA0(gfx, sPortraitBackgroundCompTexInfo, OBJECT_LEFT(portraitObj), OBJECT_TOP(portraitObj),
                                0, 0, 0, 1.0f, 1.0f);
            gfx = func_80078F80(gfx, &D_800E3F28[OBJECT_CACHE_INDEX(portraitObj)], OBJECT_LEFT(portraitObj),
                                OBJECT_TOP(portraitObj), 0, 0, 0, 1.0f, 1.0f);
            break;
        case 2:
            gfx = func_80078F80(gfx, &D_800E3F28[OBJECT_CACHE_INDEX(portraitObj)], positions[0] - 4,
                                positions[1] + 0x1A, 0, 0, 0, 1.0f, 1.0f);
            break;
        default:
            gfx = func_80078F80(gfx, &D_800E3F28[OBJECT_CACHE_INDEX(portraitObj)], positions[0], positions[1] + 0x37, 0,
                                0, 0, 1.0f, 1.0f);
            break;
    }
    return gfx;
}

extern unk_800CF1B0 D_800F80C8[];

Gfx* MachineSelect_StatsDraw(Gfx* gfx, Object* statsObj) {
    s32 temp_fp;
    s32 temp_s0;
    s32 temp_t0;
    s32 playerIndex;
    s8* temp_a3;
    s32 i;

    playerIndex = statsObj->cmdId - OBJECT_MACHINE_SELECT_STATS_0;

    temp_a3 = &D_800F80C8[gRacers[playerIndex].character].machineStats;
    temp_fp = D_i4_8011D694[playerIndex * 2 + 0];
    temp_t0 = D_i4_8011D694[playerIndex * 2 + 1];
    if (playerIndex < 2) {
        for (i = 0; i < 3; i++) {
            gfx = func_80078EA0(gfx, sMachineStatCompTexInfos[i], temp_fp, (temp_t0 - 7) + i * 20, 0, 0, 0, 1.0f, 1.0f);
            temp_s0 = sMachineStatValues[temp_a3[i]];
            gfx = Font_DrawString(gfx, temp_fp + 5, (temp_t0 + 10) + i * 20, temp_s0, 0, FONT_SET_2, 0);
        }
    } else {
        for (i = 0; i < 3; i++) {
            gfx = func_80078EA0(gfx, sMachineStatCompTexInfos[i], temp_fp - 0x14, (temp_t0 - 7) + i * 20, 0, 0, 0, 1.0f,
                                1.0f);
            temp_s0 = sMachineStatValues[temp_a3[i]];
            gfx = Font_DrawString(gfx, (temp_fp - Font_GetStringWidth(temp_s0, FONT_SET_2, 0)) - 5,
                                  (temp_t0 + 10) + i * 20, temp_s0, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

Gfx* MachineSelect_PortraitDraw(Gfx* gfx, Object* portraitObj) {
    s32 playerIndex;

    playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SELECT_PORTRAIT_0;

    gfx = func_80078F80(gfx, &D_800E3F28[OBJECT_CACHE_INDEX(portraitObj)], OBJECT_LEFT(portraitObj),
                        OBJECT_TOP(portraitObj), 0, 0, 0, 1.0f, 1.0f);
    return func_80078EA0(gfx, sPlayerNumIconCompTexInfos[playerIndex],
                         D_i4_8011D674[playerIndex * 2 + 0] + OBJECT_LEFT(portraitObj),
                         D_i4_8011D674[playerIndex * 2 + 1] + OBJECT_TOP(portraitObj), 0, 0, 0, 1.0f, 1.0f);
}

Gfx* MachineSelect_CursorNumDraw(Gfx* gfx, Object* portraitObj) {
    return func_80078EA0(gfx, sPlayerNumIconCompTexInfos[portraitObj->cmdId - OBJECT_MACHINE_SELECT_CURSOR_NUM_0],
                         OBJECT_LEFT(portraitObj), OBJECT_TOP(portraitObj), 0, 0, 0, 1.0f, 1.0f);
}

extern u32 gGameFrameCount;

Gfx* MachineSelect_CursorDraw(Gfx* gfx, Object* cursorObj) {
    s32 temp_v0;
    s32 i;
    s32 temp_s3 = 30;

    for (i = 0; i < 4; i++) {
        if (Object_Get(OBJECT_MACHINE_SELECT_CURSOR_NUM_0 + i) != NULL) {
            temp_v0 = (u32) gGameFrameCount % temp_s3;
            if ((gPlayerSelectionLock[i] != SELECTION_FREE) || (temp_v0 >= 0xF)) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255 - ((temp_v0 * 510) / temp_s3));
            }
            temp_v0 = sMachineSelectIndex[i];
            OBJECT_LEFT(cursorObj) = ((temp_v0 % 6) * 0x28) + 0x28;
            OBJECT_TOP(cursorObj) = ((temp_v0 / 6) * 0x22) + 0x25;

            gfx = func_80078EA0(gfx, sMachineSelectCursorCompTexInfo, OBJECT_LEFT(cursorObj), OBJECT_TOP(cursorObj), 1,
                                0, 0, 1.0f, 1.0f);
        }
    }
    return gfx;
}

extern unk_struct_1DC D_800E5220[];
extern GfxPool D_1000000;
extern GfxPool* gGfxPool;

Gfx* MachineSelect_CarDraw(Gfx* gfx, Object* carObj) {
    bool var_t0;
    s32 i;
    s32 j;

    gSPPerspNormalize(gfx++, D_800E5220[0].unk_118);

    gSPMatrix(gfx++, D_1000000.unk_20208, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gSPDisplayList(gfx++, D_303A5F8);

    gSPLight(gfx++, &D_1000000.unk_21A88[0].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].a, 2);
    gSPNumLights(gfx++, NUMLIGHTS_1);

    Lights_SetSource(&gGfxPool->unk_21A88[0], 0, 0, 0, 255, 255, 255, 100, 50, 69);
    Lights_SetSource(&gGfxPool->unk_21A88[1], 0, 0, 0, 100, 70, 70, 100, 50, 69);

    for (i = 0; i < 30; i++) {
        gDPPipeSync(gfx++);
        var_t0 = false;
        if (i < sMachinesUnlocked) {
            j = 0;
        } else {
            j = 1;
        }

        gSPLight(gfx++, &D_1000000.unk_21A88[j].l[0], 1);
        gSPLight(gfx++, &D_1000000.unk_21A88[j].a, 2);
        gSPViewport(gfx++, CAR_VIEWPORT(carObj) + i);

        for (j = 0; j < gNumPlayers; j++) {
            if (i == sMachineSelectIndex[j]) {
                var_t0 = true;
                break;
            }
        }

        if (!var_t0) {
            gSPMatrix(gfx++, &D_1000000.unk_20308[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        } else {
            gSPMatrix(gfx++, &D_1000000.unk_20308[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        }
        gfx = func_8009CCBC(gfx, func_8007E10C(i), 0);
    }
    return gfx;
}

Gfx* MachineSelect_OkDraw(Gfx* gfx, Object* okObj) {
    s32 var_v1;

    if (gNumPlayers == 1) {
        var_v1 = 265;
    } else {
        var_v1 = 144;
    }

    gfx = func_8007DB28(gfx, 0);
    return func_80078EA0(gfx, sOKCompTexInfo, OBJECT_LEFT(okObj) + var_v1, OBJECT_TOP(okObj) + 209, 1, 0, 0, 1.0f,
                         1.0f);
}

extern const char* gMachineNames[];

Gfx* MachineSettings_NameDraw(Gfx* gfx) {
    s32 i;
    const char* temp_s1;
    const s32* var_s0;

    if (gNumPlayers == 1) {
        temp_s1 = gMachineNames[MachineSettings_GetCharacter(gRacers[0].character)];
        gfx =
            Font_DrawString(gfx, 0x122 - Font_GetStringWidth(temp_s1, FONT_SET_1, 0), 0x22, temp_s1, 0, FONT_SET_1, 0);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_8011D6C4[i * 2];
            temp_s1 = gMachineNames[MachineSettings_GetCharacter(gRacers[i].character)];
            gfx = Font_DrawString(gfx, (var_s0[0] - Font_GetStringWidth(temp_s1, FONT_SET_2, 0)) + 0x82,
                                  var_s0[1] + 0xA, temp_s1, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

extern u16 D_9000008[];
extern Gfx D_90186C8[];

Gfx* MachineSettings_CarDraw(Gfx* gfx, Object* carObj) {
    s32 i;

    gSPPerspNormalize(gfx++, D_800E5220[0].unk_118);

    gSPMatrix(gfx++, D_1000000.unk_20208, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gSPDisplayList(gfx++, D_303A758);

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    for (i = 0; i < gNumPlayers; i++) {
        if (D_i4_8011D4E4[i] == 0) {
            continue;
        }

        if (gControllers[gPlayerControlPorts[i]].buttonCurrent & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
            D_i4_8011D4E4[i] = 0;
            continue;
        }

        gSPViewport(gfx++, CAR_VIEWPORT(carObj) + i + 4);
        gSPMatrix(gfx++, &D_1000000.unk_20A88[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CD60(gfx, gRacers[i].character);
    }

    gSPDisplayList(gfx++, D_303A7D8);
    gDPSetBlendColor(gfx++, 0, 0, 0, 255);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, CAR_VIEWPORT(carObj) + i);
        gSPMatrix(gfx++, &D_1000000.unk_21208[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CE70(gfx, gRacers[i].character);
    }

    gSPDisplayList(gfx++, D_303A5F8);

    Lights_SetSource(gGfxPool->unk_21A88, 0, 0, 0, 255, 255, 255, 50, 25, 34);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].a, 2);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, CAR_VIEWPORT(carObj) + i);
        gSPMatrix(gfx++, &D_1000000.unk_20308[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CCBC(gfx, gRacers[i].character, gRacers[i].unk_2CC);
    }

    gSPDisplayList(gfx++, D_90186C8);

    Light_SetLookAtSource(&gGfxPool->unk_21B28, &D_800E5220[0].unk_15C);
    gSPLookAt(gfx++, &gGfxPool->unk_21B28);

    gSPTexture(gfx++, D_i4_8011D4E0, D_i4_8011D4E0, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureBlock(gfx++, D_9000008, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i4_8011D4DC);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, CAR_VIEWPORT(carObj) + i);
        gSPMatrix(gfx++, &D_1000000.unk_20308[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CEA0(gfx, gRacers[i].character);
    }

    return gfx;
}

Gfx* MachineSettings_EngineWeightDraw(Gfx* gfx, Object* engineWeightObj) {
    s32 i;
    s16 temp_s4;
    s32 temp_s0;
    s32 temp_s1;

    if (gNumPlayers == 1) {
        temp_s4 = D_800F80C8[gRacers[0].character].unk_14;
        gfx = func_80078EA0(gfx, sMachineInfoGraphCompTexInfo, OBJECT_LEFT(engineWeightObj),
                            OBJECT_TOP(engineWeightObj), 0, 0, 0, 1.0f, 1.0f);
        gfx = Font_DrawMachineWeight(gfx, OBJECT_LEFT(engineWeightObj) + 0x66, OBJECT_TOP(engineWeightObj) + 0x17,
                                     temp_s4);

        switch (gMachineSettingsState) {
            case MACHINE_SETTINGS_ACTIVE:
            case MACHINE_SETTINGS_EXIT:
                gfx = func_8007DB28(gfx, 0);
                break;
            default:
                gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                break;
        }
#ifdef VERSION_JP
        gfx = func_80078EA0(gfx, sMachineAccelerationMaxSpeedCompTexInfo, OBJECT_LEFT(engineWeightObj),
                            OBJECT_TOP(engineWeightObj), 1, 0, 0, 1.0f, 1.0f);
#else
        gfx = func_80078EA0(gfx, sMachineAccelerationMaxSpeedCompTexInfo, OBJECT_LEFT(engineWeightObj) + 3,
                            OBJECT_TOP(engineWeightObj) + 1, 1, 0, 0, 1.0f, 1.0f);
#endif
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            temp_s4 = D_800F80C8[gRacers[i].character].unk_14;
            temp_s0 = D_i4_8011D6C4[i * 2 + 0];
            temp_s1 = D_i4_8011D6C4[i * 2 + 1];
            gfx = func_80078EA0(gfx, sMachineInfoGraphSmallCompTexInfo, temp_s0 + 0x2B, temp_s1 + 0xA, 0, 0, 0, 1.0f,
                                1.0f);
            gfx = Font_DrawMachineWeight(gfx, temp_s0 + 0x6E, temp_s1 + 0x1C, temp_s4);
            if (gPlayerSelectionLock[i] == SELECTION_FREE) {
                gfx = func_8007DB28(gfx, 0);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
            }
            gfx = func_80078EA0(gfx, sMachineAccelerationMaxSpeedSmallCompTexInfo, temp_s0 + 0x2B, temp_s1 + 0xA, 1, 0,
                                0, 1.0f, 1.0f);
        }
    }
    return gfx;
}

Gfx* MachineSettings_StatsDraw(Gfx* gfx, Object* statsObj) {
    s32 i;
    s32 j;
    s32 leftOffset;
    s32 topOffset;
    s8* temp;
    s32 pad;

    if (gNumPlayers == 1) {
        gfx = func_80078EA0(gfx, sMachineBodyBoostGripCompTexInfo, OBJECT_LEFT(statsObj), OBJECT_TOP(statsObj), 0, 0, 0,
                            1.0f, 1.0f);

        for (i = 0; i < 3; i++) {
            temp = D_800F80C8[gRacers[0].character].machineStats;
            gfx = Font_DrawMachineStatValue(gfx, OBJECT_LEFT(statsObj) + 0x69, OBJECT_TOP(statsObj) + i * 23 + 3,
                                            temp[i]);
        }
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            leftOffset = D_i4_8011D6C4[i * 2 + 0];
            topOffset = D_i4_8011D6C4[i * 2 + 1];

            gfx = func_80078EA0(gfx, sMachineBodyBoostGripSmallCompTexInfo, leftOffset + 0x2B, topOffset + 0x39, 0, 0,
                                0, 1.0f, 1.0f);

            for (j = 0; j < 3; j++) {
                temp = D_800F80C8[gRacers[i].character].machineStats;
                gfx = Font_DrawString(gfx, leftOffset + 0x6B, topOffset + 0x43 + j * 14, sMachineStatValues[temp[j]], 0,
                                      FONT_SET_2, 0);
            }
        }
    }
    return gfx;
}

Gfx* func_i4_801193B8(Gfx* gfx, Object* arg1) {
    s32 i;
    s32 j;
    s8* temp;
    s32 var_s3;
    s32 var_s1;
    const char* temp2;

    for (i = 0; i < gNumPlayers; i++) {
        var_s3 = D_i4_8011D6C4[i * 2 + 0];
        var_s1 = D_i4_8011D6C4[i * 2 + 1];

        for (j = 0; j < 3; j++) {
            temp = D_800F80C8[gRacers[i].character].machineStats;
            temp2 = sMachineStatValues[temp[j]];
            gfx = Font_DrawString(gfx, var_s3 + 0x6B, var_s1 + 0x43 + j * 14, temp2, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

Gfx* MachineSettings_NameCardDraw(Gfx* gfx, Object* nameCardObj) {

    if (gNumPlayers == 1) {
        gfx = func_80078F80(gfx, &D_800E3F28[OBJECT_CACHE_INDEX(nameCardObj)], OBJECT_LEFT(nameCardObj),
                            OBJECT_TOP(nameCardObj), 0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

Gfx* MachineSettings_SliderDraw(Gfx* gfx, Object* sliderObj) {
    s32 i;
    s32 temp_v1;
    s32 left;
    s32 top;

    if (gNumPlayers == 1) {
        switch (gMachineSettingsState) {
            case MACHINE_SETTINGS_ACTIVE:
            case MACHINE_SETTINGS_EXIT:
                if (1) {
                    gfx = func_8007DB28(gfx, 0);
                }
                break;
            default:
                gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                break;
        }

        gfx = func_80078EA0(gfx, sEngineSliderCompTexInfo, (s32) (gPlayerEngine[0] * 128.0f) + 0x98, 0x54, 1, 0, 0,
                            1.0f, 1.0f);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            temp_v1 = 1;
            switch (gMachineSettingsState) {
                case MACHINE_SETTINGS_ACTIVE:
                case MACHINE_SETTINGS_EXIT:
                    if (gPlayerSelectionLock[i] == SELECTION_FREE) {
                        gfx = func_8007DB28(gfx, 0);
                        break;
                    }
                default:
                    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                    break;
            }

            top = D_i4_8011D6C4[i * 2 + 1] + 0x2E;
            left = D_i4_8011D6C4[i * 2 + 0] + (s32) (gPlayerEngine[i] * 80.0f) + 0x23;
            gfx = func_80078EA0(gfx, sEngineSliderCompTexInfo, left, top, temp_v1, 0, 0, 1.0f, 1.0f);
        }
    }
    return gfx;
}

Gfx* MachineSettings_SplitscreenDraw(Gfx* gfx) {

    gfx = func_8007AD44(gfx, 255, 255, 255, 12, 119, 307, 120);
    if (gNumPlayers >= 3) {
        gfx = func_8007AD44(gfx, 255, 255, 255, 158, 8, 159, 231);
    }
    return gfx;
}

extern s32 gDifficulty;
extern s8 gUnlockableLevel;
extern s8 gSettingEverythingUnlocked;
extern s32 gAntiPiracyAddedDifficulty;

Gfx* MachineSelect_DifficultyCupsDraw(Gfx* gfx, Object* difficultyCupsObj) {
    s32 i;
    s32 temp_v0;
    s32 difficulty;
    s32 trophyIndex;
    s32 pad;
    s32 var_t0;
    s8* var_t1;

    temp_v0 = func_8007E10C(sMachineSelectIndex[0]);
    difficulty = 0;
    switch (gMachineSelectState) {
        case MACHINE_SELECT_AWAIT_OK:
        case MACHINE_SELECT_CONTINUE:
            break;
        default:
            if (((gUnlockableLevel >= 2) || (gSettingEverythingUnlocked != 0)) &&
                (gSharedController.buttonCurrent & BTN_CUP)) {
                difficulty = MASTER + 1;
            }
            if (gSharedController.buttonCurrent & BTN_CRIGHT) {
                difficulty = EXPERT + 1;
            }
            if (gSharedController.buttonCurrent & BTN_CDOWN) {
                difficulty = STANDARD + 1;
            }
            if (gSharedController.buttonCurrent & BTN_CLEFT) {
                difficulty = NOVICE + 1;
            }
            break;
    }

    if (difficulty != 0) {
        difficulty--;
    } else {
        difficulty = gDifficulty - gAntiPiracyAddedDifficulty;
    }

    if ((gUnlockableLevel >= 2) || (gSettingEverythingUnlocked != 0)) {
        var_t0 = 5;
    } else {
        if (gUnlockableLevel > 0) {
            var_t0 = 4;
        } else {
            var_t0 = 3;
        }
    }

    var_t1 = OBJECT_BUFFER(difficultyCupsObj) + difficulty * 150 + temp_v0 * 5;

    for (i = 0; i < var_t0; i++) {

        // FAKE
        if ((*((i ^ 0) + (0, var_t1))) == 0) {
            // No trophy
            trophyIndex = 20;
            if (1) {}
        } else {
            trophyIndex = (difficulty * 5) + i;
            if (1) {}
        }

        gfx = func_80078EA0(gfx, sTrophyCompTexInfos[trophyIndex], 20, 0x73 + i * 20, 0, 0, 0, 1.0f, 1.0f);
    }
    return func_80078EA0(gfx, sDifficultyCompTexInfos[difficulty], 30, 0xD1, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* MachineSelect_NameDraw(Gfx* gfx, Object* nameObj) {
    s32 pad[2];
    const char* machineName;

    machineName = gMachineNames[MachineSettings_GetCharacter(gRacers[0].character)];

    gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth(machineName, FONT_SET_2, 0) / 2), 218, machineName, 0,
                          FONT_SET_2, 0);
    gfx = Font_DrawMachineWeightSmall(gfx, 252, 221, D_800F80C8[func_8007E10C(sMachineSelectIndex[0])].unk_14);
    return Font_DrawString(gfx, 252, 221, "$", 0, FONT_SET_2, 0);
}

Gfx* MachineSettings_OkDraw(Gfx* gfx, Object* okObj) {
    gfx = func_8007DB28(gfx, 0);
    return func_80078EA0(gfx, sOKCompTexInfo, OBJECT_LEFT(okObj) + 0x10B, OBJECT_TOP(okObj) + 0xD0, 1, 0, 0, 1.0f,
                         1.0f);
}

void func_i4_80119BB8(Object* arg0) {
}

void MachineSettings_PortraitUpdate(Object* portraitObj) {
    s32 index = portraitObj->cmdId - OBJECT_MACHINE_SETTINGS_PORTRAIT_0;
    s32 character = gRacers[index].character;

    character = MachineSettings_GetCharacter(character);
    if (character != PORTRAIT_CHARACTER(portraitObj)) {
        if (gNumPlayers == 1) {
            func_800793E8(OBJECT_CACHE_INDEX(portraitObj), 0, D_i4_8011C05C[character]);
        } else {
            func_800793E8(OBJECT_CACHE_INDEX(portraitObj), 0, D_i4_8011C7A4[character]);
        }
    }
    PORTRAIT_CHARACTER(portraitObj) = character;
}

void MachineSelect_PortraitUpdate(Object* portraitObj) {
    s32 playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SELECT_PORTRAIT_0;
    s32 character = gRacers[playerIndex].character;

    character = MachineSettings_GetCharacter(character);
    if (character != PORTRAIT_CHARACTER(portraitObj)) {
        func_800793E8(OBJECT_CACHE_INDEX(portraitObj), 0, D_i4_8011C7A4[character]);
    }
    PORTRAIT_CHARACTER(portraitObj) = character;
}

void MachineSelect_CursorNumUpdate(Object* cursorNumObj) {
    s32 playerIndex = cursorNumObj->cmdId - OBJECT_MACHINE_SELECT_CURSOR_NUM_0;
    s32 temp_v1;

    temp_v1 = sMachineSelectIndex[playerIndex];
    OBJECT_LEFT(cursorNumObj) = ((temp_v1 % 6) * 0x28) + 0x28;
    OBJECT_TOP(cursorNumObj) = ((temp_v1 / 6) * 0x22) + 0x25;
}

void MachineSelect_CursorUpdate(Object* cursorObj) {
}

void MachineSelect_CarUpdate(Object* carObj) {
    Racer* var_s0;
    f32 var_fv0;
    s32 i;

    if (CAR_MINI_STATE(carObj) == 1) {
        if (D_i4_8011D778 >= 0) {
            D_i4_8011D77C -= 0.05f;
        } else {
            D_i4_8011D77C += 0.05f;
        }
        var_fv0 = D_i4_8011D778;
        D_i4_8011D778 += D_i4_8011D77C;
        if ((var_fv0 * D_i4_8011D778) < 0) {
            if (D_i4_8011D77C < 0) {
                var_fv0 = 0 - D_i4_8011D77C;
            } else {
                var_fv0 = D_i4_8011D77C;
            }
            if (var_fv0 < 0.1f) {
                CAR_MINI_STATE(carObj) = 2;
                D_800CE750 = 0.105f;
                D_800CE74C = 0.125f;
                D_800CE748 = 0.075f;
            }
        }
        D_i4_8011D77C *= 0.98f;
        // TODO: figure out matching floats
        D_800CE750 = (D_i4_8011D778 * -0.004999995f) + 0.105f;
        D_800CE74C = (D_i4_8011D778 * -0.024999999f) + 0.125f;
        D_800CE748 = (D_i4_8011D778 * 0.024999999f) + 0.075f;
    }

    i = 3;
    var_s0 = &gRacers[3];
    while (var_s0 >= &gRacers[0]) {
        if (var_s0 == &gRacers[0]) {
            var_fv0 = 0.03f;
        } else {
            var_fv0 = 0.0f;
        }
        var_s0->unk_C0.x.x += var_fv0 * var_s0->unk_C0.z.x;
        var_s0->unk_C0.x.y += var_fv0 * var_s0->unk_C0.z.y;
        var_s0->unk_C0.x.z += var_fv0 * var_s0->unk_C0.z.z;
        func_8006AA38(&var_s0->unk_C0);
        func_8006BC84(&gGfxPool->unk_20308[i], NULL, D_800CE748, D_800CE74C, D_800CE750, var_s0->unk_C0.x.x,
                      var_s0->unk_C0.x.y, var_s0->unk_C0.x.z, var_s0->unk_C0.y.x, var_s0->unk_C0.y.y,
                      var_s0->unk_C0.y.z, var_s0->unk_0C.unk_34.x, var_s0->unk_0C.unk_34.y, var_s0->unk_0C.unk_34.z);
        var_s0--;
        i--;
    }
}

void MachineSettings_CarUpdate(Object* carObj) {
    Racer* var_s0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fv0;
    s32 i;
    s32 var_a1;
    Vp* var_v0;

    var_v0 = CAR_VIEWPORT(carObj);
    for (var_a1 = 4; var_a1 < 8; var_a1++) {
        switch (gNumPlayers) {
            case 1:
                var_v0[var_a1].vp.vtrans[0] = (D_i4_8011D4B0 + 0xDC) << 2;
                var_v0[var_a1].vp.vtrans[1] = (D_i4_8011D4B4 + 0xC8) << 2;
                break;
            case 2:
                var_v0[var_a1].vp.vtrans[0] = (D_i4_8011D4B8 + 0xE9) << 2;
                var_v0[var_a1].vp.vtrans[1] = (((var_a1 % 2) * 0x69) + D_i4_8011D4BC + 0x50) << 2;
                break;
            default:
                var_v0[var_a1].vp.vtrans[0] = ((((var_a1 - 4) / 2) * 0x8C) + 0x29) << 2;
                var_v0[var_a1].vp.vtrans[1] = ((((var_a1 - 4) % 2) * 0x69) + 0x3A) << 2;
                break;
        }
    }

    switch (gNumPlayers) {
        case 1:
            var_fs2 = 10.0f;
            break;
        case 2:
            var_fs2 = 12.0f;
            break;
        default:
            var_fs2 = 5.0f;
    }

    var_s0 = &gRacers[gNumPlayers - 1];
    i = gNumPlayers - 1;
    while (var_s0 >= gRacers) {
        var_fs0 = 0.0f;
        var_fs1 = 0.0f;
        var_fv0 = 0.0f;
        var_a1 = gControllers[gPlayerControlPorts[i]].buttonCurrent & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);
        switch (var_a1) {
            case 3:
            case 12:
            case 15:
                break;
            case 0:
                var_fv0 = 0.015f;
                break;
            default:
                if (var_a1 & BTN_CLEFT) {
                    var_fs0 = 0.03f;
                }
                if (var_a1 & BTN_CDOWN) {
                    var_fs1 = 0.03f;
                }
                if (var_a1 & BTN_CUP) {
                    var_fs1 = -0.03f;
                }
                if (var_a1 & BTN_CRIGHT) {
                    var_fs0 = -0.03f;
                }
                break;
        }

        var_s0->unk_C0.x.x += var_fv0 * var_s0->unk_C0.z.x;
        var_s0->unk_C0.x.y += var_fv0 * var_s0->unk_C0.z.y;
        var_s0->unk_C0.x.z += var_fv0 * var_s0->unk_C0.z.z;
        var_s0->unk_C0.x.x += var_fs1 * var_s0->unk_C0.y.x;
        var_s0->unk_C0.x.y += var_fs1 * var_s0->unk_C0.y.y;
        var_s0->unk_C0.x.z += var_fs1 * var_s0->unk_C0.y.z;
        var_s0->unk_C0.y.x = var_s0->unk_C0.y.x + (var_fs0 * var_s0->unk_C0.z.x);
        var_s0->unk_C0.y.y = var_s0->unk_C0.y.y + (var_fs0 * var_s0->unk_C0.z.y);
        var_s0->unk_C0.y.z = var_s0->unk_C0.y.z + (var_fs0 * var_s0->unk_C0.z.z);
        func_8006AA38(&var_s0->unk_C0);
        func_8006BC84(&gGfxPool->unk_20308[i], NULL, var_fs2 * D_800CE748, var_fs2 * D_800CE74C, var_fs2 * D_800CE750,
                      var_s0->unk_C0.x.x, var_s0->unk_C0.x.y, var_s0->unk_C0.x.z, var_s0->unk_C0.y.x,
                      var_s0->unk_C0.y.y, var_s0->unk_C0.y.z, var_s0->unk_0C.unk_34.x, var_s0->unk_0C.unk_34.y,
                      var_s0->unk_0C.unk_34.z);
        func_8006BC84(&gGfxPool->unk_21208[i], NULL, (var_fs2 * 1.05f) * D_800CE748, (var_fs2 * 1.05f) * D_800CE74C,
                      (var_fs2 * 1.05f) * D_800CE750, var_s0->unk_C0.x.x, var_s0->unk_C0.x.y, var_s0->unk_C0.x.z,
                      var_s0->unk_C0.y.x, var_s0->unk_C0.y.y, var_s0->unk_C0.y.z, var_s0->unk_0C.unk_34.x,
                      var_s0->unk_0C.unk_34.y, var_s0->unk_0C.unk_34.z);
        func_8006BC84(&gGfxPool->unk_20A88[i], NULL, var_fs2 * D_800CE748, var_fs2 * D_800CE74C, var_fs2 * D_800CE750,
                      var_s0->unk_C0.x.x, var_s0->unk_C0.x.y, var_s0->unk_C0.x.z, var_s0->unk_C0.y.x,
                      var_s0->unk_C0.y.y, var_s0->unk_C0.y.z, var_s0->unk_0C.unk_34.x, var_s0->unk_0C.unk_34.y,
                      var_s0->unk_0C.unk_34.z);
        var_s0--;
        i--;
    }
}

void MachineSelect_OkUpdate(Object* okObj) {
    switch (gMachineSelectState) {
        case MACHINE_SELECT_AWAIT_OK:
        case MACHINE_SELECT_CONTINUE:
            Object_LerpPosYToClampedTarget(okObj, 0);
            break;
        default:
            Object_LerpPosYToClampedTarget(okObj, 50);
            break;
    }
}

void MachineSettings_OkUpdate(Object* okObj) {
    switch (gMachineSettingsState) {
        case MACHINE_SETTINGS_AWAIT_OK:
        case MACHINE_SETTINGS_CONTINUE:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 0, 192);
            break;
        default:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 50, 192);
            break;
    }
}

void MachineSettings_NameCardUpdate(Object* nameCardObj) {

    if (NAME_CARD_CHARACTER(nameCardObj) != gRacers[0].character) {
        if (gNumPlayers == 1) {
            func_800793E8(OBJECT_CACHE_INDEX(nameCardObj), 0, D_i4_8011CE50[gRacers[0].character % 30]);
        }
    }
    NAME_CARD_CHARACTER(nameCardObj) = gRacers[0].character;
}

void func_i4_8011A7B8(void) {
    if ((gQueuedGameMode == GAMEMODE_LX_MACHINE_SETTINGS) &&
        (CAR_MINI_STATE(Object_Get(OBJECT_MACHINE_SELECT_CAR)) != 0)) {
        D_800CE748 = 0.075f;
        D_800CE74C = 0.125f;
        D_800CE750 = 0.105f;
    } else {
        D_800CE748 = D_800CE74C = D_800CE750 = 0.1f;
    }
}
