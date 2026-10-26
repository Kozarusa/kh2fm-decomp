#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" s32 func_0024dfe0();
extern "C" u8* D_0035ede8;

void func_0024e530() {
    s32 index = 0;
    s32 offset = 0;
    while (index < func_0024dfe0()) {
        index++;
        if (func_00139d78(D_0035ede8 + offset)) {
            u8* object = (u8*)(offset + (u32)D_0035ede8);
            ((void (*)(u8*))(*(u32*)(*(u32*)object + 20)))(object);
        }
        offset += 408;
    }
}
