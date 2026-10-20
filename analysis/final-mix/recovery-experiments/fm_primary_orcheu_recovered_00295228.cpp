#include "../common/types.h"
extern "C" u32 func_00294000(u32);
extern "C" u32 func_00295158(u32);

s32 func_00295228(u32 value) {
    u32 pointer = func_00294000(0) + 16u;
    u32 index = func_00295158(value);
    return *(s8*)((index << 4) + pointer);
}
