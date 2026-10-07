#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15100180_s {
    void *ptr;
    u8 val;
};

void func_15100180(void *arg0) {
    struct func_15100180_s sp18;

    sp18.ptr = arg0;
    sp18.val = *((u8 *)arg0 + 0x3B);
    func_151494E0(&sp18, 0x48);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D630/func_151001B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D630/func_15100230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D630/func_151002BC.s")
