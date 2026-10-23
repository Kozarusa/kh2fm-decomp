#include "../common/types.h"

void func_001c8a90(void) {
register u32 high asm("$15");asm volatile("lui %0,0x1d5" : "=r"(high));*(u32*)(high-0x66a0)=0;asm volatile("" : "+r"(high) :: "memory");register u32* base asm("$14");asm volatile("addiu %0,%1,-0x66a0" : "=&r"(base) : "r"(high));asm volatile("lui %0,0x1d5" : "=r"(high));base[1]=0;*(u32*)(high-0x6698)=0;
}
