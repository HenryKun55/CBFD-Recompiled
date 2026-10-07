#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150DF820_s {
    u8 pad0[0x84];
    s32 unk84;
    u8 pad88[0x1B4 - 0x88];
    s16 unk1B4;
    u8 pad1B6[0x374 - 0x1B6];
    f32 unk374;
    u8 pad378[0x3D0 - 0x378];
    u8 *unk3D0;
};

extern f32 D_800A0F60;
extern f32 D_800A0F64;

void func_150DF820(struct func_150DF820_s *arg0) {
    arg0->unk84 &= ~0x4000;
    arg0->unk84 |= 4;
    arg0->unk84 &= ~0x1010;
    if (arg0->unk3D0[0xAD] != 0) {
        arg0->unk84 |= 0x1010;
        arg0->unk84 &= ~4;
        arg0->unk374 = D_800A0F60;
    } else if (D_800A0F64 == arg0->unk374) {
        arg0->unk1B4 = 3;
        func_15124B18();
    }
}
