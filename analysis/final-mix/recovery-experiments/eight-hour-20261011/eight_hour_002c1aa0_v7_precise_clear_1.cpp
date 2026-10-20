#include "../common/types.h"
extern "C" u8 D_00361b20;
extern "C" void func_002be770(u32*,u64,u64);
void func_002c1aa0(u32* object,u64 second,u64 third)
{
 func_002be770(object,second,third);
 register u32 flags asm("$14")=object[0x163];
 register u32 table asm("$15")=(u32)&D_00361b20;
 asm("" : "+r"(table) : "m"(object[0x2b9]));
 asm volatile("sw $0,%0" : "=m"(object[0x2b9]),"+r"(flags) : "m"(*(u8*)(object+0x2ba)));
 object[0]=table;
 object[0x163]=flags|1;
 *(u8*)(object+0x2ba)=0;
}
