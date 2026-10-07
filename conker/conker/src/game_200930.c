#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3D50.s")

struct func_151D3E04_s {
    u8 pad0[0x14];
    f32 x;
    f32 y;
    f32 z;
    u8 pad20[0x1D4 - 0x20];
    u8 *unk1D4;
};

void func_151D3E04(struct func_151D3E04_s *arg0, f32 *arg1, s32 arg2, u8 arg3, f32 arg4) {
    if (arg0->unk1D4 != NULL) {
        func_15143134(arg2, arg1, arg0->unk1D4 + (arg3 << 6));
    } else {
        arg1[0] = arg0->x;
        arg1[1] = arg0->y + arg4;
        arg1[2] = arg0->z;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D40D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D42E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4408.s")

struct func_151D4668_s {
    void *ptr;
    u8 val;
};

void func_151D4668(void *arg0) {
    struct func_151D4668_s sp18;

    sp18.ptr = arg0;
    sp18.val = *((u8 *)arg0 + 0x3B);
    func_151494E0(&sp18, 0x3C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D469C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4C38.s")

struct func_151D4D04_s {
    u8 pad0[0x58];
    u8 unk58[0x50];
    s16 unkA8;
    s16 unkAA;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
};

void func_15131828(struct func_151D4D04_s *, s32 *, s16 *, s16 *);
void func_15131958(u8 *, s32);

s32 func_151D4D04(struct func_151D4D04_s *arg0, s32 arg1) {
    s16 *temp = &arg0->unkA8;
    func_15131828(arg0, &arg0->unkAC, temp, &arg0->unkAA);
    func_15131958(arg0->unk58, ((s32 *)temp)[3]);
    return 1;
}

void func_151D4D58(s32 arg0) {
    func_151D469C(arg0, 0, 0x50, 0xFF, 1);
    func_151D469C(arg0, 1, 0x50, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4DAC.s")

struct func_151D5148_s {
    u8  pad0[0x24];
    s16 unk24;
    u8  pad26[0x1AA - 0x26];
    s16 unk1AA;
};

void func_151D5148(struct127 *arg0) {
    if (((struct func_151D5148_s *)arg0->unk31C)->unk24 > 0) {
        ((struct func_151D5148_s *)arg0->unk31C)->unk24--;
    }
    arg0->unk31C->unk1AA++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D57F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5D60.s")

void func_151D5E30(s32 *arg0) {
    u8 i;

    for (i = 0; i < 4; i++) {
        if (arg0[i] != 0) {
            func_100043B4(arg0[i], 3);
        }
    }
}
