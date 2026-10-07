#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1C0840/func_15193390.s")

void func_151934B4(void *arg0) {
    s32 temp_v1;
    f32 pos[3];
    s16 temp_v0;

    if ((*(s16 *)((char *)(arg0) + 0xA4)) < (*(s16 *)((char *)(arg0) + 0x96))) {
        temp_v0 = (*(s16 *)((char *)(arg0) + 0xAA));
        temp_v1 = temp_v0 >> 2;
        (*(s16 *)((char *)(arg0) + 0xA4)) = (temp_v1 * 0x18) / 3;
        (*(s16 *)((char *)(arg0) + 0xA2)) = (temp_v1 * 6) / 3;
        (*(s16 *)((char *)(arg0) + 0xAA)) = temp_v0 + D_800BE9E4;
        return;
    }
    (*(s16 *)((char *)(arg0) + 0x94)) = (*(s16 *)((char *)(arg0) + 0x94)) + 1;
    if ((*(s16 *)((char *)(arg0) + 0x94)) >= 0x15) {
        (*(s16 *)((char *)(arg0) + 0x94)) = 0x14;
    }
    (*(s16 *)((char *)(arg0) + 0x9E)) = (*(s16 *)((char *)(arg0) + 0x9E)) - ((s32) ((*(s16 *)((char *)(arg0) + 0x94)) * D_800BE9E4) >> 1);
    if ((*(s16 *)((char *)(arg0) + 0x9E)) < (*(s16 *)((char *)(arg0) + 0xA6))) {
        if ((*(s8 *)((char *)(arg0) + 0xB3)) == 1) {
            pos[0] = (*(s16 *)((char *)(arg0) + 0x9C));
            pos[1] = (*(s16 *)((char *)(arg0) + 0xA6));
            pos[2] = (*(s16 *)((char *)(arg0) + 0xA0));
            func_151DBCBC(5, 30.0f, 0xFF, NULL, pos, (*(u8 *)((char *)(arg0) + 0xC)), (*(u8 *)((char *)(arg0) + 1)));
        }
        (*(s16 *)((char *)(arg0) + 0x98)) = -1;
    }
}
