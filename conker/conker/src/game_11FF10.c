#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F2A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F2C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F2D14.s")

void func_150F3194(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

void func_150F31D4(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x110, arg0 + 0x114, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F3214.s")

void func_15140410();

void func_150F337C(u8 *arg0, s16 arg1) {
    func_15140410(arg0, arg0 + 0x12C, arg0 + 0x138, arg1);
}

struct func_150F33B0_s {
    u8 pad0[0x4F];
    u8 unk4F_pad : 7;
    u8 unk4F_0 : 1;
};

void func_150F33B0(struct func_150F33B0_s *arg0) {
    if (D_800DBFF0->unk300 < -2000.0f) {
        arg0->unk4F_0 = 0;
        return;
    }
    arg0->unk4F_0 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F33F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F34A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F34F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F43F0.s")
