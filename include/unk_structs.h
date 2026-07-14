#ifndef UNK_STRUCTS_H
#define UNK_STRUCTS_H

#include "libultra/ultra64.h"
#include "libc/stdbool.h"
#include "other_types.h"
#include "fzx_math.h"
#include "PR/leo.h"

typedef struct CourseSegment {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f up;
    /* 0x18 */ f32 radiusLeft;
    /* 0x1C */ f32 radiusRight;
    /* 0x20 */ s32 trackSegmentInfo;
    /* 0x24 */ f32 tension;
    /* 0x28 */ f32 length;
    /* 0x2C */ f32 lengthFromStart;
    /* 0x30 */ s32 segmentIndex;
    /* 0x34 */ struct CourseSegment* next;
    /* 0x38 */ struct CourseSegment* prev;
    /* 0x3C */ struct SegmentChunk* startChunk;
    /* 0x40 */ struct SegmentChunk* endChunk;
    /* 0x44 */ struct Jump* jumpsStart;
    /* 0x48 */ struct Jump* jumpsEnd;
    /* 0x4C */ struct Landmine* landminesStart;
    /* 0x50 */ struct Landmine* landminesEnd;
    /* 0x54 */ struct Effect* effectsStart;
    /* 0x58 */ struct Effect* effectsEnd;
    /* 0x5C */ s8 unk_5C[0x8]; // likely a pair of EffectDrawData struct ptrs
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 previousJoinEndTValue;
    /* 0x6C */ f32 nextJoinStartTValue;
    /* 0x70 */ f32 joinScale;
    /* 0x74 */ Vec3f quarterMarkPos;
    /* 0x80 */ Vec3f halfMarkPos;
    /* 0x8C */ Vec3f threeQuarterMarkPos;
    /* 0x98 */ f32 quarterMarkLength;
    /* 0x9C */ f32 halfMarkLength;
    /* 0xA0 */ f32 threeQuarterMarkLength;
} CourseSegment; // size = 0xA4

typedef struct MachineInfo {
    /* 0x00 */ u8 character;
    /* 0x01 */ u8 customType;
    /* 0x02 */ u8 frontType;
    /* 0x03 */ u8 rearType;
    /* 0x04 */ u8 wingType;
    /* 0x05 */ u8 logo;
    /* 0x06 */ u8 number;
    /* 0x07 */ u8 decal;
    /* 0x08 */ u8 bodyR;
    /* 0x09 */ u8 bodyG;
    /* 0x0A */ u8 bodyB;
    /* 0x0B */ u8 numberR;
    /* 0x0C */ u8 numberG;
    /* 0x0D */ u8 numberB;
    /* 0x0E */ u8 decalR;
    /* 0x0F */ u8 decalG;
    /* 0x10 */ u8 decalB;
    /* 0x11 */ u8 cockpitR;
    /* 0x12 */ u8 cockpitG;
    /* 0x13 */ u8 cockpitB;
} MachineInfo; // size = 0x14

typedef struct CourseInfo {
    /* 0x00 */ s32 encodedCourseIndex;
    /* 0x04 */ s32 courseIndex;
    /* 0x08 */ s32 segmentCount;
    /* 0x0C */ f32 length;
    /* 0x10 */ CourseSegment* courseSegments;
    /* 0x14 */ s16 courseFogColors[3];
    /* 0x1A */ s16 racerFogColors[3];
    /* 0x20 */ s32 timeRecord[5];
    /* 0x34 */ MachineInfo recordMachineInfos[5];
    /* 0x98 */ f32 recordEngines[5];
    /* 0xAC */ u8 recordNames[5][4];
    /* 0xC0 */ f32 maxSpeed;
    /* 0xC4 */ MachineInfo maxSpeedMachine;
    /* 0xD8 */ s32 bestTime;
    /* 0xDC */ MachineInfo bestTimeMachine;
} CourseInfo; // size = 0xF0

typedef struct Jump {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Mtx3F basis;
    /* 0x30 */ Vec3f dimensions; // width, height, depth
    /* 0x3C */ s8 unk_3C[0x4];
} Jump; // size = 0x40

typedef struct Landmine {
#ifndef EXPANSION_KIT
    /* 0x00 */ s32 unk_00;
#endif
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s8 unk_10[0x4];
} Landmine; // size = 0x10

typedef struct Effect {
    /* 0x00 */ s32 effectType;
    /* 0x04 */ f32 segmentTValueStart;
    /* 0x08 */ f32 segmentTValueEnd;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ s8 unk_24[0x4];
} Effect; // size = 0x28

#define DASH_LATERAL_OFFSET(effect) ((effect)->rightEdgeDistance)
#define DASH_LATERAL_OFFSET2(effect) ((effect)->leftEdgeDistance)
#define DASH_ANGLE(effect) ((effect)->rightEdgeDistance)
#define DASH_ANGLE2(effect) ((effect)->leftEdgeDistance)

typedef struct CourseEffect {
    /* 0x00 */ s32 segmentIndex;
    /* 0x04 */ s32 effectType;
    /* 0x08 */ f32 segmentTValueStart;
    /* 0x0C */ f32 segmentTValueEnd;
    /* 0x10 */ f32 rightEdgeDistance;
    /* 0x14 */ f32 leftEdgeDistance;
} CourseEffect; // size = 0x18

typedef struct CourseFeature {
    /* 0x00 */ s32 featureType;
    /* 0x04 */ s32 segmentIndex;
    /* 0x08 */ f32 segmentTValue;
    /* 0x0C */ f32 lateralOffset;
    /* 0x10 */ Vec3f dimensions;
} CourseFeature; // size = 0x1C

typedef struct CourseFeaturesInfo {
    /* 0x00 */ CourseFeature* features;
    /* 0x04 */ s32 featureCount;
    /* 0x08 */ s32 landmineCount;
    /* 0x0C */ s32 jumpCount;
} CourseFeaturesInfo; // size = 0x10

typedef struct CourseDecoration {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Mtx3F basis;
    /* 0x30 */ f32 scale;
    /* 0x34 */ struct SegmentChunk* loadChunk;
} CourseDecoration; // size = 0x38

typedef struct CourseEffectsInfo {
    /* 0x00 */ CourseEffect* effects;
    /* 0x04 */ s32 count;
} CourseEffectsInfo; // size = 0x8

typedef struct EffectDrawData {
    /* 0x00 */ s32 effectType;
    /* 0x04 */ Vtx* vtxStart;
    /* 0x08 */ Vtx* vtxEnd;
    /* 0x0C */ s8 unk_0C[0x4];
} EffectDrawData; // size = 0x10

typedef struct RacerSegmentPositionInfo {
    /* 0x00 */ CourseSegment* courseSegment;
    /* 0x04 */ f32 segmentTValue;
    /* 0x08 */ f32 segmentLengthProportion;
    /* 0x0C */ Vec3f segmentForward;
    /* 0x18 */ f32 segmentForwardMagnitude;
    /* 0x1C */ Vec3f segmentPos;
    /* 0x28 */ Vec3f segmentDisplacement;
    /* 0x34 */ Vec3f pos;
    /* 0x40 */ f32 distanceFromSegment;
    /* 0x44 */ Vec3f lastGroundedPos;
} RacerSegmentPositionInfo; // size = 0x50

typedef struct Racer {
    s32 id;
    s32 stateFlags;
    u16 soundEffectFlags;
    s16 points;
    RacerSegmentPositionInfo segmentPositionInfo;
    Vec3f unk_5C;
    Vec3f unk_68;
    Vec3f velocity;
    Vec3f unk_80;
    Vec3f acceleration;
    f32 speed;
    f32 maxSpeed;
    f32 heightAboveGround;
    f32 podiumHeight;
    Vec3f gravityUp;
    Vec3f tiltUp;
    Mtx3F trueBasis;
    f32 tiltUpInput;
    Mtx3F modelBasis;
    Vec3f modelPos;
    Vec3f recoilTilt;
    MtxF modelMatrix;
    s8 modelMatrixInit;
    s8 shadowMatrixInit;
    s8 attackHighlightMatrixInit;
    s8 customType;
    Vec3f shadowPos;
    f32 shadowColorStrength;
    f32 attackHighlightScale;
    f32 unk_17C;
    Vec3f focusPos;
    Vec3f focusVelocity;
    f32 unk_198;
    Vec3f upFromGround;
    f32 unk_1A8;
    f32 boostEnergyUsage;
    f32 unk_1B0;
    f32 unk_1B4;
    f32 unk_1B8;
    f32 unk_1BC;
    f32 unk_1C0;
    f32 unk_1C4;
    f32 unk_1C8;
    f32 unk_1CC;
    f32 unk_1D0;
    f32 accelerationForce;
    f32 driftAttackForce;
    f32 jumpBoost;
    f32 unk_1E0;
    f32 unk_1E4;
    f32 unk_1E8;
    f32 unk_1EC;
    f32 unk_1F0;
    f32 collidingStrength;
    f32 unk_1F8;
    f32 unk_1FC;
    f32 unk_200;
    s32 unk_204;
    s32 unk_208;
    s32 unk_20C;
    s32 vibrationStrength;
    s32 unk_214;
    s32 boostTimer;
    s32 spinOutTimer;
    s32 bodyWhiteTimer;
    f32 pitForceFieldSize;
    f32 energy;
    f32 maxEnergy;
    f32 energyRegain;
    f32 unk_234;
    f32 unk_238;
    f32 raceDistance;
    f32 lapsCompletedDistance;
    f32 lapDistance;
    f32 raceDistancePosition;
    Mtx3F segmentBasis;
    f32 currentRadiusLeft;
    f32 currentRadiusRight;
    s16 zButtonTimer;
    s16 rButtonTimer;
    s32 unk_27C;
    s32 unk_280;
    s16 attackState;
    s16 driftAttackDirection;
    s32 unk_288;
    struct Racer* unk_28C;
    s32 lapTimes[3];
    s32 completedLapsTime;
    s32 raceTime;
    s32 unk_2A4;
    s16 lap;
    s16 lapsCompleted;
    s32 position;
    s16 startNewPracticeLap;
    s8 unk_2B2;
    s8 unk_2B3;
    s32 machineLod;
    struct Racer* racerAhead;
    struct Racer* racerBehind;
    f32 distanceToRacerAhead;
    f32 distanceFromRacerBehind;
    s8 character;
    s8 machineIndex;
    u8 shadowType;
    u8 boostersType;
    s16 machineSkinIndex;
    s16 bodyR;
    s16 bodyG;
    s16 bodyB;
    s16 shadowR;
    s16 shadowG;
    s16 shadowB;
    s16 attackHighlightR;
    s16 attackHighlightG;
    s16 attackHighlightB;
    f32 bodyRF;
    f32 bodyGF;
    f32 bodyBF;
    f32 bodyLowEnergyR;
    f32 bodyLowEnergyG;
    f32 bodyLowEnergyB;
    f32 bodyLowEnergyGradientR;
    f32 bodyLowEnergyGradientG;
    f32 bodyLowEnergyGradientB;
    f32 shadowBaseR;
    f32 shadowBaseG;
    f32 shadowBaseB;
    s8 unk_310[0xC];
    f32 unk_31C;
    f32 unk_320;
    f32 unk_324;
    f32 unk_328;
    f32 energyIncrease;
    f32 unk_330;
    f32 unk_334;
    f32 unk_338;
    f32 unk_33C;
    s32 unk_340;
    s8 segmentLandmine;
    s8 segmentJump;
    s8 segmentDirt;
    s8 segmentIce;
    s8 segmentPit;
    s8 segmentDash;
    s8 nextSegmentLandmine;
    s8 nextSegmentDirt;
    s8 nextSegmentDash;
    s8 unk_34D;
    s16 obstaclePriorityState;
    s16 unk_350;
    s16 unk_352;
    f32 unk_354;
    s32 lastSegmentIndex;
    s32 trackSegmentForm;
    f32 unk_360;
    f32 unk_364;
    u32 unk_368;
    s32 awarenessFlags;
    s32 unk_370;
    s32 lastStickX;
    s32 lastStickY;
    s32 lastButtonsPressed;
    s32 lastButtonsCurrent;
    s32 unk_384;
    f32 unk_388;
    f32 unk_38C;
    s32 driftingCounter;
    s32 unk_394;
    s32 unk_398;
    s32 unk_39C;
    s32 unk_3A0;
    s32 unk_3A4;
} Racer; // size = 0x3A8

typedef struct SegmentChunk {
    /* 0x00 */ s32 trackSegmentInfo;
    /* 0x04 */ s32 segmentIndex;
    /* 0x08 */ f32 segmentTValue;
    /* 0x0C */ f32 depth;
    /* 0x10 */ bool drawState;
    /* 0x14 */ Vec3f pos;
    /* 0x20 */ s16 referencePos1[3];
    /* 0x26 */ s16 referencePos2[3];
    /* 0x2C */ s16 referencePos3[3];
    /* 0x32 */ s16 referencePos4[3];
    /* 0x38 */ s16 referencePos5[3];
    /* 0x3E */ s16 referencePos6[3];
    /* 0x44 */ s16 referencePos7[3];
    /* 0x4A */ s16 referencePos8[3];
    /* 0x50 */ s16 topTextureCoord;
    /* 0x52 */ s16 bottomTextureCoord;
    /* 0x54 */ s16 leftTextureCoord;
    /* 0x56 */ s16 rightTextureCoord;
    /* 0x58 */ s16 topTextureCorrection;
    /* 0x5A */ s16 bottomTextureCorrection;
    /* 0x5C */ s16 leftTextureCorrection;
    /* 0x5E */ s16 rightTextureCorrection;
} SegmentChunk; // size = 0x60

typedef struct Ghost {
    /* 0x0000 */ s32 encodedCourseIndex;
    /* 0x0004 */ s32 raceTime;
    /* 0x0008 */ s32 lapTimes[3];
    /* 0x0014 */ s32 replayEnd;
    /* 0x0018 */ s32 replaySize;
    /* 0x001C */ s8 replayData[16200];
    /* 0x3F64 */ s32 replayChecksum;
    /* 0x3F68 */ s16 ghostType;
    /* 0x3F6A */ MachineInfo machineInfo;
} Ghost; // size = 0x3F80

typedef struct CacheTexInfo {
    /* 0x00 */ s16 format;
    /* 0x04 */ void* segAddr;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ size_t compressedSize;
} CacheTexInfo; // size = 0x10

typedef struct TextureCacheEntry {
    void* segAddr;
    TexturePtr texture;
} TextureCacheEntry; // size = 0x8

typedef struct QueuedTextureLoad {
    CacheTexInfo* CacheTexInfo;
    TexturePtr texture;
} QueuedTextureLoad; // size = 0x8

typedef struct TextureSwapEntry {
    CacheTexInfo* CacheTexInfo;
    s32 unk_04;
} TextureSwapEntry;

typedef struct TexSwapSlot {
    TextureSwapEntry* entries;
    s16 entryIndex;
    s16 unk_06;
    s16 allocated;
    s16 slotTextureId;
    TexturePtr textureA; // primary texture
    TexturePtr textureB; // alternate texture (defaults to primary)
} TexSwapSlot; // size = 0x14


typedef struct unk_800DCE48 {
    s32 gameMode;
    s8 unk_04[0xC];
    s32 unk_10;
} unk_800DCE48; // size = 0x14

typedef struct GhostRacer {
    s32 frameCount;
    Ghost* ghost;
    s8* replayPtr;
    s32 replayIndex;
    s16 initialized;
    s16 exists;
    s32 replayPosX;
    s32 replayPosY;
    s32 replayPosZ;
    Vec3f pos;
    f32 scale;
    Racer* racer;
} GhostRacer; // size 0x34

typedef struct RaceStats {
    s32 raceTime;
    f32 maxSpeed;
    s16 position;
    s16 unk_0A;
    s16 racersKOd;
    s8 unk_0E[0x2];
} RaceStats; // size = 0x10

typedef struct unk_80141C88_unk_1D {
    MachineInfo unk_00;
    s8 unk_14[12];
} unk_80141C88_unk_1D;

typedef struct GhostInfo {
    /* 0x00 */ s32 courseIndex;
    /* 0x04 */ s32 encodedCourseIndex;
    /* 0x08 */ s32 raceTime;
    /* 0x0C */ s32 replayChecksum;
    /* 0x10 */ u16 ghostType;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ char trackName[9];
    /* 0x1D */ unk_80141C88_unk_1D unk_1D;
} GhostInfo; // size = 0x40
typedef struct Machine {
    s16 customType;
    u8 shadowType;
    u8 boostersType;
    u8 red[4];
    u8 green[4];
    u8 blue[4];
    u8 number;
    s8 machineStats[3];
    s16 weight;
} Machine; // size = 0x16

#ifndef EXPANSION_KIT
typedef struct unk_80225800 {
    /* 0x0000 */ Mtx unk_000;
    /* 0x0040 */ Vtx jumpVtx[4 * 6];
    /* 0x01C0 */ Vtx landmineVtx[48 * 5];
    /* 0x10C0 */ Vtx terrainEffectVtx[0x800];
    /* 0x90C0 */ Vtx dashVtx[0x80];
    /* 0x98C0 */ Mtx decorationMtx[32];
} unk_80225800; // size = 0xA0C0
#else
typedef struct unk_80225800 {
    /* 0x0000 */ Mtx unk_000;
    /* 0x0040 */ Vtx jumpVtx[8 * 6];
    /* 0x0340 */ Vtx landmineVtx[48 * 5];
    /* 0x1240 */ Vtx terrainEffectVtx[0x800];
    /* 0x9240 */ Vtx dashVtx[0xC0];
    /* 0x9E40 */ Mtx decorationMtx[32];
} unk_80225800; // size = 0xA640
#endif

typedef struct BoosterInfo {
    s32 count;
    Vec3f pos[4];
    f32 size[4];
} BoosterInfo;

typedef struct TextureInfo {
    /* 0x00 */ TexturePtr texture;
    /* 0x04 */ s16 width;
    /* 0x06 */ s16 height;
} TextureInfo; // size = 0x8

typedef struct CustomMachine {
    /* 0x00 */ u8 body;
    /* 0x01 */ u8 boost;
    /* 0x02 */ u8 grip;
    /* 0x03 */ u8 frontType;
    /* 0x04 */ u8 rearType;
    /* 0x05 */ u8 wingType;
    /* 0x06 */ u8 logo;
    /* 0x07 */ u8 number;
    /* 0x08 */ u8 decal;
    /* 0x09 */ u8 red;
    /* 0x0A */ u8 green;
    /* 0x0B */ u8 blue;
    /* 0x0C */ u8 numberR;
    /* 0x0D */ u8 numberG;
    /* 0x0E */ u8 numberB;
    /* 0x0F */ u8 decalR;
    /* 0x10 */ u8 decalG;
    /* 0x11 */ u8 decalB;
    /* 0x12 */ u8 cockpitR;
    /* 0x13 */ u8 cockpitG;
    /* 0x14 */ u8 cockpitB;
    /* 0x15 */ char machineName[9];
    /* 0x1E */ u16 checksum;
} CustomMachine; // size = 0x20

typedef struct CustomMachinesInfo {
    /* 0x000 */ CustomMachine customMachines[30];
    /* 0x3C0 */ s8 characterCustomState[30];
    /* 0x3DE */ u16 checksum;
} CustomMachinesInfo; // size = 0x3E0

typedef struct unk_80128C94 {
    /* 0x00000 */ Mtx unk_0000;
    /* 0x00040 */ Mtx unk_0040;
    /* 0x00080 */ s8 unk_0080[0x80];
    /* 0x00100 */ Mtx unk_0100;
    /* 0x00140 */ s8 unk_0140[0x40];
    /* 0x00180 */ Vtx unk_0180[64 * 6];
    /* 0x01980 */ Vtx unk_1980[898];
    /* 0x051A0 */ s8 unk_51A0[0x200];
    /* 0x053A0 */ Vtx jumpVtx[8 * 6];
    /* 0x056A0 */ Vtx landmineVtx[5 * 48];
    /* 0x065A0 */ Vtx terrainEffectVtx[0x800];
    /* 0x0E5A0 */ Vtx dashVtx[0x80];
    /* 0x0EDA0 */ s8 unk_EDA0[0x400];
    /* 0x0F1A0 */ Mtx decorationMtx[0x20];
    /* 0x0F9A0 */ Gfx unk_F9A0[741];
    /* 0x110C8 */ Gfx unk_110C8[5064];
} unk_80128C94; // size = 0x1AF08

typedef struct unk_807C6F10 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 lba;
    /* 0x08 */ void* vAddr;
    /* 0x0C */ s32 nLBAs;
    /* 0x10 */ OSPiHandle* piHandle;
    /* 0x14 */ OSIoMesg* ioMesg;
    /* 0x18 */ s32 direction;
    /* 0x1C */ LEOCmd* cmdBlock;
    /* 0x20 */ OSMesgQueue* mq;
} unk_807C6F10; // size = 0x24

typedef struct unk_807C6EA8 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ u16 dirId;
    /* 0x18 */ char* name;
    /* 0x1C */ char* extension;
    /* 0x20 */ void* readBuf;
    /* 0x24 */ s32 offset;
    /* 0x28 */ s32 fileSize;
    /* 0x2C */ s32 attr;
    /* 0x30 */ s32 copyCount;
    /* 0x34 */ bool writeChanges;
    /* 0x38 */ void* writeBuf;
    /* 0x3C */ char* oldName;
    /* 0x40 */ char* oldExtension;
    /* 0x44 */ char* newName;
    /* 0x48 */ char* newExtension;
    /* 0x4C */ s32 attributeToAdd;
    /* 0x50 */ s32 attributeToRemove;
    /* 0x54 */ u8 unk_54;
    /* 0x58 */ s32 startLba;
    /* 0x5C */ s32 lbaBuf;
    /* 0x60 */ s32 bssSize;
} unk_807C6EA8;

typedef struct unk_8003A5D8 {
    /* 0x00 */ char name[16];
    /* 0x10 */ s32 attr;
    /* 0x14 */ s8 unk_14[0x8];
    /* 0x1C */ char unk_1C;
    /* 0x1D */ char extension[5];
    /* 0x22 */ u8 unk_22;
    /* 0x23 */ s8 unk_23;
} unk_8003A5D8; //size = 0x24

typedef struct unk_800D6CA0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s8 unk_18[0x4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ CourseSegment unk_28;
    /* 0xCC */ s8 unk_CC[0x24];
} unk_800D6CA0; // size = 0xF0

typedef struct MenuDropItem {
    /* 0x00 */ void* backgroundTex;
    /* 0x04 */ void* backgroundSelectedTex;
    /* 0x08 */ void* contentsTex;
    /* 0x0C */ void* subContentsRGBATex;
    /* 0x10 */ struct MenuWidget* widget;
    /* 0x14 */ void (*action)(void);
    /* 0x18 */ u16 contentsWidth;
    /* 0x1A */ u16 contentsHeight;
    /* 0x1C */ void* unk_1C;
    /* 0x20 */ void* subContentsI4Tex;
} MenuDropItem; // size = 0x24

typedef struct MenuWidget {
    /* 0x00 */ s32 numItems;
    /* 0x04 */ s32 openIndex;
    /* 0x08 */ s32 highlightedIndex;
    /* 0x0C */ s32 left;
    /* 0x10 */ s32 top;
    /* 0x14 */ s32 itemXOffset;
    /* 0x18 */ s32 itemYOffset;
    /* 0x1C */ MenuDropItem* menuItems;
    /* 0x20 */ s32 cursorMinPosX;
    /* 0x24 */ s32 cursorMinPosY;
    /* 0x28 */ s32 cursorMaxPosX;
    /* 0x2C */ s32 cursorMaxPosY;
    /* 0x30 */ s32* option;
} MenuWidget; // size = 0x34

typedef struct unk_807B3C20 {
    /* 0x0000 */ CourseSegment unk_0000[64];
    /* 0x2900 */ s32 controlPointCount;
} unk_807B3C20; // size 0x2904

typedef struct unk_80128690 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} unk_80128690; // size = 0xC

typedef struct unk_8011C220 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ Mtx3F basis;
} unk_8011C220; // size = 0x38

typedef struct unk_80140E60 {
    /* 0x00 */ s32 unk_00; // type
    /* 0x04 */ s32 unk_04; // value
} unk_80140E60; // size = 0x8

typedef struct unk_801413F0 {
    /* 0x00 */ Mtx unk_00;
    /* 0x40 */ LookAt unk_40;
} unk_801413F0; // size = 0x60

#endif // UNK_STRUCTS_H
