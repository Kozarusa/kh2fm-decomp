#include "../common/types.h"
extern "C" u32 func_002fde18(...);
extern "C" u32 func_00306f30(s32);
extern "C" u32 func_0016cc18(s64, s64, u64, u64, s64);

void func_00281f90(s32 object) {
    *(u32*)(object + 0x100c) = 0xffffffff;
    asm("" : : : "memory");
    u32* cursor = (u32*)(object + 0x1010);
    *(u32*)(object + 0x1008) = 0xffffffff;
    s32 remaining = 4;
    do { *cursor = 0; --remaining; ++cursor; } while (remaining >= 0);
    func_002fde18(object + 0x1024, 0, 0x40);
}

u32 func_00307f68(u32 unusedFirst, u32 unusedSecond, s32 value) {
    register s32 dispatch asm("$4") = value;
    // The original consumes the third argument through a0.
    asm("" : : "r"(dispatch) : "$6");
    if (dispatch != 0) func_00306f30(dispatch);
    return 1;
}

u32 func_00188398(s32 object, s64 condition, u64 third, u64 fourth) {
    register s32 first asm("$15");
    register s32 second asm("$14");
    // Original two loads, with explicit output registers and no extra moves.
    asm("lw %0, 0x88(%2)\n\tlw %1, 4(%0)"
        : "=&r"(first), "=&r"(second) : "r"(object) : "memory");
    s64 loaded = *(s32*)(second + 0x484);
    u32 result = 0;
    if (loaded != 0 && condition != 0) {
        func_0016cc18(loaded, condition, third, fourth, 0);
        result = 1;
    }
    return result;
}
