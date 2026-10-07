#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15193CA0.s")

void func_151942B0(s32 arg0, s32 arg1, s32 arg2) {
    func_15193CA0(arg1, 0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151942E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194408.s")

void func_150C7020(s32, s32, s32, s32);
void func_15194408(s32, s32);

void func_15194588(s32 arg0, s32 arg1, s32 arg2) {
    func_150C7020(arg0, 500, 0xFF, 1);
    func_15194408(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151945CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194810.s")

void func_151949E0(s32 arg0, s32 arg1, s32 arg2) {
}

void func_15104170(s32, u8 *, s32);

void func_151949F4(s32 arg0, u8 *arg1, s32 arg2) {
    if (D_8008FD90 == 1) {
        if (arg1[0x127] == 0) {
            if (D_800E9D00 & 8) {
                if (*(u16 *)(*(u8 **)(arg1 + 0x31C) + 0x1A0) == 0) {
                    func_15104170(arg0, arg1, arg2);
                    *(u16 *)(*(u8 **)(arg1 + 0x31C) + 0x1A0) = 0x4B0;
                }
            }
        }
    }
}

void func_15194A68(s32 arg0, s32 arg1, s32 arg2) {
    func_1507DE4C(arg1);
    func_15138BC0(arg1, 0xFF, 1);
    func_151949F4(0, arg0, arg1);
}

struct func_15194AB4_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x9C - 5];
    s32 unk9C;
};

void func_15194AB4(struct func_15194AB4_s *arg0) {
    s32 var_a1;

    arg0->unk9C |= 0xFFFE;
    var_a1 = -1;
    switch (arg0->unk4) {
    case 0x75:
        var_a1 = 0x73;
        break;
    case 0x80:
        var_a1 = 0x72;
        break;
    }
    if (var_a1 != -1) {
        func_15083568(arg0, var_a1, 0x3F800000, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194BF0.s")

void func_15194FF4(s32 arg0, s32 arg1, s32 arg2);

void func_15194D80(s32 arg0, s32 arg1, s32 arg2) {
    func_15194FF4(arg0, arg1, 0);
}

void func_15194DA4(s32 arg0, s32 arg1, s32 arg2) {
    func_15194FF4(arg0, arg1, 1);
}

extern s32 D_800A8244;
void func_1518D1C0(s32, s32, s32, s32, s32, s32, void *);
void func_1514B364(s32, void *, s32, s32);

void func_15194DC8(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp2C[0x24];

    if (D_800BE616) {
        func_15194DA4(arg0, arg1, arg2);
    } else {
        func_1518D1C0(arg1, 0xB, 0, 1, 0xFF, 1, &D_800A8244);
    }
    func_1504715C(sp2C, arg1);
    func_1514B364(arg1 + 0x14, sp2C, 0xFF, 1);
}

void func_150B06B0(void *arg0, void *arg1, s32 arg2, s32 arg3);

void func_15194E54(void *arg0, u8 *arg1, s32 arg2) {
    if ((arg1[4] == 0x3E) || (arg1[4] == 0xA6)) {
        func_150B06B0(arg1, arg0, 0xFF, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151951E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195528.s")

void func_151B01B8();
s32 func_151B09BC();

void func_15195650(void *arg0, void *arg1, s32 arg2) {
    func_151B01B8(arg0, arg1);
    func_151B09BC(arg0, arg1, 0x3E8, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195738.s")
