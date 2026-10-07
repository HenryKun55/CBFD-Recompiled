#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_188440/func_1515AF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_188440/func_1515B21C.s")

void func_1515572C();

void func_1515B5F4(s16 arg0) {
    s16 sp1C[2];

    sp1C[0] = arg0;
    func_1515572C(sp1C, 0xB);
}

struct func_1515B62C_s {
    u8 pad0[0x70];
    s16 unk70;
};

void func_1515B62C(struct func_1515B62C_s *arg0, s16 *arg1, u8 arg2) {
    if ((arg2 == 0xB) && (arg0->unk70 == *arg1)) {
        func_1516972C((struct102 *)arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_188440/func_1515B674.s")

struct func_1515B994_s {
    u8 pad0[0x14];
    f32 unk14;
    u8 pad18[4];
    f32 unk1C;
    u8 pad20[0x54];
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    f32 unk80;
};

s32 func_1515B994(struct func_1515B994_s *arg0) {
    f32 temp_f2;

    temp_f2 = arg0->unk78;
    arg0->unk14 += (temp_f2 * D_800BE9A4) + (0.5f * arg0->unk74 * D_800BE9A4);
    arg0->unk78 += arg0->unk74 * D_800BE9A4;
    arg0->unk1C = arg0->unk7C + (arg0->unk80 * (arg0->unk78 + temp_f2) * 0.5f);
    return 1;
}

void func_1515BA10(s32 arg0) {
}

void func_1515AF90(s16 arg0);

void func_1515BA1C(s16 arg0) {
    func_1515AF90(arg0);
}

void func_1515BA48(s32 arg0) {
}

void func_1515B674(s16 arg0);

void func_1515BA54(s16 arg0) {
    func_1515B674(arg0);
}

void func_1515B5F4(s16 arg0);

void func_1515BA80(s16 arg0) {
    func_1515B5F4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_188440/func_1515BAAC.s")
