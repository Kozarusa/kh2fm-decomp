#include "../common/types.h"

extern "C" s32 D_01c60bd0[];
extern "C" void func_00188340(u8*, s32, s32*, s32);

void func_00188430(u8* object, s32 first, s32 second) {
    // why: volatile stores keep store order
    volatile s32* slot = D_01c60bd0;
    slot[0] = *(s32*)(object + 136);
    slot[1] = first;
    slot[2] = second;
    func_00188340(object, 7, D_01c60bd0, 3);
}
