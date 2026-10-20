#include "../common/types.h"
extern "C" u32 func_001386e0(...);
extern "C" u32 func_0022b9e0(...);
extern "C" f32 D_00371134;
u32 func_0022b558(u8* object, u32 value, u32 count) {
    u32 result = func_0022b9e0();
    u32 returned = func_001386e0(object, 2500, result, count, value, 11);
    *(f32*)(object + 384) = D_00371134;
    return returned;
}
