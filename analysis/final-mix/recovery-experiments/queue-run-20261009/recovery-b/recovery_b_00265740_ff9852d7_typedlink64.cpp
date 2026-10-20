#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" void func_00139d78(u32);
bool func_00265740(void) { register u64 link asm("$31"); asm volatile("" : "=r"(link)); u32 object=func_00257770(); func_00139d78(object); return *(s32*)(object+0x184)==141; }
