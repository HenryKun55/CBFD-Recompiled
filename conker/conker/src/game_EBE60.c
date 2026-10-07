#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_15142314(s32, s32, f32 *);
void func_15046C80(f32 *, s32, f32, void *);

s32 func_150BE9B0(f32 *arg0, void *arg1, void *arg2, u8 arg3) {
    f32 sp2C[3];
    s32 var_a1;

    switch (arg3) {
    case 4:
        var_a1 = 0x17;
        break;
    case 5:
        var_a1 = 0x14;
        break;
    case 6:
        var_a1 = 0xC;
        break;
    case 7:
    default:
        var_a1 = 0x10;
        break;
    }
    func_15142314(*(s32 *)((char *)arg1 + 0x1D4), var_a1, arg0);
    if (arg2 == 0) {
        return 1;
    }
    sp2C[0] = arg0[0];
    sp2C[1] = arg0[1] + 10.0f;
    sp2C[2] = arg0[2];
    func_1504715C(arg2, arg1);
    func_15046C80(sp2C, 0, arg0[1] - 50.0f, arg2);
}

s32 func_150BEAA8(s32 arg0, s32 arg1) {
    switch (arg0) {
    case 0:
    case 1:
        return 0x11;
    }
    return -1;
}

extern f32 D_800A00C0;
extern f32 D_800A00C4;
extern f32 D_800A00C8;
extern f32 D_800A00CC;
void func_15141F78(u8, void *, f32, u8, f32 *, u8);
void func_15142180(s32, f32 *, f32, f32, f32);

struct func_150BEACC_s {
    u8 pad0[0x18];
    f32 unk18;
    u8 pad1C[0x8];
};

void func_150BEACC(struct127 *arg0, s32 arg1, s32 arg2) {
    f32 sp4C[3];
    struct func_150BEACC_s sp28;

    if (arg0->unk1D4 == NULL) {
        return;
    }
    if (func_150BE9B0(sp4C, arg0, &sp28, arg1) == 0) {
        return;
    }
    func_15141F78(0xB, &sp28, (f32)arg2 * D_800A00C0 * D_800A00C4, arg0->unk40 * D_800A00C8, sp4C, arg1);
    if (arg2 >= 0x4C) {
        func_15142180(2, sp4C, sp28.unk18, 3.232f, D_800A00CC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EBE60/func_150BEC30.s")

s32 func_150BED28(s32 arg0, s32 arg1) {
    switch (arg0) {
    case 0:
    case 1:
        return 0x12;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EBE60/func_150BED4C.s")

struct func_150BEEB0_s {
    u8 pad[0x84];
    s32 unk84;
};

void func_150BEEB0(struct func_150BEEB0_s *arg0) {
    if (func_1509BE40(1, 0x4063, 6, 0x2000) || func_1509BE40(1, 0x4001, 6, 0x9000)) {
        arg0->unk84 |= 0x1010;
    } else {
        arg0->unk84 &= ~0x1010;
    }
    if (func_1509BE40(1, 0x4069, 6, 0x2000)) {
        arg0->unk84 |= 0x1000000;
    } else {
        arg0->unk84 &= ~0x1000000;
    }
}
