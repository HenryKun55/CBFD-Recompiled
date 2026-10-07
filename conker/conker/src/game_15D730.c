#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15130280.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131828.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131B7C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131DEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131EE4.s")
