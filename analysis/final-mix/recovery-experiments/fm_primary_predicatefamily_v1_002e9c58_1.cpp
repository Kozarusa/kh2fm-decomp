#include "../common/types.h"
extern "C" u32 func_0019bc38(u32);
u32 func_002e9c58(u32 first,u32 second) { register u32 two asm("$15")=2; asm("" : : "r"(two)); u32 result=1; if(*(s32*)(first+12)!=two && !(*(u32*)(second+0x588)&4)) result=func_0019bc38(second); return result; }
