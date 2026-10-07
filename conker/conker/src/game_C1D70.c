#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_150948C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_1509499C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15094AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15094EA0.s")

extern Gfx D_800873D0[];
extern s32 D_800D2CA0;

Gfx *func_15094F40(Gfx *gdl) {
    gSPDisplayList(gdl++, D_800873D0);
    D_800D2CA0 = 0;
    return gdl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15094F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15094FE8.s")

struct func_15095060_s {
    u32 unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
};
struct func_15095060_src {
    u32 unk0;
    u8 unk4;
    u8 pad5;
    u16 unk6;
    u16 unk8;
    u8 unkA;
    u8 unkB;
};
extern struct func_15095060_s D_800D2C90;

void func_15095060(struct func_15095060_src *arg0, s32 arg1, void *arg2) {
    u32 temp_v0;

    if (arg2 != NULL) {
        *(struct func_15095060_s **)((char *)arg2 + 0x10) = &D_800D2C90;
    }
    temp_v0 = arg0->unk0;
    if (temp_v0 < 0x10000000U) {
        D_800D2C90.unk0 = temp_v0;
    } else {
        D_800D2C90.unk0 = ((u32 *)temp_v0)[arg1 >> 8];
    }
    D_800D2C90.unk4 = arg0->unk6;
    D_800D2C90.unk6 = arg0->unk8;
    D_800D2C90.unk8 = arg0->unkA;
    D_800D2C90.unk9 = arg0->unkB;
    D_800D2C90.unkA = arg0->unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_150950D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_1509563C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_150958B0.s")

void func_15095A90(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);

void func_15095A48(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    func_15095A90(arg0, arg1, arg2, arg3, 4096.0f, 0, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095B08.s")

void *func_15095D34(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);

void func_15095D0C(void *arg0, void *arg1) {
    func_15095D34(arg0, arg1, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_1509629C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15096934.s")
