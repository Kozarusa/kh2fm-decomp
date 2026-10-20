#include "../common/types.h"
extern "C" s32 func_00257770(void);
extern "C" void func_00139d78(u32);
bool func_00265740() { u32 object=func_00257770(); asm volatile("" ::: "memory"); func_00139d78(object); asm volatile("" ::: "memory"); return *(s32*)(object+0x184)==141; }