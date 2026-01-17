#include "global.h"

bool D_800CD510 = false;
s32 gSkyboxType;
s32 gVenueType;
RaceStats gCupRaceStats[1][6];

void func_8007F4E0(s32 venue, s32 skybox) {
    D_800CD510 = true;
    gVenueType = venue;
    gSkyboxType = skybox;
}

s8 gRecordNameEntered[4];
s16 gForceCredits;

void func_8007F500(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gRecordNameEntered[i] = 0;
    }

    gForceCredits = false;
}
