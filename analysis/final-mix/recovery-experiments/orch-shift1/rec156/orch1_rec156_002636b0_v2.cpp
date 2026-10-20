#include "../common/types.h"
extern "C" u32 func_002632d0(...);
extern "C" s16 D_00373270[];
s32 func_002636b0() {
    u16 value = *(u16*)func_002632d0();
    s32 index = 0;
    s32 result = 0;
    if (D_00373270[0] >= 0) {
        do {
            if (D_00373270[index] == value) { result = 1; break; }
            index++;
        } while (D_00373270[index] >= 0);
    }
    return result;
}

