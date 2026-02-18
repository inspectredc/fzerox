#include "libultra/ultra64.h"

s8 gTestMessageOvl[16];
void Mod_Entry(void)
{
    gTestMessageOvl[4] = 'B';
    gTestMessageOvl[3] = 'D';
    gTestMessageOvl[0] = 'D';
    gTestMessageOvl[1] = 'E';
    gTestMessageOvl[2] = 'A';
    gTestMessageOvl[5] = 'E';
    gTestMessageOvl[6] = 'E';
    gTestMessageOvl[7] = 'F';
}
