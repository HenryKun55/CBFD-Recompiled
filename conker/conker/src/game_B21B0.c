#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_8009D954[];
extern u8 *D_80087240[];

s32 func_15084D00(u8 *arg0) {
    s32 val = arg0[4];
    s32 i;
    s32 j;

    for (i = 0; i < 7; i++) {
        for (j = 0; j < D_8009D954[i]; j++) {
            if (val == D_80087240[i][j]) {
                return D_80087240[i][0];
            }
        }
    }
    return val;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_15084D70.s")

void func_15085410(u8 *arg0, s32 arg1) {
    (*(u8 **)(arg0 + 0x31C))[0x11B] = arg1;
}

struct func_15085420_s {
    u8 pad[0x11B];
    u8 unk11B;
};

u8 func_15085420(u8 *arg0) {
    return (*(struct func_15085420_s **)(arg0 + 0x31C))->unk11B;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_15085430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_15085710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_150859AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_15085ABC.s")
