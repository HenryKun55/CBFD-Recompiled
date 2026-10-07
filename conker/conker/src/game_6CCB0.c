#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_6CCB0/func_1503F800.s")

void func_1503F800(void *, s16, s16, s32, s32);

struct func_1503F904_s {
    u8 pad0[0x14];
    f32 unk14;
    u8 pad18[4];
    f32 unk1C;
    u8 pad20[0x300];
    u8 unk320[1];
};

void func_1503F904(struct func_1503F904_s *arg0, s32 arg1, s32 arg2) {
    func_1503F800(arg0->unk320, arg0->unk14, arg0->unk1C, arg1, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6CCB0/func_1503F964.s")
