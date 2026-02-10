#include "asm.h"

.section .text, "ax"

LEAF(aspMainTextStart)
.incbin "rsp/aspmain.textbin.bin"
END(aspMainTextStart)
EXPORT(aspMainTextEnd)

.section .data, "wa"

SYM_START(aspMainDataStart)
.incbin "rsp/aspmain.databin.bin"
SYM_END(aspMainDataStart)
EXPORT(aspMainDataEnd)
