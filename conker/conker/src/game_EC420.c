#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150BEF70(s32 arg0) {
}

void *func_1516D99C();

void func_150BEF7C(s32 arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0x17C;
    var_s1 = 0;
    do {
        func_1516D99C(0x1FDB, 0x25, (s16)var_s0, 0xD, 0, 0x50, 0x8F, 0, 0, 0, 0, 0, 8, 0xC8, 0xA, 0, 0, 0, 0, 0, 0x28, 0x28, 4, 0, 0, 0, 0, 0x555, 0x555, 0x555, 0x555, arg0 & 0xFFFF, 0x32, 0, 0xFF, 0x14, 0xFA0, 0x7D0, 1, 6, 0, 1, 0, 0, 0, 0, 3, 0xFF, 0);
        var_s1 += 1;
        var_s0 = -var_s0;
    } while (var_s1 != 2);
}

struct func_150BF0F4_s {
    u8 pad0[0x14];
    s16 unk14;
    s16 unk16;
    u8 pad18[0x1F - 0x18];
    u8 unk1F;
    u8 pad20[4];
    u8 unk24;
    u8 pad25;
    u8 unk26;
    u8 unk27;
    u8 pad28[4];
    u8 unk2C;
    s8 unk2D;
    s8 unk2E;
    u8 unk2F;
};

s32 func_150BF0F4(struct func_150BF0F4_s *arg0) {
    s32 v0;
    s32 v1;

    v0 = arg0->unk1F;
    v1 = arg0->unk26;
    if (arg0->unk24 != 0) {
        if (v0 != v1) {
            v0 += D_800BE9E4 * arg0->unk27;
            if (v0 > v1) {
                v0 = v1;
            }
            arg0->unk1F = v0;
        }
    } else if (v0 != 0) {
        v0 -= D_800BE9E4 * arg0->unk2F;
        if (v0 < 0) {
            v0 = 0;
        }
        arg0->unk1F = v0;
    }
    if (arg0->unk24 == 0 && v0 == 0) {
        return 1;
    }
    v0 = arg0->unk2D;
    v0 *= D_800BE9E4;
    arg0->unk14 += v0;
    v0 = arg0->unk2E;
    v0 *= D_800BE9E4;
    arg0->unk16 += v0;
    v1 = arg0->unk14;
    if (v1 <= 0 || v1 <= 0) {
        arg0->unk14 = arg0->unk16 = 0;
        return 1;
    }
    v1 = arg0->unk2C;
    v1 += D_800BE9E4;
    if (v1 >= 0x80) {
        v1 = 0x7F;
    }
    arg0->unk2C = v1;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150BF21C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150BF760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150BFA7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150BFFE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150C01DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150C04C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150C0648.s")
