#include "../common/types.h"
extern "C" u32 func_002657a8(void);
extern "C" u32 func_00266988(void);
extern "C" u32 func_002666a8(void);
u32 func_00266678(u64 unused, s64 value) {
    asm volatile("" ::: "memory"); // why: preserves original prologue before conditional call
    if (value != 23) {
    } else {
        func_002657a8();
    }
    func_00266988();
    return func_002666a8();
}


