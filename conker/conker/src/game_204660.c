#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D71B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7264.s")

struct func_151D73A8_s {
    u8 pad[0x2C];
    volatile u8 unk2C;
};

typedef void (*func_151D73A8_fn)(struct func_151D73A8_s *, s32, u8);
extern func_151D73A8_fn D_8008FCA4[];

void func_151D73A8(struct func_151D73A8_s *arg0, s32 arg1, u8 arg2) {
    if (D_8008FCA4[arg0->unk2C] == NULL) {
        return;
    }
    D_8008FCA4[arg0->unk2C](arg0, arg1, arg2);
}

void func_151D7404(void) {
    func_151D77C8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7450.s")

struct func_151D747C_s {
    void *ptr;
    u8 val;
};

void func_151D747C(void *arg0) {
    struct func_151D747C_s sp18;

    sp18.ptr = arg0;
    sp18.val = *((u8 *)arg0 + 0x3B);
    func_151494E0((s32)&sp18, 0x3D);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D74B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D75C4.s")

struct func_151D7724_s2 {
    u8 pad0[0x84];
    u16 unk84;
    u8 pad86[0x94 - 0x86];
    s32 unk94;
};

struct func_151D7724_s3 {
    u8 pad0[5];
    u8 unk5;
};

struct func_151D7724_s {
    u8 pad0[0x28];
    struct func_151D7724_s3 unk28;
    u8 pad2E[0x40 - 0x2E];
    struct func_151D7724_s2 *unk40;
};

s32 func_151D7724(struct func_151D7724_s *arg0) {
    struct func_151D7724_s3 *p = &arg0->unk28;
    struct func_151D7724_s2 *temp = arg0->unk40;

    if ((temp->unk94 & 2) || (temp->unk84 == 4) || (temp->unk84 == 10) || (temp->unk84 == 12)) {
        p->unk5 &= ~1;
    }
    return 1;
}

struct func_151D7770_sub { u8 pad[5]; u8 unk5; };
struct func_151D7770_t { u8 pad[0x84]; u16 unk84; };
struct func_151D7770_s {
    u8 pad0[0x28];
    struct func_151D7770_sub unk28;
    u8 pad2[0x40 - 0x2E];
    struct func_151D7770_t *unk40;
};

s32 func_151D7770(struct func_151D7770_s *arg0) {
    struct func_151D7770_t *t = arg0->unk40;
    struct func_151D7770_sub *p = &arg0->unk28;
    if (t->unk84 == 0) {
        p->unk5 &= ~1;
    }
    return 1;
}

struct func_151D779C_s {
    u8 pad0[0x28];
    u8 unk28[8];
    u8 pad30[0x10];
    u8 *unk40;
};

s32 func_151D779C(struct func_151D779C_s *arg0) {
    u8 *q;
    u8 *p;

    q = arg0->unk40;
    p = arg0->unk28;
    if (q[0xAD] != 0) {
        p[5] &= ~1;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D77C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D792C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D80C4.s")

extern f32 D_800AB2EC;
extern f32 D_800AB2F0;

void func_151D8718(f32 *arg0, f32 *arg1, f32 arg2) {
    f32 temp = *arg1;
    *arg1 += D_800AB2EC * arg2;
    arg0[1] += (temp * arg2) + (D_800AB2F0 * (arg2 * arg2));
}

struct func_151D8764_s {
    u8 pad0[0x98];
    s32 **unk98;
};

void func_151D8764(struct func_151D8764_s *arg0) {
    s32 **temp_v0 = arg0->unk98;
    s32 *temp_v1 = *temp_v0;
    if (temp_v1 != NULL) {
        temp_v1[0x28 / 4] = 0;
    }
}

void func_151D8780(s32 arg0) {
    func_151D8764(arg0);
    func_151478F4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D87AC.s")
