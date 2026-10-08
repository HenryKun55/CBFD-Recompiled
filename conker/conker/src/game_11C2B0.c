#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800A163C[];
extern u8 D_800A1638[];
extern vertex D_800A15F0[];
s32 func_150EEF80(void *, u8, s32, s32);
void func_150F0A24();
struct225 *func_151602C0();

struct func_150EEE00_s {
    u8 pad0[0x94];
    s32 unk94;
    u8 pad98[0x1D4 - 0x98];
    u8 *unk1D4;
};

void func_150EEE00(struct func_150EEE00_s *arg0, u8 arg1) {
    vertex sp54;
    Header header;
    Header2 header2;
    

    if (!(D_800A163C[arg1] & arg0->unk94)) {
        func_150EEF80(arg0, arg1, 0xFF, 1);
        if (arg0->unk1D4 != NULL) {
            func_15143134(&D_800A15F0[arg1], &sp54, arg0->unk1D4 + (D_800A1638[arg1] << 6));
            header.unk0 = 3;
            header.unk1 = -1;
            header.unk2 = func_150ADA20() % 3U + 4;
            header.unk4 = 0;
            header2.unk0 = sp54.x;
            header2.unk4 = sp54.y;
            header2.unk8 = sp54.z;
            func_151602C0(&header, &header2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0xFF, 1);
            func_150F0A24(&sp54);
        }
    }
}

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

struct func_150EF7B0_s {
    u8 pad0[0x1C];
    struct102 *unk1C[2];
    struct102 *unk24;
    struct102 *unk28;
    struct102 *unk2C;
};

void func_150EF7B0(u8 *arg0) {
    struct func_150EF7B0_s *temp_s3;
    s32 i;

    temp_s3 = (struct func_150EF7B0_s *)(arg0 + 0x110);
    for (i = 0; i < 2; i++) {
        if (temp_s3->unk1C[i] != NULL) {
            func_1516972C(temp_s3->unk1C[i]);
        }
    }
    if (temp_s3->unk24 != NULL) {
        func_1516972C(temp_s3->unk24);
    }
    if (temp_s3->unk28 != NULL) {
        func_1516972C(temp_s3->unk28);
    }
    if (temp_s3->unk2C != NULL) {
        func_1516972C(temp_s3->unk2C);
    }
    func_1513CA6C(arg0);
}

void func_150EF860(u8 *arg0) {
    u8 *temp = arg0 + 0x110;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (((struct102 **)(temp + 0x1C))[i] != NULL) {
            func_1516979C(((struct102 **)(temp + 0x1C))[i]);
        }
    }
    if (*(struct102 **)(temp + 0x24) != NULL) {
        func_1516979C(*(struct102 **)(temp + 0x24));
    }
    if (*(struct102 **)(temp + 0x28) != NULL) {
        func_1516979C(*(struct102 **)(temp + 0x28));
    }
    if (*(struct102 **)(temp + 0x2C) != NULL) {
        func_1516979C(*(struct102 **)(temp + 0x2C));
    }
    func_1513CAA0(arg0);
}

struct func_150EF910_s {
    void *unk0;
    u8 unk4;
    u8 pad5[3];
    void *unk8;
    u8 unkC;
    u8 unkD;
};

struct func_150EF910_ev {
    void *unk0;
    void *unk4;
    u8 unk8;
    u8 unk9;
};

struct func_150EF910_e43 {
    void *unk0;
    u8 unk4;
    u8 unk5;
};

void func_150EF910(struct102 *arg0, void *arg1, u8 arg2) {
    struct func_150EF910_s *s = (struct func_150EF910_s *)((u8 *)arg0 + 0x110);
    struct func_150EF910_ev *ev;
    struct func_150EF910_e43 *e43;
    void *a;
    void *b;
    u8 c;
    u8 d;

    if (arg2 == 0) {
        a = s->unk0;
        b = ((struct func_150EF910_ev *)arg1)->unk0;
        c = s->unk4;
        d = ((u8 *)arg1)[4];
        if (a == b || c == d) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        ev = arg1;
        if (s->unk0 == ev->unk0) {
            s->unk0 = ev->unk4;
            s->unk4 = ev->unk9;
        } else if (s->unk0 == ev->unk4) {
            s->unk0 = ev->unk0;
            s->unk4 = ev->unk8;
        }
        if (s->unk8 == ev->unk0) {
            s->unk8 = ev->unk4;
            s->unkC = ev->unk9;
        } else if (s->unk8 == ev->unk4) {
            s->unk8 = ev->unk0;
            s->unkC = ev->unk8;
        }
        lbl:;
    } else if (arg2 == 0x43) {
        e43 = arg1;
        if ((s->unk0 == e43->unk0 || s->unk4 == e43->unk4) && s->unkD == e43->unk5) {
            func_1516972C(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFB80.s")

struct func_150EFEC8_s {
    void *unk0;
    u8 unk4;
    u8 unk5;
    void *unk8;
};

struct func_150EFEC8_a {
    s8 unk0;
    s8 unk1;
    s16 unk2;
    s16 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    s32 unk40;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
    s32 unk48;
    u8 pad4C[0x58 - 0x4C];
};

struct func_150EFEC8_b {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    s16 unk52;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u8 unk58;
    s8 unk59;
};

extern s8 (*D_8008FD00)();
extern f32 D_800A1830;
extern f32 D_800A1834;
void *func_151407D0(void *arg0, s32 arg1, void *arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, s8 arg7, u8 arg8, s32 arg9);

void *func_150EFEC8(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, void *arg5, u8 arg6, s32 arg7) {
    void *ret;
    struct func_150EFEC8_b b;
    struct func_150EFEC8_a a;
    struct func_150EFEC8_s s;

    s.unk0 = arg0;
    s.unk4 = arg0[0x3B];
    s.unk5 = arg1;
    s.unk8 = arg5;
    a.unk0 = D_8008FD00();
    a.unk1 = 3;
    a.unk2 = 0x2203;
    a.unk4 = 0x12C;
    a.unk8 = 0;
    a.unkC = 0;
    a.unk10 = arg2;
    a.unk11 = arg3;
    a.unk12 = arg4;
    a.unk13 = 0xFF;
    a.unk18 = 100.0f;
    a.unk14 = 100.0f;
    a.unk1C = 0.0f;
    a.unk20 = 0.0f;
    a.unk24 = 0.0f;
    a.unk28 = 0.0f;
    a.unk2C = 0.0f;
    a.unk30 = 0.0f;
    a.unk34 = 1.0f;
    a.unk38 = 1.0f;
    a.unk3C = 1.0f;
    a.unk40 = 0xCD2002;
    a.unk44 = 0xFF;
    a.unk45 = 0xFF;
    a.unk46 = 0;
    a.unk47 = 6;
    a.unk48 = 0;
    b.unk4 = 160.0f;
    b.unk0 = 160.0f;
    b.unkC = 80.0f;
    b.unk8 = 80.0f;
    b.unk10 = 0.5f;
    b.unk14 = 0.5f;
    b.unk18 = 1.0f;
    b.unk1C = D_800A1830;
    b.unk20 = D_800A1834;
    b.unk24 = -1;
    b.unk34 = -1;
    b.unk28 = -1;
    b.unk38 = -1;
    b.unk2C = -1;
    b.unk3C = -1;
    b.unk30 = -1;
    b.unk40 = -1;
    b.unk44 = 0;
    b.unk48 = 1.0f;
    b.unk4C = 0;
    b.unk4E = 0;
    b.unk50 = 0;
    b.unk52 = 0;
    b.unk54 = 0xFF;
    b.unk55 = 0xFF;
    b.unk56 = 0xFF;
    b.unk57 = 0xFF;
    b.unk58 = 0xA;
    b.unk59 = -1;
    ret = func_151407D0(&b, 0x6C, &a, 0x1E, 0, 0, 0, -1, arg6, arg7);
    if (ret != NULL) {
        memcpy((u8 *)ret + 0x170, &s, 0xC);
    }
    return ret;
}

typedef struct { f32 x, y, z; } func_150F00EC_v3;

struct func_150F00EC_sub {
    u8 pad0[0x18];
    u8 unk18;
    u8 pad19[0x30 - 0x19];
    func_150F00EC_v3 unk30;
};

struct func_150F00EC_obj2 {
    u8 pad0[0x34];
    func_150F00EC_v3 unk34;
    u8 pad40[0x110 - 0x40];
    struct func_150F00EC_sub unk110;
};

struct func_150F00EC_s {
    u8 pad0[0x34];
    func_150F00EC_v3 unk34;
    func_150F00EC_v3 unk40;
    u8 pad4C[0x58 - 0x4C];
    s32 unk58;
    u8 pad5C[0x178 - 0x5C];
    struct func_150F00EC_obj2 *unk178;
};

s32 func_150F00EC(struct func_150F00EC_s *arg0) {
    struct func_150F00EC_obj2 *o = arg0->unk178;
    struct func_150F00EC_sub *s;

    s = &o->unk110;
    if (s->unk18 & 1) {
        arg0->unk34 = o->unk34;
        arg0->unk40.x = o->unk34.x + s->unk30.x * 500.0f;
        arg0->unk40.y = o->unk34.y + s->unk30.y * 500.0f;
        arg0->unk40.z = o->unk34.z + s->unk30.z * 500.0f;
        arg0->unk58 |= 6;
    } else {
        arg0->unk58 &= ~4;
        arg0->unk58 &= ~2;
    }
    return 1;
}

struct225 *func_151602C0();

struct225 *func_150F0198(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4, u8 arg5, s32 arg6) {
    struct225 *temp_v0;
    Header header;
    Header2 header2;
    s32 tmp;

    tmp = arg4;
    header.unk0 = 2;
    header.unk1 = -1;
    header.unk2 = 300;
    header.unk4 = 0x21;
    header2.unk0 = 0;
    header2.unk4 = 0;
    header2.unk8 = 0;
    temp_v0 = func_151602C0(&header, &header2, arg0, arg1, arg2, arg3, 0xFF, 0, sizeof(tmp), arg5, arg6);
    if (temp_v0 != NULL) {
        memcpy(&temp_v0->unk18, &tmp, sizeof(tmp));
    }
    return temp_v0;
}

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

struct func_150F07E4_s {
    s32 unk0;
    u8 unk4;
};

struct func_150F07E4_a1 {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_150F07E4(struct102 *arg0, struct func_150F07E4_a1 *arg1, u8 arg2) {
    struct func_150F07E4_s *temp;
    s32 cur;
    s32 val;

    temp = *(struct func_150F07E4_s **)((u8 *)arg0 + 0x60);
    if (arg2 == 0) {
        cur = arg1->unk0;
        if ((cur == temp->unk0) || (((struct func_150F07E4_s *)arg1)->unk4 == temp->unk4)) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        val = arg1->unk0;
        if (val == temp->unk0) {
            temp->unk0 = arg1->unk4;
            temp->unk4 = arg1->unk9;
        } else if (temp->unk0 == arg1->unk4) {
            temp->unk0 = val;
            temp->unk4 = arg1->unk8;
        }
    }
}

struct func_150F088C_s {
    s32 unk0;
    u8 unk4;
};

struct func_150F088C_m {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

struct func_150F088C_o {
    u8 pad0[0x170];
    struct func_150F088C_s unk170;
};

void func_150F088C(struct func_150F088C_o *arg0, void *arg1, u8 arg2) {
    struct func_150F088C_s *p = &arg0->unk170;
    struct func_150F088C_m *m;
    s32 b;

    if (arg2 == 0) {
        b = ((struct func_150F088C_s *)arg1)->unk0;
        if ((b == p->unk0) || (((struct func_150F088C_s *)arg1)->unk4 == p->unk4)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        m = arg1;


        if (p->unk0 == m->unk0) {
            p->unk0 = m->unk4;
            p->unk4 = m->unk9;
        } else if (p->unk0 == m->unk4) {
            p->unk0 = m->unk0;
            p->unk4 = m->unk8;
        }
    }
}

void *func_15160A58();
extern u8 D_800A1674[];
extern u8 D_800A1680[];

void func_150F0938(void *arg0) {
    func_15160A58(arg0, 0x25, D_800A1674, 2, 0x12C, 4, 0, 0xFF, 0, 0xFF, 0, -1, 0, 0, 0xFF, 1);
    func_15160A58(arg0, 2, D_800A1680, 2, 0x12C, 0xD, 0xFF, 0xFF, 0xFF, 0xFF, 0, -1, 0, 0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0BEC.s")

extern f32 D_800A1870;
extern f32 D_800A1874;

struct func_150F0E48_s {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x3B - 0x20];
    u8 unk3B;
};

struct func_150F0E48_sub {
    struct func_150F0E48_s *unk0;
    u8 unk4;
    u8 pad5[3];
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

struct func_150F0E48_o {
    u8 pad0[0x2B];
    u8 unk2B;
    u8 pad2C[0x38 - 0x2C];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    u8 pad4C[0xA8 - 0x4C];
    struct func_150F0E48_sub unkA8;
};

s32 func_150F0E48(struct func_150F0E48_o *arg0, s32 arg1) {
    struct func_150F0E48_sub *s;
    struct func_150F0E48_s *p;

    s = &arg0->unkA8;
    p = arg0->unkA8.unk0;
    if (p->unk3B != arg0->unkA8.unk4) {
        return 0;
    }
    arg0->unk40 = p->unk14;
    arg0->unk44 = p->unk18;
    arg0->unk48 = p->unk1C;
    s->unk8 += D_800A1870 * D_800BE9A4;
    s->unkC += D_800A1874 * D_800BE9A4;
    s->unk10 += 0.25f * D_800BE9A4;
    s->unk8 = func_15144B68(s->unk8);
    s->unkC = func_15144B68(s->unkC);
    s->unk10 = func_15144B68(s->unk10);
    arg0->unk38 = sinf(s->unk8) * 243.0f + 780.0f;
    arg0->unk3C = sinf(s->unkC) * 243.0f + 780.0f;
    arg0->unk2B = sinf(s->unk10) * 50.0f + 200.0f;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1020.s")

struct func_150F10D4_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

void func_150F10D4(u8 *arg0) {
    struct func_150F10D4_s sp40;
    struct260 *temp_v0;

    sp40.unk0 = arg0;
    sp40.unk4 = arg0[0x3B];
    sp40.unk8 = 0.0f;
    sp40.unkC = *(f32 *)(arg0 + 0x14);
    sp40.unk10 = *(f32 *)(arg0 + 0x18);
    sp40.unk14 = *(f32 *)(arg0 + 0x1C);
    temp_v0 = func_15149130(0x12C, -1, 0x4C, -1, 0, 0x3A, (struct37 *)0x18, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp40, 0x18);
    }
}

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

struct func_150F1A00_s {
    u16 v[3];
};
extern struct func_150F1A00_s D_80088B00;
extern f32 D_800A18E8;
extern f32 D_800A18EC;
extern f32 D_800A18F0;
extern f32 cosf(f32);

void func_150F1A00(u8 *arg0) {
    s32 t;
    struct func_150F1A00_s sp3C;
    s32 idx;
    s32 flags;
    f32 scale;
    f32 (*m)[4];
    s32 i;
    s32 j;

    sp3C = D_80088B00;
    idx = 0;
    flags = *(s32 *)(arg0 + 0x2E4);
    if ((flags & 3) == 3) {
        idx = 1;
    }
    if ((flags & 0xC) == 0xC) {
        idx = 2;
    }
    t = sp3C.v[idx];
    ((s16 *)&D_800CC298)[10] += t * D_800BE9E4;
    scale = ((cosf(((s16 *)&D_800CC298)[10] * D_800A18E8) + 1.0f) * 0.5f * D_800A18EC) + D_800A18F0;
    m = (f32 (*)[4])(*(u8 **)(arg0 + 0x1D4) + 0xF80);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            m[i][j] *= scale;
        }
    }
}

extern f32 D_800A18F4;
extern f32 D_800A18F8;
extern u8 D_800CC354[];

struct func_150F1B48_s {
    u8 pad0[0x12];
    s16 unk12;
};

s16 *func_150F1B48(s16 *arg0, s32 arg1) {
    s32 flag;
    s32 delta;
    s32 temp;
    s32 i;

    flag = (*(u16 *)(D_800CC354 + arg1 * 0x32C) == 0x21) ? 1 : 0;
    delta = D_800BE9E4 * 0x222;
    if (flag) {
        temp = ((struct func_150F1B48_s *)&D_800CC298)->unk12 - delta;
        if (D_800A18F4 < temp) {
            ((struct func_150F1B48_s *)&D_800CC298)->unk12 = temp;
        } else {
            ((struct func_150F1B48_s *)&D_800CC298)->unk12 = -0x1999;
        }
    } else {
        temp = ((struct func_150F1B48_s *)&D_800CC298)->unk12 + delta;
        if (temp < D_800A18F8) {
            ((struct func_150F1B48_s *)&D_800CC298)->unk12 = temp;
        } else {
            ((struct func_150F1B48_s *)&D_800CC298)->unk12 = 0x1555;
        }
    }
    for (i = 0; i < 6; i++) {
        arg0[0] = 0xB2 + i * 6;
        arg0[1] = ((struct func_150F1B48_s *)&D_800CC298)->unk12;
        arg0 += 2;
    }
    return arg0;
}

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

extern u8 D_800D98F0;
extern f32 D_800A191C;

void func_150F20F0(s32 arg0) {
    f32 x;
    f32 z;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    f32 dist;

    x = gObjects[arg0].x_position;
    z = gObjects[arg0].z_position;
    x = x * x;
    z = z * z;
    x = (x * x) + (z * z);
    if (D_800D98F0 != 0) {
        if (D_800BE9E4 < D_800D98F0) {
            D_800D98F0 -= D_800BE9E4;
        } else {
            D_800D98F0 = 0;
        }
    } else if (D_800A191C < x) {
        func_100114D0(0, (s32)gObjects[arg0].y_position, 0, 0x7FFF, 20000, 19000, &sp4C, &sp48, &sp44);
        sp4C += 0x80;
        D_800D98F0 = (func_150ADA20() & 0x7F) + 0x80;
        func_10010F30(((u32)func_150ADA20() % 3) + 0x6C, 0x5DC0, sp4C, 0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F2230.s")
