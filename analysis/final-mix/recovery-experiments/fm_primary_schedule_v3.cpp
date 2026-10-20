#include "../common/types.h"
extern "C" u32 func_002fde18(...);
extern "C" u32 func_00306f30(s64);
extern "C" u32 func_0016cc18(s64, s64, u64, u64, s64);

void func_00281f90(s32 object) {
    register u32 fill asm("$15") = 0xffffffff;
    register u32* cursor asm("$14");
    // Original initialization order and temporary reuse precede the C++ loop.
    asm("sw %2, 0x100c(%1)\n\taddiu %0, %1, 0x1010\n\tsw %2, 0x1008(%1)"
        : "=&r"(cursor) : "r"(object), "r"(fill) : "memory");
    register s32 remaining asm("$15") = 4;
    do { *cursor = 0; --remaining; ++cursor; } while (remaining >= 0);
    func_002fde18(object + 0x1024, 0, 0x40);
}

u32 func_00307f68(u64 unusedFirst, u64 unusedSecond, s64 value) {
    register s64 dispatch asm("$4") = value;
    asm("" : "+r"(dispatch));
    if (dispatch != 0) func_00306f30(dispatch);
    return 1;
}

u32 func_00188398(s32 object, s64 condition, u64 third, u64 fourth) {
    register s32 first asm("$15") = *(s32*)(object + 0x88);
    register s32 second asm("$14") = *(s32*)(first + 4);
    // One combined input constraint keeps the load dependency in original order.
    asm("" : : "r"(first), "r"(second));
    s64 loaded = *(s32*)(second + 0x484);
    register u32 result asm("$2") = 0;
    if (loaded != 0 && condition != 0) {
        func_0016cc18(loaded, condition, third, fourth, 0);
        result = 1;
    }
    return result;
}
