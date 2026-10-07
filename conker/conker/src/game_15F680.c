#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151321D0.s")

struct func_151323AC_s {
    char pad0[0x60];
    s32 unk60;
    char pad64[4];
    u8 unk68;
};
extern void (*D_800899B0[])(void);

void func_151323AC(struct func_151323AC_s *arg0) {
    s32 idx;
    if (arg0->unk60 & 0x100) {
        idx = arg0->unk68;
    } else {
        idx = 0;
    }
    D_800899B0[idx]();
}

struct func_151323F8_s {
    u8 pad0[0x60];
    s32 unk60;
    u8 pad64[4];
    u8 unk68;
};

extern void (*D_800899D4[])(void);

void func_151323F8(struct func_151323F8_s *arg0) {
    s32 idx;

    idx = (arg0->unk60 & 0x100) ? arg0->unk68 : 0;
    D_800899D4[idx]();
}

struct func_15132444_node {
    void *unk0;
    struct func_15132444_node *unk4;
    struct func_15132444_node *unk8;
    u8 padC[2];
    u8 unkE;
};

struct func_15132444_s {
    u8 pad0[0x66];
    u16 unk66;
    u8 pad68[0x8C - 0x68];
    struct func_15132444_node *unk8C;
};

extern s32 D_800DC640[];
void func_1510D630(s32);
struct func_151325C8_s;
void func_151325C8(struct func_151325C8_s *);

void func_15132444(struct func_15132444_s *arg0) {
    struct func_15132444_node *node;

    D_800DC63C--;
    ((s16 *)D_800DC468)[arg0->unk66]--;
    if (((s16 *)D_800DC468)[arg0->unk66] == 0) {
        if (arg0->unk8C->unkE) {
            ((s16 *)D_800DC468)[arg0->unk66] = 1;
        } else {
            func_1510D630(D_800DC640[arg0->unk66]);
            node = arg0->unk8C;
            if (node->unk8 == NULL) {
                D_800DC460 = (s32)node->unk4;
                if (D_800DC460 != 0) {
                    ((struct func_15132444_node *)D_800DC460)->unk8 = NULL;
                } else {
                    D_800DC464 = 0;
                }
            } else {
                node->unk8->unk4 = node->unk4;
                node = arg0->unk8C;
                if (node->unk4 != NULL) {
                    node->unk4->unk8 = node->unk8;
                } else {
                    D_800DC464 = (s32)node->unk8;
                }
            }
            func_100043B4(arg0->unk8C->unk0, 4);
            func_100043B4(arg0->unk8C, 4);
        }
    }
    func_151325C8((struct func_151325C8_s *)arg0);
}

void func_15132570(s32 arg0) {
    func_15132444(arg0);
    func_15169804(arg0);
}

void func_1513259C(s32 arg0) {
    func_15132444(arg0);
    func_15169824(arg0);
}

struct func_151325C8_s {
    u8 pad0[0x154];
    s32 unk154[4];
    s32 unk164;
};

void func_151325C8(struct func_151325C8_s *arg0) {
    s32 i;

    for (i = 0; i <= D_80082FA0; i++) {
        if (arg0->unk154[i] != 0) {
            func_100043B4((void *)arg0->unk154[i], 4);
        }
    }
    if (arg0->unk164 != 0) {
        func_100043B4((void *)arg0->unk164, 4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_1513264C.s")

s32 **func_1513264C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

s32 **func_15132A4C(void *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    return func_1513264C(arg0, arg1, arg2, 0, arg3, arg4, arg5);
}

struct func_15132A88_s {
    u8 pad0[0x60];
    u32 unk60;
    u8 pad64[0x8];
    void *unk6C;
    u8 pad70[0x8];
    u8 unk78;
};

extern s32 func_151464B8(void *);
extern s32 (*D_8008998C[])(void *);

void func_15132A88(struct func_15132A88_s *arg0) {
    s32 ret;

    arg0->unk60 &= ~0x200000;
    if (arg0->unk60 & 0x20000) {
        return;
    }
    if ((arg0->unk60 & 0x400) && (arg0->unk6C != NULL) && func_151464B8(arg0->unk6C)) {
        return;
    }
    if (arg0->unk60 & 0x80000) {
        arg0->unk60 |= 0x200000;
        return;
    }
    ret = D_8008998C[arg0->unk78]((u8 *)arg0 + D_800BE9C0 * 64 + 0x90);
    if (ret == -1) {
        func_1516972C((struct102 *)arg0);
        return;
    }
    if (ret == 0) {
        arg0->unk60 &= ~0x40000;
    } else {
        arg0->unk60 |= 0x240000;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151332DC.s")

struct func_15133510_s {
    u8 pad0[0x18];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};

void func_151424F4(s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);

s32 func_15133510(s32 arg0, struct func_15133510_s *arg1) {
    func_151424F4(arg0, arg1->unk18, arg1->unk1C, arg1->unk20, arg1->unk24, arg1->unk28, arg1->unk2C,
                  arg1->unk30, arg1->unk34, arg1->unk38, arg1->unk3C, arg1->unk40);
    return 1;
}

struct func_15133588_s {
    u8 pad0[0x60];
    s32 unk60;
    u8 pad64[2];
    u16 unk66;
    u8 unk68;
    u8 pad69[0x13];
    s32 unk7C;
    u8 unk80;
};

struct func_15133588_arg1 {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_151B9660(struct func_15133588_s *);
extern void (*D_800899F8[])(struct func_15133588_s *, struct func_15133588_arg1 *, u8);

void func_15133588(struct func_15133588_s *arg0, struct func_15133588_arg1 *arg1, u8 arg2) {
    s32 type = arg2;
    s32 idx;
    s32 temp;
    s32 temp2;
    void (*fn)(struct func_15133588_s *, struct func_15133588_arg1 *, u8);

    if (type == 0x1B && arg0->unk66 == 0x22) {
        func_151B9660(arg0);
    }
    if (type == 0x2D) {
        temp = arg1->unk0;
        if (temp == arg0->unk7C) {
            arg0->unk7C = arg1->unk4;
            arg0->unk80 = arg1->unk9;
        } else if (arg0->unk7C == arg1->unk4) {
            arg0->unk7C = temp;
            arg0->unk80 = arg1->unk8;
        lbl:;
        }
    } else if (type == 0) {
        temp = arg1->unk0;
        if (temp == arg0->unk7C || arg0->unk80 == *(u8 *)&arg1->unk4) {
            arg0->unk7C = 0;
            arg0->unk80 = 0;
        }
    }
    idx = (arg0->unk60 & 0x100) ? arg0->unk68 : 0;
    fn = D_800899F8[idx];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151336A8.s")

struct func_15133760_s {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0xC];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};

void func_15142838(Mtx *m, f32 scale02, f32 scale1, f32 rotX, f32 rotY, f32 rotZ, f32 transX, f32 transY, f32 transZ);

s32 func_15133760(Mtx *arg0, struct func_15133760_s *arg1) {
    func_15142838(arg0, arg1->unk18, arg1->unk1C, arg1->unk20, arg1->unk24, arg1->unk28, arg1->unk38, arg1->unk3C, arg1->unk40);
    return 1;
}

struct func_151337C0_s {
    u8 pad0[0x20];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0xC];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
};

s32 func_151337C0(struct func_151337C0_s *arg0) {
    arg0->unk38 += arg0->unk44 * D_800BE9A4;
    arg0->unk3C += (arg0->unk48 * D_800BE9A4) + (arg0->unk5C * D_800BE9A4 * D_800BE9A4 * 0.5f);
    arg0->unk40 += arg0->unk4C * D_800BE9A4;
    arg0->unk48 += arg0->unk5C * D_800BE9A4;
    arg0->unk20 += arg0->unk50 * D_800BE9A4;
    arg0->unk24 += arg0->unk54 * D_800BE9A4;
    arg0->unk28 += arg0->unk58 * D_800BE9A4;
    return 1;
}

typedef struct {
    f32 x, y, z;
} func_15133894_v;

struct func_15133894_o {
    u8 pad0[0x4F];
    u8 unk4F;
};

struct func_15133894_s {
    u8 pad0[0x10];
    f32 unk10;
    u8 pad14[0x24];
    func_15133894_v unk38;
    u8 pad44[0x1C];
    s32 unk60;
    u8 pad64[0xF];
    u8 unk73;
    u8 pad74[0x9C];
    f32 unk110;
    f32 unk114;
    u8 pad118[0x18];
    struct func_15133894_o *unk130;
};

extern s32 func_15046C80(func_15133894_v *, s32, f32, f32 *);
extern s8 (*D_80089934[])(struct func_15133894_s *, f32, f32, f32, f32, f32 *);

s8 func_15133894(struct func_15133894_s *arg0) {
    s8 ret;
    func_15133894_v old;
    func_15133894_v pos;
    struct func_15133894_o *o;
    s32 flag;

    ret = 1;
    old = arg0->unk38;
    func_151337C0(arg0);
    if ((arg0->unk60 & 1) && arg0->unk73 && arg0->unk38.y < old.y) {
        pos.x = arg0->unk38.x;
        pos.y = arg0->unk10 + old.y;
        pos.z = arg0->unk38.z;
        if (func_15046C80(&pos, 0, arg0->unk38.y - arg0->unk10, &arg0->unk110)) {
            flag = 0;
            if ((o = arg0->unk130) != NULL && (arg0->unk130->unk4F & 0x60) == 0x40) {
                flag = 1;
            }
            if (!flag) {
                ret = D_80089934[arg0->unk73](arg0, old.x, old.y, old.z, arg0->unk110, &arg0->unk114);
            }
        }
    }
    return ret;
}

struct func_151339D4_s {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
    u8 pad18[0x24];
    f32 unk3C;
    u8 pad40[0x4];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
};

s32 func_151339D4(struct func_151339D4_s *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    f32 temp;

    arg0->unk3C = arg0->unk10 + arg4;
    temp = arg0->unk14;
    arg0->unk44 = arg0->unk44 * temp;
    arg0->unk48 = arg0->unk48 * -temp;
    arg0->unk4C = arg0->unk4C * temp;
    arg0->unk50 = arg0->unk50 * temp;
    arg0->unk54 = arg0->unk54 * temp;
    arg0->unk58 = arg0->unk58 * temp;
    return 1;
}

struct func_15133A50_s {
    u8 pad0[0x10];
    f32 unk10;
    u8 pad14[0x3C - 0x14];
    f32 unk3C;
    u8 pad40[4];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
};

s32 func_15133A50(struct func_15133A50_s *arg0, void *arg1, void *arg2, void *arg3, f32 arg4) {
    arg0->unk3C = arg0->unk10 + arg4;
    arg0->unk44 = 0.0f;
    arg0->unk48 = 0.0f;
    arg0->unk4C = 0.0f;
    arg0->unk50 = 0.0f;
    arg0->unk54 = 0.0f;
    arg0->unk58 = 0.0f;
    return 1;
}

extern u8 D_800C3E90;

struct func_15133A94_inner {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x3B - 0x5];
    u8 unk3B;
    u8 pad3C[0x74 - 0x3C];
    u8 unk74;
    u8 pad75[0x1D4 - 0x75];
    f32 (*unk1D4)[4][4];
};

struct func_15133A94_s {
    u8 pad0[0x7C];
    struct func_15133A94_inner *unk7C;
    u8 unk80;
    u8 pad81[0x170 - 0x81];
    u8 unk170;
};

s32 func_15133A94(Mtx *arg0, struct func_15133A94_s *arg1) {
    struct func_15133A94_inner *p;
    f32 (*mtxs)[4][4];

    p = arg1->unk7C;
    if (p == NULL || p->unk0 == 0 || p->unk4 == 0xFF || p->unk3B != arg1->unk80) {
        return -1;
    }
    mtxs = p->unk1D4;
    if (mtxs == NULL) {
        return 0;
    }
    if ((p->unk74 & 0xF) == 0xF) {
        return 0;
    }
    if (D_800C3E90) {
        memcpy(arg0, mtxs[arg1->unk170], 0x40);
        return 1;
    }
    {
    f32 m[4][4];
    s32 pad[2];
    memcpy(m, mtxs[arg1->unk170], 0x40);
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    m[3][3] = 1.0f;
    guMtxF2L(m, arg0);
    }
    return 1;
}

struct func_15133B98_s {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
    u8 pad18[0x24];
    f32 unk3C;
    u8 pad40[0x4];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    s32 unk60;
};

s32 func_15133B98(struct func_15133B98_s *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    f32 temp;

    arg0->unk3C = arg0->unk10 + arg4;
    temp = arg0->unk14;
    arg0->unk44 = arg0->unk44 * temp;
    arg0->unk48 = arg0->unk48 * -temp;
    arg0->unk4C = arg0->unk4C * temp;
    arg0->unk50 = arg0->unk50 * temp;
    arg0->unk54 = arg0->unk54 * temp;
    arg0->unk58 = arg0->unk58 * temp;
    if (fabsf(arg0->unk48) < 4.0f) {
        arg0->unk44 = 0.0f;
        arg0->unk60 &= ~0x69;
        arg0->unk48 = 0.0f;
        arg0->unk4C = 0.0f;
        arg0->unk50 = 0.0f;
        arg0->unk54 = 0.0f;
        arg0->unk58 = 0.0f;
        arg0->unk5C = 0.0f;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133C58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133D20.s")

struct func_15133DE8_s {
    u8 pad0[0x7C];
    s32 unk7C;
    u8 unk80;
};

struct func_15133DE8_k {
    s32 unk0;
    u8 unk4;
};

void func_15133DE8(struct func_15133DE8_s *arg0, struct func_15133DE8_k *arg1, u8 arg2) {
    s32 temp;

    if (arg2 == 0) {
        temp = arg1->unk0;
        if ((temp == arg0->unk7C) || (arg0->unk80 == arg1->unk4)) {
            func_1516972C((struct102 *) arg0);
        }
    }
}

struct func_15133E3C_s { s32 a; s32 b; };
extern struct func_15133E3C_s D_800A3860;

void func_15133E3C(void *arg0, u8 arg1) {
    struct func_15133E3C_s sp18 = D_800A3860;
    func_15169260(&sp18, 2, arg0, arg1);
}

struct func_15133E84_s {
    u8 pad[0x170];
    u16 unk170;
    u8 unk172;
    u8 pad173;
    s32 unk174;
};

void *func_15133EEC();

void func_15133E84(void *arg0, struct func_15133E84_s *arg1, s32 arg2) {
    func_15133EEC(arg0, arg1->unk170, arg1->unk172, arg1->unk174);
}

void *func_15133EEC(void *arg0, s32 arg1, s32 arg2, s32 arg3);

void func_15133EB8(void *arg0, void *arg1, s32 arg2) {
    func_15133EEC(arg0, *(u16 *)((char *)arg1 + 0x174), *(u8 *)((char *)arg1 + 0x176), *(s32 *)((char *)arg1 + 0x178));
}

struct func_15133EEC_e {
    s32 **unk0;
    u8 pad4[6];
    u8 unkA;
    u8 unkB;
};

extern struct func_15133EEC_e D_80090B60[];
s32 func_1510D0EC();

void *func_15133EEC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *ptr;
    u8 sp3B;
    u8 sp3A;
    s32 v;
    s32 sp30;

    ptr = *D_80090B60[(u16)arg1].unk0;
    sp3B = D_80090B60[(u16)arg1].unkA;
    sp3A = D_80090B60[(u16)arg1].unkB;
    v = func_1510D0EC(ptr, &sp30, arg3, 0);
    gSPSegment(((Gfx *)arg0)++, (u8)arg2, v);
    if (sp3B == 2) {
        gSPSegment(((Gfx *)arg0)++, (u8)arg2 + 1, (v + sp30) - ((sp3A == 1) ? 0x200 : 0x20));
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133FD8.s")
