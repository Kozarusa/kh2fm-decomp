#include "../common/types.h"
bool func_0028b1c0(const u8* object,u32 index)
{
 u32 bits=*(const u32*)(object+32);
 if(!bits)return false;
 register u32 mask asm("$15")=1;
 asm("sllv %0,%0,%1" : "+r"(mask) : "r"(index));
 return (bits&mask)!=0;
}
