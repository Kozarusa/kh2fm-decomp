#include "../common/types.h"
extern "C" u32 func_001058e8(void);
u32 func_002a74c0() {
    u32 address = func_001058e8() + 0x49f4u;
    u32 result = 0;
    u32 index = 0;
    do {
        u32 word = index >> 5;
        u32 bit = index & 31u;
        ++index;
        asm("" : "+r"(bit) : "r"(index)); // why: keep native bit shift after index increment
        u32 mask = 1u << bit;
        if ((*(u32*)(word * 4u + address) & mask) != 0) {
            result = 1;
            break;
        }
    } while ((s32)index < 64);
    return result;
}



