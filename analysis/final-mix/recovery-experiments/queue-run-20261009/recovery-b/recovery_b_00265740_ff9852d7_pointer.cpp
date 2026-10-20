#include "../common/types.h"
extern "C" u8* func_00257770(void);
extern "C" void func_00139d78(void*);
bool func_00265740(void) { u8* object=func_00257770(); func_00139d78(object); return *(s32*)(object+0x184)==141; }
