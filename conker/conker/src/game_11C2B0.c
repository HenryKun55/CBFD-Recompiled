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

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFEC8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0E48.s")

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
