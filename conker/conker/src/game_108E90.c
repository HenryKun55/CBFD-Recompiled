#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DB9E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DBC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DBD70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DC558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DCEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DD640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DDED0.s")

struct func_150DDF88_s {
    u8 pad[0x28];
    u8 unk28;
};

void func_150DBD70(u8 arg0, struct func_150DDF88_s *arg1);

void func_150DDF88(struct func_150DDF88_s *arg0) {
    func_150DBD70(arg0->unk28, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DDFAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DE12C.s")

struct func_150DE2A4_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_150DE2A4(struct func_150DE2A4_s *arg0) {
    if (arg0->unk1C < 0x20) {
        arg0->unk28 = arg0->unk1C * 8;
    }
    return 1;
}

struct func_150DE2C4_s {
    u8 pad0[0x34];
    s16 unk34;
    s16 unk36;
    s16 unk38;
};

void func_150DE2C4(struct func_150DE2C4_s *arg0) {
    arg0->unk34 -= 26;
    arg0->unk36 -= 26;
    if (arg0->unk34 < 10 || arg0->unk36 < 10) {
        arg0->unk38 = 0;
    }
}
