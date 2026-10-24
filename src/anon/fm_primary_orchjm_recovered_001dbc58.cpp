#include "../common/types.h"
extern "C" u8 D_001dbd38[];
extern "C" u32 func_001c1748(...);

u32 func_001dbc58(u8* object, u32 value, u8* vector, u8* source) {
    u32 result = func_001c1748(object, value, vector, D_001dbd38);
    // why: lq/sq copy primitive (kn::FVector operator= body without the self check); plain Quad copy failed in rec113
    asm("lq $8, 0(%1);"
        "sq $8, 0(%0);"
        :
        : "r"(object + 0x30), "r"(vector)
        : "t0");
    *(u8*)(object + 0x50) = 0;
    *(u8**)(object + 0x5c) = source;
    *(s8*)(object + 0x16) = -1;
    *(u8*)(object + 0x51) = 0;
    *(u32*)(object + 0x54) = 0;
    *(u32*)(object + 0x58) = 0;
    *(u8*)(object + 0x14) = *source;
    return result;
}
