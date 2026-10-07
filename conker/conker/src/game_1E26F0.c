#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800AA418;

struct func_151B5240_s {
    u8 pad0[0x580];
    struct127 *unk580;
    u8 unk584;
    struct127 *unk588;
    u8 unk58C;
    f32 unk590;
    f32 unk594;
    f32 unk598;
    f32 unk59C;
    f32 unk5A0;
    s32 unk5A4;
    s32 unk5A8;
};

struct260 *func_151B5240(s16 arg0, u8 arg1, s32 arg2) {
    struct260 *temp_v0;
    struct func_151B5240_s sp30;

    sp30.unk584 = 0x17;
    sp30.unk58C = 0x16;
    sp30.unk580 = func_15083E90(0x17);
    sp30.unk588 = func_15083E90(sp30.unk58C);
    sp30.unk598 = 250.0f;
    sp30.unk590 = 18.0f;
    sp30.unk594 = 0.0f;
    sp30.unk5A0 = D_800AA418;
    sp30.unk59C = 1.0f / sp30.unk598;
    temp_v0 = func_15149130(arg0, -1, -1, 1, 1, 0x15, (struct37 *)0x5A8, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp30, 0x5A8);
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E26F0/func_151B5328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E26F0/func_151B5A9C.s")
