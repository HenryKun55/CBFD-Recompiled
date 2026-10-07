#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_14D110/func_1511FC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_14D110/func_15120158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_14D110/func_15121490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_14D110/func_151216F8.s")

s32 func_151C9ED4(void *);

struct func_151218C4_s {
    u8 pad0[0x34];
    s32 unk34;
    u8 pad38[0x134 - 0x38];
    s32 unk134;
    u8 pad138[0x190 - 0x138];
    f32 unk190;
    u8 pad194[4];
    f32 unk198;
    u8 pad19C[0x23D - 0x19C];
    u8 unk23D;
    u8 pad23E[0x348 - 0x23E];
    f32 unk348;
    u8 pad34C[0x36C - 0x34C];
    u16 *unk36C;
    u8 pad370[4];
    f32 unk374;
    u8 pad378[0x3D0 - 0x378];
    s32 unk3D0;
    u8 *unk3D4;
    u8 pad3D8[0x6FC - 0x3D8];
    s32 unk6FC;
    u8 pad700[0x73C - 0x700];
    s16 unk73C;
    u8 pad73E[2];
    struct func_151218C4_sub {
        u8 pad0[0x2C];
        f32 unk2C;
        u8 pad30[0x4C - 0x30];
        u8 unk4C;
        u8 pad4D[0x10A - 0x4D];
        s16 unk10A;
        u8 unk10C;
    } unk740;
    u8 pad850[0x898 - 0x850];
    f32 unk898;
    f32 unk89C;
    u8 pad8A0[0x99C - 0x8A0];
    f32 unk99C;
};

void func_151218C4(struct func_151218C4_s *arg0) {
    struct func_151218C4_sub *sub = &arg0->unk740;

    if (*arg0->unk36C & 0x10) {
        return;
    }
    if (arg0->unk34 == 0x40) {
        if (arg0->unk6FC == 0xF) {
            arg0->unk898 = 0.0f;
            arg0->unk89C = 0.0f;
        }
        arg0->unk3D4[0x198] = 0;
        arg0->unk73C = 0;
        arg0->unk740.unk10A = 0x3C;
    } else {
        arg0->unk740.unk10A = 0x3C;
        arg0->unk73C = 3;
    }
    arg0->unk374 = 200.0f;
    arg0->unk348 = 100.0f;
    arg0->unk134 = sub->unk2C;
    sub->unk4C = 0;
    arg0->unk190 = 0.0f;
    arg0->unk99C = 0.0f;
    arg0->unk198 = 0.0f;
    func_1506160C(arg0->unk3D0, 2, 0xFF, 0x20, arg0->unk23D);
    if (arg0->unk740.unk10C != 0) {
        func_151C9ED4(arg0);
        arg0->unk740.unk10C = 0;
    }
}
