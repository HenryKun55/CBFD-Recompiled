#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151A7950_v {
    f32 x, y, z;
    u8 pad[0xC];
};
struct func_151A7950_s {
    u8 pad0[0x12];
    s16 unk12;
    u8 pad14[0x60 - 0x14];
    struct func_151A7950_v *unk60;
    struct func_151A7950_v *unk64;
    f32 unk68;
    u8 unk6C[0x10];
    s32 unk7C;
    struct func_151A7950_v unk80[1];
};
struct func_151A7950_a {
    s16 unk0;
    s16 unk2;
};
void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);

struct func_151A7950_s *func_151A7950(struct func_151A7950_a *arg0, s32 arg1, u8 arg2, s32 arg3) {
    struct func_151A7950_s *obj;

    obj = func_15167A68(0x2D, arg3, arg0->unk2 * sizeof(struct func_151A7950_v) + arg1 + 0x80, 1, arg2, 1);
    if (obj == NULL) {
        return NULL;
    }
    memcpy((u8 *)obj + 0x10, arg0, 0x50);
    obj->unk64 = obj->unk80;
    obj->unk60 = obj->unk64 + arg0->unk2;
    obj->unk68 = 0.0f;
    obj->unk64[0].x = 0.0f;
    obj->unk64[0].y = 0.0f;
    obj->unk64[0].z = 0.0f;
    obj->unk64[arg0->unk2 - 1].x = 0.0f;
    obj->unk64[arg0->unk2 - 1].y = 0.0f;
    obj->unk64[arg0->unk2 - 1].z = 1.0f;
    bzero(obj->unk6C, 0x10);
    obj->unk7C = obj->unk12 * 64 + 0x140;
    return obj;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8340.s")

void *func_151D5E30();

void func_151A8560(void *arg0) {
    func_151D5E30((char *)(arg0) + 0x6C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A85D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A87F8.s")

extern void (*D_8008F964[])(u8 *, s32, u8);

void func_151A8A20(u8 *arg0, s32 arg1, u8 arg2) {
    s32 idx = arg0[0x5C];
    void (*fn)(u8 *, s32, u8);

    if (idx >= 3) {
        idx = 0;
    }
    fn = D_8008F964[idx];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

struct func_151A8A78_s {
    s32 a;
    u8 b;
};

void func_151A8A78(struct102 *arg0, struct223 *arg1, u8 arg2) {
    struct func_151A8A78_s *s = *(struct func_151A8A78_s **)((char *)arg0 + 0x60);
    s32 t;
    s32 u;

    if (arg2 == 0) {
        t = arg1->unk0;
        if (t == s->a || arg1->unk4.ub == s[0].b) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        u = arg1->unk0;
        if (u == s->a) {
            s->a = arg1->unk4.w;
            s->b = arg1->unk9;
        } else if (arg1->unk4.w == s[0].a) {
            s->a = u;
            s->b = arg1->unk8;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8CEC.s")

void func_151432BC(void *, f32 *, f32 *, f32 *, f32 *);

void func_151A8F1C(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    func_151432BC(*(void **)((char *)arg0 + 0x2C), arg1, arg1 + 2, arg2, arg3);
    arg1[1] = *arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8F6C.s")

void func_151A931C(u8 *arg0, s32 arg1, u8 arg2);

void func_151A9024(u8 *arg0, s32 arg1, u8 arg2) {
    if (arg0[0x4C] == 1) {
        func_151A931C(arg0, arg1, arg2);
    }
}

extern void (*D_8008F984[])(void *, s32);

s32 func_151A9060(u8 *arg0) {
    s32 idx;

    arg0[0x16] |= 4;
    idx = *(s32 *)(arg0 + 0x18);
    if (idx < 0 || idx >= 8) {
        return 1;
    }
    if (D_8008F984[idx] != NULL) {
        D_8008F984[idx](arg0, idx);
    }
    return 1;
}

extern f32 D_800A8F58;
extern f32 D_800A8F5C;
extern f32 D_800A8F60;
extern f32 D_800A8F64;

struct func_151A90C0_s {
    s8 type;
    s32 owner;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    s8 b24;
    s8 b25;
    s8 b26;
};

void *func_151A8B20(void *, s32, s32, s32, s32);

void func_151A90C0(s32 arg0, s32 arg1) {
    struct func_151A90C0_s s;
    f32 f;
    u8 buf[1];
    u8 *p;

    s.type = 2;
    s.owner = arg0;
    f = arg1 & 1;
    s.f8 = f ? D_800A8F58 : D_800A8F5C;
    s.fC = f ? D_800A8F60 : D_800A8F64;
    s.f10 = 0.0f;
    s.f14 = 0.0f;
    s.f18 = 0.0f;
    s.f1C = 0.0f;
    s.f20 = 0.0f;
    s.b24 = 1;
    s.b25 = -1;
    s.b26 = 0;
    buf[0] = arg1;
    p = func_151A8B20(&s, -1, 1, 0xFF, 0);
    if (p != NULL) {
        memcpy(p + 0x80, buf, 1);
    }
}

struct func_151A91AC_s {
    s32 unk0;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    s32 unk18;
    s32 unk1C[4];
};

struct func_151A91AC_t {
    s16 a[3];
};

extern struct func_151A91AC_t D_8008F9A4;

void func_151A91AC(u8 *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    struct func_151A91AC_s s;
    f32 f;
    struct func_151A91AC_t tbl;
    s32 c;
    s32 b;
    s32 a;

    tbl = D_8008F9A4;
    f = func_150ADA68() * 50.0f + 50.0f;
    s.unk6 = tbl.a[func_150ADA20() % 3U];
    s.unk7 = 0;
    s.unk16 = 0;
    s.unk17 = 7;
    s.unk8 = 0;
    s.unkC = 0;
    s.unk0 = 0x1701;
    s.unk4 = 0x3C;
    s.unk10 = 0xA0;
    s.unk11 = 0xFF;
    s.unk12 = 0;
    s.unk13 = 0;
    s.unk14 = 0;
    s.unk15 = 0xFF;
    s.unk18 = 0x3B0002;
    a = func_150ADA20();
    b = func_150ADA20();
    c = func_150ADA20();
    func_1513C650((s32)&s, 1, 0, (s32)(arg0 + 0x58), arg1[0], arg1[1], arg1[2], f, f,
                  a & 0xFF, (c & 1) + (b & 1), 3, 0xFF, 0, arg0[0xC], arg0[1]);
}

void func_151A931C(u8 *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 0x17) {
        u8 *p = &arg0[0x28];

        if (*(u8 *)arg1 == arg0[0x80]) {
            *p |= 1;
        }
    } else if (arg2 == 0x18) {
        u8 *p = &arg0[0x28];

        if (*(u8 *)arg1 == arg0[0x80]) {
            *p &= ~1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9634.s")

struct func_151A9834_s {
    f32 unk0;
    u8 pad4[0x18 - 0x4];
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    s32 unk20;
};
void func_1514373C(f32, f32, f32 *, f32 *);
s32 func_15046C80(f32 *, s32, f32, struct func_151A9834_s *);
extern void (*D_8008FA60[])(f32 *, struct func_151A9834_s *, s32, u8, s32);
extern f32 D_800A8F68;
extern f32 D_800A8F6C;

void func_151A9834(f32 *arg0, f32 arg1, f32 arg2, struct func_151A9834_s *arg3, s32 arg4, u8 arg5, s32 arg6, u8 arg7, s32 arg8) {
    struct func_151A9834_s sp8C;
    f32 sp80[3];
    f32 sp74[3];
    f32 r;
    f32 k;

    if (arg3 == NULL) {
        sp8C.unk0 = D_800A8F68;
        arg3 = &sp8C;
        sp8C.unk18 = 0;
        sp8C.unk1C = 7;
        sp8C.unk1D = 0;
        sp8C.unk20 = 0;
    }
    sp80[1] = arg0[1];
    if (arg4 > 0) {
        k = D_800A8F6C;
        do {
        r = func_150ADA68();
        func_1514373C(2.0f * r * k, func_150ADA68() * arg2, &sp80[0], &sp80[2]);
        sp80[0] += arg0[0];
        sp80[2] += arg0[2];
        if (func_15046C80(sp80, 0, arg1, arg3)) {
            sp74[0] = sp80[0];
            sp74[1] = arg3->unk0;
            sp74[2] = sp80[2];
            D_8008FA60[arg5](sp74, arg3, arg6, arg7, arg8);
        }
            arg4--;
        } while (arg4 > 0);
    }
}
