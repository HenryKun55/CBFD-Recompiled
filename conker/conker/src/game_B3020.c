#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15085B70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15085BE8.s")

extern f32 D_800D2360[];
extern u8 D_800D237C[];

u8 func_15085DA8(f32 arg0) {
    s32 i = 0;

    while (D_800D2360[i] <= arg0) {
        i++;
    }
    return D_800D237C[i];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15085DF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086BD0.s")

typedef struct func_15086C70_s {
    s16 x;
    s16 y;
    s16 z;
    s16 pad[5];
} func_15086C70_s;
extern func_15086C70_s *D_800D2350;
extern void func_150A3194(s32, s32, s32, s32, s32);

void func_15086C70(s32 arg0) {
    s32 z = D_800D2350[arg0].z;
    func_150A3194(3, 0xB, D_800D2350[arg0].x, D_800D2350[arg0].y, z);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086CBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150870D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087EF0.s")

extern void *D_800872A0;

void func_15087FC4(s32 arg0, s32 arg1) {
    u8 *temp_v1;

    if (D_800872A0 != NULL) {
        temp_v1 = (arg0 * 0x84) + (u8 *)D_800872A0;
        temp_v1[0x31] = arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508802C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150880F8.s")

extern void *D_800872A0;

s32 func_150881CC(s32 arg0) {
    f32 *ptr;

    if (D_800872A0 == NULL) {
        return 0;
    }
    ptr = (f32 *)(arg0 * 0x84 + (char *)D_800872A0);
    return *ptr * 256.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088270.s")

extern void *D_800872A0;

struct func_150882B0_s {
    u8 pad0[0x27];
    s8 unk27;
    u8 pad28[0x84 - 0x28];
};

s32 func_150882B0(s32 arg0) {
    struct func_150882B0_s *temp;

    if (D_800872A0 == NULL) {
        return 0;
    }
    temp = (struct func_150882B0_s *)(arg0 * 0x84 + (char *)D_800872A0);
    return temp->unk27;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150882E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150883B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508855C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150885EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508868C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088780.s")

extern void *D_800872A0;

s32 func_150887F8(void) {
    if (D_800872A0 == NULL) {
        return 0;
    }
    return *((u8 *)D_800872A0 + 0x46) == 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150888A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508907C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150891E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150896EC.s")

extern void *D_800D23B0;

void func_15089BB0(void) {
    D_800D23B0 = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15089BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15089F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508A1BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508A6FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B194.s")

struct func_1508B1D4_s {
    u8 pad0[0x70];
    struct {
        s16 unk0;
        u8 pad2[0xA];
    } unk70[1];
};
extern struct func_1508B1D4_s *gGameState;

void func_1508B1D4(s32 arg0) {
    if (arg0 < D_8008FD90) {
        gGameState->unk70[arg0].unk0 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B2A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B3F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B9BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508BC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508BF14.s")

s32 func_1508C194(s32 arg0) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508C1A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508C5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508C9CC.s")

extern void *D_800D23B0;

s32 func_1508CA88(void) {
    ((s8 *)D_800D23B0)[0x1703]++;
    if (((s8 *)D_800D23B0)[0x1703] >= D_8008FD90) {
        ((s8 *)D_800D23B0)[0x1703] = 0;
    }
    return ((s8 *)D_800D23B0)[0x1703];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508CAD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508D850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508DA1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508DAEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508DC24.s")

void func_1508E6C8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508E6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508E780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508E89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508EB90.s")

void func_1508EBF8(s32 arg0, s32 arg1) {
    u8 v0 = D_800CC40F[arg0 * 812];

    func_1509BFB0(1, v0 | 0x2000, 0x14, arg1);
}

void func_1508EC5C(s32 arg0, s32 arg1) {
    u8 v0 = D_800CC40F[arg0 * 812];
    func_1509BFB0(1, v0 | 0x2000, 0x61, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508ECC0.s")

struct func_1508EDBC_s {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    u8 pad8[0x10];
};

void func_1508EDBC(u32 arg0) {
    if (arg0 < D_80087380) {
        ((struct func_1508EDBC_s *)D_800D23C0)[arg0].unk2 = 0;
        ((struct func_1508EDBC_s *)D_800D23C0)[arg0].unk4 = 0;
        ((struct func_1508EDBC_s *)D_800D23C0)[arg0].unk0 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508EE0C.s")
