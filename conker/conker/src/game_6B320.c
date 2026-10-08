#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1503DE70_s {
    s32 unk0;
    s32 unk4;
};
extern struct func_1503DE70_s *D_8008446C[];
void func_1503DF0C(s32, s32, s32, s32);

void func_1503DE70(struct127 *arg0, s32 arg1, s32 arg2) {
    if (arg2 != -1) {
        func_1503DF0C(arg0 - gObjects, arg1, D_8008446C[arg1][arg2].unk0, D_8008446C[arg1][arg2].unk4);
    } else {
        func_1503DF0C(arg0 - gObjects, arg1, -1, -1);
    }
}

void func_1503DF0C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct106 *ptr = &D_800C6660[arg0];

    ptr->unk4 |= arg2;
    ptr->unk8 |= arg3;
    ptr->pad[2] = arg1;
    ptr->unkF = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503DF48.s")

s32 func_1503E1F4(s32 arg0, s32 arg1) {
    if (arg0 < 32) {
        if (D_800C6660[arg1].unk4 & (1 << arg0)) {
            return 1;
        }
    } else {
        if (D_800C6660[arg1].unk8 & (1 << arg0)) {
            return 1;
        }
    }
    return 0;
}

struct func_1503E260_s {
    void *unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    u8 unkE;
    u8 unkF;
};
extern u8 *D_80084460[];
extern u8 D_80098914[];
s32 func_1503E1F4(s32 arg0, s32 arg1);
void func_10004074(s32);

void func_1503E260(s32 arg0) {

    u8 *list;
    s32 i;
    s32 n;

    if (((struct func_1503E260_s *)D_800C6660)[arg0].unkF != 0) {
        list = D_80084460[((struct func_1503E260_s *)D_800C6660)[arg0].unkE];
        if (list != NULL) {
            n = D_80098914[((struct func_1503E260_s *)D_800C6660)[arg0].unkE];
            for (i = 0; i < n; i++) {
                if (list[i] != 0xFF) {
                    if (func_1503E1F4(i, arg0)) {
                        gObjects[arg0].unk94 |= 1 << list[i];
                    }
                }
            }
        }
        ((struct func_1503E260_s *)D_800C6660)[arg0].unkF = 0;
        if (((struct func_1503E260_s *)D_800C6660)[arg0].unk0) {
            func_10004074(((struct func_1503E260_s *)D_800C6660)[arg0].unk0);
        }
        ((struct func_1503E260_s *)D_800C6660)[arg0].unk0 = 0;
        gObjects[arg0].unk74 &= ~0x80;

    }
}

extern s8 *D_80084454[];
void func_1503E5F8(f32 (*)[4], f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *);
void func_150499A0(void *, f32 (*)[4]);
void func_150A7A48(f32 (*)[4], f32 (*)[4], f32 (*)[4]);

void func_1503E3C4(s32 arg0, s32 arg1, s32 arg2, f32 *arg3, s32 arg4) {
    s32 pad;
    f32 sp94[4][4];
    f32 sp54[4][4];
    struct127 *obj;
    s32 idx;
    f32 dx, dy, dz;
    f32 dist;

    obj = &gObjects[arg0];
    bcopy((u8 *)obj->unk1D4 + ((arg1 + arg2) << 6), sp94, 0x40);
    if (arg4 != 0) {
        idx = -1;
    } else {
        idx = D_80084454[((struct func_1503E260_s *)D_800C6660)[arg0].unkE][arg1];
    }
    if (idx != -1) {
        func_150499A0((u8 *)obj->unk1D4 + (idx << 6), sp54);
        sp94[1][3] = 0.0f;
        sp94[0][3] = 0.0f;
        sp94[2][3] = 0.0f;
        sp94[3][3] = 1.0f;
        func_150A7A48(sp94, sp54, sp94);
    }
    func_1503E5F8(sp94, &arg3[0], &arg3[1], &arg3[2], &arg3[3], &arg3[4], &arg3[5], &arg3[6], &arg3[7], &arg3[8]);
    arg3[10] = arg3[1];
    arg3[11] = arg3[2];
    arg3[12] = arg3[3];
    arg3[9] = arg3[0];
    arg3[13] = arg3[4];
    arg3[14] = arg3[5];
    arg3[15] = arg3[6];
    arg3[16] = arg3[7];
    arg3[17] = arg3[8];
    dx = arg3[9] - obj->x_position;
    dy = (arg3[10] - obj->y_position) - 30.0f;
    dz = arg3[11] - obj->z_position;
    dist = sqrtf(dx * dx + dy * dy + dz * dz);
    if (dist == 0.0f) {
        dist = 1.0f;
    }
    dist = 1.0f / dist;
    arg3[18] = dx * dist;
    arg3[19] = dy * dist;
    arg3[20] = dz * dist;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EA54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EB78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503ECA0.s")

void func_1503EEB8(void) {
}

struct func_1503EEC0_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
};

void func_1503EEC0(s32 arg0) {
    s32 v;
    struct func_1503EEC0_s *p;

    func_1503ECA0(arg0);
    p = &((struct func_1503EEC0_s *)D_800C6660)[arg0];
    v = p->unkC;
    v -= D_800BE9E4;
    p->unkC = v;
    if (v <= 0) {
        func_15060F28(&gObjects[arg0], 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EF4C.s")

struct func_1503EFC4_s {
    u8 *unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    u8 unkE;
    u8 unkF;
};
extern u8 D_80098914[];

void func_1503EFC4(s32 arg0) {
    struct func_1503EFC4_s *p = &((struct func_1503EFC4_s *)D_800C6660)[arg0];
    s32 i;
    s32 n;

    p->unkC = 0x78;
    n = D_80098914[p->unkE];
    for (i = 0; i < n; i++) {
        *(f32 *)(p->unk0 + i * 0x68 + 0x4C) = (s32)(func_150ADA20() % 20U) - 5;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F078.s")

void func_1503EB78(s32 arg0, f32 arg1, f32 arg2, s32 arg3);

void func_1503F0AC(s32 arg0, s32 arg1) {
    func_1503EB78(arg0, 1.0f, 2.0f, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F0D8.s")

struct func_1503F108_s {
    u8 *unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
};
struct func_1503F108_s2 {
    s32 unk0;
    u8 pad[0x328];
};
extern struct func_1503F108_s2 D_800CC364[];

void func_1503F108(s32 arg0) {
    struct func_1503F108_s *p = &((struct func_1503F108_s *)D_800C6660)[arg0];
    p->unkC = 0x8C;
    D_800CC364[arg0].unk0 = 6;
    *(f32 *)(p->unk0 + 0x1EC) = 10.0f;
}

struct func_1503F16C_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
};
s32 func_1503EF4C(s32 arg0, s32 arg1, s32 arg2);

void func_1503F16C(s32 arg0) {
    ((struct func_1503F16C_s *)D_800C6660)[arg0].unkC = 300;
    if (func_1503EF4C(2, 0, arg0)) {
        gObjects[arg0].unk94 |= 0x40;
        gObjects[arg0].unk94 &= ~0x200;
    }
    if (func_1503EF4C(2, 1, arg0)) {
        gObjects[arg0].unk94 |= 0x80;
        gObjects[arg0].unk94 &= ~0x100;
    }
    if (func_1503EF4C(2, 2, arg0)) {
        gObjects[arg0].unk94 &= ~0x400;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F404.s")
