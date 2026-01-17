#include "global.h"
#include "fzx_thread.h"
#include "PR/leo.h"
#include "leo/mfs.h"

extern OSMesgQueue gMainThreadMesgQueue;

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
#ifdef VERSION_JP
    osWritebackDCacheAll();
    LeoFault_DrawReferUserGuide();
    LeoFault_DrawErrorNumber(err);
    osWritebackDCacheAll();
#else
    SLForceWritebackDCacheAll();
    LeoFault_DrawReferUserGuide();
    LeoFault_DrawErrorNumber(err);
    SLForceWritebackDCacheAll();
#endif
    while (true) {}
}

OSMesgQueue D_800E42D0;
OSMesg D_800E42E8[16];

extern s32 gMfsError;
extern LEODiskID D_i1_80428618;
extern LEODiskID leoBootID;

void DiskMount_Init(void) {

    func_80076310();
    osCreateMesgQueue(&D_800E42D0, D_800E42E8, ARRAY_COUNT(D_800E42E8));
#ifdef VERSION_JP
    Mfs_SetGameCode("01", "EFZJ");
#else
    Mfs_SetGameCode("01", "EFZE");
#endif
    if (Mfs_CreateLeoManager(LEO_MANAGER_REGION_JP, D_800E42E8, ARRAY_COUNT(D_800E42E8)) < 0) {
        switch (gMfsError) {
            case LEO_ERROR_DEVICE_COMMUNICATION_FAILURE:
                return;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
            case 0xF9:
            default:
                goto label;
                break;
        }
    }

label:
    if (gMfsError == 0xF9) {
        func_8007F520();
    }
    func_i1_8040428C();
    func_800762B0(D_i1_80428618);
    leoBootID = D_i1_80428618;

    switch (func_i1_804046F0()) {
        case 1:
            break;
        case 0:
            if (Mfs_InitRamArea(1) < 0) {}
            break;
        case -1:
            switch (gMfsError) {
                case 42:
                    break;
                case 23:
                    Mfs_InitRamArea(1);
                    break;
            }
            break;
    }
    Mfs_ModeSelectAsync(0, 0);
}
