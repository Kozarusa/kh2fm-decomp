#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" void func_00139d78(u32);
bool func_00265c10(void) { asm volatile("" ::: "$16"); u32 object=func_00257770(); func_00139d78(object); return *(s32*)(object+0x184)==321; }
