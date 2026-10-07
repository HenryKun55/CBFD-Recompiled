#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512A390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512ABF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512AD54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B1B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B53C.s")

struct func_1512B5FC_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3;
    s32 unk4;
    s32 unk8;
};

void func_1512B5FC(struct func_1512B5FC_s *arg0, s32 arg1, s32 arg2) {
    arg0->unk2 = arg0->unk1;
    if (arg0->unk4 < arg1) {
        arg0->unk1 = 0;
    } else {
        arg0->unk1 = 1;
    }
    arg0->unk8 = arg2;
    arg0->unk4 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512BB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C150.s")

void func_1512C200(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C47C.s")
