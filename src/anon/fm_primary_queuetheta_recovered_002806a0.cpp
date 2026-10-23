#include "../common/types.h"
extern "C" u32 func_00139d78(u32);
extern "C" u32 D_0035f264;

u32 func_002806a0(void) { u32 result=func_00139d78(D_0035f264+0x380); asm volatile("" ::: "memory"); return result; }
