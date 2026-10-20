#include "../common/types.h"
extern "C" u8 D_00349da8;
extern "C" u64 D_0036b0d8;
extern "C" void func_0014b290(u32*);
void func_0014ba20(u32* object)
{
 func_0014b290(object);
 u64 data=D_0036b0d8;
 register u64 flags asm("$14")=1ULL<<60;
 asm("" : "+r"(flags));
 *(u64*)(object+0x42)=14;
 *(u64*)(object+0x44)=data;
 *(u64*)(object+0x40)=flags|0x8001;
 *(u64*)(object+0x46)=64;
 *object=(u32)&D_00349da8;
 *(u64*)(object+0x48)=flags|0x8001;
 *(u64*)(object+0x4a)=14;
 *(u64*)(object+0x4c)=data;
 *(u64*)(object+0x4e)=64;
}
