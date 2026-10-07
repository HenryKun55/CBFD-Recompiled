#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A99D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA09C.s")

void func_151AA170(s32 arg0) {
}

struct func_151AA17C_s {
    s32 unk0;
    u8 unk4;
};

void func_15147D64();
void func_1519F3B8();

void func_151AA17C(u8 *arg0) {
    s32 ptr;
    struct func_151AA17C_s sp1C;

    ptr = *(s32 *)(arg0 + 0x18);
    sp1C.unk0 = ptr;
    ptr = (s32)&sp1C;
    sp1C.unk4 = arg0[0x1C];
    func_15147D64(ptr, 10);
    func_151494E0(ptr, 10);
    func_1519F3B8(arg0);
}

void func_151AA1D0(void) {
    func_1519F400();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA1F0.s")

void func_15147D64(s32, s32);
void func_1519F3B8(s32);

void func_151AA210(s32 arg0) {
    s32 p;
    struct {
        s32 f0;
        u8 f4;
    } tmp;

    p = *(s32 *)(arg0 + 0x18);
    tmp.f0 = p;
    p = (s32)&tmp;
    tmp.f4 = *(u8 *)(arg0 + 0x1C);
    func_15147D64(p, 0xA);
    func_151494E0(p, 0xA);
    func_1519F3B8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA30C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA5A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA6D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AAA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AAABC.s")

void func_151AAB50(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *)(*(s32 *)(arg0 + 0x80) + 0x58);
    temp_v0[5] = 0;
    func_151352EC(arg0);
}

struct func_151AAB78_s {
    u8 pad0[0x14];
    s32 unk14;
};

void func_1513530C(void *arg0);

void func_151AAB78(void *arg0) {
    struct func_151AAB78_s *tmp = (struct func_151AAB78_s *)(*(u8 **)((u8 *)arg0 + 0x80) + 0x58);
    tmp->unk14 = 0;
    func_1513530C(arg0);
}

s32 func_151AABA0(u8 *arg0) {
    s32 ret = 1;

    if (arg0[0x84] == 0) {
        ret = 0;
    }
    arg0[0x84] = 0;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AABC4.s")

struct func_151AADBC_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x98 - 0x1E];
    u8 *unk98;
};

s32 func_151AADBC(struct func_151AADBC_s *arg0) {
    u8 *p = arg0->unk98;
    s32 v = arg0->unk1C * 16;
    if (v >= 256) {
        v = 255;
    }
    if (v < p[0x1B]) {
        p[0x1B] = v;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AADF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB090.s")

struct func_151AB180_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0xB0 - 0x1C];
    u8 *unkB0;
};

s32 func_151AB180(struct func_151AB180_s *arg0) {
    u8 *temp = arg0->unkB0 + 0x58;

    *(s32 *)(temp + 0x18) = 0;
    arg0->unkB0 = NULL;
    arg0->unk18 |= 2;
    func_1513F6C0(arg0, 0, 0);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB1C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB3A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB6B8.s")

void func_151346EC(void *);
struct func_151AB788_s { u8 pad0[0x58]; u8 *unk58; u8 pad5C[2]; volatile u16 unk5E; };
void func_151AB788(struct func_151AB788_s *arg0) {
    struct func_151AB788_s *s = arg0;
    u8 *temp_v0 = s->unk58 + 0x58;
    if (s->unk5E) {
        func_100111C8(arg0->unk5E);
    }
    *(s32 *)(temp_v0 + 0x1C) = 0;
    func_151346EC(arg0);
}

struct func_151AB7D8_s {
    u8 pad0[0x58];
    struct func_151AB7D8_s *unk58;
    u8 pad5C[2];
    volatile u16 unk5E;
    u8 pad60[0x14];
    s32 unk74;
};

void func_1513470C(struct func_151AB7D8_s *arg0);

void func_151AB7D8(struct func_151AB7D8_s *arg0) {
    s32 pad;
    s32 *temp_v0 = (s32 *)&arg0->unk58->unk58;

    if (arg0->unk5E != 0) {
        func_100111C8(arg0->unk5E);
    }
    temp_v0[7] = 0;
    func_1513470C(arg0);
}

void func_151AB828(s32 arg0) {
    func_15141DA4(*(s32 *)(arg0 + 0x18), 0, 4, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB854.s")

void func_151AB920(s32 arg0, s32 arg1) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151ABD54.s")

struct func_151ABE00_s {
    void *unk0;
    u8 unk4;
};

void func_151ABE00(void *arg0) {
    struct func_151ABE00_s sp18;

    sp18.unk0 = arg0;
    sp18.unk4 = *((u8 *)arg0 + 0x3B);
    func_1516944C(0x20, &sp18, 0xC);
}
