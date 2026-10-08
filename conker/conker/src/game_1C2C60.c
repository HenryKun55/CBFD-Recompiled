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

struct func_15195D00_s {
    u8 pad0[8];
    s32 unk8;
    u16 unkC;
    u8 unkE;
    u8 padF;
    struct func_15195D00_s *next;
};

void *func_151957B0(s32, void *, s32 *);

void func_15195D00(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct func_15195D00_s *p;
    struct func_15195D00_s *n;

    n = *(struct func_15195D00_s **)((u8 *)arg0 + 0x18);
    if (n != NULL) {
        p = n;
        do {
            if (arg1 == p->unk8 && arg2 == p->unkC) {
                return;
            }
            if (p->next != NULL) {
                p = p->next;
            }
        } while (p->next != NULL);
        n = p->next = func_151957B0(0x14, &D_800E08E0, &D_800E08E4);
    } else {
        n = *(struct func_15195D00_s **)((u8 *)arg0 + 0x18) = func_151957B0(0x14, &D_800E08E0, &D_800E08E4);
    }
    n->unk8 = arg1;
    n->unkC = arg2;
    n->unkE = arg3;
    n->next = NULL;
}

struct func_15195DD4_s {
    u8 pad0[4];
    struct func_15195DD4_s *next;
    s16 unk8;
    u8 padA[8];
    u8 unk12;
    u8 unk13;
    u8 unk14;
};

typedef struct {
    s32 unk0;
    s32 unk4;
} func_15195DD4_e;

s32 func_15195868(void *, s32, s32, s32 *);
struct func_15195DD4_s *func_15195984(s32, s32, s32, s32);

void *func_15195DD4(func_15195DD4_e *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 idx;
    s32 key;
    s32 r;
    s32 sp50;
    s32 val;
    s32 val0;
    struct func_15195DD4_s *n;

    idx = arg3;
    if (arg0 == NULL) {
        return NULL;
    }
    if (D_800BEAC0) {
        return NULL;
    }
    if (arg3 == -1) {
        idx = 0;
    }
    do {
        r = func_15195868(arg0, arg1, idx, &sp50);
        if (r == -1) {
            arg3 = 0;
            continue;
        }
        if (arg1 == 0) {
            arg1 = D_800E08F0;
        }
        key = arg4 ? -1 : arg1;
        n = D_800E08E8;
        while (n != NULL && key != n->unk8) {
            n = n->next;
        }
        val = ((func_15195DD4_e *)((u8 *)arg0 + r * 8))->unk4;
        val0 = ((func_15195DD4_e *)((u8 *)arg0 + r * 8))->unk0;
        if (n == NULL) {
            n = func_15195984(arg1, val, val0, arg2);
            if (n != NULL) {
                n->unk12 = arg5;
                n->unk13 = arg6;
            } else {
                return NULL;
            }
        } else {
            r = func_15195A84(r, n, val, arg2);
        }
        arg4 = 0;
        if (n->unk14 < sp50) {
            n->unk14 = sp50;
        }
        func_15195D00(n, arg0, r, sp50);
        idx++;
    } while (arg3 == -1);
    if (arg1 == D_800E08F0) {
        D_800E08F0--;
    }
    return n;
}

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

struct func_15197AB4_s {
    u8 pad0[0x34];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    u8 pad4C[0x140 - 0x4C];
    f32 unk140;
    f32 unk144;
    f32 unk148;
    f32 unk14C;
    f32 unk150;
    f32 unk154;
    f32 unk158;
    f32 unk15C;
    f32 unk160;
};

s32 func_15197AB4(struct func_15197AB4_s *arg0) {
    arg0->unk140 *= arg0->unk15C;
    arg0->unk144 += arg0->unk158 * D_800BE9A4;
    arg0->unk148 *= arg0->unk15C;
    arg0->unk14C *= arg0->unk160;
    arg0->unk150 += arg0->unk158 * D_800BE9A4;
    arg0->unk154 *= arg0->unk160;
    arg0->unk34 += arg0->unk140 * D_800BE9A4;
    arg0->unk38 += arg0->unk144 * D_800BE9A4;
    arg0->unk3C += arg0->unk148 * D_800BE9A4;
    arg0->unk40 += arg0->unk14C * D_800BE9A4;
    arg0->unk44 += arg0->unk150 * D_800BE9A4;
    arg0->unk48 += arg0->unk154 * D_800BE9A4;
    return 1;
}

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

struct func_15198054_s {
    s32 unk0;
    u8 unk4;
};

struct func_15198054_arg1 {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_151993B4();

void func_15198054(void *arg0, struct func_15198054_arg1 *arg1, u8 arg2) {
    struct func_15198054_s *temp_v1 = *(struct func_15198054_s **)((char *)arg0 + 0x98);

    if (arg2 == 0 || arg2 == 2 || arg2 == 8) {
        if (arg1->unk0 == temp_v1->unk0 || ((struct func_15198054_s *)arg1)->unk4 == temp_v1->unk4) {
            func_151993B4(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v1->unk0 == arg1->unk0) {
            temp_v1->unk0 = arg1->unk4;
            temp_v1->unk4 = arg1->unk9;
        } else if (temp_v1->unk0 == arg1->unk4) {
            temp_v1->unk0 = arg1->unk0;
            temp_v1->unk4 = arg1->unk8;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151987CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519897C.s")

void func_15198C60(void) {
    func_10010F30(0x1AA, 0x7FFF, 0x40, 0, 0);
}

struct func_15198C90_elem {
    f32 x;
    f32 y;
    f32 z;
    u8 pad[0x24 - 0xC];
};

struct func_15198C90_inner {
    u8 pad0[0x66];
    u16 unk66;
};

struct func_15198C90_s {
    u8 pad0[0x2C];
    s8 unk2C;
    s8 unk2D;
    u8 pad2E[0x94 - 0x2E];
    struct func_15198C90_elem *unk94;
    struct func_15198C90_inner *unk98;
};

void func_15198C90(struct func_15198C90_s *arg0) {
    struct func_15198C90_inner *temp_v0 = arg0->unk98;
    struct func_15198C90_elem *temp_v1 = arg0->unk94;

    if (arg0->unk2C != 0) {
        if (temp_v0->unk66 != 0) {
            func_1000F91C(temp_v0->unk66, 0x7FFF, 0, 0, 0,
                          temp_v1[arg0->unk2D].x, temp_v1[arg0->unk2D].y, temp_v1[arg0->unk2D].z, 500, 5000);
        }
    }
}

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

struct func_1519986C_s {
    s32 unk0;
    union {
        u8 b;
        s32 w;
    } unk4;
    u8 unk8;
    u8 unk9;
};

void func_1519986C(struct102 *arg0, struct func_1519986C_s *arg1, u8 arg2) {
    struct func_1519986C_s *temp_v1 = *(struct func_1519986C_s **)((u8 *)arg0 + 0x98);

    if (arg2 == 0 || arg2 == 2 || arg2 == 0x26) {
        if (arg1->unk0 == temp_v1->unk0 || arg1->unk4.b == temp_v1->unk4.b) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v1->unk0 == arg1->unk0) {
            temp_v1->unk0 = arg1->unk4.w;
            temp_v1->unk4.b = arg1->unk9;
        } else if (temp_v1->unk0 == arg1->unk4.w) {
            temp_v1->unk0 = arg1->unk0;
            temp_v1->unk4.b = arg1->unk8;
        }
    }
}

void func_15199928(s32 arg0) {
    func_15199980(arg0);
    func_151478F4(arg0);
}

void func_15199954(s32 arg0) {
    func_15199980(arg0);
    func_15147928(arg0);
}

extern void (*D_8008F8C0[])(s32);
extern void (*D_8008F8B4[])(s32);

int func_15199980(arg0) s32 arg0; {
    char *temp_v1 = *(char **)(arg0 + 0x98);

    if (*(s8 *)(temp_v1 + 0x39) != -1) {
        D_8008F8C0[*(s8 *)(temp_v1 + 0x39)](arg0);
    }
    if (*(s8 *)(temp_v1 + 0x36) != -1) {
        D_8008F8B4[*(s8 *)(temp_v1 + 0x36)](arg0);
    }
    if (*(struct102 **)(temp_v1 + 0x148) != NULL) {
        func_1516972C(*(struct102 **)(temp_v1 + 0x148));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519A9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519B4B8.s")

struct func_1519BE1C_s { f32 x, y, z; };
void func_1519BE1C(struct func_1519BE1C_s *pos, struct func_1519BE1C_s *vel, f32 accel, f32 t) {
    struct func_1519BE1C_s v = *vel;
    vel->y += accel * t;
    pos->x += v.x * t;
    pos->y += v.y * t + 0.5f * accel * t * t;
    pos->z += v.z * t;
}

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

struct func_1519BFBC_v { f32 x; f32 y; f32 z; u8 pad[0x1C]; };
struct func_1519BFBC_s {
    u8 pad0[0x2C];
    s8 unk2C;
    s8 unk2D;
    u8 pad2E[0x94 - 0x2E];
    struct func_1519BFBC_v *unk94;
    u8 *unk98;
};
void func_1519BFBC(struct func_1519BFBC_s *arg0) {
    u8 *t = arg0->unk98;
    struct func_1519BFBC_v *v = arg0->unk94;
    if (arg0->unk2C != 0) {
        if (*(u16 *)(t + 0x130) != 0) {
            func_1000F91C(*(u16 *)(t + 0x130), 0x7FFF, 0, 0, 0,
                          v[arg0->unk2D].x, v[arg0->unk2D].y, v[arg0->unk2D].z, 0x1F4, 0x1388);
        }
    }
}

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

struct225 *func_151602C0();
void *memcpy(void *, const void *, u32);
extern f32 D_800A8AF8;

struct func_1519C09C_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct225 *func_1519C09C(s32 arg0, f32 *arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, s32 arg7) {
    struct225 *temp_v0;
    Header header;
    Header2 header2;
    s32 tmp;
    struct func_1519C09C_s data;

    tmp = arg0;
    data.unk0 = 35.0f;
    data.unk4 = 5.0f;
    data.unk8 = 110.0f;
    data.unkC = 1.0f;
    data.unk10 = 0.0f;
    data.unk14 = 7.0f;
    data.unk18 = D_800A8AF8;
    data.unk1C = 127.0f;
    header.unk0 = 2;
    header.unk1 = 2;
    header.unk2 = 300;
    header.unk4 = 0x22;
    header2.unk0 = arg1[0];
    header2.unk4 = arg1[1];
    header2.unk8 = arg1[2];
    temp_v0 = func_151602C0(&header, &header2, arg2, arg3, arg4, arg5, 0xFF, 0, sizeof(data) + sizeof(tmp), arg6, arg7);
    if (temp_v0 != NULL) {
        memcpy(&temp_v0->unk18, &data, sizeof(data));
        memcpy((u8 *)&temp_v0->unk18 + sizeof(data), &tmp, sizeof(tmp));
    }
    return temp_v0;
}

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
