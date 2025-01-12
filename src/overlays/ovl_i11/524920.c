#include "global.h"
#include "segment_symbols.h"

extern OSMesgQueue gDmaMesgQueue;
extern LEODiskID D_800CD2B0;

u8 D_i11_800FC9F0 = true;

void func_i11_800FC730(void) {
    LEOCmd cmdBlock;
    s32* ptr;
    s32 pad;
    s32 sp58;
    s32 pad2;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 pad3[2];

    leoBootID = D_800CD2B0;

    osAppNMIBuffer[0] = SEGMENT_ROM_START(unk_nmi);
    osAppNMIBuffer[1] = SEGMENT_ROM_END(unk_nmi);

    if (osAppNMIBuffer[15] != 0x20DE1529) {
        osAppNMIBuffer[15] = 0x20DE1529;
        PRINTF("===================================\n");
        PRINTF("THIS GAME IS COLD START (POWER ON)\n");
        PRINTF("ROMINFO 0x%X-0x%X\n", osAppNMIBuffer[0], osAppNMIBuffer[1]);
        PRINTF("===================================\n");
        D_i11_800FC9F0 = true;
    } else {
        PRINTF("===================================\n");
        PRINTF("THIS GAME IS HOT START (RESET GAME)\n");
        PRINTF("ROMINFO 0x%X-0x%X\n", osAppNMIBuffer[0], osAppNMIBuffer[1]);
        PRINTF("===================================\n");
        D_i11_800FC9F0 = false;
    }
    ptr = 0x80600000;

    ptr[1] = 0xFF;
    ptr[2] = 0xFF;
    ptr[3] = 0xFF;
    ptr[9] = 0xFF;
    ptr[10] = 0xFF;

    func_80075D10(&cmdBlock, 0, 0x341, ptr, 1, &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, NULL, 1);
    sp58 = ptr[1];
    sp40 = ptr[3];
    sp50 = ptr[10] - ptr[9];
    sp4C = ptr[2] - ptr[1];
    PRINTF("INFO %d, 0x%x-0x%x-0x%x-0x%x, %dBytes, %dLBAs\n");
    if (D_i11_800FC9F0) {
        func_80075D10(&cmdBlock, 0, sp58, sp40, sp4C, &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, 1);
        bzero(ptr[9], sp50);
    } else {
        switch (ptr[0]) {
            case 0:
                func_80075D10(&cmdBlock, 0, sp58, sp40, sp4C, &gDmaMesgQueue);
                osRecvMesg(&gDmaMesgQueue, NULL, 1);
                break;
            case 1:
                PRINTF("CODE USED LBA %d\n");
                LeoByteToLBA(sp58, ptr[6] - ptr[3], &sp48);
                sp48--;
                LeoLBAToByte(sp58, sp48, &sp44);
                sp44 += sp40;
                func_80075D10(&cmdBlock, 0, sp58, sp40, 1, &gDmaMesgQueue);
                osRecvMesg(&gDmaMesgQueue, NULL, 1);
                sp4C -= sp48;
                sp48 += sp58;
                func_80075D10(&cmdBlock, 0, sp48, sp44, sp4C, &gDmaMesgQueue);
                osRecvMesg(&gDmaMesgQueue, NULL, 1);
                break;
            case 2:
                break;
        }
        bzero(ptr[9], sp50);
    }
    PRINTF("RESET GAME !!!\n");
    osResetType = 2;
    LeoBootGame(sp40);
}
