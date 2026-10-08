#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void *func_15147A80(void *, s32, s32, s32, s32, s32, s32, s32, s32, u8, s32);
void *memcpy(void *, const void *, u32);

typedef struct func_151B6320_v { f32 x, y, z; } func_151B6320_v;

struct func_151B6320_s {
    func_151B6320_v pos;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    u8 pad14;
    s8 unk15;
    u8 pad16[6];
};

struct func_151B6320_d {
    void *obj;
    u8 unk4;
    func_151B6320_v pos;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u8 pad28[8];
};

void func_151B6320(void *arg0, u8 arg1, s32 arg2) {
    struct func_151B6320_s sp74;
    struct func_151B6320_d sp44;
    void *temp_v0;

    sp74.unk15 = 0xA;
    sp74.pos.x = *(f32 *)((char *)arg0 + 0x14);
    sp74.pos.y = *(f32 *)((char *)arg0 + 0x18);
    sp74.pos.z = *(f32 *)((char *)arg0 + 0x1C);
    sp74.unkC = 0x12C;
    sp74.unkE = 6;
    sp44.obj = arg0;
    sp44.unk4 = *(u8 *)((char *)arg0 + 0x3B);
    sp44.pos = sp74.pos;
    sp44.unk14 = 0.0f;
    sp44.unk18 = 0.0f;
    sp44.unk20 = -16384.0f;
    sp44.unk1C = -16384.0f;
    sp44.unk24 = 0.0f;
    sp74.unk10 = 0xD;
    temp_v0 = func_15147A80(&sp74, 0x30, 0x1C, 0xB, 0xB, 0xB, 0, 0, 0, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy(*(void **)((char *)temp_v0 + 0x98), &sp44, 0x2C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B65D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B70B4.s")

void func_15130280(void *, s32, s32, s32, s32, s32);
extern f32 D_800AA47C;

struct func_151B7144_s {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    u8 unk14[7];
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    s32 unk58;
    s32 pad5C;
    s8 unk60;
    s8 unk61;
    s8 unk62;
    s8 unk63;
    s8 unk64;
    s8 unk65;
    u8 pad66[0xA];
};

void func_151B7144(void *arg0, u8 arg1, s32 arg2) {
    struct func_151B7144_s sp28;
    s32 var_v0;
    s32 var_v1;

    sp28.unk1D = 0x29;
    sp28.unk8 = 0xE03;
    sp28.unk0 = 0x200005;
    sp28.unk4 = 0;
    sp28.unkC = 0;
    sp28.unk10 = 0;
    sp28.unk1E = 0x12;
    sp28.unk20 = 0xE;
    if (func_150ADA20() & 1) {
        var_v1 = 0x40;
    } else {
        var_v1 = 0;
    }
    if (func_150ADA20() & 1) {
        var_v0 = 0x80;
    } else {
        var_v0 = 0;
    }
    sp28.unk58 = var_v0 | 1 | var_v1 | 0x200 | 0x400 | 0x800 | 0x4000 | 0x8000 | 0x10000;
    sp28.unk60 = 3;
    sp28.unk61 = 3;
    sp28.unk62 = -1;
    sp28.unk63 = -1;
    sp28.unk64 = -1;
    sp28.unk65 = 0;
    sp28.unk22 = 0x28;
    sp28.unk14[0] = 0xDD;
    sp28.unk14[1] = 0xD3;
    sp28.unk14[2] = 0xCD;
    sp28.unk14[3] = 0xFF;
    sp28.unk14[4] = 0x57;
    sp28.unk14[5] = 0x55;
    sp28.unk14[6] = 0x5A;
    sp28.unk1C = 0xFF;
    sp28.unk54 = 0.0f;
    sp28.unk24 = D_800AA47C;
    sp28.unk30 = *(f32 *)((char *)arg0 + 0x14);
    sp28.unk34 = *(f32 *)((char *)arg0 + 0x18);
    sp28.unk38 = *(f32 *)((char *)arg0 + 0x1C);
    sp28.unk3C = 0.0f;
    sp28.unk40 = 0.0f;
    sp28.unk44 = 0.0f;
    sp28.unk1B = (func_150ADA20() % 56U) + 0xC8;
    sp28.unkA = (func_150ADA20() % 10U) + 0x1E;
    sp28.unk28 = sp28.unk2C = (func_150ADA68() * 50.0f) + 89.0f;
    sp28.unk48 = 0.0f;
    sp28.unk4C = 0.0f;
    sp28.unk50 = 0.0f;
    func_15130280(&sp28, 1, 0, 0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7328.s")

struct func_151B7678_s2 {
    s32 unk0;
    u8 pad4[0x14 - 0x4];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x3B - 0x20];
    u8 unk3B;
};
struct func_151B7678_s1 {
    struct func_151B7678_s2 *unk0;
    u8 unk4;
};
struct func_151B7678_s0 {
    s32 unk0;
    struct func_151B7678_s1 *unk4;
};
struct func_151B7678_s {
    u8 pad[0x98];
    struct func_151B7678_s0 *unk98;
};

s32 func_151B7678(struct func_151B7678_s *arg0, f32 *arg1) {
    struct func_151B7678_s0 *temp_v0 = arg0->unk98;
    struct func_151B7678_s1 *temp_v1 = temp_v0->unk4;
    struct func_151B7678_s2 *temp_a2 = temp_v1->unk0;

    if (temp_a2->unk0 == 0 || temp_a2->unk3B != temp_v1->unk4) {
        return 0;
    }
    arg1[0] = temp_a2->unk14;
    arg1[1] = temp_a2->unk18;
    arg1[2] = temp_a2->unk1C;
    return 1;
}

struct func_151B76CC_s2 {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0x38 - 0x2C];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};
struct func_151B76CC_s1 {
    struct func_151B76CC_s2 *unk0;
};
struct func_151B76CC_s0 {
    s32 unk0;
    struct func_151B76CC_s1 *unk4;
};
struct func_151B76CC_s {
    u8 pad[0x98];
    struct func_151B76CC_s0 *unk98;
};

extern void func_150A7960(void *mtx, f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);

s32 func_151B76CC(struct func_151B76CC_s *arg0, f32 *arg1) {
    struct func_151B76CC_s0 *temp_v1 = arg0->unk98;
    struct func_151B76CC_s1 *temp_t0 = temp_v1->unk4;
    struct func_151B76CC_s2 *temp_v0 = temp_t0->unk0;
    f32 mtx[4][4];

    func_150A8050(mtx, temp_v0->unk20, temp_v0->unk24, temp_v0->unk28);
    mtx[3][0] = temp_v0->unk38;
    mtx[3][1] = temp_v0->unk3C;
    mtx[3][2] = temp_v0->unk40;
    mtx[0][0] *= temp_v0->unk18;
    mtx[0][1] *= temp_v0->unk18;
    mtx[0][2] *= temp_v0->unk18;
    mtx[1][0] *= temp_v0->unk1C;
    mtx[1][1] *= temp_v0->unk1C;
    mtx[1][2] *= temp_v0->unk1C;
    mtx[2][0] *= temp_v0->unk18;
    mtx[2][1] *= temp_v0->unk18;
    mtx[2][2] *= temp_v0->unk18;
    func_150A7960(mtx, 0.0f, 0.0f, -250.0f, &arg1[0], &arg1[1], &arg1[2]);
    return 1;
}

typedef struct func_151B77F4_v { f32 x, y, z; } func_151B77F4_v;
struct func_151B77F4_e {
    func_151B77F4_v pos;
    f32 unkC;
    u8 unk10;
};
struct func_151B77F4_o {
    u8 pad0[0x40];
    func_151B77F4_v unk40;
};
struct func_151B77F4_d {
    struct func_151B77F4_o *unk0;
    u8 pad4[4];
    u8 unk8;
};
struct func_151B77F4_s {
    u8 pad0[0x10];
    func_151B77F4_v pos;
    u8 pad1C[0x25 - 0x1C];
    u8 unk25;
    u8 pad26[0x2C - 0x26];
    s8 unk2C;
    s8 unk2D;
    s8 unk2E;
    u8 pad2F[0x94 - 0x2F];
    struct func_151B77F4_e *unk94;
    struct func_151B77F4_d *unk98;
};
extern s32 (*D_8008FB90[])(struct func_151B77F4_s *, func_151B77F4_v *);
extern f32 func_15143E64(func_151B77F4_v *);

s32 func_151B77F4(struct func_151B77F4_s *arg0) {
    struct func_151B77F4_d *d;
    struct func_151B77F4_e *entries;
    func_151B77F4_v prev;
    func_151B77F4_v diff;
    f32 dist;

    d = arg0->unk98;
    entries = arg0->unk94;
    if (D_800BE9E4 > 0) {
        prev = arg0->pos;
        if (D_8008FB90[d->unk8](arg0, &arg0->pos) == 0) {
            return 0;
        }
        if (d->unk0 != NULL) {
            d->unk0->unk40 = arg0->pos;
        }
        diff.x = arg0->pos.x - prev.x;
        diff.y = arg0->pos.y - prev.y;
        diff.z = arg0->pos.z - prev.z;
        dist = func_15143E64(&diff);
        {
            struct func_151B77F4_e *e = &entries[arg0->unk2E];
            e->pos = arg0->pos;
            e->unkC = dist;
            e->unk10 = 0xFF;
        }
        arg0->unk2E++;
        if (arg0->unk2E == arg0->unk25) {
            arg0->unk2E = 0;
        }
        arg0->unk2C++;
        if (arg0->unk2E == arg0->unk2D) {
            arg0->unk2D++;
            if (arg0->unk2D == arg0->unk25) {
                arg0->unk2D = 0;
            }
            arg0->unk2C--;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7C38.s")

struct func_151B82CC_s {
    u8 pad[8];
    u8 unk8;
};
extern void (*D_8008FB98[])(void *, s32, u8);

void func_151B82CC(void *arg0, s32 arg1, u8 arg2) {
    struct func_151B82CC_s *s;
    void (*func)(void *, s32, u8);

    s = *(struct func_151B82CC_s **)((u8 *)arg0 + 0x98);
    func = D_8008FB98[s->unk8];
    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

void func_151B8318(void *arg0, void *arg1, u8 arg2) {
    s32 temp_v0 = *(s32 *) ((char *) arg0 + 0x98);
    void *temp_v1 = *(void **) ((char *) temp_v0 + 4);

    if (arg2 == 0) {
        temp_v0 = *(s32 *) arg1;
        if (temp_v0 == *(s32 *) temp_v1 || *((u8 *) temp_v1 + 4) == *((u8 *) arg1 + 4)) {
            func_1516972C((struct102 *) arg0);
        }
    }
}

struct func_151B8370_s {
    u8 pad0[0x98];
    struct102 **unk98;
};

void func_151B8370(struct func_151B8370_s *arg0) {
    struct102 **temp_v0 = arg0->unk98;

    if (*temp_v0 != NULL) {
        func_1516972C(*temp_v0);
    }
}

void func_151B83A0(s32 arg0) {
    func_151B8370(arg0);
    func_151478F4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B83CC.s")
