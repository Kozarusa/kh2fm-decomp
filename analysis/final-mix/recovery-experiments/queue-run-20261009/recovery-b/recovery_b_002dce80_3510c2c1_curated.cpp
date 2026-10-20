#include "../common/types.h"
extern "C" f32 D_00375da8;
extern "C" void func_002e5350(f32,u32,u32);

void func_002dce80(u32 a) { register f32* address asm("$15")=&D_00375da8;asm("" : "+r"(address));func_002e5350(*address,a+0x100,20); }
