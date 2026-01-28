#include "global.h"
#include "fzx_bordered_box.h"
#include "assets/course_track_gfx.h"

void BorderedBox_CleanWidget(BorderedBoxWidget** boxPtr) {
    *boxPtr = NULL;
}

s32 sBorderedBoxCount;
BorderedBoxWidget sBorderedBoxes[BORDERED_BOX_COUNT];

void BorderedBox_ClearAll(void) {
    s32 i;
    BorderedBoxWidget* box;

    sBorderedBoxCount = 0;

    for (i = 0, box = sBorderedBoxes; i < BORDERED_BOX_COUNT; i++, box++) {
        box->state = BORDERED_BOX_CLOSED;
        box->id = -1;
        box->timer = box->left = box->top = box->maxLeft = box->maxTop = box->width = box->height = 0;
        box->boxColor = box->borderColor = 0;
    }
}

BorderedBoxWidget* BorderedBox_Init(s16 id, s16 left, s16 top, s16 width, s16 height, u16 borderColor,
                                    BorderedBoxContentsDrawFunc contentsDrawFunc) {
    s32 i;
    BorderedBoxWidget* box;
    s64 state = BORDERED_BOX_OPEN_WIDTH;

    for (i = 0, box = sBorderedBoxes; i < BORDERED_BOX_COUNT; i++, box++) {
        if (id == box->id) {
            return NULL;
        }
    }

    for (i = 0, box = sBorderedBoxes; i < BORDERED_BOX_COUNT; i++, box++) {
        if (box->id == -1) {
            break;
        }
    }

    if (i == 3) {
        return NULL;
    }
    sBorderedBoxCount++;
    box->state = state;
    box->id = id;
    box->timer = 0;
    box->left = left + (width / 2);
    box->top = top + ((height - 2) / 2);
    box->maxLeft = left;
    box->maxTop = top;
    box->width = 0;
    box->height = 2;
    box->maxWidth = width;
    box->maxHeight = height;
    box->boxColor = GPACK_RGBA5551(0, 0, 0, 1);
    box->borderColor = borderColor;
    box->contentsDrawFunc = contentsDrawFunc;
    return box;
}

void BorderedBox_StartClose(BorderedBoxWidget* box) {
    box->state = BORDERED_BOX_CLOSE_HEIGHT;
    box->timer = 0;
    box->maxLeft = box->left;
    box->maxTop = box->top;
    box->maxWidth = box->width;
    box->maxHeight = box->height;
}

void BorderedBox_Update(void) {
    s32 i;
    BorderedBoxWidget* box;
    f32 scale;

    for (i = 0, box = sBorderedBoxes; i < BORDERED_BOX_COUNT; i++, box++) {
        if (box->id == -1) {
            continue;
        }

        switch (box->state) {
            case BORDERED_BOX_OPEN_WIDTH:
                box->timer++;
                scale = (box->timer / 10.0f);

                box->left = box->maxLeft + ((s16) ((box->maxWidth / 2.0f) * (1.0f - scale)));
                box->width = box->maxWidth * scale;

                if (box->timer >= 10) {
                    box->state = BORDERED_BOX_OPEN_HEIGHT;
                    box->timer = 0;
                    box->width = box->maxWidth;
                    box->left = box->maxLeft;
                }
                break;
            case BORDERED_BOX_OPEN_HEIGHT:
                box->timer++;
                scale = (box->timer / 10.0f);

                box->top = box->maxTop + (s16) (((box->maxHeight - 2) / 2.0f) * (1.0f - scale));
                box->height = (s16) ((box->maxHeight - 2) * scale) + 2;

                if (box->timer >= 10) {
                    box->state = BORDERED_BOX_OPENED;
                    box->timer = 0;
                    box->height = box->maxHeight;
                    box->top = box->maxTop;
                }
                break;
            case BORDERED_BOX_OPENED:
                break;
            case BORDERED_BOX_CLOSE_HEIGHT:
                box->timer++;
                scale = (box->timer / 10.0f);

                box->top = box->maxTop + (s16) (((box->maxHeight - 2) / 2.0f) * scale);
                box->height = (box->maxHeight - 2) * (1.0f - scale);

                if (box->timer >= 10) {
                    box->state = BORDERED_BOX_CLOSE_WIDTH;
                    box->timer = 0;
                    box->height = 2;
                    box->top = box->maxTop + ((box->maxHeight - 2) / 2);
                }
                break;
            case BORDERED_BOX_CLOSE_WIDTH:
                box->timer++;
                scale = (box->timer / 10.0f);

                box->left = box->maxLeft + (s16) ((box->maxWidth / 2.0f) * scale);
                box->width = box->maxWidth * (1.0f - scale);

                if (box->timer >= 11) {
                    box->state = BORDERED_BOX_CLOSED;
                    box->id = -1;
                    sBorderedBoxCount--;
                }
                break;
        }
    }
}

Gfx* BorderedBox_Draw(Gfx* gfx) {
    s32 i;
    BorderedBoxWidget* box;

    for (i = 0, box = sBorderedBoxes; i < BORDERED_BOX_COUNT; i++, box++) {
        if (box->id == -1) {
            continue;
        }

        gSPDisplayList(gfx++, D_80149A0);
        gDPSetFillColor(gfx++, box->borderColor << 16 | box->borderColor);
        gDPFillRectangle(gfx++, box->left, box->top, ((box->left + box->width) - 1), ((box->top + box->height) - 1));

        gDPPipeSync(gfx++);
        gDPSetFillColor(gfx++, box->boxColor << 16 | box->boxColor);
        gDPFillRectangle(gfx++, box->left + 1, box->top + 1, ((box->left + box->width) - 2),
                         ((box->top + box->height) - 2));

        if ((box->contentsDrawFunc != NULL) && (box->state == BORDERED_BOX_OPENED)) {
            gfx = box->contentsDrawFunc(gfx, box->left, box->top);
        }
    }
    return gfx;
}

bool BorderedBox_GetInfo(BorderedBoxWidget* box, s32 infoCondition) {
    bool ret = false;

    switch (infoCondition) {
        case IS_BORDERED_BOX_ACTIVE:
            ret = ((box != NULL) && (box->state != BORDERED_BOX_CLOSED)) ? true : false;
            break;
        case IS_BORDERED_BOX_OPENED:
            ret = (box->state == BORDERED_BOX_OPENED) ? true : false;
            break;
        default:
            break;
    }

    return ret;
}
