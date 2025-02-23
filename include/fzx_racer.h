#ifndef FZX_RACER_H
#define FZX_RACER_H

#include "unk_structs.h"

#define TOTAL_RACER_COUNT 30

extern Racer gRacers[TOTAL_RACER_COUNT];

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
