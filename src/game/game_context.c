#include "global.h"
#include "fzx_racer.h"

CourseInfo gCourseInfos[56];       // 0x3480
#ifndef EXPANSION_KIT
SegmentChunk gSegmentChunks[1025]; // 0x18060
#else
SegmentChunk gSegmentChunks[769];  // 0x12060
#endif
CourseSegment D_802C2020[64];      // 0x2900
Racer gRacers[TOTAL_RACER_COUNT];  // 0x6DB0
