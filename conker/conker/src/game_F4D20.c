#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C7870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C78E0.s")

void *func_151150BC();

struct func_150C7930_s {
    u8 pad[0x1E0];
    s32 unk1E0[0x10];
};

void func_150C7930(s32 *arg0) {
    s32 *p = ((struct func_150C7930_s *)D_800DBEF4)->unk1E0;
    arg0[0x3C / 4] = p[0x3C / 4] & 0xFFFF0000;
    func_151150BC();
}

void func_150C7968(u8 *arg0) {
    u8 *t;
    s16 *p;
    s16 v;

    func_15116110(arg0);
    if (!(arg0[0x73] & 4)) {
        t = *(u8 **)(arg0 + 0x7C);
        p = (s16 *)((u8 *)D_800DBEF4 + 0x1E0);
        v = p[0x1E];
        if (t != NULL) {
            t[0x13] = v >> 4;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C79BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C7C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C7D7C.s")
