#include "../common/types.h"
void func_0015cbb8(u8 a,u8 b,u8 c,u8 d)
{
 register u32 high asm("$14")=0x004f0000;
 asm("" : "+r"(high));
 register volatile u8* cursor asm("$15")=(volatile u8*)(high+0x3700);
 asm("" : "+r"(cursor) : "r"(a));
 *(volatile u8*)(high+0x3700)=a;
 cursor[1]=b;
 cursor[3]=d;
 cursor[2]=c;
}
