#include "../common/types.h"
extern "C" u32* func_00124748(u32*,s32);

s32 func_001246b8(u32* object, s32 first, s32 second, s32 third, s32 fourth, u8 flag, s32 fifth)
{
    typedef s32 (*Callback)(u32*, s32, s32, s32, s32, u8, s32);
    u32* receiver = func_00124748(object, 0);
    return ((Callback)((u32*)*receiver)[22])(receiver, first, second, third, fourth, flag, fifth);
}
