#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150D7120_v { s32 x, y, z; };
struct func_150D7120_s {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    struct func_150D7120_v unk10;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    s32 unk34;
    s32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    s16 unk52;
    s16 unk54;
    s16 unk56;
    u8 unk58;
};
extern void func_151C04F8(struct func_150D7120_v *, u8, s32);
extern void func_151C05A4(struct func_150D7120_v *, u8, s32);
extern void func_151C05F0(struct func_150D7120_v *, u8, s32);
extern void func_1514FCE8(struct func_150D7120_s *, u8, s32);
extern f32 D_800A0AE0;
extern f32 D_800A0AE4;
extern f32 D_800A0AE8;

void func_150D7120(struct func_150D7120_v *arg0, u8 arg1, s32 arg2) {
    struct func_150D7120_s s;

    func_151C04F8(arg0, arg1, arg2);
    func_151C05A4(arg0, arg1, arg2);
    func_151C05F0(arg0, arg1, arg2);
    s.unk0 = 0;
    s.unk2 = 0xFF;
    s.unk4 = -0x40;
    s.unk6 = 0x47;
    s.unk8 = 6;
    s.unkC = 4;
    s.unk10 = *arg0;
    s.unk1C = 23.0f;
    s.unk20 = 30.0f;
    s.unk24 = 45.0f;
    s.unk28 = 53.0f;
    s.unk2C = 203.0f;
    s.unk30 = 414.0f;
    s.unk34 = 7;
    s.unk38 = 3;
    s.unk3C = 15.0f;
    s.unk40 = D_800A0AE0;
    s.unk44 = D_800A0AE4;
    s.unk48 = D_800A0AE8;
    s.unk4C = 0x19;
    s.unk4E = 0xF;
    s.unk50 = 0x64;
    s.unk52 = 0x64;
    s.unk54 = 0xC;
    s.unk56 = 0x14;
    s.unk58 = 0;
    func_1514FCE8(&s, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1045D0/func_150D728C.s")
