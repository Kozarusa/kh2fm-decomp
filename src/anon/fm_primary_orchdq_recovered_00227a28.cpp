#include "../common/types.h"
extern "C" u8* D_0035dcf0;

u8* func_00227a28() {
    u8* pointer = D_0035dcf0;
    s32 count = 0;
    while (1) {
        s32 value = *(s32*)(pointer + 4);
        if (!value) return pointer;
        pointer += 84;
        ++count;
        if (count >= 128) break;
    }
    return 0;
}
