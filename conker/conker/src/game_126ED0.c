#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150F9A20_s {
    u8 pad0[0x84];
    s32 unk84;
    u8 pad88[0x190 - 0x88];
    f32 unk190;
};

void func_150F9A20(struct func_150F9A20_s *arg0) {
    if (func_1509BE40(1, 0x4025, 6, 0x2000) != 0) {
        arg0->unk84 |= 0x80;
        arg0->unk84 &= ~8;
        arg0->unk190 = 85.0f;
    } else {
        arg0->unk84 &= ~0x80;
        arg0->unk84 |= 8;
        arg0->unk190 = 0.0f;
    }
}
