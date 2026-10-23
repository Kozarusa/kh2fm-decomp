#include "../common/types.h"
extern "C" u8 D_00361810[];
extern "C" u32 func_00185ed8(u32, u32, u32, u32);

u32 func_002be7b8(u32* object, u32 b, u32 c) {
    u32 result = func_00185ed8((u32)object, b, 4, c);
    u32 flags = object[354];
    *object = (u32)D_00361810;
    object[354] = flags | 0x40000000;
    return result;
}
