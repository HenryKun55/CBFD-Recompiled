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

struct func_150BFFE0_s {
    s16 unk0;
    s16 unk2;
    u8 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    f32 unk2C[3];
    f32 unk38[3];
    s16 unk44;
    s16 unk46;
    s16 unk48;
    s16 unk4A;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    s32 unk5C;
    u8 unk60;
    s8 unk61;
    u8 unk62;
    u8 unk63;
    u8 unk64;
    f32 unk68;
};

s32 func_15136C3C(u8 *, s32, s32, s32, s32, s32, s32, s32);
s32 func_15153634(struct func_150BFFE0_s *, s32, s32, s32);
extern f32 D_800A0134;
extern f32 D_800A0138;
extern f32 D_800A013C;
extern f32 D_800A0140;
extern f32 D_800A0144;
extern f32 D_800A0148;

void func_150BFFE0(u8 *arg0) {
    f32 pos[3];
    struct func_150BFFE0_s s;

    pos[0] = *(f32 *)(arg0 + 0x14);
    pos[1] = *(f32 *)(arg0 + 0x180) + 70.0f;
    pos[2] = *(f32 *)(arg0 + 0x1C);
    func_15136C3C(arg0, 0, 0, 1, 0, 0, 0xFF, 1);
    s.unk0 = 0x11;
    s.unk2 = 7;
    s.unk4 = 0x6C;
    s.unk6 = 0x5103;
    s.unk8 = 0x200005;
    s.unk10 = 0x28;
    s.unk12 = 0x14;
    s.unk1F = 0xFF;
    s.unk1C = 0x4E;
    s.unk1D = 0x54;
    s.unk1E = 0x7B;
    s.unk20 = 0xA4;
    s.unk21 = 0xA1;
    s.unk22 = 0xC8;
    s.unk23 = 0x9B;
    s.unk24 = 0x64;
    s.unk25 = 0xFF;
    s.unk26 = 0x1E;
    s.unk28 = 8;
    s.unkC = 0;
    s.unk14 = 0;
    s.unk18 = 0;
    s.unk2A = 0x1E;
    s.unk2C[0] = D_800A0134;
    s.unk2C[1] = D_800A0138;
    s.unk2C[2] = D_800A013C;
    s.unk38[0] = pos[0];
    s.unk38[1] = pos[1] + 35.0f;
    s.unk38[2] = pos[2];
    s.unk44 = 0;
    s.unk46 = -0x14;
    s.unk48 = 0xFF;
    s.unk4A = 0x1E;
    s.unk5C = 0x40040E07;
    s.unk60 = 0x10;
    s.unk61 = -1;
    s.unk62 = 8;
    s.unk63 = 6;
    s.unk64 = 1;
    s.unk4C = 15.0f;
    s.unk50 = 39.0f;
    s.unk54 = D_800A0140;
    s.unk58 = D_800A0144;
    s.unk68 = D_800A0148;
    func_15153634(&s, 0xFF, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150C01DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150C04C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150C0648.s")
