#include "asm.h"

#ifdef EXPANSION_KIT
.section .text, "ax"

LEAF(gspF3DEX2_Rej_fifoTextStart)
.incbin "rsp/f3dex2_rej.textbin.bin"
END(gspF3DEX2_Rej_fifoTextStart)
EXPORT(gspF3DEX2_Rej_fifoTextEnd)

.section .data, "wa"

SYM_START(gspF3DEX2_Rej_fifoDataStart)
.incbin "rsp/f3dex2_rej.databin.bin"
SYM_END(gspF3DEX2_Rej_fifoDataStart)
EXPORT(gspF3DEX2_Rej_fifoDataEnd)
#endif
