#include "../common/types.h"
extern "C" void func_002f3f88(u32,u32);
extern "C" char func_00354bc0,func_00354be0;
void func_002007e0(u32 p,u32 q) { register s32 off asm("$14")=*(s32*)(*(u32*)(q+12)+4); asm("" : "+r"(off)); u32 base=p+off; func_002f3f88(base+160,(u32)(long)&func_00354bc0); func_002f3f88(base+176,(u32)(long)&func_00354be0); asm volatile(""); }
