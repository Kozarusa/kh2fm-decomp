#include "../common/types.h"
extern "C" u8* func_0016e920(u32);

u32 func_001997c0(u32* object) {
    u8* data = func_0016e920(*object);
    s32 kind = data[4];
    u8 other;
    u32 result = 1;
    if (kind != 13 && ((other = 4, kind < 14) || (other = 23, kind != 21)) && kind != other) {
        result = 0;
    }
    return result;
}
