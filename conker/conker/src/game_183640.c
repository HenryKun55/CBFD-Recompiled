#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15156190.s")

void *func_15156190(void *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4);

void *func_15156388(void *arg0, u8 arg1, s32 arg2) {
    return func_15156190(arg0, arg1, arg2, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151563B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151564F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151568F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15156B54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15156D24.s")

void *func_151D5E30();

void func_15156F94(void *arg0) {
    func_151D5E30((char *)arg0 + 0x88, arg0);
}

void func_15156FB8(s32 arg0) {
    func_15156F94(arg0);
    func_15169804(arg0);
}

void func_15156FE4(s32 arg0) {
    func_15156F94(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151571C4.s")

void func_151571C4(void *arg0);
void func_1518CA04(s32 arg0);
void func_1503F7B8(s32 arg0);

struct func_15157248_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x68 - 0x1C];
    s32 unk68;
};

void func_15157248(struct func_15157248_s *arg0) {
    func_151571C4(arg0);
    func_1518CA04(arg0->unk18);
    func_1503F7B8(arg0->unk68);
    func_15169804(arg0);
}

struct func_1515728C_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x68 - 0x1C];
    s32 unk68;
};

void func_1515728C(struct func_1515728C_s *arg0) {
    func_151571C4(arg0);
    func_1518CA04(arg0->unk18);
    func_1503F7B8(arg0->unk68);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151572D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157420.s")

struct func_15157860_s {
    u8 pad0[0x7C];
    f32 mtx[2][4][4];
};

s32 func_15157860(struct func_15157860_s *arg0) {
    guMtxIdentF(arg0->mtx[D_800BE9C0]);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157AA8.s")

void func_15157D88(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x4C, arg0 + 0x50, arg0);
}

s32 func_15157DC8(u8 *arg0) {
    func_15157DEC(arg0, arg0 + 0x120);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157DEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157F80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157FE8.s")

extern u8 D_800A6060[];

void func_15158078(s32 arg0, u8 arg1) {
    func_15169260(D_800A6060, 3, arg0, arg1);
}
