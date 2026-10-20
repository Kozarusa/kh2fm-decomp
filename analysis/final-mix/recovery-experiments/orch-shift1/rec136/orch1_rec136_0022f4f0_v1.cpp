#include "../common/types.h"
extern "C" u8* D_0035dcfc;
u8* func_0022f4f0(s32 value) {
    s32 count = 0;
    u8* pointer = D_0035dcfc;
    do {
        s32 current = *(s32*)pointer;
        u8* result = pointer + 23;
        pointer += 40;
        if (current == value) return result;
        ++count;
    } while(count < 96);
    return 0;
}
