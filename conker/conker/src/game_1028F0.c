#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150D5440_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
};

void func_150D5440(u8 *arg0, u8 arg1, s32 arg2) {
    struct func_150D5440_s tmp;
    struct260 *temp_v0;

    tmp.unk0 = arg0;
    tmp.unk4 = arg0[0x3B];
    tmp.unk8 = 0.0f;
    temp_v0 = func_15149130(0x12C, -1, 0x38, -1, 0, 0x28, 0xC, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, &tmp, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D54C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D596C.s")

void func_150D5A2C(s32 arg0) {
    func_1514933C(arg0);
}

void func_150D5A4C(void) {
    func_15149368();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D5A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D64E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D65F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D66A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6730.s")

void func_150D6C98(f32 *arg0, f32 *arg1) {
    arg1[0] = arg0[5];
    arg1[1] = arg0[6] + 60.0f;
    arg1[2] = arg0[7];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D7068.s")
