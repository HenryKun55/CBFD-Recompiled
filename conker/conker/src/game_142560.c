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

struct func_151155C0_s {
    u8 pad0[0x12];
    s16 unk12;
    u8 pad14[0x3C - 0x14];
    s32 unk3C;
    u8 pad40[0x4F - 0x40];
    u8 unk4F;
    u8 pad50[0x5C - 0x50];
    s16 unk5C;
    u8 pad5E[0x7C - 0x5E];
    s32 unk7C;
    s32 unk80;
};

void func_151155C0(struct func_151155C0_s *arg0) {
    s32 speed = (u8)(arg0->unk3C >> 16);
    s32 count = (u8)(arg0->unk3C >> 24) + 1;
    s32 target = (s16)arg0->unk3C;
    s32 flag = 0;
    s32 reached = 0;
    s32 orig = arg0->unk12;
    s32 cur;
    s32 step;

    if ((arg0->unk4F & 4) == 4) {
        flag = 1;
    }
    if (arg0->unk7C == 0) {
        arg0->unk7C = arg0->unk12;
    }
    step = (target - arg0->unk7C) / speed;
    if (arg0->unk80 == 0) {
        if (arg0->unk12 == arg0->unk7C) {
            if (flag) {
                arg0->unk80 = count;
            }
        } else {
            cur = (s16)(arg0->unk12 - step);
            if (arg0->unk7C < target) {
                if (arg0->unk7C < cur) {
                    reached = 1;
                }
            } else if (cur < arg0->unk7C) {
                reached = 1;
            }
            if (reached) {
                arg0->unk12 = cur;
            } else {
                arg0->unk12 = arg0->unk7C;
                arg0->unk80 = -count;
            }
        }
    }
    if (arg0->unk80 > 0) {
        cur = (s16)(arg0->unk12 + step);
        if (arg0->unk7C < target) {
            if (cur < target) {
                reached = 1;
            }
        } else if (target < cur) {
            reached = 1;
        }
        if (reached) {
            arg0->unk12 = cur;
            arg0->unk80 = count;
        } else {
            arg0->unk12 = target;
            arg0->unk80 = arg0->unk80 - 1;
        }
    }
    if (arg0->unk80 < 0) {
        arg0->unk80 = arg0->unk80 + 1;
    }
    arg0->unk5C = arg0->unk12 - orig;
}

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

extern u16 D_800CC354;
extern f32 D_800A2FA8;
extern f32 D_800A2FAC;
f32 func_1510F648(f32, f32, f32);

struct func_1511617C_s {
    u8 pad0[0x10];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[0x3C - 0x16];
    s32 unk3C;
    u8 pad40[0x4F - 0x40];
    u8 unk4F;
    u8 pad50[0x5C - 0x50];
    s16 unk5C;
    u8 pad5E[0x7C - 0x5E];
    f32 unk7C;
};

void func_1511617C(struct func_1511617C_s *arg0) {
    f32 d;
    s32 target;
    s16 old;

    old = arg0->unk12;
    arg0->unk7C = func_1510F648(arg0->unk10, arg0->unk12, arg0->unk14);
    if (fabsf(arg0->unk7C - arg0->unk12) > 200.0f) {
        arg0->unk3C = 0;
    }
    if (!(arg0->unk4F & 4)) {
        d = -arg0->unk3C;
        arg0->unk3C = arg0->unk3C + d * D_800A2FA8;
    } else {
        target = -20;
        if (D_800CC354 == 0x4B) {
            target = -40;
        }
        d = target - arg0->unk3C;
        arg0->unk3C = arg0->unk3C + d * D_800A2FAC;
    }
    arg0->unk12 = arg0->unk7C + arg0->unk3C;
    arg0->unk5C = arg0->unk12 - old;
}

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

struct func_15116BAC_e {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};

struct func_15116BAC_s {
    u8 pad0[0x10];
    s16 unk10[3];
    u8 pad16[0x3C - 0x16];
    s32 unk3C;
    u8 pad40[0x5A - 0x40];
    s16 unk5A[3];
    u8 pad60[0x74 - 0x60];
    u16 unk74;
    u8 pad76[0x7C - 0x76];
    s32 unk7C[3];
};

extern struct func_15116BAC_e D_80089260[];
void func_15114D24(struct func_15116BAC_s *, s32, s32, s32, s32, s32);

void func_15116BAC(struct func_15116BAC_s *arg0) {
    s32 speed;
    s32 called;
    s32 idx;
    s32 step;
    s32 i;
    s32 diff;
    s32 snd;
    s16 *cur;
    s32 *tgt;
    s32 maxDiff;
    s16 *prev;

    idx = arg0->unk3C >> 10;
    called = 0;
    maxDiff = 0;
    speed = arg0->unk3C & 0xFFFF03FF;
    if (idx != 0 && arg0->unk74 == 0) {
        snd = D_80089260[idx].unk0;
        if (snd != 0) {
            func_15114D24(arg0, snd, 0x5DC0, 0x7D0, 0xFA0, 0);
            called = 1;
        }
    }
    step = (speed * D_800BE9E4) >> 1;
    cur = arg0->unk10;
    tgt = arg0->unk7C;
    prev = arg0->unk5A;
    for (i = 0; i < 3; i++) {
        prev[i] = cur[i];
        if (cur[i] != tgt[i]) {
            if (tgt[i] < cur[i]) {
                cur[i] -= step;
                diff = cur[i] - tgt[i];
                if (diff < 0) {
                    cur[i] = tgt[i];
                }
            } else {
                cur[i] += step;
                diff = tgt[i] - cur[i];
                if (diff < 0) {
                    cur[i] = tgt[i];
                }
            }
            if (maxDiff < diff) {
                maxDiff = diff;
            }
        }
        prev[i] = cur[i] - prev[i];
    }
    if (idx != 0) {
        snd = D_80089260[idx].unk8;
        if (snd != 0) {
            maxDiff -= (D_80089260[idx].unkA * speed) >> 1;
            if (maxDiff <= 0 && (-step < maxDiff || called)) {
                func_15114D24(arg0, snd, 0x5DC0, 0x7D0, 0xFA0, 0);
            }
        }
    }
}

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

struct func_151194D4_pt {
    s16 x;
    s16 y;
    s16 z;
    u16 flag;
    u8 pad[8];
};

struct func_151194D4_cmd {
    s8 type;
    u8 pad[3];
    u32 data;
};

struct func_151194D4_s {
    u8 pad0[0x1C];
    struct func_151194D4_cmd *cmds;
    u8 pad20[0x28 - 0x20];
    struct func_151194D4_pt *pts;
};

void func_151194D4(struct func_151194D4_s *arg0, struct func_151194D4_pt *arg1, s32 arg2, s32 arg3) {
    struct func_151194D4_cmd *cmd;
    s32 found;
    u32 base;
    u32 i;
    u32 data;
    u32 bits;
    struct func_151194D4_pt *pt;
    cmd = arg0->cmds;
    while (cmd->type != -0x21) {
        switch (cmd->type) {
        case 1:
            base = (cmd->data & 0xFFFFFF) >> 4;
            break;
        case 5:
            data = cmd->data;
            found = 0;
            bits = data;
            for (i = 0; i < 3; i++) {
                pt = &arg0->pts[(bits & 0xFF) / 10 + base];
                if (arg1->x == pt->x && arg1->y == pt->y && arg1->z == pt->z) {
                    found = 1;
                    pt->flag = arg3;
                } else {
                    bits >>= 8;
                }
            }
            if (found) {
                for (bits = data, i = 0; i != 3; i++) {
                    pt = &arg0->pts[(bits & 0xFF) / 10 + base];
                    if (pt->flag == 0) {
                        if (arg2 < pt->z * pt->z + pt->x * pt->x) {
                            pt->flag = arg3;
                            func_151194D4(arg0, pt, arg2, arg3);
                        }
                    }
                    bits >>= 8;
                }
            }
            break;
        }
        cmd++;
    }
}

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

extern f32 D_800A3188;
extern f32 D_800A318C;
extern f32 D_800A3190;
extern f32 D_800A3194;

struct func_1511AF30_s {
    f32 unk0;
    u8 pad4[0x3C - 0x4];
    s32 unk3C;
    u8 pad40[0x7C - 0x40];
    f32 unk7C;
    f32 unk80;
    f32 unk84;
};

void func_1511AF30(struct func_1511AF30_s *arg0) {
    f32 f;
    f32 target;
    f32 diff;
    s32 r;

    f = arg0->unk3C;
    target = 75.0f * f * D_800A3188;
    if (target != arg0->unk7C) {
        diff = target - arg0->unk7C;
        if (fabsf(diff) < 1.0f) {
            arg0->unk7C = target;
        } else {
            arg0->unk7C += (diff < 0.0f) ? -1 : 1;
        }
        arg0->unk80 = 0.0f;
    } else {
        r = func_150ADA20() % 1000U;
        if (r < 500) {
            arg0->unk84 = r * 5.0f * f * D_800A318C * D_800A3190;
        }
        diff = arg0->unk84 - arg0->unk80;
        arg0->unk80 += diff * D_800A3194;
    }
    arg0->unk0 = arg0->unk7C + arg0->unk80;
}

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

extern f32 D_800A3210;
extern f32 D_800A3214;

struct func_1511DBC4_d {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_1511DBC4_s {
    u8 pad0[8];
    f32 unk8;
    u8 padC[0x73 - 0xC];
    u8 unk73;
    u8 pad74[8];
    struct func_1511DBC4_d *unk7C;
};

void func_1511DBC4(struct func_1511DBC4_s *arg0) {
    s32 state;
    struct func_1511DBC4_d *d;
    struct func_1511DBC4_d *t;

    t = arg0->unk7C;
    if (t == NULL) {
        t = arg0->unk7C = allocate_memory(0x10, 1, 0, 0);
        t->unk0 = 0.0f;
        t->unk4 = 0.0f;
        t->unk8 = 0.0f;
        d = t;
        t->unkC = D_800A3210;
    } else {
        d = t;
    }
    state = arg0->unk73 & 3;
    if (state == 0) {
        arg0->unk8 = 0.0f;
    } else if (state == 3) {
        arg0->unk8 = 90.0f;
        arg0->unk8 += cosf(d->unk0 * D_800A3214) * 0.5f;
        d->unk0 += 3.0f * D_800BE9E4;
    } else if (state == 2) {
        if (arg0->unk8 == 0.0f) {
            d->unk4 = 0.0f;
            d->unk8 = 0.0f;
        }
        d->unk8 += d->unkC;
        d->unk4 += d->unk8;
        arg0->unk8 += d->unk4;
        if (arg0->unk8 >= 90.0f) {
            state = 3;
            arg0->unk8 = 90.0f;
        }
    } else {
        if (D_800BE9E4 < arg0->unk8) {
            arg0->unk8 -= D_800BE9E4;
        } else {
            arg0->unk8 = 0.0f;
            state = 0;
        }
    }
    arg0->unk73 &= ~3;
    arg0->unk73 |= state;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DD98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DF6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511E780.s")

struct func_1511EC50_s {
    u8 pad0[0x12];
    s16 unk12;
    u8 pad14[0x3C - 0x14];
    s32 unk3C;
    u8 pad40[0x6E - 0x40];
    u8 unk6E;
    u8 pad6F[0x7C - 0x6F];
    s32 unk7C;
    s32 unk80;
    f32 unk84;
};

void func_1511EC50(struct func_1511EC50_s *arg0) {
    f32 step;

    if (arg0->unk7C == 0) {
        arg0->unk84 = arg0->unk12;
    }
    step = D_800BE9E4 * 4.0f;
    if (arg0->unk3C != 0) {
        step *= 0.25f;
    }
    if (arg0->unk80 != 0) {
        arg0->unk12 = arg0->unk12 + step * 5.0f;
        if (arg0->unk84 + 500.0f < arg0->unk12) {
            arg0->unk12 = arg0->unk84 + 500.0f;
            arg0->unk6E = 1;
        }
    } else {
        arg0->unk12 = arg0->unk12 - step;
        if (arg0->unk12 < arg0->unk84) {
            arg0->unk12 = arg0->unk84;
        }
    }
    arg0->unk7C = 1;
}

struct func_1511ED84_s {
    u8 pad0[0x14];
    s16 unk14;
    u8 pad16[0x72 - 0x16];
    u8 unk72;
    u8 pad73[0x7C - 0x73];
    s32 unk7C;
    s32 unk80;
    f32 unk84;
};

void func_1511ED84(struct func_1511ED84_s *arg0) {
    s32 one = 1;
    s32 dir;
    f32 step;
    f32 lim;

    if (arg0->unk7C == 0) {
        arg0->unk84 = arg0->unk14;
    }
    step = D_800BE9E4 * 4.0f;
    dir = one - (arg0->unk72 & 1);
    if (arg0->unk80 != 0) {
        if (dir & 1) {
            arg0->unk14 = arg0->unk14 + step;
            if (arg0->unk84 < arg0->unk14) {
                arg0->unk14 = arg0->unk84;
            }
        } else {
            arg0->unk14 = arg0->unk14 - step;
            if (arg0->unk14 < arg0->unk84) {
                arg0->unk14 = arg0->unk84;
            }
        }
    } else {
        if (dir & 1) {
            arg0->unk14 = arg0->unk14 - step;
            lim = arg0->unk84 - 350.0f;
            if (arg0->unk14 < lim) {
                arg0->unk14 = lim;
            }
        } else {
            arg0->unk14 = arg0->unk14 + step;
            lim = arg0->unk84 + 350.0f;
            if (lim < arg0->unk14) {
                arg0->unk14 = lim;
            }
        }
    }
    arg0->unk7C = one;
}

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

struct func_1511F788_s {
    u8 pad0[0x12];
    s16 unk12;
    u8 pad14[0x18 - 0x14];
    f32 unk18;
    u8 pad1C[0x3C - 0x1C];
    s32 unk3C;
    u8 pad40[0x5C - 0x40];
    s16 unk5C;
    u8 pad5E[0x6E - 0x5E];
    u8 unk6E;
    u8 pad6F[0x7C - 0x6F];
    s32 unk7C;
    s32 unk80;
    s32 unk84;
};

void func_1511F788(struct func_1511F788_s *arg0) {
    s32 pad1;
    s32 pad2;
    s32 limit;
    s32 fps = 60;
    s16 prev;

    prev = arg0->unk12 + arg0->unk18;
    limit = arg0->unk3C; limit = (limit * fps) / fps;
    if (D_800BE9B4) {
        arg0->unk7C = func_150ADA20() & 0xFFFF;
    }
    arg0->unk18 = cosf(arg0->unk7C * 0.0054931640625f) * 25.0f;
    arg0->unk7C += D_800BE9E4 * 10;
    if (arg0->unk80 == 1) {
        arg0->unk84 += D_800BE9E4;
        if (limit < arg0->unk84) {
            arg0->unk80 = 2;
        }
    } else if (arg0->unk80 == 2) {
        arg0->unk12 -= D_800BE9E4;
        if (arg0->unk12 < -10000) {
            arg0->unk6E = 1;
        }
    }
    arg0->unk5C = (arg0->unk12 + arg0->unk18) - prev;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F92C.s")
