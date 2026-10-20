#include "../common/types.h"
extern "C" u8 D_00349da8;
extern "C" u64 D_0036b0e0;
extern "C" void func_0014b290(u32*);
void func_0014ba90(u32* object)
{
 func_0014b290(object);
 u64 data=D_0036b0e0;
 register u64 flags asm("$14")=1ULL<<60;
 asm("" : "+r"(flags));
 register u64 fourteen asm("$13")=14;
 asm("" : "+r"(fourteen));
 *(u64*)(object+0x42)=fourteen;
 *(u64*)(object+0x44)=data;
 *(u64*)(object+0x40)=flags|0x8001;
 register u64 sixtyfour asm("$12")=64;
 asm("" : "+r"(sixtyfour));
 *(u64*)(object+0x46)=sixtyfour;
 *object=(u32)&D_00349da8;
 asm("" : "+r"(object));
 *(volatile u64*)(object+0x48)=flags|0x8001;
 *(volatile u64*)(object+0x4a)=fourteen;
 *(volatile u64*)(object+0x4c)=data;
 *(volatile u64*)(object+0x4e)=sixtyfour;
}
