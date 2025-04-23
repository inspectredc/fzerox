#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "src/overlays/ovl_i2/ovl_i2.h"
#include "ovl_i6.h"
#include "audio.h"
#include "assets/segment_2B9EA0.h"
#include "assets/segment_17B1E0.h"

s8 D_i6_8011FAF0[30];

s8 sDebugCreditsOldMachines = false;
UNUSED s32 D_i6_8011DFA4 = 64;
UNUSED s32 D_i6_8011DFA8 = 40;

s32 D_i6_8011DFAC = 60;
s32 D_i6_8011DFB0 = 30;
s32 D_i6_8011DFB4 = 50;

/*
    VEHICLE ARTWORK
 */

// BLUE FALCON
unk_80077D50 sCreditsBlueFalconCompTexInfo[] = { { 18, aCreditsBlueFalconTex, TEX_WIDTH(aCreditsBlueFalconTex),
                                                   TEX_HEIGHT(aCreditsBlueFalconTex),
                                                   TEX_COMPRESSED_SIZE(aCreditsBlueFalconTex) },
                                                 { 0 } };

// WILD GOOSE
unk_80077D50 sCreditsWildGooseCompTexInfo[] = { { 18, aCreditsWildGooseTex, TEX_WIDTH(aCreditsWildGooseTex),
                                                  TEX_HEIGHT(aCreditsWildGooseTex),
                                                  TEX_COMPRESSED_SIZE(aCreditsWildGooseTex) },
                                                { 0 } };

// FIRE STINGRAY
unk_80077D50 sCreditsFireStingrayCompTexInfo[] = { { 18, aCreditsFireStingrayTex, TEX_WIDTH(aCreditsFireStingrayTex),
                                                     TEX_HEIGHT(aCreditsFireStingrayTex),
                                                     TEX_COMPRESSED_SIZE(aCreditsFireStingrayTex) },
                                                   { 0 } };

// GOLDEN FOX
unk_80077D50 sCreditsGoldenFoxCompTexInfo[] = { { 18, aCreditsGoldenFoxTex, TEX_WIDTH(aCreditsGoldenFoxTex),
                                                  TEX_HEIGHT(aCreditsGoldenFoxTex),
                                                  TEX_COMPRESSED_SIZE(aCreditsGoldenFoxTex) },
                                                { 0 } };

// RED GAZELLE
unk_80077D50 sCreditsRedGazelleCompTexInfo[] = { { 18, aCreditsRedGazelleTex, TEX_WIDTH(aCreditsRedGazelleTex),
                                                   TEX_HEIGHT(aCreditsRedGazelleTex),
                                                   TEX_COMPRESSED_SIZE(aCreditsRedGazelleTex) },
                                                 { 0 } };

// WHITE CAT
unk_80077D50 sCreditsWhiteFoxCompTexInfo[] = { { 18, aCreditsWhiteFoxTex, TEX_WIDTH(aCreditsWhiteFoxTex),
                                                 TEX_HEIGHT(aCreditsWhiteFoxTex),
                                                 TEX_COMPRESSED_SIZE(aCreditsWhiteFoxTex) },
                                               { 0 } };

// IRON TIGER
unk_80077D50 sCreditsIronTigerCompTexInfo[] = { { 18, aCreditsIronTigerTex, TEX_WIDTH(aCreditsIronTigerTex),
                                                  TEX_HEIGHT(aCreditsIronTigerTex),
                                                  TEX_COMPRESSED_SIZE(aCreditsIronTigerTex) },
                                                { 0 } };

// DEEP CLAW
unk_80077D50 sCreditsDeepClawCompTexInfo[] = { { 18, aCreditsDeepClawTex, TEX_WIDTH(aCreditsDeepClawTex),
                                                 TEX_HEIGHT(aCreditsDeepClawTex),
                                                 TEX_COMPRESSED_SIZE(aCreditsDeepClawTex) },
                                               { 0 } };

// CRAZY BEAR
unk_80077D50 sCreditsCrazyBearCompTexInfo[] = { { 18, aCreditsCrazyBearTex, TEX_WIDTH(aCreditsCrazyBearTex),
                                                  TEX_HEIGHT(aCreditsCrazyBearTex),
                                                  TEX_COMPRESSED_SIZE(aCreditsCrazyBearTex) },
                                                { 0 } };

// GREAT STAR
unk_80077D50 sCreditsGreatStarCompTexInfo[] = { { 18, aCreditsGreatStarTex, TEX_WIDTH(aCreditsGreatStarTex),
                                                  TEX_HEIGHT(aCreditsGreatStarTex),
                                                  TEX_COMPRESSED_SIZE(aCreditsGreatStarTex) },
                                                { 0 } };

// BIG FANG
unk_80077D50 sCreditsBigFangCompTexInfo[] = { { 18, aCreditsBigFangTex, TEX_WIDTH(aCreditsBigFangTex),
                                                TEX_HEIGHT(aCreditsBigFangTex),
                                                TEX_COMPRESSED_SIZE(aCreditsBigFangTex) },
                                              { 0 } };

// MAD WOLF
unk_80077D50 sCreditsMadWolfCompTexInfo[] = { { 18, aCreditsMadWolfTex, TEX_WIDTH(aCreditsMadWolfTex),
                                                TEX_HEIGHT(aCreditsMadWolfTex),
                                                TEX_COMPRESSED_SIZE(aCreditsMadWolfTex) },
                                              { 0 } };

// NIGHT THUNDER
unk_80077D50 sCreditsNightThunderCompTexInfo[] = { { 18, aCreditsNightThunderTex, TEX_WIDTH(aCreditsNightThunderTex),
                                                     TEX_HEIGHT(aCreditsNightThunderTex),
                                                     TEX_COMPRESSED_SIZE(aCreditsNightThunderTex) },
                                                   { 0 } };

// TWIN NORITTA
unk_80077D50 sCreditsTwinNorittaCompTexInfo[] = { { 18, aCreditsTwinNorittaTex, TEX_WIDTH(aCreditsTwinNorittaTex),
                                                    TEX_HEIGHT(aCreditsTwinNorittaTex),
                                                    TEX_COMPRESSED_SIZE(aCreditsTwinNorittaTex) },
                                                  { 0 } };

// WONDER WASP
unk_80077D50 sCreditsWonderWaspCompTexInfo[] = { { 18, aCreditsWonderWaspTex, TEX_WIDTH(aCreditsWonderWaspTex),
                                                   TEX_HEIGHT(aCreditsWonderWaspTex),
                                                   TEX_COMPRESSED_SIZE(aCreditsWonderWaspTex) },
                                                 { 0 } };

// QUEEN METEOR
unk_80077D50 sCreditsQueenMeteorCompTexInfo[] = { { 18, aCreditsQueenMeteorTex, TEX_WIDTH(aCreditsQueenMeteorTex),
                                                    TEX_HEIGHT(aCreditsQueenMeteorTex),
                                                    TEX_COMPRESSED_SIZE(aCreditsQueenMeteorTex) },
                                                  { 0 } };

// BLOOD HAWK
unk_80077D50 sCreditsBloodHawkCompTexInfo[] = { { 18, aCreditsBloodHawkTex, TEX_WIDTH(aCreditsBloodHawkTex),
                                                  TEX_HEIGHT(aCreditsBloodHawkTex),
                                                  TEX_COMPRESSED_SIZE(aCreditsBloodHawkTex) },
                                                { 0 } };

// ASTRO ROBIN
unk_80077D50 sCreditsAstroRobinCompTexInfo[] = { { 18, aCreditsAstroRobinTex, TEX_WIDTH(aCreditsAstroRobinTex),
                                                   TEX_HEIGHT(aCreditsAstroRobinTex),
                                                   TEX_COMPRESSED_SIZE(aCreditsAstroRobinTex) },
                                                 { 0 } };

// DEATH ANCHOR
unk_80077D50 sCreditsDeathAnchorCompTexInfo[] = { { 18, aCreditsDeathAnchorTex, TEX_WIDTH(aCreditsDeathAnchorTex),
                                                    TEX_HEIGHT(aCreditsDeathAnchorTex),
                                                    TEX_COMPRESSED_SIZE(aCreditsDeathAnchorTex) },
                                                  { 0 } };

// WILD BOAR
unk_80077D50 sCreditsWildBoarCompTexInfo[] = { { 18, aCreditsWildBoarTex, TEX_WIDTH(aCreditsWildBoarTex),
                                                 TEX_HEIGHT(aCreditsWildBoarTex),
                                                 TEX_COMPRESSED_SIZE(aCreditsWildBoarTex) },
                                               { 0 } };

// KING METEOR
unk_80077D50 sCreditsKingMeteorCompTexInfo[] = { { 18, aCreditsKingMeteorTex, TEX_WIDTH(aCreditsKingMeteorTex),
                                                   TEX_HEIGHT(aCreditsKingMeteorTex),
                                                   TEX_COMPRESSED_SIZE(aCreditsKingMeteorTex) },
                                                 { 0 } };

// SUPER PIRANHA
unk_80077D50 sCreditsSuperPiranhaCompTexInfo[] = { { 18, aCreditsSuperPiranhaTex, TEX_WIDTH(aCreditsSuperPiranhaTex),
                                                     TEX_HEIGHT(aCreditsSuperPiranhaTex),
                                                     TEX_COMPRESSED_SIZE(aCreditsSuperPiranhaTex) },
                                                   { 0 } };

// MIGHTY HURRICANE
unk_80077D50 sCreditsMightyHurricaneCompTexInfo[] = {
    { 18, aCreditsMightyHurricaneTex, TEX_WIDTH(aCreditsMightyHurricaneTex), TEX_HEIGHT(aCreditsMightyHurricaneTex),
      TEX_COMPRESSED_SIZE(aCreditsMightyHurricaneTex) },
    { 0 }
};

// SPACE ANGLER
unk_80077D50 sCreditsSpaceAnglerCompTexInfo[] = { { 18, aCreditsSpaceAnglerTex, TEX_WIDTH(aCreditsSpaceAnglerTex),
                                                    TEX_HEIGHT(aCreditsSpaceAnglerTex),
                                                    TEX_COMPRESSED_SIZE(aCreditsSpaceAnglerTex) },
                                                  { 0 } };

// MIGHTY TYPHOON
unk_80077D50 sCreditsMightyTyphoonCompTexInfo[] = { { 18, aCreditsMightyTyphoonTex, TEX_WIDTH(aCreditsMightyTyphoonTex),
                                                      TEX_HEIGHT(aCreditsMightyTyphoonTex),
                                                      TEX_COMPRESSED_SIZE(aCreditsMightyTyphoonTex) },
                                                    { 0 } };

// HYPER SPEEDER
unk_80077D50 sCreditsHyperSpeederCompTexInfo[] = { { 18, aCreditsHyperSpeederTex, TEX_WIDTH(aCreditsHyperSpeederTex),
                                                     TEX_HEIGHT(aCreditsHyperSpeederTex),
                                                     TEX_COMPRESSED_SIZE(aCreditsHyperSpeederTex) },
                                                   { 0 } };

// GREEN PANTHER
unk_80077D50 sCreditsGreenPantherCompTexInfo[] = { { 18, aCreditsGreenPantherTex, TEX_WIDTH(aCreditsGreenPantherTex),
                                                     TEX_HEIGHT(aCreditsGreenPantherTex),
                                                     TEX_COMPRESSED_SIZE(aCreditsGreenPantherTex) },
                                                   { 0 } };

// BLACK BULL
unk_80077D50 sCreditsBlackBullCompTexInfo[] = { { 18, aCreditsBlackBullTex, TEX_WIDTH(aCreditsBlackBullTex),
                                                  TEX_HEIGHT(aCreditsBlackBullTex),
                                                  TEX_COMPRESSED_SIZE(aCreditsBlackBullTex) },
                                                { 0 } };

// LITTLE WYVERN
unk_80077D50 sCreditsLittleWyvernCompTexInfo[] = { { 18, aCreditsLittleWyvernTex, TEX_WIDTH(aCreditsLittleWyvernTex),
                                                     TEX_HEIGHT(aCreditsLittleWyvernTex),
                                                     TEX_COMPRESSED_SIZE(aCreditsLittleWyvernTex) },
                                                   { 0 } };

// SONIC PHANTOM
unk_80077D50 sCreditsSonicPhantomCompTexInfo[] = { { 18, aCreditsSonicPhantomTex, TEX_WIDTH(aCreditsSonicPhantomTex),
                                                     TEX_HEIGHT(aCreditsSonicPhantomTex),
                                                     TEX_COMPRESSED_SIZE(aCreditsSonicPhantomTex) },
                                                   { 0 } };

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
unk_80077D50 sCreditsMenuLadyCompTexInfo[] = { { 17, aCreditsMenuLadyTex, TEX_WIDTH(aCreditsMenuLadyTex),
                                                 TEX_HEIGHT(aCreditsMenuLadyTex),
                                                 TEX_COMPRESSED_SIZE(aCreditsMenuLadyTex) },
                                               { 0 } };

// 'SEE YOU AGAIN!!'
unk_80077D50 sCreditsSeeYouAgainCompTexInfo[] = { { 17, aCreditsSeeYouAgainTex, TEX_WIDTH(aCreditsSeeYouAgainTex),
                                                    TEX_HEIGHT(aCreditsSeeYouAgainTex),
                                                    TEX_COMPRESSED_SIZE(aCreditsSeeYouAgainTex) },
                                                  { 0 } };

// MR ZERO
unk_80077D50 sCreditsMrZeroCompTexInfo[] = { { 17, aCreditsMrZeroTex, TEX_WIDTH(aCreditsMrZeroTex),
                                               TEX_HEIGHT(aCreditsMrZeroTex), TEX_COMPRESSED_SIZE(aCreditsMrZeroTex) },
                                             { 0 } };

// COPYRIGHT LOGO (1998)
//! @bug This has the incorrect compressed size (leftover from version difference?)
#if 0
unk_80077D50 sCreditsCopyrightCompTexInfo[] = { { 17, aCopyrightTex, TEX_WIDTH(aCopyrightTex), TEX_HEIGHT(aCopyrightTex), TEX_COMPRESSED_SIZE(aCopyrightTex) }, { 0 } };
#else
unk_80077D50 sCreditsCopyrightCompTexInfo[] = {
    { 17, aCopyrightTex, TEX_WIDTH(aCopyrightTex), TEX_HEIGHT(aCopyrightTex), 0x439 }, { 0 }
};
#endif

// DR STEWART
unk_80077D50 sCreditsPortraitDrStewartCompTexInfo[] = {
    { 17, aFullPortraitDrStewartTex, TEX_WIDTH(aFullPortraitDrStewartTex), TEX_HEIGHT(aFullPortraitDrStewartTex),
      TEX_COMPRESSED_SIZE(aFullPortraitDrStewartTex) },
    { 0 }
};

// CAPTAIN FALCON
unk_80077D50 sCreditsPortraitCaptainFalconCompTexInfo[] = {
    { 17, aFullPortraitCaptainFalconTex, TEX_WIDTH(aFullPortraitCaptainFalconTex),
      TEX_HEIGHT(aFullPortraitCaptainFalconTex), TEX_COMPRESSED_SIZE(aFullPortraitCaptainFalconTex) },
    { 0 }
};

// JODY SUMMER
unk_80077D50 sCreditsPortraitJodySummerCompTexInfo[] = {
    { 17, aFullPortraitJodySummerTex, TEX_WIDTH(aFullPortraitJodySummerTex), TEX_HEIGHT(aFullPortraitJodySummerTex),
      TEX_COMPRESSED_SIZE(aFullPortraitJodySummerTex) },
    { 0 }
};

// SAMURAI GOROH
unk_80077D50 sCreditsPortraitSamuraiGorohCompTexInfo[] = {
    { 17, aFullPortraitSamuraiGorohTex, TEX_WIDTH(aFullPortraitSamuraiGorohTex),
      TEX_HEIGHT(aFullPortraitSamuraiGorohTex), TEX_COMPRESSED_SIZE(aFullPortraitSamuraiGorohTex) },
    { 0 }
};

// MIGHTY GAZELLE
unk_80077D50 sCreditsPortraitMightyGazelleCompTexInfo[] = {
    { 17, aFullPortraitMightyGazelleTex, TEX_WIDTH(aFullPortraitMightyGazelleTex),
      TEX_HEIGHT(aFullPortraitMightyGazelleTex), TEX_COMPRESSED_SIZE(aFullPortraitMightyGazelleTex) },
    { 0 }
};

// PICO
unk_80077D50 sCreditsPortraitPicoCompTexInfo[] = { { 17, aFullPortraitPicoTex, TEX_WIDTH(aFullPortraitPicoTex),
                                                     TEX_HEIGHT(aFullPortraitPicoTex),
                                                     TEX_COMPRESSED_SIZE(aFullPortraitPicoTex) },
                                                   { 0 } };

// BABA
unk_80077D50 sCreditsPortraitBabaCompTexInfo[] = { { 17, aFullPortraitBabaTex, TEX_WIDTH(aFullPortraitBabaTex),
                                                     TEX_HEIGHT(aFullPortraitBabaTex),
                                                     TEX_COMPRESSED_SIZE(aFullPortraitBabaTex) },
                                                   { 0 } };

// MR EAD
unk_80077D50 sCreditsPortraitMrEadCompTexInfo[] = { { 17, aFullPortraitMrEadTex, TEX_WIDTH(aFullPortraitMrEadTex),
                                                      TEX_HEIGHT(aFullPortraitMrEadTex),
                                                      TEX_COMPRESSED_SIZE(aFullPortraitMrEadTex) },
                                                    { 0 } };

// OCTOMAN
unk_80077D50 sCreditsPortraitOctomanCompTexInfo[] = { { 17, aFullPortraitOctomanTex, TEX_WIDTH(aFullPortraitOctomanTex),
                                                        TEX_HEIGHT(aFullPortraitOctomanTex),
                                                        TEX_COMPRESSED_SIZE(aFullPortraitOctomanTex) },
                                                      { 0 } };

// THE SKULL
unk_80077D50 sCreditsPortraitTheSkullCompTexInfo[] = {
    { 17, aFullPortraitTheSkullTex, TEX_WIDTH(aFullPortraitTheSkullTex), TEX_HEIGHT(aFullPortraitTheSkullTex),
      TEX_COMPRESSED_SIZE(aFullPortraitTheSkullTex) },
    { 0 }
};

// BEASTMAN
unk_80077D50 sCreditsPortraitBeastmanCompTexInfo[] = {
    { 17, aFullPortraitBeastmanTex, TEX_WIDTH(aFullPortraitBeastmanTex), TEX_HEIGHT(aFullPortraitBeastmanTex),
      TEX_COMPRESSED_SIZE(aFullPortraitBeastmanTex) },
    { 0 }
};

// ANTONIO GUSTER
unk_80077D50 sCreditsPortraitAntonioGusterCompTexInfo[] = {
    { 17, aFullPortraitAntonioGusterTex, TEX_WIDTH(aFullPortraitAntonioGusterTex),
      TEX_HEIGHT(aFullPortraitAntonioGusterTex), TEX_COMPRESSED_SIZE(aFullPortraitAntonioGusterTex) },
    { 0 }
};

// DRAQ
unk_80077D50 sCreditsPortraitDraqCompTexInfo[] = { { 17, aFullPortraitDraqTex, TEX_WIDTH(aFullPortraitDraqTex),
                                                     TEX_HEIGHT(aFullPortraitDraqTex),
                                                     TEX_COMPRESSED_SIZE(aFullPortraitDraqTex) },
                                                   { 0 } };

// ROGER BUSTER
unk_80077D50 sCreditsPortraitRogerBusterCompTexInfo[] = {
    { 17, aFullPortraitRogerBusterTex, TEX_WIDTH(aFullPortraitRogerBusterTex), TEX_HEIGHT(aFullPortraitRogerBusterTex),
      TEX_COMPRESSED_SIZE(aFullPortraitRogerBusterTex) },
    { 0 }
};

// SILVER NEEISEN
unk_80077D50 sCreditsPortraitSilverNeelsenCompTexInfo[] = {
    { 17, aFullPortraitSilverNeelsenTex, TEX_WIDTH(aFullPortraitSilverNeelsenTex),
      TEX_HEIGHT(aFullPortraitSilverNeelsenTex), TEX_COMPRESSED_SIZE(aFullPortraitSilverNeelsenTex) },
    { 0 }
};

// SUPER ARROW
unk_80077D50 sCreditsPortraitSuperArrowCompTexInfo[] = {
    { 17, aFullPortraitSuperArrowTex, TEX_WIDTH(aFullPortraitSuperArrowTex), TEX_HEIGHT(aFullPortraitSuperArrowTex),
      TEX_COMPRESSED_SIZE(aFullPortraitSuperArrowTex) },
    { 0 }
};

// MRS ARROW
unk_80077D50 sCreditsPortraitMrsArrowCompTexInfo[] = {
    { 17, aFullPortraitMrsArrowTex, TEX_WIDTH(aFullPortraitMrsArrowTex), TEX_HEIGHT(aFullPortraitMrsArrowTex),
      TEX_COMPRESSED_SIZE(aFullPortraitMrsArrowTex) },
    { 0 }
};

// ZODA
unk_80077D50 sCreditsPortraitZodaCompTexInfo[] = { { 17, aFullPortraitZodaTex, TEX_WIDTH(aFullPortraitZodaTex),
                                                     TEX_HEIGHT(aFullPortraitZodaTex),
                                                     TEX_COMPRESSED_SIZE(aFullPortraitZodaTex) },
                                                   { 0 } };

// JOHN TANAKA
unk_80077D50 sCreditsPortraitJohnTanakaCompTexInfo[] = {
    { 17, aFullPortraitJohnTanakaTex, TEX_WIDTH(aFullPortraitJohnTanakaTex), TEX_HEIGHT(aFullPortraitJohnTanakaTex),
      TEX_COMPRESSED_SIZE(aFullPortraitJohnTanakaTex) },
    { 0 }
};

// BIO REX
unk_80077D50 sCreditsPortraitBioRexCompTexInfo[] = { { 17, aFullPortraitBioRexTex, TEX_WIDTH(aFullPortraitBioRexTex),
                                                       TEX_HEIGHT(aFullPortraitBioRexTex),
                                                       TEX_COMPRESSED_SIZE(aFullPortraitBioRexTex) },
                                                     { 0 } };

// KATE ALEN
unk_80077D50 sCreditsPortraitKateAlenCompTexInfo[] = {
    { 17, aFullPortraitKateAlenTex, TEX_WIDTH(aFullPortraitKateAlenTex), TEX_HEIGHT(aFullPortraitKateAlenTex),
      TEX_COMPRESSED_SIZE(aFullPortraitKateAlenTex) },
    { 0 }
};

// GOMAR & SHIOH
unk_80077D50 sCreditsPortraitGomarAndShiohCompTexInfo[] = {
    { 17, aFullPortraitGomarAndShiohTex, TEX_WIDTH(aFullPortraitGomarAndShiohTex),
      TEX_HEIGHT(aFullPortraitGomarAndShiohTex), TEX_COMPRESSED_SIZE(aFullPortraitGomarAndShiohTex) },
    { 0 }
};

// MICHAEL CHAIN
unk_80077D50 sCreditsPortraitMichaelChainCompTexInfo[] = {
    { 17, aFullPortraitMichaelChainTex, TEX_WIDTH(aFullPortraitMichaelChainTex),
      TEX_HEIGHT(aFullPortraitMichaelChainTex), TEX_COMPRESSED_SIZE(aFullPortraitMichaelChainTex) },
    { 0 }
};

// BILLY
unk_80077D50 sCreditsPortraitBillyCompTexInfo[] = { { 17, aFullPortraitBillyTex, TEX_WIDTH(aFullPortraitBillyTex),
                                                      TEX_HEIGHT(aFullPortraitBillyTex),
                                                      TEX_COMPRESSED_SIZE(aFullPortraitBillyTex) },
                                                    { 0 } };

// DR CLASH
unk_80077D50 sCreditsPortraitDrClashCompTexInfo[] = { { 17, aFullPortraitDrClashTex, TEX_WIDTH(aFullPortraitDrClashTex),
                                                        TEX_HEIGHT(aFullPortraitDrClashTex),
                                                        TEX_COMPRESSED_SIZE(aFullPortraitDrClashTex) },
                                                      { 0 } };

// JACK LEVIN
unk_80077D50 sCreditsPortraitJackLevinCompTexInfo[] = {
    { 17, aFullPortraitJackLevinTex, TEX_WIDTH(aFullPortraitJackLevinTex), TEX_HEIGHT(aFullPortraitJackLevinTex),
      TEX_COMPRESSED_SIZE(aFullPortraitJackLevinTex) },
    { 0 }
};

// BLOOD FALCON
unk_80077D50 sCreditsPortraitBloodFalconCompTexInfo[] = {
    { 17, aFullPortraitBloodFalconTex, TEX_WIDTH(aFullPortraitBloodFalconTex), TEX_HEIGHT(aFullPortraitBloodFalconTex),
      TEX_COMPRESSED_SIZE(aFullPortraitBloodFalconTex) },
    { 0 }
};

// LEON
unk_80077D50 sCreditsPortraitLeonCompTexInfo[] = { { 17, aFullPortraitLeonTex, TEX_WIDTH(aFullPortraitLeonTex),
                                                     TEX_HEIGHT(aFullPortraitLeonTex),
                                                     TEX_COMPRESSED_SIZE(aFullPortraitLeonTex) },
                                                   { 0 } };

// JAMES MCCLOUD
unk_80077D50 sCreditsPortraitJamesMcCloudCompTexInfo[] = {
    { 17, aFullPortraitJamesMcCloudTex, TEX_WIDTH(aFullPortraitJamesMcCloudTex),
      TEX_HEIGHT(aFullPortraitJamesMcCloudTex), TEX_COMPRESSED_SIZE(aFullPortraitJamesMcCloudTex) },
    { 0 }
};

// BLACK SHADOW
unk_80077D50 sCreditsPortraitBlackShadowCompTexInfo[] = {
    { 17, aFullPortraitBlackShadowTex, TEX_WIDTH(aFullPortraitBlackShadowTex), TEX_HEIGHT(aFullPortraitBlackShadowTex),
      TEX_COMPRESSED_SIZE(aFullPortraitBlackShadowTex) },
    { 0 }
};

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

const s16 kCreditsMachinePositions[] = { 150, 210, 50, 35, 50, 210, 150, 35 };

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

void Credits_OldMachinesInit(Object* oldMachinesObj) {

    OBJECT_CACHE_INDEX(oldMachinesObj) = func_800792D8(D_i6_8011E558[0]);

    OBJECT_STATE(oldMachinesObj) = 0;

    //! @bug the case where func_800792D8 returns -1 is unhandled
    D_800E3F28[OBJECT_CACHE_INDEX(oldMachinesObj)].unk_04 = -1;
}

void Credits_MachinesInit(Object* machinesObj) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_i6_8011FAF0); i++) {
        D_i6_8011FAF0[i] = 0;
    }
    OBJECT_CACHE_INDEX(machinesObj) = func_800792D8(D_i6_8011E558[0]);

    //! @bug the case where func_800792D8 returns -1 is unhandled
    D_800E3F28[OBJECT_CACHE_INDEX(machinesObj)].unk_04 = -1;
}

void Credits_MenuLadyInit(Object* menuLadyObj) {
    func_80077D50(sCreditsMenuLadyCompTexInfo, 0);
    OBJECT_COUNTER(menuLadyObj) = 0xB6;
}

void Credits_SeeYouAgainInit(void) {
    func_80077D50(sCreditsSeeYouAgainCompTexInfo, 0);
}

void Credits_IntroInit(Object* introObj) {
    func_80077D50(sCreditsMrZeroCompTexInfo, 0);
    OBJECT_COUNTER(introObj) = 0x100;
    INTRO_TIMER(introObj) = 0;
}

void Credits_CopyrightInit(void) {
    func_80077D50(sCreditsCopyrightCompTexInfo, 0);
}

void Credits_PortraitsInit(Object* portraitsObj) {

    OBJECT_CACHE_INDEX(portraitsObj) = func_800792D8(D_i6_8011EBF8[0]);

    D_800E3F28[OBJECT_CACHE_INDEX(portraitsObj)].unk_04 = -1;
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

    left = OBJECT_LEFT(startNameObj) - i;
    top = OBJECT_TOP(startNameObj);

    letterCount = OBJECT_COUNTER(startNameObj) / 5;
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
        letterCompletion = OBJECT_COUNTER(startNameObj) - (i * 5);
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

Gfx* Credits_OldMachinesDraw(Gfx* gfx, Object* oldMachinesObj) {

    if (!sDebugCreditsOldMachines) {
        return gfx;
    }

    return func_80078F80(gfx, &D_800E3F28[OBJECT_CACHE_INDEX(oldMachinesObj)], OBJECT_LEFT(oldMachinesObj),
                         OBJECT_TOP(oldMachinesObj), 0, 0, 0, 1.0f, 1.0f);
}

#define UNK_RAND_MACRO(var, x, y) (((Math_Rand1() >> (var % 4)) % x) - y)

Gfx* Credits_MachinesDraw(Gfx* gfx, Object* machinesObj) {
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

    temp_s1 = &D_800E3F28[OBJECT_CACHE_INDEX(machinesObj)];

    left = OBJECT_LEFT(machinesObj);
    top = OBJECT_TOP(machinesObj);

    if (OBJECT_TOP(machinesObj) > 120) {
        top = OBJECT_TOP(machinesObj) - temp_s1->unk_00->unk_00->height;
    }

    sp154 = OBJECT_COUNTER(machinesObj);
    if (sp154 > 64) {
        sp154 = 64;
    }

    width = temp_s1->unk_00->unk_00->width;
    height = temp_s1->unk_00->unk_00->height;

    switch (OBJECT_STATE2(machinesObj)) {
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
            gfx = func_80078F80(gfx, temp_s1, OBJECT_LEFT(machinesObj), top, 0, 0, 0, 1.0f, 1.0f);
            break;
        case 2:
            if (sp154 < 5) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, ((64 - sp154) * 255) / 64);

                var_fv1 = (64 - (sp154 * 2)) / 64.0f;
                additionalWidth = (width * (1.0f - var_fv1)) / 2;
                additionalHeight = (height * (1.0f - var_fv1)) / 2;

                gfx = func_80078F80(gfx, temp_s1, OBJECT_LEFT(machinesObj) + additionalWidth, top + additionalHeight, 4,
                                    0, 0, var_fv1, var_fv1);
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
    s32 left;
    s32 top;
    s32 alpha;
    s32 var_t5;
    TexturePtr texture;

    texture = func_800783AC(aCreditsMenuLadyTex);
    left = OBJECT_LEFT(menuLadyObj);
    top = OBJECT_TOP(menuLadyObj);

    gSPDisplayList(gfx++, D_3000088);

    for (row = 0; row < 182; row++) {
        var_t5 = 0;

        switch (OBJECT_STATE(menuLadyObj)) {
            case 0:
                alpha = row - OBJECT_COUNTER(menuLadyObj);
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
                var_a0 = OBJECT_COUNTER(menuLadyObj) - 23;
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
                if (MENU_LADY_DITHER_SCALE(menuLadyObj) != 0) {
                    var_a0 = UNK_RAND_MACRO(row, 7, 3);
                    var_t5 = ((32 - MENU_LADY_DITHER_SCALE(menuLadyObj)) * var_a0) / 32;
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
        gSPScisTextureRectangle(gfx++, (left + var_t5) << 2, (top + row) << 2, (left + var_t5 + 80) << 2,
                                (top + row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gSPScisTextureRectangle(gfx++, ((SCREEN_WIDTH - 80 - left) + var_t5) << 2, (top + row) << 2,
                                ((SCREEN_WIDTH - left) + var_t5) << 2, (top + row + 1) << 2, 0, 0x9E0, 0, 0xFC00,
                                1 << 10);
    }

    MENU_LADY_DITHER_SCALE(menuLadyObj) = 0;

    return gfx;
}

Gfx* Credits_SeeYouAgainDraw(Gfx* gfx, Object* seeYouAgainObj) {
    s32 row;
    s32 sp50;
    s32 alpha;
    s32 var_s2;
    s32 var_s5;
    TexturePtr texture;

    OBJECT_COUNTER(seeYouAgainObj)++;
    texture = func_800783AC(aCreditsSeeYouAgainTex);
    sp50 = OBJECT_LEFT(seeYouAgainObj);
    var_s5 = OBJECT_TOP(seeYouAgainObj);

    gSPDisplayList(gfx++, D_3000088);

    if (OBJECT_STATE(seeYouAgainObj) == 1) {
        gDPSetAlphaCompare(gfx++, G_AC_DITHER);
    }

    for (row = 0; row < 64; row++) {
        switch (OBJECT_STATE(seeYouAgainObj)) {
            case 0:
                var_s2 = UNK_RAND_MACRO(row, 11, 5);
                if (OBJECT_COUNTER(seeYouAgainObj) < 64) {
                    var_s2 = (s32) ((64 - OBJECT_COUNTER(seeYouAgainObj)) * var_s2) / 64;
                } else {
                    var_s2 = 0;
                }
                if (OBJECT_COUNTER(seeYouAgainObj) < 6) {
                    alpha = OBJECT_COUNTER(seeYouAgainObj) * 50;
                } else {
                    alpha = 255;
                }
                break;
            case 1:

                var_s2 = UNK_RAND_MACRO(row, 7, 3);

                if (OBJECT_COUNTER(seeYouAgainObj) < 32) {
                    var_s2 = ((32 - OBJECT_COUNTER(seeYouAgainObj)) * var_s2) / 32;
                    MENU_LADY_DITHER_SCALE(Object_Get(OBJECT_CREDITS_MENU_LADY)) = OBJECT_COUNTER(seeYouAgainObj);
                } else {
                    var_s2 = 0;
                }
                if (OBJECT_COUNTER(seeYouAgainObj) < 20) {
                    if (OBJECT_COUNTER(seeYouAgainObj) < 10) {
                        alpha = 255 - (OBJECT_COUNTER(seeYouAgainObj) * 10);
                    } else {
                        alpha = (OBJECT_COUNTER(seeYouAgainObj) * 10) + 55;
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

        if (OBJECT_STATE2(introObj) != 0) {
            temp_a0 = OBJECT_COUNTER2(introObj);
            var_t2 = 255 - temp_a0;
            temp = ((((row * 0x1000) * (temp_a0 + 64)) / 64) / 72);
            temp_t1 = ((SIN(temp) * (temp_a0 + 4)) / 4);
            temp = (200 - temp_t1);

            gDPSetPrimColor(gfx++, 0, 0, var_t2, var_t2, var_t2, var_t2);
            gSPScisTextureRectangle(gfx++, temp << 2, (row + var) << 2, (temp + 80) << 2, (row + var + 1) << 2, 0, 0, 0,
                                    1 << 10, 1 << 10);
        }
        if (OBJECT_STATE(introObj) != 0) {
            temp_a0 = OBJECT_COUNTER(introObj);
            var_t2 = 255 - temp_a0;
            temp = ((((row * 0x1000) * (temp_a0 + 64)) / 64) / 72);
            temp_t1 = ((SIN(temp) * (temp_a0 + 4)) / 4);
            gDPSetPrimColor(gfx++, 0, 0, var_t2, var_t2, var_t2, var_t2);
            gSPScisTextureRectangle(gfx++, (temp_t1 + 40) << 2, (row + var) << 2, ((temp_t1 + 40) + 80) << 2,
                                    (row + var + 1) << 2, 0, (80 - 1) * (1 << 5), 0, (64 - 1) * (1 << 10), 1 << 10);
        }
    }

    if (INTRO_TIMER(introObj) > 290) {
        var_t2 = 0xA10 - (INTRO_TIMER(introObj) * 8);
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
    } else if (INTRO_TIMER(introObj) > 120) {
        var_t2 = (INTRO_TIMER(introObj) * 3) - 0x168;
        if (var_t2 > 255) {
            var_t2 = 255;
        }

        scale = (f32) (628 - (INTRO_TIMER(introObj) * 2)) / 192.0f;

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
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/overlays/ovl_i6/credits/Credits_IntroDraw.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i6/credits/Credits_IntroDraw.s")
#endif
#endif

Gfx* Credits_CopyrightDraw(Gfx* gfx, Object* copyRightObj) {
    s32 var_s2;
    s32 temp_s7;
    s32 var_a2;
    s32 row;
    TexturePtr texture;

    OBJECT_COUNTER(copyRightObj)++;
    texture = func_800783AC(aCopyrightTex);
    var_s2 = OBJECT_TOP(copyRightObj);
    temp_s7 = OBJECT_LEFT(copyRightObj);
    gSPDisplayList(gfx++, D_3000088);

    for (row = 0; row < 14; row++) {
        var_a2 = UNK_RAND_MACRO(row, 11, 5);
        if (OBJECT_COUNTER(copyRightObj) < 32) {
            var_a2 = ((32 - OBJECT_COUNTER(copyRightObj)) * var_a2) / 32;
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
    s32 left;
    s32 machineLeftPos;

    sp34 = &D_800E3F28[OBJECT_CACHE_INDEX(portraitsObj)];
    temp_v1 = OBJECT_COUNTER(portraitsObj);
    machineLeftPos = kCreditsMachinePositions[(PORTRAIT_MACHINE_INDEX(portraitsObj) % 4) * 2];

    if (machineLeftPos < 100) {
        left = SCREEN_WIDTH - (temp_v1 / 1.2);
    } else {
        left = (temp_v1 / 1.2) - 180;
    }

    if (OBJECT_STATE2(portraitsObj) == 0) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255 - temp_v1);
        gfx = func_80078F80(gfx, sp34, left, -5, 1, 0, 0, 1.0f, 1.0f);
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
            gfx = Font_DrawString(gfx, OBJECT_LEFT(startRolesObj) + 1, OBJECT_TOP(startRolesObj) + 1, roleName, 0,
                                  FONT_SET_6, 0);
            break;
        case 1:
        case 2:
            gfx = Font_DrawString(gfx, (OBJECT_LEFT(startRolesObj) - Font_GetStringWidth(roleName, FONT_SET_6, 0)) + 1,
                                  OBJECT_TOP(startRolesObj) + 1, roleName, 0, FONT_SET_6, 0);
            break;
    }

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    switch (roleIndex % 4) {
        case 0:
        case 3:
            gfx =
                Font_DrawString(gfx, OBJECT_LEFT(startRolesObj), OBJECT_TOP(startRolesObj), roleName, 0, FONT_SET_6, 0);
            break;
        case 1:
        case 2:
            gfx = Font_DrawString(gfx, OBJECT_LEFT(startRolesObj) - Font_GetStringWidth(roleName, FONT_SET_6, 0),
                                  OBJECT_TOP(startRolesObj), roleName, 0, FONT_SET_6, 0);
            break;
    }

    return gfx;
}

Gfx* Credits_EndRolesDraw(Gfx* gfx, Object* endRolesObj) {
    char* roleName;
    s32 roleIndex = endRolesObj->cmdId - OBJECT_CREDITS_ROLE_0;

    roleName = gCreditsAttributions[roleIndex];

    gDPSetPrimColor(gfx++, 0, 0, 24, 24, 24, 255);
    gfx = Font_DrawString(gfx, OBJECT_LEFT(endRolesObj) + 1, OBJECT_TOP(endRolesObj) + 1, roleName, 0, FONT_SET_6, 0);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = Font_DrawString(gfx, OBJECT_LEFT(endRolesObj), OBJECT_TOP(endRolesObj), roleName, 0, FONT_SET_6, 0);

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

    switch (OBJECT_STATE(startNameObj)) {
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
                OBJECT_STATE(startNameObj) = 1;
            }
            break;
        case 1:
        case 2:
            switch (temp_v1 % 4) {
                case 0:
                case 3:
                    gfx = Font_DrawString(gfx, OBJECT_LEFT(startNameObj), OBJECT_TOP(startNameObj), temp_a3, 0,
                                          FONT_SET_1, 0);
                    break;
                case 1:
                case 2:
                    gfx = Font_DrawString(gfx, OBJECT_LEFT(startNameObj) - Font_GetStringWidth(temp_a3, FONT_SET_1, 0),
                                          OBJECT_TOP(startNameObj), temp_a3, 0, FONT_SET_1, 0);
                    break;
            }
            break;
    }
    return gfx;
}

Gfx* Credits_EndNameDraw(Gfx* gfx, Object* endNamesObj) {
    s32 index = endNamesObj->cmdId - OBJECT_CREDITS_NAME_0;
    char* temp = gCreditsNames[index];

    return Font_DrawString(gfx, OBJECT_LEFT(endNamesObj), OBJECT_TOP(endNamesObj), temp, 0, FONT_SET_1, 0);
}

extern u16 gInputPressed;

void Credits_OldMachinesUpdate(Object* oldMachinesObj) {
    s32 var_v1;
    unk_800E3F28* temp_v0;

    temp_v0 = &D_800E3F28[OBJECT_CACHE_INDEX(oldMachinesObj)];
    var_v1 = 0;
    if (temp_v0->unk_04 == -1) {
        temp_v0->unk_04 = 0;
        OBJECT_STATE(oldMachinesObj) = 0;
        var_v1 = 1;
    }
    if (sDebugCreditsOldMachines) {
        if (gInputPressed & BTN_LEFT) {
            func_800BA8D8(30);
            if (OBJECT_STATE(oldMachinesObj) != 0) {
                OBJECT_STATE(oldMachinesObj)--;
            } else {
                OBJECT_STATE(oldMachinesObj) = 29;
            }
            var_v1++;
        }

        if (gInputPressed & BTN_RIGHT) {
            func_800BA8D8(30);
            OBJECT_STATE(oldMachinesObj)++;
            OBJECT_STATE(oldMachinesObj) = OBJECT_STATE(oldMachinesObj) % 30;
            var_v1++;
        }
    }
    if (var_v1 != 0) {
        func_800793E8(OBJECT_CACHE_INDEX(oldMachinesObj), 0, D_i6_8011E560[OBJECT_STATE(oldMachinesObj)]);
    }
}

void Credits_MachinesUpdate(Object* machinesObj) {
    Object* scriptObj;
    s32 var_a2;
    s32 var_v1;
    Object* portraitsObj;

    var_a2 = 0;

    OBJECT_LEFT(machinesObj) = kCreditsMachinePositions[(MACHINE_INDEX(machinesObj) % 4) * 2 + 0];
    OBJECT_TOP(machinesObj) = kCreditsMachinePositions[(MACHINE_INDEX(machinesObj) % 4) * 2 + 1];
    switch (OBJECT_STATE2(machinesObj)) {
        case 0:
            if (++OBJECT_COUNTER(machinesObj) >= 64) {
                OBJECT_STATE2(machinesObj) = 1;
            }
            break;
        case 1:
            OBJECT_COUNTER(machinesObj) = 0;
            break;
        case 2:
            if (++OBJECT_COUNTER(machinesObj) >= 64) {
                OBJECT_STATE2(machinesObj) = 3;
                OBJECT_COUNTER(machinesObj) = 0;
                scriptObj = Object_Get(OBJECT_CREDITS_SCRIPT);
                var_a2 = 0;
                if (scriptObj != NULL) {
                    OBJECT_STATE2(scriptObj) = 2;
                }
            }
            break;
        case 3:
            if (OBJECT_COUNTER(machinesObj) != 0) {
                OBJECT_STATE2(machinesObj) = 0;
                MACHINE_INDEX(machinesObj)++;
                var_v1 = 0;
                if ((MACHINE_INDEX(machinesObj) == 5) && (D_i6_8011FAF0[9] == 0)) {
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
                OBJECT_STATE(machinesObj) = var_a2;
                var_a2 = 1;
                portraitsObj = Object_Get(OBJECT_CREDITS_PORTRAITS);
                if ((portraitsObj != NULL) && (OBJECT_STATE2(portraitsObj) == 3)) {
                    OBJECT_COUNTER(portraitsObj) = 1;
                }
            }
            break;
    }

    if (D_800E3F28[OBJECT_CACHE_INDEX(machinesObj)].unk_04 == -1) {
        D_800E3F28[OBJECT_CACHE_INDEX(machinesObj)].unk_04 = 0;
        OBJECT_STATE(machinesObj) = Math_Rand1() % 30;
        D_i6_8011FAF0[OBJECT_STATE(machinesObj)] = 1;
        var_a2++;
    }
    if (var_a2 != 0) {
        func_800793E8(OBJECT_CACHE_INDEX(machinesObj), 0, D_i6_8011E560[OBJECT_STATE(machinesObj)]);
    }
}

void Credits_PortraitsUpdate(Object* portraitsObj) {
    s32 pad;
    s32 var_v1 = 0;

    switch (OBJECT_STATE2(portraitsObj)) {
        case 0:
            if (++OBJECT_COUNTER(portraitsObj) >= 255) {
                OBJECT_COUNTER(portraitsObj) = 0;
                OBJECT_STATE2(portraitsObj) = 3;
            }
            break;
        case 3:
            if (OBJECT_COUNTER(portraitsObj) != 0) {
                OBJECT_STATE2(portraitsObj) = 0;
                PORTRAIT_MACHINE_INDEX(portraitsObj)++;
                OBJECT_STATE(portraitsObj) = OBJECT_STATE(Object_Get(OBJECT_CREDITS_MACHINES));
                var_v1 = 1;
                OBJECT_COUNTER(portraitsObj) = 0;
            }
            break;
    }

    if (D_800E3F28[OBJECT_CACHE_INDEX(portraitsObj)].unk_04 == -1) {
        D_800E3F28[OBJECT_CACHE_INDEX(portraitsObj)].unk_04 = 0;
        OBJECT_STATE(portraitsObj) = OBJECT_STATE(Object_Get(OBJECT_CREDITS_MACHINES));
        var_v1++;
    }
    if (var_v1 != 0) {
        func_800793E8(OBJECT_CACHE_INDEX(portraitsObj), 0, D_i6_8011EBF8[OBJECT_STATE(portraitsObj)]);
    }
}

bool Object_MovePosXAndCheckTarget(Object* object, s32 step, s32 target) {

    OBJECT_LEFT(object) += step;
    if (step < 0) {
        if (target >= OBJECT_LEFT(object)) {
            return true;
        }
    } else {
        if (OBJECT_LEFT(object) >= target) {
            return true;
        }
    }
    return false;
}

bool Object_MovePosYAndCheckTarget(Object* object, s32 step, s32 target) {

    OBJECT_TOP(object) += step;
    if (step < 0) {
        if (target >= OBJECT_TOP(object)) {
            return true;
        }
    } else {
        if (OBJECT_TOP(object) >= target) {
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

    OBJECT_TOP(object) += step;
    if (step < 0) {
        if (target >= OBJECT_TOP(object)) {
            return true;
        }
    } else {
        if (OBJECT_TOP(object) >= target) {
            return true;
        }
    }
    return false;
}

void Credits_ObjectInit(s32 cmdId, s32 left, s32 top, s8 priority);

void Credits_ScriptUpdate(Object* scriptObj) {
    s32 objId;
    s32 index;
    Object* machinesObj;

    OBJECT_COUNTER(scriptObj)++;
    if (OBJECT_STATE(scriptObj) < 18) {
        switch (OBJECT_STATE2(scriptObj)) {
            case 0:
                switch (OBJECT_COUNTER(scriptObj)) {
                    case 1:
                        Credits_ObjectInit(OBJECT_CREDITS_ROLE_0 + OBJECT_STATE(scriptObj),
                                           kStartRolesInitialPositions[(OBJECT_STATE(scriptObj) % 4) * 2 + 0],
                                           kStartRolesInitialPositions[(OBJECT_STATE(scriptObj) % 4) * 2 + 1], 12);
                        machinesObj = Object_Get(OBJECT_CREDITS_MACHINES);
                        if ((machinesObj != NULL) && (OBJECT_STATE2(machinesObj) == 3)) {
                            OBJECT_COUNTER(machinesObj)++;
                        }
                        break;
                    case 60:
                        Credits_ObjectInit(OBJECT_CREDITS_NAME_0 + OBJECT_STATE(scriptObj),
                                           kStartNamesInitialPositions[(OBJECT_STATE(scriptObj) % 4) * 2 + 0],
                                           kStartNamesInitialPositions[(OBJECT_STATE(scriptObj) % 4) * 2 + 1], 10);
                        OBJECT_STATE2(scriptObj) = 1;
                        break;
                }
                break;
            case 1:
                OBJECT_COUNTER(scriptObj) = 0;
                break;
            case 2:
                if (OBJECT_COUNTER(scriptObj) > 30) {
                    OBJECT_STATE(scriptObj)++;
                    OBJECT_STATE2(scriptObj) = 0;
                    OBJECT_COUNTER(scriptObj) = 0;
                }
                break;
        }
    } else {
        switch (OBJECT_STATE(scriptObj)) {
            case 18:
                if ((OBJECT_COUNTER(scriptObj) % 15) == 0) {
                    index = OBJECT_COUNTER(scriptObj) / 15;
                    objId = kCreditsObjectScrollScript[index - 1];
                    if (objId > 0) {
                        Credits_ObjectInit(objId, 50, 240, 10);
                    } else if (objId < 0) {
                        OBJECT_STATE(scriptObj)++;
                    }
                }
                break;
            case 19:
                if (Object_Get(OBJECT_CREDITS_NAME_30) == NULL) {
                    OBJECT_STATE(scriptObj)++;
                }
                break;
            case 20:
                Credits_ObjectInit(OBJECT_CREDITS_MENU_LADY, 200, 30, 8);
                OBJECT_STATE(scriptObj)++;
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
    s32 initialStep;
    s32 targetTop;
    s32 step;
    char* roleName;
    Object* machinesObj;

    roleIndex = startRoleObj->cmdId - OBJECT_CREDITS_ROLE_0;
    roleName = gCreditsAttributions[roleIndex];

    switch (roleIndex % 4) {
        case 0:
        case 3:
            initialStep = -1;
            break;
        case 1:
        case 2:
            initialStep = 1;
            break;
    }

    if (roleIndex % 2) {
        targetTop = 150;
        step = 1;
    } else {
        targetTop = 70;
        step = -1;
    }

    switch (OBJECT_STATE(startRoleObj)) {
        case 0:
            if (Object_MovePosYAndCheckTarget(startRoleObj, step, targetTop)) {
                OBJECT_STATE(startRoleObj) = 1;
                OBJECT_COUNTER(startRoleObj) = 0;
            }
            break;
        case 1:
            if (++OBJECT_COUNTER(startRoleObj) > 120) {
                OBJECT_STATE(startRoleObj) = 2;
                machinesObj = Object_Get(OBJECT_CREDITS_MACHINES);
                if ((machinesObj != NULL) && (OBJECT_STATE2(machinesObj) == 1)) {
                    OBJECT_STATE2(machinesObj) = 2;
                }
            }
            break;
        case 2:
            Object_LerpAwayFromPosX(startRoleObj, kStartRolesInitialPositions[(roleIndex % 4) * 2], initialStep);
            if (initialStep < 0) {
                if (OBJECT_LEFT(startRoleObj) < -Font_GetStringWidth(roleName, FONT_SET_1, 0)) {
                    startRoleObj->cmdId = OBJECT_FREE;
                }
            } else {
                if ((Font_GetStringWidth(roleName, FONT_SET_1, 0) + SCREEN_WIDTH) < OBJECT_LEFT(startRoleObj)) {
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

    switch (OBJECT_STATE(startNameObj)) {
        case 0:
            OBJECT_COUNTER(startNameObj)++;
            break;
        case 1:
            if (OBJECT_STATE(Object_Get(OBJECT_CREDITS_ROLE_0 + nameIndex)) >= 2) {
                OBJECT_STATE(startNameObj) = 2;
            }
            break;
        case 2:
            Object_LerpAwayFromPosX(startNameObj, kStartNamesInitialPositions[(nameIndex % 4) * 2], initialStep);
            if (initialStep > 0) {
                if (OBJECT_LEFT(startNameObj) > SCREEN_WIDTH) {
                    startNameObj->cmdId = OBJECT_FREE;
                }
            } else {
                if (OBJECT_LEFT(startNameObj) < 0) {
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

    switch (OBJECT_STATE(menuLadyObj)) {
        case 0:
            if (--OBJECT_COUNTER(menuLadyObj) < 24) {
                OBJECT_STATE(menuLadyObj)++;
                OBJECT_COUNTER(menuLadyObj) = 0;
            }
            break;
        case 1:
            if (++OBJECT_COUNTER(menuLadyObj) >= 60) {
                OBJECT_STATE(menuLadyObj)++;
                OBJECT_COUNTER(menuLadyObj) = 23;
            }
            break;
        case 2:
            OBJECT_COUNTER(menuLadyObj) += OBJECT_COUNTER(menuLadyObj) / 11;
            if (OBJECT_COUNTER(menuLadyObj) >= 182) {
                OBJECT_STATE(menuLadyObj)++;
                OBJECT_COUNTER(menuLadyObj) = 0;
            }
            break;
        case 3:
            if (++OBJECT_COUNTER(menuLadyObj) >= 18) {
                OBJECT_STATE(menuLadyObj)++;
                OBJECT_COUNTER(menuLadyObj) = 0;
                Credits_ObjectInit(OBJECT_CREDITS_SEE_YOU_AGAIN, 0x80, 0x40, 8);
                func_800BA8D8(0x2B);
            }
            break;
        case 4:
            break;
    }
}

void Credits_SeeYouAgainUpdate(Object* seeYouAgainObj) {

    switch (OBJECT_STATE(seeYouAgainObj)) {
        case 0:
            if (++OBJECT_COUNTER(seeYouAgainObj) >= 175) {
                OBJECT_STATE(seeYouAgainObj)++;
                OBJECT_COUNTER(seeYouAgainObj) = 0;
                Credits_ObjectInit(OBJECT_CREDITS_COPYRIGHT, 0x60, 0xCD, 8);
            }
            break;
        case 1:
            if (++OBJECT_COUNTER(seeYouAgainObj) >= 100) {
                OBJECT_STATE(seeYouAgainObj)++;
                OBJECT_COUNTER(seeYouAgainObj) = 0;
            }
            break;
        case 2:
            break;
    }
}

void Credits_IntroUpdate(Object* introObj) {

    switch (++INTRO_TIMER(introObj)) {
        case 30:
            if (OBJECT_STATE(introObj) == 0) {
                OBJECT_STATE(introObj) = 1;
            }
            break;
        case 60:
            if (OBJECT_STATE2(introObj) == 0) {
                OBJECT_STATE2(introObj) = 1;
            }
            break;
        case 370:
            Credits_ObjectInit(OBJECT_CREDITS_SCRIPT, 0, 0, 0);
            Credits_ObjectInit(OBJECT_CREDITS_MACHINES, 0, 0, 4);
            Credits_ObjectInit(OBJECT_CREDITS_PORTRAITS, 0, 0, 8);
            introObj->cmdId = OBJECT_FREE;
            break;
        default:
            if (INTRO_TIMER(introObj) > 300) {
                if (OBJECT_STATE2(introObj) == 2) {
                    OBJECT_STATE2(introObj) = 3;
                }
                if (OBJECT_STATE(introObj) == 2) {
                    OBJECT_STATE(introObj) = 3;
                }
            }
            break;
    }

    switch (OBJECT_STATE(introObj)) {
        case 0:
            OBJECT_COUNTER(introObj) = 256;
            break;
        case 1:
            if (OBJECT_COUNTER(introObj) > 0) {
                OBJECT_COUNTER(introObj) -= 4;
            }
            if (OBJECT_COUNTER(introObj) <= 0) {
                OBJECT_COUNTER(introObj) = 0;
                OBJECT_STATE(introObj) = 2;
            }
            break;
        case 3:
            if (OBJECT_COUNTER(introObj) < 255) {
                OBJECT_COUNTER(introObj) += 4;
            }
            if (OBJECT_COUNTER(introObj) >= 255) {
                OBJECT_COUNTER(introObj) = 255;
                OBJECT_STATE(introObj) = 4;
            }
            break;
        case 4:
            OBJECT_COUNTER(introObj) = 255;
            break;
        default:
            OBJECT_COUNTER(introObj) = 0;
            break;
    }
    switch (OBJECT_STATE2(introObj)) {
        case 0:
            OBJECT_COUNTER2(introObj) = 256;
            break;
        case 1:
            if (OBJECT_COUNTER2(introObj) > 0) {
                OBJECT_COUNTER2(introObj) -= 4;
            }
            if (OBJECT_COUNTER2(introObj) <= 0) {
                OBJECT_COUNTER2(introObj) = 0;
                OBJECT_STATE2(introObj) = 2;
            }
            break;
        case 3:
            if (OBJECT_COUNTER2(introObj) < 255) {
                OBJECT_COUNTER2(introObj) += 4;
            }
            if (OBJECT_COUNTER2(introObj) >= 256) {
                OBJECT_COUNTER2(introObj) = 255;
                OBJECT_STATE2(introObj) = 4;
            }
            break;
        case 4:
            OBJECT_COUNTER2(introObj) = 255;
            break;
        default:
            OBJECT_COUNTER2(introObj) = 0;
            break;
    }
}

void Credits_CopyrightUpdate(Object* copyrightObj) {
}

void Credits_ObjectInit(s32 cmdId, s32 left, s32 top, s8 priority) {
    s32 i = 0;
    Object* object = gObjects;

    while (true) {
        if (object->cmdId == OBJECT_FREE) {
            break;
        }

        if (++i > ARRAY_COUNT(gObjects)) {
            return;
        }
        object++;
    }

    object->cmdId = cmdId;
    object->state = 0;
    object->state2 = 0;
    object->left = left;
    object->top = top;
    object->priority = priority;
    object->shouldDraw = true;
    object->counter = 0;
    object->counter2 = 0;

    switch (cmdId) {
        case OBJECT_CREDITS_MACHINES_OLD:
            Credits_OldMachinesInit(object);
            break;
        case OBJECT_CREDITS_MACHINES:
            Credits_MachinesInit(object);
            break;
        case OBJECT_CREDITS_MENU_LADY:
            Credits_MenuLadyInit(object);
            break;
        case OBJECT_CREDITS_SEE_YOU_AGAIN:
            Credits_SeeYouAgainInit();
            break;
        case OBJECT_CREDITS_INTRO:
            Credits_IntroInit(object);
            break;
        case OBJECT_CREDITS_COPYRIGHT:
            Credits_CopyrightInit();
            break;
        case OBJECT_CREDITS_PORTRAITS:
            Credits_PortraitsInit(object);
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
                case OBJECT_CREDITS_MACHINES_OLD:
                    gfx = Credits_OldMachinesDraw(gfx, &gObjects[j]);
                    break;
                case OBJECT_CREDITS_BACKGROUND:
                    gfx = func_8007AC48(gfx, 0, 0, 0);
                    break;
                case OBJECT_CREDITS_MACHINES:
                    gfx = Credits_MachinesDraw(gfx, &gObjects[j]);
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
            case OBJECT_CREDITS_MACHINES_OLD:
                Credits_OldMachinesUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_SCRIPT:
                Credits_ScriptUpdate(&gObjects[i]);
                break;
            case OBJECT_CREDITS_MACHINES:
                Credits_MachinesUpdate(&gObjects[i]);
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
        sDebugCreditsOldMachines ^= 1;
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
