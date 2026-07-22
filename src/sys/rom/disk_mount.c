#include "global.h"
#include "fzx_thread.h"
#include "PR/leo.h"
#include "leo/mfs.h"

extern OSMesgQueue gMainThreadMesgQueue;

#if BUILD_REVISION <= REVISION_B
void func_8007F520(void) {
    u8 i;
    s32 err;
    s32 msg;

    for (i = 0; i < 30; i++) {
        do {
            osRecvMesg(&gMainThreadMesgQueue, &msg, OS_MESG_BLOCK);
        } while (msg != EVENT_MESG_VI);

        LeoResetClear();
        err = SLLeoReadDiskID_for_start();
        if (err != LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED) {
            return;
        }
    }
#if BUILD_REVISION <= REVISION_A
    osWritebackDCacheAll();
    LeoFault_DrawReferUserGuide();
    LeoFault_DrawErrorNumber(err);
    osWritebackDCacheAll();
#else // REVISION_B
    SLForceWritebackDCacheAll();
    LeoFault_DrawReferUserGuide();
    LeoFault_DrawErrorNumber(err);
    SLForceWritebackDCacheAll();
#endif
    while (true) {}
}
#endif

OSMesgQueue D_800E42D0;
OSMesg D_800E42E8[16];

extern s32 gMfsError;
extern LEODiskID D_i1_80428618;
extern LEODiskID leoBootID;
extern LEODiskID D_800CD2B0;

void DiskMount_Init(void) {

    func_80076310();
    osCreateMesgQueue(&D_800E42D0, D_800E42E8, ARRAY_COUNT(D_800E42E8));
#if LANGUAGE == LANGUAGE_JPN
    Mfs_SetGameCode("01", "EFZJ");
#else
    Mfs_SetGameCode("01", "EFZE");
#endif
    if (Mfs_CreateLeoManager(LEO_MANAGER_REGION_JP, D_800E42E8, ARRAY_COUNT(D_800E42E8)) < 0) {
        switch (gMfsError) {
            case LEO_ERROR_DEVICE_COMMUNICATION_FAILURE:
                return;
#if BUILD_REVISION <= REVISION_B
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
#endif
            case 0xF9:
            default:
#if BUILD_REVISION <= REVISION_B
                goto label;
#endif
                break;
        }
    }

label:
    if (gMfsError == 0xF9) {
#if BUILD_REVISION <= REVISION_B
        func_8007F520();
#else // REVISION_C
        SLLeoResetClear();
#endif
    }

#if BUILD_REVISION <= REVISION_B
    func_i1_8040428C();
    func_800762B0(D_i1_80428618);
#else // REVISION_C
    func_800763B0();
    D_i1_80428618 = D_800CD2B0;
    func_i1_80404204();
#endif

#if BUILD_REVISION == REVISION_C
    gWorkingDirectory = MFS_ENTRY_ROOT_DIR;
    D_i1_80428644 = LEO_ERROR_GOOD;
    gMfsRamArea.id.diskId[0] = '\0';
#endif
    leoBootID = D_i1_80428618;

    switch (func_i1_804046F0()) {
        case 1:
            break;
        case 0:
#if MFS_VERSION == MFS_VERSION_A
            if (Mfs_InitRamArea(1) < 0) {}
#else
            if (Mfs_InitRamArea(1, MFS_VOLUME_ATTR_VPROTECT_WRITE, 0) < 0) {}
#endif
            break;
        case -1:
            switch (gMfsError) {
                case LEO_ERROR_MEDIUM_NOT_PRESENT:
                    break;
                case LEO_ERROR_UNRECOVERED_READ_ERROR:
#if MFS_VERSION == MFS_VERSION_A
                    Mfs_InitRamArea(1);
#else
                    Mfs_InitRamArea(1, MFS_VOLUME_ATTR_VPROTECT_WRITE, 0);
#endif
                    break;
            }
            break;
    }
#if BUILD_REVISION <= REVISION_B
    Mfs_ModeSelectAsync(0, 0);
#endif
}
