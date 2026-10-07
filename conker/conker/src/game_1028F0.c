#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150D5440_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
};

void func_150D5440(u8 *arg0, u8 arg1, s32 arg2) {
    struct func_150D5440_s tmp;
    struct260 *temp_v0;

    tmp.unk0 = arg0;
    tmp.unk4 = arg0[0x3B];
    tmp.unk8 = 0.0f;
    temp_v0 = func_15149130(0x12C, -1, 0x38, -1, 0, 0x28, 0xC, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, &tmp, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D54C8.s")

struct func_150D596C_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_150D596C(u8 *arg0, struct func_150D596C_s *arg1, u8 arg2) {
    struct func_150D596C_s *p = (struct func_150D596C_s *)(arg0 + 0x28);
    s32 a;

    if ((arg2 == 0) || (arg2 == 0x2F) || (arg2 == 3)) {
        a = arg1->unk0;
        if ((a == p->unk0) || (*(u8 *)&p->unk4 == *(u8 *)&arg1->unk4)) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if ((a = arg1->unk0) == p->unk0) {
            p->unk0 = arg1->unk4;
            *(u8 *)&p->unk4 = arg1->unk9;
        } else if (p->unk0 == arg1->unk4) {
            p->unk0 = a;
            *(u8 *)&p->unk4 = arg1->unk8;
        }
    }
}

void func_150D5A2C(s32 arg0) {
    func_1514933C(arg0);
}

void func_150D5A4C(void) {
    func_15149368();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D5A6C.s")

void func_151541B8(s32, f32, f32, f32, f32, u8, s32);

void func_150D6388(s32 arg0, u8 arg1, s32 arg2) {
    func_151541B8(arg0, func_150ADA68() * 4.0f + 15.0f, 1.3745700f, (f32)(func_150ADA20() % 56U + 200), 0.0f, arg1, arg2);
}

extern f32 D_800A0AB0;
extern f32 D_800A0AB4;
void func_15154884(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5);

void func_150D6434(s32 arg0, u8 arg1, s32 arg2) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp24 = func_150ADA68();
    sp28 = func_150ADA68();
    sp2C = func_150ADA68();
    func_15154884(arg0, (sp24 * 3.0f) + 8.0f, (sp28 * D_800A0AB0) + D_800A0AB4, (sp2C * 50.0f) + 100.0f, arg1, arg2);
}

extern f32 D_800A0AB8;
extern f32 D_800A0ABC;
extern f32 D_800A0AC0;
extern f32 D_800A0AC4;
extern f32 D_800A0AC8;

struct func_150D64E8_s {
    s32 unk0;
    s32 unk4;
    u8 pad8[0xC];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    s32 unk2C;
    s32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    s16 unk44;
    s16 unk46;
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4E;
    s8 unk50;
};

void func_150D64E8(struct func_150D64E8_s *arg0, f32 *arg1) {
    arg0->unk0 = 6;
    arg0->unk4 = 3;
    *arg1 = D_800A0AB8;
    arg0->unk14 = D_800A0ABC;
    arg0->unk18 = D_800A0AC0;
    arg0->unk1C = 150.0f;
    arg0->unk20 = 105.0f;
    arg0->unk24 = 396.0f;
    arg0->unk28 = 612.0f;
    arg0->unk2C = 4;
    arg0->unk30 = 3;
    arg0->unk34 = 25.0f;
    arg0->unk38 = D_800A0AC4;
    arg0->unk3C = -2.0f;
    arg0->unk40 = D_800A0AC8;
    arg0->unk44 = 20;
    arg0->unk46 = 30;
    arg0->unk48 = 100;
    arg0->unk4A = 100;
    arg0->unk4C = 12;
    arg0->unk4E = 20;
    if (D_80082FA0 >= 2 || D_8008FD8C >= 8) {
        arg0->unk50 = -1;
        return;
    }
    arg0->unk50 = 0;
}

void func_151A5D58(f32, u8, s32, s32, s32, s32, s32, u8, s32);

void func_150D65F0(s32 arg0, s32 arg1, u8 arg2, s32 arg3) {
    u32 b;
    u32 a;
    f32 f;

    f = func_150ADA68();
    a = func_150ADA20();
    b = func_150ADA20();
    func_151A5D58((f * 100.0f) + 150.0f, (a % 71) + 130, arg0, arg1, (b % 31) + 50, 0, 1, arg2, arg3);
}

void func_15182670(s32, s32, s32, u8, s32, u8, u8, s32);

void func_150D66A4(u8 arg0, u8 arg1, s32 arg2) {
    s32 pad; u32 temp;
    temp = func_150ADA20();
    func_15182670(0xFF, 0xFF, 0xFF, (temp % 56U) + 200, (func_150ADA20() % 6U) + 25, arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6730.s")

void func_150D6C98(f32 *arg0, f32 *arg1) {
    arg1[0] = arg0[5];
    arg1[1] = arg0[6] + 60.0f;
    arg1[2] = arg0[7];
}

struct func_150D6CC4_v { f32 x, y, z; };
struct func_150D6CC4_t {
    u8 *unk0;
    u8 unk4;
    s32 unk8;
};
struct func_150D6CC4_s {
    u8 pad0[0x40];
    struct func_150D6CC4_v unk40;
    struct func_150D6CC4_v unk4C;
    struct func_150D6CC4_v unk58;
    f32 unk64;
    u8 pad68[0xA8 - 0x68];
    struct func_150D6CC4_t unkA8;
};
void func_15131958(struct func_150D6CC4_v *, s32);

s32 func_150D6CC4(struct func_150D6CC4_s *arg0, s32 arg1) {
    u8 *p = arg0->unkA8.unk0;
    struct func_150D6CC4_t *t = &arg0->unkA8;

    if (*(s32 *)p == 0 || t->unk4 != p[0x3B]) {
        return 0;
    }
    func_150D6C98((f32 *)p, (f32 *)&arg0->unk40);
    {
    struct func_150D6CC4_v old = arg0->unk58;
    f32 dx, dy, dz;
    arg0->unk58.y += arg0->unk64 * D_800BE9A4;
    func_15131958(&arg0->unk58, t->unk8);
    dx = (arg0->unk58.x - old.x) * D_800BE9A8;
    dy = (arg0->unk58.y - old.y) * D_800BE9A8;
    dz = (arg0->unk58.z - old.z) * D_800BE9A8;
    arg0->unk4C.x += old.x * D_800BE9A4 + dx * D_800BE9A4 * D_800BE9A4 * 0.5f;
    arg0->unk4C.y += old.y * D_800BE9A4 + dy * D_800BE9A4 * D_800BE9A4 * 0.5f;
    arg0->unk4C.z += old.z * D_800BE9A4 + dz * D_800BE9A4 * D_800BE9A4 * 0.5f;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6E60.s")

struct func_150D6F0C_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

s32 func_150D6F0C(u8 *arg0, s32 arg1) {
    struct func_150D6F0C_s *p = (struct func_150D6F0C_s *)(arg0 + 0xA8);
    u8 *obj = p->unk0;

    if (*(s32 *)obj == 0 || p->unk4 != obj[0x3B]) {
        return 0;
    }
    func_150D6C98((f32 *)obj, (f32 *)(arg0 + 0x40));
    *(f32 *)(arg0 + 0x38) = *(f32 *)(arg0 + 0x3C) = sqrtf(p->unk8) * p->unk10;
    arg0[0x2B] = p->unk14 - p->unk18 * p->unk8 * p->unk8;
    p->unk8 += D_800BE9A4;
    if (p->unkC < p->unk8) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D7068.s")
