#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151957B0.s")

extern void *D_800E08E0;
extern s32 D_800E08E4;
extern void *D_800E08E8;
extern s32 D_800E08EC;
extern s32 D_800E08F0;

void func_1519582C(void) {
    D_800E08E0 = (void *)(D_800E08E4 = 0);
    D_800E08E8 = (void *)(D_800E08EC = 0);
    D_800E08F0 = -2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195984.s")

s32 func_15195A84(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195DD4.s")

void *func_15195DD4();

void *func_15195FB0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_15195DD4(*(s32 *)((char *)arg0 + 0x1C), arg1, arg2, arg3, arg4, arg5, arg6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195FF0.s")

struct func_15196318_s {
    u8 pad[0x12];
    u8 unk12;
    u8 unk13;
};

void func_15196318(struct func_15196318_s *arg0, s32 arg1, s32 arg2) {
    if (arg0 != NULL) {
        arg0->unk12 = arg1;
        arg0->unk13 = arg2;
    }
}

extern void (*D_8008F898[])(void *);
extern void (*D_8008F88C[])(void *);
void func_151478F4();

struct func_15196330_s {
    u8 pad[0x62];
    s8 unk62;
    u8 pad63[2];
    s8 unk65;
};

void func_15196330(void *arg0) {
    struct func_15196330_s *s = *(struct func_15196330_s **)((char *)arg0 + 0x98);

    if (s->unk65 != -1) {
        D_8008F898[s->unk65](arg0);
    }
    if (s->unk62 != -1) {
        D_8008F88C[s->unk62](arg0);
    }
    func_151478F4(arg0);
}

extern void (*D_8008F898[])(void *);
extern void (*D_8008F88C[])(void *);

struct func_151963B4_s {
    u8 pad[0x62];
    s8 unk62;
    u8 pad63[2];
    s8 unk65;
};

void func_151963B4(void *arg0) {
    struct func_151963B4_s *s = *(struct func_151963B4_s **)((u8 *)arg0 + 0x98);

    if (s->unk65 != -1) {
        D_8008F898[s->unk65](arg0);
    }
    if (s->unk62 != -1) {
        D_8008F88C[s->unk62](arg0);
    }
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15196438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15196748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15196B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197148.s")

extern f32 D_800A8AA4;

f32 func_151979F8(s32 arg0) {
    return D_800A8AA4;
}

extern s32 D_800A8A40;
extern s32 D_800A8A48;
extern f32 D_800A8AA8;

f32 func_15197A0C(s32 arg0) {
    return (f32) func_151422C0(0xA, &D_800A8A40, 1, 0x1F4, &D_800A8A48, 0x8CC) * D_800A8AA8;
}

extern f32 D_800A8AAC;

f32 func_15197A68(s32 arg0) {
    return D_800A8AAC;
}

void *func_15147D64();

struct func_15197A7C_s {
    void *unk0;
    u8 unk4;
};

void func_15197A7C(u8 *arg0) {
    struct func_15197A7C_s sp18;

    if (arg0 != NULL) {
        sp18.unk0 = arg0;
        sp18.unk4 = arg0[0x3B];
        func_15147D64(&sp18, 8, arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197AB4.s")

struct func_15197BBC_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x5C - 0x34];
    u8 unk5C;
    u8 pad5D[0x164 - 0x5D];
    f32 unk164;
    s16 unk168;
    s16 unk16A;
};

s32 func_15197BBC(struct func_15197BBC_s *arg0) {
    arg0->unk30 -= arg0->unk30 * arg0->unk164;
    arg0->unk2C -= arg0->unk2C * arg0->unk164;
    if (arg0->unk1C < arg0->unk168) {
        arg0->unk5C = (u32)arg0->unk1C * arg0->unk16A;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198054.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151987CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519897C.s")

void func_15198C60(void) {
    func_10010F30(0x1AA, 0x7FFF, 0x40, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198C90.s")

struct func_15198D40_s {
    u8 pad0[0x2C];
    s8 unk2C;
    u8 pad2D[0x98 - 0x2D];
    struct func_15198D40_inner {
        u8 pad0[0x66];
        u16 unk66;
    } *unk98;
};

void func_15198D40(struct func_15198D40_s *arg0) {
    struct func_15198D40_inner *temp_v0 = arg0->unk98;

    if (arg0->unk2C != 0) {
        if (temp_v0->unk66 != 0) {
            func_100111C8(temp_v0->unk66);
        }
    }
}

void func_15198D7C(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151990AC.s")

struct func_151993B4_s_inner {
    u8 pad0[6];
    u8 unk6;
};

struct func_151993B4_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
    u8 pad31[0x98 - 0x31];
    struct func_151993B4_s_inner *unk98;
};

void func_151993B4(struct func_151993B4_s *arg0) {
    struct func_151993B4_s_inner *temp_v0 = arg0->unk98;

    arg0->unk30 = 0;
    arg0->unk1E &= ~2;
    temp_v0->unk6 |= 1;
    temp_v0->unk6 |= 4;
}

extern u8 D_800A8A9C[];
struct func_151993E4_s { u8 pad[0x14]; u8 unk14; };
struct func_151993E4_s2 { u8 pad[0x3B]; u8 unk3B; };
struct func_151993E4_s3 { u8 pad[0x98]; struct func_151993E4_s2 **unk98; };
void func_151993E4(struct func_151993E4_s3 *arg0) {
    struct func_151993E4_s2 **tmp;
    struct func_151993E4_s2 *tmp2;
    s32 i;
    s32 found;
    s32 val;

    tmp = arg0->unk98;
    tmp2 = *tmp;
    i = 0;
    found = 0;
    val = tmp2->unk3B;
    do {
        if (val == D_800A8A9C[i]) { found = 1; } else { i++; }
    } while (!found && i < 6);
    if (found) { ((struct func_151993E4_s **)D_800E0900)[i]->unk14 = 0; }
}

void func_1519944C(struct func_151993E4_s3 *arg0) {
    struct func_151993E4_s2 **tmp;
    struct func_151993E4_s2 *tmp2;
    s32 i;
    s32 found;
    s32 val;

    tmp = arg0->unk98;
    tmp2 = *tmp;
    i = 0;
    found = 0;
    val = tmp2->unk3B;
    do {
        if (val == D_800A8A9C[i]) { found = 1; } else { i++; }
    } while (!found && i < 6);
    if (found) { ((struct func_151993E4_s **)D_800E0900)[i]->unk14 = 1; }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151994B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519986C.s")

void func_15199928(s32 arg0) {
    func_15199980(arg0);
    func_151478F4(arg0);
}

void func_15199954(s32 arg0) {
    func_15199980(arg0);
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519A9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519B4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519BE1C.s")

extern u8 D_800A8A9C[];
struct func_1519BEB8_s { u8 pad[0x3B]; u8 unk3B; };
void func_1519BEB8(void *arg0) {
    
    struct func_1519BEB8_s **a;
    struct func_1519BEB8_s *s;
    
    s32 i;
    s32 found;
    u8 *p;
    s32 val;
    a = *(struct func_1519BEB8_s ***)((u8 *)arg0 + 0x98);
    s = *a;
    i = 0;
    found = 0;
    val = s->unk3B; p = D_800A8A9C;
    do {
        if (val == *p) { found = 1; } else { i++; p++; }
    } while (!found && i < 6);
    if (found) { *((u8 *)D_800E0900[i] + 0x14) = 0; }
}

struct func_1519BF20_s { u8 pad[0x3B]; u8 unk3B; };
void func_1519BF20(void *arg0) {
    
    struct func_1519BF20_s **a;
    struct func_1519BF20_s *s;
    
    s32 i;
    s32 found;
    u8 *p;
    s32 val;
    a = *(struct func_1519BF20_s ***)((u8 *)arg0 + 0x98);
    s = *a;
    i = 0;
    found = 0;
    val = s->unk3B; p = D_800A8A9C;
    do {
        if (val == *p) { found = 1; } else { i++; p++; }
    } while (!found && i < 6);
    if (found) { *((u8 *)D_800E0900[i] + 0x14) = 1; }
}

void func_1519BF8C(void) {
    func_10010F30(0x1AA, 0x7FFF, 0x40, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519BFBC.s")

struct func_1519C06C_s {
    u8 pad[0x130];
    u16 unk130;
};

void func_1519C06C(u8 *arg0) {
    struct func_1519C06C_s *s = *(struct func_1519C06C_s **)(arg0 + 0x98);
    if (s->unk130 != 0) {
        func_100111C8(s->unk130);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C22C.s")

void func_1519C258(s32 arg0) {
    s32 temp_v0;

    temp_v0 = *(s32 *)(*(s32 *)(arg0 + 0x38) + 0x98);
    *(s32 *)(temp_v0 + 0x148) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C26C.s")

struct func_1519C4E4_s2 {
    u8 pad0[0x24];
    f32 unk24;
    s16 unk28;
    s16 unk2A;
};

struct func_1519C4E4_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x5C - 0x34];
    u8 unk5C;
    u8 pad5D[0x110 - 0x5D];
    struct func_1519C4E4_s2 unk110;
};

s32 func_1519C4E4(struct func_1519C4E4_s *arg0) {
    s32 i;
    s32 t;
    struct func_1519C4E4_s2 *p = &arg0->unk110;

    for (i = D_800BE9E4; i > 0; i--) {
        arg0->unk2C -= arg0->unk2C * p->unk24;
        arg0->unk30 -= arg0->unk30 * p->unk24;
    }
    if (arg0->unk1C < p->unk28) {
        t = arg0->unk1C * p->unk2A;
        if (t < arg0->unk5C) {
            arg0->unk5C = t;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C56C.s")

struct func_1519C910_s {
    u8 pad0[0x84];
    u16 unk84;
};

struct func_1519C910_t {
    struct func_1519C910_s *unk0;
    u8 pad4[0x154];
    s32 unk158;
    s32 unk15C;
};

s32 func_1519C910(s32 arg0) {
    struct func_1519C910_t *p = *(struct func_1519C910_t **)(arg0 + 0x98);
    struct func_1519C910_s *q = p->unk0;

    if ((q->unk84 != p->unk158) && (q->unk84 != p->unk15C)) {
        return 0;
    }
    return 1;
}

void func_1519CDB0(void *arg0, f32 arg1, s32 arg2);

s32 func_1519C948(void *arg0) {
    func_1519CDB0(arg0, 0.25f, 0x1C);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C9C4.s")

struct func_1519CD64_s2 {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x3B - 5];
    u8 unk3B;
};
struct func_1519CD64_s {
    u8 pad0[0xD];
    u8 unkD;
    s16 unkE;
    u8 pad10[0x28 - 0x10];
    struct func_1519CD64_s2 *unk28;
    u8 unk2C;
};

void func_1519CD64(struct func_1519CD64_s *arg0) {
    struct func_1519CD64_s2 *temp = arg0->unk28;

    if ((temp->unk0 == 0) || (temp->unk4 == 0xFF) || (temp->unk3B != arg0->unk2C)) {
        arg0->unkE = -1;
        arg0->unkD |= 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519CDB0.s")
