#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void (*D_80089670[])(s32);

void func_15130230(s32 arg0, s32 arg1) {
    u8 temp_v0 = D_800B0DF0->unkF;

    if (temp_v0 != 0) {
        D_80089670[temp_v0](arg0);
    }
}
