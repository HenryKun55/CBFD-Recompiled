#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_15142314(s32, s32, f32 *);
s32 func_15046C80(f32 *, s32, f32, s32);

s32 func_150EAF50(f32 *arg0, s32 arg1, s32 arg2, u8 arg3) {
    f32 sp2C[3];

    switch (arg3) {
    case 1:
    case 2:
        break;
    default:
        return 0;
    }
    func_15142314(*(s32 *)(arg1 + 0x1D4), (arg3 == 1) ? 0x21 : 0x1D, arg0);
    if (arg2 == 0) {
        return 1;
    }
    sp2C[0] = arg0[0];
    sp2C[1] = arg0[1] + 10.0f;
    sp2C[2] = arg0[2];
    func_1504715C(arg2, arg1);
    return func_15046C80(sp2C, 0, arg0[1] - 50.0f, arg2);
}

s32 func_150EB030(s32 arg0, s32 arg1) {
    if (arg0 == 1) {
        if (D_800BE9F0 == 4) {
            if (func_151420F8(arg1)) {
                return 6;
            } else {
                return 3;
            }
        } else {
            return -1;
        }
    }
    return -1;
}

extern f32 D_800A1470;
extern f32 D_800A1474;
void func_15141F78(s32, f32 *, f32, u8, f32 *, u8);

void func_150EB090(s32 arg0, s32 arg1, s32 arg2) {
    f32 sp4C[3];
    f32 sp28[9];

    if ((*(s32 *)(arg0 + 0x1D4) != 0) && (func_150EAF50(sp4C, arg0, (s32)sp28, arg1) != 0)) {
        func_15141F78(10, sp28, arg2 * D_800A1470, *(f32 *)(arg0 + 0x40) * D_800A1474, sp4C, arg1);
    }
}
