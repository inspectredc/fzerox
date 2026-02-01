#include "global.h"
#include "leo/mfs.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_course.h"
#include "fzx_camera.h"
#include ASSET_HEADER_EK(course_edit_textures.h)

unk_80128C94* D_80128C90;
unk_80128C94* D_80128C94;

s32 D_xk2_80103FF0 = 0;
s32 D_xk2_80103FF4 = 0;
s32 D_xk2_80103FF8 = 0;
s32 D_xk2_80103FFC = 0;

const u16 D_xk2_80104010[] = { BTN_L, BTN_R, BTN_L, BTN_R, BTN_UP, BTN_DOWN, BTN_LEFT, BTN_RIGHT, BTN_DOWN, BTN_UP };

extern volatile u8 D_80794E14;
extern unk_800D6CA0 D_800D6CA0;
extern s32 D_xk1_80032C20;

void func_xk2_800EC2A0(void) {
    static s32 D_xk2_80104000 = 0;
    u16 temp_a0;

    temp_a0 = gControllers[gPlayerControlPorts[0]].buttonPressed;
    if (D_80794E14 != 0) {
        D_xk2_80104000 = 0;
        return;
    }
    if (D_800D6CA0.unk_08 != 0) {
        D_xk2_80104000 = 0;
        return;
    }
    if (temp_a0 != 0) {
        if (temp_a0 & D_xk2_80104010[D_xk2_80104000]) {
            D_xk2_80104000++;
            if (D_xk2_80104000 == 10) {
                D_xk2_80104000 = 0;
                Audio_TriggerSystemSE(NA_SE_46);
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0xFF;
            }
        } else {
            D_xk2_80104000 = 0;
            if (gControllers[gPlayerControlPorts[0]].buttonPressed & D_xk2_80104010[0]) {
                D_xk2_80104000 = 1;
            }
        }
    }
}

extern s32 D_800CCFBC;
extern bool gInCourseEditor;
extern s32 D_8076C958;

extern CourseData D_800D0910;
extern CourseSegment D_802D0620[];
extern unk_807B3C20 D_802CB6D0;

void func_xk2_800EC3AC(void) {
    s32 i;

    PRINTF("EDIT_MODE_COURSE 07\n");
    PRINTF("EDIT_MODE_COURSE 07\n");
    PRINTF("sizeof save  %d\n");
    PRINTF("sizeof save2 %d\n");
    PRINTF("sizeof ghost %d\n");
    PRINTF("EDIT_MODE_COURSE -1\n");
    PRINTF("CONTINUE\n");
    PRINTF("EDIT_MODE_COURSE 02\n");
    PRINTF("EDIT_MODE_COURSE 01\n");
    PRINTF("FILE LOADING END DATA_CHANGE_FG: %d\n");
    PRINTF("DELETING BEFORE SAVING\n");
    PRINTF("FILE REAL SAVE START\n");
    PRINTF("SAVING\n");
    PRINTF("EDIT_MODE_COURSE: DISK FORMAT END\n");
    PRINTF("FILE FULL CHECK WAIT\n");
    PRINTF("EDIT_MODE_COURSE 06\n");

    D_8076C958 = 0;
    func_80705E18();
    func_80704810(true);
    func_xk1_8002FBB0();
    Audio_EditorExit();
    D_800CCFBC = 1;
    gCourseInfos->courseSegments = D_802D0620;
    gCourseInfos->segmentCount = D_802CB6D0.controlPointCount;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        D_802D0620[i] = D_802CB6D0.unk_0000[i];

        D_802D0620[i].segmentIndex = i;
        D_802D0620[i].prev = &D_802D0620[i - 1];
        D_802D0620[i].next = &D_802D0620[i + 1];
    }

    D_802D0620[0].prev = &D_802D0620[D_802CB6D0.controlPointCount - 1];
    D_802D0620[D_802CB6D0.controlPointCount - 1].next = &D_802D0620[0];
    func_80702D6C();
    D_800D0910 = COURSE_CONTEXT()->courseData;
    gInCourseEditor = false;
}

void func_xk2_800EC508(void) {

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        if (D_xk1_80032C20 != 0) {
            Audio_TriggerSystemSE(NA_SE_5);
            func_80767FE4(1, 0x20, NULL);
            D_800D6CA0.unk_08 = 0xFE;
        } else {
            Audio_TriggerSystemSE(NA_SE_37);
            D_800D6CA0.unk_08 = 0;
        }
    } else if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        Audio_TriggerSystemSE(NA_SE_37);
        D_800D6CA0.unk_08 = 0;
    } else {
        func_xk1_8002D2F0();
    }
}

extern s32 D_xk1_80030608;
extern s32 D_800CCFBC;
extern CourseEffectsInfo* D_800E12C0;
extern s32 D_xk1_80032BF8;
extern s32 D_xk2_800F7058;
extern s32 D_xk2_80119800;
extern u8* sCourseMinimapTex;
extern MenuWidget gCourseEditWidget;
extern s32 gNumPlayers;
extern s32 gCourseIndex;
extern s32 gPointOption;
extern s32 gVenueOption;
extern s32 gSkyboxOption;
extern s32 gBGMOption;
extern s32 gBGMOptionToCourseBGM[];
extern s32 D_xk2_800F7060;
extern s32 D_xk2_800F7064;
extern s32 D_xk2_800F7040;
extern s32 D_xk2_800F7044;
extern s32 D_xk2_800F7048;
extern s32 D_xk2_800F704C;
extern CourseFeaturesInfo gCourseFeaturesInfo;
extern CourseFeature gCourseFeatures[];
extern CourseEffectsInfo gCourseEffectsInfo;
extern CourseEffect gCourseEffects[];
extern unk_807B3C20 D_807B6528;
extern s16 D_800CCFE8;
extern s32 D_8076C964;
extern GfxPool* gGfxPool;
extern Vtx* gCourseVtxPtr;
extern CourseInfo* gCurrentCourseInfo;

void CourseEdit_Init(void) {
    gCourseEditWidget.highlightedIndex = -1;
    gNumPlayers = 1;
    gCourseIndex = 0;
    func_xk2_800F6290();
    func_80704810(false);
    gNumPlayers = 1;
    func_xk1_80025F98();
    D_xk2_800F7060 = Math_Rand2() % 30;
    D_xk2_800F7064 = Math_Rand2() % 4;
    D_xk2_800F7040 = 4;
    D_xk2_800F7048 = 0;
    // clang-format off
    D_800D6CA0.unk_28.pos.x = 0.0f; \
    D_800D6CA0.unk_28.pos.y = 0.0f; \
    D_800D6CA0.unk_28.pos.z = 0.0f;
    // clang-format on
    func_xk1_80025C00(3);
    ExpansionKit_SetInputIndicatorFlashRate(3);
    func_xk1_8002FB80();
    func_xk1_8002E9D0(3);
    func_800A4D0C(0);
    gInCourseEditor = true;
    gPointOption = 0;
    D_xk1_80030608 = 0x1F4;
    D_xk2_800F704C = -1;
    D_xk2_80119800 = -1;
    D_xk1_80032BF8 = 0;
    gCourseInfos->courseSegments = D_802CB6D0.unk_0000;
    gCurrentCourseInfo = gCourseInfos;
    gCurrentCourseInfo->length = 0.0f;
    gCourseFeaturesInfo.features = gCourseFeatures;
    gCourseEffectsInfo.effects = gCourseEffects;
    D_807B6528.controlPointCount = 0;
    D_807B6528.unk_0000[0].prev = &D_802CB6D0.unk_0000[0];
    D_807B6528.unk_0000[0].next = &D_802CB6D0.unk_0000[0];
    func_xk2_800E6F9C();
    D_800CCFBC = 3;
    D_800CCFE8 = 3;
    gCameras[0].fov = 40.0f;
    func_xk1_8002D86C(9, 2);
    func_xk1_8002D880(0x18);
    func_xk2_800E77F0();
    COURSE_CONTEXT()->courseData = D_800D0910;
    gVenueOption = COURSE_CONTEXT()->courseData.venue;
    gSkyboxOption = COURSE_CONTEXT()->courseData.skybox;
    gBGMOption = gBGMOptionToCourseBGM[COURSE_CONTEXT()->courseData.bgm];
    func_80702FF4(gVenueOption);
    func_xk2_800E7028(D_xk1_80030608);
    func_xk2_800F5C5C();
    func_xk1_8002AF10(4);
    gCourseVtxPtr = gGfxPool->courseVtxBuffer;
    D_800E12C0 = &gCourseEffectsInfo;
    func_xk2_800DC3F8();
    func_xk2_800DD638();
    D_800D6CA0.unk_0C = D_802CB6D0.controlPointCount - 1;
    func_xk2_800EF78C();
    func_xk2_800F0FE8();
    if (D_8076C964 == 1) {
        D_xk2_800F7044 = 1;
    } else {
        D_xk2_800F7044 = 0;
    }
    D_xk2_800F7058 = 0;
    sCourseMinimapTex = Arena_Allocate(ALLOC_FRONT, 0x1000);
    D_800D6CA0.unk_08 = 0;
}

extern s8 gGamePaused;

void func_xk2_800EC8AC(void) {
    gGamePaused = false;
    Audio_TriggerSystemSE(NA_SE_12);
    Audio_PauseSet(AUDIO_PAUSE_UNPAUSED);
    if ((gRacers[0].stateFlags & RACER_STATE_FALLING_OFF_TRACK) && (D_xk2_80103FF8 == 0)) {
        D_xk2_80103FF4 = 0;
        D_xk2_80103FF8 = 1;
        D_xk2_80103FF0 = 0x78;
    }
}

extern bool gInCourseEditTestRun;

void func_xk2_800EC91C(void) {
    gGamePaused = false;
    gInCourseEditTestRun = false;
    func_800A4D0C(0);
    D_xk2_80103FF0 = 0;
    D_xk2_80103FF4 = 0;
    D_xk2_80103FF8 = 0;
    Audio_PauseSet(AUDIO_PAUSE_UNPAUSED);
    Audio_TestRunEnd();
    D_800CCFBC = 3;
    gCameras[0].fov = 40.0f;
    func_xk2_800F13C4();
    func_xk2_800EF8B0();
    D_xk2_800F7040 = 4;
    D_800D6CA0.unk_0C = gRacers[0].segmentPositionInfo.courseSegment->next->segmentIndex;
}

extern s32 D_xk1_8003A550;
extern s32 D_xk1_8003A554;
extern s32 D_800D11C8[];
extern s32 gLastCourseBGM;

void func_xk2_800EC9BC(void) {
    func_xk2_800DE758();
    func_xk1_80027CFC(&gCourseEditWidget, &D_xk1_8003A550, &D_xk1_8003A554);
    if (D_80794E14 == 1) {
        return;
    }
    if ((gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) && (func_807424CC() == 0)) {
        if (Audio_GetActiveBgm() != BGM_COURSE_EDITOR) {
            if (D_800D11C8[2] != 0) {
                Audio_DDBgmStart(BGM_COURSE_EDITOR);
            } else {
                Audio_DDBgmStop();
            }
        }
        func_xk1_80027B74(&gCourseEditWidget);
        gLastCourseBGM = -1;
        D_800D6CA0.unk_08 = 0;
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        func_xk1_80027DC8(&gCourseEditWidget, &D_xk1_8003A550, &D_xk1_8003A554);
    }
    func_xk1_80028064();
    func_xk1_80028250();
    func_xk1_80028708();
    func_xk1_800287BC();
    func_xk1_80028818();
    func_xk1_80028A04();
    func_xk1_80028BA0();
    func_xk1_80028BD4();
    func_xk1_80028C08();
    func_xk1_80028C3C();
    func_xk1_80028C70();
    func_xk1_80028CA4();
    func_xk1_80028CD8();
    func_xk1_80028D0C();
    func_xk1_80028D40();
    func_xk1_80028D74();
    func_xk1_80028DA8();
    func_xk1_80028DDC();
    func_xk1_80028E10();
    func_xk1_80028E54();
    func_xk1_80028E88();
    func_xk1_80028EBC();
    func_xk1_80028EF0();
    func_xk1_80028F50();
    func_xk1_80028F94();
}

s32 func_xk2_800ECBC0(void) {
    if (gGamePaused) {
        Effects_Update();
        Racer_Update();
        Camera_Update();
        Background_Update();
        Course_Update();
        func_xk2_800E5B6C();
        return GAMEMODE_COURSE_EDIT;
    }
    if (D_xk2_80103FF0 != 0) {
        D_xk2_80103FF0 -= 1;
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_START) {
        gGamePaused = true;
        func_xk2_800F632C();
        Audio_TriggerSystemSE(NA_SE_12);
        Audio_PauseSet(AUDIO_PAUSE_PAUSED);
    } else {
        Effects_Update();
        Racer_Update();
        Camera_Update();
        Background_Update();
        Course_Update();
        if ((gRacers[0].stateFlags & RACER_STATE_RETIRED) && (D_xk2_80103FF8 == 0)) {
            D_xk2_80103FF8 = 1;
            D_xk2_80103FF4 = 0;
            D_xk2_80103FF0 = 0x78;
        }
        if ((D_xk2_80103FF0 <= 60) && (D_xk2_80103FF4 == 0)) {
            Audio_TestRunStart();
            Racer_Init();
            Camera_Init();
            Effects_Init();
            D_xk2_80103FF4 = 1;
            D_xk2_80103FF8 = 0;
        }
        func_xk2_800E5B6C();
        func_8070304C();
    }
    return GAMEMODE_COURSE_EDIT;
}

void func_xk2_800ECD60(void) {
    func_xk2_800EBE90();
    func_xk2_800EBEF4();
    func_xk2_800EBE14();
}

extern s32 gCourseEditFileOption;
extern s32 gExpansionKitNameEntryStrLength;
extern u8 gExpansionKitNameEntryStr[];
extern s32 D_80119880;

void func_xk2_800ECD90(void) {

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        ExpansionKit_NameEntryInit(func_xk1_8002AC24);
        gExpansionKitNameEntryStrLength = mfsStrLen(gExpansionKitNameEntryStr);
        D_800D6CA0.unk_08 = 2;
        D_80119880 = 9;
        func_xk1_8002AEB4(9, 4);
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        Audio_TriggerSystemSE(NA_SE_37);
        D_800D6CA0.unk_08 = 0;
        gCourseEditFileOption = -1;
    }
}

extern s32 gCourseEditEntryOption;
extern s32 D_xk1_80032BF8;
extern s32 D_xk2_80119918;
extern unk_8003A5D8 D_xk1_8003A598;
extern s32 D_800DCCFC;
extern Vtx* gEffectsVtxPtr;
extern Vtx* gEffectsVtxEndPtr;
extern volatile u8 D_80794E10;
extern u8 D_xk2_800F7400;
extern CourseContext D_xk2_800F7408;

s32 CourseEdit_Update(void) {

    gCourseVtxPtr = gGfxPool->courseVtxBuffer;
    gEffectsVtxPtr = gGfxPool->effectsVtxBuffer;
    gEffectsVtxEndPtr = &gGfxPool->effectsVtxBuffer[0x7FF];
    D_80128C94 = &D_80128C90[D_800DCCFC];
    if (D_xk2_800F7040 != 0) {
        D_xk2_800F7040 -= 1;
    }
    if (!gInCourseEditTestRun) {
        func_xk2_800EC2A0();
    }
    func_xk2_800D8DAC();
    func_xk1_8002D810(&gControllers[gPlayerControlPorts[0]]);
    func_xk1_8002D974();

    if (gInCourseEditTestRun) {
        return func_xk2_800ECBC0();
    }
    if ((D_xk2_80119918 == 0) && (D_800D6CA0.unk_08 != 0xFF)) {
        func_xk2_800DEE20();
    }
    if (gInCourseEditTestRun) {
        return GAMEMODE_COURSE_EDIT;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        gCurrentCourseInfo->length = 0.0f;
    }
    if (!gInCourseEditTestRun) {
        func_80702F1C();
    }
    switch (D_800D6CA0.unk_08) {
        case 0x38:
            if (D_80794E14) {
                break;
            }
            D_800D6CA0.unk_08 = 0;
            break;
        case 0x13:
            if (D_80794E14) {
                break;
            }
            if (D_80794E10 && (D_xk2_800F7400 == 0)) {
                func_xk2_800EF78C();
                func_xk2_800EACB0();
                D_800D6CA0.unk_08 = 0;
            }
            break;
        case 0x14:
            if (D_80794E14) {
                break;
            }
            switch (D_80119880) {
                case -1:
                case 1:
                    func_8076814C(MFS_ENTRY_WORKING_DIR, D_xk1_8003A598.name, &D_xk1_8003A598.extension,
                                  COURSE_CONTEXT(), sizeof(CourseContext), 0, 0xFF, true);
                    D_800D6CA0.unk_08 = 0x12;
                    break;
                case 9:
                    func_807681C8(MFS_ENTRY_WORKING_DIR, D_xk1_8003A598.name, &D_xk1_8003A598.extension,
                                  &D_xk2_800F7408, sizeof(CourseContext), 0, 0xFF, true);
                    D_800D6CA0.unk_08 = 0x12;
                    break;
            }
            break;
        case 0x12:
            if (D_80794E14) {
                break;
            }
            switch (D_80119880) {
                case -1:
                case 1:
                    if (COURSE_CONTEXT()->courseData.flag == 0) {
                        func_xk2_800EBFE8(D_xk1_8003A598.name);
                        D_800D6CA0.unk_08 = 0x22;
                    } else {
                        D_800D6CA0.unk_08 = 0;
                    }
                    break;
                case 9:
                    if (D_xk2_800F7408.courseData.flag == 0) {
                        func_xk2_800EBFE8(D_xk1_8003A598.name);
                        D_800D6CA0.unk_08 = 0x22;
                    } else {
                        D_800D6CA0.unk_08 = 0;
                    }
                    break;
            }
            break;
        case 0xFF:
            func_xk2_800EC508();
            break;
        case 0xFE:
            if (D_80794E14) {
                break;
            }
            D_800D6CA0.unk_08 = 0;
            break;
        case 0x31:
            if (D_80794E14 == 0) {
                func_xk2_800EB018();
            }
            break;
        case 0x1:
            func_xk2_800EC9BC();
            break;
        case 0x10:
            func_xk2_800DD938();
            break;
        case 0x4:
            func_xk2_800F40B0();
            break;
        case 0x2:
            ExpansionKit_NameEntryUpdate(&D_xk1_8003A550, &D_xk1_8003A554);
            break;
        case 0x20:
            func_xk2_800ECD60();
            break;
        case 0x30:
            func_xk2_800ECD90();
            break;
        case 0x3:
            func_xk1_8002BBA4();
            if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
                func_xk2_800EB400();
            }
            if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
                func_xk2_800EB3B4();
            }
            break;
        case 0x22:
            if (D_80794E14) {
                break;
            }
            func_xk2_800EC174();
            D_800D6CA0.unk_08 = 0x37;
            break;
        case 0x5:
            func_xk2_800D950C();
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z) {
                func_xk2_800DC0D4();
            } else {
                func_xk2_800DC2D0();
                D_800D6CA0.unk_08 = 0;
            }
            break;
        case 0x32:
            if (D_80794E14 == 0) {
                D_800D6CA0.unk_08 = 0x31;
            }
            break;
        case 0x33:
            if (D_80794E14 == 0) {
                D_800D6CA0.unk_08 = 0x30;
            }
            break;
        case 0x34:
            if (D_80794E14 == 0) {
                D_xk1_80032BF8 = 0;
                D_800D6CA0.unk_08 = 0x35;
            }
            break;
        case 0x35:
            func_xk1_8002AC70();
            break;
        case 0x36:
            if (D_80794E14) {
                break;
            }
            func_xk2_800EBA34();
            break;
        case 0x37:
            if (D_80794E14) {
                break;
            }
            func_8070405C(true);
            D_800D6CA0.unk_08 = 0;
            break;
        case 0x11:
            func_xk2_800DF370();
            break;
        case 0x23:
            func_xk2_800DF42C();
            break;
        case 0x24:
            if (D_80794E14 == 0) {
                gCourseEditEntryOption = -1;
                Audio_TriggerSystemSE(NA_SE_5);
                func_8070405C(true);
                D_800D6CA0.unk_08 = 0;
            }
            break;
        case 0xFD:
            D_xk2_80103FFC++;
            if (D_xk2_80103FFC >= 3) {
                D_xk2_80103FFC = 0;
                D_800D6CA0.unk_08 = 0;
                func_xk2_800EC3AC();
                return 0x8007;
            }
            break;
        default:
            if ((func_xk2_800DE980() != 0) && (D_xk2_80119918 == 0)) {
                D_xk2_80103FFC = 0;
                D_800D6CA0.unk_08 = 0xFD;
            } else if (D_xk2_80119918 != 0) {
                func_xk2_800F5F2C();
                func_xk2_800D7058();
                func_xk2_800D71E8();
                func_xk2_800D78A0();
                func_xk2_800D6FF0();
            } else {
                func_xk2_800D8F04();
            }
            break;
    }

    if (D_xk2_800F7040 == 3) {
        func_xk2_800F12B0();
    }
    func_xk2_800E7854();

    return GAMEMODE_COURSE_EDIT;
}

extern Gfx D_8014940[];

void func_xk2_800ED6A4(Gfx** gfxP) {
    Gfx* gfx;
    s32 alpha;

    if ((D_xk2_80103FF0 == 0) || !gInCourseEditTestRun) {
        return;
    }
    gfx = *gfxP;
    if (D_xk2_80103FF0 > 60) {
        alpha = ((120 - D_xk2_80103FF0) * 255) / 60;
    } else {
        alpha = (D_xk2_80103FF0 * 255) / 60;
    }
    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, alpha);

    gSPTextureRectangle(gfx++, 0 << 2, 0 << 2, SCREEN_WIDTH << 2, SCREEN_HEIGHT << 2, 0, 0, 0, 1 << 10, 1 << 10);

    *gfxP = gfx;
}

extern Gfx D_8076CAF8[];
extern Vp aVpFullScreen;
extern s32 D_800DCD04;
extern FrameBuffer* gFrameBuffers[];

Gfx* D_xk2_80104004[] = { D_9014D78, D_9014DB8, D_9014DF8 };

Gfx* CourseEdit_Draw(Gfx* gfx) {

    if (!gInCourseEditor) {
        return gfx;
    }
    D_80128C94 = &D_80128C90[D_800DCCFC];
    gfx = Segment_SetTableAddresses(gfx);

    gSPDisplayList(gfx++, D_8076CAF8);
    gSPDisplayList(gfx++, D_xk2_80104004[D_800DCD04]);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));
    gSPViewport(gfx++, &aVpFullScreen);
    gfx = func_xk2_800F1428(gfx);
    gSPDisplayList(gfx++, D_9014A38);
    gfx = func_xk2_800DF5FC(gfx);
    func_xk2_800ED6A4(&gfx);
    if ((gInCourseEditTestRun) && (gGamePaused)) {
        gfx = func_xk2_800F634C(gfx);
    }
    return gfx;
}
