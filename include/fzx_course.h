#ifndef FZX_COURSE_H
#define FZX_COURSE_H

#include "fzx_math.h"

typedef struct ControlPoint {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ s16 radiusLeft;
    /* 0x0E */ s16 radiusRight;
    /* 0x10 */ s32 trackSegmentInfo;
} ControlPoint; // size = 0x14

typedef struct CourseData {
    /* 0x000 */ s8 creatorId;
    /* 0x001 */ s8 controlPointCount;
    /* 0x002 */ s8 venue;
    /* 0x003 */ s8 skybox;
    /* 0x004 */ u32 checksum;
    /* 0x008 */ s8 flag;
    /* 0x009 */ char fileName[23];
    /* 0x020 */ ControlPoint controlPoint[64];
    /* 0x520 */ s16 bankAngle[64];
    /* 0x5A0 */ s8 pit[64];
    /* 0x5E0 */ s8 dash[64];
    /* 0x620 */ s8 dirt[64];
    /* 0x660 */ s8 ice[64];
    /* 0x6A0 */ s8 jump[64];
    /* 0x6E0 */ s8 landmine[64];
    /* 0x720 */ s8 gate[64];
    /* 0x760 */ s8 building[64];
    /* 0x7A0 */ s8 sign[64];
} CourseData; // size = 0x7E0

typedef enum Courses {
    /*  0 */ COURSE_MUTE_CITY,
    /*  1 */ COURSE_SILENCE,
    /*  2 */ COURSE_SAND_OCEAN,
    /*  3 */ COURSE_DEVILS_FOREST,
    /*  4 */ COURSE_BIG_BLUE,
    /*  5 */ COURSE_PORT_TOWN,
    /*  6 */ COURSE_SECTOR_ALPHA,
    /*  7 */ COURSE_RED_CANYON,
    /*  8 */ COURSE_DEVILS_FOREST_2,
    /*  9 */ COURSE_MUTE_CITY_2,
    /* 10 */ COURSE_BIG_BLUE_2,
    /* 11 */ COURSE_WHITE_LAND,
    /* 12 */ COURSE_FIRE_FIELD,
    /* 13 */ COURSE_SILENCE_2,
    /* 14 */ COURSE_SECTOR_BETA,
    /* 15 */ COURSE_RED_CANYON_2,
    /* 16 */ COURSE_WHITE_LAND_2,
    /* 17 */ COURSE_MUTE_CITY_3,
    /* 18 */ COURSE_RAINBOW_ROAD,
    /* 19 */ COURSE_DEVILS_FOREST_3,
    /* 20 */ COURSE_SPACE_PLANT,
    /* 21 */ COURSE_SAND_OCEAN_2,
    /* 22 */ COURSE_PORT_TOWN_2,
    /* 23 */ COURSE_BIG_HAND,
    /* 24 */ COURSE_EDIT_1,
    /* 25 */ COURSE_EDIT_2,
    /* 26 */ COURSE_EDIT_3,
    /* 27 */ COURSE_EDIT_4,
    /* 28 */ COURSE_EDIT_5,
    /* 29 */ COURSE_EDIT_6,
    /* 48 */ COURSE_X_1 = 48,
    /* 49 */ COURSE_X_2,
    /* 50 */ COURSE_X_3,
    /* 51 */ COURSE_X_4,
    /* 52 */ COURSE_X_5,
    /* 53 */ COURSE_X_6,
    /* 54 */ COURSE_DEATH_RACE,
    /* 55 */ COURSE_ENDING,
} Courses;

#define CREATOR_NINTENDO 4

typedef enum Venue {
    /*  0 */ VENUE_MUTE_CITY,
    /*  1 */ VENUE_PORT_TOWN,
    /*  2 */ VENUE_BIG_BLUE,
    /*  3 */ VENUE_SAND_OCEAN,
    /*  4 */ VENUE_DEVILS_FOREST,
    /*  5 */ VENUE_WHITE_LAND,
    /*  6 */ VENUE_SECTOR,
    /*  7 */ VENUE_RED_CANYON,
    /*  8 */ VENUE_FIRE_FIELD,
    /*  9 */ VENUE_SILENCE,
    /* 10 */ VENUE_ENDING,
} Venue;

typedef enum Skybox {
    /* 0 */ SKYBOX_PURPLE,
    /* 1 */ SKYBOX_TURQUOISE,
    /* 2 */ SKYBOX_DESERT,
    /* 3 */ SKYBOX_BLUE,
    /* 4 */ SKYBOX_NIGHT,
    /* 5 */ SKYBOX_ORANGE,
    /* 6 */ SKYBOX_SUNSET,
    /* 7 */ SKYBOX_SKY_BLUE,
} Skybox;

typedef enum CourseFeatures {
    /*  0 */ COURSE_FEATURE_GATE_SQUARE,
    /*  1 */ COURSE_FEATURE_GATE_START,
    /*  2 */ COURSE_FEATURE_GATE_HEXAGONAL,
    /*  3 */ COURSE_FEATURE_SIGN_TV_RIGHT,
    /*  4 */ COURSE_FEATURE_SIGN_TV_LEFT,
    /*  5 */ COURSE_FEATURE_SIGN_2_RIGHT,
    /*  6 */ COURSE_FEATURE_SIGN_2_LEFT,
    /*  7 */ COURSE_FEATURE_SIGN_1_RIGHT,
    /*  8 */ COURSE_FEATURE_SIGN_1_LEFT,
    /*  9 */ COURSE_FEATURE_SIGN_NINTEX_RIGHT,
    /* 10 */ COURSE_FEATURE_SIGN_NINTEX_LEFT,
    /* 11 */ COURSE_FEATURE_SIGN_OVERHEAD,
    /* 12 */ COURSE_FEATURE_BUILDING_TALL_LEFT,
    /* 13 */ COURSE_FEATURE_BUILDING_TALL_RIGHT,
    /* 14 */ COURSE_FEATURE_BUILDING_SHORT_LEFT,
    /* 15 */ COURSE_FEATURE_BUILDING_SHORT_RIGHT,
    /* 16 */ COURSE_FEATURE_BUILDING_SPIRE_LEFT,
    /* 17 */ COURSE_FEATURE_BUILDING_SPIRE_RIGHT,
    /* 18 */ COURSE_FEATURE_BUILDING_MOUNTAIN_LEFT,
    /* 19 */ COURSE_FEATURE_BUILDING_MOUNTAIN_RIGHT,
    /* 20 */ COURSE_FEATURE_BUILDING_TALL_GOLD_LEFT,
    /* 21 */ COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT,
    /* 22 */ COURSE_FEATURE_LANDMINE,
    /* 23 */ COURSE_FEATURE_JUMP,
} CourseFeatures;

#define COURSE_FEATURE_IS_BUILDING(feature) (((feature) >= COURSE_FEATURE_BUILDING_TALL_LEFT) && ((feature) <= COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT))

typedef enum PitZone {
    /* -1 */ PIT_NONE = -1,
    /*  0 */ PIT_BOTH,
    /*  1 */ PIT_LEFT,
    /*  2 */ PIT_RIGHT,
} PitZone;

typedef enum DashZone {
    /* -1 */ DASH_NONE = -1,
    /*  0 */ DASH_MIDDLE,
    /*  1 */ DASH_LEFT,
    /*  2 */ DASH_RIGHT,
} DashZone;

typedef enum Dirt {
    /* -1 */ DIRT_NONE = -1,
    /*  0 */ DIRT_BOTH,
    /*  1 */ DIRT_LEFT,
    /*  2 */ DIRT_RIGHT,
    /*  3 */ DIRT_MIDDLE,
} Dirt;

typedef enum Ice {
    /* -1 */ ICE_NONE = -1,
    /*  0 */ ICE_BOTH,
    /*  1 */ ICE_LEFT,
    /*  2 */ ICE_RIGHT,
    /*  3 */ ICE_MIDDLE,
} Ice;

typedef enum Jump {
    /* -1 */ JUMP_NONE = -1,
    /*  0 */ JUMP_ALL,
    /*  1 */ JUMP_LEFT,
    /*  2 */ JUMP_RIGHT,
} Jump;

typedef enum Landmine {
    /* -1 */ LANDMINE_NONE = -1,
    /*  0 */ LANDMINE_MIDDLE,
    /*  1 */ LANDMINE_LEFT,
    /*  2 */ LANDMINE_RIGHT,
} Landmine;

typedef enum Gate {
    /* -1 */ GATE_NONE = -1,
    /*  0 */ GATE_SQUARE,
    /*  1 */ GATE_START,
    /*  2 */ GATE_HEXAGONAL,
} Gate;

typedef enum Building {
    /* -1 */ BUILDING_NONE = -1,
    /*  0 */ BUILDING_TALL_BOTH,
    /*  1 */ BUILDING_TALL_LEFT,
    /*  2 */ BUILDING_TALL_RIGHT,
    /*  3 */ BUILDING_SHORT_BOTH,
    /*  4 */ BUILDING_SHORT_LEFT,
    /*  5 */ BUILDING_SHORT_RIGHT,
    /*  6 */ BUILDING_SPIRE_BOTH,
    /*  7 */ BUILDING_SPIRE_LEFT,
    /*  8 */ BUILDING_SPIRE_RIGHT,
    /*  9 */ BUILDING_MOUNTAIN_BOTH,
    /* 10 */ BUILDING_MOUNTAIN_LEFT,
    /* 11 */ BUILDING_MOUNTAIN_RIGHT,
    /* 12 */ BUILDING_TALL_GOLD_BOTH,
    /* 13 */ BUILDING_TALL_GOLD_LEFT,
    /* 14 */ BUILDING_TALL_GOLD_RIGHT,
} Building;

typedef enum Sign {
    /* -1 */ SIGN_NONE = -1,
    /*  0 */ SIGN_TV,
    /*  1 */ SIGN_1,
    /*  2 */ SIGN_2,
    /*  3 */ SIGN_NINTEX,
    /*  4 */ SIGN_OVERHEAD,
} Sign;

typedef enum Road {
    /* 0 */ ROAD_START_LINE,
    /* 1 */ ROAD_1,
    /* 2 */ ROAD_2,
    /* 3 */ ROAD_3,
    /* 4 */ ROAD_4,
    /* 5 */ ROAD_5,
    /* 6 */ ROAD_6,
    /* 7 */ ROAD_MAX,
} Road;

typedef enum WalledRoad {
    /* 0 */ WALLED_ROAD_0,
    /* 1 */ WALLED_ROAD_1,
    /* 2 */ WALLED_ROAD_2,
    /* 3 */ WALLED_ROAD_MAX,
} WalledRoad;

typedef enum Pipe {
    /* 0 */ PIPE_0,
    /* 1 */ PIPE_1,
    /* 2 */ PIPE_2,
    /* 3 */ PIPE_3,
    /* 4 */ PIPE_MAX,
} Pipe;

typedef enum Cylinder {
    /* 0 */ CYLINDER_0,
    /* 1 */ CYLINDER_1,
    /* 2 */ CYLINDER_2,
    /* 3 */ CYLINDER_3,
    /* 4 */ CYLINDER_MAX,
} Cylinder;

typedef enum HalfPipe {
    /* 0 */ HALF_PIPE_0,
    /* 1 */ HALF_PIPE_1,
    /* 2 */ HALF_PIPE_2,
    /* 3 */ HALF_PIPE_3,
    /* 4 */ HALF_PIPE_MAX,
} HalfPipe;

typedef enum Tunnel {
    /* 0 */ TUNNEL_0,
    /* 1 */ TUNNEL_1,
    /* 2 */ TUNNEL_2,
    /* 3 */ TUNNEL_3,
    /* 4 */ TUNNEL_MAX,
} Tunnel;

typedef enum BorderlessRoad {
    /* 0 */ BORDERLESS_ROAD_0,
    /* 1 */ BORDERLESS_ROAD_1,
    /* 2 */ BORDERLESS_ROAD_2,
    /* 3 */ BORDERLESS_ROAD_MAX,
} BorderlessRoad;

#define TRACK_TYPE_NONE 0x3F
#define TRACK_TYPE_MASK 0x3F

#define TRACK_SHAPE_ROAD 0x0
#define TRACK_SHAPE_WALLED_ROAD 0x40
#define TRACK_SHAPE_PIPE 0x80
#define TRACK_SHAPE_CYLINDER 0xC0
#define TRACK_SHAPE_HALF_PIPE 0x100
#define TRACK_SHAPE_TUNNEL 0x140
#define TRACK_SHAPE_AIR 0x180
#define TRACK_SHAPE_BORDERLESS_ROAD 0x1C0

#define TRACK_SHAPE_MASK 0x1C0

#define TRACK_SHAPE_INDEX(shape) ((shape) >> 6)

#define TRACK_JOIN_PREVIOUS 0x200
#define TRACK_JOIN_NEXT 0x400
#define TRACK_JOIN_BOTH 0x600
#define TRACK_JOIN_MASK 0x600

#define TRACK_UNK1_0 0x0
#define TRACK_UNK1_800 0x800
#define TRACK_UNK1_1000 0x1000
#define TRACK_UNK1_1800 0x1800
#define TRACK_UNK1_MASK 0x1800

#define TRACK_UNK2_0 0x0
#define TRACK_UNK2_2000 0x2000
#define TRACK_UNK2_4000 0x4000
#define TRACK_UNK2_6000 0x6000
#define TRACK_UNK2_MASK 0x6000

#define TRACK_FORM_STRAIGHT 0x00008000
#define TRACK_FORM_LEFT 0x00010000
#define TRACK_FORM_RIGHT 0x00018000
#define TRACK_FORM_S 0x00020000
#define TRACK_FORM_S_FLIPPED 0x00028000

#define TRACK_FORM_MASK 0x00038000

#define TRACK_FLAG_8000000 0x8000000
#define TRACK_FLAG_JOINABLE 0x10000000
#define TRACK_FLAG_20000000 0x20000000
#define TRACK_FLAG_CONTINUOUS 0x40000000
#define TRACK_FLAG_80000000 0x80000000

#endif // FZX_COURSE_H
