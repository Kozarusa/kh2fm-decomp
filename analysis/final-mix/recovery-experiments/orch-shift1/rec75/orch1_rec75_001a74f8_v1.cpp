#include "../common/types.h"
extern "C" u32 D_01c6cb78;
extern "C" u32 func_001b8e88(u64);
extern "C" u32 func_0019c218(u32, u32);

u32 func_001a74f8() {
    u32 result = func_001b8e88(0);
    *(s32*)(D_01c6cb78 + 0x9b0) = 0;
    return func_0019c218(D_01c6cb78, result);
}
