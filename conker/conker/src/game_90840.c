#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s16 func_15063390(struct127 *arg0) {
    return func_1505A630(gObjects[arg0->unk222].x_position - arg0->x_position,
                         arg0->z_position - gObjects[arg0->unk222].z_position, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150634E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063570.s")

void func_15081690(void *, s32, s32, s32, f32, f32, f32, void *, f32, s32, s32, s32, s32, s32, s32);
void func_150636A4(void *);

void func_15063628(void *arg0, f32 arg1) {
    char *temp_v0 = *(char **)((char *)arg0 + 0x31C);

    func_15081690(arg0, *(s32 *)(temp_v0 + 0x13C), *(s32 *)(temp_v0 + 0x140), *(s32 *)(temp_v0 + 0x144),
                  *(f32 *)(temp_v0 + 0x130), *(f32 *)(temp_v0 + 0x134), *(f32 *)(temp_v0 + 0x138),
                  temp_v0 + 0xB0, arg1, 0, 0, 0, -1, 0, 0);
    func_150636A4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150636A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150636F0.s")

extern s16 D_800CC2B2;
s16 func_15063390(struct struct127 *arg0);

s16 func_150639BC(struct struct127 *arg0) {
    D_800CC2B2 = (arg0->unk7A - arg0->unk31C->unk12) - func_15063390(arg0);
    if (D_800CC2B2 > 0x3E80) {
        D_800CC2B2 = 0x3E80;
    }
    if (D_800CC2B2 < -0x3E80) {
        D_800CC2B2 = -0x3E80;
    }
    return D_800CC2B2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150641D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150642AC.s")

void func_150649A0(s32 arg0, s32 arg1) {
    struct197 *a = gObjects[arg1].unk2D0;
    struct197 *b = gObjects[arg0].unk2D0;

    if ((a != NULL) && (b != NULL)) {
        a->unk8 = b->unk8;
        if (a->unk18 <= a->unk8) {
            a->unk8 = a->unk18 - 1.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15064A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15064B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15065A5C.s")
