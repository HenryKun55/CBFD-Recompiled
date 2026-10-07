#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF484.s")

void func_151CF898(struct127 *arg0, f32 arg1, f32 arg2);

void func_150CF530(s32 arg0) {
    func_151CF898(gObjects, gObjects[0].y_position + 300.0f, -10000.0f);
}

extern s32 D_80088890;
extern s32 D_80088894;
extern s32 D_80088898;

void func_150CF578(s32 arg0) {
    D_80088890 += D_800BE9E4 * 26;
    D_80088894 -= D_800BE9E4 * 28;
    D_80088898 -= D_800BE9E4 * 28;
}

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

extern void (*D_800888B0[])(void);
void func_150CFE98(void *arg0);

void func_150D00C0(u8 *arg0, u8 *arg1, u8 arg2) {
    void (*fn)(void);

    if (arg2 == 0x51) {
        if (arg0[0x28] == *arg1) {
            func_150CFE98(arg0);
        }
    } else {
        fn = D_800888B0[arg0[0x4D]];
        if (fn != NULL) {
            fn();
        }
    }
}

void **func_150CFF10(u8 arg0, u8 *arg1, s16 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6, s32 arg7);
void func_150D0134(u8 arg0, u8 *arg1, s16 arg2, u8 arg3, s32 arg4) {
    u8 sp30[8];
    void **temp_v0;
    sp30[0] = 0;
    temp_v0 = func_150CFF10(arg0, arg1, arg2, 8, 0, 0, arg3, arg4);
    if (temp_v0 != NULL) {
        memcpy(temp_v0[0x12], sp30, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D01A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D02B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D032C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D04C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D0534.s")
