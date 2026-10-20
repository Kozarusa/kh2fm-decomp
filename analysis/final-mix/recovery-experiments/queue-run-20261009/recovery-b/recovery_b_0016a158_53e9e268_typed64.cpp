#include "../common/types.h"
extern "C" u32 func_0016d080(u32,u32);
extern "C" void func_0016cbc8(u32,u32,u32,u32);
extern "C" void func_0016cce8(u64,u32,void*,u32,u32);
void func_0016a158(u32 p,u32 q) { s32 array[4]; u32 value=func_0016d080(q,p); *(u32*)(p+0x484)=value;
array[0]=p; func_0016cce8(value,0,array,1,0); func_0016cbc8(*(u32*)(p+0x484),1,0,0); }
