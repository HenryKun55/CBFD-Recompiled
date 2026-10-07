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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E28C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E4A8.s")

Gfx *func_1517EA4C(Gfx *gfx) {
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
    gDPSetOtherMode(gfx++, 0x002C0F, 0x504344);
    return gfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517EAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517EC1C.s")
