#include "global.h"

UNUSED s32 D_800CD2A0 = -1;

f32 Math_VectorGetDistance(Vec3f arg0, Vec3f arg1) {
    return sqrtf(SQ(arg1.x - arg0.x) + SQ(arg1.y - arg0.y) + SQ(arg1.z - arg0.z));
}
