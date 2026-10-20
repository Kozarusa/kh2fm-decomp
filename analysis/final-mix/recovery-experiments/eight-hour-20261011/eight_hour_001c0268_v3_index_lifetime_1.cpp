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
 u32 bits=*(u32*)(object+4)&mask;
 asm("" : "+r"(index));
 return bits==0;
}
