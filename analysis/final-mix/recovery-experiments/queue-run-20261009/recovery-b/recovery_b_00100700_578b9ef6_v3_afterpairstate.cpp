#include "../common/types.h"
extern "C" u32 func_0030edb0(void);
extern "C" void func_0030ee00(void);
extern "C" u32 D_0037aa2c,D_0037aa30;
void func_00100700(u32 a,u32* p,u32 c,u32 d) { p[4]=0; *(volatile u32*)p=0xffffffff; asm volatile("" ::: "memory"); p[1]=c; p[2]=d; *(u64*)(p+4)|=0x7fa; p[3]=a; u32 value=func_0030edb0(); D_0037aa2c=(u32)value; p[6]=D_0037aa30; D_0037aa30=(u32)p; if(value) func_0030ee00(); asm volatile("" ::: "memory"); }
