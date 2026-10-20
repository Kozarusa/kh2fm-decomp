#include "../common/types.h"
extern "C" u32 func_001058e8(...);
u8* func_00243230(u32 value,u32 index) {
 u8* base=(u8*)func_001058e8();
 u32 bit=value*8+index;
 base+=0x49d8; asm("" : "+r"(base)); // why: materializes adjusted save base before indexing
 register u32* pointer asm("$13")=(u32*)((bit>>5)*4+(u32)base); // why: original word cursor occupies t5
 register u32 mask asm("$14")=1u<<(bit&31); // why: original bit mask occupies t6
 u32 old=*pointer;
 u32 result=old|mask; asm("" : "+r"(result)); // why: keeps combined value computed before conditional store
 if((old&mask)==0) *pointer=result;
 return base;
}






