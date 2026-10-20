#include "../common/types.h"
extern "C" s32 func_0016c028(u8*);
extern "C" u32 func_001a7610(s32, void*, u32, f32, f32);
extern "C" u32 func_0016ace0(u8*, void*);

void func_001852b8(u8* object) {
    u8 buffer[16];
    s32 world = func_0016c028(object);
    u32 flags = (u32)((*(s64*)(object + 0x600) << 29) >> 32) & 0xf;
    f32* first = (f32*)0x0036c8cc;
    f32* second = (f32*)0x0036c8d0;
    if (func_001a7610(world, buffer, flags | 0x10000, *first, *second)) {
        func_0016ace0(object, buffer);
    }
}
