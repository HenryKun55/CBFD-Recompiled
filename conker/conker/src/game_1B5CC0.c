#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_1518894C.s")

struct func_15188A58_s {
    s32 pad[3];
    struct func_15188A58_s *next;
};

void func_15188A58(struct func_15188A58_s *arg0, struct func_15188A58_s **arg1) {
    struct func_15188A58_s *p;
    struct func_15188A58_s *next;

    arg0->next = NULL;
    if (*arg1 != NULL) {
        p = *arg1;
        while ((next = p->next) != NULL) {
            p = next;
        }
        p->next = arg0;
        return;
    }
    *arg1 = arg0;
}

struct func_15188A9C_s {
    u8 pad0[6];
    s16 unk6;
    u8 pad8[4];
    struct func_15188A9C_s *unkC;
    s32 unk10;
};

void func_15188A9C(s32 arg0) {
    struct func_15188A9C_s *var_v0;

    var_v0 = (struct func_15188A9C_s *)D_800DF7C8[0];
    if (var_v0 != NULL) {
        do {
            if (arg0 == var_v0->unk10) {
                var_v0->unk6 = 0;
            }
            var_v0 = var_v0->unkC;
        } while (var_v0 != NULL);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15189118.s")

struct func_151895A4_s {
    s32 unk0;
    s32 unk4;
    void *unk8;
};

void func_151895A4(struct func_151895A4_s *arg0) {
    func_100043B4(arg0->unk8, 2);
}

void func_151895CC(void **arg0) {
    func_100043B4(arg0[2], 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_151895F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_151897A4.s")

struct func_151898C0_s {
    char pad0[0xC];
    struct func_151898C0_s *next;
    s32 id;
    s32 val;
};

void func_151898C0(s32 arg0, s32 arg1) {
    struct func_151898C0_s *var_v0;

    for (var_v0 = (struct func_151898C0_s *)D_800DF7C8[0]; var_v0 != NULL; var_v0 = var_v0->next) {
        if (arg0 == var_v0->id) {
            var_v0->val = arg1;
            return;
        }
    }
}
