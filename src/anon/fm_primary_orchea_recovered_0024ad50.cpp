#include "../common/types.h"
extern "C" s32 func_001d56c8(...);
extern "C" u32 func_00276c18(...);

u32 func_0024ad50() {
    u8* pointer = (u8*)func_001d56c8(10);
    u32 result = 0;
    asm("" : "+r"(result)); // why: retain carried result across conditional call
    if (*pointer < 2) {
        if (func_00276c18() != 0) result = 1;
    } else result = 1;
    return result;
}
