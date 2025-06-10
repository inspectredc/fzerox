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
Racer* sPlayerRacer;
UNUSED s32 D_i3_80141914;
s32 sCaptainFalconRacerId;
s32 sDrStewartRacerId;
s32 sPicoRacerId;
s32 sSamuraiGorohRacerId;
s32 sJodySummerRacerId;
s32 sMightyGazelleRacerId;
s32 sMrEadRacerId;
s32 sBabaRacerId;
s32 sOctomanRacerId;
s32 sGomarAndShiohRacerId;
s32 sKateAlenRacerId;
s32 sRogerBusterRacerId;
s32 sJamesMcCloudRacerId;
s32 sLeonRacerId;
s32 sAntonioGusterRacerId;
s32 sBlackShadowRacerId;
s32 sMichaelChainRacerId;
s32 sJackLevinRacerId;
s32 sSuperArrowRacerId;
s32 sMrsArrowRacerId;
s32 sJohnTanakaRacerId;
s32 sBeastmanRacerId;
s32 sZodaRacerId;
s32 sDrClashRacerId;
s32 sSilverNeelsenRacerId;
s32 sBioRexRacerId;
s32 sDraqRacerId;
s32 sBillyRacerId;
s32 sTheSkullRacerId;
s32 sBloodFalconRacerId;
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
extern s32 gTotalRacers;
extern s32 D_800E5FF0;
extern s16 D_80115D50[];

void func_i3_80115E74(void) {
    s32 pad[44];
    Racer* tempRacer;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    Racer* var_s0;
    s32 var_a1;
    s32 sp70[8];
    s32 var_a3;
    s32 temp_hi;
    s32 var_s5;

    if ((gGameMode == GAMEMODE_GP_END_CS) || (gGameMode == GAMEMODE_DEATH_RACE) || (gGameMode == GAMEMODE_PRACTICE)) {
        D_i3_80141998 = 1;
    } else {
        D_i3_80141998 = 0;
    }
    D_i3_8014190C = D_i3_80141908 = 0;
    sPlayerRacer = gRacers;

    for (i = 0; i < gTotalRacers; i++) {
        gRacers[i].id = i;
    }

    if ((gGameMode != GAMEMODE_GP_RACE) || (D_800E5FF0 == 1) || (D_800CD010 == 1) || (D_i3_8013DBEC != 0) ||
        (gNumPlayers >= 2)) {
        var_s0 = gRacers;
        while (var_s0 < &gRacers[gTotalRacers]) {
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
            var_s0->unk_350 = var_s0->unk_368 = 0xFF;
            var_s0++;
        }
    }
    if ((gNumPlayers == 1) && (gTotalRacers != 1)) {
        if ((gGameMode != GAMEMODE_GP_END_CS) &&
            ((gGameMode != GAMEMODE_GP_RACE) || (D_800E5FF0 == 1) || (D_800CD010 == 1) || (D_i3_8013DBEC != 0))) {
            for (i = 0; i < 100; i++) {
                m = (Math_Rand2() % (gTotalRacers - 1)) + 1;
                k = (Math_Rand1() % (gTotalRacers - 1)) + 1;

                var_a3 = gRacers[m].unk_34D;
                gRacers[m].unk_34D = gRacers[k].unk_34D;
                gRacers[k].unk_34D = var_a3;
            }
            var_s5 = 0;
            if (gGameMode == GAMEMODE_GP_RACE) {
                m = 0;
                for (i = 1; i < gTotalRacers; i++) {

                    for (j = 0; j < 3; j++) {
                        if (sPlayerRacer->character == D_i3_8013E7A8[gRacers[i].character].unk_03[j]) {
                            gRacers[i].unk_350 = 0;
                            gRacers[i].unk_34D = 7;
                            m++;
                            break;
                        }
                    }

                    for (j = 0; j < 8; j++) {
                        if (sPlayerRacer->character == D_i3_8013E7A8[gRacers[i].character].unk_06[j]) {
                            sp70[var_s5++] = gRacers[i].id;
                            break;
                        }
                    }
                }

                for (i = 0; i < 200; i++) {
                    if (var_s5 != 0) {
                        temp_hi = Math_Rand2() % var_s5;

                        if ((gRacers[sp70[temp_hi]].unk_350 == 0xFF) && (sp70[temp_hi] != 0xFF)) {
                            gRacers[sp70[temp_hi]].unk_350 = 0;
                            gRacers[sp70[temp_hi]].unk_34D = 7;
                            m++;

                            // FAKE!
                            if (gRacers) {}
                        }
                        if ((m >= 3) || ((m >= 2) && (gDifficulty <= EXPERT))) {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                for (i = 1; i < gTotalRacers; i++) {
                    if (gRacers[i].unk_34D == 6) {
                        for (j = 0; gRacers[i].unk_350 == 0xFF && j < 200;) {
                            temp_hi = Math_Rand2() % 11;
                            if (temp_hi < 3) {
                                var_a3 = D_i3_8013E7A8[gRacers[i].character].unk_03[temp_hi];
                            } else {
                                var_a3 = D_i3_8013E7A8[gRacers[i].character].unk_06[temp_hi - 3];
                            }
                            j++;
                            for (m = 1; m < gTotalRacers; m++) {
                                if (gRacers[m].character == var_a3) {
                                    n = 0;
                                    for (k = 1; k < gTotalRacers; k++) {
                                        if (gRacers[k].unk_350 == m) {
                                            n++;
                                        }
                                        if (gRacers[m].unk_34D >= 6) {
                                            n++;
                                        }
                                    }
                                    if ((n == 0) && (gRacers[m].unk_350 == 0xFF)) {
                                        gRacers[i].unk_350 = m;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        n = 1;
        for (k = 0; k < 8; k++) {
            for (var_s0 = &gRacers[1]; var_s0 < &gRacers[gTotalRacers]; var_s0++) {
                if (var_s0->unk_34D == k) {
                    var_s0->unk_368 = n;
                    n++;
                }
            }
        }
        for (var_s0 = &gRacers[1]; var_s0 < &gRacers[gTotalRacers]; var_s0++) {
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
        tempRacer = gRacers;
        gRacers[0].unk_368 = 0xFF;
        gRacers[0].unk_350 = 0xFF;
        n = 1;

        for (k = 0; k < 8; k++) {
            for (i = 1; i < gTotalRacers; i++) {
                if (gRacers[i].unk_34D == k) {

                    // FAKE!
                    (*(tempRacer + i)).position = D_80115D50[i] = n;
                    if (1) {}
                    if (1) {}

                    n++;
                }
            }
        }
        gRacers[0].position = D_80115D50[0] = gTotalRacers;
    } else {
        var_a1 = 0;
        for (k = 1; k <= gTotalRacers; k++) {
            j = 0;
            for (i = 0; i < gTotalRacers; i++) {
                if (D_80115D50[i] == k) {
                    j++;
                    break;
                }
            }

            if (j == 0) {
                var_a1 = 1;
                break;
            }
        }
        if (var_a1 == 0) {
            for (i = 0; i < gTotalRacers; i++) {
                gRacers[i].position = (gTotalRacers - D_80115D50[i]) + 1;
            }
        } else {
            n = 1;
            for (k = 0; k < 8; k++) {
                for (i = 1; i < gTotalRacers; i++) {
                    if (gRacers[i].unk_34D == k) {
                        gRacers[i].position = n;
                        n++;
                    }
                }
            }
            gRacers[0].position = gTotalRacers;
        }
    }

    if (((gGameMode == GAMEMODE_GP_RACE) && (D_i3_8013E94C[gCourseIndex] == 1)) || (D_800CD010 == 1)) {
        var_a1 = 4;
        for (var_a3 = 0; var_a3 < gTotalRacers; var_a3++) {
            for (j = 1; j < gTotalRacers; j++) {
                if ((gRacers[j].unk_368 >= 4) && (gRacers[j].unk_368 < gTotalRacers) &&
                    (gRacers[j].position == (var_a3 + 1))) {
                    gRacers[j].unk_368 = var_a1;
                    var_a1++;
                    break;
                }
            }
        }
    }
    if (gGameMode == GAMEMODE_GP_END_CS) {
        for (i = 0; i < gTotalRacers; i++) {
            gRacers[i].position = i + 1;
        }
    }
    if (gNumPlayers != 1) {
        for (i = 0; i < 4; i++) {
            gRacers[i].position = i + 1;
        }
    }
}

extern CourseInfo* gCurrentCourseInfo;

void func_i3_80116974(void) {
    s32 pad[2];
    s32 timeRecord;
    GhostInfo sp1C;

    if (gCourseIndex < COURSE_EDIT_1) {
        if (Save_LoadStaffGhostRecord(&sp1C, gCourseIndex) == 0) {
            D_i3_80141990 = D_i3_8013E328[gCourseIndex * 4 + gDifficulty];
        } else {
            D_i3_80141990 = MAX_TIMER;
        }
        if (gDifficulty >= EXPERT) {
            timeRecord = gCurrentCourseInfo->timeRecord[0];
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

    temp_ft3 = gCurrentCourseInfo->length * gTotalLapCount;

    if (gTotalRacers < arg0->unk_368) {
        for (i = gNumPlayers, var_fs0 = temp_ft3, var_s3 = 0; i < gTotalRacers; i++) {
            var_s0 = &gRacers[i];
            if ((gTotalRacers >= var_s0->unk_368) && (arg0->id != var_s0->id)) {
                temp_fv0 = func_i3_fabsf(arg0->raceDistance - var_s0->raceDistance);
                if (temp_fv0 < var_fs0) {
                    var_fs0 = temp_fv0;
                    var_s3 = i;
                }
            }
        }
        arg0->unk_368 = gRacers[var_s3].unk_368;
        if (gTotalRacers < arg0->unk_368) {
            arg0->unk_368 = 1;
        }
        func_i3_801175A4();
    }

    arg0->unk_398 = D_i3_80141990 - ((temp_ft3 - arg0->raceDistance) / temp_ft3) * D_i3_8013E9E0[gDifficulty] +
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
    s32 characterRacerIds[30];
    s32 pad[3];
    s32 i;
    s32 j;

    sPlayerRacer = gRacers;
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
            characterRacerIds[i] = 0xFF;
            for (j = 0; j < gTotalRacers; j++) {
                if (gRacers[j].character == i) {
                    characterRacerIds[i] = j;
                    break;
                }
            }
        }

        sCaptainFalconRacerId = characterRacerIds[CAPTAIN_FALCON];
        sDrStewartRacerId = characterRacerIds[DR_STEWART];
        sPicoRacerId = characterRacerIds[PICO];
        sSamuraiGorohRacerId = characterRacerIds[SAMURAI_GOROH];
        sJodySummerRacerId = characterRacerIds[JODY_SUMMER];
        sMightyGazelleRacerId = characterRacerIds[MIGHTY_GAZELLE];
        sMrEadRacerId = characterRacerIds[MR_EAD];
        sBabaRacerId = characterRacerIds[BABA];
        sOctomanRacerId = characterRacerIds[OCTOMAN];
        sGomarAndShiohRacerId = characterRacerIds[GOMAR_AND_SHIOH];
        sKateAlenRacerId = characterRacerIds[KATE_ALEN];
        sRogerBusterRacerId = characterRacerIds[ROGER_BUSTER];
        sJamesMcCloudRacerId = characterRacerIds[JAMES_MCCLOUD];
        sLeonRacerId = characterRacerIds[LEON];
        sAntonioGusterRacerId = characterRacerIds[ANTONIO_GUSTER];
        sBlackShadowRacerId = characterRacerIds[BLACK_SHADOW];
        sMichaelChainRacerId = characterRacerIds[MICHAEL_CHAIN];
        sJackLevinRacerId = characterRacerIds[JACK_LEVIN];
        sSuperArrowRacerId = characterRacerIds[SUPER_ARROW];
        sMrsArrowRacerId = characterRacerIds[MRS_ARROW];
        sJohnTanakaRacerId = characterRacerIds[JOHN_TANAKA];
        sBeastmanRacerId = characterRacerIds[BEASTMAN];
        sZodaRacerId = characterRacerIds[ZODA];
        sDrClashRacerId = characterRacerIds[DR_CLASH];
        sSilverNeelsenRacerId = characterRacerIds[SILVER_NEELSEN];
        sBioRexRacerId = characterRacerIds[BIO_REX];
        sDraqRacerId = characterRacerIds[DRAQ];
        sBillyRacerId = characterRacerIds[BILLY];
        sTheSkullRacerId = characterRacerIds[THE_SKULL];
        sBloodFalconRacerId = characterRacerIds[BLOOD_FALCON];
    }

    arg0->lastSegmentIndex = 0xFFFF;
    arg0->unk_330 = 0.01f;
    arg0->unk_334 = Math_Rand1() % 32768 / 32767.0f * 20.0f + 350.0f;
    arg0->unk_338 = Math_Rand2() % 32768 / 32767.0f * 0.01f + 0.3f;
    arg0->unk_354 = Math_Rand1() % 32768 / 32767.0f + 5.0f;
    arg0->unk_340 = Math_Rand1() % 8 + 15;
    arg0->unk_3A4 = 0;
    arg0->unk_39C = 0;
    arg0->unk_398 = 0;
    arg0->unk_394 = 0;
    arg0->driftingCounter = 0;
    arg0->awarenessFlags = 0;
    arg0->unk_384 = 0;
    arg0->unk_1E8 = 0.0f;
    arg0->unk_364 = 0.0f;
    arg0->unk_360 = 0.0f;
    arg0->unk_38C = 0.0f;
    arg0->unk_3A0 = gTotalRacers;
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

    arg0->awarenessFlags = D_i3_8013E7A8[arg0->character].unk_00;

    if (D_i3_8013E7A8[arg0->character].unk_02 < 2) {
        arg0->awarenessFlags |= 0x200;
    }

    arg0->lastButtonsCurrent = 0;
    arg0->lastButtonsPressed = 0;
    arg0->lastStickY = 0;
    arg0->lastStickX = 0;

    if (gGameMode == GAMEMODE_GP_END_CS) {
        arg0->unk_1A8 = func_8008960C(0.1f);
        arg0->unk_1EC = 2500.0f / 27.0f;
        arg0->unk_1E8 = 0.0f;
        arg0->unk_330 = 0.01f;
        arg0->unk_334 = Math_Rand1() % 32768 / 32767.0f * 20.0f + 500.0f;
    }

    // If CPU racer
    if (arg0->id >= gNumPlayers) {
        if (gCourseIndex < COURSE_EDIT_1) {
            if (gTotalRacers >= arg0->unk_368) {
                arg0->unk_39C = D_i3_8013E4A8[gCourseIndex * 4 + gDifficulty] +
                                D_i3_8013E628[gCourseIndex * 4 + gDifficulty] * (arg0->unk_368 - 1);
            }
        }
        if ((sPlayerRacer->position == arg0->position - 4) || (sPlayerRacer->position == (arg0->position + 4)) ||
            (gNumPlayers >= 2)) {
            var_fa0 = sPlayerRacer->unk_1A8;
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
            var_fa0 = sPlayerRacer->unk_1A8;
            var_fa0 += Math_Rand2() % 32768 / 32767.0f * 0.2f - 0.1f;
            if (var_fa0 > 0.95f) {
                var_fa0 = 0.95f;
            }
            if (var_fa0 < 0.0f) {
                var_fa0 = 0.0f;
            }
            arg0->unk_1A8 = var_fa0;
        }
        if (gCourseIndex == COURSE_FIRE_FIELD) {
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
extern s16 gRacersRemaining;
extern Racer* gRacersByPosition[];

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

    sPlayerRacer = gRacers;

    temp_fv0 = gCurrentCourseInfo->length * gTotalLapCount;
    if ((gRacersByPosition[0]->lap == 2) && (D_i3_80141904 == 0)) {
        var_a3 = 0;
        var_t0 = 0;
        for (i = 0; i < gTotalRacers; i++) {
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
            if (var_t0 >= gRacersRemaining) {
                D_i3_80141904 = 1;
            }
        }
    }
    if ((sPlayerRacer->position == 1) && (sPlayerRacer->lap >= 2)) {
        for (i = 0; i < gTotalRacers; i++) {
            if (gRacersByPosition[i]->unk_368 < gTotalRacers) {
                break;
            }
        }

        if (i < ((gTotalRacers * 2) / 3)) {
            if ((sPlayerRacer->raceDistance - gRacersByPosition[i]->raceDistance) > 3000.0f) {
                temp_a1 = ((temp_fv0 - sPlayerRacer->raceDistance) / temp_fv0) * 1000.0f;
                temp_a1 += 1000;
                temp2 = ((sPlayerRacer->raceTime / sPlayerRacer->raceDistance) * temp_fv0) + temp_a1;
                if (temp2 < D_i3_80141994) {
                    D_i3_80141990 = temp2;
                }
            }
        }
    }

    for (i = 0; i < gTotalRacers; i++) {
        sp54[i] = i;
    }

    for (i = 0; i < gTotalRacers - 1; i++) {
        for (temp_a1 = i + 1; temp_a1 < gTotalRacers; temp_a1++) {
            if ((gRacers[sp54[i]].unk_368 > gRacers[sp54[temp_a1]].unk_368) ||
                ((gRacers[sp54[i]].unk_368 == gRacers[sp54[temp_a1]].unk_368) &&
                 (gRacers[sp54[i]].raceDistance < gRacers[sp54[temp_a1]].raceDistance))) {
                temp_t3 = sp54[i];
                sp54[i] = sp54[temp_a1];
                sp54[temp_a1] = temp_t3;
            }
        }
    }

    for (i = 0; i < gTotalRacers; i++) {
        if (gRacers[sp54[i]].unk_368 <= gTotalRacers) {
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

void func_i3_80117A4C(Racer* racer, s32 racerId) {
    Racer* temp_v0 = &gRacers[racerId];

    if ((racer->unk_368 < gTotalRacers) && (racerId < gTotalRacers)) {
        if (temp_v0->unk_368 < gTotalRacers) {
            racer->unk_368 = temp_v0->unk_368;
            racer->unk_398 = temp_v0->unk_398;

            if (temp_v0->unk_33C < racer->unk_33C) {
                racer->unk_33C = temp_v0->unk_33C + 92.0f;
            } else {
                racer->unk_33C = temp_v0->unk_33C - 92.0f;
            }
            racer->unk_352 = 255;
        }
    }
}

void Cpu_BehaviorDoNothing(Racer* racer, Controller* controller) {
}

void Cpu_BehaviorMrsArrow(Racer* racer, Controller* controller) {
    func_i3_80117A4C(racer, sSuperArrowRacerId);
}

void Cpu_BehaviorDraq(Racer* racer, Controller* controller) {
    func_i3_80117A4C(racer, sRogerBusterRacerId);
}

void Cpu_BehaviorJohnTanaka(Racer* racer, Controller* controller) {
    func_i3_80117A4C(racer, sKateAlenRacerId);
}

void Cpu_BehaviorBilly(Racer* racer, Controller* controller) {
    if ((racer->machineLod != 0) && (sPlayerRacer->raceDistance < racer->raceDistance) &&
        (racer->stateFlags & RACER_STATE_AIRBORNE)) {
        controller->buttonPressed |= BTN_R_Z_COMBO;
    }
}

void Cpu_BehaviorMichaelChain(Racer* racer, Controller* controller) {
}

void Cpu_BehaviorMrEad(Racer* racer, Controller* controller) {
}

void (*sCharacterBehaviorFuncs[])(Racer*, Controller*) = {
    Cpu_BehaviorDoNothing,    // CAPTAIN_FALCON
    Cpu_BehaviorDoNothing,    // DR_STEWART
    Cpu_BehaviorDoNothing,    // PICO
    Cpu_BehaviorDoNothing,    // SAMURAI_GOROH
    Cpu_BehaviorDoNothing,    // JODY_SUMMER
    Cpu_BehaviorDoNothing,    // MIGHTY_GAZELLE
    Cpu_BehaviorMrEad,        // MR_EAD
    Cpu_BehaviorDoNothing,    // BABA
    Cpu_BehaviorDoNothing,    // OCTOMAN
    Cpu_BehaviorDoNothing,    // GOMAR_AND_SHIOH
    Cpu_BehaviorDoNothing,    // KATE_ALEN
    Cpu_BehaviorDoNothing,    // ROGER_BUSTER
    Cpu_BehaviorDoNothing,    // JAMES_MCCLOUD
    Cpu_BehaviorDoNothing,    // LEON
    Cpu_BehaviorDoNothing,    // ANTONIO_GUSTER
    Cpu_BehaviorDoNothing,    // BLACK_SHADOW
    Cpu_BehaviorMichaelChain, // MICHAEL_CHAIN
    Cpu_BehaviorDoNothing,    // JACK_LEVIN
    Cpu_BehaviorDoNothing,    // SUPER_ARROW
    Cpu_BehaviorMrsArrow,     // MRS_ARROW
    Cpu_BehaviorJohnTanaka,   // JOHN_TANAKA
    Cpu_BehaviorDoNothing,    // BEASTMAN
    Cpu_BehaviorDoNothing,    // ZODA
    Cpu_BehaviorDoNothing,    // DR_CLASH
    Cpu_BehaviorDoNothing,    // SILVER_NEELSEN
    Cpu_BehaviorDoNothing,    // BIO_REX
    Cpu_BehaviorDraq,         // DRAQ
    Cpu_BehaviorBilly,        // BILLY
    Cpu_BehaviorDoNothing,    // THE_SKULL
    Cpu_BehaviorDoNothing,    // BLOOD_FALCON
};

UNUSED f32 D_i3_8013ED08[] = { 0.05f, 3.5f };

f32 D_i3_8013ED10[] = { 0.0f, 138.0f, 138.0f };

f32 D_i3_8013ED1C[] = { 0.0f, 2.0f, -2.0f };

extern u32 gGameFrameCount;
extern s32 gTotalLapCount;
extern s32 D_800F80A8[];
extern CourseData gCourseData;

void Cpu_GenerateInputs(Racer* racer, Controller* controller) {
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

    if ((racer->id & 3) != (gGameFrameCount % 4) && (gGameMode != GAMEMODE_GP_END_CS)) {
        controller->buttonReleased = 0;
        controller->stickX = racer->lastStickX;
        controller->stickY = racer->lastStickY;
        controller->buttonPressed = 0;
        controller->buttonCurrent = racer->lastButtonsCurrent;
        return;
    }
    controller->buttonCurrent = controller->buttonPressed = controller->buttonReleased = 0;
    if (racer->machineLod != 0) {
        sp70 = true;
    } else {
        sp70 = false;
    }
    sp44 = racer->racerAhead;
    sp40 = racer->racerBehind;
    sp94 = ((-racer->unk_0C.unk_28.x * racer->unk_24C.z.x) - (racer->unk_0C.unk_28.y * racer->unk_24C.z.y)) -
           (racer->unk_0C.unk_28.z * racer->unk_24C.z.z);
    if (racer->unk_1F8 < 2.0f) {
        racer->unk_1F8 = 10.0f;
        racer->unk_1E0 = 0.108f;
        racer->unk_1E4 = 0.06f;
        if (racer->id >= gNumPlayers) {
            racer->boostEnergyUsage = 0.0f;
        }
    }
    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P)) {
        if (racer->id >= gNumPlayers) {
            if (gNumPlayers == 3) {
                var_a1 = 30;
                for (i = 0; i < gNumPlayers; i++) {
                    if (gRacers[i].position < var_a1) {
                        var_a1 = gRacers[i].position;
                        var_a3 = i;
                    }
                }
            } else if (racer->id == 2) {
                var_a3 = 0;
            } else {
                var_a3 = 1;
            }

            // FAKE
            if (racer->boostEnergyUsage == 0.0f) {}

            temp_fv1 = (gRacers[var_a3].raceDistance + racer->unk_38C) - racer->raceDistance;
            if (temp_fv1 > 0) {
                racer->unk_1EC = 69.44444f;
                racer->unk_1E8 = temp_fv1 * 0.0003f;
                if (racer->unk_1E8 > 1.0f) {
                    racer->unk_1E8 = 1.0f;
                }
            } else {
                racer->unk_1EC = gRacers[var_a3].speed - (temp_fv1 * 0.0002f);
                if ((gTotalLapCount == racer->lap) &&
                    (((s32) (gCurrentCourseInfo->segmentCount * 2) / 3) < racer->unk_0C.courseSegment->segmentIndex)) {
                    racer->unk_1EC = gRacers[var_a3].speed - (temp_fv1 * 0.002f);
                }
                racer->unk_1E8 = 0.0f;
            }
            if ((gTotalLapCount == racer->lap) &&
                (((s32) (gCurrentCourseInfo->segmentCount * 2) / 3) < racer->unk_0C.courseSegment->segmentIndex)) {
                racer->unk_1E8 = 0.0f;
            }
            racer->unk_38C = 0;
        }
    }
    if (D_i3_80141998 != 0) {
        if (gGameMode == GAMEMODE_PRACTICE) {
            racer->unk_1EC = func_i3_801179DC(racer);
            racer->unk_1E8 = func_i3_80117A1C(racer);
        }
    } else if (((gNumPlayers == 1) && (sPlayerRacer->stateFlags & RACER_STATE_FLAGS_2000000)) ||
               (racer->stateFlags & RACER_STATE_FLAGS_2000000) || (racer->id < gNumPlayers)) {
        racer->unk_1E8 = 0.0f;
        racer->unk_1EC = (2500.0f / 27.0f);
        racer->unk_1B4 = 1.00894f;
        racer->unk_1B0 = 1.156336f;
        racer->unk_1B8 = 0.119168f;
        racer->unk_1BC = 36.769516f;
        racer->unk_1C4 = 1.726068f;
        racer->unk_1D0 = 0.198282f;
        if ((gNumPlayers == 1) && (gTotalRacers != 1) && (racer->id != 0) &&
            (sPlayerRacer->stateFlags & RACER_STATE_FLAGS_2000000)) {
            if ((sp44->id == 0) && (racer->distanceToRacerAhead < 2000.0f)) {
                racer->unk_1EC = (625.0f / 27.0f);
            } else if ((sp40->id == 0) && (racer->distanceFromRacerBehind < 2000.0f)) {
                racer->unk_1E8 = 1.0f;
                controller->buttonPressed |= BTN_B;
            }
        }
    } else if ((racer->unk_274 + racer->unk_270) < 184.0f) {
        racer->unk_1E8 = 0.0f;
        racer->unk_1EC = (2500.0f / 27.0f);
    } else if (gNumPlayers == 1) {
        if (racer->unk_352 != 0xFF) {
            spBC = (gRacers[racer->unk_352].raceDistance + racer->unk_38C) - racer->raceDistance;
            func_i3_fabsf(sPlayerRacer->raceDistance - racer->raceDistance);
            if ((func_i3_fabsf(spBC) < 460.0f) && sp70 && (racer->raceTime > 1000)) {
                // FAKE!
                do {
                    if ((racer->unk_352 >= gNumPlayers) && ((racer->id + gGameFrameCount) % 16) < 4) {
                        spB4 = ((-gRacers[racer->unk_352].unk_0C.unk_28.x * gRacers[racer->unk_352].unk_24C.z.x) -
                                (gRacers[racer->unk_352].unk_0C.unk_28.y * gRacers[racer->unk_352].unk_24C.z.y)) -
                               (gRacers[racer->unk_352].unk_0C.unk_28.z * gRacers[racer->unk_352].unk_24C.z.z);
                        if (Math_Rand2() % 2) {
                            racer->unk_33C = spB4 + 23.0f;
                        } else {
                            racer->unk_33C = spB4 - 23.0f;
                        }
                    } else {
                        if (spB4) {}
                    }
                } while (0);
            }
            if (spBC < 2000.0f) {
                racer->unk_1EC = gRacers[racer->unk_352].speed + (spBC * 0.01f);
            } else {
                racer->unk_1EC = (625.0f / 9.0f);
            }
            racer->unk_1E8 = 1.2f;
            if (sp70 && (racer->raceTime > 1000) && ((racer->unk_274 + racer->unk_270) > 138.0f) &&
                (func_i3_fabsf(gRacers[racer->unk_352].raceDistance - racer->raceDistance) < 184.0f)) {
                spB4 = ((f32) (Math_Rand1() % 32768) / 32767.0f) + 0.00001f;

                if (func_i3_fabsf(gRacers[racer->unk_352].unk_33C - racer->unk_33C) < 92.0f) {
                    if (((racer->unk_352 != 0) && (spB4 < 0.15f) && (racer->awarenessFlags & 0x200)) ||
                        (spB4 < racer->unk_360)) {
                        if (racer->driftingCounter == 0) {
                            if (racer->unk_33C < gRacers[racer->unk_352].unk_33C) {
                                racer->driftingCounter = 5;
                            } else {
                                racer->driftingCounter = -5;
                            }
                        }
                    } else if ((((racer->unk_352 != 0) && (spB4 < 0.2f) && (racer->awarenessFlags & 0x200)) ||
                                (spB4 < racer->unk_364)) &&
                               (((gDifficulty >= EXPERT) && (sPlayerRacer->raceDistance < racer->raceDistance)) ||
                                ((sPlayerRacer->raceDistance + 138.0f) < racer->raceDistance))) {
                        if (Math_Rand2() % 2) {
                            controller->buttonPressed |= BTN_R_Z_COMBO;
                        } else {
                            controller->buttonPressed |= BTN_Z_R_COMBO;
                        }
                    }
                }
            }
            if (racer->lap == 1) {
                var_fv0 = func_i3_801179DC(racer);
                if (var_fv0 < racer->unk_1EC) {
                    racer->unk_1EC = var_fv0;
                }
                var_fv0 = func_i3_80117A1C(racer);
                if (var_fv0 < racer->unk_1E8) {
                    racer->unk_1E8 = var_fv0;
                }
            }
            if ((u32) (u8) (racer->id + gGameFrameCount) < 4) {
                if (racer->unk_352 < gNumPlayers) {
                    racer->unk_38C =
                        ((Math_Rand2() % 32768 / 32767.0f * 400.0f + 30.0f) + 200.0f) - (80 * -gDifficulty + 240);
                } else {
                    racer->unk_38C = 30.0f;
                }
            }

            if (((gTotalLapCount == racer->lap) &&
                 (((s32) (gCurrentCourseInfo->segmentCount * 2) / 3) < racer->unk_0C.courseSegment->segmentIndex)) ||
                ((gRacers[racer->unk_352].unk_368 == 254) && (gGameMode != GAMEMODE_PRACTICE) &&
                 (gGameMode != GAMEMODE_DEATH_RACE))) {
                racer->unk_352 = 255;
                if (racer->lap >= 2) {
                    func_i3_80116A50(racer);
                }
            }
        } else if ((racer->lap >= 2) || (D_800CD010 == 1)) {
            if ((racer->unk_398 == 0) || ((u32) (racer->id + gGameFrameCount) % 64) < 4) {
                func_i3_80116A50(racer);
            }

            var_fv0 = (gCurrentCourseInfo->length * (gTotalLapCount - 1)) / (racer->unk_398 - racer->lapTimes[0]);
            spBC =
                (((racer->raceTime - racer->lapTimes[0]) * var_fv0) + gCurrentCourseInfo->length) - racer->raceDistance;
            spB4 = ((((racer->raceTime - racer->lapTimes[0]) - 0x11) * var_fv0) + gCurrentCourseInfo->length) -
                   racer->raceDistance;

            var_fv0 = func_i3_fabsf(sPlayerRacer->raceDistance - racer->raceDistance);
            racer->unk_1EC = (spBC * 0.05f) + (spBC - spB4);
            racer->unk_1E8 = 0.3f;
            if (spBC > 0.0f) {
                if (spBC > 200.0f) {
                    racer->unk_1E8 = 0.0f;
                    controller->buttonPressed |= BTN_B;
                    if (spBC > 1000.0f) {
                        racer->unk_1EC = (2500.0f / 27.0f);
                    }
                }
            } else if ((var_fv0 < 2000.0f) && (gTotalLapCount == racer->lap) &&
                       (((s32) (gCurrentCourseInfo->segmentCount * 2) / 3) <
                        racer->unk_0C.courseSegment->segmentIndex)) {
                spBC = sPlayerRacer->speed - 2.3148148f;
                if ((var_fv0 < 0.0f) && (racer->unk_1EC < spBC)) {
                    racer->unk_1EC = spBC;
                }
            }
        } else {
            if (racer->unk_39C != 0) {
                spBC = (racer->raceTime * (gCurrentCourseInfo->length / racer->unk_39C)) - racer->raceDistance;
                spB4 = ((racer->raceTime - 0x11) * (gCurrentCourseInfo->length / racer->unk_39C)) - racer->raceDistance;
                if (racer->raceDistance > 0.0f) {
                    racer->unk_1EC = (spBC * 0.05f) + (spBC - spB4);
                    racer->unk_1E8 = 1.0f;
                } else {
                    racer->unk_1EC = (2500.0f / 27.0f);
                    racer->unk_1E8 = 0.0f;
                }
            } else {
                racer->unk_1EC = func_i3_801179DC(racer);
                racer->unk_1E8 = func_i3_80117A1C(racer);
            }
        }
    }
    var_a3 = racer->unk_0C.courseSegment->segmentIndex * 4;
    if (racer->unk_0C.unk_08 >= 0.5f) {
        var_a3 += 2;
    }

    if (D_i3_8013DBE8[var_a3] < racer->unk_1EC) {
        racer->unk_1EC = D_i3_8013DBE8[var_a3];
    }
    if (((D_80141900 > 20) || (D_800F80A8[0] > 30)) && (gNumPlayers == 1) && (racer->id != 0) &&
        (racer->raceTime > 10000) && !(sPlayerRacer->stateFlags & RACER_STATE_CRASHED) &&
        (func_i3_fabsf(sPlayerRacer->unk_33C - sp94) < 138.0f)) {

        var_fv0 = sPlayerRacer->raceDistance - racer->raceDistance;
        while (var_fv0 > gCurrentCourseInfo->length * 0.5f) {
            var_fv0 -= gCurrentCourseInfo->length;
        }

        while (var_fv0 < gCurrentCourseInfo->length * -0.5f) {
            var_fv0 += gCurrentCourseInfo->length;
        }

        if (var_fv0 < 0) {
            var_fv0 = 0.0f - var_fv0;
        }
        if (var_fv0 < 500.0f) {
            if (Math_Rand1() % 2) {
                controller->buttonPressed |= BTN_R_Z_COMBO;
            } else {
                controller->buttonPressed |= BTN_Z_R_COMBO;
            }
        }
    }
    if (gCourseIndex == COURSE_FIRE_FIELD) {
        sp7C = racer->unk_0C.courseSegment->segmentIndex;
        if ((sp7C >= 4) && (sp7C < 0x10)) {
            racer->unk_1EC = (2500.0f / 27.0f);
            racer->unk_1E8 = 1.0f;
        }
    }
    controller->buttonCurrent |= BTN_A;
    if (racer->unk_340 < racer->unk_20C) {
        controller->buttonPressed |= BTN_A;
    }

    sp74 = false;
    if ((racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_PIPE) {
        if ((racer->unk_0C.courseSegment->next->next->next->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_PIPE) {
            sp74 = true;
            racer->unk_330 = 10.0f;
        } else if ((racer->unk_0C.courseSegment->next->next->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_PIPE) {
            sp74 = true;
            racer->unk_330 = 10.0f;
        } else if ((racer->unk_0C.courseSegment->next->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_PIPE) {
            sp74 = true;
            racer->unk_330 = 10.0f;
        }
    }

    if (func_8009D16C(&racer->unk_0C, racer->unk_0C.unk_34.x + (racer->unk_330 * racer->velocity.x),
                      racer->unk_0C.unk_34.y + (racer->unk_330 * racer->velocity.y),
                      racer->unk_0C.unk_34.z + (racer->unk_330 * racer->velocity.z), &sp4C) == 0) {
        if (((racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_PIPE) &&
            ((racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_CYLINDER)) {
            temp4 = racer->unk_C0.x.x;
            temp5 = racer->unk_C0.x.y;
            temp6 = racer->unk_C0.x.z;
            if (gGameMode == GAMEMODE_GP_END_CS) {
                racer->unk_33C = D_i3_8013ED1C[racer->id] * 46.0f;
                if (racer->id != 0) {
                    temp3 = ((gRacers[0].raceDistance - D_i3_8013ED10[racer->id]) - racer->raceDistance);
                    racer->unk_1EC = gRacers[0].speed + (temp3 * 0.1f);
                    racer->unk_1E8 = 1.0f;
                }
            }
            temp_fa0 = (racer->unk_338 * (((racer->unk_33C + (racer->unk_0C.unk_28.x * racer->unk_24C.z.x)) +
                                           (racer->unk_0C.unk_28.y * racer->unk_24C.z.y)) +
                                          (racer->unk_0C.unk_28.z * racer->unk_24C.z.z))) *
                       1.2f;
            temp_fa0 += (racer->unk_334 * ((temp4 * sp4C.z.x) + (temp5 * sp4C.z.y) + (temp6 * sp4C.z.z)) * 1.2f);
            var_a3 = Math_Round(temp_fa0);
        } else if (!sp74) {
            var_a3 = Math_Round(-racer->unk_334 * ((racer->unk_C0.z.x * sp4C.x.x) + (racer->unk_C0.z.y * sp4C.x.y) +
                                                   (racer->unk_C0.z.z * sp4C.x.z)));
            if (!(Math_Rand2() % 64)) {
                if (Math_Rand1() % 2) {
                    racer->unk_370 = (Math_Rand2() % 16) + 20;
                } else {
                    racer->unk_370 = -20 - (Math_Rand1() % 16);
                }
            }

            if (racer->unk_370 != 0) {
                var_a3 += (s32) (racer->unk_334 / 20.0f);
                racer->unk_370--;
            }
        } else {
            racer->unk_370 = 0;
            spB4 = (racer->unk_338 *
                    (racer->unk_C0.z.x * racer->unk_24C.y.x + racer->unk_C0.z.y * racer->unk_24C.y.y +
                     racer->unk_C0.z.z * racer->unk_24C.y.z) *
                    160.0f);
            var_a3 = Math_Round(spB4 - (racer->unk_334 * 0.5f *
                                        ((racer->unk_C0.z.x * sp4C.x.x) + (racer->unk_C0.z.y * -sp4C.x.y) +
                                         (racer->unk_C0.z.z * sp4C.x.z))));
        }
        if (racer->stateFlags & RACER_STATE_AIRBORNE) {
            var_a1 = Math_Round(-racer->unk_334 * 0.1f * DOT_XYZ(&racer->unk_C0.y, &sp4C.x));

            if (gCourseIndex == COURSE_FIRE_FIELD) {
                if ((racer->unk_0C.courseSegment->segmentIndex >= 7) &&
                    (racer->unk_0C.courseSegment->segmentIndex <= 14)) {
                    if (racer->unk_A0 > 400.0f) {
                        var_a3 = 0;
                    }
                    var_a1 = (s32) ((var_a1 * 0.25f) - (racer->unk_A0 * 0.015f));
                    var_a3 *= 5;
                }
            }

            if (var_a1 < -70) {
                var_a1 = -70;
            } else if (var_a1 > 70) {
                var_a1 = 70;
            }
            var_a3 /= 5;
            if (((racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_CYLINDER) ||
                ((racer->unk_0C.courseSegment->next->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_AIR) ||
                ((racer->unk_0C.courseSegment->next->next->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_AIR)) {
                var_a1 = 70;
                controller->buttonCurrent &= (u16) (~BTN_A);
                controller->buttonPressed &= (u16) (~BTN_A);
                controller->buttonReleased &= (u16) (~BTN_A);
            }

            if (racer->unk_33C > 0.0f) {
                racer->unk_33C -= racer->unk_354;
            } else {
                racer->unk_33C += racer->unk_354;
            }
            racer->unk_1EC = (2500.0f / 27.0f);
            if (racer->unk_1E8 >= 1.0f) {
                racer->unk_1E8 = 1.0f;
            }
        } else {
            var_a1 = 70;
            if (((racer->unk_0C.courseSegment->next->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_AIR) &&
                (racer->unk_0C.unk_08 > 0.5f)) {
                racer->unk_1EC = 69.44444f;
            }
        }
        if (var_a3 < -70) {
            var_a3 = -70;
            controller->buttonCurrent |= BTN_Z;
        } else if (var_a3 > 70) {
            var_a3 = 70;
            controller->buttonCurrent |= BTN_R;
        }
        controller->stickX = (var_a3 * 5) / 8;
        controller->stickY = var_a1;
        if (gNumPlayers == 1) {
            if (sp70 && (racer->raceTime > 1000) && (gDifficulty >= EXPERT) && (racer->id != 0) &&
                (gTotalRacers != 1) && (racer->awarenessFlags & 0x200)) {
                if ((racer->distanceFromRacerBehind < 23.0f) &&
                    (((gDifficulty >= EXPERT) && (sPlayerRacer->raceDistance < racer->raceDistance)) ||
                     ((sPlayerRacer->raceDistance + 138.0f) < racer->raceDistance)) &&
                    ((Math_Rand2() % 32768) < 16)) {
                    if (Math_Rand2() % 2) {
                        controller->buttonPressed |= BTN_R_Z_COMBO;
                    } else {
                        controller->buttonPressed |= BTN_Z_R_COMBO;
                    }
                }
                if ((racer->distanceFromRacerBehind < 23.0f) &&
                    (func_i3_fabsf(sp40->unk_33C - racer->unk_33C) < 138.0f) && (racer->driftingCounter == 0) &&
                    (((f32) (Math_Rand1() % 32768) / 32767.0f) < 0.01f)) {
                    if (racer->unk_33C < sp40->unk_33C) {
                        racer->driftingCounter = 5;
                    } else {
                        racer->driftingCounter = -5;
                    }
                }
            }

            if (racer->driftingCounter < 0) {
                racer->driftingCounter++;
                if (((racer->driftingCounter == -3) || (racer->driftingCounter == -1)) &&
                    ((gDifficulty >= EXPERT) ||
                     (func_i3_fabsf(sPlayerRacer->raceDistance - racer->raceDistance) > 184.0f)) &&
                    (sPlayerRacer->raceDistance < racer->raceDistance)) {
                    controller->buttonPressed |= BTN_Z;
                }
            } else if (racer->driftingCounter > 0) {
                racer->driftingCounter--;
                if (((racer->driftingCounter == 3) || (racer->driftingCounter == 1)) &&
                    ((gDifficulty >= EXPERT) || ((racer->raceDistance - sPlayerRacer->raceDistance) > 184.0f)) &&
                    (sPlayerRacer->raceDistance < racer->raceDistance)) {
                    controller->buttonPressed |= BTN_R;
                }
            }
            if (!(Math_Rand2() % 2048)) {
                racer->awarenessFlags &= ~0xC00;
            }
        }
        if (racer->stateFlags & COURSE_EFFECT_PIT) {
            racer->unk_394 = 180;
        }

        if (racer->unk_394 > 0) {
            racer->unk_394--;
        }

        var_a3 = racer->unk_0C.courseSegment->segmentIndex;
        if (var_a3 != racer->lastSegmentIndex) {
            racer->segmentLandmine = gCourseData.landmine[var_a3];
            racer->segmentJump = gCourseData.jump[var_a3];
            racer->segmentDirt = gCourseData.dirt[var_a3];
            racer->segmentIce = gCourseData.ice[var_a3];
            racer->segmentPit = gCourseData.pit[var_a3];
            // Look for dash pads in expert and master only
            if (gDifficulty >= EXPERT) {
                racer->segmentDash = gCourseData.dash[var_a3];
            } else {
                racer->segmentDash = DASH_NONE;
            }

            racer->trackSegmentForm = racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_FORM_MASK;
            racer->lastSegmentIndex = var_a3;

            if (++var_a3 >= gCurrentCourseInfo->segmentCount) {
                var_a3 = 0;
            }
            racer->nextSegmentLandmine = gCourseData.landmine[var_a3];
            racer->nextSegmentDirt = gCourseData.dirt[var_a3];
            racer->nextSegmentDash = gCourseData.dash[var_a3];
            racer->obstaclePriorityState = 6;
            if (racer->segmentLandmine != LANDMINE_NONE) {
                racer->obstaclePriorityState = 5;
            }
            if (racer->segmentDirt != DIRT_NONE) {
                racer->obstaclePriorityState = 4;
            }
            if (racer->segmentPit != PIT_NONE) {
                racer->obstaclePriorityState = 3;
            }
            if (racer->segmentJump == JUMP_LEFT) {
                racer->obstaclePriorityState = 2;
            }
            if (racer->segmentJump == JUMP_RIGHT) {
                racer->obstaclePriorityState = 1;
            }
        }

        if (racer->awarenessFlags & 0x800) {
            var_a3 = (racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK);
            if ((var_a3 == TRACK_SHAPE_PIPE) || (var_a3 == TRACK_SHAPE_CYLINDER)) {
                if (racer->character & 1) {
                    controller->stickX += 42;
                    if (controller->stickX > 70) {
                        controller->stickX = 70;
                    }
                } else {
                    controller->stickX -= 42;
                    if (controller->stickX < -70) {
                        controller->stickX = -70;
                    }
                }
            } else {
                var_a3 = (u32) ((racer->character * 5) + gGameFrameCount) % 280U;
                if (var_a3 > 140) {
                    var_a3 = -var_a3;
                }
                if (var_a3 > 70) {
                    var_a3 = 140 - var_a3;
                }
                if (var_a3 < -70) {
                    var_a3 = -140 - var_a3;
                }
                controller->stickX = var_a3;
                if (sPlayerRacer->raceDistance < racer->raceDistance) {
                    if (Math_Rand2() % 2) {
                        controller->buttonPressed |= BTN_R_Z_COMBO;
                    } else {
                        controller->buttonPressed |= BTN_Z_R_COMBO;
                    }
                }
            }
        } else {
            if (((racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_PIPE) &&
                ((racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_CYLINDER) &&
                (gGameMode != GAMEMODE_GP_END_CS)) {
                if ((gCourseIndex < COURSE_EDIT_1) &&
                    (((racer->raceTime > 2000) &&
                      (((racer->unk_368 % 6) < 2) ||
                       (func_i3_fabsf(racer->raceDistance - sPlayerRacer->raceDistance) > 5000.0f))) ||
                     (racer->id < gNumPlayers))) {
                    var_a3 = racer->unk_0C.courseSegment->segmentIndex * 4;
                    if (racer->unk_0C.unk_08 >= 0.5f) {
                        var_a3 += 2;
                    }
                    var_a1 = var_a3 + 2;
                    if (var_a1 >= (gCurrentCourseInfo->segmentCount * 4)) {
                        var_a1 = 0;
                    }
                    sp7C = D_i3_8013DBE8[var_a3 + 1];
                    temps = D_i3_8013DBE8[var_a1 + 1];
                    spBC = (temps - sp7C) * racer->unk_0C.unk_08 + sp7C;
                    if (gTotalRacers != 1) {
                        if (sp44->id != racer->unk_352) {
                            if ((racer->distanceToRacerAhead < 92.0f) &&
                                (func_i3_fabsf(sp44->unk_33C - spBC) < 69.0f)) {
                                if (spBC < sp44->unk_33C) {
                                    racer->unk_33C = spBC - 92.0f;
                                } else {
                                    racer->unk_33C = spBC + 92.0f;
                                }
                            } else {
                                racer->unk_33C = spBC;
                            }
                        }
                    } else {
                        racer->unk_33C = spBC;
                    }
                    if ((var_a3 != racer->lastSegmentIndex) && (sp7C & 1) && (racer->id < gNumPlayers)) {
                        var_fv0 = racer->energy / racer->maxEnergy;
                        if (var_fv0 > 0.3f) {
                            controller->buttonPressed |= BTN_A | BTN_B;
                        }
                        racer->lastSegmentIndex = racer->unk_0C.courseSegment->segmentIndex;
                    }
                    racer->unk_388 = var_a3;
                    racer->unk_330 = 0.1f;
                } else {
                    racer->unk_330 = racer->speed * 0.1f;
                    sp9C = (racer->unk_274 - racer->unk_270) * 0.5f;
                    var_fv0 = racer->energy / racer->maxEnergy;
                    switch (racer->obstaclePriorityState) {
                        case 1:
                            if (gCourseIndex != COURSE_MUTE_CITY_3) {
                                if (racer->unk_33C < sp9C + 92.0f) {
                                    racer->unk_33C = sp9C + 92.0f;
                                }
                            } else {
                                if (racer->unk_33C > sp9C - 230.0f) {
                                    racer->unk_33C = sp9C - 230.0f;
                                }
                            }
                            break;
                        case 2:
                            if (gCourseIndex != COURSE_MUTE_CITY_3) {
                                if (racer->unk_33C > sp9C - 230.0f) {
                                    racer->unk_33C = sp9C - 230.0f;
                                }
                            } else {
                                if (racer->unk_33C < sp9C + 92.0f) {
                                    racer->unk_33C = sp9C + 92.0f;
                                }
                            }
                            break;
                        case 3:
                            if ((racer->segmentPit == PIT_BOTH) && (var_fv0 < 0.99f)) {
                                racer->unk_33C = ((-racer->unk_0C.unk_28.x * racer->unk_24C.z.x) -
                                                  (racer->unk_0C.unk_28.y * racer->unk_24C.z.y)) -
                                                 (racer->unk_0C.unk_28.z * racer->unk_24C.z.z);

                                if (func_i3_fabsf(sp9C - racer->unk_33C) < 146.0f) {
                                    if (racer->unk_33C > sp9C) {
                                        racer->unk_33C += racer->unk_354 * 10.0f;
                                    } else {
                                        racer->unk_33C -= racer->unk_354 * 10.0f;
                                    }
                                }
                                break;
                            }

                            if ((racer->segmentPit == PIT_LEFT) && (var_fv0 < 0.99f)) {
                                racer->unk_33C = sp94;
                                if ((gGameMode == GAMEMODE_DEATH_RACE) && (racer->id >= gNumPlayers)) {
                                    if (racer->unk_33C < ((sp9C - 100.0f) + 46.0f)) {
                                        racer->unk_33C += (racer->unk_354 * 10.0f);
                                    }
                                } else {
                                    if (racer->unk_33C > ((sp9C - 100.0f) - 46.0f)) {
                                        racer->unk_33C -= racer->unk_354 * 10.0f;
                                    }
                                }
                                break;
                            }

                            if ((racer->segmentPit == PIT_RIGHT) && ((racer->lap == 1) || (var_fv0 < 0.99f))) {
                                racer->unk_33C = sp94;
                                if (racer->unk_33C < (sp9C + 100.0f + 46.0f)) {
                                    racer->unk_33C += racer->unk_354 * 10.0f;
                                }
                                break;
                            }
                            /* fallthrough */
                        case 4:
                            if ((racer->segmentDirt != DIRT_NONE) && (racer->awarenessFlags & 4)) {
                                if ((racer->segmentDirt == DIRT_BOTH) &&
                                    (func_i3_fabsf(sp9C - racer->unk_33C) > 77.0f)) {
                                    if (racer->unk_33C > sp9C) {
                                        racer->unk_33C -= racer->unk_354 * 4.0f;
                                    } else {
                                        racer->unk_33C += racer->unk_354 * 4.0f;
                                    }
                                    break;
                                }

                                if ((racer->segmentDirt == DIRT_RIGHT) &&
                                    (racer->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    racer->unk_33C -= racer->unk_354 * 4.0f;
                                    break;
                                }

                                if (racer->segmentDirt == DIRT_LEFT && (racer->unk_33C < ((sp9C - 100.0f) + 46.0f))) {
                                    racer->unk_33C += racer->unk_354 * 4.0f;
                                } else if (racer->segmentDirt == DIRT_MIDDLE) {
                                    if (func_i3_fabsf(sp9C - racer->unk_33C) > 146.0f) {
                                        if (racer->unk_33C < sp9C) {
                                            racer->unk_33C -= racer->unk_354 * 4.0f;
                                        } else {
                                            racer->unk_33C += racer->unk_354 * 4.0f;
                                        }
                                        break;
                                    }
                                }
                            }
                            /* fallthrough */
                        case 5:
                            if (racer->segmentLandmine != LANDMINE_NONE) {
                                if ((racer->segmentLandmine == LANDMINE_RIGHT) && (racer->unk_33C > (sp9C - 46.0f))) {
                                    racer->unk_33C -= racer->unk_354 * 3.0f;
                                    break;
                                } else if ((racer->segmentLandmine == LANDMINE_LEFT) &&
                                           (racer->unk_33C < (sp9C + 46.0f))) {
                                    racer->unk_33C += racer->unk_354 * 3.0f;
                                    break;
                                }
                            }
                            /* fallthrough */
                        case 6:
                            if ((gTotalRacers != 1) && (sp44->id != racer->unk_352) &&
                                (racer->distanceToRacerAhead < 92.0f) &&
                                (func_i3_fabsf(sp44->unk_33C - racer->unk_33C) < 92.0f)) {
                                if ((racer->unk_33C > 0.0f) && (racer->unk_274 < (racer->unk_33C + 46.0f))) {
                                    racer->unk_33C -= racer->unk_354;
                                    break;
                                }
                                if ((racer->unk_33C < 0.0f) && ((46.0f - racer->unk_33C) < racer->unk_270)) {
                                    racer->unk_33C += racer->unk_354;
                                    break;
                                }
                                if (sp44->unk_33C < racer->unk_33C) {
                                    racer->unk_33C += racer->unk_354;
                                    break;
                                }

                                racer->unk_33C -= racer->unk_354;
                                break;
                            }

                            if ((racer->segmentDash != DASH_NONE) && (racer->awarenessFlags & 1)) {
                                if ((racer->segmentDash == DASH_MIDDLE) && (racer->unk_0C.unk_08 < 0.8f) &&
                                    (func_i3_fabsf(racer->unk_33C - sp9C) < 230.0f)) {
                                    racer->unk_33C = sp9C;
                                    break;
                                }
                                if ((racer->segmentDash == DASH_LEFT) && (racer->unk_0C.unk_08 < 0.8f) &&
                                    (func_i3_fabsf(racer->unk_33C - ((-1.0f * racer->unk_270) + 100.0f)) < 230.0f)) {
                                    racer->unk_33C = (racer->unk_270 * -1.0f) + 100.0f;
                                    break;
                                }
                                if ((racer->segmentDash == DASH_RIGHT) && (racer->unk_0C.unk_08 < 0.8f)) {
                                    if (func_i3_fabsf(racer->unk_33C - (racer->unk_274 - 100.0f)) < 230.0f) {
                                        racer->unk_33C = racer->unk_274 - 100.0f;
                                        break;
                                    }
                                }
                            }
                            if ((racer->segmentIce != ICE_NONE) && (racer->awarenessFlags & 1)) {
                                if ((racer->segmentIce == ICE_BOTH) && (func_i3_fabsf(sp9C - racer->unk_33C) > 77.0f)) {
                                    if (sp9C < racer->unk_33C) {
                                        racer->unk_33C -= racer->unk_354 * 3.0f;
                                    } else {
                                        racer->unk_33C += racer->unk_354 * 3.0f;
                                    }
                                    break;
                                }

                                if ((racer->segmentIce == ICE_RIGHT) && (racer->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    racer->unk_33C -= racer->unk_354 * 3.0f;
                                    break;
                                }

                                if ((racer->segmentIce == ICE_LEFT) && (racer->unk_33C < ((sp9C - 100.0f) + 46.0f))) {
                                    racer->unk_33C += racer->unk_354 * 3.0f;
                                    break;
                                }

                                if ((racer->segmentIce == ICE_MIDDLE) &&
                                    (func_i3_fabsf(sp9C - racer->unk_33C) > 146.0f)) {
                                    if (racer->unk_33C < sp9C) {
                                        racer->unk_33C -= racer->unk_354 * 3.0f;
                                    } else {
                                        racer->unk_33C += racer->unk_354 * 3.0f;
                                    }
                                    break;
                                }
                            }

                            if ((racer->nextSegmentDirt != DIRT_NONE) && (racer->awarenessFlags & 0x10)) {
                                if ((racer->nextSegmentDirt == DIRT_BOTH) &&
                                    (func_i3_fabsf(sp9C - racer->unk_33C) > 77.0f)) {
                                    if (racer->unk_33C > sp9C) {
                                        racer->unk_33C -= racer->unk_354 * 3.0f;
                                    } else {
                                        racer->unk_33C += racer->unk_354 * 3.0f;
                                    }
                                    break;
                                }

                                if ((racer->nextSegmentDirt == DIRT_RIGHT) &&
                                    (racer->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    racer->unk_33C -= racer->unk_354 * 3.0f;
                                    break;
                                }
                                if (racer->nextSegmentDirt == DIRT_LEFT &&
                                    (racer->unk_33C < ((sp9C - 100.0f) + 46.0f))) {
                                    racer->unk_33C += racer->unk_354 * 3.0f;
                                } else {
                                    if ((racer->nextSegmentDirt == DIRT_MIDDLE) &&
                                        (func_i3_fabsf(sp9C - racer->unk_33C) > 146.0f)) {
                                        if (racer->unk_33C < sp9C) {
                                            racer->unk_33C -= racer->unk_354 * 3.0f;
                                        } else {
                                            racer->unk_33C += racer->unk_354 * 3.0f;
                                        }
                                        break;
                                    }
                                }
                            }
                            if ((racer->nextSegmentLandmine != LANDMINE_NONE) && (racer->awarenessFlags & 8)) {
                                if ((racer->nextSegmentLandmine == LANDMINE_RIGHT) &&
                                    (racer->unk_33C > (sp9C - 46.0f))) {
                                    racer->unk_33C -= racer->unk_354 * 3.0f;
                                    break;
                                } else if ((racer->nextSegmentLandmine == LANDMINE_LEFT) &&
                                           (racer->unk_33C < (sp9C + 46.0f))) {
                                    racer->unk_33C += racer->unk_354 * 3.0f;
                                    break;
                                }
                            }

                            if ((racer->nextSegmentDash != DASH_NONE) && (racer->awarenessFlags & 0x20)) {
                                if ((racer->nextSegmentDash == DASH_MIDDLE) && (racer->unk_0C.unk_08 < 0.5f) &&
                                    (func_i3_fabsf(racer->unk_33C - sp9C) < 230.0f)) {
                                    racer->unk_33C = sp9C;
                                    break;
                                } else {
                                    if ((racer->nextSegmentDash == DASH_LEFT) && (racer->unk_0C.unk_08 < 0.5f) &&
                                        (func_i3_fabsf(racer->unk_33C - ((-1.0f * racer->unk_270) + 100.0f)) <
                                         230.0f)) {
                                        racer->unk_33C = (racer->unk_270 * -1.0f) + 100.0f;
                                        break;
                                    }
                                    if ((racer->nextSegmentDash == DASH_RIGHT) && (racer->unk_0C.unk_08 < 0.5f) &&
                                        (func_i3_fabsf(racer->unk_33C - (racer->unk_274 - 100.0f)) < 230.0f)) {
                                        racer->unk_33C = racer->unk_274 - 100.0f;
                                        break;
                                    }
                                }
                            }

                            if ((racer->raceTime > 2000) && !(Math_Rand1() & 0x7F0)) {
                                if (!(Math_Rand1() % 2)) {
                                    racer->unk_33C -= 46.0f;
                                } else {
                                    racer->unk_33C += 46.0f;
                                }
                            }
                    }
                }
            }
        }
        sCharacterBehaviorFuncs[racer->character](racer, controller);
        if ((gNumPlayers == 1) && (racer->id != 0)) {
            var_fv0 = racer->raceDistance - sPlayerRacer->raceDistance;
            if ((var_fv0 > -230.0f) && (var_fv0 < -11.5f) && (func_i3_fabsf(sp94 - sPlayerRacer->unk_33C) < 92.0f)) {
                if (sPlayerRacer->unk_33C < sp94) {
                    racer->unk_33C = sPlayerRacer->unk_33C + 92.0f;
                } else {
                    racer->unk_33C = sPlayerRacer->unk_33C - 92.0f;
                }
            }
        }

        if ((racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_HALF_PIPE) {
            spBC = 92.0f;
        } else if ((racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) != TRACK_SHAPE_BORDERLESS_ROAD) {
            if (racer->trackSegmentForm == TRACK_FORM_STRAIGHT) {
                spBC = 23.0f;
            } else {
                spBC = 50.600002f;
            }
        } else {
            spBC = 92.0f;
        }
        if ((racer->trackSegmentForm == TRACK_FORM_RIGHT) ||
            ((racer->trackSegmentForm == TRACK_FORM_S) && (racer->unk_0C.unk_08 > 0.6f)) ||
            ((racer->trackSegmentForm == TRACK_FORM_S_FLIPPED) && (racer->unk_0C.unk_08 < 0.4f))) {
            if (racer->unk_33C < 0.0f) {
                if (racer->unk_270 < ((racer->unk_33C * -1.0f) + spBC)) {
                    racer->unk_33C = (racer->unk_270 - spBC) * -1.0f;
                }
            } else {
                if (racer->unk_274 < (racer->unk_33C + (spBC * 0.5f))) {
                    racer->unk_33C = racer->unk_274 - (spBC * 0.5f);
                }
            }
        } else if ((racer->trackSegmentForm == TRACK_FORM_LEFT) ||
                   ((racer->trackSegmentForm == TRACK_FORM_S) && (racer->unk_0C.unk_08 < 0.4f)) ||
                   ((racer->trackSegmentForm == TRACK_FORM_S_FLIPPED) && (racer->unk_0C.unk_08 > 0.6f))) {
            if (racer->unk_33C < 0.0f) {
                if (racer->unk_270 < ((racer->unk_33C * -1.0f) + (spBC * 0.5f))) {
                    racer->unk_33C = (racer->unk_270 - (spBC * 0.5f)) * -1.0f;
                }
            } else {
                if (racer->unk_274 < (racer->unk_33C + spBC)) {
                    racer->unk_33C = racer->unk_274 - spBC;
                }
            }
        } else {
            if (racer->unk_33C < 0.0f) {
                if (racer->unk_270 < ((racer->unk_33C * -1.0f) + spBC)) {
                    racer->unk_33C = (racer->unk_270 - spBC) * -1.0f;
                }
            } else {
                if (racer->unk_274 < (racer->unk_33C + spBC)) {
                    racer->unk_33C = racer->unk_274 - spBC;
                }
            }
        }
        if ((gNumPlayers == 1) && (racer->id != 0)) {
            var_fv0 = sPlayerRacer->raceDistance - racer->raceDistance;
            if ((var_fv0 > 0.0f) && (var_fv0 < 92.0f) &&
                (func_i3_fabsf(sPlayerRacer->unk_33C - racer->unk_33C) < 69.0f)) {
                if (sPlayerRacer->speed < racer->unk_1EC) {
                    racer->unk_1EC = sPlayerRacer->speed;
                }
            }
        }
        if (racer->unk_1EC < (625.0f / 27.0f)) {
            racer->unk_1EC = (625.0f / 27.0f);
        }
        if ((racer->stateFlags & RACER_STATE_FLAGS_2000000) || (gGameMode == GAMEMODE_GP_END_CS)) {
            racer->awarenessFlags &= ~0xA00;
            if (racer->id < gNumPlayers) {
                controller->buttonPressed &= ~BTN_B;
            }
            if (D_i3_80141908 != 0) {
                // FAKE!
                if (1) {}
                var_a1 = 0;
                for (i = 0; i < gTotalRacers; i++) {
                    if (gRacers[i].trackSegmentForm == TRACK_FORM_STRAIGHT) {
                        var_a1++;
                    }
                }

                if (var_a1 == gTotalRacers) {
                    if (racer->id == 0) {
                        D_i3_8014190C++;
                    }
                    if (D_i3_8014190C > 60) {
                        racer->unk_1EC = racer->speed * 0.1f;
                        controller->buttonCurrent |= BTN_CDOWN;
                        controller->buttonCurrent &= (u16) (~BTN_A);
                        controller->buttonPressed &= (u16) (~BTN_A);
                        controller->buttonReleased &= (u16) (~BTN_A);
                    }
                }
            }
            if (racer->awarenessFlags & 0x1000) {
                controller->buttonCurrent |= BTN_CDOWN;
                controller->buttonCurrent &= (u16) (~BTN_A);
                controller->buttonPressed &= (u16) (~BTN_A);
                controller->buttonReleased &= (u16) (~BTN_A);
            }
        }
        racer->lastStickX = controller->stickX;
        racer->lastStickY = controller->stickY;
        racer->lastButtonsPressed = controller->buttonPressed;
        racer->lastButtonsCurrent = controller->buttonCurrent;
    }
}
