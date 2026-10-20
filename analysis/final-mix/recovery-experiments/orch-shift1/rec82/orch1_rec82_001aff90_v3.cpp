#include "../common/types.h"
extern "C" u8* D_01c940b4;

u8* func_001aff90(u32 first, u32 second) {
    s32 index = 0;
    u8* base = D_01c940b4;
    u8* pointer = base + 8;
    s32 total = *(volatile s32*)(base + 4); // why: keeps count in a temporary before the loop copy
    if (total > 0) {
        s32 count = total;
        do {
            if (pointer[0] == first && pointer[1] == second) {
                return pointer;
            }
            index++;
            pointer += 14;
        } while (index < count);
    }
    return 0;
}
