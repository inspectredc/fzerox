#include "PR/leo.h"

void func_i1_804030A0(void) {
    //! @bug leads to null pointer dereference
    LeoByteToLBA(0, 1, NULL);
}
