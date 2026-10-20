#include "../common/types.h"
// Complete-range scheduling/address proposal.
extern "C" u64 func_0010c7e8(u32); extern "C" void func_0011a938(f32,f32,u64,s32);
void func_002f10c0(s32* object) { u64 value=func_0010c7e8(*(u32*)(object[0]+4)); register s32 integer asm("$5")=object[1]; asm volatile("" : "+r"(integer)); register f32 second asm("$f13")=((f32*)object)[3]; asm("" : : "f"(second)); func_0011a938(((f32*)object)[2],second,value,integer); }
