#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A361C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A37C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A483C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A499C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4CE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4D88.s")

struct func_151A4E34_s {
    void *obj;
    u8 pad4;
    u8 unk5;
    u8 pad6[2];
    u8 unk8[1];
};

s32 func_151A4E34(struct func_151A4E34_s *arg0, s32 arg1) {
    void *obj = arg0->obj;

    if (*(s32 *) ((char *) obj + 0x1D4) == 0) {
        return 0;
    }
    if ((*(u8 *) ((char *) obj + 0x74) & 0xF) == 0xF) {
        return 0;
    }
    func_15143134(arg0->unk8, arg1, *(s32 *) ((char *) obj + 0x1D4) + (arg0->unk5 << 6));
    return 1;
}

struct func_151A4E9C_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
    u8 pad31[0x98 - 0x31];
    struct func_151A4E9C_s *unk98;
};

void func_151A4E9C(struct func_151A4E9C_s *arg0) {
    struct func_151A4E9C_s *v0 = arg0->unk98;

    arg0->unk30 = 0;
    arg0->unk1E &= ~2;
    v0->unk30 |= 1;
    v0->unk30 |= 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4ECC.s")

struct func_151A4F7C_s {
    s32 unk0;
    u8 unk4;
};

void func_151A4F7C(struct102 *arg0, struct func_151A4F7C_s *arg1, u8 arg2) {
    struct func_151A4F7C_s *temp_v0 = (struct func_151A4F7C_s *)((u8 *)arg0 + 0x28);

    if (arg2 == 0) {
        if ((arg1->unk0 == temp_v0->unk0) || (arg1->unk4 == temp_v0->unk4)) {
            func_1516972C(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A5070.s")

struct func_151A5130_s {
    u8 pad[0x14];
    u8 unk14;
};
extern void (*D_8008F900[])(void *, struct func_151A5130_s *, s16);

void func_151A5130(void *arg0, struct func_151A5130_s *arg1, s16 arg2) {
    D_8008F900[arg1->unk14](arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A5170.s")

extern void (*D_8008F904[])(u8 *, s32, u8);

void func_151A55D4(u8 *arg0, s32 arg1, u8 arg2) {
    void (*fn)(u8 *, s32, u8) = D_8008F904[arg0[0x19]];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A561C.s")
