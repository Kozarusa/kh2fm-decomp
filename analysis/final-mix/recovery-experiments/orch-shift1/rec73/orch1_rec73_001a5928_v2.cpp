#include "../common/types.h"
extern "C" u32 func_001050d8(u64);
extern "C" u32 func_001a4df0(...);
extern "C" void func_001c70e8(void);
extern "C" u64 func_0016e920(u32);

u32 func_001a5928(void) {
    func_001c70e8();
    u32 memory = func_001050d8(0xa00);
    u64 data = func_0016e920(0x5c3);
    return func_001a4df0(memory, data, 0x100, 0x60);
}