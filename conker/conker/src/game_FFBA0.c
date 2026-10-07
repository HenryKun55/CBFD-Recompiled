#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150D26F0_s {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    s32 unkC;
    s32 unk10[1];
};

void func_150D278C(s32, s32 *, u8, u8);

void func_150D26F0(u8 *arg0) {
    struct func_150D26F0_s *p = (struct func_150D26F0_s *)(arg0 + 0x28);

    if (arg0[0x78] & 1) {
        p->unkC -= D_800BE9E4;
        if (p->unkC < 0) {
            func_150D278C(p->unk0, p->unk10, arg0[0xC], arg0[1]);
            p->unkC = (func_150ADA20() % (p->unk8 + 1)) + p->unk4;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D278C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D2924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D2D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D317C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D32FC.s")
