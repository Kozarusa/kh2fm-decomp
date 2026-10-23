#include "../common/types.h"
extern "C" s32 D_01d5ba98;
extern "C" u16* func_001d6cc8(u16*);

s32 func_001d6d00(u32 id) {
    u16* entry = 0;
    while ((entry = func_001d6cc8(entry)) != 0) {
        if (*entry == id) {
            return (((s32)entry - D_01d5ba98 - 8) >> 6) + 1;
        }
    }
    return 0;
}
