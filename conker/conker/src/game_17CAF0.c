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

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FCE8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515452C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154A88.s")

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
