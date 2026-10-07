#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_8009FBC0[];
void func_1514C858(f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, f32, s32, s32);
void func_151D3FF4();

void func_150B3AB0(u8 *arg0, volatile u8 arg1) {
    struct {
        f32 x;
        f32 y;
        f32 z;
        s16 pad;
        s16 rot;
    } pos;
    struct {
        u8 f0;
        s16 f2;
        u8 f4;
        u8 f5;
        s8 f6;
    } local;

    if (arg0 != NULL) {
        if (*(s32 *)(arg0 + 0x1D4) != 0) {
            func_1512D748(&D_800DBFF0[D_800BE9E8], 6, 1);
            pos.rot = (*(u16 *)(arg0 + 0x7A) >> 8) + 0x40;
            func_15143134(D_8009FBC0, &pos, *(s32 *)(arg0 + 0x1D4) + 0x640);
            func_1514C858(pos.x, pos.y, pos.z, 10.0f, pos.rot, 0, 0xFF, (u32) func_150ADA20() % 31 + 40, 8, 0, 0.0f, 0, arg1);
            local.f0 = 1;
            local.f2 = (func_150ADA20() & 0xF) + 12;
            local.f4 = (func_150ADA20() & 3) + 5;
            local.f6 = -1;
            local.f5 = 1;
            func_151D8868(&local, 0, arg1, 0);
            func_151D3FF4(&pos, arg1, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E0F60/func_150B3C0C.s")
