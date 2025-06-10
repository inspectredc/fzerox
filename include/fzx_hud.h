#ifndef FZX_HUD_H
#define FZX_HUD_H

typedef enum PositionSuffix {
    /* 0 */ POSITION_SUFFIX_ST,
    /* 1 */ POSITION_SUFFIX_ND,
    /* 2 */ POSITION_SUFFIX_RD,
    /* 3 */ POSITION_SUFFIX_TH,
} PositionSuffix;

typedef enum TimerDigits {
    /*  0 */ TIMER_DIGIT_0,
    /*  1 */ TIMER_DIGIT_1,
    /*  2 */ TIMER_DIGIT_2,
    /*  3 */ TIMER_DIGIT_3,
    /*  4 */ TIMER_DIGIT_4,
    /*  5 */ TIMER_DIGIT_5,
    /*  6 */ TIMER_DIGIT_6,
    /*  7 */ TIMER_DIGIT_7,
    /*  8 */ TIMER_DIGIT_8,
    /*  9 */ TIMER_DIGIT_9,
    /* 10 */ TIMER_DIGIT_PRIME,
    /* 11 */ TIMER_DIGIT_DOUBLE_PRIME,
    /* 12 */ TIMER_DIGIT_PLUS,
    /* 13 */ TIMER_DIGIT_MINUS,
} TimerDigits;

#endif // FZX_HUD_H
