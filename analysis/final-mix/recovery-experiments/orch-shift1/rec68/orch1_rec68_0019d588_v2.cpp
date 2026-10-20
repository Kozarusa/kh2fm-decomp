#include "../common/types.h"
extern "C" u32 D_0036d3b8[];
extern "C" s32 func_0013e610(u32);
extern "C" u64 func_0019d548(...);

void func_0019d588(u8* object, s32 index) {
    if (index != *(s32*)(object + 4)) {
        func_0019d548();
    }
    if (index != 0 && *(s32*)(object + 8) == 0) {
        *(s32*)(object + 8) = func_0013e610(D_0036d3b8[index - 1]);
    }
    *(s32*)(object + 4) = index;
}
