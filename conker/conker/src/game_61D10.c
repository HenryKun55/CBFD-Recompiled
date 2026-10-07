#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034860.s")

extern s16 D_800C3EF0;
extern f32 D_80097D60;

struct func_15034EB4_e {
    u8 pad[0x34];
    f32 unk34;
    u8 pad2[0x8];
};

struct func_15034EB4_s {
    u8 pad[0x14C];
    f32 unk14C;
    u8 pad2[0x84];
    struct func_15034EB4_e *unk1D4;
};

void func_15034EB4(struct func_15034EB4_s *arg0, s32 arg1, s32 arg2) {
    f32 temp;
    s32 base;

    if (D_800C3EF0 != 0) {
        temp = D_800C3EF0 * D_80097D60 * arg0->unk14C;
        base = (s32)arg0->unk1D4;
        ((struct func_15034EB4_e *)((arg1 << 6) + base))->unk34 -= temp;
        if (arg2 != -1) {
            ((struct func_15034EB4_e *)((arg2 << 6) + base))->unk34 -= temp;
        }
    }
}

extern u8 D_800C3F00;

void func_15034F20(void) {
    D_800C3F00 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034F30.s")

struct func_150356C8_s {
    u8 pad[0xC];
};
extern u8 D_800C3F00;
extern struct func_150356C8_s D_800C3F08[];

void *func_150356C8(void) {
    if (D_800C3F00 == 15) {
        return NULL;
    }
    D_800C3F00++;
    return &D_800C3F08[D_800C3F00 - 1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15036148.s")
