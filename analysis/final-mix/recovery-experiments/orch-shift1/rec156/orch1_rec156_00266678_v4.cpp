#include "../common/types.h"
extern "C" u32 func_002657a8(void);
extern "C" u32 func_00266988(void);
extern "C" u32 func_002666a8(void);
u32 func_00266678(u64 unused, s64 value) {
    s64 limit = 23;
    asm volatile("" : "+r"(limit) :: "memory"); // why: materializes comparison constant before original conditional call
    if (value == limit) func_002657a8();
    func_00266988();
    return func_002666a8();
}



