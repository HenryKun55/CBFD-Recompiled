#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_AE1D0/func_15080D20.s")

extern struct { u16 id; u16 pad; } D_8009BD30[];

s32 func_1508108C(u8 *arg0) {
    s32 i;
    for (i = 0; i < 23; i++) {
        if (arg0[4] == D_8009BD30[i].id) {
            return i;
        }
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AE1D0/func_1508114C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AE1D0/func_15081574.s")
