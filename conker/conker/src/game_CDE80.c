#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A09D0.s")

extern f32 D_8009F5A0;
extern f32 D_8009F5A4;

struct func_150A0D14_s {
    u8 pad0[0xC];
    f32 unkC;
    f32 unk10;
    u8 pad14[0x10];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
};

void func_150A0D14(struct func_150A0D14_s *arg0) {
    f32 temp;

    temp = arg0->unkC * D_8009F5A0;
    arg0->unk24 = func_150AD78C(temp);
    arg0->unk28 = func_150AD780(temp);
    temp = arg0->unk10 * D_8009F5A4;
    arg0->unk2C = func_150AD78C(temp);
    arg0->unk30 = func_150AD780(temp);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A0D8C.s")

s32 func_150A1040(s32 arg0) {
    return arg0 + 0x400;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A104C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A11C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A1DA0.s")

struct func_150A23E4_s {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[0xF];
    u8 unk15;
    u8 pad16;
    u8 unk17;
    s32 unk18;
    u32 unk1C;
    s32 unk20;
};

void func_150A23E4(struct func_150A23E4_s *arg0) {
    s32 flags;
    s32 t0;

    if (arg0->unk20 == 0) {
        flags = 0;
        t0 = 8;
        if (!(arg0->unk15 & 3)) {
            flags = 0x8000;
        }
        if (arg0->unk17 >> 7) {
            t0 = 0x108;
        }
        func_1000FA64(arg0->unk1C >> 16, arg0->unk0, arg0->unk2, arg0->unk4, (arg0->unk17 & 0x7F) * 327, arg0->unk18 | flags, arg0->unk1C & 0xFFFF, 0, 0, 0, t0, 0);
        arg0->unk20 = 1;
    lbl:;
    } else {
        arg0->unk20 = 1;
    }
}

struct func_150A24C0_s {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 pad8[0xF];
    u8 unk17;
    union {
        s32 w;
        s16 h;
        u8 b[4];
    } unk18;
    union {
        s32 w;
        u8 b[4];
    } unk1C;
    s32 unk20;
};

s32 func_15183290(s16, s32, s16, s32, s32, s32, s32, s32, s32, s32, s32);

void func_150A24C0(struct func_150A24C0_s *arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_v0;

    if (arg1 != 0xFF) {
        var_v0 = arg0->unk1C.w & 0xFF;
        temp_a0 = var_v0;
        if ((temp_a0 == 0) || (arg0->unk17 == 9)) {
            s32 a = arg0->unk17;
            s32 b = arg0->unk18.w & 0xFF;
            s32 c = arg0->unk18.h;
            s32 d = arg0->unk18.b[2];
            s32 e = arg0->unk1C.b[0];
            s32 f = arg0->unk1C.b[1];
            s32 g = arg0->unk20;
            var_v0 = func_15183290(arg0->unk0, arg0->unk2 + (f << 4), arg0->unk4, b, a, arg0->unk6, arg1, c, d, e, g);
            if ((var_v0 != -1) && (arg0->unk17 != 9)) {
                arg0->unk1C.w = (var_v0 << 8) | 0xF0 | (arg0->unk1C.w & 0xFFFF0000);
            }
            return;
        }
        {
            var_v0 = temp_a0;
            if (var_v0 < 2) {
                var_v0 = 2;
            }
            arg0->unk1C.w = (arg0->unk1C.w & ~0xFF) | var_v0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A25D4.s")

struct func_150A278C_s {
    u8 pad0[0x15];
    u8 unk15;
    u8 pad16;
    u8 unk17;
    s32 unk18;
    u8 pad1C[0x18];
};

s32 func_150A1DA0();
void func_15172E7C();

void func_150A278C(u8 *arg0) {
    u32 i;
    struct func_150A278C_s *p;

    if (arg0[0x65] == 0) {
        for (i = 0; i < D_800D3094; i++) {
            p = *(struct func_150A278C_s **)&D_800D3098;
            if (p[i].unk15 >> 2 == 8) {
                if (!func_150A1DA0(arg0, &p[i], 0)) {
                    func_15172E7C(arg0, (*(struct func_150A278C_s **)&D_800D3098)[i].unk17,
                                  (*(struct func_150A278C_s **)&D_800D3098)[i].unk18);
                }
            }
        }
    }
}

struct func_150A2864_s {
    u8 pad0[0x14];
    u8 unk14;
    u8 pad15[0x1F];
};

extern u64 D_800D30F0[16][3];

void func_150A2864(u32 arg0, s32 arg1) {
    s32 i;

    arg0 &= 0xFFF;
    if (arg0 < (u32)D_800D3094) {
        (*(struct func_150A2864_s **)&D_800D3098)[arg0].unk14 = arg1;
    }
    if (arg1 == 1) {
        for (i = 0; i < 16; i++) {
            D_800D30F0[i][arg0 >> 6] &= ~((u64)1 << (arg0 & 0x3F));
        }
    }
}

struct func_150A2940_s {
    u8 pad0[0x17];
    u8 unk17;
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x14];
};

void func_150A2940(u32 arg0, s32 arg1, s32 arg2) {
    arg0 &= 0xFFF;
    if (arg0 < (u32)D_800D3094) {
        if (arg1 != -1) {
            (*(struct func_150A2940_s **)&D_800D3098)[arg0].unk18 = arg1;
        }
        if (arg2 != -1) {
            (*(struct func_150A2940_s **)&D_800D3098)[arg0].unk17 = arg2;
        }
        (*(struct func_150A2940_s **)&D_800D3098)[arg0].unk1C = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A29C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2AEC.s")

extern u64 D_800D30F0[][3];

s32 func_150A2CA4(u32 arg0) {
    s32 i;

    arg0 &= 0xFFF;
    if (arg0 > (u32)D_800D3094) {
        return -1;
    }
    for (i = 0; i < 16; i++) {
        if (*(u16 *)((u8 *)&D_800D2138 + 0x208) & (1 << i)) {
            if ((D_800D30F0[i][arg0 >> 6] >> (arg0 & 0x3F)) & 1) {
                return i;
            }
        }
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2EE4.s")

struct func_150A2FA4_s {
    u8 pad0[0x15];
    u8 unk15;
    u8 pad16[0x1E];
};

s32 func_150A2E4C(struct func_150A2FA4_s *arg0, f32 arg1, f32 arg2, f32 arg3);

s32 func_150A2FA4(s32 arg0, u32 arg1) {
    struct108 *p = &D_800DBFF0[arg0];
    struct func_150A2FA4_s *base;

    arg1 &= 0xFFF;
    if ((u32)D_800D3094 < arg1) {
        return 1;
    }
    if (((base = *(struct func_150A2FA4_s **)&D_800D3098)[arg1].unk15 & 3) == 3) {
        return func_150A2E4C(&base[arg1], p->unk2F8, p->unk2FC, p->unk300);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3194.s")

struct func_150A32B4_s {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0xC];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    u8 pad38[0x180 - 0x38];
    f32 unk180;
    u8 pad184[0x32C - 0x184];
};

s32 func_150A1DA0(struct func_150A32B4_s *, s32, s32);

s32 func_150A32B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct func_150A32B4_s sp24;
    s32 pad[2];

    sp24.unk14 = sp24.unk2C = arg1;
    sp24.unk180 = sp24.unk18 = sp24.unk30 = arg2;
    sp24.unk1C = sp24.unk34 = arg3;
    if (func_150A1DA0(&sp24, arg0, 0) == 0) {
        return 1;
    }
    return 0;
}

void func_150A3330(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    *arg1 = *(u8 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x17);
    *arg2 = *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x18);
    *arg3 = *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x1C);
    *arg4 = *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x20);
}

void func_150A3398(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (arg1 & 1) {
        *(u8 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x17) = arg2;
    }
    if (arg1 & 2) {
        *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x18) = arg3;
    }
    if (arg1 & 4) {
        *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x1C) = arg4;
    }
    if (arg1 & 8) {
        *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x20) = arg5;
    }
}

void func_150A3444(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    *(s16 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x0) = arg1;
    *(s16 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x2) = arg2;
    *(s16 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x4) = arg3;
}

s32 func_150A3504(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

s32 func_150A34B0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0[0x14] == 1) {
        return 0;
    }
    if (!(arg0[0x15] & 3)) {
        return func_150A3504(arg0, arg1, arg2, arg3);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3504.s")
