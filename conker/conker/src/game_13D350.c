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

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151103C8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_1511473C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114D24.s")

void func_15114CC4();
void func_1001001C();

void func_15114F04(s32 arg0, s32 arg1, s32 arg2) {
    func_1001001C(func_15114CC4, arg0, 0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114F44.s")
