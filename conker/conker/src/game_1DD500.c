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

struct func_151B1AB0_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
};

void func_151B1AB0(u8 *arg0) {
    struct260 *temp_v0;
    struct func_151B1AB0_s sp28;

    if (arg0 == NULL) {
        return;
    }
    sp28.unk0 = arg0;
    sp28.unk4 = arg0[0x3B];
    sp28.unk8 = 0.0f;
    temp_v0 = func_151491F4(0x3C, -1, 0x15, 1, 0x11, (struct37 *)0xC, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy(&temp_v0->pad18[0x10], &sp28, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1FAC.s")
