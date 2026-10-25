#include "../common/types.h"
extern "C" u32 D_0035f5e4;
// why: extern "C" because the probe linker script defines only the plain func_ symbol, and the accepted definition is C++ (mangled)
extern "C" s32 func_002a4990(s32 value);

s32 func_002a4a00(s32 value) {
    s32 count;
    s32 sum;
    s32 left;
    s32 result;
    u8* pointer;
    u8* entry;
    u8 flags;

    if (value < 0) {
        value = *(s32*)(D_0035f5e4 + 0x1084) + *(s32*)(D_0035f5e4 + 0x1088) / 8;
    }
    count = func_002a4990(value);
    sum = 0;
    if (count > 0) {
        pointer = (u8*)(D_0035f5e4 + 0x1001);
        left = count;
        do {
            left--;
            sum += *pointer;
            pointer += 8;
        } while (left != 0);
    }
    entry = (u8*)(count * 8 + D_0035f5e4);
    result = 8;
    if (value - sum >= entry[0x1001] - 1) {
        flags = entry[0x1000];
        result = flags & 7;
        if (result == 0) {
            result = 8;
            if (flags == 0) {
                result = 1;
            }
        }
    }
    return result;
}
