#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503CF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D368.s")

void func_1503D438(s32 *arg0, s32 arg1) {
    if (*arg0 != 0) {
        if ((*arg0 & 0xF000000) == 0) {
            *arg0 += arg1;
        }
    }
}

void func_1503D45C(s32 *arg0, s32 arg1) {
    while (*arg0 != 0) {
        *arg0 += arg1;
        arg0 += 2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D5F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D984.s")

struct func_1503DA3C_s {
    u8 pad[0x30];
    u8 *data;
    u32 count;
};

u8 func_1503DA3C(s32 arg0, s32 arg1) {
    s32 p;
    struct func_1503DA3C_s *s;
    u8 ret;

    p = (&D_800D19A0)[arg0];
    s = (struct func_1503DA3C_s *)(p - 0x38);
    if (p == 0) {
        return 0xFF;
    }
    if (s->count < (u32)(arg1 + 1)) {
        return 0xFF;
    }
    ret = (s->data != NULL) ? s->data[arg1] : 0xFF;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503DA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503DC3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503DD1C.s")
