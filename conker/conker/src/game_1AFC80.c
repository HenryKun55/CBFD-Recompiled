#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1AFC80/func_151827D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AFC80/func_15182C5C.s")

struct func_15182F58_s {
    f32 unk0;
    u8 pad4[0x14];
};
extern struct func_15182F58_s D_8008D058[];
extern u8 D_800DDE54[];

f32 func_15182F58(s32 arg0, s32 arg1) {
    f32 var_f2;

    var_f2 = D_8008D058[D_800DDE54[arg1]].unk0 * (f32)(arg0 * 40);
    if (var_f2 < 0.0f) {
        var_f2 = 0.0f;
    } else if (39.0f < var_f2) {
        var_f2 = 39.0f;
    }
    return var_f2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AFC80/func_15182FDC.s")
