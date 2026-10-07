#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150BB700(s32 arg0) {
    if (func_1509BE40(1, 0x4047, 6, 0x2000)) {
        *(s32 *)(arg0 + 0x84) |= 0x1000;
    } else {
        *(s32 *)(arg0 + 0x84) &= ~0x1000;
    }
}
