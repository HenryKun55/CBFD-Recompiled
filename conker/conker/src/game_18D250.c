#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_1515FDA0.s")

struct func_1515FF74_s {
    u8 pad[0xE];
    u8 unkE[8];
};

struct func_1515FF74_s *func_1515FF74(void *arg0, s32 arg1, u8 arg2, s32 arg3) {
    struct func_1515FF74_s *ret = func_15167A68(0x34, arg3, arg1 + 0x18, 1, arg2, 1);
    if (ret == 0) {
        return NULL;
    }
    memcpy(&ret->unkE, arg0, 8);
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_1515FFEC.s")

extern void (*D_8008B0E4[])(void *, s32, u8);

void func_15160090(u8 *arg0, s32 arg1, u8 arg2) {
    void (*fn)(void *, s32, u8) = D_8008B0E4[arg0[0x14]];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_151600D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_15160274.s")
