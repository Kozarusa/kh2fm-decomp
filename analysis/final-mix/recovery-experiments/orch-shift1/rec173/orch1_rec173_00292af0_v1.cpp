#include "../common/types.h"
extern "C" s16 D_0035f4e0;
extern "C" u16* D_0035f4dc;
s32 func_00292af0(u64 value) {
    s32 index = 0;
    s32 count = D_0035f4e0;
    if (count > 0) {
        u16* pointer = D_0035f4dc;
        do {
            u16 item = *pointer;
            pointer += 2;
            if (item == value) return 1;
            ++index;
        } while (index < count);
    }
    return 0;
}
