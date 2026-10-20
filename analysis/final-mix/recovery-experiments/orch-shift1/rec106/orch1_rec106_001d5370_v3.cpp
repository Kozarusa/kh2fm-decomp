#include "../common/types.h"
extern "C" u32 func_00168b38(...);

void func_001d5370(u32* output, u64 handle, s32 index) {
    s32 first = func_00168b38(handle, -1LL);
    s32 second = func_00168b38(handle, -1LL, index + 1);
    u32 high = *(u32*)(second + 8);
    u32 low = *(u32*)(first + 8);
    output[1] = high;
    output[0] = low;
}
