#include "../common/types.h"
extern "C" u32 func_00139d78(u32);
extern "C" u32 D_0035f21c;

u32 func_00276f38(void) { u32 result=func_00139d78(D_0035f21c+0x198); asm volatile("" ::: "memory"); return result; }
