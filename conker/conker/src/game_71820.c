#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 D_800CBD9C;

void func_15044370(void) {
    D_800CBD9C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504452C.s")

void func_15044658(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150448D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044A28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044B78.s")

struct func_15044CE4_s {
    u8 pad0[6];
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 padC[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[2];
    s16 *unk18;
    s16 *unk1C;
};

void func_15044CE4(struct func_15044CE4_s *arg0) {
    s16 temp;
    arg0->unk6 = arg0->unk18[0];
    arg0->unk8 = arg0->unk18[1];
    arg0->unkA = arg0->unk18[2];
    temp = arg0->unk1C[0] / 32;
    arg0->unk10 = temp;
    arg0->unk12 = temp;
    arg0->unk14 = temp;
    func_15044B78(arg0);
}

void func_1505D1C4(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, u16 arg5, s32 arg6, s32 arg7);

s32 func_15044D40(s16 *arg0) {
    func_1505D1C4(arg0[3], arg0[4], arg0[5], arg0[8], 0xFF, 0, 0, 0);
    return 0;
}

void func_15044DA0(void) {
    if ((gObjects[0].stunned == 0) && (gObjects[0].immune == 0)) {
        func_1505D024(gObjects, 5, gObjects[0].unk7A, -1);
    }
}

void func_15044DE8(void) {
    if ((gObjects[0].stunned == 0) && (gObjects[0].immune == 0) && (D_800C35EA != 1)) {
        func_1505D024(&gObjects[0], 4, gObjects[0].unk7A, -1);
    }
}

void func_15044E40(void) {
    if ((gObjects[0].stunned == 0) && (gObjects[0].immune == 0)) {
        func_1505D024(gObjects, 0x40, gObjects[0].unk7A, -1);
    }
}

void func_15044E88(void) {
    if ((gObjects->stunned == 0) && (gObjects->immune == 0)) {
        func_1505D024(gObjects, 1, gObjects->unk7A, -1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150450CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504530C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504554C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150461D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150466F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504697C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150470B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504715C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150472C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047B80.s")
