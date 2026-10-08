#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502BAD0.s")

struct func_1502BD84_s {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 pad6[0xA4 - 0x6];
    u8 unkA4;
    u8 padA5[0xF8 - 0xA5];
    s32 unkF8;
    u8 padFC[0x134 - 0xFC];
    u8 unk134;
    u8 unk135;
    u8 pad136[0x1C9 - 0x136];
    u8 unk1C9;
    u8 pad1CA[0x1D4 - 0x1CA];
    s32 unk1D4;
    u8 pad1D8[0x1FC - 0x1D8];
    u8 unk1FC;
    u8 pad1FD[0x260 - 0x1FD];
    s32 unk260;
};

void func_1502DF38(s32, s32);
void func_1502C608(s32);
void func_1502FBE8(struct func_1502BD84_s *);
void func_1502E4C4(s32);
void func_1503A08C(struct func_1502BD84_s *);
void func_150345E4(s32);
void func_1503A830(struct func_1502BD84_s *);
void func_1502EEF4(s32);
void func_1502F264(s32);
void func_1502EAFC(struct func_1502BD84_s *);
void func_150A4B04(struct func_1502BD84_s *);

void func_1502BD84(struct func_1502BD84_s *arg0, s32 arg1) {
    arg0->unk1D4 = 0;
    if (arg0->unk5 == 5) {
        func_1502DF38(arg1, 1);
        return;
    }
    if (arg0->unk4 == 0xFF) {
        return;
    }
    if (arg0->unk5 == 3) {
        return;
    }
    if (arg0->unk5 == 2) {
        func_1502C608(arg1);
        return;
    }
    if (arg0->unk1C9 != 0) {
        func_1502FBE8(arg0);
    }
    func_1502E4C4(arg1);
    func_1502DF38(arg1, 0);
    func_1503A08C(arg0);
    if (arg0->unk1D4 == 0) {
        arg0->unk1FC = 2;
    } else {
        func_150345E4(arg1);
        func_1503A830(arg0);
    }
    if (D_800C6660[arg1].unkF != 0) {
        func_1503DF48(arg1);
    }
    if (arg0->unk0 != 0) {
        func_1502EEF4(arg1);
        func_1502F264(arg1);
        if (arg0->unkA4 != 0) {
            func_1502EAFC(arg0);
        }
        if (arg0->unkF8 & 0x4000) {
            func_150A4B04(arg0);
        }
        if (arg0->unk260 != 0) {
            func_1517AD00(arg0->unk134, arg0->unk135, arg1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502BEE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C1A4.s")

extern s32 D_800C3E88;
extern s32 D_800C3E8C;
extern s16 D_800C3E7A;

void func_1502C380(void) {
    D_800C3E8C = D_800C3E88 = (&D_800C3E80)[D_800BE9C0];
    D_800C3E7A = 0;
}

extern u8 D_800CC406[];

s32 func_1502C3BC(s32 arg0) {
    s32 v = D_800CC406[arg0 * 0x32C];
    if (v >= 0x46) {
        v = 0xB;
    }
    return v;
}

struct func_1502C408_s {
    s16 x;
    s16 y;
    s16 z;
    s16 unk6;
    s16 unk8;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 padE[6];
};

extern Gfx D_800873D0[];
extern Gfx D_80087408[];
extern struct func_1502C608_s *D_8008CA4C[];
Gfx *func_15094F70(Gfx *, void *, s32, void *, s32, s32, s32, s32, s32);
Gfx *func_15095760(Gfx *, void *);

Gfx *func_1502C408(Gfx *gdl, s32 arg1) {
    struct func_1502C408_s sp6C;
    s32 h;
    s32 w;
    Gfx *gfx;
    u8 size;
    s16 a2;
    s32 unk7;
    s32 idx;

    if (D_800BEAC0 != 0) {
        return gdl;
    }
    unk7 = gObjects[arg1].unk7;
    size = gObjects[arg1].unk122;
    a2 = ((s16 *)&gObjects[arg1].unk60)[0];
    if (unk7 == 0) {
        return gdl;
    }
    h = size * 19;
    w = h;
    if (gObjects[arg1].interaction_state == 3) {
        h = size * 15;
        w = h;
    }
    idx = func_1502C3BC(arg1);
    gSPDisplayList(gdl++, D_800873D0);
    gDPPipeSync(gdl++);
    if (0) {}
    gfx = func_15094F70(gdl, D_8008CA4C[idx], a2, &sp6C, 0, 0, 0, 2, 3);
    sp6C.unkD = 0;
    sp6C.unk6 = h;
    sp6C.unk8 = w;
    sp6C.unkA = unk7;
    sp6C.x = gObjects[arg1].x_position;
    sp6C.y = gObjects[arg1].y_position + (size / 2);
    sp6C.z = gObjects[arg1].z_position;
    gfx = func_15095760(gfx, &sp6C);
    gSPDisplayList(gfx++, D_80087408);
    return gfx;
}

struct func_1502C608_s {
    u8 pad0[4];
    u8 unk4;
};
extern struct func_1502C608_s *D_8008CA4C[];

void func_1502C608(s32 arg0) {
    s32 max;
    s16 a;
    s16 b;

    if (D_800BEAC0 == 0) {
        a = ((s16 *)&gObjects[arg0].unk60)[0];
        b = ((s16 *)&gObjects[arg0].unk60)[1];
        if (gObjects[arg0].unk7 != 0) {
            max = D_8008CA4C[func_1502C3BC(arg0)]->unk4 << 8;
            a += b;
            if (a >= max) {
                a -= max;
            } else if (a < 0) {
                a += max;
            }
            ((s16 *)&gObjects[arg0].unk60)[0] = a;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C6E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C974.s")

struct func_1502CC34_s {
    u8 pad0[0xA4];
    u8 unkA4;
};

void func_1502EC34(struct func_1502CC34_s *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4);

void func_1502CC34(struct func_1502CC34_s *arg0, s32 arg1, s32 arg2, s32 *arg3,
                   s32 *arg4, s32 *arg5, s32 *arg6, s32 *arg7, s32 *arg8, s32 *arg9,
                   s32 *argA, s32 *argB, s32 *argC, s32 *argD) {
    *arg4 = D_800D9B68[arg1][0];
    *arg5 = D_800D9B68[arg1][1];
    *arg6 = D_800D9B68[arg1][2];
    *arg7 = D_800D9B78[arg1][0];
    *arg8 = D_800D9B78[arg1][1];
    *arg9 = D_800D9B78[arg1][2];
    *argA = 0;
    *argB = 0;
    *argC = 0;
    *argD = arg3[3];
    if (arg0->unkA4) {
        func_1502EC34(arg0, argA, argB, argC, argD);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502CCFC.s")

void func_1502D54C(s32 arg0, s32 *arg1) {
    u8 *p = (u8 *)&gObjects[arg0];
    if ((p[0x66] & 0xC) == 4) {
        arg1[0] = (p[0x1E0] + p[0x1DD]) / 2;
        arg1[1] = (p[0x1E1] + p[0x1DE]) / 2;
        arg1[2] = (p[0x1E2] + p[0x1DF]) / 2;
        arg1[0] = 0xFF - arg1[0];
        arg1[1] = 0xFF - arg1[1];
        arg1[2] = 0xFF - arg1[2];
    } else {
        arg1[0] = arg1[1] = arg1[2] = 0xFF;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502D630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502D824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DF38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502E474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502E4C4.s")

void func_1502E9FC(s32 arg0, s32 arg1) {
}

struct func_1502EA0C_s {
    u8 pad0[0xA0];
    s32 unkA0;
    u8 unkA4;
    u8 unkA5;
    u8 unkA6;
    u8 unkA7;
};

void func_1502EA0C(struct func_1502EA0C_s *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    arg0->unkA4 = 4;
    arg0->unkA5 = 0;
    arg0->unkA6 = arg5;
    arg0->unkA0 = (arg4 << 24) | (arg1 << 16) | (arg2 << 8) | arg3;
    arg0->unkA7 = 0xFF;
}

void func_1502EA50(s32 arg0) {
    *(u8 *)(arg0 + 0xA4) = 5;
}

struct func_1502EA60_s {
    u8 pad0[0xA4];
    u8 unkA4;
    u8 unkA5;
    u8 unkA6;
};

void func_1502EA60(struct func_1502EA60_s *arg0, s32 arg1) {
    arg0->unkA4 = 2;
    arg0->unkA5 = 0xFF;
    arg0->unkA6 = arg1;
}

void func_1502EA7C(u8 *arg0, s32 arg1) {
    arg0[0xA4] = 3;
    arg0[0xA5] = 0xFF;
    arg0[0xA6] = arg1;
}

struct func_1502EA98_s {
    u8 pad0[0xA0];
    s32 unkA0;
    u8 unkA4;
    u8 unkA5;
    u8 unkA6;
};

void func_1502EA98(struct func_1502EA98_s *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if ((arg0->unkA4 != 6) && (arg0->unkA4 != 7)) {
        if (arg5) {
            arg0->unkA5 = 0xFF;
        } else {
            arg0->unkA5 = 0;
        }
        arg0->unkA0 = (arg4 << 24) | (arg1 << 16) | (arg2 << 8) | arg3;
        arg0->unkA6 = arg6;
    }
    arg0->unkA4 = 6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EAFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EC34.s")

extern u8 D_800CC33A[];
s32 func_1502EE8C(s32 arg0, s32 arg1) {
    s32 v = D_800CC33A[arg0 * 0x32C + arg1];
    s32 ret;
    if (v >= 2) { ret = (v >= 4) ? 2 : v - 2; } else { ret = v; }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EEF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F01C.s")

struct func_1502F264_s {
    u8 pad0[0x30];
    f32 x;
    f32 y;
    f32 z;
    u8 pad3C[4];
};

void func_1502F264(s32 arg0) {
    struct127 *obj = &gObjects[arg0];
    struct127 *parent;
    struct func_1502F264_s *m;
    s32 i;

    if (obj->unk65 == 0) {
        return;
    }
    parent = &gObjects[obj->unk65 - 1];
    if ((obj->unk101 & 2) == 2) {
        return;
    }
    m = (struct func_1502F264_s *)parent->unk1D4;
    if (m == NULL) {
        obj->x_position = parent->x_position;
        obj->y_position = parent->y_position;
        obj->z_position = parent->z_position;
    } else {
        m += obj->unk5C;
        obj->x_position = m->x;
        obj->y_position = m->y;
        obj->z_position = m->z;
    }
    obj->unk180 = parent->unk180;
    obj->y_velocity = -4.0f;
    if (!(obj->unk101 & 0x20)) {
        obj->unk76 = parent->unk76;
        obj->xz_velocity = parent->xz_velocity;
        obj->unk40 = parent->unk40;
        obj->unk76 = parent->unk76;
        obj->unk7A = parent->unk7A;
        obj->unk78 = parent->unk78;
    }
    if (!(obj->unk101 & 0x40)) {
        obj->unk7 = parent->unk7;
        obj->unk8 = parent->unk8;
        obj->unk9 = parent->unk9;
        obj->unkA = parent->unkA;
        obj->unkE.ub[1] = parent->unkE.ub[1];
        for (i = 0; i <= D_80082FA0; i++) {
            (&obj->unkB)[i] = (&parent->unkB)[i];
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F3C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F490.s")

extern void *allocate_memory(s32, s32, s32, s32);

struct func_1502F948_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0xF8 - 5];
    s32 unkF8;
    u8 padFC[0x1D4 - 0xFC];
    void *unk1D4;
    void *unk1D8;
    u8 pad1DC[0x264 - 0x1DC];
    s32 unk264;
};

void func_1502F948(struct func_1502F948_s *arg0) {
    s32 idx;

    if ((arg0->unkF8 & 0x4000) && (arg0->unk264 != 0) && (arg0->unk1D4 != NULL)) {
        idx = arg0->unk4;
        if (arg0->unk1D8 == NULL) {
            arg0->unk1D8 = allocate_memory(D_800C4ED0[idx] << 6, 1, 1, 2);
            if (arg0->unk1D8 == NULL) {
                return;
            }
        }
        bcopy(arg0->unk1D4, arg0->unk1D8, D_800C4ED0[idx] << 6);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502FBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502FD70.s")
