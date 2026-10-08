#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15147740_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u16 unk1E;
    u8 pad20[4];
    s8 unk24;
    u8 pad25[0x2F - 0x25];
    u8 unk2F;
    u8 unk30;
};

extern s32 (*D_8008A200[])(struct func_15147740_s *);
extern s32 (*D_8008A23C[])(struct func_15147740_s *);
extern s32 (*D_8008A284[])(struct func_15147740_s *);

void func_15147740(struct func_15147740_s *arg0) {
    s32 pad;
    s8 kill = 0;

    if (arg0->unk1E & 1) {
        arg0->unk1C -= D_800BE9E4;
        if (arg0->unk1C < 0) {
            kill = 1;
        }
    }
    if (arg0->unk2F >= 15) {
        func_1516972C((struct102 *)arg0);
        return;
    }
    if (arg0->unk2F != 0 && !kill) {
        if (!D_8008A200[arg0->unk2F](arg0)) {
            kill = 1;
        }
    }
    if (arg0->unk30 >= 18) {
        func_1516972C((struct102 *)arg0);
        return;
    }
    if (arg0->unk30 != 0 && !kill) {
        if (!D_8008A23C[arg0->unk30](arg0)) {
            kill = 1;
        }
    }
    if (arg0->unk1E & 0x10) {
        if (arg0->unk24 < -1 || arg0->unk24 >= 8) {
            func_1516972C((struct102 *)arg0);
            return;
        }
        if (arg0->unk24 != -1 && !kill) {
            if (!D_8008A284[arg0->unk24](arg0)) {
                kill = 1;
            }
        }
    }
    if (kill) {
        func_1516972C((struct102 *)arg0);
    }
}

void func_151478D0(u8 *arg0) {
    func_151D5E30(arg0 + 0x84, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_151478F4.s")

void func_15147928(s32 arg0) {
    func_151478D0(arg0);
    func_1514795C(arg0);
    func_15169824(arg0);
}

int func_1514795C(s32 arg0) {
    s32 i;

    for (i = 0; i <= D_80082FA0; i++) {
        if (((s32 *)arg0)[i + 15]) {
            func_100043B4(((s32 *)arg0)[i + 15], 4);
        }
    }
    if (((s32 *)arg0)[19] != 0) {
        func_100043B4(((s32 *)arg0)[19], 4);
    }
}

extern void (*D_8008A2F0[])(void *);

struct func_151479E0_s {
    u8 pad[0x20];
    s32 unk20;
};

void func_151479E0(struct func_151479E0_s *arg0) {
    s32 idx = arg0->unk20;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 20) {
        idx = 0;
    }
    D_8008A2F0[idx](arg0);
}

extern void (*D_8008A340[])(s32 *);

void func_15147A30(s32 *arg0) {
    s32 idx = arg0[8];

    if (idx < 0) {
        idx = 0;
    } else if (idx >= 20) {
        idx = 0;
    }
    D_8008A340[idx](arg0);
}

struct func_15147A80_src {
    u8 pad0[0xE];
    u16 unkE;
    u8 pad10[5];
    u8 unk15;
    u8 pad16[6];
};

struct func_15147A80_blk {
    s32 w[9];
};

struct func_15147A80_s {
    u8 pad0[0x10];
    struct func_15147A80_src unk10;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    u8 unk30;
    u8 unk31;
    u8 pad32[2];
    s32 unk34;
    u8 unk38;
    u8 pad39[3];
    s32 unk3C[4];
    s32 unk4C;
    s32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    struct func_15147A80_blk unk60;
    u8 pad84[0x10];
    void *unk94;
    void *unk98;
    u8 pad9C[4];
};

extern void *func_15167A68(s32, s32, s32, s32, u8, s32);
extern s32 func_1515D480(s32);
extern s32 func_1515D440(void);

struct func_15147A80_s *func_15147A80(struct func_15147A80_src *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, struct func_15147A80_blk *arg8, u8 arg9, s32 arg10) {
    struct func_15147A80_s *p;
    s32 i;
    u8 type;
    s32 tmp;

    tmp = arg0->unk15 * arg2;
    if (arg0->unkE & 0x40) {
        type = 0x4D;
    } else {
        type = 0x22;
    }
    p = func_15167A68(type, arg10, arg1 + tmp + 0xA0, 1, arg9, 1);
    if (p == NULL) {
        return NULL;
    }
    p->unk98 = (u8 *)p + 0xA0;
    p->unk94 = (u8 *)p->unk98 + arg1;
    memcpy(&p->unk10, arg0, 0x1C);
    p->unk2C = 0;
    p->unk2D = 0;
    p->unk2E = 0;
    p->unk2F = arg3;
    p->unk30 = arg4;
    p->unk31 = arg5;
    if (arg8 != NULL) {
        p->unk60 = *arg8;
    } else {
        ((u8 *)&p->unk60)[0x1C] = 0;
    }
    p->unk34 = arg6;
    p->unk50 = arg7;
    p->unk38 = 0;
    for (i = 0; i < 4; i++) {
        p->unk3C[i] = 0;
    }
    p->unk4C = 0;
    if (arg6 != 0) {
        for (i = 0; i <= D_80082FA0; i++) {
            p->unk3C[i] = func_1515D480(arg6);
        }
        p->unk4C = func_1515D440();
    }
    p->unk54 = 0.0f;
    p->unk58 = 0.0f;
    p->unk5C = 0.0f;
    bzero(p->pad84, 0x10);
    return p;
}

struct func_15147C4C_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[0x8];
    s32 unk28;
    u8 pad2C[0x5];
    u8 unk31;
    u8 pad32[0x2];
    u8 unk34[0x20];
    u8 unk54[0x4];
};

extern s32 func_151462C8();
extern s32 (*D_8008A2A4[])(struct func_15147C4C_s *, s32, s16);

s32 func_15147C4C(s32 arg0, struct func_15147C4C_s *arg1, s16 arg2) {
    arg0 = func_151462C8(arg0, arg1->unk34, 0, 0, 0, arg2, arg1->unk54, 2,
                         (arg1->unk1E & 0x20) ? arg1->unk28 : 0);
    if (arg1->unk31 >= 0x13) {
        func_1516972C((struct102 *)arg1);
        return arg0;
    }
    if (arg1->unk31 != 0) {
        return D_8008A2A4[arg1->unk31](arg1, arg0, arg2);
    }
    return arg0;
}

struct func_15147D1C_s {
    char pad0[0x20];
    s32 unk20;
};
extern void (*D_8008A390[])(struct func_15147D1C_s *, s32, u8);

void func_15147D1C(struct func_15147D1C_s *arg0, s32 arg1, u8 arg2) {
    void (*func)(struct func_15147D1C_s *, s32, u8) = D_8008A390[arg0->unk20];
    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

extern u8 D_800A5760[];

void func_15147D64(void *arg0, u8 arg1) {
    func_15169260(&D_800A5760, 2, arg0, arg1);
}
