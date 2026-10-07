#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E5FF0/func_151B8B40.s")

struct func_151B8BE0_s {
    u8 pad0[0x44];
    f32 unk44;
    u8 pad48[0x58 - 0x48];
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
};

f32 sinf(f32);
void func_151D9450(struct func_151B8BE0_s *arg0, s32 arg1);

void func_151B8BE0(struct func_151B8BE0_s *arg0, s32 arg1) {
    arg0->unk44 = (sinf(arg0->unk58) * arg0->unk64) + arg0->unk5C;
    arg0->unk58 = arg0->unk58 + (arg0->unk60 * D_800BE9A4);
    arg0->unk58 = func_15144B68(arg0->unk58);
    func_151D9450(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E5FF0/func_151B8C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E5FF0/func_151B8CFC.s")
