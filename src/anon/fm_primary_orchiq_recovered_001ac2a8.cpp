#include "../common/types.h"

extern "C" u32 func_00239bf8(void* dest, s32 count);

// Preserve original registry aliases.
u32 func_001ac2a8(int *arg1,s32 arg2,int arg3,int arg4) asm("_Z16wtarget_001ac2a8jjjj");

u32 func_001ac2a8(int *arg1,s32 arg2,int arg3,int arg4)
{
    u32 result;
    if (arg2 != 0)
    {
        result = func_00239bf8(arg1 + 3, arg2 + 1);
    }
    arg1[0] = arg2;
    arg1[1] = arg3;
    arg1[2] = arg4;
    return result;
}
