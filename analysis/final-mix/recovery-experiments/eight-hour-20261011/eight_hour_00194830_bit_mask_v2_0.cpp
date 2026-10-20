#include "../common/types.h"
extern "C" u32* func_001947c0(u64,u64);
u32 func_00194830(u64 first,u64 second,u32 bit){u32*record=func_001947c0(first,second);if(!record)return false;u32 mask=(u32)1<<bit;asm("":"+r"(mask));return (*record & mask)!=0;}

