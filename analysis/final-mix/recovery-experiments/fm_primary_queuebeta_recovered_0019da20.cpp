#include "../common/types.h"
extern "C" u32 func_001bc688(...);
extern "C" u32 func_00190128(...);

void func_0019da20(u32* p,u32 a) { *p=a; *(u16*)(p+1)=0;func_001bc688(p+1);func_00190128(p+4);
u32 z=0xffffffff; asm volatile("" : "+r"(z)); p[0x14]=0;asm volatile("" ::: "memory");p[9]=z;asm volatile("" ::: "memory");p[0xf]=0;
}
