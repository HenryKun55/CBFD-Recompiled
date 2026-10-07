#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_15155780.s")

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
