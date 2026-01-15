#ifndef FZX_BORDERED_BOX_H
#define FZX_BORDERED_BOX_H

#include "libultra/ultra64.h"

#ifndef EXPANSION_KIT
#define BORDERED_BOX_COUNT 3
#else // EXPANSION_KIT
#define BORDERED_BOX_COUNT 5
#endif

typedef Gfx* (*BorderedBoxContentsDrawFunc)(Gfx*, s32, s32);

typedef struct BorderedBoxWidget {
    /* 0x00 */ s32 state;
    /* 0x04 */ s16 id;
    /* 0x06 */ s16 timer;
    /* 0x08 */ s16 left;
    /* 0x0A */ s16 top;
    /* 0x0C */ s16 maxLeft;
    /* 0x0E */ s16 maxTop;
    /* 0x10 */ s16 width;
    /* 0x12 */ s16 height;
    /* 0x14 */ s16 maxWidth;
    /* 0x16 */ s16 maxHeight;
    /* 0x18 */ u16 boxColor;
    /* 0x1A */ u16 borderColor;
    /* 0x1C */ BorderedBoxContentsDrawFunc contentsDrawFunc;
} BorderedBoxWidget; // size = 0x20

typedef enum BorderedBoxState {
    /* 0 */ BORDERED_BOX_CLOSED,
    /* 1 */ BORDERED_BOX_OPEN_WIDTH,
    /* 2 */ BORDERED_BOX_OPEN_HEIGHT,
    /* 3 */ BORDERED_BOX_OPENED,
    /* 4 */ BORDERED_BOX_CLOSE_HEIGHT,
    /* 5 */ BORDERED_BOX_CLOSE_WIDTH,
} BorderedBoxState;

typedef enum BorderedBoxInfoRequest {
    /* 0 */ IS_BORDERED_BOX_ACTIVE,
    /* 1 */ IS_BORDERED_BOX_OPENED,
} BorderedBoxInfoRequest;

void BorderedBox_CleanWidget(BorderedBoxWidget** boxPtr);
void BorderedBox_ClearAll(void);
BorderedBoxWidget* BorderedBox_Init(s16 id, s16 left, s16 top, s16 width, s16 height, u16 borderColor, BorderedBoxContentsDrawFunc contentsDrawFunc);
void BorderedBox_StartClose(BorderedBoxWidget* box);
void BorderedBox_Update(void);
Gfx* BorderedBox_Draw(Gfx* gfx);
bool BorderedBox_GetInfo(BorderedBoxWidget* box, s32 infoCondition);

#endif // FZX_BORDERED_BOX_H
