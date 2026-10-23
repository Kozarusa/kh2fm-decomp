#include "../common/types.h"
extern "C" u32 func_001d86a0(...);
extern "C" u32 D_00375a40[];

u32 func_002d28f8(u32 unused, s32 multiplier, s32 index) {
    u32 counts[3] = {D_00375a40[0], D_00375a40[1], D_00375a40[2]};
    return func_001d86a0(counts[index] * multiplier, 0);
}
