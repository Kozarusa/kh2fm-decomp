#include "../common/types.h"
extern "C" u32* func_00124748(u32*,s32);

s32 func_001244b8(u32* object, s32 base, s32 value)
{
    typedef s32 (*Callback)(u32*, s32, s32);
    s32 index;
    s32 result;
    u32* receiver = func_00124748(object, 0);
    register Callback method asm("$14") = (Callback)((u32*)*receiver)[18]; // why: original loads the vtable slot into t6
    result = method(receiver, base, value);
    for (index = 1; index < (s32)object[4]; index++) {
        receiver = func_00124748(object, index);
        register Callback next asm("$14") = (Callback)((u32*)*receiver)[18]; // why: original loads the vtable slot into t6
        result = next(receiver, base + ((s32*)object)[index + 7], value);
    }
    return result;
}
