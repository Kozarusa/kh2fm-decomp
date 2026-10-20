#include "../common/types.h"
extern "C" u8* func_001058e8();
void func_002429c0(u32 first,u32 second)
{
 u8* context=func_001058e8();
 *(u16*)(context+0x41a0)=(u16)first;
 *(u16*)(context+0x41a2)=(u16)second;
}
