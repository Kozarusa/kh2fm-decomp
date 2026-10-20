#include "../common/types.h"
extern "C" u32** D_0034b278;
extern "C" u32* D_0034b240;
extern "C" void func_0031dd50(u32);

void func_0015de98() {
    u32** heap = D_0034b278;
    u32 object = ((u32 (*)(u32**, s32, u32))(**(u32**)heap))(heap, 4928, (u32)__builtin_return_address(0));
    func_0031dd50(object);
    D_0034b240 = (u32*)object;
    // why: original loads the vtable into t7 ($15) and the method into t6 ($14)
    register u32* table asm("$15") = *(u32**)object;
    register u32 method asm("$14") = *table;
    ((void (*)(u32))method)(object);
}
