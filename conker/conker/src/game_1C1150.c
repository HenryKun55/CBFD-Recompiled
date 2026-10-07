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

void func_15182670(s32, s32, s32, s32, s32, s32, s32, s32);
void func_15194BF0(s32, s32, u8 *);

void func_15194EA8(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp37 = 0;
    s32 pad;
    s32 sp2C[1];

    if (*(s32 *)(arg1 + 0x318) != 0) {
        sp2C[0] = func_150ADA20();
        func_15182670(0xFF, 0xFF, 0xFF, 0xFF, (func_150ADA20() % 11U) + 0x23,
                      *(u8 *)(*(s32 *)(arg1 + 0x318) + 0x23D), 0xFF, 1);
    }
    func_15194BF0(arg0, arg1, &sp37);
}

void func_151C0098(f32 *, void *, s32, s32, s32);
void func_15136C3C(void *, s32, s32, s32, s32, s32, s32, s32);
void func_1507CD64(void *, s32);

void func_15194F48(s32 arg0, f32 *arg1, s32 arg2) {
    f32 sp34[3];

    sp34[0] = arg1[5];
    sp34[1] = arg1[6] + 50.0f;
    sp34[2] = arg1[7];
    func_151C0098(sp34, arg1, 1, 0xFF, 1);
    func_15136C3C(arg1, 0, 0, 1, 0, 0, 0xFF, 1);
    func_15145A50(arg1);
    func_1507CD64(arg1, 6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151951E0.s")

extern f32 D_800A8708;
void func_1514373C(f32, f32, f32 *, f32 *);
void func_15137610(void *, f32 *, f32 *, f32 *, s32, s32);

void func_15195528(void *arg0, void *arg1, s32 arg2) {
    f32 ang;
    f32 a[3];
    f32 b[3];
    f32 dir[3];

    if (arg0 != NULL) {
        ang = *(f32 *)((char *)arg0 + 0x40) - 90.0f;
    } else if (arg1 != NULL) {
        ang = *(f32 *)((char *)arg1 + 0x40) - 90.0f;
    } else {
        ang = func_150ADA68() * 360.0f;
    }
    func_1514373C(ang * D_800A8708, 1.0f, &dir[0], &dir[2]);
    dir[1] = 0.0f;
    a[0] = dir[0] * 20.0f + *(f32 *)((char *)arg1 + 0x14);
    a[1] = *(f32 *)((char *)arg1 + 0x18) + 50.0f;
    a[2] = dir[2] * 20.0f + *(f32 *)((char *)arg1 + 0x1C);
    b[0] = *(f32 *)((char *)arg1 + 0x14) - dir[0] * 20.0f;
    b[1] = *(f32 *)((char *)arg1 + 0x18) + 50.0f;
    b[2] = *(f32 *)((char *)arg1 + 0x1C) - dir[2] * 20.0f;
    func_15137610(arg1, a, b, dir, 0xFF, 1);
}

void func_151B01B8();
s32 func_151B09BC();

void func_15195650(void *arg0, void *arg1, s32 arg2) {
    func_151B01B8(arg0, arg1);
    func_151B09BC(arg0, arg1, 0x3E8, 0xFF, 0);
}

void func_15136C3C();
void func_1507CD64();

void func_15195698(u8 *arg0, u8 *arg1, s32 arg2) {
    if (arg1[0x1CA] == 0) {
        if (arg1[0x127] != 0xFF) {
            func_15136C3C(arg1, 1, 1, 1, 1, 0, 0xFF, 1);
            func_15145A50(arg1);
            func_1507CD64(arg1, 6);
        }
    }
    if (arg0[4] == 0x47) {
        arg0[0x1CA] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195738.s")
