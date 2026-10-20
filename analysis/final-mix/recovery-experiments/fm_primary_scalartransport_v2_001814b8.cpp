#include "../common/types.h"
extern u8 D_0032d7c0[];
// Separate signed page scaling from the word index; preserve original address splitting.
void func_001814b8(u32 param_1) {
 register s32 page asm("$13") = (s32)param_1 >> 10;
 register u32 base asm("$15") = (u32)D_0032d7c0;
 asm volatile("" : "+r"(page), "+r"(base));
 register u32 low asm("$14") = (param_1 & 0x3ff) >> 5;
 page <<= 5;
 asm volatile("" : "+r"(page), "+r"(low));
 page += base;
 asm volatile("" : "+r"(page));
 low <<= 2;
 page += low;
 asm volatile("" : "+r"(page));
 *(u32*)page &= ~(1u << (param_1 & 31));
}
