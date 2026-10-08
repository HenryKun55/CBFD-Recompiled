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

struct func_150B7220_s {
    void *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
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
    u8 unk3A;
    u8 unk3B;
};
extern u8 D_80091924[];
void func_15169900(struct func_150B7220_s *, s32);

void func_150B7220(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct func_150B7220_s sp44;
    s32 r;
    s32 px;
    s32 py;


    sp44.unk0 = D_80091924;
    sp44.unk8 = (arg0 << 16) | (arg1 & 0xFFFF);
    sp44.unk28 = 0x1000;
    sp44.unk2A = 0x1000;
    sp44.unkC = arg2;
    sp44.unk14 = arg2;
    sp44.unk18 = 0;
    sp44.unk24 = 0;
    sp44.unk26 = 0;
    sp44.unk2C = 0x10;
    sp44.unk2E = 0x10;
    sp44.unk30 = 7;
    sp44.unk31 = 2;
    sp44.unk32 = 0xFF;
    sp44.unk33 = 0;
    sp44.unk34 = 0;
    sp44.unk35 = 0xFF;
    sp44.unk36 = 7;
    sp44.unk37 = 0x11;
    if (arg0 < (D_800BE638 >> 1)) {
        r = D_800BE638 - arg0;
    } else {
        r = arg0;
    }
    px = arg0;
    py = arg1 - r;
    sp44.unk10 = (px << 16) | (py & 0xFFFF);
    sp44.unk39 = 0;
    sp44.unk16 = 0;
    sp44.unk1C = px;
    sp44.unk20 = py;
    func_15169900(&sp44, arg3);
    py = arg1 + r;
    sp44.unk10 = (px << 16) | (py & 0xFFFF);
    sp44.unk39 = 8;
    sp44.unk20 = py;
    func_15169900(&sp44, arg3);
    px = arg0 - r;
    py = arg1;
    sp44.unk1C = px;
    sp44.unk10 = (px << 16) | (py & 0xFFFF);
    sp44.unk39 = 4;
    sp44.unk16 = 0x100;
    sp44.unk20 = py;
    func_15169900(&sp44, arg3);
    px = arg0 + r;
    sp44.unk10 = (px << 16) | (py & 0xFFFF);
    sp44.unk39 = 0;
    sp44.unk1C = px;
    func_15169900(&sp44, arg3);
}

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

struct func_150B791C_s {
    void *unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
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

extern u8 D_8009190C[];

void func_150B791C(void) {
    struct func_150B791C_s sp24;

    if (D_800D9898[2] != NULL) {
        func_1516972C((struct102 *)D_800D9898[2]);
        D_800D9898[2] = NULL;
    }
    sp24.unk20 = 150.0f;
    sp24.unk1C = 230.0f;
    sp24.unk31 = 3;
    sp24.unk2C = 0x40;
    sp24.unk2E = 0x10;
    sp24.unk30 = 5;
    sp24.unk24 = 0;
    sp24.unk26 = 0;
    sp24.unk14 = 0;
    sp24.unk16 = 0;
    sp24.unk18 = 0;
    sp24.unk0 = D_8009190C;
    sp24.unk4 = NULL;
    sp24.unk8 = 0;
    sp24.unkC = sp24.unk20;
    sp24.unk10 = 0;
    sp24.unk32 = 0xFF;
    sp24.unk33 = 0;
    sp24.unk34 = 0;
    sp24.unk35 = 0x80;
    sp24.unk36 = 7;
    sp24.unk37 = 0x11;
    sp24.unk38 = 1;
    sp24.unk39 = 0;
    sp24.unk28 = 0x1000;
    sp24.unk2A = 0x1000;
    if (D_800D9898[5] != NULL) {
        func_1516972C((struct102 *)D_800D9898[5]);
    }
    D_800D9898[5] = func_15169968((struct func_150B7560_s *)&sp24);
    sp24.unk20 = 170.0f;
    sp24.unk16 = 0x100;
    sp24.unk8 = 0x100;
    sp24.unkC = sp24.unk20;
    sp24.unk35 = 0xFF;
    if (D_800D9898[6] != NULL) {
        func_1516972C((struct102 *)D_800D9898[5]);
    }
    D_800D9898[6] = func_15169968((struct func_150B7560_s *)&sp24);
    sp24.unk20 = 190.0f;
    sp24.unk16 = 0x200;
    sp24.unk8 = 0x200;
    sp24.unkC = sp24.unk20;
    sp24.unk35 = 0x80;
    if (D_800D9898[7] != NULL) {
        func_1516972C((struct102 *)D_800D9898[5]);
    }
    D_800D9898[7] = func_15169968((struct func_150B7560_s *)&sp24);
    sp24.unk14 = 0;
    sp24.unk16 = 0;
    sp24.unk18 = 0;
    sp24.unk31 = 0;
    sp24.unk2C = 0x58;
    sp24.unk2E = 0x40;
    sp24.unk35 = 0xFF;
    sp24.unk30 = 0;
    sp24.unk0 = D_800918E8;
    sp24.unk1C = 230.0f;
    sp24.unk20 = 170.0f;
    if (D_800D9898[9] != NULL) {
        func_1516972C((struct102 *)D_800D9898[9]);
    }
    D_800D9898[9] = func_15169968((struct func_150B7560_s *)&sp24);
    D_800D9890 = 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B82D0.s")

s32 func_15130374();
extern f32 D_8009FD88;

struct func_150B85C0_s {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    vertex unk30;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60;
    u8 unk61;
    s8 unk62;
    s8 unk63;
    s8 unk64;
    s8 unk65;
    u8 pad66[8];
};

void func_150B85C0(vertex *arg0, f32 *arg1, f32 *arg2, u8 arg3, s32 arg4) {
    struct func_150B85C0_s sp28;
    s32 var_v0;
    s32 var_v1;

    sp28.unk1D = 0x29;
    sp28.unk8 = 0xE03;
    sp28.unk0 = 0x200005;
    sp28.unk4 = 0;
    sp28.unkA = (func_150ADA20() % 11U) + 0x23;
    sp28.unkC = 0;
    sp28.unk10 = 0;
    sp28.unk18 = 0xB0;
    sp28.unk19 = 0xA0;
    sp28.unk1A = 0x2A;
    sp28.unk14 = 0x40;
    sp28.unk15 = 0xB;
    sp28.unk16 = 0x6A;
    sp28.unk17 = 0xFF;
    sp28.unk1B = (func_150ADA20() % 51U) + 0x64;
    sp28.unk1C = 0xFF;
    sp28.unk60 = 3;
    sp28.unk61 = 3;
    sp28.unk28 = *arg2 * 20.0f;
    sp28.unk2C = *arg1 * 20.0f;
    sp28.unk30 = *arg0;
    sp28.unk3C = 0.0f;
    sp28.unk40 = 0.0f;
    sp28.unk44 = 0.0f;
    sp28.unk48 = 0.0f;
    sp28.unk4C = 0.0f;
    sp28.unk50 = 0.0f;
    sp28.unk54 = 0.0f;
    var_v1 = (func_150ADA20() & 1) ? 0x40 : 0;
    if (func_150ADA20() & 1) {
        var_v0 = 0x80;
    } else {
        var_v0 = 0;
    }
    sp28.unk58 = var_v0 | 0xE01 | var_v1 | 0x8000 | 0x4000;
    sp28.unk62 = -1;
    sp28.unk63 = -1;
    sp28.unk1E = 0x19;
    sp28.unk20 = 0xA;
    sp28.unk22 = 0x28;
    sp28.unk64 = -1;
    sp28.unk65 = 0;
    sp28.unk24 = D_8009FD88;
    func_15130374(&sp28, 1, 0, arg3, arg4);
}

s32 func_15130374();
void func_15143874(s16 arg0, f32 arg1, f32 *arg2, f32 *arg3);
extern f32 D_8009FD8C;
extern f32 D_8009FD90;
extern f32 D_8009FD94;
extern f32 D_8009FD98;
extern f32 D_8009FD9C;
extern f32 D_8009FDA0;

struct func_150B879C_s {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60;
    u8 unk61;
    s8 unk62;
    s8 unk63;
    s8 unk64;
    s8 unk65;
    u8 pad66[12];
};

s32 func_150B879C(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, u8 argE) {
    f32 spA4;
    struct func_150B879C_s sp30;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v1;

    spA4 = D_8009FD8C;
    sp30.unk1D = 0x29;
    sp30.unk8 = 0xE03;
    sp30.unk0 = 0x200005;
    sp30.unk4 = 0;
    sp30.unkA = (func_150ADA20() & 0xF) + 0x19;
    sp30.unkC = 0;
    sp30.unk10 = 0;
    sp30.unk18 = 0xB0;
    sp30.unk19 = 0xA0;
    sp30.unk1A = 0x2A;
    sp30.unk14 = 0x40;
    sp30.unk15 = 0xB;
    sp30.unk16 = 0x6A;
    sp30.unk17 = 0xFF;
    sp30.unk1B = (func_150ADA20() % 71U) + 0x3C;
    sp30.unk1C = 0xFF;
    sp30.unk60 = 3;
    sp30.unk61 = 3;
    sp30.unk28 = sp30.unk2C = ((func_150ADA68() * D_8009FD90) + D_8009FD94) * D_8009FD98;
    sp30.unk3C = 0.0f;
    sp30.unk30 = arg2;
    sp30.unk40 = 0.0f;
    sp30.unk44 = 0.0f;
    sp30.unk34 = arg3;
    sp30.unk38 = arg4;
    func_15143874(arg8, ((func_150ADA68() * 154.0f) + 205.0f) * D_8009FD9C, &sp30.unk48, &sp30.unk50);
    sp30.unk4C = 0.0f;
    sp30.unk54 = 0.0f;
    var_v1 = (func_150ADA20() & 1) ? 0x40 : 0;
    if (func_150ADA20() & 1) {
        var_v0 = 0x80;
    } else {
        var_v0 = 0;
    }
    sp30.unk58 = var_v0 | 0xE05 | var_v1 | 0x8000 | 0x4000;
    sp30.unk62 = 0xA;
    sp30.unk63 = -1;
    sp30.unk1E = 0x1C;
    sp30.unk20 = 9;
    sp30.unk22 = 0x19;
    sp30.unk64 = -1;
    sp30.unk65 = 0;
    sp30.unk24 = D_8009FDA0;
    temp_v0 = func_15130374(&sp30, 1, 4, argE, 1);
    if (temp_v0 != 0) {
        memcpy(temp_v0 + 0xA8, &spA4, 4);
    }
    return 1;
}
