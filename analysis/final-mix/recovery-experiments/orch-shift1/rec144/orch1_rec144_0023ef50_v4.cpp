#include "../common/types.h"
extern "C" s32 func_00236ca8(...);
void func_0023ef50(u8* object) {
    // why: original keeps count in register 17.
    register s32 count asm("$17") = *(s32*)(object + 40);
    s32 index = 0;
    if (count > 0) {
        u8* pointer = object + 48;
        do {
            s32 result = func_00236ca8(*(s32*)(pointer + 40), index);
            index++;
            *(u8*)(result + 400) = 1;
        } while (index < count);
    }
}

