#include "../common/types.h"
extern "C" void func_00106420(...);
extern "C" u8* D_0034c7a0;

void func_00165968() {
    u8* base = D_0034c7a0;
    if (base != 0) {
        u8* cursor = base + 0x400;
        bool more;
        do {
            // why: original loop body is five nop words (inlined empty destructor loop)
            asm volatile("nop\n\tnop\n\tnop\n\tnop\n\tnop");
            more = base != cursor;
            cursor -= 16;
        } while (more);
        func_00106420();
        D_0034c7a0 = 0;
    }
}
