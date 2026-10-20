#include "../common/types.h"
extern "C" u32 func_00305a30(u32);
bool func_0030ec28() { register u32 result asm("$2")=func_00305a30(4); register u32 mask asm("$3")=0x10000; asm volatile("" : "+r"(mask)); asm("and %0,%0,%1" : "+r"(result) : "r"(mask)); return result!=0; }
