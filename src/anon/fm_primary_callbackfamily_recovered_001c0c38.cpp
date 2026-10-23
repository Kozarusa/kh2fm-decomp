#include "../common/types.h"
extern "C" char func_00320888;
extern "C" void func_002fd248(u32,u32,u32,u32,u32);

void func_001c0c38(u32 object) { register u32 high asm("$15"); asm("lui %0,0x1d5" : "=r"(high)); asm volatile("" : : "r"(high) : "memory"); register u32 callback asm("$8"); asm("lui %0,%%hi(func_00320888)" : "=r"(callback)); register u32 data asm("$5"); register u32 size asm("$7"); asm("lw %0,-27808(%3); addiu %1,%1,%%lo(func_00320888); addiu %2,$0,32" : "=r"(data), "+r"(callback), "=r"(size) : "r"(high), "m"(*(u32*)(high+(s16)0x9360))); register u32 third asm("$6")=*(u32*)(data+4); asm("" : "+r"(third), "+r"(data)); func_002fd248(object,data+8,third,size,callback); asm volatile(""); }
