#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_1516D400(void) {
    s32 i;
    s32 tmp;

    for (i = 0; i < 4; i++) {
        if ((&D_800DD2A0)[i] < 0xFF) {
            tmp = (&D_800DD2A0)[i] + D_800BE9A0;
            if (tmp > 0xFF) {
                tmp = 0xFF;
            }
            (&D_800DD2A0)[i] = tmp;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D4E8.s")

extern s32 (*D_8008CBA0[])(void *);

struct func_1516D678_s {
    u8 pad0[0x10];
    s16 unk10;
    u8 pad12[6];
    s16 unk18;
    u8 pad1A[9];
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 pad26[0xA];
    s16 *unk30;
};

void func_1516D678(struct func_1516D678_s *arg0) {
    s32 v;
    s32 t;

    t = arg0->unk24;
    if (t != 0) {
        t -= D_800BE9E4;
        if (t < 0) {
            t = 0;
        }
        arg0->unk24 = t;
    }
    if (D_8008CBA0[arg0->unk23](arg0) == 1) {
        if (arg0->unk30 != NULL) {
            arg0->unk30[2] = 0;
        }
        func_1516972C(arg0);
    } else {
        v = arg0->unk10;
        v = (v << 8) + arg0->unk25;
        v += (u32)(arg0->unk18 * D_800BE9E4);
        arg0->unk10 = v >> 8;
        arg0->unk25 = v & 0xFF;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516DB90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516E778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516E8CC.s")

struct func_1516ECAC_s {
    u8 pad0[0x14];
    s16 unk14;
    s16 unk16;
    u8 pad18[0x1F - 0x18];
    u8 unk1F;
    u8 pad20[0x24 - 0x20];
    u8 unk24;
    u8 pad25;
    u8 unk26;
    u8 pad27[0x2C - 0x27];
    u8 unk2C;
    u8 unk2D;
};

s32 func_1516ECAC(struct func_1516ECAC_s *arg0) {
    s32 v1 = arg0->unk1F;
    s32 t;
    s32 p;

    if (arg0->unk24 != 0) {
        if (v1 != 0xFF) {
            v1 += D_800BE9E4 << 7;
            if (v1 >= 0x100) {
                v1 = 0xFF;
            }
            arg0->unk1F = v1;
        }
    } else if (v1 != 0) {
        v1 -= D_800BE9E4 * arg0->unk26;
        if (v1 < 0) {
            v1 = 0;
        }
        arg0->unk1F = v1;
    }
    if (arg0->unk24 == 0 && v1 == 0) {
        return 1;
    }
    t = (arg0->unk2C << 8) | arg0->unk2D;
    p = t * v1;
    arg0->unk14 = arg0->unk16 = p >> 7;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516ED68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516EED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F1C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F864.s")

struct func_1516F8EC_s {
    u8 pad[0x26];
    s8 hi;
    u8 lo;
};

void func_1516F8EC(struct func_1516F8EC_s *arg0, u32 arg1) {
    s32 v;

    v = arg0->hi;
    v = (v << 8) + arg0->lo;
    v = (s32)(v * arg1) >> 8;
    arg0->hi = v >> 8;
    arg0->lo = v & 0xFF;
}

void func_1516F91C(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = *(s8 *)((char *)arg0 + 0x28);
    temp_v0 <<= 8;
    temp_v0 += *(u8 *)((char *)arg0 + 0x29);
    temp_v0 = (s32)(temp_v0 * (u32)arg1) >> 8;
    *(s8 *)((char *)arg0 + 0x28) = temp_v0 >> 8;
    *(u8 *)((char *)arg0 + 0x29) = temp_v0 & 0xFF;
}

void func_1516F94C(s32 arg0, s32 arg1) {
    func_1516F8EC(arg0, arg1);
    func_1516F91C(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F984.s")

struct func_1516F9C4_s {
    u8 pad0[0x14];
    s16 unk14;
    s16 unk16;
    u8 pad18[0x1F - 0x18];
    u8 unk1F;
    u8 pad20[0x24 - 0x20];
    u8 unk24;
};

s32 func_1516F9C4(struct func_1516F9C4_s *arg0) {
    s32 v;

    v = arg0->unk1F;
    if (arg0->unk24 != 0) {
        if (v != 0xFF) {
            v += D_800BE9E4 << 4;
            if (v >= 0x100) {
                v = 0xFF;
            }
            arg0->unk1F = v;
        }
    } else {
        if (v != 0) {
            v -= D_800BE9E4 << 3;
            if (v < 0) {
                v = 0;
            }
            arg0->unk1F = v;
        }
        arg0->unk14 = arg0->unk16 = (v << 9) >> 8;
    }
    if (arg0->unk24 == 0 && v == 0) {
        return 1;
    }
    func_1516F864(arg0);
    func_1516F984(arg0, 0xF0);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FA88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FBCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FE1C.s")

void func_15170034(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    s32 mask;
    f32 cs;
    f32 s;
    f32 c;
    s32 a;

    mask = (arg0 & 0x40) ? 0x3F : 0x7F;
    a = func_150ADA20() & mask;
    *arg2 = func_150489B0(a);
    c = func_15048A40(a);
    a = func_150ADA20() & 0xFF;
    s = func_150489B0(a);
    cs = func_15048A40(a);
    *arg1 = c * cs;
    *arg3 = c * s;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_151700D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_15170500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_151707E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_151709B4.s")
