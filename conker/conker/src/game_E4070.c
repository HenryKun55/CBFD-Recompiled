#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6C90.s")

struct func_150B6D34_s {
    u8 pad[0x20];
    s32 unk20;
};
extern struct func_150B6D34_s *D_800D9898[];

void func_150B6D34(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_800D9898[i + 5] != NULL) {
            D_800D9898[i + 5]->unk20 = 1;
        }
    }
    D_800D9890 = 3;
}

extern struct102 *D_800D9894;

void func_150B6D78(void) {
    s32 i;

    if (D_800D9894 != NULL) {
        func_1516972C(D_800D9894);
        D_800D9894 = NULL;
    }
    for (i = 0; i < 10; i++) {
        if (D_800D9898[i] != NULL) {
            func_1516972C((struct102 *)D_800D9898[i]);
            D_800D9898[i] = NULL;
        }
    }
    D_800D9890 = 3;
}

struct func_150B6DFC_s {
    u8 pad0[0x34];
    s16 unk34;
};

void func_150B6DFC(struct func_150B6DFC_s *arg0) {
    arg0->unk34 += D_800BE9E4 * 48;
    if (arg0->unk34 > 0x800) {
        arg0->unk34 = -0xC00;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6E3C.s")

struct func_150B709C_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x2C - 0x1C];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x45 - 0x34];
    u8 unk45;
};

void func_150B709C(struct func_150B709C_s *arg0) {
    s32 v;
    s32 temp;

    v = arg0->unk18;
    if (v == 30) {
        temp = arg0->unk45;
        temp += D_800BE9E4 * 8;
        if (temp >= 256) {
            temp = 0;
        }
        arg0->unk45 = temp;
    }
    v += D_800BE9E4 * 2;
    if (v > 30) {
        v = 30;
    }
    arg0->unk18 = v;
    arg0->unk2C = (v * -84) / 30 + 230;
    arg0->unk30 = (v * -50) / 30 + 170;
}

struct func_150B71A8_s {
    u8 pad0[0x38];
    s16 unk38;
    s16 unk3A;
};

void func_150B71A8(struct func_150B71A8_s *arg0) {
    if (arg0->unk38 != 0x1000) {
        arg0->unk38 += D_800BE9E4 << 8;
        if (arg0->unk38 > 0x1000) {
            arg0->unk38 = 0x1000;
        }
    } else if (arg0->unk3A != 0x1000) {
        arg0->unk3A += D_800BE9E4 << 8;
        if (arg0->unk3A > 0x1000) {
            arg0->unk3A = 0x1000;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7220.s")

struct func_150B73F0_s {
    u8 pad0[0x18];
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8 pad26[0x6];
    f32 unk2C;
    f32 unk30;
};

void func_150B73F0(struct func_150B73F0_s *arg0) {
    s32 x0 = arg0->unk18;
    s32 y0 = arg0->unk1A;
    s32 x1 = arg0->unk20;
    s32 y1 = arg0->unk22;
    s32 d = arg0->unk1C;
    s32 n = arg0->unk24;
    u32 t = (n << 16) / d;
    arg0->unk2C = ((s32)((x1 - x0) * t) >> 16) + x0;
    arg0->unk30 = ((s32)((y1 - y0) * t) >> 16) + y0;
}

extern u8 D_800918DC[];
void *func_15169968();

struct func_150B7484_s {
    void *unk0;
    u8 pad4[0x10];
    s16 unk14;
    s16 unk16;
    s16 unk18;
    f32 unk1C;
    f32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 unk39;
};

void func_150B7484(void) {
    struct func_150B7484_s sp1C;

    sp1C.unk31 = 1;
    sp1C.unk2C = 0x58;
    sp1C.unk1C = 60.0f;
    sp1C.unk20 = 60.0f;
    sp1C.unk14 = 0;
    sp1C.unk16 = 0;
    sp1C.unk18 = 0;
    sp1C.unk2E = 0x58;
    sp1C.unk30 = 6;
    sp1C.unk0 = D_800918DC;
    sp1C.unk32 = 0xFF;
    sp1C.unk33 = 0;
    sp1C.unk34 = 0;
    sp1C.unk35 = 0xFF;
    sp1C.unk24 = 0;
    sp1C.unk26 = 0;
    sp1C.unk39 = 0;
    sp1C.unk36 = 7;
    sp1C.unk37 = 0x15;
    sp1C.unk38 = 1;
    sp1C.unk28 = 0x51;
    sp1C.unk2A = 0x51;
    if (D_800D9898[0] != NULL) {
        func_1516972C((struct102 *)D_800D9898[0]);
    }
    D_800D9898[0] = func_15169968(&sp1C);
    D_800D9890 = 3;
}

struct func_150B7560_s {
    void *unk0;
    u8 pad4[0x10];
    s16 unk14;
    s16 unk16;
    s16 unk18;
    f32 unk1C;
    f32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 unk39;
};

extern u8 D_800918DC[];
extern struct102 *D_800D98A4;
void *func_15169968(struct func_150B7560_s *arg0);

void func_150B7560(void) {
    struct func_150B7560_s sp1C;

    if (D_800D9898[0] != NULL) {
        func_1516972C((struct102 *)D_800D9898[0]);
        D_800D9898[0] = NULL;
    }
    sp1C.unk18 = 0x4D;
    sp1C.unk31 = 0xF;
    sp1C.unk14 = 0;
    sp1C.unk16 = 0;
    sp1C.unk2C = 0x58;
    sp1C.unk2E = 0x58;
    sp1C.unk30 = 0;
    sp1C.unk0 = D_800918DC;
    sp1C.unk24 = 0;
    sp1C.unk26 = 0;
    sp1C.unk32 = 0xFF;
    sp1C.unk33 = 0;
    sp1C.unk34 = 0;
    sp1C.unk35 = 0xFF;
    sp1C.unk36 = 7;
    sp1C.unk37 = 0x11;
    sp1C.unk38 = 1;
    sp1C.unk39 = 0;
    sp1C.unk28 = 0x1000;
    sp1C.unk2A = 0x1000;
    sp1C.unk1C = 60.0f;
    sp1C.unk20 = 60.0f;
    if (D_800D98A4 != NULL) {
        func_1516972C(D_800D98A4);
    }
    D_800D98A4 = func_15169968(&sp1C);
    D_800D9890 = 3;
}

void func_150B76BC(s32, s32);

void func_150B765C(void) {
    func_150B76BC(0x3C, 1);
    D_800D9890 = 3;
}

void func_150B76BC(s32 arg0, s32 arg1);

void func_150B768C(void) {
    func_150B76BC(0xE6, 2);
    D_800D9890 = 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B76BC.s")

struct func_150B77A8_s {
    void *unk0;
    void *unk4;
    u8 pad8[0xC];
    s16 unk14;
    s16 unk16;
    s16 unk18;
    f32 unk1C;
    f32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 unk39;
};

extern u8 D_800918F4[];
extern u8 D_80091900[];
extern u8 D_800918E8[];

void func_150B77A8(void) {
    struct func_150B77A8_s sp24;

    if (D_800D9898[1] != NULL) {
        func_1516972C((struct102 *)D_800D9898[1]);
        D_800D9898[1] = NULL;
    }
    sp24.unk1C = 60.0f;
    sp24.unk20 = 170.0f;
    sp24.unk2C = 0x40;
    sp24.unk2E = 0x40;
    sp24.unk30 = 4;
    sp24.unk0 = D_800918F4;
    sp24.unk4 = D_80091900;
    sp24.unk14 = 0;
    sp24.unk16 = 0;
    sp24.unk18 = 0;
    sp24.unk31 = 0;
    sp24.unk24 = -0x800;
    sp24.unk26 = 9;
    sp24.unk32 = 0xFF;
    sp24.unk33 = 0;
    sp24.unk34 = 0;
    sp24.unk35 = 0xFF;
    sp24.unk36 = 0xD;
    sp24.unk37 = 0x12;
    sp24.unk38 = 2;
    sp24.unk39 = 3;
    sp24.unk28 = 0x1000;
    sp24.unk2A = 0x1000;
    if (D_800D9898[4] != NULL) {
        func_1516972C((struct102 *)D_800D9898[4]);
    }
    D_800D9898[4] = func_15169968((struct func_150B7560_s *)&sp24);
    sp24.unk24 = 0;
    sp24.unk26 = 0;
    sp24.unk2C = 0x58;
    sp24.unk2E = 0x40;
    sp24.unk30 = 0;
    sp24.unk36 = 7;
    sp24.unk37 = 0x11;
    sp24.unk0 = D_800918E8;
    sp24.unk38 = 1;
    if (D_800D9898[8] != NULL) {
        func_1516972C((struct102 *)D_800D9898[8]);
    }
    D_800D9898[8] = func_15169968((struct func_150B7560_s *)&sp24);
    D_800D9890 = 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B791C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B82D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B85C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B879C.s")
