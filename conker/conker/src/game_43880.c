#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150163D0_s {
    s32 offset;
    s32 unk4;
};

extern struct func_150163D0_s *D_800D18B0;

void func_150163D0(s32 arg0) {
    s32 i;
    s32 count;

    if (func_1502B7F0(&D_800D18B0, 3, 12, arg0, 9) > 0) {
        count = 1;
        for (i = 0; D_800D18B0[i].offset != 0; count++) {
            i++;
        }
        for (i = 0; i < count - 1; i++) {
            D_800D18B0[i].offset += (s32)D_800D18B0;
        }
    } else {
        D_800D18B0 = NULL;
    }
}
