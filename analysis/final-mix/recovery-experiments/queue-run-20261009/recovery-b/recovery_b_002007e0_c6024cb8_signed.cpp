#include "../common/types.h"
extern "C" void func_002f3f88(u32,u32);
extern "C" char func_00354bc0,func_00354be0;
void func_002007e0(s32 p,s32 q) { u32 base=p+*(s32*)(*(u32*)(q+12)+4); func_002f3f88(base+160,(u32)(long)&func_00354bc0); func_002f3f88(base+176,(u32)(long)&func_00354be0); asm volatile(""); }
