#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F22D0.s")

s32 func_150F237C(s32 arg0, s32 arg1) {
    return 0xE;
}

struct func_150F2390_s {
    u8 pad[0x1D4];
    void *unk1D4;
};
void func_150F22D0();

void func_150F2390(struct func_150F2390_s *arg0, u8 arg1, s32 arg2) {
    u8 sp1C[0xC];

    if (arg0->unk1D4 != NULL) {
        func_150F22D0(sp1C, arg0, arg1);
        func_151C329C(sp1C, 0xFF, 0);
    }
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} func_150F23E0_sub;
struct func_150F23E0_s {
    u8 pad0[0x20];
    f32 unk20;
    f32 pad24;
    f32 unk28;
    u8 pad2C[0x170 - 0x2C];
    func_150F23E0_sub unk170;
};
f32 sinf(f32);

s32 func_150F23E0(struct func_150F23E0_s *arg0) {
    func_150F23E0_sub *p = &arg0->unk170;

    arg0->unk20 = sinf(p->unk0) * p->unk10;
    arg0->unk28 = sinf(p->unk4) * p->unk14;
    p->unk0 = func_15144B68(p->unk0 + p->unk8 * D_800BE9A4);
    p->unk4 = func_15144B68(p->unk4 + p->unkC * D_800BE9A4);
    return 1;
}

struct func_150F2480_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
};

struct func_150F2480_a {
    u8 pad0[0x50];
    s32 unk50;
};

s32 func_150F2480(struct func_150F2480_a *arg0) {
    struct func_150F2480_s *s;

    s = (struct func_150F2480_s *) ((s32) arg0 + arg0->unk50 + 0xF8);
    s->unk24 = sinf(s->unk0) * s->unk10;
    s->unk28 = sinf(s->unk4) * s->unk14;
    s->unk0 = func_15144B68(s->unk0 + s->unk8 * D_800BE9A4);
    s->unk4 = func_15144B68(s->unk4 + s->unkC * D_800BE9A4);
    return 1;
}

struct func_150F2518_s {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
};

struct func_150F2518_a {
    u8 pad0[0x50];
    s32 unk50;
    u8 pad54[0x78 - 0x54];
    Mtx unk78[2];
    u8 unkF8[1];
};

s32 func_150F2518(struct func_150F2518_a *arg0, s32 arg1) {
    f32 mtx[4][4];
    struct func_150F2518_s *temp_v0;


    temp_v0 = (struct func_150F2518_s *) ((s32) arg0 + arg0->unk50 + 0xF8);
    func_150A8050(mtx, temp_v0->unk24, 0.0f, temp_v0->unk28);
    mtx[3][0] = temp_v0->unk18;
    mtx[3][1] = temp_v0->unk1C;
    mtx[3][2] = temp_v0->unk20;
    guMtxF2L(mtx, (Mtx *) ((s32) arg0 + (D_800BE9C0 << 6) + 0x78));
    return 1;
}

struct func_150F25A0_s14 {
    u8 pad0[0xE];
    s16 unkE;
    s16 unk10;
    s16 unk12;
};

struct func_150F25A0_s18 {
    u8 pad0[0x20];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0x38 - 0x2C];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};

struct func_150F25A0_s {
    u8 pad0[0x14];
    struct func_150F25A0_s14 *unk14;
    struct func_150F25A0_s18 *unk18;
};

void func_150A7960(void *mtx, f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);

s32 func_150F25A0(struct func_150F25A0_s *arg0) {
    struct func_150F25A0_s18 **p;
    f32 z;
    f32 y;
    f32 x;
    f32 mtx[4][4];

    func_150A8050(mtx, arg0->unk18->unk20 * 3.0f, 0.0f, arg0->unk18->unk28 * 3.0f);
    p = &arg0->unk18;
    if (p) {}
    mtx[3][0] = p[0]->unk38;
    mtx[3][1] = p[0]->unk3C;
    mtx[3][2] = p[0]->unk40;
    func_150A7960(mtx, 0.0f, -495.0f, 0.0f, &x, &y, &z);
    arg0->unk14->unkE = x;
    arg0->unk14->unk10 = y;
    arg0->unk14->unk12 = z;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F26A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2994.s")
