#include "asm.h"

.section .text, "ax"

LEAF(gspF3DFLX2_Rej_fifoTextStart)
.incbin "rsp/f3dflx2.textbin.bin"
END(gspF3DFLX2_Rej_fifoTextStart)
EXPORT(gspF3DFLX2_Rej_fifoTextEnd)

.section .data, "wa"

SYM_START(gspF3DFLX2_Rej_fifoDataStart)
.incbin "rsp/f3dflx2.databin.bin"
SYM_END(gspF3DFLX2_Rej_fifoDataStart)
EXPORT(gspF3DFLX2_Rej_fifoDataEnd)
