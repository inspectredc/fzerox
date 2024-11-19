#include "global.h"
#include "fzx_racer.h"
#include "tex_assets.h"

extern Gfx D_5000178[];
extern Gfx D_5001E38[];
extern Gfx D_5002B18[];

extern s16 D_800CCFE8;
extern s32 D_800CD004;
extern s8 D_800CD3C0;
extern s8 D_800DCE5C;
extern s16 D_800E42CC;
extern s32 D_800F8514;
extern unk_800E4268 D_800E4268[1][6];
extern unk_8010B7B0 D_8010B7B0;
extern s32 D_i2_80106F10;
extern s16 D_80106F48;

extern s32 gNumPlayers;
extern s32 gDifficulty;

extern char* D_800E4180[55];
extern unk_800E4268 D_800E4268[1][6];

extern u8 D_303C3F0[];
extern Gfx D_8014940[];

extern FrameBuffer* D_800DCCD0[];
extern GfxPool* D_800DCCF0;
extern s32 D_800DCD04;
extern unk_struct_1DC D_800E5220[];
extern Vtx* D_800E5ECC;
extern Vtx* D_800E5ED0;
extern Vtx* D_800F8520;

extern GfxPool D_1000000;
extern Gfx D_303A810[];

#include "prevent_bss_reordering.h"
#include "ovl_i7.h"

extern unk_8014B480 D_8014B480[2];
extern unk_8014B480* D_i7_8014BDF0;
extern s16 D_i7_8014BDF4;
extern u16 D_i7_8014BDF6;
extern void* D_i7_8014BDF8;
extern void* D_i7_8014BDFC;
extern s16 D_i7_8014BE00;
extern s16 D_i7_8014BE02;
extern s16 D_i7_8014BE04;
extern s32 D_i7_8014BE08;
extern s16 D_i7_8014BE0C;
extern f32 D_i7_8014BE10;
extern s16 D_i7_8014BE14;
extern s16 D_i7_8014BE16;
extern s16 D_i7_8014BE18;
extern s16 D_i7_8014BE1A;
extern s16 D_i7_8014BE1C;
extern s16 D_i7_8014BE1E;
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

void* D_i7_80149E90[][2] = {
    { D_F13AAE4, D_F255FF8 }, { D_F15DEA8, D_F2457C4 }, { D_F1A1758, D_F2461CC }, { D_F16FEEC, D_F246C18 },
    { D_F180754, D_F247590 }, { D_F193DC4, D_F247F40 }, { D_F166A40, D_F248844 }, { D_F146944, D_F2490D0 },
    { D_F19CD38, D_F249A78 }, { D_F16B94C, D_F24A294 }, { D_F1882F0, D_F24AC0C }, { D_F1A9E6C, D_F24B444 },
    { D_F17CDC8, D_F24BD9C }, { D_F18BDDC, D_F24C588 }, { D_F13EC40, D_F24CE20 }, { D_F151B38, D_F24D864 },
    { D_F18FFC0, D_F24E224 }, { D_F179494, D_F24EC48 }, { D_F142BF0, D_F24F4A0 }, { D_F198B8C, D_F24FD5C },
    { D_F184744, D_F2505E8 }, { D_F14A3CC, D_F250D64 }, { D_F1B2DBC, D_F251718 }, { D_F159288, D_F252134 },
    { D_F1AE278, D_F252AF8 }, { D_F1A5D74, D_F2532F0 }, { D_F1619EC, D_F253C68 }, { D_F14E458, D_F254468 },
    { D_F174BF0, D_F254EF0 }, { D_F15538C, D_F25577C }, { D_F1B72F0, NULL },      { D_F1C0524, D_F244F14 },
    { D_F1B9F4C, NULL },      { D_F1BD278, NULL },
};

void* D_i7_80149FA0[] = { D_F243410, D_F243610, D_F243710, D_F243910, D_F243B10,
                          D_F243D10, D_F243F10, D_F244110, D_F244310, D_F244510 };

void* D_i7_80149FC8[] = { D_F244710, D_F244910, D_F244B10, D_F244D10 };

Gfx* D_i7_80149FD8[] = { D_5000178, D_5001E38, D_5002B18 };

f32 D_i7_80149FE4 = 0.3f;
f32 D_i7_80149FE8 = 1.0f;

s16 D_i7_80149FEC[] = { 1, 3, 4, 4, 4, 4, 4, 4, 5, -1 };

char D_i7_8014A000[] = "TOTAL RANKING";

const char* D_i7_8014A010[] = { "JACK CUP", "QUEEN CUP", "KING CUP", "JOKER CUP", "EDIT CUP", "X CUP" };

char D_i7_8014A028[] = "THANKS FOR PLAYING!!";

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

void* D_i7_8014AC08[] = { D_F0385AC, D_F033AB4, D_F051FDC, D_F04412C, D_F03EBB4, D_F04B7E4, D_F05E28C,
                          D_F05839C, D_F065414, D_F0B2F94, D_F0AE148, D_F082E6C, D_F0DD308, D_F0D724C,
                          D_F075A98, D_F0E2840, D_F0B9D2C, D_F0CC4D4, D_F08F4F4, D_F096470, D_F0A1AB8,
                          D_F0704D0, D_F09C0CC, D_F0C5624, D_F0892B4, D_F0A7614, D_F07B3EC, D_F0BF7E4,
                          D_F06AA80, D_F0D120C, D_F0E85EC, D_F0EE2A4, D_F0F4838 };

u8 D_i7_8014AC8C[] = { 1 << 7, 1 << 6, 1 << 5, 1 << 4, 1 << 3, 1 << 2, 1 << 1, 1 << 0 };

void* D_i7_8014AC94[] = { D_F265E80, D_F268A80, D_F266880, D_F267A80, D_F268680, D_F266280, D_F267C80, D_F266080,
                          D_F267880, D_F267080, D_F269680, D_F266480, D_F268080, D_F269280, D_F268C80, D_F266A80,
                          D_F269480, D_F266680, D_F267280, D_F268880, D_F269080, D_F267480, D_F268E80, D_F266E80,
                          D_F269880, D_F268480, D_F266C80, D_F267680, D_F268280, D_F267E80 };

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

s32 func_i7_801439D0(s32 arg0, s16 arg1, s8 arg2) {
    s32 var_v1;

    switch (arg1) {
        case 0:
            if (arg2 >= 2) {
                var_v1 = 30;
            } else {
                switch (arg0) {
                    case 1:
                    case 2:
                        var_v1 = 31;
                        break;
                    case 3:
                        var_v1 = arg1;
                        break;
                }
            }
            break;
        case 3:
            if (arg2 >= 2) {
                var_v1 = 32;
            } else {
                var_v1 = arg1;
            }
            break;
        case 4:
            if (arg2 >= 2) {
                var_v1 = 33;
            } else {
                var_v1 = arg1;
            }
            break;
        default:
            var_v1 = arg1;
            break;
    }
    return var_v1;
}

void func_i7_80147CC0(void);
void func_i7_801467FC(void);

void func_i7_80143A90(void) {
    unk_8014BE28* var_v1;
    s32 sp38;
    s32 pad;
    Racer* player = &gRacers[0];
    s32 i;
    s32 j;
    void** temp_v0;
    s32 var_a0;

    D_800CCFE8 = D_i2_80106F10 = 3;
    D_800DCE5C = 0;
    gNumPlayers = 1;
    sp38 = (D_800F8514 / 6) * 6;
    D_800F8514 = 0x37;
    D_i7_8014BE1A = gDifficulty;
    gDifficulty = MASTER;
    D_i7_8014BDF4 = 0;

    for (j = 0; j < 6; j++) {
        D_i7_8014BDF4 += D_800E4268[0][j].unk_0C;
    }

    func_800A4EAC();
    func_i3_80116C4C();
    func_8008C7C8();
    func_80085610();
    func_8007F4E0(D_8010B7B0.unk_000[2], D_8010B7B0.unk_000[3]);
    func_i3_801365E0();
    func_i2_801044F0();
    func_8006D448();
    func_8006E478();
    func_8006EC7C();
    func_80071260(0);
    func_i7_80147CC0();
    func_i7_801467FC();
    D_i7_8014BE00 = 0;
    D_i7_8014BE02 = 0;
    D_i7_8014BE04 = 0;
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
        switch (D_i7_8014BE1A) {
            case 2:
            case 3:
                if (D_800CD004 == 3 && D_80106F48 == 1) {
                    D_i7_8014BDF6 |= 0x10;
                }
                break;
        }
    }

    if (D_80106F48 == 1) {
        switch (D_i7_8014BE1A) {
            case 1:
            case 2:
            case 3:
                D_i7_8014BDF6 |= 0x20;
                break;
        }
    }

    D_i7_8014BE10 = 0.0f;
    D_i7_8014BE14 = 0;
    D_i7_8014BE08 = 0;
    D_i7_8014BE0C = 0;

    switch (D_800CD004) {
        case 0:
            D_i7_8014BE16 = 0;
            break;
        case 1:
            D_i7_8014BE16 = 1;
            break;
        case 2:
            D_i7_8014BE16 = 2;
            break;
        case 3:
            D_i7_8014BE16 = 3;
            break;
        case 4:
            D_i7_8014BE16 = 5;
            break;
        case 5:
            D_i7_8014BE16 = 4;
            break;
    }
    D_i7_8014BE18 = func_i2_801062E4(D_i7_8014A010[D_i7_8014BE16], 3, 1);
    D_i7_8014BE1C = 0;
    D_i7_8014BE1E = 0;
    D_i7_8014BF28 = 0;
    var_a0 = 0;

    var_v1 = D_i7_8014BE28;
    for (i = 0; D_i7_80149FEC[i] != -1; i++) {
        var_v1->unk_04 = 0;
        var_v1->unk_00 = D_i7_80149FEC[i];
        switch (var_v1->unk_00) {
            case 1:
                var_v1->unk_02 = 0;
                var_v1->unk_08 = 28.0f;
                var_v1->unk_0C = 104.0f;
                var_v1->unk_06 = 0x1F;
                break;
            case 2:
                var_v1->unk_02 = 0;
                var_v1->unk_08 = 76.0f;
                var_v1->unk_06 = 0xCB;
                var_v1->unk_0C = 62.0f;
                break;
            case 3:
                var_v1->unk_02 = 0;
                var_v1->unk_08 = 0.0f;
                var_v1->unk_06 = 0x34;
                var_v1->unk_0C = 236.0f;
                break;
            case 5:
                var_v1->unk_02 = 0;
                var_v1->unk_08 = 0.0f;
                var_v1->unk_0C = 100.0f;
                var_v1->unk_06 = 0x10A;
                break;
            case 4:
                var_v1->unk_02 = (s16) (sp38 + var_a0);
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
    func_80078104(D_F256900, 0x3FF0, 0, 0, 0);
    func_80078104(D_F243410, 0x200, 0, 0, 0);
    func_80078104(D_F243610, 0x100, 0, 0, 0);
    func_80078104(D_F243710, 0x200, 0, 0, 0);
    func_80078104(D_F243910, 0x200, 0, 0, 0);
    func_80078104(D_F243B10, 0x200, 0, 0, 0);
    func_80078104(D_F243D10, 0x200, 0, 0, 0);
    func_80078104(D_F243F10, 0x200, 0, 0, 0);
    func_80078104(D_F244110, 0x200, 0, 0, 0);
    func_80078104(D_F244310, 0x200, 0, 0, 0);
    func_80078104(D_F244510, 0x200, 0, 0, 0);
    func_80078104(D_F244710, 0x200, 0, 0, 0);
    func_80078104(D_F244910, 0x200, 0, 0, 0);
    func_80078104(D_F244B10, 0x200, 0, 0, 0);
    func_80078104(D_F244D10, 0x200, 0, 0, 0);

    if (D_i7_8014BDF6 & 0x20) {

        temp_v0 = D_i7_80149E90[func_i7_801439D0(D_i7_8014BE1A, player->character, player->unk_167)];

        D_i7_8014BDF8 = func_80078104(temp_v0[0], 0x81F0, 0, 1, 0);

        if (temp_v0[1] != NULL) {
            D_i7_8014BDFC = func_80078104(temp_v0[1], 0x3100, 0, 1, 0);
        } else {
            D_i7_8014BDFC = NULL;
        }
    }
}

s32 func_i7_801442A0(void);
void func_i7_80145FFC(void);
void func_i7_8014612C(void);
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
        func_i7_80145FFC();
    }
    if (D_i7_8014BE00 != 0) {
        func_i7_8014612C();
    }
    func_i7_80146920();

    switch (func_i7_801442A0()) {
        case 1:
            return 0x8007;
        case 2:
            return 0x800C;
        case 0:
        default:
            return 0x11;
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
                D_i7_8014BE14 = 0xFF;
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
                    D_i7_8014BE00 = 1;
                } else {
                    D_i7_8014BE08 = 6;
                }
                D_i7_8014BE0C = 0;
            }
            break;
        case 5:
            if (D_i7_8014BE00 == 0) {
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

Gfx* func_i7_80144EF4(Gfx*, unk_8014BE28*, f32);
Gfx* func_i7_801454B4(Gfx*, unk_8014BE28*, f32);
Gfx* func_i7_80145D28(Gfx*, unk_8014BE28*, f32);
Gfx* func_i7_80146020(Gfx*);
Gfx* func_i7_80146250(Gfx*);

Gfx* func_i7_80144B2C(Gfx* gfx) {
    unk_8014BE28* var_s1;
    f32 var_fs0;
    s32 i;

    var_fs0 = D_i7_8014BE10;

    var_s1 = D_i7_8014BE28;
    for (i = 0; i < D_i7_8014BE20; i++, var_s1++) {
        var_fs0 += var_s1->unk_0C;
        if ((var_s1->unk_00 == 0) || (var_s1->unk_04 == 0) || var_fs0 > 232.0f) {
            continue;
        }

        if ((var_s1->unk_06 + var_fs0) < 8.0f) {
            var_s1->unk_00 = 0;
            continue;
        }
        switch (var_s1->unk_00) {
            case 1:
                if (D_i7_8014BDF6 & 4) {
                    gDPPipeSync(gfx++);
                    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i7_8014BE14);

                    gfx = func_8007B14C(gfx, func_800783AC(D_F256900), var_s1->unk_08, var_fs0, 0x108, 0x1F,
                                        G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
                }
                break;
            case 2:
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i7_8014BE14);

                gfx = func_8007B14C(gfx, D_i7_8014BDF8, var_s1->unk_08, var_fs0, 0xA8, 0x63, G_IM_FMT_RGBA,
                                    G_IM_SIZ_16b, 1, 1, 0, 0);

                if (D_i7_8014BDFC != NULL) {
                    gfx = func_8007B14C(gfx, D_i7_8014BDFC, var_s1->unk_08 + -14.0f, var_fs0 + 99.0f + 10.0f, 0xC4,
                                        0x20, 0, 2, 1, 1, 0, 0);
                }
                break;
            case 3:
                gfx = func_i7_80145D28(gfx, var_s1, var_fs0);
                break;
            case 4:
                gfx = func_i7_80144EF4(gfx, var_s1, var_fs0);
                break;
            case 5:
                gfx = func_i7_801454B4(gfx, var_s1, var_fs0);
                break;
        }
    }

    if (D_i7_8014BE1C != 0) {
        gfx = func_i7_80146020(gfx);
    }
    if (D_i7_8014BE00 != 0) {
        gfx = func_i7_80146250(gfx);
    }
    return gfx;
}

Gfx* func_i7_80145244(Gfx*, s32, s32, s32, bool);
Gfx* func_i7_80146344(Gfx*, s32, s32, s32);

Gfx* func_i7_80144EF4(Gfx* gfx, unk_8014BE28* arg1, f32 arg2) {
    s32 sp9C;
    f32 var_fv0;
    bool var_v0;
    s32 pad[2];
    unk_800E4268* temp_s2;
    const char* temp_s1;

    sp9C = arg1->unk_02 % 6;
    temp_s2 = &D_800E4268[0][sp9C];
    temp_s1 = D_800E4180[arg1->unk_02];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    var_fv0 = 160.0f;

    gfx = func_i2_80106450(gfx, (var_fv0 + 2.0f) - (func_i2_801062E4(temp_s1, 3, 1) / 2), (arg2 + 16.0f) + 2.0f,
                           temp_s1, 1, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    gfx = func_i2_80106450(gfx, var_fv0 - (func_i2_801062E4(temp_s1, 3, 1) / 2), (arg2 + 16.0f), temp_s1, 1, 3, 0);
    gSPDisplayList(gfx++, D_8014940);

    if (temp_s2->unk_08 == 1) {
        var_v0 = true;
    } else {
        var_v0 = false;
    }

    gfx = func_i7_80145244(gfx, 50, arg2 + 26.0f, temp_s2->unk_08, var_v0);
    gDPPipeSync(gfx++);
    if (0) {}
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    if (0) {}
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gfx = func_i3_8012F554(gfx, temp_s2->unk_00, 0x6E, (arg2 + 28.0f), 1.0f);
    gDPPipeSync(gfx++);
    gfx = func_i3_8013B348(gfx, 0xC2, (arg2 + 28.0f), temp_s2->unk_04, false, false);
    gDPPipeSync(gfx++);
    return func_i7_80146344(gfx, 0x6E, (arg2 + 48.0f), temp_s2->unk_0C);
}

Gfx* func_i7_80145244(Gfx* gfx, s32 xPos, s32 yPos, s32 arg3, bool arg4) {
    s32 i;
    s32 xOffset;
    s32 width;
    s32 sp80;
    s32 sp78[2];
    s32 var_t0;
    s32 temp_v0;

    var_t0 = arg3;

    if ((arg3 == 1) || (arg3 == 0x15)) {
        sp80 = 0;
    } else if ((arg3 == 2) || (arg3 == 0x16)) {
        sp80 = 1;
    } else if ((arg3 == 3) || (arg3 == 0x17)) {
        sp80 = 2;
    } else {
        sp80 = 3;
    }

    for (i = 0; i < 2; i++) {
        sp78[i] = var_t0 % 10;
        var_t0 /= 10;
    }

    gDPPipeSync(gfx++);

    if (arg4) {
        gfx = func_8007DB28(gfx, 0);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 255, 255);
    }

    for (i = 0; i < 2; i++) {
        temp_v0 = sp78[1 - i];
        if ((i == 0) && (temp_v0 == 0)) {
            xPos += 16;
            continue;
        }

        if (temp_v0 != 1) {
            xOffset = 0;
            width = 16;
        } else {
            xOffset = 8;
            width = 8;
        }
        gfx = func_8007B14C(gfx, func_800783AC(D_i7_80149FA0[temp_v0]), xPos + xOffset, yPos, width, 16, G_IM_FMT_RGBA,
                            G_IM_SIZ_16b, 1, 0, 0, 0);
        xPos += 16;
    }

    return func_8007B14C(gfx, func_800783AC(D_i7_80149FC8[sp80]), xPos, yPos, 16, 16, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0,
                         0, 0);
}

extern u16 D_4013DE0[];
extern u8 D_4019020[];

Gfx* func_i7_801454B4(Gfx* gfx, unk_8014BE28* arg1, f32 arg2) {
    s32 i;
    f32 temp_fa1;
    f32 var_fv0;
    s32 spDC[2];
    s32 spD8;
    s32 var_a1;
    s32 temp_a2;
    s8 spCC[4];

    var_a1 = D_80106F48;
    if ((var_a1 == 1) || (var_a1 == 0x15)) {
        spD8 = 0;
    } else if ((var_a1 == 2) || (var_a1 == 0x16)) {
        spD8 = 1;
    } else if ((var_a1 == 3) || (var_a1 == 0x17)) {
        spD8 = 2;
    } else {
        spD8 = 3;
    }

    for (i = 0; i < 2; i++) {
        spDC[i] = var_a1 % 10;
        var_a1 /= 10;
    }

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    var_fv0 = 160.0f;
    temp_fa1 = arg2 + 16.0f;

    gfx = func_i2_80106450(gfx, (var_fv0 + 2.0f) - (func_i2_801062E4(D_i7_8014A000, 3, 1) / 2), temp_fa1 + 2.0f,
                           D_i7_8014A000, 1, 3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 250, 0, 255);
    gfx =
        func_i2_80106450(gfx, var_fv0 - (func_i2_801062E4(D_i7_8014A000, 3, 1) / 2), temp_fa1, D_i7_8014A000, 1, 3, 0);
    temp_fa1 += 10.0f;
    var_fv0 = 122.0f;
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    for (i = 0; i < 2; i++) {
        temp_a2 = spDC[1 - i];
        if ((i == 0) && (temp_a2 == 0)) {
            var_fv0 += 28.0f;
            continue;
        }

        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_4013DE0 + (temp_a2 * 0x380), G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, (s32) (var_fv0) << 2, (s32) (temp_fa1) << 2, (s32) (var_fv0 + 28.0f) << 2,
                                (s32) (temp_fa1 + 32.0f) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        var_fv0 += 28.0f;
    }

    gDPLoadTextureBlock(gfx++, (D_4019020 + (spD8 * 0x320)), G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPScisTextureRectangle(gfx++, (s32) (var_fv0) << 2, (s32) ((temp_fa1 + 12.0f)) << 2, (s32) (var_fv0 + 20.0f) << 2,
                            (s32) ((temp_fa1 + 12.0f) + 20.0f) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gfx = func_i7_80146344(gfx, 0x6E, arg2 + 70.0f, D_i7_8014BDF4);

    if (D_i7_8014BDF4 > 0) {

        for (i = 0; i < 4; i++) {
            spCC[i] = 0;
        }

        sprintf(spCC, "%d", D_i7_8014BDF4);

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        i = D_i7_8014BDF4 / 10;
        if (D_i7_8014BDF4 % 10) {
            i++;
        }
        gfx = func_i2_80106450(gfx, 0x6E, (arg2 + 70.0f) + 20.0f + (i * 10), spCC, 1, 3, 0);
    }
    return gfx;
}

extern const char* sDifficultyNames[];

Gfx* func_i7_80145D28(Gfx* gfx, unk_8014BE28* arg1, f32 arg2) {
    s32 pad;
    f32 var_fv0;
    f32 temp_fa1;
    const char* temp_s1;

    temp_s1 = D_i7_8014A010[D_i7_8014BE16];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    var_fv0 = 160.0f;
    temp_fa1 = arg2 + 16.0f;

    gfx = func_i2_80106450(gfx, (var_fv0 + 2.0f) - (func_i2_801062E4(temp_s1, 3, 1) / 2), temp_fa1 + 2.0f, temp_s1, 1,
                           3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_i2_80106450(gfx, var_fv0 - (func_i2_801062E4(temp_s1, 3, 1) / 2), temp_fa1, temp_s1, 1, 3, 0);

    temp_fa1 += 20.0f;
    temp_s1 = sDifficultyNames[D_i7_8014BE1A];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gfx = func_i2_80106450(gfx, (var_fv0 + 2.0f) - (func_i2_801062E4(temp_s1, 3, 1) / 2), temp_fa1 + 2.0f, temp_s1, 1,
                           3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    return func_i2_80106450(gfx, var_fv0 - (func_i2_801062E4(temp_s1, 3, 1) / 2), temp_fa1, temp_s1, 1, 3, 0);
}

void func_i7_80145FFC(void) {
    if (D_i7_8014BE1E < 120) {
        D_i7_8014BE1E++;
    }
}

#ifdef IMPORT_BSS
Gfx* func_i7_80146020(Gfx* gfx) {
    static s32 D_i7_8014BDE0;
    static s32 D_i7_8014BDE4;
    static s32 D_i7_8014BDE8;
    static s32 D_i7_8014BDEC;

    D_i7_8014BDEC = (D_i7_8014BE1E * 255) / 120;

    gfx = func_8007A440(gfx, 12, 8, 308, 232, 0, 0, 0, D_i7_8014BDEC);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i7_8014BDEC);

    D_i7_8014BDE8 = func_i2_801062E4(D_i7_8014A028, 1, 1);
    D_i7_8014BDE0 = (320 - D_i7_8014BDE8) / 2;
    D_i7_8014BDE4 = 120;

    return func_i2_80106450(gfx, D_i7_8014BDE0, 120, D_i7_8014A028, 1, 1, 1);
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i7/E9A30/func_i7_80146020.s")
#endif

void func_i7_8014612C(void) {
    switch (D_i7_8014BE00) {
        case 1:
            D_i7_8014BE02++;
            D_i7_8014BE04 = (D_i7_8014BE02 * 255) / 120;
            if (D_i7_8014BE02 >= 120) {
                D_i7_8014BE00 = 2;
                D_i7_8014BE02 = 0;
                D_i7_8014BE04 = 255;
            }
            return;
        case 2:
            D_i7_8014BE02++;
            if (D_i7_8014BE02 >= 180) {
                D_i7_8014BE00 = 3;
                D_i7_8014BE02 = 0;
            }
            break;
        case 3:
            D_i7_8014BE02++;
            D_i7_8014BE04 = 255 - (D_i7_8014BE02 * 255) / 120;
            if (D_i7_8014BE02 >= 120) {
                D_i7_8014BE00 = 0;
                D_i7_8014BE02 = 0;
                D_i7_8014BE04 = 0;
            }
            break;
    }
}

Gfx* func_i7_80146250(Gfx* gfx) {

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i7_8014BE04);

    gfx = func_8007B14C(gfx, D_i7_8014BDF8, 76, 62, 168, 99, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
    if (D_i7_8014BDFC != NULL) {
        gfx = func_8007B14C(gfx, D_i7_8014BDFC, 62, 171, 196, 32, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
    }
    return gfx;
}

extern u16 D_401A9A0[];

Gfx* func_i7_80146344(Gfx* gfx, s32 left, s32 top, s32 arg3) {
    s32 i;
    s32 j;
    s32 temp;
    s32 pad;
    s32 numBlocks;
    s32 remainder;

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gfx++, D_401A9A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    numBlocks = arg3 / 10;
    remainder = arg3 % 10;

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
    if ((D_i7_8014BE1A > 0) && (D_80106F48 < 4)) {
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
            if ((character == 0) && (gRacers[i].unk_167 >= 2)) {
                j = 0x1E;
            } else if ((character == 3) && (gRacers[i].unk_167 >= 2)) {
                j = 0x1F;
            } else if ((character == 4) && (gRacers[i].unk_167 >= 2)) {
                j = 0x20;
            }
            D_i7_8014C034 = func_80078104(D_i7_8014AC08[j], 0x15888, 0, 1, 1);

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

extern Gfx D_400A258[];

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
            if (D_800CD004 == 4) {
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
                temp_s4->unk_34 = Math_Rand1() % (128 - (D_i7_8014BE1A * 32));
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
                    if (func_i3_80115DF0(var_fs0) < 0.001f) {
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
                        if (func_i3_80115DF0(var_fs0) < 0.001f) {
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
