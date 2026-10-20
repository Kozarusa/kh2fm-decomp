#include "../common/types.h"
extern "C" u32 D_0035f5ac;
extern "C" u32 func_00276638(s32);
extern "C" s8* func_0029da68(s32);
extern "C" s32 func_00292a90(s32);
extern "C" s32 func_00292af0(s32);
extern "C" s32 func_0029dd60();
s32 func_0029dda8() {
    u32 index=func_00276638(15);
    s8 value=func_0029da68(*(s16*)(D_0035f5ac+(index<<1)+8))[1];
    s32 result=func_00292a90(value);
    if(result) return result;
    result=func_00292af0(value);
    if(result) return result;
    return func_0029dd60();
}
