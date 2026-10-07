#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503DE70.s")

void func_1503DF0C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct106 *ptr = &D_800C6660[arg0];

    ptr->unk4 |= arg2;
    ptr->unk8 |= arg3;
    ptr->pad[2] = arg1;
    ptr->unkF = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503DF48.s")

s32 func_1503E1F4(s32 arg0, s32 arg1) {
    if (arg0 < 32) {
        if (D_800C6660[arg1].unk4 & (1 << arg0)) {
            return 1;
        }
    } else {
        if (D_800C6660[arg1].unk8 & (1 << arg0)) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E3C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EA54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EB78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503ECA0.s")

void func_1503EEB8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EFC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F078.s")

void func_1503EB78(s32 arg0, f32 arg1, f32 arg2, s32 arg3);

void func_1503F0AC(s32 arg0, s32 arg1) {
    func_1503EB78(arg0, 1.0f, 2.0f, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F0D8.s")

struct func_1503F108_s {
    u8 *unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
};
struct func_1503F108_s2 {
    s32 unk0;
    u8 pad[0x328];
};
extern struct func_1503F108_s2 D_800CC364[];

void func_1503F108(s32 arg0) {
    struct func_1503F108_s *p = &((struct func_1503F108_s *)D_800C6660)[arg0];
    p->unkC = 0x8C;
    D_800CC364[arg0].unk0 = 6;
    *(f32 *)(p->unk0 + 0x1EC) = 10.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F16C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F404.s")
