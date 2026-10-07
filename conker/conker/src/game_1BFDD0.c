#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15192920_s {
    void *unk0;
    u8 unk4;
    f32 unk8;
};

void func_15192920(void *arg0) {
    struct260 *temp_v0;

    if ((s32)arg0 != 0) {
        struct func_15192920_s sp28;
        sp28.unk0 = (void *)arg0;
        sp28.unk4 = *((u8 *)arg0 + 0x3B);
        sp28.unk8 = 0.0f;
        temp_v0 = func_151491F4(0x23, -1, 0x14, 1, 0x10, (struct37 *)0xC, 0xFF, 1);
        if (temp_v0 != NULL) {
            memcpy((u8 *)temp_v0 + 0x28, &sp28, 0xC);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BFDD0/func_151929A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BFDD0/func_15192D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BFDD0/func_15192DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BFDD0/func_15193234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BFDD0/func_151932E0.s")
