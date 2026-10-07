#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150F52B0_s {
    u8 pad[0x84];
    u32 unk84;
};

s32 func_1509BE40(s32, s32, s32, s32);

void func_150F52B0(struct func_150F52B0_s *arg0) {
    if (func_1509BE40(1, 0x401C, 6, 0x9000)) {
        arg0->unk84 |= 0x80000000;
    } else {
        arg0->unk84 &= 0x7FFFFFFF;
    }
}

void func_150F5310(s32 arg0) {
    func_151827D0();
}
