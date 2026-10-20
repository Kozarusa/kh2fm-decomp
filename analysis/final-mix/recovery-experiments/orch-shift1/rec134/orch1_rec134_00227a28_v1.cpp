#include "../common/types.h"
extern "C" u8* D_0035dcf0;
u8* func_00227a28() {
    s32 count = 0;
    u8* pointer = D_0035dcf0;
    while (1) {
        u8* result = pointer;
        s32 value = *(s32*)(pointer + 4);
        pointer += 84;
        if (!value) return result;
        ++count;
        if (count >= 128) break;
    }
    return 0;
}
