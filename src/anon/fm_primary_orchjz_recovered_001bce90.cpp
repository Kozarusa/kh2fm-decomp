#include "../common/types.h"
extern "C" s32 func_001bc780(s32,u64,s32,u64);
extern "C" u32 func_001bc778(...);

void func_001bce90(u32 menu, u16* items, u32 count, u32 data) {
    s32 entry;
    u32 index;

    index = 0;
    func_001bc778(menu);
    // why: keeps the index and loop setup after the clear call; without it the s-register saves and setup reorder (v3, 10 words)
    asm volatile("" ::: "memory");
    if (count != 0) {
        do {
            entry = func_001bc780(menu, *items, data, 1);
            index = index + 1;
            *(u8*)(entry + 6) = *(u8*)(items + 1);
            items = items + 2;
        } while (index < count);
    }
}
