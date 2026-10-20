#include "../common/types.h"
extern "C" u32 func_001acdc0(...);

void func_001acf38(s32* object) {
    if (object[25] == 2) {
        func_001acdc0(object, object[1], object[2] + ((u32)object[24] >> 1), object[1] + ((u32)object[23] >> 1), object[2] + (u32)object[24], 0);
        return;
    }
    func_001acdc0(object, object[1], object[2], object[1] + ((u32)object[23] >> 1), object[2] + ((u32)object[24] >> 1), 0);
    // why: keeps the call non-tail so the epilogue follows the jal
    asm volatile("" ::: "memory");
}
