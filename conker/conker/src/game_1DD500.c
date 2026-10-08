#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B0050.s")

extern f32 D_800AA2A0;
extern f32 D_800AA2A4;
extern f32 D_800AA2A8;
extern f32 D_800AA2AC;
extern f32 D_800AA2B0;
extern u8 D_800AA120[];
s32 func_15134070(void *);
void func_15153F18(void *, void *, void *, s32, s32);

struct func_151B01B8_s {
    s16 unk0[4];
    u8 unk8[0xC];
    f32 unk14[6];
    s16 unk2C[8];
    u8 unk3C;
    f32 unk40;
    s16 unk44;
    s16 unk46;
    s32 unk48;
};

void func_151B01B8(u8 *arg0, u8 *arg1) {
    struct func_151B01B8_s sp54;
    u8 sp53;
    u8 sp2C[0x24];
    s32 var_v0;

    if ((arg0 != NULL) && (*(s32 *)(arg0 + 0x1D4) != 0) && ((arg0[0x74] & 0xF) != 0xF)) {
        func_1504715C(sp2C, arg0);
        var_v0 = (arg1 != NULL) ? (((arg1[4] == 0x53) || (arg1[4] == 0xA5)) ? 4 : func_15134070(arg1)) : 4;
        if (var_v0 != 0x63) {
                        if (D_800A3FD8[var_v0 * 0x10 + 0xE] != 2) {
                sp53 = (*(u16 *)(arg0 + 0x7A) >> 8) + 0x40;
                func_15143134(D_800AA120, sp54.unk8, *(s32 *)(arg0 + 0x1D4) + 0x180);
                sp54.unk14[0] = D_800AA2A0;
                sp54.unk2C[0] = 0xA;
                sp54.unk2C[1] = 0x14;
                sp54.unk0[0] = sp53 - 0x68;
                sp54.unk0[1] = 0xD0;
                sp54.unk0[2] = -0x1B;
                sp54.unk0[3] = 0x36;
                sp54.unk2C[2] = 3;
                sp54.unk2C[3] = 2;
                sp54.unk2C[4] = 0x1E;
                sp54.unk2C[5] = 0x28;
                sp54.unk2C[6] = 0x9B;
                sp54.unk2C[7] = 0x64;
                sp54.unk14[1] = D_800AA2A4;
                sp54.unk14[2] = D_800AA2A8;
                sp54.unk14[3] = D_800AA2AC;
                sp54.unk14[4] = 6.0f;
                sp54.unk14[5] = D_800AA2B0;
                sp54.unk40 = 0.5f;
                if (D_800A3FD8[var_v0 * 0x10 + 0xE] == 1) {
                    sp54.unk3C = 1;
                } else {
                    sp54.unk3C = 0;
                }
                sp54.unk44 = 0x10;
                sp54.unk46 = 0xF;
                sp54.unk48 = 0;
                func_15153F18(&sp54, sp54.unk8, sp2C, 0xFF, 1);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B03B8.s")

s32 func_15134070(void *);
extern u8 D_800A3FE6[][16];

struct func_151B09BC_s {
    void *unk0;
    u8 unk4;
    s32 unk8;
    s32 unkC[11][3];
    f32 unk90;
    s8 unk94;
};

struct260 *func_151B09BC(void *arg0, void *arg1, s16 arg2, u8 arg3, s32 arg4) {
    struct260 *ret;
    struct func_151B09BC_s s;
    s32 type;
    s16 time;
    u8 flag;

    if (arg0 == NULL) {
        return NULL;
    }
    type = (arg1 != NULL) ? ((*((u8 *)arg1 + 4) == 0x53) || (*((u8 *)arg1 + 4) == 0xA5)) ? 4 : func_15134070(arg1) : 4;
    if (type == 0x63) {
        return NULL;
    }
    if (D_800A3FE6[type][0] == 2) {
        return NULL;
    }
    if (D_800A3FE6[type][0] == 1) {
        s.unk94 = 1;
    } else {
        s.unk94 = 0;
    }
    {
        struct {
            void *unk0;
            u8 unk4;
        } msg;

        msg.unk0 = arg0;
        msg.unk4 = *((u8 *)arg0 + 0x3B);
        func_151494E0((s32)&msg, 0x13);
    }
    flag = 0;
    if (arg2 == -1) {
        time = 0x12C;
    } else {
        time = arg2;
        flag = 1;
    }
    s.unk0 = arg0;
    s.unk4 = *((u8 *)arg0 + 0x3B);
    s.unk8 = 0;
    s.unk90 = 0.0f;
    {
        s32 i;
        for (i = 0; i < 11; i++) {
            s.unkC[i][0] = 0;
            s.unkC[i][1] = 0;
            s.unkC[i][2] = 0;
        }
    }
    ret = func_151491F4(time, -1, 0x13, flag, 0xF, (struct37 *)0x98, arg3, arg4);
    if (ret != NULL) {
        memcpy((u8 *)ret + 0x28, &s, 0x98);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B0B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B118C.s")

struct func_151B1478_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x5C - 0x1E];
    u8 unk5C;
};

s32 func_151B1478(struct func_151B1478_s *arg0) {
    s32 temp;
    if (arg0->unk1C < 32) {
        temp = arg0->unk1C * 8;
        if (temp < arg0->unk5C) {
            arg0->unk5C = temp;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B14AC.s")

struct func_151B1828_sub {
    u8 pad0[0x10];
    u8 unk10;
    u8 unk11;
    s8 unk12;
    s8 unk13;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

struct func_151B1828_s {
    u8 pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x110 - 0x34];
    struct func_151B1828_sub unk110;
};

s32 func_151B1828(struct func_151B1828_s *arg0) {
    struct func_151B1828_sub *sub;
    s32 pad;
    f32 f;
    f32 g;

    sub = &arg0->unk110;
    sub->unk10 += sub->unk12 * D_800BE9E4;
    sub->unk11 += sub->unk13 * D_800BE9E4;
    f = func_151423D8(sub->unk10 - 0x40);
    g = func_151423D8(sub->unk11 - 0x40);
    arg0->unk2C += ((sub->unk14 + sub->unk1C * f) - arg0->unk2C) * 0.5f;
    arg0->unk30 += ((sub->unk18 + sub->unk20 * g) - arg0->unk30) * 0.5f;
    return 1;
}

struct func_151B1918_e {
    struct102 *unk0;
    s32 unk4;
    s32 unk8;
};

struct func_151B1918_s {
    u8 pad0[0x28];
    struct func_151B1918_e unk28[12];
    f32 unkB8;
};

void func_151B1918(struct func_151B1918_s *arg0) {
    struct func_151B1918_e *arr = arg0->unk28;
    s32 i;
    arr->unk8 = 0;
    arg0->unkB8 = 0.0f;
    for (i = 0; i < 11; i++) {
        struct func_151B1918_e *e = &arr[i + 1];
        if (e->unk0 != 0) {
            func_1516972C(e->unk0);
        }
        e->unk0 = 0;
        e->unk4 = 0;
        e->unk8 = 0;
    }
}

typedef struct {
    s32 unk0;
    u8 unk4;
} func_151B19A4_sub;

struct func_151B19A4_s {
    u8 pad0[0x28];
    void *unk28;
    u8 unk2C;
};

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
} func_151B19A4_arg;

typedef struct {
    void *unk0;
    u8 unk4;
} func_151B19A4_arg2;

void func_151B19A4(struct func_151B19A4_s *arg0, void *arg1, u8 arg2) {
    void *temp = arg0->unk28;
    func_151B19A4_sub *p = (func_151B19A4_sub *)&arg0->unk28;
    func_151B19A4_arg *m;

    if (arg2 == 0 || arg2 == 0x13) {
        if (temp == ((func_151B19A4_arg2 *)arg1)->unk0 || ((func_151B19A4_arg2 *)arg1)->unk4 == arg0->unk2C) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        m = arg1;
        if (p->unk0 == m->unk0) {
            p->unk0 = m->unk4;
            p->unk4 = m->unk9;
        } else if (p->unk0 == m->unk4) {
            p->unk0 = m->unk0;
            p->unk4 = m->unk8;
        }
    }
}

void func_151B1918();

void func_151B1A58(s32 arg0) {
    func_151B1918(arg0);
    func_1514933C(arg0);
}

void func_151B1A84(s32 arg0) {
    func_151B1918(arg0);
    func_15149368(arg0);
}

struct func_151B1AB0_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
};

void func_151B1AB0(u8 *arg0) {
    struct260 *temp_v0;
    struct func_151B1AB0_s sp28;

    if (arg0 == NULL) {
        return;
    }
    sp28.unk0 = arg0;
    sp28.unk4 = arg0[0x3B];
    sp28.unk8 = 0.0f;
    temp_v0 = func_151491F4(0x3C, -1, 0x15, 1, 0x11, (struct37 *)0xC, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy(&temp_v0->pad18[0x10], &sp28, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1FAC.s")
