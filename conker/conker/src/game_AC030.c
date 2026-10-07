#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_1507EB80(u8 *buf, s32 *len, u8 c) {
    if (*len + 1 < 40) {
        buf[*len] = c;
        *len = *len + 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EBB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EC38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EE58.s")

void func_1507EEB8(u8 arg0, u8 *arg1) {
    s32 i;
    for (i = 4; i > 0; i--) {
        arg1[i] = arg1[i - 1];
    }
    arg1[0] = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EEF4.s")

void func_1507EFA0(s32 arg0, u8 *arg1) {
    s32 i;
    for (i = 4; i >= 0; i--) {
        if (arg0 == arg1[i]) {
            arg1[i] = 0;
            return;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FC2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FEA0.s")

struct func_1507FF94_s {
    struct127 *ptr;
    u8 id;
};

void func_1507FF94(struct127 *arg0) {
    struct func_1507FF94_s tmp;

    tmp.ptr = arg0;
    tmp.id = arg0->unique_id;
    // reusing the parameter as an integer-cast pointer makes IDO spill
    // &tmp across the first call instead of rematerialising it
    arg0 = (struct127 *)(s32)&tmp;
    func_15191B8C(arg0, 0xD);
    func_151494E0(arg0, 0xD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FFD8.s")
