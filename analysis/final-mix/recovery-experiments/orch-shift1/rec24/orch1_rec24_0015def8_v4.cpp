#include "../common/types.h"
extern "C" u32** D_0034b278;
extern "C" u8* D_0034b244;
extern "C" void func_0031dd50(u32);

void func_0015def8() {
    // why: reloaded global pointer in t5 ($13)
    register u8* flagObject asm("$13");
    u32** heap = D_0034b278;
    u32 object = ((u32 (*)(u32**, s32, u32))(**(u32**)heap))(heap, 4928, (u32)__builtin_return_address(0));
    func_0031dd50(object);
    D_0034b244 = (u8*)object;
    // why: keeps store order
    asm volatile("" ::: "memory");
    // why: vtable pointer in t7 ($15)
    register u32* table asm("$15") = *(u32**)object;
    // why: method pointer in t6 ($14)
    register u32 method asm("$14") = *table;
    ((void (*)(u32))method)(object);
    flagObject = D_0034b244;
    flagObject[4] = 1;
}
