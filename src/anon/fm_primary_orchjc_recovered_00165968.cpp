#include "../common/types.h"
extern "C" void func_00106420(u32*);
extern "C" u32* D_0034c7a0;

void func_00165968() {
    u32* base = D_0034c7a0;
    if (base != 0) {
        u8* cursor = (u8*)base + 0x400;
        while (1) {
            // why: testing the end in the loop head instead compiles 24 bytes shorter (measured)
            if ((u8*)base == cursor) {
                break;
            }
            cursor -= 16;
        }
        func_00106420(base);
        D_0034c7a0 = 0;
    }
}
