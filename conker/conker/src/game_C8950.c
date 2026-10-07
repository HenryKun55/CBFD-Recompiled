#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct249 *func_1509B704(s16 arg0);
void func_1509C120();
void func_1509C3A0();
s32 func_1509C2A4();


void func_1509B4A0(s32 arg0, s32 arg1) {
    s32 i;

    if(0) {};

    D_8003C8E0 = 0x5000000;
    func_1509C120();
    func_15096970();

    for (i = 0; i < D_800D2F3C; i++) {
        if (func_1509CBD4(D_800D2F40[i])) {
            func_1509B5AC(D_800D2F40[i], arg1);
        }
    }

    func_1509C3A0();
    D_8003C8E0 = 0;
}

u16 *func_1509B570(s32 arg0) {
    struct248 *temp_v0;
    u16 res;

    temp_v0 = func_1509B704(arg0);
    if (temp_v0 != 0) {
        res = temp_v0->unkA;
        return (s32)temp_v0 + (res & 0xFFFF);
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C8950/func_1509B5AC.s")

struct249 *func_1509B704( s16 arg0) {
    struct249 *tmp;
    s32 mask = 0xFFFF03FF;
    s32 i;

    tmp = D_800D2F48.unk4;
    for (i = 0; i < D_800D2F48.length; i++) {
        if (arg0 == (tmp->unk0 & mask)) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}


void func_1509B764(struct249 *arg0) {
    if (D_800D2F48.length == 1) {
        D_800D2F48.unk4 = NULL;
        D_800D2F48.unk8 = NULL;
    } else {
        if (arg0 == D_800D2F48.unk4) {
            D_800D2F48.unk4 = arg0->next;
            arg0->next->prev = NULL;
        } else {
            arg0->prev->next = arg0->next;
        }
        if (arg0 == D_800D2F48.unk8) {
            D_800D2F48.unk8 = arg0->prev;
            arg0->prev->next = NULL;
        } else {
            arg0->next->prev = arg0->prev;
        }
    }
    func_10004074(arg0);
    D_800D2F48.length--;
}

// NON-MATCHING: full semantics recovered and verified via isolated
// harness - the insertion counterpart to func_1509B764's removal:
// inserts arg0 into the D_800D2F48 list in descending order by its
// masked key (unk0 & 0xFFFF03FF), searching backward from the tail
// (the same mask constant already used by func_1509B704) until a node
// with a smaller key is found (insert after it, with a tail-append
// special case) or the list is exhausted (insert at head). Three of
// four setup-register roles (length/newKey/one of tail-or-cursor) were
// recoverable by trying different initializer orderings, and the loop
// body's exact instruction shape (including target's two dead
// delay-slot-duplicate stores) was reproduced, but getting the loop
// body shape right and getting the head/tail-insertion block ORDER
// right (target lays out the general middle-insertion case
// immediately after the loop and the insert-at-head fallback last;
// the natural C control flow here keeps insert-at-head immediately
// after the loop instead) turned out to be mutually exclusive - every
// restructuring tried to fix one regressed the other.
// void func_1509B810(struct249 *arg0) {
//     s32 length;
//     struct249 *tail;
//     struct249 *cursor;
//     s32 newKey;
//     s32 count;
//
//     tail = D_800D2F48.unk8;
//     cursor = tail;
//     newKey = arg0->unk0 & (s32) 0xFFFF03FF;
//     length = D_800D2F48.length;
//
//     if (length == 0) {
//         D_800D2F48.unk4 = arg0;
//         D_800D2F48.unk8 = arg0;
//         arg0->next = NULL;
//         arg0->prev = NULL;
//         D_800D2F48.length++;
//         return;
//     }
//
//     if (length > 0) {
//         count = 0;
//         do {
//             count++;
//             if ((cursor->unk0 & (s32) 0xFFFF03FF) < newKey) {
//                 goto insert_after;
//             }
//         } while (count < length && (cursor = cursor->prev, 1));
//     }
//
//     {
//         struct249 *head = D_800D2F48.unk4;
//         D_800D2F48.unk4 = arg0;
//         arg0->prev = NULL;
//         arg0->next = head;
//         head->prev = arg0;
//         D_800D2F48.length++;
//         return;
//     }
//
// insert_after:
//     arg0->prev = cursor;
//     if (cursor != tail) {
//         arg0->next = cursor->next;
//         cursor->next->prev = arg0;
//         cursor->next = arg0;
//     } else {
//         arg0->next = NULL;
//         cursor->next = arg0;
//         D_800D2F48.unk8 = arg0;
//     }
//     D_800D2F48.length++;
// }
void func_1509B810(struct249 *arg0) {
    s32 mask = 0xFFFF03FF;
    struct249 *cursor;
    s32 key;
    s32 i;

    cursor = D_800D2F48.unk8;
    key = arg0->unk0 & mask;

    if (D_800D2F48.length == 0) {
        D_800D2F48.unk4 = arg0;
        D_800D2F48.unk8 = arg0;
        arg0->next = NULL;
        arg0->prev = NULL;
        D_800D2F48.length++;
        return;
    }
    for (i = 0; i < D_800D2F48.length; i++) {
        if ((cursor->unk0 & mask) < key) {
            if (cursor == D_800D2F48.unk8) {
                arg0->prev = cursor;
                arg0->next = NULL;
                cursor->next = arg0;
                D_800D2F48.unk8 = arg0;
                D_800D2F48.length++;
                return;
            }
            arg0->prev = cursor;
            arg0->next = cursor->next;
            cursor->next->prev = arg0;
            cursor->next = arg0;
            D_800D2F48.length++;
            return;
        }
        cursor = cursor->prev;
    }
    cursor = D_800D2F48.unk4;
    D_800D2F48.unk4 = arg0;
    arg0->prev = NULL;
    arg0->next = cursor;
    cursor->prev = arg0;
    D_800D2F48.length++;
}

void func_1509B8FC(arg0)
    s16 arg0;
{
    struct248 *temp_v0;
    s16 sp18[2];

    temp_v0 = func_1502B5C8(&sp18, 2, 20, arg0);
    temp_v0->unk0 |= arg0;
    temp_v0->unk2 = D_800BE9F0;
    func_1509B950(temp_v0);
}

// NON-MATCHING: register-choice gap only from the "unk6" read onward -
// same instruction count (15) and identical opcodes/shape for that
// whole block, just renamed temp registers. Two real structural fixes
// were needed to get this far: (1) target computes the first 8-byte
// alignment pad as "8 - (addr & 7)" via its OWN named temp (subu from
// the constant 8, then a separate addu with the base) rather than the
// mathematically-equivalent "(addr & 7)" subtracted directly with the
// +8 folded in afterward - writing "pad = 8 - (...)" as its own
// statement (not inlined into the addition) was required to get IDO to
// pick target's subu-from-8-then-add shape instead of a subu-then-
// addiu-8 shape; (2) target stores the pre-final-alignment value to
// unk4 (A6020004) even though it's immediately overwritten by the
// final aligned value two instructions later - a genuine dead store in
// target that IDO's optimizer eliminates by default for this pattern;
// marking that specific write through a `volatile u16 *` cast was
// needed to force it to survive. void func_1509B950(void *arg0) {
//     u16 v0;
//     u16 t1;
//     u16 t0;
//     u16 pad;
//     u16 final;
//     void *newBuf;
//
//     v0 = *(u16 *) ((char *) arg0 + 4);
//     t1 = *(u16 *) ((char *) arg0 + 6);
//     pad = 8 - (((u32) arg0 + v0) & 7);
//     t0 = v0 + pad;
//     v0 = t0 + t1;
//     final = (v0 - (((u32) arg0 + v0) & 7)) + 8;
//     *(volatile u16 *) ((char *) arg0 + 4) = v0;
//     *(u16 *) ((char *) arg0 + 0xA) = t0;
//     *(u16 *) ((char *) arg0 + 4) = final;
//     newBuf = allocate_memory(final, 0xFF, 2, 0);
//     if (newBuf == 0) {
//         while (1) {
//         }
//     }
//     bcopy(arg0, newBuf, *(u16 *) ((char *) arg0 + 4));
//     bzero((char *) newBuf + *(u16 *) ((char *) newBuf + 0xA), *(u16 *) ((char *) newBuf + 6));
//     func_10004074(arg0);
//     return newBuf;
// }
int func_1509B950(struct248 *arg0) {
    struct248 *newBuf;
    u32 pad;
    pad = 8 - (((u32)arg0 + arg0->unk4) & 7);
    arg0->unkA = arg0->unk4 + pad;
    arg0->unk4 = arg0->unkA + arg0->unk6;
    arg0->unk4 += 8 - (((u32)arg0 + arg0->unk4) & 7);
    newBuf = (struct248 *)allocate_memory(arg0->unk4, 0xFF, 2, 0);
    if (newBuf == NULL) {
        while (1) {
        }
    }
    bcopy(arg0, newBuf, arg0->unk4);
    bzero((u8 *)newBuf + newBuf->unkA, newBuf->unk6);
    func_10004074(arg0);
    return (int)newBuf;
}

void func_1509C228(void);
s32 func_150ADAF0(struct249 *, s32);
extern u8 D_800D2E69;

void func_1509BA04(s32 arg0) {
    s32 mask = 0xFFFF03FF;
    s32 i;
    s32 length;
    struct249 *next;
    struct249 *cur;
    s32 bit;
    s32 byte;
    s32 id;

    cur = D_800D2F48.unk4;
    length = D_800D2F48.length;
    if (D_800D2E69 != 0) {
        func_1509C228();
        D_800D2E69 = 0;
    }
    for (i = 0; i < length; i++) {
        id = cur->unk0 & mask;
        byte = id >> 3;
        bit = 1 << (id & 7);
        next = cur->next;
        if ((*(u8 *)(byte + (u32)D_800D2E4C) & bit) && (arg0 == 0)) {
            func_1509B764(cur);
            ((u8 *)&D_800D2E70)[id] = 3;
        } else if ((arg0 != 0) || (cur->unk0 & 0x8000) || ((cur->unk0 & 0x1000) && (D_800BE9F0 != *(u16 *)((u8 *)cur + 2)))) {
            D_8003C8E0 = 0x06000001;
            func_150ADAF0(cur, 3);
            D_8003C8E0 = 0;
            func_1509B764(cur);
            if (!(*(u8 *)(byte + (u32)D_800D2E4C) & bit)) {
                ((u8 *)&D_800D2E70)[id] = 0;
            } else {
                ((u8 *)&D_800D2E70)[id] = 3;
            }
        }
        cur = next;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C8950/func_1509BBA0.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/game_C8950/func_1509BE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C8950/func_1509BFB0.s")

// need a bigger brain
// NON-MATCHING: randomly picks an index 0-3, and (skipping entirely
// unless D_800D2E4C is null or a second random roll has bit 4 set)
// allocates one new 0x1B-byte block per index up to and including the
// pick, frees every allocated block except the picked one, then
// either promotes the picked block to D_800D2E4C directly (if it was
// previously null) or bcopy's the old D_800D2E4C's contents into the
// newly-picked block, swaps it in, and frees the old one.
// void func_1509C120(void) {
//     s32 idx;
//     struct102 *old;
//     s32 arr[4];
//     s32 i;
//
//     idx = func_150ADA20() & 3;
//     old = D_800D2E4C;
//
//     if (old == 0 || (func_150ADA20() & 4) != 0) {
//         if (idx >= 0) {
//             i = 0;
//             do {
//                 arr[i] = allocate_memory(0x1B, 0xFF, 2, 0);
//                 i++;
//             } while (i <= idx);
//         }
//
//         if (idx >= 0) {
//             i = 0;
//             do {
//                 if (i != idx) {
//                     func_10004074((void *) arr[i]);
//                 }
//                 i++;
//             } while (i <= idx);
//         }
//
//         {
//             s32 kept = arr[idx];
//             if (old != 0) {
//                 D_800D2E4C = (struct102 *) kept;
//                 bcopy(old, D_800D2E4C, 0x1B);
//                 func_10004074(old);
//             } else {
//                 D_800D2E4C = (struct102 *) kept;
//             }
//         }
//     }
// }
// 69 vs target's 66 instructions. The two fill/consume loops each
// needed a guarded do-while (matching target's own two separate
// bound checks) rather than a `for` loop, which duplicated its guard
// against an outer `if`. Computing the picked block's address once
// into a local (`kept`) before branching on `old != 0` - rather than
// re-expressing `arr[idx]` in both branches - closed most of a larger
// gap by letting the two branches share one address computation, but
// target still needs about 3 fewer instructions in that tail section
// that further restructuring didn't close.
void func_1509C120(void) {
    s32 idx;
    s32 i;
    s32 arr[4];
    struct102 *old;

    idx = func_150ADA20() & 3;
    old = D_800D2E4C;
    if ((old != NULL) && !(func_150ADA20() & 4)) {
        return;
    }
    for (i = 0; i <= idx; i++) {
        arr[i] = allocate_memory(0x1B, 0xFF, 2, 0);
    }
    for (i = 0; i <= idx; i++) {
        if (i != idx) {
            func_10004074(arr[i]);
        }
    }
    D_800D2E4C = arr[idx];
    if (old != NULL) {
        bcopy(old, D_800D2E4C, 0x1B);
        func_10004074(old);
    }
}

void func_1509C228(void) {
    if ((D_800D2E68 & 8) || (D_800D2E4C->unkF & 1)) {
        func_1509BFB0(2, 0x2000, 0x36, 0, 1);
        return;
    }
    func_1509BFB0(2, 0x2000, 0x36, 1, 1);
}

s32 func_1509C2A4(void) {
    s32 temp_v0 = D_800BE9F0;
    if ((temp_v0 == 3) ||
        (temp_v0 == 5) ||
        (temp_v0 == 9) ||
        (temp_v0 == 13) ||
        (temp_v0 == 15) ||
        (temp_v0 == 17) ||
        (temp_v0 == 21) ||
        (temp_v0 == 22) ||
        (temp_v0 == 24) ||
        (temp_v0 == 26) ||
        (temp_v0 == 29) ||
        (temp_v0 == 31) ||
        (temp_v0 == 32) ||
        (temp_v0 == 33) ||
        (temp_v0 == 34) ||
        (temp_v0 == 36) ||
        (temp_v0 == 37) ||
        (temp_v0 == 42) ||
        (temp_v0 == 43) ||
        (temp_v0 == 45) ||
        (temp_v0 == 48) ||
        (temp_v0 == 51) ||
        (temp_v0 == 52) ||
        (temp_v0 == 56) ||
        (temp_v0 == 62) ||
        (temp_v0 == 63) ||
        (D_800D2E44 != 0)
      ) {
        return 0;
    }
    return 1;
}

void func_1509C3A0(void) {
    if ((D_800D2E43 != 0) && (D_800D2E44 == 0) && (func_1509C2A4() != 0)) {
        D_800BE3DF = (s8) D_800BE9F4;
        if (D_800C35C4 == 0) {
            func_15007718(D_8008FDA8);
        }
        D_800D2E43 = 0;
    }
}


s32 func_1509C414(s32 arg0) {
    return ((D_800D2E4C->unk3 & 1) << 0xA) + arg0 + 0x1400;
}
