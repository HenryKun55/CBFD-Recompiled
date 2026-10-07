#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150D8B10(f32 *arg0, f32 *arg1) {
    arg1[0] = arg0[5];
    arg1[1] = arg0[6] + 20.0f;
    arg1[2] = arg0[7];
}

extern f32 D_800A0B40;
extern f32 D_800A0B44;
void func_15145740(void *arg0, f32 *arg1, f32 *arg2, void *arg3, f32 arg4);

void func_150D8B3C(void *arg0, void *arg1) {
    f32 sp34[3];
    f32 sp28[3];

    func_15145740(arg0, sp34, sp28, arg1, D_800BE616 ? D_800A0B40 : D_800A0B44);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8B88.s")

struct func_150D8D84_s {
    f32 x, y, z;
};
extern f32 D_800A0B4C;
extern f32 D_800A0B50;

void func_150D8D84(struct func_150D8D84_s *pos, struct func_150D8D84_s *vel, f32 dt) {
    struct func_150D8D84_s v;

    v = *vel;
    vel->y += D_800A0B4C * dt;
    pos->x += v.x * dt;
    pos->y += v.y * dt + D_800A0B50 * dt * dt;
    pos->z += v.z * dt;
}

struct func_150D8E1C_s {
    u8 pad0[0x1C];
    u16 unk1C;
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
};

void func_150D8E1C(struct func_150D8E1C_s *arg0) {
    arg0->unk30 = 0;
    arg0->unk1E &= ~2;
    arg0->unk1E |= 8;
    arg0->unk1E |= 1;
    arg0->unk1C = 0x28;
}

struct func_150D8E4C_e {
    struct func_150D8D84_s pos;
    struct func_150D8D84_s vel;
    u8 pad18[0xC];
};

struct func_150D8E4C_t {
    u8 pad0[0x31C];
    struct { u8 pad[0x1AA]; s16 unk1AA; } *unk31C;
};

struct func_150D8E4C_o {
    struct func_150D8E4C_t *unk0;
    u8 pad4[0x49];
    s8 unk4D;
};

struct func_150D8E4C_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[5];
    u8 unk25;
    u8 pad26[6];
    s8 unk2C;
    s8 unk2D;
    s8 unk2E;
    u8 pad2F[0x25];
    struct func_150D8D84_s unk54;
    u8 pad60[0x34];
    struct func_150D8E4C_e *unk94;
    struct func_150D8E4C_o *unk98;
};

s32 func_150D8E4C(struct func_150D8E4C_s *arg0) {
    struct func_150D8E4C_o *o = arg0->unk98;
    struct func_150D8E4C_e *e = arg0->unk94;
    s32 i;

    if (arg0->unk2C < 2 && (arg0->unk1E & 8)) {
        return 0;
    }
    i = arg0->unk2E;
    while (i != arg0->unk2D) {
        i--;
        if (i < 0) {
            i = arg0->unk25 - 1;
        }
        func_150D8D84(&e[i].pos, &e[i].vel, D_800BE9A4);
    }
    {
        struct func_150D8D84_s *p = &arg0->unk54;
        if (arg0->unk2C > 0) {
            *p = e[arg0->unk2D].pos;
        } else {
            arg0->unk54.x = 0.0f; arg0->unk54.y = 0.0f; arg0->unk54.z = 0.0f;
        }
    }
    o->unk4D += D_800BE9E4;
    if (o->unk4D >= 0x3D) {
        if (o->unk0 != NULL && o->unk0->unk31C != NULL) {
            o->unk0->unk31C->unk1AA++;
        }
        o->unk4D = 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8FAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D942C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D9C7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150DA484.s")

void func_150DA484(s32 arg0);
void func_151478F4(s32 arg0);

void func_150DA4B4(s32 arg0) {
    func_150DA484(arg0);
    func_151478F4(arg0);
}

void func_150DA4E0(s32 arg0) {
    func_150DA484(arg0);
    func_15147928(arg0);
}

struct func_150DA50C_s {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x37];
    f32 unk3C;
};

struct func_150DA50C_msg {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

struct func_150DA50C_msg2 {
    s32 unk0;
    u8 unk4;
    u8 pad5[3];
    f32 unk8;
};

void func_150DA50C(struct102 *arg0, struct func_150DA50C_msg *arg1, u8 arg2) {
    struct func_150DA50C_s *v0 = *(struct func_150DA50C_s **)((u8 *)arg0 + 0x98);

    if (arg2 == 0x44) {
        struct func_150DA50C_msg2 *m = (struct func_150DA50C_msg2 *)arg1;
        if (m->unk0 == v0->unk0 || m->unk4 == v0->unk4) {
            v0->unk3C = m->unk8;
        }
    } else if (arg2 == 0) {
        struct func_150DA50C_msg2 *m = (struct func_150DA50C_msg2 *)arg1;
        s32 t = m->unk0;
        if (t == v0->unk0 || v0->unk4 == m->unk4) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (v0->unk0 == arg1->unk0) {
            v0->unk0 = arg1->unk4;
            v0->unk4 = arg1->unk9;
        } else if (v0->unk0 == arg1->unk4) {
            v0->unk0 = arg1->unk0;
            v0->unk4 = arg1->unk8;
        }
    }
}

struct func_150DA5EC_s {
    u8 *ptr;
    u8 b;
    f32 f;
};

void func_150DA5EC(u8 *arg0, f32 arg1) {
    struct func_150DA5EC_s s;

    s.ptr = arg0;
    s.b = arg0[0x3B];
    s.f = arg1;
    func_15147D64(&s, 0x44);
}

void *func_15131828();
void *func_15131958();

s32 func_150DA628(u8 *arg0, s32 arg1) {
    u8 *temp_a2 = arg0 + 0xA8;

    func_15131828(arg0, arg0 + 0xAC, temp_a2, arg0 + 0xAA);
    func_15131958(arg0 + 0x58, *(s32 *)(temp_a2 + 0xC), temp_a2);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150DA67C.s")
