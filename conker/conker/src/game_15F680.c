#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151321D0.s")

struct func_151323AC_s {
    char pad0[0x60];
    s32 unk60;
    char pad64[4];
    u8 unk68;
};
extern void (*D_800899B0[])(void);

void func_151323AC(struct func_151323AC_s *arg0) {
    s32 idx;
    if (arg0->unk60 & 0x100) {
        idx = arg0->unk68;
    } else {
        idx = 0;
    }
    D_800899B0[idx]();
}

struct func_151323F8_s {
    u8 pad0[0x60];
    s32 unk60;
    u8 pad64[4];
    u8 unk68;
};

extern void (*D_800899D4[])(void);

void func_151323F8(struct func_151323F8_s *arg0) {
    s32 idx;

    idx = (arg0->unk60 & 0x100) ? arg0->unk68 : 0;
    D_800899D4[idx]();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132444.s")

void func_15132570(s32 arg0) {
    func_15132444(arg0);
    func_15169804(arg0);
}

void func_1513259C(s32 arg0) {
    func_15132444(arg0);
    func_15169824(arg0);
}

struct func_151325C8_s {
    u8 pad0[0x154];
    s32 unk154[4];
    s32 unk164;
};

void func_151325C8(struct func_151325C8_s *arg0) {
    s32 i;

    for (i = 0; i <= D_80082FA0; i++) {
        if (arg0->unk154[i] != 0) {
            func_100043B4((void *)arg0->unk154[i], 4);
        }
    }
    if (arg0->unk164 != 0) {
        func_100043B4((void *)arg0->unk164, 4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_1513264C.s")

s32 **func_1513264C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

s32 **func_15132A4C(void *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    return func_1513264C(arg0, arg1, arg2, 0, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151332DC.s")

struct func_15133510_s {
    u8 pad0[0x18];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};

void func_151424F4(s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);

s32 func_15133510(s32 arg0, struct func_15133510_s *arg1) {
    func_151424F4(arg0, arg1->unk18, arg1->unk1C, arg1->unk20, arg1->unk24, arg1->unk28, arg1->unk2C,
                  arg1->unk30, arg1->unk34, arg1->unk38, arg1->unk3C, arg1->unk40);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151336A8.s")

struct func_15133760_s {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0xC];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};

void func_15142838(Mtx *m, f32 scale02, f32 scale1, f32 rotX, f32 rotY, f32 rotZ, f32 transX, f32 transY, f32 transZ);

s32 func_15133760(Mtx *arg0, struct func_15133760_s *arg1) {
    func_15142838(arg0, arg1->unk18, arg1->unk1C, arg1->unk20, arg1->unk24, arg1->unk28, arg1->unk38, arg1->unk3C, arg1->unk40);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151337C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133894.s")

struct func_151339D4_s {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
    u8 pad18[0x24];
    f32 unk3C;
    u8 pad40[0x4];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
};

s32 func_151339D4(struct func_151339D4_s *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    f32 temp;

    arg0->unk3C = arg0->unk10 + arg4;
    temp = arg0->unk14;
    arg0->unk44 = arg0->unk44 * temp;
    arg0->unk48 = arg0->unk48 * -temp;
    arg0->unk4C = arg0->unk4C * temp;
    arg0->unk50 = arg0->unk50 * temp;
    arg0->unk54 = arg0->unk54 * temp;
    arg0->unk58 = arg0->unk58 * temp;
    return 1;
}

struct func_15133A50_s {
    u8 pad0[0x10];
    f32 unk10;
    u8 pad14[0x3C - 0x14];
    f32 unk3C;
    u8 pad40[4];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
};

s32 func_15133A50(struct func_15133A50_s *arg0, void *arg1, void *arg2, void *arg3, f32 arg4) {
    arg0->unk3C = arg0->unk10 + arg4;
    arg0->unk44 = 0.0f;
    arg0->unk48 = 0.0f;
    arg0->unk4C = 0.0f;
    arg0->unk50 = 0.0f;
    arg0->unk54 = 0.0f;
    arg0->unk58 = 0.0f;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133C58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133D20.s")

struct func_15133DE8_s {
    u8 pad0[0x7C];
    s32 unk7C;
    u8 unk80;
};

struct func_15133DE8_k {
    s32 unk0;
    u8 unk4;
};

void func_15133DE8(struct func_15133DE8_s *arg0, struct func_15133DE8_k *arg1, u8 arg2) {
    s32 temp;

    if (arg2 == 0) {
        temp = arg1->unk0;
        if ((temp == arg0->unk7C) || (arg0->unk80 == arg1->unk4)) {
            func_1516972C((struct102 *) arg0);
        }
    }
}

struct func_15133E3C_s { s32 a; s32 b; };
extern struct func_15133E3C_s D_800A3860;

void func_15133E3C(void *arg0, u8 arg1) {
    struct func_15133E3C_s sp18 = D_800A3860;
    func_15169260(&sp18, 2, arg0, arg1);
}

struct func_15133E84_s {
    u8 pad[0x170];
    u16 unk170;
    u8 unk172;
    u8 pad173;
    s32 unk174;
};

void *func_15133EEC();

void func_15133E84(void *arg0, struct func_15133E84_s *arg1, s32 arg2) {
    func_15133EEC(arg0, arg1->unk170, arg1->unk172, arg1->unk174);
}

void *func_15133EEC(void *arg0, s32 arg1, s32 arg2, s32 arg3);

void func_15133EB8(void *arg0, void *arg1, s32 arg2) {
    func_15133EEC(arg0, *(u16 *)((char *)arg1 + 0x174), *(u8 *)((char *)arg1 + 0x176), *(s32 *)((char *)arg1 + 0x178));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133FD8.s")
