#include "../common/types.h"

void func_00308da0(u32 p){
register u32 flags asm("$3")=*(u32*)(p+0x10);
register u32 mask asm("$2");
asm volatile("lui %0,0xffff; ori %0,%0,0xfffe" : "=r"(mask) : "r"(flags) : "memory");
*(u32*)(p+0x18)=0;
asm volatile("" : "+r"(flags) : "r"(mask) : "memory");
*(u32*)(p+0x10)=flags&mask;
}
