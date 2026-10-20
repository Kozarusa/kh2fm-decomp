#include "../common/types.h"

extern "C" u32 func_0016cc18(s64, s64, u64, u64, s64);

u32 func_00188398(s32 object, s64 condition, u64 third, u64 fourth) {
    register s32 first asm("$15") = *(s32*)(object + 0x88);
    asm("" : "+r"(first) : : "$2");
    register s32 second asm("$14") = *(s32*)(first + 4);
    // Keep zero-return initialization after the constrained address reads.
    asm("" : "+r"(second) : : "$2");
    s64 loaded = *(s32*)(second + 0x484);
    u32 result = 0;
    if (loaded != 0 && condition != 0) {
        func_0016cc18(loaded, condition, third, fourth, 0);
        result = 1;
    }
    return result;
}
