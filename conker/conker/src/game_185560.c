#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151580B0.s")

void *func_151580B0(void *, s32, s32, u8, s32, u8, s32);

void func_151581D8(void *arg0, u8 arg1, s32 arg2, u8 arg3, s32 arg4) {
    func_151580B0(arg0, 0, 0, arg1, arg2, arg3, arg4);
}

extern s32 (*D_8008AE00[])(void);

void func_15158224(struct102 *arg0) {
    s32 idx;
    u8 var_v1 = 0;

    if (((u8 *)arg0)[0x10] & 1) {
        *(s16 *)((u8 *)arg0 + 0x14) -= D_800BE9E4;
        if (*(s16 *)((u8 *)arg0 + 0x14) < 0) {
            var_v1 = 1;
        }
    }
    if (!var_v1) {
        idx = *(s8 *)((u8 *)arg0 + 0x12);
        if (idx != -1) {
            if (!D_8008AE00[idx]()) {
                var_v1 = 1;
            }
        }
    }
    if (var_v1) {
        func_1516972C(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151582C8.s")

struct func_1515858C_s {
    u8 pad0[0x48];
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    u8 pad54[0xF8 - 0x54];
    f32 unkF8[4];
};

s32 func_1515858C(Mtx *arg0, struct func_1515858C_s *arg1) {
    f32 *rot;
    f32 mf[4][4];

    rot = arg1->unkF8;
    func_150A8050(mf, rot[0], rot[1], rot[2]);
    mf[3][0] = arg1->unk48;
    mf[3][1] = arg1->unk4C;
    mf[3][2] = arg1->unk50;
    mf[0][0] *= rot[3];
    mf[0][1] *= rot[3];
    mf[0][2] *= rot[3];
    mf[1][0] *= rot[3];
    mf[1][1] *= rot[3];
    mf[1][2] *= rot[3];
    mf[2][0] *= rot[3];
    mf[2][1] *= rot[3];
    mf[2][2] *= rot[3];
    guMtxF2L(mf, arg0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158684.s")

struct func_15158920_arg_s {
    u8 pad0[0x48];
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    u8 pad54[0xF8 - 0x54];
    f32 unkF8;
};

union func_15158920_s {
    f32 m[4][4];
    s64 force_align;
};

extern union func_15158920_s D_8008AE18;
extern f32 D_800A6070;

s32 func_15158920(Mtx *arg0, struct func_15158920_arg_s *arg1) {
    f32 scale;
    union func_15158920_s mf;

    mf = D_8008AE18;
    scale = arg1->unkF8 * D_800A6070;
    mf.m[3][0] = arg1->unk48;
    mf.m[3][1] = arg1->unk4C;
    mf.m[3][2] = arg1->unk50;
    mf.m[0][0] *= scale;
    mf.m[0][1] *= scale;
    mf.m[0][2] *= scale;
    mf.m[1][0] *= scale;
    mf.m[1][1] *= scale;
    mf.m[1][2] *= scale;
    mf.m[2][0] *= scale;
    mf.m[2][1] *= scale;
    mf.m[2][2] *= scale;
    guMtxF2L(mf.m, arg0);
    return 1;
}

struct func_15158A20_s {
    u8 pad0[0xE0];
    s32 unkE0[4];
    s32 unkF0;
};

void func_15158A20(struct func_15158A20_s *arg0) {
    s32 i;

    for (i = 0; i <= D_80082FA0; i++) {
        if (arg0->unkE0[i] != 0) {
            func_100043B4((void *)arg0->unkE0[i], 4);
        }
    }
    if (arg0->unkF0 != 0) {
        func_100043B4((void *)arg0->unkF0, 4);
    }
}

void func_15158AA4(s32 arg0) {
    func_15158A20(arg0);
    func_15169804(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158AD0.s")

struct func_15158AFC_s {
    u8 pad0[0x14];
    s16 unk14;
    u8 pad16[0x3B - 0x16];
    u8 unk3B;
    u8 pad3C[0xF8 - 0x3C];
    s16 unkF8;
    u8 padFA[2];
    u32 unkFC;
};

s32 func_15158AFC(struct func_15158AFC_s *arg0) {
    s32 temp;

    if (arg0->unk14 < arg0->unkF8) {
        temp = arg0->unk14 * arg0->unkFC;
        if (temp < arg0->unk3B) {
            arg0->unk3B = temp;
        }
    }
    return 1;
}

struct func_15158B3C_s {
    u8 pad0[0x40];
    s32 unk40;
    u8 unk44;
};

struct func_15158B3C_a {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_15158B3C(struct func_15158B3C_s *arg0, struct func_15158B3C_a *arg1, u8 arg2) {
    s32 temp;

    if (arg2 == 0x2D) {
        temp = arg1->unk0;
        if (temp == arg0->unk40) {
            arg0->unk40 = arg1->unk4;
            arg0->unk44 = arg1->unk9;
            return;
        }
        if (arg0->unk40 == arg1->unk4) {
            arg0->unk40 = temp;
            arg0->unk44 = arg1->unk8;
        }
end:
        return;
    }
    if (arg2 != 0) {
        goto end;
    }
    temp = arg1->unk0;
    if (temp == arg0->unk40 || arg0->unk44 == *(u8 *)&arg1->unk4) {
        arg0->unk40 = 0;
        arg0->unk44 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158BD0.s")

void func_15158CD4(struct225 *arg0) {
    func_1514EDF0(arg0, arg0->unk18);
    func_15169804(arg0);
}

struct func_15158D00_s {
    char pad0[0x18];
    s32 unk18;
};

void func_15158D00(struct func_15158D00_s *arg0) {
    func_1514EDF0(arg0, arg0->unk18);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158FA4.s")

extern f32 D_800A63A0;

struct func_15159084_s {
    u8 pad0[0x18];
    f32 unk18;
    u8 pad1C[0x118 - 0x1C];
    f32 unk118;
    u8 pad11C[0x137 - 0x11C];
    u8 unk137;
    u8 pad138[0x184 - 0x138];
    s32 unk184;
};

s32 func_15159084(struct func_15159084_s *arg0, u8 arg1) {
    s32 flags = arg0->unk184 & 0x1F;
    s32 ret;

    if (arg1 == 2 || arg1 == 3) {
        ret = 0;
    } else if (D_800A63A0 == arg0->unk118 && !(flags & 0xA)) {
        ret = 1;
    } else if (arg0->unk118 < arg0->unk18 || arg0->unk137) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

struct func_15159120_s {
    u8 pad0[0x118];
    f32 unk118;
    u8 pad11C[0x180 - 0x11C];
    f32 unk180;
};

s32 func_15159120(struct func_15159120_s *arg0, u8 arg1) {
    s32 ret;

    if ((arg1 == 2) || (arg1 == 3)) {
        ret = 1;
    } else if (arg0->unk180 < (arg0->unk118 - 35.0f)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

struct func_15159184_s {
    u8 pad0[0x18];
    f32 unk18;
    u8 pad1C[0x118 - 0x1C];
    f32 unk118;
};

s32 func_15159184(struct func_15159184_s *arg0, u8 arg1) {
    s32 ret;

    if ((arg1 == 2) || (arg1 == 3)) {
        if (D_800C35EA != 1) {
            ret = 0;
        } else if ((arg0->unk118 - 75.0f) < arg0->unk18) {
            ret = 1;
        } else {
            ret = 0;
        }
    } else if ((arg0->unk118 - 75.0f) < arg0->unk18) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

struct func_15159230_s {
    f32 x;
    f32 y;
    f32 z;
};

s32 func_15159230(void *arg0, struct func_15159230_s *arg1, u8 arg2) {
    s32 ret;

    if ((arg1->x != ((f32 *)arg0)[5]) || (arg1->y != ((f32 *)arg0)[6]) || (arg1->z != ((f32 *)arg0)[7])) {
        if ((arg2 == 1) || (arg2 == 2)) {
            ret = 2;
        } else {
            ret = 1;
        }
    } else {
        ret = 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151592B8.s")

struct func_15159370_s {
    u8 pad0[4];
    u8 unk4;
    u8 unk5;
    u8 pad6[0x3B - 6];
    u8 unk3B;
};

s32 func_15159370(struct func_15159370_s *arg0, u8 *arg1) {
    s32 ret = 0;

    if (D_800BE616) {
        *arg1 = 0;
        ret = 1;
    }
    if (arg0->unk3B == 1) {
        *arg1 = 0;
        ret = 1;
    }
    if ((arg0->unk5 == 5) || (arg0->unk5 == 2)) {
        *arg1 = 1;
        ret = 1;
    }
    switch (arg0->unk4) {
    case 8:
        *arg1 = 2;
        ret = 1;
        break;
    case 10:
        *arg1 = 3;
        ret = 1;
        break;
    case 0x29:
    case 0x2A:
        *arg1 = 4;
        ret = 1;
        break;
    }
    return ret;
}

struct func_1515942C_s {
    u8 pad0[0x2C];
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    u8 unk30;
};

struct func_1515942C_s2 {
    u8 pad0[0x10];
    struct func_1515942C_s *unk10;
};

extern s32 func_1514ECE0(s32, s32, struct func_1515942C_s2 **);

u8 func_1515942C(u8 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    struct func_1515942C_s *s;
    struct func_1515942C_s2 *sp38;
    u8 ret = 0;
    s32 m1, m2, m3, m4, m5;
    s32 mask;
    s32 bits;

    if (!func_1514ECE0(*(s32 *)(arg0 + 0x2F4), 0x13, &sp38)) {
        return 0;
    }
    s = sp38->unk10;
    m4 = (arg4 == -1) ? 0x1E00 : (1 << (arg4 + 9));
    m3 = (arg3 == -1) ? 0x1C0 : (1 << (arg3 + 6));
    m2 = (arg2 == -1) ? 0x38 : (1 << (arg2 + 3));
    m1 = (arg1 == -1) ? 7 : (1 << arg1);
    m5 = (arg5 == -1) ? 0x3E000 : (1 << (arg5 + 13));
    mask = m5 | m1 | m2 | m3 | m4;
    bits = (1 << s->unk2C) | (1 << (s->unk2D + 3)) | (1 << (s->unk2E + 6)) | (1 << (s->unk2F + 9)) | (1 << (s->unk30 + 13));
    if ((mask | bits) == mask) {
        ret = 1;
    }
    return ret;
}

struct func_15159594_s {
    u8 unk0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x33];
    f32 unk40;
    s32 unk44;
    f32 unk48;
    f32 unk4C;
    u8 pad50[4];
    f32 unk54;
    u8 pad58[4];
    f32 unk5C;
    u8 pad60[0x20];
    f32 unk80;
    u8 unk84[0x19];
    u8 unk9D;
    u8 pad9E[0xA];
    f32 unkA8;
};

s32 func_151596BC(struct func_15159594_s *, f32 *);
s32 func_1514672C(f32 *);
s32 func_15046C00(f32 *, s32, s32, f32 *);
extern f32 D_800A63A4;

u8 func_15159594(struct func_15159594_s *arg0, f32 *arg1) {
    volatile u8 ret = 1;
    f32 vec[4];

    if (func_151596BC(arg0, arg1) != 0) {
        if (arg0->unk5C > 0.0f) {
            vec[0] = arg0->unk40 + arg0->unk4C;
            vec[1] = arg1[1];
            vec[2] = arg0->unk48 + arg0->unk54;
            if (!func_1514672C(vec)) {
                return 0;
            }
            if (func_15046C00(vec, 0, arg0->unk44, &arg0->unk80)) {
                vec[1] = arg0->unk80;
                if (arg0->unk9D == 3) {
                    func_151DBCBC(func_151D8E20(), arg0->unkA8 * D_800A63A4, 0xFF, arg0->unk84, vec, arg0->unkC, arg0->unk1);
                }
                ret = 0;
                return ret;
            }
        }
    } else {
        ret = 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151596BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159890.s")

s32 func_15159890(f32 *arg0, f32 *arg1, s32 arg2, s32 arg3);

void func_15159BB0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6) {
    f32 sp24[3];
    f32 sp18[3];

    sp24[0] = arg0;
    sp24[1] = arg1;
    sp18[0] = 0.0f;
    sp18[1] = 0.0f;
    sp18[2] = 0.0f;
    sp24[2] = arg2;
    func_15159890(sp24, sp18, arg6[0xC], arg6[1]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A11C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A238.s")

struct func_1515A60C_s {
    f32 unk0;
    u8 unk4;
    u8 unk5;
    s8 unk6;
    s8 unk7;
    f32 unk8;
    f32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

s32 func_1515A60C(void *arg0, void *arg1) {
    s32 i;
    struct func_1515A60C_s *s = (struct func_1515A60C_s *)((u8 *)arg0 + 0xA8);

    *(f32 *)((u8 *)arg0 + 0x38) = func_151423D8(s->unk4 - 0x40) * s->unk8 + s->unk0;
    *(f32 *)((u8 *)arg0 + 0x3C) = func_151423D8(s->unk5 - 0x40) * s->unkC + s->unk0;
    *(f32 *)((u8 *)arg0 + 0x4C) = func_151423D8(s->unk10 - 0x40) * s->unk14;
    *(f32 *)((u8 *)arg0 + 0x54) = func_151423D8(s->unk11 - 0x40) * s->unk18;
    s->unk4 += s->unk6 * D_800BE9E4;
    s->unk5 += s->unk7 * D_800BE9E4;
    s->unk10 += s->unk12 * D_800BE9E4;
    s->unk11 += s->unk13 * D_800BE9E4;
    for (i = D_800BE9E4; i > 0; i--) {
        *(f32 *)((u8 *)arg0 + 0x58) *= s->unk1C;
        *(f32 *)((u8 *)arg0 + 0x5C) *= s->unk1C;
        *(f32 *)((u8 *)arg0 + 0x60) *= s->unk1C;
    }
    return 1;
}

struct func_1515A78C_s {
    u8 unk0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x1E];
    u8 unk2B;
    u8 pad2C[0x14];
    f32 unk40;
    union { s32 i; f32 f; } unk44;
    f32 unk48;
    f32 unk4C;
    u8 pad50[4];
    f32 unk54;
    u8 pad58[4];
    f32 unk5C;
    u8 pad60[0x20];
    f32 unk80;
    u8 unk84[0x19];
    u8 unk9D;
    u8 pad9E[0xA];
    f32 unkA8[9];
};

extern f32 D_800A6408;
extern f32 D_800A640C;
extern f32 D_800A6410;
s32 func_1515A60C(void *arg0, void *arg1);

u8 func_1515A78C(struct func_1515A78C_s *arg0, f32 *arg1) {
    f32 *s = (f32 *)((u8 *)arg0 + 0xA8);
    volatile u8 ret = 1;
    f32 vec[3];

    func_1515A60C(arg0, arg1);
    if (arg0->unk5C < 0.0f) {
        return 1;
    }
    vec[0] = arg0->unk40 + arg0->unk4C;
    vec[1] = arg1[1];
    vec[2] = arg0->unk48 + arg0->unk54;
    if (D_800A6408 == s[8]) {
        if (!func_1514672C(vec)) {
            return 0;
        }
        if (func_15046C00(vec, 0, arg0->unk44.i, &arg0->unk80)) {
            vec[1] = arg0->unk80;
            ret = 0;
        }
    } else if (s[8] <= arg0->unk44.f) {
        vec[1] = s[8];
        ret = 0;
    }
    if (ret == 0 && func_150ADA68() < D_800A640C && arg0->unk9D == 3) {
        func_151DBCBC(func_151D8E20(), *s * D_800A6410, arg0->unk2B, arg0->unk84, vec, arg0->unkC, arg0->unk1);
    }
    return ret;
}

extern s32 func_1514ECE0();

s32 func_1515A920(u8 *arg0, s32 *arg1) {
    u8 *sp1C;
    s32 temp;

    if (func_1514ECE0(*(s32 *)(arg0 + 0x2F4), 0x13, &sp1C) == 0) {
        return 0;
    }
    temp = *(s32 *)(sp1C + 0x10);
    *arg1 = temp + 0x34;
    return 1;
}

struct func_1515A974_c {
    u8 b[4];
};

struct func_1515A974_d {
    s32 w[10];
};

struct func_1515A974_s {
    struct func_1515A974_c c;
    struct func_1515A974_d d;
};

struct func_1515A974_l {
    struct func_1515A974_c c;
    struct func_1515A974_d d;
    s32 pad[2];
};

struct func_1515A974_e {
    f32 x;
    f32 y;
    struct func_1515A974_s s;
};

struct func_1515A974_p {
    s8 unk0;
    void *unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    s8 unk24;
    s8 unk25;
    s8 unk26;
};

extern struct func_1515A974_e D_800A636C[];
extern s32 func_151A8B20();
extern void *memcpy(void *, const void *, s32);

void func_1515A974(u8 *arg0, s32 arg1) {
    struct func_1515A974_p sp60;
    struct func_1515A974_e *e;
    s32 ret;
    struct func_1515A974_s sp2C;
    s32 idx;

    idx = arg0[0x1F];
    if (idx > 0) {
        return;
    }
    {
        e = &D_800A636C[idx];
        sp60.unk0 = 0xF;
        sp60.unk4 = arg0;
        sp60.unk8 = e->x;
        sp60.unkC = e->y;
        sp60.unk10 = 0.0f;
        sp60.unk14 = 0.0f;
        sp60.unk18 = 0.0f;
        sp60.unk1C = 0.0f;
        sp60.unk20 = 0.0f;
        sp60.unk24 = 0;
        sp60.unk25 = -1;
        sp60.unk26 = 2;
        sp2C.c = e->s.c;
        sp2C.d = e->s.d;
        ret = func_151A8B20(&sp60, -1, 0x2C, 0xFF, 0);
        if (ret != 0) {
            memcpy((void *)(ret + 0x80), &sp2C, 0x2C);
        }
    }
}

struct func_1515AA84_v { f32 x, y, z; };
struct func_1515AA84_b { s32 w[10]; };
struct func_1515AA84_r { s16 lo; s16 range; };
struct func_1515AA84_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xC - 0x2];
    u8 unkC;
    u8 padD[0x80 - 0xD];
    struct func_1515AA84_r unk80;
    struct func_1515AA84_b unk84;
};
struct func_1515AA84_l {
    f32 unk0;
    struct func_1515AA84_v unk4;
    f32 unk10;
    struct func_1515AA84_b unk14;
};

void func_1515AA84(struct func_1515AA84_s *arg0, struct func_1515AA84_v *arg1, f32 arg2, s32 arg3) {
    struct func_1515AA84_l sp44;
    struct260 *temp_v0;
    struct func_1515AA84_r *r;

    sp44.unk0 = 0.0f;
    sp44.unk4 = *arg1;
    sp44.unk10 = arg2;
    sp44.unk14 = arg0->unk84;
    r = &arg0->unk80;
    temp_v0 = func_15149130((func_150ADA20() % (u32)(r->range + 1)) + r->lo, -1, 0x3F, -1, 1, 0, (struct37 *)0x3C, arg0->unkC, arg0->unk1);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp44, 0x3C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515AB88.s")
