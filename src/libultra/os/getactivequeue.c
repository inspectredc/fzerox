#include "PR/os_internal.h"
#include "PR/osint.h"

OSThread* __osGetActiveQueue(void) {
    return __osActiveQueue;
}
