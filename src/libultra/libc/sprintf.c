#include "PR/xstdio.h"
#include "libc/string.h"
#include "PR/os.h"

// TODO: this comes from a header
#ident "$Revision: 1.23 $"

static char* proutSprintf(char* dst, const char* src, size_t count);

static char* proutSprintf(char* dst, const char* src, size_t count) {
    return (char*) memcpy((u8*) dst, (u8*) src, count) + count;
}

int sprintf(char* dst, const char* fmt, ...) {
    s32 ans;
    va_list ap;
    va_start(ap, fmt);
    ans = _Printf(proutSprintf, dst, fmt, ap);
    if (ans >= 0) {
        dst[ans] = 0;
    }
    return ans;
}
