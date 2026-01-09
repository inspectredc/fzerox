#include "leo/mfs.h"

s32 (*gLeoReadWriteFunc)(LEOCmd*, s32, u32, void*, u32, OSMesgQueue*);
s32 (*gLeoSeekFunc)(LEOCmd*, u32, OSMesgQueue*);
s32 (*gLeoSpdlMotorFunc)(LEOCmd*, u8, OSMesgQueue*);
s32 (*gLeoReadDiskIDFunc)(LEOCmd*, LEODiskID*, OSMesgQueue*);
s32 (*gLeoReadRTCFunc)(LEOCmd*, OSMesgQueue*);
s32 (*gLeoSetRTCFunc)(LEOCmd*, LEODiskTime*, OSMesgQueue*);
s32 (*gLeoModeSelectAsyncFunc)(LEOCmd*, u32, u32, OSMesgQueue*);
s32 (*gLeoRezeroFunc)(LEOCmd*, OSMesgQueue*);

void Mfs_SetDefaultLeoHandlerFuncs(void) {
    gLeoReadWriteFunc = LeoReadWrite;
    gLeoSeekFunc = LeoSeek;
    gLeoSpdlMotorFunc = LeoSpdlMotor;
    gLeoReadDiskIDFunc = LeoReadDiskID;
    gLeoReadRTCFunc = LeoReadRTC;
    gLeoSetRTCFunc = LeoSetRTC;
    gLeoModeSelectAsyncFunc = LeoModeSelectAsync;
    gLeoRezeroFunc = LeoRezero;
    return;
}

#if MFS_VERSION == MFS_VERSION_A
void Mfs_SetLeoHandlerFunc(s32 handlerId, void* func) {
    switch (handlerId) {
        case 0:
            gLeoReadWriteFunc = func;
            break;
        case 1:
            gLeoSeekFunc = func;
            break;
        case 2:
            gLeoSpdlMotorFunc = func;
            break;
        case 3:
            gLeoReadDiskIDFunc = func;
            break;
        case 4:
            gLeoReadRTCFunc = func;
            break;
        case 5:
            gLeoSetRTCFunc = func;
            break;
        case 6:
            gLeoModeSelectAsyncFunc = func;
            break;
        case 7:
            gLeoRezeroFunc = func;
            break;
        default:
            break;
    }
}
#endif
