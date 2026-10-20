#include "../common/types.h"
extern "C" u32 func_00239bf8(s32, s32);

void func_001ac2a8(s32* object, s32 first, s32 second, s32 third) {
    s32 saved_second = second;
    if (first != 0) {
        func_00239bf8((s32)(object + 3), first + 1);
    }
    object[2] = third;
    // why: keeps store order
    asm volatile("" ::: "memory");
    object[0] = first;
    // why: keeps store order
    asm volatile("" ::: "memory");
    object[1] = saved_second;
}
