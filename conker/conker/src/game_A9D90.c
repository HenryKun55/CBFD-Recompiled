#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_1507C8E0(struct127 *arg0, s32 arg1) {
    arg0->unk31C->unk120 = (u8)2;
    arg0->unk31C->unk124 = arg1;
}

// "goto" hell
#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507C8FC.s")

void func_1507CD0C(struct127 *arg0) {
    s32 temp_lo = ((s32)arg0 - (s32)&gObjects) / (s32)sizeof(struct127);

    arg0->unk31C->unk120 = 3;

    if (temp_lo <= D_80082FA0) {
        func_15181D70(temp_lo);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507CD64.s")
void func_1507D158(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 v0 = D_800CC40F[arg0 * 812];

    func_1509BFB0(3, v0 | 0x2000, arg1, arg2, arg3, arg4);
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507D1D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507D4F8.s")
// NON-MATCHING: pretty far away!
// void func_1507D4F8(s16 arg0) { // struct126 *
//     // s32 sp24;
//     struct127 *temp_a0;
//
//     if ((D_8008FDBC & 1) == 0) {
//         func_15085710(arg0, 4, 1);
//     }
//     // sp24 = (s32) arg0;
//     if (func_150859AC(arg0, 3) != 0) {
//         func_15085710(arg0, 5, D_8008726C); //temp_ret =
//         temp_a0 = &gObjects[arg0];
//         temp_a0->unkB2 = (u16)0;
//         if (D_800BE616 == 0) {
//             D_800D18A8 = (u8)1;
//             if (((D_800D2E4C->unk19 & 4) != 0) || (D_8008FDA8 < 0)) {
//                 func_1501C730(2, D_800BE3DF, D_800BE3E0, 0, 0);
//                 return;
//             }
//             func_1501C730(1, 0x22, 0, 0, 0);
//             return;
//         }
//         if (D_800E0C20 != 0) {
//             temp_a0->unk31C->unk120 = (u8)0xA;
//             return; // temp_ret;
//         }
//         func_1507D1D8(temp_a0);
//         return;
//     }
//     if (D_800BE616 == 0) {
//         D_800D2E43 = (u8)1;
//         func_1509C3A0();
//         D_800D18A8 = (u8)1;
//         func_15085710(arg0, 5, D_8008726C);
//         func_15085710(arg0, 2, D_80087260);
//         func_1501C730(1, 0x18, 0, 0, 0);
//     } else {
//         D_800D18A0 = (u16) (D_800D18A0 | (1 << (s32) arg0));
//     }
//     // temp_a0 = &gObjects[arg0];
//     if (temp_a0->unk31C->unk84 == 0) {
//         D_8008FD94 -= 1; //(s8) (D_8008FD94 - 1);
//     }
//     temp_a0->unk31C->unk120 = (u8)0xA;
//     D_800BE618 -= 1; //(s8) (D_800BE618 - 1);
//     //return temp_a0_2->unk31C;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507D754.s")

void func_1507DB44(s32 arg0, s32 arg1) {
    func_1503DE70(arg0, arg1, -1);
}

void func_1507DB64(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507DB6C.s")

void func_1507DE4C(struct127 *arg0) {

    if (arg0->interaction_state == 1) {
        func_150836CC(arg0, 0x44);
        func_150836CC(arg0, 0x23);
        arg0->unk9C |= 0xF000;
        func_150836CC(arg0, 0x44);
        func_150836CC(arg0, 0x23);
        return;
    }

    switch(arg0->id) {
        case 0x9F:
        case 0xa0:
            arg0->unk9C |= 0xF000;
            break;
        case 0x5A:
        case 0x74:
        case 0x7A:
            arg0->unk9C |= 0xFF8;
            break;
    }
}


// NON-MATCHING: exact 53/53 instruction match, byte-identical except the
// jtbl_8009B884 lui/lw placeholder (resolves once linked). A 6-value
// dispatch on arg1 (4..9, two values sharing each of the last three
// case bodies) compiled by target as a genuine jump table, matching a
// plain C switch here - unlike func_151347CC's dispatch in this same
// segment, where a switch provoked a jump table target DIDN'T have.
// struct127 and its unk94/unk9C/unk2E4 fields already established by
// the neighboring func_1507DE4C.
void func_1507DF10(struct127 *arg0, s32 arg1) {
    switch (arg1) {
        case 9:
            arg0->unk94 |= 0x20;
            arg0->unk9C |= 0x78;
            arg0->unk2E4 = 1;
            break;
        case 8:
            arg0->unk94 |= 0x40;
            arg0->unk94 &= ~0x200;
            arg0->unk9C |= 0xF00;
            arg0->unk2E4 = 2;
            break;
        case 6:
        case 7:
            arg0->unk94 |= 0xE;
            arg0->unk94 &= ~0x410;
            arg0->unk9C |= 0xEE0000;
            arg0->unk2E4 = 4;
            break;
        case 4:
        case 5:
            arg0->unk94 |= 0x80;
            arg0->unk94 &= ~0x500;
            arg0->unk2E4 = 8;
            break;
    }
}
// void func_1507DF10(struct127 *arg0, s32 arg1) {
//     switch (arg1) {
//         case 9:
//             arg0->unk94 |= 0x20;
//             arg0->unk9C |= 0x78;
//             arg0->unk2E4 = 1;
//             break;
//         case 8:
//             arg0->unk94 |= 0x40;
//             arg0->unk94 &= ~0x200;
//             arg0->unk9C |= 0xF00;
//             arg0->unk2E4 = 2;
//             break;
//         case 6:
//         case 7:
//             arg0->unk94 |= 0xE;
//             arg0->unk94 &= ~0x410;
//             arg0->unk9C |= 0xEE0000;
//             arg0->unk2E4 = 4;
//             break;
//         case 4:
//         case 5:
//             arg0->unk94 |= 0x80;
//             arg0->unk94 &= ~0x500;
//             arg0->unk2E4 = 8;
//             break;
//     }
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507DFE4.s")
s32 func_15084D70(s32, u8, s32, s32 *, s32 *, u8 *, u8 *, s32 *, s32 *, s32, s32 *);

s32 func_1507E114(s32 arg0) {
    s32 sp5C;
    s32 sp54[2];
    s32 sp48[3];
    s32 sp44;
    u8 sp43;
    u8 sp42;
    s32 sp3C;

    if (D_800D18A8 == 0) {
        return 0;
    }
    if ((D_800BE9F4 == 0x22) || (D_800BE9F4 == 0x18)) {
        return 0;
    }
    D_800BE9F4 = (s8)D_800BE3DF;
    func_15084D70(0, D_800BE3E0, 1, sp54, sp48, &sp43, &sp42, &sp44, &sp3C, 1, &sp5C);
    return sp5C + 1;
}
// NON-MATCHING: full semantics recovered and verified via isolated
// harness. Struct unidentified (raw offset casts, matching the sibling
// func_151380B4 in game_161520.c which reads the same arg0->unk1D4
// field). If unk1D4 is 0, copies unk14/unk18/unk1C straight out to
// *arg1/*arg2/*arg3. Otherwise builds a {0, unk150*30.0f, 0} triple,
// picks a flags value from unk1D4 (+0x300 if unk0==1, +0xC0 if
// unk0==0x1E, else unmodified - same offsets func_151380B4 in
// game_161520.c uses), and calls the already-K&R-declared
// func_15143134(data, out, flags) - a real 4th-argument call site
// exists at game_161520.c:465, but here the raw asm never sets $a3
// before the jal (it only spills arg3's OWN value there for reuse
// right after the call), so this reconstruction calls it with 3 args
// and lets the K&R convention leave $a3 holding this function's own
// arg3 untouched, matching target exactly.
// 52 vs target's 53 instructions: every operation, offset and branch
// TARGET matches; the sole gap is the top-level unk1D4 guard, which
// target compiles as a plain (non-likely) `beqz`, while every source
// form tried here (`if (flag) {...} else {...}` and the reverse) picks
// a `beqzl`/`bnezl` (branch-likely) instead - both directions tried,
// same result each time.
// void func_1507E1D0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
//     s32 flag;
//     s32 type;
//     s32 flags;
//     f32 data[3];
//     f32 out[3];
//
//     flag = *(s32 *) ((char *) arg0 + 0x1D4);
//     if (flag != 0) {
//         data[0] = 0.0f;
//         data[1] = *(f32 *) ((char *) arg0 + 0x150) * 30.0f;
//         data[2] = 0.0f;
//
//         type = *(s32 *) arg0;
//         flags = *(s32 *) ((char *) arg0 + 0x1D4);
//         if (type == 1) {
//             flags += 0x300;
//         } else if (type == 0x1E) {
//             flags += 0xC0;
//         }
//
//         func_15143134(data, out, flags);
//
//         *arg1 = out[0];
//         *arg2 = out[1];
//         *arg3 = out[2];
//     } else {
//         *arg1 = *(f32 *) ((char *) arg0 + 0x14);
//         *arg2 = *(f32 *) ((char *) arg0 + 0x18);
//         *arg3 = *(f32 *) ((char *) arg0 + 0x1C);
//     }
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507E1D0.s")
