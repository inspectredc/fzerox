#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "fzx_math.h"
#include "fzx_camera.h"
#include "unk_structs.h"

typedef struct CourseVenueFloor {
    void* texture;
    f32 xScale;
    f32 zScale;
    f32 xScrollSpeed;
    f32 zScrollSpeed;
} CourseVenueFloor; // size = 0x14

typedef struct CourseSkyboxes {
    void* texture;
    u8 courseFogR;
    u8 courseFogG;
    u8 courseFogB;
    u8 racerFogR;
    u8 racerFogG;
    u8 racerFogB;
    u8 backgroundSpriteR;
    u8 backgroundSpriteG;
    u8 backgroundSpriteB;
    u16 flags;
} CourseSkyboxes; // size = 0x10

typedef struct BackgroundContext {
    CourseVenueFloor* venueFloor;
    CourseSkyboxes* skybox;
} BackgroundContext; // size = 0x8

typedef struct ScrollingBackground {
    f32 relativeEyeHeight;
    f32 relativeBackgroundHeight;
    f32 xScale;
    f32 zScale;
    f32 xScroll;
    f32 zScroll;
    f32 xScrollSpeed;
    f32 zScrollSpeed;
} ScrollingBackground; // size = 0x20

typedef struct Background {
    Vec3f pos;
    f32 horizontalRange;
    f32 scrollDepth;
    f32 verticalRange;
    f32 skyboxDepth;
    ScrollingBackground floorScroll;
    ScrollingBackground cloudScroll;
    f32 aspectRatio;
} Background; // size = 0x60

typedef struct BackgroundSpriteInitData {
    s16 spriteId;
    f32 angle;
} BackgroundSpriteInitData; // size = 0x8

typedef struct BackgroundSprite {
    s16 spriteId;
    s16 isVisible;
    s16 replacementIndex;
    Vec3f pos;
    TexturePtr texture;
    u16* palette;
} BackgroundSprite; // size = 0x1C

typedef struct BackgroundSpritePaletteReplacement {
    s16 spriteId;
    s16 whiteIndex;
    u16 palette[16];
} BackgroundSpritePaletteReplacement; // size = 0x24

typedef struct StarPosition {
    f32 left;
    f32 top;
} StarPosition;

typedef struct Star {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    s8 isVisible[4];
    Vec3f pos;
    StarPosition screenPosition[4];
} Star; // size = 0x34

#define SKYBOX_STARRY (1 << 0)
#define SKYBOX_CLOUDY (1 << 1)
#define SKYBOX_NIGHTTIME (1 << 2)

typedef enum BackgroundSpriteId {
    /*  0 */ BG_SPRITE_END,
    /*  1 */ BG_SPRITE_CITY_SKYLINE_1,
    /*  2 */ BG_SPRITE_CITY_SKYLINE_2,
    /*  3 */ BG_SPRITE_CITY_SKYLINE_3,
    /*  4 */ BG_SPRITE_CITY_SKYLINE_4,
    /*  5 */ BG_SPRITE_MOUNTAINS_1,
    /*  6 */ BG_SPRITE_SKULL_MOUNTAIN,
    /*  7 */ BG_SPRITE_GIANT_TREE,
    /*  8 */ BG_SPRITE_MOUNTAIN_CITY,
    /*  9 */ BG_SPRITE_CITY_SKYLINE_5,
    /* 10 */ BG_SPRITE_CITY_SKYLINE_6,
    /* 11 */ BG_SPRITE_CITY_SKYLINE_7,
    /* 12 */ BG_SPRITE_CITY_SKYLINE_8,
    /* 13 */ BG_SPRITE_NIGHT_CITY_SKYLINE_5,
    /* 14 */ BG_SPRITE_NIGHT_CITY_SKYLINE_6,
    /* 15 */ BG_SPRITE_NIGHT_CITY_SKYLINE_7,
    /* 16 */ BG_SPRITE_NIGHT_CITY_SKYLINE_8,
    /* 17 */ BG_SPRITE_MOUNTAINS_2,
    /* 18 */ BG_SPRITE_MOUNTAINS_3,
    /* 19 */ BG_SPRITE_MOUNTAINS_TOWERS_1,
    /* 20 */ BG_SPRITE_MOUNTAINS_TOWERS_2,
    /* 21 */ BG_SPRITE_TOWERS_1,
    /* 22 */ BG_SPRITE_PYRAMID,
    /* 23 */ BG_SPRITE_TOWERS_2,
    /* 24 */ BG_SPRITE_MOON_1,
    /* 25 */ BG_SPRITE_STATUE_1,
    /* 26 */ BG_SPRITE_MOUNTAINS_TOWERS_3,
    /* 27 */ BG_SPRITE_CASTLE,
    /* 28 */ BG_SPRITE_MOUNTAINS_TOWERS_4,
    /* 29 */ BG_SPRITE_ROCKET_LAUNCH_1,
    /* 30 */ BG_SPRITE_ROCKET_LAUNCH_2,
    /* 31 */ BG_SPRITE_ROCKET_LAUNCH_3,
    /* 32 */ BG_SPRITE_RADAR_DISH,
    /* 33 */ BG_SPRITE_RAISED_CITY_1,
    /* 34 */ BG_SPRITE_RAISED_GLASS_DOME,
    /* 35 */ BG_SPRITE_RAISED_CITY_2,
    /* 36 */ BG_SPRITE_CONNECTED_MOUNTAINS,
    /* 37 */ BG_SPRITE_MOON_2,
    /* 38 */ BG_SPRITE_FLYING_CITY,
    /* 39 */ BG_SPRITE_NIGHT_CITY_SKYLINE_1,
    /* 40 */ BG_SPRITE_NIGHT_CITY_SKYLINE_2,
    /* 41 */ BG_SPRITE_NIGHT_CITY_SKYLINE_3,
    /* 42 */ BG_SPRITE_NIGHT_CITY_SKYLINE_4,
    /* 43 */ BG_SPRITE_NINTENDO_BUILDING,
    /* 44 */ BG_SPRITE_JACK_CUP_BUILDING,
    /* 45 */ BG_SPRITE_NINTENDO_N_BUILDING,
    /* 46 */ BG_SPRITE_FZERO_X_BUILDING,
    /* 47 */ BG_SPRITE_DOUBLE_SPHEROID_BUILDING,
    /* 48 */ BG_SPRITE_QUEEN_CUP_BUILDING,
    /* 49 */ BG_SPRITE_KING_CUP_BUILDING,
    /* 50 */ BG_SPRITE_JOKER_CUP_BUILDING,
    /* 51 */ BG_SPRITE_X_CUP_BUILDING,
    /* 52 */ BG_SPRITE_EDIT_CUP_BUILDING,
    /* 53 */ BG_SPRITE_MAN_STATUE_2,
    /* 54 */ BG_SPRITE_MOON_3,
    /* 55 */ BG_SPRITE_SINGLE_SPHEROID_BUILDING,
} BackgroundSpriteId;

void Background_InitBackgroundInfo(Camera* camera, Background* background, CourseVenueFloor* venueFloor, f32 cloudXScrollSpeed, f32 cloudZScrollSpeed);
void Background_UpdateSkyboxVtx(Vtx* vtx, Background* background, Camera* camera, f32 depthFovRatio);
void Background_UpdateVenueFloorVtx(Vtx* vtx, Background* background, Camera* camera, f32 xOffset1, f32 zOffset1, f32 xOffset2, f32 zOffset2, f32 xRange, f32 zRange, s32 brightness1, s32 brightness2);
void Background_UpdateCloudVtx(Vtx* vtx, Background* background, Camera* camera, ScrollingBackground* cloudScroll, f32 xOffset1, f32 zOffset1, f32 xOffset2, f32 zOffset2, f32 xRange, f32 zRange, s32 alpha1, s32 alpha2, bool usingHeightRelativeToEye);
void Background_InitBackgroundSprites(void);
void Background_UpdateBackgroundSprites(void);
u16 Background_GetWhitePaletteFlashingReplacementColor(void);
Gfx* Background_DrawBackgroundSprites(Gfx* gfx);
void Background_InitStars(void);
void Background_UpdateStars(s32 cameraIndex, Background* background, Camera* camera);
Gfx* Background_DrawStars(Gfx* gfx, s32 cameraIndex);

#endif // BACKGROUND_H
