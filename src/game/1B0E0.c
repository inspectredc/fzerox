#include "global.h"
#include "audio.h"
#include "fzx_racer.h"
#include "fzx_game.h"
#include "fzx_course.h"
#include "fzx_save.h"
#include "unk_gfx.h"
#include "assets/segment_16C8A0.h"
#include "assets/segment_17B960.h"
#include "assets/segment_1B8550.h"
#include "assets/segment_1E23F0.h"
#include "assets/segment_22B0A0.h"

typedef struct unk_800F5EA0 {
    Racer* unk_00;
    Racer* unk_04;
    f32 unk_08;
    f32 unk_0C;
    s32 unk_10;
} unk_800F5EA0; // size = 0x14

unk_struct_1DC D_800E5220[4];
unk_struct_F8 D_800E5990[4];
unk_800E5D70 D_800E5D70[4];
unk_struct_20_2 D_800E5E00[4];
s32 D_800E5E80;
s32 D_800E5E84;
s16 D_800E5E88;
s16 D_800E5E8A;
s16 D_800E5E8C;
Vec3f D_800E5E90[4];
s32 D_800E5EC0;
Racer* D_800E5EC4;
Racer* D_800E5EC8;
Vtx* D_800E5ECC;
Vtx* D_800E5ED0;
s16 gPlayerLives[4];
s16 D_800E5EE0[4];
s16 D_800E5EE8[4];
f32 gPlayerEngine[4];
s32 D_800E5F00[4];
s32 D_800E5F10[4];
s32 D_800E5F20[4];
s32 D_800E5F30[4];
Racer* D_800E5F40[30];
s32 D_800E5FB8;
s16 D_800E5FBC;
s16 D_800E5FBE;
s16 D_800E5FC0;
s16 D_800E5FC2;
s16 D_800E5FC4;
s16 D_800E5FC6;
s16 D_800E5FC8;
s16 D_800E5FCA;
s16 D_800E5FCC;
s16 D_800E5FCE;
s16 D_800E5FD0;
s16 gRacersKOd;
s16 D_800E5FD4;
s16 D_800E5FD6;
s32 D_800E5FD8;
s32 D_800E5FDC;
s16 D_800E5FE0;
s16 D_800E5FE2;
s16 D_800E5FE4;
s16 D_800E5FE6;
Vec3s* D_800E5FE8;
Vec3s* D_800E5FEC;
s32 D_800E5FF0;
Ghost gGhosts[3];
Ghost* gFastestGhost;
s8 sGhostReplayRecordingBuffer[16200];
s32 sGhostReplayRecordingSize;
s32 sGhostReplayRecordingEnd;
s32 D_800F5DD0;
s8* sGhostReplayRecordingPtr;
s32 D_800F5DD8;
s32 D_800F5DDC;
s32 D_800F5DE0;
s16 D_800F5DE4;
s16 D_800F5DE6;
s16 D_800F5DE8;
s16 D_800F5DEA;
GhostRacer gGhostRacers[3];
s32 D_800F5E8C;
GhostRacer* gFastestGhostRacer;
UNUSED s32 D_800F5E94;
s32 D_800F5E98;
unk_800F5EA0 D_800F5EA0[TOTAL_RACER_COUNT * (TOTAL_RACER_COUNT - 1) / 2];
f32 D_800F809C;
f32 D_800F80A0;
f32 D_800F80A4;
s32 D_800F80A8[4];
s32 D_800F80B8;
f32 D_800F80BC;
f32 D_800F80C0;
s16 D_800F80C4;
unk_800CF1B0 D_800F80C8[30];
u8 D_800F8360[30][14];
u8 D_800F8504[7];

const unk_redo_1 D_800D4C80 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
};

const unk_redo_2 D_800D4CF8 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f },
};

UNUSED const unk_8008112C_arg_1 D_800D4DA4 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   0.0f,
      0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   1.0f,
      0.0f, 120.0f, 120.0f, 1.0f, 35.0f, 35.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 300.0f, 0.0f },
};

const unk_redo_3 D_800D4E98 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
};

const unk_redo_2 D_800D4F58 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  1.0f,  0.0f, 1.0f,  0.0f,  1.0f, 0.0f,
      0.0f, 400.0f, 400.0f, 1.0f, 40.0f, 40.0f, 1.0f, 50.0f, 50.0f, 1.0f },
};

const unk_redo_2 D_800D5004 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,    0.0f,    0.0f, 0.0f,  1.0f,  0.0f, 1.0f,  0.0f,  1.0f, 0.0f,
      0.0f, 1500.0f, 1500.0f, 1.0f, 35.0f, 35.0f, 1.0f, 50.0f, 50.0f, 1.0f },
};

const unk_redo_2 D_800D50B0 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,     0.0f,     0.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 10500.0f, 10500.0f, 1.0f, 20.0f, 20.0f, 1.0f, 0.0f, 0.0f, 1.0f },
};

const unk_redo_1 D_800D515C = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 4000.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 0.0f, 30.0f, 30.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};

UNUSED const unk_redo_1 D_800D51D4 = {
    { 0.0f, 50.0f, 0.0f,  0.0f,  150.0f, 500.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 0.0f,  75.0f, 75.0f, 0.0f,   0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};

const unk_redo_2 D_800D524C = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
      0.0f, 1.0f, 75.0f, 75.0f, 1.0f, 0.0f, 77.0f, 0.0f, 77.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,    0.0f,    0.0f, 0.0f,  1.0f,  0.0f, 1.0f,   0.0f,   1.0f, 0.0f,
      0.0f, 1000.0f, 1000.0f, 1.0f, 35.0f, 35.0f, 1.0f, 180.0f, 180.0f, 1.0f },
};

const Vec3f D_800D52F8[] = {
    { 80.0f, 400.0f, 50.0f },
    { 75.0f, 90.0f, 25.0f },
    { 75.0f, 120.0f, 35.0f },
    { 100.0f, 120.0f, 50.0f },
};

const Vec3f D_800D5328[] = {
    { 100.0f, 400.0f, 50.0f },
    { 90.0f, 100.0f, 25.0f },
    { 100.0f, 120.0f, 35.0f },
    { 110.0f, 125.0f, 40.0f },
};

const unk_8008112C_arg_1 D_800D5358 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 400.0f, 0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
      0.0f, 1.0f, 80.0f, 80.0f, 0.2f, 0.0f,   77.0f, 0.0f, 77.0f, 0.1f, 0.2f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   0.0f,
      0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   1.0f,
      0.0f, 400.0f, 400.0f, 0.2f, 50.0f, 50.0f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 300.0f, 0.0f },
};

const unk_8008112C_arg_1 D_800D544C = {
    { 0.0f, 0.0f, 0.0f,   0.0f,   0.0f, 400.0f, 0.0f,   1.0f, 0.0f,   0.0f, 1.0f,
      0.0f, 1.0f, 100.0f, 100.0f, 0.2f, 0.0f,   -15.0f, 0.0f, -15.0f, 0.1f, 0.2f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   0.0f,
      0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   1.0f,
      0.0f, 400.0f, 400.0f, 0.2f, 50.0f, 50.0f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 300.0f, 0.0f },
};

const s32 D_800D5540[] = { 0 };

const s32 D_800D5544[] = { 1, 2 };

const s32 D_800D554C[] = { 5, 7, 6 };

const s32 D_800D5558[] = { 5, 7, 6, 8 };

s32 D_800CD8A0 = -1;
s32 D_800CD8A4 = 1;
f32 D_800CD8A8 = 5.0f;
f32 D_800CD8AC = 5.0f;

// Probably a larger combined array (both should ideally have length 14)
f32 D_800CD8B0[] = {
    2000.0f,
    0.0f,
    25.0f,
};

f32 D_800CD8BC[] = {
    4000.0f,
    -0.9f,
    50.0f,
};

f32 D_800CD8C8[] = {
    -7.0f, 0.0f, 63.0f, -7.0f, 0.0f, 63.0f, 26.0f, 20.0f, -65.0f, 26.0f, 20.0f, -65.0f, 0.0f, 0.0f,
};

f32 D_800CD900[] = {
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -50.0f, 40.0f, 40.0f, -50.0f, 40.0f, -40.0f, 0.0f, 1.0f,
};

f32 D_800CD938[] = {
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -40.0f, 30.0f, 104.0f, 40.0f, 30.0f, 104.0f, 0.0f, 1.0f,
};

unk_800CD970 D_800CD970[] = {
    { 0, 88, 60.0f, D_800CD8B0 }, { 1, 23, 60.0f, D_800CD8C8 },  { 1, 23, 60.0f, D_800CD900 },
    { 1, 23, 80.0f, D_800CD938 }, { 0, 284, 60.0f, D_800CD8BC },
};

const s32* D_800CD9AC[] = {
    NULL, D_800D5540, D_800D5544, D_800D554C, D_800D5558,
};

ScissorBox D_800CD9C0 = { 12, 8, 308, 232 };
ScissorBox D_800CD9D0 = { 12, 8, 307, 119 };
ScissorBox D_800CD9E0 = { 12, 120, 307, 231 };
ScissorBox D_800CD9F0 = { 12, 8, 159, 231 };
ScissorBox D_800CDA00 = { 160, 8, 307, 231 };
ScissorBox D_800CDA10 = { 12, 8, 159, 119 };
ScissorBox D_800CDA20 = { 160, 8, 307, 119 };
ScissorBox D_800CDA30 = { 12, 120, 159, 231 };
ScissorBox D_800CDA40 = { 160, 120, 307, 231 };
ScissorBox D_800CDA50 = { 86, 8, 233, 119 };
ScissorBox D_800CDA60 = { 86, 120, 233, 231 };
ScissorBox D_800CDA70 = { 12, 64, 159, 175 };
ScissorBox D_800CDA80 = { 160, 64, 307, 175 };

f32 D_800CDA90 = 25.4629631f;
f32 D_800CDA94 = 46.29629517f;
f32 D_800CDA98 = 120.0f;
s32 D_800CDA9C = 8;

TexturePtr D_800CDAA0[] = {
    aFirstPlaceMarker1PTex,
    aSecondPlaceMarker1PTex,
    aThirdPlaceMarker1PTex,
};

TexturePtr D_800CDAAC[] = {
    aFirstPlaceMarkerMPTex,
    aSecondPlaceMarkerMPTex,
    aThirdPlaceMarkerMPTex,
};

TexturePtr D_800CDAB8[] = {
    aExplosion1Tex, aExplosion2Tex, aExplosion3Tex, aExplosion4Tex,
    aExplosion5Tex, aExplosion6Tex, aExplosion7Tex, aExplosion8Tex,
};

// Car Models
Gfx* D_800CDAD8[] = {
    D_9001210, D_9001DA0, D_90027D0, D_9003050, D_9003870, D_9003F90, D_900CF48, D_90057A8, D_90061A0,
    D_9006A70, D_90078F0, D_9008060, D_90089A0, D_9009358, D_9009980, D_900A150, D_900AC40, D_900B288,
    D_900BD28, D_900C550, D_9004B98, D_900D898, D_900DFF8, D_900E698, D_900EFE8, D_900F790, D_90100F8,
    D_9010C38, D_90113D8, D_9011EA8, D_9015400, D_9015938, D_9015658, D_9014B40, D_9014DE0, D_9015088,
    D_90148F8, D_9015B58, D_9017350, D_9016DA0, D_9015F50, D_9016298, D_9016530, D_9016948, D_90186C0,
    D_9017B18, D_9018230, D_9017BF0, D_90183F0, D_9017D20, D_9017EC8,
};

Vtx* D_800CDBA4[] = {
    D_3004F18, D_3006C78, D_3008C18, D_300A4E8, D_300BB78, D_300D3F8, D_3020758, D_30104F8, D_3011778,
    D_3012EC8, D_30140D8, D_3015418, D_3016958, D_30177D8, D_3018E98, D_301A2E8, D_301B7B8, D_301CA98,
    D_301E058, D_301F328, D_300E9A8, D_3022178, D_3023358, D_3024D78, D_3025DB8, D_3027068, D_30285C8,
    D_3029648, D_302A908, D_302B9F8, D_3036A78, D_3036EB8, D_30372F8, D_3037738, D_3037B78, D_3037FB8,
    D_30383F8, D_3038838, D_3038C78, D_30390B8, D_30394F8, D_3039938, D_3039D78, D_303A1B8,
};

TexturePtr D_800CDC54[] = {
    D_3004F58, D_3006CB8, D_3008C58, D_300A528, D_300BBB8, D_300D438, D_3020798, D_3010538, D_30117B8,
    D_3012F08, D_3014118, D_3015458, D_3016998, D_3017818, D_3018ED8, D_301A328, D_301B7F8, D_301CAD8,
    D_301E098, D_301F368, D_300E9E8, D_30221B8, D_3023398, D_3024DB8, D_3025DF8, D_30270A8, D_3028608,
    D_3029688, D_302A948, D_302BA38, D_3036AB8, D_3036EF8, D_3037338, D_3037778, D_3037BB8, D_3037FF8,
    D_3038438, D_3038878, D_3038CB8, D_30390F8, D_3039538, D_3039978, D_3039DB8, D_303A1F8,
};

UNUSED u8 D_800CDD04[] = { 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28, 0x29, 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28,
                           0x29, 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28, 0x29, 0x25, 0x2B, 0x2A, 0x26, 0x27,
                           0x28, 0x29, 0x1E, 0x24, 0x23, 0x1F, 0x20, 0x21, 0x22, 0x1E, 0x24, 0x23, 0x1F,
                           0x20, 0x21, 0x22, 0x1E, 0x24, 0x23, 0x1F, 0x20, 0x21, 0x22 };

// Custom Cars Models?
Gfx* D_800CDD38[] = {
    D_8022F8C0, D_802308E0, D_80231900, D_80232920, D_80233940, D_80234960, D_80235980, D_802369A0,
    D_802379C0, D_802389E0, D_80239A00, D_8023AA20, D_8023BA40, D_8023CA60, D_8023DA80, D_8023EAA0,
    D_8023FAC0, D_80240AE0, D_80241B00, D_80242B20, D_80243B40, D_80244B60, D_80245B80, D_80246BA0,
    D_80247BC0, D_80248BE0, D_80249C00, D_8024AC20, D_8024BC40, D_8024CC60,
};

Gfx* D_800CDDB0[] = {
    D_8022FA58, D_8022FE48, D_80230198, D_80230480, D_802306F0, D_7045098,  D_80230A78, D_80230E68, D_802311B8,
    D_802314A0, D_80231710, D_7045098,  D_80231A98, D_80231E88, D_802321D8, D_802324C0, D_80232730, D_7045098,
    D_80232AB8, D_80232EA8, D_802331F8, D_802334E0, D_80233750, D_7045098,  D_80233AD8, D_80233EC8, D_80234218,
    D_80234500, D_80234770, D_7045098,  D_80234AF8, D_80234EE8, D_80235238, D_80235520, D_80235790, D_7045098,
    D_80235B18, D_80235F08, D_80236258, D_80236540, D_802367B0, D_7045098,  D_80236B38, D_80236F28, D_80237278,
    D_80237560, D_802377D0, D_7045098,  D_80237B58, D_80237F48, D_80238298, D_80238580, D_802387F0, D_7045098,
    D_80238B78, D_80238F68, D_802392B8, D_802395A0, D_80239810, D_7045098,  D_80239B98, D_80239F88, D_8023A2D8,
    D_8023A5C0, D_8023A830, D_7045098,  D_8023ABB8, D_8023AFA8, D_8023B2F8, D_8023B5E0, D_8023B850, D_7045098,
    D_8023BBD8, D_8023BFC8, D_8023C318, D_8023C600, D_8023C870, D_7045098,  D_8023CBF8, D_8023CFE8, D_8023D338,
    D_8023D620, D_8023D890, D_7045098,  D_8023DC18, D_8023E008, D_8023E358, D_8023E640, D_8023E8B0, D_7045098,
    D_8023EC38, D_8023F028, D_8023F378, D_8023F660, D_8023F8D0, D_7045098,  D_8023FC58, D_80240048, D_80240398,
    D_80240680, D_802408F0, D_7045098,  D_80240C78, D_80241068, D_802413B8, D_802416A0, D_80241910, D_7045098,
    D_80241C98, D_80242088, D_802423D8, D_802426C0, D_80242930, D_7045098,  D_80242CB8, D_802430A8, D_802433F8,
    D_802436E0, D_80243950, D_7045098,  D_80243CD8, D_802440C8, D_80244418, D_80244700, D_80244970, D_7045098,
    D_80244CF8, D_802450E8, D_80245438, D_80245720, D_80245990, D_7045098,  D_80245D18, D_80246108, D_80246458,
    D_80246740, D_802469B0, D_7045098,  D_80246D38, D_80247128, D_80247478, D_80247760, D_802479D0, D_7045098,
    D_80247D58, D_80248148, D_80248498, D_80248780, D_802489F0, D_7045098,  D_80248D78, D_80249168, D_802494B8,
    D_802497A0, D_80249A10, D_7045098,  D_80249D98, D_8024A188, D_8024A4D8, D_8024A7C0, D_8024AA30, D_7045098,
    D_8024ADB8, D_8024B1A8, D_8024B4F8, D_8024B7E0, D_8024BA50, D_7045098,  D_8024BDD8, D_8024C1C8, D_8024C518,
    D_8024C800, D_8024CA70, D_7045098,  D_8024CDF8, D_8024D1E8, D_8024D538, D_8024D820, D_8024DA90,
};

Gfx* D_800CE07C[] = {
    D_7045098, D_7045278, D_70469D8, D_70476D8, D_7047F70, D_7048550, D_7045098,
};

Gfx* (*D_800CE098[])(Gfx*) = {
    func_i9_801685B4, // CAPTAIN_FALCON
    func_i9_801680E8, // DR_STEWART
    func_i9_80167C1C, // PICO
    func_i9_80167898, // SAMURAI_GOROH
    func_i9_80167530, // JODY_SUMMER
    func_i9_80167068, // MIGHTY_GAZELLE
    func_i9_801636F4, // MR_EAD
    func_i9_801667F8, // BABA
    func_i9_80166468, // OCTOMAN
    func_i9_801660BC, // GOMAR_AND_SHIOH
    func_i9_80165D28, // KATE_ALEN
    func_i9_80165858, // ROGER_BUSTER
    func_i9_80165494, // JAMES_MCCLOUD
    func_i9_80165124, // LEON
    func_i9_80164E34, // ANTONIO_GUSTER
    func_i9_8016497C, // BLACK_SHADOW
    func_i9_80164608, // MICHAEL_CHAIN
    func_i9_801642A4, // JACK_LEVIN
    func_i9_80163F28, // SUPER_ARROW
    func_i9_80163BAC, // MRS_ARROW
    func_i9_80166CF4, // JOHN_TANAKA
    func_i9_80163374, // BEASTMAN
    func_i9_80162FE0, // ZODA
    func_i9_80162B08, // DR_CLASH
    func_i9_80162768, // SILVER_NEELSEN
    func_i9_80162370, // BIO_REX
    func_i9_80161FF8, // DRAQ
    func_i9_80161C78, // BILLY
    func_i9_8016197C, // THE_SKULL
    func_i9_801614D0, // BLOOD_FALCON
    func_i9_801685B4, func_i9_80167898, func_i9_80167530,
};

Gfx* (*D_800CE11C[][5])(Gfx*) = {
    { func_i9_8012D998, func_i9_8012E4E4, func_i9_8012ECF4, func_i9_8012F30C, func_i9_8012F608 }, // CAPTAIN_FALCON
    { func_i9_8012F7BC, func_i9_801300FC, func_i9_80130840, func_i9_80130E44, func_i9_80131130 }, // DR_STEWART
    { func_i9_801312F0, func_i9_80131D18, func_i9_8013251C, func_i9_80132B40, func_i9_80132E04 }, // PICO
    { func_i9_80132F44, func_i9_80133744, func_i9_80133E58, func_i9_80134468, func_i9_80134734 }, // SAMURAI_GOROH
    { func_i9_80134880, func_i9_80135180, func_i9_80135894, func_i9_80135F5C, func_i9_801361B8 }, // JODY_SUMMER
    { func_i9_80136350, func_i9_80136C74, func_i9_8013737C, func_i9_80137968, func_i9_80137C68 }, // MIGHTY_GAZELLE
    { func_i9_8014FCC0, func_i9_80150414, func_i9_80150AEC, func_i9_801511A8, func_i9_8015156C }, // MR_EAD
    { func_i9_8013996C, func_i9_8013A25C, func_i9_8013A9A8, func_i9_8013AFD4, func_i9_8013B34C }, // BABA
    { func_i9_8013B57C, func_i9_8013BD04, func_i9_8013C360, func_i9_8013C8EC, func_i9_8013CC0C }, // OCTOMAN
    { func_i9_8013CED0, func_i9_8013D814, func_i9_8013DF88, func_i9_8013E5A8, func_i9_8013E964 }, // GOMAR_AND_SHIOH
    { func_i9_8013EB2C, func_i9_8013F248, func_i9_8013F8E0, func_i9_8013FF20, func_i9_801403C4 }, // KATE_ALEN
    { func_i9_8014061C, func_i9_80140E54, func_i9_80141590, func_i9_80141BC8, func_i9_80141ECC }, // ROGER_BUSTER
    { func_i9_80142078, func_i9_80142950, func_i9_80143080, func_i9_801436A4, func_i9_80143BB8 }, // JAMES_MCCLOUD
    { func_i9_80143E40, func_i9_80144518, func_i9_80144B30, func_i9_801450C4, func_i9_8014553C }, // LEON
    { func_i9_80145860, func_i9_80145F34, func_i9_8014651C, func_i9_80146A4C, func_i9_80146DB8 }, // ANTONIO_GUSTER
    { func_i9_80147074, func_i9_801479B8, func_i9_8014812C, func_i9_80148778, func_i9_80148BF0 }, // BLACK_SHADOW
    { func_i9_80148E3C, func_i9_801495B8, func_i9_80149CBC, func_i9_8014A31C, func_i9_8014A6D4 }, // MICHAEL_CHAIN
    { func_i9_8014A98C, func_i9_8014B174, func_i9_8014B874, func_i9_8014BE8C, func_i9_8014C32C }, // JACK_LEVIN
    { func_i9_8014C5D4, func_i9_8014CD1C, func_i9_8014D3A0, func_i9_8014D9A4, func_i9_8014DE64 }, // SUPER_ARROW
    { func_i9_8014E104, func_i9_8014E8E0, func_i9_8014EFAC, func_i9_8014F580, func_i9_8014FA30 }, // MRS_ARROW
    { func_i9_80137DBC, func_i9_801387D4, func_i9_80138F38, func_i9_801394EC, func_i9_801397B0 }, // JOHN_TANAKA
    { func_i9_801517FC, func_i9_80151FE0, func_i9_801526BC, func_i9_80152CA8, func_i9_801531A4 }, // BEASTMAN
    { func_i9_80153538, func_i9_80153BD4, func_i9_80154234, func_i9_8015483C, func_i9_80154CE4 }, // ZODA
    { func_i9_80154F14, func_i9_801556FC, func_i9_80155EB8, func_i9_801564E8, func_i9_801569C8 }, // DR_CLASH
    { func_i9_80156CAC, func_i9_80157390, func_i9_80157A50, func_i9_8015805C, func_i9_801584F0 }, // SILVER_NEELSEN
    { func_i9_80158800, func_i9_80158EEC, func_i9_801595B0, func_i9_80159BE0, func_i9_80159F7C }, // BIO_REX
    { func_i9_8015A1B4, func_i9_8015AAE8, func_i9_8015B1F4, func_i9_8015B7E8, func_i9_8015BC90 }, // DRAQ
    { func_i9_8015BF44, func_i9_8015C634, func_i9_8015CD18, func_i9_8015D344, func_i9_8015D814 }, // BILLY
    { func_i9_8015DA94, func_i9_8015E268, func_i9_8015E910, func_i9_8015EE84, func_i9_8015F214 }, // THE_SKULL
    { func_i9_8015F46C, func_i9_8015FC70, func_i9_80160314, func_i9_801608D8, func_i9_80160D90 }, // BLOOD_FALCON
    { func_i9_80127F54, func_i9_801289DC, func_i9_801292C0, func_i9_80129974, func_i9_80129D04 },
    { func_i9_80129FC4, func_i9_8012A8B0, func_i9_8012B010, func_i9_8012B6C4, func_i9_8012B9C4 },
    { func_i9_8012BB50, func_i9_8012C564, func_i9_8012CD8C, func_i9_8012D524, func_i9_8012D7CC },
};

u8 D_800CE3B0[] = {
    true,  // CAPTAIN_FALCON
    true,  // DR_STEWART
    true,  // PICO
    true,  // SAMURAI_GOROH
    false, // JODY_SUMMER
    true,  // MIGHTY_GAZELLE
    true,  // MR_EAD
    false, // BABA
    true,  // OCTOMAN
    true,  // GOMAR_AND_SHIOH
    false, // KATE_ALEN
    true,  // ROGER_BUSTER
    true,  // JAMES_MCCLOUD
    true,  // LEON
    true,  // ANTONIO_GUSTER
    true,  // BLACK_SHADOW
    true,  // MICHAEL_CHAIN
    true,  // JACK_LEVIN
    true,  // SUPER_ARROW
    false, // MRS_ARROW
    true,  // JOHN_TANAKA
    true,  // BEASTMAN
    true,  // ZODA
    true,  // DR_CLASH
    true,  // SILVER_NEELSEN
    true,  // BIO_REX
    true,  // DRAQ
    true,  // BILLY
    true,  // THE_SKULL
    true,  // BLOOD_FALCON
};

// Dma Read Data
u8 D_800CE3D0[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0A, 0x14, 0x1E, 0x28, 0x32, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x32, 0x28, 0x1E,
    0x14, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x1E, 0x32, 0x46, 0x5A,
    0x6E, 0x5A, 0x46, 0x32, 0x1E, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x14, 0x32, 0x50, 0x6E, 0x8C, 0xAA, 0xC8, 0xE6, 0xC8,
    0xAA, 0x8C, 0x6E, 0x50, 0x32, 0x14, 0x00, 0x00, 0x00,
};

s16 gSettingVsHandicap = 0;
s16 gSettingVsCom = 1;

f32 D_800CE4D8 = 2000.0f;

s8 gTotalLives[] = { 5, 4, 3, 2 };

Vec3s D_800CE4E0[] = {
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
};

Vec3s D_800CE5D0[] = {
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },
    { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },
    { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },
    { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
};

s32 D_800CE6C0[] = {
    100, 93, 87, 81, 76, 71, 66, 62, 58, 54, 50, 47, 44, 41, 38,
    35,  33, 31, 29, 27, 25, 23, 22, 21, 20, 19, 18, 17, 16, 15,
};

s32 D_800CE738[] = { 5, 3, 1, 0 };

f32 D_800CE748 = 0.1f;
f32 D_800CE74C = 0.1f;
f32 D_800CE750 = 0.1f;

f32 D_800CE754 = 250.0f;

UNUSED Vec3f D_800CE758 = { 0 };

s16 D_800CE764 = 60;
s32 D_800CE768 = 700;
f32 D_800CE76C = 0.01f;
f32 D_800CE770 = 25.0f;
s32 sInitialBoostTimer = 100;
f32 sEnergyRefillScale = 0.008f;
s16 D_800CE77C = 0;
s16 D_800CE780 = 1;
s16 D_800CE784 = 0;

typedef struct unk_800CE788 {
    s32 unk_00;
    Vec3f unk_04[4];
    f32 unk_34[4];
} unk_800CE788;

// clang-format off
unk_800CE788 D_800CE788[] = {
    { 4, { { -87.0f, 22.0f, -208.0f }, { -87.0f, 60.0f, -208.0f }, { 87.0f, 22.0f, -208.0f }, { 87.0f, 60.0f, -208.0f } }, { 10.0f, 10.0f, 10.0f, 10.0f } },
    { 4, { { -73.0f, 25.0f, -202.0f }, { -26.0f, 25.0f, -202.0f }, { 24.0f, 25.0f, -202.0f }, { 72.0f, 25.0f, -202.0f } }, { 12.0f, 12.0f, 12.0f, 12.0f } },
    { 3, { { 28.0f, 36.0f, -236.0f }, { -31.0f, 36.0f, -236.0f }, { 0.0f, 127.0f, -262.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 15.0f, 0.0f } },
    { 2, { { -33.0f, 55.0f, -170.0f }, { 33.0f, 52.0f, -170.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 4, { { -50.0f, 19.0f, -222.0f }, { 48.0f, 19.0f, -222.0f }, { -83.0f, 19.0f, -222.0f }, { 81.0f, 19.0f, -222.0f } }, { 10.0f, 10.0f, 10.0f, 10.0f } },
    { 1, { { 2.0f, 29.0f, -226.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 21.0f, 0.0f, 0.0f, 0.0f } },
    { 4, { { -68.0f, 58.0f, -205.0f }, { -23.0f, 58.0f, -205.0f }, { 22.0f, 58.0f, -205.0f }, { 67.0f, 58.0f, -205.0f } }, { 12.0f, 12.0f, 12.0f, 12.0f } },
    { 2, { { -85.0f, 31.0f, -276.0f }, { 85.0f, 31.0f, -276.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 12.0f, 12.0f, 0.0f, 0.0f } },
    { 4, { { -52.0f, 29.0f, -213.0f }, { -17.0f, 29.0f, -213.0f }, { 17.0f, 29.0f, -213.0f }, { 52.0f, 29.0f, -213.0f } }, { 10.0f, 10.0f, 10.0f, 10.0f } },
    { 2, { { -82.0f, 40.0f, -215.0f }, { 82.0f, 40.0f, -215.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 12.0f, 12.0f, 0.0f, 0.0f } },
    { 2, { { -35.0f, 36.0f, -188.0f }, { 35.0f, 36.0f, -188.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 1, { { 0.0f, 86.0f, -200.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 23.0f, 0.0f, 0.0f, 0.0f } },
    { 2, { { -67.0f, 50.0f, -218.0f }, { 67.0f, 50.0f, -218.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 1, { { 0.0f, 42.0f, -230.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 0.0f, 0.0f, 0.0f } },
    { 2, { { -27.0f, 36.0f, -201.0f }, { 27.0f, 36.0f, -201.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 3, { { -56.0f, 30.0f, -235.0f }, { 54.0f, 30.0f, -235.0f }, { 0.0f, 30.0f, -235.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 15.0f, 0.0f } },
    { 2, { { -30.0f, 37.0f, -218.0f }, { 29.0f, 37.0f, -218.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 17.0f, 17.0f, 0.0f, 0.0f } },
    { 2, { { -32.0f, 35.0f, -229.0f }, { 33.0f, 35.0f, -229.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 9.0f, 9.0f, 0.0f, 0.0f } },
    { 3, { { -45.0f, 37.0f, -208.0f }, { 45.0f, 37.0f, -208.0f }, { 0.0f, 115.0f, -208.0f }, { 0.0f, 0.0f, 0.0f } }, { 19.0f, 19.0f, 19.0f, 0.0f } },
    { 2, { { 0.0f, 32.0f, -228.0f }, { 0.0f, 95.0f, -221.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 2, { { -27.0f, 94.0f, -136.0f }, { 27.0f, 94.0f, -136.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 3, { { -86.0f, 28.0f, -242.0f }, { 87.0f, 28.0f, -242.0f }, { 0.0f, 33.0f, -242.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 20.0f, 0.0f } },
    { 1, { { 0.0f, 91.0f, -220.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 18.0f, 0.0f, 0.0f, 0.0f } },
    { 3, { { -62.0f, 65.0f, -226.0f }, { 60.0f, 65.0f, -226.0f }, { 0.0f, 65.0f, -226.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 15.0f, 0.0f } },
    { 4, { { -83.0f, 30.0f, -220.0f }, { -28.0f, 30.0f, -220.0f }, { 28.0f, 30.0f, -220.0f }, { 83.0f, 30.0f, -220.0f } }, { 15.0f, 15.0f, 15.0f, 15.0f } },
    { 3, { { -75.0f, 31.0f, -226.0f }, { 75.0f, 31.0f, -226.0f }, { 0.0f, 100.0f, -226.0f }, { 0.0f, 0.0f, 0.0f } }, { 22.0f, 22.0f, 20.0f, 0.0f } },
    { 3, { { 0.0f, 33.0f, -210.0f }, { 0.0f, 90.0f, -210.0f }, { 0.0f, 150.0f, -210.0f }, { 0.0f, 0.0f, 0.0f } }, { 17.0f, 17.0f, 17.0f, 0.0f } },
    { 1, { { 0.0f, 123.0f, -206.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 0.0f, 0.0f, 0.0f } },
    { 1, { { 0.0f, 28.0f, -225.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 0.0f, 0.0f, 0.0f } },
    { 4, { { -84.0f, 25.0f, -234.0f }, { -28.0f, 25.0f, -234.0f }, { 28.0f, 25.0f, -234.0f }, { 83.0f, 25.0f, -234.0f } }, { 17.0f, 17.0f, 17.0f, 17.0f } },
    { 1, { { 0.0f, 34.0f, -224.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 0.0f, 0.0f, 0.0f } },
    { 2, { { -130.0f, 40.0f, -225.0f }, { 130.0f, 40.0f, -225.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 2, { { -30.0f, 46.0f, -228.0f }, { 30.0f, 46.0f, -228.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 0.0f, 0.0f } },
    { 2, { { -32.0f, 33.0f, -232.0f }, { 32.0f, 33.0f, -232.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 3, { { -65.0f, 30.0f, -240.0f }, { 65.0f, 30.0f, -240.0f }, { 0.0f, 30.0f, -240.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 16.0f, 0.0f } },
    { 2, { { -95.0f, 30.0f, -229.0f }, { 100.0f, 30.0f, -229.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 4, { { -98.0f, 34.0f, -229.0f }, { -33.0f, 34.0f, -229.0f }, { 32.0f, 34.0f, -229.0f }, { 97.0f, 34.0f, -229.0f } }, { 18.0f, 18.0f, 18.0f, 18.0f } },
};
// clang-format on

f32 D_800CF15C = 0.1f;

f32 gBodyHealthValues[] = {
    190.0f, 178.0f, 166.0f, 154.0f, 142.0f,
};

f32 D_800CF174[] = {
    0.210f, 0.207f, 0.204f, 0.201f, 0.198f,
};

f32 D_800CF188[] = {
    1.277f, 1.237f, 1.197f, 1.157f, 1.117f,
};

f32 D_800CF19C[] = {
    0.397f, 0.367f, 0.337f, 0.307f, 0.277f,
};

// clang-format off
unk_800CF1B0 D_800CF1B0[] = {
    { 0, 0, 0, { 0, 211, 0, 77 }, { 0, 0, 87, 77 }, { 255, 102, 48, 77 }, 7, { BODY_B, BOOST_C, GRIP_B }, 1260 },                // CAPTAIN_FALCON
    { 0, 1, 1, { 255, 226, 43, 120 }, { 205, 255, 133, 80 }, { 25, 255, 255, 160 }, 3, { BODY_D, BOOST_A, GRIP_D }, 1420 },      // DR_STEWART
    { 0, 2, 2, { 0, 75, 190, 100 }, { 134, 81, 65, 100 }, { 73, 163, 16, 100 }, 6, { BODY_B, BOOST_B, GRIP_C }, 1620 },          // PICO
    { 0, 3, 3, { 245, 52, 72, 43 }, { 72, 52, 121, 120 }, { 146, 52, 245, 65 }, 5, { BODY_A, BOOST_D, GRIP_B }, 1960 },          // SAMURAI_GOROH
    { 0, 4, 4, { 111, 255, 0, 255 }, { 79, 0, 182, 168 }, { 184, 0, 133, 0 }, 2, { BODY_C, BOOST_C, GRIP_A }, 1150 },            // JODY_SUMMER
    { 0, 5, 5, { 255, 0, 74, 36 }, { 0, 0, 74, 101 }, { 0, 190, 74, 46 }, 1, { BODY_E, BOOST_A, GRIP_C }, 1330 },                // MIGHTY_GAZELLE
    { 0, 6, 6, { 143, 255, 77, 57 }, { 73, 104, 198, 188 }, { 232, 3, 216, 35 }, 9, { BODY_E, BOOST_A, GRIP_D }, 1870 },         // MR_EAD
    { 0, 7, 7, { 143, 60, 146, 220 }, { 144, 60, 216, 220 }, { 192, 60, 146, 146 }, 4, { BODY_B, BOOST_D, GRIP_A }, 1780 },      // BABA
    { 0, 8, 8, { 146, 255, 14, 44 }, { 0, 108, 75, 148 }, { 17, 0, 26, 196 }, 8, { BODY_B, BOOST_B, GRIP_C }, 990 },             // OCTOMAN
    { 0, 9, 9, { 100, 240, 239, 92 }, { 100, 201, 98, 184 }, { 100, 64, 195, 227 }, 22, { BODY_E, BOOST_A, GRIP_C }, 780 },      // GOMAR_AND_SHIOH
    { 0, 10, 10, { 71, 255, 58, 99 }, { 202, 240, 58, 223 }, { 196, 0, 58, 102 }, 12, { BODY_B, BOOST_C, GRIP_B }, 1010 },       // KATE_ALEN
    { 0, 11, 11, { 0, 196, 20, 121 }, { 90, 33, 41, 101 }, { 90, 33, 121, 20 }, 28, { BODY_E, BOOST_B, GRIP_B }, 1780 },         // ROGER_BUSTER
    { 0, 12, 12, { 160, 255, 223, 123 }, { 160, 168, 112, 251 }, { 180, 0, 255, 255 }, 10, { BODY_E, BOOST_B, GRIP_B }, 1390 },  // JAMES_MCCLOUD
    { 0, 13, 13, { 71, 255, 255, 150 }, { 79, 198, 84, 150 }, { 151, 0, 144, 150 }, 19, { BODY_C, BOOST_C, GRIP_A }, 910 },      // LEON
    { 0, 14, 14, { 10, 53, 255, 92 }, { 50, 201, 240, 238 }, { 20, 255, 0, 63 }, 17, { BODY_A, BOOST_B, GRIP_D }, 2060 },        // ANTONIO_GUSTER
    { 0, 15, 15, { 30, 54, 82, 122 }, { 30, 35, 54, 107 }, { 30, 192, 82, 14 }, 30, { BODY_A, BOOST_E, GRIP_A }, 2340 },         // BLACK_SHADOW
    { 0, 16, 16, { 206, 25, 249, 22 }, { 84, 168, 218, 217 }, { 22, 29, 3, 174 }, 24, { BODY_A, BOOST_C, GRIP_C }, 2110 },       // MICHAEL_CHAIN
    { 0, 17, 17, { 71, 255, 28, 56 }, { 79, 0, 80, 56 }, { 151, 0, 42, 56 }, 14, { BODY_B, BOOST_D, GRIP_A }, 1050 },            // JACK_LEVIN
    { 0, 18, 18, { 141, 29, 46, 38 }, { 15, 21, 46, 130 }, { 36, 184, 46, 29 }, 20, { BODY_E, BOOST_B, GRIP_B }, 860 },          // SUPER_ARROW
    { 0, 19, 19, { 141, 29, 46, 38 }, { 15, 21, 46, 130 }, { 36, 184, 46, 29 }, 21, { BODY_E, BOOST_B, GRIP_B }, 1140 },         // MRS_ARROW
    { 0, 20, 20, { 14, 200, 213, 22 }, { 145, 51, 14, 95 }, { 213, 195, 14, 38 }, 26, { BODY_D, BOOST_A, GRIP_D }, 900 },        // JOHN_TANAKA
    { 0, 21, 21, { 19, 190, 165, 20 }, { 64, 190, 12, 60 }, { 90, 190, 12, 20 }, 18, { BODY_C, BOOST_C, GRIP_A }, 1460 },        // BEASTMAN
    { 0, 22, 22, { 26, 219, 217, 155 }, { 30, 230, 0, 24 }, { 57, 255, 0, 156 }, 13, { BODY_E, BOOST_A, GRIP_C }, 1620 },        // ZODA
    { 0, 23, 23, { 203, 121, 255, 255 }, { 203, 205, 255, 149 }, { 84, 212, 255, 244 }, 29, { BODY_A, BOOST_B, GRIP_E }, 2220 }, // DR_CLASH
    { 0, 24, 24, { 3, 218, 28, 118 }, { 3, 17, 181, 118 }, { 46, 17, 104, 118 }, 23, { BODY_B, BOOST_A, GRIP_E }, 1530 },        // SILVER_NEELSEN
    { 0, 25, 25, { 51, 203, 0, 9 }, { 48, 0, 126, 131 }, { 28, 0, 20, 166 }, 15, { BODY_B, BOOST_D, GRIP_A }, 1520 },            // BIO_REX
    { 0, 26, 26, { 72, 21, 179, 69 }, { 90, 120, 49, 72 }, { 0, 149, 67, 137 }, 27, { BODY_C, BOOST_A, GRIP_D }, 950 },          // DRAQ
    { 0, 27, 27, { 254, 227, 20, 104 }, { 244, 62, 72, 99 }, { 65, 34, 24, 150 }, 11, { BODY_B, BOOST_B, GRIP_C }, 1490 },       // BILLY
    { 0, 28, 28, { 31, 232, 192, 91 }, { 63, 0, 0, 91 }, { 223, 0, 176, 91 }, 16, { BODY_C, BOOST_A, GRIP_D }, 1010 },           // THE_SKULL
    { 0, 29, 29, { 200, 0, 63, 40 }, { 0, 72, 214, 38 }, { 0, 255, 42, 105 }, 25, { BODY_B, BOOST_A, GRIP_E }, 1170 },           // BLOOD_FALCON
    { 2, 0, 0, { 223, 34, 12, 224 }, { 199, 34, 50, 239 }, { 33, 34, 109, 240 }, 7, { BODY_A, BOOST_B, GRIP_A }, 790 },
    { 3, 3, 3, { 55, 42, 85, 10 }, { 55, 59, 11, 123 }, { 55, 136, 24, 125 }, 5, { BODY_B, BOOST_A, GRIP_A }, 2210 },
    { 4, 4, 4, { 33, 42, 0, 134 }, { 55, 42, 134, 0 }, { 137, 42, 73, 72 }, 2, { BODY_A, BOOST_A, GRIP_B }, 1840 },
};
// clang-format on

UNUSED s16 D_800CF488[] = {
    270, 290, 320, 350, 420, 580, 630, 0, 510, 560, 630, 720, 890, 930, 1170, 0, 0, 100, 120, 140, 190, 250, 420, 0,
};

void func_8008EC38(Racer*);
void func_8008EC58(Racer*);
void func_8008EC98(Racer*);
void func_8008F550(Racer*);
void func_8008FC80(Racer*);
void func_8008EC78(Racer*);
void func_80090490(Racer*);
void func_80090568(Racer*);

void (*D_800CF4B8[])(Racer*) = {
    func_8008EC38, // TRACK_SHAPE_ROAD
    func_8008EC58, // TRACK_SHAPE_WALLED_ROAD
    func_8008EC98, // TRACK_SHAPE_PIPE
    func_8008F550, // TRACK_SHAPE_CYLINDER
    func_8008FC80, // TRACK_SHAPE_HALF_PIPE
    func_8008EC78, // TRACK_SHAPE_TUNNEL
    func_80090490, // TRACK_SHAPE_AIR
    func_80090568, // TRACK_SHAPE_BORDERLESS_ROAD
};

u8 D_800CF4D8[] = {
    0, 1, 2, 5, 4, 3, 7, 6, 5, 0, 4, 8, 2, 1, 7, 6, 8, 0, 7, 5, 6, 2, 3, 8,
};

u8 D_800CF4F0[] = {
    0, // VENUE_MUTE_CITY
    3, // VENUE_PORT_TOWN
    4, // VENUE_BIG_BLUE
    2, // VENUE_SAND_OCEAN
    5, // VENUE_DEVILS_FOREST
    8, // VENUE_WHITE_LAND
    7, // VENUE_SECTOR
    6, // VENUE_RED_CANYON
    2, // VENUE_FIRE_FIELD
    1, // VENUE_SILENCE
    0, // VENUE_ENDING
};

void func_800810E0(unk_struct_F8* arg0, unk_struct_20* arg1) {
    arg0->unk_00 = 1;
    arg0->unk_04.unk_58.unk_00.unk_00.unk_00 = *arg1;
}

void func_8008112C(unk_struct_F8* arg0, unk_redo_1* arg1) {
    arg0->unk_00 = 1;
    arg0->unk_04.unk_00 = arg1->unk_00;
    arg0->unk_04.unk_58.unk_00.unk_00.unk_00 = arg1->unk_58;
}

void func_800811B0(unk_struct_F8* arg0, unk_struct_9C* arg1) {
    arg0->unk_00 = 4;
    arg0->unk_04.unk_58 = *arg1;
}

void func_800811F0(unk_struct_F8* arg0, unk_8008112C_arg_1* arg1) {
    arg0->unk_00 = 4;
    arg0->unk_04.unk_00 = arg1->unk_00;
    arg0->unk_04.unk_58 = arg1->unk_58;
}

void func_80081268(unk_struct_F8* arg0, s32 arg1, unk_struct_54* arg2) {
    arg0->unk_00 = arg1;
    arg0->unk_04.unk_58.unk_00.unk_00 = *arg2;
}

void func_800812A4(unk_struct_F8* arg0, s32 arg1, unk_redo_2* arg2) {
    arg0->unk_00 = arg1;
    arg0->unk_04.unk_00 = arg2->unk_00;
    arg0->unk_04.unk_58.unk_00.unk_00 = arg2->unk_58;
}

void func_80081318(unk_struct_F8* arg0, unk_struct_68* arg1) {
    arg0->unk_00 = 5;
    arg0->unk_04.unk_58.unk_00 = *arg1;
}

void func_80081364(unk_struct_F8* arg0, unk_redo_3* arg1) {
    arg0->unk_00 = 5;
    arg0->unk_04.unk_00 = arg1->unk_00;
    arg0->unk_04.unk_58.unk_00 = arg1->unk_58;
}

void func_800813E8(unk_struct_F8* arg0) {
    f32* var = arg0->unk_04.unk_00.unk_18;

    var[0] += (var[3] - var[0]) * var[6];
    var[1] += (var[4] - var[1]) * var[6];
    var[2] += (var[5] - var[2]) * var[6];
    var[7] += (var[8] - var[7]) * var[9];
    var[10] += (var[12] - var[10]) * var[14];
    var[11] += (var[13] - var[11]) * var[15];
}

// Likely uses the previously defined structs
void func_8008149C(unk_struct_F8* arg0) {
    unk_struct_20* var2 = &arg0->unk_04.unk_58.unk_00.unk_00.unk_00;
    unk_struct_58* var = &arg0->unk_04.unk_00;

    var->unk_00.x += (var2->unk_00.x - var->unk_00.x) * var2->unk_18;
    var->unk_00.y += (var2->unk_00.y - var->unk_00.y) * var2->unk_18;
    var->unk_00.z += (var2->unk_00.z - var->unk_00.z) * var2->unk_18;
    var->unk_0C.x += (var2->unk_0C.x - var->unk_0C.x) * var2->unk_1C;
    var->unk_0C.y += (var2->unk_0C.y - var->unk_0C.y) * var2->unk_1C;
    var->unk_0C.z += (var2->unk_0C.z - var->unk_0C.z) * var2->unk_1C;
}

void func_80081550(unk_struct_F8* arg0) {
    f32 temp_fa0;
    f32 sp40;
    f32 sp3C;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 temp_v0;
    f32 sp28;
    unk_struct_58* temp_v0_4;
    unk_struct_54* temp_v1 = &arg0->unk_04.unk_58.unk_00.unk_00;

    temp_v1->unk_30.x += (temp_v1->unk_30.y - temp_v1->unk_30.x) * temp_v1->unk_30.z;
    temp_v1->unk_3C.x += (temp_v1->unk_3C.y - temp_v1->unk_3C.x) * temp_v1->unk_3C.z;
    temp_v1->unk_48.x += (temp_v1->unk_48.y - temp_v1->unk_48.x) * temp_v1->unk_48.z;
    temp_v0 = Math_Round(DEG_TO_FZXANG2(temp_v1->unk_3C.x));

    sp3C = temp_v1->unk_30.x * SIN(temp_v0);
    sp40 = temp_v1->unk_30.x * COS(temp_v0);

    temp_v0 = Math_Round(DEG_TO_FZXANG2(temp_v1->unk_48.x));
    temp_fv0 = SIN(temp_v0) * sp40;
    temp_fv1 = COS(temp_v0) * sp40;

    temp_fa0 = (temp_v1->unk_00.unk_0C.x * temp_fv1) + (temp_v1->unk_24.x * temp_fv0) + (temp_v1->unk_00.unk_18 * sp3C);
    temp_ft5 = (temp_v1->unk_00.unk_0C.y * temp_fv1) + (temp_v1->unk_24.y * temp_fv0) + (temp_v1->unk_00.unk_1C * sp3C);
    sp28 = (temp_v1->unk_00.unk_0C.z * temp_fv1) + (temp_v1->unk_24.z * temp_fv0) + (temp_v1->unk_20 * sp3C);

    temp_v0_4 = &arg0->unk_04.unk_00;
    switch (arg0->unk_00) {
        case 2:
            temp_v0_4->unk_00 = temp_v1->unk_00.unk_00;
            temp_v0_4->unk_0C.x = temp_v1->unk_00.unk_00.x + temp_fa0;
            temp_v0_4->unk_0C.y = temp_v1->unk_00.unk_00.y + temp_ft5;
            temp_v0_4->unk_0C.z = temp_v1->unk_00.unk_00.z + sp28;
            break;
        case 3:
            temp_v0_4->unk_0C = temp_v1->unk_00.unk_00;
            temp_v0_4->unk_00.x = temp_v1->unk_00.unk_00.x + temp_fa0;
            temp_v0_4->unk_00.y = temp_v1->unk_00.unk_00.y + temp_ft5;
            temp_v0_4->unk_00.z = temp_v1->unk_00.unk_00.z + sp28;
            break;
    }
}

extern s32 gNumPlayers;
extern s8 D_800DCE5C;

void func_80081794(unk_struct_F8* arg0, unk_struct_1DC* arg1) {
    s32 angle;
    f32 var_fv1;
    f32 spA4;
    Vec3f sp98;
    Vec3f sp8C;
    Racer* racer = &gRacers[arg1->unk_00];
    Vec3f sp7C;
    Vec3f sp70;
    f32 temp_fv0;
    unk_8008112C_arg_1* temp_s1 = &arg0->unk_04;
    unk_struct_9C* temp_s2 = &arg0->unk_04.unk_58;

    temp_s2->unk_68[1] += (temp_s2->unk_68[2] - temp_s2->unk_68[1]) * temp_s2->unk_68[3];
    temp_s2->unk_68[4] += (temp_s2->unk_68[5] - temp_s2->unk_68[4]) * temp_s2->unk_68[6];
    temp_s2->unk_68[7] += (temp_s2->unk_68[8] - temp_s2->unk_68[7]) * temp_s2->unk_68[9];

    arg1->unk_20.x = racer->unk_180.x;
    arg1->unk_20.y = racer->unk_180.y;
    arg1->unk_20.z = racer->unk_180.z;

    var_fv1 = (racer->unk_18C.x * racer->unk_A8.x) + (racer->unk_18C.y * racer->unk_A8.y) +
              (racer->unk_18C.z * racer->unk_A8.z);
    sp98.x = (temp_s2->unk_00.unk_54.x - arg1->unk_20.x) + (var_fv1 * racer->unk_A8.x);
    sp98.y = (temp_s2->unk_00.unk_54.y - arg1->unk_20.y) + (var_fv1 * racer->unk_A8.y);
    sp98.z = (temp_s2->unk_00.unk_54.z - arg1->unk_20.z) + (var_fv1 * racer->unk_A8.z);
    var_fv1 = sqrtf(SQ(sp98.x) + SQ(sp98.y) + SQ(sp98.z));

    if (var_fv1 < 0.01f) {
        return;
    }

    var_fv1 = 1.0f / var_fv1;
    sp98.x *= var_fv1;
    sp98.y *= var_fv1;
    sp98.z *= var_fv1;
    if (D_800DCE5C == 0) {
        temp_fv0 = temp_s2->unk_68[1];
        temp_s2->unk_00.unk_54.x = arg1->unk_20.x + (temp_fv0 * sp98.x);
        temp_s2->unk_00.unk_54.y = arg1->unk_20.y + (temp_fv0 * sp98.y);
        temp_s2->unk_00.unk_54.z = arg1->unk_20.z + (temp_fv0 * sp98.z);
    }

    temp_fv0 = (racer->unk_18C.x * arg1->unk_5C.y.x) + (racer->unk_18C.y * arg1->unk_5C.y.y) +
               (racer->unk_18C.z * arg1->unk_5C.y.z);
    if (temp_s2->unk_68[8] >= 50.0f) {
        var_fv1 = 0.0f;
    } else {
        var_fv1 = (50.0f - temp_s2->unk_68[8]) * 0.02f;
    }

    temp_s1->unk_00.unk_00.x = arg1->unk_20.x + (var_fv1 * (racer->unk_18C.x - (temp_fv0 * arg1->unk_5C.y.x)));
    temp_s1->unk_00.unk_00.y = arg1->unk_20.y + (var_fv1 * (racer->unk_18C.y - (temp_fv0 * arg1->unk_5C.y.y)));
    temp_s1->unk_00.unk_00.z = arg1->unk_20.z + (var_fv1 * (racer->unk_18C.z - (temp_fv0 * arg1->unk_5C.y.z)));
    sp8C.x = racer->unk_A8.x - arg1->unk_2C.y.x;
    sp8C.y = racer->unk_A8.y - arg1->unk_2C.y.y;
    sp8C.z = racer->unk_A8.z - arg1->unk_2C.y.z;

    var_fv1 = sqrtf(SQ(sp8C.x) + SQ(sp8C.y) + SQ(sp8C.z)) * 0.2f;
    arg1->unk_2C.y.x += var_fv1 * sp8C.x;
    temp_s2->unk_00.unk_00.unk_30.x = arg1->unk_2C.y.x;
    arg1->unk_2C.y.y += var_fv1 * sp8C.y;
    temp_s2->unk_00.unk_00.unk_30.y = arg1->unk_2C.y.y;
    arg1->unk_2C.y.z += var_fv1 * sp8C.z;

    temp_s2->unk_00.unk_00.unk_30.z = arg1->unk_2C.y.z;
    sp7C.x = (temp_s2->unk_00.unk_00.unk_30.y * sp98.z) - (temp_s2->unk_00.unk_00.unk_30.z * sp98.y);
    sp7C.y = (temp_s2->unk_00.unk_00.unk_30.z * sp98.x) - (temp_s2->unk_00.unk_00.unk_30.x * sp98.z);
    sp7C.z = (temp_s2->unk_00.unk_00.unk_30.x * sp98.y) - (temp_s2->unk_00.unk_00.unk_30.y * sp98.x);
    var_fv1 = sqrtf(SQ(sp7C.x) + SQ(sp7C.y) + SQ(sp7C.z));
    if (var_fv1 < 0.1f) {
        return;
    }

    var_fv1 = 1.0f / var_fv1;
    sp7C.x *= var_fv1;
    sp7C.y *= var_fv1;
    sp7C.z *= var_fv1;

    sp70.x = (sp98.y * sp7C.z) - (sp98.z * sp7C.y);
    sp70.y = (sp98.z * sp7C.x) - (sp98.x * sp7C.z);
    sp70.z = (sp98.x * sp7C.y) - (sp98.y * sp7C.x);

    var_fv1 = 1.0f / sqrtf(SQ(sp70.x) + SQ(sp70.y) + SQ(sp70.z));

    sp70.x *= var_fv1;
    sp70.y *= var_fv1;
    sp70.z *= var_fv1;
    angle = Math_Round(DEG_TO_FZXANG2(temp_s2->unk_68[4]));

    var_fv1 = temp_s2->unk_68[1] * SIN(angle) *
              ((sp70.x * racer->unk_C0.y.x) + (sp70.y * racer->unk_C0.y.y) + (sp70.z * racer->unk_C0.y.z));
    spA4 = temp_s2->unk_68[1] * COS(angle);

    angle = Math_Round(DEG_TO_FZXANG2(temp_s2->unk_68[8]));
    temp_fv0 = COS(angle) * spA4;
    spA4 = SIN(angle) * spA4;
    temp_s1->unk_00.unk_0C.x = arg1->unk_20.x + (spA4 * sp7C.x) + (temp_fv0 * sp98.x) + (var_fv1 * sp70.x);
    temp_s1->unk_00.unk_0C.y = arg1->unk_20.y + (spA4 * sp7C.y) + (temp_fv0 * sp98.y) + (var_fv1 * sp70.y);
    temp_s1->unk_00.unk_0C.z = arg1->unk_20.z + (spA4 * sp7C.z) + (temp_fv0 * sp98.z) + (var_fv1 * sp70.z);
    temp_s2->unk_00.unk_00.unk_24.x = temp_s1->unk_00.unk_00.x - temp_s1->unk_00.unk_0C.x;
    temp_s2->unk_00.unk_00.unk_24.y = temp_s1->unk_00.unk_00.y - temp_s1->unk_00.unk_0C.y;
    temp_s2->unk_00.unk_00.unk_24.z = temp_s1->unk_00.unk_00.z - temp_s1->unk_00.unk_0C.z;
    func_8006AA38((Mtx3F*) &temp_s2->unk_00.unk_00.unk_24);
    if (D_800DCE5C == 0) {
        temp_s1->unk_00.unk_18[3] = temp_s1->unk_00.unk_18[0] = temp_s2->unk_00.unk_00.unk_30.x;
        temp_s1->unk_00.unk_18[4] = temp_s1->unk_00.unk_18[1] = temp_s2->unk_00.unk_00.unk_30.y;
        temp_s1->unk_00.unk_18[5] = temp_s1->unk_00.unk_18[2] = temp_s2->unk_00.unk_00.unk_30.z;
    }
    temp_s1->unk_00.unk_18[10] = 0.0f;
    temp_s1->unk_00.unk_18[12] = 0.0f;
    if (gNumPlayers == 2) {
        temp_s1->unk_00.unk_18[11] = -15.0f;
        temp_s1->unk_00.unk_18[13] = -15.0f;
    } else {
        temp_s1->unk_00.unk_18[11] = 77.0f;
        temp_s1->unk_00.unk_18[13] = 77.0f;
    }
}

void func_80081E24(unk_struct_F8* arg0) {
    unk_struct_58* var = &arg0->unk_04.unk_00;
    unk_struct_68* var2 = &arg0->unk_04.unk_58.unk_00;

    var2->unk_00.unk_30.x += (var2->unk_00.unk_3C.x - var2->unk_00.unk_30.x) * var2->unk_60;
    var2->unk_00.unk_30.y += (var2->unk_00.unk_3C.y - var2->unk_00.unk_30.y) * var2->unk_60;
    var2->unk_00.unk_30.z += (var2->unk_00.unk_3C.z - var2->unk_00.unk_30.z) * var2->unk_60;

    var2->unk_00.unk_48.x += (var2->unk_54.x - var2->unk_00.unk_48.x) * var2->unk_64;
    var2->unk_00.unk_48.y += (var2->unk_54.y - var2->unk_00.unk_48.y) * var2->unk_64;
    var2->unk_00.unk_48.z += (var2->unk_54.z - var2->unk_00.unk_48.z) * var2->unk_64;

    var->unk_00.x = var2->unk_00.unk_00.unk_00.x + (var2->unk_00.unk_24.x * var2->unk_00.unk_30.x) +
                    (var2->unk_00.unk_00.unk_18 * var2->unk_00.unk_30.y) +
                    (var2->unk_00.unk_00.unk_0C.x * var2->unk_00.unk_30.z);
    var->unk_00.y = var2->unk_00.unk_00.unk_00.y + (var2->unk_00.unk_24.y * var2->unk_00.unk_30.x) +
                    (var2->unk_00.unk_00.unk_1C * var2->unk_00.unk_30.y) +
                    (var2->unk_00.unk_00.unk_0C.y * var2->unk_00.unk_30.z);
    var->unk_00.z = var2->unk_00.unk_00.unk_00.z + (var2->unk_00.unk_24.z * var2->unk_00.unk_30.x) +
                    (var2->unk_00.unk_20 * var2->unk_00.unk_30.y) +
                    (var2->unk_00.unk_00.unk_0C.z * var2->unk_00.unk_30.z);

    var->unk_0C.x = var2->unk_00.unk_00.unk_00.x + (var2->unk_00.unk_24.x * var2->unk_00.unk_48.x) +
                    (var2->unk_00.unk_00.unk_18 * var2->unk_00.unk_48.y) +
                    (var2->unk_00.unk_00.unk_0C.x * var2->unk_00.unk_48.z);
    var->unk_0C.y = var2->unk_00.unk_00.unk_00.y + (var2->unk_00.unk_24.y * var2->unk_00.unk_48.x) +
                    (var2->unk_00.unk_00.unk_1C * var2->unk_00.unk_48.y) +
                    (var2->unk_00.unk_00.unk_0C.y * var2->unk_00.unk_48.z);
    var->unk_0C.z = var2->unk_00.unk_00.unk_00.z + (var2->unk_00.unk_24.z * var2->unk_00.unk_48.x) +
                    (var2->unk_00.unk_20 * var2->unk_00.unk_48.y) +
                    (var2->unk_00.unk_00.unk_0C.z * var2->unk_00.unk_48.z);
}

void func_80082068(unk_struct_F8* arg0, unk_struct_1DC* arg1) {

    switch (arg0->unk_00) {
        case 1:
            func_8008149C(arg0);
            break;
        case 4:
            func_80081794(arg0, arg1);
            break;
        case 2:
        case 3:
            func_80081550(arg0);
            break;
        case 5:
            func_80081E24(arg0);
            break;
    }
    func_800813E8(arg0);
}

void func_800820F4(unk_struct_F8* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    unk_8008112C_arg_1* temp_v0_3 = &arg0->unk_04;
    unk_struct_9C* temp_v0 = &arg0->unk_04.unk_58;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.unk_00.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_00.unk_00.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_00.unk_00.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.unk_0C.x = arg2->x;
        temp_v0->unk_00.unk_00.unk_00.unk_0C.y = arg2->y;
        temp_v0->unk_00.unk_00.unk_00.unk_0C.z = arg2->z;
    }
    if (arg3 != NULL) {
        temp_v0_3->unk_00.unk_18[3] = arg3->x;
        temp_v0_3->unk_00.unk_18[4] = arg3->y;
        temp_v0_3->unk_00.unk_18[5] = arg3->z;
    }
    if (arg4 != NULL) {
        arg0->unk_04.unk_00.unk_18[8] = *arg4;
    }
}

void func_8008217C(unk_struct_F8* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    unk_8008112C_arg_1* temp_v0_3 = &arg0->unk_04;
    unk_struct_9C* temp_v0 = &arg0->unk_04.unk_58;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.unk_00.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_00.unk_00.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_00.unk_00.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_00.unk_00.unk_30.y = arg2->x;
        temp_v0->unk_00.unk_00.unk_48.y = arg2->y;
        temp_v0->unk_00.unk_00.unk_3C.y = arg2->z;
    }
    if (arg3 != NULL) {
        temp_v0_3->unk_00.unk_18[3] = arg3->x;
        temp_v0_3->unk_00.unk_18[4] = arg3->y;
        temp_v0_3->unk_00.unk_18[5] = arg3->z;
    }
    if (arg4 != NULL) {
        arg0->unk_04.unk_00.unk_18[8] = *arg4;
    }
}

void func_80082204(unk_struct_F8* arg0, Vec3f* arg1, Mtx3F* arg2, Vec3f* arg3, Vec3f* arg4, Vec3f* arg5, f32* arg6) {
    unk_struct_58* temp_v0_4 = &arg0->unk_04.unk_00;
    unk_struct_68* temp_v0 = &arg0->unk_04.unk_58.unk_00;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_00.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_00.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_00.unk_00.unk_0C.x += arg2->mf[0][0] * 0.2f;
        temp_v0->unk_00.unk_00.unk_0C.y += arg2->mf[0][1] * 0.2f;
        temp_v0->unk_00.unk_00.unk_0C.z += arg2->mf[0][2] * 0.2f;
        temp_v0->unk_00.unk_00.unk_18 += arg2->mf[1][0] * 0.2f;
        temp_v0->unk_00.unk_00.unk_1C += arg2->mf[1][1] * 0.2f;
        temp_v0->unk_00.unk_20 += arg2->mf[1][2] * 0.2f;
        temp_v0->unk_00.unk_24.x += arg2->mf[2][0] * 0.2f;
        temp_v0->unk_00.unk_24.y += arg2->mf[2][1] * 0.2f;
        temp_v0->unk_00.unk_24.z += arg2->mf[2][2] * 0.2f;
        func_8006AA38((Mtx3F*) &temp_v0->unk_00.unk_00.unk_0C);
    }
    if (arg3 != NULL) {
        temp_v0->unk_00.unk_3C.x = arg3->x;
        temp_v0->unk_00.unk_3C.y = arg3->y;
        temp_v0->unk_00.unk_3C.z = arg3->z;
    }
    if (arg4 != NULL) {
        temp_v0->unk_54.x = arg4->x;
        temp_v0->unk_54.y = arg4->y;
        temp_v0->unk_54.z = arg4->z;
    }
    if (arg5 != NULL) {
        temp_v0_4->unk_18[3] = arg5->x;
        temp_v0_4->unk_18[4] = arg5->y;
        temp_v0_4->unk_18[5] = arg5->z;
    }
    if (arg6 != NULL) {
        temp_v0_4->unk_18[8] = *arg6;
    }
}

void func_800823A0(unk_struct_F8* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    unk_8008112C_arg_1* temp_v0_3 = &arg0->unk_04;
    unk_struct_9C* temp_v0 = &arg0->unk_04.unk_58;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_48.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_48.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_48.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_68[2] = arg2->x;
        temp_v0->unk_68[8] = arg2->y;
        temp_v0->unk_68[5] = arg2->z;
    }
    if (arg3 != NULL) {
        temp_v0_3->unk_00.unk_18[3] = arg3->x;
        temp_v0_3->unk_00.unk_18[4] = arg3->y;
        temp_v0_3->unk_00.unk_18[5] = arg3->z;
    }
    if (arg4 != NULL) {
        arg0->unk_04.unk_00.unk_18[8] = *arg4;
    }
}

f32 func_80082428(CourseSegment** arg0, f32 arg1, f32 arg2) {
    f32 temp_fs3;
    s32 i;
    s32 sp54;
    s32 pad[4];
    Vec3f sp80;
    Mtx3F sp5C;

    sp54 = (s32) arg2 / 20;
    temp_fs3 = func_8009E85C(*arg0, arg1, &sp5C, 0.0f);

    for (i = 0; i < sp54; i++) {
        arg1 += 20.0f / temp_fs3;
        if (arg1 >= 1.0f) {
            *arg0 = (*arg0)->next;
            arg1 -= 1.0f;
            arg1 *= (temp_fs3 / func_8009E538(*arg0, 0.0f, &sp80));
        }
    }

    arg1 += ((arg2 - ((f32) sp54 * 20.0f)) / temp_fs3);
    if (arg1 >= 1.0f) {
        *arg0 = (*arg0)->next;
        arg1 -= 1.0f;
        arg1 *= (temp_fs3 / func_8009E538(*arg0, 0.0f, &sp80));
    }
    return arg1;
}

Mtx3F* func_800825A4(Mtx3F* arg0, CourseSegment* arg1, f32 arg2) {
    s32 pad;
    f32 sp40;
    Mtx3F sp1C;

    func_8009E85C(arg1, arg2, &sp1C, func_8009E108(arg1, arg2, &sp40));
    *arg0 = sp1C;

    return arg0;
}

void func_80082624(unk_struct_1DC* arg0, unk_8008112C_arg_1* arg1, unk_struct_9C* arg2, s32 arg3) {
    Vec3f* var_v0;

    if (arg3 == 2) {
        var_v0 = &D_800D5328[arg0->unk_08];
    } else {
        var_v0 = &D_800D52F8[arg0->unk_08];
    }
    arg2->unk_68[2] = var_v0->y;
    arg2->unk_68[5] = var_v0->z;
    arg1->unk_00.unk_18[8] = arg0->unk_14 = var_v0->x;

    arg0->unk_10 = 2;

    switch (arg0->unk_08) {
        case 1:
        case 2:
            arg0->unk_10 |= 1;
            break;
        default:
            break;
    }
}

void func_800826B8(unk_struct_1DC* arg0, unk_struct_F8* arg1) {
    arg0->unk_50 = arg1->unk_04.unk_00.unk_0C;

    arg0->unk_88 = arg1->unk_04.unk_00.unk_00;

    arg0->unk_5C.mf[1][0] = arg1->unk_04.unk_00.unk_18[0];
    arg0->unk_5C.mf[1][1] = arg1->unk_04.unk_00.unk_18[1];
    arg0->unk_5C.mf[1][2] = arg1->unk_04.unk_00.unk_18[2];
    arg0->unk_94.x = arg1->unk_04.unk_00.unk_18[7];
    arg0->unk_94.y = arg1->unk_04.unk_00.unk_18[10];
    arg0->unk_94.z = arg1->unk_04.unk_00.unk_18[11];
}

void func_8008271C(unk_struct_1DC* arg0) {
    Mtx3F* temp_a0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;

    arg0->unk_5C.mf[0][0] = arg0->unk_88.x - arg0->unk_50.x;
    arg0->unk_5C.mf[0][1] = arg0->unk_88.y - arg0->unk_50.y;
    arg0->unk_5C.mf[0][2] = arg0->unk_88.z - arg0->unk_50.z;

    func_8006AA38(&arg0->unk_5C);
    temp_fv0 = arg0->unk_5C.mf[0][0];
    temp_fv1 = arg0->unk_5C.mf[0][2];
    temp_fv0_2 = sqrtf(SQ(temp_fv0) + SQ(temp_fv1));
    if (temp_fv0_2 != 0.0f) {
        arg0->unk_80 = (f32) (arg0->unk_5C.mf[0][0] / temp_fv0_2);
        arg0->unk_84 = (f32) (arg0->unk_5C.mf[0][2] / temp_fv0_2);
    }
}

void func_800827C4(MtxF* arg0, MtxF* arg1, MtxF* arg2) {
    arg0->m[0][0] = (arg1->m[0][0] * arg2->m[0][0]) + (arg1->m[2][0] * arg2->m[0][2]);
    arg0->m[0][1] = (arg1->m[1][1] * arg2->m[0][1]) + (arg1->m[2][1] * arg2->m[0][2]);
    arg0->m[0][2] = arg1->m[2][2] * arg2->m[0][2];
    arg0->m[0][3] = -arg2->m[0][2];
    arg0->m[1][0] = (arg1->m[0][0] * arg2->m[1][0]) + (arg1->m[2][0] * arg2->m[1][2]);
    arg0->m[1][1] = (arg1->m[1][1] * arg2->m[1][1]) + (arg1->m[2][1] * arg2->m[1][2]);
    arg0->m[1][2] = arg1->m[2][2] * arg2->m[1][2];
    arg0->m[1][3] = -arg2->m[1][2];
    arg0->m[2][0] = (arg1->m[0][0] * arg2->m[2][0]) + (arg1->m[2][0] * arg2->m[2][2]);
    arg0->m[2][1] = (arg1->m[1][1] * arg2->m[2][1]) + (arg1->m[2][1] * arg2->m[2][2]);
    arg0->m[2][2] = arg1->m[2][2] * arg2->m[2][2];
    arg0->m[2][3] = -arg2->m[2][2];
    arg0->m[3][0] = (arg1->m[0][0] * arg2->m[3][0]) + (arg1->m[2][0] * arg2->m[3][2]);
    arg0->m[3][1] = (arg1->m[1][1] * arg2->m[3][1]) + (arg1->m[2][1] * arg2->m[3][2]);
    arg0->m[3][2] = (arg1->m[2][2] * arg2->m[3][2]) + arg1->m[3][2];
    arg0->m[3][3] = -arg2->m[3][2];
}

void func_80082960(MtxF* arg0, Mtx* arg1) {
    s32 pad[4];
    s64 var_v1;
    f32 temp_fv0;
    s32 i;
    s32 j;

    for (i = 3; i >= 0; i--) {
        for (j = 3; j >= 0; j--) {
            temp_fv0 = arg0->m[i][j] * 65536.0f;
            if (temp_fv0 < 0.0f) {
                var_v1 = temp_fv0 - 0.5f;
            } else {
                var_v1 = temp_fv0 + 0.5f;
            }

            if (arg1) {}
            arg1->u.i[i][j] = var_v1 >> 0x10;
            arg1->u.f[i][j] = var_v1 & 0xFFFF;
        }
    }
}

extern s32 D_800CCFB0;

void func_80082A6C(GfxPool* arg0, unk_struct_1DC* arg1) {
    Vec3f sp64;
    Vec3f sp58;
    f32 var_fv0;
    f32 var_fv1;

    func_8006D03C(&arg0->unk_20008[arg1->unk_00], &arg1->unk_11C, arg1->unk_94.x, arg1->unk_A0, arg1->unk_A4,
                  arg1->unk_A8, arg1->unk_94.y, arg1->unk_AC, arg1->unk_94.z, &arg1->unk_118);

    if (D_800E5E8C != 0) {
        var_fv0 = D_800CD8AC;
        var_fv1 = D_800CD8A8;
        if (D_800CCFB0 & 1) {
            var_fv0 = 0.0f - var_fv0;
            var_fv1 = 0.0f - var_fv1;
        }
        sp58.x = arg1->unk_50.x + (arg1->unk_5C.xz * var_fv0);
        sp58.y = arg1->unk_50.y + (arg1->unk_5C.yz * var_fv0);
        sp58.z = arg1->unk_50.z + (arg1->unk_5C.zz * var_fv0);
        sp64.x = arg1->unk_88.x + (arg1->unk_5C.xz * var_fv1);
        sp64.y = arg1->unk_88.y + (arg1->unk_5C.yz * var_fv1);
        sp64.z = arg1->unk_88.z + (arg1->unk_5C.zz * var_fv1);
    } else {
        sp58 = arg1->unk_50;
        sp64 = arg1->unk_88;
    }

    func_8006CC98(&arg0->unk_20108[arg1->unk_00], &arg1->unk_15C, sp58.x, sp58.y, sp58.z, sp64.x, sp64.y, sp64.z,
                  arg1->unk_5C.mf[1][0], arg1->unk_5C.mf[1][1], arg1->unk_5C.mf[1][2]);

    func_800827C4(&arg1->unk_19C, &arg1->unk_11C, &arg1->unk_15C);
    func_80082960(&arg1->unk_19C, &arg0->unk_20208[arg1->unk_00]);
}

void func_80082C80(unk_struct_1DC* arg0) {
    s32 pad[3];
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fa0;
    f32 var_fv1;
    Racer* temp_v0;

    temp_v0 = &gRacers[D_800E5FB8];
    temp_fa1 = temp_v0->unk_0C.unk_34.x - arg0->unk_50.x;
    temp_ft4 = temp_v0->unk_0C.unk_34.y - arg0->unk_50.y;
    temp_ft5 = temp_v0->unk_0C.unk_34.z - arg0->unk_50.z;

    var_fv1 = sqrtf(SQ(temp_fa1) + SQ(temp_ft4) + SQ(temp_ft5));

    if (var_fv1 != 0.0f) {
        temp_fa0 =
            (-((temp_fa1 * arg0->unk_5C.xz) + (temp_ft4 * arg0->unk_5C.yz) + (temp_ft5 * arg0->unk_5C.zz))) / var_fv1;
        var_fv1 *= temp_fa0;
    }
    if ((var_fv1 >= -1000.0f) && (var_fv1 <= 1000.0f)) {
        func_800BA2D0(((var_fv1 + 1000.0f) / 2000.0f) * 127.0f);
    }
}

void func_80082E40(f32* x, f32* y, f32* z) {
    f32 normalizeScale;

    normalizeScale = 1.0f / (SQ(*x) + SQ(*y) + SQ(*z));
    *x *= normalizeScale;
    *y *= normalizeScale;
    *z *= normalizeScale;
}

void func_80082E90(MtxF* mtxF, f32 angle, f32 x, f32 y, f32 z) {
    s32 pad[2];
    f32 temp_fa0;
    f32 temp_ft1;
    f32 cos;
    f32 sp18;
    f32 temp_fv0;
    f32 sin;
    s32 temp_v0;

    func_80082E40(&x, &y, &z);
    temp_v0 = Math_Round(DEG_TO_FZXANG2(angle));
    sin = SIN(temp_v0);
    cos = COS(temp_v0);
    temp_fv0 = 1.0f - cos;
    temp_ft1 = x * y * temp_fv0;
    temp_fa0 = y * z * temp_fv0;
    sp18 = z * x * temp_fv0;
    mtxF->m[0][0] = ((1.0f - SQ(x)) * cos) + SQ(x);
    mtxF->m[2][1] = temp_fa0 - (x * sin);
    mtxF->m[1][2] = (x * sin) + temp_fa0;
    mtxF->m[1][1] = ((1.0f - SQ(y)) * cos) + SQ(y);
    mtxF->m[2][0] = (y * sin) + sp18;
    mtxF->m[0][2] = sp18 - (y * sin);
    mtxF->m[2][2] = ((1.0f - SQ(z)) * cos) + SQ(z);
    mtxF->m[1][0] = temp_ft1 - (z * sin);
    mtxF->m[0][1] = (z * sin) + temp_ft1;
    mtxF->m[3][3] = 1.0f;
    mtxF->m[0][3] = mtxF->m[1][3] = mtxF->m[2][3] = mtxF->m[3][0] = mtxF->m[3][1] = mtxF->m[3][2] = 0.0f;
}

typedef struct unk_800832EC_arg_2 {
    u32 unk_00;
    u32 unk_04;
    s32* unk_08;
    u8* unk_0C;
} unk_800832EC_arg_2;

void func_80083034(unk_800832EC_arg_2* arg0) {
    u32 i;

    for (i = 0; i < arg0->unk_04; i++) {
        arg0->unk_08[i] = 0;
    }
}

u8* func_80083074(u32 arg0, unk_800832EC_arg_2* arg1) {
    s32 var_v0;
    u32 temp_a2;
    u32 temp_v0;
    s32 var_a0;
    u32 var_a3;

    if ((arg0 % arg1->unk_00) != 0) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }

    temp_a2 = var_v0 + (arg0 / arg1->unk_00);
    if (arg1->unk_04 < temp_a2) {
        return NULL;
    }

    temp_v0 = (arg1->unk_04 - temp_a2) + 1;

    for (var_a0 = 0; var_a0 < temp_v0; var_a0++) {
        for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
            if (arg1->unk_08[var_a0 + var_a3] != 0) {
                break;
            }
        }
        if (var_a3 >= temp_a2) {
            for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
                arg1->unk_08[var_a0 + var_a3] = temp_a2 - var_a3;
            }
            return &arg1->unk_0C[arg1->unk_00 * var_a0];
        }
    }
    return NULL;
}

void func_80083210(u8* arg0, unk_800832EC_arg_2* arg1) {
    s32 temp_v1;
    u32 i;
    u32 temp_lo;

    if (arg0 != NULL) {
        temp_lo = (size_t) (arg0 - arg1->unk_0C) / arg1->unk_00;
        temp_v1 = arg1->unk_08[temp_lo];

        for (i = 0; i < temp_v1; i++) {
            arg1->unk_08[temp_lo + i] = 0;
        }
    }
}

u8* func_800832EC(u8* arg0, u32 arg1, unk_800832EC_arg_2* arg2) {
    u8* temp_v0;
    u32 var_a2;
    s32 var_v1;

    temp_v0 = func_80083074(arg1, arg2);
    if (temp_v0 == NULL) {
        return NULL;
    }
    if (arg0 == NULL) {
        return temp_v0;
    }
    var_v1 = arg2->unk_08[(size_t) (arg0 - arg2->unk_0C) / arg2->unk_00];
    var_a2 = arg2->unk_00 * var_v1;
    if (arg1 < var_a2) {
        var_a2 = arg1;
    }

    bcopy(arg0, temp_v0, var_a2);
    func_80083210(arg0, arg2);
    return temp_v0;
}

extern s32 gGameMode;
extern GfxPool D_1000000;

Gfx* func_800833AC(Gfx* gfx, s32 arg1, s32 playerIndex) {
    unk_struct_1DC* temp_v0 = &D_800E5220[playerIndex];

    switch (temp_v0->unk_E0) {
        case 1:
            gSPViewport(gfx++, &D_1000000.unk_2C2C8[playerIndex]);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, temp_v0->unk_B0, temp_v0->unk_B4, temp_v0->unk_B8, temp_v0->unk_BC);
            break;
        default:
            gfx = func_8006A00C(gfx, arg1);
            if ((gNumPlayers == 1) && (gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS)) {
                gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
            }
            break;
    }

    return gfx;
}

void func_80083500(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {

    D_800E5990[arg0].unk_04.unk_58.unk_68[1] = D_800E5990[arg0].unk_04.unk_58.unk_68[2] = arg1;
    D_800E5990[arg0].unk_04.unk_58.unk_68[4] = D_800E5990[arg0].unk_04.unk_58.unk_68[5] = arg2;
    D_800E5990[arg0].unk_04.unk_58.unk_68[7] = D_800E5990[arg0].unk_04.unk_58.unk_68[8] = arg3;
}

void func_80083548(unk_800E5D70* arg0, unk_struct_F8* arg1) {
    arg0->unk_00 = arg1;
}

void func_80083550(unk_800E5D70* arg0, unk_struct_20_2* arg1) {
    arg0->unk_0C = arg1;
}

void func_80083558(unk_800E5D70* arg0, Vec3f* arg1, Mtx3F* arg2, Racer* arg3) {
    arg0->unk_10 = arg1;
    arg0->unk_14 = arg2;
    arg0->unk_18 = arg3;
}

void func_80083568(unk_800E5D70* arg0, Vec3f* arg1, Mtx3F* arg2) {
    arg0->unk_1C = arg1;
    arg0->unk_20 = arg2;
}

void func_80083574(unk_800E5D70* arg0, unk_struct_C* arg1) {
    arg0->unk_04 = arg1;
    arg0->unk_08 = 0;
}

void func_80084CDC(unk_struct_20_2* arg0, s32 arg1);

void func_80083580(unk_800E5D70* arg0, s32 arg1) {
    func_80084CDC(arg0->unk_0C, arg1);
}

void func_800835A0(unk_800E5D70* arg0, f32* arg1) {
    arg0->unk_00->unk_04.unk_00.unk_18[13] = *arg1;
}

bool func_800835B0(unk_800E5D70* arg0) {
    bool ret;
    unk_struct_C* var_s0;

    while (true) {
        ret = false;
        var_s0 = arg0->unk_04;
        if (var_s0 == NULL) {
            return true;
        }

        if (var_s0->unk_04 != NULL) {
            ((void (*)(unk_800E5D70*, void*)) var_s0->unk_04)(arg0, var_s0->unk_08);
        }
        switch (var_s0->unk_00) {
            case 0:
                arg0->unk_04++;
                continue;
            case -1:
                arg0->unk_08 = 0;
                var_s0 = NULL;
                ret = true;
                break;
            case -2:
                arg0->unk_08++;
                ret = true;
                break;
            default:
                if (++arg0->unk_08 >= var_s0->unk_00) {
                    var_s0++;
                    arg0->unk_08 = 0;
                }
                break;
        }
        break;
    }

    arg0->unk_04 = var_s0;
    return ret;
}

void func_800836A4(unk_800E5D70* arg0, unk_redo_1* arg1) {
    func_8008112C(arg0->unk_00, arg1);
}

void func_800836C4(unk_800E5D70* arg0, unk_redo_2* arg1) {
    func_800812A4(arg0->unk_00, 2, arg1);
}

void func_800836EC(unk_800E5D70* arg0, unk_redo_2* arg1) {
    func_800812A4(arg0->unk_00, 3, arg1);
}

void func_80083714(unk_800E5D70* arg0, unk_8008112C_arg_1* arg1) {
    func_800811F0(arg0->unk_00, arg1);
}

void func_80083734(unk_800E5D70* arg0, unk_redo_3* arg1) {
    func_80081364(arg0->unk_00, arg1);
}

void func_80085390(Vec3f*, unk_struct_20_2*, unk_struct_14*);

void func_80083754(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp38[2];
    Vec3f sp2C;

    func_80085390(sp38, arg0->unk_0C, arg1);
    sp2C.x = sp38[0].x + arg0->unk_10->x;
    sp2C.y = sp38[0].y + arg0->unk_10->y;
    sp2C.z = sp38[0].z + arg0->unk_10->z;
    func_800820F4(arg0->unk_00, &sp2C, &sp38[1], NULL, NULL);
}

void func_800853D4(Vec3f*, unk_struct_20_2*, unk_struct_14*);

void func_800837DC(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp34[3];
    Vec3f sp28;

    func_800853D4(sp34, arg0->unk_0C, arg1);
    sp28.x = sp34[0].x + arg0->unk_10->x;
    sp28.y = sp34[0].y + arg0->unk_10->y;
    sp28.z = sp34[0].z + arg0->unk_10->z;
    func_800820F4(arg0->unk_00, &sp28, &sp34[1], &sp34[2], NULL);
}

void func_80085434(unk_80085434_arg_0*, unk_struct_20_2*, unk_80085434_arg_2*);

void func_80083864(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp34;
    Vec3f sp28;

    func_80085434(&sp34, arg0->unk_0C, arg1);
    sp28.x = sp34.unk_00[0].x + arg0->unk_10->x;
    sp28.y = sp34.unk_00[0].y + arg0->unk_10->y;
    sp28.z = sp34.unk_00[0].z + arg0->unk_10->z;
    func_800820F4(arg0->unk_00, &sp28, &sp34.unk_00[1], NULL, &sp34.unk_18);
}

void func_80085494(unk_80085494_arg_0*, unk_struct_20_2*, unk_80085494_arg_2*);

void func_800838F0(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp38;
    Vec3f sp2C;

    func_80085494(&sp38, arg0->unk_0C, arg1);
    sp2C.x = sp38.unk_00[0].x + arg0->unk_10->x;
    sp2C.y = sp38.unk_00[0].y + arg0->unk_10->y;
    sp2C.z = sp38.unk_00[0].z + arg0->unk_10->z;
    func_800820F4(arg0->unk_00, &sp2C, &sp38.unk_00[1], &sp38.unk_00[2], &sp38.unk_24);
}

void func_8008397C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp48[2];
    Vec3f sp3C;
    Vec3f sp30;

    func_80085390(sp48, arg0->unk_0C, arg1);
    sp3C.x = sp48[0].x + arg0->unk_10->x;
    sp3C.y = sp48[0].y + arg0->unk_10->y;
    sp3C.z = sp48[0].z + arg0->unk_10->z;

    sp30.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp48[1].z + arg0->unk_20->mf[1][0] * sp48[1].y +
             arg0->unk_20->mf[2][0] * sp48[1].x;
    sp30.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp48[1].z + arg0->unk_20->mf[1][1] * sp48[1].y +
             arg0->unk_20->mf[2][1] * sp48[1].x;
    sp30.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp48[1].z + arg0->unk_20->mf[1][2] * sp48[1].y +
             arg0->unk_20->mf[2][2] * sp48[1].x;
    func_800820F4(arg0->unk_00, &sp3C, &sp30, NULL, NULL);
}

void func_80083AAC(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp44[3];
    Vec3f sp38;
    Vec3f sp2C;

    func_800853D4(sp44, arg0->unk_0C, arg1);
    sp38.x = sp44[0].x + arg0->unk_10->x;
    sp38.y = sp44[0].y + arg0->unk_10->y;
    sp38.z = sp44[0].z + arg0->unk_10->z;

    sp2C.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp44[1].z + arg0->unk_20->mf[1][0] * sp44[1].y +
             arg0->unk_20->mf[2][0] * sp44[1].x;
    sp2C.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp44[1].z + arg0->unk_20->mf[1][1] * sp44[1].y +
             arg0->unk_20->mf[2][1] * sp44[1].x;
    sp2C.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp44[1].z + arg0->unk_20->mf[1][2] * sp44[1].y +
             arg0->unk_20->mf[2][2] * sp44[1].x;
    func_800820F4(arg0->unk_00, &sp38, &sp2C, &sp44[2], NULL);
}

void func_80083BDC(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp44;
    Vec3f sp38;
    Vec3f sp2C;

    func_80085434(&sp44, arg0->unk_0C, arg1);
    sp38.x = sp44.unk_00[0].x + arg0->unk_10->x;
    sp38.y = sp44.unk_00[0].y + arg0->unk_10->y;
    sp38.z = sp44.unk_00[0].z + arg0->unk_10->z;

    sp2C.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp44.unk_00[1].z + arg0->unk_20->mf[1][0] * sp44.unk_00[1].y +
             arg0->unk_20->mf[2][0] * sp44.unk_00[1].x;
    sp2C.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp44.unk_00[1].z + arg0->unk_20->mf[1][1] * sp44.unk_00[1].y +
             arg0->unk_20->mf[2][1] * sp44.unk_00[1].x;
    sp2C.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp44.unk_00[1].z + arg0->unk_20->mf[1][2] * sp44.unk_00[1].y +
             arg0->unk_20->mf[2][2] * sp44.unk_00[1].x;
    func_800820F4(arg0->unk_00, &sp38, &sp2C, NULL, &sp44.unk_18);
}

void func_80083D10(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp48;
    Vec3f sp3C;
    Vec3f sp30;

    func_80085494(&sp48, arg0->unk_0C, arg1);
    sp3C.x = sp48.unk_00[0].x + arg0->unk_10->x;
    sp3C.y = sp48.unk_00[0].y + arg0->unk_10->y;
    sp3C.z = sp48.unk_00[0].z + arg0->unk_10->z;

    sp30.x = arg0->unk_1C->x + arg0->unk_20->mf[0][0] * sp48.unk_00[1].z + arg0->unk_20->mf[1][0] * sp48.unk_00[1].y +
             arg0->unk_20->mf[2][0] * sp48.unk_00[1].x;
    sp30.y = arg0->unk_1C->y + arg0->unk_20->mf[0][1] * sp48.unk_00[1].z + arg0->unk_20->mf[1][1] * sp48.unk_00[1].y +
             arg0->unk_20->mf[2][1] * sp48.unk_00[1].x;
    sp30.z = arg0->unk_1C->z + arg0->unk_20->mf[0][2] * sp48.unk_00[1].z + arg0->unk_20->mf[1][2] * sp48.unk_00[1].y +
             arg0->unk_20->mf[2][2] * sp48.unk_00[1].x;
    func_800820F4(arg0->unk_00, &sp3C, &sp30, &sp48.unk_00[2], &sp48.unk_24);
}

void func_80083E44(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80085390(sp20, arg0->unk_0C, arg1);
    func_800820F4(arg0->unk_00, &sp20[0], &sp20[1], NULL, NULL);
}

void func_80083E90(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_800853D4(sp24, arg0->unk_0C, arg1);
    func_800820F4(arg0->unk_00, &sp24[0], &sp24[1], &sp24[2], NULL);
}

void func_80083EDC(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp24;

    func_80085434(&sp24, arg0->unk_0C, arg1);
    func_800820F4(arg0->unk_00, &sp24.unk_00[0], &sp24.unk_00[1], NULL, &sp24.unk_18);
}

void func_80083F2C(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp20;

    func_80085494(&sp20, arg0->unk_0C, arg1);
    func_800820F4(arg0->unk_00, &sp20.unk_00[0], &sp20.unk_00[1], &sp20.unk_00[2], &sp20.unk_24);
}

void func_80083F7C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80085390(sp20, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp20[0], &sp20[1], NULL, NULL);
}

void func_80083FC8(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_800853D4(sp24, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp24[0], &sp24[1], &sp24[2], NULL);
}

void func_80084014(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp24;

    func_80085434(&sp24, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp24.unk_00[0], &sp24.unk_00[1], NULL, &sp24.unk_18);
}

void func_80084064(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp20;

    func_80085494(&sp20, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp20.unk_00[0], &sp20.unk_00[1], &sp20.unk_00[2], &sp20.unk_24);
}

void func_800840B4(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80085390(sp20, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp20[1], &sp20[0], NULL, NULL);
}

void func_80084100(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_800853D4(sp24, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp24[1], &sp24[0], &sp24[2], NULL);
}

void func_8008414C(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp24;

    func_80085434(&sp24, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp24.unk_00[1], &sp24.unk_00[0], NULL, &sp24.unk_18);
}

void func_8008419C(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp20;

    func_80085494(&sp20, arg0->unk_0C, arg1);
    func_8008217C(arg0->unk_00, &sp20.unk_00[1], &sp20.unk_00[0], &sp20.unk_00[2], &sp20.unk_24);
}

void func_800841EC(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 sp64;
    s32 temp_v0;
    f32 sp5C;
    f32 sp58;
    f32 temp_fv0;
    Vec3f sp3C[2];
    Vec3f sp30;
    s32 pad;

    func_80085390(sp3C, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp64 = Math_Round(DEG_TO_FZXANG2(sp5C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp58));
    temp_fv0 = COS(temp_v0) * sp3C[0].x;
    sp30.x = COS(sp64) * temp_fv0 + arg0->unk_10->x;
    sp30.y = sp3C[0].x * SIN(temp_v0) + arg0->unk_10->y;
    sp30.z = arg0->unk_10->z - SIN(sp64) * temp_fv0;
    func_8008217C(arg0->unk_00, &sp30, &sp3C[1], NULL, NULL);
}

void func_80084304(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 sp6C;
    s32 temp_v0;
    f32 sp64;
    f32 sp60;
    f32 temp_fv0;
    Vec3f sp38[3];
    Vec3f sp2C;
    s32 pad;

    func_800853D4(sp38, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp6C = Math_Round(DEG_TO_FZXANG2(sp64));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp60));
    temp_fv0 = COS(temp_v0) * sp38[0].x;
    sp2C.x = COS(sp6C) * temp_fv0 + arg0->unk_10->x;
    sp2C.y = sp38[0].x * SIN(temp_v0) + arg0->unk_10->y;
    sp2C.z = arg0->unk_10->z - SIN(sp6C) * temp_fv0;
    func_8008217C(arg0->unk_00, &sp2C, &sp38[1], &sp38[2], NULL);
}

void func_8008441C(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 sp64;
    s32 temp_v0;
    f32 sp5C;
    f32 sp58;
    f32 temp_fv0;
    unk_80085434_arg_0 sp38;
    Vec3f sp2C;
    s32 pad;

    func_80085434(&sp38, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp64 = Math_Round(DEG_TO_FZXANG2(sp5C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp58));
    temp_fv0 = COS(temp_v0) * sp38.unk_00[0].x;
    sp2C.x = COS(sp64) * temp_fv0 + arg0->unk_10->x;
    sp2C.y = sp38.unk_00[0].x * SIN(temp_v0) + arg0->unk_10->y;
    sp2C.z = arg0->unk_10->z - SIN(sp64) * temp_fv0;
    func_8008217C(arg0->unk_00, &sp2C, &sp38.unk_00[1], NULL, &sp38.unk_18);
}

void func_80084538(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    s32 sp74;
    s32 temp_v0;
    f32 sp6C;
    f32 sp68;
    f32 temp_fv0;
    unk_80085494_arg_0 sp3C;
    Vec3f sp30;
    s32 pad;

    func_80085494(&sp3C, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp74 = Math_Round(DEG_TO_FZXANG2(sp6C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp68));
    temp_fv0 = COS(temp_v0) * sp3C.unk_00[0].x;
    sp30.x = COS(sp74) * temp_fv0 + arg0->unk_10->x;
    sp30.y = sp3C.unk_00[0].x * SIN(temp_v0) + arg0->unk_10->y;
    sp30.z = arg0->unk_10->z - SIN(sp74) * temp_fv0;
    func_8008217C(arg0->unk_00, &sp30, &sp3C.unk_00[1], &sp3C.unk_00[2], &sp3C.unk_24);
}

void func_80084654(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 pad;
    Vec3f sp64[2];
    Vec3f sp58;
    Mtx3F sp34;

    func_80085390(sp64, arg0->unk_0C, arg1->unk_00);
    sp58.x = arg0->unk_10->x;
    sp58.y = arg0->unk_10->y;
    sp58.z = arg0->unk_10->z;
    sp34 = *arg0->unk_14;
    func_80082204(arg0->unk_00, &sp58, &sp34, &sp64[0], &sp64[1], NULL, NULL);
}

void func_80084700(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad;
    Vec3f sp60[3];
    Vec3f sp54;
    Mtx3F sp30;

    func_800853D4(sp60, arg0->unk_0C, arg1);
    sp54.x = arg0->unk_10->x;
    sp54.y = arg0->unk_10->y;
    sp54.z = arg0->unk_10->z;
    sp30 = *arg0->unk_14;
    func_80082204(arg0->unk_00, &sp54, &sp30, &sp60[0], &sp60[1], &sp60[2], NULL);
}

void func_800847B0(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 pad;
    unk_80085434_arg_0 sp60;
    Vec3f sp54;
    Mtx3F sp30;

    func_80085434(&sp60, arg0->unk_0C, arg1);
    sp54.x = arg0->unk_10->x;
    sp54.y = arg0->unk_10->y;
    sp54.z = arg0->unk_10->z;
    sp30 = *arg0->unk_14;
    func_80082204(arg0->unk_00, &sp54, &sp30, &sp60.unk_00[0], &sp60.unk_00[1], NULL, &sp60.unk_18);
}

void func_80084860(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    s32 pad;
    unk_80085494_arg_0 sp64;
    Vec3f sp58;
    Mtx3F sp34;

    func_80085494(&sp64, arg0->unk_0C, arg1);
    sp58.x = arg0->unk_10->x;
    sp58.y = arg0->unk_10->y;
    sp58.z = arg0->unk_10->z;
    sp34 = *arg0->unk_14;
    func_80082204(arg0->unk_00, &sp58, &sp34, &sp64.unk_00[0], &sp64.unk_00[1], &sp64.unk_00[2], &sp64.unk_24);
}

// TODO: sort out unk_struct_20 and unk_struct_68 (conflicting struct copies)
void func_80084914(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    Vec3f sp38[2];
    Vec3f sp2C;

    func_80085390(sp38, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->speed;
    temp_v0->unk_98 = temp_v1->unk_0C.courseSegment->trackSegmentInfo;
    sp2C.x = sp38[0].x + arg0->unk_10->x;
    sp2C.y = sp38[0].y + arg0->unk_10->y;
    sp2C.z = sp38[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp2C, &sp38[1], 0, 0);
}

void func_80084A04(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    Vec3f sp34[3];
    Vec3f sp28;

    func_800853D4(sp34, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->speed;
    temp_v0->unk_98 = temp_v1->unk_0C.courseSegment->trackSegmentInfo;
    sp28.x = sp34[0].x + arg0->unk_10->x;
    sp28.y = sp34[0].y + arg0->unk_10->y;
    sp28.z = sp34[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp28, &sp34[1], &sp34[2], 0);
}

void func_80084AF4(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 pad[6];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    unk_80085434_arg_0 sp34;
    Vec3f sp28;

    func_80085434(&sp34, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->speed;
    temp_v0->unk_98 = temp_v1->unk_0C.courseSegment->trackSegmentInfo;
    sp28.x = sp34.unk_00[0].x + arg0->unk_10->x;
    sp28.y = sp34.unk_00[0].y + arg0->unk_10->y;
    sp28.z = sp34.unk_00[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp28, &sp34.unk_00[1], 0, &sp34.unk_18);
}

void func_80084BE8(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    unk_80085494_arg_0 sp38;
    Vec3f sp2C;

    func_80085494(&sp38, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->speed;
    temp_v0->unk_98 = temp_v1->unk_0C.courseSegment->trackSegmentInfo;
    sp2C.x = sp38.unk_00[0].x + arg0->unk_10->x;
    sp2C.y = sp38.unk_00[0].y + arg0->unk_10->y;
    sp2C.z = sp38.unk_00[0].z + arg0->unk_10->z;

    func_800823A0(arg0->unk_00, &sp2C, &sp38.unk_00[1], &sp38.unk_00[2], &sp38.unk_24);
}

void func_80084CDC(unk_struct_20_2* arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        arg0->unk_00[i].unk_04 = 0;
        arg0->unk_00[i].unk_00 = 0;
    }
}

f32 func_80084D50(f32 arg0, s32 arg1, f32* arg2, s32 arg3) {
    s32 pad[2];
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 sp4;

    if (arg1 == 0) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        sp4 = CB(temp_fv0);
        temp_fa1 = temp_fv1 * arg0;
        sp8 = (((temp_fa1 * 21.0f) / 12.0f) - (temp_fv1 * 9.0f / 2.0f)) + (arg0 * 3.0f);
        spC = ((-temp_fa1 * 11.0f) / 12.0f) + (temp_fv1 * 3.0f / 2.0f);
        sp10 = temp_fa1 / 6.0f;
    } else if (arg1 == 1) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        sp4 = CB(temp_fv0) / 4.0f;
        temp_fa1 = temp_fv1 * arg0;
        sp8 = (((temp_fa1 * 7.0f) / 12.0f) - (temp_fv1 * 5.0f / 4.0f)) + (arg0 / 4.0f) + 7.0f / 12.0f;
        spC = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (arg0 / 2.0f) + 1.0f / 6.0f;
        sp10 = temp_fa1 / 6.0f;
    } else if ((arg3 < 7) || (arg1 < (arg3 - 5))) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        temp_fa1 = temp_fv1 * arg0;
        sp4 = CB(temp_fv0) / 6.0f;
        sp8 = ((temp_fa1 / 2.0f) - temp_fv1) + 2.0f / 3.0f;
        spC = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (arg0 / 2.0f) + 1.0f / 6.0f;
        sp10 = temp_fa1 / 6.0f;
    } else if (arg1 == arg3 - 5) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = temp_fv0 * temp_fv0;
        temp_fa1 = temp_fv1 * temp_fv0;
        sp4 = temp_fa1 / 6.0f;
        sp8 = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (temp_fv0 / 2.0f) + 1.0f / 6.0f;
        spC = (((temp_fa1 * 7.0f) / 12.0f) - (temp_fv1 * 5.0f / 4.0f)) + (temp_fv0 / 4.0f) + 7.0f / 12.0f;
        sp10 = CB(arg0) / 4.0f;
    } else if (arg1 == arg3 - 4) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = temp_fv0 * temp_fv0;
        temp_fa1 = temp_fv1 * temp_fv0;
        sp4 = temp_fa1 / 6.0f;
        sp8 = ((-temp_fa1 * 11.0f) / 12.0f) + (temp_fv1 * 3.0f / 2.0f);
        spC = (((temp_fa1 * 21.0f) / 12.0f) - (temp_fv1 * 9.0f / 2.0f)) + (temp_fv0 * 3.0f);
        sp10 = CB(arg0);
    }

    return sp4 * arg2[arg1] + sp8 * arg2[arg1 + 1] + spC * arg2[arg1 + 2] + sp10 * arg2[arg1 + 3];
}

void func_80085154(f32* arg0, unk_struct_8* arg1, unk_80085154_arg_2* arg2) {
    s32 temp_s0;
    s32 temp_t2;
    s32 temp_t6;
    s32 temp_t9;
    s32 var_s0;
    s32 var_v0;

    while (arg2->unk_08[arg1->unk_04] == 0) {
        arg1->unk_04++;
    }

    *arg0 =
        func_80084D50((f32) arg1->unk_00 / (f32) arg2->unk_08[arg1->unk_04], arg1->unk_04, arg2->unk_04, arg2->unk_00);

    arg1->unk_00++;

    if (arg1->unk_00 >= arg2->unk_08[arg1->unk_04]) {
        arg1->unk_00 = 0;
        arg1->unk_04++;
        if (arg1->unk_04 >= (arg2->unk_00 - 3)) {
            arg1->unk_04 = -1;
        }
    }
}

void func_8008524C(Vec3f* arg0, unk_struct_8* arg1, unk_struct_14* arg2) {
    s32 temp_s0;
    s32 temp_t2;
    s32 temp_t6;
    s32 temp_t9;
    s32 var_s0;
    s32 var_v0;
    s32 i;

    while (arg2->unk_10[arg1->unk_04] == 0) {
        arg1->unk_04++;
    }

    for (i = 0; i < 3; i++) {
        arg0->v[i] = func_80084D50((f32) arg1->unk_00 / (f32) arg2->unk_10[arg1->unk_04], arg1->unk_04, arg2->unk_04[i],
                                   arg2->unk_00);
    }

    arg1->unk_00++;

    if (arg1->unk_00 >= arg2->unk_10[arg1->unk_04]) {
        arg1->unk_00 = 0;
        arg1->unk_04++;
        if (arg1->unk_04 >= (arg2->unk_00 - 3)) {
            arg1->unk_04 = -1;
        }
    }
}

void func_80085390(Vec3f* arg0, unk_struct_20_2* arg1, unk_struct_14* arg2) {
    func_8008524C(&arg0[0], &arg1->unk_00[0], &arg2[0]);
    func_8008524C(&arg0[1], &arg1->unk_00[1], &arg2[1]);
}

void func_800853D4(Vec3f* arg0, unk_struct_20_2* arg1, unk_struct_14* arg2) {
    func_8008524C(&arg0[0], &arg1->unk_00[0], &arg2[0]);
    func_8008524C(&arg0[1], &arg1->unk_00[1], &arg2[1]);
    func_8008524C(&arg0[2], &arg1->unk_00[2], &arg2[2]);
}

void func_80085434(unk_80085434_arg_0* arg0, unk_struct_20_2* arg1, unk_80085434_arg_2* arg2) {
    func_8008524C(&arg0->unk_00[0], &arg1->unk_00[0], &arg2->unk_00[0]);
    func_8008524C(&arg0->unk_00[1], &arg1->unk_00[1], &arg2->unk_00[1]);
    func_80085154(&arg0->unk_18, &arg1->unk_00[2], &arg2->unk_28);
}

void func_80085494(unk_80085494_arg_0* arg0, unk_struct_20_2* arg1, unk_80085494_arg_2* arg2) {
    func_8008524C(&arg0->unk_00[0], &arg1->unk_00[0], &arg2->unk_00[0]);
    func_8008524C(&arg0->unk_00[1], &arg1->unk_00[1], &arg2->unk_00[1]);
    func_8008524C(&arg0->unk_00[2], &arg1->unk_00[2], &arg2->unk_00[2]);
    func_80085154(&arg0->unk_24, &arg1->unk_00[3], &arg2->unk_3C);
}

void func_80085510(void) {
    unk_800E5D70* var_s1;
    s32 i;
    Racer* temp_a3;
    unk_struct_1DC* var_s0;
    unk_struct_20_2* var_s4;
    unk_struct_F8* var_s3;

    for (i = 0, var_s0 = D_800E5220, var_s1 = D_800E5D70, var_s3 = D_800E5990, var_s4 = D_800E5E00; i < 4; i++) {
        var_s0->unk_00 = (s16) i;
        var_s0->unk_08 = 2;
        var_s0->unk_E0 = 0;
        func_80083548(var_s1, var_s3);
        func_80083550(var_s1, var_s4);
        temp_a3 = &gRacers[var_s0->unk_00];
        func_80083558(var_s1, &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);

        var_s1++;
        var_s3++;
        var_s4++;
        var_s0++;
    }
    D_800E5E8A = 0;
}

extern s8 D_800CD010;

void func_80085B80(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2);

// FAKE! Very hacky tricks to get 1 to load into v0
void func_80085610(void) {
    s32 i;
    unk_struct_1DC* var_s0;
    Racer* temp_a3;
    s32 v0;

    D_800E5E84 = 0;
    D_800E5E8C = 0;

    for (i = 0, var_s0 = D_800E5220; i < 4; i++, var_s0++) {
        temp_a3 = &gRacers[var_s0->unk_00];
        func_80083558(&D_800E5D70[i], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
    }
    switch (gGameMode) {
        case GAMEMODE_FLX_TITLE:
            v0 = 0;
            if (1) {}
            D_800E5E80 = ++v0;
            D_800E5220[0].unk_04 = 0;
            func_80085B80(D_800E5220, D_800E5990, D_800E5D70);
            break;
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_FLX_MACHINE_SELECT:
            v0 = 0;
            if (1) {}
            D_800E5E80 = ++v0;
            D_800E5220[0].unk_04 = v0;
            func_80085B80(D_800E5220, D_800E5990, D_800E5D70);
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_FLX_GP_RACE_NEXT_MACHINE_SETTINGS:
            v0 = 0;
            if (1) {}
            D_800E5E8C = D_800E5E8A;
            D_800E5E80 = ++v0;
            D_800E5220[0].unk_04 = 2;
            func_80085B80(D_800E5220, D_800E5990, D_800E5D70);
            break;
        case GAMEMODE_FLX_COURSE_SELECT:
        case GAMEMODE_FLX_GP_RACE_NEXT_COURSE:
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
            v0 = 0;
            if (1) {}
            D_800E5E80 = ++v0;
            D_800E5220[0].unk_04 = 3;
            func_80085B80(D_800E5220, D_800E5990, D_800E5D70);
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_DEATH_RACE:
            D_800E5E8C = D_800E5E8A;
            /* fallthrough */
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
            D_800CD8A0 = -1;
            D_800E5E80 = gNumPlayers;
            for (i = 0; i < D_800E5E80; i++) {
                if (D_800CD010 != 0) {
                    D_800E5220[i].unk_04 = 15;
                } else {
                    D_800E5220[i].unk_04 = 4;
                }

                D_800E5220[i].unk_20 = gRacers[i].unk_0C.unk_34;

                D_800E5220[i].unk_2C = gRacers[i].unk_C0;

                func_80085B80(&D_800E5220[i], &D_800E5990[i], &D_800E5D70[i]);
            }

            break;
        case GAMEMODE_TIME_ATTACK:
            D_800E5E8C = D_800E5E8A;
            D_800CD8A0 = -1;
            D_800E5E80 = 2;
            if (D_800CD010 != 0) {
                D_800E5220[0].unk_04 = 15;
                // FAKE some kind of override here
                if (1) {
                    D_800E5220[0].unk_04 = 4;
                }
            } else {
                D_800E5220[0].unk_04 = 4;
            }
            D_800E5220[0].unk_20 = gRacers[0].unk_0C.unk_34;
            D_800E5220[0].unk_2C = gRacers[0].unk_C0;

            D_800E5220[1].unk_04 = 12;
            for (i = 0; i < D_800E5E80; i++) {
                func_80085B80(&D_800E5220[i], &D_800E5990[i], &D_800E5D70[i]);
            }
            break;
        case GAMEMODE_RECORDS:

            D_800E5E80 = 2;
            D_800E5220[0].unk_04 = 0xB;
            D_800E5220[0].unk_20 = gRacers[0].unk_0C.unk_34;
            D_800E5220[0].unk_2C = gRacers[0].unk_C0;
            D_800E5220[1].unk_04 = 0xC;
            for (i = 0; i < D_800E5E80; i++) {
                func_80085B80(&D_800E5220[i], &D_800E5990[i], &D_800E5D70[i]);
            }
            break;
        case GAMEMODE_GP_END_CS:
            v0 = 0;
            if (1) {}
            D_800E5E80 = ++v0;
            D_800E5220[0].unk_04 = 0xE;
            func_80085B80(D_800E5220, D_800E5990, D_800E5D70);
            break;
    }
}

void func_80088408(Vec3f* arg0, CourseSegment* arg1, f32 arg2, unk_800CD970* arg3);
void func_80086400(unk_struct_1DC* arg0);
extern s16 D_80106F48;

void func_80085B80(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 pad;
    s32 sp48;
    bool sp44;
    f32 angle;
    s32 pad2;
    Vec3f* sp38;
    Vec3f sp2C;
    Racer* racer;

    arg0->unk_0C = 0;
    arg0->unk_18 = 0;
    arg0->unk_1C = 0;
    sp44 = false;

    switch (arg0->unk_04) {
        case 1:
        case 12:
            arg0->unk_A0 = 16.0f;
            arg0->unk_A4 = 8192.0f;
            arg0->unk_A8 = 320.0f;
            arg0->unk_AC = 240.0f;
            func_800812A4(arg1, 2, &D_800D4F58);
            break;
        case 2:
            arg0->unk_A0 = 16.0f;
            arg0->unk_A4 = 8192.0f;
            arg0->unk_A8 = 320.0f;
            arg0->unk_AC = 240.0f;
            func_800812A4(arg1, 2, &D_800D5004);
            if (gNumPlayers >= 2) {
                arg1->unk_04.unk_58.unk_00.unk_00.unk_48.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_48.y = 30.0f;
            }
            break;
        case 3:
            arg0->unk_A0 = 16.0f;
            arg0->unk_A4 = 16384.0f;
            arg0->unk_A8 = 320.0f;
            arg0->unk_AC = 240.0f;
            func_800812A4(arg1, 2, &D_800D50B0);
            break;
        case 4:
            func_800812A4(arg1, 2, &D_800D524C);
            if (gNumPlayers == 2) {
                arg0->unk_A0 = 16.0f;
                arg0->unk_A4 = 8192.0f;
                arg1->unk_04.unk_00.unk_18[11] = arg1->unk_04.unk_00.unk_18[13] = -15.0f;
                arg1->unk_04.unk_00.unk_18[7] = arg1->unk_04.unk_00.unk_18[8] = 100.0f;
            } else {
                arg0->unk_A0 = 16.0f;
                arg0->unk_A4 = 8192.0f;
            }
            arg0->unk_A8 = 320.0f;
            arg0->unk_AC = 240.0f;
            sp44 = 1;
            break;
        case 6:
        case 15:
            if (D_800CD010 != 0) {
                sp48 = 2;
            } else {
                sp48 = arg0->unk_08;
            }
            if (gNumPlayers == 2) {
                arg0->unk_A0 = 16.0f;
                arg0->unk_A4 = 8192.0f;
                arg0->unk_A8 = 320.0f;
                arg0->unk_AC = 240.0f;

                func_800811F0(arg1, &D_800D544C);

                sp38 = &D_800D5328[sp48];
            } else {
                arg0->unk_A0 = 16.0f;
                arg0->unk_A4 = 8192.0f;
                arg0->unk_A8 = 320.0f;
                arg0->unk_AC = 240.0f;

                func_800811F0(arg1, &D_800D5358);

                sp38 = &D_800D52F8[sp48];
            }
            arg1->unk_04.unk_58.unk_68[2] = arg1->unk_04.unk_58.unk_68[1] = sp38->y;
            arg1->unk_04.unk_58.unk_68[5] = arg1->unk_04.unk_58.unk_68[4] = sp38->z;
            arg1->unk_04.unk_00.unk_18[8] = arg1->unk_04.unk_00.unk_18[7] = sp38->x;

            Math_Round(DEG_TO_FZXANG2(arg1->unk_04.unk_58.unk_68[4]));
            racer = &gRacers[arg0->unk_00];
            arg1->unk_04.unk_58.unk_00.unk_54.x = racer->unk_180.x - (sp38->y * racer->unk_C0.x.x);
            arg1->unk_04.unk_58.unk_00.unk_54.y = racer->unk_180.y - (sp38->y * racer->unk_C0.x.y);
            arg1->unk_04.unk_58.unk_00.unk_54.z = racer->unk_180.z - (sp38->y * racer->unk_C0.x.z);
            arg0->unk_14 = arg1->unk_04.unk_00.unk_18[8];
            arg0->unk_10 = 0;
            if ((sp48 == 1) || (sp48 == 2)) {
                arg0->unk_10 |= 1;
            }
            sp44 = true;
            break;
        case 7:
            sp2C = arg1->unk_04.unk_00.unk_0C;
            func_8008112C(arg1, &D_800D4C80);
            arg1->unk_04.unk_00.unk_18[7] = arg1->unk_04.unk_00.unk_18[8] = 80.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C = sp2C;
            if (gNumPlayers == 2) {
                arg1->unk_04.unk_00.unk_18[11] = arg1->unk_04.unk_00.unk_18[13] = -50.0f;
            }
            break;
        case 8:
            func_8008112C(arg1, &D_800D4C80);
            arg1->unk_04.unk_00.unk_18[8] = D_800CD970[0].unk_04;
            if (gNumPlayers == 2) {
                arg1->unk_04.unk_00.unk_18[11] = arg1->unk_04.unk_00.unk_18[13] = -30.0f;
            }

            racer = &gRacers[arg0->unk_00];
            func_80088408(&D_800E5E90[arg0->unk_00], racer->unk_0C.courseSegment, racer->unk_0C.unk_04, &D_800CD970[0]);
            break;
        case 9:
            racer = &gRacers[arg0->unk_00];

            func_800812A4(arg1, 2, &D_800D4CF8);
            if (gNumPlayers == 2) {
                arg1->unk_04.unk_00.unk_18[11] = arg1->unk_04.unk_00.unk_18[13] = -30.0f;
            }
            arg1->unk_04.unk_00.unk_18[7] = arg1->unk_04.unk_00.unk_18[8] = 80.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_30.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_30.y = 125.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.y = 35.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_48.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_48.y = -50.0f;

            *(Mtx3F*) &arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C = racer->unk_C0;

            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_18 = racer->unk_B4.x;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_1C = racer->unk_B4.y;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_20 = racer->unk_B4.z;
            break;
        case 10:
            sp2C = arg1->unk_04.unk_00.unk_0C;
            func_8008112C(arg1, &D_800D4C80);
            arg1->unk_04.unk_00.unk_18[7] = arg1->unk_04.unk_00.unk_18[8] = 80.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C = sp2C;
            break;
        case 11:
            arg0->unk_A0 = 16.0f;
            arg0->unk_A4 = 8192.0f;
            arg0->unk_A8 = 320.0f;
            arg0->unk_AC = 240.0f;
            func_800811F0(arg1, &D_800D5358);
            arg1->unk_04.unk_58.unk_68[2] = arg1->unk_04.unk_58.unk_68[1] = D_800D52F8[1].y;
            arg1->unk_04.unk_58.unk_68[5] = arg1->unk_04.unk_58.unk_68[4] = 15.0f;
            arg1->unk_04.unk_00.unk_18[8] = arg1->unk_04.unk_00.unk_18[7] = D_800D52F8[1].x;
            angle = 15.0f;
            sp38 = &D_800D52F8[1];
            Math_Round(DEG_TO_FZXANG2(angle));
            racer = &gRacers[0];
            arg1->unk_04.unk_58.unk_00.unk_54.x = racer->unk_180.x - (sp38->y * racer->unk_C0.x.x);
            arg1->unk_04.unk_58.unk_00.unk_54.y = racer->unk_180.y - (sp38->y * racer->unk_C0.x.y);
            arg1->unk_04.unk_58.unk_00.unk_54.z = racer->unk_180.z - (sp38->y * racer->unk_C0.x.z);
            arg0->unk_14 = arg1->unk_04.unk_00.unk_18[8];
            arg0->unk_10 = 0;
            sp44 = true;
            break;
        case 13:
            arg0->unk_A0 = 512.0f;
            arg0->unk_A4 = 8192.0f;
            arg0->unk_A8 = 320.0f;
            arg0->unk_AC = 240.0f;
            func_8008112C(arg1, &D_800D515C);
            break;
        case 14:
            arg0->unk_A0 = 16.0f;
            arg0->unk_A4 = 8192.0f;
            arg0->unk_A8 = 320.0f;
            arg0->unk_AC = 240.0f;
            func_800812A4(arg1, 3, &D_800D4CF8);
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00.x = 196.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00.y = 25.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00.z = -3000.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_30.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_30.y = 258.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.y = -7.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_48.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_48.y = 269.0f;
            sp44 = true;
            if (D_80106F48 < 4) {
                D_800E5E88 = D_80106F48 - 1;
            } else {
                D_800E5E88 = 0;
            }
            break;
    }
    if (sp44) {
        arg0->unk_E0 = 0;
        arg0->unk_E4 = arg0->unk_E6 = 0;
        func_80086400(arg0);
    }
}

extern s32 D_800E5E80;

void func_80086400(unk_struct_1DC* arg0) {
    s32* temp = D_800CD9AC[D_800E5E80];
    s32 temp2 = temp[arg0->unk_00];
    Vp* sp24;
    ScissorBox* sp20;

    switch (temp2) {
        case 0:
            sp24 = Segment_SegmentedToVirtual(&D_80146A8);
            sp20 = &D_800CD9C0;
            break;
        case 1:
            sp24 = Segment_SegmentedToVirtual(&D_80146B8);
            sp20 = &D_800CD9D0;
            break;
        case 2:
            sp24 = Segment_SegmentedToVirtual(&D_80146C8);
            sp20 = &D_800CD9E0;
            break;
        case 3:
            sp24 = Segment_SegmentedToVirtual(&D_80146D8);
            sp20 = &D_800CD9F0;
            break;
        case 4:
            sp24 = Segment_SegmentedToVirtual(&D_80146E8);
            sp20 = &D_800CDA00;
            break;
        case 5:
            sp24 = Segment_SegmentedToVirtual(&D_80146F8);
            sp20 = &D_800CDA10;
            break;
        case 6:
            sp24 = Segment_SegmentedToVirtual(&D_8014708);
            sp20 = &D_800CDA20;
            break;
        case 7:
            sp24 = Segment_SegmentedToVirtual(&D_8014718);
            sp20 = &D_800CDA30;
            break;
        case 8:
            sp24 = Segment_SegmentedToVirtual(&D_8014728);
            sp20 = &D_800CDA40;
            break;
        case 9:
            sp24 = Segment_SegmentedToVirtual(&D_8014738);
            sp20 = &D_800CDA50;
            break;
        case 10:
            sp24 = Segment_SegmentedToVirtual(&D_8014748);
            sp20 = &D_800CDA60;
            break;
        case 11:
            sp24 = Segment_SegmentedToVirtual(&D_8014758);
            sp20 = &D_800CDA70;
            break;
        case 12:
            sp24 = Segment_SegmentedToVirtual(&D_8014768);
            sp20 = &D_800CDA80;
            break;
    }

    arg0->unk_E8 = arg0->unk_F8 = arg0->unk_108 = sp24->vp.vscale[0] * 0.25f;
    arg0->unk_EC = arg0->unk_FC = arg0->unk_10C = sp24->vp.vscale[1] * 0.25f;

    arg0->unk_F0 = sp24->vp.vtrans[0] * 0.25f;
    arg0->unk_F4 = sp24->vp.vtrans[1] * 0.25f;

    arg0->unk_100 = arg0->unk_110 = arg0->unk_F0 - arg0->unk_E8;
    arg0->unk_104 = arg0->unk_114 = arg0->unk_F4 - arg0->unk_EC;

    arg0->unk_B0 = arg0->unk_C0 = arg0->unk_D0 = sp20->left;
    arg0->unk_B4 = arg0->unk_C4 = arg0->unk_D4 = sp20->top;
    arg0->unk_B8 = arg0->unk_C8 = arg0->unk_D8 = sp20->right;
    arg0->unk_BC = arg0->unk_CC = arg0->unk_DC = sp20->bottom;
}

void func_8008681C(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_80086FD0(void);
extern s32 D_800E5E80;

void func_8008675C(void) {
    s32 i;

    for (i = 0; i < D_800E5E80; i++) {
        func_8008681C(&D_800E5220[i], &D_800E5990[i], &D_800E5D70[i]);
    }

    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P) || (gGameMode == GAMEMODE_VS_4P)) {
        func_80086FD0();
    }
}

void func_80086B64(unk_struct_1DC*, unk_struct_F8*);
void func_800876A8(unk_struct_1DC*, unk_struct_F8*);
void func_800879E0(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_80087DB8(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_80087E14(unk_struct_1DC*, unk_struct_F8*);
void func_80087F60(unk_struct_1DC*, unk_struct_F8*);
void func_80087FAC(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_800885F0(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_80088660(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);
void func_800888D0(unk_struct_1DC*, unk_struct_F8*, unk_800E5D70*);

extern GfxPool* D_800DCCF0;

void func_8008681C(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_fv0;
    f32 var_fv1;
    f32 var_fv1_2;
    f32 var_fv1_3;
    f32 var_fv1_4;
    bool var_v0;
    u32 temp_s4;
    u32 var_v1;

    do {
        temp_s4 = var_v1 = arg0->unk_04;
        switch (var_v1) {
            case 0:
            case 1:
            case 2:
            case 16:
            default:
                break;
            case 3:
                func_80087E14(arg0, arg1);
                break;
            case 4:
                if (D_800DCE5C == 0) {
                    func_800876A8(arg0, arg1);
                }
                break;
            case 5:

                var_v0 = true;

                temp_fv0 = arg1->unk_04.unk_00.unk_18[8] - arg1->unk_04.unk_00.unk_18[7];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                temp_fv0 = arg1->unk_04.unk_00.unk_18[13] - arg1->unk_04.unk_00.unk_18[11];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                temp_fv0 = arg1->unk_04.unk_58.unk_68[2] - arg1->unk_04.unk_58.unk_68[1];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                temp_fv0 = arg1->unk_04.unk_58.unk_68[5] - arg1->unk_04.unk_58.unk_68[4];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                if (var_v0) {
                    arg0->unk_04 = 6;
                    arg1->unk_04.unk_00.unk_18[9] = 0.2f;
                    arg1->unk_04.unk_00.unk_18[6] = 1.0f;
                    arg1->unk_04.unk_00.unk_18[14] = 0.1f;
                    arg1->unk_04.unk_00.unk_18[15] = 0.2f;
                    arg1->unk_04.unk_58.unk_68[3] = 0.2f;
                    arg1->unk_04.unk_58.unk_68[6] = 0.2f;
                }
                break;
            case 6:
                func_800879E0(arg0, arg1, arg2);
                break;
            case 15:
                func_80087DB8(arg0, arg1, arg2);
                break;
            case 7:
                if (D_800DCE5C == 0) {
                    func_80087F60(arg0, arg1);
                }
                break;
            case 8:
                if (D_800DCE5C == 0) {
                    func_80087FAC(arg0, arg1, arg2);
                }
                break;
            case 9:
                if (D_800DCE5C == 0) {
                    func_80088660(arg0, arg1, arg2);
                }
                break;
            case 10:
                if (D_800DCE5C == 0) {
                    func_800885F0(arg0, arg1, arg2);
                }
                break;
            case 14:
                func_800888D0(arg0, arg1, arg2);
                break;
        }
        var_v1 = arg0->unk_04;
    } while (temp_s4 != var_v1);

    func_80082068(arg1, arg0);
    func_80086B64(arg0, arg1);
    func_800826B8(arg0, arg1);
    func_8008271C(arg0);
    func_80082A6C(D_800DCCF0, arg0);
    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_TIME_ATTACK) ||
        (gGameMode == GAMEMODE_DEATH_RACE)) {
        func_80082C80(arg0);
    }
}

void func_80086B64(unk_struct_1DC* arg0, unk_struct_F8* arg1) {
    Vec3f* var_s1;
    s32 angle;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    Mtx3F sp48;
    f32 temp_fv0;
    f32 temp_fv1;
    unk_8008112C_arg_1* temp_v1 = &arg1->unk_04;
    Racer* temp_s0;

    if (arg0->unk_04 == 4) {
        if (gNumPlayers == 2) {
            var_s1 = &D_800D5328[2];
        } else {
            var_s1 = &D_800D52F8[2];
        }

        temp_s0 = &gRacers[arg0->unk_00];

        sp48.x.x = 0.0f - (var_s1->y * temp_s0->unk_C0.x.x);
        sp48.x.y = 0.0f - (var_s1->y * temp_s0->unk_C0.x.y);
        sp48.x.z = 0.0f - (var_s1->y * temp_s0->unk_C0.x.z);
        temp_fv1 = 1.0f / sqrtf(SQ(sp48.x.x) + SQ(sp48.x.y) + SQ(sp48.x.z));
        sp48.x.x *= temp_fv1;
        sp48.x.y *= temp_fv1;
        sp48.x.z *= temp_fv1;

        sp48.z.x = (temp_s0->unk_C0.y.y * sp48.x.z) - (temp_s0->unk_C0.y.z * sp48.x.y);
        sp48.z.y = (temp_s0->unk_C0.y.z * sp48.x.x) - (temp_s0->unk_C0.y.x * sp48.x.z);
        sp48.z.z = (temp_s0->unk_C0.y.x * sp48.x.y) - (temp_s0->unk_C0.y.y * sp48.x.x);
        temp_fv1 = 1.0f / sqrtf(SQ(sp48.z.x) + SQ(sp48.z.y) + SQ(sp48.z.z));
        sp48.z.x *= temp_fv1;
        sp48.z.y *= temp_fv1;
        sp48.z.z *= temp_fv1;

        sp48.y.x = (sp48.x.y * sp48.z.z) - (sp48.x.z * sp48.z.y);
        sp48.y.y = (sp48.x.z * sp48.z.x) - (sp48.x.x * sp48.z.z);
        sp48.y.z = (sp48.x.x * sp48.z.y) - (sp48.x.y * sp48.z.x);
        temp_fv1 = 1.0f / sqrtf(SQ(sp48.y.x) + SQ(sp48.y.y) + SQ(sp48.y.z));
        sp48.y.x *= temp_fv1;
        sp48.y.y *= temp_fv1;
        sp48.y.z *= temp_fv1;

        angle = Math_Round(DEG_TO_FZXANG2(var_s1->z));

        temp_fv0 = (SIN(angle) * var_s1->y) * ((sp48.y.x * temp_s0->unk_C0.y.x) + (sp48.y.y * temp_s0->unk_C0.y.y) +
                                               (sp48.y.z * temp_s0->unk_C0.y.z));
        temp_fv1 = COS(angle) * var_s1->y;

        temp1 = (temp_s0->unk_180.x + (temp_fv1 * sp48.x.x) + (temp_fv0 * sp48.y.x));
        temp2 = (temp_s0->unk_180.y + (temp_fv1 * sp48.x.y) + (temp_fv0 * sp48.y.y));
        temp3 = (temp_s0->unk_180.z + (temp_fv1 * sp48.x.z) + (temp_fv0 * sp48.y.z));

        temp_fv0 = (f32) (arg0->unk_1C - 1) / 300.0f;

        temp_fv0 = (-2.0f * temp_fv0 * temp_fv0 * temp_fv0) + (3.0f * temp_fv0 * temp_fv0);

        temp_v1->unk_00.unk_0C.x = ((1.0f - temp_fv0) * temp_v1->unk_00.unk_0C.x) + (temp_fv0 * temp1);
        temp_v1->unk_00.unk_0C.y = ((1.0f - temp_fv0) * temp_v1->unk_00.unk_0C.y) + (temp_fv0 * temp2);
        temp_v1->unk_00.unk_0C.z = ((1.0f - temp_fv0) * temp_v1->unk_00.unk_0C.z) + (temp_fv0 * temp3);

        sp48.x.x = temp_v1->unk_00.unk_00.x - temp_v1->unk_00.unk_0C.x;
        sp48.x.y = temp_v1->unk_00.unk_00.y - temp_v1->unk_00.unk_0C.y;
        sp48.x.z = temp_v1->unk_00.unk_00.z - temp_v1->unk_00.unk_0C.z;
        sp48.y.x = temp_s0->unk_C0.y.x;
        sp48.y.y = temp_s0->unk_C0.y.y;
        sp48.y.z = temp_s0->unk_C0.y.z;
        func_8006AA38(&sp48);
        temp_v1->unk_00.unk_18[3] = sp48.y.x;
        temp_v1->unk_00.unk_18[0] = temp_v1->unk_00.unk_18[3];
        temp_v1->unk_00.unk_18[4] = sp48.y.y;
        temp_v1->unk_00.unk_18[1] = temp_v1->unk_00.unk_18[4];
        temp_v1->unk_00.unk_18[5] = sp48.y.z;
        temp_v1->unk_00.unk_18[2] = temp_v1->unk_00.unk_18[5];
    }
}

extern s32 D_800CD8A0;
extern s32 D_800E5E80;
extern s16 D_800E5FBC;
extern s32 D_i2_80106F10;
extern s32 D_80141D6C;
extern s32 D_80141D70;

void func_80086FD0(void) {
    Racer* var_a1;
    f32 temp_fv0;
    s32 i;
    unk_struct_1DC* var_a0;
    Vp* vp;

    if (D_800CD8A0 == -1) {
        if ((D_800E5FBC != 0) && (D_80141D6C != 0)) {
            D_i2_80106F10 = 0x1E;

            for (i = 0, var_a0 = D_800E5220; i < D_800E5E80; i++, var_a0++) {
                var_a1 = &gRacers[i];
                if (var_a1->position == 1) {
                    D_800CD8A0 = i;
                }
                var_a0->unk_E0 = 1;
                var_a0->unk_E4 = 0;
                var_a0->unk_E6 = 0x1E;
            }

            switch (gGameMode) {
                case GAMEMODE_VS_2P:
                    if (D_800CD8A0 == 0) {
                        D_800E5220[0].unk_D4 = 8.0f;
                        D_800E5220[0].unk_DC = 231.0f;
                        D_800E5220[0].unk_10C = 120.0f;
                        D_800E5220[0].unk_114 = 0.0f;
                        D_800E5220[1].unk_D4 = 231.0f;
                        D_800E5220[1].unk_DC = 231.0f;
                        D_800E5220[1].unk_10C = 0.0f;
                        D_800E5220[1].unk_114 = 240.0f;
                    } else {
                        D_800E5220[0].unk_D4 = 8.0f;
                        D_800E5220[0].unk_DC = 8.0f;
                        D_800E5220[0].unk_10C = 0.0f;
                        D_800E5220[0].unk_114 = 0.0f;
                        D_800E5220[1].unk_D4 = 8.0f;
                        D_800E5220[1].unk_DC = 231.0f;
                        D_800E5220[1].unk_10C = 120.0f;
                        D_800E5220[1].unk_114 = 0.0f;
                    }
                    break;
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                    switch (D_800CD8A0) {
                        case 0:
                            D_800E5220[0].unk_D0 = 12.0f;
                            D_800E5220[0].unk_D4 = 8.0f;
                            D_800E5220[0].unk_D8 = 307.0f;
                            D_800E5220[0].unk_DC = 231.0f;
                            D_800E5220[0].unk_108 = 160.0f;
                            D_800E5220[0].unk_10C = 120.0f;
                            D_800E5220[0].unk_110 = 0.0f;
                            D_800E5220[0].unk_114 = 0.0f;
                            D_800E5220[1].unk_D0 = 12.0f;
                            D_800E5220[1].unk_D4 = 231.0f;
                            D_800E5220[1].unk_D8 = 307.0f;
                            D_800E5220[1].unk_DC = 231.0f;
                            D_800E5220[1].unk_108 = 160.0f;
                            D_800E5220[1].unk_10C = 0.0f;
                            D_800E5220[1].unk_110 = 0.0f;
                            D_800E5220[1].unk_114 = 240.0f;
                            D_800E5220[2].unk_D0 = 307.0f;
                            D_800E5220[2].unk_D4 = 8.0f;
                            D_800E5220[2].unk_DC = 231.0f;
                            D_800E5220[2].unk_D8 = 307.0f;
                            D_800E5220[2].unk_108 = 0.0f;
                            D_800E5220[2].unk_10C = 120.0f;
                            D_800E5220[2].unk_110 = 320.0f;
                            D_800E5220[2].unk_114 = 0.0f;
                            D_800E5220[3].unk_D0 = 307.0f;
                            D_800E5220[3].unk_D4 = 231.0f;
                            D_800E5220[3].unk_D8 = 307.0f;
                            D_800E5220[3].unk_DC = 231.0f;
                            D_800E5220[3].unk_108 = 0.0f;
                            D_800E5220[3].unk_10C = 0.0f;
                            D_800E5220[3].unk_110 = 320.0f;
                            D_800E5220[3].unk_114 = 240.0f;
                            break;
                        case 1:
                            D_800E5220[0].unk_D0 = 12.0f;
                            D_800E5220[0].unk_D4 = 8.0f;
                            D_800E5220[0].unk_D8 = 307.0f;
                            D_800E5220[0].unk_DC = 8.0f;
                            D_800E5220[0].unk_108 = 160.0f;
                            D_800E5220[0].unk_10C = 0.0f;
                            D_800E5220[0].unk_110 = 0.0f;
                            D_800E5220[0].unk_114 = 0.0f;
                            D_800E5220[1].unk_D0 = 12.0f;
                            D_800E5220[1].unk_D4 = 8.0f;
                            D_800E5220[1].unk_D8 = 307.0f;
                            D_800E5220[1].unk_DC = 231.0f;
                            D_800E5220[1].unk_108 = 160.0f;
                            D_800E5220[1].unk_10C = 120.0f;
                            D_800E5220[1].unk_110 = 0.0f;
                            D_800E5220[1].unk_114 = 0.0f;
                            D_800E5220[2].unk_D0 = 307.0f;
                            D_800E5220[2].unk_D4 = 8.0f;
                            D_800E5220[2].unk_D8 = 307.0f;
                            D_800E5220[2].unk_DC = 8.0f;
                            D_800E5220[2].unk_108 = 0.0f;
                            D_800E5220[2].unk_10C = 0.0f;
                            D_800E5220[2].unk_110 = 320.0f;
                            D_800E5220[2].unk_114 = 0.0f;
                            D_800E5220[3].unk_D0 = 307.0f;
                            D_800E5220[3].unk_D4 = 8.0f;
                            D_800E5220[3].unk_D8 = 307.0f;
                            D_800E5220[3].unk_DC = 231.0f;
                            D_800E5220[3].unk_108 = 0.0f;
                            D_800E5220[3].unk_10C = 120.0f;
                            D_800E5220[3].unk_110 = 320.0f;
                            D_800E5220[3].unk_114 = 0.0f;
                            break;
                        case 2:
                            D_800E5220[0].unk_D0 = 12.0f;
                            D_800E5220[0].unk_D4 = 8.0f;
                            D_800E5220[0].unk_D8 = 12.0f;
                            D_800E5220[0].unk_DC = 231.0f;
                            D_800E5220[0].unk_108 = 0.0f;
                            D_800E5220[0].unk_10C = 120.0f;
                            D_800E5220[0].unk_110 = 0.0f;
                            D_800E5220[0].unk_114 = 0.0f;
                            D_800E5220[1].unk_D0 = 12.0f;
                            D_800E5220[1].unk_D4 = 231.0f;
                            D_800E5220[1].unk_D8 = 12.0f;
                            D_800E5220[1].unk_DC = 231.0f;
                            D_800E5220[1].unk_108 = 0.0f;
                            D_800E5220[1].unk_10C = 0.0f;
                            D_800E5220[1].unk_110 = 0.0f;
                            D_800E5220[1].unk_114 = 240.0f;
                            D_800E5220[2].unk_D0 = 12.0f;
                            D_800E5220[2].unk_D4 = 8.0f;
                            D_800E5220[2].unk_D8 = 307.0f;
                            D_800E5220[2].unk_DC = 231.0f;
                            D_800E5220[2].unk_108 = 160.0f;
                            D_800E5220[2].unk_10C = 120.0f;
                            D_800E5220[2].unk_110 = 0.0f;
                            D_800E5220[2].unk_114 = 0.0f;
                            D_800E5220[3].unk_D0 = 12.0f;
                            D_800E5220[3].unk_D4 = 231.0f;
                            D_800E5220[3].unk_D8 = 307.0f;
                            D_800E5220[3].unk_DC = 231.0f;
                            D_800E5220[3].unk_108 = 160.0f;
                            D_800E5220[3].unk_10C = 0.0f;
                            D_800E5220[3].unk_110 = 0.0f;
                            D_800E5220[3].unk_114 = 240.0f;
                            break;
                        case 3:
                            D_800E5220[0].unk_108 = 0.0f;
                            D_800E5220[0].unk_10C = 0.0f;
                            D_800E5220[0].unk_D0 = 12.0f;
                            D_800E5220[0].unk_D8 = 12.0f;
                            D_800E5220[0].unk_110 = 0.0f;
                            D_800E5220[0].unk_114 = 0.0f;
                            D_800E5220[0].unk_D4 = 8.0f;
                            D_800E5220[0].unk_DC = 8.0f;
                            D_800E5220[1].unk_D0 = 12.0f;
                            D_800E5220[1].unk_D8 = 12.0f;
                            D_800E5220[2].unk_D0 = 12.0f;
                            D_800E5220[3].unk_D0 = 12.0f;
                            D_800E5220[1].unk_D4 = 8.0f;
                            D_800E5220[2].unk_D4 = 8.0f;
                            D_800E5220[2].unk_DC = 8.0f;
                            D_800E5220[3].unk_D4 = 8.0f;
                            D_800E5220[1].unk_10C = 120.0f;
                            D_800E5220[3].unk_10C = 120.0f;
                            D_800E5220[1].unk_DC = 231.0f;
                            D_800E5220[3].unk_DC = 231.0f;
                            D_800E5220[2].unk_108 = 160.0f;
                            D_800E5220[3].unk_108 = 160.0f;
                            D_800E5220[2].unk_D8 = 307.0f;
                            D_800E5220[3].unk_D8 = 307.0f;
                            D_800E5220[1].unk_108 = 0.0f;
                            D_800E5220[1].unk_110 = 0.0f;
                            D_800E5220[1].unk_114 = 0.0f;
                            D_800E5220[2].unk_10C = 0.0f;
                            D_800E5220[2].unk_110 = 0.0f;
                            D_800E5220[2].unk_114 = 0.0f;
                            D_800E5220[3].unk_110 = 0.0f;
                            D_800E5220[3].unk_114 = 0.0f;
                            break;
                    }
                    break;
            }
        }
    } else if ((D_800E5220[D_800CD8A0].unk_E4 == 0x1E) && (D_80141D70 == 0)) {
        D_80141D70 = 1;
    }

    for (i = 0, var_a0 = D_800E5220; i < D_800E5E80; i++, var_a0++) {
        if (var_a0->unk_E0 == 1) {
            if (var_a0->unk_E4 < var_a0->unk_E6) {
                var_a0->unk_E4++;
            }

            temp_fv0 = (f32) var_a0->unk_E4 / var_a0->unk_E6;

            var_a0->unk_B0 = var_a0->unk_C0 + ((var_a0->unk_D0 - var_a0->unk_C0) * temp_fv0);
            var_a0->unk_B4 = var_a0->unk_C4 + ((var_a0->unk_D4 - var_a0->unk_C4) * temp_fv0);

            var_a0->unk_B8 = var_a0->unk_C8 + ((var_a0->unk_D8 - var_a0->unk_C8) * temp_fv0);
            var_a0->unk_BC = var_a0->unk_CC + ((var_a0->unk_DC - var_a0->unk_CC) * temp_fv0);
            var_a0->unk_E8 = var_a0->unk_F8 + ((var_a0->unk_108 - var_a0->unk_F8) * temp_fv0);
            var_a0->unk_EC = var_a0->unk_FC + ((var_a0->unk_10C - var_a0->unk_FC) * temp_fv0);
            var_a0->unk_F0 = var_a0->unk_100 + ((var_a0->unk_110 - var_a0->unk_100) * temp_fv0) + var_a0->unk_E8;
            var_a0->unk_F4 = var_a0->unk_104 + ((var_a0->unk_114 - var_a0->unk_104) * temp_fv0) + var_a0->unk_EC;

            vp = &D_800DCCF0->unk_2C2C8[i];
            vp->vp.vscale[0] = var_a0->unk_E8 * 4.0f;
            vp->vp.vscale[1] = var_a0->unk_EC * 4.0f;
            vp->vp.vscale[2] = 0x1FF;
            vp->vp.vscale[3] = 0;
            vp->vp.vtrans[0] = var_a0->unk_F0 * 4.0f;
            vp->vp.vtrans[1] = var_a0->unk_F4 * 4.0f;
            vp->vp.vtrans[2] = 0x1FF;
            vp->vp.vtrans[3] = 0;
        }
    }
}

void func_800876A8(unk_struct_1DC* arg0, unk_struct_F8* arg1) {
    Vec3f* var_v1;
    f32 temp_fv0;
    s32 index;
    unk_8008112C_arg_1* temp_a0 = &arg1->unk_04;
    Racer* temp_t3 = &gRacers[arg0->unk_00];
    unk_struct_9C* temp_a3 = &arg1->unk_04.unk_58;
    Racer* temp_t4;
    s32 pad[5];

    temp_a3->unk_00.unk_00.unk_00.unk_00 = temp_t3->unk_180;

    *((Mtx3F*) &arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C) = temp_t3->unk_C0;

    temp_fv0 = (f32) arg0->unk_1C / 300.0f;
    temp_fv0 = (-2.0f * temp_fv0 * temp_fv0 * temp_fv0) + (3.0f * temp_fv0 * temp_fv0);
    arg1->unk_04.unk_58.unk_00.unk_00.unk_30.y = (-880.0f * temp_fv0) + 1000.0f;
    arg1->unk_04.unk_58.unk_00.unk_00.unk_48.y = (-360.0f * temp_fv0) + 180.0f;

    if (arg0->unk_1C >= 0x12C) {
        if (gNumPlayers == 2) {
            func_800811B0(arg1, &D_800D544C.unk_58);
            var_v1 = &D_800D5328[2];
        } else {
            func_800811B0(arg1, &D_800D5358.unk_58);
            var_v1 = &D_800D52F8[2];
        }
        arg0->unk_04 = 5;
        temp_a3->unk_00.unk_00.unk_48.x = 0.0f;
        temp_a3->unk_00.unk_00.unk_48.y = 0.0f;
        temp_a3->unk_00.unk_00.unk_48.z = 0.0f;

        temp_a3->unk_68[1] = var_v1->y;
        temp_a3->unk_68[4] = var_v1->z;
        temp_a0->unk_00.unk_18[7] = var_v1->x;

        if (gNumPlayers == 2) {
            var_v1 = &D_800D5328[arg0->unk_08];
        } else {
            var_v1 = &D_800D52F8[arg0->unk_08];
        }
        temp_a3->unk_68[2] = var_v1->y;
        temp_a3->unk_68[5] = var_v1->z;
        temp_a0->unk_00.unk_18[8] = var_v1->x;

        temp_t4 = &gRacers[arg0->unk_00];
        temp_a3->unk_00.unk_54.x = temp_t4->unk_180.x - (var_v1->y * temp_t4->unk_C0.xx);
        temp_a3->unk_00.unk_54.y = temp_t4->unk_180.y - (var_v1->y * temp_t4->unk_C0.yx);
        temp_a3->unk_00.unk_54.z = temp_t4->unk_180.z - (var_v1->y * temp_t4->unk_C0.zx);

        arg0->unk_20 = temp_t4->unk_180;
        arg0->unk_2C = temp_t4->unk_C0;

        arg0->unk_14 = arg1->unk_04.unk_00.unk_18[8];
        arg0->unk_10 = 0;
        if ((arg0->unk_08 == 1) || (arg0->unk_08 == 2)) {
            arg0->unk_10 |= 1;
        }
        temp_a3->unk_68[6] = 0.1f;
        temp_a3->unk_68[3] = 0.1f;
        temp_a0->unk_00.unk_18[6] = 0.1f;
        temp_a0->unk_00.unk_18[9] = 0.1f;
        temp_a0->unk_00.unk_18[15] = 0.1f;
    } else {
        arg0->unk_1C++;
    }
}

extern Controller gControllers[];
extern s32 gPlayerControlPorts[];
extern s32 gNumPlayers;
extern s32 gCurrentGhostType;
extern s8 D_800DCE5C;
extern s32 gFastestGhostTime;

void func_800879E0(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    f32 var_fa0;
    f32 var_fv1;
    s32 index;
    bool var_v1;
    unk_8008112C_arg_1* temp_a1;
    s32 pad[4];
    Racer* temp_t0;
    unk_struct_9C* temp_a2 = &arg1->unk_04.unk_58;
    Controller* controller;

    index = arg0->unk_00;
    temp_t0 = &gRacers[index];
    if (D_800DCE5C == 0) {
        if (temp_t0->stateFlags & RACER_STATE_FLAGS_80000) {
            arg0->unk_04 = 7;
            func_80085B80(arg0, arg1, arg2);
            return;
        }
        if (temp_t0->stateFlags & RACER_STATE_FLAGS_2000000) {
            if ((gNumPlayers >= 2) && (D_800E5FBC != 0)) {
                arg0->unk_04 = 9;
                func_80085B80(arg0, arg1, arg2);
                return;
            }
            if (gGameMode == GAMEMODE_TIME_ATTACK) {
                if ((gCurrentGhostType != GHOST_STAFF) && (gCurrentGhostType != GHOST_CELEBRITY) &&
                    (gCurrentGhostType != GHOST_CHAMP)) {
                    arg0->unk_04 = 8;
                } else if (temp_t0->raceTime < gFastestGhostTime) {
                    arg0->unk_04 = 8;
                } else {
                    arg0->unk_04 = 10;
                }
            } else {
                arg0->unk_04 = 8;
            }
            func_80085B80(arg0, arg1, arg2);
            return;
        }
    }

    controller = &gControllers[gPlayerControlPorts[index]];
    var_v1 = false;

    if (!(temp_t0->stateFlags & RACER_STATE_FLAGS_40000) && (controller->buttonPressed & BTN_CRIGHT)) {
        var_v1 = true;
        if (++arg0->unk_08 == 4) {
            arg0->unk_08 = 0;
        }
    }
    if (var_v1) {
        func_80082624(arg0, &arg1->unk_04, temp_a2, gNumPlayers);
    }
    temp_a1 = &arg1->unk_04;
    if ((D_800CD8A4 != 0) && (D_800DCE5C == 0)) {
        if ((controller->buttonCurrent & BTN_CUP) && !(temp_t0->stateFlags & RACER_STATE_FLAGS_40000)) {
            if (++arg0->unk_0C > D_800CDA9C) {
                arg0->unk_0C = D_800CDA9C;
            }
        } else {
            if (--arg0->unk_0C < 0) {
                arg0->unk_0C = 0;
            }
        }
        temp_a2->unk_68[8] = (arg0->unk_0C * 180.0f) / D_800CDA9C;
    }
    if (arg0->unk_10 & 1) {

        var_fv1 = sqrtf(SQ(temp_t0->unk_5C.x) + SQ(temp_t0->unk_5C.z)) - D_800CDA90;
        if (var_fv1 < 0.0f) {
            var_fa0 = arg0->unk_14;
        } else {
            var_fv1 /= (D_800CDA94 - D_800CDA90);
            if (var_fv1 > 1.0f) {
                var_fv1 = 1.0f;
            }

            var_fa0 = arg0->unk_14 + ((120.0f - arg0->unk_14) * var_fv1);
        }
        if (arg0->unk_10 & 2) {
            temp_a1->unk_00.unk_18[8] = var_fa0;
        } else {
            temp_a1->unk_00.unk_18[8] = var_fa0;
            temp_a1->unk_00.unk_18[7] = var_fa0;
        }
    }
    var_fv1 = temp_a1->unk_00.unk_18[8] - temp_a1->unk_00.unk_18[7];

    if (ABS(var_fv1) < 0.1f) {
        arg0->unk_10 &= ~2;
    }
}

void func_80087DB8(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 index = arg0->unk_00;

    if (gRacers[index].stateFlags & RACER_STATE_FLAGS_80000) {
        arg0->unk_04 = 7;
        func_80085B80(arg0, arg1, arg2);
    }
}

extern s8 D_i5_801190D0;

void func_80087E14(unk_struct_1DC* arg0, unk_struct_F8* arg1) {
    s32 i;
    unk_struct_9C* temp_v0 = &arg1->unk_04.unk_58;

    if (D_i5_801190D0 != 0) {
        temp_v0->unk_00.unk_00.unk_48.y += 1.0f;
        if (temp_v0->unk_00.unk_00.unk_48.y >= 360.0f) {
            temp_v0->unk_00.unk_00.unk_48.y -= 360.0f;
        }
        if (arg0->unk_18 == 0) {
            for (i = 0; i < gNumPlayers; i++) {
                Controller* controller = &gControllers[gPlayerControlPorts[i]];

                if (controller->buttonCurrent & BTN_CUP) {
                    temp_v0->unk_00.unk_00.unk_3C.y += 0.1f;
                }
                if (controller->buttonCurrent & BTN_CDOWN) {
                    temp_v0->unk_00.unk_00.unk_3C.y -= 0.1f;
                }
            }
        } else {
            arg0->unk_18 = 0;
            temp_v0->unk_00.unk_00.unk_3C.y = 20.0f;
        }

        if (temp_v0->unk_00.unk_00.unk_3C.y < -50.0f) {
            temp_v0->unk_00.unk_00.unk_3C.y = -50.0f;
        } else if (temp_v0->unk_00.unk_00.unk_3C.y > 90.0f) {
            temp_v0->unk_00.unk_00.unk_3C.y = 90.0f;
        }
    }
}

void func_80087F60(unk_struct_1DC* arg0, unk_struct_F8* arg1) {
    arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00 = gRacers[arg0->unk_00].unk_0C.unk_34;
}

void func_80087FAC(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    unk_struct_9C* temp_v1 = &arg1->unk_04.unk_58;
    Vec3f* temp_s1 = &D_800E5E90[arg0->unk_00];
    unk_800CD970* temp_a3 = &D_800CD970[arg0->unk_18];
    unk_8008112C_arg_1* temp_t0 = &arg1->unk_04;
    s16 temp_t1 = temp_a3->unk_00;
    Racer* temp_t2 = &gRacers[arg0->unk_00];
    unk_800CD8B0* temp_v0_2;
    s32 pad[2];

    if (temp_t2->stateFlags & RACER_STATE_FLAGS_80000) {
        arg0->unk_04 = 7;
        func_80085B80(arg0, arg1, arg2);
        return;
    }
    switch (temp_a3->unk_00) {
        case 0:
            temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_t2->unk_180;
            temp_v1->unk_00.unk_00.unk_00.unk_0C.x = temp_s1->x;
            temp_v1->unk_00.unk_00.unk_00.unk_0C.y = temp_s1->y;
            temp_v1->unk_00.unk_00.unk_00.unk_0C.z = temp_s1->z;
            break;
        case 1:
            temp_v0_2 = (unk_800CD8B0*) temp_a3->unk_08;

            *((Mtx3F*) &temp_v1->unk_00.unk_00.unk_00.unk_0C) = temp_t2->unk_C0;

            temp_t0->unk_00.unk_18[3] = temp_v1->unk_00.unk_00.unk_00.unk_18;
            temp_t0->unk_00.unk_18[4] = temp_v1->unk_00.unk_00.unk_00.unk_1C;
            temp_t0->unk_00.unk_18[5] = temp_v1->unk_00.unk_00.unk_20;
            temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_t2->unk_180;

            temp_v1->unk_00.unk_00.unk_3C.x =
                temp_v0_2->unk_00.x +
                ((((temp_v0_2->unk_0C.x - temp_v0_2->unk_00.x) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_30);
            temp_v1->unk_00.unk_00.unk_3C.y =
                temp_v0_2->unk_00.y +
                ((((temp_v0_2->unk_0C.y - temp_v0_2->unk_00.y) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_30);
            temp_v1->unk_00.unk_00.unk_3C.z =
                temp_v0_2->unk_00.z +
                ((((temp_v0_2->unk_0C.z - temp_v0_2->unk_00.z) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_30);

            temp_v1->unk_00.unk_54.x =
                temp_v0_2->unk_18.x +
                ((((temp_v0_2->unk_24.x - temp_v0_2->unk_18.x) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_34);
            temp_v1->unk_00.unk_54.y =
                temp_v0_2->unk_18.y +
                ((((temp_v0_2->unk_24.y - temp_v0_2->unk_18.y) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_34);
            temp_v1->unk_00.unk_54.z =
                temp_v0_2->unk_18.z +
                ((((temp_v0_2->unk_24.z - temp_v0_2->unk_18.z) * arg0->unk_1C) / temp_a3->unk_02) * temp_v0_2->unk_34);
        default:
            break;
    }

    if (arg0->unk_1C >= temp_a3->unk_02) {
        arg0->unk_1C = 0;
        if (++arg0->unk_18 >= 5) {
            arg0->unk_04 = 9;
            func_80085B80(arg0, arg1, arg2);
            return;
        }
        temp_a3 = &D_800CD970[arg0->unk_18];
        temp_t0->unk_00.unk_18[8] = temp_a3->unk_04;

        switch (temp_a3->unk_00) {
            case 0:
                if (temp_t1 != temp_a3->unk_00) {
                    func_800810E0(arg1, &D_800D4C80.unk_58);
                }
                temp_t0->unk_00.unk_18[3] = 0.0f;
                temp_t0->unk_00.unk_18[4] = 1.0f;
                temp_t0->unk_00.unk_18[5] = 0.0f;
                func_80088408(temp_s1, temp_t2->unk_0C.courseSegment, temp_t2->unk_0C.unk_04, temp_a3);
                temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_t2->unk_180;
                temp_v1->unk_00.unk_00.unk_00.unk_0C.x = temp_s1->x;
                temp_v1->unk_00.unk_00.unk_00.unk_0C.y = temp_s1->y;
                temp_v1->unk_00.unk_00.unk_00.unk_0C.z = temp_s1->z;
                break;
            case 1:
                if (temp_t1 != temp_a3->unk_00) {
                    func_80081318(arg1, &D_800D4E98.unk_58);
                }
                temp_v0_2 = (unk_800CD8B0*) temp_a3->unk_08;
                temp_v1->unk_00.unk_00.unk_3C = temp_v0_2->unk_00;
                temp_v1->unk_00.unk_54 = temp_v0_2->unk_18;
                break;
            default:
                break;
        }
    } else {
        arg0->unk_1C++;
    }
}

void func_80088408(Vec3f* arg0, CourseSegment* arg1, f32 arg2, unk_800CD970* arg3) {
    f32 abs;
    f32 sp60;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 var_fa0;
    f32 var_fv0;
    Mtx3F sp2C;
    unk_800CD8B0* sp28 = (unk_800CD8B0*) arg3->unk_08;

    sp60 = func_80082428(&arg1, arg2, sp28->unk_00.x);

    func_8009E6F0(arg1, sp60, arg0);
    func_800825A4(&sp2C, arg1, sp60);

    temp_ft4 = arg1->radiusLeft * (1.0f - sp60) + arg1->next->radiusLeft * sp60;
    temp_fa1 = arg1->radiusRight * (1.0f - sp60) + arg1->next->radiusRight * sp60;

    switch (arg1->trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_CYLINDER:
            var_fv0 = sp28->unk_00.y * temp_fa1;
            var_fa0 = sp28->unk_00.z + temp_fa1;
            break;
        case TRACK_SHAPE_HALF_PIPE:
            var_fv0 = sp28->unk_00.y * temp_ft4;
            var_fa0 = sp28->unk_00.z;
            break;
        default:
            if (sp28->unk_00.y >= 0.0f) {
                var_fv0 = sp28->unk_00.y * temp_ft4;
            } else {
                var_fv0 = sp28->unk_00.y * temp_fa1;
            }
            var_fa0 = sp28->unk_00.z;
            break;
    }

    abs = ABS(var_fv0);
    if (D_800CDA98 < abs) {
        abs = D_800CDA98;
        if (var_fv0 < 0) {
            var_fv0 = 0.0f - abs;
        } else {
            var_fv0 = abs;
        }
    }

    arg0->x += (sp2C.xy * var_fa0) + (sp2C.xz * var_fv0);
    arg0->y += (sp2C.yy * var_fa0) + (sp2C.yz * var_fv0);
    arg0->z += (sp2C.zy * var_fa0) + (sp2C.zz * var_fv0);
}

void func_800885F0(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {

    if (arg0->unk_1C <= 60) {
        arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00 = gRacers[arg0->unk_00].unk_0C.unk_34;
        arg0->unk_1C++;
    }
}

extern s32 gNumPlayers;

void func_80088660(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 pad;
    f32 temp;
    unk_struct_9C* temp_v1 = &arg1->unk_04.unk_58;
    Racer* temp_a3 = &gRacers[arg0->unk_00];
    unk_8008112C_arg_1* temp_a0 = &arg1->unk_04;

    if (temp_a3->stateFlags & RACER_STATE_FLAGS_80000) {
        arg0->unk_04 = 7;
        func_80085B80(arg0, arg1, arg2);
        return;
    }
    temp_v1->unk_00.unk_00.unk_00.unk_18 += temp_a3->unk_B4.x * 0.3f;
    temp_v1->unk_00.unk_00.unk_00.unk_1C += temp_a3->unk_B4.y * 0.3f;
    temp_v1->unk_00.unk_00.unk_20 += temp_a3->unk_B4.z * 0.3f;

    func_8006AC10((Mtx3F*) &temp_v1->unk_00.unk_00.unk_00.unk_0C);

    temp_a0->unk_00.unk_18[3] = temp_v1->unk_00.unk_00.unk_00.unk_18;
    temp_a0->unk_00.unk_18[4] = temp_v1->unk_00.unk_00.unk_00.unk_1C;
    temp_a0->unk_00.unk_18[5] = temp_v1->unk_00.unk_00.unk_20;

    temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_a3->unk_180;

    switch (arg0->unk_18) {
        case 0:
            if (++arg0->unk_1C >= 0xB4) {
                arg0->unk_18 = 1;
                arg0->unk_1C = 0;
                temp_v1->unk_00.unk_00.unk_30.z = 0.005f;
            }
            break;
        case 1:
            if (++arg0->unk_1C >= 0x12C) {
                arg0->unk_1C = 0;
                temp_v1->unk_00.unk_00.unk_30.y = (Math_Rand1() % 451) + 50.0f;
            }
            temp_v1->unk_00.unk_00.unk_48.y += 0.4f;

            if (temp_v1->unk_00.unk_00.unk_48.y >= 360.0f) {
                temp_v1->unk_00.unk_00.unk_48.y -= 360.0f;
            }
            break;
        default:
            break;
    }

    if ((D_800CD8A0 == arg0->unk_00) && (gNumPlayers == 2)) {

        if (arg0->unk_E4 < arg0->unk_E6) {
            temp = (f32) (arg0->unk_E4 + 1) / arg0->unk_E6;
            arg1->unk_04.unk_00.unk_18[13] = -30.0f - (-30.0f * temp);
        } else {
            arg1->unk_04.unk_00.unk_18[13] = 0.0f;
        }
    }
}

bool func_80088CB8(s32);

extern unk_struct_C D_i7_8014A4D0[];
extern unk_struct_C D_i7_8014A7E0[];
extern unk_struct_C D_i7_8014AB60[];
extern unk_struct_C D_i7_8014B070[];
extern unk_struct_C D_i7_8014B190[];
extern unk_struct_C D_i7_8014B310[];
extern u16 D_i7_8014BDF6;

void func_800888D0(unk_struct_1DC* arg0, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 var_s3 = true;
    Racer* temp_a3;
    unk_struct_9C* temp_v0;
    unk_struct_C* var_a1;

    while (var_s3) {

        var_s3 = false;
        switch (arg0->unk_18) {
            case 0:
                if (func_80088CB8(1)) {
                    if (D_i7_8014BDF6 & 0x40) {
                        var_s3 = true;
                        arg0->unk_18 = 2;
                        func_80081318(arg1, &D_800D4E98.unk_58);
                        arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.z = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.y = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.x = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_54.x = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_54.y = 37.0f;
                        arg1->unk_04.unk_58.unk_00.unk_54.z = -132.0f;
                    } else {
                        arg0->unk_18 = 1;
                        arg0->unk_1C = 0;
                        if (D_800E5E88 == 0) {
                            var_a1 = D_i7_8014A4D0;
                        } else if (D_800E5E88 == 1) {
                            var_a1 = D_i7_8014AB60;
                        } else {
                            var_a1 = D_i7_8014A7E0;
                        }
                        func_80083574(arg2, var_a1);
                        temp_a3 = &gRacers[D_800E5E88];
                        func_80083558(&D_800E5D70[arg0->unk_00], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
                    }
                }
                break;
            case 1:
                if (func_800835B0(arg2)) {
                    arg0->unk_18 = 2;
                    arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.x = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.y = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.z = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_54.x = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_54.y = 37.0f;
                    var_s3 = true;
                    temp_v0 = &arg1->unk_04.unk_58;
                    if (D_i7_8014BDF6 & 2) {
                        temp_v0->unk_00.unk_54.z = 132.0f;
                    } else {
                        temp_v0->unk_00.unk_54.z = -132.0f;
                    }
                }
                break;
            case 2:
                temp_a3 = &gRacers[D_800E5E88];
                *((Mtx3F*) &arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C) = temp_a3->unk_C0;
                arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00 = temp_a3->unk_180;
                if (func_80088CB8(4)) {
                    arg0->unk_18 = 3;
                    arg0->unk_1C = 0;
                    temp_a3 = &gRacers[2];
                    func_80083558(&D_800E5D70[arg0->unk_00], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
                    func_80083574(arg2, D_i7_8014B310);
                }
                break;
            case 3:
                if (func_800835B0(arg2) && func_80088CB8(3)) {
                    arg0->unk_18 = 4;
                    arg0->unk_1C = 0;
                    temp_a3 = &gRacers[1];
                    func_80083558(&D_800E5D70[arg0->unk_00], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
                    func_80083574(arg2, D_i7_8014B190);
                }
                break;
            case 4:
                if (func_800835B0(arg2) && func_80088CB8(2)) {
                    arg0->unk_18 = 5;
                    arg0->unk_1C = 0;
                    temp_a3 = &gRacers[0];
                    func_80083558(&D_800E5D70[arg0->unk_00], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
                    func_80083574(arg2, D_i7_8014B070);
                }
                break;
            case 5:
                func_800835B0(arg2);
                break;
        }
    }
    // FAKE, likely some recast somewhere
    if (!arg1) {}
}

extern s32 D_800E5E84;

void func_80088CAC(s32 arg0) {
    D_800E5E84 = arg0;
}

bool func_80088CB8(s32 arg0) {
    bool var_v1 = false;

    if (arg0 == D_800E5E84) {
        var_v1 = true;
        D_800E5E84 = 0;
    }
    return var_v1;
}

s32 func_80088CE0(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800E5EC0; i++) {
        if (arg0 == gRacers[i].position) {
            return i;
        }
    }
    return -1;
}

void func_i3_80115E74(void);
s32 func_8009EBEC(Racer_unk_C*, f32, f32, f32, s32, f32);

extern s32 gNumPlayers;
extern s8 D_800CD010;

extern CourseRecordInfo* gCurrentCourseRecordInfo;
extern Vec3f D_802C4938;

void func_80088D28(void) {
    f32 var_fs0;
    f32 var_fs4;
    f32 var_fv0;
    s32 i;
    s32 j;
    CourseSegment* var_s2;
    Racer* temp_s1;
    s32 index;

    func_i3_80115E74();

    var_s2 = gCurrentCourseRecordInfo->courseSegments->prev;
    var_fs0 = 1.0f;
    for (i = 20; i > 0; i--) {
        var_fs0 -= 7.3f / func_8009E538(var_s2, var_fs0, &D_802C4938);
    }

    if ((gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS) && (D_800CD010 == 0)) {
        if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
            var_fs4 = 1.99f;
        } else {
            var_fs4 = 0;
        }
    } else {
        var_fs4 = 7.99f;
    }

    for (j = 1; j <= D_800E5EC0; j++) {
        index = func_80088CE0(j);
        temp_s1 = &gRacers[index];
        temp_s1->unk_0C.courseSegment = var_s2;
        temp_s1->unk_0C.unk_04 = var_fs0;
        func_8009E6F0(var_s2, var_fs0, &temp_s1->unk_0C.unk_1C);
        temp_s1->unk_0C.unk_34 = temp_s1->unk_0C.unk_44 = temp_s1->unk_0C.unk_1C;
        temp_s1->unk_0C.unk_28.x = 0.0f;
        temp_s1->unk_0C.unk_28.y = 0.0f;
        temp_s1->unk_0C.unk_28.z = 0.0f;
        temp_s1->unk_0C.unk_40 = 0.0f;
        temp_s1->unk_0C.unk_18 =
            func_8009E538(temp_s1->unk_0C.courseSegment, temp_s1->unk_0C.unk_04, &temp_s1->unk_0C.unk_0C);
        temp_s1->unk_0C.unk_08 =
            func_8009E108(temp_s1->unk_0C.courseSegment, temp_s1->unk_0C.unk_04, &temp_s1->unk_244);
        func_8009E85C(temp_s1->unk_0C.courseSegment, temp_s1->unk_0C.unk_04, &temp_s1->unk_24C, temp_s1->unk_0C.unk_08);
        if (D_800E5EC0 >= 4) {
            var_fv0 = 3.0f;
        } else {
            var_fv0 = D_800E5EC0 - 1;
        }
        var_fv0 = (((j - 1) & 3) * 2 - var_fv0) * 50.0f;
        func_8009EBEC(&temp_s1->unk_0C,
                      temp_s1->unk_0C.unk_34.x + (var_fs4 * temp_s1->unk_24C.xy) + (var_fv0 * temp_s1->unk_24C.xz),
                      temp_s1->unk_0C.unk_34.y + (var_fs4 * temp_s1->unk_24C.yy) + (var_fv0 * temp_s1->unk_24C.yz),
                      temp_s1->unk_0C.unk_34.z + (var_fs4 * temp_s1->unk_24C.zy) + (var_fv0 * temp_s1->unk_24C.zz), 100,
                      1.0f);
        if (gNumPlayers == 1) {
            var_fv0 = 100.0f;
        } else {
            var_fv0 = 0.1f;
        }

        for (i = 20; i > 0; i--) {
            var_fs0 -= (var_fv0 / 20.0f) / temp_s1->unk_0C.unk_18;
            if (var_fs0 < 0.0f) {
                var_s2 = var_s2->prev;
                var_fs0 *= (temp_s1->unk_0C.unk_18 / func_8009E538(var_s2, 1.0f, &temp_s1->unk_0C.unk_0C));
                var_fs0 += 1.0f;
            }
        }
    }
}

extern s8 D_800CD010;

void func_800890B4(void) {
    s16 temp_a0;
    s16 temp_a1;
    s32 var_a2;
    s32 var_a3;
    s32 temp_t5;
    s32 temp_t9;
    Racer* temp;
    Racer* var_a0;
    Racer* var_v0;
    Racer* var_v1;

    if ((gGameMode != GAMEMODE_GP_RACE) || ((D_800E5EC0 - D_800E5FC2) < 2) || (D_800CD010 != 0)) {
        D_800E5EC8 = NULL;
        return;
    }
    var_v0 = gRacers;
    while (var_v0->stateFlags & RACER_STATE_FLAGS_40000) {
        var_v0++;
    }
    var_v1 = var_v0 + 1;
    while (var_v1->stateFlags & RACER_STATE_FLAGS_40000) {
        var_v1++;
    }

    if (var_v0->unk_0A < var_v1->unk_0A) {
        temp = var_v0;
        var_v0 = var_v1;
        var_v1 = temp;
        var_a2 = var_v1->unk_0A;
        var_a3 = var_v0->unk_0A;
    } else {
        var_a2 = var_v0->unk_0A;
        var_a3 = var_v1->unk_0A;
    }

    var_a0 = D_800E5EC4;
    do {
        if (!(var_a0->stateFlags & RACER_STATE_FLAGS_40000)) {
            if (var_a2 < var_a0->unk_0A) {
                var_v1 = var_v0;
                var_a3 = var_a2;
                var_v0 = var_a0;
                var_a2 = var_a0->unk_0A;
            } else if ((var_a3 < var_a0->unk_0A) && (var_a0 != var_v0)) {
                var_v1 = var_a0;
                var_a3 = var_a0->unk_0A;
            }
        }
        var_a0--;
    } while (var_a0 >= gRacers);

    if (var_a2 == 0) {
        D_800E5EC8 = NULL;
        return;
    }
    if (var_v0 == gRacers) {
        D_800E5EC8 = var_v1;
        return;
    }
    D_800E5EC8 = var_v0;
}

void func_i3_80128D8C(void);
void func_i3_TriggerLivesIncrease(void);

void func_80089220(s32 playerNum) {

    gPlayerLives[playerNum]++;

    func_i3_80128D8C();
    func_i3_TriggerLivesIncrease();
    if (D_800E5FD0 != 0) {
        func_800BA8D8(0);
    }
    D_800F80C4 = 0;
}

void func_i3_TriggerLivesDecrease(void);

void func_8008927C(s32 arg0) {

    if (--gPlayerLives[arg0] >= 0) {
        func_i3_TriggerLivesDecrease();
    }
    if (D_800E5FD0 != 0) {
        func_800BA8D8(44);
    }
    D_800F80C4 = 0;
}

void func_800892E0(Racer* arg0) {

    if (!(arg0->stateFlags & (RACER_STATE_FLAGS_2000000 | RACER_STATE_FLAGS_40000))) {
        arg0->stateFlags |= RACER_STATE_FLAGS_40000;
        arg0->energy = 0.0f;
        D_800E5FC2++;
        if (arg0->id < gNumPlayers) {
            D_800E5FC8++;
        } else if (D_800E5FBC == 0) {
            D_800E5FC6++;
            if ((gGameMode == GAMEMODE_DEATH_RACE) && (D_800E5EC0 == (D_800E5FC6 + 1))) {
                gRacers[0].stateFlags |= (RACER_STATE_FLAGS_2000000 | RACER_STATE_FLAGS_800000);
                gRacers[0].raceTime += Math_Rand2() % 16;
                D_800E5FBC = 1;
                gRacers[0].energy = gRacers[0].maxEnergy;
                D_800F5DE8 = D_800E5FBC;
                func_800BA2B4(gRacers[0].id);
                func_800BAB68(gRacers[0].id);
                func_8007E0CC();
            }
        }
        arg0->unk_248 = (D_800E5FD8 + ((D_800E5EC0 - arg0->position) / 10.0f)) - 600000.0f;
        if (gGameMode == GAMEMODE_GP_RACE) {
            if (arg0->id < gNumPlayers) {
                D_800F80C4 = -1;
            }
            if (arg0 == D_800E5EC8) {
                func_800890B4();
            }
        }
    }
}

void func_800894C0(Racer* arg0) {

    if (D_800E5FD0 != 0) {
        if (arg0->unk_08 & 0x800) {
            arg0->unk_08 &= ~0x800;
            func_800BA3E4(arg0->id, 4);
        }
        if (arg0->unk_08 & 0x400) {
            arg0->unk_08 &= ~0x400;
            func_800BA3E4(arg0->id, 5);
        }
        if (arg0->unk_08 & 0x20) {
            arg0->unk_08 &= ~0x20;
            func_800BA3E4(arg0->id, 11);
        }
        if (arg0->unk_08 & 0x200) {
            arg0->unk_08 &= ~0x200;
            func_800BA3E4(arg0->id, 6);
        }
        if (arg0->unk_08 & 0x40) {
            arg0->unk_08 &= ~0x40;
            func_800BA3E4(arg0->id, 10);
        }
        if (arg0->unk_08 & 0x2000) {
            arg0->unk_08 &= ~0x2000;
            func_800BA3E4(arg0->id, 8);
        }
        if (arg0->unk_08 & 0x100) {
            arg0->unk_08 &= ~0x100;
            func_800BAB50(arg0->id);
        }
        if (arg0->unk_08 & 0x80) {
            arg0->unk_08 &= ~0x80;
            func_800BA3E4(arg0->id, 9);
        }
        func_800BAB68(arg0->id);
    } else {
        arg0->unk_08 &= ~(0x800 | 0x400 | 0x20 | 0x200 | 0x40 | 0x2000 | 0x100 | 0x80);
    }
}

// todo: figure out 0.6899998f as a fraction
f32 func_8008960C(f32 arg0) {
    if (arg0 != 0.0f) {
        return 1.0f / (((1.0f + 0.6899998f) / arg0) - 0.6899998f);
    }
    return 0.0f;
}

f32 func_80089654(f32 arg0) {
    if (arg0 != 0.0f) {
        return (1.0f + 0.6899998f) / ((1.0f / arg0) + 0.6899998f);
    }
    return 0.0f;
}

void func_8008969C(void) {
    s32 i;

    for (i = gNumPlayers - 1; i >= 0; i--) {
        gRacers[i].character = D_800E5EE0[i];
        gRacers[i].unk_2CC = D_800E5EE8[i];
    }
}

void func_80089724(void) {
    s32 i;

    for (i = gNumPlayers - 1; i >= 0; i--) {
        D_800E5EE0[i] = gRacers[i].character;
        D_800E5EE8[i] = gRacers[i].unk_2CC;
        gRacers[i].unk_1A8 = func_8008960C(gPlayerEngine[i]);
    }
}

void func_80089800(void) {
    s32 i;
    s16 j;
    s32 index0;
    s32 index1;

    j = 0;

    for (i = 1; i < 30; i++) {
        if (j == D_800E5EE0[0]) {
            j++;
        }
        gRacers[i].character = j++;
        gRacers[i].unk_2CC = 0;
    }

    for (i = 0; i < 28; i++) {
        index0 = (Math_Rand1() & 0x1FFFF) % 29 + 1;
        index1 = (Math_Rand2() & 0x1FFFF) % 29 + 1;

        j = gRacers[index0].character;
        gRacers[index0].character = gRacers[index1].character;
        gRacers[index1].character = j;
    }
}

void func_80089934(void) {
    s32 i;
    s32 j;
    s32 var_s0;
    Racer* temp_s1;
    Racer* var_v0;

    for (i = 1; i < D_800E5EC0; i++) {
        if (i >= gNumPlayers) {
            do {
                gRacers[i].character = (Math_Rand2() & 0x1FFFF) % 30;
                gRacers[i].unk_2CC = (Math_Rand1() & 0x1FFFF) % 4;
                for (j = 0; j < gNumPlayers; j++) {
                    if ((gRacers[i].character == gRacers[j].character) && (gRacers[i].unk_2CC == gRacers[j].unk_2CC)) {
                        break;
                    }
                }
            } while (j < gNumPlayers);
        }
    }
}

void func_80089A74(CarInfo* arg0) {
    u8 var_v0;
    u8* temp_v0;

    arg0->character = gRacers[0].character;
    arg0->envR2 = (s32) gRacers[0].unk_2E0;
    arg0->envG2 = (s32) gRacers[0].unk_2E4;
    arg0->envB2 = (s32) gRacers[0].unk_2E8;
    arg0->customType = var_v0 = gRacers[0].unk_167;
    if (var_v0 == 1) {
        temp_v0 = D_800F8360[gRacers[0].character];
        arg0->frontType = temp_v0[0];
        arg0->rearType = temp_v0[1];
        arg0->wingType = temp_v0[2];
        arg0->logo = temp_v0[3];
        arg0->decal = D_800F80C8[gRacers[0].character].unk_10 - 1;
        arg0->number = temp_v0[4];
        arg0->primR1 = temp_v0[5];
        arg0->primG1 = temp_v0[6];
        arg0->primB1 = temp_v0[7];
        arg0->primR2 = temp_v0[8];
        arg0->primG2 = temp_v0[9];
        arg0->primB2 = temp_v0[10];
        arg0->envR1 = temp_v0[11];
        arg0->envG1 = temp_v0[12];
        arg0->envB1 = temp_v0[13];
    } else {
        arg0->frontType = arg0->rearType = arg0->wingType = arg0->logo = arg0->decal = arg0->number = arg0->primR1 =
            arg0->primG1 = arg0->primB1 = arg0->primR2 = arg0->primG2 = arg0->primB2 = arg0->envR1 = arg0->envG1 =
                arg0->envB1 = 0;
    }
}

void func_80089BD0(void) {
    s32 i;
    s32 j;
    s32 var_a1_3;
    s32* var_a0_3;
    s32* var_v1_10;
    Ghost* ghost;

    if (D_800F5DE8 != 0) {
        for (i = 0; i < 5; i++) {
            if (gRacers[0].raceTime < gCurrentCourseRecordInfo->timeRecord[i]) {
                D_800E5FE2 = i + 1;

                for (j = 3; j >= i; j--) {

                    gCurrentCourseRecordInfo->timeRecord[j + 1] = gCurrentCourseRecordInfo->timeRecord[j];
                    gCurrentCourseRecordInfo->carInfo[j + 1] = gCurrentCourseRecordInfo->carInfo[j];
                    gCurrentCourseRecordInfo->engine[j + 1] = gCurrentCourseRecordInfo->engine[j];
                    *(s32*) &gCurrentCourseRecordInfo->name[j + 1] = *(s32*) &gCurrentCourseRecordInfo->name[j];

                    D_800F8504[j + 1] = D_800F8504[j];
                }

                gCurrentCourseRecordInfo->timeRecord[i] = gRacers[0].raceTime;

                func_80089A74(&gCurrentCourseRecordInfo->carInfo[i]);

                gCurrentCourseRecordInfo->engine[i] = gPlayerEngine[0];
                D_800F8504[i] = gRacers[0].unk_2C9;
                break;
            }
        }

        if (gCurrentCourseRecordInfo->maxSpeed < gRacers[0].maxSpeed) {
            D_800E5FE4 = 1;
            gCurrentCourseRecordInfo->maxSpeed = gRacers[0].maxSpeed;

            func_80089A74(&gCurrentCourseRecordInfo->maxSpeedCar);
            D_800F8504[5] = gRacers[0].unk_2C9;
        }

        var_a1_3 = gCurrentCourseRecordInfo->bestTime;
        for (i = 0; i < 3; i++) {
            if (gRacers[0].lapTimes[i] < var_a1_3) {
                j = i;
                var_a1_3 = gRacers[0].lapTimes[i];
            }
        }

        if (var_a1_3 < gCurrentCourseRecordInfo->bestTime) {
            D_800E5FE6 = j + 1;
            gCurrentCourseRecordInfo->bestTime = var_a1_3;
            func_80089A74(&gCurrentCourseRecordInfo->bestTimeCar);
            D_800F8504[6] = gRacers[0].unk_2C9;
        }
    }

    if (D_800F5DEA != 0) {
        for (j = 0; j < 3; j++) {
            if (gGhosts[j].encodedCourseIndex == 0) {
                break;
            }
        }

        var_a1_3 = -1;
        if (j == 3) {
            for (i = 0; i < 3; i++) {
                if ((gGhosts[i].encodedCourseIndex != gCurrentCourseRecordInfo->encodedCourseIndex) ||
                    ((gCurrentGhostType == GHOST_PLAYER) && (gGhosts[i].ghostType != GHOST_PLAYER))) {
                    j = i;
                    var_a1_3 = gGhosts[i].raceTime;
                    break;
                }
            }

            // FAKE
            if (1) {}

            if (var_a1_3 != -1) {
                for (i = j + 1; i < 3; i++) {
                    if ((gCurrentCourseRecordInfo->encodedCourseIndex != gGhosts[i].encodedCourseIndex) ||
                        ((gCurrentGhostType == GHOST_PLAYER) && (gGhosts[i].ghostType != GHOST_PLAYER))) {
                        if (var_a1_3 < gGhosts[i].raceTime) {
                            j = i;
                            var_a1_3 = gGhosts[i].raceTime;
                        }
                    }
                }
            } else {
                for (i = 0; i < 3; i++) {
                    if ((gCurrentCourseRecordInfo->encodedCourseIndex == gGhosts[i].encodedCourseIndex) &&
                        (gGhosts[i].ghostType == GHOST_PLAYER)) {
                        j = i;
                        var_a1_3 = gGhosts[i].raceTime;
                        break;
                    }
                }

                for (i = j + 1; i < 3; i++) {
                    if ((gCurrentCourseRecordInfo->encodedCourseIndex == gGhosts[i].encodedCourseIndex) &&
                        (gGhosts[i].ghostType == GHOST_PLAYER)) {
                        if (var_a1_3 < gGhosts[i].raceTime) {
                            j = i;
                            var_a1_3 = gGhosts[i].raceTime;
                        }
                    }
                }

                if (gRacers[0].raceTime >= var_a1_3) {
                    j = 3;
                }
            }
        }

        if (j < 3) {
            ghost = &gGhosts[j];

            for (i = 0; i < 3; i++) {
                if (ghost == gGhostRacers[i].ghost) {
                    gGhostRacers[i].exists = gGhostRacers[i].initialized = false;
                }
            }
            ghost->ghostType = GHOST_PLAYER;
            ghost->encodedCourseIndex = gCurrentCourseRecordInfo->encodedCourseIndex;
            ghost->raceTime = gRacers[0].raceTime;

            for (i = 0; i < 3; i++) {
                ghost->lapTimes[i] = gRacers[0].lapTimes[i];
            }

            ghost->replayEnd = sGhostReplayRecordingEnd;
            ghost->replaySize = sGhostReplayRecordingSize;

            func_80089A74(&ghost->carInfo);

            i = (sGhostReplayRecordingSize - 1) & ~3;
            var_v1_10 = (s32*) &sGhostReplayRecordingBuffer[i];
            var_a0_3 = (s32*) &ghost->replayData[i];
            ghost->replayChecksum = 0;
            do {
                ghost->replayChecksum += * var_a0_3-- = *var_v1_10--;
            } while (var_v1_10 >= (s32*) sGhostReplayRecordingBuffer);
            if ((gFastestGhost == NULL) || (ghost->raceTime < gFastestGhost->raceTime)) {
                gFastestGhost = ghost;
            }
        }
    }
}

void func_8008A978(void) {
    Racer* var_a1;
    Racer* var_a2;
    s32 var_a3;
    Racer* var_v0;
    s32 var_v1;
    s32 var_a0;
    f32 var_fv0;

    var_v0 = D_800E5EC4;
    do {
        var_v0->position = 0;
        var_v0--;
    } while (var_v0 >= gRacers);

    var_v1 = 1;
    var_a0 = D_800E5EC0;

    do {
        var_a1 = NULL;
        var_a2 = NULL;
        var_v0 = D_800E5EC4;
        // FAKE
        if (D_800E5F40[0]) {}

        do {
            if (var_v0->position == 0) {
                if (var_v0->stateFlags & RACER_STATE_FLAGS_2000000) {
                    if ((var_a2 == NULL) || (var_v0->raceTime < var_a3)) {
                        var_a3 = var_v0->raceTime;
                        var_a2 = var_v0;
                    }
                } else if ((var_a1 == NULL) || (var_v0->unk_248 < var_fv0)) {
                    var_fv0 = var_v0->unk_248;
                    var_a1 = var_v0;
                }
            }
            var_v0--;
        } while (var_v0 >= gRacers);

        if (var_a2 != NULL) {
            D_800E5F40[var_v1 - 1] = var_a2;

            var_a2->position = var_v1;
            var_v1++;
        }
        if (var_a1 != NULL) {
            D_800E5F40[var_a0 - 1] = var_a1;

            var_a1->position = var_a0;
            var_a0--;
        }
    } while (var_a0 >= var_v1);
}

extern s32 gTotalLapCount;

void func_8008AA8C(void) {
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    Racer* var_s0;
    Racer* var_v0;

    for (var_s0 = D_800E5EC4; var_s0 >= gRacers; var_s0--) {
        if (var_s0->stateFlags & RACER_STATE_FLAGS_2000000) {
            continue;
        }

        if (var_s0->stateFlags & RACER_STATE_FLAGS_8000000) {
            var_s0->raceTime = 0;
        } else if (var_s0->stateFlags & RACER_STATE_FLAGS_80000) {
            var_s0->stateFlags &= ~RACER_STATE_FLAGS_40000000;
            var_s0->stateFlags |= RACER_STATE_FLAGS_8000000;
            D_800E5FC0++;
            func_800892E0(var_s0);
            var_s0->raceTime = 0;
        } else {
            var_s0->stateFlags |= RACER_STATE_FLAGS_2000000;
            var_a0 = 0;
            if (var_s0->lapTimes[1] != 0) {
                var_a1 = var_s0->lapTimes[0] - var_s0->lapTimes[1];
                if (var_a1 < 0) {
                    var_a1 = 0;
                }
            } else {
                var_a1 = 0;
            }

            var_s0->raceTime = (s32) (((var_s0->raceTime - var_a1) * gTotalLapCount) *
                                      gCurrentCourseRecordInfo->length / var_s0->unk_23C) +
                               var_a1;

            var_a1 = 0;
            var_a0 = 0;
            while (true) {
                if (var_s0->lapTimes[var_a0] == 0) {
                    break;
                }

                var_a1 += var_s0->lapTimes[var_a0];

                var_a0++;

                if (var_a0 >= gTotalLapCount) {
                    break;
                }
            }

            while (var_a0 < gTotalLapCount) {
                var_s0->lapTimes[var_a0] = (var_s0->raceTime - var_a1) / (gTotalLapCount - var_a0);
                var_a1 += var_s0->lapTimes[var_a0];
                var_a0++;
            }
        }
    }
    func_8008A978();
    if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].stateFlags & RACER_STATE_FLAGS_2000000)) {
        var_v1 = D_800E5EC0 - 1;
        while (var_v1 >= 0) {
            if (D_800E5F40[var_v1]->raceTime != 0) {
                break;
            }
            var_v1--;
        }

        while (var_v1 >= 0) {
            D_800E5F40[var_v1]->unk_0A += D_800CE6C0[var_v1];
            var_v1--;
        }
        D_800E5FD6 = D_800E5FD4;
    }
}

void func_8008AD38(void) {
    Racer* var_a0;
    Racer* var_a1;
    f32 var_fv0;
    f32 var_fv1;
    Racer* sp14;
    f32 temp_fv1;
    f32 temp_fv0;
    s32 temp_a2;
    u32 i;
    unk_800F5EA0* var_v1;

    if (D_800E5EC0 < 2) {
        gRacers[0].unk_2B8 = gRacers[0].unk_2BC = NULL;
        gRacers[0].unk_2C0 = gRacers[0].unk_2C4 = gCurrentCourseRecordInfo->length;
        return;
    }

    temp_fv0 = gCurrentCourseRecordInfo->length * 0.5f;
    var_v1 = &D_800F5EA0[((s32) (D_800E5EC0 * (D_800E5EC0 - 1)) >> 1) - 1];
    var_a0 = D_800E5EC4;

    do {
        var_a1 = var_a0 - 1;
        do {
            temp_fv1 = var_a1->unk_244 - var_a0->unk_244;
            if (temp_fv1 < 0.0f) {
                temp_fv1 = -temp_fv1;
                if (temp_fv1 < temp_fv0) {
                    var_v1->unk_00 = var_a0;
                    var_v1->unk_04 = var_a1;
                    var_v1->unk_08 = temp_fv1;
                    var_v1->unk_0C = gCurrentCourseRecordInfo->length - temp_fv1;
                } else {
                    var_v1->unk_00 = var_a1;
                    var_v1->unk_04 = var_a0;
                    var_v1->unk_08 = gCurrentCourseRecordInfo->length - temp_fv1;
                    var_v1->unk_0C = temp_fv1;
                }
            } else if (temp_fv1 < temp_fv0) {
                var_v1->unk_00 = var_a1;
                var_v1->unk_04 = var_a0;
                var_v1->unk_08 = temp_fv1;
                var_v1->unk_0C = gCurrentCourseRecordInfo->length - temp_fv1;
            } else {
                var_v1->unk_00 = var_a0;
                var_v1->unk_04 = var_a1;
                var_v1->unk_08 = gCurrentCourseRecordInfo->length - temp_fv1;
                var_v1->unk_0C = temp_fv1;
            }
            var_a1--;
            var_v1--;
        } while (var_a1 >= gRacers);
        var_a0--;
    } while (var_a0 > gRacers);

    var_a0 = D_800E5EC4;
    temp_a2 = (s32) (var_a0->id * (var_a0->id - 1)) >> 1;

    var_fv0 = gCurrentCourseRecordInfo->length + 10.0f;

    for (var_a1 = var_a0 - 1; var_a1 >= gRacers; var_a1--) {

        var_a1->unk_2B8 = NULL;
        var_v1 = &D_800F5EA0[temp_a2 + var_a1->id];
        if (var_a1 == var_v1->unk_04) {
            var_fv1 = var_v1->unk_08;
        } else {
            var_fv1 = var_v1->unk_0C;
        }
        if (var_fv1 < var_fv0) {
            var_fv0 = var_fv1;
            sp14 = var_a1;
        }
    }

    var_a0->unk_2BC = sp14;
    sp14->unk_2B8 = var_a0;
    sp14->unk_2C0 = var_fv0;
    var_a0->unk_2C4 = var_fv0;

    for (i = D_800E5EC0 - 2; i > 0; i--) {
        var_a0 = sp14;
        var_fv0 = gCurrentCourseRecordInfo->length + 10.0f;
        temp_a2 = (s32) (sp14->id * (sp14->id - 1)) >> 1;

        for (var_a1 = gRacers; var_a1 < var_a0; var_a1++) {
            if (var_a1->unk_2B8 == NULL) {
                var_v1 = &D_800F5EA0[temp_a2 + var_a1->id];
                if (var_a1 == var_v1->unk_04) {
                    var_fv1 = var_v1->unk_08;
                } else {
                    var_fv1 = var_v1->unk_0C;
                }
                if (var_fv1 < var_fv0) {
                    var_fv0 = var_fv1;
                    sp14 = var_a1;
                }
            }
        }

        for (var_a1 = var_a1 + 1; var_a1 < D_800E5EC4; var_a1++) {
            if (var_a1->unk_2B8 != NULL) {
                continue;
            }

            temp_a2 = var_a1->id;
            var_v1 = &D_800F5EA0[((s32) (temp_a2 * (temp_a2 - 1)) >> 1) + var_a0->id];
            if (var_a1 == var_v1->unk_04) {
                var_fv1 = var_v1->unk_08;
            } else {
                var_fv1 = var_v1->unk_0C;
            }
            if (var_fv1 < var_fv0) {
                var_fv0 = var_fv1;
                sp14 = var_a1;
            }
        }
        var_a0->unk_2BC = sp14;
        sp14->unk_2B8 = var_a0;
        sp14->unk_2C0 = var_fv0;
        var_a0->unk_2C4 = var_fv0;
    }

    var_a0 = D_800E5EC4;
    sp14->unk_2BC = var_a0;
    var_a0->unk_2B8 = sp14;
    var_v1 = &D_800F5EA0[((s32) (var_a0->id * (var_a0->id - 1)) >> 1) + sp14->id];
    if (sp14 == var_v1->unk_00) {
        var_fv0 = var_v1->unk_08;
    } else {
        var_fv0 = var_v1->unk_0C;
    }
    var_a0->unk_2C0 = var_fv0;
    sp14->unk_2C4 = var_fv0;
}

void func_8008B150(void) {
    s32 i;
    f32 var_fv0;

    var_fv0 = gCurrentCourseRecordInfo->length;

    for (i = D_800E5EC0 - 1; i > 0; i--) {
        if (D_800F5EA0[(i * (i - 1)) >> 1].unk_08 < var_fv0) {
            var_fv0 = D_800F5EA0[(i * (i - 1)) >> 1].unk_08;
            D_800E5FB8 = i;
        }
    }
}

extern s32 gDifficulty;
extern s16 gLastRandomCourseIndex;

void func_8008B1CC(void) {
    s32 size = ARRAY_COUNT(gRacers) - 1;
    s32 i;

    if (size) {}

    D_800E5FD6 = D_800E5FF0 = 0;
    gLastRandomCourseIndex = -1;

    for (i = size; i >= 0; i--) {
        gRacers[i].unk_0A = 0;
    }

    gPlayerLives[0] = gPlayerLives[1] = gPlayerLives[2] = gPlayerLives[3] = gTotalLives[gDifficulty];
}

s32 func_8008B23C(CarInfo* arg0, CarInfo* arg1) {
    s32 i;
    u8* var_v0 = (u8*) arg0;
    u8* var_v1 = (u8*) arg1;

    for (i = sizeof(CarInfo); i > 0; i--, var_v0++, var_v1++) {
        if (*var_v0 != *var_v1) {
            return -1;
        }
    }

    return 0;
}

f32 func_8008B2D8(Racer*, f32);

f32 func_8008B2D8(Racer* arg0, f32 arg1) {
    unk_800CF1B0* temp_a1;
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fs1;
    f32 temp_fv1;
    f32 temp_ret;
    f32 temp_fa1;

    temp_fs0 = (arg0->unk_1F0 - 780.0f) / 1560.0f;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((f32) ((ROM_READ(0x078) >> 0xF) & 0xFF) * 0.1f) -
                 ((f32) (((ROM_READ(0x50C) >> 0x13) & 0xFF) | 0x600) * 0.001f)) *
                temp_fs0) +
               ((f32) (((ROM_READ(0x50C) >> 0x13) & 0xFF) | 0x600) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x780) >> 0x15) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x390) >> 9) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x390) >> 9) & 0xFF) * 0.001f);

    arg0->unk_1B4 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv0 - temp_fv1) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 = arg0->unk_1B4;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((f32) ((ROM_READ(0x0A0) >> 0x15) & 0xFF) * 0.1f) -
                 ((f32) (((ROM_READ(0x540) >> 0xD) & 0xFF) | 0x800) * 0.001f)) *
                temp_fs0) +
               ((f32) (((ROM_READ(0x540) >> 0xD) & 0xFF) | 0x800) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x95C) >> 0x13) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x50C) >> 6) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x50C) >> 6) & 0xFF) * 0.001f);
    arg0->unk_1B0 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv0 - temp_fv1) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 += arg0->unk_1B0;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        ((((f32) ((ROM_READ(0x1BC) >> 0x13) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x57C) >> 0xF) & 0xFF) * 0.1f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x57C) >> 0xF) & 0xFF) * 0.1f);
    temp_fv1 =
        (((((f32) ((ROM_READ(0x978) >> 0x15) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x550) >> 0x13) & 0xFF) * 0.001f)) *
          temp_fs0)) +
        ((f32) ((ROM_READ(0x550) >> 0x13) & 0xFF) * 0.001f);
    arg0->unk_1B8 = ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1B8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((f32) ((ROM_READ(0x2C4) >> 0xE) & 0xFF) - (f32) ((ROM_READ(0x5D8) >> 4) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x5D8) >> 4) & 0xFF);
    temp_fv1 = (((f32) ((ROM_READ(0x988) >> 0x18) & 0xFF) - (f32) ((ROM_READ(0x57C) >> 0xA) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x57C) >> 0xA) & 0xFF);
    arg0->unk_1BC = ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1BC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        ((((f32) ((ROM_READ(0x2FC) >> 0x12) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x660) >> 0x10) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x660) >> 0x10) & 0xFF) * 0.001f);
    temp_fv1 =
        (((((f32) ((ROM_READ(0xA20) >> 0xC) & 0xFF) * 0.01f) - ((f32) ((ROM_READ(0x5E4) >> 0x14) & 0xFF) * 0.01f)) *
          temp_fs0) +
         ((f32) ((ROM_READ(0x5E4) >> 0x14) & 0xFF) * 0.01f));
    arg0->unk_1C8 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv1 - temp_fv0) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 += arg0->unk_1C8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((f32) ((ROM_READ(0x36C) >> 0x10) & 0xFF) - (f32) ((ROM_READ(0x6A0) >> 0xC) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x6A0) >> 0xC) & 0xFF);
    temp_fv1 = ((((f32) ((ROM_READ(0x1BC) >> 0xA) & 0xFF) - (f32) ((ROM_READ(0x60C) >> 0x16) & 0xFF)) * temp_fs0) +
                (f32) ((ROM_READ(0x60C) >> 0x16) & 0xFF));
    arg0->unk_1CC = arg0->unk_1C8 / (((temp_fv1 - temp_fv0) * arg1) + temp_fv0 +
                                     (0.2f * (temp_fv1 - temp_fv0) * (1.0f - SQ((2.0f * arg1) - 1.0f))));
    temp_fs1 += arg0->unk_1CC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((ROM_READ(0x374) >> 3) & 0xFF) - ((f32) ((ROM_READ(0x6D8) >> 2) & 0xFF) * 0.01f)) * temp_fs0) +
               (((ROM_READ(0x6D8) >> 2) & 0xFF) * 0.01f);
    temp_fv1 =
        (((((ROM_READ(0x1C8) >> 4) & 0xFF) * 0.01f) - ((f32) ((ROM_READ(0x664) >> 2) & 0xFF) * 0.01f)) * temp_fs0) +
        (((ROM_READ(0x664) >> 2) & 0xFF) * 0.01f);
    temp_a1 = &D_800F80C8[arg0->character];
    arg0->unk_1F8 = D_800CF188[temp_a1->machineStats[GRIP_STAT]] + ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1F8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        (((f32) ((ROM_READ(0x384) >> 5) & 0xFF) - ((f32) ((ROM_READ(0x718) >> 0xD) & 0xFF) * 0.001f)) * temp_fs0) +
        (((ROM_READ(0x718) >> 0xD) & 0xFF) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x248) >> 0xB) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x6A0) >> 0xE) & 0xFF) * 0.01f)) *
         temp_fs0) +
        (((ROM_READ(0x6A0) >> 0xE) & 0xFF) * 0.01f);
    arg0->unk_1FC = D_800CF19C[temp_a1->machineStats[GRIP_STAT]] + ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1FC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((ROM_READ(0x38C) & 0xFF) - (((ROM_READ(0x740) >> 0x12) & 0xFF) * 0.001f)) * temp_fs0) +
               (((ROM_READ(0x740) >> 0x12) & 0xFF) * 0.001f);
    temp_fv1 =
        (((((ROM_READ(0x250) >> 3) & 0xFF) * 0.001f) - (((ROM_READ(0x718) >> 0x17) & 0xFF) * 0.001f)) * temp_fs0) +
        (((ROM_READ(0x718) >> 0x17) & 0xFF) * 0.001f);

    temp_fa1 = ((temp_fv1 - temp_fv0) * arg0->unk_1A8) + temp_fv0;

    arg0->unk_1C0 = (D_800CF174[temp_a1->machineStats[BOOST_STAT]] + temp_fa1) / arg0->unk_1B8;
    temp_fs1 += arg0->unk_1C0;
    arg0->unk_1C4 = (D_800CF174[2] + temp_fa1) / arg0->unk_1B8;
    temp_fs1 += arg0->unk_1C4;
    temp_ret = func_80089654(arg1);
    temp_ret = func_80089654(temp_ret);
    temp_ret = func_80089654(temp_ret);
    arg0->unk_1D0 = ((D_800CF15C - 1.0f) * temp_ret) + 1.0f;

    return temp_ret;
}

void func_8008C14C(Racer* arg0) {
    s32 pad[7];
    f32 temp;
    f32 temp_fv0_4;
    f32 var_fs0;
    s32 i;
    Mtx3F spE8;
    unk_800CF1B0* temp_s2;

    temp_s2 = &D_800F80C8[arg0->character];
    arg0->unk_167 = temp_s2->unk_00;
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        arg0->unk_2C9 = 0;
    } else {
        arg0->unk_2C9 = arg0->character;
    }

    arg0->unk_2CA = temp_s2->unk_02;
    arg0->unk_2CB = temp_s2->unk_03;
    arg0->unk_2E0 = arg0->unk_2CE = temp_s2->unk_04[arg0->unk_2CC];
    arg0->unk_2E4 = arg0->unk_2D0 = temp_s2->unk_08[arg0->unk_2CC];
    arg0->unk_2E8 = arg0->unk_2D2 = temp_s2->unk_0C[arg0->unk_2CC];
    arg0->unk_2DA = arg0->unk_2DC = arg0->unk_2DE = arg0->shadowR = arg0->shadowG = arg0->shadowB = 0;
    arg0->unk_2EC = 255.0f;
    arg0->unk_2F0 = 0.0f;
    arg0->unk_2F4 = 0.0f;
    arg0->unk_2F8 = arg0->unk_2E0 - arg0->unk_2EC;
    arg0->unk_2FC = arg0->unk_2E4 - arg0->unk_2F0;
    arg0->unk_300 = arg0->unk_2E8 - arg0->unk_2F4;
    if ((D_800CD010 != 0) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
        arg0->stateFlags = RACER_STATE_FLAGS_40000000 | RACER_STATE_FLAGS_20000000 | RACER_STATE_FLAGS_100000 | RACER_STATE_FLAGS_8000;
    } else {
        arg0->stateFlags = RACER_STATE_FLAGS_40000000 | RACER_STATE_FLAGS_20000000 | RACER_STATE_FLAGS_8000;
    }
    if ((arg0->id >= gNumPlayers) || (D_800CE77C != 0) || (gGameMode == GAMEMODE_RECORDS) ||
        (gGameMode == GAMEMODE_GP_END_CS) || (D_800CD010 != 0)) {
        arg0->stateFlags |= RACER_STATE_FLAGS_800000;
    }
    arg0->unk_0C.unk_08 = func_8009E108(arg0->unk_0C.courseSegment, arg0->unk_0C.unk_04, &arg0->unk_244);

    func_8009E85C(arg0->unk_0C.courseSegment, arg0->unk_0C.unk_04, &arg0->unk_24C, arg0->unk_0C.unk_08);
    // FAKE spE8 is compiler stack from a chain struct copy
    spE8 = arg0->unk_24C;
    arg0->unk_C0 = spE8;
    arg0->unk_E8 = spE8;

    spE8.x = arg0->unk_0C.unk_34;

    arg0->unk_180 = spE8.x;
    arg0->unk_10C = spE8.x;

    arg0->unk_A8.x = arg0->unk_B4.x = arg0->unk_19C.x = arg0->unk_C0.xy;
    arg0->unk_A8.y = arg0->unk_B4.y = arg0->unk_19C.y = arg0->unk_C0.yy;
    arg0->unk_A8.z = arg0->unk_B4.z = arg0->unk_19C.z = arg0->unk_C0.zy;

    for (i = 0; i < 3; i++) {
        arg0->lapTimes[i] = NULL;
    }

    arg0->unk_2B4 = arg0->unk_2B2 = arg0->unk_2B3 = 1;
    arg0->unk_168.y = -54321.0f;
    arg0->unk_240 = -gCurrentCourseRecordInfo->length;
    arg0->unk_284 = 0;
    arg0->unk_286 = 0;
    arg0->unk_23C = arg0->unk_248 = arg0->unk_240 + arg0->unk_244;
    arg0->unk_2A4 = ((Math_Rand2() & 0x1FFFF) % 150) + 1;
    arg0->unk_2AA = 1;
    arg0->unk_28C = NULL;
    arg0->unk_08 = 0x8000;
    arg0->unk_2B0 = arg0->unk_288 = arg0->unk_278 = arg0->unk_27A = arg0->unk_27C = arg0->unk_220 = arg0->unk_21C =
        arg0->unk_29C = arg0->raceTime = arg0->lap = arg0->unk_204 = arg0->unk_208 = arg0->unk_20C = arg0->boostTimer =
            arg0->unk_214 = arg0->unk_210 = 0;
    arg0->unk_118.x = arg0->unk_118.y = arg0->unk_118.z = arg0->unk_224 = arg0->unk_1DC = arg0->unk_E4 = arg0->unk_238 =
        arg0->unk_200 = arg0->unk_A0 = arg0->unk_1D4 = arg0->unk_1D8 = arg0->speed = arg0->maxSpeed = arg0->unk_198 =
            arg0->unk_18C.x = arg0->unk_18C.y = arg0->unk_18C.z = arg0->unk_68.x = arg0->unk_68.y = arg0->unk_68.z =
                arg0->unk_5C.x = arg0->unk_5C.y = arg0->unk_5C.z = arg0->unk_80.x = arg0->unk_80.y = arg0->unk_80.z =
                    arg0->velocity.x = arg0->velocity.y = arg0->velocity.z = var_fs0 = 0.0f;
    arg0->unk_A4 = arg0->unk_230 = arg0->unk_178 = arg0->unk_1E8 = 0.0f;
    arg0->shadowColorStrength = 1.0f;
    arg0->unk_1EC = 2500.0f / 27.0f;
    arg0->unk_17C = D_800F80A4;

    arg0->unk_1E0 = (((temp_s2->unk_14 - 780.0f) * -0.0050000027f) / 1560.0f) + 0.054f;
    arg0->unk_1E4 = (((temp_s2->unk_14 - 780.0f) * -0.004999999f) / 1560.0f) + 0.03f;
    arg0->unk_1F0 = temp_s2->unk_14;
    arg0->unk_1F4 =
        ((4 - temp_s2->machineStats[BODY_STAT]) * 312.0f) + 780.0f + ((312.0f * (temp_s2->unk_14 - 780.0f)) / 1560.0f);

    // arg0->unk_1F4 = SQ(arg0->unk_1F4);
    // FAKE
    arg0->unk_1F4 = arg0->unk_1F4 * (temp = arg0->unk_1F4);

    for (i = 0; i < 2;) {
        temp_fv0_4 = func_8008B2D8(arg0, arg0->unk_1A8);
        if (temp_fv0_4 == var_fs0) {
            i++;
        } else {
            i = 0;
        }
        var_fs0 = temp_fv0_4;
    }

    arg0->unk_234 = 1.7f;

    arg0->energy = arg0->maxEnergy = gBodyHealthValues[temp_s2->machineStats[BODY_STAT]];
    arg0->boostEnergyUsage = arg0->maxEnergy * 0.0015f;
    arg0->unk_31C = arg0->unk_1C4 - 1.0f;
    arg0->unk_320 = (0.5f - arg0->unk_1A8) * 0.5f;
    arg0->unk_324 = 1.0f / (2.0f * arg0->unk_1BC);
    arg0->unk_328 = 1.0f - arg0->unk_1D0;
    arg0->energyIncrease = arg0->maxEnergy * sEnergyRefillScale;

    arg0->unk_270 = (arg0->unk_0C.unk_08 *
                     (arg0->unk_0C.courseSegment->next->radiusLeft - arg0->unk_0C.courseSegment->radiusLeft)) +
                    arg0->unk_0C.courseSegment->radiusLeft;
    arg0->unk_274 = (arg0->unk_0C.unk_08 *
                     (arg0->unk_0C.courseSegment->next->radiusRight - arg0->unk_0C.courseSegment->radiusRight)) +
                    arg0->unk_0C.courseSegment->radiusRight;
}

extern OSMesgQueue D_800DCAB0;
extern s16 D_80115D90[];
extern GfxPool D_8024DCE0[2];
extern CourseData gCourseData;

void func_8008C7C8(void) {
    s32 i;
    s32 j;
    s32 var_a3;
    s32 var_t0;
    Racer* var_s1_2;
    GhostRacer* temp_s0_2;
    CarInfo sp6C;
    OSMesg sp68;

    D_800E5FE8 = &D_800CE4E0[gCourseData.venue * 4];
    D_800E5FEC = &D_800CE5D0[gCourseData.venue * 4];
    D_800E5FDC = 600000 - 1;
    D_800F809C = D_800F80A0 = 0.0f;
    D_800E5FD8 = D_800E5FE0 = gRacersKOd = D_800F80C4 = D_800F80B8 = D_800E5FBC = D_800E5FBE = D_800E5FC0 = D_800E5FC2 =
        D_800E5FC4 = D_800E5FC6 = D_800E5FC8 = D_800E5FCA = 0;
    D_800F80BC = gCurrentCourseRecordInfo->length * 0.5;
    D_800F80C0 = -D_800F80BC;
    if (gGameMode != GAMEMODE_GP_RACE) {
        D_800E5FD6 = 0;
    }
    D_800E5FD4 = D_800E5FD6;
    D_800E5FF0++;

    if (gNumPlayers == 1) {
        switch (gGameMode) {
            case GAMEMODE_RECORDS:
            case GAMEMODE_TIME_ATTACK:
                D_800E5EC0 = 1;
                break;
            case GAMEMODE_GP_END_CS:
                if (D_80106F48 < 4) {
                    D_800E5EC0 = 3;
                    for (i = 1; i < 4; i++) {
                        for (j = 0; j < 30; j++) {
                            if (D_80115D90[j] == i) {
                                break;
                            }
                        }
                        gRacers[0].lapTimes[i - 1] = (gRacers[j].character << 0x10) | gRacers[j].unk_2CC;
                    }

                    for (i = 0; i < 3; i++) {
                        gRacers[i].character = (gRacers[0].lapTimes[i] >> 0x10);
                        gRacers[i].unk_2CC = gRacers[0].lapTimes[i] & 0xFFFF;
                    }
                } else {
                    D_800E5EC0 = 1;
                }
                break;
            default:
                if (gGameMode == GAMEMODE_PRACTICE || gGameMode == GAMEMODE_DEATH_RACE || D_800E5FF0 == 1) {
                    func_80089800();
                }
                D_800E5EC0 = 30;
                break;
        }
    } else {
        if (gSettingVsCom != 0) {
            D_800E5EC0 = 4;
            func_80089934();
        } else {
            D_800E5EC0 = gNumPlayers;
        }
        if ((D_800E5EC0 != D_800E5FCC) || (gNumPlayers != D_800E5FCE)) {
            D_800E5FCC = D_800E5EC0;
            D_800E5FCE = gNumPlayers;
            for (i = 0; i < 4; i++) {
                D_800E5F00[i] = D_800E5F10[i] = 0;
            }
        }
    }
    D_800E5EC4 = &gRacers[D_800E5EC0 - 1];
    if (D_800CD010 != 0) {
        for (i = 29; i >= 0; i--) {
            gRacers[i].character = i;
            gRacers[i].unk_2CC = 0;
        }
        var_a3 = 0x21;
        for (var_a3 = 33; var_a3 > 0; var_a3--) {
            i = (Math_Rand1() & 0x1FFFF) % 30;
            j = (Math_Rand2() & 0x1FFFF) % 30;

            var_t0 = gRacers[i].character;
            gRacers[i].character = gRacers[j].character;
            gRacers[j].character = var_t0;
        }
    }
    if (gNumPlayers >= 2) {
        for (i = 0; i < D_800E5EC0; i++) {
            gRacers[i].position = i + 1;
        }
    }

    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
        D_800F80A4 = 7.0f;
    } else {
        D_800F80A4 = 5.0f;
    }
    func_80088D28();
    osRecvMesg(&D_800DCAB0, &sp68, OS_MESG_NOBLOCK);
    osRecvMesg(&D_800DCAB0, &sp68, OS_MESG_BLOCK);
    for (i = 0; i < D_800E5EC0; i++) {
        gRacers[i].id = i;
        func_i3_80116C74(&gRacers[i]);
        func_8008C14C(&gRacers[i]);
        if (i < gNumPlayers) {
            gRacers[i].unk_2A4 = 0;
            gControllers[gPlayerControlPorts[i]].unk_72 = gControllers[gPlayerControlPorts[i]].unk_78 = 1;
            D_800E5F30[i] = 0;
            D_800E5F20[i] = 0;
        }
    }

    func_8008AD38();
    func_8008A978();
    func_8008B150();

    for (i = 0; i < 435; i++) {
        D_800F5EA0[i].unk_10 = 0;
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            Lights_SetSource(&D_8024DCE0[i].unk_21A88[j], 100, 100, 100, 255, 255, 255, 69, 69, 69);
        }
    }

    for (i = 0; i < 4; i++) {
        D_800F80A8[i] = 0;
    }

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        for (var_s1_2 = D_800E5EC4; var_s1_2 > gRacers; var_s1_2--) {
            var_s1_2->energy *= 0.5f;
            var_s1_2->maxEnergy *= 0.5f;
        }
    }
    if ((gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS) && (D_800CD010 == 0)) {
        D_800CE780 = 1;
        D_800F5E98 = 460;
        D_800E5FD0 = 1;
    } else {
        D_800E5FD0 = 0;
        D_800F5E98 = 0;

        if (D_800CD010 != 0) {
            D_800CE780 = 1;
        } else {
            D_800CE780 = 0;
        }
        for (var_s1_2 = D_800E5EC4; var_s1_2 >= gRacers; var_s1_2--) {
            var_s1_2->stateFlags |= RACER_STATE_FLAGS_400000;
            var_s1_2->unk_17C = 13.0f;
            var_s1_2->unk_2A4 = 0;
        }
    }
    func_800890B4();

    for (i = 0; i < 3; i++) {
        gGhostRacers[i].exists = false;
    }
    D_800E5FE2 = D_800E5FE4 = D_800E5FE6 = D_800F5DE4 = D_800F5DEA = D_800F5DE8 = 0;
    gFastestGhostRacer = NULL;
    gFastestGhost = NULL;
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        D_800F5DD8 = Math_Round(gRacers[0].unk_0C.unk_34.x);
        D_800F5DDC = Math_Round(gRacers[0].unk_0C.unk_34.y);
        D_800F5DE0 = Math_Round(gRacers[0].unk_0C.unk_34.z);
        if (gCurrentGhostType != GHOST_NONE) {
            func_80089A74(&sp6C);
            var_a3 = var_t0 = 0x40000000;

            for (i = 0; i < 3; i++) {
                if (gCurrentCourseRecordInfo->encodedCourseIndex != gGhosts[i].encodedCourseIndex) {
                    continue;
                }

                if (gGhosts[i].ghostType == GHOST_PLAYER) {
                    if (gGhosts[i].raceTime < var_t0) {
                        var_t0 = gGhosts[i].raceTime;
                        gFastestGhost = &gGhosts[i];
                    }
                }
                if (gGhosts[i].ghostType != gCurrentGhostType) {
                    continue;
                }

                temp_s0_2 = &gGhostRacers[i];

                if (gGhosts[i].raceTime < var_a3) {
                    var_a3 = gGhosts[i].raceTime;
                    gFastestGhostRacer = temp_s0_2;
                }
                temp_s0_2->exists = true;
                temp_s0_2->ghost = &gGhosts[i];
                temp_s0_2->replayPtr = gGhosts[i].replayData;
                temp_s0_2->frameCount = 0;
                temp_s0_2->replayIndex = 0;
                temp_s0_2->initialized = false;
                temp_s0_2->scale = 1.0f;
                temp_s0_2->replayPosX = D_800F5DD8;
                temp_s0_2->replayPosY = D_800F5DDC;
                temp_s0_2->replayPosZ = D_800F5DE0;
                temp_s0_2->racer = &gRacers[i + 1];
                gRacers[i + 1] = gRacers[0];
                var_s1_2 = temp_s0_2->racer;

                var_s1_2->id = i + 1;
                var_s1_2->character = temp_s0_2->ghost->carInfo.character;

                if (func_8008B23C(&temp_s0_2->ghost->carInfo, &sp6C) != 0) {
                    var_s1_2->unk_2C9 = i + 7;
                } else {
                    var_s1_2->unk_2C9 = gRacers[0].unk_2C9;
                }

                var_s1_2->unk_2CA = D_800F80C8[var_s1_2->character].unk_02;
                var_s1_2->unk_2CB = D_800F80C8[var_s1_2->character].unk_03;
                var_s1_2->unk_2CE = temp_s0_2->ghost->carInfo.envR2;
                var_s1_2->unk_2D0 = temp_s0_2->ghost->carInfo.envG2;
                var_s1_2->unk_2D2 = temp_s0_2->ghost->carInfo.envB2;
            }
        }
        sGhostReplayRecordingPtr = sGhostReplayRecordingBuffer;
        D_800F5DE6 = D_800F5DD0 = sGhostReplayRecordingSize = 0;
    }
}

void func_8008D33C(void) {
    s32 i;

    for (i = 29; i >= 0; i--) {
        D_800F80C8[i] = D_800CF1B0[i];
    }
}

void func_8008D3C4(s32 arg0, s32 arg1) {
    s32 pad[2];
    Gfx* gfx;
    s32 i;
    unk_800CF1B0* temp_v0 = &D_800F80C8[arg0];

    if (temp_v0->unk_00 == 1) {
        gfx = func_i9_80161050(D_800CDD38[arg1], D_800F8360[arg0][3], temp_v0->unk_10 - 1, D_800F8360[arg0][4]);
        gSPEndDisplayList(gfx);

        for (i = 4; i >= 0; i--) {
            gfx = func_i9_80115DF0(D_800CDDB0[arg1 * 6 + i], i, D_800F8360[arg0][0], D_800F8360[arg0][1],
                                   D_800F8360[arg0][2], D_800F8360[arg0][8], D_800F8360[arg0][9], D_800F8360[arg0][10],
                                   D_800F8360[arg0][5], D_800F8360[arg0][6], D_800F8360[arg0][7], 255, 255, 255,
                                   D_800F8360[arg0][11], D_800F8360[arg0][12], D_800F8360[arg0][13]);
            gSPEndDisplayList(gfx);
        }

        return;
    }
    if (temp_v0->unk_00 != 0) {
        arg0 = temp_v0->unk_00 + 28;
    } else {
        arg0 = arg0;
    }

    gfx = D_800CE098[arg0](D_800CDD38[arg1]);
    gSPEndDisplayList(gfx);

    for (i = 4; i >= 0; i--) {
        gfx = D_800CE11C[arg0][i](D_800CDDB0[arg1 * 6 + i]);
        gSPEndDisplayList(gfx);
    }
}

void func_8008D5F4(CarInfo* arg0, s32 arg1) {
    s32 pad[2];
    s32 var_v1;
    Gfx* gfx;
    s32 i;

    if (arg0->customType == 1) {
        gfx = func_i9_80161050(D_800CDD38[arg1], arg0->logo, arg0->decal, arg0->number);
        gSPEndDisplayList(gfx);

        for (i = 4; i >= 0; i--) {
            gfx = func_i9_80115DF0(D_800CDDB0[arg1 * 6 + i], i, arg0->frontType, arg0->rearType, arg0->wingType,
                                   arg0->primR2, arg0->primG2, arg0->primB2, arg0->primR1, arg0->primG1, arg0->primB1,
                                   255, 255, 255, arg0->envR1, arg0->envG1, arg0->envB1);
            gSPEndDisplayList(gfx);
        }

        return;
    }
    if (arg0->customType != 0) {
        var_v1 = arg0->customType - 2 + 30;
    } else {
        var_v1 = arg0->character;
    }

    gfx = D_800CE098[var_v1](D_800CDD38[arg1]);
    gSPEndDisplayList(gfx);

    for (i = 4; i >= 0; i--) {
        gfx = D_800CE11C[var_v1][i](D_800CDDB0[arg1 * 6 + i]);
        gSPEndDisplayList(gfx);
    }
}

void func_8008D7E8(void) {
    s32 i;

    for (i = 29; i >= 0; i--) {
        func_8008D3C4(i, i);
    }
}

extern s32 gCourseIndex;

void func_8008D824(void) {
    CourseRecordInfo* sp2C;
    s32 i;
    u8 var;

    sp2C = &gCourseRecordInfos[gCourseIndex];

    for (i = 4; i >= 0; i--) {
        D_800F8504[i] = i + 1;
        func_8008D5F4(&sp2C->carInfo[i], D_800F8504[i]);
    }

    var = 5;
    D_800F8504[var] = var + 1;
    func_8008D5F4(&sp2C->maxSpeedCar, D_800F8504[var]);
    var = 6;
    D_800F8504[var] = var + 1;
    func_8008D5F4(&sp2C->bestTimeCar, D_800F8504[var]);
}

void func_800A4DF0(void);

void func_8008D8E8(void) {
    s32 i;

    func_800A4DF0();
    func_8008D3C4(D_800E5EE0[0], 0);
    func_8008D824();

    for (i = 0; i < 3; i++) {
        if (gCurrentCourseRecordInfo->encodedCourseIndex == gGhosts[i].encodedCourseIndex) {
            func_8008D5F4(&gGhosts[i].carInfo, i + 7);
        }
    }
}

void func_8008D97C(void) {
    Gfx* gfx;
    s32 i;
    s32 index;
    s32 j;

    for (i = 29; i >= 0; i--) {
        index = i;
        gfx = D_800CE098[index](D_800CDD38[i]);
        gSPEndDisplayList(gfx);
        for (j = 4; j >= 0; j--) {
            gfx = D_800CE11C[index][j](D_800CDDB0[i * 6 + j]);
            gSPEndDisplayList(gfx);
        }
    }
}

extern s16 D_800E5FCC;
extern s16 D_800E5FCE;

void func_8008DA68(void) {
    s32 i;

    D_800E5FD6 = D_800E5FF0 = 0;
    D_800E5FCC = D_800E5FCE = 0;

    for (i = 0; i < ARRAY_COUNT(gRacers); i++) {
        gRacers[i].character = (s8) (i % ARRAY_COUNT(gRacers));
        gRacers[i].unk_2CC = 0;
        gRacers[i].unk_1A8 = func_8008960C(0.5f);
        if (i < 4) {
            D_800E5EE0[i] = (s16) gRacers[i].character;
            D_800E5EE8[i] = gRacers[i].unk_2CC;
            gPlayerEngine[i] = 0.5f;
        }
    }
    func_8008D33C();
}

void func_8008DB98(void) {
    func_8008DA68();
}

extern s16 gRacersKOd;

void func_8008DBB8(Racer* arg0, s32 arg1) {
    Racer* temp_v0;

    if (arg1 >= arg0->unk_288) {
        temp_v0 = arg0->unk_28C;
        if ((temp_v0 != NULL) && !(temp_v0->stateFlags & (RACER_STATE_FLAGS_2000000 | RACER_STATE_FLAGS_40000 | RACER_STATE_FLAGS_4000))) {
            D_800E5FD4++;
            gRacersKOd++;
            if ((gGameMode == GAMEMODE_GP_RACE) && (gRacersKOd == 5)) {
                gPlayerLives[0]++;
                func_i3_80128D8C();
                func_i3_TriggerLivesIncrease();
                if (D_800E5FD0 != 0) {
                    func_800BA8D8(0);
                }
            }
            temp_v0->unk_230 += temp_v0->maxEnergy * 0.125f;
            if ((gNumPlayers == 1) && (D_800E5FD0 != 0)) {
                func_800BA8D8(0x39);
            }
        }
    }
}

void func_8008DCD8(Racer* arg0, f32 arg1) {
    s32 pad[7];
    Vec3f sp90;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 i;

    if (arg0->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_2000000)) {
        if (((arg0->stateFlags & (RACER_STATE_FLAGS_40000000 | RACER_STATE_FLAGS_8000000)) == (RACER_STATE_FLAGS_40000000 | RACER_STATE_FLAGS_8000000)) && (D_800CE770 < arg1)) {
            arg0->stateFlags &= ~RACER_STATE_FLAGS_40000000;
            arg0->unk_C0 = arg0->unk_24C;
            D_800E5FC0++;
            if (arg0->id < gNumPlayers) {
                func_800894C0(arg0);
            }
            if (D_800E5FD0 != 0) {
                func_800BA710(arg0->id, 8);
            }
            if (arg0->unk_2B4 != 0) {
                if (arg0->unk_28C == NULL) {
                    sp90.x = 0.0f;
                    sp90.y = 0.0f;
                    sp90.z = 0.0f;
                } else {
                    sp90.z = arg0->unk_28C->velocity.x;
                    sp90.y = arg0->unk_28C->velocity.y;
                    sp90.x = arg0->unk_28C->velocity.z;
                }
                func_i2_80105648(arg0->unk_0C.unk_34.x, arg0->unk_0C.unk_34.y, arg0->unk_0C.unk_34.z, sp90.z, sp90.y,
                                 sp90.x, 40.0f, arg0);

                temp_s5 = arg0->unk_2E0;
                temp_s6 = arg0->unk_2E4;
                temp_s7 = arg0->unk_2E8;

                i = (arg0->id < gNumPlayers) ? 60 : 30;
                do {

                    temp_fs2 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;

                    temp_fs0 = ((Math_Rand2() & 0x1FFFF) * (7.0f / 131071.0f)) + 3.5f;

                    temp_fs1 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;

                    func_i2_80105A28(((s32) (Math_Rand2() % 32) - 0x10) + arg0->unk_0C.unk_34.x,
                                     ((s32) (Math_Rand1() % 32) - 0x10) + arg0->unk_0C.unk_34.y,
                                     ((s32) (Math_Rand1() % 32) - 0x10) + arg0->unk_0C.unk_34.z,
                                     sp90.z + (arg0->unk_C0.xz * temp_fs2) + (temp_fs0 * arg0->unk_C0.xy) +
                                         (temp_fs1 * arg0->unk_C0.xx),
                                     sp90.y + (arg0->unk_C0.yz * temp_fs2) + (temp_fs0 * arg0->unk_C0.yy) +
                                         (temp_fs1 * arg0->unk_C0.yx),
                                     sp90.x + (arg0->unk_C0.zz * temp_fs2) + (temp_fs0 * arg0->unk_C0.zy) +
                                         (temp_fs1 * arg0->unk_C0.zx),
                                     &arg0->unk_C0, temp_s5, temp_s6, temp_s7, arg0);
                    i--;
                } while (i != 0);
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_FLAGS_20000;
        arg0->energy -= arg1;
        if (arg0->energy < 0.0f) {
            if (arg0->unk_2B4 == 0) {
                arg0->energy = 0.1f;
                return;
            }
            arg0->energy = 0.0f;
            arg0->unk_238 = 0.2f * arg1;
            if (arg0->unk_238 > 1.0f) {
                arg0->unk_238 = 1.0f;
            }
            if (Math_Rand1() % 2) {
                arg0->unk_238 *= -1.0f;
            }

            if (!(arg0->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_4000))) {
                arg0->stateFlags |= RACER_STATE_FLAGS_4000;
                arg0->stateFlags &= ~RACER_STATE_FLAGS_400000;
                arg0->unk_21C = 1;
                arg0->unk_234 = 2.0f;
                func_8008DBB8(arg0, 60);
            }
        }
    }
}

void func_8008E188(Racer* arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 pad;
    Racer* var;
    f32 var_fv0;

    var_fv0 = arg0->unk_24C.xz * arg3;
    arg0->unk_0C.unk_28.x -= var_fv0;
    arg0->unk_0C.unk_34.x -= var_fv0;
    arg0->unk_0C.unk_44.x -= var_fv0;

    var_fv0 = arg0->unk_24C.yz * arg3;
    arg0->unk_0C.unk_28.y -= var_fv0;
    arg0->unk_0C.unk_34.y -= var_fv0;
    arg0->unk_0C.unk_44.y -= var_fv0;

    var_fv0 = arg0->unk_24C.zz * arg3;
    arg0->unk_0C.unk_28.z -= var_fv0;
    arg0->unk_0C.unk_34.z -= var_fv0;
    arg0->unk_0C.unk_44.z -= var_fv0;

    arg0->unk_0C.unk_40 = sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));

    if (arg1 * arg2 <= 0.0f) {
        return;
    }

    if (arg1 * arg2 > 0.01f) {
        if (arg0->unk_2B4 != 0) {
            func_i2_801054C0(arg0->unk_0C.unk_34.x + ((arg2 * 15.0f) * arg0->unk_24C.xz),
                             arg0->unk_0C.unk_34.y + ((arg2 * 15.0f) * arg0->unk_24C.yz),
                             arg0->unk_0C.unk_34.z + ((arg2 * 15.0f) * arg0->unk_24C.zz), arg0->velocity.x,
                             arg0->velocity.y, arg0->velocity.z, (arg1 * arg2 * 1.5f) + 18.0f, arg0);
        }
        if (D_800E5FD0 != 0) {
            func_800BA710(arg0->id, 3);
        }
        func_8008DCD8(arg0, arg1 * arg2 * 0.7f);
    }

    arg0->velocity.x = (arg0->velocity.x - arg0->unk_234 * arg1 * arg0->unk_24C.xz) * 0.998f;
    arg0->velocity.y = (arg0->velocity.y - arg0->unk_234 * arg1 * arg0->unk_24C.yz) * 0.998f;
    arg0->velocity.z = (arg0->velocity.z - arg0->unk_234 * arg1 * arg0->unk_24C.zz) * 0.998f;

    // FAKE
    var = arg0;
    var->unk_118.x = var->unk_24C.xz * (-0.15f * arg1);
    var->unk_118.y = var->unk_24C.yz * (-0.15f * arg1);
    var->unk_118.z = var->unk_24C.zz * (-0.15f * arg1);

    arg0->stateFlags |= RACER_STATE_FLAGS_2000;
}

void func_8008E418(Racer* arg0) {
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 =
        ((arg0->unk_A8.x * arg0->unk_B4.x) + (arg0->unk_A8.y * arg0->unk_B4.y) + (arg0->unk_A8.z * arg0->unk_B4.z)) *
        0.15f * arg0->unk_E4;

    arg0->unk_B4.x = arg0->unk_C0.xy + (temp_fv0 * arg0->unk_C0.xx);
    arg0->unk_B4.y = arg0->unk_C0.yy + (temp_fv0 * arg0->unk_C0.yx);
    arg0->unk_B4.z = arg0->unk_C0.zy + (temp_fv0 * arg0->unk_C0.zx);

    temp_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));
    arg0->unk_B4.x *= temp_fv1;
    arg0->unk_B4.y *= temp_fv1;
    arg0->unk_B4.z *= temp_fv1;
}

void func_8008E504(Racer* arg0) {

    arg0->unk_A8.x -= 0.5f * arg0->unk_A8.x;
    arg0->unk_A8.y += 0.5f * (1.0f - arg0->unk_A8.y);
    arg0->unk_A8.z -= 0.5f * arg0->unk_A8.z;
}

void func_80090568(Racer*);

void func_8008E54C(Racer* arg0, f32 arg1) {
    f32 temp_ft4;
    f32 sp50;
    f32 temp_fv0;

    if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        arg0->unk_270 += 57.5f;
        arg0->unk_274 += 57.5f;
        func_80090568(arg0);

        arg0->unk_270 -= 57.5f;
        arg0->unk_274 -= 57.5f;
        if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
            return;
        }
        sp50 = (arg0->unk_24C.xz * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yz * arg0->unk_0C.unk_28.y) +
               (arg0->unk_24C.zz * arg0->unk_0C.unk_28.z);
        if ((sp50 < -arg0->unk_274) || (arg0->unk_270 < sp50)) {
            arg0->stateFlags |= RACER_STATE_FLAGS_80000000;
            func_8008DCD8(arg0, 2.0f);
            func_i2_801054C0(arg0->unk_0C.unk_34.x, arg0->unk_0C.unk_34.y, arg0->unk_0C.unk_34.z, arg0->velocity.x,
                             arg0->velocity.y, arg0->velocity.z, 40.0f, arg0);
            if (D_800E5FD0 != 0) {
                func_800BA710(arg0->id, 3);
            }
        }
    } else {
        sp50 = (arg0->unk_24C.xz * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yz * arg0->unk_0C.unk_28.y) +
               (arg0->unk_24C.zz * arg0->unk_0C.unk_28.z);
        arg0->unk_A0 = (arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                       (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z);
        arg0->unk_19C.x = arg0->unk_24C.xy;
        arg0->unk_19C.y = arg0->unk_24C.yy;
        arg0->unk_19C.z = arg0->unk_24C.zy;

        if (arg1 < arg0->unk_A0) {
            arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_FLAGS_4000000;
            if (arg0->id < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (D_800E5FD0 != 0) {
                        func_800BA2F0(arg0->id, 8);
                    }
                }
            }
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }

        if (arg0->unk_A0 < 0.0f) {
            temp_fv0 = arg0->unk_A0 * arg0->unk_24C.xy;
            arg0->unk_0C.unk_28.x -= temp_fv0;
            arg0->unk_0C.unk_34.x -= temp_fv0;
            arg0->unk_0C.unk_44.x -= temp_fv0;

            temp_fv0 = arg0->unk_A0 * arg0->unk_24C.yy;
            arg0->unk_0C.unk_28.y -= temp_fv0;
            arg0->unk_0C.unk_34.y -= temp_fv0;
            arg0->unk_0C.unk_44.y -= temp_fv0;

            temp_fv0 = arg0->unk_A0 * arg0->unk_24C.zy;
            arg0->unk_0C.unk_28.z -= temp_fv0;
            arg0->unk_0C.unk_34.z -= temp_fv0;
            arg0->unk_0C.unk_44.z -= temp_fv0;

            arg0->unk_A0 = 0.0f;

            temp_ft4 = (arg0->unk_24C.xy * arg0->velocity.x) + (arg0->unk_24C.yy * arg0->velocity.y) +
                       (arg0->unk_24C.zy * arg0->velocity.z);
            if (temp_ft4 < 0.0f) {
                arg0->velocity.x -= temp_ft4 * arg0->unk_24C.xy;
                arg0->velocity.y -= temp_ft4 * arg0->unk_24C.yy;
                arg0->velocity.z -= temp_ft4 * arg0->unk_24C.zy;
                if ((arg0->id < gNumPlayers) && (D_800E5FD0 != 0)) {
                    func_800BB3C4(arg0->id, temp_ft4);
                }
            }
        }

        if (arg0->unk_A0 <= 15.0f) {
            arg0->stateFlags &= ~RACER_STATE_FLAGS_4000000;
            if (arg0->id < gNumPlayers) {

                if (arg0->unk_08 & 0x2000) {
                    arg0->unk_08 &= ~0x2000;
                    if (D_800E5FD0 != 0) {
                        func_800BA3E4(arg0->id, 8);
                    }
                }
            }

            arg0->unk_A8.x = arg0->unk_B4.x = arg0->unk_24C.xy;
            arg0->unk_A8.y = arg0->unk_B4.y = arg0->unk_24C.yy;
            arg0->unk_A8.z = arg0->unk_B4.z = arg0->unk_24C.zy;

        } else {
            arg0->stateFlags |= RACER_STATE_FLAGS_4000000;
            if (arg0->id < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (D_800E5FD0 != 0) {
                        func_800BA2F0(arg0->id, 8);
                    }
                }
            }
            func_8008E418(arg0);
            func_8008E504(arg0);

            if (arg0->unk_A0 < 30.0f) {

                temp_ft4 = (arg0->unk_A0 - 15.0f) / 15.0f;
                arg0->unk_A8.x = (arg0->unk_A8.x - arg0->unk_24C.xy) * temp_ft4 + arg0->unk_24C.xy;
                arg0->unk_A8.y = (arg0->unk_A8.y - arg0->unk_24C.yy) * temp_ft4 + arg0->unk_24C.yy;
                arg0->unk_A8.z = (arg0->unk_A8.z - arg0->unk_24C.zy) * temp_ft4 + arg0->unk_24C.zy;

                arg0->unk_B4.x = (arg0->unk_B4.x - arg0->unk_24C.xy) * temp_ft4 + arg0->unk_B4.x;
                arg0->unk_B4.y = (arg0->unk_B4.y - arg0->unk_24C.yy) * temp_ft4 + arg0->unk_B4.y;
                arg0->unk_B4.z = (arg0->unk_B4.z - arg0->unk_24C.zy) * temp_ft4 + arg0->unk_B4.z;

                temp_fv0 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));
                arg0->unk_B4.x *= temp_fv0;
                arg0->unk_B4.y *= temp_fv0;
                arg0->unk_B4.z *= temp_fv0;
            }
        }

        if (sp50 < -arg0->unk_274) {
            func_8008E188(arg0,
                          (arg0->unk_24C.xz * arg0->velocity.x) + (arg0->unk_24C.yz * arg0->velocity.y) +
                              (arg0->unk_24C.zz * arg0->velocity.z),
                          -1.0f, arg0->unk_274 + sp50);
        } else if (arg0->unk_270 < sp50) {
            func_8008E188(arg0,
                          (arg0->unk_24C.xz * arg0->velocity.x) + (arg0->unk_24C.yz * arg0->velocity.y) +
                              (arg0->unk_24C.zz * arg0->velocity.z),
                          1.0f, sp50 - arg0->unk_270);
        } else {
            arg0->unk_0C.unk_40 =
                sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
        }

        arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_24C.xy);
        arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_24C.yy);
        arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_24C.zy);
    }
}

void func_8008EC38(Racer* arg0) {
    func_8008E54C(arg0, 40.0f);
}

void func_8008EC58(Racer* arg0) {
    func_8008E54C(arg0, 145.0f);
}

void func_8008EC78(Racer* arg0) {
    func_8008E54C(arg0, 210.0f);
}

extern f32 D_800CF8E8[];

void func_8008EC98(Racer* arg0) {
    f32 var_fv0;
    f32 temp_fv0;
    f32 var_fv1;
    f32 sp60;
    f32 var_fs0;
    f32 sp58;
    f32 sp54;

    if (arg0->unk_0C.unk_04 < arg0->unk_0C.courseSegment->unk_68) {
        var_fv0 = sp60 = arg0->unk_0C.unk_08 / arg0->unk_0C.courseSegment->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = arg0->unk_270;
    } else if (arg0->unk_0C.courseSegment->unk_6C < arg0->unk_0C.unk_04) {
        var_fv0 = sp60 = (1.0f - arg0->unk_0C.unk_08) / arg0->unk_0C.courseSegment->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = -arg0->unk_270;
    } else {
        var_fv0 = arg0->unk_270;
        var_fs0 = 0.0f;
    }

    arg0->unk_A0 = arg0->unk_270 - arg0->unk_0C.unk_40;
    if (arg0->unk_0C.unk_40 > 0.01f) {
        var_fv1 = -1.0f / arg0->unk_0C.unk_40;
        arg0->unk_19C.x = arg0->unk_0C.unk_28.x * var_fv1;
        arg0->unk_19C.y = arg0->unk_0C.unk_28.y * var_fv1;
        arg0->unk_19C.z = arg0->unk_0C.unk_28.z * var_fv1;
    }

    if (var_fs0 != 0.0f) {
        var_fv1 = ((arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                   (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z)) -
                  23.0f;
        if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
            if ((var_fv1 >= 0.0f) || (arg0->unk_270 < arg0->unk_0C.unk_40)) {
                func_8008E418(arg0);
                func_8008E504(arg0);
                arg0->unk_168.y = -54321.0f;
                return;
            }
            arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
        } else if (var_fv1 >= 0.0f) {
            arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_FLAGS_4000000;
            if (arg0->id < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (D_800E5FD0 != 0) {
                        func_800BA2F0(arg0->id, 8);
                    }
                }
            }
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
    } else if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        if (arg0->unk_270 < arg0->unk_0C.unk_40) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    }

    if (var_fs0 != 0.0f) {
        var_fv1 = var_fv0 + (arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                  (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z);
        if (var_fv1 < arg0->unk_A0) {
            arg0->unk_A0 = var_fv1;
            arg0->unk_19C.x = arg0->unk_24C.xy;
            arg0->unk_19C.y = arg0->unk_24C.yy;
            arg0->unk_19C.z = arg0->unk_24C.zy;

            arg0->unk_B4.x = (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_24C.xy) +
                             (var_fs0 * arg0->unk_24C.xx);
            arg0->unk_B4.y = (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_24C.yy) +
                             (var_fs0 * arg0->unk_24C.yx);
            arg0->unk_B4.z = (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_24C.zy) +
                             (var_fs0 * arg0->unk_24C.zx);

            if (false) {
                // FAKE: ARTIFICIALLY INCREASE COMPILER STACK
                arg0->unk_B4.x = arg0->unk_B4.y = arg0->unk_B4.z;
            }

            var_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));

            arg0->unk_B4.x *= var_fv1;
            arg0->unk_B4.y *= var_fv1;
            arg0->unk_B4.z *= var_fv1;

            if (arg0->unk_A0 < 0.0f) {
                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.xy;
                arg0->unk_0C.unk_28.x -= temp_fv0;
                arg0->unk_0C.unk_34.x -= temp_fv0;
                arg0->unk_0C.unk_44.x -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.yy;
                arg0->unk_0C.unk_28.y -= temp_fv0;
                arg0->unk_0C.unk_34.y -= temp_fv0;
                arg0->unk_0C.unk_44.y -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.zy;
                arg0->unk_0C.unk_28.z -= temp_fv0;
                arg0->unk_0C.unk_34.z -= temp_fv0;
                arg0->unk_0C.unk_44.z -= temp_fv0;

                arg0->unk_0C.unk_40 =
                    sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
                arg0->unk_A0 = 0.0f;

                var_fs0 = (arg0->unk_24C.xy * arg0->velocity.x) + (arg0->unk_24C.yy * arg0->velocity.y) +
                          (arg0->unk_24C.zy * arg0->velocity.z);
                if (var_fs0 < 0.0f) {
                    arg0->velocity.x -= var_fs0 * arg0->unk_24C.xy;
                    arg0->velocity.y -= var_fs0 * arg0->unk_24C.yy;
                    arg0->velocity.z -= var_fs0 * arg0->unk_24C.zy;
                    if ((arg0->id < gNumPlayers) && (D_800E5FD0 != 0)) {
                        func_800BB3C4(arg0->id, var_fs0);
                    }
                }
            }
        } else {
            arg0->unk_B4 = arg0->unk_19C;
        }
        var_fs0 = ((arg0->unk_B4.x - arg0->unk_24C.xy) * sp60) + arg0->unk_24C.xy;
        sp58 = ((arg0->unk_B4.y - arg0->unk_24C.yy) * sp60) + arg0->unk_24C.yy;
        sp54 = ((arg0->unk_B4.z - arg0->unk_24C.zy) * sp60) + arg0->unk_24C.zy;

        var_fv1 = sqrtf(SQ(var_fs0) + SQ(sp58) + SQ(sp54));
        if (var_fv1 > 0.01f) {
            var_fv1 = 1.0f / var_fv1;
            arg0->unk_B4.x = var_fv1 * var_fs0;
            arg0->unk_B4.y = var_fv1 * sp58;
            arg0->unk_B4.z = var_fv1 * sp54;
        }

        arg0->unk_A8.x = ((arg0->unk_19C.x - arg0->unk_24C.xy) * sp60) + arg0->unk_24C.xy;
        arg0->unk_A8.y = ((arg0->unk_19C.y - arg0->unk_24C.yy) * sp60) + arg0->unk_24C.yy;
        arg0->unk_A8.z = ((arg0->unk_19C.z - arg0->unk_24C.zy) * sp60) + arg0->unk_24C.zy;
    } else {
        arg0->unk_A8 = arg0->unk_B4 = arg0->unk_19C;
    }

    if (arg0->unk_270 < arg0->unk_0C.unk_40) {
        var_fv1 = arg0->unk_270 / arg0->unk_0C.unk_40;
        arg0->unk_0C.unk_40 = arg0->unk_270;

        arg0->unk_0C.unk_28.x *= var_fv1;
        arg0->unk_0C.unk_34.x = arg0->unk_0C.unk_44.x = arg0->unk_0C.unk_28.x + arg0->unk_0C.unk_1C.x;

        arg0->unk_0C.unk_28.y *= var_fv1;
        arg0->unk_0C.unk_34.y = arg0->unk_0C.unk_44.y = arg0->unk_0C.unk_28.y + arg0->unk_0C.unk_1C.y;

        arg0->unk_0C.unk_28.z *= var_fv1;
        arg0->unk_0C.unk_34.z = arg0->unk_0C.unk_44.z = arg0->unk_0C.unk_28.z + arg0->unk_0C.unk_1C.z;

        arg0->unk_A0 = 0.0f;

        var_fs0 = (arg0->unk_19C.x * arg0->velocity.x) + (arg0->unk_19C.y * arg0->velocity.y) +
                  (arg0->unk_19C.z * arg0->velocity.z);
        if (var_fs0 < 0.0f) {
            arg0->velocity.x -= var_fs0 * arg0->unk_19C.x;
            arg0->velocity.y -= var_fs0 * arg0->unk_19C.y;
            arg0->velocity.z -= var_fs0 * arg0->unk_19C.z;
            if ((arg0->id < gNumPlayers) && (D_800E5FD0 != 0)) {
                func_800BB3C4(arg0->id, var_fs0);
            }
        }
    }

    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_19C.x);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_19C.y);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_19C.z);

    if (arg0->unk_A0 <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA3E4(arg0->id, 8);
                }
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->id, 8);
                }
            }
        }
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/fHjsj stack
void func_8008F550(Racer* arg0) {
    f32 var_fa1;
    f32 temp_fv1;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 temp_fv0;

    if (arg0->unk_0C.unk_04 < arg0->unk_0C.courseSegment->unk_68) {
        sp5C = sp58 = arg0->unk_0C.unk_08 / arg0->unk_0C.courseSegment->unk_70;
        sp5C *= arg0->unk_270;
        var_fa1 = arg0->unk_270;
    } else if (arg0->unk_0C.courseSegment->unk_6C < arg0->unk_0C.unk_04) {
        var_fa1 = -arg0->unk_270;
        sp5C = sp58 = (1.0f - arg0->unk_0C.unk_08) / arg0->unk_0C.courseSegment->unk_70;
        sp5C *= arg0->unk_270;
    } else {
        var_fa1 = 0.0f;
        sp5C = arg0->unk_270;
    }

    arg0->unk_A0 = arg0->unk_0C.unk_40 - sp5C;
    if (arg0->unk_0C.unk_40 > 0.01f) {
        temp_fv1 = 1.0f / arg0->unk_0C.unk_40;
        arg0->unk_19C.x = arg0->unk_0C.unk_28.x * temp_fv1;
        arg0->unk_19C.y = arg0->unk_0C.unk_28.y * temp_fv1;
        arg0->unk_19C.z = arg0->unk_0C.unk_28.z * temp_fv1;
    }

    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_19C.x);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_19C.y);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_19C.z);
    if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        if ((arg0->unk_270 + 200.0f) < arg0->unk_0C.unk_40) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    } else if ((arg0->unk_270 + 200.0f) < arg0->unk_0C.unk_40) {
        arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->id, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);
        arg0->unk_168.y = -54321.0f;
        return;
    }

    if (var_fa1 != 0.0f) {

        sp54 = ((arg0->unk_19C.x - arg0->unk_24C.xy) * sp58) + arg0->unk_24C.xy;
        sp50 = ((arg0->unk_19C.y - arg0->unk_24C.yy) * sp58) + arg0->unk_24C.yy;
        sp4C = ((arg0->unk_19C.z - arg0->unk_24C.zy) * sp58) + arg0->unk_24C.zy;

        temp_fv1 = sqrtf(SQ(sp54) + SQ(sp50) + SQ(sp4C));
        if (temp_fv1 > 0.01f) {
            temp_fv1 = 1.0f / temp_fv1;
            arg0->unk_B4.x = temp_fv1 * sp54;
            arg0->unk_B4.y = temp_fv1 * sp50;
            arg0->unk_B4.z = temp_fv1 * sp4C;
        }

        temp_fv1 = 1.0f - sp58;
        sp54 = arg0->unk_24C.xy * SQ(temp_fv1);
        sp50 = arg0->unk_24C.yy * SQ(temp_fv1);
        sp4C = arg0->unk_24C.zy * SQ(temp_fv1);

        arg0->unk_A8.x = ((arg0->unk_19C.x - sp54) * sp58) + sp54;
        arg0->unk_A8.y = ((arg0->unk_19C.y - sp50) * sp58) + sp50;
        arg0->unk_A8.z = ((arg0->unk_19C.z - sp4C) * sp58) + sp4C;
        temp_fv1 = (sp58 * 200.0f) + sp5C + (arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) +
                   (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) + (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z);
        if (temp_fv1 < arg0->unk_A0) {
            arg0->unk_A0 = temp_fv1;
            arg0->unk_19C.x = arg0->unk_24C.xy;
            arg0->unk_19C.y = arg0->unk_24C.yy;
            arg0->unk_19C.z = arg0->unk_24C.zy;
            if (arg0->unk_A0 < 0.0f) {

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.xy;
                arg0->unk_0C.unk_28.x -= temp_fv0;
                arg0->unk_0C.unk_34.x -= temp_fv0;
                arg0->unk_0C.unk_44.x -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.yy;
                arg0->unk_0C.unk_28.y -= temp_fv0;
                arg0->unk_0C.unk_34.y -= temp_fv0;
                arg0->unk_0C.unk_44.y -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.zy;
                arg0->unk_0C.unk_28.z -= temp_fv0;
                arg0->unk_0C.unk_34.z -= temp_fv0;
                arg0->unk_0C.unk_44.z -= temp_fv0;

                arg0->unk_0C.unk_40 =
                    sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
                arg0->unk_A0 = 0.0f;
            }
        }
    } else {
        arg0->unk_A8 = arg0->unk_B4 = arg0->unk_19C;
    }

    if (arg0->unk_0C.unk_40 < sp5C) {
        temp_fv1 = sp5C / arg0->unk_0C.unk_40;
        arg0->unk_0C.unk_40 = sp5C;

        arg0->unk_0C.unk_28.x *= temp_fv1;
        arg0->unk_0C.unk_34.x = arg0->unk_0C.unk_44.x = arg0->unk_0C.unk_28.x + arg0->unk_0C.unk_1C.x;

        arg0->unk_0C.unk_28.y *= temp_fv1;
        arg0->unk_0C.unk_34.y = arg0->unk_0C.unk_44.y = arg0->unk_0C.unk_28.y + arg0->unk_0C.unk_1C.y;

        arg0->unk_0C.unk_28.z *= temp_fv1;
        arg0->unk_0C.unk_34.z = arg0->unk_0C.unk_44.z = arg0->unk_0C.unk_28.z + arg0->unk_0C.unk_1C.z;

        arg0->unk_A0 = 0.0f;

        var_fa1 = (arg0->unk_19C.x * arg0->velocity.x) + (arg0->unk_19C.y * arg0->velocity.y) +
                  (arg0->unk_19C.z * arg0->velocity.z);
        if (var_fa1 < 0.0f) {
            arg0->velocity.x -= (var_fa1 * arg0->unk_19C.x);
            arg0->velocity.y -= (var_fa1 * arg0->unk_19C.y);
            arg0->velocity.z -= (var_fa1 * arg0->unk_19C.z);
            // FAKE: lowers stack
            if (1) {}
            if ((arg0->id < gNumPlayers) && (D_800E5FD0 != 0)) {
                func_800BB3C4(arg0->id, var_fa1);
            }
        }
    }

    if (arg0->unk_A0 <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA3E4(arg0->id, 8);
                }
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->id, 8);
                }
            }
        }
    }
}
#else
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/game/1B0E0/func_8008F550.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_8008F550.s")
#endif
#endif

void func_8008FC80(Racer* arg0) {
    f32 var_fv0;
    f32 var_fs0;
    f32 temp_fv1;
    f32 sp58;
    f32 temp_fv0;
    f32 sp50;
    f32 sp4C;

    if (arg0->unk_0C.unk_04 < arg0->unk_0C.courseSegment->unk_68) {
        var_fv0 = sp58 = arg0->unk_0C.unk_08 / arg0->unk_0C.courseSegment->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = arg0->unk_270;
    } else if (arg0->unk_0C.courseSegment->unk_6C < arg0->unk_0C.unk_04) {
        var_fv0 = sp58 = (1.0f - arg0->unk_0C.unk_08) / arg0->unk_0C.courseSegment->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = -arg0->unk_270;
    } else {
        var_fv0 = arg0->unk_270;
        var_fs0 = 0.0f;
    }

    arg0->unk_A0 = arg0->unk_270 - arg0->unk_0C.unk_40;
    if (arg0->unk_0C.unk_40 > 0.01f) {
        temp_fv1 = -1.0f / arg0->unk_0C.unk_40;
        arg0->unk_19C.x = arg0->unk_0C.unk_28.x * temp_fv1;
        arg0->unk_19C.y = arg0->unk_0C.unk_28.y * temp_fv1;
        arg0->unk_19C.z = arg0->unk_0C.unk_28.z * temp_fv1;
    }

    temp_fv1 = (((arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                 (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z)) -
                23.0f) +
               (var_fv0 * 0.3826834f);
    if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        if ((temp_fv1 >= 0.0f) || (arg0->unk_270 < arg0->unk_0C.unk_40)) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;

    } else if (temp_fv1 >= 0.0f) {
        arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->id, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);
        arg0->unk_168.y = -54321.0f;
        return;
    }

    if (var_fs0 != 0.0f) {
        temp_fv1 = var_fv0 + (arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                   (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z);
        if (temp_fv1 < arg0->unk_A0) {
            arg0->unk_A0 = temp_fv1;
            arg0->unk_19C.x = arg0->unk_24C.xy;
            arg0->unk_19C.y = arg0->unk_24C.yy;
            arg0->unk_19C.z = arg0->unk_24C.zy;
            arg0->unk_B4.x =
                (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_19C.x) + (var_fs0 * arg0->unk_24C.xx);
            arg0->unk_B4.y =
                (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_19C.y) + (var_fs0 * arg0->unk_24C.yx);
            arg0->unk_B4.z =
                (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_19C.z) + (var_fs0 * arg0->unk_24C.zx);

            temp_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));

            arg0->unk_B4.x *= temp_fv1;
            arg0->unk_B4.y *= temp_fv1;
            arg0->unk_B4.z *= temp_fv1;

            if (arg0->unk_A0 < 0.0f) {
                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.xy;
                arg0->unk_0C.unk_28.x -= temp_fv0;
                arg0->unk_0C.unk_34.x -= temp_fv0;
                arg0->unk_0C.unk_44.x -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.yy;
                arg0->unk_0C.unk_28.y -= temp_fv0;
                arg0->unk_0C.unk_34.y -= temp_fv0;
                arg0->unk_0C.unk_44.y -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.zy;
                arg0->unk_0C.unk_28.z -= temp_fv0;
                arg0->unk_0C.unk_34.z -= temp_fv0;
                arg0->unk_0C.unk_44.z -= temp_fv0;

                arg0->unk_0C.unk_40 =
                    sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
                arg0->unk_A0 = 0.0f;

                var_fs0 = (arg0->unk_24C.xy * arg0->velocity.x) + (arg0->unk_24C.yy * arg0->velocity.y) +
                          (arg0->unk_24C.zy * arg0->velocity.z);
                if (var_fs0 < 0.0f) {
                    arg0->velocity.x -= var_fs0 * arg0->unk_24C.xy;
                    arg0->velocity.y -= var_fs0 * arg0->unk_24C.yy;
                    arg0->velocity.z -= var_fs0 * arg0->unk_24C.zy;
                    if ((arg0->id < gNumPlayers) && (D_800E5FD0 != 0)) {
                        func_800BB3C4(arg0->id, var_fs0);
                    }
                }
            }
        } else {
            arg0->unk_B4 = arg0->unk_19C;
        }

        var_fs0 = ((arg0->unk_B4.x - arg0->unk_24C.xy) * sp58) + arg0->unk_24C.xy;
        sp50 = ((arg0->unk_B4.y - arg0->unk_24C.yy) * sp58) + arg0->unk_24C.yy;
        sp4C = ((arg0->unk_B4.z - arg0->unk_24C.zy) * sp58) + arg0->unk_24C.zy;

        temp_fv1 = sqrtf(SQ(var_fs0) + SQ(sp50) + SQ(sp4C));
        if (temp_fv1 > 0.01f) {
            temp_fv1 = 1.0f / temp_fv1;
            arg0->unk_B4.x = temp_fv1 * var_fs0;
            arg0->unk_B4.y = temp_fv1 * sp50;
            arg0->unk_B4.z = temp_fv1 * sp4C;
        }
    } else {
        arg0->unk_B4 = arg0->unk_19C;
    }

    if (arg0->unk_270 < arg0->unk_0C.unk_40) {
        temp_fv1 = arg0->unk_270 / arg0->unk_0C.unk_40;
        arg0->unk_0C.unk_40 = arg0->unk_270;

        arg0->unk_0C.unk_28.x *= temp_fv1;
        arg0->unk_0C.unk_34.x = arg0->unk_0C.unk_44.x = arg0->unk_0C.unk_28.x + arg0->unk_0C.unk_1C.x;
        arg0->unk_0C.unk_28.y *= temp_fv1;
        arg0->unk_0C.unk_34.y = arg0->unk_0C.unk_44.y = arg0->unk_0C.unk_28.y + arg0->unk_0C.unk_1C.y;
        arg0->unk_0C.unk_28.z *= temp_fv1;
        arg0->unk_0C.unk_34.z = arg0->unk_0C.unk_44.z = arg0->unk_0C.unk_28.z + arg0->unk_0C.unk_1C.z;

        arg0->unk_A0 = 0.0f;

        var_fs0 = (arg0->unk_19C.x * arg0->velocity.x) + (arg0->unk_19C.y * arg0->velocity.y) +
                  (arg0->unk_19C.z * arg0->velocity.z);
        if (var_fs0 < 0.0f) {
            arg0->velocity.x -= var_fs0 * arg0->unk_19C.x;
            arg0->velocity.y -= var_fs0 * arg0->unk_19C.y;
            arg0->velocity.z -= var_fs0 * arg0->unk_19C.z;
            if ((arg0->id < gNumPlayers) && (D_800E5FD0 != 0)) {
                func_800BB3C4(arg0->id, var_fs0);
            }
        }
    }

    arg0->unk_A8.x = arg0->unk_24C.xy;
    arg0->unk_A8.y = arg0->unk_24C.yy;
    arg0->unk_A8.z = arg0->unk_24C.zy;
    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_19C.x);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_19C.y);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_19C.z);

    if (arg0->unk_A0 <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA3E4(arg0->id, 8);
                }
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->id, 8);
                }
            }
        }
    }
}

void func_80090490(Racer* arg0) {

    arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_FLAGS_4000000;
    if (arg0->id < gNumPlayers) {
        if (!(arg0->unk_08 & 0x2000)) {
            arg0->unk_08 |= 0x2000;
            if (D_800E5FD0 != 0) {
                func_800BA2F0(arg0->id, 8);
            }
        }
    }

    arg0->unk_168.y = -54321.0f;

    arg0->unk_A0 = (arg0->unk_0C.unk_28.x * arg0->unk_24C.xy) + (arg0->unk_0C.unk_28.y * arg0->unk_24C.yy) +
                   (arg0->unk_0C.unk_28.z * arg0->unk_24C.zy);

    arg0->unk_19C.x = arg0->unk_24C.xy;
    arg0->unk_19C.y = arg0->unk_24C.yy;
    arg0->unk_19C.z = arg0->unk_24C.zy;
    func_8008E418(arg0);
    func_8008E504(arg0);
}

void func_80090568(Racer* arg0) {
    f32 temp_fv1;
    f32 sp48;
    f32 temp_fv0;

    sp48 = (arg0->unk_24C.xz * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yz * arg0->unk_0C.unk_28.y) +
           (arg0->unk_24C.zz * arg0->unk_0C.unk_28.z);

    arg0->unk_A0 = (arg0->unk_24C.xy * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.yy * arg0->unk_0C.unk_28.y) +
                   (arg0->unk_24C.zy * arg0->unk_0C.unk_28.z);

    arg0->unk_19C.x = arg0->unk_24C.xy;
    arg0->unk_19C.y = arg0->unk_24C.yy;
    arg0->unk_19C.z = arg0->unk_24C.zy;

    // FAKE
    if ((arg0->stateFlags ^ 0) & RACER_STATE_FLAGS_80000000) {
        if ((arg0->unk_A0 < -100.0f) || (arg0->unk_A0 > 30.0f) || (sp48 < -arg0->unk_274) || (arg0->unk_270 < sp48)) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    } else if ((arg0->unk_A0 > 30.0f) || (sp48 < -arg0->unk_274) || (arg0->unk_270 < sp48)) {
        arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->id, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);
        arg0->unk_168.y = -54321.0f;
        return;
    }

    if (arg0->unk_A0 < 0.0f) {

        temp_fv0 = arg0->unk_A0 * arg0->unk_24C.xy;
        arg0->unk_0C.unk_28.x -= temp_fv0;
        arg0->unk_0C.unk_34.x -= temp_fv0;
        arg0->unk_0C.unk_44.x -= temp_fv0;

        temp_fv0 = arg0->unk_A0 * arg0->unk_24C.yy;
        arg0->unk_0C.unk_28.y -= temp_fv0;
        arg0->unk_0C.unk_34.y -= temp_fv0;
        arg0->unk_0C.unk_44.y -= temp_fv0;

        temp_fv0 = arg0->unk_A0 * arg0->unk_24C.zy;
        arg0->unk_0C.unk_28.z -= temp_fv0;
        arg0->unk_0C.unk_34.z -= temp_fv0;
        arg0->unk_0C.unk_44.z -= temp_fv0;

        arg0->unk_A0 = 0.0f;
        sp48 = (arg0->unk_24C.xy * arg0->velocity.x) + (arg0->unk_24C.yy * arg0->velocity.y) +
               (arg0->unk_24C.zy * arg0->velocity.z);

        if (sp48 < 0.0f) {
            arg0->velocity.x -= sp48 * arg0->unk_24C.xy;
            arg0->velocity.y -= sp48 * arg0->unk_24C.yy;
            arg0->velocity.z -= sp48 * arg0->unk_24C.zy;
            if ((arg0->id < gNumPlayers) && (D_800E5FD0 != 0)) {
                func_800BB3C4(arg0->id, sp48);
            }
        }
    }

    if (arg0->unk_A0 <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA3E4(arg0->id, 8);
                }
            }
        }
        arg0->unk_A8.x = arg0->unk_B4.x = arg0->unk_24C.xy;
        arg0->unk_A8.y = arg0->unk_B4.y = arg0->unk_24C.yy;
        arg0->unk_A8.z = arg0->unk_B4.z = arg0->unk_24C.zy;
    } else {
        arg0->stateFlags |= RACER_STATE_FLAGS_4000000;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(arg0->id, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);

        if (arg0->unk_A0 < 30.0f) {
            temp_fv1 = (arg0->unk_A0 - 15.0f) / 15.0f;

            arg0->unk_A8.x = ((arg0->unk_A8.x - arg0->unk_24C.xy) * temp_fv1) + arg0->unk_24C.xy;
            arg0->unk_A8.y = ((arg0->unk_A8.y - arg0->unk_24C.yy) * temp_fv1) + arg0->unk_24C.yy;
            arg0->unk_A8.z = ((arg0->unk_A8.z - arg0->unk_24C.zy) * temp_fv1) + arg0->unk_24C.zy;

            arg0->unk_B4.x = ((arg0->unk_B4.x - arg0->unk_24C.xy) * temp_fv1) + arg0->unk_B4.x;
            arg0->unk_B4.y = ((arg0->unk_B4.y - arg0->unk_24C.yy) * temp_fv1) + arg0->unk_B4.y;
            arg0->unk_B4.z = ((arg0->unk_B4.z - arg0->unk_24C.zy) * temp_fv1) + arg0->unk_B4.z;

            temp_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));
            arg0->unk_B4.x *= temp_fv1;
            arg0->unk_B4.y *= temp_fv1;
            arg0->unk_B4.z *= temp_fv1;
        }
    }
    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_24C.xy);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_24C.yy);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_24C.zy);
}

void func_80090AFC(Racer* arg0) {

    if (!(arg0->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_4000))) {
        func_8008DBB8(arg0, 120);
    }
    arg0->stateFlags = (arg0->stateFlags & ~RACER_STATE_FLAGS_400000) | RACER_STATE_FLAGS_80000;

    if ((arg0->id < gNumPlayers) && (D_800E5FD0 != 0)) {
        if (D_800CE3B0[arg0->character]) {
            func_800BA710(arg0->id, 52);
        } else {
            func_800BA710(arg0->id, 53);
        }
        func_800894C0(arg0);
    }
}

extern u32 gGameFrameCount;

#ifdef NON_MATCHING
void func_80090BCC(Racer* racer, Controller* controller) {
    bool var_v1;
    s32 i;
    s32 sp13C;
    s32 sp138;
    s32 sp134;
    f32 var_fa1; // sp130
    f32 sp12C;
    f32 sp128;
    f32 var_fv1;
    f32 var_fs1;
    f32 var_fs0;
    f32 var_ft4; // sp118
    Vec3f sp10C;
    Mtx3F spE8;
    f32 spE4;
    CourseSegment* temp_v1;
    unk_802D3E38* temp_a0;
    unk_802D3E38* var_v0;
    unk_802D3978* var_v0_2;
    unk_802D3978* temp2;
    unk_802D3D38* var_v0_3;
    unk_802D3D38* temp;
    u16 buttonReleased; // spC6
    u16 buttonCurrent;
    u16 buttonPressed;
    f32 temp_fa0;
    s32 pad;

    if (!(racer->stateFlags & RACER_STATE_FLAGS_400000)) {
        buttonReleased = 0;
        buttonPressed = 0;
        buttonCurrent = 0;
        racer->unk_E4 = 0.0f;
        sp12C = racer->unk_238;
        racer->unk_238 *= 0.99f;
    } else {
        buttonCurrent = controller->buttonCurrent;
        buttonPressed = controller->buttonPressed;
        buttonReleased = controller->buttonReleased;
        racer->unk_E4 = controller->stickY / 63.0f;

        if (racer->unk_E4 < -1.0f) {
            racer->unk_E4 = -1.0f;
        } else if (racer->unk_E4 > 1.0f) {
            racer->unk_E4 = 1.0f;
        }
        sp12C = controller->stickX / 63.0f;

        if (sp12C < -1.0f) {
            sp12C = -1.0f;
        } else if (sp12C > 1.0f) {
            sp12C = 1.0f;
        }
    }

    spE8 = racer->unk_C0;

    sp10C.x = racer->unk_0C.unk_34.x + racer->velocity.x;
    sp10C.y = racer->unk_0C.unk_34.y + racer->velocity.y;
    sp10C.z = racer->unk_0C.unk_34.z + racer->velocity.z;
    temp_v1 = racer->unk_0C.courseSegment;

    racer->stateFlags &= ~COURSE_EFFECT_MASK;
    var_v0 = temp_v1->unk_54;
    if ((var_v0 != NULL) && !(racer->stateFlags & RACER_STATE_FLAGS_4000000)) {
        temp_a0 = temp_v1->unk_58;
        if (temp_v1->trackSegmentInfo & TRACK_FLAG_8000000) {
            var_fa1 = (racer->unk_0C.unk_28.x * racer->unk_24C.z.x) + (racer->unk_0C.unk_28.y * racer->unk_24C.z.y) +
                      (racer->unk_0C.unk_28.z * racer->unk_24C.z.z) + (0.5f * (racer->unk_274 - racer->unk_270));

            do {
                if (var_fa1 < var_v0->unk_0C.x) {
                    continue;
                }
                if (var_v0->unk_18.x < var_fa1) {
                    continue;
                }
                if (racer->unk_0C.unk_04 < var_v0->unk_04) {
                    continue;
                }
                if (var_v0->unk_08 < racer->unk_0C.unk_04) {
                    continue;
                }
                racer->stateFlags |= var_v0->effectType;
                break;
            } while (++var_v0 != temp_a0);

        } else {

            do {
                if (racer->unk_0C.unk_04 < var_v0->unk_04) {
                    continue;
                }

                if (var_v0->unk_08 < racer->unk_0C.unk_04) {
                    continue;
                }

                if ((((racer->unk_0C.unk_28.y * var_v0->unk_0C.z) - (racer->unk_0C.unk_28.z * var_v0->unk_0C.y)) *
                     racer->unk_24C.x.x) +
                        (((racer->unk_0C.unk_28.z * var_v0->unk_0C.x) - (racer->unk_0C.unk_28.x * var_v0->unk_0C.z)) *
                         racer->unk_24C.x.y) +
                        (((racer->unk_0C.unk_28.x * var_v0->unk_0C.y) - (racer->unk_0C.unk_28.y * var_v0->unk_0C.x)) *
                         racer->unk_24C.x.z) <
                    0.0f) {
                    continue;
                }

                if ((((var_v0->unk_18.y * racer->unk_0C.unk_28.z) - (var_v0->unk_18.z * racer->unk_0C.unk_28.y)) *
                     racer->unk_24C.x.x) +
                        (((var_v0->unk_18.z * racer->unk_0C.unk_28.x) - (var_v0->unk_18.x * racer->unk_0C.unk_28.z)) *
                         racer->unk_24C.x.y) +
                        (((var_v0->unk_18.x * racer->unk_0C.unk_28.y) - (var_v0->unk_18.y * racer->unk_0C.unk_28.x)) *
                         racer->unk_24C.x.z) <
                    0.0f) {
                    continue;
                }

                racer->stateFlags |= var_v0->effectType;
                break;

            } while (++var_v0 != temp_a0);
        }
    }
    if ((sp12C > 0.1f) || (sp12C < -0.1f)) {
        var_fs1 = racer->unk_C0.x.x;
        var_fs0 = racer->unk_C0.x.y;
        var_ft4 = racer->unk_C0.x.z;

        if (racer->unk_21C != 0) {
            var_fa1 = 0.2f;
        } else {
            if (buttonCurrent & (BTN_Z | BTN_R)) {
                if (racer->unk_1D8 != 0.f) {
                    var_fa1 = ((racer->unk_1E0 - racer->unk_1E4) * 0.4f) + racer->unk_1E4;
                } else {
                    var_fa1 = racer->unk_1E0;
                }
            } else if (racer->stateFlags & RACER_STATE_FLAGS_20000000) {
                if (buttonCurrent & BTN_A) {
                    var_fa1 = racer->unk_1E4;
                } else {
                    var_fa1 = ((racer->unk_1E0 - racer->unk_1E4) * 0.125f) + racer->unk_1E4;
                }
            } else {
                var_fa1 = racer->unk_1E0;
            }
        }
        var_fa1 *= sp12C;

        racer->unk_C0.x.x -= (var_fa1 * racer->unk_C0.z.x);
        racer->unk_C0.x.y -= (var_fa1 * racer->unk_C0.z.y);
        racer->unk_C0.x.z -= (var_fa1 * racer->unk_C0.z.z);

        racer->unk_C0.z.x = (racer->unk_C0.y.y * racer->unk_C0.x.z) - (racer->unk_C0.y.z * racer->unk_C0.x.y);

        racer->unk_C0.z.y = (racer->unk_C0.y.z * racer->unk_C0.x.x) - (racer->unk_C0.y.x * racer->unk_C0.x.z);

        racer->unk_C0.z.z = (racer->unk_C0.y.x * racer->unk_C0.x.y) - (racer->unk_C0.y.y * racer->unk_C0.x.x);

        temp_fa0 = 1.0f / sqrtf(SQ(racer->unk_C0.z.x) + SQ(racer->unk_C0.z.y) + SQ(racer->unk_C0.z.z));
        racer->unk_C0.z.x *= temp_fa0;
        racer->unk_C0.z.y *= temp_fa0;
        racer->unk_C0.z.z *= temp_fa0;

        var_fs1 -= racer->unk_C0.x.x = (racer->unk_C0.z.y * racer->unk_C0.y.z) - (racer->unk_C0.z.z * racer->unk_C0.y.y);
        var_fs0 -= racer->unk_C0.x.y = (racer->unk_C0.z.z * racer->unk_C0.y.x) - (racer->unk_C0.z.x * racer->unk_C0.y.z);
        var_ft4 -= racer->unk_C0.x.z = (racer->unk_C0.z.x * racer->unk_C0.y.y) - (racer->unk_C0.z.y * racer->unk_C0.y.x);
        spE4 = sqrtf(SQ(var_fs1) + SQ(var_fs0) + SQ(var_ft4));
    } else {
        spE4 = 0.0f;
    }
    if (racer->unk_21C != 0) {
        var_fs1 = var_ft4 = 0.997f;
    } else if (racer->stateFlags & RACER_STATE_FLAGS_8000000) {
        var_fs1 = var_ft4 = 0.98305196f;
    } else {
        var_ft4 = 0.997f;
        var_fs1 = 0.996f;
    }
    if ((racer->boostTimer == 0) && ((racer->stateFlags & (RACER_STATE_FLAGS_4000000 | COURSE_EFFECT_MASK)) == COURSE_EFFECT_DIRT)) {
        var_fs1 *= 0.987f;
        var_ft4 *= 0.987f;
        if (racer->id < gNumPlayers) {
            if (!(racer->unk_08 & 0x400)) {
                racer->unk_08 |= 0x400;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(racer->id, 5);
                }
            }
        }
    } else if (racer->id < gNumPlayers) {
        if (racer->unk_08 & 0x400) {
            racer->unk_08 &= ~0x400;
            if (D_800E5FD0 != 0) {
                func_800BA3E4(racer->id, 5);
            }
        }
    }

    if (buttonCurrent & BTN_CDOWN) {
        var_fs1 *= 0.987f;
        var_ft4 *= 0.987f;
        if (gGameMode == GAMEMODE_GP_END_CS) {
            var_fs1 *= 0.9f;
            var_ft4 *= 0.9f;
        }
        if (racer->id < gNumPlayers) {
            if (!(racer->unk_08 & 0x80)) {
                racer->unk_08 |= 0x80;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(racer->id, 9);
                }
            }
        }
    } else if (racer->id < gNumPlayers) {
        if (racer->unk_08 & 0x80) {
            racer->unk_08 &= ~0x80;
            if (D_800E5FD0 != 0) {
                func_800BA3E4(racer->id, 9);
            }
        }
    }

    var_fs1 *= ((racer->unk_C0.z.x * racer->velocity.x) + (racer->unk_C0.z.y * racer->velocity.y) +
                (racer->unk_C0.z.z * racer->velocity.z));
    var_fs0 = ((racer->unk_C0.y.x * racer->velocity.x) + (racer->unk_C0.y.y * racer->velocity.y) +
               (racer->unk_C0.y.z * racer->velocity.z)) *
              0.94f;
    var_ft4 *= ((racer->unk_C0.x.x * racer->velocity.x) + (racer->unk_C0.x.y * racer->velocity.y) +
                (racer->unk_C0.x.z * racer->velocity.z));
    racer->velocity.x = (racer->unk_C0.z.x * var_fs1) + (racer->unk_C0.y.x * var_fs0) + (racer->unk_C0.x.x * var_ft4);
    racer->velocity.y = (racer->unk_C0.z.y * var_fs1) + (racer->unk_C0.y.y * var_fs0) + (racer->unk_C0.x.y * var_ft4);
    racer->velocity.z = (racer->unk_C0.z.z * var_fs1) + (racer->unk_C0.y.z * var_fs0) + (racer->unk_C0.x.z * var_ft4);

    if ((buttonPressed & BTN_B) && (racer->boostTimer == 0) && (racer->energy != 0.0) && (racer->stateFlags & RACER_STATE_FLAGS_100000)) {
        racer->shadowColorStrength = 1.3f;
        racer->shadowBaseR = racer->shadowBaseB = 91.0f;
        racer->shadowBaseG = 255.0f;
        racer->boostTimer = sInitialBoostTimer;
        racer->unk_08 |= 0x1000;
        if (D_800E5FD0 != 0) {
            func_800BA710(racer->id, 7);
        }
    } else {
        if ((racer->stateFlags & (RACER_STATE_FLAGS_8000000 | COURSE_EFFECT_MASK)) == COURSE_EFFECT_DASH) {
            buttonCurrent |= BTN_A;
            racer->shadowColorStrength = 1.3f;
            racer->shadowBaseR = 255.0f;
            racer->shadowBaseG = 223.0f;
            racer->shadowBaseB = 0.0f;
            racer->stateFlags |= RACER_STATE_DASH_PAD_BOOST;
            racer->boostTimer = sInitialBoostTimer;
            if (!(racer->unk_08 & 0x1000)) {
                racer->unk_08 |= 0x1000;
                if (D_800E5FD0 != 0) {
                    func_800BA710(racer->id, 7);
                }
            }
        } else {
            racer->unk_08 &= ~0x1000;
        }
    }

    if (!(racer->stateFlags & RACER_STATE_FLAGS_10000)) {
        temp_v1 = racer->unk_0C.courseSegment;
        var_v0_2 = temp_v1->unk_4C;
        if (var_v0_2 != NULL) {
            temp2 = temp_v1->unk_50;
            do {
                var_fs1 = var_v0_2->unk_04.x - racer->unk_0C.unk_34.x;
                var_fs0 = var_v0_2->unk_04.y - racer->unk_0C.unk_34.y;
                var_ft4 = var_v0_2->unk_04.z - racer->unk_0C.unk_34.z;
                if ((SQ(var_fs1) + SQ(var_fs0) + SQ(var_ft4)) < 900.0f) {
                    racer->acceleration.x += (15.0f * racer->unk_B4.x);
                    racer->acceleration.y += (15.0f * racer->unk_B4.y);
                    racer->acceleration.z += (15.0f * racer->unk_B4.z);
                    racer->stateFlags |= RACER_STATE_FLAGS_10000;
                    func_8008DCD8(racer, 12.5f);
                    if (D_800E5FD0 != 0) {
                        func_800BA710(racer->id, 1);
                    }
                    break;
                }
            } while (++var_v0_2 != temp2);
        }
    }

    if (!(racer->stateFlags & RACER_STATE_FLAGS_200000)) {
        temp_v1 = racer->unk_0C.courseSegment;
        var_v0_3 = temp_v1->unk_44;
        if (var_v0_3 != NULL) {
            temp = temp_v1->unk_48;
            do {
                var_fs1 = racer->unk_0C.unk_34.x - var_v0_3->unk_00.x;
                var_fs0 = racer->unk_0C.unk_34.y - var_v0_3->unk_00.y;
                var_ft4 = racer->unk_0C.unk_34.z - var_v0_3->unk_00.z;
                var_fa1 = (var_v0_3->unk_0C.x.x * var_fs1) + (var_v0_3->unk_0C.x.y * var_fs0) +
                          (var_v0_3->unk_0C.x.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (var_v0_3->unk_30.z < var_fa1) {
                    continue;
                }

                var_fa1 = (var_v0_3->unk_0C.z.x * var_fs1) + (var_v0_3->unk_0C.z.y * var_fs0) +
                          (var_v0_3->unk_0C.z.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (var_v0_3->unk_30.x < var_fa1) {
                    continue;
                }

                var_fa1 = (var_v0_3->unk_0C.y.x * var_fs1) + (var_v0_3->unk_0C.y.y * var_fs0) +
                          (var_v0_3->unk_0C.y.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (var_v0_3->unk_30.y < var_fa1) {
                    continue;
                }

                racer->stateFlags |= RACER_STATE_FLAGS_200000;
                racer->unk_1DC = (racer->speed * 0.3f) + 0.5f;
                if ((racer->id < gNumPlayers) && (D_800E5FD0 != 0)) {
                    func_800BA710(racer->id, 0x37);
                }
                break;

            } while (++var_v0_3 != temp);
        }
    }
    racer->acceleration.x += (-1.0f * racer->unk_A8.x);
    racer->acceleration.y += (-1.0f * racer->unk_A8.y);
    racer->acceleration.z += (-1.0f * racer->unk_A8.z);
    if (racer->stateFlags & RACER_STATE_FLAGS_200000) {
        racer->acceleration.x += (racer->unk_1DC * racer->unk_B4.x);
        racer->acceleration.y += (racer->unk_1DC * racer->unk_B4.y);
        racer->acceleration.z += (racer->unk_1DC * racer->unk_B4.z);
        racer->unk_1DC *= 0.8f;
    }
    if (!(racer->stateFlags & RACER_STATE_FLAGS_80000000)) {
        var_fa1 = racer->unk_17C - racer->unk_A0;
        if (var_fa1 > 0.0f) {
            var_fa1 -= ((racer->velocity.x * racer->unk_19C.x) + (racer->velocity.y * racer->unk_19C.y) +
                        (racer->velocity.z * racer->unk_19C.z));

            racer->unk_198 = var_fa1 * 0.2f;

            racer->acceleration.x += (racer->unk_198 * racer->unk_19C.x);
            racer->acceleration.y += (racer->unk_198 * racer->unk_19C.y);
            racer->acceleration.z += (racer->unk_198 * racer->unk_19C.z);
            if (racer->unk_1DC < 0.5f) {
                racer->stateFlags &= ~(RACER_STATE_FLAGS_200000 | RACER_STATE_FLAGS_10000);
            }
        } else {
            racer->unk_198 = 0.0f;
        }
    } else {
        racer->unk_198 = 0.0f;
    }
    racer->unk_278++;
    racer->unk_27A++;
    if (buttonPressed & STICK_UP) {
        buttonPressed |= BTN_Z;
        buttonCurrent |= BTN_R;
        racer->unk_278 = 10;
    } else if (buttonPressed & STICK_DOWN) {
        buttonCurrent |= BTN_Z;
        buttonPressed |= BTN_R;
        racer->unk_27A = 10;
    }

    switch (buttonPressed & (BTN_Z | BTN_R)) {
        case BTN_Z:
            if ((racer->unk_278 < 0xF) && (racer->unk_27C == 0)) {
                racer->unk_27C = 0x80;
                racer->unk_280 = 0x100;
                if (buttonCurrent & BTN_R) {
                    racer->unk_284 = 2;
                    if (D_800E5FD0 != 0) {
                        func_800BA710(racer->id, 2);
                    }
                } else {
                    racer->unk_284 = 1;
                    if (D_800E5FD0 != 0) {
                        func_800BA710(racer->id, 6);
                    }
                }
            }
            racer->unk_278 = 0;
            break;
        case BTN_R:
            if ((racer->unk_27A < 0xF) && (racer->unk_27C == 0)) {
                racer->unk_27C = 0xF80;
                racer->unk_280 = -0x100;
                if (buttonCurrent & BTN_Z) {
                    racer->unk_284 = 2;
                    if (D_800E5FD0 != 0) {
                        func_800BA710(racer->id, 2);
                    }
                } else {
                    racer->unk_284 = 1;
                    if (D_800E5FD0 != 0) {
                        func_800BA710(racer->id, 6);
                    }
                }
            }
            racer->unk_27A = 0;
            break;
        default:
            break;
    }

    var_v1 = false;
    if (racer->unk_284 == 1) {
        if (racer->unk_280 < 0) {
            racer->unk_286 = 1;
            var_fa1 = -racer->unk_5C.x;
        } else {
            var_fa1 = racer->unk_5C.x;
            racer->unk_286 = 0;
        }
        if (var_fa1 < 0.0f) {
            racer->unk_1D8 = 5.0f;
        } else if (var_fa1 < 6.0f) {
            racer->unk_1D8 = 5.0f - (0.8333333f * var_fa1);
        } else {
            racer->unk_1D8 = 0.0f;
        }

        var_fs1 = racer->unk_1D8 * racer->unk_C0.z.x;
        var_fs0 = racer->unk_1D8 * racer->unk_C0.z.y;
        var_ft4 = racer->unk_1D8 * racer->unk_C0.z.z;
        var_fa1 = (racer->unk_A8.x * var_fs1) + (var_fs0 * racer->unk_A8.y) + (var_ft4 * racer->unk_A8.z);
        if (racer->unk_286 == 1) {
            racer->acceleration.x -= (var_fs1 - (var_fa1 * racer->unk_A8.x));
            racer->acceleration.y -= (var_fs0 - (var_fa1 * racer->unk_A8.y));
            racer->acceleration.z -= (var_ft4 - (var_fa1 * racer->unk_A8.z));
        } else {
            racer->acceleration.x += (var_fs1 - (var_fa1 * racer->unk_A8.x));
            racer->acceleration.y += (var_fs0 - (var_fa1 * racer->unk_A8.y));
            racer->acceleration.z += (var_ft4 - (var_fa1 * racer->unk_A8.z));
        }
    } else if (racer->unk_284 == 2) {
        if (racer->unk_280 < 0) {
            racer->unk_286 = 1;
            var_fa1 = -racer->unk_5C.x;
        } else {
            var_fa1 = racer->unk_5C.x;
            racer->unk_286 = 0;
        }
        if (var_fa1 < 0.0f) {
            racer->unk_1D8 = 0.5f;
        } else if (var_fa1 < 2.0f) {
            racer->unk_1D8 = 0.5f - (0.25f * var_fa1);
        } else {
            racer->unk_1D8 = 0.0f;
        }

        var_fs1 = racer->unk_1D8 * racer->unk_C0.z.x;
        var_fs0 = racer->unk_1D8 * racer->unk_C0.z.y;
        var_ft4 = racer->unk_1D8 * racer->unk_C0.z.z;
        if (racer->unk_286 == 1) {
            racer->acceleration.x -= var_fs1;
            racer->acceleration.y -= var_fs0;
            racer->acceleration.z -= var_ft4;
        } else {
            racer->acceleration.x += var_fs1;
            racer->acceleration.y += var_fs0;
            racer->acceleration.z += var_ft4;
        }
    } else {
        switch (buttonCurrent & (BTN_Z | BTN_R)) {
            case 0:
            case (BTN_Z | BTN_R):
                racer->unk_1D8 = 0.0f;
                break;
            default:
                if ((buttonCurrent & (BTN_Z | BTN_R)) == BTN_Z) {
                    var_fa1 = racer->unk_5C.x;
                    racer->unk_286 = 0;
                } else {
                    racer->unk_286 = 1;
                    var_fa1 = -racer->unk_5C.x;
                }
                if (var_fa1 < 0.0f) {
                    racer->unk_1D8 = 1.0f;
                } else if (var_fa1 < 8.0f) {
                    racer->unk_1D8 = 1.0f - (0.125f * var_fa1);
                } else {
                    racer->unk_1D8 = 0.0f;
                }
                if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_ICE) {
                    racer->unk_1D8 *= 0.2f;
                }

                var_fs1 = racer->unk_1D8 * racer->unk_C0.z.x;
                var_fs0 = racer->unk_1D8 * racer->unk_C0.z.y;
                var_ft4 = racer->unk_1D8 * racer->unk_C0.z.z;
                var_fa1 = (racer->unk_A8.x * var_fs1) + (var_fs0 * racer->unk_A8.y) + (var_ft4 * racer->unk_A8.z);
                if (racer->unk_286 == 1) {
                    racer->acceleration.x -= (var_fs1 - (var_fa1 * racer->unk_A8.x));
                    racer->acceleration.y -= (var_fs0 - (var_fa1 * racer->unk_A8.y));
                    racer->acceleration.z -= (var_ft4 - (var_fa1 * racer->unk_A8.z));
                } else {
                    racer->acceleration.x += (var_fs1 - (var_fa1 * racer->unk_A8.x));
                    racer->acceleration.y += (var_fs0 - (var_fa1 * racer->unk_A8.y));
                    racer->acceleration.z += (var_ft4 - (var_fa1 * racer->unk_A8.z));
                }

                var_v1 = true;
                break;
        }
    }
    if (racer->id < gNumPlayers) {
        if (var_v1) {
            if (!(racer->unk_08 & 0x40)) {
                racer->unk_08 |= 0x40;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(racer->id, 0xA);
                }
            }
        } else {
            if (racer->unk_08 & 0x40) {
                racer->unk_08 &= ~0x40;
                if (D_800E5FD0 != 0) {
                    func_800BA3E4(racer->id, 0xA);
                }
            }
        }
    }

    if (!(racer->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_4000)) && ((racer->stateFlags & COURSE_EFFECT_MASK) != COURSE_EFFECT_ICE)) {
        sp128 = (racer->unk_C0.z.x * racer->velocity.x) + (racer->unk_C0.z.y * racer->velocity.y) +
                (racer->unk_C0.z.z * racer->velocity.z);

        if (sp128 < 0.0f) {
            var_fa1 = -1.0f;
            sp128 = -sp128;
        } else {
            var_fa1 = 1.0f;
        }
        if (buttonPressed & BTN_A) {
            racer->unk_204 = 0x1E;
            racer->unk_214 = 0x1B;
            if ((racer->id < gNumPlayers) && (D_800E5FD0 != 0)) {
                func_800BA710(racer->id, 0x29);
            }
        } else {
            if (racer->unk_214 != 0) {
                racer->unk_214--;
            }
        }
        if ((racer->stateFlags & (RACER_STATE_FLAGS_4000000 | RACER_STATE_FLAGS_20000)) || (racer->unk_208 != 0) || (buttonCurrent & (BTN_Z | BTN_R))) {

            if (racer->unk_208 != 0) {
                racer->unk_208--;
            }

            if (racer->unk_204 != 0) {
                racer->unk_204--;
            }
            racer->stateFlags &= ~RACER_STATE_FLAGS_20000000;

            if (racer->unk_1FC < sp128) {
                sp128 = racer->unk_1FC;
            }
        } else {
            if ((racer->unk_204 != 0) || !(buttonCurrent & BTN_A)) {
                if (racer->unk_204 != 0) {
                    racer->unk_204--;
                }
                racer->stateFlags |= RACER_STATE_FLAGS_20000000;

                if (racer->unk_1F8 < sp128) {
                    sp128 = racer->unk_1F8;
                }
            } else if (racer->stateFlags & RACER_STATE_FLAGS_20000000) {
                if (racer->unk_1F8 < sp128) {
                    racer->stateFlags &= ~RACER_STATE_FLAGS_20000000;
                    sp128 = racer->unk_1FC;
                }
            } else {
                if (racer->unk_1FC < sp128) {
                    sp128 = racer->unk_1FC;
                } else {
                    racer->stateFlags |= RACER_STATE_FLAGS_20000000;
                }
            }
        }

        sp128 *= var_fa1;
        racer->velocity.x -= sp128 * racer->unk_C0.z.x;
        racer->velocity.y -= sp128 * racer->unk_C0.z.y;
        racer->velocity.z -= sp128 * racer->unk_C0.z.z;
        if (((racer->unk_5C.x < -8.0f) || (racer->unk_5C.x > 8.0f)) && !(racer->stateFlags & RACER_STATE_FLAGS_4000000)) {

            racer->unk_20C++;
            var_fa1 = racer->unk_20C / 100.0f;
            if (var_fa1 >= 1.0f) {
                racer->unk_200 = racer->unk_1C8;
            } else if (racer->unk_200 < var_fa1) {
                racer->unk_200 = racer->unk_1C8 * var_fa1;
            }
            if (racer->id < gNumPlayers) {
                if (!(racer->unk_08 & 0x200)) {
                    racer->unk_08 |= 0x200;
                    if (D_800E5FD0 != 0) {
                        func_800BA2F0(racer->id, 6);
                    }
                }
            }
        } else {
            racer->unk_20C = 0;
            if (racer->id < gNumPlayers) {
                if (racer->unk_08 & 0x200) {
                    racer->unk_08 &= ~0x200;
                    if (D_800E5FD0 != 0) {
                        func_800BA3E4(racer->id, 6);
                    }
                }
            }
        }
    } else {
        racer->unk_20C = 0;
        if (racer->id < gNumPlayers) {
            if (racer->unk_08 & 0x200) {
                racer->unk_08 &= ~0x200;
                if (D_800E5FD0 != 0) {
                    func_800BA3E4(racer->id, 6);
                }
            }
        }
    }

    if (racer->unk_200 != 0.0f) {
        var_fs1 = racer->unk_1B4;
        var_fs0 = racer->unk_1B8;
        var_ft4 = (racer->unk_31C * racer->unk_200) + 1.0f;
        racer->unk_200 -= racer->unk_1CC;
        if (racer->unk_200 < 0.0f) {
            racer->unk_200 = 0.0f;
        }
    } else {
        var_fs1 = racer->unk_1B0;
        var_fs0 = racer->unk_1B8;
        var_ft4 = 1.0f;
    }
    if ((gNumPlayers >= 2) && (gSettingVsHandicap == 2)) {
        var_fv1 = (D_800E5F40[0]->unk_23C - racer->unk_23C);
        var_fv1 /= D_800CE4D8;
        if (var_fv1 >= 1.0f) {
            var_fs1 += 0.03f;
            var_fs0 += 0.03f;
        } else {
            var_fs1 += 0.03f * var_fv1;
            var_fs0 += 0.03f * var_fv1;
        }
    }
    if (racer->boostTimer != 0) {
        if (racer->stateFlags & RACER_STATE_DASH_PAD_BOOST) {
            if (var_ft4 < racer->unk_1C4) {
                var_ft4 = racer->unk_1C4;
            }
        } else {
            if (var_ft4 < racer->unk_1C0) {
                var_ft4 = racer->unk_1C0;
            }
            if ((gNumPlayers == 1) || (gSettingVsHandicap == 0)) {
                sp128 = racer->boostEnergyUsage;
            } else {
                sp128 = (D_800E5F40[0]->unk_23C - racer->unk_23C);
                sp128 /= D_800CE4D8;
                if (sp128 >= 1.0f) {
                    sp128 = racer->boostEnergyUsage * 0.1f;
                } else {
                    sp128 = (((1.0f - sp128) * 0.9f) + 0.1f) * racer->boostEnergyUsage;
                }
            }
            racer->energy -= sp128;
            if (racer->energy < 0.0f) {
                racer->boostTimer = 1;
                racer->energy = 0.0f;
            }
        }
        racer->boostTimer--;
        if (racer->boostTimer == 0) {
            racer->stateFlags &= ~RACER_STATE_DASH_PAD_BOOST;
            racer->unk_08 &= ~0x1000;
        }
    }
    var_fs1 *= var_ft4;
    var_fs0 *= var_ft4;

    if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_ICE) {
        if (racer->id < gNumPlayers) {
            if (!(racer->unk_08 & 0x20)) {
                racer->unk_08 |= 0x20;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(racer->id, 0xB);
                }
            }
        }
        var_ft4 = racer->speed;
    } else {
        if (racer->id < gNumPlayers) {
            if (racer->unk_08 & 0x20) {
                racer->unk_08 &= ~0x20;
                if (D_800E5FD0 != 0) {
                    func_800BA3E4(racer->id, 0xB);
                }
            }
        }
        var_ft4 = racer->unk_5C.z;
    }
    if (((buttonCurrent | buttonReleased) & BTN_A) && (racer->speed < racer->unk_1EC)) {
        if (var_ft4 <= 0.0f) {
            var_ft4 = 0.0f;
            var_fv1 = var_fs1;
        } else {
            var_fv1 = racer->unk_1BC;
            if (var_ft4 < var_fv1) {
                var_fa1 = var_ft4 / var_fv1;

                sp128 = 1.0f - SQ((2.0f * var_fa1) - 1.0f);
                if (var_fs1 < var_fs0) {
                    sp128 *= (var_fs0 - var_fs1) * racer->unk_320;
                } else {
                    sp128 *= (var_fs1 - var_fs0) * racer->unk_320;
                }
                var_fv1 = ((var_fs0 - var_fs1) * var_fa1) + var_fs1 + sp128;
            } else {
                if (racer->unk_1E8 == 0.0f) {
                    var_fv1 = var_fs0;
                } else {
                    var_fv1 = ((D_800CF174[4] - var_fs0) * racer->unk_1E8) + var_fs0;
                }
            }
        }
        var_fv1 -= ((spE4 * 0.5f) + (racer->unk_1D8 * 0.16f));
        if (var_fv1 < 0.0f) {
            racer->unk_1D4 = 0.0f;
        } else {
            if (var_fv1 <= racer->unk_1D4) {
                racer->unk_1D4 = var_fv1;
            } else {
                var_ft4 *= racer->unk_324;
                if (var_ft4 < 1.0f) {
                    var_ft4 = (racer->unk_328 * var_ft4) + racer->unk_1D0;
                } else {
                    var_ft4 = 1.0f;
                }
                racer->unk_1D4 += ((var_fv1 - racer->unk_1D4) * var_ft4);
            }

            var_fs1 = racer->unk_1D4 * racer->unk_C0.x.x;
            var_fs0 = racer->unk_1D4 * racer->unk_C0.x.y;
            var_ft4 = racer->unk_1D4 * racer->unk_C0.x.z;
            var_fa1 = (racer->unk_A8.x * var_fs1) + (var_fs0 * racer->unk_A8.y) + (var_ft4 * racer->unk_A8.z);
            racer->acceleration.x += (var_fs1 - (var_fa1 * racer->unk_A8.x));
            racer->acceleration.y += (var_fs0 - (var_fa1 * racer->unk_A8.y));
            racer->acceleration.z += (var_ft4 - (var_fa1 * racer->unk_A8.z));
        }
    } else {
        racer->unk_1D4 = 0.0f;
    }
    racer->velocity.x += racer->acceleration.x;
    racer->velocity.y += racer->acceleration.y;
    racer->velocity.z += racer->acceleration.z;
    racer->speed = sqrtf(SQ(racer->velocity.x) + SQ(racer->velocity.y) + SQ(racer->velocity.z));
    if (racer->stateFlags & RACER_STATE_FLAGS_80000) {
        racer->velocity.x *= 0.94f;
        racer->velocity.z *= 0.94f;
        racer->unk_0C.unk_34.x += racer->velocity.x;
        racer->unk_0C.unk_34.y += racer->velocity.y;
        racer->unk_0C.unk_34.z += racer->velocity.z;
        racer->unk_0C.unk_28.x += racer->velocity.x;
        racer->unk_0C.unk_28.y += racer->velocity.y;
        racer->unk_0C.unk_28.z += racer->velocity.z;
        racer->unk_0C.unk_40 = sqrtf(SQ(racer->unk_0C.unk_28.x) + SQ(racer->unk_0C.unk_28.y) + SQ(racer->unk_0C.unk_28.z));
        D_800CF4B8[TRACK_SHAPE_INDEX(TRACK_SHAPE_AIR)](racer);
        if (racer->unk_0C.unk_34.y < -2750.0f) {
            racer->stateFlags &= ~RACER_STATE_FLAGS_40000000;
            racer->stateFlags |= RACER_STATE_FLAGS_8000000;
            D_800E5FC0++;
            func_800892E0(racer);

            if (racer->id < gNumPlayers) {
                func_800894C0(racer);
            }
            if ((racer->id < gNumPlayers) || (gRacers[0].stateFlags & RACER_STATE_FLAGS_80000)) {
                func_i2_80105590(racer->unk_0C.unk_34.x, racer->unk_0C.unk_34.y, racer->unk_0C.unk_34.z, 0.0f, 0.0f, 0.0f,
                                 600.0f, racer);
                if (D_800E5FD0 != 0) {
                    func_800BA710(racer->id, 8);
                    if ((racer->id == 0) && (gNumPlayers == 1)) {
                        func_800BB048();
                    }
                }
                racer->unk_C0.x.y = 0.0f;
                racer->unk_C0.y.x = 0.0f;
                racer->unk_C0.z.z = 0.0f;
                racer->unk_C0.x.x = 0.0f;
                racer->unk_C0.y.z = 0.0f;
                racer->unk_C0.z.y = 0.0f;
                racer->unk_C0.x.z = 1.0f;
                racer->unk_C0.y.y = 1.0f;
                racer->unk_C0.z.x = 1.0f;
                func_i2_801059B4(14.0f, racer);
            }
            if (racer->id < gNumPlayers) {
                controller->unk_88 = 0x2710;
                controller->unk_8C = 0x1F4;
                controller->unk_90 = 5;
            }
        }
    } else {
        if (racer->speed > 138.9f) {
            var_fa1 = 138.9f / racer->speed;
            racer->speed = 138.9f;
            racer->velocity.x *= var_fa1;
            racer->velocity.y *= var_fa1;
            racer->velocity.z *= var_fa1;
        }
        if (racer->id < gNumPlayers) {
            var_fa1 = 1.0f;
            i = 100;
        } else {
            var_fa1 = 5.0f;
            i = 3;
        }

        if (func_8009EBEC(&racer->unk_0C, racer->unk_0C.unk_34.x + racer->velocity.x,
                          racer->unk_0C.unk_34.y + racer->velocity.y, racer->unk_0C.unk_34.z + racer->velocity.z, i,
                          var_fa1) == 0) {
            sp128 = racer->unk_244;
            racer->unk_244 = func_8009DFA0(&racer->unk_0C);
            temp_v1 = racer->unk_0C.courseSegment;

            racer->unk_270 =
                (racer->unk_0C.unk_08 * (temp_v1->next->radiusLeft - temp_v1->radiusLeft)) + temp_v1->radiusLeft;
            racer->unk_274 =
                (racer->unk_0C.unk_08 * (temp_v1->next->radiusRight - temp_v1->radiusRight)) + temp_v1->radiusRight;

            var_fa1 = 1.0f / racer->unk_0C.unk_18;
            racer->unk_24C.x.x = racer->unk_0C.unk_0C.x * var_fa1;
            racer->unk_24C.x.y = racer->unk_0C.unk_0C.y * var_fa1;
            racer->unk_24C.x.z = racer->unk_0C.unk_0C.z * var_fa1;

            racer->unk_24C.y.x =
                (racer->unk_0C.unk_08 * (temp_v1->next->unk_0C.x - temp_v1->unk_0C.x)) + temp_v1->unk_0C.x;
            racer->unk_24C.y.y =
                (racer->unk_0C.unk_08 * (temp_v1->next->unk_0C.y - temp_v1->unk_0C.y)) + temp_v1->unk_0C.y;
            racer->unk_24C.y.z =
                (racer->unk_0C.unk_08 * (temp_v1->next->unk_0C.z - temp_v1->unk_0C.z)) + temp_v1->unk_0C.z;

            racer->unk_24C.z.x = (racer->unk_24C.y.y * racer->unk_24C.x.z) - (racer->unk_24C.y.z * racer->unk_24C.x.y);
            racer->unk_24C.z.y = (racer->unk_24C.y.z * racer->unk_24C.x.x) - (racer->unk_24C.y.x * racer->unk_24C.x.z);
            racer->unk_24C.z.z = (racer->unk_24C.y.x * racer->unk_24C.x.y) - (racer->unk_24C.y.y * racer->unk_24C.x.x);

            temp_fa0 = 1.0f / sqrtf(SQ(racer->unk_24C.z.x) + SQ(racer->unk_24C.z.y) + SQ(racer->unk_24C.z.z));

            racer->unk_24C.z.x *= temp_fa0;
            racer->unk_24C.z.y *= temp_fa0;
            racer->unk_24C.z.z *= temp_fa0;

            racer->unk_24C.y.x = (racer->unk_24C.x.y * racer->unk_24C.z.z) - (racer->unk_24C.x.z * racer->unk_24C.z.y);
            racer->unk_24C.y.y = (racer->unk_24C.x.z * racer->unk_24C.z.x) - (racer->unk_24C.x.x * racer->unk_24C.z.z);
            racer->unk_24C.y.z = (racer->unk_24C.x.x * racer->unk_24C.z.y) - (racer->unk_24C.x.y * racer->unk_24C.z.x);
            if (!(racer->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_2000000 | RACER_STATE_FLAGS_80000)) && (D_800F5E98 < 0x28) && (gGameMode != GAMEMODE_RECORDS)) {

                sp128 -= racer->unk_244;
                racer->unk_288++;
                racer->unk_2A4++;
                racer->raceTime = (s32) (racer->unk_2A4 * 50) / 3;
                if (D_800F80BC < sp128) {
                    racer->unk_240 += gCurrentCourseRecordInfo->length;
                    racer->lap++;
                    if ((racer->lap == racer->unk_2AA + 1) && ((gTotalLapCount + 1) >= racer->lap)) {
                        racer->unk_2AA = racer->lap;
                        racer->stateFlags |= RACER_STATE_FLAGS_100000;
                        i = racer->raceTime -
                            (s32) ((50.0f * racer->unk_244) / (3.0f * (gCurrentCourseRecordInfo->length - sp128)));
                        racer->lapTimes[racer->lap - 2] = (s32) (i - racer->unk_29C);
                        racer->unk_29C = i;
                        racer->unk_2B0 = 1;
                        if ((gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
                            if (racer == gRacers) {
                                if (racer->lapTimes[racer->lap - 2] < D_800E5FDC) {
                                    D_800E5FDC = racer->lapTimes[racer->lap - 2];
                                    D_800E5FE0 = 1;
                                }
                            }
                            if ((gTotalLapCount + 1) == racer->lap) {
                                racer->lap = racer->unk_2AA = 1;
                                racer->unk_240 = 0;
                            }
                        } else if ((gTotalLapCount + 1) == racer->lap) {
                            racer->raceTime = i;
                            racer->stateFlags |= RACER_STATE_FLAGS_2000000 | RACER_STATE_FLAGS_800000;
                            racer->energy = racer->maxEnergy;

                            if (racer->id < gNumPlayers) {
                                gControllers[gPlayerControlPorts[racer->id]].unk_72 = 0;
                                D_800E5FCA++;
                            }
                            D_800E5FC4++;
                            D_800F5DE8 = 1;

                            if (racer->id < gNumPlayers) {
                                if (D_800E5FD0 != 0) {
                                    func_800BA710(racer->id, 0xF);
                                    func_800BA2B4(racer->id);
                                }
                                func_800894C0(racer);
                                if (gNumPlayers == 1) {
                                    func_8007E0CC();
                                } else if (D_800E5FC4 == 1) {
                                    func_8007E0CC();
                                }
                            }
                        }
                    }
                } else if (sp128 < D_800F80C0) {
                    racer->lap--;
                    racer->unk_240 -= gCurrentCourseRecordInfo->length;
                }
                racer->unk_23C = racer->unk_248 = racer->unk_240 + racer->unk_244;
            }

            D_800CF4B8[TRACK_SHAPE_INDEX((u32) racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK)](racer);
            if (racer->stateFlags & RACER_STATE_FLAGS_80000000) {
                if ((racer->unk_0C.unk_34.x < -20000.0f) || (racer->unk_0C.unk_34.x > 20000.0f) ||
                    (racer->unk_0C.unk_34.z < -20000.0f) || (racer->unk_0C.unk_34.z > 20000.0f) ||
                    ((racer->velocity.y < 0.0f) && (racer->unk_0C.unk_28.y < -racer->unk_270) &&
                     (((racer->unk_0C.unk_28.x * racer->velocity.x) + (racer->unk_0C.unk_28.y * racer->velocity.y) +
                       (racer->unk_0C.unk_28.z * racer->velocity.z)) >= 0.0f))) {
                    func_80090AFC(racer);
                }
            }
        } else {
            racer->unk_0C.unk_34 = sp10C;
            func_80090AFC(racer);
        }
    }
    racer->unk_C0.y.x += 0.19f * racer->unk_B4.x;
    racer->unk_C0.y.y += 0.19f * racer->unk_B4.y;
    racer->unk_C0.y.z += 0.19f * racer->unk_B4.z;
    if (func_8006AC10(&racer->unk_C0) != 0) {
        racer->unk_C0 = spE8;
    }
    if (racer->unk_198 != 0.0f) {
        sp128 = racer->unk_A0;
    } else {
        sp128 = racer->unk_17C;
    }

    var_fa1 = racer->unk_180.x;
    var_fv1 = racer->unk_0C.unk_34.x - (sp128 * racer->unk_C0.y.x);
    racer->unk_180.x = var_fv1;
    racer->unk_18C.x = var_fv1 - var_fa1;

    var_fa1 = racer->unk_180.y;
    var_fv1 = racer->unk_0C.unk_34.y - (sp128 * racer->unk_C0.y.y);
    racer->unk_180.y = var_fv1;
    racer->unk_18C.y = var_fv1 - var_fa1;

    var_fa1 = racer->unk_180.z;
    var_fv1 = racer->unk_0C.unk_34.z - (sp128 * racer->unk_C0.y.z);
    racer->unk_180.z = var_fv1;
    racer->unk_18C.z = var_fv1 - var_fa1;

    racer->unk_80.x = racer->unk_0C.unk_34.x - sp10C.x;
    racer->unk_80.y = racer->unk_0C.unk_34.y - sp10C.y;
    racer->unk_80.z = racer->unk_0C.unk_34.z - sp10C.z;

    racer->unk_68.x = (spE8.z.x * racer->unk_80.x) + (spE8.z.y * racer->unk_80.y) + (spE8.z.z * racer->unk_80.z);
    racer->unk_68.y = (spE8.y.x * racer->unk_80.x) + (spE8.y.y * racer->unk_80.y) + (spE8.y.z * racer->unk_80.z);
    racer->unk_68.z = (spE8.x.x * racer->unk_80.x) + (spE8.x.y * racer->unk_80.y) + (spE8.x.z * racer->unk_80.z);
    racer->unk_5C.x = (racer->unk_C0.z.x * racer->velocity.x) + (racer->unk_C0.z.y * racer->velocity.y) +
                     (racer->unk_C0.z.z * racer->velocity.z);
    racer->unk_5C.y = (racer->unk_C0.y.x * racer->velocity.x) + (racer->unk_C0.y.y * racer->velocity.y) +
                     (racer->unk_C0.y.z * racer->velocity.z);
    racer->unk_5C.z = (racer->unk_C0.x.x * racer->velocity.x) + (racer->unk_C0.x.y * racer->velocity.y) +
                     (racer->unk_C0.x.z * racer->velocity.z);
    if ((racer->id < gNumPlayers) && (controller->unk_74 != 0)) {

        if (!(racer->stateFlags & (RACER_STATE_FLAGS_40000 | RACER_STATE_FLAGS_4000))) {
            if (racer->stateFlags & RACER_STATE_FLAGS_20000) {
                if (D_800E5F20[racer->id] == 0) {
                    D_800E5F20[racer->id] = 1;
                    controller->unk_88 = 4000;
                    controller->unk_8C = 0;
                    controller->unk_90 = 0;
                    goto skip;
                }
            } else {
                if (D_800E5F20[racer->id] != 0) {
                    D_800E5F20[racer->id]--;
                }
                if (racer->boostTimer == sInitialBoostTimer - 1) {
                    controller->unk_88 = 1000;
                    controller->unk_8C = controller->unk_90 = 0;
                    goto skip;
                } else if (racer->boostTimer != 0) {
                    controller->unk_8C = (racer->boostTimer * 300) / sInitialBoostTimer;
                    goto skip;
                }
            }

            if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_DIRT) {
                if (D_800E5F30[racer->id] == 0) {
                    D_800E5F30[racer->id] = 150;
                    controller->unk_88 = 2000;
                    controller->unk_8C = 300;
                    controller->unk_90 = 1;
                    goto skip;
                } else if (D_800E5F30[racer->id] >= 2) {
                    D_800E5F30[racer->id]--;
                    goto skip;
                }
            } else {
                D_800E5F30[racer->id] = 0;
            }

            var_ft4 = racer->unk_80.x;
            var_fs0 = racer->unk_80.y;
            var_fs1 = racer->unk_80.z;
            i = (s32) (sqrtf(SQ(var_ft4) + SQ(var_fs0) + SQ(var_fs1)) * D_800CE754);
            if (i > 1000) {
                i = 1000;
            }
            controller->unk_8C = i;
            controller->unk_90 = 0;
        skip:;
        }
    }

    if ((racer->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_4000000 | RACER_STATE_FLAGS_4000 | COURSE_EFFECT_MASK)) == COURSE_EFFECT_PIT) {
        racer->energy += racer->energyIncrease;
        if (racer->maxEnergy < racer->energy) {
            racer->energy = racer->maxEnergy;
        }

        if (racer->unk_224 < 1.0f) {
            racer->unk_224 += 0.1f;
            if (racer->unk_224 >= 1.0f) {
                racer->unk_224 = 1.0f;
            } else if ((racer->id < gNumPlayers) && (racer->unk_224 == 0.1f)) {
                racer->unk_08 |= 0x800;
                if (D_800E5FD0 != 0) {
                    func_800BA2F0(racer->id, 4);
                }
            }
        }
    } else {
        if (racer->unk_224 > 0.0f) {
            racer->unk_224 -= 0.1f;
            if (racer->unk_224 <= 0.0f) {
                racer->unk_224 = 0.0f;
                if (racer->id < gNumPlayers) {
                    racer->unk_08 &= ~0x800;
                    if (D_800E5FD0 != 0) {
                        func_800BA3E4(racer->id, 4);
                    }
                }
            }
        }
    }
    racer->unk_210 = (racer->unk_210 + (s32) (racer->unk_1D4 * 4000.0f)) & 0xFFF;

    var_fa1 = SIN(racer->unk_210) * (racer->speed * 0.007f);
    if (racer->unk_08 & 0x400) {
        var_fa1 *= 5.0f;
    }
    racer->unk_10C.x = racer->unk_0C.unk_34.x + (var_fa1 * racer->unk_E8.y.x);
    racer->unk_10C.y = racer->unk_0C.unk_34.y + (var_fa1 * racer->unk_E8.y.y);
    racer->unk_10C.z = racer->unk_0C.unk_34.z + (var_fa1 * racer->unk_E8.y.z);
    if (racer->unk_21C != 0) {
        racer->unk_10C.x += ((f32) (Math_Rand1() & 0xFFFF) * 0.000027466238f) - 0.9f;
        racer->unk_10C.y += ((f32) (Math_Rand1() & 0xFFFF) * 0.000027466238f) - 0.9f;
        racer->unk_10C.z += ((f32) (Math_Rand2() & 0xFFFF) * 0.000027466238f) - 0.9f;
    }

    if (racer->unk_27C != 0) {
        if (racer->unk_284 == 1) {
            racer->unk_E8.x.x = racer->unk_C0.x.x;
            racer->unk_E8.x.y = racer->unk_C0.x.y;
            racer->unk_E8.x.z = racer->unk_C0.x.z;
        } else {
            var_fs1 = COS(racer->unk_27C);
            var_fs0 = SIN(racer->unk_27C);
            racer->unk_E8.x.x = (racer->unk_C0.x.x * var_fs1) + (var_fs0 * racer->unk_C0.z.x);
            racer->unk_E8.x.y = (racer->unk_C0.x.y * var_fs1) + (var_fs0 * racer->unk_C0.z.y);
            racer->unk_E8.x.z = (racer->unk_C0.x.z * var_fs1) + (var_fs0 * racer->unk_C0.z.z);
        }

        if (racer->unk_284 == 1) {
            racer->unk_27C += racer->unk_280;
            if ((racer->unk_27C == -0x80) || (racer->unk_27C == 0x1080)) {
                racer->unk_204 = 0x1E;
                racer->unk_27C = 0;
                racer->unk_284 = 0;
            }
        } else {
            racer->unk_27C += racer->unk_280;
            if (racer->unk_280 < 0) {
                racer->unk_280 += 2;
                if (racer->unk_27C <= 0) {
                    racer->unk_27C += 0x1000;
                    if (racer->unk_280 >= -0x31) {
                        racer->unk_27C = 0;
                        racer->unk_284 = 0;
                    } else if (D_800E5FD0 != 0) {
                        func_800BA710(racer->id, 2);
                    }
                }
            } else {
                racer->unk_280 -= 2;
                if (racer->unk_27C >= 0x1000) {
                    racer->unk_27C -= 0x1000;
                    if (racer->unk_280 < 0x32) {
                        racer->unk_27C = 0;
                        racer->unk_284 = 0;
                    } else if (D_800E5FD0 != 0) {
                        func_800BA710(racer->id, 2);
                    }
                }
            }
        }
    } else {
        racer->unk_E8.x.x = racer->unk_C0.x.x;
        racer->unk_E8.x.y = racer->unk_C0.x.y;
        racer->unk_E8.x.z = racer->unk_C0.x.z;
        if (gGameMode == GAMEMODE_GP_END_CS) {
            racer->unk_10C.x += (var_fs1 = racer->unk_A4 * racer->unk_C0.y.x);
            racer->unk_10C.y += (var_fs0 = racer->unk_A4 * racer->unk_C0.y.y);
            racer->unk_10C.z += (var_ft4 = racer->unk_A4 * racer->unk_C0.y.z);
            racer->unk_168.x += var_fs1;
            racer->unk_168.y += var_fs0;
            racer->unk_168.z += var_ft4;
        }
    }
    var_fa1 = racer->unk_68.x * 0.6f;

    racer->unk_E8.y.x += 0.19f * (racer->unk_C0.y.x + (var_fa1 * racer->unk_C0.z.x));
    racer->unk_E8.y.y += 0.19f * (racer->unk_C0.y.y + (var_fa1 * racer->unk_C0.z.y));
    racer->unk_E8.y.z += 0.19f * (racer->unk_C0.y.z + (var_fa1 * racer->unk_C0.z.z));

    racer->unk_E8.z.x = (racer->unk_E8.y.y * racer->unk_E8.x.z) - (racer->unk_E8.y.z * racer->unk_E8.x.y);
    racer->unk_E8.z.y = (racer->unk_E8.y.z * racer->unk_E8.x.x) - (racer->unk_E8.y.x * racer->unk_E8.x.z);
    racer->unk_E8.z.z = (racer->unk_E8.y.x * racer->unk_E8.x.y) - (racer->unk_E8.y.y * racer->unk_E8.x.x);

    temp_fa0 = 1.0f / sqrtf(SQ(racer->unk_E8.z.x) + SQ(racer->unk_E8.z.y) + SQ(racer->unk_E8.z.z));

    racer->unk_E8.z.x *= temp_fa0;
    racer->unk_E8.z.y *= temp_fa0;
    racer->unk_E8.z.z *= temp_fa0;

    racer->unk_E8.y.x = (racer->unk_E8.x.y * racer->unk_E8.z.z) - (racer->unk_E8.x.z * racer->unk_E8.z.y);
    racer->unk_E8.y.y = (racer->unk_E8.x.z * racer->unk_E8.z.x) - (racer->unk_E8.x.x * racer->unk_E8.z.z);
    racer->unk_E8.y.z = (racer->unk_E8.x.x * racer->unk_E8.z.y) - (racer->unk_E8.x.y * racer->unk_E8.z.x);
    if (racer->stateFlags & RACER_STATE_FLAGS_2000) {
        racer->unk_E8.y.x += racer->unk_118.x *= 0.8f;
        racer->unk_E8.y.y += racer->unk_118.y *= 0.8f;
        racer->unk_E8.y.z += racer->unk_118.z *= 0.8f;

        var_fa1 = 1.0f / sqrtf(SQ(racer->unk_E8.y.x) + SQ(racer->unk_E8.y.y) + SQ(racer->unk_E8.y.z));
        if (var_fa1 > 0.99f) {
            racer->stateFlags &= ~RACER_STATE_FLAGS_2000;
        }

        racer->unk_E8.y.x *= var_fa1;
        racer->unk_E8.y.y *= var_fa1;
        racer->unk_E8.y.z *= var_fa1;

        racer->unk_E8.z.x = (racer->unk_E8.y.y * racer->unk_E8.x.z) - (racer->unk_E8.y.z * racer->unk_E8.x.y);
        racer->unk_E8.z.y = (racer->unk_E8.y.z * racer->unk_E8.x.x) - (racer->unk_E8.y.x * racer->unk_E8.x.z);
        racer->unk_E8.z.z = (racer->unk_E8.y.x * racer->unk_E8.x.y) - (racer->unk_E8.y.y * racer->unk_E8.x.x);

        temp_fa0 = 1.0f / sqrtf(SQ(racer->unk_E8.z.x) + SQ(racer->unk_E8.z.y) + SQ(racer->unk_E8.z.z));

        racer->unk_E8.z.x *= temp_fa0;
        racer->unk_E8.z.y *= temp_fa0;
        racer->unk_E8.z.z *= temp_fa0;

        racer->unk_E8.x.x = (racer->unk_E8.z.y * racer->unk_E8.y.z) - (racer->unk_E8.z.z * racer->unk_E8.y.y);
        racer->unk_E8.x.y = (racer->unk_E8.z.z * racer->unk_E8.y.x) - (racer->unk_E8.z.x * racer->unk_E8.y.z);
        racer->unk_E8.x.z = (racer->unk_E8.z.x * racer->unk_E8.y.y) - (racer->unk_E8.z.y * racer->unk_E8.y.x);
    }

    if (racer->unk_220 != 0) {
        racer->unk_220--;
    }
    if (racer->unk_21C != 0) {
        if (!((racer->id + gGameFrameCount) & 3) && (racer->unk_2B4 != 0)) {
            sp10C.x = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->unk_0C.unk_34.x;
            sp10C.y = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->unk_0C.unk_34.y;
            sp10C.z = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->unk_0C.unk_34.z;
            func_i2_80105590(sp10C.x, sp10C.y, sp10C.z, racer->velocity.x, racer->velocity.y, racer->velocity.z,
                             (f32) ((Math_Rand2() & 0xF) + ((s32) (racer->unk_21C * 5) / 150) + 5), racer);
            if (!((racer->id + gGameFrameCount) & 4) && (D_800E5FD0 != 0)) {
                func_800BA710(racer->id, 5);
            }
            if (racer->id < gNumPlayers) {
                controller->unk_88 = 0xBB8;
                controller->unk_8C = 0;
                controller->unk_90 = 0;
            }

            for (i = 2; i > 0; i--) {
                var_fs1 = ((f32) (Math_Rand2() & 0x1FFFF) * 0.000068665075f) - 4.5f;
                var_fs0 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.000038147264f) + 2.0f;
                var_ft4 = ((f32) (Math_Rand2() & 0x1FFFF) * 0.000068665075f) - 4.5f;
                func_i2_80105700(sp10C.x, sp10C.y, sp10C.z,
                                 racer->velocity.x + (var_fs1 * racer->unk_C0.z.x) + (var_fs0 * racer->unk_C0.y.x) +
                                     (var_ft4 * racer->unk_C0.x.x),
                                 racer->velocity.y + (var_fs1 * racer->unk_C0.z.y) + (var_fs0 * racer->unk_C0.y.y) +
                                     (var_ft4 * racer->unk_C0.x.y),
                                 racer->velocity.z + (var_fs1 * racer->unk_C0.z.z) + (var_fs0 * racer->unk_C0.y.z) +
                                     (var_ft4 * racer->unk_C0.x.z),
                                 racer);
            }
        }

        racer->unk_21C++;
        if (racer->unk_21C > 150) {

            racer->stateFlags &= ~RACER_STATE_FLAGS_4000;
            racer->unk_21C = 0;
            racer->stateFlags |= RACER_STATE_FLAGS_8000000;
            racer->unk_17C = 10.0f;
            D_800E5FBE++;
            func_800892E0(racer);
            if (racer->unk_2B4 != 0) {
                func_i2_80105648(racer->unk_0C.unk_34.x, racer->unk_0C.unk_34.y, racer->unk_0C.unk_34.z, racer->velocity.x,
                                 racer->velocity.y, racer->velocity.z, 80.0f, racer);
                if (racer->id < gNumPlayers) {
                    i = 60;
                } else {
                    i = 30;
                }
                sp13C = racer->unk_2E0;
                sp138 = racer->unk_2E4;
                sp134 = racer->unk_2E8;
                do {
                    var_fs1 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.00011444179f) - 7.5f;
                    var_fs0 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.00005340617f) + 3.5f;
                    var_ft4 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.00011444179f) - 7.5f;
                    func_i2_80105A28((s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->unk_0C.unk_34.x,
                                     (s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->unk_0C.unk_34.y,
                                     (s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->unk_0C.unk_34.z,
                                     racer->velocity.x + (var_fs1 * racer->unk_C0.z.x) + (var_fs0 * racer->unk_C0.y.x) +
                                         (var_ft4 * racer->unk_C0.x.x),
                                     racer->velocity.y + (var_fs1 * racer->unk_C0.z.y) + (var_fs0 * racer->unk_C0.y.y) +
                                         (var_ft4 * racer->unk_C0.x.y),
                                     racer->velocity.z + (var_fs1 * racer->unk_C0.z.z) + (var_fs0 * racer->unk_C0.y.z) +
                                         (var_ft4 * racer->unk_C0.x.z),
                                     &racer->unk_C0, sp13C, sp138, sp134, racer);
                    i--;
                } while (i != 0);
                if (D_800E5FD0 != 0) {
                    func_800BA710(racer->id, 8);
                }
                if (racer->id < gNumPlayers) {
                    controller->unk_88 = 10000;
                    controller->unk_8C = 500;
                    controller->unk_90 = 5;
                }
            }
        }
    }
    if (!(racer->stateFlags & RACER_STATE_FLAGS_8000000)) {
        var_fa1 = racer->energy / racer->maxEnergy;
        if ((racer->id < gNumPlayers) && (var_fa1 < 0.3f) && (racer->unk_21C == 0) && (D_800E5FD0 != 0)) {
            if (var_fa1 >= 0.2f) {
                if (!(gGameFrameCount & 0x1F)) {
                    func_800BA710(racer->id, 0x13);
                }
            } else if (var_fa1 >= 0.1f) {
                if (!(gGameFrameCount & 0xF)) {
                    func_800BA710(racer->id, 0x14);
                }
            } else if (!(gGameFrameCount & 7)) {
                func_800BA710(racer->id, 0x15);
            }
        }
        if (!(gGameFrameCount & 8) && ((var_fa1 < 0.2f) || ((var_fa1 < 0.5f) && !(gGameFrameCount & 0x10)))) {
            var_fa1 *= 2;
            var_fs1 = (racer->unk_2F8 * var_fa1) + racer->unk_2EC;
            var_fs0 = (racer->unk_2FC * var_fa1) + racer->unk_2F0;
            var_ft4 = (racer->unk_300 * var_fa1) + racer->unk_2F4;
            var_fa1 = (f32) ((u32) gGameFrameCount & 7) / 7.0f;
            var_fs1 += ((racer->unk_2E0 - var_fs1) * var_fa1);
            var_fs0 += ((racer->unk_2E4 - var_fs0) * var_fa1);
            var_ft4 += ((racer->unk_2E8 - var_ft4) * var_fa1);
        } else {
            var_fs1 = racer->unk_2E0;
            var_fs0 = racer->unk_2E4;
            var_ft4 = racer->unk_2E8;
        }

        var_fa1 = racer->unk_220 / 5.0f;
        racer->unk_2CE = ((255.0f - var_fs1) * var_fa1) + var_fs1;
        racer->unk_2D0 = ((255.0f - var_fs0) * var_fa1) + var_fs0;
        racer->unk_2D2 = ((255.0f - var_ft4) * var_fa1) + var_ft4;
        if (racer->unk_284 == 2) {
            var_fa1 = SIN(racer->unk_27C & 0x7FF);
            racer->unk_178 = (0.1f * var_fa1) + 1.05f;
            racer->unk_2DA = 0xFF;
            racer->unk_2DC = 0xFF - (s32) (255.0f * var_fa1);
            racer->unk_2DE = 0;
        } else if (racer->unk_284 == 1) {
            racer->unk_178 = 1.075f;
            racer->unk_2DA = 0xFF;
            racer->unk_2DC = 0;
            racer->unk_2DE = 0;
        } else {
            racer->unk_178 = 0.0f;
        }
    } else {
        racer->unk_2CE = racer->unk_2E0;
        racer->unk_2D0 = racer->unk_2E4;
        racer->unk_2D2 = racer->unk_2E8;
        if (((Math_Rand1() & 0x1FFFF) < 0x444) && (racer->unk_2B4 != 0)) {
            var_fs1 = (((f32) (Math_Rand1() & 0x1FFFF) / 131071.0f) * 3.0f) - 1.5f;
            var_fs0 = (((f32) (Math_Rand2() & 0x1FFFF) / 131071.0f) * 1.5f) + 0.5f;
            var_ft4 = (((f32) (Math_Rand2() & 0x1FFFF) / 131071.0f) * 3.0f) - 1.5f;
            sp10C.x = (s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->unk_0C.unk_34.x;
            sp10C.y = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->unk_0C.unk_34.y;
            sp10C.z = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->unk_0C.unk_34.z;

            func_i2_801054C0(sp10C.x, sp10C.y, sp10C.z,
                             racer->velocity.x + (var_fs1 * racer->unk_C0.z.x) + (var_fs0 * racer->unk_C0.y.x) +
                                 (var_ft4 * racer->unk_C0.x.x),
                             racer->velocity.y + (var_fs1 * racer->unk_C0.z.y) + (var_fs0 * racer->unk_C0.y.y) +
                                 (var_ft4 * racer->unk_C0.x.y),
                             racer->velocity.z + (var_fs1 * racer->unk_C0.z.z) + (var_fs0 * racer->unk_C0.y.z) +
                                 (var_ft4 * racer->unk_C0.x.z),
                             10.0f, racer);
            func_i2_801058FC(sp10C.x, sp10C.y, sp10C.z, racer->velocity.x + racer->unk_B4.x,
                             racer->velocity.y + racer->unk_B4.y, racer->velocity.z + racer->unk_B4.z, 20.0f, racer);

            if (racer->id < gNumPlayers) {
                func_800BA710(racer->id, 0x32);
            }
            racer->unk_178 = 1.03f;
            racer->unk_2DA = racer->unk_2DC = 0xFF;
            racer->unk_2DE = 0;
        } else {
            racer->unk_178 = 0.0f;
        }
    }

    if (!(racer->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_8000))) {
        racer->unk_17C += ((13.0f - racer->unk_17C) * 0.05f);
        if (racer->unk_17C > 13.0f) {
            racer->unk_17C = 13.0f;
            racer->stateFlags |= RACER_STATE_FLAGS_8000;
        }
    } else if ((D_800F80A4 == racer->unk_17C) && (controller->buttonCurrent != 0) && (D_800F5E98 < 250)) {
        racer->stateFlags &= ~RACER_STATE_FLAGS_8000;
        racer->shadowColorStrength = 1.3f;
        racer->shadowBaseR = 0.0f;
        racer->shadowBaseG = 205.0f;
        racer->shadowBaseB = 255.0f;
        if (racer->id < gNumPlayers) {
            func_800BA710(racer->id, 0x28);
        }
    }

    if (racer->shadowColorStrength != 1.0f) {
        var_fa1 = (racer->shadowColorStrength - 1.0f) / 0.29999995f;
        var_fa1 *= var_fa1;
        racer->shadowR = racer->shadowBaseR * var_fa1;
        racer->shadowG = racer->shadowBaseG * var_fa1;
        racer->shadowB = racer->shadowBaseB * var_fa1;
        racer->shadowColorStrength -= 0.003f;
        if (racer->shadowColorStrength < 1.f) {
            racer->shadowColorStrength = 1.0f;
        }
    } else {
        racer->shadowR = racer->shadowG = racer->shadowB = 0;
    }
    if (racer->id < gNumPlayers) {
        if ((racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_FLAG_20000000) && !(racer->stateFlags & RACER_STATE_FLAGS_80000000)) {
            if (!(racer->unk_08 & 0x100)) {
                racer->unk_08 |= 0x100;
                if (D_800E5FD0 != 0) {
                    func_800BAB34(racer->id);
                }
            }
        } else {

            if (racer->unk_08 & 0x100) {
                racer->unk_08 &= ~0x100;
                if (D_800E5FD0 != 0) {
                    func_800BAB50(racer->id);
                }
            }
        }
    }
}
#else
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/game/1B0E0/func_80090BCC.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80090BCC.s")
#endif
#endif

void func_80094FF4(s32 position) {
    if (!(position > -0x80 && position < 0x80)) {
        sGhostReplayRecordingSize += 3;
        if (sGhostReplayRecordingSize <= 16200) {
            *sGhostReplayRecordingPtr++ = -0x80;
            *sGhostReplayRecordingPtr++ = ((position & 0xFFFF) >> 8);
            *sGhostReplayRecordingPtr++ = position & 0xFF;
        } else {
            sGhostReplayRecordingSize -= 3;
            D_800F5DE6 = 1;
            D_800F5DE4 = 0;
        }
    } else {
        sGhostReplayRecordingSize++;
        if (sGhostReplayRecordingSize <= 16200) {
            *sGhostReplayRecordingPtr++ = position;
        } else {
            sGhostReplayRecordingSize--;
            D_800F5DE6 = 1;
            D_800F5DE4 = 0;
        }
    }
}

s32 func_800950E8(GhostRacer* arg0) {
    s32 temp1 = *arg0->replayPtr++;

    if (temp1 == -0x80) {
        temp1 = *arg0->replayPtr++;
        temp1 <<= 8;
        temp1 |= (u8) *arg0->replayPtr++;
        arg0->replayIndex += 3;
    } else {
        arg0->replayIndex++;
    }

    return temp1;
}

void func_80095144(void) {
    s32 i;

    for (i = 0; i < gNumPlayers; i++) {
        gControllers[gPlayerControlPorts[i]].unk_72 = 0;
    }

    if (D_800F80C4 == 1) {
        func_80089220(0);
    } else if (D_800F80C4 == -1) {
        func_8008927C(0);
    }
}

void func_80090BCC(Racer*, Controller*);
void func_i3_80117BF0(Racer*, Controller*);

void func_800951DC(Racer* arg0) {
    Controller sp24;
    f32 sp20;

    if (arg0->stateFlags & RACER_STATE_FLAGS_800000) {
        sp20 = arg0->energy;
        func_i3_80117BF0(arg0, &sp24);
        if (sp20 < arg0->energy) {
            arg0->energy = sp20;
        }
        if ((D_800F5E98 > 40) && (arg0->unk_2A4 != 0)) {
            sp24.buttonCurrent = 0;
            if (D_800F5E98 < 250) {
                arg0->unk_2A4--;
            }
        }
        func_80090BCC(arg0, &sp24);
    } else {
        func_80090BCC(arg0, &gControllers[gPlayerControlPorts[arg0->id]]);
        arg0->unk_33C = -arg0->unk_0C.unk_28.x * arg0->unk_24C.xz - arg0->unk_0C.unk_28.y * arg0->unk_24C.yz -
                        arg0->unk_0C.unk_28.z * arg0->unk_24C.zz;
    }
}

#ifdef NON_MATCHING
// float regalloc https://decomp.me/scratch/eSbNu
void func_800952F4(void) {
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 sp128;
    f32 temp_fv1_3;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fs0;
    f32 var_fs1;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 var_fs2;
    f32 var_ft4;
    s32 posDiff;
    GhostRacer* var_s0;
    unk_800F5EA0* temp_s2;
    s32 i;
    Mtx3F spCC;
    Racer* racer;
    Racer* racer2;
    unk_struct_1DC* var_s1_2;

    D_800E5FD8++;
    if (D_800F5E98 != 0) {
        if (D_800DCE5C == 0) {
            if (D_800F5E98 == 460) {
                func_8007E08C();
                if (D_800CD010 == 0) {
                    func_800BB018();
                }
                for (i = 0; i < gNumPlayers; i++) {
                    func_800BAE5C(i);
                }
            }

            D_800F5E98--;
            if (D_800F5E98 == 40) {
                for (racer = D_800E5EC4; racer >= gRacers; racer--) {
                    racer->stateFlags |= RACER_STATE_FLAGS_400000;
                }
            } else if ((D_800F5E98 == 255) && (gGameMode == GAMEMODE_TIME_ATTACK)) {
                D_800F5DE4 = 1;
                D_800F5DD0 = 0;
                D_800F5DD8 = Math_Round(gRacers[0].unk_0C.unk_34.x);
                D_800F5DDC = Math_Round(gRacers[0].unk_0C.unk_34.y);
                D_800F5DE0 = Math_Round(gRacers[0].unk_0C.unk_34.z);

                for (var_s0 = &gGhostRacers[2]; var_s0 >= gGhostRacers; var_s0--) {
                    if (var_s0->exists) {
                        var_s0->initialized = true;
                        var_s0->frameCount= 0;
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosX = posDiff + D_800F5DD8;
                        var_s0->pos.x = gRacers[0].unk_0C.unk_34.x + (posDiff * 0.5f);
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosY = posDiff + D_800F5DDC;
                        var_s0->pos.y = gRacers[0].unk_0C.unk_34.y + (posDiff * 0.5f);
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosZ = posDiff + D_800F5DE0;
                        var_s0->pos.z = gRacers[0].unk_0C.unk_34.z + (posDiff * 0.5f);
                    }
                }
            }
        }

        for (i = gNumPlayers - 1; i >= 0; i--) {
            racer2 = &gRacers[i];
            var_s1_2 = &D_800E5220[i];
            spCC.x.x = -var_s1_2->unk_5C.x.x;
            spCC.x.y = -var_s1_2->unk_5C.x.y;
            spCC.x.z = -var_s1_2->unk_5C.x.z;
            spCC.y.x = racer2->unk_C0.y.x;
            spCC.y.y = racer2->unk_C0.y.y;
            spCC.y.z = racer2->unk_C0.y.z;
            func_8006AC10(&spCC);
            if (D_800F5E98 > 220) {
                var_fs0 = (D_800F5E98 - 220) / 240.0f;
            } else if (D_800F5E98 > 30) {
                var_fs0 = 0.0f;
            } else {
                var_fs0 = (30 - D_800F5E98) / 30.0f;
            }
            var_fs0 = (1500.0f * var_fs0 * var_fs0) + 33.0f;
            var_fs2 = var_fs0 - racer2->unk_A0;
            func_8006BC84(&D_800DCCF0->unk_21988[i], NULL, 0.2f, 0.2f, 0.2f, spCC.x.x, spCC.x.y, spCC.x.z, spCC.y.x,
                          spCC.y.y, spCC.y.z,
                          (racer2->unk_0C.unk_34.x + (var_fs2 * racer2->unk_C0.y.x) + (50.0f * racer2->unk_C0.x.x)) -
                              (var_fs0 * var_s1_2->unk_5C.x.x),
                          (racer2->unk_0C.unk_34.y + (var_fs2 * racer2->unk_C0.y.y) + (50.0f * racer2->unk_C0.x.y)) -
                              (var_fs0 * var_s1_2->unk_5C.x.y),
                          (racer2->unk_0C.unk_34.z + (var_fs2 * racer2->unk_C0.y.z) + (50.0f * racer2->unk_C0.x.z)) -
                              (var_fs0 * var_s1_2->unk_5C.x.z));
        }
    }

    if (D_800DCE5C != 0) {
        for (racer = D_800E5EC4; racer >= gRacers; racer--) {
            racer->unk_164 = racer->unk_165 = racer->unk_166 = 0;
        }
        gControllers[(gGameFrameCount & 3)].unk_78 = 1;
        return;
    }

    for (racer = D_800E5EC4; racer >= gRacers; racer--) {
        racer->unk_164 = racer->unk_165 = racer->unk_166 = 0;
        racer->stateFlags &= ~RACER_STATE_FLAGS_20000;
        racer->acceleration.x = racer->acceleration.y = racer->acceleration.z = 0.0f;
        if ((racer->unk_230 != 0.0f) && !(racer->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_4000))) {
            racer->energy += racer->unk_230;
            if (racer->maxEnergy < racer->energy) {
                racer->energy = racer->maxEnergy;
            }
            racer->unk_230 = 0.0f;
        }
    }

    if (gNumPlayers != 1) {
        for (racer = D_800E5EC4; racer >= gRacers; racer--) {
            racer->unk_2B4 = racer->unk_2B2 = racer->unk_2B3 = 1;
        }
    }
    if (D_800E5EC0 >= 2) {
        racer = D_800E5EC4;
        do {
            if (!(racer->stateFlags & RACER_STATE_FLAGS_40000000)) {
                continue;
            }

            i = (s32) (racer->id * (racer->id - 1)) >> 1;
            racer2 = racer - 1;
            do {
                if (racer2->stateFlags & RACER_STATE_FLAGS_40000000) {
                    temp_s2 = &D_800F5EA0[i + racer2->id];
                    if (temp_s2->unk_08 > 92.0f) {
                        temp_s2->unk_10 = 0;
                    } else {
                        sp110 = racer2->unk_0C.unk_34.x - racer->unk_0C.unk_34.x;
                        sp108 = racer2->unk_0C.unk_34.z - racer->unk_0C.unk_34.z;

                        if (SQ(sp110) + SQ(sp108) > 2116.f) {
                            temp_s2->unk_10 = 0;
                        } else {
                            sp10C = racer2->unk_0C.unk_34.y - racer->unk_0C.unk_34.y;
                            if ((SQ(sp110) + SQ(sp108) + SQ(sp10C)) > 2116.0f) {
                                temp_s2->unk_10 = 0;
                            } else {
                                sp128 = sqrtf((SQ(sp110) + SQ(sp108) + SQ(sp10C)));
                                if (racer->stateFlags & RACER_STATE_FLAGS_8000000) {
                                    var_fs2 = racer->unk_1F4 * 0.333f;
                                } else {
                                    var_fs2 = racer->unk_1F4;
                                }
                                if (racer2->stateFlags & RACER_STATE_FLAGS_8000000) {
                                    var_fs1 = racer2->unk_1F4 * 0.333f;
                                } else {
                                    var_fs1 = racer2->unk_1F4;
                                }
                                temp_fv1_3 = var_fs2 + var_fs1;
                                var_fs2 /= temp_fv1_3;
                                var_fs1 /= temp_fv1_3;
                                temp_fs3 = racer2->velocity.x - racer->velocity.x;
                                temp_fs4 = racer2->velocity.y - racer->velocity.y;
                                temp_fs5 = racer2->velocity.z - racer->velocity.z;
                                if (temp_s2->unk_10 == 0) {
                                    if (racer->id < gNumPlayers) {
                                        racer2->unk_288 = 0;
                                        racer2->unk_28C = racer;
                                    }
                                    if (racer2->id < gNumPlayers) {
                                        racer->unk_288 = 0;
                                        racer->unk_28C = racer2;
                                    }
                                    if (sp128 < 0.01f) {
                                        temp_fv1_3 = 1.0f / sqrtf(SQ(temp_fs3) + SQ(temp_fs4) + SQ(temp_fs5));
                                        var_fa0 = temp_fv1_3 * temp_fs3;
                                        var_fa1 = temp_fv1_3 * temp_fs4;
                                        var_ft4 = temp_fv1_3 * temp_fs5;
                                    } else {
                                        temp_fv1_3 = 1.0f / sp128;
                                        var_fa0 = temp_fv1_3 * sp110;
                                        var_fa1 = temp_fv1_3 * sp10C;
                                        var_ft4 = temp_fv1_3 * sp108;
                                    }
                                    var_fs0 = (var_fa0 * temp_fs3) + (var_fa1 * temp_fs4) + (var_ft4 * temp_fs5);

                                    if (var_fs0 < 0.0f) {
                                        var_fs0 = -var_fs0;
                                    }
                                    if ((racer2->unk_2B4 != 0) &&
                                        (func_i2_801054C0(((racer->unk_0C.unk_34.x + racer2->unk_0C.unk_34.x) * 0.5f) +
                                                              (6.0f * racer->unk_C0.y.x),
                                                          ((racer->unk_0C.unk_34.y + racer2->unk_0C.unk_34.y) * 0.5f) +
                                                              (6.0f * racer->unk_C0.y.y),
                                                          ((racer->unk_0C.unk_34.z + racer2->unk_0C.unk_34.z) * 0.5f) +
                                                              (6.0f * racer->unk_C0.y.z),
                                                          (racer->velocity.x + racer2->velocity.x) * 0.5f,
                                                          (racer->velocity.y + racer2->velocity.y) * 0.5f,
                                                          (racer->velocity.z + racer2->velocity.z) * 0.5f,
                                                          var_fs0 + 12.0f, racer2) == 0)) {
                                        racer->unk_220 = racer2->unk_220;
                                    }
                                    var_fs0 *= 1.1f;
                                    if (racer->unk_284 == 0) {
                                        if (racer2->unk_284 == 0) {
                                            func_8008DCD8(racer, var_fs1 * var_fs0);
                                            func_8008DCD8(racer2, var_fs2 * var_fs0);
                                        } else if ((racer2 == gRacers) && (gNumPlayers == 1)) {
                                            func_8008DCD8(racer, var_fs0 * 10.0f);
                                        } else {
                                            func_8008DCD8(racer, var_fs0);
                                        }
                                    } else if (racer2->unk_284 == 0) {
                                        func_8008DCD8(racer2, var_fs0);
                                    } else {
                                        func_8008DCD8(racer, var_fs1 * var_fs0);
                                        func_8008DCD8(racer2, var_fs2 * var_fs0);
                                    }
                                    if (D_800E5FD0 != 0) {
                                        func_800BA710(racer2->id, 4);
                                    }
                                }
                                temp_s2->unk_10 = 1;
                                if (((sp110 * temp_fs3) + (sp10C * temp_fs4) + (sp108 * temp_fs5)) <= 0.0f) {
                                    if (sp128 < 0.01f) {
                                        temp_fv1_3 = -46.0f / sqrtf(SQ(temp_fs3) + SQ(temp_fs4) + SQ(temp_fs5));
                                        var_fa0 = temp_fv1_3 * temp_fs3;
                                        var_fa1 = temp_fv1_3 * temp_fs4;
                                        var_ft4 = temp_fv1_3 * temp_fs5;
                                    } else {
                                        if ((racer->unk_284 | racer2->unk_284) != 0) {
                                            var_fs0 = 46.0f - sp128;
                                            if (var_fs0 < 3) {
                                                var_fs0 = 3;
                                            }
                                            var_fs0 /= sp128;
                                        } else {
                                            var_fs0 = 46.0f - sp128;
                                            var_fs0 /= sp128;
                                        }
                                        var_fa0 = var_fs0 * sp110;
                                        var_fa1 = var_fs0 * sp10C;
                                        var_ft4 = var_fs0 * sp108;
                                    }
                                    if (racer->unk_284 != 0) {
                                        if (racer2->unk_284 == 0) {
                                            var_fs2 = 3.0f;
                                            var_fs1 = 0.0f;
                                            racer2->unk_208 = 0x3C;
                                        }
                                    } else if (racer2->unk_284 != 0) {
                                        var_fs2 = 0.0f;
                                        var_fs1 = 3.0f;
                                        racer->unk_208 = 0x3C;
                                    }
                                    racer->acceleration.x -= var_fs1 * var_fa0;
                                    racer->acceleration.y -= var_fs1 * var_fa1;
                                    racer->acceleration.z -= var_fs1 * var_ft4;
                                    racer->unk_118.x = (-0.15f * var_fs1) * var_fa0;
                                    racer->unk_118.y = (-0.15f * var_fs1) * var_fa1;
                                    racer->unk_118.z = (-0.15f * var_fs1) * var_ft4;
                                    racer->stateFlags |= RACER_STATE_FLAGS_2000;
                                    racer2->acceleration.x += var_fs2 * var_fa0;
                                    racer2->acceleration.y += var_fs2 * var_fa1;
                                    racer2->acceleration.z += var_fs2 * var_ft4;
                                    racer2->unk_118.x = (0.15f * var_fs2) * var_fa0;
                                    racer2->unk_118.y = (0.15f * var_fs2) * var_fa1;
                                    racer2->unk_118.z = (0.15f * var_fs2) * var_ft4;
                                    racer2->stateFlags |= RACER_STATE_FLAGS_2000;
                                }
                            }
                        }
                    }
                }
            } while (--racer2 >= gRacers);
        } while (--racer > gRacers);
    }
    for (racer = D_800E5EC4; racer >= gRacers; racer--) {
        if (racer->stateFlags & RACER_STATE_FLAGS_40000000) {
            func_800951DC(racer);
        }
    }

    for (i = 0; i < gNumPlayers; i++) {
        racer2 = &gRacers[i];
        if ((racer2->maxSpeed < racer2->speed) && !(racer2->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_4000000 | RACER_STATE_FLAGS_2000000 | RACER_STATE_FLAGS_80000)) && (D_800F80A8[i] == 0)) {
            racer2->maxSpeed = racer2->speed;
        }
    }

    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        D_800F5DD0++;
        if ((D_800F5DE4 != 0) && !(D_800F5DD0 & 1)) {
            i = Math_Round(gRacers[0].unk_0C.unk_34.x);
            func_80094FF4(i - D_800F5DD8);
            D_800F5DD8 = i;
            i = Math_Round(gRacers[0].unk_0C.unk_34.y);
            func_80094FF4(i - D_800F5DDC);
            D_800F5DDC = i;
            i = Math_Round(gRacers[0].unk_0C.unk_34.z);
            func_80094FF4(i - D_800F5DE0);
            D_800F5DE0 = i;
            if ((D_800F5DE8 != 0) && (D_800F5DE6 == 0) && (D_800F5DEA == 0)) {
                D_800F5DEA = 1;
                sGhostReplayRecordingEnd = sGhostReplayRecordingSize;
            }
        }
        for (var_s0 = &gGhostRacers[2]; var_s0 >= gGhostRacers; var_s0--) {
            if ((var_s0->exists) && (var_s0->initialized)) {
                racer = var_s0->racer;
                sp110 = racer->unk_10C.x + racer->velocity.x;
                sp10C = racer->unk_10C.y + racer->velocity.y;
                sp108 = racer->unk_10C.z + racer->velocity.z;
                racer->velocity.x = var_s0->pos.x - racer->unk_10C.x;
                racer->velocity.y = var_s0->pos.y - racer->unk_10C.y;
                racer->velocity.z = var_s0->pos.z - racer->unk_10C.z;
                racer->unk_10C = var_s0->pos;

                if (func_8009EBEC(&racer->unk_0C, racer->unk_10C.x, racer->unk_10C.y, racer->unk_10C.z, 100, 1.0f) !=
                    0) {
                    var_s0->exists = var_s0->initialized = false;
                } else {
                    racer->unk_0C.unk_08 =
                        func_8009E108(racer->unk_0C.courseSegment, racer->unk_0C.unk_04, &racer->unk_244);

                    func_8009E85C(racer->unk_0C.courseSegment, racer->unk_0C.unk_04, &racer->unk_24C,
                                  racer->unk_0C.unk_08);
                    racer->unk_270 = (racer->unk_0C.unk_08 * (racer->unk_0C.courseSegment->next->radiusLeft -
                                                              racer->unk_0C.courseSegment->radiusLeft)) +
                                     racer->unk_0C.courseSegment->radiusLeft;
                    racer->unk_274 = (racer->unk_0C.unk_08 * (racer->unk_0C.courseSegment->next->radiusRight -
                                                              racer->unk_0C.courseSegment->radiusRight)) +
                                     racer->unk_0C.courseSegment->radiusRight;
                    D_800CF4B8[TRACK_SHAPE_INDEX((u32) racer->unk_0C.courseSegment->trackSegmentInfo &
                                                 TRACK_SHAPE_MASK)](racer);

                    var_s0->frameCount++;
                    if (var_s0->frameCount & 1) {
                        var_s0->pos.x = var_s0->replayPosX;
                        var_s0->pos.y = var_s0->replayPosY;
                        var_s0->pos.z = var_s0->replayPosZ;
                        if (var_s0->replayIndex >= var_s0->ghost->replaySize) {
                            var_s0->exists = var_s0->initialized = false;
                        }
                    } else {
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosX += posDiff;
                        var_s0->pos.x += (posDiff * 0.5f);
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosY += posDiff;
                        var_s0->pos.y += (posDiff * 0.5f);
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosZ += posDiff;
                        var_s0->pos.z += (posDiff * 0.5f);
                    }

                    racer->speed = sqrtf(SQ(racer->velocity.x) + SQ(racer->velocity.y) + SQ(racer->velocity.z));

                    spCC = racer->unk_C0;
                    if (racer->speed > 1.0f) {
                        racer->unk_C0.x.x = var_s0->pos.x - racer->unk_10C.x;
                        racer->unk_C0.x.y = var_s0->pos.y - racer->unk_10C.y;
                        racer->unk_C0.x.z = var_s0->pos.z - racer->unk_10C.z;
                    }
                    racer->unk_C0.y.x += 0.19f * racer->unk_B4.x;
                    racer->unk_C0.y.y += 0.19f * racer->unk_B4.y;
                    racer->unk_C0.y.z += 0.19f * racer->unk_B4.z;
                    if (func_8006AC10(&racer->unk_C0) != 0) {
                        racer->unk_C0 = spCC;
                    }

                    racer->unk_80.x = racer->unk_10C.x - sp110;
                    racer->unk_80.y = racer->unk_10C.y - sp10C;
                    racer->unk_80.z = racer->unk_10C.z - sp108;
                    var_fs0 = racer->unk_68.x;
                    racer->unk_68.x = ((spCC.z.x * (racer->unk_80.x)) + (spCC.z.y * racer->unk_80.y) +
                                       (spCC.z.z * racer->unk_80.z) + var_fs0) *
                                      0.5f;
                    racer->unk_68.y =
                        (spCC.y.x * (racer->unk_80.x)) + (spCC.y.y * racer->unk_80.y) + (spCC.y.z * racer->unk_80.z);
                    racer->unk_68.z =
                        (spCC.x.x * (racer->unk_80.x)) + (spCC.x.y * racer->unk_80.y) + (spCC.x.z * racer->unk_80.z);
                    racer->unk_5C.x = (racer->unk_C0.z.x * racer->velocity.x) +
                                      (racer->unk_C0.z.y * racer->velocity.y) + (racer->unk_C0.z.z * racer->velocity.z);
                    racer->unk_5C.y = (racer->unk_C0.y.x * racer->velocity.x) +
                                      (racer->unk_C0.y.y * racer->velocity.y) + (racer->unk_C0.y.z * racer->velocity.z);
                    racer->unk_5C.z = (racer->unk_C0.x.x * racer->velocity.x) +
                                      (racer->unk_C0.x.y * racer->velocity.y) + (racer->unk_C0.x.z * racer->velocity.z);
                    racer->unk_E8.x.x = racer->unk_C0.x.x;
                    racer->unk_E8.x.y = racer->unk_C0.x.y;
                    racer->unk_E8.x.z = racer->unk_C0.x.z;

                    var_fs0 = racer->unk_68.x * 0.6f;
                    racer->unk_E8.y.x += 0.19f * (racer->unk_C0.y.x + (var_fs0 * racer->unk_C0.z.x));
                    racer->unk_E8.y.y += 0.19f * (racer->unk_C0.y.y + (var_fs0 * racer->unk_C0.z.y));
                    racer->unk_E8.y.z += 0.19f * (racer->unk_C0.y.z + (var_fs0 * racer->unk_C0.z.z));
                    func_8006AA38(&racer->unk_E8);
                    if (var_s0->ghost->replayEnd < var_s0->replayIndex) {
                        if (var_s0->scale != 0.f) {
                            var_s0->scale -= 0.02f;
                            if (var_s0->scale <= 0.0f) {
                                var_s0->exists = var_s0->initialized = false;
                            }
                        }
                    }
                }
            }
        }
    }
    if (gGameFrameCount & 1) {
        func_8008AD38();
    } else {
        if ((D_800E5FBC == 0) || (gNumPlayers == 1)) {
            func_8008A978();
        }

        for (i = 0; i < gNumPlayers; i++) {
            racer2 = &gRacers[i];
            if ((((racer2->unk_24C.x.x * racer2->velocity.x) + (racer2->unk_24C.x.y * racer2->velocity.y) +
                  (racer2->unk_24C.x.z * racer2->velocity.z)) < -0.3f) &&
                !(racer2->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_80000))) {
                D_800F80A8[i]++;
                if (D_800F80A8[i] == 100) {
                    func_800BA8D8(0x3C);
                }
            } else {
                D_800F80A8[i] = 0;
            }
        }
    }
    if (D_800E5EC0 >= 2) {
        if (gNumPlayers == 1) {
            func_8008B150();
            if (D_800E5FD0 != 0) {
                func_800BA2E0(D_800E5FB8);
            }
        }
        if ((D_800E5F40[0]->id < gNumPlayers) && (gGameMode != GAMEMODE_DEATH_RACE) &&
            (gGameMode != GAMEMODE_PRACTICE)) {
            var_fs0 = D_800E5F40[0]->unk_23C - D_800E5F40[1]->unk_23C;
            if (var_fs0 > 4000.0f) {
                if (!(D_800E5F40[0]->unk_08 & 0x4000)) {
                    D_800E5F40[0]->unk_08 |= 0x4000;
                    if (D_800E5FD0 != 0) {
                        func_800BA8D8(0x3B);
                    }
                }
            } else if (var_fs0 < 2000.0f) {
                D_800E5F40[0]->unk_08 &= ~0x4000;
            }
        }
    }
    if (D_800E5FBC == 0) {
        if (gNumPlayers == 1) {
            if (gRacers[0].stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_2000000)) {
                D_800E5FBC = 1;
            }
        } else {
            i = D_800E5FC2 + D_800E5FC4;

            if ((i >= (D_800E5EC0 - 1)) || (gNumPlayers == (D_800E5FC8 + D_800E5FCA))) {
                D_800E5FBC = 1;
                if (gGameFrameCount & 1) {
                    func_8008A978();
                }
                for (racer = &gRacers[D_800E5EC0 - 1]; racer >= gRacers; racer--) {
                    if (!(racer->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_2000000))) {
                        racer->stateFlags |= RACER_STATE_FLAGS_2000000 | RACER_STATE_FLAGS_800000;
                        racer->energy = racer->maxEnergy;
                        if (D_800E5FD0 != 0) {
                            if (racer->position == 1) {
                                func_800BA710(racer->id, 0xF);
                            }
                            func_800BA2B4(racer->id);
                            func_800BAB68(racer->id);
                            if ((i != 0) && (D_800E5FCA == 0)) {
                                i = 0;
                                func_8007E0CC();
                            }
                        }
                    }
                }

                for (i = D_800E5EC0 - 2; i >= 0; i--) {
                    D_800E5F10[D_800E5F40[i]->id] += D_800CE738[i];
                }
                D_800E5F00[D_800E5F40[0]->id]++;
            }
        }
    } else {
        D_800F80B8++;
        switch (D_800F80B8) {
            case 60:
                func_80095144();
                break;
            case 30:
                if (gRacers[0].stateFlags & RACER_STATE_FLAGS_2000000) {
                    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
                        func_800BA8D8(0x3D);
                        break;
                    } else if (gGameMode == GAMEMODE_TIME_ATTACK) {
                        if ((gCurrentGhostType == GHOST_PLAYER) || (gCurrentGhostType == GHOST_NONE)) {
                            func_800BA8D8(0x3D);
                        } else if (gRacers[0].raceTime < gFastestGhostTime) {
                            func_800BA8D8(0x43);
                        }
                    }
                }
                break;
            case 120:
                if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].stateFlags & RACER_STATE_FLAGS_2000000) && (gRacers[0].position == 1)) {
                    func_800BA8D8(0x33);
                }
                break;
        }
    }
}
#else
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/game/1B0E0/func_800952F4.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_800952F4.s")
#endif
#endif

extern unk_80111870 D_80111870[32];
extern s32 D_80111CF0;
extern s32 D_80111CF4;
extern unk_80111870 D_80111CF8[32];
extern s32 D_80112178;
extern s32 D_8011217C;
extern unk_80111870 D_80112180[8];
extern s32 D_801122A0;
extern s32 D_801122A4;
extern unk_801122A8 D_801122A8[32];
extern s32 D_80112B28;
extern s32 D_80112B2C;
extern unk_80111870 D_80112B30[32];
extern s32 D_80112FB0;
extern s32 D_80112FB4;
extern unk_80112FB8 D_80112FB8[32];
extern s32 D_80113138;
extern s32 D_8011313C;
extern unk_80113140 D_80113140[128];
extern s32 D_80115D40;
extern s32 D_80115D44;

#ifdef NON_EQUIVALENT
Gfx* func_80096CE8(Gfx* gfx, s32 playerIndex) {
    s32 var_s3; // sp5CC
    s32 var_s4; // sp5C8
    s32 sp5C4;
    MtxF sp580;
    f32 sp574;
    f32 sp570;
    f32 sp56C;
    f32 sp568;
    f32 sp564;
    f32 sp560;
    f32 sp55C;
    f32 sp558;
    f32 temp_fs4; // sp554
    f32 temp_fs5; // sp550
    f32 sp54C;
    f32 temp_fs1; // sp548
    f32 temp_fs3; // sp544
    f32 temp_fs2; // sp540
    f32 sp53C;
    f32 sp538;
    f32 sp534;
    GhostRacer* sp4F8;
    unk_struct_1DC* spA4;
    Racer* sp9C;
    f32 sp84;
    s32 i;
    Lights1* temp_v0_7;
    Racer* racer;
    Racer* temp_v0_14;
    Racer* temp_v0_27;
    Vec3s* var_v0;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fa0_3;
    f32 temp_fa0_4;
    f32 temp_fa0_5;
    f32 temp_fa0_6;
    f32 temp_fa1;
    f32 temp_fa1_2;
    f32 temp_fa1_3;
    f32 temp_fa1_4;
    f32 temp_fs0;
    f32 temp_fs0_10;
    f32 temp_fs0_11;
    f32 temp_fs0_14;
    f32 temp_fs0_15;
    f32 temp_fs0_18;
    f32 temp_fs0_5;
    f32 temp_fs0_6;

    f32 temp_fv0;
    f32 temp_fv0_10;
    f32 temp_fv0_11;
    f32 temp_fv0_12;
    f32 temp_fv0_13;
    f32 temp_fv0_14;
    f32 temp_fv0_15;
    f32 temp_fv0_16;
    f32 temp_fv0_17;
    f32 temp_fv0_18;
    f32 temp_fv0_19;
    f32 temp_fv0_20;
    f32 temp_fv0_21;
    f32 temp_fv0_22;
    f32 temp_fv0_23;
    f32 temp_fv0_24;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0_6;
    f32 temp_fv0_7;
    f32 temp_fv0_8;
    f32 temp_fv0_9;
    f32 temp_fv1;
    f32 temp_fv1_10;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    f32 temp_fv1_7;
    f32 temp_fv1_9;
    f32 var_fs0;
    f32 var_fs0_2;
    f32 var_fs1;
    f32 var_fs3;

    s32 temp_s7_7;
    s32 temp_a3_4;

    s32 temp_a1_2;
    s32 temp_s4;
    s32 temp_v1_2;
    s32 var_s3_3;
    s32 var_s3_4;
    s32 var_s3_6;
    s32 var_s4_5;
    s32 var_s7;
    TexturePtr var_s2;
    CourseSegment* temp_v0_6;
    unk_800CE788* temp_fp;
    GhostRacer* temp_t8;
    GhostRacer* temp_v0_10;
    GhostRacer* temp_v0_4;
    GhostRacer* var_v1;
    unk_80111870* temp_s1;
    unk_80111870* temp_s1_4;
    unk_80111870* temp_s1_5;
    unk_801122A8* temp_s1_3;
    unk_80112FB8* temp_s1_6;
    Mtx* mtx;
    unk_80113140* temp_v0_13;
    s32 temp;

    spA4 = &D_800E5220[playerIndex];

    temp_fv1 = (spA4->unk_5C.x.x * 100.0f) - spA4->unk_50.x;
    temp_fv0 = (spA4->unk_5C.x.y * 100.0f) - spA4->unk_50.y;
    temp_fa0 = (spA4->unk_5C.x.z * 100.0f) - spA4->unk_50.z;
    temp_fa1 = ((-temp_fv1 * spA4->unk_15C.zx) - (temp_fv0 * spA4->unk_15C.zy)) - (spA4->unk_15C.zz * temp_fa0);
    sp580.ww = temp_fa1;
    sp580.zw = spA4->unk_11C.zw - (temp_fa1 * spA4->unk_11C.zz);
    sp580.xw = (spA4->unk_11C.xx *
                ((temp_fv1 * spA4->unk_15C.xx) + (temp_fv0 * spA4->unk_15C.xy) + (temp_fa0 * spA4->unk_15C.xz))) -
               (temp_fa1 * spA4->unk_11C.xz);
    sp580.xx = spA4->unk_19C.xx;
    sp580.xy = spA4->unk_19C.xy;
    sp580.yw = (spA4->unk_11C.yy *
                ((temp_fv1 * spA4->unk_15C.yx) + (temp_fv0 * spA4->unk_15C.yy) + (temp_fa0 * spA4->unk_15C.yz))) -
               (temp_fa1 * spA4->unk_11C.yz);
    sp580.yx = spA4->unk_19C.yx;
    sp580.zx = spA4->unk_19C.zx;
    sp580.wx = spA4->unk_19C.wx;
    sp580.yy = spA4->unk_19C.yy;
    sp580.zy = spA4->unk_19C.zy;
    sp580.wy = spA4->unk_19C.wy;
    sp580.xz = spA4->unk_19C.xz;
    sp580.yz = spA4->unk_19C.yz;
    sp580.zz = spA4->unk_19C.zz;
    sp580.wz = spA4->unk_19C.wz;
    if (gGameMode != GAMEMODE_GP_END_CS) {
        for (racer = D_800E5EC4; racer >= gRacers; racer--) {
            racer->unk_2B4 = racer->unk_2B2 = racer->unk_2B3 = 0;
            if (racer->stateFlags & RACER_STATE_FLAGS_40000000) {
                temp_fv0_2 = racer->unk_0C.unk_34.x;
                temp_fv1_2 = racer->unk_0C.unk_34.y;
                temp_fa1_2 = racer->unk_0C.unk_34.z;
                temp_fa0_2 = sp580.zw + ((sp580.zx * temp_fv0_2) + (sp580.zy * temp_fv1_2) + (sp580.zz * temp_fa1_2));
                if ((temp_fa0_2 < 0.0f) || (temp_fa0_2 > 2500.0f)) {
                    continue;
                }
                sp574 =
                    1.0f / (sp580.ww + ((sp580.wx * temp_fv0_2) + (sp580.wy * temp_fv1_2) + (sp580.wz * temp_fa1_2)));

                temp_fs0 =
                    (sp580.xw + ((sp580.xx * temp_fv0_2) + (sp580.xy * temp_fv1_2) + (sp580.xz * temp_fa1_2))) * sp574;
                if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                    continue;
                }

                temp_fs0 =
                    (sp580.yw + ((sp580.yx * temp_fv0_2) + (sp580.yy * temp_fv1_2) + (sp580.yz * temp_fa1_2))) * sp574;
                if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                    continue;
                }

                if (temp_fa0_2 < 230.0f) {
                    racer->unk_2B4 = 1;
                } else if (temp_fa0_2 < 290.0f) {
                    racer->unk_2B4 = 2;
                } else if (temp_fa0_2 < 380.0f) {
                    racer->unk_2B4 = 3;
                } else if (temp_fa0_2 < 470.0f) {
                    racer->unk_2B4 = 4;
                } else if (temp_fa0_2 < 1500.0f) {
                    racer->unk_2B4 = 5;
                } else {
                    racer->unk_2B4 = 6;
                }

                if (temp_fa0_2 < 800.0f) {
                    racer->unk_2B2 = 1;
                }
                if (temp_fa0_2 < 400.0f) {
                    racer->unk_2B3 = 2;
                } else if (temp_fa0_2 < 900.0f) {
                    racer->unk_2B3 = 1;
                }
            }
        }
    } else {
        for (racer = D_800E5EC4; racer >= gRacers; racer--) {
            racer->unk_2B4 = racer->unk_2B2 = 1;
            racer->unk_2B3 = 2;
        }
    }
    if (gNumPlayers >= 3) {
        for (racer = &gRacers[gNumPlayers - 1]; racer >= gRacers; racer--) {
            if ((racer->unk_2B4 != 0) && (racer->unk_2B4 < 6)) {
                racer->unk_2B4++;
            }
            if (racer->unk_2B3 == 2) {
                racer->unk_2B3 = 1;
            }
        }
    } else if (gGameMode == GAMEMODE_TIME_ATTACK) {
        for (var_v1 = &gGhostRacers[2]; var_v1 >= gGhostRacers; var_v1--) {
            if (var_v1->exists) {
                racer = var_v1->racer;
                racer->unk_2B4 = racer->unk_2B2 = racer->unk_2B3 = 0;
                if (var_v1->exists) {
                    temp_fv0_3 = racer->unk_0C.unk_34.x;
                    temp_fv1_3 = racer->unk_0C.unk_34.y;
                    temp_fa1_3 = racer->unk_0C.unk_34.z;
                    temp_fa0_2 =
                        sp580.zw + ((sp580.zx * temp_fv0_3) + (sp580.zy * temp_fv1_3) + (sp580.zz * temp_fa1_3));
                    if ((temp_fa0_2 < 0.0f) || (temp_fa0_2 > 2500.0f)) {
                        continue;
                    }
                    sp574 = 1.0f /
                            (sp580.ww + ((sp580.wx * temp_fv0_3) + (sp580.wy * temp_fv1_3) + (sp580.wz * temp_fa1_3)));

                    temp_fs0 =
                        (sp580.xw + ((sp580.xx * temp_fv0_3) + (sp580.xy * temp_fv1_3) + (sp580.xz * temp_fa1_3))) *
                        sp574;
                    if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                        continue;
                    }
                    temp_fs0 =
                        (sp580.yw + ((sp580.yx * temp_fv0_3) + (sp580.yy * temp_fv1_3) + (sp580.yz * temp_fa1_3))) *
                        sp574;
                    if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                        continue;
                    }

                    if (temp_fa0_2 < 230.0f) {
                        racer->unk_2B4 = 1;
                    } else if (temp_fa0_2 < 290.0f) {
                        racer->unk_2B4 = 2;
                    } else if (temp_fa0_2 < 380.0f) {
                        racer->unk_2B4 = 3;
                    } else if (temp_fa0_2 < 470.0f) {
                        racer->unk_2B4 = 4;
                    } else if (temp_fa0_2 < 1500.0f) {
                        racer->unk_2B4 = 5;
                    } else {
                        racer->unk_2B4 = 6;
                    }

                    if (temp_fa0_2 < 800.0f) {
                        racer->unk_2B2 = 1;
                    }
                    if (temp_fa0_2 < 400.0f) {
                        racer->unk_2B3 = 2;
                    } else if (temp_fa0_2 < 900.0f) {
                        racer->unk_2B3 = 1;
                    }
                }
            }
        }
    }
    if (D_800F5E98 < 280) {
        gSPDisplayList(gfx++, D_303A758);
        if (gGameMode == GAMEMODE_GP_END_CS) {
            gSPSetGeometryMode(gfx++, G_ZBUFFER);
            gDPSetRenderMode(gfx++, G_RM_ZB_XLU_DECAL, G_RM_ZB_XLU_DECAL2);
        }

        for (racer = D_800E5EC4; racer >= gRacers; racer--) {

            if ((racer->unk_2B2 != 0) && (racer->unk_168.y != -54321.0f)) {
                if (racer->unk_165 == 0) {
                    if (racer->unk_284 == 1) {
                        var_fs0 = ((COS(racer->unk_27C) * 0.15f) + 0.85f) * D_800CE750;
                    } else {
                        var_fs0 = D_800CE750;
                    }

                    func_8006BFCC(&D_800DCCF0->unk_20A88[racer->id], NULL, racer->shadowColorStrength * D_800CE748, 0.1f,
                                  racer->shadowColorStrength * var_fs0, &racer->unk_E8.x, &racer->unk_19C, &racer->unk_168);
                    racer->unk_165 = 1;
                }
                gSPMatrix(gfx++, &D_1000000.unk_20A88[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

                if (!(racer->stateFlags & RACER_STATE_FLAGS_8000000)) {
                    gDPLoadTextureBlock_4b(gfx++, D_800CDC54[racer->unk_2CA], G_IM_FMT_I, 32, 64, 0,
                                           G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD,
                                           G_TX_NOLOD);
                    gDPSetPrimColor(gfx++, 0, 0, racer->shadowR, racer->shadowG, racer->shadowB, 200);
                    gSPVertex(gfx++, D_800CDBA4[racer->unk_2CA], 4, 0);
                } else {
                    gDPLoadTextureBlock_4b(gfx++, D_70488A8, G_IM_FMT_I, 32, 64, 0, G_TX_MIRROR | G_TX_CLAMP,
                                           G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
                    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 200);
                    gSPVertex(gfx++, D_7048868, 4, 0);
                }
                gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
            }
        }
        if (gGameMode == GAMEMODE_TIME_ATTACK) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 200);

            for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
                if (sp4F8->exists) {
                    racer = sp4F8->racer;
                    if ((racer->unk_2B2 != 0) && (racer->unk_168.y != -54321.0f)) {
                        func_8006BFCC(&D_800DCCF0->unk_20A88[racer->id], NULL, sp4F8->scale * D_800CE748, 0.1f,
                                      sp4F8->scale * D_800CE750, &racer->unk_E8.x, &racer->unk_19C, &racer->unk_168);
                        gSPMatrix(gfx++, &D_1000000.unk_20A88[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                        gDPLoadTextureBlock_4b(gfx++, D_800CDC54[racer->unk_2CA], G_IM_FMT_I, 32, 64, 0,
                                               G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD,
                                               G_TX_NOLOD);
                        gSPVertex(gfx++, D_800CDBA4[racer->unk_2CA], 4, 0);
                        gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
                    }
                }
            }
        }
    } else {
        gRacers[0].speed = gRacers[1].speed = gRacers[2].speed = gRacers[3].speed = 0.0f;
    }

    gSPDisplayList(gfx++, D_303A7D8);

    for (racer = D_800E5EC4; racer >= gRacers; racer--) {
        if (racer->unk_178 != 0.0f) {
            if ((racer->unk_2B4 != 0) && (racer->unk_2B4 < 6)) {
                if (racer->unk_166 == 0) {
                    func_8006C278(&D_800DCCF0->unk_21208[racer->id], NULL, racer->unk_178 * D_800CE748,
                                  racer->unk_178 * D_800CE74C, racer->unk_178 * D_800CE750, &racer->unk_E8,
                                  &racer->unk_10C);
                    racer->unk_166 = 1;
                }
                gSPMatrix(gfx++, &D_1000000.unk_21208[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPPipeSync(gfx++);
                gDPSetBlendColor(gfx++, racer->unk_2DA, racer->unk_2DC, racer->unk_2DE, 255);

                if (!(racer->stateFlags & RACER_STATE_FLAGS_8000000)) {
                    gSPDisplayList(gfx++, D_800CDDB0[racer->unk_2C9 * 6 + racer->unk_2B4 - 1]);
                } else {
                    gSPDisplayList(gfx++, D_800CE07C[racer->unk_2B4]);
                }
            }
        }
    }
    sp9C = &gRacers[playerIndex];

    temp_v0_6 = sp9C->unk_0C.courseSegment;
    if (temp_v0_6->trackSegmentInfo & TRACK_FLAG_20000000) {
        if (temp_v0_6->unk_6C < sp9C->unk_0C.unk_04) {
            var_fs0_2 = (1.0f - sp9C->unk_0C.unk_08) / temp_v0_6->unk_70;
        } else if (sp9C->unk_0C.unk_04 < temp_v0_6->unk_68) {
            var_fs0_2 = sp9C->unk_0C.unk_08 / temp_v0_6->unk_70;
        } else {
            var_s3 = 50;
            var_s4 = 50;
            sp5C4 = 50;
            goto block_115;
        }
        var_s3 = Math_Round(var_fs0_2 * -50.0f) + 100;
        var_s4 = Math_Round(var_fs0_2 * -50.0f) + 100;
        sp5C4 = Math_Round(var_fs0_2 * -50.0f) + 100;
    } else {
        var_s3 = 100;
        var_s4 = 100;
        sp5C4 = 100;
    }
block_115:
    temp_v0_7 = &D_800DCCF0->unk_21A88[playerIndex];
    temp_v0_7->a.l.colc[0] = var_s3;
    temp_v0_7->a.l.col[0] = var_s3;
    temp_v0_7->a.l.colc[1] = var_s4;
    temp_v0_7->a.l.col[1] = var_s4;
    temp_v0_7->a.l.colc[2] = sp5C4;
    temp_v0_7->a.l.col[2] = sp5C4;
    if (gGameMode == GAMEMODE_GP_END_CS) {
        gSPDisplayList(gfx++, D_303A5F8);
    } else {
        gSPDisplayList(gfx++, D_303A6A8);
    }

    gSPLight(gfx++, &D_1000000.unk_21A88[playerIndex].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_21A88[playerIndex].a, 2);

    if ((sp9C->unk_0C.courseSegment->trackSegmentInfo & TRACK_FLAG_20000000) && !(sp9C->stateFlags & RACER_STATE_FLAGS_80000000)) {
        sp560 = sp9C->unk_24C.y.x;
        D_800DCCF0->unk_21A88[playerIndex].l[0].l.dir[0] = Math_Round(sp560 * 120.0f);
        sp55C = sp9C->unk_24C.y.y;
        D_800DCCF0->unk_21A88[playerIndex].l[0].l.dir[1] = Math_Round(sp55C * 120.0f);
        sp558 = sp9C->unk_24C.y.z;
        D_800DCCF0->unk_21A88[playerIndex].l[0].l.dir[2] = Math_Round(sp558 * 120.0f);
        if ((sp9C->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_PIPE) {
            var_v0 = &D_800E5FE8[sp9C->unk_0C.courseSegment->trackSegmentInfo & TRACK_TYPE_MASK];
        } else {
            var_v0 = &D_800E5FEC[sp9C->unk_0C.courseSegment->trackSegmentInfo & TRACK_TYPE_MASK];
        }
        var_s3 = var_v0->x;
        sp5C4 = var_v0->y;
        var_s4 = var_v0->z;
    } else {
        D_800DCCF0->unk_21A88[playerIndex].l[0].l.dir[0] = D_800DCCF0->unk_21A88[playerIndex].l[0].l.dir[1] =
            D_800DCCF0->unk_21A88[playerIndex].l[0].l.dir[2] = 0x45;
        sp560 = 0.57735f;
        sp55C = 0.57735f;
        sp558 = 0.57735f;
        var_s3 = gCurrentCourseRecordInfo->unk_14[3];
        sp5C4 = gCurrentCourseRecordInfo->unk_14[4];
        var_s4 = gCurrentCourseRecordInfo->unk_14[5];
    }
    if (gGameMode != GAMEMODE_GP_END_CS) {
        D_800DCCF0->unk_21AE8[playerIndex].l.unk_08[0] = Math_Round((sp560 - spA4->unk_5C.x.x) * 16383.0f);
        D_800DCCF0->unk_21AE8[playerIndex].l.unk_08[1] = Math_Round((sp55C - spA4->unk_5C.x.y) * 16383.0f);
        D_800DCCF0->unk_21AE8[playerIndex].l.unk_08[2] = Math_Round((sp558 - spA4->unk_5C.x.z) * 16383.0f);
        gSPDmaRead(gfx++, 0x8B0, D_800CE3D0, 0x100);
        gSPLookAtY(gfx++, &D_1000000.unk_21AE8[playerIndex]);
        gDPSetFogColor(gfx++, var_s3, sp5C4, var_s4, 255);
    }

    for (racer = D_800E5EC4; racer >= gRacers; racer--) {
        if (racer->unk_2B4 != 0) {
            if (racer->unk_164 == 0) {
                func_8006C278(&D_800DCCF0->unk_20308[racer->id], &racer->unk_124, D_800CE748, D_800CE74C, D_800CE750,
                              &racer->unk_E8, &racer->unk_10C);
                racer->unk_164 = 1;
            }
            if (!(racer->stateFlags & RACER_STATE_FLAGS_8000000)) {
                gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(gfx++, D_800CDD38[racer->unk_2C9]);
                gDPSetEnvColor(gfx++, racer->unk_2CE, racer->unk_2D0, racer->unk_2D2, 255);
                gSPDisplayList(gfx++, D_800CDDB0[racer->unk_2C9 * 6 + racer->unk_2B4 - 1]);
            }
        }
    }
    if (gGameMode == GAMEMODE_GP_END_CS) {
        gSPDisplayList(gfx++, D_90186C8);
        Light_SetLookAtSource(&D_800DCCF0->unk_21B28, &spA4->unk_15C);
        gSPLookAt(gfx++, &D_800DCCF0->unk_21B28);
        gSPTexture(gfx++, D_800CE768, D_800CE768, 0, G_TX_RENDERTILE, G_ON);

        gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_MIRROR | G_TX_WRAP, 5,
                   G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

        if (gCourseData.skybox == 3) {
            var_s2 = D_9000A10;
        } else {
            var_s2 = D_9000208;
        }

        gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, var_s2);
        gDPLoadBlock(gfx++, G_TX_RENDERTILE, 0, 0, 1023, 256);
        gDPTileSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_MIRROR | G_TX_WRAP, 5,
                   G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

        D_800F809C += ((spA4->unk_5C.z.x * gRacers->velocity.x) + (spA4->unk_5C.z.y * gRacers->velocity.y) +
                       (spA4->unk_5C.z.z * gRacers->velocity.z)) *
                      D_800CE76C;
        temp_a1_2 = (s32) (D_800F809C * 4.0f) & 0xFF;

        D_800F80A0 += ((spA4->unk_5C.y.x * gRacers->velocity.x) + (spA4->unk_5C.y.y * gRacers->velocity.y) +
                       (spA4->unk_5C.y.z * gRacers->velocity.z)) *
                      D_800CE76C;
        temp_v1_2 = (s32) (D_800F80A0 * 4.0f) & 0xFF;

        gDPSetTileSize(gfx++, G_TX_RENDERTILE, temp_a1_2, temp_v1_2, temp_v1_2 + 0xFC, temp_v1_2 + 0xFC);

        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_800CE764);

        for (racer = D_800E5EC4; racer >= gRacers; racer--) {
            gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gfx = func_8009CEA0(gfx, racer->character);
        }
    }

    var_s7 = 0;
    for (racer = D_800E5EC4; racer >= gRacers; racer--) {
        if ((racer->unk_2B4 != 0) && (racer->stateFlags & RACER_STATE_FLAGS_8000000)) {
            if (var_s7 == 0) {
                gSPDisplayList(gfx++, D_7045150);
                var_s7 = 1;
            }
            gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPPipeSync(gfx++);
            gDPSetEnvColor(gfx++, racer->unk_2CE, racer->unk_2D0, racer->unk_2D2, 255);
            gSPDisplayList(gfx++, D_800CE07C[racer->unk_2B4]);
        }
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++,
                         Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL |
                             GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA),
                         Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL |
                             GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));

        for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
            if (sp4F8->exists) {
                racer = sp4F8->racer;
                if (racer->unk_2B4 != 0) {
                    func_8006C278(&D_800DCCF0->unk_20308[racer->id], &racer->unk_124, sp4F8->scale * D_800CE748,
                                  sp4F8->scale * D_800CE74C, sp4F8->scale * D_800CE750, &racer->unk_E8,
                                  &racer->unk_10C);
                    gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gSPDisplayList(gfx++, D_800CDD38[racer->unk_2C9]);
                    gDPSetEnvColor(gfx++, racer->unk_2CE, racer->unk_2D0, racer->unk_2D2, 240);
                    gSPDisplayList(gfx++, D_800CDDB0[racer->unk_2C9 * 6 + racer->unk_2B4 - 1]);
                }
            }
        }
    }
    sp560 = spA4->unk_5C.z.x;
    sp55C = spA4->unk_5C.z.y;
    sp558 = spA4->unk_5C.z.z;
    sp56C = spA4->unk_5C.y.x;
    sp568 = spA4->unk_5C.y.y;
    sp564 = spA4->unk_5C.y.z;

    gSPDisplayList(gfx++, D_4007F08);

    if (D_800DCE5C == 0) {
        sp5C4 = gGameFrameCount;
    } else {
        sp5C4 = 1;
    }

    for (racer = D_800E5EC4; racer >= gRacers; racer--) {
        if ((racer->unk_2B3 != 0) && !(racer->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_4000))) {
            temp_fp = &D_800CE788[racer->unk_2CB];

            var_s3_3 = (3 - (sp5C4 & 3)) * 2;
            if ((3 - (sp5C4 & 3)) * 2 < racer->unk_214) {
                var_s3_3 = racer->unk_214;
            }
            sp574 = var_s3_3 * 0.2f;

            // Boost color
            temp_fs0_5 = (f32) racer->boostTimer / sInitialBoostTimer;
            if (temp_fs0_5 != 0.0f) {
                sp574 += (7.5f * sqrtf(temp_fs0_5));
                if (racer->stateFlags & RACER_STATE_DASH_PAD_BOOST) {
                    gDPSetEnvColor(gfx++, 255, 223, 0, 255);
                } else {
                    gDPSetEnvColor(gfx++, 91, 255, 91, 255);
                }
            } else {
                gDPSetEnvColor(gfx++, 0, 255, 255, 255);
            }

            sp570 = (racer->unk_17C - D_800F80A4) / (13.0f - D_800F80A4);

            for (var_s3_4 = temp_fp->unk_00 - 1; var_s3_4 >= 0; var_s3_4--) {
                temp_fs0_6 = temp_fp->unk_34[var_s3_4] * 0.35f;
                temp_fv0_12 = temp_fp->unk_04[var_s3_4].x;
                temp_fv1_4 = temp_fp->unk_04[var_s3_4].y;
                temp_fa0_4 = temp_fp->unk_04[var_s3_4].z - (temp_fs0_6 * 3.6f);
                temp_fs4 = racer->unk_124.xw + ((racer->unk_124.xx * temp_fv0_12) + (racer->unk_124.xy * temp_fv1_4) +
                                                (racer->unk_124.xz * temp_fa0_4));
                temp_fs5 = racer->unk_124.yw + ((racer->unk_124.yx * temp_fv0_12) + (racer->unk_124.yy * temp_fv1_4) +
                                                (racer->unk_124.yz * temp_fa0_4));
                sp54C = racer->unk_124.zw + ((racer->unk_124.zx * temp_fv0_12) + (racer->unk_124.zy * temp_fv1_4) +
                                             (racer->unk_124.zz * temp_fa0_4));

                temp_fs0_6 += sp574;
                temp_fs0_6 *= sp570;
                temp_fs1 = temp_fs0_6 * sp56C;
                D_800E5ECC[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
                temp_fs2 = temp_fs0_6 * sp568;
                D_800E5ECC[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
                temp_fs3 = temp_fs0_6 * sp564;
                D_800E5ECC[0].v.ob[2] = Math_Round(sp54C + temp_fs3);

                D_800E5ECC[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                D_800E5ECC[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                D_800E5ECC[2].v.ob[2] = Math_Round(sp54C - temp_fs3);
                temp_fs1 = temp_fs0_6 * sp560;
                D_800E5ECC[1].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
                temp_fs2 = temp_fs0_6 * sp55C;
                D_800E5ECC[1].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
                temp_fs3 = temp_fs0_6 * sp558;
                D_800E5ECC[1].v.ob[2] = Math_Round(sp54C + temp_fs3);
                D_800E5ECC[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                D_800E5ECC[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                D_800E5ECC[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
                D_800E5ECC[0].v.tc[0] = D_800E5ECC[1].v.tc[0] = D_800E5ECC[1].v.tc[1] = D_800E5ECC[2].v.tc[1] = 0;
                D_800E5ECC[0].v.tc[1] = D_800E5ECC[2].v.tc[0] = D_800E5ECC[3].v.tc[0] = D_800E5ECC[3].v.tc[1] = 0x3FF;
                if (racer->unk_2B3 == 2) {
                    temp_fs0_6 = racer->speed * 0.9f;
                    D_800E5ECC[4].v.ob[0] = Math_Round(temp_fs4 - (racer->unk_E8.x.x * temp_fs0_6));
                    D_800E5ECC[4].v.ob[1] = Math_Round(temp_fs5 - (racer->unk_E8.x.y * temp_fs0_6));
                    D_800E5ECC[4].v.ob[2] = Math_Round(sp54C - (racer->unk_E8.x.z * temp_fs0_6));
                    D_800E5ECC[4].v.tc[0] = 0x3FF;
                    D_800E5ECC[4].v.tc[1] = 0;
                    D_800E5ECC += 5;
                } else {
                    D_800E5ECC += 4;
                }
            }
            if (racer->unk_2B3 == 2) {
                temp = temp_fp->unk_00 * 5;
                gSPVertex(gfx++, D_800E5ECC - temp, temp, 0);

                switch (temp_fp->unk_00) {
                    case 4:
                        gSP2Triangles(gfx++, 16, 17, 18, 0, 15, 16, 18, 0);
                        gSP2Triangles(gfx++, 10, 11, 13, 0, 16, 19, 18, 0);
                        gSP2Triangles(gfx++, 11, 14, 13, 0, 11, 12, 13, 0);
                    /* fallthrough */
                    case 2:
                        gSP2Triangles(gfx++, 6, 7, 8, 0, 5, 6, 8, 0);
                        gSP2Triangles(gfx++, 0, 1, 3, 0, 6, 9, 8, 0);
                        gSP2Triangles(gfx++, 1, 4, 3, 0, 1, 2, 3, 0);
                        break;
                    case 3:
                        gSP2Triangles(gfx++, 11, 12, 13, 0, 10, 11, 13, 0);
                        gSP2Triangles(gfx++, 5, 6, 8, 0, 11, 14, 13, 0);
                        gSP2Triangles(gfx++, 6, 9, 8, 0, 6, 7, 8, 0);
                    /* fallthrough */
                    case 1:
                        gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                        gSP1Triangle(gfx++, 1, 4, 3, 0);
                        break;
                }

            } else {
                gSPVertex(gfx++, D_800E5ECC - temp_fp->unk_00 * 4, temp_fp->unk_00 * 4, 0);

                switch (temp_fp->unk_00) {
                    case 4:
                        gSP2Triangles(gfx++, 13, 14, 15, 0, 12, 13, 15, 0);
                    /* fallthrough */
                    case 3:
                        gSP2Triangles(gfx++, 9, 10, 11, 0, 8, 9, 11, 0);
                    /* fallthrough */
                    case 2:
                        gSP2Triangles(gfx++, 5, 6, 7, 0, 4, 5, 7, 0);
                    /* fallthrough */
                    case 1:
                        gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                        break;
                }
            }
        }
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        gDPPipeSync(gfx++);
        gDPSetEnvColor(gfx++, 255, 0, 255, 160);

        for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
            if (sp4F8->exists) {
                racer = sp4F8->racer;
                if (racer->unk_2B3 != 0) {
                    temp_fp = &D_800CE788[racer->unk_2CB];

                    sp84 = (f32) ((3 - (sp5C4 & 3)) * 2) * 0.2f;
                    for (var_s3_4 = temp_fp->unk_00 - 1; var_s3_4 >= 0; var_s3_4--) {

                        temp_fs0_10 = temp_fp->unk_34[var_s3_4] * 0.35f;
                        temp_fv0_13 = temp_fp->unk_04[var_s3_4].x;
                        temp_fv1_5 = temp_fp->unk_04[var_s3_4].y;
                        temp_fa0_5 = temp_fp->unk_04[var_s3_4].z - (temp_fs0_10 * 3.6f);
                        temp_fs4 =
                            racer->unk_124.xw + ((racer->unk_124.xx * temp_fv0_13) + (racer->unk_124.xy * temp_fv1_5) +
                                                 (racer->unk_124.xz * temp_fa0_5));
                        temp_fs5 =
                            racer->unk_124.yw + ((racer->unk_124.yx * temp_fv0_13) + (racer->unk_124.yy * temp_fv1_5) +
                                                 (racer->unk_124.yz * temp_fa0_5));
                        sp54C =
                            racer->unk_124.zw + ((racer->unk_124.zx * temp_fv0_13) + (racer->unk_124.zy * temp_fv1_5) +
                                                 (racer->unk_124.zz * temp_fa0_5));

                        D_800E5ECC[0].v.ob[0] = Math_Round(temp_fs4 + (temp_fs1 = temp_fs0_10 * sp56C));
                        D_800E5ECC[0].v.ob[1] = Math_Round(temp_fs5 + (temp_fs2 = temp_fs0_10 * sp568));
                        D_800E5ECC[0].v.ob[2] = Math_Round(sp54C + (temp_fs3 = temp_fs0_10 * sp564));
                        D_800E5ECC[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                        D_800E5ECC[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                        D_800E5ECC[2].v.ob[2] = Math_Round(sp54C - temp_fs3);
                        temp_fs0_10 += sp84;

                        D_800E5ECC[1].v.ob[0] = Math_Round(temp_fs4 + (temp_fs1 = temp_fs0_10 * sp560));
                        D_800E5ECC[1].v.ob[1] = Math_Round(temp_fs5 + (temp_fs2 = temp_fs0_10 * sp55C));
                        D_800E5ECC[1].v.ob[2] = Math_Round(sp54C + (temp_fs3 = temp_fs0_10 * sp558));
                        D_800E5ECC[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                        D_800E5ECC[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                        D_800E5ECC[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
                        D_800E5ECC[0].v.tc[0] = D_800E5ECC[1].v.tc[0] = D_800E5ECC[1].v.tc[1] = D_800E5ECC[2].v.tc[1] =
                            0;
                        D_800E5ECC[0].v.tc[1] = D_800E5ECC[2].v.tc[0] = D_800E5ECC[3].v.tc[0] = D_800E5ECC[3].v.tc[1] =
                            0x3FF;
                        if (racer->unk_2B3 == 2) {
                            temp_fs0_11 = racer->speed * 0.9f;
                            D_800E5ECC[4].v.ob[0] = Math_Round(temp_fs4 - (racer->unk_E8.x.x * temp_fs0_11));
                            D_800E5ECC[4].v.ob[1] = Math_Round(temp_fs5 - (racer->unk_E8.x.y * temp_fs0_11));
                            D_800E5ECC[4].v.ob[2] = Math_Round(sp54C - (racer->unk_E8.x.z * temp_fs0_11));
                            D_800E5ECC[4].v.tc[0] = 0x3FF;
                            D_800E5ECC[4].v.tc[1] = 0;
                            D_800E5ECC += 5;
                        } else {
                            D_800E5ECC += 4;
                        }
                    }
                    if (racer->unk_2B3 == 2) {
                        temp = temp_fp->unk_00 * 5;
                        gSPVertex(gfx++, D_800E5ECC - temp, temp, 0);

                        switch (temp_fp->unk_00) {
                            case 4:
                                gSP2Triangles(gfx++, 16, 17, 18, 0, 15, 16, 18, 0);
                                gSP2Triangles(gfx++, 10, 11, 13, 0, 16, 19, 18, 0);
                                gSP2Triangles(gfx++, 11, 14, 13, 0, 11, 12, 13, 0);
                            /* fallthrough */
                            case 2:
                                gSP2Triangles(gfx++, 6, 7, 8, 0, 5, 6, 8, 0);
                                gSP2Triangles(gfx++, 0, 1, 3, 0, 6, 9, 8, 0);
                                gSP2Triangles(gfx++, 1, 4, 3, 0, 1, 2, 3, 0);
                                break;
                            case 3:
                                gSP2Triangles(gfx++, 11, 12, 13, 0, 10, 11, 13, 0);
                                gSP2Triangles(gfx++, 5, 6, 8, 0, 11, 14, 13, 0);
                                gSP2Triangles(gfx++, 6, 9, 8, 0, 6, 7, 8, 0);
                            /* fallthrough */
                            case 1:
                                gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                                gSP1Triangle(gfx++, 1, 4, 3, 0);
                                break;
                        }
                    } else {
                        temp = temp_fp->unk_00 * 4;
                        gSPVertex(gfx++, D_800E5ECC - temp, temp, 0);

                        switch (temp_fp->unk_00) {
                            case 4:
                                gSP2Triangles(gfx++, 13, 14, 15, 0, 12, 13, 15, 0);
                            /* fallthrough */
                            case 3:
                                gSP2Triangles(gfx++, 9, 10, 11, 0, 8, 9, 11, 0);
                            /* fallthrough */
                            case 2:
                                gSP2Triangles(gfx++, 5, 6, 7, 0, 4, 5, 7, 0);
                            /* fallthrough */
                            case 1:
                                gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                                break;
                        }
                    }
                }
            }
        }
    }
    gSPDisplayList(gfx++, D_4007FB8);

    var_s3_6 = D_8011217C;

    var_s7 = (D_80112178 - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((u32) (D_800E5ED0 - 3) >= (u32) D_800E5ECC)) {
        temp_s1 = &D_80111CF8[var_s7];

        temp_fs1 = temp_s1->unk_18 * sp56C;
        temp_fs3 = temp_s1->unk_18 * sp568;
        temp_fs2 = temp_s1->unk_18 * sp564;
        sp53C = temp_s1->unk_18 * sp560;
        sp538 = temp_s1->unk_18 * sp55C;
        sp534 = temp_s1->unk_18 * sp558;

        D_800E5ECC[0].v.ob[0] = Math_Round(temp_s1->unk_00.x + temp_fs1);
        D_800E5ECC[0].v.ob[1] = Math_Round(temp_s1->unk_00.y + temp_fs3);
        D_800E5ECC[0].v.ob[2] = Math_Round(temp_s1->unk_00.z + temp_fs2);
        D_800E5ECC[2].v.ob[0] = Math_Round(temp_s1->unk_00.x - temp_fs1);
        D_800E5ECC[2].v.ob[1] = Math_Round(temp_s1->unk_00.y - temp_fs3);
        D_800E5ECC[2].v.ob[2] = Math_Round(temp_s1->unk_00.z - temp_fs2);
        D_800E5ECC[1].v.ob[0] = Math_Round(temp_s1->unk_00.x + sp53C);
        D_800E5ECC[1].v.ob[1] = Math_Round(temp_s1->unk_00.y + sp538);
        D_800E5ECC[1].v.ob[2] = Math_Round(temp_s1->unk_00.z + sp534);
        D_800E5ECC[3].v.ob[0] = Math_Round(temp_s1->unk_00.x - sp53C);
        D_800E5ECC[3].v.ob[1] = Math_Round(temp_s1->unk_00.y - sp538);
        D_800E5ECC[3].v.ob[2] = Math_Round(temp_s1->unk_00.z - sp534);

        D_800E5ECC[0].v.tc[0] = D_800E5ECC[1].v.tc[0] = D_800E5ECC[1].v.tc[1] = D_800E5ECC[2].v.tc[1] = 0;
        D_800E5ECC[0].v.tc[1] = D_800E5ECC[2].v.tc[0] = D_800E5ECC[3].v.tc[0] = D_800E5ECC[3].v.tc[1] = 0x7FF;

        gSPVertex(gfx++, D_800E5ECC, 4, 0);
        gDPPipeSync(gfx++);

        if (temp_s1->unk_1C < 8) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->unk_1C * 16), 255);
            gDPSetEnvColor(gfx++, 255, 255 - (temp_s1->unk_1C * 32), 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->unk_1C * 16), 255);
            gDPSetEnvColor(gfx++, 0x1FF - (temp_s1->unk_1C * 32), 0, 0, 0x17F - (temp_s1->unk_1C * 16));
        }

        gDPLoadTextureBlock(gfx++, D_800CDAB8[temp_s1->unk_1C >> 1], G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 0, 0, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);

        var_s3_6--;

        var_s7 = (var_s7 - 1) & 0x1F;

        D_800E5ECC += 4;
    }
    var_s3_6 = D_801122A4;
    var_s7 = (D_801122A0 - 1) & 7;
    while ((var_s3_6 != 0) && ((D_800E5ED0 - 3) >= D_800E5ECC)) {
        temp_s1 = &D_80112180[var_s7];
        temp_fs1 = temp_s1->unk_18 * sp56C;
        temp_fs3 = temp_s1->unk_18 * sp568;
        temp_fs2 = temp_s1->unk_18 * sp564;
        sp538 = temp_s1->unk_18 * sp55C;
        sp53C = temp_s1->unk_18 * sp560;
        sp534 = temp_s1->unk_18 * sp558;

        D_800E5ECC[0].v.ob[0] = Math_Round(temp_s1->unk_00.x + temp_fs1);
        D_800E5ECC[0].v.ob[1] = Math_Round(temp_s1->unk_00.y + temp_fs3);
        D_800E5ECC[0].v.ob[2] = Math_Round(temp_s1->unk_00.z + temp_fs2);
        D_800E5ECC[2].v.ob[0] = Math_Round(temp_s1->unk_00.x - temp_fs1);
        D_800E5ECC[2].v.ob[1] = Math_Round(temp_s1->unk_00.y - temp_fs3);
        D_800E5ECC[2].v.ob[2] = Math_Round(temp_s1->unk_00.z - temp_fs2);
        D_800E5ECC[1].v.ob[0] = Math_Round(temp_s1->unk_00.x + sp53C);
        D_800E5ECC[1].v.ob[1] = Math_Round(temp_s1->unk_00.y + sp538);
        D_800E5ECC[1].v.ob[2] = Math_Round(temp_s1->unk_00.z + sp534);
        D_800E5ECC[3].v.ob[0] = Math_Round(temp_s1->unk_00.x - sp53C);
        D_800E5ECC[3].v.ob[1] = Math_Round(temp_s1->unk_00.y - sp538);
        D_800E5ECC[3].v.ob[2] = Math_Round(temp_s1->unk_00.z - sp534);

        D_800E5ECC[0].v.tc[0] = D_800E5ECC[1].v.tc[0] = D_800E5ECC[1].v.tc[1] = D_800E5ECC[2].v.tc[1] = 0;
        D_800E5ECC[0].v.tc[1] = D_800E5ECC[2].v.tc[0] = D_800E5ECC[3].v.tc[0] = D_800E5ECC[3].v.tc[1] = 0x7FF;

        gSPVertex(gfx++, D_800E5ECC, 4, 0);
        gDPPipeSync(gfx++);

        if (temp_s1->unk_1C < 16) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->unk_1C * 8), 255);
            gDPSetEnvColor(gfx++, 255, 255 - (temp_s1->unk_1C * 16), 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->unk_1C * 8), 255);
            gDPSetEnvColor(gfx++, 0x1FF - (temp_s1->unk_1C * 16), 0, 0, 0x17F - (temp_s1->unk_1C * 8));
        }

        gDPLoadTextureBlock(gfx++, D_800CDAB8[temp_s1->unk_1C >> 2], G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 0, 0, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);

        var_s3_6--;

        var_s7 = (var_s7 - 1) & 7;

        D_800E5ECC += 4;
    }

    gSPDisplayList(gfx++, D_4007FD8);

    var_s3_6 = D_80115D44;

    var_s7 = (D_80115D40 - 1) & 0x7F;
    while ((var_s3_6 != 0) && ((D_800E5ED0 - 2) >= D_800E5ECC)) {

        temp_v0_13 = &D_80113140[var_s7];
        D_800E5ECC[0].v.ob[0] = temp_v0_13->unk_00.x;
        D_800E5ECC[0].v.ob[1] = temp_v0_13->unk_00.y;
        D_800E5ECC[0].v.ob[2] = temp_v0_13->unk_00.z;
        D_800E5ECC[1].v.ob[0] = temp_v0_13->unk_0C.x;
        D_800E5ECC[1].v.ob[1] = temp_v0_13->unk_0C.y;
        D_800E5ECC[1].v.ob[2] = temp_v0_13->unk_0C.z;
        D_800E5ECC[2].v.ob[0] = temp_v0_13->unk_18.x;
        D_800E5ECC[2].v.ob[1] = temp_v0_13->unk_18.y;
        D_800E5ECC[2].v.ob[2] = temp_v0_13->unk_18.z;
        D_800E5ECC[0].v.cn[0] = temp_v0_13->unk_48;
        D_800E5ECC[0].v.cn[1] = temp_v0_13->unk_4A;
        D_800E5ECC[0].v.cn[2] = temp_v0_13->unk_4C;
        D_800E5ECC[0].v.cn[3] = temp_v0_13->unk_4E;
        gSPVertex(gfx++, D_800E5ECC, 3, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);

        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x7F;
        D_800E5ECC += 3;
    }

    gSPDisplayList(gfx++, D_4008000);

    var_s3_6 = D_80112B2C;
    var_s7 = (D_80112B28 - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((D_800E5ED0 - 2) >= D_800E5ECC)) {
        temp_s1_3 = &D_801122A8[var_s7];
        D_800E5ECC[0].v.ob[0] = Math_Round(temp_s1_3->unk_00.x - (3.0f * temp_s1_3->unk_0C.x));
        D_800E5ECC[0].v.ob[1] = Math_Round(temp_s1_3->unk_00.y - (3.0f * temp_s1_3->unk_0C.y));
        D_800E5ECC[0].v.ob[2] = Math_Round(temp_s1_3->unk_00.z - (3.0f * temp_s1_3->unk_0C.z));
        D_800E5ECC[1].v.ob[0] = Math_Round(temp_s1_3->unk_00.x + temp_s1_3->unk_30.x);
        D_800E5ECC[1].v.ob[1] = Math_Round(temp_s1_3->unk_00.y + temp_s1_3->unk_30.y);
        D_800E5ECC[1].v.ob[2] = Math_Round(temp_s1_3->unk_00.z + temp_s1_3->unk_30.z);
        D_800E5ECC[2].v.ob[0] = Math_Round(temp_s1_3->unk_00.x - temp_s1_3->unk_30.x);
        D_800E5ECC[2].v.ob[1] = Math_Round(temp_s1_3->unk_00.y - temp_s1_3->unk_30.y);
        D_800E5ECC[2].v.ob[2] = Math_Round(temp_s1_3->unk_00.z - temp_s1_3->unk_30.z);

        D_800E5ECC[0].v.cn[0] = 0xFF;
        D_800E5ECC[0].v.cn[1] = D_800E5ECC[0].v.cn[2] = 0;
        D_800E5ECC[0].v.cn[3] = 0;
        D_800E5ECC[1].v.cn[0] = D_800E5ECC[2].v.cn[0] = D_800E5ECC[1].v.cn[1] = D_800E5ECC[2].v.cn[1] = 0xFF;
        D_800E5ECC[1].v.cn[2] = D_800E5ECC[2].v.cn[2] = 0;
        D_800E5ECC[1].v.cn[3] = D_800E5ECC[2].v.cn[3] = 0xFF;
        gSPVertex(gfx++, D_800E5ECC, 3, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);

        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
        D_800E5ECC += 3;
    }

    gSPDisplayList(gfx++, D_4008028);

    var_s3_6 = D_80111CF4;
    var_s7 = (D_80111CF0 - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((D_800E5ED0 - 3) >= D_800E5ECC)) {
        temp_s1_4 = &D_80111870[var_s7];
        temp_v0_14 = temp_s1_4->unk_20;
        if (temp_v0_14->unk_2B3 != 0) {
            temp_fv1_6 = SQ(temp_s1_4->unk_1C - 1) * -0.15f;
            temp_fs4 = temp_s1_4->unk_00.x + (temp_fv1_6 * temp_v0_14->unk_C0.y.x);
            temp_fs5 = temp_s1_4->unk_00.y + (temp_fv1_6 * temp_v0_14->unk_C0.y.y);
            sp54C = temp_s1_4->unk_00.z + (temp_fv1_6 * temp_v0_14->unk_C0.y.z);

            temp_fv0_16 = temp_s1_4->unk_18;
            temp_fs1 = temp_fv0_16 * sp56C;
            temp_fs3 = temp_fv0_16 * sp568;
            temp_fs2 = temp_fv0_16 * sp564;
            sp53C = temp_fv0_16 * sp560;
            sp538 = temp_fv0_16 * sp55C;
            sp534 = temp_fv0_16 * sp558;

            D_800E5ECC[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
            D_800E5ECC[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs3);
            D_800E5ECC[0].v.ob[2] = Math_Round(sp54C + temp_fs2);
            D_800E5ECC[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
            D_800E5ECC[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs3);
            D_800E5ECC[2].v.ob[2] = Math_Round(sp54C - temp_fs2);
            D_800E5ECC[1].v.ob[0] = Math_Round(temp_fs4 + sp53C);
            D_800E5ECC[1].v.ob[1] = Math_Round(temp_fs5 + sp538);
            D_800E5ECC[1].v.ob[2] = Math_Round(sp54C + sp534);
            D_800E5ECC[3].v.ob[0] = Math_Round(temp_fs4 - sp53C);
            D_800E5ECC[3].v.ob[1] = Math_Round(temp_fs5 - sp538);
            D_800E5ECC[3].v.ob[2] = Math_Round(sp54C - sp534);
            D_800E5ECC[0].v.tc[0] = D_800E5ECC[1].v.tc[0] = D_800E5ECC[1].v.tc[1] = D_800E5ECC[2].v.tc[1] = 0;
            D_800E5ECC[0].v.tc[1] = D_800E5ECC[2].v.tc[0] = D_800E5ECC[3].v.tc[0] = D_800E5ECC[3].v.tc[1] = 0x7FF;

            gSPTexture(gfx++, 0x8000, 0x8000, 0, temp_s1_4->unk_1C >> 1, G_ON);
            gSPVertex(gfx++, D_800E5ECC, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1_4->unk_1C * 8), 255);
            gDPSetEnvColor(gfx++, 255, 255 - (temp_s1_4->unk_1C * 16), 0, 255 - (temp_s1_4->unk_1C * 4));
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            D_800E5ECC += 4;
        }
        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
    }

    gSPDisplayList(gfx++, D_4008130);

    var_s3_6 = D_80112FB4;
    var_s7 = (D_80112FB0 - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((D_800E5ED0 - 3) >= D_800E5ECC)) {
        temp_s1_5 = &D_80112B30[var_s7];
        if (temp_s1_5->unk_20->unk_2B3 != 0) {
            temp_fv0_17 = temp_s1_5->unk_18;
            temp_fs1 = temp_fv0_17 * sp56C;
            temp_fs3 = temp_fv0_17 * sp568;
            temp_fs2 = temp_fv0_17 * sp564;
            sp53C = temp_fv0_17 * sp560;
            sp538 = temp_fv0_17 * sp55C;
            sp534 = temp_fv0_17 * sp558;
            D_800E5ECC[0].v.ob[0] = Math_Round(temp_s1_5->unk_00.x + temp_fs1);
            D_800E5ECC[0].v.ob[1] = Math_Round(temp_s1_5->unk_00.y + temp_fs3);
            D_800E5ECC[0].v.ob[2] = Math_Round(temp_s1_5->unk_00.z + temp_fs2);
            D_800E5ECC[2].v.ob[0] = Math_Round(temp_s1_5->unk_00.x - temp_fs1);
            D_800E5ECC[2].v.ob[1] = Math_Round(temp_s1_5->unk_00.y - temp_fs3);
            D_800E5ECC[2].v.ob[2] = Math_Round(temp_s1_5->unk_00.z - temp_fs2);
            D_800E5ECC[1].v.ob[0] = Math_Round(temp_s1_5->unk_00.x + sp53C);
            D_800E5ECC[1].v.ob[1] = Math_Round(temp_s1_5->unk_00.y + sp538);
            D_800E5ECC[1].v.ob[2] = Math_Round(temp_s1_5->unk_00.z + sp534);
            D_800E5ECC[3].v.ob[0] = Math_Round(temp_s1_5->unk_00.x - sp53C);
            D_800E5ECC[3].v.ob[1] = Math_Round(temp_s1_5->unk_00.y - sp538);
            D_800E5ECC[3].v.ob[2] = Math_Round(temp_s1_5->unk_00.z - sp534);
            D_800E5ECC[0].v.tc[0] = D_800E5ECC[1].v.tc[0] = D_800E5ECC[1].v.tc[1] = D_800E5ECC[2].v.tc[1] = 0;
            D_800E5ECC[0].v.tc[1] = D_800E5ECC[2].v.tc[0] = D_800E5ECC[3].v.tc[0] = D_800E5ECC[3].v.tc[1] = 0x7FF;
            gSPTexture(gfx++, 0x8000, 0x8000, 0, temp_s1_5->unk_1C >> 1, G_ON);
            gSPVertex(gfx++, D_800E5ECC, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetEnvColor(gfx++, 180, 150, 100, 230 - (temp_s1_4->unk_1C * 4));
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            D_800E5ECC += 4;
        }
        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
    }

    gSPDisplayList(gfx++, D_4008180);

    if (D_800DCE5C == 0) {
        var_s3_6 = gGameFrameCount & 7;
    } else {
        var_s3_6 = 0;
    }

    racer = D_800E5EC4;
    while ((racer >= gRacers) && ((D_800E5ED0 - 3) >= D_800E5ECC)) {
        if ((racer->unk_224 != 0.0f) && (racer->unk_2B3 != 0)) {
            temp_fs0_14 = 3.0f - ((1.0f - racer->unk_224) * 19.0f);
            temp_fs4 = racer->unk_0C.unk_34.x + (temp_fs0_14 * racer->unk_C0.y.x);
            temp_fs5 = racer->unk_0C.unk_34.y + (temp_fs0_14 * racer->unk_C0.y.y);
            temp_fs0_15 = racer->unk_224 * 38.0f;
            sp54C = racer->unk_0C.unk_34.z + (temp_fs0_14 * racer->unk_C0.y.z);
            temp_fs1 = temp_fs0_15 * sp56C;
            temp_fs3 = temp_fs0_15 * sp568;
            temp_fs2 = temp_fs0_15 * sp564;
            temp_fs0_15 = racer->unk_224 * 40.0f;
            D_800E5ECC[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
            D_800E5ECC[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs3);
            D_800E5ECC[0].v.ob[2] = Math_Round(sp54C + temp_fs2);
            D_800E5ECC[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
            D_800E5ECC[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs3);
            D_800E5ECC[2].v.ob[2] = Math_Round(sp54C - temp_fs2);
            temp_fs1 = temp_fs0_15 * sp560;
            D_800E5ECC[1].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
            temp_fs2 = temp_fs0_15 * sp55C;
            D_800E5ECC[1].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
            temp_fs3 = temp_fs0_15 * sp558;
            D_800E5ECC[1].v.ob[2] = Math_Round(sp54C + temp_fs3);
            D_800E5ECC[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
            D_800E5ECC[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
            D_800E5ECC[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
            D_800E5ECC[2].v.tc[0] = D_800E5ECC[3].v.tc[0] = D_800E5ECC[3].v.tc[1] = D_800E5ECC[0].v.tc[1] = 0x20;
            D_800E5ECC[2].v.tc[1] = D_800E5ECC[0].v.tc[0] = D_800E5ECC[1].v.tc[0] = D_800E5ECC[1].v.tc[1] = 0x7E0;
            gSPTexture(gfx++, 0x8000, 0x8000, 0, var_s3_6, G_ON);
            gSPVertex(gfx++, D_800E5ECC, 4, 0);
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            D_800E5ECC += 4;
        }
        racer--;
    }

    gSPDisplayList(gfx++, D_40081D8);

    var_s3_6 = D_8011313C;
    var_s7 = (D_80113138 - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((D_800E5ED0 - 7) >= D_800E5ECC)) {
        temp_s1_6 = &D_80112FB8[var_s7];
        racer = temp_s1_6->unk_08;
        temp_s4 = temp_s1_6->unk_04 - 5;
        if (temp_s1_6->unk_04 == 0) {
            break;
        }

        if ((temp_s4 >= 0) && (temp_s4 < 60)) {
            f32 temp;
            if ((D_800E5ED0 - 3) < D_800E5ECC) {
                break;
            }

            temp = SIN(((s32) (temp_s4 << 0xA) / 60)) * 163.64f;

            if (temp_s4 < 20) {
                sp5C4 = 255;
            } else {
                sp5C4 = (s32) ((60 - temp_s4) * 255) / 40;
            }

            temp_fs0_15 = temp * temp_s1_6->unk_00;
            temp_fs1 = temp_fs0_15 * sp56C;
            D_800E5ECC[0].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x + temp_fs1);
            temp_fs2 = temp_fs0_15 * sp568;
            D_800E5ECC[0].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y + temp_fs2);
            temp_fs3 = temp_fs0_15 * sp564;
            D_800E5ECC[0].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z + temp_fs3);
            D_800E5ECC[2].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x - temp_fs1);
            D_800E5ECC[2].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y - temp_fs2);
            D_800E5ECC[2].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z - temp_fs3);
            temp_fs1 = temp_fs0_15 * sp560;
            D_800E5ECC[1].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x + temp_fs1);
            temp_fs2 = temp_fs0_15 * sp55C;
            D_800E5ECC[1].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y + temp_fs2);
            temp_fs3 = temp_fs0_15 * sp558;
            D_800E5ECC[1].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z + temp_fs3);
            D_800E5ECC[3].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x - temp_fs1);
            D_800E5ECC[3].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y - temp_fs2);
            D_800E5ECC[3].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z - temp_fs3);
            D_800E5ECC[0].v.tc[0] = D_800E5ECC[1].v.tc[0] = D_800E5ECC[1].v.tc[1] = D_800E5ECC[2].v.tc[1] = 0x40;
            D_800E5ECC[0].v.tc[1] = D_800E5ECC[2].v.tc[0] = D_800E5ECC[3].v.tc[0] = D_800E5ECC[3].v.tc[1] = 0x1FBF;
            gSPTexture(gfx++, 0x8000, 0x8000, 0, 0, G_ON);
            gSPVertex(gfx++, D_800E5ECC, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, sp5C4, 80, 255);
            gDPSetEnvColor(gfx++, sp5C4, 0, 0, sp5C4);
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            D_800E5ECC += 4;
        }

        if (temp_s1_6->unk_04 < 0x1A) {
            if ((D_800E5ED0 - 3) < D_800E5ECC) {
                break;
            }
            temp_fs0_18 = (temp_s1_6->unk_00 * 163.64f * (f32) temp_s1_6->unk_04) / 26.0f;
            temp_fs1 = racer->unk_C0.x.x * temp_fs0_18;
            temp_fs3 = racer->unk_C0.x.y * temp_fs0_18;
            temp_fs2 = racer->unk_C0.x.z * temp_fs0_18;
            sp53C = racer->unk_C0.z.x * temp_fs0_18;
            sp538 = racer->unk_C0.z.y * temp_fs0_18;
            sp534 = racer->unk_C0.z.z * temp_fs0_18;
            D_800E5ECC[0].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x + temp_fs1);
            D_800E5ECC[0].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y + temp_fs3);
            D_800E5ECC[0].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z + temp_fs2);
            D_800E5ECC[2].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x - temp_fs1);
            D_800E5ECC[2].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y - temp_fs3);
            D_800E5ECC[2].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z - temp_fs2);
            D_800E5ECC[1].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x + sp53C);
            D_800E5ECC[1].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y + sp538);
            D_800E5ECC[1].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z + sp534);
            D_800E5ECC[3].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x - sp53C);
            D_800E5ECC[3].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y - sp538);
            D_800E5ECC[3].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z - sp534);
            D_800E5ECC[2].v.tc[1] = 0x40;

            D_800E5ECC[0].v.tc[0] = D_800E5ECC[1].v.tc[0] = D_800E5ECC[1].v.tc[1] = D_800E5ECC[2].v.tc[1];
            D_800E5ECC[3].v.tc[1] = 0x1FBF;
            D_800E5ECC[0].v.tc[1] = D_800E5ECC[2].v.tc[0] = D_800E5ECC[3].v.tc[0] = D_800E5ECC[3].v.tc[1];
            gSPTexture(gfx++, 0x8000, 0x8000, 0, 1, G_ON);
            gSPVertex(gfx++, D_800E5ECC, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 100, 255, 255, 255);
            gDPSetEnvColor(gfx++, 0, 0, 255, (((26 - temp_s1_6->unk_04) * 255) / 26));
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            D_800E5ECC += 4;
        }

        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
    }

    if (D_800F5E98 != 0) {
        gSPDisplayList(gfx++, D_400A258);

        gSPMatrix(gfx++, &D_1000000.unk_21988[playerIndex], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPDisplayList(gfx++, aCountdownSignDL);

        if (((D_800F5E98 <= 220) && (D_800F5E98 >= 210)) || ((D_800F5E98 <= 160) && (D_800F5E98 >= 150)) ||
            ((D_800F5E98 <= 100) && (D_800F5E98 >= 90)) || (D_800F5E98 <= 40)) {
            var_s2 = aCountdownMrZeroMouthOpenTex;
        } else {
            var_s2 = aCountdownMrZeroMouthClosedTex;
        }

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                            G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

        gSPDisplayList(gfx++, D_400A480);

        if (D_800F5E98 > 220) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        } else {
            if (D_800F5E98 > 160) {
                var_s2 = aCountdown3Tex;
                if ((playerIndex == 0) && (D_800DCE5C == 0) && (D_800F5E98 == 220)) {
                    func_800BA8D8(0x2F);
                }
            } else if (D_800F5E98 > 100) {
                var_s2 = aCountdown2Tex;
                if ((playerIndex == 0) && (D_800DCE5C == 0) && (D_800F5E98 == 160)) {
                    func_800BA8D8(9);
                }
            } else if (D_800F5E98 > 40) {
                var_s2 = aCountdown1Tex;
                if ((playerIndex == 0) && (D_800DCE5C == 0) && (D_800F5E98 == 100)) {
                    func_800BA8D8(0xA);
                }
            } else {
                var_s2 = aCountdownGoTex;
                if ((playerIndex == 0) && (D_800DCE5C == 0)) {
                    if (D_800F5E98 == 40) {
                        func_800BA8D8(0xB);
                    }
                    if ((D_800F5E98 == 1) && (D_800CD010 == 0)) {
                        if (gCurrentCourseRecordInfo->unk_04 < 24) {
                            func_8007E0AC(D_800CF4D8[gCurrentCourseRecordInfo->unk_04]);
                        } else if (gCurrentCourseRecordInfo->unk_04 == 48) {
                            func_8007E0AC(0x18);
                        } else {
                            func_8007E0AC(D_800CF4F0[gCourseData.venue]);
                        }
                    }
                }
            }

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                                G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
        }
        gSPVertex(gfx++, D_400AA28, 4, 0);
        gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    } else if ((D_800E5EC0 >= 2) && !(sp9C->stateFlags & (RACER_STATE_FLAGS_2000000 | RACER_STATE_FLAGS_40000)) && (gGameMode != GAMEMODE_GP_END_CS)) {
        gSPDisplayList(gfx++, D_4007EA8);
        if ((gGameMode != GAMEMODE_PRACTICE) && (gGameMode != GAMEMODE_DEATH_RACE)) {
            if (D_800E5EC0 < 3) {
                var_s4_5 = D_800E5EC0;
            } else {
                var_s4_5 = 3;
            }

            for (i = 0; i < var_s4_5; i++) {

                racer = D_800E5F40[i];
                if (racer->unk_2B4 != 0) {
                    if ((playerIndex != racer->id) && !(racer->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_2000000))) {
                        if (racer->id < playerIndex) {
                            var_s7 = ((s32) ((playerIndex - 1) * playerIndex) >> 1) + racer->id;
                        } else {
                            var_s7 = ((s32) (racer->id * (racer->id - 1)) >> 1) + playerIndex;
                        }

                        if ((D_800F5EA0[var_s7].unk_08 < 800.0f)) {
                            continue;
                        }

                        temp_fs4 = racer->unk_0C.unk_34.x + (20.0f * racer->unk_C0.y.x);
                        temp_fs5 = racer->unk_0C.unk_34.y + (20.0f * racer->unk_C0.y.y);
                        temp_fv0_19 = racer->unk_0C.unk_34.z + (20.0f * racer->unk_C0.y.z);
                        temp_fv1_7 =
                            1.0f / (spA4->unk_19C.ww + ((spA4->unk_19C.wx * temp_fs4) + (spA4->unk_19C.wy * temp_fs5) +
                                                        (spA4->unk_19C.wz * temp_fv0_19)));
                        sp56C = (spA4->unk_19C.xw + ((spA4->unk_19C.xx * temp_fs4) + (spA4->unk_19C.xy * temp_fs5) +
                                                     (spA4->unk_19C.xz * temp_fv0_19))) *
                                temp_fv1_7;
                        sp568 = (spA4->unk_19C.yw + ((spA4->unk_19C.yx * temp_fs4) + (spA4->unk_19C.yy * temp_fs5) +
                                                     (spA4->unk_19C.yz * temp_fv0_19))) *
                                temp_fv1_7;
                        sp564 = (spA4->unk_19C.zw + ((spA4->unk_19C.zx * temp_fs4) + (spA4->unk_19C.zy * temp_fs5) +
                                                     (spA4->unk_19C.zz * temp_fv0_19))) *
                                temp_fv1_7;
                        gDPPipeSync(gfx++);
                        gDPSetPrimDepth(gfx++, (s32) ((sp564 * 16352.0f) + 16352.0f), 0);

                        if (gNumPlayers < 2) {
                            gDPLoadTextureBlock(gfx++, D_800CDAA0[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 30, 0,
                                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                                                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                            temp_s7_7 = ((s32) ((spA4->unk_E8 * sp56C) + spA4->unk_F0 + 0.5f) - 0xC) << 2;
                            sp5C4 = ((s32) ((-spA4->unk_EC * sp568) + spA4->unk_F4 + 0.5f) - 0x1E) << 2;
                            gSPScisTextureRectangle(gfx++, temp_s7_7, sp5C4, temp_s7_7 + (24 * 4 - 1),
                                                    sp5C4 + (30 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                        } else {
                            gDPLoadTextureBlock(gfx++, D_800CDAAC[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                                                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                            temp_s7_7 = ((s32) ((spA4->unk_E8 * sp56C) + spA4->unk_F0 + 0.5f) - 8) << 2;
                            sp5C4 = ((s32) ((-spA4->unk_EC * sp568) + spA4->unk_F4 + 0.5f) - 0x10) << 2;
                            gSPScisTextureRectangle(gfx++, temp_s7_7, sp5C4, temp_s7_7 + (16 * 4 - 1),
                                                    sp5C4 + (16 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                        }
                    }
                }
            }
            if ((gGameMode == GAMEMODE_GP_RACE) && (D_800E5EC8 != NULL) && (D_800E5EC8->unk_2B4 != 0) &&
                !(D_800E5EC8->stateFlags & (RACER_STATE_FLAGS_8000000 | RACER_STATE_FLAGS_2000000)) && (gRacers[0].position >= D_800E5EC8->position)) {
                temp_fs4 = D_800E5EC8->unk_0C.unk_34.x + (20.0f * D_800E5EC8->unk_C0.y.x);
                temp_fs5 = D_800E5EC8->unk_0C.unk_34.y + (20.0f * D_800E5EC8->unk_C0.y.y);
                temp_fv0_19 = D_800E5EC8->unk_0C.unk_34.z + (20.0f * D_800E5EC8->unk_C0.y.z);
                temp_fv1_7 = 1.0f / (spA4->unk_19C.ww + ((spA4->unk_19C.wx * temp_fs4) + (spA4->unk_19C.wy * temp_fs5) +
                                                         (spA4->unk_19C.wz * temp_fv0_19)));
                sp56C = (spA4->unk_19C.xw + ((spA4->unk_19C.xx * temp_fs4) + (spA4->unk_19C.xy * temp_fs5) +
                                             (spA4->unk_19C.xz * temp_fv0_19))) *
                        temp_fv1_7;
                sp568 = (spA4->unk_19C.yw + ((spA4->unk_19C.yx * temp_fs4) + (spA4->unk_19C.yy * temp_fs5) +
                                             (spA4->unk_19C.yz * temp_fv0_19))) *
                        temp_fv1_7;
                sp564 = (spA4->unk_19C.zw + ((spA4->unk_19C.zx * temp_fs4) + (spA4->unk_19C.zy * temp_fs5) +
                                             (spA4->unk_19C.zz * temp_fv0_19))) *
                        temp_fv1_7;
                gDPPipeSync(gfx++);
                gDPSetPrimDepth(gfx++, (s32) ((sp564 * 16352.0f) + 16352.0f), 0);
                gDPLoadTextureBlock(gfx++, aRivalMarkerTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);

                temp_s7_7 = ((s32) ((spA4->unk_E8 * sp56C) + spA4->unk_F0 + 0.5f) - 0x10) << 2;
                sp5C4 = ((s32) ((-spA4->unk_EC * sp568) + spA4->unk_F4 + 0.5f) - 0x10) << 2;
                gSPScisTextureRectangle(gfx++, temp_s7_7, sp5C4, temp_s7_7 + (32 * 4 - 1), sp5C4 + (16 * 4 - 1), 0, 0,
                                        0, 1 << 10, 1 << 10);
            }
            gDPPipeSync(gfx++);
        }

        gDPSetDepthSource(gfx++, G_ZS_PIXEL);

        if (sp9C->unk_2C4 < 3000.0f) {
            temp_v0_27 = sp9C->unk_2BC;
            if ((temp_v0_27->position == (sp9C->position + 1)) && !(temp_v0_27->stateFlags & RACER_STATE_FLAGS_40000)) {
                temp_fa0_6 = sp9C->unk_0C.unk_34.x - temp_v0_27->unk_0C.unk_34.x;
                temp_fv1_9 = sp9C->unk_0C.unk_34.y - temp_v0_27->unk_0C.unk_34.y;
                sp564 = sp9C->unk_0C.unk_34.z - temp_v0_27->unk_0C.unk_34.z;
                if ((((spA4->unk_5C.x.x * temp_fa0_6) + (temp_fv1_9 * spA4->unk_5C.x.y) + (sp564 * spA4->unk_5C.x.z)) <
                     0.0f)) {
                    goto end;
                }
                var_fs1 =
                    (spA4->unk_5C.z.x * temp_fa0_6) + (temp_fv1_9 * spA4->unk_5C.z.y) + (sp564 * spA4->unk_5C.z.z);
                var_fs3 =
                    (spA4->unk_5C.y.x * temp_fa0_6) + (temp_fv1_9 * spA4->unk_5C.y.y) + (sp564 * spA4->unk_5C.y.z);
                temp_fv0_21 = SQ(var_fs1) + SQ(var_fs3);

                if ((temp_fv0_21 < 0.1f)) {
                    goto end;
                }
                temp_fa1_4 = ((spA4->unk_B8 - spA4->unk_B0) * 0.5f) + 4.0f;
                sp568 = ((spA4->unk_BC - spA4->unk_B4) * 0.5f) - 4.0f;
                temp_fv0_22 = sqrtf((SQ(temp_fa1_4) + SQ(sp568)) / temp_fv0_21);
                var_fs1 *= temp_fv0_22;
                var_fs3 *= temp_fv0_22;
                if (sp568 < var_fs3) {
                    temp_fv0_22 = sp568 / var_fs3;
                    var_fs1 *= temp_fv0_22;
                    var_fs3 *= temp_fv0_22;
                }

                gSPClearGeometryMode(gfx++, G_ZBUFFER);
                gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

                if (D_800DCE5C != 0) {
                    var_s7 = 255;
                } else {
                    var_s7 = 255 - ((gGameFrameCount & 0xF) * 0x10);
                }

                gDPSetPrimColor(gfx++, 0, 0, 255, var_s7, 0, (255 - (s32) (sp9C->unk_2C4 * 0.085f)));

                if (gNumPlayers < 2) {
                    gDPLoadTextureBlock_4b(gfx++, aCheckMarkerTex, G_IM_FMT_IA, 32, 23, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                    temp_s7_7 = ((s32) (((spA4->unk_B0 + spA4->unk_B8) * 0.5f) + var_fs1 + 0.5f) - 0x10) << 2;
                    temp_a3_4 = ((s32) (((spA4->unk_B4 + spA4->unk_BC) * 0.5f) + var_fs3 + 0.5f) - 0x1C) << 2;

                    gSPScisTextureRectangle(gfx++, temp_s7_7, temp_a3_4, temp_s7_7 + (32 * 4 - 1),
                                            temp_a3_4 + (23 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                } else {
                    gDPLoadTextureBlock_4b(gfx++, aDownMarkerTex, G_IM_FMT_IA, 16, 10, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                    temp_s7_7 = ((s32) (((spA4->unk_B0 + spA4->unk_B8) * 0.5f) + var_fs1 + 0.5f) - 8) << 2;
                    temp_a3_4 = ((s32) (((spA4->unk_B4 + spA4->unk_BC) * 0.5f) + var_fs3 + 0.5f) - 0xA) << 2;
                    gSPScisTextureRectangle(gfx++, temp_s7_7, temp_a3_4, temp_s7_7 + (16 * 4 - 1),
                                            temp_a3_4 + (10 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                }

                if ((gNumPlayers == 1) && (gGameMode != GAMEMODE_DEATH_RACE)) {
                    if (sp9C->unk_2C4 < 1000.0f) {
                        if (!(sp9C->unk_08 & 0x8000)) {
                            sp9C->unk_08 |= 0x8000;
                            if (D_800E5FD0 != 0) {
                                func_800BA8D8(0x3A);
                            }
                        }
                    } else if (sp9C->unk_2C4 > 2500.0f) {
                        sp9C->unk_08 &= ~0x8000;
                    }
                }
            }
        }
    }
end:
    return gfx;
}
#else
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/game/1B0E0/func_80096CE8.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1B0E0/func_80096CE8.s")
#endif
#endif

Gfx* func_8009CBE8(Gfx* gfx, s32 arg1, s32 red, s32 green, s32 blue) {
    u8 character;

    if (arg1 < 6) {
        character = D_800F8504[arg1 - 1];
    } else if (arg1 == 6) {
        character = D_800F8504[5];
    } else {
        character = D_800F8504[6];
    }

    gSPDisplayList(gfx++, D_800CDD38[character]);
    gDPSetEnvColor(gfx++, red, green, blue, 255);
    gSPDisplayList(gfx++, D_800CDDB0[character * 6]);
    return gfx;
}

Gfx* func_8009CCBC(Gfx* gfx, s32 character, s32 arg2) {
    unk_800CF1B0* temp_t0 = &D_800F80C8[character];

    gSPDisplayList(gfx++, D_800CDD38[character]);
    gDPSetEnvColor(gfx++, temp_t0->unk_04[arg2], temp_t0->unk_08[arg2], temp_t0->unk_0C[arg2], 255);
    gSPDisplayList(gfx++, D_800CDDB0[character * 6]);
    return gfx;
}

Gfx* func_8009CD60(Gfx* gfx, s32 character) {
    unk_800CF1B0* temp_v1 = &D_800F80C8[character];

    gDPLoadTextureBlock_4b(gfx++, D_800CDC54[temp_v1->unk_02], G_IM_FMT_I, 32, 64, 0, G_TX_MIRROR | G_TX_CLAMP,
                           G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);

    gSPVertex(gfx++, D_800CDBA4[temp_v1->unk_02], 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    return gfx;
}

Gfx* func_8009CE70(Gfx* gfx, s32 character) {
    gSPDisplayList(gfx++, D_800CDDB0[character * 6]);
    return gfx;
}

Gfx* func_8009CEA0(Gfx* gfx, s32 character) {
    gSPDisplayList(gfx++, D_800CDAD8[character]);
    return gfx;
}
