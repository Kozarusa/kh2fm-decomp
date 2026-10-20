#include "../common/types.h"
extern "C" char func_00367848;
extern "C" void func_003167f8(void);
extern "C" void func_00106420(u32);
void func_00315700(u32 p) { u32 table=(u32)(long)&func_00367848; asm volatile("sw %1,%0" : "=m"(*(u32*)p) : "r"(table)); func_003167f8(); func_00106420(p); asm volatile(""); }
