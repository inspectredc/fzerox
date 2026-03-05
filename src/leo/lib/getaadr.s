#include "asm.h"

.section .text, "ax"

LEAF(LeoGetAAdr)
.incbin "leo/lib/getaadr.textbin.bin"
