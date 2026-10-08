#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800A36E0;
void func_1508EF80(void *, void *, f32, void *);

struct func_1512D390_sub {
    u8 pad0[0x24];
    s32 unk24;
    f32 unk28;
};

struct func_1512D390_s {
    u8 pad0[0x2C];
    s32 unk2C;
    u8 pad30[0x84 - 0x30];
    s32 unk84;
    u8 pad88[0x2A4 - 0x88];
    f32 unk2A4;
    u8 pad2A8[0x2F8 - 0x2A8];
    f32 unk2F8;
    u8 pad2FC[0x36C - 0x2FC];
    u16 *unk36C;
    u8 pad370[0x698 - 0x370];
    s32 unk698;
    struct func_1512D390_sub unk69C;
    u8 pad6C8[0x6B0 - 0x6C8 + 0x30];
};

#define unk6B0 unk69C.pad0[0x14]

void func_1512D390(struct func_1512D390_s *arg0) {
    struct func_1512D390_sub *p;
    u16 flags = *arg0->unk36C;

    p = &arg0->unk69C;
    if ((flags & 3) && !(arg0->unk84 & 0x200000)) {
        if (arg0->unk698 == 0) {
            if (flags & 1) {
                *(s32 *)&arg0->unk6B0 = 1;
            } else {
                *(s32 *)&arg0->unk6B0 = -1;
            }
            p->unk24++;
            p->unk28 += *(s32 *)&arg0->unk6B0 * 0.5f * D_800BE9A4;
            p->unk28 = (p->unk28 < -10.0f) ? -10.0f : ((p->unk28 > 10.0f) ? 10.0f : p->unk28);
            if (arg0->unk2C & 0x400) {
                p->unk24 = 20;
                return;
            }
            func_1508EF80(&arg0->unk2F8, &arg0->unk2A4, (p->unk28 * D_800BE9A4) / 2.5f, &arg0->unk2F8);
        }
    } else {
        if (p->unk28 != 0.0f) {
            p->unk28 -= p->unk28 * D_800A36E0 * D_800BE9A4;
            func_1508EF80(&arg0->unk2F8, &arg0->unk2A4, (p->unk28 * D_800BE9A4) / 2.5f, &arg0->unk2F8);
        }
    }
}
