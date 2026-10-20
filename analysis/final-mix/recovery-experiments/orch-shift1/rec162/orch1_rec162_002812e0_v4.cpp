#include "../common/types.h"
extern "C" u32 func_001058e8(void);
extern "C" s8 D_00374188[];
s32 func_002812e0() {
    u8 value = *(u8*)(func_001058e8() + 12);
    s32 result = 0;
    s8* pointer = D_00374188;
    if (*pointer >= 0) {
        do {
            s64 entry = *pointer++;
            if (entry == value) { result = 1; break; }
        } while (*pointer >= 0);
    }
    return result;
}

