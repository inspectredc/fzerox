#include "PR/leo.h"
#include "PR/os_internal.h"
#include "leo/leo_internal.h"
#include "libc/stdint.h"

void __LeoBootGame2(void* entry);
void __LeoBootGame3(void* entry);

void LeoBootGame(void* entry) {
    u8* ptr;
    u8 key;
    u32 i;

    // Descramble __LeoBootGame2
    ptr = (u8*) &__LeoBootGame2;
    // Define difference key (a sum of each byte of __LeoBootGame2 address)
    key = ((((uintptr_t) ptr & 0xFF000000) >> 0x18) + (((uintptr_t) ptr & 0x00FF0000) >> 0x10) +
           (((uintptr_t) ptr & 0x0000FF00) >> 0x08) + (((uintptr_t) ptr & 0x000000FF))) &
          0xFF;
    for (i = 0; i < 0x324; i += 4) {
        ptr[2] -= key;
        ptr[3] += key;
        ptr += 4;
    }
    osWritebackDCacheAll();
    osInvalICache(__LeoBootGame2, 0x324);

    // Descramble __LeoBootGame3
    ptr = (u8*) &__LeoBootGame3;
    for (i = 0; i < 0x60; i += 4) {
        ptr[2] -= key;
        ptr[3] += key;
        ptr += 4;
    }
    osWritebackDCacheAll();
    osInvalICache(__LeoBootGame3, 0x60);

    __LeoBootGame2(entry);
}

// -----------------------------------------
// Encrypted function
// -----------------------------------------

// This MUST be scrambled by the build process or they will not be executable
// at runtime when descrambled.
void __LeoBootGame2(void* entry) {
    u8* entry2 = (u8*) entry;
    u32 i;
    s32 sp134;
    u8 sp34[0x100];
    vu32* var_v0;

    sp134 = 0;
    bzero(LeoBootGame, 0x13C);
    osWritebackDCache(LeoBootGame, 0x13C);
    __osSetSR(SR_CU1 | SR_CU0);

    *(u8*) 0xA0000010 = (u32) (LEO_country_code & 0xFF000000) >> 0x18;

    while ((!IO_READ(SP_STATUS_REG)) & SP_STATUS_HALT) {}

    IO_WRITE(SP_STATUS_REG, SP_SET_HALT | SP_CLR_INTR);

    while (sp134 < 0x50) {
        sp34[(sp134 * 0x11) % 256] = entry2[sp134];
        sp134++;
    }

    while (IO_READ(SP_DMA_BUSY_REG) & 1) {}

    IO_WRITE(PI_STATUS_REG, PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY);

    while (sp134 < 0xAA) {
        sp34[(sp134 * 0x11) % 256] = entry2[sp134];
        sp134++;
    }

    while (IO_READ(VI_CURRENT_REG) >= 11) {}

    IO_WRITE(VI_INTR_REG, 0x3FF);
    IO_WRITE(VI_H_START_REG, 0);
    IO_WRITE(VI_CURRENT_REG, 0);
    *(u8*) 0xA0000190 = LEO_country_code & 0xFF;
    IO_WRITE(AI_DRAM_ADDR_REG, 0);
    IO_WRITE(AI_LEN_REG, 0);

    while (sp134 < 0x100) {
        sp34[(sp134 * 0x11) % 256] = entry2[sp134];
        sp134++;
    }

    bcopy(&sp34, entry2, 0x100);
    *(u8*) 0xA0000110 = (u32) (LEO_country_code & 0xFF00) >> 8;
    __osSetCause(0);
    __osSetCount(0);
    __osSetCompare(0);
    IO_WRITE(SP_STATUS_REG, SP_SET_HALT | SP_CLR_BROKE | SP_CLR_INTR | SP_CLR_SSTEP | SP_CLR_INTR_BREAK | SP_CLR_SIG0 |
                                SP_CLR_SIG1 | SP_CLR_SIG2 | SP_CLR_SIG3 | SP_CLR_SIG4 | SP_CLR_SIG5 | SP_CLR_SIG6 |
                                SP_CLR_SIG7);
    *(u8*) 0xA0000090 = (u32) (LEO_country_code & 0xFF0000) >> 0x10;
    IO_WRITE(MI_INTR_MASK_REG, 0);
    IO_WRITE(SI_STATUS_REG, 0);
    IO_WRITE(AI_STATUS_REG, 0);
    IO_WRITE(MI_MODE_REG, MI_CLR_DP_INTR);
    IO_WRITE(PI_STATUS_REG, PI_STATUS_IO_BUSY);
    osResetType = 2;

    var_v0 = (vu32*) 0xA4001000;
    for (i = 0; i < 0x100; i++) {
        *var_v0++ = 0;
    }

    var_v0 = (vu32*) 0xA4000000;
    for (i = 0; i < 0x100; i++) {
        *var_v0++ = 0;
    }
    bzero(__LeoBootGame2, 0x2E4);
    osWritebackDCache(__LeoBootGame2, 0x2E4);
    __LeoBootGame3(entry2);
}
