#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15188810_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s8 unk4;
    u8 pad5;
    s16 unk6;
    void *unk8;
    struct func_15188810_s *unkC;
    u8 *unk10;
    s32 unk14;
};

extern void *allocate_memory(s32, s32, s32, s32);
extern void func_10004074(void *);
extern s32 func_1502DB20(u8);
void func_15188A58();

void func_15188810(u8 *arg0, s32 arg1, s32 arg2) {
    struct func_15188810_s *var_s0;
    u32 n;
    void *temp_v0_2;
    s32 pad[2];

    for (var_s0 = (struct func_15188810_s *)D_800DF7C8[0]; var_s0 != NULL; var_s0 = var_s0->unkC) {
        if (arg0 == var_s0->unk10) {
            if (var_s0->unk6 < arg1) {
                var_s0->unk6 = arg1;
            }
            var_s0->unk4 = arg2;
            return;
        }
    }
    var_s0 = allocate_memory(0x18, 1, 0, 0);
    if (var_s0 != NULL) {
        n = func_1502DB20(arg0[4]);
        if (n == 0) {
            func_10004074(var_s0);
            return;
        }
        temp_v0_2 = allocate_memory((n * 3) << 7, 1, 1, 1);
        if (temp_v0_2 == NULL) {
            func_10004074(var_s0);
            return;
        }
        var_s0->unk0 = 0;
        var_s0->unk1 = 3;
        var_s0->unk2 = 0;
        var_s0->unk3 = 0x14;
        var_s0->unk4 = arg2;
        var_s0->unk6 = arg1;
        var_s0->unk8 = temp_v0_2;
        var_s0->unk10 = arg0;
        var_s0->unk14 = 0;
        bzero(temp_v0_2, (n * 3) << 7);
        func_15188A58(var_s0, D_800DF7C8);
    }
}

struct func_1518894C_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s8 unk4;
    u8 pad5;
    s16 unk6;
    void *unk8;
    struct func_1518894C_s *unkC;
    s32 unk10;
};

extern struct func_1518894C_s *D_800DF7CC;
extern void *allocate_memory(s32, s32, s32, s32);
extern void func_10004074(void *);
void func_15188A58();

void func_1518894C(s32 arg0, s32 arg1, s32 arg2) {
    struct func_1518894C_s *var_s0;
    void *temp_v0_2;

    for (var_s0 = D_800DF7CC; var_s0 != NULL; var_s0 = var_s0->unkC) {
        if (arg0 == var_s0->unk10) {
            if (var_s0->unk6 < arg1) {
                var_s0->unk6 = arg1;
            }
            var_s0->unk4 = arg2;
            return;
        }
    }
    var_s0 = allocate_memory(0x14, 1, 0, 0);
    if (var_s0 != NULL) {
        temp_v0_2 = allocate_memory(0x180, 1, 1, 0);
        if (temp_v0_2 == NULL) {
            func_10004074(var_s0);
            return;
        }
        var_s0->unk0 = 1;
        var_s0->unk1 = 3;
        var_s0->unk2 = 0;
        var_s0->unk3 = 0x14;
        var_s0->unk4 = arg2;
        var_s0->unk6 = arg1;
        var_s0->unk8 = temp_v0_2;
        var_s0->unk10 = arg0;
        bzero(temp_v0_2, 0x180);
        func_15188A58(var_s0, &D_800DF7CC);
    }
}

struct func_15188A58_s {
    s32 pad[3];
    struct func_15188A58_s *next;
};

void func_15188A58(struct func_15188A58_s *arg0, struct func_15188A58_s **arg1) {
    struct func_15188A58_s *p;
    struct func_15188A58_s *next;

    arg0->next = NULL;
    if (*arg1 != NULL) {
        p = *arg1;
        while ((next = p->next) != NULL) {
            p = next;
        }
        p->next = arg0;
        return;
    }
    *arg1 = arg0;
}

struct func_15188A9C_s {
    u8 pad0[6];
    s16 unk6;
    u8 pad8[4];
    struct func_15188A9C_s *unkC;
    s32 unk10;
};

void func_15188A9C(s32 arg0) {
    struct func_15188A9C_s *var_v0;

    var_v0 = (struct func_15188A9C_s *)D_800DF7C8[0];
    if (var_v0 != NULL) {
        do {
            if (arg0 == var_v0->unk10) {
                var_v0->unk6 = 0;
            }
            var_v0 = var_v0->unkC;
        } while (var_v0 != NULL);
    }
}

struct func_15188AD0_s {
    u8 pad0[8];
    void *unk8;
    struct func_15188AD0_s *unkC;
    s32 unk10;
};

void func_10004074(void *arg0);

void func_15188AD0(s32 arg0) {
    struct func_15188AD0_s *p;
    struct func_15188AD0_s *next;
    struct func_15188AD0_s *prev;

    p = (struct func_15188AD0_s *)D_800DF7C8[0];
    prev = NULL;
    while (p != NULL) {
        next = p->unkC;
        if (arg0 == p->unk10) {
            if (prev == NULL) {
                D_800DF7C8[0] = (s32)next;
            } else {
                prev->unkC = next;
            }
            func_100043B4(p->unk8, 2);
            func_10004074(p);
        } else {
            prev = p;
        }
        p = next;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188B74.s")

struct func_15188D00_s {
    u8 unk0;
    u8 pad1[0xB];
    struct func_15188D00_s *unkC;
};

extern Mtx D_80089470;
extern Gfx *(*D_8008D590[])(Gfx *, struct func_15188D00_s *, s16);

Gfx *func_15188D00(Gfx *gdl, s32 arg1, s16 arg2) {
    struct func_15188D00_s *p;

    p = (struct func_15188D00_s *)D_800DF7C8[arg1];
    if (p == NULL) {
        return gdl;
    }
    gSPMatrix(gdl++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    { Gfx *_g = gdl++; _g->words.w0 = 0xD9FFFFFF; _g->words.w1 = 0x200004; }
    { Gfx *_g = gdl++; _g->words.w0 = 0xD9EEFFFF; _g->words.w1 = 0; }
    gDPPipeSync(gdl++);
    { Gfx *_g = gdl++; _g->words.w0 = 0xE2001E01; _g->words.w1 = 0; }
    { Gfx *_g = gdl++; _g->words.w0 = 0xEC000000; _g->words.w1 = 0xFF; }
    while (p != NULL) {
        gdl = D_8008D590[p->unk0](gdl, p, arg2);
        p = p->unkC;
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15189118.s")

struct func_151895A4_s {
    s32 unk0;
    s32 unk4;
    void *unk8;
};

void func_151895A4(struct func_151895A4_s *arg0) {
    func_100043B4(arg0->unk8, 2);
}

void func_151895CC(void **arg0) {
    func_100043B4(arg0[2], 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_151895F4.s")

struct func_151897A4_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 *unk10;
};

extern s32 func_151137D4(s32, u8 *, s32, s32, s32, s32);

s32 func_151897A4(s32 arg0, struct func_151897A4_s *arg1, s16 arg2) {
    s32 i;
    s32 n;
    s32 m;
    s32 start;
    s32 k;
    s32 t;
    s32 pad1; // unused, sizes the frame
    s32 pad2;
    s32 saved;

    if (arg1->unk2 == 0) {
        return arg0;
    }
    k = arg1->unk1;
    n = arg1->unk2;
    m = arg1->unk3;
    start = D_800BE9C0 * k;
    saved = arg1->unk10[0x8A];
    for (i = 0, t = m * 96; i < n; t += m * 32, i++) {
        arg1->unk10[0x8A] = t >> 8;
        arg0 = func_151137D4(arg0, arg1->unk10, arg1->unk8 + ((start + i) << 6), arg2, 0, 0);
    }
    arg1->unk10[0x8A] = saved;
    return arg0;
}

struct func_151898C0_s {
    char pad0[0xC];
    struct func_151898C0_s *next;
    s32 id;
    s32 val;
};

void func_151898C0(s32 arg0, s32 arg1) {
    struct func_151898C0_s *var_v0;

    for (var_v0 = (struct func_151898C0_s *)D_800DF7C8[0]; var_v0 != NULL; var_v0 = var_v0->next) {
        if (arg0 == var_v0->id) {
            var_v0->val = arg1;
            return;
        }
    }
}
