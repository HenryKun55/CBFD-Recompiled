#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151A4ECC_sub;
void func_151A3504(struct func_151A4ECC_sub *arg0, s32 arg1);
void func_151A4590(u8 *arg0, u8 arg1);
void func_151A499C(u8 *arg0, u8 arg1);
s32 func_15160A58(void *, u8, f32 *, u8, s16, s32, s32, s32, s32, s32, s32, s8, s32, u8, u8, s32);
extern f32 D_800A8D50;
extern f32 D_800A8D54;

struct func_151A3390_s {
    u8 *unk0;
    u8 unk4;
    s8 unk5;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    f32 unk20;
    f32 unk24;
    s8 unk28;
    s8 unk29;
    s8 unk2A;
    s8 unk2B;
    u8 unk2C;
    s8 unk2D;
    s8 unk2E;
};

void func_151A3390(u8 *arg0, u8 arg1) {
    struct func_151A3390_s sp68;
    f32 sp5C[3];

    sp68.unk0 = arg0;
    sp68.unk4 = arg0[0x3B];
    sp68.unk5 = 1;
    sp68.unk8 = 0.0f;
    sp68.unkC = 0.0f;
    sp68.unk10 = 0.0f;
    sp68.unk2B = 1;
    sp68.unk2C = 0xFF;
    sp68.unk2D = 8;
    sp68.unk2E = 0x1F;
    sp68.unk18 = 0xAA;
    sp68.unk1A = 0x28;
    sp68.unk1C = 7;
    sp68.unk28 = 2;
    sp68.unk29 = 4;
    sp68.unk2A = 1;
    sp68.unk14 = D_800A8D50;
    sp68.unk20 = 30.0f;
    sp68.unk24 = D_800A8D54;
    func_151A3504((struct func_151A4ECC_sub *)&sp68, arg1);
    func_151A4590(arg0, arg1);
    func_151A499C(arg0, arg1);
    func_10010154(0x1AA, arg0, 0x55F0, 0x3E8, 0xFA0);
    sp5C[0] = 0.0f;
    sp5C[1] = 0.0f;
    sp5C[2] = 0.0f;
    func_15160A58(arg0, 1, sp5C, 2, 0x12C, 0x50, 0xFF, 0xFF, 0x75, 0xFF, 0, -1, 0, 0, arg1, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A361C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A37C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3BE4.s")

extern f32 D_800A8D5C;
s32 func_1513418C(void *, s32, u8, s32);

struct func_151A4590_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    void *unkC;
    s8 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    s8 unk2A;
    s8 unk2B;
    s8 unk2C;
    s8 unk2D;
};

void func_151A4590(u8 *arg0, u8 arg1) {
    struct func_151A4590_s sp18;

    if (arg0 == NULL) {
        return;
    }
    {
        sp18.unk0 = 0;
        sp18.unk4 = 0;
        sp18.unk8 = arg0[0x3B];
        sp18.unk10 = 1;
        sp18.unk14 = 0.0f;
        sp18.unk18 = 0.0f;
        sp18.unk1C = 0.0f;
        sp18.unk20 = D_800A8D5C;
        sp18.unk24 = 3.0f;
        sp18.unk28 = 0x64;
        sp18.unk2A = 0xA;
        sp18.unk2B = 1;
        sp18.unk2C = -1;
        sp18.unk2D = 0;
        sp18.unkC = arg0;
        func_1513418C(&sp18, 0, arg1, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4638.s")

struct func_151A483C_sub {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};

struct func_151A483C_s {
    u8 pad0[0x18];
    s16 unk18;
    s16 unk1A;
    u8 pad1C[0x2B - 0x1C];
    u8 unk2B;
    u8 unk2C;
    u8 pad2D[0x38 - 0x2D];
    f32 unk38;
    f32 unk3C;
    u8 pad40[0x70 - 0x40];
    u8 unk70;
    u8 unk71;
    u8 unk72;
    u8 pad73[0xA8 - 0x73];
    struct func_151A483C_sub unkA8;
};

s32 func_151A483C(struct func_151A483C_s *arg0, s32 arg1) {
    struct func_151A483C_sub *sub = &arg0->unkA8;
    f32 tmp;

    if (arg0->unk1A < arg0->unkA8.unk4) {
        arg0->unk2B = arg0->unk1A * arg0->unkA8.unk6;
    }
    if (arg0->unk1A < sub->unk8) {
        f32 *p;
        tmp = sub->unkA * D_800BE9E4;
        p = &arg0->unk38;
        p[0] += tmp;
        p[1] += tmp;
    }
    if (arg0->unk1A < sub->unk0) {
        arg0->unk72 = 1;
        arg0->unk70 = 2;
        arg0->unk71 = 2;
        arg0->unk2C = arg0->unk1A * sub->unk2;
        arg0->unk18 = 0x5203;
    }
    return 1;
}

struct func_151A4900_sub {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};

struct func_151A4900_s {
    u8 pad0[0x1A];
    s16 unk1A;
    u8 pad1C[0x2B - 0x1C];
    u8 unk2B;
    u8 unk2C;
    u8 pad2D[0x38 - 0x2D];
    f32 unk38;
    f32 unk3C;
    u8 pad40[0xA8 - 0x40];
    struct func_151A4900_sub unkA8;
};

s32 func_151A4900(struct func_151A4900_s *arg0, s32 arg1) {
    struct func_151A4900_sub *p = &arg0->unkA8;
    f32 tmp;

    if (arg0->unk1A < p->unk4) {
        arg0->unk2B = arg0->unk1A * p->unk6;
    }
    if (arg0->unk1A < p->unk8) {
        f32 *f = &arg0->unk38;
        tmp = p->unkA * D_800BE9E4;
        f[0] += tmp;
        f[1] += tmp;
    }
    arg0->unk2C = arg0->unk1A * p->unk2;
    return 1;
}

extern f32 D_800A8D64;

struct func_151A499C_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
    f32 unkC;
    u8 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

void func_151A499C(u8 *arg0, u8 arg1) {
    struct260 *temp_v0;
    struct func_151A499C_s sp2C;

    sp2C.unk0 = arg0;
    sp2C.unk4 = arg0[0x3B];
    sp2C.unk8 = D_800A8D64;
    sp2C.unkC = 0.0f;
    sp2C.unk10 = 1;
    sp2C.unk14 = 0.0f;
    sp2C.unk18 = 0.0f;
    sp2C.unk1C = 0.0f;
    temp_v0 = func_151491F4(0x12C, -1, 5, 0, 1, (struct37 *)0x20, arg1, 0);
    if (temp_v0 != NULL) {
        memcpy(&temp_v0->pad18[0x10], &sp2C, 0x20);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4A38.s")

struct func_151A4E9C_s;
void func_151A4E9C(struct func_151A4E9C_s *arg0);

struct func_151A4CE0_s {
    s32 unk0;
    u8 unk4;
};

struct func_151A4CE0_a1 {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_151A4CE0(void *arg0, void *arg1, u8 arg2) {
    struct func_151A4CE0_s *v0 = *(struct func_151A4CE0_s **)((u8 *)arg0 + 0x98);

    if (arg2 == 0) {
        if (((struct func_151A4CE0_s *)arg1)->unk0 == v0->unk0 || ((struct func_151A4CE0_s *)arg1)->unk4 == v0->unk4) {
            func_151A4E9C(arg0);
        }
    } else if (arg2 == 45) {
        struct func_151A4CE0_a1 *a1 = arg1;
        if (v0->unk0 == a1->unk0) {
            v0->unk0 = a1->unk4;
            v0->unk4 = a1->unk9;
        } else if (v0->unk0 == a1->unk4) {
            v0->unk0 = a1->unk0;
            v0->unk4 = a1->unk8;
        }
    }
}

struct func_151A4D88_s {
    s32 a;
    u8 b;
};

struct func_151A4D88_s2 {
    s32 a;
    s32 c;
    u8 b;
    u8 d;
};

void func_151A4D88(struct102 *arg0, struct func_151A4D88_s2 *arg1, u8 arg2) {
    struct func_151A4D88_s *p;

    p = (struct func_151A4D88_s *)((u8 *)arg0 + 0x28);
    if (arg2 == 0) {
        if (arg1->a == p->a || ((struct func_151A4D88_s *)arg1)->b == p->b) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (p->a == arg1->a) {
            p->a = arg1->c;
            p->b = arg1->d;
        } else if (p->a == arg1->c) {
            p->a = arg1->a;
            p->b = arg1->b;
        }
    }
}

struct func_151A4E34_s {
    void *obj;
    u8 pad4;
    u8 unk5;
    u8 pad6[2];
    u8 unk8[1];
};

s32 func_151A4E34(struct func_151A4E34_s *arg0, s32 arg1) {
    void *obj = arg0->obj;

    if (*(s32 *) ((char *) obj + 0x1D4) == 0) {
        return 0;
    }
    if ((*(u8 *) ((char *) obj + 0x74) & 0xF) == 0xF) {
        return 0;
    }
    func_15143134(arg0->unk8, arg1, *(s32 *) ((char *) obj + 0x1D4) + (arg0->unk5 << 6));
    return 1;
}

struct func_151A4E9C_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
    u8 pad31[0x98 - 0x31];
    struct func_151A4E9C_s *unk98;
};

void func_151A4E9C(struct func_151A4E9C_s *arg0) {
    struct func_151A4E9C_s *v0 = arg0->unk98;

    arg0->unk30 = 0;
    arg0->unk1E &= ~2;
    v0->unk30 |= 1;
    v0->unk30 |= 4;
}

struct func_151A4ECC_obj {
    s32 unk0;
    u8 pad4[0x3B - 4];
    u8 unk3B;
    u8 pad3C[0x74 - 0x3C];
    u8 unk74;
    u8 pad75[0x1D4 - 0x75];
    s32 unk1D4;
};

struct func_151A4ECC_sub {
    struct func_151A4ECC_obj *obj;
    u8 unk4;
};

struct func_151A4ECC_s {
    u8 pad0[0xC];
    u8 unkC;
    u8 unkD;
    s16 unkE;
    u8 pad10[0x18];
    struct func_151A4ECC_sub unk28;
};

void func_151A3504(struct func_151A4ECC_sub *arg0, s32 arg1);

void func_151A4ECC(struct func_151A4ECC_s *arg0) {
    struct func_151A4ECC_sub *sub = &arg0->unk28;
    u8 flag = 0;
    struct func_151A4ECC_obj *obj;

    if (arg0->unk28.obj->unk0 == 0) {
        flag = 1;
    }
    obj = sub->obj;
    if (obj->unk3B != sub->unk4) {
        flag = 1;
    }
    if (!flag && obj->unk1D4 != 0 && (obj->unk74 & 0xF) != 0xF) {
        func_151A3504(sub, arg0->unkC);
        flag = 1;
    }
    if (flag) {
        arg0->unkE = -1;
        arg0->unkD |= 1;
    }
}

struct func_151A4F7C_s {
    s32 unk0;
    u8 unk4;
};

void func_151A4F7C(struct102 *arg0, struct func_151A4F7C_s *arg1, u8 arg2) {
    struct func_151A4F7C_s *temp_v0 = (struct func_151A4F7C_s *)((u8 *)arg0 + 0x28);

    if (arg2 == 0) {
        if ((arg1->unk0 == temp_v0->unk0) || (arg1->unk4 == temp_v0->unk4)) {
            func_1516972C(arg0);
        }
    }
}

struct func_151A4FD0_s {
    u8 pad0[0x10];
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
};

extern void *func_15167A68(s32, s32, s32, s32, s32, s32);

struct func_151A4FD0_s *func_151A4FD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6, s32 arg7) {
    struct func_151A4FD0_s *v1 = func_15167A68(0x5A, 0, arg7 + 0x20, 0, 0xFF, 1);

    if (v1 == NULL) {
        return NULL;
    }
    v1->unk14 = arg0;
    v1->unk10 = arg1;
    v1->unk15 = arg2;
    v1->unk16 = arg3;
    v1->unk17 = arg4;
    v1->unk19 = arg6;
    v1->unk18 = 0;
    v1->unk1A = arg5;
    return v1;
}

struct func_151A5070_s {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14;
    u8 unk15;
    u8 pad16[2];
    u8 unk18;
    u8 unk19;
};

void func_151A5070(struct func_151A5070_s *arg0) {
    s32 t = arg0->unk10;
    s32 step;
    s32 val;

    if (t != 0) {
        t -= D_800BE9E4;
        if (t <= 0) {
            func_1516972C((struct102 *) arg0);
            return;
        }
        arg0->unk10 = t;
    }
    if (arg0->unk19 == 0) {
        func_10011FA0(2);
    }
    step = D_800BE9E4 * 2;
    val = arg0->unk15;
    if (arg0->unk18 == 0) {
        val -= step;
        if (val < 0x90) {
            val = 0x90;
            arg0->unk18 = 1;
        }
    } else {
        val += step;
        if (val >= 0x100) {
            val = 0xFF;
            arg0->unk18 = 0;
        }
    }
    arg0->unk15 = val;
}

struct func_151A5130_s {
    u8 pad[0x14];
    u8 unk14;
};
extern void (*D_8008F900[])(void *, struct func_151A5130_s *, s16);

void func_151A5130(void *arg0, struct func_151A5130_s *arg1, s16 arg2) {
    D_8008F900[arg1->unk14](arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A5170.s")

extern void (*D_8008F904[])(u8 *, s32, u8);

void func_151A55D4(u8 *arg0, s32 arg1, u8 arg2) {
    void (*fn)(u8 *, s32, u8) = D_8008F904[arg0[0x19]];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A561C.s")
