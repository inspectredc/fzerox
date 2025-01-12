#include "global.h"
#include "libultra/ultra64.h"
#include "audio.h"
#include "fzxthread.h"

extern OSMesgQueue gAudioTaskMesgQueue;
extern OSMesgQueue gMainThreadMesgQueue;
extern OSTask* gCurAudioOSTask;

OSMesg sAudioTaskMsg;

void Audio_ThreadEntry(void* arg0) {
    static AudioTask* sCurAudioTask = NULL;
    Audio_Init();

    while (true) {
        MQ_GET_MESG(&gAudioTaskMesgQueue, &sAudioTaskMsg);
        MQ_WAIT_FOR_MESG(&gAudioTaskMesgQueue, &sAudioTaskMsg);
        if (sCurAudioTask != NULL) {
            gCurAudioOSTask = &sCurAudioTask->task;
            osSendMesg(&gMainThreadMesgQueue, (OSMesg) EVENT_MESG_AUDIO_TASK_SET, OS_MESG_BLOCK);
        }
        sCurAudioTask = Audio_SetupCreateTask();
    }
}
