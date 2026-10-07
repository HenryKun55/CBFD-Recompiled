#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B3DD0.s")

void func_1000FC18(s32, s16, s16, s16, s32);
void func_151478F4(void *);

void func_150B3E74(void *arg0) {
    func_1000FC18(0x221, (s16)*(f32 *)((char *)arg0 + 0x10), (s16)*(f32 *)((char *)arg0 + 0x14), (s16)*(f32 *)((char *)arg0 + 0x18), 0xFA0);
    func_151478F4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B3EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B3F5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B40E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B4294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B4710.s")

struct func_150B5060_s {
    u8 pad0[0x1C];
    u8 unk1C;
    u8 pad1D;
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
    u8 pad31[0x98 - 0x31];
    struct func_150B5060_s *unk98;
};

void func_150B5060(struct func_150B5060_s *arg0) {
    arg0->unk30 = 0;
    arg0->unk1E &= ~2;
    arg0->unk98->unk1C |= 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B5088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B538C.s")
