#include "../common/types.h"
extern "C" u8 D_00373a98[],D_00373aa0[];
void func_002713a0(s64 a,u8**b,u32*c) { register u8* high asm("$15")=(u8*)0x370000;asm("" : "+r"(high));u8* p;if(!a)p=high+0x3a98;else p=high+0x3aa0;*b=p;register u32 count asm("$14")=3;asm volatile("" : "+r"(count) : "r"(p) : "memory");*c=count; }
