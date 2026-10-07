#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7950.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A91AC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9834.s")
