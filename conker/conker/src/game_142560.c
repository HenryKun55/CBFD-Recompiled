#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_151150B0(s32 arg0) {
}

struct func_151150BC_s {
    u8 pad0[8];
    f32 unk8;
    u8 padC[0x3C - 0xC];
    s32 unk3C;
    u8 pad40[0x68 - 0x40];
    f32 unk68;
};

void func_151150BC(struct func_151150BC_s *arg0) {
    arg0->unk68 = ((arg0->unk3C >> 16) * D_800BE9E4) * (1.0f / 256.0f);
    arg0->unk8 += arg0->unk68;
    if (arg0->unk8 < 0.0f) {
        arg0->unk8 += 360.0f;
    } else if (arg0->unk8 >= 360.0f) {
        arg0->unk8 -= 360.0f;
    }
}

struct func_1511515C_s {
    u8 pad0[0x4];
    f32 unk4;
    u8 pad8[0x3C - 0x8];
    s32 unk3C;
    u8 pad40[0x64 - 0x40];
    f32 unk64;
};

void func_1511515C(struct func_1511515C_s *arg0) {
    arg0->unk64 = (arg0->unk3C >> 16) * D_800BE9E4 * (1.0f / 256.0f);
    arg0->unk4 += arg0->unk64;
    if (arg0->unk4 < 0.0f) {
        arg0->unk4 += 360.0f;
    } else if (arg0->unk4 >= 360.0f) {
        arg0->unk4 -= 360.0f;
    }
}

struct func_151151FC_s {
    f32 unk0;
    u8 pad4[0x38];
    s32 unk3C;
    u8 pad40[0x20];
    f32 unk60;
};

void func_151151FC(struct func_151151FC_s *arg0) {
    arg0->unk60 = (f32)((arg0->unk3C >> 16) * D_800BE9E4) * (1.0f / 256.0f);
    arg0->unk0 += arg0->unk60;
    if (arg0->unk0 < 0.0f) {
        arg0->unk0 += 360.0f;
    } else if (arg0->unk0 >= 360.0f) {
        arg0->unk0 -= 360.0f;
    }
}

void func_1511529C(s32 arg0) {
}

extern f32 D_800A2F8C;

struct func_151152A8_s {
    u8 pad0[0x12];
    s16 unk12;
    u8 pad14[0x3C - 0x14];
    s32 unk3C;
    u8 pad40[0x4F - 0x40];
    u8 unk4F;
    u8 pad50[0x7C - 0x50];
    s32 unk7C;
};

void func_151152A8(struct func_151152A8_s *arg0) {
    if (arg0->unk7C == 0) {
        arg0->unk7C = arg0->unk12;
    }
    if (arg0->unk4F & 4) {
        if ((arg0->unk7C - arg0->unk12) < (s16)arg0->unk3C) {
            arg0->unk12 -= (s16)(arg0->unk3C >> 16) * D_800BE9E4;
        }
    } else {
        arg0->unk12 = arg0->unk12 + (arg0->unk7C - arg0->unk12) * D_800A2F8C * D_800BE9E4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15115368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151155C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511575C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15115E0C.s")

struct func_15115EDC_s {
    u8 pad0[0x7C];
    f32 unk7C;
    f32 unk80;
    u16 unk84;
};

void func_15115E0C(struct func_15115EDC_s *arg0, struct func_15115EDC_s *arg1);

void func_15115EDC(struct func_15115EDC_s *arg0, struct func_15115EDC_s *arg1) {
    f32 x;
    f32 z;
    f32 cx;
    f32 cz;

    x = arg0->unk7C;
    z = arg0->unk80;
    func_15115E0C(arg0, arg1);
    if (arg1->unk84 == 0x4B) {
        cx = arg0->unk7C;
        cz = arg0->unk80;
        x = (cx - x) * 4.0f;
        z = (cz - z) * 4.0f;
        arg0->unk7C = cx + x;
        arg0->unk80 = cz + z;
    }
}

struct func_15115F68_s {
    f32 unk0;
    u8 pad4[0x38];
    s32 unk3C;
    u8 pad40[0x3C];
    f32 unk7C;
    f32 unk80;
};
void func_15115F68(struct func_15115F68_s *arg0) {
    s8 a, b, c, d;

    a = arg0->unk3C; b = arg0->unk3C >> 16;
    c = arg0->unk3C >> 8; d = arg0->unk3C >> 24;
    if ((s8)arg0->unk3C != 0) {
        arg0->unk0 += arg0->unk7C / a + b;
    } else {
        arg0->unk0 += b * D_800BE9E4;
    }
    if (arg0->unk0 > c) {
        arg0->unk0 = c;
    } else if (arg0->unk0 < d) {
        arg0->unk0 = d;
    }
    arg0->unk7C = arg0->unk80 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511617C.s")

struct func_151162D4_s {
    u8 pad0[0x12];
    s16 unk12;
    u8 pad14[4];
    f32 unk18;
    u8 pad1C[0x20];
    u32 unk3C;
    u8 pad40[0x1C];
    s16 unk5C;
    u8 pad5E[0x1E];
    s32 unk7C;
};

#define S ((struct func_151162D4_s *)arg0)

void func_151162D4(struct131 *arg0) {
    f32 amp;
    u32 speed;
    s16 prev;
    f32 temp;

    prev = S->unk12 + S->unk18;
    amp = (s16)(S->unk3C & 0xFFFF);
    speed = (u16)((s32)S->unk3C >> 16);
    temp = cosf(S->unk7C * 0.0054931640625f) * amp;
    S->unk18 = temp;
    S->unk7C += speed * D_800BE9E4;
    S->unk5C = (S->unk12 + temp) - prev;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151163C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511650C.s")

struct func_15116888_s {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x1C];
    f32 unk3C;
    u8 pad40[0x36];
    u16 unk76;
};

s32 func_150490A8(struct17 *arg0);

s32 func_15116888(s32 arg0, s32 arg1, s32 arg2, struct func_15116888_s *arg3) {
    s32 x;
    s32 z;
    s32 v;
    s32 r;
    u8 pad[8];
    struct17 sp1C;
    f32 f;

    x = arg3->unk14;
    z = arg3->unk1C;
    sp1C.unk0 = x - arg0;
    sp1C.unk8 = z - arg1;
    r = func_150490A8(&sp1C);
    v = arg3->unk76;
    v = 0x40 - (v >> 8);
    v -= r;
    f = func_15048A40(v);
    f = f * arg3->unk3C;
    return f;
}

void func_15116924(s32 arg0) {
}

struct func_15116930_s {
    u8 pad0[0x4F];
    u8 unk4F;
    u8 pad50[0x73 - 0x50];
    u8 unk73;
};

void func_15116930(struct func_15116930_s *arg0, void *arg1) {
    if (arg0->unk4F & 4) {
        if (!(arg0->unk73 & 3) && !(arg0->unk73 & 4)) {
            if (*(u8 *)(*(u8 **)((u8 *)arg1 + 0x31C) + 0x57) == 1) {
                arg0->unk73 &= ~3;
                arg0->unk73 |= 2;
            }
        }
    }
}

struct func_15116984_s {
    u8 pad[0x73];
    u8 unk73;
};

void func_151169B4(struct func_15116984_s *arg0);

void func_15116984(struct func_15116984_s *arg0) {
    if (arg0->unk73 & 2) {
        func_151169B4(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151169B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116BAC.s")

struct func_15116D7C_s {
    f32 unk0[3];
    u8 padC[0x3C - 0xC];
    s32 unk3C;
    u8 pad40[0x60 - 0x40];
    f32 unk60[3];
    u8 pad6C[0x7C - 0x6C];
    f32 unk7C[3];
};

void func_15116D7C(struct func_15116D7C_s *arg0) {
    f32 step;
    f32 dt;
    s32 i;
    f32 *rot;
    f32 *cur;
    f32 *tgt;

    step = arg0->unk3C * (1.0f / 256.0f);
    dt = D_800BE9E4;
    cur = arg0->unk60;
    tgt = arg0->unk7C;
    rot = arg0->unk0;
    for (i = 0; i < 3; i++) {
        if (cur[i] != tgt[i]) {
            if (tgt[i] < cur[i]) {
                cur[i] -= step;
                if (cur[i] < tgt[i]) {
                    cur[i] = tgt[i];
                }
            } else {
                cur[i] += step;
                if (tgt[i] < cur[i]) {
                    cur[i] = tgt[i];
                }
            }
        }
        rot[i] += cur[i] * dt;
        if (rot[i] < 0.0f) {
            rot[i] += 360.0f;
        } else if (rot[i] >= 360.0f) {
            rot[i] -= 360.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151172D8.s")

f32 func_151172D8(void *arg0, s32 arg1);

void func_151174A0(void *arg0) {
    *(f32 *)((u8 *)arg0 + 8) = func_151172D8(arg0, *(s32 *)((u8 *)arg0 + 8));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151174C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151174F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117518.s")

f32 func_15117518(f32 *arg0, f32 arg1);

void func_15117770(f32 *arg0) {
    *arg0 = func_15117518(arg0, *arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151177C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151179BC.s")

struct func_15117D3C_s {
    u8 pad0[0x3C];
    s32 unk3C;
    u8 pad40[0x4F - 0x40];
    u8 unk4F;
    u8 pad50[0x73 - 0x50];
    u8 unk73;
};

void func_15117D3C(struct func_15117D3C_s *arg0, s32 *arg1) {
    s32 temp = arg0->unk3C & 0xFFFF;

    if (*arg1 == 1) {
        if (arg0->unk4F & 4) {
            if (!(arg0->unk73 & 3) && !(arg0->unk73 & 4)) {
                if (temp == 0 || *(u8 *)(*(u8 **)((u8 *)arg1 + 0x31C) + 0x57) == 1) {
                    arg0->unk73 &= ~3;
                    arg0->unk73 |= 2;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117F3C.s")

void func_1511896C(s32 arg0) {
    func_151189AC(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511898C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151189AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15118F24.s")

struct func_151193AC_s {
    u8 pad[0x73];
    u8 unk73;
};

void func_151193AC(struct func_151193AC_s *arg0, s32 *arg1) {
    if (arg1[0] == 1 && ((u8 *)arg1)[0x65] == 0) {
        if (!(arg0->unk73 & 3) && !(arg0->unk73 & 4)) {
            arg0->unk73 &= ~3;
            arg0->unk73 |= 2;
        }
    }
}

struct func_151193F4_s {
    u8 pad0[0x12];
    s16 unk12;
    u8 pad14[0x3C - 0x14];
    s32 unk3C;
    u8 pad40[0x73 - 0x40];
    u8 unk73;
    u8 pad74[0x7C - 0x74];
    s32 unk7C;
    s32 unk80;
    s32 unk84;
};

void func_151193F4(struct func_151193F4_s *arg0) {
    s32 step;
    s32 target;
    s32 diff;
    s32 mul;
    s32 base;
    s32 hi;

    if (arg0->unk84 == 0) {
        arg0->unk84 = arg0->unk12 | 0x80000000;
    }
    step = arg0->unk7C;
    if (step != 0) {
        mul = arg0->unk80;
        base = (s16)(arg0->unk84 & 0xFFFF);
        hi = arg0->unk3C;
        hi = (u16)(hi >> 16);
        arg0->unk73 &= ~3;
        target = (s32)(hi * mul) / 256 + base;
        if (target != arg0->unk12) {
            diff = arg0->unk12 - target;
            if (diff < 0) {
                if (-diff < step) {
                    arg0->unk12 = target;
                } else {
                    arg0->unk12 = arg0->unk12 + step;
                }
            } else {
                if (diff < step) {
                    arg0->unk12 = target;
                } else {
                    arg0->unk12 = arg0->unk12 - step;
                }
            }
            arg0->unk73 |= 0;
        } else {
            arg0->unk73 |= 3;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151194D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151196D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15119938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15119FC0.s")

s32 func_1511A410(s8 *arg0, s32 *arg1) {
    s32 count;
    s32 sp[2];
    s32 i;

    sp[0] = 0;
    sp[1] = 0;
    count = 0;
    for (i = 0; arg0[i << 3] != -0x21 && count < 2; i++) {
        switch (arg0[i << 3]) {
            case -3:
                sp[count] = i;
                count++;
        }
    }
    *arg1 = sp[1];
    return sp[0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511A494.s")

void func_15116110(void *arg0);
void func_1511A494(void *arg0, void *arg1, void *arg2);

void func_1511A6FC(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x3C) != 0) {
        func_15116110(arg0);
    }
    func_1511A494(arg0, arg0 + 0x80, arg0 + 0x84);
}

s32 func_15022B08(s32 arg0, s32 arg1);
void func_151162D4(struct131 *arg0);

void func_1511A738(struct131 *arg0) {
    if (D_800C35EA == 1) {
        if (func_15022B08(arg0 - D_800DBEF4, 0)) {
            *(s32 *)((u8 *)arg0 + 0x7C) = 0;
            *(f32 *)((u8 *)arg0 + 0x18) = 0.0f;
        }
    }
    func_151162D4(arg0);
    func_1511A494(arg0, (u8 *)arg0 + 0x80, (u8 *)arg0 + 0x84);
}

struct func_1511A7C0_s {
    u8 pad0[4];
    f32 *unk4;
    u8 pad8[8];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
};

void func_1511A7C0(u8 *arg0) {
    struct func_1511A7C0_s *s = *(struct func_1511A7C0_s **)(arg0 + 0x80);
    s32 i;

    s->unk1E = 1;
    s->unk10 = 0.0f;
    s->unk1C = 0;
    s->unk1D = 7;
    s->unk14 = 260.0f;
    s->unk18 = 100.0f;
    for (i = 0; i < *(u16 *)(arg0 + 0x16); i++) {
        s->unk4[i] = 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511A838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511AF30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511B07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511B51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511B7D4.s")

void func_15188010(s32 arg0, f32 *arg1);

void func_1511BA24(u8 *arg0) {
    f32 sp1C;

    sp1C = 0.0f;
    func_15188010(*(s32 *)(arg0 + 0x3C), &sp1C);
    arg0[0x8A] = sp1C * 255.0f;
    if (arg0[0x8A] == 0) {
        arg0[0x8A] = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511BB04.s")

void func_1511BB04(void *, f32, f32, f32, f32);

struct func_1511BDF4_s {
    u8 pad0[0x3F];
    u8 unk3F;
    u8 pad40[0x40];
    struct127 *unk80;
};

void func_1511BDF4(struct func_1511BDF4_s *arg0) {
    struct127 *obj;

    obj = (arg0->unk80 != NULL) ? arg0->unk80 : func_15083E90(arg0->unk3F);
    if (obj != NULL) {
        func_1511BB04(arg0, obj->x_position, obj->z_position, 1.0f, 1.0f);
    }
}

extern f32 D_800A31E0;

struct func_1511BE5C_s {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[8];
    s16 unk10;
    s16 pad12;
    s16 unk14;
};

void func_1511BE5C(struct func_1511BE5C_s *arg0) {
    arg0->unk4 = func_150484A0(arg0->unk10 - D_800DBFF0->unk2F8, arg0->unk14 - D_800DBFF0->unk300) * D_800A31E0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511BEBC.s")

void func_1511C540(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511C548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511C638.s")

extern f32 D_800A31F4;

void func_1511CB2C(s32 arg0, f32 *arg1) {
    *arg1 = D_800A31F4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511CB44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511D394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511D7BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511D9E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DBC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DD98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DF6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511E780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511EC50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511ED84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511EF40.s")

struct func_1511F31C_s {
    u8 pad0[0x10];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[0x3E - 0x16];
    u16 unk3E;
    u8 pad40[0x54 - 0x40];
    u16 unk54;
};

void *func_151149AC(u8 arg0);
void func_1511490C(void *mtx, void *arg1);
void func_150A7960(void *mtx, f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);

void func_1511F31C(struct func_1511F31C_s *arg0) {
    s32 pad[2];
    Mtx mtx;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    void *ptr;
    u16 temp = arg0->unk3E;

    if (arg0->unk54 == 0x8005 && D_800BE9F0 == 0x35) {
        ptr = func_151149AC(temp);
        if (ptr != NULL) {
            func_1511490C(&mtx, ptr);
            func_150A7960(&mtx, -3.0f, 223.0f, 549.0f, &sp44, &sp40, &sp3C);
            arg0->unk10 = sp44;
            arg0->unk12 = sp40;
            arg0->unk14 = sp3C;
        }
    }
}

struct func_1511F3E8_s {
    u8 pad0[0x3C];
    s32 unk3C;
    u8 pad40[0x6E - 0x40];
    u8 unk6E;
    u8 pad6F[0x7C - 0x6F];
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    u8 pad88[2];
    u8 unk8A;
};

void func_1511F3E8(struct func_1511F3E8_s *arg0) {
    s32 total;

    if (arg0->unk7C == 0) {
        total = arg0->unk3C;
        arg0->unk80 = ((total >> 16) & 0xFFFF) * 60;
        arg0->unk7C = 1;
    }
    total = (arg0->unk3C & 0xFFFF) * 60;
    if (arg0->unk80 != 0) {
        if (D_800BE9E4 < arg0->unk80) {
            arg0->unk80 -= D_800BE9E4;
        } else {
            arg0->unk80 = 0;
            arg0->unk84 = total;
        }
    } else if (D_800BE9E4 < arg0->unk84) {
        arg0->unk84 -= D_800BE9E4;
        arg0->unk8A = (arg0->unk84 * 255) / total;
    } else {
        arg0->unk6E = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F4D0.s")

struct func_1511F768_s {
    u8 pad0[0x80];
    s32 unk80;
};

void func_1511F768(struct func_1511F768_s *arg0, s32 arg1) {
    if (arg0->unk80 == 0) {
        arg0->unk80 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F92C.s")
