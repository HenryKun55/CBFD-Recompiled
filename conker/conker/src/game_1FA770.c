#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151CD2C0_s {
    u8 pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

struct func_151CD2C0_s2 {
    struct func_151CD2C0_s *unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
};

struct260 *func_151CD2C0(struct func_151CD2C0_s *arg0, u8 arg1, s32 arg2) {
    struct260 *temp_v0;
    struct func_151CD2C0_s2 sp34;

    sp34.unk0 = arg0;
    sp34.unk4 = arg0->unk18;
    sp34.unk8 = 0;
    sp34.unkC = arg0->unk1C;
    temp_v0 = func_15149130(0x12C, -1, -1, -1, 0, 0x1E, (struct37 *)0x10, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp34, 0x10);
    }
    return temp_v0;
}

void func_151CD35C(s32 arg0) {
    s32 sp1C;

    if ((arg0 >= 0) && (arg0 < 4)) {
        sp1C = arg0;
        func_151494E0((s32)&sp1C, 0x17);
    }
}

void func_151CD394(s32 arg0) {
    s32 sp1C;

    if (arg0 >= 0 && arg0 < 4) {
        sp1C = arg0;
        func_151494E0((s32)&sp1C, 0x18);
    }
}

struct func_151CD3CC_s {
    u8 pad0[0x14];
    u8 unk14;
};

typedef struct {
    struct func_151CD3CC_s *unk0;
    s32 unk4;
    struct func_151CE47C_s *unk8;
    u8 unkC;
} func_151CD3CC_sub;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x1B];
    func_151CD3CC_sub unk28;
} func_151CD3CC_obj;

struct func_151CE47C_s *func_151CD4C0(struct func_151CD3CC_s *, u8, s32, u8, u8);
struct func_151CE47C_s;
void func_151CE47C(struct func_151CE47C_s *);

void func_151CD3CC(func_151CD3CC_obj *arg0, s32 *arg1, u8 arg2) {
    func_151CD3CC_sub *sub = &arg0->unk28;
    s32 pad[2];

    if (arg2 == 0x17) {
        s32 id = sub->unk4;
        if (id == *arg1 && sub->unk8 == NULL) {
            sub->unk8 = func_151CD4C0(sub->unk0, sub->unkC, id, arg0->unkC, arg0->unk1);
            sub->unk0->unk14 = 0;
        }
    } else if (arg2 == 0x18) {
        if (sub->unk4 == *arg1 && sub->unk8 != NULL) {
            func_151CE47C(sub->unk8);
        }
    } else if (arg2 == 0x23) {
        if (sub->unk4 == *arg1) {
            sub->unk8 = NULL;
            sub->unk0->unk14 = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD7BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CDB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CDE20.s")

struct func_151CE47C_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
};

void func_151CE47C(struct func_151CE47C_s *arg0) {
    arg0->unk30 = 0;
    arg0->unk1E &= ~2;
    arg0->unk1E |= 8;
}

void func_151CE49C(s32 arg0) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = *(s32 *)(arg0 + 0x98);
    sp1C = *(s32 *)(temp_v0 + 0x48);
    func_151494E0((s32)&sp1C, 0x23);
    func_151478F4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE4DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE51C.s")

struct func_151CE634_obj {
    u8 pad0[0x48];
    s32 unk48;
};

struct func_151CE634_node {
    u8 pad0[8];
    struct func_151CE634_node *next;
    u8 padC[0x20 - 0xC];
    s32 unk20;
    u8 pad24[0x98 - 0x24];
    struct func_151CE634_obj *unk98;
};

struct func_151CE634_s {
    struct func_151CE634_node *list[0x1A0 / 4];
};

extern s32 D_800A5760[];
extern struct func_151CE634_s D_800DCE50[];

struct func_151CE634_node *func_151CE634(s32 arg0) {
    u8 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            struct func_151CE634_node *n = D_800DCE50[j].list[D_800A5760[i]];

            while (n != NULL) {
                if (n->unk20 == 11) {
                    struct func_151CE634_obj *o = n->unk98;

                    if (o->unk48 == arg0) {
                        return n;
                    }
                }
                n = n->next;
            }
        }
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CEA20.s")

extern f32 D_800AB008;
struct func_151CEC10_s;
struct func_151CEC10_b;
s32 func_151CEC10(struct func_151CEC10_s *out, f32 *a1, struct func_151CEC10_b *a2);
void *func_15147A80(void *, s32, s32, s32, s32, s32, s32, s32, s32, u8, s32);

struct func_151CEAAC_info {
    f32 x, y, z;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    u8 unk14;
    u8 unk15;
};

struct func_151CEAAC_s {
    u8 *unk0;
    u8 unk4;
    void *unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    u8 unk1C;
    f32 unk20;
    f32 unk24;
};

void *func_151CEAAC(u8 *arg0, void *arg1, u8 arg2, u8 arg3, s32 arg4) {
    s32 pad;
    struct func_151CEAAC_info info;
    struct func_151CEAAC_s data;
    void *ret;
    s32 t;

    info.unk15 = 0x19;
    info.unkC = 0x12C;
    info.unkE = 0x10;
    info.unk10 = 0x11;
    info.unk14 = 3;
    data.unk0 = arg0;
    if (arg0 != NULL) {
        data.unk4 = arg0[0x3B];
    } else {
        data.unk4 = 0;
    }
    data.unk8 = arg1;
    data.unkC = 0.0f;
    data.unk10 = 1.0f;
    data.unk14 = 0.0f;
    data.unk18 = 1.0f;
    if (arg2) {
        t = 2;
    } else {
        t = 0;
    }
    data.unk1C = t;
    data.unk20 = func_150ADA68() * 400.0f + 400.0f;
    data.unk24 = func_150ADA68() * 2.0f * D_800AB008;
    if (!func_151CEC10((struct func_151CEC10_s *)&info, (f32 *)arg0, arg1)) {
        info.x = 0.0f;
        info.y = 0.0f;
        info.z = 0.0f;
    }
    ret = func_15147A80(&info, 0x28, 0x28, 0, 0xF, 0xF, 0, 0, 0, arg3, arg4);
    if (ret != NULL) {
        memcpy(*(void **)((u8 *)ret + 0x98), &data, 0x28);
    }
    return ret;
}

struct func_151CEC10_s {
    f32 x, y, z;
};

struct func_151CEC10_b {
    u8 pad[0x40];
    struct func_151CEC10_s pos;
};

s32 func_151CEC10(struct func_151CEC10_s *out, f32 *a1, struct func_151CEC10_b *a2) {
    if (a2 != NULL) {
        *out = a2->pos;
    } else {
        out->x = a1[5];
        out->y = a1[6];
        out->z = a1[7];
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CEC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CF120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CF380.s")

void func_151CF844(u8 *arg0, void *arg1, u8 arg2) {
    s32 *temp = *(s32 **)(arg0 + 0x98);

    if (*temp != 0) {
        func_15169850(arg1, arg2, temp, temp + 1, arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CF898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CFA4C.s")

void func_151D0024(struct127 *arg0) {
    struct {
        struct127 *ptr;
        u8 id;
    } tmp;

    tmp.ptr = arg0;
    tmp.id = arg0->unique_id;
    func_151494E0(&tmp, 0x18);
}

struct func_151D0058_s {
    u8 *ptr;
    u8 unk4;
    u16 unk6;
    f32 unk8;
    u8 unkC;
    u8 unkD;
};

void func_151D0058(u8 *arg0, u8 arg1, u8 arg2, s32 arg3) {
    u8 *ret;
    struct func_151D0058_s tmp;

    tmp.ptr = arg0;
    tmp.unk4 = arg0[0x3B];
    tmp.unk8 = (*(f32 *)(arg0 + 0x150) + *(f32 *)(arg0 + 0x14C)) * 0.5f;
    tmp.unkD = arg1;
    tmp.unkC = ((u32)func_150ADA20() % 56) + 200;
    tmp.unk6 = *(u16 *)(arg0 + 0x84);
    if ((ret = (u8 *)func_15149130(0x12C, -1, 0x61, 4, 0, 0x31, (void *)0x10, arg2, arg3)) != NULL) {
        memcpy(ret + 0x28, &tmp, 0x10);
    }
}

struct func_151D0128_t { u8 pad[0x84]; u16 unk84; };
struct func_151D0128_s {
    u8 pad0[0xE];
    s16 unkE;
    u8 pad10[0x18];
    struct func_151D0128_t *unk28;
    u8 pad2C[2];
    u16 unk2E;
};

void func_151D0128(struct func_151D0128_s *arg0) {
    struct func_151D0128_t *temp = arg0->unk28;

    if (arg0->unk2E != temp->unk84) {
        arg0->unkE = -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D014C.s")

struct func_151D08F0_s {
    s32 unk0;
    u8 unk4;
};

struct func_151D08F0_m {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_151D08F0(struct102 *arg0, void *arg1, u8 arg2) {
    struct func_151D08F0_s *a = arg1;
    struct func_151D08F0_m *m = arg1;
    struct func_151D08F0_s *p = (struct func_151D08F0_s *)((u8 *)arg0 + 0x28);
    s32 v;

    if (arg2 == 0 || arg2 == 0x18) {
        v = a->unk0;
        if (v == p->unk0 || a->unk4 == p->unk4) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (p->unk0 == m->unk0) {
            p->unk0 = m->unk4;
            p->unk4 = m->unk9;
        } else if (p->unk0 == m->unk4) {
            p->unk0 = m->unk0;
            p->unk4 = m->unk8;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D09A8.s")

void func_151D0ED8(s32 arg0) {
    s32 temp = arg0;
    if (*(s32 *)(temp + 0xA8) != 0) {
        func_1516972C(*(struct102 **)(temp + 0xA8));
    }
}

void func_151D0F08(s32 arg0) {
    func_151D0ED8(arg0);
    func_1513173C(arg0);
}

void func_151D0F34(s32 arg0) {
    func_151D0ED8(arg0);
    func_1513175C(arg0);
}

typedef struct {
    f32 x, y, z;
} func_151D0F60_v;

struct func_151D0F60_s {
    u8 *unk0;
    u8 unk4;
    s32 unk8;
    func_151D0F60_v unkC;
    func_151D0F60_v unk18;
    func_151D0F60_v unk24;
    f32 unk30;
    u8 unk34;
};

extern s32 (*D_8008FC30[])(u8 *, func_151D0F60_v *);

void func_151D0F60(u8 *arg0, u8 arg1, u8 arg2, s32 arg3) {
    struct260 *temp_v0;
    struct func_151D0F60_s sp34;

    sp34.unk0 = arg0;
    sp34.unk4 = arg0[0x3B];
    sp34.unk8 = 0;
    if (D_8008FC30[arg1](arg0, &sp34.unk18) == 0) {
        sp34.unk18 = *(func_151D0F60_v *)&D_800A5480;
    }
    sp34.unkC = sp34.unk18;
    sp34.unk24 = *(func_151D0F60_v *)&D_800A5480;
    sp34.unk30 = 0.0f;
    sp34.unk34 = arg1;
    temp_v0 = func_15149130(0x12C, -1, 0x5F, -1, 0, 0x48, (struct37 *)0x38, arg2, arg3);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp34, 0x38);
    }
}

s32 func_151D1074(u8 *arg0, f32 *arg1) {
    arg1[0] = *(f32 *)(arg0 + 0x14);
    arg1[1] = *(f32 *)(arg0 + 0x180) + 8.0f;
    arg1[2] = *(f32 *)(arg0 + 0x1C);
    return 1;
}

void func_151D10A4(s32 arg0, s32 arg1) {
    func_151D10E4(arg0, arg1, 0);
}

void func_151D10C4(void *arg0, s32 arg1) {
    func_151D10E4(arg0, arg1, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D10E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1138.s")

void func_151D1328(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

void func_151D1368(void) {
    func_151D13E0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D13B4.s")

struct func_151D13E0_s {
    u8 pad0[0x1C];
    u16 unk1C;
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
    u8 pad31[0x98 - 0x31];
    s32 *unk98;
};

struct func_151D13E0_t {
    s32 unk0;
    s32 unk4;
    struct func_151D13E0_s *unk8;
};
int func_151D13E0(s32 arg0) {
    struct func_151D13E0_t *s;
    s32 *p;

    s = (struct func_151D13E0_t *)(arg0 + 0x28);
    if (s->unk8 != NULL) {
        p = s->unk8->unk98;
        s->unk8->unk30 = 0;
        s->unk8->unk1E &= ~2;
        s->unk8->unk1E |= 8;
        s->unk8->unk1E |= 1;
        s->unk8->unk1C = 0x28;
        *p = 0;
        s->unk8 = NULL;
    }
    if (*(s32 *)(arg0 + 0x30) != 0) {
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D15D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D197C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1C98.s")

void func_151D223C(s32 *arg0) {
    s32 **temp_v0 = (s32 **)arg0[0x98 / 4];
    s32 *temp_v1 = *temp_v0;
    if (temp_v1 != NULL) {
        temp_v1[0x30 / 4] = 0;
    }
}

void func_151D2258(s32 arg0) {
    func_151D223C(arg0);
    func_151478F4(arg0);
}

void func_151D223C();
void *func_15147928();

void func_151D2284(void *arg0) {
    func_151D223C(arg0);
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D22B0.s")
