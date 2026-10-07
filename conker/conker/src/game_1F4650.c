#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C71A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C756C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C7E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C82D0.s")

void func_151C8674(s32 arg0, s32 arg1) {
    s32 sp18[2];

    if (arg0 != 0) {
        sp18[0] = arg0;
        sp18[1] = arg1;
        func_151403A8((s32)sp18, 32);
    }
}

s32 func_151C87E0(s32, u8 *);
void func_151C899C(s32, u8 *);

void func_151C86AC(u8 *arg0, s32 *arg1, u8 arg2) {
    u8 *temp_v0 = arg0 + 0x110;

    switch (arg2) {
    case 0x20:
        if ((temp_v0[0x86] & 0x10) && (*(s32 *)(temp_v0 + 0x28) == arg1[1]) && func_151C87E0(arg1[0], arg0) != 0) {
            func_151C899C(arg1[0], arg0);
        }
        break;
    case 0x3A:
        if (*(s32 *)(temp_v0 + 0x28) == arg1[0]) {
            switch (*(u8 *)&arg1[1]) {
            case 0:
                temp_v0[0x86] |= 2;
                break;
            case 1:
                temp_v0[0x86] &= ~2;
                break;
            case 2:
                func_151C899C(0, arg0);
                break;
            }
        }
        break;
    }
}

struct func_151C87AC_s {
    u8 pad0[0x18];
    u8 *unk18;
};

s32 func_151C87AC(struct func_151C87AC_s *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 *arg6) {
    u8 *temp_v0 = arg0->unk18;

    if (!(temp_v0[0x86] & 2)) {
        *arg6 = 0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C87E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C899C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C8FCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C94D4.s")

struct func_151C95D8_s {
    u8 pad0[0x2C];
    struct102 *unk2C;
    u8 pad30[4];
    struct102 *unk34;
    struct102 *unk38;
    struct102 *unk3C;
    struct102 *unk40;
    struct102 *unk44;
    struct102 *unk48;
    struct102 *unk4C;
    struct102 *unk50;
};

struct func_151C95D8_t {
    u8 pad0[0x110];
    struct func_151C95D8_s unk110;
};

extern void func_1000FD38(s32 x, s32 y, s32 z);
s32 func_151C87AC();

void func_151C95D8(struct func_151C95D8_t *arg0) {
    struct func_151C95D8_s *s;

    s = &arg0->unk110;
    if (s->unk2C != NULL) {
        func_1516972C(s->unk2C);
        func_1000FD38((s32)func_151C87AC, (s32)s, 0);
    }
    if (s->unk34 != NULL) func_1516972C(s->unk34);
    if (s->unk38 != NULL) func_1516972C(s->unk38);
    if (s->unk3C != NULL) func_1516972C(s->unk3C);
    if (s->unk40 != NULL) func_1516972C(s->unk40);
    if (s->unk44 != NULL) func_1516972C(s->unk44);
    if (s->unk48 != NULL) func_1516972C(s->unk48);
    if (s->unk4C != NULL) func_1516972C(s->unk4C);
    if (s->unk50 != NULL) func_1516972C(s->unk50);
    func_1513CAA0(arg0);
}

struct func_151C96DC_s {
    u8 pad0[0x170];
    u8 *unk170;
};

s32 func_151C96DC(struct func_151C96DC_s *arg0, s32 arg1) {
    u8 *temp = arg0->unk170 + 0x110;
    s32 ret = 0;

    if (temp[0x86] & 2) {
        return 1;
    }
    return ret;
}

struct func_151C970C_s {
    s32 unk0;
    s8 unk4;
};

void func_151C970C(s32 arg0, s32 arg1) {
    struct func_151C970C_s sp18;

    sp18.unk0 = arg1;
    sp18.unk4 = arg0;
    func_151403A8((s32)&sp18, 0x3A);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9740.s")

struct func_151C9AC0_s {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x180 - 0x20];
    f32 unk180;
};

void func_151ABE40();

void func_151C9AC0(struct func_151C9AC0_s *arg0, u8 arg1, s32 arg2) {
    f32 sp44[3];
    u8 sp20[0x24];

    sp44[0] = arg0->unk14;
    sp44[1] = arg0->unk180 + 2.0f;
    sp44[2] = arg0->unk1C;
    func_1504715C(sp20, arg0);
    func_151ABE40(sp44, sp20, 2, arg1, arg2);
}

struct func_151C9B30_s {
    u8 pad0[0x14];
    u8 *unk14;
    u8 *unk18;
};

s32 func_151C9B30(struct func_151C9B30_s *arg0) {
    u8 *temp_v0 = arg0->unk18;

    if (temp_v0[0x6F] == 0) {
        arg0->unk14[9] = 0;
    } else {
        arg0->unk14[9] = 1;
    }
    return 1;
}

struct func_151C9B64_s {
    u8 pad0[0x58];
    s32 unk58;
    u8 pad5C[0x188 - 0x5C];
    u8 *unk188;
};

s32 func_151C9B64(struct func_151C9B64_s *arg0, u8 *arg1) {
    u8 *temp = arg0->unk188;

    if (temp[0x6F] == 0) {
        *arg1 = 1;
    } else {
        arg0->unk58 &= ~2;
        *arg1 = 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9BA0.s")

void func_151C9F38(s32 arg0, s32 arg1, u8 arg2, s8 arg3, u8 arg4);
void func_151CC524(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5);
void func_151CC840(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5);
void func_151CCF08(s32 arg0, u8 arg1, s8 arg2, u8 arg3);
void func_150BDE90(s32 arg0, u8 arg1, s32 arg2);
void func_151CB5FC(s32 arg0, s32 arg1, u8 arg2, s8 arg3, u8 arg4);

void func_151C9DE8(s32 arg0, u8 arg1, s8 arg2, u8 arg3, s32 arg4) {
    func_151C9F38(arg0, 4, arg1, arg2, arg3);
    func_151CC524(arg0, 0, 0x32, 0xFF, arg1, arg3);
    func_151CC840(arg0, 0, 0x32, 0xFF, arg1, arg3);
    func_151CCF08(arg0, arg1, arg2, arg3);
    func_150BDE90(arg0, arg3, arg4);
    func_151CB5FC(arg0, 2, arg1, arg2, arg3);
    if (D_800BE9F0 == 0x27) {
        D_8008CD00 = 1;
    }
}

void func_15160274(s32 arg0, s32 arg1);
void func_1515572C(s32 arg0, s32 arg1);
void func_151A561C(s32 arg0, s32 arg1);

void func_151C9ED4(s32 arg0) {
    s32 sp24;

    sp24 = arg0;
    arg0 = (s32)&sp24;
    func_15160274(arg0, 0x21);
    func_1515572C(arg0, 0x21);
    func_151A561C(arg0, 0x21);
    func_151494E0(arg0, 0x21);
    D_8008CD00 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CA6A0.s")

struct func_151CAACC_s {
    u8 pad0[0x70];
    s32 unk70;
    u8 pad74[0x7D - 0x74];
    u8 unk7D;
};

extern void (*D_8008FC10[])(struct func_151CAACC_s *, s32 *, u8);

void func_151CAACC(struct func_151CAACC_s *arg0, s32 *arg1, u8 arg2) {
    s32 temp_v0;

    if (arg2 == 0x21) {
        if (arg0->unk70 == *arg1) {
            func_1516972C((struct102 *) arg0);
            goto block_end; // splits the block so IDO fills the b delay slot from the target
        block_end:;
        }
    } else if (arg2 == 0) {
        temp_v0 = *arg1;
        if (arg0->unk70 == *(s32 *)(temp_v0 + 0x318)) {
            func_1516972C((struct102 *) arg0);
        }
    }
    if (D_8008FC10[arg0->unk7D]) {
        D_8008FC10[arg0->unk7D](arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CAB78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CAD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB110.s")

struct func_151CB49C_s {
    u8 pad0[0x18];
    s32 unk18;
};

void func_151CB49C(struct func_151CB49C_s *arg0, s32 *arg1, u8 arg2) {
    s32 temp_v0;

    if (arg2 == 0x21) {
        if (arg0->unk18 == *arg1) {
            func_1516972C((struct102 *) arg0);
        }
    } else if (arg2 == 0) {
        temp_v0 = *arg1;
        if (arg0->unk18 == *(s32 *) (temp_v0 + 0x318)) {
            func_1516972C((struct102 *) arg0);
        }
    }
}

extern f32 D_800AAEA8;

struct func_151CB510_s2 {
    u8 *unk0;
    f32 unk4;
    f32 unk8;
};

struct func_151CB510_s {
    u8 pad0[0x2E];
    u8 unk2E;
    u8 pad2F[0x70 - 0x2F];
    struct func_151CB510_s2 unk70;
};

void func_151CB510(struct func_151CB510_s *arg0) {
    f32 var_f0;
    struct func_151CB510_s2 *s;

    if ((**(u16 **)(arg0->unk70.unk0 + 0x36C) & 0x2000) &&
        (s = &arg0->unk70, *(u16 *)(*(u8 **)(arg0->unk70.unk0 + 0x3D4) + 0x19E) == 0)) {
        var_f0 = s->unk8;
    } else {
        var_f0 = 0.0f;
        s = &arg0->unk70;
    }
    s->unk4 += (var_f0 - s->unk4) * D_800AAEA8;
    arg0->unk2E = s->unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB5FC.s")

struct func_151CB918_s {
    s32 unk0;
    u8 pad4[8];
    u8 unkC;
    u8 padD;
    u8 unkE;
    u8 padF;
    f32 unk10;
    f32 unk14;
};

struct func_151CB918_s0 {
    u8 pad0[0x70];
    struct func_151CB918_s unk70;
};

typedef struct {
    u8 unk0;
    s32 unk4;
} func_151CB918_arg1;

void func_151CB918(struct func_151CB918_s0 *arg0, func_151CB918_arg1 *arg1, u8 arg2) {
    struct func_151CB918_s *temp_v0 = &arg0->unk70;

    if ((arg2 == 0x37) && (temp_v0->unkE == arg1->unk0) && (temp_v0->unk0 == arg1->unk4)) {
        temp_v0->unk10 = 0.0f;
        temp_v0->unkC |= 1;
        temp_v0->unk14 = 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB970.s")

struct func_151CBB6C_s {
    u8 pad0[0x20];
    s32 unk20;
    u8 pad24[0x318 - 0x24];
    s32 unk318;
};

void func_151CBB6C(struct func_151CBB6C_s *arg0, struct func_151CBB6C_s **arg1, u8 arg2) {
    struct func_151CBB6C_s *temp;

    if (arg2 == 0x21) {
        if (arg0->unk20 == (s32) arg1[0]) {
            func_1516972C((struct102 *) arg0);
        }
    } else if (arg2 == 0) {
        temp = arg1[0];
        if (temp->unk318 == arg0->unk20) {
            func_1516972C((struct102 *) arg0);
        }
    }
}

struct func_151CBBE0_sub {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
};

struct func_151CBBE0_s {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    u8 pad18[0x70 - 0x18];
    struct func_151CBBE0_sub unk70;
};

extern f32 D_800AAEB8;
f32 func_151CC1D4(struct func_151CBBE0_s *arg0);
void func_1514373C(f32, f32, s32 *, s32 *);

s32 func_151CBBE0(struct func_151CBBE0_s *arg0) {
    f32 temp_f0;
    f32 temp;
    struct func_151CBBE0_sub *sub;

    sub = &arg0->unk70;
    temp_f0 = func_151CC1D4(arg0);
    if (sub->unk28 != temp_f0) {
        sub->unk28 = temp_f0;
        temp = (temp_f0 - sub->unk18) * sub->unk20 * D_800AAEB8;
        func_1514373C(sub->unk24 + temp, 55.0f, &arg0->unk10, &arg0->unk14);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CBC60.s")

struct func_151CC1D4_obj {
    u8 pad0[0x19C];
    f32 unk19C;
    f32 unk1A0;
};

struct func_151CC1D4_sub {
    struct func_151CC1D4_obj *unk0;
    u8 pad4[0x8];
    u8 unkC;
    u8 padD[0x18 - 0xD];
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x54 - 0x20];
    s8 unk54;
};

struct func_151CC1D4_s {
    u8 pad0[0x70];
    struct func_151CC1D4_sub unk70;
};

extern f32 D_800AAEC0;

f32 func_151CC1D4(struct func_151CBBE0_s *arg0) {
    struct func_151CC1D4_sub *sub;
    f32 val;
    f32 t;

    sub = &((struct func_151CC1D4_s *) arg0)->unk70;
    if (((struct func_151CC1D4_s *) arg0)->unk70.unkC & 4) {
        t = D_800C3958[sub->unk54].unk28 * D_800AAEC0;
        val = sub->unk18 + (sub->unk1C - sub->unk18) * t;
    lbl:;

    } else {
        val = (sub->unk0->unk19C + sub->unk0->unk1A0) * 0.5f;
    }
    if (val < sub->unk18) {
        val = sub->unk18;
    } else if (sub->unk1C < val) {
        val = sub->unk1C;
    }

    return val;
}

void func_1515572C();

void func_151CC290(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    func_1515572C(&sp1C, 0x46);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC2BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC524.s")

extern f32 D_800AAED4;
extern f32 D_800AAED8;
void func_15145974(void *arg0, f32 *arg1, f32 *arg2);

struct func_151CC77C_s {
    u8 pad0[0x20];
    u8 unk20;
    u8 pad21[0x60 - 0x21];
    f32 unk60;
    f32 unk64;
    u8 pad68[0x70 - 0x68];
    u8 *unk70;
};

s32 func_151CC77C(struct func_151CC77C_s *arg0) {
    u8 *temp_v0;
    u8 *temp_v1;
    f32 sp20[4];
    f32 temp1;
    f32 temp2;

    temp_v0 = arg0->unk70;
    temp_v1 = *(u8 **)(temp_v0 + 0x3D0);
    if (temp_v1 == NULL) {
        return 0;
    }
    temp_v0 = *(u8 **)(temp_v1 + 0x31C);
    if (temp_v0 == NULL) {
        return 0;
    }
    func_15145974(temp_v0 + 0x130, &sp20[1], &sp20[0]);
    if (arg0->unk20 == 0x9A) {
        temp1 = -(sp20[1] * D_800AAED4 * 2560.0f);
        arg0->unk60 = temp1 + temp1;
    } else {
        temp2 = sp20[0] * D_800AAED8 * 2560.0f;
        arg0->unk64 = temp2 + temp2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CCD1C.s")

void *func_151A4FD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void *memcpy(void *, const void *, size_t);

void func_151CCE94(u8 *arg0) {
    u8 *temp_v0;
    u8 *sp28;

    if (D_800BE616 != 0) {
        sp28 = arg0;
        temp_v0 = func_151A4FD0(0, 0, 0, 0xFF, 0, arg0[0x23D], 1, 4);
        if (temp_v0 != NULL) {
            memcpy(temp_v0 + 0x20, &sp28, 4);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CCF08.s")

struct func_151CD224_sub {
    u8 pad0[0xD];
    u8 unkD;
    u8 padE[0x18 - 0xE];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

struct func_151CD224_s {
    u8 pad0[0x14];
    f32 unk14;
    u8 pad18[0x70 - 0x18];
    struct func_151CD224_sub unk70;
};

void func_151CD224(struct func_151CD224_s *arg0) {
    f32 temp_f0;
    f32 temp;
    struct func_151CD224_sub *sub;

    sub = &arg0->unk70;
    temp_f0 = func_151CC1D4((struct func_151CBBE0_s *) arg0);
    temp = (1.0f - (temp_f0 - sub->unk18) * sub->unk20) * 75.0f;
    if (sub->unkD == 5) {
        arg0->unk14 = 92.0f + temp;
    } else if (sub->unkD == 4) {
        arg0->unk14 = -92.0f - temp;
    }
}
