#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1517E080_s {
    u8 pad0[0xC];
    f32 unkC;
    f32 unk10;
    u8 pad14[0x10];
    struct func_1517E080_s *next;
    s16 unk28;
    u8 pad2A[4];
    u8 unk2E;
    u8 unk2F;
    u8 unk30;
};

void *allocate_memory();

struct func_1517E080_s *func_1517E080(s32 arg0, s32 arg1) {
    struct func_1517E080_s *new;
    struct func_1517E080_s **link;
    struct func_1517E080_s *cur;

    cur = D_800DDD64;
    if (cur != NULL) {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        link = &cur->next;
    } else {
        link = (struct func_1517E080_s **)&D_800DDD64;
    }
    new = allocate_memory(0x34, 1, 0, 1);
    if (new == NULL) {
        return NULL;
    }
    *link = new;
    new->next = NULL;
    new->unk28 = 0;
    new->unk2E = 0;
    new->unk10 = 0.0f;
    new->unkC = 0.0f;
    new->unk2F = arg0;
    new->unk30 = arg1;
    return new;
}

struct func_1517E134_s {
    u8 pad[0x24];
    struct func_1517E134_s *next;
};

void func_1517E134(struct func_1517E134_s *arg0) {
    struct func_1517E134_s *prev;

    if (arg0 == (struct func_1517E134_s *)D_800DDD64) {
        D_800DDD64 = arg0->next;
    } else {
        for (prev = D_800DDD64; prev != NULL && prev->next != arg0; prev = prev->next) {
        }
        if (prev == NULL) {
            return;
        }
        prev->next = arg0->next;
    }
    func_10004074(arg0);
}

struct func_1517E1AC_s {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    u8 pad14[0x24 - 0x14];
    struct func_1517E1AC_s *next;
    u8 pad28[2];
    u16 unk2A;
};

void func_1517E1AC(void) {
    struct func_1517E1AC_s *p;

    for (p = D_800DDD64; p != NULL; p = p->next) {
        if (p->x >= 0.0f && p->x < D_800BE620 && p->y >= 0.0f && p->y < D_800BE624) {
            p->unk2A = ((u16 *)D_800BE9C4)[(s32)p->x + (u32)(s32)p->y * D_800BE620];
        }
    }
}

struct func_1517E28C_s {
    u8 pad0[0xC];
    f32 unkC;
    f32 unk10;
    u8 pad14[0x10];
    struct func_1517E28C_s *next;
    u16 unk28;
    u16 unk2A;
    u16 unk2C;
    u8 unk2E;
    u8 unk2F;
    u8 unk30;
};

struct func_1517E28C_c {
    u8 v[2];
};

s32 func_1517E4A8(s32, struct func_1517E28C_s *, u8, u8, u8, s32, u8 *);
s32 func_1517EC1C(struct func_1517E28C_s *, s32 *);
s32 func_1517EAAC(f32 arg0, f32 arg1, s32 arg2, f32 *arg3, f32 *arg4);
extern struct func_1517E28C_c D_8008D004;
extern struct func_1517E28C_c D_8008D008;
extern struct func_1517E28C_c D_8008D00C;
extern u8 D_800DDD60;

s32 func_1517E28C(s32 arg0, s32 arg1) {
    s32 var_s2;
    s32 flags;
    s32 sp6C;
    u8 *var_v1;
    struct func_1517E28C_s *p;
    struct func_1517E28C_c sp60;
    struct func_1517E28C_c sp5C;
    struct func_1517E28C_c sp58;
    s32 fail;
    s32 *temp_v0;

    sp60 = D_8008D004;
    sp5C = D_8008D008;
    sp58 = D_8008D00C;
    D_800DDD60 = 0;
    for (p = D_800DDD64; p != NULL; p = p->next) {
        if (p->unk30 != 0) {
            flags = p->unk2E;
            fail = 0;
            if (flags & 1) {
                if (!D_800DCDD0) {
                    fail = 1;
                } else {
                    temp_v0 = (s32 *)D_8008CFFC[D_800B0DF0->unk10];
                    var_s2 = func_1517EAAC(((f32 *)temp_v0)[0], ((f32 *)temp_v0)[1], temp_v0[2], &p->unkC, &p->unk10);
                    if (var_s2 != 1) {
                        fail = 1;
                    }
                    if (p->unk2A != 0xFFFC) {
                        var_s2 = -1;
                    } else {
                        var_s2 = 0xFF;
                    }
                }
            } else {
                var_s2 = func_1517EC1C(p, &sp6C);
                if (var_s2 != 1) {
                    fail = 1;
                }
                if (p->unk2C - sp6C < 0x1E) {
                    var_s2 = 0x100;
                } else {
                    var_s2 = -1;
                }
            }
            flags = p->unk2E;
            var_v1 = (flags & 2) ? &D_800DD2D0 : NULL;
            if (fail == 0) {
                arg0 = func_1517E4A8(arg0, p, sp60.v[p->unk2F], sp5C.v[p->unk2F], sp58.v[p->unk2F], var_s2, var_v1);
            } else if (var_v1 != NULL) {
                *var_v1 = 0;
            }
        }
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E4A8.s")

Gfx *func_1517EA4C(Gfx *gfx) {
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
    gDPSetOtherMode(gfx++, 0x002C0F, 0x504344);
    return gfx;
}

void func_15110360(s32 arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4);
void func_150A7A00(void *arg0, f32 arg1, f32 arg2, s32 arg3, f32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7);

s32 func_1517EAAC(f32 arg0, f32 arg1, s32 arg2, f32 *arg3, f32 *arg4) {
    f32 temp_f0;
    f32 nx;
    f32 nz;
    f32 ny;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    Mtx sp38;
    f32 x;
    f32 y;
    char *temp_v0;

    temp_v0 = (char *)D_800DBFF0 + D_80082FA4 * 0x9A0;
    nx = -*(f32 *)(temp_v0 + 0x388);
    ny = -*(f32 *)(temp_v0 + 0x380);
    nz = *(f32 *)(temp_v0 + 0x5EC);
    func_15110360(D_80082FA4, &sp38, nx, ny, nz);
    temp_v0 = (char *)D_800BE628 + D_80082FA4 * 0x180;
    x = *(f32 *)(temp_v0 + 0xC);
    y = *(f32 *)(temp_v0 + 0x10);
    func_150A7A00(&sp38, arg0, arg1, arg2, &sp84, &sp80, &sp7C, &sp78);
    if (sp78 > 10.0f) {
        temp_f0 = 1.0f / sp78;
        sp84 = sp84 * x * temp_f0;
        sp80 = sp80 * y * temp_f0;
        *arg3 = x + sp84;
        *arg4 = y - sp80;
        return 1;
    }
    *arg3 = 0.0f;
    *arg4 = 0.0f;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517EC1C.s")
