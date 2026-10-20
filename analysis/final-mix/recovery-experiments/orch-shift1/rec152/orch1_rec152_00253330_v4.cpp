#include "../common/types.h"
extern "C" s16 D_003726d0[];
s16* func_00253330(s32 value) {
    s16* result = 0;
    s32 index = 0;
    if (D_003726d0[0] >= 0) {
        s32 offset = 0;
        do {
            s16* pointer = (s16*)((u8*)D_003726d0 + offset);
            ++index;
            register s32 nextOffset asm("$14") = index * 16; // why: original shift result uses t6
            offset = nextOffset;
            if (*pointer == value) result = pointer;
        } while (*(s16*)((u8*)D_003726d0 + offset) >= 0);
    }
    return result;
}



