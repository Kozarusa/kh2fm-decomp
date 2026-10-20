#include "../common/types.h"
// Complete-range proposal; independent original-byte verification required.
extern "C" char D_0032b950; typedef u32 (*Allocate)(u32*,u32,u32);
void func_001024b0(u32* object) { register u32 caller asm("$31"); asm("" : "=r"(caller)); u32* result=(u32*)((Allocate)(*(u32*)*object))(object,0x120,caller); result[1]=(u32)object; result[0x44]=0; result[0]=(u32)&D_0032b950; result[3]=0; result[2]=0; result[4]=0; }
