#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C71A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C756C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C7E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C82D0.s")

void func_151C8674(s32 arg0, s32 arg1) {
    s32 sp18[2];

    if (arg0 != 0) {
        sp18[0] = arg0;
        sp18[1] = arg1;
        func_151403A8((s32)sp18, 32);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C86AC.s")

struct func_151C87AC_s {
    u8 pad0[0x18];
    u8 *unk18;
};

s32 func_151C87AC(struct func_151C87AC_s *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 *arg6) {
    u8 *temp_v0 = arg0->unk18;

    if (!(temp_v0[0x86] & 2)) {
        *arg6 = 0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C87E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C899C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C8FCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C94D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C95D8.s")

struct func_151C96DC_s {
    u8 pad0[0x170];
    u8 *unk170;
};

s32 func_151C96DC(struct func_151C96DC_s *arg0, s32 arg1) {
    u8 *temp = arg0->unk170 + 0x110;
    s32 ret = 0;

    if (temp[0x86] & 2) {
        return 1;
    }
    return ret;
}

struct func_151C970C_s {
    s32 unk0;
    s8 unk4;
};

void func_151C970C(s32 arg0, s32 arg1) {
    struct func_151C970C_s sp18;

    sp18.unk0 = arg1;
    sp18.unk4 = arg0;
    func_151403A8((s32)&sp18, 0x3A);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9AC0.s")

struct func_151C9B30_s {
    u8 pad0[0x14];
    u8 *unk14;
    u8 *unk18;
};

s32 func_151C9B30(struct func_151C9B30_s *arg0) {
    u8 *temp_v0 = arg0->unk18;

    if (temp_v0[0x6F] == 0) {
        arg0->unk14[9] = 0;
    } else {
        arg0->unk14[9] = 1;
    }
    return 1;
}

struct func_151C9B64_s {
    u8 pad0[0x58];
    s32 unk58;
    u8 pad5C[0x188 - 0x5C];
    u8 *unk188;
};

s32 func_151C9B64(struct func_151C9B64_s *arg0, u8 *arg1) {
    u8 *temp = arg0->unk188;

    if (temp[0x6F] == 0) {
        *arg1 = 1;
    } else {
        arg0->unk58 &= ~2;
        *arg1 = 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9DE8.s")

void func_15160274(s32 arg0, s32 arg1);
void func_1515572C(s32 arg0, s32 arg1);
void func_151A561C(s32 arg0, s32 arg1);

void func_151C9ED4(s32 arg0) {
    s32 sp24;

    sp24 = arg0;
    arg0 = (s32)&sp24;
    func_15160274(arg0, 0x21);
    func_1515572C(arg0, 0x21);
    func_151A561C(arg0, 0x21);
    func_151494E0(arg0, 0x21);
    D_8008CD00 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CA6A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CAACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CAB78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CAD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB5FC.s")

struct func_151CB918_s {
    s32 unk0;
    u8 pad4[8];
    u8 unkC;
    u8 padD;
    u8 unkE;
    u8 padF;
    f32 unk10;
    f32 unk14;
};

struct func_151CB918_s0 {
    u8 pad0[0x70];
    struct func_151CB918_s unk70;
};

typedef struct {
    u8 unk0;
    s32 unk4;
} func_151CB918_arg1;

void func_151CB918(struct func_151CB918_s0 *arg0, func_151CB918_arg1 *arg1, u8 arg2) {
    struct func_151CB918_s *temp_v0 = &arg0->unk70;

    if ((arg2 == 0x37) && (temp_v0->unkE == arg1->unk0) && (temp_v0->unk0 == arg1->unk4)) {
        temp_v0->unk10 = 0.0f;
        temp_v0->unkC |= 1;
        temp_v0->unk14 = 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CBB6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CBBE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CBC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC1D4.s")

void func_1515572C();

void func_151CC290(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    func_1515572C(&sp1C, 0x46);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC2BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC77C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CCD1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CCE94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CCF08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CD224.s")
