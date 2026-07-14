#include "global.h"
#include "fzx_font.h"
#include ASSET_HEADER(common_assets_compressed.h)

CacheTexInfo sFont1ACacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1ATex);
CacheTexInfo sFont1BCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1BTex);
CacheTexInfo sFont1CCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1CTex);
CacheTexInfo sFont1DCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1DTex);
CacheTexInfo sFont1ECacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1ETex);
CacheTexInfo sFont1FCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1FTex);
CacheTexInfo sFont1GCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1GTex);
CacheTexInfo sFont1HCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1HTex);
CacheTexInfo sFont1ICacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1ITex);
CacheTexInfo sFont1JCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1JTex);
CacheTexInfo sFont1KCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1KTex);
CacheTexInfo sFont1LCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1LTex);
CacheTexInfo sFont1MCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1MTex);
CacheTexInfo sFont1NCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1NTex);
CacheTexInfo sFont1OCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1OTex);
CacheTexInfo sFont1PCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1PTex);
CacheTexInfo sFont1QCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1QTex);
CacheTexInfo sFont1RCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1RTex);
CacheTexInfo sFont1SCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1STex);
CacheTexInfo sFont1TCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1TTex);
CacheTexInfo sFont1UCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1UTex);
CacheTexInfo sFont1VCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1VTex);
CacheTexInfo sFont1WCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1WTex);
CacheTexInfo sFont1XCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1XTex);
CacheTexInfo sFont1YCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1YTex);
CacheTexInfo sFont1ZCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1ZTex);
CacheTexInfo sFont1CommaCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1CommaTex);
CacheTexInfo sFont1PeriodCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1PeriodTex);
CacheTexInfo sFont1PrimeCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1PrimeTex);
CacheTexInfo sFont1ExclamationMarkCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1ExclamationMarkTex);
CacheTexInfo sFont1Num0CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num0Tex);
CacheTexInfo sFont1Num1CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num1Tex);
CacheTexInfo sFont1Num2CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num2Tex);
CacheTexInfo sFont1Num3CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num3Tex);
CacheTexInfo sFont1Num4CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num4Tex);
CacheTexInfo sFont1Num5CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num5Tex);
CacheTexInfo sFont1Num6CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num6Tex);
CacheTexInfo sFont1Num7CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num7Tex);
CacheTexInfo sFont1Num8CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num8Tex);
CacheTexInfo sFont1Num9CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num9Tex);
CacheTexInfo sFont1UnderscoreCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1UnderscoreTex);
CacheTexInfo sFont1EndCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1EndTex);
CacheTexInfo sFont1BoxCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1BoxTex);
CacheTexInfo sFont1DashCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1DashTex);
CacheTexInfo sFont1AmpersandCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1AmpersandTex);

CacheTexInfo* sFont1CacheTexInfos[] = {
    sFont1ACacheTexInfo,          sFont1BCacheTexInfo,
    sFont1CCacheTexInfo,          sFont1DCacheTexInfo,
    sFont1ECacheTexInfo,          sFont1FCacheTexInfo,
    sFont1GCacheTexInfo,          sFont1HCacheTexInfo,
    sFont1ICacheTexInfo,          sFont1JCacheTexInfo,
    sFont1KCacheTexInfo,          sFont1LCacheTexInfo,
    sFont1MCacheTexInfo,          sFont1NCacheTexInfo,
    sFont1OCacheTexInfo,          sFont1PCacheTexInfo,
    sFont1QCacheTexInfo,          sFont1RCacheTexInfo,
    sFont1SCacheTexInfo,          sFont1TCacheTexInfo,
    sFont1UCacheTexInfo,          sFont1VCacheTexInfo,
    sFont1WCacheTexInfo,          sFont1XCacheTexInfo,
    sFont1YCacheTexInfo,          sFont1ZCacheTexInfo,
    sFont1PrimeCacheTexInfo,      sFont1PrimeCacheTexInfo,
    sFont1AmpersandCacheTexInfo,  sFont1PrimeCacheTexInfo,
    sFont1DashCacheTexInfo,       sFont1ExclamationMarkCacheTexInfo,
    sFont1Num0CacheTexInfo,       sFont1Num1CacheTexInfo,
    sFont1Num2CacheTexInfo,       sFont1Num3CacheTexInfo,
    sFont1Num4CacheTexInfo,       sFont1Num5CacheTexInfo,
    sFont1Num6CacheTexInfo,       sFont1Num7CacheTexInfo,
    sFont1Num8CacheTexInfo,       sFont1Num9CacheTexInfo,
    sFont1PeriodCacheTexInfo,     sFont1PeriodCacheTexInfo,
    sFont1EndCacheTexInfo,        sFont1BoxCacheTexInfo,
    sFont1UnderscoreCacheTexInfo, sFont1CommaCacheTexInfo,
};

CacheTexInfo sFont2ACacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2ATex);
CacheTexInfo sFont2BCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2BTex);
CacheTexInfo sFont2CCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2CTex);
CacheTexInfo sFont2DCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2DTex);
CacheTexInfo sFont2ECacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2ETex);
CacheTexInfo sFont2FCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2FTex);
CacheTexInfo sFont2GCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2GTex);
CacheTexInfo sFont2HCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2HTex);
CacheTexInfo sFont2ICacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2ITex);
CacheTexInfo sFont2JCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2JTex);
CacheTexInfo sFont2KCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2KTex);
CacheTexInfo sFont2LCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2LTex);
CacheTexInfo sFont2MCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2MTex);
CacheTexInfo sFont2NCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2NTex);
CacheTexInfo sFont2OCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2OTex);
CacheTexInfo sFont2PCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2PTex);
CacheTexInfo sFont2QCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2QTex);
CacheTexInfo sFont2RCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2RTex);
CacheTexInfo sFont2SCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2STex);
CacheTexInfo sFont2TCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2TTex);
CacheTexInfo sFont2UCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2UTex);
CacheTexInfo sFont2VCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2VTex);
CacheTexInfo sFont2WCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2WTex);
CacheTexInfo sFont2XCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2XTex);
CacheTexInfo sFont2YCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2YTex);
CacheTexInfo sFont2ZCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2ZTex);
CacheTexInfo sFont2CommaCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2CommaTex);
CacheTexInfo sFont2PeriodCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2PeriodTex);
CacheTexInfo sFont2PrimeCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2PrimeTex);
CacheTexInfo sFont2DashCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2DashTex);
CacheTexInfo sFont2KgCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2KgTex);
CacheTexInfo sFont2AmpersandCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2AmpersandTex);
CacheTexInfo sFont2Num0CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num0Tex);
CacheTexInfo sFont2Num1CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num1Tex);
CacheTexInfo sFont2Num2CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num2Tex);
CacheTexInfo sFont2Num3CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num3Tex);
CacheTexInfo sFont2Num4CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num4Tex);
CacheTexInfo sFont2Num5CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num5Tex);
CacheTexInfo sFont2Num6CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num6Tex);
CacheTexInfo sFont2Num7CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num7Tex);
CacheTexInfo sFont2Num8CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num8Tex);
CacheTexInfo sFont2Num9CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num9Tex);

CacheTexInfo* sFont2CacheTexInfos[] = {
    sFont2ACacheTexInfo,         sFont2BCacheTexInfo,     sFont2CCacheTexInfo,      sFont2DCacheTexInfo,
    sFont2ECacheTexInfo,         sFont2FCacheTexInfo,     sFont2GCacheTexInfo,      sFont2HCacheTexInfo,
    sFont2ICacheTexInfo,         sFont2JCacheTexInfo,     sFont2KCacheTexInfo,      sFont2LCacheTexInfo,
    sFont2MCacheTexInfo,         sFont2NCacheTexInfo,     sFont2OCacheTexInfo,      sFont2PCacheTexInfo,
    sFont2QCacheTexInfo,         sFont2RCacheTexInfo,     sFont2SCacheTexInfo,      sFont2TCacheTexInfo,
    sFont2UCacheTexInfo,         sFont2VCacheTexInfo,     sFont2WCacheTexInfo,      sFont2XCacheTexInfo,
    sFont2YCacheTexInfo,         sFont2ZCacheTexInfo,     sFont2PrimeCacheTexInfo,  sFont2PrimeCacheTexInfo,
    sFont2AmpersandCacheTexInfo, sFont2PrimeCacheTexInfo, sFont2DashCacheTexInfo,   sFont2KgCacheTexInfo,
    sFont2Num0CacheTexInfo,      sFont2Num1CacheTexInfo,  sFont2Num2CacheTexInfo,   sFont2Num3CacheTexInfo,
    sFont2Num4CacheTexInfo,      sFont2Num5CacheTexInfo,  sFont2Num6CacheTexInfo,   sFont2Num7CacheTexInfo,
    sFont2Num8CacheTexInfo,      sFont2Num9CacheTexInfo,  sFont2PeriodCacheTexInfo, sFont2PeriodCacheTexInfo,
    sFont2PeriodCacheTexInfo,    sFont2CommaCacheTexInfo, sFont2CommaCacheTexInfo,  sFont2CommaCacheTexInfo,
};

CacheTexInfo sFont3ACacheTexInfo[] = COMP_TEX_INFO(4, aFont3ATex, 0);
CacheTexInfo sFont3BCacheTexInfo[] = COMP_TEX_INFO(4, aFont3BTex, 0);
CacheTexInfo sFont3CCacheTexInfo[] = COMP_TEX_INFO(4, aFont3CTex, 0);
CacheTexInfo sFont3DCacheTexInfo[] = COMP_TEX_INFO(4, aFont3DTex, 0);
CacheTexInfo sFont3ECacheTexInfo[] = COMP_TEX_INFO(4, aFont3ETex, 0);
CacheTexInfo sFont3FCacheTexInfo[] = COMP_TEX_INFO(4, aFont3FTex, 0);
CacheTexInfo sFont3GCacheTexInfo[] = COMP_TEX_INFO(4, aFont3GTex, 0);
CacheTexInfo sFont3HCacheTexInfo[] = COMP_TEX_INFO(4, aFont3HTex, 0);
CacheTexInfo sFont3ICacheTexInfo[] = COMP_TEX_INFO(4, aFont3ITex, 0);
CacheTexInfo sFont3JCacheTexInfo[] = COMP_TEX_INFO(4, aFont3JTex, 0);
CacheTexInfo sFont3KCacheTexInfo[] = COMP_TEX_INFO(4, aFont3KTex, 0);
CacheTexInfo sFont3LCacheTexInfo[] = COMP_TEX_INFO(4, aFont3LTex, 0);
CacheTexInfo sFont3MCacheTexInfo[] = COMP_TEX_INFO(4, aFont3MTex, 0);
CacheTexInfo sFont3NCacheTexInfo[] = COMP_TEX_INFO(4, aFont3NTex, 0);
CacheTexInfo sFont3OCacheTexInfo[] = COMP_TEX_INFO(4, aFont3OTex, 0);
CacheTexInfo sFont3PCacheTexInfo[] = COMP_TEX_INFO(4, aFont3PTex, 0);
CacheTexInfo sFont3QCacheTexInfo[] = COMP_TEX_INFO(4, aFont3QTex, 0);
CacheTexInfo sFont3RCacheTexInfo[] = COMP_TEX_INFO(4, aFont3RTex, 0);
CacheTexInfo sFont3SCacheTexInfo[] = COMP_TEX_INFO(4, aFont3STex, 0);
CacheTexInfo sFont3TCacheTexInfo[] = COMP_TEX_INFO(4, aFont3TTex, 0);
CacheTexInfo sFont3UCacheTexInfo[] = COMP_TEX_INFO(4, aFont3UTex, 0);
CacheTexInfo sFont3VCacheTexInfo[] = COMP_TEX_INFO(4, aFont3VTex, 0);
CacheTexInfo sFont3WCacheTexInfo[] = COMP_TEX_INFO(4, aFont3WTex, 0);
CacheTexInfo sFont3XCacheTexInfo[] = COMP_TEX_INFO(4, aFont3XTex, 0);
CacheTexInfo sFont3YCacheTexInfo[] = COMP_TEX_INFO(4, aFont3YTex, 0);
CacheTexInfo sFont3ZCacheTexInfo[] = COMP_TEX_INFO(4, aFont3ZTex, 0);
CacheTexInfo sFont3AlphaCacheTexInfo[] = COMP_TEX_INFO(4, aFont3AlphaTex, 0);
CacheTexInfo sFont3BetaCacheTexInfo[] = COMP_TEX_INFO(4, aFont3BetaTex, 0);
CacheTexInfo sFont3GammaCacheTexInfo[] = COMP_TEX_INFO(4, aFont3GammaTex, 0);
CacheTexInfo sFont3PrimeCacheTexInfo[] = COMP_TEX_INFO(4, aFont3PrimeTex, 0);
CacheTexInfo sFont3EllipsisCacheTexInfo[] = COMP_TEX_INFO(4, aFont3EllipsisTex, 0);
CacheTexInfo sFont3ColonCacheTexInfo[] = COMP_TEX_INFO(4, aFont3ColonTex, 0);
CacheTexInfo sFont3PeriodCacheTexInfo[] = COMP_TEX_INFO(4, aFont3PeriodTex, 0);
CacheTexInfo sFont3AmpersandCacheTexInfo[] = COMP_TEX_INFO(4, aFont3AmpersandTex, 0);
CacheTexInfo sFont3CommaCacheTexInfo[] = COMP_TEX_INFO(4, aFont3CommaTex, 0);

CacheTexInfo sFont3DashCacheTexInfo[] = COMP_TEX_INFO(4, aFont3DashTex, 0);
CacheTexInfo sFont3Num0CacheTexInfo[] = COMP_TEX_INFO(4, aFont3Num0Tex, 0);
CacheTexInfo sFont3Num1CacheTexInfo[] = COMP_TEX_INFO(4, aFont3Num1Tex, 0);
CacheTexInfo sFont3Num2CacheTexInfo[] = COMP_TEX_INFO(4, aFont3Num2Tex, 0);
CacheTexInfo sFont3Num3CacheTexInfo[] = COMP_TEX_INFO(4, aFont3Num3Tex, 0);
CacheTexInfo sFont3Num4CacheTexInfo[] = COMP_TEX_INFO(4, aFont3Num4Tex, 0);
CacheTexInfo sFont3Num5CacheTexInfo[] = COMP_TEX_INFO(4, aFont3Num5Tex, 0);
CacheTexInfo sFont3Num6CacheTexInfo[] = COMP_TEX_INFO(4, aFont3Num6Tex, 0);
CacheTexInfo sFont3Num7CacheTexInfo[] = COMP_TEX_INFO(4, aFont3Num7Tex, 0);
CacheTexInfo sFont3Num8CacheTexInfo[] = COMP_TEX_INFO(4, aFont3Num8Tex, 0);
CacheTexInfo sFont3Num9CacheTexInfo[] = COMP_TEX_INFO(4, aFont3Num9Tex, 0);

CacheTexInfo* sFont3CacheTexInfos[] = {
    sFont3ACacheTexInfo,         sFont3BCacheTexInfo,    sFont3CCacheTexInfo,     sFont3DCacheTexInfo,
    sFont3ECacheTexInfo,         sFont3FCacheTexInfo,    sFont3GCacheTexInfo,     sFont3HCacheTexInfo,
    sFont3ICacheTexInfo,         sFont3JCacheTexInfo,    sFont3KCacheTexInfo,     sFont3LCacheTexInfo,
    sFont3MCacheTexInfo,         sFont3NCacheTexInfo,    sFont3OCacheTexInfo,     sFont3PCacheTexInfo,
    sFont3QCacheTexInfo,         sFont3RCacheTexInfo,    sFont3SCacheTexInfo,     sFont3TCacheTexInfo,
    sFont3UCacheTexInfo,         sFont3VCacheTexInfo,    sFont3WCacheTexInfo,     sFont3XCacheTexInfo,
    sFont3YCacheTexInfo,         sFont3ZCacheTexInfo,    sFont3PrimeCacheTexInfo, sFont3ACacheTexInfo,
    sFont3AmpersandCacheTexInfo, sFont3ACacheTexInfo,    sFont3DashCacheTexInfo,  sFont3ACacheTexInfo,
    sFont3Num0CacheTexInfo,      sFont3Num1CacheTexInfo, sFont3Num2CacheTexInfo,  sFont3Num3CacheTexInfo,
    sFont3Num4CacheTexInfo,      sFont3Num5CacheTexInfo, sFont3Num6CacheTexInfo,  sFont3Num7CacheTexInfo,
    sFont3Num8CacheTexInfo,      sFont3Num9CacheTexInfo, sFont3ColonCacheTexInfo, sFont3PeriodCacheTexInfo,
    sFont3EllipsisCacheTexInfo,  sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3CommaCacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3AlphaCacheTexInfo,     sFont3BetaCacheTexInfo, sFont3GammaCacheTexInfo, sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3GammaCacheTexInfo, sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,    sFont3ACacheTexInfo,     sFont3ACacheTexInfo,
    sFont3ACacheTexInfo,         sFont3ACacheTexInfo,
};

//! @bug These textures actually have width 16 and height 8.
// They instead should be cropped or reformatted rather than setting the width here
CacheTexInfo sFont4ACacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4ATex, 8, TEX_HEIGHT(aFont4ATex), 0);
CacheTexInfo sFont4DCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4DTex, 8, TEX_HEIGHT(aFont4DTex), 0);
CacheTexInfo sFont4ECacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4ETex, 8, TEX_HEIGHT(aFont4ETex), 0);
CacheTexInfo sFont4MCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4MTex, 8, TEX_HEIGHT(aFont4MTex), 0);
CacheTexInfo sFont4AmpersandCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4AmpersandTex, 8, TEX_HEIGHT(aFont4AmpersandTex), 0);
#ifndef VERSION_JP
CacheTexInfo sFont4BCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4BTex, 8, TEX_HEIGHT(aFont4BTex), 0);
CacheTexInfo sFont4CCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4CTex, 8, TEX_HEIGHT(aFont4CTex), 0);
CacheTexInfo sFont4FCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4FTex, 8, TEX_HEIGHT(aFont4FTex), 0);
CacheTexInfo sFont4GCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4GTex, 8, TEX_HEIGHT(aFont4GTex), 0);
CacheTexInfo sFont4HCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4HTex, 8, TEX_HEIGHT(aFont4HTex), 0);
CacheTexInfo sFont4ICacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4ITex, 8, TEX_HEIGHT(aFont4ITex), 0);
CacheTexInfo sFont4JCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4JTex, 8, TEX_HEIGHT(aFont4JTex), 0);
CacheTexInfo sFont4KCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4KTex, 8, TEX_HEIGHT(aFont4KTex), 0);
CacheTexInfo sFont4LCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4LTex, 8, TEX_HEIGHT(aFont4LTex), 0);
CacheTexInfo sFont4NCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4NTex, 8, TEX_HEIGHT(aFont4NTex), 0);
CacheTexInfo sFont4OCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4OTex, 8, TEX_HEIGHT(aFont4OTex), 0);
CacheTexInfo sFont4PCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4PTex, 8, TEX_HEIGHT(aFont4PTex), 0);
CacheTexInfo sFont4QCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4QTex, 8, TEX_HEIGHT(aFont4QTex), 0);
CacheTexInfo sFont4RCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4RTex, 8, TEX_HEIGHT(aFont4RTex), 0);
CacheTexInfo sFont4SCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4STex, 8, TEX_HEIGHT(aFont4STex), 0);
CacheTexInfo sFont4TCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4TTex, 8, TEX_HEIGHT(aFont4TTex), 0);
CacheTexInfo sFont4UCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4UTex, 8, TEX_HEIGHT(aFont4UTex), 0);
CacheTexInfo sFont4VCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4VTex, 8, TEX_HEIGHT(aFont4VTex), 0);
CacheTexInfo sFont4WCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4WTex, 8, TEX_HEIGHT(aFont4WTex), 0);
CacheTexInfo sFont4XCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4XTex, 8, TEX_HEIGHT(aFont4XTex), 0);
CacheTexInfo sFont4YCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4YTex, 8, TEX_HEIGHT(aFont4YTex), 0);
CacheTexInfo sFont4ZCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4ZTex, 8, TEX_HEIGHT(aFont4ZTex), 0);
CacheTexInfo sFont4LowerCCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4LowerCTex, 8, TEX_HEIGHT(aFont4LowerCTex), 0);
CacheTexInfo sFont4LowerRCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4LowerRTex, 8, TEX_HEIGHT(aFont4LowerRTex), 0);
CacheTexInfo sFont4LowerSCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4LowerSTex, 8, TEX_HEIGHT(aFont4LowerSTex), 0);
CacheTexInfo sFont4PeriodCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4PeriodTex, 8, TEX_HEIGHT(aFont4PeriodTex), 0);
#endif
CacheTexInfo sFont4KatakanaACacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaATex, 8, TEX_HEIGHT(aFont4KatakanaATex), 0);
CacheTexInfo sFont4KatakanaICacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaITex, 8, TEX_HEIGHT(aFont4KatakanaITex), 0);
CacheTexInfo sFont4KatakanaUCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaUTex, 8, TEX_HEIGHT(aFont4KatakanaUTex), 0);
CacheTexInfo sFont4KatakanaECacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaETex, 8, TEX_HEIGHT(aFont4KatakanaETex), 0);
CacheTexInfo sFont4KatakanaOCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaOTex, 8, TEX_HEIGHT(aFont4KatakanaOTex), 0);
CacheTexInfo sFont4KatakanaKaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaKaTex, 8, TEX_HEIGHT(aFont4KatakanaKaTex), 0);
CacheTexInfo sFont4KatakanaKiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaKiTex, 8, TEX_HEIGHT(aFont4KatakanaKiTex), 0);
CacheTexInfo sFont4KatakanaKuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaKuTex, 8, TEX_HEIGHT(aFont4KatakanaKuTex), 0);
CacheTexInfo sFont4KatakanaKeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaKeTex, 8, TEX_HEIGHT(aFont4KatakanaKeTex), 0);
CacheTexInfo sFont4KatakanaKoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaKoTex, 8, TEX_HEIGHT(aFont4KatakanaKoTex), 0);
CacheTexInfo sFont4KatakanaSaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaSaTex, 8, TEX_HEIGHT(aFont4KatakanaSaTex), 0);
CacheTexInfo sFont4KatakanaShiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaShiTex, 8, TEX_HEIGHT(aFont4KatakanaShiTex), 0);
CacheTexInfo sFont4KatakanaSuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaSuTex, 8, TEX_HEIGHT(aFont4KatakanaSuTex), 0);
CacheTexInfo sFont4KatakanaSeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaSeTex, 8, TEX_HEIGHT(aFont4KatakanaSeTex), 0);
CacheTexInfo sFont4KatakanaSoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaSoTex, 8, TEX_HEIGHT(aFont4KatakanaSoTex), 0);
CacheTexInfo sFont4KatakanaTaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaTaTex, 8, TEX_HEIGHT(aFont4KatakanaTaTex), 0);
CacheTexInfo sFont4KatakanaChiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaChiTex, 8, TEX_HEIGHT(aFont4KatakanaChiTex), 0);
CacheTexInfo sFont4KatakanaTsuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaTsuTex, 8, TEX_HEIGHT(aFont4KatakanaTsuTex), 0);
CacheTexInfo sFont4KatakanaTeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaTeTex, 8, TEX_HEIGHT(aFont4KatakanaTeTex), 0);
CacheTexInfo sFont4KatakanaToCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaToTex, 8, TEX_HEIGHT(aFont4KatakanaToTex), 0);
CacheTexInfo sFont4KatakanaSoukonCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaSoukonTex, 8, TEX_HEIGHT(aFont4KatakanaSoukonTex), 0);
CacheTexInfo sFont4KatakanaNaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNaTex, 8, TEX_HEIGHT(aFont4KatakanaNaTex), 0);
CacheTexInfo sFont4KatakanaNiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNiTex, 8, TEX_HEIGHT(aFont4KatakanaNiTex), 0);
CacheTexInfo sFont4KatakanaNuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNuTex, 8, TEX_HEIGHT(aFont4KatakanaNuTex), 0);
CacheTexInfo sFont4KatakanaNeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNeTex, 8, TEX_HEIGHT(aFont4KatakanaNeTex), 0);
CacheTexInfo sFont4KatakanaNoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNoTex, 8, TEX_HEIGHT(aFont4KatakanaNoTex), 0);
CacheTexInfo sFont4KatakanaHaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaHaTex, 8, TEX_HEIGHT(aFont4KatakanaHaTex), 0);
CacheTexInfo sFont4KatakanaHiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaHiTex, 8, TEX_HEIGHT(aFont4KatakanaHiTex), 0);
CacheTexInfo sFont4KatakanaFuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaFuTex, 8, TEX_HEIGHT(aFont4KatakanaFuTex), 0);
CacheTexInfo sFont4KatakanaHeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaHeTex, 8, TEX_HEIGHT(aFont4KatakanaHeTex), 0);
CacheTexInfo sFont4KatakanaHoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaHoTex, 8, TEX_HEIGHT(aFont4KatakanaHoTex), 0);
CacheTexInfo sFont4KatakanaMaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaMaTex, 8, TEX_HEIGHT(aFont4KatakanaMaTex), 0);
CacheTexInfo sFont4KatakanaMiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaMiTex, 8, TEX_HEIGHT(aFont4KatakanaMiTex), 0);
CacheTexInfo sFont4KatakanaMuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaMuTex, 8, TEX_HEIGHT(aFont4KatakanaMuTex), 0);
CacheTexInfo sFont4KatakanaMeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaMeTex, 8, TEX_HEIGHT(aFont4KatakanaMeTex), 0);
CacheTexInfo sFont4KatakanaMoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaMoTex, 8, TEX_HEIGHT(aFont4KatakanaMoTex), 0);
CacheTexInfo sFont4KatakanaYaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYaTex, 8, TEX_HEIGHT(aFont4KatakanaYaTex), 0);
CacheTexInfo sFont4KatakanaYuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYuTex, 8, TEX_HEIGHT(aFont4KatakanaYuTex), 0);
CacheTexInfo sFont4KatakanaYoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYoTex, 8, TEX_HEIGHT(aFont4KatakanaYoTex), 0);
CacheTexInfo sFont4KatakanaYoonYaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYoonYaTex, 8, TEX_HEIGHT(aFont4KatakanaYoonYaTex), 0);
CacheTexInfo sFont4KatakanaYoonYuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYoonYuTex, 8, TEX_HEIGHT(aFont4KatakanaYoonYuTex), 0);
CacheTexInfo sFont4KatakanaYoonYoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYoonYoTex, 8, TEX_HEIGHT(aFont4KatakanaYoonYoTex), 0);
CacheTexInfo sFont4KatakanaRaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaRaTex, 8, TEX_HEIGHT(aFont4KatakanaRaTex), 0);
CacheTexInfo sFont4KatakanaRiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaRiTex, 8, TEX_HEIGHT(aFont4KatakanaRiTex), 0);
CacheTexInfo sFont4KatakanaRuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaRuTex, 8, TEX_HEIGHT(aFont4KatakanaRuTex), 0);
CacheTexInfo sFont4KatakanaReCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaReTex, 8, TEX_HEIGHT(aFont4KatakanaReTex), 0);
CacheTexInfo sFont4KatakanaRoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaRoTex, 8, TEX_HEIGHT(aFont4KatakanaRoTex), 0);
CacheTexInfo sFont4KatakanaWaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaWaTex, 8, TEX_HEIGHT(aFont4KatakanaWaTex), 0);
CacheTexInfo sFont4KatakanaWoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaWoTex, 8, TEX_HEIGHT(aFont4KatakanaWoTex), 0);
CacheTexInfo sFont4KatakanaNCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNTex, 8, TEX_HEIGHT(aFont4KatakanaNTex), 0);
CacheTexInfo sFont4KatakanaGaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaGaTex, 8, TEX_HEIGHT(aFont4KatakanaGaTex), 0);
CacheTexInfo sFont4KatakanaGiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaGiTex, 8, TEX_HEIGHT(aFont4KatakanaGiTex), 0);
CacheTexInfo sFont4KatakanaGuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaGuTex, 8, TEX_HEIGHT(aFont4KatakanaGuTex), 0);
CacheTexInfo sFont4KatakanaGeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaGeTex, 8, TEX_HEIGHT(aFont4KatakanaGeTex), 0);
CacheTexInfo sFont4KatakanaGoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaGoTex, 8, TEX_HEIGHT(aFont4KatakanaGoTex), 0);
CacheTexInfo sFont4KatakanaZaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaZaTex, 8, TEX_HEIGHT(aFont4KatakanaZaTex), 0);
CacheTexInfo sFont4KatakanaJiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaJiTex, 8, TEX_HEIGHT(aFont4KatakanaJiTex), 0);
CacheTexInfo sFont4KatakanaZuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaZuTex, 8, TEX_HEIGHT(aFont4KatakanaZuTex), 0);
CacheTexInfo sFont4KatakanaZeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaZeTex, 8, TEX_HEIGHT(aFont4KatakanaZeTex), 0);
CacheTexInfo sFont4KatakanaZoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaZoTex, 8, TEX_HEIGHT(aFont4KatakanaZoTex), 0);
CacheTexInfo sFont4KatakanaDaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDaTex, 8, TEX_HEIGHT(aFont4KatakanaDaTex), 0);
CacheTexInfo sFont4KatakanaDjiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDjiTex, 8, TEX_HEIGHT(aFont4KatakanaDjiTex), 0);
CacheTexInfo sFont4KatakanaDzuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDzuTex, 8, TEX_HEIGHT(aFont4KatakanaDzuTex), 0);
CacheTexInfo sFont4KatakanaDeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDeTex, 8, TEX_HEIGHT(aFont4KatakanaDeTex), 0);
CacheTexInfo sFont4KatakanaDoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDoTex, 8, TEX_HEIGHT(aFont4KatakanaDoTex), 0);
CacheTexInfo sFont4KatakanaBaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaBaTex, 8, TEX_HEIGHT(aFont4KatakanaBaTex), 0);
CacheTexInfo sFont4KatakanaBiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaBiTex, 8, TEX_HEIGHT(aFont4KatakanaBiTex), 0);
CacheTexInfo sFont4KatakanaBuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaBuTex, 8, TEX_HEIGHT(aFont4KatakanaBuTex), 0);
CacheTexInfo sFont4KatakanaBeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaBeTex, 8, TEX_HEIGHT(aFont4KatakanaBeTex), 0);
CacheTexInfo sFont4KatakanaBoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaBoTex, 8, TEX_HEIGHT(aFont4KatakanaBoTex), 0);
CacheTexInfo sFont4KatakanaPaCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaPaTex, 8, TEX_HEIGHT(aFont4KatakanaPaTex), 0);
CacheTexInfo sFont4KatakanaPiCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaPiTex, 8, TEX_HEIGHT(aFont4KatakanaPiTex), 0);
CacheTexInfo sFont4KatakanaPuCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaPuTex, 8, TEX_HEIGHT(aFont4KatakanaPuTex), 0);
CacheTexInfo sFont4KatakanaPeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaPeTex, 8, TEX_HEIGHT(aFont4KatakanaPeTex), 0);
CacheTexInfo sFont4KatakanaPoCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaPoTex, 8, TEX_HEIGHT(aFont4KatakanaPoTex), 0);
CacheTexInfo sFont4KatakanaDigraphACacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDigraphATex, 8, TEX_HEIGHT(aFont4KatakanaDigraphATex), 0);
CacheTexInfo sFont4KatakanaDigraphICacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDigraphITex, 8, TEX_HEIGHT(aFont4KatakanaDigraphITex), 0);
CacheTexInfo sFont4KatakanaDigraphECacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDigraphETex, 8, TEX_HEIGHT(aFont4KatakanaDigraphETex), 0);
CacheTexInfo sFont4DashCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4DashTex, 8, TEX_HEIGHT(aFont4DashTex), 0);
CacheTexInfo sFont4Num0CacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num0Tex, 8, TEX_HEIGHT(aFont4Num0Tex), 0);
CacheTexInfo sFont4Num1CacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num1Tex, 8, TEX_HEIGHT(aFont4Num1Tex), 0);
CacheTexInfo sFont4Num2CacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num2Tex, 8, TEX_HEIGHT(aFont4Num2Tex), 0);
CacheTexInfo sFont4Num3CacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num3Tex, 8, TEX_HEIGHT(aFont4Num3Tex), 0);
CacheTexInfo sFont4Num4CacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num4Tex, 8, TEX_HEIGHT(aFont4Num4Tex), 0);
CacheTexInfo sFont4Num5CacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num5Tex, 8, TEX_HEIGHT(aFont4Num5Tex), 0);
CacheTexInfo sFont4Num6CacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num6Tex, 8, TEX_HEIGHT(aFont4Num6Tex), 0);
CacheTexInfo sFont4Num7CacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num7Tex, 8, TEX_HEIGHT(aFont4Num7Tex), 0);
CacheTexInfo sFont4Num8CacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num8Tex, 8, TEX_HEIGHT(aFont4Num8Tex), 0);
CacheTexInfo sFont4Num9CacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num9Tex, 8, TEX_HEIGHT(aFont4Num9Tex), 0);
CacheTexInfo sFont4PrimeCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4PrimeTex, 8, TEX_HEIGHT(aFont4PrimeTex), 0);
CacheTexInfo sFont4DoublePrimeCacheTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4DoublePrimeTex, 8, TEX_HEIGHT(aFont4DoublePrimeTex), 0);
CacheTexInfo sFont4STCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4STTex, 8, TEX_HEIGHT(aFont4STTex), 0);
CacheTexInfo sFont4NDCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4NDTex, 8, TEX_HEIGHT(aFont4NDTex), 0);
CacheTexInfo sFont4RDCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4RDTex, 8, TEX_HEIGHT(aFont4RDTex), 0);
CacheTexInfo sFont4THCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4THTex, 8, TEX_HEIGHT(aFont4THTex), 0);
CacheTexInfo sFont4PlusCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4PlusTex, 8, TEX_HEIGHT(aFont4PlusTex), 0);
CacheTexInfo sFont4MinusCacheTexInfo[] = COMP_TEX_INFO_WH(4, aFont4MinusTex, 8, TEX_HEIGHT(aFont4MinusTex), 0);
CacheTexInfo sFont4PointsCacheTexInfo[] = COMP_TEX_INFO(4, aFont4PointsTex, 0);

#ifdef VERSION_JP
CacheTexInfo* sFont4CacheTexInfos[] = {
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4DCacheTexInfo,
    sFont4ECacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4MCacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4PrimeCacheTexInfo,
    sFont4DoublePrimeCacheTexInfo,
    sFont4AmpersandCacheTexInfo,
    sFont4PlusCacheTexInfo,
    sFont4MinusCacheTexInfo,
    sFont4PointsCacheTexInfo,
    sFont4Num0CacheTexInfo,
    sFont4Num1CacheTexInfo,
    sFont4Num2CacheTexInfo,
    sFont4Num3CacheTexInfo,
    sFont4Num4CacheTexInfo,
    sFont4Num5CacheTexInfo,
    sFont4Num6CacheTexInfo,
    sFont4Num7CacheTexInfo,
    sFont4Num8CacheTexInfo,
    sFont4Num9CacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4KatakanaDigraphACacheTexInfo,
    sFont4KatakanaACacheTexInfo,
    sFont4KatakanaDigraphICacheTexInfo,
    sFont4KatakanaICacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaDigraphECacheTexInfo,
    sFont4KatakanaECacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaKaCacheTexInfo,
    sFont4KatakanaGaCacheTexInfo,
    sFont4KatakanaKiCacheTexInfo,
    sFont4KatakanaGiCacheTexInfo,
    sFont4KatakanaKuCacheTexInfo,
    sFont4KatakanaGuCacheTexInfo,
    sFont4KatakanaKeCacheTexInfo,
    sFont4KatakanaGeCacheTexInfo,
    sFont4KatakanaKoCacheTexInfo,
    sFont4KatakanaGoCacheTexInfo,
    sFont4KatakanaSaCacheTexInfo,
    sFont4KatakanaZaCacheTexInfo,
    sFont4KatakanaShiCacheTexInfo,
    sFont4KatakanaJiCacheTexInfo,
    sFont4KatakanaSuCacheTexInfo,
    sFont4KatakanaZuCacheTexInfo,
    sFont4KatakanaSeCacheTexInfo,
    sFont4KatakanaZeCacheTexInfo,
    sFont4KatakanaSoCacheTexInfo,
    sFont4KatakanaZoCacheTexInfo,
    sFont4KatakanaTaCacheTexInfo,
    sFont4KatakanaDaCacheTexInfo,
    sFont4KatakanaChiCacheTexInfo,
    sFont4KatakanaDjiCacheTexInfo,
    sFont4KatakanaSoukonCacheTexInfo,
    sFont4KatakanaTsuCacheTexInfo,
    sFont4KatakanaDzuCacheTexInfo,
    sFont4KatakanaTeCacheTexInfo,
    sFont4KatakanaDeCacheTexInfo,
    sFont4KatakanaToCacheTexInfo,
    sFont4KatakanaDoCacheTexInfo,
    sFont4KatakanaNaCacheTexInfo,
    sFont4KatakanaNiCacheTexInfo,
    sFont4KatakanaNuCacheTexInfo,
    sFont4KatakanaNeCacheTexInfo,
    sFont4KatakanaNoCacheTexInfo,
    sFont4KatakanaHaCacheTexInfo,
    sFont4KatakanaBaCacheTexInfo,
    sFont4KatakanaPaCacheTexInfo,
    sFont4KatakanaHiCacheTexInfo,
    sFont4KatakanaBiCacheTexInfo,
    sFont4KatakanaPiCacheTexInfo,
    sFont4KatakanaFuCacheTexInfo,
    sFont4KatakanaBuCacheTexInfo,
    sFont4KatakanaPuCacheTexInfo,
    sFont4KatakanaHeCacheTexInfo,
    sFont4KatakanaBeCacheTexInfo,
    sFont4KatakanaPeCacheTexInfo,
    sFont4KatakanaHoCacheTexInfo,
    sFont4KatakanaBoCacheTexInfo,
    sFont4KatakanaPoCacheTexInfo,
    sFont4KatakanaMaCacheTexInfo,
    sFont4KatakanaMiCacheTexInfo,
    sFont4KatakanaMuCacheTexInfo,
    sFont4KatakanaMeCacheTexInfo,
    sFont4KatakanaMoCacheTexInfo,
    sFont4KatakanaYoonYaCacheTexInfo,
    sFont4KatakanaYaCacheTexInfo,
    sFont4KatakanaYoonYuCacheTexInfo,
    sFont4KatakanaYuCacheTexInfo,
    sFont4KatakanaYoonYoCacheTexInfo,
    sFont4KatakanaYoCacheTexInfo,
    sFont4KatakanaRaCacheTexInfo,
    sFont4KatakanaRiCacheTexInfo,
    sFont4KatakanaRuCacheTexInfo,
    sFont4KatakanaReCacheTexInfo,
    sFont4KatakanaRoCacheTexInfo,
    sFont4KatakanaWaCacheTexInfo,
    sFont4KatakanaWoCacheTexInfo,
    sFont4KatakanaNCacheTexInfo,
    sFont4KatakanaDigraphACacheTexInfo,
    sFont4KatakanaACacheTexInfo,
    sFont4KatakanaDigraphICacheTexInfo,
    sFont4KatakanaICacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaDigraphECacheTexInfo,
    sFont4KatakanaECacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaKaCacheTexInfo,
    sFont4KatakanaGaCacheTexInfo,
    sFont4KatakanaKiCacheTexInfo,
    sFont4KatakanaGiCacheTexInfo,
    sFont4KatakanaKuCacheTexInfo,
    sFont4KatakanaGuCacheTexInfo,
    sFont4KatakanaKeCacheTexInfo,
    sFont4KatakanaGeCacheTexInfo,
    sFont4KatakanaKoCacheTexInfo,
    sFont4KatakanaGoCacheTexInfo,
    sFont4KatakanaSaCacheTexInfo,
    sFont4KatakanaZaCacheTexInfo,
    sFont4KatakanaShiCacheTexInfo,
    sFont4KatakanaJiCacheTexInfo,
    sFont4KatakanaSuCacheTexInfo,
    sFont4KatakanaZuCacheTexInfo,
    sFont4KatakanaSeCacheTexInfo,
    sFont4KatakanaZeCacheTexInfo,
    sFont4KatakanaSoCacheTexInfo,
    sFont4KatakanaZoCacheTexInfo,
    sFont4KatakanaTaCacheTexInfo,
    sFont4KatakanaDaCacheTexInfo,
    sFont4KatakanaChiCacheTexInfo,
    sFont4KatakanaDjiCacheTexInfo,
    sFont4KatakanaSoukonCacheTexInfo,
    sFont4KatakanaTsuCacheTexInfo,
    sFont4KatakanaDzuCacheTexInfo,
    sFont4KatakanaTeCacheTexInfo,
    sFont4KatakanaDeCacheTexInfo,
    sFont4KatakanaToCacheTexInfo,
    sFont4KatakanaDoCacheTexInfo,
    sFont4KatakanaNaCacheTexInfo,
    sFont4KatakanaNiCacheTexInfo,
    sFont4KatakanaNuCacheTexInfo,
    sFont4KatakanaNeCacheTexInfo,
    sFont4KatakanaNoCacheTexInfo,
    sFont4KatakanaHaCacheTexInfo,
    sFont4KatakanaBaCacheTexInfo,
    sFont4KatakanaPaCacheTexInfo,
    sFont4KatakanaHiCacheTexInfo,
    sFont4KatakanaBiCacheTexInfo,
    sFont4KatakanaPiCacheTexInfo,
    sFont4KatakanaFuCacheTexInfo,
    sFont4KatakanaBuCacheTexInfo,
    sFont4KatakanaPuCacheTexInfo,
    sFont4KatakanaHeCacheTexInfo,
    sFont4KatakanaBeCacheTexInfo,
    sFont4KatakanaPeCacheTexInfo,
    sFont4KatakanaHoCacheTexInfo,
    sFont4KatakanaBoCacheTexInfo,
    sFont4KatakanaPoCacheTexInfo,
    sFont4KatakanaMaCacheTexInfo,
    sFont4KatakanaMiCacheTexInfo,
    sFont4KatakanaMuCacheTexInfo,
    sFont4KatakanaMeCacheTexInfo,
    sFont4KatakanaMoCacheTexInfo,
    sFont4KatakanaYoonYaCacheTexInfo,
    sFont4KatakanaYaCacheTexInfo,
    sFont4KatakanaYoonYuCacheTexInfo,
    sFont4KatakanaYuCacheTexInfo,
    sFont4KatakanaYoonYoCacheTexInfo,
    sFont4KatakanaYoCacheTexInfo,
    sFont4KatakanaRaCacheTexInfo,
    sFont4KatakanaRiCacheTexInfo,
    sFont4KatakanaRuCacheTexInfo,
    sFont4KatakanaReCacheTexInfo,
    sFont4KatakanaRoCacheTexInfo,
    sFont4KatakanaWaCacheTexInfo,
    sFont4KatakanaWoCacheTexInfo,
    sFont4KatakanaNCacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4NDCacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4RDCacheTexInfo,
    sFont4STCacheTexInfo,
    sFont4THCacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4DashCacheTexInfo,
};
#else
CacheTexInfo* sFont4CacheTexInfos[] = {
    sFont4ACacheTexInfo,
    sFont4BCacheTexInfo,
    sFont4CCacheTexInfo,
    sFont4DCacheTexInfo,
    sFont4ECacheTexInfo,
    sFont4FCacheTexInfo,
    sFont4GCacheTexInfo,
    sFont4HCacheTexInfo,
    sFont4ICacheTexInfo,
    sFont4JCacheTexInfo,
    sFont4KCacheTexInfo,
    sFont4LCacheTexInfo,
    sFont4MCacheTexInfo,
    sFont4NCacheTexInfo,
    sFont4OCacheTexInfo,
    sFont4PCacheTexInfo,
    sFont4QCacheTexInfo,
    sFont4RCacheTexInfo,
    sFont4SCacheTexInfo,
    sFont4TCacheTexInfo,
    sFont4UCacheTexInfo,
    sFont4VCacheTexInfo,
    sFont4WCacheTexInfo,
    sFont4XCacheTexInfo,
    sFont4YCacheTexInfo,
    sFont4ZCacheTexInfo,
    sFont4PrimeCacheTexInfo,
    sFont4DoublePrimeCacheTexInfo,
    sFont4AmpersandCacheTexInfo,
    sFont4PlusCacheTexInfo,
    sFont4MinusCacheTexInfo,
    sFont4PointsCacheTexInfo,
    sFont4Num0CacheTexInfo,
    sFont4Num1CacheTexInfo,
    sFont4Num2CacheTexInfo,
    sFont4Num3CacheTexInfo,
    sFont4Num4CacheTexInfo,
    sFont4Num5CacheTexInfo,
    sFont4Num6CacheTexInfo,
    sFont4Num7CacheTexInfo,
    sFont4Num8CacheTexInfo,
    sFont4Num9CacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4PeriodCacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4KatakanaDigraphACacheTexInfo,
    sFont4KatakanaACacheTexInfo,
    sFont4LowerCCacheTexInfo,
    sFont4KatakanaICacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaDigraphECacheTexInfo,
    sFont4KatakanaECacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaKaCacheTexInfo,
    sFont4KatakanaGaCacheTexInfo,
    sFont4KatakanaKiCacheTexInfo,
    sFont4KatakanaGiCacheTexInfo,
    sFont4KatakanaKuCacheTexInfo,
    sFont4KatakanaGuCacheTexInfo,
    sFont4KatakanaKeCacheTexInfo,
    sFont4LowerRCacheTexInfo,
    sFont4LowerSCacheTexInfo,
    sFont4KatakanaGoCacheTexInfo,
    sFont4KatakanaSaCacheTexInfo,
    sFont4KatakanaZaCacheTexInfo,
    sFont4KatakanaShiCacheTexInfo,
    sFont4KatakanaJiCacheTexInfo,
    sFont4KatakanaSuCacheTexInfo,
    sFont4KatakanaZuCacheTexInfo,
    sFont4KatakanaSeCacheTexInfo,
    sFont4KatakanaZeCacheTexInfo,
    sFont4KatakanaSoCacheTexInfo,
    sFont4KatakanaZoCacheTexInfo,
    sFont4KatakanaTaCacheTexInfo,
    sFont4KatakanaDaCacheTexInfo,
    sFont4KatakanaChiCacheTexInfo,
    sFont4KatakanaDjiCacheTexInfo,
    sFont4KatakanaSoukonCacheTexInfo,
    sFont4KatakanaTsuCacheTexInfo,
    sFont4KatakanaDzuCacheTexInfo,
    sFont4KatakanaTeCacheTexInfo,
    sFont4KatakanaDeCacheTexInfo,
    sFont4KatakanaToCacheTexInfo,
    sFont4KatakanaDoCacheTexInfo,
    sFont4KatakanaNaCacheTexInfo,
    sFont4KatakanaNiCacheTexInfo,
    sFont4KatakanaNuCacheTexInfo,
    sFont4KatakanaNeCacheTexInfo,
    sFont4KatakanaNoCacheTexInfo,
    sFont4KatakanaHaCacheTexInfo,
    sFont4KatakanaBaCacheTexInfo,
    sFont4KatakanaPaCacheTexInfo,
    sFont4KatakanaHiCacheTexInfo,
    sFont4KatakanaBiCacheTexInfo,
    sFont4KatakanaPiCacheTexInfo,
    sFont4KatakanaFuCacheTexInfo,
    sFont4KatakanaBuCacheTexInfo,
    sFont4KatakanaPuCacheTexInfo,
    sFont4KatakanaHeCacheTexInfo,
    sFont4KatakanaBeCacheTexInfo,
    sFont4KatakanaPeCacheTexInfo,
    sFont4KatakanaHoCacheTexInfo,
    sFont4KatakanaBoCacheTexInfo,
    sFont4KatakanaPoCacheTexInfo,
    sFont4KatakanaMaCacheTexInfo,
    sFont4KatakanaMiCacheTexInfo,
    sFont4KatakanaMuCacheTexInfo,
    sFont4KatakanaMeCacheTexInfo,
    sFont4KatakanaMoCacheTexInfo,
    sFont4KatakanaYoonYaCacheTexInfo,
    sFont4KatakanaYaCacheTexInfo,
    sFont4KatakanaYoonYuCacheTexInfo,
    sFont4KatakanaYuCacheTexInfo,
    sFont4KatakanaYoonYoCacheTexInfo,
    sFont4KatakanaYoCacheTexInfo,
    sFont4KatakanaRaCacheTexInfo,
    sFont4KatakanaRiCacheTexInfo,
    sFont4KatakanaRuCacheTexInfo,
    sFont4KatakanaReCacheTexInfo,
    sFont4KatakanaRoCacheTexInfo,
    sFont4KatakanaWaCacheTexInfo,
    sFont4KatakanaWoCacheTexInfo,
    sFont4KatakanaNCacheTexInfo,
    sFont4KatakanaDigraphACacheTexInfo,
    sFont4KatakanaACacheTexInfo,
    sFont4KatakanaDigraphICacheTexInfo,
    sFont4KatakanaICacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaDigraphECacheTexInfo,
    sFont4KatakanaECacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaKaCacheTexInfo,
    sFont4KatakanaGaCacheTexInfo,
    sFont4KatakanaKiCacheTexInfo,
    sFont4KatakanaGiCacheTexInfo,
    sFont4KatakanaKuCacheTexInfo,
    sFont4KatakanaGuCacheTexInfo,
    sFont4KatakanaKeCacheTexInfo,
    sFont4KatakanaGeCacheTexInfo,
    sFont4KatakanaKoCacheTexInfo,
    sFont4KatakanaGoCacheTexInfo,
    sFont4KatakanaSaCacheTexInfo,
    sFont4KatakanaZaCacheTexInfo,
    sFont4KatakanaShiCacheTexInfo,
    sFont4KatakanaJiCacheTexInfo,
    sFont4KatakanaSuCacheTexInfo,
    sFont4KatakanaZuCacheTexInfo,
    sFont4KatakanaSeCacheTexInfo,
    sFont4KatakanaZeCacheTexInfo,
    sFont4KatakanaSoCacheTexInfo,
    sFont4KatakanaZoCacheTexInfo,
    sFont4KatakanaTaCacheTexInfo,
    sFont4KatakanaDaCacheTexInfo,
    sFont4KatakanaChiCacheTexInfo,
    sFont4KatakanaDjiCacheTexInfo,
    sFont4KatakanaSoukonCacheTexInfo,
    sFont4KatakanaTsuCacheTexInfo,
    sFont4KatakanaDzuCacheTexInfo,
    sFont4KatakanaTeCacheTexInfo,
    sFont4KatakanaDeCacheTexInfo,
    sFont4KatakanaToCacheTexInfo,
    sFont4KatakanaDoCacheTexInfo,
    sFont4KatakanaNaCacheTexInfo,
    sFont4KatakanaNiCacheTexInfo,
    sFont4KatakanaNuCacheTexInfo,
    sFont4KatakanaNeCacheTexInfo,
    sFont4KatakanaNoCacheTexInfo,
    sFont4KatakanaHaCacheTexInfo,
    sFont4KatakanaBaCacheTexInfo,
    sFont4KatakanaPaCacheTexInfo,
    sFont4KatakanaHiCacheTexInfo,
    sFont4KatakanaBiCacheTexInfo,
    sFont4KatakanaPiCacheTexInfo,
    sFont4KatakanaFuCacheTexInfo,
    sFont4KatakanaBuCacheTexInfo,
    sFont4KatakanaPuCacheTexInfo,
    sFont4KatakanaHeCacheTexInfo,
    sFont4KatakanaBeCacheTexInfo,
    sFont4KatakanaPeCacheTexInfo,
    sFont4KatakanaHoCacheTexInfo,
    sFont4KatakanaBoCacheTexInfo,
    sFont4KatakanaPoCacheTexInfo,
    sFont4KatakanaMaCacheTexInfo,
    sFont4KatakanaMiCacheTexInfo,
    sFont4KatakanaMuCacheTexInfo,
    sFont4KatakanaMeCacheTexInfo,
    sFont4KatakanaMoCacheTexInfo,
    sFont4KatakanaYoonYaCacheTexInfo,
    sFont4KatakanaYaCacheTexInfo,
    sFont4KatakanaYoonYuCacheTexInfo,
    sFont4KatakanaYuCacheTexInfo,
    sFont4KatakanaYoonYoCacheTexInfo,
    sFont4KatakanaYoCacheTexInfo,
    sFont4KatakanaRaCacheTexInfo,
    sFont4KatakanaRiCacheTexInfo,
    sFont4KatakanaRuCacheTexInfo,
    sFont4KatakanaReCacheTexInfo,
    sFont4KatakanaRoCacheTexInfo,
    sFont4KatakanaWaCacheTexInfo,
    sFont4KatakanaWoCacheTexInfo,
    sFont4KatakanaNCacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4NDCacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4RDCacheTexInfo,
    sFont4STCacheTexInfo,
    sFont4THCacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4DashCacheTexInfo,
};
#endif

CacheTexInfo sFont5Num0CacheTexInfo[] = COMP_TEX_INFO(4, aFont5Num0Tex, 0);
CacheTexInfo sFont5Num1CacheTexInfo[] = COMP_TEX_INFO(4, aFont5Num1Tex, 0);
CacheTexInfo sFont5Num2CacheTexInfo[] = COMP_TEX_INFO(4, aFont5Num2Tex, 0);
CacheTexInfo sFont5Num3CacheTexInfo[] = COMP_TEX_INFO(4, aFont5Num3Tex, 0);
CacheTexInfo sFont5Num4CacheTexInfo[] = COMP_TEX_INFO(4, aFont5Num4Tex, 0);
CacheTexInfo sFont5Num5CacheTexInfo[] = COMP_TEX_INFO(4, aFont5Num5Tex, 0);
CacheTexInfo sFont5Num6CacheTexInfo[] = COMP_TEX_INFO(4, aFont5Num6Tex, 0);
CacheTexInfo sFont5Num7CacheTexInfo[] = COMP_TEX_INFO(4, aFont5Num7Tex, 0);
CacheTexInfo sFont5Num8CacheTexInfo[] = COMP_TEX_INFO(4, aFont5Num8Tex, 0);
CacheTexInfo sFont5Num9CacheTexInfo[] = COMP_TEX_INFO(4, aFont5Num9Tex, 0);
CacheTexInfo sFont5VCacheTexInfo[] = COMP_TEX_INFO(4, aFont5VTex, 0);
CacheTexInfo sFont5OpenParenthesisCacheTexInfo[] = COMP_TEX_INFO(4, aFont5OpenParenthesisTex, 0);
CacheTexInfo sFont5CloseParenthesisCacheTexInfo[] = COMP_TEX_INFO(4, aFont5CloseParenthesisTex, 0);
CacheTexInfo sFont5STCacheTexInfo[] = COMP_TEX_INFO(4, aFont5STTex, 0);
CacheTexInfo sFont5NDCacheTexInfo[] = COMP_TEX_INFO(4, aFont5NDTex, 0);
CacheTexInfo sFont5RDCacheTexInfo[] = COMP_TEX_INFO(4, aFont5RDTex, 0);
CacheTexInfo sFont5THCacheTexInfo[] = COMP_TEX_INFO(4, aFont5THTex, 0);
CacheTexInfo sFont5PlusCacheTexInfo[] = COMP_TEX_INFO(4, aFont5PlusTex, 0);
CacheTexInfo sFont5UpArrowCacheTexInfo[] = COMP_TEX_INFO(4, aFont5UpArrowTex, 0);
CacheTexInfo sFont5DownArrowCacheTexInfo[] = COMP_TEX_INFO(4, aFont5DownArrowTex, 0);
CacheTexInfo sFont5SideArrowCacheTexInfo[] = COMP_TEX_INFO(4, aFont5SideArrowTex, 0);
CacheTexInfo sFont5PointsCacheTexInfo[] = COMP_TEX_INFO_DEF(20, aFont5PointsTex);
CacheTexInfo sFont5PlayerCacheTexInfo[] = COMP_TEX_INFO_DEF(20, aFont5PlayerTex);
CacheTexInfo sFont5ComputerCacheTexInfo[] = COMP_TEX_INFO_DEF(20, aFont5ComputerTex);
CacheTexInfo sFont5SelectCourseCacheTexInfo[] = COMP_TEX_INFO_DEF(20, aFont5SelectCourseTex);
CacheTexInfo sFont5QuitCacheTexInfo[] = COMP_TEX_INFO_DEF(20, aFont5QuitTex);

CacheTexInfo* sFont5CacheTexInfos[] = {
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont4PrimeCacheTexInfo,
    sFont4DoublePrimeCacheTexInfo,
    sFont4AmpersandCacheTexInfo,
    sFont5PlusCacheTexInfo,
    sFont4MinusCacheTexInfo,
    sFont5PointsCacheTexInfo,
    sFont5Num0CacheTexInfo,
    sFont5Num1CacheTexInfo,
    sFont5Num2CacheTexInfo,
    sFont5Num3CacheTexInfo,
    sFont5Num4CacheTexInfo,
    sFont5Num5CacheTexInfo,
    sFont5Num6CacheTexInfo,
    sFont5Num7CacheTexInfo,
    sFont5Num8CacheTexInfo,
    sFont5Num9CacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4ACacheTexInfo,
    sFont5OpenParenthesisCacheTexInfo,
    sFont5CloseParenthesisCacheTexInfo,
    sFont4ACacheTexInfo,
    sFont4KatakanaDigraphACacheTexInfo,
    sFont4KatakanaACacheTexInfo,
    sFont4KatakanaDigraphICacheTexInfo,
    sFont4KatakanaICacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaDigraphECacheTexInfo,
    sFont4KatakanaECacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaKaCacheTexInfo,
    sFont4KatakanaGaCacheTexInfo,
    sFont4KatakanaKiCacheTexInfo,
    sFont4KatakanaGiCacheTexInfo,
    sFont4KatakanaKuCacheTexInfo,
    sFont4KatakanaGuCacheTexInfo,
    sFont4KatakanaKeCacheTexInfo,
    sFont4KatakanaGeCacheTexInfo,
    sFont4KatakanaKoCacheTexInfo,
    sFont4KatakanaGoCacheTexInfo,
    sFont4KatakanaSaCacheTexInfo,
    sFont4KatakanaZaCacheTexInfo,
    sFont4KatakanaShiCacheTexInfo,
    sFont4KatakanaJiCacheTexInfo,
    sFont4KatakanaSuCacheTexInfo,
    sFont4KatakanaZuCacheTexInfo,
    sFont4KatakanaSeCacheTexInfo,
    sFont4KatakanaZeCacheTexInfo,
    sFont4KatakanaSoCacheTexInfo,
    sFont4KatakanaZoCacheTexInfo,
    sFont4KatakanaTaCacheTexInfo,
    sFont4KatakanaDaCacheTexInfo,
    sFont4KatakanaChiCacheTexInfo,
    sFont4KatakanaDjiCacheTexInfo,
    sFont4KatakanaSoukonCacheTexInfo,
    sFont4KatakanaTsuCacheTexInfo,
    sFont4KatakanaDzuCacheTexInfo,
    sFont4KatakanaTeCacheTexInfo,
    sFont4KatakanaDeCacheTexInfo,
    sFont4KatakanaToCacheTexInfo,
    sFont4KatakanaDoCacheTexInfo,
    sFont4KatakanaNaCacheTexInfo,
    sFont4KatakanaNiCacheTexInfo,
    sFont4KatakanaNuCacheTexInfo,
    sFont4KatakanaNeCacheTexInfo,
    sFont4KatakanaNoCacheTexInfo,
    sFont4KatakanaHaCacheTexInfo,
    sFont4KatakanaBaCacheTexInfo,
    sFont4KatakanaPaCacheTexInfo,
    sFont4KatakanaHiCacheTexInfo,
    sFont4KatakanaBiCacheTexInfo,
    sFont4KatakanaPiCacheTexInfo,
    sFont4KatakanaFuCacheTexInfo,
    sFont4KatakanaBuCacheTexInfo,
    sFont4KatakanaPuCacheTexInfo,
    sFont4KatakanaHeCacheTexInfo,
    sFont4KatakanaBeCacheTexInfo,
    sFont4KatakanaPeCacheTexInfo,
    sFont4KatakanaHoCacheTexInfo,
    sFont4KatakanaBoCacheTexInfo,
    sFont4KatakanaPoCacheTexInfo,
    sFont4KatakanaMaCacheTexInfo,
    sFont4KatakanaMiCacheTexInfo,
    sFont4KatakanaMuCacheTexInfo,
    sFont4KatakanaMeCacheTexInfo,
    sFont4KatakanaMoCacheTexInfo,
    sFont4KatakanaYoonYaCacheTexInfo,
    sFont4KatakanaYaCacheTexInfo,
    sFont4KatakanaYoonYuCacheTexInfo,
    sFont4KatakanaYuCacheTexInfo,
    sFont4KatakanaYoonYoCacheTexInfo,
    sFont4KatakanaYoCacheTexInfo,
    sFont4KatakanaRaCacheTexInfo,
    sFont4KatakanaRiCacheTexInfo,
    sFont4KatakanaRuCacheTexInfo,
    sFont4KatakanaReCacheTexInfo,
    sFont4KatakanaRoCacheTexInfo,
    sFont4KatakanaWaCacheTexInfo,
    sFont4KatakanaWoCacheTexInfo,
    sFont4KatakanaNCacheTexInfo,
    sFont4KatakanaDigraphACacheTexInfo,
    sFont4KatakanaACacheTexInfo,
    sFont4KatakanaDigraphICacheTexInfo,
    sFont4KatakanaICacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaUCacheTexInfo,
    sFont4KatakanaDigraphECacheTexInfo,
    sFont4KatakanaECacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaOCacheTexInfo,
    sFont4KatakanaKaCacheTexInfo,
    sFont4KatakanaGaCacheTexInfo,
    sFont4KatakanaKiCacheTexInfo,
    sFont4KatakanaGiCacheTexInfo,
    sFont4KatakanaKuCacheTexInfo,
    sFont4KatakanaGuCacheTexInfo,
    sFont4KatakanaKeCacheTexInfo,
    sFont4KatakanaGeCacheTexInfo,
    sFont4KatakanaKoCacheTexInfo,
    sFont4KatakanaGoCacheTexInfo,
    sFont4KatakanaSaCacheTexInfo,
    sFont4KatakanaZaCacheTexInfo,
    sFont4KatakanaShiCacheTexInfo,
    sFont4KatakanaJiCacheTexInfo,
    sFont4KatakanaSuCacheTexInfo,
    sFont4KatakanaZuCacheTexInfo,
    sFont4KatakanaSeCacheTexInfo,
    sFont4KatakanaZeCacheTexInfo,
    sFont4KatakanaSoCacheTexInfo,
    sFont4KatakanaZoCacheTexInfo,
    sFont4KatakanaTaCacheTexInfo,
    sFont4KatakanaDaCacheTexInfo,
    sFont4KatakanaChiCacheTexInfo,
    sFont4KatakanaDjiCacheTexInfo,
    sFont4KatakanaSoukonCacheTexInfo,
    sFont4KatakanaTsuCacheTexInfo,
    sFont4KatakanaDzuCacheTexInfo,
    sFont4KatakanaTeCacheTexInfo,
    sFont4KatakanaDeCacheTexInfo,
    sFont4KatakanaToCacheTexInfo,
    sFont4KatakanaDoCacheTexInfo,
    sFont4KatakanaNaCacheTexInfo,
    sFont4KatakanaNiCacheTexInfo,
    sFont4KatakanaNuCacheTexInfo,
    sFont4KatakanaNeCacheTexInfo,
    sFont4KatakanaNoCacheTexInfo,
    sFont4KatakanaHaCacheTexInfo,
    sFont4KatakanaBaCacheTexInfo,
    sFont4KatakanaPaCacheTexInfo,
    sFont4KatakanaHiCacheTexInfo,
    sFont4KatakanaBiCacheTexInfo,
    sFont4KatakanaPiCacheTexInfo,
    sFont4KatakanaFuCacheTexInfo,
    sFont4KatakanaBuCacheTexInfo,
    sFont4KatakanaPuCacheTexInfo,
    sFont4KatakanaHeCacheTexInfo,
    sFont4KatakanaBeCacheTexInfo,
    sFont4KatakanaPeCacheTexInfo,
    sFont4KatakanaHoCacheTexInfo,
    sFont4KatakanaBoCacheTexInfo,
    sFont4KatakanaPoCacheTexInfo,
    sFont4KatakanaMaCacheTexInfo,
    sFont4KatakanaMiCacheTexInfo,
    sFont4KatakanaMuCacheTexInfo,
    sFont4KatakanaMeCacheTexInfo,
    sFont4KatakanaMoCacheTexInfo,
    sFont4KatakanaYoonYaCacheTexInfo,
    sFont4KatakanaYaCacheTexInfo,
    sFont4KatakanaYoonYuCacheTexInfo,
    sFont4KatakanaYuCacheTexInfo,
    sFont4KatakanaYoonYoCacheTexInfo,
    sFont4KatakanaYoCacheTexInfo,
    sFont4KatakanaRaCacheTexInfo,
    sFont4KatakanaRiCacheTexInfo,
    sFont4KatakanaRuCacheTexInfo,
    sFont4KatakanaReCacheTexInfo,
    sFont4KatakanaRoCacheTexInfo,
    sFont4KatakanaWaCacheTexInfo,
    sFont4KatakanaWoCacheTexInfo,
    sFont4KatakanaNCacheTexInfo,
    sFont5ComputerCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5SelectCourseCacheTexInfo,
    sFont5DownArrowCacheTexInfo,
    sFont5QuitCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5SideArrowCacheTexInfo,
    sFont5NDCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5PlayerCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5RDCacheTexInfo,
    sFont5STCacheTexInfo,
    sFont5THCacheTexInfo,
    sFont5UpArrowCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
    sFont5VCacheTexInfo,
};

CacheTexInfo sFont6ACacheTexInfo[] = COMP_TEX_INFO(4, aFont6ATex, 0);
CacheTexInfo sFont6BCacheTexInfo[] = COMP_TEX_INFO(4, aFont6BTex, 0);
CacheTexInfo sFont6CCacheTexInfo[] = COMP_TEX_INFO(4, aFont6CTex, 0);
CacheTexInfo sFont6DCacheTexInfo[] = COMP_TEX_INFO(4, aFont6DTex, 0);
CacheTexInfo sFont6ECacheTexInfo[] = COMP_TEX_INFO(4, aFont6ETex, 0);
CacheTexInfo sFont6FCacheTexInfo[] = COMP_TEX_INFO(4, aFont6FTex, 0);
CacheTexInfo sFont6GCacheTexInfo[] = COMP_TEX_INFO(4, aFont6GTex, 0);
CacheTexInfo sFont6HCacheTexInfo[] = COMP_TEX_INFO(4, aFont6HTex, 0);
CacheTexInfo sFont6ICacheTexInfo[] = COMP_TEX_INFO(4, aFont6ITex, 0);
CacheTexInfo sFont6JCacheTexInfo[] = COMP_TEX_INFO(4, aFont6JTex, 0);
CacheTexInfo sFont6KCacheTexInfo[] = COMP_TEX_INFO(4, aFont6KTex, 0);
CacheTexInfo sFont6LCacheTexInfo[] = COMP_TEX_INFO(4, aFont6LTex, 0);
CacheTexInfo sFont6MCacheTexInfo[] = COMP_TEX_INFO(4, aFont6MTex, 0);
CacheTexInfo sFont6NCacheTexInfo[] = COMP_TEX_INFO(4, aFont6NTex, 0);
CacheTexInfo sFont6OCacheTexInfo[] = COMP_TEX_INFO(4, aFont6OTex, 0);
CacheTexInfo sFont6PCacheTexInfo[] = COMP_TEX_INFO(4, aFont6PTex, 0);
CacheTexInfo sFont6QCacheTexInfo[] = COMP_TEX_INFO(4, aFont6QTex, 0);
CacheTexInfo sFont6RCacheTexInfo[] = COMP_TEX_INFO(4, aFont6RTex, 0);
CacheTexInfo sFont6SCacheTexInfo[] = COMP_TEX_INFO(4, aFont6STex, 0);
CacheTexInfo sFont6TCacheTexInfo[] = COMP_TEX_INFO(4, aFont6TTex, 0);
CacheTexInfo sFont6UCacheTexInfo[] = COMP_TEX_INFO(4, aFont6UTex, 0);
CacheTexInfo sFont6VCacheTexInfo[] = COMP_TEX_INFO(4, aFont6VTex, 0);
CacheTexInfo sFont6WCacheTexInfo[] = COMP_TEX_INFO(4, aFont6WTex, 0);
CacheTexInfo sFont6XCacheTexInfo[] = COMP_TEX_INFO(4, aFont6XTex, 0);
CacheTexInfo sFont6YCacheTexInfo[] = COMP_TEX_INFO(4, aFont6YTex, 0);
CacheTexInfo sFont6ZCacheTexInfo[] = COMP_TEX_INFO(4, aFont6ZTex, 0);
CacheTexInfo sFont6Num0CacheTexInfo[] = COMP_TEX_INFO(4, aFont6Num0Tex, 0);
CacheTexInfo sFont6Num1CacheTexInfo[] = COMP_TEX_INFO(4, aFont6Num1Tex, 0);
CacheTexInfo sFont6Num2CacheTexInfo[] = COMP_TEX_INFO(4, aFont6Num2Tex, 0);
CacheTexInfo sFont6Num3CacheTexInfo[] = COMP_TEX_INFO(4, aFont6Num3Tex, 0);
CacheTexInfo sFont6Num4CacheTexInfo[] = COMP_TEX_INFO(4, aFont6Num4Tex, 0);
CacheTexInfo sFont6Num5CacheTexInfo[] = COMP_TEX_INFO(4, aFont6Num5Tex, 0);
CacheTexInfo sFont6Num6CacheTexInfo[] = COMP_TEX_INFO(4, aFont6Num6Tex, 0);
CacheTexInfo sFont6Num7CacheTexInfo[] = COMP_TEX_INFO(4, aFont6Num7Tex, 0);
CacheTexInfo sFont6Num8CacheTexInfo[] = COMP_TEX_INFO(4, aFont6Num8Tex, 0);
CacheTexInfo sFont6Num9CacheTexInfo[] = COMP_TEX_INFO(4, aFont6Num9Tex, 0);
CacheTexInfo sFont6AlphaCacheTexInfo[] = COMP_TEX_INFO(4, aFont6AlphaTex, 0);
CacheTexInfo sFont6BetaCacheTexInfo[] = COMP_TEX_INFO(4, aFont6BetaTex, 0);
CacheTexInfo sFont6HiraganaNiCacheTexInfo[] = COMP_TEX_INFO(4, aFont6HiraganaNiTex, 0);
CacheTexInfo sFont6AmpersandCacheTexInfo[] = COMP_TEX_INFO(4, aFont6AmpersandTex, 0);
CacheTexInfo sFont6CommaCacheTexInfo[] = COMP_TEX_INFO(4, aFont6CommaTex, 0);
CacheTexInfo sFont6DoublePrimeCacheTexInfo[] = COMP_TEX_INFO(4, aFont6DoublePrimeTex, 0);
CacheTexInfo sFont6DashCacheTexInfo[] = COMP_TEX_INFO(4, aFont6DashTex, 0);
CacheTexInfo sFont6PeriodCacheTexInfo[] = COMP_TEX_INFO(4, aFont6PeriodTex, 0);
CacheTexInfo sFont6PrimeCacheTexInfo[] = COMP_TEX_INFO(4, aFont6PrimeTex, 0);
CacheTexInfo sFont6UnderscoreCacheTexInfo[] = COMP_TEX_INFO(4, aFont6UnderscoreTex, 0);

CacheTexInfo* sFont6CacheTexInfos[] = {
    sFont6ACacheTexInfo,         sFont6BCacheTexInfo,    sFont6CCacheTexInfo,          sFont6DCacheTexInfo,
    sFont6ECacheTexInfo,         sFont6FCacheTexInfo,    sFont6GCacheTexInfo,          sFont6HCacheTexInfo,
    sFont6ICacheTexInfo,         sFont6JCacheTexInfo,    sFont6KCacheTexInfo,          sFont6LCacheTexInfo,
    sFont6MCacheTexInfo,         sFont6NCacheTexInfo,    sFont6OCacheTexInfo,          sFont6PCacheTexInfo,
    sFont6QCacheTexInfo,         sFont6RCacheTexInfo,    sFont6SCacheTexInfo,          sFont6TCacheTexInfo,
    sFont6UCacheTexInfo,         sFont6VCacheTexInfo,    sFont6WCacheTexInfo,          sFont6XCacheTexInfo,
    sFont6YCacheTexInfo,         sFont6ZCacheTexInfo,    sFont6PrimeCacheTexInfo,      sFont6DoublePrimeCacheTexInfo,
    sFont6AmpersandCacheTexInfo, sFont6ACacheTexInfo,    sFont6DashCacheTexInfo,       sFont6ACacheTexInfo,
    sFont6Num0CacheTexInfo,      sFont6Num1CacheTexInfo, sFont6Num2CacheTexInfo,       sFont6Num3CacheTexInfo,
    sFont6Num4CacheTexInfo,      sFont6Num5CacheTexInfo, sFont6Num6CacheTexInfo,       sFont6Num7CacheTexInfo,
    sFont6Num8CacheTexInfo,      sFont6Num9CacheTexInfo, sFont6ACacheTexInfo,          sFont6PeriodCacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6CommaCacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6HiraganaNiCacheTexInfo, sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6AlphaCacheTexInfo,     sFont6BetaCacheTexInfo, sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,         sFont6ACacheTexInfo,    sFont6ACacheTexInfo,          sFont6ACacheTexInfo,
    sFont6ACacheTexInfo,
};

CacheTexInfo sMachineStatACacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineStatATex);
CacheTexInfo sMachineStatBCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineStatBTex);
CacheTexInfo sMachineStatCCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineStatCTex);
CacheTexInfo sMachineStatDCacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineStatDTex);
CacheTexInfo sMachineStatECacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineStatETex);

CacheTexInfo* sMachineStatValueCacheTexInfos[] = {
    sMachineStatACacheTexInfo, sMachineStatBCacheTexInfo, sMachineStatCCacheTexInfo,
    sMachineStatDCacheTexInfo, sMachineStatECacheTexInfo,
};

CacheTexInfo sMachineWeight0CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight0Tex);
CacheTexInfo sMachineWeight1CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight1Tex);
CacheTexInfo sMachineWeight2CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight2Tex);
CacheTexInfo sMachineWeight3CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight3Tex);
CacheTexInfo sMachineWeight4CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight4Tex);
CacheTexInfo sMachineWeight5CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight5Tex);
CacheTexInfo sMachineWeight6CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight6Tex);
CacheTexInfo sMachineWeight7CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight7Tex);
CacheTexInfo sMachineWeight8CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight8Tex);
CacheTexInfo sMachineWeight9CacheTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight9Tex);

CacheTexInfo* sMachineWeightDigitCacheTexInfos[] = {
    sMachineWeight0CacheTexInfo, sMachineWeight1CacheTexInfo, sMachineWeight2CacheTexInfo, sMachineWeight3CacheTexInfo,
    sMachineWeight4CacheTexInfo, sMachineWeight5CacheTexInfo, sMachineWeight6CacheTexInfo, sMachineWeight7CacheTexInfo,
    sMachineWeight8CacheTexInfo, sMachineWeight9CacheTexInfo,
};

void Font_IntToString(s32 num, s8* str) {
    s32 numDigits;
    s32 digitMask;
    s32 i;
    s32 j;

    j = num;
    numDigits = 0;
    if (num == 0) {
        numDigits = 1;
    } else {
        while (j != 0) {
            j /= 10;
            numDigits++;
        }
    }

    for (i = numDigits; i > 0; i--) {
        digitMask = 1;
        for (j = 0; j < i - 1; j++) {
            digitMask *= 10;
        }

        *str++ = (num / digitMask) + '0';
        num %= digitMask;
    }

    *str = '\0';
}

s32 func_i2_80105EE4(s8* str) {
    s32 ret;
    u8 temp_v0 = *str + 0x80;

    // FAKE
    ret = temp_v0;
    if (1) {}

    if ((temp_v0 >= 0x21) && (temp_v0 < 0x6E)) {
        ret += 15;
    } else {
        switch (temp_v0) {
            case 0x6F:
                ret = 0x7D;
                break;
            case 0x72:
            case 0x73:
                ret += 12;
                break;
            default:
                ret = FONT_CHAR_UNKNOWN;
                break;
        }
    }
    return ret;
}

s32 func_i2_80105F48(s8* str) {
    return func_i2_80105EE4(str) + 0x50;
}

s32 func_i2_80105F6C(s8* str) {
    u8 temp_v0;
    s32 ret;

    temp_v0 = (str[1] + 0x80);
    ret = 2;

    switch (str[0]) {
        case (s8) 0xAB:
            break;
        case (s8) 0xA1:
            switch (temp_v0) {
                case 0x3C:
                case 0x3D:
                case 0x5D:
                    ret = 0xEA;
                    break;
                case 0x75:
                    ret = 0x1C;
                    break;
                default:
                    ret = 2;
                    break;
            }
            break;
        case (s8) 0xA3:
            if ((temp_v0 >= 0x61) && (temp_v0 < 0x7B)) {
                ret = temp_v0 + 0x6F;
            } else if ((temp_v0 >= 0x41) && (temp_v0 < 0x5B)) {
                ret = temp_v0 + 0x8F;
            }
            break;
        default:
            ret = 2;
            break;
    }

    return ret;
}

s32 Font_GetCharIndex(s8* str, s32 fontSetLowercase) {
    s32 fontChar = 1;

    if ((*str >= 'a') && (*str <= 'z')) {
        switch (fontSetLowercase) {
            case FONT_SET_UPPERCASE_ONLY:
                fontChar = *str - 0x61;
                break;
            case FONT_SET_HAS_LOWERCASE:
                fontChar = *str - 0x31;
                break;
        }
    } else if ((*str >= 'A') && (*str <= 'Z')) {
        fontChar = *str - 0x41;
    } else if ((*str >= '0') && (*str <= '9')) {
        fontChar = *str - 0x10;
    } else if (*str == ' ') {
        fontChar = FONT_CHAR_SPACE;
    } else if (*str < 0) {
        // EUC-JP
        switch (*str) {
            case (s8) 0xA4:
                fontChar = func_i2_80105EE4(str + 1);
                break;
            case (s8) 0xA5:
                fontChar = func_i2_80105F48(str + 1);
                break;
            case (s8) 0xA1:
            case (s8) 0xA3:
            case (s8) 0xAB:
                fontChar = func_i2_80105F6C(str);
                break;
        }
    } else {
        switch (*str) {
            case '\'':
                fontChar = FONT_CHAR_PRIME;
                break;
            case '\"':
                fontChar = FONT_CHAR_DOUBLE_PRIME;
                break;
            case '&':
                fontChar = FONT_CHAR_AMPERSAND;
                break;
            case '+':
                fontChar = FONT_CHAR_PLUS;
                break;
            case '-':
                fontChar = FONT_CHAR_MINUS;
                break;
            case '!':
            case '$':
                fontChar = FONT_CHAR_POINTS_KG;
                break;
            case ':':
                fontChar = FONT_CHAR_COLON;
                break;
            case '.':
                fontChar = FONT_CHAR_PERIOD;
                break;
            case '*':
            case '<':
                fontChar = FONT_CHAR_ELLIPSIS;
                break;
            case '(':
            case '>':
                fontChar = FONT_CHAR_OPEN_PARENTHESIS;
                break;
            case '_':
            case ')':
                fontChar = FONT_CHAR_CLOSE_PARENTHESIS;
                break;
            case ',':
                fontChar = FONT_CHAR_COMMA;
                break;
            default:
                fontChar = FONT_CHAR_UNKNOWN;
                break;
        }
    }
    return fontChar;
}

const s16 kFont1CharWidths[] = {
    13, 15, 14, 15, 14, 13, 15, 15, 7,  14, 15, 14, 17, 14, 14, 15, 15, 14, 14, 14, 14, 12, 16, 16,
    14, 14, 8,  8,  16, 8,  16, 7,  13, 7,  13, 13, 13, 12, 13, 12, 13, 13, 8,  8,  16, 16, 16, 8,
};

const s16 kFont2CharWidths[] = {
    8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
};

const s16 kFont3CharWidths[] = {
    13, 12, 12, 13, 12, 11, 12, 13, 6,  9,  15, 11, 15, 13, 13, 12, 12, 12, 11, 11, 12, 12, 15, 13, 12, 11,
    7,  14, 14, 14, 13, 14, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 9,  9,  14, 14, 14, 9,  14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    12, 12, 12, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
};

#ifdef VERSION_JP
const s16 kFont4CharWidths[] = {
    7, 7, 6, 7, 6, 5, 6, 7, 4, 4, 6, 5, 7, 6, 7, 6, 7, 7, 6, 6, 7, 6, 7, 7, 7, 5, 8, 8, 8, 8, 8, 16, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
};
#else
const s16 kFont4CharWidths[] = {
    7, 7, 6, 7, 6, 5, 6, 7, 4, 4, 6, 5, 7, 6, 7, 6, 7, 7, 6, 6, 7, 6, 7, 7, 7, 5, 8, 8, 8, 8, 8, 16, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 6,  6, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
};
#endif

const s16 kFont5CharWidths[] = {
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 8,
    8,  8,  14, 8,  22, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 8,  8,  8,  14, 16, 6,  8,  8,  8,  8,  8,  8,
    8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
    8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
    8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
    8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
    8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
    8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  68, 14, 96, 16, 44, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 68, 14, 14, 14, 14, 16, 14, 14, 14, 14, 14, 14,
};

const s16 kFont6CharWidths[] = {
    11, 10, 10, 10, 9,  9,  10, 10, 7,  8,  11, 9,  12, 11, 11, 9,  11, 9,  9,  8,  10, 11, 12, 10, 8,  10, 7,
    9,  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 8,  11, 11, 11, 7,  11, 11, 11, 7,  11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
};

const s16 kMachineWeightDigitWidths[] = { 9, 5, 9, 9, 9, 9, 9, 9, 9, 9 };

s32 Font_GetCharacterWidth(s8* str, s32 fontSet) {
    s32 strWidth;
    s32 fontChar;
    const s16* fontCharWidths;
    s32 fontSpaceWidth;

    switch (fontSet) {
        case FONT_SET_2:
            fontCharWidths = kFont2CharWidths;
            fontSpaceWidth = 3;
            break;
        case FONT_SET_3:
            fontCharWidths = kFont3CharWidths;
            fontSpaceWidth = 6;
            break;
        case FONT_SET_4:
            fontCharWidths = kFont4CharWidths;
            fontSpaceWidth = 3;
            break;
        case FONT_SET_5:
            fontCharWidths = kFont5CharWidths;
            fontSpaceWidth = 3;
            break;
        case FONT_SET_6:
            fontCharWidths = kFont6CharWidths;
            fontSpaceWidth = 3;
            break;
        case FONT_SET_1:
        default:
            fontCharWidths = kFont1CharWidths;
            fontSpaceWidth = 7;
            break;
    }
    strWidth = 0;
    if (fontSet == FONT_SET_4) {
        fontChar = Font_GetCharIndex(str, FONT_SET_HAS_LOWERCASE);
    } else {
        fontChar = Font_GetCharIndex(str, FONT_SET_UPPERCASE_ONLY);
    }

    if (fontChar >= 0) {
        strWidth = fontCharWidths[fontChar];
    } else if (fontChar == FONT_CHAR_SPACE) {
        strWidth = fontSpaceWidth;
    }
    return strWidth;
}

s32 Font_GetStringWidth(s8* str, s32 fontSet, s32 additionalSpacing) {
    const s16* fontCharWidths;
    s32 strWidth;
    s32 fontSpaceWidth;
    s32 fontChar;

    strWidth = 0;
    switch (fontSet) {
        case FONT_SET_2:
            fontCharWidths = kFont2CharWidths;
            fontSpaceWidth = 3;
            break;
        case FONT_SET_3:
            fontCharWidths = kFont3CharWidths;
            fontSpaceWidth = 6;
            break;
        case FONT_SET_4:
            fontCharWidths = kFont4CharWidths;
            fontSpaceWidth = 3;
            break;
        case FONT_SET_5:
            fontCharWidths = kFont5CharWidths;
            fontSpaceWidth = 3;
            break;
        case FONT_SET_6:
            fontCharWidths = kFont6CharWidths;
            fontSpaceWidth = 3;
            break;
        case FONT_SET_1:
        default:
            fontCharWidths = kFont1CharWidths;
            fontSpaceWidth = 7;
            break;
    }

    while (*str != '\0') {
        if (fontSet == FONT_SET_4) {
            fontChar = Font_GetCharIndex(str, FONT_SET_HAS_LOWERCASE);
        } else {
            fontChar = Font_GetCharIndex(str, FONT_SET_UPPERCASE_ONLY);
        }
        if (fontChar >= 0) {
            strWidth += fontCharWidths[fontChar];
        } else if (fontChar == FONT_CHAR_SPACE) {
            strWidth += fontSpaceWidth;
        }
        strWidth += additionalSpacing;

        if (*str < 0) {
            str += 2;
        } else {
            str += 1;
        }
    }
    return strWidth;
}

#ifdef EXPANSION_KIT
void Font_LoadString(s8* str, s32 fontSet) {
    CacheTexInfo** fontCharTexInfos;
    s32 fontChar;

    switch (fontSet) {
        case FONT_SET_2:
            fontCharTexInfos = sFont2CacheTexInfos;
            break;
        case FONT_SET_3:
            fontCharTexInfos = sFont3CacheTexInfos;
            break;
        case FONT_SET_4:
            fontCharTexInfos = sFont4CacheTexInfos;
            break;
        case FONT_SET_5:
            fontCharTexInfos = sFont5CacheTexInfos;
            break;
        case FONT_SET_6:
            fontCharTexInfos = sFont6CacheTexInfos;
            break;
        case FONT_SET_1:
        default:
            fontCharTexInfos = sFont1CacheTexInfos;
            break;
    }
    while (*str != 0) {
        if (fontSet == FONT_SET_4) {
            fontChar = Font_GetCharIndex(str, FONT_SET_HAS_LOWERCASE);
        } else {
            fontChar = Font_GetCharIndex(str, FONT_SET_UPPERCASE_ONLY);
        }
        if (fontChar >= 0) {
            TextureCache_LoadCacheTexInfoList_impl(fontCharTexInfos[fontChar], false, true);
        } else {
            switch (fontChar) {
                case FONT_CHAR_SPACE:
                    break;
                case FONT_CHAR_UNKNOWN:
                default:
                    return;
            }
        }
        if (*str < 0) {
            str += 2;
        } else {
            str += 1;
        }
    }
}
#endif

Gfx* Font_DrawString(Gfx* gfx, s32 left, s32 top, s8* str, s32 additionalSpacing, s32 fontSet, s32 arg6) {
    const s16* fontCharWidths;
    s32 strWidth;
    s32 fontChar;
    CacheTexInfo** fontCharTexInfos;
    s32 fontSpaceWidth;

    switch (fontSet) {
        case FONT_SET_2:
            fontCharWidths = kFont2CharWidths;
            fontCharTexInfos = sFont2CacheTexInfos;
            fontSpaceWidth = 3;
            top -= 8;
            break;
        case FONT_SET_3:
            fontCharWidths = kFont3CharWidths;
            fontCharTexInfos = sFont3CacheTexInfos;
            fontSpaceWidth = 6;
            top -= 16;
            break;
        case FONT_SET_4:
            fontCharWidths = kFont4CharWidths;
            fontCharTexInfos = sFont4CacheTexInfos;
            fontSpaceWidth = 3;
            top -= 8;
            break;
        case FONT_SET_5:
            fontCharWidths = kFont5CharWidths;
            fontCharTexInfos = sFont5CacheTexInfos;
            fontSpaceWidth = 3;
            top -= 16;
            break;
        case FONT_SET_6:
            fontCharWidths = kFont6CharWidths;
            fontCharTexInfos = sFont6CacheTexInfos;
            fontSpaceWidth = 3;
            top -= 16;
            break;
        case FONT_SET_1:
        default:
            fontCharWidths = kFont1CharWidths;
            fontCharTexInfos = sFont1CacheTexInfos;
            fontSpaceWidth = 7;
            top -= 16;
            break;
    }
    strWidth = 0;
    while (*str != '\0') {
        if (fontSet == FONT_SET_4) {
            fontChar = Font_GetCharIndex(str, FONT_SET_HAS_LOWERCASE);
        } else {
            fontChar = Font_GetCharIndex(str, FONT_SET_UPPERCASE_ONLY);
        }
        if (fontChar >= 0) {
            TextureCache_LoadCacheTexInfoList_impl(fontCharTexInfos[fontChar], false, true);
            if (arg6 == 1) {
                gfx = TextureCache_DrawList_impl(gfx, fontCharTexInfos[fontChar], left + strWidth, top, 1, false, false,
                                                 1.0f, 1.0f, true);
            } else {
                gfx = TextureCache_DrawList_impl(gfx, fontCharTexInfos[fontChar], left + strWidth, top, 0, false, false,
                                                 1.0f, 1.0f, true);
            }

            strWidth += fontCharWidths[fontChar] + additionalSpacing;
        } else {
            switch (fontChar) {
                case FONT_CHAR_SPACE:
                    strWidth += fontSpaceWidth + additionalSpacing;
                    break;
                case FONT_CHAR_UNKNOWN:
                default:
                    return gfx;
            }
        }

        if (*str < 0) {
            str += 2;
        } else {
            str += 1;
        }
    }
    return gfx;
}

Gfx* Font_DrawScaledString(Gfx* gfx, s32 left, s32 top, s8* str, s32 additionalSpacing, s32 fontSet, s32 arg6,
                           f32 scaleX, f32 scaleY) {
    const s16* fontCharWidths;
    s32 strWidth;
    s32 fontChar;
    CacheTexInfo** fontCharTexInfos;
    s32 fontSpaceWidth;

    switch (fontSet) {
        case FONT_SET_2:
            fontCharWidths = kFont2CharWidths;
            fontCharTexInfos = sFont2CacheTexInfos;
            fontSpaceWidth = 3;
            top -= 8;
            break;
        case FONT_SET_3:
            fontCharWidths = kFont3CharWidths;
            fontCharTexInfos = sFont3CacheTexInfos;
            fontSpaceWidth = 6;
            top -= 16;
            break;
        case FONT_SET_4:
            fontCharWidths = kFont4CharWidths;
            fontCharTexInfos = sFont4CacheTexInfos;
            fontSpaceWidth = 3;
            top -= 8;
            break;
        case FONT_SET_5:
            fontCharWidths = kFont5CharWidths;
            fontCharTexInfos = sFont5CacheTexInfos;
            fontSpaceWidth = 3;
            top -= 16;
            break;
        case FONT_SET_6:
            fontCharWidths = kFont6CharWidths;
            fontCharTexInfos = sFont6CacheTexInfos;
            fontSpaceWidth = 3;
            top -= 16;
            break;
        case FONT_SET_1:
        default:
            fontCharWidths = kFont1CharWidths;
            fontCharTexInfos = sFont1CacheTexInfos;
            fontSpaceWidth = 7;
            top -= 16;
            break;
    }
    strWidth = 0;
    while (*str != '\0') {
        if (fontSet == FONT_SET_4) {
            fontChar = Font_GetCharIndex(str, FONT_SET_HAS_LOWERCASE);
        } else {
            fontChar = Font_GetCharIndex(str, FONT_SET_UPPERCASE_ONLY);
        }
        if (fontChar >= 0) {
            TextureCache_LoadCacheTexInfoList_impl(fontCharTexInfos[fontChar], false, true);
            if (arg6 == 1) {
                gfx = TextureCache_DrawList_impl(gfx, fontCharTexInfos[fontChar], (s32) (left + (strWidth * scaleX)),
                                                 top, 4, false, false, scaleX, scaleY, true);
            } else {
                gfx = TextureCache_DrawList_impl(gfx, fontCharTexInfos[fontChar], (s32) (left + (strWidth * scaleX)),
                                                 top, 3, false, false, scaleX, scaleY, true);
            }

            strWidth += fontCharWidths[fontChar] + additionalSpacing;
        } else {
            switch (fontChar) {
                case FONT_CHAR_SPACE:
                    strWidth += fontSpaceWidth + additionalSpacing;
                    break;
                case FONT_CHAR_UNKNOWN:
                default:
                    return gfx;
            }
        }

        if (*str < 0) {
            str += 2;
        } else {
            str += 1;
        }
    }
    return gfx;
}

Gfx* Font_DrawMachineStatValue(Gfx* gfx, s32 left, s32 top, s32 statValue) {

    if ((statValue < 0) && (statValue >= 5)) {
        return gfx;
    }

    TextureCache_LoadCacheTexInfoList_impl(sMachineStatValueCacheTexInfos[statValue], false, true);
    return TextureCache_DrawList_impl(gfx, sMachineStatValueCacheTexInfos[statValue], left, top, 0, false, false, 1.0f,
                                      1.0f, true);
}

Gfx* Font_DrawMachineStatValueSmall(Gfx* gfx, s32 left, s32 top, s32 statValue) {

    if ((statValue < 0) && (statValue >= 5)) {
        return gfx;
    }

    TextureCache_LoadCacheTexInfoList_impl(sMachineStatValueCacheTexInfos[statValue], false, true);
    return TextureCache_DrawList_impl(gfx, sMachineStatValueCacheTexInfos[statValue], left, top, 3, false, false, 0.5f,
                                      0.5f, true);
}

Gfx* Font_DrawMachineWeight(Gfx* gfx, s32 left, s32 top, u32 weight) {
    s32 width;
    s32 digit;

    width = 0;
    do {
        digit = weight % 10;
        width -= kMachineWeightDigitWidths[digit];
        TextureCache_LoadCacheTexInfoList_impl(sMachineWeightDigitCacheTexInfos[digit], false, true);
        gfx = TextureCache_DrawList_impl(gfx, sMachineWeightDigitCacheTexInfos[digit], left + width, top - 16, 0, false,
                                         false, 1.0f, 1.0f, true);
        weight /= 10;
    } while (weight != 0);

    return gfx;
}

Gfx* Font_DrawMachineWeightSmall(Gfx* gfx, s32 left, s32 top, u32 weight) {
    s32 width;
    s32 digit;
    f32 scale = 0.75f;

    width = 0;
    do {
        digit = weight % 10;
        width -= kMachineWeightDigitWidths[digit] * scale + 1.0f;
        TextureCache_LoadCacheTexInfoList_impl(sMachineWeightDigitCacheTexInfos[digit], false, true);
        gfx = TextureCache_DrawList_impl(gfx, sMachineWeightDigitCacheTexInfos[digit], left + width,
                                         top - (16.0f * scale), 3, false, false, scale, scale, true);
        weight /= 10;
    } while (weight != 0);

    return gfx;
}
