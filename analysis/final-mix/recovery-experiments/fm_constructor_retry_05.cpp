#include "../common/types.h"
extern u32 D_0033cc18;
extern "C" void func_00106108(u32*);
void func_001060b8(u32* object,u32 first,u32 second) { register u32 stack asm("$29"); register u32 table asm("$15"); asm("lui %0,0x34" : "=r"(table) : "r"(stack)); table-=0x33e8; object[0]=table; asm volatile("" ::: "memory"); object[2]=second; asm volatile("" ::: "memory"); object[1]=first; func_00106108(object); }
void func_001060e0(u32* object,u32 first,u32 second) { register u32 stack asm("$29"); register u32 table asm("$15"); asm("lui %0,0x34" : "=r"(table) : "r"(stack)); table-=0x33e8; object[0]=table; asm volatile("" ::: "memory"); object[2]=second; asm volatile("" ::: "memory"); object[1]=first; func_00106108(object); }
