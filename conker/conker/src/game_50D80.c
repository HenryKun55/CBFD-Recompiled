#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150238D0(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150238D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_15023BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_15023DE0.s")

struct func_15024130_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 pad9;
    u16 unkA;
};
extern struct func_15024130_s *D_800C3D50;
void func_1502A8A0();

void func_15024130(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < arg0; i++) {
        func_1502A8A0(D_800C3D50[i].unk0, D_800C3D50[i].unk8, D_800C3D50[i].unkA, D_800C3D50[i].unk4, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150241B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150242F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_1502460C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150265CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_15029BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_1502A8A0.s")
