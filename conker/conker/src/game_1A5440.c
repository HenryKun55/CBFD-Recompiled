#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15177F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_151787AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178BE4.s")

s32 func_15178B98(u8 arg0);

void func_15178C34(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4) {
    s32 temp_v0;

    temp_v0 = func_15178B98(arg0);
    if (temp_v0 != 0) {
        *(s32 *)(temp_v0 + 0x10) = (arg1 << 16) | (arg2 & 0xFFFF);
        *(s32 *)(temp_v0 + 0x14) = arg3 << 16;
        *(s16 *)(temp_v0 + 0x30) = arg4;
    }
}

s32 func_15178B98(u8 arg0);

s32 func_15178C9C(u8 arg0, s32 arg1) {
    s32 temp_v0;
    s32 dx;
    s32 dy;
    s32 dz;

    temp_v0 = func_15178B98(arg0);
    if (temp_v0 != 0) {
        dx = gObjects[arg1].x_position - *(s32 *)(temp_v0 + 0x18);
        dy = gObjects[arg1].y_position - *(s32 *)(temp_v0 + 0x1C);
        dz = gObjects[arg1].z_position - *(s32 *)(temp_v0 + 0x20);
        dx *= dx;
        dy *= dy;
        dz *= dz;
        return sqrtf(dx + dy + dz);
    }
    return 1;
}

extern struct102 *D_800DCF3C;

void func_15178DA4(s32 arg0) {
    s32 pad;
    struct102 *var_a1;
    struct102 *next;

    var_a1 = D_800DCF3C;
    func_100111C8(*(u16 *)((char *)arg0 + 0x2E));
    if (var_a1 != NULL) {
        do {
            next = *(struct102 **)((char *)var_a1 + 0x8);
            if (arg0 == *(s32 *)((char *)var_a1 + 0x14)) {
                func_1516972C(var_a1);
            }
            var_a1 = next;
        } while (next != NULL);
    }
    func_15169824(arg0);
}

s32 func_15178B98(u8 arg0);
void func_15178DA4(s32 arg0);

void func_15178E14(u8 arg0) {
    func_15178DA4(func_15178B98(arg0));
}
