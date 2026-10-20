#include "../common/types.h"

extern "C" u32 func_001ad990(f32, f32, f32, void*);

u32 func_001940b8(u8* object, u32 a, u32 b, u32 c, f32 x, f32 y) {
    object[0x680] = a;
    object[0x681] = b;
    object[0x682] = c;
    return func_001ad990(*(f32*)(object + 0x8c0), x, y, object + 0x8c0);
}
