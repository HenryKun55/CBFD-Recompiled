#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1514F640_s {
    u8 unk0;
    u8 pad1[3];
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C[3];
    f32 unk28;
};

s32 func_15144E80(void *, f32 *, f32 *, f32 *);
f32 func_15144A74(f32 *, void *);

void func_1514F640(u8 *arg0, struct func_1514F640_s *arg1) {
    arg1->unk0 = 2;
    arg1->unk28 = *(f32 *)(arg0 + 0x20);
    if (func_15144E80(arg0 + 0xC, arg1->unk10, arg1->unk1C, arg1->unk4) != 0) {
        if (func_15144A74(arg1->unk4, arg0) < 0.0f) {
            arg1->unk4[0] = -arg1->unk4[0];
            arg1->unk4[1] = -arg1->unk4[1];
            arg1->unk4[2] = -arg1->unk4[2];
        }
    }
}

s32 func_15145128();
s32 func_15146078(void *arg0, f32 *arg1, f32 *arg2);

struct func_1514F6E8_s {
    u8 flags;
    f32 a[3];
    f32 b[3];
    f32 c[3];
};

s32 func_1514F6E8(struct func_1514F6E8_s *arg0) {
    s32 flags = arg0->flags;

    if (!(flags & 1)) {
        if (func_15145128(arg0->a, arg0->a, 0, 0) == 0) {
            return 0;
        }
        arg0->a[0] *= 1000.0f;
        arg0->a[1] *= 1000.0f;
        arg0->a[2] *= 1000.0f;
        flags = arg0->flags |= 1;
    }
    if (!(flags & 2)) {
        if (func_15146078(arg0->a, arg0->b, arg0->c) == 0) {
            return 0;
        }
        flags = arg0->flags |= 6;
    }
    if (!(flags & 4)) {
        if (func_15145128(arg0->b, arg0->b, 0, 0) == 0) {
            return 0;
        }
        if (func_15145128(arg0->c, arg0->c, 0, 0) == 0) {
            return 0;
        }
        arg0->flags |= 4;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F8F8.s")

s32 func_15146078(void *arg0, f32 *arg1, f32 *arg2);
void func_1514F8F8(void *arg0, void *arg1, f32 *arg2, f32 *arg3, f32 arg4, u8 arg5, s32 arg6);

void func_1514FB98(f32 *arg0, u8 arg1, s32 arg2) {
    f32 sp34[3];
    f32 sp28[3];

    if (func_15146078(arg0, sp34, sp28) != 0) {
        func_1514F8F8(arg0 + 4, arg0, sp34, sp28, arg0[3], arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FBFC.s")

struct func_1514FCE8_s {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u32 unk8;
    u32 unkC;
    u8 unk10[0xC];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    u32 unk34;
    u32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    s16 unk52;
    s16 unk54;
    s16 unk56;
    s8 unk58;
};

void func_151A2A14(void *, s16, s16, f32, f32, f32, s32, f32, f32, f32, f32, s16, s16, s16, s16, s16, s16, s8, u8, s32);

void func_1514FCE8(struct func_1514FCE8_s *arg0, u8 arg1, s32 arg2) {
    u32 count;
    u32 r1;
    u32 r2;

    for (count = func_150ADA20() % (arg0->unkC + 1) + arg0->unk8; count != 0; count--) {
        r1 = func_150ADA20();
        r2 = func_150ADA20();
        func_151A2A14(arg0->unk10,
                      r1 % (u32)(arg0->unk2 + 1) + arg0->unk0,
                      r2 % (u32)(arg0->unk6 + 1) + arg0->unk4,
                      func_150ADA68() * arg0->unk20 + arg0->unk1C,
                      func_150ADA68() * arg0->unk28 + arg0->unk24,
                      func_150ADA68() * arg0->unk30 + arg0->unk2C,
                      func_150ADA20() % (arg0->unk38 + 1) + arg0->unk34,
                      arg0->unk3C, arg0->unk40, arg0->unk44, arg0->unk48,
                      arg0->unk4C, arg0->unk4E, arg0->unk50, arg0->unk52, arg0->unk54, arg0->unk56,
                      arg0->unk58, arg1, arg2);
    }
}

struct func_1514FEFC_s {
    u8 pad[0x2C];
};

void func_1514F640();
void func_1514FF44();

void func_1514FEFC(s32 arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    struct func_1514FEFC_s sp24;

    func_1514F640(arg0, &sp24);
    func_1514FF44(&sp24, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FF44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515080C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151511FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152874.s")

extern u8 D_800A5FE0[][3];

void func_15152ABC(u8 *arg0) {
    u8 idx;
    u8 *c;

    idx = func_150ADA20() % 5U;
    c = D_800A5FE0[idx];
    arg0[3] = (func_150ADA20() % 101U) + 155;
    arg0[0] = c[0];
    arg0[1] = c[1];
    arg0[2] = c[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151539B4.s")

void func_15153C84(void *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    s32 sp24[11];
    func_1514F640(arg0, sp24);
    func_15153CCC(sp24, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151541B8.s")

struct func_1515452C_sub {
    f32 t;     /* 0x170 */
    f32 end;   /* 0x174 */
    f32 scale; /* 0x178 */
    f32 a;     /* 0x17C */
    f32 b;     /* 0x180 */
    u8 flags;  /* 0x184 */
};

struct func_1515452C_t {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 pos[3];
    u8 pad2C[0x50 - 0x2C];
    f32 vel[3];
    u8 pad5C[0x70 - 0x5C];
    u8 unk70;
    u8 pad71[0x170 - 0x71];
    struct func_1515452C_sub sub;
};

s32 func_1515452C(struct func_1515452C_t *arg0) {
    struct func_1515452C_sub *s = &arg0->sub;
    f32 v;

    v = sqrtf(s->t) * s->scale;
    arg0->unk18 = v;
    if (!(s->flags & 1)) {
        arg0->unk1C = v;
    }
    {
        f32 t = s->t;
        arg0->unk70 = s->a - s->b * t * t;
        s->t += D_800BE9A4;
        if (s->end < s->t) {
            return 0;
        }
    }
    arg0->pos[0] += arg0->vel[0] * D_800BE9A4;
    arg0->pos[1] += arg0->vel[1] * D_800BE9A4;
    arg0->pos[2] += arg0->vel[2] * D_800BE9A4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154684.s")

struct func_15154884_v {
    f32 x, y, z;
};

struct func_15154884_s {
    f32 unk0[10];
    struct func_15154884_v unk28;
    f32 unk0b[7];
    s32 unk50;
    s16 unk54;
    s16 unk56;
    u8 unk58;
    void *unk5C;
    u8 unk60;
    u8 unk61;
    u8 unk62;
    u8 unk63;
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 unk67;
    u8 unk68;
    u8 unk69;
    u8 unk6A;
    s32 unk6C;
    u8 unk70;
    s16 unk72;
    s16 unk74;
    s32 unk78;
};

extern f32 D_800A601C;
extern f32 D_800A6020;
extern f32 D_800A6024;
extern f32 D_800A6028;
extern f32 D_800A602C;
void *func_15132A4C(void *, s32, s32, s32, s32, s32);

void *func_15154884(struct func_15154884_v *arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, s32 arg5) {
    void *ret;
    struct func_15154884_s s;
    f32 sp2C[5];

    if (arg1 <= 0.0f) {
        return NULL;
    }
    sp2C[0] = arg1;
    sp2C[1] = arg2;
    sp2C[2] = arg3;
    sp2C[3] = 0.0f;
    sp2C[4] = D_800A601C / arg1;
    s.unk0[0] = 1.0f;
    s.unk0[1] = 1.0f;
    s.unk0[2] = 0.0f;
    s.unk0[3] = 0.0f;
    s.unk0[4] = func_150ADA68() * 360.0f;
    s.unk0[5] = func_150ADA68() * 360.0f;
    s.unk0[6] = func_150ADA68() * 360.0f;
    s.unk0[7] = 1.0f;
    s.unk0[8] = 1.0f;
    s.unk0[9] = 1.0f;
    s.unk28 = *arg0;
    s.unk0b[0] = 0.0f;
    s.unk0b[1] = 0.0f;
    s.unk0b[2] = 0.0f;
    s.unk0b[3] = func_150ADA68() * D_800A6020 + D_800A6024;
    s.unk0b[4] = 0.0f;
    s.unk0b[5] = func_150ADA68() * D_800A6028 + D_800A602C;
    s.unk0b[6] = 0.0f;
    s.unk50 = 0x140;
    s.unk56 = 0x55;
    s.unk58 = 0;
    s.unk5C = 0;
    s.unk60 = 0xFF;
    s.unk61 = 0x12;
    s.unk62 = 0;
    s.unk63 = 0;
    s.unk64 = 0;
    s.unk65 = 0;
    s.unk66 = 0;
    s.unk67 = 0;
    s.unk68 = 2;
    s.unk6A = 0;
    s.unk6C = 0;
    s.unk70 = 0;
    s.unk72 = 1;
    s.unk74 = 0xFF;
    s.unk54 = 0x12C;
    ret = func_15132A4C(&s, 0, 0, 0x14, arg4, arg5);
    if (ret != NULL) {
        memcpy((u8 *)ret + 0x170, sp2C, 0x14);
    }
    return ret;
}

struct func_15154A88_sub {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

struct func_15154A88_s {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0x50 - 0x2C];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u8 pad5C[0x70 - 0x5C];
    u8 unk70;
    u8 pad71[0x170 - 0x71];
    struct func_15154A88_sub unk170;
};

s32 func_15154A88(struct func_15154A88_s *arg0) {
    f32 s;
    struct func_15154A88_sub *p;

    p = &arg0->unk170;
    s = sinf(p->unkC);
    arg0->unk18 = arg0->unk1C = p->unk4 * s;
    arg0->unk70 = (u8)p->unk8 * s;
    p->unk0 -= D_800BE9A4;
    if (p->unk0 <= 0.0f) {
        return 0;
    }
    p->unkC += p->unk10 * D_800BE9A4;
    arg0->unk20 += arg0->unk50 * D_800BE9A4;
    arg0->unk24 += arg0->unk54 * D_800BE9A4;
    arg0->unk28 += arg0->unk58 * D_800BE9A4;
    return 1;
}

struct func_15154C90_s {
    u8 pad0[0x22];
    s16 unk22;
    u16 unk24;
    s16 unk26;
    s16 unk28;
    u8 pad2A[4];
    u8 unk2E;
    u8 pad2F[0x68 - 0x2F];
    u8 unk68;
};

extern s32 (*D_8008ACC8[])(struct func_15154C90_s *);

void func_15154C90(struct func_15154C90_s *arg0) {
    s32 temp;
    s8 var_a1;

    var_a1 = 0;
    if (arg0->unk24 & 1) {
        arg0->unk22 -= D_800BE9E4;
        if (arg0->unk22 < 0) {
            var_a1 = 1;
        }
    }
    if (arg0->unk68 & 0xF) {
        if (var_a1 == 0) {
            if (D_8008ACC8[arg0->unk68 & 0xF](arg0) == 0) {
                var_a1 = 1;
            }
        }
    }
    if (arg0->unk24 & 8) {
        if (arg0->unk22 < arg0->unk26) {
            temp = arg0->unk22 * arg0->unk28;
            temp = (s16)temp;
            if (temp < arg0->unk2E) {
                arg0->unk2E = temp;
            }
        }
    }
    if (var_a1) {
        func_1516972C((struct102 *)arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154D80.s")

struct func_1515548C_s {
    u8 pad0[0x8];
    f32 x8;
    f32 xC;
    u8 pad10[0x4];
    u16 x14;
};
struct func_1515548C_r {
    u8 pad0[0x10];
    u8 data[0x58];
    u8 x68;
};
s32 func_151555AC(struct func_1515548C_s *arg0, f32 *arg1);
void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);

struct func_1515548C_r *func_1515548C(struct func_1515548C_s *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, s32 arg6) {
    struct func_1515548C_r *ret;
    f32 sp2C[2];

    if (arg2 != 0 && arg3 > 0) {
        sp2C[0] = arg0->x8;
        sp2C[1] = arg0->xC;
        if (func_151555AC(arg0, sp2C) != 0) {
            return NULL;
        }
    }
    ret = func_15167A68((arg0->x14 & 0x20) ? 0x57 : 0x5D, arg6, arg4 + 0x70, 1, arg5, 1);
    if (ret == NULL) {
        return NULL;
    }
    memcpy(ret->data, arg0, 0x58);
    ret->x68 = 0;
    ret->x68 |= arg1;
    return ret;
}

extern void (*D_8008AD04[])(void *, s32, u8);

void func_15155564(void *arg0, s32 arg1, u8 arg2) {
    void (*func)(void *, s32, u8) = D_8008AD04[*((u8 *)arg0 + 0x2A)];
    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151555AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515572C.s")
