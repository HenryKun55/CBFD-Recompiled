#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DF8C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DF920.s")

extern s32 D_80090324[];
s32 func_150DF8C0(s32);
s32 func_1510D0EC(s32, void *, s32, s32);

Gfx *func_150DFBD0(Gfx *gdl) {
    s32 i;
    s32 temp;
    s32 sp48[2];
    s32 arg;
    s32 seg;

    for (i = 0; i < 3; i++) {
        temp = func_150DF8C0(i);
        if (temp) {
            temp = D_800DD405;
            arg = D_80090324[temp + 9];
        } else {
            arg = D_80090324[8];
        }
        seg = func_1510D0EC(arg, sp48, 3, 0);
        gSPSegment(gdl++, i + 2, seg);
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFCA8.s")

extern f32 D_800A0FB0;

void func_150DFDA4(void *arg0) {
    char *temp_v0;

    temp_v0 = *(char **)((char *)arg0 + 0x1D4) + 0x40;
    *(f32 *)(temp_v0 + 0x30) = *(f32 *)((char *)arg0 + 0x14);
    *(f32 *)(temp_v0 + 0x34) = D_800A0FB0;
    *(f32 *)(temp_v0 + 0x38) = *(f32 *)((char *)arg0 + 0x1C);
}

struct func_150DFDD0_s {
    u32 w0;
    u32 w1;
};

s32 func_150DFDD0(u8 *arg0, u8 *arg1) {
    f32 f;
    struct func_150DFDD0_s *v0;
    s32 i;
    s32 t;
    struct func_150DFDD0_s *p;

    if (*(s32 *)(arg1 + 0x2EC) != 0) {
        arg0[0x13] = 2;
        *(f32 *)(arg1 + 0x2D8) -= D_800BE9A4;
        if (*(f32 *)(arg1 + 0x2D8) < 0.0f) {
            *(s32 *)(arg1 + 0x2EC) = 0;
            return 1;
        }
        f = 1.0f - *(f32 *)(arg1 + 0x2D8) * *(f32 *)(arg1 + 0x2DC);
    } else {
        f = 0.0f;
        arg0[0x13] = 0;
    }
    v0 = **(struct func_150DFDD0_s ***)(arg0 + 0x24);
    if (v0 != NULL) {
        for (i = 0; *(s8 *)&v0[i] != -14; i++) {
        }
        p = (struct func_150DFDD0_s *)((u8 *)v0 + i * 8);
        arg0 = (u8 *)p->w0;
        t = 2 - (s32)(((u32)arg0 >> 12) & 0xFFF) / 3;
        while (t < 0) {
            t += 64;
        }
        p->w0 = 0xF2000000 | (((s32)(500.0f * f + 2.0f) & 0xFFF) << 12) | (t & 0xFFF);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFEFC.s")

void func_150E02C0(s32 arg0, s32 arg1, u8 arg2) {
    func_15149514(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

void func_150E0300(void) {
    if (D_80088980 == 0) {
        func_1515F170(6, 0);
        func_1513BAE8();
        D_80088980 = 1;
    }
}

struct func_150E0348_v { s32 x, y, z; };
struct func_150E0348_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    void *unkC;
    u8 unk10;
    struct func_150E0348_v unk14;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    u8 unk2A;
    u8 unk2B;
    s8 unk2C;
    u8 unk2D;
};
extern f32 D_800A0FB4;
extern f32 D_800A0FB8;
void *func_1513418C(void *, s32, u8, s32);

void func_150E0348(s32 arg0, u8 arg1, s32 arg2) {
    struct func_150E0348_s s;

    s.unk0 = 0;
    s.unk4 = 0;
    s.unk8 = *(u8 *)(arg0 + 0x3B);
    s.unkC = (void *)arg0;
    s.unk10 = 0;
    s.unk14 = *(struct func_150E0348_v *)&D_800A5480;
    s.unk20 = D_800A0FB4;
    s.unk24 = D_800A0FB8;
    s.unk28 = 300;
    s.unk2A = 27;
    s.unk2B = 11;
    s.unk2C = -1;
    s.unk2D = 0;
    func_1513418C(&s, 0, arg1, arg2);
}

s32 func_15143794(s16, s16, f32, f32 *);
s32 func_151A26EC(f32 *, f32 *, f32 *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 D_800A0FBC;
extern f32 D_800A0FC0;
extern f32 D_800A0FC4;
extern f32 D_800A0FC8;
extern f32 D_800A0FCC;

void func_150E03F8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 *arg6) {
    f32 pos[3];
    f32 vel[3];
    f32 zero[3];
    f32 scale;
    f32 sp64;
    u32 sp60;
    u32 sp5C;
    f32 sp58;

    pos[0] = arg0;
    pos[1] = arg1;
    pos[2] = arg2;
    sp5C = func_150ADA20();
    sp60 = func_150ADA20();
    func_15143794(sp5C & 0xFF, (sp60 % 65) - 0x20, func_150ADA68() * D_800A0FBC, vel);
    scale = func_150ADA68();
    arg0 = D_800BE9A8;
    scale = (scale * D_800A0FC0) + D_800A0FC4;
    zero[0] = 0.0f;
    zero[1] = 0.0f;
    zero[2] = 0.0f;
    vel[0] += -arg3 * arg0 * scale;
    vel[1] += -arg4 * arg0 * scale;
    vel[2] += -arg5 * arg0 * scale;
    sp58 = func_150ADA68();
    sp64 = func_150ADA68();
    sp5C = func_150ADA20();
    sp60 = func_150ADA20();
    func_151A26EC(pos, zero, vel, 0.98689097f, (sp58 * D_800A0FC8) + D_800A0FCC, (sp64 * 200.0f) + 150.0f,
                  (sp5C % 26) + 0x28, (sp60 % 201) + 0x37, 0x1E, 0x14, 0, -1, 0x34, 0x35, 0x34,
                  arg6[0xC], arg6[1]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E05F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E06D8.s")
