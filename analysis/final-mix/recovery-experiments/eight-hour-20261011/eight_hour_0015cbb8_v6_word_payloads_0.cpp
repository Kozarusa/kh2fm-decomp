#include "../common/types.h"
void func_0015cbb8(u8 a,u32 b,u32 c,u32 d)
{
 register u32 high asm("$14")=0x004f0000;
 asm("" : "+r"(high));
 register u8* cursor asm("$15")=(u8*)(high+0x3700);
 asm("" : "+r"(cursor) : "m"(*(u8*)(high+0x3700)));
 *(u8*)(high+0x3700)=a;
 asm("" : "+r"(b),"+r"(c),"+r"(d) : "m"(*(u8*)(high+0x3700)));
 b=(u8)b;c=(u8)c;d=(u8)d;
 asm("" : : "r"(b),"r"(c),"r"(d));
 (*(volatile u8*)(cursor+1))=b;
 (*(volatile u8*)(cursor+3))=d;
 (*(volatile u8*)(cursor+2))=c;
}
