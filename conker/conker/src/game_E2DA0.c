#include <ultra64.h>
#include "functions.h"
#include "variables.h"


u16 *func_150B58F0(u16 *arg0, s32 arg1) {
    if (D_800C35EA == 1) {
        return arg0;
    }
    arg0[0] = 0x1A;
    arg0[1] = *(u16 *)((u8 *)D_800CC34A + arg1 * 0x32C);
    return arg0 + 2;
}

extern f32 D_8009FC98;
extern f32 D_8009FC9C;
void func_150B5A3C(f32 *pos, u8 a, u8 b);
void func_150B60E0();

void func_150B5950(u8 *arg0) {
    s32 pad;
    f32 pos[3];
    u8 *obj;

    obj = *(u8 **)(arg0 + 0x28);
    if (*(s32 *)obj == 0 || arg0[0x2C] != obj[0x3B]) {
        *(s16 *)(arg0 + 0xE) = -1;
        return;
    }
    if (*(s32 *)(obj + 0x1D4) != 0) {
        if (func_150ADA68() < D_8009FC98) {
            pos[0] = *(f32 *)(obj + 0x14);
            pos[1] = *(f32 *)(obj + 0x18);
            pos[2] = *(f32 *)(obj + 0x1C);
            func_150B5A3C(pos, arg0[0xC], arg0[1]);
        }
        if (func_150ADA68() < D_8009FC9C) {
            func_150B60E0(obj, pos);
            func_150B5A3C(pos, arg0[0xC], arg0[1]);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5E34.s")

struct225 *func_151602C0(Header *header, Header2 *header2, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 offset, s32 arg9, s32 argA);

void func_150B6000(f32 *arg0, u8 arg1, s32 arg2) {
    Header header;
    Header2 header2;

    header.unk0 = 3;
    header.unk1 = -1;
    header.unk2 = ((u32) func_150ADA20() % 9) + 3;
    header.unk4 = 0;
    header2.unk0 = (s32) arg0[0];
    header2.unk4 = (s32) arg0[1];
    header2.unk8 = (s32) arg0[2];
    func_151602C0(&header, &header2, ((u32) func_150ADA20() % 201) + 0x37, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, arg1, arg2);
}

extern u8 D_8009FC30[];

struct func_150B60E0_s {
    u8 pad[0x1D4];
    s32 unk1D4;
};

void func_150B60E0(struct func_150B60E0_s *arg0, void *arg1) {
    func_15143134(D_8009FC30, arg1, arg0->unk1D4 + 0x140);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B6110.s")

void func_150B6450(struct102 *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 0x4A) {
        func_1516972C(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B648C.s")

struct func_150B66DC_s {
    u8 pad0[0x14];
    u8 *unk14;
    u8 *unk18;
};

s32 func_150B66DC(struct func_150B66DC_s *arg0) {
    u8 *p = arg0->unk18;

    switch (p[0x68] - 15) {
        case 0:
            arg0->unk14[9] = 1;
            break;
        case 1:
            arg0->unk14[9] = 0;
            arg0->unk14[0x2F] = 0x14;
            break;
        case 2:
        default:
            arg0->unk14[9] = 0;
            arg0->unk14[0x2F] = 0x28;
            break;
    }
    return 1;
}

void func_150B6754(u8 arg0, s32 arg1) {
    u32 b;
    u32 a;

    a = func_150ADA20();
    b = func_150ADA20();
    func_15182670(0xCC, 0xCC, 0xFF, (u8)((a % 56) + 200), (b % 11) + 15, 0, arg0, arg1);
}
