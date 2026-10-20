#include "../common/types.h"
extern "C" void func_00306e80(s64);
u32 func_00307f40(u64 a,u64 b,s64 c) { register s64 condition asm("$4"); asm("" : "=r"(condition) : "0"(c)); if(condition) func_00306e80(condition); asm volatile("" ::: "memory"); return 1; }
