#include "../common/types.h"
extern "C" u32 D_0032dedc[];
u32 func_001a8450(u8*object){
 if(!object)return 0;
 u16 index=*(u16*)(object+10);
 u32 quotient=index>>5;
 register u32 bit asm("$11");
 asm("andi %0,%1,31":"=r"(bit):"r"(index),"r"(quotient));
 u32 offset=quotient*4;
 if(!index)return 0;
 register u32 mask asm("$15")=(u32)1<<bit;
 asm("":"+r"(mask));
 u32*table=D_0032dedc;
 asm("":"+r"(table));
 return (*(u32*)((u8*)table+offset)&mask)!=0;
}
