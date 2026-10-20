#include "../common/types.h"
extern "C" u32 func_001a80c8(...);
extern "C" s8 D_00374488[];
s32 func_002914a8(u32 unused, u32 value) {
    s32 result = 0;
    u8* object = (u8*)func_001a80c8(value);
    if (D_00374488[0] >= 0) {
        asm volatile("" ::: "memory"); // why: retain original table reload after initial sign check
        u32 key = object[2];
        s8* pointer = D_00374488;
        do {
            s32 current = *pointer;
            ++pointer;
            if (key == current) { result = 1; break; }
        } while (*pointer >= 0);
    }
    return result;
}


