#include "../common/types.h"
extern "C" u32 D_0033cae8[];
bool func_002f1ae0(u32 index)
{
 register u32* table asm("$15")=D_0033cae8;
 asm("" : "+r"(table));
 return (table[index>>5]&(1u<<(index&31)))!=0;
}
