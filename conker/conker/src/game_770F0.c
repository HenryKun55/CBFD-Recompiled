#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_15049C40(f32 *a, f32 *b) {
    f32 dot;

    dot = a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
    if (dot < 0.0f) {
        b[0] = -b[0];
        b[1] = -b[1];
        b[2] = -b[2];
        b[3] = -b[3];
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_770F0/func_15049CB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_770F0/func_15049EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_770F0/func_1504A140.s")
