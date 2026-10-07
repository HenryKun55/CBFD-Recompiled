#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_100038E0(void) {
    s16 *p = (s16 *)0xBC000C02;
    *(s16 **)&D_80038070 = p;
    D_80038074 = 0x4040;
    *p = 0x4040;
}
// NON-MATCHING: wtf is this
// s32 func_100038E0(void) {
//     D_80038070 = 0xBC000C02; // -0.007815362885594368 ?
//     D_80038074 = (u16)0x4040;
//     D_BC000C02 = (u16)0x4040;
//     return 0xBC000C02;
// }

s32 func_1000390C(void) {
    return 0;
}
