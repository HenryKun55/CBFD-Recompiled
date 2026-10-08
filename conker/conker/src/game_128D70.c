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

struct func_150FC438_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
    u8 unkC;
    u8 unkD;
    s32 unk10;
    s16 unk14;
    s8 unk16;
    u8 *unk18;
    u8 unk1C;
    u8 unk1D;
};

struct func_150FC438_s2 {
    u8 unk0;
    s8 unk1;
    s8 unk2;
    s16 unk4;
    u8 unk6;
    f32 unk8[12];
};

extern f32 D_800A1EB0;
extern f32 D_800A1EB4;
extern f32 D_800A1EB8;
extern f32 D_800A1EBC;
extern f32 D_800A1EC0;
extern f32 D_800A1EC4;
extern f32 D_800A1EC8;
extern f32 D_800A1ECC;
extern f32 D_800A1ED0;
void *func_15164780(void *arg0, s32 arg1, u8 arg2, s32 arg3);

void func_150FC438(u8 *arg0, u8 *arg1, u8 arg2, u8 arg3) {
    struct func_150FC438_s s;
    struct260 *ret;
    u8 *dst;
    struct func_150FC438_s2 t;

    s.unk0 = arg0;
    s.unk4 = arg0[0x3B];
    s.unk8 = 0.0f;
    s.unkC = 0;
    s.unkD = arg2;
    s.unk10 = 0;
    s.unk14 = 0;
    s.unk1D = arg3;
    if (arg1 != NULL && *(u8 **)(arg1 + 0x318) != NULL) {
        s.unk16 = (*(u8 **)(arg1 + 0x318))[0x23D];
    } else {
        s.unk16 = -1;
    }
    s.unk18 = arg1;
    if (arg1 != NULL) {
        s.unk1C = arg1[0x3B];
    } else {
        s.unk1C = 0xFF;
    }
    ret = func_15149130(0x12C, -1, 0x27, -1, 0, 0x25, (struct37 *)0x20, 0xFF, 1);
    if (ret != NULL) {
        dst = (u8 *)ret + 0x28;
        memcpy(dst, &s, 0x20);
        if (arg1 != NULL && *(u8 **)(arg1 + 0x318) != NULL) {
            t.unk0 = 4;
            t.unk1 = -1;
            t.unk2 = -1;
            t.unk4 = 0x12C;
            t.unk6 = (*(u8 **)(arg1 + 0x318))[0x23D];
            t.unk8[0] = 12.0f;
            t.unk8[1] = 20.0f;
            t.unk8[2] = 19.0f;
            t.unk8[3] = D_800A1EB0;
            t.unk8[4] = D_800A1EB4;
            t.unk8[5] = D_800A1EB8;
            t.unk8[6] = D_800A1EBC;
            t.unk8[7] = D_800A1EC0;
            t.unk8[8] = D_800A1EC4;
            t.unk8[9] = D_800A1EC8;
            t.unk8[10] = D_800A1ECC;
            t.unk8[11] = D_800A1ED0;
            *(void **)(dst + 0x10) = func_15164780(&t, 0, 0xFF, 1);
        }
    }
}

s32 func_150FB8C0(void *, u8, f32, u8, s32, s32);

struct func_150FC614_s {
    u8 *unk0;
    u8 unk4;
    u8 pad5[3];
    f32 unk8;
    u8 unkC;
    u8 unkD;
    u8 padE[6];
    s16 unk14;
    s8 unk16;
    u8 pad17;
    u8 *unk18;
    u8 pad1C;
    u8 unk1D;
};

struct func_150FC614_msg {
    u8 unk0;
    s16 unk2;
    u8 unk4;
    u8 unk5;
    s8 unk6;
};

void func_150FC614(u8 *arg0) {
    struct func_150FC614_s *s;
    u8 *obj;
    struct func_150FC614_msg msg;

    obj = *(u8 **)(arg0 + 0x28);
    if ((*(s32 *)obj == 0) || (s = (struct func_150FC614_s *)(arg0 + 0x28), obj[4] == 0xFF) ||
        (s->unk4 != obj[0x3B]) || (D_800C35EA == 1)) {
        *(s16 *)(arg0 + 0xE) = -1;
        return;
    }
    if (s->unk1D != *(u16 *)(obj + 0x84)) {
        *(s16 *)(arg0 + 0xE) = -1;
        return;
    }
    s->unk8 -= D_800BE9A4;
    while (s->unk8 < 0.0f) {
        func_150FB8C0(obj, s->unkC, -s->unk8, s->unkD, arg0[0xC], arg0[1]);
        s->unkC ^= 1;
        if (s->unk18 != NULL && *(u8 **)(s->unk18 + 0x31C) != NULL) {
            (*(s16 *)(*(u8 **)(s->unk18 + 0x31C) + 0x1AA))++;
        }
        s->unk8 += 4.0f + func_150ADA68() * 4.0f;
    }
    if (s->unk16 != -1) {
        s->unk14 -= D_800BE9E4;
        if (s->unk14 < 0) {
            msg.unk0 = 1;
            func_150ADA20();
            msg.unk2 = 0x1E;
            msg.unk5 = 1 << s->unk16;
            msg.unk4 = (func_150ADA20() % 6U) + 3;
            msg.unk6 = -1;
            func_151D8868(&msg, 0, arg0[0xC], arg0[1]);
            func_150ADA20();
            s->unk14 = 0xFA;
        }
    }
}

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
