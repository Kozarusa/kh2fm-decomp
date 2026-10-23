#include "../common/types.h"
extern "C" u32 func_002c7060(u8*);
extern "C" u32 func_0016bd60(u8*, s32);

u32 func_002c1860(u32 unused, u8* object) {
    u8* part = object + 0xb70;
    u32 result = func_002c7060(part);
    u32 positive = 0.0f < *(f32*)(part + 0x54);
    if ((positive & 0xff) != 0) {
        return result;
    }
    return func_0016bd60(object, 0x2f);
}
