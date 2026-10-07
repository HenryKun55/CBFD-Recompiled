#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void *func_15147D64();

void func_1519CF70(u8 arg0) {
    u8 sp1C[4];

    sp1C[0] = arg0;
    func_15147D64(sp1C, 6);
}

struct func_1519CFA0_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
    u8 pad31[0x98 - 0x31];
    u8 *unk98;
};

void func_1519CFA0(struct func_1519CFA0_s *arg0) {
    u8 *temp_v0 = arg0->unk98;
    arg0->unk1E &= ~2;
    arg0->unk30 = 0;
    temp_v0[6] |= 1;
    temp_v0[6] |= 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519CFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D9F4.s")

struct func_1519E1F4_s {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x4C - 5];
    u8 unk4C;
};

struct func_1519E1F4_a {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_1519E1F4(struct func_1519CFA0_s *arg0, struct func_1519E1F4_a *arg1, u8 arg2) {
    struct func_1519E1F4_s *temp_v0 = (struct func_1519E1F4_s *)arg0->unk98;

    if (arg2 == 0) {
        if (arg1->unk0 == temp_v0->unk0 || ((u8 *)arg1)[4] == temp_v0->unk4) {
            func_1519CFA0(arg0);
        }
    } else if (arg2 == 6) {
        if (((u8 *)arg1)[0] == ((u8 *)temp_v0)[0x4C]) {
            func_1519CFA0(arg0);
        }
    } else if (arg2 == 7) {
        if (arg1->unk0 == temp_v0->unk0 || ((u8 *)arg1)[4] == temp_v0->unk4) {
            func_1519CFA0(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v0->unk0 == arg1->unk0) {
            temp_v0->unk0 = arg1->unk4;
            temp_v0->unk4 = arg1->unk9;
        } else if (temp_v0->unk0 == arg1->unk4) {
            temp_v0->unk0 = arg1->unk0;
            temp_v0->unk4 = arg1->unk8;
        }
    }
}

struct func_1519E304_s {
    void *obj;
    u8 pad4;
    u8 unk5;
    u8 pad6[2];
    u8 unk8[1];
};

s32 func_1519E304(struct func_1519E304_s *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 sp1C[3];

    if (*(s32 *) ((char *) arg0->obj + 0x1D4) == 0) {
        return 0;
    }
    func_15143134(arg0->unk8, sp1C, *(s32 *) ((char *) arg0->obj + 0x1D4) + (arg0->unk5 << 6));
    arg1[0] = ((sp1C[0] - arg2) * arg5) + arg2;
    arg1[1] = ((sp1C[1] - arg3) * arg5) + arg3;
    arg1[2] = ((sp1C[2] - arg4) * arg5) + arg4;
    return 1;
}

void func_1519E688(void);
void *func_1519D030(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);

void func_1519E3BC(s32 arg0, s16 arg1, u8 arg2, s32 arg3) {
    func_1519E688();
    func_1519D030(arg0, 3, 0x12C, 0, arg2, arg3);
    func_1519D030(arg0, 4, 0x12C, 0, arg2, arg3);
    func_151491F4(arg1, 6, -1, 1, 3, NULL, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E464.s")

struct func_1519E570_s {
    s32 unk0;
    u8 unk4;
};

struct func_1519E570_t {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_1519E570(struct102 *arg0, struct func_1519E570_t *arg1, u8 arg2) {
    struct func_1519E570_s *temp_v0 = (struct func_1519E570_s *)((u8 *)arg0 + 0x28);

    if (arg2 == 0) {
        if ((arg1->unk0 == temp_v0->unk0) || (((struct func_1519E570_s *)arg1)->unk4 == temp_v0->unk4)) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v0->unk0 == arg1->unk0) {
            temp_v0->unk0 = arg1->unk4;
            temp_v0->unk4 = arg1->unk9;
        } else if (temp_v0->unk0 == arg1->unk4) {
            temp_v0->unk0 = arg1->unk0;
            temp_v0->unk4 = arg1->unk8;
        }
    }
}

void func_1519E61C(struct102 *arg0, s32 arg1, u8 arg2) {
    if ((arg2 == 0) || (arg2 == 9)) {
        func_1516972C(arg0);
    }
}

void func_1519E65C(s32 arg0) {
    func_1519CF70(3);
    func_1519CF70(4);
}

void func_1519E688(void) {
    func_1519CF70(3);
    func_1519CF70(4);
    func_15147D64(0, 9);
}

extern s32 D_800E0920;
void *memcpy(void *dst, const void *src, u32 size);

struct func_1519E6BC_s {
    void *unk0;
    u8 unk4;
    s32 unk8;
};

void func_1519E6BC(void *arg0) {
    struct func_1519E6BC_s sp2C;

    func_1519E688();
    if (D_800E0920 == 0) {
        sp2C.unk8 = 0;
        sp2C.unk0 = arg0;
        sp2C.unk4 = ((u8 *)arg0)[0x3B];
        if ((D_800E0920 = (s32)func_151491F4(0x12C, -1, 9, 0, 4, (struct37 *)0xC, 0xFF, 0)) != 0) {
            memcpy((u8 *)D_800E0920 + 0x28, &sp2C, 0xC);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E754.s")

extern s32 D_800E0920;

typedef struct {
    s32 unk0;
    u8 unk4;
} func_1519E818_sub;

struct func_1519E818_s {
    u8 pad0[0x28];
    func_1519E818_sub unk28;
};

struct func_1519E818_a {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_1519E818(struct func_1519E818_s *arg0, struct func_1519E818_a *arg1, u8 arg2) {
    func_1519E818_sub *s = &arg0->unk28;

    if (arg2 == 0) {
        if ((arg1->unk0 == s->unk0) || (((u8 *)arg1)[4] == s->unk4)) {
            func_1516972C((struct102 *)arg0);
            { s32 *p = &D_800E0920; *p = 0; }
        }
    } else if (arg2 == 0x2D) {
        if (s->unk0 == arg1->unk0) {
            s->unk0 = arg1->unk4;
            s->unk4 = arg1->unk9;
        } else if (s->unk0 == arg1->unk4) {
            s->unk0 = arg1->unk0;
            s->unk4 = arg1->unk8;
        }
    }
}

struct func_1519E8CC_s {
    u8 pad0[0x28];
    s32 unk28;
};

void func_1514EDF0(struct func_1519E8CC_s *arg0, s32 arg1);

void func_1519E8CC(struct func_1519E8CC_s *arg0) {
    func_1514EDF0(arg0, arg0->unk28);
    func_1514933C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E8F8.s")

extern s32 D_800E0920;

void func_1519E924(s32 arg0) {
    D_800E0920 = 0;
    func_1514933C(arg0);
}

extern s32 D_800E0920;

void func_1519E948(void) {
    D_800E0920 = 0;
    func_15149368();
}
