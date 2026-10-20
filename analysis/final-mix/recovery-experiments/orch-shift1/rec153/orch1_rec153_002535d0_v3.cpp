#include "../common/types.h"
extern "C" volatile signed char D_003726c8[];
extern "C" s32 func_00102fa0();
s32 func_002535d0(s32 value) {
    s32 result = -1;
    if (D_003726c8[0] >= 0) {
        volatile signed char* pointer = D_003726c8;
        do {
            s32 current = *pointer++;
            if (value == current) { result = 2; break; }
        } while (*pointer >= 0);
    }
    if (func_00102fa0() != 0) result = 2;
    return result;
}


