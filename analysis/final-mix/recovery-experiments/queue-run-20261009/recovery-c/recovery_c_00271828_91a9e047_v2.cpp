#include "../common/types.h"
extern "C" u32 func_00192048(u32);
extern "C" void func_002595e8(u32,u32);
extern "C" char func_00373970;
u32 func_00271828(u32 i,u32 p){u32 v=func_00192048(*(u32*)((u32)(long)&func_00373970+i*4));register u32 arg asm("$4");asm(".set push\n.set noreorder\ndaddu %0,%1,$0\n.set pop" : "=r"(arg) : "r"(p));func_002595e8(arg,v); return p;}