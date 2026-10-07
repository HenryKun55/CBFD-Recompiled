#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15155780_s {
    char pad0[0x10];
    u8 unk10;
    u8 unk11;
    char pad12[2];
    s32 unk14;
    char pad18[0x80];
    f32 unk98;
};

struct func_15155780_s *func_15167A68(s32, s32, s32, s32, s32, s32);
void func_1518C900(s32);

struct func_15155780_s *func_15155780(s32 arg0, s32 arg1) {
    struct func_15155780_s *temp_v0;

    temp_v0 = func_15167A68(0x50, 0, 0xA0, 1, arg1, 1);
    if (temp_v0 == NULL) {
        return temp_v0;
    }
    temp_v0->unk10 = arg0;
    temp_v0->unk11 = 0;
    temp_v0->unk14 = 0;
    temp_v0->unk98 = 0.0f;
    func_1518C900(0xA6);
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_151557FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_1515589C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_15155CFC.s")

void func_1515F10C(void *);
void func_1518CA04(s32);

void func_15155EF8(u8 *arg0) {
    u8 *p = arg0;
    if (*(void **)(p + 0x14) != NULL) {
        func_1515F10C(*(void **)(p + 0x14));
    }
    func_15169804(p);
    func_1518CA04(0xA6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_15155F3C.s")

struct func_15155F90_s {
    u8 pad[0x11];
    u8 unk11;
};
struct func_15155F90_s *func_15155FD4(u8 arg0);

void func_15155F90(void) {
    struct func_15155F90_s *p = func_15155FD4(gCurrentObjectIndex);
    if (p != NULL) {
        if (p->unk11 == 3) {
            p->unk11 = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_15155FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_15156028.s")
