#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F48D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4A38.s")

void func_150F4CFC(u8 *arg0, s32 arg1, u8 arg2) {
    u8 *p = arg0 + 0x170;

    if (arg2 == 0x4E) {
        arg0[0x71] = 0;
        p[0x24] |= 5;
    } else if (arg2 == 0x4F) {
        func_1516972C((struct102 *) arg0);
    }
}

struct func_150F4D5C_s {
    s32 unk0;
    f32 unk4;
    s8 unk8;
    u8 unk9;
};

void func_150F4D5C(s32 arg0, s8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    struct func_150F4D5C_s tmp;
    struct260 *temp_v0;

    tmp.unk0 = arg0;
    tmp.unk4 = 0.0f;
    tmp.unk8 = arg1;
    tmp.unk9 = arg2;
    temp_v0 = func_15149130(0x12C, -1, 0x56, -1, 0, 0, 0xC, arg3, arg4);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, &tmp, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4DEC.s")
