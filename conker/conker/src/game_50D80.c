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

extern u16 D_800C3C9A;

void func_150241B4(struct func_15024130_s *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 i;
    s32 idx;

    if (*arg1 >= D_800C3C9A) {
        func_15024130(*arg1, arg6);
        *arg1 = 0;
        return;
    }
    idx = *arg1;
    for (i = 0; i < *arg1; i++) {
        if (arg0[i].unk4 >= arg5) {
            idx = i;
            break;
        }
    }
    for (i = *arg1 - 1; i >= idx; i--) {
        arg0[i + 1] = arg0[i];
    }
    arg0[idx].unk0 = arg2;
    arg0[idx].unk8 = arg3;
    arg0[idx].unkA = arg4;
    arg0[idx].unk4 = arg5;
    *arg1 += 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150242F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_1502460C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150265CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_15029BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_1502A8A0.s")
