#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F6E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F8F8.s")

s32 func_15146078(void *arg0, f32 *arg1, f32 *arg2);
void func_1514F8F8(void *arg0, void *arg1, f32 *arg2, f32 *arg3, f32 arg4, u8 arg5, s32 arg6);

void func_1514FB98(f32 *arg0, u8 arg1, s32 arg2) {
    f32 sp34[3];
    f32 sp28[3];

    if (func_15146078(arg0, sp34, sp28) != 0) {
        func_1514F8F8(arg0 + 4, arg0, sp34, sp28, arg0[3], arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FBFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FCE8.s")

struct func_1514FEFC_s {
    u8 pad[0x2C];
};

void func_1514F640();
void func_1514FF44();

void func_1514FEFC(s32 arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    struct func_1514FEFC_s sp24;

    func_1514F640(arg0, &sp24);
    func_1514FF44(&sp24, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FF44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515080C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151511FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152ABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151539B4.s")

void func_15153C84(void *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    s32 sp24[11];
    func_1514F640(arg0, sp24);
    func_15153CCC(sp24, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151541B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515452C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515548C.s")

extern void (*D_8008AD04[])(void *, s32, u8);

void func_15155564(void *arg0, s32 arg1, u8 arg2) {
    void (*func)(void *, s32, u8) = D_8008AD04[*((u8 *)arg0 + 0x2A)];
    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151555AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515572C.s")
