#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150F5340_s {
    s32 unk[17];
};
extern struct func_150F5340_s D_800A1AB0;

void func_150F5340(void) {
    u8 i;
    struct func_150F5340_s sp28 = D_800A1AB0;

    for (i = 0; i < 17; i++) {
        func_151C970C(1, *(s32 *)&D_800D3098 + sp28.unk[i] * 0x34);
    }
    func_1515F170(9, 1);
}
