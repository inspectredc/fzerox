#include "asm.h"

.section .text, "ax"

LEAF(gspF3DEX2_fifoTextStart)
.incbin "rsp/f3dex2.textbin.bin"
END(gspF3DEX2_fifoTextStart)
EXPORT(gspF3DEX2_fifoTextEnd)

.section .data, "wa"

SYM_START(gspF3DEX2_fifoDataStart)
.incbin "rsp/f3dex2.databin.bin"
SYM_END(gspF3DEX2_fifoDataStart)
EXPORT(gspF3DEX2_fifoDataEnd)
