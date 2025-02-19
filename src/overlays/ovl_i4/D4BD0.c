#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "assets/segment_2B9EA0.h"
#include "assets/segment_17B960.h"

UNUSED s32 D_8011D770;
s32 D_i4_8011D774;
f32 D_i4_8011D778;
f32 D_i4_8011D77C;
s16 D_i4_8011D780[8];
s32 D_i4_8011D790;
s32 D_i4_8011D794;

unk_80077D50 sPortraitDrStewartCompTexInfo[] = { { 17, aFullPortraitDrStewartTex, 180, 245, 0x4AF4 }, { 0 } };
unk_80077D50 sPortraitCaptainFalconCompTexInfo[] = { { 17, aFullPortraitCaptainFalconTex, 180, 245, 0x6604 }, { 0 } };
unk_80077D50 sPortraitJodySummerCompTexInfo[] = { { 17, aFullPortraitJodySummerTex, 180, 245, 0x5573 }, { 0 } };
unk_80077D50 sPortraitSamuraiGorohCompTexInfo[] = { { 17, aFullPortraitSamuraiGorohTex, 180, 245, 0x76B4 }, { 0 } };
unk_80077D50 sPortraitMightyGazelleCompTexInfo[] = { { 17, aFullPortraitMightyGazelleTex, 180, 245, 0x67F2 }, { 0 } };
unk_80077D50 sPortraitPicoCompTexInfo[] = { { 17, aFullPortraitPicoTex, 180, 245, 0x63BB }, { 0 } };
unk_80077D50 sPortraitBabaCompTexInfo[] = { { 17, aFullPortraitBabaTex, 180, 245, 0x5EE9 }, { 0 } };
unk_80077D50 sPortraitMrEadCompTexInfo[] = { { 17, aFullPortraitMrEadTex, 180, 245, 0x7184 }, { 0 } };
unk_80077D50 sPortraitOctomanCompTexInfo[] = { { 17, aFullPortraitOctomanTex, 180, 245, 0x5666 }, { 0 } };
unk_80077D50 sPortraitTheSkullCompTexInfo[] = { { 17, aFullPortraitTheSkullTex, 180, 245, 0x5A49 }, { 0 } };
unk_80077D50 sPortraitBeastmanCompTexInfo[] = { { 17, aFullPortraitBeastmanTex, 180, 245, 0x55C1 }, { 0 } };
unk_80077D50 sPortraitAntonioGusterCompTexInfo[] = { { 17, aFullPortraitAntonioGusterTex, 180, 245, 0x594F }, { 0 } };
unk_80077D50 sPortraitDraqCompTexInfo[] = { { 17, aFullPortraitDraqTex, 180, 245, 0x7A7A }, { 0 } };
unk_80077D50 sPortraitRogerBusterCompTexInfo[] = { { 17, aFullPortraitRogerBusterTex, 180, 245, 0x6444 }, { 0 } };
unk_80077D50 sPortraitSilverNeelsenCompTexInfo[] = { { 17, aFullPortraitSilverNeelsenTex, 180, 245, 0x623A }, { 0 } };
unk_80077D50 sPortraitSuperArrowCompTexInfo[] = { { 17, aFullPortraitSuperArrowTex, 180, 245, 0x6F78 }, { 0 } };
unk_80077D50 sPortraitMrsArrowCompTexInfo[] = { { 17, aFullPortraitMrsArrowTex, 180, 245, 0x5C56 }, { 0 } };
unk_80077D50 sPortraitZodaCompTexInfo[] = { { 17, aFullPortraitZodaTex, 180, 245, 0x59E6 }, { 0 } };
unk_80077D50 sPortraitJohnTanakaCompTexInfo[] = { { 17, aFullPortraitJohnTanakaTex, 180, 245, 0x5B58 }, { 0 } };
unk_80077D50 sPortraitBioRexCompTexInfo[] = { { 17, aFullPortraitBioRexTex, 180, 245, 0x6B2D }, { 0 } };
unk_80077D50 sPortraitKateAlenCompTexInfo[] = { { 17, aFullPortraitKateAlenTex, 180, 245, 0x4E48 }, { 0 } };
unk_80077D50 sPortraitGomarAndShiohCompTexInfo[] = { { 17, aFullPortraitGomarAndShiohTex, 180, 245, 0x6D92 }, { 0 } };
unk_80077D50 sPortraitMichaelChainCompTexInfo[] = { { 17, aFullPortraitMichaelChainTex, 180, 245, 0x5AB3 }, { 0 } };
unk_80077D50 sPortraitBillyCompTexInfo[] = { { 17, aFullPortraitBillyTex, 180, 245, 0x5E3B }, { 0 } };
unk_80077D50 sPortraitDrClashCompTexInfo[] = { { 17, aFullPortraitDrClashTex, 180, 245, 0x6EAC }, { 0 } };
unk_80077D50 sPortraitJackLevinCompTexInfo[] = { { 17, aFullPortraitJackLevinTex, 180, 245, 0x4D32 }, { 0 } };
unk_80077D50 sPortraitBloodFalconCompTexInfo[] = { { 17, aFullPortraitBloodFalconTex, 180, 245, 0x603A }, { 0 } };
unk_80077D50 sPortraitLeonCompTexInfo[] = { { 17, aFullPortraitLeonTex, 180, 245, 0x60B6 }, { 0 } };
unk_80077D50 sPortraitJamesMcCloudCompTexInfo[] = { { 17, aFullPortraitJamesMcCloudTex, 180, 245, 0x5534 }, { 0 } };
unk_80077D50 sPortraitBlackShadowCompTexInfo[] = { { 17, aFullPortraitBlackShadowTex, 180, 245, 0x5DA7 }, { 0 } };
unk_80077D50 sPortraitCaptainFalconAltCompTexInfo[] = { { 17, aFullPortraitCaptainFalconAltTex, 180, 245, 0x5CB2 },
                                                        { 0 } };
unk_80077D50 sPortraitSamuraiGorohAltCompTexInfo[] = { { 17, aFullPortraitSamuraiGorohAltTex, 180, 245, 0x6590 },
                                                       { 0 } };
unk_80077D50 sPortraitJodySummerAltCompTexInfo[] = { { 17, aFullPortraitJodySummerAltTex, 180, 245, 0x5022 }, { 0 } };
unk_80077D50 sPortraitBackgroundCompTexInfo[] = { { 17, aFullPortraitBackgroundTex, 180, 245, 0x58F4 }, { 0 } };

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

unk_80077D50 sSmallPortraitDrStewartCompTexInfo[] = { { 17, aSmallPortraitDrStewartTex, 40, 40, 0x77F }, { 0 } };
unk_80077D50 sSmallPortraitCaptainFalconCompTexInfo[] = { { 17, aSmallPortraitCaptainFalconTex, 40, 40, 0x8AF },
                                                          { 0 } };
unk_80077D50 sSmallPortraitJodySummerCompTexInfo[] = { { 17, aSmallPortraitJodySummerTex, 40, 40, 0x875 }, { 0 } };
unk_80077D50 sSmallPortraitSamuraiGorohCompTexInfo[] = { { 17, aSmallPortraitSamuraiGorohTex, 40, 40, 0x935 }, { 0 } };
unk_80077D50 sSmallPortraitMightyGazelleCompTexInfo[] = { { 17, aSmallPortraitMightyGazelleTex, 40, 40, 0x8EB },
                                                          { 0 } };
unk_80077D50 sSmallPortraitPicoCompTexInfo[] = { { 17, aSmallPortraitPicoTex, 40, 40, 0x908 }, { 0 } };
unk_80077D50 sSmallPortraitBabaCompTexInfo[] = { { 17, aSmallPortraitBabaTex, 40, 40, 0x919 }, { 0 } };
unk_80077D50 sSmallPortraitMrEadCompTexInfo[] = { { 17, aSmallPortraitMrEadTex, 40, 40, 0x989 }, { 0 } };
unk_80077D50 sSmallPortraitOctomanCompTexInfo[] = { { 17, aSmallPortraitOctomanTex, 40, 40, 0x82D }, { 0 } };
unk_80077D50 sSmallPortraitTheSkullCompTexInfo[] = { { 17, aSmallPortraitTheSkullTex, 40, 40, 0x8F8 }, { 0 } };
unk_80077D50 sSmallPortraitBeastmanCompTexInfo[] = { { 17, aSmallPortraitBeastmanTex, 40, 40, 0x908 }, { 0 } };
unk_80077D50 sSmallPortraitAntonioGusterCompTexInfo[] = { { 17, aSmallPortraitAntonioGusterTex, 40, 40, 0x8EE },
                                                          { 0 } };
unk_80077D50 sSmallPortraitDraqCompTexInfo[] = { { 17, aSmallPortraitDraqTex, 40, 40, 0x9AD }, { 0 } };
unk_80077D50 sSmallPortraitRogerBusterCompTexInfo[] = { { 17, aSmallPortraitRogerBusterTex, 40, 40, 0x923 }, { 0 } };
unk_80077D50 sSmallPortraitSilverNeelsenCompTexInfo[] = { { 17, aSmallPortraitSilverNeelsenTex, 40, 40, 0x93A },
                                                          { 0 } };
unk_80077D50 sSmallPortraitSuperArrowCompTexInfo[] = { { 17, aSmallPortraitSuperArrowTex, 40, 40, 0x97F }, { 0 } };
unk_80077D50 sSmallPortraitMrsArrowCompTexInfo[] = { { 17, aSmallPortraitMrsArrowTex, 40, 40, 0xA3D }, { 0 } };
unk_80077D50 sSmallPortraitZodaCompTexInfo[] = { { 17, aSmallPortraitZodaTex, 40, 40, 0x8AB }, { 0 } };
unk_80077D50 sSmallPortraitJohnTanakaCompTexInfo[] = { { 17, aSmallPortraitJohnTanakaTex, 40, 40, 0x8A0 }, { 0 } };
unk_80077D50 sSmallPortraitBioRexCompTexInfo[] = { { 17, aSmallPortraitBioRexTex, 40, 40, 0x89B }, { 0 } };
unk_80077D50 sSmallPortraitKateAlenCompTexInfo[] = { { 17, aSmallPortraitKateAlenTex, 40, 40, 0x6D1 }, { 0 } };
unk_80077D50 sSmallPortraitGomarAndShiohCompTexInfo[] = { { 17, aSmallPortraitGomarAndShiohTex, 40, 40, 0x958 },
                                                          { 0 } };
unk_80077D50 sSmallPortraitMichaelChainCompTexInfo[] = { { 17, aSmallPortraitMichaelChainTex, 40, 40, 0x8D8 }, { 0 } };
unk_80077D50 sSmallPortraitBillyCompTexInfo[] = { { 17, aSmallPortraitBillyTex, 40, 40, 0x8E8 }, { 0 } };
unk_80077D50 sSmallPortraitDrClashCompTexInfo[] = { { 17, aSmallPortraitDrClashTex, 40, 40, 0xA0A }, { 0 } };
unk_80077D50 sSmallPortraitJackLevinCompTexInfo[] = { { 17, aSmallPortraitJackLevinTex, 40, 40, 0x797 }, { 0 } };
unk_80077D50 sSmallPortraitBloodFalconCompTexInfo[] = { { 17, aSmallPortraitBloodFalconTex, 40, 40, 0x896 }, { 0 } };
unk_80077D50 sSmallPortraitLeonCompTexInfo[] = { { 17, aSmallPortraitLeonTex, 40, 40, 0x8BC }, { 0 } };
unk_80077D50 sSmallPortraitJamesMcCloudCompTexInfo[] = { { 17, aSmallPortraitJamesMcCloudTex, 40, 40, 0x879 }, { 0 } };
unk_80077D50 sSmallPortraitBlackShadowCompTexInfo[] = { { 17, aSmallPortraitBlackShadowTex, 40, 40, 0x7AB }, { 0 } };
unk_80077D50 sSmallPortraitCaptainFalconAltCompTexInfo[] = { { 17, aSmallPortraitCaptainFalconAltTex, 40, 40, 0x859 },
                                                             { 0 } };
unk_80077D50 sSmallPortraitSamuraiGorohAltCompTexInfo[] = { { 17, aSmallPortraitSamuraiGorohAltTex, 40, 40, 0x813 },
                                                            { 0 } };
unk_80077D50 sSmallPortraitJodySummerAltCompTexInfo[] = { { 17, aSmallPortraitJodySummerAltTex, 40, 40, 0x859 },
                                                          { 0 } };

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

unk_80077D50 sNameCardCaptainFalconCompTexInfo[] = { { 18, aNameCardCaptainFalconTex, 80, 40, 0x6B4 }, { 0 } };
unk_80077D50 sNameCardDrStewartCompTexInfo[] = { { 18, aNameCardDrStewartTex, 80, 40, 0x653 }, { 0 } };
unk_80077D50 sNameCardPicoCompTexInfo[] = { { 18, aNameCardPicoTex, 80, 40, 0x4BD }, { 0 } };
unk_80077D50 sNameCardSamuraiGorohCompTexInfo[] = { { 18, aNameCardSamuraiGorohTex, 80, 40, 0x770 }, { 0 } };
unk_80077D50 sNameCardJodySummerCompTexInfo[] = { { 18, aNameCardJodySummerTex, 80, 40, 0x5F4 }, { 0 } };
unk_80077D50 sNameCardMrEadCompTexInfo[] = { { 18, aNameCardMrEadTex, 80, 40, 0x505 }, { 0 } };
unk_80077D50 sNameCardBabaCompTexInfo[] = { { 18, aNameCardBabaTex, 80, 40, 0x59A }, { 0 } };
unk_80077D50 sNameCardOctomanCompTexInfo[] = { { 18, aNameCardOctomanTex, 80, 40, 0x54E }, { 0 } };
unk_80077D50 sNameCardGomarAndShiohCompTexInfo[] = { { 18, aNameCardGomarAndShiohTex, 80, 40, 0x639 }, { 0 } };
unk_80077D50 sNameCardKateAlenCompTexInfo[] = { { 18, aNameCardKateAlenTex, 80, 40, 0x651 }, { 0 } };
unk_80077D50 sNameCardRogerBusterCompTexInfo[] = { { 18, aNameCardRogerBusterTex, 80, 40, 0x5E1 }, { 0 } };
unk_80077D50 sNameCardJamesMcCloudCompTexInfo[] = { { 18, aNameCardJamesMcCloudTex, 80, 40, 0x5A4 }, { 0 } };
unk_80077D50 sNameCardLeonCompTexInfo[] = { { 18, aNameCardLeonTex, 80, 40, 0x5E4 }, { 0 } };
unk_80077D50 sNameCardAntonioGusterCompTexInfo[] = { { 18, aNameCardAntonioGusterTex, 80, 40, 0x5FA }, { 0 } };
unk_80077D50 sNameCardBlackShadowCompTexInfo[] = { { 18, aNameCardBlackShadowTex, 80, 40, 0x734 }, { 0 } };
unk_80077D50 sNameCardMichaelChainCompTexInfo[] = { { 18, aNameCardMichaelChainTex, 80, 40, 0x626 }, { 0 } };
unk_80077D50 sNameCardJackLevinCompTexInfo[] = { { 18, aNameCardJackLevinTex, 80, 40, 0x5E7 }, { 0 } };
unk_80077D50 sNameCardSuperArrowCompTexInfo[] = { { 18, aNameCardSuperArrowTex, 80, 40, 0x64D }, { 0 } };
unk_80077D50 sNameCardMrsArrowCompTexInfo[] = { { 18, aNameCardMrsArrowTex, 80, 40, 0x5FF }, { 0 } };
unk_80077D50 sNameCardJohnTanakaCompTexInfo[] = { { 18, aNameCardJohnTanakaTex, 80, 40, 0x54E }, { 0 } };
unk_80077D50 sNameCardBeastmanCompTexInfo[] = { { 18, aNameCardBeastmanTex, 80, 40, 0x6C2 }, { 0 } };
unk_80077D50 sNameCardZodaCompTexInfo[] = { { 18, aNameCardZodaTex, 80, 40, 0x4CB }, { 0 } };
unk_80077D50 sNameCardDrClashCompTexInfo[] = { { 18, aNameCardDrClashTex, 80, 40, 0x5ED }, { 0 } };
unk_80077D50 sNameCardSilverNeelsenCompTexInfo[] = { { 18, aNameCardSilverNeelsenTex, 80, 40, 0x7A4 }, { 0 } };
unk_80077D50 sNameCardBioRexCompTexInfo[] = { { 18, aNameCardBioRexTex, 80, 40, 0x4E6 }, { 0 } };
unk_80077D50 sNameCardDraqCompTexInfo[] = { { 18, aNameCardDraqTex, 80, 40, 0x465 }, { 0 } };
unk_80077D50 sNameCardBillyCompTexInfo[] = { { 18, aNameCardBillyTex, 80, 40, 0x50A }, { 0 } };
unk_80077D50 sNameCardBloodFalconCompTexInfo[] = { { 18, aNameCardBloodFalconTex, 80, 40, 0x6BF }, { 0 } };
unk_80077D50 sNameCardMightyGazelleCompTexInfo[] = { { 18, aNameCardMightyGazelleTex, 80, 40, 0x468 }, { 0 } };
unk_80077D50 sNameCardTheSkullCompTexInfo[] = { { 18, aNameCardTheSkullTex, 80, 40, 0x454 }, { 0 } };

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

unk_80077D50 sSelectMachineCompTexInfo[] = { { 4, aSelectMachineTex, 160, 24, 0 }, { 0 } };
unk_80077D50 s1PIconCompTexInfo[] = { { 17, a1PIconTex, 40, 40, 0x19E }, { 0 } };
unk_80077D50 s2PIconCompTexInfo[] = { { 17, a2PIconTex, 40, 40, 0x19C }, { 0 } };
unk_80077D50 s3PIconCompTexInfo[] = { { 17, a3PIconTex, 40, 40, 0x19A }, { 0 } };
unk_80077D50 s4PIconCompTexInfo[] = { { 17, a4PIconTex, 40, 40, 0x19A }, { 0 } };

unk_80077D50* sPlayerNumIconCompTexInfos[] = {
    s1PIconCompTexInfo,
    s2PIconCompTexInfo,
    s3PIconCompTexInfo,
    s4PIconCompTexInfo,
};

unk_80077D50 sMachineSelectCursorCompTexInfo[] = { { 17, aMachineSelectCursorTex, 40, 40, 0x277 }, { 0 } };
unk_80077D50 sMachineInfoGraphCompTexInfo[] = { { 17, aMachineInfoGraphTex, 128, 64, 0x837 }, { 0 } };
unk_80077D50 sMachineAccelerationMaxSpeedCompTexInfo[] = { { 17, aMachineAccelerationMaxSpeedTex, 128, 64, 0x7E9 },
                                                           { 0 } };
unk_80077D50 sMachineBodyBoostGripCompTexInfo[] = { { 17, aMachineBodyBoostGripTex, 128, 64, 0x7E4 }, { 0 } };
unk_80077D50 sMachineInfoGraphSmallCompTexInfo[] = { { 18, aMachineInfoGraphSmallTex, 80, 40, 0x4C2 }, { 0 } };
unk_80077D50 sMachineAccelerationMaxSpeedSmallCompTexInfo[] = {
    { 18, aMachineAccelerationMaxSpeedSmallTex, 80, 40, 0x33E }, { 0 }
};
unk_80077D50 sMachineBodyBoostGripSmallCompTexInfo[] = { { 17, aMachineBodyBoostGripSmallTex, 80, 40, 0x35E }, { 0 } };
unk_80077D50 sEngineSliderCompTexInfo[] = { { 17, aEngineSliderTex, 16, 16, 0x066 }, { 0 } };
unk_80077D50 sNoviceJackTrophyCompTexInfo[] = { { 17, aNoviceJackTrophyTex, 16, 16, 0x092 }, { 0 } };
unk_80077D50 sNoviceQueenTrophyCompTexInfo[] = { { 17, aNoviceQueenTrophyTex, 16, 16, 0x093 }, { 0 } };
unk_80077D50 sNoviceKingTrophyCompTexInfo[] = { { 17, aNoviceKingTrophyTex, 16, 16, 0x098 }, { 0 } };
unk_80077D50 sNoviceJokerTrophyCompTexInfo[] = { { 17, aNoviceJokerTrophyTex, 16, 16, 0x091 }, { 0 } };
unk_80077D50 sNoviceXTrophyCompTexInfo[] = { { 17, aNoviceXTrophyTex, 16, 16, 0x097 }, { 0 } };
unk_80077D50 sStandardJackTrophyCompTexInfo[] = { { 17, aStandardJackTrophyTex, 16, 16, 0x0A6 }, { 0 } };
unk_80077D50 sStandardQueenTrophyCompTexInfo[] = { { 17, aStandardQueenTrophyTex, 16, 16, 0x0A3 }, { 0 } };
unk_80077D50 sStandardKingTrophyCompTexInfo[] = { { 17, aStandardKingTrophyTex, 16, 16, 0x0B4 }, { 0 } };
unk_80077D50 sStandardJokerTrophyCompTexInfo[] = { { 17, aStandardJokerTrophyTex, 16, 16, 0x09C }, { 0 } };
unk_80077D50 sStandardXTrophyCompTexInfo[] = { { 17, aStandardXTrophyTex, 16, 16, 0x0A2 }, { 0 } };
unk_80077D50 sExpertJackTrophyCompTexInfo[] = { { 17, aExpertJackTrophyTex, 16, 16, 0x0AA }, { 0 } };
unk_80077D50 sExpertQueenTrophyCompTexInfo[] = { { 17, aExpertQueenTrophyTex, 16, 16, 0x0B1 }, { 0 } };
unk_80077D50 sExpertKingTrophyCompTexInfo[] = { { 17, aExpertKingTrophyTex, 16, 16, 0x0B6 }, { 0 } };
unk_80077D50 sExpertJokerTrophyCompTexInfo[] = { { 17, aExpertJokerTrophyTex, 16, 16, 0x0A8 }, { 0 } };
unk_80077D50 sExpertXTrophyCompTexInfo[] = { { 17, aExpertXTrophyTex, 16, 16, 0x097 }, { 0 } };
unk_80077D50 sMasterJackTrophyCompTexInfo[] = { { 17, aMasterJackTrophyTex, 16, 16, 0x0CB }, { 0 } };
unk_80077D50 sMasterQueenTrophyCompTexInfo[] = { { 17, aMasterQueenTrophyTex, 16, 16, 0x0D4 }, { 0 } };
unk_80077D50 sMasterKingTrophyCompTexInfo[] = { { 17, aMasterKingTrophyTex, 16, 16, 0x0DD }, { 0 } };
unk_80077D50 sMasterJokerTrophyCompTexInfo[] = { { 17, aMasterJokerTrophyTex, 16, 16, 0x0C8 }, { 0 } };
unk_80077D50 sMasterXTrophyCompTexInfo[] = { { 17, aMasterXTrophyTex, 16, 16, 0x0BF }, { 0 } };
unk_80077D50 sNoTrophyCompTexInfo[] = { { 17, aNoTrophyTex, 16, 16, 0x059 }, { 0 } };

unk_80077D50* sTrophyCompTexInfos[] = {
    sNoviceJackTrophyCompTexInfo,    sNoviceQueenTrophyCompTexInfo,  sNoviceKingTrophyCompTexInfo,
    sNoviceJokerTrophyCompTexInfo,   sNoviceXTrophyCompTexInfo,      sStandardJackTrophyCompTexInfo,
    sStandardQueenTrophyCompTexInfo, sStandardKingTrophyCompTexInfo, sStandardJokerTrophyCompTexInfo,
    sStandardXTrophyCompTexInfo,     sExpertJackTrophyCompTexInfo,   sExpertQueenTrophyCompTexInfo,
    sExpertKingTrophyCompTexInfo,    sExpertJokerTrophyCompTexInfo,  sExpertXTrophyCompTexInfo,
    sMasterJackTrophyCompTexInfo,    sMasterQueenTrophyCompTexInfo,  sMasterKingTrophyCompTexInfo,
    sMasterJokerTrophyCompTexInfo,   sMasterXTrophyCompTexInfo,      sNoTrophyCompTexInfo,
};

static unk_80077D50 sNoviceCompTexInfo[] = { { 17, aNoviceTex, 64, 18, 0x144 }, { 0 } };
static unk_80077D50 sStandardCompTexInfo[] = { { 17, aStandardTex, 64, 18, 0x14C }, { 0 } };
static unk_80077D50 sExpertCompTexInfo[] = { { 17, aExpertTex, 64, 18, 0x149 }, { 0 } };
static unk_80077D50 sMasterCompTexInfo[] = { { 17, aMasterTex, 64, 18, 0x14E }, { 0 } };

static unk_80077D50* sDifficultyCompTexInfos[] = {
    sNoviceCompTexInfo,
    sStandardCompTexInfo,
    sExpertCompTexInfo,
    sMasterCompTexInfo,
};

unk_80077D50 sBoostCompTexInfo[] = { { 17, aBoostTex, 20, 8, 0x5E }, { 0 } };
unk_80077D50 sBodyCompTexInfo[] = { { 17, aBodyTex, 16, 8, 0x46 }, { 0 } };
unk_80077D50 sGripCompTexInfo[] = { { 17, aGripTex, 16, 8, 0x4F }, { 0 } };

unk_80077D50* sMachineStatCompTexInfos[] = {
    sBodyCompTexInfo,
    sBoostCompTexInfo,
    sGripCompTexInfo,
};

static unk_80077D50 sOKCompTexInfo[] = { { 17, aOKTex, 32, 16, 0x112 }, { 0 } };

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

static unk_80077D50 sTitleBackgroundMainCompTexInfo[] = { { 17, aTitleBackgroundMainTex, 304, 240, 0x14A5D }, { 0 } };
static unk_80077D50 sTitleBackgroundComicCompTexInfo[] = { { 17, aTitleBackgroundComicTex, 320, 240, 0x118DB }, { 0 } };
static unk_80077D50 sTitleBackgroundFalconCompTexInfo[] = { { 17, aTitleBackgroundFalconTex, 320, 240, 0x9E0A },
                                                            { 0 } };

static unk_80077D50* sTitleBackgroundCompTexInfos[] = {
    sTitleBackgroundMainCompTexInfo,
    sTitleBackgroundComicCompTexInfo,
    sTitleBackgroundFalconCompTexInfo,
};

unk_80077D50 sTitleLogoCompTexInfo[] = { { 18, aTitleLogoTex, 160, 65, 0x26C0 }, { 0 } };
unk_80077D50 sTitlePushStartCompTexInfo[] = { { 18, aTitlePushStartTex, 80, 40, 0x389 }, { 0 } };
unk_80077D50 sTitleNoControllerCompTexInfo[] = { { 20, aTitleNoControllerTex, 160, 32, 0x259 }, { 0 } };
unk_80077D50 sTitleExpansionPakWarningCompTexInfo[] = { { 20, aTitleExpansionPakWarningTex, 160, 32, 0x4EA }, { 0 } };
unk_80077D50 sTitleDiskWarningCompTexInfo[] = { { 20, aTitleDiskWarningTex, 160, 32, 0x3B7 }, { 0 } };

unk_80077D50* sTitleWarningCompTexInfos[] = {
    sTitleNoControllerCompTexInfo,
    sTitleExpansionPakWarningCompTexInfo,
    sTitleDiskWarningCompTexInfo,
};

unk_80077D50 sCopyrightCompTexInfo[] = { { 17, aCopyrightTex, 128, 14, 0x3EC }, { 0 } };

UNUSED s32 D_i4_8011D628[] = { 85, 21, 120, 150 };

s32 D_i4_8011D638 = 0;

const s32 D_i4_8011D674[] = { -4, 0, -6, -24, 2, -1, 5, -25 };

const s32 D_i4_8011D694[] = { 19, 60, 19, 136, 299, 60, 299, 136, 42, 10, 42, 120 };

const s32 D_i4_8011D6C4[] = { 25, 20, 25, 125, 164, 20, 164, 125 };

extern s16 D_800CCFE8;
extern s32 D_800CD380;
extern s8 D_800CD3A8[];
extern s32 D_800CD3B0;
extern s8 gSettingEverythingUnlocked;
extern f32 D_800CE748;
extern f32 D_800CE74C;
extern f32 D_800CE750;
extern s32 gNumPlayers;

void func_i4_80115DF0(void) {
    s32 i;

    D_800CCFE8 = 3;
    D_800CE750 = 0.1f;
    D_800CE74C = D_800CE750;
    D_800CE748 = D_800CE74C;
    func_80085610();
    func_8008969C();
    D_800CD3B0 = 0;

    for (i = 0; i < 4; i++) {
        D_800CD3A8[i] = 0;
        D_i4_8011D780[i] = func_8007E11C(gRacers[i].character);
    }
    D_i4_8011D774 = ((func_8007E008() / 3) * 6) + 6;
    if (gSettingEverythingUnlocked != 0) {
        D_i4_8011D774 = 30;
    }
    if (D_i4_8011D774 > 30) {
        D_i4_8011D774 = 30;
    }
    func_800794B0(5, 0, 0, 1);
    func_800794B0(0x1E, 0, 0, 4);
    func_800794B0(0x1F, 0x50, 0xD, 4);
    func_800794B0(0x2C, 0x3C, 0xA, 8);
    func_800794B0(0x2D, 0, 0, 0xA);

    switch (gNumPlayers) {
        case 4:
            func_800794B0(0x44, 0, 0, 0xC);
            func_800794B0(0x2B, 0x3C, 0xA, 0xC);
            func_800794B0(0x24, 0x104, 0xBE, 6);
            /* fallthrough */
        case 3:
            func_800794B0(0x43, 0, 0, 0xC);
            func_800794B0(0x2A, 0x3C, 0xA, 0xC);
            func_800794B0(0x23, 0x104, 0xA, 6);
            /* fallthrough */
        case 2:
            func_800794B0(0x42, 0, 0, 0xC);
            func_800794B0(0x29, 0x3C, 0xA, 0xC);
            func_800794B0(0x22, 0x14, 0xBE, 6);
            /* fallthrough */
        case 1:
            break;
    }

    if (D_800CD380 == 0) {
        func_800794B0(0x2F, 0, 0, 0xC);
    }
    func_800794B0(0x41, 0, 0, 0xC);
    func_800794B0(0x28, 0x3C, 0xA, 0xC);
    func_800794B0(0x21, 0x14, 0xA, 6);

    if (gNumPlayers == 1) {
        func_800794B0(0x30, 0, 0, 0xC);
    }

    func_800794B0(0x2E, 0, 0, 0xC);
}

extern s32 D_800CD3B4;
extern s32 gGameMode;
extern s32 gCourseIndex;
extern f32 gCharacterLastEngine[];
extern f32 gPlayerEngine[];

void func_i4_801160D8(void) {
    s32 i;

    D_800CCFE8 = 3;
    func_80085610();
    func_8008969C();
    D_800CD3B4 = 0;

    for (i = 0; i < 4; i++) {
        D_800CD3A8[i] = 0;
        if (gGameMode != GAMEMODE_4012) {
            gPlayerEngine[i] = 0.5f;
        }
    }

    if ((gNumPlayers == 1) && (gCourseIndex < 24)) {
        Save_UpdateCharacterSave(gCourseIndex);
        gPlayerEngine[0] = gCharacterLastEngine[gRacers[0].character];
    }

    func_800794B0(5, 0, 0, 1);
    func_800794B0(0x3B, 0, 0, 4);
    func_800794B0(0x32, 0, 0, 0xC);
    func_800794B0(0x33, 0xA0, 0x22, 0xA);
    func_800794B0(0x34, 0xA0, 0x61, 0xA);
    if (gNumPlayers == 2) {
        func_800794B0(0x3A, 0xA0, 0x61, 0xD);
    }
    func_800794B0(0x35, 0, 0, 0xC);
    func_800794B0(0x36, 0x14, 0xB9, 0xC);
    func_800794B0(0x37, 0xD0, 0x55, 0xB);
    func_800794B0(0x39, 0, 0, 0xE);

    switch (gNumPlayers) {
        case 4:
            func_800794B0(0x3F, -6, -5, 8);
            /* fallthrough */
        case 3:
            func_800794B0(0x3E, -6, -5, 8);
            /* fallthrough */
        case 2:
            func_800794B0(0x38, 0, 0, 6);
            func_800794B0(0x3D, -6, -5, 8);
            /* fallthrough */
        case 1:
            func_800794B0(0x3C, -6, -5, 8);
            break;
    }
}

extern Controller gSharedController;
extern s32 D_800CD380;
extern s32 D_800CD3B0;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;
extern s32 gPlayerControlPorts[];
extern Controller gControllers[];
extern s8 D_800CD3AC[];

s32 func_i4_8011631C(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 pad;
    s16 pad2;
    s16 temp_v0_2;

    func_8008675C();

    for (i = 3; i >= 0; i--) {

        func_8007DABC(&gControllers[gPlayerControlPorts[i]]);
        if (i >= gNumPlayers) {
            if ((gInputButtonPressed & BTN_B) && (D_800CD3B0 == 0)) {
                func_800BA8D8(0x10);
                D_800CD3B0 = 1;
                if (D_800CD380 == 2) {
                    return GAMEMODE_FLX_MAIN_MENU;
                }
                // FAKE
                if ((gRacers + i)->character) {}
                return GAMEMODE_800A;
            }
            continue;
        }
        if (gInputButtonPressed & (BTN_L | BTN_R | BTN_CLEFT | BTN_CDOWN)) {
            if ((gSharedController.buttonCurrent & 0x20) && (gSharedController.buttonCurrent & 0x10) &&
                (gSharedController.buttonCurrent & 2) && (gSharedController.buttonCurrent & 4) &&
                (func_80079E88(0x2D)->unk_20 == 0) && (D_800CD3B0 != 3)) {
                func_80079E88(0x2D)->unk_20 = 1;
                D_i4_8011D778 = 1.0f;
                D_i4_8011D77C = 0.0f;
                func_800BA8D8(0x17);
                return gGameMode;
            }
        }

        switch (D_800CD3B0) {
            case 0:
                temp_v0_2 = D_i4_8011D780[i];

                if (D_800CD3A8[i] == 0) {
                    if (gInputPressed & BTN_LEFT) {
                        if (D_i4_8011D780[i] % 6) {
                            D_i4_8011D780[i]--;
                        } else {
                            D_i4_8011D780[i] += 5;
                        }
                    } else if (gInputPressed & BTN_RIGHT) {
                        if ((D_i4_8011D780[i] % 6) < 5) {
                            D_i4_8011D780[i]++;
                        } else {
                            D_i4_8011D780[i] -= 5;
                        }
                    }
                    if (gInputPressed & BTN_UP) {
                        D_i4_8011D780[i] -= 6;
                    } else if (gInputPressed & BTN_DOWN) {
                        D_i4_8011D780[i] += 6;
                    }
                }

                D_i4_8011D780[i] += D_i4_8011D774;
                D_i4_8011D780[i] %= D_i4_8011D774;
                gRacers[i].character = func_8007E10C(D_i4_8011D780[i]);

                if (temp_v0_2 != D_i4_8011D780[i]) {
                    func_800BA710(i, 0x1E);
                    D_800CD3AC[i] = 1;
                    gPlayerEngine[i] = 0.5f;
                }

                if (gInputButtonPressed & BTN_B) {
                    func_800BA710(i, 0x10);

                    if (D_800CD3A8[i] != 0) {
                        D_800CD3A8[i] = 0;
                    } else {
                        D_800CD3B0 = 1;
                        if (D_800CD380 == 2) {
                            return GAMEMODE_FLX_MAIN_MENU;
                        }
                        return GAMEMODE_800A;
                    }
                } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    if (D_800CD3A8[i] == 0) {
                        D_800CD3A8[i] = 1;
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
                    if (D_800CD3A8[j] == 0) {
                        k++;
                        break;
                    }
                }

                if (k == 0) {
                    D_800CD3B0 = 2;
                }
                break;
            case 2:
                if (gInputButtonPressed & BTN_B) {
                    D_800CD3A8[i] = 0;
                    D_800CD3B0 = 0;
                    func_800BA710(i, 0x10);
                    break;
                }
                if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    func_800BA710(i, 0x3E);
                    D_800CD3B0 = 3;
                    return GAMEMODE_LX_MACHINE_SETTINGS;
                }
                break;
        }
    }
    return gGameMode;
}

extern s32 D_i2_80106DA4;

s32 func_i4_801168D4(void) {
    s32 i;
    s32 j;
    s32 k;
    Controller* temp_s1;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 var_fa1;
    s32 var_v0;

    func_8008675C();
    if (D_i2_80106DA4 != 0) {
        return gGameMode;
    }

    for (i = gNumPlayers - 1; i >= 0; i--) {
        temp_s1 = &gControllers[gPlayerControlPorts[i]];
        func_8007DABC(temp_s1);

        switch (D_800CD3B4) {
            case 0:
                if (D_800CD3A8[i] == 0) {

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
                    var_v0 = temp_s1->stickX;
                    temp_fa0 = gPlayerEngine[i];
                    temp_fv0 = (f32) var_v0 * 0.003;
                    var_fa1 = SQ(temp_fv0);
                    if (var_fa1 < 0.001) {
                        var_fa1 = 0.0078125f;
                        var_v0 = 0;
                        if (gInputPressed & 0x200) {
                            var_v0 = -1;
                        } else if (!(gInputPressed & 0x100)) {
                            var_fa1 = 0.0f;
                        }
                    }
                    if (var_v0 < 0) {
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

                    if (D_800CD3A8[i] != 0) {
                        D_800CD3A8[i] = 0;
                    } else {
                        D_800CD3B4 = 1;
                        if (gGameMode == GAMEMODE_LX_MACHINE_SETTINGS) {
                            return GAMEMODE_FLX_MACHINE_SELECT;
                        }
                        return GAMEMODE_800F;
                    }
                } else if ((gInputButtonPressed & (BTN_A | BTN_START)) && (D_800CD3A8[i] == 0)) {
                    func_800BA710(i, 0x21);
                    D_800CD3A8[i] = 1;
                }

                for (k = 0, j = 0; j < gNumPlayers; j++) {
                    if (D_800CD3A8[j] == 0) {
                        k++;
                        break;
                    }
                }

                if (k == 0) {
                    D_800CD3B4 = 2;
                }
                break;
            case 2:
                if (gInputButtonPressed & BTN_B) {
                    D_800CD3A8[i] = 0;
                    D_800CD3B4 = 0;
                    func_800BA710(i, 0x10);
                } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    func_800BA710(i, 0x3E);
                    func_8007E0CC();
                    D_800CD3B4 = 3;
                    switch (D_800CD380) {
                        case 0:
                            return GAMEMODE_GP_RACE;
                        case 1:
                            return GAMEMODE_TIME_ATTACK;
                        case 5:
                            return GAMEMODE_PRACTICE;
                        case 3:
                            return gNumPlayers + 1;
                        case 2:
                            return GAMEMODE_DEATH_RACE;
                    }
                }
            case 1:
            case 3:
            default:
                break;
        }
    }

    return gGameMode;
}

extern unk_800DCE48 D_800DCE48;

Gfx* func_i4_80116DC4(Gfx* gfx) {
    gfx = func_80079BC8(gfx);
    func_800790D4();
    if (gGameMode != D_800DCE48.gameMode) {
        func_80089724();
    }
    return gfx;
}

Gfx* func_i4_80116E10(Gfx* gfx) {
    gfx = func_80079BC8(gfx);
    func_800790D4();
    if (gGameMode != D_800DCE48.gameMode) {
        func_80089724();
    }
    return gfx;
}

s32 func_i4_80116E5C(s32 arg0) {
    return arg0;
}

void func_i4_80116E64(void) {
    func_80077D50(sSelectMachineCompTexInfo, 0);
}

void func_i4_80116E8C(unk_800E3A28* arg0) {
    s32 i;

    if (gNumPlayers == 1) {
        func_80077D50(sPortraitCompTexInfos[gRacers[0].character], 0);
        return;
    }

    for (i = 0; i < gNumPlayers; i++) {
        func_80077D50(sSmallPortraitCompTexInfos[gRacers[i].character], 0);
    }
}

void func_i4_80116F48(unk_800E3A28* arg0) {
    s32 index = arg0->unk_00 - 60;

    arg0->unk_04 = gRacers[index].character;
    arg0->unk_04 = func_i4_80116E5C(arg0->unk_04);

    if (gNumPlayers == 1) {
        func_80077D50(sPortraitBackgroundCompTexInfo, 0);
        arg0->unk_18 = func_800792D8(D_i4_8011C05C[arg0->unk_04]);
    } else {
        arg0->unk_18 = func_800792D8(D_i4_8011C7A4[arg0->unk_04]);
    }
}

void func_i4_80117008(unk_800E3A28* arg0) {
    arg0->unk_18 = func_800792D8(D_i4_8011C7A4[0]);
}

void func_i4_80117038(unk_800E3A28* arg0) {
    func_80077D50(sPlayerNumIconCompTexInfos[arg0->unk_00 - 0x28], 0);
}

void func_i4_8011706C(void) {
    func_80077D50(sMachineSelectCursorCompTexInfo, 0);
}

void func_i4_80117094(unk_800E3A28* arg0) {
    Vp* temp_v0;
    s32 i;
    s32 j;

    temp_v0 = (Vp*) func_800768F4(0, 30 * sizeof(Vp));
    arg0->unk_1C = temp_v0;

    for (i = 0; i < 30; i++) {
        temp_v0[i].vp.vscale[0] = 0x280;
        temp_v0[i].vp.vscale[1] = 0x1E0;
        temp_v0[i].vp.vscale[2] = 0x1FF;
        temp_v0[i].vp.vscale[3] = 0;
        temp_v0[i].vp.vtrans[0] = (((i % 6) * 0x28) + 0x39) << 2;
        temp_v0[i].vp.vtrans[1] = (((i / 6) * 0x22) + 0x39) << 2;
        temp_v0[i].vp.vtrans[2] = 0x1FF;
        temp_v0[i].vp.vtrans[3] = 0;
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

void func_i4_80117400(unk_800E3A28* arg0) {
    Vp* temp_v0;
    s32 i;
    s32 j;
    s32 k;

    temp_v0 = (Vp*) func_800768F4(0, 2 * 4 * sizeof(Vp));
    arg0->unk_1C = temp_v0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            temp_v0[i * 4 + j].vp.vscale[0] = 0x280;
            temp_v0[i * 4 + j].vp.vscale[1] = 0x1E0;
            temp_v0[i * 4 + j].vp.vscale[2] = 0x1FF;
            temp_v0[i * 4 + j].vp.vscale[3] = 0;

            switch (gNumPlayers) {
                case 1:
                    temp_v0[i * 4 + j].vp.vtrans[0] = ((i * -4) + 0xDC) << 2;
                    temp_v0[i * 4 + j].vp.vtrans[1] = ((i * 0xA) + 0xC8) << 2;
                    break;
                case 2:
                    temp_v0[i * 4 + j].vp.vtrans[0] = ((i * -6) + 0xE9) << 2;
                    temp_v0[i * 4 + j].vp.vtrans[1] = (((j % 2) * 0x69) + (i * 0xE) + 0x50) << 2;
                    break;
                default:
                    temp_v0[i * 4 + j].vp.vtrans[0] = (((j / 2) * 0x8C) + (i * -2) + 0x2B) << 2;
                    temp_v0[i * 4 + j].vp.vtrans[1] = (((j % 2) * 0x69) + (i * 5) + 0x35) << 2;
                    break;
            }

            temp_v0[i * 4 + j].vp.vtrans[2] = 0x1FF;
            temp_v0[i * 4 + j].vp.vtrans[3] = 0;
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

void func_i4_8011764C(void) {
    if (gNumPlayers == 1) {
        func_80077D50(sMachineInfoGraphCompTexInfo, 0);
        func_80077D50(sMachineAccelerationMaxSpeedCompTexInfo, 0);
    } else {
        func_80077D50(sMachineInfoGraphSmallCompTexInfo, 0);
        func_80077D50(sMachineAccelerationMaxSpeedSmallCompTexInfo, 0);
    }
}

void func_i4_801176BC(void) {
    if (gNumPlayers == 1) {
        func_80077D50(sMachineBodyBoostGripCompTexInfo, 0);
    } else {
        func_80077D50(sMachineBodyBoostGripSmallCompTexInfo, 0);
    }
}

void func_i4_8011770C(unk_800E3A28* arg0) {
    if (gNumPlayers == 1) {
        arg0->unk_18 = func_800792D8(D_i4_8011CE50[0]);
    }
}

void func_i4_8011774C(void) {
    func_80077D50(sEngineSliderCompTexInfo, 0);
}

void func_i4_80117774(unk_800E3A28* arg0) {
    s32 i;

    arg0->unk_18 = func_800768F4(0, 0x258);

    Save_UpdateCupSave(arg0->unk_18);

    for (i = 0; i < 21; i++) {
        func_80077D50(sTrophyCompTexInfos[i], 0);
    }

    for (i = 0; i < 4; i++) {
        func_80077D50(sDifficultyCompTexInfos[i], 0);
    }
}

void func_i4_80117808(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        func_80077D50(sMachineStatCompTexInfos[i], 0);
    }
}

void func_i4_80117854(unk_800E3A28* arg0) {
    func_80077D50(sOKCompTexInfo, 0);
    arg0->unk_10 = 50;
}

void func_i4_8011788C(unk_800E3A28* arg0) {
    func_80077D50(sOKCompTexInfo, 0);
    arg0->unk_0C = 50;
}

#define PACK_5551(r, g, b, a) (((((r) << 11) | ((g) << 6)) | ((b) << 1)) | (a))

#ifdef NON_MATCHING
// loop unroll issue
Gfx* func_i4_801178C4(Gfx* gfx) {
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
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i4/D4BD0/func_i4_801178C4.s")
#endif

Gfx* func_i4_80117B74(Gfx* gfx, unk_800E3A28* arg1) {
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    return func_80078EA0(gfx, sSelectMachineCompTexInfo, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_80117BE0(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    const s32* var_s0;

    if (gNumPlayers == 1) {
        gfx = func_80078EA0(gfx, sPortraitCompTexInfos[gRacers[0].character], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f,
                            1.0f);
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

Gfx* func_i4_80117D10(Gfx* gfx, unk_800E3A28* arg1) {
    s32 temp_v1;
    const s32* temp_v0;

    temp_v1 = arg1->unk_00 - 0x3C;
    temp_v0 = &D_i4_8011D6C4[temp_v1 * 2];
    switch (gNumPlayers) {
        case 1:
            gfx = func_80078EA0(gfx, sPortraitBackgroundCompTexInfo, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
            gfx = func_80078F80(gfx, &D_800E3F28[arg1->unk_18], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
            break;
        case 2:
            gfx = func_80078F80(gfx, &D_800E3F28[arg1->unk_18], temp_v0[0] - 4, temp_v0[1] + 0x1A, 0, 0, 0, 1.0f, 1.0f);
            break;
        default:
            gfx = func_80078F80(gfx, &D_800E3F28[arg1->unk_18], temp_v0[0], temp_v0[1] + 0x37, 0, 0, 0, 1.0f, 1.0f);
            break;
    }
    return gfx;
}

extern unk_800CF1B0 D_800F80C8[];

Gfx* func_i4_80117E98(Gfx* gfx, unk_800E3A28* arg1) {
    s32 temp_fp;
    s32 temp_s0;
    s32 temp_t0;
    s32 temp_t2;
    s8* temp_a3;
    s32 i;

    temp_t2 = arg1->unk_00 - 0x41;

    temp_a3 = &D_800F80C8[gRacers[temp_t2].character].machineStats;
    temp_fp = D_i4_8011D694[temp_t2 * 2 + 0];
    temp_t0 = D_i4_8011D694[temp_t2 * 2 + 1];
    if (temp_t2 < 2) {
        for (i = 0; i < 3; i++) {
            gfx = func_80078EA0(gfx, sMachineStatCompTexInfos[i], temp_fp, (temp_t0 - 7) + i * 20, 0, 0, 0, 1.0f, 1.0f);
            temp_s0 = sMachineStatValues[temp_a3[i]];
            gfx = func_i2_80106450(gfx, temp_fp + 5, (temp_t0 + 10) + i * 20, temp_s0, 0, 2, 0);
        }
    } else {
        for (i = 0; i < 3; i++) {
            gfx = func_80078EA0(gfx, sMachineStatCompTexInfos[i], temp_fp - 0x14, (temp_t0 - 7) + i * 20, 0, 0, 0, 1.0f,
                                1.0f);
            temp_s0 = sMachineStatValues[temp_a3[i]];
            gfx = func_i2_80106450(gfx, (temp_fp - func_i2_801062E4(temp_s0, 2, 0)) - 5, (temp_t0 + 10) + i * 20,
                                   temp_s0, 0, 2, 0);
        }
    }
    return gfx;
}

Gfx* func_i4_801180EC(Gfx* gfx, unk_800E3A28* arg1) {
    s32 sp3C;
    s32* temp_v1;

    sp3C = arg1->unk_00 - 0x21;

    gfx = func_80078F80(gfx, &D_800E3F28[arg1->unk_18], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
    return func_80078EA0(gfx, sPlayerNumIconCompTexInfos[sp3C], D_i4_8011D674[sp3C * 2 + 0] + arg1->unk_0C,
                         D_i4_8011D674[sp3C * 2 + 1] + arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_801181C0(Gfx* gfx, unk_800E3A28* arg1) {
    return func_80078EA0(gfx, sPlayerNumIconCompTexInfos[arg1->unk_00 - 0x28], arg1->unk_0C, arg1->unk_10, 0, 0, 0,
                         1.0f, 1.0f);
}

extern u32 gGameFrameCount;

Gfx* func_i4_8011821C(Gfx* gfx, unk_800E3A28* arg1) {
    s32 temp_v0;
    s32 i;
    s32 temp_s3 = 30;

    for (i = 0; i < 4; i++) {
        if (func_80079E88(i + 0x28) != NULL) {
            temp_v0 = (u32) gGameFrameCount % temp_s3;
            if ((D_800CD3A8[i] != 0) || (temp_v0 >= 0xF)) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255 - ((temp_v0 * 510) / temp_s3));
            }
            temp_v0 = D_i4_8011D780[i];
            arg1->unk_0C = ((temp_v0 % 6) * 0x28) + 0x28;
            arg1->unk_10 = ((temp_v0 / 6) * 0x22) + 0x25;

            gfx = func_80078EA0(gfx, sMachineSelectCursorCompTexInfo, arg1->unk_0C, arg1->unk_10, 1, 0, 0, 1.0f, 1.0f);
        }
    }
    return gfx;
}

extern unk_struct_1DC D_800E5220[];
extern GfxPool D_1000000;
extern GfxPool* D_800DCCF0;

Gfx* func_i4_80118414(Gfx* gfx, unk_800E3A28* arg1) {
    bool var_t0;
    s32 i;
    s32 j;

    gSPPerspNormalize(gfx++, D_800E5220[0].unk_118);

    gSPMatrix(gfx++, D_1000000.unk_20208, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gSPDisplayList(gfx++, D_303A5F8);

    gSPLight(gfx++, &D_1000000.unk_21A88[0].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].a, 2);
    gSPNumLights(gfx++, NUMLIGHTS_1);

    Lights_SetSource(&D_800DCCF0->unk_21A88[0], 0, 0, 0, 255, 255, 255, 100, 50, 69);
    Lights_SetSource(&D_800DCCF0->unk_21A88[1], 0, 0, 0, 100, 70, 70, 100, 50, 69);

    for (i = 0; i < 30; i++) {
        gDPPipeSync(gfx++);
        var_t0 = false;
        if (i < D_i4_8011D774) {
            j = 0;
        } else {
            j = 1;
        }

        gSPLight(gfx++, &D_1000000.unk_21A88[j].l[0], 1);
        gSPLight(gfx++, &D_1000000.unk_21A88[j].a, 2);
        gSPViewport(gfx++, (Vp*) arg1->unk_1C + i);

        for (j = 0; j < gNumPlayers; j++) {
            if (i == D_i4_8011D780[j]) {
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

Gfx* func_i4_80118734(Gfx* gfx, unk_800E3A28* arg1) {
    s32 var_v1;

    if (gNumPlayers == 1) {
        var_v1 = 0x109;
    } else {
        var_v1 = 0x90;
    }

    gfx = func_8007DB28(gfx, 0);
    return func_80078EA0(gfx, sOKCompTexInfo, arg1->unk_0C + var_v1, arg1->unk_10 + 0xD1, 1, 0, 0, 1.0f, 1.0f);
}

extern const char* gMachineNames[];

Gfx* func_i4_801187C0(Gfx* gfx) {
    s32 i;
    const char* temp_s1;
    const s32* var_s0;

    if (gNumPlayers == 1) {
        temp_s1 = gMachineNames[func_i4_80116E5C(gRacers[0].character)];
        gfx = func_i2_80106450(gfx, 0x122 - func_i2_801062E4(temp_s1, 1, 0), 0x22, temp_s1, 0, 1, 0);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_8011D6C4[i * 2];
            temp_s1 = gMachineNames[func_i4_80116E5C(gRacers[i].character)];
            gfx = func_i2_80106450(gfx, (var_s0[0] - func_i2_801062E4(temp_s1, 2, 0)) + 0x82, var_s0[1] + 0xA, temp_s1,
                                   0, 2, 0);
        }
    }
    return gfx;
}

extern u16 D_9000008[];
extern Gfx D_90186C8[];

Gfx* func_i4_80118918(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;

    gSPPerspNormalize(gfx++, D_800E5220[0].unk_118);

    gSPMatrix(gfx++, D_1000000.unk_20208, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gSPDisplayList(gfx++, D_303A758);

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    for (i = 0; i < gNumPlayers; i++) {
        if (D_i4_8011D4E4[i] == 0) {
            continue;
        }

        if (gControllers[gPlayerControlPorts[i]].buttonCurrent & 0xF) {
            D_i4_8011D4E4[i] = 0;
            continue;
        }

        gSPViewport(gfx++, (Vp*) arg1->unk_1C + i + 4);
        gSPMatrix(gfx++, &D_1000000.unk_20A88[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CD60(gfx, gRacers[i].character);
    }

    gSPDisplayList(gfx++, D_303A7D8);
    gDPSetBlendColor(gfx++, 0, 0, 0, 255);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, (Vp*) arg1->unk_1C + i);
        gSPMatrix(gfx++, &D_1000000.unk_21208[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CE70(gfx, gRacers[i].character);
    }

    gSPDisplayList(gfx++, D_303A5F8);

    Lights_SetSource(D_800DCCF0->unk_21A88, 0, 0, 0, 255, 255, 255, 50, 25, 34);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].a, 2);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, (Vp*) arg1->unk_1C + i);
        gSPMatrix(gfx++, &D_1000000.unk_20308[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CCBC(gfx, gRacers[i].character, gRacers[i].unk_2CC);
    }

    gSPDisplayList(gfx++, D_90186C8);

    Light_SetLookAtSource(&D_800DCCF0->unk_21B28, &D_800E5220[0].unk_15C);
    gSPLookAt(gfx++, &D_800DCCF0->unk_21B28);

    gSPTexture(gfx++, D_i4_8011D4E0, D_i4_8011D4E0, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureBlock(gfx++, D_9000008, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i4_8011D4DC);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, (Vp*) arg1->unk_1C + i);
        gSPMatrix(gfx++, &D_1000000.unk_20308[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CEA0(gfx, gRacers[i].character);
    }

    return gfx;
}

Gfx* func_i4_80118EC8(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    s16 temp_s4;
    s32 temp_s0;
    s32 temp_s1;

    if (gNumPlayers == 1) {
        temp_s4 = D_800F80C8[gRacers[0].character].unk_14;
        gfx = func_80078EA0(gfx, sMachineInfoGraphCompTexInfo, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
        gfx = func_i2_DrawMachineWeight(gfx, arg1->unk_0C + 0x66, arg1->unk_10 + 0x17, temp_s4);

        switch (D_800CD3B4) {
            case 0:
            case 1:
                gfx = func_8007DB28(gfx, 0);
                break;
            default:
                gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                break;
        }

        gfx = func_80078EA0(gfx, sMachineAccelerationMaxSpeedCompTexInfo, arg1->unk_0C + 3, arg1->unk_10 + 1, 1, 0, 0,
                            1.0f, 1.0f);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            temp_s4 = D_800F80C8[gRacers[i].character].unk_14;
            temp_s0 = D_i4_8011D6C4[i * 2 + 0];
            temp_s1 = D_i4_8011D6C4[i * 2 + 1];
            gfx = func_80078EA0(gfx, sMachineInfoGraphSmallCompTexInfo, temp_s0 + 0x2B, temp_s1 + 0xA, 0, 0, 0, 1.0f,
                                1.0f);
            gfx = func_i2_DrawMachineWeight(gfx, temp_s0 + 0x6E, temp_s1 + 0x1C, temp_s4);
            if (D_800CD3A8[i] == 0) {
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

Gfx* func_i4_80119170(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    s32 j;
    s32 leftOffset;
    s32 topOffset;
    s8* temp;
    s32 pad;

    if (gNumPlayers == 1) {
        gfx = func_80078EA0(gfx, sMachineBodyBoostGripCompTexInfo, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);

        for (i = 0; i < 3; i++) {
            temp = D_800F80C8[gRacers[0].character].machineStats;
            gfx = func_i2_DrawMachineStatValue(gfx, arg1->unk_0C + 0x69, arg1->unk_10 + i * 23 + 3, temp[i]);
        }
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            leftOffset = D_i4_8011D6C4[i * 2 + 0];
            topOffset = D_i4_8011D6C4[i * 2 + 1];

            gfx = func_80078EA0(gfx, sMachineBodyBoostGripSmallCompTexInfo, leftOffset + 0x2B, topOffset + 0x39, 0, 0,
                                0, 1.0f, 1.0f);

            for (j = 0; j < 3; j++) {
                temp = D_800F80C8[gRacers[i].character].machineStats;
                gfx = func_i2_80106450(gfx, leftOffset + 0x6B, topOffset + 0x43 + j * 14, sMachineStatValues[temp[j]],
                                       0, 2, 0);
            }
        }
    }
    return gfx;
}

Gfx* func_i4_801193B8(Gfx* gfx, unk_800E3A28* arg1) {
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
            gfx = func_i2_80106450(gfx, var_s3 + 0x6B, var_s1 + 0x43 + j * 14, temp2, 0, 2, 0);
        }
    }
    return gfx;
}

Gfx* func_i4_801194F8(Gfx* gfx, unk_800E3A28* arg1) {

    if (gNumPlayers == 1) {
        gfx = func_80078F80(gfx, &D_800E3F28[arg1->unk_18], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

Gfx* func_i4_80119574(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    s32 temp_v1;
    s32 left;
    s32 top;

    if (gNumPlayers == 1) {
        switch (D_800CD3B4) {
            case 0:
            case 1:
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
            switch (D_800CD3B4) {
                case 0:
                case 1:
                    if (D_800CD3A8[i] == 0) {
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

Gfx* func_i4_801197A0(Gfx* gfx) {

    gfx = func_8007AD44(gfx, 255, 255, 255, 12, 119, 307, 120);
    if (gNumPlayers >= 3) {
        gfx = func_8007AD44(gfx, 255, 255, 255, 158, 8, 159, 231);
    }
    return gfx;
}

extern s32 gDifficulty;
extern s8 D_800CD3C0;
extern s8 gSettingEverythingUnlocked;

Gfx* func_i4_80119834(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    s32 temp_v0;
    s32 difficulty;
    s32 trophyIndex;
    s32 pad;
    s32 var_t0;
    s8* var_t1;

    temp_v0 = func_8007E10C(D_i4_8011D780[0]);
    difficulty = 0;
    switch (D_800CD3B0) {
        case 2:
        case 3:
            break;
        default:
            if (((D_800CD3C0 >= 2) || (gSettingEverythingUnlocked != 0)) && (gSharedController.buttonCurrent & 8)) {
                difficulty = MASTER + 1;
            }
            if (gSharedController.buttonCurrent & 1) {
                difficulty = EXPERT + 1;
            }
            if (gSharedController.buttonCurrent & 4) {
                difficulty = STANDARD + 1;
            }
            if (gSharedController.buttonCurrent & 2) {
                difficulty = NOVICE + 1;
            }
            break;
    }

    if (difficulty != 0) {
        difficulty--;
    } else {
        difficulty = gDifficulty - D_800DCE48.unk_10;
    }

    if ((D_800CD3C0 >= 2) || (gSettingEverythingUnlocked != 0)) {
        var_t0 = 5;
    } else {
        if (D_800CD3C0 > 0) {
            var_t0 = 4;
        } else {
            var_t0 = 3;
        }
    }

    var_t1 = arg1->unk_18 + difficulty * 150 + temp_v0 * 5;

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

Gfx* func_i4_80119A64(Gfx* gfx, unk_800E3A28* arg1) {
    s32 pad[2];
    const char* machineName;

    machineName = gMachineNames[func_i4_80116E5C(gRacers[0].character)];

    gfx = func_i2_80106450(gfx, 160 - (func_i2_801062E4(machineName, 2, 0) / 2), 218, machineName, 0, 2, 0);
    gfx = func_i2_DrawMachineWeightSmall(gfx, 252, 221, D_800F80C8[func_8007E10C(D_i4_8011D780[0])].unk_14);
    return func_i2_80106450(gfx, 252, 221, "$", 0, 2, 0);
}

Gfx* func_i4_80119B50(Gfx* gfx, unk_800E3A28* arg1) {
    gfx = func_8007DB28(gfx, 0);
    return func_80078EA0(gfx, sOKCompTexInfo, arg1->unk_0C + 0x10B, arg1->unk_10 + 0xD0, 1, 0, 0, 1.0f, 1.0f);
}

void func_i4_80119BB8(unk_800E3A28* arg0) {
}

void func_i4_80119BC0(unk_800E3A28* arg0) {
    s32 index = arg0->unk_00 - 0x3C;
    s32 character = gRacers[index].character;

    character = func_i4_80116E5C(character);
    if (character != arg0->unk_04) {
        if (gNumPlayers == 1) {
            func_800793E8(arg0->unk_18, 0, D_i4_8011C05C[character]);
        } else {
            func_800793E8(arg0->unk_18, 0, D_i4_8011C7A4[character]);
        }
    }
    arg0->unk_04 = character;
}

void func_i4_80119C80(unk_800E3A28* arg0) {
    s32 index = arg0->unk_00 - 0x21;
    s32 character = gRacers[index].character;

    character = func_i4_80116E5C(character);
    if (character != arg0->unk_04) {
        func_800793E8(arg0->unk_18, 0, D_i4_8011C7A4[character]);
    }
    arg0->unk_04 = character;
}

void func_i4_80119D0C(unk_800E3A28* arg0) {
    s32 index = arg0->unk_00 - 0x28;
    s32 temp_v1;

    temp_v1 = D_i4_8011D780[index];
    arg0->unk_0C = ((temp_v1 % 6) * 0x28) + 0x28;
    arg0->unk_10 = ((temp_v1 / 6) * 0x22) + 0x25;
}

void func_i4_80119D84(unk_800E3A28* arg0) {
}

void func_i4_80119D8C(unk_800E3A28* arg0) {
    Racer* var_s0;
    f32 var_fv0;
    s32 i;

    if (arg0->unk_20 == 1) {
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
                arg0->unk_20 = 2;
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
        func_8006BC84(&D_800DCCF0->unk_20308[i], NULL, D_800CE748, D_800CE74C, D_800CE750, var_s0->unk_C0.x.x,
                      var_s0->unk_C0.x.y, var_s0->unk_C0.x.z, var_s0->unk_C0.y.x, var_s0->unk_C0.y.y,
                      var_s0->unk_C0.y.z, var_s0->unk_0C.unk_34.x, var_s0->unk_0C.unk_34.y, var_s0->unk_0C.unk_34.z);
        var_s0--;
        i--;
    }
}

void func_i4_8011A08C(unk_800E3A28* arg0) {
    Racer* var_s0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fv0;
    s32 i;
    s32 var_a1;
    Vp* var_v0;

    var_v0 = (Vp*) arg0->unk_1C;
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
        var_a1 = gControllers[gPlayerControlPorts[i]].buttonCurrent & 0xF;
        switch (var_a1) {
            case 3:
            case 12:
            case 15:
                break;
            case 0:
                var_fv0 = 0.015f;
                break;
            default:
                if (var_a1 & 2) {
                    var_fs0 = 0.03f;
                }
                if (var_a1 & 4) {
                    var_fs1 = 0.03f;
                }
                if (var_a1 & 8) {
                    var_fs1 = -0.03f;
                }
                if (var_a1 & 1) {
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
        func_8006BC84(&D_800DCCF0->unk_20308[i], NULL, var_fs2 * D_800CE748, var_fs2 * D_800CE74C, var_fs2 * D_800CE750,
                      var_s0->unk_C0.x.x, var_s0->unk_C0.x.y, var_s0->unk_C0.x.z, var_s0->unk_C0.y.x,
                      var_s0->unk_C0.y.y, var_s0->unk_C0.y.z, var_s0->unk_0C.unk_34.x, var_s0->unk_0C.unk_34.y,
                      var_s0->unk_0C.unk_34.z);
        func_8006BC84(&D_800DCCF0->unk_21208[i], NULL, (var_fs2 * 1.05f) * D_800CE748, (var_fs2 * 1.05f) * D_800CE74C,
                      (var_fs2 * 1.05f) * D_800CE750, var_s0->unk_C0.x.x, var_s0->unk_C0.x.y, var_s0->unk_C0.x.z,
                      var_s0->unk_C0.y.x, var_s0->unk_C0.y.y, var_s0->unk_C0.y.z, var_s0->unk_0C.unk_34.x,
                      var_s0->unk_0C.unk_34.y, var_s0->unk_0C.unk_34.z);
        func_8006BC84(&D_800DCCF0->unk_20A88[i], NULL, var_fs2 * D_800CE748, var_fs2 * D_800CE74C, var_fs2 * D_800CE750,
                      var_s0->unk_C0.x.x, var_s0->unk_C0.x.y, var_s0->unk_C0.x.z, var_s0->unk_C0.y.x,
                      var_s0->unk_C0.y.y, var_s0->unk_C0.y.z, var_s0->unk_0C.unk_34.x, var_s0->unk_0C.unk_34.y,
                      var_s0->unk_0C.unk_34.z);
        var_s0--;
        i--;
    }
}

void func_i4_8011A6A0(unk_800E3A28* arg0) {
    switch (D_800CD3B0) {
        case 2:
        case 3:
            func_8007A154(arg0, 0);
            break;
        default:
            func_8007A154(arg0, 50);
            break;
    }
}

void func_i4_8011A6EC(unk_800E3A28* arg0) {
    switch (D_800CD3B4) {
        case 2:
        case 3:
            func_8007A0A0(arg0, 0, 192);
            break;
        default:
            func_8007A0A0(arg0, 50, 192);
            break;
    }
}

void func_i4_8011A73C(unk_800E3A28* arg0) {

    if (arg0->unk_04 != gRacers[0].character) {
        if (gNumPlayers == 1) {
            func_800793E8(arg0->unk_18, 0, D_i4_8011CE50[gRacers[0].character % 30]);
        }
    }
    arg0->unk_04 = gRacers[0].character;
}

void func_i4_8011A7B8(void) {
    if ((D_800DCE48.gameMode == GAMEMODE_LX_MACHINE_SETTINGS) && (func_80079E88(0x2D)->unk_20 != 0)) {
        D_800CE748 = 0.075f;
        D_800CE74C = 0.125f;
        D_800CE750 = 0.105f;
    } else {
        D_800CE748 = D_800CE74C = D_800CE750 = 0.1f;
    }
}

void func_i4_8011A860(u16* arg0) {
}

void func_i4_8011A868(u16* texture) {
    s32 column;
    s32 pixel;
    s32 pixelIndex;
    s32 nextPixelIndex;

    column = (Math_Rand1() >> 3) % 304;
    pixelIndex = (((Math_Rand1() >> 4) % 240) * 304) + column;
    nextPixelIndex = (pixelIndex + 1) % (304 * 240);

    pixel = texture[pixelIndex];
    texture[pixelIndex] = texture[nextPixelIndex];
    texture[nextPixelIndex] = pixel;

    column = (Math_Rand1() >> 5) % 304;
    pixelIndex = (((Math_Rand1() >> 6) % 240) * 304) + column;
    nextPixelIndex = (pixelIndex + 304) % (304 * 240);

    pixel = texture[pixelIndex];
    texture[pixelIndex] = texture[nextPixelIndex];
    texture[nextPixelIndex] = pixel;
}

void func_i4_8011A98C(u16* texture) {
    u32 column;
    s32 pad;
    u32 pixelIndex;
    s32 pad2;
    u16* srcPixel;

    column = (Math_Rand1() >> 4) % 304;
    pixelIndex = (((Math_Rand1() >> 5) % 240) * 304) + column;

    srcPixel = (u16*) texture + pixelIndex;

    switch ((Math_Rand1() >> 6) % 4) {
        case 0:
            pixelIndex = (pixelIndex + 1) % (304 * 240);
            break;
        case 1:
            pixelIndex = (pixelIndex - 1) % (304 * 240);
            break;
        case 2:
            pixelIndex = (pixelIndex + 304) % (304 * 240);
            break;
        case 3:
            pixelIndex = (pixelIndex - 304) % (304 * 240);
            break;
    }

    if (texture[pixelIndex] < *srcPixel) {
        texture[pixelIndex] = *srcPixel;
    }
}

void func_i4_8011AAD8(u16* texture) {
    u32 column;
    s32 pad;
    u32 pixelIndex;
    s32 fakeVar;
    u16* srcPixel;

    column = (Math_Rand1() >> 5) % 304;
    pixelIndex = (((Math_Rand1() >> 6) % 240) * 304) + column;

    srcPixel = (u16*) texture + pixelIndex;

    switch ((Math_Rand1() >> 7) % 4) {
        case 0:
            pixelIndex = (pixelIndex + 1) % (304 * 240);
            break;
        case 1:
            pixelIndex = (pixelIndex - 1) % (304 * 240);
            break;
        case 2:
            pixelIndex = (pixelIndex + 304) % (304 * 240);
            break;
        case 3:
            pixelIndex = (pixelIndex - 304) % (304 * 240);
            break;
    }

    // FAKE
    fakeVar = texture[pixelIndex];

    if (*srcPixel - texture[pixelIndex] < 0) {
        texture[pixelIndex] = *srcPixel;
    }
}

void func_i4_8011AC24(u16* texture) {
    u32 column;
    s32 pad;
    u32 pixelIndex;
    s32 pad2;
    u16* srcPixel;

    column = (Math_Rand1() >> 6) % 304;
    pixelIndex = (((Math_Rand1() >> 7) % 240) * 304) + column;

    srcPixel = (u16*) texture + pixelIndex;

    switch ((Math_Rand1() >> 8) % 4) {
        case 0:
            pixelIndex = (pixelIndex + 1) % (304 * 240);
            break;
        case 1:
            pixelIndex = (pixelIndex - 1) % (304 * 240);
            break;
        case 2:
            pixelIndex = (pixelIndex + 304) % (304 * 240);
            break;
        case 3:
            pixelIndex = (pixelIndex - 304) % (304 * 240);
            break;
    }

    texture[pixelIndex] = *srcPixel;
}

extern s32 gLeoDDConnected;

void func_i4_TitleInit(void) {
    D_800CCFE8 = 3;
    D_i4_8011D638 = 1;
    gCourseIndex = 0;
    D_i4_8011D790 = 0;
    D_i4_8011D794 = 0;
    func_800794B0(5, 0, 0, 1);
    func_800794B0(10, 0, 0, 8);
    func_800794B0(15, 0, 0, 10);
    func_800794B0(17, 0, 0, 12);
    func_800794B0(19, 94, 200, 12);
    if (gLeoDDConnected) {
        func_800794B0(20, 0, 0, 12);
    }
}

extern s32 gControllersConnected;
extern s16 D_800CD044;

s32 func_i4_8011AE2C(void) {

    if (gControllersConnected == 0) {
        return gGameMode;
    }
    func_8007DABC(&gSharedController);
    Math_Rand1();
    if (gLeoDDConnected && (func_80079E88(20)->unk_1C != 0) && (func_80079E88(20)->unk_04 == 0)) {
        return gGameMode;
    }
    if (D_i4_8011D794 != 0) {
        return gGameMode;
    }

    if (D_i4_8011D790 < 0) {
        return gGameMode;
    }

    D_i4_8011D790++;
    if (D_i4_8011D790 < 0x50) {
        return gGameMode;
    }

    if ((D_800CD044 == 0) && (gInputButtonPressed & (BTN_A | BTN_START))) {
        func_800BA8D8(0x3E);
        func_8007E0CC();
        D_i4_8011D790 = -1;
        if (gLeoDDConnected && (func_80079E88(20)->unk_04 == 1)) {
            func_800BB370();
        }
        return GAMEMODE_FLX_MAIN_MENU;
    } else {
        return GAMEMODE_FLX_TITLE;
    }
}

Gfx* func_i4_8011AF84(Gfx* gfx) {

    gfx = func_80079BC8(gfx);

    if (D_i4_8011D794 != 0) {
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    }

    return gfx;
}

extern s8 D_800CD3C4;

void func_i4_8011B06C(unk_800E3A28* arg0) {
    arg0->unk_04 = D_800CD3C4;
    func_80077D50(sTitleBackgroundCompTexInfos[arg0->unk_04], 0);
    if (arg0->unk_04 == 0) {
        arg0->unk_0C = 8;
    }
}

void func_i4_8011B0C8(void) {
}

void func_i4_8011B0D0(unk_800E3A28* arg0) {
    arg0->unk_04 = D_800CD3C4;
    arg0->unk_0C = 0x55;

    switch (arg0->unk_04) {
        case 0:
        case 2:
            arg0->unk_10 = 0x15;
            break;
        case 1:
            arg0->unk_10 = 0x30;
            break;
    }

    func_80077D50(sTitleLogoCompTexInfo, 0);
}

void func_i4_8011B134(void) {
}

void func_i4_8011B13C(unk_800E3A28* arg0) {

    arg0->unk_04 = D_800CD3C4;
    func_80077D50(sTitleNoControllerCompTexInfo, 0);
    if (gControllersConnected != 0) {
        func_80077D50(sTitlePushStartCompTexInfo, 0);
        arg0->unk_0C = 120;
        switch (arg0->unk_04) {
            case 0:
                arg0->unk_10 = 0x96;
                return;
            case 1:
            case 2:
                arg0->unk_10 = 0xAB;
                break;
        }
    }
}

void func_i4_8011B1E4(void) {
}

void func_i4_8011B1EC(void) {
    func_80077D50(sCopyrightCompTexInfo, 0);
}

extern s32 gRamDDCompatible;

void func_i4_8011B214(unk_800E3A28* arg0) {
    s32 var_v0;

    arg0->unk_0C = 0x50;

    switch (D_800CD3C4) {
        case 0:
        case 2:
            arg0->unk_10 = 0x64;
            break;
        case 1:
            arg0->unk_10 = 0x78;
            break;
    }

    if (!gRamDDCompatible) {
        var_v0 = 1;
    } else {
        var_v0 = 2;
    }

    func_80077D50(sTitleWarningCompTexInfos[var_v0], 0);
    if (gRamDDCompatible && (func_800758F8() != 1)) {
        arg0->unk_1C++;
        D_i4_8011D794 = 1;
        func_800BB334();
    }
}

void (*sTitleBackgroundEffectFuncs[])(u16*) = {
    func_i4_8011A860, func_i4_8011A860, func_i4_8011A868, func_i4_8011A98C, func_i4_8011AAD8, func_i4_8011AC24,
};

void func_i4_8011B2E0(unk_800E3A28* arg0) {
    void (*backgroundEffect)(u16*);
    s32 i;
    u16* backgroundTexture;

    if (D_i4_8011D638 == 0) {
        arg0->unk_04++;
        if (arg0->unk_04 > 5) {
            arg0->unk_04 = 1;
        }
        backgroundEffect = sTitleBackgroundEffectFuncs[arg0->unk_04];
    } else {
        backgroundEffect = sTitleBackgroundEffectFuncs[D_i4_8011D638];
    }

    backgroundTexture = func_800783AC(aTitleBackgroundMainTex);

    for (i = 1999; i > 0; i--) {
        backgroundEffect(backgroundTexture);
    }
}

Gfx* func_i4_8011B380(Gfx* gfx, unk_800E3A28* arg1) {
    return func_80078EA0(gfx, sTitleBackgroundCompTexInfos[arg1->unk_04], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f,
                         1.0f);
}

Gfx* func_i4_8011B3DC(Gfx* gfx, unk_800E3A28* arg1) {
    return gfx;
}

Gfx* func_i4_8011B3E8(Gfx* gfx, unk_800E3A28* arg1) {
    return func_80078EA0(gfx, sTitleLogoCompTexInfo, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_8011B438(Gfx* gfx, unk_800E3A28* arg1) {
    return gfx;
}

Gfx* func_i4_8011B444(Gfx* gfx, unk_800E3A28* arg1) {
    s32 var_v1;

    if (gControllersConnected != 0) {
        if ((D_i4_8011D790 < 0x5F) && (D_i4_8011D790 >= 0)) {
            return gfx;
        }
        gfx = func_8007DB28(gfx, 0);
        gfx = func_80078EA0(gfx, sTitlePushStartCompTexInfo, arg1->unk_0C, arg1->unk_10, 1, 0, 0, 1.0f, 1.0f);
    } else {
        arg1->unk_0C = 0x50;

        switch (arg1->unk_04) {
            case 0:
            case 2:
                arg1->unk_10 = 0x96;
                break;
            case 1:
                arg1->unk_10 = 0xA2;
                break;
        }

        var_v1 = gGameFrameCount % 60U;
        if (var_v1 > 30) {
            var_v1 = 90 - var_v1;
        } else {
            var_v1 = 30 - var_v1;
        }

        gfx = func_8007A440(gfx, arg1->unk_0C, arg1->unk_10, arg1->unk_0C + 0xA0, arg1->unk_10 + 0x20,
                            (s32) (var_v1 * 0x28) / 60, 0, 0, 0xF0);
        var_v1 = gGameFrameCount % 60U;
        if (var_v1 > 30) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, ((0x28 - var_v1) * 255) / 40, 0, 0, 255);
        }

        gfx = func_80078EA0(gfx, sTitleNoControllerCompTexInfo, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

Gfx* func_i4_8011B668(Gfx* gfx, unk_800E3A28* arg1) {
    return gfx;
}

Gfx* func_i4_8011B674(Gfx* gfx, unk_800E3A28* arg1) {
    return func_80078EA0(gfx, sCopyrightCompTexInfo, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_8011B6C4(Gfx* gfx, unk_800E3A28* arg1) {
    s32 var_t0;
    s32 var_v1;

    var_t0 = 0;
    if (!gRamDDCompatible) {
        var_t0 = 1;
    } else if (arg1->unk_04 != 0) {
        var_t0 = 2;
    }

    if (var_t0 != 0) {
        var_v1 = gGameFrameCount % 60U;
        if (var_v1 > 30) {
            var_v1 = 90 - var_v1;
        } else {
            var_v1 = 30 - var_v1;
        }

        gfx = func_8007A440(gfx, arg1->unk_0C, arg1->unk_10, arg1->unk_0C + 0xA0, arg1->unk_10 + 0x20,
                            (s32) (var_v1 * 0x28) / 60, 0, 0, 0xF0);
        var_v1 = gGameFrameCount % 60U;
        if (var_v1 > 30) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, ((0x28 - var_v1) * 255) / 40, 0, 0, 255);
        }
        gfx = func_80078EA0(gfx, sTitleWarningCompTexInfos[var_t0], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

extern s8 D_800CD010;

void func_i4_8011B874(unk_800E3A28* arg0) {

    if (gRamDDCompatible && (D_i4_8011D790 != -1) && (D_800CD010 == 0)) {
        if (func_800758F8() == 1) {
            if (arg0->unk_1C != 0) {
                func_800BB370();
                func_800BAFA4(0xD);
            }
            arg0->unk_1C = 0;
            arg0->unk_04 = 0;
            D_i4_8011D794 = 0;
            return;
        }

        if (arg0->unk_1C < 30) {
            arg0->unk_1C++;
        }
        switch (arg0->unk_1C) {
            case 1:
                func_800BB334();
                break;
            case 30:
                if (func_800761D4() == 2) {
                    func_8007F9E0();
                    func_8007515C();
                } else {
                    arg0->unk_04 = 1;
                    D_i4_8011D794 = 0;
                }
                break;
        }
    }
}
