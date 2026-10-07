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

struct func_1516D4E8_s {
    u8 pad0[0xE];
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    s32 unk30;
};

struct func_1516D4E8_s *func_15167A68(s32, s32, s32, s32, s32, s32);
s32 func_150448D0(s32, s32, void *, s32, s32, s32, s32, void *, void *);

void func_1516D4E8(s16 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8,
                   u8 arg9, u8 arg10, u8 arg11, u8 arg12, u8 arg13, u8 arg14, u8 arg15, u8 arg16, u8 arg17,
                   u8 arg18, u8 arg19, u8 arg20, u8 arg21, u8 arg22, s16 arg23, s16 arg24, u8 arg25, s16 arg26,
                   s32 arg27, void *arg28, u8 arg29, s32 arg30) {
    struct func_1516D4E8_s *obj;

    obj = func_15167A68(arg27 ? 0x67 : 0x12, arg30, 0x34, 0, arg29, 1);
    if (obj != NULL) {
        obj->unkE = arg0;
        obj->unk10 = arg1;
        obj->unk12 = arg2;
        obj->unk1A = arg3;
        obj->unk1B = arg4;
        obj->unk1C = arg5;
        obj->unk1D = arg6;
        obj->unk1E = arg7;
        obj->unk1F = arg8;
        obj->unk20 = arg9;
        obj->unk21 = arg10;
        obj->unk22 = arg11;
        obj->unk23 = arg12;
        obj->unk14 = arg23;
        obj->unk16 = arg24;
        obj->unk24 = arg25;
        obj->unk18 = arg26;
        obj->unk25 = 0;
        obj->unk26 = arg13;
        obj->unk27 = arg14;
        obj->unk28 = arg15;
        obj->unk29 = arg16;
        obj->unk2A = arg17;
        obj->unk2B = arg18;
        obj->unk2C = arg19;
        obj->unk2D = arg20;
        obj->unk2E = arg21;
        obj->unk2F = arg22;
        if (arg28 != NULL) {
            obj->unk30 = func_150448D0(-1, 0, arg28, 0x14, 0x14, 0x14, 0, &obj->unkE, &obj->unk14);
        } else {
            obj->unk30 = 0;
        }
    }
}

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

void func_1516D99C();

void func_1516F1C0(s32 arg0, s32 arg1, u8 arg2, s32 arg3) {
    func_1516D99C(2, 0, 0, 0x2D, 0, 0xFF, 0xFF, 0xFF, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0x50, 0x50, 0, 0, arg1, 0xA, 0xA, arg0, 0x3C, 0, 0, 0x81, 4, 0, 1, 0, 0, 0, 4, 2, arg2, arg3);
}

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

void func_1516FA88(s16 arg0, s16 arg1, s16 arg2, s32 arg3, u8 arg4, s32 arg5) {
    func_1516D99C(arg0, arg1, arg2, 0x1B, 0, 0xFF, 0xFF, 0xFF, 0, 0xFF, 0xFF, 0xFF, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x400, 0x400, 0, 0, 2, 0, 0, 0xFF, 0xF, 0, 0, 9, 0, 0xFF, 0xA, 0x5A, 5, arg3, 0, 0, arg4, arg5);
}

struct func_1516FBCC_s {
    u8 pad0[0x14];
    s16 unk14;
    s16 unk16;
    u8 pad18[4];
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 pad20[4];
    u8 unk24;
    u8 pad25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    u8 unk2C;
    s8 unk2D;
    s8 unk2E;
    u8 unk2F;
};

s32 func_1516FBCC(struct func_1516FBCC_s *arg0) {
    s32 v;
    s32 a;
    s32 b;

    v = arg0->unk1F;
    if (arg0->unk24 != 0) {
        if (v != 0xFF) {
            v += D_800BE9E4 * 16;
            if (v >= 0x100) {
                v = 0xFF;
            }
            arg0->unk1F = v;
        }
    } else if (v != 0) {
        v -= D_800BE9E4 << arg0->unk2F;
        if (v < 0) {
            v = 0;
        }
        arg0->unk1F = v;
    }
    if (arg0->unk24 == 0 && v == 0) {
        return 1;
    }
    v = arg0->unk2D;
    v *= D_800BE9E4;
    arg0->unk14 += v;
    v = arg0->unk2E;
    v *= D_800BE9E4;
    arg0->unk16 += v;
    if (arg0->unk14 <= 0 || arg0->unk14 <= 0) {
        arg0->unk14 = arg0->unk16 = 0;
        return 1;
    }
    v = arg0->unk2C;
    v += D_800BE9E4;
    if (v >= 0x80) {
        v = 0x7F;
    }
    arg0->unk2C = v;
    v *= 2;
    a = arg0->unk26;
    b = arg0->unk29;
    arg0->unk1C = (((b - a) * v) >> 8) + a;
    a = arg0->unk27;
    b = arg0->unk2A;
    arg0->unk1D = (((b - a) * v) >> 8) + a;
    a = arg0->unk28;
    b = arg0->unk2B;
    arg0->unk1E = (((b - a) * v) >> 8) + a;
    return 0;
}

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
