#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_151094FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109FB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_1510A344.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_1510A40C.s")

struct func_1510A870_s { s32 a; u8 b; };
struct func_1510A870_t { s32 x; s32 y; u8 c; u8 d; };

void func_1510A870(u8 *arg0, struct func_1510A870_t *arg1, u8 arg2) {
    struct func_1510A870_s *p = (struct func_1510A870_s *)(arg0 + 0x28);
    s32 x;

    if (arg2 == 0x2D) {
        x = arg1->x;
        if (x == p->a) {
            p->a = arg1->y;
            p->b = arg1->d;
        } else if (p->a == arg1->y) {
            p->a = x;
            p->b = arg1->c;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_1510A8CC.s")
