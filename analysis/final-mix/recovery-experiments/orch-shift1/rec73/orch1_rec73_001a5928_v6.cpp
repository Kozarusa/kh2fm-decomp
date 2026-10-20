#include "../common/types.h"
extern "C" u32 func_001050d8(u64);
extern "C" u32 func_001a4df0(...);
extern "C" u32 func_001c70e8(void);
extern "C" u64 func_0016e920(u32);

u32 func_001a5928(void) {
    // why: keeps the first call's delay slot empty like the original
    asm volatile("" ::: "memory");
    func_001c70e8();
    // why: pairs with the barrier above to keep prologue save order
    asm volatile("" ::: "memory");
    u32 memory = func_001050d8(0xa00);
    u64 data = func_0016e920(0x5c3);
    return func_001a4df0(memory, data, 0x100, 0x60);
}