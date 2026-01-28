#ifndef FZX_EFFECTS_H
#define FZX_EFFECTS_H

#include "fzx_math.h"
#include "unk_structs.h"

typedef struct MachineEffect {
    Vec3f pos;
    Vec3f velocity;
    f32 scale;
    s32 timer;
    Racer* racer;
} MachineEffect; // size = 0x24

typedef struct FallExplosionEffect {
    f32 scale;
    s32 timer;
    Racer* racer;
} FallExplosionEffect; // size = 0xC

typedef struct FlyingSparkEffect {
    Vec3f pos;
    Vec3f velocity;
    Mtx3F basis;
    s32 timer;
    Racer* racer;
} FlyingSparkEffect; // size = 0x44

typedef struct MachineDebrisEffect {
    Vec3f cornerPos1;
    Vec3f cornerPos2;
    Vec3f cornerPos3;
    s32 cornerVibration1;
    s32 cornerVibration2;
    s32 cornerVibration3;
    Vec3f velocity;
    Vec3f up;
    s16 red;
    s16 green;
    s16 blue;
    s16 alpha;
    s32 timer;
    Racer* racer;
} MachineDebrisEffect; // size = 0x58

extern MachineEffect gCollisionSparks[32];
extern s32 gCollisionSparkIndex;
extern s32 gCollisionSparkCount;
extern MachineEffect gExplosions1[32];
extern s32 gExplosions1Index;
extern s32 gExplosions1Count;
extern MachineEffect gExplosions2[8];
extern s32 gExplosions2Index;
extern s32 gExplosions2Count;
extern FlyingSparkEffect gFlyingSparks[32];
extern s32 gFlyingSparksIndex;
extern s32 gFlyingSparksCount;
extern MachineEffect gSmokes[32];
extern s32 gSmokesIndex;
extern s32 gSmokesCount;
extern FallExplosionEffect gFallExplosions[32];
extern s32 gFallExplosionsIndex;
extern s32 gFallExplosionsCount;
extern MachineDebrisEffect gMachineDebris[128];
extern s32 gMachineDebrisIndex;
extern s32 gMachineDebrisCount;

#endif // FZX_EFFECTS_H
