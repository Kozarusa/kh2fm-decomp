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
 register u64 fourteen asm("$13")=14;
 asm("" : "+r"(fourteen));
 register u32 table asm("$15")=0x00350000;
 asm("" : "+r"(table));
 asm volatile("sd %1,%0" : "=m"(*(u64*)(object+0x42)) : "r"(fourteen));
 *(u64*)(object+0x44)=data;
 *(u64*)(object+0x40)=flags|0x8001;
 register u64 sixtyfour asm("$12")=64;
 asm("" : "+r"(sixtyfour));
 asm volatile("addiu %0,%0,-25176" : "+r"(table) : "m"(*(u64*)(object+0x40)));
 *(u64*)(object+0x46)=sixtyfour;
 *object=table;
 asm("" : "+r"(object));
 *(volatile u64*)(object+0x48)=flags|0x8001;
 *(volatile u64*)(object+0x4a)=fourteen;
 *(volatile u64*)(object+0x4c)=data;
 *(volatile u64*)(object+0x4e)=sixtyfour;
}
