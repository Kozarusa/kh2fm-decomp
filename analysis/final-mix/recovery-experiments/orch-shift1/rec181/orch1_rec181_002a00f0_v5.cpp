#include "../common/types.h"
extern "C" s8* D_0035f5d0;
extern "C" int func_002a01c8(int);
extern "C" s32 func_002943e8(s32);
s32 func_002a00f0() {
    s32 index = 0;
    s32 count = 0;
    register s8* pointer asm("$13") = D_0035f5d0; // why: original carries the cursor in t5
    if (*pointer > 0) {
        do {
            s32 value = func_002a01c8(pointer[index + 6]);
            ++index;
            if (func_002943e8(value)) ++count;
            pointer = D_0035f5d0;
        } while (index < *pointer);
    }
    return count;
}


