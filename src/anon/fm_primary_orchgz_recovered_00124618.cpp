#include "../common/types.h"
extern "C" u32* func_00124748(u32*,s32);

s32 func_00124618(u32* object, s32 first, s32 second, s32 third, s32 fourth, s32 fifth, u8 flag, s32 sixth)
{
    typedef s32 (*Callback)(u32*, s32, s32, s32, s32, s32, u8, s32);
    u32* receiver = func_00124748(object, 0);
    return ((Callback)((u32*)*receiver)[20])(receiver, first, second, third, fourth, fifth, flag, sixth);
}
