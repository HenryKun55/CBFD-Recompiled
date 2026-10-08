#include <ultra64.h>

#include "functions.h"
#include "variables.h"

// struct21 *func_100214F0(struct42 *arg0, void *arg1, s32 arg2, void *struct21);
#pragma GLOBAL_ASM("asm/nonmatchings/init_214F0/func_100214F0.s")
struct func_10021C40_s3 {
    u32 unk0;
    u32 unk4;
};

struct func_10021C40_s2 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x20];
};

struct func_10021C40_s1 {
    s32 unk0;
    s32 unk4;
    s32 pad8;
    struct func_10021C40_s2 *unkC;
    struct func_10021C40_s3 *unk10;
};

struct func_10021C40_s {
    u8 pad0[0x18];
    void *unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    struct func_10021C40_s1 *unk28;
    s32 unk2C;
    s32 pad30;
    s32 pad34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
};

s32 func_10021C40(struct func_10021C40_s *arg0, s32 arg1, struct func_10021C40_s1 *arg2) {
    switch (arg1) {
    case 5:
        arg0->unk28 = arg2;
        arg0->unk44 = arg0->unk28->unk0;
        arg0->unk38 = 0;
        arg0->unk28->unk4 = (arg0->unk28->unk4 / 9) * 9;
        if (((u32)arg0->unk28->unk10 & 0xFF000003) != 0x80000000) {
            arg0->unk1C = arg0->unk20 = arg0->unk24 = 0;
            break;
        } else {
            arg0->unk2C = arg0->unk28->unk10->unk0 * 2 * arg0->unk28->unk10->unk4 * 8;
        }
        if (arg0->unk28->unkC != NULL) {
            arg0->unk1C = arg0->unk28->unkC->unk0;
            arg0->unk20 = arg0->unk28->unkC->unk4;
            arg0->unk24 = arg0->unk28->unkC->unk8;
            bcopy(arg0->unk28->unkC->unkC, arg0->unk18, 0x20);
        } else {
            arg0->unk1C = arg0->unk20 = arg0->unk24 = 0;
        }
        break;
    case 4:
        arg0->unk3C = 0;
        arg0->unk40 = 1;
        arg0->unk38 = 0;
        if (arg0->unk28 != NULL) {
            arg0->unk44 = arg0->unk28->unk0;
            arg0->unk24 = 0;
        }
        break;
    default:
        break;
    }
    return 0;
}
// ? func_10021C40(void *arg0, s32 arg1, s32 arg2) {
//     s32 temp_s0;
//     s32 temp_s0_2;
//     void *temp_t3;
//     void *temp_t3_2;
//
//     if (arg1 != 4) {
//         if (arg1 != 5) {
//
//         } else {
//             arg0->unk28 = arg2;
//             arg0->unk44 = (s32) *arg0->unk28;
//             arg0->unk38 = 0;
//             temp_t3 = arg0->unk28;
//             temp_t3->unk4 = (s32) (((s32) temp_t3->unk4 / 9) * 9);
//             if ((arg0->unk28->unk10 & 0xFF000003) != 0x80000000) {
//                 arg0->unk24 = 0;
//                 temp_s0 = arg0->unk24;
//                 arg0->unk20 = temp_s0;
//                 arg0->unk1C = temp_s0;
//             } else {
//                 temp_t3_2 = arg0->unk28->unk10;
//                 arg0->unk2C = (s32) (temp_t3_2->unk0 * 2 * temp_t3_2->unk4 * 8);
//                 if (arg0->unk28->unkC != 0) {
//                     arg0->unk1C = (s32) *arg0->unk28->unkC;
//                     arg0->unk20 = (s32) arg0->unk28->unkC->unk4;
//                     arg0->unk24 = (s32) arg0->unk28->unkC->unk8;
//                     bcopy(arg0->unk28->unkC + 0xC, arg0->unk18, 0x20);
//                 } else {
//                     arg0->unk24 = 0;
//                     temp_s0_2 = arg0->unk24;
//                     arg0->unk20 = temp_s0_2;
//                     arg0->unk1C = temp_s0_2;
//                 }
//             }
//         }
//     } else {
//         arg0->unk3C = 0;
//         arg0->unk40 = 1;
//         arg0->unk38 = 0;
//         if (arg0->unk28 != 0) {
//             arg0->unk44 = (s32) *arg0->unk28;
//             arg0->unk24 = 0;
//         }
//     }
//     return 0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/init_214F0/func_10021E4C.s")
