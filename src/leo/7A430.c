#include "global.h"
#include "unk_leo.h"

s32 (*D_i1_8042A620)(LEOCmd*, s32, u32, void*, u32, OSMesgQueue*);
s32 (*D_i1_8042A624)(LEOCmd*, u32, OSMesgQueue*);
s32 (*D_i1_8042A628)(LEOCmd*, u8, OSMesgQueue*);
s32 (*D_i1_8042A62C)(LEOCmd*, LEODiskID*, OSMesgQueue*);
s32 (*D_i1_8042A630)(LEOCmd*, OSMesgQueue*);
s32 (*D_i1_8042A634)(LEOCmd*, LEODiskTime*, OSMesgQueue*);
s32 (*D_i1_8042A638)(LEOCmd*, u32, u32, OSMesgQueue*);
s32 (*D_i1_8042A63C)(LEOCmd*, OSMesgQueue*);

void func_i1_8040B320(void) {
    D_i1_8042A620 = LeoReadWrite;
    D_i1_8042A624 = LeoSeek;
    D_i1_8042A628 = LeoSpdlMotor;
    D_i1_8042A62C = LeoReadDiskID;
    D_i1_8042A630 = LeoReadRTC;
    D_i1_8042A634 = LeoSetRTC;
    D_i1_8042A638 = LeoModeSelectAsync;
    D_i1_8042A63C = LeoRezero;
    return;
}

void func_i1_8040B3B8(s32 arg0, void* arg1) {
    switch (arg0) {
        case 0:
            D_i1_8042A620 = arg1;
            break;
        case 1:
            D_i1_8042A624 = arg1;
            break;
        case 2:
            D_i1_8042A628 = arg1;
            break;
        case 3:
            D_i1_8042A62C = arg1;
            break;
        case 4:
            D_i1_8042A630 = arg1;
            break;
        case 5:
            D_i1_8042A634 = arg1;
            break;
        case 6:
            D_i1_8042A638 = arg1;
            break;
        case 7:
            D_i1_8042A63C = arg1;
            break;
        default:
            break;
    }
}
