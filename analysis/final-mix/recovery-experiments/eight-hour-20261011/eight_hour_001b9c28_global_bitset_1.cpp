#include "../common/types.h"
extern "C" u32 D_01d48db8[];
void func_001b9c28(u32 index)
{
 register u32 offset asm("$13")=(index>>5)*4;
 register u32* table asm("$15")=D_01d48db8;
 asm("" : "+r"(table));
 register u32* slot asm("$13")=(u32*)(offset+(u32)table);
 index&=31;
 *slot|=1u<<index;
}
