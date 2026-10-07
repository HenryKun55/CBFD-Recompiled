#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_197120/func_15169C70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197120/func_1516A3F4.s")

void func_15171D4C(f32, f32, f32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);

struct func_1516A538_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[7];
    s16 unk14;
    s16 pad16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 pad1E[7];
    u8 unk25;
};

void func_1516A538(struct func_1516A538_s *arg0) {
    u32 sp4C;
    s32 sp48;
    s32 sp44;

    if (arg0->unk14 >= 0x300) {
        sp48 = func_150ADA20() % 3U;
        sp44 = arg0->unk25;
        sp4C = func_150ADA20() % 360U;
        func_15171D4C((f32) arg0->unk18, (f32) (arg0->unk1A - 0xA), (f32) arg0->unk1C, 0x64, 0, sp48 + 0x20,
                      (f32) sp4C, 0, ((sp44 * 0x19) / 255) + 0x19, 0, 0x100, 0,
                      arg0->unkC, arg0->unk1);
    }
}

struct func_1516A648_s {
    u8 pad0[0xE];
    s16 x;
    s16 y;
    s16 z;
    u8 pad14[4];
    s16 vy;
    u8 pad1A[5];
    u8 alpha;
    u8 pad20[4];
    u8 fadeIn;
    u8 pad25[7];
    u8 hiY;
    u8 loY;
};

void func_1516F864(struct func_1516A648_s *);
s32 func_1510F8D8(s32, s32, s32, s32);
void func_1516F94C(struct func_1516A648_s *, s32);

s32 func_1516A648(struct func_1516A648_s *arg0) {
    s32 alpha = arg0->alpha;
    s32 h;

    if (arg0->fadeIn) {
        if (alpha != 0xFF) {
            alpha += D_800BE9E4 * 16;
            if (alpha >= 0x100) {
                alpha = 0xFF;
            }
            arg0->alpha = alpha;
        }
    } else if (alpha) {
        alpha -= D_800BE9E4 * 4;
        if (alpha < 0) {
            alpha = 0;
        }
        arg0->alpha = alpha;
    }
    if (arg0->fadeIn == 0 && alpha == 0) {
        return 1;
    }
    arg0->vy -= 300;
    func_1516F864(arg0);
    h = func_1510F8D8(arg0->x, arg0->y, arg0->z, 0) + 10;
    arg0->hiY = h >> 8;
    arg0->loY = h & 0xFF;
    if (arg0->y < h) {
        arg0->y = h;
        arg0->vy = arg0->vy * -0.5f;
        func_1516F94C(arg0, 0xE6);
    }
    return 0;
}
