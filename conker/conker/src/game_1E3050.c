#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151B5BA0_s {
    u8 pad0[4];
    u8 unk4;
};

void func_151B4FE0(struct func_151B5BA0_s *arg0, s32 arg1, s32 arg2);

void func_151B5BA0(struct func_151B5BA0_s *arg0, struct func_151B5BA0_s *arg1) {
    if (arg0->unk4 == 0x53) {
        if (arg1->unk4 == 0x16) {
            func_151B4FE0(arg1, 0xFF, 1);
        }
    }
}
