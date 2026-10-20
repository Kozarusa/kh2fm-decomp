#include "../common/types.h"
extern "C" u8* D_01c6cb98;

u8* func_001a81f0(u32 a, u32 b, u32 c) {
    s32 index = 0;
    u8* entry = D_01c6cb98;
    u32 first = *(u16*)(entry + 2);
    s32 count;
    entry += 4;
    if (first != 0) {
        count = first;
        // why: forces the loop bound into its own register copy like the original
        asm("" : "+r"(count));
        do {
            if (entry[4] == 0 && entry[5] == a && entry[6] == b && entry[7] == c) {
                return entry;
            }
            index++;
            entry += 12;
        } while (index < count);
    }
    return 0;
}
