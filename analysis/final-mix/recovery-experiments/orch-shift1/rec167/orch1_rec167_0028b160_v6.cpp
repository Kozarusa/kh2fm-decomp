#include "../common/types.h"
s32 func_0028b160(u8* object,s32 value) {
    register u16 count asm("$12") = *(u16*)(object + 4); // why: original retains the unsigned count in t4
    asm("" : "+r"(count)); // why: preserves unsigned count before signed comparisons
    register s32 limit asm("$13") = (s16)count; // why: original signed loop limit resides in t5
    s32 index = 0;
    if (limit > 0) {
        s32* pointer = *(s32**)(object + 40);
        do {
            if (value == *pointer++) break;
            ++index;
        } while (index < limit);
    }
    s32 result = -1;
    if (index < (s16)count) result = index;
    return result;
}





