#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FB8C0.s")

void func_151C3B0C(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, u8 arg6, u8 arg7);

void func_150FC368(u8 *arg0) {
    u8 *temp_v0;
    u8 *temp_a;
    u8 *temp_v1;
    u8 mask;

    temp_v0 = *(u8 **)(arg0 + 0x1A0);
    if ((temp_v0 == NULL) || (*(s32 *)temp_v0 == 0) || (temp_v0[4] == 0xFF) ||
        (arg0[0x1A4] != temp_v0[0x3B]) ||
        ((temp_a = *(u8 **)(temp_v0 + 0x31C)) == NULL) || (temp_a[0x84] != 0) ||
        (temp_v0[0x127] == 0xFF) ||
        ((temp_v1 = *(u8 **)(temp_v0 + 0x318)) == NULL)) {
        mask = 0xFF;
    } else {
        mask = ~(1 << temp_v1[0x23D]) & 0xFF;
    }
    func_151C3B0C(arg0, 1.0f, 1.0f, 0.6f, 0.0f, 0xFF, 0xFF, mask);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC614.s")

struct func_150FC818_e {
    s32 id;
    u8 b;
    u8 pad[0x13];
};

struct func_150FC818_s {
    u8 pad[0x28];
    struct func_150FC818_e e[2];
};

struct func_150FC818_a {
    s32 a;
    s32 b;
    u8 c;
    u8 d;
};

void func_150FC818(struct func_150FC818_s *arg0, struct func_150FC818_a *arg1, u8 arg2) {
    struct func_150FC818_e *e = arg0->e;
    s32 id;
    s32 a;
    s32 x;
    s32 y;

    if (arg2 == 0) {
        a = arg1->a;
        id = e[0].id;
        if ((id == a) || (*(u8 *)&arg1->b == e[0].b)) {
            func_1516972C((struct102 *)arg0);
        } else {
            id = e[1].id;
            if (id != 0) {
                if ((a == id) || (*(u8 *)&arg1->b == e[1].b)) {
                    func_1516972C((struct102 *)arg0);
                }
            }
        }
    } else if (arg2 == 0x2D) {
        x = arg1->a;
        id = e[0].id;
        if (x == id) {
            e[0].id = arg1->b;
            e[0].b = arg1->d;
        } else if ((y = arg1->b) == id) {
            e[0].id = x;
            e[0].b = arg1->c;
        } else {
            id = e[1].id;
            if (id != 0) {
                if (x == id) {
                    e[1].id = y;
                    e[1].b = arg1->d;
                } else if (y == id) {
                    e[1].id = x;
                    e[1].b = arg1->c;
                }
            }
        }
    }
}

s32 func_150FC930(u8 *arg0, s32 arg1, s32 arg2) {
    switch (arg0[4]) {
    case 0x12:
    case 0x23:
    case 0x73:
    case 0x8A:
        return 0;
    }
    return 1;
}

struct func_150FC974_s {
    u8 pad[0x38];
    union {
        s32 i;
        struct102 *p;
    } unk38;
};

void func_150FC974(struct func_150FC974_s *arg0) {
    if (arg0->unk38.i != 0) {
        func_1516972C(arg0->unk38.p);
    }
}

void func_150FC9A4(s32 arg0) {
    func_150FC974(arg0);
    func_1514933C(arg0);
}

void func_150FC9D0(s32 arg0) {
    func_150FC974(arg0);
    func_15149368(arg0);
}
