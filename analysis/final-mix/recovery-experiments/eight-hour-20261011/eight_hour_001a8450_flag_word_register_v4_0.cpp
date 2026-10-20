#include "../common/types.h"
extern "C" u32 D_0032dedc[];
u32 func_001a8450(u8*object){if(!object)return false;u16 index=*(u16*)(object+10);if(!index)return false;register u32 mask asm("$15")=(u32)1<<(index&31);asm("":"+r"(mask));u32*table=D_0032dedc;asm("":"+r"(table));register u32 flags asm("$13")=table[index>>5];return (flags&mask)!=0;}


