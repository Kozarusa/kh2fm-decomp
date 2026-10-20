#include "../common/types.h"
extern "C" u32 func_00108398(void*);
void func_002e5f70(s32 p) {func_00108398((void*)(p+0x10));func_00108398((void*)(p+0x120));
*(u64*)(p+0x230)=0;asm volatile("" ::: "memory");*(u32*)(p+0x220)=0;asm volatile("" ::: "memory");*(u32*)(p+0x224)=0;asm volatile("" ::: "memory");*(u32*)(p+0x228)=0;asm volatile("" ::: "memory");*(u32*)(p+0x22c)=0;
}