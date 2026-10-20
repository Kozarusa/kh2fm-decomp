#include "../common/types.h"
extern "C" void func_003167f8(void);
extern "C" void func_00106420(u32);
void func_00315700(u32 p) { register u32 table asm("$15"); table=0x360000; asm("" : "+r"(table)); asm("addiu %0,%0,30792" : "+r"(table)); asm("sw %1,%0" : "=m"(*(u32*)p) : "r"(table)); func_003167f8(); func_00106420(p); asm volatile(""); }
