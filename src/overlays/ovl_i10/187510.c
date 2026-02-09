#include "global.h"
#include "leo/mfs.h"

#include ASSET_SOURCE_EK(overlays/ovl_i10/a187510/a187510.c)

extern FrameBuffer* gFrameBuffers[];

void func_i10_8012B780(u16* texPtr, s32 left, s32 top, s32 widthToDraw, s32 arg4, s32 texWidth) {
    u16* var_v0;
    s32 i;
    s32 j;

    var_v0 = gFrameBuffers[0];
    var_v0 += top * SCREEN_WIDTH + left;

    for (i = 0; i < arg4; i++) {
        for (j = 0; j < widthToDraw; j++) {
            *var_v0++ = *texPtr++;
        }
        texPtr += texWidth - widthToDraw;
        var_v0 -= widthToDraw;
        var_v0 += SCREEN_WIDTH;
    }
}

void func_i10_8012B854(void) {
    func_i10_8012B780(aDDLoadingTex, 96, 180, 64, 16, 64);
}

void func_i10_8012B894(s32 progress) {
    func_i10_8012B780(aDDLoadMachineTrailTex, 160, 180, progress - 160, 16, 32);
    func_i10_8012B780(aDDLoadBlueFalconTex, progress, 180, 32, 16, 32);
}

extern s32 D_800D11C8[6];
extern OSMesgQueue gMFSMesgQ;
extern u8 gEditCupTrackNames[4 * 6][9];

void func_i10_8012B904(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        gEditCupTrackNames[i][0] = '\0';
    }
    func_8076852C(MFS_ENTRY_WORKING_DIR, "CRS_ENTRY", "CENT", gEditCupTrackNames, sizeof(gEditCupTrackNames));
    osRecvMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);
    func_8076852C(MFS_ENTRY_WORKING_DIR, "OPTION", "OPT", D_800D11C8, sizeof(D_800D11C8));
    osRecvMesg(&gMFSMesgQ, NULL, OS_MESG_BLOCK);

    for (i = 0; i < 6; i++) {
        if (Mfs_ValidateFileName(gEditCupTrackNames[i]) != 0) {
            gEditCupTrackNames[i][0] = '\0';
        }
    }
    for (i = 0; i < 4; i++) {
        if ((D_800D11C8[i] < 0) || (D_800D11C8[i] >= 2)) {
            D_800D11C8[i] = 1;
        }
    }
    if ((D_800D11C8[4] < 0) || (D_800D11C8[4] >= 9)) {
        D_800D11C8[4] = 4;
    }
}
