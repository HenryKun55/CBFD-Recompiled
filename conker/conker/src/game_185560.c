#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151580B0.s")

void *func_151580B0(void *, s32, s32, u8, s32, u8, s32);

void func_151581D8(void *arg0, u8 arg1, s32 arg2, u8 arg3, s32 arg4) {
    func_151580B0(arg0, 0, 0, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151582C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515858C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158920.s")

struct func_15158A20_s {
    u8 pad0[0xE0];
    s32 unkE0[4];
    s32 unkF0;
};

void func_15158A20(struct func_15158A20_s *arg0) {
    s32 i;

    for (i = 0; i <= D_80082FA0; i++) {
        if (arg0->unkE0[i] != 0) {
            func_100043B4((void *)arg0->unkE0[i], 4);
        }
    }
    if (arg0->unkF0 != 0) {
        func_100043B4((void *)arg0->unkF0, 4);
    }
}

void func_15158AA4(s32 arg0) {
    func_15158A20(arg0);
    func_15169804(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158AD0.s")

struct func_15158AFC_s {
    u8 pad0[0x14];
    s16 unk14;
    u8 pad16[0x3B - 0x16];
    u8 unk3B;
    u8 pad3C[0xF8 - 0x3C];
    s16 unkF8;
    u8 padFA[2];
    u32 unkFC;
};

s32 func_15158AFC(struct func_15158AFC_s *arg0) {
    s32 temp;

    if (arg0->unk14 < arg0->unkF8) {
        temp = arg0->unk14 * arg0->unkFC;
        if (temp < arg0->unk3B) {
            arg0->unk3B = temp;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158BD0.s")

void func_15158CD4(struct225 *arg0) {
    func_1514EDF0(arg0, arg0->unk18);
    func_15169804(arg0);
}

struct func_15158D00_s {
    char pad0[0x18];
    s32 unk18;
};

void func_15158D00(struct func_15158D00_s *arg0) {
    func_1514EDF0(arg0, arg0->unk18);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159084.s")

struct func_15159120_s {
    u8 pad0[0x118];
    f32 unk118;
    u8 pad11C[0x180 - 0x11C];
    f32 unk180;
};

s32 func_15159120(struct func_15159120_s *arg0, u8 arg1) {
    s32 ret;

    if ((arg1 == 2) || (arg1 == 3)) {
        ret = 1;
    } else if (arg0->unk180 < (arg0->unk118 - 35.0f)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159184.s")

struct func_15159230_s {
    f32 x;
    f32 y;
    f32 z;
};

s32 func_15159230(void *arg0, struct func_15159230_s *arg1, u8 arg2) {
    s32 ret;

    if ((arg1->x != ((f32 *)arg0)[5]) || (arg1->y != ((f32 *)arg0)[6]) || (arg1->z != ((f32 *)arg0)[7])) {
        if ((arg2 == 1) || (arg2 == 2)) {
            ret = 2;
        } else {
            ret = 1;
        }
    } else {
        ret = 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151592B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515942C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151596BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159890.s")

s32 func_15159890(f32 *arg0, f32 *arg1, s32 arg2, s32 arg3);

void func_15159BB0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6) {
    f32 sp24[3];
    f32 sp18[3];

    sp24[0] = arg0;
    sp24[1] = arg1;
    sp18[0] = 0.0f;
    sp18[1] = 0.0f;
    sp18[2] = 0.0f;
    sp24[2] = arg2;
    func_15159890(sp24, sp18, arg6[0xC], arg6[1]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A11C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A78C.s")

extern s32 func_1514ECE0();

s32 func_1515A920(u8 *arg0, s32 *arg1) {
    u8 *sp1C;
    s32 temp;

    if (func_1514ECE0(*(s32 *)(arg0 + 0x2F4), 0x13, &sp1C) == 0) {
        return 0;
    }
    temp = *(s32 *)(sp1C + 0x10);
    *arg1 = temp + 0x34;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515AA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515AB88.s")
