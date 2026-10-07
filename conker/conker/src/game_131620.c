#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_131620/func_15104170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_131620/func_151041E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_131620/func_1510448C.s")

extern void *D_800CC5EC;

u8 func_151044F4(void) {
    if (D_800CC5EC != NULL) {
        return *((u8 *)D_800CC5EC + 0x7D);
    }
    return 0;
}
