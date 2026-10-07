#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150D8B10(f32 *arg0, f32 *arg1) {
    arg1[0] = arg0[5];
    arg1[1] = arg0[6] + 20.0f;
    arg1[2] = arg0[7];
}

extern f32 D_800A0B40;
extern f32 D_800A0B44;
void func_15145740(void *arg0, f32 *arg1, f32 *arg2, void *arg3, f32 arg4);

void func_150D8B3C(void *arg0, void *arg1) {
    f32 sp34[3];
    f32 sp28[3];

    func_15145740(arg0, sp34, sp28, arg1, D_800BE616 ? D_800A0B40 : D_800A0B44);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8D84.s")

struct func_150D8E1C_s {
    u8 pad0[0x1C];
    u16 unk1C;
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
};

void func_150D8E1C(struct func_150D8E1C_s *arg0) {
    arg0->unk30 = 0;
    arg0->unk1E &= ~2;
    arg0->unk1E |= 8;
    arg0->unk1E |= 1;
    arg0->unk1C = 0x28;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8FAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D942C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D9C7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150DA484.s")

void func_150DA484(s32 arg0);
void func_151478F4(s32 arg0);

void func_150DA4B4(s32 arg0) {
    func_150DA484(arg0);
    func_151478F4(arg0);
}

void func_150DA4E0(s32 arg0) {
    func_150DA484(arg0);
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150DA50C.s")

struct func_150DA5EC_s {
    u8 *ptr;
    u8 b;
    f32 f;
};

void func_150DA5EC(u8 *arg0, f32 arg1) {
    struct func_150DA5EC_s s;

    s.ptr = arg0;
    s.b = arg0[0x3B];
    s.f = arg1;
    func_15147D64(&s, 0x44);
}

void *func_15131828();
void *func_15131958();

s32 func_150DA628(u8 *arg0, s32 arg1) {
    u8 *temp_a2 = arg0 + 0xA8;

    func_15131828(arg0, arg0 + 0xAC, temp_a2, arg0 + 0xAA);
    func_15131958(arg0 + 0x58, *(s32 *)(temp_a2 + 0xC), temp_a2);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150DA67C.s")
