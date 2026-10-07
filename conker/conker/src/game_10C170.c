#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_10C170/func_150DECC0.s")

typedef struct { f32 x, y, z; } func_150DF334_v;
struct func_150DF334_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x1B];
    func_150DF334_v pos;
};
s32 func_1504697C(func_150DF334_v *, s32, f32, f32 *);
void func_150E83AC(func_150DF334_v *, s16, u8, u8);
void func_151A9834(func_150DF334_v *, f32, f32, f32 *, s32, s32, s32, u8, u8);

void func_150DF334(struct func_150DF334_s *arg0) {
    f32 out[10];
    u8 found = 0;
    func_150DF334_v v;
    func_150DF334_v tmp;
    func_150DF334_v copy;
    func_150DF334_v *p;
    func_150DF334_v *q;

    tmp.x = arg0->pos.x;
    tmp.y = arg0->pos.y + 500.0f;
    tmp.z = arg0->pos.z;
    p = &arg0->pos;
    if (func_1504697C(&tmp, 0, tmp.y - 1000.0f, out)) {
        v.x = p->x;
        v.y = out[0];
        v.z = p->z;
        found = 1;
    }
    q = found ? &v : p;
    func_150E83AC(q, (u32)func_150ADA20() % 62 + 120, arg0->unkC, arg0->unk1);
    p = found ? &v : &arg0->pos;
    copy = *p;
    copy.y += 500.0f;
    func_151A9834(&copy, copy.y - 1000.0f, 250.0f, out, (u32)func_150ADA20() % 3 + 3, 1, 0, arg0->unkC, arg0->unk1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10C170/func_150DF4B8.s")
