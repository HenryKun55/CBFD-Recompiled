#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150B53D0_s {
    void *unk0;
    u8 unk4;
    f32 unk8;
    f32 unkC;
};

struct260 *func_150B53D0(u8 *arg0, s16 arg1, u8 arg2, s32 arg3) {
    struct260 *temp_v0;
    struct func_150B53D0_s tmp;

    if (arg0 == NULL) {
        return NULL;
    }
    tmp.unk0 = arg0;
    tmp.unk4 = arg0[0x3B];
    tmp.unk8 = 0.0f;
    tmp.unkC = 0.0f;
    temp_v0 = func_15149130((arg1 == -1) ? 300 : arg1, -1, 0x24, -1, (arg1 == -1) ? 0 : 1, 0x23, (struct37 *) 0x10, arg2, arg3);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, &tmp, 0x10);
        func_151D2AB0(6);
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2880/func_150B54A8.s")

void func_150B57C4(s32 arg0) {
    func_151D2B4C(6);
}

void func_150B57E8(s32 arg0) {
    func_150B57C4(arg0);
    func_1514933C(arg0);
}

void func_150B5814(s32 arg0) {
    func_150B57C4(arg0);
    func_15149368(arg0);
}

struct func_150B5840_s {
    s32 unk0;
    u8 unk4;
};

struct func_150B5840_m {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

struct func_150B5840_a {
    u8 pad0[0x28];
    struct func_150B5840_s unk28;
};

void func_150B5840(struct func_150B5840_a *arg0, struct func_150B5840_m *arg1, u8 arg2) {
    struct func_150B5840_s *p = &arg0->unk28;
    s32 v;

    if (arg2 == 0) {
        v = arg1->unk0;
        if ((v == p->unk0) || (((struct func_150B5840_s *)arg1)->unk4 == p->unk4)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        if (p->unk0 == arg1->unk0) {
            p->unk0 = arg1->unk4;
            p->unk4 = arg1->unk9;
        } else if (p->unk0 == arg1->unk4) {
            p->unk0 = arg1->unk0;
            p->unk4 = arg1->unk8;
        }
    }
}
