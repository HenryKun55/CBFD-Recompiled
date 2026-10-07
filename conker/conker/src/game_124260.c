#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150F6DB0_s {
    void *unk0;
    u8 unk4;
};

void func_150F6DB0(void *arg0) {
    struct func_150F6DB0_s sp18;

    sp18.unk0 = arg0;
    sp18.unk4 = *((u8 *)arg0 + 0x3B);
    func_151494E0(&sp18, 0x3E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_124260/func_150F6DE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124260/func_150F706C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124260/func_150F7310.s")

void func_1514EDF0(s32, s32);

struct func_150F739C_s {
    s32 unk0;
    s32 unk4;
    struct102 *unk8[2];
};

void func_150F739C(s32 arg0) {
    struct func_150F739C_s *p;
    u8 i;

    p = (struct func_150F739C_s *)(arg0 + 0x28);
    for (i = 0; i < 2; i++) {
        if (p->unk8[i] != NULL) {
            func_1516972C(p->unk8[i]);
        }
    }
    func_1514EDF0(arg0, p->unk0);
}

void func_150F740C(s32 arg0) {
    func_150F739C(arg0);
    func_1514933C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_124260/func_150F7438.s")
