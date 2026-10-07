#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800CBD4C;

void func_15015910(void) {
    D_800CBD4C = 0;
}

struct func_15015920_s {
    u32 start;
    u32 end;
};
extern struct func_15015920_s D_80082F80[];
void func_10004074();
void func_15015A38();

void func_15015920(s16 arg0) {
    u8 *buf;
    u8 *p;
    s32 i;

    buf = (u8 *)func_10003C6C(0x2800, 1, 2, 1, 0);
    func_10004514(D_80082F80[arg0].start, buf, D_80082F80[arg0].end - D_80082F80[arg0].start, 1);
    p = buf;
    i = 0;
    while ((u32)(p + 0xF) < (u32)(buf + D_80082F80[arg0].end - D_80082F80[arg0].start)) {
        func_15015A38(p, i, arg0);
        p += (p[4] << 24) + (p[5] << 16) + (p[6] << 8) + p[7];
        i++;
    }
    func_10004074(buf);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_42DC0/func_15015A38.s")
