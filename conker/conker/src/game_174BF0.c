#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_15147740.s")

void func_151478D0(u8 *arg0) {
    func_151D5E30(arg0 + 0x84, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_151478F4.s")

void func_15147928(s32 arg0) {
    func_151478D0(arg0);
    func_1514795C(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_1514795C.s")

extern void (*D_8008A2F0[])(void *);

struct func_151479E0_s {
    u8 pad[0x20];
    s32 unk20;
};

void func_151479E0(struct func_151479E0_s *arg0) {
    s32 idx = arg0->unk20;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 20) {
        idx = 0;
    }
    D_8008A2F0[idx](arg0);
}

extern void (*D_8008A340[])(s32 *);

void func_15147A30(s32 *arg0) {
    s32 idx = arg0[8];

    if (idx < 0) {
        idx = 0;
    } else if (idx >= 20) {
        idx = 0;
    }
    D_8008A340[idx](arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_15147A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_15147C4C.s")

struct func_15147D1C_s {
    char pad0[0x20];
    s32 unk20;
};
extern void (*D_8008A390[])(struct func_15147D1C_s *, s32, u8);

void func_15147D1C(struct func_15147D1C_s *arg0, s32 arg1, u8 arg2) {
    void (*func)(struct func_15147D1C_s *, s32, u8) = D_8008A390[arg0->unk20];
    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

extern u8 D_800A5760[];

void func_15147D64(void *arg0, u8 arg1) {
    func_15169260(&D_800A5760, 2, arg0, arg1);
}
