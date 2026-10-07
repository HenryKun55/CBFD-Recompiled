#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501BB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501BBB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C0F0.s")

extern u8 D_80084060[];

void func_1501C17C(u8 arg0) {
    s32 idx = D_80084060[arg0];
    if (idx < 4) {
        D_800BE93C[idx] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C1B0.s")

void func_1501C17C(u8);
void func_1501C53C(void) {
    u8 i;
    for (i = 0; i < 4; i++) {
        func_1501C17C(i);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C57C.s")
