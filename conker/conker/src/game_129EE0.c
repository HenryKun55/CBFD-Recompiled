#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCBC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCF1C.s")

void func_150FCFB0(s32 arg0) {
    func_15103828();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCFD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FD514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FDB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FDBA0.s")

struct func_150FDC2C_s {
    u8 pad0[0x24];
    struct102 *unk24;
    struct102 *unk28;
    u8 pad2C[0x54 - 0x2C];
    u16 unk54;
    u16 unk56;
};

struct func_150FDC2C_t {
    u8 pad0[0x110];
    struct func_150FDC2C_s unk110;
};

void func_150FDC2C(struct func_150FDC2C_t *arg0) {
    struct func_150FDC2C_s *s = &arg0->unk110;

    if (arg0->unk110.unk24 != NULL) {
        func_1516972C(s->unk24);
    }
    if (s->unk28 != NULL) {
        func_1516972C(s->unk28);
    }
    if (s->unk54 != 0) {
        func_100111C8(s->unk54);
    }
    if (s->unk56 != 0) {
        func_100111C8(s->unk56);
    }
}

void func_150FDCAC(s32 arg0) {
    func_150FDC2C(arg0);
    func_1513CA6C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FDCD8.s")
