#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_1510FEA0.s")

void func_150A7A48(s32, void *, s32);

void func_151102CC(s32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    f32 sp28[16];

    func_150A8050((void *)arg0, 0.0f, arg2, 0.0f);
    func_150A8050(sp28, arg1, 0.0f, 0.0f);
    func_150A7A48(arg0, sp28, arg0);
    func_150A8050(sp28, 0.0f, 0.0f, *(f32 *)&arg3);
    func_150A7A48(arg0, sp28, arg0);
}

void func_151102CC(s32, f32, f32, s32);
void func_150A7A48(s32, void *, s32);

void func_15110360(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    func_151102CC(arg1, arg2, arg3, arg4);
    func_150A7A48(arg1, (u8 *)D_800BE628 + arg0 * 0x180 + 0xBC, arg1);
}

struct func_151103C8_s {
    u8  unk0[0x24];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    u8  unk34[0x14C];
};

extern u8 D_800DBEA8[];
s32 func_15110544(s32, s32, s32, s32, s32, s32, s32, s32);
Gfx *func_1501A6CC(Gfx *arg0, s32 a, s32 b, s32 c, s32 d);

Gfx *func_151103C8(Gfx *gfx, s32 arg1, s32 arg2, s32 arg3) {
    struct func_151103C8_s *cam;
    s32 half;
    s32 half2;

    cam = &((struct func_151103C8_s *)D_800BE628)[D_80082FA4];
    gfx = (Gfx *)func_15110544((s32)gfx, (s32)cam->unk2C, (s32)cam->unk24, (s32)(cam->unk30 - 1.0f), (s32)cam->unk28,
                               D_800DBEA8[0], D_800DBEA8[1], D_800DBEA8[2]);
    if (D_80082FA0 != 0 && D_80082FA4 == 0) {
        gDPPipeSync(gfx++);
        gfx = (Gfx *)func_1501A490(gfx, 0xFF, 0, 0, 0, 0);
        gDPSetFillColor(gfx++, 0x10001);
        gfx = func_1501A6CC(gfx, 0, (half = D_800BE624 >> 1) - 6, D_800BE620, half + 6);
        if (D_80082FA0 != 1) {
            gfx = func_1501A6CC(gfx, (half2 = D_800BE620 >> 1) - 1, 0, half2 + 1, D_800BE624);
        }
    }
    return gfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15110544.s")

extern u8 D_800DBEA8[];
s32 func_15110544(s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_15110600(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if ((D_800BE9F0 == 0x1B) || (D_800BE9F0 == 0x1E) ||
        ((D_800BE9F0 == 0x31) && (*(u8 *)&D_800DBFF0->unk3D4->unk78 == 3))) {
        arg0 = func_15110544(arg0, 2, 0, D_800BE620 - 2, D_800BE624, D_800DBEA8[0], D_800DBEA8[1], D_800DBEA8[2]);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151106A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151108C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15110CFC.s")

extern void *D_800DBE80;
extern s32 *D_800891BC[];
void func_10004074(s32);
void func_15111858(void);
void func_1510D694(s32);

void func_1511172C(s32 arg0) {
    s32 i;

    if (arg0 == 1) {
        D_800B0DF0->unk8 = 1;
        if (D_800DBE80 != 0) {
            func_10004074((s32)D_800DBE80);
        }
        func_15111858();
        return;
    }
    if (arg0 != D_800B0DF0->unk9) {
        if (D_800B0DF0->unk8 == 4) {
            if (D_80038080 != 0) {
                for (i = 0; i < 360; i++) {
                    func_1510D694(*D_800891BC[D_800B0DF0->unk9] + i);
                }
            }
            func_10004074((s32)D_800DBE80);
            D_800B0DF0->unk9 = arg0;
            func_1502B7F0(&D_800DBE80, 2, 0xD, D_800B0DF0->unk9);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15111858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15111AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15112520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15112A80.s")

struct func_15113180_s {
    u8 pad0[0x38];
    s32 unk38;
    u8 pad3C[0x33];
    u8 unk6F;
    u8 unk70;
    u8 pad71[0x2F];
};

void func_15113180(void) {
    s32 i;

    for (i = 0; i < D_800DBEF0; i++) {
        ((struct func_15113180_s *)D_800DBEF4)[i].unk6F &= ~0x40;
        if ((((struct func_15113180_s *)D_800DBEF4)[i].unk6F & 0xF) || ((((struct func_15113180_s *)D_800DBEF4)[i].unk70 & 4) == 4)) {
            if (((struct func_15113180_s *)D_800DBEF4)[i].unk38 != 0) {
                ((struct func_15113180_s *)D_800DBEF4)[i].unk6F |= 0x40;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151135C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151137D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113E54.s")

extern s32 *D_800DBF94;

s32 func_15114050(struct131 *arg0, s32 arg1) {
    if ((u8)arg0->unk4F & 0x80) {
        if (arg1 == -1) {
            return 1;
        }
        if (D_800DBF94[arg0 - D_800DBEF4] & (1 << arg1)) {
            return 1;
        }
    }
    return 0;
}

s32 func_151140C4(struct131 *arg0) {
    s32 i = 0;

    if ((u8)arg0->unk4F & 0x80) {
        for (; i < 32; i++) {
            if (D_800DBF94[arg0 - D_800DBEF4] & (1 << i)) {
                return i;
            }
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114348.s")

extern f32 D_800A2F60;
extern u16 D_800CBDA0[];
void func_15114348(s32, f32 *, f32 *, f32 *);

void func_1511473C(struct127 *arg0, s32 arg1) {
    if (arg0 == NULL) {
        return;
    }
    if (arg1 >= D_800DBEF0) {
        return;
    }
    func_15114348(arg1, &arg0->x_position, &arg0->y_position, &arg0->z_position);
    arg0->unk76 += *(f32 *)((u8 *)&D_800DBEF4[arg1] + 0x64) * D_800A2F60;
    if (*((u8 *)arg0 + 0x137) && (arg1 + 1) == D_800CBDA0[arg0 - gObjects]) {
        arg0->unk7A = arg0->unk76;
    }
}

void func_151148A8(void *arg0, f32 *arg1) {
    f32 sp18[16];

    func_150A8050(arg0, 0.0f, arg1[1], 0.0f);
    func_150A8050(sp18, arg1[0], 0.0f, arg1[2]);
    func_150A7A48(sp18, arg0, arg0);
}

struct func_1511490C_s {
    u8 pad0[0x10];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[2];
    f32 unk18;
    u8 pad1C[0x10];
    s32 unk2C;
    s32 unk30;
    s32 unk34;
};

void func_1511490C(f32 *arg0, struct func_1511490C_s *arg1) {
    f32 sp20[16];

    func_151148A8(arg0, arg1);
    arg0[12] = arg1->unk10;
    arg0[13] = arg1->unk12 + arg1->unk18;
    arg0[14] = arg1->unk14;
    func_150A7CB0(sp20, arg1->unk2C, arg1->unk30, arg1->unk34);
    func_150A7A48(sp20, arg0, arg0);
}

struct131 *func_151149AC(u8 arg0) {
    s32 i;

    if (arg0 == 0) {
        return NULL;
    }
    for (i = 0; i < D_800DBEF0; i++) {
        if (arg0 == D_800DBEF4[i].pad70[2]) {
            return &D_800DBEF4[i];
        }
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114A1C.s")

struct func_15114B94_s {
    u8 pad0[0x6E];
    u8 unk6E;
    u8 pad6F;
    u8 unk70;
    u8 pad71[0x23];
    struct102 *unk94;
    u8 pad98[0x8];
};

extern s32 D_800DBF98;

void func_15114B94(u32 arg0) {
    u32 n;

    if (arg0 < D_800DBEF0) {
        if (((struct func_15114B94_s *)D_800DBEF4)[arg0].unk94 != NULL) {
            func_1516972C(((struct func_15114B94_s *)D_800DBEF4)[arg0].unk94);
            ((struct func_15114B94_s *)D_800DBEF4)[arg0].unk94 = NULL;
        }
        ((struct func_15114B94_s *)D_800DBEF4)[arg0].unk70 |= 8;
        ((struct func_15114B94_s *)D_800DBEF4)[arg0].unk6E = 1;
    }
    n = D_800DBEF0 - D_800DBF98;
    arg0 = D_800DBEF0 - 1;
    if (D_800DBEF0 != 0) {
        while (((struct func_15114B94_s *)D_800DBEF4)[arg0].unk70 & 8) {
            if (arg0 >= n && D_800DBF98 != 0) {
                D_800DBF98--;
            } else {
                n--;
            }
            D_800DBEF0--;
            arg0--;
            if (D_800DBEF0 == 0) {
                return;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114D24.s")

void func_15114CC4();
void func_1001001C();

void func_15114F04(s32 arg0, s32 arg1, s32 arg2) {
    func_1001001C(func_15114CC4, arg0, 0, arg1, arg2);
}

extern s32 D_800DBF9C;
extern s32 D_800DBFA0;
extern s32 D_800DBFA4;

struct func_15114F44_s {
    u32 a;
    u32 b;
    u32 c;
};

void func_15114F44(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 j;
    struct func_15114F44_s *p;

    if ((D_800BE9F0 == 0x12) || (D_800BE9F0 == 0x36) || (D_800BE9F0 == 0x13)) {
        for (i = 0; i < 2; i++) {
            p = (struct func_15114F44_s *)D_800DBDD8[i];
            for (j = 0; j < D_800DBE18[i]; j++) {
                if (((p[j].a & 0xF0000000) != 0x80000000) || ((p[j].b & 0xF0000000) != 0x80000000) ||
                    ((p[j].c & 0xF0000000) != 0x80000000) || (p[j].a & 3) || (p[j].b & 3) || (p[j].c & 3)) {
                    D_8003C8E0 = 0xC00005A;
                    func_150AD770();
                }
            }
        }
        D_800DBF9C = arg0;
        D_800DBFA0 = arg1;
        D_800DBFA4 = arg2;
    }
}
