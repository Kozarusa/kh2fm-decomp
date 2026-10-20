#include "../common/types.h"
struct State { u32 value,zero; u8* first; u8* last; u8 data[1]; };
extern "C" State D_01e352c0;

State* func_00306900(u32 a) { register u8* high asm("$2")=(u8*)0x1e30000; asm("" : "+r"(high)); register volatile State* p asm("$3")=(State*)(high+0x52c0); asm volatile("" : "+r"(p) :: "memory");*(volatile u32*)(high+0x52c0)=a;register u8* data asm("$4")=(u8*)p->data; asm("" : "+r"(data)); p->first=data; p->zero=0; p->last=data; return (State*)p; }
