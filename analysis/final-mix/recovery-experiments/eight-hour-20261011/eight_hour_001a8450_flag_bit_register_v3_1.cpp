#include "../common/types.h"
extern "C" u32 D_0032dedc[];
u32 func_001a8450(u8*object){if(!object)return false;u16 index=*(u16*)(object+10);register u32 bit asm("$11")=index&31;asm("":"+r"(bit));if(!index)return false;register u32 mask asm("$15")=(u32)1<<bit;asm("":"+r"(mask));u32*table=D_0032dedc;asm("":"+r"(table));return (table[index>>5]&mask)!=0;}


