#ifndef FZX_RACER_H
#define FZX_RACER_H

#include "unk_structs.h"

#define TOTAL_RACER_COUNT 30

extern Racer gRacers[TOTAL_RACER_COUNT];

typedef enum CourseEffects {
    COURSE_EFFECT_NONE,
    COURSE_EFFECT_PIT,
    COURSE_EFFECT_DIRT,
    COURSE_EFFECT_DASH,
    COURSE_EFFECT_ICE,
} CourseEffects;

#define COURSE_EFFECT_MASK 0xF

#define RACER_STATE_FLAGS_2000 (1 << 13)
#define RACER_STATE_SPINNING_OUT (1 << 14)
#define RACER_STATE_FLAGS_8000 (1 << 15)
#define RACER_STATE_FLAGS_10000 (1 << 16)
#define RACER_STATE_FLAGS_20000 (1 << 17)
#define RACER_STATE_RETIRED (1 << 18)
#define RACER_STATE_FLAGS_80000 (1 << 19)
#define RACER_STATE_FLAGS_100000 (1 << 20)
#define RACER_STATE_FLAGS_200000 (1 << 21)
#define RACER_STATE_FLAGS_400000 (1 << 22)
#define RACER_STATE_CPU_CONTROLLED (1 << 23)
#define RACER_STATE_DASH_PAD_BOOST (1 << 24)
#define RACER_STATE_FLAGS_2000000 (1 << 25)
#define RACER_STATE_AIRBORNE (1 << 26)
#define RACER_STATE_CRASHED (1 << 27)
#define RACER_STATE_FLAGS_10000000 (1 << 28)
#define RACER_STATE_FLAGS_20000000 (1 << 29)
#define RACER_STATE_FLAGS_40000000 (1 << 30)
#define RACER_STATE_FLAGS_80000000 (1 << 31)

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
    BODY_STAT,
    BOOST_STAT,
    GRIP_STAT,
} MachineStatIndex;

#endif // FZX_RACER_H
