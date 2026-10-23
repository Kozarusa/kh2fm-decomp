#include "../common/types.h"
extern "C" u8* D_0035dcf4;

u8* func_0022e330(s32 value) {
    u8* pointer = D_0035dcf4;
    s32 count = 0;
    while (1) {
        s32 current = *(s32*)(pointer + 4);
        if (current == value) return pointer;
        pointer += 52;
        ++count;
        if (count >= 96) break;
    }
    return 0;
}
