#ifndef FZX_GAME_H
#define FZX_GAME_H

typedef enum GameMode {
    /*  0x0 */ GAMEMODE_0,
    /*  0x1 */ GAMEMODE_GP_RACE,
    /*  0x2 */ GAMEMODE_PRACTICE,
    /*  0x3 */ GAMEMODE_VS_2P,
    /*  0x4 */ GAMEMODE_VS_3P,
    /*  0x5 */ GAMEMODE_VS_4P,
    /*  0x6 */ GAMEMODE_6,
    /*  0x7 */ GAMEMODE_7,
    /*  0x8 */ GAMEMODE_8,
    /*  0x9 */ GAMEMODE_9,
    /*  0xA */ GAMEMODE_A,
    /*  0xB */ GAMEMODE_B,
    /*  0xC */ GAMEMODE_C,
    /*  0xD */ GAMEMODE_D,
    /*  0xE */ GAMEMODE_TIME_ATTACK,
    /*  0xF */ GAMEMODE_F,
    /* 0x10 */ GAMEMODE_10,
    /* 0x11 */ GAMEMODE_11,
    /* 0x12 */ GAMEMODE_12,
    /* 0x13 */ GAMEMODE_13,
    /* 0x14 */ GAMEMODE_14,
    /* 0x15 */ GAMEMODE_DEATH_RACE,
} GameMode;

#define GET_MODE(gamemode) (gamemode & 0x1F)

#define GAMEMODE_F3D_MASK 0xC000

#define MODE_F3DLX 0x4000
#define MODE_F3DFLX 0x8000

#define GAMEMODE_F3DLX(mode) (mode | MODE_F3DLX)
#define GAMEMODE_F3DFLX(mode) (mode | MODE_F3DFLX)

#define GAMEMODE_8000 GAMEMODE_F3DFLX(GAMEMODE_0)
#define GAMEMODE_8007 GAMEMODE_F3DFLX(GAMEMODE_7)
#define GAMEMODE_8008 GAMEMODE_F3DFLX(GAMEMODE_8)
#define GAMEMODE_4009 GAMEMODE_F3DLX(GAMEMODE_9)
#define GAMEMODE_800A GAMEMODE_F3DFLX(GAMEMODE_A)
#define GAMEMODE_800B GAMEMODE_F3DFLX(GAMEMODE_B)
#define GAMEMODE_800C GAMEMODE_F3DFLX(GAMEMODE_C)
#define GAMEMODE_800F GAMEMODE_F3DFLX(GAMEMODE_F)
#define GAMEMODE_4012 GAMEMODE_F3DLX(GAMEMODE_12)
#define GAMEMODE_8013 GAMEMODE_F3DFLX(GAMEMODE_13)
#define GAMEMODE_8014 GAMEMODE_F3DFLX(GAMEMODE_14)

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
    /* 30 */ MAX_CHARACTER
} Character;

typedef enum Cup {
    JACK_CUP,
    QUEEN_CUP,
    KING_CUP,
    JOKER_CUP,
    X_CUP,
    EDIT_CUP,
} Cup;

#endif // FZX_GAME_H

