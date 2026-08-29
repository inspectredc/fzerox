#include "global.h"

s32 sMenuHighlightAlphaChangeScale = 1;

void ExpansionKit_SetMenuHighlightAlphaChangeScale(s32 scale) {
    sMenuHighlightAlphaChangeScale = scale;
}

s32 ExpansionKit_GetMenuHighlightAlphaChangeScale(void) {
    return sMenuHighlightAlphaChangeScale;
}
