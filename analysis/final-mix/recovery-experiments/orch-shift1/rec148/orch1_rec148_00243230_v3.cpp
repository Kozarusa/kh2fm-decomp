#include "../common/types.h"
extern "C" u32 func_001058e8(...);
u8* func_00243230(u32 value,u32 index) {
 u8* base=(u8*)func_001058e8();
 u32 bit=value*8+index;
 base+=0x49d8; asm("" : "+r"(base)); // why: materializes adjusted save base before indexing
 u32* pointer=(u32*)base+(bit>>5);
 u32 mask=1u<<(bit&31);
 u32 old=*pointer;
 u32 result=old|mask;
 if((old&mask)==0) *pointer=result;
 return base;
}


