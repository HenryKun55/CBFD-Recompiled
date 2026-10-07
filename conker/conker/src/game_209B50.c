#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_209B50/func_151DC6A0.s")

struct func_151DC8BC_v {
    f32 x, y, z;
};

struct func_151DC8BC_s {
    struct func_151DC8BC_v pos;
    f32 unkC;
    u8 unk10;
};

void func_151DC6A0(struct func_151DC8BC_v *arg0, u8 arg1, s32 arg2);

void func_151DC8BC(struct func_151DC8BC_v *arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5) {
    struct func_151DC8BC_s sp34;
    struct260 *temp_v0;

    if (arg2) {
        func_151DC6A0(arg0, arg4, arg5);
    }
    sp34.pos = *arg0;
    sp34.unkC = 0.0f;
    sp34.unk10 = arg3;
    temp_v0 = func_15149130(arg1, -1, 0x5B, -1, 1, 0, (struct37 *)0x14, arg4, arg5);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp34, 0x14);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_209B50/func_151DC97C.s")
