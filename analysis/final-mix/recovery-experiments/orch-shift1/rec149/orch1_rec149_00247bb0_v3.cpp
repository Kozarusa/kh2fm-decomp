#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u8* D_0035ed34;
void func_00247bb0() {
    s32 offset = 0;
    s32 count = 3;
    do {
        if (func_00139d78(D_0035ed34 + offset)) {
            u8* object = (u8*)(offset + (u32)D_0035ed34);
            ((void (*)(u8*))(*(u32*)(*(u32*)object + 20)))(object);
        }
        --count;
        offset += 408;
    } while (count >= 0);
}


