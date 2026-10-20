#include "../common/types.h"
extern "C" u64 func_0016a020(...);
extern "C" void func_0019b0e8(f32,f32,void*,u64,s32);
extern "C" u64 func_0016ace0(...);
void func_00172928(s32* object) { u8 packet[16]; u32 source=*(u32*)(object[0]+4); u64 value=func_0016a020(source); register s32 integer asm("$6")=object[1]; asm("" : : "r"(integer)); register f32 second asm("$f13")=((f32*)object)[3]; asm("" : : "f"(second)); register void* destination asm("$4")=packet; asm("" : : "r"(destination)); func_0019b0e8(((f32*)object)[2],second,destination,value,integer); func_0016ace0(source,packet); }
