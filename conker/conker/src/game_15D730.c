#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);

struct func_15130280_s {
    s32 w[7];
    u8 has;
    s32 w2;
};

struct func_15130280_t {
    u8 pad0[0x10];
    u8 data[0x70];
    struct func_15130280_s ent;
};

void *func_15130280(void *arg0, u8 arg1, struct func_15130280_s *arg2, s32 arg3, u8 arg4, s32 arg5) {
    struct func_15130280_t *v1;
    s32 id;

    switch (arg1) {
    case 0:
        id = 0x2B;
        break;
    case 1:
        id = 0x52;
        break;
    case 2:
        id = 0x47;
        break;
    default:
        id = 0x2B;
        break;
    }
    v1 = func_15167A68(id, arg5, arg3 + 0xA8, 1, arg4, 1);
    if (v1 == NULL) {
        return NULL;
    }
    memcpy(v1->data, arg0, 0x70);
    if (arg2 != NULL) {
        v1->ent = *arg2;
    } else {
        v1->ent.has = 0;
    }
    return v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15130374.s")

s32 func_15130374(s32, u8, s32, s32, s32);

s32 func_151303BC(s32 arg0, u8 arg1, s32 arg2) {
    return func_15130374(arg0, arg1, arg2, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_151303EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15130A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_1513137C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131514.s")

s32 func_1513137C(s32, s32, s32, s32, s32);     /* extern */
s32 func_15131514(s32, s32, s32, s32, s32);     /* extern */

void func_1513164C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    func_15131514(arg4, arg5, arg6, arg7, arg8);
    func_1513137C(arg0, arg1, arg2, arg3, arg8);
}

void func_151318E8(void *arg0, s32 arg1);

s32 func_151316AC(u8 *arg0, s32 arg1) {
    func_151318E8(arg0 + 0x58, *(s32 *)(arg0 + 0xA8));
    return 1;
}

s32 func_151316DC(u8 *arg0, s32 arg1) {
    func_15131918(arg0 + 0x58, *(s32 *)(arg0 + 0xA8));
    return 1;
}

s32 func_1513170C(u8 *arg0, s32 arg1) {
    func_15131958(arg0 + 0x58, *(s32 *)(arg0 + 0xA8));
    return 1;
}

void func_1513173C(void) {
    func_15169804();
}

void func_1513175C(void) {
    func_15169824();
}

struct func_1513177C_s {
    u8 pad0[0x68];
    s32 unk68;
    u8 pad6C[0x75 - 0x6C];
    u8 unk75;
};

extern void (*D_80089814[])(struct func_1513177C_s *);

void func_1513177C(struct func_1513177C_s *arg0) {
    s32 idx = (arg0->unk68 & 0x4000) ? arg0->unk75 : 0;
    D_80089814[idx](arg0);
}

struct func_151317C8_s {
    u8 pad0[0x68];
    s32 unk68;
    u8 pad6C[0x75 - 0x6C];
    u8 unk75;
};

extern void (*D_80089844[])(struct func_151317C8_s *);

void func_151317C8(struct func_151317C8_s *arg0) {
    s32 idx = (arg0->unk68 & 0x4000) ? arg0->unk75 : 0;

    D_80089844[idx](arg0);
}

s32 func_15131814(s32 arg0, s32 arg1) {
    return 0;
}

struct func_15131828_s {
    u8 pad0[0x4C];
    f32 unk4C;
    u8 pad50[4];
    f32 unk54;
};

void func_15131828(struct func_15131828_s *arg0, f32 *arg1, u8 *arg2, u8 *arg3) {
    arg0->unk4C = arg1[0] * func_151423D8(arg2[0] - 0x40);
    arg0->unk54 = arg1[1] * func_151423D8(arg2[1] - 0x40);
    arg2[0] += arg3[0] * D_800BE9E4;
    arg2[1] += arg3[1] * D_800BE9E4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_151318E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131958.s")

void func_151319C4(u8 *arg0, s32 arg1, u8 *arg2);

void func_151319A4(u8 *arg0, s32 arg1) {
    func_151319C4(arg0, arg1, arg0 + 0xA8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_151319C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131B3C.s")

struct func_15131B7C_s {
    u8 pad0[0x3C];
    f32 unk3C;
    u8 pad40[4];
    f32 unk44;
    u8 pad48[0x58 - 0x48];
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    s32 unk68;
};

struct func_15131B7C_v {
    u8 unk0;
    u8 pad1[3];
    f32 unk4;
};

extern f32 D_800A3848;
extern f32 D_800A384C;

s32 func_15131B7C(struct func_15131B7C_s *arg0, s32 arg1, struct func_15131B7C_v *arg2, struct func_15131B7C_v *arg3) {
    arg0->unk44 = arg2->unk4 + arg0->unk3C * D_800A3848;
    arg0->unk58 = arg0->unk58 * arg3->unk4;
    arg0->unk5C = arg0->unk5C * -arg3->unk4;
    arg0->unk60 = arg0->unk60 * arg3->unk4;
    if (fabsf(arg0->unk5C) < D_800A384C) {
        arg0->unk58 = 0.0f;
        arg0->unk5C = 0.0f;
        arg0->unk60 = 0.0f;
        arg0->unk64 = 0.0f;
        arg3->unk0 &= ~1;
        arg0->unk68 &= ~6;
    }
    return 1;
}

struct func_15131C2C_s {
    u8 pad0[0x68];
    s32 unk68;
    u8 pad6C[0x75 - 0x6C];
    u8 unk75;
};

extern void (*D_80089878[])(struct func_15131C2C_s *, s32, u8);

void func_15131C2C(struct func_15131C2C_s *arg0, s32 arg1, u8 arg2) {
    void (*fn)(struct func_15131C2C_s *, s32, u8);

    if (arg0->unk68 & 0x4000) {
        fn = D_80089878[arg0->unk75];
        if (fn != NULL) {
            fn(arg0, arg1, arg2);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131C84.s")

struct func_15131D4C_s {
    s32 a;
    s32 b;
    s32 c;
};
extern struct func_15131D4C_s D_800A37F0;

void func_15131D4C(void *arg0, u8 arg1) {
    struct func_15131D4C_s sp1C = D_800A37F0;

    func_15169260(&sp1C, 3, arg0, arg1);
}

struct func_15131D9C_s {
    u8 pad0[0x38];
    f32 unk38;
    f32 unk3C;
    u8 pad40[0xA8 - 0x40];
    s16 unkA8;
    s16 unkAA;
    s32 unkAC;
    s32 unkB0;
};

void func_15131C84(s16 *, s16 *, s32, s32 *, f32 *, f32 *);

s32 func_15131D9C(struct func_15131D9C_s *arg0, s32 arg1) {
    func_15131C84(&arg0->unkA8, &arg0->unkAA, arg0->unkAC, &arg0->unkB0, &arg0->unk38, &arg0->unk3C);
    return 1;
}

struct func_15131DEC_s {
    u8 pad0[0x2B];
    u8 unk2B;
    u8 pad2C[0x38 - 0x2C];
    f32 unk38;
    f32 unk3C;
    u8 pad40[0xA8 - 0x40];
    f32 unkA8;
    f32 unkAC;
    f32 unkB0;
    f32 unkB4;
    f32 unkB8;
};
extern f32 D_800BE9A4;

s32 func_15131DEC(struct func_15131DEC_s *arg0, s32 arg1) {
    f32 t = arg0->unkA8;
    arg0->unk38 = arg0->unk3C = sqrtf(t) * arg0->unkB0;
    arg0->unk2B = arg0->unkB4 - arg0->unkB8 * t * t;
    arg0->unkA8 = t + D_800BE9A4;
    if (arg0->unkAC < arg0->unkA8) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131EE4.s")
