#include "../common/types.h"
extern "C" s16 D_003726b8[];
s32 func_00253380(s32 value) {
    register s32 result asm("$2") = 0; // why: original initializes return register before loop
    asm("" : "+r"(result)); // why: preserves early return-register initialization
    s32 index = 0;
    if (D_003726b8[0] >= 0) {
        do {
            if (D_003726b8[index] == value) return 1;
            index++;
        } while (D_003726b8[index] >= 0);
    }
    return result;
}

