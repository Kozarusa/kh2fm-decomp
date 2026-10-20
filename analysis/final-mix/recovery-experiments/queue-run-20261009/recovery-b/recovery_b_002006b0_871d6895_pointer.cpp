#include "../common/types.h"
extern "C" u32 func_002f3f88(void*,void*);
extern "C" u8 D_00354bc0[],D_00354be0[];
void func_002006b0(u8* p,u8* q) { p+=*(s32*)(*(u32*)(q+12)+4); func_002f3f88(p+160,D_00354bc0); asm("" ::: "memory"); func_002f3f88(p+176,D_00354be0); asm("" ::: "memory"); }
