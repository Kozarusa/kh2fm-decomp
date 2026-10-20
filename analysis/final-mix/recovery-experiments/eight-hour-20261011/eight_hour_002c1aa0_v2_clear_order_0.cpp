#include "../common/types.h"
extern "C" u8 D_00361b20;
extern "C" void func_002be770(u32*,u64,u64);
void func_002c1aa0(u32* object,u64 second,u64 third)
{
 func_002be770(object,second,third);
 object[0x2b9]=0;
 asm("" : "+m"(object[0x2b9]),"+m"(*(u8*)(object+0x2ba)));
 *(u32*)object=(u32)&D_00361b20;
 object[0x163]|=1;
 *(u8*)(object+0x2ba)=0;
}
