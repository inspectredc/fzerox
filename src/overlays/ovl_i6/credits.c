#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "src/overlays/ovl_i2/ovl_i2.h"
#include "ovl_i6.h"
#include "audio.h"
#include "assets/segment_2B9EA0.h"
#include "assets/segment_17B1E0.h"

s8 D_i6_8011FAF0[30];

s8 D_i6_8011DFA0 = 0;
UNUSED s32 D_i6_8011DFA4 = 64;
UNUSED s32 D_i6_8011DFA8 = 40;

s32 D_i6_8011DFAC = 60;
s32 D_i6_8011DFB0 = 30;
s32 D_i6_8011DFB4 = 50;

/*
    VEHICLE ARTWORK
 */

// BLUE FALCON
unk_80077D50 sCreditsBlueFalconCompTexInfo[] = { { 18, aCreditsBlueFalconTex, 128, 85, 0x2289 }, { 0 } };

// WILD GOOSE
unk_80077D50 sCreditsWildGooseCompTexInfo[] = { { 18, aCreditsWildGooseTex, 128, 94, 0x2905 }, { 0 } };

// FIRE STINGRAY
unk_80077D50 sCreditsFireStingrayCompTexInfo[] = { { 18, aCreditsFireStingrayTex, 128, 113, 0x2DBA }, { 0 } };

// GOLDEN FOX
unk_80077D50 sCreditsGoldenFoxCompTexInfo[] = { { 18, aCreditsGoldenFoxTex, 128, 91, 0x2A88 }, { 0 } };

// RED GAZELLE
unk_80077D50 sCreditsRedGazelleCompTexInfo[] = { { 18, aCreditsRedGazelleTex, 128, 94, 0x1DDB }, { 0 } };

// WHITE CAT
unk_80077D50 sCreditsWhiteFoxCompTexInfo[] = { { 18, aCreditsWhiteFoxTex, 128, 79, 0x24F5 }, { 0 } };

// IRON TIGER
unk_80077D50 sCreditsIronTigerCompTexInfo[] = { { 18, aCreditsIronTigerTex, 128, 92, 0x2C79 }, { 0 } };

// DEEP CLAW
unk_80077D50 sCreditsDeepClawCompTexInfo[] = { { 18, aCreditsDeepClawTex, 128, 87, 0x2A05 }, { 0 } };

// CRAZY BEAR
unk_80077D50 sCreditsCrazyBearCompTexInfo[] = { { 18, aCreditsCrazyBearTex, 128, 96, 0x3077 }, { 0 } };

// GREAT STAR
unk_80077D50 sCreditsGreatStarCompTexInfo[] = { { 18, aCreditsGreatStarTex, 128, 82, 0x272B }, { 0 } };

// BIG FANG
unk_80077D50 sCreditsBigFangCompTexInfo[] = { { 18, aCreditsBigFangTex, 128, 100, 0x2D0A }, { 0 } };

// MAD WOLF
unk_80077D50 sCreditsMadWolfCompTexInfo[] = { { 18, aCreditsMadWolfTex, 128, 97, 0x3694 }, { 0 } };

// NIGHT THUNDER
unk_80077D50 sCreditsNightThunderCompTexInfo[] = { { 18, aCreditsNightThunderTex, 128, 84, 0x2674 }, { 0 } };

// TWIN NORITTA
unk_80077D50 sCreditsTwinNorittaCompTexInfo[] = { { 18, aCreditsTwinNorittaTex, 128, 93, 0x25D7 }, { 0 } };

// WONDER WASP
unk_80077D50 sCreditsWonderWaspCompTexInfo[] = { { 18, aCreditsWonderWaspTex, 128, 85, 0x21A2 }, { 0 } };

// QUEEN METEOR
unk_80077D50 sCreditsQueenMeteorCompTexInfo[] = { { 18, aCreditsQueenMeteorTex, 128, 86, 0x226D }, { 0 } };

// BLOOD HAWK
unk_80077D50 sCreditsBloodHawkCompTexInfo[] = { { 18, aCreditsBloodHawkTex, 128, 96, 0x2E39 }, { 0 } };

// ASTRO ROBIN
unk_80077D50 sCreditsAstroRobinCompTexInfo[] = { { 18, aCreditsAstroRobinTex, 128, 101, 0x309E }, { 0 } };

// DEATH ANCHOR
unk_80077D50 sCreditsDeathAnchorCompTexInfo[] = { { 18, aCreditsDeathAnchorTex, 128, 118, 0x2B7C }, { 0 } };

// WILD BOAR
unk_80077D50 sCreditsWildBoarCompTexInfo[] = { { 18, aCreditsWildBoarTex, 128, 98, 0x2EF3 }, { 0 } };

// KING METEOR
unk_80077D50 sCreditsKingMeteorCompTexInfo[] = { { 18, aCreditsKingMeteorTex, 128, 103, 0x2D69 }, { 0 } };

// SUPER PIRANHA
unk_80077D50 sCreditsSuperPiranhaCompTexInfo[] = { { 18, aCreditsSuperPiranhaTex, 128, 94, 0x2E5F }, { 0 } };

// MIGHTY HURRICANE
unk_80077D50 sCreditsMightyHurricaneCompTexInfo[] = { { 18, aCreditsMightyHurricaneTex, 128, 83, 0x2432 }, { 0 } };

// SPACE ANGLER
unk_80077D50 sCreditsSpaceAnglerCompTexInfo[] = { { 18, aCreditsSpaceAnglerTex, 128, 92, 0x2CB2 }, { 0 } };

// MIGHTY TYPHOON
unk_80077D50 sCreditsMightyTyphoonCompTexInfo[] = { { 18, aCreditsMightyTyphoonTex, 128, 82, 0x22C9 }, { 0 } };

// HYPER SPEEDER
unk_80077D50 sCreditsHyperSpeederCompTexInfo[] = { { 18, aCreditsHyperSpeederTex, 128, 101, 0x2B2E }, { 0 } };

// GREEN PANTHER
unk_80077D50 sCreditsGreenPantherCompTexInfo[] = { { 18, aCreditsGreenPantherTex, 128, 88, 0x287D }, { 0 } };

// BLACK BULL
unk_80077D50 sCreditsBlackBullCompTexInfo[] = { { 18, aCreditsBlackBullTex, 128, 93, 0x2488 }, { 0 } };

// LITTLE WYVERN
unk_80077D50 sCreditsLittleWyvernCompTexInfo[] = { { 18, aCreditsLittleWyvernTex, 128, 82, 0x22DA }, { 0 } };

// SONIC PHANTOM
unk_80077D50 sCreditsSonicPhantomCompTexInfo[] = { { 18, aCreditsSonicPhantomTex, 128, 92, 0x276B }, { 0 } };

unk_800792D8 D_i6_8011E378[] = { { sCreditsBlueFalconCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E388[] = { { sCreditsWildGooseCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E398[] = { { sCreditsFireStingrayCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3A8[] = { { sCreditsGoldenFoxCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3B8[] = { { sCreditsRedGazelleCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3C8[] = { { sCreditsWhiteFoxCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3D8[] = { { sCreditsIronTigerCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3E8[] = { { sCreditsDeepClawCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3F8[] = { { sCreditsCrazyBearCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E408[] = { { sCreditsGreatStarCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E418[] = { { sCreditsBigFangCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E428[] = { { sCreditsMadWolfCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E438[] = { { sCreditsNightThunderCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E448[] = { { sCreditsTwinNorittaCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E458[] = { { sCreditsWonderWaspCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E468[] = { { sCreditsQueenMeteorCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E478[] = { { sCreditsBloodHawkCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E488[] = { { sCreditsAstroRobinCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E498[] = { { sCreditsDeathAnchorCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4A8[] = { { sCreditsWildBoarCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4B8[] = { { sCreditsKingMeteorCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4C8[] = { { sCreditsSuperPiranhaCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4D8[] = { { sCreditsMightyHurricaneCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4E8[] = { { sCreditsSpaceAnglerCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4F8[] = { { sCreditsMightyTyphoonCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E508[] = { { sCreditsHyperSpeederCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E518[] = { { sCreditsGreenPantherCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E528[] = { { sCreditsBlackBullCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E538[] = { { sCreditsLittleWyvernCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011E548[] = { { sCreditsSonicPhantomCompTexInfo, 60 }, { 0 } };

unk_800792D8* D_i6_8011E558[] = {
    D_i6_8011E498,
    D_i6_8011E498,
};

unk_800792D8* D_i6_8011E560[] = {
    D_i6_8011E378, // CAPTAIN_FALCON
    D_i6_8011E388, // DR_STEWART
    D_i6_8011E398, // PICO
    D_i6_8011E3A8, // SAMURAI_GOROH
    D_i6_8011E3B8, // JODY_SUMMER
    D_i6_8011E3C8, // MIGHTY_GAZELLE
    D_i6_8011E3D8, // MR_EAD
    D_i6_8011E3E8, // BABA
    D_i6_8011E3F8, // OCTOMAN
    D_i6_8011E408, // GOMAR_AND_SHIOH
    D_i6_8011E418, // KATE_ALEN
    D_i6_8011E428, // ROGER_BUSTER
    D_i6_8011E438, // JAMES_MCCLOUD
    D_i6_8011E448, // LEON
    D_i6_8011E458, // ANTONIO_GUSTER
    D_i6_8011E468, // BLACK_SHADOW
    D_i6_8011E478, // MICHAEL_CHAIN
    D_i6_8011E488, // JACK_LEVIN
    D_i6_8011E498, // SUPER_ARROW
    D_i6_8011E4A8, // MRS_ARROW
    D_i6_8011E4B8, // JOHN_TANAKA
    D_i6_8011E4C8, // BEASTMAN
    D_i6_8011E4D8, // ZODA
    D_i6_8011E4E8, // DR_CLASH
    D_i6_8011E4F8, // SILVER_NEELSEN
    D_i6_8011E508, // BIO_REX
    D_i6_8011E518, // DRAQ
    D_i6_8011E528, // BILLY
    D_i6_8011E538, // THE_SKULL
    D_i6_8011E548, // BLOOD_FALCON
};

/*
    CREDITS / ENDING IMAGES + CHARACTER PORTRAITS
 */

// ENDING SCREEN GIRL
unk_80077D50 sCreditsMenuLadyCompTexInfo[] = { { 17, aCreditsMenuLadyTex, 80, 182, 0x25D1 }, { 0 } };

// 'SEE YOU AGAIN!!'
unk_80077D50 sCreditsSeeYouAgainCompTexInfo[] = { { 17, aCreditsSeeYouAgainTex, 64, 64, 0x95A }, { 0 } };

// MR ZERO
unk_80077D50 sCreditsMrZeroCompTexInfo[] = { { 17, aCreditsMrZeroTex, 80, 72, 0x1662 }, { 0 } };

// COPYRIGHT LOGO (1998)
//! @bug This has the incorrect compressed size (leftover from version difference?)
unk_80077D50 sCreditsCopyrightCompTexInfo[] = { { 17, aCopyrightTex, 128, 14, 0x439 }, { 0 } };

// DR STEWART
unk_80077D50 sCreditsPortraitDrStewartCompTexInfo[] = { { 17, aFullPortraitDrStewartTex, 180, 245, 0x4AF4 }, { 0 } };

// CAPTAIN FALCON
unk_80077D50 sCreditsPortraitCaptainFalconCompTexInfo[] = { { 17, aFullPortraitCaptainFalconTex, 180, 245, 0x6604 },
                                                            { 0 } };

// JODY SUMMER
unk_80077D50 sCreditsPortraitJodySummerCompTexInfo[] = { { 17, aFullPortraitJodySummerTex, 180, 245, 0x5573 }, { 0 } };

// SAMURAI GOROH
unk_80077D50 sCreditsPortraitSamuraiGorohCompTexInfo[] = { { 17, aFullPortraitSamuraiGorohTex, 180, 245, 0x76B4 },
                                                           { 0 } };

// MIGHTY GAZELLE
unk_80077D50 sCreditsPortraitMightyGazelleCompTexInfo[] = { { 17, aFullPortraitMightyGazelleTex, 180, 245, 0x67F2 },
                                                            { 0 } };

// PICO
unk_80077D50 sCreditsPortraitPicoCompTexInfo[] = { { 17, aFullPortraitPicoTex, 180, 245, 0x63BB }, { 0 } };

// BABA
unk_80077D50 sCreditsPortraitBabaCompTexInfo[] = { { 17, aFullPortraitBabaTex, 180, 245, 0x5EE9 }, { 0 } };

// MR EAD
unk_80077D50 sCreditsPortraitMrEadCompTexInfo[] = { { 17, aFullPortraitMrEadTex, 180, 245, 0x7184 }, { 0 } };

// OCTOMAN
unk_80077D50 sCreditsPortraitOctomanCompTexInfo[] = { { 17, aFullPortraitOctomanTex, 180, 245, 0x5666 }, { 0 } };

// THE SKULL
unk_80077D50 sCreditsPortraitTheSkullCompTexInfo[] = { { 17, aFullPortraitTheSkullTex, 180, 245, 0x5A49 }, { 0 } };

// BEASTMAN
unk_80077D50 sCreditsPortraitBeastmanCompTexInfo[] = { { 17, aFullPortraitBeastmanTex, 180, 245, 0x55C1 }, { 0 } };

// ANTONIO GUSTER
unk_80077D50 sCreditsPortraitAntonioGusterCompTexInfo[] = { { 17, aFullPortraitAntonioGusterTex, 180, 245, 0x594F },
                                                            { 0 } };

// DRAQ
unk_80077D50 sCreditsPortraitDraqCompTexInfo[] = { { 17, aFullPortraitDraqTex, 180, 245, 0x7A7A }, { 0 } };

// ROGER BUSTER
unk_80077D50 sCreditsPortraitRogerBusterCompTexInfo[] = { { 17, aFullPortraitRogerBusterTex, 180, 245, 0x6444 },
                                                          { 0 } };

// SILVER NEEISEN
unk_80077D50 sCreditsPortraitSilverNeelsenCompTexInfo[] = { { 17, aFullPortraitSilverNeelsenTex, 180, 245, 0x623A },
                                                            { 0 } };

// SUPER ARROW
unk_80077D50 sCreditsPortraitSuperArrowCompTexInfo[] = { { 17, aFullPortraitSuperArrowTex, 180, 245, 0x6F78 }, { 0 } };

// MRS ARROW
unk_80077D50 sCreditsPortraitMrsArrowCompTexInfo[] = { { 17, aFullPortraitMrsArrowTex, 180, 245, 0x5C56 }, { 0 } };

// ZODA
unk_80077D50 sCreditsPortraitZodaCompTexInfo[] = { { 17, aFullPortraitZodaTex, 180, 245, 0x59E6 }, { 0 } };

// JOHN TANAKA
unk_80077D50 sCreditsPortraitJohnTanakaCompTexInfo[] = { { 17, aFullPortraitJohnTanakaTex, 180, 245, 0x5B58 }, { 0 } };

// BIO REX
unk_80077D50 sCreditsPortraitBioRexCompTexInfo[] = { { 17, aFullPortraitBioRexTex, 180, 245, 0x6B2D }, { 0 } };

// KATE ALEN
unk_80077D50 sCreditsPortraitKateAlenCompTexInfo[] = { { 17, aFullPortraitKateAlenTex, 180, 245, 0x4E48 }, { 0 } };

// GOMAR & SHIOH
unk_80077D50 sCreditsPortraitGomarAndShiohCompTexInfo[] = { { 17, aFullPortraitGomarAndShiohTex, 180, 245, 0x6D92 },
                                                            { 0 } };

// MICHAEL CHAIN
unk_80077D50 sCreditsPortraitMichaelChainCompTexInfo[] = { { 17, aFullPortraitMichaelChainTex, 180, 245, 0x5AB3 },
                                                           { 0 } };

// BILLY
unk_80077D50 sCreditsPortraitBillyCompTexInfo[] = { { 17, aFullPortraitBillyTex, 180, 245, 0x5E3B }, { 0 } };

// DR CLASH
unk_80077D50 sCreditsPortraitDrClashCompTexInfo[] = { { 17, aFullPortraitDrClashTex, 180, 245, 0x6EAC }, { 0 } };

// JACK LEVIN
unk_80077D50 sCreditsPortraitJackLevinCompTexInfo[] = { { 17, aFullPortraitJackLevinTex, 180, 245, 0x4D32 }, { 0 } };

// BLOOD FALCON
unk_80077D50 sCreditsPortraitBloodFalconCompTexInfo[] = { { 17, aFullPortraitBloodFalconTex, 180, 245, 0x603A },
                                                          { 0 } };

// LEON
unk_80077D50 sCreditsPortraitLeonCompTexInfo[] = { { 17, aFullPortraitLeonTex, 180, 245, 0x60B6 }, { 0 } };

// JAMES MCCLOUD
unk_80077D50 sCreditsPortraitJamesMcCloudCompTexInfo[] = { { 17, aFullPortraitJamesMcCloudTex, 180, 245, 0x5534 },
                                                           { 0 } };

// BLACK SHADOW
unk_80077D50 sCreditsPortraitBlackShadowCompTexInfo[] = { { 17, aFullPortraitBlackShadowTex, 180, 245, 0x5DA7 },
                                                          { 0 } };

unk_800792D8 D_i6_8011EA18[] = { { sCreditsPortraitDrStewartCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA28[] = { { sCreditsPortraitCaptainFalconCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA38[] = { { sCreditsPortraitJodySummerCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA48[] = { { sCreditsPortraitSamuraiGorohCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA58[] = { { sCreditsPortraitMightyGazelleCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA68[] = { { sCreditsPortraitPicoCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA78[] = { { sCreditsPortraitBabaCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA88[] = { { sCreditsPortraitMrEadCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA98[] = { { sCreditsPortraitOctomanCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAA8[] = { { sCreditsPortraitTheSkullCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAB8[] = { { sCreditsPortraitBeastmanCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAC8[] = { { sCreditsPortraitAntonioGusterCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAD8[] = { { sCreditsPortraitDraqCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAE8[] = { { sCreditsPortraitRogerBusterCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAF8[] = { { sCreditsPortraitSilverNeelsenCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB08[] = { { sCreditsPortraitSuperArrowCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB18[] = { { sCreditsPortraitMrsArrowCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB28[] = { { sCreditsPortraitZodaCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB38[] = { { sCreditsPortraitJohnTanakaCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB48[] = { { sCreditsPortraitBioRexCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB58[] = { { sCreditsPortraitKateAlenCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB68[] = { { sCreditsPortraitGomarAndShiohCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB78[] = { { sCreditsPortraitMichaelChainCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB88[] = { { sCreditsPortraitBillyCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB98[] = { { sCreditsPortraitDrClashCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EBA8[] = { { sCreditsPortraitJackLevinCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EBB8[] = { { sCreditsPortraitBloodFalconCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EBC8[] = { { sCreditsPortraitLeonCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EBD8[] = { { sCreditsPortraitJamesMcCloudCompTexInfo, 60 }, { 0 } };

unk_800792D8 D_i6_8011EBE8[] = { { sCreditsPortraitBlackShadowCompTexInfo, 60 }, { 0 } };

unk_800792D8* D_i6_8011EBF8[] = {
    D_i6_8011EA28, // CAPTAIN_FALCON
    D_i6_8011EA68, // DR_STEWART
    D_i6_8011EA48, // PICO
    D_i6_8011EA18, // SAMURAI_GOROH
    D_i6_8011EA58, // JODY_SUMMER
    D_i6_8011EA38, // MIGHTY_GAZELLE
    D_i6_8011EA78, // MR_EAD
    D_i6_8011EA98, // BABA
    D_i6_8011EB98, // OCTOMAN
    D_i6_8011EA88, // GOMAR_AND_SHIOH
    D_i6_8011EB48, // KATE_ALEN
    D_i6_8011EB88, // ROGER_BUSTER
    D_i6_8011EAF8, // JAMES_MCCLOUD
    D_i6_8011EB68, // LEON
    D_i6_8011EB38, // ANTONIO_GUSTER
    D_i6_8011EB18, // BLACK_SHADOW
    D_i6_8011EBB8, // MICHAEL_CHAIN
    D_i6_8011EBA8, // JACK_LEVIN
    D_i6_8011EB28, // SUPER_ARROW
    D_i6_8011EB78, // MRS_ARROW
    D_i6_8011EB08, // JOHN_TANAKA
    D_i6_8011EB58, // BEASTMAN
    D_i6_8011EAE8, // ZODA
    D_i6_8011EBC8, // DR_CLASH
    D_i6_8011EAD8, // SILVER_NEELSEN
    D_i6_8011EAB8, // BIO_REX
    D_i6_8011EAC8, // DRAQ
    D_i6_8011EBE8, // BILLY
    D_i6_8011EBD8, // THE_SKULL
    D_i6_8011EAA8, // BLOOD_FALCON
};

const char* gCreditsAttributions[] = {
    "director",          "assistant director", "chief programmer",    "programmer",          "programmer",
    "programmer",        "dd programmer",      "dd programmer",       "sound composer",      "sound composer",
    "sound effects",     "chief designer",     "graphic designer",    "machine modeler",     "course design",
    "course design",     "course design",      "course design",       "sequence support",    "graphic support",
    "technical support", "technical support",  "progress management", "progress management", "special thanks to",
    "special thanks to", "special thanks to",  "special thanks to",   "special thanks to",   "executive producer",
    "producer",
};

const char* gCreditsNames[] = {
    "tadashi sugiyama",  "yasuyuki oyagi",     "keizo ohta",       "tsutomu kaneshige", "masahiro kawano",
    "daisuke tsujimura", "hiroki sotoike",     "shiro mouri",      "taro bando",        "hajime wakai",
    "taro bando",        "takaya imamura",     "katsuhiko kanno",  "tadashi sugiyama",  "tadashi sugiyama",
    "takaya imamura",    "yasuyuki oyagi",     "keizo ohta",       "hideki konno",      "masanao arimoto",
    "hironobu kakui",    "shin hasegawa",      "kimiyoshi fukui",  "keizo kato",        "yasuhiro sakai",
    "atsushi tejima",    "masanori sato",      "takayuki hashida", "super mario club",  "hiroshi yamauchi",
    "shigeru miyamoto",  "yoshitaka yasumoto", "naruhisa kawano",  "sou kimura",        "kayomi mcdonald",
    "jim wornell",
};

const s16 kStartRolesInitialPositions[] = { 50, 240, 280, -20, 280, 240, 50, -20 };

const s16 kStartNamesInitialPositions[] = { 50, 100, 280, 180, 280, 100, 50, 180 };

const s16 D_i6_8011F4DC[] = { 150, 210, 50, 35, 50, 210, 150, 35 };

const s16 kCreditsObjectScrollScript[] = {
    OBJECT_CREDITS_ROLE_18,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_18,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_ROLE_19,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_19,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_ROLE_20,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_20,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_21,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_ROLE_22,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_22,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_23,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_ROLE_24,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_24,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_25,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_32,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_26,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_27,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_31,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_33,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_34,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_35,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_28,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_ROLE_29,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_29,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_ROLE_30,
    OBJECT_FREE,
    OBJECT_FREE,
    OBJECT_CREDITS_NAME_30,
    -1,
};

extern Object gObjects[32];
extern unk_800E3F28 D_800E3F28[];

void Credits_OldCarsInit(Object* oldCarsObj) {

    oldCarsObj->unk_18 = func_800792D8(D_i6_8011E558[0]);

    oldCarsObj->unk_04 = 0;

    //! @bug the case where func_800792D8 returns -1 is unhandled
    D_800E3F28[oldCarsObj->unk_18].unk_04 = -1;
}

void Credits_CarsInit(Object* carsObj) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_i6_8011FAF0); i++) {
        D_i6_8011FAF0[i] = 0;
    }
    carsObj->unk_18 = func_800792D8(D_i6_8011E558[0]);

    //! @bug the case where func_800792D8 returns -1 is unhandled
    D_800E3F28[carsObj->unk_18].unk_04 = -1;
}

void Credits_MenuLadyInit(Object* menuLadyObj) {
    func_80077D50(sCreditsMenuLadyCompTexInfo, 0);
    menuLadyObj->unk_1C = 0xB6;
}

void Credits_SeeYouAgainInit(void) {
    func_80077D50(sCreditsSeeYouAgainCompTexInfo, 0);
}

void Credits_IntroInit(Object* introObj) {
    func_80077D50(sCreditsMrZeroCompTexInfo, 0);
    introObj->unk_1C = 0x100;
    introObj->unk_18 = 0;
}

void Credits_CopyrightInit(void) {
    func_80077D50(sCreditsCopyrightCompTexInfo, 0);
}

void Credits_PortraitsInit(Object* portraitsObj) {

    portraitsObj->unk_18 = func_800792D8(D_i6_8011EBF8[0]);

    D_800E3F28[portraitsObj->unk_18].unk_04 = -1;
}

Gfx* Credits_FadeInNameByLetter(Gfx* gfx, Object* startNameObj, bool* wordFadeInProgress, bool isRightJustified) {
    s32 letterPosOffset;
    s32 i;
    s32 left;
    s32 letterCount;
    s32 top;
    s32 letterCompletion;
    s32 pad[4]; // possibly part of buffer
    signed char letterStr[2];
    s8* name;

    name = gCreditsNames[startNameObj->cmdId - OBJECT_CREDITS_NAME_0];

    if (isRightJustified) {
        i = Font_GetStringWidth(name, FONT_SET_1, 0);
    } else {
        i = 0;
    }

    left = startNameObj->left - i;
    top = startNameObj->top;

    letterCount = startNameObj->unk_1C / 5;
    if (letterCount >= 23) {
        letterCount = 23;
    }
    *wordFadeInProgress = false;

    for (i = 0; i < letterCount + 1; i++) {

        letterStr[0] = *name++;
        if (letterStr[0] == '\0') {
            break;
        }

        letterStr[1] = '\0';
        letterCompletion = startNameObj->unk_1C - (i * 5);
        if (letterCompletion >= 5) {
            letterCompletion = 5;
        } else {
            *wordFadeInProgress = true;
        }
        if (letterCompletion < 0) {
            break;
        }

        letterPosOffset = 5 - letterCompletion;
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, (letterCompletion * 255) / 5);
        gfx =
            Font_DrawString(gfx, left + (letterPosOffset * 2), top - SQ(letterPosOffset), letterStr, 0, FONT_SET_1, 1);

        left += Font_GetCharacterWidth(letterStr, FONT_SET_1);
    }

    return gfx;
}

Gfx* Credits_OldCarsDraw(Gfx* gfx, Object* oldCarsObj) {

    if (!D_i6_8011DFA0) {
        return gfx;
    }

    return func_80078F80(gfx, &D_800E3F28[oldCarsObj->unk_18], oldCarsObj->left, oldCarsObj->top, 0, 0, 0, 1.0f, 1.0f);
}

#define UNK_RAND_MACRO(var, x, y) (((Math_Rand1() >> (var % 4)) % x) - y)

Gfx* Credits_CarsDraw(Gfx* gfx, Object* carsObj) {
    s32 sp154;
    s32 row;
    s32 var_t5;
    f32 var_fv1;
    s32 left;
    unk_800E3F28* temp_s1;
    s32 height;
    s32 width;
    s32 var_a0;
    s32 pad;
    s32 additionalWidth;
    s32 additionalHeight;
    f32 var_ft4;
    TexturePtr texture;
    s32 top;

    temp_s1 = &D_800E3F28[carsObj->unk_18];

    left = carsObj->left;
    top = carsObj->top;

    if (carsObj->top > 120) {
        top = carsObj->top - temp_s1->unk_00->unk_00->height;
    }

    sp154 = carsObj->unk_1C;
    if (sp154 > 64) {
        sp154 = 64;
    }

    width = temp_s1->unk_00->unk_00->width;
    height = temp_s1->unk_00->unk_00->height;

    switch (carsObj->unk_08) {
        case 0:

            if (temp_s1->unk_0A == 0) {
                texture = temp_s1->unk_0C;
            } else {
                texture = temp_s1->unk_10;
            }

            gSPDisplayList(gfx++, D_3000088);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, (sp154 * 255) / 64);

            var_a0 = UNK_RAND_MACRO(row, 13, 6);
            left += var_a0 * (64 - sp154) / 64;

            for (row = 0; row < height; row++) {
                var_a0 = UNK_RAND_MACRO(row, 15, 7);
                if ((var_a0 < 4) && (var_a0 > -4)) {
                    var_a0 = 0;
                } else {
                    if (var_a0 > 0) {
                        var_a0 -= (sp154 * 4) / 64;
                        var_a0 = var_a0 * var_a0;
                    } else {
                        var_a0 += (sp154 * 4) / 64;
                        var_a0 = -var_a0 * var_a0;
                    }
                    var_a0 = ((64 - sp154) * var_a0) / 64;
                }

                var_t5 = (UNK_RAND_MACRO(row, 7, 3) * (64 - sp154)) / 64;

                if (((row + var_t5) < 0) || ((row + var_t5) >= height)) {
                    var_t5 = 0;
                }

                gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, 1 /* unused by macro */, 0,
                                   (row + var_t5), width, (row + var_t5) + 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPScisTextureRectangle(gfx++, (left + var_a0) << 2, (top + row) << 2, ((left + var_a0) + width) << 2,
                                        (top + row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            }
            break;
        case 1:
            gfx = func_80078F80(gfx, temp_s1, carsObj->left, top, 0, 0, 0, 1.0f, 1.0f);
            break;
        case 2:
            if (sp154 < 5) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, ((64 - sp154) * 255) / 64);

                var_fv1 = (64 - (sp154 * 2)) / 64.0f;
                additionalWidth = (width * (1.0f - var_fv1)) / 2;
                additionalHeight = (height * (1.0f - var_fv1)) / 2;

                gfx = func_80078F80(gfx, temp_s1, carsObj->left + additionalWidth, top + additionalHeight, 4, 0, 0,
                                    var_fv1, var_fv1);
            } else {
                if (temp_s1->unk_0A == 0) {
                    texture = temp_s1->unk_0C;
                } else {
                    texture = temp_s1->unk_10;
                }
                gSPDisplayList(gfx++, D_3000088);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, ((64 - sp154) * 255) / 64);

                var_fv1 = (64 - (sp154 * 2)) / 64.0f;
                var_ft4 = (84 - (sp154 * 6)) / 64.0f;

                if (var_fv1 < 0.0f) {
                    var_fv1 = 0;
                }
                if (var_ft4 < 0.0f) {
                    var_ft4 = 0;
                }

                if (var_fv1 != 0.0f) {
                    var_t5 = 1024.0f / var_fv1;
                } else {
                    var_t5 = 0;
                }

                additionalWidth = (width * (1.0f - var_fv1)) / 2;
                additionalHeight = (height * (1.0f - var_ft4)) / 2;

                for (row = 0; row < height; row++) {
                    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, ((64 - sp154) * 255) / 64);
                    gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

                    gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, 1 /* unused by macro */, 0,
                                       row, width, row + 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                       G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    gSPScisTextureRectangle(
                        gfx++, (left + additionalWidth) << 2, (s32) ((top + additionalHeight) + (row * var_ft4)) << 2,
                        ((left + additionalWidth) + width) << 2,
                        (s32) (((top + additionalHeight) + (row * var_ft4)) + 1.0f) << 2, 0, 0, 0, var_t5, 1 << 10);
                    gDPPipeSync(gfx++);
                    gfx = func_8007A440(gfx, (left + additionalWidth), ((top + additionalHeight) + (row * var_ft4)),
                                        ((left + additionalWidth) + (width * var_fv1)),
                                        ((top + additionalHeight) + (row * var_ft4)) + 1.0f, 0x80, 0x80, 0x80, 0x10);
                }
            }
            break;
    }

    return gfx;
}

Gfx* Credits_MenuLadyDraw(Gfx* gfx, Object* menuLadyObj) {
    s32 row;
    s32 var_a0;
    s32 var_a1;
    s32 spB0;
    s32 var_s1;
    s32 alpha;
    s32 var_t5;
    TexturePtr texture;

    texture = func_800783AC(aCreditsMenuLadyTex);
    spB0 = menuLadyObj->left;
    var_s1 = menuLadyObj->top;

    gSPDisplayList(gfx++, D_3000088);

    for (row = 0; row < 182; row++) {
        var_t5 = 0;

        switch (menuLadyObj->unk_04) {
            case 0:
                alpha = row - menuLadyObj->unk_1C;
                if (alpha < 0) {
                    alpha = -alpha;
                }

                if (alpha < 8) {
                    alpha = 255 - (alpha * 32);
                } else {
                    alpha = 0;
                }
                break;
            case 1:
                alpha = row - 0x17;
                if (alpha < 0) {
                    alpha = -alpha;
                }
                if (alpha < 8) {
                    alpha = 255 - (alpha * 32);
                } else {
                    alpha = 0;
                }
                break;
            case 2:
                var_a1 = row - 0x17;
                var_a0 = menuLadyObj->unk_1C - 0x17;
                if (var_a0 < 0) {
                    var_a0 = -var_a0;
                }
                if (var_a1 < 0) {
                    var_a1 = -var_a1;
                }
                alpha = (var_a0 - var_a1);
                if (var_a1 < var_a0) {
                    alpha = 255;
                } else if ((var_a1 - var_a0) < 8) {
                    alpha = (alpha * 32) + 255;
                } else {
                    alpha = 0;
                }
                break;
            case 3:
                alpha = 255;
                break;
            case 4:
                alpha = 255;
                if (menuLadyObj->unk_08 != 0) {
                    var_a0 = UNK_RAND_MACRO(row, 7, 3);
                    var_t5 = (s32) ((0x20 - menuLadyObj->unk_08) * var_a0) / 32;
                }
                break;
            default:
                alpha = 255;
                break;
        }

        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
        gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 1 /* unused by macro */, 0, row, 80,
                           row + 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, (spB0 + var_t5) << 2, (var_s1 + row) << 2, (spB0 + var_t5 + 80) << 2,
                                (var_s1 + row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gSPScisTextureRectangle(gfx++, ((SCREEN_WIDTH - 80 - spB0) + var_t5) << 2, (var_s1 + row) << 2,
                                ((SCREEN_WIDTH - spB0) + var_t5) << 2, (var_s1 + row + 1) << 2, 0, 0x9E0, 0, 0xFC00,
                                1 << 10);
    }

    menuLadyObj->unk_08 = 0;

    return gfx;
}

Gfx* Credits_SeeYouAgainDraw(Gfx* gfx, Object* seeYouAgainObj) {
    s32 row;
    s32 sp50;
    s32 alpha;
    s32 var_s2;
    s32 var_s5;
    TexturePtr texture;

    seeYouAgainObj->unk_1C++;
    texture = func_800783AC(aCreditsSeeYouAgainTex);
    sp50 = seeYouAgainObj->left;
    var_s5 = seeYouAgainObj->top;

    gSPDisplayList(gfx++, D_3000088);

    if (seeYouAgainObj->unk_04 == 1) {
        gDPSetAlphaCompare(gfx++, G_AC_DITHER);
    }

    for (row = 0; row < 64; row++) {
        switch (seeYouAgainObj->unk_04) {
            case 0:
                var_s2 = UNK_RAND_MACRO(row, 11, 5);
                if (seeYouAgainObj->unk_1C < 64) {
                    var_s2 = (s32) ((64 - seeYouAgainObj->unk_1C) * var_s2) / 64;
                } else {
                    var_s2 = 0;
                }
                if (seeYouAgainObj->unk_1C < 6) {
                    alpha = seeYouAgainObj->unk_1C * 50;
                } else {
                    alpha = 255;
                }
                break;
            case 1:

                var_s2 = UNK_RAND_MACRO(row, 7, 3);

                if (seeYouAgainObj->unk_1C < 32) {
                    var_s2 = ((32 - seeYouAgainObj->unk_1C) * var_s2) / 32;
                    Object_Get(OBJECT_CREDITS_MENU_LADY)->unk_08 = seeYouAgainObj->unk_1C;
                } else {
                    var_s2 = 0;
                }
                if (seeYouAgainObj->unk_1C < 20) {
                    if (seeYouAgainObj->unk_1C < 10) {
                        alpha = 255 - (seeYouAgainObj->unk_1C * 10);
                    } else {
                        alpha = (seeYouAgainObj->unk_1C * 10) + 55;
                    }
                } else {
                    alpha = 255;
                }
                break;
            default:
                var_s2 = 0;
                alpha = 255;
                break;
        }

        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
        gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 1 /* unused by macro */, 0, row, 64,
                           row + 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, (sp50 + var_s2) << 2, (var_s5 + row) << 2, (sp50 + var_s2 + 64) << 2,
                                (var_s5 + row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    return gfx;
}

#ifdef NON_MATCHING
Gfx* Credits_IntroDraw(Gfx* gfx, Object* introObj) {
    s32 temp_a0;
    s32 temp_t1;
    s32 var_t2;
    s32 row;
    s32 temp;
    s32 var;
    f32 scale;
    TexturePtr texture;

    texture = func_800783AC(aCreditsMrZeroTex);
    gSPDisplayList(gfx++, D_3000088);

    var = 60;

    for (row = 0; row < 72; row++) {
        gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 1 /* unused by macro */, 0, row, 80,
                           row + 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);

        if (introObj->unk_08 != 0) {
            temp_a0 = introObj->unk_20;
            var_t2 = 255 - temp_a0;
            temp = ((((row * 0x1000) * (temp_a0 + 64)) / 64) / 72);
            temp_t1 = ((SIN(temp) * (temp_a0 + 4)) / 4);
            temp = (200 - temp_t1);

            gDPSetPrimColor(gfx++, 0, 0, var_t2, var_t2, var_t2, var_t2);
            gSPScisTextureRectangle(gfx++, temp << 2, (row + var) << 2, (temp + 80) << 2, (row + var + 1) << 2, 0, 0, 0,
                                    1 << 10, 1 << 10);
        }
        if (introObj->unk_04 != 0) {
            temp_a0 = introObj->unk_1C;
            var_t2 = 255 - temp_a0;
            temp = ((((row * 0x1000) * (temp_a0 + 64)) / 64) / 72);
            temp_t1 = ((SIN(temp) * (temp_a0 + 4)) / 4);
            gDPSetPrimColor(gfx++, 0, 0, var_t2, var_t2, var_t2, var_t2);
            gSPScisTextureRectangle(gfx++, (temp_t1 + 40) << 2, (row + var) << 2, ((temp_t1 + 40) + 80) << 2,
                                    (row + var + 1) << 2, 0, (80 - 1) * (1 << 5), 0, (64 - 1) * (1 << 10), 1 << 10);
        }
    }

    if (introObj->unk_18 > 290) {
        var_t2 = 0xA10 - (introObj->unk_18 * 8);
        if (var_t2 > 255) {
            var_t2 = 255;
        }
        if (var_t2 < 0) {
            var_t2 = 0;
        }

        scale = (511 - var_t2) / 256.0f;

        gDPSetPrimColor(gfx++, 0, 0, var_t2, var_t2, var_t2, var_t2);

        gfx = Font_DrawScaledString(
            gfx, (s32) (160.0f - (((f32) Font_GetStringWidth("f-zero x", FONT_SET_1, 0) * scale) / 2)),
            D_i6_8011DFAC + D_i6_8011DFB0, "f-zero x", 0, FONT_SET_1, 1, scale, scale);
        gfx = Font_DrawScaledString(gfx,
                                    (s32) (160.0f - (((f32) Font_GetStringWidth("staff", FONT_SET_1, 0) * scale) / 2)),
                                    D_i6_8011DFAC + D_i6_8011DFB4, "staff", 0, FONT_SET_1, 1, scale, scale);
    } else if (introObj->unk_18 > 120) {
        var_t2 = (introObj->unk_18 * 3) - 0x168;
        if (var_t2 > 255) {
            var_t2 = 255;
        }

        scale = (f32) (628 - (introObj->unk_18 * 2)) / 192.0f;

        if (scale < 1.0) {
            scale = 1.0f;
        }
        gDPSetPrimColor(gfx++, 0, 0, var_t2, var_t2, var_t2, var_t2);

        gfx = Font_DrawScaledString(
            gfx, (s32) (160.0f - (((f32) Font_GetStringWidth("f-zero x", FONT_SET_1, 0) * scale) / 2)),
            (D_i6_8011DFAC + D_i6_8011DFB0) - (scale - 1.0) * 20.0, "f-zero x", 0, FONT_SET_1, 1, scale, scale);
        gfx = Font_DrawScaledString(
            gfx, (s32) (160.0f - (((f32) Font_GetStringWidth("staff", FONT_SET_1, 0) * scale) / 2)),
            (D_i6_8011DFAC + D_i6_8011DFB4) + (scale - 1.0) * 20.0, "staff", 0, FONT_SET_1, 1, scale, scale);
    }
    return gfx;
}
#else
Gfx* Credits_IntroDraw(Gfx* gfx, Object* introObj);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i6/credits/Credits_IntroDraw.s")
#endif

Gfx* Credits_CopyrightDraw(Gfx* gfx, Object* copyRightObj) {
    s32 var_s2;
    s32 temp_s7;
    s32 var_a2;
    s32 row;
    TexturePtr texture;

    copyRightObj->unk_1C++;
    texture = func_800783AC(aCopyrightTex);
    var_s2 = copyRightObj->top;
    temp_s7 = copyRightObj->left;
    gSPDisplayList(gfx++, D_3000088);

    for (row = 0; row < 14; row++) {
        var_a2 = UNK_RAND_MACRO(row, 11, 5);
        if (copyRightObj->unk_1C < 32) {
            var_a2 = ((32 - copyRightObj->unk_1C) * var_a2) / 32;
        } else {
            var_a2 = 0;
        }
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 1 /* unused by macro */, 0, row, 128,
                           row + 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, (temp_s7 + var_a2) << 2, (var_s2 + row) << 2, (temp_s7 + var_a2 + 128) << 2,
                                (var_s2 + row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    return gfx;
}

Gfx* Credits_PortraitsDraw(Gfx* gfx, Object* portraitsObj) {
    s32 pad[14];
    unk_800E3F28* sp34;
    s32 temp_v1;
    s32 var_a2;
    s32 temp;

    sp34 = &D_800E3F28[portraitsObj->unk_18];
    temp_v1 = portraitsObj->unk_1C;
    temp = D_i6_8011F4DC[(portraitsObj->unk_20 % 4) * 2];

    if (temp < 100) {
        var_a2 = SCREEN_WIDTH - (temp_v1 / 1.2);
    } else {
        var_a2 = (temp_v1 / 1.2) - 180;
    }

    if (portraitsObj->unk_08 == 0) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255 - temp_v1);
        gfx = func_80078F80(gfx, sp34, var_a2, -5, 1, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

Gfx* Credits_StartRolesDraw(Gfx* gfx, Object* startRolesObj) {
    s32 pad[3];
    s32 roleIndex;
    char* roleName;

    roleIndex = startRolesObj->cmdId - OBJECT_CREDITS_ROLE_0;
    roleName = gCreditsAttributions[roleIndex];

    gDPSetPrimColor(gfx++, 0, 0, 24, 24, 24, 255);

    switch (roleIndex % 4) {
        case 0:
        case 3:
            gfx = Font_DrawString(gfx, startRolesObj->left + 1, startRolesObj->top + 1, roleName, 0, FONT_SET_6, 0);
            break;
        case 1:
        case 2:
            gfx = Font_DrawString(gfx, (startRolesObj->left - Font_GetStringWidth(roleName, FONT_SET_6, 0)) + 1,
                                  startRolesObj->top + 1, roleName, 0, FONT_SET_6, 0);
            break;
    }

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    switch (roleIndex % 4) {
        case 0:
        case 3:
            gfx = Font_DrawString(gfx, startRolesObj->left, startRolesObj->top, roleName, 0, FONT_SET_6, 0);
            break;
        case 1:
        case 2:
            gfx = Font_DrawString(gfx, startRolesObj->left - Font_GetStringWidth(roleName, FONT_SET_6, 0),
                                  startRolesObj->top, roleName, 0, FONT_SET_6, 0);
            break;
    }

    return gfx;
}

Gfx* Credits_EndRolesDraw(Gfx* gfx, Object* endRolesObj) {
    char* roleName;
    s32 roleIndex = endRolesObj->cmdId - OBJECT_CREDITS_ROLE_0;

    roleName = gCreditsAttributions[roleIndex];

    gDPSetPrimColor(gfx++, 0, 0, 24, 24, 24, 255);
    gfx = Font_DrawString(gfx, endRolesObj->left + 1, endRolesObj->top + 1, roleName, 0, FONT_SET_6, 0);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = Font_DrawString(gfx, endRolesObj->left, endRolesObj->top, roleName, 0, FONT_SET_6, 0);

    return gfx;
}

Gfx* Credits_StartNameDraw(Gfx* gfx, Object* startNameObj) {
    s32 temp_v1;
    s32 pad[2];
    bool wordFadeInProgress;
    s32 pad2[9];
    char* temp_a3;

    temp_v1 = startNameObj->cmdId - OBJECT_CREDITS_NAME_0;
    temp_a3 = gCreditsNames[temp_v1];

    switch (startNameObj->unk_04) {
        case 0:
            wordFadeInProgress = false;
            switch (temp_v1 % 4) {
                case 0:
                case 3:
                    gfx = Credits_FadeInNameByLetter(gfx, startNameObj, &wordFadeInProgress, false);
                    break;
                case 1:
                case 2:
                    gfx = Credits_FadeInNameByLetter(gfx, startNameObj, &wordFadeInProgress, true);
                    break;
            }
            if (!wordFadeInProgress) {
                startNameObj->unk_04 = 1;
            }
            break;
        case 1:
        case 2:
            switch (temp_v1 % 4) {
                case 0:
                case 3:
                    gfx = Font_DrawString(gfx, startNameObj->left, startNameObj->top, temp_a3, 0, FONT_SET_1, 0);
                    break;
                case 1:
                case 2:
                    gfx = Font_DrawString(gfx, startNameObj->left - Font_GetStringWidth(temp_a3, FONT_SET_1, 0),
                                          startNameObj->top, temp_a3, 0, FONT_SET_1, 0);
                    break;
            }
            break;
    }
    return gfx;
}

Gfx* Credits_EndNameDraw(Gfx* gfx, Object* endNamesObj) {
    s32 index = endNamesObj->cmdId - OBJECT_CREDITS_NAME_0;
    char* temp = gCreditsNames[index];

    return Font_DrawString(gfx, endNamesObj->left, endNamesObj->top, temp, 0, FONT_SET_1, 0);
}

extern u16 gInputPressed;

void Credits_OldCarsUpdate(Object* oldCarsObj) {
    s32 var_v1;
    unk_800E3F28* temp_v0;

    temp_v0 = &D_800E3F28[oldCarsObj->unk_18];
    var_v1 = 0;
    if (temp_v0->unk_04 == -1) {
        temp_v0->unk_04 = 0;
        oldCarsObj->unk_04 = 0;
        var_v1 = 1;
    }
    if (D_i6_8011DFA0) {
        if (gInputPressed & BTN_LEFT) {
            func_800BA8D8(30);
            if (oldCarsObj->unk_04 != 0) {
                oldCarsObj->unk_04--;
            } else {
                oldCarsObj->unk_04 = 29;
            }
            var_v1++;
        }

        if (gInputPressed & BTN_RIGHT) {
            func_800BA8D8(30);
            oldCarsObj->unk_04++;
            oldCarsObj->unk_04 = oldCarsObj->unk_04 % 30;
            var_v1++;
        }
    }
    if (var_v1 != 0) {
        func_800793E8(oldCarsObj->unk_18, 0, D_i6_8011E560[oldCarsObj->unk_04]);
    }
}

void Credits_CarsUpdate(Object* carsObj) {
    s32 pad;
    s32 var_a2;
    s32 var_v1;
    Object* temp_v0_2;

    var_a2 = 0;

    carsObj->left = D_i6_8011F4DC[(carsObj->unk_20 % 4) * 2 + 0];
    carsObj->top = D_i6_8011F4DC[(carsObj->unk_20 % 4) * 2 + 1];
    switch (carsObj->unk_08) {
        case 0:
            if (++carsObj->unk_1C >= 64) {
                carsObj->unk_08 = 1;
            }
            break;
        case 1:
            carsObj->unk_1C = 0;
            break;
        case 2:
            if (++carsObj->unk_1C >= 64) {
                carsObj->unk_08 = 3;
                carsObj->unk_1C = 0;
                temp_v0_2 = Object_Get(OBJECT_CREDITS_SCRIPT);
                var_a2 = 0;
                if (temp_v0_2 != NULL) {
                    temp_v0_2->unk_08 = 2;
                }
            }
            break;
        case 3:
            if (carsObj->unk_1C != 0) {
                carsObj->unk_08 = 0;
                carsObj->unk_20++;
                var_v1 = 0;
                if ((carsObj->unk_20 == 5) && (D_i6_8011FAF0[9] == 0)) {
                    var_a2 = 9;
                    D_i6_8011FAF0[9] = 1;
                    var_v1 = 1;
                }
                if (var_v1 == 0) {
                    while (true) {
                        var_a2 = Math_Rand1() % 30;
                        if (D_i6_8011FAF0[var_a2] == 0) {
                            D_i6_8011FAF0[var_a2] = 1;
                            goto label;
                        }
                        var_v1++;
                        if (var_v1 > 10) {
                            break;
                        }
                    }

                    for (var_v1 = 0; var_v1 < ARRAY_COUNT(D_i6_8011FAF0); var_v1++) {
                        var_a2 = var_v1;
                        if (D_i6_8011FAF0[var_v1] == 0) {
                            D_i6_8011FAF0[var_v1] = 1;
                            goto label;
                        }
                    }
                }
            label:
                carsObj->unk_04 = var_a2;
                var_a2 = 1;
                temp_v0_2 = Object_Get(OBJECT_CREDITS_PORTRAITS);
                if ((temp_v0_2 != NULL) && (temp_v0_2->unk_08 == 3)) {
                    temp_v0_2->unk_1C = 1;
                }
            }
            break;
    }

    if (D_800E3F28[carsObj->unk_18].unk_04 == -1) {
        D_800E3F28[carsObj->unk_18].unk_04 = 0;
        carsObj->unk_04 = Math_Rand1() % 30;
        D_i6_8011FAF0[carsObj->unk_04] = 1;
        var_a2++;
    }
    if (var_a2 != 0) {
        func_800793E8(carsObj->unk_18, 0, D_i6_8011E560[carsObj->unk_04]);
    }
}

void Credits_PortraitsUpdate(Object* portraitsObj) {
    s32 pad;
    s32 var_v1 = 0;

    switch (portraitsObj->unk_08) {
        case 0:
            if (++portraitsObj->unk_1C >= 255) {
                portraitsObj->unk_1C = 0;
                portraitsObj->unk_08 = 3;
            }
            break;
        case 3:
            if (portraitsObj->unk_1C != 0) {
                portraitsObj->unk_08 = 0;
                portraitsObj->unk_20++;
                portraitsObj->unk_04 = Object_Get(OBJECT_CREDITS_CARS)->unk_04;
                var_v1 = 1;
                portraitsObj->unk_1C = 0;
            }
            break;
    }

    if (D_800E3F28[portraitsObj->unk_18].unk_04 == -1) {
        D_800E3F28[portraitsObj->unk_18].unk_04 = 0;
        portraitsObj->unk_04 = Object_Get(OBJECT_CREDITS_CARS)->unk_04;
        var_v1++;
    }
    if (var_v1 != 0) {
        func_800793E8(portraitsObj->unk_18, 0, D_i6_8011EBF8[portraitsObj->unk_04]);
    }
}

bool Object_MovePosXAndCheckTarget(Object* object, s32 step, s32 target) {

    object->left += step;
    if (step < 0) {
        if (target >= object->left) {
            return true;
        }
    } else {
        if (object->left >= target) {
            return true;
        }
    }
    return false;
}

bool Object_MovePosYAndCheckTarget(Object* object, s32 step, s32 target) {

    object->top += step;
    if (step < 0) {
        if (target >= object->top) {
            return true;
        }
    } else {
        if (object->top >= target) {
            return true;
        }
    }
    return false;
}

extern u32 gGameFrameCount;

bool Object_OnIntervalMovePosYAndCheckTarget(Object* object, s32 step, s32 target, s32 frameInterval) {

    if (gGameFrameCount % frameInterval) {
        return false;
    }

    object->top += step;
    if (step < 0) {
        if (target >= object->top) {
            return true;
        }
    } else {
        if (object->top >= target) {
            return true;
        }
    }
    return false;
}

void Credits_ObjectInit(s32 cmdId, s32 left, s32 top, s8 priority);

void Credits_ScriptUpdate(Object* scriptObj) {
    s32 temp_a0;
    s32 index;
    Object* temp_v0_4;

    scriptObj->unk_1C++;
    if (scriptObj->unk_04 < 18) {
        switch (scriptObj->unk_08) {
            case 0:
                switch (scriptObj->unk_1C) {
                    case 0x1:
                        Credits_ObjectInit(OBJECT_CREDITS_ROLE_0 + scriptObj->unk_04,
                                           kStartRolesInitialPositions[(scriptObj->unk_04 % 4) * 2 + 0],
                                           kStartRolesInitialPositions[(scriptObj->unk_04 % 4) * 2 + 1], 12);
                        temp_v0_4 = Object_Get(OBJECT_CREDITS_CARS);
                        if ((temp_v0_4 != NULL) && (temp_v0_4->unk_08 == 3)) {
                            temp_v0_4->unk_1C++;
                        }
                        break;
                    case 0x3C:
                        Credits_ObjectInit(OBJECT_CREDITS_NAME_0 + scriptObj->unk_04,
                                           kStartNamesInitialPositions[(scriptObj->unk_04 % 4) * 2 + 0],
                                           kStartNamesInitialPositions[(scriptObj->unk_04 % 4) * 2 + 1], 10);
                        scriptObj->unk_08 = 1;
                        break;
                }
                break;
            case 1:
                scriptObj->unk_1C = 0;
                break;
            case 2:
                if (scriptObj->unk_1C > 30) {
                    scriptObj->unk_04++;
                    scriptObj->unk_08 = 0;
                    scriptObj->unk_1C = 0;
                }
                break;
        }
    } else {
        switch (scriptObj->unk_04) {
            case 18:
                if ((scriptObj->unk_1C % 15) == 0) {
                    index = scriptObj->unk_1C / 15;
                    temp_a0 = kCreditsObjectScrollScript[index - 1];
                    if (temp_a0 > 0) {
                        Credits_ObjectInit(temp_a0, 50, 240, 0xA);
                    } else if (temp_a0 < 0) {
                        scriptObj->unk_04++;
                    }
                }
                break;
            case 19:
                if (Object_Get(OBJECT_CREDITS_NAME_30) == NULL) {
                    scriptObj->unk_04++;
                }
                break;
            case 20:
                Credits_ObjectInit(OBJECT_CREDITS_MENU_LADY, 200, 30, 8);
                scriptObj->unk_04++;
                break;
            case 21:
                scriptObj->cmdId = OBJECT_FREE;
                break;
            default:
                break;
        }
    }
}

void Credits_StartRoleUpdate(Object* startRoleObj) {
    s32 pad[2];
    s32 roleIndex;
    s32 sp28;
    s32 var_a2;
    s32 var_a1;
    char* roleName;
    Object* temp_v0_3;

    roleIndex = startRoleObj->cmdId - OBJECT_CREDITS_ROLE_0;
    roleName = gCreditsAttributions[roleIndex];

    switch (roleIndex % 4) {
        case 0:
        case 3:
            sp28 = -1;
            break;
        case 1:
        case 2:
            sp28 = 1;
            break;
    }

    if (roleIndex % 2) {
        var_a2 = 150;
        var_a1 = 1;
    } else {
        var_a2 = 70;
        var_a1 = -1;
    }

    switch (startRoleObj->unk_04) {
        case 0:
            if (Object_MovePosYAndCheckTarget(startRoleObj, var_a1, var_a2)) {
                startRoleObj->unk_04 = 1;
                startRoleObj->unk_1C = 0;
            }
            break;
        case 1:
            if (++startRoleObj->unk_1C > 120) {
                startRoleObj->unk_04 = 2;
                temp_v0_3 = Object_Get(OBJECT_CREDITS_CARS);
                if ((temp_v0_3 != NULL) && (temp_v0_3->unk_08 == 1)) {
                    temp_v0_3->unk_08 = 2;
                }
            }
            break;
        case 2:
            Object_LerpAwayFromPosX(startRoleObj, kStartRolesInitialPositions[(roleIndex % 4) * 2], sp28);
            if (sp28 < 0) {
                if (startRoleObj->left < -Font_GetStringWidth(roleName, FONT_SET_1, 0)) {
                    startRoleObj->cmdId = OBJECT_FREE;
                }
            } else {
                if ((Font_GetStringWidth(roleName, FONT_SET_1, 0) + SCREEN_WIDTH) < startRoleObj->left) {
                    startRoleObj->cmdId = OBJECT_FREE;
                }
            }
            break;
    }
}

void Credits_EndRoleUpdate(Object* endRoleObj) {
    if (Object_OnIntervalMovePosYAndCheckTarget(endRoleObj, -1, -20, 2)) {
        endRoleObj->cmdId = OBJECT_FREE;
    }
}

void Credits_StartNameUpdate(Object* startNameObj) {
    s32 nameIndex;
    s32 initialStep;

    nameIndex = startNameObj->cmdId - OBJECT_CREDITS_NAME_0;

    switch (nameIndex % 4) {
        case 0:
        case 3:
            initialStep = 1;
            break;
        case 1:
        case 2:
            initialStep = -1;
            break;
    }

    switch (startNameObj->unk_04) {
        case 0:
            startNameObj->unk_1C++;
            break;
        case 1:
            if (Object_Get(OBJECT_CREDITS_ROLE_0 + nameIndex)->unk_04 >= 2) {
                startNameObj->unk_04 = 2;
            }
            break;
        case 2:
            Object_LerpAwayFromPosX(startNameObj, kStartNamesInitialPositions[(nameIndex % 4) * 2], initialStep);
            if (initialStep > 0) {
                if (startNameObj->left > SCREEN_WIDTH) {
                    startNameObj->cmdId = OBJECT_FREE;
                }
            } else {
                if (startNameObj->left < 0) {
                    startNameObj->cmdId = OBJECT_FREE;
                }
            }
            break;
    }
}

void Credits_EndNameUpdate(Object* endNameObj) {
    if (Object_OnIntervalMovePosYAndCheckTarget(endNameObj, -1, -20, 2)) {
        endNameObj->cmdId = OBJECT_FREE;
    }
}

void Credits_MenuLadyUpdate(Object* menuLadyObj) {

    switch (menuLadyObj->unk_04) {
        case 0:
            if (--menuLadyObj->unk_1C < 0x18) {
                menuLadyObj->unk_04++;
                menuLadyObj->unk_1C = 0;
            }
            break;
        case 1:
            if (++menuLadyObj->unk_1C >= 0x3C) {
                menuLadyObj->unk_04++;
                menuLadyObj->unk_1C = 0x17;
            }
            break;
        case 2:
            menuLadyObj->unk_1C += menuLadyObj->unk_1C / 11;
            if (menuLadyObj->unk_1C >= 0xB6) {
                menuLadyObj->unk_04++;
                menuLadyObj->unk_1C = 0;
            }
            break;
        case 3:
            if (++menuLadyObj->unk_1C >= 0x12) {
                menuLadyObj->unk_04++;
                menuLadyObj->unk_1C = 0;
                Credits_ObjectInit(OBJECT_CREDITS_SEE_YOU_AGAIN, 0x80, 0x40, 8);
                func_800BA8D8(0x2B);
            }
            break;
        case 4:
            break;
    }
}

void Credits_SeeYouAgainUpdate(Object* seeYouAgainObj) {

    switch (seeYouAgainObj->unk_04) {
        case 0:
            if (++seeYouAgainObj->unk_1C >= 175) {
                seeYouAgainObj->unk_04++;
                seeYouAgainObj->unk_1C = 0;
                Credits_ObjectInit(OBJECT_CREDITS_COPYRIGHT, 0x60, 0xCD, 8);
            }
            break;
        case 1:
            if (++seeYouAgainObj->unk_1C >= 100) {
                seeYouAgainObj->unk_04++;
                seeYouAgainObj->unk_1C = 0;
            }
            break;
        case 2:
            break;
    }
}

void Credits_IntroUpdate(Object* introObj) {

    switch (++introObj->unk_18) {
        case 30:
            if (introObj->unk_04 == 0) {
                introObj->unk_04 = 1;
            }
            break;
        case 60:
            if (introObj->unk_08 == 0) {
                introObj->unk_08 = 1;
            }
            break;
        case 370:
            Credits_ObjectInit(OBJECT_CREDITS_SCRIPT, 0, 0, 0);
            Credits_ObjectInit(OBJECT_CREDITS_CARS, 0, 0, 4);
            Credits_ObjectInit(OBJECT_CREDITS_PORTRAITS, 0, 0, 8);
            introObj->cmdId = OBJECT_FREE;
            break;
        default:
            if (introObj->unk_18 > 300) {
                if (introObj->unk_08 == 2) {
                    introObj->unk_08 = 3;
                }
                if (introObj->unk_04 == 2) {
                    introObj->unk_04 = 3;
                }
            }
            break;
    }

    switch (introObj->unk_04) {
        case 0:
            introObj->unk_1C = 256;
            break;
        case 1:
            if (introObj->unk_1C > 0) {
                introObj->unk_1C -= 4;
            }
            if (introObj->unk_1C <= 0) {
                introObj->unk_1C = 0;
                introObj->unk_04 = 2;
            }
            break;
        case 3:
            if (introObj->unk_1C < 255) {
                introObj->unk_1C += 4;
            }
            if (introObj->unk_1C >= 255) {
                introObj->unk_1C = 255;
                introObj->unk_04 = 4;
            }
            break;
        case 4:
            introObj->unk_1C = 255;
            break;
        default:
            introObj->unk_1C = 0;
            break;
    }
    switch (introObj->unk_08) {
        case 0:
            introObj->unk_20 = 256;
            break;
        case 1:
            if (introObj->unk_20 > 0) {
                introObj->unk_20 -= 4;
            }
            if (introObj->unk_20 <= 0) {
                introObj->unk_20 = 0;
                introObj->unk_08 = 2;
            }
            break;
        case 3:
            if (introObj->unk_20 < 255) {
                introObj->unk_20 += 4;
            }
            if (introObj->unk_20 >= 256) {
                introObj->unk_20 = 255;
                introObj->unk_08 = 4;
            }
            break;
        case 4:
            introObj->unk_20 = 255;
            break;
        default:
            introObj->unk_20 = 0;
            break;
    }
}

void Credits_CopyrightUpdate(Object* copyrightObj) {
}

void Credits_ObjectInit(s32 cmdId, s32 left, s32 top, s8 priority) {
    s32 i = 0;
    Object* var_s0 = gObjects;

    while (true) {
        if (var_s0->cmdId == OBJECT_FREE) {
            break;
        }

        if (++i > ARRAY_COUNT(gObjects)) {
            return;
        }
        var_s0++;
    }

    var_s0->cmdId = cmdId;
    var_s0->unk_04 = 0;
    var_s0->unk_08 = 0;
    var_s0->left = left;
    var_s0->top = top;
    var_s0->priority = priority;
    var_s0->shouldDraw = true;
    var_s0->unk_1C = 0;
    var_s0->unk_20 = 0;

    switch (cmdId) {
        case OBJECT_CREDITS_OLD_CARS:
            Credits_OldCarsInit(var_s0);
            break;
        case OBJECT_CREDITS_CARS:
            Credits_CarsInit(var_s0);
            break;
        case OBJECT_CREDITS_MENU_LADY:
            Credits_MenuLadyInit(var_s0);
            break;
        case OBJECT_CREDITS_SEE_YOU_AGAIN:
            Credits_SeeYouAgainInit();
            break;
        case OBJECT_CREDITS_INTRO:
            Credits_IntroInit(var_s0);
            break;
        case OBJECT_CREDITS_COPYRIGHT:
            Credits_CopyrightInit();
            break;
        case OBJECT_CREDITS_PORTRAITS:
            Credits_PortraitsInit(var_s0);
            break;
        case OBJECT_CREDITS_SCRIPT:
        case OBJECT_CREDITS_BACKGROUND:
        default:
            break;
    }
}

Gfx* Credits_ObjectDraw(Gfx* gfx) {
    s32 i;
    s32 j;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 32; j++) {

            if ((gObjects[j].priority != i) || !gObjects[j].shouldDraw) {
                continue;
            }

            switch (gObjects[j].cmdId) {
                case OBJECT_FREE:
                    break;
                case OBJECT_FRAMEBUFFER:
                    gfx = func_8007AB88(gfx);
                    gfx = func_8007AE70(gfx);
                    gfx = func_8007ABA4(gfx);
                    break;
                case OBJECT_150:
                    gfx = func_8007AC48(gfx, 0, 0, 0);
                    break;
                case OBJECT_CREDITS_OLD_CARS:
                    gfx = Credits_OldCarsDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_BACKGROUND:
                    gfx = func_8007AC48(gfx, 0, 0, 0);
                    break;
                case OBJECT_CREDITS_CARS:
                    gfx = Credits_CarsDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_MENU_LADY:
                    gfx = Credits_MenuLadyDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_SEE_YOU_AGAIN:
                    gfx = Credits_SeeYouAgainDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_INTRO:
                    gfx = Credits_IntroDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_COPYRIGHT:
                    gfx = Credits_CopyrightDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_PORTRAITS:
                    gfx = Credits_PortraitsDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_ROLE_0:
                case OBJECT_CREDITS_ROLE_1:
                case OBJECT_CREDITS_ROLE_2:
                case OBJECT_CREDITS_ROLE_3:
                case OBJECT_CREDITS_ROLE_4:
                case OBJECT_CREDITS_ROLE_5:
                case OBJECT_CREDITS_ROLE_6:
                case OBJECT_CREDITS_ROLE_7:
                case OBJECT_CREDITS_ROLE_8:
                case OBJECT_CREDITS_ROLE_9:
                case OBJECT_CREDITS_ROLE_10:
                case OBJECT_CREDITS_ROLE_11:
                case OBJECT_CREDITS_ROLE_12:
                case OBJECT_CREDITS_ROLE_13:
                case OBJECT_CREDITS_ROLE_14:
                case OBJECT_CREDITS_ROLE_15:
                case OBJECT_CREDITS_ROLE_16:
                case OBJECT_CREDITS_ROLE_17:
                    gfx = Credits_StartRolesDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_ROLE_18:
                case OBJECT_CREDITS_ROLE_19:
                case OBJECT_CREDITS_ROLE_20:
                case OBJECT_CREDITS_ROLE_21:
                case OBJECT_CREDITS_ROLE_22:
                case OBJECT_CREDITS_ROLE_23:
                case OBJECT_CREDITS_ROLE_24:
                case OBJECT_CREDITS_ROLE_25:
                case OBJECT_CREDITS_ROLE_26:
                case OBJECT_CREDITS_ROLE_27:
                case OBJECT_CREDITS_ROLE_28:
                case OBJECT_CREDITS_ROLE_29:
                case OBJECT_CREDITS_ROLE_30:
                    gfx = Credits_EndRolesDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_NAME_0:
                case OBJECT_CREDITS_NAME_1:
                case OBJECT_CREDITS_NAME_2:
                case OBJECT_CREDITS_NAME_3:
                case OBJECT_CREDITS_NAME_4:
                case OBJECT_CREDITS_NAME_5:
                case OBJECT_CREDITS_NAME_6:
                case OBJECT_CREDITS_NAME_7:
                case OBJECT_CREDITS_NAME_8:
                case OBJECT_CREDITS_NAME_9:
                case OBJECT_CREDITS_NAME_10:
                case OBJECT_CREDITS_NAME_11:
                case OBJECT_CREDITS_NAME_12:
                case OBJECT_CREDITS_NAME_13:
                case OBJECT_CREDITS_NAME_14:
                case OBJECT_CREDITS_NAME_15:
                case OBJECT_CREDITS_NAME_16:
                case OBJECT_CREDITS_NAME_17:
                    gfx = Credits_StartNameDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_NAME_18:
                case OBJECT_CREDITS_NAME_19:
                case OBJECT_CREDITS_NAME_20:
                case OBJECT_CREDITS_NAME_21:
                case OBJECT_CREDITS_NAME_22:
                case OBJECT_CREDITS_NAME_23:
                case OBJECT_CREDITS_NAME_24:
                case OBJECT_CREDITS_NAME_25:
                case OBJECT_CREDITS_NAME_26:
                case OBJECT_CREDITS_NAME_27:
                case OBJECT_CREDITS_NAME_28:
                case OBJECT_CREDITS_NAME_29:
                case OBJECT_CREDITS_NAME_30:
                case OBJECT_CREDITS_NAME_31:
                case OBJECT_CREDITS_NAME_32:
                case OBJECT_CREDITS_NAME_33:
                case OBJECT_CREDITS_NAME_34:
                case OBJECT_CREDITS_NAME_35:
                    gfx = Credits_EndNameDraw(gfx, &gObjects[j]);
                    break;
            }
        }
    }
    return gfx;
}

void Credits_ObjectUpdate(void) {
    s32 i;

    for (i = 0; i < 32; i++) {

        switch (gObjects[i].cmdId) {
            case OBJECT_FREE:
                break;
            case OBJECT_CREDITS_OLD_CARS:
                Credits_OldCarsUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_SCRIPT:
                Credits_ScriptUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_CARS:
                Credits_CarsUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_PORTRAITS:
                Credits_PortraitsUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_ROLE_0:
            case OBJECT_CREDITS_ROLE_1:
            case OBJECT_CREDITS_ROLE_2:
            case OBJECT_CREDITS_ROLE_3:
            case OBJECT_CREDITS_ROLE_4:
            case OBJECT_CREDITS_ROLE_5:
            case OBJECT_CREDITS_ROLE_6:
            case OBJECT_CREDITS_ROLE_7:
            case OBJECT_CREDITS_ROLE_8:
            case OBJECT_CREDITS_ROLE_9:
            case OBJECT_CREDITS_ROLE_10:
            case OBJECT_CREDITS_ROLE_11:
            case OBJECT_CREDITS_ROLE_12:
            case OBJECT_CREDITS_ROLE_13:
            case OBJECT_CREDITS_ROLE_14:
            case OBJECT_CREDITS_ROLE_15:
            case OBJECT_CREDITS_ROLE_16:
            case OBJECT_CREDITS_ROLE_17:
                Credits_StartRoleUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_ROLE_18:
            case OBJECT_CREDITS_ROLE_19:
            case OBJECT_CREDITS_ROLE_20:
            case OBJECT_CREDITS_ROLE_21:
            case OBJECT_CREDITS_ROLE_22:
            case OBJECT_CREDITS_ROLE_23:
            case OBJECT_CREDITS_ROLE_24:
            case OBJECT_CREDITS_ROLE_25:
            case OBJECT_CREDITS_ROLE_26:
            case OBJECT_CREDITS_ROLE_27:
            case OBJECT_CREDITS_ROLE_28:
            case OBJECT_CREDITS_ROLE_29:
            case OBJECT_CREDITS_ROLE_30:
                Credits_EndRoleUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_NAME_0:
            case OBJECT_CREDITS_NAME_1:
            case OBJECT_CREDITS_NAME_2:
            case OBJECT_CREDITS_NAME_3:
            case OBJECT_CREDITS_NAME_4:
            case OBJECT_CREDITS_NAME_5:
            case OBJECT_CREDITS_NAME_6:
            case OBJECT_CREDITS_NAME_7:
            case OBJECT_CREDITS_NAME_8:
            case OBJECT_CREDITS_NAME_9:
            case OBJECT_CREDITS_NAME_10:
            case OBJECT_CREDITS_NAME_11:
            case OBJECT_CREDITS_NAME_12:
            case OBJECT_CREDITS_NAME_13:
            case OBJECT_CREDITS_NAME_14:
            case OBJECT_CREDITS_NAME_15:
            case OBJECT_CREDITS_NAME_16:
            case OBJECT_CREDITS_NAME_17:
                Credits_StartNameUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_NAME_18:
            case OBJECT_CREDITS_NAME_19:
            case OBJECT_CREDITS_NAME_20:
            case OBJECT_CREDITS_NAME_21:
            case OBJECT_CREDITS_NAME_22:
            case OBJECT_CREDITS_NAME_23:
            case OBJECT_CREDITS_NAME_24:
            case OBJECT_CREDITS_NAME_25:
            case OBJECT_CREDITS_NAME_26:
            case OBJECT_CREDITS_NAME_27:
            case OBJECT_CREDITS_NAME_28:
            case OBJECT_CREDITS_NAME_29:
            case OBJECT_CREDITS_NAME_30:
            case OBJECT_CREDITS_NAME_31:
            case OBJECT_CREDITS_NAME_32:
            case OBJECT_CREDITS_NAME_33:
            case OBJECT_CREDITS_NAME_34:
            case OBJECT_CREDITS_NAME_35:
                Credits_EndNameUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_MENU_LADY:
                Credits_MenuLadyUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_SEE_YOU_AGAIN:
                Credits_SeeYouAgainUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_INTRO:
                Credits_IntroUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_COPYRIGHT:
                Credits_CopyrightUpdate(&gObjects[i]);
                break;
        }
    }
}

extern s16 D_800CCFE8;

void Credits_Init(void) {
    D_800CCFE8 = 3;
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Credits_ObjectInit(OBJECT_CREDITS_BACKGROUND, 0, 0, 1);
    Credits_ObjectInit(OBJECT_CREDITS_INTRO, 0, 0, 8);
}

extern s32 gGameMode;
extern Controller gSharedController;

s32 Credits_Update(void) {

    Controller_SetGlobalInputs(&gSharedController);
    if (gInputPressed & (BTN_A | BTN_START)) {
        D_i6_8011DFA0 ^= 1;
    }
    if ((gGameMode != GAMEMODE_FLX_UNSKIPPABLE_CREDITS) && (gInputPressed & BTN_B)) {
        return GAMEMODE_FLX_MAIN_MENU;
    } else {
        return gGameMode;
    }
}

Gfx* Credits_Draw(Gfx* gfx) {
    Credits_ObjectUpdate();
    gfx = Credits_ObjectDraw(gfx);
    func_800790D4();
    return gfx;
}
