#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B0050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B01B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B03B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B09BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B0B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B118C.s")

struct func_151B1478_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x5C - 0x1E];
    u8 unk5C;
};

s32 func_151B1478(struct func_151B1478_s *arg0) {
    s32 temp;
    if (arg0->unk1C < 32) {
        temp = arg0->unk1C * 8;
        if (temp < arg0->unk5C) {
            arg0->unk5C = temp;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B14AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B19A4.s")

void func_151B1918();

void func_151B1A58(s32 arg0) {
    func_151B1918(arg0);
    func_1514933C(arg0);
}

void func_151B1A84(s32 arg0) {
    func_151B1918(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1FAC.s")
