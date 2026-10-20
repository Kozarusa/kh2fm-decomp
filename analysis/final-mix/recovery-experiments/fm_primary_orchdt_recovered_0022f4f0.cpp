#include "../common/types.h"
extern "C" u8* D_0035dcfc;

u8* func_0022f4f0(s32 value) {
    s32 count = 0;
    u8* pointer = D_0035dcfc;
    do {
        s32 current = *(s32*)pointer;
        register u8* result asm("$2") = pointer + 23; // why: original forms return address directly in v0
        asm("" : "+r"(result)); // why: keeps return address in v0
        pointer += 40;
        if (current == value) return result;
        ++count;
    } while(count < 96);
    return 0;
}
