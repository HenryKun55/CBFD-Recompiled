#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151BFC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151BFDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151BFE84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C0098.s")

s32 func_151C02E4(s32 *arg0, s32 *arg1, s32 arg2, s32 **arg3) {
    u8 i;

    for (i = 0; i < arg2; i++) {
        if (arg0 == arg3[i]) {
            return 0;
        }
    }
    if (arg0 == arg1) {
        return 0;
    }
    if (*arg0 == 0) {
        return 0;
    }
    if (((u8 *)arg0)[4] == 0xFF) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C0360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C0418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C04F8.s")

void func_151D5334(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_151C05A4(void *arg0, u8 arg1, s32 arg2) {
    func_151D5334(arg0, 800.0f, 2000.0f, 0.0005f, 5, arg1, arg2);
}

void func_151C05F0(void *arg0, u8 arg1, s32 arg2) {
    func_151D5404(arg0, 800.0f, 2000.0f, 0.0005f, 0xF, 0x14, arg1, arg2);
}

void func_150E83AC(s32 arg0, s16 arg1, u8 arg2, s32 arg3);

void func_151C0644(s32 arg0, u8 arg1, s32 arg2) {
    func_150E83AC(arg0, (func_150ADA20() % 62U) + 120, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C0698.s")

struct func_151C110C_s {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 pad8[0x10];
    f32 *unk18;
};

s32 func_151C110C(struct func_151C110C_s *arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, s16 *arg6) {
    f32 *tmp = arg0->unk18;

    if (tmp != NULL && *arg2 != 0) {
        arg0->unk2 = tmp[14];
        arg0->unk4 = tmp[15];
        arg0->unk6 = tmp[16];
        return 0;
    }
    *arg6 = 0;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1570.s")

void func_151C15FC(s32 arg0) {
    func_151C1570(arg0);
    func_15132570(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1654.s")

extern u8 D_800AA954[];
extern u8 D_800AA958[][12];

struct func_151C1798_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x1D4 - 5];
    s32 unk1D4;
};

void func_151C1798(struct func_151C1798_s *arg0, s32 arg1) {
    s32 idx;

    switch (arg0->unk4) {
    case 0x77:
        idx = 1;
        break;
    case 0x28:
        idx = 2;
        break;
    default:
        idx = 0;
        break;
    }
    func_15143134(D_800AA958[idx], arg1, arg0->unk1D4 + (D_800AA954[idx] << 6));
}

void func_151C1814(void *arg0, s32 *arg1, u8 arg2) {
    s32 *ptr = (s32 *)((u8 *)arg0 + 0x170);

    if (arg2 == 0x2D) {
        if (arg1[0] == ptr[0x6C / 4]) {
            ptr[0x6C / 4] = arg1[1];
        } else if (arg1[1] == ptr[0x6C / 4]) {
            ptr[0x6C / 4] = arg1[0];
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1860.s")

void func_151C1940(s32 arg0, s32 arg1, s32 *arg2) {
    func_151C02E4(arg0, arg1, *arg2, arg2 + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C196C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1FB8.s")
