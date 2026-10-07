#include <ultra64.h>

#include "functions.h"
#include "variables.h"

#include "macros.h"

void func_15000AC0(void) {
    D_800D9E64 = (u8)0;
}

// jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_2DF70/func_15000AD0.s")
// loops!
#pragma GLOBAL_ASM("asm/nonmatchings/game_2DF70/func_15001460.s")

void func_15001970(void) {
    s32 pad;
    s32 tmp;

    D_800B0DE4 = 0;
    D_800DBE63 = 0;
    (*(s32 *)((D_800DBE18))) = 0;
    (*(s32 *)((D_800DBE1C))) = 0;
    D_800DBE20 = 0;
    tmp = D_80091C04[D_800BE9F0];
    D_800DBE24 = 0;
    D_800B0DC0 = allocate_memory(tmp, 1, 0, 0);
    D_800B0DC8 = tmp + D_800B0DC0;
    D_800B0DC4 = D_800B0DC0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_2DF70/func_15001A08.s")
// NON-MATCHING: JUSTREG
// void func_15001A08(void) {
//     s32 sp24;
//     s32 tmp;
//     s32 sp1C;
//
//     tmp = D_800BE9F0;
//     sp24 = D_80091AF0[tmp];
//
//     __osPiGetAccess();
//
//     while ((IO_READ(PI_STATUS_REG) & 3)) {};
//
//     tmp = D_80000308 | 0xB0000D24 | 0xA0000000;
//     sp1C = *(s32*)tmp;
//
//     __osPiRelAccess();
//
//     if (sp1C != 0x98CCE31A) {
//         sp24 <<= 1;
//     }
//
//     D_800B0DDC = allocate_memory(sp24, 1, 0, 0);
//     D_800B0DE0 = D_800B0DDC;
//     D_800B0DCC = 0;
//     D_800B0DD0 = 0;
//     D_800DBE30 = 0;
//     D_800DBE32 = 0;
//     D_800DBE34 = 0;
//     D_800DBE36 = 0;
// }

u16* func_15001B10(void) {
    u16 *temp_v0;

    D_800B0DE0 = ALIGN4(D_800B0DE0);
    D_800B0DCC += 1;

    temp_v0 = (u16*)D_800B0DE0;
    temp_v0[6] = 0;
    temp_v0[2] = 0;

    D_800B0DE0 += 14;
    return temp_v0;
}

void func_15001B5C( u8 arg0) {
    *D_800B0DE0++ = arg0;
}

void func_15001B8C( u16 arg0) {
   D_800B0DE0[0] = (arg0 >> 8);
   D_800B0DE0[1] = arg0 & 0xFF;
   D_800B0DE0 += 2;
}

void func_15001BC8(s32 arg0, s16 *arg1, s16 *arg2) {
    u16 *tmp;
    s16 *sp20;
    s32 i;

    func_1510F800(arg0);
    D_800B0DD8 = 10;
    D_800B0DD4 = 512;
    sp20 = allocate_memory((D_800DBE4C + 1) << 1, 1, 0, 0);

    *sp20 = D_800DBE4C;
    for (i = 0; i < D_800DBE4C; i++) {
        sp20[i + 1] = i;
    }

    tmp = func_15001DE0(0, 0, 32768, 32768, 0, sp20);
    D_800DBE08[arg0] = tmp;
    func_15002560(tmp, 0);
    func_10004074(sp20);

    // regalloc fix:
    if (1) { }

    if (arg1 != 0) {
        *arg1 = D_800B0DCC;
    }
    if (arg2 != 0) {
        *arg2 = D_800B0DD0;
    }
}

void func_15001CEC(s32 arg0) {
    u16 *temp_v0;
    s16 *sp20;
    s32 i;

    func_1510F800(arg0);
    temp_v0 = func_15001B10();

    D_800DBE08[arg0] = temp_v0;

    *((s16*)temp_v0 + 0) = 32768;
    temp_v0[1] = 32767;
    temp_v0[2] = 0;
    temp_v0[3] = -32768;
    temp_v0[4] = 0;
    temp_v0[5] = 0;
    temp_v0[6] = 0;

    sp20 = allocate_memory((D_800DBE4C + 1) << 1, 1, 0, 0);

    *sp20 = D_800DBE4C;
    for (i = 0; i < D_800DBE4C; i++) {
        sp20[i + 1] = i;
    }

    func_15002008(-0x8000, 0x8000, -0x8000, 0x8000, sp20);
    func_10004074(sp20);
}

u16 *func_15001DE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u16 *temp_v0;
    u16 *temp_v0_2;
    u16 *temp_v0_3;
    u16 *temp_v0_4;

    s32 sp7C;
    s32 sp78;

    s32 tmp0;
    s32 tmp1;

    s32 sp44;
    s32 sp48;
    s32 sp4C;
    s32 sp50;
    s32 sp54;
    s32 sp58;

    tmp0 = D_800B0DD8;
    tmp1 = D_800B0DD4;

    sp54 = arg0 - arg2;
    sp50 = arg0 + arg2;
    sp4C = arg1 - arg3;
    sp48 = arg1 + arg3;

    if ((func_15002248(sp54, sp50, sp4C, sp48, &sp7C, &sp78, arg5, &sp58) < tmp0) || (arg2 < tmp1)) {
        temp_v0 = func_15001B10();
        D_800B0DD0 = (D_800B0DD0 + 1);
        temp_v0[0] = sp7C;
        temp_v0[1] = sp78;
        temp_v0[3] = arg2;
        temp_v0[4] = arg0;
        temp_v0[5] = arg1;
        temp_v0[2] = 0;
        temp_v0[6] = 0;
        func_15002008(sp54, sp50, sp4C, sp48, sp58);
    } else {
        temp_v0 = func_15001B10();
        temp_v0[0] = sp7C;
        temp_v0[1] = sp78;
        temp_v0[3] = arg2;
        temp_v0[4] = arg0;
        temp_v0[5] = arg1;
        temp_v0[2] = 0;

        temp_v0_2 = func_15001DE0(arg0 - (arg2 >> 1), arg1 - (arg3 >> 1), arg2 >> 1, arg3 >> 1, 0, sp58);
        temp_v0[6] = (s32)temp_v0_2 - (s32)temp_v0;
        temp_v0_3 = func_15001DE0(arg0 - (arg2 >> 1), (arg3 >> 1) + arg1, arg2 >> 1, arg3 >> 1, 0, sp58);
        temp_v0_2[2] = (s32)temp_v0_3 - (s32)temp_v0_2;
        temp_v0_4 = func_15001DE0((arg2 >> 1) + arg0, arg1 - (arg3 >> 1), arg2 >> 1, arg3 >> 1, 0, sp58);
        temp_v0_3[2] = (s32)temp_v0_4 - (s32)temp_v0_3;
        temp_v0_4[2] = (s32)func_15001DE0((arg2 >> 1) + arg0, (arg3 >> 1) + arg1, arg2 >> 1, arg3 >> 1, 0, sp58) - (s32)temp_v0_4;
    }
    func_10004074(sp58);
    return temp_v0;
}

// 3 loops
#pragma GLOBAL_ASM("asm/nonmatchings/game_2DF70/func_15002008.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_2DF70/func_15002248.s")
// NON-MATCHING: recursive tree relink (sibling-offset fields at +4 and
// +0xC, both s16 byte-offsets relative to the current node - +0xC is a
// "first child" offset, +4 is a "prev/parent" back-offset computed
// lazily on first visit). First ~18 instructions verified byte-perfect
// against target including two branch-likely selections that needed
// specific source shapes: the outer "compute back-offset if unset" had
// to duplicate the read in both the true and false arms of the child-
// exists check (not an early-return guard) for IDO to autogenerate
// target's exact bnel-then-duplicate-lh pattern, and the "arg1==0"
// ternary needed its true case (arg1!=0) written first to get target's
// beqz polarity. Blocked on one remaining gap: inside the child-walk,
// target reloads the child's +4 field TWICE from memory (once as $t7
// for the has-more-children check, once as a fresh separate $t8 for
// the sibling-offset value) with no apparent reason not to reuse the
// first value; every C form tried (early-return guard, if/else with
// the read duplicated in both arms, an aliasing-workaround cast) gets
// this CSE'd into a single read plus a spurious "move" instead,
// shifting every following instruction by one and swapping the
// $a1/$v1 register pair for target's $t7/$t8.
// void func_15002560(void *arg0, void *arg1) {
//     void *s1;
//     s32 v0;
//     s32 t8;
//
// loop:
//     if (arg0 == 0) {
//         return;
//     }
//     if (*(s16 *) ((char *) arg0 + 4) == 0) {
//         if (arg1 != 0) {
//             v0 = (char *) arg1 - (char *) arg0;
//         } else {
//             v0 = 0;
//         }
//         *(s16 *) ((char *) arg0 + 4) = v0;
//     }
//     v0 = *(s16 *) ((char *) arg0 + 0xC);
//     if (v0 == 0) {
//         return;
//     }
//     s1 = (char *) arg0 + v0;
//     if (*(s16 *) ((char *) s1 + 4) == 0) {
//         goto tail;
//     }
//     t8 = *(s16 *) ((char *) s1 + 4);
// inner:
//     {
//         void *s0 = (char *) s1 + t8;
//         func_15002560(s1, s0);
//         s1 = s0;
//     }
//     if (*(s16 *) ((char *) s1 + 4) != 0) {
//         t8 = *(s16 *) ((char *) s1 + 4);
//         goto inner;
//     }
// tail:
//     arg0 = s1;
//     goto loop;
// }
int func_15002560(void *arg0, void *arg1) {
    char *s1;
    char *s0;
    s32 v0;

loop:
    if (arg0 == 0) {
        return;
    }
    if (*(s16 *) ((char *) arg0 + 4) == 0) {
        if (arg1 != 0) {
            v0 = (char *) arg1 - (char *) arg0;
        } else {
            v0 = 0;
        }
        *(s16 *) ((char *) arg0 + 4) = v0;
    }
    v0 = *(s16 *) ((char *) arg0 + 0xC);
    if (v0 == 0) {
        return;
    }
    s1 = (char *) arg0 + v0;
    while (*(s16 *) (s1 + 4) != 0) {
        s0 = s1;
        s0 += *(s16 *) (s1 + 4);
        func_15002560(s1, s0);
        s1 = s0;
    }
    arg0 = s1;
    goto loop;
}

void func_150025FC(void) {
    s32 tmp0;
    s32 tmp1;
    s32 tmp2;
    s32 tmp3;

    tmp0 = D_800DBE2A;
    tmp1 = D_800DBE2C;

    D_800DBE28 = (((tmp0 + 7) / 8) + 0xF) & 0xFFF0;
    tmp2 = func_1502B5C8(0, 2, 5, D_800BE9F0 << 1);
    tmp3 = func_1502B5C8(0, 2, 5, (D_800BE9F0 << 1) + 1);
    if (tmp2 == 0) {
        D_800BE5D0 = 0;
    } else {
        func_150183D0(D_800DBE28, tmp1, tmp2, tmp3);
        func_10004074(tmp3);
    }
}

void func_150026C4(s32 arg0) {
    D_800DBE38 = 0;
    func_1510F800(arg0);
}

void func_150026E8(s32 arg0) {
    D_800DBE18[arg0] = D_800DBE38;
    D_800DBE4C = D_800DBE38;
    D_800B0DE4 += D_800DBE38;
}

void func_15002724(s32 arg0) {
    D_800DBE38 += func_150027F8(arg0);
}

// NON-MATCHING: register-choice gap only, logic and instruction shapes
// verified identical to target. Bump-allocates three sub-buffers (sizes
// count*12, count*8, count*4, where count=D_800DBE38) from the 4-byte-
// aligned heap pointer D_800B0DC0, recording each sub-buffer's start
// address into D_800DBDD8[idx]/D_800DBDE8[idx]/D_800DBDF8[idx] (idx =
// D_800DBE50), then calls func_1510F800() and resets D_800DBE38. Every
// instruction's opcode/operand matches target (including the identical
// "x*4-x, then *4" constant-multiplication strategy IDO picks for *12),
// but target puts count in $a2 and idx in $a0 for the multiply/index
// steps while every source variant tried here (both declaration orders,
// inline vs named locals, load-order swaps) puts count in $a0 and idx
// in $a2/$a1 instead - the opposite pairing, decided by something other
// than source order since swapping it in C had no effect.
// void func_15002754(void) {
//     s32 count = D_800DBE38;
//     s32 idx = D_800DBE50;
//
//     D_800B0DC0 = (D_800B0DC0 + 3) & ~3;
//     D_800DBDD8[idx] = D_800B0DC0;
//     D_800B0DC0 += count * 12;
//     D_800DBDE8[idx] = D_800B0DC0;
//     D_800B0DC0 += count * 8;
//     D_800DBDF8[idx] = D_800B0DC0;
//     D_800B0DC0 += count * 4;
//     func_1510F800();
//     D_800DBE38 = 0;
// }
void func_15002754(void) {
    D_800B0DC0 = (D_800B0DC0 + 3) & ~3;
    D_800DBDD8[D_800DBE50] = D_800B0DC0;
    D_800B0DC0 += D_800DBE38 * 12;
    D_800DBDE8[D_800DBE50] = D_800B0DC0;
    D_800B0DC0 += D_800DBE38 * 8;
    D_800DBDF8[D_800DBE50] = D_800B0DC0;
    D_800B0DC0 += D_800DBE38 * 4;
    func_1510F800(D_800DBE50);
    D_800DBE38 = 0;
}


s32 func_150027F8(s8 *arg0) {
    s8 c;
    s32 v0;
    s32 v1;
    s32 nib;
    s32 one;

    if (arg0 == NULL) {
        return 0;
    }
    v0 = 0;
    v1 = 0;
    c = *arg0;
    one = 1;
    if (c != -0x21) {
        nib = c >> 4;
        do {
            v0 += 1;
            if (one == nib) {
                v1 += 4;
            } else if (c == 6) {
                v1 += 2;
            } else if (c == 5) {
                v1 += 1;
            }
            c = arg0[v0 << 3];
            if (c == -0x21) {
                break;
            }
            nib = c >> 4;
        } while (1);
    }

    return v1;
}

s32 func_15002878(void) {
    s32 i;
    s32 tmp;
    s32 highest;

    highest = (*(s32 *)((D_800DBE18)));

    for (i = 0; i < 3; i++) {
        tmp = D_800DBE1C[i];
        if (highest < tmp) {
            highest = tmp;
        }
    }

    return highest;
}

// 12 loops!
#pragma GLOBAL_ASM("asm/nonmatchings/game_2DF70/func_150028BC.s")

void func_15002F40(s32 arg0) {
    if (arg0 == 50 || arg0 == 51) {
        D_800DBE64 = 150.0f;
        return;
    }
    if (D_800BE616) {
        D_800DBE64 = 85.0f;
        return;
    }
    D_800DBE64 = 50.0f;
}

s32 func_15002FA0(s32 arg0) {
    return arg0 ^ 0xF0F0F0F0;
}

void func_15002FB4(s32 arg0) {
    struct00 *sp3C; // TBD
    s32 sp38;
    s32 sp34;
    struct104 *temp_v0;
    s32 sp2C;

    sp3C = func_1502B6BC(&sp34, 0, &sp38, 2, 21, arg0);
    if ((sp38 != 0) && ((sp3C->unk4 << 8) != 0)) {
        D_800B0DF0 = sp3C->unk0;
        if (sp34 == 0) {
            D_8003C8E0 = 0xC000037;
            func_150AD770();
        }
        if (D_800B0DF0 == 0) {
            D_8003C8E0 = 0xC000037;
            func_150AD770();
        }
    }
    osPiReadIo(func_15002FA0(0x40F0FAAC), &sp2C);
    sp2C = func_15002FA0(sp2C);
    if (sp2C != 0xE7B00F09) {
        temp_v0 = D_800B0DF0;
        temp_v0->unk12 >>= 1;
    }

    temp_v0 = D_800B0DF0;
    if (temp_v0->unk12 != 0) {
        D_800D2F3C = temp_v0->unk12;
        D_800D2F40 = sp3C->unk8;
    } else {
        D_800D2F3C = 0U;
        D_800D2F40 = 0;
    }

    if ((D_8008FD90 >= 2) && (temp_v0->unk8 == 4)) {
        temp_v0->unk8 = 2U;
    }
}

void func_1500310C(void) {
}
