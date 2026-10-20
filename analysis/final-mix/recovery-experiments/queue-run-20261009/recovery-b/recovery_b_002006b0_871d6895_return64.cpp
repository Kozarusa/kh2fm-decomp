#include "../common/types.h"
extern "C" u64 func_002f3f88(void*,void*);
extern "C" u8 D_00354bc0[],D_00354be0[];
void func_002006b0(s32 p,s32 q) { s32 base; base=p+*(s32*)(*(u32*)(q+12)+4); func_002f3f88((void*)(base+160),D_00354bc0); asm("" ::: "memory"); func_002f3f88((void*)(base+176),D_00354be0); asm("" ::: "memory"); }
