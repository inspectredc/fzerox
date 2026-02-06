#include "global.h"
#include "fzx_font.h"
#include ASSET_HEADER(common_assets_compressed.h)

unk_80077D50 sFont1ACompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1ATex);
unk_80077D50 sFont1BCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1BTex);
unk_80077D50 sFont1CCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1CTex);
unk_80077D50 sFont1DCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1DTex);
unk_80077D50 sFont1ECompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1ETex);
unk_80077D50 sFont1FCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1FTex);
unk_80077D50 sFont1GCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1GTex);
unk_80077D50 sFont1HCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1HTex);
unk_80077D50 sFont1ICompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1ITex);
unk_80077D50 sFont1JCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1JTex);
unk_80077D50 sFont1KCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1KTex);
unk_80077D50 sFont1LCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1LTex);
unk_80077D50 sFont1MCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1MTex);
unk_80077D50 sFont1NCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1NTex);
unk_80077D50 sFont1OCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1OTex);
unk_80077D50 sFont1PCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1PTex);
unk_80077D50 sFont1QCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1QTex);
unk_80077D50 sFont1RCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1RTex);
unk_80077D50 sFont1SCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1STex);
unk_80077D50 sFont1TCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1TTex);
unk_80077D50 sFont1UCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1UTex);
unk_80077D50 sFont1VCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1VTex);
unk_80077D50 sFont1WCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1WTex);
unk_80077D50 sFont1XCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1XTex);
unk_80077D50 sFont1YCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1YTex);
unk_80077D50 sFont1ZCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1ZTex);
unk_80077D50 sFont1CommaCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1CommaTex);
unk_80077D50 sFont1PeriodCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1PeriodTex);
unk_80077D50 sFont1PrimeCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1PrimeTex);
unk_80077D50 sFont1ExclamationMarkCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1ExclamationMarkTex);
unk_80077D50 sFont1Num0CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num0Tex);
unk_80077D50 sFont1Num1CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num1Tex);
unk_80077D50 sFont1Num2CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num2Tex);
unk_80077D50 sFont1Num3CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num3Tex);
unk_80077D50 sFont1Num4CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num4Tex);
unk_80077D50 sFont1Num5CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num5Tex);
unk_80077D50 sFont1Num6CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num6Tex);
unk_80077D50 sFont1Num7CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num7Tex);
unk_80077D50 sFont1Num8CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num8Tex);
unk_80077D50 sFont1Num9CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1Num9Tex);
unk_80077D50 sFont1UnderscoreCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1UnderscoreTex);
unk_80077D50 sFont1EndCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1EndTex);
unk_80077D50 sFont1BoxCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1BoxTex);
unk_80077D50 sFont1DashCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1DashTex);
unk_80077D50 sFont1AmpersandCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont1AmpersandTex);

unk_80077D50* sFont1CompTexInfos[] = {
    sFont1ACompTexInfo,         sFont1BCompTexInfo,     sFont1CCompTexInfo,          sFont1DCompTexInfo,
    sFont1ECompTexInfo,         sFont1FCompTexInfo,     sFont1GCompTexInfo,          sFont1HCompTexInfo,
    sFont1ICompTexInfo,         sFont1JCompTexInfo,     sFont1KCompTexInfo,          sFont1LCompTexInfo,
    sFont1MCompTexInfo,         sFont1NCompTexInfo,     sFont1OCompTexInfo,          sFont1PCompTexInfo,
    sFont1QCompTexInfo,         sFont1RCompTexInfo,     sFont1SCompTexInfo,          sFont1TCompTexInfo,
    sFont1UCompTexInfo,         sFont1VCompTexInfo,     sFont1WCompTexInfo,          sFont1XCompTexInfo,
    sFont1YCompTexInfo,         sFont1ZCompTexInfo,     sFont1PrimeCompTexInfo,      sFont1PrimeCompTexInfo,
    sFont1AmpersandCompTexInfo, sFont1PrimeCompTexInfo, sFont1DashCompTexInfo,       sFont1ExclamationMarkCompTexInfo,
    sFont1Num0CompTexInfo,      sFont1Num1CompTexInfo,  sFont1Num2CompTexInfo,       sFont1Num3CompTexInfo,
    sFont1Num4CompTexInfo,      sFont1Num5CompTexInfo,  sFont1Num6CompTexInfo,       sFont1Num7CompTexInfo,
    sFont1Num8CompTexInfo,      sFont1Num9CompTexInfo,  sFont1PeriodCompTexInfo,     sFont1PeriodCompTexInfo,
    sFont1EndCompTexInfo,       sFont1BoxCompTexInfo,   sFont1UnderscoreCompTexInfo, sFont1CommaCompTexInfo,
};

unk_80077D50 sFont2ACompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2ATex);
unk_80077D50 sFont2BCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2BTex);
unk_80077D50 sFont2CCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2CTex);
unk_80077D50 sFont2DCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2DTex);
unk_80077D50 sFont2ECompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2ETex);
unk_80077D50 sFont2FCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2FTex);
unk_80077D50 sFont2GCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2GTex);
unk_80077D50 sFont2HCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2HTex);
unk_80077D50 sFont2ICompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2ITex);
unk_80077D50 sFont2JCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2JTex);
unk_80077D50 sFont2KCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2KTex);
unk_80077D50 sFont2LCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2LTex);
unk_80077D50 sFont2MCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2MTex);
unk_80077D50 sFont2NCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2NTex);
unk_80077D50 sFont2OCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2OTex);
unk_80077D50 sFont2PCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2PTex);
unk_80077D50 sFont2QCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2QTex);
unk_80077D50 sFont2RCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2RTex);
unk_80077D50 sFont2SCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2STex);
unk_80077D50 sFont2TCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2TTex);
unk_80077D50 sFont2UCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2UTex);
unk_80077D50 sFont2VCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2VTex);
unk_80077D50 sFont2WCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2WTex);
unk_80077D50 sFont2XCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2XTex);
unk_80077D50 sFont2YCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2YTex);
unk_80077D50 sFont2ZCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2ZTex);
unk_80077D50 sFont2CommaCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2CommaTex);
unk_80077D50 sFont2PeriodCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2PeriodTex);
unk_80077D50 sFont2PrimeCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2PrimeTex);
unk_80077D50 sFont2DashCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2DashTex);
unk_80077D50 sFont2KgCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2KgTex);
unk_80077D50 sFont2AmpersandCompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2AmpersandTex);
unk_80077D50 sFont2Num0CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num0Tex);
unk_80077D50 sFont2Num1CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num1Tex);
unk_80077D50 sFont2Num2CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num2Tex);
unk_80077D50 sFont2Num3CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num3Tex);
unk_80077D50 sFont2Num4CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num4Tex);
unk_80077D50 sFont2Num5CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num5Tex);
unk_80077D50 sFont2Num6CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num6Tex);
unk_80077D50 sFont2Num7CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num7Tex);
unk_80077D50 sFont2Num8CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num8Tex);
unk_80077D50 sFont2Num9CompTexInfo[] = COMP_TEX_INFO_DEF(17, aFont2Num9Tex);

unk_80077D50* sFont2CompTexInfos[] = {
    sFont2ACompTexInfo,         sFont2BCompTexInfo,     sFont2CCompTexInfo,      sFont2DCompTexInfo,
    sFont2ECompTexInfo,         sFont2FCompTexInfo,     sFont2GCompTexInfo,      sFont2HCompTexInfo,
    sFont2ICompTexInfo,         sFont2JCompTexInfo,     sFont2KCompTexInfo,      sFont2LCompTexInfo,
    sFont2MCompTexInfo,         sFont2NCompTexInfo,     sFont2OCompTexInfo,      sFont2PCompTexInfo,
    sFont2QCompTexInfo,         sFont2RCompTexInfo,     sFont2SCompTexInfo,      sFont2TCompTexInfo,
    sFont2UCompTexInfo,         sFont2VCompTexInfo,     sFont2WCompTexInfo,      sFont2XCompTexInfo,
    sFont2YCompTexInfo,         sFont2ZCompTexInfo,     sFont2PrimeCompTexInfo,  sFont2PrimeCompTexInfo,
    sFont2AmpersandCompTexInfo, sFont2PrimeCompTexInfo, sFont2DashCompTexInfo,   sFont2KgCompTexInfo,
    sFont2Num0CompTexInfo,      sFont2Num1CompTexInfo,  sFont2Num2CompTexInfo,   sFont2Num3CompTexInfo,
    sFont2Num4CompTexInfo,      sFont2Num5CompTexInfo,  sFont2Num6CompTexInfo,   sFont2Num7CompTexInfo,
    sFont2Num8CompTexInfo,      sFont2Num9CompTexInfo,  sFont2PeriodCompTexInfo, sFont2PeriodCompTexInfo,
    sFont2PeriodCompTexInfo,    sFont2CommaCompTexInfo, sFont2CommaCompTexInfo,  sFont2CommaCompTexInfo,
};

unk_80077D50 sFont3ACompTexInfo[] = COMP_TEX_INFO(4, aFont3ATex, 0);
unk_80077D50 sFont3BCompTexInfo[] = COMP_TEX_INFO(4, aFont3BTex, 0);
unk_80077D50 sFont3CCompTexInfo[] = COMP_TEX_INFO(4, aFont3CTex, 0);
unk_80077D50 sFont3DCompTexInfo[] = COMP_TEX_INFO(4, aFont3DTex, 0);
unk_80077D50 sFont3ECompTexInfo[] = COMP_TEX_INFO(4, aFont3ETex, 0);
unk_80077D50 sFont3FCompTexInfo[] = COMP_TEX_INFO(4, aFont3FTex, 0);
unk_80077D50 sFont3GCompTexInfo[] = COMP_TEX_INFO(4, aFont3GTex, 0);
unk_80077D50 sFont3HCompTexInfo[] = COMP_TEX_INFO(4, aFont3HTex, 0);
unk_80077D50 sFont3ICompTexInfo[] = COMP_TEX_INFO(4, aFont3ITex, 0);
unk_80077D50 sFont3JCompTexInfo[] = COMP_TEX_INFO(4, aFont3JTex, 0);
unk_80077D50 sFont3KCompTexInfo[] = COMP_TEX_INFO(4, aFont3KTex, 0);
unk_80077D50 sFont3LCompTexInfo[] = COMP_TEX_INFO(4, aFont3LTex, 0);
unk_80077D50 sFont3MCompTexInfo[] = COMP_TEX_INFO(4, aFont3MTex, 0);
unk_80077D50 sFont3NCompTexInfo[] = COMP_TEX_INFO(4, aFont3NTex, 0);
unk_80077D50 sFont3OCompTexInfo[] = COMP_TEX_INFO(4, aFont3OTex, 0);
unk_80077D50 sFont3PCompTexInfo[] = COMP_TEX_INFO(4, aFont3PTex, 0);
unk_80077D50 sFont3QCompTexInfo[] = COMP_TEX_INFO(4, aFont3QTex, 0);
unk_80077D50 sFont3RCompTexInfo[] = COMP_TEX_INFO(4, aFont3RTex, 0);
unk_80077D50 sFont3SCompTexInfo[] = COMP_TEX_INFO(4, aFont3STex, 0);
unk_80077D50 sFont3TCompTexInfo[] = COMP_TEX_INFO(4, aFont3TTex, 0);
unk_80077D50 sFont3UCompTexInfo[] = COMP_TEX_INFO(4, aFont3UTex, 0);
unk_80077D50 sFont3VCompTexInfo[] = COMP_TEX_INFO(4, aFont3VTex, 0);
unk_80077D50 sFont3WCompTexInfo[] = COMP_TEX_INFO(4, aFont3WTex, 0);
unk_80077D50 sFont3XCompTexInfo[] = COMP_TEX_INFO(4, aFont3XTex, 0);
unk_80077D50 sFont3YCompTexInfo[] = COMP_TEX_INFO(4, aFont3YTex, 0);
unk_80077D50 sFont3ZCompTexInfo[] = COMP_TEX_INFO(4, aFont3ZTex, 0);
unk_80077D50 sFont3AlphaCompTexInfo[] = COMP_TEX_INFO(4, aFont3AlphaTex, 0);
unk_80077D50 sFont3BetaCompTexInfo[] = COMP_TEX_INFO(4, aFont3BetaTex, 0);
unk_80077D50 sFont3GammaCompTexInfo[] = COMP_TEX_INFO(4, aFont3GammaTex, 0);
unk_80077D50 sFont3PrimeCompTexInfo[] = COMP_TEX_INFO(4, aFont3PrimeTex, 0);
unk_80077D50 sFont3EllipsisCompTexInfo[] = COMP_TEX_INFO(4, aFont3EllipsisTex, 0);
unk_80077D50 sFont3ColonCompTexInfo[] = COMP_TEX_INFO(4, aFont3ColonTex, 0);
unk_80077D50 sFont3PeriodCompTexInfo[] = COMP_TEX_INFO(4, aFont3PeriodTex, 0);
unk_80077D50 sFont3AmpersandCompTexInfo[] = COMP_TEX_INFO(4, aFont3AmpersandTex, 0);
unk_80077D50 sFont3CommaCompTexInfo[] = COMP_TEX_INFO(4, aFont3CommaTex, 0);

unk_80077D50 sFont3DashCompTexInfo[] = COMP_TEX_INFO(4, aFont3DashTex, 0);
unk_80077D50 sFont3Num0CompTexInfo[] = COMP_TEX_INFO(4, aFont3Num0Tex, 0);
unk_80077D50 sFont3Num1CompTexInfo[] = COMP_TEX_INFO(4, aFont3Num1Tex, 0);
unk_80077D50 sFont3Num2CompTexInfo[] = COMP_TEX_INFO(4, aFont3Num2Tex, 0);
unk_80077D50 sFont3Num3CompTexInfo[] = COMP_TEX_INFO(4, aFont3Num3Tex, 0);
unk_80077D50 sFont3Num4CompTexInfo[] = COMP_TEX_INFO(4, aFont3Num4Tex, 0);
unk_80077D50 sFont3Num5CompTexInfo[] = COMP_TEX_INFO(4, aFont3Num5Tex, 0);
unk_80077D50 sFont3Num6CompTexInfo[] = COMP_TEX_INFO(4, aFont3Num6Tex, 0);
unk_80077D50 sFont3Num7CompTexInfo[] = COMP_TEX_INFO(4, aFont3Num7Tex, 0);
unk_80077D50 sFont3Num8CompTexInfo[] = COMP_TEX_INFO(4, aFont3Num8Tex, 0);
unk_80077D50 sFont3Num9CompTexInfo[] = COMP_TEX_INFO(4, aFont3Num9Tex, 0);

unk_80077D50* sFont3CompTexInfos[] = {
    sFont3ACompTexInfo,         sFont3BCompTexInfo,    sFont3CCompTexInfo,     sFont3DCompTexInfo,
    sFont3ECompTexInfo,         sFont3FCompTexInfo,    sFont3GCompTexInfo,     sFont3HCompTexInfo,
    sFont3ICompTexInfo,         sFont3JCompTexInfo,    sFont3KCompTexInfo,     sFont3LCompTexInfo,
    sFont3MCompTexInfo,         sFont3NCompTexInfo,    sFont3OCompTexInfo,     sFont3PCompTexInfo,
    sFont3QCompTexInfo,         sFont3RCompTexInfo,    sFont3SCompTexInfo,     sFont3TCompTexInfo,
    sFont3UCompTexInfo,         sFont3VCompTexInfo,    sFont3WCompTexInfo,     sFont3XCompTexInfo,
    sFont3YCompTexInfo,         sFont3ZCompTexInfo,    sFont3PrimeCompTexInfo, sFont3ACompTexInfo,
    sFont3AmpersandCompTexInfo, sFont3ACompTexInfo,    sFont3DashCompTexInfo,  sFont3ACompTexInfo,
    sFont3Num0CompTexInfo,      sFont3Num1CompTexInfo, sFont3Num2CompTexInfo,  sFont3Num3CompTexInfo,
    sFont3Num4CompTexInfo,      sFont3Num5CompTexInfo, sFont3Num6CompTexInfo,  sFont3Num7CompTexInfo,
    sFont3Num8CompTexInfo,      sFont3Num9CompTexInfo, sFont3ColonCompTexInfo, sFont3PeriodCompTexInfo,
    sFont3EllipsisCompTexInfo,  sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3CommaCompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3AlphaCompTexInfo,     sFont3BetaCompTexInfo, sFont3GammaCompTexInfo, sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3GammaCompTexInfo, sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,    sFont3ACompTexInfo,     sFont3ACompTexInfo,
    sFont3ACompTexInfo,         sFont3ACompTexInfo,
};

//! @bug These textures actually have width 16 and height 8.
// They instead should be cropped or reformatted rather than setting the width here
unk_80077D50 sFont4ACompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4ATex, 8, TEX_HEIGHT(aFont4ATex), 0);
unk_80077D50 sFont4DCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4DTex, 8, TEX_HEIGHT(aFont4DTex), 0);
unk_80077D50 sFont4ECompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4ETex, 8, TEX_HEIGHT(aFont4ETex), 0);
unk_80077D50 sFont4MCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4MTex, 8, TEX_HEIGHT(aFont4MTex), 0);
unk_80077D50 sFont4AmpersandCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4AmpersandTex, 8, TEX_HEIGHT(aFont4AmpersandTex), 0);
#ifndef VERSION_JP
unk_80077D50 sFont4BCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4BTex, 8, TEX_HEIGHT(aFont4BTex), 0);
unk_80077D50 sFont4CCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4CTex, 8, TEX_HEIGHT(aFont4CTex), 0);
unk_80077D50 sFont4FCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4FTex, 8, TEX_HEIGHT(aFont4FTex), 0);
unk_80077D50 sFont4GCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4GTex, 8, TEX_HEIGHT(aFont4GTex), 0);
unk_80077D50 sFont4HCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4HTex, 8, TEX_HEIGHT(aFont4HTex), 0);
unk_80077D50 sFont4ICompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4ITex, 8, TEX_HEIGHT(aFont4ITex), 0);
unk_80077D50 sFont4JCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4JTex, 8, TEX_HEIGHT(aFont4JTex), 0);
unk_80077D50 sFont4KCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4KTex, 8, TEX_HEIGHT(aFont4KTex), 0);
unk_80077D50 sFont4LCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4LTex, 8, TEX_HEIGHT(aFont4LTex), 0);
unk_80077D50 sFont4NCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4NTex, 8, TEX_HEIGHT(aFont4NTex), 0);
unk_80077D50 sFont4OCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4OTex, 8, TEX_HEIGHT(aFont4OTex), 0);
unk_80077D50 sFont4PCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4PTex, 8, TEX_HEIGHT(aFont4PTex), 0);
unk_80077D50 sFont4QCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4QTex, 8, TEX_HEIGHT(aFont4QTex), 0);
unk_80077D50 sFont4RCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4RTex, 8, TEX_HEIGHT(aFont4RTex), 0);
unk_80077D50 sFont4SCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4STex, 8, TEX_HEIGHT(aFont4STex), 0);
unk_80077D50 sFont4TCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4TTex, 8, TEX_HEIGHT(aFont4TTex), 0);
unk_80077D50 sFont4UCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4UTex, 8, TEX_HEIGHT(aFont4UTex), 0);
unk_80077D50 sFont4VCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4VTex, 8, TEX_HEIGHT(aFont4VTex), 0);
unk_80077D50 sFont4WCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4WTex, 8, TEX_HEIGHT(aFont4WTex), 0);
unk_80077D50 sFont4XCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4XTex, 8, TEX_HEIGHT(aFont4XTex), 0);
unk_80077D50 sFont4YCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4YTex, 8, TEX_HEIGHT(aFont4YTex), 0);
unk_80077D50 sFont4ZCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4ZTex, 8, TEX_HEIGHT(aFont4ZTex), 0);
unk_80077D50 sFont4LowerCCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4LowerCTex, 8, TEX_HEIGHT(aFont4LowerCTex), 0);
unk_80077D50 sFont4LowerRCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4LowerRTex, 8, TEX_HEIGHT(aFont4LowerRTex), 0);
unk_80077D50 sFont4LowerSCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4LowerSTex, 8, TEX_HEIGHT(aFont4LowerSTex), 0);
unk_80077D50 sFont4PeriodCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4PeriodTex, 8, TEX_HEIGHT(aFont4PeriodTex), 0);
#endif
unk_80077D50 sFont4KatakanaACompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaATex, 8, TEX_HEIGHT(aFont4KatakanaATex), 0);
unk_80077D50 sFont4KatakanaICompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaITex, 8, TEX_HEIGHT(aFont4KatakanaITex), 0);
unk_80077D50 sFont4KatakanaUCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaUTex, 8, TEX_HEIGHT(aFont4KatakanaUTex), 0);
unk_80077D50 sFont4KatakanaECompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaETex, 8, TEX_HEIGHT(aFont4KatakanaETex), 0);
unk_80077D50 sFont4KatakanaOCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaOTex, 8, TEX_HEIGHT(aFont4KatakanaOTex), 0);
unk_80077D50 sFont4KatakanaKaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaKaTex, 8, TEX_HEIGHT(aFont4KatakanaKaTex), 0);
unk_80077D50 sFont4KatakanaKiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaKiTex, 8, TEX_HEIGHT(aFont4KatakanaKiTex), 0);
unk_80077D50 sFont4KatakanaKuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaKuTex, 8, TEX_HEIGHT(aFont4KatakanaKuTex), 0);
unk_80077D50 sFont4KatakanaKeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaKeTex, 8, TEX_HEIGHT(aFont4KatakanaKeTex), 0);
unk_80077D50 sFont4KatakanaKoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaKoTex, 8, TEX_HEIGHT(aFont4KatakanaKoTex), 0);
unk_80077D50 sFont4KatakanaSaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaSaTex, 8, TEX_HEIGHT(aFont4KatakanaSaTex), 0);
unk_80077D50 sFont4KatakanaShiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaShiTex, 8, TEX_HEIGHT(aFont4KatakanaShiTex), 0);
unk_80077D50 sFont4KatakanaSuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaSuTex, 8, TEX_HEIGHT(aFont4KatakanaSuTex), 0);
unk_80077D50 sFont4KatakanaSeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaSeTex, 8, TEX_HEIGHT(aFont4KatakanaSeTex), 0);
unk_80077D50 sFont4KatakanaSoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaSoTex, 8, TEX_HEIGHT(aFont4KatakanaSoTex), 0);
unk_80077D50 sFont4KatakanaTaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaTaTex, 8, TEX_HEIGHT(aFont4KatakanaTaTex), 0);
unk_80077D50 sFont4KatakanaChiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaChiTex, 8, TEX_HEIGHT(aFont4KatakanaChiTex), 0);
unk_80077D50 sFont4KatakanaTsuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaTsuTex, 8, TEX_HEIGHT(aFont4KatakanaTsuTex), 0);
unk_80077D50 sFont4KatakanaTeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaTeTex, 8, TEX_HEIGHT(aFont4KatakanaTeTex), 0);
unk_80077D50 sFont4KatakanaToCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaToTex, 8, TEX_HEIGHT(aFont4KatakanaToTex), 0);
unk_80077D50 sFont4KatakanaSoukonCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaSoukonTex, 8, TEX_HEIGHT(aFont4KatakanaSoukonTex), 0);
unk_80077D50 sFont4KatakanaNaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNaTex, 8, TEX_HEIGHT(aFont4KatakanaNaTex), 0);
unk_80077D50 sFont4KatakanaNiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNiTex, 8, TEX_HEIGHT(aFont4KatakanaNiTex), 0);
unk_80077D50 sFont4KatakanaNuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNuTex, 8, TEX_HEIGHT(aFont4KatakanaNuTex), 0);
unk_80077D50 sFont4KatakanaNeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNeTex, 8, TEX_HEIGHT(aFont4KatakanaNeTex), 0);
unk_80077D50 sFont4KatakanaNoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNoTex, 8, TEX_HEIGHT(aFont4KatakanaNoTex), 0);
unk_80077D50 sFont4KatakanaHaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaHaTex, 8, TEX_HEIGHT(aFont4KatakanaHaTex), 0);
unk_80077D50 sFont4KatakanaHiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaHiTex, 8, TEX_HEIGHT(aFont4KatakanaHiTex), 0);
unk_80077D50 sFont4KatakanaFuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaFuTex, 8, TEX_HEIGHT(aFont4KatakanaFuTex), 0);
unk_80077D50 sFont4KatakanaHeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaHeTex, 8, TEX_HEIGHT(aFont4KatakanaHeTex), 0);
unk_80077D50 sFont4KatakanaHoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaHoTex, 8, TEX_HEIGHT(aFont4KatakanaHoTex), 0);
unk_80077D50 sFont4KatakanaMaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaMaTex, 8, TEX_HEIGHT(aFont4KatakanaMaTex), 0);
unk_80077D50 sFont4KatakanaMiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaMiTex, 8, TEX_HEIGHT(aFont4KatakanaMiTex), 0);
unk_80077D50 sFont4KatakanaMuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaMuTex, 8, TEX_HEIGHT(aFont4KatakanaMuTex), 0);
unk_80077D50 sFont4KatakanaMeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaMeTex, 8, TEX_HEIGHT(aFont4KatakanaMeTex), 0);
unk_80077D50 sFont4KatakanaMoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaMoTex, 8, TEX_HEIGHT(aFont4KatakanaMoTex), 0);
unk_80077D50 sFont4KatakanaYaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYaTex, 8, TEX_HEIGHT(aFont4KatakanaYaTex), 0);
unk_80077D50 sFont4KatakanaYuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYuTex, 8, TEX_HEIGHT(aFont4KatakanaYuTex), 0);
unk_80077D50 sFont4KatakanaYoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYoTex, 8, TEX_HEIGHT(aFont4KatakanaYoTex), 0);
unk_80077D50 sFont4KatakanaYoonYaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYoonYaTex, 8, TEX_HEIGHT(aFont4KatakanaYoonYaTex), 0);
unk_80077D50 sFont4KatakanaYoonYuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYoonYuTex, 8, TEX_HEIGHT(aFont4KatakanaYoonYuTex), 0);
unk_80077D50 sFont4KatakanaYoonYoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaYoonYoTex, 8, TEX_HEIGHT(aFont4KatakanaYoonYoTex), 0);
unk_80077D50 sFont4KatakanaRaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaRaTex, 8, TEX_HEIGHT(aFont4KatakanaRaTex), 0);
unk_80077D50 sFont4KatakanaRiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaRiTex, 8, TEX_HEIGHT(aFont4KatakanaRiTex), 0);
unk_80077D50 sFont4KatakanaRuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaRuTex, 8, TEX_HEIGHT(aFont4KatakanaRuTex), 0);
unk_80077D50 sFont4KatakanaReCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaReTex, 8, TEX_HEIGHT(aFont4KatakanaReTex), 0);
unk_80077D50 sFont4KatakanaRoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaRoTex, 8, TEX_HEIGHT(aFont4KatakanaRoTex), 0);
unk_80077D50 sFont4KatakanaWaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaWaTex, 8, TEX_HEIGHT(aFont4KatakanaWaTex), 0);
unk_80077D50 sFont4KatakanaWoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaWoTex, 8, TEX_HEIGHT(aFont4KatakanaWoTex), 0);
unk_80077D50 sFont4KatakanaNCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaNTex, 8, TEX_HEIGHT(aFont4KatakanaNTex), 0);
unk_80077D50 sFont4KatakanaGaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaGaTex, 8, TEX_HEIGHT(aFont4KatakanaGaTex), 0);
unk_80077D50 sFont4KatakanaGiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaGiTex, 8, TEX_HEIGHT(aFont4KatakanaGiTex), 0);
unk_80077D50 sFont4KatakanaGuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaGuTex, 8, TEX_HEIGHT(aFont4KatakanaGuTex), 0);
unk_80077D50 sFont4KatakanaGeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaGeTex, 8, TEX_HEIGHT(aFont4KatakanaGeTex), 0);
unk_80077D50 sFont4KatakanaGoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaGoTex, 8, TEX_HEIGHT(aFont4KatakanaGoTex), 0);
unk_80077D50 sFont4KatakanaZaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaZaTex, 8, TEX_HEIGHT(aFont4KatakanaZaTex), 0);
unk_80077D50 sFont4KatakanaJiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaJiTex, 8, TEX_HEIGHT(aFont4KatakanaJiTex), 0);
unk_80077D50 sFont4KatakanaZuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaZuTex, 8, TEX_HEIGHT(aFont4KatakanaZuTex), 0);
unk_80077D50 sFont4KatakanaZeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaZeTex, 8, TEX_HEIGHT(aFont4KatakanaZeTex), 0);
unk_80077D50 sFont4KatakanaZoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaZoTex, 8, TEX_HEIGHT(aFont4KatakanaZoTex), 0);
unk_80077D50 sFont4KatakanaDaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDaTex, 8, TEX_HEIGHT(aFont4KatakanaDaTex), 0);
unk_80077D50 sFont4KatakanaDjiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDjiTex, 8, TEX_HEIGHT(aFont4KatakanaDjiTex), 0);
unk_80077D50 sFont4KatakanaDzuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDzuTex, 8, TEX_HEIGHT(aFont4KatakanaDzuTex), 0);
unk_80077D50 sFont4KatakanaDeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDeTex, 8, TEX_HEIGHT(aFont4KatakanaDeTex), 0);
unk_80077D50 sFont4KatakanaDoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDoTex, 8, TEX_HEIGHT(aFont4KatakanaDoTex), 0);
unk_80077D50 sFont4KatakanaBaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaBaTex, 8, TEX_HEIGHT(aFont4KatakanaBaTex), 0);
unk_80077D50 sFont4KatakanaBiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaBiTex, 8, TEX_HEIGHT(aFont4KatakanaBiTex), 0);
unk_80077D50 sFont4KatakanaBuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaBuTex, 8, TEX_HEIGHT(aFont4KatakanaBuTex), 0);
unk_80077D50 sFont4KatakanaBeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaBeTex, 8, TEX_HEIGHT(aFont4KatakanaBeTex), 0);
unk_80077D50 sFont4KatakanaBoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaBoTex, 8, TEX_HEIGHT(aFont4KatakanaBoTex), 0);
unk_80077D50 sFont4KatakanaPaCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaPaTex, 8, TEX_HEIGHT(aFont4KatakanaPaTex), 0);
unk_80077D50 sFont4KatakanaPiCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaPiTex, 8, TEX_HEIGHT(aFont4KatakanaPiTex), 0);
unk_80077D50 sFont4KatakanaPuCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaPuTex, 8, TEX_HEIGHT(aFont4KatakanaPuTex), 0);
unk_80077D50 sFont4KatakanaPeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaPeTex, 8, TEX_HEIGHT(aFont4KatakanaPeTex), 0);
unk_80077D50 sFont4KatakanaPoCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaPoTex, 8, TEX_HEIGHT(aFont4KatakanaPoTex), 0);
unk_80077D50 sFont4KatakanaDigraphACompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDigraphATex, 8, TEX_HEIGHT(aFont4KatakanaDigraphATex), 0);
unk_80077D50 sFont4KatakanaDigraphICompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDigraphITex, 8, TEX_HEIGHT(aFont4KatakanaDigraphITex), 0);
unk_80077D50 sFont4KatakanaDigraphECompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4KatakanaDigraphETex, 8, TEX_HEIGHT(aFont4KatakanaDigraphETex), 0);
unk_80077D50 sFont4DashCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4DashTex, 8, TEX_HEIGHT(aFont4DashTex), 0);
unk_80077D50 sFont4Num0CompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num0Tex, 8, TEX_HEIGHT(aFont4Num0Tex), 0);
unk_80077D50 sFont4Num1CompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num1Tex, 8, TEX_HEIGHT(aFont4Num1Tex), 0);
unk_80077D50 sFont4Num2CompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num2Tex, 8, TEX_HEIGHT(aFont4Num2Tex), 0);
unk_80077D50 sFont4Num3CompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num3Tex, 8, TEX_HEIGHT(aFont4Num3Tex), 0);
unk_80077D50 sFont4Num4CompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num4Tex, 8, TEX_HEIGHT(aFont4Num4Tex), 0);
unk_80077D50 sFont4Num5CompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num5Tex, 8, TEX_HEIGHT(aFont4Num5Tex), 0);
unk_80077D50 sFont4Num6CompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num6Tex, 8, TEX_HEIGHT(aFont4Num6Tex), 0);
unk_80077D50 sFont4Num7CompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num7Tex, 8, TEX_HEIGHT(aFont4Num7Tex), 0);
unk_80077D50 sFont4Num8CompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num8Tex, 8, TEX_HEIGHT(aFont4Num8Tex), 0);
unk_80077D50 sFont4Num9CompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4Num9Tex, 8, TEX_HEIGHT(aFont4Num9Tex), 0);
unk_80077D50 sFont4PrimeCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4PrimeTex, 8, TEX_HEIGHT(aFont4PrimeTex), 0);
unk_80077D50 sFont4DoublePrimeCompTexInfo[] =
    COMP_TEX_INFO_WH(4, aFont4DoublePrimeTex, 8, TEX_HEIGHT(aFont4DoublePrimeTex), 0);
unk_80077D50 sFont4STCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4STTex, 8, TEX_HEIGHT(aFont4STTex), 0);
unk_80077D50 sFont4NDCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4NDTex, 8, TEX_HEIGHT(aFont4NDTex), 0);
unk_80077D50 sFont4RDCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4RDTex, 8, TEX_HEIGHT(aFont4RDTex), 0);
unk_80077D50 sFont4THCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4THTex, 8, TEX_HEIGHT(aFont4THTex), 0);
unk_80077D50 sFont4PlusCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4PlusTex, 8, TEX_HEIGHT(aFont4PlusTex), 0);
unk_80077D50 sFont4MinusCompTexInfo[] = COMP_TEX_INFO_WH(4, aFont4MinusTex, 8, TEX_HEIGHT(aFont4MinusTex), 0);
unk_80077D50 sFont4PointsCompTexInfo[] = COMP_TEX_INFO(4, aFont4PointsTex, 0);

#ifdef VERSION_JP
unk_80077D50* sFont4CompTexInfos[] = {
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4DCompTexInfo,
    sFont4ECompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4MCompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4PrimeCompTexInfo,
    sFont4DoublePrimeCompTexInfo,
    sFont4AmpersandCompTexInfo,
    sFont4PlusCompTexInfo,
    sFont4MinusCompTexInfo,
    sFont4PointsCompTexInfo,
    sFont4Num0CompTexInfo,
    sFont4Num1CompTexInfo,
    sFont4Num2CompTexInfo,
    sFont4Num3CompTexInfo,
    sFont4Num4CompTexInfo,
    sFont4Num5CompTexInfo,
    sFont4Num6CompTexInfo,
    sFont4Num7CompTexInfo,
    sFont4Num8CompTexInfo,
    sFont4Num9CompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4KatakanaDigraphACompTexInfo,
    sFont4KatakanaACompTexInfo,
    sFont4KatakanaDigraphICompTexInfo,
    sFont4KatakanaICompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaDigraphECompTexInfo,
    sFont4KatakanaECompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaKaCompTexInfo,
    sFont4KatakanaGaCompTexInfo,
    sFont4KatakanaKiCompTexInfo,
    sFont4KatakanaGiCompTexInfo,
    sFont4KatakanaKuCompTexInfo,
    sFont4KatakanaGuCompTexInfo,
    sFont4KatakanaKeCompTexInfo,
    sFont4KatakanaGeCompTexInfo,
    sFont4KatakanaKoCompTexInfo,
    sFont4KatakanaGoCompTexInfo,
    sFont4KatakanaSaCompTexInfo,
    sFont4KatakanaZaCompTexInfo,
    sFont4KatakanaShiCompTexInfo,
    sFont4KatakanaJiCompTexInfo,
    sFont4KatakanaSuCompTexInfo,
    sFont4KatakanaZuCompTexInfo,
    sFont4KatakanaSeCompTexInfo,
    sFont4KatakanaZeCompTexInfo,
    sFont4KatakanaSoCompTexInfo,
    sFont4KatakanaZoCompTexInfo,
    sFont4KatakanaTaCompTexInfo,
    sFont4KatakanaDaCompTexInfo,
    sFont4KatakanaChiCompTexInfo,
    sFont4KatakanaDjiCompTexInfo,
    sFont4KatakanaSoukonCompTexInfo,
    sFont4KatakanaTsuCompTexInfo,
    sFont4KatakanaDzuCompTexInfo,
    sFont4KatakanaTeCompTexInfo,
    sFont4KatakanaDeCompTexInfo,
    sFont4KatakanaToCompTexInfo,
    sFont4KatakanaDoCompTexInfo,
    sFont4KatakanaNaCompTexInfo,
    sFont4KatakanaNiCompTexInfo,
    sFont4KatakanaNuCompTexInfo,
    sFont4KatakanaNeCompTexInfo,
    sFont4KatakanaNoCompTexInfo,
    sFont4KatakanaHaCompTexInfo,
    sFont4KatakanaBaCompTexInfo,
    sFont4KatakanaPaCompTexInfo,
    sFont4KatakanaHiCompTexInfo,
    sFont4KatakanaBiCompTexInfo,
    sFont4KatakanaPiCompTexInfo,
    sFont4KatakanaFuCompTexInfo,
    sFont4KatakanaBuCompTexInfo,
    sFont4KatakanaPuCompTexInfo,
    sFont4KatakanaHeCompTexInfo,
    sFont4KatakanaBeCompTexInfo,
    sFont4KatakanaPeCompTexInfo,
    sFont4KatakanaHoCompTexInfo,
    sFont4KatakanaBoCompTexInfo,
    sFont4KatakanaPoCompTexInfo,
    sFont4KatakanaMaCompTexInfo,
    sFont4KatakanaMiCompTexInfo,
    sFont4KatakanaMuCompTexInfo,
    sFont4KatakanaMeCompTexInfo,
    sFont4KatakanaMoCompTexInfo,
    sFont4KatakanaYoonYaCompTexInfo,
    sFont4KatakanaYaCompTexInfo,
    sFont4KatakanaYoonYuCompTexInfo,
    sFont4KatakanaYuCompTexInfo,
    sFont4KatakanaYoonYoCompTexInfo,
    sFont4KatakanaYoCompTexInfo,
    sFont4KatakanaRaCompTexInfo,
    sFont4KatakanaRiCompTexInfo,
    sFont4KatakanaRuCompTexInfo,
    sFont4KatakanaReCompTexInfo,
    sFont4KatakanaRoCompTexInfo,
    sFont4KatakanaWaCompTexInfo,
    sFont4KatakanaWoCompTexInfo,
    sFont4KatakanaNCompTexInfo,
    sFont4KatakanaDigraphACompTexInfo,
    sFont4KatakanaACompTexInfo,
    sFont4KatakanaDigraphICompTexInfo,
    sFont4KatakanaICompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaDigraphECompTexInfo,
    sFont4KatakanaECompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaKaCompTexInfo,
    sFont4KatakanaGaCompTexInfo,
    sFont4KatakanaKiCompTexInfo,
    sFont4KatakanaGiCompTexInfo,
    sFont4KatakanaKuCompTexInfo,
    sFont4KatakanaGuCompTexInfo,
    sFont4KatakanaKeCompTexInfo,
    sFont4KatakanaGeCompTexInfo,
    sFont4KatakanaKoCompTexInfo,
    sFont4KatakanaGoCompTexInfo,
    sFont4KatakanaSaCompTexInfo,
    sFont4KatakanaZaCompTexInfo,
    sFont4KatakanaShiCompTexInfo,
    sFont4KatakanaJiCompTexInfo,
    sFont4KatakanaSuCompTexInfo,
    sFont4KatakanaZuCompTexInfo,
    sFont4KatakanaSeCompTexInfo,
    sFont4KatakanaZeCompTexInfo,
    sFont4KatakanaSoCompTexInfo,
    sFont4KatakanaZoCompTexInfo,
    sFont4KatakanaTaCompTexInfo,
    sFont4KatakanaDaCompTexInfo,
    sFont4KatakanaChiCompTexInfo,
    sFont4KatakanaDjiCompTexInfo,
    sFont4KatakanaSoukonCompTexInfo,
    sFont4KatakanaTsuCompTexInfo,
    sFont4KatakanaDzuCompTexInfo,
    sFont4KatakanaTeCompTexInfo,
    sFont4KatakanaDeCompTexInfo,
    sFont4KatakanaToCompTexInfo,
    sFont4KatakanaDoCompTexInfo,
    sFont4KatakanaNaCompTexInfo,
    sFont4KatakanaNiCompTexInfo,
    sFont4KatakanaNuCompTexInfo,
    sFont4KatakanaNeCompTexInfo,
    sFont4KatakanaNoCompTexInfo,
    sFont4KatakanaHaCompTexInfo,
    sFont4KatakanaBaCompTexInfo,
    sFont4KatakanaPaCompTexInfo,
    sFont4KatakanaHiCompTexInfo,
    sFont4KatakanaBiCompTexInfo,
    sFont4KatakanaPiCompTexInfo,
    sFont4KatakanaFuCompTexInfo,
    sFont4KatakanaBuCompTexInfo,
    sFont4KatakanaPuCompTexInfo,
    sFont4KatakanaHeCompTexInfo,
    sFont4KatakanaBeCompTexInfo,
    sFont4KatakanaPeCompTexInfo,
    sFont4KatakanaHoCompTexInfo,
    sFont4KatakanaBoCompTexInfo,
    sFont4KatakanaPoCompTexInfo,
    sFont4KatakanaMaCompTexInfo,
    sFont4KatakanaMiCompTexInfo,
    sFont4KatakanaMuCompTexInfo,
    sFont4KatakanaMeCompTexInfo,
    sFont4KatakanaMoCompTexInfo,
    sFont4KatakanaYoonYaCompTexInfo,
    sFont4KatakanaYaCompTexInfo,
    sFont4KatakanaYoonYuCompTexInfo,
    sFont4KatakanaYuCompTexInfo,
    sFont4KatakanaYoonYoCompTexInfo,
    sFont4KatakanaYoCompTexInfo,
    sFont4KatakanaRaCompTexInfo,
    sFont4KatakanaRiCompTexInfo,
    sFont4KatakanaRuCompTexInfo,
    sFont4KatakanaReCompTexInfo,
    sFont4KatakanaRoCompTexInfo,
    sFont4KatakanaWaCompTexInfo,
    sFont4KatakanaWoCompTexInfo,
    sFont4KatakanaNCompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4NDCompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4RDCompTexInfo,
    sFont4STCompTexInfo,
    sFont4THCompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4DashCompTexInfo,
};
#else
unk_80077D50* sFont4CompTexInfos[] = {
    sFont4ACompTexInfo,
    sFont4BCompTexInfo,
    sFont4CCompTexInfo,
    sFont4DCompTexInfo,
    sFont4ECompTexInfo,
    sFont4FCompTexInfo,
    sFont4GCompTexInfo,
    sFont4HCompTexInfo,
    sFont4ICompTexInfo,
    sFont4JCompTexInfo,
    sFont4KCompTexInfo,
    sFont4LCompTexInfo,
    sFont4MCompTexInfo,
    sFont4NCompTexInfo,
    sFont4OCompTexInfo,
    sFont4PCompTexInfo,
    sFont4QCompTexInfo,
    sFont4RCompTexInfo,
    sFont4SCompTexInfo,
    sFont4TCompTexInfo,
    sFont4UCompTexInfo,
    sFont4VCompTexInfo,
    sFont4WCompTexInfo,
    sFont4XCompTexInfo,
    sFont4YCompTexInfo,
    sFont4ZCompTexInfo,
    sFont4PrimeCompTexInfo,
    sFont4DoublePrimeCompTexInfo,
    sFont4AmpersandCompTexInfo,
    sFont4PlusCompTexInfo,
    sFont4MinusCompTexInfo,
    sFont4PointsCompTexInfo,
    sFont4Num0CompTexInfo,
    sFont4Num1CompTexInfo,
    sFont4Num2CompTexInfo,
    sFont4Num3CompTexInfo,
    sFont4Num4CompTexInfo,
    sFont4Num5CompTexInfo,
    sFont4Num6CompTexInfo,
    sFont4Num7CompTexInfo,
    sFont4Num8CompTexInfo,
    sFont4Num9CompTexInfo,
    sFont4ACompTexInfo,
    sFont4PeriodCompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4KatakanaDigraphACompTexInfo,
    sFont4KatakanaACompTexInfo,
    sFont4LowerCCompTexInfo,
    sFont4KatakanaICompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaDigraphECompTexInfo,
    sFont4KatakanaECompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaKaCompTexInfo,
    sFont4KatakanaGaCompTexInfo,
    sFont4KatakanaKiCompTexInfo,
    sFont4KatakanaGiCompTexInfo,
    sFont4KatakanaKuCompTexInfo,
    sFont4KatakanaGuCompTexInfo,
    sFont4KatakanaKeCompTexInfo,
    sFont4LowerRCompTexInfo,
    sFont4LowerSCompTexInfo,
    sFont4KatakanaGoCompTexInfo,
    sFont4KatakanaSaCompTexInfo,
    sFont4KatakanaZaCompTexInfo,
    sFont4KatakanaShiCompTexInfo,
    sFont4KatakanaJiCompTexInfo,
    sFont4KatakanaSuCompTexInfo,
    sFont4KatakanaZuCompTexInfo,
    sFont4KatakanaSeCompTexInfo,
    sFont4KatakanaZeCompTexInfo,
    sFont4KatakanaSoCompTexInfo,
    sFont4KatakanaZoCompTexInfo,
    sFont4KatakanaTaCompTexInfo,
    sFont4KatakanaDaCompTexInfo,
    sFont4KatakanaChiCompTexInfo,
    sFont4KatakanaDjiCompTexInfo,
    sFont4KatakanaSoukonCompTexInfo,
    sFont4KatakanaTsuCompTexInfo,
    sFont4KatakanaDzuCompTexInfo,
    sFont4KatakanaTeCompTexInfo,
    sFont4KatakanaDeCompTexInfo,
    sFont4KatakanaToCompTexInfo,
    sFont4KatakanaDoCompTexInfo,
    sFont4KatakanaNaCompTexInfo,
    sFont4KatakanaNiCompTexInfo,
    sFont4KatakanaNuCompTexInfo,
    sFont4KatakanaNeCompTexInfo,
    sFont4KatakanaNoCompTexInfo,
    sFont4KatakanaHaCompTexInfo,
    sFont4KatakanaBaCompTexInfo,
    sFont4KatakanaPaCompTexInfo,
    sFont4KatakanaHiCompTexInfo,
    sFont4KatakanaBiCompTexInfo,
    sFont4KatakanaPiCompTexInfo,
    sFont4KatakanaFuCompTexInfo,
    sFont4KatakanaBuCompTexInfo,
    sFont4KatakanaPuCompTexInfo,
    sFont4KatakanaHeCompTexInfo,
    sFont4KatakanaBeCompTexInfo,
    sFont4KatakanaPeCompTexInfo,
    sFont4KatakanaHoCompTexInfo,
    sFont4KatakanaBoCompTexInfo,
    sFont4KatakanaPoCompTexInfo,
    sFont4KatakanaMaCompTexInfo,
    sFont4KatakanaMiCompTexInfo,
    sFont4KatakanaMuCompTexInfo,
    sFont4KatakanaMeCompTexInfo,
    sFont4KatakanaMoCompTexInfo,
    sFont4KatakanaYoonYaCompTexInfo,
    sFont4KatakanaYaCompTexInfo,
    sFont4KatakanaYoonYuCompTexInfo,
    sFont4KatakanaYuCompTexInfo,
    sFont4KatakanaYoonYoCompTexInfo,
    sFont4KatakanaYoCompTexInfo,
    sFont4KatakanaRaCompTexInfo,
    sFont4KatakanaRiCompTexInfo,
    sFont4KatakanaRuCompTexInfo,
    sFont4KatakanaReCompTexInfo,
    sFont4KatakanaRoCompTexInfo,
    sFont4KatakanaWaCompTexInfo,
    sFont4KatakanaWoCompTexInfo,
    sFont4KatakanaNCompTexInfo,
    sFont4KatakanaDigraphACompTexInfo,
    sFont4KatakanaACompTexInfo,
    sFont4KatakanaDigraphICompTexInfo,
    sFont4KatakanaICompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaDigraphECompTexInfo,
    sFont4KatakanaECompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaKaCompTexInfo,
    sFont4KatakanaGaCompTexInfo,
    sFont4KatakanaKiCompTexInfo,
    sFont4KatakanaGiCompTexInfo,
    sFont4KatakanaKuCompTexInfo,
    sFont4KatakanaGuCompTexInfo,
    sFont4KatakanaKeCompTexInfo,
    sFont4KatakanaGeCompTexInfo,
    sFont4KatakanaKoCompTexInfo,
    sFont4KatakanaGoCompTexInfo,
    sFont4KatakanaSaCompTexInfo,
    sFont4KatakanaZaCompTexInfo,
    sFont4KatakanaShiCompTexInfo,
    sFont4KatakanaJiCompTexInfo,
    sFont4KatakanaSuCompTexInfo,
    sFont4KatakanaZuCompTexInfo,
    sFont4KatakanaSeCompTexInfo,
    sFont4KatakanaZeCompTexInfo,
    sFont4KatakanaSoCompTexInfo,
    sFont4KatakanaZoCompTexInfo,
    sFont4KatakanaTaCompTexInfo,
    sFont4KatakanaDaCompTexInfo,
    sFont4KatakanaChiCompTexInfo,
    sFont4KatakanaDjiCompTexInfo,
    sFont4KatakanaSoukonCompTexInfo,
    sFont4KatakanaTsuCompTexInfo,
    sFont4KatakanaDzuCompTexInfo,
    sFont4KatakanaTeCompTexInfo,
    sFont4KatakanaDeCompTexInfo,
    sFont4KatakanaToCompTexInfo,
    sFont4KatakanaDoCompTexInfo,
    sFont4KatakanaNaCompTexInfo,
    sFont4KatakanaNiCompTexInfo,
    sFont4KatakanaNuCompTexInfo,
    sFont4KatakanaNeCompTexInfo,
    sFont4KatakanaNoCompTexInfo,
    sFont4KatakanaHaCompTexInfo,
    sFont4KatakanaBaCompTexInfo,
    sFont4KatakanaPaCompTexInfo,
    sFont4KatakanaHiCompTexInfo,
    sFont4KatakanaBiCompTexInfo,
    sFont4KatakanaPiCompTexInfo,
    sFont4KatakanaFuCompTexInfo,
    sFont4KatakanaBuCompTexInfo,
    sFont4KatakanaPuCompTexInfo,
    sFont4KatakanaHeCompTexInfo,
    sFont4KatakanaBeCompTexInfo,
    sFont4KatakanaPeCompTexInfo,
    sFont4KatakanaHoCompTexInfo,
    sFont4KatakanaBoCompTexInfo,
    sFont4KatakanaPoCompTexInfo,
    sFont4KatakanaMaCompTexInfo,
    sFont4KatakanaMiCompTexInfo,
    sFont4KatakanaMuCompTexInfo,
    sFont4KatakanaMeCompTexInfo,
    sFont4KatakanaMoCompTexInfo,
    sFont4KatakanaYoonYaCompTexInfo,
    sFont4KatakanaYaCompTexInfo,
    sFont4KatakanaYoonYuCompTexInfo,
    sFont4KatakanaYuCompTexInfo,
    sFont4KatakanaYoonYoCompTexInfo,
    sFont4KatakanaYoCompTexInfo,
    sFont4KatakanaRaCompTexInfo,
    sFont4KatakanaRiCompTexInfo,
    sFont4KatakanaRuCompTexInfo,
    sFont4KatakanaReCompTexInfo,
    sFont4KatakanaRoCompTexInfo,
    sFont4KatakanaWaCompTexInfo,
    sFont4KatakanaWoCompTexInfo,
    sFont4KatakanaNCompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4NDCompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4RDCompTexInfo,
    sFont4STCompTexInfo,
    sFont4THCompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4DashCompTexInfo,
};
#endif

unk_80077D50 sFont5Num0CompTexInfo[] = COMP_TEX_INFO(4, aFont5Num0Tex, 0);
unk_80077D50 sFont5Num1CompTexInfo[] = COMP_TEX_INFO(4, aFont5Num1Tex, 0);
unk_80077D50 sFont5Num2CompTexInfo[] = COMP_TEX_INFO(4, aFont5Num2Tex, 0);
unk_80077D50 sFont5Num3CompTexInfo[] = COMP_TEX_INFO(4, aFont5Num3Tex, 0);
unk_80077D50 sFont5Num4CompTexInfo[] = COMP_TEX_INFO(4, aFont5Num4Tex, 0);
unk_80077D50 sFont5Num5CompTexInfo[] = COMP_TEX_INFO(4, aFont5Num5Tex, 0);
unk_80077D50 sFont5Num6CompTexInfo[] = COMP_TEX_INFO(4, aFont5Num6Tex, 0);
unk_80077D50 sFont5Num7CompTexInfo[] = COMP_TEX_INFO(4, aFont5Num7Tex, 0);
unk_80077D50 sFont5Num8CompTexInfo[] = COMP_TEX_INFO(4, aFont5Num8Tex, 0);
unk_80077D50 sFont5Num9CompTexInfo[] = COMP_TEX_INFO(4, aFont5Num9Tex, 0);
unk_80077D50 sFont5VCompTexInfo[] = COMP_TEX_INFO(4, aFont5VTex, 0);
unk_80077D50 sFont5OpenParenthesisCompTexInfo[] = COMP_TEX_INFO(4, aFont5OpenParenthesisTex, 0);
unk_80077D50 sFont5CloseParenthesisCompTexInfo[] = COMP_TEX_INFO(4, aFont5CloseParenthesisTex, 0);
unk_80077D50 sFont5STCompTexInfo[] = COMP_TEX_INFO(4, aFont5STTex, 0);
unk_80077D50 sFont5NDCompTexInfo[] = COMP_TEX_INFO(4, aFont5NDTex, 0);
unk_80077D50 sFont5RDCompTexInfo[] = COMP_TEX_INFO(4, aFont5RDTex, 0);
unk_80077D50 sFont5THCompTexInfo[] = COMP_TEX_INFO(4, aFont5THTex, 0);
unk_80077D50 sFont5PlusCompTexInfo[] = COMP_TEX_INFO(4, aFont5PlusTex, 0);
unk_80077D50 sFont5UpArrowCompTexInfo[] = COMP_TEX_INFO(4, aFont5UpArrowTex, 0);
unk_80077D50 sFont5DownArrowCompTexInfo[] = COMP_TEX_INFO(4, aFont5DownArrowTex, 0);
unk_80077D50 sFont5SideArrowCompTexInfo[] = COMP_TEX_INFO(4, aFont5SideArrowTex, 0);
unk_80077D50 sFont5PointsCompTexInfo[] = COMP_TEX_INFO_DEF(20, aFont5PointsTex);
unk_80077D50 sFont5PlayerCompTexInfo[] = COMP_TEX_INFO_DEF(20, aFont5PlayerTex);
unk_80077D50 sFont5ComputerCompTexInfo[] = COMP_TEX_INFO_DEF(20, aFont5ComputerTex);
unk_80077D50 sFont5SelectCourseCompTexInfo[] = COMP_TEX_INFO_DEF(20, aFont5SelectCourseTex);
unk_80077D50 sFont5QuitCompTexInfo[] = COMP_TEX_INFO_DEF(20, aFont5QuitTex);

unk_80077D50* sFont5CompTexInfos[] = {
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont4PrimeCompTexInfo,
    sFont4DoublePrimeCompTexInfo,
    sFont4AmpersandCompTexInfo,
    sFont5PlusCompTexInfo,
    sFont4MinusCompTexInfo,
    sFont5PointsCompTexInfo,
    sFont5Num0CompTexInfo,
    sFont5Num1CompTexInfo,
    sFont5Num2CompTexInfo,
    sFont5Num3CompTexInfo,
    sFont5Num4CompTexInfo,
    sFont5Num5CompTexInfo,
    sFont5Num6CompTexInfo,
    sFont5Num7CompTexInfo,
    sFont5Num8CompTexInfo,
    sFont5Num9CompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont4ACompTexInfo,
    sFont5OpenParenthesisCompTexInfo,
    sFont5CloseParenthesisCompTexInfo,
    sFont4ACompTexInfo,
    sFont4KatakanaDigraphACompTexInfo,
    sFont4KatakanaACompTexInfo,
    sFont4KatakanaDigraphICompTexInfo,
    sFont4KatakanaICompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaDigraphECompTexInfo,
    sFont4KatakanaECompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaKaCompTexInfo,
    sFont4KatakanaGaCompTexInfo,
    sFont4KatakanaKiCompTexInfo,
    sFont4KatakanaGiCompTexInfo,
    sFont4KatakanaKuCompTexInfo,
    sFont4KatakanaGuCompTexInfo,
    sFont4KatakanaKeCompTexInfo,
    sFont4KatakanaGeCompTexInfo,
    sFont4KatakanaKoCompTexInfo,
    sFont4KatakanaGoCompTexInfo,
    sFont4KatakanaSaCompTexInfo,
    sFont4KatakanaZaCompTexInfo,
    sFont4KatakanaShiCompTexInfo,
    sFont4KatakanaJiCompTexInfo,
    sFont4KatakanaSuCompTexInfo,
    sFont4KatakanaZuCompTexInfo,
    sFont4KatakanaSeCompTexInfo,
    sFont4KatakanaZeCompTexInfo,
    sFont4KatakanaSoCompTexInfo,
    sFont4KatakanaZoCompTexInfo,
    sFont4KatakanaTaCompTexInfo,
    sFont4KatakanaDaCompTexInfo,
    sFont4KatakanaChiCompTexInfo,
    sFont4KatakanaDjiCompTexInfo,
    sFont4KatakanaSoukonCompTexInfo,
    sFont4KatakanaTsuCompTexInfo,
    sFont4KatakanaDzuCompTexInfo,
    sFont4KatakanaTeCompTexInfo,
    sFont4KatakanaDeCompTexInfo,
    sFont4KatakanaToCompTexInfo,
    sFont4KatakanaDoCompTexInfo,
    sFont4KatakanaNaCompTexInfo,
    sFont4KatakanaNiCompTexInfo,
    sFont4KatakanaNuCompTexInfo,
    sFont4KatakanaNeCompTexInfo,
    sFont4KatakanaNoCompTexInfo,
    sFont4KatakanaHaCompTexInfo,
    sFont4KatakanaBaCompTexInfo,
    sFont4KatakanaPaCompTexInfo,
    sFont4KatakanaHiCompTexInfo,
    sFont4KatakanaBiCompTexInfo,
    sFont4KatakanaPiCompTexInfo,
    sFont4KatakanaFuCompTexInfo,
    sFont4KatakanaBuCompTexInfo,
    sFont4KatakanaPuCompTexInfo,
    sFont4KatakanaHeCompTexInfo,
    sFont4KatakanaBeCompTexInfo,
    sFont4KatakanaPeCompTexInfo,
    sFont4KatakanaHoCompTexInfo,
    sFont4KatakanaBoCompTexInfo,
    sFont4KatakanaPoCompTexInfo,
    sFont4KatakanaMaCompTexInfo,
    sFont4KatakanaMiCompTexInfo,
    sFont4KatakanaMuCompTexInfo,
    sFont4KatakanaMeCompTexInfo,
    sFont4KatakanaMoCompTexInfo,
    sFont4KatakanaYoonYaCompTexInfo,
    sFont4KatakanaYaCompTexInfo,
    sFont4KatakanaYoonYuCompTexInfo,
    sFont4KatakanaYuCompTexInfo,
    sFont4KatakanaYoonYoCompTexInfo,
    sFont4KatakanaYoCompTexInfo,
    sFont4KatakanaRaCompTexInfo,
    sFont4KatakanaRiCompTexInfo,
    sFont4KatakanaRuCompTexInfo,
    sFont4KatakanaReCompTexInfo,
    sFont4KatakanaRoCompTexInfo,
    sFont4KatakanaWaCompTexInfo,
    sFont4KatakanaWoCompTexInfo,
    sFont4KatakanaNCompTexInfo,
    sFont4KatakanaDigraphACompTexInfo,
    sFont4KatakanaACompTexInfo,
    sFont4KatakanaDigraphICompTexInfo,
    sFont4KatakanaICompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaUCompTexInfo,
    sFont4KatakanaDigraphECompTexInfo,
    sFont4KatakanaECompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaOCompTexInfo,
    sFont4KatakanaKaCompTexInfo,
    sFont4KatakanaGaCompTexInfo,
    sFont4KatakanaKiCompTexInfo,
    sFont4KatakanaGiCompTexInfo,
    sFont4KatakanaKuCompTexInfo,
    sFont4KatakanaGuCompTexInfo,
    sFont4KatakanaKeCompTexInfo,
    sFont4KatakanaGeCompTexInfo,
    sFont4KatakanaKoCompTexInfo,
    sFont4KatakanaGoCompTexInfo,
    sFont4KatakanaSaCompTexInfo,
    sFont4KatakanaZaCompTexInfo,
    sFont4KatakanaShiCompTexInfo,
    sFont4KatakanaJiCompTexInfo,
    sFont4KatakanaSuCompTexInfo,
    sFont4KatakanaZuCompTexInfo,
    sFont4KatakanaSeCompTexInfo,
    sFont4KatakanaZeCompTexInfo,
    sFont4KatakanaSoCompTexInfo,
    sFont4KatakanaZoCompTexInfo,
    sFont4KatakanaTaCompTexInfo,
    sFont4KatakanaDaCompTexInfo,
    sFont4KatakanaChiCompTexInfo,
    sFont4KatakanaDjiCompTexInfo,
    sFont4KatakanaSoukonCompTexInfo,
    sFont4KatakanaTsuCompTexInfo,
    sFont4KatakanaDzuCompTexInfo,
    sFont4KatakanaTeCompTexInfo,
    sFont4KatakanaDeCompTexInfo,
    sFont4KatakanaToCompTexInfo,
    sFont4KatakanaDoCompTexInfo,
    sFont4KatakanaNaCompTexInfo,
    sFont4KatakanaNiCompTexInfo,
    sFont4KatakanaNuCompTexInfo,
    sFont4KatakanaNeCompTexInfo,
    sFont4KatakanaNoCompTexInfo,
    sFont4KatakanaHaCompTexInfo,
    sFont4KatakanaBaCompTexInfo,
    sFont4KatakanaPaCompTexInfo,
    sFont4KatakanaHiCompTexInfo,
    sFont4KatakanaBiCompTexInfo,
    sFont4KatakanaPiCompTexInfo,
    sFont4KatakanaFuCompTexInfo,
    sFont4KatakanaBuCompTexInfo,
    sFont4KatakanaPuCompTexInfo,
    sFont4KatakanaHeCompTexInfo,
    sFont4KatakanaBeCompTexInfo,
    sFont4KatakanaPeCompTexInfo,
    sFont4KatakanaHoCompTexInfo,
    sFont4KatakanaBoCompTexInfo,
    sFont4KatakanaPoCompTexInfo,
    sFont4KatakanaMaCompTexInfo,
    sFont4KatakanaMiCompTexInfo,
    sFont4KatakanaMuCompTexInfo,
    sFont4KatakanaMeCompTexInfo,
    sFont4KatakanaMoCompTexInfo,
    sFont4KatakanaYoonYaCompTexInfo,
    sFont4KatakanaYaCompTexInfo,
    sFont4KatakanaYoonYuCompTexInfo,
    sFont4KatakanaYuCompTexInfo,
    sFont4KatakanaYoonYoCompTexInfo,
    sFont4KatakanaYoCompTexInfo,
    sFont4KatakanaRaCompTexInfo,
    sFont4KatakanaRiCompTexInfo,
    sFont4KatakanaRuCompTexInfo,
    sFont4KatakanaReCompTexInfo,
    sFont4KatakanaRoCompTexInfo,
    sFont4KatakanaWaCompTexInfo,
    sFont4KatakanaWoCompTexInfo,
    sFont4KatakanaNCompTexInfo,
    sFont5ComputerCompTexInfo,
    sFont5VCompTexInfo,
    sFont5SelectCourseCompTexInfo,
    sFont5DownArrowCompTexInfo,
    sFont5QuitCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5SideArrowCompTexInfo,
    sFont5NDCompTexInfo,
    sFont5VCompTexInfo,
    sFont5PlayerCompTexInfo,
    sFont5VCompTexInfo,
    sFont5RDCompTexInfo,
    sFont5STCompTexInfo,
    sFont5THCompTexInfo,
    sFont5UpArrowCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
    sFont5VCompTexInfo,
};

unk_80077D50 sFont6ACompTexInfo[] = COMP_TEX_INFO(4, aFont6ATex, 0);
unk_80077D50 sFont6BCompTexInfo[] = COMP_TEX_INFO(4, aFont6BTex, 0);
unk_80077D50 sFont6CCompTexInfo[] = COMP_TEX_INFO(4, aFont6CTex, 0);
unk_80077D50 sFont6DCompTexInfo[] = COMP_TEX_INFO(4, aFont6DTex, 0);
unk_80077D50 sFont6ECompTexInfo[] = COMP_TEX_INFO(4, aFont6ETex, 0);
unk_80077D50 sFont6FCompTexInfo[] = COMP_TEX_INFO(4, aFont6FTex, 0);
unk_80077D50 sFont6GCompTexInfo[] = COMP_TEX_INFO(4, aFont6GTex, 0);
unk_80077D50 sFont6HCompTexInfo[] = COMP_TEX_INFO(4, aFont6HTex, 0);
unk_80077D50 sFont6ICompTexInfo[] = COMP_TEX_INFO(4, aFont6ITex, 0);
unk_80077D50 sFont6JCompTexInfo[] = COMP_TEX_INFO(4, aFont6JTex, 0);
unk_80077D50 sFont6KCompTexInfo[] = COMP_TEX_INFO(4, aFont6KTex, 0);
unk_80077D50 sFont6LCompTexInfo[] = COMP_TEX_INFO(4, aFont6LTex, 0);
unk_80077D50 sFont6MCompTexInfo[] = COMP_TEX_INFO(4, aFont6MTex, 0);
unk_80077D50 sFont6NCompTexInfo[] = COMP_TEX_INFO(4, aFont6NTex, 0);
unk_80077D50 sFont6OCompTexInfo[] = COMP_TEX_INFO(4, aFont6OTex, 0);
unk_80077D50 sFont6PCompTexInfo[] = COMP_TEX_INFO(4, aFont6PTex, 0);
unk_80077D50 sFont6QCompTexInfo[] = COMP_TEX_INFO(4, aFont6QTex, 0);
unk_80077D50 sFont6RCompTexInfo[] = COMP_TEX_INFO(4, aFont6RTex, 0);
unk_80077D50 sFont6SCompTexInfo[] = COMP_TEX_INFO(4, aFont6STex, 0);
unk_80077D50 sFont6TCompTexInfo[] = COMP_TEX_INFO(4, aFont6TTex, 0);
unk_80077D50 sFont6UCompTexInfo[] = COMP_TEX_INFO(4, aFont6UTex, 0);
unk_80077D50 sFont6VCompTexInfo[] = COMP_TEX_INFO(4, aFont6VTex, 0);
unk_80077D50 sFont6WCompTexInfo[] = COMP_TEX_INFO(4, aFont6WTex, 0);
unk_80077D50 sFont6XCompTexInfo[] = COMP_TEX_INFO(4, aFont6XTex, 0);
unk_80077D50 sFont6YCompTexInfo[] = COMP_TEX_INFO(4, aFont6YTex, 0);
unk_80077D50 sFont6ZCompTexInfo[] = COMP_TEX_INFO(4, aFont6ZTex, 0);
unk_80077D50 sFont6Num0CompTexInfo[] = COMP_TEX_INFO(4, aFont6Num0Tex, 0);
unk_80077D50 sFont6Num1CompTexInfo[] = COMP_TEX_INFO(4, aFont6Num1Tex, 0);
unk_80077D50 sFont6Num2CompTexInfo[] = COMP_TEX_INFO(4, aFont6Num2Tex, 0);
unk_80077D50 sFont6Num3CompTexInfo[] = COMP_TEX_INFO(4, aFont6Num3Tex, 0);
unk_80077D50 sFont6Num4CompTexInfo[] = COMP_TEX_INFO(4, aFont6Num4Tex, 0);
unk_80077D50 sFont6Num5CompTexInfo[] = COMP_TEX_INFO(4, aFont6Num5Tex, 0);
unk_80077D50 sFont6Num6CompTexInfo[] = COMP_TEX_INFO(4, aFont6Num6Tex, 0);
unk_80077D50 sFont6Num7CompTexInfo[] = COMP_TEX_INFO(4, aFont6Num7Tex, 0);
unk_80077D50 sFont6Num8CompTexInfo[] = COMP_TEX_INFO(4, aFont6Num8Tex, 0);
unk_80077D50 sFont6Num9CompTexInfo[] = COMP_TEX_INFO(4, aFont6Num9Tex, 0);
unk_80077D50 sFont6AlphaCompTexInfo[] = COMP_TEX_INFO(4, aFont6AlphaTex, 0);
unk_80077D50 sFont6BetaCompTexInfo[] = COMP_TEX_INFO(4, aFont6BetaTex, 0);
unk_80077D50 sFont6HiraganaNiCompTexInfo[] = COMP_TEX_INFO(4, aFont6HiraganaNiTex, 0);
unk_80077D50 sFont6AmpersandCompTexInfo[] = COMP_TEX_INFO(4, aFont6AmpersandTex, 0);
unk_80077D50 sFont6CommaCompTexInfo[] = COMP_TEX_INFO(4, aFont6CommaTex, 0);
unk_80077D50 sFont6DoublePrimeCompTexInfo[] = COMP_TEX_INFO(4, aFont6DoublePrimeTex, 0);
unk_80077D50 sFont6DashCompTexInfo[] = COMP_TEX_INFO(4, aFont6DashTex, 0);
unk_80077D50 sFont6PeriodCompTexInfo[] = COMP_TEX_INFO(4, aFont6PeriodTex, 0);
unk_80077D50 sFont6PrimeCompTexInfo[] = COMP_TEX_INFO(4, aFont6PrimeTex, 0);
unk_80077D50 sFont6UnderscoreCompTexInfo[] = COMP_TEX_INFO(4, aFont6UnderscoreTex, 0);

unk_80077D50* sFont6CompTexInfos[] = {
    sFont6ACompTexInfo,         sFont6BCompTexInfo,    sFont6CCompTexInfo,          sFont6DCompTexInfo,
    sFont6ECompTexInfo,         sFont6FCompTexInfo,    sFont6GCompTexInfo,          sFont6HCompTexInfo,
    sFont6ICompTexInfo,         sFont6JCompTexInfo,    sFont6KCompTexInfo,          sFont6LCompTexInfo,
    sFont6MCompTexInfo,         sFont6NCompTexInfo,    sFont6OCompTexInfo,          sFont6PCompTexInfo,
    sFont6QCompTexInfo,         sFont6RCompTexInfo,    sFont6SCompTexInfo,          sFont6TCompTexInfo,
    sFont6UCompTexInfo,         sFont6VCompTexInfo,    sFont6WCompTexInfo,          sFont6XCompTexInfo,
    sFont6YCompTexInfo,         sFont6ZCompTexInfo,    sFont6PrimeCompTexInfo,      sFont6DoublePrimeCompTexInfo,
    sFont6AmpersandCompTexInfo, sFont6ACompTexInfo,    sFont6DashCompTexInfo,       sFont6ACompTexInfo,
    sFont6Num0CompTexInfo,      sFont6Num1CompTexInfo, sFont6Num2CompTexInfo,       sFont6Num3CompTexInfo,
    sFont6Num4CompTexInfo,      sFont6Num5CompTexInfo, sFont6Num6CompTexInfo,       sFont6Num7CompTexInfo,
    sFont6Num8CompTexInfo,      sFont6Num9CompTexInfo, sFont6ACompTexInfo,          sFont6PeriodCompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6CommaCompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6HiraganaNiCompTexInfo, sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6AlphaCompTexInfo,     sFont6BetaCompTexInfo, sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,         sFont6ACompTexInfo,    sFont6ACompTexInfo,          sFont6ACompTexInfo,
    sFont6ACompTexInfo,
};

unk_80077D50 sMachineStatACompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineStatATex);
unk_80077D50 sMachineStatBCompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineStatBTex);
unk_80077D50 sMachineStatCCompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineStatCTex);
unk_80077D50 sMachineStatDCompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineStatDTex);
unk_80077D50 sMachineStatECompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineStatETex);

unk_80077D50* sMachineStatValueCompTexInfos[] = {
    sMachineStatACompTexInfo, sMachineStatBCompTexInfo, sMachineStatCCompTexInfo,
    sMachineStatDCompTexInfo, sMachineStatECompTexInfo,
};

unk_80077D50 sMachineWeight0CompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight0Tex);
unk_80077D50 sMachineWeight1CompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight1Tex);
unk_80077D50 sMachineWeight2CompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight2Tex);
unk_80077D50 sMachineWeight3CompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight3Tex);
unk_80077D50 sMachineWeight4CompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight4Tex);
unk_80077D50 sMachineWeight5CompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight5Tex);
unk_80077D50 sMachineWeight6CompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight6Tex);
unk_80077D50 sMachineWeight7CompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight7Tex);
unk_80077D50 sMachineWeight8CompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight8Tex);
unk_80077D50 sMachineWeight9CompTexInfo[] = COMP_TEX_INFO_DEF(17, aMachineWeight9Tex);

unk_80077D50* sMachineWeightDigitCompTexInfos[] = {
    sMachineWeight0CompTexInfo, sMachineWeight1CompTexInfo, sMachineWeight2CompTexInfo, sMachineWeight3CompTexInfo,
    sMachineWeight4CompTexInfo, sMachineWeight5CompTexInfo, sMachineWeight6CompTexInfo, sMachineWeight7CompTexInfo,
    sMachineWeight8CompTexInfo, sMachineWeight9CompTexInfo,
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
    unk_80077D50** fontCharTexInfos;
    s32 fontChar;

    switch (fontSet) {
        case FONT_SET_2:
            fontCharTexInfos = sFont2CompTexInfos;
            break;
        case FONT_SET_3:
            fontCharTexInfos = sFont3CompTexInfos;
            break;
        case FONT_SET_4:
            fontCharTexInfos = sFont4CompTexInfos;
            break;
        case FONT_SET_5:
            fontCharTexInfos = sFont5CompTexInfos;
            break;
        case FONT_SET_6:
            fontCharTexInfos = sFont6CompTexInfos;
            break;
        case FONT_SET_1:
        default:
            fontCharTexInfos = sFont1CompTexInfos;
            break;
    }
    while (*str != 0) {
        if (fontSet == FONT_SET_4) {
            fontChar = Font_GetCharIndex(str, FONT_SET_HAS_LOWERCASE);
        } else {
            fontChar = Font_GetCharIndex(str, FONT_SET_UPPERCASE_ONLY);
        }
        if (fontChar >= 0) {
            func_80077D50_impl(fontCharTexInfos[fontChar], 0, true);
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
    unk_80077D50** fontCharTexInfos;
    s32 fontSpaceWidth;

    switch (fontSet) {
        case FONT_SET_2:
            fontCharWidths = kFont2CharWidths;
            fontCharTexInfos = sFont2CompTexInfos;
            fontSpaceWidth = 3;
            top -= 8;
            break;
        case FONT_SET_3:
            fontCharWidths = kFont3CharWidths;
            fontCharTexInfos = sFont3CompTexInfos;
            fontSpaceWidth = 6;
            top -= 16;
            break;
        case FONT_SET_4:
            fontCharWidths = kFont4CharWidths;
            fontCharTexInfos = sFont4CompTexInfos;
            fontSpaceWidth = 3;
            top -= 8;
            break;
        case FONT_SET_5:
            fontCharWidths = kFont5CharWidths;
            fontCharTexInfos = sFont5CompTexInfos;
            fontSpaceWidth = 3;
            top -= 16;
            break;
        case FONT_SET_6:
            fontCharWidths = kFont6CharWidths;
            fontCharTexInfos = sFont6CompTexInfos;
            fontSpaceWidth = 3;
            top -= 16;
            break;
        case FONT_SET_1:
        default:
            fontCharWidths = kFont1CharWidths;
            fontCharTexInfos = sFont1CompTexInfos;
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
            func_80077D50_impl(fontCharTexInfos[fontChar], 0, true);
            if (arg6 == 1) {
                gfx = func_80078EA0_impl(gfx, fontCharTexInfos[fontChar], left + strWidth, top, 1, 0, 0, 1.0f, 1.0f,
                                         true);
            } else {
                gfx = func_80078EA0_impl(gfx, fontCharTexInfos[fontChar], left + strWidth, top, 0, 0, 0, 1.0f, 1.0f,
                                         true);
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
    unk_80077D50** fontCharTexInfos;
    s32 fontSpaceWidth;

    switch (fontSet) {
        case FONT_SET_2:
            fontCharWidths = kFont2CharWidths;
            fontCharTexInfos = sFont2CompTexInfos;
            fontSpaceWidth = 3;
            top -= 8;
            break;
        case FONT_SET_3:
            fontCharWidths = kFont3CharWidths;
            fontCharTexInfos = sFont3CompTexInfos;
            fontSpaceWidth = 6;
            top -= 16;
            break;
        case FONT_SET_4:
            fontCharWidths = kFont4CharWidths;
            fontCharTexInfos = sFont4CompTexInfos;
            fontSpaceWidth = 3;
            top -= 8;
            break;
        case FONT_SET_5:
            fontCharWidths = kFont5CharWidths;
            fontCharTexInfos = sFont5CompTexInfos;
            fontSpaceWidth = 3;
            top -= 16;
            break;
        case FONT_SET_6:
            fontCharWidths = kFont6CharWidths;
            fontCharTexInfos = sFont6CompTexInfos;
            fontSpaceWidth = 3;
            top -= 16;
            break;
        case FONT_SET_1:
        default:
            fontCharWidths = kFont1CharWidths;
            fontCharTexInfos = sFont1CompTexInfos;
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
            func_80077D50_impl(fontCharTexInfos[fontChar], 0, true);
            if (arg6 == 1) {
                gfx = func_80078EA0_impl(gfx, fontCharTexInfos[fontChar], (s32) (left + (strWidth * scaleX)), top, 4, 0,
                                         0, scaleX, scaleY, true);
            } else {
                gfx = func_80078EA0_impl(gfx, fontCharTexInfos[fontChar], (s32) (left + (strWidth * scaleX)), top, 3, 0,
                                         0, scaleX, scaleY, true);
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

    func_80077D50_impl(sMachineStatValueCompTexInfos[statValue], 0, true);
    return func_80078EA0_impl(gfx, sMachineStatValueCompTexInfos[statValue], left, top, 0, 0, 0, 1.0f, 1.0f, true);
}

Gfx* Font_DrawMachineStatValueSmall(Gfx* gfx, s32 left, s32 top, s32 statValue) {

    if ((statValue < 0) && (statValue >= 5)) {
        return gfx;
    }

    func_80077D50_impl(sMachineStatValueCompTexInfos[statValue], 0, true);
    return func_80078EA0_impl(gfx, sMachineStatValueCompTexInfos[statValue], left, top, 3, 0, 0, 0.5f, 0.5f, true);
}

Gfx* Font_DrawMachineWeight(Gfx* gfx, s32 left, s32 top, u32 weight) {
    s32 width;
    s32 digit;

    width = 0;
    do {
        digit = weight % 10;
        width -= kMachineWeightDigitWidths[digit];
        func_80077D50_impl(sMachineWeightDigitCompTexInfos[digit], 0, true);
        gfx = func_80078EA0_impl(gfx, sMachineWeightDigitCompTexInfos[digit], left + width, top - 16, 0, 0, 0, 1.0f,
                                 1.0f, true);
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
        func_80077D50_impl(sMachineWeightDigitCompTexInfos[digit], 0, true);
        gfx = func_80078EA0_impl(gfx, sMachineWeightDigitCompTexInfos[digit], left + width, top - (16.0f * scale), 3, 0,
                                 0, scale, scale, true);
        weight /= 10;
    } while (weight != 0);

    return gfx;
}
