#include "../common/types.h"
extern "C" u32 D_00347f80;
extern "C" u8 D_0035e050[];
extern "C" u8 D_00347f98[];
extern "C" u8 D_00347e60[];
extern "C" void func_0031a838(u32);
extern "C" void func_00239700(u32);
// why: no recovered source declares func_00228ab0; the u32 argument comes from a0 and the u32
// result from its final v0 (it stores and returns the v0 of func_00224910, an integer load)
extern "C" u32 func_00228ab0(u32);

// why: the only exit is the tail call to func_00228ab0, whose v0 is a direct integer result
// (its $f0 zero is crossed by a later call, so no float is live), so the result is returned

u32 func_00228e58() {
    u32 allocator = *(u32*)(D_00347f80 + 20);
    u32 table = *(u32*)allocator;
    u32 (*allocate)(u32, u32, u32) = (u32 (*)(u32, u32, u32))(*(u32*)table);
    s32 count = 2;
    u32 object = allocate(allocator, 1260, 0);
    s32 last = -1;
    *(u32*)(object + 12) = 0;
    *(u32*)(object + 0) = (u32)D_0035e050;
    u32 first = (u32)D_00347f98;
    u32 cursor = object + 24;
    u32 second = (u32)D_00347e60;
    do {
        *(u32*)(cursor + 0) = first;
        count--;
        func_0031a838(cursor + 12);
        *(u32*)(cursor + 0) = second;
        func_00239700(cursor + 24);
        cursor += 408;
    } while (count != last);
    return func_00228ab0(object);
}
