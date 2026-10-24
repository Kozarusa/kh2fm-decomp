#include "../common/types.h"
extern "C" u8 D_01d49574[];

// Preserve original registry aliases.
void func_001c4080(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_001c4080jjjj");

void func_001c4080(u32 a, u32 b, u32 c, u32 d) {
    if (b == 0xffff) {
        if (a == 1) {
            u8* p = D_01d49574;
            // why: keeps store order
            *(volatile u16*)(p + 4) = b;
            u8* q = p - 4;
            // why: keeps store order
            *(volatile u8*)(q + 2) = b;
            // why: keeps store order
            *(volatile u16*)D_01d49574 = b;
            // why: keeps store order
            *(volatile u8*)(q + 1) = b;
            // why: keeps store order
            *(volatile u8*)(p - 4) = b;
            // why: keeps store order
            *(volatile u16*)(p + 2) = b;
        }
    }
}
