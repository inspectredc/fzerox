#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "fzx_camera.h"
#include "fzx_font.h"
#include "fzx_cache.h"
#include "src/overlays/ovl_i2/transition.h"
#include "ovl_i4.h"
#include ASSET_HEADER(machine_custom_gfx.h)
#include ASSET_HEADER(machine_models.h)
#include ASSET_HEADER(common_assets_compressed.h)

UNUSED s32 D_8011D770;
static s32 sMachinesUnlocked;
f32 D_i4_8011D778;
f32 D_i4_8011D77C;
static s16 sMachineSelectIndex[8];

#ifdef EXPANSION_KIT
UNUSED s32 D_i4_80074F50 = 0;
#include ASSET_SOURCE_EK(overlays/ovl_i4/machine/machine.c)
#endif

CacheTexInfo sPortraitDrStewartCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitDrStewartTex);
CacheTexInfo sPortraitCaptainFalconCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitCaptainFalconTex);
CacheTexInfo sPortraitJodySummerCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitJodySummerTex);
CacheTexInfo sPortraitSamuraiGorohCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitSamuraiGorohTex);
CacheTexInfo sPortraitMightyGazelleCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitMightyGazelleTex);
CacheTexInfo sPortraitPicoCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitPicoTex);
CacheTexInfo sPortraitBabaCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitBabaTex);
CacheTexInfo sPortraitMrEadCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitMrEadTex);
CacheTexInfo sPortraitOctomanCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitOctomanTex);
CacheTexInfo sPortraitTheSkullCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitTheSkullTex);
CacheTexInfo sPortraitBeastmanCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitBeastmanTex);
CacheTexInfo sPortraitAntonioGusterCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitAntonioGusterTex);
CacheTexInfo sPortraitDraqCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitDraqTex);
CacheTexInfo sPortraitRogerBusterCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitRogerBusterTex);
CacheTexInfo sPortraitSilverNeelsenCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitSilverNeelsenTex);
CacheTexInfo sPortraitSuperArrowCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitSuperArrowTex);
CacheTexInfo sPortraitMrsArrowCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitMrsArrowTex);
CacheTexInfo sPortraitZodaCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitZodaTex);
CacheTexInfo sPortraitJohnTanakaCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitJohnTanakaTex);
CacheTexInfo sPortraitBioRexCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitBioRexTex);
CacheTexInfo sPortraitKateAlenCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitKateAlenTex);
CacheTexInfo sPortraitGomarAndShiohCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitGomarAndShiohTex);
CacheTexInfo sPortraitMichaelChainCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitMichaelChainTex);
CacheTexInfo sPortraitBillyCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitBillyTex);
CacheTexInfo sPortraitDrClashCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitDrClashTex);
CacheTexInfo sPortraitJackLevinCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitJackLevinTex);
CacheTexInfo sPortraitBloodFalconCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitBloodFalconTex);
CacheTexInfo sPortraitLeonCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitLeonTex);
CacheTexInfo sPortraitJamesMcCloudCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitJamesMcCloudTex);
CacheTexInfo sPortraitBlackShadowCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitBlackShadowTex);
CacheTexInfo sPortraitCaptainFalconAltCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitCaptainFalconAltTex);
CacheTexInfo sPortraitSamuraiGorohAltCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitSamuraiGorohAltTex);
CacheTexInfo sPortraitJodySummerAltCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitJodySummerAltTex);
CacheTexInfo sPortraitBackgroundCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aFullPortraitBackgroundTex);

CacheTexInfo* sPortraitCacheTexInfos[] = {
    sPortraitCaptainFalconCacheTexInfo,    // CAPTAIN_FALCON
    sPortraitDrStewartCacheTexInfo,        // DR_STEWART
    sPortraitPicoCacheTexInfo,             // PICO
    sPortraitSamuraiGorohCacheTexInfo,     // SAMURAI_GOROH
    sPortraitJodySummerCacheTexInfo,       // JODY_SUMMER
    sPortraitMightyGazelleCacheTexInfo,    // MIGHTY_GAZELLE
    sPortraitMrEadCacheTexInfo,            // MR_EAD
    sPortraitBabaCacheTexInfo,             // BABA
    sPortraitOctomanCacheTexInfo,          // OCTOMAN
    sPortraitGomarAndShiohCacheTexInfo,    // GOMAR_AND_SHIOH
    sPortraitKateAlenCacheTexInfo,         // KATE_ALEN
    sPortraitRogerBusterCacheTexInfo,      // ROGER_BUSTER
    sPortraitJamesMcCloudCacheTexInfo,     // JAMES_MCCLOUD
    sPortraitLeonCacheTexInfo,             // LEON
    sPortraitAntonioGusterCacheTexInfo,    // ANTONIO_GUSTER
    sPortraitBlackShadowCacheTexInfo,      // BLACK_SHADOW
    sPortraitMichaelChainCacheTexInfo,     // MICHAEL_CHAIN
    sPortraitJackLevinCacheTexInfo,        // JACK_LEVIN
    sPortraitSuperArrowCacheTexInfo,       // SUPER_ARROW
    sPortraitMrsArrowCacheTexInfo,         // MRS_ARROW
    sPortraitJohnTanakaCacheTexInfo,       // JOHN_TANAKA
    sPortraitBeastmanCacheTexInfo,         // BEASTMAN
    sPortraitZodaCacheTexInfo,             // ZODA
    sPortraitDrClashCacheTexInfo,          // DR_CLASH
    sPortraitSilverNeelsenCacheTexInfo,    // SILVER_NEELSEN
    sPortraitBioRexCacheTexInfo,           // BIO_REX
    sPortraitDraqCacheTexInfo,             // DRAQ
    sPortraitBillyCacheTexInfo,            // BILLY
    sPortraitTheSkullCacheTexInfo,         // THE_SKULL
    sPortraitBloodFalconCacheTexInfo,      // BLOOD_FALCON
    sPortraitCaptainFalconAltCacheTexInfo, // FALCON_ALT
    sPortraitCaptainFalconAltCacheTexInfo, // FALCON_ALT
    sPortraitCaptainFalconAltCacheTexInfo, // FALCON_ALT
    sPortraitSamuraiGorohAltCacheTexInfo,  // GOROH_ALT
    sPortraitJodySummerAltCacheTexInfo,    // SUMMERS_ALT
};

TextureSwapEntry D_i4_8011BE4C[] = { { sPortraitDrStewartCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BE5C[] = { { sPortraitCaptainFalconCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BE6C[] = { { sPortraitJodySummerCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BE7C[] = { { sPortraitSamuraiGorohCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BE8C[] = { { sPortraitMightyGazelleCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BE9C[] = { { sPortraitPicoCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BEAC[] = { { sPortraitBabaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BEBC[] = { { sPortraitMrEadCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BECC[] = { { sPortraitOctomanCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BEDC[] = { { sPortraitTheSkullCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BEEC[] = { { sPortraitBeastmanCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BEFC[] = { { sPortraitAntonioGusterCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BF0C[] = { { sPortraitDraqCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BF1C[] = { { sPortraitRogerBusterCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BF2C[] = { { sPortraitSilverNeelsenCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BF3C[] = { { sPortraitSuperArrowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BF4C[] = { { sPortraitMrsArrowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BF5C[] = { { sPortraitZodaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BF6C[] = { { sPortraitJohnTanakaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BF7C[] = { { sPortraitBioRexCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BF8C[] = { { sPortraitKateAlenCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BF9C[] = { { sPortraitGomarAndShiohCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BFAC[] = { { sPortraitMichaelChainCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BFBC[] = { { sPortraitBillyCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BFCC[] = { { sPortraitDrClashCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BFDC[] = { { sPortraitJackLevinCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BFEC[] = { { sPortraitBloodFalconCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011BFFC[] = { { sPortraitLeonCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C00C[] = { { sPortraitJamesMcCloudCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C01C[] = { { sPortraitBlackShadowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C02C[] = { { sPortraitCaptainFalconAltCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C03C[] = { { sPortraitSamuraiGorohAltCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C04C[] = { { sPortraitJodySummerAltCacheTexInfo, 60 }, { 0 } };

TextureSwapEntry* D_i4_8011C05C[] = {
    D_i4_8011BE5C, D_i4_8011BE4C, D_i4_8011BE9C, D_i4_8011BE7C, D_i4_8011BE6C, D_i4_8011BE8C, D_i4_8011BEBC,
    D_i4_8011BEAC, D_i4_8011BECC, D_i4_8011BF9C, D_i4_8011BF8C, D_i4_8011BF1C, D_i4_8011C00C, D_i4_8011BFFC,
    D_i4_8011BEFC, D_i4_8011C01C, D_i4_8011BFAC, D_i4_8011BFDC, D_i4_8011BF3C, D_i4_8011BF4C, D_i4_8011BF6C,
    D_i4_8011BEEC, D_i4_8011BF5C, D_i4_8011BFCC, D_i4_8011BF2C, D_i4_8011BF7C, D_i4_8011BF0C, D_i4_8011BFBC,
    D_i4_8011BEDC, D_i4_8011BFEC, D_i4_8011C02C, D_i4_8011C02C, D_i4_8011C02C, D_i4_8011C03C, D_i4_8011C04C,
};

CacheTexInfo sSmallPortraitDrStewartCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitDrStewartTex);
CacheTexInfo sSmallPortraitCaptainFalconCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitCaptainFalconTex);
CacheTexInfo sSmallPortraitJodySummerCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitJodySummerTex);
CacheTexInfo sSmallPortraitSamuraiGorohCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitSamuraiGorohTex);
CacheTexInfo sSmallPortraitMightyGazelleCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitMightyGazelleTex);
CacheTexInfo sSmallPortraitPicoCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitPicoTex);
CacheTexInfo sSmallPortraitBabaCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitBabaTex);
CacheTexInfo sSmallPortraitMrEadCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitMrEadTex);
CacheTexInfo sSmallPortraitOctomanCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitOctomanTex);
CacheTexInfo sSmallPortraitTheSkullCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitTheSkullTex);
CacheTexInfo sSmallPortraitBeastmanCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitBeastmanTex);
CacheTexInfo sSmallPortraitAntonioGusterCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitAntonioGusterTex);
CacheTexInfo sSmallPortraitDraqCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitDraqTex);
CacheTexInfo sSmallPortraitRogerBusterCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitRogerBusterTex);
CacheTexInfo sSmallPortraitSilverNeelsenCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitSilverNeelsenTex);
CacheTexInfo sSmallPortraitSuperArrowCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitSuperArrowTex);
CacheTexInfo sSmallPortraitMrsArrowCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitMrsArrowTex);
CacheTexInfo sSmallPortraitZodaCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitZodaTex);
CacheTexInfo sSmallPortraitJohnTanakaCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitJohnTanakaTex);
CacheTexInfo sSmallPortraitBioRexCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitBioRexTex);
CacheTexInfo sSmallPortraitKateAlenCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitKateAlenTex);
CacheTexInfo sSmallPortraitGomarAndShiohCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitGomarAndShiohTex);
CacheTexInfo sSmallPortraitMichaelChainCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitMichaelChainTex);
CacheTexInfo sSmallPortraitBillyCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitBillyTex);
CacheTexInfo sSmallPortraitDrClashCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitDrClashTex);
CacheTexInfo sSmallPortraitJackLevinCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitJackLevinTex);
CacheTexInfo sSmallPortraitBloodFalconCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitBloodFalconTex);
CacheTexInfo sSmallPortraitLeonCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitLeonTex);
CacheTexInfo sSmallPortraitJamesMcCloudCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitJamesMcCloudTex);
CacheTexInfo sSmallPortraitBlackShadowCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitBlackShadowTex);
CacheTexInfo sSmallPortraitCaptainFalconAltCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitCaptainFalconAltTex);
CacheTexInfo sSmallPortraitSamuraiGorohAltCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitSamuraiGorohAltTex);
CacheTexInfo sSmallPortraitJodySummerAltCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aSmallPortraitJodySummerAltTex);

CacheTexInfo* sSmallPortraitCacheTexInfos[] = {
    sSmallPortraitCaptainFalconCacheTexInfo,    // CAPTAIN_FALCON
    sSmallPortraitDrStewartCacheTexInfo,        // DR_STEWART
    sSmallPortraitPicoCacheTexInfo,             // PICO
    sSmallPortraitSamuraiGorohCacheTexInfo,     // SAMURAI_GOROH
    sSmallPortraitJodySummerCacheTexInfo,       // JODY_SUMMER
    sSmallPortraitMightyGazelleCacheTexInfo,    // MIGHTY_GAZELLE
    sSmallPortraitMrEadCacheTexInfo,            // MR_EAD
    sSmallPortraitBabaCacheTexInfo,             // BABA
    sSmallPortraitOctomanCacheTexInfo,          // OCTOMAN
    sSmallPortraitGomarAndShiohCacheTexInfo,    // GOMAR_AND_SHIOH
    sSmallPortraitKateAlenCacheTexInfo,         // KATE_ALEN
    sSmallPortraitRogerBusterCacheTexInfo,      // ROGER_BUSTER
    sSmallPortraitJamesMcCloudCacheTexInfo,     // JAMES_MCCLOUD
    sSmallPortraitLeonCacheTexInfo,             // LEON
    sSmallPortraitAntonioGusterCacheTexInfo,    // ANTONIO_GUSTER
    sSmallPortraitBlackShadowCacheTexInfo,      // BLACK_SHADOW
    sSmallPortraitMichaelChainCacheTexInfo,     // MICHAEL_CHAIN
    sSmallPortraitJackLevinCacheTexInfo,        // JACK_LEVIN
    sSmallPortraitSuperArrowCacheTexInfo,       // SUPER_ARROW
    sSmallPortraitMrsArrowCacheTexInfo,         // MRS_ARROW
    sSmallPortraitJohnTanakaCacheTexInfo,       // JOHN_TANAKA
    sSmallPortraitBeastmanCacheTexInfo,         // BEASTMAN
    sSmallPortraitZodaCacheTexInfo,             // ZODA
    sSmallPortraitDrClashCacheTexInfo,          // DR_CLASH
    sSmallPortraitSilverNeelsenCacheTexInfo,    // SILVER_NEELSEN
    sSmallPortraitBioRexCacheTexInfo,           // BIO_REX
    sSmallPortraitDraqCacheTexInfo,             // DRAQ
    sSmallPortraitBillyCacheTexInfo,            // BILLY
    sSmallPortraitTheSkullCacheTexInfo,         // THE_SKULL
    sSmallPortraitBloodFalconCacheTexInfo,      // BLOOD_FALCON
    sSmallPortraitCaptainFalconAltCacheTexInfo, // FALCON_ALT
    sSmallPortraitCaptainFalconAltCacheTexInfo, // FALCON_ALT
    sSmallPortraitCaptainFalconAltCacheTexInfo, // FALCON_ALT
    sSmallPortraitSamuraiGorohAltCacheTexInfo,  // GOROH_ALT
    sSmallPortraitJodySummerAltCacheTexInfo,    // SUMMERS_ALT
};

TextureSwapEntry D_i4_8011C594[] = { { sSmallPortraitDrStewartCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C5A4[] = { { sSmallPortraitCaptainFalconCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C5B4[] = { { sSmallPortraitJodySummerCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C5C4[] = { { sSmallPortraitSamuraiGorohCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C5D4[] = { { sSmallPortraitMightyGazelleCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C5E4[] = { { sSmallPortraitPicoCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C5F4[] = { { sSmallPortraitBabaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C604[] = { { sSmallPortraitMrEadCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C614[] = { { sSmallPortraitOctomanCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C624[] = { { sSmallPortraitTheSkullCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C634[] = { { sSmallPortraitBeastmanCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C644[] = { { sSmallPortraitAntonioGusterCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C654[] = { { sSmallPortraitDraqCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C664[] = { { sSmallPortraitRogerBusterCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C674[] = { { sSmallPortraitSilverNeelsenCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C684[] = { { sSmallPortraitSuperArrowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C694[] = { { sSmallPortraitMrsArrowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C6A4[] = { { sSmallPortraitZodaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C6B4[] = { { sSmallPortraitJohnTanakaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C6C4[] = { { sSmallPortraitBioRexCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C6D4[] = { { sSmallPortraitKateAlenCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C6E4[] = { { sSmallPortraitGomarAndShiohCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C6F4[] = { { sSmallPortraitMichaelChainCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C704[] = { { sSmallPortraitBillyCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C714[] = { { sSmallPortraitDrClashCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C724[] = { { sSmallPortraitJackLevinCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C734[] = { { sSmallPortraitBloodFalconCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C744[] = { { sSmallPortraitLeonCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C754[] = { { sSmallPortraitJamesMcCloudCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C764[] = { { sSmallPortraitBlackShadowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C774[] = { { sSmallPortraitCaptainFalconAltCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C784[] = { { sSmallPortraitSamuraiGorohAltCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011C794[] = { { sSmallPortraitJodySummerAltCacheTexInfo, 60 }, { 0 } };

TextureSwapEntry* D_i4_8011C7A4[] = {
    D_i4_8011C5A4, D_i4_8011C594, D_i4_8011C5E4, D_i4_8011C5C4, D_i4_8011C5B4, D_i4_8011C5D4,
    D_i4_8011C604, D_i4_8011C5F4, D_i4_8011C614, D_i4_8011C6E4, D_i4_8011C6D4, D_i4_8011C664,
    D_i4_8011C754, D_i4_8011C744, D_i4_8011C644, D_i4_8011C764, D_i4_8011C6F4, D_i4_8011C724,
    D_i4_8011C684, D_i4_8011C694, D_i4_8011C6B4, D_i4_8011C634, D_i4_8011C6A4, D_i4_8011C714,
    D_i4_8011C674, D_i4_8011C6C4, D_i4_8011C654, D_i4_8011C704, D_i4_8011C624, D_i4_8011C734,
    D_i4_8011C774, D_i4_8011C774, D_i4_8011C774, D_i4_8011C784, D_i4_8011C794, D_i4_8011C774,
};

CacheTexInfo sNameCardCaptainFalconCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardCaptainFalconTex);
CacheTexInfo sNameCardDrStewartCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardDrStewartTex);
CacheTexInfo sNameCardPicoCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardPicoTex);
CacheTexInfo sNameCardSamuraiGorohCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardSamuraiGorohTex);
CacheTexInfo sNameCardJodySummerCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardJodySummerTex);
CacheTexInfo sNameCardMrEadCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardMrEadTex);
CacheTexInfo sNameCardBabaCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardBabaTex);
CacheTexInfo sNameCardOctomanCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardOctomanTex);
CacheTexInfo sNameCardGomarAndShiohCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardGomarAndShiohTex);
CacheTexInfo sNameCardKateAlenCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardKateAlenTex);
CacheTexInfo sNameCardRogerBusterCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardRogerBusterTex);
CacheTexInfo sNameCardJamesMcCloudCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardJamesMcCloudTex);
CacheTexInfo sNameCardLeonCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardLeonTex);
CacheTexInfo sNameCardAntonioGusterCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardAntonioGusterTex);
CacheTexInfo sNameCardBlackShadowCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardBlackShadowTex);
CacheTexInfo sNameCardMichaelChainCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardMichaelChainTex);
CacheTexInfo sNameCardJackLevinCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardJackLevinTex);
CacheTexInfo sNameCardSuperArrowCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardSuperArrowTex);
CacheTexInfo sNameCardMrsArrowCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardMrsArrowTex);
CacheTexInfo sNameCardJohnTanakaCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardJohnTanakaTex);
CacheTexInfo sNameCardBeastmanCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardBeastmanTex);
CacheTexInfo sNameCardZodaCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardZodaTex);
CacheTexInfo sNameCardDrClashCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardDrClashTex);
CacheTexInfo sNameCardSilverNeelsenCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardSilverNeelsenTex);
CacheTexInfo sNameCardBioRexCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardBioRexTex);
CacheTexInfo sNameCardDraqCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardDraqTex);
CacheTexInfo sNameCardBillyCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardBillyTex);
CacheTexInfo sNameCardBloodFalconCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardBloodFalconTex);
CacheTexInfo sNameCardMightyGazelleCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardMightyGazelleTex);
CacheTexInfo sNameCardTheSkullCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aNameCardTheSkullTex);

CacheTexInfo* sNameCardCacheTexInfos[] = {
    sNameCardCaptainFalconCacheTexInfo, // CAPTAIN_FALCON
    sNameCardDrStewartCacheTexInfo,     // DR_STEWART
    sNameCardPicoCacheTexInfo,          // PICO
    sNameCardSamuraiGorohCacheTexInfo,  // SAMURAI_GOROH
    sNameCardJodySummerCacheTexInfo,    // JODY_SUMMER
    sNameCardMightyGazelleCacheTexInfo, // MIGHTY_GAZELLE
    sNameCardMrEadCacheTexInfo,         // MR_EAD
    sNameCardBabaCacheTexInfo,          // BABA
    sNameCardOctomanCacheTexInfo,       // OCTOMAN
    sNameCardGomarAndShiohCacheTexInfo, // GOMAR_AND_SHIOH
    sNameCardKateAlenCacheTexInfo,      // KATE_ALEN
    sNameCardRogerBusterCacheTexInfo,   // ROGER_BUSTER
    sNameCardJamesMcCloudCacheTexInfo,  // JAMES_MCCLOUD
    sNameCardLeonCacheTexInfo,          // LEON
    sNameCardAntonioGusterCacheTexInfo, // ANTONIO_GUSTER
    sNameCardBlackShadowCacheTexInfo,   // BLACK_SHADOW
    sNameCardMichaelChainCacheTexInfo,  // MICHAEL_CHAIN
    sNameCardJackLevinCacheTexInfo,     // JACK_LEVIN
    sNameCardSuperArrowCacheTexInfo,    // SUPER_ARROW
    sNameCardMrsArrowCacheTexInfo,      // MRS_ARROW
    sNameCardJohnTanakaCacheTexInfo,    // JOHN_TANAKA
    sNameCardBeastmanCacheTexInfo,      // BEASTMAN
    sNameCardZodaCacheTexInfo,          // ZODA
    sNameCardDrClashCacheTexInfo,       // DR_CLASH
    sNameCardSilverNeelsenCacheTexInfo, // SILVER_NEELSEN
    sNameCardBioRexCacheTexInfo,        // BIO_REX
    sNameCardDraqCacheTexInfo,          // DRAQ
    sNameCardBillyCacheTexInfo,         // BILLY
    sNameCardTheSkullCacheTexInfo,      // THE_SKULL
    sNameCardBloodFalconCacheTexInfo,   // BLOOD_FALCON
    sNameCardCaptainFalconCacheTexInfo,
};

TextureSwapEntry D_i4_8011CC70[] = { { sNameCardCaptainFalconCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CC80[] = { { sNameCardDrStewartCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CC90[] = { { sNameCardPicoCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CCA0[] = { { sNameCardSamuraiGorohCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CCB0[] = { { sNameCardJodySummerCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CCC0[] = { { sNameCardMightyGazelleCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CCD0[] = { { sNameCardMrEadCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CCE0[] = { { sNameCardBabaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CCF0[] = { { sNameCardOctomanCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CD00[] = { { sNameCardGomarAndShiohCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CD10[] = { { sNameCardKateAlenCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CD20[] = { { sNameCardRogerBusterCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CD30[] = { { sNameCardJamesMcCloudCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CD40[] = { { sNameCardLeonCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CD50[] = { { sNameCardAntonioGusterCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CD60[] = { { sNameCardBlackShadowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CD70[] = { { sNameCardMichaelChainCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CD80[] = { { sNameCardJackLevinCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CD90[] = { { sNameCardSuperArrowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CDA0[] = { { sNameCardMrsArrowCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CDB0[] = { { sNameCardJohnTanakaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CDC0[] = { { sNameCardBeastmanCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CDD0[] = { { sNameCardZodaCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CDE0[] = { { sNameCardDrClashCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CDF0[] = { { sNameCardSilverNeelsenCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CE00[] = { { sNameCardBioRexCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CE10[] = { { sNameCardDraqCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CE20[] = { { sNameCardBillyCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CE30[] = { { sNameCardTheSkullCacheTexInfo, 60 }, { 0 } };
TextureSwapEntry D_i4_8011CE40[] = { { sNameCardBloodFalconCacheTexInfo, 60 }, { 0 } };

TextureSwapEntry* D_i4_8011CE50[] = {
    D_i4_8011CC70, D_i4_8011CC80, D_i4_8011CC90, D_i4_8011CCA0, D_i4_8011CCB0, D_i4_8011CCC0, D_i4_8011CCD0,
    D_i4_8011CCE0, D_i4_8011CCF0, D_i4_8011CD00, D_i4_8011CD10, D_i4_8011CD20, D_i4_8011CD30, D_i4_8011CD40,
    D_i4_8011CD50, D_i4_8011CD60, D_i4_8011CD70, D_i4_8011CD80, D_i4_8011CD90, D_i4_8011CDA0, D_i4_8011CDB0,
    D_i4_8011CDC0, D_i4_8011CDD0, D_i4_8011CDE0, D_i4_8011CDF0, D_i4_8011CE00, D_i4_8011CE10, D_i4_8011CE20,
    D_i4_8011CE30, D_i4_8011CE40, D_i4_8011CC70,
};

CacheTexInfo sSelectMachineCacheTexInfo[] = CACHE_TEX_INFO(TEX_CACHE_FMT_I4, aSelectMachineTex, 0);
CacheTexInfo s1PIconCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, a1PIconTex);
CacheTexInfo s2PIconCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, a2PIconTex);
CacheTexInfo s3PIconCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, a3PIconTex);
CacheTexInfo s4PIconCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, a4PIconTex);

CacheTexInfo* sPlayerNumIconCacheTexInfos[] = {
    s1PIconCacheTexInfo,
    s2PIconCacheTexInfo,
    s3PIconCacheTexInfo,
    s4PIconCacheTexInfo,
};

CacheTexInfo sMachineSelectCursorCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMachineSelectCursorTex);
CacheTexInfo sMachineInfoGraphCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMachineInfoGraphTex);
CacheTexInfo sMachineAccelerationMaxSpeedCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMachineAccelerationMaxSpeedTex);
CacheTexInfo sMachineBodyBoostGripCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMachineBodyBoostGripTex);
CacheTexInfo sMachineInfoGraphSmallCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aMachineInfoGraphSmallTex);
CacheTexInfo sMachineAccelerationMaxSpeedSmallCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16_TILED, aMachineAccelerationMaxSpeedSmallTex);
CacheTexInfo sMachineBodyBoostGripSmallCacheTexInfo[] =
    CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMachineBodyBoostGripSmallTex);
CacheTexInfo sEngineSliderCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aEngineSliderTex);
CacheTexInfo sNoviceJackTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aNoviceJackTrophyTex);
CacheTexInfo sNoviceQueenTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aNoviceQueenTrophyTex);
CacheTexInfo sNoviceKingTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aNoviceKingTrophyTex);
CacheTexInfo sNoviceJokerTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aNoviceJokerTrophyTex);
CacheTexInfo sNoviceXTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aNoviceXTrophyTex);
CacheTexInfo sStandardJackTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aStandardJackTrophyTex);
CacheTexInfo sStandardQueenTrophyCacheTexInfo[] =
    CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aStandardQueenTrophyTex);
CacheTexInfo sStandardKingTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aStandardKingTrophyTex);
CacheTexInfo sStandardJokerTrophyCacheTexInfo[] =
    CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aStandardJokerTrophyTex);
CacheTexInfo sStandardXTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aStandardXTrophyTex);
CacheTexInfo sExpertJackTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aExpertJackTrophyTex);
CacheTexInfo sExpertQueenTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aExpertQueenTrophyTex);
CacheTexInfo sExpertKingTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aExpertKingTrophyTex);
CacheTexInfo sExpertJokerTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aExpertJokerTrophyTex);
CacheTexInfo sExpertXTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aExpertXTrophyTex);
CacheTexInfo sMasterJackTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aMasterJackTrophyTex);
CacheTexInfo sMasterQueenTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aMasterQueenTrophyTex);
CacheTexInfo sMasterKingTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aMasterKingTrophyTex);
CacheTexInfo sMasterJokerTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aMasterJokerTrophyTex);
CacheTexInfo sMasterXTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aMasterXTrophyTex);
CacheTexInfo sNoTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aNoTrophyTex);
#ifdef EXPANSION_KIT
CacheTexInfo sNoviceDDTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aNoviceDDTrophyTex);
CacheTexInfo sStandardDDTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aStandardDDTrophyTex);
CacheTexInfo sExpertDDTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aExpertDDTrophyTex);
CacheTexInfo sMasterDDTrophyCacheTexInfo[] = CACHE_TEX_INFO_COMP_PAD(TEX_CACHE_FMT_RGBA16, aMasterDDTrophyTex);
#endif

CacheTexInfo* sTrophyCacheTexInfos[] = {
    sNoviceJackTrophyCacheTexInfo,    sNoviceQueenTrophyCacheTexInfo,  sNoviceKingTrophyCacheTexInfo,
    sNoviceJokerTrophyCacheTexInfo,   sNoviceXTrophyCacheTexInfo,      sStandardJackTrophyCacheTexInfo,
    sStandardQueenTrophyCacheTexInfo, sStandardKingTrophyCacheTexInfo, sStandardJokerTrophyCacheTexInfo,
    sStandardXTrophyCacheTexInfo,     sExpertJackTrophyCacheTexInfo,   sExpertQueenTrophyCacheTexInfo,
    sExpertKingTrophyCacheTexInfo,    sExpertJokerTrophyCacheTexInfo,  sExpertXTrophyCacheTexInfo,
    sMasterJackTrophyCacheTexInfo,    sMasterQueenTrophyCacheTexInfo,  sMasterKingTrophyCacheTexInfo,
    sMasterJokerTrophyCacheTexInfo,   sMasterXTrophyCacheTexInfo,      sNoTrophyCacheTexInfo,
#ifdef EXPANSION_KIT
    sNoviceDDTrophyCacheTexInfo,      sStandardDDTrophyCacheTexInfo,   sExpertDDTrophyCacheTexInfo,
    sMasterDDTrophyCacheTexInfo,
#endif
};

static CacheTexInfo sNoviceCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aNoviceTex);
static CacheTexInfo sStandardCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aStandardTex);
static CacheTexInfo sExpertCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aExpertTex);
static CacheTexInfo sMasterCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aMasterTex);

static CacheTexInfo* sDifficultyCacheTexInfos[] = {
    sNoviceCacheTexInfo,
    sStandardCacheTexInfo,
    sExpertCacheTexInfo,
    sMasterCacheTexInfo,
};

static CacheTexInfo sBoostCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aBoostTex);
static CacheTexInfo sBodyCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aBodyTex);
static CacheTexInfo sGripCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aGripTex);

CacheTexInfo* sMachineStatCacheTexInfos[] = {
    sBodyCacheTexInfo,
    sBoostCacheTexInfo,
    sGripCacheTexInfo,
};

static CacheTexInfo sOKCacheTexInfo[] = CACHE_TEX_INFO_COMP(TEX_CACHE_FMT_RGBA16, aOKTex);

static const char* sMachineStatValueStr[] = { "a", "b", "c", "d", "e" };

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
    D_800CE748 = D_800CE74C = D_800CE750 = 0.1f;
    Camera_Init();
    func_8008969C();
    gMachineSelectState = MACHINE_SELECT_ACTIVE;

    for (i = 0; i < 4; i++) {
        gPlayerSelectionLock[i] = SELECTION_FREE;
        sMachineSelectIndex[i] = Character_GetSlotFromCharacter(gRacers[i].character);
    }
    sMachinesUnlocked = ((func_8007E008() / 3) * 6) + 6;
    if (gSettingEverythingUnlocked) {
        sMachinesUnlocked = 30;
    }
    if (sMachinesUnlocked > 30) {
        sMachinesUnlocked = 30;
    }
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_MACHINE_SELECT_BACKGROUND, 0, 0, 4);
    Object_Init(OBJECT_MACHINE_SELECT_HEADER, 80, 13, 4);
    Object_Init(OBJECT_MACHINE_SELECT_CURSOR, 60, 10, 8);
    Object_Init(OBJECT_MACHINE_SELECT_MACHINE, 0, 0, 10);

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
    Camera_Init();
    func_8008969C();
    gMachineSettingsState = MACHINE_SETTINGS_ACTIVE;

    for (i = 0; i < 4; i++) {
        gPlayerSelectionLock[i] = SELECTION_FREE;
        if (gGameMode != GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS) {
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
    Object_Init(OBJECT_MACHINE_SETTINGS_MACHINE, 0, 0, 12);
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

extern u16 gInputPressed;
extern u16 gInputButtonPressed;
extern s8 D_800CD3AC[];

s32 MachineSelect_Update(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 pad;
    s16 pad2;
    s16 lastMachineIndex;

    Camera_Update();

    for (i = 3; i >= 0; i--) {

        Controller_SetGlobalInputs(&gControllers[gPlayerControlPorts[i]]);
        if (i >= gNumPlayers) {
            if ((gInputButtonPressed & BTN_B) && (gMachineSelectState == MACHINE_SELECT_ACTIVE)) {
                Audio_TriggerSystemSE(NA_SE_16);
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
                (MACHINE_MINI_STATE(Object_Get(OBJECT_MACHINE_SELECT_MACHINE)) == 0) &&
                (gMachineSelectState != MACHINE_SELECT_CONTINUE)) {
                MACHINE_MINI_STATE(Object_Get(OBJECT_MACHINE_SELECT_MACHINE)) = 1;
                D_i4_8011D778 = 1.0f;
                D_i4_8011D77C = 0.0f;
                Audio_TriggerSystemSE(NA_SE_23);
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
                gRacers[i].character = Character_GetCharacterFromSlot(sMachineSelectIndex[i]);

                if (lastMachineIndex != sMachineSelectIndex[i]) {
                    Audio_PlayerTriggerSEStart(i, NA_SE_30);
                    D_800CD3AC[i] = 1;
                    gPlayerEngine[i] = 0.5f;
                }

                if (gInputButtonPressed & BTN_B) {
                    Audio_PlayerTriggerSEStart(i, NA_SE_16);

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
                                        j == gRacers[k].machineSkinIndex) {
                                        break;
                                    }
                                }

                                if (k >= 4) {
                                    gRacers[i].machineSkinIndex = j;
                                    break;
                                }
                            }
                            if (j >= 4) {
                                gRacers[i].machineSkinIndex = 0;
                            }
                        }
                        Audio_PlayerTriggerSEStart(i, NA_SE_33);
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
            case MACHINE_SELECT_AWAIT_OK:
                if (gInputButtonPressed & BTN_B) {
                    gPlayerSelectionLock[i] = SELECTION_FREE;
                    gMachineSelectState = MACHINE_SELECT_ACTIVE;
                    Audio_PlayerTriggerSEStart(i, NA_SE_16);
                    break;
                }
                if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    Audio_PlayerTriggerSEStart(i, NA_SE_62);
                    gMachineSelectState = MACHINE_SELECT_CONTINUE;
                    return GAMEMODE_LX_MACHINE_SETTINGS;
                }
                break;
        }
    }
    return gGameMode;
}

extern s32 gTransitionState;

s32 MachineSettings_Update(void) {
    s32 i;
    s32 j;
    s32 k;
    Controller* temp_s1;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 var_fa1;
    s32 stickX;

    Camera_Update();
    if (gTransitionState != TRANSITION_INACTIVE) {
        return gGameMode;
    }

    for (i = gNumPlayers - 1; i >= 0; i--) {
        temp_s1 = &gControllers[gPlayerControlPorts[i]];
        Controller_SetGlobalInputs(temp_s1);

        switch (gMachineSettingsState) {
            case MACHINE_SETTINGS_ACTIVE:
                if (gPlayerSelectionLock[i] == SELECTION_FREE) {

                    k = gRacers[i].machineSkinIndex;

                    if (gInputButtonPressed & BTN_Z) {
                        gRacers[i].machineSkinIndex--;
                        gRacers[i].machineSkinIndex &= 3;
                    }
                    if (gInputButtonPressed & BTN_R) {
                        gRacers[i].machineSkinIndex++;
                        gRacers[i].machineSkinIndex &= 3;
                    }
                    if (k != gRacers[i].machineSkinIndex) {
                        Audio_PlayerTriggerSEStart(i, NA_SE_30);
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
                        Audio_PlayerTriggerSEStart(i, NA_SE_22);
                    }
                    if (gNumPlayers == 1) {
                        gCharacterLastEngine[gRacers[0].character] = gPlayerEngine[0];
                    }
                }
                if (gInputButtonPressed & BTN_B) {
                    Audio_PlayerTriggerSEStart(i, NA_SE_16);

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
                    Audio_PlayerTriggerSEStart(i, NA_SE_33);
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
                    Audio_PlayerTriggerSEStart(i, NA_SE_16);
                } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    Audio_PlayerTriggerSEStart(i, NA_SE_62);
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
    TextureCache_ProcessLoadQueue();
    if (gGameMode != gQueuedGameMode) {
        func_80089724();
    }
    return gfx;
}

Gfx* MachineSettings_Draw(Gfx* gfx) {
    gfx = Object_UpdateAndDrawAll(gfx);
    TextureCache_ProcessLoadQueue();
    if (gGameMode != gQueuedGameMode) {
        func_80089724();
    }
    return gfx;
}

extern CustomMachinesInfo gCustomMachinesInfo;

s32 MachineSettings_GetCharacter(s32 character) {

#ifdef EXPANSION_KIT
    if (gCustomMachinesInfo.characterCustomState[character] == -1) {
        character += 30;
        if (character >= 36) {
            character %= 30;
        }
    }
#endif

    return character;
}

void MachineSelect_HeaderInit(void) {
    TextureCache_LoadCacheTexInfoList_impl(sSelectMachineCacheTexInfo, false, true);
}

void func_i4_80116E8C(Object* arg0) {
    s32 i;

    if (gNumPlayers == 1) {
        TextureCache_LoadCacheTexInfoList_impl(sPortraitCacheTexInfos[gRacers[0].character], false, true);
        return;
    }

    for (i = 0; i < gNumPlayers; i++) {
        TextureCache_LoadCacheTexInfoList_impl(sSmallPortraitCacheTexInfos[gRacers[i].character], false, true);
    }
}

void MachineSettings_PortraitInit(Object* portraitObj) {
    s32 playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SETTINGS_PORTRAIT_0;

    OBJECT_STATE(portraitObj) = gRacers[playerIndex].character;
    OBJECT_STATE(portraitObj) = MachineSettings_GetCharacter(OBJECT_STATE(portraitObj));

    if (gNumPlayers == 1) {
        TextureCache_LoadCacheTexInfoList_impl(sPortraitBackgroundCacheTexInfo, false, true);
        OBJECT_CACHE_INDEX(portraitObj) = TextureCache_AllocSwapSlot(D_i4_8011C05C[OBJECT_STATE(portraitObj)]);
    } else {
        OBJECT_CACHE_INDEX(portraitObj) = TextureCache_AllocSwapSlot(D_i4_8011C7A4[OBJECT_STATE(portraitObj)]);
    }
}

void MachineSelect_PortraitInit(Object* portraitObj) {
    OBJECT_CACHE_INDEX(portraitObj) = TextureCache_AllocSwapSlot(D_i4_8011C7A4[0]);
}

void MachineSelect_CursorNumInit(Object* cursorNumObj) {
    TextureCache_LoadCacheTexInfoList_impl(
        sPlayerNumIconCacheTexInfos[cursorNumObj->cmdId - OBJECT_MACHINE_SELECT_CURSOR_NUM_0], false, true);
}

void MachineSelect_CursorInit(void) {
    TextureCache_LoadCacheTexInfoList_impl(sMachineSelectCursorCacheTexInfo, false, true);
}

void MachineSelect_MachineInit(Object* machineObj) {
    Vp* vp;
    s32 i;
    s32 j;

    vp = (Vp*) Arena_Allocate(ALLOC_FRONT, 30 * sizeof(Vp));
    MACHINE_VIEWPORT(machineObj) = vp;

    for (i = 0; i < 30; i++) {
        vp[i].vp.vscale[0] = (SCREEN_WIDTH / 2) << 2;
        vp[i].vp.vscale[1] = (SCREEN_HEIGHT / 2) << 2;
        vp[i].vp.vscale[2] = 0x1FF;
        vp[i].vp.vscale[3] = 0;
        vp[i].vp.vtrans[0] = (((i % 6) * 0x28) + 0x39) << 2;
        vp[i].vp.vtrans[1] = (((i / 6) * 0x22) + 0x39) << 2;
        vp[i].vp.vtrans[2] = 0x1FF;
        vp[i].vp.vtrans[3] = 0;
    }

    for (j = 3; j >= 0; j--) {
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

void MachineSettings_MachineInit(Object* machineObj) {
    Vp* vp;
    s32 i;
    s32 j;
    s32 k;

    vp = (Vp*) Arena_Allocate(ALLOC_FRONT, 2 * 4 * sizeof(Vp));
    MACHINE_VIEWPORT(machineObj) = vp;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            vp[i * 4 + j].vp.vscale[0] = (SCREEN_WIDTH / 2) << 2;
            vp[i * 4 + j].vp.vscale[1] = (SCREEN_HEIGHT / 2) << 2;
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
        gRacers[k].segmentPositionInfo.pos.x = gRacers[k].segmentPositionInfo.pos.y =
            gRacers[k].segmentPositionInfo.pos.z = 0.0f;
        gRacers[k].trueBasis.x.z = 1.0f;
        gRacers[k].trueBasis.y.y = 1.0f;
        gRacers[k].trueBasis.z.x = 1.0f;
        gRacers[k].trueBasis.x.x = 0.0f;
        gRacers[k].trueBasis.y.z = 0.0f;
        gRacers[k].trueBasis.z.y = 0.0f;
        gRacers[k].trueBasis.x.y = 0.0f;
        gRacers[k].trueBasis.y.x = 0.0f;
        gRacers[k].trueBasis.z.z = 0.0f;
    }
}

void MachineSettings_EngineWeightInit(void) {
    if (gNumPlayers == 1) {
        TextureCache_LoadCacheTexInfoList_impl(sMachineInfoGraphCacheTexInfo, false, true);
        TextureCache_LoadCacheTexInfoList_impl(sMachineAccelerationMaxSpeedCacheTexInfo, false, true);
    } else {
        TextureCache_LoadCacheTexInfoList_impl(sMachineInfoGraphSmallCacheTexInfo, false, true);
        TextureCache_LoadCacheTexInfoList_impl(sMachineAccelerationMaxSpeedSmallCacheTexInfo, false, true);
    }
}

void MachineSettings_StatsInit(void) {
    if (gNumPlayers == 1) {
        TextureCache_LoadCacheTexInfoList_impl(sMachineBodyBoostGripCacheTexInfo, false, true);
    } else {
        TextureCache_LoadCacheTexInfoList_impl(sMachineBodyBoostGripSmallCacheTexInfo, false, true);
    }
}

void MachineSettings_NameCardInit(Object* nameCardObj) {
    if (gNumPlayers == 1) {
        OBJECT_CACHE_INDEX(nameCardObj) = TextureCache_AllocSwapSlot(D_i4_8011CE50[0]);
    }
}

void MachineSettings_SliderInit(void) {
    TextureCache_LoadCacheTexInfoList_impl(sEngineSliderCacheTexInfo, false, true);
}

void MachineSelect_DifficultyCupsInit(Object* difficultyCupsObj) {
    s32 i;

    OBJECT_BUFFER(difficultyCupsObj) =
        Arena_Allocate(ALLOC_FRONT, NUM_DIFFICULTIES * TOTAL_RACER_COUNT * NUM_COMPETITIVE_CUPS);

    Save_UpdateCupSave(OBJECT_BUFFER(difficultyCupsObj));

    for (i = 0; i < 21; i++) {
        TextureCache_LoadCacheTexInfoList_impl(sTrophyCacheTexInfos[i], false, false);
    }

#ifdef EXPANSION_KIT
    for (i = 21; i < 25; i++) {
        TextureCache_LoadCacheTexInfoListEK(sTrophyCacheTexInfos[i], false);
    }
#endif

    for (i = 0; i < 4; i++) {
        TextureCache_LoadCacheTexInfoList_impl(sDifficultyCacheTexInfos[i], false, true);
    }
}

void MachineSelect_StatsInit(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        TextureCache_LoadCacheTexInfoList_impl(sMachineStatCacheTexInfos[i], false, true);
    }
}

void MachineSelect_OkInit(Object* okObj) {
    TextureCache_LoadCacheTexInfoList_impl(sOKCacheTexInfo, false, true);
    OBJECT_TOP(okObj) = 50;
}

void MachineSettings_OkInit(Object* okObj) {
    TextureCache_LoadCacheTexInfoList_impl(sOKCacheTexInfo, false, true);
    OBJECT_LEFT(okObj) = 50;
}

Gfx* MachineSelect_BackgroundDraw(Gfx* gfx) {
    s32 color;
    s32 i;
    s32 r, g, b;
    s32 temp_a1;
    s32 temp_t1 = 224;
    s32 rmul2 = 0;
    s32 gmul2 = 0;
    s32 bmul2 = 0;
    s32 rmul = 10;
    s32 gmul = 0;
    s32 bmul = 60;

    gDPSetCycleType(gfx++, G_CYC_FILL);

    for (i = 0; i < 224; i++) {
        s32 temp_t6 = 224;
        temp_a1 = temp_t6 - i;
        r = ((((rmul2 * temp_a1) + (rmul * i)) / temp_t1) >> 3);
        g = ((((gmul2 * temp_a1) + (gmul * i)) / temp_t1) >> 3);
        b = ((((bmul2 * temp_a1) + (bmul * i)) / temp_t1) >> 3);

        gDPPipeSync(gfx++);
        gDPSetFillColor(gfx++, PACK_5551(r, g, b, 1) << 0x10 | PACK_5551(r, g, b, 1));
        gDPFillRectangle(gfx++, 12, i + 8, 307, i + 8);
    }
    return gfx;
}

Gfx* MachineSelect_HeaderDraw(Gfx* gfx, Object* headerObj) {
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    return TextureCache_DrawList_impl(gfx, sSelectMachineCacheTexInfo, OBJECT_LEFT(headerObj), OBJECT_TOP(headerObj),
                                      TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
}

Gfx* func_i4_80117BE0(Gfx* gfx, Object* arg1) {
    s32 i;
    const s32* var_s0;

    if (gNumPlayers == 1) {
        gfx = TextureCache_DrawList_impl(gfx, sPortraitCacheTexInfos[gRacers[0].character], OBJECT_LEFT(arg1),
                                         OBJECT_TOP(arg1), TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_8011D6C4[i * 2];
            gfx = TextureCache_DrawList_impl(gfx, sSmallPortraitCacheTexInfos[gRacers[i].character], var_s0[0],
                                             var_s0[1] + 55, TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
        }
    }
    return gfx;
}

extern TexSwapSlot gTextureSwapSlots[];

Gfx* MachineSettings_PortraitDraw(Gfx* gfx, Object* portraitObj) {
    s32 playerIndex;
    const s32* positions;

    playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SETTINGS_PORTRAIT_0;
    positions = &D_i4_8011D6C4[playerIndex * 2];
    switch (gNumPlayers) {
        case 1:
            gfx =
                TextureCache_DrawList_impl(gfx, sPortraitBackgroundCacheTexInfo, OBJECT_LEFT(portraitObj),
                                           OBJECT_TOP(portraitObj), TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
            gfx = TextureCache_DrawSwapSlot_impl(gfx, &gTextureSwapSlots[OBJECT_CACHE_INDEX(portraitObj)],
                                                 OBJECT_LEFT(portraitObj), OBJECT_TOP(portraitObj), TEXTURE_CACHE_DRAW,
                                                 false, false, 1.0f, 1.0f, true);
            break;
        case 2:
            gfx = TextureCache_DrawSwapSlot_impl(gfx, &gTextureSwapSlots[OBJECT_CACHE_INDEX(portraitObj)],
                                                 positions[0] - 4, positions[1] + 0x1A, TEXTURE_CACHE_DRAW, false,
                                                 false, 1.0f, 1.0f, true);
            break;
        default:
            gfx =
                TextureCache_DrawSwapSlot_impl(gfx, &gTextureSwapSlots[OBJECT_CACHE_INDEX(portraitObj)], positions[0],
                                               positions[1] + 0x37, TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
            break;
    }
    return gfx;
}

extern Machine gMachines[];

Gfx* MachineSelect_StatsDraw(Gfx* gfx, Object* statsObj) {
    s32 temp_fp;
    s32 temp_s0;
    s32 temp_t0;
    s32 playerIndex;
    s8* temp_a3;
    s32 i;

    playerIndex = statsObj->cmdId - OBJECT_MACHINE_SELECT_STATS_0;

    temp_a3 = &gMachines[gRacers[playerIndex].character].machineStats;
    temp_fp = D_i4_8011D694[playerIndex * 2 + 0];
    temp_t0 = D_i4_8011D694[playerIndex * 2 + 1];
    if (playerIndex < 2) {
        for (i = 0; i < 3; i++) {
            gfx = TextureCache_DrawList_impl(gfx, sMachineStatCacheTexInfos[i], temp_fp, (temp_t0 - 7) + i * 20,
                                             TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
            temp_s0 = sMachineStatValueStr[temp_a3[i]];
            gfx = Font_DrawString(gfx, temp_fp + 5, (temp_t0 + 10) + i * 20, temp_s0, 0, FONT_SET_2, 0);
        }
    } else {
        for (i = 0; i < 3; i++) {
            gfx = TextureCache_DrawList_impl(gfx, sMachineStatCacheTexInfos[i], temp_fp - 20, (temp_t0 - 7) + i * 20,
                                             TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
            temp_s0 = sMachineStatValueStr[temp_a3[i]];
            gfx = Font_DrawString(gfx, (temp_fp - Font_GetStringWidth(temp_s0, FONT_SET_2, 0)) - 5,
                                  (temp_t0 + 10) + i * 20, temp_s0, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

Gfx* MachineSelect_PortraitDraw(Gfx* gfx, Object* portraitObj) {
    s32 playerIndex;

    playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SELECT_PORTRAIT_0;

    gfx = TextureCache_DrawSwapSlot_impl(gfx, &gTextureSwapSlots[OBJECT_CACHE_INDEX(portraitObj)],
                                         OBJECT_LEFT(portraitObj), OBJECT_TOP(portraitObj), TEXTURE_CACHE_DRAW, false,
                                         false, 1.0f, 1.0f, true);
    return TextureCache_DrawList_impl(gfx, sPlayerNumIconCacheTexInfos[playerIndex],
                                      D_i4_8011D674[playerIndex * 2 + 0] + OBJECT_LEFT(portraitObj),
                                      D_i4_8011D674[playerIndex * 2 + 1] + OBJECT_TOP(portraitObj), TEXTURE_CACHE_DRAW,
                                      false, false, 1.0f, 1.0f, true);
}

Gfx* MachineSelect_CursorNumDraw(Gfx* gfx, Object* portraitObj) {
    return TextureCache_DrawList_impl(
        gfx, sPlayerNumIconCacheTexInfos[portraitObj->cmdId - OBJECT_MACHINE_SELECT_CURSOR_NUM_0],
        OBJECT_LEFT(portraitObj), OBJECT_TOP(portraitObj), TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
}

extern u32 gGameFrameCount;

Gfx* MachineSelect_CursorDraw(Gfx* gfx, Object* cursorObj) {
    s32 temp_v0;
    s32 i;
    s32 temp_s3 = 30;
    s32 red;
    s32 green;
    s32 blue;

    for (i = 0; i < 4; i++) {
        if (Object_Get(OBJECT_MACHINE_SELECT_CURSOR_NUM_0 + i) != NULL) {
            temp_v0 = gGameFrameCount % temp_s3;
#ifdef EXPANSION_KIT
            if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex[i]] != 0) {
                red = 255;
                green = 155;
                blue = 55;
            } else {
#endif
                red = 255;
                green = 255;
                blue = 255;
#ifdef EXPANSION_KIT
            }
#endif
            if ((gPlayerSelectionLock[i] != SELECTION_FREE) || (temp_v0 >= 15)) {
                gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255 - ((temp_v0 * 255 * 2) / temp_s3));
            }
            temp_v0 = sMachineSelectIndex[i];
            OBJECT_LEFT(cursorObj) = ((temp_v0 % 6) * 40) + 40;
            OBJECT_TOP(cursorObj) = ((temp_v0 / 6) * 34) + 37;

            gfx = TextureCache_DrawList_impl(gfx, sMachineSelectCursorCacheTexInfo, OBJECT_LEFT(cursorObj),
                                             OBJECT_TOP(cursorObj), TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f,
                                             true);
        }
    }
    return gfx;
}

extern GfxPool D_1000000;
extern GfxPool* gGfxPool;

Gfx* MachineSelect_MachineDraw(Gfx* gfx, Object* machineObj) {
    bool var_t0;
    s32 i;
    s32 j;

#ifdef EXPANSION_KIT
    gSPLoadUcodeL(gfx++, gspF3DEX2_Rej_fifo);
#endif
    gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);

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
        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i);

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
#ifdef EXPANSION_KIT
        gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
#endif
        gfx = func_8009CCBC(gfx, Character_GetCharacterFromSlot(i), 0);
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
    return TextureCache_DrawList_impl(gfx, sOKCacheTexInfo, OBJECT_LEFT(okObj) + var_v1, OBJECT_TOP(okObj) + 209,
                                      TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
}

extern const char* gMachineNames[];

Gfx* MachineSettings_NameDraw(Gfx* gfx) {
    s32 i;
    const char* machineName;
    const s32* var_s0;
    s32 characterSlot;

    if (gNumPlayers == 1) {
#ifdef EXPANSION_KIT
        characterSlot = Character_GetSlotFromCharacter(gRacers[0].character);
        if (gCustomMachinesInfo.characterCustomState[characterSlot] > 0) {
            machineName = gCustomMachinesInfo.customMachines[characterSlot].machineName;
        } else {
#endif
            machineName = gMachineNames[MachineSettings_GetCharacter(gRacers[0].character)];
#ifdef EXPANSION_KIT
        }
#endif
        gfx = Font_DrawString(gfx, 290 - Font_GetStringWidth(machineName, FONT_SET_1, 0), 34, machineName, 0,
                              FONT_SET_1, 0);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_8011D6C4[i * 2];
#ifdef EXPANSION_KIT
            characterSlot = Character_GetSlotFromCharacter(gRacers[i].character);
            if (gCustomMachinesInfo.characterCustomState[characterSlot] > 0) {
                machineName = gCustomMachinesInfo.customMachines[characterSlot].machineName;
            } else {
#endif
                machineName = gMachineNames[MachineSettings_GetCharacter(gRacers[i].character)];
#ifdef EXPANSION_KIT
            }
#endif
            gfx = Font_DrawString(gfx, (var_s0[0] - Font_GetStringWidth(machineName, FONT_SET_2, 0)) + 130,
                                  var_s0[1] + 10, machineName, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

Gfx* MachineSettings_MachineDraw(Gfx* gfx, Object* machineObj) {
    s32 i;

    gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);

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

        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i + 4);
        gSPMatrix(gfx++, &D_1000000.unk_20A88[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CD60(gfx, gRacers[i].character);
    }

    gSPDisplayList(gfx++, D_303A7D8);
    gDPSetBlendColor(gfx++, 0, 0, 0, 255);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i);
        gSPMatrix(gfx++, &D_1000000.unk_21208[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CE70(gfx, gRacers[i].character);
    }

    gSPDisplayList(gfx++, D_303A5F8);

    Lights_SetSource(gGfxPool->unk_21A88, 0, 0, 0, 255, 255, 255, 50, 25, 34);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].a, 2);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i);
        gSPMatrix(gfx++, &D_1000000.unk_20308[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CCBC(gfx, gRacers[i].character, gRacers[i].machineSkinIndex);
    }

    gSPDisplayList(gfx++, D_90186C8);

    Light_SetLookAtSource(&gGfxPool->unk_21B28, &gCameras[0].viewMtx);
    gSPLookAt(gfx++, &gGfxPool->unk_21B28);

    gSPTexture(gfx++, D_i4_8011D4E0, D_i4_8011D4E0, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureBlock(gfx++, D_9000008, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i4_8011D4DC);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i);
        gSPMatrix(gfx++, &D_1000000.unk_20308[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CEA0(gfx, gRacers[i].character);
    }

    return gfx;
}

Gfx* MachineSettings_EngineWeightDraw(Gfx* gfx, Object* engineWeightObj) {
    s32 i;
    s16 weight;
    s32 temp_s0;
    s32 temp_s1;

    if (gNumPlayers == 1) {
        weight = gMachines[gRacers[0].character].weight;
        gfx =
            TextureCache_DrawList_impl(gfx, sMachineInfoGraphCacheTexInfo, OBJECT_LEFT(engineWeightObj),
                                       OBJECT_TOP(engineWeightObj), TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
        gfx = Font_DrawMachineWeight(gfx, OBJECT_LEFT(engineWeightObj) + 0x66, OBJECT_TOP(engineWeightObj) + 0x17,
                                     weight);

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
        gfx = TextureCache_DrawList_impl(gfx, sMachineAccelerationMaxSpeedCacheTexInfo, OBJECT_LEFT(engineWeightObj),
                                         OBJECT_TOP(engineWeightObj), TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f,
                                         1.0f, true);
#else
        gfx = TextureCache_DrawList_impl(gfx, sMachineAccelerationMaxSpeedCacheTexInfo,
                                         OBJECT_LEFT(engineWeightObj) + 3, OBJECT_TOP(engineWeightObj) + 1,
                                         TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
#endif
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            weight = gMachines[gRacers[i].character].weight;
            temp_s0 = D_i4_8011D6C4[i * 2 + 0];
            temp_s1 = D_i4_8011D6C4[i * 2 + 1];
            gfx = TextureCache_DrawList_impl(gfx, sMachineInfoGraphSmallCacheTexInfo, temp_s0 + 0x2B, temp_s1 + 0xA,
                                             TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);
            gfx = Font_DrawMachineWeight(gfx, temp_s0 + 0x6E, temp_s1 + 0x1C, weight);
            if (gPlayerSelectionLock[i] == SELECTION_FREE) {
                gfx = func_8007DB28(gfx, 0);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
            }
            gfx = TextureCache_DrawList_impl(gfx, sMachineAccelerationMaxSpeedSmallCacheTexInfo, temp_s0 + 0x2B,
                                             temp_s1 + 0xA, TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
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
        gfx = TextureCache_DrawList_impl(gfx, sMachineBodyBoostGripCacheTexInfo, OBJECT_LEFT(statsObj),
                                         OBJECT_TOP(statsObj), TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);

        for (i = 0; i < 3; i++) {
            temp = gMachines[gRacers[0].character].machineStats;
            gfx = Font_DrawMachineStatValue(gfx, OBJECT_LEFT(statsObj) + 0x69, OBJECT_TOP(statsObj) + i * 23 + 3,
                                            temp[i]);
        }
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            leftOffset = D_i4_8011D6C4[i * 2 + 0];
            topOffset = D_i4_8011D6C4[i * 2 + 1];

            gfx = TextureCache_DrawList_impl(gfx, sMachineBodyBoostGripSmallCacheTexInfo, leftOffset + 0x2B,
                                             topOffset + 0x39, TEXTURE_CACHE_DRAW, false, false, 1.0f, 1.0f, true);

            for (j = 0; j < 3; j++) {
                temp = gMachines[gRacers[i].character].machineStats;
                gfx = Font_DrawString(gfx, leftOffset + 0x6B, topOffset + 0x43 + j * 14, sMachineStatValueStr[temp[j]],
                                      0, FONT_SET_2, 0);
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
            temp = gMachines[gRacers[i].character].machineStats;
            temp2 = sMachineStatValueStr[temp[j]];
            gfx = Font_DrawString(gfx, var_s3 + 0x6B, var_s1 + 0x43 + j * 14, temp2, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

Gfx* MachineSettings_NameCardDraw(Gfx* gfx, Object* nameCardObj) {

    if (gNumPlayers == 1) {
        gfx = TextureCache_DrawSwapSlot_impl(gfx, &gTextureSwapSlots[OBJECT_CACHE_INDEX(nameCardObj)],
                                             OBJECT_LEFT(nameCardObj), OBJECT_TOP(nameCardObj), TEXTURE_CACHE_DRAW,
                                             false, false, 1.0f, 1.0f, true);
    }
    return gfx;
}

Gfx* MachineSettings_SliderDraw(Gfx* gfx, Object* sliderObj) {
    s32 i;
    s32 mode;
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

        gfx = TextureCache_DrawList_impl(gfx, sEngineSliderCacheTexInfo, (s32) (gPlayerEngine[0] * 128.0f) + 0x98, 0x54,
                                         TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            mode = TEXTURE_CACHE_DRAW_TINTED;
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
            gfx = TextureCache_DrawList_impl(gfx, sEngineSliderCacheTexInfo, left, top, mode, false, false, 1.0f, 1.0f,
                                             true);
        }
    }
    return gfx;
}

Gfx* MachineSettings_SplitscreenDraw(Gfx* gfx) {

    gfx = TextureUtils_DrawColorRectangle(gfx, 255, 255, 255, 12, 119, 307, 120);
    if (gNumPlayers >= 3) {
        gfx = TextureUtils_DrawColorRectangle(gfx, 255, 255, 255, 158, 8, 159, 231);
    }
    return gfx;
}

extern s32 gDifficulty;
extern s8 gUnlockableLevel;
extern s8 gSettingEverythingUnlocked;
extern s32 gAntiPiracyAddedDifficulty;

Gfx* MachineSelect_DifficultyCupsDraw(Gfx* gfx, Object* difficultyCupsObj) {
    s32 i;
    s32 character;
    s32 difficulty;
    s32 trophyIndex;
    s32 pad;
    s32 cupsUnlocked;
    s8* var_t1;

    character = Character_GetCharacterFromSlot(sMachineSelectIndex[0]);
    difficulty = 0;
    switch (gMachineSelectState) {
        case MACHINE_SELECT_AWAIT_OK:
        case MACHINE_SELECT_CONTINUE:
            break;
        default:
            if (((gUnlockableLevel >= 2) || gSettingEverythingUnlocked) &&
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

    if ((gUnlockableLevel >= 2) || gSettingEverythingUnlocked) {
        cupsUnlocked = 5;
    } else {
        if (gUnlockableLevel > 0) {
            cupsUnlocked = 4;
        } else {
            cupsUnlocked = 3;
        }
    }

    var_t1 = OBJECT_BUFFER(difficultyCupsObj) + difficulty * (TOTAL_RACER_COUNT * NUM_COMPETITIVE_CUPS) +
             character * NUM_COMPETITIVE_CUPS;

    for (i = 0; i < cupsUnlocked; i++) {

        // FAKE
        if (((s8*) var_t1)[(i ^ 0)] == 0) {
            // No trophy
            trophyIndex = 20;
#ifndef EXPANSION_KIT
            if (1) {}
#endif
        } else {
            trophyIndex = (difficulty * 5) + i;
#ifndef EXPANSION_KIT
            if (1) {}
#endif
        }

        gfx = TextureCache_DrawList_impl(gfx, sTrophyCacheTexInfos[trophyIndex], 20, 115 + i * 20, TEXTURE_CACHE_DRAW,
                                         false, false, 1.0f, 1.0f, false);
    }

#ifdef EXPANSION_KIT
    if (1) {}

    for (i = 0; i < 2; i++) {

        if (((s8*) var_t1)[(i ^ 0) + 5] == 0) {
            // No trophy
            trophyIndex = 20;
        } else {
            trophyIndex = difficulty + 21;
        }

        gfx = TextureCache_DrawList_impl(gfx, sTrophyCacheTexInfos[trophyIndex], 284, 115 + i * 20, TEXTURE_CACHE_DRAW,
                                         false, false, 1.0f, 1.0f, false);
    }
#endif

    return TextureCache_DrawList_impl(gfx, sDifficultyCacheTexInfos[difficulty], 30, 209, TEXTURE_CACHE_DRAW, false,
                                      false, 1.0f, 1.0f, true);
}

Gfx* MachineSelect_NameDraw(Gfx* gfx, Object* nameObj) {
    s32 pad[2];
    const char* machineName;

#ifdef EXPANSION_KIT
    if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex[0]] > 0) {
        machineName = gCustomMachinesInfo.customMachines[sMachineSelectIndex[0]].machineName;
    } else {
#endif
        machineName = gMachineNames[MachineSettings_GetCharacter(gRacers[0].character)];
#ifdef EXPANSION_KIT
    }
#endif

    gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth(machineName, FONT_SET_2, 0) / 2), 218, machineName, 0,
                          FONT_SET_2, 0);
    gfx = Font_DrawMachineWeightSmall(gfx, 252, 221,
                                      gMachines[Character_GetCharacterFromSlot(sMachineSelectIndex[0])].weight);
    return Font_DrawString(gfx, 252, 221, "$", 0, FONT_SET_2, 0);
}

Gfx* MachineSettings_OkDraw(Gfx* gfx, Object* okObj) {
    gfx = func_8007DB28(gfx, 0);
    return TextureCache_DrawList_impl(gfx, sOKCacheTexInfo, OBJECT_LEFT(okObj) + 0x10B, OBJECT_TOP(okObj) + 0xD0,
                                      TEXTURE_CACHE_DRAW_TINTED, false, false, 1.0f, 1.0f, true);
}

void func_i4_80119BB8(Object* arg0) {
}

void MachineSettings_PortraitUpdate(Object* portraitObj) {
    s32 index = portraitObj->cmdId - OBJECT_MACHINE_SETTINGS_PORTRAIT_0;
    s32 character = gRacers[index].character;

    character = MachineSettings_GetCharacter(character);
    if (character != PORTRAIT_CHARACTER(portraitObj)) {
        if (gNumPlayers == 1) {
            TextureCache_SetSwapSlotEntry(OBJECT_CACHE_INDEX(portraitObj), 0, D_i4_8011C05C[character]);
        } else {
            TextureCache_SetSwapSlotEntry(OBJECT_CACHE_INDEX(portraitObj), 0, D_i4_8011C7A4[character]);
        }
    }
    PORTRAIT_CHARACTER(portraitObj) = character;
}

void MachineSelect_PortraitUpdate(Object* portraitObj) {
    s32 playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SELECT_PORTRAIT_0;
    s32 character = gRacers[playerIndex].character;

    character = MachineSettings_GetCharacter(character);
    if (character != PORTRAIT_CHARACTER(portraitObj)) {
        TextureCache_SetSwapSlotEntry(OBJECT_CACHE_INDEX(portraitObj), 0, D_i4_8011C7A4[character]);
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

void MachineSelect_MachineUpdate(Object* machineObj) {
    Racer* var_s0;
    f32 var_fv0;
    s32 i;

    if (MACHINE_MINI_STATE(machineObj) == 1) {
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
                MACHINE_MINI_STATE(machineObj) = 2;
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
        var_s0->trueBasis.x.x += var_fv0 * var_s0->trueBasis.z.x;
        var_s0->trueBasis.x.y += var_fv0 * var_s0->trueBasis.z.y;
        var_s0->trueBasis.x.z += var_fv0 * var_s0->trueBasis.z.z;
        Math_OrthonormalizeAroundForward(&var_s0->trueBasis);
        Matrix_SetLockedLookAt(&gGfxPool->unk_20308[i], NULL, D_800CE748, D_800CE74C, D_800CE750, var_s0->trueBasis.x.x,
                               var_s0->trueBasis.x.y, var_s0->trueBasis.x.z, var_s0->trueBasis.y.x,
                               var_s0->trueBasis.y.y, var_s0->trueBasis.y.z, var_s0->segmentPositionInfo.pos.x,
                               var_s0->segmentPositionInfo.pos.y, var_s0->segmentPositionInfo.pos.z);
        var_s0--;
        i--;
    }
}

void MachineSettings_MachineUpdate(Object* machineObj) {
    Racer* var_s0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fv0;
    s32 i;
    s32 var_a1;
    Vp* var_v0;

    var_v0 = MACHINE_VIEWPORT(machineObj);
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

        var_s0->trueBasis.x.x += var_fv0 * var_s0->trueBasis.z.x;
        var_s0->trueBasis.x.y += var_fv0 * var_s0->trueBasis.z.y;
        var_s0->trueBasis.x.z += var_fv0 * var_s0->trueBasis.z.z;
        var_s0->trueBasis.x.x += var_fs1 * var_s0->trueBasis.y.x;
        var_s0->trueBasis.x.y += var_fs1 * var_s0->trueBasis.y.y;
        var_s0->trueBasis.x.z += var_fs1 * var_s0->trueBasis.y.z;
        var_s0->trueBasis.y.x += var_fs0 * var_s0->trueBasis.z.x;
        var_s0->trueBasis.y.y += var_fs0 * var_s0->trueBasis.z.y;
        var_s0->trueBasis.y.z += var_fs0 * var_s0->trueBasis.z.z;
        Math_OrthonormalizeAroundForward(&var_s0->trueBasis);
        Matrix_SetLockedLookAt(&gGfxPool->unk_20308[i], NULL, var_fs2 * D_800CE748, var_fs2 * D_800CE74C,
                               var_fs2 * D_800CE750, var_s0->trueBasis.x.x, var_s0->trueBasis.x.y,
                               var_s0->trueBasis.x.z, var_s0->trueBasis.y.x, var_s0->trueBasis.y.y,
                               var_s0->trueBasis.y.z, var_s0->segmentPositionInfo.pos.x,
                               var_s0->segmentPositionInfo.pos.y, var_s0->segmentPositionInfo.pos.z);
        Matrix_SetLockedLookAt(&gGfxPool->unk_21208[i], NULL, (var_fs2 * 1.05f) * D_800CE748,
                               (var_fs2 * 1.05f) * D_800CE74C, (var_fs2 * 1.05f) * D_800CE750, var_s0->trueBasis.x.x,
                               var_s0->trueBasis.x.y, var_s0->trueBasis.x.z, var_s0->trueBasis.y.x,
                               var_s0->trueBasis.y.y, var_s0->trueBasis.y.z, var_s0->segmentPositionInfo.pos.x,
                               var_s0->segmentPositionInfo.pos.y, var_s0->segmentPositionInfo.pos.z);
        Matrix_SetLockedLookAt(&gGfxPool->unk_20A88[i], NULL, var_fs2 * D_800CE748, var_fs2 * D_800CE74C,
                               var_fs2 * D_800CE750, var_s0->trueBasis.x.x, var_s0->trueBasis.x.y,
                               var_s0->trueBasis.x.z, var_s0->trueBasis.y.x, var_s0->trueBasis.y.y,
                               var_s0->trueBasis.y.z, var_s0->segmentPositionInfo.pos.x,
                               var_s0->segmentPositionInfo.pos.y, var_s0->segmentPositionInfo.pos.z);
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
            TextureCache_SetSwapSlotEntry(OBJECT_CACHE_INDEX(nameCardObj), 0, D_i4_8011CE50[gRacers[0].character % 30]);
        }
    }
    NAME_CARD_CHARACTER(nameCardObj) = gRacers[0].character;
}

void func_i4_8011A7B8(void) {
    if ((gQueuedGameMode == GAMEMODE_LX_MACHINE_SETTINGS) &&
        (MACHINE_MINI_STATE(Object_Get(OBJECT_MACHINE_SELECT_MACHINE)) != 0)) {
        D_800CE748 = 0.075f;
        D_800CE74C = 0.125f;
        D_800CE750 = 0.105f;
    } else {
        D_800CE748 = D_800CE74C = D_800CE750 = 0.1f;
    }
}
