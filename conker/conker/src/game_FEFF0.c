#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800A08E0;

void func_150D1B40(f32 *arg0) {
    f32 *sp28;

    sp28 = &arg0[10];
    func_151467A4(&arg0[12], 10.0f, &arg0[11], 86.0f, 170.0f, 255.0f, D_800A08E0, sp28);
    func_1515D4D4((s32)*sp28, ((u8 *)&D_800DCD20)[1], ((u8 *)&D_800DCD20)[2], 0);
}

void func_150D1BD0(s32 arg0) {
    if (func_1509BE40(1, 0x402C, 6, 0x2000)) {
        *(s32 *)(arg0 + 0x84) |= 0x10;
    } else {
        *(s32 *)(arg0 + 0x84) &= ~0x10;
    }
}
