#include "../common/types.h"
extern "C" u8* func_00257770(void);
extern "C" void func_00139d78(void*);
bool func_00265740() { u8* object=func_00257770(); asm volatile("" ::: "memory"); func_00139d78(object); asm volatile("" ::: "memory"); return *(volatile s32*)(object+0x184)==141; }
