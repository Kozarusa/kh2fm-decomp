#include "../common/types.h"
extern "C" s32 func_002a9d68(void);

u32 func_002abdc8() {
    u32 result = (u32)func_002a9d68() + 320;
    u32 index = 0;
    do {
        u32 mask = 1u << (index & 31);
        u32* pointer = (u32*)((index >> 5) * 4 + result);
        ++index;
        u32 previous = *pointer;
        if ((previous & mask) == 0) {
            *pointer = previous | mask;
        }
    } while ((s32)index < 4);
    return result;
}
