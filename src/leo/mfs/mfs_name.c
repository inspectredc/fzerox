#include "leo/leo_internal.h"
#include "leo/mfs.h"

s32 Mfs_ValidateFileName(char* name) {
    char* ptr;

    if ((name == NULL) || (*name == 0)) {
        return -1;
    }
    if (mfsStrLen(name) > 20) {
        return -1;
    }

    for (ptr = name; *ptr != 0; ptr++) {
#if MFS_VERSION == MFS_VERSION_A
        if (*ptr == '/') {
#else // MFS_VERSION_B
        if (*ptr == '/' || *ptr == '.' || *ptr == ':') {
#endif
            return -1;
        }
        if ((((*ptr >= 0x20 && *ptr < 0x7F) || (*ptr > 0xA0 && *ptr < 0xE0)) && (*ptr != '/'))) {
            continue;
        }
        if (*ptr >= 0x81 && *ptr < 0x99) {
            ptr++;
            if (*ptr >= 0x40 && *ptr < 0xFD && *ptr != 0x7F) {
                continue;
            }
            return -1;
        }
        return -1;
    }

    return 0;
}

u16 D_i1_80428660[] = {
    0x0000, 0x8142, 0x8175, 0x8176, 0x8141, 0x8145, 0x8392, 0x8340, 0x8342, 0x8344, 0x8346, 0x8348, 0x8383,
    0x8385, 0x8387, 0x8362, 0x815B, 0x8341, 0x8343, 0x8345, 0x8347, 0x8349, 0x834A, 0x834C, 0x834E, 0x8350,
    0x8352, 0x8354, 0x8356, 0x8358, 0x835A, 0x835C, 0x835E, 0x8360, 0x8363, 0x8365, 0x8367, 0x8369, 0x836A,
    0x836B, 0x836C, 0x836D, 0x836E, 0x8371, 0x8374, 0x8377, 0x837A, 0x837D, 0x837E, 0x8380, 0x8381, 0x8382,
    0x8384, 0x8386, 0x8388, 0x8389, 0x838A, 0x838B, 0x838C, 0x838D, 0x838F, 0x8393, 0x814F, 0x814B,
};

s16 func_i1_804070EC(s32 character) {
    if ((character > ' ') && (character < 0x7F)) {
        return (s16) (character - ' ');
    }
    if ((character > 0xA0) && (character < 0xE0)) {
        return D_i1_80428660[character - 0xA0];
    }
    return 0;
}
