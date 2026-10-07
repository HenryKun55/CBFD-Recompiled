#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CD5A0/func_150A00F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CD5A0/func_150A019C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CD5A0/func_150A0264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CD5A0/func_150A02D0.s")

struct func_150A0374_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};
extern struct func_150A0374_s D_800D3014[];

s32 func_150A0374(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 3) {
        return D_800D3014[arg0].unk0;
    }
    return 0;
}
