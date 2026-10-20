#include "../common/types.h"
extern "C" s32* D_0035dcfc;

s32* func_00227cd8(s32 value) {
    s32 count = 0;
    s32* pointer = D_0035dcfc;
    do {
        if (*pointer == value) return pointer;
        pointer += 10;
        ++count;
    } while (count < 96);
    return 0;
}
