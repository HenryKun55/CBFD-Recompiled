#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_14F8F0/func_15122440.s")

struct func_15122980_s {
    u8 pad0[0x84];
    s32 unk84;
    u8 pad88[0xDC - 0x88];
    s32 unkDC;
    u8 padE0[0x298 - 0xE0];
    s16 unk298;
    u8 pad29A[0x2BC - 0x29A];
    f32 unk2BC[3];
    f32 unk2C8[3];
    u8 pad2D4[0x2F8 - 0x2D4];
    f32 unk2F8[3];
    u8 pad304[0x37C - 0x304];
    f32 unk37C;
    u8 pad380[0x390 - 0x380];
    f32 unk390;
    u8 pad394[0x39C - 0x394];
    f32 unk39C;
    u8 pad3A0[0x7B4 - 0x3A0];
    f32 unk7B4;
    u8 pad7B8[0x8D4 - 0x7B8];
    f32 unk8D4;
    f32 unk8D8;
    f32 unk8DC;
};

void func_150495B0(f32 *, f32, f32 *, f32, f32, f32);
void func_15123A54(struct func_15122980_s *);
void func_1512E140(struct func_15122980_s *);
void func_1512A390(struct func_15122980_s *);
extern f32 D_800A34A0;

void func_15122980(struct func_15122980_s *arg0) {
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 temp_f14;

    if (arg0->unkDC != 4) {
        func_15048F90(arg0->unk2F8, arg0->unk2C8, sp44);
        func_15048F90(arg0->unk2F8, arg0->unk2BC, sp38);
        sp34 = func_15048FC8(sp44);
        temp_f14 = func_15048FC8(sp38);
        if (arg0->unk298 == 0) {
            arg0->unk8D4 = 0.0f;
        } else if ((arg0->unk84 & 0x100000) || ((arg0->unk390 > 180.0f) && (arg0->unk390 < 270.0f))) {
            arg0->unk8D4 = 0.75f;
        } else {
            arg0->unk8D4 = 0.5f;
        }
        func_150495B0(&arg0->unk8DC, arg0->unk8D4, &arg0->unk8D8, 1.0f, 2.0f, arg0->unk7B4);
        arg0->unk37C += func_15048A70(sp34, temp_f14) * arg0->unk8DC;
        arg0->unk39C = arg0->unk37C * D_800A34A0;
    }
    func_15123A54(arg0);
    func_1512E140(arg0);
    func_1512A390(arg0);
}
