#ifndef FZX_THREAD_H
#define FZX_THREAD_H

#include "unk_structs.h"

#define TOTAL_RACER_COUNT 30

extern Racer gRacers[TOTAL_RACER_COUNT];

typedef enum PositionSuffix {
    POSITION_SUFFIX_ST,
    POSITION_SUFFIX_ND,
    POSITION_SUFFIX_RD,
    POSITION_SUFFIX_TH,
} PositionSuffix;

#endif // FZX_THREAD_H
