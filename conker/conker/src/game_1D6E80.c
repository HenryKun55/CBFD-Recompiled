#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A99D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9BA0.s")

extern f32 D_800A8F80;
s32 func_15045800(f32 *, s32, f32, f32 *);
void func_151ABE40();
void func_10010FFC();
void func_151AA264();
void func_151ABE00(void *arg0);

void func_151A9CA0(u8 *arg0) {
    u8 *s0;
    f32 pos[3];

    s0 = *(u8 **)(arg0 + 0x18);
    if (*(u8 **)(s0 + 0x31C) != NULL && (*(u8 **)(s0 + 0x31C))[0x95] != 0) {
        return;
    }
    pos[0] = *(f32 *)(s0 + 0x14);
    if (D_800A8F80 < *(f32 *)(s0 + 0x118)) {
        pos[1] = *(f32 *)(s0 + 0x118) + 100.0f;
    } else {
        pos[1] = *(f32 *)(s0 + 0x18) + 150.0f;
    }
    pos[2] = *(f32 *)(s0 + 0x1C);
    if (func_15045800(pos, 0, pos[1] - 300.0f, (f32 *)(arg0 + 0x34)) != 0) {
        pos[1] = *(f32 *)(arg0 + 0x34);
        func_151ABE40(pos, (f32 *)(arg0 + 0x34), 1, arg0[0xC], arg0[1]);
        func_10010FFC(0, 8, 0x6978, 0, 0, s0);
    }
    func_151AA264(s0, (f32 *)(arg0 + 0x34));
    func_151ABE00(s0);
}

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

extern f32 D_800A8F94;

struct func_151AA264_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    void *unkC;
    s8 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    s8 unk2A;
    s8 unk2B;
    s8 unk2C;
    s8 unk2D;
};

void func_151AA264(u8 *arg0, u8 *arg1) {
    struct func_151AA264_s sp18;

    if (arg1[0x1C] & 1) {
        sp18.unk0 = 0;
        sp18.unk4 = 0;
        sp18.unk8 = arg0[0x3B];
        sp18.unkC = arg0;
        sp18.unk10 = 1;
        sp18.unk14 = 0.0f;
        sp18.unk18 = 0.0f;
        sp18.unk1C = 0.0f;
        sp18.unk20 = 25.0f;
        sp18.unk24 = D_800A8F94;
        sp18.unk28 = 0x1E;
        sp18.unk2A = 0xE;
        sp18.unk2B = 2;
        sp18.unk2C = -1;
        sp18.unk2D = 0;
        func_1513418C(&sp18, 0, 0xFF, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA30C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA5A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA6D8.s")

struct func_151AAA4C_s {
    u8 pad0[0x8];
    u32 unk8;
    u32 unkC;
    f32 unk10;
    f32 unk14;
};

f32 func_151AAA4C(u8 *arg0) {
    struct func_151AAA4C_s *s = (struct func_151AAA4C_s *)(arg0 + 0x80);
    f32 temp;

    temp = func_151423D8((s->unk8 >> 16) - 0x40) * s->unk14 + s->unk10;
    s->unk8 += s->unkC * D_800BE9E4;
    return temp;
}

struct func_151AAABC_s { u8 pad0[0x14]; u8 *unk14; u8 pad18[0x4]; u8 *unk1C; };
u8 *func_151AA48C(s32);
u8 *func_151AB2C4(s32);

void func_151AAABC(u8 *arg0) {
    s32 a = *(s32 *)(arg0 + 0x18);
    struct func_151AAABC_s *s = (struct func_151AAABC_s *)(arg0 + 0x58);

    if (*(s32 *)(arg0 + 0x6C) != 0) {
        u8 *p = s->unk14 + 0x80;
        p[4] = 1;
    } else {
        s->unk14 = func_151AA48C(a);
    }
    if (s->unk1C != NULL) {
        u8 *q = s->unk1C + 0x58;
        q[4] = 1;
    } else {
        s->unk1C = func_151AB2C4(a);
    }
}

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

struct func_151AB090_sub {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[3];
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 pad1A;
    f32 unk1C;
};

struct func_151AB090_s {
    u8 pad0[0x24];
    s32 unk24;
    u8 pad28[0x88];
    struct func_151AB090_sub unkB0;
};

s8 func_151AB090(struct func_151AB090_s *arg0) {
    s8 ret;
    struct func_151AB090_sub *p = &arg0->unkB0;
    ret = 1;
    if (p->unk4 == 0) {
        ret = 0;
    }
    p->unk4 = 0;
    p->unk14 -= D_800BE9E4;
    if (p->unk14 < 0) {
        p->unk14 = (u32)func_150ADA20() % (p->unk18 + 1) + p->unk16;
        p->unk10 = func_150ADA68() * p->unkC + p->unk8;
    }
    arg0->unk24 += (s32)((p->unk10 - arg0->unk24) * p->unk1C);
    return ret;
}

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

struct func_151AB6B8_sub { u8 pad0[4]; u8 unk4; u8 pad5; u16 unk6; };
struct func_151AB6B8_s { u8 pad0[0x58]; struct func_151AB6B8_sub unk58; };

u8 func_151AB6B8(struct func_151AB6B8_s *arg0) {
    u8 ret = 1;
    struct func_151AB6B8_sub *s = &arg0->unk58;

    if (s->unk6 != 0 && !(D_800DBFF0->unk5F0 & 1)) {
        func_100111C8(s->unk6);
        s->unk6 = 0;
    } else if (s->unk6 == 0 && (D_800DBFF0->unk5F0 & 1)) {
        s->unk6 = func_10010F30(0x355, 0x7D00, 0x40, 0, 0);
    }
    if (s->unk4 == 0) {
        ret = 0;
    }
    s->unk4 = 0;
    return ret;
}

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

struct func_151AB854_s {
    u8 *unk0;
    u8 unk4;
    s16 unk6;
    s8 unk8;
    s8 unk9;
    s8 unkA;
};

void func_151AB854(u8 *arg0) {
    u8 *temp_v1;
    struct func_151AB854_s sp20;
    s32 temp_v0;

    temp_v1 = *(u8 **)(arg0 + 0x18);
    temp_v0 = temp_v1[4];
    if ((temp_v0 == 0) || (temp_v0 == 1) || (temp_v0 == 2) || (temp_v0 == 3) || (temp_v0 == 4) || (temp_v0 == 0x96)) {
        sp20.unk0 = temp_v1;
        sp20.unk4 = temp_v1[0x3B];
        sp20.unk6 = 0x12C;
        sp20.unk8 = 0;
        sp20.unk9 = 0;
        if (temp_v1[4] == 0x96) {
            sp20.unkA = 3;
        } else {
            sp20.unkA = 0;
        }
        if (temp_v1[0x127] != 0xFF) {
            *(s16 *)(*(u8 **)(temp_v1 + 0x31C) + 0x66) = 0x1F4;
        }
        func_15190770(&sp20, 0, arg0[0xC], arg0[1]);
    }
}

void func_151AB920(s32 arg0, s32 arg1) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB9C8.s")

struct func_151ABD54_s {
    s32 unk0;
    u8 unk4;
};

struct func_151ABD54_msg {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_151ABD54(struct102 *arg0, struct func_151ABD54_msg *arg1, u8 arg2) {
    struct func_151ABD54_s *p = (struct func_151ABD54_s *)((u8 *)arg0 + 0x28);

    if (arg2 == 0) {
        if (arg1->unk0 == p->unk0 || ((struct func_151ABD54_s *)arg1)->unk4 == p->unk4) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (p->unk0 == arg1->unk0) {
            p->unk0 = arg1->unk4;
            p->unk4 = arg1->unk9;
        } else if (p->unk0 == arg1->unk4) {
            p->unk0 = arg1->unk0;
            p->unk4 = arg1->unk8;
        }
    }
}

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
