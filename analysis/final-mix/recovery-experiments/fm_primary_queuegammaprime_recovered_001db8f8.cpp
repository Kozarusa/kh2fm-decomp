#include "../common/types.h"
extern "C" u8 D_00352a78;
extern "C" void func_001c23a8(u32*,u64,u64,u64,u64,u64,u64);

void func_001db8f8(u32* object,u64 second,u64 third,u64 fourth)
{
 func_001c23a8(object,second,third,0,0,96,fourth);
 object[0x27e]=0;
 object[0x162]|=0x10000000;
 *(u32*)object=(u32)&D_00352a78;
}
