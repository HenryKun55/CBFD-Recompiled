#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150ED638();

void func_150FDD10(s32 arg0) {
    struct127 *obj;

    func_15103828();
    if (D_800C35EA == 1) {
        obj = gObjects;
        do {
            if (obj->id == 0x28) {
                func_150ED638(obj, 0x14, 0x14);
            }
            obj++;
        } while (obj != (struct127 *)&D_800D121C);
    }
}
