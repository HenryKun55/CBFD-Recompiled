#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150C7770_s {
    char pad0[0x84];
    s32 unk84;
};

void func_150C7770(struct func_150C7770_s *arg0) {
    if (func_1509BE40(3, 0x2000, 0xAC, 0x401B, 0x401C, 0x401D) != 0) {
        func_1509BFB0(1, 0x2000, 0x3B, 2);
    }
    if (func_1509BE40(1, 0x4006, 6, 0x2000) != 0) {
        arg0->unk84 |= 0x400000;
    } else {
        arg0->unk84 &= ~0x400000;
    }
    arg0->unk84 |= 0x400000;
    if (func_1509BE40(1, 0x4030, 6, 0x2000) != 0) {
        arg0->unk84 |= 0x1000000;
    } else {
        arg0->unk84 &= ~0x1000000;
    }
}
