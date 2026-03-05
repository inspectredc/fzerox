#include "asm.h"

.section .text, "ax"

LEAF(gspL3DEX2_fifoTextStart)
.incbin "rsp/l3dex2.textbin.bin"
END(gspL3DEX2_fifoTextStart)
EXPORT(gspL3DEX2_fifoTextEnd)

.section .data, "wa"

SYM_START(gspL3DEX2_fifoDataStart)
.incbin "rsp/l3dex2.databin.bin"
SYM_END(gspL3DEX2_fifoDataStart)
EXPORT(gspL3DEX2_fifoDataEnd)
