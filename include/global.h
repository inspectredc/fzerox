#ifndef GLOBAL_H
#define GLOBAL_H

#include "PR/ultratypes.h"
#include "PR/mbi.h"
#include "functions.h"
#include "variables.h"
#include "macros.h"
#include "sys.h"
#include "controller.h"
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

typedef enum Character {
    /* 00 */ CAPTAIN_FALCON,
    /* 01 */ DR_STEWART,
    /* 02 */ PICO,
    /* 03 */ SAMURAI_GOROH,
    /* 04 */ JODY_SUMMER,
    /* 05 */ MIGHTY_GAZELLE,
    /* 06 */ MR_EAD,
    /* 07 */ BABA,
    /* 08 */ OCTOMAN,
    /* 09 */ GOMAR_AND_SHIOH,
    /* 10 */ KATE_ALEN,
    /* 11 */ ROGER_BUSTER,
    /* 12 */ JAMES_MCCLOUD,
    /* 13 */ LEON,
    /* 14 */ ANTONIO_GUSTER,
    /* 15 */ BLACK_SHADOW,
    /* 16 */ MICHAEL_CHAIN,
    /* 17 */ JACK_LEVIN,
    /* 18 */ SUPER_ARROW,
    /* 19 */ MRS_ARROW,
    /* 20 */ JOHN_TANAKA,
    /* 21 */ BEASTMAN,
    /* 22 */ ZODA,
    /* 23 */ DR_CLASH,
    /* 24 */ SILVER_NEELSEN,
    /* 25 */ BIO_REX,
    /* 26 */ DRAQ,
    /* 27 */ BILLY,
    /* 28 */ THE_SKULL,
    /* 29 */ BLOOD_FALCON,
} Character;

#endif // GLOBAL_H
