#include "../common/types.h"
extern "C" f32 D_0036c8cc[];
extern "C" f32 D_0036c8d0[];
extern "C" s32 func_0016c028(u8*);
extern "C" u32 func_001a7610(s32, void*, u32, f32, f32);
extern "C" u32 func_0016ace0(u8*, void*);

u32 func_001852b8(u8* object) {
    u8 buffer[16];
    s32 world = func_0016c028(object);
    // why: original reuses t7 for both constant addresses
    register f32* constant asm("$15") = D_0036c8cc;
    asm("" : "+r"(constant)); // why: keeps lui+addiu then lwc1 0(t7)
    f32 x = *constant;
    u32 flags = (u32)((*(s64*)(object + 0x600) << 29) >> 32) & 0xf;
    constant = D_0036c8d0;
    asm("" : "+r"(constant)); // why: keeps lui+addiu then lwc1 0(t7)
    f32 y = *constant;
    u32 result = func_001a7610(world, buffer, flags | 0x10000, x, y);
    if (result) {
        result = func_0016ace0(object, buffer);
    }
    return result;
}
