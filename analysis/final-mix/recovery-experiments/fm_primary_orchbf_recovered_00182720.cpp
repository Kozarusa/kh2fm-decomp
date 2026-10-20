#include "../common/types.h"
extern "C" u8 D_01c60534[];

void func_00182720(u32 a, u32 b, u32 c, u32 d) {
    if (b == 0xffff) {
        if (a == 1) {
            u8* p = D_01c60534;
            // why: keeps store order
            *(volatile u16*)(p + 4) = b;
            u8* q = p - 4;
            // why: keeps store order
            *(volatile u8*)(q + 2) = b;
            // why: keeps store order
            *(volatile u16*)D_01c60534 = b;
            // why: keeps store order
            *(volatile u8*)(q + 1) = b;
            // why: keeps store order
            *(volatile u8*)(p - 4) = b;
            // why: keeps store order
            *(volatile u16*)(p + 2) = b;
        }
    }
}
