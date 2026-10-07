#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E30A0/func_151B5BF0.s")

extern f32 D_800AA434;
extern f32 D_800AA438;
extern f32 D_800AA43C;
extern f32 D_800AA440;
f32 sinf(f32);
void func_15133894(void *);

struct func_151B5E94_s {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x18];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    u8 pad44[0x170 - 0x44];
    f32 unk170[2];
};

void func_151B5E94(struct func_151B5E94_s *arg0) {
    f32 *p = arg0->unk170;

    p[0] += D_800AA434 * D_800BE9A4;
    if (p[0] > D_800AA438) {
        p[0] = 0.0f;
        func_10010F88(0x502, 0x5DC0, 0, 0, -1, arg0->unk38, arg0->unk3C, arg0->unk40, 100, 500);
    }
    if (p[0] < D_800AA43C) {
        arg0->unk18 = arg0->unk1C = sinf(p[0]) * (D_800AA440 * p[1]) + p[1];
    lbl:;
    } else {
        arg0->unk18 = arg0->unk1C = p[1];
    }
    func_15133894(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E30A0/func_151B5FCC.s")
