#include "../common/types.h"
extern "C" s32* D_0035dcf8;
s32* func_00232e60() {
    s32 index = 0;
    s32* pointer = D_0035dcf8;
    do {
        s32* result = pointer;
        s32 value = *pointer;
        pointer += 16;
        if (value == -1) return result;
        ++index;
    } while (index < 64);
    return 0;
}