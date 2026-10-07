#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15015E80_s {
    u8 pad[0x1C];
    u16 unk1C;
};
extern s32 D_800BE9C8[];
extern s32 D_800BEBA4;
s32 allocate_memory();
#define S ((struct func_15015E80_s *)D_800B0DF0)

void func_15015E80(void) {
    if (S->unk1C == 0) {
        S->unk1C = 8000;
    }
    S->unk1C += 400;
    D_800BE9C8[0] = allocate_memory(S->unk1C * 8, 0xFF, 2, 0);
    D_800BE9C8[1] = allocate_memory(S->unk1C * 8, 0xFF, 2, 0);
    D_800BEBA4 = ((D_800BE9C8[1] - D_800BE9C8[0]) >> 3) - 400;
}
