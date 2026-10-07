#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EEE00.s")

struct func_150EEF40_s {
    void *unk0;
    u8 unk4;
    u8 unk5;
};

void func_150EEF40(u8 *arg0, u8 arg1) {
    struct func_150EEF40_s sp18;

    sp18.unk0 = arg0;
    sp18.unk4 = arg0[0x3B];
    sp18.unk5 = arg1;
    func_151403A8(&sp18, 0x43);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EEF80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EF38C.s")

s32 func_150EF784(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg0[4] == 0x28) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EF7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EF860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EF910.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFB80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFEC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F00EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0198.s")

void func_150F0260(void) {
    func_150F02A0();
}

void func_150F0280(void) {
    func_150F02A0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F02A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F02C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F02EC.s")

void func_150F0318(s32 arg0) {
    s32 temp_v0;

    temp_v0 = *(s32 *)(arg0 + 0x28);
    *(s32 *)(temp_v0 + 0x134) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0354.s")

struct func_150F0380_s {
    u8 pad0[0x178];
    s32 *unk178;
};

void func_150F0380(struct func_150F0380_s *arg0) {
    s32 *temp_v0 = arg0->unk178;
    temp_v0[0x138 / 4] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F03BC.s")

struct func_150F03E8_s {
    u8 pad0[0x18];
    struct { u8 pad[0x13C]; s32 unk13C; } *unk18;
};

void func_150F03E8(struct func_150F03E8_s *arg0) {
    struct { u8 pad[0x13C]; s32 unk13C; } *temp = arg0->unk18;
    temp->unk13C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F03F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F07E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F088C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F10D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F15F8.s")

struct func_150F1684_s {
    s32 unk0;
    u8 unk4;
};

void func_150F1684(struct102 *arg0, struct func_150F1684_s *arg1, u8 arg2) {
    struct func_150F1684_s *temp;
    s32 val;

    temp = (struct func_150F1684_s *)((u8 *)arg0 + 0x18);
    if (arg2 == 0x43) {
        val = arg1->unk0;
        if ((val == temp->unk0) || (arg1->unk4 == temp->unk4)) {
            func_1516972C(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F16DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1B48.s")

struct func_150F1CB0_s {
    u8 pad0[0x68];
    u8 unk68;
    u8 unk69;
    u8 pad6A[0x84 - 0x6A];
    u16 unk84;
    u8 pad86[0x2E4 - 0x86];
    s32 unk2E4;
};

void func_150F1CB0(struct func_150F1CB0_s *arg0) {
    if (arg0->unk84 == 0x14) {
        arg0->unk68 = 0x1B;
    } else {
        arg0->unk68 = 0xC;
    }
    arg0->unk69 = 0x13;
    if ((arg0->unk2E4 & 3) == 3) {
        arg0->unk69 = 0x14;
    }
    if ((arg0->unk2E4 & 0xC) == 0xC) {
        arg0->unk69 = 0x17;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F20F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F2230.s")
