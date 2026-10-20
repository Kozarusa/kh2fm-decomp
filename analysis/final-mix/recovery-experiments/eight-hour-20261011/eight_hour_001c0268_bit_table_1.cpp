#include "../common/types.h"
bool func_001c0268(u32 object,u32 other)
{
 register u32 index asm("$15")=*(u32*)(other+28);
 register u32 mask asm("$14")=1;
 asm("" : "+r"(mask));
 register u32 offset asm("$13")=(index>>5)*4;
 index&=31;
 object+=offset;
 mask<<=index;
 return (*(u32*)(object+4)&mask)==0;
}
