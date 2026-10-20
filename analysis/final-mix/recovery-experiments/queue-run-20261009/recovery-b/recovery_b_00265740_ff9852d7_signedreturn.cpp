#include "../common/types.h"
extern "C" s32 func_00257770(void);
extern "C" void func_00139d78(u32);
bool func_00265740(void) { u32 object=func_00257770(); func_00139d78(object); return *(s32*)(object+0x184)==141; }
