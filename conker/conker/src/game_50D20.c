#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15023870_s {
    u8 pad[0x3B];
    u8 unk3B;
};
struct func_15023870_t {
    u8 pad[0x2A];
    u8 unk2A;
};
extern struct func_15023870_t *D_800C35F0[];
extern struct func_15023870_s *func_1505EEF4(s32);

void func_15023870(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct func_15023870_s *tmp;
    if (arg0 == 11 && arg1 == 2) {
        tmp = func_1505EEF4(arg3);
        if (tmp != NULL) {
            D_800C35F0[arg2]->unk2A = tmp->unk3B;
        }
    }
}
