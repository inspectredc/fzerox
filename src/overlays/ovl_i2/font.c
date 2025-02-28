#include "global.h"
#include "ovl_i2.h"
#include "assets/segment_2B9EA0.h"

unk_80077D50 sFont1ACompTexInfo[] = { { 17, aFont1ATex, 16, 16, 0xD7 }, { 0 } };
unk_80077D50 sFont1BCompTexInfo[] = { { 17, aFont1BTex, 16, 16, 0xD6 }, { 0 } };
unk_80077D50 sFont1CCompTexInfo[] = { { 17, aFont1CTex, 16, 16, 0xDB }, { 0 } };
unk_80077D50 sFont1DCompTexInfo[] = { { 17, aFont1DTex, 16, 16, 0xDD }, { 0 } };
unk_80077D50 sFont1ECompTexInfo[] = { { 17, aFont1ETex, 16, 16, 0xBC }, { 0 } };
unk_80077D50 sFont1FCompTexInfo[] = { { 17, aFont1FTex, 16, 16, 0xB5 }, { 0 } };
unk_80077D50 sFont1GCompTexInfo[] = { { 17, aFont1GTex, 16, 16, 0xF2 }, { 0 } };
unk_80077D50 sFont1HCompTexInfo[] = { { 17, aFont1HTex, 16, 16, 0xC5 }, { 0 } };
unk_80077D50 sFont1ICompTexInfo[] = { { 17, aFont1ITex, 8, 16, 0x8E }, { 0 } };
unk_80077D50 sFont1JCompTexInfo[] = { { 17, aFont1JTex, 16, 16, 0xCF }, { 0 } };
unk_80077D50 sFont1KCompTexInfo[] = { { 17, aFont1KTex, 16, 16, 0xEE }, { 0 } };
unk_80077D50 sFont1LCompTexInfo[] = { { 17, aFont1LTex, 16, 16, 0xAC }, { 0 } };
unk_80077D50 sFont1MCompTexInfo[] = { { 17, aFont1MTex, 16, 16, 0x10B }, { 0 } };
unk_80077D50 sFont1NCompTexInfo[] = { { 17, aFont1NTex, 16, 16, 0xF3 }, { 0 } };
unk_80077D50 sFont1OCompTexInfo[] = { { 17, aFont1OTex, 16, 16, 0xE8 }, { 0 } };
unk_80077D50 sFont1PCompTexInfo[] = { { 17, aFont1PTex, 16, 16, 0xC6 }, { 0 } };
unk_80077D50 sFont1QCompTexInfo[] = { { 17, aFont1QTex, 16, 16, 0x101 }, { 0 } };
unk_80077D50 sFont1RCompTexInfo[] = { { 17, aFont1RTex, 16, 16, 0xDA }, { 0 } };
unk_80077D50 sFont1SCompTexInfo[] = { { 17, aFont1STex, 16, 16, 0xDF }, { 0 } };
unk_80077D50 sFont1TCompTexInfo[] = { { 17, aFont1TTex, 16, 16, 0xB9 }, { 0 } };
unk_80077D50 sFont1UCompTexInfo[] = { { 17, aFont1UTex, 16, 16, 0xE4 }, { 0 } };
unk_80077D50 sFont1VCompTexInfo[] = { { 17, aFont1VTex, 16, 16, 0xD6 }, { 0 } };
unk_80077D50 sFont1WCompTexInfo[] = { { 17, aFont1WTex, 16, 16, 0x100 }, { 0 } };
unk_80077D50 sFont1XCompTexInfo[] = { { 17, aFont1XTex, 16, 16, 0xD8 }, { 0 } };
unk_80077D50 sFont1YCompTexInfo[] = { { 17, aFont1YTex, 16, 16, 0xD4 }, { 0 } };
unk_80077D50 sFont1ZCompTexInfo[] = { { 17, aFont1ZTex, 16, 16, 0xAB }, { 0 } };
unk_80077D50 sFont1CommaCompTexInfo[] = { { 17, aFont1CommaTex, 8, 16, 0x70 }, { 0 } };
unk_80077D50 sFont1PeriodCompTexInfo[] = { { 17, aFont1PeriodTex, 8, 16, 0x56 }, { 0 } };
unk_80077D50 sFont1PrimeCompTexInfo[] = { { 17, aFont1PrimeTex, 8, 16, 0x5C }, { 0 } };
unk_80077D50 sFont1ExclamationMarkCompTexInfo[] = { { 17, aFont1ExclamationMarkTex, 8, 16, 0x80 }, { 0 } };
unk_80077D50 sFont1Num0CompTexInfo[] = { { 17, aFont1Num0Tex, 16, 16, 0xDA }, { 0 } };
unk_80077D50 sFont1Num1CompTexInfo[] = { { 17, aFont1Num1Tex, 8, 16, 0x8E }, { 0 } };
unk_80077D50 sFont1Num2CompTexInfo[] = { { 17, aFont1Num2Tex, 16, 16, 0xDB }, { 0 } };
unk_80077D50 sFont1Num3CompTexInfo[] = { { 17, aFont1Num3Tex, 16, 16, 0xE4 }, { 0 } };
unk_80077D50 sFont1Num4CompTexInfo[] = { { 17, aFont1Num4Tex, 16, 16, 0xC3 }, { 0 } };
unk_80077D50 sFont1Num5CompTexInfo[] = { { 17, aFont1Num5Tex, 16, 16, 0xD8 }, { 0 } };
unk_80077D50 sFont1Num6CompTexInfo[] = { { 17, aFont1Num6Tex, 16, 16, 0xDB }, { 0 } };
unk_80077D50 sFont1Num7CompTexInfo[] = { { 17, aFont1Num7Tex, 16, 16, 0xB5 }, { 0 } };
unk_80077D50 sFont1Num8CompTexInfo[] = { { 17, aFont1Num8Tex, 16, 16, 0xF4 }, { 0 } };
unk_80077D50 sFont1Num9CompTexInfo[] = { { 17, aFont1Num9Tex, 16, 16, 0xEB }, { 0 } };
unk_80077D50 sFont1UnderscoreCompTexInfo[] = { { 17, aFont1UnderscoreTex, 16, 16, 0x56 }, { 0 } };
unk_80077D50 sFont1EndCompTexInfo[] = { { 17, aFont1EndTex, 16, 16, 0x97 }, { 0 } };
unk_80077D50 sFont1BoxCompTexInfo[] = { { 17, aFont1BoxTex, 16, 16, 0x6A }, { 0 } };
unk_80077D50 sFont1DashCompTexInfo[] = { { 17, aFont1DashTex, 16, 16, 0x5E }, { 0 } };
unk_80077D50 sFont1AmpersandCompTexInfo[] = { { 17, aFont1AmpersandTex, 16, 16, 0xFD }, { 0 } };

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

unk_80077D50 sFont2ACompTexInfo[] = { { 17, aFont2ATex, 8, 8, 0x3A }, { 0 } };
unk_80077D50 sFont2BCompTexInfo[] = { { 17, aFont2BTex, 8, 8, 0x40 }, { 0 } };
unk_80077D50 sFont2CCompTexInfo[] = { { 17, aFont2CTex, 8, 8, 0x3F }, { 0 } };
unk_80077D50 sFont2DCompTexInfo[] = { { 17, aFont2DTex, 8, 8, 0x3D }, { 0 } };
unk_80077D50 sFont2ECompTexInfo[] = { { 17, aFont2ETex, 8, 8, 0x37 }, { 0 } };
unk_80077D50 sFont2FCompTexInfo[] = { { 17, aFont2FTex, 8, 8, 0x35 }, { 0 } };
unk_80077D50 sFont2GCompTexInfo[] = { { 17, aFont2GTex, 8, 8, 0x41 }, { 0 } };
unk_80077D50 sFont2HCompTexInfo[] = { { 17, aFont2HTex, 8, 8, 0x3A }, { 0 } };
unk_80077D50 sFont2ICompTexInfo[] = { { 17, aFont2ITex, 4, 8, 0x2D }, { 0 } };
unk_80077D50 sFont2JCompTexInfo[] = { { 17, aFont2JTex, 8, 8, 0x39 }, { 0 } };
unk_80077D50 sFont2KCompTexInfo[] = { { 17, aFont2KTex, 8, 8, 0x3B }, { 0 } };
unk_80077D50 sFont2LCompTexInfo[] = { { 17, aFont2LTex, 8, 8, 0x35 }, { 0 } };
unk_80077D50 sFont2MCompTexInfo[] = { { 17, aFont2MTex, 8, 8, 0x3A }, { 0 } };
unk_80077D50 sFont2NCompTexInfo[] = { { 17, aFont2NTex, 8, 8, 0x3F }, { 0 } };
unk_80077D50 sFont2OCompTexInfo[] = { { 17, aFont2OTex, 8, 8, 0x3D }, { 0 } };
unk_80077D50 sFont2PCompTexInfo[] = { { 17, aFont2PTex, 8, 8, 0x3A }, { 0 } };
unk_80077D50 sFont2QCompTexInfo[] = { { 17, aFont2QTex, 8, 8, 0x41 }, { 0 } };
unk_80077D50 sFont2RCompTexInfo[] = { { 17, aFont2RTex, 8, 8, 0x3C }, { 0 } };
unk_80077D50 sFont2SCompTexInfo[] = { { 17, aFont2STex, 8, 8, 0x40 }, { 0 } };
unk_80077D50 sFont2TCompTexInfo[] = { { 17, aFont2TTex, 8, 8, 0x35 }, { 0 } };
unk_80077D50 sFont2UCompTexInfo[] = { { 17, aFont2UTex, 8, 8, 0x3D }, { 0 } };
unk_80077D50 sFont2VCompTexInfo[] = { { 17, aFont2VTex, 8, 8, 0x3D }, { 0 } };
unk_80077D50 sFont2WCompTexInfo[] = { { 17, aFont2WTex, 8, 8, 0x40 }, { 0 } };
unk_80077D50 sFont2XCompTexInfo[] = { { 17, aFont2XTex, 8, 8, 0x49 }, { 0 } };
unk_80077D50 sFont2YCompTexInfo[] = { { 17, aFont2YTex, 8, 8, 0x37 }, { 0 } };
unk_80077D50 sFont2ZCompTexInfo[] = { { 17, aFont2ZTex, 8, 8, 0x35 }, { 0 } };
unk_80077D50 sFont2CommaCompTexInfo[] = { { 17, aFont2CommaTex, 8, 8, 0x2E }, { 0 } };
unk_80077D50 sFont2PeriodCompTexInfo[] = { { 17, aFont2PeriodTex, 8, 8, 0x2D }, { 0 } };
unk_80077D50 sFont2PrimeCompTexInfo[] = { { 17, aFont2PrimeTex, 8, 8, 0x31 }, { 0 } };
unk_80077D50 sFont2DashCompTexInfo[] = { { 17, aFont2DashTex, 8, 8, 0x26 }, { 0 } };
unk_80077D50 sFont2KgCompTexInfo[] = { { 17, aFont2KgTex, 8, 8, 0x4D }, { 0 } };
unk_80077D50 sFont2AmpersandCompTexInfo[] = { { 17, aFont2AmpersandTex, 8, 8, 0x3F }, { 0 } };
unk_80077D50 sFont2Num0CompTexInfo[] = { { 17, aFont2Num0Tex, 8, 8, 0x37 }, { 0 } };
unk_80077D50 sFont2Num1CompTexInfo[] = { { 17, aFont2Num1Tex, 8, 8, 0x37 }, { 0 } };
unk_80077D50 sFont2Num2CompTexInfo[] = { { 17, aFont2Num2Tex, 8, 8, 0x3B }, { 0 } };
unk_80077D50 sFont2Num3CompTexInfo[] = { { 17, aFont2Num3Tex, 8, 8, 0x39 }, { 0 } };
unk_80077D50 sFont2Num4CompTexInfo[] = { { 17, aFont2Num4Tex, 8, 8, 0x3D }, { 0 } };
unk_80077D50 sFont2Num5CompTexInfo[] = { { 17, aFont2Num5Tex, 8, 8, 0x39 }, { 0 } };
unk_80077D50 sFont2Num6CompTexInfo[] = { { 17, aFont2Num6Tex, 8, 8, 0x3C }, { 0 } };
unk_80077D50 sFont2Num7CompTexInfo[] = { { 17, aFont2Num7Tex, 8, 8, 0x31 }, { 0 } };
unk_80077D50 sFont2Num8CompTexInfo[] = { { 17, aFont2Num8Tex, 8, 8, 0x38 }, { 0 } };
unk_80077D50 sFont2Num9CompTexInfo[] = { { 17, aFont2Num9Tex, 8, 8, 0x3B }, { 0 } };

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

unk_80077D50 sFont3ACompTexInfo[] = { { 4, aFont3ATex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3BCompTexInfo[] = { { 4, aFont3BTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3CCompTexInfo[] = { { 4, aFont3CTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3DCompTexInfo[] = { { 4, aFont3DTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3ECompTexInfo[] = { { 4, aFont3ETex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3FCompTexInfo[] = { { 4, aFont3FTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3GCompTexInfo[] = { { 4, aFont3GTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3HCompTexInfo[] = { { 4, aFont3HTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3ICompTexInfo[] = { { 4, aFont3ITex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3JCompTexInfo[] = { { 4, aFont3JTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3KCompTexInfo[] = { { 4, aFont3KTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3LCompTexInfo[] = { { 4, aFont3LTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3MCompTexInfo[] = { { 4, aFont3MTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3NCompTexInfo[] = { { 4, aFont3NTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3OCompTexInfo[] = { { 4, aFont3OTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3PCompTexInfo[] = { { 4, aFont3PTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3QCompTexInfo[] = { { 4, aFont3QTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3RCompTexInfo[] = { { 4, aFont3RTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3SCompTexInfo[] = { { 4, aFont3STex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3TCompTexInfo[] = { { 4, aFont3TTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3UCompTexInfo[] = { { 4, aFont3UTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3VCompTexInfo[] = { { 4, aFont3VTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3WCompTexInfo[] = { { 4, aFont3WTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3XCompTexInfo[] = { { 4, aFont3XTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3YCompTexInfo[] = { { 4, aFont3YTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3ZCompTexInfo[] = { { 4, aFont3ZTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3AlphaCompTexInfo[] = { { 4, aFont3AlphaTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3BetaCompTexInfo[] = { { 4, aFont3BetaTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3GammaCompTexInfo[] = { { 4, aFont3GammaTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3PrimeCompTexInfo[] = { { 4, aFont3PrimeTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3EllipsisCompTexInfo[] = { { 4, aFont3EllipsisTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3ColonCompTexInfo[] = { { 4, aFont3ColonTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3PeriodCompTexInfo[] = { { 4, aFont3PeriodTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3AmpersandCompTexInfo[] = { { 4, aFont3AmpersandTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3CommaCompTexInfo[] = { { 4, aFont3CommaTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3DashCompTexInfo[] = { { 4, aFont3DashTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3Num0CompTexInfo[] = { { 4, aFont3Num0Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3Num1CompTexInfo[] = { { 4, aFont3Num1Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3Num2CompTexInfo[] = { { 4, aFont3Num2Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3Num3CompTexInfo[] = { { 4, aFont3Num3Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3Num4CompTexInfo[] = { { 4, aFont3Num4Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3Num5CompTexInfo[] = { { 4, aFont3Num5Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3Num6CompTexInfo[] = { { 4, aFont3Num6Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3Num7CompTexInfo[] = { { 4, aFont3Num7Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3Num8CompTexInfo[] = { { 4, aFont3Num8Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont3Num9CompTexInfo[] = { { 4, aFont3Num9Tex, 16, 16, 0 }, { 0 } };

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
unk_80077D50 sFont4ACompTexInfo[] = { { 4, aFont4ATex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4DCompTexInfo[] = { { 4, aFont4DTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4ECompTexInfo[] = { { 4, aFont4ETex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4MCompTexInfo[] = { { 4, aFont4MTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4AmpersandCompTexInfo[] = { { 4, aFont4AmpersandTex, 8, 8, 0 }, { 0 } };
#ifndef VERSION_JP
unk_80077D50 sFont4BCompTexInfo[] = { { 4, aFont4BTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4CCompTexInfo[] = { { 4, aFont4CTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4FCompTexInfo[] = { { 4, aFont4FTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4GCompTexInfo[] = { { 4, aFont4GTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4HCompTexInfo[] = { { 4, aFont4HTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4ICompTexInfo[] = { { 4, aFont4ITex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4JCompTexInfo[] = { { 4, aFont4JTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KCompTexInfo[] = { { 4, aFont4KTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4LCompTexInfo[] = { { 4, aFont4LTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4NCompTexInfo[] = { { 4, aFont4NTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4OCompTexInfo[] = { { 4, aFont4OTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4PCompTexInfo[] = { { 4, aFont4PTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4QCompTexInfo[] = { { 4, aFont4QTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4RCompTexInfo[] = { { 4, aFont4RTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4SCompTexInfo[] = { { 4, aFont4STex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4TCompTexInfo[] = { { 4, aFont4TTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4UCompTexInfo[] = { { 4, aFont4UTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4VCompTexInfo[] = { { 4, aFont4VTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4WCompTexInfo[] = { { 4, aFont4WTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4XCompTexInfo[] = { { 4, aFont4XTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4YCompTexInfo[] = { { 4, aFont4YTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4ZCompTexInfo[] = { { 4, aFont4ZTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4LowerCCompTexInfo[] = { { 4, aFont4LowerCTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4LowerRCompTexInfo[] = { { 4, aFont4LowerRTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4LowerSCompTexInfo[] = { { 4, aFont4LowerSTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4PeriodCompTexInfo[] = { { 4, aFont4PeriodTex, 8, 8, 0 }, { 0 } };
#endif
unk_80077D50 sFont4KatakanaACompTexInfo[] = { { 4, aFont4KatakanaATex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaICompTexInfo[] = { { 4, aFont4KatakanaITex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaUCompTexInfo[] = { { 4, aFont4KatakanaUTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaECompTexInfo[] = { { 4, aFont4KatakanaETex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaOCompTexInfo[] = { { 4, aFont4KatakanaOTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaKaCompTexInfo[] = { { 4, aFont4KatakanaKaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaKiCompTexInfo[] = { { 4, aFont4KatakanaKiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaKuCompTexInfo[] = { { 4, aFont4KatakanaKuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaKeCompTexInfo[] = { { 4, aFont4KatakanaKeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaKoCompTexInfo[] = { { 4, aFont4KatakanaKoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaSaCompTexInfo[] = { { 4, aFont4KatakanaSaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaShiCompTexInfo[] = { { 4, aFont4KatakanaShiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaSuCompTexInfo[] = { { 4, aFont4KatakanaSuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaSeCompTexInfo[] = { { 4, aFont4KatakanaSeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaSoCompTexInfo[] = { { 4, aFont4KatakanaSoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaTaCompTexInfo[] = { { 4, aFont4KatakanaTaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaChiCompTexInfo[] = { { 4, aFont4KatakanaChiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaTsuCompTexInfo[] = { { 4, aFont4KatakanaTsuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaTeCompTexInfo[] = { { 4, aFont4KatakanaTeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaToCompTexInfo[] = { { 4, aFont4KatakanaToTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaSoukonCompTexInfo[] = { { 4, aFont4KatakanaSoukonTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaNaCompTexInfo[] = { { 4, aFont4KatakanaNaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaNiCompTexInfo[] = { { 4, aFont4KatakanaNiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaNuCompTexInfo[] = { { 4, aFont4KatakanaNuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaNeCompTexInfo[] = { { 4, aFont4KatakanaNeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaNoCompTexInfo[] = { { 4, aFont4KatakanaNoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaHaCompTexInfo[] = { { 4, aFont4KatakanaHaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaHiCompTexInfo[] = { { 4, aFont4KatakanaHiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaFuCompTexInfo[] = { { 4, aFont4KatakanaFuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaHeCompTexInfo[] = { { 4, aFont4KatakanaHeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaHoCompTexInfo[] = { { 4, aFont4KatakanaHoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaMaCompTexInfo[] = { { 4, aFont4KatakanaMaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaMiCompTexInfo[] = { { 4, aFont4KatakanaMiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaMuCompTexInfo[] = { { 4, aFont4KatakanaMuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaMeCompTexInfo[] = { { 4, aFont4KatakanaMeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaMoCompTexInfo[] = { { 4, aFont4KatakanaMoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaYaCompTexInfo[] = { { 4, aFont4KatakanaYaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaYuCompTexInfo[] = { { 4, aFont4KatakanaYuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaYoCompTexInfo[] = { { 4, aFont4KatakanaYoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaYoonYaCompTexInfo[] = { { 4, aFont4KatakanaYoonYaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaYoonYuCompTexInfo[] = { { 4, aFont4KatakanaYoonYuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaYoonYoCompTexInfo[] = { { 4, aFont4KatakanaYoonYoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaRaCompTexInfo[] = { { 4, aFont4KatakanaRaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaRiCompTexInfo[] = { { 4, aFont4KatakanaRiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaRuCompTexInfo[] = { { 4, aFont4KatakanaRuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaReCompTexInfo[] = { { 4, aFont4KatakanaReTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaRoCompTexInfo[] = { { 4, aFont4KatakanaRoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaWaCompTexInfo[] = { { 4, aFont4KatakanaWaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaWoCompTexInfo[] = { { 4, aFont4KatakanaWoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaNCompTexInfo[] = { { 4, aFont4KatakanaNTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaGaCompTexInfo[] = { { 4, aFont4KatakanaGaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaGiCompTexInfo[] = { { 4, aFont4KatakanaGiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaGuCompTexInfo[] = { { 4, aFont4KatakanaGuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaGeCompTexInfo[] = { { 4, aFont4KatakanaGeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaGoCompTexInfo[] = { { 4, aFont4KatakanaGoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaZaCompTexInfo[] = { { 4, aFont4KatakanaZaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaJiCompTexInfo[] = { { 4, aFont4KatakanaJiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaZuCompTexInfo[] = { { 4, aFont4KatakanaZuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaZeCompTexInfo[] = { { 4, aFont4KatakanaZeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaZoCompTexInfo[] = { { 4, aFont4KatakanaZoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaDaCompTexInfo[] = { { 4, aFont4KatakanaDaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaDjiCompTexInfo[] = { { 4, aFont4KatakanaDjiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaDzuCompTexInfo[] = { { 4, aFont4KatakanaDzuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaDeCompTexInfo[] = { { 4, aFont4KatakanaDeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaDoCompTexInfo[] = { { 4, aFont4KatakanaDoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaBaCompTexInfo[] = { { 4, aFont4KatakanaBaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaBiCompTexInfo[] = { { 4, aFont4KatakanaBiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaBuCompTexInfo[] = { { 4, aFont4KatakanaBuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaBeCompTexInfo[] = { { 4, aFont4KatakanaBeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaBoCompTexInfo[] = { { 4, aFont4KatakanaBoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaPaCompTexInfo[] = { { 4, aFont4KatakanaPaTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaPiCompTexInfo[] = { { 4, aFont4KatakanaPiTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaPuCompTexInfo[] = { { 4, aFont4KatakanaPuTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaPeCompTexInfo[] = { { 4, aFont4KatakanaPeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaPoCompTexInfo[] = { { 4, aFont4KatakanaPoTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaDigraphACompTexInfo[] = { { 4, aFont4KatakanaDigraphATex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaDigraphICompTexInfo[] = { { 4, aFont4KatakanaDigraphITex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4KatakanaDigraphECompTexInfo[] = { { 4, aFont4KatakanaDigraphETex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4DashCompTexInfo[] = { { 4, aFont4DashTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4Num0CompTexInfo[] = { { 4, aFont4Num0Tex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4Num1CompTexInfo[] = { { 4, aFont4Num1Tex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4Num2CompTexInfo[] = { { 4, aFont4Num2Tex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4Num3CompTexInfo[] = { { 4, aFont4Num3Tex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4Num4CompTexInfo[] = { { 4, aFont4Num4Tex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4Num5CompTexInfo[] = { { 4, aFont4Num5Tex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4Num6CompTexInfo[] = { { 4, aFont4Num6Tex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4Num7CompTexInfo[] = { { 4, aFont4Num7Tex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4Num8CompTexInfo[] = { { 4, aFont4Num8Tex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4Num9CompTexInfo[] = { { 4, aFont4Num9Tex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4PrimeCompTexInfo[] = { { 4, aFont4PrimeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4DoublePrimeCompTexInfo[] = { { 4, aFont4DoublePrimeTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4STCompTexInfo[] = { { 4, aFont4STTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4NDCompTexInfo[] = { { 4, aFont4NDTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4RDCompTexInfo[] = { { 4, aFont4RDTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4THCompTexInfo[] = { { 4, aFont4THTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4PlusCompTexInfo[] = { { 4, aFont4PlusTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4MinusCompTexInfo[] = { { 4, aFont4MinusTex, 8, 8, 0 }, { 0 } };
unk_80077D50 sFont4PointsCompTexInfo[] = { { 4, aFont4PointsTex, 16, 8, 0 }, { 0 } };

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

unk_80077D50 sFont5Num0CompTexInfo[] = { { 4, aFont5Num0Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5Num1CompTexInfo[] = { { 4, aFont5Num1Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5Num2CompTexInfo[] = { { 4, aFont5Num2Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5Num3CompTexInfo[] = { { 4, aFont5Num3Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5Num4CompTexInfo[] = { { 4, aFont5Num4Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5Num5CompTexInfo[] = { { 4, aFont5Num5Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5Num6CompTexInfo[] = { { 4, aFont5Num6Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5Num7CompTexInfo[] = { { 4, aFont5Num7Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5Num8CompTexInfo[] = { { 4, aFont5Num8Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5Num9CompTexInfo[] = { { 4, aFont5Num9Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5VCompTexInfo[] = { { 4, aFont5VTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5OpenParenthesisCompTexInfo[] = { { 4, aFont5OpenParenthesisTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5CloseParenthesisCompTexInfo[] = { { 4, aFont5CloseParenthesisTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5STCompTexInfo[] = { { 4, aFont5STTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5NDCompTexInfo[] = { { 4, aFont5NDTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5RDCompTexInfo[] = { { 4, aFont5RDTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5THCompTexInfo[] = { { 4, aFont5THTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5PlusCompTexInfo[] = { { 4, aFont5PlusTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5UpArrowCompTexInfo[] = { { 4, aFont5UpArrowTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5DownArrowCompTexInfo[] = { { 4, aFont5DownArrowTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5SideArrowCompTexInfo[] = { { 4, aFont5SideArrowTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont5PointsCompTexInfo[] = { { 20, aFont5PointsTex, 32, 16, 0x7B }, { 0 } };
unk_80077D50 sFont5PlayerCompTexInfo[] = { { 20, aFont5PlayerTex, 80, 16, 0x16C }, { 0 } };
unk_80077D50 sFont5ComputerCompTexInfo[] = { { 20, aFont5ComputerTex, 80, 16, 0x1C8 }, { 0 } };
unk_80077D50 sFont5SelectCourseCompTexInfo[] = { { 20, aFont5SelectCourseTex, 96, 16, 0x1D2 }, { 0 } };
unk_80077D50 sFont5QuitCompTexInfo[] = { { 20, aFont5QuitTex, 32, 16, 0xC0 }, { 0 } };

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

unk_80077D50 sFont6ACompTexInfo[] = { { 4, aFont6ATex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6BCompTexInfo[] = { { 4, aFont6BTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6CCompTexInfo[] = { { 4, aFont6CTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6DCompTexInfo[] = { { 4, aFont6DTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6ECompTexInfo[] = { { 4, aFont6ETex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6FCompTexInfo[] = { { 4, aFont6FTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6GCompTexInfo[] = { { 4, aFont6GTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6HCompTexInfo[] = { { 4, aFont6HTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6ICompTexInfo[] = { { 4, aFont6ITex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6JCompTexInfo[] = { { 4, aFont6JTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6KCompTexInfo[] = { { 4, aFont6KTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6LCompTexInfo[] = { { 4, aFont6LTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6MCompTexInfo[] = { { 4, aFont6MTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6NCompTexInfo[] = { { 4, aFont6NTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6OCompTexInfo[] = { { 4, aFont6OTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6PCompTexInfo[] = { { 4, aFont6PTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6QCompTexInfo[] = { { 4, aFont6QTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6RCompTexInfo[] = { { 4, aFont6RTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6SCompTexInfo[] = { { 4, aFont6STex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6TCompTexInfo[] = { { 4, aFont6TTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6UCompTexInfo[] = { { 4, aFont6UTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6VCompTexInfo[] = { { 4, aFont6VTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6WCompTexInfo[] = { { 4, aFont6WTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6XCompTexInfo[] = { { 4, aFont6XTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6YCompTexInfo[] = { { 4, aFont6YTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6ZCompTexInfo[] = { { 4, aFont6ZTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6Num0CompTexInfo[] = { { 4, aFont6Num0Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6Num1CompTexInfo[] = { { 4, aFont6Num1Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6Num2CompTexInfo[] = { { 4, aFont6Num2Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6Num3CompTexInfo[] = { { 4, aFont6Num3Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6Num4CompTexInfo[] = { { 4, aFont6Num4Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6Num5CompTexInfo[] = { { 4, aFont6Num5Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6Num6CompTexInfo[] = { { 4, aFont6Num6Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6Num7CompTexInfo[] = { { 4, aFont6Num7Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6Num8CompTexInfo[] = { { 4, aFont6Num8Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6Num9CompTexInfo[] = { { 4, aFont6Num9Tex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6AlphaCompTexInfo[] = { { 4, aFont6AlphaTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6BetaCompTexInfo[] = { { 4, aFont6BetaTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6HiraganaNiCompTexInfo[] = { { 4, aFont6HiraganaNiTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6AmpersandCompTexInfo[] = { { 4, aFont6AmpersandTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6CommaCompTexInfo[] = { { 4, aFont6CommaTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6DoublePrimeCompTexInfo[] = { { 4, aFont6DoublePrimeTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6DashCompTexInfo[] = { { 4, aFont6DashTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6PeriodCompTexInfo[] = { { 4, aFont6PeriodTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6PrimeCompTexInfo[] = { { 4, aFont6PrimeTex, 16, 16, 0 }, { 0 } };
unk_80077D50 sFont6UnderscoreCompTexInfo[] = { { 4, aFont6UnderscoreTex, 16, 16, 0 }, { 0 } };

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

unk_80077D50 sMachineStatACompTexInfo[] = { { 17, aMachineStatATex, 16, 16, 0xB3 }, { 0 } };
unk_80077D50 sMachineStatBCompTexInfo[] = { { 17, aMachineStatBTex, 16, 16, 0xBF }, { 0 } };
unk_80077D50 sMachineStatCCompTexInfo[] = { { 17, aMachineStatCTex, 16, 16, 0xB5 }, { 0 } };
unk_80077D50 sMachineStatDCompTexInfo[] = { { 17, aMachineStatDTex, 16, 16, 0xC9 }, { 0 } };
unk_80077D50 sMachineStatECompTexInfo[] = { { 17, aMachineStatETex, 16, 16, 0x97 }, { 0 } };

unk_80077D50* sMachineStatValueCompTexInfos[] = {
    sMachineStatACompTexInfo, sMachineStatBCompTexInfo, sMachineStatCCompTexInfo,
    sMachineStatDCompTexInfo, sMachineStatECompTexInfo,
};

unk_80077D50 sMachineWeight0CompTexInfo[] = { { 17, aMachineWeight0Tex, 8, 16, 0xCE }, { 0 } };
unk_80077D50 sMachineWeight1CompTexInfo[] = { { 17, aMachineWeight1Tex, 4, 16, 0x5B }, { 0 } };
unk_80077D50 sMachineWeight2CompTexInfo[] = { { 17, aMachineWeight2Tex, 8, 16, 0x82 }, { 0 } };
unk_80077D50 sMachineWeight3CompTexInfo[] = { { 17, aMachineWeight3Tex, 8, 16, 0x7E }, { 0 } };
unk_80077D50 sMachineWeight4CompTexInfo[] = { { 17, aMachineWeight4Tex, 8, 16, 0x8F }, { 0 } };
unk_80077D50 sMachineWeight5CompTexInfo[] = { { 17, aMachineWeight5Tex, 8, 16, 0x7F }, { 0 } };
unk_80077D50 sMachineWeight6CompTexInfo[] = { { 17, aMachineWeight6Tex, 8, 16, 0x96 }, { 0 } };
unk_80077D50 sMachineWeight7CompTexInfo[] = { { 17, aMachineWeight7Tex, 8, 16, 0x6D }, { 0 } };
unk_80077D50 sMachineWeight8CompTexInfo[] = { { 17, aMachineWeight8Tex, 8, 16, 0xAA }, { 0 } };
unk_80077D50 sMachineWeight9CompTexInfo[] = { { 17, aMachineWeight9Tex, 8, 16, 0x96 }, { 0 } };

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

const s16 kFont4CharWidths[] = {
    7, 7, 6, 7, 6, 5, 6, 7, 4, 4, 6, 5, 7, 6, 7, 6, 7, 7, 6, 6, 7, 6, 7, 7, 7, 5, 8, 8, 8, 8, 8, 16, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 6,  6, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
};

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
            func_80077D50(fontCharTexInfos[fontChar], 0);
            if (arg6 == 1) {
                gfx = func_80078EA0(gfx, fontCharTexInfos[fontChar], left + strWidth, top, 1, 0, 0, 1.0f, 1.0f);
            } else {
                gfx = func_80078EA0(gfx, fontCharTexInfos[fontChar], left + strWidth, top, 0, 0, 0, 1.0f, 1.0f);
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
            func_80077D50(fontCharTexInfos[fontChar], 0);
            if (arg6 == 1) {
                gfx = func_80078EA0(gfx, fontCharTexInfos[fontChar], (s32) (left + (strWidth * scaleX)), top, 4, 0, 0,
                                    scaleX, scaleY);
            } else {
                gfx = func_80078EA0(gfx, fontCharTexInfos[fontChar], (s32) (left + (strWidth * scaleX)), top, 3, 0, 0,
                                    scaleX, scaleY);
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

    func_80077D50(sMachineStatValueCompTexInfos[statValue], 0);
    return func_80078EA0(gfx, sMachineStatValueCompTexInfos[statValue], left, top, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* Font_DrawMachineStatValueSmall(Gfx* gfx, s32 left, s32 top, s32 statValue) {

    if ((statValue < 0) && (statValue >= 5)) {
        return gfx;
    }

    func_80077D50(sMachineStatValueCompTexInfos[statValue], 0);
    return func_80078EA0(gfx, sMachineStatValueCompTexInfos[statValue], left, top, 3, 0, 0, 0.5f, 0.5f);
}

Gfx* Font_DrawMachineWeight(Gfx* gfx, s32 left, s32 top, u32 weight) {
    s32 width;
    s32 digit;

    width = 0;
    do {
        digit = weight % 10;
        width -= kMachineWeightDigitWidths[digit];
        func_80077D50(sMachineWeightDigitCompTexInfos[digit], 0);
        gfx = func_80078EA0(gfx, sMachineWeightDigitCompTexInfos[digit], left + width, top - 16, 0, 0, 0, 1.0f, 1.0f);
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
        func_80077D50(sMachineWeightDigitCompTexInfos[digit], 0);
        gfx = func_80078EA0(gfx, sMachineWeightDigitCompTexInfos[digit], left + width, top - (16.0f * scale), 3, 0, 0,
                            scale, scale);
        weight /= 10;
    } while (weight != 0);

    return gfx;
}
