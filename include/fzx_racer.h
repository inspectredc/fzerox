#ifndef FZX_RACER_H
#define FZX_RACER_H

#include "unk_structs.h"

#define TOTAL_RACER_COUNT 30

typedef struct RacerPairInfo {
    Racer* leadRacer;
    Racer* trailRacer;
    f32 trailToLeadDistance;
    f32 leadToTrailDistance;
    bool areColliding;
} RacerPairInfo; // size = 0x14

typedef enum CourseEffects {
    COURSE_EFFECT_NONE,
    COURSE_EFFECT_PIT,
    COURSE_EFFECT_DIRT,
    COURSE_EFFECT_DASH,
    COURSE_EFFECT_ICE,
} CourseEffects;

#define COURSE_EFFECT_MASK 0xF

#define RACER_STATE_COLLISION_RECOIL (1 << 13)
#define RACER_STATE_SPINNING_OUT (1 << 14)
#define RACER_STATE_FLAGS_8000 (1 << 15)
#define RACER_STATE_TOUCHING_LANDMINE (1 << 16)
#define RACER_STATE_RECEIVED_DAMAGE (1 << 17)
#define RACER_STATE_RETIRED (1 << 18)
#define RACER_STATE_FALLING_OFF_TRACK (1 << 19)
#define RACER_STATE_CAN_BOOST (1 << 20)
#define RACER_STATE_JUMP_BOOST (1 << 21)
#define RACER_STATE_FLAGS_400000 (1 << 22)
#define RACER_STATE_CPU_CONTROLLED (1 << 23)
#define RACER_STATE_DASH_PAD_BOOST (1 << 24)
#define RACER_STATE_FINISHED (1 << 25)
#define RACER_STATE_AIRBORNE (1 << 26)
#define RACER_STATE_CRASHED (1 << 27)
#define RACER_STATE_FLAGS_10000000 (1 << 28)
#define RACER_STATE_FLAGS_20000000 (1 << 29)
#define RACER_STATE_ACTIVE (1 << 30)
#define RACER_STATE_FLAGS_80000000 (1 << 31)

#define RACER_SE_FLAGS_ICE (1 << 5)
#define RACER_SE_FLAGS_DRIFT_SLIDE (1 << 6)
#define RACER_SE_FLAGS_BRAKE (1 << 7)
#define RACER_SE_FLAGS_ENGINE_ECHO (1 << 8)
#define RACER_SE_FLAGS_200 (1 << 9)
#define RACER_SE_FLAGS_DIRT (1 << 10)
#define RACER_SE_FLAGS_PIT (1 << 11)
#define RACER_SE_FLAGS_BOOST (1 << 12)
#define RACER_SE_FLAGS_AIRBORNE (1 << 13)
#define RACER_SE_FLAGS_4000 (1 << 14)
#define RACER_SE_FLAGS_8000 (1 << 15)

typedef enum BodyStat {
    /* 0 */ BODY_A,
    /* 1 */ BODY_B,
    /* 2 */ BODY_C,
    /* 3 */ BODY_D,
    /* 4 */ BODY_E,
} BodyStat;

typedef enum BoostStat {
    /* 0 */ BOOST_A,
    /* 1 */ BOOST_B,
    /* 2 */ BOOST_C,
    /* 3 */ BOOST_D,
    /* 4 */ BOOST_E,
} BoostStat;

typedef enum GripStat {
    /* 0 */ GRIP_A,
    /* 1 */ GRIP_B,
    /* 2 */ GRIP_C,
    /* 3 */ GRIP_D,
    /* 4 */ GRIP_E,
} GripStat;

typedef enum MachineStatIndex {
    /* 0 */ BODY_STAT,
    /* 1 */ BOOST_STAT,
    /* 2 */ GRIP_STAT,
} MachineStatIndex;

typedef enum AttackState {
    /* 0 */ ATTACK_STATE_NONE,
    /* 1 */ ATTACK_STATE_SIDE,
    /* 2 */ ATTACK_STATE_SPIN,
} AttackState;

typedef enum DriftAttackDirection {
    /* 0 */ DRIFT_ATTACK_LEFT,
    /* 1 */ DRIFT_ATTACK_RIGHT,
} DriftAttackDirection;

extern Racer gRacers[TOTAL_RACER_COUNT];

#endif // FZX_RACER_H
