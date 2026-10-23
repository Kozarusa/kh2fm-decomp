#include "../common/types.h"
extern "C" u32 func_0023cc18(u32);
extern "C" u32 func_002ef618(void);

u32 func_002ef340(u32 object, u64 first, u32 second) {
    volatile u64 saved_first[2];
    volatile u32 saved_second;
    u32 inner = object + 0x40;
    asm volatile("" ::: "memory"); // why: keeps store order
    saved_first[0] = first;
    saved_second = second;
    func_0023cc18(inner);
    return func_002ef618();
}
