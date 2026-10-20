#include "../common/types.h"
extern "C" char func_00367860;
extern "C" void func_003167f8(void);
extern "C" void func_00106420(u32);
void func_00315678(u32 object) { register u32 table asm("$15")=(u32)&func_00367860; asm volatile("" : "+r"(table)); *(u32*)object=table; func_003167f8(); func_00106420(object); asm volatile(""); }
