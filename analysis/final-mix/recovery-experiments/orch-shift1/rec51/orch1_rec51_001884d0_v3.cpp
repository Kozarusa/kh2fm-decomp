#include "../common/types.h"

extern "C" s32 D_01c60be0[];
extern "C" u8* func_00187ab8(s32, s32);
extern "C" void func_00188398(u8*, u16, s32*, s32);

void func_001884d0(u8* object, s32* source) {
    s32 owner = *(s32*)(object + 140);
    if (owner != 0) {
        u8* entry = func_00187ab8(owner, source[0]);
        if (entry != 0) {
            D_01c60be0[0] = *(s32*)(object + 136);
            D_01c60be0[1] = source[1];
            u16 id = *(u16*)(entry + 20);
            func_00188398(object, id, D_01c60be0, 2);
        }
    }
}
