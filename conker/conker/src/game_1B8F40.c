#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BBF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C0B8.s")

struct func_1518C540_s {
    u8 pad0[0x1B];
    u8 unk1B;
};

s32 func_1518C540(void *arg0) {
    struct func_1518C540_s *p = *(struct func_1518C540_s **)((u8 *)arg0 + 0x98);
    s32 v = *(s16 *)((u8 *)arg0 + 0x1C) * 8;
    u8 b;
    if (v >= 256) {
        v = 255;
    }
    p->unk1B = v;
    b = v;
    if (b < 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C57C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C850.s")
