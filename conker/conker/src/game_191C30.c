#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15164780.s")

void func_15164888(u8 *arg0) {
    arg0[0x10] |= 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_1516489C.s")

extern u8 D_800DCDE0[];

void func_15164EE4(void) {
    bzero(D_800DCDE0, 0x60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15164F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15165628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_151658DC.s")

struct func_15165B80_s {
    u8 pad[0x108];
    u8 unk108[0xC];
    s32 unk114;
    s32 unk118;
    f32 unk11C;
};

void func_15165BB0(struct func_15165B80_s *, void *, s32, s32, f32);

void func_15165B80(struct func_15165B80_s *arg0) {
    func_15165BB0(arg0, arg0->unk108, arg0->unk114, arg0->unk118, arg0->unk11C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15165BB0.s")
