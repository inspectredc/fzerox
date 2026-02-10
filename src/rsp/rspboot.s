#include "asm.h"

.section .text, "ax"

LEAF(rspbootTextStart)
.incbin "rsp/rspboot.textbin.bin"
END(rspbootTextStart)
EXPORT(rspbootTextEnd)
