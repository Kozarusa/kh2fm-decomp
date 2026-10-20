#include "../common/types.h"
extern "C" u32 D_0035f680[];
extern "C" u32 func_00139d78(...);

u32 func_002b56e8() {
    register s32 count asm("$16") = 0; // why: original loop counter lives in s0
    u32* pointer = D_0035f680;
    u32 result = 0;
    while (count < 4) {
        u32 value = *pointer++;
        if (value != 0) {
            if (func_00139d78(value) != 0) {
                result = 1;
                break;
            }
        }
        count++;
    }
    return result;
}
