#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15100180_s {
    void *ptr;
    u8 val;
};

void func_15100180(void *arg0) {
    struct func_15100180_s sp18;

    sp18.ptr = arg0;
    sp18.val = *((u8 *)arg0 + 0x3B);
    func_151494E0(&sp18, 0x48);
}

struct func_151001B4_s {
    void *unk0;
    u8 unk4;
    s16 unk6;
};

void func_151001B4(void *arg0) {
    struct func_151001B4_s tmp;
    struct260 *temp_v0;

    tmp.unk0 = arg0;
    tmp.unk4 = *((u8 *)arg0 + 0x3B);
    tmp.unk6 = 0;
    temp_v0 = func_15149130(0x12C, -1, 0x4E, -1, 0, 0x3B, (struct37 *)8, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &tmp, 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D630/func_15100230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D630/func_151002BC.s")
