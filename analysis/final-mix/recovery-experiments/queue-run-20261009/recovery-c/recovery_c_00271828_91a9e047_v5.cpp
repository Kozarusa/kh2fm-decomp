#include "../common/types.h"
extern "C" u64 func_00192048(u32);
extern "C" void func_002595e8(u32,u64);
extern "C" char func_00373970;
u32 func_00271828(u32 i,u32 p){u64 v=func_00192048(*(u32*)((u32)(long)&func_00373970+i*4));func_002595e8(p,v);return p;}