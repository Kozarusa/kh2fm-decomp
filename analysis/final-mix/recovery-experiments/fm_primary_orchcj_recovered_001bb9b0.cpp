#include "../common/types.h"
extern "C" u32 D_01d49320;
extern "C" bool func_001bb4a0(void);

u32 func_001bb9b0(void) {
    u32 result;
    if (func_001bb4a0() == 0) {
        result = 0;
    } else {
        u32 inner = *(u32*)(D_01d49320 + 8);
        u32 bits = *(u16*)(inner + 4);
        bits = bits >> 4;
        result = bits & 1;
    }
    return result;
}
