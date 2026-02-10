#include "asm.h"

.section .text, "ax"

LEAF(LeoGetKAdr)
.incbin "leo/lib/getkadr.textbin.bin"
