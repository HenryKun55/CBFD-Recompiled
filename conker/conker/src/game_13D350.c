#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_1510FEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151102CC.s")

void func_151102CC(s32, f32, f32, s32);
void func_150A7A48(s32, void *, s32);

void func_15110360(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    func_151102CC(arg1, arg2, arg3, arg4);
    func_150A7A48(arg1, (u8 *)D_800BE628 + arg0 * 0x180 + 0xBC, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151103C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15110544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15110600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151106A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151108C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15110CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_1511172C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15111858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15111AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15112520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15112A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151135C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151137D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113E54.s")

extern s32 *D_800DBF94;

s32 func_15114050(struct131 *arg0, s32 arg1) {
    if ((u8)arg0->unk4F & 0x80) {
        if (arg1 == -1) {
            return 1;
        }
        if (D_800DBF94[arg0 - D_800DBEF4] & (1 << arg1)) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151140C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_1511473C.s")

void func_151148A8(void *arg0, f32 *arg1) {
    f32 sp18[16];

    func_150A8050(arg0, 0.0f, arg1[1], 0.0f);
    func_150A8050(sp18, arg1[0], 0.0f, arg1[2]);
    func_150A7A48(sp18, arg0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_1511490C.s")

struct131 *func_151149AC(u8 arg0) {
    s32 i;

    if (arg0 == 0) {
        return NULL;
    }
    for (i = 0; i < D_800DBEF0; i++) {
        if (arg0 == D_800DBEF4[i].pad70[2]) {
            return &D_800DBEF4[i];
        }
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114A1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114D24.s")

void func_15114CC4();
void func_1001001C();

void func_15114F04(s32 arg0, s32 arg1, s32 arg2) {
    func_1001001C(func_15114CC4, arg0, 0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114F44.s")
