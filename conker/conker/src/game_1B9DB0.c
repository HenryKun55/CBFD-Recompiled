#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800DF7D0[];
extern s32 D_800DF9B8[];
extern void *D_800E0148[];
s32 *func_1502B6BC(s32, s32, s32, s32, s32, s32);
void func_1510CE60(s32, s32, s32, s32, s32 *);
void func_15168E54(s32, s32 *);

s32 func_1518C900(s32 arg0) {
    s32 *s0;

    if (D_800DF7D0[arg0] == 0) {
        s0 = func_1502B6BC(0, 0, 0, 2, 9, arg0);
        if (s0 == NULL) {
            return 0;
        }
        func_1510CE60(*s0, 0, 1, 0x3E, &D_800DF9B8[arg0]);
        func_15168E54(*s0, s0);
        D_800E0148[arg0] = s0;
    } else {
        s0 = D_800E0148[arg0];
    }
    if (D_800DF7D0[arg0] != 0xFF) {
        D_800DF7D0[arg0]++;
    }
    return *s0;
}

extern u8 D_800DF7D0[];
extern s32 D_800DF9B8[];
extern void *D_800E0148[];
void func_1510D630(s32);

void func_1518CA04(s32 arg0) {
    if (arg0 != 0x1E4) {
        if (D_800DF7D0[arg0] != 0) {
            if (--D_800DF7D0[arg0] == 0) {
                func_1510D630(D_800DF9B8[arg0]);
                func_100043B4(D_800E0148[arg0], 4);
            }
        }
    }
}
