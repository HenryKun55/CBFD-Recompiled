#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034EB4.s")

extern u8 D_800C3F00;

void func_15034F20(void) {
    D_800C3F00 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034F30.s")

struct func_150356C8_s {
    u8 pad[0xC];
};
extern u8 D_800C3F00;
extern struct func_150356C8_s D_800C3F08[];

void *func_150356C8(void) {
    if (D_800C3F00 == 15) {
        return NULL;
    }
    D_800C3F00++;
    return &D_800C3F08[D_800C3F00 - 1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15036148.s")
