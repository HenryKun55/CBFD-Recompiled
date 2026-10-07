#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct func_1517ABB0_s {
    void *ptr;
    u8 timer;
} func_1517ABB0_s;
struct func_1517ABB0_t {
    u8 type;
    u8 count;
};
extern struct func_1517ABB0_t D_800A7230[][4];
extern u16 D_800C4310[];
void func_10004074(void *);

void func_1517ABB0(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i != 2; i++) {
        if (D_800DD460[i] != 0) {
            for (j = 0; j < D_800C4310[D_800A7230[i][0].type]; j++) {
                for (k = 0; k < D_800A7230[i][0].count; k++) {
                    if (((func_1517ABB0_s **)D_800DD460[i])[j][k].ptr != NULL) {
                        if (((func_1517ABB0_s **)D_800DD460[i])[j][k].timer != 0) {
                            ((func_1517ABB0_s **)D_800DD460[i])[j][k].timer--;
                        } else {
                            func_10004074(((func_1517ABB0_s **)D_800DD460[i])[j][k].ptr);
                            ((func_1517ABB0_s **)D_800DD460[i])[j][k].ptr = NULL;
                        }
                    }
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A8060/func_1517AD00.s")
