#include "../common/types.h"
extern "C" u32 D_00363860[];
extern "C" u32 D_003637e0[];
extern "C" u32 func_001a93e8(...);
extern "C" u32 func_00106ac8(...);
extern "C" u32 func_001a9350(...);

// Preserve original registry aliases.
u32 func_002eec58(u32* object) asm("_Z16u_call4_002eec58jjjj");

u32 func_002eec58(u32* object) {
    object[0] = (u32)D_00363860;
    u32* handle = (u32*)func_001a93e8(object + 11);
    ((void (*)(u32*, u32, u32))((u32*)handle[0])[10])(handle, object[10], object[17]);
    func_00106ac8(object + 20);
    u32 result = func_001a9350(object + 11);
    object[0] = (u32)D_003637e0;
    return result;
}
