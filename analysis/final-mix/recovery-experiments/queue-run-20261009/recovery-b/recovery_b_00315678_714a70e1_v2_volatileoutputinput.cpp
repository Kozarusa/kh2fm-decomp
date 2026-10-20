#include "../common/types.h"
extern "C" char func_00367860;
extern "C" void func_003167f8(void);
extern "C" void func_00106420(u32);
void func_00315678(u32 p) { u32 table=(u32)(long)&func_00367860; asm volatile("sw %1,%0" : "=m"(*(u32*)p) : "r"(table),"r"(p)); func_003167f8(); func_00106420(p); asm volatile(""); }
