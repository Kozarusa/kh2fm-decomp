#include "../common/types.h"
extern "C" u32 func_001386e0(...);
extern "C" u32 func_0022b9e0(...);

u32 func_0022b558(u8* object, u32 value, u32 count) {
    register u8* pointer asm("$17") = object;     u32 result = func_0022b9e0();
    u32 returned = func_001386e0(pointer, 2500, result, count, value, 11);

         *(f32*)(pointer + 384) = 1.0f;
    return returned;
}
