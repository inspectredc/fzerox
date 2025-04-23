#ifndef FZX_MACHINE_H
#define FZX_MACHINE_H

#include "unk_structs.h"

typedef struct CustomMachineInfo {
    /* 0x0 */ u8 frontType;
    /* 0x1 */ u8 rearType;
    /* 0x2 */ u8 wingType;
    /* 0x3 */ u8 logo;
    /* 0x4 */ u8 decal;
    /* 0x5 */ u8 numberR;
    /* 0x6 */ u8 numberG;
    /* 0x7 */ u8 numberB;
    /* 0x8 */ u8 decalR;
    /* 0x9 */ u8 decalG;
    /* 0xA */ u8 decalB;
    /* 0xB */ u8 cockpitR;
    /* 0xC */ u8 cockpitG;
    /* 0xD */ u8 cockpitB;
} CustomMachineInfo; // size = 0xE

typedef enum CustomMachineType {
    /* 0 */ CUSTOM_MACHINE_DEFAULT,
    /* 1 */ CUSTOM_MACHINE_EDITED,
    /* 2 */ CUSTOM_MACHINE_SUPER_FALCON,
    /* 3 */ CUSTOM_MACHINE_SUPER_STINGRAY,
    /* 4 */ CUSTOM_MACHINE_SUPER_CAT,
} CustomMachineType;

typedef enum MachineLod {
    /* 0 */ MACHINE_LOD_NOT_VISIBLE,
    /* 1 */ MACHINE_LOD_1,
    /* 2 */ MACHINE_LOD_2,
    /* 3 */ MACHINE_LOD_3,
    /* 4 */ MACHINE_LOD_4,
    /* 5 */ MACHINE_LOD_5,
    /* 6 */ MACHINE_LOD_6,
} MachineLod;

typedef enum FrontType {
    /* 0 */ FRONT_0,
    /* 1 */ FRONT_1,
    /* 2 */ FRONT_2,
    /* 3 */ FRONT_3,
    /* 4 */ FRONT_4,
    /* 5 */ FRONT_5,
    /* 6 */ FRONT_6,
} FrontType;

typedef enum RearType {
    /* 0 */ REAR_0,
    /* 1 */ REAR_1,
    /* 2 */ REAR_2,
    /* 3 */ REAR_3,
    /* 4 */ REAR_4,
    /* 5 */ REAR_5,
    /* 6 */ REAR_6,
} RearType;

typedef enum WingType {
    /* 0 */ WING_NONE,
    /* 1 */ WING_1,
    /* 2 */ WING_2,
    /* 3 */ WING_3,
    /* 4 */ WING_4,
    /* 5 */ WING_5,
    /* 6 */ WING_6,
} WingType;

typedef enum Logo {
    /* 0 */ LOGO_SHIELD,
    /* 1 */ LOGO_ARROW_PLANE,
    /* 2 */ LOGO_CIRCLE,
    /* 3 */ LOGO_SKULL,
    /* 4 */ LOGO_YELLOW_GREEN,
    /* 5 */ LOGO_KANJI,
    /* 6 */ LOGO_X,
    /* 7 */ LOGO_N64,
} Logo;

typedef enum Decal {
    /* 0 */ DECAL_STRIPE,
    /* 1 */ DECAL_THIN_STRIPE,
    /* 2 */ DECAL_DOUBLE_STRIPE,
    /* 3 */ DECAL_TRIPLE_STRIPE_UNEVEN,
    /* 4 */ DECAL_BLOCK,
} Decal;

#define MACHINE_NUMBER(x) ((x) - 1)

typedef enum CustomMachineTile {
    MACHINE_TILE_CUSTOM_LOGO = 1,
    MACHINE_TILE_CUSTOM_NUMBER,
    MACHINE_TILE_CUSTOM_DECAL,
    MACHINE_TILE_CUSTOM_AIR_DUCT,
    MACHINE_TILE_CUSTOM_FLOOR_DUCT,
    MACHINE_TILE_CUSTOM_BOOSTER,
} CustomMachineTile;

#define IS_SUPER_MACHINE(customType) ((customType) >= CUSTOM_MACHINE_SUPER_FALCON)

#endif // FZX_MACHINE_H
