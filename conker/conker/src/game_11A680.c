#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 func_15144BC8(f32);

f32 func_150ED1D0(f32 arg0, f32 arg1) {
    f32 d;

    arg0 = func_15144BC8(arg0);
    d = func_15144BC8(func_15144BC8(arg1) - arg0);
    if (d > 180.0f) {
        d = -360.0f + d;
    }
    return d;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150EEC84.s")

struct func_150EEDA8_s {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[0xE4 - 6];
    s16 unkE4;
    u8 padE6[0x125 - 0xE6];
    u8 unk125;
};
void func_151045E0(struct func_150EEDA8_s *arg0, s32 arg1, f32 arg2);
void *func_15052590();

void func_150EEDA8(struct func_150EEDA8_s *arg0) {
    if (arg0->unk5 != 3) {
        func_151045E0(arg0, 0xF, 250.0f);
        arg0->unk5 = 3;
        arg0->unkE4 = 0;
        arg0->unk125 = 0xFF;
    }
    func_15052590(arg0);
}
