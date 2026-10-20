#include "../common/types.h"
extern "C" u8* D_0035f480;
extern "C" s16 D_0035f468[];
extern "C" s16 D_0035f470[];
s16* func_0028f690(s32 index) {
    u8* address = D_0035f480 + index * 884 + 388;
    s32 value = *(s32*)address;
    s16* result = 0;
    register s32 count asm("$14") = 2; // why: original loop count uses t6
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


