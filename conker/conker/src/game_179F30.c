#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514CA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D64C.s")

void func_1514D96C(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DAA4.s")

s32 func_15158BD0(s32 arg0, s32 arg1, s32 arg2);
void func_1514EC1C(s32 arg0, s32 arg1, s32 arg2);

void func_1514DB18(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_15158BD0(arg0, 1, 0);
    if (temp_v0 != 0) {
        func_1514EC1C(temp_v0, arg0, 0x13);
    }
}

void func_1514DB58(s32 arg0) {
}

void func_1514DB64(void) {
    if (D_800BE9F0 == 20) {
        func_151B2060();
    }
}

void func_1514DB98(void) {
    func_1514F194();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DBB8.s")

void func_1514DC38(struct127 *arg0) {
    func_1500EE18(arg0, 0xFF, 1);
}

void func_151D0F60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_1514DC5C(s32 arg0) {
    func_151D0F60(arg0, 0, 0xFF, 1);
}

void func_1514DC84(s32 arg0) {
    *(s32 *)(arg0 + 0x94) |= 2;
}

struct func_1514DC98_s {
    u8 pad0[0x94];
    s32 unk94;
};

void func_1514DC98(struct func_1514DC98_s *arg0) {
    arg0->unk94 |= 0x710;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DCAC.s")

void func_1514DCF4(struct127 *arg0) {
    if (arg0->unk31C != NULL) {
        arg0->unk31C->unk94 = 1;
    }
    func_15083568(arg0, 0x17, 0x3F800000, 0);
}

void func_1514DD2C(void) {
    func_1514DCAC();
}

void func_1514DD4C(void) {
    func_1514DCAC();
}

void func_1514DD6C(void) {
    func_1514DCAC();
}

void func_1514DD8C(void) {
    func_1514DCAC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DDAC.s")

void func_1514DDCC(void) {
    func_1514DCAC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DDEC.s")

void func_1514DE0C(void) {
    func_1514DCAC();
}

void func_1514DE2C(s32 arg0) {
}

void func_1514DE38(s32 arg0) {
}

void func_1514DE44(s32 arg0) {
}

void func_1514DE50(void) {
    if (((u8 *)&D_800D2E4C->unk10)[1] & 8) {
        func_1514DCAC();
    }
}

void func_1514DE88(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE94.s")

s32 func_15083FB0(s32);

struct func_1514DFD0_s {
    u8 pad0[0x65];
    u8 unk65;
    u8 pad66[0x101 - 0x66];
    u8 unk101;
};

void func_1514DFD0(struct func_1514DFD0_s *arg0) {
    arg0->unk65 = func_15083FB0(9) + 1;
    arg0->unk101 |= 0x34;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E00C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E31C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E718.s")

extern s32 D_800A5920;
s32 func_1518D1C0();
void func_1514EC1C();

void func_1514E7C8(s32 arg0) {
    func_1514EC1C(func_1518D1C0(arg0, 7, 0, 1, 0xFF, 1, &D_800A5920), arg0, 0xF);
}

void func_1514E824(s32 arg0) {
}

void func_1514E830(struct102 *arg0) {
    func_1516972C(arg0);
}

void func_1514E850(struct102 *arg0) {
    func_1518E308(arg0);
    func_1516972C(arg0);
}

void func_1514E87C(void) {
    func_1515F10C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E920.s")

void func_1514E920(void);

void func_1514E9DC(void) {
    func_1514E920();
}

void func_1514E9FC(void) {
    func_1514E89C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EA1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EB6C.s")

s32 func_1514EB8C(s32 arg0, s32 arg1, s32 arg2) {
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EBA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EC1C.s")

struct func_1514ECE0_s {
    u8 pad0[0x14];
    struct func_1514ECE0_s *next;
    u8 pad18[0x4];
    s16 id;
};

s32 func_1514ECE0(struct func_1514ECE0_s *arg0, s16 arg1, struct func_1514ECE0_s **arg2) {
    s32 found = 0;
    struct func_1514ECE0_s *p = arg0;

    while (p != NULL && !found) {
        arg0 = p->next;
        if (arg1 == p->id) {
            found = 1;
        } else {
            p = arg0;
        }
    }
    if (arg2 != NULL) {
        *arg2 = p;
    }
    return found;
}

struct func_1514ED3C_s {
    u8 pad0[0x10];
    s32 unk10;
    struct func_1514ED3C_s *next;
};

s32 func_1514ED3C(struct func_1514ED3C_s *arg0, s32 arg1, struct func_1514ED3C_s **arg2) {
    s32 found = 0;
    struct func_1514ED3C_s *p = arg0;
    struct func_1514ED3C_s *next;

    while (p != NULL && !found) {
        next = p->next;
        if (arg1 == p->unk10) {
            found = 1;
        } else {
            p = next;
        }
    }
    if (arg2 != NULL) {
        *arg2 = p;
    }
    return found;
}

struct func_1514ED8C_s {
    u8 pad0[0x10];
    s32 unk10;
    struct func_1514ED8C_s *next;
    struct func_1514ED8C_s *prev;
};

s32 func_1514ED8C(struct func_1514ED8C_s *arg0, u8 *arg1) {
    s32 ret;

    if (arg0 == *(struct func_1514ED8C_s **)(arg1 + 0x2F4)) {
        *(struct func_1514ED8C_s **)(arg1 + 0x2F4) = arg0->next;
    }
    if (arg0->next != NULL) {
        arg0->next->prev = arg0->prev;
    }
    if (arg0->prev != NULL) {
        arg0->prev->next = arg0->next;
    }
    ret = arg0->unk10;
    func_1516972C((struct102 *)arg0);
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EDF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EECC.s")

void func_1514F110(void) {
    func_1514F194();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F44C.s")

void func_151D74B0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_1514F4A8(void *arg0) {
    func_151D74B0(arg0, 1, -1, 0xFF, 1);
}

void func_151D74B0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_1514F4D8(void *arg0) {
    func_151D74B0(arg0, 2, 1, 0xFF, 1);
}

void func_1514F508(s32 arg0) {
    func_151D74B0(arg0, 3, 0, 0xFF, 1);
}

void func_1514F538(void *arg0) {
    func_151D74B0(arg0, 4, -1, 0xFF, 1);
}

void func_150C4120(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_1514F568(s32 arg0) {
    func_150C4120(arg0, -1, 0xFF, 1);
}

void func_1514F590(s32 arg0) {
    func_1501175C(arg0, 0xFF, 1);
    func_15011A78(arg0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F5CC.s")
