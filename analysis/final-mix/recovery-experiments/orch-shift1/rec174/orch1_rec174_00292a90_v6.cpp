#include "../common/types.h"
extern "C" s32 D_0035f4d0;
extern "C" s32* D_0035f4d4;
s32 func_00292a90(s32 value) {
    s32 index = 0;
    register s32 result asm("$2") = 0; // why: original initializes v0 before the loop
    s32 count = D_0035f4d0;
    if (count > 0) {
        s32* cursor = D_0035f4d4;
        do {
            u8 flag = ((volatile s32*)cursor)[1] & 1;
            if (flag != 0) {
                if (*cursor == value) { result = 1; asm("" : "+r"(result)); // why: successful exit returns the defined v0 independently
                    return result; }
            }
            ++index;
            cursor += 4;
        } while (index < count);
    }
    return result;
}





