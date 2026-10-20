#include "../common/types.h"
void func_0015cbb8(u8 a,u8 b,u8 c,u8 d)
{
 register u32 high asm("$14")=0x004f0000;
 asm("" : "+r"(high));
 register u8* cursor asm("$15")=(u8*)(high+0x3700);
 asm("" : "+r"(cursor) : "m"(*(u8*)(high+0x3700)));
 *(u8*)(high+0x3700)=a;
 cursor[1]=b;
 asm("" : "+m"(cursor[1]),"+m"(cursor[2]),"+m"(cursor[3]));
 cursor[3]=d;
 asm("" : "+m"(cursor[2]),"+m"(cursor[3]));
 cursor[2]=c;
}
