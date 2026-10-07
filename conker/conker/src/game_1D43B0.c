#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A6F00.s")

struct func_151A73EC_s {
    u8 pad0[0x64];
    s16 unk64;
    u8 pad66[0x170 - 0x66];
    struct102 *unk170[2];
};

s32 func_151A73EC(struct func_151A73EC_s *arg0) {
    struct102 **w = arg0->unk170;
    if (arg0->unk64 < 0x20) {
        if (w[1] != NULL) {
            func_1516972C(w[1]);
            w[1] = NULL;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A743C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A7610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A77C0.s")

struct func_151A787C_sub {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};

struct func_151A787C_s {
    u8 pad0[0x34];
    s16 unk34[2];
    s16 unk38;
    u8 pad3A[0x3F - 0x3A];
    u8 unk3F;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 pad43[0x50 - 0x43];
    struct func_151A787C_sub unk50;
};

void func_151A787C(struct func_151A787C_s *arg0) {
    struct func_151A787C_sub *s = &arg0->unk50;

    if (arg0->unk38 < arg0->unk50.unk4) {
        arg0->unk3F = arg0->unk38 * arg0->unk50.unk6;
    }
    if (arg0->unk38 < s->unk8) {
        s16 t = s->unkA * D_800BE9E4;
        arg0->unk34[0] += t;
        arg0->unk34[1] += t;
    }
    arg0->unk40 = arg0->unk41 = arg0->unk42 = arg0->unk38 * s->unk2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A7908.s")
