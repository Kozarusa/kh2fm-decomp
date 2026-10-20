#include "../common/types.h"
extern "C" u16 func_00147050(u32,u32,u32,u32,u32*);
extern "C" u32 D_00348800;
void func_00143348(u32 p) {
u32 out=0;
u16 a=func_00147050(D_00348800,0,p,0,&out);
u16 b=(u16)out;
asm volatile("sh %0,280(%1)" :: "r"(a),"r"(p));*(volatile u16 *)(p+282)=b;
}