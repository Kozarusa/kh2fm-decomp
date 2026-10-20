#include "../common/types.h"
extern "C" u32 D_0033cae8[];
bool func_002f1ae0(u32 index)
{
 register u32 bits asm("$2")=D_0033cae8[index>>5];
 index&=31;
 asm("" : "+r"(bits));
 register u32 mask asm("$15")=1;
 asm("" : "+r"(mask) : "r"(bits));
 return (bits&(mask<<index))!=0;
}
