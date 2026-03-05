#include "asm.h"

.section .text, "ax"

LEAF(gspF3DLX2_Rej_fifoTextStart)
.incbin "rsp/f3dlx2.textbin.bin"
END(gspF3DLX2_Rej_fifoTextStart)
EXPORT(gspF3DLX2_Rej_fifoTextEnd)

.section .data, "wa"

SYM_START(gspF3DLX2_Rej_fifoDataStart)
.incbin "rsp/f3dlx2.databin.bin"
SYM_END(gspF3DLX2_Rej_fifoDataStart)
EXPORT(gspF3DLX2_Rej_fifoDataEnd)
