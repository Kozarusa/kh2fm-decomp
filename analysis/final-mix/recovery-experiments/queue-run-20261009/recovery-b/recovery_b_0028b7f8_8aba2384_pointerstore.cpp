#include "../common/types.h"
extern "C" char func_0035f3a0;
extern "C" void func_0028b8a0(void);
extern "C" void func_0023f820(u32);
void func_0028b7f8(u32 p) { *(volatile void**)p=&func_0035f3a0; func_0028b8a0(); func_0023f820(p); asm volatile(""); }
