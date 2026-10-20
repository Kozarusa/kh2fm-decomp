#include "../common/types.h"
extern "C" u32 func_0016ed50(void*, s64, s64);
extern "C" u32 func_00170320(s32);
extern "C" u32 func_001d01e0(void);

u32 func_001d0068(void) {
    // why: keeps store order (prologue sd s0 stays out of the call delay slot)
    asm volatile("" ::: "memory");
    u32 table = func_001d01e0();
    func_00170320(5000);
    return func_0016ed50((void*)table, 5000, 7);
}