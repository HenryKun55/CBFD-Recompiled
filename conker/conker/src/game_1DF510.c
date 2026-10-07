#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2100.s")

void func_151B222C();

void func_151B220C(void) {
    func_151B222C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B222C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B229C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B22C8.s")

struct func_151B22F4_s {
    u8 pad0[0x5C];
    s32 unk5C;
    u8 pad60[5];
    u8 unk65;
};

s32 func_151B22F4(struct127 **arg0) {
    struct127 *obj = arg0[10];
    struct func_151B22F4_s *p = (struct func_151B22F4_s *)arg0[12];
    s32 ret = 2;
    if ((p->unk65 == (obj - gObjects) + 1) && (p->unk5C == 1)) {
        return 1;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2690.s")

struct func_151B2950_s {
    u8 pad[0x178];
    s32 *unk178;
    u8 unk17C;
};

void func_151B2950(struct func_151B2950_s *arg0) {
    if (arg0->unk178 != NULL) {
        arg0->unk178[arg0->unk17C + 14] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2974.s")

void func_151B2EC4(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2F04.s")

void func_151B47D8(void *, void *, s32, u8);

void func_151B2FA0(u8 *arg0, s32 arg1, u8 arg2) {
    func_151B47D8(arg0, arg0 + 0x150, arg1, arg2);
}

struct func_151B2FD0_s {
    u8 pad0[0x44];
    s32 unk44;
    u8 pad48[0x4];
    struct func_151B2FD0_s *unk4C;
};
void func_151B2FD0(struct func_151B2FD0_s *arg0) {
    if (arg0->unk4C != NULL) {
        arg0->unk4C->unk44 = 0;
    }
}

void func_151B2FE8(s32 arg0) {
    func_151B2FD0(arg0);
    func_1514933C(arg0);
}

void func_151B3014(s32 arg0) {
    func_151B2FD0(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B3040.s")
