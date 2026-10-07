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

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFDD0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E03F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E05F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E06D8.s")
