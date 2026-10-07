#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1515BAE0_s {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8 pad16[2];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[0x18];
    /* 0x38 */ s8 unk38;
    /* 0x39 */ s8 unk39;
};

extern s32 (*D_8008B078[])(struct func_1515BAE0_s *);
extern s32 (*D_8008B07C[])(struct func_1515BAE0_s *);
u8 func_1514401C(u8, s32 *, s32 *, u8);

void func_1515BAE0(struct func_1515BAE0_s *arg0) {
    s32 pad;
    u8 done = 0;

    if (arg0->unk11 & 1) {
        arg0->unk14 -= D_800BE9E4;
        if (arg0->unk14 < 0) {
            done = 1;
        }
    }
    if (!done) {
        if (arg0->unk38 != -1) {
            if (D_8008B078[arg0->unk38](arg0) == 0) {
                done = 1;
            }
        }
        if (arg0->unk1C != 0) {
            done = func_1514401C(arg0->unk10, &arg0->unk1C, &arg0->unk18, arg0->unk12);
        }
    }
    if (done) {
        if (arg0->unk39 != -1) {
            if (D_8008B07C[arg0->unk39](arg0) != 0) {
                func_1516972C(arg0);
            }
        } else {
            func_1516972C(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515BBF0.s")

struct func_1515BE50_inner {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};
struct func_1515BE50_s {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    u8 unk18[8];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    s32 unk44;
    s32 unk48;
};
extern void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void *memcpy(void *, const void *, u32);

struct func_1515BE50_s *func_1515BE50(struct func_1515BE50_inner **arg0, s32 arg1, u8 arg2, s32 arg3) {
    struct func_1515BE50_s *ret;

    if (*arg0 == NULL) {
        return NULL;
    }
    ret = func_15167A68(0x32, arg3, arg1 + 0x50, 1, arg2, 1);
    if (ret == NULL) {
        return NULL;
    }
    memcpy(ret->unk18, arg0, 8);
    ret->unk20 = (*arg0)->unk14;
    ret->unk24 = (*arg0)->unk18;
    ret->unk28 = (*arg0)->unk1C;
    ret->unk2C = (*arg0)->unk14;
    ret->unk30 = (*arg0)->unk18;
    ret->unk34 = (*arg0)->unk1C;
    ret->unk44 = 0;
    ret->unk48 = -1;
    ret->unk10 = 1;
    ret->unk14 = 0;
    ret->unk38 = 0.0f;
    ret->unk3C = 0.0f;
    ret->unk40 = 0.0f;
    return ret;
}

void func_1514EDF0(s32 arg0, s32 arg1);

void func_1515BF50(s32 *arg0) {
    func_1514EDF0(arg0, arg0[6]);
    func_15169804(arg0);
}

void func_1515BF7C(s32 *arg0) {
    func_1514EDF0(arg0, arg0[6]);
    func_15169824(arg0);
}

typedef struct { f32 x, y, z; } func_1515BFA8_v;
struct func_1515BFA8_t {
    s32 unk0;
    u8 pad4[0x10];
    func_1515BFA8_v pos;
    u8 pad20[0x3B - 0x20];
    u8 unk3B;
};
struct func_1515BFA8_s {
    u8 pad0[0x18];
    struct func_1515BFA8_t *unk18;
    u8 unk1C;
    u8 unk1D;
    s16 unk1E;
    func_1515BFA8_v pos;
    func_1515BFA8_v prev;
    func_1515BFA8_v vel;
};

void func_1515BFA8(struct func_1515BFA8_s *arg0) {
    s32 done = 0;

    if (arg0->unk1D & 1) {
        arg0->unk1E -= D_800BE9E4;
        if (arg0->unk1E < 0) {
            done = 1;
        }
    }
    if (arg0->unk18->unk0 == 0 || arg0->unk18->unk3B != arg0->unk1C) {
        done = 1;
    }
    if (!done) {
        arg0->prev = arg0->pos;
        arg0->pos.x = arg0->unk18->pos.x;
        arg0->pos.y = arg0->unk18->pos.y;
        arg0->pos.z = arg0->unk18->pos.z;
        arg0->vel.x = (arg0->prev.x - arg0->pos.x) * D_800BE9A8;
        arg0->vel.y = (arg0->prev.y - arg0->pos.y) * D_800BE9A8;
        arg0->vel.z = (arg0->prev.z - arg0->pos.z) * D_800BE9A8;
    }
    if (done) {
        func_1516972C((struct102 *)arg0);
    }
}

void func_1515C0B8(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x18, arg0 + 0x1C, arg0);
}

s32 func_1514ECE0();

s32 func_1515C0F8(s32 arg0, s32 *arg1) {
    s32 sp1C;
    s32 temp;

    if (arg0 == 0) {
        return 0;
    }
    if (func_1514ECE0(*(s32 *)(arg0 + 0x2F4), 0x16, &sp1C) != 0) {
        temp = *(s32 *)(sp1C + 0x10);
        *arg1 = temp + 0x38;
        return 1;
    }
    return 0;
}

struct func_1515C158_node {
    u8 pad0[8];
    struct func_1515C158_node *next;
    u8 padC[0x38];
    s32 unk44;
    s32 unk48;
};

struct func_1515C158_s {
    u8 pad0[0xC8];
    struct func_1515C158_node *head;
    u8 padCC[0x1A0 - 0xCC];
};

extern struct func_1515C158_s D_800DCE50[];

void func_1515C158(void) {
    s32 i;
    struct func_1515C158_node *n;

    for (i = 0; i < 2; i++) {
        for (n = D_800DCE50[i].head; n != NULL; n = n->next) {
            n->unk44 = 0;
            n->unk48 = -1;
        }
    }
}

void func_1515C1A0(u8 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    if ((arg0[4] < 0xBB) && (arg0[4] != 0xFF)) {
        *arg2 = *(s16 *)(arg0 + 0xD2);
        *arg3 = *(s16 *)(arg0 + 0xD4);
        arg1[0] = *(f32 *)(arg0 + 0x14);
        arg1[1] = *(s16 *)(arg0 + 0xD6) + *(f32 *)(arg0 + 0x18);
        arg1[2] = *(f32 *)(arg0 + 0x1C);
    } else {
        *arg2 = 1.0f;
        *arg3 = 1.0f;
        arg1[0] = *(f32 *)(arg0 + 0x14);
        arg1[1] = *(f32 *)(arg0 + 0x18);
        arg1[2] = *(f32 *)(arg0 + 0x1C);
    }
}

struct func_1515C244_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x14 - 5];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0xE4 - 0x20];
    s16 unkE4;
    s16 unkE6;
    s16 unkE8;
};

void func_1515C244(struct func_1515C244_s *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    if (arg0->unk4 < 0xBB && arg0->unk4 != 0xFF) {
        *arg2 = arg0->unkE4;
        *arg3 = arg0->unkE6;
        arg1[0] = arg0->unk14;
        arg1[1] = arg0->unk18 + arg0->unkE8;
        arg1[2] = arg0->unk1C;
    } else {
        *arg2 = 1.0f;
        *arg3 = 1.0f;
        arg1[0] = arg0->unk14;
        arg1[1] = arg0->unk18;
        arg1[2] = arg0->unk1C;
    }
}
