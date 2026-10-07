#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151B9F00_s {
    u8 unk0;
    s8 unk1;
    u8 unk2;
    u8 pad3;
    s16 unk4;
    s16 pad6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 unk24;
    u8 unk25;
    u8 pad26[0xA];
    s32 unk30;
    s32 unk34;
    u8 unk38;
    u8 unk39;
};
struct func_151B9F00_t {
    void *obj;
    u8 unk4;
};
struct func_151B9F00_r {
    u8 pad0[0x50];
    s32 unk50;
    u8 pad54[0xA4];
    u8 unkF8[1];
};
extern void *func_1513B5E0(struct func_151B9F00_s *, s32, s32, u8, s32);
extern s8 D_800E0BCE[];

void *func_151B9F00(struct127 *arg0, u8 arg1, s32 arg2) {
    void *v0;
    struct func_151B9F00_s st;
    struct func_151B9F00_t data;
    s32 idx;

    if (arg0 == NULL) {
        return NULL;
    }
    data.obj = arg0;
    data.unk4 = ((u8 *)arg0)[0x3B];
    st.unk0 = 2;
    st.unk1 = -1;
    st.unk2 = 3;
    st.unk4 = 0x12C;
    st.unk30 = 9;
    st.unk34 = 0x1AD;
    st.unk39 = 0xFF;
lbl:
    idx = arg0 - gObjects;
    if ((idx < 2) && (D_800E0BCE[idx] != 0)) {
        if (D_8008FD90 == 2) {
            st.unk39 = 0xFD;
        } else if (D_8008FD90 == 4) {
            if (idx == 0) {
                st.unk39 = 0xFB;
            } else {
                st.unk39 = 0xF7;
            }
        }
    }
    st.unk8 = 1;
    st.unkC = 0x200205;
    st.unk10 = 0x60600;
    st.unk24 = 0;
    st.unk25 = 0;
    st.unk14 = 1;
    st.unk18 = 0x36;
    st.unk1C = 0x80;
    st.unk20 = 0x20;
    st.unk38 = 2;
    v0 = func_1513B5E0(&st, 1, 8, arg1, arg2);
    if (v0 != NULL) {
        memcpy(&((struct func_151B9F00_r *)v0)->unkF8[((struct func_151B9F00_r *)v0)->unk50], &data, 8);
    }
    return v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BA084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BA468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BA518.s")

struct func_151BB044_s {
    u8 pad0[0x14];
    f32 x;
    f32 y;
    f32 z;
};
void func_151BB0E0(void);

void func_151BB044(struct func_151BB044_s *arg0) {
    func_1000FA64(0x4A7, (s16) arg0->x, (s16) arg0->y, (s16) arg0->z, 0x2000, 0x320, 0xC8, (s32) func_151BB0E0, (s32) arg0, 0, 8, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BB0E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BB61C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BBA9C.s")

void func_151BBEE4(f32 *arg0, u8 arg1, s32 arg2) {
    Header header;
    Header2 header2;

    header.unk0 = 3;
    header.unk1 = -1;
    header.unk2 = (func_150ADA20() & 0xF) + 5;
    header.unk4 = 0;

    header2.unk0 = arg0[0];
    header2.unk4 = arg0[1];
    header2.unk8 = arg0[2];

    func_151602C0(&header, &header2, (func_150ADA20() % 21U) + 30, 0xFF, 0x61, 0x36, 0xFF, 0, 0, arg1, arg2);
}

void func_150E7FEC(f32 arg0, u8 arg1, s32 arg2, void *arg3, s16 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u8 arg10, s32 arg11);

void func_151BBFBC(s32 arg0, void *arg1, u8 arg2, s32 arg3) {
    s32 pad;
    u32 sp40;
    f32 sp3C;

    sp3C = func_150ADA68();
    sp40 = func_150ADA20();
    func_150E7FEC((sp3C * 75.0f) + 75.0f, (sp40 % 56U) + 0xC8, arg0, arg1, (func_150ADA20() % 205U) + 0x12B, 1, 1, 0, 0, 0, arg2, 0);
}

extern f32 D_800AA760[3];
extern f32 D_800AA76C[3];
extern f32 D_800AA82C;
void func_15160CDC(s32, s32, f32 *, f32 *, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_151BC074(s32 arg0) {
    if (arg0 != 0) {
        func_15160CDC(arg0, 1, D_800AA760, D_800AA76C, D_800AA82C, 2, 0x12C, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0, 0, 0xFF, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC370.s")

struct func_151BC580_s {
    char pad0[0x40];
    s32 *unk40;
};

s32 func_151BC580(struct func_151BC580_s *arg0) {
    s32 *temp_v0 = arg0->unk40;

    if (*temp_v0 == 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC5A4.s")

typedef struct {
    f32 x, y, z;
} func_151BC64C_v3;

struct func_151BC64C_e {
    func_151BC64C_v3 pos;
    s16 unkC;
    u8 unkE;
    u8 padF[5];
};

struct func_151BC64C_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[5];
    u8 unk25;
    u8 pad26[6];
    s8 unk2C;
    s8 unk2D;
    s8 unk2E;
    u8 pad2F[0x25];
    func_151BC64C_v3 unk54;
    u8 pad60[0x34];
    struct func_151BC64C_e *unk94;
};

s32 func_151BC64C(struct func_151BC64C_s *arg0) {
    struct func_151BC64C_e *entries = arg0->unk94;
    struct func_151BC64C_e *e;
    s32 i;
    s32 v;

    if (arg0->unk2C < 2 && (arg0->unk1E & 8)) {
        return 0;
    }
    i = arg0->unk2E;
    while (i != arg0->unk2D) {
        i--;
        if (i < 0) {
            i = arg0->unk25 - 1;
        }
        e = &entries[i];
        e->unkC -= D_800BE9E4;
        if (e->unkC < 0) {
            while (i != arg0->unk2D) {
                arg0->unk2D++;
                if (arg0->unk2D == arg0->unk25) {
                    arg0->unk2D = 0;
                }
                arg0->unk2C--;
            }
        } else if (e->unkC < 10) {
            v = e->unkC * 25;
            if (v < e->unkE) {
                e->unkE = v;
            }
        }
    }
    if (arg0->unk2C > 0) {
        arg0->unk54 = entries[arg0->unk2D].pos;
    } else {
        arg0->unk54.x = 0.0f;
        arg0->unk54.y = 0.0f;
        arg0->unk54.z = 0.0f;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BCA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD21C.s")

struct func_151BD2BC_s2 {
    s32 unk0;
    u8 pad4[0x37];
    u8 unk3B;
};

struct func_151BD2BC_s {
    u8 pad0[0x28];
    struct func_151BD2BC_s2 *unk28;
    u8 unk2C;
};

s32 func_151BD2BC(struct func_151BD2BC_s *arg0) {
    struct func_151BD2BC_s2 *temp = arg0->unk28;

    if (temp->unk0 == 0) {
        return 0;
    }
    if (temp->unk3B != arg0->unk2C) {
        return 0;
    }
    return 1;
}

extern f32 D_800AA850;
void *func_15134DAC();

struct func_151BD2F8_s {
    u8 unk0;
    u8 pad1[3];
    void *unk4;
    s8 unk8;
    u8 pad9[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    s8 unk24;
    u8 pad25;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    u8 pad2C[2];
    s8 unk2E;
    s8 unk2F;
    s8 unk30;
    u8 pad31[3];
    f32 unk34;
    s8 unk38;
    s8 unk39;
    u8 pad3A[2];
};

void func_151BD2F8(void *arg0, s32 arg1, s32 arg2) {
    struct func_151BD2F8_s sp24;
    s16 sp20[2];
    void *temp_v0;

    if (arg0 != NULL) {
        sp24.unk0 = *((u8 *)arg0 + 0x3B);
        sp24.unk4 = arg0;
        sp24.unk8 = 1;
        sp24.unk24 = 0;
        sp24.unk26 = 0x32;
        sp24.unk28 = 0x64;
        sp24.unk2A = 0x12C;
        sp24.unk2E = 4;
        sp24.unk2F = 4;
        sp24.unk30 = 3;
        sp24.unk38 = 5;
        sp24.unk39 = -1;
        sp20[0] = 0;
        sp24.unkC = 31.0f;
        sp24.unk10 = -34.0f;
        sp24.unk14 = -117.0f;
        sp24.unk18 = 35.0f;
        sp24.unk1C = -24.0f;
        sp24.unk20 = -182.0f;
        sp24.unk34 = D_800AA850;
        temp_v0 = func_15134DAC(&sp24, 2);
        if (temp_v0 != NULL) {
            memcpy((char *)temp_v0 + 0x80, sp20, 2);
        }
        sp24.unkC = -sp24.unkC;
        sp24.unk18 = -sp24.unk18;
        temp_v0 = func_15134DAC(&sp24, 2);
        if (temp_v0 != NULL) {
            memcpy((char *)temp_v0 + 0x80, sp20, 2);
        }
    }
}

struct func_151BD42C_s {
    u8 pad[0x80];
    s16 unk80;
};

s32 func_151BD42C(struct func_151BD42C_s *arg0) {
    arg0->unk80 = 0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD43C.s")

extern f32 D_800AA860;
extern f32 D_800AA864;

struct func_151BD750_s {
    u8 pad0[0x80];
    s16 unk80;
};

f32 func_151BD750(struct func_151BD750_s *arg0) {
    f32 ret;

    ret = (f32)arg0->unk80 * 2 * D_800AA860 + D_800AA864;
    arg0->unk80 += D_800BE9E4;
    return ret;
}

struct func_151BD79C_s {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x14 - 0x5];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

void func_1513170C(void *arg0);

void func_151BD79C(void *arg0) {
    struct func_151BD79C_s *temp_v0 = *(struct func_151BD79C_s **)((u8 *)arg0 + 0xB0);

    if (temp_v0->unk0 != 0 && temp_v0->unk4 != 0xFF) {
        *(f32 *)((u8 *)arg0 + 0x4C) = temp_v0->unk14;
        *(f32 *)((u8 *)arg0 + 0x50) = temp_v0->unk18;
        *(f32 *)((u8 *)arg0 + 0x54) = temp_v0->unk1C;
    }
    func_1513170C(arg0);
}

struct func_151BD7F4_s {
    u8 *ptr;
    u8 id;
};

void func_151BD7F4(u8 *arg0) {
    struct func_151BD7F4_s sp18;

    sp18.ptr = arg0;
    sp18.id = arg0[0x3B];
    func_151494E0(&sp18, 0x3B);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BDD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE0AC.s")

struct func_151BE138_s {
    u8 pad0[0x28];
    struct102 *unk28[6];
};

void func_151BE138(struct func_151BE138_s *arg0) {
    struct102 **p = arg0->unk28;

    if (*(s32 *)&arg0->unk28[2] != 0) {
        func_1516972C(arg0->unk28[2]);
    }
    if (p[3] != NULL) {
        func_1516972C(p[3]);
    }
    if (p[4] != NULL) {
        func_1516972C(p[4]);
    }
    if (p[5] != NULL) {
        func_1516972C(p[5]);
    }
}

void func_151BE1B8(s32 arg0) {
    func_151BE138(arg0);
    func_1514933C(arg0);
}

void func_151BE1E4(s32 arg0) {
    func_151BE138(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE210.s")

struct func_151BE4B8_s2 {
    s32 unk0;
    u8 pad4[0x37];
    u8 unk3B;
};

struct func_151BE4B8_s {
    struct func_151BE4B8_s2 *unk0;
    u8 unk4;
    u8 pad5[0x40 - 0x5];
    f32 unk40;
    f32 unk44;
    u8 pad48[0x54 - 0x48];
    f32 unk54;
    u8 unk58;
};

s32 func_151BE4B8(u8 *arg0, s16 arg1) {
    struct func_151BE4B8_s *s;
    f32 sp20[3];

    if (((struct func_151BE4B8_s *)(arg0 + 0x110))->unk0->unk3B != ((struct func_151BE4B8_s *)(arg0 + 0x110))->unk4
        || (s = (struct func_151BE4B8_s *)(arg0 + 0x110), s->unk0->unk0 == 0)) {
        func_1516972C(arg0);
        return 0;
    }
    if (!(s->unk58 & 1)) {
        return 0;
    }
    sp20[0] = s->unk40 * s->unk54;
    sp20[1] = s->unk44 * s->unk54;
    return func_1513FAB4(arg0, 0, sp20, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE558.s")

void func_151BE604(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x110, arg0 + 0x114, arg0);
}

struct func_151BE644_s {
    s32 unk0;
    s32 unk4;
    s32 unk8[1];
};

struct func_151BE644_t {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[0x4A];
    u8 *unk50;
};

void func_151BE644(u8 *arg0) {
    struct func_151BE644_t *temp = (struct func_151BE644_t *)(arg0 + 0x110);
    struct func_151BE644_s *p;

    if (temp->unk50 != NULL) {
        p = (struct func_151BE644_s *)(temp->unk50 + 0x28);
        p->unk8[temp->unk5] = 0;
    }
}

void func_151BE674(s32 arg0) {
    func_151BE644(arg0);
    func_1513CA6C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE6A0.s")

struct func_151BE6CC_s { s32 a[4]; };
struct func_151BE6CC_t { u8 pad0[0x48]; f32 unk48; };
extern struct func_151BE6CC_s D_800AA7A8;
extern f32 D_800AA8AC;

s32 func_151BE6CC(u8 *arg0) {
    struct func_151BE6CC_t *temp = (struct func_151BE6CC_t *)(arg0 + 0x110);
    struct func_151BE6CC_s sp24 = D_800AA7A8;
    s32 pad;

    *(s16 *)(arg0 + 0x170) -= D_800BE9E4;
    if (*(s16 *)(arg0 + 0x170) < 0) {
        arg0[0x18] = sp24.a[func_150ADA20() & 3];
        *(s16 *)(arg0 + 0x170) = (func_150ADA20() & 7) + 3;
    }
    temp->unk48 += (*(f32 *)(arg0 + 0x174) - temp->unk48) * D_800AA8AC;
    return 1;
}

void func_151BE788(s32 arg0, s32 arg1, s32 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x180, arg0 + 0x184, arg0);
}

struct func_151BE7C8_s {
    u8 pad0[0x10];
    s32 unk10[1];
};

struct func_151BE7C8_t {
    u8 pad0[8];
    u8 *unk8;
    u8 unkC;
};

void func_151BE7C8(u8 *arg0) {
    struct func_151BE7C8_t *temp = (struct func_151BE7C8_t *)(arg0 + 0x170);
    struct func_151BE7C8_s *s;

    if (temp->unk8 != NULL) {
        s = (struct func_151BE7C8_s *)(temp->unk8 + 0x28);
        s->unk10[temp->unkC] = 0;
    }
}

void func_151BE7F8(s32 arg0) {
    func_151BE7C8(arg0);
    func_151411A4(arg0);
}

void func_151BE824(s32 arg0) {
    func_151BE7C8(arg0);
    func_151411C4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BEB20.s")

s32 func_151BEC94(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    *arg4 = 1;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BECB8.s")

struct func_151BEE94_s {
    void *unk0;
    u8 unk4;
    u8 pad5[0x127 - 5];
    u8 unk127;
};

s32 func_151BEE94(struct func_151BEE94_s *arg0) {
    if (arg0->unk127 == 0xFF) {
        return 0;
    }
    if (arg0->unk0 == NULL) {
        return 0;
    }
    if (arg0->unk4 == 0xFF) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BEEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BF0C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BF340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BF81C.s")

struct func_151BFB2C_s {
    char pad0[0x28];
    s32 unk28[3];
};

void func_151BFB2C(s32 arg0) {
    struct102 **p;
    s32 i;

    if (((struct func_151BFB2C_s *)arg0)->unk28[0]) {
        func_1516972C(*(struct102 **)((struct func_151BFB2C_s *)arg0)->unk28);
    }
    i = 0;
    p = (struct102 **)((struct func_151BFB2C_s *)arg0)->unk28;
    do {
        if (p[i + 1] != NULL) {
            func_1516972C(p[i + 1]);
        }
        i = (u8)(i + 1);
    } while (i < 2);
}

void func_151BFB2C(s32 arg0);

void func_151BFBA4(s32 arg0) {
    func_151BFB2C(arg0);
    func_1514933C(arg0);
}

void func_151BFBD0(s32 arg0) {
    func_151BFB2C(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BFBFC.s")
