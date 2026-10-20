#include "../common/types.h"
extern "C" u32 func_001386e0(...);
extern "C" u32 func_0022b9e0(...);
extern "C" f32 D_00371134;

u32 func_0022b558(u8* object, u32 value, u32 count) {
    register u8* pointer asm("$17") = object; // why: original preserves object in s1 across both calls
    u32 result = func_0022b9e0();
    u32 returned = func_001386e0(pointer, 2500, result, count, value, 11);
    f32* source = &D_00371134;
    asm("" : "+r"(source)); // why: original forms full global address separately from load
    *(f32*)(pointer + 384) = *source;
    return returned;
}
