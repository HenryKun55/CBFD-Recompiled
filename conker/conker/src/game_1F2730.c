#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5280.s")

s32 func_15102B38(s32, s32, s32 *, s32 *, f32 *, s32, s32, f32, s32, s32, s32, s32, s32, s32); /* extern */
extern s32 D_800AAA90;
extern s32 D_800AAA9C;
extern f32 D_800AAABC;
extern f32 D_800AAAC0;
extern f32 D_800AAAC4;
extern f32 D_800AAAC8;

void func_151C5588(s32 arg0, s32 arg1, s16 arg2, u8 arg3, s32 arg4) {
    f32 sp50[2];
    s32 sp44[3];

    sp50[1] = ((func_150ADA68() * D_800AAABC) + 604.0f) * D_800AAAC0;
    sp50[0] = ((func_150ADA68() * 59.0f) + 141.0f) * D_800AAAC4;
    sp44[0] = func_150ADA20();
    sp44[1] = func_150ADA20();
    func_15102B38(arg0, 0, &D_800AAA90, &D_800AAA9C, sp50, (sp44[0] & 3) + 6, 0xFF, (func_150ADA68() * 270.0f) + D_800AAAC8, arg1, 0xFF, 0, arg2, arg3, arg4);
}

struct225 *func_151602C0(Header *header, Header2 *header2, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 offset, s32 arg9, s32 argA);

void func_151C56A4(f32 *pos, u8 arg1, s32 arg2) {
    Header header;
    Header2 header2;

    header.unk0 = 3;
    header.unk1 = -1;
    header.unk2 = ((u32) func_150ADA20() % 3) + 3;
    header.unk4 = 0;

    header2.unk0 = pos[0];
    header2.unk4 = pos[1];
    header2.unk8 = pos[2];

    func_151602C0(&header, &header2, (func_150ADA20() & 1) + 6, 0xFF, 0xE8, 0xAB, 0xFF, 0, 0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C577C.s")

struct func_151C5E74_s {
    u8 unk0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
};

void func_15137F30(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, struct func_151C5E74_s *arg5, f32 *arg6, f32 *arg7, f32 *arg8, f32 *arg9, s16 *argA, u8 *argB, f32 *argC);
void func_151D9014(void *arg0, f32 *arg1, u8 arg2, f32 arg3, s16 arg4, u8 arg5, f32 arg6, u8 arg7, f32 arg8, f32 arg9, u8 argA, s32 argB, u8 argC, u8 argD, u8 argE, s32 argF);

void func_151C5E74(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, struct func_151C5E74_s *arg5) {
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp50;
    s16 sp4E;
    u8 sp4D;
    f32 sp48;

    func_15137F30(arg0, arg1, arg2, arg3, arg4, arg5, sp6C, sp60, sp54, &sp50, &sp4E, &sp4D, &sp48);
    func_151D9014(sp6C, sp54, 1, sp50, sp4E, sp4D, sp48, 0, 1.0f, 1.0f, 1, 0, 1, 0, arg5->unkC, arg5->unk1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5F44.s")

extern f32 D_800AAAF4;
extern f32 D_800AAAF8;
extern f32 D_800AAAFC;
void func_15154684(void *arg0, s32 arg1, s32 arg2);

struct func_151C61A0_s {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 unk24;
    u8 unk25;
    s16 unk26;
    s16 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    s32 unk38;
};

void func_151C61A0(s32 arg0, s32 arg1, u8 arg2, s32 arg3) {
    struct func_151C61A0_s sp1C;

    sp1C.unk10 = 5.0f;
    sp1C.unk0 = 0xA;
    sp1C.unk14 = 7.0f;
    sp1C.unk2 = 4;
    sp1C.unk4 = arg0;
    sp1C.unk8 = 0;
    sp1C.unkC = 0xFF;
    sp1C.unkA = -0x18;
    sp1C.unkE = 0x19;
    sp1C.unk24 = 0xBE;
    sp1C.unk25 = 0x41;
    sp1C.unk26 = 0xC8;
    sp1C.unk28 = 0x96;
    sp1C.unk18 = D_800AAAF4;
    sp1C.unk1C = D_800AAAF8;
    sp1C.unk20 = D_800AAAFC;
    sp1C.unk2C = 96.0f;
    sp1C.unk30 = 109.0f;
    sp1C.unk34 = 1.0f;
    sp1C.unk38 = arg1;
    func_15154684(&sp1C, arg2, arg3);
}

s32 func_151C6290(u8 *arg0, s32 arg1, s32 arg2) {
    switch (arg0[4]) {
    case 0x5A:
    case 0x74:
    case 0x7A:
        return 0;
    }
    return 1;
}
