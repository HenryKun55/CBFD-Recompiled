#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15104170_s {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    s16 unk18;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
};
extern struct func_15104170_s *func_15167A68(s32, s32, s32, s32, s32, s32);

void func_15104170(s32 arg0, s32 arg1, s32 arg2) {
    struct func_15104170_s *v0 = func_15167A68(0x64, 0, 0x20, 0, 0xFF, 1);
    if (v0 != NULL) {
        v0->unk18 = 0xF;
        v0->unk1A = 0;
        v0->unk1B = 0;
        v0->unk10 = arg1;
        v0->unk14 = arg2;
        v0->unk1C = arg0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_131620/func_151041E4.s")

s32 func_1517F08C();

s32 func_1510448C(s32 arg0, u8 *arg1, s16 arg2) {
    s32 v;
    u8 **pp = &arg1;
    if (arg2 != 0 || (v = (*pp)[0x1B]) == 0) {
        return arg0;
    }
    return func_1517F08C(arg0, (v * 0x3F) >> 8, 0, 0, 0, arg2);
}

extern void *D_800CC5EC;

u8 func_151044F4(void) {
    if (D_800CC5EC != NULL) {
        return *((u8 *)D_800CC5EC + 0x7D);
    }
    return 0;
}
