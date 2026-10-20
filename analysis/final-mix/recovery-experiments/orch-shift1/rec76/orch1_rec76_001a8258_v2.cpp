#include "../common/types.h"
extern "C" u8* D_01c6cb98;

u8* func_001a8258(u32 id) {
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
            if (entry[4] == 1 && *(u16*)entry == id) {
                return entry;
            }
            index++;
            entry += 12;
        } while (index < count);
    }
    return 0;
}