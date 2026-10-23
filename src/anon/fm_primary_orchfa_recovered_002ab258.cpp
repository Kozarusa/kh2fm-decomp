#include "../common/types.h"
extern "C" s32 func_002a9d68(void);

u32 func_002ab258(u32 value) {
    u32 result = (u32)func_002a9d68() + 136;
    u32* pointer = (u32*)((value >> 5) * 4 + result);
    u32 previous = *pointer;
    u32 mask = 1u << (value & 31);
    if ((previous & mask) == 0) {
        *pointer = previous | mask;
    }
    return result;
}
