#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B65D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B70B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7328.s")

struct func_151B7678_s2 {
    s32 unk0;
    u8 pad4[0x14 - 0x4];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x3B - 0x20];
    u8 unk3B;
};
struct func_151B7678_s1 {
    struct func_151B7678_s2 *unk0;
    u8 unk4;
};
struct func_151B7678_s0 {
    s32 unk0;
    struct func_151B7678_s1 *unk4;
};
struct func_151B7678_s {
    u8 pad[0x98];
    struct func_151B7678_s0 *unk98;
};

s32 func_151B7678(struct func_151B7678_s *arg0, f32 *arg1) {
    struct func_151B7678_s0 *temp_v0 = arg0->unk98;
    struct func_151B7678_s1 *temp_v1 = temp_v0->unk4;
    struct func_151B7678_s2 *temp_a2 = temp_v1->unk0;

    if (temp_a2->unk0 == 0 || temp_a2->unk3B != temp_v1->unk4) {
        return 0;
    }
    arg1[0] = temp_a2->unk14;
    arg1[1] = temp_a2->unk18;
    arg1[2] = temp_a2->unk1C;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B76CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B77F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7C38.s")

struct func_151B82CC_s {
    u8 pad[8];
    u8 unk8;
};
extern void (*D_8008FB98[])(void *, s32, u8);

void func_151B82CC(void *arg0, s32 arg1, u8 arg2) {
    struct func_151B82CC_s *s;
    void (*func)(void *, s32, u8);

    s = *(struct func_151B82CC_s **)((u8 *)arg0 + 0x98);
    func = D_8008FB98[s->unk8];
    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

void func_151B8318(void *arg0, void *arg1, u8 arg2) {
    s32 temp_v0 = *(s32 *) ((char *) arg0 + 0x98);
    void *temp_v1 = *(void **) ((char *) temp_v0 + 4);

    if (arg2 == 0) {
        temp_v0 = *(s32 *) arg1;
        if (temp_v0 == *(s32 *) temp_v1 || *((u8 *) temp_v1 + 4) == *((u8 *) arg1 + 4)) {
            func_1516972C((struct102 *) arg0);
        }
    }
}

struct func_151B8370_s {
    u8 pad0[0x98];
    struct102 **unk98;
};

void func_151B8370(struct func_151B8370_s *arg0) {
    struct102 **temp_v0 = arg0->unk98;

    if (*temp_v0 != NULL) {
        func_1516972C(*temp_v0);
    }
}

void func_151B83A0(s32 arg0) {
    func_151B8370(arg0);
    func_151478F4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B83CC.s")
