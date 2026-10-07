#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DB9E0.s")

extern f32 D_800A0C24;
extern f32 D_800A0C28;
extern f32 D_800A0C2C;
extern f32 D_800A0C30;
void func_15152F70(void *arg0, s32 arg1);

struct func_150DBC60_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    u8 unk38;
    u8 unk39;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    u8 unk54;
    u8 unk55;
};

void func_150DBC60(u8 *arg0) {
    struct func_150DBC60_s sp18;

    sp18.unk0 = D_800A0C24;
    sp18.unk4 = D_800A0C28;
    sp18.unk8 = D_800A0C2C;
    sp18.unk1C = 7.0f;
    sp18.unk20 = 5.0f;
    sp18.unk14 = D_800A0C30;
    sp18.unk18 = 0.0f;
    sp18.unk24 = 1;
    sp18.unk26 = 2;
    sp18.unk28 = -0x4B;
    sp18.unk2C = -0x26;
    sp18.unk2A = 0x16;
    sp18.unk2E = 0x23;
    sp18.unk30 = 3;
    sp18.unk32 = 2;
    sp18.unk34 = 0x29;
    sp18.unk36 = 0;
    sp18.unkC = 2.0f;
    sp18.unk10 = 2.0f;
    sp18.unk38 = 0xA;
    sp18.unk39 = 0x28;
    sp18.unk3C = 1;
    sp18.unk40 = 0;
    sp18.unk44 = 0;
    sp18.unk48 = 0;
    sp18.unk4C = 0;
    sp18.unk50 = 0;
    sp18.unk54 = 0xFF;
    sp18.unk55 = 0xFF;
    func_15152F70(&sp18, arg0[0xC]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DBD70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DC558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DCEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DD640.s")

struct func_150DDED0_s {
    u8 pad0[0x28];
    u8 unk28;
    u8 pad29[0x72 - 0x29];
    u8 unk72;
};

void func_150DDED0(struct func_150DDED0_s *arg0) {
    struct func_150DDED0_s *temp_v0;

    temp_v0 = (struct func_150DDED0_s *)func_151491F4(0x64, 2, -1, 1, 0, (struct37 *)1, 0xFF, 0);
    if (temp_v0 != NULL) {
        switch (arg0->unk72) {
        case 0xFB:
            temp_v0->unk28 = 1;
            break;
        case 0xFC:
            temp_v0->unk28 = 2;
            break;
        case 0xFD:
            temp_v0->unk28 = 4;
            break;
        case 0xFE:
            temp_v0->unk28 = 3;
            break;
        default:
            func_1516972C((struct102 *)temp_v0);
            break;
        }
    }
}

struct func_150DDF88_s {
    u8 pad[0x28];
    u8 unk28;
};

void func_150DBD70(u8 arg0, struct func_150DDF88_s *arg1);

void func_150DDF88(struct func_150DDF88_s *arg0) {
    func_150DBD70(arg0->unk28, arg0);
}

struct func_150DDFAC_s2 {
    f32 x;
    f32 y;
    f32 z;
    s32 pad[2];
};

struct func_150DDFAC_s {
    s32 unk0;
    s16 unk4;
    u8 unk6;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    s32 unk18;
    s32 pad1C;
    s64 pad20;
};

s32 func_150DDFAC(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5) {
    void *sp8C;
    struct func_150DDFAC_s2 *sp88;
    struct func_150DDFAC_s sp60;
    f32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;

    sp8C = (*(void **)((char *)(arg0) + 0x98));
    sp88 = (*(struct func_150DDFAC_s2 **)((char *)(arg0) + 0x94));
    sp5C = (func_150ADA68() * 70.0f) + 10.0f;
    (*(s8 *)((char *)(sp8C) + 0x20)) = 4;
    switch (func_150ADA20() & 1) {
    case 0:
        sp60.unk6 = 0x1D;
        break;
    case 1:
        sp60.unk6 = 0x1E;
        break;
    }
    sp60.unk8 = 0;
    sp60.unkC = 0;
    sp60.unk0 = 0x11;
    sp60.unk4 = 0x64;
    sp60.unk10 = 0xFF;
    sp60.unk11 = 0xFF;
    sp60.unk12 = 0;
    sp60.unk13 = 0;
    sp60.unk14 = 0;
    sp60.unk15 = 0xFF;
    sp60.unk18 = 0x30002;
    sp50 = func_150ADA20();
    sp54 = func_150ADA20();
    func_1513C73C((s32)&sp60, 5, 0, arg5, sp88[*(s8 *)((char *)(arg0) + 0x2D)].x, arg4, sp88[*(s8 *)((char *)(arg0) + 0x2D)].z, sp5C, sp5C, sp50 & 0xFF, (sp58 = func_150ADA20(), sp58 & 1) + (sp54 & 1), 0, *(u8 *)((char *)(arg0) + 0xC), *(u8 *)((char *)(arg0) + 1));
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DE12C.s")

struct func_150DE2A4_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_150DE2A4(struct func_150DE2A4_s *arg0) {
    if (arg0->unk1C < 0x20) {
        arg0->unk28 = arg0->unk1C * 8;
    }
    return 1;
}

struct func_150DE2C4_s {
    u8 pad0[0x34];
    s16 unk34;
    s16 unk36;
    s16 unk38;
};

void func_150DE2C4(struct func_150DE2C4_s *arg0) {
    arg0->unk34 -= 26;
    arg0->unk36 -= 26;
    if (arg0->unk34 < 10 || arg0->unk36 < 10) {
        arg0->unk38 = 0;
    }
}
