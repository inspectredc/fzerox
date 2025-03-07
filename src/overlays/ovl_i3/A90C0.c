#include "global.h"
#include "ovl_i3.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_course.h"
#include "assets/segment_2B9EA0.h"

s32 D_80141900;
s32 D_i3_80141904;
s32 D_i3_80141908;
s32 D_i3_8014190C;
Racer* D_i3_80141910;
UNUSED s32 D_i3_80141914;
s32 D_i3_80141918;
s32 D_i3_8014191C;
s32 D_i3_80141920;
s32 D_i3_80141924;
s32 D_i3_80141928;
s32 D_i3_8014192C;
s32 D_i3_80141930;
s32 D_i3_80141934;
s32 D_i3_80141938;
s32 D_i3_8014193C;
s32 D_i3_80141940;
s32 D_i3_80141944;
s32 D_i3_80141948;
s32 D_i3_8014194C;
s32 D_i3_80141950;
s32 D_i3_80141954;
s32 D_i3_80141958;
s32 D_i3_8014195C;
s32 D_i3_80141960;
s32 D_i3_80141964;
s32 D_i3_80141968;
s32 D_i3_8014196C;
s32 D_i3_80141970;
s32 D_i3_80141974;
s32 D_i3_80141978;
s32 D_i3_8014197C;
s32 D_i3_80141980;
s32 D_i3_80141984;
s32 D_i3_80141988;
s32 D_i3_8014198C;
s32 D_i3_80141990;
s32 D_i3_80141994;
s32 D_i3_80141998;

s16* D_i3_8013DB80[] = {
    D_F264110, D_F264340, D_F264450, D_F2641D8, D_F264690, D_F264540, D_F264920, D_F264860,
    D_F264740, D_F264C80, D_F264B40, D_F2652B0, D_F264DE0, D_F264F08, D_F2650B0, D_F2651C8,
    D_F264A58, D_F2656C8, D_F265530, D_F2659E0, D_F2658D0, D_F265B70, D_F2653E8, D_F265D08,
};

UNUSED Gfx D_i3_8013DBE0[] = { gsSPEndDisplayList() };

s16* D_i3_8013DBE8 = NULL;

s32 D_i3_8013DBEC = 0;

f32 D_i3_8013DBF0[] = { 0.99f, 0.98f, 0.96f, 0.94f, 0.0f };

f32 D_i3_8013DC04[] = { 0.99f, 0.98f, 0.96f, 0.94f, 0.0f };

f32 D_i3_8013DC18[] = {
    0.40f, 0.5f,  0.55f, 0.60f, 0.45f, 0.60f, 0.65f, 0.65f, 0.39f, 0.46f, 0.5f,  0.5f,  0.39f, 0.46f, 0.5f,  0.60f,
    0.41f, 0.5f,  0.5f,  0.55f, 0.38f, 0.44f, 0.5f,  0.60f, 0.39f, 0.42f, 0.5f,  0.55f, 0.41f, 0.55f, 0.60f, 1.0f,
    0.44f, 0.48f, 0.60f, 0.65f, 0.37f, 0.43f, 0.5f,  0.60f, 0.38f, 0.45f, 0.5f,  0.5f,  0.39f, 0.48f, 0.60f, 0.65f,
    0.45f, 0.5f,  0.60f, 1.0f,  0.38f, 0.5f,  0.55f, 0.60f, 0.40f, 0.45f, 0.5f,  0.70f, 0.36f, 0.37f, 0.45f, 0.5f,
    0.37f, 0.39f, 0.43f, 0.55f, 0.39f, 0.60f, 0.62f, 0.65f, 0.37f, 0.39f, 0.41f, 0.45f, 0.36f, 0.38f, 0.42f, 0.45f,
    0.38f, 0.39f, 0.42f, 0.55f, 0.38f, 0.40f, 0.43f, 0.60f, 0.36f, 0.38f, 0.5f,  0.55f, 0.40f, 0.5f,  1.0f,  1.0f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f, 0.39f, 0.41f, 0.43f, 0.45f,
    0.37f, 0.38f, 0.40f, 0.41f, 0.37f, 0.38f, 0.40f, 0.41f, 0.37f, 0.38f, 0.40f, 0.41f, 0.37f, 0.38f, 0.40f, 0.41f,
    0.37f, 0.38f, 0.40f, 0.41f, 0.37f, 0.38f, 0.40f, 0.41f, 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
    1.0f,  1.0f
};

f32 D_i3_8013DFA0[] = {
    0.0f,  0.0f,  0.25f, 0.68f, 0.0f,  0.02f, 0.35f, 0.73f, 0.0f,  0.02f, 0.1f,  0.35f, 0.0f,  0.0f,  0.2f,  0.55f,
    0.0f,  0.2f,  0.75,  1.0f,  0.0f,  0.0f,  0.1f,  0.3f,  0.0f,  0.0f,  0.0f,  0.3f,  0.0f,  0.15f, 0.70f, 1.6f,
    0.0f,  0.0f,  0.2f,  0.75,  0.0f,  0.0f,  0.1f,  0.6f,  0.0f,  0.2f,  0.5f,  0.6f,  0.0f,  0.1f,  0.5f,  0.9f,
    0.0f,  0.3f,  1.0f,  1.6f,  0.0f,  0.2f,  0.35f, 0.8f,  0.0f,  0.05f, 0.15f, 0.53f, 0.0f,  0.1f,  0.1f,  0.6f,
    0.0f,  0.1f,  0.1f,  0.33f, 0.0f,  0.2f,  0.5f,  1.4f,  0.0f,  0.15f, 0.2f,  0.24f, 0.0f,  0.1f,  0.3f,  0.55f,
    0.0f,  0.1f,  0.1f,  0.45f, 0.0f,  0.1f,  0.3f,  0.8f,  0.0f,  0.1f,  0.3f,  0.62f, 0.0f,  0.3f,  0.6f,  1.2f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,  0.05f, 0.15f, 0.22f, 0.3f,
    0.0f,  0.1f,  0.2f,  0.25f, 0.0f,  0.1f,  0.2f,  0.25f, 0.0f,  0.1f,  0.2f,  0.25f, 0.0f,  0.1f,  0.2f,  0.25f,
    0.0f,  0.1f,  0.2f,  0.25f, 0.0f,  0.1f,  0.2f,  0.25f, 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    0.0f,  0.0f,
};

u32 D_i3_8013E328[] = {
    107000, 99000,  90000,  82000,  91000,  82000,  76000,  70500,  93000,  83000,  78000,  74000,  99000,  92000,
    86000,  81500,  110000, 104000, 98500,  92000,  108000, 102000, 98000,  92500,  96000,  91000,  85000,  79500,
    97000,  90000,  83000,  76000,  102000, 96000,  89000,  83000,  90000,  85000,  82000,  78500,  77000,  73000,
    68500,  64500,  110000, 105000, 101000, 96500,  97000,  92000,  87000,  82500,  109000, 104000, 99500,  95500,
    120000, 114000, 108500, 103500, 118000, 112000, 106500, 102000, 86000,  83000,  77000,  72000,  121000, 116000,
    109000, 101000, 155000, 148000, 141000, 134500, 91000,  86000,  82500,  79000,  137000, 130000, 125000, 120500,
    114000, 108000, 102500, 97500,  125000, 120000, 114000, 109000, 161000, 155000, 148500, 143000,
};

u32 D_i3_8013E4A8[] = {
    35000, 33000, 32000, 30000, 31000, 29000, 27500, 26300, 28000, 27000, 26200, 24500, 29000, 28000, 26500, 26000,
    35000, 33500, 32000, 31000, 34000, 33000, 32000, 31000, 31000, 29500, 29000, 28000, 30500, 29000, 27500, 27000,
    33000, 32000, 29500, 28000, 30000, 28500, 27000, 26000, 23000, 22500, 21700, 21000, 35500, 34500, 34000, 33000,
    30000, 29500, 28000, 27500, 35000, 34000, 33000, 31000, 38000, 37000, 36000, 35000, 37000, 36000, 34500, 33000,
    25500, 24500, 23500, 22000, 40000, 38000, 36000, 34000, 51000, 49000, 47000, 45500, 31000, 29000, 27500, 26000,
    44000, 42000, 40000, 39000, 35500, 34000, 32500, 31500, 40000, 39000, 38000, 37000, 51000, 49500, 48500, 47000,
};

u32 D_i3_8013E628[] = {
    350, 300, 250, 200, 400, 350, 270, 200, 400, 350, 300, 300, 600, 500, 350, 300, 450, 350, 300, 250,
    400, 300, 250, 200, 300, 280, 250, 230, 600, 500, 250, 150, 400, 350, 300, 250, 500, 350, 330, 300,
    500, 400, 300, 250, 500, 400, 350, 250, 600, 500, 300, 250, 600, 500, 450, 350, 400, 350, 300, 280,
    500, 500, 500, 500, 450, 400, 350, 350, 250, 240, 220, 200, 450, 400, 350, 300, 300, 290, 270, 250,
    500, 450, 350, 300, 550, 450, 300, 250, 600, 500, 400, 300, 550, 400, 350, 300,
};

unk_8013E7A8 D_i3_8013E7A8[] = {
    // CAPTAIN_FALCON
    { 61, 4, { BLACK_SHADOW, BLOOD_FALCON, -1 }, { DR_STEWART, PICO, ROGER_BUSTER, DRAQ, SAMURAI_GOROH, -1, -1, -1 } },
    // DR_STEWART
    { 63, 5, { -1, -1, -1 }, { BLACK_SHADOW, SAMURAI_GOROH, ROGER_BUSTER, DRAQ, PICO, -1, -1, -1 } },
    // PICO
    { 61, 3, { -1, -1, -1 }, { DR_STEWART, BLACK_SHADOW, MICHAEL_CHAIN, ROGER_BUSTER, DRAQ, ANTONIO_GUSTER, -1, -1 } },
    // SAMURAI_GOROH
    { 61, 1, { ANTONIO_GUSTER, -1, -1 }, { BLACK_SHADOW, BLOOD_FALCON, CAPTAIN_FALCON, PICO, -1, -1, -1, -1 } },
    // JODY_SUMMER
    { 6, 3, { OCTOMAN, -1, -1 }, { ZODA, MRS_ARROW, JACK_LEVIN, BABA, SUPER_ARROW, -1, -1, -1 } },
    // MIGHTY_GAZELLE
    { 7, 5, { -1, -1, -1 }, { MR_EAD, THE_SKULL, DR_CLASH, -1, -1, -1, -1, -1 } },
    // MR_EAD
    { 4, 1, { -1, -1, -1 }, { MIGHTY_GAZELLE, JAMES_MCCLOUD, DR_CLASH, SILVER_NEELSEN, LEON, THE_SKULL, BILLY, -1 } },
    // BABA
    { 4, 1, { -1, -1, -1 }, { JODY_SUMMER, MRS_ARROW, KATE_ALEN, JACK_LEVIN, -1, -1, -1, -1 } },
    // OCTOMAN
    { 4, 2, { JODY_SUMMER, -1, -1 }, { JOHN_TANAKA, BABA, KATE_ALEN, GOMAR_AND_SHIOH, SUPER_ARROW, -1, -1, -1 } },
    // GOMAR_AND_SHIOH
    { 6, 2, { -1, -1, -1 }, { SUPER_ARROW, MRS_ARROW, JOHN_TANAKA, JODY_SUMMER, OCTOMAN, JACK_LEVIN, -1, -1 } },
    // KATE_ALEN
    { 6, 3, { -1, -1, -1 }, { BABA, MRS_ARROW, JACK_LEVIN, -1, -1, -1, -1, -1 } },
    // ROGER_BUSTER
    { 6, 4, { -1, -1, -1 }, { DR_STEWART, MICHAEL_CHAIN, BLOOD_FALCON, ANTONIO_GUSTER, -1, -1, -1, -1 } },
    // JAMES_MCCLOUD
    { 29, 4, { -1, -1, -1 }, { BIO_REX, BILLY, LEON, SILVER_NEELSEN, THE_SKULL, MIGHTY_GAZELLE, MR_EAD, -1 } },
    // LEON
    { 5, 4, { -1, -1, -1 }, { BILLY, BEASTMAN, MIGHTY_GAZELLE, -1, -1, -1, -1, -1 } },
    // ANTONIO_GUSTER
    { 6, 4, { SAMURAI_GOROH, -1, -1 }, { DRAQ, ROGER_BUSTER, BLOOD_FALCON, MICHAEL_CHAIN, -1, -1, -1, -1 } },
    // BLACK_SHADOW
    { 61, 3, { -1, -1, -1 }, { CAPTAIN_FALCON, MICHAEL_CHAIN, PICO, DR_STEWART, -1, -1, -1, CAPTAIN_FALCON } },
    // MICHAEL_CHAIN
    { 4, 0, { -1, -1, -1 }, { PICO, BLACK_SHADOW, ANTONIO_GUSTER, -1, -1, -1, -1, -1 } },
    // JACK_LEVIN
    { 29, 5, { -1, -1, -1 }, { KATE_ALEN, JODY_SUMMER, JOHN_TANAKA, ZODA, GOMAR_AND_SHIOH, -1, -1, -1 } },
    // SUPER_ARROW
    { 63, 1, { ZODA, -1, -1 }, { GOMAR_AND_SHIOH, JOHN_TANAKA, -1, -1, -1, -1, -1, -1 } },
    // MRS_ARROW
    { 7, 4, { -1, -1, -1 }, { ZODA, GOMAR_AND_SHIOH, KATE_ALEN, OCTOMAN, BABA, -1, -1, -1 } },
    // JOHN_TANAKA
    { 6, 1, { -1, -1, -1 }, { OCTOMAN, SUPER_ARROW, ZODA, KATE_ALEN, BABA, JACK_LEVIN, GOMAR_AND_SHIOH, -1 } },
    // BEASTMAN
    { 6, 0, { LEON, BILLY, -1 }, { SILVER_NEELSEN, THE_SKULL, BIO_REX, -1, -1, -1, -1, -1 } },
    // ZODA
    { 29, 0, { SUPER_ARROW, -1, -1 }, { MRS_ARROW, OCTOMAN, JOHN_TANAKA, JODY_SUMMER, -1, -1, -1, -1 } },
    // DR_CLASH
    { 4, 1, { -1, -1, -1 }, { BIO_REX, BILLY, MR_EAD, SILVER_NEELSEN, -1, -1, -1, -1 } },
    // SILVER_NEELSEN
    { 6, 5, { -1, -1, -1 }, { DR_CLASH, LEON, BEASTMAN, BIO_REX, JAMES_MCCLOUD, MR_EAD, -1, -1 } },
    // BIO_REX
    { 36, 3, { -1, -1, -1 }, { THE_SKULL, BEASTMAN, DR_CLASH, SILVER_NEELSEN, -1, -1, -1, -1 } },
    // DRAQ
    { 6, 2, { -1, -1, -1 }, { MICHAEL_CHAIN, ANTONIO_GUSTER, DR_STEWART, BLOOD_FALCON, -1, -1, -1, -1 } },
    // BILLY
    { 4, 2, { -1, -1, -1 }, { LEON, BEASTMAN, JAMES_MCCLOUD, MIGHTY_GAZELLE, -1, -1, -1, -1 } },
    // THE_SKULL
    { 5, 3, { -1, -1, -1 }, { MIGHTY_GAZELLE, BIO_REX, BEASTMAN, DR_CLASH, JAMES_MCCLOUD, MR_EAD, -1, -1 } },
    // BLOOD_FALCON
    { 5, 0, { -1, -1, -1 }, { CAPTAIN_FALCON, SAMURAI_GOROH, DRAQ, ROGER_BUSTER, -1, -1, -1, -1 } },
};

// fabsf
f32 func_i3_fabsf(f32 num) {
    if (num < 0.0f) {
        return 0.0f - num;
    }
    return num;
}

// abs
s32 func_i3_abs(s32 num) {
    if (num < 0) {
        return -num;
    }
    return num;
}

void func_i3_80115E34(Racer* arg0) {

    arg0->unk_34D = (arg0->id % 5) + 2;
    if ((arg0->id < 15) && (arg0->unk_34D == 2)) {
        arg0->unk_34D = 1;
    }
}

s16 D_i3_8013E94C[] = {
    0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000,
};

extern s32 gGameMode;
extern s32 gDifficulty;
extern s32 gNumPlayers;
extern s32 gCourseIndex;
extern s8 D_800CD010;
extern s32 D_800E5EC0;
extern s32 D_800E5FF0;
extern s16 D_80115D50[];

#ifdef NON_EQUIVALENT
// close with fakes in https://decomp.me/scratch/NV0Rp
void func_i3_80115E74(void) {
    s32 sp70[1];
    s32 i; // s3
    s32 j; // s1
    s32 k;
    s32 l;
    Racer* var_s0;
    Racer* var_s2;
    s32 var_v0_5;
    s32 var_s0_3;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a3_2;
    s32 var_s0_2;
    s8 var_a3;
    s32 temp_hi;
    s32 temp1;
    s32 temp2;
    u32 var_s5;
    s32 temp_a0;

    if ((gGameMode == GAMEMODE_GP_END_CS) || (gGameMode == GAMEMODE_DEATH_RACE) || (gGameMode == GAMEMODE_PRACTICE)) {
        D_i3_80141998 = 1;
    } else {
        D_i3_80141998 = 0;
    }
    D_i3_8014190C = D_i3_80141908 = 0;
    D_i3_80141910 = gRacers;

    for (i = 0; i < D_800E5EC0; i++) {
        gRacers[i].id = i;
    }

    if ((gGameMode != GAMEMODE_GP_RACE) || (D_800E5FF0 == 1) || (D_800CD010 == 1) || (D_i3_8013DBEC != 0) ||
        (gNumPlayers >= 2)) {
        var_s0 = gRacers;
        while (var_s0 < &gRacers[D_800E5EC0]) {
            switch (gGameMode) {
                case GAMEMODE_GP_RACE:
                case GAMEMODE_PRACTICE:
                case GAMEMODE_TIME_ATTACK:
                case GAMEMODE_DEATH_RACE:
                    func_i3_80115E34(var_s0);
                    break;
                case GAMEMODE_RECORDS:
                case GAMEMODE_GP_END_CS:
                    var_s0->unk_34D = 1;
                    break;
                default:
                    var_s0->unk_34D = -1;
                    break;
            }
            if (gNumPlayers != 1) {
                var_s0->unk_34D = 1;
            }
            var_s0->unk_368 = 0xFF;
            var_s0->unk_350 = 0xFF;
            var_s0++;
        }
    }
    if ((gNumPlayers == 1) && (D_800E5EC0 != 1)) {
        if ((gGameMode != GAMEMODE_GP_END_CS) &&
            ((gGameMode != GAMEMODE_GP_RACE) || (D_800E5FF0 == 1) || (D_800CD010 == 1) || (D_i3_8013DBEC != 0))) {
            for (i = 0; i < 100; i++) {
                temp1 = (Math_Rand1() % (D_800E5EC0 - 1)) + 1;
                temp2 = (Math_Rand2() % (D_800E5EC0 - 1)) + 1;

                var_a3 = gRacers[temp1].unk_34D;
                gRacers[temp1].unk_34D = gRacers[temp2].unk_34D;
                gRacers[temp2].unk_34D = var_a3;
            }
            var_s5 = 0;
            if (gGameMode == GAMEMODE_GP_RACE) {
                var_s0_2 = 0;
                for (i = 1; i < D_800E5EC0; i++) {

                    for (j = 0; j < 3; j++) {
                        if (D_i3_80141910->character == D_i3_8013E7A8[gRacers[i].character].unk_03[j]) {
                            gRacers[i].unk_350 = 0;
                            gRacers[i].unk_34D = 7;
                            var_s0_2++;
                            break;
                        }
                    }

                    for (j = 0; j < 8; j++) {
                        if (D_i3_80141910->character == D_i3_8013E7A8[gRacers[i].character].unk_06[j]) {
                            sp70[var_s5++] = gRacers[i].id;
                            break;
                        }
                    }
                }

                for (i = 0; i < 200; i++) {
                    if (var_s5 != 0) {
                        temp_hi = Math_Rand1() % var_s5;

                        if ((gRacers[sp70[temp_hi]].unk_350 == 0xFF) && (sp70[temp_hi] != 0xFF)) {
                            gRacers[sp70[temp_hi]].unk_350 = 0;
                            gRacers[sp70[temp_hi]].unk_34D = 7;
                            var_s0_2++;
                            // FAKE!
                            // if ((gRacers && gRacers) && gRacers){}
                        }
                        if ((var_s0_2 >= 3) || ((var_s0_2 >= 2) && (gDifficulty <= EXPERT))) {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                for (i = 1; i < D_800E5EC0; i++) {
                    if (gRacers[i].unk_34D == 6) {
                        for (j = 0; gRacers[i].unk_350 == 0xFF && j < 200;) {
                            temp_hi = Math_Rand1() % 11;
                            if (temp_hi < 3) {
                                var_a3 = D_i3_8013E7A8[gRacers[i].character].unk_03[temp_hi];
                            } else {
                                var_a3 = D_i3_8013E7A8[gRacers[i].character].unk_06[temp_hi - 3];
                            }
                            j++;
                            for (var_s0_3 = 1; var_s0_3 < D_800E5EC0; var_s0_3++) {
                                if (gRacers[var_s0_3].character == var_a3) {
                                    var_v0_5 = 0;
                                    for (k = 1; k < D_800E5EC0; k++) {
                                        if (gRacers[k].unk_350 == var_s0_3) {
                                            var_v0_5++;
                                        }
                                        if (gRacers[var_s0_3].unk_34D >= 6) {
                                            var_v0_5++;
                                        }
                                    }
                                    if ((var_v0_5 == 0) && (gRacers[var_s0_3].unk_350 == 0xFF)) {
                                        gRacers[i].unk_350 = var_s0_3;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        var_v0_5 = 1;
        for (var_a0_2 = 0; var_a0_2 < 8; var_a0_2++) {
            for (var_s0 = &gRacers[1]; var_s0 < &gRacers[D_800E5EC0]; var_s0++) {
                if (var_s0->unk_34D == var_a0_2) {
                    var_s0->unk_368 = var_v0_5;
                    var_v0_5++;
                }
            }
        }
        for (var_s0 = &gRacers[1]; var_s0 < &gRacers[D_800E5EC0]; var_s0++) {
            if (var_s0->unk_350 != 0xFF) {
                var_s0->unk_352 = var_s0->unk_350;
                var_s0->unk_368 = 0xFF;
            } else {
                var_s0->unk_352 = 0xFF;
            }
        }
    }
    if ((gGameMode != GAMEMODE_GP_RACE) || (D_800E5FF0 == 1) || ((gCourseIndex % 6) == 0) || (D_800CD010 == 1) ||
        (D_i3_8013DBEC != 0)) {
        gRacers[0].unk_368 = 0xFF;
        gRacers[0].unk_350 = 0xFF;
        var_v0_5 = 1;

        for (var_a0_2 = 0; var_a0_2 < 8; var_a0_2++) {
            for (i = 1; i < D_800E5EC0; i++) {
                if (gRacers[i].unk_34D == var_a0_2) {
                    gRacers[i].position = D_80115D50[i] = var_v0_5;
                    var_v0_5++;
                }
            }
        }
        gRacers[0].position = D_80115D50[0] = D_800E5EC0;
    } else {
        var_a1 = false;
        for (var_a0_2 = 1; var_a0_2 - 1 < D_800E5EC0; var_a0_2++) {
            j = false;
            for (i = 0; i < D_800E5EC0; i++) {
                if (D_80115D50[i] == var_a0_2) {
                    j = true;
                    break;
                }
            }

            if (!j) {
                var_a1 = true;
                break;
            }
        }
        if (!var_a1) {
            for (i = 0; i < D_800E5EC0; i++) {
                gRacers[i].position = (D_800E5EC0 - D_80115D50[i]) + 1;
            }
        } else {
            var_v0_5 = 1;
            for (var_a0_2 = 0; var_a0_2 < 8; var_a0_2++) {
                for (k = 1; k < D_800E5EC0; k++) {
                    if (gRacers[k].unk_34D == var_a0_2) {
                        gRacers[k].position = var_v0_5;
                        var_v0_5++;
                    }
                }
            }
            gRacers[0].position = D_800E5EC0;
        }
    }

    if (((gGameMode == GAMEMODE_GP_RACE) && (D_i3_8013E94C[gCourseIndex] == 1)) || (D_800CD010 == 1)) {
        var_v0_5 = 4;
        for (var_a3_2 = 0; var_a3_2 < D_800E5EC0; var_a3_2++) {
            for (j = 1; j < D_800E5EC0; j++) {
                if ((gRacers[j].unk_368 >= 4) && (gRacers[j].unk_368 < D_800E5EC0) &&
                    (gRacers[j].position == (var_a3_2 + 1))) {
                    gRacers[j].unk_368 = var_v0_5;
                    var_v0_5++;
                    break;
                }
            }
        }
    }
    if (gGameMode == GAMEMODE_GP_END_CS) {
        for (i = 0; i < D_800E5EC0; i++) {
            gRacers[i].position = i + 1;
        }
    }
    if (gNumPlayers != 1) {
        for (i = 0; i < 4; i++) {
            gRacers[i].position = i + 1;
        }
    }
}
#else
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/overlays/ovl_i3/A90C0/func_i3_80115E74.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i3/A90C0/func_i3_80115E74.s")
#endif
#endif

extern CourseRecordInfo* gCurrentCourseRecordInfo;

void func_i3_80116974(void) {
    s32 pad[2];
    s32 timeRecord;
    GhostInfo sp1C;

    if (gCourseIndex < 0x18) {
        if (Save_LoadStaffGhostRecord(&sp1C, gCourseIndex) == 0) {
            D_i3_80141990 = D_i3_8013E328[gCourseIndex * 4 + gDifficulty];
        } else {
            D_i3_80141990 = MAX_TIMER;
        }
        if (gDifficulty >= EXPERT) {
            timeRecord = gCurrentCourseRecordInfo->timeRecord[0];
            if (timeRecord < sp1C.raceTime) {
                D_i3_80141990 = timeRecord + (D_i3_80141990 - sp1C.raceTime);
            }
        }
    } else {
        D_i3_80141990 = MAX_TIMER;
    }
    D_i3_80141994 = D_i3_80141990;
}

extern s32 gTotalLapCount;

f32 D_i3_8013E9E0[] = { 5000.0f, 2000.0f, 1000.0f, 1000.0f };

s32 D_i3_8013E9F0[] = {
    0,     860,   1780,  2760,  3800,  4900,  6060,  7280,  8560,  9900,  11300, 12760, 14280, 15860, 17500,
    19200, 20960, 22780, 24660, 26600, 28600, 30660, 32780, 34960, 37200, 39500, 41860, 44280, 46760, 49300,
    0,     680,   1440,  2280,  3200,  4200,  5280,  6440,  7680,  9000,  10400, 11880, 13440, 15080, 16800,
    18600, 20480, 22440, 24480, 26600, 28800, 31080, 33440, 35880, 38400, 41000, 43680, 46440, 49280, 52200,
    0,     560,   1180,  1860,  2600,  3400,  4260,  5180,  6160,  7200,  8300,  9460,  10680, 11960, 13300,
    14700, 16160, 17680, 19260, 20900, 22600, 24360, 26180, 28060, 30000, 32000, 34060, 36180, 38360, 40600,
    0,     560,   1180,  1860,  2600,  3400,  4260,  5180,  6160,  7200,  8300,  9460,  10680, 11960, 13300,
    14700, 16160, 17680, 19260, 20900, 22600, 24360, 26180, 28060, 30000, 32000, 34060, 36180, 38360, 40600,
};

void func_i3_80116A50(Racer* arg0) {
    s32 var_s3;
    s32 i;
    Racer* var_s0;
    f32 temp_ft3;
    f32 temp_fv0;
    f32 var_fs0;

    temp_ft3 = gCurrentCourseRecordInfo->length * gTotalLapCount;

    if (D_800E5EC0 < arg0->unk_368) {
        for (i = gNumPlayers, var_fs0 = temp_ft3, var_s3 = 0; i < D_800E5EC0; i++) {
            var_s0 = &gRacers[i];
            if ((D_800E5EC0 >= var_s0->unk_368) && (arg0->id != var_s0->id)) {
                temp_fv0 = func_i3_fabsf(arg0->unk_23C - var_s0->unk_23C);
                if (temp_fv0 < var_fs0) {
                    var_fs0 = temp_fv0;
                    var_s3 = i;
                }
            }
        }
        arg0->unk_368 = gRacers[var_s3].unk_368;
        if (D_800E5EC0 < arg0->unk_368) {
            arg0->unk_368 = 1;
        }
        func_i3_801175A4();
    }

    arg0->unk_398 = D_i3_80141990 - ((temp_ft3 - arg0->unk_23C) / temp_ft3) * D_i3_8013E9E0[gDifficulty] +
                    D_i3_8013E9F0[arg0->unk_368 - 1 + gDifficulty * 30];
}

void func_i3_80116C4C(void) {
    D_i3_8013DBE8 = func_800768F4(0, 0x200 * sizeof(s16));
}

f32 D_i3_8013EBD0[] = {
    0.0f, 0.0f, 0.04f, 0.08f, 0.0f, 0.0f, 0.03f, 0.05f, 0.0f, 0.0f, 0.0f, 0.02f,
    0.0f, 0.0f, 0.05f, 0.09f, 0.0f, 0.0f, 0.02f, 0.03f, 0.0f, 0.0f, 0.0f, 0.0f,
};

f32 D_i3_8013EC30[] = {
    0.0f, 0.0f, 0.02f, 0.01f, 0.0f, 0.0f, 0.02f, 0.01f,  0.0f, 0.0f, 0.03f, 0.03f,
    0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.01f, 0.005f, 0.0f, 0.0f, 0.0f,  0.0f,
};

extern s32 gCupType;

void func_i3_80116C74(Racer* arg0) {
    f32 var_fa0;
    s32 padC0[7];
    s32 sp48[30];
    s32 pad[3];
    s32 i;
    s32 j;

    D_i3_80141910 = gRacers;
#ifndef VERSION_JP
    D_80141900 = 0;
#endif
    if (arg0->id == 0) {
        func_i3_80116974();
        if (gCourseIndex < ARRAY_COUNT(D_i3_8013DB80)) {
            func_80077CF0(D_i3_8013DB80[gCourseIndex], 0x200 * sizeof(s16), D_i3_8013DBE8);
        } else {
            for (i = 0; i < 0x200; i += 2) {
                D_i3_8013DBE8[i + 0] = 0x45;
                D_i3_8013DBE8[i + 1] = 0;
            }
        }

        if (gGameMode == GAMEMODE_RECORDS) {
            arg0->unk_1A8 = 0.5f;
        }

        if ((gCupType == X_CUP) || (gCupType == EDIT_CUP)) {
            D_i3_80141904 = 0;
        } else {
            D_i3_80141904 = 1;
        }

        for (i = 0; i < 30; i++) {
            sp48[i] = 0xFF;
            for (j = 0; j < D_800E5EC0; j++) {
                if (gRacers[j].character == i) {
                    sp48[i] = j;
                    break;
                }
            }
        }

        D_i3_80141918 = sp48[0];
        D_i3_8014191C = sp48[1];
        D_i3_80141920 = sp48[2];
        D_i3_80141924 = sp48[3];
        D_i3_80141928 = sp48[4];
        D_i3_8014192C = sp48[5];
        D_i3_80141930 = sp48[6];
        D_i3_80141934 = sp48[7];
        D_i3_80141938 = sp48[8];
        D_i3_8014193C = sp48[9];
        D_i3_80141940 = sp48[10];
        D_i3_80141944 = sp48[11];
        D_i3_80141948 = sp48[12];
        D_i3_8014194C = sp48[13];
        D_i3_80141950 = sp48[14];
        D_i3_80141954 = sp48[15];
        D_i3_80141958 = sp48[16];
        D_i3_8014195C = sp48[17];
        D_i3_80141960 = sp48[18];
        D_i3_80141964 = sp48[19];
        D_i3_80141968 = sp48[20];
        D_i3_8014196C = sp48[21];
        D_i3_80141970 = sp48[22];
        D_i3_80141974 = sp48[23];
        D_i3_80141978 = sp48[24];
        D_i3_8014197C = sp48[25];
        D_i3_80141980 = sp48[26];
        D_i3_80141984 = sp48[27];
        D_i3_80141988 = sp48[28];
        D_i3_8014198C = sp48[29];
    }

    arg0->unk_358 = 0xFFFF;
    arg0->unk_330 = 0.01f;
    arg0->unk_334 = Math_Rand1() % 32768 / 32767.0f * 20.0f + 350.0f;
    arg0->unk_338 = Math_Rand2() % 32768 / 32767.0f * 0.01f + 0.3f;
    arg0->unk_354 = Math_Rand1() % 32768 / 32767.0f + 5.0f;
    arg0->unk_340 = Math_Rand1() % 8 + 15;
    arg0->unk_3A4 = 0;
    arg0->unk_39C = 0;
    arg0->unk_398 = 0;
    arg0->unk_394 = 0;
    arg0->unk_390 = 0;
    arg0->unk_36C = 0;
    arg0->unk_384 = 0;
    arg0->unk_1E8 = 0.0f;
    arg0->unk_364 = 0.0f;
    arg0->unk_360 = 0.0f;
    arg0->unk_38C = 0.0f;
    arg0->unk_3A0 = D_800E5EC0;
    arg0->unk_1EC = 2500.0f / 27.0f;

    if (gGameMode == GAMEMODE_GP_RACE) {
        arg0->unk_360 = D_i3_8013EBD0[D_i3_8013E7A8[arg0->character].unk_02 * 4 + gDifficulty];
        arg0->unk_364 = D_i3_8013EC30[D_i3_8013E7A8[arg0->character].unk_02 * 4 + gDifficulty] + arg0->unk_360;
    }

    arg0->unk_370 = 0;
    arg0->unk_33C = ((arg0->unk_24C.z.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.z.y * arg0->unk_0C.unk_28.y) +
                     (arg0->unk_24C.z.z * arg0->unk_0C.unk_28.z)) *
                    -1.0f;
    arg0->unk_340 = Math_Rand2() % 2 + 1;

    arg0->unk_36C = D_i3_8013E7A8[arg0->character].unk_00;

    if (D_i3_8013E7A8[arg0->character].unk_02 < 2) {
        arg0->unk_36C |= 0x200;
    }

    arg0->unk_380 = 0;
    arg0->unk_37C = 0;
    arg0->unk_378 = 0;
    arg0->unk_374 = 0;

    if (gGameMode == GAMEMODE_GP_END_CS) {
        arg0->unk_1A8 = func_8008960C(0.1f);
        arg0->unk_1EC = 2500.0f / 27.0f;
        arg0->unk_1E8 = 0.0f;
        arg0->unk_330 = 0.01f;
        arg0->unk_334 = Math_Rand1() % 32768 / 32767.0f * 20.0f + 500.0f;
    }

    // If CPU player
    if (arg0->id >= gNumPlayers) {
        if (gCourseIndex < 0x18) {
            if (D_800E5EC0 >= arg0->unk_368) {
                arg0->unk_39C = D_i3_8013E4A8[gCourseIndex * 4 + gDifficulty] +
                                D_i3_8013E628[gCourseIndex * 4 + gDifficulty] * (arg0->unk_368 - 1);
            }
        }
        if ((D_i3_80141910->position == arg0->position - 4) || (D_i3_80141910->position == (arg0->position + 4)) ||
            (gNumPlayers >= 2)) {
            var_fa0 = D_i3_80141910->unk_1A8;
            if (var_fa0 > 0.95f) {
                var_fa0 = 0.95f;
            }
            if (var_fa0 < 0.0f) {
                var_fa0 = 0.0f;
            }
            arg0->unk_1A8 = var_fa0;
        } else if ((gDifficulty == MASTER) && (D_i3_8013E94C[gCourseIndex] != 0)) {
            var_fa0 = (Math_Rand1() % 256 / 255.0f + 10.0f) / 14.0f;
            if (var_fa0 > 0.95f) {
                var_fa0 = 0.95f;
            }
            if (var_fa0 < 0.0f) {
                var_fa0 = 0.0f;
            }
            arg0->unk_1A8 = func_8008960C(var_fa0);
        } else {
            var_fa0 = D_i3_80141910->unk_1A8;
            var_fa0 += Math_Rand2() % 32768 / 32767.0f * 0.2f - 0.1f;
            if (var_fa0 > 0.95f) {
                var_fa0 = 0.95f;
            }
            if (var_fa0 < 0.0f) {
                var_fa0 = 0.0f;
            }
            arg0->unk_1A8 = var_fa0;
        }
        if (gCourseIndex == 0xC) {
            if (arg0->unk_1A8 > 0.8f) {
                arg0->unk_1A8 = 0.8f;
            }
            if (arg0->unk_1A8 < 0.6f) {
                arg0->unk_1A8 = 0.6f;
            }
        }
        if (gGameMode == GAMEMODE_DEATH_RACE) {
            arg0->unk_1A8 = (Math_Rand1() % 256 / 255.0f) * 0.2f;
        }
        arg0->unk_1EC = 2500.0f / 27.0f;
        arg0->unk_1E8 = 0.0f;
    }
}

extern s32 gTotalLapCount;
extern s16 D_80115DE0;
extern Racer* D_800E5F40[];

void func_i3_801175A4(void) {
    f32 temp_fv0;
    s32 temp_a1;
    s32 var_t0;
    s32 var_a3;
    s32 i;
    s32 temp1;
    s16 sp54[30];
    s32 temp2;
    s32 temp_v0;
    s32 temp_t3;
    s32 var_v0_2;

    D_i3_80141910 = gRacers;

    temp_fv0 = gCurrentCourseRecordInfo->length * gTotalLapCount;
    if ((D_800E5F40[0]->lap == 2) && (D_i3_80141904 == 0)) {
        var_a3 = 0;
        var_t0 = 0;
        for (i = 0; i < D_800E5EC0; i++) {
            if (gRacers[i].lap >= 2) {
                var_t0++;
                var_a3 += gRacers[i].lapTimes[0];
            }
        }

        if (var_t0 != 0) {
            if (gCupType == EDIT_CUP) {
                var_v0_2 = D_i3_8013DC04[gDifficulty] * ((f32) (s32) ((f32) var_a3 / var_t0) * gTotalLapCount);
            } else {
                var_v0_2 = D_i3_8013DBF0[gDifficulty] * ((f32) (s32) ((f32) var_a3 / var_t0) * gTotalLapCount);
            }
            if (var_v0_2 < D_i3_80141994) {
                D_i3_80141990 = var_v0_2;
                D_i3_80141994 = D_i3_80141990;
            }
            if (var_t0 >= D_80115DE0) {
                D_i3_80141904 = 1;
            }
        }
    }
    if ((D_i3_80141910->position == 1) && (D_i3_80141910->lap >= 2)) {
        for (i = 0; i < D_800E5EC0; i++) {
            if (D_800E5F40[i]->unk_368 < D_800E5EC0) {
                break;
            }
        }

        if (i < ((D_800E5EC0 * 2) / 3)) {
            if ((D_i3_80141910->unk_23C - D_800E5F40[i]->unk_23C) > 3000.0f) {
                temp_a1 = ((temp_fv0 - D_i3_80141910->unk_23C) / temp_fv0) * 1000.0f;
                temp_a1 += 1000;
                temp2 = ((D_i3_80141910->raceTime / D_i3_80141910->unk_23C) * temp_fv0) + temp_a1;
                if (temp2 < D_i3_80141994) {
                    D_i3_80141990 = temp2;
                }
            }
        }
    }

    for (i = 0; i < D_800E5EC0; i++) {
        sp54[i] = i;
    }

    for (i = 0; i < D_800E5EC0 - 1; i++) {
        for (temp_a1 = i + 1; temp_a1 < D_800E5EC0; temp_a1++) {
            if ((gRacers[sp54[i]].unk_368 > gRacers[sp54[temp_a1]].unk_368) ||
                ((gRacers[sp54[i]].unk_368 == gRacers[sp54[temp_a1]].unk_368) &&
                 (gRacers[sp54[i]].unk_23C < gRacers[sp54[temp_a1]].unk_23C))) {
                temp_t3 = sp54[i];
                sp54[i] = sp54[temp_a1];
                sp54[temp_a1] = temp_t3;
            }
        }
    }

    for (i = 0; i < D_800E5EC0; i++) {
        if (gRacers[sp54[i]].unk_368 <= D_800E5EC0) {
            gRacers[sp54[i]].unk_368 = i + 1;
        }
    }
}

f32 func_i3_801179DC(Racer* arg0) {
    return D_i3_8013DC18[gCourseIndex * 4 + gDifficulty] * (2500.0f / 27.0f);
}

f32 func_i3_80117A1C(Racer* arg0) {
    return D_i3_8013DFA0[gCourseIndex * 4 + gDifficulty];
}

void func_i3_80117A4C(Racer* arg0, s32 arg1) {
    Racer* temp_v0 = &gRacers[arg1];

    if ((arg0->unk_368 < D_800E5EC0) && (arg1 < D_800E5EC0)) {
        if (temp_v0->unk_368 < D_800E5EC0) {
            arg0->unk_368 = temp_v0->unk_368;
            arg0->unk_398 = temp_v0->unk_398;

            if (temp_v0->unk_33C < arg0->unk_33C) {
                arg0->unk_33C = temp_v0->unk_33C + 92.0f;
            } else {
                arg0->unk_33C = temp_v0->unk_33C - 92.0f;
            }
            arg0->unk_352 = 255;
        }
    }
}

void func_i3_80117B04(Racer* arg0, Controller* arg1) {
}

void func_i3_80117B10(Racer* arg0, Controller* arg1) {
    func_i3_80117A4C(arg0, D_i3_80141960);
}

void func_i3_80117B38(Racer* arg0, Controller* arg1) {
    func_i3_80117A4C(arg0, D_i3_80141944);
}

void func_i3_80117B60(Racer* arg0, Controller* arg1) {
    func_i3_80117A4C(arg0, D_i3_80141940);
}

void func_i3_80117B88(Racer* arg0, Controller* arg1) {
    if ((arg0->unk_2B4 != 0) && (D_i3_80141910->unk_23C < arg0->unk_23C) && (arg0->stateFlags & RACER_STATE_FLAGS_4000000)) {
        arg1->buttonPressed |= STICK_UP;
    }
}

void func_i3_80117BD8(Racer* arg0, Controller* arg1) {
}

void func_i3_80117BE4(Racer* arg0, Controller* arg1) {
}

void (*D_i3_8013EC90[])(Racer*, Controller*) = {
    func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04,
    func_i3_80117BE4, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04,
    func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04, func_i3_80117BD8, func_i3_80117B04,
    func_i3_80117B04, func_i3_80117B10, func_i3_80117B60, func_i3_80117B04, func_i3_80117B04, func_i3_80117B04,
    func_i3_80117B04, func_i3_80117B04, func_i3_80117B38, func_i3_80117B88, func_i3_80117B04, func_i3_80117B04,
};

UNUSED f32 D_i3_8013ED08[] = { 0.05f, 3.5f };

f32 D_i3_8013ED10[] = { 0.0f, 138.0f, 138.0f };

f32 D_i3_8013ED1C[] = { 0.0f, 2.0f, -2.0f };

extern u32 gGameFrameCount;
extern s32 gTotalLapCount;
extern s32 D_800F80A8[];
extern CourseData gCourseData;

void func_i3_80117BF0(Racer* arg0, Controller* arg1) {
    f32 spBC;
    s32 temps;
    f32 spB4;
    s32 i;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv1;
    f32 var_fv0;
    f32 sp9C;
    s32 var_a1;
    f32 sp94;
    f32 temp4;
    f32 temp5;
    f32 temp6;
    s32 var_a3;
    s32 pad;
    s32 sp7C;
    f32 temp2;
    bool sp74;
    bool sp70;
    Mtx3F sp4C;
    f32 temp3;
    Racer* sp44;
    Racer* sp40;

    if ((arg0->id & 3) != (gGameFrameCount % 4) && (gGameMode != GAMEMODE_GP_END_CS)) {
        arg1->buttonReleased = 0;
        arg1->stickX = arg0->unk_374;
        arg1->stickY = arg0->unk_378;
        arg1->buttonPressed = 0;
        arg1->buttonCurrent = arg0->unk_380;
        return;
    }
    arg1->buttonCurrent = arg1->buttonPressed = arg1->buttonReleased = 0;
    if (arg0->unk_2B4 != 0) {
        sp70 = true;
    } else {
        sp70 = false;
    }
    sp44 = arg0->unk_2B8;
    sp40 = arg0->unk_2BC;
    sp94 = ((-arg0->unk_0C.unk_28.x * arg0->unk_24C.z.x) - (arg0->unk_0C.unk_28.y * arg0->unk_24C.z.y)) -
           (arg0->unk_0C.unk_28.z * arg0->unk_24C.z.z);
    if (arg0->unk_1F8 < 2.0f) {
        arg0->unk_1F8 = 10.0f;
        arg0->unk_1E0 = 0.108f;
        arg0->unk_1E4 = 0.06f;
        if (arg0->id >= gNumPlayers) {
            arg0->boostEnergyUsage = 0.0f;
        }
    }
    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P)) {
        if (arg0->id >= gNumPlayers) {
            if (gNumPlayers == 3) {
                var_a1 = 30;
                for (i = 0; i < gNumPlayers; i++) {
                    if (gRacers[i].position < var_a1) {
                        var_a1 = gRacers[i].position;
                        var_a3 = i;
                    }
                }
            } else if (arg0->id == 2) {
                var_a3 = 0;
            } else {
                var_a3 = 1;
            }

            // FAKE
            if (arg0->boostEnergyUsage == 0.0f) {}

            temp_fv1 = (gRacers[var_a3].unk_23C + arg0->unk_38C) - arg0->unk_23C;
            if (temp_fv1 > 0) {
                arg0->unk_1EC = 69.44444f;
                arg0->unk_1E8 = temp_fv1 * 0.0003f;
                if (arg0->unk_1E8 > 1.0f) {
                    arg0->unk_1E8 = 1.0f;
                }
            } else {
                arg0->unk_1EC = gRacers[var_a3].speed - (temp_fv1 * 0.0002f);
                if ((gTotalLapCount == arg0->lap) &&
                    (((s32) (gCurrentCourseRecordInfo->segmentCount * 2) / 3) < arg0->unk_0C.courseSegment->segmentIndex)) {
                    arg0->unk_1EC = gRacers[var_a3].speed - (temp_fv1 * 0.002f);
                }
                arg0->unk_1E8 = 0.0f;
            }
            if ((gTotalLapCount == arg0->lap) &&
                (((s32) (gCurrentCourseRecordInfo->segmentCount * 2) / 3) < arg0->unk_0C.courseSegment->segmentIndex)) {
                arg0->unk_1E8 = 0.0f;
            }
            arg0->unk_38C = 0;
        }
    }
    if (D_i3_80141998 != 0) {
        if (gGameMode == GAMEMODE_PRACTICE) {
            arg0->unk_1EC = func_i3_801179DC(arg0);
            arg0->unk_1E8 = func_i3_80117A1C(arg0);
        }
    } else if (((gNumPlayers == 1) && (D_i3_80141910->stateFlags & RACER_STATE_FLAGS_2000000)) || (arg0->stateFlags & RACER_STATE_FLAGS_2000000) ||
               (arg0->id < gNumPlayers)) {
        arg0->unk_1E8 = 0.0f;
        arg0->unk_1EC = (2500.0f / 27.0f);
        arg0->unk_1B4 = 1.00894f;
        arg0->unk_1B0 = 1.156336f;
        arg0->unk_1B8 = 0.119168f;
        arg0->unk_1BC = 36.769516f;
        arg0->unk_1C4 = 1.726068f;
        arg0->unk_1D0 = 0.198282f;
        if ((gNumPlayers == 1) && (D_800E5EC0 != 1) && (arg0->id != 0) && (D_i3_80141910->stateFlags & RACER_STATE_FLAGS_2000000)) {
            if ((sp44->id == 0) && (arg0->unk_2C0 < 2000.0f)) {
                arg0->unk_1EC = (625.0f / 27.0f);
            } else if ((sp40->id == 0) && (arg0->unk_2C4 < 2000.0f)) {
                arg0->unk_1E8 = 1.0f;
                arg1->buttonPressed |= BTN_B;
            }
        }
    } else if ((arg0->unk_274 + arg0->unk_270) < 184.0f) {
        arg0->unk_1E8 = 0.0f;
        arg0->unk_1EC = (2500.0f / 27.0f);
    } else if (gNumPlayers == 1) {
        if (arg0->unk_352 != 0xFF) {
            spBC = (gRacers[arg0->unk_352].unk_23C + arg0->unk_38C) - arg0->unk_23C;
            func_i3_fabsf(D_i3_80141910->unk_23C - arg0->unk_23C);
            if ((func_i3_fabsf(spBC) < 460.0f) && sp70 && (arg0->raceTime > 1000)) {
                do {
                    if ((arg0->unk_352 >= gNumPlayers) && ((arg0->id + gGameFrameCount) % 16) < 4) {
                        spB4 = ((-gRacers[arg0->unk_352].unk_0C.unk_28.x * gRacers[arg0->unk_352].unk_24C.z.x) -
                                (gRacers[arg0->unk_352].unk_0C.unk_28.y * gRacers[arg0->unk_352].unk_24C.z.y)) -
                               (gRacers[arg0->unk_352].unk_0C.unk_28.z * gRacers[arg0->unk_352].unk_24C.z.z);
                        if (Math_Rand2() % 2) {
                            arg0->unk_33C = spB4 + 23.0f;
                        } else {
                            arg0->unk_33C = spB4 - 23.0f;
                        }
                    } else {
                        if (spB4) {}
                    }
                } while (0);
            }
            if (spBC < 2000.0f) {
                arg0->unk_1EC = gRacers[arg0->unk_352].speed + (spBC * 0.01f);
            } else {
                arg0->unk_1EC = (625.0f / 9.0f);
            }
            arg0->unk_1E8 = 1.2f;
            if (sp70 && (arg0->raceTime > 1000) && ((arg0->unk_274 + arg0->unk_270) > 138.0f) &&
                (func_i3_fabsf(gRacers[arg0->unk_352].unk_23C - arg0->unk_23C) < 184.0f)) {
                spB4 = ((f32) (Math_Rand1() % 32768) / 32767.0f) + 0.00001f;

                if (func_i3_fabsf(gRacers[arg0->unk_352].unk_33C - arg0->unk_33C) < 92.0f) {
                    if (((arg0->unk_352 != 0) && (spB4 < 0.15f) && (arg0->unk_36C & 0x200)) || (spB4 < arg0->unk_360)) {
                        if (arg0->unk_390 == 0) {
                            if (arg0->unk_33C < gRacers[arg0->unk_352].unk_33C) {
                                arg0->unk_390 = 5;
                            } else {
                                arg0->unk_390 = -5;
                            }
                        }
                    } else if ((((arg0->unk_352 != 0) && (spB4 < 0.2f) && (arg0->unk_36C & 0x200)) ||
                                (spB4 < arg0->unk_364)) &&
                               (((gDifficulty >= EXPERT) && (D_i3_80141910->unk_23C < arg0->unk_23C)) ||
                                ((D_i3_80141910->unk_23C + 138.0f) < arg0->unk_23C))) {
                        if (Math_Rand2() % 2) {
                            arg1->buttonPressed |= STICK_UP;
                        } else {
                            arg1->buttonPressed |= STICK_DOWN;
                        }
                    }
                }
            }
            if (arg0->lap == 1) {
                var_fv0 = func_i3_801179DC(arg0);
                if (var_fv0 < arg0->unk_1EC) {
                    arg0->unk_1EC = var_fv0;
                }
                var_fv0 = func_i3_80117A1C(arg0);
                if (var_fv0 < arg0->unk_1E8) {
                    arg0->unk_1E8 = var_fv0;
                }
            }
            if ((u32) (u8) (arg0->id + gGameFrameCount) < 4) {
                if (arg0->unk_352 < gNumPlayers) {
                    arg0->unk_38C =
                        ((Math_Rand2() % 32768 / 32767.0f * 400.0f + 30.0f) + 200.0f) - (80 * -gDifficulty + 240);
                } else {
                    arg0->unk_38C = 30.0f;
                }
            }

            if (((gTotalLapCount == arg0->lap) &&
                 (((s32) (gCurrentCourseRecordInfo->segmentCount * 2) / 3) < arg0->unk_0C.courseSegment->segmentIndex)) ||
                ((gRacers[arg0->unk_352].unk_368 == 0xFE) && (gGameMode != GAMEMODE_PRACTICE) &&
                 (gGameMode != GAMEMODE_DEATH_RACE))) {
                arg0->unk_352 = 255;
                if (arg0->lap >= 2) {
                    func_i3_80116A50(arg0);
                }
            }
        } else if ((arg0->lap >= 2) || (D_800CD010 == 1)) {
            if ((arg0->unk_398 == 0) || ((u32) (arg0->id + gGameFrameCount) % 64) < 4) {
                func_i3_80116A50(arg0);
            }

            var_fv0 = (gCurrentCourseRecordInfo->length * (gTotalLapCount - 1)) / (arg0->unk_398 - arg0->lapTimes[0]);
            spBC =
                (((arg0->raceTime - arg0->lapTimes[0]) * var_fv0) + gCurrentCourseRecordInfo->length) - arg0->unk_23C;
            spB4 = ((((arg0->raceTime - arg0->lapTimes[0]) - 0x11) * var_fv0) + gCurrentCourseRecordInfo->length) -
                   arg0->unk_23C;

            var_fv0 = func_i3_fabsf(D_i3_80141910->unk_23C - arg0->unk_23C);
            arg0->unk_1EC = (spBC * 0.05f) + (spBC - spB4);
            arg0->unk_1E8 = 0.3f;
            if (spBC > 0.0f) {
                if (spBC > 200.0f) {
                    arg0->unk_1E8 = 0.0f;
                    arg1->buttonPressed |= BTN_B;
                    if (spBC > 1000.0f) {
                        arg0->unk_1EC = (2500.0f / 27.0f);
                    }
                }
            } else if ((var_fv0 < 2000.0f) && (gTotalLapCount == arg0->lap) &&
                       (((s32) (gCurrentCourseRecordInfo->segmentCount * 2) / 3) <
                        arg0->unk_0C.courseSegment->segmentIndex)) {
                spBC = D_i3_80141910->speed - 2.3148148f;
                if ((var_fv0 < 0.0f) && (arg0->unk_1EC < spBC)) {
                    arg0->unk_1EC = spBC;
                }
            }
        } else {
            if (arg0->unk_39C != 0) {
                spBC = (arg0->raceTime * (gCurrentCourseRecordInfo->length / arg0->unk_39C)) - arg0->unk_23C;
                spB4 = ((arg0->raceTime - 0x11) * (gCurrentCourseRecordInfo->length / arg0->unk_39C)) - arg0->unk_23C;
                if (arg0->unk_23C > 0.0f) {
                    arg0->unk_1EC = (spBC * 0.05f) + (spBC - spB4);
                    arg0->unk_1E8 = 1.0f;
                } else {
                    arg0->unk_1EC = (2500.0f / 27.0f);
                    arg0->unk_1E8 = 0.0f;
                }
            } else {
                arg0->unk_1EC = func_i3_801179DC(arg0);
                arg0->unk_1E8 = func_i3_80117A1C(arg0);
            }
        }
    }
    var_a3 = arg0->unk_0C.courseSegment->segmentIndex * 4;
    if (arg0->unk_0C.unk_08 >= 0.5f) {
        var_a3 += 2;
    }

    if (D_i3_8013DBE8[var_a3] < arg0->unk_1EC) {
        arg0->unk_1EC = D_i3_8013DBE8[var_a3];
    }
    if (((D_80141900 >= 0x15) || (D_800F80A8[0] > 30)) && (gNumPlayers == 1) && (arg0->id != 0) &&
        (arg0->raceTime >= 10001) && !(D_i3_80141910->stateFlags & RACER_STATE_FLAGS_8000000) &&
        (func_i3_fabsf(D_i3_80141910->unk_33C - sp94) < 138.0f)) {

        var_fv0 = D_i3_80141910->unk_23C - arg0->unk_23C;
        while (var_fv0 > gCurrentCourseRecordInfo->length * 0.5f) {
            var_fv0 -= gCurrentCourseRecordInfo->length;
        }

        while (var_fv0 < gCurrentCourseRecordInfo->length * -0.5f) {
            var_fv0 += gCurrentCourseRecordInfo->length;
        }

        if (var_fv0 < 0) {
            var_fv0 = 0.0f - var_fv0;
        }
        if (var_fv0 < 500.0f) {
            if (Math_Rand1() % 2) {
                arg1->buttonPressed |= STICK_UP;
            } else {
                arg1->buttonPressed |= STICK_DOWN;
            }
        }
    }
    if (gCourseIndex == 0xC) {
        sp7C = arg0->unk_0C.courseSegment->segmentIndex;
        if ((sp7C >= 4) && (sp7C < 0x10)) {
            arg0->unk_1EC = (2500.0f / 27.0f);
            arg0->unk_1E8 = 1.0f;
        }
    }
    arg1->buttonCurrent |= BTN_A;
    if (arg0->unk_340 < arg0->unk_20C) {
        arg1->buttonPressed |= BTN_A;
    }

    sp74 = false;
    if ((arg0->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_PIPE) {
        if ((arg0->unk_0C.courseSegment->next->next->next->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_PIPE) {
            sp74 = true;
            arg0->unk_330 = 10.0f;
        } else if ((arg0->unk_0C.courseSegment->next->next->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_PIPE) {
            sp74 = true;
            arg0->unk_330 = 10.0f;
        } else if ((arg0->unk_0C.courseSegment->next->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_PIPE) {
            sp74 = true;
            arg0->unk_330 = 10.0f;
        }
    }

    if (func_8009D16C(&arg0->unk_0C, arg0->unk_0C.unk_34.x + (arg0->unk_330 * arg0->velocity.x),
                      arg0->unk_0C.unk_34.y + (arg0->unk_330 * arg0->velocity.y),
                      arg0->unk_0C.unk_34.z + (arg0->unk_330 * arg0->velocity.z), &sp4C) == 0) {
        if (((arg0->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_PIPE) &&
            ((arg0->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_CYLINDER)) {
            temp4 = arg0->unk_C0.x.x;
            temp5 = arg0->unk_C0.x.y;
            temp6 = arg0->unk_C0.x.z;
            if (gGameMode == GAMEMODE_GP_END_CS) {
                arg0->unk_33C = D_i3_8013ED1C[arg0->id] * 46.0f;
                if (arg0->id != 0) {
                    temp3 = ((gRacers[0].unk_23C - D_i3_8013ED10[arg0->id]) - arg0->unk_23C);
                    arg0->unk_1EC = gRacers[0].speed + (temp3 * 0.1f);
                    arg0->unk_1E8 = 1.0f;
                }
            }
            temp_fa0 = (arg0->unk_338 * (((arg0->unk_33C + (arg0->unk_0C.unk_28.x * arg0->unk_24C.z.x)) +
                                          (arg0->unk_0C.unk_28.y * arg0->unk_24C.z.y)) +
                                         (arg0->unk_0C.unk_28.z * arg0->unk_24C.z.z))) *
                       1.2f;
            temp_fa0 += (arg0->unk_334 * ((temp4 * sp4C.z.x) + (temp5 * sp4C.z.y) + (temp6 * sp4C.z.z)) * 1.2f);
            var_a3 = Math_Round(temp_fa0);
        } else if (!sp74) {
            var_a3 = Math_Round(-arg0->unk_334 * ((arg0->unk_C0.z.x * sp4C.x.x) + (arg0->unk_C0.z.y * sp4C.x.y) +
                                                  (arg0->unk_C0.z.z * sp4C.x.z)));
            if (!(Math_Rand2() % 64)) {
                if (Math_Rand1() % 2) {
                    arg0->unk_370 = (Math_Rand2() % 16) + 20;
                } else {
                    arg0->unk_370 = -20 - (Math_Rand1() % 16);
                }
            }

            if (arg0->unk_370 != 0) {
                var_a3 += (s32) (arg0->unk_334 / 20.0f);
                arg0->unk_370--;
            }
        } else {
            arg0->unk_370 = 0;
            spB4 = (arg0->unk_338 *
                    (arg0->unk_C0.z.x * arg0->unk_24C.y.x + arg0->unk_C0.z.y * arg0->unk_24C.y.y +
                     arg0->unk_C0.z.z * arg0->unk_24C.y.z) *
                    160.0f);
            var_a3 = Math_Round(spB4 - (arg0->unk_334 * 0.5f *
                                        ((arg0->unk_C0.z.x * sp4C.x.x) + (arg0->unk_C0.z.y * -sp4C.x.y) +
                                         (arg0->unk_C0.z.z * sp4C.x.z))));
        }
        if (arg0->stateFlags & RACER_STATE_FLAGS_4000000) {
            var_a1 = Math_Round(-arg0->unk_334 * 0.1f * DOT_XYZ(&arg0->unk_C0.y, &sp4C.x));

            if (gCourseIndex == 0xC) {
                if ((arg0->unk_0C.courseSegment->segmentIndex >= 7) &&
                    (arg0->unk_0C.courseSegment->segmentIndex < 0xF)) {
                    if (arg0->unk_A0 > 400.0f) {
                        var_a3 = 0;
                    }
                    var_a1 = (s32) ((var_a1 * 0.25f) - (arg0->unk_A0 * 0.015f));
                    var_a3 *= 5;
                }
            }

            if (var_a1 < -0x46) {
                var_a1 = -0x46;
            } else if (var_a1 >= 0x47) {
                var_a1 = 0x46;
            }
            var_a3 /= 5;
            if (((arg0->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_CYLINDER) ||
                ((arg0->unk_0C.courseSegment->next->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_AIR) ||
                ((arg0->unk_0C.courseSegment->next->next->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_AIR)) {
                var_a1 = 0x46;
                arg1->buttonCurrent &= 0x7FFF;
                arg1->buttonPressed &= 0x7FFF;
                arg1->buttonReleased &= 0x7FFF;
            }

            if (arg0->unk_33C > 0.0f) {
                arg0->unk_33C -= arg0->unk_354;
            } else {
                arg0->unk_33C += arg0->unk_354;
            }
            arg0->unk_1EC = (2500.0f / 27.0f);
            if (arg0->unk_1E8 >= 1.0f) {
                arg0->unk_1E8 = 1.0f;
            }
        } else {
            var_a1 = 0x46;
            if (((arg0->unk_0C.courseSegment->next->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_AIR) &&
                (arg0->unk_0C.unk_08 > 0.5f)) {
                arg0->unk_1EC = 69.44444f;
            }
        }
        if (var_a3 < -0x46) {
            var_a3 = -0x46;
            arg1->buttonCurrent |= BTN_Z;
        } else if (var_a3 >= 0x47) {
            var_a3 = 0x46;
            arg1->buttonCurrent |= STICK_RIGHT;
        }
        arg1->stickX = (var_a3 * 5) / 8;
        arg1->stickY = var_a1;
        if (gNumPlayers == 1) {
            if (sp70 && (arg0->raceTime > 1000) && (gDifficulty >= EXPERT) && (arg0->id != 0) && (D_800E5EC0 != 1) &&
                (arg0->unk_36C & 0x200)) {
                if ((arg0->unk_2C4 < 23.0f) &&
                    (((gDifficulty >= EXPERT) && (D_i3_80141910->unk_23C < arg0->unk_23C)) ||
                     ((D_i3_80141910->unk_23C + 138.0f) < arg0->unk_23C)) &&
                    ((Math_Rand2() % 32768) < 16)) {
                    if (Math_Rand2() % 2) {
                        arg1->buttonPressed |= STICK_UP;
                    } else {
                        arg1->buttonPressed |= STICK_DOWN;
                    }
                }
                if ((arg0->unk_2C4 < 23.0f) && (func_i3_fabsf(sp40->unk_33C - arg0->unk_33C) < 138.0f) &&
                    (arg0->unk_390 == 0) && (((f32) (Math_Rand1() % 32768) / 32767.0f) < 0.01f)) {
                    if (arg0->unk_33C < sp40->unk_33C) {
                        arg0->unk_390 = 5;
                    } else {
                        arg0->unk_390 = -5;
                    }
                }
            }

            if (arg0->unk_390 < 0) {
                arg0->unk_390++;
                if (((arg0->unk_390 == -3) || (arg0->unk_390 == -1)) &&
                    ((gDifficulty >= EXPERT) || (func_i3_fabsf(D_i3_80141910->unk_23C - arg0->unk_23C) > 184.0f)) &&
                    (D_i3_80141910->unk_23C < arg0->unk_23C)) {
                    arg1->buttonPressed |= BTN_Z;
                }
            } else if (arg0->unk_390 > 0) {
                arg0->unk_390--;
                if (((arg0->unk_390 == 3) || (arg0->unk_390 == 1)) &&
                    ((gDifficulty >= EXPERT) || ((arg0->unk_23C - D_i3_80141910->unk_23C) > 184.0f)) &&
                    (D_i3_80141910->unk_23C < arg0->unk_23C)) {
                    arg1->buttonPressed |= STICK_RIGHT;
                }
            }
            if (!(Math_Rand2() % 2048)) {
                arg0->unk_36C &= ~0xC00;
            }
        }
        if (arg0->stateFlags & COURSE_EFFECT_PIT) {
            arg0->unk_394 = 180;
        }

        if (arg0->unk_394 > 0) {
            arg0->unk_394--;
        }

        var_a3 = arg0->unk_0C.courseSegment->segmentIndex;
        if (var_a3 != arg0->unk_358) {
            arg0->unk_344 = gCourseData.landmine[var_a3];
            arg0->unk_345 = gCourseData.jump[var_a3];
            arg0->unk_346 = gCourseData.dirt[var_a3];
            arg0->unk_347 = gCourseData.ice[var_a3];
            arg0->unk_348 = gCourseData.pit[var_a3];
            if (gDifficulty >= EXPERT) {
                arg0->unk_349 = gCourseData.dash[var_a3];
            } else {
                arg0->unk_349 = -1;
            }

            arg0->unk_35C = arg0->unk_0C.courseSegment->trackSegmentInfo & TRACK_FORM_MASK;
            arg0->unk_358 = var_a3;

            if (++var_a3 >= gCurrentCourseRecordInfo->segmentCount) {
                var_a3 = 0;
            }
            arg0->unk_34A = gCourseData.landmine[var_a3];
            arg0->unk_34B = gCourseData.dirt[var_a3];
            arg0->unk_34C = gCourseData.dash[var_a3];
            arg0->unk_34E = 6;
            if (arg0->unk_344 != -1) {
                arg0->unk_34E = 5;
            }
            if (arg0->unk_346 != -1) {
                arg0->unk_34E = 4;
            }
            if (arg0->unk_348 != -1) {
                arg0->unk_34E = 3;
            }
            if (arg0->unk_345 == 1) {
                arg0->unk_34E = 2;
            }
            if (arg0->unk_345 == 2) {
                arg0->unk_34E = 1;
            }
        }

        if (arg0->unk_36C & 0x800) {
            var_a3 = (arg0->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK);
            if ((var_a3 == 0x80) || (var_a3 == 0xC0)) {
                if (arg0->character & 1) {
                    arg1->stickX += 42;
                    if (arg1->stickX > 70) {
                        arg1->stickX = 70;
                    }
                } else {
                    arg1->stickX -= 42;
                    if (arg1->stickX < -70) {
                        arg1->stickX = -70;
                    }
                }
            } else {
                var_a3 = (u32) ((arg0->character * 5) + gGameFrameCount) % 280U;
                if (var_a3 >= 0x8D) {
                    var_a3 = -var_a3;
                }
                if (var_a3 >= 0x47) {
                    var_a3 = 0x8C - var_a3;
                }
                if (var_a3 < -0x46) {
                    var_a3 = -0x8C - var_a3;
                }
                arg1->stickX = var_a3;
                if (D_i3_80141910->unk_23C < arg0->unk_23C) {
                    if (Math_Rand2() % 2) {
                        arg1->buttonPressed |= STICK_UP;
                    } else {
                        arg1->buttonPressed |= STICK_DOWN;
                    }
                }
            }
        } else {
            if (((arg0->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_PIPE) &&
                ((arg0->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_CYLINDER) &&
                (gGameMode != GAMEMODE_GP_END_CS)) {
                if ((gCourseIndex < 0x18) &&
                    (((arg0->raceTime > 2000) && (((arg0->unk_368 % 6) < 2) ||
                                                  (func_i3_fabsf(arg0->unk_23C - D_i3_80141910->unk_23C) > 5000.0f))) ||
                     (arg0->id < gNumPlayers))) {
                    var_a3 = arg0->unk_0C.courseSegment->segmentIndex * 4;
                    if (arg0->unk_0C.unk_08 >= 0.5f) {
                        var_a3 += 2;
                    }
                    var_a1 = var_a3 + 2;
                    if (var_a1 >= (gCurrentCourseRecordInfo->segmentCount * 4)) {
                        var_a1 = 0;
                    }
                    sp7C = D_i3_8013DBE8[var_a3 + 1];
                    temps = D_i3_8013DBE8[var_a1 + 1];
                    spBC = (temps - sp7C) * arg0->unk_0C.unk_08 + sp7C;
                    if (D_800E5EC0 != 1) {
                        if (sp44->id != arg0->unk_352) {
                            if ((arg0->unk_2C0 < 92.0f) && (func_i3_fabsf(sp44->unk_33C - spBC) < 69.0f)) {
                                if (spBC < sp44->unk_33C) {
                                    arg0->unk_33C = spBC - 92.0f;
                                } else {
                                    arg0->unk_33C = spBC + 92.0f;
                                }
                            } else {
                                arg0->unk_33C = spBC;
                            }
                        }
                    } else {
                        arg0->unk_33C = spBC;
                    }
                    if ((var_a3 != arg0->unk_358) && (sp7C & 1) && (arg0->id < gNumPlayers)) {
                        var_fv0 = arg0->energy / arg0->maxEnergy;
                        if (var_fv0 > 0.3f) {
                            arg1->buttonPressed |= BTN_A | BTN_B;
                        }
                        arg0->unk_358 = arg0->unk_0C.courseSegment->segmentIndex;
                    }
                    arg0->unk_388 = var_a3;
                    arg0->unk_330 = 0.1f;
                } else {
                    arg0->unk_330 = arg0->speed * 0.1f;
                    sp9C = (arg0->unk_274 - arg0->unk_270) * 0.5f;
                    var_fv0 = arg0->energy / arg0->maxEnergy;
                    switch (arg0->unk_34E) {
                        case 1:
                            if (gCourseIndex != 0x11) {
                                if (arg0->unk_33C < sp9C + 92.0f) {
                                    arg0->unk_33C = sp9C + 92.0f;
                                }
                            } else {
                                if (arg0->unk_33C > sp9C - 230.0f) {
                                    arg0->unk_33C = sp9C - 230.0f;
                                }
                            }
                            break;
                        case 2:
                            if (gCourseIndex != 0x11) {
                                if (arg0->unk_33C > sp9C - 230.0f) {
                                    arg0->unk_33C = sp9C - 230.0f;
                                }
                            } else {
                                if (arg0->unk_33C < sp9C + 92.0f) {
                                    arg0->unk_33C = sp9C + 92.0f;
                                }
                            }
                            break;
                        case 3:
                            if ((arg0->unk_348 == 0) && (var_fv0 < 0.99f)) {
                                arg0->unk_33C = ((-arg0->unk_0C.unk_28.x * arg0->unk_24C.z.x) -
                                                 (arg0->unk_0C.unk_28.y * arg0->unk_24C.z.y)) -
                                                (arg0->unk_0C.unk_28.z * arg0->unk_24C.z.z);

                                if (func_i3_fabsf(sp9C - arg0->unk_33C) < 146.0f) {
                                    if (arg0->unk_33C > sp9C) {
                                        arg0->unk_33C += arg0->unk_354 * 10.0f;
                                    } else {
                                        arg0->unk_33C -= arg0->unk_354 * 10.0f;
                                    }
                                }
                                break;
                            }

                            if ((arg0->unk_348 == 1) && (var_fv0 < 0.99f)) {
                                arg0->unk_33C = sp94;
                                if ((gGameMode == GAMEMODE_DEATH_RACE) && (arg0->id >= gNumPlayers)) {
                                    if (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f)) {
                                        arg0->unk_33C += (arg0->unk_354 * 10.0f);
                                    }
                                } else {
                                    if (arg0->unk_33C > ((sp9C - 100.0f) - 46.0f)) {
                                        arg0->unk_33C -= arg0->unk_354 * 10.0f;
                                    }
                                }
                                break;
                            }

                            if ((arg0->unk_348 == 2) && ((arg0->lap == 1) || (var_fv0 < 0.99f))) {
                                arg0->unk_33C = sp94;
                                if (arg0->unk_33C < (sp9C + 100.0f + 46.0f)) {
                                    arg0->unk_33C += arg0->unk_354 * 10.0f;
                                }
                                break;
                            }
                            /* fallthrough */
                        case 4:
                            if ((arg0->unk_346 != -1) && (arg0->unk_36C & 4)) {
                                if ((arg0->unk_346 == 0) && (func_i3_fabsf(sp9C - arg0->unk_33C) > 77.0f)) {
                                    if (arg0->unk_33C > sp9C) {
                                        arg0->unk_33C -= arg0->unk_354 * 4.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 4.0f;
                                    }
                                    break;
                                }

                                if ((arg0->unk_346 == 2) && (arg0->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 4.0f;
                                    break;
                                }

                                if (arg0->unk_346 == 1) {
                                    if (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f)) {
                                        arg0->unk_33C += arg0->unk_354 * 4.0f;
                                        goto block_359;
                                    }
                                }
                                if (arg0->unk_346 == 3) {
                                    if (func_i3_fabsf(sp9C - arg0->unk_33C) > 146.0f) {
                                        if (arg0->unk_33C < sp9C) {
                                            arg0->unk_33C -= arg0->unk_354 * 4.0f;
                                        } else {
                                            arg0->unk_33C += arg0->unk_354 * 4.0f;
                                        }
                                        break;
                                    }
                                }
                            }
                            /* fallthrough */
                        case 5:
                        block_359:
                            if (arg0->unk_344 != -1) {
                                if ((arg0->unk_344 == 2) && (arg0->unk_33C > (sp9C - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                } else if ((arg0->unk_344 == 1) && (arg0->unk_33C < (sp9C + 46.0f))) {
                                    arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    break;
                                }
                            }
                            /* fallthrough */
                        case 6:
                            if ((D_800E5EC0 != 1) && (sp44->id != arg0->unk_352) && (arg0->unk_2C0 < 92.0f) &&
                                (func_i3_fabsf(sp44->unk_33C - arg0->unk_33C) < 92.0f)) {
                                if ((arg0->unk_33C > 0.0f) && (arg0->unk_274 < (arg0->unk_33C + 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354;
                                    break;
                                }
                                if ((arg0->unk_33C < 0.0f) && ((46.0f - arg0->unk_33C) < arg0->unk_270)) {
                                    arg0->unk_33C += arg0->unk_354;
                                    break;
                                }
                                if (sp44->unk_33C < arg0->unk_33C) {
                                    arg0->unk_33C += arg0->unk_354;
                                    break;
                                }

                                arg0->unk_33C -= arg0->unk_354;
                                break;
                            }

                            if ((arg0->unk_349 != -1) && (arg0->unk_36C & 1)) {
                                if ((arg0->unk_349 == 0) && (arg0->unk_0C.unk_08 < 0.8f) &&
                                    (func_i3_fabsf(arg0->unk_33C - sp9C) < 230.0f)) {
                                    arg0->unk_33C = sp9C;
                                    break;
                                }
                                if ((arg0->unk_349 == 1) && (arg0->unk_0C.unk_08 < 0.8f) &&
                                    (func_i3_fabsf(arg0->unk_33C - ((-1.0f * arg0->unk_270) + 100.0f)) < 230.0f)) {
                                    arg0->unk_33C = (arg0->unk_270 * -1.0f) + 100.0f;
                                    break;
                                }
                                if ((arg0->unk_349 == 2) && (arg0->unk_0C.unk_08 < 0.8f)) {
                                    if (func_i3_fabsf(arg0->unk_33C - (arg0->unk_274 - 100.0f)) < 230.0f) {
                                        arg0->unk_33C = arg0->unk_274 - 100.0f;
                                        break;
                                    }
                                }
                            }
                            if ((arg0->unk_347 != -1) && (arg0->unk_36C & 1)) {
                                if ((arg0->unk_347 == 0) && (func_i3_fabsf(sp9C - arg0->unk_33C) > 77.0f)) {
                                    if (sp9C < arg0->unk_33C) {
                                        arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    }
                                    break;
                                }

                                if ((arg0->unk_347 == 2) && (arg0->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                }

                                if ((arg0->unk_347 == 1) && (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f))) {
                                    arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    break;
                                }

                                if ((arg0->unk_347 == 3) && (func_i3_fabsf(sp9C - arg0->unk_33C) > 146.0f)) {
                                    if (arg0->unk_33C < sp9C) {
                                        arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    }
                                    break;
                                }
                            }

                            if ((arg0->unk_34B != -1) && (arg0->unk_36C & 0x10)) {
                                if ((arg0->unk_34B == 0) && (func_i3_fabsf(sp9C - arg0->unk_33C) > 77.0f)) {
                                    if (arg0->unk_33C > sp9C) {
                                        arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    }
                                    break;
                                }

                                if ((arg0->unk_34B == 2) && (arg0->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                }
                                if (arg0->unk_34B == 1) {
                                    if (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f)) {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    } else {
                                        goto block_429;
                                    }
                                } else {
                                block_429:
                                    if ((arg0->unk_34B == 3) && (func_i3_fabsf(sp9C - arg0->unk_33C) > 146.0f)) {
                                        if (arg0->unk_33C < sp9C) {
                                            arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                        } else {
                                            arg0->unk_33C += arg0->unk_354 * 3.0f;
                                        }
                                        break;
                                    }
                                }
                            }
                            if ((arg0->unk_34A != -1) && (arg0->unk_36C & 8)) {
                                if ((arg0->unk_34A == 2) && (arg0->unk_33C > (sp9C - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                } else if ((arg0->unk_34A == 1) && (arg0->unk_33C < (sp9C + 46.0f))) {
                                    arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    break;
                                }
                            }

                            if ((arg0->unk_34C != -1) && (arg0->unk_36C & 0x20)) {
                                if ((arg0->unk_34C == 0) && (arg0->unk_0C.unk_08 < 0.5f) &&
                                    (func_i3_fabsf(arg0->unk_33C - sp9C) < 230.0f)) {
                                    arg0->unk_33C = sp9C;
                                    break;
                                } else {
                                    if ((arg0->unk_34C == 1) && (arg0->unk_0C.unk_08 < 0.5f) &&
                                        (func_i3_fabsf(arg0->unk_33C - ((-1.0f * arg0->unk_270) + 100.0f)) < 230.0f)) {
                                        arg0->unk_33C = (arg0->unk_270 * -1.0f) + 100.0f;
                                        break;
                                    }
                                    if ((arg0->unk_34C == 2) && (arg0->unk_0C.unk_08 < 0.5f) &&
                                        (func_i3_fabsf(arg0->unk_33C - (arg0->unk_274 - 100.0f)) < 230.0f)) {
                                        arg0->unk_33C = arg0->unk_274 - 100.0f;
                                        break;
                                    }
                                }
                            }

                            if ((arg0->raceTime >= 0x7D1) && !(Math_Rand1() & 0x7F0)) {
                                if (!(Math_Rand1() % 2)) {
                                    arg0->unk_33C -= 46.0f;
                                } else {
                                    arg0->unk_33C += 46.0f;
                                }
                            }
                            break;
                    }
                }
            }
        }
        D_i3_8013EC90[arg0->character](arg0, arg1);
        if ((gNumPlayers == 1) && (arg0->id != 0)) {
            var_fv0 = arg0->unk_23C - D_i3_80141910->unk_23C;
            if ((var_fv0 > -230.0f) && (var_fv0 < -11.5f) && (func_i3_fabsf(sp94 - D_i3_80141910->unk_33C) < 92.0f)) {
                if (D_i3_80141910->unk_33C < sp94) {
                    arg0->unk_33C = D_i3_80141910->unk_33C + 92.0f;
                } else {
                    arg0->unk_33C = D_i3_80141910->unk_33C - 92.0f;
                }
            }
        }

        if ((arg0->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_HALF_PIPE) {
            spBC = 92.0f;
        } else if ((arg0->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_BORDERLESS_ROAD) {
            if (arg0->unk_35C == TRACK_FORM_STRAIGHT) {
                spBC = 23.0f;
            } else {
                spBC = 50.600002f;
            }
        } else {
            spBC = 92.0f;
        }
        if ((arg0->unk_35C == TRACK_FORM_RIGHT) || ((arg0->unk_35C == TRACK_FORM_S) && (arg0->unk_0C.unk_08 > 0.6f)) ||
            ((arg0->unk_35C == TRACK_FORM_S_FLIPPED) && (arg0->unk_0C.unk_08 < 0.4f))) {
            if (arg0->unk_33C < 0.0f) {
                if (arg0->unk_270 < ((arg0->unk_33C * -1.0f) + spBC)) {
                    arg0->unk_33C = (arg0->unk_270 - spBC) * -1.0f;
                }
            } else {
                if (arg0->unk_274 < (arg0->unk_33C + (spBC * 0.5f))) {
                    arg0->unk_33C = arg0->unk_274 - (spBC * 0.5f);
                }
            }
        } else if ((arg0->unk_35C == TRACK_FORM_LEFT) ||
                   ((arg0->unk_35C == TRACK_FORM_S) && (arg0->unk_0C.unk_08 < 0.4f)) ||
                   ((arg0->unk_35C == TRACK_FORM_S_FLIPPED) && (arg0->unk_0C.unk_08 > 0.6f))) {
            if (arg0->unk_33C < 0.0f) {
                if (arg0->unk_270 < ((arg0->unk_33C * -1.0f) + (spBC * 0.5f))) {
                    arg0->unk_33C = (arg0->unk_270 - (spBC * 0.5f)) * -1.0f;
                }
            } else {
                if (arg0->unk_274 < (arg0->unk_33C + spBC)) {
                    arg0->unk_33C = arg0->unk_274 - spBC;
                }
            }
        } else {
            if (arg0->unk_33C < 0.0f) {
                if (arg0->unk_270 < ((arg0->unk_33C * -1.0f) + spBC)) {
                    arg0->unk_33C = (arg0->unk_270 - spBC) * -1.0f;
                }
            } else {
                if (arg0->unk_274 < (arg0->unk_33C + spBC)) {
                    arg0->unk_33C = arg0->unk_274 - spBC;
                }
            }
        }
        if ((gNumPlayers == 1) && (arg0->id != 0)) {
            var_fv0 = D_i3_80141910->unk_23C - arg0->unk_23C;
            if ((var_fv0 > 0.0f) && (var_fv0 < 92.0f) &&
                (func_i3_fabsf(D_i3_80141910->unk_33C - arg0->unk_33C) < 69.0f)) {
                if (D_i3_80141910->speed < arg0->unk_1EC) {
                    arg0->unk_1EC = D_i3_80141910->speed;
                }
            }
        }
        if (arg0->unk_1EC < (625.0f / 27.0f)) {
            arg0->unk_1EC = (625.0f / 27.0f);
        }
        if ((arg0->stateFlags & RACER_STATE_FLAGS_2000000) || (gGameMode == GAMEMODE_GP_END_CS)) {
            arg0->unk_36C &= ~0xA00;
            if (arg0->id < gNumPlayers) {
                arg1->buttonPressed &= ~BTN_B;
            }
            if (D_i3_80141908 != 0) {
                // FAKE!
                if (1) {}
                var_a1 = 0;
                for (i = 0; i < D_800E5EC0; i++) {
                    if (gRacers[i].unk_35C == TRACK_FORM_STRAIGHT) {
                        var_a1++;
                    }
                }

                if (var_a1 == D_800E5EC0) {
                    if (arg0->id == 0) {
                        D_i3_8014190C++;
                    }
                    if (D_i3_8014190C > 60) {
                        arg0->unk_1EC = arg0->speed * 0.1f;
                        arg1->buttonCurrent |= BTN_CDOWN;
                        arg1->buttonCurrent &= 0x7FFF;
                        arg1->buttonPressed &= 0x7FFF;
                        arg1->buttonReleased &= 0x7FFF;
                    }
                }
            }
            if (arg0->unk_36C & 0x1000) {
                arg1->buttonCurrent |= BTN_CDOWN;
                arg1->buttonCurrent &= 0x7FFF;
                arg1->buttonPressed &= 0x7FFF;
                arg1->buttonReleased &= 0x7FFF;
            }
        }
        arg0->unk_374 = arg1->stickX;
        arg0->unk_378 = arg1->stickY;
        arg0->unk_37C = arg1->buttonPressed;
        arg0->unk_380 = arg1->buttonCurrent;
    }
}
