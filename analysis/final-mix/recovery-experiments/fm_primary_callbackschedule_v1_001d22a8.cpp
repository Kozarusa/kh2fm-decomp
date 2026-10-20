#include "../common/types.h"
extern "C" char func_00321688;
extern "C" void func_002fd248(u32,u32,u32,u32,u32);
void func_001d22a8(u32 object) { register u32 high asm("$15"); asm("lui %0,0x1d6" : "=r"(high)); asm volatile("" : : "r"(high) : "memory"); register u32 callback asm("$8"); asm("lui %0,%%hi(func_00321688)" : "=r"(callback)); register u32 data asm("$5"); register u32 size asm("$7"); asm("lw %0,-17920(%3); addiu %1,%1,%%lo(func_00321688); addiu %2,$0,16" : "=r"(data), "+r"(callback), "=r"(size) : "r"(high), "m"(*(u32*)(high+(s16)0xba00))); func_002fd248(object,data+8,*(u32*)(data+4),size,callback); asm volatile(""); }
