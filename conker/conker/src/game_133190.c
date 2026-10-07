#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15105CE0.s")

struct func_1510608C_v { s32 x, y, z; };
struct func_1510608C_o { u8 pad0[0x40]; struct func_1510608C_v pos; };
struct func_1510608C_s {
    u8 pad0[0x10];
    s16 unk10;
    u8 unk12;
    u8 pad13;
    struct func_1510608C_v unk14;
    u8 pad20[0x38 - 0x20];
    struct func_1510608C_v unk38;
    s8 unk44;
    u8 pad45[0x54 - 0x45];
    s16 unk54;
    s16 unk56;
    u8 pad58[0x68 - 0x58];
    s16 unk68;
    u8 pad6A[2];
    struct func_1510608C_o *unk6C;
    struct func_1510608C_o *unk70;
};
extern s32 (*D_80088C10[])(struct func_1510608C_s *, u8 *);
void func_15106214(struct func_1510608C_s *);
void func_15106610(struct func_1510608C_s *);

void func_1510608C(struct func_1510608C_s *arg0) {
    s32 (*f)(struct func_1510608C_s *, u8 *);
    u8 sp2B;

    sp2B = 0;

    if (arg0->unk44 != -1) {
        f = D_80088C10[arg0->unk44];
        if (f != NULL) {
            if (f(arg0, &sp2B) == 0) {
                func_1516972C((struct102 *)arg0);
            }
        }
    }
    if (arg0->unk12 & 1) {
        arg0->unk10 -= D_800BE9E4;
        if (arg0->unk10 < 0) {
            func_1516972C((struct102 *)arg0);
        }
    }
    if (sp2B) {
        func_15106214(arg0);
    }
    arg0->unk68 -= D_800BE9E4;
    if (arg0->unk68 < 0) {
        func_15106610(arg0);
        arg0->unk68 = (u32)func_150ADA20() % (arg0->unk56 + 1) + arg0->unk54;
    }
    if (arg0->unk6C != NULL) {
        arg0->unk6C->pos = arg0->unk14;
    }
    if (arg0->unk70 != NULL) {
        arg0->unk70->pos = arg0->unk38;
    }
}

void *func_151061E0(u8 *arg0) {
    return arg0 + 0x88;
}

struct func_151061EC_s {
    u8 pad0[0x48];
    s32 unk48;
    u8 pad4C[0x88 - 0x4C];
    u8 unk88[1][0x34];
};

void *func_151061EC(struct func_151061EC_s *arg0) {
    s32 idx = arg0->unk48;
    return &arg0->unk88[idx];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106214.s")

f32 func_151064B4(f32 arg0) {
    f32 temp = 1.0f - arg0;
    return temp * temp * temp;
}

f32 func_151064DC(f32 t) {
    f32 u = 1.0f - t;
    return 3.0f * t * u * u;
}

f32 func_15106510(f32 arg0) {
    return 3.0f * arg0 * arg0 * (1.0f - arg0);
}

f32 func_15106540(f32 x) {
    return x * x * x;
}

f32 func_15106558(f32 arg0) {
    f32 t = 1.0f - arg0;
    return -3.0f * t * t;
}

f32 func_15106584(f32 arg0) {
    return ((9.0f * arg0 * arg0) - (12.0f * arg0)) + 3.0f;
}

f32 func_151065BC(f32 arg0) {
    return (-9.0f * arg0 * arg0) + (6.0f * arg0);
}

f32 func_151065EC(f32 arg0) {
    return 3.0f * arg0 * arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151067B8.s")

extern void (*D_80088C18[])(s32);
void func_151D5E30(void *);

void func_15106E78(s32 arg0) {
    void (*f)(s32) = D_80088C18[((u8 *)arg0)[0x5C]];

    if (f != NULL) {
        f(arg0);
    }
    if (*(struct102 **)(arg0 + 0x6C) != NULL) {
        func_1516972C(*(struct102 **)(arg0 + 0x6C));
    }
    if (*(struct102 **)(arg0 + 0x70) != NULL) {
        func_1516972C(*(struct102 **)(arg0 + 0x70));
    }
    func_151D5E30((void *)(arg0 + 0x74));
}

void func_15106E78(s32 arg0);
void func_15169804(s32 arg0);

void func_15106EF8(s32 arg0) {
    func_15106E78(arg0);
    func_15169804(arg0);
}

void func_15106F24(s32 arg0) {
    func_15106E78(arg0);
    func_15169824(arg0);
}

extern void (*D_80088C28[])(u8 *, s32, u8);

void func_15106F50(u8 *arg0, s32 arg1, u8 arg2) {
    void (*func)(u8 *, s32, u8) = D_80088C28[arg0[0x5C]];

    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

struct func_15106F98_v { s32 x, y, z; };
struct func_15106F98_b { s32 data[12]; };
struct func_15106F98_s {
    s32 count;
    s32 unk4;
    s32 unk8;
    struct func_15106F98_v *pts;
    struct func_15106F98_b unk10;
    u8 unk40;
};

void func_151070F8(struct260 *arg0, s32 arg1, s16 arg2, s32 arg3);

struct260 *func_15106F98(struct func_15106F98_v *arg0, struct func_15106F98_v *arg1, s32 arg2, struct func_15106F98_b *arg3, s32 arg4, u8 arg5, u8 arg6, s32 arg7) {
    struct260 *ret;
    struct func_15106F98_s sp40;
    struct func_15106F98_s *s;

    sp40.count = (1 << arg2) + 1;
    sp40.unk8 = 0;
    sp40.unk4 = 0;
    sp40.unk10 = *arg3;
    sp40.unk40 = arg5;
    ret = func_15149130(0, -1, 0x3E, -1, 0, 0x30, (struct37 *)(sp40.count * 12 + 0x48), arg6, arg7);
    if (ret != NULL) {
        s = (struct func_15106F98_s *)((u8 *)ret + 0x28);
        memcpy(s, &sp40, 0x44);
        s->pts = (struct func_15106F98_v *)((u8 *)s + 0x48);
        s->pts[0] = *arg0;
        s->pts[sp40.count - 1] = *arg1;
        func_151070F8(ret, 0, sp40.count - 1, arg4);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151070F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151072BC.s")

struct func_15107604_s { u8 pad[0x28]; s32 unk28[3]; };
void func_15107604(s32 arg0) {
    struct func_15107604_s **pp = *(struct func_15107604_s ***)(arg0 + 0x60);
    s32 *p = (*pp)->unk28;
    p[2] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_1510761C.s")

void func_1510761C(void *arg0);

void func_1510764C(void *arg0) {
    func_1510761C(arg0);
    func_1514933C(arg0);
}

void func_15107678(s32 arg0) {
    func_1510761C(arg0);
    func_15149368(arg0);
}

struct func_151076A4_s {
    u8 pad[0x68];
    volatile u8 unk68;
};

extern void (*D_80088C38[])(struct func_151076A4_s *, s32, u8);

void func_151076A4(struct func_151076A4_s *arg0, s32 arg1, u8 arg2) {
    if (D_80088C38[arg0->unk68] != NULL) {
        D_80088C38[arg0->unk68](arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107700.s")

struct func_151078E4_s {
    u8 pad0[0x60];
    u8 *unk60;
};

void func_151078E4(struct func_151078E4_s *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0->unk60, arg0->unk60 + 4, arg0);
}

void func_15107A20();
void func_15107AE0();

typedef struct {
    f32 x, y, z;
} func_15107924_v3;

struct func_15107924_inner {
    s32 unk0;
    u8 pad4[0x3B - 4];
    u8 unk3B;
};

struct func_15107924_data {
    struct func_15107924_inner *unk0;
    u8 unk4;
    s16 unk6;
    s16 unk8;
};

struct func_15107924_s {
    u8 pad0[0x14];
    func_15107924_v3 unk14;
    func_15107924_v3 unk20;
    func_15107924_v3 unk2C;
    func_15107924_v3 unk38;
    u8 pad44[0x60 - 0x44];
    struct func_15107924_data *unk60;
};

s32 func_15107924(struct func_15107924_s *arg0, s8 *arg1) {
    struct func_15107924_data *data = arg0->unk60;
    struct func_15107924_inner *inner = data->unk0;
    func_15107924_v3 old;

    if (inner->unk0 == 0 || inner->unk3B != data->unk4) {
        return 0;
    }
    *arg1 = 0;
    old = arg0->unk14;
    func_15107A20(inner, data->unk6, data->unk8, &arg0->unk14, 0);
    if (old.x != arg0->unk14.x || old.y != arg0->unk14.y || old.z != arg0->unk14.z) {
        *arg1 = 1;
        func_15107AE0(&arg0->unk14, &arg0->unk38, &arg0->unk20, &arg0->unk2C);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107AE0.s")

struct func_15107B78_s {
    u8 pad0[0xF0];
    f32 unkF0;
    u8 padF4[0x1D4 - 0xF4];
    s32 unk1D4;
};

void func_1515C244();
void func_15143794();

void func_15107B78(struct func_15107B78_s *arg0, s16 arg1, s16 arg2, u8 arg3, s32 arg4) {
    f32 sp2C[3];
    f32 sp20[3];
    s32 sp1C;
    s32 sp18;

    if (arg0->unk1D4 != 0) {
        func_1515C244(arg0, sp20, &sp1C, &sp18);
        func_15143794(arg1, arg2, sp1C, sp2C);
        sp2C[1] *= arg0->unkF0;
        sp2C[0] += sp20[0];
        sp2C[1] += sp20[1];
        sp2C[2] += sp20[2];
        func_151C329C(sp2C, arg3, arg4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107C1C.s")

typedef struct { f32 x, y, z; } func_15107E48_v3;
struct func_15107E48_s2 {
    struct127 *unk0;
    u8 unk4;
    u8 pad5[3];
    u8 unk8[0xC];
    u8 unk14;
};
struct func_15107E48_s {
    u8 pad0[0x14];
    func_15107E48_v3 unk14;
    u8 unk20[0xC];
    u8 unk2C[0xC];
    u8 unk38[0x28];
    struct func_15107E48_s2 *unk60;
};
void func_15107F54(struct127 *arg0, u8 arg1, s32 arg2, s32 arg3);
void func_15107AE0(void *, void *, void *, void *);

s32 func_15107E48(struct func_15107E48_s *arg0, u8 *arg1) {
    struct func_15107E48_s2 *v = arg0->unk60;
    struct127 *s = v->unk0;
    func_15107E48_v3 old;

    if (s->interaction_state == 0 || s->unique_id != v->unk4) {
        return 0;
    }
    if (s->unk1D4 == 0) {
        return 0;
    }
    *arg1 = 0;
    old = arg0->unk14;
    func_15107F54(s, v->unk14, (s32)v->unk8, (s32)&arg0->unk14);
    if (old.x != arg0->unk14.x || old.y != arg0->unk14.y || old.z != arg0->unk14.z) {
        *arg1 = 1;
        func_15107AE0(&arg0->unk14, arg0->unk38, arg0->unk20, arg0->unk2C);
    }
    return 1;
}

void func_15107F54(struct127 *arg0, u8 arg1, s32 arg2, s32 arg3) {
    func_15143134(arg2, arg3, (s32) arg0->unk1D4 + (arg1 << 6));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107F98.s")
