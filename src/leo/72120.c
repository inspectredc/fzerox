#include "PR/leo.h"

void func_i1_80403010(void) {
#if VERSION_US
    LeoGetAAdr2(0, NULL, NULL, NULL);
#elif VERSION_PAL
    LeoGetAAdr2(0, NULL, NULL, NULL);
    LeoByteToLBA(0, 0, NULL);
    LeoReset();
    LeoLBAToByte(0, 0, NULL);
    LeoReadWrite(NULL, 0, 0, NULL, 0, NULL);
    LeoSpdlMotor(NULL, 0, NULL);
    LeoReadDiskID(NULL, NULL, NULL);
    LeoTestUnitReady(NULL);
    LeoCJCreateLeoManager(0, 0, NULL, 0);
    LeoResetClear();
    LeoGetKAdr(0);
    LeoCreateLeoManager(0, 0, NULL, 0);
    LeoCACreateLeoManager(0, 0, NULL, 0);
    LeoGetAAdr(0, NULL, NULL, NULL);
    LeoReadCapacity(NULL, 0);
    LeoRezero(NULL, NULL);
    LeoSeek(NULL, 0, NULL);
    LeoReadRTC(NULL, NULL);
    LeoSetRTC(NULL, NULL, NULL);
    LeoModeSelectAsync(NULL, 0, 0, NULL);
#endif
}
