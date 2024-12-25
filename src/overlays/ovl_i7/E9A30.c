#include "global.h"
#include "fzx_game.h"
#include "fzx_hud.h"
#include "fzx_racer.h"
#include "assets/segment_17B960.h"
#include "assets/segment_1B8550.h"
#include "assets/segment_2738A0.h"
#include "assets/segment_2B9EA0.h"

extern s16 D_800CCFE8;
extern s32 gCupType;
extern s8 D_800CD3C0;
extern s8 D_800DCE5C;
extern s16 D_800E42CC;
extern s32 gTrackIndex;
extern RaceStats gCupRaceStats[1][6];
extern unk_8010B7B0 D_8010B7B0[];
extern s32 D_i2_80106F10;
extern s16 D_80106F48;

extern s32 gNumPlayers;
extern s32 gDifficulty;

extern char* gTrackNames[55];

extern Gfx D_8014940[];

extern FrameBuffer* D_800DCCD0[];
extern GfxPool* D_800DCCF0;
extern s32 D_800DCD04;
extern unk_struct_1DC D_800E5220[];
extern Vtx* D_800E5ECC;
extern Vtx* D_800E5ED0;
extern Vtx* D_800F8520;

extern GfxPool D_1000000;

#include "prevent_bss_reordering.h"
#include "ovl_i7.h"

extern unk_8014B480 D_8014B480[2];
extern unk_8014B480* D_i7_8014BDF0;
extern s16 sTotalRacersKOd;
extern u16 D_i7_8014BDF6;
extern void* sEndingTex;
extern void* sEndingTextTex;
extern s16 sEndScreenState;
extern s16 sEndScreenFade;
extern s16 sEndScreenAlpha;
extern s32 D_i7_8014BE08; // state
extern s16 D_i7_8014BE0C; // counter
extern f32 D_i7_8014BE10; // scroll top
extern s16 D_i7_8014BE14; // congrats/ending alpha
extern s16 sCupNameIndex;
extern s16 D_i7_8014BE18;
extern s16 sCupDifficulty;
extern s16 D_i7_8014BE1C; // thanks for playing state
extern s16 sThanksForPlayingFade;
extern s16 D_i7_8014BE20;
extern unk_8014BE28 D_i7_8014BE28[10];
extern unk_8014BEC8 D_i7_8014BEC8[3];
extern u16 D_i7_8014BF28;
extern Vec3f D_i7_8014BF30[8];
extern s16 D_i7_8014BF90;
extern s16 D_i7_8014BF92;
extern unk_8014BF94* D_i7_8014BF94;
extern unk_8014BF98* D_i7_8014BF98;
extern UNUSED u8 D_i7_8014BFA0[0x80];
extern s32 D_i7_8014C020;
extern UNUSED s32 D_i7_8014C024;
extern u16* D_i7_8014C028[3];
extern u16* D_i7_8014C034;
extern u16* D_i7_8014C038;
extern u16* D_i7_8014C03C;
extern u16* D_i7_8014C040;
extern s32 D_i7_8014C044;
extern u8 D_i7_8014C048[0x200];
extern s32 D_i7_8014C248;

void* sEndingTextures[][2] = {
    { aEndingCaptainFalconMasterTex, aEndingTextCaptainFalconMasterTex },                 // CAPTAIN_FALCON
    { aEndingDrStewartTex, aEndingTextDrStewartTex },                                     // DR_STEWART
    { aEndingPicoTex, aEndingTextPicoTex },                                               // PICO
    { aEndingSamuraiGorohTex, aEndingTextSamuraiGorohTex },                               // SAMURAI_GOROH
    { aEndingJodySummerTex, aEndingTextJodySummerTex },                                   // JODY_SUMMER
    { aEndingMightyGazelleTex, aEndingTextMightyGazelleTex },                             // MIGHTY_GAZELLE
    { aEndingMrEadTex, aEndingTextMrEadTex },                                             // MR_EAD
    { aEndingBabaTex, aEndingTextBabaTex },                                               // BABA
    { aEndingOctomanTex, aEndingTextOctomanTex },                                         // OCTOMAN
    { aEndingGomarAndShiohTex, aEndingTextGomarAndShiohTex },                             // GOMAR_AND_SHIOH
    { aEndingKateAlenTex, aEndingTextKateAlenTex },                                       // KATE_ALEN
    { aEndingRogerBusterTex, aEndingTextRogerBusterTex },                                 // ROGER_BUSTER
    { aEndingJamesMcCloudTex, aEndingTextJamesMcCloudTex },                               // JAMES_MCCLOUD
    { aEndingLeonTex, aEndingTextLeonTex },                                               // LEON
    { aEndingAntonioGusterTex, aEndingTextAntonioGusterTex },                             // ANTONIO_GUSTER
    { aEndingBlackShadowTex, aEndingTextBlackShadowTex },                                 // BLACK_SHADOW
    { aEndingMichaelChainTex, aEndingTextMichaelChainTex },                               // MICHAEL_CHAIN
    { aEndingJackLevinTex, aEndingTextJackLevinTex },                                     // JACK_LEVIN
    { aEndingSuperArrowTex, aEndingTextSuperArrowTex },                                   // SUPER_ARROW
    { aEndingMrsArrowTex, aEndingTextMrsArrowTex },                                       // MRS_ARROW
    { aEndingJohnTanakaTex, aEndingTextJohnTanakaTex },                                   // JOHN_TANAKA
    { aEndingBeastmanTex, aEndingTextBeastmanTex },                                       // BEASTMAN
    { aEndingZodaTex, aEndingTextZodaTex },                                               // ZODA
    { aEndingDrClashTex, aEndingTextDrClashTex },                                         // DR_CLASH
    { aEndingSilverNeelsenTex, aEndingTextSilverNeelsenTex },                             // SILVER_NEELSEN
    { aEndingBioRexTex, aEndingTextBioRexTex },                                           // BIO_REX
    { aEndingDraqTex, aEndingTextDraqTex },                                               // DRAQ
    { aEndingBillyTex, aEndingTextBillyTex },                                             // BILLY
    { aEndingTheSkullTex, aEndingTextTheSkullTex },                                       // THE_SKULL
    { aEndingBloodFalconTex, aEndingTextBloodFalconTex },                                 // BLOOD_FALCON
    { aEndingCaptainFalconAltTex, NULL },                                                 // CAPTAIN_FALCON 2
    { aEndingCaptainFalconStandardExpertTex, aEndingTextCaptainFalconStandardExpertTex }, // CAPTAIN_FALCON 3
    { aEndingSamuraiGorohAltTex, NULL },                                                  // SAMURAI_GOROH 2
    { aEndingJodySummerAltTex, NULL },                                                    // JODY_SUMMER 2
};

void* sFinalResultPositionDigitTexs[] = {
    aFinalResultPosition0Tex, aFinalResultPosition1Tex, aFinalResultPosition2Tex, aFinalResultPosition3Tex,
    aFinalResultPosition4Tex, aFinalResultPosition5Tex, aFinalResultPosition6Tex, aFinalResultPosition7Tex,
    aFinalResultPosition8Tex, aFinalResultPosition9Tex,
};

void* sFinalResultsPositionSuffixTexs[] = { aFinalResultPositionSuffixSTTex, aFinalResultPositionSuffixNDTex,
                                            aFinalResultPositionSuffixRDTex, aFinalResultPositionSuffixTHTex };

Gfx* D_i7_80149FD8[] = { D_5000178, D_5001E38, D_5002B18 };

f32 D_i7_80149FE4 = 0.3f;
f32 D_i7_80149FE8 = 1.0f;

s16 D_i7_80149FEC[] = { 1, 3, 4, 4, 4, 4, 4, 4, 5, -1 };

char sTotalRankingStr[] = "TOTAL RANKING";

const char* sCupNames[] = { "JACK CUP", "QUEEN CUP", "KING CUP", "JOKER CUP", "EDIT CUP", "X CUP" };

char sThanksForPlayingStr[] = "THANKS FOR PLAYING!!";

f32 D_i7_8014A040[] = { 0.0f, -40.0f, -60.0f, 0.0f };

f32 D_i7_8014A050[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A060[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A070[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A080[] = { 360 };

f32 D_i7_8014A084[] = { 53.0f, -36.0f, -75.0f, -75.0f, -75.0f };

f32 D_i7_8014A098[] = { 20.0f, 61.0f, 9.0f, 9.0f, 9.0f };

f32 D_i7_8014A0AC[] = { -700.0f, 87.0f, 92.0f, 92.0f, 92.0f };

s32 D_i7_8014A0C0[] = { 180, 180 };

unk_struct_14 D_i7_8014A0C8[] = {
    { 4, D_i7_8014A050, D_i7_8014A060, D_i7_8014A070, D_i7_8014A080 },
    { 5, D_i7_8014A084, D_i7_8014A098, D_i7_8014A0AC, D_i7_8014A0C0 },
};

f32 D_i7_8014A0F0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A108[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A120[] = { 0.0f, 0.0f, 61.0f, 61.0f, 61.0f, 61.0f };

s32 D_i7_8014A138[] = { 180, 180, 180 };

f32 D_i7_8014A144[] = { 375.0f, 375.0f, 375.0f, -49.0f, -223.0f, -223.0f, -223.0f, -223.0f };

f32 D_i7_8014A164[] = { 140.0f, 140.0f, 140.0f, 57.0f, 11.0f, 11.0f, 11.0f, 11.0f };

f32 D_i7_8014A184[] = { 56.0f, 56.0f, 56.0f, -53.0f, -1.0f, -1.0f, -1.0f, -1.0f };

s32 D_i7_8014A1A4[] = { 60, 60, 60, 180, 180 };

f32 D_i7_8014A1B8[] = { 60.0f, 60.0f, 60.0f, 60.0f };

s32 D_i7_8014A1C8[] = { 540 };

unk_80085434_arg_2 D_i7_8014A1CC = {
    {
        { 6, D_i7_8014A0F0, D_i7_8014A108, D_i7_8014A120, D_i7_8014A138 },
        { 8, D_i7_8014A144, D_i7_8014A164, D_i7_8014A184, D_i7_8014A1A4 },
    },
    { 4, D_i7_8014A1B8, D_i7_8014A1C8 },
};

f32 D_i7_8014A200[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A210[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A220[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A230[] = { 120 };

f32 D_i7_8014A234[] = { -60.0f, -56.0f, -56.0f, -56.0f };

f32 D_i7_8014A244[] = { 17.0f, 14.0f, 14.0f, 14.0f };

f32 D_i7_8014A254[] = { 229.0f, -85.0f, -85.0f, -85.0f };

s32 D_i7_8014A264[] = { 120 };

f32 D_i7_8014A268[] = { 60.0f, 79.0f, 79.0f, 79.0f };

s32 D_i7_8014A278[] = { 120 };

unk_80085434_arg_2 D_i7_8014A27C = {
    {
        { 4, D_i7_8014A200, D_i7_8014A210, D_i7_8014A220, D_i7_8014A230 },
        { 4, D_i7_8014A234, D_i7_8014A244, D_i7_8014A254, D_i7_8014A264 },
    },
    { 4, D_i7_8014A268, D_i7_8014A278 },
};

f32 D_i7_8014A2B0[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A2C0[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A2D0[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A2E0[] = { 120 };

f32 D_i7_8014A2E4[] = { 149.0f, -45.0f, -45.0f, -45.0f };

f32 D_i7_8014A2F4[] = { 9.0f, 12.0f, 12.0f, 12.0f };

f32 D_i7_8014A304[] = { 42.0f, 98.0f, 98.0f, 98.0f };

s32 D_i7_8014A314[] = { 120 };

unk_struct_14 D_i7_8014A318[] = {
    { 4, D_i7_8014A2B0, D_i7_8014A2C0, D_i7_8014A2D0, D_i7_8014A2E0 },
    { 4, D_i7_8014A2E4, D_i7_8014A2F4, D_i7_8014A304, D_i7_8014A314 },
};

f32 D_i7_8014A340[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A350[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A360[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A370[] = { 300 };

f32 D_i7_8014A374[] = { 43.0f, 43.0f, 43.0f, 43.0f, 43.0f };

f32 D_i7_8014A388[] = { 8.0f, 10.0f, 10.0f, 10.0f, 10.0f };

f32 D_i7_8014A39C[] = { 110.0f, -94.0f, -94.0f, -94.0f, -94.0f };

s32 D_i7_8014A3B0[] = { 120, 180 };

f32 D_i7_8014A3B8[] = { 60.0f, 74.0f, 74.0f, 74.0f };

s32 D_i7_8014A3C8[] = { 300 };

unk_80085434_arg_2 D_i7_8014A3CC = {
    {
        { 4, D_i7_8014A340, D_i7_8014A350, D_i7_8014A360, D_i7_8014A370 },
        { 5, D_i7_8014A374, D_i7_8014A388, D_i7_8014A39C, D_i7_8014A3B0 },
    },
    { 4, D_i7_8014A3B8, D_i7_8014A3C8 },
};

f32 D_i7_8014A400[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A414[] = { 29.0f, 29.0f, 29.0f, 29.0f, 29.0f };

f32 D_i7_8014A428[] = { -220.0f, 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A43C[] = { 240, 180 };

f32 D_i7_8014A444[] = { 4.0f, 4.0f, 4.0f, -18.0f, -18.0f, -18.0f, -18.0f };

f32 D_i7_8014A460[] = { 6.0f, -18.0f, -18.0f, 7.0f, 7.0f, 7.0f, 7.0f };

f32 D_i7_8014A47C[] = { -110.0f, -34.0f, 38.0f, 108.0f, 108.0f, 108.0f, 108.0f };

s32 D_i7_8014A498[] = { 120, 60, 60, 180 };

unk_struct_14 D_i7_8014A4A8[] = {
    { 5, D_i7_8014A400, D_i7_8014A414, D_i7_8014A428, D_i7_8014A43C },
    { 7, D_i7_8014A444, D_i7_8014A460, D_i7_8014A47C, D_i7_8014A498 },
};

extern unk_8008112C_arg_1 D_800D4E98;

unk_struct_C D_i7_8014A4D0[] = {
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 360, func_80084654, D_i7_8014A0C8 },
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 540, func_80084654, &D_i7_8014A1CC },
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 120, func_80084654, &D_i7_8014A27C },
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 120, func_80084654, D_i7_8014A318 },
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 300, func_80084654, &D_i7_8014A3CC },
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 420, func_80084654, D_i7_8014A4A8 },
    { -2, NULL, 0 },
    { 0, NULL, 0 },
};

f32 D_i7_8014A5C0[] = { 0.0f, 0.0f, 0.0f, -125.0f, -125.0f, -125.0f, -125.0f, -125.0f };

f32 D_i7_8014A5E0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A600[] = { 0.0f, 0.0f, 0.0f, 141.0f, 141.0f, 141.0f, 141.0f, 141.0f };

s32 D_i7_8014A620[] = { 300, 150, 150, 150, 150 };

f32 D_i7_8014A634[] = { 98.0f, 98.0f, 98.0f, 62.0f, 62.0f, 62.0f, 62.0f, 62.0f };

f32 D_i7_8014A654[] = { 20.0f, 20.0f, 20.0f, 38.0f, 38.0f, 38.0f, 38.0f, 38.0f };

f32 D_i7_8014A674[] = { -74.0f, -74.0f, -74.0f, -63.0f, -63.0f, -63.0f, -63.0f, -63.0f };

s32 D_i7_8014A694[] = { 300, 150, 150, 150, 150 };

f32 D_i7_8014A6A8[] = { 70.0f, 70.0f, 70.0f, 70.0f };

s32 D_i7_8014A6B8[] = { 900 };

unk_80085434_arg_2 D_i7_8014A6BC = {
    {
        { 8, D_i7_8014A5C0, D_i7_8014A5E0, D_i7_8014A600, D_i7_8014A620 },
        { 8, D_i7_8014A634, D_i7_8014A654, D_i7_8014A674, D_i7_8014A694 },
    },
    { 4, D_i7_8014A6A8, D_i7_8014A6B8 },
};

f32 D_i7_8014A6F0[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A700[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A710[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A720[] = { 960 };

f32 D_i7_8014A724[] = { -1.0f, -1.0f, -1.0f, -38.0f, -38.0f, -38.0f, -38.0f, -38.0f };

f32 D_i7_8014A744[] = { 450.0f, 450.0f, 450.0f, 53.0f, 53.0f, 53.0f, 53.0f, 53.0f };

f32 D_i7_8014A764[] = { 79.0f, 79.0f, 79.0f, 79.0f, 79.0f, 79.0f, 79.0f, 79.0f };

s32 D_i7_8014A784[] = { 300, 150, 150, 150, 210 };

f32 D_i7_8014A798[] = { 70.0f, 60.0f, 60.0f, 60.0f };

s32 D_i7_8014A7A8[] = { 960 };

unk_80085434_arg_2 D_i7_8014A7AC = {
    {
        { 4, D_i7_8014A6F0, D_i7_8014A700, D_i7_8014A710, D_i7_8014A720 },
        { 8, D_i7_8014A724, D_i7_8014A744, D_i7_8014A764, D_i7_8014A784 },
    },
    { 4, D_i7_8014A798, D_i7_8014A7A8 },
};

unk_struct_C D_i7_8014A7E0[] = {
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 900, func_800847B0, &D_i7_8014A6BC },
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 960, func_800847B0, &D_i7_8014A7AC },
    { -2, NULL, 0 },
    { 0, NULL, 0 },
};

f32 D_i7_8014A840[] = { 146.0f, 146.0f, 146.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A858[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A870[] = { 194.0f, 194.0f, 194.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A888[] = { 300, 150, 150 };

f32 D_i7_8014A894[] = { -72.0f, -72.0f, -72.0f, -79.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A8B4[] = { 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f };

f32 D_i7_8014A8D4[] = { -82.0f, -82.0f, -82.0f, 27.0f, 113.0f, 113.0f, 113.0f, 113.0f };

s32 D_i7_8014A8F4[] = { 250, 125, 75, 75, 75 };

unk_struct_14 D_i7_8014A908[] = {
    { 6, D_i7_8014A840, D_i7_8014A858, D_i7_8014A870, D_i7_8014A888 },
    { 8, D_i7_8014A894, D_i7_8014A8B4, D_i7_8014A8D4, D_i7_8014A8F4 },
};

f32 D_i7_8014A930[] = { 0.0f, 0.0f, 0.0f, -29.0f, -29.0f, -29.0f };

f32 D_i7_8014A948[] = { 0.0f, 0.0f, 0.0f, 22.0f, 22.0f, 22.0f };

f32 D_i7_8014A960[] = { 0.0f, 0.0f, 0.0f, 2.0f, 2.0f, 2.0f };

s32 D_i7_8014A978[] = { 300, 150, 150 };

f32 D_i7_8014A984[] = { 0.0f, 0.0f, 86.0f, 86.0f, 86.0f, 86.0f };

f32 D_i7_8014A99C[] = { 30.0f, 45.0f, 41.0f, 41.0f, 41.0f, 41.0f };

f32 D_i7_8014A9B4[] = { 113.0f, 27.0f, 13.0f, 13.0f, 13.0f, 13.0f };

s32 D_i7_8014A9CC[] = { 300, 150, 150 };

unk_struct_14 D_i7_8014A9D8[] = {
    { 6, D_i7_8014A930, D_i7_8014A948, D_i7_8014A960, D_i7_8014A978 },
    { 6, D_i7_8014A984, D_i7_8014A99C, D_i7_8014A9B4, D_i7_8014A9CC },
};

f32 D_i7_8014AA00[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014AA10[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014AA20[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014AA30[] = { 300 };

f32 D_i7_8014AA34[] = { -10.0f, -10.0f, -10.0f, -10.0f, -10.0f, -10.0f };

f32 D_i7_8014AA4C[] = { 222.0f, 222.0f, 222.0f, 222.0f, 222.0f, 222.0f };

f32 D_i7_8014AA64[] = { -498.0f, -498.0f, -498.0f, 563.0f, 563.0f, 563.0f };

s32 D_i7_8014AA7C[] = { 100, 100, 100 };

f32 D_i7_8014AA88[] = { 90.0f, 60.0f, 60.0f, 60.0f };

s32 D_i7_8014AA98[] = { 300 };

unk_80085434_arg_2 D_i7_8014AA9C = {
    {
        { 4, D_i7_8014AA00, D_i7_8014AA10, D_i7_8014AA20, D_i7_8014AA30 },
        { 6, D_i7_8014AA34, D_i7_8014AA4C, D_i7_8014AA64, D_i7_8014AA7C },
    },
    { 4, D_i7_8014AA88, D_i7_8014AA98 },
};

f32 D_i7_8014AAD0[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014AAE0[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014AAF0[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014AB00[] = { 360 };

f32 D_i7_8014AB04[] = { -10.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014AB14[] = { 222.0f, 37.0f, 37.0f, 37.0f };

f32 D_i7_8014AB24[] = { 563.0f, 132.0f, 132.0f, 132.0f };

s32 D_i7_8014AB34[] = { 360 };

unk_struct_14 D_i7_8014AB38[] = {
    { 4, D_i7_8014AAD0, D_i7_8014AAE0, D_i7_8014AAF0, D_i7_8014AB00 },
    { 4, D_i7_8014AB04, D_i7_8014AB14, D_i7_8014AB24, D_i7_8014AB34 },
};

unk_struct_C D_i7_8014AB60[] = {
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 600, func_80084654, D_i7_8014A908 },
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 600, func_80084654, D_i7_8014A9D8 },
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 300, func_80084654, &D_i7_8014AA9C },
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 360, func_80084654, D_i7_8014AB38 },
    { -2, NULL, 0 },
};

UNUSED s32 D_i7_8014ABFC = 0;
s32 D_i7_8014AC00 = 0;
UNUSED s32 D_i7_8014AC04 = 0x800;

void* sFullPortraits[] = {
    aFullPortraitCaptainFalconTex, // CAPTAIN_FALCON
    aFullPortraitDrStewartTex,     // DR_STEWART
    aFullPortraitPicoTex,          // PICO
    aFullPortraitSamuraiGorohTex,  // SAMURAI_GOROH
    aFullPortraitJodySummerTex,    // JODY_SUMMER
    aFullPortraitMightyGazelleTex, // MIGHTY_GAZELLE
    aFullPortraitMrEadTex,         // MR_EAD
    aFullPortraitBabaTex,          // BABA
    aFullPortraitOctomanTex,       // OCTOMAN
    aFullPortraitGomarAndShiohTex, // GOMAR_AND_SHIOH
    aFullPortraitKateAlenTex,      // KATE_ALEN
    aFullPortraitRogerBusterTex,   // ROGER_BUSTER
    aFullPortraitJamesMcCloudTex,  // JAMES_MCCLOUD
    aFullPortraitLeonTex,          // LEON
    aFullPortraitAntonioGusterTex, // ANTONIO_GUSTER
    aFullPortraitBlackShadowTex,   // BLACK_SHADOW
    aFullPortraitMichaelChainTex,  // MICHAEL_CHAIN
    aFullPortraitJackLevinTex,     // JACK_LEVIN
    aFullPortraitSuperArrowTex,    // SUPER_ARROW
    aFullPortraitMrsArrowTex,      // MRS_ARROW
    aFullPortraitJohnTanakaTex,    // JOHN_TANAKA
    aFullPortraitBeastmanTex,      // BEASTMAN
    aFullPortraitZodaTex,          // ZODA
    aFullPortraitDrClashTex,       // DR_CLASH
    aFullPortraitSilverNeelsenTex, // SILVER_NEELSEN
    aFullPortraitBioRexTex,        // BIO_REX
    aFullPortraitDraqTex,          // DRAQ
    aFullPortraitBillyTex,         // BILLY
    aFullPortraitTheSkullTex,      // THE_SKULL
    aFullPortraitBloodFalconTex,   // BLOOD_FALCON
    aFullPortraitCaptainFalconAltTex,
    aFullPortraitSamuraiGorohAltTex,
    aFullPortraitJodySummerAltTex,
};

u8 D_i7_8014AC8C[] = { 1 << 7, 1 << 6, 1 << 5, 1 << 4, 1 << 3, 1 << 2, 1 << 1, 1 << 0 };

// Icon Textures (Less than 4b size), used as some kind of mask
// Fireworks?
void* D_i7_8014AC94[] = {
    D_F265E80, // CAPTAIN_FALCON
    D_F268A80, // DR_STEWART
    D_F266880, // PICO
    D_F267A80, // SAMURAI_GOROH
    D_F268680, // JODY_SUMMER
    D_F266280, // MIGHTY_GAZELLE
    D_F267C80, // MR_EAD
    D_F266080, // BABA
    D_F267880, // OCTOMAN
    D_F267080, // GOMAR_AND_SHIOH
    D_F269680, // KATE_ALEN
    D_F266480, // ROGER_BUSTER
    D_F268080, // JAMES_MCCLOUD
    D_F269280, // LEON
    D_F268C80, // ANTONIO_GUSTER
    D_F266A80, // BLACK_SHADOW
    D_F269480, // MICHAEL_CHAIN
    D_F266680, // JACK_LEVIN
    D_F267280, // SUPER_ARROW
    D_F268880, // MRS_ARROW
    D_F269080, // JOHN_TANAKA
    D_F267480, // BEASTMAN
    D_F268E80, // ZODA
    D_F266E80, // DR_CLASH
    D_F269880, // SILVER_NEELSEN
    D_F268480, // BIO_REX
    D_F266C80, // DRAQ
    D_F267680, // BILLY
    D_F268280, // THE_SKULL
    D_F267E80, // BLOOD_FALCON
};

void* D_i7_8014AD0C = D_F269A80;
void* D_i7_8014AD10 = D_F269C80;
void* D_i7_8014AD14 = D_F269E80;

void* D_i7_8014AD18[] = { D_F26A080, D_F26A280, D_F26A480, D_F26A680 };

void* D_i7_8014AD28 = D_F26A880;

u8 D_i7_8014AD2C[][3] = {
    { 255, 255, 255 }, { 255, 248, 248 }, { 255, 240, 240 }, { 255, 232, 232 }, { 255, 224, 224 }, { 255, 216, 216 },
    { 255, 208, 208 }, { 255, 200, 200 }, { 255, 192, 192 }, { 255, 184, 184 }, { 255, 176, 176 }, { 255, 168, 168 },
    { 255, 160, 160 }, { 255, 152, 152 }, { 255, 144, 144 }, { 255, 136, 136 }, { 255, 128, 128 }, { 255, 120, 120 },
    { 255, 112, 112 }, { 255, 104, 104 }, { 255, 96, 96 },   { 255, 88, 88 },   { 255, 80, 80 },   { 255, 72, 72 },
    { 255, 64, 64 },   { 255, 56, 56 },   { 255, 48, 48 },   { 255, 40, 40 },   { 255, 32, 32 },   { 255, 24, 24 },
    { 255, 16, 16 },   { 255, 8, 8 },
};

TexturePtr D_i7_8014AD8C[] = {
    D_i7_8014ADA8,
    D_i7_8014AE30,
    D_i7_8014AEB8,
    NULL,
};

UNUSED Gfx D_i7_8014ADA0[] = {
    gsSPEndDisplayList(),
};

u16 D_i7_8014ADA8[] = {
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF,
    0xFFFF, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
};

UNUSED Gfx D_i7_8014AE28[] = {
    gsSPEndDisplayList(),
};

u16 D_i7_8014AE30[] = {
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0xFFFE, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFE,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
};

UNUSED Gfx D_i7_8014AEB0[] = {
    gsSPEndDisplayList(),
};

u16 D_i7_8014AEB8[] = {
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFE, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
};

Vtx D_i7_8014AF38[] = {
    VTX(-160, 420, 0, 0, 0, 0, 0, 0, 255),
    VTX(160, 420, 0, 992, 0, 0, 0, 0, 255),
    VTX(160, 0, 0, 992, 1312, 0, 0, 0, 255),
    VTX(-160, 0, 0, 0, 1312, 0, 0, 0, 255),
};

Gfx D_i7_8014AF78[] = {
    gsSPVertex(D_i7_8014AF38, 4, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSP1Triangle(0, 3, 2, 0),
    gsSPEndDisplayList(),
};

UNUSED s32 D_i7_8014AF98 = 0;
UNUSED s32 D_i7_8014AF9C = 0;

f32 D_i7_8014AFA0[] = { 0.0f, 0.0f, 0.0f, -25.0f, -25.0f, -25.0f };

f32 D_i7_8014AFB8[] = { 0.0f, 0.0f, 0.0f, 300.0f, 300.0f, 300.0f };

f32 D_i7_8014AFD0[] = { 0.0f, 0.0f, 0.0f, -285.0f, -285.0f, -285.0f };

s32 D_i7_8014AFE8[] = { 160, 130, 190 };

f32 D_i7_8014AFF4[] = { 0.0f, 0.0f, -27.0f, -27.0f, -27.0f, -27.0f };

f32 D_i7_8014B00C[] = { 20.0f, 20.0f, 20.0f, 196.0f, 196.0f, 196.0f };

f32 D_i7_8014B024[] = { 199.0f, 199.0f, 154.0f, 154.0f, 154.0f, 154.0f };

s32 D_i7_8014B03C[] = { 160, 160, 160 };

unk_struct_14 D_i7_8014B048[] = {
    { 6, D_i7_8014AFA0, D_i7_8014AFB8, D_i7_8014AFD0, D_i7_8014AFE8 },
    { 6, D_i7_8014AFF4, D_i7_8014B00C, D_i7_8014B024, D_i7_8014B03C },
};

unk_struct_C D_i7_8014B070[] = {
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 480, func_80084654, D_i7_8014B048 },
    { -2, NULL, 0 },
};

f32 D_i7_8014B0A0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014B0B8[] = { 0.0f, 0.0f, 0.0f, 80.0f, 80.0f, 80.0f };

f32 D_i7_8014B0D0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014B0E8[] = { 125, 100, 75 };

f32 D_i7_8014B0F4[] = { 0.0f, 125.0f, 113.0f, -36.0f, -36.0f, -36.0f };

f32 D_i7_8014B10C[] = { 42.0f, 35.0f, 59.0f, 86.0f, 86.0f, 86.0f };

f32 D_i7_8014B124[] = { -139.0f, -63.0f, 74.0f, 138.0f, 138.0f, 138.0f };

s32 D_i7_8014B13C[] = { 125, 120, 75 };

f32 D_i7_8014B148[] = { 60.0f, 74.0f, 74.0f, 74.0f };

s32 D_i7_8014B158[] = { 300 };

unk_80085434_arg_2 D_i7_8014B15C = {
    {
        { 6, D_i7_8014B0A0, D_i7_8014B0B8, D_i7_8014B0D0, D_i7_8014B0E8 },
        { 6, D_i7_8014B0F4, D_i7_8014B10C, D_i7_8014B124, D_i7_8014B13C },
    },
    { 4, D_i7_8014B148, D_i7_8014B158 },
};

unk_struct_C D_i7_8014B190[] = {
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 300, func_800847B0, &D_i7_8014B15C },
    { -2, NULL, 0 },
};

f32 D_i7_8014B1C0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014B1D8[] = { 0.0f, 0.0f, 0.0f, 60.0f, 60.0f, 60.0f };

f32 D_i7_8014B1F0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014B208[] = { 170, 150, 130 };

f32 D_i7_8014B214[] = { 325.0f, 325.0f, 33.0f, 48.0f, 48.0f, 48.0f };

f32 D_i7_8014B22C[] = { 60.0f, 60.0f, 26.0f, 87.0f, 87.0f, 87.0f };

f32 D_i7_8014B244[] = { 162.0f, 162.0f, 140.0f, 140.0f, 140.0f, 140.0f };

s32 D_i7_8014B25C[] = { 170, 150, 130 };

f32 D_i7_8014B268[] = { -1.0f, -1.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014B27C[] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };

f32 D_i7_8014B290[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014B2A4[] = { 130, 170 };

f32 D_i7_8014B2AC[] = { 75.0f, 75.0f, 60.0f, 60.0f, 91.4f };

s32 D_i7_8014B2C0[] = { 130, 170 };

unk_80085494_arg_2 D_i7_8014B2C8 = {
    {
        { 6, D_i7_8014B1C0, D_i7_8014B1D8, D_i7_8014B1F0, D_i7_8014B208 },
        { 6, D_i7_8014B214, D_i7_8014B22C, D_i7_8014B244, D_i7_8014B25C },
        { 5, D_i7_8014B268, D_i7_8014B27C, D_i7_8014B290, D_i7_8014B2A4 },
    },
    { 5, D_i7_8014B2AC, D_i7_8014B2C0 },
};

unk_struct_C D_i7_8014B310[] = {
    { 0, func_80083734, &D_800D4E98 },
    { 0, func_80083580, 4 },
    { 300, func_80084860, &D_i7_8014B2C8 },
    { -2, 0, 0 },
};

s32 func_i7_GetEndScreenIndex(s32 difficulty, s16 character, s8 arg2) {
    s32 endScreenCharacterIndex;

    switch (character) {
        case CAPTAIN_FALCON:
            if (arg2 >= 2) {
                endScreenCharacterIndex = 30;
            } else {
                switch (difficulty) {
                    case STANDARD:
                    case EXPERT:
                        endScreenCharacterIndex = 31;
                        break;
                    case MASTER:
                        endScreenCharacterIndex = character;
                        break;
                }
            }
            break;
        case SAMURAI_GOROH:
            if (arg2 >= 2) {
                endScreenCharacterIndex = 32;
            } else {
                endScreenCharacterIndex = character;
            }
            break;
        case JODY_SUMMER:
            if (arg2 >= 2) {
                endScreenCharacterIndex = 33;
            } else {
                endScreenCharacterIndex = character;
            }
            break;
        default:
            endScreenCharacterIndex = character;
            break;
    }
    return endScreenCharacterIndex;
}

void func_i7_80147CC0(void);
void func_i7_801467FC(void);

void func_i7_80143A90(void) {
    unk_8014BE28* var_v1;
    s32 cupFirstTrackIndex;
    s32 pad;
    Racer* player = &gRacers[0];
    s32 i;
    s32 j;
    void** endingTextures;
    s32 var_a0;

    D_800CCFE8 = D_i2_80106F10 = 3;
    D_800DCE5C = 0;
    gNumPlayers = 1;
    cupFirstTrackIndex = (gTrackIndex / 6) * 6;
    gTrackIndex = 55;
    sCupDifficulty = gDifficulty;
    gDifficulty = MASTER;
    sTotalRacersKOd = 0;

    for (j = 0; j < 6; j++) {
        sTotalRacersKOd += gCupRaceStats[0][j].racersKOd;
    }

    func_800A4EAC();
    func_i3_80116C4C();
    func_8008C7C8();
    func_80085610();
    func_8007F4E0(D_8010B7B0[0].unk_002, D_8010B7B0[0].unk_003);
    func_i3_801365E0();
    func_i2_801044F0();
    func_8006D448();
    func_8006E478();
    func_8006EC7C();
    func_80071260(0);
    func_i7_80147CC0();
    func_i7_801467FC();
    sEndScreenState = END_SCREEN_INACTIVE;
    sEndScreenFade = 0;
    sEndScreenAlpha = 0;
    D_i7_8014BDF6 = 0;
    if (D_80106F48 < 4) {
        D_i7_8014BDF6 |= 0xF;
    } else {
        D_i7_8014BDF6 |= 0x40;
    }
    if (D_800E42CC != 0) {
        D_800E42CC = 0;
        D_i7_8014BDF6 |= 0x10;
    } else if (D_800CD3C0 >= 2) {
        switch (sCupDifficulty) {
            case EXPERT:
            case MASTER:
                if (gCupType == JOKER_CUP && D_80106F48 == 1) {
                    D_i7_8014BDF6 |= 0x10;
                }
                break;
        }
    }

    if (D_80106F48 == 1) {
        switch (sCupDifficulty) {
            case STANDARD:
            case EXPERT:
            case MASTER:
                D_i7_8014BDF6 |= 0x20;
                break;
        }
    }

    D_i7_8014BE10 = 0.0f;
    D_i7_8014BE14 = 0;
    D_i7_8014BE08 = 0;
    D_i7_8014BE0C = 0;

    switch (gCupType) {
        case JACK_CUP:
            sCupNameIndex = 0;
            break;
        case QUEEN_CUP:
            sCupNameIndex = 1;
            break;
        case KING_CUP:
            sCupNameIndex = 2;
            break;
        case JOKER_CUP:
            sCupNameIndex = 3;
            break;
        case X_CUP:
            sCupNameIndex = 5;
            break;
        case EDIT_CUP:
            sCupNameIndex = 4;
            break;
    }
    D_i7_8014BE18 = func_i2_801062E4(sCupNames[sCupNameIndex], 3, 1);
    D_i7_8014BE1C = 0;
    sThanksForPlayingFade = 0;
    D_i7_8014BF28 = 0;
    var_a0 = 0;

    var_v1 = D_i7_8014BE28;
    for (i = 0; D_i7_80149FEC[i] != -1; i++) {
        var_v1->unk_04 = 0;
        var_v1->unk_00 = D_i7_80149FEC[i];
        switch (var_v1->unk_00) {
            case 1:
                var_v1->track = 0;
                var_v1->unk_08 = 28.0f;
                var_v1->unk_0C = 104.0f;
                var_v1->unk_06 = 0x1F;
                break;
            case 2:
                var_v1->track = 0;
                var_v1->unk_08 = 76.0f;
                var_v1->unk_06 = 0xCB;
                var_v1->unk_0C = 62.0f;
                break;
            case 3:
                var_v1->track = 0;
                var_v1->unk_08 = 0.0f;
                var_v1->unk_06 = 0x34;
                var_v1->unk_0C = 236.0f;
                break;
            case 5:
                var_v1->track = 0;
                var_v1->unk_08 = 0.0f;
                var_v1->unk_0C = 100.0f;
                var_v1->unk_06 = 0x10A;
                break;
            case 4:
                var_v1->track = (s16) (cupFirstTrackIndex + var_a0);
                var_v1->unk_08 = 76.0f;

                if (var_a0 != 0) {
                    var_v1->unk_0C = 120.0f;
                } else {
                    var_v1->unk_0C = 120.0f;
                }

                var_v1->unk_06 = 0x50;
                var_a0++;
                break;
        }
        var_v1++;
    }
    D_i7_8014BE20 = var_v1 - D_i7_8014BE28;
    func_80078104(aCongratulationsTex, 0x3FF0, 0, 0, 0);
    func_80078104(aFinalResultPosition0Tex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPosition1Tex, 0x100, 0, 0, 0);
    func_80078104(aFinalResultPosition2Tex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPosition3Tex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPosition4Tex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPosition5Tex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPosition6Tex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPosition7Tex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPosition8Tex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPosition9Tex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPositionSuffixSTTex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPositionSuffixNDTex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPositionSuffixRDTex, 0x200, 0, 0, 0);
    func_80078104(aFinalResultPositionSuffixTHTex, 0x200, 0, 0, 0);

    if (D_i7_8014BDF6 & 0x20) {

        endingTextures = sEndingTextures[func_i7_GetEndScreenIndex(sCupDifficulty, player->character, player->unk_167)];

        sEndingTex = func_80078104(endingTextures[0], 0x81F0, 0, 1, 0);

        if (endingTextures[1] != NULL) {
            sEndingTextTex = func_80078104(endingTextures[1], 0x3100, 0, 1, 0);
        } else {
            sEndingTextTex = NULL;
        }
    }
}

s32 func_i7_801442A0(void);
void func_i7_FadeInThanksForPlaying(void);
void func_i7_FadeEndScreen(void);
void func_i7_80146920(void);
void func_i7_80147EBC(void);

extern s32 D_800DCCFC;
extern Controller D_800DD180;

s32 func_i7_801441A0(void) {

    func_8007DABC(&D_800DD180);
    D_i7_8014BDF0 = &D_8014B480[D_800DCCFC];
    func_i2_8010466C();
    func_800952F4();
    func_8008675C();
    func_i3_80136A6C();
    func_800A5028();
    func_80074844();
    func_i7_80147EBC();
    if (D_i7_8014BE1C != 0) {
        func_i7_FadeInThanksForPlaying();
    }
    if (sEndScreenState != END_SCREEN_INACTIVE) {
        func_i7_FadeEndScreen();
    }
    func_i7_80146920();

    switch (func_i7_801442A0()) {
        case 1:
            return GAMEMODE_8007;
        case 2:
            return GAMEMODE_800C;
        case 0:
        default:
            return GAMEMODE_11;
    }
}

extern u16 D_800E416E;
extern s32 D_i3_80141908;

s32 func_i7_801442A0(void) {
    unk_8014BE28* var_v0;
    Racer* racer;
    s32 sp1C;
    f32 var_fv0;
    bool var_a0;
    s32 i;

    sp1C = 0;
    switch (D_i7_8014BE08) {
        case 0:
            if (D_i7_8014BE0C >= 120) {
                D_i7_8014BE08 = 1;
                D_i7_8014BE0C = 0;
            } else {
                D_i7_8014BE0C++;
            }
            break;
        case 1:
            D_i7_8014BE0C++;
            var_fv0 = (f32) D_i7_8014BE0C / 30.0f;
            if (var_fv0 >= 1.0f) {
                var_fv0 = 1.0f;
            }
            D_i7_8014BE14 = 255.0f * var_fv0;
            if (D_i7_8014BE0C >= 120) {
                D_i7_8014BE08 = 2;
                D_i7_8014BE14 = 255;
                D_i7_8014BE0C = 0;
                func_80088CAC(1);
            }
            break;
        case 2:
            D_i7_8014BE14 = 255;
            if (D_i7_8014BE0C <= 300) {
                D_i7_8014BE0C++;
            }
            if ((D_i7_8014BE0C == 300) && (D_i7_8014BDF6 & 8)) {
                D_i7_8014C248 = 1;
            }
            D_i7_8014BE10 -= 0.5f;

            var_a0 = true;
            var_v0 = D_i7_8014BE28;
            for (i = 0; i < D_i7_8014BE20; i++) {
                if (var_v0->unk_00 != 0) {
                    var_a0 = false;
                }
                var_v0++;
            }
            if (var_a0) {
                D_i7_8014BE08 = 6;
                D_i7_8014BE0C = 0;
                D_i7_8014C248 = 0;
                if (D_i7_8014BDF6 & 2) {
                    D_i3_80141908 = 1;
                    D_i7_8014BE08 = 3;
                }
            }
            break;
        case 3:
            var_a0 = true;

            for (i = 0, racer = gRacers; i < 3; i++) {
                if (racer->unk_98 > 0.1f) {
                    var_a0 = false;
                    break;
                }
                racer++;
            }

            if (var_a0) {
                D_i7_8014BE08 = 4;
                D_i7_8014BE0C = 0;
            }
            break;
        case 4:
            D_i7_8014BE0C++;

            if (D_i7_8014BE0C == 1) {
                D_i7_8014BF28 |= 4;
                func_80088CAC(4);
            }
            if (D_i7_8014BE0C == 271) {
                D_i7_8014BF28 |= 2;
                func_80088CAC(3);
            }
            if (D_i7_8014BE0C == 541) {
                D_i7_8014BF28 |= 1;
                func_80088CAC(2);
            }
            if (D_i7_8014BE0C > 1020) {
                if (D_i7_8014BDF6 & 0x20) {
                    D_i7_8014BE08 = 5;
                    sEndScreenState = END_SCREEN_FADE_IN;
                } else {
                    D_i7_8014BE08 = 6;
                }
                D_i7_8014BE0C = 0;
            }
            break;
        case 5:
            if (sEndScreenState == END_SCREEN_INACTIVE) {
                D_i7_8014BE08 = 6;
                D_i7_8014BE0C = 0;
            }
            break;
        case 6:
            D_i7_8014BE0C++;
            if (D_i7_8014BE0C > 0) {
                D_i7_8014BE08 = 7;
                D_i7_8014BE0C = 0;
                if (D_i7_8014BDF6 & 1) {
                    D_i7_8014C248 = 2;
                }
            }
            break;
        case 7:
            if ((D_i7_8014C248 == 0) && (D_i7_8014BF92 == 0)) {
                D_i7_8014BE0C++;
                if (D_i7_8014BE0C == 0x3C) {
                    D_i7_8014BE1C = 1;
                    func_800BB09C();
                }
            }
            if (D_i7_8014BE0C >= 360) {
                D_i7_8014BE0C = 360;
                if (D_800E416E & (BTN_A | BTN_START)) {
                    sp1C = 1;
                }
            }
            break;
    }

    var_v0 = D_i7_8014BE28;
    for (i = 0; i < D_i7_8014BE20; i++) {
        switch (var_v0->unk_00) {
            case 1:
                if ((D_i7_8014BE08 != 0) && (var_v0->unk_04 == 0)) {
                    var_v0->unk_04 = 1;
                }
                break;
            case 2:
                if ((D_i7_8014BE08 != 0) && (var_v0->unk_04 == 0)) {
                    var_v0->unk_04 = 1;
                }
                break;
            default:
                if ((D_i7_8014BE08 == 2) && (var_v0->unk_04 == 0)) {
                    var_v0->unk_04 = 1;
                }
                break;
        }
        var_v0++;
    }
    if ((sp1C != 0) && (D_i7_8014BDF6 & 0x10)) {
        sp1C = 2;
    }
    return sp1C;
}

Gfx* func_i7_80144B2C(Gfx*);
Gfx* func_i7_80146E28(Gfx*);
Gfx* func_i7_80147AC8(Gfx*);

Gfx* func_i7_801447F4(Gfx* gfx) {

    if (D_i2_80106F10 != 0) {
        D_i2_80106F10--;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPPipelineMode(gfx++, G_PM_NPRIMITIVE);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCD04]));
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    }

    gSPDisplayList(gfx++, D_303A810);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCD04]));

    D_800F8520 = D_800DCCF0->unk_10008;
    D_800E5ECC = D_800DCCF0->unk_21B48;
    D_800E5ED0 = &D_800DCCF0->unk_21B48[0x7FF];
    gfx = func_i3_801381DC(gfx, 0, 0);
    gfx = func_800A9938(gfx, 0);
    gfx = func_8006DAAC(gfx, 0);
    gfx = func_i7_80146E28(gfx);

    gSPLoadUcodeL(gfx++, gspF3DLX_Rej_fifo);
    gfx = func_80076C08(gfx);
    gSPClipRatio(gfx++, FRUSTRATIO_3);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCD04]));
    gSPPerspNormalize(gfx++, D_800E5220[0].unk_118);
    gSPMatrix(gfx++, D_1000000.unk_20208, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gfx = func_800833AC(gfx, 0, 0);
    gfx = func_80096CE8(gfx, 0);
    gfx = func_i7_80147AC8(gfx);
    return func_i7_80144B2C(gfx);
}

Gfx* func_i7_DrawFinalResultsRaceResult(Gfx*, unk_8014BE28*, f32);
Gfx* func_i7_801454B4(Gfx*, unk_8014BE28*, f32);
Gfx* func_i7_DrawFinalResultsCupInfo(Gfx*, unk_8014BE28*, f32);
Gfx* func_i7_DrawThanksForPlayingWindow(Gfx*);
Gfx* func_i7_DrawEndScreen(Gfx*);

Gfx* func_i7_80144B2C(Gfx* gfx) {
    unk_8014BE28* var_s1;
    f32 textureTop;
    s32 i;

    textureTop = D_i7_8014BE10;

    var_s1 = D_i7_8014BE28;
    for (i = 0; i < D_i7_8014BE20; i++, var_s1++) {
        textureTop += var_s1->unk_0C;
        if ((var_s1->unk_00 == 0) || (var_s1->unk_04 == 0) || textureTop > 232.0f) {
            continue;
        }

        if ((var_s1->unk_06 + textureTop) < 8.0f) {
            var_s1->unk_00 = 0;
            continue;
        }
        switch (var_s1->unk_00) {
            case 1:
                if (D_i7_8014BDF6 & 4) {
                    gDPPipeSync(gfx++);
                    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i7_8014BE14);

                    gfx = func_8007B14C(gfx, func_800783AC(aCongratulationsTex), var_s1->unk_08, textureTop, 264, 31,
                                        G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
                }
                break;
            case 2:
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i7_8014BE14);

                gfx = func_8007B14C(gfx, sEndingTex, var_s1->unk_08, textureTop, 168, 99, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                                    1, 1, 0, 0);

                if (sEndingTextTex != NULL) {
                    gfx = func_8007B14C(gfx, sEndingTextTex, var_s1->unk_08 + -14.0f, textureTop + 99.0f + 10.0f, 196,
                                        32, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
                }
                break;
            case 3:
                gfx = func_i7_DrawFinalResultsCupInfo(gfx, var_s1, textureTop);
                break;
            case 4:
                gfx = func_i7_DrawFinalResultsRaceResult(gfx, var_s1, textureTop);
                break;
            case 5:
                gfx = func_i7_801454B4(gfx, var_s1, textureTop);
                break;
        }
    }

    if (D_i7_8014BE1C != 0) {
        gfx = func_i7_DrawThanksForPlayingWindow(gfx);
    }
    if (sEndScreenState != END_SCREEN_INACTIVE) {
        gfx = func_i7_DrawEndScreen(gfx);
    }
    return gfx;
}

Gfx* func_i7_DrawFinalResultsPosition(Gfx*, s32, s32, s32, bool);
Gfx* func_i7_DrawResultsRacersKOd(Gfx*, s32, s32, s32);

Gfx* func_i7_DrawFinalResultsRaceResult(Gfx* gfx, unk_8014BE28* arg1, f32 baseYPos) {
    s32 cupTrackNo;
    f32 var_fv0;
    bool shouldHighlight;
    s32 pad[2];
    RaceStats* raceStats;
    const char* trackName;

    cupTrackNo = arg1->track % 6;
    raceStats = &gCupRaceStats[0][cupTrackNo];
    trackName = gTrackNames[arg1->track];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    var_fv0 = 160.0f;

    gfx = func_i2_80106450(gfx, (var_fv0 + 2.0f) - (func_i2_801062E4(trackName, 3, 1) / 2), (baseYPos + 16.0f) + 2.0f,
                           trackName, 1, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    gfx = func_i2_80106450(gfx, var_fv0 - (func_i2_801062E4(trackName, 3, 1) / 2), (baseYPos + 16.0f), trackName, 1, 3,
                           0);
    gSPDisplayList(gfx++, D_8014940);

    if (raceStats->position == 1) {
        shouldHighlight = true;
    } else {
        shouldHighlight = false;
    }

    gfx = func_i7_DrawFinalResultsPosition(gfx, 50, baseYPos + 26.0f, raceStats->position, shouldHighlight);
    gDPPipeSync(gfx++);
    if (0) {}
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    if (0) {}
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gfx = func_i3_DrawTimerScisThousandths(gfx, raceStats->raceTime, 110, (baseYPos + 28.0f), 1.0f);
    gDPPipeSync(gfx++);
    gfx = func_i3_DrawSpeed(gfx, 194, (baseYPos + 28.0f), raceStats->maxSpeed, false, false);
    gDPPipeSync(gfx++);
    return func_i7_DrawResultsRacersKOd(gfx, 110, (baseYPos + 48.0f), raceStats->racersKOd);
}

Gfx* func_i7_DrawFinalResultsPosition(Gfx* gfx, s32 xPos, s32 yPos, s32 position, bool shouldHighlight) {
    s32 i;
    s32 xOffset;
    s32 width;
    s32 positionSuffix;
    s32 digits[2];
    s32 positionVar;
    s32 digit;

    positionVar = position;

    if ((position == 1) || (position == 21)) {
        positionSuffix = POSITION_SUFFIX_ST;
    } else if ((position == 2) || (position == 22)) {
        positionSuffix = POSITION_SUFFIX_ND;
    } else if ((position == 3) || (position == 23)) {
        positionSuffix = POSITION_SUFFIX_RD;
    } else {
        positionSuffix = POSITION_SUFFIX_TH;
    }

    for (i = 0; i < 2; i++) {
        digits[i] = positionVar % 10;
        positionVar /= 10;
    }

    gDPPipeSync(gfx++);

    if (shouldHighlight) {
        gfx = func_8007DB28(gfx, 0);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 255, 255);
    }

    for (i = 0; i < 2; i++) {
        digit = digits[1 - i];
        if ((i == 0) && (digit == 0)) {
            xPos += 16;
            continue;
        }

        if (digit != 1) {
            xOffset = 0;
            width = 16;
        } else {
            xOffset = 8;
            width = 8;
        }
        gfx = func_8007B14C(gfx, func_800783AC(sFinalResultPositionDigitTexs[digit]), xPos + xOffset, yPos, width, 16,
                            G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0, 0, 0);
        xPos += 16;
    }

    return func_8007B14C(gfx, func_800783AC(sFinalResultsPositionSuffixTexs[positionSuffix]), xPos, yPos, 16, 16,
                         G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0, 0, 0);
}

Gfx* func_i7_801454B4(Gfx* gfx, unk_8014BE28* arg1, f32 arg2) {
    s32 i;
    f32 temp_fa1;
    f32 left;
    s32 positionDigits[2];
    s32 ordinalSuffix;
    s32 position;
    s32 positionDigit;
    char racersKOdStr[4];

    position = D_80106F48;
    if ((position == 1) || (position == 21)) {
        ordinalSuffix = POSITION_SUFFIX_ST;
    } else if ((position == 2) || (position == 22)) {
        ordinalSuffix = POSITION_SUFFIX_ND;
    } else if ((position == 3) || (position == 23)) {
        ordinalSuffix = POSITION_SUFFIX_RD;
    } else {
        ordinalSuffix = POSITION_SUFFIX_TH;
    }

    for (i = 0; i < ARRAY_COUNT(positionDigits); i++) {
        positionDigits[i] = position % 10;
        position /= 10;
    }

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    left = 160.0f;
    temp_fa1 = arg2 + 16.0f;

    gfx = func_i2_80106450(gfx, (left + 2.0f) - (func_i2_801062E4(sTotalRankingStr, 3, 1) / 2), temp_fa1 + 2.0f,
                           sTotalRankingStr, 1, 3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 250, 0, 255);
    gfx = func_i2_80106450(gfx, left - (func_i2_801062E4(sTotalRankingStr, 3, 1) / 2), temp_fa1, sTotalRankingStr, 1, 3,
                           0);
    temp_fa1 += 10.0f;
    left = 122.0f;
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    for (i = 0; i < ARRAY_COUNT(positionDigits); i++) {
        positionDigit = positionDigits[1 - i];
        if ((i == 0) && (positionDigit == 0)) {
            left += 28.0f;
            continue;
        }

        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, aPositionDigitTexs[positionDigit], G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, (s32) (left) << 2, (s32) (temp_fa1) << 2, (s32) (left + 28.0f) << 2,
                                (s32) (temp_fa1 + 32.0f) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        left += 28.0f;
    }

    gDPLoadTextureBlock(gfx++, aPositionOrdinalSuffixTexs[ordinalSuffix], G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPScisTextureRectangle(gfx++, (s32) (left) << 2, (s32) ((temp_fa1 + 12.0f)) << 2, (s32) (left + 20.0f) << 2,
                            (s32) ((temp_fa1 + 12.0f) + 20.0f) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gfx = func_i7_DrawResultsRacersKOd(gfx, 0x6E, arg2 + 70.0f, sTotalRacersKOd);

    if (sTotalRacersKOd > 0) {

        for (i = 0; i < 4; i++) {
            racersKOdStr[i] = 0;
        }

        sprintf(racersKOdStr, "%d", sTotalRacersKOd);

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        i = sTotalRacersKOd / 10;
        if (sTotalRacersKOd % 10) {
            i++;
        }
        gfx = func_i2_80106450(gfx, 0x6E, (arg2 + 70.0f) + 20.0f + (i * 10), racersKOdStr, 1, 3, 0);
    }
    return gfx;
}

extern const char* sDifficultyNames[];

Gfx* func_i7_DrawFinalResultsCupInfo(Gfx* gfx, unk_8014BE28* arg1, f32 arg2) {
    UNUSED s32 pad;
    f32 var_fv0;
    f32 temp_fa1;
    const char* name;

    name = sCupNames[sCupNameIndex];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    var_fv0 = 160.0f;
    temp_fa1 = arg2 + 16.0f;

    gfx = func_i2_80106450(gfx, (var_fv0 + 2.0f) - (func_i2_801062E4(name, 3, 1) / 2), temp_fa1 + 2.0f, name, 1, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_i2_80106450(gfx, var_fv0 - (func_i2_801062E4(name, 3, 1) / 2), temp_fa1, name, 1, 3, 0);

    temp_fa1 += 20.0f;
    name = sDifficultyNames[sCupDifficulty];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gfx = func_i2_80106450(gfx, (var_fv0 + 2.0f) - (func_i2_801062E4(name, 3, 1) / 2), temp_fa1 + 2.0f, name, 1, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    return func_i2_80106450(gfx, var_fv0 - (func_i2_801062E4(name, 3, 1) / 2), temp_fa1, name, 1, 3, 0);
}

void func_i7_FadeInThanksForPlaying(void) {
    if (sThanksForPlayingFade < 120) {
        sThanksForPlayingFade++;
    }
}

#ifdef IMPORT_BSS
Gfx* func_i7_DrawThanksForPlayingWindow(Gfx* gfx) {
    static s32 sThanksForPlayingLeft;
    static s32 sThanksForPlayingTop;
    static s32 sThanksForPlayingWidth;
    static s32 sThanksForPlayingBackgroundAlpha;

    sThanksForPlayingBackgroundAlpha = (sThanksForPlayingFade * 255) / 120;

    gfx = func_8007A440(gfx, 12, 8, 308, 232, 0, 0, 0, sThanksForPlayingBackgroundAlpha);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, sThanksForPlayingBackgroundAlpha);

    sThanksForPlayingWidth = func_i2_801062E4(sThanksForPlayingStr, 1, 1);
    sThanksForPlayingLeft = (SCREEN_WIDTH - sThanksForPlayingWidth) / 2;
    sThanksForPlayingTop = SCREEN_HEIGHT / 2;

    return func_i2_80106450(gfx, sThanksForPlayingLeft, sThanksForPlayingTop, sThanksForPlayingStr, 1, 1, 1);
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i7/E9A30/func_i7_DrawThanksForPlayingWindow.s")
#endif

void func_i7_FadeEndScreen(void) {
    switch (sEndScreenState) {
        case END_SCREEN_FADE_IN:
            sEndScreenFade++;
            sEndScreenAlpha = (sEndScreenFade * 255) / 120;
            if (sEndScreenFade >= 120) {
                sEndScreenState = END_SCREEN_WAIT;
                sEndScreenFade = 0;
                sEndScreenAlpha = 255;
            }
            return;
        case END_SCREEN_WAIT:
            sEndScreenFade++;
            if (sEndScreenFade >= 180) {
                sEndScreenState = END_SCREEN_FADE_OUT;
                sEndScreenFade = 0;
            }
            break;
        case END_SCREEN_FADE_OUT:
            sEndScreenFade++;
            sEndScreenAlpha = 255 - (sEndScreenFade * 255) / 120;
            if (sEndScreenFade >= 120) {
                sEndScreenState = END_SCREEN_INACTIVE;
                sEndScreenFade = 0;
                sEndScreenAlpha = 0;
            }
            break;
    }
}

Gfx* func_i7_DrawEndScreen(Gfx* gfx) {

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, sEndScreenAlpha);

    gfx = func_8007B14C(gfx, sEndingTex, 76, 62, 168, 99, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
    if (sEndingTextTex != NULL) {
        gfx = func_8007B14C(gfx, sEndingTextTex, 62, 171, 196, 32, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
    }
    return gfx;
}

Gfx* func_i7_DrawResultsRacersKOd(Gfx* gfx, s32 left, s32 top, s32 racersKOd) {
    s32 i;
    s32 j;
    s32 temp;
    s32 pad;
    s32 numBlocks;
    s32 remainder;

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gfx++, aHudRacersKOdTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    numBlocks = racersKOd / 10;
    remainder = racersKOd % 10;

    for (i = 0; i < numBlocks; i++) {
        temp = i * 10;
        for (j = 0; j < 10; j++) {
            gSPScisTextureRectangle(gfx++, (left + j * 10) << 2, (top + temp) << 2, (left + 8 + j * 10) << 2,
                                    (top + 8 + temp) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }

    if (remainder > 0) {
        for (j = 0; j < remainder; j++) {
            gSPScisTextureRectangle(gfx++, (left + j * 10) << 2, (top + numBlocks * 10) << 2, (left + 8 + j * 10) << 2,
                                    (top + 8 + numBlocks * 10) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }
    return gfx;
}

extern f32 D_800DD230[];

#ifdef IMPORT_BSS
void func_i7_801467FC(void) {
    f32 temp_fa0;
    s32 i;
    unk_8014BEC8* var_v0 = D_i7_8014BEC8;
    Vec3f* var = D_i7_8014BF30;

    if (1) {}

    for (i = 0; i < 3; var_v0++, i++) {
        var_v0->unk_00 = 0;
        var_v0->unk_02 = 0;
        var_v0->unk_04 = 0;
        var_v0->unk_10 = 0.0f;
        var_v0->unk_08 = 0.0f;
        var_v0->unk_0C = -160.0f;
        var_v0->unk_14 = 0.0f;
        var_v0->unk_18 = 0.0f;
        var_v0->unk_1C = 1.0f;
    }
    i = (Math_Round(341.33334f) + 0x400);
    temp_fa0 = D_800DD230[i & 0xFFF] * 60.0f;

    var->x = 0.0f;
    var->y = 0.0f;
    var->z = 0.0f;
    var++;

    var->x = 30.0f;
    var->y = 0.0f;
    var->z = temp_fa0;
    var++;

    var->x = -30.0f;
    var->y = 0.0f;
    var->z = temp_fa0;
    var++;

    var->x = -60.0f;
    var->y = 0.0f;
    var->z = 0.0f;
    var++;

    var->x = -30.0f;
    var->y = 0.0f;
    var->z = 0.0f - temp_fa0;
    var++;

    var->x = 30.0f;
    var->y = 0.0f;
    var->z = 0.0f - temp_fa0;
    var++;

    var->x = 60.0f;
    var->y = 0.0f;
    var->z = 0.0f;
    var++;
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i7/E9A30/func_i7_801467FC.s")
#endif

#ifdef NON_MATCHING
// vtx weirdness
extern Vec3f D_i7_8014BF30[];

void func_i7_80146920(void) {
    unk_8014BEC8* var_s2;
    Racer* var_s4;
    s32 i;
    s32 j;
    s32 var_a1;
    s32 var_a2;
    Vtx* vtx;
    f32 var_fv0;
    f32 temp_fv0;

    for (i = 0, var_s2 = D_i7_8014BEC8, var_s4 = gRacers; i < 3; i++, var_s2++, var_s4++) {
        switch (var_s2->unk_00) {
            case 0:
                if (D_i7_8014BF28 & (1 << i)) {
                    var_s2->unk_00 = 1;
                    var_s2->unk_04 = 0;
                    var_s2->unk_08 = var_s4->unk_180.x;
                    var_s2->unk_10 = var_s4->unk_180.z;
                    var_s2->unk_14 = var_s4->unk_C0.x.x;
                    var_s2->unk_18 = var_s4->unk_C0.x.y;
                    var_s2->unk_1C = var_s4->unk_C0.x.z;
                    func_800BA8D8(0x40);
                }
                break;
            case 2:
                break;
            case 1:
                var_s2->unk_02 |= 3;
                var_s2->unk_04++;
                var_fv0 = var_s2->unk_04 / 60.0f;

                if (var_fv0 > 1.0f) {
                    var_fv0 = 1.0f;
                }

                vtx = D_i7_8014BDF0->unk_180[i];
                for (j = 0; j < 13; j++) {
                    if (j < 7) {
                        var_a1 = D_i7_8014BF30[j].x;
                        var_a2 = D_i7_8014BF30[j].z;
                    } else if (j == 12) {
                        var_a1 = D_i7_8014BF30[1].x * var_fv0;
                        var_a2 = D_i7_8014BF30[1].z * var_fv0;
                    } else {
                        var_a1 = D_i7_8014BF30[j - 5].x * var_fv0;
                        var_a2 = D_i7_8014BF30[j - 5].z * var_fv0;
                    }
                    vtx->v.ob[0] = var_a1;
                    vtx->v.ob[1] = 0;
                    vtx->v.ob[2] = var_a2;
                    vtx->v.flag = 0;
                    vtx->v.tc[0] = 0;
                    vtx->v.tc[1] = 0;
                    vtx->v.cn[0] = 0;
                    vtx->v.cn[1] = 0;
                    vtx->v.cn[2] = 0;
                    vtx->v.cn[3] = 0xFF;
                    vtx++;
                }

                var_s2->unk_0C = (((D_i7_8014A040[i] - -160.0f) * var_s2->unk_04) / 270.0f) + -160.0f;
                if (var_s2->unk_04 >= 0x10E) {
                    var_s2->unk_00 = 2;
                    var_s2->unk_0C = D_i7_8014A040[i];
                    var_s2->unk_04 = 0;
                }
                temp_fv0 = (var_s2->unk_0C + 120.0f) - var_s4->unk_168.y;
                if (temp_fv0 > 0.0f) {
                    var_s4->unk_A4 += temp_fv0;
                }
                break;
        }

        if (var_s2->unk_02 & 2) {
            func_8006BC84(&D_i7_8014BDF0->unk_C0[i], NULL, D_i7_80149FE8, D_i7_80149FE8, D_i7_80149FE8, var_s2->unk_14,
                          var_s2->unk_18, var_s2->unk_1C, 0.0f, 1.0f, 0.0f, var_s2->unk_08, 0.0f, var_s2->unk_10);
        }
        if (var_s2->unk_02 & 1) {
            func_8006BC84(&D_i7_8014BDF0->unk_00[i], NULL, D_i7_80149FE4, D_i7_80149FE4, D_i7_80149FE4, var_s2->unk_14,
                          var_s2->unk_18, var_s2->unk_1C, 0.0f, 1.0f, 0.0f, var_s2->unk_08, var_s2->unk_0C,
                          var_s2->unk_10);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i7/E9A30/func_i7_80146920.s")
#endif

#ifdef NON_MATCHING
// very weird, possibly patched after compilation?
Gfx* func_i7_80146E28(Gfx* gfx) {
    s32 i;

    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CLIPPING);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTextureDetail(gfx++, G_TD_CLAMP);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);

    gDPPipeSync(gfx++);
    // gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPSetRenderMode(gfx++, (G_RM_AA_ZB_OPA_SURF) & ~Z_CMP, (G_RM_AA_ZB_OPA_SURF2) & ~Z_CMP);
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gDPSetDepthSource(gfx++, G_ZS_PRIM);
    gDPSetPrimDepth(gfx++, 0x7FC0, 0);

    for (i = 0; i < 3; i++) {
        if (!(D_i7_8014BEC8[i].unk_02 & 2)) {
            continue;
        }
        gSPMatrix(gfx++, &D_i7_8014BDF0->unk_C0[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPVertex(gfx++, D_i7_8014BDF0->unk_180[i], 13, 0);
        gSP2Triangles(gfx++, 0, 7, 1, 0, 0, 8, 2, 0);
        gSP2Triangles(gfx++, 0, 9, 3, 0, 0, 10, 4, 0);
        gSP2Triangles(gfx++, 0, 11, 5, 0, 0, 12, 6, 0);
    }

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);

    gDPSetDepthSource(gfx++, G_ZS_PIXEL);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    for (i = 0; i < 3; i++) {
        if (!(D_i7_8014BEC8[i].unk_02 & 1)) {
            continue;
        }
        gSPMatrix(gfx++, &D_i7_8014BDF0->unk_00[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, D_i7_80149FD8[i]);
    }

    return gfx;
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i7/E9A30/func_i7_80146E28.s")
#endif

extern s32 D_800E5EC0;

void func_i7_801471C0(void) {
    s32 var_a0;
    s32 var_v0;
    s32 i;
    s32 j;
    s32 character;

    D_i7_8014C044 = 0;
    if ((sCupDifficulty > NOVICE) && (D_80106F48 < 4)) {
        D_i7_8014C044 = 1;
        D_i7_8014C038 = func_800768F4(0, 0xA80);
        D_i7_8014C03C = func_800768F4(0, 0xA80);
        D_i7_8014C040 = func_800768F4(0, 0xA80);

        for (j = 0; j < 0x540; j++) {
            D_i7_8014C038[j] = D_i7_8014C03C[j] = D_i7_8014C040[j] = 0;
        }

        for (i = D_800E5EC0 - 1; i >= 0; i--) {

            character = gRacers[i].character;
            j = character;
            if ((character == CAPTAIN_FALCON) && (gRacers[i].unk_167 >= 2)) {
                j = 30;
            } else if ((character == SAMURAI_GOROH) && (gRacers[i].unk_167 >= 2)) {
                j = 31;
            } else if ((character == JODY_SUMMER) && (gRacers[i].unk_167 >= 2)) {
                j = 32;
            }
            D_i7_8014C034 = func_80078104(sFullPortraits[j], 0x15888, 0, 1, 1);

            for (j = 0; j != 0x2A; j++) {
                for (var_a0 = 0; var_a0 < 32; var_a0++) {
                    var_v0 = (s32) (var_a0 * 5.625f) + (s32) (5.8333335f * j) * 180;
                    D_i7_8014C038[var_a0 + j * 32] = D_i7_8014C034[var_v0];
                }
            }

            j = 0;
            while (j == 0) {
                j = 0;

                for (var_a0 = 0x520; var_a0 < 0x540; var_a0++) {
                    if (D_i7_8014C038[var_a0] != 0) {
                        j++;
                    }
                }

                if (j == 0) {

                    for (var_a0 = 41; var_a0 > 0; var_a0--) {
                        for (var_v0 = 0; var_v0 < 32; var_v0++) {
                            D_i7_8014C038[var_a0 * 32 + var_v0] = D_i7_8014C038[var_a0 * 32 + var_v0 - 32];
                        }
                    }

                    for (var_v0 = 0; var_v0 < 32; var_v0++) {
                        D_i7_8014C038[var_v0] = 0;
                    }
                }
            }

            for (j = 0; j < 32; j++) {
                D_i7_8014C038[j] = 0;
            }

            if (i == 2) {
                for (j = 0; j < 0x540; j++) {
                    D_i7_8014C040[j] = D_i7_8014C038[j];
                }
            }

            if (i == 1) {
                for (j = 0; j < 0x540; j++) {
                    D_i7_8014C03C[j] = D_i7_8014C038[j];
                }
            }
        }
        D_i7_8014C028[0] = D_i7_8014C038;
        D_i7_8014C028[1] = D_i7_8014C03C;
        D_i7_8014C028[2] = D_i7_8014C040;
    }
}

void func_i7_801478E8(void) {
    Racer* racer;
    s32 i;

    if (D_i7_8014C044 == 1) {
        for (i = 0; i < D_800E5EC0; i++) {
            racer = &gRacers[i];
            func_8006BC84(
                &D_i7_8014BDF0->unk_3F0[i], NULL, 0.04f, 0.04f, 0.04f, -D_800E5220[0].unk_5C.x.x,
                -D_800E5220[0].unk_5C.x.y, -D_800E5220[0].unk_5C.x.z, racer->unk_C0.y.x, racer->unk_C0.y.y,
                racer->unk_C0.y.z,
                racer->unk_168.x + ((racer->unk_C0.x.x * 23.0f * 3.0f) / 2) + (racer->unk_C0.z.x * 23.0f * 0.8f),
                (D_i7_8014BEC8[i].unk_0C + 120.0f) - 1.0f,
                racer->unk_168.z + ((racer->unk_C0.x.z * 23.0f * 3.0f) / 2) + (racer->unk_C0.z.z * 23.0f * 0.8f));
        }
    }
}

Gfx* func_i7_80147AC8(Gfx* gfx) {
    s32 i;

    if ((D_i7_8014C044 == 1) && (D_i7_8014BF28 != 0)) {
        gSPDisplayList(gfx++, D_400A258);
        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);

        for (i = 0; i < D_800E5EC0; i++) {
            gDPPipeSync(gfx++);

            gDPLoadTextureBlock(gfx++, D_i7_8014C028[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 42, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPMatrix(gfx++, &D_i7_8014BDF0->unk_3F0[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            gSPDisplayList(gfx++, D_i7_8014AF78);
        }
    }
    return gfx;
}

extern s16 D_80115DE0;

void func_i7_80147CC0(void) {
    s32 i;

    D_80115DE0 = D_800E5EC0;
    if (D_80106F48 < 4) {
        func_i7_801471C0();
        D_i7_8014BF94 = func_800768F4(0, 0xCB20);
        D_i7_8014BF98 = func_800768F4(0, 0x280);
        D_i7_8014BF90 = 10;

        for (i = 0; i < D_i7_8014BF90; i++) {
            D_i7_8014BF98[i].unk_24 = 0;
        }

        D_i7_8014C248 = 0;
        D_i7_8014C020 = 0;
        if (D_80106F48 == 1) {
            if (gCupType == X_CUP) {
                func_80077CF0(D_i7_8014AD18[Math_Rand1() % 4], 0x200, D_i7_8014C048);
            } else if ((gRacers[0].character == CAPTAIN_FALCON) && (gRacers[0].unk_167 >= 2)) {
                func_80077CF0(D_i7_8014AD0C, 0x200, D_i7_8014C048);
            } else if ((gRacers[0].character == SAMURAI_GOROH) && (gRacers[0].unk_167 >= 2)) {
                func_80077CF0(D_i7_8014AD10, 0x200, D_i7_8014C048);
            } else if ((gRacers[0].character == JODY_SUMMER) && (gRacers[0].unk_167 >= 2)) {
                func_80077CF0(D_i7_8014AD14, 0x200, D_i7_8014C048);
            } else {
                func_80077CF0(D_i7_8014AC94[gRacers[0].character], 0x200, D_i7_8014C048);
            }
        } else {
            func_80077CF0(D_i7_8014AD28, 0x200, D_i7_8014C048);
        }
    }
}

#ifdef NON_EQUIVALENT
// probably equivalent, just some float s-reg blowup
void func_i7_80147EBC(void) {
    s32 i;
    s32 j;
    unk_struct_1DC* var = &D_800E5220[0];
    unk_8014BF98* temp_s4;
    unk_8014BF94* temp_s0;
    s32 var_s1;
    bool var_a1;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 var_fa0;
    f32 temp_fa1;
    f32 temp_fv0_6;
    f32 temp_fv0_9;
    f32 temp_fv0_12;
    f32 var_fv1;
    f32 temp_fv1_5;
    f32 temp_fv1_6;

    if (D_80106F48 >= 4) {
        return;
    }

    func_i7_801478E8();
    D_i7_8014AC00++;

    for (i = 0; i < D_i7_8014BF90; i++) {
        temp_s4 = &D_i7_8014BF98[i];
        temp_s4->unk_25 = temp_s4->unk_24;

        switch (D_i7_8014BF98[i].unk_24) {
            case 0:
                temp_s4->unk_00 = (Math_Rand1() % 256) - 128.1f;
                temp_s4->unk_08 = (Math_Rand1() % 256) - 128.1f;

                var_fv1 = sqrtf(SQ(temp_s4->unk_00) + SQ(temp_s4->unk_08));

                if (var_fv1 < 0.001f) {
                    var_fv1 = 0.001f;
                }
                var_fv1 = 1.0f / var_fv1;
                temp_s4->unk_00 = temp_s4->unk_00 * var_fv1 * 700.0f;
                temp_s4->unk_08 = temp_s4->unk_08 * var_fv1 * 700.0f;

                temp_s4->unk_04 = ((Math_Rand1() % 16) + 0x190) * -1.0f;
                temp_s4->unk_0C = temp_s4->unk_10 = 0x200;
                temp_s4->unk_1C = 25.0f;
                temp_s4->unk_18 = ((Math_Rand1() % 256) - 128.0f) * 0.01f;
                temp_s4->unk_20 = ((Math_Rand1() % 256) - 128.0f) * 0.01f;
                temp_s4->unk_3C = Math_Rand1() % 7;
                temp_s4->unk_2C = Math_Rand1() % 7;
                temp_s4->unk_34 = Math_Rand1() % (128 - (sCupDifficulty * 32));
                temp_s4->unk_28 = 1.2f;
                switch (D_i7_8014C248) {
                    case 0:
                        break;
                    case 1:
                        temp_s4->unk_2E = i * 100;
                        temp_s4->unk_30 = 100;
                        temp_s4->unk_24 = 1;
                        break;
                    case 2:
                        if (i == 0) {
                            var_a1 = false;
                            for (j = 0; j < D_i7_8014BF90; j++) {
                                if (D_i7_8014BF98[j].unk_24 != 0) {
                                    var_a1 = true;
                                }
                            }

                            if (!var_a1) {
                                temp_s4->unk_2E = 0;
                                temp_s4->unk_30 = 0x320;
                                temp_s4->unk_24 = 1;
                                temp_s4->unk_2C = 0x20;
                                D_i7_8014C248 = 0;
                                temp_s4->unk_00 = var->unk_5C.x.x * 700.0f;
                                temp_s4->unk_08 = var->unk_5C.x.z * 700.0f;
                                temp_s4->unk_18 = 0.0f;
                                temp_s4->unk_20 = 0.0f;
                                temp_s4->unk_04 = -500.0f;
                                temp_s4->unk_28 = 1.5f;
                                temp_s4->unk_1C = 28.0f;
                                D_i7_8014BF90 = 1;
                            }
                        }
                        break;
                }
                if (temp_s4->unk_24 == 1) {
                    for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                        temp_s0 = &D_i7_8014BF94[j];
                        temp_s0->unk_2C = 0;
                        temp_s0->unk_28 = 0;
                        temp_s0->unk_10 = 0x200;
                        temp_s0->unk_0C = 0x200;
                    }
                }
                break;
            case 1:
                if (temp_s4->unk_34 > 0) {
                    temp_s4->unk_34--;
                } else {
                    temp_s4->unk_24 = 2;
                }
                break;
            case 2:
                temp_s4->unk_00 += temp_s4->unk_18;
                temp_s4->unk_04 += temp_s4->unk_1C;
                temp_s4->unk_08 += temp_s4->unk_20;
                temp_s4->unk_1C -= 0.5f;
                if (temp_s4->unk_1C < 0.0f) {
                    temp_s4->unk_24 = 3;
                    var_s1 = 0;
                    if (temp_s4->unk_2C == 0x20) {
                        func_800BAA88(0x40, 0x7F);
                    } else {
                        var_fs0 = temp_s4->unk_00;
                        temp_ft4 = temp_s4->unk_04;
                        temp_ft5 = temp_s4->unk_08;
                        var_fa0 = sqrtf(SQ(var_fs0) + SQ(temp_ft4) + SQ(temp_ft5));

                        if (var_fa0 != 0.0f) {
                            var_fa0 *= -((var_fs0 * var->unk_5C.z.x) + (temp_ft4 * var->unk_5C.z.y) +
                                         (var->unk_5C.z.z * temp_ft5)) /
                                       var_fa0;
                        }
                        if ((var_fa0 >= -1000.0f) && (var_fa0 <= 1000.0f)) {
                            // var_ft3 = (u32) (((var_fa0 + 1000.0f) / 2000.0f) * 127.0f);
                            func_800BAA88((s32) (f32) (u32) (((var_fa0 + 1000.0f) / 2000.0f) * 127.0f), 0x40);
                        }
                    }
                    var_fs1 = sqrtf(SQ(D_800E5220[0].unk_5C.z.x) + SQ(D_800E5220[0].unk_5C.z.z));

                    if (var_fs1 < 0.0001f) {
                        var_fs1 = 0.0001f;
                    }

                    var_fs1 = 1.0f / var_fs1;
                    for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                        temp_s0 = &D_i7_8014BF94[j];
                        temp_s0->unk_00 = temp_s4->unk_00;
                        temp_s0->unk_04 = temp_s4->unk_04;
                        temp_s0->unk_08 = temp_s4->unk_08;

                        switch (temp_s4->unk_2C) {
                            case 0:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = (Math_Rand1() % 5) + 5.1f;
                                break;
                            case 1:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = Math_Rand1() % 5;
                                break;
                            case 2:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = (Math_Rand1() % 10) - 5.1f;
                                break;
                            case 3:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = 0.0f;
                                break;
                            case 4:
                                temp_s0->unk_18 = 0.0f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = (Math_Rand1() % 10) - 5.1f;
                                break;
                            case 5:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = 0.0f;
                                temp_s0->unk_1C = (Math_Rand1() % 10) - 5.1f;
                                break;
                            case 6:
                                switch (j % 3) {
                                    case 0:
                                        temp_s0->unk_20 = (Math_Rand1() % 10) - 5.0f;
                                        temp_s0->unk_18 = 0.0f;
                                        temp_s0->unk_1C = (Math_Rand1() % 10) - 5.0f;
                                        break;
                                    case 1:
                                        temp_s0->unk_18 = (Math_Rand1() % 10) - 5.0f;
                                        temp_s0->unk_1C = 0.0f;
                                        temp_s0->unk_20 = (Math_Rand1() % 10) - 5.0f;
                                        break;
                                    default:
                                        temp_s0->unk_18 = (Math_Rand1() % 10) - 5.0f;
                                        temp_s0->unk_20 = 0.0f;
                                        temp_s0->unk_1C = (Math_Rand1() % 10) - 5.0f;
                                        break;
                                }
                                break;
                            case 32:
                                while (!(D_i7_8014C048[var_s1 >> 3] & D_i7_8014AC8C[var_s1 & 7])) {
                                    var_s1++;
                                    if (var_s1 >= 0x1000) {
                                        var_s1 = 0;
                                    }
                                }

                                temp_fv0_6 = -(((var_s1 & 0x3F) - 0x20) * 0.12f);
                                temp_s0->unk_18 = ((D_800E5220[0].unk_5C.z.x * var_fs1 * 0.866f) -
                                                   (D_800E5220[0].unk_5C.z.z * var_fs1 * 0.5f)) *
                                                  temp_fv0_6;
                                temp_s0->unk_20 = ((D_800E5220[0].unk_5C.z.z * var_fs1 * 0.866f) +
                                                   (D_800E5220[0].unk_5C.z.x * var_fs1 * 0.5f)) *
                                                  temp_fv0_6;
                                temp_s0->unk_1C = -(f32) ((var_s1 >> 6) - 0x48) * 0.12f;
                                var_s1++;
                                break;
                            default:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = (Math_Rand1() % 10) - 5.1f;
                                break;
                        }
                        if (temp_s4->unk_2C != 0x20) {
                            var_fs0 = sqrtf(SQ(temp_s0->unk_18) + SQ(temp_s0->unk_1C) + SQ(temp_s0->unk_20));

                            if (var_fs0 < 0.0001f) {
                                var_fs0 = 0.0001f;
                            }

                            temp_fv0_9 = (((Math_Rand1() % 100) / 100.0f) - 0.5f) + 4.0f;
                            temp_s0->unk_18 = (f32) ((temp_s0->unk_18 / var_fs0) * temp_fv0_9);
                            temp_s0->unk_1C = (f32) ((temp_s0->unk_1C / var_fs0) * temp_fv0_9);
                            temp_s0->unk_20 = (f32) ((temp_s0->unk_20 / var_fs0) * temp_fv0_9);
                        }
                    }
                }
                break;
            case 3:
                for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                    temp_s0 = &D_i7_8014BF94[j];
                    temp_s0->unk_00 += temp_s0->unk_18;
                    temp_s0->unk_04 += temp_s0->unk_1C;
                    temp_s0->unk_08 += temp_s0->unk_20;
                    if (temp_s4->unk_2C != 0x20) {
                        temp_s0->unk_18 = temp_s0->unk_18 * 0.98f;
                        temp_s0->unk_1C = (temp_s0->unk_1C * 0.98f) - 0.05f;
                        temp_s0->unk_20 = temp_s0->unk_20 * 0.98f;
                    } else {
                        temp_s0->unk_18 = temp_s0->unk_18 * 0.985f;
                        temp_s0->unk_1C = (temp_s0->unk_1C * 0.985f) - 0.04f;
                        temp_s0->unk_20 = temp_s0->unk_20 * 0.985f;
                    }
                }
                if (temp_s4->unk_2C != 0x20) {
                    temp_s4->unk_28 -= 0.01f;
                } else {
                    temp_s4->unk_28 -= 0.007f;
                }
                if (temp_s4->unk_28 <= 0.0f) {
                    temp_s4->unk_24 = 0;
                    temp_s4->unk_10 = 0x200;
                    temp_s4->unk_0C = 0x200;
                    temp_s4->unk_28 = 0.0f;
                    for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                        temp_s0 = &D_i7_8014BF94[j];
                        temp_s0->unk_10 = 0x200;
                        temp_s0->unk_0C = 0x200;
                    }
                }
                break;
        }

        if ((temp_s4->unk_24 >= 3) || ((D_i7_8014C020 != 0) && (temp_s4->unk_24 > 0))) {
            var_fs2 = temp_s4->unk_00;
            var_fs0 = temp_s4->unk_08;
            var_fa0 = sqrtf(SQ(var_fs2) + SQ(var_fs0));

            if (var_fa0 < 0.001f) {
                var_fa0 = 0.001f;
            }
            var_fa0 = 1.0f / var_fa0;
            if (((var_fs2 * var_fa0 * var->unk_5C.x.x) + (var_fs0 * var_fa0 * var->unk_5C.x.z)) < 0.4f) {
                temp_s4->unk_24 = 0;
                temp_s4->unk_28 = 0.0f;
                temp_s4->unk_0C = temp_s4->unk_10 = 0x200;
                for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                    temp_s0 = &D_i7_8014BF94[j];
                    temp_s0->unk_0C = temp_s0->unk_10 = 0x200;
                }
            }
        }

        if (temp_s4->unk_24 >= 2) {
            j = temp_s4->unk_2E;
            if (temp_s4->unk_24 != 3) {
                temp_s0 = &D_i7_8014BF94[j];
                temp_fv0_12 = var->unk_50.x + temp_s4->unk_00;
                temp_fv1_5 = temp_s4->unk_04;
                temp_fa1 = var->unk_50.z + temp_s4->unk_08;
                if (((var->unk_5C.x.x * (temp_fv0_12 - var->unk_50.x)) +
                     ((temp_fv1_5 - var->unk_50.y) * var->unk_5C.x.y) +
                     ((temp_fa1 - var->unk_50.z) * var->unk_5C.x.z)) <= 0.0f) {
                    temp_s4->unk_10 = 0x200;
                    temp_s4->unk_0C = 0x200;
                } else {
                    var_fs2 = var->unk_19C.xw + ((var->unk_19C.xx * temp_fv0_12) + (var->unk_19C.xy * temp_fv1_5) +
                                                 (var->unk_19C.xz * temp_fa1));
                    var_fs1 = var->unk_19C.yw + ((var->unk_19C.yx * temp_fv0_12) + (var->unk_19C.yy * temp_fv1_5) +
                                                 (var->unk_19C.yz * temp_fa1));
                    var_fs0 = var->unk_19C.zw + ((var->unk_19C.zx * temp_fv0_12) + (var->unk_19C.zy * temp_fv1_5) +
                                                 (var->unk_19C.zz * temp_fa1));
                    if (func_i3_fabsf(var_fs0) < 0.001f) {
                        temp_s0->unk_10 = 0x200;
                        temp_s0->unk_0C = 0x200;
                    } else {
                        temp_s4->unk_0C = (s32) (var->unk_F0 + ((var_fs2 * var->unk_E8) / var_fs0));
                        temp_s4->unk_10 = (s32) (var->unk_F4 - ((var_fs1 * var->unk_EC) / var_fs0));

                        if ((temp_s4->unk_0C < var->unk_B0) || (var->unk_B8 < temp_s4->unk_0C) ||
                            (temp_s4->unk_10 < var->unk_B4) || (var->unk_BC < temp_s4->unk_10)) {
                            temp_s4->unk_10 = 0x200;
                            temp_s4->unk_0C = 0x200;
                        }
                    }
                }
            } else {
                for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {

                    temp_s0 = &D_i7_8014BF94[j];
                    temp_fv0_12 = D_800E5220[0].unk_50.x + temp_s0->unk_00;
                    temp_fv1_5 = temp_s0->unk_04;
                    temp_fa1 = D_800E5220[0].unk_50.z + temp_s0->unk_08;
                    if (((var->unk_5C.x.x * (temp_fv0_12 - var->unk_50.x)) +
                         ((temp_fv1_5 - var->unk_50.y) * var->unk_5C.x.y) +
                         ((temp_fa1 - var->unk_50.z) * var->unk_5C.x.z)) <= 0.0f) {
                        temp_s0->unk_10 = 0x200;
                        temp_s0->unk_0C = 0x200;
                    } else {
                        var_fs2 = var->unk_19C.xw + ((var->unk_19C.xx * temp_fv0_12) + (var->unk_19C.xy * temp_fv1_5) +
                                                     (var->unk_19C.xz * temp_fa1));
                        var_fs1 = var->unk_19C.yw + ((var->unk_19C.yx * temp_fv0_12) + (var->unk_19C.yy * temp_fv1_5) +
                                                     (var->unk_19C.yz * temp_fa1));
                        var_fs0 = var->unk_19C.zw + ((var->unk_19C.zx * temp_fv0_12) + (var->unk_19C.zy * temp_fv1_5) +
                                                     (var->unk_19C.zz * temp_fa1));
                        if (func_i3_fabsf(var_fs0) < 0.001f) {
                            temp_s0->unk_10 = 0x200;
                            temp_s0->unk_0C = 0x200;
                        } else {
                            temp_s0->unk_0C = var->unk_F0 + ((var_fs2 * var->unk_E8) / var_fs0);
                            temp_s0->unk_10 = var->unk_F4 - ((var_fs1 * var->unk_EC) / var_fs0);

                            if ((temp_s0->unk_0C < var->unk_B0) || (var->unk_B8 < temp_s0->unk_0C) ||
                                (temp_s0->unk_10 < var->unk_B4) || (var->unk_BC < temp_s0->unk_10)) {
                                temp_s0->unk_10 = 0x200;
                                temp_s0->unk_0C = 0x200;
                            }
                        }
                    }
                }
            }
        }
    }
    D_i7_8014BF92 = 0;
    for (j = 0; j < D_i7_8014BF90; j++) {
        if (D_i7_8014BF98[j].unk_24 != 0) {
            D_i7_8014BF92++;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i7/E9A30/func_i7_80147EBC.s")
#endif

#ifdef NON_EQUIVALENT
// texture rectangle issues
Gfx* func_i7_80149760(Gfx* gfx) {
    s32 i;
    s32 j;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;
    f32 var_fs1;
    s32 temp_t4;
    s32 temp_t6;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fa0;
    s32 l;
    s32 t;
    s32 r;
    s32 b;
    unk_8014BF94* temp_a0;
    unk_8014BF98* temp_s6;
    unk_8014BF98* temp_v0;

    if (D_80106F48 >= 4) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    for (i = 0; i < D_i7_8014BF90; i++) {

        if (D_i7_8014BF98[i + 0].unk_24 < 2) {
            continue;
        }
        var_fs1 = D_i7_8014BF98[i].unk_28 * 0.5f;

        if (var_fs1 > 0.8f) {
            var_fs1 = 0.8f;
        }

        if (var_fs1 < 0.1f) {
            continue;
        }

        func_8006ADE4((i * 0x600) / D_i7_8014BF90, Math_Rand1() % 256, 255, &red, &green, &blue);
        gDPPipeSync(gfx++);
        alpha = (s32) ((var_fs1 / 0.8f) * 255.0f);
        gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
        gDPLoadTextureBlock(gfx++, D_i7_8014AD8C[Math_Rand1() % 3], G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        if (D_i7_8014BF98[i].unk_24 != 3) {
            if (D_i7_8014BF98[i].unk_0C != 0x200) {
                temp_fv0 = D_i7_8014BF98[i].unk_0C;
                temp_fv1 = D_i7_8014BF98[i].unk_10;
                l = (s32) ((temp_fv0 * 4.0f) - (4.0f * var_fs1));
                t = (s32) ((temp_fv1 * 4.0f) - (4.0f * var_fs1));
                r = (s32) (((temp_fv0 + 7.0f) * 4.0f) + (4.0f * var_fs1));
                b = (s32) (((temp_fv1 + 7.0f) * 4.0f) + (4.0f * var_fs1));
                gSPTextureRectangle(gfx++, l, t, r, b, 0, 0, 0, (s32) (1024.0f / var_fs1), (s32) (1024.0f / var_fs1));
            }
        } else {
            for (j = D_i7_8014BF98[i].unk_2E; j < D_i7_8014BF98[i].unk_2E + D_i7_8014BF98[i].unk_30; j++) {
                if ((D_i7_8014BF98[i].unk_2C == 0x20) && !(j & 0x1F)) {
                    temp_t6 = Math_Rand1() % 32;

                    gDPPipeSync(gfx++);
                    gDPSetPrimColor(gfx++, 0, 0, D_i7_8014AD2C[temp_t6][0], D_i7_8014AD2C[temp_t6][1],
                                    D_i7_8014AD2C[temp_t6][2], alpha);
                    // if (!l){}
                    gDPLoadTextureBlock(gfx++, D_i7_8014AD8C[Math_Rand1() % 3], G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0,
                                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                        G_TX_NOLOD, G_TX_NOLOD);
                }

                if (D_i7_8014BF94[j].unk_0C != 0x200) {
                    temp_fv0 = D_i7_8014BF94[j].unk_0C;
                    temp_fv1 = D_i7_8014BF94[j].unk_10;
                    l = (s32) ((temp_fv0 * 4.0f) - (4.0f * var_fs1));
                    t = (s32) ((temp_fv1 * 4.0f) - (4.0f * var_fs1));
                    r = (s32) (((temp_fv0 + 7.0f) * 4.0f) + (4.0f * var_fs1));
                    b = (s32) (((temp_fv1 + 7.0f) * 4.0f) + (4.0f * var_fs1));
                    gSPTextureRectangle(gfx++, l, t, r, b, 0, 0, 0, (s32) (1024.0f / var_fs1),
                                        (s32) (1024.0f / var_fs1));
                }
            }
        }
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);

    return gfx;
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i7/E9A30/func_i7_80149760.s")
#endif
