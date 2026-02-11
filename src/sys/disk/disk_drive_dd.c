#include "global.h"

extern Controller gSharedController;
extern OSMesgQueue gSerialEventQueue;

s32 D_8076CB40 = -1;
s32 D_8076CB44 = 0;

void func_807038B0(void) {
    s32 sp24;

    PRINTF("WAIT MEDIA INIT\n");
    PRINTF("WAIT MEDIA START\n");
    PRINTF("WAIT RECOVER MANAGE AREA\n");

    func_8070F8A4(-1, 6);
    sp24 = osRecvMesg(&gSerialEventQueue, NULL, OS_MESG_NOBLOCK);
    do {
        osContStartReadData(&gSerialEventQueue);
        Controller_UpdateInputs();
    } while (!(gSharedController.buttonPressed & BTN_A));
    if (sp24 != -1) {
        osContStartReadData(&gSerialEventQueue);
    }
    func_8070F8A4(-1, 0xA);
}

void func_80703948(void) {
    s32 sp24;

    func_8070F8A4(-1, 7);
    sp24 = osRecvMesg(&gSerialEventQueue, NULL, OS_MESG_NOBLOCK);
    do {
        osContStartReadData(&gSerialEventQueue);
        Controller_UpdateInputs();
    } while (!(gSharedController.buttonPressed & BTN_A));
    if (sp24 != -1) {
        osContStartReadData(&gSerialEventQueue);
    }
}

extern u8 D_i1_80415190[];
extern OSMesgQueue gDmaMesgQueue;

s32 func_800750B0(s32 startLba, void* vram, s32 diskSize, s32 bssSize) {
    void* bssStart;
    s32 sp58;
    s32 lbaCount;
    s32 nBytes;
    LEOCmd cmdBlock;

    nBytes = 0;
    LeoByteToLBA(startLba, diskSize, &lbaCount);
    osVirtualToPhysical(vram);
    bssStart = (uintptr_t) vram + diskSize;
    osVirtualToPhysical(bssStart);
    osVirtualToPhysical((uintptr_t) bssStart + bssSize);

    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n", startLba, vram, bssStart, (uintptr_t) bssStart + bssSize,
           lbaCount);
    PRINTF("========================================================\n");

    if (lbaCount - 1) {
        LeoLBAToByte(startLba, lbaCount - 1, &nBytes);
        SLLeoReadWrite(&cmdBlock, OS_READ, startLba, osPhysicalToVirtual((uintptr_t) vram), lbaCount - 1,
                       &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
    }
    diskSize -= nBytes;
    SLLeoReadWrite(&cmdBlock, OS_READ, (startLba + lbaCount) - 1, osPhysicalToVirtual((uintptr_t) D_i1_80415190), 1,
                   &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
    bcopy(D_i1_80415190, osPhysicalToVirtual((uintptr_t) vram + nBytes), diskSize);
    bzero((uintptr_t) vram + nBytes + diskSize, bssSize);
    D_8076CB44 = 0;
    return sp58;
}

s32 DiskDrive_LoadData(s32 startLba, void* vram, s32 diskSize, s32 bssSize) {
    void* bssStart;
    s32 sp58;
    s32 lbaCount;
    s32 nBytes;
    LEOCmd cmdBlock;

    nBytes = 0;
    LeoByteToLBA(startLba, diskSize, &lbaCount);
    osVirtualToPhysical(vram);
    bssStart = (uintptr_t) vram + diskSize;
    osVirtualToPhysical(bssStart);
    osVirtualToPhysical((uintptr_t) bssStart + bssSize);

    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n", startLba, vram, bssStart, (uintptr_t) bssStart + bssSize,
           lbaCount);
    PRINTF("========================================================\n");

    if (lbaCount - 1) {
        LeoLBAToByte(startLba, lbaCount - 1, &nBytes);
        func_80768AF0(&cmdBlock, OS_READ, startLba, osPhysicalToVirtual((uintptr_t) vram), lbaCount - 1,
                      &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
    }
    diskSize -= nBytes;
    func_80768AF0(&cmdBlock, OS_READ, (startLba + lbaCount) - 1, osPhysicalToVirtual((uintptr_t) D_i1_80415190), 1,
                  &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
    bcopy(D_i1_80415190, osPhysicalToVirtual((uintptr_t) vram + nBytes), diskSize);
    bzero((uintptr_t) vram + nBytes + diskSize, bssSize);
    return sp58;
}

s32 DiskDrive_LoadOverlay(s32 startLba, void* vram, s32 diskSize, s32 bssSize) {
    void* bssStart;
    s32 sp58;
    s32 lbaCount;
    s32 nBytes;
    LEOCmd cmdBlock;

    nBytes = 0;
    LeoByteToLBA(startLba, diskSize, &lbaCount);
    osVirtualToPhysical(vram);
    bssStart = (uintptr_t) vram + diskSize;
    osVirtualToPhysical(bssStart);
    osVirtualToPhysical((uintptr_t) bssStart + bssSize);

    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n", startLba, vram, bssStart, (uintptr_t) bssStart + bssSize,
           lbaCount);
    PRINTF("========================================================\n");

    if (lbaCount - 1) {
        LeoLBAToByte(startLba, lbaCount - 1, &nBytes);
        func_80768A5C(&cmdBlock, OS_READ, startLba, osPhysicalToVirtual((uintptr_t) vram), lbaCount - 1,
                      &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
    }
    diskSize -= nBytes;
    func_80768A5C(&cmdBlock, OS_READ, (startLba + lbaCount) - 1, osPhysicalToVirtual((uintptr_t) D_i1_80415190), 1,
                  &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
    bcopy(&D_i1_80415190, osPhysicalToVirtual((uintptr_t) vram + nBytes), diskSize);
    bzero((uintptr_t) vram + nBytes + diskSize, bssSize);
    return sp58;
}

extern s32 D_800CCFB0;

s32 DiskDrive_LoadOverlayProgressBar(s32 startLba, void* vram, s32 diskSize, s32 bssSize) {
    void* bssStart;
    s32 sp70;
    s32 lbaCount;
    s32 progress;
    LEOCmd sp4C;
    OSMesg sp48;
    s32 pad[2];

    LeoByteToLBA(startLba, diskSize, &lbaCount);
    osVirtualToPhysical(vram);
    bssStart = (uintptr_t) vram + diskSize;
    osVirtualToPhysical(bssStart);
    osVirtualToPhysical((uintptr_t) bssStart + bssSize);
    func_80768A5C(&sp4C, OS_READ, startLba, vram, lbaCount, &gDmaMesgQueue);

    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n", startLba, vram, bssStart, (uintptr_t) bssStart + bssSize,
           lbaCount);
    PRINTF("========================================================\n");

    if (D_8076CB40 != -1) {
        func_i10_8012B854();
    }

    while (osRecvMesg(&gDmaMesgQueue, &sp48, OS_MESG_NOBLOCK) == -1) {
        if (D_8076CB40 != -1) {
            osWritebackDCacheAll();
            progress = (D_800CCFB0 - D_8076CB40) / 6 + 160;
            if (progress > 192) {
                progress = 192;
            }
            func_i10_8012B894(progress);
            osWritebackDCacheAll();
        }
    }
    bzero(bssStart, bssSize);
    return sp70;
}

void DiskDrive_InitRomSegmentPairs(void) {
    size_t size = osAppNMIBuffer[1] - osAppNMIBuffer[0];
    Dma_ClearRomCopy(osAppNMIBuffer[0], gRomSegmentPairs, size);
}

extern FrameBuffer* gFrameBuffers[];

void DiskDrive_DrawErrorBackground(void) {
    u8 i;
    u64* var_v0;
    u64* temp;

    SLForceWritebackDCacheAll();

    for (i = 0; i < 3; i++) {
        // FAKE
        temp = gFrameBuffers[i]->buffer;
        var_v0 = &gFrameBuffers[i]->buffer[19199];
        while (var_v0 >= temp) {
            var_v0--;
            *(var_v0 + 1) = 0x0001000100010001;
        }
    }
    SLForceWritebackDCacheAll();
}
