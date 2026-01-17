#include "global.h"
#include "fzx_effects.h"

MachineEffect gCollisionSparks[32];
s32 gCollisionSparkIndex;
s32 gCollisionSparkCount;
MachineEffect gExplosions1[32];
s32 gExplosions1Index;
s32 gExplosions1Count;
MachineEffect gExplosions2[8];
s32 gExplosions2Index;
s32 gExplosions2Count;
FlyingSparkEffect gFlyingSparks[32];
s32 gFlyingSparksIndex;
s32 gFlyingSparksCount;
MachineEffect gSmokes[32];
s32 gSmokesIndex;
s32 gSmokesCount;
FallExplosionEffect gFallExplosions[32];
s32 gFallExplosionsIndex;
s32 gFallExplosionsCount;
MachineDebrisEffect gMachineDebris[128];
s32 gMachineDebrisIndex;
s32 gMachineDebrisCount;

void Effects_Init(void) {
    s32 i;

    gCollisionSparkIndex = gCollisionSparkCount = 0;

    for (i = 0; i < ARRAY_COUNT(gCollisionSparks); i++) {
        gCollisionSparks[i].timer = 0;
    }

    gExplosions1Index = gExplosions1Count = 0;

    for (i = 0; i < ARRAY_COUNT(gExplosions1); i++) {
        gExplosions1[i].timer = 0;
    }

    gExplosions2Index = gExplosions2Count = 0;

    for (i = 0; i < ARRAY_COUNT(gExplosions2); i++) {
        gExplosions2[i].timer = 0;
    }

    gFlyingSparksIndex = gFlyingSparksCount = 0;

    for (i = 0; i < ARRAY_COUNT(gFlyingSparks); i++) {
        gFlyingSparks[i].timer = 0;
    }

    gSmokesIndex = gSmokesCount = 0;

    for (i = 0; i < ARRAY_COUNT(gSmokes); i++) {
        gSmokes[i].timer = 0;
    }

    gFallExplosionsIndex = gFallExplosionsCount = 0;

    for (i = 0; i < ARRAY_COUNT(gFallExplosions); i++) {
        gFallExplosions[i].timer = 0;
    }

    gMachineDebrisIndex = gMachineDebrisCount = 0;

    for (i = 0; i < ARRAY_COUNT(gMachineDebris); i++) {
        gMachineDebris[i].timer = 0;
    }
}

extern s8 gGamePaused;

void Effects_Update(void) {
    u32 index;
    s32 count;
    f32 vibrationOffset;
    f32 normalizingFactor;
    Vec3f randVec;
    MachineEffect* machineEffect;
    FlyingSparkEffect* flyingSpark;
    FallExplosionEffect* fallExplosion;
    MachineDebrisEffect* machineDebris;

    if (gGamePaused) {
        return;
    }

    for (count = gCollisionSparkCount, index = (gCollisionSparkIndex - 1), index %= ARRAY_COUNT(gCollisionSparks);
         count != 0; index = (index - 1) % ARRAY_COUNT(gCollisionSparks), count--) {
        machineEffect = &gCollisionSparks[index];
        machineEffect->timer = (machineEffect->timer + 1) % 16U;
        if (machineEffect->timer != 0) {
            machineEffect->scale *= 1.05f;
            machineEffect->pos.x += machineEffect->velocity.x;
            machineEffect->pos.y += machineEffect->velocity.y;
            machineEffect->pos.z += machineEffect->velocity.z;
        } else {
            gCollisionSparkCount--;
        }
    }

    for (count = gExplosions1Count, index = (gExplosions1Index - 1), index %= ARRAY_COUNT(gExplosions1); count != 0;
         index = (index - 1) % ARRAY_COUNT(gExplosions1), count--) {
        machineEffect = &gExplosions1[index];
        machineEffect->timer = (machineEffect->timer + 1) % 16U;
        if (machineEffect->timer != 0) {
            machineEffect->scale *= 1.02f;
            machineEffect->pos.x += machineEffect->velocity.x;
            machineEffect->pos.y += machineEffect->velocity.y;
            machineEffect->pos.z += machineEffect->velocity.z;
        } else {
            gExplosions1Count--;
        }
    }

    for (count = gExplosions2Count, index = (gExplosions2Index - 1), index %= ARRAY_COUNT(gExplosions2); count != 0;
         index = (index - 1) % ARRAY_COUNT(gExplosions2), count--) {
        machineEffect = &gExplosions2[index];
        machineEffect->timer = (machineEffect->timer + 1) % 32U;
        if (machineEffect->timer != 0) {
            machineEffect->scale *= 1.02f;
            machineEffect->pos.x += machineEffect->velocity.x;
            machineEffect->pos.y += machineEffect->velocity.y;
            machineEffect->pos.z += machineEffect->velocity.z;
        } else {
            gExplosions2Count--;
        }
    }

    for (count = gFlyingSparksCount, index = (gFlyingSparksIndex - 1), index %= ARRAY_COUNT(gFlyingSparks); count != 0;
         index = (index - 1) % ARRAY_COUNT(gFlyingSparks), count--) {
        flyingSpark = &gFlyingSparks[index];
        flyingSpark->timer = (flyingSpark->timer + 1) % 64U;

        if (flyingSpark->timer != 0) {
            Racer* racer = flyingSpark->racer;
            flyingSpark->pos.x += flyingSpark->velocity.x -= 0.4f * racer->gravityUp.x;
            flyingSpark->pos.y += flyingSpark->velocity.y -= 0.4f * racer->gravityUp.y;
            flyingSpark->pos.z += flyingSpark->velocity.z -= 0.4f * racer->gravityUp.z;

            normalizingFactor =
                1.0f / sqrtf(SQ(flyingSpark->velocity.x) + SQ(flyingSpark->velocity.y) + SQ(flyingSpark->velocity.z));
            flyingSpark->basis.x.x = flyingSpark->velocity.x * normalizingFactor;
            flyingSpark->basis.x.y = flyingSpark->velocity.y * normalizingFactor;
            flyingSpark->basis.x.z = flyingSpark->velocity.z * normalizingFactor;

            flyingSpark->basis.y.x += flyingSpark->basis.z.x;
            flyingSpark->basis.y.y += flyingSpark->basis.z.y;
            flyingSpark->basis.y.z += flyingSpark->basis.z.z;

            flyingSpark->basis.z.x =
                (flyingSpark->basis.y.y * flyingSpark->basis.x.z) - (flyingSpark->basis.y.z * flyingSpark->basis.x.y);
            flyingSpark->basis.z.y =
                (flyingSpark->basis.y.z * flyingSpark->basis.x.x) - (flyingSpark->basis.y.x * flyingSpark->basis.x.z);
            flyingSpark->basis.z.z =
                (flyingSpark->basis.y.x * flyingSpark->basis.x.y) - (flyingSpark->basis.y.y * flyingSpark->basis.x.x);

            normalizingFactor =
                1.0f / sqrtf(SQ(flyingSpark->basis.z.x) + SQ(flyingSpark->basis.z.y) + SQ(flyingSpark->basis.z.z));
            flyingSpark->basis.z.x *= normalizingFactor;
            flyingSpark->basis.z.y *= normalizingFactor;
            flyingSpark->basis.z.z *= normalizingFactor;

            flyingSpark->basis.y.x =
                (flyingSpark->basis.x.y * flyingSpark->basis.z.z) - (flyingSpark->basis.x.z * flyingSpark->basis.z.y);
            flyingSpark->basis.y.y =
                (flyingSpark->basis.x.z * flyingSpark->basis.z.x) - (flyingSpark->basis.x.x * flyingSpark->basis.z.z);
            flyingSpark->basis.y.z =
                (flyingSpark->basis.x.x * flyingSpark->basis.z.y) - (flyingSpark->basis.x.y * flyingSpark->basis.z.x);
        } else {
            gFlyingSparksCount--;
        }
    }

    for (count = gSmokesCount, index = (gSmokesIndex - 1), index %= ARRAY_COUNT(gSmokes); count != 0;
         index = (index - 1) % ARRAY_COUNT(gSmokes), count--) {
        machineEffect = &gSmokes[index];
        machineEffect->timer = (machineEffect->timer + 1) % 32U;
        if (machineEffect->timer != 0) {
            machineEffect->scale *= 1.02f;
            machineEffect->pos.x += machineEffect->velocity.x;
            machineEffect->pos.y += machineEffect->velocity.y;
            machineEffect->pos.z += machineEffect->velocity.z;
        } else {
            gSmokesCount--;
        }
    }

    for (count = gFallExplosionsCount, index = (gFallExplosionsIndex - 1), index %= ARRAY_COUNT(gFallExplosions);
         count != 0; index = (index - 1) % ARRAY_COUNT(gFallExplosions), count--) {
        fallExplosion = &gFallExplosions[index];
        fallExplosion->timer++;
        if (fallExplosion->timer > 65) {
            fallExplosion->timer = 0;
            gFallExplosionsCount--;
        }
        if (fallExplosion->timer >= 53 && fallExplosion->timer < 63) {
            Racer* racer = fallExplosion->racer;
            randVec.x = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 1.8f) - 0.9f;
            randVec.y = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 0.4f) + 0.4f;
            randVec.z = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 1.8f) - 0.9f;
            Effects_SpawnSmoke(((s32) (Math_Rand1() % 16) - 8) + racer->segmentPositionInfo.pos.x,
                               ((s32) (Math_Rand1() % 16) - 8) + racer->segmentPositionInfo.pos.y,
                               ((s32) (Math_Rand1() % 16) - 8) + racer->segmentPositionInfo.pos.z,
                               racer->velocity.x + (randVec.x * racer->trueBasis.z.x) +
                                   (randVec.y * racer->trueBasis.y.x) + (randVec.z * racer->trueBasis.x.x),
                               racer->velocity.y + (randVec.x * racer->trueBasis.z.y) +
                                   (randVec.y * racer->trueBasis.y.y) + (randVec.z * racer->trueBasis.x.y),
                               racer->velocity.z + (randVec.x * racer->trueBasis.z.z) +
                                   (randVec.y * racer->trueBasis.y.z) + (randVec.z * racer->trueBasis.x.z),
                               30.0f, fallExplosion->racer);
        }
    }

    for (count = gMachineDebrisCount, index = (gMachineDebrisIndex - 1), index %= ARRAY_COUNT(gMachineDebris);
         count != 0; index = (index - 1) % ARRAY_COUNT(gMachineDebris), count--) {
        machineDebris = &gMachineDebris[index];
        machineDebris->timer = (machineDebris->timer + 1) % 64U;
        if (machineDebris->timer != 0) {
            machineDebris->cornerVibration1 += 0xCC;

            vibrationOffset = SIN(machineDebris->cornerVibration1) * 1.5f;
            machineDebris->cornerPos1.x += machineDebris->velocity.x + (vibrationOffset * machineDebris->up.x);
            machineDebris->cornerPos1.y += machineDebris->velocity.y + (vibrationOffset * machineDebris->up.y);
            machineDebris->cornerPos1.z += machineDebris->velocity.z + (vibrationOffset * machineDebris->up.z);

            machineDebris->cornerVibration2 += 0xCC;
            vibrationOffset = SIN(machineDebris->cornerVibration2) * 1.5f;
            machineDebris->cornerPos2.x += machineDebris->velocity.x + (vibrationOffset * machineDebris->up.x);
            machineDebris->cornerPos2.y += machineDebris->velocity.y + (vibrationOffset * machineDebris->up.y);
            machineDebris->cornerPos2.z += machineDebris->velocity.z + (vibrationOffset * machineDebris->up.z);

            machineDebris->cornerVibration3 += 0xCC;
            vibrationOffset = SIN(machineDebris->cornerVibration3) * 1.5f;
            machineDebris->cornerPos3.x += machineDebris->velocity.x + (vibrationOffset * machineDebris->up.x);
            machineDebris->cornerPos3.y += machineDebris->velocity.y + (vibrationOffset * machineDebris->up.y);
            machineDebris->cornerPos3.z += machineDebris->velocity.z + (vibrationOffset * machineDebris->up.z);

            machineDebris->velocity.x =
                (machineDebris->velocity.x * 0.98f) - (0.2f * machineDebris->racer->gravityUp.x);
            machineDebris->velocity.y =
                (machineDebris->velocity.y * 0.98f) - (0.2f * machineDebris->racer->gravityUp.y);
            machineDebris->velocity.z =
                (machineDebris->velocity.z * 0.98f) - (0.2f * machineDebris->racer->gravityUp.z);
            machineDebris->alpha = 255 - (s32) (SIN(machineDebris->cornerVibration1 & 0x7FF) * 255.0f);
        } else {
            gMachineDebrisCount--;
        }
    }
}

s32 Effects_SpawnCollisionSparks(f32 xPos, f32 yPos, f32 zPos, f32 xVelocity, f32 yVelocity, f32 zVelocity, f32 scale,
                                 Racer* racer) {
    MachineEffect* collisionSpark;

    if (gCollisionSparkCount < 32) {
        if (racer->bodyWhiteTimer != 0) {
            return -1;
        }
        racer->bodyWhiteTimer = 5;
        collisionSpark = &gCollisionSparks[gCollisionSparkIndex];
        collisionSpark->pos.x = xPos + xVelocity;
        collisionSpark->pos.y = yPos + yVelocity;
        collisionSpark->pos.z = zPos + zVelocity;
        collisionSpark->velocity.x = xVelocity;
        collisionSpark->velocity.y = yVelocity;
        collisionSpark->velocity.z = zVelocity;
        collisionSpark->scale = scale;
        collisionSpark->racer = racer;
        gCollisionSparkIndex = (gCollisionSparkIndex + 1) % 32U;
        gCollisionSparkCount++;
        return 0;
    }
    return -1;
}

s32 Effects_SpawnExplosion1(f32 xPos, f32 yPos, f32 zPos, f32 xVelocity, f32 yVelocity, f32 zVelocity, f32 scale,
                            Racer* racer) {
    MachineEffect* explosion;

    if (gExplosions1Count < 32) {
        explosion = &gExplosions1[gExplosions1Index];
        explosion->pos.x = xPos + xVelocity;
        explosion->pos.y = yPos + yVelocity;
        explosion->pos.z = zPos + zVelocity;
        explosion->velocity.x = xVelocity;
        explosion->velocity.y = yVelocity;
        explosion->velocity.z = zVelocity;
        explosion->scale = scale;
        explosion->racer = racer;
        gExplosions1Index = (gExplosions1Index + 1) % 32U;
        gExplosions1Count++;
        return 0;
    }
    return -1;
}

s32 Effects_SpawnExplosion2(f32 xPos, f32 yPos, f32 zPos, f32 xVelocity, f32 yVelocity, f32 zVelocity, f32 scale,
                            Racer* racer) {
    MachineEffect* explosion;

    if (gExplosions2Count < 8) {
        explosion = &gExplosions2[gExplosions2Index];
        explosion->pos.x = xPos + xVelocity;
        explosion->pos.y = yPos + yVelocity;
        explosion->pos.z = zPos + zVelocity;
        explosion->velocity.x = xVelocity;
        explosion->velocity.y = yVelocity;
        explosion->velocity.z = zVelocity;
        explosion->scale = scale;
        explosion->racer = racer;
        gExplosions2Index = (gExplosions2Index + 1) % 8U;
        gExplosions2Count++;
        return 0;
    }
    return -1;
}

s32 Effects_SpawnFlyingSparks(f32 xPos, f32 yPos, f32 zPos, f32 xVelocity, f32 yVelocity, f32 zVelocity, Racer* racer) {
    FlyingSparkEffect* flyingSpark;
    f32 normalizingFactor;

    if (gFlyingSparksCount < 32) {
        flyingSpark = &gFlyingSparks[gFlyingSparksIndex];
        normalizingFactor = SQ(xVelocity) + SQ(yVelocity) + SQ(zVelocity);
        if (normalizingFactor < 0.01f) {
            return -1;
        }

        normalizingFactor = 1.0f / sqrtf(normalizingFactor);

        flyingSpark->basis.x.x = normalizingFactor * xVelocity;
        flyingSpark->basis.x.y = normalizingFactor * yVelocity;
        flyingSpark->basis.x.z = normalizingFactor * zVelocity;

        normalizingFactor = SQ(flyingSpark->basis.x.z) + SQ(flyingSpark->basis.x.x);

        if (normalizingFactor < 0.01f) {
            return -1;
        }

        normalizingFactor = 1.0f / sqrtf(normalizingFactor);

        flyingSpark->basis.z.x = flyingSpark->basis.x.z * normalizingFactor;
        flyingSpark->basis.z.y = 0.0f;
        flyingSpark->basis.z.z = -flyingSpark->basis.x.x * normalizingFactor;

        flyingSpark->basis.y.x = flyingSpark->basis.x.y * flyingSpark->basis.z.z;
        flyingSpark->basis.y.y =
            (flyingSpark->basis.x.z * flyingSpark->basis.z.x) - (flyingSpark->basis.x.x * flyingSpark->basis.z.z);
        flyingSpark->basis.y.z = -flyingSpark->basis.x.y * flyingSpark->basis.z.x;

        flyingSpark->pos.x = xPos + xVelocity;
        flyingSpark->pos.y = yPos + yVelocity;
        flyingSpark->pos.z = zPos + zVelocity;
        flyingSpark->velocity.x = xVelocity;
        flyingSpark->velocity.y = yVelocity;
        flyingSpark->velocity.z = zVelocity;
        flyingSpark->racer = racer;
        gFlyingSparksIndex = (gFlyingSparksIndex + 1) % 32U;
        gFlyingSparksCount++;
        return 0;
    }

    return -1;
}

s32 Effects_SpawnSmoke(f32 xPos, f32 yPos, f32 zPos, f32 xVelocity, f32 yVelocity, f32 zVelocity, f32 scale,
                       Racer* racer) {
    MachineEffect* smoke;

    if (gSmokesCount < 32) {
        smoke = &gSmokes[gSmokesIndex];
        smoke->pos.x = xPos + xVelocity;
        smoke->pos.y = yPos + yVelocity;
        smoke->pos.z = zPos + zVelocity;
        smoke->velocity.x = xVelocity;
        smoke->velocity.y = yVelocity;
        smoke->velocity.z = zVelocity;
        smoke->scale = scale;
        smoke->racer = racer;
        gSmokesIndex = (gSmokesIndex + 1) % 32U;
        gSmokesCount++;
        return 0;
    }

    return -1;
}

s32 Effects_SpawnFallExplosion(f32 scale, Racer* racer) {
    FallExplosionEffect* fallExplosion;

    if (gFallExplosionsCount < 32) {
        fallExplosion = &gFallExplosions[gFallExplosionsIndex];
        fallExplosion->scale = scale;
        fallExplosion->racer = racer;
        gFallExplosionsIndex = (gFallExplosionsIndex + 1) % 32U;
        gFallExplosionsCount++;
        return 0;
    }
    return -1;
}

s32 Effects_SpawnMachineDebris(f32 xPos, f32 yPos, f32 zPos, f32 xVelocity, f32 yVelocity, f32 zVelocity,
                               Mtx3F* racerBasis, s32 red, s32 green, s32 blue, Racer* racer) {
    MachineDebrisEffect* machineDebris;
    f32 randomSideOffset;
    f32 randomForwardOffset;

    if (gMachineDebrisCount < 128) {
        machineDebris = &gMachineDebris[gMachineDebrisIndex];
        randomSideOffset = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        randomForwardOffset = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        machineDebris->cornerPos1.x =
            xPos + (randomSideOffset * racerBasis->z.x) + (randomForwardOffset * racerBasis->x.x);
        machineDebris->cornerPos1.y =
            yPos + (randomSideOffset * racerBasis->z.y) + (randomForwardOffset * racerBasis->x.y);
        machineDebris->cornerPos1.z =
            zPos + (randomSideOffset * racerBasis->z.z) + (randomForwardOffset * racerBasis->x.z);

        randomSideOffset = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        randomForwardOffset = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        machineDebris->cornerPos2.x =
            xPos + (randomSideOffset * racerBasis->z.x) + (randomForwardOffset * racerBasis->x.x);
        machineDebris->cornerPos2.y =
            yPos + (randomSideOffset * racerBasis->z.y) + (randomForwardOffset * racerBasis->x.y);
        machineDebris->cornerPos2.z =
            zPos + (randomSideOffset * racerBasis->z.z) + (randomForwardOffset * racerBasis->x.z);

        randomSideOffset = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        randomForwardOffset = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        machineDebris->cornerPos3.x =
            xPos + (randomSideOffset * racerBasis->z.x) + (randomForwardOffset * racerBasis->x.x);
        machineDebris->cornerPos3.y =
            yPos + (randomSideOffset * racerBasis->z.y) + (randomForwardOffset * racerBasis->x.y);
        machineDebris->cornerPos3.z =
            zPos + (randomSideOffset * racerBasis->z.z) + (randomForwardOffset * racerBasis->x.z);
        machineDebris->cornerVibration1 = Math_Rand1() % 4096;
        machineDebris->cornerVibration2 = Math_Rand1() % 4096;
        machineDebris->cornerVibration3 = Math_Rand1() % 4096;
        machineDebris->velocity.x = xVelocity;
        machineDebris->velocity.y = yVelocity;
        machineDebris->velocity.z = zVelocity;
        machineDebris->up.x = racerBasis->y.x;
        machineDebris->up.y = racerBasis->y.y;
        machineDebris->up.z = racerBasis->y.z;
        machineDebris->red = red;
        machineDebris->green = green;
        machineDebris->blue = blue;
        machineDebris->alpha = 0;
        machineDebris->racer = racer;
        gMachineDebrisIndex = (gMachineDebrisIndex + 1) % 128U;
        gMachineDebrisCount++;
        return 0;
    }
    return -1;
}
