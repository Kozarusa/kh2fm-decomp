#include "../common/types.h"
extern "C" s32 D_00374ca4;
extern "C" s32 D_00374ca8;
extern "C" u32 func_002b23e0(...);

s32 func_002b1aa0(void) {
    u32* pointer = (u32*)func_002b23e0(-1);
    u32 flags = *pointer;
    if (flags & 0x04000000) {
        return 20690;
    }
    if (flags & 0x10000000) {
        return D_00374ca4;
    }
    return D_00374ca8;
}
