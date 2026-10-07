#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_1509BE40(s32, ...);

struct func_150C7350_s {
    u8 pad0[0x84];
    s32 unk84;
};

void func_150C7350(struct func_150C7350_s *arg0) {
    arg0->unk84 |= 0x80004000;
    if (func_1509BE40(3, 0x2000, 0xAC, 0x4002, 0x4003, 0x4004) != 0) {
        arg0->unk84 |= 0x400000;
    } else {
        arg0->unk84 &= ~0x400000;
    }
}
