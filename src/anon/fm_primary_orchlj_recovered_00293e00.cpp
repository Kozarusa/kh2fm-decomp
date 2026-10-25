#include "../common/types.h"
extern "C" u32 D_0035f570;
extern "C" u32 D_0035f574;
extern "C" u32* D_0035f578;
extern "C" s32 func_001063c0(u32, u32);
// why: a0 object, a1 base, a2 count are the registers set before the call; no result is used
extern "C" void func_002907c0(u32, u32, u32);

// why: the only exit leaves the second func_001063c0 result in v0 (direct callee result)

s32 func_00293e00(u32 base) {
    D_0035f570 = base;
    s32 menu = func_001063c0(24, base);
    func_002907c0(menu, D_0035f570, 10);
    D_0035f574 = menu;
    s32 table = func_001063c0(64, D_0035f570);
    u32* cursor = (u32*)table;
    for (s32 count = 15; count >= 0; count--) {
        *cursor++ = 0;
    }
    D_0035f578 = (u32*)table;
    // why: the original reloads the global after storing it
    cursor = *(u32* volatile*)&D_0035f578;
    for (s32 count = 15; count >= 0; count--) {
        *cursor++ = 0;
    }
    return table;
}
