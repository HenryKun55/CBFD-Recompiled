#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF484.s")

void func_151CF898(struct127 *arg0, f32 arg1, f32 arg2);

void func_150CF530(s32 arg0) {
    func_151CF898(gObjects, gObjects[0].y_position + 300.0f, -10000.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF5E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF800.s")

struct func_150CFBEC_sub {
    u8 flags;
    u8 pad1[3];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_150CFBEC_s {
    u8 pad0[0x10];
    f32 unk10;
    u8 pad14[0x70 - 0x14];
    struct func_150CFBEC_sub unk70;
};

void func_150CFBEC(struct func_150CFBEC_s *arg0, f32 *arg1, u8 arg2) {
    struct func_150CFBEC_sub *p = &arg0->unk70;
    if (arg2 == 0x52) {
        p->flags |= 1;
        p->unk4 = 0.0f;
        p->unk8 = arg0->unk10;
        p->unkC = arg1[0] - arg0->unk10;
    }
}

void func_150CFC38(f32 arg0) {
    f32 sp1C;

    sp1C = arg0;
    func_1515572C(&sp1C, 0x52);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CFC60.s")

u8 *func_150CFD20(u8 *s) {
    while (*s != 0xBD && *s != 0) {
        s++;
    }
    return s;
}

u8 *func_150CFD5C(u8 *s) {
    while (*s != 0) {
        s++;
    }
    return s;
}

s32 func_150CFD84(s32 arg0, s32 *arg1) {
    s32 temp_v0 = func_150CFD20(arg0);
    *arg1 = temp_v0;
    return temp_v0 - arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CFDB8.s")

struct func_150CFE3C_inner {
    u8 pad0[0xC];
    void *src;
    u8 pad10[4];
    u8 size;
    u8 idx;
    u8 pad16[2];
    u8 *buf[1];
};
struct func_150CFE3C_s {
    u8 pad0[0x28];
    struct func_150CFE3C_inner sub;
};

void func_150CFE3C(struct func_150CFE3C_s *arg0) {
    struct func_150CFE3C_inner *s;
    s = &arg0->sub;
    memcpy(arg0->sub.buf[arg0->sub.idx], arg0->sub.src, arg0->sub.size);
    s->buf[s->idx][s->size] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CFE98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CFF10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D0034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D00C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D0134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D01A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D02B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D032C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D04C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D0534.s")
