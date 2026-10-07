#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150E9FE0_s {
    u8 unk0;
    void *unk4;
    s8 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    s8 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s8 unk2C;
    s8 unk2D;
    s8 unk2E;
    s8 unk2F;
    s8 unk30;
    f32 unk34;
    s8 unk38;
    s8 unk39;
};

struct func_150E9FE0_s2 {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
};

extern f32 D_800A1410;
extern f32 D_800A1414;
void *func_15134DAC(void *, s32);
void *memcpy(void *, const void *, s32);

void *func_150E9FE0(void *arg0, s16 arg1, s32 arg2, s32 arg3) {
    struct func_150E9FE0_s s;
    void *ret;
    struct func_150E9FE0_s2 t;

    s.unk0 = *((u8 *) arg0 + 0x3B);
    s.unkC = -9.0f;
    s.unk4 = arg0;
    s.unk8 = 8;
    s.unk10 = -14.0f;
    s.unk1C = -14.0f;
    s.unk24 = 2;
    s.unk26 = 60;
    s.unk28 = 60;
    s.unk2A = arg1;
    s.unk2E = 2;
    s.unk2F = 2;
    s.unk30 = 2;
    s.unk38 = 3;
    s.unk39 = -1;
    t.unk0 = 0;
    t.unk4 = 0x11111;
    s.unk14 = 27.0f;
    s.unk18 = -21.0f;
    s.unk20 = 41.0f;
    s.unk34 = 0.5f;
    t.unk8 = D_800A1410;
    t.unkC = D_800A1414;
    ret = func_15134DAC(&s, 0x10);
    if (ret != NULL) {
        memcpy((char *) ret + 0x80, &t, 0x10);
    }
    return ret;
}

s32 func_150EA10C(s32 arg0) {
    *(s32*)(arg0 + 0x80) = 0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA11C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA490.s")

extern f32 D_800A1438;
void *func_1513418C();

struct func_150EA500_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    void *unkC;
    u8 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    u8 unk2A;
    u8 unk2B;
    s8 unk2C;
    u8 unk2D;
};

void func_150EA500(u8 *arg0, s16 arg1, void *arg2, void *arg3) {
    struct func_150EA500_s sp20;

    sp20.unk0 = 0;
    sp20.unk4 = 0;
    sp20.unk8 = arg0[0x3B];
    sp20.unkC = arg0;
    sp20.unk10 = 1;
    sp20.unk14 = 0.0f;
    sp20.unk18 = 0.0f;
    sp20.unk1C = 0.0f;
    sp20.unk20 = 25.0f;
    sp20.unk24 = D_800A1438;
    sp20.unk28 = (arg1 == -1) ? 300 : arg1;
    sp20.unk2A = ((arg1 == -1) ? 0 : 4) | 0xA;
    sp20.unk2B = 7;
    sp20.unk2C = -1;
    sp20.unk2D = 6;
    func_1513418C(&sp20, 0, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA5CC.s")

void func_150E5AE0();

void func_150EA8E0(s32 arg0) {
    func_150E5AE0();
}

void func_150EA904(s32 arg0, s32 arg1) {
    if (D_800DBEF4[arg1].pad70[2] == 0xE0) {
        D_800DBEF4[arg1].unk73 = (D_800DBEF4[arg1].unk73 | 1) | 2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EAB10.s")

s32 func_15046C80(f32 *, s32, f32, void *);

struct func_150EAE24_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct func_150EAE24_s2 {
    u8 pad0[0x14];
    s16 *unk14;
    struct func_150EAE24_s unk18;
};

s32 func_150EAE24(struct func_150EAE24_s2 *arg0) {
    struct func_150EAE24_s *p;
    f32 sp28[3];

    arg0->unk18.unk0 += arg0->unk18.unk8 * D_800BE9A4;
    arg0->unk18.unk4 += arg0->unk18.unkC * D_800BE9A4;
    sp28[0] = arg0->unk18.unk0;
    sp28[1] = arg0->unk18.unk10;
    sp28[2] = arg0->unk18.unk4;
    arg0->unk14[7] = arg0->unk18.unk0;
    arg0->unk14[9] = arg0->unk18.unk4;
    p = &arg0->unk18;
    if (func_15046C80(sp28, 0, arg0->unk18.unk14, &arg0->unk18.unk1C)) {
        arg0->unk14[8] = p->unk1C;
    } else {
        arg0->unk14[8] = p->unk10;
    }
    p->unk18 -= D_800BE9A4;
    if (p->unk18 <= 0.0f) {
        return 0;
    }
    return 1;
}
