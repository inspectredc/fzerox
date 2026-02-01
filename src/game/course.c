#include "global.h"
#include "fzx_racer.h"
#include "fzx_game.h"
#include "fzx_course.h"
#include "fzx_math.h"
#include "fzx_camera.h"
#include "fzx_segmentA.h"
#include ASSET_HEADER(course_track_gfx.h)

#define VERTEX_MODIFIED_ST(s, t) ((((s) << 15) & 0xFFFF0000) | ((t) &0xFFFF))

typedef struct unk_800CF528 {
    s32 texture;
    f32 textureScale;
    s32 width;
    s32 tile;
    s32 unk_10;
    s16 textureCoordinateMask;
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
    s16 unk_1C;
    s16 unk_1E;
} unk_800CF528; // size = 0x20

typedef struct unk_800F8958 {
    SegmentChunk* chunk;
    Gfx* unk_04;
    Gfx* unk_08;
    Gfx* unk_0C;
    Gfx* unk_10;
    Gfx* unk_14;
    Gfx* unk_18;
    Gfx* unk_1C;
    Gfx* unk_20;
    Gfx* unk_24;
    Gfx* unk_28;
    s32 loadVtxIndex;
} unk_800F8958; // size = 0x30

typedef struct SegmentChunkGroup {
    SegmentChunk* startChunk;
    SegmentChunk* endChunk;
    f32 averageDepth;
    s32 drawState;
} SegmentChunkGroup; // size = 0x10

CourseInfo* gCurrentCourseInfo;
s32 gCourseIndex;
s32 gSegmentChunkCount;
SegmentChunk* sLastSegmentChunk;
Vtx* gCourseVtxPtr;
s32 D_800F8524;
SegmentChunkGroup sSegmentChunkGroups[64];
s32 sLastTrackShapeType;
s32 D_800F892C;
s16 D_800F8930[5];
s32 sRandomCourseInitSeed1;
s32 sRandomCourseInitMask1;
s32 sRandomCourseInitSeed2;
s32 sRandomCourseInitMask2;
f32 D_800F894C;
f32 D_800F8950;
unk_800F8958 D_800F8958[2];
unk_800F8958* D_800F89B8;
unk_800F8958* D_800F89BC;
s32 D_800F89C0;
Gfx* sCourseDisp;
SegmentChunk* D_800F89C8;
SegmentChunk* sWorkingSegmentChunk;
SegmentChunk* sWorkingNextSegmentChunk;
s32 D_800F89D4;
bool D_800F89D8;
s32 sWorkingChunkJoinInfo;
f32 D_800F89E0;
f32 D_800F89E4;
f32 D_800F89E8;

s32 D_800CF500 = 0;
s16 gLastRandomCourseIndex = -1;
s32 sCourseFogStartDistance = 990;
UNUSED s32 D_800CF50C = 0;

f32 D_800CF510 = 6000.0f;
f32 D_800CF514 = 1500.0f;
f32 D_800CF518 = 3000.0f;
f32 D_800CF51C = 400.0f;
f32 sCourseFarRenderDistance = 5500.0f;
f32 sCourseRenderOriginDistance = 1000.0f;

// TRACK_SHAPE_ROAD
unk_800CF528 D_800CF528[] = {
    { D_A001000, 10.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_START_LINE
    { D_A000000, 10.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_1
    { D_A002000, 14.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_2
    { D_A003000, 14.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_3
    { D_A004000, 14.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_4
    { D_A005000, 14.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_5
    { D_A006000, 14.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_6
};

// TRACK_SHAPE_WALLED_ROAD
unk_800CF528 D_800CF608[] = {
    { D_A007000, 7.0f, 128, 0, 1, 511, 32, 0x1320, 0x1EA0, 0x1F60, 0x1FC0 }, // WALLED_ROAD_0
    { D_8000008, 7.0f, 128, 0, 1, 511, 32, 0x1320, 0x1EA0, 0x1F60, 0x1FC0 }, // WALLED_ROAD_1
    { D_8001008, 7.0f, 128, 0, 1, 511, 32, 0x1320, 0x1EA0, 0x1F60, 0x1FC0 }, // WALLED_ROAD_2
};

// TRACK_SHAPE_PIPE
unk_800CF528 D_800CF668[] = {
    { D_8008008, 2.8f, 128, 0, 2, 255, 32, 0x8A0, 0x1120, 0x1A20, 0x1FC0 }, // PIPE_0
    { D_8009008, 2.8f, 128, 0, 2, 255, 32, 0x8A0, 0x1120, 0x1A20, 0x1FC0 }, // PIPE_1
    { D_800A008, 2.8f, 128, 0, 2, 255, 32, 0x8A0, 0x1120, 0x1A20, 0x1FC0 }, // PIPE_2
    { D_800B008, 2.8f, 128, 0, 2, 255, 32, 0x8A0, 0x1120, 0x1A20, 0x1FC0 }, // PIPE_3
};

// TRACK_SHAPE_CYLINDER
unk_800CF528 D_800CF6E8[] = {
    { D_800C008, 9.3f, 128, 0, 1, 511, 32, 0x960, 0x12A0, 0x1B60, 0x1FC0 }, // CYLINDER_0
    { D_800D008, 9.3f, 128, 0, 1, 511, 32, 0x960, 0x12A0, 0x1B60, 0x1FC0 }, // CYLINDER_1
    { D_800E008, 9.3f, 128, 0, 1, 511, 32, 0x960, 0x12A0, 0x1B60, 0x1FC0 }, // CYLINDER_2
    { D_800F008, 9.3f, 128, 0, 1, 511, 32, 0x960, 0x12A0, 0x1B60, 0x1FC0 }, // CYLINDER_3
};

// TRACK_SHAPE_HALF_PIPE
unk_800CF528 D_800CF768[] = {
    { D_8010008, 14.0f, 64, 4, 5, 1023, 32, 0x5E0, 0xBE0, 0xDE0, 0xFC0 }, // HALF_PIPE_0
    { D_8011008, 4.0f, 64, 4, 5, 1023, 32, 0x5E0, 0xBE0, 0xDE0, 0xFC0 },  // HALF_PIPE_1
    { D_8012008, 7.0f, 64, 4, 5, 1023, 32, 0x5E0, 0xBE0, 0xDE0, 0xFC0 },  // HALF_PIPE_2
    { D_8013008, 14.0f, 64, 4, 5, 1023, 32, 0x5E0, 0xBE0, 0xDE0, 0xFC0 }, // HALF_PIPE_3
};

// TRACK_SHAPE_TUNNEL
unk_800CF528 D_800CF7E8[] = {
    { D_8004008, 14.0f, 64, 4, 6, 1023, 32, 0x3A0, 0x660, 0x960, 0xFC0 }, // TUNNEL_0
    { D_8005008, 14.0f, 64, 4, 6, 1023, 32, 0x3A0, 0x660, 0x960, 0xFC0 }, // TUNNEL_1
    { D_8006008, 14.0f, 64, 4, 6, 1023, 32, 0x3A0, 0x660, 0x960, 0xFC0 }, // TUNNEL_2
    { D_8007008, 14.0f, 64, 4, 6, 1023, 32, 0x3A0, 0x660, 0x960, 0xFC0 }, // TUNNEL_3
};

// TRACK_SHAPE_BORDERLESS_ROAD
unk_800CF528 D_800CF868[] = {
    { D_A008000, 14.0f, 64, 4, 5, 1023, 32, 0xB60, 0xEA0, 0xF20, 0xFC0 }, // BORDERLESS_ROAD_0
    { D_8002008, 14.0f, 64, 4, 5, 1023, 32, 0xB60, 0xEA0, 0xF20, 0xFC0 }, // BORDERLESS_ROAD_1
    { D_8003008, 14.0f, 64, 4, 5, 1023, 32, 0xB60, 0xEA0, 0xF20, 0xFC0 }, // BORDERLESS_ROAD_2
};

unk_800CF528* D_800CF8C8[] = {
    D_800CF528, // TRACK_SHAPE_ROAD
    D_800CF608, // TRACK_SHAPE_WALLED_ROAD
    D_800CF668, // TRACK_SHAPE_PIPE
    D_800CF6E8, // TRACK_SHAPE_CYLINDER
    D_800CF768, // TRACK_SHAPE_HALF_PIPE
    D_800CF7E8, // TRACK_SHAPE_TUNNEL
    NULL,       // TRACK_SHAPE_AIR
    D_800CF868, // TRACK_SHAPE_BORDERLESS_ROAD
};

f32 gTrackJoinUpperLength[] = {
    0.0f,    // TRACK_SHAPE_ROAD
    50.0f,   // TRACK_SHAPE_WALLED_ROAD
    1000.0f, // TRACK_SHAPE_PIPE
    1000.0f, // TRACK_SHAPE_CYLINDER
    1000.0f, // TRACK_SHAPE_HALF_PIPE
    250.0f,  // TRACK_SHAPE_TUNNEL
    0.0f,    // TRACK_SHAPE_AIR
    50.0f,   // TRACK_SHAPE_BORDERLESS_ROAD
};

typedef void (*SegmentChunkCalculateReferencePosFunc)(SegmentChunk*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*,
                                                      Vec3f*);

void Course_ChunkCalculateRoadAirReferencePos(SegmentChunk*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void Course_ChunkCalculateWalledRoadReferencePos(SegmentChunk*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*,
                                                 Vec3f*);
void Course_ChunkCalculatePipeReferencePos(SegmentChunk*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void Course_ChunkCalculateCylinderReferencePos(SegmentChunk*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void Course_ChunkCalculateHalfPipeReferencePos(SegmentChunk*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void Course_ChunkCalculateTunnelReferencePos(SegmentChunk*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void Course_ChunkCalculateBorderlessRoadReferencePos(SegmentChunk*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*,
                                                     Vec3f*);

SegmentChunkCalculateReferencePosFunc sSegmentChunkCalculateReferencePosFuncs[] = {
    Course_ChunkCalculateRoadAirReferencePos,        // TRACK_SHAPE_ROAD
    Course_ChunkCalculateWalledRoadReferencePos,     // TRACK_SHAPE_WALLED_ROAD
    Course_ChunkCalculatePipeReferencePos,           // TRACK_SHAPE_PIPE
    Course_ChunkCalculateCylinderReferencePos,       // TRACK_SHAPE_CYLINDER
    Course_ChunkCalculateHalfPipeReferencePos,       // TRACK_SHAPE_HALF_PIPE
    Course_ChunkCalculateTunnelReferencePos,         // TRACK_SHAPE_TUNNEL
    Course_ChunkCalculateRoadAirReferencePos,        // TRACK_SHAPE_AIR
    Course_ChunkCalculateBorderlessRoadReferencePos, // TRACK_SHAPE_BORDERLESS_ROAD
};

typedef void (*SegmentChunkJoinFunc)(SegmentChunk*, SegmentChunk*, f32);

void Course_ChunkJoinPipeTunnel(SegmentChunk*, SegmentChunk*, f32);
void Course_ChunkJoinCylinder(SegmentChunk*, SegmentChunk*, f32);
void Course_ChunkJoinEqual(SegmentChunk*, SegmentChunk*, f32);

SegmentChunkJoinFunc sSegmentChunkJoinFuncs[] = {
    Course_ChunkJoinEqual,      // TRACK_SHAPE_ROAD
    Course_ChunkJoinEqual,      // TRACK_SHAPE_WALLED_ROAD
    Course_ChunkJoinPipeTunnel, // TRACK_SHAPE_PIPE
    Course_ChunkJoinCylinder,   // TRACK_SHAPE_CYLINDER
    Course_ChunkJoinEqual,      // TRACK_SHAPE_HALF_PIPE
    Course_ChunkJoinPipeTunnel, // TRACK_SHAPE_TUNNEL
    Course_ChunkJoinEqual,      // TRACK_SHAPE_AIR
    Course_ChunkJoinEqual,      // TRACK_SHAPE_BORDERLESS_ROAD
};

void Course_DrawBackwardRoadChunkGroup(void);
void Course_DrawBackwardPipeTunnelChunkGroup(void);
void Course_DrawBackwardCylinderChunkGroup(void);
void Course_DrawBackwardHalfPipeChunkGroup(void);
void Course_DrawBackwardAirChunkGroup(void);

void (*sBackwardChunkGroupDrawFuncs[])(void) = {
    Course_DrawBackwardRoadChunkGroup,       // TRACK_SHAPE_ROAD
    Course_DrawBackwardRoadChunkGroup,       // TRACK_SHAPE_WALLED_ROAD
    Course_DrawBackwardPipeTunnelChunkGroup, // TRACK_SHAPE_PIPE
    Course_DrawBackwardCylinderChunkGroup,   // TRACK_SHAPE_CYLINDER
    Course_DrawBackwardHalfPipeChunkGroup,   // TRACK_SHAPE_HALF_PIPE
    Course_DrawBackwardPipeTunnelChunkGroup, // TRACK_SHAPE_TUNNEL
    Course_DrawBackwardAirChunkGroup,        // TRACK_SHAPE_AIR
    Course_DrawBackwardRoadChunkGroup,       // TRACK_SHAPE_BORDERLESS_ROAD
};

void Course_DrawForwardRoadChunkGroup(void);
void Course_DrawForwardPipeTunnelChunkGroup(void);
void Course_DrawForwardCylinderChunkGroup(void);
void Course_DrawForwardHalfPipeChunkGroup(void);
void Course_DrawForwardAirChunkGroup(void);

void (*sForwardChunkGroupDrawFuncs[])(void) = {
    Course_DrawForwardRoadChunkGroup,       // TRACK_SHAPE_ROAD
    Course_DrawForwardRoadChunkGroup,       // TRACK_SHAPE_WALLED_ROAD
    Course_DrawForwardPipeTunnelChunkGroup, // TRACK_SHAPE_PIPE
    Course_DrawForwardCylinderChunkGroup,   // TRACK_SHAPE_CYLINDER
    Course_DrawForwardHalfPipeChunkGroup,   // TRACK_SHAPE_HALF_PIPE
    Course_DrawForwardPipeTunnelChunkGroup, // TRACK_SHAPE_TUNNEL
    Course_DrawForwardAirChunkGroup,        // TRACK_SHAPE_AIR
    Course_DrawForwardRoadChunkGroup,       // TRACK_SHAPE_BORDERLESS_ROAD
};

f32 D_800CF988[] = {
    7.5f,
    15.0f,
    30.0f,
    60.0f,
};

f32 D_800CF998[] = {
    0.0f,
    350.0f,
    700.0f,
    1400.0f,
};

s32 D_800CF9A8[] = {
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_3,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_3,
};

s32 D_800CF9B4[] = {
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_5,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_6,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_6,
};

s32 D_800CF9C0[] = {
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_4,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2,
};

s32 D_800CF9CC[] = {
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_4,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_3,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_3,
};

s32 D_800CF9D8[] = {
    TRACK_FLAG_8000000 | TRACK_SHAPE_BORDERLESS_ROAD | BORDERLESS_ROAD_0,
    TRACK_FLAG_8000000 | TRACK_SHAPE_BORDERLESS_ROAD | BORDERLESS_ROAD_1,
    TRACK_FLAG_8000000 | TRACK_SHAPE_BORDERLESS_ROAD | BORDERLESS_ROAD_2,
};

s32 D_800CF9E4[] = {
    TRACK_FLAG_8000000 | TRACK_SHAPE_WALLED_ROAD | WALLED_ROAD_0,
    TRACK_FLAG_8000000 | TRACK_SHAPE_WALLED_ROAD | WALLED_ROAD_1,
    TRACK_FLAG_8000000 | TRACK_SHAPE_WALLED_ROAD | WALLED_ROAD_2,
};

s32 D_800CF9F0[] = {
    TRACK_FLAG_INSIDE | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_0,
    TRACK_FLAG_INSIDE | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_1,
    TRACK_FLAG_INSIDE | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_2,
    TRACK_FLAG_INSIDE | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_3,
};

s32 D_800CFA00[] = {
    TRACK_SHAPE_HALF_PIPE | HALF_PIPE_0,
    TRACK_SHAPE_HALF_PIPE | HALF_PIPE_1,
    TRACK_SHAPE_HALF_PIPE | HALF_PIPE_2,
    TRACK_SHAPE_HALF_PIPE | HALF_PIPE_3,
};

s32 D_800CFA10[] = {
    TRACK_FLAG_INSIDE | TRACK_SHAPE_PIPE | PIPE_0,
    TRACK_FLAG_INSIDE | TRACK_SHAPE_PIPE | PIPE_1,
    TRACK_FLAG_INSIDE | TRACK_SHAPE_PIPE | PIPE_2,
    TRACK_FLAG_INSIDE | TRACK_SHAPE_PIPE | PIPE_3,
};

s32 D_800CFA20[] = {
    TRACK_SHAPE_CYLINDER | CYLINDER_0,
    TRACK_SHAPE_CYLINDER | CYLINDER_1,
    TRACK_SHAPE_CYLINDER | CYLINDER_2,
    TRACK_SHAPE_CYLINDER | CYLINDER_3,
};

void func_8009CED0(s32 venue) {
    switch (venue) {
        case VENUE_MUTE_CITY:
            D_800CF528[ROAD_2].textureScale = D_800CF528[ROAD_3].textureScale = D_800CF528[ROAD_4].textureScale =
                D_800CF528[ROAD_5].textureScale = D_800CF528[ROAD_6].textureScale = 16.0f;
            D_800CF868[BORDERLESS_ROAD_0].textureScale = 14.0f;
            D_800CF608[WALLED_ROAD_0].textureScale = 7.0f;
            break;
        case VENUE_BIG_BLUE:
            D_800CF528[ROAD_2].textureScale = D_800CF528[ROAD_3].textureScale = 14.0f;
            D_800CF528[ROAD_5].textureScale = 1.0f;
            D_800CF868[BORDERLESS_ROAD_0].textureScale = 1.0f;
            D_800CF528[ROAD_4].textureScale = 2.0f;
            D_800CF528[ROAD_6].textureScale = 6.0f;
            D_800CF608[WALLED_ROAD_0].textureScale = 7.0f;
            break;
        case VENUE_DEVILS_FOREST:
            D_800CF528[ROAD_2].textureScale = D_800CF528[ROAD_3].textureScale = D_800CF528[ROAD_4].textureScale =
                D_800CF528[ROAD_5].textureScale = D_800CF528[ROAD_6].textureScale =
                    D_800CF868[BORDERLESS_ROAD_0].textureScale = 14.0f;
            D_800CF608[WALLED_ROAD_0].textureScale = 3.5f;
            break;
        case VENUE_SECTOR:
            D_800CF868[BORDERLESS_ROAD_0].textureScale = 7.0f;
            D_800CF528[ROAD_4].textureScale = 5.0f;
            D_800CF528[ROAD_2].textureScale = D_800CF528[ROAD_3].textureScale = D_800CF528[ROAD_5].textureScale =
                D_800CF528[ROAD_6].textureScale = 10.0f;
            D_800CF608[WALLED_ROAD_0].textureScale = 3.5f;
            break;
        case VENUE_RED_CANYON:
            D_800CF528[ROAD_2].textureScale = D_800CF528[ROAD_3].textureScale = D_800CF528[ROAD_4].textureScale =
                D_800CF528[ROAD_5].textureScale = D_800CF528[ROAD_6].textureScale =
                    D_800CF868[BORDERLESS_ROAD_0].textureScale = 14.0f;
            D_800CF608[WALLED_ROAD_0].textureScale = 3.5f;
            break;
        case VENUE_SILENCE:
            D_800CF528[ROAD_2].textureScale = D_800CF528[ROAD_3].textureScale = D_800CF528[ROAD_5].textureScale =
                D_800CF528[ROAD_6].textureScale = D_800CF868[BORDERLESS_ROAD_0].textureScale = 14.0f;
            D_800CF528[ROAD_4].textureScale = 7.0f;
            D_800CF608[WALLED_ROAD_0].textureScale = 7.0f;
            break;
        case VENUE_ENDING:
            D_800CF528[ROAD_2].textureScale = D_800CF528[ROAD_3].textureScale = D_800CF528[ROAD_4].textureScale =
                D_800CF528[ROAD_5].textureScale = D_800CF528[ROAD_6].textureScale = 5.5f;
            D_800CF868[BORDERLESS_ROAD_0].textureScale = 14.0f;
            D_800CF608[WALLED_ROAD_0].textureScale = 7.0f;
            break;
        default:
            D_800CF528[ROAD_2].textureScale = D_800CF528[ROAD_3].textureScale = D_800CF528[ROAD_4].textureScale =
                D_800CF528[ROAD_5].textureScale = D_800CF528[ROAD_6].textureScale =
                    D_800CF868[BORDERLESS_ROAD_0].textureScale = 14.0f;
            D_800CF608[WALLED_ROAD_0].textureScale = 7.0f;
            break;
    }
}

s32 func_8009D16C(RacerSegmentPositionInfo* arg0, f32 arg1, f32 arg2, f32 arg3, Mtx3F* arg4) {
    s32 i;
    Vec3f sp130;
    CourseSegment* var_s1_2;
    CourseSegment* var_v1;
    CourseSegment* var_v0;
    CourseSegment* var_a0;
    f32 tSquare;
    f32 tCube;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 temp_fv1;
    f32 sp78;
    f32 sp74;
    s32 pad;
    f32 tension;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 spE8;
    CourseSegment* var_s0;
    CourseSegment* var_s1;
    CourseSegment* var_s2;
    CourseSegment* var_s3;
    RacerSegmentPositionInfo sp88;

    i = 3;

    sp130.x = arg1 - arg0->lastGroundedPos.x;
    sp130.y = arg2 - arg0->lastGroundedPos.y;
    sp130.z = arg3 - arg0->lastGroundedPos.z;

    var_s0 = arg0->courseSegment;
    var_s1 = var_s0->next;
    var_s2 = var_s0->prev;
    var_s3 = var_s1->next;
    tension = var_s0->tension;

    sp114 = tension - 2.0f;
    sp110 = sp114 - 1.0f;
    sp10C = sp110 + tension;
    sp78 = (sp10C - 3.0f) + tension;
    sp74 = sp78 + tension;

    sp88.segmentTValue = arg0->segmentTValue;
    sp88.courseSegment = arg0->courseSegment;
    sp88.segmentForward = arg0->segmentForward;
    sp88.segmentForwardMagnitude = arg0->segmentForwardMagnitude;

    while ((SQ_SUM(&sp130) > 5.0f) && (--i != 0)) {
        sp88.segmentTValue += (DOT_XYZ(&sp130, &sp88.segmentForward) / SQ(sp88.segmentForwardMagnitude));
        if (sp88.segmentTValue >= 1.0f) {
            if (sp88.segmentTValue > 1.9f) {
                return -1;
            }
            sp88.courseSegment = sp88.courseSegment->next;
            var_s2 = var_s0;
            var_s0 = var_s1;
            var_s1 = var_s3;
            var_s3 = sp88.courseSegment->next->next;
            tension = sp88.courseSegment->tension;
            sp114 = tension - 2.0f;
            sp110 = sp114 - 1.0f;
            sp10C = sp110 + tension;
            sp88.segmentTValue -= 1.0f;
            sp88.segmentTValue *=
                (sp88.segmentForwardMagnitude / Course_SplineGetTangent(sp88.courseSegment, 0.0f, &sp130));
        } else if (sp88.segmentTValue < 0.0f) {
            if (sp88.segmentTValue < -0.9f) {
                return -1;
            }
            sp88.courseSegment = sp88.courseSegment->prev;
            var_s3 = var_s1;
            var_s1 = var_s0;
            var_s0 = var_s2;
            var_s2 = sp88.courseSegment->prev;
            tension = sp88.courseSegment->tension;
            sp114 = tension - 2.0f;
            sp110 = sp114 - 1.0f;
            sp10C = sp110 + tension;

            sp88.segmentTValue *=
                (sp88.segmentForwardMagnitude / Course_SplineGetTangent(sp88.courseSegment, 1.0f, &sp130));
            sp88.segmentTValue += 1.0f;
        }
        tSquare = SQ(sp88.segmentTValue);
        tCube = tSquare * sp88.segmentTValue;
        temp_fa0 = (((2.0f * tSquare) - sp88.segmentTValue) - tCube) * tension;
        temp_fa1 = ((sp110 * tSquare) - sp114 * tCube) + 1.0f;
        temp_ft4 = (sp114 * tCube - (sp10C * tSquare)) + (tension * sp88.segmentTValue);
        spE8 = (tCube - tSquare) * tension;

        sp88.segmentPos.x = (temp_fa0 * var_s2->pos.x) + (temp_fa1 * var_s0->pos.x) + (temp_ft4 * var_s1->pos.x) +
                            (spE8 * var_s3->pos.x);
        sp88.segmentPos.y = (temp_fa0 * var_s2->pos.y) + (temp_fa1 * var_s0->pos.y) + (temp_ft4 * var_s1->pos.y) +
                            (spE8 * var_s3->pos.y);
        sp88.segmentPos.z = (temp_fa0 * var_s2->pos.z) + (temp_fa1 * var_s0->pos.z) + (temp_ft4 * var_s1->pos.z) +
                            (spE8 * var_s3->pos.z);

        sp78 = (sp10C - 3.0f) + tension;
        sp74 = sp78 + tension;

        temp_fa0 = (((4.0f * sp88.segmentTValue) - 1.0f) - (3.0f * tSquare)) * tension;
        temp_fa1 = ((sp10C - 3.0f) * sp88.segmentTValue) - sp78 * tSquare;
        temp_ft4 = (sp78 * tSquare - (sp74 * sp88.segmentTValue)) + tension;
        spE8 = ((3.0f * tSquare) - (2.0f * sp88.segmentTValue)) * tension;

        sp88.segmentForward.x = (temp_fa0 * var_s2->pos.x) + (temp_fa1 * var_s0->pos.x) + (temp_ft4 * var_s1->pos.x) +
                                (spE8 * var_s3->pos.x);
        sp88.segmentForward.y = (temp_fa0 * var_s2->pos.y) + (temp_fa1 * var_s0->pos.y) + (temp_ft4 * var_s1->pos.y) +
                                (spE8 * var_s3->pos.y);
        sp88.segmentForward.z = (temp_fa0 * var_s2->pos.z) + (temp_fa1 * var_s0->pos.z) + (temp_ft4 * var_s1->pos.z) +
                                (spE8 * var_s3->pos.z);

        sp88.segmentForwardMagnitude = sqrtf(SQ_SUM(&sp88.segmentForward));

        sp88.segmentDisplacement.x = arg1 - sp88.segmentPos.x;
        sp88.segmentDisplacement.y = arg2 - sp88.segmentPos.y;
        sp88.segmentDisplacement.z = arg3 - sp88.segmentPos.z;

        sp88.distanceFromSegment = sqrtf(SQ_SUM(&sp88.segmentDisplacement));

        if (sp88.distanceFromSegment < 0.001f) {
            break;
        }
        sp88.pos.x = CROSS_X(&sp88.segmentDisplacement, &sp88.segmentForward);
        sp88.pos.y = CROSS_Y(&sp88.segmentDisplacement, &sp88.segmentForward);
        sp88.pos.z = CROSS_Z(&sp88.segmentDisplacement, &sp88.segmentForward);

        sp88.segmentDisplacement.x = CROSS_X(&sp88.segmentForward, &sp88.pos);
        sp88.segmentDisplacement.y = CROSS_Y(&sp88.segmentForward, &sp88.pos);
        sp88.segmentDisplacement.z = CROSS_Z(&sp88.segmentForward, &sp88.pos);

        temp_fv1 = sp88.distanceFromSegment / sqrtf(SQ_SUM(&sp88.segmentDisplacement));
        sp130.x = arg1 - ((sp88.segmentDisplacement.x * temp_fv1) + sp88.segmentPos.x);
        sp130.y = arg2 - ((sp88.segmentDisplacement.y * temp_fv1) + sp88.segmentPos.y);
        sp130.z = arg3 - ((sp88.segmentDisplacement.z * temp_fv1) + sp88.segmentPos.z);
    }

    var_s1_2 = sp88.courseSegment;
    var_v0 = var_s1_2->next;
    var_v1 = var_s1_2->prev;
    var_a0 = var_v0->next;

    tSquare = SQ(sp88.segmentTValue);

    tension = var_s1_2->tension;
    temp_fa0 = (((4.0f * sp88.segmentTValue) - 1.0f) - 3.0f * tSquare) * tension;
    temp_fa1 = ((6.0f - 3.0f * tension) * tSquare) + (((2.0f * tension) - 6.0f) * sp88.segmentTValue);
    temp_ft4 = ((3.0f * tension - 6.0f) * tSquare) + ((6.0f - (4.0f * tension)) * sp88.segmentTValue) + tension;
    spE8 = (3.0f * tSquare - (2.0f * sp88.segmentTValue)) * tension;

    arg4->x.x =
        (temp_fa0 * var_v1->pos.x) + (temp_fa1 * var_s1_2->pos.x) + (temp_ft4 * var_v0->pos.x) + (spE8 * var_a0->pos.x);
    arg4->x.y =
        (temp_fa0 * var_v1->pos.y) + (temp_fa1 * var_s1_2->pos.y) + (temp_ft4 * var_v0->pos.y) + (spE8 * var_a0->pos.y);
    arg4->x.z =
        (temp_fa0 * var_v1->pos.z) + (temp_fa1 * var_s1_2->pos.z) + (temp_ft4 * var_v0->pos.z) + (spE8 * var_a0->pos.z);

    temp_fv1 = 1.0f / sqrtf(SQ_SUM(&arg4->x));
    arg4->x.x *= temp_fv1;
    arg4->x.y *= temp_fv1;
    arg4->x.z *= temp_fv1;

    arg4->y.x = ((var_s1_2->next->up.x - var_s1_2->up.x) * sp88.segmentTValue) + var_s1_2->up.x;
    arg4->y.y = ((var_s1_2->next->up.y - var_s1_2->up.y) * sp88.segmentTValue) + var_s1_2->up.y;
    arg4->y.z = ((var_s1_2->next->up.z - var_s1_2->up.z) * sp88.segmentTValue) + var_s1_2->up.z;

    arg4->z.x = CROSS_X(&arg4->y, &arg4->x);
    arg4->z.y = CROSS_Y(&arg4->y, &arg4->x);
    arg4->z.z = CROSS_Z(&arg4->y, &arg4->x);
    temp_fv1 = 1.0f / sqrtf(SQ_SUM(&arg4->z));
    arg4->z.x *= temp_fv1;
    arg4->z.y *= temp_fv1;
    arg4->z.z *= temp_fv1;
    return 0;
}

#ifdef NON_EQUIVALENT
// Weird float/double calculations
void func_8009DB28(CourseSegment* segment, f32* arg1, f32* arg2) {
    f64 temp_ft5;
    f64 temp_fs0;
    f64 temp_fs1;
    f64 temp_fs2;
    f64 temp_fs3;
    f64 temp_fs4;
    f64 spB0;
    f64 spA8;
    f64 sp60;
    f64 sp58;
    f64 sp48;
    f64 temp_fv0_5;
    f64 temp_fa0_3;
    f64 temp_fa1_3;
    f64 temp_ft5_2;
    f64 temp_fv0_6;
    f64 temp_ft4;
    CourseSegment* prevSegment = segment->prev;
    CourseSegment* nextSegment = segment->next;
    CourseSegment* nextNextSegment = nextSegment->next;

    temp_ft5 = segment->pos.x - nextSegment->pos.x;
    temp_fs2 = prevSegment->pos.x - nextNextSegment->pos.x + temp_ft5;
    temp_fs0 = segment->pos.y - nextSegment->pos.y;
    temp_fs3 = prevSegment->pos.y - nextNextSegment->pos.y + temp_fs0;
    temp_fs1 = segment->pos.z - nextSegment->pos.z;
    temp_fs4 = prevSegment->pos.z - nextNextSegment->pos.z + temp_fs1;

    sp58 = ((temp_ft5 * temp_fs2) + (temp_fs0 * temp_fs3) + (temp_fs1 * temp_fs4)) * 0.75;
    spB0 = SQ(sp58);
    spA8 = (SQ(temp_ft5) + SQ(temp_fs0) + SQ(temp_fs1)) * 9.0;

    temp_fv0_5 = nextSegment->pos.x - prevSegment->pos.x;
    temp_fa0_3 = nextSegment->pos.y - prevSegment->pos.y;
    temp_fa1_3 = nextSegment->pos.z - prevSegment->pos.z;
    sp60 = (SQ(temp_fs2) + SQ(temp_fs3) + SQ(temp_fs4)) * 0.0625;
    sp48 = sp60 - SQ(temp_fv0_5) - SQ(temp_fa0_3) - SQ(temp_fa1_3);
    temp_ft5_2 = sp48 * spA8;

    if (temp_ft5_2 <= spB0) {
        temp_fv0_6 = sqrtf(spB0 - temp_ft5_2);
        temp_ft4 = 2.0 * sp48;
        if (temp_ft4 < -0.1) {
            *arg1 = (sp58 - temp_fv0_6) / temp_ft4;
        } else if (temp_ft4 > 0.1) {
            *arg1 = (sp58 + temp_fv0_6) / temp_ft4;
        } else {
            *arg1 = -1.0f;
        }
    } else {
        *arg1 = -1.0f;
    }

    temp_fv0_5 = nextNextSegment->pos.x - segment->pos.x;
    temp_fa0_3 = nextNextSegment->pos.y - segment->pos.y;
    temp_fa1_3 = nextNextSegment->pos.z - segment->pos.z;
    sp48 = sp60 - SQ(temp_fv0_5) - SQ(temp_fa0_3) - SQ(temp_fa1_3);
    temp_ft5_2 = sp48 * spA8;
    if (temp_ft5_2 <= spB0) {
        temp_fv0_6 = sqrtf(spB0 - temp_ft5_2);
        temp_ft4 = 2.0 * sp48;
        if (temp_ft4 < -0.1) {
            *arg2 = (sp58 - temp_fv0_6) / temp_ft4;
        } else if (temp_ft4 > 0.1) {
            *arg2 = (sp58 + temp_fv0_6) / temp_ft4;
        } else {
            *arg2 = -1.0f;
        }
    } else {
        *arg2 = -1.0f;
    }
}
#else
void func_8009DB28(CourseSegment*, f32*, f32*);
#ifndef EXPANSION_KIT
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/game/course/func_8009DB28.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/course/func_8009DB28.s")
#endif
#endif
#endif

s32 Course_SplineCalculateTensions(CourseInfo* courseInfo) {
    f32 alpha1;
    f32 alpha2;
    CourseSegment* segment = courseInfo->courseSegments;

    do {
        func_8009DB28(segment, &alpha1, &alpha2);
        if ((alpha1 < 0.0f) || (alpha1 > 2.0f) || (alpha2 < 0.0f) || (alpha2 > 2.0f)) {
            return -1;
        }
        segment->tension = (alpha1 + alpha2) * 0.5f;
        segment = segment->next;
    } while (segment != courseInfo->courseSegments);

    return 0;
}

// Get Rough Racer Lap Distance
f32 func_8009DFA0(RacerSegmentPositionInfo* arg0) {
    f32 length;
    Vec3f posDiff;

    if (arg0->segmentTValue < 0.5f) {
        if (arg0->segmentTValue < 0.25f) {
            length = 0.0f;
            posDiff.x = arg0->segmentPos.x - arg0->courseSegment->pos.x;
            posDiff.y = arg0->segmentPos.y - arg0->courseSegment->pos.y;
            posDiff.z = arg0->segmentPos.z - arg0->courseSegment->pos.z;
        } else {
            length = arg0->courseSegment->quarterMarkLength;
            posDiff.x = arg0->segmentPos.x - arg0->courseSegment->quarterMarkPos.x;
            posDiff.y = arg0->segmentPos.y - arg0->courseSegment->quarterMarkPos.y;
            posDiff.z = arg0->segmentPos.z - arg0->courseSegment->quarterMarkPos.z;
        }
    } else if (arg0->segmentTValue < 0.75f) {
        length = arg0->courseSegment->halfMarkLength;
        posDiff.x = arg0->segmentPos.x - arg0->courseSegment->halfMarkPos.x;
        posDiff.y = arg0->segmentPos.y - arg0->courseSegment->halfMarkPos.y;
        posDiff.z = arg0->segmentPos.z - arg0->courseSegment->halfMarkPos.z;
    } else {
        length = arg0->courseSegment->threeQuarterMarkLength;
        posDiff.x = arg0->segmentPos.x - arg0->courseSegment->threeQuarterMarkPos.x;
        posDiff.y = arg0->segmentPos.y - arg0->courseSegment->threeQuarterMarkPos.y;
        posDiff.z = arg0->segmentPos.z - arg0->courseSegment->threeQuarterMarkPos.z;
    }

    length += sqrtf(SQ(posDiff.x) + SQ(posDiff.y) + SQ(posDiff.z));
    arg0->segmentLengthProportion = length / arg0->courseSegment->length;
    return arg0->courseSegment->lengthFromStart + length;
}

// Get Length Into Course Segment
// Returns Length proportion along the track
f32 Course_SplineGetLengthInfo(CourseSegment* segment, f32 targetT, f32* lengthFromStart) {
    f32 tension;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 t;
    f32 temp_fs2;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 tSquare;
    f32 tCube;
    f32 tEnd;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 spA4;
    Vec3f sp98;
    Vec3f sp8C;
    CourseSegment* nextSegment = segment->next;
    CourseSegment* prevSegment = segment->prev;
    CourseSegment* nextNextSegment = nextSegment->next;

    tension = segment->tension;
    spD8 = tension - 2.0f;
    spD4 = tension - 3.0f;
    spD0 = 3.0f - (2.0f * tension);
    *lengthFromStart = 0.0f;
    if (targetT < 0.5f) {
        t = 0.0f;
        tEnd = targetT;
    } else {
        t = targetT;
        tEnd = 1.0f;
    }

    tSquare = SQ(t);
    tCube = tSquare * t;
    temp_fa0 = (2.0f * tSquare - t - tCube) * tension;
    temp_fa1 = spD4 * tSquare - spD8 * tCube + 1.0f;
    temp_ft4 = spD8 * tCube + spD0 * tSquare + tension * t;
    spA4 = (tCube - tSquare) * tension;

    sp98.x = temp_fa0 * prevSegment->pos.x + temp_fa1 * segment->pos.x + temp_ft4 * nextSegment->pos.x +
             spA4 * nextNextSegment->pos.x;
    sp98.y = temp_fa0 * prevSegment->pos.y + temp_fa1 * segment->pos.y + temp_ft4 * nextSegment->pos.y +
             spA4 * nextNextSegment->pos.y;
    sp98.z = temp_fa0 * prevSegment->pos.z + temp_fa1 * segment->pos.z + temp_ft4 * nextSegment->pos.z +
             spA4 * nextNextSegment->pos.z;

    while (t < tEnd) {
        t += 0.05f;
        if (tEnd < t) {
            t = tEnd;
        }

        tSquare = SQ(t);
        tCube = tSquare * t;
        temp_fa0 = (2.0f * tSquare - t - tCube) * tension;
        temp_fa1 = spD4 * tSquare - spD8 * tCube + 1.0f;
        temp_ft4 = spD8 * tCube + spD0 * tSquare + tension * t;
        spA4 = (tCube - tSquare) * tension;

        sp8C.x = (prevSegment->pos.x * temp_fa0) + (temp_fa1 * segment->pos.x) + (temp_ft4 * nextSegment->pos.x) +
                 (spA4 * nextNextSegment->pos.x);
        temp_fs2 = sp8C.x - sp98.x;
        sp8C.y = (prevSegment->pos.y * temp_fa0) + (temp_fa1 * segment->pos.y) + (temp_ft4 * nextSegment->pos.y) +
                 (spA4 * nextNextSegment->pos.y);
        temp_fv0 = sp8C.y - sp98.y;
        sp8C.z = (prevSegment->pos.z * temp_fa0) + (temp_fa1 * segment->pos.z) + (temp_ft4 * nextSegment->pos.z) +
                 (spA4 * nextNextSegment->pos.z);
        temp_fv1 = sp8C.z - sp98.z;

        *lengthFromStart += sqrtf(SQ(temp_fs2) + SQ(temp_fv0) + SQ(temp_fv1));

        sp98 = sp8C;
    }

    if (targetT >= 0.5f) {
        *lengthFromStart = segment->length - *lengthFromStart;
    }

    t = *lengthFromStart / segment->length;
    if (t < 0.0f) {
        t = 0.0f;
    } else if (t > 1.0f) {
        t = 1.0f;
    }
    *lengthFromStart += segment->lengthFromStart;
    return t;
}

// Get un-normalised tangent vector along course segment (and magnitude)
f32 Course_SplineGetTangent(CourseSegment* segment, f32 t, Vec3f* tangentVec) {
    f32 tSquare;
    f32 tension;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    CourseSegment* nextSegment = segment->next;
    CourseSegment* prevSegment = segment->prev;
    CourseSegment* nextNextSegment = nextSegment->next;

    tSquare = SQ(t);
    tension = segment->tension;

    sp44 = (4.0f * t - 1.0f - (3.0f * tSquare)) * tension;
    sp40 = (6.0f - 3.0f * tension) * tSquare + (2.0f * tension - 6.0f) * t;
    sp3C = (3.0f * tension - 6.0f) * tSquare + (6.0f - 4.0f * tension) * t + tension;
    sp38 = ((3.0f * tSquare) - 2.0f * t) * tension;

    tangentVec->x =
        sp44 * prevSegment->pos.x + sp40 * segment->pos.x + sp3C * nextSegment->pos.x + sp38 * nextNextSegment->pos.x;
    tangentVec->y =
        sp44 * prevSegment->pos.y + sp40 * segment->pos.y + sp3C * nextSegment->pos.y + sp38 * nextNextSegment->pos.y;
    tangentVec->z =
        sp44 * prevSegment->pos.z + sp40 * segment->pos.z + sp3C * nextSegment->pos.z + sp38 * nextNextSegment->pos.z;

    return sqrtf(SQ(tangentVec->x) + SQ(tangentVec->y) + SQ(tangentVec->z));
}

// Get position along course segment
void Course_SplineGetPosition(CourseSegment* segment, f32 t, Vec3f* pos) {
    f32 tension;
    f32 tSquare;
    f32 tCube;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    CourseSegment* prevSegment = segment->prev;
    CourseSegment* nextSegment = segment->next;
    CourseSegment* nextNextSegment = nextSegment->next;

    tension = segment->tension;
    tSquare = SQ(t);
    tCube = tSquare * t;
    sp30 = (2.0f * tSquare - t - tCube) * tension;
    sp2C = (2.0f - tension) * tCube + (tension - 3.0f) * tSquare + 1.0f;
    sp28 = (tension - 2.0f) * tCube + (3.0f - 2.0f * tension) * tSquare + tension * t;
    sp24 = (tCube - tSquare) * tension;

    pos->x =
        sp30 * prevSegment->pos.x + sp2C * segment->pos.x + sp28 * nextSegment->pos.x + sp24 * nextNextSegment->pos.x;
    pos->y =
        sp30 * prevSegment->pos.y + sp2C * segment->pos.y + sp28 * nextSegment->pos.y + sp24 * nextNextSegment->pos.y;
    pos->z =
        sp30 * prevSegment->pos.z + sp2C * segment->pos.z + sp28 * nextSegment->pos.z + sp24 * nextNextSegment->pos.z;
}

// Get segment basis matrix (forward = tangent vector, up = up, left-right = horizontal road slope vector)
// NOTE: z vector is positive in the left direction!
// Returns magnitude of tangent
f32 Course_SplineGetBasis(CourseSegment* segment, f32 t, Mtx3F* basis, f32 lengthProportionAlongSegment) {
    f32 tension;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    CourseSegment* nextSegment = segment->next;
    CourseSegment* prevSegment = segment->prev;
    CourseSegment* nextNextSegment = nextSegment->next;

    tension = segment->tension;
    sp50 = SQ(t);
    sp4C = (4.0f * t - 1.0f - 3.0f * sp50) * tension;
    sp48 = (6.0f - 3.0f * tension) * sp50 + (2.0f * tension - 6.0f) * t;
    sp44 = (3.0f * tension - 6.0f) * sp50 + (6.0f - 4.0f * tension) * t + tension;
    sp40 = (3.0f * sp50 - 2.0f * t) * tension;

    basis->x.x =
        sp4C * prevSegment->pos.x + sp48 * segment->pos.x + sp44 * nextSegment->pos.x + sp40 * nextNextSegment->pos.x;
    basis->x.y =
        sp4C * prevSegment->pos.y + sp48 * segment->pos.y + sp44 * nextSegment->pos.y + sp40 * nextNextSegment->pos.y;
    basis->x.z =
        sp4C * prevSegment->pos.z + sp48 * segment->pos.z + sp44 * nextSegment->pos.z + sp40 * nextNextSegment->pos.z;

    sp50 = sqrtf(SQ(basis->x.x) + SQ(basis->x.y) + SQ(basis->x.z));
    tension = 1.0f / sp50;

    basis->x.x *= tension;
    basis->x.y *= tension;
    basis->x.z *= tension;

    basis->y.x = (segment->next->up.x - segment->up.x) * lengthProportionAlongSegment + segment->up.x;
    basis->y.y = (segment->next->up.y - segment->up.y) * lengthProportionAlongSegment + segment->up.y;
    basis->y.z = (segment->next->up.z - segment->up.z) * lengthProportionAlongSegment + segment->up.z;

    basis->z.x = basis->y.y * basis->x.z - basis->y.z * basis->x.y;
    basis->z.y = basis->y.z * basis->x.x - basis->y.x * basis->x.z;
    basis->z.z = basis->y.x * basis->x.y - basis->y.y * basis->x.x;

    tension = 1.0f / sqrtf(SQ(basis->z.x) + SQ(basis->z.y) + SQ(basis->z.z));

    basis->z.x *= tension;
    basis->z.y *= tension;
    basis->z.z *= tension;

    basis->y.x = basis->x.y * basis->z.z - basis->x.z * basis->z.y;
    basis->y.y = basis->x.z * basis->z.x - basis->x.x * basis->z.z;
    basis->y.z = basis->x.x * basis->z.y - basis->x.y * basis->z.x;

    return sp50;
}

s32 func_8009EBEC(RacerSegmentPositionInfo* arg0, f32 xPos, f32 yPos, f32 zPos, s32 i, f32 arg5) {
    s32 pad2;
    Vec3f spD0;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 pad;
    f32 temp_fa0;
    f32 tension;
    f32 var_fs5;
    f32 tSquare;
    f32 tCube;
    CourseSegment* prevSegment;
    CourseSegment* nextNextSegment;
    CourseSegment* segment;
    CourseSegment* nextSegment;

    spD0.x = xPos - arg0->lastGroundedPos.x;
    spD0.y = yPos - arg0->lastGroundedPos.y;
    spD0.z = zPos - arg0->lastGroundedPos.z;

    segment = arg0->courseSegment;
    nextSegment = segment->next;
    prevSegment = segment->prev;
    nextNextSegment = nextSegment->next;

    tension = segment->tension;
    var_fs5 = tension - 2.0f;

    spBC = ((var_fs5 - 1.0f) + tension) - 3.0f;
    spB8 = spBC + tension;
    spB4 = spB8 + tension;

    while ((arg5 < (SQ_SUM(&spD0))) && (--i != 0)) {

        arg0->segmentTValue += DOT_XYZ(&spD0, &arg0->segmentForward) / SQ(arg0->segmentForwardMagnitude);

        if (arg0->segmentTValue >= 1.0f) {
            if (arg0->segmentTValue > 1.9f) {
                return -1;
            }
            arg0->courseSegment = arg0->courseSegment->next;
            prevSegment = segment;
            segment = nextSegment;
            nextSegment = nextNextSegment;
            nextNextSegment = arg0->courseSegment->next->next;
            tension = arg0->courseSegment->tension;

            var_fs5 = tension - 2.0f;

            spBC = ((var_fs5 - 1.0f) + tension) - 3.0f;
            spB8 = spBC + tension;
            spB4 = spB8 + tension;

            arg0->segmentTValue -= 1.0f;

            arg0->segmentTValue *=
                arg0->segmentForwardMagnitude / Course_SplineGetTangent(arg0->courseSegment, 0.0f, &spD0);
        } else if (arg0->segmentTValue < 0.0f) {
            if (arg0->segmentTValue < -0.9f) {
                return -1;
            }
            arg0->courseSegment = arg0->courseSegment->prev;
            nextNextSegment = nextSegment;
            nextSegment = segment;
            segment = prevSegment;
            prevSegment = arg0->courseSegment->prev;
            tension = arg0->courseSegment->tension;

            var_fs5 = tension - 2.0f;

            spBC = ((var_fs5 - 1.0f) + tension) - 3.0f;
            spB8 = spBC + tension;
            spB4 = spB8 + tension;

            arg0->segmentTValue *=
                arg0->segmentForwardMagnitude / Course_SplineGetTangent(arg0->courseSegment, 1.0f, &spD0);
            arg0->segmentTValue += 1.0f;
        }

        tCube = tSquare = SQ(arg0->segmentTValue);
        tCube *= arg0->segmentTValue;

        temp_ft4 = ((2.0f * tSquare) - arg0->segmentTValue - tCube) * tension;
        temp_ft5 = (((var_fs5 - 1.0f) * tSquare) - var_fs5 * tCube) + 1.0f;
        temp_fs1 = (var_fs5 * tCube - (((var_fs5 - 1.0f) + tension) * tSquare)) + (tension * arg0->segmentTValue);
        temp_fs2 = (tCube - tSquare) * tension;

        arg0->segmentPos.x = (temp_ft4 * prevSegment->pos.x) + (temp_ft5 * segment->pos.x) +
                             (temp_fs1 * nextSegment->pos.x) + (temp_fs2 * nextNextSegment->pos.x);
        arg0->segmentPos.y = (temp_ft4 * prevSegment->pos.y) + (temp_ft5 * segment->pos.y) +
                             (temp_fs1 * nextSegment->pos.y) + (temp_fs2 * nextNextSegment->pos.y);
        arg0->segmentPos.z = (temp_ft4 * prevSegment->pos.z) + (temp_ft5 * segment->pos.z) +
                             (temp_fs1 * nextSegment->pos.z) + (temp_fs2 * nextNextSegment->pos.z);

        temp_ft4 = (((arg0->segmentTValue * 4.0f) - 1.0f) - (3.0f * tSquare)) * tension;
        temp_ft5 = (arg0->segmentTValue * spBC) - spB8 * tSquare;
        temp_fs1 = (spB8 * tSquare - (spB4 * arg0->segmentTValue)) + tension;
        temp_fs2 = ((3.0f * tSquare) - (2.0f * arg0->segmentTValue)) * tension;

        arg0->segmentForward.x = (temp_ft4 * prevSegment->pos.x) + (temp_ft5 * segment->pos.x) +
                                 (temp_fs1 * nextSegment->pos.x) + (temp_fs2 * nextNextSegment->pos.x);
        arg0->segmentForward.y = (temp_ft4 * prevSegment->pos.y) + (temp_ft5 * segment->pos.y) +
                                 (temp_fs1 * nextSegment->pos.y) + (temp_fs2 * nextNextSegment->pos.y);
        arg0->segmentForward.z = (temp_ft4 * prevSegment->pos.z) + (temp_ft5 * segment->pos.z) +
                                 (temp_fs1 * nextSegment->pos.z) + (temp_fs2 * nextNextSegment->pos.z);

        arg0->segmentForwardMagnitude = sqrtf(SQ_SUM(&arg0->segmentForward));
        arg0->segmentDisplacement.x = xPos - arg0->segmentPos.x;
        arg0->segmentDisplacement.y = yPos - arg0->segmentPos.y;
        arg0->segmentDisplacement.z = zPos - arg0->segmentPos.z;
        arg0->distanceFromSegment = sqrtf(SQ_SUM(&arg0->segmentDisplacement));

        if (arg0->distanceFromSegment < 0.001f) {
            break;
        }

        arg0->pos.x = CROSS_X(&arg0->segmentDisplacement, &arg0->segmentForward);
        arg0->pos.y = CROSS_Y(&arg0->segmentDisplacement, &arg0->segmentForward);
        arg0->pos.z = CROSS_Z(&arg0->segmentDisplacement, &arg0->segmentForward);

        arg0->segmentDisplacement.x = CROSS_X(&arg0->segmentForward, &arg0->pos);
        arg0->segmentDisplacement.y = CROSS_Y(&arg0->segmentForward, &arg0->pos);
        arg0->segmentDisplacement.z = CROSS_Z(&arg0->segmentForward, &arg0->pos);

        temp_fa0 = arg0->distanceFromSegment / sqrtf(SQ_SUM(&arg0->segmentDisplacement));

        arg0->segmentDisplacement.x *= temp_fa0;
        arg0->lastGroundedPos.x = pad = arg0->segmentDisplacement.x + arg0->segmentPos.x;
        spD0.x = xPos - arg0->lastGroundedPos.x;

        arg0->segmentDisplacement.y *= temp_fa0;
        arg0->lastGroundedPos.y = pad = arg0->segmentDisplacement.y + arg0->segmentPos.y;
        spD0.y = yPos - arg0->lastGroundedPos.y;

        arg0->segmentDisplacement.z *= temp_fa0;
        arg0->lastGroundedPos.z = pad = arg0->segmentDisplacement.z + arg0->segmentPos.z;
        spD0.z = zPos - arg0->lastGroundedPos.z;
    }

    arg0->segmentDisplacement.x = xPos - arg0->segmentPos.x;
    arg0->segmentDisplacement.y = yPos - arg0->segmentPos.y;
    arg0->segmentDisplacement.z = zPos - arg0->segmentPos.z;

    arg0->pos.x = xPos;
    arg0->pos.y = yPos;
    arg0->pos.z = zPos;
    arg0->distanceFromSegment = sqrtf(SQ_SUM(&arg0->segmentDisplacement));

    return 0;
}

s32 func_8009F334(CourseInfo* courseInfo) {
    CourseSegment* segment = courseInfo->courseSegments;
    Mtx3F sp30;

    do {
        sp30.y.x = segment->up.x;
        sp30.y.y = segment->up.y;
        sp30.y.z = segment->up.z;
        Course_SplineGetTangent(segment, 0.0f, &sp30.x);
        if (Math_OrthonormalizeAroundForward(&sp30) != 0) {
            return -1;
        }
        segment->up.x = sp30.y.x;
        segment->up.y = sp30.y.y;
        segment->up.z = sp30.y.z;
        segment = segment->next;
    } while (segment != courseInfo->courseSegments);

    return 0;
}

s32 Course_SegmentJoinsInit(CourseInfo* courseInfo) {
    s32 var_v1 = 0;
    CourseSegment* segment = courseInfo->courseSegments;

    do {
        segment->trackSegmentInfo &= ~TRACK_JOIN_MASK;
        if (segment->trackSegmentInfo & TRACK_FLAG_JOINABLE) {
            continue;
        }

        if (segment->prev->trackSegmentInfo & TRACK_FLAG_JOINABLE) {
            segment->trackSegmentInfo |= TRACK_JOIN_PREVIOUS;
        }

        if (segment->next->trackSegmentInfo & TRACK_FLAG_JOINABLE) {
            segment->trackSegmentInfo |= TRACK_JOIN_NEXT;
        }

        switch (segment->trackSegmentInfo & TRACK_JOIN_MASK) {
            case TRACK_JOIN_PREVIOUS:
            case TRACK_JOIN_NEXT:
                if (segment->length <=
                    (gTrackJoinUpperLength[TRACK_SHAPE_INDEX((u32) segment->trackSegmentInfo & TRACK_SHAPE_MASK)] +
                     100.0f)) {
                    var_v1 = -1;
                }
                break;
            case TRACK_JOIN_BOTH:
                if (segment->length <=
                    ((2.0f *
                      gTrackJoinUpperLength[TRACK_SHAPE_INDEX((u32) segment->trackSegmentInfo & TRACK_SHAPE_MASK)]) +
                     100.0f)) {
                    var_v1 = -1;
                }
                break;
            default:
                break;
        }

    } while ((segment = segment->next) != courseInfo->courseSegments);

    return var_v1;
}

void Course_SegmentLengthsInit(CourseInfo* courseInfo) {
    CourseSegment* segment = courseInfo->courseSegments;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 cube;
    f32 square;
    f32 temp_fv1;
    f32 temp_fa1;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fv0;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    Vec3f sp9C;
    Vec3f sp90;
    s32 i;

    courseInfo->length = 0.0f;
    do {
        f32 tension = segment->tension;
        CourseSegment* nextSegment = segment->next;
        CourseSegment* prevSegment = segment->prev;
        CourseSegment* nextNextSegment = nextSegment->next;

        spD8 = tension - 2.0f;
        spD4 = tension - 3.0f;
        spD0 = 3.0f - (2.0f * tension);

        sp9C = segment->pos;
        segment->length = 0.0f;

        for (i = 1; i <= 50; i++) {
            temp_fv1 = (f32) i / 50.0f;
            square = SQ(temp_fv1);
            cube = square * temp_fv1;
            temp_fa1 = (2.0f * square - temp_fv1 - cube) * tension;
            spB0 = (spD4 * square - spD8 * cube) + 1.0f;
            spAC = spD8 * cube + spD0 * square + tension * temp_fv1;
            spA8 = (cube - square) * tension;

            sp90.x = temp_fa1 * prevSegment->pos.x + spB0 * segment->pos.x + spAC * nextSegment->pos.x +
                     spA8 * nextNextSegment->pos.x;
            temp_fs3 = sp90.x - sp9C.x;
            sp90.y = temp_fa1 * prevSegment->pos.y + spB0 * segment->pos.y + spAC * nextSegment->pos.y +
                     spA8 * nextNextSegment->pos.y;
            temp_fs4 = sp90.y - sp9C.y;
            sp90.z = temp_fa1 * prevSegment->pos.z + spB0 * segment->pos.z + spAC * nextSegment->pos.z +
                     spA8 * nextNextSegment->pos.z;
            temp_fv0 = sp90.z - sp9C.z;

            segment->length += sqrtf(SQ(temp_fs3) + SQ(temp_fs4) + SQ(temp_fv0));
            sp9C = sp90;
        }

        courseInfo->length += segment->length;
        segment = nextSegment;
        segment->lengthFromStart = courseInfo->length;
    } while (segment != courseInfo->courseSegments);
    courseInfo->courseSegments->lengthFromStart = 0.0f;
    segment = courseInfo->courseSegments;
    do {
        Course_SplineGetPosition(segment, 0.25f, &segment->quarterMarkPos);
        Course_SplineGetPosition(segment, 0.5f, &segment->halfMarkPos);
        Course_SplineGetPosition(segment, 0.75f, &segment->threeQuarterMarkPos);
        Course_SplineGetLengthInfo(segment, 0.25f, &segment->quarterMarkLength);
        segment->quarterMarkLength -= segment->lengthFromStart;
        Course_SplineGetLengthInfo(segment, 0.5f, &segment->halfMarkLength);
        segment->halfMarkLength -= segment->lengthFromStart;
        Course_SplineGetLengthInfo(segment, 0.75f, &segment->threeQuarterMarkLength);
        segment->threeQuarterMarkLength -= segment->lengthFromStart;
        segment = segment->next;
    } while (segment != courseInfo->courseSegments);
}

f32 func_8009F87C(Mtx3F* arg0, Mtx3F* arg1, Vec3f* arg2, Vec3f* arg3) {
    f32 temp_v1;
    Vec3fFlip sp80;
    Vec3fFlip sp74;
    Vec3fFlip sp68;

    sp80.x = arg0->y.x + arg1->y.x;
    sp80.y = arg0->y.y + arg1->y.y;
    sp80.z = arg0->y.z + arg1->y.z;

    // normalize sp80
    if (SQ_SUM(&sp80) < 0.1f) {
        return 0.0f;
    }
    temp_v1 = 1.0f / sqrtf(SQ_SUM(&sp80));
    sp80.x *= temp_v1;
    sp80.y *= temp_v1;
    sp80.z *= temp_v1;

    // MAG(arg0->x()) * cos
    temp_v1 = DOT_XYZ(&arg0->x, &sp80);

    sp68.x = arg0->x.x - temp_v1 * sp80.x;
    sp68.y = arg0->x.y - temp_v1 * sp80.y;
    sp68.z = arg0->x.z - temp_v1 * sp80.z;

    // FAKE (Compiler Stack)
    goto dummy_label;
dummy_label:;

    // normalize sp68
    if (SQ_SUM(&sp68) < 0.1f) {
        return 0.0f;
    }
    temp_v1 = 1.0f / sqrtf(SQ_SUM(&sp68));
    sp68.x *= temp_v1;
    sp68.y *= temp_v1;
    sp68.z *= temp_v1;

    // Perpendicular and normalized vector to sp80/sp68
    sp74.x = CROSS_X(&sp80, &sp68);
    sp74.y = CROSS_Y(&sp80, &sp68);
    sp74.z = CROSS_Z(&sp80, &sp68);

    temp_v1 = DOT_XYZ(&arg1->x, &sp80);

    sp68.x = arg1->x.x - temp_v1 * sp80.x;
    sp68.y = arg1->x.y - temp_v1 * sp80.y;
    sp68.z = arg1->x.z - temp_v1 * sp80.z;

    // normalize sp68
    if (SQ_SUM(&sp68) < 0.1f) {
        return 0.0f;
    }
    temp_v1 = 1.0f / sqrtf(SQ_SUM(&sp68));
    sp68.x *= temp_v1;
    sp68.y *= temp_v1;
    sp68.z *= temp_v1;

    temp_v1 = DOT_XYZ(&sp74, &sp68);
    if ((temp_v1 < 0.1f) && (temp_v1 > -0.1f)) {
        return 0.0f;
    }

    // sp68 . (arg3 - arg2)
    temp_v1 = DIST_DOT_XYZ(&sp68, arg3, arg2) / temp_v1;

    sp80.x = sp74.x * temp_v1 + arg2->x;
    sp80.y = sp74.y * temp_v1 + arg2->y;
    sp80.z = sp74.z * temp_v1 + arg2->z;

    sp74.x = arg2->x - sp80.x;
    sp74.y = arg2->y - sp80.y;
    sp74.z = arg2->z - sp80.z;

    sp68.x = arg3->x - sp80.x;
    sp68.y = arg3->y - sp80.y;
    sp68.z = arg3->z - sp80.z;

    return (sqrtf(SQ_SUM(&sp74)) + sqrtf(SQ_SUM(&sp68))) / 2.0f;
}

void Course_SegmentFormsInit(CourseInfo* courseInfo) {
    CourseSegment* segment = courseInfo->courseSegments;
    Mtx3F segmentStartBasis;
    Mtx3F segmentMidpointBasis;
    Mtx3F segmentEndBasis;
    Vec3f segmentStartPos;
    Vec3f segmentMidpointPos;
    Vec3f segmentEndPos;
    Vec3fFlip sp98;
    Vec3fFlip sp8C;
    f32 sp88;
    f32 sp7C;
    f32 temp_fs0;
    f32 temp_ft3;
    f32 temp_fv0;

    do {
        segment->trackSegmentInfo &= ~TRACK_FORM_MASK;
        Course_SplineGetBasis(segment, 0.0f, &segmentStartBasis, 0.0f);
        Course_SplineGetBasis(segment, 0.5f, &segmentMidpointBasis, 0.5f);
        Course_SplineGetBasis(segment, 1.0f, &segmentEndBasis, 1.0f);
        sp98.x = CROSS_X(&segmentStartBasis.x, &segmentMidpointBasis.x);
        sp98.y = CROSS_Y(&segmentStartBasis.x, &segmentMidpointBasis.x);
        sp98.z = CROSS_Z(&segmentStartBasis.x, &segmentMidpointBasis.x);
        sp8C.x = CROSS_X(&segmentMidpointBasis.x, &segmentEndBasis.x);
        sp8C.y = CROSS_Y(&segmentMidpointBasis.x, &segmentEndBasis.x);
        sp8C.z = CROSS_Z(&segmentMidpointBasis.x, &segmentEndBasis.x);
        sp88 = DOT_XYZ(&sp98, &segmentMidpointBasis.y);
        sp7C = DOT_XYZ(&sp8C, &segmentMidpointBasis.y);
        Course_SplineGetPosition(segment, 0.0f, &segmentStartPos);
        Course_SplineGetPosition(segment, 0.5f, &segmentMidpointPos);
        Course_SplineGetPosition(segment, 1.0f, &segmentEndPos);
        temp_fs0 = func_8009F87C(&segmentStartBasis, &segmentMidpointBasis, &segmentStartPos, &segmentMidpointPos);
        temp_fv0 = func_8009F87C(&segmentMidpointBasis, &segmentEndBasis, &segmentMidpointPos, &segmentEndPos);
        if (temp_fs0 != 0.0f) {
            if (temp_fv0 != 0.0f) {
                if (temp_fs0 < temp_fv0) {
                    segment->unk_64 = temp_fs0;
                } else {
                    segment->unk_64 = temp_fv0;
                }
                if (sp88 < 0.0f) {
                    if (sp7C < 0.0f) {
                        segment->trackSegmentInfo |= TRACK_FORM_RIGHT;
                    } else {
                        segment->trackSegmentInfo |= TRACK_FORM_S_FLIPPED;
                    }
                } else if (sp7C < 0.0f) {
                    segment->trackSegmentInfo |= TRACK_FORM_S;
                } else {
                    segment->trackSegmentInfo |= TRACK_FORM_LEFT;
                }
            } else {
                segment->unk_64 = temp_fs0;
                if (sp88 < 0.0f) {
                    segment->trackSegmentInfo |= TRACK_FORM_RIGHT;
                } else {
                    segment->trackSegmentInfo |= TRACK_FORM_LEFT;
                }
            }
        } else if (temp_fv0 != 0.0f) {
            segment->unk_64 = temp_fv0;
            if (sp7C < 0.0f) {
                segment->trackSegmentInfo |= TRACK_FORM_RIGHT;
            } else {
                segment->trackSegmentInfo |= TRACK_FORM_LEFT;
            }
        } else {
            segment->unk_64 = 0.0f;
            segment->trackSegmentInfo |= TRACK_FORM_STRAIGHT;
        }
        segment = segment->next;
    } while (segment != courseInfo->courseSegments);
}

void Course_SegmentContinuousFlagInit(CourseInfo* courseInfo) {
    CourseSegment* segment = courseInfo->courseSegments;
    CourseSegment* prevSegment = segment->prev;

    do {
        if ((prevSegment->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) ==
            (segment->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
            segment->trackSegmentInfo |= TRACK_FLAG_CONTINUOUS;
        } else {
            segment->trackSegmentInfo &= ~TRACK_FLAG_CONTINUOUS;
        }
        prevSegment = segment;
        segment = segment->next;
    } while (segment != courseInfo->courseSegments);
}

void Course_ChunkCalculateCommonRoadReferencePos(SegmentChunk* chunk, f32 radiusLeft, f32 radiusRight, Mtx3F* basis,
                                                 Vec3f* leftPos, Vec3f* rightPos, Vec3f* topPos, Vec3f* bottomPos,
                                                 Vec3f* centerPos, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD) {
    f32 temp1;
    f32 temp2;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 sp6C;

    temp_fs4 = radiusLeft + 11.5f;
    temp_fs5 = radiusRight + 11.5f;
    temp1 = temp_fs4 - temp_fs5;
    temp2 = temp_fs4 + temp_fs5;
    temp_fs1 = temp1 / 2.0f;

    chunk->referencePos2[0] = Math_Round(centerPos->x = chunk->pos.x + (temp_fs1 * basis->z.x));
    chunk->referencePos2[1] = Math_Round(centerPos->y = chunk->pos.y + (temp_fs1 * basis->z.y));
    chunk->referencePos2[2] = Math_Round(centerPos->z = chunk->pos.z + (temp_fs1 * basis->z.z));

    chunk->referencePos1[0] = Math_Round(centerPos->x + ((argB - argC - argD) * basis->y.x));
    chunk->referencePos1[1] = Math_Round(centerPos->y + ((argB - argC - argD) * basis->y.y));
    chunk->referencePos1[2] = Math_Round(centerPos->z + ((argB - argC - argD) * basis->y.z));

    temp_fs1 = temp2 / 2.0f;

    topPos->x = (temp_fs2 = basis->y.x * temp_fs1) + centerPos->x;
    topPos->y = (temp_fs3 = basis->y.y * temp_fs1) + centerPos->y;
    topPos->z = (temp_fs0 = basis->y.z * temp_fs1) + centerPos->z;

    bottomPos->x = centerPos->x - temp_fs2;
    bottomPos->y = centerPos->y - temp_fs3;
    bottomPos->z = centerPos->z - temp_fs0;

    chunk->referencePos5[0] = Math_Round(leftPos->x = (temp_fs4 = basis->z.x * temp_fs1) + centerPos->x);
    chunk->referencePos5[1] = Math_Round(leftPos->y = (temp_fs5 = basis->z.y * temp_fs1) + centerPos->y);
    chunk->referencePos5[2] = Math_Round(leftPos->z = (sp6C = basis->z.z * temp_fs1) + centerPos->z);

    chunk->referencePos8[0] = Math_Round(rightPos->x = centerPos->x - temp_fs4);
    chunk->referencePos8[1] = Math_Round(rightPos->y = centerPos->y - temp_fs5);
    chunk->referencePos8[2] = Math_Round(rightPos->z = centerPos->z - sp6C);

    temp_fs1 += arg9;

    chunk->referencePos4[0] =
        Math_Round((temp_fs2 = centerPos->x + (argB * basis->y.x)) + (temp_fs4 = basis->z.x * temp_fs1));
    chunk->referencePos4[1] =
        Math_Round((temp_fs3 = centerPos->y + (argB * basis->y.y)) + (temp_fs5 = basis->z.y * temp_fs1));
    chunk->referencePos4[2] =
        Math_Round((temp_fs0 = centerPos->z + (argB * basis->y.z)) + (sp6C = basis->z.z * temp_fs1));

    chunk->referencePos7[0] = Math_Round(temp_fs2 - temp_fs4);
    chunk->referencePos7[1] = Math_Round(temp_fs3 - temp_fs5);
    chunk->referencePos7[2] = Math_Round(temp_fs0 - sp6C);

    temp_fs1 += argA;

    chunk->referencePos3[0] =
        Math_Round((temp_fs2 = centerPos->x + ((argB - argC) * basis->y.x)) + (temp_fs4 = basis->z.x * temp_fs1));
    chunk->referencePos3[1] =
        Math_Round((temp_fs3 = centerPos->y + ((argB - argC) * basis->y.y)) + (temp_fs5 = basis->z.y * temp_fs1));
    chunk->referencePos3[2] =
        Math_Round((temp_fs0 = centerPos->z + ((argB - argC) * basis->y.z)) + (sp6C = basis->z.z * temp_fs1));

    chunk->referencePos6[0] = Math_Round(temp_fs2 - temp_fs4);
    chunk->referencePos6[1] = Math_Round(temp_fs3 - temp_fs5);
    chunk->referencePos6[2] = Math_Round(temp_fs0 - sp6C);
}

void Course_ChunkCalculateRoadAirReferencePos(SegmentChunk* chunk, f32 radiusLeft, f32 radiusRight, Mtx3F* basis,
                                              Vec3f* leftPos, Vec3f* rightPos, Vec3f* topPos, Vec3f* bottomPos,
                                              Vec3f* centerPos) {
    Course_ChunkCalculateCommonRoadReferencePos(chunk, radiusLeft, radiusRight, basis, leftPos, rightPos, topPos,
                                                bottomPos, centerPos, 30.0f, 10.0f, 10.0f, 50.0f, 50.0f);
}

void Course_ChunkCalculateWalledRoadReferencePos(SegmentChunk* chunk, f32 radiusLeft, f32 radiusRight, Mtx3F* basis,
                                                 Vec3f* leftPos, Vec3f* rightPos, Vec3f* topPos, Vec3f* bottomPos,
                                                 Vec3f* centerPos) {
    Course_ChunkCalculateCommonRoadReferencePos(chunk, radiusLeft, radiusRight, basis, leftPos, rightPos, topPos,
                                                bottomPos, centerPos, 30.0f, 20.0f, 120.0f, 155.0f, 50.0f);
}

void Course_ChunkCalculatePipeReferencePos(SegmentChunk* chunk, f32 radiusLeft, f32 radiusRight, Mtx3F* basis,
                                           Vec3f* leftPos, Vec3f* rightPos, Vec3f* topPos, Vec3f* bottomPos,
                                           Vec3f* centerPos) {
    Course_ChunkCalculateCylinderReferencePos(chunk, radiusLeft / gSinTable[0x501], radiusRight, basis, leftPos,
                                              rightPos, topPos, bottomPos, centerPos);
}

void Course_ChunkCalculateCylinderReferencePos(SegmentChunk* chunk, f32 radius, f32 radiusRight, Mtx3F* basis,
                                               Vec3f* leftPos, Vec3f* rightPos, Vec3f* topPos, Vec3f* bottomPos,
                                               Vec3f* centerPos) {
    f32 sp64;
    f32 sp60;
    f32 temp_fs1;
    f32 temp_fs0;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_fs4;

    chunk->referencePos4[0] = Math_Round(leftPos->x = (centerPos->x = chunk->pos.x) + (sp54 = basis->z.x * radius));
    chunk->referencePos4[1] = Math_Round(leftPos->y = (centerPos->y = chunk->pos.y) + (sp50 = basis->z.y * radius));
    chunk->referencePos4[2] = Math_Round(leftPos->z = (centerPos->z = chunk->pos.z) + (sp4C = basis->z.z * radius));

    chunk->referencePos7[0] = Math_Round(rightPos->x = chunk->pos.x - sp54);
    chunk->referencePos7[1] = Math_Round(rightPos->y = chunk->pos.y - sp50);
    chunk->referencePos7[2] = Math_Round(rightPos->z = chunk->pos.z - sp4C);

    chunk->referencePos2[0] = Math_Round(topPos->x = (temp_fs2 = basis->y.x * radius) + chunk->pos.x);
    chunk->referencePos2[1] = Math_Round(topPos->y = (temp_fs3 = basis->y.y * radius) + chunk->pos.y);
    chunk->referencePos2[2] = Math_Round(topPos->z = (temp_fs4 = basis->y.z * radius) + chunk->pos.z);

    chunk->referencePos1[0] = Math_Round(bottomPos->x = chunk->pos.x - temp_fs2);
    chunk->referencePos1[1] = Math_Round(bottomPos->y = chunk->pos.y - temp_fs3);
    chunk->referencePos1[2] = Math_Round(bottomPos->z = chunk->pos.z - temp_fs4);

    sp64 = gSinTable[0x200] * radius;

    chunk->referencePos5[0] =
        Math_Round((sp60 = (sp54 = basis->z.x * sp64) + chunk->pos.x) + (temp_fs2 = basis->y.x * sp64));
    chunk->referencePos5[1] =
        Math_Round((temp_fs1 = (sp50 = basis->z.y * sp64) + chunk->pos.y) + (temp_fs3 = basis->y.y * sp64));
    chunk->referencePos5[2] =
        Math_Round((temp_fs0 = (sp4C = basis->z.z * sp64) + chunk->pos.z) + (temp_fs4 = basis->y.z * sp64));

    chunk->referencePos3[0] = Math_Round(sp60 - temp_fs2);
    chunk->referencePos3[1] = Math_Round(temp_fs1 - temp_fs3);
    chunk->referencePos3[2] = Math_Round(temp_fs0 - temp_fs4);

    chunk->referencePos8[0] = Math_Round((sp60 = chunk->pos.x - sp54) + temp_fs2);
    chunk->referencePos8[1] = Math_Round((temp_fs1 = chunk->pos.y - sp50) + temp_fs3);
    chunk->referencePos8[2] = Math_Round((temp_fs0 = chunk->pos.z - sp4C) + temp_fs4);

    chunk->referencePos6[0] = Math_Round(sp60 - temp_fs2);
    chunk->referencePos6[1] = Math_Round(temp_fs1 - temp_fs3);
    chunk->referencePos6[2] = Math_Round(temp_fs0 - temp_fs4);
}

void Course_ChunkCalculateHalfPipeReferencePos(SegmentChunk* chunk, f32 radiusLeft, f32 radiusRight, Mtx3F* basis,
                                               Vec3f* leftPos, Vec3f* rightPos, Vec3f* topPos, Vec3f* bottomPos,
                                               Vec3f* centerPos) {
    f32 sp64;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 sp58;
    f32 sp54;
    f32 temp_fs0;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;

    sp64 = radiusLeft / gSinTable[0x4C1];
    temp_fs1 = gSinTable[0xD00] * sp64;
    temp_fs2 = gSinTable[0x900] * sp64;

    chunk->referencePos7[0] =
        Math_Round(rightPos->x = (sp58 = chunk->pos.x + (temp_fs2 * basis->y.x)) + (temp_fs3 = basis->z.x * temp_fs1));
    chunk->referencePos7[1] =
        Math_Round(rightPos->y = (sp54 = chunk->pos.y + (temp_fs2 * basis->y.y)) + (temp_fs4 = basis->z.y * temp_fs1));
    chunk->referencePos7[2] = Math_Round(rightPos->z = (temp_fs0 = chunk->pos.z + (temp_fs2 * basis->y.z)) +
                                                       (temp_fs5 = basis->z.z * temp_fs1));

    chunk->referencePos4[0] = Math_Round(leftPos->x = sp58 - temp_fs3);
    chunk->referencePos4[1] = Math_Round(leftPos->y = sp54 - temp_fs4);
    chunk->referencePos4[2] = Math_Round(leftPos->z = temp_fs0 - temp_fs5);

    temp_fs1 = gSinTable[0xE80] * sp64;
    temp_fs2 = gSinTable[0xA80] * sp64;

    chunk->referencePos8[0] =
        Math_Round((sp58 = chunk->pos.x + (temp_fs2 * basis->y.x)) + (temp_fs3 = basis->z.x * temp_fs1));
    chunk->referencePos8[1] =
        Math_Round((sp54 = chunk->pos.y + (temp_fs2 * basis->y.y)) + (temp_fs4 = basis->z.y * temp_fs1));
    chunk->referencePos8[2] =
        Math_Round((temp_fs0 = chunk->pos.z + (temp_fs2 * basis->y.z)) + (temp_fs5 = basis->z.z * temp_fs1));

    chunk->referencePos5[0] = Math_Round(sp58 - temp_fs3);
    chunk->referencePos5[1] = Math_Round(sp54 - temp_fs4);
    chunk->referencePos5[2] = Math_Round(temp_fs0 - temp_fs5);

    chunk->referencePos2[0] = Math_Round(bottomPos->x = chunk->pos.x - (sp64 * basis->y.x));
    chunk->referencePos2[1] = Math_Round(bottomPos->y = chunk->pos.y - (sp64 * basis->y.y));
    chunk->referencePos2[2] = Math_Round(bottomPos->z = chunk->pos.z - (sp64 * basis->y.z));

    sp64 *= 1.2f;
    temp_fs1 = gSinTable[0xE80] * sp64;
    temp_fs2 = gSinTable[0xA80] * sp64;

    chunk->referencePos6[0] =
        Math_Round((sp58 = chunk->pos.x + (temp_fs2 * basis->y.x)) + (temp_fs3 = basis->z.x * temp_fs1));
    chunk->referencePos6[1] =
        Math_Round((sp54 = chunk->pos.y + (temp_fs2 * basis->y.y)) + (temp_fs4 = basis->z.y * temp_fs1));
    chunk->referencePos6[2] =
        Math_Round((temp_fs0 = chunk->pos.z + (temp_fs2 * basis->y.z)) + (temp_fs5 = basis->z.z * temp_fs1));

    chunk->referencePos3[0] = Math_Round(sp58 - temp_fs3);
    chunk->referencePos3[1] = Math_Round(sp54 - temp_fs4);
    chunk->referencePos3[2] = Math_Round(temp_fs0 - temp_fs5);

    chunk->referencePos1[0] = Math_Round((topPos->x = centerPos->x = chunk->pos.x) - (sp64 * basis->y.x));
    chunk->referencePos1[1] = Math_Round((topPos->y = centerPos->y = chunk->pos.y) - (sp64 * basis->y.y));
    chunk->referencePos1[2] = Math_Round((topPos->z = centerPos->z = chunk->pos.z) - (sp64 * basis->y.z));
}

void Course_ChunkCalculateTunnelReferencePos(SegmentChunk* chunk, f32 radiusLeft, f32 radiusRight, Mtx3F* basis,
                                             Vec3f* leftPos, Vec3f* rightPos, Vec3f* topPos, Vec3f* bottomPos,
                                             Vec3f* centerPos) {
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;

    temp_fs4 = radiusLeft + 11.5f;
    temp_fs5 = radiusRight + 11.5f;

    temp_fs1 = (temp_fs4 - temp_fs5) / 2.0f;

    chunk->referencePos1[0] = Math_Round(centerPos->x = chunk->pos.x + (temp_fs1 * basis->z.x));
    chunk->referencePos1[1] = Math_Round(centerPos->y = chunk->pos.y + (temp_fs1 * basis->z.y));
    chunk->referencePos1[2] = Math_Round(centerPos->z = chunk->pos.z + (temp_fs1 * basis->z.z));

    chunk->referencePos2[0] = Math_Round(topPos->x = (temp_fs2 = basis->y.x * 185.0f) + centerPos->x);
    chunk->referencePos2[1] = Math_Round(topPos->y = (temp_fs3 = basis->y.y * 185.0f) + centerPos->y);
    chunk->referencePos2[2] = Math_Round(topPos->z = (sp68 = basis->y.z * 185.0f) + centerPos->z);

    bottomPos->x = centerPos->x - temp_fs2;
    bottomPos->y = centerPos->y - temp_fs3;
    bottomPos->z = centerPos->z - sp68;
    temp_fs1 = (temp_fs4 + temp_fs5) / 2.0f;

    chunk->referencePos3[0] = Math_Round(leftPos->x = (sp64 = basis->z.x * temp_fs1) + centerPos->x);
    chunk->referencePos3[1] = Math_Round(leftPos->y = (sp60 = basis->z.y * temp_fs1) + centerPos->y);
    chunk->referencePos3[2] = Math_Round(leftPos->z = (sp5C = basis->z.z * temp_fs1) + centerPos->z);

    chunk->referencePos6[0] = Math_Round(rightPos->x = centerPos->x - sp64);
    chunk->referencePos6[1] = Math_Round(rightPos->y = centerPos->y - sp60);
    chunk->referencePos6[2] = Math_Round(rightPos->z = centerPos->z - sp5C);

    chunk->referencePos4[0] = Math_Round((temp_fs2 = basis->y.x * 85.0f) + leftPos->x);
    chunk->referencePos4[1] = Math_Round((temp_fs3 = basis->y.y * 85.0f) + leftPos->y);
    chunk->referencePos4[2] = Math_Round((sp68 = basis->y.z * 85.0f) + leftPos->z);

    chunk->referencePos7[0] = Math_Round(rightPos->x + temp_fs2);
    chunk->referencePos7[1] = Math_Round(rightPos->y + temp_fs3);
    chunk->referencePos7[2] = Math_Round(rightPos->z + sp68);

    temp_fs1 *= 0.625f;

    chunk->referencePos5[0] =
        Math_Round((temp_fs2 = centerPos->x + (160.0f * basis->y.x)) + (sp64 = basis->z.x * temp_fs1));
    chunk->referencePos5[1] =
        Math_Round((temp_fs3 = centerPos->y + (160.0f * basis->y.y)) + (sp60 = basis->z.y * temp_fs1));
    chunk->referencePos5[2] =
        Math_Round((sp68 = centerPos->z + (160.0f * basis->y.z)) + (sp5C = basis->z.z * temp_fs1));

    chunk->referencePos8[0] = Math_Round(temp_fs2 - sp64);
    chunk->referencePos8[1] = Math_Round(temp_fs3 - sp60);
    chunk->referencePos8[2] = Math_Round(sp68 - sp5C);
}

void Course_ChunkCalculateBorderlessRoadReferencePos(SegmentChunk* chunk, f32 radiusLeft, f32 radiusRight, Mtx3F* basis,
                                                     Vec3f* leftPos, Vec3f* rightPos, Vec3f* topPos, Vec3f* bottomPos,
                                                     Vec3f* centerPos) {
    Course_ChunkCalculateCommonRoadReferencePos(chunk, radiusLeft - 15.410001f, radiusRight - 15.410001f, basis,
                                                leftPos, rightPos, topPos, bottomPos, centerPos, 10.0f, 0.0f, -10.0f,
                                                40.0f, 40.0f);
}

// "Join" Segment Chunk reference positions
void Course_ChunkJoinReferencePos(s16* referencePos1, s16* referencePos2, f32 joinScale, s16* outReferencePos) {
    outReferencePos[0] = (s16) Math_Round((referencePos2[0] - referencePos1[0]) * joinScale) + referencePos1[0];
    outReferencePos[1] = (s16) Math_Round((referencePos2[1] - referencePos1[1]) * joinScale) + referencePos1[1];
    outReferencePos[2] = (s16) Math_Round((referencePos2[2] - referencePos1[2]) * joinScale) + referencePos1[2];
}

void Course_ChunkJoinPipeTunnel(SegmentChunk* currentChunk, SegmentChunk* nextChunk, f32 joinScale) {
    Course_ChunkJoinReferencePos(currentChunk->referencePos2, nextChunk->referencePos1, joinScale,
                                 nextChunk->referencePos2);
    Course_ChunkJoinReferencePos(currentChunk->referencePos1, nextChunk->referencePos1, joinScale,
                                 nextChunk->referencePos1);
    Course_ChunkJoinReferencePos(currentChunk->referencePos4, nextChunk->referencePos4, joinScale,
                                 nextChunk->referencePos4);
    Course_ChunkJoinReferencePos(currentChunk->referencePos7, nextChunk->referencePos7, joinScale,
                                 nextChunk->referencePos7);
    Course_ChunkJoinReferencePos(currentChunk->referencePos5, nextChunk->referencePos3, joinScale,
                                 nextChunk->referencePos5);
    Course_ChunkJoinReferencePos(currentChunk->referencePos3, nextChunk->referencePos3, joinScale,
                                 nextChunk->referencePos3);
    Course_ChunkJoinReferencePos(currentChunk->referencePos8, nextChunk->referencePos6, joinScale,
                                 nextChunk->referencePos8);
    Course_ChunkJoinReferencePos(currentChunk->referencePos6, nextChunk->referencePos6, joinScale,
                                 nextChunk->referencePos6);
}

void Course_ChunkJoinCylinder(SegmentChunk* currentChunk, SegmentChunk* nextChunk, f32 joinScale) {

    if (joinScale == 0.0f) {
        nextChunk->referencePos1[0] = currentChunk->referencePos1[0];
        nextChunk->referencePos1[1] = currentChunk->referencePos1[1];
        nextChunk->referencePos1[2] = currentChunk->referencePos1[2];
        nextChunk->referencePos2[0] = currentChunk->referencePos2[0];
        nextChunk->referencePos2[1] = currentChunk->referencePos2[1];
        nextChunk->referencePos2[2] = currentChunk->referencePos2[2];
        nextChunk->referencePos3[0] = currentChunk->referencePos3[0];
        nextChunk->referencePos3[1] = currentChunk->referencePos3[1];
        nextChunk->referencePos3[2] = currentChunk->referencePos3[2];
        nextChunk->referencePos4[0] = currentChunk->referencePos4[0];
        nextChunk->referencePos4[1] = currentChunk->referencePos4[1];
        nextChunk->referencePos4[2] = currentChunk->referencePos4[2];
        nextChunk->referencePos5[0] = currentChunk->referencePos5[0];
        nextChunk->referencePos5[1] = currentChunk->referencePos5[1];
        nextChunk->referencePos5[2] = currentChunk->referencePos5[2];
        nextChunk->referencePos6[0] = currentChunk->referencePos6[0];
        nextChunk->referencePos6[1] = currentChunk->referencePos6[1];
        nextChunk->referencePos6[2] = currentChunk->referencePos6[2];
        nextChunk->referencePos7[0] = currentChunk->referencePos7[0];
        nextChunk->referencePos7[1] = currentChunk->referencePos7[1];
        nextChunk->referencePos7[2] = currentChunk->referencePos7[2];
        nextChunk->referencePos8[0] = currentChunk->referencePos8[0];
        nextChunk->referencePos8[1] = currentChunk->referencePos8[1];
        nextChunk->referencePos8[2] = currentChunk->referencePos8[2];
    } else {
        Course_ChunkJoinReferencePos(currentChunk->referencePos2, nextChunk->referencePos1, joinScale,
                                     nextChunk->referencePos1);
        Course_ChunkJoinReferencePos(currentChunk->referencePos2, nextChunk->referencePos2, joinScale,
                                     nextChunk->referencePos2);
        Course_ChunkJoinReferencePos(currentChunk->referencePos2, nextChunk->referencePos3, joinScale,
                                     nextChunk->referencePos3);
        Course_ChunkJoinReferencePos(currentChunk->referencePos2, nextChunk->referencePos4, joinScale,
                                     nextChunk->referencePos4);
        Course_ChunkJoinReferencePos(currentChunk->referencePos2, nextChunk->referencePos5, joinScale,
                                     nextChunk->referencePos5);
        Course_ChunkJoinReferencePos(currentChunk->referencePos2, nextChunk->referencePos6, joinScale,
                                     nextChunk->referencePos6);
        Course_ChunkJoinReferencePos(currentChunk->referencePos2, nextChunk->referencePos7, joinScale,
                                     nextChunk->referencePos7);
        Course_ChunkJoinReferencePos(currentChunk->referencePos2, nextChunk->referencePos8, joinScale,
                                     nextChunk->referencePos8);
    }
}

void Course_ChunkJoinEqual(SegmentChunk* currentChunk, SegmentChunk* nextChunk, f32 joinScale) {
    Course_ChunkJoinReferencePos(currentChunk->referencePos1, nextChunk->referencePos1, joinScale,
                                 nextChunk->referencePos1);
    Course_ChunkJoinReferencePos(currentChunk->referencePos2, nextChunk->referencePos2, joinScale,
                                 nextChunk->referencePos2);
    Course_ChunkJoinReferencePos(currentChunk->referencePos3, nextChunk->referencePos3, joinScale,
                                 nextChunk->referencePos3);
    Course_ChunkJoinReferencePos(currentChunk->referencePos4, nextChunk->referencePos4, joinScale,
                                 nextChunk->referencePos4);
    Course_ChunkJoinReferencePos(currentChunk->referencePos5, nextChunk->referencePos5, joinScale,
                                 nextChunk->referencePos5);
    Course_ChunkJoinReferencePos(currentChunk->referencePos6, nextChunk->referencePos6, joinScale,
                                 nextChunk->referencePos6);
    Course_ChunkJoinReferencePos(currentChunk->referencePos7, nextChunk->referencePos7, joinScale,
                                 nextChunk->referencePos7);
    Course_ChunkJoinReferencePos(currentChunk->referencePos8, nextChunk->referencePos8, joinScale,
                                 nextChunk->referencePos8);
}

f32 Course_SegmentGetJoinLengths(CourseSegment* segment) {
    f32 temp_fv1;
    f32 joinLength;
    f32 length;
    Vec3f sp58;

    segment->joinScale = -1.0f;
    joinLength = gTrackJoinUpperLength[TRACK_SHAPE_INDEX((u32) segment->trackSegmentInfo & TRACK_SHAPE_MASK)];

    if (segment->trackSegmentInfo & TRACK_JOIN_PREVIOUS) {
        segment->previousJoinEndTValue = 0.0f;
        length = 0.0f;
        do {
            temp_fv1 = 50.0f / Course_SplineGetTangent(segment, segment->previousJoinEndTValue, &sp58);
            segment->previousJoinEndTValue += temp_fv1;

            if (segment->previousJoinEndTValue >= 1.0f) {
                joinLength = length;
                segment->previousJoinEndTValue -= temp_fv1;
                break;
            }
            length += 50.0f;
        } while (length < joinLength);
        segment->joinScale = length / segment->length;
    } else {
        segment->previousJoinEndTValue = -99.0f;
    }

    if (segment->trackSegmentInfo & TRACK_JOIN_NEXT) {
        segment->nextJoinStartTValue = 1.0f;

        length = 0.0f;
        do {
            temp_fv1 = 50.0f / Course_SplineGetTangent(segment, segment->nextJoinStartTValue, &sp58);
            segment->nextJoinStartTValue -= temp_fv1;
            if (segment->nextJoinStartTValue <= 0.0f) {
                joinLength = length;
                segment->nextJoinStartTValue += temp_fv1;
                break;
            }
            length += 50.0f;
        } while (length < joinLength);
        segment->joinScale = length / segment->length;
    } else if (!(segment->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) &&
               (segment->next->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        segment->nextJoinStartTValue = 1.0f - (100.0f / Course_SplineGetTangent(segment, 1.0f, &sp58));
    } else {
        segment->nextJoinStartTValue = 99.0f;
    }
    if (segment->nextJoinStartTValue <= segment->previousJoinEndTValue) {
        segment->previousJoinEndTValue = 0.49f;
        segment->nextJoinStartTValue = 0.51f;
        segment->joinScale = 0.49f;
        joinLength = segment->length * 0.49f;
    }
    return joinLength;
}

bool func_800A1818(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    Vec3f vec;
    f32 temp_fa1;

    vec.x = arg2->x - arg0->x;
    vec.y = arg2->y - arg0->y;
    vec.z = arg2->z - arg0->z;
    temp_fa1 = DOT_XYZ(arg1, &vec);
    if (SQ_SUM(&vec) - SQ(temp_fa1) < D_800F89E8) {
        return false;
    }
    return true;
}

f32 Course_ChunkPositionDistance(Vec3f* vec1, Vec3f* vec2) {
    f32 diff;
    f32 sum;

    diff = vec1->x - vec2->x;
    sum = SQ(diff);
    diff = vec1->y - vec2->y;
    sum += SQ(diff);
    diff = vec1->z - vec2->z;
    sum += SQ(diff);

    return sqrtf(sum);
}

s32 func_800A18FC(s32 trackSegmentInfo, f32 distance) {

    if ((trackSegmentInfo & TRACK_TYPE_MASK) != TRACK_TYPE_NONE) {
        return (s32) (D_800CF8C8[TRACK_SHAPE_INDEX(trackSegmentInfo & TRACK_SHAPE_MASK)]
                                [trackSegmentInfo & TRACK_TYPE_MASK]
                                    .textureScale *
                      distance) -
               0x8000;
    }
    return -0x8000;
}

extern SegmentChunk gSegmentChunks[];

s32 func_800A1954(CourseInfo* courseInfo) {
    CourseSegment* startSegment;
    CourseSegment* segment;
    CourseSegment* nextSegment;
    s32 trackSegmentInfo;
    f32 lengthProportionAlongSegment;
    f32 forwardMagnitude;
    f32 radiusLeft;
    f32 radiusRight;
    f32 sp274;
    SegmentChunk* segmentChunk;
    SegmentChunk* nextSegmentChunk;
    f32 t;
    f32 var_fs3;
    f32 var_fs0;
    Vec3f segmentStartLeftPos;
    Vec3f segmentStartRightPos;
    Vec3f segmentStartTopPos;
    Vec3f segmentStartBottomPos;
    Vec3f segmentStartCenterPos;
    Vec3f currentChunkLeftPos;
    Vec3f currentChunkRightPos;
    Vec3f currentChunkTopPos;
    Vec3f currentChunkBottomPos;
    Vec3f currentChunkCenterPos;
    Vec3f previousChunkLeftPos;
    Vec3f previousChunkRightPos;
    Vec3f previousChunkTopPos;
    Vec3f previousChunkBottomPos;
    Vec3f courseStartLeftPos;
    Vec3f courseStartRightPos;
    Vec3f courseStartTopPos;
    Vec3f courseStartBottomPos;
    Vec3f forward;
    Vec3f sp170;
    SegmentChunk sp110;
    Mtx3F segmentBasis;
    f32 leftFaceDistance;
    f32 rightFaceDistance;
    f32 topFaceDistance;
    f32 bottomFaceDistance;
    Vec3f* segmentPos;
    s32 leftTextureCoord;
    s32 rightTextureCoord;
    s32 topTextureCoord;
    s32 bottomTextureCoord;
    s32 var_v1;
    f32 temp_fv0_5;
    unk_800CF528* temp_a3;
    f32 joinLengths;
    s32 spB4;
    Vec3f spA8;
    s32 pad;

    spB4 = 0;
    segment = courseInfo->courseSegments;

    while (segment->trackSegmentInfo & TRACK_FLAG_CONTINUOUS) {
        segment = segment->next;
    }

    startSegment = segment;
    nextSegment = segment->next;
    gSegmentChunks[0].trackSegmentInfo = (segment->trackSegmentInfo & ~TRACK_JOIN_MASK) | TRACK_FLAG_80000000;
    if (segment->trackSegmentInfo & TRACK_JOIN_PREVIOUS) {
        gSegmentChunks[0].trackSegmentInfo |= (TRACK_JOIN_PREVIOUS | TRACK_CHUNK_JOIN_PREVIOUS_START);
    } else if (segment->prev->trackSegmentInfo & TRACK_JOIN_NEXT) {
        gSegmentChunks[0].trackSegmentInfo |= TRACK_JOIN_NEXT;
    }
    joinLengths = Course_SegmentGetJoinLengths(segment);
    forwardMagnitude = Course_SplineGetBasis(segment, 0.0f, &segmentBasis, 0.0f);

    Course_SplineGetPosition(segment, 0.0f, &gSegmentChunks[0].pos);
    if (gSegmentChunks[0].trackSegmentInfo & TRACK_JOIN_BOTH) {
        Course_ChunkCalculateRoadAirReferencePos(&gSegmentChunks[0], segment->radiusLeft, segment->radiusRight,
                                                 &segmentBasis, &segmentStartLeftPos, &segmentStartRightPos,
                                                 &segmentStartTopPos, &segmentStartBottomPos, &segmentStartCenterPos);
    } else {
        sSegmentChunkCalculateReferencePosFuncs[TRACK_SHAPE_INDEX(
            (u32) (segment->trackSegmentInfo & TRACK_SHAPE_MASK))](
            &gSegmentChunks[0], segment->radiusLeft, segment->radiusRight, &segmentBasis, &segmentStartLeftPos,
            &segmentStartRightPos, &segmentStartTopPos, &segmentStartBottomPos, &segmentStartCenterPos);
    }
    forward.x = segmentBasis.x.x;
    forward.y = segmentBasis.x.y;
    forward.z = segmentBasis.x.z;

    spA8 = segmentStartLeftPos;
    previousChunkLeftPos = spA8;
    courseStartLeftPos = spA8;
    spA8 = segmentStartRightPos;
    previousChunkRightPos = spA8;
    courseStartRightPos = spA8;
    spA8 = segmentStartTopPos;
    previousChunkTopPos = spA8;
    courseStartTopPos = spA8;
    spA8 = segmentStartBottomPos;
    previousChunkBottomPos = spA8;
    courseStartBottomPos = spA8;

    gSegmentChunks[0].leftTextureCorrection = gSegmentChunks[0].rightTextureCorrection =
        gSegmentChunks[0].topTextureCorrection = gSegmentChunks[0].bottomTextureCorrection = -0x8000;
    gSegmentChunks[0].segmentIndex = (s32) (segment - courseInfo->courseSegments);

    leftFaceDistance = rightFaceDistance = topFaceDistance = bottomFaceDistance = 0.0f;
    var_fs3 = 0.0f;
    t = 0.0f;
    segmentChunk = gSegmentChunks;
    nextSegmentChunk = segmentChunk + 1;
    gSegmentChunks[0].segmentTValue = 0.0f;
    segment->startChunk = gSegmentChunks;
    gSegmentChunkCount = 1;

    while (true) {
        trackSegmentInfo = segment->trackSegmentInfo;
        sp274 = D_800F89E0 / forwardMagnitude;
        if (D_800F8524 != 0) {
            var_fs3 += D_800F89E0;
        }

        if (((segment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_AIR) ||
            (((t == segment->nextJoinStartTValue)) &&
             ((segment->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) ==
              (TRACK_SHAPE_ROAD | ROAD_START_LINE)))) {
            segment->endChunk = nextSegmentChunk;
            segment = nextSegment;
            t = 0.0f;
            if (nextSegment != startSegment) {
                nextSegment = nextSegment->next;
                segment->startChunk = nextSegmentChunk;
                joinLengths = Course_SegmentGetJoinLengths(segment);
            } else {
                break;
            }
        } else if (t < segment->previousJoinEndTValue) {
            t += sp274;

            if (segment->previousJoinEndTValue <= t) {
                t = segment->previousJoinEndTValue;
            }
        } else if ((t < segment->nextJoinStartTValue) && (segment->nextJoinStartTValue < 1.0f)) {
            t += sp274;
            if (segment->nextJoinStartTValue <= t) {
                t = segment->nextJoinStartTValue;
            }
            // FAKE
            gSegmentChunks[0].trackSegmentInfo = gSegmentChunks[0].trackSegmentInfo;
        } else {
            t += sp274;

            if (t >= 1.0f) {
                if (nextSegment->trackSegmentInfo & TRACK_FLAG_CONTINUOUS) {
                    if (t < 2.0f) {
                        t -= 1.0f;
                        t *= (forwardMagnitude / Course_SplineGetTangent(nextSegment, 0.0f, &segmentBasis.x));
                    } else {
                        t = 0.0f;
                    }
                } else {
                    t = 0.0f;
                }
                segment->endChunk = nextSegmentChunk;
                segment = nextSegment;
                if (nextSegment != startSegment) {
                    nextSegment = nextSegment->next;
                    if (t == 0.0f) {
                        segment->startChunk = nextSegmentChunk;
                    } else {
                        segment->startChunk = nextSegmentChunk - 1;
                    }
                    joinLengths = Course_SegmentGetJoinLengths(segment);

                } else {
                    break;
                }
            }
        }

        segmentPos = &nextSegmentChunk->pos;
        lengthProportionAlongSegment = Course_SplineGetLengthInfo(segment, t, &sp274);
        radiusLeft =
            ((nextSegment->radiusLeft - segment->radiusLeft) * lengthProportionAlongSegment) + segment->radiusLeft;
        radiusRight =
            ((nextSegment->radiusRight - segment->radiusRight) * lengthProportionAlongSegment) + segment->radiusRight;
        forwardMagnitude = Course_SplineGetBasis(segment, t, &segmentBasis, lengthProportionAlongSegment);
        Course_SplineGetPosition(segment, t, segmentPos);

        sSegmentChunkCalculateReferencePosFuncs[TRACK_SHAPE_INDEX((u32) segment->trackSegmentInfo & TRACK_SHAPE_MASK)](
            nextSegmentChunk, radiusLeft, radiusRight, &segmentBasis, &currentChunkLeftPos, &currentChunkRightPos,
            &currentChunkTopPos, &currentChunkBottomPos, &currentChunkCenterPos);
        leftFaceDistance += Course_ChunkPositionDistance(&currentChunkLeftPos, &previousChunkLeftPos);
        rightFaceDistance += Course_ChunkPositionDistance(&currentChunkRightPos, &previousChunkRightPos);
        topFaceDistance += Course_ChunkPositionDistance(&currentChunkTopPos, &previousChunkTopPos);
        bottomFaceDistance += Course_ChunkPositionDistance(&currentChunkBottomPos, &previousChunkBottomPos);
        previousChunkLeftPos = currentChunkLeftPos;
        previousChunkRightPos = currentChunkRightPos;
        previousChunkTopPos = currentChunkTopPos;
        previousChunkBottomPos = currentChunkBottomPos;
        if ((D_800F8524 == 0) || (D_800F89E4 <= var_fs3) ||
            (func_800A1818(&segmentStartLeftPos, &forward, &currentChunkLeftPos) != 0) ||
            (func_800A1818(&segmentStartRightPos, &forward, &currentChunkRightPos) != 0) ||
            (func_800A1818(&segmentStartTopPos, &forward, &currentChunkTopPos) != 0) ||
            (func_800A1818(&segmentStartBottomPos, &forward, &currentChunkBottomPos) != 0) || (t == 0.0f) ||
            (t == segment->previousJoinEndTValue) || (t == segment->nextJoinStartTValue)) {

            forward.x = currentChunkCenterPos.x - segmentStartCenterPos.x;
            forward.y = currentChunkCenterPos.y - segmentStartCenterPos.y;
            forward.z = currentChunkCenterPos.z - segmentStartCenterPos.z;
            if (0) {}

            if (((sp170.x = currentChunkLeftPos.x - segmentStartLeftPos.x) * forward.x) +
                    ((sp170.y = currentChunkLeftPos.y - segmentStartLeftPos.y) * forward.y) +
                    ((sp170.z = currentChunkLeftPos.z - segmentStartLeftPos.z) * forward.z) >
                0.0f) {
                var_fs0 = sqrtf(SQ(sp170.x) + SQ(sp170.y) + SQ(sp170.z));

                if (((sp170.x = currentChunkRightPos.x - segmentStartRightPos.x) * forward.x) +
                        ((sp170.y = currentChunkRightPos.y - segmentStartRightPos.y) * forward.y) +
                        ((sp170.z = currentChunkRightPos.z - segmentStartRightPos.z) * forward.z) >
                    0.0f) {
                    temp_fv0_5 = sqrtf(SQ(sp170.x) + SQ(sp170.y) + SQ(sp170.z));

                    if (var_fs0 < temp_fv0_5) {
                        sp274 = var_fs0 / temp_fv0_5;
                    } else {
                        sp274 = temp_fv0_5 / var_fs0;
                    }

                    if (sp274 > 0.044f) {
                        if (((sp170.x = currentChunkTopPos.x - segmentStartTopPos.x) * forward.x) +
                                ((sp170.y = currentChunkTopPos.y - segmentStartTopPos.y) * forward.y) +
                                ((sp170.z = currentChunkTopPos.z - segmentStartTopPos.z) * forward.z) >
                            0.0f) {
                            var_fs0 = sqrtf(SQ(sp170.x) + SQ(sp170.y) + SQ(sp170.z));
                            if (((sp170.x = currentChunkBottomPos.x - segmentStartBottomPos.x) * forward.x) +
                                    ((sp170.y = currentChunkBottomPos.y - segmentStartBottomPos.y) * forward.y) +
                                    ((sp170.z = currentChunkBottomPos.z - segmentStartBottomPos.z) * forward.z) >
                                0.0f) {
                                temp_fv0_5 = sqrtf(SQ(sp170.x) + SQ(sp170.y) + SQ(sp170.z));
                                if (var_fs0 < temp_fv0_5) {
                                    sp274 = var_fs0 / temp_fv0_5;
                                } else {
                                    sp274 = temp_fv0_5 / var_fs0;
                                }
                                if (sp274 > 0.034f) {
                                    goto skip;
                                }
                            }
                        }
                    }
                }
            }

            if (!(spB4 & 0x10000)) {
                spB4 |= 0x10000 | nextSegmentChunk - gSegmentChunks;
            }

        skip:

            sp274 = SQ(forward.x) + SQ(forward.y) + SQ(forward.z);

            sp274 = 1.0f / sqrtf(sp274);
            forward.x *= sp274;
            forward.y *= sp274;
            forward.z *= sp274;

            segmentStartCenterPos = currentChunkCenterPos;
            segmentStartLeftPos = currentChunkLeftPos;
            segmentStartRightPos = currentChunkRightPos;
            segmentStartTopPos = currentChunkTopPos;
            segmentStartBottomPos = currentChunkBottomPos;

            leftTextureCoord = func_800A18FC(trackSegmentInfo, leftFaceDistance);
            rightTextureCoord = func_800A18FC(trackSegmentInfo, rightFaceDistance);
            topTextureCoord = func_800A18FC(trackSegmentInfo, topFaceDistance);
            bottomTextureCoord = func_800A18FC(trackSegmentInfo, bottomFaceDistance);
            if ((leftTextureCoord < 0x8000) && (rightTextureCoord < 0x8000) && (topTextureCoord < 0x8000) &&
                (bottomTextureCoord < 0x8000)) {
                nextSegmentChunk->leftTextureCoord = leftTextureCoord;
                nextSegmentChunk->rightTextureCoord = rightTextureCoord;
                nextSegmentChunk->topTextureCoord = topTextureCoord;
                nextSegmentChunk->bottomTextureCoord = bottomTextureCoord;
            } else {
                segmentChunk->trackSegmentInfo =
                    (segmentChunk->trackSegmentInfo & ~TRACK_FLAG_CONTINUOUS) | TRACK_FLAG_80000000;
                temp_a3 = &D_800CF8C8[TRACK_SHAPE_INDEX((u32) trackSegmentInfo & TRACK_SHAPE_MASK)]
                                     [trackSegmentInfo & TRACK_TYPE_MASK];

                var_v1 = temp_a3->textureCoordinateMask;
                temp_fv0_5 = temp_a3->textureScale;
                segmentChunk->leftTextureCorrection = (segmentChunk->leftTextureCoord & var_v1) - 0x8000;
                nextSegmentChunk->leftTextureCoord =
                    (leftTextureCoord - segmentChunk->leftTextureCoord) + segmentChunk->leftTextureCorrection;
                leftFaceDistance = (f32) (nextSegmentChunk->leftTextureCoord + 0x8000) / temp_fv0_5;

                segmentChunk->rightTextureCorrection = (segmentChunk->rightTextureCoord & var_v1) - 0x8000;
                nextSegmentChunk->rightTextureCoord =
                    (rightTextureCoord - segmentChunk->rightTextureCoord) + segmentChunk->rightTextureCorrection;
                rightFaceDistance = (f32) (nextSegmentChunk->rightTextureCoord + 0x8000) / temp_fv0_5;

                segmentChunk->topTextureCorrection = (segmentChunk->topTextureCoord & var_v1) - 0x8000;
                nextSegmentChunk->topTextureCoord =
                    (topTextureCoord - segmentChunk->topTextureCoord) + segmentChunk->topTextureCorrection;
                topFaceDistance = (f32) (nextSegmentChunk->topTextureCoord + 0x8000) / temp_fv0_5;

                segmentChunk->bottomTextureCorrection = (segmentChunk->bottomTextureCoord & var_v1) - 0x8000;
                nextSegmentChunk->bottomTextureCoord =
                    (bottomTextureCoord - segmentChunk->bottomTextureCoord) + segmentChunk->bottomTextureCorrection;
                bottomFaceDistance = (f32) (nextSegmentChunk->bottomTextureCoord + 0x8000) / temp_fv0_5;
            }
            nextSegmentChunk->trackSegmentInfo =
                segment->trackSegmentInfo &
                ~(TRACK_JOIN_MASK | TRACK_CHUNK_JOIN_TRANSITION_END_MASK | TRACK_CHUNK_JOIN_TRANSITION_START_MASK);
            nextSegmentChunk->segmentIndex = segment - courseInfo->courseSegments;
            nextSegmentChunk->segmentTValue = t;

            if ((segment->previousJoinEndTValue <= t) && (t <= segment->nextJoinStartTValue)) {
                if (t == segment->previousJoinEndTValue) {

                    if ((nextSegmentChunk - 1)->trackSegmentInfo & TRACK_FLAG_INSIDE) {
                        (nextSegmentChunk - 1)->trackSegmentInfo =
                            ((nextSegmentChunk - 1)->trackSegmentInfo & ~TRACK_FLAG_CONTINUOUS) |
                            TRACK_CHUNK_JOIN_PREVIOUS_END;
                    } else {
                        (nextSegmentChunk - 1)->trackSegmentInfo |= TRACK_CHUNK_JOIN_PREVIOUS_END;
                    }
                } else if (t == segment->nextJoinStartTValue) {
                    nextSegmentChunk->trackSegmentInfo |= TRACK_CHUNK_JOIN_NEXT_START;
                    if (!(nextSegmentChunk->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
                        nextSegmentChunk->trackSegmentInfo =
                            (nextSegmentChunk->trackSegmentInfo & ~TRACK_TYPE_MASK) | 1;
                    }
                }
            } else {
                if (t < segment->previousJoinEndTValue) {
                    nextSegmentChunk->trackSegmentInfo |= TRACK_JOIN_PREVIOUS;
                    sp274 = (segment->length * lengthProportionAlongSegment) / joinLengths;
                } else {
                    nextSegmentChunk->trackSegmentInfo |= TRACK_JOIN_NEXT;
                    sp274 = (segment->length - (segment->length * lengthProportionAlongSegment)) / joinLengths;
                }
                sp110.pos = *segmentPos;

                Course_ChunkCalculateRoadAirReferencePos(
                    &sp110, radiusLeft, radiusRight, &segmentBasis, &currentChunkLeftPos, &currentChunkRightPos,
                    &currentChunkTopPos, &currentChunkBottomPos, &currentChunkCenterPos);
                sSegmentChunkJoinFuncs[TRACK_SHAPE_INDEX((u32) (segment->trackSegmentInfo & TRACK_SHAPE_MASK))](
                    &sp110, nextSegmentChunk, sp274);
            }

            if ((t != 0.0f) && (t != segment->previousJoinEndTValue) && (t != segment->nextJoinStartTValue) &&
                (var_fs3 < D_800F89E4)) {
                nextSegmentChunk->trackSegmentInfo |= TRACK_FLAG_CONTINUOUS;
                var_fs3 = 0.0f;
            } else {
                nextSegmentChunk->trackSegmentInfo &= ~TRACK_FLAG_CONTINUOUS;

                var_fs3 = 0.0f;
                if (t == 0.0f) {
                    if (segment->prev->trackSegmentInfo & TRACK_JOIN_NEXT) {

                        nextSegmentChunk->trackSegmentInfo |= TRACK_JOIN_NEXT;
                        if (((nextSegmentChunk - 1)->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_CYLINDER) {
                            (nextSegmentChunk - 1)->trackSegmentInfo =
                                (s32) (((nextSegmentChunk - 1)->trackSegmentInfo & ~TRACK_FLAG_CONTINUOUS) |
                                       TRACK_CHUNK_JOIN_NEXT_FINISH);
                        } else {
                            (nextSegmentChunk - 1)->trackSegmentInfo |= TRACK_CHUNK_JOIN_NEXT_FINISH;
                        }
                    }

                    if (nextSegmentChunk->trackSegmentInfo & TRACK_JOIN_PREVIOUS) {
                        nextSegmentChunk->trackSegmentInfo |= TRACK_CHUNK_JOIN_PREVIOUS_START;
                    }
                    nextSegmentChunk->trackSegmentInfo |= TRACK_FLAG_80000000;
                    nextSegmentChunk->leftTextureCorrection = nextSegmentChunk->rightTextureCorrection =
                        nextSegmentChunk->topTextureCorrection = nextSegmentChunk->bottomTextureCorrection = -0x8000;
                    leftFaceDistance = rightFaceDistance = topFaceDistance = bottomFaceDistance = 0.0f;
                }
            }

            if (++gSegmentChunkCount == 0x400) {
                spB4 |= 0x20000;
            } else {
                segmentChunk = nextSegmentChunk;
                nextSegmentChunk++;
            }
        }
    }

    leftFaceDistance += Course_ChunkPositionDistance(&courseStartLeftPos, &previousChunkLeftPos);
    rightFaceDistance += Course_ChunkPositionDistance(&courseStartRightPos, &previousChunkRightPos);
    topFaceDistance += Course_ChunkPositionDistance(&courseStartTopPos, &previousChunkTopPos);
    bottomFaceDistance += Course_ChunkPositionDistance(&courseStartBottomPos, &previousChunkBottomPos);
    leftTextureCoord = func_800A18FC(trackSegmentInfo, leftFaceDistance);
    rightTextureCoord = func_800A18FC(trackSegmentInfo, rightFaceDistance);
    topTextureCoord = func_800A18FC(trackSegmentInfo, topFaceDistance);
    bottomTextureCoord = func_800A18FC(trackSegmentInfo, bottomFaceDistance);
    if ((leftTextureCoord < 0x8000) && (rightTextureCoord < 0x8000) && (topTextureCoord < 0x8000) &&
        (bottomTextureCoord < 0x8000)) {
        gSegmentChunks[0].leftTextureCoord = leftTextureCoord;
        gSegmentChunks[0].rightTextureCoord = rightTextureCoord;
        gSegmentChunks[0].topTextureCoord = topTextureCoord;
        gSegmentChunks[0].bottomTextureCoord = bottomTextureCoord;
    } else {
        segmentChunk->trackSegmentInfo =
            (segmentChunk->trackSegmentInfo & ~TRACK_FLAG_CONTINUOUS) | TRACK_FLAG_80000000;
        temp_a3 = &D_800CF8C8[TRACK_SHAPE_INDEX((u32) trackSegmentInfo & TRACK_SHAPE_MASK)]
                             [trackSegmentInfo & TRACK_TYPE_MASK];
        var_v1 = temp_a3->textureCoordinateMask;

        segmentChunk->leftTextureCorrection = (segmentChunk->leftTextureCoord & var_v1) - 0x8000;
        gSegmentChunks[0].leftTextureCoord =
            (leftTextureCoord - segmentChunk->leftTextureCoord) + segmentChunk->leftTextureCorrection;

        segmentChunk->rightTextureCorrection = (segmentChunk->rightTextureCoord & var_v1) - 0x8000;
        gSegmentChunks[0].rightTextureCoord =
            (rightTextureCoord - segmentChunk->rightTextureCoord) + segmentChunk->rightTextureCorrection;

        segmentChunk->topTextureCorrection = (segmentChunk->topTextureCoord & var_v1) - 0x8000;
        gSegmentChunks[0].topTextureCoord =
            (topTextureCoord - segmentChunk->topTextureCoord) + segmentChunk->topTextureCorrection;

        segmentChunk->bottomTextureCorrection = (segmentChunk->bottomTextureCoord & var_v1) - 0x8000;
        gSegmentChunks[0].bottomTextureCoord =
            (bottomTextureCoord - segmentChunk->bottomTextureCoord) + segmentChunk->bottomTextureCorrection;
    }
    if (nextSegment->prev->trackSegmentInfo & TRACK_JOIN_NEXT) {
        if ((segmentChunk->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_CYLINDER) {
            segmentChunk->trackSegmentInfo =
                (segmentChunk->trackSegmentInfo & ~TRACK_FLAG_CONTINUOUS) | TRACK_CHUNK_JOIN_NEXT_FINISH;
        } else {
            segmentChunk->trackSegmentInfo |= TRACK_CHUNK_JOIN_NEXT_FINISH;
        }
    }

    sLastSegmentChunk = &gSegmentChunks[gSegmentChunkCount];
    gSegmentChunks[gSegmentChunkCount] = gSegmentChunks[0];
    return spB4;
}

Vtx* func_800A2BDC(Vtx* vtx, Vec3f* arg1, Mtx3F* arg2) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    temp_fs0 = arg2->y.x * 115.47f;
    temp_fs1 = arg2->y.y * 115.47f;
    temp_fs2 = arg2->y.z * 115.47f;
    sp40 = arg2->z.x * 200.0f;
    sp3C = arg2->z.y * 200.0f;
    sp38 = arg2->z.z * 200.0f;

    vtx->v.ob[0] = Math_Round(arg1->x + temp_fs0 + temp_fs0);
    vtx->v.ob[1] = Math_Round(arg1->y + temp_fs1 + temp_fs1);
    vtx->v.ob[2] = Math_Round(arg1->z + temp_fs2 + temp_fs2);
    vtx++;
    vtx->v.ob[0] = Math_Round((temp_fs0 = arg1->x - temp_fs0) + sp40);
    vtx->v.ob[1] = Math_Round((temp_fs1 = arg1->y - temp_fs1) + sp3C);
    vtx->v.ob[2] = Math_Round((temp_fs2 = arg1->z - temp_fs2) + sp38);
    vtx++;
    vtx->v.ob[0] = Math_Round(temp_fs0 - sp40);
    vtx->v.ob[1] = Math_Round(temp_fs1 - sp3C);
    vtx->v.ob[2] = Math_Round(temp_fs2 - sp38);
    vtx++;

    return vtx;
}

s32 func_800A2D2C(CourseInfo* arg0, Vtx* arg1) {
    CourseSegment* var_s0;
    f32 spD0;
    f32 var_fs1;
    f32 var_fs2;
    Vec3f spBC;
    Vec3f spB0;
    Vec3f spA4;
    Mtx3F sp80;
    s32 var_s2;
    Vtx* var_s3;

    D_800F89E8 = 3000.0f;
    var_s0 = arg0->courseSegments;
    var_fs1 = 0.0f;
    var_fs2 = Course_SplineGetBasis(var_s0, 0.0f, &sp80, 0.0f);
    Course_SplineGetPosition(var_s0, 0.0f, &spA4);
    var_s3 = func_800A2BDC(arg1, &spA4, &sp80);
    spBC.x = sp80.x.x;
    spBC.y = sp80.x.y;
    spBC.z = sp80.x.z;
    spB0 = spA4;
    var_s2 = 3;

    while (true) {
        var_fs1 += 300.0f / var_fs2;
        if (var_fs1 >= 1.0f) {
            var_s0 = var_s0->next;
            var_fs1 -= 1.0f;
            if (var_s0 != arg0->courseSegments) {
                var_fs1 *= (var_fs2 / Course_SplineGetTangent(var_s0, 0.0f, &spA4));
            } else {
                break;
            }
        }

        var_fs2 = Course_SplineGetBasis(var_s0, var_fs1, &sp80, Course_SplineGetLengthInfo(var_s0, var_fs1, &spD0));
        Course_SplineGetPosition(var_s0, var_fs1, &spA4);
        if (func_800A1818(&spB0, &spBC, &spA4) != 0) {

            spBC.x = spA4.x - spB0.x;
            spBC.y = spA4.y - spB0.y;
            spBC.z = spA4.z - spB0.z;

            spD0 = SQ_SUM(&spBC);
            spD0 = 1.0f / sqrtf(spD0);
            spB0 = spA4;

            var_s2 += 3;

            spBC.x *= spD0;
            spBC.y *= spD0;
            spBC.z *= spD0;

            if (var_s2 < 0xC00) {
                var_s3 = func_800A2BDC(var_s3, &spA4, &sp80);
                continue;
            }
            return 0;
        }
    }

    var_s2 += 3;

    if (var_s2 < 0xC00) {
        var_s3[0] = arg1[0];
        var_s3[1] = arg1[1];
        var_s3[2] = arg1[2];
        return var_s2;
    } else {
        return 0;
    }
}

extern s32 gRandSeed1;
extern s32 gRandMask1;
extern s32 gRandSeed2;
extern s32 gRandMask2;
extern s8 gTitleDemoState;
extern s32 gGameMode;

void Course_GenerateRandomCourse(void) {
    s32 var_s4;
    s32 temp_s3;
    s32 var_s6;
    s32 sp108;
    s32 sp104;
    CourseSegment* var_s0;
    CourseSegment* var_s1;
    CourseSegment* var_s2;
    ControlPoint* var_s1_2;
    ControlPoint* var_s0_4;
    ControlPoint* var_s3;
    f32 spE8;
    s32 temp_a0;
    s32 temp_s2;
    f32 var_fs4;
    f32 temp_fs5;
    Vec3f spCC;
    f32 temp_fs3;
    f32 temp_fs2;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_ft5;
    s32* spB4;
    ControlPoint* spB0;
    f32 var_fs0;
    f32 var_fs1;

    // Restore random generation seeding if track is re-done
    if ((gGameMode == GAMEMODE_GP_RACE) && (gTitleDemoState == TITLE_DEMO_INACTIVE) &&
        (gCourseIndex == gLastRandomCourseIndex)) {
        Math_Rand1Init(sRandomCourseInitSeed1, sRandomCourseInitMask1);
        Math_Rand2Init(sRandomCourseInitSeed2, sRandomCourseInitMask2);
    }
    gLastRandomCourseIndex = gCourseIndex;
    sRandomCourseInitSeed1 = gRandSeed1;
    sRandomCourseInitMask1 = gRandMask1;
    sRandomCourseInitSeed2 = gRandSeed2;
    sRandomCourseInitMask2 = gRandMask2;
    do {
    loop_start:
        do {
            if ((Math_Rand1() & 0x1FFFF) < 0x38E3) {
                if ((Math_Rand2() & 0x1FFFF) < 0x7FFF) {
                    sp108 = 3;
                } else if ((Math_Rand2() & 0x1FFFF) < 0xFFFF) {
                    sp108 = 2;
                } else {
                    sp108 = 1;
                }
            } else {
                sp108 = 0;
            }

            switch (sp108) {
                case 0:
                case 3:
                    D_800CF510 = 1000.0f;
                    D_800CF514 = 10000.0f;
                    D_800CF518 = D_800CF998[Math_Rand1() & 3];
                    var_s4 = 9;
                    break;
                default:
                    D_800CF510 = 6000.0f;
                    D_800CF514 = 2500.0f;
                    D_800CF518 = 2500.0f;
                    var_s4 = 6;
                    break;
            }

            gCurrentCourseInfo->segmentCount = ((Math_Rand2() & 0x1FFFF) % 5) + var_s4;
            var_s4 = (gCurrentCourseInfo->segmentCount * 3) + 1;
            var_s0 = var_s4 + gCurrentCourseInfo->courseSegments;
            var_s1 = gCurrentCourseInfo->courseSegments;
            do {
                var_s0->segmentIndex = var_s4;
                var_s0->prev = var_s0 - 1;
                var_s0->next = var_s1;
                var_s1 = var_s0;
                var_s0--;
                var_s4--;
            } while (var_s4 >= 0);

            var_fs4 = D_800CF514 / 131071.0f;
            spE8 = 4096.0f / gCurrentCourseInfo->segmentCount;
            temp_fs5 = D_800CF518 / 131071.0f;

            gCurrentCourseInfo->segmentCount = (gCurrentCourseInfo->segmentCount * 3) + 2;

            do {
                gCurrentCourseInfo->segmentCount = (gCurrentCourseInfo->segmentCount - 2) / 3;

                gCurrentCourseInfo->courseSegments[0].prev =
                    &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];
                gCurrentCourseInfo->courseSegments[0].prev->next = &gCurrentCourseInfo->courseSegments[0];
                temp_fs2 = 1.0f / (131071.0f * 5.0f);

                do {
                    var_fs1 = 0.0f;
                    var_s0 = gCurrentCourseInfo->courseSegments[0].prev;

                    do {

                        var_fs0 = ((Math_Rand2() & 0x1FFFF) * var_fs4) + D_800CF510;

                        temp_a0 = ((((Math_Rand1() & 0x1FFFF) * temp_fs2) + var_fs1) * spE8);
                        var_s0->pos.x = COS(temp_a0) * var_fs0;
                        var_s0->pos.z = SIN(temp_a0) * var_fs0;
                        var_s0->pos.y = (f32) ((Math_Rand2() & 0x1FFFF) * temp_fs5);

                        var_s0--;
                        var_fs1 += 1.0f;
                    } while (var_s0 >= gCurrentCourseInfo->courseSegments);
                } while (Course_SplineCalculateTensions(gCurrentCourseInfo) != 0);

                var_s1_2 = COURSE_CONTEXT()->courseData.controlPoint;
                var_s0 = gCurrentCourseInfo->courseSegments;

                do {
                    Course_SplineGetPosition(var_s0, 0.333333f, &spCC);
                    var_s1_2->pos = spCC;
                    var_s1_2++;
                    Course_SplineGetPosition(var_s0, 0.666667f, &spCC);
                    var_s1_2->pos = spCC;
                    var_s0 = var_s0->next;
                    var_s1_2++;
                    var_s1_2->pos = var_s0->pos;
                    var_s1_2++;
                } while (var_s0 != gCurrentCourseInfo->courseSegments);

                var_s1_2 -= 3;
                var_fs1 = 0.0f;
                var_s0_4 = var_s1_2 + 1;

                do {
                    temp_fs2 = var_s0_4->pos.x - var_s1_2->pos.x;
                    temp_ft5 = var_s0_4->pos.y - var_s1_2->pos.y;
                    temp_fs3 = var_s0_4->pos.z - var_s1_2->pos.z;
                    temp_fv0 = SQ(temp_fs2) + SQ(temp_ft5) + SQ(temp_fs3);
                    if (var_fs1 < temp_fv0) {
                        var_fs1 = temp_fv0;
                        spB0 = var_s1_2;
                    }
                    var_s1_2 -= 3;
                    var_s0_4 -= 3;
                } while (var_s1_2 >= COURSE_CONTEXT()->courseData.controlPoint);

                var_s0_4 = spB0 + 1;
                spCC.x = (spB0->pos.x + var_s0_4->pos.x) * 0.5f;
                spCC.y = (spB0->pos.y + var_s0_4->pos.y) * 0.5f;
                spCC.z = (spB0->pos.z + var_s0_4->pos.z) * 0.5f;
                temp_fv0 = sqrtf(var_fs1);
                temp_fv1 = 1587.5f / temp_fv0;
                temp_fs2 = (var_s0_4->pos.x - spB0->pos.x) * temp_fv1;
                temp_ft5 = (var_s0_4->pos.y - spB0->pos.y) * temp_fv1;
                temp_fs3 = (var_s0_4->pos.z - spB0->pos.z) * temp_fv1;

                if (temp_fv0 < 5000.0f) {
                    var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount * 3 - 1];
                    temp_fv1 = 3.1496062f - (temp_fv0 / 1587.5f);

                    do {
                        if ((((var_s1_2->pos.x - spCC.x) * temp_fs2) + ((var_s1_2->pos.y - spCC.y) * temp_ft5) +
                             ((var_s1_2->pos.z - spCC.z) * temp_fs3)) < 0.0f) {
                            var_s1_2->pos.x -= (temp_fv1 * temp_fs2);
                            var_s1_2->pos.y -= (temp_fv1 * temp_ft5);
                            var_s1_2->pos.z -= (temp_fv1 * temp_fs3);
                        }
                        var_s1_2--;
                    } while (var_s1_2 >= COURSE_CONTEXT()->courseData.controlPoint);
                    spCC.x -= (temp_fv1 * temp_fs2) * 0.5f;
                    spCC.y -= (temp_fv1 * temp_ft5) * 0.5f;
                    spCC.z -= (temp_fv1 * temp_fs3) * 0.5f;
                }
                gCurrentCourseInfo->segmentCount = (gCurrentCourseInfo->segmentCount * 3) + 2;

                gCurrentCourseInfo->courseSegments[0].prev->next = gCurrentCourseInfo->courseSegments[0].prev + 1;
                gCurrentCourseInfo->courseSegments[0].prev =
                    &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];
                gCurrentCourseInfo->courseSegments[0].prev->next = &gCurrentCourseInfo->courseSegments[0];

                var_s1_2 = spB0;
                var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];

                do {
                    var_s0->pos = var_s1_2->pos;
                    var_s0--;
                    if (--var_s1_2 < COURSE_CONTEXT()->courseData.controlPoint) {
                        var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 3];
                    }
                } while (var_s1_2 != spB0);

                var_s0->pos.x = spCC.x + temp_fs2;
                var_s0->pos.y = spCC.y + temp_ft5;
                var_s0->pos.z = spCC.z + temp_fs3;
                var_s0--;
                var_s0->pos.x = spCC.x - temp_fs2;
                var_s0->pos.y = spCC.y - temp_ft5;
                var_s0->pos.z = spCC.z - temp_fs3;
            } while (Course_SplineCalculateTensions(gCurrentCourseInfo) != 0);

            var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];

            do {
                var_s1 = var_s0->next;
                if ((SQ(var_s0->pos.x - var_s1->pos.x) + SQ(var_s0->pos.y - var_s1->pos.y) +
                     SQ(var_s0->pos.z - var_s1->pos.z)) < 8500.0f) {
                    break;
                }
                var_s0--;
            } while (var_s0 >= gCurrentCourseInfo->courseSegments);

            if (var_s0 >= gCurrentCourseInfo->courseSegments) {
                goto loop_start;
            }

            spE8 = 0.0f;
            var_fs4 = 5000.0f;
            var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];

            do {
                if (var_s0->pos.y < var_fs4) {
                    var_fs4 = var_s0->pos.y;
                }
                if (spE8 < var_s0->pos.y) {
                    spE8 = var_s0->pos.y;
                }
                var_s0--;
            } while (var_s0 >= gCurrentCourseInfo->courseSegments);

            var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];

            do {
                var_s0->pos.y += (0 - var_fs4) + ((spE8 - var_fs4) * 0.5f);
                var_s0--;
            } while (var_s0 >= gCurrentCourseInfo->courseSegments);

            sp104 = Math_Rand1() % 2;
            switch (sp108) {
                case 0:
                    var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];
                    do {
                        var_s1 = var_s0->next;
                        var_s2 = var_s0->prev;

                        temp_fs2 = var_s1->pos.x - var_s0->pos.x;
                        temp_fs3 = var_s1->pos.z - var_s0->pos.z;
                        spCC.x = var_s0->pos.x - var_s2->pos.x;
                        spCC.z = var_s0->pos.z - var_s2->pos.z;

                        var_fs0 = ((spCC.x * temp_fs3) - (spCC.z * temp_fs2)) /
                                  sqrtf((SQ(spCC.x) + SQ(spCC.z)) * (SQ(temp_fs2) + SQ(temp_fs3)));

                        if (((spCC.x * temp_fs2) + (spCC.z * temp_fs3)) < 0.0f) {
                            if (var_fs0 < 0.0f) {
                                var_fs0 = -1.0f;
                            } else {
                                var_fs0 = 1.0f;
                            }
                        }
                        var_fs1 = ((SQ(var_fs0) * 100.0f) + 500.0f) - 200.0f;
                        if (sp104 != 0) {
                            var_s2 = var_s1;
                        }
                        var_s0--;

                        var_s2->radiusLeft = ((0.5f - (SQ(var_fs0) * var_fs0 * 0.5f)) * var_fs1) + 100.0f;
                        var_s2->radiusRight = (((SQ(var_fs0) * var_fs0 * 0.5f) + 0.5f) * var_fs1) + 100.0f;

                    } while (var_s0 >= gCurrentCourseInfo->courseSegments);

                    gCurrentCourseInfo->courseSegments[0].radiusLeft =
                        gCurrentCourseInfo->courseSegments[0].radiusRight =
                            gCurrentCourseInfo->courseSegments[1].radiusLeft =
                                gCurrentCourseInfo->courseSegments[1].radiusRight =
                                    (gCurrentCourseInfo->courseSegments[0].radiusLeft +
                                     gCurrentCourseInfo->courseSegments[0].radiusRight +
                                     gCurrentCourseInfo->courseSegments[1].radiusLeft +
                                     gCurrentCourseInfo->courseSegments[1].radiusRight) /
                                    4.0f;
                    break;
                case 3:
                    var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];
                    do {
                        var_s1 = var_s0->next;
                        var_s2 = var_s0->prev;

                        temp_fs2 = var_s1->pos.x - var_s0->pos.x;
                        temp_fs3 = var_s1->pos.z - var_s0->pos.z;
                        spCC.x = var_s0->pos.x - var_s2->pos.x;
                        spCC.z = var_s0->pos.z - var_s2->pos.z;
                        var_fs0 = ((spCC.x * temp_fs3) - (spCC.z * temp_fs2)) /
                                  sqrtf((SQ(spCC.x) + SQ(spCC.z)) * (SQ(temp_fs2) + SQ(temp_fs3)));

                        if (((spCC.x * temp_fs2) + (spCC.z * temp_fs3)) < 0.0f) {
                            if (var_fs0 < 0.0f) {
                                var_fs0 = -1.0f;
                            } else {
                                var_fs0 = 1.0f;
                            }
                        }
                        if (sp104 != 0) {
                            var_s2 = var_s1;
                        }
                        var_s0--;
                        var_s2->radiusLeft = var_s2->radiusRight = (SQ(var_fs0) * 50.0f) + 200.0f;

                    } while (var_s0 >= gCurrentCourseInfo->courseSegments);
                    gCurrentCourseInfo->courseSegments[0].radiusLeft =
                        gCurrentCourseInfo->courseSegments[0].radiusRight =
                            gCurrentCourseInfo->courseSegments[1].radiusLeft =
                                gCurrentCourseInfo->courseSegments[1].radiusRight =
                                    (gCurrentCourseInfo->courseSegments[0].radiusLeft +
                                     gCurrentCourseInfo->courseSegments[1].radiusLeft) *
                                    0.5f;
                    break;
                default:
                    var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];
                    do {
                        var_s0->radiusRight = 250.0f;
                        var_s0->radiusLeft = 250.0f;
                        var_s0--;
                    } while (var_s0 >= gCurrentCourseInfo->courseSegments);
                    break;
            }

            COURSE_CONTEXT()->courseData.creatorId = CREATOR_NINTENDO;
            COURSE_CONTEXT()->courseData.controlPointCount = gCurrentCourseInfo->segmentCount;
            COURSE_CONTEXT()->courseData.venue = (Math_Rand2() & 0x1FFFF) % 10;
            COURSE_CONTEXT()->courseData.skybox = (Math_Rand1() & 0x1FFFF) % 8;
            COURSE_CONTEXT()->courseData.flag = 1;

            switch (Math_Rand1() & 3) {
                case 0: // ROAD GROUP 1
                    spB4 = D_800CF9A8;
                    break;
                case 1: // ROAD GROUP 2
                    spB4 = D_800CF9B4;
                    break;
                case 2: // ROAD GROUP 3
                    spB4 = D_800CF9C0;
                    break;
                case 3: // ROAD GROUP 4
                    spB4 = D_800CF9CC;
                    break;
            }
            var_s6 = 0;
            var_s4 = COURSE_CONTEXT()->courseData.controlPointCount - 1;
            if (sp104 != 0) {
                var_s0 = gCurrentCourseInfo->courseSegments[0].prev;
            } else {
                var_s0 = gCurrentCourseInfo->courseSegments[1].next;
            }

            do {
                var_s3 = &COURSE_CONTEXT()->courseData.controlPoint[var_s4];
                var_s3->pos = var_s0->pos;
                var_s3->radiusLeft = var_s0->radiusLeft;
                var_s3->radiusRight = var_s0->radiusRight;
                var_s3->trackSegmentInfo = spB4[var_s6];
                var_s6++;
                if (var_s6 >= 3) {
                    var_s6 = 0;
                }

                COURSE_CONTEXT()->courseData.bankAngle[var_s4] = 0;
                COURSE_CONTEXT()->courseData.pit[var_s4] = PIT_NONE;
                COURSE_CONTEXT()->courseData.dash[var_s4] = DASH_NONE;
                COURSE_CONTEXT()->courseData.dirt[var_s4] = DIRT_NONE;
                COURSE_CONTEXT()->courseData.ice[var_s4] = ICE_NONE;
                COURSE_CONTEXT()->courseData.jump[var_s4] = JUMP_NONE;
                COURSE_CONTEXT()->courseData.landmine[var_s4] = LANDMINE_NONE;
                COURSE_CONTEXT()->courseData.gate[var_s4] = GATE_NONE;
                COURSE_CONTEXT()->courseData.building[var_s4] = BUILDING_NONE;
                COURSE_CONTEXT()->courseData.sign[var_s4] = SIGN_NONE;

                if (sp104 != 0) {
                    var_s0 = var_s0->prev;
                } else {
                    var_s0 = var_s0->next;
                }
                var_s4--;
            } while (var_s4 >= 0);

            // Override for start line
            COURSE_CONTEXT()->courseData.controlPoint[0].trackSegmentInfo =
                TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_START_LINE;
            COURSE_CONTEXT()->courseData.gate[1] = GATE_START;
            COURSE_CONTEXT()->courseData.controlPoint[1].trackSegmentInfo =
                COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 1].trackSegmentInfo =
                    spB4[1];
            COURSE_CONTEXT()->courseData.controlPoint[3].trackSegmentInfo =
                COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 3].trackSegmentInfo =
                    spB4[0];

            if (((sp108 == 0) || (sp108 == 3)) && ((Math_Rand1() & 0x1FFFF) >= 0x8000)) {
                temp_a0 = Math_Rand2() & 3;
                var_fs1 = D_800CF988[temp_a0];
                if ((temp_a0 < 2) && ((Math_Rand1() & 0x1FFFF) >= 0x10000)) {
                    var_s6 = 0;
                } else {
                    var_s6 = 1;
                }

                var_s4 = gCurrentCourseInfo->segmentCount - 4;

                do {
                    var_s3 = &COURSE_CONTEXT()->courseData.controlPoint[var_s4];
                    var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[var_s4 + 1];
                    spB0 = &COURSE_CONTEXT()->courseData.controlPoint[var_s4 - 1];
                    spCC.x = var_s1_2->pos.x - var_s3->pos.x;
                    spCC.z = var_s1_2->pos.z - var_s3->pos.z;

                    temp_fv0 = sqrtf(SQ(spCC.x) + SQ(spCC.z));
                    spCC.x /= temp_fv0;
                    spCC.z /= temp_fv0;

                    temp_fs2 = var_s3->pos.x - spB0->pos.x;
                    temp_fs3 = var_s3->pos.z - spB0->pos.z;
                    temp_fv0 = sqrtf(SQ(temp_fs2) + SQ(temp_fs3));

                    temp_fs2 /= temp_fv0;
                    temp_fs3 /= temp_fv0;

                    var_fs0 = (spCC.x * temp_fs2) + (spCC.z * temp_fs3);
                    if (var_fs0 < 0.0f) {
                        var_fs0 = 0.0f;
                    }
                    if ((temp_fs2 * spCC.z) < (spCC.x * temp_fs3)) {
                        if (var_s6 != 0) {
                            COURSE_CONTEXT()->courseData.bankAngle[var_s4] =
                                360 - (s32) ((1.0f - SQ(var_fs0)) * var_fs1);
                        } else {
                            COURSE_CONTEXT()->courseData.bankAngle[var_s4] = (s32) ((1.0f - SQ(var_fs0)) * var_fs1);
                        }
                    } else if (var_s6 != 0) {
                        COURSE_CONTEXT()->courseData.bankAngle[var_s4] = (s32) ((1.0f - SQ(var_fs0)) * var_fs1);
                    } else {
                        COURSE_CONTEXT()->courseData.bankAngle[var_s4] = 360 - (s32) ((1.0f - SQ(var_fs0)) * var_fs1);
                    }
                    var_s4--;
                } while (var_s4 > 1);
            }

            if (sp108 == 0) {
                if (1) {}
                var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 4];
                do {
                    var_s0_4 = var_s1_2 + 1;
                    if (((Math_Rand1() & 0x1FFFF) < 0x1112) &&
                        ((var_s1_2 - 1)->trackSegmentInfo & TRACK_FLAG_JOINABLE)) {
                        if ((var_s0_4 + 1)->trackSegmentInfo & TRACK_FLAG_JOINABLE) {
                            var_s1_2->trackSegmentInfo = var_s0_4->trackSegmentInfo =
                                D_800CF9D8[(Math_Rand1() & 0x1FFFF) % 3];
                        }
                    }
                    var_s1_2 -= 3;
                } while (var_s1_2 >= &COURSE_CONTEXT()->courseData.controlPoint[4]);

                var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 3];
                do {
                    var_s0_4 = var_s1_2 + 1;
                    if (((Math_Rand1() & 0x1FFFF) < 0x1112) &&
                        ((var_s1_2 - 1)->trackSegmentInfo & TRACK_FLAG_JOINABLE)) {
                        if ((var_s0_4 + 1)->trackSegmentInfo & TRACK_FLAG_JOINABLE) {
                            var_s1_2->trackSegmentInfo = var_s0_4->trackSegmentInfo =
                                D_800CF9E4[(Math_Rand1() & 0x1FFFF) % 3];
                        }
                    }
                    var_s1_2 -= 3;
                } while (var_s1_2 >= &COURSE_CONTEXT()->courseData.controlPoint[2]);

                if ((Math_Rand2() & 0x1FFFF) < 0xFFFF) {
                    var_s1_2 =
                        &COURSE_CONTEXT()
                             ->courseData
                             .controlPoint[((Math_Rand1() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 1)) + 1];
                    var_s0_4 =
                        &COURSE_CONTEXT()
                             ->courseData
                             .controlPoint[((Math_Rand2() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 1)) + 1];
                    if ((var_s1_2 < var_s0_4) && ((var_s1_2 - 1)->trackSegmentInfo & TRACK_FLAG_JOINABLE) &&
                        ((var_s0_4 + 1)->trackSegmentInfo & TRACK_FLAG_JOINABLE)) {
                        var_s6 = Math_Rand1() & 3;
                        temp_s2 = D_800CF9F0[var_s6];
                        temp_a0 = D_800CF9F0[(((Math_Rand2() & 0x1FFFF) % 3) + var_s6 + 1) & 3];
                        spB0 = var_s1_2;
                        do {
                            spB0->trackSegmentInfo = temp_s2;
                            spB0++;
                        } while (spB0 <= var_s0_4);

                        var_s4 = (s32) (var_s0_4 - var_s1_2) / 3;
                        while (var_s4 != 0) {
                            var_s4--;
                            (var_s1_2 + var_s4)->trackSegmentInfo = (var_s0_4 - var_s4)->trackSegmentInfo = temp_a0;
                        }
                    }
                }

                // Ensure there are pit zones
                COURSE_CONTEXT()->courseData.pit[gCurrentCourseInfo->segmentCount - 3] =
                    COURSE_CONTEXT()->courseData.pit[gCurrentCourseInfo->segmentCount - 4] = PIT_BOTH;
            } else {
                if (sp108 == 1) { // PIPE
                    spB4 = D_800CFA10;
                } else if (sp108 == 2) { // CYLINDER
                    spB4 = D_800CFA20;
                } else { // HALF PIPE
                    spB4 = D_800CFA00;
                }
                var_s6 = Math_Rand2() & 3;
                temp_s3 = ((Math_Rand1() & 0x1FFFF) % 3) + 1;
                var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[2];
                var_s0_4 = &COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 5];

                var_s4 = 4;
                do {
                    if (var_s0_4 >= var_s1_2) {
                        var_fs1 = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 200.0f) + 100.0f;

                        if (sp108 == 2) {
                            var_fs1 += 30.0f;
                        }
                        temp_s2 = spB4[var_s6];
                        if (sp108 == 3) {
                            do {
                                var_s1_2->trackSegmentInfo = temp_s2;
                                var_s1_2++;
                            } while (var_s1_2 < var_s0_4);
                        } else {
                            do {
                                var_s1_2->trackSegmentInfo = temp_s2;
                                var_s1_2->radiusLeft = var_s1_2->radiusRight = var_fs1;
                                var_s1_2++;
                            } while (var_s1_2 < var_s0_4);
                        }
                        var_s1_2->trackSegmentInfo = temp_s2;
                    }
                    var_s6 = (var_s6 + temp_s3) & 3;
                    var_s1_2 =
                        &COURSE_CONTEXT()
                             ->courseData
                             .controlPoint[((Math_Rand1() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 6)) + 2];
                    var_s0_4 =
                        &COURSE_CONTEXT()
                             ->courseData
                             .controlPoint[((Math_Rand2() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 6)) + 2];
                    var_s4--;
                } while (var_s4 > 0);
                // Ensure there are pit zones
                COURSE_CONTEXT()->courseData.pit[gCurrentCourseInfo->segmentCount - 1] =
                    COURSE_CONTEXT()->courseData.pit[gCurrentCourseInfo->segmentCount - 2] = PIT_BOTH;
            }
            temp_s3 = Math_Rand1() & 7;
            while (temp_s3 != 0) {
                do {
                    var_s4 = ((Math_Rand2() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 6)) + 2;
                    if (COURSE_CONTEXT()->courseData.controlPoint[var_s4].trackSegmentInfo & TRACK_FLAG_8000000) {
                        break;
                    }
                } while (COURSE_CONTEXT()
                             ->courseData
                             .controlPoint[((var_s4 + gCurrentCourseInfo->segmentCount) - 1) %
                                           gCurrentCourseInfo->segmentCount]
                             .trackSegmentInfo !=
                         COURSE_CONTEXT()
                             ->courseData.controlPoint[(var_s4 + 1) % gCurrentCourseInfo->segmentCount]
                             .trackSegmentInfo);

                COURSE_CONTEXT()->courseData.dash[var_s4] = (Math_Rand1() & 0x1FFFF) % 3;
                temp_s3--;
            }
            var_s6 = (Math_Rand1() & 0x1FFFF) % 3;

            temp_s3 = (Math_Rand2() & 7) - 1;
            while (temp_s3 >= 0) {
                var_s4 = ((Math_Rand2() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 2)) + 2;
                temp_s2 = COURSE_CONTEXT()->courseData.controlPoint[var_s4].trackSegmentInfo & TRACK_SHAPE_MASK;
                if ((temp_s2 == TRACK_SHAPE_ROAD) || (temp_s2 == TRACK_SHAPE_BORDERLESS_ROAD)) {
                    temp_s2 = COURSE_CONTEXT()->courseData.controlPoint[var_s4 - 1].trackSegmentInfo & TRACK_SHAPE_MASK;
                    if ((temp_s2 == TRACK_SHAPE_ROAD) || (temp_s2 == TRACK_SHAPE_BORDERLESS_ROAD)) {
                        if ((Math_Rand2() & 0x1FFFF) < 0xAAAA) {
                            COURSE_CONTEXT()->courseData.sign[var_s4] = (Math_Rand1() & 1) + 3;
                        } else {
                            COURSE_CONTEXT()->courseData.sign[var_s4] = var_s6;
                        }
                    }
                }
                temp_s3--;
            }
            func_80074428(gCourseIndex);
            Course_SegmentLengthsInit(gCurrentCourseInfo);
        } while (Course_SegmentJoinsInit(gCurrentCourseInfo) != 0);
    } while (func_800A1954(gCurrentCourseInfo) != 0);

    for (temp_s3 = 0; temp_s3 < 5; temp_s3++) {
        gCurrentCourseInfo->timeRecord[temp_s3] = 600000 - 1;
    }

    gCurrentCourseInfo->maxSpeed = 0.0f;
    gCurrentCourseInfo->bestTime = 600000 - 1;
}

extern CourseSegment D_802C2020[];

void func_800A4B54(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCourseInfos); i++) {
        gCourseInfos[i].courseIndex = i;
        gCourseInfos[i].courseSegments = D_802C2020;
    }
}

extern GfxPool D_8024DCE0[];

void func_800A4BAC(void) {
    Vtx* var_a0;
    Vtx* var_v1;
    s32 i;

    D_800F8958[0].unk_04 = D_80140F0;
    D_800F8958[0].unk_08 = D_8014180;
    D_800F8958[0].unk_0C = D_80140F0;
    D_800F8958[0].unk_10 = D_8014210;
    D_800F8958[0].unk_14 = D_80142C0;
    D_800F8958[0].unk_18 = D_8014308;
    D_800F8958[0].unk_1C = D_80143E0;
    D_800F8958[0].unk_20 = D_8014430;
    D_800F8958[0].unk_24 = D_8014520;
    D_800F8958[0].unk_28 = D_80145E0;
    D_800F8958[0].loadVtxIndex = 0;
    D_800F8958[1].unk_04 = D_8014138;
    D_800F8958[1].unk_08 = D_80141C8;
    D_800F8958[1].unk_0C = D_8014138;
    D_800F8958[1].unk_10 = D_8014268;
    D_800F8958[1].unk_14 = D_8014350;
    D_800F8958[1].unk_18 = D_8014398;
    D_800F8958[1].unk_1C = D_8014480;
    D_800F8958[1].unk_20 = D_80144D0;
    D_800F8958[1].unk_24 = D_8014580;
    D_800F8958[1].unk_28 = D_8014640;
    D_800F8958[1].loadVtxIndex = 8;

    var_a0 = &D_8024DCE0[0].courseVtxBuffer[0xFFF];
    var_v1 = &D_8024DCE0[1].courseVtxBuffer[0xFFF];
    // FAKE
    goto dummy;
dummy:;
    do {
        var_a0->v.cn[0] = var_a0->v.cn[1] = var_a0->v.cn[2] = var_v1->v.cn[0] = var_v1->v.cn[1] = var_v1->v.cn[2] = 0;
        var_a0->v.cn[3] = var_v1->v.cn[3] = 255;

        var_a0--;
        var_v1--;
    } while ((u32) var_v1 >= (u32) D_8024DCE0[1].courseVtxBuffer);

    func_800A4B54();
}

// Set course piece step value (and other info)
void func_800A4D0C(s32 arg0) {
    D_800F8524 = arg0;
    switch (D_800F8524) {
        case 0:
            D_800F89E0 = 300.0f;
            break;
        case 1:
            D_800F894C = 2000.0f;
            D_800F8950 = 300.0f;
            D_800F89E8 = 400.0f;
            D_800F89E0 = 20.0f;
            D_800F89E4 = 2000.0f;
            break;
        case 2:
            D_800F894C = 1500.0f;
            D_800F8950 = 100.0f;
            D_800F89E8 = 700.0f;
            D_800F89E0 = 20.0f;
            D_800F89E4 = 4000.0f;
            break;
    }
}

void func_800A4DF0(void) {

    gCurrentCourseInfo = &gCourseInfos[gCourseIndex];
    Course_Load(gCourseIndex);
    func_800747EC(COURSE_CONTEXT()->courseData.venue);
    func_8009CED0(COURSE_CONTEXT()->courseData.venue);
    func_80074634(gCurrentCourseInfo);
    Course_SplineCalculateTensions(gCurrentCourseInfo);
    if (gCurrentCourseInfo->courseIndex >= COURSE_EDIT_1) {
        gCurrentCourseInfo->encodedCourseIndex = COURSE_EDIT_1;
    } else {
        gCurrentCourseInfo->encodedCourseIndex = gCurrentCourseInfo->courseIndex;
    }
    gCurrentCourseInfo->encodedCourseIndex |= Course_CalculateChecksum() << 5;
}

extern s32 gNumPlayers;

void Course_Init(void) {
    CourseSegment* segment;

    if (gCourseIndex >= ARRAY_COUNT(gCourseInfos)) {
        gCourseIndex = ARRAY_COUNT(gCourseInfos) - 1;
    }
    if (gNumPlayers >= 3) {
        func_800A4D0C(2);
    } else {
        func_800A4D0C(1);
    }
    func_800A4DF0();
    Course_SegmentsInit();
    Course_SegmentLengthsInit(gCurrentCourseInfo);
    Course_GadgetsInit(gCourseIndex);
    Course_SegmentJoinsInit(gCurrentCourseInfo);
    Course_SegmentContinuousFlagInit(gCurrentCourseInfo);
    Course_SegmentFormsInit(gCurrentCourseInfo);
    func_800A1954(gCurrentCourseInfo);
    sCourseRenderOriginDistance = 900.0f;
    segment = gCurrentCourseInfo->courseSegments;
    do {

        if (sCourseRenderOriginDistance < segment->radiusLeft) {
            sCourseRenderOriginDistance = segment->radiusLeft;
        }

        if (sCourseRenderOriginDistance < segment->radiusRight) {
            sCourseRenderOriginDistance = segment->radiusRight;
        }
        segment = segment->next;
    } while (segment != gCurrentCourseInfo->courseSegments);
    sCourseRenderOriginDistance += 100.0f;
    sCourseFarRenderDistance = sCourseRenderOriginDistance + 4500.0f;
    D_800F894C += sCourseRenderOriginDistance - 1000.0f;
    D_800F8950 += sCourseRenderOriginDistance - 1000.0f;
}

void Course_Update(void) {
}

void Course_SetupChunkPipeTunnelVtxPos(SegmentChunk* chunk) {
    gCourseVtxPtr[0].v.ob[0] = chunk->referencePos1[0];
    gCourseVtxPtr[0].v.ob[1] = chunk->referencePos1[1];
    gCourseVtxPtr[0].v.ob[2] = chunk->referencePos1[2];
    gCourseVtxPtr[1].v.ob[0] = chunk->referencePos6[0];
    gCourseVtxPtr[1].v.ob[1] = chunk->referencePos6[1];
    gCourseVtxPtr[1].v.ob[2] = chunk->referencePos6[2];
    gCourseVtxPtr[2].v.ob[0] = chunk->referencePos7[0];
    gCourseVtxPtr[2].v.ob[1] = chunk->referencePos7[1];
    gCourseVtxPtr[2].v.ob[2] = chunk->referencePos7[2];
    gCourseVtxPtr[3].v.ob[0] = chunk->referencePos8[0];
    gCourseVtxPtr[3].v.ob[1] = chunk->referencePos8[1];
    gCourseVtxPtr[3].v.ob[2] = chunk->referencePos8[2];
    gCourseVtxPtr[4].v.ob[0] = chunk->referencePos2[0];
    gCourseVtxPtr[4].v.ob[1] = chunk->referencePos2[1];
    gCourseVtxPtr[4].v.ob[2] = chunk->referencePos2[2];
    gCourseVtxPtr[5].v.ob[0] = chunk->referencePos5[0];
    gCourseVtxPtr[5].v.ob[1] = chunk->referencePos5[1];
    gCourseVtxPtr[5].v.ob[2] = chunk->referencePos5[2];
    gCourseVtxPtr[6].v.ob[0] = chunk->referencePos4[0];
    gCourseVtxPtr[6].v.ob[1] = chunk->referencePos4[1];
    gCourseVtxPtr[6].v.ob[2] = chunk->referencePos4[2];
    gCourseVtxPtr[7].v.ob[0] = chunk->referencePos3[0];
    gCourseVtxPtr[7].v.ob[1] = chunk->referencePos3[1];
    gCourseVtxPtr[7].v.ob[2] = chunk->referencePos3[2];
    gCourseVtxPtr += 8;
}

void Course_SetupChunkDefaultVtxPos(SegmentChunk* chunk) {
    gCourseVtxPtr[0].v.tc[0] = D_800F8930[4];
    gCourseVtxPtr[1].v.tc[0] = gCourseVtxPtr[7].v.tc[0] = D_800F8930[3];
    gCourseVtxPtr[2].v.tc[0] = gCourseVtxPtr[6].v.tc[0] = D_800F8930[2];
    gCourseVtxPtr[3].v.tc[0] = gCourseVtxPtr[5].v.tc[0] = D_800F8930[1];
    gCourseVtxPtr[4].v.tc[0] = D_800F8930[0];
    gCourseVtxPtr[0].v.ob[0] = chunk->referencePos1[0];
    gCourseVtxPtr[0].v.ob[1] = chunk->referencePos1[1];
    gCourseVtxPtr[0].v.ob[2] = chunk->referencePos1[2];
    gCourseVtxPtr[1].v.ob[0] = chunk->referencePos6[0];
    gCourseVtxPtr[1].v.ob[1] = chunk->referencePos6[1];
    gCourseVtxPtr[1].v.ob[2] = chunk->referencePos6[2];
    gCourseVtxPtr[2].v.ob[0] = chunk->referencePos7[0];
    gCourseVtxPtr[2].v.ob[1] = chunk->referencePos7[1];
    gCourseVtxPtr[2].v.ob[2] = chunk->referencePos7[2];
    gCourseVtxPtr[3].v.ob[0] = chunk->referencePos8[0];
    gCourseVtxPtr[3].v.ob[1] = chunk->referencePos8[1];
    gCourseVtxPtr[3].v.ob[2] = chunk->referencePos8[2];
    gCourseVtxPtr[4].v.ob[0] = chunk->referencePos2[0];
    gCourseVtxPtr[4].v.ob[1] = chunk->referencePos2[1];
    gCourseVtxPtr[4].v.ob[2] = chunk->referencePos2[2];
    gCourseVtxPtr[5].v.ob[0] = chunk->referencePos5[0];
    gCourseVtxPtr[5].v.ob[1] = chunk->referencePos5[1];
    gCourseVtxPtr[5].v.ob[2] = chunk->referencePos5[2];
    gCourseVtxPtr[6].v.ob[0] = chunk->referencePos4[0];
    gCourseVtxPtr[6].v.ob[1] = chunk->referencePos4[1];
    gCourseVtxPtr[6].v.ob[2] = chunk->referencePos4[2];
    gCourseVtxPtr[7].v.ob[0] = chunk->referencePos3[0];
    gCourseVtxPtr[7].v.ob[1] = chunk->referencePos3[1];
    gCourseVtxPtr[7].v.ob[2] = chunk->referencePos3[2];
    gCourseVtxPtr += 8;
}

void Course_SetupChunkRoadAirVtx(SegmentChunk* chunk, s32 arg1) {
    s32 tcLeft;
    s32 tcRight;

    if (arg1 != 0) {
        tcRight = chunk->rightTextureCorrection;
        tcLeft = chunk->leftTextureCorrection;
    } else {
        tcRight = chunk->rightTextureCoord;
        tcLeft = chunk->leftTextureCoord;
    }

    gCourseVtxPtr[1].v.tc[1] = gCourseVtxPtr[2].v.tc[1] = gCourseVtxPtr[3].v.tc[1] = tcRight;
    gCourseVtxPtr[5].v.tc[1] = gCourseVtxPtr[6].v.tc[1] = gCourseVtxPtr[7].v.tc[1] = tcLeft;
    gCourseVtxPtr[0].v.tc[1] = gCourseVtxPtr[4].v.tc[1] = (tcRight + tcLeft) >> 1;
    Course_SetupChunkDefaultVtxPos(chunk);
}

void Course_SetupChunkPipeTunnelVtx(SegmentChunk* chunk, s32 arg1) {
    s32 tcBottom;
    s32 tcRight;
    s32 tcLeft;
    s32 tcTop;

    if (arg1 != 0) {
        tcRight = chunk->rightTextureCorrection;
        tcLeft = chunk->leftTextureCorrection;
        tcTop = chunk->topTextureCorrection;
        tcBottom = chunk->bottomTextureCorrection;
    } else {
        tcRight = chunk->rightTextureCoord;
        tcLeft = chunk->leftTextureCoord;
        tcTop = chunk->topTextureCoord;
        tcBottom = chunk->bottomTextureCoord;
    }
    if (chunk->trackSegmentInfo & TRACK_JOIN_MASK) {
        gCourseVtxPtr[0].v.tc[1] = gCourseVtxPtr[4].v.tc[1] = tcBottom;
        gCourseVtxPtr[1].v.tc[1] = gCourseVtxPtr[3].v.tc[1] = (tcBottom + tcRight) >> 1;
        gCourseVtxPtr[2].v.tc[1] = tcRight;
        gCourseVtxPtr[6].v.tc[1] = tcLeft;
        gCourseVtxPtr[7].v.tc[1] = gCourseVtxPtr[5].v.tc[1] = (tcLeft + tcBottom) >> 1;
        gCourseVtxPtr[0].v.tc[0] = D_800F8930[4];
        gCourseVtxPtr[1].v.tc[0] = gCourseVtxPtr[7].v.tc[0] = D_800F8930[3];
        gCourseVtxPtr[2].v.tc[0] = gCourseVtxPtr[6].v.tc[0] = D_800F8930[2];
        gCourseVtxPtr[3].v.tc[0] = gCourseVtxPtr[5].v.tc[0] = D_800F8930[3];
        gCourseVtxPtr[4].v.tc[0] = D_800F8930[4];
    } else {
        gCourseVtxPtr[0].v.tc[1] = tcBottom;
        gCourseVtxPtr[1].v.tc[1] = (tcBottom + tcRight) >> 1;
        gCourseVtxPtr[2].v.tc[1] = tcRight;
        gCourseVtxPtr[3].v.tc[1] = (tcRight + tcTop) >> 1;
        gCourseVtxPtr[4].v.tc[1] = tcTop;
        gCourseVtxPtr[5].v.tc[1] = (tcTop + tcLeft) >> 1;
        gCourseVtxPtr[6].v.tc[1] = tcLeft;
        gCourseVtxPtr[7].v.tc[1] = (tcLeft + tcBottom) >> 1;
        gCourseVtxPtr[0].v.tc[0] = D_800F8930[4];
        gCourseVtxPtr[1].v.tc[0] = gCourseVtxPtr[7].v.tc[0] = D_800F8930[3];
        gCourseVtxPtr[2].v.tc[0] = gCourseVtxPtr[6].v.tc[0] = D_800F8930[2];
        gCourseVtxPtr[3].v.tc[0] = gCourseVtxPtr[5].v.tc[0] = D_800F8930[1];
        gCourseVtxPtr[4].v.tc[0] = D_800F8930[0];
    }
    Course_SetupChunkPipeTunnelVtxPos(chunk);
}

void Course_SetupChunkPipeTunnelJoinVtx(SegmentChunk* chunk) {
    Gfx* gfx;

    gCourseVtxPtr[0].v.ob[0] = ((chunk->referencePos7[0] - chunk->referencePos4[0]) >> 5) + chunk->referencePos7[0];
    gCourseVtxPtr[0].v.ob[1] = ((chunk->referencePos7[1] - chunk->referencePos4[1]) >> 5) + chunk->referencePos7[1];
    gCourseVtxPtr[0].v.ob[2] = ((chunk->referencePos7[2] - chunk->referencePos4[2]) >> 5) + chunk->referencePos7[2];

    gCourseVtxPtr[1].v.ob[0] = ((chunk->referencePos8[0] - chunk->referencePos3[0]) >> 5) + chunk->referencePos8[0];
    gCourseVtxPtr[1].v.ob[1] = ((chunk->referencePos8[1] - chunk->referencePos3[1]) >> 5) + chunk->referencePos8[1];
    gCourseVtxPtr[1].v.ob[2] = ((chunk->referencePos8[2] - chunk->referencePos3[2]) >> 5) + chunk->referencePos8[2];

    gCourseVtxPtr[2].v.ob[0] = ((chunk->referencePos2[0] - chunk->referencePos1[0]) >> 5) + chunk->referencePos2[0];
    gCourseVtxPtr[2].v.ob[1] = ((chunk->referencePos2[1] - chunk->referencePos1[1]) >> 5) + chunk->referencePos2[1];
    gCourseVtxPtr[2].v.ob[2] = ((chunk->referencePos2[2] - chunk->referencePos1[2]) >> 5) + chunk->referencePos2[2];

    gCourseVtxPtr[3].v.ob[0] = ((chunk->referencePos5[0] - chunk->referencePos6[0]) >> 5) + chunk->referencePos5[0];
    gCourseVtxPtr[3].v.ob[1] = ((chunk->referencePos5[1] - chunk->referencePos6[1]) >> 5) + chunk->referencePos5[1];
    gCourseVtxPtr[3].v.ob[2] = ((chunk->referencePos5[2] - chunk->referencePos6[2]) >> 5) + chunk->referencePos5[2];

    gCourseVtxPtr[4].v.ob[0] = ((chunk->referencePos4[0] - chunk->referencePos7[0]) >> 5) + chunk->referencePos4[0];
    gCourseVtxPtr[4].v.ob[1] = ((chunk->referencePos4[1] - chunk->referencePos7[1]) >> 5) + chunk->referencePos4[1];
    gCourseVtxPtr[4].v.ob[2] = ((chunk->referencePos4[2] - chunk->referencePos7[2]) >> 5) + chunk->referencePos4[2];

    gSPVertex(sCourseDisp - 1, gCourseVtxPtr, 5, 16);

    gCourseVtxPtr += 5;
}

void Course_SetupChunkCylinderVtx(SegmentChunk* chunk, s32 arg1) {
    s16 tcLeft;
    s16 tcTop;
    s16 tcBottom;
    s16 tcRight;

    if (arg1 != 0) {
        tcRight = chunk->rightTextureCorrection;
        tcLeft = chunk->leftTextureCorrection;
        tcTop = chunk->topTextureCorrection;
        tcBottom = chunk->bottomTextureCorrection;
    } else {
        tcRight = chunk->rightTextureCoord;
        tcLeft = chunk->leftTextureCoord;
        tcTop = chunk->topTextureCoord;
        tcBottom = chunk->bottomTextureCoord;
    }
    gCourseVtxPtr[0].v.tc[1] = tcBottom;
    gCourseVtxPtr[1].v.tc[1] = (tcBottom + tcRight) >> 1;
    gCourseVtxPtr[2].v.tc[1] = tcRight;
    gCourseVtxPtr[3].v.tc[1] = (tcRight + tcTop) >> 1;
    gCourseVtxPtr[4].v.tc[1] = tcTop;
    gCourseVtxPtr[5].v.tc[1] = (tcTop + tcLeft) >> 1;
    gCourseVtxPtr[6].v.tc[1] = tcLeft;
    gCourseVtxPtr[7].v.tc[1] = (tcLeft + tcBottom) >> 1;
    Course_SetupChunkDefaultVtxPos(chunk);
}

void Course_SetupChunkHalfPipeVtx(SegmentChunk* chunk, s32 arg1) {
    s32 tcRight;
    s32 tcLeft;
    s32 tcBottom;

    if (arg1 != 0) {
        tcRight = chunk->rightTextureCorrection;
        tcLeft = chunk->leftTextureCorrection;
        tcBottom = chunk->bottomTextureCorrection;
    } else {
        tcRight = chunk->rightTextureCoord;
        tcLeft = chunk->leftTextureCoord;
        tcBottom = chunk->bottomTextureCoord;
    }

    gCourseVtxPtr[1].v.tc[1] = tcRight;
    gCourseVtxPtr[2].v.tc[1] = gCourseVtxPtr[3].v.tc[1] = (tcRight + tcBottom) >> 1;
    gCourseVtxPtr[0].v.tc[1] = tcBottom;
    gCourseVtxPtr[4].v.tc[1] = tcBottom;
    gCourseVtxPtr[5].v.tc[1] = gCourseVtxPtr[6].v.tc[1] = (tcLeft + tcBottom) >> 1;
    gCourseVtxPtr[7].v.tc[1] = tcLeft;
    Course_SetupChunkDefaultVtxPos(chunk);
}

void Course_SetupRoadChunkGroupPairVtx(void) {

    gSPVertex(sCourseDisp++, gCourseVtxPtr, 16, 0);
    gSPDisplayList(sCourseDisp++, D_80140F0);

    Course_SetupChunkRoadAirVtx(sWorkingSegmentChunk, sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000);
    D_800F8958[0].chunk = sWorkingSegmentChunk;
    Course_SetupChunkRoadAirVtx(sWorkingNextSegmentChunk, 0);
    D_800F8958[1].chunk = sWorkingNextSegmentChunk;
}

void Course_DrawBackwardRoadChunkGroup(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (sWorkingSegmentChunk == D_800F89B8->chunk) {
        if (sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], (sWorkingSegmentChunk->leftTextureCorrection +
                                                               sWorkingSegmentChunk->rightTextureCorrection) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], sWorkingSegmentChunk->rightTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingSegmentChunk->rightTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], sWorkingSegmentChunk->rightTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], (sWorkingSegmentChunk->leftTextureCorrection +
                                                               sWorkingSegmentChunk->rightTextureCorrection) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], sWorkingSegmentChunk->leftTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingSegmentChunk->leftTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], sWorkingSegmentChunk->leftTextureCorrection));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);

        gSPDisplayList(sCourseDisp++, D_800F89B8->unk_04);

        Course_SetupChunkRoadAirVtx(sWorkingNextSegmentChunk, 0);
        D_800F89BC->chunk = sWorkingNextSegmentChunk;
    } else {
        D_800F89C0 = 1;
        Course_SetupRoadChunkGroupPairVtx();
    }
}

void Course_DrawForwardRoadChunkGroup(void) {
    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (sWorkingNextSegmentChunk == D_800F89B8->chunk) {
        if (sWorkingNextSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], (sWorkingNextSegmentChunk->leftTextureCoord +
                                                               sWorkingNextSegmentChunk->rightTextureCoord) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], sWorkingNextSegmentChunk->rightTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingNextSegmentChunk->rightTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], sWorkingNextSegmentChunk->rightTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], (sWorkingNextSegmentChunk->leftTextureCoord +
                                                               sWorkingNextSegmentChunk->rightTextureCoord) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], sWorkingNextSegmentChunk->leftTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingNextSegmentChunk->leftTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], sWorkingNextSegmentChunk->leftTextureCoord));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];
        gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);
        gSPDisplayList(sCourseDisp++, D_800F89BC->unk_04);
        Course_SetupChunkRoadAirVtx(sWorkingSegmentChunk, sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000);
        D_800F89BC->chunk = sWorkingSegmentChunk;
    } else {
        D_800F89C0 = 0;
        Course_SetupRoadChunkGroupPairVtx();
    }
}

void Course_SetupPipeTunnelChunkGroupPairVtx(void) {

    gSPVertex(sCourseDisp++, gCourseVtxPtr, 16, 0);
    if (sWorkingChunkJoinInfo != 0) {
        if (D_800F892C != D_800F89D4) {
            gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
            gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
            D_800F892C = D_800F89D4;
        }

        switch (sWorkingSegmentChunk->trackSegmentInfo & TRACK_CHUNK_JOIN_TRANSITION_START_MASK) {
            case TRACK_CHUNK_JOIN_TRANSITION_START_NONE:
                gSPDisplayList(sCourseDisp++, D_80140F0);
                break;
            case TRACK_CHUNK_JOIN_PREVIOUS_END:
                gSPDisplayList(sCourseDisp++, D_80142C0);
                break;
            default:
                gSPDisplayList(sCourseDisp++, D_8014308);
                if (1) {}
                break;
        }
    } else {
        if (D_800F892C != D_800F89D4) {
            gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
            gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
            D_800F892C = D_800F89D4;
        }

        gSPDisplayList(sCourseDisp++, D_8014180);
        if (D_800F89D8) {
            if (D_800F892C != (D_800F89D4 + 1)) {
                gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4 + 1, G_ON);
                D_800F892C = D_800F89D4 + 1;
            }
            gSPDisplayList(sCourseDisp++, D_80140F0);
        }
    }
    Course_SetupChunkPipeTunnelVtx(sWorkingSegmentChunk, sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000);
    D_800F8958[0].chunk = sWorkingSegmentChunk;
    Course_SetupChunkPipeTunnelVtx(sWorkingNextSegmentChunk, 0);
    D_800F8958[1].chunk = sWorkingNextSegmentChunk;
}

void Course_DrawBackwardPipeTunnelChunkGroup(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (sWorkingSegmentChunk == D_800F89B8->chunk) {
        if (sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000) {
            if (sWorkingSegmentChunk->trackSegmentInfo & TRACK_JOIN_BOTH) {
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], sWorkingSegmentChunk->bottomTextureCorrection));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 1, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingSegmentChunk->bottomTextureCorrection +
                                                                   sWorkingSegmentChunk->rightTextureCorrection) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingSegmentChunk->rightTextureCorrection));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 3, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingSegmentChunk->bottomTextureCorrection +
                                                                   sWorkingSegmentChunk->rightTextureCorrection) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], sWorkingSegmentChunk->bottomTextureCorrection));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 5, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingSegmentChunk->bottomTextureCorrection +
                                                                   sWorkingSegmentChunk->leftTextureCorrection) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingSegmentChunk->leftTextureCorrection));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 7, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingSegmentChunk->bottomTextureCorrection +
                                                                   sWorkingSegmentChunk->leftTextureCorrection) >>
                                                                      1));
            } else {
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], sWorkingSegmentChunk->bottomTextureCorrection));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 1, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingSegmentChunk->bottomTextureCorrection +
                                                                   sWorkingSegmentChunk->rightTextureCorrection) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingSegmentChunk->rightTextureCorrection));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 3, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingSegmentChunk->rightTextureCorrection +
                                                                   sWorkingSegmentChunk->topTextureCorrection) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[0], sWorkingSegmentChunk->topTextureCorrection));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 5, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingSegmentChunk->topTextureCorrection +
                                                                   sWorkingSegmentChunk->leftTextureCorrection) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingSegmentChunk->leftTextureCorrection));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 7, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingSegmentChunk->leftTextureCorrection +
                                                                   sWorkingSegmentChunk->bottomTextureCorrection) >>
                                                                      1));
            }
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);

        if (sWorkingChunkJoinInfo != 0) {
            if (D_800F892C != D_800F89D4) {
                gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            switch (sWorkingSegmentChunk->trackSegmentInfo & TRACK_CHUNK_JOIN_TRANSITION_START_MASK) {
                case TRACK_CHUNK_JOIN_TRANSITION_START_NONE:
                    gSPDisplayList(sCourseDisp++, D_800F89B8->unk_04);
                    break;
                case TRACK_CHUNK_JOIN_PREVIOUS_END:
                    gSPDisplayList(sCourseDisp++, D_800F89B8->unk_14);
                    break;
                default:
                    Course_SetupChunkPipeTunnelJoinVtx(sWorkingSegmentChunk);
                    gSPDisplayList(sCourseDisp++, D_800F89B8->unk_20);
                    gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);
                    gSPDisplayList(sCourseDisp++, D_800F89B8->unk_18);
                    break;
            }
        } else {
            if (D_800F892C != D_800F89D4) {
                gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            gSPDisplayList(sCourseDisp++, D_800F89B8->unk_08);

            if (D_800F89D8) {
                if (D_800F892C != (D_800F89D4 + 1)) {
                    gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
                    gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4 + 1, G_ON);
                    D_800F892C = D_800F89D4 + 1;
                }

                gSPDisplayList(sCourseDisp++, D_800F89B8->unk_04);
            }
        }
        Course_SetupChunkPipeTunnelVtx(sWorkingNextSegmentChunk, 0);
        D_800F89BC->chunk = sWorkingNextSegmentChunk;
    } else {
        D_800F89C0 = 1;
        Course_SetupPipeTunnelChunkGroupPairVtx();
    }
}

void Course_DrawForwardPipeTunnelChunkGroup(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (sWorkingNextSegmentChunk == D_800F89B8->chunk) {
        if (sWorkingNextSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000) {
            if (sWorkingNextSegmentChunk->trackSegmentInfo & TRACK_JOIN_BOTH) {
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], sWorkingNextSegmentChunk->bottomTextureCoord));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 1, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingNextSegmentChunk->bottomTextureCoord +
                                                                   sWorkingNextSegmentChunk->rightTextureCoord) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingNextSegmentChunk->rightTextureCoord));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 3, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingNextSegmentChunk->bottomTextureCoord +
                                                                   sWorkingNextSegmentChunk->rightTextureCoord) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], sWorkingNextSegmentChunk->bottomTextureCoord));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 5, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingNextSegmentChunk->bottomTextureCoord +
                                                                   sWorkingNextSegmentChunk->leftTextureCoord) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingNextSegmentChunk->leftTextureCoord));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 7, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingNextSegmentChunk->bottomTextureCoord +
                                                                   sWorkingNextSegmentChunk->leftTextureCoord) >>
                                                                      1));
            } else {
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[4], sWorkingNextSegmentChunk->bottomTextureCoord));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 1, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingNextSegmentChunk->bottomTextureCoord +
                                                                   sWorkingNextSegmentChunk->rightTextureCoord) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingNextSegmentChunk->rightTextureCoord));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 3, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingNextSegmentChunk->rightTextureCoord +
                                                                   sWorkingNextSegmentChunk->topTextureCoord) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[0], sWorkingNextSegmentChunk->topTextureCoord));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 5, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingNextSegmentChunk->topTextureCoord +
                                                                   sWorkingNextSegmentChunk->leftTextureCoord) >>
                                                                      1));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingNextSegmentChunk->leftTextureCoord));
                gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 7, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingNextSegmentChunk->leftTextureCoord +
                                                                   sWorkingNextSegmentChunk->bottomTextureCoord) >>
                                                                      1));
            }
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];
        gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);

        if (sWorkingChunkJoinInfo != 0) {
            if (D_800F892C != D_800F89D4) {
                gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            switch (sWorkingSegmentChunk->trackSegmentInfo & TRACK_CHUNK_JOIN_TRANSITION_START_MASK) {
                case TRACK_CHUNK_JOIN_TRANSITION_START_NONE:
                    gSPDisplayList(sCourseDisp++, D_800F89BC->unk_04);
                    break;
                case TRACK_CHUNK_JOIN_PREVIOUS_END:
                    Course_SetupChunkPipeTunnelJoinVtx(sWorkingNextSegmentChunk);
                    gSPDisplayList(sCourseDisp++, D_800F89B8->unk_1C);
                    gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);
                    gSPDisplayList(sCourseDisp++, D_800F89BC->unk_14);
                    break;
                default:
                    gSPDisplayList(sCourseDisp++, D_800F89BC->unk_18);
                    if (1) {}
                    break;
            }
        } else {
            if (D_800F892C != D_800F89D4) {
                gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }
            gSPDisplayList(sCourseDisp++, D_800F89BC->unk_08);

            if (D_800F89D8) {
                if (D_800F892C != (D_800F89D4 + 1)) {
                    gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
                    gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4 + 1, G_ON);
                    D_800F892C = D_800F89D4 + 1;
                }
                gSPDisplayList(sCourseDisp++, D_800F89BC->unk_04);
            }
        }
        Course_SetupChunkPipeTunnelVtx(sWorkingSegmentChunk,
                                       sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000);
        D_800F89BC->chunk = sWorkingSegmentChunk;
    } else {
        D_800F89C0 = 0;
        Course_SetupPipeTunnelChunkGroupPairVtx();
    }
}

void Course_SetupCylinderChunkGroupPairVtx(void) {

    gSPVertex(sCourseDisp++, gCourseVtxPtr, 16, 0);

    switch (sWorkingSegmentChunk->trackSegmentInfo & TRACK_CHUNK_JOIN_TRANSITION_END_MASK) {
        case TRACK_CHUNK_JOIN_TRANSITION_END_NONE:
            gSPDisplayList(sCourseDisp++, D_80140F0);
            break;
        case TRACK_CHUNK_JOIN_PREVIOUS_START:
            gSPDisplayList(sCourseDisp++, D_8014520);
            break;
        default:
            gSPDisplayList(sCourseDisp++, D_80145E0);
            if (1) {}
            break;
    }
    Course_SetupChunkCylinderVtx(sWorkingSegmentChunk, sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000);
    D_800F8958[0].chunk = sWorkingSegmentChunk;
    Course_SetupChunkCylinderVtx(sWorkingNextSegmentChunk, 0);
    D_800F8958[1].chunk = sWorkingNextSegmentChunk;
}

void Course_DrawBackwardCylinderChunkGroup(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (sWorkingSegmentChunk == D_800F89B8->chunk) {
        if (sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], sWorkingSegmentChunk->bottomTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingSegmentChunk->bottomTextureCorrection +
                                                               sWorkingSegmentChunk->rightTextureCorrection) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingSegmentChunk->rightTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingSegmentChunk->rightTextureCorrection +
                                                               sWorkingSegmentChunk->topTextureCorrection) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], sWorkingSegmentChunk->topTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingSegmentChunk->topTextureCorrection +
                                                               sWorkingSegmentChunk->leftTextureCorrection) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingSegmentChunk->leftTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingSegmentChunk->leftTextureCorrection +
                                                               sWorkingSegmentChunk->bottomTextureCorrection) >>
                                                                  1));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);

        switch (sWorkingSegmentChunk->trackSegmentInfo & TRACK_CHUNK_JOIN_TRANSITION_END_MASK) {
            case TRACK_CHUNK_JOIN_TRANSITION_END_NONE:
                gSPDisplayList(sCourseDisp++, D_800F89B8->unk_04);
                break;
            case TRACK_CHUNK_JOIN_PREVIOUS_START:
                gSPDisplayList(sCourseDisp++, D_800F89B8->unk_24);
                break;
            default:
                gSPDisplayList(sCourseDisp++, D_800F89B8->unk_28);
                if (1) {}
                break;
        }

        Course_SetupChunkCylinderVtx(sWorkingNextSegmentChunk, 0);
        D_800F89BC->chunk = sWorkingNextSegmentChunk;
    } else {
        D_800F89C0 = 1;
        Course_SetupCylinderChunkGroupPairVtx();
    }
}

void Course_DrawForwardCylinderChunkGroup(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];
    if (sWorkingNextSegmentChunk == D_800F89B8->chunk) {
        if (sWorkingNextSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], sWorkingNextSegmentChunk->bottomTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingNextSegmentChunk->bottomTextureCoord +
                                                               sWorkingNextSegmentChunk->rightTextureCoord) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingNextSegmentChunk->rightTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingNextSegmentChunk->rightTextureCoord +
                                                               sWorkingNextSegmentChunk->topTextureCoord) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], sWorkingNextSegmentChunk->topTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingNextSegmentChunk->topTextureCoord +
                                                               sWorkingNextSegmentChunk->leftTextureCoord) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], sWorkingNextSegmentChunk->leftTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], (sWorkingNextSegmentChunk->leftTextureCoord +
                                                               sWorkingNextSegmentChunk->bottomTextureCoord) >>
                                                                  1));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);

        switch (sWorkingSegmentChunk->trackSegmentInfo & TRACK_CHUNK_JOIN_TRANSITION_END_MASK) {
            case TRACK_CHUNK_JOIN_TRANSITION_END_NONE:
                gSPDisplayList(sCourseDisp++, D_800F89BC->unk_04);
                break;
            case TRACK_CHUNK_JOIN_PREVIOUS_START:
                gSPDisplayList(sCourseDisp++, D_800F89BC->unk_24);
                break;
            default:
                gSPDisplayList(sCourseDisp++, D_800F89BC->unk_28);
                if (1) {}
                break;
        }

        Course_SetupChunkCylinderVtx(sWorkingSegmentChunk,
                                     sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000);
        D_800F89BC->chunk = sWorkingSegmentChunk;
    } else {
        D_800F89C0 = 0;
        Course_SetupCylinderChunkGroupPairVtx();
    }
}

void Course_SetupHalfPipeChunkGroupPairVtx(void) {

    gSPVertex(sCourseDisp++, gCourseVtxPtr, 16, 0);
    gSPDisplayList(sCourseDisp++, D_80140F0);

    Course_SetupChunkHalfPipeVtx(sWorkingSegmentChunk, sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000);
    D_800F8958[0].chunk = sWorkingSegmentChunk;
    Course_SetupChunkHalfPipeVtx(sWorkingNextSegmentChunk, 0);
    D_800F8958[1].chunk = sWorkingNextSegmentChunk;
}

void Course_DrawBackwardHalfPipeChunkGroup(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (sWorkingSegmentChunk == D_800F89B8->chunk) {
        if (sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], sWorkingSegmentChunk->bottomTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], sWorkingSegmentChunk->rightTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], (sWorkingSegmentChunk->rightTextureCorrection +
                                                               sWorkingSegmentChunk->bottomTextureCorrection) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingSegmentChunk->rightTextureCorrection +
                                                               sWorkingSegmentChunk->bottomTextureCorrection) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], sWorkingSegmentChunk->bottomTextureCorrection));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingSegmentChunk->leftTextureCorrection +
                                                               sWorkingSegmentChunk->bottomTextureCorrection) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], (sWorkingSegmentChunk->leftTextureCorrection +
                                                               sWorkingSegmentChunk->bottomTextureCorrection) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], sWorkingSegmentChunk->leftTextureCorrection));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];
        gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);
        gSPDisplayList(sCourseDisp++, D_800F89B8->unk_0C);
        Course_SetupChunkHalfPipeVtx(sWorkingNextSegmentChunk, 0);
        D_800F89BC->chunk = sWorkingNextSegmentChunk;
    } else {
        D_800F89C0 = 1;
        Course_SetupHalfPipeChunkGroupPairVtx();
    }
}

void Course_DrawForwardHalfPipeChunkGroup(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];

    if (sWorkingNextSegmentChunk == D_800F89B8->chunk) {
        if (sWorkingNextSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[4], sWorkingNextSegmentChunk->bottomTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], sWorkingNextSegmentChunk->rightTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], (sWorkingNextSegmentChunk->rightTextureCoord +
                                                               sWorkingNextSegmentChunk->bottomTextureCoord) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingNextSegmentChunk->rightTextureCoord +
                                                               sWorkingNextSegmentChunk->bottomTextureCoord) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[0], sWorkingNextSegmentChunk->bottomTextureCoord));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[1], (sWorkingNextSegmentChunk->leftTextureCoord +
                                                               sWorkingNextSegmentChunk->bottomTextureCoord) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[2], (sWorkingNextSegmentChunk->leftTextureCoord +
                                                               sWorkingNextSegmentChunk->bottomTextureCoord) >>
                                                                  1));
            gSPModifyVertex(sCourseDisp++, D_800F89B8->loadVtxIndex + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_800F8930[3], sWorkingNextSegmentChunk->leftTextureCoord));
        }

        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];
        gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);
        gSPDisplayList(sCourseDisp++, D_800F89BC->unk_0C);
        Course_SetupChunkHalfPipeVtx(sWorkingSegmentChunk,
                                     sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000);
        D_800F89BC->chunk = sWorkingSegmentChunk;
    } else {
        D_800F89C0 = 0;
        Course_SetupHalfPipeChunkGroupPairVtx();
    }
}

void Course_SetupAirChunkGroupPairVtx(void) {

    gSPVertex(sCourseDisp++, gCourseVtxPtr, 16, 0);
    gSPDisplayList(sCourseDisp++, D_8014210);
    Course_SetupChunkRoadAirVtx(sWorkingSegmentChunk, 0);
    D_800F8958[0].chunk = sWorkingSegmentChunk;
    Course_SetupChunkRoadAirVtx(sWorkingNextSegmentChunk, 0);
    D_800F8958[1].chunk = sWorkingNextSegmentChunk;
}

void Course_DrawBackwardAirChunkGroup(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];
    if (sWorkingSegmentChunk == D_800F89B8->chunk) {
        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);
        gSPDisplayList(sCourseDisp++, D_800F89B8->unk_10);
        Course_SetupChunkRoadAirVtx(sWorkingNextSegmentChunk, 0);
        D_800F89BC->chunk = sWorkingNextSegmentChunk;
    } else {
        D_800F89C0 = 1;
        Course_SetupAirChunkGroupPairVtx();
    }
}

void Course_DrawForwardAirChunkGroup(void) {

    D_800F89B8 = &D_800F8958[D_800F89C0];
    if (sWorkingNextSegmentChunk == D_800F89B8->chunk) {
        D_800F89BC = &D_800F8958[D_800F89C0 ^= 1];

        gSPVertex(sCourseDisp++, gCourseVtxPtr, 8, D_800F89BC->loadVtxIndex);
        gSPDisplayList(sCourseDisp++, D_800F89BC->unk_10);
        Course_SetupChunkRoadAirVtx(sWorkingSegmentChunk, sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_80000000);
        D_800F89BC->chunk = sWorkingSegmentChunk;
    } else {
        D_800F89C0 = 0;
        Course_SetupAirChunkGroupPairVtx();
    }
}

extern SegmentChunk gSegmentChunks[];

void Course_DrawBackwardChunkGroup(SegmentChunkGroup* chunkGroup) {
    f32 var_fv0;
    s32 trackType;
    u32 trackShape;
    unk_800CF528* temp_a1;

    sWorkingSegmentChunk = chunkGroup->startChunk;
    sWorkingNextSegmentChunk = chunkGroup->startChunk + 1;

    if (sWorkingNextSegmentChunk == sLastSegmentChunk) {
        sWorkingNextSegmentChunk = gSegmentChunks;
    }

    do {
        if (sWorkingNextSegmentChunk->trackSegmentInfo & TRACK_FLAG_CONTINUOUS) {
            if (sWorkingNextSegmentChunk != chunkGroup->endChunk) {

                D_800F89C8 = sWorkingNextSegmentChunk + 1;
                if (D_800F89C8 == sLastSegmentChunk) {
                    D_800F89C8 = gSegmentChunks;
                }
                var_fv0 = D_800F894C;

                do {
                    var_fv0 += D_800F8950;
                    if (D_800F89C8->depth < var_fv0) {
                        break;
                    }

                    if ((sWorkingNextSegmentChunk = D_800F89C8) == chunkGroup->endChunk) {
                        break;
                    }

                    D_800F89C8++;
                    if (D_800F89C8 == sLastSegmentChunk) {
                        D_800F89C8 = gSegmentChunks;
                    }
                } while (sWorkingNextSegmentChunk->trackSegmentInfo & TRACK_FLAG_CONTINUOUS);
            }
        }

        trackShape = TRACK_SHAPE_INDEX((u32) sWorkingSegmentChunk->trackSegmentInfo & TRACK_SHAPE_MASK);
        trackType = sWorkingSegmentChunk->trackSegmentInfo & TRACK_TYPE_MASK;
        if (trackType != TRACK_TYPE_NONE) {
            temp_a1 = &D_800CF8C8[trackShape][trackType];
            D_800F89D4 = temp_a1->unk_10;

            if (D_800F892C != D_800F89D4) {
                gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            trackType = sWorkingSegmentChunk->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK);
            if (trackType != sLastTrackShapeType) {
                gDPLoadSync(sCourseDisp++);
                gDPSetTextureImage(sCourseDisp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, temp_a1->width, temp_a1->texture);
                gDPLoadBlock(sCourseDisp++, temp_a1->tile, 0, 0, 2047, CALC_DXT(temp_a1->width, G_IM_SIZ_16b));

                sLastTrackShapeType = trackType;
                D_800F8930[0] = temp_a1->unk_16;
                D_800F8930[1] = temp_a1->unk_18;
                D_800F8930[2] = temp_a1->unk_1A;
                D_800F8930[3] = temp_a1->unk_1C;
                D_800F8930[4] = temp_a1->unk_1E;
            }
        }
        sWorkingChunkJoinInfo =
            sWorkingSegmentChunk->trackSegmentInfo &
            (TRACK_JOIN_MASK | TRACK_CHUNK_JOIN_TRANSITION_END_MASK | TRACK_CHUNK_JOIN_TRANSITION_START_MASK);
        sBackwardChunkGroupDrawFuncs[trackShape]();

        sWorkingSegmentChunk = sWorkingNextSegmentChunk++;
        if (sWorkingNextSegmentChunk == sLastSegmentChunk) {
            sWorkingNextSegmentChunk = gSegmentChunks;
        }
    } while (sWorkingSegmentChunk != chunkGroup->endChunk);
}

void Course_DrawForwardChunkGroup(SegmentChunkGroup* chunkGroup) {
    f32 var_fv0;
    s32 trackType;
    u32 trackShape;
    unk_800CF528* temp_a2;
    SegmentChunk* firstChunk = gSegmentChunks;

    sWorkingSegmentChunk = chunkGroup->endChunk - 1;
    if (sWorkingSegmentChunk < firstChunk) {
        sWorkingSegmentChunk = sLastSegmentChunk - 1;
    }
    sWorkingNextSegmentChunk = chunkGroup->endChunk;

    do {
        if (sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_CONTINUOUS) {
            if (sWorkingSegmentChunk != chunkGroup->startChunk) {
                D_800F89C8 = sWorkingSegmentChunk - 1;
                if (D_800F89C8 < firstChunk) {
                    D_800F89C8 = sLastSegmentChunk - 1;
                }
                var_fv0 = D_800F894C;

                do {
                    var_fv0 += D_800F8950;
                    if (D_800F89C8->depth < var_fv0) {
                        break;
                    }

                    if ((sWorkingSegmentChunk = D_800F89C8) == chunkGroup->startChunk) {
                        break;
                    }

                    D_800F89C8--;
                    if (D_800F89C8 < firstChunk) {
                        D_800F89C8 = sLastSegmentChunk - 1;
                    }
                } while (sWorkingSegmentChunk->trackSegmentInfo & TRACK_FLAG_CONTINUOUS);
            }
        }
        trackShape = TRACK_SHAPE_INDEX((u32) sWorkingSegmentChunk->trackSegmentInfo & TRACK_SHAPE_MASK);
        trackType = sWorkingSegmentChunk->trackSegmentInfo & TRACK_TYPE_MASK;
        if (trackType != TRACK_TYPE_NONE) {
            temp_a2 = &D_800CF8C8[trackShape][trackType];
            D_800F89D4 = temp_a2->unk_10;

            if (D_800F892C != D_800F89D4) {
                gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            trackType = sWorkingSegmentChunk->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK);
            if (trackType != sLastTrackShapeType) {
                gDPLoadSync(sCourseDisp++);
                gDPSetTextureImage(sCourseDisp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, temp_a2->width, temp_a2->texture);
                gDPLoadBlock(sCourseDisp++, temp_a2->tile, 0, 0, 2047, CALC_DXT(temp_a2->width, G_IM_SIZ_16b));
                sLastTrackShapeType = trackType;
                D_800F8930[0] = temp_a2->unk_16;
                D_800F8930[1] = temp_a2->unk_18;
                D_800F8930[2] = temp_a2->unk_1A;
                D_800F8930[3] = temp_a2->unk_1C;
                D_800F8930[4] = temp_a2->unk_1E;
            }
        }
        sWorkingChunkJoinInfo =
            sWorkingSegmentChunk->trackSegmentInfo &
            (TRACK_JOIN_MASK | TRACK_CHUNK_JOIN_TRANSITION_END_MASK | TRACK_CHUNK_JOIN_TRANSITION_START_MASK);
        sForwardChunkGroupDrawFuncs[trackShape]();

        sWorkingNextSegmentChunk = sWorkingSegmentChunk--;
        if (sWorkingSegmentChunk < firstChunk) {
            sWorkingSegmentChunk = sLastSegmentChunk - 1;
        }
    } while (sWorkingNextSegmentChunk != chunkGroup->startChunk);
}

Gfx* Course_DrawModel(Gfx* gfx, Vtx* vtx, s32 vtxCount) {
    s32 i;

    while (vtxCount > 30) {
        gSPVertex(gfx++, vtx, 30, 0);

        for (i = 0; i < 27; i += 3) {
            gSP2Triangles(gfx++, i + 1, i + 0, i + 4, 0, i + 4, i + 0, i + 3, 0);
            gSP2Triangles(gfx++, i + 0, i + 2, i + 3, 0, i + 3, i + 2, i + 5, 0);
            gSP2Triangles(gfx++, i + 2, i + 1, i + 5, 0, i + 5, i + 1, i + 4, 0);
        }
        vtxCount -= 27;
        vtx += 27;
    }

    gSPVertex(gfx++, vtx, vtxCount, 0);

    i = 0;
    do {
        gSP2Triangles(gfx++, i + 1, i + 0, i + 4, 0, i + 4, i + 0, i + 3, 0);
        gSP2Triangles(gfx++, i + 0, i + 2, i + 3, 0, i + 3, i + 2, i + 5, 0);
        gSP2Triangles(gfx++, i + 2, i + 1, i + 5, 0, i + 5, i + 1, i + 4, 0);
        i += 3;
        vtxCount -= 3;
    } while (vtxCount > 3);

    return gfx;
}

extern u32 gGameFrameCount;

Gfx* func_800A95B4(Gfx* gfx) {
    s32 trackType;
    u32 trackShape;
    unk_800CF528* temp_a1;

    if (gSegmentChunkCount < 3) {
        return gfx;
    }
    D_800F89D8 = true;
    sCourseDisp = gfx;
    gSPDisplayList(sCourseDisp++, D_8014040);
    gSPDisplayList(sCourseDisp++, D_8014078);
    gDPSetPrimColor(sCourseDisp++, 0, 0, (255 - (u8) (gGameFrameCount * 8)), 0, 0, 255);

    sLastTrackShapeType = D_800F892C = -1;
    D_800F8958[0].chunk = D_800F8958[1].chunk = 0;
    D_800F89C0 = 0;
    sWorkingSegmentChunk = gSegmentChunks;
    sWorkingNextSegmentChunk = &gSegmentChunks[1];
    do {
        trackShape = TRACK_SHAPE_INDEX((u32) sWorkingSegmentChunk->trackSegmentInfo & TRACK_SHAPE_MASK);
        trackType = sWorkingSegmentChunk->trackSegmentInfo & TRACK_TYPE_MASK;
        if (trackType != TRACK_TYPE_NONE) {
            temp_a1 = &D_800CF8C8[trackShape][trackType];
            D_800F89D4 = temp_a1->unk_10;
            if (D_800F892C != D_800F89D4) {
                gSPTexture(sCourseDisp++, 0, 0, 0, D_800F892C, G_OFF);
                gSPTexture(sCourseDisp++, 0x8000, 0xFFFF, 0, D_800F89D4, G_ON);
                D_800F892C = D_800F89D4;
            }

            trackType = sWorkingSegmentChunk->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK);
            if (trackType != sLastTrackShapeType) {
                gDPLoadSync(sCourseDisp++);
                gDPSetTextureImage(sCourseDisp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, temp_a1->width, temp_a1->texture);
                gDPLoadBlock(sCourseDisp++, temp_a1->tile, 0, 0, 2047, CALC_DXT(temp_a1->width, G_IM_SIZ_16b));

                sLastTrackShapeType = trackType;
                D_800F8930[0] = temp_a1->unk_16;
                D_800F8930[1] = temp_a1->unk_18;
                D_800F8930[2] = temp_a1->unk_1A;
                D_800F8930[3] = temp_a1->unk_1C;
                D_800F8930[4] = temp_a1->unk_1E;
            }
        }
        sWorkingChunkJoinInfo =
            sWorkingSegmentChunk->trackSegmentInfo &
            (TRACK_JOIN_MASK | TRACK_CHUNK_JOIN_TRANSITION_END_MASK | TRACK_CHUNK_JOIN_TRANSITION_START_MASK);
        sBackwardChunkGroupDrawFuncs[trackShape]();

        sWorkingSegmentChunk = sWorkingNextSegmentChunk++;

    } while (sWorkingSegmentChunk != sLastSegmentChunk);

    return sCourseDisp;
}

Gfx* Course_Draw(Gfx* gfx, s32 playerIndex) {
    MtxF sp60;
    f32 var_fv1;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv1;
    s32 lastChunkDrawState;
    SegmentChunk* parseStartChunk;
    SegmentChunk* nextChunk;
    SegmentChunk* chunk;
    SegmentChunkGroup* furthestChunkGroup;
    CourseSegment* segment;
    SegmentChunkGroup* segmentChunkGroupEnd;
    SegmentChunkGroup* segmentChunkGroup;
    s32 var_a0;
    s32 var_t0;
    s32 var_a2;
    Racer* racer;
    Camera* camera;
    s32 i;

    camera = &gCameras[playerIndex];
    racer = &gRacers[camera->id];

    sCourseDisp = gfx;
    segment = racer->segmentPositionInfo.courseSegment;

    if (segment->trackSegmentInfo & TRACK_FLAG_INSIDE) {
        if (((segment->trackSegmentInfo & TRACK_JOIN_PREVIOUS) &&
             (racer->segmentPositionInfo.segmentTValue < segment->previousJoinEndTValue)) ||
            ((segment->trackSegmentInfo & TRACK_JOIN_NEXT) &&
             (segment->nextJoinStartTValue < racer->segmentPositionInfo.segmentTValue))) {
            D_800F89D8 = true;
        } else {
            D_800F89D8 = false;
        }
    } else {
        D_800F89D8 = true;
    }

    temp_fv1 = (camera->basis.x.x * sCourseRenderOriginDistance) - camera->eye.x;
    temp_fa0 = (camera->basis.x.y * sCourseRenderOriginDistance) - camera->eye.y;
    temp_fa1 = (camera->basis.x.z * sCourseRenderOriginDistance) - camera->eye.z;

    sp60.m[3][2] = camera->projectionMtx.m[3][2] -
                   (camera->projectionMtx.m[2][2] *
                    (sp60.m[3][3] = ((-temp_fv1 * camera->viewMtx.m[0][2]) - (temp_fa0 * camera->viewMtx.m[1][2])) -
                                    (temp_fa1 * camera->viewMtx.m[2][2])));
    sp60.m[3][0] =
        (camera->projectionMtx.m[0][0] * ((temp_fv1 * camera->viewMtx.m[0][0]) + (temp_fa0 * camera->viewMtx.m[1][0]) +
                                          (temp_fa1 * camera->viewMtx.m[2][0]))) -
        (camera->projectionMtx.m[2][0] * sp60.m[3][3]);
    sp60.m[3][1] =
        (camera->projectionMtx.m[1][1] * ((temp_fv1 * camera->viewMtx.m[0][1]) + (temp_fa0 * camera->viewMtx.m[1][1]) +
                                          (temp_fa1 * camera->viewMtx.m[2][1]))) -
        (camera->projectionMtx.m[2][1] * sp60.m[3][3]);
    sp60.m[0][0] = camera->projectionViewMtx.m[0][0];
    sp60.m[0][1] = camera->projectionViewMtx.m[0][1];
    sp60.m[0][2] = camera->projectionViewMtx.m[0][2];
    sp60.m[0][3] = camera->projectionViewMtx.m[0][3];
    sp60.m[1][0] = camera->projectionViewMtx.m[1][0];
    sp60.m[1][1] = camera->projectionViewMtx.m[1][1];
    sp60.m[1][2] = camera->projectionViewMtx.m[1][2];
    sp60.m[1][3] = camera->projectionViewMtx.m[1][3];
    sp60.m[2][0] = camera->projectionViewMtx.m[2][0];
    sp60.m[2][1] = camera->projectionViewMtx.m[2][1];
    sp60.m[2][2] = camera->projectionViewMtx.m[2][2];
    sp60.m[2][3] = camera->projectionViewMtx.m[2][3];

    chunk = gSegmentChunks;

    do {
        chunk->depth = ((sp60.m[0][2] * chunk->pos.x) + (sp60.m[1][2] * chunk->pos.y) + (sp60.m[2][2] * chunk->pos.z)) +
                       sp60.m[3][2];

        if ((chunk->depth < 0.0f) || (sCourseFarRenderDistance < chunk->depth)) {
            chunk->drawState = 0;
        } else {
            temp_fa0 =
                1.0f /
                (((sp60.m[0][3] * chunk->pos.x) + (sp60.m[1][3] * chunk->pos.y) + (sp60.m[2][3] * chunk->pos.z)) +
                 sp60.m[3][3]);
            var_fv1 = temp_fa0 *
                      (((sp60.m[0][0] * chunk->pos.x) + (sp60.m[1][0] * chunk->pos.y) + (sp60.m[2][0] * chunk->pos.z)) +
                       sp60.m[3][0]);
            if ((var_fv1 < -1.0f) || (var_fv1 > 1.0f)) {
                chunk->drawState = 0;
            } else {
                temp_fa0 =
                    1.0f /
                    (((sp60.m[0][3] * chunk->pos.x) + (sp60.m[1][3] * chunk->pos.y) + (sp60.m[2][3] * chunk->pos.z)) +
                     sp60.m[3][3]);
                var_fv1 =
                    temp_fa0 *
                    (((sp60.m[0][1] * chunk->pos.x) + (sp60.m[1][1] * chunk->pos.y) + (sp60.m[2][1] * chunk->pos.z)) +
                     sp60.m[3][1]);
                if ((var_fv1 < -1.0f) || (var_fv1 > 1.0f)) {
                    chunk->drawState = 0;
                } else {
                    chunk->drawState = 1;
                }
            }
        }
        chunk++;
    } while (chunk != sLastSegmentChunk);
    sLastSegmentChunk->depth = gSegmentChunks->depth;
    sLastSegmentChunk->drawState = gSegmentChunks->drawState;
    lastChunkDrawState = 1;
    D_800CF500 = 0;
    nextChunk = &gSegmentChunks[1];
    chunk = gSegmentChunks;
    do {
        if ((chunk->drawState != 0) || (nextChunk->drawState != 0)) {
            var_fv1 = nextChunk->depth - chunk->depth;
            if (var_fv1 < -30.0f) {
                chunk->drawState = lastChunkDrawState = -1;
            } else if (var_fv1 > 30.0f) {
                chunk->drawState = lastChunkDrawState = 1;
            } else {
                chunk->drawState = lastChunkDrawState;
            }
            D_800CF500++;
        } else {
            chunk->drawState = 0;
        }
        chunk = nextChunk;
        nextChunk++;
    } while (sLastSegmentChunk >= nextChunk);
    sLastSegmentChunk->drawState = gSegmentChunks->drawState;
    if (D_800CF500 == 0) {
        return sCourseDisp;
    }
    if (D_800CF500 == gSegmentChunkCount) {
        segmentChunkGroup = sSegmentChunkGroups;
        segmentChunkGroup->startChunk = segmentChunkGroup->endChunk = gSegmentChunks;
        segmentChunkGroup->drawState = 1;
        segmentChunkGroup->averageDepth = 0.0f;
        segmentChunkGroupEnd = segmentChunkGroup + 1;
    } else {
        chunk = sLastSegmentChunk - 1;
        if (chunk->drawState == 0) {
            chunk = gSegmentChunks;
            while (chunk->drawState == 0) {
                chunk++;
            }
        } else {
            chunk--;
            while (chunk->drawState != 0) {
                chunk--;
            }
            chunk++;
        }
        parseStartChunk = chunk;

        i = 0;
        segmentChunkGroup = sSegmentChunkGroups;
        do {
            segmentChunkGroup->startChunk = chunk;
            segmentChunkGroup->averageDepth = temp_fa0 = chunk->depth;
            segmentChunkGroup->drawState = lastChunkDrawState = chunk->drawState;
            var_a0 = 1;

            while (true) {
                chunk++;
                if (chunk == sLastSegmentChunk) {
                    chunk = gSegmentChunks;
                }
                var_a0++;
                segmentChunkGroup->averageDepth += chunk->depth;
                var_fv1 = temp_fa0 - chunk->depth;
                if ((var_fv1 < -D_800CF51C) || (D_800CF51C < var_fv1) || (chunk == parseStartChunk) ||
                    (lastChunkDrawState != chunk->drawState)) {
                    break;
                }
            }

            segmentChunkGroup->endChunk = chunk;
            segmentChunkGroup->averageDepth /= var_a0;

            if (++segmentChunkGroup == sSegmentChunkGroups + ARRAY_COUNT(sSegmentChunkGroups)) {
                return sCourseDisp;
            }
            while (chunk->drawState == 0) {
                chunk++;
                if (chunk == sLastSegmentChunk) {
                    chunk = gSegmentChunks;
                }
            }
        } while (chunk != parseStartChunk);
        segmentChunkGroupEnd = segmentChunkGroup;
    }

    gSPDisplayList(sCourseDisp++, D_8014008);
    gSPDisplayList(sCourseDisp++, D_8014078);
    gSPFogPosition(sCourseDisp++, sCourseFogStartDistance, 1000);
    gDPSetPrimColor(sCourseDisp++, 0, 0, 255 - ((gGameFrameCount * 8) % 256), 0, 0, 255);

    if (1) {}
    segment = racer->segmentPositionInfo.courseSegment;

    if (segment->trackSegmentInfo & TRACK_FLAG_INSIDE) {
        if (segment->nextJoinStartTValue < racer->segmentPositionInfo.segmentTValue) {
            var_fv1 = (1.0f - racer->segmentPositionInfo.segmentLengthProportion) / segment->joinScale;
        } else if (racer->segmentPositionInfo.segmentTValue < segment->previousJoinEndTValue) {
            var_fv1 = racer->segmentPositionInfo.segmentLengthProportion / segment->joinScale;
        } else {
            var_a0 = gCurrentCourseInfo->courseFogColors[0] >> 2;
            var_t0 = gCurrentCourseInfo->courseFogColors[1] >> 2;
            var_a2 = gCurrentCourseInfo->courseFogColors[2] >> 2;
            goto block_68;
        }
        var_a0 = gCurrentCourseInfo->courseFogColors[0] +
                 Math_Round(((gCurrentCourseInfo->courseFogColors[0] >> 2) - gCurrentCourseInfo->courseFogColors[0]) *
                            var_fv1);
        var_t0 = gCurrentCourseInfo->courseFogColors[1] +
                 Math_Round(((gCurrentCourseInfo->courseFogColors[1] >> 2) - gCurrentCourseInfo->courseFogColors[1]) *
                            var_fv1);
        var_a2 = gCurrentCourseInfo->courseFogColors[2] +
                 Math_Round(((gCurrentCourseInfo->courseFogColors[2] >> 2) - gCurrentCourseInfo->courseFogColors[2]) *
                            var_fv1);
    } else {
        var_a0 = gCurrentCourseInfo->courseFogColors[0];
        var_t0 = gCurrentCourseInfo->courseFogColors[1];
        var_a2 = gCurrentCourseInfo->courseFogColors[2];
    }
block_68:

    gDPSetFogColor(sCourseDisp++, var_a0, var_t0, var_a2, 255);

    sLastTrackShapeType = D_800F892C = -1;
    D_800F8958[0].chunk = D_800F8958[1].chunk = NULL;
    D_800F89C0 = 0;

    while (true) {
        var_fv1 = -10000.0f;

        segmentChunkGroup = sSegmentChunkGroups;
        do {
            if (var_fv1 < segmentChunkGroup->averageDepth) {
                var_fv1 = segmentChunkGroup->averageDepth;
                furthestChunkGroup = segmentChunkGroup;
            }
            segmentChunkGroup++;
        } while (segmentChunkGroup != segmentChunkGroupEnd);

        if (var_fv1 == -10000.0f) {
            break;
        }

        if (furthestChunkGroup->drawState == 1) {
            Course_DrawForwardChunkGroup(furthestChunkGroup);
        } else { // drawState == -1
            Course_DrawBackwardChunkGroup(furthestChunkGroup);
        }
        furthestChunkGroup->averageDepth = -20000.0f;
    }

    if (D_800F892C == 1) {
        gSPTexture(sCourseDisp++, 0, 0, 0, 1, G_OFF);
    } else {
        gSPTexture(sCourseDisp++, 0, 0, 0, 5, G_OFF);
    }
    return sCourseDisp;
}

s32 Course_CalculateChecksum(void) {
    s32 i;
    u32 checksum = COURSE_CONTEXT()->courseData.controlPointCount;

    for (i = 0; i < COURSE_CONTEXT()->courseData.controlPointCount; i++) {

        COURSE_CONTEXT()->courseData.controlPoint[i].trackSegmentInfo &= ~TRACK_JOIN_MASK;
        COURSE_CONTEXT()->courseData.controlPoint[i].trackSegmentInfo &= ~TRACK_FORM_MASK;
        COURSE_CONTEXT()->courseData.controlPoint[i].trackSegmentInfo &= ~TRACK_FLAG_CONTINUOUS;

        checksum +=
            (s32) ((COURSE_CONTEXT()->courseData.controlPoint[i].pos.x +
                    ((1.1f + (0.7f * i)) * COURSE_CONTEXT()->courseData.controlPoint[i].pos.y)) +
                   ((2.2f + (1.2f * i)) * COURSE_CONTEXT()->courseData.controlPoint[i].pos.z * (4.4f + (0.9f * i))) +
                   COURSE_CONTEXT()->courseData.controlPoint[i].radiusLeft +
                   ((5.5f + (0.8f * i)) * COURSE_CONTEXT()->courseData.controlPoint[i].radiusRight * 4.8f)) +
            COURSE_CONTEXT()->courseData.controlPoint[i].trackSegmentInfo * (0xFE - i) +
            COURSE_CONTEXT()->courseData.bankAngle[i] * (0x93DE - i * 2);
    }

    for (i = 0; i < COURSE_CONTEXT()->courseData.controlPointCount; i++) {
        checksum += (COURSE_CONTEXT()->courseData.pit[i] * i);
        checksum += (COURSE_CONTEXT()->courseData.dash[i] * (i + 0x10));
        checksum += (COURSE_CONTEXT()->courseData.dirt[i] * (i + 0x80));
        checksum += (COURSE_CONTEXT()->courseData.ice[i] * (i + 0x100));
        checksum += (COURSE_CONTEXT()->courseData.jump[i] * (i + 0x800));
        checksum += (COURSE_CONTEXT()->courseData.landmine[i] * (i + 0x1000));
        checksum += (COURSE_CONTEXT()->courseData.gate[i] * (i + 0x8000));
        checksum += (COURSE_CONTEXT()->courseData.building[i] * (i + 0x10000));
        checksum += (COURSE_CONTEXT()->courseData.sign[i] * (i + 0x80000));
    }

    return checksum;
}
