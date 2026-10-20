#include "../common/types.h"
extern "C" void func_001d7cd0(u32);
extern "C" char func_00351468;
void func_001c2ce8(u32 p) {func_001d7cd0(p);
u32 a=*(u32*)(p+1416);u32 b=*(u32*)(p+2748);a|=0x200000;b|=4;*(u32*)(p+1416)=a;*(volatile u32*)p=(u32)(long)&func_00351468;*(volatile u32*)(p+2748)=b;
}