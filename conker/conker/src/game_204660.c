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

struct func_151D74B0_s {
    void *ptr;
    u8 unk4;
    u8 unk5;
    s8 unk6;
};

extern u8 *func_151D71B0(s32, s32, s32, f32, s32, s32, s32);
extern void *memcpy(void *, const void *, u32);

void func_151D74B0(void *arg0, u8 arg1, s8 arg2, u8 arg3, s32 arg4) {
    struct func_151D74B0_s sp30;
    u8 *ret;

    sp30.ptr = arg0;
    sp30.unk4 = *((u8 *)arg0 + 0x3B);
    sp30.unk5 = arg1;
    sp30.unk6 = arg2;
    ret = func_151D71B0(0x12C, 0, 0, 12.0f, 8, arg3, arg4);
    if (ret != NULL) {
        memcpy(ret + 0x40, &sp30, 8);
    }
}

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

typedef struct {
    f32 x, y, z;
} func_151D7830_v;

struct func_151D7830_s {
    u8 unk0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x1B];
    void *unk28;
    u8 pad2C[4];
    func_151D7830_v unk30;
};

struct func_151D7830_a {
    func_151D7830_v pos;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    s32 unk18;
};

struct func_151D7830_b {
    struct func_151D7830_s *ptr;
    func_151D7830_v pos;
    func_151D7830_v vel;
};

extern void *func_15147A80();

void func_151D7830(struct func_151D7830_s *arg0) {
    void *ret;
    struct func_151D7830_b b;
    struct func_151D7830_a a;
    void *temp;

    b.ptr = arg0;
    b.pos = arg0->unk30;
    b.vel.x = 0.0f;
    b.vel.y = 0.0f;
    b.vel.z = 0.0f;
    a.unk15 = 0x19;
    a.pos = arg0->unk30;
    a.unkC = 0x12C;
    a.unkE = 0x76;
    a.unk10 = 0x12;
    a.unk14 = 4;
    a.unk18 = 0;
    ret = func_15147A80(&a, 0x20, 0x1C, 0xD, 0x10, 0x10, 0, 0, 0, arg0->unkC, arg0->unk1);
    if (ret != NULL) {
        memcpy(*(void **)((u8 *)ret + 0x98), &b, 0x1C);
        arg0->unk28 = ret;
    }
}

typedef struct { f32 x, y, z; } func_151D792C_v;
struct func_151D792C_e {
    func_151D792C_v pos;
    u8 unkC[0x10];
};
struct func_151D792C_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[5];
    u8 unk25;
    u8 pad26[6];
    s8 unk2C;
    s8 unk2D;
    s8 unk2E;
    u8 pad2F[0x54 - 0x2F];
    func_151D792C_v unk54;
    u8 pad60[0x94 - 0x60];
    struct func_151D792C_e *unk94;
};

void func_151D8718(f32 *arg0, f32 *arg1, f32 arg2);

s32 func_151D792C(struct func_151D792C_s *arg0) {
    struct func_151D792C_e *arr = arg0->unk94;
    s32 i;
    struct func_151D792C_e *e;

    if (arg0->unk2C < 2 && (arg0->unk1E & 8)) {
        return 0;
    }
    i = arg0->unk2E;
    while (i != arg0->unk2D) {
        i--;
        if (i < 0) {
            i = arg0->unk25 - 1;
        }
        e = &arr[i];
        func_151D8718(&e->pos.x, (f32 *)e->unkC, D_800BE9A4);
    }
lbl:
    if (arg0->unk2C > 0) {
        arg0->unk54 = arr[arg0->unk2D].pos;
    } else {
        arg0->unk54.x = 0.0f;
        arg0->unk54.y = 0.0f;
        arg0->unk54.z = 0.0f;
    }
    return 1;
}

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
