#include "../common/types.h"
extern "C" void func_00306e80(void);
u32 func_00307f40(u64 a,u64 b,s32 c) { register s32 condition asm("$4"); asm("" : "=r"(condition) : "0"(c)); if(condition) func_00306e80(); asm volatile("" ::: "memory"); return 1; }
