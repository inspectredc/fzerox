#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_course.h"
#include "fzx_camera.h"
#include "background.h"
#include ASSET_HEADER(common_assets_compressed.h)
#include ASSET_HEADER(machine_custom_gfx.h)

Background sBackgrounds[4];
s32 sBackgroundCount;
s16 sIsEndingCutscene;
s16 sBackgroundSpriteCount;
s16 sSpritePaletteReplacementCount;
s16 sBackgroundSpriteR;
s16 sBackgroundSpriteG;
s16 sBackgroundSpriteB;
BackgroundContext sBackgroundCtx;
u16 sSkyboxFlags;
s32 sCloudCount;
TexturePtr sSkyboxTexture;
TexturePtr sVenueFloorTexture;
TexturePtr sCloudTexture;
TexturePtr sStarTexture;
BackgroundSprite sBackgroundSprites[6];
BackgroundSpritePaletteReplacement sBackgroundSpritePaletteReplacements[6];
Star sStars[100];
s32 sStarCount;

f32 sBackgroundSpriteScale = 50.0f;
f32 sBackgroundSpriteHeight = 400.0f;
f32 sBackgroundScale = 100.0f;

/*
    VENUE FLOOR TEXTURES
 */

// MUTE CITY
CourseVenueFloor sVenueFloorMuteCity = { aVenueMuteCityTex, 0.03f, 0.03f, 0.0f, 0.0f };

// PORT TOWN
CourseVenueFloor sVenueFloorPortTown = { aVenuePortTownTex, 0.03f, 0.03f, 0.0f, 0.0f };

// BIG BLUE / RAINBOW ROAD
CourseVenueFloor sVenueFloorBigBlue = { aVenueBigBlueTex, 0.03f, 0.03f, 0.01f, 0.01f };

// SAND OCEAN
CourseVenueFloor sVenueFloorSandOcean = { aVenueSandOceanTex, 0.03f, 0.03f, 0.0f, 0.0f };

// DEVILS FOREST / BIG HAND
CourseVenueFloor sVenueFloorDevilsForest = { aVenueDevilsForestTex, 0.03f, 0.03f, 0.0f, 0.0f };

// WHITE LAND
CourseVenueFloor sVenueFloorWhiteLand = { aVenueWhiteLandTex, 0.03f, 0.03f, 0.0f, 0.0f };

// SECTORS / SPACE PLANT
CourseVenueFloor sVenueFloorSector = { aVenueSectorTex, 0.03f, 0.03f, 0.0f, 0.0f };

// RED CANYON
CourseVenueFloor sVenueFloorRedCanyon = { aVenueRedCanyonTex, 0.03f, 0.03f, 0.0f, 0.0f };

// FIRE FIELD
CourseVenueFloor sVenueFloorFireField = { aVenueFireFieldTex, 0.03f, 0.03f, 0.005f, 0.005f };

// SILENCE
CourseVenueFloor sVenueFloorSilence = { aVenueSilenceTex, 0.03f, 0.03f, 0.0f, 0.0f };

CourseVenueFloor* sCourseVenueFloors[] = {
    &sVenueFloorMuteCity,     // VENUE_MUTE_CITY
    &sVenueFloorPortTown,     // VENUE_PORT_TOWN
    &sVenueFloorBigBlue,      // VENUE_BIG_BLUE
    &sVenueFloorSandOcean,    // VENUE_SAND_OCEAN
    &sVenueFloorDevilsForest, // VENUE_DEVILS_FOREST
    &sVenueFloorWhiteLand,    // VENUE_WHITE_LAND
    &sVenueFloorSector,       // VENUE_SECTOR
    &sVenueFloorRedCanyon,    // VENUE_RED_CANYON
    &sVenueFloorFireField,    // VENUE_FIRE_FIELD
    &sVenueFloorSilence,      // VENUE_SILENCE
    &sVenueFloorMuteCity,     // VENUE_ENDING
};

/*
    BACKGROUND SKYBOXES
 */

// PURPLE SKIES
// MUTE CITY / WHITE LAND
CourseSkyboxes sSkyboxPurple = { aSkyboxPurpleTex, 252, 192, 253, 0, 0, 0, 200, 130, 240, SKYBOX_CLOUDY };

// TURQUOISE SKIES
// SILENCE 2
CourseSkyboxes sSkyboxTurquoise = { aSkyboxTurquoiseTex, 155, 247, 245, 210, 255, 230, 155, 247, 245, SKYBOX_CLOUDY };

// DESERT YELLOW
// SAND OCEAN
CourseSkyboxes sSkyboxDesert = { aSkyboxDesertTex, 224, 234, 210, 0, 0, 0, 225, 190, 160, SKYBOX_CLOUDY };

// BLUE
CourseSkyboxes sSkyboxBlue = { aSkyboxBlueTex, 151, 194, 218, 210, 255, 230, 151, 194, 218, SKYBOX_CLOUDY };

// NIGHT
// SILENCE / MUTE CITY 2
CourseSkyboxes sSkyboxNight = {
    aSkyboxNightTex, 2, 2, 23, 245, 162, 99, 125, 155, 185, SKYBOX_STARRY | SKYBOX_NIGHTTIME
};

// ORANGE DAY
// DEVILS FOREST / SECTOR ALPHA
CourseSkyboxes sSkyboxOrange = { aSkyboxOrangeTex, 255, 224, 144, 0, 0, 0, 255, 224, 204, SKYBOX_CLOUDY };

// SUNSET
// PORT TOWN / DEVILS FOREST 2 / FIRE FIELD
CourseSkyboxes sSkyboxSunset = { aSkyboxSunsetTex, 245, 162, 99, 0, 0, 0, 245, 162, 99, SKYBOX_CLOUDY };

// SKY BLUE
// BIG BLUE 1 & 2 / RED CANYON
CourseSkyboxes sSkyboxSkyBlue = { aSkyboxSkyBlueTex, 250, 255, 255, 0, 0, 0, 180, 200, 180, SKYBOX_CLOUDY };

CourseSkyboxes* sCourseSkyboxes[] = {
    &sSkyboxPurple,    // SKYBOX_PURPLE
    &sSkyboxTurquoise, // SKYBOX_TURQUOISE
    &sSkyboxDesert,    // SKYBOX_DESERT
    &sSkyboxBlue,      // SKYBOX_BLUE
    &sSkyboxNight,     // SKYBOX_NIGHT
    &sSkyboxOrange,    // SKYBOX_ORANGE
    &sSkyboxSunset,    // SKYBOX_SUNSET
    &sSkyboxSkyBlue,   // SKYBOX_SKY_BLUE
};

/*
    BACKGROUND SPRITES AND PALETTES
 */

TexturePtr sBackgroundSpritePalettePairs[][2] = {
    { NULL, NULL },           // BG_SPRITE_END
    { D_F220810, D_F221010 }, // BG_SPRITE_CITY_SKYLINE_1
    { D_F221210, D_F221A10 }, // BG_SPRITE_CITY_SKYLINE_2
    { D_F221C10, D_F222410 }, // BG_SPRITE_CITY_SKYLINE_3
    { D_F222610, D_F222E10 }, // BG_SPRITE_CITY_SKYLINE_4
    { D_F223010, D_F223810 }, // BG_SPRITE_MOUNTAINS_1
    { D_F223A10, D_F224210 }, // BG_SPRITE_SKULL_MOUNTAIN
    { D_F224410, D_F224C10 }, // BG_SPRITE_GIANT_TREE
    { D_F224E10, D_F225610 }, // BG_SPRITE_MOUNTAIN_CITY
    { D_F225810, D_F226010 }, // BG_SPRITE_CITY_SKYLINE_5
    { D_F226210, D_F226A10 }, // BG_SPRITE_CITY_SKYLINE_6
    { D_F226C10, D_F227410 }, // BG_SPRITE_CITY_SKYLINE_7
    { D_F227610, D_F227E10 }, // BG_SPRITE_CITY_SKYLINE_8
    { D_F228010, D_F228810 }, // BG_SPRITE_NIGHT_CITY_SKYLINE_5
    { D_F228A10, D_F229210 }, // BG_SPRITE_NIGHT_CITY_SKYLINE_6
    { D_F229410, D_F229C10 }, // BG_SPRITE_NIGHT_CITY_SKYLINE_7
    { D_F229E10, D_F22A610 }, // BG_SPRITE_NIGHT_CITY_SKYLINE_8
    { D_F22A810, D_F22B010 }, // BG_SPRITE_MOUNTAINS_2
    { D_F22B210, D_F22BA10 }, // BG_SPRITE_MOUNTAINS_3
    { D_F22BC10, D_F22C410 }, // BG_SPRITE_MOUNTAINS_TOWERS_1
    { D_F22C610, D_F22CE10 }, // BG_SPRITE_MOUNTAINS_TOWERS_2
    { D_F22D010, D_F22D810 }, // BG_SPRITE_TOWERS_1
    { D_F22DA10, D_F22E210 }, // BG_SPRITE_PYRAMID
    { D_F22E410, D_F22EC10 }, // BG_SPRITE_TOWERS_2
    { D_F22EE10, D_F22F610 }, // BG_SPRITE_MOON_1
    { D_F22F810, D_F230010 }, // BG_SPRITE_STATUE_1
    { D_F230210, D_F230A10 }, // BG_SPRITE_MOUNTAINS_TOWERS_3
    { D_F230C10, D_F231410 }, // BG_SPRITE_CASTLE
    { D_F231610, D_F231E10 }, // BG_SPRITE_MOUNTAINS_TOWERS_4
    { D_F232010, D_F232810 }, // BG_SPRITE_ROCKET_LAUNCH_1
    { D_F232A10, D_F233210 }, // BG_SPRITE_ROCKET_LAUNCH_2
    { D_F233410, D_F233C10 }, // BG_SPRITE_ROCKET_LAUNCH_3
    { D_F233E10, D_F234610 }, // BG_SPRITE_RADAR_DISH
    { D_F234810, D_F235010 }, // BG_SPRITE_RAISED_CITY_1
    { D_F235210, D_F235A10 }, // BG_SPRITE_RAISED_GLASS_DOME
    { D_F235C10, D_F236410 }, // BG_SPRITE_RAISED_CITY_2
    { D_F236610, D_F236E10 }, // BG_SPRITE_CONNECTED_MOUNTAINS
    { D_F237010, D_F237810 }, // BG_SPRITE_MOON_2
    { D_F237A10, D_F238210 }, // BG_SPRITE_FLYING_CITY
    { D_F238410, D_F238C10 }, // BG_SPRITE_NIGHT_CITY_SKYLINE_1
    { D_F238E10, D_F239610 }, // BG_SPRITE_NIGHT_CITY_SKYLINE_2
    { D_F239810, D_F23A010 }, // BG_SPRITE_NIGHT_CITY_SKYLINE_3
    { D_F23A210, D_F23AA10 }, // BG_SPRITE_NIGHT_CITY_SKYLINE_4
    { D_F23AC10, D_F23B410 }, // BG_SPRITE_NINTENDO_BUILDING
    { D_F23B610, D_F23BE10 }, // BG_SPRITE_JACK_CUP_BUILDING
    { D_F23C010, D_F23C810 }, // BG_SPRITE_NINTENDO_N_BUILDING
    { D_F23CA10, D_F23D210 }, // BG_SPRITE_FZERO_X_BUILDING
    { D_F23D410, D_F23DC10 }, // BG_SPRITE_DOUBLE_SPHEROID_BUILDING
    { D_F23DE10, D_F23E610 }, // BG_SPRITE_QUEEN_CUP_BUILDING
    { D_F23E810, D_F23F010 }, // BG_SPRITE_KING_CUP_BUILDING
    { D_F23F210, D_F23FA10 }, // BG_SPRITE_JOKER_CUP_BUILDING
    { D_F23FC10, D_F240410 }, // BG_SPRITE_X_CUP_BUILDING
    { D_F240610, D_F240E10 }, // BG_SPRITE_EDIT_CUP_BUILDING
    { D_F241010, D_F241810 }, // BG_SPRITE_MAN_STATUE_2
    { D_F241A10, D_F242210 }, // BG_SPRITE_MOON_3
    { D_F242410, D_F242C10 }, // BG_SPRITE_SINGLE_SPHEROID_BUILDING
};

BackgroundSpriteInitData sBackgroundSpriteInitMuteCity[] = {
    { BG_SPRITE_CITY_SKYLINE_1, 0.0f },
    { BG_SPRITE_CITY_SKYLINE_2, 60.0f },
    { BG_SPRITE_CITY_SKYLINE_3, 120.0f },
    { BG_SPRITE_CITY_SKYLINE_4, 150.0f },
    { BG_SPRITE_CITY_SKYLINE_1, 240.0f },
    { BG_SPRITE_CITY_SKYLINE_2, 300.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitSilence[] = {
    { BG_SPRITE_MOON_3, 0.0f },
    { BG_SPRITE_SINGLE_SPHEROID_BUILDING, 180.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitSandOcean[] = {
    { BG_SPRITE_MOUNTAINS_1, 0.0f },   { BG_SPRITE_MOUNTAINS_2, 60.0f },  { BG_SPRITE_MOUNTAINS_1, 120.0f },
    { BG_SPRITE_MOUNTAINS_2, 180.0f }, { BG_SPRITE_MOUNTAINS_1, 240.0f }, { BG_SPRITE_MOUNTAINS_2, 300.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitDevilsForest[] = {
    { BG_SPRITE_MOUNTAINS_1, 0.0f },   { BG_SPRITE_SKULL_MOUNTAIN, 60.0f },
    { BG_SPRITE_GIANT_TREE, 120.0f },  { BG_SPRITE_MOUNTAIN_CITY, 180.0f },
    { BG_SPRITE_MOUNTAINS_1, 240.0f }, { BG_SPRITE_SKULL_MOUNTAIN, 300.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitBigBlue[] = {
    { BG_SPRITE_RAISED_CITY_1, 0.0f },
    { BG_SPRITE_RAISED_GLASS_DOME, 60.0f },
    { BG_SPRITE_RAISED_CITY_2, 120.0f },
    { BG_SPRITE_CONNECTED_MOUNTAINS, 180.0f },
    { BG_SPRITE_RAISED_CITY_1, 240.0f },
    { BG_SPRITE_RAISED_GLASS_DOME, 300.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitPortTown[] = {
    { BG_SPRITE_CITY_SKYLINE_5, 0.0f },
    { BG_SPRITE_CITY_SKYLINE_6, 120.0f },
    { BG_SPRITE_CITY_SKYLINE_7, 240.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitSectorAlpha[] = {
    { BG_SPRITE_TOWERS_1, 0.0f },
    { BG_SPRITE_PYRAMID, 120.0f },
    { BG_SPRITE_TOWERS_2, 240.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitRedCanyon[] = {
    { BG_SPRITE_MOUNTAINS_2, 0.0f },
    { BG_SPRITE_MOUNTAINS_3, 60.0f },
    { BG_SPRITE_MOUNTAINS_TOWERS_1, 120.0f },
    { BG_SPRITE_MOUNTAINS_TOWERS_2, 180.0f },
    { BG_SPRITE_MOUNTAINS_2, 240.0f },
    { BG_SPRITE_MOUNTAINS_3, 300.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitDevilsForest2[] = {
    { BG_SPRITE_MOUNTAINS_1, 0.0f },   { BG_SPRITE_GIANT_TREE, 60.0f },
    { BG_SPRITE_GIANT_TREE, 120.0f },  { BG_SPRITE_MOUNTAIN_CITY, 180.0f },
    { BG_SPRITE_MOUNTAINS_1, 240.0f }, { BG_SPRITE_SKULL_MOUNTAIN, 300.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitMuteCity2[] = {
    { BG_SPRITE_NIGHT_CITY_SKYLINE_1, 0.0f },
    { BG_SPRITE_NIGHT_CITY_SKYLINE_2, 60.0f },
    { BG_SPRITE_NIGHT_CITY_SKYLINE_3, 120.0f },
    { BG_SPRITE_NIGHT_CITY_SKYLINE_4, 180.0f },
    { BG_SPRITE_NIGHT_CITY_SKYLINE_1, 240.0f },
    { BG_SPRITE_NIGHT_CITY_SKYLINE_2, 300.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitBigBlue2[] = {
    { BG_SPRITE_RAISED_CITY_1, 0.0f },
    { BG_SPRITE_RAISED_GLASS_DOME, 120.0f },
    { BG_SPRITE_RAISED_CITY_2, 240.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitWhiteLand[] = {
    { BG_SPRITE_ROCKET_LAUNCH_1, 0.0f },
    { BG_SPRITE_ROCKET_LAUNCH_2, 120.0f },
    { BG_SPRITE_ROCKET_LAUNCH_3, 240.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitFireField[] = {
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitSilence2[] = {
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitSectorBeta[] = {
    { BG_SPRITE_TOWERS_1, 0.0f },
    { BG_SPRITE_PYRAMID, 120.0f },
    { BG_SPRITE_TOWERS_2, 240.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitRedCanyon2[] = {
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitWhiteLand2[] = {
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitMuteCity3[] = {
    { BG_SPRITE_CITY_SKYLINE_1, 0.0f },
    { BG_SPRITE_CITY_SKYLINE_2, 60.0f },
    { BG_SPRITE_CITY_SKYLINE_3, 120.0f },
    { BG_SPRITE_CITY_SKYLINE_4, 150.0f },
    { BG_SPRITE_CITY_SKYLINE_1, 240.0f },
    { BG_SPRITE_CITY_SKYLINE_2, 300.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitRainbowRoad[] = {
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitDevilsForest3[] = {
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitSpacePlant[] = {
    { BG_SPRITE_TOWERS_1, 0.0f },
    { BG_SPRITE_PYRAMID, 120.0f },
    { BG_SPRITE_TOWERS_2, 240.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitSandOcean2[] = {
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitPortTown2[] = {
    { BG_SPRITE_NIGHT_CITY_SKYLINE_5, 0.0f },
    { BG_SPRITE_NIGHT_CITY_SKYLINE_6, 120.0f },
    { BG_SPRITE_NIGHT_CITY_SKYLINE_7, 240.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitBigHand[] = {
    { BG_SPRITE_STATUE_1, 0.0f },
    { BG_SPRITE_MOUNTAINS_TOWERS_3, 60.0f },
    { BG_SPRITE_CASTLE, 120.0f },
    { BG_SPRITE_MOUNTAINS_TOWERS_4, 180.0f },
    { BG_SPRITE_MOUNTAINS_TOWERS_3, 300.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData sBackgroundSpriteInitEnding[] = {
    { BG_SPRITE_JACK_CUP_BUILDING, 0.0f },
    { BG_SPRITE_NINTENDO_N_BUILDING, 60.0f },
    { BG_SPRITE_FZERO_X_BUILDING, 120.0f },
    { BG_SPRITE_DOUBLE_SPHEROID_BUILDING, 180.0f },
    { BG_SPRITE_JACK_CUP_BUILDING, 240.0f },
    { BG_SPRITE_NINTENDO_N_BUILDING, 300.0f },
    { BG_SPRITE_END, 0.0f },
};

BackgroundSpriteInitData* sBackgroundSpriteCourseInitData[] = {
    sBackgroundSpriteInitMuteCity,      // COURSE_MUTE_CITY
    sBackgroundSpriteInitSilence,       // COURSE_SILENCE
    sBackgroundSpriteInitSandOcean,     // COURSE_SAND_OCEAN
    sBackgroundSpriteInitDevilsForest,  // COURSE_DEVILS_FOREST
    sBackgroundSpriteInitBigBlue,       // COURSE_BIG_BLUE
    sBackgroundSpriteInitPortTown,      // COURSE_PORT_TOWN
    sBackgroundSpriteInitSectorAlpha,   // COURSE_SECTOR_ALPHA
    sBackgroundSpriteInitRedCanyon,     // COURSE_RED_CANYON
    sBackgroundSpriteInitDevilsForest2, // COURSE_DEVILS_FOREST_2
    sBackgroundSpriteInitMuteCity2,     // COURSE_MUTE_CITY_2
    sBackgroundSpriteInitBigBlue2,      // COURSE_BIG_BLUE_2
    sBackgroundSpriteInitWhiteLand,     // COURSE_WHITE_LAND
    sBackgroundSpriteInitFireField,     // COURSE_FIRE_FIELD
    sBackgroundSpriteInitSilence2,      // COURSE_SILENCE_2
    sBackgroundSpriteInitSectorBeta,    // COURSE_SECTOR_BETA
    sBackgroundSpriteInitRedCanyon2,    // COURSE_RED_CANYON_2
    sBackgroundSpriteInitWhiteLand2,    // COURSE_WHITE_LAND_2
    sBackgroundSpriteInitMuteCity3,     // COURSE_MUTE_CITY_3
    sBackgroundSpriteInitRainbowRoad,   // COURSE_RAINBOW_ROAD
    sBackgroundSpriteInitDevilsForest3, // COURSE_DEVILS_FOREST_3
    sBackgroundSpriteInitSpacePlant,    // COURSE_SPACE_PLANT
    sBackgroundSpriteInitSandOcean2,    // COURSE_SAND_OCEAN_2
    sBackgroundSpriteInitPortTown2,     // COURSE_PORT_TOWN_2
    sBackgroundSpriteInitBigHand,       // COURSE_BIG_HAND
};

s16 sDaytimeBackgroundSprites[] = {
    BG_SPRITE_CITY_SKYLINE_1,
    BG_SPRITE_CITY_SKYLINE_2,
    BG_SPRITE_CITY_SKYLINE_3,
    BG_SPRITE_CITY_SKYLINE_4,
    BG_SPRITE_MOUNTAINS_1,
    BG_SPRITE_SKULL_MOUNTAIN,
    BG_SPRITE_GIANT_TREE,
    BG_SPRITE_MOUNTAIN_CITY,
    BG_SPRITE_CITY_SKYLINE_5,
    BG_SPRITE_CITY_SKYLINE_6,
    BG_SPRITE_CITY_SKYLINE_7,
    BG_SPRITE_CITY_SKYLINE_8,
    BG_SPRITE_MOUNTAINS_2,
    BG_SPRITE_MOUNTAINS_3,
    BG_SPRITE_MOUNTAINS_TOWERS_1,
    BG_SPRITE_MOUNTAINS_TOWERS_2,
    BG_SPRITE_TOWERS_1,
    BG_SPRITE_PYRAMID,
    BG_SPRITE_TOWERS_2,
    BG_SPRITE_MOON_1,
    BG_SPRITE_STATUE_1,
    BG_SPRITE_MOUNTAINS_TOWERS_3,
    BG_SPRITE_CASTLE,
    BG_SPRITE_MOUNTAINS_TOWERS_4,
    BG_SPRITE_ROCKET_LAUNCH_1,
    BG_SPRITE_ROCKET_LAUNCH_2,
    BG_SPRITE_ROCKET_LAUNCH_3,
    BG_SPRITE_RADAR_DISH,
    BG_SPRITE_RAISED_CITY_1,
    BG_SPRITE_RAISED_GLASS_DOME,
    BG_SPRITE_RAISED_CITY_2,
    BG_SPRITE_CONNECTED_MOUNTAINS,
    BG_SPRITE_MOON_2,
    BG_SPRITE_FLYING_CITY,
};

s16 sNighttimeBackgroundSprites[] = {
    BG_SPRITE_NIGHT_CITY_SKYLINE_5,
    BG_SPRITE_NIGHT_CITY_SKYLINE_6,
    BG_SPRITE_NIGHT_CITY_SKYLINE_7,
    BG_SPRITE_NIGHT_CITY_SKYLINE_8,
    BG_SPRITE_NIGHT_CITY_SKYLINE_1,
    BG_SPRITE_NIGHT_CITY_SKYLINE_2,
    BG_SPRITE_NIGHT_CITY_SKYLINE_3,
    BG_SPRITE_NIGHT_CITY_SKYLINE_4,
    BG_SPRITE_NINTENDO_N_BUILDING,
    BG_SPRITE_FZERO_X_BUILDING,
    BG_SPRITE_DOUBLE_SPHEROID_BUILDING,
    BG_SPRITE_X_CUP_BUILDING,
    BG_SPRITE_MOON_3,
    BG_SPRITE_SINGLE_SPHEROID_BUILDING,
};

UNUSED s32 D_i3_8006C538[10] = { 0 };

s8 sBackgroundFlashingColors[][3] = {
    { 31, 10, 0 },
    { 0, 15, 31 },
    { 31, 31, 10 },
};

extern s32 gSkyboxType;
extern s32 gVenueType;
extern bool D_800CD510;
extern s32 gNumPlayers;
extern s32 gCourseIndex;
extern s32 gGameMode;
extern Camera gCameras[];

void Background_Init(void) {
    s32 pad;
    s32 i;
    f32 cloudXScrollSpeed;
    f32 cloudZScrollSpeed;
    CourseInfo* courseInfo;
    Background* background;
    Camera* camera;

    sBackgroundCount = gNumPlayers;
    D_800CD510 = false;
    sBackgroundCtx.venueFloor = sCourseVenueFloors[gVenueType];
    sBackgroundCtx.skybox = sCourseSkyboxes[gSkyboxType];
    sSkyboxFlags = sBackgroundCtx.skybox->flags;

    i = Math_Rand1() % 11;
    cloudXScrollSpeed = i * 0.0005f;
    if (Math_Rand1() % 2) {
        cloudXScrollSpeed = 0.0f - cloudXScrollSpeed;
    }
    cloudZScrollSpeed = i * 0.0005f;
    if (Math_Rand1() % 2) {
        cloudZScrollSpeed = 0.0f - cloudZScrollSpeed;
    }

    for (background = sBackgrounds, camera = gCameras, i = 0; i < sBackgroundCount; background++, camera++, i++) {
        Background_InitBackgroundInfo(camera, background, sBackgroundCtx.venueFloor, cloudXScrollSpeed,
                                      cloudZScrollSpeed);
    }

    courseInfo = &gCourseInfos[gCourseIndex];
    courseInfo->courseFogColors[0] = sBackgroundCtx.skybox->courseFogR;
    courseInfo->courseFogColors[1] = sBackgroundCtx.skybox->courseFogG;
    courseInfo->courseFogColors[2] = sBackgroundCtx.skybox->courseFogB;

    if ((sBackgroundCtx.skybox->racerFogR == 0) && (sBackgroundCtx.skybox->racerFogG == 0) &&
        (sBackgroundCtx.skybox->racerFogB == 0)) {
        courseInfo->racerFogColors[0] = sBackgroundCtx.skybox->courseFogR;
        courseInfo->racerFogColors[1] = sBackgroundCtx.skybox->courseFogG;
        courseInfo->racerFogColors[2] = sBackgroundCtx.skybox->courseFogB;
    } else {
        courseInfo->racerFogColors[0] = sBackgroundCtx.skybox->racerFogR;
        courseInfo->racerFogColors[1] = sBackgroundCtx.skybox->racerFogG;
        courseInfo->racerFogColors[2] = sBackgroundCtx.skybox->racerFogB;
    }

    sBackgroundSpriteR = sBackgroundCtx.skybox->backgroundSpriteR;
    sBackgroundSpriteG = sBackgroundCtx.skybox->backgroundSpriteG;
    sBackgroundSpriteB = sBackgroundCtx.skybox->backgroundSpriteB;

    if (sSkyboxFlags & SKYBOX_CLOUDY) {
        if (gNumPlayers >= 3) {
            sCloudCount = 0;
            sSkyboxFlags &= ~SKYBOX_CLOUDY;
        } else {
            sCloudCount = 1;
        }
    } else {
        sCloudCount = 0;
    }
    if (sSkyboxFlags & SKYBOX_STARRY) {
        Background_InitStars();
    }
    Background_InitBackgroundSprites();

    sSkyboxTexture =
        TextureCache_LoadAndCache(sBackgroundCtx.skybox->texture, 64 * 1 * sizeof(u16), false, false, false);
    sVenueFloorTexture =
        TextureCache_LoadAndCache(sBackgroundCtx.venueFloor->texture, 64 * 32 * sizeof(u16), false, false, false);

    if (sSkyboxFlags & SKYBOX_CLOUDY) {
        sCloudTexture = TextureCache_LoadAndCache(aCloudTex, TEX_SIZE(aCloudTex, sizeof(u8)), false, false, false);
    }
    if (sSkyboxFlags & SKYBOX_STARRY) {
        sStarTexture = TextureCache_LoadAndCache(D_F2207C8, TEX_SIZE(D_F2207C8, sizeof(u8)), false, false, false);
    }
    if (gGameMode == GAMEMODE_GP_END_CS) {
        sIsEndingCutscene = true;
    } else {
        sIsEndingCutscene = false;
    }
}

const ScrollingBackground kDefaultCloudInfo = { 400.0f, 1700.0f, 0.006f, 0.006f, 0.0f, 0.0f, 0.0f, 0.0f };

void Background_InitBackgroundInfo(Camera* camera, Background* background, CourseVenueFloor* venueFloor,
                                   f32 cloudXScrollSpeed, f32 cloudZScrollSpeed) {
    background->pos.x = 0.0f;
    background->pos.z = 0.0f;
    background->pos.y = -750.0f;
    if (gNumPlayers == 2) {
        background->scrollDepth = 4300.0f;
        background->skyboxDepth = 5300.0f;
    } else {
        background->scrollDepth = 6000.0f;
        background->skyboxDepth = 7000.0f;
    }
    background->floorScroll.relativeEyeHeight = -750.0f;
    background->floorScroll.relativeBackgroundHeight = -750.0f;
    background->floorScroll.xScale = venueFloor->xScale;
    background->floorScroll.zScale = venueFloor->zScale;
    background->floorScroll.xScroll = 0.0f;
    background->floorScroll.zScroll = 0.0f;
    background->floorScroll.xScrollSpeed = venueFloor->xScrollSpeed;
    background->floorScroll.zScrollSpeed = venueFloor->zScrollSpeed;
    background->cloudScroll = kDefaultCloudInfo;
    background->cloudScroll.xScrollSpeed = cloudXScrollSpeed;
    background->cloudScroll.zScrollSpeed = cloudZScrollSpeed;
    background->aspectRatio = camera->fovScaleY / camera->fovScaleX;
}

extern GfxPool* gGfxPool;

void Background_Update(void) {
    s32 pad[4];
    Camera* camera;
    Background* background;
    Vtx* vtx;
    s32 i;
    f32 xScale;
    f32 zScale;
    f32 depthFovRatio;
    f32 xRange;
    f32 zRange;
    f32 xOffset;
    f32 zOffset;
    f32 cloudHeightAboveEye;
    s32 angle;
    f32 cloudTransparencyStrength;
    bool usingHeightRelativeToEye;

    for (i = 0, background = sBackgrounds, camera = gCameras; i < sBackgroundCount; i++, background++, camera++) {

        background->pos.x = camera->eye.x + (camera->xzNormalizedX * sBackgroundScale);
        background->pos.z = camera->eye.z + (camera->xzNormalizedZ * sBackgroundScale);
        angle = Math_Round(DEG_TO_FZXANG3(0.5f * camera->fov));
        depthFovRatio = TAN(angle);

#ifndef EXPANSION_KIT
        background->horizontalRange = (background->scrollDepth + sBackgroundScale) * depthFovRatio * 1.2f;
#else
        background->horizontalRange = (background->scrollDepth + sBackgroundScale) * depthFovRatio * 1.5f;
#endif
        background->verticalRange = background->horizontalRange * background->aspectRatio;

        xScale = camera->xzNormalizedX;
        zScale = camera->xzNormalizedZ;
        xOffset = background->scrollDepth * xScale;
        zOffset = background->scrollDepth * zScale;
        xRange = background->horizontalRange * zScale;
        zRange = background->horizontalRange * (0.0f - xScale);

        vtx = &gGfxPool->unk_29B48[i * 28 + 2 * 4];
        Background_UpdateSkyboxVtx(vtx, background, camera, depthFovRatio);

        vtx = &gGfxPool->unk_29B48[i * 28 + 0 * 4];
        Background_UpdateVenueFloorVtx(vtx, background, camera, xOffset, zOffset, 0.0f, 0.0f, xRange, zRange, 255, 0);

        vtx = &gGfxPool->unk_29B48[i * 28 + 1 * 4];
        Background_UpdateVenueFloorVtx(vtx, background, camera, 0.0f, 0.0f, 0.0f - xOffset, 0.0f - zOffset, xRange,
                                       zRange, 0, 255);

        if (sCloudCount > 0) {
            cloudHeightAboveEye =
                (background->pos.y + background->cloudScroll.relativeBackgroundHeight) - camera->eye.y;
            if (cloudHeightAboveEye == 0.0f) {
                continue;
            }
            cloudTransparencyStrength = ABS(cloudHeightAboveEye);
            cloudTransparencyStrength /= 100.0f;
            if (cloudTransparencyStrength > 1.0f) {
                cloudTransparencyStrength = 1.0f;
            }
            if (cloudHeightAboveEye > 0.0f) {
                usingHeightRelativeToEye = true;
            } else {
                usingHeightRelativeToEye = false;
            }

            vtx = &gGfxPool->unk_29B48[i * 28 + 3 * 4];
            Background_UpdateCloudVtx(vtx, background, camera, &background->cloudScroll, xOffset, zOffset, 0.0f, 0.0f,
                                      xRange, zRange, 255, ((1.0f - cloudTransparencyStrength) * 255.0f),
                                      usingHeightRelativeToEye);

            vtx = &gGfxPool->unk_29B48[i * 28 + 4 * 4];
            Background_UpdateCloudVtx(vtx, background, camera, &background->cloudScroll, 0.0f, 0.0f, 0.0f - xOffset,
                                      0.0f - zOffset, xRange, zRange, ((1.0f - cloudTransparencyStrength) * 255.0f),
                                      255, usingHeightRelativeToEye);
        }
        if (sSkyboxFlags & SKYBOX_STARRY) {
            Background_UpdateStars(i, background, camera);
        }
    }
    if (sBackgroundSpriteCount != 0) {
        Background_UpdateBackgroundSprites();
    }
}

void Background_UpdateSkyboxVtx(Vtx* vtx, Background* background, Camera* camera, f32 depthFovRatio) {
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    s32 t;
    f32 fovRadius = (background->skyboxDepth * depthFovRatio);
    f32 temp;
    f32 horizontalCenterOffset;
    f32 verticalCenterOffset;
    f32 xPositions[4];
    f32 yPositions[4];
    f32 zPositions[4];
    f32 textureSCoordinates[4];
    f32 textureTCoordinates[4];

    horizontalCenterOffset = (2.0f * (camera->frustrumCenterX * fovRadius)) / camera->fovScaleX;
    fovRadius *= background->aspectRatio;
    verticalCenterOffset = (2.0f * (camera->frustrumCenterY * fovRadius)) / camera->fovScaleY;

    xPositions[0] = camera->eye.x + (camera->basis.x.x * background->skyboxDepth) +
                    (camera->basis.y.x * (background->verticalRange + verticalCenterOffset)) +
                    (camera->basis.z.x * (background->horizontalRange - horizontalCenterOffset));
    yPositions[0] = camera->eye.y + (camera->basis.x.y * background->skyboxDepth) +
                    (camera->basis.y.y * (background->verticalRange + verticalCenterOffset)) +
                    (camera->basis.z.y * (background->horizontalRange - horizontalCenterOffset));
    zPositions[0] = camera->eye.z + (camera->basis.x.z * background->skyboxDepth) +
                    (camera->basis.y.z * (background->verticalRange + verticalCenterOffset)) +
                    (camera->basis.z.z * (background->horizontalRange - horizontalCenterOffset));
    xPositions[1] = (camera->eye.x + (camera->basis.x.x * background->skyboxDepth) +
                     (camera->basis.y.x * (background->verticalRange + verticalCenterOffset))) -
                    (camera->basis.z.x * (background->horizontalRange + horizontalCenterOffset));
    yPositions[1] = (camera->eye.y + (camera->basis.x.y * background->skyboxDepth) +
                     (camera->basis.y.y * (background->verticalRange + verticalCenterOffset))) -
                    (camera->basis.z.y * (background->horizontalRange + horizontalCenterOffset));
    zPositions[1] = (camera->eye.z + (camera->basis.x.z * background->skyboxDepth) +
                     (camera->basis.y.z * (background->verticalRange + verticalCenterOffset))) -
                    (camera->basis.z.z * (background->horizontalRange + horizontalCenterOffset));
    xPositions[2] = ((camera->eye.x + (camera->basis.x.x * background->skyboxDepth)) -
                     (camera->basis.y.x * (background->verticalRange - verticalCenterOffset))) +
                    (camera->basis.z.x * (background->horizontalRange - horizontalCenterOffset));
    yPositions[2] = ((camera->eye.y + (camera->basis.x.y * background->skyboxDepth)) -
                     (camera->basis.y.y * (background->verticalRange - verticalCenterOffset))) +
                    (camera->basis.z.y * (background->horizontalRange - horizontalCenterOffset));
    zPositions[2] = ((camera->eye.z + (camera->basis.x.z * background->skyboxDepth)) -
                     (camera->basis.y.z * (background->verticalRange - verticalCenterOffset))) +
                    (camera->basis.z.z * (background->horizontalRange - horizontalCenterOffset));
    xPositions[3] = ((camera->eye.x + (camera->basis.x.x * background->skyboxDepth)) -
                     (camera->basis.y.x * (background->verticalRange - verticalCenterOffset))) -
                    (camera->basis.z.x * (background->horizontalRange + horizontalCenterOffset));
    yPositions[3] = ((camera->eye.y + (camera->basis.x.y * background->skyboxDepth)) -
                     (camera->basis.y.y * (background->verticalRange - verticalCenterOffset))) -
                    (camera->basis.z.y * (background->horizontalRange + horizontalCenterOffset));
    zPositions[3] = ((camera->eye.z + (camera->basis.x.z * background->skyboxDepth)) -
                     (camera->basis.y.z * (background->verticalRange - verticalCenterOffset))) -
                    (camera->basis.z.z * (background->horizontalRange + horizontalCenterOffset));

    for (i = 0; i < 4; i++) {
        if (xPositions[i] < -32000.0f) {
            xPositions[i] = -32000.0f;
        } else if (xPositions[i] > 32000.0f) {
            xPositions[i] = 32000.0f;
        }

        if (yPositions[i] < -32000.0f) {
            yPositions[i] = -32000.0f;
        } else if (yPositions[i] > 32000.0f) {
            yPositions[i] = 32000.0f;
        }

        if (zPositions[i] < -32000.0f) {
            zPositions[i] = -32000.0f;
        } else if (zPositions[i] > 32000.0f) {
            zPositions[i] = 32000.0f;
        }

        temp = ((xPositions[i] - xPositions[0]) / (background->horizontalRange * 2.0f));

        if (xPositions[i] < -32000.0f) {
            xPositions[i] = -32000.0f;
        } else if (xPositions[i] > 32000.0f) {
            xPositions[i] = 32000.0f;
        }

        if (yPositions[i] < -32000.0f) {
            yPositions[i] = -32000.0f;
        } else if (yPositions[i] > 32000.0f) {
            yPositions[i] = 32000.0f;
        }

        if (zPositions[i] < -32000.0f) {
            zPositions[i] = -32000.0f;
        } else if (zPositions[i] > 32000.0f) {
            zPositions[i] = 32000.0f;
        }

        textureTCoordinates[i] = ((temp * 256.0f) * 2.0f) - 0.5f;
        temp = 1.0f - ((yPositions[i] - background->pos.y) / (background->verticalRange * 2.0f));
        textureSCoordinates[i] = (temp * 64.0f) - 0.5f;
    }

    for (i = 0; i < 4; i++) {
        x = xPositions[i];
        y = yPositions[i];
        z = zPositions[i];
        s = textureSCoordinates[i] * 32.0f;
        t = textureTCoordinates[i] * 32.0f;

        SET_VTX(vtx, x, y, z, s, t, 0, 0, 0, 255);
        vtx++;
    }
}

extern s8 gGamePaused;

void Background_UpdateVenueFloorVtx(Vtx* vtx, Background* background, Camera* camera, f32 xOffset1, f32 zOffset1,
                                    f32 xOffset2, f32 zOffset2, f32 xRange, f32 zRange, s32 brightness1,
                                    s32 brightness2) {
    ScrollingBackground* floorScroll;
    f32 perspectiveRatio;
    f32 baseSReference;
    f32 baseTReference;
    s32 brightness;
    s32 x;
    s32 z;
    s32 s;
    s32 t;
    s32 i;
    f32 xPositions[4];
    f32 y = background->pos.y;
    f32 zPositions[4];
    f32 textureSCoordinates[4];
    f32 textureTCoordinates[4];
    s32 pad;

    floorScroll = &background->floorScroll;
    xPositions[0] = background->pos.x + xOffset1 + xRange;
    zPositions[0] = background->pos.z + zOffset1 + zRange;
    xPositions[1] = background->pos.x + xOffset1 - xRange;
    zPositions[1] = background->pos.z + zOffset1 - zRange;
    xPositions[2] = background->pos.x + xOffset2 + xRange;
    zPositions[2] = background->pos.z + zOffset2 + zRange;
    xPositions[3] = background->pos.x + xOffset2 - xRange;
    zPositions[3] = background->pos.z + zOffset2 - zRange;

    perspectiveRatio = (floorScroll->relativeBackgroundHeight - camera->eye.y) / (y - camera->eye.y);

    if (!gGamePaused) {
        floorScroll->xScroll += floorScroll->xScrollSpeed;
        if (floorScroll->xScroll >= 1024.0f) {
            floorScroll->xScroll -= 1024.0f;
        } else if (floorScroll->xScroll < -1024.0f) {
            floorScroll->xScroll += 1024.0f;
        }
    }
    if (!gGamePaused) {
        floorScroll->zScroll += floorScroll->zScrollSpeed;

        if (floorScroll->zScroll >= 1024.0f) {
            floorScroll->zScroll -= 1024.0f;
        } else if (floorScroll->zScroll < -1024.0f) {
            floorScroll->zScroll += 1024.0f;
        }
    }

    textureSCoordinates[0] =
        ((((xPositions[0] - camera->eye.x) * perspectiveRatio) + camera->eye.x) * floorScroll->xScale) +
        floorScroll->xScroll;
    textureTCoordinates[0] =
        ((((zPositions[0] - camera->eye.z) * perspectiveRatio) + camera->eye.z) * floorScroll->zScale) +
        floorScroll->zScroll;
    textureSCoordinates[1] =
        ((((xPositions[1] - camera->eye.x) * perspectiveRatio) + camera->eye.x) * floorScroll->xScale) +
        floorScroll->xScroll;
    textureTCoordinates[1] =
        ((((zPositions[1] - camera->eye.z) * perspectiveRatio) + camera->eye.z) * floorScroll->zScale) +
        floorScroll->zScroll;
    textureSCoordinates[2] =
        ((((xPositions[2] - camera->eye.x) * perspectiveRatio) + camera->eye.x) * floorScroll->xScale) +
        floorScroll->xScroll;
    textureTCoordinates[2] =
        ((((zPositions[2] - camera->eye.z) * perspectiveRatio) + camera->eye.z) * floorScroll->zScale) +
        floorScroll->zScroll;
    textureSCoordinates[3] =
        ((((xPositions[3] - camera->eye.x) * perspectiveRatio) + camera->eye.x) * floorScroll->xScale) +
        floorScroll->xScroll;
    textureTCoordinates[3] =
        ((((zPositions[3] - camera->eye.z) * perspectiveRatio) + camera->eye.z) * floorScroll->zScale) +
        floorScroll->zScroll;

    baseSReference = textureSCoordinates[0];
    baseTReference = textureTCoordinates[0];

    for (i = 1; i < 4; i++) {
        if (textureSCoordinates[i] < baseSReference) {
            baseSReference = textureSCoordinates[i];
        }

        if (textureTCoordinates[i] < baseTReference) {
            baseTReference = textureTCoordinates[i];
        }
    }

    if (baseSReference > 0.0f) {
        baseSReference = (s32) (baseSReference + 1024.0f) / 1024 * -1024.0f;
    } else {
        baseSReference = (s32) baseSReference / 1024 * -1024.0f;
    }
    if (baseTReference > 0.0f) {
        baseTReference = (s32) (baseTReference + 1024.0f) / 1024 * -1024.0f;
    } else {
        baseTReference = (s32) baseTReference / 1024 * -1024.0f;
    }

    for (i = 0; i < 4; i++) {
        textureSCoordinates[i] += baseSReference;
        textureTCoordinates[i] += baseTReference;
    }

    for (i = 0; i < 4; i++) {
        x = xPositions[i];
        z = zPositions[i];
        s = textureSCoordinates[i] * 32.0f;
        t = textureTCoordinates[i] * 32.0f;

        brightness = (i < 2) ? brightness1 : brightness2;

        SET_VTX(vtx, x, (s32) (y), z, s, t, brightness, brightness, brightness, 255);
        vtx++;
    }
}

void Background_UpdateCloudVtx(Vtx* vtx, Background* background, Camera* camera, ScrollingBackground* cloudScroll,
                               f32 xOffset1, f32 zOffset1, f32 xOffset2, f32 zOffset2, f32 xRange, f32 zRange,
                               s32 alpha1, s32 alpha2, bool usingHeightRelativeToEye) {
    s32 x;
    s32 z;
    s32 s;
    s32 t;
    s32 alpha;
    f32 perspectiveRatio;
    s32 pad;
    f32 baseSReference;
    f32 baseTReference;
    s32 i;
    f32 xPositions[4];
    f32 y;
    f32 zPositions[4];
    f32 textureSCoordinates[4];
    f32 textureTCoordinates[4];

    if (usingHeightRelativeToEye) {
        y = camera->eye.y + cloudScroll->relativeEyeHeight;
    } else {
        y = background->pos.y + cloudScroll->relativeBackgroundHeight;
    }

    xPositions[0] = background->pos.x + xOffset1 + xRange;
    zPositions[0] = background->pos.z + zOffset1 + zRange;
    xPositions[1] = background->pos.x + xOffset1 - xRange;
    zPositions[1] = background->pos.z + zOffset1 - zRange;
    xPositions[2] = background->pos.x + xOffset2 + xRange;
    zPositions[2] = background->pos.z + zOffset2 + zRange;
    xPositions[3] = background->pos.x + xOffset2 - xRange;
    zPositions[3] = background->pos.z + zOffset2 - zRange;

    if (!gGamePaused) {
        cloudScroll->xScroll += cloudScroll->xScrollSpeed;
        if (cloudScroll->xScroll >= 1024.0f) {
            cloudScroll->xScroll -= 1024.0f;
        } else if (cloudScroll->xScroll < -1024.0f) {
            cloudScroll->xScroll += 1024.0f;
        }
    }
    if (!gGamePaused) {
        cloudScroll->zScroll += cloudScroll->zScrollSpeed;
        if (cloudScroll->zScroll >= 1024.0f) {
            cloudScroll->zScroll -= 1024.0f;
        } else if (cloudScroll->zScroll < -1024.0f) {
            cloudScroll->zScroll += 1024.0f;
        }
    }

    if (usingHeightRelativeToEye) {
        perspectiveRatio =
            ((background->pos.y + cloudScroll->relativeBackgroundHeight) - camera->eye.y) / (y - camera->eye.y);
        textureSCoordinates[0] =
            ((((xPositions[0] - camera->eye.x) * perspectiveRatio) + camera->eye.x) * cloudScroll->xScale) +
            cloudScroll->xScroll;
        textureTCoordinates[0] =
            ((((zPositions[0] - camera->eye.z) * perspectiveRatio) + camera->eye.z) * cloudScroll->zScale) +
            cloudScroll->zScroll;
        textureSCoordinates[1] =
            ((((xPositions[1] - camera->eye.x) * perspectiveRatio) + camera->eye.x) * cloudScroll->xScale) +
            cloudScroll->xScroll;
        textureTCoordinates[1] =
            ((((zPositions[1] - camera->eye.z) * perspectiveRatio) + camera->eye.z) * cloudScroll->zScale) +
            cloudScroll->zScroll;
        textureSCoordinates[2] =
            ((((xPositions[2] - camera->eye.x) * perspectiveRatio) + camera->eye.x) * cloudScroll->xScale) +
            cloudScroll->xScroll;
        textureTCoordinates[2] =
            ((((zPositions[2] - camera->eye.z) * perspectiveRatio) + camera->eye.z) * cloudScroll->zScale) +
            cloudScroll->zScroll;
        textureSCoordinates[3] =
            ((((xPositions[3] - camera->eye.x) * perspectiveRatio) + camera->eye.x) * cloudScroll->xScale) +
            cloudScroll->xScroll;
        textureTCoordinates[3] =
            ((((zPositions[3] - camera->eye.z) * perspectiveRatio) + camera->eye.z) * cloudScroll->zScale) +
            cloudScroll->zScroll;
    } else {
        textureSCoordinates[0] = (xPositions[0] * cloudScroll->xScale) + cloudScroll->xScroll;
        textureTCoordinates[0] = (zPositions[0] * cloudScroll->zScale) + cloudScroll->zScroll;
        textureSCoordinates[1] = (xPositions[1] * cloudScroll->xScale) + cloudScroll->xScroll;
        textureTCoordinates[1] = (zPositions[1] * cloudScroll->zScale) + cloudScroll->zScroll;
        textureSCoordinates[2] = (xPositions[2] * cloudScroll->xScale) + cloudScroll->xScroll;
        textureTCoordinates[2] = (zPositions[2] * cloudScroll->zScale) + cloudScroll->zScroll;
        textureSCoordinates[3] = (xPositions[3] * cloudScroll->xScale) + cloudScroll->xScroll;
        textureTCoordinates[3] = (zPositions[3] * cloudScroll->zScale) + cloudScroll->zScroll;
    }
    baseSReference = textureSCoordinates[0];
    baseTReference = textureTCoordinates[0];

    for (i = 1; i < 4; i++) {
        if (textureSCoordinates[i] < baseSReference) {
            baseSReference = textureSCoordinates[i];
        }
        if (textureTCoordinates[i] < baseTReference) {
            baseTReference = textureTCoordinates[i];
        }
    }

    if (baseSReference > 0.0f) {
        baseSReference = (f32) ((s32) (baseSReference + 1024.0f) / 1024) * -1024.0f;
    } else {
        baseSReference = (f32) ((s32) baseSReference / 1024) * -1024.0f;
    }
    if (baseTReference > 0.0f) {
        baseTReference = (f32) ((s32) (baseTReference + 1024.0f) / 1024) * -1024.0f;
    } else {
        baseTReference = (f32) ((s32) baseTReference / 1024) * -1024.0f;
    }

    for (i = 0; i < 4; i++) {
        textureSCoordinates[i] += baseSReference;
        textureTCoordinates[i] += baseTReference;
    }

    for (i = 0; i < 4; i++) {
        x = xPositions[i];
        z = zPositions[i];
        s = textureSCoordinates[i] * 32.0f;
        t = textureTCoordinates[i] * 32.0f;

        if (i < 2) {
            alpha = alpha1;
        } else {
            alpha = alpha2;
        }

        SET_VTX(vtx, x, (s32) (y), z, s, t, 255, 255, 255, alpha);
        vtx++;
    }
}

extern GfxPool D_1000000;
extern Mtx D_2000000[];

Gfx* Background_Draw(Gfx* gfx, s32 cameraIndex, s32 scissorBoxType) {
    CourseSkyboxes* skybox;
    Camera* camera = &gCameras[cameraIndex];

    skybox = sBackgroundCtx.skybox;

    gSPPerspNormalize(gfx++, camera->perspectiveScale);

    gSPMatrix(gfx++, &D_1000000.unk_20208[cameraIndex], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gfx = Camera_Draw(gfx, scissorBoxType, cameraIndex);
    gSPDisplayList(gfx++, D_303A9E0);

    if (sIsEndingCutscene) {
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 204);
    }
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gfx++, &D_1000000.unk_29B48[cameraIndex * 28], 28, 0);

    gDPLoadTextureBlock(gfx++, sSkyboxTexture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSP2Triangles(gfx++, 8, 11, 9, 0, 8, 10, 11, 0);

    if (sSkyboxFlags & SKYBOX_STARRY) {
        gSPDisplayList(gfx++, D_303AA18);
        gfx = Background_DrawStars(gfx, cameraIndex);
    }
    if (cameraIndex == 0 && (sBackgroundSpriteCount != 0)) {
        gfx = Background_DrawBackgroundSprites(gfx);
        gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPVertex(gfx++, &D_1000000.unk_29B48[cameraIndex * 28], 28, 0);
    }

#ifdef EXPANSION_KIT
    if (sBackgrounds[cameraIndex].pos.y < camera->eye.y) {
#endif
        gSPDisplayList(gfx++, D_303AA40);
        gDPSetPrimColor(gfx++, 0, 0, skybox->courseFogR, skybox->courseFogG, skybox->courseFogB, 0);

        gDPLoadTextureBlock(gfx++, sVenueFloorTexture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
        gSP2Triangles(gfx++, 4, 7, 5, 0, 4, 6, 7, 0);
#ifdef EXPANSION_KIT
    }
#endif

    if (gGameMode == GAMEMODE_GP_END_CS) {
        gfx = EndingCutsceneEffects_DrawFireworks(gfx);
        gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
        gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_CLIPPING);
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }

    if (sCloudCount > 0) {
        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, 0, TEXEL0, SHADE, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, TEXEL0,
                          SHADE, TEXEL0);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 0);

        gDPLoadTextureBlock(gfx++, sCloudTexture, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 12, 15, 13, 0, 12, 14, 15, 0);
        gSP2Triangles(gfx++, 16, 19, 17, 0, 16, 18, 19, 0);
    }

    return gfx;
}

extern s16 gPlayer1OverallPosition;
extern s32 gCupType;
extern GfxPool D_8024DCE0[];
extern bool gInCourseEditTestRun;

void Background_InitBackgroundSprites(void) {
    s32 pad[3];
    GfxPool* gfxPool;
    s32 i;
    s32 j;
    BackgroundSpriteInitData* bgSpriteInitData;
    BackgroundSprite* backgroundSprite;
    BackgroundSpritePaletteReplacement* spritePaletteReplacement;
    s32 index;
    f32 rotationIncrement;
    s32 replacementIndex;
    void** texturePalettePair;
    BackgroundSpriteInitData spriteInitDataBuffer[8];

    sBackgroundSpriteCount = 0;
    if (gNumPlayers != 1) {
        return;
    }

#ifdef EXPANSION_KIT
    if (gInCourseEditTestRun) {
        return;
    }
#endif

    if (gCourseIndex < COURSE_EDIT_1) {
        bgSpriteInitData = sBackgroundSpriteCourseInitData[gCourseIndex];
    } else if ((gCourseIndex >= COURSE_X_1) && (gCourseIndex <= COURSE_X_6)) {
        j = Math_Rand1() % 7;
        bgSpriteInitData = spriteInitDataBuffer;
        if (j > 0) {
            rotationIncrement = 360.0f / j;
        }

        for (i = 0; i < j; i++) {
            if (sSkyboxFlags & SKYBOX_NIGHTTIME) {
                bgSpriteInitData->spriteId = sNighttimeBackgroundSprites[Math_Rand1() % 12];
            } else {
                bgSpriteInitData->spriteId = sDaytimeBackgroundSprites[Math_Rand1() % 34];
                if ((Math_Rand1() % 3) == 0) {
                    bgSpriteInitData->spriteId = BG_SPRITE_MAN_STATUE_2;
                }
            }
            bgSpriteInitData->angle = i * rotationIncrement;
            bgSpriteInitData++;
        }
        bgSpriteInitData->spriteId = BG_SPRITE_END;
        bgSpriteInitData->angle = 0.0f;
        bgSpriteInitData = spriteInitDataBuffer;
    } else if (gCourseIndex != COURSE_ENDING) {
        return;
    } else { // COURSE_ENDING
        // FAKE
        if (1) {
            bgSpriteInitData = sBackgroundSpriteInitEnding;
        }
        if (gPlayer1OverallPosition >= 4) {
            return;
        }
    }

    backgroundSprite = sBackgroundSprites;
    while (bgSpriteInitData->spriteId != BG_SPRITE_END) {
        backgroundSprite->spriteId = bgSpriteInitData->spriteId;
        if (backgroundSprite->spriteId == BG_SPRITE_JACK_CUP_BUILDING) {
            switch (gCupType) {
                case QUEEN_CUP:
                    backgroundSprite->spriteId = BG_SPRITE_QUEEN_CUP_BUILDING;
                    break;
                case KING_CUP:
                    backgroundSprite->spriteId = BG_SPRITE_KING_CUP_BUILDING;
                    break;
                case JOKER_CUP:
                    backgroundSprite->spriteId = BG_SPRITE_JOKER_CUP_BUILDING;
                    break;
                case X_CUP:
                    backgroundSprite->spriteId = BG_SPRITE_X_CUP_BUILDING;
                    break;
                case EDIT_CUP:
                    backgroundSprite->spriteId = BG_SPRITE_EDIT_CUP_BUILDING;
                    break;
#ifdef EXPANSION_KIT
                case JACK_CUP:
                    backgroundSprite->spriteId = BG_SPRITE_JACK_CUP_BUILDING;
                    break;
                default:
                    backgroundSprite->spriteId = BG_SPRITE_FZERO_X_BUILDING;
                    break;
#endif
            }
        }
        backgroundSprite->isVisible = false;
        backgroundSprite->replacementIndex = 0;
        i = Math_Round(DEG_TO_FZXANG2(bgSpriteInitData->angle));

        backgroundSprite->pos.x = 0.0f - (SIN(i) * 8000.0f);
        backgroundSprite->pos.y = sBackgroundSpriteHeight;
        backgroundSprite->pos.z = 0.0f - (COS(i) * 8000.0f);

        texturePalettePair = sBackgroundSpritePalettePairs[backgroundSprite->spriteId];

        backgroundSprite->texture = TextureCache_LoadAndCache(texturePalettePair[0], 64 * 64 / 2, false, false, false);
        backgroundSprite->palette =
            TextureCache_LoadAndCache(texturePalettePair[1], 16 * 1 * sizeof(u16), false, false, false);
        sBackgroundSpriteCount++;
        backgroundSprite++;
        bgSpriteInitData++;
    }

    for (i = 0, gfxPool = D_8024DCE0; i < 2; i++, gfxPool++) {
        SET_VTX(&gfxPool->unk_2C4E8[0], -32, 32, 0, 0, 0, 255, 255, 255, 255);
        SET_VTX(&gfxPool->unk_2C4E8[1], 32, 32, 0, 0x800, 0, 255, 255, 255, 255);
        SET_VTX(&gfxPool->unk_2C4E8[2], -32, -32, 0, 0, 0x800, 255, 255, 255, 0);
        SET_VTX(&gfxPool->unk_2C4E8[3], 32, -32, 0, 0x800, 0x800, 255, 255, 255, 0);
    }
    sSpritePaletteReplacementCount = 0;

    if (sSkyboxFlags & SKYBOX_NIGHTTIME) {
        // clang-format off
        for (i = 0, spritePaletteReplacement = sBackgroundSpritePaletteReplacements; i < 6; i++, spritePaletteReplacement++) { \
            spritePaletteReplacement->spriteId = BG_SPRITE_END;
        }
        // clang-format on

        for (i = 0, backgroundSprite = sBackgroundSprites; i < sBackgroundSpriteCount; i++, backgroundSprite++) {
            replacementIndex = -1;
            for (j = 0, spritePaletteReplacement = sBackgroundSpritePaletteReplacements; j < 6;
                 j++, spritePaletteReplacement++) {
                if (spritePaletteReplacement->spriteId == backgroundSprite->spriteId) {
                    backgroundSprite->replacementIndex = j;
                    break;
                }

                if (spritePaletteReplacement->spriteId == BG_SPRITE_END) {
                    replacementIndex = j;
                    backgroundSprite->replacementIndex = j;
                    break;
                }
            }

            if (replacementIndex != -1) {
                spritePaletteReplacement = &sBackgroundSpritePaletteReplacements[replacementIndex];
                spritePaletteReplacement->spriteId = backgroundSprite->spriteId;
                spritePaletteReplacement->whiteIndex = -1;
                for (j = 0; j < 16; j++) {
                    spritePaletteReplacement->palette[j] = backgroundSprite->palette[j];
                    if (spritePaletteReplacement->palette[j] == GPACK_RGBA5551(255, 255, 255, 1)) {
                        spritePaletteReplacement->whiteIndex = j;
                    }
                }
                sSpritePaletteReplacementCount++;
            }
        }
    }
}

void Background_UpdateBackgroundSprites(void) {
    s32 i;
    s32 j;
    s32 flashingPaletteColor;
    Vec3f lookAt;
    Vec3f vec;
    Vec3f up;
    BackgroundSprite* backgroundSprite;
    BackgroundSpritePaletteReplacement* spritePaletteReplacement;
    s32 playerIndex = 0;

    for (i = 0, backgroundSprite = sBackgroundSprites; i < sBackgroundSpriteCount; i++, backgroundSprite++) {

        lookAt.x = 0.0f - gCameras[playerIndex].basis.x.x;
        lookAt.y = 0.0f - gCameras[playerIndex].basis.x.y;
        lookAt.z = 0.0f - gCameras[playerIndex].basis.x.z;

        vec.x = 0.0f - lookAt.z;
        vec.z = lookAt.x;

        up.x = 0.0f - (vec.z * lookAt.y);
        up.y = (vec.z * lookAt.x) - (vec.x * lookAt.z);
        up.z = (vec.x * lookAt.y) - 0.0f;

        vec.x = gCameras[playerIndex].eye.x + backgroundSprite->pos.x;
        vec.y = 400.0f;
        vec.z = gCameras[playerIndex].eye.z + backgroundSprite->pos.z;

        if ((vec.x <= 23000.0f) && (vec.x >= -23000.0f) && (vec.z <= 23000.0f) && (vec.z >= -23000.0f)) {
            backgroundSprite->isVisible = true;
            Matrix_SetLockedLookAtFromVectors(&gGfxPool->unk_2C368[i], NULL, sBackgroundSpriteScale,
                                              sBackgroundSpriteScale, sBackgroundSpriteScale, &lookAt, &up, &vec);
        } else {
            backgroundSprite->isVisible = false;
        }
    }
    if (sSpritePaletteReplacementCount > 0) {
        flashingPaletteColor = Background_GetWhitePaletteFlashingReplacementColor();

        for (i = 0; i < sSpritePaletteReplacementCount; i++) {
            spritePaletteReplacement = &sBackgroundSpritePaletteReplacements[i];
            if (spritePaletteReplacement->whiteIndex != -1) {
                spritePaletteReplacement->palette[spritePaletteReplacement->whiteIndex] = flashingPaletteColor;
            }

            for (j = 0; j < 16; j++) {
                gGfxPool->unk_2C528[i][j] = spritePaletteReplacement->palette[j];
            }
        }
    }
}

extern u32 gGameFrameCount;

u16 Background_GetWhitePaletteFlashingReplacementColor(void) {
    s32 blendTimer;
    s32 startColorIndex;
    s32 endColorIndex;
    s32 red;
    s32 green;
    s32 blue;

    startColorIndex = (gGameFrameCount >> 4) % ARRAY_COUNT(sBackgroundFlashingColors);
    endColorIndex = (startColorIndex + 1) % ARRAY_COUNT(sBackgroundFlashingColors);
    blendTimer = gGameFrameCount % 16;

    red = sBackgroundFlashingColors[startColorIndex][0] +
          ((sBackgroundFlashingColors[endColorIndex][0] - sBackgroundFlashingColors[startColorIndex][0]) * blendTimer) /
              15;
    green =
        sBackgroundFlashingColors[startColorIndex][1] +
        ((sBackgroundFlashingColors[endColorIndex][1] - sBackgroundFlashingColors[startColorIndex][1]) * blendTimer) /
            15;
    blue =
        sBackgroundFlashingColors[startColorIndex][2] +
        ((sBackgroundFlashingColors[endColorIndex][2] - sBackgroundFlashingColors[startColorIndex][2]) * blendTimer) /
            15;

    return PACK_5551(red, green, blue, 1);
}

Gfx* Background_DrawBackgroundSprites(Gfx* gfx) {
    BackgroundSprite* backgroundSprite;
    s32 i;

    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    if (sSkyboxFlags & SKYBOX_NIGHTTIME) {
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
    } else {
        gDPSetCombineLERP(gfx++, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0,
                          SHADE, 0);
    }

    gDPSetPrimColor(gfx++, 0, 0, sBackgroundSpriteR, sBackgroundSpriteG, sBackgroundSpriteB, 255);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0, backgroundSprite = sBackgroundSprites; i < sBackgroundSpriteCount; i++, backgroundSprite++) {
        if (!backgroundSprite->isVisible) {
            continue;
        }
        gSPMatrix(gfx++, &D_1000000.unk_2C368[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPVertex(gfx++, D_1000000.unk_2C4E8, 4, 0);
        gDPPipeSync(gfx++);

        if (sSkyboxFlags & SKYBOX_NIGHTTIME) {
            gDPLoadTLUT_pal256(gfx++, D_1000000.unk_2C528[backgroundSprite->replacementIndex]);
        } else {
            gDPLoadTLUT_pal256(gfx++, backgroundSprite->palette);
        }
        gDPLoadTextureBlock_4b(gfx++, backgroundSprite->texture, G_IM_FMT_CI, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
    }
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    return gfx;
}

void Background_InitStars(void) {
    Star* star;
    s32 i;
    s32 j;
    f32 scale;
    s32 angle;

    if ((gNumPlayers > 0) && (gNumPlayers < 5)) {
        sStarCount = 100 / gNumPlayers;
    }

    for (i = 0, star = sStars; i < sStarCount; i++, star++) {
        for (j = 0; j < 4; j++) {
            star->isVisible[j] = false;
            star->screenPosition[j].left = star->screenPosition[j].top = 0.0f;
        }

        star->pos.y = (Math_Rand1() % 100000) + 100000.0f;
        angle = Math_Rand1() % 0x1000;
        scale = Math_Rand1() % 800000;
        star->pos.x = COS(angle) * scale;
        star->pos.z = SIN(angle) * scale;

        scale = ((Math_Rand1() % 10) + 1) * 0.1f;
        star->red = star->green = 255.0f * scale;
        star->blue = 64.0f * scale;
        star->alpha = 255;
    }
}

void Background_UpdateStars(s32 cameraIndex, Background* background, Camera* camera) {
    Star* star;
    s32 i;
    f32 distanceInFrontOfCamera;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 xPos;
    f32 yPos;
    f32 zPos;
    StarPosition* screenPosition;

    for (i = 0, star = sStars; i < sStarCount; i++, star++) {
        xPos = star->pos.x;
        yPos = star->pos.y;
        zPos = star->pos.z;
        temp_fa1 = xPos - camera->eye.x;
        temp_ft4 = yPos - camera->eye.y;
        temp_ft5 = zPos - camera->eye.z;
        distanceInFrontOfCamera =
            ((temp_fa1 * camera->basis.x.x) + (temp_ft4 * camera->basis.x.y) + (temp_ft5 * camera->basis.x.z));
        if (distanceInFrontOfCamera <= 0.0f) {
            star->isVisible[cameraIndex] = false;
        } else {
            temp_fa1 = ((camera->projectionViewMtx.m[0][0] * xPos) + (camera->projectionViewMtx.m[1][0] * yPos) +
                        (camera->projectionViewMtx.m[2][0] * zPos)) +
                       camera->projectionViewMtx.m[3][0];
            temp_ft4 = ((camera->projectionViewMtx.m[0][1] * xPos) + (camera->projectionViewMtx.m[1][1] * yPos) +
                        (camera->projectionViewMtx.m[2][1] * zPos)) +
                       camera->projectionViewMtx.m[3][1];
            temp_ft5 = ((camera->projectionViewMtx.m[0][3] * xPos) + (camera->projectionViewMtx.m[1][3] * yPos) +
                        (camera->projectionViewMtx.m[2][3] * zPos)) +
                       camera->projectionViewMtx.m[3][3];
            star->screenPosition[cameraIndex].left =
                camera->currentVpTransX + ((temp_fa1 * camera->currentVpScaleX) / temp_ft5);
            star->screenPosition[cameraIndex].top =
                camera->currentVpTransY - ((temp_ft4 * camera->currentVpScaleY) / temp_ft5);
            screenPosition = &star->screenPosition[cameraIndex];
            if ((screenPosition->left < camera->currentScissorLeft) ||
                (camera->currentScissorRight < screenPosition->left) ||
                ((screenPosition->top < camera->currentScissorTop)) ||
                (camera->currentScissorBottom < screenPosition->top)) {
                star->isVisible[cameraIndex] = false;
            } else {
                star->isVisible[cameraIndex] = true;
            }
        }
    }
}

Gfx* Background_DrawStars(Gfx* gfx, s32 cameraIndex) {
    Star* star;
    s32 i;
    s32 xl;
    s32 yl;
    s32 xh;
    s32 yh;
    StarPosition* screenPosition;

    gDPLoadTextureBlock(gfx++, sStarTexture, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0, star = sStars; i < sStarCount; i++, star++) {
        if (!star->isVisible[cameraIndex]) {
            continue;
        }
        screenPosition = &star->screenPosition[cameraIndex];

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, star->red, star->green, star->blue, star->alpha);

        xl = (screenPosition->left) * 4.0f;
        yl = (screenPosition->top) * 4.0f;
        xh = (screenPosition->left + 8.0f) * 4.0f;
        yh = (screenPosition->top + 8.0f) * 4.0f;

        gSPTextureRectangle(gfx++, xl, yl, xh, yh, 0, 0, 0, 1 << 10, 1 << 10);
    }
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);

    return gfx;
}
