#include "../common/types.h"
extern "C" u8* func_001058e8();
u8* func_00243230(u32 value,u32 index) {
 u8* base=func_001058e8();
 u32 bit=value*8+index;
 u32* pointer=(u32*)(base+0x49d8)+(bit>>5);
 u32 mask=1u<<(bit&31);
 u32 old=*pointer;
 u32 result=old|mask;
 if((old&mask)==0) *pointer=result;
 return base+0x49d8;
}
