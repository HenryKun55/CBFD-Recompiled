#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150D0650(struct108 *arg0) {
    if ((D_800D2E4C->unk0 & 0x80) == 0) {
        if (func_1509BE40(0, 0x2000, 0xBB) != -1) {
            if (func_15123934(arg0, arg0->unk2C, 0, arg0->unk134, 8) != 0) {
                arg0->unk84 |= 0x1000000;
                func_151254F4(arg0, D_800CC335 - 1);
                arg0->unk190 = 100.0f;
            }
        } else if (func_151239CC(arg0, 8) != 0) {
            func_151254F4(arg0, 0);
            arg0->unk190 = 0.0f;
        }
    }
}
