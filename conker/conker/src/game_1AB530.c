#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E134.s")

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
