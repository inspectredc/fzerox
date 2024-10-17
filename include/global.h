#ifndef GLOBAL_H
#define GLOBAL_H

#include "PR/ultratypes.h"
#include "PR/mbi.h"
#include "functions.h"
#include "variables.h"
#include "macros.h"
#include "sys.h"
#include "fzxmath.h"
#include "unk_structs.h"
#include "leo/leo_internal.h"

// TODO: Move to own header

typedef enum Difficulty {
    /* 0 */ NOVICE,
    /* 1 */ STANDARD,
    /* 2 */ EXPERT,
    /* 3 */ MASTER,
} Difficulty;

#endif // GLOBAL_H
