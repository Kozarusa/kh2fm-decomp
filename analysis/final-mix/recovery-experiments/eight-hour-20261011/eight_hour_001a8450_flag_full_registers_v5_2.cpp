#include "../common/types.h"
extern "C" u32 D_0032dedc[];
u32 func_001a8450(u8*object){
 if(!object)return 0;
 register u32 index asm("$15")=*(u16*)(object+10);
 register u32 quotient asm("$14")=index>>5;
 register u32 bit asm("$11")=index&31;
 asm("":"+r"(bit):"r"(quotient));
 u32 offset=quotient<<2;
 if(index){
  register u32 mask asm("$15")=(u32)1<<bit;
  asm("":"+r"(mask));
  register u32*table asm("$14")=D_0032dedc;
  asm("":"+r"(table));
  u32 flags=*(u32*)((u8*)table+offset);
  flags&=mask;
  asm("":"+r"(flags));
  return flags!=0;
 }
 return 0;
}

