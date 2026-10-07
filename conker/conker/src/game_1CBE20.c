#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519E970.s")

struct func_1519EA04_t { u8 pad[0x30]; s32 unk30; };
struct func_1519EA04_s {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0xC];
    s16 unk20;
    u8 pad22[2];
    struct func_1519EA04_t *unk24;
    u8 unk28;
};

void func_1519EA04(struct func_1519EA04_s *arg0) {
    s32 var_v0;
    struct func_1519EA04_t *temp;

    if (arg0->unk10 & 1) {
        arg0->unk20 -= D_800BE9E4;
        var_v0 = 0;
        if (arg0->unk20 < 0) {
            var_v0 = 1;
        }
        if (var_v0) {
            if (arg0->unk28 == 0) {
                temp = arg0->unk24;
                temp->unk30 = 0;
            }
            func_1516972C((struct102 *)arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519EA78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519EB8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519ED24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519ED84.s")

struct func_1519EF04_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

s32 func_1519EF04(u8 *arg0) {
    struct func_1519EF04_s *temp_v1;

    temp_v1 = *(struct func_1519EF04_s **)(arg0 + 0x110);
    *(f32 *)(arg0 + 0x2C) = temp_v1->unk18 * 10.0f;
    *(f32 *)(arg0 + 0x30) = temp_v1->unk1C * 10.0f;
    *(f32 *)(arg0 + 0x40) = temp_v1->unkC;
    *(f32 *)(arg0 + 0x44) = temp_v1->unk10;
    *(f32 *)(arg0 + 0x48) = temp_v1->unk14;
    *(f32 *)(arg0 + 0x34) = temp_v1->unk0;
    *(f32 *)(arg0 + 0x38) = temp_v1->unk4;
    *(f32 *)(arg0 + 0x3C) = temp_v1->unk8;
    return 1;
}
