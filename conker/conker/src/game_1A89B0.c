#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517B500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517B6E8.s")

s32 func_1517B7A8(s16 *arg0, s16 *arg1, s32 *arg2, s32 arg3) {
    if (*arg2 >= 0x300) {
        if (*arg2 > 0x500) {
            *arg2 -= 0x200;
        } else {
            *arg2 = 0x300;
        }
    }
    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517B7F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517B89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517BBAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517CFC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D074.s")

struct func_1517D578_s {
    s16 x;
    s16 y;
    s16 z;
    u8 unk6;
    s16 unk8;
    s16 unkA;
    f32 unkC;
};
extern struct func_1517D578_s D_800DDD28[];

void func_1517D578(s16 arg0, s16 arg1, s16 arg2, f32 arg3, s32 arg4, s32 arg5, u8 arg6) {
    s32 n;
    struct func_1517D578_s *temp_v1;

    n = D_8008CEB0;
    if (n < 3) {
        temp_v1 = &D_800DDD28[n];
        temp_v1->x = arg0;
        temp_v1->y = arg1;
        temp_v1->z = arg2;
        temp_v1->unkC = arg3;
        temp_v1->unk8 = arg4;
        temp_v1->unkA = arg5;
        temp_v1->unk6 = arg6;
        D_8008CEB0 = n + 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D5FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517DE5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517E05C.s")
