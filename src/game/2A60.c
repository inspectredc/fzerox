#include "global.h"
#include "libultra/ultra64.h"
#include "audio.h"
#include "fzxthread.h"

extern OSMesgQueue D_800DCA98;
extern OSMesgQueue D_800DCAE0;
extern OSTask* D_800DCCC4;
extern void* D_800DCE30;

void func_80068A60(void* arg0) {
    static AudioTask* D_800CCFF0 = NULL;
    func_800BA268();

    while (true) {
        MQ_GET_MESG(&D_800DCA98, &D_800DCE30);
        MQ_WAIT_FOR_MESG(&D_800DCA98, &D_800DCE30);
        if (D_800CCFF0 != NULL) {
            D_800DCCC4 = &D_800CCFF0->task;
            osSendMesg(&D_800DCAE0, (void*) 0x16, OS_MESG_BLOCK);
        }
        D_800CCFF0 = func_800BB49C();
    }
}
