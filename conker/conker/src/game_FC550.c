#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150CF0A0_s {
    u8 pad0[0x4F];
    u8 unk4F;
    u8 pad50[0x73 - 0x50];
    u8 unk73;
};
extern struct func_150CF0A0_s *func_151149AC(s32);
extern void func_15117798(void);
extern u8 *D_800CC5EC;

void func_150CF0A0(struct func_150CF0A0_s *arg0) {
    struct func_150CF0A0_s *temp;

    if ((arg0->unk73 & 3) != 2) {
        if ((arg0->unk4F & 4) && D_800CC5EC[0x57]) {
            temp = func_151149AC(0xFE);
            temp->unk73 &= ~3;
            temp->unk73 |= 2;
            temp = func_151149AC(0xFD);
            temp->unk73 &= ~3;
            temp->unk73 |= 2;
        }
    } else {
        func_15117798();
    }
}
