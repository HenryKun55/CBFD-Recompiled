#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern OSTimer D_800BE6E0;

void func_1501BB20(void) {
    if (D_80084064) {
        osSetTimer(&D_800BE6E0, (25 * D_8002BD10) / 1000000ULL, 0, &D_8003B218, (OSMesg)6);
        D_80084064 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501BBB8.s")

extern f32 D_80096960;
void func_1501C0F0(u8, f32, f32);

void func_1501C010(u8 arg0, u8 arg1) {
    f32 a;
    f32 b;
    f32 t;

    if (arg1 > 8) {
        arg1 = 8;
    }
    if (arg1 == 8) {
        a = 20.0f;
        b = 0.0f;
    } else if (arg1 == 0) {
        a = 0.0f;
        b = 99.0f;
    } else {
        t = (arg1 - 1.0f) * D_80096960 * 5.0f;
        a = t + 2.0f;
        b = 7.0f - t;
    }
    func_1501C0F0(arg0, a, b);
}

extern u8 D_80084060[];

void func_1501C0F0(u8 arg0, f32 arg1, f32 arg2) {
    s32 idx = D_80084060[arg0];
    if (idx < 4) {
        if (D_800BE944[idx] != 0) {
            D_800BE93C[idx] = 1;
            D_800BE950[idx] = 0.0f;
            D_800BE960[idx] = arg1;
            D_800BE970[idx] = arg2;
            D_800BE980[idx] = arg1 + arg2;
        }
    }
}

extern u8 D_80084060[];

void func_1501C17C(u8 arg0) {
    s32 idx = D_80084060[arg0];
    if (idx < 4) {
        D_800BE93C[idx] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C1B0.s")

void func_1501C17C(u8);
void func_1501C53C(void) {
    u8 i;
    for (i = 0; i < 4; i++) {
        func_1501C17C(i);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C57C.s")
