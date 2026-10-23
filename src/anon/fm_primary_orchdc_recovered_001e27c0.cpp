#include "../common/types.h"
extern "C" u64 func_001e17b8(...);

u64 func_001e27c0(u8* object) {
    // why: original keeps the -1 constant in t6 ($14), allocator picks t7
    register s32 invalid asm("$14") = -1;
    *(s32*)(object + 0xdc4) = 0;
    *(s32*)(object + 0xe00) = invalid;
    *(s32*)(object + 0xdcc) = 0;
    *(s32*)(object + 0xdd0) = 0;
    *(s32*)(object + 0xde4) = 0;
    *(s32*)(object + 0xdec) = 0;
    *(s32*)(object + 0xdc0) = 0;
    return func_001e17b8();
}
