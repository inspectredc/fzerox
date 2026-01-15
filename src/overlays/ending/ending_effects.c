#include "global.h"
#include "ending.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_machine.h"
#include "fzx_camera.h"
#include "assets/segment_16C8A0.h"
#include "assets/segment_1B8550.h"
#include "assets/segment_2B9EA0.h"

s16 sFireworksLauncherCount;
s16 gActiveFireworks;
Firework* sFireworks;
FireworksLauncher* sFireworksLaunchers;
UNUSED u8 D_i7_8014BFA0[0x80];
bool D_i7_8014C020;
UNUSED s32 D_i7_8014C024;
u16* sPodiumRacerCharacterTextures[3];
u16* sPodiumRacerPortraitTexture;
u16* sPodiumRacerCharacterTexture;
u16* sPodiumRacerCharacterTextureP2;
u16* sPodiumRacerCharacterTextureP3;
s32 sPodiumRacerCharacterAllocationState;
u8 sCharacterFireworkBuffer[0x200];
s32 sFireworksType;

s32 sEndingCharacterTimer = 0;
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

u8 sFireworksBitMask[] = { 1 << 7, 1 << 6, 1 << 5, 1 << 4, 1 << 3, 1 << 2, 1 << 1, 1 << 0 };

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

u8 sCharacterFireworkColors[][3] = {
    { 255, 255, 255 }, { 255, 248, 248 }, { 255, 240, 240 }, { 255, 232, 232 }, { 255, 224, 224 }, { 255, 216, 216 },
    { 255, 208, 208 }, { 255, 200, 200 }, { 255, 192, 192 }, { 255, 184, 184 }, { 255, 176, 176 }, { 255, 168, 168 },
    { 255, 160, 160 }, { 255, 152, 152 }, { 255, 144, 144 }, { 255, 136, 136 }, { 255, 128, 128 }, { 255, 120, 120 },
    { 255, 112, 112 }, { 255, 104, 104 }, { 255, 96, 96 },   { 255, 88, 88 },   { 255, 80, 80 },   { 255, 72, 72 },
    { 255, 64, 64 },   { 255, 56, 56 },   { 255, 48, 48 },   { 255, 40, 40 },   { 255, 32, 32 },   { 255, 24, 24 },
    { 255, 16, 16 },   { 255, 8, 8 },
};

TexturePtr sFireworkBubbleTextures[] = {
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

Vtx aPodiumRacerCharacterVtx[] = {
    VTX(-160, 420, 0, 0, 0, 0, 0, 0, 255),
    VTX(160, 420, 0, 992, 0, 0, 0, 0, 255),
    VTX(160, 0, 0, 992, 1312, 0, 0, 0, 255),
    VTX(-160, 0, 0, 0, 1312, 0, 0, 0, 255),
};

Gfx aPodiumRacerCharacterDL[] = {
    gsSPVertex(aPodiumRacerCharacterVtx, 4, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSP1Triangle(0, 3, 2, 0),
    gsSPEndDisplayList(),
};

extern s32 gTotalRacers;
extern s16 gPlayer1OverallPosition;

void EndingCutsceneEffects_InitPodiumRacerCharacters(void) {
    s32 var_a0;
    s32 var_v0;
    s32 i;
    s32 j;
    s32 character;

    sPodiumRacerCharacterAllocationState = 0;
    if ((sCupDifficulty > NOVICE) && (gPlayer1OverallPosition < 4)) {
        sPodiumRacerCharacterAllocationState = 1;
        sPodiumRacerCharacterTexture = Arena_Allocate(ALLOC_FRONT, 0xA80);
        sPodiumRacerCharacterTextureP2 = Arena_Allocate(ALLOC_FRONT, 0xA80);
        sPodiumRacerCharacterTextureP3 = Arena_Allocate(ALLOC_FRONT, 0xA80);

        for (j = 0; j < 32 * 42; j++) {
            sPodiumRacerCharacterTexture[j] = sPodiumRacerCharacterTextureP2[j] = sPodiumRacerCharacterTextureP3[j] = 0;
        }

        for (i = gTotalRacers - 1; i >= 0; i--) {

            character = gRacers[i].character;
            j = character;
            if ((character == CAPTAIN_FALCON) && IS_SUPER_MACHINE(gRacers[i].customType)) {
                j = 30;
            } else if ((character == SAMURAI_GOROH) && IS_SUPER_MACHINE(gRacers[i].customType)) {
                j = 31;
            } else if ((character == JODY_SUMMER) && IS_SUPER_MACHINE(gRacers[i].customType)) {
                j = 32;
            }
            sPodiumRacerPortraitTexture = func_80078104(sFullPortraits[j], 180 * 245 * sizeof(u16), 0, 1, 1);

            // Resize texture
            for (j = 0; j != 42; j++) {
                for (var_a0 = 0; var_a0 < 32; var_a0++) {
                    var_v0 = (s32) (var_a0 * (180.0f / 32.0f)) + (s32) ((245.0f / 42.0f) * j) * 180;
                    sPodiumRacerCharacterTexture[var_a0 + j * 32] = sPodiumRacerPortraitTexture[var_v0];
                }
            }

            // Lower texture to bottom
            j = 0;
            while (j == 0) {
                j = 0;

                for (var_a0 = 32 * (42 - 1); var_a0 < 32 * 42; var_a0++) {
                    if (sPodiumRacerCharacterTexture[var_a0] != 0) {
                        j++;
                    }
                }

                if (j == 0) {

                    for (var_a0 = 42 - 1; var_a0 > 0; var_a0--) {
                        for (var_v0 = 0; var_v0 < 32; var_v0++) {
                            sPodiumRacerCharacterTexture[var_a0 * 32 + var_v0] =
                                sPodiumRacerCharacterTexture[var_a0 * 32 + var_v0 - 32];
                        }
                    }

                    for (var_v0 = 0; var_v0 < 32; var_v0++) {
                        sPodiumRacerCharacterTexture[var_v0] = 0;
                    }
                }
            }

            for (j = 0; j < 32; j++) {
                sPodiumRacerCharacterTexture[j] = 0;
            }

            if (i == 2) {
                for (j = 0; j < 32 * 42; j++) {
                    sPodiumRacerCharacterTextureP3[j] = sPodiumRacerCharacterTexture[j];
                }
            }

            if (i == 1) {
                for (j = 0; j < 32 * 42; j++) {
                    sPodiumRacerCharacterTextureP2[j] = sPodiumRacerCharacterTexture[j];
                }
            }
        }
        sPodiumRacerCharacterTextures[0] = sPodiumRacerCharacterTexture;
        sPodiumRacerCharacterTextures[1] = sPodiumRacerCharacterTextureP2;
        sPodiumRacerCharacterTextures[2] = sPodiumRacerCharacterTextureP3;
    }
}

void EndingCutsceneEffects_UpdatePodiumRacerCharacters(void) {
    Racer* racer;
    s32 i;

    if (sPodiumRacerCharacterAllocationState == 1) {
        for (i = 0; i < gTotalRacers; i++) {
            racer = &gRacers[i];
            Matrix_SetLockedLookAt(&gPodiumDrawDataPtr->racerCharacterMtx[i], NULL, 0.04f, 0.04f, 0.04f,
                                   -gCameras[0].basis.x.x, -gCameras[0].basis.x.y, -gCameras[0].basis.x.z,
                                   racer->trueBasis.y.x, racer->trueBasis.y.y, racer->trueBasis.y.z,
                                   racer->shadowPos.x + ((racer->trueBasis.x.x * 23.0f * 3.0f) / 2) +
                                       (racer->trueBasis.z.x * 23.0f * 0.8f),
                                   (gPodiums[i].pos.y + 120.0f) - 1.0f,
                                   racer->shadowPos.z + ((racer->trueBasis.x.z * 23.0f * 3.0f) / 2) +
                                       (racer->trueBasis.z.z * 23.0f * 0.8f));
        }
    }
}

Gfx* EndingCutsceneEffects_DrawPodiumRacerCharacters(Gfx* gfx) {
    s32 i;

    if ((sPodiumRacerCharacterAllocationState == 1) && (gPodiumActiveFlags != 0)) {
        gSPDisplayList(gfx++, D_400A258);
        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);

        for (i = 0; i < gTotalRacers; i++) {
            gDPPipeSync(gfx++);

            gDPLoadTextureBlock(gfx++, sPodiumRacerCharacterTextures[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 42, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPMatrix(gfx++, &gPodiumDrawDataPtr->racerCharacterMtx[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            gSPDisplayList(gfx++, aPodiumRacerCharacterDL);
        }
    }
    return gfx;
}

extern s16 gRacersRemaining;
extern s32 gCupType;

void EndingCutsceneEffects_Init(void) {
    s32 i;

    gRacersRemaining = gTotalRacers;
    if (gPlayer1OverallPosition < 4) {
        EndingCutsceneEffects_InitPodiumRacerCharacters();
        sFireworks = Arena_Allocate(ALLOC_FRONT, MAX_FIREWORKS_LAUNCHERS * 100 * sizeof(Firework));
        sFireworksLaunchers = Arena_Allocate(ALLOC_FRONT, MAX_FIREWORKS_LAUNCHERS * sizeof(FireworksLauncher));
        sFireworksLauncherCount = MAX_FIREWORKS_LAUNCHERS;

        for (i = 0; i < sFireworksLauncherCount; i++) {
            sFireworksLaunchers[i].state = FIREWORKS_CREATE;
        }

        sFireworksType = FIREWORKS_NONE;
        D_i7_8014C020 = false;
        if (gPlayer1OverallPosition == 1) {
            if (gCupType == X_CUP) {
                func_80077CF0(D_i7_8014AD18[Math_Rand1() % 4], 0x200, sCharacterFireworkBuffer);
            } else if ((gRacers[0].character == CAPTAIN_FALCON) && IS_SUPER_MACHINE(gRacers[0].customType)) {
                func_80077CF0(D_i7_8014AD0C, 0x200, sCharacterFireworkBuffer);
            } else if ((gRacers[0].character == SAMURAI_GOROH) && IS_SUPER_MACHINE(gRacers[0].customType)) {
                func_80077CF0(D_i7_8014AD10, 0x200, sCharacterFireworkBuffer);
            } else if ((gRacers[0].character == JODY_SUMMER) && IS_SUPER_MACHINE(gRacers[0].customType)) {
                func_80077CF0(D_i7_8014AD14, 0x200, sCharacterFireworkBuffer);
            } else {
                func_80077CF0(D_i7_8014AC94[gRacers[0].character], 0x200, sCharacterFireworkBuffer);
            }
        } else {
            func_80077CF0(D_i7_8014AD28, 0x200, sCharacterFireworkBuffer);
        }
    }
}

void EndingCutsceneEffects_Update(void) {
    s32 var_s1;
    s32 i;
    s32 j;
    Camera* camera = &gCameras[0];
    FireworksLauncher* fireworksLauncher;
    Firework* firework;
    bool otherFireworksActive;
    f32 var_fs0;
    f32 var_fs0_2;
    f32 var_fs1;
    f32 var_fs1_2;
    f32 var_fs2;
    f32 var_fa0;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fa1;
    f32 temp_fv0_6;
    f32 temp_fv0_9;
    f32 temp_fv0_12;
    f32 var_fv1;
    f32 temp_fv1_5;
    f32 temp1;
    s32 pad[21];

    if (gPlayer1OverallPosition > 3) {
        return;
    }

    EndingCutsceneEffects_UpdatePodiumRacerCharacters();
    sEndingCharacterTimer++;

    for (i = 0; i < sFireworksLauncherCount; i++) {
        fireworksLauncher = &sFireworksLaunchers[i];
        fireworksLauncher->previousState = fireworksLauncher->state;

        switch (sFireworksLaunchers[i].state) {
            case FIREWORKS_CREATE:
                fireworksLauncher->pos.x = (Math_Rand1() % 256) - 128.1f;
                fireworksLauncher->pos.z = (Math_Rand1() % 256) - 128.1f;

                var_fv1 = sqrtf(SQ(fireworksLauncher->pos.x) + SQ(fireworksLauncher->pos.z));

                if (var_fv1 < 0.001f) {
                    var_fv1 = 0.001f;
                }

                var_fv1 = 1.0f / var_fv1;

                fireworksLauncher->pos.x = fireworksLauncher->pos.x * var_fv1 * 700.0f;
                fireworksLauncher->pos.z = fireworksLauncher->pos.z * var_fv1 * 700.0f;

                fireworksLauncher->pos.y = ((Math_Rand1() % 16) + 0x190) * -1.0f;
                fireworksLauncher->left = fireworksLauncher->top = FIREWORK_OFFSCREEN;
                fireworksLauncher->velocity.y = 25.0f;
                fireworksLauncher->velocity.x = ((Math_Rand1() % 256) - 128.0f) * 0.01f;
                fireworksLauncher->velocity.z = ((Math_Rand1() % 256) - 128.0f) * 0.01f;
                fireworksLauncher->unk_3C = Math_Rand1() % 7;
                fireworksLauncher->style = Math_Rand1() % 7;
                fireworksLauncher->fuseTimer = Math_Rand1() % (128 - (sCupDifficulty * 32));
                fireworksLauncher->scale = 1.2f;
                switch (sFireworksType) {
                    case FIREWORKS_NONE:
                        break;
                    case FIREWORKS_SIDE:
                        fireworksLauncher->indexStart = i * 100;
                        fireworksLauncher->count = 100;
                        fireworksLauncher->state = FIREWORKS_WAIT_FOR_LAUNCH;
                        break;
                    case FIREWORKS_CHARACTER:
                        if (i == 0) {
                            otherFireworksActive = false;
                            for (var_s1 = 0; var_s1 < sFireworksLauncherCount; var_s1++) {
                                if (sFireworksLaunchers[var_s1].state != FIREWORKS_CREATE) {
                                    otherFireworksActive = true;
                                }
                            }

                            if (!otherFireworksActive) {
                                fireworksLauncher->indexStart = 0;
                                fireworksLauncher->count = 800;
                                fireworksLauncher->state = FIREWORKS_WAIT_FOR_LAUNCH;
                                fireworksLauncher->style = FIREWORKS_STYLE_CHARACTER;
                                sFireworksType = FIREWORKS_NONE;
                                fireworksLauncher->pos.x = camera->basis.x.x * 700.0f;
                                fireworksLauncher->pos.z = camera->basis.x.z * 700.0f;
                                fireworksLauncher->velocity.x = 0.0f;
                                fireworksLauncher->velocity.z = 0.0f;
                                fireworksLauncher->pos.y = -500.0f;
                                fireworksLauncher->scale = 1.5f;
                                fireworksLauncher->velocity.y = 28.0f;
                                sFireworksLauncherCount = 1;
                            }
                        }
                        break;
                }
                if (fireworksLauncher->state == FIREWORKS_WAIT_FOR_LAUNCH) {
                    for (j = fireworksLauncher->indexStart;
                         j < fireworksLauncher->indexStart + fireworksLauncher->count; j++) {
                        firework = &sFireworks[j];
                        firework->unk_28 = firework->unk_2C = 0;
                        firework->left = firework->top = FIREWORK_OFFSCREEN;
                    }
                }
                break;
            case FIREWORKS_WAIT_FOR_LAUNCH:
                if (fireworksLauncher->fuseTimer > 0) {
                    fireworksLauncher->fuseTimer--;
                } else {
                    fireworksLauncher->state = FIREWORKS_LAUNCH;
                }
                break;
            case FIREWORKS_LAUNCH:
                fireworksLauncher->pos.x += fireworksLauncher->velocity.x;
                fireworksLauncher->pos.y += fireworksLauncher->velocity.y;
                fireworksLauncher->pos.z += fireworksLauncher->velocity.z;
                fireworksLauncher->velocity.y -= 0.5f;
                if (fireworksLauncher->velocity.y < 0.0f) {
                    fireworksLauncher->state = FIREWORKS_EXPLODE;
                    var_s1 = 0;
                    if (fireworksLauncher->style == FIREWORKS_STYLE_CHARACTER) {
                        Audio_Hanabi(0x40, 0x7F);
                    } else {
                        var_fs0_2 = fireworksLauncher->pos.x;
                        temp_ft4 = fireworksLauncher->pos.y;
                        temp_ft5 = fireworksLauncher->pos.z;
                        var_fa0 = sqrtf(SQ(var_fs0_2) + SQ(temp_ft4) + SQ(temp_ft5));

                        if (var_fa0 != 0.0f) {
                            var_fv1 = -((camera->basis.z.z * temp_ft5) +
                                        ((var_fs0_2 * camera->basis.z.x) + (temp_ft4 * camera->basis.z.y))) /
                                      var_fa0;
                            var_fa0 *= var_fv1;
                        }
                        if ((var_fa0 >= -1000) && (var_fa0 <= 1000)) {
                            Audio_Hanabi((s32) (f32) (u32) (((var_fa0 + 1000.0f) / 2000.0f) * 127.0f), 0x40);
                        }
                    }
                    var_fs1_2 = sqrtf(SQ(gCameras[0].basis.z.x) + SQ(gCameras[0].basis.z.z));

                    if (var_fs1_2 < 0.0001f) {
                        var_fs1_2 = 0.0001f;
                    }

                    var_fs1_2 = 1.0f / var_fs1_2;
                    for (j = fireworksLauncher->indexStart;
                         j < fireworksLauncher->indexStart + fireworksLauncher->count; j++) {
                        firework = &sFireworks[j];
                        firework->pos.x = fireworksLauncher->pos.x;
                        firework->pos.y = fireworksLauncher->pos.y;
                        firework->pos.z = fireworksLauncher->pos.z;

                        switch (fireworksLauncher->style) {
                            case FIREWORKS_STYLE_0:
                                firework->velocity.x = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.z = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.y = (Math_Rand1() % 5) + 5.1f;
                                break;
                            case FIREWORKS_STYLE_1:
                                firework->velocity.x = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.z = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.y = Math_Rand1() % 5;
                                break;
                            case FIREWORKS_STYLE_2:
                                firework->velocity.x = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.z = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.y = (Math_Rand1() % 10) - 5.1f;
                                break;
                            case FIREWORKS_STYLE_3:
                                firework->velocity.x = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.z = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.y = 0.0f;
                                break;
                            case FIREWORKS_STYLE_4:
                                firework->velocity.x = 0.0f;
                                firework->velocity.z = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.y = (Math_Rand1() % 10) - 5.1f;
                                break;
                            case FIREWORKS_STYLE_5:
                                firework->velocity.x = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.z = 0.0f;
                                firework->velocity.y = (Math_Rand1() % 10) - 5.1f;
                                break;
                            case FIREWORKS_STYLE_6:
                                switch (j % 3) {
                                    case 0:
                                        firework->velocity.z = (Math_Rand1() % 10) - 5.0f;
                                        firework->velocity.x = 0.0f;
                                        firework->velocity.y = (Math_Rand1() % 10) - 5.0f;
                                        break;
                                    case 1:
                                        firework->velocity.x = (Math_Rand1() % 10) - 5.0f;
                                        firework->velocity.y = 0.0f;
                                        firework->velocity.z = (Math_Rand1() % 10) - 5.0f;
                                        break;
                                    default:
                                        firework->velocity.x = (Math_Rand1() % 10) - 5.0f;
                                        firework->velocity.z = 0.0f;
                                        firework->velocity.y = (Math_Rand1() % 10) - 5.0f;
                                        break;
                                }
                                break;
                            case FIREWORKS_STYLE_CHARACTER:
                                while (!(sCharacterFireworkBuffer[var_s1 >> 3] & sFireworksBitMask[var_s1 & 7])) {
                                    var_s1++;
                                    if (var_s1 >= 0x1000) {
                                        var_s1 = 0;
                                    }
                                }

                                temp_fv0_6 = -(((var_s1 & 0x3F) - 0x20) * 0.12f);

                                firework->velocity.x = ((gCameras[0].basis.z.x * var_fs1_2 * 0.866f) -
                                                        (gCameras[0].basis.z.z * var_fs1_2 * 0.5f)) *
                                                       temp_fv0_6;
                                firework->velocity.z = ((gCameras[0].basis.z.z * var_fs1_2 * 0.866f) +
                                                        (gCameras[0].basis.z.x * var_fs1_2 * 0.5f)) *
                                                       temp_fv0_6;

                                firework->velocity.y = ((-(f32) ((var_s1 >> 6) - 0x48)) * 0.12f);
                                var_s1++;
                                break;
                            default:
                                firework->velocity.x = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.z = (Math_Rand1() % 10) - 5.1f;
                                firework->velocity.y = (Math_Rand1() % 10) - 5.1f;
                                break;
                        }
                        if (fireworksLauncher->style != FIREWORKS_STYLE_CHARACTER) {
                            var_fs0 =
                                sqrtf(SQ(firework->velocity.x) + SQ(firework->velocity.y) + SQ(firework->velocity.z));

                            if (var_fs0 < 0.0001f) {
                                var_fs0 = 0.0001f;
                            }

                            temp_fv0_9 = (((Math_Rand1() % 100) / 100.0f) - 0.5f) + 4.0f;
                            firework->velocity.x = (firework->velocity.x / var_fs0) * temp_fv0_9;
                            firework->velocity.y = (firework->velocity.y / var_fs0) * temp_fv0_9;
                            firework->velocity.z = (firework->velocity.z / var_fs0) * temp_fv0_9;
                        }
                    }
                }
                break;
            case FIREWORKS_EXPLODE:
                for (j = fireworksLauncher->indexStart; j < fireworksLauncher->indexStart + fireworksLauncher->count;
                     j++) {
                    firework = &sFireworks[j];
                    firework->pos.x += firework->velocity.x;
                    firework->pos.y += firework->velocity.y;
                    firework->pos.z += firework->velocity.z;
                    if (fireworksLauncher->style != FIREWORKS_STYLE_CHARACTER) {
                        firework->velocity.y = (firework->velocity.y * 0.98f) - 0.05f;
                        firework->velocity.x = firework->velocity.x * 0.98f;
                        firework->velocity.z = firework->velocity.z * 0.98f;
                    } else {
                        firework->velocity.y = (firework->velocity.y * 0.985f) - 0.04f;
                        firework->velocity.x = firework->velocity.x * 0.985f;
                        firework->velocity.z = firework->velocity.z * 0.985f;
                    }
                }
                if (fireworksLauncher->style != FIREWORKS_STYLE_CHARACTER) {
                    fireworksLauncher->scale -= 0.01f;
                } else {
                    fireworksLauncher->scale -= 0.007f;
                }
                if (fireworksLauncher->scale <= 0) {
                    fireworksLauncher->state = FIREWORKS_CREATE;
                    fireworksLauncher->left = fireworksLauncher->top = FIREWORK_OFFSCREEN;
                    fireworksLauncher->scale = 0;
                    for (j = fireworksLauncher->indexStart;
                         j < fireworksLauncher->indexStart + fireworksLauncher->count; j++) {
                        firework = &sFireworks[j];
                        firework->left = firework->top = FIREWORK_OFFSCREEN;
                    }
                }
                break;
        }

        if ((fireworksLauncher->state >= FIREWORKS_EXPLODE) ||
            (D_i7_8014C020 && (fireworksLauncher->state > FIREWORKS_CREATE))) {
            var_fs2 = fireworksLauncher->pos.x;
            var_fs0 = fireworksLauncher->pos.z;
            var_fa0 = sqrtf(SQ(var_fs2) + SQ(var_fs0));

            if (var_fa0 < 0.001f) {
                var_fa0 = 0.001f;
            }
            var_fa0 = 1.0f / var_fa0;
            var_fs2 *= var_fa0;
            var_fs0 *= var_fa0;
            if (((var_fs0 * camera->basis.x.z) + (var_fs2 * camera->basis.x.x)) < 0.4f) {
                fireworksLauncher->state = FIREWORKS_CREATE;
                fireworksLauncher->scale = 0;
                fireworksLauncher->left = fireworksLauncher->top = FIREWORK_OFFSCREEN;
                for (j = fireworksLauncher->indexStart; j < fireworksLauncher->indexStart + fireworksLauncher->count;
                     j++) {
                    firework = &sFireworks[j];
                    firework->left = firework->top = FIREWORK_OFFSCREEN;
                }
            }
        }

        if (fireworksLauncher->state >= FIREWORKS_LAUNCH) {
            if (fireworksLauncher->state != FIREWORKS_EXPLODE) {
                firework = &sFireworks[fireworksLauncher->indexStart];
                temp_fv0_12 = camera->eye.x + fireworksLauncher->pos.x;
                temp_fv1_5 = fireworksLauncher->pos.y;
                temp_fa1 = camera->eye.z + fireworksLauncher->pos.z;

                var_fs0_2 = (temp_fv0_12 - camera->eye.x);
                temp_ft4 = (temp_fv1_5 - camera->eye.y);
                temp_ft5 = (temp_fa1 - camera->eye.z);
                var_fa0 =
                    (var_fs0_2 * camera->basis.x.x) + (temp_ft4 * camera->basis.x.y) + (temp_ft5 * camera->basis.x.z);
                if (var_fa0 <= 0) {
                    fireworksLauncher->left = fireworksLauncher->top = FIREWORK_OFFSCREEN;
                } else {
                    var_fs2 = ((camera->projectionViewMtx.m[0][0] * temp_fv0_12) +
                               (camera->projectionViewMtx.m[1][0] * temp_fv1_5) +
                               (camera->projectionViewMtx.m[2][0] * temp_fa1)) +
                              camera->projectionViewMtx.m[3][0];
                    var_fs1 = ((camera->projectionViewMtx.m[0][1] * temp_fv0_12) +
                               (camera->projectionViewMtx.m[1][1] * temp_fv1_5) +
                               (camera->projectionViewMtx.m[2][1] * temp_fa1)) +
                              camera->projectionViewMtx.m[3][1];
                    temp1 = ((camera->projectionViewMtx.m[0][2] * temp_fv0_12) +
                             (camera->projectionViewMtx.m[1][2] * temp_fv1_5) +
                             (camera->projectionViewMtx.m[2][2] * temp_fa1)) +
                            camera->projectionViewMtx.m[3][2];
                    var_fs0 = ((camera->projectionViewMtx.m[0][3] * temp_fv0_12) +
                               (camera->projectionViewMtx.m[1][3] * temp_fv1_5) +
                               (camera->projectionViewMtx.m[2][3] * temp_fa1)) +
                              camera->projectionViewMtx.m[3][3];
                    if (func_i3_fabsf(var_fs0) < 0.001f) {
                        firework->left = firework->top = FIREWORK_OFFSCREEN;
                    } else {
                        fireworksLauncher->left =
                            camera->currentVpTransX + ((var_fs2 * camera->currentVpScaleX) / var_fs0);
                        fireworksLauncher->top =
                            camera->currentVpTransY - ((var_fs1 * camera->currentVpScaleY) / var_fs0);

                        if ((fireworksLauncher->left < camera->currentScissorLeft) ||
                            (camera->currentScissorRight < fireworksLauncher->left) ||
                            (fireworksLauncher->top < camera->currentScissorTop) ||
                            (camera->currentScissorBottom < fireworksLauncher->top)) {
                            fireworksLauncher->left = fireworksLauncher->top = FIREWORK_OFFSCREEN;
                        }
                    }
                }
            } else {
                for (j = fireworksLauncher->indexStart; j < fireworksLauncher->indexStart + fireworksLauncher->count;
                     j++) {
                    firework = &sFireworks[j];
                    temp_fv0_12 = gCameras[0].eye.x + firework->pos.x;
                    temp_fv1_5 = firework->pos.y;
                    temp_fa1 = gCameras[0].eye.z + firework->pos.z;

                    var_fs0_2 = (temp_fv0_12 - camera->eye.x);
                    temp_ft4 = (temp_fv1_5 - camera->eye.y);
                    temp_ft5 = (temp_fa1 - camera->eye.z);
                    var_fa0 = (var_fs0_2 * camera->basis.x.x) + (temp_ft4 * camera->basis.x.y) +
                              (temp_ft5 * camera->basis.x.z);
                    if (var_fa0 <= 0) {
                        firework->left = firework->top = FIREWORK_OFFSCREEN;
                    } else {
                        var_fs2 = ((camera->projectionViewMtx.m[0][0] * temp_fv0_12) +
                                   (camera->projectionViewMtx.m[1][0] * temp_fv1_5) +
                                   (camera->projectionViewMtx.m[2][0] * temp_fa1)) +
                                  camera->projectionViewMtx.m[3][0];
                        var_fs1 = ((camera->projectionViewMtx.m[0][1] * temp_fv0_12) +
                                   (camera->projectionViewMtx.m[1][1] * temp_fv1_5) +
                                   (camera->projectionViewMtx.m[2][1] * temp_fa1)) +
                                  camera->projectionViewMtx.m[3][1];
                        temp1 = ((camera->projectionViewMtx.m[0][2] * temp_fv0_12) +
                                 (camera->projectionViewMtx.m[1][2] * temp_fv1_5) +
                                 (camera->projectionViewMtx.m[2][2] * temp_fa1)) +
                                camera->projectionViewMtx.m[3][2];
                        var_fs0 = ((camera->projectionViewMtx.m[0][3] * temp_fv0_12) +
                                   (camera->projectionViewMtx.m[1][3] * temp_fv1_5) +
                                   (camera->projectionViewMtx.m[2][3] * temp_fa1)) +
                                  camera->projectionViewMtx.m[3][3];
                        if (func_i3_fabsf(var_fs0) < 0.001f) {
                            firework->left = firework->top = FIREWORK_OFFSCREEN;
                        } else {
                            firework->left = camera->currentVpTransX + ((var_fs2 * camera->currentVpScaleX) / var_fs0);
                            firework->top = camera->currentVpTransY - ((var_fs1 * camera->currentVpScaleY) / var_fs0);

                            if ((firework->left < camera->currentScissorLeft) ||
                                (camera->currentScissorRight < firework->left) ||
                                (firework->top < camera->currentScissorTop) ||
                                (camera->currentScissorBottom < firework->top)) {
                                firework->left = firework->top = FIREWORK_OFFSCREEN;
                            }
                        }
                    }
                }
            }
        }
    }
    gActiveFireworks = 0;
    for (j = 0; j < sFireworksLauncherCount; j++) {
        if (sFireworksLaunchers[j].state != FIREWORKS_CREATE) {
            gActiveFireworks++;
        }
    }
}

Gfx* EndingCutsceneEffects_DrawFireworks(Gfx* gfx) {
    FireworksLauncher* fireworksLauncher;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 i;
    s32 j;
    s32 red;
    s32 green;
    s32 blue;
    f32 scale;
    s32 colorIndex;
    Firework* firework;
    s32 pad;

    if (gPlayer1OverallPosition >= 4) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    for (i = 0; i < sFireworksLauncherCount; i++) {
        if (sFireworksLaunchers[i].state >= FIREWORKS_LAUNCH) {
            fireworksLauncher = &sFireworksLaunchers[i];
            scale = fireworksLauncher->scale * 0.5f;

            if (scale > 0.8f) {
                scale = 0.8f;
            }

            if (scale < 0.1f) {
                continue;
            }

            func_8006ADE4((i * 0x600) / sFireworksLauncherCount, Math_Rand1() % 256, 255, &red, &green, &blue);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, red, green, blue, (s32) ((scale / 0.8f) * 255.0f));
            gDPLoadTextureBlock(gfx++, sFireworkBubbleTextures[Math_Rand1() % 3], G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            if (sFireworksLaunchers[i].state != FIREWORKS_EXPLODE) {
                if (fireworksLauncher->left != FIREWORK_OFFSCREEN) {
                    left = (s32) ((fireworksLauncher->left * 4.0f) - (4.0f * scale));
                    top = (s32) ((fireworksLauncher->top * 4.0f) - (4.0f * scale));
                    right = (s32) (((fireworksLauncher->left + 7.0f) * 4.0f) + (4.0f * scale));
                    bottom = (s32) (((fireworksLauncher->top + 7.0f) * 4.0f) + (4.0f * scale));
                    gSPTextureRectangle(gfx++, left, top, right, bottom, 0, 0, 0, (s32) (1024.0f / scale),
                                        (s32) (1024.0f / scale));
                }
            } else {
                for (j = sFireworksLaunchers[i].indexStart;
                     j < sFireworksLaunchers[i].indexStart + sFireworksLaunchers[i].count; j++) {
                    if ((fireworksLauncher->style == FIREWORKS_STYLE_CHARACTER) && !(j & 0x1F)) {
                        colorIndex = Math_Rand1() % 32;

                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, sCharacterFireworkColors[colorIndex][0],
                                        sCharacterFireworkColors[colorIndex][1],
                                        sCharacterFireworkColors[colorIndex][2], (s32) ((scale / 0.8f) * 255.0f));
                        gDPLoadTextureBlock(gfx++, sFireworkBubbleTextures[Math_Rand1() % 3], G_IM_FMT_RGBA,
                                            G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    }

                    firework = &sFireworks[j];
                    if (firework->left != FIREWORK_OFFSCREEN) {
                        left = (s32) ((firework->left * 4.0f) - (4.0f * scale));
                        top = (s32) ((firework->top * 4.0f) - (4.0f * scale));
                        right = (s32) (((firework->left + 7.0f) * 4.0f) + (4.0f * scale));
                        bottom = (s32) (((firework->top + 7.0f) * 4.0f) + (4.0f * scale));
                        gSPTextureRectangle(gfx++, left, top, right, bottom, 0, 0, 0, (s32) (1024.0f / scale),
                                            (s32) (1024.0f / scale));
                    }
                }
            }
        }
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);

    return gfx;
}
