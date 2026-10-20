#include "../common/types.h"
extern "C" u32* func_001947c0(u64,u64);

u32 func_00194830(u64 first,u64 second,u32 bit){u32*record=func_001947c0(first,second);if(record){register u32 one asm("$15")=1;register u32 mask asm("$15");asm("sllv %0,%1,%2":"=r"(mask):"r"(one),"r"(bit));return (*record & mask)!=0;}return 0;}
