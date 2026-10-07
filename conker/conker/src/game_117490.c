#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150E9FE0.s")

s32 func_150EA10C(s32 arg0) {
    *(s32*)(arg0 + 0x80) = 0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA11C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA5CC.s")

void func_150E5AE0();

void func_150EA8E0(s32 arg0) {
    func_150E5AE0();
}

void func_150EA904(s32 arg0, s32 arg1) {
    if (D_800DBEF4[arg1].pad70[2] == 0xE0) {
        D_800DBEF4[arg1].unk73 = (D_800DBEF4[arg1].unk73 | 1) | 2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EAB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EAE24.s")
