#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void *func_1502B5C8();
extern void func_15085BE8(void);
extern s16 D_80087290;
extern s16 D_80087294;
extern struct func_15086C70_s *D_800D2350;

void func_15085B70(s32 arg0) {
    s16 *ptr = func_1502B5C8(0, 2, 0x19, arg0);

    if (ptr == NULL) {
        D_80087290 = 0;
        D_80087294 = 0;
        D_800D2350 = NULL;
    } else {
        D_80087290 = ptr[0];
        D_80087294 = ptr[1];
        D_800D2350 = (struct func_15086C70_s *)(ptr + 2);
    }
    func_15085BE8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15085BE8.s")

extern f32 D_800D2360[];
extern u8 D_800D237C[];

u8 func_15085DA8(f32 arg0) {
    s32 i = 0;

    while (D_800D2360[i] <= arg0) {
        i++;
    }
    return D_800D237C[i];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15085DF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086BD0.s")

typedef struct func_15086C70_s {
    s16 x;
    s16 y;
    s16 z;
    s16 pad[5];
} func_15086C70_s;
extern func_15086C70_s *D_800D2350;
extern void func_150A3194(s32, s32, s32, s32, s32);

void func_15086C70(s32 arg0) {
    s32 z = D_800D2350[arg0].z;
    func_150A3194(3, 0xB, D_800D2350[arg0].x, D_800D2350[arg0].y, z);
}

extern s16 D_80087290;

s32 func_15086CBC(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    if (arg0 < 0 || arg0 >= D_80087290) {
        return 0;
    }
    *arg1 = D_800D2350[arg0].x;
    *arg2 = D_800D2350[arg0].y;
    *arg3 = D_800D2350[arg0].z;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150870D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087350.s")

extern void *D_800872A0;
extern s8 D_800D2398;
struct func_15087CC0_s {
    u8 pad0[0x30];
    s8 unk30;
    s8 unk31;
    u8 pad32[0x16];
    u8 unk48;
    s8 unk49;
    u8 pad4A[0x84 - 0x4A];
};
void func_150891E8(struct func_15087CC0_s *, struct127 *);
void func_150896EC(struct func_15087CC0_s *, struct127 *, s32);

void func_15087CC0(void) {
    s32 i;
    struct func_15087CC0_s *e;
    struct127 *obj;

    D_800D23A9 = 0;
    if (D_800872A0 != NULL) {
        for (i = 0; i < D_800D2398; i++) {
            e = (struct func_15087CC0_s *)(i * 0x84 + (char *)D_800872A0);
            obj = &gObjects[e->unk31];
            if (*(s32 *)((u8 *)obj + 0x318) != 0) {
                if (e->unk30 >= 2) {
                    func_150891E8(e, obj);
                } else if (e->unk48 == 0) {
                    func_150896EC(e, obj, 0);
                } else if (e->unk49 != 0) {
                    func_150896EC(e, obj, 1);
                }
            }
        }
    }
}

extern void *D_800872A0;
u8 func_150888A8(s32 arg0, s32 arg1, s32 arg2);

struct func_15087DCC_s {
    u8 pad0[0x2B];
    u8 unk2B;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    s8 unk2F;
    u8 pad30[0x84 - 0x30];
};

void func_15087DCC(s32 arg0, s32 arg1) {
    struct func_15087DCC_s *temp;

    if (D_800872A0 != NULL) {
        temp = (struct func_15087DCC_s *)(arg0 * 0x84 + (char *)D_800872A0);
        if (arg1 != temp->unk2F) {
            if (arg1 != 0) {
                temp->unk2D = func_150888A8(temp->unk2B, temp->unk2C, 1);
                temp->unk2E = func_150888A8(temp->unk2C, temp->unk2D, 1);
            }
            temp->unk2F = arg1;
        }
    }
}

struct func_15087E54_s {
    u8 pad0[0xC];
    f32 unkC;
    f32 unk10;
    u8 pad14[0x84 - 0x14];
};

struct func_15087E54_t {
    u8 pad0[0x76];
    u16 unk76;
};

void func_15087E54(s32 arg0, struct func_15087E54_t *arg1) {
    struct func_15087E54_s *temp;
    u16 angle;
    u16 diff;

    if (D_800872A0 != NULL) {
        temp = (struct func_15087E54_s *)(arg0 * 0x84 + (char *)D_800872A0);
        angle = func_1505A630(temp->unk10, temp->unkC, 0) + 0x4000;
        diff = angle - arg1->unk76;
        if (diff & 0x8000) {
            if (diff < 0xDBFF) {
                arg1->unk76 = angle + 0x2400;
            }
        } else if (diff > 0x2400) {
            arg1->unk76 = angle - 0x2400;
        }
    }
}

extern s8 D_800D23A8;

struct func_15087EF0_s {
    f32 unk0;
    u8 pad4[0x8];
    f32 unkC;
    f32 unk10;
    u8 pad14[0x84 - 0x14];
};

void func_15087EF0(s32 arg0, u8 *arg1) {
    struct func_15087EF0_s *temp;
    u16 ret;
    u16 val;

    if (D_800872A0 != NULL) {
        temp = (struct func_15087EF0_s *)(arg0 * 0x84 + (char *)D_800872A0);
        ret = func_1505A630(temp->unk10, temp->unkC, 0);
        if (D_800D23A8 == 0) {
            if (temp->unk0 < 0.5f) {
                val = ret + 0x4A00;
            } else {
                val = ret + 0x3600;
            }
        } else {
            if (temp->unk0 >= 0.5f) {
                val = ret + 0x4A00;
            } else {
                val = ret + 0x3600;
            }
        }
        *(u16 *)(arg1 + 0x76) = val;
    }
}

extern void *D_800872A0;

void func_15087FC4(s32 arg0, s32 arg1) {
    u8 *temp_v1;

    if (D_800872A0 != NULL) {
        temp_v1 = (arg0 * 0x84) + (u8 *)D_800872A0;
        temp_v1[0x31] = arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087FEC.s")

struct func_1508802C_s {
    u8 pad0[0x30];
    u8 unk30;
    s8 unk31;
};

s32 func_1508802C(struct func_1508802C_s *arg0, struct127 *arg1, s32 arg2) {
    if (arg1->unk31C->unk120 != 0) {
        return 1;
    }
    if (D_800D18A0 & (1 << (arg1 - gObjects))) {
        return 1;
    }
    arg1->unk31C->unk84 = 1;
    arg1->interaction_state = 0xC;
    arg1->unk232 = arg2;
    gCurrentObject = arg1;
    gCurrentObjectIndex = arg0->unk31;
    arg1->unk218 = func_1507BB28(0, arg2);
    arg1->unk21C = 0;
    arg1->immune = 0xFF;
    arg0->unk30 = 2;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150880F8.s")

extern void *D_800872A0;

s32 func_150881CC(s32 arg0) {
    f32 *ptr;

    if (D_800872A0 == NULL) {
        return 0;
    }
    ptr = (f32 *)(arg0 * 0x84 + (char *)D_800872A0);
    return *ptr * 256.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088270.s")

extern void *D_800872A0;

struct func_150882B0_s {
    u8 pad0[0x27];
    s8 unk27;
    u8 pad28[0x84 - 0x28];
};

s32 func_150882B0(s32 arg0) {
    struct func_150882B0_s *temp;

    if (D_800872A0 == NULL) {
        return 0;
    }
    temp = (struct func_150882B0_s *)(arg0 * 0x84 + (char *)D_800872A0);
    return temp->unk27;
}

extern void *D_800872A0;
extern s8 D_800D2398;

struct func_150882E4_s {
    u8 pad0[0x8];
    f32 unk8;
    u8 padC[0x24 - 0xC];
    s16 unk24;
    u8 pad26[0x29 - 0x26];
    s8 unk29;
    u8 pad2A[0x84 - 0x2A];
};

s32 func_150882E4(s32 arg0, s32 arg1) {
    struct func_150882E4_s *base;
    struct func_150882E4_s *self;
    struct func_150882E4_s *other;
    s32 target;
    s32 i;
    s32 d;

    base = D_800872A0;
    if (base == NULL) {
        return 0x10;
    }
    self = &base[arg0];
    target = self->unk29 + arg1;
    for (i = 0; i < D_800D2398; i++) {
        other = &base[i];
        if (target == other->unk29 && i != arg0) {
            d = (self->unk24 * 16) + (s32)(self->unk8 * 16.0f);
            d = d - (other->unk24 * 16) - (s32)(other->unk8 * 16.0f);
            if (d < 0) {
                d = -d;
            }
            return (d << 8) | i;
        }
    }
    return 0x10;
}

extern f32 D_8009DA00;

struct func_150883B0_s {
    f32 unk0;
    u8 pad4[0xC - 0x4];
    f32 unkC;
    f32 unk10;
    u8 pad14[0x2F - 0x14];
    s8 unk2F;
    s8 unk30;
    s8 unk31;
    u8 pad32[0x84 - 0x32];
};

struct127 *func_150883B0(s32 arg0, s32 arg1, f32 *arg2, s32 *arg3) {
    struct func_150883B0_s *self;
    struct127 *result;
    f32 sign;
    f32 dx;
    f32 dz;
    f32 best;
    f32 d;
    s32 kind;
    s8 skip;
    f32 base;
    f32 x;
    f32 z;
    s32 i;

    if (D_800872A0 == NULL) {
        return NULL;
    }
    self = (struct func_150883B0_s *)(arg0 * 0x84 + (char *)D_800872A0);
    if (arg1 >= 0) {
        sign = -1.0f;
    } else {
        sign = 1.0f;
    }
    x = gObjects[self->unk31].x_position;
    z = gObjects[self->unk31].z_position;
    dx = self->unkC * sign;
    dz = self->unk10 * sign;
    kind = self->unk2F;
    skip = gObjects[self->unk31].unk124 - 1;
    result = NULL;
    base = -(dx * x + dz * z);
    best = D_8009DA00;
    for (i = 0; i < D_800D2398; i++) {
        self = (struct func_150883B0_s *)(i * 0x84 + (char *)D_800872A0);
        if (skip != self->unk31 && (kind == 0 || kind == self->unk2F)) {
            x = gObjects[self->unk31].x_position;
            z = gObjects[self->unk31].z_position;
            d = dx * x + dz * z + base;
            if (d > 0.0f && d < best) {
                best = d;
                *arg2 = self->unk0;
                *arg3 = self->unk2F;
                result = &gObjects[self->unk31];
            }
        }
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508855C.s")

extern void *D_800872A0;

struct func_150885EC_s {
    u8 pad0[0x30];
    s8 unk30;
    s8 unk31;
    u8 pad32[0x84 - 0x32];
};

void func_150885EC(s32 arg0, s32 arg1) {
    s32 b;
    s32 a;

    if (D_800872A0 != NULL) {
        b = ((struct func_150885EC_s *)D_800872A0)[arg1].unk31;
        a = ((struct func_150885EC_s *)D_800872A0)[arg1].unk30;
        bcopy(arg0 * 0x84 + (char *)D_800872A0, arg1 * 0x84 + (char *)D_800872A0, 0x84);
        ((struct func_150885EC_s *)D_800872A0)[arg1].unk31 = b;
        ((struct func_150885EC_s *)D_800872A0)[arg1].unk30 = a;
    }
}

extern void *D_800872A0;
extern s32 D_800D2394;
extern s8 D_800D2398;
extern s8 D_800D2399;
struct func_15088824_s;
void func_15088824(struct func_15088824_s *arg0);

struct func_1508868C_s {
    u8 pad0[0x30];
    u8 unk30;
    u8 unk31;
    u8 pad32[0x84 - 0x32];
};

s32 func_1508868C(struct127 *arg0) {
    s32 i;
    s32 mask;

    if (D_800872A0 == NULL) {
        return -1;
    }
    for (mask = 1, i = 0; i < D_800D2399; i++, mask <<= 1) {
        if (!(D_800D2394 & mask)) {
            D_800D2394 |= mask;
            i += D_800D2398;
            func_15088824((struct func_15088824_s *)(i * 0x84 + (char *)D_800872A0));
            ((struct func_1508868C_s *)D_800872A0)[i].unk30 = 1;
            ((struct func_1508868C_s *)D_800872A0)[i].unk31 = arg0 - gObjects;
            return i;
        }
    }
    return -1;
}

extern s32 D_800D2394;
extern s8 D_800D2398;
s32 func_1508855C(void);

struct func_15088780_s {
    u8 pad0[0x31];
    u8 unk31;
    u8 pad32[0x84 - 0x32];
};

void func_15088780(void) {
    s32 idx;

    if (D_800872A0 != NULL) {
        idx = func_1508855C();
        ((struct func_15088780_s *)D_800872A0)[idx].unk31 = 0;
        D_800D2394 &= ~(1 << (idx - D_800D2398));
    }
}

extern void *D_800872A0;

s32 func_150887F8(void) {
    if (D_800872A0 == NULL) {
        return 0;
    }
    return *((u8 *)D_800872A0 + 0x46) == 0xFF;
}

struct func_15088824_s {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ u8 unk26;
    /* 0x27 */ u8 unk27;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 unk2A;
    /* 0x2B */ u8 unk2B;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 unk30;
    /* 0x31 */ u8 unk31;
    /* 0x32 */ u8 unk32;
    /* 0x33 */ u8 unk33;
    /* 0x34 */ u8 pad34[0x15];
    /* 0x49 */ u8 unk49;
};

void func_15088824(struct func_15088824_s *arg0) {
    arg0->unk2B = 0;
    arg0->unk2C = 0;
    arg0->unk2D = 0;
    arg0->unk2E = 0;
    arg0->unk28 = 0;
    arg0->unk1C = 0;
    arg0->unk18 = 0;
    arg0->unk20 = -1;
    arg0->unk2F = 0;
    arg0->unk8 = 0.0f;
    arg0->unk0 = 0.5f;
    arg0->unk4 = 0.5f;
    arg0->unk24 = 0;
    arg0->unk26 = 0;
    arg0->unk27 = 0;
    arg0->unk31 = 0;
    arg0->unkC = 0.0f;
    arg0->unk14 = 0.0f;
    arg0->unk33 = 2;
    arg0->unk30 = 0;
    arg0->unk2A = 0x7F;
    arg0->unk49 = 0;
    arg0->unk10 = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150888A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088D58.s")

struct func_15088F30_s {
    s16 x;
    s16 y;
    s16 z;
    u8 pad6[3];
    u8 links[5];
    u8 unkE;
    u8 padF;
};

struct func_15088F30_arg {
    f32 unk0;
    u8 pad4[0x27];
    u8 unk2B[4];
};

#define NODES ((struct func_15088F30_s *)D_800D2350)

void func_15088F30(struct func_15088F30_arg *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 idx;
    s32 i;
    s32 j;
    struct func_15088F30_s *a;
    struct func_15088F30_s *b;
    f32 dx;
    f32 dz;

    for (i = 0; i < 4; i++) {
        if (arg0->unk2B[i] != 0xFF) {
            a = arg0->unk2B[i] + NODES;
            b = a;
            for (j = 0; j < 5; j++) {
                idx = a->links[j];
                if (idx != 0xFF && NODES[idx].unkE == 4) {
                    b = idx + NODES;
                    j = 5;
                }
            }
            dx = b->x - a->x;
            dz = b->z - a->z;
            arg1[i] = a->x + dx * arg0->unk0;
            arg2[i] = a->y;
            arg3[i] = a->z + dz * arg0->unk0;
        } else {
            arg1[i] = i * 64;
            arg2[i] = 0.0f;
            arg3[i] = 0.0f;
        }
    }
}

struct func_1508907C_s {
    u8 pad[9];
    u8 links[5];
    u8 unkE;
    u8 unkF;
};

u8 func_1508907C(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    struct func_1508907C_s *q;
    struct func_1508907C_s *p;
    s32 i;
    u8 ret = 0xFF;

    if (arg0 >= D_80087290) {
        return 0xFF;
    }
    p = (struct func_1508907C_s *)&D_800D2350[arg0];
    for (i = 0; i < 5; i++) {
        if (p->links[i] != 0xFF && p->links[i] != arg2) {
            q = &((struct func_1508907C_s *)D_800D2350)[p->links[i]];
            if (q->unkE == arg1 || arg1 == 0xFF) {
                if (q->unkF == arg3) {
                    return p->links[i];
                }
                ret = p->links[i];
            }
        }
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150891E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150896EC.s")

extern void *D_800D23B0;

void func_15089BB0(void) {
    D_800D23B0 = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15089BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15089F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508A1BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508A6FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B194.s")

struct func_1508B1D4_s {
    u8 pad0[0x70];
    struct {
        s16 unk0;
        u8 pad2[0xA];
    } unk70[1];
};
extern struct func_1508B1D4_s *gGameState;

void func_1508B1D4(s32 arg0) {
    if (arg0 < D_8008FD90) {
        gGameState->unk70[arg0].unk0 = 0;
    }
}

struct func_1508B20C_e {
    f32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};

struct func_1508B20C_s {
    u8 pad0[0x1745];
    s8 unk1745;
    u8 pad1746[2];
    struct func_1508B20C_e unk1748[8];
};

void func_1508B20C(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 i;

    if (D_800D23B0 != NULL) {
        if (((struct func_1508B20C_s *)D_800D23B0)->unk1745 < 8) {
            i = ((struct func_1508B20C_s *)D_800D23B0)->unk1745++;
            ((struct func_1508B20C_s *)D_800D23B0)->unk1748[i].unk4 = arg0;
            ((struct func_1508B20C_s *)D_800D23B0)->unk1748[i].unk6 = arg1;
            ((struct func_1508B20C_s *)D_800D23B0)->unk1748[i].unk8 = arg2;
            ((struct func_1508B20C_s *)D_800D23B0)->unk1748[i].unk0 = arg3 * arg3;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B2A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B3F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B9BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508BC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508BF14.s")

s32 func_1508C194(s32 arg0) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508C1A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508C5B8.s")

s32 func_1508C9CC(void) {
    s32 count = 0;
    s32 result = -1;
    s8 i;

    i = ((s8 *)D_800D23B0)[0x1702];
    do {
        i++;
        if (i >= D_8008FD8C) {
            i = 0;
        }
        if (gObjects[i].interaction_state != 0 && gObjects[i].unk31C != NULL &&
            gObjects[i].unk31C->unk84 != 0 && !(D_800D18A0 & (1 << i))) {
            count = D_8008FD8C;
            result = i;
        }
        count++;
    } while (count < D_8008FD8C);
    ((s8 *)D_800D23B0)[0x1702] = i;
    return result;
}

extern void *D_800D23B0;

s32 func_1508CA88(void) {
    ((s8 *)D_800D23B0)[0x1703]++;
    if (((s8 *)D_800D23B0)[0x1703] >= D_8008FD90) {
        ((s8 *)D_800D23B0)[0x1703] = 0;
    }
    return ((s8 *)D_800D23B0)[0x1703];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508CAD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508D850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508DA1C.s")

struct func_1508DAEC_s {
    u8 pad0[0xEAC];
    s32 unkEAC;
    s32 unkEB0[48];
    s32 unkF70[64];
    s32 unk1070[32];
    s32 unk10F0[65];
    s32 unk11F4[64];
    s32 unk12F4[32];
    s32 unk1374[32];
    s32 unk13F4[32];
    s32 unk1474[32];
};

s32 func_1508DAEC(s32 arg0, s32 arg1) {
    s32 idx;
    s32 val;
    struct127 *obj;
    
    if (D_800D23B0 == NULL) {
        return 0;
    }
    idx = ((struct func_1508DAEC_s *)D_800D23B0)->unkEB0[arg0];
    if (idx >= 0) {
        if (arg1 < 0) {
            return 1;
        }
        ((struct func_1508DAEC_s *)D_800D23B0)->unkEB0[arg0] = -1;
        if (!(((struct func_1508DAEC_s *)D_800D23B0)->unk11F4[idx] & 2)) {
            ((struct func_1508DAEC_s *)D_800D23B0)->unkF70[idx] = -1;
            ((struct func_1508DAEC_s *)D_800D23B0)->unk10F0[idx] = -1;
            obj = &gObjects[arg0];
            val = ((struct func_1508DAEC_s *)D_800D23B0)->unkEAC;
            if (arg1 == 1) {
                ((struct func_1508DAEC_s *)D_800D23B0)->unk12F4[idx] = 300;
                ((struct func_1508DAEC_s *)D_800D23B0)->unk1374[idx] = obj->x_position;
                ((struct func_1508DAEC_s *)D_800D23B0)->unk13F4[idx] = obj->y_position + 50.0f;
                ((struct func_1508DAEC_s *)D_800D23B0)->unk1474[idx] = obj->z_position;
                val = 4;
            }
            ((struct func_1508DAEC_s *)D_800D23B0)->unk1070[idx] = val;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508DC24.s")

void func_1508E6C8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508E6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508E780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508E89C.s")

void func_1508EB90(s32 arg0, s32 arg1, s32 arg2) {
    u8 v0 = D_800CC40F[arg0 * 812];

    func_1509BFB0(1, v0 | 0x2000, arg1, arg2);
}

void func_1508EBF8(s32 arg0, s32 arg1) {
    u8 v0 = D_800CC40F[arg0 * 812];

    func_1509BFB0(1, v0 | 0x2000, 0x14, arg1);
}

void func_1508EC5C(s32 arg0, s32 arg1) {
    u8 v0 = D_800CC40F[arg0 * 812];
    func_1509BFB0(1, v0 | 0x2000, 0x61, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508ECC0.s")

struct func_1508EDBC_s {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    u8 pad8[0x10];
};

void func_1508EDBC(u32 arg0) {
    if (arg0 < D_80087380) {
        ((struct func_1508EDBC_s *)D_800D23C0)[arg0].unk2 = 0;
        ((struct func_1508EDBC_s *)D_800D23C0)[arg0].unk4 = 0;
        ((struct func_1508EDBC_s *)D_800D23C0)[arg0].unk0 = 0;
    }
}

struct func_1508EE0C_s {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    u16 unk8[8];
};

void func_15114B94(s32);
void func_1503DDD0(s32);

#define D (*(struct func_1508EE0C_s **)&D_800D23C0)

void func_1508EE0C(u16 arg0, u16 arg1) {
    u32 i;
    u32 j;
    s32 t;
    u16 key;

    for (i = 0; i < D_80087380; i++) {
        key = (arg0 << 12) + arg1;
        for (j = 0; j < D[i].unk2; j++) {
            if (D[i].unk8[j] == key) {
                for (j = 0; j < D[i].unk2; j++) {
                    t = D[i].unk8[j] & 0xFFF;
                    switch (D[i].unk8[j] >> 12) {
                        case 2:
                            func_15114B94(t);
                            break;
                        case 3:
                            func_1503DDD0(t);
                            break;
                    }
                }
                func_1508EDBC(i);
                return;
            }
        }
    }
}
