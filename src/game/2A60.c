#include "global.h"
#include "libultra/ultra64.h"
#include "fzxthread.h"

void func_800BA268(void);
s32 func_800BB49C(void);
extern OSMesgQueue D_800DCA98;
extern OSMesgQueue D_800DCAE0;
extern s32 D_800DCCC4;
extern void* D_800DCE30;

void func_80068A60(s32 arg0) {
    static s32 D_800CCFF0 = 0;
    func_800BA268();

    while (true) {
        MQ_GET_MESG(&D_800DCA98, &D_800DCE30);
        MQ_WAIT_FOR_MESG(&D_800DCA98, &D_800DCE30);
        if (D_800CCFF0 != 0) {
            D_800DCCC4 = D_800CCFF0;
            osSendMesg(&D_800DCAE0, (void*) 0x16, 1);
        }
        D_800CCFF0 = func_800BB49C();
    }
}
