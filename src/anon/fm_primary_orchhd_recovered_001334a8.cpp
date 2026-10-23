#include "../common/types.h"
extern "C" u32 func_00313bc0(f32);

u32 func_001334a8(u8* object, u32 numerator, u32 denominator) {
    f32 ratio = (f32)numerator / (f32)denominator;
    u32 result = func_00313bc0((f32)*(u32*)(object + 0x28) * ratio);
    return (result >> 16) & 0xfff;
}
