#include "../common/types.h"
extern "C" u8* D_0035f480;
extern "C" s16 D_0035f468[];
extern "C" s16 D_0035f470[];
s16* func_0028f690(s32 index) {
    s32 count = 2;
    s32 value = *(s32*)(D_0035f480 + index * 884 + 388);
    s16* result = 0;
    s16* pointer = D_0035f468;
    s16* base = pointer;
    do {
        s16 current = *pointer;
        --count;
        ++pointer;
        if (value == current) result = base;
    } while (count >= 0);
    if (!result) result = D_0035f470;
    return result;
}

