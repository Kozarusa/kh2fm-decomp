#include "../common/types.h"
extern "C" void* D_00350de8;
extern "C" u32 D_01c94040[];
extern "C" s32 func_001b1490(void*);
extern "C" u32 func_00168b38(...);
u32 func_001aeb80() {
    s32 index = 0;
    s32 object = func_001b1490(D_00350de8);
    u32* pointer = D_01c94040;
    u32 result;
    do {
        result = func_00168b38(object, 2, index++);
        u32 value = *(u32*)(result + 8);
        *pointer++ = value;
    } while (index < 19);
    return result;
}

