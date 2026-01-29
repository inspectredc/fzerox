#ifndef FZX_EXPANSION_KIT_H
#define FZX_EXPANSION_KIT_H

#define INVALID_OPTION -1

typedef enum CourseEditFileOption {
    /* 0 */ FILE_OPTION_LOAD,
    /* 1 */ FILE_OPTION_SAVE,
    /* 2 */ FILE_OPTION_RENAME,
    /* 3 */ FILE_OPTION_ERASE,
    /* 4 */ FILE_OPTION_COPY,
} CourseEditFileOption;

typedef enum CreateOption {
    /* 0 */ CREATE_OPTION_COURSE,
    /* 1 */ CREATE_OPTION_POINT,
    /* 2 */ CREATE_OPTION_DESIGN,
    /* 3 */ CREATE_OPTION_PARTS,
    /* 4 */ CREATE_OPTION_BACKGROUND,
    /* 5 */ CREATE_OPTION_BGM,
} CreateOption;

typedef enum PointOption {
    /* 0 */ POINT_OPTION_SET,
    /* 1 */ POINT_OPTION_START,
    /* 2 */ POINT_OPTION_CENTERING,
    /* 3 */ POINT_OPTION_REVERSE,
    /* 4 */ POINT_OPTION_CLEAR_ALL,
} PointOption;

typedef enum MoveOption {
    /* 0 */ MOVE_OPTION_MOVE_XZ,
    /* 1 */ MOVE_OPTION_MOVE_Y,
    /* 2 */ MOVE_OPTION_WIDTH,
    /* 3 */ MOVE_OPTION_BANK,
    /* 4 */ MOVE_OPTION_CENTER,
    /* 5 */ MOVE_OPTION_CLEAR,
    /* 6 */ MOVE_OPTION_STRAIGHT,
} MoveOption;

typedef enum TrackDesignStyle {
    /* 0 */ TRACK_DESIGN_STYLE_ROAD,
    /* 1 */ TRACK_DESIGN_STYLE_H_ROAD,
    /* 2 */ TRACK_DESIGN_STYLE_T_ROAD,
    /* 3 */ TRACK_DESIGN_STYLE_TUNNEL,
    /* 4 */ TRACK_DESIGN_STYLE_PIPE,
    /* 5 */ TRACK_DESIGN_STYLE_HALF_PIPE,
    /* 6 */ TRACK_DESIGN_STYLE_CYLINDER,
    /* 7 */ TRACK_DESIGN_STYLE_SPACE,
    /* 8 */ TRACK_DESIGN_STYLE_LOOP,
} TrackDesignStyle;

typedef enum TrackPartStyle {
    /* 0 */ TRACK_PART_STYLE_PIT,
    /* 1 */ TRACK_PART_STYLE_DASH,
    /* 2 */ TRACK_PART_STYLE_DIRT,
    /* 3 */ TRACK_PART_STYLE_SLIP,
    /* 4 */ TRACK_PART_STYLE_JUMP,
    /* 5 */ TRACK_PART_STYLE_TRAP,
    /* 6 */ TRACK_PART_STYLE_GATE,
    /* 7 */ TRACK_PART_STYLE_BUILDING,
    /* 8 */ TRACK_PART_STYLE_SIGN,
} TrackPartStyle;

#endif // FZX_EXPANSION_KIT_H
