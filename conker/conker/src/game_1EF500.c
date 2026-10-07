#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C229C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2AD0.s")

struct func_151C2E4C_s {
    s32 unk0;
    u8 unk4;
};

s32 func_151C2E4C(struct func_151C2E4C_s *a0, struct func_151C2E4C_s *a1) {
    if (a0 == a1) {
        return 0;
    }
    if (a0->unk0 == 0) {
        return 0;
    }
    if (a0->unk4 == 0xFF) {
        return 0;
    }
    return 1;
}

struct func_151C2E94_s {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x127 - 5];
    u8 unk127;
};

s32 func_151C2E94(struct func_151C2E94_s *arg0, struct func_151C2E94_s *arg1) {
    if (arg0 == arg1) {
        return 0;
    }
    if (arg0->unk0 == 0) {
        return 0;
    }
    if (arg0->unk4 == 0xFF) {
        return 0;
    }
    if (arg0->unk127 == 0xFF) {
        return 0;
    }
    return 1;
}

struct func_151C2EF0_s {
    u8 pad0[1];
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x170 - 0xD];
    u8 unk170[0x44];
    s32 unk1B4;
};
void func_151D4DAC(s32, s32, s32, s32, s32, s32, void *, s32, s32);

void func_151C2EF0(s32 arg0, s32 arg1, struct func_151C2EF0_s *arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_151D4DAC(arg0, arg1, arg3, arg4, arg5, arg2->unk1B4, arg2->unk170, arg2->unkC, arg2->unk1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C329C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C36D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C3B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C436C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C43E0.s")

void func_151C4510(f32 *arg0, f32 *arg1, f32 arg2) {
    arg0[13] += arg1[1] * arg2;
    arg0[14] += arg1[2] * arg2;
    arg0[15] += arg1[3] * arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C455C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4B0C.s")
