#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D4E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516DB90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516E778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516E8CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516ECAC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F9C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FA88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FBCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FE1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_15170034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_151700D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_15170500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_151707E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_151709B4.s")
