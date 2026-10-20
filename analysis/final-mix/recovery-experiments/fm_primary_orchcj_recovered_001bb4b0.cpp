#include "../common/types.h"
extern "C" u8* D_01d49320;
extern "C" bool func_001bb4a0(void);

u32 func_001bb4b0(void) {
    u32 result;
    if (func_001bb4a0() == 0) {
        result = 0;
    } else {
        u32 flags = *(u32*)(D_01d49320 + 4);
        flags = flags & 4;
        result = (flags == 0);
    }
    return result;
}
