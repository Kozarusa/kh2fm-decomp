#include "../common/types.h"

extern "C" u32 D_0034e948;
extern "C" u32 func_0019ba60(u32);

u32 func_0017a6c8() {
    u32 result = 0;
    if (func_0019ba60(D_0034e948)) {
        u8* object = (u8*)D_0034e948;
        u32 masked = *(u32*)(object + 0x160) & 0x4000;
        result = masked != 0;
    }
    return result;
}
