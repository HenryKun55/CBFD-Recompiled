#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E080.s")

struct func_1517E134_s {
    u8 pad[0x24];
    struct func_1517E134_s *next;
};

void func_1517E134(struct func_1517E134_s *arg0) {
    struct func_1517E134_s *prev;

    if (arg0 == (struct func_1517E134_s *)D_800DDD64) {
        D_800DDD64 = arg0->next;
    } else {
        for (prev = D_800DDD64; prev != NULL && prev->next != arg0; prev = prev->next) {
        }
        if (prev == NULL) {
            return;
        }
        prev->next = arg0->next;
    }
    func_10004074(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E1AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E28C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E4A8.s")

Gfx *func_1517EA4C(Gfx *gfx) {
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
    gDPSetOtherMode(gfx++, 0x002C0F, 0x504344);
    return gfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517EAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517EC1C.s")
