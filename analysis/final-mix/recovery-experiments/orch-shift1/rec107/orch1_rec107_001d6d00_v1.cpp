#include "../common/types.h"
extern "C" s32 D_01d5ba98;
extern "C" u32 func_001d6cc8(s64);

s32 func_001d6d00(u32 id) {
    u32 entry = 0;
    while (1) {
        entry = func_001d6cc8(entry);
        if (entry == 0) {
            return 0;
        }
        if (*(u16*)entry == id) {
            return ((s32)(entry - D_01d5ba98) - 8 >> 6) + 1;
        }
    }
}
