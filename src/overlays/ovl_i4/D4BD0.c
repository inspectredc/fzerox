#include "global.h"
#include "fzx_racer.h"
#include "tex_assets.h"
#include "assets/segment_17B960.h"

UNUSED s32 D_8011D770;
s32 D_i4_8011D774;
f32 D_i4_8011D778;
f32 D_i4_8011D77C;
s16 D_i4_8011D780[8];
s32 D_i4_8011D790;
s32 D_i4_8011D794;

unk_80077D50 D_i4_8011B980[] = { { 17, D_F033AB4, 180, 245, 0x4AF4 }, { 0 } };
unk_80077D50 D_i4_8011B9A0[] = { { 17, D_F0385AC, 180, 245, 0x6604 }, { 0 } };
unk_80077D50 D_i4_8011B9C0[] = { { 17, D_F03EBB4, 180, 245, 0x5573 }, { 0 } };
unk_80077D50 D_i4_8011B9E0[] = { { 17, D_F04412C, 180, 245, 0x76B4 }, { 0 } };
unk_80077D50 D_i4_8011BA00[] = { { 17, D_F04B7E4, 180, 245, 0x67F2 }, { 0 } };
unk_80077D50 D_i4_8011BA20[] = { { 17, D_F051FDC, 180, 245, 0x63BB }, { 0 } };
unk_80077D50 D_i4_8011BA40[] = { { 17, D_F05839C, 180, 245, 0x5EE9 }, { 0 } };
unk_80077D50 D_i4_8011BA60[] = { { 17, D_F05E28C, 180, 245, 0x7184 }, { 0 } };
unk_80077D50 D_i4_8011BA80[] = { { 17, D_F065414, 180, 245, 0x5666 }, { 0 } };
unk_80077D50 D_i4_8011BAA0[] = { { 17, D_F06AA80, 180, 245, 0x5A49 }, { 0 } };
unk_80077D50 D_i4_8011BAC0[] = { { 17, D_F0704D0, 180, 245, 0x55C1 }, { 0 } };
unk_80077D50 D_i4_8011BAE0[] = { { 17, D_F075A98, 180, 245, 0x594F }, { 0 } };
unk_80077D50 D_i4_8011BB00[] = { { 17, D_F07B3EC, 180, 245, 0x7A7A }, { 0 } };
unk_80077D50 D_i4_8011BB20[] = { { 17, D_F082E6C, 180, 245, 0x6444 }, { 0 } };
unk_80077D50 D_i4_8011BB40[] = { { 17, D_F0892B4, 180, 245, 0x623A }, { 0 } };
unk_80077D50 D_i4_8011BB60[] = { { 17, D_F08F4F4, 180, 245, 0x6F78 }, { 0 } };
unk_80077D50 D_i4_8011BB80[] = { { 17, D_F096470, 180, 245, 0x5C56 }, { 0 } };
unk_80077D50 D_i4_8011BBA0[] = { { 17, D_F09C0CC, 180, 245, 0x59E6 }, { 0 } };
unk_80077D50 D_i4_8011BBC0[] = { { 17, D_F0A1AB8, 180, 245, 0x5B58 }, { 0 } };
unk_80077D50 D_i4_8011BBE0[] = { { 17, D_F0A7614, 180, 245, 0x6B2D }, { 0 } };
unk_80077D50 D_i4_8011BC00[] = { { 17, D_F0AE148, 180, 245, 0x4E48 }, { 0 } };
unk_80077D50 D_i4_8011BC20[] = { { 17, D_F0B2F94, 180, 245, 0x6D92 }, { 0 } };
unk_80077D50 D_i4_8011BC40[] = { { 17, D_F0B9D2C, 180, 245, 0x5AB3 }, { 0 } };
unk_80077D50 D_i4_8011BC60[] = { { 17, D_F0BF7E4, 180, 245, 0x5E3B }, { 0 } };
unk_80077D50 D_i4_8011BC80[] = { { 17, D_F0C5624, 180, 245, 0x6EAC }, { 0 } };
unk_80077D50 D_i4_8011BCA0[] = { { 17, D_F0CC4D4, 180, 245, 0x4D32 }, { 0 } };
unk_80077D50 D_i4_8011BCC0[] = { { 17, D_F0D120C, 180, 245, 0x603A }, { 0 } };
unk_80077D50 D_i4_8011BCE0[] = { { 17, D_F0D724C, 180, 245, 0x60B6 }, { 0 } };
unk_80077D50 D_i4_8011BD00[] = { { 17, D_F0DD308, 180, 245, 0x5534 }, { 0 } };
unk_80077D50 D_i4_8011BD20[] = { { 17, D_F0E2840, 180, 245, 0x5DA7 }, { 0 } };
unk_80077D50 D_i4_8011BD40[] = { { 17, D_F0E85EC, 180, 245, 0x5CB2 }, { 0 } };
unk_80077D50 D_i4_8011BD60[] = { { 17, D_F0EE2A4, 180, 245, 0x6590 }, { 0 } };
unk_80077D50 D_i4_8011BD80[] = { { 17, D_F0F4838, 180, 245, 0x5022 }, { 0 } };
unk_80077D50 D_i4_8011BDA0[] = { { 17, D_F0F9860, 180, 245, 0x58F4 }, { 0 } };

unk_80077D50* D_i4_8011BDC0[] = {
    D_i4_8011B9A0, D_i4_8011B980, D_i4_8011BA20, D_i4_8011B9E0, D_i4_8011B9C0, D_i4_8011BA00, D_i4_8011BA60,
    D_i4_8011BA40, D_i4_8011BA80, D_i4_8011BC20, D_i4_8011BC00, D_i4_8011BB20, D_i4_8011BD00, D_i4_8011BCE0,
    D_i4_8011BAE0, D_i4_8011BD20, D_i4_8011BC40, D_i4_8011BCA0, D_i4_8011BB60, D_i4_8011BB80, D_i4_8011BBC0,
    D_i4_8011BAC0, D_i4_8011BBA0, D_i4_8011BC80, D_i4_8011BB40, D_i4_8011BBE0, D_i4_8011BB00, D_i4_8011BC60,
    D_i4_8011BAA0, D_i4_8011BCC0, D_i4_8011BD40, D_i4_8011BD40, D_i4_8011BD40, D_i4_8011BD60, D_i4_8011BD80,
};

unk_800792D8 D_i4_8011BE4C[] = { { D_i4_8011B980, 60 }, { 0 } };
unk_800792D8 D_i4_8011BE5C[] = { { D_i4_8011B9A0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BE6C[] = { { D_i4_8011B9C0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BE7C[] = { { D_i4_8011B9E0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BE8C[] = { { D_i4_8011BA00, 60 }, { 0 } };
unk_800792D8 D_i4_8011BE9C[] = { { D_i4_8011BA20, 60 }, { 0 } };
unk_800792D8 D_i4_8011BEAC[] = { { D_i4_8011BA40, 60 }, { 0 } };
unk_800792D8 D_i4_8011BEBC[] = { { D_i4_8011BA60, 60 }, { 0 } };
unk_800792D8 D_i4_8011BECC[] = { { D_i4_8011BA80, 60 }, { 0 } };
unk_800792D8 D_i4_8011BEDC[] = { { D_i4_8011BAA0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BEEC[] = { { D_i4_8011BAC0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BEFC[] = { { D_i4_8011BAE0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF0C[] = { { D_i4_8011BB00, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF1C[] = { { D_i4_8011BB20, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF2C[] = { { D_i4_8011BB40, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF3C[] = { { D_i4_8011BB60, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF4C[] = { { D_i4_8011BB80, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF5C[] = { { D_i4_8011BBA0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF6C[] = { { D_i4_8011BBC0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF7C[] = { { D_i4_8011BBE0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF8C[] = { { D_i4_8011BC00, 60 }, { 0 } };
unk_800792D8 D_i4_8011BF9C[] = { { D_i4_8011BC20, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFAC[] = { { D_i4_8011BC40, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFBC[] = { { D_i4_8011BC60, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFCC[] = { { D_i4_8011BC80, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFDC[] = { { D_i4_8011BCA0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFEC[] = { { D_i4_8011BCC0, 60 }, { 0 } };
unk_800792D8 D_i4_8011BFFC[] = { { D_i4_8011BCE0, 60 }, { 0 } };
unk_800792D8 D_i4_8011C00C[] = { { D_i4_8011BD00, 60 }, { 0 } };
unk_800792D8 D_i4_8011C01C[] = { { D_i4_8011BD20, 60 }, { 0 } };
unk_800792D8 D_i4_8011C02C[] = { { D_i4_8011BD40, 60 }, { 0 } };
unk_800792D8 D_i4_8011C03C[] = { { D_i4_8011BD60, 60 }, { 0 } };
unk_800792D8 D_i4_8011C04C[] = { { D_i4_8011BD80, 60 }, { 0 } };

unk_800792D8* D_i4_8011C05C[] = {
    D_i4_8011BE5C, D_i4_8011BE4C, D_i4_8011BE9C, D_i4_8011BE7C, D_i4_8011BE6C, D_i4_8011BE8C, D_i4_8011BEBC,
    D_i4_8011BEAC, D_i4_8011BECC, D_i4_8011BF9C, D_i4_8011BF8C, D_i4_8011BF1C, D_i4_8011C00C, D_i4_8011BFFC,
    D_i4_8011BEFC, D_i4_8011C01C, D_i4_8011BFAC, D_i4_8011BFDC, D_i4_8011BF3C, D_i4_8011BF4C, D_i4_8011BF6C,
    D_i4_8011BEEC, D_i4_8011BF5C, D_i4_8011BFCC, D_i4_8011BF2C, D_i4_8011BF7C, D_i4_8011BF0C, D_i4_8011BFBC,
    D_i4_8011BEDC, D_i4_8011BFEC, D_i4_8011C02C, D_i4_8011C02C, D_i4_8011C02C, D_i4_8011C03C, D_i4_8011C04C,
};

unk_80077D50 D_i4_8011C0E8[] = { { 17, D_F0FF164, 40, 40, 0x77F }, { 0 } };
unk_80077D50 D_i4_8011C108[] = { { 17, D_F0FF8E8, 40, 40, 0x8AF }, { 0 } };
unk_80077D50 D_i4_8011C128[] = { { 17, D_F10019C, 40, 40, 0x875 }, { 0 } };
unk_80077D50 D_i4_8011C148[] = { { 17, D_F100A18, 40, 40, 0x935 }, { 0 } };
unk_80077D50 D_i4_8011C168[] = { { 17, D_F101354, 40, 40, 0x8EB }, { 0 } };
unk_80077D50 D_i4_8011C188[] = { { 17, D_F101C44, 40, 40, 0x908 }, { 0 } };
unk_80077D50 D_i4_8011C1A8[] = { { 17, D_F102550, 40, 40, 0x919 }, { 0 } };
unk_80077D50 D_i4_8011C1C8[] = { { 17, D_F102E70, 40, 40, 0x989 }, { 0 } };
unk_80077D50 D_i4_8011C1E8[] = { { 17, D_F103800, 40, 40, 0x82D }, { 0 } };
unk_80077D50 D_i4_8011C208[] = { { 17, D_F104034, 40, 40, 0x8F8 }, { 0 } };
unk_80077D50 D_i4_8011C228[] = { { 17, D_F104930, 40, 40, 0x908 }, { 0 } };
unk_80077D50 D_i4_8011C248[] = { { 17, D_F10523C, 40, 40, 0x8EE }, { 0 } };
unk_80077D50 D_i4_8011C268[] = { { 17, D_F105B30, 40, 40, 0x9AD }, { 0 } };
unk_80077D50 D_i4_8011C288[] = { { 17, D_F1064E4, 40, 40, 0x923 }, { 0 } };
unk_80077D50 D_i4_8011C2A8[] = { { 17, D_F106E0C, 40, 40, 0x93A }, { 0 } };
unk_80077D50 D_i4_8011C2C8[] = { { 17, D_F10774C, 40, 40, 0x97F }, { 0 } };
unk_80077D50 D_i4_8011C2E8[] = { { 17, D_F1080D0, 40, 40, 0xA3D }, { 0 } };
unk_80077D50 D_i4_8011C308[] = { { 17, D_F108B14, 40, 40, 0x8AB }, { 0 } };
unk_80077D50 D_i4_8011C328[] = { { 17, D_F1093C4, 40, 40, 0x8A0 }, { 0 } };
unk_80077D50 D_i4_8011C348[] = { { 17, D_F109C68, 40, 40, 0x89B }, { 0 } };
unk_80077D50 D_i4_8011C368[] = { { 17, D_F10A508, 40, 40, 0x6D1 }, { 0 } };
unk_80077D50 D_i4_8011C388[] = { { 17, D_F10ABE0, 40, 40, 0x958 }, { 0 } };
unk_80077D50 D_i4_8011C3A8[] = { { 17, D_F10B53C, 40, 40, 0x8D8 }, { 0 } };
unk_80077D50 D_i4_8011C3C8[] = { { 17, D_F10BE18, 40, 40, 0x8E8 }, { 0 } };
unk_80077D50 D_i4_8011C3E8[] = { { 17, D_F10C704, 40, 40, 0xA0A }, { 0 } };
unk_80077D50 D_i4_8011C408[] = { { 17, D_F10D114, 40, 40, 0x797 }, { 0 } };
unk_80077D50 D_i4_8011C428[] = { { 17, D_F10D8B0, 40, 40, 0x896 }, { 0 } };
unk_80077D50 D_i4_8011C448[] = { { 17, D_F10E14C, 40, 40, 0x8BC }, { 0 } };
unk_80077D50 D_i4_8011C468[] = { { 17, D_F10EA0C, 40, 40, 0x879 }, { 0 } };
unk_80077D50 D_i4_8011C488[] = { { 17, D_F10F28C, 40, 40, 0x7AB }, { 0 } };
unk_80077D50 D_i4_8011C4A8[] = { { 17, D_F10FA3C, 40, 40, 0x859 }, { 0 } };
unk_80077D50 D_i4_8011C4C8[] = { { 17, D_F11029C, 40, 40, 0x813 }, { 0 } };
unk_80077D50 D_i4_8011C4E8[] = { { 17, D_F110AB4, 40, 40, 0x859 }, { 0 } };

unk_80077D50* D_i4_8011C508[] = {
    D_i4_8011C108, D_i4_8011C0E8, D_i4_8011C188, D_i4_8011C148, D_i4_8011C128, D_i4_8011C168, D_i4_8011C1C8,
    D_i4_8011C1A8, D_i4_8011C1E8, D_i4_8011C388, D_i4_8011C368, D_i4_8011C288, D_i4_8011C468, D_i4_8011C448,
    D_i4_8011C248, D_i4_8011C488, D_i4_8011C3A8, D_i4_8011C408, D_i4_8011C2C8, D_i4_8011C2E8, D_i4_8011C328,
    D_i4_8011C228, D_i4_8011C308, D_i4_8011C3E8, D_i4_8011C2A8, D_i4_8011C348, D_i4_8011C268, D_i4_8011C3C8,
    D_i4_8011C208, D_i4_8011C428, D_i4_8011C4A8, D_i4_8011C4A8, D_i4_8011C4A8, D_i4_8011C4C8, D_i4_8011C4E8,
};

unk_800792D8 D_i4_8011C594[] = { { D_i4_8011C0E8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5A4[] = { { D_i4_8011C108, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5B4[] = { { D_i4_8011C128, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5C4[] = { { D_i4_8011C148, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5D4[] = { { D_i4_8011C168, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5E4[] = { { D_i4_8011C188, 60 }, { 0 } };
unk_800792D8 D_i4_8011C5F4[] = { { D_i4_8011C1A8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C604[] = { { D_i4_8011C1C8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C614[] = { { D_i4_8011C1E8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C624[] = { { D_i4_8011C208, 60 }, { 0 } };
unk_800792D8 D_i4_8011C634[] = { { D_i4_8011C228, 60 }, { 0 } };
unk_800792D8 D_i4_8011C644[] = { { D_i4_8011C248, 60 }, { 0 } };
unk_800792D8 D_i4_8011C654[] = { { D_i4_8011C268, 60 }, { 0 } };
unk_800792D8 D_i4_8011C664[] = { { D_i4_8011C288, 60 }, { 0 } };
unk_800792D8 D_i4_8011C674[] = { { D_i4_8011C2A8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C684[] = { { D_i4_8011C2C8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C694[] = { { D_i4_8011C2E8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6A4[] = { { D_i4_8011C308, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6B4[] = { { D_i4_8011C328, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6C4[] = { { D_i4_8011C348, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6D4[] = { { D_i4_8011C368, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6E4[] = { { D_i4_8011C388, 60 }, { 0 } };
unk_800792D8 D_i4_8011C6F4[] = { { D_i4_8011C3A8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C704[] = { { D_i4_8011C3C8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C714[] = { { D_i4_8011C3E8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C724[] = { { D_i4_8011C408, 60 }, { 0 } };
unk_800792D8 D_i4_8011C734[] = { { D_i4_8011C428, 60 }, { 0 } };
unk_800792D8 D_i4_8011C744[] = { { D_i4_8011C448, 60 }, { 0 } };
unk_800792D8 D_i4_8011C754[] = { { D_i4_8011C468, 60 }, { 0 } };
unk_800792D8 D_i4_8011C764[] = { { D_i4_8011C488, 60 }, { 0 } };
unk_800792D8 D_i4_8011C774[] = { { D_i4_8011C4A8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C784[] = { { D_i4_8011C4C8, 60 }, { 0 } };
unk_800792D8 D_i4_8011C794[] = { { D_i4_8011C4E8, 60 }, { 0 } };

unk_800792D8* D_i4_8011C7A4[] = {
    D_i4_8011C5A4, D_i4_8011C594, D_i4_8011C5E4, D_i4_8011C5C4, D_i4_8011C5B4, D_i4_8011C5D4,
    D_i4_8011C604, D_i4_8011C5F4, D_i4_8011C614, D_i4_8011C6E4, D_i4_8011C6D4, D_i4_8011C664,
    D_i4_8011C754, D_i4_8011C744, D_i4_8011C644, D_i4_8011C764, D_i4_8011C6F4, D_i4_8011C724,
    D_i4_8011C684, D_i4_8011C694, D_i4_8011C6B4, D_i4_8011C634, D_i4_8011C6A4, D_i4_8011C714,
    D_i4_8011C674, D_i4_8011C6C4, D_i4_8011C654, D_i4_8011C704, D_i4_8011C624, D_i4_8011C734,
    D_i4_8011C774, D_i4_8011C774, D_i4_8011C774, D_i4_8011C784, D_i4_8011C794, D_i4_8011C774,
};

unk_80077D50 D_i4_8011C834[] = { { 18, D_F111314, 80, 40, 0x6B4 }, { 0 } };
unk_80077D50 D_i4_8011C854[] = { { 18, D_F1119CC, 80, 40, 0x653 }, { 0 } };
unk_80077D50 D_i4_8011C874[] = { { 18, D_F112024, 80, 40, 0x4BD }, { 0 } };
unk_80077D50 D_i4_8011C894[] = { { 18, D_F1124E8, 80, 40, 0x770 }, { 0 } };
unk_80077D50 D_i4_8011C8B4[] = { { 18, D_F112C5C, 80, 40, 0x5F4 }, { 0 } };
unk_80077D50 D_i4_8011C8D4[] = { { 18, D_F113254, 80, 40, 0x505 }, { 0 } };
unk_80077D50 D_i4_8011C8F4[] = { { 18, D_F113760, 80, 40, 0x59A }, { 0 } };
unk_80077D50 D_i4_8011C914[] = { { 18, D_F113D00, 80, 40, 0x54E }, { 0 } };
unk_80077D50 D_i4_8011C934[] = { { 18, D_F114254, 80, 40, 0x639 }, { 0 } };
unk_80077D50 D_i4_8011C954[] = { { 18, D_F114894, 80, 40, 0x651 }, { 0 } };
unk_80077D50 D_i4_8011C974[] = { { 18, D_F114EEC, 80, 40, 0x5E1 }, { 0 } };
unk_80077D50 D_i4_8011C994[] = { { 18, D_F1154D4, 80, 40, 0x5A4 }, { 0 } };
unk_80077D50 D_i4_8011C9B4[] = { { 18, D_F115A7C, 80, 40, 0x5E4 }, { 0 } };
unk_80077D50 D_i4_8011C9D4[] = { { 18, D_F116064, 80, 40, 0x5FA }, { 0 } };
unk_80077D50 D_i4_8011C9F4[] = { { 18, D_F116664, 80, 40, 0x734 }, { 0 } };
unk_80077D50 D_i4_8011CA14[] = { { 18, D_F116D9C, 80, 40, 0x626 }, { 0 } };
unk_80077D50 D_i4_8011CA34[] = { { 18, D_F1173C8, 80, 40, 0x5E7 }, { 0 } };
unk_80077D50 D_i4_8011CA54[] = { { 18, D_F1179B4, 80, 40, 0x64D }, { 0 } };
unk_80077D50 D_i4_8011CA74[] = { { 18, D_F11855C, 80, 40, 0x5FF }, { 0 } };
unk_80077D50 D_i4_8011CA94[] = { { 18, D_F118008, 80, 40, 0x54E }, { 0 } };
unk_80077D50 D_i4_8011CAB4[] = { { 18, D_F118B60, 80, 40, 0x6C2 }, { 0 } };
unk_80077D50 D_i4_8011CAD4[] = { { 18, D_F119228, 80, 40, 0x4CB }, { 0 } };
unk_80077D50 D_i4_8011CAF4[] = { { 18, D_F1196F8, 80, 40, 0x5ED }, { 0 } };
unk_80077D50 D_i4_8011CB14[] = { { 18, D_F119CEC, 80, 40, 0x7A4 }, { 0 } };
unk_80077D50 D_i4_8011CB34[] = { { 18, D_F11A494, 80, 40, 0x4E6 }, { 0 } };
unk_80077D50 D_i4_8011CB54[] = { { 18, D_F11A980, 80, 40, 0x465 }, { 0 } };
unk_80077D50 D_i4_8011CB74[] = { { 18, D_F11ADEC, 80, 40, 0x50A }, { 0 } };
unk_80077D50 D_i4_8011CB94[] = { { 18, D_F11B2FC, 80, 40, 0x6BF }, { 0 } };
unk_80077D50 D_i4_8011CBB4[] = { { 18, D_F11CAFC, 80, 40, 0x468 }, { 0 } };
unk_80077D50 D_i4_8011CBD4[] = { { 18, D_F11CF68, 80, 40, 0x454 }, { 0 } };

unk_80077D50* D_i4_8011CBF4[] = {
    D_i4_8011C834, D_i4_8011C854, D_i4_8011C874, D_i4_8011C894, D_i4_8011C8B4, D_i4_8011CBB4, D_i4_8011C8D4,
    D_i4_8011C8F4, D_i4_8011C914, D_i4_8011C934, D_i4_8011C954, D_i4_8011C974, D_i4_8011C994, D_i4_8011C9B4,
    D_i4_8011C9D4, D_i4_8011C9F4, D_i4_8011CA14, D_i4_8011CA34, D_i4_8011CA54, D_i4_8011CA74, D_i4_8011CA94,
    D_i4_8011CAB4, D_i4_8011CAD4, D_i4_8011CAF4, D_i4_8011CB14, D_i4_8011CB34, D_i4_8011CB54, D_i4_8011CB74,
    D_i4_8011CBD4, D_i4_8011CB94, D_i4_8011C834,
};

unk_800792D8 D_i4_8011CC70[] = { { D_i4_8011C834, 60 }, { 0 } };
unk_800792D8 D_i4_8011CC80[] = { { D_i4_8011C854, 60 }, { 0 } };
unk_800792D8 D_i4_8011CC90[] = { { D_i4_8011C874, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCA0[] = { { D_i4_8011C894, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCB0[] = { { D_i4_8011C8B4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCC0[] = { { D_i4_8011CBB4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCD0[] = { { D_i4_8011C8D4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCE0[] = { { D_i4_8011C8F4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CCF0[] = { { D_i4_8011C914, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD00[] = { { D_i4_8011C934, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD10[] = { { D_i4_8011C954, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD20[] = { { D_i4_8011C974, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD30[] = { { D_i4_8011C994, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD40[] = { { D_i4_8011C9B4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD50[] = { { D_i4_8011C9D4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD60[] = { { D_i4_8011C9F4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD70[] = { { D_i4_8011CA14, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD80[] = { { D_i4_8011CA34, 60 }, { 0 } };
unk_800792D8 D_i4_8011CD90[] = { { D_i4_8011CA54, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDA0[] = { { D_i4_8011CA74, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDB0[] = { { D_i4_8011CA94, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDC0[] = { { D_i4_8011CAB4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDD0[] = { { D_i4_8011CAD4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDE0[] = { { D_i4_8011CAF4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CDF0[] = { { D_i4_8011CB14, 60 }, { 0 } };
unk_800792D8 D_i4_8011CE00[] = { { D_i4_8011CB34, 60 }, { 0 } };
unk_800792D8 D_i4_8011CE10[] = { { D_i4_8011CB54, 60 }, { 0 } };
unk_800792D8 D_i4_8011CE20[] = { { D_i4_8011CB74, 60 }, { 0 } };
unk_800792D8 D_i4_8011CE30[] = { { D_i4_8011CBD4, 60 }, { 0 } };
unk_800792D8 D_i4_8011CE40[] = { { D_i4_8011CB94, 60 }, { 0 } };

unk_800792D8* D_i4_8011CE50[] = {
    D_i4_8011CC70, D_i4_8011CC80, D_i4_8011CC90, D_i4_8011CCA0, D_i4_8011CCB0, D_i4_8011CCC0, D_i4_8011CCD0,
    D_i4_8011CCE0, D_i4_8011CCF0, D_i4_8011CD00, D_i4_8011CD10, D_i4_8011CD20, D_i4_8011CD30, D_i4_8011CD40,
    D_i4_8011CD50, D_i4_8011CD60, D_i4_8011CD70, D_i4_8011CD80, D_i4_8011CD90, D_i4_8011CDA0, D_i4_8011CDB0,
    D_i4_8011CDC0, D_i4_8011CDD0, D_i4_8011CDE0, D_i4_8011CDF0, D_i4_8011CE00, D_i4_8011CE10, D_i4_8011CE20,
    D_i4_8011CE30, D_i4_8011CE40, D_i4_8011CC70,
};

unk_80077D50 D_i4_8011CECC[] = { { 4, D_F11D3C8, 160, 24, 0 }, { 0 } };
unk_80077D50 D_i4_8011CEEC[] = { { 17, D_F11B9C0, 40, 40, 0x19E }, { 0 } };
unk_80077D50 D_i4_8011CF0C[] = { { 17, D_F11BB64, 40, 40, 0x19C }, { 0 } };
unk_80077D50 D_i4_8011CF2C[] = { { 17, D_F11BD04, 40, 40, 0x19A }, { 0 } };
unk_80077D50 D_i4_8011CF4C[] = { { 17, D_F11BEA4, 40, 40, 0x19A }, { 0 } };

unk_80077D50* D_i4_8011CF6C[] = {
    D_i4_8011CEEC,
    D_i4_8011CF0C,
    D_i4_8011CF2C,
    D_i4_8011CF4C,
};

unk_80077D50 D_i4_8011CF7C[] = { { 17, D_F11C044, 40, 40, 0x277 }, { 0 } };
unk_80077D50 D_i4_8011CF9C[] = { { 17, D_F11C2C0, 128, 64, 0x837 }, { 0 } };
unk_80077D50 D_i4_8011CFBC[] = { { 17, D_F11DB4C, 128, 64, 0x7E9 }, { 0 } };
unk_80077D50 D_i4_8011CFDC[] = { { 17, D_F11E33C, 128, 64, 0x7E4 }, { 0 } };
unk_80077D50 D_i4_8011CFFC[] = { { 18, D_F11EB24, 80, 40, 0x4C2 }, { 0 } };
unk_80077D50 D_i4_8011D01C[] = { { 18, D_F11EFEC, 80, 40, 0x33E }, { 0 } };
unk_80077D50 D_i4_8011D03C[] = { { 17, D_F11F330, 80, 40, 0x35E }, { 0 } };
unk_80077D50 D_i4_8011D05C[] = { { 17, D_F11F694, 16, 16, 0x066 }, { 0 } };
unk_80077D50 D_i4_8011D07C[] = { { 17, D_F11F804, 16, 16, 0x092 }, { 0 } };
unk_80077D50 D_i4_8011D09C[] = { { 17, D_F11F89C, 16, 16, 0x093 }, { 0 } };
unk_80077D50 D_i4_8011D0BC[] = { { 17, D_F11F934, 16, 16, 0x098 }, { 0 } };
unk_80077D50 D_i4_8011D0DC[] = { { 17, D_F11F9D0, 16, 16, 0x091 }, { 0 } };
unk_80077D50 D_i4_8011D0FC[] = { { 17, D_F11FA68, 16, 16, 0x097 }, { 0 } };
unk_80077D50 D_i4_8011D11C[] = { { 17, D_F11FB04, 16, 16, 0x0A6 }, { 0 } };
unk_80077D50 D_i4_8011D13C[] = { { 17, D_F11FBB0, 16, 16, 0x0A3 }, { 0 } };
unk_80077D50 D_i4_8011D15C[] = { { 17, D_F11FC58, 16, 16, 0x0B4 }, { 0 } };
unk_80077D50 D_i4_8011D17C[] = { { 17, D_F11FD10, 16, 16, 0x09C }, { 0 } };
unk_80077D50 D_i4_8011D19C[] = { { 17, D_F11FDB0, 16, 16, 0x0A2 }, { 0 } };
unk_80077D50 D_i4_8011D1BC[] = { { 17, D_F11FE58, 16, 16, 0x0AA }, { 0 } };
unk_80077D50 D_i4_8011D1DC[] = { { 17, D_F11FF08, 16, 16, 0x0B1 }, { 0 } };
unk_80077D50 D_i4_8011D1FC[] = { { 17, D_F11FFC0, 16, 16, 0x0B6 }, { 0 } };
unk_80077D50 D_i4_8011D21C[] = { { 17, D_F12007C, 16, 16, 0x0A8 }, { 0 } };
unk_80077D50 D_i4_8011D23C[] = { { 17, D_F120128, 16, 16, 0x097 }, { 0 } };
unk_80077D50 D_i4_8011D25C[] = { { 17, D_F1201C4, 16, 16, 0x0CB }, { 0 } };
unk_80077D50 D_i4_8011D27C[] = { { 17, D_F120294, 16, 16, 0x0D4 }, { 0 } };
unk_80077D50 D_i4_8011D29C[] = { { 17, D_F12036C, 16, 16, 0x0DD }, { 0 } };
unk_80077D50 D_i4_8011D2BC[] = { { 17, D_F120450, 16, 16, 0x0C8 }, { 0 } };
unk_80077D50 D_i4_8011D2DC[] = { { 17, D_F12051C, 16, 16, 0x0BF }, { 0 } };
unk_80077D50 D_i4_8011D2FC[] = { { 17, D_F1205E0, 16, 16, 0x059 }, { 0 } };

unk_80077D50* D_i4_8011D31C[] = {
    D_i4_8011D07C, D_i4_8011D09C, D_i4_8011D0BC, D_i4_8011D0DC, D_i4_8011D0FC, D_i4_8011D11C, D_i4_8011D13C,
    D_i4_8011D15C, D_i4_8011D17C, D_i4_8011D19C, D_i4_8011D1BC, D_i4_8011D1DC, D_i4_8011D1FC, D_i4_8011D21C,
    D_i4_8011D23C, D_i4_8011D25C, D_i4_8011D27C, D_i4_8011D29C, D_i4_8011D2BC, D_i4_8011D2DC, D_i4_8011D2FC,
};

unk_80077D50 D_i4_8011D370[] = { { 17, D_F134D64, 64, 18, 0x144 }, { 0 } };
unk_80077D50 D_i4_8011D390[] = { { 17, D_F134EAC, 64, 18, 0x14C }, { 0 } };
unk_80077D50 D_i4_8011D3B0[] = { { 17, D_F134FFC, 64, 18, 0x149 }, { 0 } };
unk_80077D50 D_i4_8011D3D0[] = { { 17, D_F13514C, 64, 18, 0x14E }, { 0 } };

unk_80077D50* D_i4_8011D3F0[] = {
    D_i4_8011D370,
    D_i4_8011D390,
    D_i4_8011D3B0,
    D_i4_8011D3D0,
};

unk_80077D50 D_i4_8011D400[] = { { 17, D_F11F700, 20, 8, 0x5E }, { 0 } };
unk_80077D50 D_i4_8011D420[] = { { 17, D_F11F764, 16, 8, 0x46 }, { 0 } };
unk_80077D50 D_i4_8011D440[] = { { 17, D_F11F7B0, 16, 8, 0x4F }, { 0 } };

unk_80077D50* D_i4_8011D460[] = {
    D_i4_8011D420,
    D_i4_8011D400,
    D_i4_8011D440,
};

unk_80077D50 D_i4_8011D46C[] = { { 17, D_F139710, 32, 16, 0x112 }, { 0 } };

const char* D_i4_8011D48C[] = { "a", "b", "c", "d", "e" };

UNUSED s32 D_i4_8011D4A0[] = { 100, 218, 252, 221 };

s32 D_i4_8011D4B0 = -4;
s32 D_i4_8011D4B4 = 10;
s32 D_i4_8011D4B8 = -6;
s32 D_i4_8011D4BC = 14;

UNUSED s32 D_i4_8011D4C0[] = { 0, 0, 0, 10, 0, 40 };

UNUSED f32 D_i4_8011D4D8 = 1.2f;

s16 D_i4_8011D4DC = 60;

s32 D_i4_8011D4E0 = 2600;

s8 D_i4_8011D4E4[] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

unk_80077D50 D_i4_8011D4F0[] = { { 17, D_F000004, 304, 240, 0x14A5D }, { 0 } };
unk_80077D50 D_i4_8011D510[] = { { 17, D_F014A68, 320, 240, 0x118DB }, { 0 } };
unk_80077D50 D_i4_8011D530[] = { { 17, D_F026348, 320, 240, 0x9E0A }, { 0 } };

unk_80077D50* D_i4_8011D550[] = {
    D_i4_8011D4F0,
    D_i4_8011D510,
    D_i4_8011D530,
};

unk_80077D50 D_i4_8011D55C[] = { { 18, D_F030158, 160, 65, 0x26C0 }, { 0 } };
unk_80077D50 D_i4_8011D57C[] = { { 18, D_F033328, 80, 40, 0x389 }, { 0 } };
unk_80077D50 D_i4_8011D59C[] = { { 20, D_F03281C, 160, 32, 0x259 }, { 0 } };
unk_80077D50 D_i4_8011D5BC[] = { { 20, D_F032A7C, 160, 32, 0x4EA }, { 0 } };
unk_80077D50 D_i4_8011D5DC[] = { { 20, D_F032F6C, 160, 32, 0x3B7 }, { 0 } };

unk_80077D50* D_i4_8011D5FC[] = {
    D_i4_8011D59C,
    D_i4_8011D5BC,
    D_i4_8011D5DC,
};

unk_80077D50 D_i4_8011D608[] = { { 17, D_F0336B8, 128, 14, 0x3EC }, { 0 } };

s32 D_i4_8011D628[] = { 85, 21, 120, 150 };

s32 D_i4_8011D638 = 0;

const s32 D_i4_8011D674[] = { -4, 0, -6, -24, 2, -1, 5, -25 };

const s32 D_i4_8011D694[] = { 19, 60, 19, 136, 299, 60, 299, 136, 42, 10, 42, 120 };

const s32 D_i4_8011D6C4[] = { 25, 20, 25, 125, 164, 20, 164, 125 };

extern s16 D_800CCFE8;
extern s32 D_800CD380;
extern s8 D_800CD3A8[];
extern s32 D_800CD3B0;
extern s8 D_800CD3C8;
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
    if (D_800CD3C8 != 0) {
        D_i4_8011D774 = 0x1E;
    }
    if (D_i4_8011D774 >= 0x1F) {
        D_i4_8011D774 = 0x1E;
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
extern s32 D_800DCE44;
extern s32 D_800F8514;
extern f32 D_800E40F0[];
extern f32 D_800E5EF0[];

void func_i4_801160D8(void) {
    s32 i;

    D_800CCFE8 = 3;
    func_80085610();
    func_8008969C();
    D_800CD3B4 = 0;

    for (i = 0; i < 4; i++) {
        D_800CD3A8[i] = 0;
        if (D_800DCE44 != 0x4012) {
            D_800E5EF0[i] = 0.5f;
        }
    }

    if ((gNumPlayers == 1) && (D_800F8514 < 24)) {
        func_i2_80100C18(D_800F8514);
        D_800E5EF0[0] = D_800E40F0[gRacers[0].character];
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

extern Controller D_800DD180;
extern s32 D_800CD380;
extern s32 D_800CD3B0;
extern s32 D_800DD224;
extern u16 D_800E416C;
extern u16 D_800E416E;
extern s32 D_800DD218[];
extern Controller D_800DCE98[];
extern s8 D_800CD3AC[];

#ifdef NON_MATCHING
// saved register regalloc
s32 func_i4_8011631C(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 pad;
    s16 pad2;
    s16 temp_v0_2;

    func_8008675C();

    for (i = 3; i >= 0; i--) {

        func_8007DABC(&D_800DCE98[D_800DD218[i]]);
        if (i >= gNumPlayers) {
            if ((D_800E416E & BTN_B) && (D_800CD3B0 == 0)) {
                func_800BA8D8(0x10);
                D_800CD3B0 = 1;
                if (D_800CD380 == 2) {
                    return 0x8007;
                }
                return 0x800A;
            }
            continue;
        }
        if (D_800E416E & (BTN_L | BTN_R | BTN_CLEFT | BTN_CDOWN)) {
            if ((D_800DD180.unk_7A & 0x20) && (D_800DD180.unk_7A & 0x10) && (D_800DD180.unk_7A & 2) &&
                (D_800DD180.unk_7A & 4) && (func_80079E88(0x2D)->unk_20 == 0) && (D_800CD3B0 != 3)) {
                func_80079E88(0x2D)->unk_20 = 1;
                D_i4_8011D778 = 1.0f;
                D_i4_8011D77C = 0.0f;
                func_800BA8D8(0x17);
                return D_800DCE44;
            }
        }

        switch (D_800CD3B0) {
            case 0:
                temp_v0_2 = D_i4_8011D780[i];

                if (D_800CD3A8[i] == 0) {
                    if (D_800E416C & 0x200) {
                        if (D_i4_8011D780[i] % 6) {
                            D_i4_8011D780[i]--;
                        } else {
                            D_i4_8011D780[i] += 5;
                        }
                    } else if (D_800E416C & 0x100) {
                        if ((D_i4_8011D780[i] % 6) < 5) {
                            D_i4_8011D780[i]++;
                        } else {
                            D_i4_8011D780[i] -= 5;
                        }
                    }
                    if (D_800E416C & 0x800) {
                        D_i4_8011D780[i] -= 6;
                    } else if (D_800E416C & 0x400) {
                        D_i4_8011D780[i] += 6;
                    }
                }

                D_i4_8011D780[i] += D_i4_8011D774;
                D_i4_8011D780[i] %= D_i4_8011D774;
                gRacers[i].character = func_8007E10C(D_i4_8011D780[i]);

                if (temp_v0_2 != D_i4_8011D780[i]) {
                    func_800BA710(i, 0x1E);
                    D_800CD3AC[i] = 1;
                    D_800E5EF0[i] = 0.5f;
                }

                if (D_800E416E & BTN_B) {
                    func_800BA710(i, 0x10);

                    if (D_800CD3A8[i] != 0) {
                        D_800CD3A8[i] = 0;
                    } else {
                        D_800CD3B0 = 1;
                        if (D_800CD380 == 2) {
                            return 0x8007;
                        }
                        return 0x800A;
                    }
                } else if (D_800E416E & (BTN_A | BTN_START)) {
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
                if (D_800E416E & BTN_B) {
                    D_800CD3A8[i] = 0;
                    D_800CD3B0 = 0;
                    func_800BA710(i, 0x10);
                    break;
                }
                if (D_800E416E & (BTN_A | BTN_START)) {
                    func_800BA710(i, 0x3E);
                    D_800CD3B0 = 3;
                    return 0x4009;
                }
                break;
        }
    }
    return D_800DCE44;
}
#else
s32 func_i4_8011631C(void);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i4/D4BD0/func_i4_8011631C.s")
#endif

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
        return D_800DCE44;
    }

    for (i = gNumPlayers - 1; i >= 0; i--) {
        temp_s1 = &D_800DCE98[D_800DD218[i]];
        func_8007DABC(temp_s1);

        switch (D_800CD3B4) {
            case 0:
                if (D_800CD3A8[i] == 0) {

                    k = gRacers[i].unk_2CC;

                    if (D_800E416E & 0x2000) {
                        gRacers[i].unk_2CC--;
                        gRacers[i].unk_2CC &= 3;
                    }
                    if (D_800E416E & 0x10) {
                        gRacers[i].unk_2CC++;
                        gRacers[i].unk_2CC &= 3;
                    }
                    if (k != gRacers[i].unk_2CC) {
                        func_800BA710(i, 0x1E);
                    }
                    var_v0 = temp_s1->stickX;
                    temp_fa0 = D_800E5EF0[i];
                    temp_fv0 = (f32) var_v0 * 0.003;
                    var_fa1 = SQ(temp_fv0);
                    if (var_fa1 < 0.001) {
                        var_fa1 = 0.0078125f;
                        var_v0 = 0;
                        if (D_800E416C & 0x200) {
                            var_v0 = -1;
                        } else if (!(D_800E416C & 0x100)) {
                            var_fa1 = 0.0f;
                        }
                    }
                    if (var_v0 < 0) {
                        D_800E5EF0[i] -= var_fa1;
                        if (D_800E5EF0[i] < 0.0) {
                            D_800E5EF0[i] = 0.0f;
                        }
                    } else {
                        D_800E5EF0[i] += var_fa1;
                        if (D_800E5EF0[i] > 1.0) {
                            D_800E5EF0[i] = 1.0f;
                        }
                    }
                    if ((s32) (temp_fa0 / 0.1f) != (s32) (D_800E5EF0[i] / 0.1f)) {
                        func_800BA710(i, 0x16);
                    }
                    if (gNumPlayers == 1) {
                        D_800E40F0[gRacers[0].character] = D_800E5EF0[0];
                    }
                }
                if (D_800E416E & 0x4000) {
                    func_800BA710(i, 0x10);

                    if (D_800CD3A8[i] != 0) {
                        D_800CD3A8[i] = 0;
                    } else {
                        D_800CD3B4 = 1;
                        if (D_800DCE44 == 0x4009) {
                            return 0x8008;
                        }
                        return 0x800F;
                    }
                } else if ((D_800E416E & 0x9000) && (D_800CD3A8[i] == 0)) {
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
                if (D_800E416E & 0x4000) {
                    D_800CD3A8[i] = 0;
                    D_800CD3B4 = 0;
                    func_800BA710(i, 0x10);
                } else if (D_800E416E & 0x9000) {
                    func_800BA710(i, 0x3E);
                    func_8007E0CC();
                    D_800CD3B4 = 3;
                    switch (D_800CD380) {
                        case 0:
                            return 1;
                        case 1:
                            return 0xE;
                        case 5:
                            return 2;
                        case 3:
                            return gNumPlayers + 1;
                        case 2:
                            return 0x15;
                    }
                }
            case 1:
            case 3:
            default:
                break;
                break;
        }
    }

    return D_800DCE44;
}

extern unk_800DCE48 D_800DCE48;

Gfx* func_i4_80116DC4(Gfx* gfx) {
    gfx = func_80079BC8(gfx);
    func_800790D4();
    if (D_800DCE44 != D_800DCE48.unk_00) {
        func_80089724();
    }
    return gfx;
}

Gfx* func_i4_80116E10(Gfx* gfx) {
    gfx = func_80079BC8(gfx);
    func_800790D4();
    if (D_800DCE44 != D_800DCE48.unk_00) {
        func_80089724();
    }
    return gfx;
}

s32 func_i4_80116E5C(s32 arg0) {
    return arg0;
}

void func_i4_80116E64(void) {
    func_80077D50(D_i4_8011CECC, 0);
}

void func_i4_80116E8C(unk_800E3A28* arg0) {
    s32 i;

    if (gNumPlayers == 1) {
        func_80077D50(D_i4_8011BDC0[gRacers[0].character], 0);
        return;
    }

    for (i = 0; i < gNumPlayers; i++) {
        func_80077D50(D_i4_8011C508[gRacers[i].character], 0);
    }
}

void func_i4_80116F48(unk_800E3A28* arg0) {
    s32 index = arg0->unk_00 - 60;

    arg0->unk_04 = gRacers[index].character;
    arg0->unk_04 = func_i4_80116E5C(arg0->unk_04);

    if (gNumPlayers == 1) {
        func_80077D50(D_i4_8011BDA0, 0);
        arg0->unk_18 = func_800792D8(D_i4_8011C05C[arg0->unk_04]);
    } else {
        arg0->unk_18 = func_800792D8(D_i4_8011C7A4[arg0->unk_04]);
    }
}

void func_i4_80117008(unk_800E3A28* arg0) {
    arg0->unk_18 = func_800792D8(D_i4_8011C7A4[0]);
}

void func_i4_80117038(unk_800E3A28* arg0) {
    func_80077D50(D_i4_8011CF6C[arg0->unk_00 - 0x28], 0);
}

void func_i4_8011706C(void) {
    func_80077D50(D_i4_8011CF7C, 0);
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
        func_80077D50(D_i4_8011CF9C, 0);
        func_80077D50(D_i4_8011CFBC, 0);
    } else {
        func_80077D50(D_i4_8011CFFC, 0);
        func_80077D50(D_i4_8011D01C, 0);
    }
}

void func_i4_801176BC(void) {
    if (gNumPlayers == 1) {
        func_80077D50(D_i4_8011CFDC, 0);
    } else {
        func_80077D50(D_i4_8011D03C, 0);
    }
}

void func_i4_8011770C(unk_800E3A28* arg0) {
    if (gNumPlayers == 1) {
        arg0->unk_18 = func_800792D8(D_i4_8011CE50[0]);
    }
}

void func_i4_8011774C(void) {
    func_80077D50(D_i4_8011D05C, 0);
}

void func_i4_80117774(unk_800E3A28* arg0) {
    s32 i;

    arg0->unk_18 = func_800768F4(0, 0x258);

    func_i2_80100C60(arg0->unk_18);

    for (i = 0; i < 21; i++) {
        func_80077D50(D_i4_8011D31C[i], 0);
    }

    for (i = 0; i < 4; i++) {
        func_80077D50(D_i4_8011D3F0[i], 0);
    }
}

void func_i4_80117808(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        func_80077D50(D_i4_8011D460[i], 0);
    }
}

void func_i4_80117854(unk_800E3A28* arg0) {
    func_80077D50(D_i4_8011D46C, 0);
    arg0->unk_10 = 50;
}

void func_i4_8011788C(unk_800E3A28* arg0) {
    func_80077D50(D_i4_8011D46C, 0);
    arg0->unk_0C = 50;
}

#define PACK_5551(r, g, b, a) (((((r) << 11) | ((g) << 6)) | ((b) << 1)) | (a))

#ifdef NON_EQUIVALENT
// loop unroll issue
Gfx* func_i4_801178C4(Gfx* gfx) {
    s32 color;
    s32 i;

    gDPSetCycleType(gfx++, G_CYC_FILL);

    for (i = 0; i < 0xE0; i++) {
        color = PACK_5551((i * 10) / 1792, 0 / 1792, (i * 60) / 1792, 1);
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

    return func_80078EA0(gfx, D_i4_8011CECC, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_80117BE0(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    const s32* var_s0;

    if (gNumPlayers == 1) {
        gfx = func_80078EA0(gfx, D_i4_8011BDC0[gRacers[0].character], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_8011D6C4[i * 2];
            gfx =
                func_80078EA0(gfx, D_i4_8011C508[gRacers[i].character], var_s0[0], var_s0[1] + 55, 0, 0, 0, 1.0f, 1.0f);
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
            gfx = func_80078EA0(gfx, D_i4_8011BDA0, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
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

    temp_a3 = &D_800F80C8[gRacers[temp_t2].character].unk_11;
    temp_fp = D_i4_8011D694[temp_t2 * 2 + 0];
    temp_t0 = D_i4_8011D694[temp_t2 * 2 + 1];
    if (temp_t2 < 2) {
        for (i = 0; i < 3; i++) {
            gfx = func_80078EA0(gfx, D_i4_8011D460[i], temp_fp, (temp_t0 - 7) + i * 20, 0, 0, 0, 1.0f, 1.0f);
            temp_s0 = D_i4_8011D48C[temp_a3[i]];
            gfx = func_i2_80106450(gfx, temp_fp + 5, (temp_t0 + 10) + i * 20, temp_s0, 0, 2, 0);
        }
    } else {
        for (i = 0; i < 3; i++) {
            gfx = func_80078EA0(gfx, D_i4_8011D460[i], temp_fp - 0x14, (temp_t0 - 7) + i * 20, 0, 0, 0, 1.0f, 1.0f);
            temp_s0 = D_i4_8011D48C[temp_a3[i]];
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
    return func_80078EA0(gfx, D_i4_8011CF6C[sp3C], D_i4_8011D674[sp3C * 2 + 0] + arg1->unk_0C,
                         D_i4_8011D674[sp3C * 2 + 1] + arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_801181C0(Gfx* gfx, unk_800E3A28* arg1) {
    return func_80078EA0(gfx, D_i4_8011CF6C[arg1->unk_00 - 0x28], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

extern s32 gGameFrameCount;

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

            gfx = func_80078EA0(gfx, D_i4_8011CF7C, arg1->unk_0C, arg1->unk_10, 1, 0, 0, 1.0f, 1.0f);
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

    func_8006B010(&D_800DCCF0->unk_21A88[0], 0, 0, 0, 255, 255, 255, 100, 50, 69);
    func_8006B010(&D_800DCCF0->unk_21A88[1], 0, 0, 0, 100, 70, 70, 100, 50, 69);

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
    return func_80078EA0(gfx, D_i4_8011D46C, arg1->unk_0C + var_v1, arg1->unk_10 + 0xD1, 1, 0, 0, 1.0f, 1.0f);
}

extern const char* D_800CD450[];

Gfx* func_i4_801187C0(Gfx* gfx) {
    s32 i;
    const char* temp_s1;
    const s32* var_s0;

    if (gNumPlayers == 1) {
        temp_s1 = D_800CD450[func_i4_80116E5C(gRacers[0].character)];
        gfx = func_i2_80106450(gfx, 0x122 - func_i2_801062E4(temp_s1, 1, 0), 0x22, temp_s1, 0, 1, 0);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_8011D6C4[i * 2];
            temp_s1 = D_800CD450[func_i4_80116E5C(gRacers[i].character)];
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

        if (D_800DCE98[D_800DD218[i]].unk_7A & 0xF) {
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

    func_8006B010(D_800DCCF0->unk_21A88, 0, 0, 0, 255, 255, 255, 50, 25, 34);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_21A88[0].a, 2);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, (Vp*) arg1->unk_1C + i);
        gSPMatrix(gfx++, &D_1000000.unk_20308[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8009CCBC(gfx, gRacers[i].character, gRacers[i].unk_2CC);
    }

    gSPDisplayList(gfx++, D_90186C8);

    func_8006B07C(&D_800DCCF0->unk_21B28, &D_800E5220[0].unk_15C);
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
        gfx = func_80078EA0(gfx, D_i4_8011CF9C, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
        gfx = func_i2_80106B08(gfx, arg1->unk_0C + 0x66, arg1->unk_10 + 0x17, temp_s4);

        switch (D_800CD3B4) {
            case 0:
            case 1:
                gfx = func_8007DB28(gfx, 0);
                break;
            default:
                gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                break;
        }

        gfx = func_80078EA0(gfx, D_i4_8011CFBC, arg1->unk_0C + 3, arg1->unk_10 + 1, 1, 0, 0, 1.0f, 1.0f);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            temp_s4 = D_800F80C8[gRacers[i].character].unk_14;
            temp_s0 = D_i4_8011D6C4[i * 2 + 0];
            temp_s1 = D_i4_8011D6C4[i * 2 + 1];
            gfx = func_80078EA0(gfx, D_i4_8011CFFC, temp_s0 + 0x2B, temp_s1 + 0xA, 0, 0, 0, 1.0f, 1.0f);
            gfx = func_i2_80106B08(gfx, temp_s0 + 0x6E, temp_s1 + 0x1C, temp_s4);
            if (D_800CD3A8[i] == 0) {
                gfx = func_8007DB28(gfx, 0);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
            }
            gfx = func_80078EA0(gfx, D_i4_8011D01C, temp_s0 + 0x2B, temp_s1 + 0xA, 1, 0, 0, 1.0f, 1.0f);
        }
    }
    return gfx;
}

Gfx* func_i4_80119170(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    s32 j;
    s32 sp74;
    s32 sp70;
    s8* temp;
    s32 pad;

    if (gNumPlayers == 1) {
        gfx = func_80078EA0(gfx, D_i4_8011CFDC, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);

        for (i = 0; i < 3; i++) {
            temp = D_800F80C8[gRacers[0].character].unk_11;
            gfx = func_i2_801069E4(gfx, arg1->unk_0C + 0x69, arg1->unk_10 + i * 23 + 3, temp[i]);
        }
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            sp74 = D_i4_8011D6C4[i * 2 + 0];
            sp70 = D_i4_8011D6C4[i * 2 + 1];

            gfx = func_80078EA0(gfx, D_i4_8011D03C, sp74 + 0x2B, sp70 + 0x39, 0, 0, 0, 1.0f, 1.0f);

            for (j = 0; j < 3; j++) {
                temp = D_800F80C8[gRacers[i].character].unk_11;
                gfx = func_i2_80106450(gfx, sp74 + 0x6B, sp70 + 0x43 + j * 14, D_i4_8011D48C[temp[j]], 0, 2, 0);
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
            temp = D_800F80C8[gRacers[i].character].unk_11;
            temp2 = D_i4_8011D48C[temp[j]];
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
    s32 temp;
    s32 temp2;

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

        gfx = func_80078EA0(gfx, D_i4_8011D05C, (s32) (D_800E5EF0[0] * 128.0f) + 0x98, 0x54, 1, 0, 0, 1.0f, 1.0f);
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

            temp2 = D_i4_8011D6C4[i * 2 + 1] + 0x2E;
            temp = D_i4_8011D6C4[i * 2 + 0] + (s32) (D_800E5EF0[i] * 80.0f) + 0x23;
            gfx = func_80078EA0(gfx, D_i4_8011D05C, temp, temp2, temp_v1, 0, 0, 1.0f, 1.0f);
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
extern s8 D_800CD3C8;

Gfx* func_i4_80119834(Gfx* gfx, unk_800E3A28* arg1) {
    s32 i;
    s32 temp_v0;
    s32 var_t3;
    s32 var_v0;
    s32 pad;
    s32 var_t0;
    s8* var_t1;

    temp_v0 = func_8007E10C(D_i4_8011D780[0]);
    var_t3 = 0;
    switch (D_800CD3B0) {
        case 2:
        case 3:
            break;
        default:
            if (((D_800CD3C0 >= 2) || (D_800CD3C8 != 0)) && (D_800DD180.unk_7A & 8)) {
                var_t3 = 4;
            }
            if (D_800DD180.unk_7A & 1) {
                var_t3 = 3;
            }
            if (D_800DD180.unk_7A & 4) {
                var_t3 = 2;
            }
            if (D_800DD180.unk_7A & 2) {
                var_t3 = 1;
            }
            break;
    }

    if (var_t3 != 0) {
        var_t3--;
    } else {
        var_t3 = gDifficulty - D_800DCE48.unk_10;
    }

    if ((D_800CD3C0 >= 2) || (D_800CD3C8 != 0)) {
        var_t0 = 5;
    } else {
        if (D_800CD3C0 > 0) {
            var_t0 = 4;
        } else {
            var_t0 = 3;
        }
    }

    var_t1 = arg1->unk_18 + var_t3 * 150 + temp_v0 * 5;

    for (i = 0; i < var_t0; i++) {

        // FAKE
        if ((*((i ^ 0) + (0, var_t1))) == 0) {
            var_v0 = 20;
            if (1) {}
        } else {
            var_v0 = (var_t3 * 5) + i;
            if (1) {}
        }

        gfx = func_80078EA0(gfx, D_i4_8011D31C[var_v0], 20, 0x73 + i * 20, 0, 0, 0, 1.0f, 1.0f);
    }
    return func_80078EA0(gfx, D_i4_8011D3F0[var_t3], 30, 0xD1, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_80119A64(Gfx* gfx, unk_800E3A28* arg1) {
    s32 pad[2];
    const char* temp_a0;

    temp_a0 = D_800CD450[func_i4_80116E5C(gRacers[0].character)];

    gfx = func_i2_80106450(gfx, 0xA0 - (func_i2_801062E4(temp_a0, 2, 0) / 2), 0xDA, temp_a0, 0, 2, 0);
    gfx = func_i2_80106C20(gfx, 0xFC, 0xDD, D_800F80C8[func_8007E10C(D_i4_8011D780[0])].unk_14);
    return func_i2_80106450(gfx, 0xFC, 0xDD, "$", 0, 2, 0);
}

Gfx* func_i4_80119B50(Gfx* gfx, unk_800E3A28* arg1) {
    gfx = func_8007DB28(gfx, 0);
    return func_80078EA0(gfx, D_i4_8011D46C, arg1->unk_0C + 0x10B, arg1->unk_10 + 0xD0, 1, 0, 0, 1.0f, 1.0f);
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
        var_a1 = D_800DCE98[D_800DD218[i]].unk_7A & 0xF;
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
    if ((D_800DCE48.unk_00 == 0x4009) && (func_80079E88(0x2D)->unk_20 != 0)) {
        D_800CE748 = 0.075f;
        D_800CE74C = 0.125f;
        D_800CE750 = 0.105f;
    } else {
        D_800CE748 = D_800CE74C = D_800CE750 = 0.1f;
    }
}

void func_i4_8011A860(u16* arg0) {
}

void func_i4_8011A868(u16* arg0) {
    s32 sp1C;
    s32 temp_v1;
    s32 temp_a2;
    s32 temp;

    sp1C = (Math_Rand1() >> 3) % 304;
    temp_v1 = (((Math_Rand1() >> 4) % 240) * 0x130) + sp1C;
    temp = (temp_v1 + 1) % 72960;

    temp_a2 = arg0[temp_v1];
    arg0[temp_v1] = arg0[temp];
    arg0[temp] = temp_a2;

    sp1C = (Math_Rand1() >> 5) % 304;
    temp_v1 = (((Math_Rand1() >> 6) % 240) * 0x130) + sp1C;
    temp = (temp_v1 + 0x130) % 72960;

    temp_a2 = arg0[temp_v1];
    arg0[temp_v1] = arg0[temp];
    arg0[temp] = temp_a2;
}

void func_i4_8011A98C(u16* arg0) {
    u32 sp2C;
    s32 pad;
    u32 var_a0;
    s32 pad2;
    u16* sp1C;

    sp2C = (Math_Rand1() >> 4) % 304;
    var_a0 = (((Math_Rand1() >> 5) % 240) * 0x130) + sp2C;

    // FAKE
    sp1C = &(0, arg0)[var_a0];

    switch ((Math_Rand1() >> 6) % 4) {
        case 0:
            var_a0 = (var_a0 + 1) % 72960;
            break;
        case 1:
            var_a0 = (var_a0 - 1) % 72960;
            break;
        case 2:
            var_a0 = (var_a0 + 0x130) % 72960;
            break;
        case 3:
            var_a0 = (var_a0 - 0x130) % 72960;
            break;
    }

    if (arg0[var_a0] < *sp1C) {
        arg0[var_a0] = *sp1C;
    }
}

void func_i4_8011AAD8(u16* arg0) {
    u32 sp2C;
    s32 pad;
    u32 var_a0;
    s32 pad2;
    u16* sp1C;

    sp2C = (Math_Rand1() >> 5) % 304;
    var_a0 = (((Math_Rand1() >> 6) % 240) * 0x130) + sp2C;

    // FAKE
    sp1C = &(0, arg0)[var_a0];

    switch ((Math_Rand1() >> 7) % 4) {
        case 0:
            var_a0 = (var_a0 + 1) % 72960;
            break;
        case 1:
            var_a0 = (var_a0 - 1) % 72960;
            break;
        case 2:
            var_a0 = (var_a0 + 0x130) % 72960;
            break;
        case 3:
            var_a0 = (var_a0 - 0x130) % 72960;
            break;
    }

    // FAKE
    pad2 = arg0[var_a0];

    if (*sp1C - arg0[var_a0] < 0) {
        arg0[var_a0] = *sp1C;
    }
}

void func_i4_8011AC24(u16* arg0) {
    u32 sp2C;
    s32 pad;
    u32 var_a0;
    s32 pad2;
    u16* sp1C;

    sp2C = (Math_Rand1() >> 6) % 304;
    var_a0 = (((Math_Rand1() >> 7) % 240) * 0x130) + sp2C;

    // FAKE
    sp1C = &(0, arg0)[var_a0];

    switch ((Math_Rand1() >> 8) % 4) {
        case 0:
            var_a0 = (var_a0 + 1) % 72960;
            break;
        case 1:
            var_a0 = (var_a0 - 1) % 72960;
            break;
        case 2:
            var_a0 = (var_a0 + 0x130) % 72960;
            break;
        case 3:
            var_a0 = (var_a0 - 0x130) % 72960;
            break;
    }

    arg0[var_a0] = *sp1C;
}

extern s32 D_800DCCCC;

void func_i4_8011AD60(void) {
    D_800CCFE8 = 3;
    D_i4_8011D638 = 1;
    D_800F8514 = 0;
    D_i4_8011D790 = 0;
    D_i4_8011D794 = 0;
    func_800794B0(5, 0, 0, 1);
    func_800794B0(10, 0, 0, 8);
    func_800794B0(15, 0, 0, 10);
    func_800794B0(17, 0, 0, 12);
    func_800794B0(19, 94, 200, 12);
    if (D_800DCCCC != 0) {
        func_800794B0(20, 0, 0, 12);
    }
}

extern s32 D_800DD228;
extern s16 D_800CD044;

s32 func_i4_8011AE2C(void) {

    if (D_800DD228 == 0) {
        return D_800DCE44;
    }
    func_8007DABC(&D_800DD180);
    Math_Rand1();
    if ((D_800DCCCC != 0) && (func_80079E88(20)->unk_1C != 0) && (func_80079E88(20)->unk_04 == 0)) {
        return D_800DCE44;
    }
    if (D_i4_8011D794 != 0) {
        return D_800DCE44;
    }

    if (D_i4_8011D790 < 0) {
        return D_800DCE44;
    }

    D_i4_8011D790++;
    if (D_i4_8011D790 < 0x50) {
        return D_800DCE44;
    }

    if ((D_800CD044 == 0) && (D_800E416E & 0x9000)) {
        func_800BA8D8(0x3E);
        func_8007E0CC();
        D_i4_8011D790 = -1;
        if ((D_800DCCCC != 0) && (func_80079E88(20)->unk_04 == 1)) {
            func_800BB370();
        }
        return 0x8007;
    } else {
        return 0x8000;
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
    func_80077D50(D_i4_8011D550[arg0->unk_04], 0);
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

    func_80077D50(D_i4_8011D55C, 0);
}

void func_i4_8011B134(void) {
}

void func_i4_8011B13C(unk_800E3A28* arg0) {

    arg0->unk_04 = D_800CD3C4;
    func_80077D50(D_i4_8011D59C, 0);
    if (D_800DD228 != 0) {
        func_80077D50(D_i4_8011D57C, 0);
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
    func_80077D50(D_i4_8011D608, 0);
}

extern s32 D_800CCFC0;

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

    if (D_800CCFC0 == 0) {
        var_v0 = 1;
    } else {
        var_v0 = 2;
    }

    func_80077D50(D_i4_8011D5FC[var_v0], 0);
    if ((D_800CCFC0 != 0) && (func_800758F8() != 1)) {
        arg0->unk_1C++;
        D_i4_8011D794 = 1;
        func_800BB334();
    }
}

void (*D_i4_8011D63C[])(u16*) = {
    func_i4_8011A860, func_i4_8011A860, func_i4_8011A868, func_i4_8011A98C, func_i4_8011AAD8, func_i4_8011AC24,
};

void func_i4_8011B2E0(unk_800E3A28* arg0) {
    void (*var_s2)(u16*);
    s32 i;
    u16* temp_s1;

    if (D_i4_8011D638 == 0) {
        arg0->unk_04++;
        if (arg0->unk_04 > 5) {
            arg0->unk_04 = 1;
        }
        var_s2 = D_i4_8011D63C[arg0->unk_04];
    } else {
        var_s2 = D_i4_8011D63C[D_i4_8011D638];
    }

    temp_s1 = func_800783AC(D_F000004);

    for (i = 1999; i > 0; i--) {
        var_s2(temp_s1);
    }
}

Gfx* func_i4_8011B380(Gfx* gfx, unk_800E3A28* arg1) {
    return func_80078EA0(gfx, D_i4_8011D550[arg1->unk_04], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_8011B3DC(Gfx* gfx, unk_800E3A28* arg1) {
    return gfx;
}

Gfx* func_i4_8011B3E8(Gfx* gfx, unk_800E3A28* arg1) {
    return func_80078EA0(gfx, D_i4_8011D55C, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_8011B438(Gfx* gfx, unk_800E3A28* arg1) {
    return gfx;
}

Gfx* func_i4_8011B444(Gfx* gfx, unk_800E3A28* arg1) {
    s32 var_v1;

    if (D_800DD228 != 0) {
        if ((D_i4_8011D790 < 0x5F) && (D_i4_8011D790 >= 0)) {
            return gfx;
        }
        gfx = func_8007DB28(gfx, 0);
        gfx = func_80078EA0(gfx, D_i4_8011D57C, arg1->unk_0C, arg1->unk_10, 1, 0, 0, 1.0f, 1.0f);
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

        gfx = func_80078EA0(gfx, D_i4_8011D59C, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

Gfx* func_i4_8011B668(Gfx* gfx, unk_800E3A28* arg1) {
    return gfx;
}

Gfx* func_i4_8011B674(Gfx* gfx, unk_800E3A28* arg1) {
    return func_80078EA0(gfx, D_i4_8011D608, arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_8011B6C4(Gfx* gfx, unk_800E3A28* arg1) {
    s32 var_t0;
    s32 var_v1;

    var_t0 = 0;
    if (D_800CCFC0 == 0) {
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
        gfx = func_80078EA0(gfx, D_i4_8011D5FC[var_t0], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

extern s8 D_800CD010;

void func_i4_8011B874(unk_800E3A28* arg0) {

    if ((D_800CCFC0 != 0) && (D_i4_8011D790 != -1) && (D_800CD010 == 0)) {
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
