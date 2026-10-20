#include "../common/types.h"
extern "C" char func_0035f3a0;
extern "C" void func_0028b8a0(void);
extern "C" void func_0023f820(u32);
void func_0028b7f8(u32 p) { u32 table=(u32)(long)&func_0035f3a0; asm("sw %1,%0" : "=m"(*(u32*)p) : "r"(table)); func_0028b8a0(); func_0023f820(p); asm volatile(""); }
