#include "global.h"
#include "fzx_thread.h"

void func_80076490(void) {
}

extern OSMesgQueue gDmaMesgQueue;
extern OSIoMesg gDmaIOMsg;
extern OSPiHandle* gCartRomHandle;

void Dma_RomCopy(u8* romAddr, u8* ramAddr, size_t size) {
    OSMesg msgBuf[7];

    gDmaIOMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    gDmaIOMsg.hdr.retQueue = &gDmaMesgQueue;
    gDmaIOMsg.dramAddr = osPhysicalToVirtual(ramAddr);
    gDmaIOMsg.devAddr = romAddr;
    gDmaIOMsg.size = size;
    gCartRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
#ifndef EXPANSION_KIT
    osEPiStartDma(gCartRomHandle, &gDmaIOMsg, OS_READ);
#else
    func_80768B88(gCartRomHandle, &gDmaIOMsg, OS_READ);
#endif
    osRecvMesg(&gDmaMesgQueue, msgBuf, OS_MESG_BLOCK);
}

void Dma_RomCopyWithBssInit(u8* romAddr, u8* ramAddr, size_t size, void* bssAddr, size_t bssSize) {
    OSMesg msgBuf[7];

    gDmaIOMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    gDmaIOMsg.hdr.retQueue = &gDmaMesgQueue;
    gDmaIOMsg.dramAddr = osPhysicalToVirtual(ramAddr);
    gDmaIOMsg.devAddr = romAddr;
    gDmaIOMsg.size = size;
    gCartRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
#ifndef EXPANSION_KIT
    osEPiStartDma(gCartRomHandle, &gDmaIOMsg, OS_READ);
#else
    func_80768B88(gCartRomHandle, &gDmaIOMsg, OS_READ);
#endif
    bzero(bssAddr, bssSize);
    osRecvMesg(&gDmaMesgQueue, msgBuf, OS_MESG_BLOCK);
}

void Dma_LoadAssets(u8* romAddr, u8* ramAddr, size_t size) {
    s32 remainder;
    s32 i;
    s32 numBlocks = size / 1024;

    for (i = 0; i < numBlocks; i++) {
        Dma_RomCopy(romAddr, ramAddr, 0x400);

        romAddr += 0x400;
        ramAddr += 0x400;
    }
    remainder = size % 1024;
    if (remainder != 0) {
        Dma_RomCopy(romAddr, ramAddr, remainder);
    }
}

void Dma_LoadOverlay(u8* romAddr, u8* ramAddr, size_t size, void* bssAddr, size_t bssSize) {
    s32 remainder;
    s32 i;
    s32 numBlocks;

    numBlocks = size / 1024;

    for (i = 0; i < numBlocks; i++) {
        Dma_RomCopy(romAddr, ramAddr, 0x400);

        romAddr += 0x400;
        ramAddr += 0x400;
    }
    remainder = size % 1024;
    if (remainder != 0) {
        Dma_RomCopyWithBssInit(romAddr, ramAddr, remainder, bssAddr, bssSize);
    }
}
