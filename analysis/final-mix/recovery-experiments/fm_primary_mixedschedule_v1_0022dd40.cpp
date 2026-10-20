#include "../common/types.h"
// Complete-range scheduling/address proposal.
extern "C" s32 func_002282f0(s16); extern "C" void func_00102c18(u32,u32,u32); extern "C" char D_0022dc30;
void func_0022dd40(u32 object) { s32 value=func_002282f0(*(s16*)(object+4)); register u32 high asm("$5"); asm("lui %0,1" : "=r"(high)); if(!value) func_00102c18(1,high|0x7318,(u32)&D_0022dc30); }
