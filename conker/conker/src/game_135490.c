#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_1509BE40(s32, s32, s32, s32);
void func_15123070(struct108 *arg0);

void func_15107FE0(struct108 *arg0) {
    if (func_150859AC(arg0->unk3D0->unk127, 1) == 9) {
        func_151239CC(arg0, 2);
        if (func_15123934(arg0, 8, 0, arg0->unk134, 3)) {
            arg0->unk73C = 0;
            arg0->unk84 |= 0x1300000;
            arg0->unk84 &= ~4;
            func_15123070(arg0);
        }
        arg0->unk348 = 150.0f;
        arg0->unk34C = 150.0f;
        arg0->unk374 = 340.0f;
        arg0->unk190 = -6.0f;
        arg0->unk5F0 |= 0x800;
    } else {
        arg0->unk5F0 &= ~0x800;
    }
    if (func_1509BE40(1, 0x401A, 6, 0x9000) || func_1509BE40(1, 0x401B, 6, 0x9000)) {
        arg0->unk84 |= 0x10000;
    } else {
        arg0->unk84 &= ~0x10000;
    }
}
